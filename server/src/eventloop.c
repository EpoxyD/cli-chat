#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "eventloop.h"

static int max_events;

int eventloop_create_fd()
{
    int epoll_fd;

    epoll_fd = epoll_create(1);
    if (epoll_fd < 0)
    {
        perror("Error creating an eventloop");
        exit(-1);
    }

    fprintf(stdout, "Created eventloop with FD %d\n", epoll_fd);

    return epoll_fd;
}

int eventloop_add_event(int epoll_fd, int socket_fd)
{
    struct epoll_event event;

    memset(&event, 0, sizeof(struct epoll_event));

    event.events = EPOLLIN;
    event.data.fd = socket_fd;

    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, socket_fd, &event))
    {
        perror("Error creating an event");
        exit(-1);
    }

    max_events++;

    fprintf(stdout, "Added event EPOLLIN on eventloop FD %d for socket %d. Max events = %d\n", epoll_fd, socket_fd, max_events);

    return 0;
}

int eventloop_wait(int epoll_fd, struct epoll_event *events)
{
    int nr_of_fd;

    nr_of_fd = epoll_wait(epoll_fd, events, max_events, 1000);
    if (nr_of_fd < 0)
    {
        perror("Error closing polling file descriptor");
        exit(-1);
    }

    fprintf(stdout, "Number of FD's fired: %d\n", nr_of_fd);

    return nr_of_fd;
}

int eventloop_close(int epoll_fd)
{
    int error;

    error = close(epoll_fd);
    if (error < 0)
    {
        perror("Error closing polling file descriptor");
        exit(-1);
    }

    fprintf(stdout, "Closing eventloop FD %d\n", epoll_fd);

    return 0;
}
