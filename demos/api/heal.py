import gmsh

gmsh.initialize()
gmsh.option.setNumber('General.Terminal', 1)
# load step file
gmsh.open('as1-tu-203.stp')

# get all model entities
ent = gmsh.model.getEntities()

gmsh.model.occ.healShapes()

gmsh.model.occ.synchronize()

gmsh.finalize()

#gmsh.fltk.run()
