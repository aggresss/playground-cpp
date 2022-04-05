#include <stdio.h>
#include <signal.h>

static int interrupted = 0;

static void handleInterrupt(int sig)
{
    interrupted = 1;
}

int main(int argc, const char * argv[])
{
    (void)signal(SIGINT, handleInterrupt);
    (void)signal(SIGTERM, handleInterrupt);
    (void)signal(SIGKILL, handleInterrupt);

    printf("Hello, World!\n");
    while(!interrupted) {
    }
    return 0;
}
