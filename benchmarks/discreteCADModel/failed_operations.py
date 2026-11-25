import gmsh
import sys

# Operations of the discrete CAD modeler that fail leave the model as it was:
# a boolean operation whose tag is taken (its operands used to be removed
# first), and a fillet whose radius is too large for one of several volumes
# (the volumes done before used to stay filleted)

gmsh.initialize(sys.argv)
discrete = gmsh.model.discrete
errors = []


def entities():
    return [len(gmsh.model.getEntities(dim)) for dim in range(4)]


a = discrete.addBox(0, 0, 0, 1, 1, 1)
b = discrete.addBox(0.5, 0.5, 0.5, 1, 1, 1)
c = discrete.addBox(5, 0, 0, 1, 1, 1)
discrete.synchronize()
before = entities()
try:
    discrete.cut([(3, a)], [(3, b)], tag=c)
    errors.append("boolean operation with the tag of another volume done")
except Exception:
    pass
discrete.synchronize()
if entities() != before:
    errors.append("entities %s instead of %s after the failed boolean "
                  "operation" % (entities(), before))

gmsh.clear()
a = discrete.addBox(0, 0, 0, 1, 1, 1)
b = discrete.addBox(3, 0, 0, 1, 1, 1)
discrete.synchronize()
before = entities()
curves = [[], []]
for _, tag in gmsh.model.getEntities(1):
    x = gmsh.model.getBoundingBox(1, tag)
    if abs(x[2]) < 1e-6 and abs(x[5] - 1) < 1e-6:
        curves[0 if x[0] < 2 else 1].append(tag)
try:
    discrete.fillet([a, b], curves[0] + curves[1],
                    [0.2] * len(curves[0]) + [5.] * len(curves[1]))
    errors.append("fillet with a radius larger than the box done")
except Exception:
    pass
discrete.synchronize()
if entities() != before:
    errors.append("entities %s instead of %s after the failed fillet" %
                  (entities(), before))
# and the model can still be filleted
discrete.fillet([a], curves[0], [0.2])
discrete.synchronize()
if entities()[2] != before[2] + 4:
    errors.append("%d surfaces instead of %d after the fillet" %
                  (entities()[2], before[2] + 4))

gmsh.finalize()

if errors:
    print("\n".join(errors))
    sys.exit(1)
print("OK")
