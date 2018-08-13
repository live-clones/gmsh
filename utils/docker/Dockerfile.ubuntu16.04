FROM ubuntu:16.04

RUN apt-get update && apt-get install -y cmake curl g++ gfortran libfltk1.3-dev libfreetype6-dev libgl1-mesa-dev liblapack-dev libxi-dev libxmu-dev mesa-common-dev tcl-dev tk-dev
RUN curl -L -o occ71.tgz "http://git.dev.opencascade.org/gitweb/?p=occt.git;a=snapshot;h=refs/tags/V7_1_0;sf=tgz"
RUN tar xf occ71.tgz
RUN cd occt-V7_1_0 && mkdir build && cd build && cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_MODULE_Draw=0 -DBUILD_MODULE_Visualization=0 -DBUILD_MODULE_ApplicationFramework=0 .. && cat CMakeCache.txt && make -j8
RUN cd occt-V7_1_0/build && make install

VOLUME ["/etc/gitlab-runner"]
RUN useradd -ms /bin/bash validator
USER validator
WORKDIR /home/validator
