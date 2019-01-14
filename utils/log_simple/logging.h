/*
 * @file logging.h
 * @author aggresss@163.com
 * @brief loging header file
 */

/**
 * @page logging
 * @brief 描述 logging 工作原理
 *
 *    <p>日志输出分成四个级别：
 *    - ERROR
 *    - WARN
 *    - INFO
 *    - DEBUG
 *    </p>
 *
 */

#ifndef __LOGGING_H__
#define __LOGGING_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/** @name 定义日志 */
/**@{*/
#define LOG_LVL_DISABLE   0
#define LOG_LVL_ERROR     1
#define LOG_LVL_WARN      2
#define LOG_LVL_INFO      3
#define LOG_LVL_DEBUG     4

#define LOG_SUCCESS       0
#define LOG_FAIL         -1

#define LOG_LABEL "LABEL"
#define LOG_OUTPUT_LVL LOG_LVL_DEBUG
/**@}*/

/* bin format print log */
void log_bin(size_t length, void *bin);

#if LOG_OUTPUT_LVL >= LOG_LVL_ERROR
#define log_error(fmt, args...) { \
    fprintf(stdout, "[ %s ][%ld][ERROR] FUNCTION:[%s] LINE:[%d] "fmt"\n", LOG_LABEL, (long)time(NULL), __func__, __LINE__, ##args); \
}
#else
#define log_error(fmt, args...) ((void)0)
#endif /* LOG_OUTPUT_LVL >= LOG_LVL_ERROR */

#if LOG_OUTPUT_LVL >= LOG_LVL_WARN
#define log_warn(fmt, args...) \
    fprintf(stdout, "[ %s ][%ld][WARN] "fmt"\n", LOG_LABEL, (long)time(NULL), ##args);
#else
#define log_warn(fmt, args...) ((void)0)
#endif /* LOG_OUTPUT_LVL >= LOG_LVL_WARN */

#if LOG_OUTPUT_LVL >= LOG_LVL_INFO
#define log_info(fmt, args...) \
    fprintf(stdout, "[ %s ][%ld][INFO] "fmt"\n", LOG_LABEL, (long)time(NULL), ##args);
#else
#define log_info(fmt, args...) ((void)0)
#endif /* LOG_OUTPUT_LVL >= LOG_LVL_INFO */

#if LOG_OUTPUT_LVL >= LOG_LVL_DEBUG
#define log_debug(fmt, args...) \
    fprintf(stdout, "[ %s ][%ld][DEBUG] FUNCTION:[%s] LINE:[%d] "fmt"\n", LOG_LABEL, (long)time(NULL), __func__, __LINE__, ##args);
#else
#define log_debug(fmt, args...) ((void)0)
#endif /* LOG_OUTPUT_LVL >= LOG_LVL_DEBUG */

/**
 * bin format print log
 *
 * HEX print, 8 bytes each line.
 *
 * @param length
 * @param bin
 * @return void
 */
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

#endif /* __LOGGING_H__ */

