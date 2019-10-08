#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <execinfo.h>


#define DUMP(func, call) printf("%s: func = %p, called by = %p\n", __FUNCTION__, func, call)

void __attribute__((__no_instrument_function__))
__cyg_profile_func_enter(void *this_func, void *call_site)
{
    DUMP(this_func, call_site);
}
void __attribute__((__no_instrument_function__))
__cyg_profile_func_exit(void *this_func, void *call_site)
{
    DUMP(this_func, call_site);
}


static void SignalSegFaultHandler(int sig)
{
    void *array[16];
    size_t bt_size;
    char **bt_strings;
    size_t i;

    printf("Segmentfault signal captured.\n");

    bt_size = backtrace(array, 16);
    bt_strings = backtrace_symbols(array, bt_size);
    if (NULL == bt_strings) {
        perror("backtrace_synbols");
        exit(EXIT_FAILURE);
    }

    printf("Obtained %zd stack frames.\n", bt_size);

    for (i = 0; i < bt_size; i++) {
        printf("\t%s\n", bt_strings[i]);
    }

    free(bt_strings);
    bt_strings = NULL;

    exit(EXIT_FAILURE);
}


int main()
{
    signal(SIGSEGV, SignalSegFaultHandler);
    puts("Hello World!");
    char *test = strdup(NULL);
    return 0;
}

