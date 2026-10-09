# This example shows how to use hierarchical basis functions on a periodic
# mesh: the keys of the basis functions on a periodic (slave) surface are mapped
# to the keys of the master surface with `getPeriodicKeys()', and, the elements
# being oriented with the tags of the master nodes (the default of
# `getBasisFunctionsOrientationForElement()'), each basis function on the slave
# surface is the basis function of its master key on the master surface. This
# is checked on a cube periodic in x and y, meshed with tetrahedra, for H1,
# H(curl) and H(div) basis functions.

import gmsh
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


rng = np.random.default_rng(1)
failed = False
for kind, space in [("H1", "H1Legendre3"), ("Hcurl", "HcurlLegendre2"),
                    ("Hdiv", "HdivLegendre2")]:
    worst = 0.
    for slave, shift in slaves:
        # the keys of the basis functions on the slave surface, and their
        # master keys
        tagMaster, typeKeys, typeKeysMaster, entityKeys, entityKeysMaster, _, \
            _ = gmsh.model.mesh.getPeriodicKeys(faceType, space, slave,
                                                returnCoord=False)
        master = dict(zip(zip(typeKeys, entityKeys),
                          zip(typeKeysMaster, entityKeysMaster)))
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
            scale = max(np.abs(v).max() for v in ts.values())
            for key, v in ts.items():
                if key in master:
                    worst = max(worst, np.abs(v - tm[master[key]]).max() / scale)
    print("{}: the basis functions on the slave surfaces differ from those of "
          "their master keys by {:.1e}".format(space, worst))
    failed = failed or worst > 1e-10

gmsh.finalize()
if failed:
    sys.exit(1)
