import gmsh
gmsh.initialize()
gmsh.model.occ.addRectangle(0,0,0,1,1)
gmsh.model.occ.synchronize()
gmsh.model.mesh.generate()
while 1:
    gmsh.fltk.setStatusMessage("Select an element, or press 'q' to quit", True)
    ret, ele = gmsh.fltk.selectElements()
    if ret == 0: break
    else: print(ele)
gmsh.finalize()
