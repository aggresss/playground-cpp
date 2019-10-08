#include <stdio.h>
#include <string.h>

int main(int argc, const char* argv[])
{
    puts("Hello World!");
    char *test = strdup((char *)0x04);
    return 0;
}
