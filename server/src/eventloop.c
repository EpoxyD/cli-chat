#include <errno.h>
#include <stdio.h>
#include <sys/epoll.h>
#include <unistd.h>

#include "eventloop.h"

int eventloop_create_fd()
{
    int epoll_fd;

    epoll_fd = epoll_create(1);
    if (epoll_fd < 0)
    {
        perror("Error creating an eventloop");
        return epoll_fd;
    }

    return epoll_fd;
}

int eventloop_add_event(int epoll_fd, int socket_fd)
{
    struct epoll_event event;
    event.events = EPOLLIN;
    event.data.fd = socket_fd;

    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, socket_fd, &event))
    {
        perror("Error creating an event");
        return -1;
    }

    return 0;
}

int eventloop_close(int epoll_fd)
{
    int error;

    error = close(epoll_fd);
    if (error < 0)
    {
        perror("Error closing polling file descriptor");
        return error;
    }

    return 0;
}
