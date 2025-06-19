import gmsh
import sys

gmsh.initialize()

# create a cube with sphere inclusion
cube = [(3, gmsh.model.occ.addBox(0,0,0, 1,1,1))]
sphere = [(3, gmsh.model.occ.addSphere(0.5,0.5,0.5, 0.2))]
out = [gmsh.model.occ.fragment(cube, sphere)[0][0]]
gmsh.model.occ.synchronize()

# generate a mesh
gmsh.option.setNumber('Mesh.MeshSizeFactor', 0.3)
gmsh.model.mesh.generate(3)

if '-nopopup' not in sys.argv:
    gmsh.fltk.run()

# remove the mesh outside the sphere
gmsh.model.mesh.clear(out)

# get all the entities making up the sphere (surfaces, curves and points)
s = gmsh.model.getBoundary(sphere, oriented=False)
c = gmsh.model.getBoundary(s, combined=False, oriented=False)
p = gmsh.model.getBoundary(c, combined=False, oriented=False)
c = list(dict.fromkeys(c))
p = list(dict.fromkeys(p))

# move the mesh of the sphere (one could also directly change the coordinates of
# some of the node with gmsh.model.mesh.setNode())
gmsh.model.mesh.affineTransform([1,0,0,0.2, 0,1,0,0, 0,0,1,0], sphere+s+c+p)

# ask to mesh only the empty entities, i.e. in this case the volume outside the
# sphere
gmsh.option.setNumber('Mesh.MeshOnlyEmpty', 1)
gmsh.model.mesh.generate(3)

if '-nopopup' not in sys.argv:
    gmsh.fltk.run()

gmsh.finalize()
