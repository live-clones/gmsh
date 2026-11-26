# Regression check for #3521: with Mesh.MMG3DCombineDomains = 1, the sizes of
# the MMG3D passes after the first one are evaluated in the region of each
# vertex, so that a field restricted to one of the volumes gives the same
# number of tetrahedra as with one MMG3D call per volume.

import sys
import gmsh

gmsh.initialize(sys.argv)
gmsh.option.setNumber("General.Terminal", 0)
gmsh.option.setNumber("General.Verbosity", 1)
if "Mmg" not in gmsh.option.getString("General.BuildOptions"):
    print("Gmsh is not compiled with MMG: skipped")
    gmsh.finalize()
    sys.exit(77)


def count(combine):
    gmsh.clear()
    gmsh.model.occ.addBox(0, 0, 0, 1, 1, 1)
    gmsh.model.occ.addBox(1, 0, 0, 1, 1, 1)
    gmsh.model.occ.fragment([(3, 1)], [(3, 2)])
    gmsh.model.occ.synchronize()
    fields = []
    for vol, size in ((1, 0.3), (2, 0.1)):
        f = gmsh.model.mesh.field.add("MathEval")
        gmsh.model.mesh.field.setString(f, "F", str(size))
        r = gmsh.model.mesh.field.add("Restrict")
        gmsh.model.mesh.field.setNumber(r, "InField", f)
        gmsh.model.mesh.field.setNumbers(r, "VolumesList", [vol])
        fields.append(r)
    m = gmsh.model.mesh.field.add("Min")
    gmsh.model.mesh.field.setNumbers(m, "FieldsList", fields)
    gmsh.model.mesh.field.setAsBackgroundMesh(m)
    gmsh.option.setNumber("Mesh.MeshSizeExtendFromBoundary", 0)
    gmsh.option.setNumber("Mesh.MeshSizeFromPoints", 0)
    gmsh.option.setNumber("Mesh.MeshSizeFromCurvature", 0)
    gmsh.option.setNumber("Mesh.Algorithm3D", 7)
    gmsh.option.setNumber("Mesh.MMG3DCombineDomains", combine)
    gmsh.model.mesh.generate(3)
    return len(gmsh.model.mesh.getElementsByType(4, 2)[0])


separate, combined = count(0), count(1)
gmsh.finalize()

if abs(combined - separate) > 0.2 * separate:
    print("FAILED: %d tetrahedra in the fine volume with one MMG3D call per "
          "volume, %d with a combined call" % (separate, combined))
    sys.exit(1)

print("OK: %d and %d tetrahedra in the fine volume" % (separate, combined))
