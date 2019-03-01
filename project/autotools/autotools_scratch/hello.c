#include <stdio.h>
int main(int argc, const char * argv[])
{
    printf("Hello, World!\n");
#ifdef ARG_TEST001
    printf("WITH ARG TEST001\n");
#elif defined(ARG_TEST002)
    printf("WITH ARG TEST002\n");
#else
    printf("WITHOUT ARG TEST\n");
#endif
    return 0;
}

