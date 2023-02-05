# -----------------------------------------------------------------------------
#
#  Gmsh Julia extended tutorial 7
#
#  Additional mesh data: internal edges and faces
#
# -----------------------------------------------------------------------------

import gmsh

gmsh.initialize(append!(["gmsh"], ARGS))

gmsh.model.add("x7")

# Meshes are fully described in Gmsh by nodes and elements, both associated to
# model entities. The API can be used to generate and handle other mesh
# entities, i.e. mesh edges and faces, which are not stored by default.

# Let's create a simple model and mesh it:
gmsh.model.occ.addBox(0, 0, 0, 1, 1, 1)
gmsh.model.occ.synchronize()
gmsh.option.setNumber("Mesh.MeshSizeMin", 2.)
gmsh.model.mesh.generate(3)

# Like elements, mesh edges and faces are described by (an ordered list of)
# their nodes. Let us retrieve the edges and the (triangular) faces of all the
# first order tetrahedra in the mesh:
elementType = gmsh.model.mesh.getElementType("tetrahedron", 1)
edgeNodes = gmsh.model.mesh.getElementEdgeNodes(elementType)
faceNodes = gmsh.model.mesh.getElementFaceNodes(elementType, 3)

# Edges and faces are returned for each element as a list of nodes corresponding
# to the canonical orientation of the edges and faces for a given element type.

# Gmsh can also identify unique edges and faces (a single edge or face whatever
# the ordering of their nodes) and assign them a unique tag. This identification
# can be done internally by Gmsh (e.g. when generating keys for basis
# functions), or requested explicitly as follows:
gmsh.model.mesh.createEdges()
gmsh.model.mesh.createFaces()

# Edge and face tags can then be retrieved by providing their nodes:
edgeTags, edgeOrientations = gmsh.model.mesh.getEdges(edgeNodes)
faceTags, faceOrientations = gmsh.model.mesh.getFaces(3, faceNodes)

# Since element edge and face nodes are returned in the same order as the
# elements, one can easily keep track of which element(s) each edge or face is
# connected to:
elementTags, elementNodeTags = gmsh.model.mesh.getElementsByType(elementType)
edges2Elements = Dict()
faces2Elements = Dict()
for i in 1:length(edgeTags) # 6 edges per tetrahedron
    if !haskey(edges2Elements, edgeTags[i])
        edges2Elements[edgeTags[i]] = [elementTags[div(i - 1, 6) + 1]]
    else
        push!(edges2Elements[edgeTags[i]], elementTags[div(i - 1, 6) + 1])
    end
end
for i in 1:length(faceTags) # 4 faces per tetrahedron
    if !haskey(faces2Elements, faceTags[i])
        faces2Elements[faceTags[i]] = [elementTags[div(i - 1, 4) + 1]]
    else
        push!(faces2Elements[faceTags[i]], elementTags[div(i - 1, 4) + 1])
    end
end

# New unique lower dimensional elements can also be easily created given the
# edge or face nodes. This is especially useful for numerical methods that
# require integrating or interpolating on internal edges or faces (like
# e.g. Discontinuous Galerkin techniques), since creating elements for the
# internal entities will make this additional mesh data readily available (see
# `x6.py'). For example, we can create a new discrete surface...
s = gmsh.model.addDiscreteEntity(2)

# ... and fill it with unique triangles corresponding to the faces of the
# tetrahedra:
maxElementTag = gmsh.model.mesh.getMaxElementTag()
uniqueFaceTags = Set()
tagsForTriangles = []
faceNodesForTriangles = []
for i in 1:length(faceTags)
    if !in(faceTags[i], uniqueFaceTags)
        push!(uniqueFaceTags, faceTags[i])
        push!(tagsForTriangles, faceTags[i] + maxElementTag)
        push!(faceNodesForTriangles,
              faceNodes[3 * (i - 1) + 1], faceNodes[3 * (i - 1) + 2], faceNodes[3 * (i - 1) + 3])
    end
end
elementType2D = gmsh.model.mesh.getElementType("triangle", 1)
gmsh.model.mesh.addElementsByType(s, elementType2D, tagsForTriangles,
                                  faceNodesForTriangles)

# Since the tags for the triangles have been created based on the face tags,
# the information about neighboring elements can also be readily created,
# useful e.g. in Finite Volume or Discontinuous Galerkin techniques:
for t in tagsForTriangles
    println("triangle " * string(t) * " is connected to tetrahedra " *
            string(convert(Array{Int}, faces2Elements[t - maxElementTag])))
end

# If all you need is the list of all edges or faces in terms of their nodes, you
# can also directly call:
edgeTags, edgeNodes = gmsh.model.mesh.getAllEdges()
faceTags, faceNodes = gmsh.model.mesh.getAllFaces(3)

# Launch the GUI to see the results:
if !("-nopopup" in ARGS)
    gmsh.fltk.run()
end

gmsh.finalize()
