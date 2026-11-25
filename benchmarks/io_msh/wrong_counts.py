import gmsh
import os
import sys
import tempfile

# MSH4 files whose section headers do not agree with their blocks, or with an
# invalid dimension for a physical name, are refused with an error (they used
# to be read past the end of the arrays sized by the headers)

gmsh.initialize(sys.argv)
errors = []
n = 20000


def write(name, nodes, elements, dim=2):
    with open(name, "w") as f:
        f.write("$MeshFormat\n4.1 0 8\n$EndMeshFormat\n")
        f.write("$PhysicalNames\n1\n%d 1 \"a\"\n$EndPhysicalNames\n" % dim)
        f.write("$Entities\n0 0 1 0\n1 0 0 0 1 1 0 0 0\n$EndEntities\n")
        f.write("$Nodes\n1 %d 1 %d\n2 1 0 %d\n" % (nodes, n, n))
        f.write("".join("%d\n" % (i + 1) for i in range(n)))
        f.write("".join("%d %d 0\n" % (i, i % 7) for i in range(n)))
        f.write("$EndNodes\n")
        f.write("$Elements\n1 %d 1 %d\n2 1 2 %d\n" % (elements, n - 2, n - 2))
        f.write("".join("%d %d %d %d\n" % (i + 1, i + 1, i + 2, i + 3)
                        for i in range(n - 2)))
        f.write("$EndElements\n")


with tempfile.TemporaryDirectory() as tmp:
    for what, args, ok in [("consistent file", (n, n - 2), True),
                           ("number of nodes", (1, n - 2), False),
                           ("number of elements", (n, 1), False),
                           ("dimension of physical name", (n, n - 2, 100), False)]:
        name = os.path.join(tmp, "wrong_counts.msh")
        write(name, *args)
        gmsh.clear()
        try:
            gmsh.open(name)
            read = True
        except Exception:
            read = False
        if read != ok:
            errors.append("%s: %s" % (what, "read" if read else "not read"))
        elif ok and len(gmsh.model.mesh.getNodes()[0]) != n:
            errors.append("%s: wrong number of nodes read" % what)

gmsh.finalize()

if errors:
    print("\n".join(errors))
    sys.exit(1)
print("OK")
