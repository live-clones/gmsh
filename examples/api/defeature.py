import gmsh
import sys

# Defeaturing removes small features (holes, bosses, fillets...) from a CAD
# volume, e.g. to mesh a simplified model: gmsh.model.occ.defeature() takes the
# surfaces of the features and rebuilds the volume without them. The surfaces
# left unchanged or modified, like a face whose hole is filled, keep their tags,
# with their physical groups and mesh constraints

gmsh.initialize(sys.argv)
gmsh.model.add("defeature")

# a plate with two through holes and a boss, itself with a blind hole
plate = gmsh.model.occ.addBox(0, 0, 0, 4, 2, 0.5)
boss = gmsh.model.occ.addCylinder(2, 1, 0.5, 0, 0, 0.5, 0.5)
part, _ = gmsh.model.occ.fuse([(3, plate)], [(3, boss)])
holes = [gmsh.model.occ.addCylinder(x, 1, -0.5, 0, 0, 1.5, 0.2) for x in [1, 3]]
holes.append(gmsh.model.occ.addCylinder(2, 1, 0.8, 0, 0, 0.5, 0.2))
part, _ = gmsh.model.occ.cut(part, [(3, h) for h in holes])

# a copy of the part next to it, to compare the original with the defeatured
# copy
copy = gmsh.model.occ.copy(part)
gmsh.model.occ.translate(copy, 0, 3, 0)
gmsh.model.occ.synchronize()
volume = copy[0][1]

# physical groups on the top and the bottom of the copy, whose holes will be
# filled
top = gmsh.model.getEntitiesInBoundingBox(-0.1, 2.9, 0.49, 4.1, 5.1, 0.51, 2)
bottom = gmsh.model.getEntitiesInBoundingBox(-0.1, 2.9, -0.01, 4.1, 5.1, 0.01, 2)
gmsh.model.addPhysicalGroup(2, [s[1] for s in top], name="top")
gmsh.model.addPhysicalGroup(2, [s[1] for s in bottom], name="bottom")

# the features: the cylindrical surfaces (the walls of the holes and of the
# boss) and the surfaces above the plate (the top of the boss and the bottom of
# its hole)
features = []
for s in gmsh.model.getAdjacencies(3, volume)[1]:
    zmin = gmsh.model.getBoundingBox(2, s)[2]
    if gmsh.model.getType(2, s) == "Cylinder" or zmin > 0.6:
        features.append(s)

# remove them: the copy is now a plain box, with the same volume tag, and its
# top and bottom surfaces, without their holes, keep their physical groups
gmsh.model.occ.defeature([volume], features)
gmsh.model.occ.synchronize()
gmsh.model.addPhysicalGroup(3, [volume], name="defeatured part")

gmsh.option.setNumber("Mesh.MeshSizeMax", 0.15)
gmsh.model.mesh.generate(3)

if '-nopopup' not in sys.argv:
    gmsh.fltk.run()

gmsh.finalize()
