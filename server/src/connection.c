#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include "connection.h"

#ifndef WANIP
#define WANIP "127.0.0.1"
#endif

#ifndef PORT
#define PORT 5000
#endif

int connection_create_socket(int domain, int type)
{
    int sock;

    sock = socket(domain, type, 0);
    if (sock < 0)
    {
        perror("Error creating socket");
        exit(-1);
    }

    return sock;
}

int connection_bind_socket(int socket)
{
    int error;
    struct sockaddr_in inaddr;

    memset(&inaddr, 0, sizeof(struct sockaddr_in));
    inaddr.sin_family = AF_INET;
    inaddr.sin_port = htons(PORT);
    inet_aton(WANIP, &inaddr.sin_addr);

    error = bind(socket, (const struct sockaddr *)&inaddr, sizeof(inaddr));
    if (error < 0)
    {
        perror("Error binding on socket");
        exit(-1);
    }

    return 0;
}

int connection_listen_socket(int socket)
{
    int error;

    error = listen(socket, 10);
    if (error < 0)
    {
        perror("Error listening on socket");
        exit(-1);
    }

    return 0;
}

int connection_accept_socket(int socket)
{
    int new_fd, size;
    struct sockaddr_in inaddr;

    memset(&inaddr, 0, sizeof(inaddr));
    size = sizeof(inaddr);

    new_fd = accept(socket, (struct sockaddr *)&inaddr, (socklen_t *)&size);
    if (new_fd < 0)
    {
        perror("Error accepting connection on socket");
        exit(-1);
    }

    return new_fd;
}
