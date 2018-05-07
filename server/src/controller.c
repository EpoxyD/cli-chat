#include "controller.h"
#include "connection.h"
#include "eventloop.h"

#include <stdbool.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>

static int epoll_fd;
static int main_socket;
static bool alive;

static int epoll_fd;
static int main_socket;

void controller_init()
{
    main_socket = connection_create_socket(AF_INET, SOCK_STREAM);
    fprintf(stdout, "Created   socket %d\n", main_socket);
    int error = connection_bind_socket(main_socket);
    fprintf(stdout, "Bind   on socket %d. Status %d\n", main_socket, error);
    error = connection_listen_socket(main_socket);
    fprintf(stdout, "Listen on socket %d. Status %d\n", main_socket, error);
<<<<<<< HEAD

    epoll_fd = eventloop_create_fd();
    fprintf(stdout, "Created       eventloop %d\n", epoll_fd);
    error = eventloop_add_event(epoll_fd, main_socket);
    fprintf(stdout, "Added fd %d to eventloop %d. Status %d\n", main_socket,
            epoll_fd, error);
=======
    
    epoll_fd = eventloop_create_fd();
    fprintf(stdout, "Created       eventloop %d\n", epoll_fd);
>>>>>>> Add events to eventloop
}

void controller_run()
{
<<<<<<< HEAD
    alive = true;
    while (alive)
    {
        sleep(1);
    }
}

void controller_stop()
{
    alive = false;
    return;
=======
    int error = eventloop_add_event(epoll_fd, main_socket);
    fprintf(stdout, "Added fd %d to eventloop %d. Status %d\n", main_socket, epoll_fd, error);
>>>>>>> Add events to eventloop
}

void controller_cleanup()
{
    int error = eventloop_close(epoll_fd);
    fprintf(stdout, "Closed        eventloop %d. Status %d\n", epoll_fd, error);
}