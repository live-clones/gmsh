# This file reimplements gmsh/tutorial/t13.geo in Python.

# Remeshing without an underlying CAD model

import gmsh
import math

gmsh.initialize()

gmsh.option.setNumber("General.Terminal", 1)

# Let's merge an STL mesh that we would like to remesh.
gmsh.merge("t13.stl")

# We first classify ("color") the surfaces by splitting the original surface
# along sharp geometrical features. This will create new discrete surfaces,
# curves and points.

angle = 40 # Angle for surface detection
forceParametrizablePatches = False # Create surfaces guaranteed to be parametrizable?
includeBoundary = True

gmsh.model.mesh.classifySurfaces(angle * math.pi/180.,
                                 includeBoundary,
                                 forceParametrizablePatches)

# Create a geometry for all the discrete curves and surfaces in the mesh, by
# computing a parametrization for each one
gmsh.model.mesh.createGeometry()

# Create a volume as usual
s = gmsh.model.getEntities(2)
l = gmsh.model.geo.addSurfaceLoop([s[i][1] for i in range(len(s))])
gmsh.model.geo.addVolume([l])

gmsh.model.geo.synchronize()

# element size imposed by a size field, just because we can :-)
funny = False

f = gmsh.model.mesh.field.add("MathEval");
if funny:
  gmsh.model.mesh.field.setString(f, "F", "2*Sin((x+y)/5) + 3")
else:
  gmsh.model.mesh.field.setString(f, "F", "4")
gmsh.model.mesh.field.setAsBackgroundMesh(f)

gmsh.model.mesh.generate(3)

gmsh.fltk.run()

gmsh.finalize()
