#include <arpa/inet.h>
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

    // 1.create socket

    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("creat socket error\n");
        return 2;
    }

    // 2. sendto
    struct sockaddr_in remote;
    remote.sin_family = AF_INET;
    remote.sin_port = htons(atoi(argv[2]));
    remote.sin_addr.s_addr = inet_addr(argv[1]);

    int done = 0;
    char buf[1024];
    while (!done) {
        memset(buf, '\0', sizeof(buf));
        printf("Please Enter:");
        fflush(stdout);
        ssize_t _s = read(0, buf, sizeof(buf) - 1);
        (void)_s;
        sendto(sock, buf, sizeof(buf), 0, (struct sockaddr *)&remote, sizeof(remote));
    }
    return 0;
}
