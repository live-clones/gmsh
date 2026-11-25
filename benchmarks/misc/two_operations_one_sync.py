# Several operations on a kernel between two synchronizations give the same
# model (entities and physical groups) as the same operations each followed by
# a synchronization, for the three kernels.

import gmsh
import sys


def model(build, everyStep):
    gmsh.clear()
    sync = build(everyStep)
    sync()
    return ([sorted(gmsh.model.getEntities(d)) for d in range(4)],
            sorted((d, t, tuple(sorted(gmsh.model.getEntitiesForPhysicalGroup(d, t))))
                   for d, t in gmsh.model.getPhysicalGroups()))


def geo(everyStep):
    g = gmsh.model.geo
    sync = g.synchronize
    p = [g.addPoint(x, y, 0) for x, y in [(0, 0), (1, 0), (1, 1), (0, 1)]]
    l = [g.addLine(p[i], p[(i + 1) % 4]) for i in range(4)]
    s = g.addPlaneSurface([g.addCurveLoop(l)])
    if everyStep: sync()
    gmsh.model.addPhysicalGroup(2, [s], 10)
    g.translate([(2, s)], 2, 0, 0)
    if everyStep: sync()
    g.extrude([(2, s)], 0, 0, 1)
    if everyStep: sync()
    c = g.copy([(2, s)])
    g.rotate(c, 0, 0, 0, 0, 0, 1, 1)
    return sync


def occ(everyStep):
    o = gmsh.model.occ
    sync = o.synchronize
    b = o.addBox(0, 0, 0, 1, 1, 1)
    o.addBox(2, 0, 0, 1, 1, 1)
    sync()
    gmsh.model.addPhysicalGroup(3, [b], 20)
    gmsh.model.addPhysicalGroup(2, [1, 2], 21)
    o.translate([(3, b)], 0.5, 0.5, 0)
    if everyStep: sync()
    o.fillet([b], [1], [0.1])
    if everyStep: sync()
    o.healShapes()
    return sync


def discrete(everyStep):
    d = gmsh.model.discrete
    sync = d.synchronize
    b = d.addBox(0, 0, 0, 1, 1, 1)
    s = d.addSphere(1, 1, 1, 0.5)
    c = d.addCylinder(3, 0, 0, 0, 0, 1, 0.3)
    if everyStep: sync()
    d.cut([(3, b)], [(3, s)])
    if everyStep: sync()
    d.remove([(3, c)], True)
    return sync


gmsh.initialize(sys.argv)
gmsh.option.setNumber('General.Terminal', 0)
fails = 0
for name, build in [('geo', geo), ('occ', occ), ('discrete', discrete)]:
    a = model(build, True)
    b = model(build, False)
    if a != b:
        print('%s: one synchronization at the end gives another model' % name)
        print('  every step:', [len(x) for x in a[0]], a[1])
        print('  at the end:', [len(x) for x in b[0]], b[1])
        fails += 1
gmsh.finalize()
if fails:
    raise SystemExit(1)
