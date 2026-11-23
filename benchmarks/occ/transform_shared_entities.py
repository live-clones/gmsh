import gmsh
import sys

# Transformations of OpenCASCADE entities that share sub-entities with
# entities that are not transformed:
# - the shared sub-entity (the point a translated curve shares with another
#   curve) stays as it is with its tag, before the model is synchronized as
#   after, with Geometry.OCCFastUnbind or without;
# - an entity that bounds another one (a face of a box) cannot be transformed
#   alone: it is an error, not a silent transformation of a copy

gmsh.initialize(sys.argv)
occ = gmsh.model.occ
errors = []

for fast in (1, 0):
    gmsh.clear()
    gmsh.option.setNumber("Geometry.OCCFastUnbind", fast)
    occ.addPoint(0, 0, 0, tag=1)
    occ.addPoint(1, 0, 0, tag=2)
    occ.addPoint(1, 1, 0, tag=3)
    occ.addLine(1, 2, 1)
    occ.addLine(2, 3, 2)
    occ.synchronize()
    occ.translate([(1, 1)], 0, 0, 1)
    # point 2 is still the end of curve 2, before the synchronization
    p = occ.addPoint(5, 5, 5)
    l = occ.addLine(2, p)
    occ.synchronize()
    x = list(gmsh.model.getValue(0, 2, []))
    if x != [1, 0, 0]:
        errors.append("fast unbind %d: point 2 is at %s" % (fast, x))
    b = [t for _, t in gmsh.model.getBoundary([(1, l)], oriented=False)]
    if sorted(b) != sorted([2, p]):
        errors.append("fast unbind %d: the new curve joins points %s instead "
                      "of %s" % (fast, b, [2, p]))
    z = sorted(gmsh.model.getValue(0, t, [])[2] for _, t in
               gmsh.model.getBoundary([(1, 1)], oriented=False))
    if z != [1, 1]:
        errors.append("fast unbind %d: curve 1 was not translated" % fast)

gmsh.clear()
occ.addBox(0, 0, 0, 1, 1, 1)
occ.synchronize()
n = len(gmsh.model.getEntities(2))
try:
    occ.translate([(2, 1)], -1, 0, 0)
    errors.append("a face of a box was translated alone")
except Exception:
    pass
occ.synchronize()
if len(gmsh.model.getEntities(2)) != n:
    errors.append("%d surfaces instead of %d after the refused translation" %
                  (len(gmsh.model.getEntities(2)), n))
# the box itself, and a copy of the face, can be
occ.translate([(3, 1)], 1, 0, 0)
occ.translate(occ.copy([(2, 1)]), -1, 0, 0)
occ.synchronize()
if len(gmsh.model.getEntities(2)) != n + 1:
    errors.append("the copy of a face was not translated")

gmsh.finalize()

if errors:
    print("\n".join(errors))
    sys.exit(1)
print("OK")
