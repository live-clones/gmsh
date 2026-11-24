# This example shows how to use hierarchical basis functions on a periodic
# mesh: the keys of the basis functions on a periodic (slave) surface are mapped
# to the keys of the master surface with `getPeriodicKeys()', and, the elements
# being oriented with the tags of the master nodes (the default of
# `getBasisFunctionsOrientationForElement()'), each basis function on the slave
# surface is the basis function of its master key on the master surface. This
# is checked on a cube periodic in x and y, meshed with tetrahedra, for H1,
# H(curl) and H(div) basis functions.
#
# The master keys are at the end of the chains of periodic entities: e.g. the
# master keys of the edges along the corner x = 1, y = 1 are those of the edges
# along x = 0, y = 0, and not those along x = 0, y = 1 (which are on the master
# surface of x, but are periodic in y). The master keys are thus never periodic
# themselves, and a key is the image of its master key by a composition of
# periodic transformations (here a sum of distinct translations).

import gmsh
import itertools
import sys
import numpy as np

gmsh.initialize()
gmsh.option.setNumber("General.Verbosity", 2)
gmsh.model.add("periodic_keys")
gmsh.model.occ.addBox(0, 0, 0, 1, 1, 1)
gmsh.model.occ.synchronize()


# the face of the box where coordinate c is equal to x
def face(c, x):
    for d, t in gmsh.model.getEntities(2):
        b = gmsh.model.getBoundingBox(d, t)
        if abs(b[c] - x) < 1e-5 and abs(b[c + 3] - x) < 1e-5:
            return t


# the faces x = 1 and y = 1 are the images of the faces x = 0 and y = 0 by a
# translation
slaves = []
for c in range(2):
    translation = [1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1]
    translation[4 * c + 3] = 1
    gmsh.model.mesh.setPeriodic(2, [face(c, 1)], [face(c, 0)], translation)
    slaves.append((face(c, 1), np.eye(3)[c]))

gmsh.option.setNumber("Mesh.MeshSizeMax", 0.4)
gmsh.model.mesh.generate(3)

# renumber the nodes randomly, as for a mesh read from a file or reordered: in
# the mesh as generated, the nodes of a slave surface are numbered in the order
# of those of the master surface, which would hide a wrong orientation
tags, _, _ = gmsh.model.mesh.getNodes()
new = np.random.default_rng(7).permutation(len(tags)) + 1
gmsh.model.mesh.renumberNodes(tags, new)
gmsh.model.mesh.createEdges()
gmsh.model.mesh.createFaces()

volumeType = 4  # tetrahedra
faceType = 2  # triangles
faceSize = 3

# the 3D element containing each face, by its nodes
volumes, volumeNodes = gmsh.model.mesh.getElementsByType(volumeType)
faceNodes, _ = gmsh.model.mesh.getElementFaceNodes(volumeType, primary=True)
faceNodes = np.array(faceNodes).reshape(len(volumes), -1, faceSize)
volumeOfFace = {}
for v, faces in zip(volumes, faceNodes):
    for f in faces:
        volumeOfFace[frozenset(f)] = v


# the traces of the basis functions of the 3D element at the points xyz, by
# key: values for H1, tangential components for H(curl), normal component for
# H(div); the elements are oriented with the tags of the master nodes
def traces(element, xyz, space, kind, t1, t2):
    uvw = []
    for x in xyz:
        uvw.extend(gmsh.model.mesh.getLocalCoordinatesInElement(element, *x))
    o = gmsh.model.mesh.getBasisFunctionsOrientationForElement(element, space)
    nc, bf, _ = gmsh.model.mesh.getBasisFunctions(volumeType, uvw, space, [o])
    jac, det, _ = gmsh.model.mesh.getJacobian(element, uvw)
    typeKeys, entityKeys, _ = gmsh.model.mesh.getKeysForElement(element, space,
                                                               returnCoord=False)
    bf = np.array(bf).reshape(len(xyz), len(typeKeys), nc)
    n = np.cross(t1, t2)
    result = {}
    for f in range(len(typeKeys)):
        values = []
        for q in range(len(xyz)):
            J = np.array(jac[9 * q:9 * q + 9]).reshape(3, 3)  # dx_j / du_i
            if kind == "H1":
                values.append(bf[q, f, 0])
            elif kind == "Hcurl":  # covariant Piola map
                v = np.linalg.solve(J, bf[q, f])
                values.extend([v @ t1, v @ t2])
            else:  # contravariant Piola map
                v = J.T @ bf[q, f] / det[q]
                values.append(v @ n)
        result[(typeKeys[f], entityKeys[f])] = np.array(values)
    return result


