#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>

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

    struct sockaddr_in local;
    local.sin_family = AF_INET;
    local.sin_port = htons(atoi(argv[2]));
    local.sin_addr.s_addr = inet_addr(argv[1]); // or INADDR_ANY

    int reuse = 1;
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));

    // 2.bind

    if (bind(sock, (struct sockaddr *)&local, sizeof(local)) < 0) {
        perror("bind error");
        return 3;
    }

    // 3. recvfrom

    int done = 0;
    struct sockaddr_in peer;
    socklen_t len = sizeof(peer);

    char buf[1024];
    while (!done) {
        memset(buf, '\0', sizeof(buf));
        printf("Please Enter:");
        recvfrom(sock, buf, sizeof(buf), 0, (struct sockaddr *)&peer, &len);
        printf("get a client,socket: %s:%d\n", inet_ntoa(peer.sin_addr), ntohs(peer.sin_port));
        printf("client : %s ,echo client!\n", buf);
    }
    return 0;
}
