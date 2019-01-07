#include <string.h>
#include "logging.h"

int main()
{
    log_debug("test debug");
    log_info("test info :%s", "args_test");
    log_warn("test warn");
    log_error("test error");
    char test_char[] = "test bin test bin";
    log_bin(strlen(test_char), (void*)test_char);
    return 0;
}
