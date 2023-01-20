# See the corresponding Python tutorial for detailed comments.

import gmsh


gmsh.initialize()

gmsh.model.add("t18")

gmsh.model.occ.addBox(0, 0, 0, 1, 1, 1, 1)
gmsh.model.occ.synchronize()

gmsh.model.mesh.setSize(gmsh.model.getEntities(0), 0.1)
gmsh.model.mesh.setSize([(0, 1)], 0.02)

translation = [1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1]
gmsh.model.mesh.setPeriodic(2, [2], [1], translation)

gmsh.model.mesh.setPeriodic(2, [6], [5],
                            [1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1])
gmsh.model.mesh.setPeriodic(2, [4], [3],
                            [1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1])

gmsh.model.occ.addBox(2, 0, 0, 1, 1, 1, 10)

x = 2 - 0.3
y = 0
z = 0

gmsh.model.occ.addSphere(x, y, z, 0.35, 11)
gmsh.model.occ.addSphere(x + 1, y, z, 0.35, 12)
gmsh.model.occ.addSphere(x, y + 1, z, 0.35, 13)
gmsh.model.occ.addSphere(x, y, z + 1, 0.35, 14)
gmsh.model.occ.addSphere(x + 1, y + 1, z, 0.35, 15)
gmsh.model.occ.addSphere(x, y + 1, z + 1, 0.35, 16)
gmsh.model.occ.addSphere(x + 1, y, z + 1, 0.35, 17)
gmsh.model.occ.addSphere(x + 1, y + 1, z + 1, 0.35, 18)

out, _ = gmsh.model.occ.fragment([(3, 10)], [(3, i) for i in 11:18])
gmsh.model.occ.synchronize()

gmsh.option.setNumber("Geometry.OCCBoundsUseStl", 1)

eps = 1e-3
vin = gmsh.model.getEntitiesInBoundingBox(2 - eps, -eps, -eps, 2 + 1 + eps,
                                          1 + eps, 1 + eps, 3)
for v in vin
    deleteat!(out, findall(x->x==v,out))
end
gmsh.model.removeEntities(out, true) 

p = gmsh.model.getBoundary(vin, false, false, true)  
gmsh.model.mesh.setSize(p, 0.1)
p = gmsh.model.getEntitiesInBoundingBox(2 - eps, -eps, -eps, 2 + eps, eps, eps,
                                        0)

gmsh.model.mesh.setSize(p, 0.001)

sxmin = gmsh.model.getEntitiesInBoundingBox(2 - eps, -eps, -eps, 2 + eps,
                                            1 + eps, 1 + eps, 2)

for i in sxmin
    
    xmin, ymin, zmin, xmax, ymax, zmax = gmsh.model.getBoundingBox(i[1], i[2])
    
    sxmax = gmsh.model.getEntitiesInBoundingBox(xmin - eps + 1, ymin - eps,
                                                zmin - eps, xmax + eps + 1,
                                                ymax + eps, zmax + eps, 2)
    
    for j in sxmax
        xmin2, ymin2, zmin2, xmax2, ymax2, zmax2 = gmsh.model.getBoundingBox(
            j[1], j[2])
        xmin2 -= 1
        xmax2 -= 1
        
        if (abs(xmin2 - xmin) < eps && abs(xmax2 - xmax) < eps
                && abs(ymin2 - ymin) < eps && abs(ymax2 - ymax) < eps
                && abs(zmin2 - zmin) < eps && abs(zmax2 - zmax) < eps)
            gmsh.model.mesh.setPeriodic(2, [j[2]], [i[2]], translation)
        end
    end
end

gmsh.model.mesh.generate(3)
gmsh.write("t18.msh")

if !("-nopopup" in ARGS)
    gmsh.fltk.run()
end

gmsh.finalize()
