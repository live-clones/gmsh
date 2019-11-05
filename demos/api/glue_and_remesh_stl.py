import gmsh
import math

gmsh.initialize()
gmsh.option.setNumber('General.Terminal', 1)

# load two STL surfaces
gmsh.merge('surface1.stl')
gmsh.merge('surface2.stl')

# merge nodes that are at the same position up to some tol
gmsh.option.setNumber('Geometry.Tolerance', 1e-4)
gmsh.model.mesh.removeDuplicateNodes()

# classify surface mesh accroding to given angle, and create discrete model
# entities (surfaces, curves and points) accordingly
gmsh.model.mesh.classifySurfaces(math.pi/2)

# create a geometry for the discrete curves and surfaces (uncomment this if you
# don't want to remesh the surfaces and simply use the original mesh)
gmsh.model.mesh.createGeometry()

# get all the surfaces in the model
s = gmsh.model.getEntities(2)

# create a surface loop and a volume from these surfaces
l = gmsh.model.geo.addSurfaceLoop([s[i][1] for i in range(len(s))])
gmsh.model.geo.addVolume([l])

# synchronize the geo (built-in) entities with the model
gmsh.model.geo.synchronize()

# mesh
gmsh.option.setNumber("Mesh.Algorithm", 6);
gmsh.option.setNumber("Mesh.CharacteristicLengthMin", 0.4);
gmsh.option.setNumber("Mesh.CharacteristicLengthMax", 0.4);
gmsh.model.mesh.generate(3)

gmsh.fltk.run()
gmsh.finalize()
