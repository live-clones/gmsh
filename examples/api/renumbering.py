import gmsh
gmsh.initialize()
gmsh.option.setNumber("Mesh.MeshSizeMax", 0.1)
gmsh.option.setNumber("Mesh.MeshSizeMin", 0.1)
gmsh.option.setNumber("Mesh.NodeLabels", 1)

gmsh.model.occ.addRectangle(0,0,0, 1,1)
gmsh.model.occ.synchronize()

gmsh.model.mesh.generate()
gmsh.fltk.run()

old, new = gmsh.model.mesh.computeRenumbering('RCMK')
gmsh.model.mesh.renumberNodes(old, new)
gmsh.fltk.run()

old, new = gmsh.model.mesh.computeRenumbering('Hilbert')
gmsh.model.mesh.renumberNodes(old, new)
gmsh.fltk.run()

gmsh.finalize()
