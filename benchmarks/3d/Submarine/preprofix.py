import gmshpy
import sys
m = gmshpy.GModel()
if (len(sys.argv) < 3) :
    print("please specify input and output files")
    exit()
m.load(sys.argv[1])

# generate a list of boundary elements

def isBoundaryFace(f) :
    vent = [f.getVertex(i).onWhat() for i in range(f.getNumVertices())]
    return  all([e.dim() < 3 for e in vent])

def areCoplanarFaces(f0, f1, tol) :
    n0 = f0.normal()
    n1 = f1.normal()
    return abs(gmshpy.dot(n0, n1)) > tol

def isBadPyramid(p) :
    fs = [p.getFace(i) for i in range(p.getNumFaces())]
    bndfs = [f for f in fs if (isBoundaryFace(f) and f.getNumVertices() == 3)]
    bad = False
    for i in range(len(bndfs)) :
        for j in range(i):
            bad |= areCoplanarFaces(bndfs[0], bndfs[1], 0.9)
    return bad


for r in m.bindingsGetRegions() :
    badp = [p for p in r.pyramids if isBadPyramid(p)]
    for p in badp :
        cog = p.barycenter()
        nv = gmshpy.MVertex(cog.x(), cog.y(), cog.z(), r);
        nv.thisown = False
        r.addMeshVertex(nv)
        for i in range(4) :
            f = p.getFace(i)
            vs = [f.getVertex(i) for i in range(3)] + [nv]
            t = gmshpy.MTetrahedron(*vs)
            t.thisown = False
            r.addTetrahedron(t)
        p.setVertex(4, nv)

m.save(sys.argv[2])



