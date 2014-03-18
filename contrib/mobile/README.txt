iOS:

Version: 1.0.0

SKU: org.geuz.Onelab

Description:

Onelab (http://onelab.info) is a finite element package based on the open source mesh generator Gmsh (http://gmsh.info) and the solver GetDP (http://getdp.info). It can be used to simulate a wide variety of multi-physic problems: electromagnetics, thermics, mechanics...

Onelab comes packaged with a selection of ready-to-use examples. New models can be added through iTunes file sharing: see http://onelab.info/wiki/Mobile for more information.



=====

How to build the mobile version for iOS:

http://onelab.info/wiki/Mobile

In short, if all the frameworks are installed in ./frameworks:

cd ./build
cmake -DCMAKE_PREFIX_PATH="$HOME/src/gmsh/contrib/mobile/frameworks;$HOME/src/getdp" ..
make xcodeProject 
open Onelab/Onelab.xcodeproj 

cd ./build_simulator
cmake -DCMAKE_PREFIX_PATH="$HOME/src/gmsh/contrib/mobile/frameworks_simulator;$HOME/src/getdp" ..
make xcodeProject 
open Onelab/Onelab.xcodeproj 

