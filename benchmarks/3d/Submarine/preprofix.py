import gmshpy
import math


def areCoplanarFaces(f0, f1, tol) :
    n0 = f0.normal()
    n1 = f1.normal()
    return (abs(math.acos(gmshpy.dot(n0, n1))*180/math.pi) < tol)

def nbVerticesOnSurface(el) :
    vent = [el.getVertex(i).onWhat().dim() for i in range(el.getNumVertices())]
    return  len([e for e in vent if e < 3])

def isBadElement(el) :
    fs = [el.getFace(i) for i in range(el.getNumFaces())]
    bad = False
    for i in range(len(fs)) :
        for j in range(i):
            bad |= areCoplanarFaces(fs[i], fs[j], 10) #10 degrees min angle allowed
    return bad    

def fixTetras(m):
    for r in m.bindingsGetRegions() :
	goodt = [t for t in r.tetrahedra if (not ((nbVerticesOnSurface(t) == 4) and  isBadElement(t)))]
        oldSize = r.tetrahedra.size()
        r.tetrahedra.clear()
        for t in goodt :
            r.addTetrahedron(t)
        print("-- Removed %i tetrahedra over %i"%(oldSize-r.tetrahedra.size(), oldSize))


def fixPyramids(m):
    for r in m.bindingsGetRegions() :
	goodp = [p for p in r.pyramids if (not ((nbVerticesOnSurface(p) == 5) and  isBadElement(p)))]
        oldSize = r.pyramids.size()
        r.pyramids.clear()
        for p in goodp :
            r.addPyramid(p)
        print("-- Removed %i pyramids over %i"%(oldSize-r.pyramids.size(), oldSize))

def fixPrisms(m):
    for r in m.bindingsGetRegions() :
	goodp = [p for p in r.prisms if (not ((nbVerticesOnSurface(p) == 6) and  isBadElement(p)))]
        oldSize = r.prisms.size()
        r.prisms.clear()
        for p in goodp :
            r.addPrism(p)
        print("-- Removed %i prisms over %i"%(oldSize-r.prisms.size(), oldSize))

def fixHexs(m):
    for r in m.bindingsGetRegions() :
	goodh = [h for h in r.hexahedra if (not ((nbVerticesOnSurface(h) == 8) and  isBadElement(p)))]
        oldSize = r.hexahedra.size()
        r.hexahedra.clear()
        for h in goodh :
            r.addHexahedron(h)
        print("-- Removed %i hexahedra over %i"%(oldSize-r.hexahedra.size(), oldSize))



