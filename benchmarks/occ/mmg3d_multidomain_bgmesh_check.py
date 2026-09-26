# Regression check for mmg3d_multidomain_bgmesh.geo: the file meshes itself
# (isotropic pass, Delete Meshes, then anisotropic pass against the
# discontinuous background field), so this script only needs to open it and
# verify that every node used by tetrahedra of both volumes is also used by
# a triangle of the interface surface -- see the header comment of the .geo
# file for the full explanation of what "hanging nodes" means here and why
# they used to appear with Mesh.MMG3DCombineDomains = 1.

import os
import sys
import gmsh
import numpy as np

gmsh.initialize()
gmsh.option.setNumber("General.Terminal", 0)

geofile = os.path.join(os.path.dirname(os.path.realpath(__file__)),
                       "mmg3d_multidomain_bgmesh.geo")
gmsh.open(geofile)

vols = [t for _, t in gmsh.model.getEntities(3)]


def used(v):
    ts, _, ns = gmsh.model.mesh.getElements(dim=3, tag=v)
    return {
        int(k)
        for t, n in zip(ts, ns) if gmsh.model.mesh.getElementProperties(t)[3] == 4
        for k in np.asarray(n).reshape(-1)
    }


tri = set()
for _, s in gmsh.model.getEntities(2):
    ts, _, ns = gmsh.model.mesh.getElements(dim=2, tag=s)
    for t, n in zip(ts, ns):
        if gmsh.model.mesh.getElementProperties(t)[3] == 3:
            tri |= {int(k) for k in np.asarray(n).reshape(-1)}

shared = used(vols[0]) & used(vols[1])
hanging = shared - tri

gmsh.finalize()

if hanging:
    print("FAILED: %d hanging node(s) on the interface: %s" %
         (len(hanging), sorted(hanging)))
    sys.exit(1)

print("OK: 0 hanging nodes")
