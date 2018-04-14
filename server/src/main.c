#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>

int main(void)
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        perror("Error on opening socket");
        exit(-1);
    }

    struct sockaddr_in sock_in;
    sock_in.sin_family = AF_INET;
    sock_in.sin_port = htons("5000");
    if(inet_pton(AF_INET, "0.0.0.0", &sock_in.sin_addr) != 1)
    {
        perror("Error on converting IP address");
        exit(-1);
    }
    if(bind(sockfd, (struct sockaddr *) &sock_in, sizeof(sock_in)) < 0)
    {
        perror("Error on binding to socket");
        exit(-1);
    }


    
    return 0;
}