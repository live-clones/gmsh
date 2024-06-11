
# * Dockerfile.debian.stretch.64bit is used to create the Docker image
#   onelab/debian.stretch.64bit, used for the offical Linux builds
#
# * Dockerfile.ubuntu20.04 is used to create the Docker image
#   onelab/ubuntu20.04, used for the Linux continuous integration builds

# To rebuild the docker images (change xxx to a random string to rebuild the
# Gmsh lib):

docker build -f Dockerfile.debian.stretch.64bit -t onelab/debian.stretch.64bit --build-arg REBUILD_GMSH=xxx .
docker build --platform linux/amd64 -f Dockerfile.ubuntu20.04 -t onelab/ubuntu20.04 --build-arg REBUILD_GMSH=xxx .

# To push the docker images to docker-hub:

docker login
docker push onelab/ubuntu20.04
docker push onelab/debian.stretch.64bit

# To run something using the docker images:

docker run onelab/ubuntu20.04 ls -al /'
docker run -it onelab/ubuntu20.04 bash
docker run -it onelab/debian.stretch.64bit bash
