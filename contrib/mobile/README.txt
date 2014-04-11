This directory contains the source code for Onelab/Mobile, the mobile version of
Onelab for iOS and Android devices.

Version: 1.0.2

Copyright (C) 2014 Christophe Geuzaine and Maxime Graulich, University of Liege

See http://onelab.info/wiki/Mobile for more information, including how to build
Onelab/Mobile for iOS (iPhone/iPad) and Android devices.

Quick cheat sheet for iOS if all the dependencies (GetDP, Gmsh, PETSc, BLAS,
LAPACK frameworks) are already installed in ./frameworks_simulator:

mkdir build
cd build
cmake -DCMAKE_PREFIX_PATH="$HOME/src/gmsh/contrib/mobile/frameworks_simulator;\
                           $HOME/src/getdp" ..
make xcodeProject 
open Onelab/Onelab.xcodeproj

--

Store description:

Onelab (http://onelab.info) is a finite element package based on the open source
mesh generator Gmsh (http://gmsh.info) and the solver GetDP
(http://getdp.info). It can be used to simulate a wide variety of multi-physic
problems: electromagnetics, thermics, mechanics...

Onelab comes packaged with a selection of ready-to-use examples. New models can
be added through iTunes file sharing: see http://onelab.info/wiki/Mobile for
more information.

iTunes link:

https://itunes.apple.com/us/app/onelab/id845930897

Google Play link:

Coming soon!
