import gmsh
import sys
import math

gmsh.initialize(sys.argv)

gmsh.option.setNumber('Mesh.MeshSizeFactor', 0.1)

# make extrusions only return "top" and "body" entities, not lateral ones
gmsh.option.setNumber('Geometry.ExtrudeReturnLateralEntities', 0)

# read input STL, classify into reparametrizable surfaces and create geometry
gmsh.merge('aneurysm_data.stl')
gmsh.model.mesh.classifySurfaces(math.pi, True, True)
gmsh.model.mesh.createGeometry()

# extrude a boundary layer of 4 elements using mesh normals (thickness = 0.5)
gmsh.model.geo.extrudeBoundaryLayer(gmsh.model.getEntities(2), [4], [0.5], True)

# extrude a second boundary layer in the opposite direction (note the `second ==
# True' argument to distinguish it from the first one)
e = gmsh.model.geo.extrudeBoundaryLayer(gmsh.model.getEntities(2), [4], [-0.5], True, True)

gmsh.model.geo.synchronize()

# get inner surfaces
inner = [s for s in e if s[0] == 2]
surf = [s[1] for s in inner]

# get boundary of inner surfaces and construct 3 plane surfaces to fill the 3
# holes
bnd = gmsh.model.getBoundary(inner)
fill = []
for b in bnd:
    cl = gmsh.model.geo.addCurveLoop([b[1]])
    fill.append(gmsh.model.geo.addPlaneSurface([cl]))
print('Created plane surfaces to fill the holes:', fill)

# create a volume inside
surf.extend(fill)
sl = gmsh.model.geo.addSurfaceLoop(surf)
gmsh.model.geo.addVolume([sl])

gmsh.model.geo.synchronize()

if '-nopopup' not in sys.argv:
    gmsh.fltk.run()

gmsh.finalize()
