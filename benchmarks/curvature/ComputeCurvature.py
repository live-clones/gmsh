from dgpy import *
from gmshpy import *
import os
import sys

#if (os.path.isfile("Torus.msh")) :
  #print('---- The mesh file already exists ----');

#else :
  #cmd = "gmsh -3 Torus.geo"
  #os.system(cmd)
  #print('---- Mesh has been executed ----');
  
#meshName = "Torus"
#meshName = "Sphere"
meshName = "Bifurcation"

g = GModel()

#g.load(meshName+".geo")
g.load(meshName+".msh")
print "Model is loaded"

#g.compute_curvature("Wall","curvature.pos")


cv = Curvature(g)
cv.retrievePhysicalSurfaces("Wall")
cv.computeCurvature_Rusinkiewicz()
cv.writeToFile("result.pos")


  
print "Youpiii Exit :-)"
sys.exit(0)
