import gmsh
import sys

# healShapes keeps the tags of the entities it heals and of the rest of the
# model it changes (e.g. the surfaces they share), with their physical groups
# and mesh constraints, and returns the healed entities (#3184)

gmsh.initialize(sys.argv)
occ = gmsh.model.occ
errors = []

# a box with 5 small boxes cut out of it, kept as volumes: healing the box also
# changes the surfaces it shares with them
big = occ.addBox(0, 0, 0, 10, 10, 10)
small = [occ.addBox(1 + 1.5 * i, 1, 1, 1, 1, 1) for i in range(5)]
out, _ = occ.cut([(3, big)], [(3, s) for s in small], removeTool=False)
occ.synchronize()
for s in small:
    gmsh.model.addPhysicalGroup(3, [s], s)
gmsh.model.addPhysicalGroup(3, [out[0][1]], 100)
faces = list(gmsh.model.getAdjacencies(3, small[0])[1])
gmsh.model.addPhysicalGroup(2, faces, 200)
curves = [c[1] for c in gmsh.model.getBoundary([(2, faces[0])], oriented=False)]
for c in curves:
    gmsh.model.mesh.setTransfiniteCurve(c, 7)

healed = occ.healShapes([(3, out[0][1])])
occ.synchronize()

if healed != [(3, out[0][1])]:
    errors.append("healShapes returned %s instead of %s" % (healed, out[:1]))
groups = gmsh.model.getPhysicalGroups()
for dim, tag in [(3, s) for s in small] + [(3, 100), (2, 200)]:
    if (dim, tag) not in groups:
        errors.append("physical group (%d, %d) lost" % (dim, tag))
if sorted(gmsh.model.getEntitiesForPhysicalGroup(2, 200)) != sorted(faces):
    errors.append("physical surface 200 is not on surfaces %s" % faces)
gmsh.model.mesh.generate(1)
for c in curves:
    n = len(gmsh.model.mesh.getNodes(1, c, includeBoundary=True)[0])
    if n != 7:
        errors.append("curve %d has %d nodes instead of 7" % (c, n))

# healing all the entities returns the volumes
healed = occ.healShapes()
occ.synchronize()
if sorted(healed) != sorted(gmsh.model.getEntities(3)):
    errors.append("healShapes() returned %s" % healed)

# two curves merged into one by sewing: the physical groups of both are on
# the curve that is left
gmsh.clear()
occ.addRectangle(5, 0, 0, 1, 1)
occ.addRectangle(6, 0, 0, 1, 1)
occ.synchronize()
shared = [t for _, t in gmsh.model.getEntities(1)
          if abs(occ.getCenterOfMass(1, t)[0] - 6) < 1e-6]
gmsh.model.addPhysicalGroup(1, shared[:1], 40)
gmsh.model.addPhysicalGroup(1, shared[1:], 41)
occ.healShapes(sewFaces=True, makeSolids=False)
occ.synchronize()
left = [t for _, t in gmsh.model.getEntities(1)
        if abs(occ.getCenterOfMass(1, t)[0] - 6) < 1e-6]
if len(shared) != 2 or len(left) != 1:
    errors.append("%d curves sewn into %d" % (len(shared), len(left)))
for g in (40, 41):
    if ((1, g) not in gmsh.model.getPhysicalGroups() or
            list(gmsh.model.getEntitiesForPhysicalGroup(1, g)) != left):
        errors.append("physical curve %d is not on the sewn curve" % g)

gmsh.finalize()

if errors:
    print("\n".join(errors))
    sys.exit(1)
print("OK")
