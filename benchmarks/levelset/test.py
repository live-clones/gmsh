
from gmshpy import *
import math

#Define levelset
ls1 = gLevelsetMathEval('x^2+y^2-0.8',1)
ls2 = gLevelsetPlane(0,0,1,-0.5,2)
ls3 = gLevelsetUnion([ls1,ls2])
		
#Mesh geometry
mesh = GModel()
mesh.load("cube.geo")
mesh.mesh(3)

#Cut mesh
model1 = GModel()
model1 = mesh.buildCutGModel(ls3, True, False) # ls, cutElements?, write triangles?

model1.save("cube2.msh")

