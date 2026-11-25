import gmsh
import os
import sys
import tempfile

# .geo_unrolled files keep the tags of the named physical groups, and Radioss
# files get node sets for the physical points, e.g. for the reference point of
# a rigid body (#3294)

gmsh.initialize(sys.argv)
gmsh.model.add("physicals")
p = [gmsh.model.geo.addPoint(x, y, 0) for x, y in [(0, 0), (1, 0), (1, 1), (0, 1)]]
l = [gmsh.model.geo.addLine(p[i], p[(i + 1) % 4]) for i in range(4)]
s = gmsh.model.geo.addPlaneSurface([gmsh.model.geo.addCurveLoop(l)])
gmsh.model.geo.synchronize()
groups = {(0, 5): "reference", (1, 3): "wall", (2, 7): "plate"}
gmsh.model.addPhysicalGroup(0, [p[0]], 5, "reference")
gmsh.model.addPhysicalGroup(1, [l[0]], 3, "wall")
gmsh.model.addPhysicalGroup(2, [s], 7, "plate")
gmsh.model.mesh.generate(2)

errors = []
d = tempfile.mkdtemp()
geo = os.path.join(d, "physicals.geo_unrolled")
rad = os.path.join(d, "physicals.rad")
gmsh.write(geo)
gmsh.option.setNumber("Mesh.SaveGroupsOfNodes", 1)
gmsh.write(rad)
if "/GRNOD/NODE/1\nreference" not in open(rad).read():
    errors.append("no Radioss node set for physical point 5")

gmsh.clear()
gmsh.open(geo)
read = {(dim, tag): gmsh.model.getPhysicalName(dim, tag)
        for dim, tag in gmsh.model.getPhysicalGroups()}
if read != groups:
    errors.append("physical groups read back as %s instead of %s" %
                  (read, groups))
gmsh.finalize()
for f in [geo, rad]:
    os.remove(f)
os.rmdir(d)

if errors:
    print("\n".join(errors))
    sys.exit(1)
print("OK")
