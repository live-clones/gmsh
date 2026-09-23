# Reads crafted and legacy view files: blocks of the same name that cannot go
# in the same view, legacy .pos files (ASCII and binary, truncated, long
# names). Run from the root of the source tree with
#   PYTHONPATH=api python3 benchmarks/io_msh_views/readers.py
import os
import sys
import tempfile
import gmsh

OUT = tempfile.mkdtemp()
failed = 0


def check(name, err):
    global failed
    print('%-52s %s' % (name, err or 'ok'))
    failed += bool(err)


def start():
    gmsh.initialize(readConfigFiles=False)
    gmsh.option.setNumber('General.Terminal', 0)


def views():
    out = []
    for v in gmsh.view.getTags():
        for s in range(int(gmsh.view.option.getNumber(v, 'NbTimeStep'))):
            t, tags, d, _, nc = gmsh.view.getModelData(v, s)
            out.append((s, t, nc, {int(k): [float(y) for y in x]
                                  for k, x in zip(tags, d)}))
    return out


# blocks named "u": node data with 1 component (partition 1), with 3
# components at the same step (partition 2), and element data
MESH = '''$MeshFormat
2.2 0 8
$EndMeshFormat
$Nodes
4
1 0 0 0
2 1 0 0
3 1 1 0
4 0 1 0
$EndNodes
$Elements
2
1 2 2 0 1 1 2 3
2 2 2 0 1 1 3 4
$EndElements
'''


def block(kind, step, nc, part, rows):
    return '$%s\n1\n"u"\n1\n0\n4\n%d\n%d\n%d\n%d\n%s\n$End%s\n' % (
        kind, step, nc, len(rows), part, '\n'.join(rows), kind)


f = os.path.join(OUT, 'blocks.msh')
open(f, 'w').write(MESH + block('NodeData', 0, 1, 1, ['1 1', '2 2']) +
                   block('NodeData', 0, 3, 2, ['3 1 2 3', '4 4 5 6']) +
                   block('ElementData', 1, 1, 1, ['1 7', '2 8']) +
                   block('NodeData', 1, 1, 1, ['1 9', '2 9']))
start()
gmsh.merge(f)
got = views()
gmsh.finalize()
want = [(0, 'NodeData', 1, {1: [1.], 2: [2.]}),
        (1, 'NodeData', 1, {1: [9.], 2: [9.]}),
        (0, 'NodeData', 3, {3: [1., 2., 3.], 4: [4., 5., 6.]}),
        (0, 'ElementData', 1, {}), (1, 'ElementData', 1, {1: [7.], 2: [8.]})]
check('MSH blocks of one name in compatible views',
      None if sorted(map(str, got)) == sorted(map(str, want)) else str(got))


# legacy .pos files, written by Gmsh, read back
def legacy(fmt):
    start()
    v = gmsh.view.add('a legacy view')
    gmsh.view.addListData(v, 'ST', 2, [0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 2, 3, 4, 5, 6] +
                          [1, 1, 0, 0, 1, 1, 0, 0, 0, 7, 8, 9, 10, 11, 12])
    gmsh.view.addListData(v, 'VL', 1, [0, 1, 0, 0, 0, 0] + list(range(12)))
    ref = gmsh.view.getListData(v)
    f = os.path.join(OUT, 'legacy_%d.pos' % fmt)
    g = os.path.join(OUT, 'save.geo')
    open(g, 'w').write('PostProcessing.Format = %d;\nSave View[0] "%s";\n' %
                       (fmt, f))
    gmsh.merge(g)
    gmsh.view.remove(v)
    gmsh.merge(f)
    v = gmsh.view.getTags()[0]
    got = gmsh.view.getListData(v)
    name = gmsh.view.option.getString(v, 'Name')
    gmsh.finalize()
    same = (list(ref[0]) == list(got[0]) and list(ref[1]) == list(got[1]) and
            all((a == b).all() for a, b in zip(ref[2], got[2])))
    return f, (None if same and name == 'a legacy view' else
               'differs (%s)' % name)


