#!/usr/bin/env python3
# Scalability of the meshes and the views made of polygons and polyhedra:
#
#   python3 scalability.py [--api dir] [--size small|medium|large]
#                          [--cells n,n,...] [--dims 2,3] [--given] [--nt n]
#                          [--no-draw] [--dump file] [stages...]
#   python3 scalability.py --compare file1 file2
#
# The meshes are honeycombs: hexagons in 2D, and the same hexagons extruded
# into layers of hexagonal prisms in 3D, so that every result has an exact
# value to check against (areas and volumes, integrals of a linear field,
# skins, sections, numbers of edges and faces). With --given, each cell gets
# a node at its centre and its sub-triangulation or sub-tetrahedralization
# is given (6 triangles, 20 tetrahedra), instead of being computed by Gmsh.
#
# Each size and dimension runs in a process of its own, which times each
# stage below and reports the peak memory after it:
#
#   build      nodes and polytopes added through the API
#   get        polytopes read back through the API
#   simplices  their sub-simplices (computed on the fly if not given)
#   measure    Plugin(MeshVolume): the area or the volume
#   view       a node view of f = x + 2y + 3z added through the API
#   integrate  Plugin(Integrate) of the view
#   skin       Plugin(Skin) of the view
#   cut        Plugin(CutPlane) of the view, and the integral of the section
#   edgesfaces mesh edges (and faces in 3D) created
#   writemsh   mesh (binary MSH 4.2, with edges and faces) and view written
#   readmsh    and read back in a new model
#   vtu        mesh written in .vtu and read back
#   med        mesh written in .med and read back (if Gmsh has MED)
#   draw       a picture of the view clipped and capped (if Gmsh has OpenGL)
#
# The table gives the time of each stage for each size, and the exponent of
# its growth between the last two sizes (1 for a linear stage). --dump writes
# the results, so that two builds can be compared with --compare (e.g. with
# --api pointing to the api directory of another tree, which loads the
# library of the build next to it).

import argparse
import json
import math
import os
import resource
import subprocess
import sys
import tempfile
import time

HERE = os.path.dirname(os.path.abspath(__file__))
STAGES = ['build', 'get', 'simplices', 'measure', 'view', 'integrate', 'skin',
          'cut', 'edgesfaces', 'writemsh', 'readmsh', 'vtu', 'med', 'draw']
SIZES = {'small': [1000, 10000], 'medium': [10000, 100000],
         'large': [10000, 100000, 1000000]}
H = 1.5  # layer height of the prisms


