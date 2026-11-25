import gmsh
import sys

# With Geometry.OCCBooleanPreserveNumbering = 2, the entities on the boundary of
# the arguments of boolean operations keep their tags when they are left
# unchanged or modified into a single entity: physical groups and mesh
# constraints can be defined on the original entities, before the boolean
# operations, and remain valid after them

gmsh.initialize(sys.argv)
gmsh.model.add("preserve_numbering")
gmsh.option.setNumber("Geometry.OCCBooleanPreserveNumbering", 2)

# a plate, whose surfaces 1 to 6 are the faces x = 0, x = 4, y = 0, y = 2, z = 0
# and z = 0.5
plate = gmsh.model.occ.addBox(0, 0, 0, 4, 2, 0.5)

# a hole, whose wall will be the lateral surface (7) of a cylinder
hole = gmsh.model.occ.addCylinder(3, 1, -0.1, 0, 0, 0.7, 0.4)

# a rib, whose top will be the face z = 1 (15) of a box
rib = gmsh.model.occ.addBox(0, 0.9, 0.5, 2.5, 0.2, 0.5)

gmsh.model.occ.synchronize()

# physical groups and mesh constraints on the original entities
gmsh.model.addPhysicalGroup(2, [1], 1, "clamped")
gmsh.model.addPhysicalGroup(2, [2], 2, "loaded")
gmsh.model.addPhysicalGroup(2, [7], 3, "hole")
gmsh.model.addPhysicalGroup(2, [15], 4, "rib top")
for c in gmsh.model.getBoundary([(2, 2)], oriented=False):
    gmsh.model.mesh.setTransfiniteCurve(c[1], 9)
gmsh.model.mesh.setTransfiniteSurface(2)
gmsh.model.mesh.setSize(gmsh.model.getBoundary([(2, 1)], recursive=True), 0.05)

# the boolean operations keep them valid: the clamped face now includes the end
# of the rib
gmsh.model.occ.cut([(3, plate)], [(3, hole)])
out, _ = gmsh.model.occ.fuse([(3, plate)], [(3, rib)])
gmsh.model.occ.synchronize()

# the volume of the union is a new one
gmsh.model.addPhysicalGroup(3, [out[0][1]], 5, "solid")

gmsh.option.setNumber("Mesh.MeshSizeMax", 0.2)
gmsh.model.mesh.generate(3)

if '-nopopup' not in sys.argv:
    gmsh.fltk.run()

gmsh.finalize()
