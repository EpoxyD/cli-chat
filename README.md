# cli-chat
A simple C library for setting up a cli chat server and client. 

### Develop cross platform using Docker
After installing Docker on either Linux, Windows or Mac, use the following commands starting from the project root directory (./cli-chat). These commands will warp you into a terminal session in which make can be used to build the project. Using this method only allows for testing in the same terminal session.

'''
docker build -t buildproject .
docker run -v "${PWD}:/home/builder" --rm -it --name buildroject buildproject
'''