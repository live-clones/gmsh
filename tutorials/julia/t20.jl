# See the corresponding Python tutorial for detailed comments.

import gmsh

gmsh.initialize()

gmsh.model.add("t20")

path = abspath(joinpath("..","t20_data.step"))
v = gmsh.model.occ.importShapes(path)

xmin, ymin, zmin, xmax, ymax, zmax = gmsh.model.occ.getBoundingBox(
    v[1][1], v[1][2])

N = 5
dir = "X"
surf = false

dx = (xmax - xmin)
dy = (ymax - ymin)
dz = (zmax - zmin)
 
if (dir == "X")
    L = dz

else 
    L = dx 
end

if (dir == "Y")
    H = dz

else 
    H = dy 
end

s = []

push!(s,(2, gmsh.model.occ.addRectangle(xmin, ymin, zmin, L, H)))

if dir == "X"
    gmsh.model.occ.rotate([s[1]], xmin, ymin, zmin, 0, 1, 0, -pi/2)

elseif dir == "Y"
    gmsh.model.occ.rotate([s[1]], xmin, ymin, zmin, 1, 0, 0, pi/2)
end

if (dir == "X")
    tx = dx / N

else 
    tx = 0 
end

if (dir == "Y")
    ty = dy / N

else 
    ty = 0 
end

if (dir == "Z")
    tz = dz / N

else 
    tz = 0 
end

gmsh.model.occ.translate([s[1]], tx, ty, tz)


for i in 1:N-1
    append!(s,(gmsh.model.occ.copy([s[1]])))
    gmsh.model.occ.translate([s[length(s)]], i * tx, i * ty, i * tz)
end

gmsh.model.occ.fragment(v, s)

gmsh.model.occ.remove(gmsh.model.occ.getEntities(2), true)

gmsh.model.occ.synchronize()

if surf
    eps = 1e-4
    s = []
    for i in 1:N
        
        if (dir == "X")
            xx = xmin

        else 
            xx = xmax 
        end

        if (dir == "Y")
            yy = ymin

        else 
            yy = ymax 
        end

        if (dir == "Z")
            zz = zmin

        else 
            zz = zmax 
        end
        
        append!(s, (gmsh.model.getEntitiesInBoundingBox(
            xmin - eps + i * tx, ymin - eps + i * ty, zmin - eps + i * tz,
            xx + eps + i * tx, yy + eps + i * ty, zz + eps + i * tz, 2)))
    end
    
    dels = gmsh.model.getEntities(2)
    
    for e in s
        deleteat!(s, findall(x->x==e,s))
    end
    
    gmsh.model.removeEntities(gmsh.model.getEntities(3))
    gmsh.model.removeEntities(dels)
    gmsh.model.removeEntities(gmsh.model.getEntities(1))
    gmsh.model.removeEntities(gmsh.model.getEntities(0))

end

gmsh.option.setNumber("Mesh.MeshSizeMin", 3)
gmsh.option.setNumber("Mesh.MeshSizeMax", 3)
gmsh.model.mesh.generate(3)
gmsh.write("t20.msh")

if !("-nopopup" in ARGS)
    gmsh.fltk.run()
end

gmsh.finalize()
