#include <errno.h>
#include <stdio.h>
#include <sys/epoll.h>

#include "eventloop.h"

int eventloop_create()
{
    int polling_fd;

    polling_fd = epoll_create(1);
    if(polling_fd < 0)
    {
        perror("Error creating an eventloop");
        return polling_fd;
    }

    return polling_fd;
}

int eventloop_close(int polling_fd)
{
    int error;

    error = close(polling_fd);
    if(error < 0)
    {
        perror("Error closing polling file descriptor");
        return error;
    }

    return 0;
}