import gmsh

gmsh.initialize()

gmsh.model.occ.addRectangle(0,0,0, 1,1, tag=1)
gmsh.model.occ.addRectangle(2,0,0, 1,1, tag=2)
gmsh.model.occ.synchronize()
gmsh.model.mesh.generate(2)

# it is only possible to delete the mesh of an entity if the entity is not on
# the boundary of another entity with a non-empty mesh, since the nodes are
# shared:
gmsh.model.mesh.clear([(2, 2)]) # ok to remove mesh of surface 2
gmsh.model.mesh.clear([(1, 1)]) # not ok to remove mesh of curve 1 (on the
                                # boundary of surface 1)

# it is however possible to remove all the *elements* from an entity
gmsh.model.mesh.removeElements(1, 1)

# it is also possible to remove specific elements
_, tags, _ = gmsh.model.mesh.getElements(1, 2)
gmsh.model.mesh.removeElements(1, 2, tags[0][:3])

gmsh.write('remove_elements_no_reclassify.msh')

# to get model that conforms to the Gmsh data model, nodes should be
# reclassified on the entity of lowest dimension
gmsh.model.mesh.reclassifyNodes()
gmsh.write('remove_elements_reclassify.msh')

gmsh.finalize()
