/*******************************************************************************
 *
 *  Gmsh C++ extended tutorial 1
 *
 *  Accessing geometrical and mesh data
 *
 *******************************************************************************/

// The C++ API allows to do much more than what can be done in .geo files. These
// additional features are introduced gradually in the extended tutorials,
// starting with `x1.cpp'.

// In this first extended tutorial, we start by using the API to explore basic
// geometrical and mesh data.

#include <iostream>
#include <gmsh.h>

int main(int argc, char **argv)
{
  if(argc < 2){
    std::cout << "Usage: " << argv[0] << " file" << std::endl;
    return 0;
  }

  gmsh::initialize();
  gmsh::option::setNumber("General.Terminal", 1);
  gmsh::open(argv[1]);

  // Geometrical data is made of elementary model `entities', called `points'
  // (entities of dimension 0), `curves' (entities of dimension 1), `surfaces'
  // (entities of dimension 2) and `volumes' (entities of dimension 3). As we
  // have seen in the other C++ tutorials, elementary model entities are
  // identified by their dimension and by a `tag': a strictly positive
  // identification number. Model entities can be either CAD entities (from the
  // built-in `geo' kernel or from the OpenCASCADE `occ' kernel) or `discrete'
  // entities (defined by a mesh).

  // Get all the entities in the model, as a vector of (dimension, tag) pairs:
  std::vector<std::pair<int, int> > entities;
  gmsh::model::getEntities(entities);

  for(unsigned int i = 0; i < entities.size(); i++){
    // Mesh data is made of `elements' (points, lines, triangles, ...), defined
    // by an ordered list of their `nodes'. Elements and nodes are identified by
    // `tags' as well (strictly positive identification numbers), and are stored
    // ("classified") in the model entity they discretize.

    // A model entity of dimension 0 (a geometrical point) will contain a mesh
    // element of type point, as well as a mesh node. A model curve will contain
    // line elements as well as its interior nodes, while its boundary nodes
    // will be stored in the bounding model points. A model surface will contain
    // triangular and/or quadrangular elements and all the nodes not classified
    // on its boundary or on its embedded entities (curves and points). A model
    // volume will contain tetrahedra, hexahedra, etc. and all the nodes not
    // classified on its boundary or on its embedded entities (surfaces, curves
    // and points).

    // Get the mesh nodes for each entity:
    std::vector<std::size_t> nodeTags;
    std::vector<double> nodeCoords, nodeParams;
    int dim = entities[i].first, tag = entities[i].second;
    gmsh::model::mesh::getNodes(nodeTags, nodeCoords, nodeParams, dim, tag);

    // Get the mesh elements for each entity:
    std::vector<int> elemTypes;
    std::vector<std::vector<std::size_t> > elemTags, elemNodeTags;
    gmsh::model::mesh::getElements(elemTypes, elemTags, elemNodeTags, dim, tag);

    // Print a summary of information available on the entity and its mesh:
    int numElem = 0;
    for(unsigned int i = 0; i < elemTags.size(); i++)
      numElem += elemTags[i].size();
    std::string type;
    gmsh::model::getType(dim, tag, type);
    std::cout << nodeTags.size() << " mesh nodes and "
              << numElem << " mesh elements on entity ("
              << dim << "," << tag << ") of type " << type << "\n";
    std::vector<int> physicalTags;
    gmsh::model::getPhysicalGroupsForEntity(dim, tag, physicalTags);
    if(physicalTags.size()) {
      std::cout << " - Physical group tag(s):";
      for(unsigned int i = 0; i < physicalTags.size(); i++)
        std::cout << " " << physicalTags[i];
      std::cout << "\n";
    }
    std::vector<int> partitions;
    gmsh::model::getPartitions(dim, tag, partitions);
    if(partitions.size()){
      std::cout << " - Partition tag(s):";
      for(unsigned int i = 0; i < partitions.size(); i++)
        std::cout << " " << partitions[i];
      int parentDim, parentTag;
      gmsh::model::getParent(dim, tag, parentDim, parentTag);
      std::cout << " - parent entity (" << parentDim << "," << parentTag << ")\n";
    }
    for(unsigned int i = 0; i < elemTypes.size(); i++){
      std::string name;
      int d, order, numv, numpv;
      std::vector<double> param;
      gmsh::model::mesh::getElementProperties(elemTypes[i], name, d, order,
                                              numv, param, numpv);
      std::cout << " - Element type: " << name << ", order " << order << "\n";
      std::cout << "   with " << numv << " nodes in param coord: (";
      for(unsigned int j = 0; j < param.size(); j++)
        std::cout << param[j] << " ";
      std::cout << ")\n";
    }
  }

  gmsh::finalize();
  return 0;
}
