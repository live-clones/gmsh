import gmsh
import os
import sys
import tempfile

# A mesh in the z = 0 plane without volume elements is saved in Medit format as
# a 2D mesh ("Dimension 2", 2 coordinates per node), and the Dimension field is
# read on one line or two, with or without leading spaces (#2402)

gmsh.initialize(sys.argv)
errors = []
d = tempfile.mkdtemp()
f = os.path.join(d, "square.mesh")

gmsh.model.add("square")
p = [gmsh.model.geo.addPoint(x, y, 0, 0.2) for x, y in [(0, 0), (1, 0), (1, 1), (0, 1)]]
l = [gmsh.model.geo.addLine(p[i], p[(i + 1) % 4]) for i in range(4)]
gmsh.model.geo.addPlaneSurface([gmsh.model.geo.addCurveLoop(l)])
gmsh.model.geo.synchronize()
gmsh.model.mesh.generate(2)
num = len(gmsh.model.mesh.getNodes()[0])
gmsh.write(f)
txt = open(f).read()
if " Dimension\n 2\n" not in txt:
    errors.append("planar mesh not saved with Dimension 2")

variants = {"two lines": txt,
            "one line": txt.replace(" Dimension\n 2\n", " Dimension 2\n"),
            "no spaces": txt.replace(" Dimension\n 2\n", "Dimension\n2\n")}
for what, t in variants.items():
    open(f, "w").write(t)
    gmsh.clear()
    gmsh.open(f)
    tags, xyz, _ = gmsh.model.mesh.getNodes()
    if len(tags) != num or max(abs(z) for z in xyz[2::3]) != 0:
        errors.append("%s: read %d nodes (instead of %d), max |z| %g" %
                      (what, len(tags), num, max(abs(z) for z in xyz[2::3])))

# a volume mesh stays 3D
gmsh.clear()
gmsh.model.occ.addBox(0, 0, 0, 1, 1, 1)
gmsh.model.occ.synchronize()
gmsh.model.mesh.generate(3)
gmsh.write(f)
if " Dimension\n 3\n" not in open(f).read():
    errors.append("volume mesh not saved with Dimension 3")

gmsh.finalize()
os.remove(f)
os.rmdir(d)

if errors:
    print("\n".join(errors))
    sys.exit(1)
print("OK")
