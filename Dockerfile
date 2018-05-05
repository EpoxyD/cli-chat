FROM alpine

RUN apk update; \
    apk add gcc make libc-dev;

WORKDIR /home/builder