from gmshpy import *
import sys
import pickle
import preprofix
name = "Submarine"

g = GModel()
g.load(name + ".geo")
g.mesh(3)
g.writeMSH(name + ".msh", 3.0)
#g.load(name + ".msh")
g.setAllVolumesPositiveTopology()

g.writeMSH(name + "_topology.msh", 3.0)
preprofix.fixTetras(g)
preprofix.fixPyramids(g)
preprofix.fixPrisms(g)
preprofix.fixHexs(g)
g.writeMSH(name + "_FIX.msh", 3.0)

#exit()
#preprofix.fixPyramids(g)

#g.writeMSH(name + "Fix.msh",3.0)

OH = MeshQualOptParameters()
OH.onlyVisible = False
OH.dim = 3
OH.fixBndNodes = False    # Fix boundary nodes or not
OH.strategy = 0           # 0 = Connected blobs, 1 = Adaptive one-by-one (recommended in 3D)

OH.excludeHex = False
OH.excludePrism = False
OH.nbLayers = 3          # Nb. of layers around invalid element to construct blob
OH.distanceFactor = 3    # Distance factor to construct blob
OH.maxPatchAdapt = 5       # Number of blob adaption iteration
OH.maxLayersAdaptFact = 3 # Factor to multiply nb. of layers when adapting
OH.distanceAdaptFact = 3 # Factor to multiply distance factor when adapting
#OH.weight = 0
OH.onlyValidity = False
#OH.minTargetIdealJac = 0.1
OH.minTargetInvCondNum = 0.3

#OH.weightFixed = 1.e-3
#OH.weightFree = 1.e-6

OH.nCurses = 1
OH.logFileName = "log"

OH.maxOptIter = 20             # Nb of optimixation iterations
OH.maxBarrierUpdates = 15        # Nb. of optimization passes

#print("minTargetIdealJac = %g" % OH.minTargetIdealJac)
print("minTargetInvCondNum = %g" % OH.minTargetInvCondNum)
print("nbLayers = %g, distanceFactor = %g" % (OH.nbLayers, OH.distanceFactor))
print("itMax = %g, optPassMax = %g" % (OH.maxOptIter, OH.maxBarrierUpdates))
#print("weightFree = %g, weightFixed = %g" % (OH.weightFree, OH.weightFixed))
print("strategy = %g" % OH.strategy)
print("maxAdaptBlob = %g" % OH.maxPatchAdapt)
print("maxLayersAdaptFact = %g, distanceAdaptFact = %g" % (OH.maxLayersAdaptFact, OH.distanceAdaptFact))

MeshQualityOptimizer(g, OH)

#print("RESULT: minNCJ = %g, maxNCJ = %g, CPU = %g" % (OH.minNCJ, OH.maxNCJ, OH.CPU))
#print("RESULT: minInvIdealJac = %g, maxInvIdealJac = %g, CPU = %g" %
#      (OH.minIdealJac, OH.maxIdealJac, OH.CPU))
print("RESULT: minInvCondNum = %g, maxInvCondNum = %g, CPU = %g" %
      (OH.minInvCondNum, OH.maxInvCondNum, OH.CPU))

g.writeMSH(name + "_opt.msh", 3.0)
pOpt = meshPartitionOptions()
pOpt.setNumOfPartitions(5)
PartitionMesh(g,  pOpt)
g.writeMSH(name + "_opt_part.msh", 3.0)

#g.writeMSH(name + "_OK.msh",3.0,False,False,False,1.0,0,0)

