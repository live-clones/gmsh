# This reimplements gmsh/demos/boolean/boolean.geo in Python.

from gmsh import *
import sys

gmshInitialize(sys.argv)

gmshOptionSetNumber("General.Terminal", 1)

gmshModelCreate("boolean")

# from http://en.wikipedia.org/wiki/Constructive_solid_geometry

gmshOptionSetNumber("Mesh.Algorithm", 6);
gmshOptionSetNumber("Mesh.CharacteristicLengthMin", 0.4);
gmshOptionSetNumber("Mesh.CharacteristicLengthMax", 0.4);

R = 1.4; Rs = R*.7; Rt = R*1.25

ov = PairVector(); ovv = PairVectorVector()

gmshModelOccAddBox(1, -R,-R,-R, 2*R,2*R,2*R)
gmshModelOccAddSphere(2, 0,0,0,Rt)
gmshModelOccBooleanIntersection(3, [(3, 1)], [(3, 2)], ov, ovv)
gmshModelOccAddCylinder(4, -2*R,0,0, 4*R,0,0, Rs)
gmshModelOccAddCylinder(5, 0,-2*R,0, 0,4*R,0, Rs)
gmshModelOccAddCylinder(6, 0,0,-2*R, 0,0,4*R, Rs)
gmshModelOccBooleanUnion(7, [(3, 4), (3, 5)], [(3, 6)], ov, ovv)
gmshModelOccBooleanDifference(8, [(3, 3)], [(3, 7)], ov, ovv)

gmshModelOccSynchronize();

gmshModelMesh(3)

gmshExport("boolean.msh")

gmshFinalize()

