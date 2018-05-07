# cli-chat
A simple C library for setting up a cli chat server and client. 

### Develop cross platform using Docker
After installing Docker on either Linux, Windows or Mac, use the following commands starting from the project root directory (./cli-chat). These commands will warp you into a terminal session in which make can be used to build the project. Using this method only allows for testing in the same terminal session.

Check at first if you already have the buildproject container running
``` bash
docker ps
```

If the container is already there, reuse it with
```  bash
docker attach buildproject
```

Else, build and start the container from scratch
```  bash
docker build -t buildproject .
docker run -v "${PWD}:/home/builder" --rm -it --name buildproject buildproject
```

