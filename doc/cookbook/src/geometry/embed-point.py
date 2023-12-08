import gmsh

def pointInCurve(point_tag, curve_tag):
    return gmsh.model.occ.fragment([(0, point_tag)], [(1, curve_tag)])[0]

gmsh.initialize()
a = gmsh.model.occ.addPoint(0, 0, 0)
b = gmsh.model.occ.addPoint(5, 0, 0)
line = gmsh.model.occ.addLine(a, b)

# the point we want to embed
p = gmsh.model.occ.addPoint(1, 0, 0)

# embed it
result_tags = pointInCurve(p, line)
# find the new point tag
embedded_point = next(tag for (dim, tag) in result_tags if dim == 0)

# add a physical group for the new point
gmsh.model.occ.synchronize()
group = gmsh.model.addPhysicalGroup(0, [embedded_point])
gmsh.model.setPhysicalName(0, group, "embedded point")

gmsh.finalize()
