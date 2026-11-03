import gmsh
import sys

gmsh.initialize()
b = gmsh.model.occ.addBox(0,0,0, 1,1,0.5)
s = gmsh.model.occ.addSphere(1,1,0.5,0.4)
c = gmsh.model.occ.cut([(3, b)], [(3, s)])
b1 = gmsh.model.occ.addBox(0.3,0.3,0.4, 0.1,0.1,0.1)
b2 = gmsh.model.occ.addBox(0.5,0.5,0.4, 0.1,0.1,0.1)
gmsh.model.occ.fragment([(3, b1), (3, b2)], c[0])
gmsh.model.occ.synchronize()

size_bulk = 0.04
size_small = 0.002
power = 1.2

gmsh.model.mesh.setSize(gmsh.model.getEntities(0), size_bulk)
gmsh.model.mesh.setSize(gmsh.model.getBoundary([(3, b1), (3, b2)], recursive=True), size_small)

# new "Extend" field:
f = gmsh.model.mesh.field.add("Extend")
gmsh.model.mesh.field.setNumbers(f, "VolumesList",
                                 [e[1] for e in gmsh.model.getEntities(3)])
gmsh.model.mesh.field.setNumbers(f, "SurfacesList",
                                 [e[1] for e in gmsh.model.getEntities(2)])
gmsh.model.mesh.field.setNumber(f, "SizeMax", size_bulk)
gmsh.model.mesh.field.setNumber(f, "Ratio", power)
gmsh.model.mesh.field.setAsBackgroundMesh(f)
gmsh.option.setNumber("Mesh.MeshSizeExtendFromBoundary", 0)

# new 3D algo:
gmsh.option.setNumber("Mesh.Algorithm3D", 11)
gmsh.model.mesh.generate(3)

if '-nopopup' not in sys.argv:
    gmsh.fltk.run()

gmsh.finalize()
