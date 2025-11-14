
# * Dockerfile.debian* is used to create the Docker image for offical Linux
#   builds (using a mature compiler and static dependencies)

# * Dockerfile.ubuntu* is used to create the Docker image for Linux CI builds,
#   using standard, up-to-date dependencies as available in recent ditros

# To rebuild the docker images (change xxx to a random string to rebuild the
# Gmsh lib):

docker build --platform linux/amd64 -f Dockerfile.ubuntu20.04 -t onelab/ubuntu20.04 --build-arg REBUILD_GMSH=xxx .
docker build --platform linux/amd64 -f Dockerfile.ubuntu25.10 -t onelab/ubuntu25.10 --build-arg REBUILD_GMSH=xxx .
docker build --platform linux/amd64 -f Dockerfile.debian.stretch.64bit -t onelab/debian.stretch.64bit --build-arg REBUILD_GMSH=xxx .
docker build --platform linux/amd64 -f Dockerfile.debian.bullseye -t onelab/debian.bullseye --build-arg REBUILD_GMSH=xxx .

# To push the docker images to docker-hub:

docker login
docker push onelab/ubuntu20.04
docker push onelab/ubuntu25.10
docker push onelab/debian.stretch.64bit
docker push onelab/debian.bullseye

# To run something using the docker images:

docker run --platform linux/amd64 onelab/ubuntu20.04 ls -al /'
docker run --platform linux/amd64 -it onelab/ubuntu20.04 bash
docker run --platform linux/amd64 -it onelab/ubuntu25.10 bash -i
docker run --platform linux/amd64 -it onelab/debian.stretch.64bit bash
docker run --platform linux/amd64 -it onelab/debian.bullseye bash
