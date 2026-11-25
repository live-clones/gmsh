# A chain of 12 periodic surfaces: 12 boxes along x, the face x = i + 1 of
# each being periodic on its face x = i. The master keys of getPeriodicKeys()
# are at the end of the chain, on the face x = 0, whatever its length: none
# of them is periodic, and each key has a single master key.

import gmsh
import sys

n = 12
gmsh.initialize()
gmsh.option.setNumber("General.Verbosity", 2)
gmsh.model.add("periodic_keys_chain")
for i in range(n):
    gmsh.model.occ.addBox(i, 0, 0, 1, 1, 1)
gmsh.model.occ.fragment([(3, 1)], [(3, i + 1) for i in range(1, n)])
gmsh.model.occ.synchronize()


# the face where x is equal to i
def face(i):
    for d, t in gmsh.model.getEntities(2):
        b = gmsh.model.getBoundingBox(d, t)
        if abs(b[0] - i) < 1e-5 and abs(b[3] - i) < 1e-5:
            return t


translation = [1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1]
for i in range(n):
    gmsh.model.mesh.setPeriodic(2, [face(i + 1)], [face(i)], translation)
gmsh.option.setNumber("Mesh.MeshSizeMax", 0.5)
gmsh.model.mesh.generate(3)
gmsh.model.mesh.createEdges()
gmsh.model.mesh.createFaces()

failed = False
for space in ["Lagrange", "H1Legendre2", "HcurlLegendre1"]:
    master = {}
    for i in range(1, n + 1):
        _, typeKeys, typeKeysMaster, entityKeys, entityKeysMaster, _, \
            coordMaster = gmsh.model.mesh.getPeriodicKeys(2, space, face(i))
        for k, km, x in zip(zip(typeKeys, entityKeys),
                            zip(typeKeysMaster, entityKeysMaster),
                            coordMaster[0::3]):
            if master.setdefault(k, km) != km:
                print("{}: key {} has two master keys".format(
                    space, tuple(map(int, k))))
                failed = True
            if abs(x) > 1e-10:
                print("{}: the master of key {} is not on x = 0".format(
                    space, tuple(map(int, k))))
                failed = True
    if any(km in master for km in master.values()):
        print("{}: master keys are periodic".format(space))
        failed = True

gmsh.finalize()
if failed:
    sys.exit(1)
