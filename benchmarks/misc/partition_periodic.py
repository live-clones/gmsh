# Partitions periodic meshes with Mesh.PartitionPeriodic, and checks that the
# partition entities cut from the periodic entities are periodic, in memory
# and after writing and reading the mesh: each has a master in the same
# partitions, and all its nodes are the images of the nodes of the master
import gmsh
import math
import os
import sys
import tempfile
import numpy as np

def box():
    gmsh.model.occ.addBox(0, 0, 0, 1, 1, 1)
    gmsh.model.occ.synchronize()
    t = lambda dx, dy, dz: [1, 0, 0, dx, 0, 1, 0, dy, 0, 0, 1, dz, 0, 0, 0, 1]
    gmsh.model.mesh.setPeriodic(2, [2], [1], t(1, 0, 0))
    gmsh.model.mesh.setPeriodic(2, [4], [3], t(0, 1, 0))
    gmsh.model.mesh.setPeriodic(2, [6], [5], t(0, 0, 1))
    return 3

def wedge():
    # a sector of a cylinder, periodic by rotation
    a = math.pi / 3
    gmsh.model.occ.addCylinder(0, 0, 0, 0, 0, 1, 1, angle=a)
    gmsh.model.occ.synchronize()
    master = slave = -1
    for dim, tag in gmsh.model.getEntities(2):
        x, y, z = gmsh.model.occ.getCenterOfMass(dim, tag)
        if abs(z - 0.5) > 1e-6: continue
        if abs(y) < 1e-6: master = tag
        if abs(math.atan2(y, x) - a) < 1e-6 and math.hypot(x, y) < 0.6:
            slave = tag
    c, s = math.cos(a), math.sin(a)
    gmsh.model.mesh.setPeriodic(2, [slave], [master],
                                [c, -s, 0, 0, s, c, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1])
    return 3

def square():
    gmsh.model.occ.addRectangle(0, 0, 0, 1, 1)
    gmsh.model.occ.synchronize()
    gmsh.model.mesh.setPeriodic(1, [2], [4],
                                [1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1])
    gmsh.model.mesh.setPeriodic(1, [3], [1],
                                [1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1])
    return 2

def check(what):
    tags, coord, _ = gmsh.model.mesh.getNodes()
    pos = dict(zip(tags, coord.reshape(-1, 3)))
    num = 0
    for dim, tag in gmsh.model.getEntities():
        pdim, ptag = gmsh.model.getParent(dim, tag)
        if ptag < 0: continue
        master, nodes, masterNodes, tfo = gmsh.model.mesh.getPeriodicNodes(
            dim, tag, True)
        if master == tag:
            # all the pieces of a periodic entity of its dimension are periodic
            if pdim == dim and gmsh.model.mesh.getPeriodic(pdim, [ptag])[0] != ptag:
                raise Exception('%s: entity (%d, %d) is not periodic' %
                                (what, dim, tag))
            continue
        num += 1
        if list(gmsh.model.getPartitions(dim, tag)) != \
           list(gmsh.model.getPartitions(dim, master)):
            raise Exception('%s: entity (%d, %d) and its master are not in '
                            'the same partitions' % (what, dim, tag))
        own = set(np.concatenate(gmsh.model.mesh.getElements(dim, tag)[2]).tolist())
        other = set(np.concatenate(gmsh.model.mesh.getElements(dim, master)[2]).tolist())
        if own != set(nodes.tolist()) or other != set(masterNodes.tolist()):
            raise Exception('%s: wrong periodic nodes on entity (%d, %d)' %
                            (what, dim, tag))
        t = np.array(tfo).reshape(4, 4)
        for n, m in zip(nodes, masterNodes):
            if np.linalg.norm((t @ np.append(pos[m], 1))[:3] - pos[n]) > 1e-6:
                raise Exception('%s: node %d is not the image of node %d' %
                                (what, n, m))
    if not num: raise Exception('%s: no periodic partition entities' % what)
    return num

gmsh.initialize()
gmsh.option.setNumber('General.Verbosity', 2)
gmsh.option.setNumber('Mesh.PartitionPeriodic', 1)
tmp = os.path.join(tempfile.mkdtemp(), 'partition_periodic.msh')
for model, size, order, parts, algo in [
        (box, 0.2, 1, 4, 1), (box, 0.1, 1, 16, 2), (box, 0.15, 2, 7, 3),
        (wedge, 0.1, 1, 5, 2), (wedge, 0.15, 2, 12, 1),
        (square, 0.05, 1, 6, 2), (square, 0.05, 2, 3, 1)]:
    gmsh.clear()
    dim = model()
    gmsh.option.setNumber('Mesh.MeshSizeMax', size)
    gmsh.option.setNumber('Mesh.MetisAlgorithm', algo)
    gmsh.model.mesh.generate(dim)
    gmsh.model.mesh.setOrder(order)
    gmsh.model.mesh.partition(parts)
    what = '%s, order %d, %d partitions' % (model.__name__, order, parts)
    num = check(what)
    for binary in [0, 1]:
        gmsh.option.setNumber('Mesh.Binary', binary)
        gmsh.write(tmp)
        gmsh.open(tmp)
        if check(what + ' (file)') != num:
            raise Exception('%s: periodic entities lost in the file' % what)
    print('%s: %d periodic partition entities' % (what, num))
os.remove(tmp)
gmsh.finalize()
