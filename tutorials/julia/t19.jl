# See the corresponding Python tutorial for detailed comments.

import gmsh

gmsh.initialize()

gmsh.model.add("t19")

gmsh.model.occ.addCircle(0, 0, 0, 0.5, 1)
gmsh.model.occ.addCurveLoop([1], 1)
gmsh.model.occ.addCircle(0.1, 0.05, 1, 0.1, 2)
gmsh.model.occ.addCurveLoop([2], 2)
gmsh.model.occ.addCircle(-0.1, -0.1, 2, 0.3, 3)
gmsh.model.occ.addCurveLoop([3], 3)
gmsh.model.occ.addThruSections([1, 2, 3], 1)
gmsh.model.occ.synchronize()

gmsh.model.occ.addCircle(2 + 0, 0, 0, 0.5, 11)
gmsh.model.occ.addCurveLoop([11], 11)
gmsh.model.occ.addCircle(2 + 0.1, 0.05, 1, 0.1, 12)
gmsh.model.occ.addCurveLoop([12], 12)
gmsh.model.occ.addCircle(2 - 0.1, -0.1, 2, 0.3, 13)
gmsh.model.occ.addCurveLoop([13], 13)
gmsh.model.occ.addThruSections([11, 12, 13], 11, true, true)
gmsh.model.occ.synchronize()

out = gmsh.model.occ.copy([(3, 1)])
gmsh.model.occ.translate(out, 4, 0, 0)
gmsh.model.occ.synchronize()
e = gmsh.model.getBoundary(gmsh.model.getBoundary(out), false)
gmsh.model.occ.fillet([out[1][2]], [abs(i[2]) for i in e], [0.1])
gmsh.model.occ.synchronize()


nturns = 1.
npts = 20
r = 1.
h = 1. * nturns
p = []

for i in 0:npts
    theta = i * 2 * pi * nturns / npts
    gmsh.model.occ.addPoint(r * cos(theta), r * sin(theta),
                            i * h / npts, 1, 1000 + i)
    append!(p , 1000 + i)
end

gmsh.model.occ.addSpline(p, 1000)

gmsh.model.occ.addWire([1000], 1000)

gmsh.model.occ.addDisk(1, 0, 0, 0.2, 0.2, 1000)
gmsh.model.occ.rotate([(2, 1000)], 0, 0, 0, 1, 0, 0, pi / 2)

gmsh.model.occ.addPipe([(2, 1000)], 1000, "DiscreteTrihedron")

gmsh.model.occ.remove([(2, 1000)])
gmsh.option.setNumber("Geometry.NumSubEdges", 1000)

gmsh.model.occ.synchronize()

gmsh.option.setNumber("Mesh.MeshSizeFromCurvature", 20)

gmsh.option.setNumber("Mesh.MeshSizeMin", 0.001)
gmsh.option.setNumber("Mesh.MeshSizeMax", 0.3)

gmsh.model.mesh.generate(3)
gmsh.write("t19.msh")

if !("-nopopup" in ARGS)
    gmsh.fltk.run()
end

gmsh.finalize()
