== Official releases ==

Docker image for offical Linux builds (using a mature compiler and statically
linked dependencies) - change xxx to a random string to only rebuild the Gmsh
library:

* Gmsh 4.x releases, based on Debian 9 (Stretch, GLIBC 2.24)

> docker build --platform linux/amd64 -f Dockerfile.debian.stretch.64bit -t onelab/debian.stretch.64bit --build-arg REBUILD_GMSH=xxx .

* Gmsh 5.x releases, based on Debian 10 (Buster, GLIBC 2.28)

> docker build --platform linux/amd64 -f Dockerfile.debian.buster -t onelab/debian.buster --build-arg REBUILD_GMSH=xxx .

== CI builds ==

Docker image for Linux CI builds, using a recent distribution with pre-compiled
dependencies + tools useful for CI testing (valgrind, ...):

> docker build --platform linux/amd64 -f Dockerfile.ci -t onelab/ci --build-arg REBUILD_GMSH=xxx .

== Pushing the docker images to docker-hub ==

> docker login
> docker push onelab/debian.buster
> docker push onelab/ci

== Running something using the docker images ==

> docker run --platform linux/amd64 -it onelab/debian.buster bash -i
> docker run --platform linux/amd64 -it onelab/ci bash -i
