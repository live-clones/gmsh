import gmsh
import sys
import os
import math

gmsh.initialize(sys.argv)

# merge STL, create surface patches that are reparametrizable (so we can remesh
# them) and compute the parametrizations
path = os.path.dirname(os.path.abspath(__file__))
gmsh.merge(os.path.join(path, 'aneurysm_data.stl'))
gmsh.model.mesh.classifySurfaces(math.pi, True, True)
gmsh.model.mesh.createGeometry()

extrude = True
#extrude = False

if extrude:
    # make extrusions only return "top" surfaces and volumes, not lateral
    # surfaces
    gmsh.option.setNumber('Geometry.ExtrudeReturnLateralEntities', 0)

    # extrude a boundary layer of 4 elements using mesh normals (thickness =
    # 0.5)
    e1 = gmsh.model.geo.extrudeBoundaryLayer(gmsh.model.getEntities(2),
                                             [4], [0.5], True)

    # extrude a second boundary layer in the opposite direction (note the
    # `second == True' argument to distinguish it from the first one)
    e2 = gmsh.model.geo.extrudeBoundaryLayer(gmsh.model.getEntities(2), [4], [-0.5],
                                             True, True)

    # get "top" surfaces created by extrusion
    top_ent = [s for s in e2 if s[0] == 2]
    top_surf = [s[1] for s in top_ent]

    # get boundary of top surfaces, i.e. boundaries of holes
    gmsh.model.geo.synchronize()
    bnd_ent = gmsh.model.getBoundary(top_ent)
    bnd_curv = [c[1] for c in bnd_ent]

    # create plane surfaces filling the holes
    loops = gmsh.model.geo.addCurveLoops(bnd_curv)
    bnd_surf = []
    for l in loops:
        bnd_surf.append(gmsh.model.geo.addPlaneSurface([l]))

    # create the inner volume
    vf = gmsh.model.geo.addVolume([gmsh.model.geo.addSurfaceLoop(top_surf + bnd_surf)])
    gmsh.model.geo.synchronize()

    gmsh.model.addPhysicalGroup(3, [v[1] for v in e1 if v[0] == 3], name="solid")
    gmsh.model.addPhysicalGroup(3, [v[1] for v in e2 if v[0] == 3], name="fluid bl")
    gmsh.model.addPhysicalGroup(3, [vf], name="fluid")

    # to do: identify useful boundaries

# use MeshAdapt for the resulting not-so-smooth parametrizations
gmsh.option.setNumber('Mesh.Algorithm', 1)
gmsh.option.setNumber('Mesh.MeshSizeFactor', 0.1)

if '-nopopup' not in sys.argv:
    gmsh.fltk.run()

gmsh.finalize()
