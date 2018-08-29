/*
 * fork from https://blog.csdn.net/wishfly/article/details/51906692
 * This program can receive rtmp live stream and save it as local flv file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "librtmp/rtmp_sys.h"
#include "librtmp/log.h"

int main(int argc, char* argv[])
{
    double duration=-1;
    int nRead;
    //is live stream ?
    bool bLiveStream=true;

    int bufsize=1024*1024*10;
    char *buf=(char*)malloc(bufsize);
    memset(buf,0,bufsize);
    long countbufsize=0;

    FILE *fp=fopen("receive.flv","wb");
    if (!fp){
        RTMP_LogPrintf("Open File Error.\n");
        return -1;
    }

    /* set log level */
    //RTMP_LogLevel loglvl=RTMP_LOGDEBUG;
    //RTMP_LogSetLevel(loglvl);

    RTMP *rtmp=RTMP_Alloc();
    RTMP_Init(rtmp);
    //set connection timeout,default 30s
    rtmp->Link.timeout=10;
    // HKS's live URL
    if(!RTMP_SetupURL(rtmp,"rtmp://live.hkstv.hk.lxdns.com/live/hks"))
    {
        RTMP_Log(RTMP_LOGERROR,"SetupURL Err\n");
        RTMP_Free(rtmp);
        return -1;
    }
    if (bLiveStream){
        rtmp->Link.lFlags|=RTMP_LF_LIVE;
    }

    RTMP_SetBufferMS(rtmp, 3600*1000); // 3600 seconds

    if(!RTMP_Connect(rtmp,NULL)){
        RTMP_Log(RTMP_LOGERROR,"Connect Err\n");
        RTMP_Free(rtmp);
        return -1;
    }

    if(!RTMP_ConnectStream(rtmp,0)){
        RTMP_Log(RTMP_LOGERROR,"ConnectStream Err\n");
        RTMP_Close(rtmp);
        RTMP_Free(rtmp);
        return -1;
    }

    int count = 0;
    while(count < 6000){
        nRead=RTMP_Read(rtmp,buf,bufsize);
        fwrite(buf,1,nRead,fp);
        count++;
        countbufsize+=nRead;
        RTMP_LogPrintf("Count: %5d, Receive: %5dByte, Total: %5.2fkB\n",count, nRead, countbufsize*1.0/1024);
    }

    if(fp)
        fclose(fp);

    if(buf){
        free(buf);
    }

    if(rtmp){
        RTMP_Close(rtmp);
        RTMP_Free(rtmp);
        rtmp=NULL;
    }
    return 0;
}

