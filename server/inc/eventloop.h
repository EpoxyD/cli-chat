#pragma once

int eventloop_create_fd();
int eventloop_add_event(int epoll_fd, int socket_fd);
int eventloop_wait(int epoll_fd);
int eventloop_close(int epoll_fd);