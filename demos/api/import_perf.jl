import gmsh

gmsh.initialize()

N = 2500

tic = gmsh.logger.getWallTime()
# x, y, z coordinates of all the nodes
coords = Array{Float64,1}(undef, (N + 1) * (N + 1) * 3)
# tags of corresponding nodes
nodes = Array{UInt,1}(undef, (N + 1) * (N + 1))
# connectivities (node tags) of triangle elements
tris = Array{UInt,1}(undef, N * N * 2 * 3)

function tag(i, j)
    return (N + 1) * i + j + 1
end

k = 0
l = 0
for i in 0:N
    for j in 0:N
        nodes[1 + k] = tag(i, j)
        coords[1 + 3 * k] = float(i) / N
        coords[1 + 3 * k + 1] = float(j) / N
        coords[1 + 3 * k + 2] = 0.05 * sin(10 * float(i + j) / N)
        global k += 1
        if (i > 0 && j > 0)
            tris[1 + 6 * l] = tag(i - 1, j - 1)
            tris[1 + 6 * l + 1] = tag(i, j - 1)
            tris[1 + 6 * l + 2] = tag(i - 1, j)
            tris[1 + 6 * l + 3] = tag(i, j - 1)
            tris[1 + 6 * l + 4] = tag(i, j)
            tris[1 + 6 * l + 5] = tag(i - 1, j)
            global l += 1
        end
    end
end

toc = gmsh.logger.getWallTime()
println("==> created nodes and connectivities in ", toc - tic, " seconds")

tic = gmsh.logger.getWallTime()
surf = gmsh.model.addDiscreteEntity(2)
toc = gmsh.logger.getWallTime()
println("==> created surface in ", toc - tic, " seconds")

tic = gmsh.logger.getWallTime()
gmsh.model.mesh.addNodes(2, 1, nodes, coords)
toc = gmsh.logger.getWallTime()
println("==> imported nodes in ", toc - tic, " seconds")

tic = gmsh.logger.getWallTime()
gmsh.model.mesh.addElementsByType(1, 2, [], tris)
toc = gmsh.logger.getWallTime()
println("==> imported elements in ", toc - tic, " seconds")

tic = gmsh.logger.getWallTime()
gmsh.option.setNumber("Mesh.Binary", 1)
gmsh.write("import_perf.msh")
toc = gmsh.logger.getWallTime()
println("==> wrote to disk in ", toc - tic, " seconds")

tic = gmsh.logger.getWallTime()
gmsh.merge("import_perf.msh")
toc = gmsh.logger.getWallTime()
println("==> read from disk in ", toc - tic, " seconds")

#gmsh.fltk.run()

gmsh.finalize()
