import gmsh
import sys

# With Geometry.OCCBooleanPreserveNumbering = 2, an entity split by a boolean
# operation and then transformed, without a synchronization of the model in
# between, gives its physical groups to all its pieces: the piece that keeps
# its tag used to hide the others

gmsh.initialize(sys.argv)
gmsh.option.setNumber("Geometry.OCCBooleanPreserveNumbering", 2)
occ = gmsh.model.occ
errors = []


def check(what, n):
    g = gmsh.model.getEntitiesForPhysicalGroup(2, 100)
    if len(g) != n:
        errors.append("%s: physical surface 100 has %d surfaces instead of %d" %
                      (what, len(g), n))
    for t in g:
        b = gmsh.model.getBoundingBox(2, t)
        if b[0] < 10 - 1e-6 or b[3] > 11 + 1e-6:
            errors.append("%s: surface %d is not a piece of the translated "
                          "rectangle" % (what, t))


# split once, then translated
occ.addRectangle(0, 0, 0, 1, 1, 1)
occ.synchronize()
gmsh.model.addPhysicalGroup(2, [1], 100)
r = occ.addRectangle(-1, 0.5, 0, 5, 5)
out, _ = occ.fragment([(2, 1)], [(2, r)])
occ.translate(out, 10, 0, 0)
occ.synchronize()
check("fragment, translate", 2)

# split twice, then translated
gmsh.clear()
gmsh.option.setNumber("Geometry.OCCBooleanPreserveNumbering", 2)
occ.addRectangle(0, 0, 0, 1, 1, 1)
occ.synchronize()
gmsh.model.addPhysicalGroup(2, [1], 100)
r = occ.addRectangle(-1, 0.5, 0, 5, 5)
out, _ = occ.fragment([(2, 1)], [(2, r)])
r = occ.addRectangle(0.5, -1, 0, 5, 5)
out, _ = occ.fragment(out, [(2, r)])
occ.translate(out, 10, 0, 0)
occ.synchronize()
check("two fragments, translate", 4)

gmsh.finalize()

if errors:
    print("\n".join(errors))
    sys.exit(1)
print("OK")
