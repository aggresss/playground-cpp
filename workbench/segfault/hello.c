#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <pthread.h>

static int interrupted = 0;
static void handleInterrupt(int sig)
{
    interrupted = 1;
}

static void segfault_trigger(void) {
    char *test = strdup((char *)0x04);
    (void)test;
}

static void * thread_1_do(void * arg)
{
    while(!interrupted) {
        sleep(1);
    }
    return NULL;
}

static void * thread_2_do(void * arg)
{
    while(!interrupted) {
        sleep(1);
    }
    return NULL;
}

static void * thread_3_do(void * arg)
{
    //sleep(1);
    segfault_trigger();
    return NULL;
}

int main(int argc, const char* argv[])
{
    pthread_t thread_1, thread_2, thread_3;
    pthread_attr_t attr;

    (void)signal(SIGINT, handleInterrupt);
    (void)signal(SIGTERM, handleInterrupt);
    (void)signal(SIGKILL, handleInterrupt);

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    pthread_create(&thread_1, &attr, thread_1_do, NULL);
    pthread_create(&thread_2, &attr, thread_2_do, NULL);
    pthread_create(&thread_3, &attr, thread_3_do, NULL);

    puts("Hello World!");

    while(!interrupted) {
        sleep(1);
    }
    return 0;
}

