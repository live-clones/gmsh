import gmsh
import os
import sys
import tempfile

# The surfaces of a 2D mesh read from a file are extruded with the built-in
# kernel, which gets their boundary from the model (it used to need
# CreateTopology first), and the extruded mesh can be set to second order
# without warnings (the extruded copies of discrete curves have no geometry).
# A second-order mesh, or a mesh saved without the elements of its curves,
# cannot be extruded: an error says so (the former used to overrun the stack)

gmsh.initialize(sys.argv)
errors = []


def source(name, order=1, curves=True):
    gmsh.clear()
    geo = gmsh.model.geo
    for i, (x, y) in enumerate([(0, 0), (1, 0), (2, 0), (2, 1), (1, 1), (0, 1)]):
        geo.addPoint(x, y, 0, tag=i + 1)
    for i, (a, b) in enumerate([(1, 2), (2, 3), (3, 4), (4, 5), (5, 6), (6, 1),
                                (2, 5)]):
        geo.addLine(a, b, i + 1)
    geo.addPlaneSurface([geo.addCurveLoop([1, 7, 5, 6])], 1)
    geo.addPlaneSurface([geo.addCurveLoop([2, 3, 4, -7])], 2)
    geo.synchronize()
    gmsh.model.addPhysicalGroup(2, [1, 2], 1)
    gmsh.option.setNumber("Mesh.MeshSizeMax", 0.2)
    gmsh.option.setNumber("Mesh.RecombineAll", 1)
    gmsh.option.setNumber("Mesh.Algorithm", 8)
    gmsh.option.setNumber("Mesh.SecondOrderIncomplete", 1)
    gmsh.option.setNumber("Mesh.SaveAll", 1 if curves else 0)
    gmsh.model.mesh.generate(2)
    gmsh.model.mesh.setOrder(order)
    gmsh.write(name)
    quads = len(gmsh.model.mesh.getElementsByType(3 if order == 1 else 16)[0])
    gmsh.clear()
    gmsh.option.setNumber("Mesh.RecombineAll", 0)
    return quads


def extrude(name):
    gmsh.merge(name)
    gmsh.model.geo.extrude(gmsh.model.getEntities(2), 0, 0, -1, [5],
                           recombine=True)
    gmsh.model.geo.synchronize()
    gmsh.model.mesh.generate(3)


with tempfile.TemporaryDirectory() as tmp:
    name = os.path.join(tmp, "extrude_merged_mesh.msh")

    quads = source(name)
    extrude(name)
    hexes = len(gmsh.model.mesh.getElementsByType(5)[0])
    if hexes != 5 * quads:
        errors.append("%d hexahedra instead of %d" % (hexes, 5 * quads))
    # (2 sources, 2 tops, and the lateral surfaces of their 8 curves)
    if len(gmsh.model.getEntities(3)) != 2 or len(gmsh.model.getEntities(2)) != 12:
        errors.append("%d volumes and %d surfaces instead of 2 and 12" %
                      (len(gmsh.model.getEntities(3)),
                       len(gmsh.model.getEntities(2))))
    gmsh.logger.start()
    gmsh.model.mesh.setOrder(2)
    log = [l for l in gmsh.logger.get() if l.startswith("Warning")]
    gmsh.logger.stop()
    if log:
        errors.append("%d warnings setting the order of the extruded mesh (%s)" %
                      (len(log), log[0]))
    if len(gmsh.model.mesh.getElementsByType(17)[0]) != hexes:
        errors.append("extruded mesh not set to second order")

    for what, order, curves in [("second-order mesh", 2, True),
                                ("mesh without the elements of its curves", 1,
                                 False)]:
        source(name, order, curves)
        try:
            extrude(name)
            errors.append("%s extruded" % what)
        except Exception as e:
            if "Cannot extrude" not in str(e):
                errors.append("%s: %s" % (what, e))

gmsh.finalize()

if errors:
    print("\n".join(errors))
    sys.exit(1)
print("OK")
