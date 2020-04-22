// -----------------------------------------------------------------------------
//
//  Gmsh C++ extended tutorial 1
//
//  Geometry and mesh data
//
// -----------------------------------------------------------------------------

// The C++ API allows to do much more than what can be done in .geo files. These
// additional features are introduced gradually in the extended tutorials,
// starting with `x1.cpp'.

// In this first extended tutorial, we start by using the API to access basic
// geometrical and mesh data.

#include <iostream>
#include <gmsh.h>

int main(int argc, char **argv)
{
  if(argc < 2) {
    std::cout << "Usage: " << argv[0] << " file" << std::endl;
    return 0;
  }

  gmsh::initialize();
  gmsh::option::setNumber("General.Terminal", 1);

  // You can run this tutorial on any file that Gmsh can read, e.g. a mesh file
  // in the MSH format: `t1.exe file.msh'
  gmsh::open(argv[1]);

  // Print the model name and dimension:
  std::string name;
  gmsh::model::getCurrent(name);
  std::cout << "Model " << name << " (" << gmsh::model::getDimension()
            << "D)\n";

  // Geometrical data is made of elementary model `entities', called `points'
  // (entities of dimension 0), `curves' (entities of dimension 1), `surfaces'
  // (entities of dimension 2) and `volumes' (entities of dimension 3). As we
  // have seen in the other C++ tutorials, elementary model entities are
  // identified by their dimension and by a `tag': a strictly positive
  // identification number. Model entities can be either CAD entities (from the
  // built-in `geo' kernel or from the OpenCASCADE `occ' kernel) or `discrete'
  // entities (defined by a mesh). `Physical groups' are collections of model
  // entities and are also identified by their dimension and by a tag.

  // Get all the elementary entities in the model, as a vector of (dimension,
  // tag) pairs:
  std::vector<std::pair<int, int> > entities;
  gmsh::model::getEntities(entities);

  for(std::size_t i = 0; i < entities.size(); i++) {
    // Mesh data is made of `elements' (points, lines, triangles, ...), defined
    // by an ordered list of their `nodes'. Elements and nodes are identified by
    // `tags' as well (strictly positive identification numbers), and are stored
    // ("classified") in the model entity they discretize. Tags for elements and
    // nodes are globally unique (and not only per dimension, like entities).

    // A model entity of dimension 0 (a geometrical point) will contain a mesh
    // element of type point, as well as a mesh node. A model curve will contain
    // line elements as well as its interior nodes, while its boundary nodes
    // will be stored in the bounding model points. A model surface will contain
    // triangular and/or quadrangular elements and all the nodes not classified
    // on its boundary or on its embedded entities. A model volume will contain
    // tetrahedra, hexahedra, etc. and all the nodes not classified on its
    // boundary or on its embedded entities.

    // Dimension and tag of the entity:
    int dim = entities[i].first, tag = entities[i].second;

    // Get the mesh nodes for the entity (dim, tag):
    std::vector<std::size_t> nodeTags;
    std::vector<double> nodeCoords, nodeParams;
    gmsh::model::mesh::getNodes(nodeTags, nodeCoords, nodeParams, dim, tag);

    // Get the mesh elements for the entity (dim, tag):
    std::vector<int> elemTypes;
    std::vector<std::vector<std::size_t> > elemTags, elemNodeTags;
    gmsh::model::mesh::getElements(elemTypes, elemTags, elemNodeTags, dim, tag);

    // Let's print a summary of the information available on the entity and its
    // mesh.

    // * Type of the entity:
    std::string type;
    gmsh::model::getType(dim, tag, type);
    std::string name;
    gmsh::model::getEntityName(dim, tag, name);
    if(name.size()) name += " ";
    std::cout << "Entity " << name << "(" << dim << "," << tag << ") of type "
              << type << "\n";

    // * Number of mesh nodes and elements:
    int numElem = 0;
    for(std::size_t j = 0; j < elemTags.size(); j++)
      numElem += elemTags[j].size();
    std::cout << " - Mesh has " << nodeTags.size() << " nodes and " << numElem
              << " elements\n";

    // * Entities on its boundary:
    std::vector<std::pair<int, int> > boundary;
    gmsh::model::getBoundary({{dim, tag}}, boundary);
    if(boundary.size()) {
      std::cout << " - Boundary entities: ";
      for(std::size_t j = 0; j < boundary.size(); j++)
        std::cout << "(" << boundary[j].first << "," << boundary[j].second
                  << ") ";
      std::cout << "\n";
    }

    // * Does the entity belong to physical groups?
    std::vector<int> physicalTags;
    gmsh::model::getPhysicalGroupsForEntity(dim, tag, physicalTags);
    if(physicalTags.size()) {
      std::cout << " - Physical group: ";
      for(std::size_t j = 0; j < physicalTags.size(); j++) {
        std::string n;
        gmsh::model::getPhysicalName(dim, physicalTags[j], n);
        if(n.size()) n += " ";
        std::cout << n << "(" << dim << ", " << physicalTags[j] << ") ";
      }
      std::cout << "\n";
    }

    // * Is the entity a partition entity? If so, what is its parent entity?
    std::vector<int> partitions;
    gmsh::model::getPartitions(dim, tag, partitions);
    if(partitions.size()) {
      std::cout << " - Partition tags:";
      for(std::size_t j = 0; j < partitions.size(); j++)
        std::cout << " " << partitions[j];
      int parentDim, parentTag;
      gmsh::model::getParent(dim, tag, parentDim, parentTag);
      std::cout << " - parent entity (" << parentDim << "," << parentTag
                << ")\n";
    }

    // * List all types of elements making up the mesh of the entity:
    for(std::size_t j = 0; j < elemTypes.size(); j++) {
      std::string name;
      int d, order, numv, numpv;
      std::vector<double> param;
      gmsh::model::mesh::getElementProperties(elemTypes[j], name, d, order,
                                              numv, param, numpv);
      std::cout << " - Element type: " << name << ", order " << order << "\n";
      std::cout << "   with " << numv << " nodes in param coord: (";
      for(std::size_t k = 0; k < param.size(); k++)
        std::cout << param[k] << " ";
      std::cout << ")\n";
    }
  }

  // We can use this to clear all the model data:
  gmsh::clear();

  gmsh::finalize();
  return 0;
}
