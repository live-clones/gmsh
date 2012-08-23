import math
from gmshpy import *
from Common import *

def Adaptation ( gm , gm_adapt) :

    print "hello 1"
    myMap = IntDoubleVectorMap ()
    gf = gm.getFaceByTag(6)
    print "hello 2"
    for i in range(1, gf.getNumMeshElements()):
        e = gf.getMeshElement(i)
        for j in range (0, e.getNumVertices()):
            v = e.getVertex(j)
            x = v.x()
            y = v.y()
            myMap[v.getNum()] = [math.tanh(-100*(y-0.5-0.25*sin(2*3.14159*x))) + tanh(100*(y-x))];       
#            myMap[v.getNum()] = [math.exp(-100*((v.x()-0.5)*(v.x()-0.5)+(v.y()-0.5)*(v.y()-0.5)))]
    print "hello 3", myMap.size()
    pv = PView ('xcarre','NodeData', gm, myMap)
    pve = PViewEvaluator (pv)
    lcMin = 0.00001
    lcMax = .1
    eps = 1.e-2
    nbIter = 4
    allDim = 1
    
    gm_adapt.adaptMesh([2], [pve], [[eps, lcMin, lcMax]], nbIter, allDim)
    print "hello 4"

gm = GModel()
gm.load('square.geo')
gm.load('square.msh')

gm_adapt = GModel()
gm_adapt.load('square.geo')

gm_adapt2 = GModel()
gm_adapt2.load('square.geo')

Adaptation ( gm , gm_adapt2)
print "------------------------------------------------------------------------"
Adaptation ( gm_adapt2 , gm_adapt)
