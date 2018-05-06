#pragma once

#define ERROR_INVALID_PROTOCOL -50

int connection_create_socket(int domain, int type);
int connection_bind_socket(int socket);