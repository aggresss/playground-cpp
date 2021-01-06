#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

static void usage(const char *proc) {
    printf("please use : %s [ip] [port]\n", proc);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        usage(argv[0]);
        exit(1);
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket error");
        return 1;
    }

    struct sockaddr_in remote;
    remote.sin_family = AF_INET;
    remote.sin_port = htons(atoi(argv[2]));
    remote.sin_addr.s_addr = inet_addr(argv[1]);

    int ret = connect(sock, (struct sockaddr *)&remote, sizeof(remote));
    if (ret < 0) {
        printf("connect failed:%s\n", strerror(errno));
        return 2;
    }

    printf("connect success!\n");

    char buf[1024];
    while (1) {
        memset(buf, '\0', sizeof(buf));
        printf("please enter:");
        fflush(stdout);
        ssize_t _s = read(0, buf, sizeof(buf) - 1);
        if (_s > 0) {
            buf[_s - 1] = '\0';
            write(sock, buf, strlen(buf));
            _s = read(sock, buf, sizeof(buf) - 1);
            if (_s > 0) {
                if (strncasecmp(buf, "quit", 4) == 0) {
                    printf("qiut\n");
                    break;
                }
                buf[_s - 1] = '\0';
                printf("%s\n", buf);
            }
        }
    }
    close(sock);
    return 0;
}
