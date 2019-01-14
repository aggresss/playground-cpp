#ifndef __LOG_H__
#define __LOG_H__

#include <stdarg.h>
#include <stdio.h>

#define _s_l_(x) #x
#define _str_line_(x) _s_l_(x)
#define __STR_LINE__ _str_line_(__LINE__)

#define LOG_LEVEL_TRACE 1
#define LOG_LEVEL_DEBUG 2
#define LOG_LEVEL_INFO  3
#define LOG_LEVEL_WARN  4
#define LOG_LEVEL_ERROR 5

#define MAX_LOG_LENGTH 512

extern int nLogLevel;
typedef void (*LogFunc)(int nLevel, char * pLog);

void SetLogLevel(int nLevel);
void SetLogCallback(LogFunc f);
void Log(int nLevel, char * pFmt, ...);

#define LogTrace(fmt,...) \
        Log(LOG_LEVEL_TRACE, __FILE__ ":" __STR_LINE__ "[T]: " fmt "\n", ##__VA_ARGS__)
#define LogDebug(fmt,...) \
        Log(LOG_LEVEL_DEBUG, __FILE__ ":" __STR_LINE__ "[D]: " fmt "\n", ##__VA_ARGS__)
#define LogInfo(fmt,...) \
        Log(LOG_LEVEL_INFO,  __FILE__ ":" __STR_LINE__ "[I]: " fmt "\n", ##__VA_ARGS__)
#define LogWarn(fmt,...) \
        Log(LOG_LEVEL_WARN,  __FILE__ ":" __STR_LINE__ "[W]: " fmt "\n", ##__VA_ARGS__)
#define LogError(fmt,...) \
        Log(LOG_LEVEL_ERROR, __FILE__ ":" __STR_LINE__ "[E]: " fmt "\n", ##__VA_ARGS__)


#endif
