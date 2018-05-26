# cli-chat
A simple C library for setting up a cli chat server and client. 

### Develop cross platform using Docker
After installing Docker on either Linux, Windows or Mac, use the following commands starting from the project root directory (./cli-chat). These commands will warp you into a terminal session in which make can be used to build the project. Using this method only allows for testing in the same terminal session.

Check at first if you already have the chatbuilder container running
``` bash
docker ps
```

If the container is already there, reuse it with
```  bash
docker attach chatbuilder
```

If you do not have the container running, check if you already have the chatbuilder image
``` bash
docker image ls
```

If this is not the case, build it.
```  bash
docker build -t chatbuilder .
```

Once you have the image, start the container using
```  bash
docker run -v "${PWD}:/home/builder" --rm -it --name chatbuilder chatbuilder
```

