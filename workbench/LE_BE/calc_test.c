/*
   Write a C program to find out if the underlying
   architecture is little endian or big endian.
 */

#include <stdio.h>
#include <math.h>

/*
 * C语言实现中，整形数在进行位运算时都会先默认将自己转换成 bslsf (bit stream left bit first) 形式
 *
 * */

int main ()
{
    unsigned char c = 0x00;
    unsigned char cf = 0XFF;
    unsigned char cc = 0x00;
    unsigned long long x = 0;
    unsigned long long value = 0;
    x |= cf; x <<= 8;
    x |= cf;
    value = x & ((unsigned int)pow(2, 16) - 1);
    c = *((unsigned char *)&value + 1);
    printf("x: %llu, value: %llu\n", x, value);
    printf("c: %u\n", c);

    return 0;
}