f, err = legacy(2)
check('parsed .pos read back', err)
for fmt, name in ((0, 'ASCII'), (1, 'binary')):
    f, err = legacy(fmt)
    check('legacy %s .pos read back' % name, err)
    # the same file cut in the middle of its data: an error, no view
    data = open(f, 'rb').read()
    cut = os.path.join(OUT, 'cut.pos')
    open(cut, 'wb').write(data[:len(data) // 2])
    start()
    try:
        gmsh.merge(cut)
        err = 'read without error'
    except Exception:
        err = None if not len(gmsh.view.getTags()) else 'view created'
    gmsh.finalize()
    check('truncated legacy %s .pos refused' % name, err)

# a name longer than the 255 characters read
f = os.path.join(OUT, 'long.pos')
open(f, 'w').write('$PostFormat\n1.3 0 8\n$EndPostFormat\n$View\n' + 'n' * 1000 +
                   ' 1' + ' 0' * 28 + '\n0\n$EndView\n')
start()
try:
    gmsh.merge(f)
    err = None
except Exception:
    err = None  # an error, not a crash, is fine
gmsh.finalize()
check('legacy .pos with a 1000-character name', err)

# a view with several steps written in MED and read back, twice: the second
# read (the same file) makes a view of its own
start()
med = 'Med' in gmsh.option.getString('General.BuildOptions')
gmsh.finalize()
if med:
    start()
    gmsh.merge(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..',
                            'plugins', 'data', 'square.msh'))
    v = gmsh.view.getTags()[0]
    ref = [list(x) for x in gmsh.view.getModelData(v, 2)[2]]
    f = os.path.join(OUT, 'steps.med')
    gmsh.view.write(v, f)
    gmsh.finalize()
    start()
    gmsh.merge(f)
    gmsh.merge(f)
    tags = gmsh.view.getTags()
    got = [list(x) for x in gmsh.view.getModelData(tags[0], 2)[2]]
    gmsh.finalize()
    check('MED with 3 steps read back, twice',
          None if len(tags) == 2 and got == ref else 'differs')

    # steps on different nodes: the others are skipped
    start()
    gmsh.merge(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..',
                            'plugins', 'data', 'square.msh'))
    tags = list(gmsh.model.mesh.getNodes()[0])
    v = gmsh.view.add('split')
    h = len(tags) // 2
    gmsh.view.addHomogeneousModelData(v, 0, '', 'NodeData', tags[:h], [1.] * h)
    gmsh.view.addHomogeneousModelData(v, 1, '', 'NodeData', tags[h:2 * h],
                                      [2.] * h)
    try:
        gmsh.view.write(v, os.path.join(OUT, 'split.med'))
        err = None
    except Exception as e:
        err = str(e)
    gmsh.finalize()
    check('MED with steps on different nodes', err)

    # the mesh and its views saved together (Mesh.SaveViews), the values
    # compared at the positions of the nodes
    def fields():
        tags, xyz, _ = gmsh.model.mesh.getNodes()
        pos = {int(t): tuple(round(c, 9) for c in xyz[3 * i:3 * i + 3])
               for i, t in enumerate(tags)}
        out = {}
        for v in gmsh.view.getTags():
            name = gmsh.view.option.getString(v, 'Name')
            for s in range(int(gmsh.view.option.getNumber(v, 'NbTimeStep'))):
                t, tg, d, _, _ = gmsh.view.getModelData(v, s)
                if t == 'NodeData':
                    out[(name, s)] = sorted(
                        (pos[int(k)], tuple(round(x, 12) for x in dd))
                        for k, dd in zip(tg, d))
        return out

    start()
    gmsh.merge(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..',
                            'plugins', 'data', 'square.msh'))
    ref = fields()
    gmsh.option.setNumber('Mesh.SaveViews', 2)
    f = os.path.join(OUT, 'all.med')
    gmsh.write(f)
    gmsh.finalize()
    start()
    gmsh.merge(f)
    got = fields()
    gmsh.finalize()
    check('MED mesh with its views (%d steps)' % len(ref),
          None if got == ref else 'differs')

# a CGNS field with the name of a list-based view (a file of the untracked
# benchmarks/cgns/new)
f = os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', 'cgns',
                 'new', 'yf17.cgns')
if os.path.exists(f):
    start()
    v = gmsh.view.add('FlowSolution_Density')
    gmsh.view.addListData(v, 'SP', 1, [0, 0, 0, 1])
    gmsh.merge(f)
    names = [gmsh.view.option.getString(t, 'Name') for t in gmsh.view.getTags()]
    gmsh.finalize()
    check('CGNS field named as a list-based view',
          None if names.count('FlowSolution_Density') == 2 else str(names))

print('%d failed' % failed)
sys.exit(1 if failed else 0)
