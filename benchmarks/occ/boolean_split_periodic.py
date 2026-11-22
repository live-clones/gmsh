# With Geometry.OCCBooleanPreserveNumbering = 2, periodic surfaces and curves
# split by boolean operations stay periodic (#338): check that the nodes of the
# meshes of their pieces correspond

import gmsh
import sys

gmsh.initialize(sys.argv)
gmsh.option.setNumber('Geometry.OCCBooleanPreserveNumbering', 2)
gmsh.option.setNumber('Mesh.MeshSizeMax', 0.1)
translation = [1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1]


def check(dim, expected):
    pieces = 0
    for _, t in gmsh.model.getEntities(dim):
        m, nodes, masterNodes, _ = gmsh.model.mesh.getPeriodicNodes(dim, t)
        if m == t or not len(nodes):
            continue
        pieces += 1
        for n, mn in zip(nodes, masterNodes):
            x = gmsh.model.mesh.getNode(n)[0]
            xm = gmsh.model.mesh.getNode(mn)[0]
            d = abs(x[0] - xm[0] - 1) + abs(x[1] - xm[1]) + abs(x[2] - xm[2])
            if d > 1e-10:
                raise Exception('Node %d is not the image of node %d' % (n, mn))
    if pieces != expected:
        raise Exception('%d periodic entities of dimension %d instead of %d' %
                        (pieces, dim, expected))


# a cube periodic in x, with spheres on the periodic faces, which are split
# into a disk and a face with a hole
gmsh.model.add('cube')
gmsh.model.occ.addBox(0, 0, 0, 1, 1, 1)
gmsh.model.occ.synchronize()
gmsh.model.mesh.setPeriodic(2, [2], [1], translation)
s1 = gmsh.model.occ.addSphere(0, 0.5, 0.5, 0.2)
s2 = gmsh.model.occ.addSphere(1, 0.5, 0.5, 0.2)
gmsh.model.occ.fragment([(3, 1)], [(3, s1), (3, s2)])
gmsh.model.occ.synchronize()
gmsh.model.mesh.generate(3)
check(2, 2)

# a square periodic in x, with disks on the periodic curves, which are split
# into three curves
gmsh.model.add('square')
gmsh.model.occ.addRectangle(0, 0, 0, 1, 1)
gmsh.model.occ.synchronize()
gmsh.model.mesh.setPeriodic(1, [2], [4], translation)
d1 = gmsh.model.occ.addDisk(0, 0.5, 0, 0.2, 0.2)
d2 = gmsh.model.occ.addDisk(1, 0.5, 0, 0.2, 0.2)
gmsh.model.occ.fragment([(2, 1)], [(2, d1), (2, d2)])
gmsh.model.occ.synchronize()
gmsh.model.mesh.generate(2)
check(1, 3)

gmsh.finalize()
