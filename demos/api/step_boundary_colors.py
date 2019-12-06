import gmsh
gmsh.initialize()

gmsh.option.setNumber("General.Terminal", 1)

gmsh.merge('step_boundary_colors.stp')

for tag in gmsh.model.getEntities():
    col = gmsh.model.getColor(*tag)
    if col != (0,0,255,0): print('entity', tag, 'color', col)
