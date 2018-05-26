FROM alpine

RUN apk update; \
    apk add gcc make libc-dev valgrind;

WORKDIR /home/builder