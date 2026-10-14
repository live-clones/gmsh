# Regression check for the unconstrained 3D Delaunay of cospherical points
# (Mesh.Algorithm3D = 1): ties between Delaunay configurations must be resolved
# from the input order of the points, not from where the allocator puts them.
# The corners of a cube and of an octahedron are tetrahedralized repeatedly,
# with mesh data of varied sizes allocated and freed in between so that the
# vertices land at different addresses; every run must give the same
# tetrahedra, which must fill the polyhedron.

import sys
import gmsh

shapes = {
    'cube': ([0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0,
              0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1], 1.),
    'octahedron': ([1, 0, 0, -1, 0, 0, 0, 1, 0, 0, -1, 0,
                    0, 0, 1, 0, 0, -1], 4. / 3.)
}

gmsh.initialize()
gmsh.option.setNumber('General.Terminal', 0)
gmsh.option.setNumber('Mesh.Algorithm3D', 1)
gmsh.option.setNumber('Mesh.RandomFactor3D', 0)


def volume(x, t):
    p = [x[3 * (n - 1):3 * n] for n in t]
    a, b, c = [[p[i][k] - p[0][k] for k in range(3)] for i in (1, 2, 3)]
    return abs(a[0] * (b[1] * c[2] - b[2] * c[1]) -
               a[1] * (b[0] * c[2] - b[2] * c[0]) +
               a[2] * (b[0] * c[1] - b[1] * c[0])) / 6.


def perturbHeap(repeat):
    # leave freed blocks of various sizes between live ones
    for i in range(8 + repeat):
        gmsh.model.add('heap%d' % i)
        gmsh.model.addDiscreteEntity(0, 1)
        n = 1 + (i * 7 + repeat) % 23
        gmsh.model.mesh.addNodes(0, 1, [], [0.] * 3 * n)
    for i in range(0, 8 + repeat, 2):
        gmsh.model.setCurrent('heap%d' % i)
        gmsh.model.remove()


failed = False
for name, (x, vol) in shapes.items():
    reference = None
    for repeat in range(16):
        perturbHeap(repeat)
        tets, steiner = gmsh.algorithm.tetrahedralize(x)
        tets = [list(map(int, tets[i:i + 4])) for i in range(0, len(tets), 4)]
        v = sum(volume(x, t) for t in tets)
        if len(steiner) or abs(v - vol) > 1e-12 or \
           any(volume(x, t) < 1e-12 for t in tets):
            print('%s: invalid tetrahedralization (volume %g)' % (name, v))
            failed = True
            break
        tets = sorted(sorted(t) for t in tets)
        if reference is None:
            reference = tets
        elif tets != reference:
            print('%s: connectivity depends on allocations (repeat %d)' %
                  (name, repeat))
            failed = True
            break
    if reference is not None and not failed:
        print('%s: %d tetrahedra, identical in 16 runs' % (name, len(reference)))

gmsh.finalize()
sys.exit(1 if failed else 0)
