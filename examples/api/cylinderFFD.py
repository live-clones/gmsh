# This demo implements free form deformation in cylindrical coordinates

# Contributed by Ekrem Ekici

from math import pi, cos, sin, comb
import gmsh
import os
import sys
import numpy as np

def cart2cyl(x, y, z):
    # cartesian to cylindrical
    rho = np.sqrt(x**2 + y**2)
    phi = np.arctan2(y, x)
    zeta = z
    return rho, phi, zeta

def cyl2cart(rho, phi, zeta):
    # cylindrical to Cartesian
    x = rho * np.cos(phi)
    y = rho * np.sin(phi)
    z = zeta
    return x, y, z

gmsh.initialize()
gmsh.option.setNumber("General.Terminal", 0)
gmsh.model.add("original_model")

R = 0.1
L_total = 0.4

gmsh.model.occ.addCylinder(0, 0, 0, 0, 0, L_total, R, tag=1)
gmsh.model.occ.synchronize()

lc = 0.1 #0.005

gmsh.option.setNumber("Mesh.MeshSizeMax", lc)
gmsh.option.setNumber("Mesh.SaveAll", 0)

gmsh.model.mesh.generate(3)

# get mesh data
mesh_data = {}
for e in gmsh.model.getEntities():
    mesh_data[e] = (gmsh.model.getBoundary([e]),
            gmsh.model.mesh.getNodes(e[0], e[1]),
            gmsh.model.mesh.getElements(e[0], e[1]))

gmsh.write("cylinder.msh")

### Introducing FFD

l = 2 # number of control points in the x axis
m = 4 # number of control points in the y axis
n = 5 # number of control points in the z axis
Pr = np.zeros((l,m,n))
Pphi = np.zeros((l,m,n))
Pz = np.zeros((l,m,n))

nodes, coords, param = gmsh.model.mesh.getNodes(3, -1, True, True)
xs = coords[0::3]
ys = coords[1::3]
zs = coords[2::3]

rhos, phis, zetas = cart2cyl(xs, ys, zs)

dr = max(rhos)-min(rhos)
dphi = 2*np.pi
dz = max(zetas)-min(zetas)

for i in range(l):
    for j in range(m):
        for k in range(n):
            Pr[i, j, k] = min(rhos)  + dr * i / (l - 1)
            Pphi[i, j, k] = min(phis)  + dphi * j / (m -1)
            Pz[i, j, k] = min(zetas)  + dz * k / (n -1)

P0 = np.array([Pr[0, 0, 0], Pphi[0, 0, 0], Pz[0, 0, 0]])

# Moving control points
for i in range(m):
    Pr[1, i, 2] += 0.02 # change the radius of the 3rd points in the z direction
    Pr[1, i, 4] -= 0.02
    Pz[1, i, 0] += 0.05 # change the z of the 1st points in the z direction

# parametrize mesh nodes
def calcSTU(coords, P0, dr, dphi, dz):
    """
    Calc STU coordinates
    """
    xs = coords[0::3]
    ys = coords[1::3]
    zs = coords[2::3]

    rhos, phis, zetas = cart2cyl(xs, ys, zs)

    s = (rhos - P0[0])/dr
    t = (phis - P0[1])/dphi
    u = (zetas - P0[2])/dz

    return s,t,u

gmsh.model.add('deformed_model')

# deform the mesh using control points
for e in mesh_data:
    if len(mesh_data[e][1][1])==3:
        old_coord = mesh_data[e][1][1]

        s,t,u = calcSTU(old_coord,P0, dr, dphi, dz)
        Xdef = np.zeros(3)
        for i in range(l):
            for j in range(m):
                for k in range(n):
                    Xdef += comb(l-1,i)*np.power(1-s, l-1-i)*np.power(s,i) * \
                            comb(m-1,j)*np.power(1-t, m-1-j)*np.power(t,j) * \
                            comb(n-1,k)*np.power(1-u, n-1-k)*np.power(u,k) * \
                            np.asarray([Pr[i,j,k], Pphi[i,j,k], Pz[i,j,k]])
        Xdef_3d_cart = Xdef.copy()
        Xdef_3d_cart[0], Xdef_3d_cart[1],Xdef_3d_cart[2] = cyl2cart(Xdef[0], Xdef[1], Xdef[2])
        new_coord = Xdef_3d_cart.flatten()

    else:
        old_coords = mesh_data[e][1][1]
        s,t,u = calcSTU(old_coords,P0, dr, dphi, dz)
        Xdef = np.zeros((int(len(old_coords)/3),3))
        for point, param_s in enumerate(s):
            for i in range(l):
                for j in range(m):
                    for k in range(n):
                        Xdef[point] +=  comb(l-1,i)*np.power(1-s[point], l-1-i)*np.power(s[point],i) * \
                                        comb(m-1,j)*np.power(1-t[point], m-1-j)*np.power(t[point],j) * \
                                        comb(n-1,k)*np.power(1-u[point], n-1-k)*np.power(u[point],k) * \
                                        np.asarray([Pr[i,j,k], Pphi[i,j,k], Pz[i,j,k]])


        Xdef_3d_cart = Xdef.copy()
        Xdef_3d_cart[:,0], Xdef_3d_cart[:,1],Xdef_3d_cart[:,2] = cyl2cart(Xdef[:,0], Xdef[:,1], Xdef[:,2])

        new_coord = Xdef_3d_cart.flatten()

    gmsh.model.addDiscreteEntity(e[0], e[1], [b[1] for b in mesh_data[e][0]])
    gmsh.model.mesh.addNodes(e[0], e[1], mesh_data[e][1][0], new_coord)
    gmsh.model.mesh.addElements(e[0], e[1], mesh_data[e][2][0], mesh_data[e][2][1], mesh_data[e][2][2])

if '-nopopup' not in sys.argv:
    gmsh.fltk.run()

gmsh.write("cylinder_deformed.msh")
gmsh.finalize()
