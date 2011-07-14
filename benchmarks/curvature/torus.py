#!/usr/bin/env python

from gmshpy import *

lc = 0.8
GmshSetOption('Mesh', 'CharacteristicLengthFactor', lc)

R = 1 ;
g = GModel();
g.setFactory('OpenCASCADE')

#g.addBlock([-R,-R,-R],[R,R,R]);
g.addTorus([0,0,0],[1,0,0], 2.0, 1.5);

#g.mesh(2);
#g.save("occtorus.msh");
g.save("occtorus.brep");

#FlGui.instance();
#FlGui.run();
