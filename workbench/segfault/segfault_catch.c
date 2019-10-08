#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <execinfo.h>
#include <pthread.h>
#include <ucontext.h>


#define MAX_THREADS 255
#define MAX_STACK_DEPTH 64

typedef struct
{
    pid_t thread_id;
    int stack_depth;
    void* func_addr[MAX_STACK_DEPTH];
} threadEntry;

static pthread_mutex_t stack_mutex = PTHREAD_MUTEX_INITIALIZER;
static int thread_count = 0;
static int current_thread_index = 0;
static threadEntry threads[MAX_THREADS];


void __attribute__((__no_instrument_function__))
__cyg_profile_func_enter(void *this_func, void *call_site)
{
    int i;
    pid_t curr_thread = pthread_self();
    pthread_mutex_lock(&stack_mutex);
    for (i = 0; i < thread_count; i++) {
        if (curr_thread == threads[i].thread_id && threads[i].stack_depth < MAX_STACK_DEPTH) {
            threads[i].func_addr[threads[i].stack_depth] = this_func;
            threads[i].stack_depth++;
            current_thread_index = i;
            break;
        }
    }

    if (i == thread_count && i < MAX_THREADS) {
        threads[i].thread_id = curr_thread;
        threads[i].stack_depth = 0;
        threads[i].func_addr[threads[i].stack_depth] = this_func;
        threads[i].stack_depth++;
        thread_count++;
        current_thread_index = i;
    }

    pthread_mutex_unlock(&stack_mutex);
}

void __attribute__((__no_instrument_function__))
__cyg_profile_func_exit(void *this_func, void *call_site)
{
    int i;
    pid_t curr_thread = pthread_self();
    pthread_mutex_lock(&stack_mutex);
    for (i = 0; i < thread_count; i++) {
        if (curr_thread == threads[i].thread_id) {
            if (this_func == threads[i].func_addr[threads[i].stack_depth -1]) {
                threads[i].stack_depth--;
            }
            break;
        }
    }
    pthread_mutex_unlock(&stack_mutex);
}


static void SignalSegFaultHandler(int signal, siginfo_t *si, void *ctx)
{
    void *array[MAX_STACK_DEPTH];
    size_t bt_size;
    char **bt_strings;
    int i;
    ucontext_t *triger_context = (ucontext_t*)ctx;

    FILE *mapfd = fopen("/proc/self/maps", "r");
    if (mapfd != NULL) {
        printf("\n/proc/self/maps:\n");

        char buf[256];
        int n;
        while ((n = fread(buf, 1, sizeof(buf), mapfd))) {
            printf("%.*s", n, buf);
        }
        printf ("\n");
        fclose(mapfd);
    }

    printf("Segmentfault signal captured.\n");
    if (si) {
        printf("Segfault at address: %p\n", si->si_addr);
    }

    if (ctx) {
        void *reg_state_start = &(triger_context->uc_mcontext);
        void *reg_state_end = &(triger_context->uc_sigmask);

        printf("\nregister state:\n");
        while(reg_state_start < reg_state_end) {
            printf("\t0x%zx\n", *(size_t *)reg_state_start);
            reg_state_start += sizeof(size_t);
        }
        printf ("\n");
    }

    bt_size = backtrace(array, MAX_STACK_DEPTH);
    bt_strings = backtrace_symbols(array, bt_size);
    if (NULL == bt_strings) {
        perror("backtrace_symbols");
        exit(EXIT_FAILURE);
    }

    if (bt_size > 0) {
        printf("backtrace() obtained %zd stack frames.\n", bt_size);
        for (i = 0; i < bt_size; i++) {
            printf("\t%s\n", bt_strings[i]);
        }
        printf ("\n");

        free(bt_strings);
        bt_strings = NULL;
    }

    int current_stack_depth = threads[current_thread_index].stack_depth;
    printf("Function instrument obtained %d stack frames.\n", current_stack_depth);
    for (i = current_stack_depth - 1; i >= 0; i--) {
        printf("\t%p\n", threads[current_thread_index].func_addr[i]);
    }
    printf("Use \"objdump -d execute_program\" to view function offset.\n");
    printf("Use \"addr2line -e execute_program address\" to parse function stack.\n");

    printf ("\n");

    exit(EXIT_FAILURE);
}

void __attribute__ ((constructor)) segfault_handler (void)
{
    struct sigaction sa;
    stack_t ss;
    void *stack_mem = malloc (2 * SIGSTKSZ);

    sa.sa_sigaction = SignalSegFaultHandler;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset (&sa.sa_mask);

    if (stack_mem != NULL) {
        ss.ss_sp = stack_mem;
        ss.ss_flags = 0;
        ss.ss_size = 2 * SIGSTKSZ;
        if (sigaltstack (&ss, NULL) == 0) {
            sa.sa_flags |= SA_ONSTACK;
        }
    }

    sigaction (SIGSEGV, &sa, NULL);
}

