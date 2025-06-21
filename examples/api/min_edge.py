import gmsh
gmsh.initialize()
gmsh.model.occ.addBox(0,0,0, 1,1,1)
gmsh.model.occ.synchronize()
gmsh.model.mesh.generate()
types, tags, _ = gmsh.model.mesh.getElements(dim=3)
qual = gmsh.model.mesh.getElementQualities(tags[0], qualityName="minEdge")
print(min(zip(qual, tags[0])))
gmsh.finalize()
