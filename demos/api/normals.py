import gmsh
import sys

gmsh.initialize(sys.argv)
gmsh.model.add("normals")
gmsh.model.occ.addSphere(0, 0, 0, 1)
gmsh.model.occ.addBox(2, 0, 0, 1, 1, 1)
gmsh.model.occ.synchronize()
gmsh.model.mesh.generate(2)

vp = []

# get all surfaces
ent = gmsh.model.getEntities(2)

for e in ent:
    surf = e[1]
    # get nodes on surf, including those on the boundary (contrary to internal
    # nodes, which store their parametric coordinates, boundary nodes will be
    # reparametrized on surf in order to compute their parametric coordinates -
    # which will be different when reparametrized on another adjacent surface)
    tags, coord, param = gmsh.model.mesh.getNodes(2, surf, True)
    normals = gmsh.model.getNormals(surf, param)
    for i in range(0,len(coord),3):
        vp.append(coord[i])
        vp.append(coord[i+1])
        vp.append(coord[i+2])
        vp.append(normals[i])
        vp.append(normals[i+1])
        vp.append(normals[i+2])

t = gmsh.view.add("normals")
gmsh.view.addListData(t, "VP", len(vp)/6, vp)
gmsh.view.write(t, "normals.pos")

gmsh.finalize()
