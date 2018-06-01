#include <iostream>
#include <gmsh.h>

int main(int argc, char **argv)
{
  if(argc < 2){
    std::cout << "Usage: " << argv[0] << " file.msh [options]" << std::endl;
    return 0;
  }

  gmsh::initialize();
  gmsh::option::setNumber("General.Terminal", 1);
  gmsh::open(argv[1]);

  // get all elementary entities in the model
  std::vector<std::pair<int, int> > entities;
  gmsh::model::getEntities(entities);

  for(unsigned int i = 0; i < entities.size(); i++){
    // get the mesh nodes for each elementary entity
    std::vector<int> nodeTags;
    std::vector<double> nodeCoords, nodeParams;
    int dim = entities[i].first, tag = entities[i].second;
    gmsh::model::mesh::getNodes(nodeTags, nodeCoords, nodeParams, dim, tag);

    // get the mesh elements for each elementary entity
    std::vector<int> elemTypes;
    std::vector<std::vector<int> > elemTags, elemNodeTags;
    gmsh::model::mesh::getElements(elemTypes, elemTags, elemNodeTags, dim, tag);

    // report some statistics
    int numElem = 0;
    for(unsigned int i = 0; i < elemTags.size(); i++)
      numElem += elemTags[i].size();
    std::cout << nodeTags.size() << " mesh nodes and "
              << numElem << " mesh elements on entity ("
              << dim << "," << tag << ")\n";
    for(unsigned int i = 0; i < elemTypes.size(); i++){
      std::string name;
      int d, order, numv;
      std::vector<double> param;
      gmsh::model::mesh::getElementProperties(elemTypes[i], name, d, order, numv, param);
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
