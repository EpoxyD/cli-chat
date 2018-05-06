#include "controller.h"
#include "connection.h"
#include "eventloop.h"

#include <stdio.h>
#include <sys/socket.h>

void controller_init()
{
    int socket, error, polling_fd;
    socket = connection_create_socket(AF_INET, SOCK_STREAM);
    fprintf(stdout, "Created socket %d\n", socket);
    error = connection_bind_socket(socket);
    fprintf(stdout, "Bind socket %d. Status %d\n", socket, error);
    error = connection_listen_socket(socket);
    fprintf(stdout, "Listen on socket %d. Status %d\n", socket, error);
    
    polling_fd = eventloop_create();
    fprintf(stdout, "Created eventloop %d\n", polling_fd);
    error = eventloop_close(polling_fd);
    fprintf(stdout, "Closed eventloop %d. Status %d\n", polling_fd, error);
}

void controller_run()
{
}

void controller_cleanup()
{
}