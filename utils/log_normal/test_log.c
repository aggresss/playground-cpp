#include <string.h>
#include "log.h"

int main()
{
    //SetLogLevel(LOG_LEVEL_TRACE);
    LogTrace("test trace");
    LogDebug("test debug");
    LogInfo("test info: %s", "args_test");
    LogWarn("test warn");
    LogError("test error");
    return 0;
}

