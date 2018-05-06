#include "controller.h"
#include "connection.h"

#include <stdio.h>
#include <sys/socket.h>

void controller_init()
{
    int socket, error;
    socket = connection_create_socket(AF_INET, SOCK_STREAM);
    fprintf(stdout, "Created socket %d\n", socket);
    error = connection_bind_socket(socket);
    fprintf(stdout, "Bind socket %d. Status %d\n", socket, error);
}

void controller_run()
{
}

void controller_cleanup()
{
}