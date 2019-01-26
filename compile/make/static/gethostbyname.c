// fork from https://blog.csdn.net/daiyudong2020/article/details/51946080

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>

extern int h_errno;

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Use example: %s www.google.com\n", *argv);
        return -1;
    }

    char *name = argv[1];
    struct hostent *hptr;

    hptr = gethostbyname(name);
    if (hptr == NULL) {
        printf("gethostbyname error for host: %s: %s\n", name, hstrerror(h_errno));
        return -1;
    }
    // output host official name
    printf("\tofficial: %s\n", hptr->h_name);

    // output host alias name
    char **pptr;
    char str[INET_ADDRSTRLEN];
    for (pptr=hptr->h_aliases; *pptr!=NULL; pptr++) {
        printf("\ttalias: %s\n", *pptr);
    }

    // output ip address
    switch (hptr->h_addrtype) {
        case AF_INET:
            pptr = hptr->h_addr_list;
            for (; *pptr!=NULL; pptr++) {
                printf("\taddress: %s\n",
                        inet_ntop(hptr->h_addrtype, hptr->h_addr, str, sizeof(str)));
            }
            break;
        default:
            printf("unknown address type\n");
            break;
    }

    return 0;
}
