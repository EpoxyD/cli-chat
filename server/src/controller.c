#include "controller.h"
#include "connection.h"
#include "eventloop.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>

#define READ_BUFFER_SIZE 256

static int epoll_fd;
static int main_socket;
static bool alive = true;

static ssize_t read_data(int fd, void *buffer, size_t n_bytes)
{
    ssize_t bytes;
    bytes = read(fd, buffer, n_bytes);
    if (bytes < 0)
    {
        perror("Error reading data\n");
        exit(-1);
    }
    return bytes;
}

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

            if (events.data.fd == main_socket)
            {
                new_socket = connection_accept_socket(main_socket);
                eventloop_add_event(epoll_fd, new_socket);
            }
            else
            {
                char buffer[READ_BUFFER_SIZE] = {'\0'};
                int bytes_read = read_data(events.data.fd, buffer, READ_BUFFER_SIZE);
                if (bytes_read == 0)
                {
                    close(events.data.fd);
                }
                else
                {
                    fprintf(stdout, "[Buffer] %s\n", buffer);
                }
            }
        }
    }
}

void controller_stop()
{
    alive = false;
    return;
}

void controller_cleanup()
{
    int error = eventloop_close(epoll_fd);
    fprintf(stdout, "Closed        eventloop %d. Status %d\n", epoll_fd, error);
}