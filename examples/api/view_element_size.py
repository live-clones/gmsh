import gmsh
import sys

gmsh.initialize(sys.argv)

# create a non-uniform mesh
gmsh.model.add("my model")
gmsh.model.occ.addBox(0,0,0, 1,1,1)
gmsh.model.occ.synchronize()
gmsh.model.mesh.setSize(gmsh.model.getEntities(0), 0.1)
gmsh.model.mesh.setSize([(0, 1)], 0.01)
gmsh.model.mesh.generate(3)

# get element volumes
_, eleTags , _ = gmsh.model.mesh.getElements(dim=3)
q = gmsh.model.mesh.getElementQualities(eleTags[0], "volume")

# create view
t = gmsh.view.add("Element sizes")
gmsh.view.addHomogeneousModelData(t, 0, "my model", "ElementData", eleTags[0], q)

# visualize
if '-nopopup' not in sys.argv:
    gmsh.fltk.run()

gmsh.finalize()
