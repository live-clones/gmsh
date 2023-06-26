import gmsh
gmsh.initialize()
gmsh.model.occ.addBox(0,0,0,1,1,1)
gmsh.model.occ.synchronize()
gmsh.model.mesh.generate()
gmsh.model.setAttribute('Comments', ["Hello this is my comment on the block model",
                                     "... and a second comment"])
gmsh.write('block_with_attribute.msh')
gmsh.finalize()

gmsh.initialize()
gmsh.open('block_with_attribute.msh')
for attr in gmsh.model.getAttributeNames():
    print('Attribute ' + attr + " = ", gmsh.model.getAttribute(attr))
gmsh.finalize()
