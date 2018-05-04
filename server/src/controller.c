#include "controller.h"
#include "connection.h"

#include <stdio.h>
#include <sys/socket.h>

void controller_init()
{
}

void controller_run()
{
    int socket;
    socket = connection_create_socket(AF_INET, SOCK_STREAM);
    fprintf(stdout, "Created socket %d\n", socket);
}

void controller_cleanup()
{
}