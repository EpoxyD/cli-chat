#define _GNU_SOURCE
#include <errno.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>  
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>

#include "connection.h"

#ifndef WANIP
#define WANIP "127.0.0.1"
#endif

#ifndef PORT
#define PORT 5000
#endif

int connection_create_socket()
{
    int socket_fd, error;
    char port[5];
    struct addrinfo hints, *res;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    sprintf(port, "%d", PORT);
    getaddrinfo(WANIP, port, &hints, &res);
    socket_fd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (socket_fd == -1)
    {
        perror("Error creating socket");
        exit(-1);
    }

    error = bind(socket_fd, res->ai_addr, res->ai_addrlen);
    if (error == -1)
    {
        perror("Error binding socket");
        exit(-1);
    }

    return socket_fd;
}

int connection_connect_socket(int socket)
{
    return 0;
}