# The boolean operations of the discrete CAD modeler: a tube
# drilled across the seams of its cylinders, its volume compared with the one
# computed by OpenCASCADE

import gmsh
import sys

gmsh.initialize(sys.argv)


def tube(kernel, **tolerance):
    outer = kernel.addCylinder(0, 0, 0, 0, 0, 2, 0.5, **tolerance)
    inner = kernel.addCylinder(0, 0, -0.5, 0, 0, 3, 0.3, **tolerance)
    t, _ = kernel.cut([(3, outer)], [(3, inner)])
    drill = kernel.addCylinder(-1, 0, 1, 2, 0, 0, 0.1, **tolerance)
    t, _ = kernel.cut(t, [(3, drill)])
    return t


gmsh.model.add("occ")
t = tube(gmsh.model.occ)
gmsh.model.occ.synchronize()
exact = sum(gmsh.model.occ.getMass(3, tag) for _, tag in t)
gmsh.model.remove()

gmsh.model.add("discrete_booleans")
t = tube(gmsh.model.discrete, tolerance=1e-3)
gmsh.model.discrete.synchronize()
for dim in range(4):
    print("dimension {}: {} entities".format(dim,
                                             len(gmsh.model.getEntities(dim))))

gmsh.option.setNumber("Mesh.MeshSizeMax", 0.05)
gmsh.model.mesh.generate(3)

volume = 0.
for _, tag in t:
    _, elementTags, _ = gmsh.model.mesh.getElements(3, tag)
    volume += sum(gmsh.model.mesh.getElementQualities(elementTags[0], "volume"))
print("volume {:.5f}, OpenCASCADE {:.5f}".format(volume, exact))

if '-nopopup' not in sys.argv:
    gmsh.fltk.run()

gmsh.finalize()
