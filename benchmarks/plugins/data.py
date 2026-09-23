#!/usr/bin/env python3
# Writes the inputs shared by the plugin tests into data/: small meshes of a
# square (triangles, or quadrangles) and of a cube (tetrahedra, or hexahedra),
# with physical groups on their boundary and interior, each with the same views
# as model data (.msh) and as list data (.pos):
#
#   scalar  node data, 3 steps at times 0, 1, 2
#   vector  node data, 3 steps
#   tensor  node data, 1 step
#   cell    element data, 1 step
#
# The files are committed: run this only to change them.

import math
import os
import gmsh

HERE = os.path.dirname(os.path.abspath(__file__))
SQUARE = ((0, 0), (1, 0), (1, 1), (0, 1))


def scalar(x, y, z, s):
    return (1 + s) * (x * x + 2 * y + 0.5 * z) + math.sin(3 * x) * y


def vector(x, y, z, s):
    return [-(y - 0.5) * (1 + s), x - 0.5, 0.2 * z + 0.1 * s]


def tensor(x, y, z):
    return [1 + x, y, z, y, 2 + y, x * z, z, x * z, 3 + z]


def geometry(name):
    lc = 0.2 if name in ('square', 'quads') else 0.5
    if name in ('square', 'quads'):
        g = gmsh.model.geo
        p = [g.addPoint(x, y, 0, lc) for x, y in SQUARE]
        c = [g.addLine(p[i], p[(i + 1) % 4]) for i in range(4)]
        g.addPlaneSurface([g.addCurveLoop(c)])
        g.synchronize()
        gmsh.model.addPhysicalGroup(1, [1], 1, 'bottom')
        gmsh.model.addPhysicalGroup(1, [2, 3, 4], 2, 'rest')
        gmsh.model.addPhysicalGroup(2, [1], 3, 'domain')
        if name == 'quads':
            gmsh.option.setNumber('Mesh.RecombineAll', 1)
        gmsh.model.mesh.generate(2)
    else:
        g = gmsh.model.geo
        p = [g.addPoint(x, y, 0, lc) for x, y in SQUARE]
        c = [g.addLine(p[i], p[(i + 1) % 4]) for i in range(4)]
        g.addPlaneSurface([g.addCurveLoop(c)])
        g.extrude([(2, 1)], 0, 0, 1)
        g.synchronize()
        faces = [s[1] for s in gmsh.model.getEntities(2)]
        gmsh.model.addPhysicalGroup(2, [1], 1, 'bottom')
        gmsh.model.addPhysicalGroup(2, faces[1:], 2, 'rest')
        gmsh.model.addPhysicalGroup(3, [1], 3, 'domain')
        if name == 'hexes':
            for c in gmsh.model.getEntities(1):
                gmsh.model.mesh.setTransfiniteCurve(c[1], 4)
            for s in gmsh.model.getEntities(2):
                gmsh.model.mesh.setTransfiniteSurface(s[1])
                gmsh.model.mesh.setRecombine(2, s[1])
            gmsh.model.mesh.setTransfiniteVolume(1)
        gmsh.model.mesh.generate(3)


def views(name):
    tags, coord, _ = gmsh.model.mesh.getNodes()
    xyz = [coord[3 * i:3 * i + 3] for i in range(len(tags))]
    dim = 2 if name in ('square', 'quads') else 3
    v = gmsh.view.add('scalar')
    for s in range(3):
        gmsh.view.addHomogeneousModelData(
            v, s, name, 'NodeData', tags, [scalar(*p, s) for p in xyz], s)
    v = gmsh.view.add('vector')
    for s in range(3):
        gmsh.view.addHomogeneousModelData(
            v, s, name, 'NodeData', tags,
            [c for p in xyz for c in vector(*p, s)], s, 3)
    v = gmsh.view.add('tensor')
    gmsh.view.addHomogeneousModelData(
        v, 0, name, 'NodeData', tags, [c for p in xyz for c in tensor(*p)],
        0, 9)
    v = gmsh.view.add('cell')
    node = dict(zip(tags, xyz))
    et, vals = [], []
    for ee, nn in zip(*gmsh.model.mesh.getElements(dim)[1:]):
        nn = nn.reshape(len(ee), -1)
        for e, n in zip(ee, nn):
            c = [sum(node[k][i] for k in n) / len(n) for i in range(3)]
            et.append(e)
            vals.append(scalar(*c, 0))
    gmsh.view.addHomogeneousModelData(v, 0, name, 'ElementData', et, vals)


def main():
    os.makedirs(os.path.join(HERE, 'data'), exist_ok=True)
    gmsh.initialize(readConfigFiles=False)
    gmsh.option.setNumber('General.Terminal', 0)
    for name in ('square', 'quads', 'cube', 'hexes'):
        gmsh.clear()
        gmsh.option.setNumber('PostProcessing.SaveMesh', 1)
        gmsh.option.setNumber('Mesh.RecombineAll', 0)
        gmsh.model.add(name)
        geometry(name)
        views(name)
        msh = os.path.join(HERE, 'data', name + '.msh')
        pos = os.path.join(HERE, 'data', name + '.pos')
        gmsh.write(msh)
        gmsh.option.setNumber('PostProcessing.SaveMesh', 0)
        for i, v in enumerate(gmsh.view.getTags()):
            gmsh.view.write(v, msh, True)
            gmsh.view.write(v, pos, i > 0)
    gmsh.finalize()


if __name__ == '__main__':
    main()
