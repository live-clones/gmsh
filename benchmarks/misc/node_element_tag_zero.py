import gmsh
import sys

# Explicit node and element tags must be strictly positive: a tag 0 used to be
# silently replaced by a new tag, possibly one given to another element, which
# lost an element (a hole in #2387); it is now an error, and nothing is added

gmsh.initialize(sys.argv)
errors = []


def rejected(what, f):
    try:
        f()
    except Exception as e:
        if "strictly positive" in str(e):
            return
        errors.append("%s: unexpected error %s" % (what, e))
        return
    errors.append("%s: tag 0 accepted" % what)


gmsh.model.addDiscreteEntity(2, 1)
coord = [0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0]
rejected("addNodes",
         lambda: gmsh.model.mesh.addNodes(2, 1, [0, 1, 2, 3], coord))
if len(gmsh.model.mesh.getNodes()[0]):
    errors.append("addNodes added nodes")

gmsh.model.mesh.addNodes(2, 1, [1, 2, 3, 4], coord)
rejected("addElementsByType",
         lambda: gmsh.model.mesh.addElementsByType(1, 2, [0, 1],
                                                   [1, 2, 3, 1, 3, 4]))
rejected("addElements",
         lambda: gmsh.model.mesh.addElements(2, 1, [2], [[0, 1]],
                                             [[1, 2, 3, 1, 3, 4]]))
rejected("addPolygons",
         lambda: gmsh.model.mesh.addPolygons(1, [0], [1, 2, 3, 4], [4]))
if len(gmsh.model.mesh.getElements(2)[0]):
    errors.append("elements added")

# tags from 1, or automatic tags, are fine
gmsh.model.mesh.addElementsByType(1, 2, [1, 2], [1, 2, 3, 1, 3, 4])
gmsh.model.mesh.addElementsByType(1, 2, [], [1, 2, 3, 1, 3, 4])
tags = sorted(gmsh.model.mesh.getElements(2)[1][0])
if tags != [1, 2, 3, 4]:
    errors.append("element tags %s instead of [1, 2, 3, 4]" % tags)

gmsh.finalize()

if errors:
    print("\n".join(errors))
    sys.exit(1)
print("OK")
