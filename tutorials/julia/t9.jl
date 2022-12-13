# See the corresponding Python tutorial for detailed comments.
# Add the path to the view3.pos from the Gmsh tutorials folder before running the script.
# To avoid syntax error when giving the path, use \\ instead of \.

import Gmsh: gmsh

gmsh.initialize()

path = "< PATH TO GMSH >\\tutorials\\view3.pos"
gmsh.merge(path)

v = gmsh.view.getTags()
if length(v) != 1
    gmsh.logger.write("Wrong number of views!", "error")
    gmsh.finalize()
    exit()
end

gmsh.plugin.setNumber("Isosurface", "Value", 0.67)
gmsh.plugin.setNumber("Isosurface", "View", 0)

v1 = gmsh.plugin.run("Isosurface")

gmsh.plugin.setNumber("CutPlane", "A", 0)
gmsh.plugin.setNumber("CutPlane", "B", 0.2)
gmsh.plugin.setNumber("CutPlane", "C", 1)
gmsh.plugin.setNumber("CutPlane", "D", 0)
gmsh.plugin.setNumber("CutPlane", "View", 0)

v2 = gmsh.plugin.run("CutPlane")

gmsh.plugin.setString("Annotate", "Text", "A nice title")
gmsh.plugin.setNumber("Annotate", "X", 1.e5)
gmsh.plugin.setNumber("Annotate", "Y", 50)
gmsh.plugin.setString("Annotate", "Font", "Times-BoldItalic")
gmsh.plugin.setNumber("Annotate", "FontSize", 28)
gmsh.plugin.setString("Annotate", "Align", "Center")
gmsh.plugin.setNumber("Annotate", "View", 0)
gmsh.plugin.run("Annotate")

gmsh.plugin.setString("Annotate", "Text", "(and a small subtitle)")
gmsh.plugin.setNumber("Annotate", "Y", 70)
gmsh.plugin.setString("Annotate", "Font", "Times-Roman")
gmsh.plugin.setNumber("Annotate", "FontSize", 12)
gmsh.plugin.run("Annotate")

gmsh.view.option.setNumber(v[1], "Light", 1)
gmsh.view.option.setNumber(v[1], "IntervalsType", 1)
gmsh.view.option.setNumber(v[1], "NbIso", 6)
gmsh.view.option.setNumber(v[1], "SmoothNormals", 1)
gmsh.view.option.setNumber(v1, "IntervalsType", 2)
gmsh.view.option.setNumber(v2, "IntervalsType", 2)

if !("-nopopup" in ARGS)
    gmsh.fltk.run()
end

gmsh.finalize()
