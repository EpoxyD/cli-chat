#include "controller.h"
#include "connection.h"
#include "eventloop.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>

static int epoll_fd;
static int main_socket;
static bool alive = true;

void controller_init()
{
    main_socket = connection_create_socket(AF_INET, SOCK_STREAM);
    connection_bind_socket(main_socket);
    connection_listen_socket(main_socket);

    epoll_fd = eventloop_create_fd();
    eventloop_add_event(epoll_fd, main_socket);
}

void controller_run()
{
    alive = true;
    int loop, new_socket, nr_of_fd;
    struct epoll_event events;

    while (alive)
    {
        nr_of_fd = eventloop_wait(epoll_fd, &events);

        for (loop = 0; loop < nr_of_fd; ++loop)
        {
            fprintf(stdout, "[Events] events  = %d\n", events.events);
            fprintf(stdout, "[Events] data.fd = %d\n", events.data.fd);

            if(events.data.fd == main_socket)
            {
                new_socket = connection_accept_socket(main_socket);
                eventloop_add_event(epoll_fd, new_socket);
            }
            else
            {
                char buffer[10];
                int error = read(events.data.fd, buffer, 10);
                if(error < 0)
                {
                    perror("Error reading data\n");
                    exit(-1);
                }
                else if(error == 0)
                {
                    close(events.data.fd);
                }
                else if(error < 10)
                {
                    buffer[error] = '\0';
                }
                fprintf(stdout, "[Buffer] %s\n", buffer);
            }
        }

        fprintf(stdout, "I'm in a loop\n");
    }
}

void controller_stop()
{
    alive = false;
    return;
    int error = eventloop_add_event(epoll_fd, main_socket);
    fprintf(stdout, "Added fd %d to eventloop %d. Status %d\n", main_socket, epoll_fd, error);
}

void controller_cleanup()
{
    int error = eventloop_close(epoll_fd);
    fprintf(stdout, "Closed        eventloop %d. Status %d\n", epoll_fd, error);
}