#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
    int client_sockfd;
    int len;
    struct sockaddr_in address;//服务器端网络地址结构体
     int result;
    char ch = 'A';
    client_sockfd = socket(AF_INET, SOCK_STREAM, 0);//建立客户端socket
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(“127.0.0.1”);
    address.sin_port = 9734;
    len = sizeof(address);
    result = connect(client_sockfd, (struct sockaddr *)&address, len);
    if(result == -1)
    {
         perror("oops: client2");
         exit(1);
    }
    write(client_sockfd, &ch, 1);
    read(client_sockfd, &ch, 1);
    printf("char from server = %c/n", ch);
    close(client_sockfd);
    zexit(0);
}
