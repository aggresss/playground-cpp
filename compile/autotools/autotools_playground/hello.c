#include <stdio.h>
#include "config.h"
#include "version.h"


int main(int argc, const char * argv[])
{
    printf("TEST_VERSION_STRING: %s\n", TEST_VERSION_STRING);
#ifdef ARG_TEST001
    printf("WITH ARG TEST001\n");
#elif defined(ARG_TEST002)
    printf("WITH ARG TEST002\n");
#else
    printf("WITHOUT ARG TEST\n");
#endif
    return 0;
}