def honeycomb(nx, ny):
    # pointy-top hexagons of circumradius 1 in nx columns and ny rows; the
    # corners are on the lattice of integer (X, Y), x = X sqrt(3) / 2 and
    # y = Y / 2, the centre of cell (q, r) at X = 2q + r, Y = 3r
    import numpy as np
    r = np.repeat(np.arange(ny), nx)
    q = np.tile(np.arange(nx), ny) - r // 2
    cx, cy = 2 * q + r, 3 * r
    off = np.array([(1, 1), (0, 2), (-1, 1), (-1, -1), (0, -2), (1, -1)])
    kx = cx[:, None] + off[:, 0] + 2
    ky = cy[:, None] + off[:, 1] + 2
    width = 2 * nx + ny + 8
    keys, inv = np.unique(ky * width + kx, return_inverse=True)
    cells = inv.reshape(-1, 6) + 1  # node tags, counter-clockwise
    x = (keys % width - 2) * math.sqrt(3) / 2
    y = (keys // width - 2) * 0.5
    # the edges, each sorted, and those of one cell only (the boundary)
    a, b = cells, np.roll(cells, -1, axis=1)
    e = np.sort(np.stack([a.ravel(), b.ravel()], axis=1), axis=1)
    _, counts = np.unique(e[:, 0] * (len(keys) + 1) + e[:, 1],
                          return_counts=True)
    return {'x': x, 'y': y, 'cells': cells,
            'cx': cx * math.sqrt(3) / 2, 'cy': cy * 0.5,
            'edges': len(counts), 'boundary': int((counts == 1).sum())}


def case(dim, cells, given):
    # the mesh of a case, with what its results should be
    import numpy as np
    area = 3 * math.sqrt(3) / 2  # of a hexagon of circumradius 1
    if dim == 2:
        n = max(2, round(math.sqrt(cells)))
        hc, layers = honeycomb(n, n), 1
    else:
        n = max(2, round(cells ** (1 / 3)))
        hc, layers = honeycomb(n, n), n
    nc2, nn2 = len(hc['cells']), len(hc['x'])
    c = {'dim': dim, 'given': given, 'n2': nc2, 'layers': layers}
    if dim == 2:
        c['x'], c['y'], c['z'] = hc['x'], hc['y'], np.zeros(nn2)
        c['cells'] = hc['cells']
        c['cx'], c['cy'], c['cz'] = hc['cx'], hc['cy'], np.zeros(nc2)
        c['num'] = nc2
        c['measure'] = nc2 * area
        c['skin'] = {'SL': hc['boundary']}
        c['edges'] = hc['edges']
        c['simplices'] = 6 * nc2 if given else 4 * nc2  # (ear clipping)
        # the section by y = y0, between two rows of centres: its length
        c['y0'] = 0.75
    else:
        lev = np.arange(layers + 1)
        c['x'] = np.tile(hc['x'], layers + 1)
        c['y'] = np.tile(hc['y'], layers + 1)
        c['z'] = np.repeat(lev * H, nn2).astype(float)
        cells = hc['cells']
        faces = []
        for k in range(layers):
            lo, hi = cells + k * nn2, cells + (k + 1) * nn2
            f = [lo[:, ::-1], hi]  # bottom (outward), top
            for i in range(6):
                j = (i + 1) % 6
                f.append(np.stack([lo[:, i], lo[:, j], hi[:, j], hi[:, i]],
                                  axis=1))
            faces.append(np.concatenate(f, axis=1))
        c['cells'] = np.concatenate(faces)
        c['cx'] = np.tile(hc['cx'], layers)
        c['cy'] = np.tile(hc['cy'], layers)
        c['cz'] = np.repeat((np.arange(layers) + 0.5) * H, nc2)
        c['num'] = nc2 * layers
        c['measure'] = c['num'] * area * H
        # the hexagons of the skin as fans of 4 triangles, its quadrangles
        c['skin'] = {'ST': 8 * nc2, 'SQ': layers * hc['boundary']}
        c['edges'] = (layers + 1) * hc['edges'] + layers * nn2
        c['faces'] = (layers + 1) * nc2 + layers * hc['edges']
        # (fan from the first node: the top hexagon and 4 of the quadrangles)
        c['simplices'] = 20 * c['num'] if given else 12 * c['num']
        # the section by z = z0, in the middle of the first layer
        c['z0'] = 0.5 * H
        c['section'] = nc2 * area
        sec = area * (hc['cx'] + 2 * hc['cy'] + 3 * c['z0'])
        c['section_integral'] = float(sec.sum())
    # f = x + 2y + 3z is linear: its integral over a cell is the measure of
    # the cell times its value at the centroid
    cm = c['measure'] / c['num']
    c['integral'] = float((cm * (c['cx'] + 2 * c['cy'] + 3 * c['cz'])).sum())
    return c


def peak_mb():
    r = resource.getrusage(resource.RUSAGE_SELF).ru_maxrss
    return r / (1 << 20) if sys.platform == 'darwin' else r / (1 << 10)


def child(args):
    import numpy as np
    import gmsh
    dim, cells, given = args.child_dim, args.child_cells, args.given
    t0 = time.perf_counter()
    c = case(dim, cells, given)
    times = {'generate': time.perf_counter() - t0}
    mem, checks = {}, {}
    out = {'dim': dim, 'cells': c['num'], 'times': times, 'memory': mem,
           'checks': checks}
    tmp = tempfile.mkdtemp(prefix='gmsh_polytopes_')

    def check(name, value, expected, rtol=1e-9):
        ok = abs(value - expected) <= rtol * max(1., abs(expected))
        checks[name] = [value, expected, ok]

    def stage(name):
        # decorator: runs and times the stage if asked for
        def run(f):
            if args.stages and name not in args.stages:
                return
            t = time.perf_counter()
            try:
                f()
            except Exception as e:
                checks[name + ' error'] = [str(e)[:200], '', False]
            times[name] = time.perf_counter() - t
            mem[name] = peak_mb()
        return run

    def last_list(t):
        # the counts and the data of the list view of tag t, by type
        types, nums, data = gmsh.view.getListData(t)
        return {ty: (int(n), d) for ty, n, d in zip(types, nums, data) if n}

    def last_value():
        # the scalar a plugin like Integrate or MeshVolume leaves in its view
        l = last_list(gmsh.view.getTags()[-1])
        return float(l['SP'][1][3])

    gmsh.initialize(readConfigFiles=False)
    gmsh.option.setNumber('General.Terminal', 0)
    gmsh.option.setNumber('General.NumThreads', args.nt)
    gmsh.model.add('polytopes')
    ent = [None]

    @stage('build')
    def _():
        ent[0] = gmsh.model.addDiscreteEntity(dim)
        tags = np.arange(1, len(c['x']) + 1)
        xyz = np.stack([c['x'], c['y'], c['z']], axis=1).ravel()
        gmsh.model.mesh.addNodes(dim, ent[0], tags, xyz)
        cl = c['cells']
        if dim == 2:
            gmsh.model.mesh.addPolygons(ent[0], [], cl.ravel(),
                                        np.full(len(cl), 6))
        else:
            sizes = np.tile([6, 6, 4, 4, 4, 4, 4, 4], len(cl))
            gmsh.model.mesh.addPolyhedra(ent[0], [], np.full(len(cl), 8),
                                         sizes, cl.ravel())
        if given:
            # a node at the centre of each cell, and its simplices
            nn = len(c['x'])
            ctag = np.arange(nn + 1, nn + c['num'] + 1)
            cxyz = np.stack([c['cx'], c['cy'], c['cz']], axis=1).ravel()
            gmsh.model.mesh.addNodes(dim, ent[0], ctag, cxyz)
            if dim == 2:
                v = cl
                simp = np.stack([np.repeat(ctag, 6), v.ravel(),
                                 np.roll(v, -1, axis=1).ravel()], axis=1)
                per = 6
            else:
                # faces fanned from their first node, joined to the centre
                bot, top = cl[:, 0:6], cl[:, 6:12]
                tri = []
                for f in (bot, top):
                    for i in range(1, 5):
                        tri.append(np.stack([f[:, 0], f[:, i], f[:, i + 1]],
                                            axis=1))
                for s in range(6):
                    qd = cl[:, 12 + 4 * s:16 + 4 * s]
                    tri.append(qd[:, [0, 1, 2]])
                    tri.append(qd[:, [0, 2, 3]])
                tri = np.stack(tri, axis=1)  # (cells, 20, 3)
                simp = np.concatenate(
                    [np.repeat(ctag, 20)[:, None], tri.reshape(-1, 3)], axis=1)
                per = 20
            etags = gmsh.model.mesh.getPolygons(ent[0])[0] if dim == 2 else \
                gmsh.model.mesh.getPolyhedra(ent[0])[0]
            gmsh.model.mesh.setPolytopeSimplices(etags, np.full(len(etags), per),
                                                 simp.ravel())

    @stage('get')
    def _():
        if dim == 2:
            t, nodes, num = gmsh.model.mesh.getPolygons()
            check('polygons', len(t), c['num'])
            check('polygon nodes', len(nodes), 6 * c['num'])
        else:
            t, nf, fs, nodes = gmsh.model.mesh.getPolyhedra()
            check('polyhedra', len(t), c['num'])
            check('polyhedron face nodes', len(nodes), 36 * c['num'])

    @stage('simplices')
    def _():
        t, ns, nodes, giv = gmsh.model.mesh.getPolytopeSimplices(
            34 if dim == 2 else 35)
        check('simplices', int(np.sum(ns)), c['simplices'])
        check('given', int(np.sum(giv)), c['num'] if given else 0)

    @stage('measure')
    def _():
        gmsh.plugin.setNumber('MeshVolume', 'Dimension', dim)
        gmsh.plugin.run('MeshVolume')
        check('measure', last_value(), c['measure'], 1e-9)

    view = [None]

    @stage('view')
    def _():
        tags, coord, _ = gmsh.model.mesh.getNodes()
        x, y, z = coord[0::3], coord[1::3], coord[2::3]
        view[0] = gmsh.view.add('f')
        gmsh.view.addHomogeneousModelData(view[0], 0, 'polytopes', 'NodeData',
                                          tags, x + 2 * y + 3 * z)

    @stage('integrate')
    def _():
        gmsh.plugin.setNumber('Integrate', 'View',
                              gmsh.view.getIndex(view[0]))
        gmsh.plugin.setNumber('Integrate', 'Dimension', dim)
        gmsh.plugin.run('Integrate')
        check('integral', last_value(), c['integral'], 1e-8)

    @stage('skin')
    def _():
        gmsh.plugin.setNumber('Skin', 'View', gmsh.view.getIndex(view[0]))
        gmsh.plugin.setNumber('Skin', 'FromMesh', 0)
        gmsh.plugin.setNumber('Skin', 'Visible', 0)
        gmsh.plugin.run('Skin')
        l = last_list(gmsh.view.getTags()[-1])
        for ty, n in c['skin'].items():
            check('skin ' + ty, l.get(ty, (0, []))[0], n)

    @stage('cut')
    def _():
        p = gmsh.plugin
        if dim == 2:
            p.setNumber('CutPlane', 'A', 0)
            p.setNumber('CutPlane', 'B', 1)
            p.setNumber('CutPlane', 'C', 0)
            p.setNumber('CutPlane', 'D', -c['y0'])
        else:
            p.setNumber('CutPlane', 'A', 0)
            p.setNumber('CutPlane', 'B', 0)
            p.setNumber('CutPlane', 'C', 1)
            p.setNumber('CutPlane', 'D', -c['z0'])
        p.setNumber('CutPlane', 'View', gmsh.view.getIndex(view[0]))
        p.run('CutPlane')
        cut = gmsh.view.getTags()[-1]
        l = last_list(cut)
        n = sum(v[0] for v in l.values())
        checks['cut elements'] = [n, '> 0', n > 0]
        if dim == 3:
            p.setNumber('Integrate', 'View', gmsh.view.getIndex(cut))
            p.setNumber('Integrate', 'Dimension', 2)
            p.run('Integrate')
            check('section integral', last_value(), c['section_integral'],
                  1e-8)

    @stage('edgesfaces')
    def _():
        gmsh.model.mesh.createEdges()
        check('edges', len(gmsh.model.mesh.getAllEdges()[0]), c['edges'])
        if dim == 3:
            gmsh.model.mesh.createFaces()
            check('faces', len(gmsh.model.mesh.getAllFaces()[0]), c['faces'])

    msh = os.path.join(tmp, 'polytopes.msh')

    @stage('writemsh')
    def _():
        gmsh.option.setNumber('Mesh.Binary', 1)
        gmsh.option.setNumber('PostProcessing.SaveMesh', 0)
        gmsh.write(msh)
        gmsh.view.write(view[0], msh, True)
        out['msh MB'] = os.path.getsize(msh) / (1 << 20)

    @stage('readmsh')
    def _():
        gmsh.clear()
        gmsh.open(msh)
        if dim == 2:
            check('read polygons', len(gmsh.model.mesh.getPolygons()[0]),
                  c['num'])
        else:
            check('read polyhedra', len(gmsh.model.mesh.getPolyhedra()[0]),
                  c['num'])
            check('read faces', len(gmsh.model.mesh.getAllFaces()[0]),
                  c['faces'])
        check('read edges', len(gmsh.model.mesh.getAllEdges()[0]), c['edges'])
        check('read views', len(gmsh.view.getTags()), 1)

    def roundtrip(ext):
        f = os.path.join(tmp, 'polytopes.' + ext)
        gmsh.write(f)
        gmsh.clear()
        gmsh.open(f)
        n = len(gmsh.model.mesh.getPolygons()[0]) if dim == 2 else \
            len(gmsh.model.mesh.getPolyhedra()[0])
        check('read ' + ext, n, c['num'])

    @stage('vtu')
    def _():
        roundtrip('vtu')

    @stage('med')
    def _():
        roundtrip('med')

    @stage('draw')
    def _():
        if args.no_draw:
            return
        gmsh.clear()
        gmsh.open(msh)
        o = gmsh.option
        o.setNumber('General.GraphicsWidth', 800)
        o.setNumber('General.GraphicsHeight', 600)
        o.setNumber('Mesh.SurfaceFaces', 0)
        o.setNumber('Mesh.VolumeFaces', 0)
        o.setNumber('View[0].ShowElement', 1)
        o.setNumber('General.Clip0A', 1)
        o.setNumber('General.Clip0B', 0)
        o.setNumber('General.Clip0C', 0)
        o.setNumber('General.Clip0D', -float(np.mean(c['x'])))
        o.setNumber('View[0].Clip', 1)
        o.setNumber('General.ClipCapping', 1)
        o.setNumber('General.RotationX', -60)
        o.setNumber('General.RotationZ', 20)
        gmsh.write(os.path.join(tmp, 'polytopes.png'))

    gmsh.finalize()
    for f in os.listdir(tmp):
        os.remove(os.path.join(tmp, f))
    os.rmdir(tmp)
    print(json.dumps(out))


def run_case(dim, cells, args):
    cmd = [sys.executable, os.path.abspath(__file__), '--child-dim', str(dim),
           '--child-cells', str(cells), '--nt', str(args.nt)]
    if args.given:
        cmd.append('--given')
    if args.no_draw:
        cmd.append('--no-draw')
    cmd += args.stages
    env = dict(os.environ, PYTHONPATH=args.api)
    r = subprocess.run(cmd, env=env, capture_output=True, text=True)
    lines = [l for l in r.stdout.splitlines() if l.startswith('{')]
    if r.returncode or not lines:
        return {'dim': dim, 'cells': cells, 'crash': r.returncode,
                'stderr': r.stderr[-2000:]}
    return json.loads(lines[-1])


def table(results):
    # one table per dimension: a column per size, and the exponent of the
    # growth of each stage between the last two sizes
    failed = []
    for dim in sorted(set(r['dim'] for r in results)):
        rs = [r for r in results if r['dim'] == dim and 'times' in r]
        for r in results:
            if r['dim'] == dim and 'crash' in r:
                print('%dD, %d cells: CRASH %s\n%s' % (dim, r['cells'],
                      r['crash'], r['stderr']))
                failed.append(r)
        if not rs:
            continue
        print('\n%dD (%s)' % (dim, 'polygons' if dim == 2 else 'polyhedra'))
        head = '%-11s' % 'stage' + ''.join('%12s' % ('%d' % r['cells'])
                                           for r in rs)
        if len(rs) > 1:
            head += '%9s' % 'growth'
        print(head + '%10s' % 'peak MB')
        for s in ['generate'] + STAGES:
            ts = [r['times'].get(s) for r in rs]
            if all(t is None for t in ts):
                continue
            line = '%-11s' % s + ''.join(
                '%12s' % ('-' if t is None else '%.3f' % t) for t in ts)
            if len(rs) > 1 and ts[-1] and ts[-2] and ts[-2] > 1e-3:
                g = math.log(ts[-1] / ts[-2]) / \
                    math.log(rs[-1]['cells'] / rs[-2]['cells'])
                line += '%9.2f%s' % (g, ' !' if g > 1.3 else '  ')
            elif len(rs) > 1:
                line += '%11s' % ''
            m = rs[-1]['memory'].get(s)
            line += '%10s' % ('' if m is None else '%.0f' % m)
            print(line)
        if 'msh MB' in rs[-1]:
            print('%-11s' % 'file MB' + ''.join(
                '%12.1f' % r.get('msh MB', 0) for r in rs))
        for r in rs:
            for name, (v, e, ok) in r['checks'].items():
                if not ok:
                    print('  %dD %d cells: %s = %s, expected %s' %
                          (dim, r['cells'], name, v, e))
                    failed.append(r)
    print('\n%s' % ('all checks passed' if not failed else
                    '%d failed case(s)' % len(failed)))
    return not failed


def compare(f1, f2):
    a, b = json.load(open(f1)), json.load(open(f2))
    key = lambda r: (r['dim'], r['cells'])
    bb = {key(r): r for r in b if 'times' in r}
    print('%-4s%10s%-12s%10s%10s%8s' % ('dim', 'cells', '  stage', f1[-10:],
                                        f2[-10:], 'ratio'))
    for r in a:
        if 'times' not in r or key(r) not in bb:
            continue
        for s, t in r['times'].items():
            u = bb[key(r)]['times'].get(s)
            if u is None or t < 1e-3:
                continue
            print('%-4d%10d  %-10s%10.3f%10.3f%8.2f' % (r['dim'], r['cells'],
                                                       s, t, u, u / t))


def main():
    p = argparse.ArgumentParser()
    p.add_argument('--api', default=os.path.join(HERE, '..', '..', 'api'))
    p.add_argument('--size', default='small', choices=sorted(SIZES))
    p.add_argument('--cells', default=None,
                   help='comma-separated numbers of cells (overrides --size)')
    p.add_argument('--dims', default='2,3')
    p.add_argument('--given', action='store_true')
    p.add_argument('--nt', type=int, default=1)
    p.add_argument('--no-draw', action='store_true')
    p.add_argument('--dump', default=None)
    p.add_argument('--compare', nargs=2, default=None)
    p.add_argument('--child-dim', type=int, default=0)
    p.add_argument('--child-cells', type=int, default=0)
    p.add_argument('stages', nargs='*')
    args = p.parse_args()
    for s in args.stages:
        if s not in STAGES:
            p.error('unknown stage %s (stages: %s)' % (s, ' '.join(STAGES)))
    if args.compare:
        return compare(*args.compare)
    if args.child_dim:
        return child(args)
    args.api = os.path.abspath(args.api)
    sizes = [int(float(n)) for n in args.cells.split(',')] if args.cells \
        else SIZES[args.size]
    results = []
    for dim in [int(d) for d in args.dims.split(',')]:
        for n in sizes:
            print('%dD, %d cells...' % (dim, n), flush=True)
            results.append(run_case(dim, n, args))
    if args.dump:
        json.dump(results, open(args.dump, 'w'), indent=1)
    sys.exit(0 if table(results) else 1)


if __name__ == '__main__':
    main()
