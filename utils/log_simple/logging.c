#include "logging.h"

void log_bin(size_t length, void *bin)
{
    unsigned char *temp = bin;
    size_t i;
    printf("length:%ld, bin: ", length);
    for (i = 0; i < length; i++) {
        if ((i % 8) == 0) {
            printf("\n LINE%02ld: ", (i / 8));
        }
        printf("0x%02X ", *temp);
        temp++;
    }
    printf("\n");
}