# the translations composing the periodic transformations: the sums of the
# shifts of distinct directions
shifts = [np.sum(s, axis=0) for n in range(1, len(slaves) + 1)
          for s in itertools.combinations([s for _, s in slaves], n)]

rng = np.random.default_rng(1)
failed = False
for kind, space in [("H1", "H1Legendre3"), ("Hcurl", "HcurlLegendre2"),
                    ("Hdiv", "HdivLegendre2")]:
    # the master key of the keys of all the slave surfaces, and the keys of
    # each slave surface
    master, slaveKeys = {}, {}
    for slave, shift in slaves:
        tagMaster, typeKeys, typeKeysMaster, entityKeys, entityKeysMaster, \
            coord, coordMaster = gmsh.model.mesh.getPeriodicKeys(faceType,
                                                                 space, slave)
        slaveKeys[slave] = set(zip(typeKeys, entityKeys))
        d = np.reshape(coord, (-1, 3)) - np.reshape(coordMaster, (-1, 3))
        for k, km, dk in zip(zip(typeKeys, entityKeys),
                             zip(typeKeysMaster, entityKeysMaster), d):
            if master.setdefault(k, km) != km:
                print("{}: key {} has two master keys".format(space, k))
                failed = True
            if min(np.abs(dk - s).max() for s in shifts) > 1e-10:
                print("{}: key {} is not the image of its master key by a "
                      "periodic transformation".format(space, k))
                failed = True
    if any(km in master for km in master.values()):
        print("{}: master keys are periodic".format(space))
        failed = True

    worst = 0.
    for slave, shift in slaves:
        elements, nodes = gmsh.model.mesh.getElementsByType(faceType, slave)
        nodes = np.array(nodes).reshape(-1, faceSize)
        for nn in nodes:
            x = [gmsh.model.mesh.getNode(n)[0] for n in nn]
            t1, t2 = x[1] - x[0], x[-1] - x[0]
            xyz = [x[0] + a * t1 + b * t2 for a, b in rng.uniform(0.1, 0.4, (3, 2))]
            # the 3D elements on both sides, and their traces
            vs = volumeOfFace[frozenset(nn)]
            ts = traces(vs, xyz, space, kind, t1, t2)
            # the master element: the 3D element containing the image of the
            # face on the master surface
            centre = np.mean(x, axis=0) - shift
            inner = centre + 1e-3 * (np.array([0.5, 0.5, 0.5]) - centre)
            vm = gmsh.model.mesh.getElementByCoordinates(*inner, dim=3)[0]
            tm = traces(vm, [p - shift for p in xyz], space, kind, t1, t2)
            # the functions of the master element by master key (their own key
            # if they are not periodic)
            tmByMaster = {}
            for key, v in tm.items():
                tmByMaster.setdefault(master.get(key, key), []).append(v)
            scale = max(np.abs(v).max() for v in ts.values())
            for key, v in ts.items():
                if key in slaveKeys[slave]:
                    worst = max(worst, min(np.abs(v - w).max() / scale for w in
                                           tmByMaster.get(master[key], [np.inf])))
    print("{}: the basis functions on the slave surfaces differ from those of "
          "their master keys by {:.1e}".format(space, worst))
    failed = failed or worst > 1e-10

gmsh.finalize()
if failed:
    sys.exit(1)
