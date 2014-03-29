This directory contains the source code for Onelab/Mobile, the mobile version of
Onelab for iOS and Android devices.

Version: 1.0.0

Copyright (C) 2014 Maxime Graulich and Christophe Geuzaine, University of Liege

== iOS ==

= Apple AppStore description =

Onelab/Mobile (http://onelab.info) is a finite element package based on the open
source mesh generator Gmsh (http://gmsh.info) and the solver GetDP
(http://getdp.info). It can be used to simulate a wide variety of multi-physic
problems: electromagnetics, thermics, mechanics...

Onelab comes packaged with a selection of ready-to-use examples. New models can
be added through iTunes file sharing: see http://onelab.info/wiki/Mobile for
more information.

= iOS build instructions =

See http://onelab.info/wiki/Mobile

Quick guide if all the dependencies (GetDP, Gmsh, PETSc, BLAS, LAPACK
frameworks) are already installed in ./frameworks_simulator:

* cd ./build_simulator
* cmake -DCMAKE_PREFIX_PATH="$HOME/src/gmsh/contrib/mobile/frameworks_simulator;$HOME/src/getdp" ..
* make xcodeProject 
* open Onelab/Onelab.xcodeproj 

== Android ==

= Google Play store description =

= Android build instructions =

See http://onelab.info/wiki/Mobile
