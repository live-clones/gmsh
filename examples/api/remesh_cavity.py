import gmsh
import sys
from collections import Counter

gmsh.initialize()

# create a cube and mesh it
cube = gmsh.model.occ.addBox(0,0,0, 10,10,10)
gmsh.model.occ.synchronize()
gmsh.option.setNumber('Mesh.Algorithm3D', 10) # test new algo
gmsh.option.setNumber('Mesh.MeshSizeMax', 0.3) # mesh size
gmsh.model.mesh.generate(3)

# remove some tetrahedra from the volume mesh
gmsh.plugin.setNumber("Invisible", "DeleteElements", 1.)
gmsh.plugin.setNumber("Invisible", "Inside", 1)
gmsh.plugin.setNumber("Invisible", "XMin", 2)
gmsh.plugin.setNumber("Invisible", "YMin", 4)
gmsh.plugin.setNumber("Invisible", "ZMin", 2)
gmsh.plugin.setNumber("Invisible", "XMax", 8)
gmsh.plugin.setNumber("Invisible", "YMax", 5)
gmsh.plugin.setNumber("Invisible", "ZMax", 8)
gmsh.plugin.run("Invisible")
gmsh.plugin.setNumber("Invisible", "XMin", 2)
gmsh.plugin.setNumber("Invisible", "YMin", 2)
gmsh.plugin.setNumber("Invisible", "ZMin", 4)
gmsh.plugin.setNumber("Invisible", "XMax", 3)
gmsh.plugin.setNumber("Invisible", "YMax", 8)
gmsh.plugin.setNumber("Invisible", "ZMax", 6)
gmsh.plugin.run("Invisible")

TRI=2 # first order tri
TET=4 # first order tet

# get the faces from the remaining tets
facenodes = gmsh.model.mesh.getElementFaceNodes(TET, 3, cube)
gmsh.model.mesh.createFaces([(3, cube)])
facetags, faceori = gmsh.model.mesh.getFaces(3, facenodes)

# keep track of face/nodes map
def map_keys_to_triplets(keys, values):
    if len(values) != 3 * len(keys):
        raise ValueError("Length of values must be exactly 3 times the length of keys.")
    return {keys[i]: values[3*i:3*i+3] for i in range(len(keys))}
facemap = map_keys_to_triplets(facetags, facenodes)

# compute boundary by keeping only the faces that appear once
def remove_elements_appearing_twice(array):
    counts = Counter(array)
    return [item for item in array if counts[item] != 2]
bndfaces = set(remove_elements_appearing_twice(facetags))

# remove the faces that are on the boundary of the cube
bnd = gmsh.model.getBoundary([(3, cube)], oriented=False)
for b in bnd:
    facenodes = gmsh.model.mesh.getElementFaceNodes(TRI, 3, b[1])
    facetags, faceori = gmsh.model.mesh.getFaces(3, facenodes)
    for f in facetags: bndfaces.remove(f)

# create a discrete surface with the triangles corresponding to the remaining
# faces, bounding the cavity
news = gmsh.model.addDiscreteEntity(2)
nn = []
for f in bndfaces:
    nn.extend(facemap[f])
gmsh.model.mesh.addElementsByType(news, TRI, [], nn);

# reclassify the mesh nodes on the lowest dimensional model entity
gmsh.model.mesh.reclassifyNodes()

# create the volume that will be remeshed
newv = gmsh.model.addDiscreteEntity(3, boundary=[news])
gmsh.model.mesh.createGeometry([(3, newv)])

# only mesh the entities that have no mesh
gmsh.option.setNumber('Mesh.MeshOnlyEmpty', 1)

# remesh the cavity
gmsh.model.mesh.generate(3)

#print(gmsh.model.mesh.getNodes())
#print(gmsh.model.mesh.getElements())

# run the GUI if -nopopup is not specified on the command line
if '-nopopup' not in sys.argv:
    gmsh.fltk.run()

gmsh.finalize()
