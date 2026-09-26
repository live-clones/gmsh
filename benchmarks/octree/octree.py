#!/usr/bin/env python3
# Times the search of the mesh elements containing a point (MElementOctree,
# through gmsh.model.mesh.getElementByCoordinates) and of the probes of views
# (OctreePost), on straight-sided, curved and hexahedral meshes:
#
#   python3 octree.py [--api dir] [--size small|large] [--dump file] [cases...]
#   python3 octree.py --compare file1 file2
#
# For each case: the time to build the octree (with the first query), and the
# time per query for points inside the mesh, points just outside (strict, and
# lenient, i.e. retrying with larger tolerances), and all the elements
# containing a point. --dump writes the elements found, so that two builds can
# be compared with --compare (e.g. with --api pointing to the api directory of
# another tree, which loads the library of the build next to it). Points on
# nodes or faces shared by several elements may legitimately differ.

import argparse
import os
import random
import sys
import time

HERE = os.path.dirname(os.path.abspath(__file__))

# name: (geometry, mesh size for --size small and large, order)
CASES = {
    'tet': ('box', 0.05, 0.0125, 1),
    'tet2': ('sphere', 0.1, 0.03, 2),
    'hex': ('hexbox', 0.05, 0.01, 1),
    'tri': ('square', 0.02, 0.002, 1),
    'view': ('box', 0.05, 0.02, 1)
}


def build(gmsh, geo, h, order):
    if geo == 'square':
        gmsh.model.occ.addRectangle(0, 0, 0, 1, 1)
    elif geo == 'sphere':
        gmsh.model.occ.addSphere(0.5, 0.5, 0.5, 0.5)
    else:
        gmsh.model.occ.addBox(0, 0, 0, 1, 1, 1)
    gmsh.model.occ.synchronize()
    if geo == 'hexbox':
        n = int(round(1 / h))
        for c in gmsh.model.getEntities(1):
            gmsh.model.mesh.setTransfiniteCurve(c[1], n + 1)
        for s in gmsh.model.getEntities(2):
            gmsh.model.mesh.setTransfiniteSurface(s[1])
            gmsh.model.mesh.setRecombine(2, s[1])
        gmsh.model.mesh.setTransfiniteVolume(1)
    gmsh.option.setNumber('Mesh.MeshSizeMin', h)
    gmsh.option.setNumber('Mesh.MeshSizeMax', h)
    dim = 2 if geo == 'square' else 3
    gmsh.model.mesh.generate(dim)
    if order > 1: gmsh.model.mesh.setOrder(order)
    return dim


