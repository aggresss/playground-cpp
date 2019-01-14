#include "log.h"

int nLogLevel = LOG_LEVEL_INFO;
LogFunc logFunc = NULL;

void SetLogCallback(LogFunc f)
{
        logFunc = f;
}

void SetLogLevel(int level)
{
        if (level >= LOG_LEVEL_TRACE && level <= LOG_LEVEL_ERROR)
                nLogLevel = level;
}


void Log(int nLevel, char * pFmt, ...)
{
        if (nLevel >= nLogLevel){
                va_list ap;
                va_start(ap, pFmt);
                if (logFunc == NULL) {
                        vprintf(pFmt, ap);
                } else {
                        char logStr[MAX_LOG_LENGTH +1] = {0};
                        vsnprintf(logStr, sizeof(logStr), pFmt, ap);
                        logFunc(nLevel, logStr);
                }
                va_end(ap);
        }
}
