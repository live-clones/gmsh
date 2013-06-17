#!/usr/bin/env python
from gmshpy import *
import numpy as np

GmshSetOption('Mesh', 'CharacteristicLengthFactor', 10.)
GmshSetOption('Mesh', 'Algorithm', 1.0)
GmshSetOption('Mesh', 'Algorithm3D',4.0)

myModel = GModel()

R = np.pi

myModel.addBlock([-R,-R,-R],[R,R,R])
myModel.addSphere(0,0,0,R/4)
myModel.addBlock([-R,-R,R],[R,R,2*R])
myModel.addBlock([-R,-R,2*R],[R,R,4*R])
myModel.addBlock([-R,-R,4*R],[R,R,8*R])
myModel.addBlock([-R,-R,8*R],[R,R,12*R])
myModel.addBlock([-R,-R,-2*R],[R,R,-R])

### connect, geomanalyse with salome partition splitter
myModel.salomeconnect()

### auto copy mesh from faces translated of a vector given vector T
### arg1: translation vector from master to slave
myModel.setPeriodicAllFaces([0.,2*R,0.])
myModel.setPeriodicAllFaces([2*R,0,0.])

### assign Physical number to entities in a box with setPhysicalNumToEntitiesInBox
### arg1: (O:vertex, 1:edge, 2:face, 3:volume)
### arg2: physical number you want
### arg3: bounding box (2 diagonal corners)
myModel.setPhysicalNumToEntitiesInBox(2,11,[-R-R/4,-R-R/4,-2*R-R/4],[R+R/4,-R+R/4,12*R+R/4])
myModel.setPhysicalNumToEntitiesInBox(2,12,[-R-R/4,R-R/4,-2*R-R/4],[R+R/4,R+R/4,12*R+R/4])
myModel.setPhysicalNumToEntitiesInBox(2,21,[-R-R/4,-R-R/4,-2*R-R/4],[-R+R/4,R+R/4,12*R+R/4])
myModel.setPhysicalNumToEntitiesInBox(2,22,[R-R/4,-R-R/4,-2*R-R/4],[R+R/4,R+R/4,12*R+R/4])

print myModel.noPhysicalGroups()

myModel.mesh(2)

myModel.setAsCurrent()
myModel.setVisibility(1)
FlGui.instance()
FlGui.run()
FlGui.close()

