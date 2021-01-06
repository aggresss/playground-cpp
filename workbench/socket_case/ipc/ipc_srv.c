#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>

#define SRC_ADDR "/tmp/uds_test.socket"

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_un src;

    unlink(SRC_ADDR);
    sockfd = socket(AF_UNIX, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("create socket failed");
        exit(EXIT_FAILURE);
    }

    memset(&src, 0, sizeof(src));
    src.sun_family = AF_UNIX;
    strcpy(src.sun_path, SRC_ADDR);
    int len;
    len = offsetof(struct sockaddr_un, sun_path) +
          sizeof(SRC_ADDR);

    if (bind(sockfd, (struct sockaddr *)&src, len) < 0) {
        perror("bind socket failed");
        exit(EXIT_FAILURE);
    }

    size_t size = 0;
    char buf[BUFSIZ] = {'\0'};
    for (;;) {
        size = recvfrom(sockfd, buf, BUFSIZ, 0,
                        NULL, NULL);

        if (size > 0)
            printf("recv: %s\n", buf);
    }

    return 0;
}