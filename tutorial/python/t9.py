# ------------------------------------------------------------------------------
#
#  Gmsh Python tutorial 9
#
#  Plugins
#
# ------------------------------------------------------------------------------

import gmsh
import os

# Plugins can be added to Gmsh in order to extend its capabilities. For example,
# post-processing plugins can modify views, or create new views based on
# previously loaded views. Several default plugins are statically linked with
# Gmsh, e.g. Isosurface, CutPlane, CutSphere, Skin, Transform or Smooth.
#
# Plugins can be controlled through the API functions with the `gmsh.plugin'
# prefix, or from the graphical interface (right click on the view button, then
# `Plugins').

model = gmsh.model
factory = model.geo

gmsh.initialize()
gmsh.option.setNumber("General.Terminal", 1)

# Let us for example include a three-dimensional scalar view:
path = os.path.dirname(os.path.abspath(__file__))
gmsh.merge(os.path.join(path, '..', 'view3.pos'))

# We then set some options for the `Isosurface' plugin (which extracts an
# isosurface from a 3D scalar view), and run it:
plugin = gmsh.plugin
plugin.setNumber("Isosurface", "Value", 0.67)
plugin.setNumber("Isosurface", "View", 0)
plugin.run("Isosurface")

# We also set some options for the `CutPlane' plugin (which computes a section
# of a 3D view using the plane A*x+B*y+C*z+D=0), and then run it:
plugin.setNumber("CutPlane", "A", 0)
plugin.setNumber("CutPlane", "B", 0.2)
plugin.setNumber("CutPlane", "C", 1)
plugin.setNumber("CutPlane", "D", 0)
plugin.setNumber("CutPlane", "View", 0)
plugin.run("CutPlane")

# Add a title (By convention, for window coordinates a value greater than 99999
# represents the center. We could also use `General.GraphicsWidth / 2', but that
# would only center the string for the current window size.):
plugin.setString("Annotate", "Text", "A nice title")
plugin.setNumber("Annotate", "X", 1.e5)
plugin.setNumber("Annotate", "Y", 50)
plugin.setString("Annotate", "Font", "Times-BoldItalic")
plugin.setNumber("Annotate", "FontSize", 28)
plugin.setString("Annotate", "Align", "Center")
plugin.setNumber("Annotate", "View", 0)
plugin.run("Annotate")

plugin.setString("Annotate", "Text", "(and a small subtitle)")
plugin.setNumber("Annotate", "Y", 70)
plugin.setString("Annotate", "Font", "Times-Roman")
plugin.setNumber("Annotate", "FontSize", 12)
plugin.run("Annotate")

# We finish by setting some options:
option = gmsh.option
option.setNumber("View[0].Light", 1)
option.setNumber("View[0].IntervalsType", 1)
option.setNumber("View[0].NbIso", 6)
option.setNumber("View[0].SmoothNormals", 1)
option.setNumber("View[1].IntervalsType", 2)
option.setNumber("View[2].IntervalsType", 2)

# show the GUI at the end
gmsh.fltk.run()

gmsh.finalize()
