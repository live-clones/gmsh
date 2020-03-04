# This file reimplements gmsh/tutorial/t9.geo in Python.
#
# Post-processing plugins (levelsets, sections, annotations)

import gmsh
import os

model = gmsh.model
factory = model.geo

gmsh.initialize()
gmsh.option.setNumber("General.Terminal", 1)

# add a three-dimensional scalar view to work on:
path = os.path.dirname(os.path.abspath(__file__))
gmsh.merge(os.path.join(path, '..', 'view3.pos'))

# set plugin options
plugin = gmsh.plugin

# First plugin is Isosurface
plugin.setNumber("Isosurface", "Value", 0.67)
plugin.setNumber("Isosurface", "View", 0)

plugin.run("Isosurface")

# Second is CutPlane
plugin.setNumber("CutPlane", "A", 0)
plugin.setNumber("CutPlane", "B", 0.2)
plugin.setNumber("CutPlane", "C", 1)
plugin.setNumber("CutPlane", "D", 0)
plugin.setNumber("CutPlane", "View", 0)
plugin.run("CutPlane")

# Third is Annotate
plugin.setString("Annotate", "Text", "A nice title")
# By convention, window coordinates larger than 99999 represent the center
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

# set some general options
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
