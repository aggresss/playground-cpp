#include <stdio.h>

int main(int argc, const char * argv[])
{
#if (__BYTE_ORDER__==__ORDER_BIG_ENDIAN__)
    printf("Big endian\n");
#elif (__BYTE_ORDER__==__ORDER_LITTLE_ENDIAN__)
    printf("Little endian\n");
#endif
    return 0;
}

