import gmsh
import sys

if len(sys.argv) < 2:
    print "Usage: " + sys.argv[0] + " file.msh [options]"
    exit(0)

gmsh.initialize()
gmsh.optionSetNumber("General.Terminal", 1)
gmsh.open(sys.argv[1])

# get all elementary entities in the model
entities = gmsh.PairVector()
gmsh.modelGetEntities(entities)

for e in entities:
    # get the mesh vertices for each elementary entity
    vertexTags = gmsh.IntVector()
    vertexCoords = gmsh.DoubleVector(); vertexParams = gmsh.DoubleVector()
    gmsh.modelMeshGetVertices(e[0], e[1], vertexTags, vertexCoords, vertexParams)
    # get the mesh elements for each elementary entity
    elemTypes = gmsh.IntVector()
    elemTags = gmsh.IntVectorVector(); elemVertexTags = gmsh.IntVectorVector()
    gmsh.modelMeshGetElements(e[0], e[1], elemTypes, elemTags, elemVertexTags)
    # report some statistics
    numElem = sum(len(i) for i in elemTags)
    print str(vertexTags.size()) + " mesh vertices " + str(numElem),\
          "mesh elements on entity " + str(e)

gmsh.finalize()
