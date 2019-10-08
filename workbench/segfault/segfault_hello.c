#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <execinfo.h>
#include <pthread.h>

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


static void SignalSegFaultHandler(int sig)
{
    void *array[16];
    size_t bt_size;
    char **bt_strings;
    int i;

    printf("Segmentfault signal captured.\n");

    bt_size = backtrace(array, 16);
    bt_strings = backtrace_symbols(array, bt_size);
    if (NULL == bt_strings) {
        perror("backtrace_synbols");
        exit(EXIT_FAILURE);
    }

    if (bt_size > 0) {
        printf("Obtained %zd stack frames.\n", bt_size);
        for (i = 0; i < bt_size; i++) {
            printf("\t%s\n", bt_strings[i]);
        }

        free(bt_strings);
        bt_strings = NULL;
    } else {
        int current_stack_depth = threads[current_thread_index].stack_depth;
        printf("Function instrument %d stack frames.\n", current_stack_depth);
        for (i = current_stack_depth - 1; i >= 0; i--) {
            printf("\t%p\n", threads[current_thread_index].func_addr[i]);
        }
    }

    exit(EXIT_FAILURE);
}


int main()
{
    signal(SIGSEGV, SignalSegFaultHandler);
    puts("Hello World!");
    char *test = strdup(NULL);
    return 0;
}

