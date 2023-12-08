# -----------------------------------------------------------------------------
#
#  Gmsh Julia extended tutorial 1
#
#  Geometry and mesh data
#
# -----------------------------------------------------------------------------

# The Julia API allows to do much more than what can be done in .geo
# files. These additional features are introduced gradually in the extended
# tutorials, starting with `x1.jl'.

# In this first extended tutorial, we start by using the API to access basic
# geometrical and mesh data.

import gmsh

gmsh.initialize()

if length(ARGS) > 0 && ARGS[1][1] != '-'
    # If an argument is provided, handle it as a file that Gmsh can read, e.g. a
    # mesh file in the MSH format (`julia x1.py file.msh')
    gmsh.open(ARGS[1])
else
    # Otherwise, create and mesh a simple geometry
    gmsh.model.occ.addCone(1, 0, 0, 1, 0, 0, 0.5, 0.1)
    gmsh.model.occ.synchronize()
    gmsh.model.mesh.generate()
end

# Print the model name and dimension:
println("Model ", gmsh.model.getCurrent(), " (", gmsh.model.getDimension(), "D)")

# Geometrical data is made of elementary model `entities', called `points'
# (entities of dimension 0), `curves' (entities of dimension 1), `surfaces'
# (entities of dimension 2) and `volumes' (entities of dimension 3). As we have
# seen in the other Julia tutorials, elementary model entities are identified
# by their dimension and by a `tag': a strictly positive identification
# number. Model entities can be either CAD entities (from the built-in `geo'
# kernel or from the OpenCASCADE `occ' kernel) or `discrete' entities (defined
# by a mesh). `Physical groups' are collections of model entities and are also
# identified by their dimension and by a tag.

# Get all the elementary entities in the model, as a vector of (dimension, tag)
# pairs:
entities = gmsh.model.getEntities()

for e in entities
    # Dimension and tag of the entity:
    dim = e[1]
    tag = e[2]

    # Mesh data is made of `elements' (points, lines, triangles, ...), defined
    # by an ordered list of their `nodes'. Elements and nodes are identified by
    # `tags' as well (strictly positive identification numbers), and are stored
    # ("classified") in the model entity they discretize. Tags for elements and
    # nodes are globally unique (and not only per dimension, like entities).

    # A model entity of dimension 0 (a geometrical point) will contain a mesh
    # element of type point, as well as a mesh node. A model curve will contain
    # line elements as well as its interior nodes, while its boundary nodes will
    # be stored in the bounding model points. A model surface will contain
    # triangular and/or quadrangular elements and all the nodes not classified
    # on its boundary or on its embedded entities. A model volume will contain
    # tetrahedra, hexahedra, etc. and all the nodes not classified on its
    # boundary or on its embedded entities.

    # Get the mesh nodes for the entity (dim, tag):
    nodeTags, nodeCoords, nodeParams = gmsh.model.mesh.getNodes(dim, tag)

    # Get the mesh elements for the entity (dim, tag):
    elemTypes, elemTags, elemNodeTags = gmsh.model.mesh.getElements(dim, tag)

    # Elements can also be obtained by type, by using `getElementTypes()'
    # followed by `getElementsByType()'.

    # Let's print a summary of the information available on the entity and its
    # mesh.

    # * Type and name of the entity:
    type = gmsh.model.getType(dim, tag)
    name = gmsh.model.getEntityName(dim, tag)
    if length(name) > 0
        name *= " "
    end
    println("Entity ", name, e, " of type ", type)

    # * Number of mesh nodes and elements:
    numElem = sum(length(i) for i in elemTags; init=0)
    println(" - Mesh has ", length(nodeTags), " nodes and ", numElem,
            " elements")

    # * Upward and downward adjacencies:
    up, down = gmsh.model.getAdjacencies(dim, tag)
    if length(up) > 0
        println(" - Upward adjacencies: ", up)
    end
    if length(down) > 0
        println(" - Downward adjacencies: ", down)
    end

    # * Does the entity belong to physical groups?
    physicalTags = gmsh.model.getPhysicalGroupsForEntity(dim, tag)
    if length(physicalTags) > 0
        s = ""
        for p in physicalTags
            n = gmsh.model.getPhysicalName(dim, p)
            if n != ""
                n *= " "
            end
            s *= n * '(' * string(dim) * ", " * string(p) * ") "
        end
        println(" - Physical groups: " * s)
    end

    # * Is the entity a partition entity? If so, what is its parent entity?
    partitions = gmsh.model.getPartitions(dim, tag)
    if length(partitions) > 0
        println(" - Partition tags: ", partitions, " - parent entity ",
                gmsh.model.getParent(dim, tag))
    end

    # * List all types of elements making up the mesh of the entity:
    for t in elemTypes
        name, dim, order, numv, parv, _ = gmsh.model.mesh.getElementProperties(
            t)
        println(" - Element type: ", name, ", order ", order, " (",
                numv, " nodes in param coord: ", parv, ")")
    end
end

# Launch the GUI to see the model:
if !("-nopopup" in ARGS)
    gmsh.fltk.run()
end

# We can use this to clear all the model data:
gmsh.clear()

gmsh.finalize()
