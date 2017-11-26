# This reimplements gmsh/demos/boolean/boolean.geo in Python.

import gmsh
import sys
import math #FIXME default args

model = gmsh.model
factory = model.occ

gmsh.initialize(sys.argv)

gmsh.option.setNumber("General.Terminal", 1)

model.add("boolean")

# from http://en.wikipedia.org/wiki/Constructive_solid_geometry

gmsh.option.setNumber("Mesh.Algorithm", 6);
gmsh.option.setNumber("Mesh.CharacteristicLengthMin", 0.4);
gmsh.option.setNumber("Mesh.CharacteristicLengthMax", 0.4);

R = 1.4; Rs = R*.7; Rt = R*1.25

factory.addBox(-R,-R,-R, 2*R,2*R,2*R, 1)
factory.addSphere(0,0,0,Rt, 2, -math.pi/2, math.pi/2, 2*math.pi)#FIXME default args
factory.booleanIntersection([(3, 1)], [(3, 2)], 3, True,True) #FIXME default args
factory.addCylinder(-2*R,0,0, 4*R,0,0, Rs, 4, 2*math.pi)#FIXME default args
factory.addCylinder(0,-2*R,0, 0,4*R,0, Rs, 5, 2*math.pi)#FIXME default args
factory.addCylinder(0,0,-2*R, 0,0,4*R, Rs, 6, 2*math.pi)#FIXME default args
factory.booleanUnion([(3, 4), (3, 5)], [(3, 6)], 7, True,True) #FIXME default args
factory.booleanDifference([(3, 3)], [(3, 7)], 8, True,True) #FIXME default args

factory.synchronize();

model.mesh.generate(3)

gmsh.write("boolean.msh")

gmsh.finalize()

