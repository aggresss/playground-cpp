#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <time.h>
#include <unistd.h>

#define DST_ADDR "/tmp/uds_test.socket"

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_un dst;

    sockfd = socket(AF_UNIX, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("create socket failed");
        exit(EXIT_FAILURE);
    }

    memset(&dst, 0, sizeof(dst));
    dst.sun_family = AF_UNIX;
    strcpy(dst.sun_path, DST_ADDR);
    int len;
    len = offsetof(struct sockaddr_un, sun_path) +
          sizeof(DST_ADDR);

    time_t t;
    char *str;

    for (;;) {
        t = time(NULL);
        str = ctime(&t);
        if (str == NULL)
            break;

        sendto(sockfd, str, strlen(str), 0,
               (struct sockaddr *)&dst, len);

        sleep(1);
    }

    return 0;
}