def points(geo, dim, n):
    # points inside, and points outside at distances from 1e-6 to 0.5
    def inside():
        while True:
            p = [random.uniform(0.01, 0.99) for i in range(3)]
            if dim == 2: p[2] = 0
            if geo != 'sphere' or sum((x - .5)**2 for x in p) < .45**2:
                return p

    def outside():
        d = 10**random.uniform(-6, -0.3)
        if geo == 'sphere':
            q = [random.gauss(0, 1) for i in range(3)]
            r = sum(x * x for x in q)**0.5
            return [0.5 + x / r * (0.5 + d) for x in q]
        p = [random.uniform(0, 1) for i in range(3)]
        p[random.randrange(dim)] = 1 + d if random.random() < 0.5 else -d
        if dim == 2: p[2] = 0
        return p

    return [inside() for i in range(n)], [outside() for i in range(n // 10)]


def timed(out, label, pts, f):
    t = time.perf_counter()
    res = []
    for p in pts:
        try:
            res.append(f(p))
        except Exception:
            res.append(None)
    dt = time.perf_counter() - t
    found = sum(r is not None for r in res)
    print(f'  {label:24s} {1e6 * dt / len(pts):10.1f} us/query  '
          f'found {found}/{len(pts)}')
    if out: out.write(f'{label}: {res}\n')


def run(gmsh, name, size, out):
    geo, hs, hl, order = CASES[name]
    gmsh.clear()
    random.seed(1)
    dim = build(gmsh, geo, hs if size == 'small' else hl, order)
    num = len(gmsh.model.mesh.getElements(dim)[1][0])
    pin, pout = points(geo, dim, 20000)
    print(f'{name}: {num} elements of dimension {dim}, order {order}')
    if out: out.write(f'case {name}\n')
    if name == 'view':
        # a list-based view on the tetrahedra, and the same values in a
        # model-based view
        tags, coord, _ = gmsh.model.mesh.getNodes()
        X = {int(t): coord[3 * i:3 * i + 3] for i, t in enumerate(tags)}
        f = lambda x: x[0] + 2 * x[1] * x[2]
        vm = gmsh.view.add('model')
        gmsh.view.addHomogeneousModelData(vm, 0, '', 'NodeData', tags,
                                          [f(X[int(t)]) for t in tags])
        et, en = gmsh.model.mesh.getElementsByType(4)
        data = []
        for i in range(len(et)):
            ns = [X[int(n)] for n in en[4 * i:4 * i + 4]]
            data += [x[k] for k in range(3) for x in ns] + [f(x) for x in ns]
        vl = gmsh.view.add('list')
        gmsh.view.addListData(vl, 'SS', len(et), data)
        for v, label in ((vl, 'list'), (vm, 'model')):
            t = time.perf_counter()
            gmsh.view.probe(v, 0.5, 0.5, 0.5)
            print(f'  {label} view: build {time.perf_counter() - t:.3f} s')
            probe = lambda p: float(gmsh.view.probe(v, *p)[0][0])
            timed(out, f'{label} probe inside', pin, probe)
            probe = lambda p: float(
                gmsh.view.probe(v, *p, distanceMax=0.1)[0][0])
            timed(out, f'{label} probe outside', pout, probe)
        return
    t = time.perf_counter()
    gmsh.model.mesh.getElementByCoordinates(*pin[0], dim, True)
    print(f'  build (+1 query)         {time.perf_counter() - t:10.3f} s')
    find = lambda d, s: lambda p: int(
        gmsh.model.mesh.getElementByCoordinates(*p, d, s)[0])
    timed(out, 'inside', pin, find(dim, True))
    timed(out, 'inside, any dim', pin, find(-1, True))
    timed(out, 'outside, strict', pout, find(dim, True))
    timed(out, 'outside, lenient', pout, find(dim, False))
    timed(out, 'outside, lenient, any dim', pout, find(-1, False))
    findAll = lambda p: sorted(
        int(e) for e in gmsh.model.mesh.getElementsByCoordinates(*p, -1, True))
    timed(out, 'all', pin[:2000], findAll)


def same(u, v):
    # probed values are compared up to round-off
    if isinstance(u, float) and isinstance(v, float):
        return abs(u - v) <= 1e-9 * (1 + abs(u))
    return u == v


def compare(file1, file2):
    a = open(file1).read().splitlines()
    b = open(file2).read().splitlines()
    diff = 0
    for x, y in zip(a, b):
        if x.startswith('case'):
            print(x)
        elif x != y:
            label, rx = x.split(': ', 1)
            ry = y.split(': ', 1)[1]
            rx, ry = eval(rx), eval(ry)
            d = [(i, u, v) for i, (u, v) in enumerate(zip(rx, ry))
                 if not same(u, v)]
            if not d: continue
            print(f'  {label}: {len(d)} of {len(rx)} differ, e.g. {d[:4]}')
            diff += 1
    return 1 if diff else 0


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('cases', nargs='*', default=list(CASES))
    ap.add_argument('--api', default=os.path.join(HERE, '..', '..', 'api'))
    ap.add_argument('--size', choices=['small', 'large'], default='small')
    ap.add_argument('--dump')
    ap.add_argument('--compare', nargs=2)
    args = ap.parse_args()
    if args.compare: sys.exit(compare(*args.compare))
    sys.path.insert(0, os.path.abspath(args.api))
    import gmsh
    gmsh.initialize()
    gmsh.option.setNumber('General.Terminal', 0)
    gmsh.option.setNumber('General.NumThreads', 1)
    out = open(args.dump, 'w') if args.dump else None
    for name in args.cases:
        run(gmsh, name, args.size, out)
    gmsh.finalize()


if __name__ == '__main__':
    main()
