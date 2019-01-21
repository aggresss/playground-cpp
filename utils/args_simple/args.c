#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "mygetopt.h"

#define MAX_ARG_LEN 256

extern int myoptind;
extern char* myoptarg;

typedef struct _Ctx {
    const char* appname;
    const char* username;
    const char* password;
    const char* host;
    int port;
    bool info;
    bool debug;
} Ctx;

void init_ctx(Ctx* ctx)
{
    memset(ctx, 0, sizeof(Ctx));
    ctx->port = 0;
}


void my_show_usage(Ctx* ctx)
{
    printf("%s:\n", ctx->appname);
    printf("-?          Help, print this usage" "\n");
    printf("-h <host>   Host to connect to" "\n");
    printf("-p <port>   Port to connect to" "\n");
    printf("-u <str>    Username" "\n");
    printf("-w <str>    Password" "\n");
    printf("-d          Debug" "\n");
    printf("-i          Info" "\n");
}

int my_parse_args(Ctx* ctx, int argc, const char** argv)
{
    int rc;
    char myoptstring[] = "?h:p:u:w:di";
    while ((rc = mygetopt(argc, argv, myoptstring)) != -1) {
        switch ((char)rc) {
        case '?' :
            my_show_usage(ctx);
            return -1;

        case 'h' :
            ctx->host = myoptarg;
            break;

        case 'p' :
            ctx->port = (int)atoi(myoptarg);
            if (ctx->port <= 0 || ctx->port >= 65536 ) {
                printf("Invalid Port Number!");
                return -1;
            }
            break;

        case 'u':
            ctx->username = myoptarg;
            break;

        case 'w':
            ctx->password = myoptarg;
            break;

        case 'd':
            ctx->debug = true;
            break;

        case 'i':
            ctx->info = true;
            break;

        default:
            my_show_usage(ctx);
            return -1;
        }
    }

    myoptind = 0; /* reset for test cases */
    return 0;
}

int main(int argc, const char * argv[])
{
    Ctx ctx;
    init_ctx(&ctx);
    ctx.appname = argv[0];
    my_parse_args(&ctx, argc, argv);
    printf("==============================" "\n");
    printf("\n host: %s \n port: %d \n username: %s \n password: %s \n\n",
            ctx.host, ctx.port, ctx.username, ctx.password);
    if (ctx.debug) {printf("debug mode on.\n");}
    if (ctx.info) {printf("info mode on.\n");}
    return 0;
}
