# Writes views to .msh files and reads them back: every element of a
# list-based view must come back with the same nodes and values, in MSH 2.2
# and 4.1, ASCII and binary. Run from the root of the source tree with
#   PYTHONPATH=api python3 benchmarks/io_msh_views/roundtrip.py
import os
import sys
import tempfile
import numpy as np
import gmsh

HERE = os.path.dirname(os.path.abspath(__file__))
DATA = os.path.join(HERE, '..', 'plugins', 'data')
NC = {'S': 1, 'V': 3, 'T': 9}
OUT = tempfile.mkdtemp()


def start():
    gmsh.initialize(readConfigFiles=False)
    gmsh.option.setNumber('General.Terminal', 0)


def key(xyz):
    return (len(xyz), ) + tuple(np.round(xyz.mean(axis=0), 9))


# the elements of a list-based view: nodes and values at each step
def listElements(v):
    out = {}
    types, nums, data = gmsh.view.getListData(v)
    steps = int(gmsh.view.option.getNumber(v, 'NbTimeStep'))
    for t, n, d in zip(types, nums, data):
        if not n:
            continue
        nc = NC[t[0]]
        d = d.reshape(n, -1)
        nn = d.shape[1] // (3 + steps * nc)
        for e in d:
            xyz = np.array([e[0:nn], e[nn:2 * nn], e[2 * nn:3 * nn]]).T
            vals = e[3 * nn:].reshape(steps, nn, nc)
            out.setdefault(key(xyz), []).append((nc, vals))
    return out


# the elements of the model-based views read from a file
def modelElements():
    out = {}
    for v in gmsh.view.getTags():
        steps = int(gmsh.view.option.getNumber(v, 'NbTimeStep'))
        per = {}
        for s in range(steps):
            _, tags, data, _, nc = gmsh.view.getModelData(v, s)
            for t, d in zip(tags, data):
                per.setdefault(t, []).append((nc, d))
        for t, st in per.items():
            _, nodes, _, _ = gmsh.model.mesh.getElement(t)
            xyz = np.array([gmsh.model.mesh.getNode(n)[0] for n in nodes])
            nc = st[0][0]
            vals = np.array([d for _, d in st]).reshape(len(st), len(nodes), nc)
            out.setdefault(key(xyz), []).append((nc, vals))
    return out


def compare(a, b):
    if a.keys() != b.keys():
        return 'elements differ (%d vs %d)' % (len(a), len(b))
    for k in a:
        la = sorted(a[k], key=lambda x: (x[0], x[1].round(12).tobytes()))
        lb = sorted(b[k], key=lambda x: (x[0], x[1].round(12).tobytes()))
        if len(la) != len(lb):
            return 'number of elements at %s' % (k, )
        for (na, va), (nb, vb) in zip(la, lb):
            if na != nb or va.shape != vb.shape or np.abs(va - vb).max() > 1e-10:
                return 'values at %s' % (k, )
    return None


def load(case):
    if case == 'mixed':  # scalar and vector elements in one view
        v = gmsh.view.add('mixed')
        gmsh.view.addListData(v, 'SS', 1,
                              [0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 2, 3, 4])
        gmsh.view.addListData(v, 'VT', 1, [1, 2, 1, 0, 0, 1, 0, 0, 0] +
                              [1, 1, 1, 2, 2, 2, 3, 3, 3])
        return [v]
    before = set(gmsh.view.getTags())
    gmsh.merge(os.path.join(DATA, case))
    return [v for v in gmsh.view.getTags() if v not in before]


failed = 0


def check(name, err):
    global failed
    print('%-44s %s' % (name, err or 'ok'))
    failed += bool(err)


# list-based views of all the element types, high order, several steps
for case in ('cube.pos', 'hexes.pos', 'square.pos', 'quads.pos', 'order2.pos',
             'mixed'):
    start()
    n = len(load(case))
    gmsh.finalize()
    for i in range(n):
        for version, binary in ((2.2, 0), (4.1, 0), (4.1, 1)):
            start()
            v = load(case)[i]
            name = gmsh.view.option.getString(v, 'Name')
            ref = listElements(v)
            gmsh.option.setNumber('Mesh.MshFileVersion', version)
            gmsh.option.setNumber('Mesh.Binary', binary)
            f = os.path.join(OUT, 'out.msh')
            gmsh.view.write(v, f)
            # writing leaves the numbering of the current model alone
            err = None
            if gmsh.model.mesh.getMaxNodeTag():
                err = 'current model numbering changed'
            gmsh.clear()
            gmsh.merge(f)
            err = err or compare(ref, modelElements())
            gmsh.finalize()
            check('%s %s MSH %g %s' % (case, name, version,
                                        'binary' if binary else 'ASCII'), err)


# nodes merged within the geometrical tolerance, and forced data types
def triangles(d, force=None):
    start()
    v = gmsh.view.add('t')
    gmsh.view.addListData(v, 'ST', 2, [0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 2, 3] +
                          [1, d, 1, 0, 0, 1 + d, 0, 0, 0, 4, 5, 6])
    if force:
        gmsh.option.setNumber('PostProcessing.' + force, 1)
    f = os.path.join(OUT, 'tri.msh')
    gmsh.view.write(v, f)
    gmsh.clear()
    gmsh.merge(f)
    n = len(gmsh.model.mesh.getNodes()[0])
    typ, tags, data, _, _ = gmsh.view.getModelData(gmsh.view.getTags()[0], 0)
    gmsh.finalize()
    return n, typ, [list(x) for x in data]


check('nodes equal', None if triangles(0.)[0] == 4 else 'not merged')
check('nodes closer than the tolerance',
      None if triangles(1e-12)[0] == 4 else 'not merged')
check('nodes farther than the tolerance',
      None if triangles(1e-3)[0] == 5 else 'merged')
check('ForceNodeData (the last element at a node)',
      None if triangles(0., 'ForceNodeData')[1:] ==
      ('NodeData', [[5.], [4.], [3.], [6.]]) else 'wrong values')
check('ForceElementData (the first node)',
      None if triangles(0., 'ForceElementData')[1:] ==
      ('ElementData', [[1.], [4.]]) else 'wrong values')

print('%d failed' % failed)
sys.exit(1 if failed else 0)
