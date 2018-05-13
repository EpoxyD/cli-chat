#pragma once

#include <sys/epoll.h>

int eventloop_create_fd();
int eventloop_add_event(int epoll_fd, int socket_fd);
int eventloop_wait(int epoll_fd, struct epoll_event *events);
int eventloop_close(int epoll_fd);