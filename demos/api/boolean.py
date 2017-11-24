# This reimplements gmsh/demos/boolean/boolean.geo in Python.

import gmsh
import sys

gmsh.initialize(sys.argv)

gmsh.optionSetNumber("General.Terminal", 1)

gmsh.modelAdd("boolean")

# from http://en.wikipedia.org/wiki/Constructive_solid_geometry

gmsh.optionSetNumber("Mesh.Algorithm", 6);
gmsh.optionSetNumber("Mesh.CharacteristicLengthMin", 0.4);
gmsh.optionSetNumber("Mesh.CharacteristicLengthMax", 0.4);

R = 1.4; Rs = R*.7; Rt = R*1.25

ov = gmsh.PairVector(); ovv = gmsh.PairVectorVector()

gmsh.modelOccAddBox(-R,-R,-R, 2*R,2*R,2*R, 1)
gmsh.modelOccAddSphere(0,0,0,Rt, 2)
gmsh.modelOccBooleanIntersection([(3, 1)], [(3, 2)], ov, ovv, 3)
gmsh.modelOccAddCylinder(-2*R,0,0, 4*R,0,0, Rs, 4)
gmsh.modelOccAddCylinder(0,-2*R,0, 0,4*R,0, Rs, 5)
gmsh.modelOccAddCylinder(0,0,-2*R, 0,0,4*R, Rs, 6)
gmsh.modelOccBooleanUnion([(3, 4), (3, 5)], [(3, 6)], ov, ovv, 7)
gmsh.modelOccBooleanDifference([(3, 3)], [(3, 7)], ov, ovv, 8)

gmsh.modelOccSynchronize();

gmsh.modelMeshGenerate(3)

gmsh.write("boolean.msh")

gmsh.finalize()

