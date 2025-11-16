# ------------------------------------------------------------------------------
# Debian docker images for offical Linux builds (using a mature compiler and
# static dependencies) - (change xxx to a random string to rebuild the Gmsh lib)
# ------------------------------------------------------------------------------

* Debian 9 (Stretch) GLIBC 2.24

docker build --platform linux/amd64 -f Dockerfile.debian.stretch.64bit -t onelab/debian.stretch.64bit --build-arg REBUILD_GMSH=xxx .

* Debian 10 (Buster) GLIBC 2.28

docker build --platform linux/amd64 -f Dockerfile.debian.buster -t onelab/debian.buster --build-arg REBUILD_GMSH=xxx .

* Debian 11 (Bullseye) GLIBC 2.31

docker build --platform linux/amd64 -f Dockerfile.debian.bullseye -t onelab/debian.bullseye --build-arg REBUILD_GMSH=xxx .

# ------------------------------------------------------------------------------
# Ubuntu docker images for Linux CI builds, using standard dependencies as
# available in recent ditros
# ------------------------------------------------------------------------------

* Ubuntu 20.04

docker build --platform linux/amd64 -f Dockerfile.ubuntu20.04 -t onelab/ubuntu20.04 --build-arg REBUILD_GMSH=xxx .

* Debian 13 (Trixie)

docker build --platform linux/amd64 -f Dockerfile.ci -t onelab/ci --build-arg REBUILD_GMSH=xxx .

# ------------------------------------------------------------------------------
# To push the docker images to docker-hub:
# ------------------------------------------------------------------------------

docker login
docker push onelab/debian.buster
docker push onelab/ci

# ------------------------------------------------------------------------------
# To run something using the docker images:
# ------------------------------------------------------------------------------

docker run --platform linux/amd64 onelab/ubuntu20.04 ls -al /'
docker run --platform linux/amd64 -it onelab/ubuntu20.04 bash
docker run --platform linux/amd64 -it onelab/ubuntu25.10 bash -i
docker run --platform linux/amd64 -it onelab/debian.stretch.64bit bash
docker run --platform linux/amd64 -it onelab/debian.buster bash -i
docker run --platform linux/amd64 -it onelab/debian.bullseye bash
