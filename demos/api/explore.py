import gmsh
import sys

if len(sys.argv) < 2:
    print "Usage: " + sys.argv[0] + " file.msh [options]"
    exit(0)

gmsh.initialize([]) #FIXME default args
gmsh.option.setNumber("General.Terminal", 1)
gmsh.open(sys.argv[1])

# get all elementary entities in the model
entities = gmsh.model.getEntities(-1) #FIXME default args

for e in entities:
    # get the mesh vertices for each elementary entity
    vertexTags, vertexCoords, vertexParams = gmsh.model.mesh.getVertices(e[0], e[1])
    # get the mesh elements for each elementary entity
    elemTypes, elemTags, elemVertexTags = gmsh.model.mesh.getElements(e[0], e[1])
    # report some statistics
    numElem = sum(len(i) for i in elemTags)
    print str(len(vertexTags)) + " mesh vertices " + str(numElem),\
          "mesh elements on entity " + str(e)

gmsh.finalize()
