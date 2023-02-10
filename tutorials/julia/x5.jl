# -----------------------------------------------------------------------------
#
#  Gmsh Julia extended tutorial 5
#
#  Additional geometrical data: parametrizations, normals, curvatures
#
# -----------------------------------------------------------------------------

import gmsh

gmsh.initialize(append!(["gmsh"], ARGS))

# The API provides access to geometrical data in a CAD kernel agnostic manner.

# Let's create a simple CAD model by fusing a sphere and a cube, then mesh the
# surfaces:
gmsh.model.add("x5")
s = gmsh.model.occ.addSphere(0, 0, 0, 1)
b = gmsh.model.occ.addBox(0.5, 0, 0, 1.3, 2, 3)
gmsh.model.occ.fuse([(3, s)], [(3, b)])
gmsh.model.occ.synchronize()
gmsh.model.mesh.generate(2)

# We can for example retrieve the exact normals and the curvature at all the
# mesh nodes (i.e. not normals and curvatures computed from the mesh, but
# directly evaluated on the geometry), by querying the CAD kernels at the
# corresponding parametric coordinates.
normals = []
curvatures = []

# For each surface in the model:
for e in gmsh.model.getEntities(2)
    # Retrieve the surface tag
    local s = e[2]

    # Get the mesh nodes on the surface, including those on the boundary
    # (contrary to internal nodes, which store their parametric coordinates,
    # boundary nodes will be reparametrized on the surface in order to compute
    # their parametric coordinates, the result being different when
    # reparametrized on another adjacent surface)
    tags, coord, param = gmsh.model.mesh.getNodes(2, s, true)

    # Get the surface normals on all the points on the surface corresponding to
    # the parametric coordinates of the nodes
    norm = gmsh.model.getNormal(s, param)

    # In the same way, get the curvature
    curv = gmsh.model.getCurvature(2, s, param)

    # Store the normals and the curvatures so that we can display them as
    # list-based post-processing views
    for i in 1:3:length(coord)
        push!(normals, coord[i], coord[i + 1], coord[i + 2],
              norm[i], norm[i + 1], norm[i + 2])
        push!(curvatures, coord[i], coord[i + 1], coord[i + 2],
              curv[div(i - 1, 3) + 1])
    end
end

# Create a list-based vector view on points to display the normals, and a scalar
# view on points to display the curvatures
vn = gmsh.view.add("normals")
gmsh.view.addListData(vn, "VP", length(normals) / 6, normals)
gmsh.view.option.setNumber(vn, "ShowScale", 0)
gmsh.view.option.setNumber(vn, "ArrowSizeMax", 30)
gmsh.view.option.setNumber(vn, "ColormapNumber", 19)
vc = gmsh.view.add("curvatures")
gmsh.view.addListData(vc, "SP", length(curvatures) / 4, curvatures)
gmsh.view.option.setNumber(vc, "ShowScale", 0)

# We can also retrieve the parametrization bounds of model entities, e.g. of
# curve 5, and evaluate the parametrization for several parameter values:
bounds = gmsh.model.getParametrizationBounds(1, 5)
N = 20
t = [bounds[1][1] + i * (bounds[2][1] - bounds[1][1]) / N for i in 0:N - 1]
xyz1 = gmsh.model.getValue(1, 5, t)

# We can also reparametrize curve 5 on surface 1, and evaluate the points in the
# parametric plane of the surface:
uv = gmsh.model.reparametrizeOnSurface(1, 5, t, 1)
xyz2 = gmsh.model.getValue(2, 1, uv)

# Hopefully we get the same x, y, z coordinates!
if maximum([abs(a - b) for (a, b) in zip(xyz1, xyz2)]) < 1e-12
    gmsh.logger.write("Evaluation on curve and surface match!")
else
    gmsh.logger.write("Evaluation on curve and surface do not match!", "error")
end

# Launch the GUI to see the results:
if !("-nopopup" in ARGS)
    gmsh.fltk.run()
end

gmsh.finalize()
