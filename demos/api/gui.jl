import gmsh

model = gmsh.model
factory = model.occ

gmsh.initialize(ARGS)

# creates the FLTK user interface; this could also be called after the geometry
# is created (or not at all - fltk.run() will do it automatically)
gmsh.fltk.initialize()

# Copied from boolean.py...
model.add("boolean")
gmsh.option.setNumber("Mesh.Algorithm", 6);
gmsh.option.setNumber("Mesh.CharacteristicLengthMin", 0.4);
gmsh.option.setNumber("Mesh.CharacteristicLengthMax", 0.4);
R = 1.4; Rs = R*.7; Rt = R*1.25
factory.addBox(-R,-R,-R, 2*R,2*R,2*R, 1)
factory.addSphere(0,0,0,Rt, 2)
factory.intersect([(3, 1)], [(3, 2)], 3)
factory.addCylinder(-2*R,0,0, 4*R,0,0, Rs, 4)
factory.addCylinder(0,-2*R,0, 0,4*R,0, Rs, 5)
factory.addCylinder(0,0,-2*R, 0,0,4*R, Rs, 6)
factory.fuse([(3, 4), (3, 5)], [(3, 6)], 7)
factory.cut([(3, 3)], [(3, 7)], 8)
factory.synchronize();
# ...end of copy

# this would be equivalent to gmsh.fltk.run():
#
# gmsh.graphics.draw()
# while true
#     gmsh.fltk.wait()
#     println("just treated an event in the interface")
# end

gmsh.fltk.run()

gmsh.finalize()
