#!/usr/bin/env python

from gmsh import *
import sys

if len(sys.argv) < 2:
    print "Usage: " + sys.argv[0] + " file.msh [options]"
    exit(0)

gmshInitialize()
gmshOptionSetNumber("General.Terminal", 1)
gmshOpen(sys.argv[1])

# get all elementary entities in the model
entities = PairVector()
gmshModelGetEntities(entities)

for e in entities:
    # get the mesh vertices for each elementary entity
    vertexTags = IntVector()
    vertexCoords = DoubleVector(); vertexParams = DoubleVector()
    gmshModelGetMeshVertices(e[0], e[1], vertexTags, vertexCoords, vertexParams)
    # get the mesh elements for each elementary entity
    elemTypes = IntVector()
    elemTags = IntVectorVector(); elemVertexTags = IntVectorVector()
    gmshModelGetMeshElements(e[0], e[1], elemTypes, elemTags, elemVertexTags)
    # report some statistics
    numElem = sum(len(i) for i in elemTags)
    print str(vertexTags.size()) + " mesh vertices " + str(numElem),\
          "mesh elements on entity " + str(e)

gmshFinalize()
