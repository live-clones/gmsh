import gmsh
import sys

gmsh.initialize(sys.argv)

gmsh.option.setNumber("General.Terminal", 1)

# create simple geometry
gmsh.model.occ.addBox(-3, -2, -1, 6, 4, 2)
gmsh.model.occ.synchronize()

gmsh.option.setNumber("Mesh.SurfaceFaces", 1)

# launch GUI
gmsh.fltk.initialize()

# split window 50%-50% horizontally
gmsh.fltk.splitCurrentWindow('h', 0.5)

# set the right subwindow (subwindows are indexed starting from 0; new
# subwindows created by Split are appended at the end) as current window
gmsh.fltk.setCurrentWindow(1)

# rotation/translation/scale options are applied to the current subwindow
gmsh.option.setNumber("General.Trackball", 0)
gmsh.option.setNumber("General.RotationX", -90)
gmsh.option.setNumber("General.RotationY", 0)
gmsh.option.setNumber("General.RotationZ", -90)

# split the current subwindow into two parts, vertically
gmsh.fltk.splitCurrentWindow('v', 0.5)

# set the newly created subwindow as the current one and change rotation
gmsh.fltk.setCurrentWindow(2)
gmsh.option.setNumber("General.RotationX", -90)
gmsh.option.setNumber("General.RotationY", 0)
gmsh.option.setNumber("General.RotationZ", 180)

# mesh the model
gmsh.model.mesh.generate(2)

# redraw
gmsh.graphics.draw()

# save all subwindows into a composite PNG
gmsh.option.setNumber("Print.CompositeWindows", 1)
gmsh.write("img_composite.png")

# restore single window
gmsh.fltk.splitCurrentWindow('u')
gmsh.write("img_single.png")

gmsh.finalize()
