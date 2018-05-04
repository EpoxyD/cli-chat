#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>

#include "connection.h"

int connection_create_socket(int domain, int type)
{
    int sock;

    sock = socket(domain, type, 0);
    if (sock < 0)
    {
        perror("Error creating socket");
        return sock;
    }

    return sock;
}