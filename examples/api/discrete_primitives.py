# The discrete CAD modeler: a box and a sphere whose surfaces are
# triangulations (the sphere at most a given distance away from the exact
# surface), copied into the model by synchronize() and meshed like any other
# entities

import gmsh
import math
import sys

gmsh.initialize(sys.argv)
gmsh.model.add("discrete_primitives")

r = 0.5
tolerance = 1e-3
box = gmsh.model.discrete.addBox(0, 0, 0, 1, 1, 1)
sphere = gmsh.model.discrete.addSphere(2.5, 0.5, 0.5, r, tolerance=tolerance)
gmsh.model.discrete.synchronize()

for dim in range(4):
    print("dimension {}: {} entities".format(dim,
                                             len(gmsh.model.getEntities(dim))))

gmsh.option.setNumber("Mesh.MeshSizeMax", 0.1)
gmsh.model.mesh.generate(3)


# the volume of the tetrahedra of a volume
def volume(tag):
    nodeTags, coord, _ = gmsh.model.mesh.getNodes()
    x = dict(zip(nodeTags, zip(coord[0::3], coord[1::3], coord[2::3])))
    v = 0.
    for elementType, _, elementNodes in zip(*gmsh.model.mesh.getElements(3, tag)):
        if elementType != 4:
            continue
        for i in range(0, len(elementNodes), 4):
            a, b, c, d = (x[n] for n in elementNodes[i:i + 4])
            u = [b[k] - a[k] for k in range(3)]
            w = [c[k] - a[k] for k in range(3)]
            t = [d[k] - a[k] for k in range(3)]
            v += abs(u[0] * (w[1] * t[2] - w[2] * t[1]) -
                     u[1] * (w[0] * t[2] - w[2] * t[0]) +
                     u[2] * (w[0] * t[1] - w[1] * t[0])) / 6.
    return v


print("box volume: {:.6f} (exact 1)".format(volume(box)))
print("sphere volume: {:.6f} (exact {:.6f})".format(volume(sphere),
                                                    4. / 3. * math.pi * r**3))

# the nodes of the surface mesh of the sphere, on its triangulation: at most
# the tolerance away from the exact sphere
d = 0.
for dim, tag in gmsh.model.getBoundary([(3, sphere)], oriented=False):
    _, coord, _ = gmsh.model.mesh.getNodes(dim, tag, includeBoundary=True)
    for i in range(0, len(coord), 3):
        d = max(d, abs(math.dist(coord[i:i + 3], (2.5, 0.5, 0.5)) - r))
print("sphere: nodes at most {:.2e} from the exact surface (tolerance {})".
      format(d, tolerance))

if '-nopopup' not in sys.argv:
    gmsh.fltk.run()

gmsh.finalize()
