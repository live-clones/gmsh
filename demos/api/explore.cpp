#include <iostream>
#include <gmsh.h>

int main(int argc, char **argv)
{
  if(argc < 2){
    std::cout << "Usage: " << argv[0] << " file.msh [options]" << std::endl;
    return 1;
  }

  gmsh::initialize();
  gmsh::option::setNumber("General.Terminal", 1);
  gmsh::open(argv[1]);

  // get all elementary entities in the model
  std::vector<std::pair<int, int> > entities;
  gmsh::model::getEntities(entities);

  for(unsigned int i = 0; i < entities.size(); i++){
    // get the mesh vertices for each elementary entity
    std::vector<int> vertexTags;
    std::vector<double> vertexCoords, vertexParams;
    int dim = entities[i].first, tag = entities[i].second;
    gmsh::model::mesh::getVertices(dim, tag, vertexTags, vertexCoords, vertexParams);

    // get the mesh elements for each elementary entity
    std::vector<int> elemTypes;
    std::vector<std::vector<int> > elemTags, elemVertexTags;
    gmsh::model::mesh::getElements(dim, tag, elemTypes, elemTags, elemVertexTags);

    // report some statistics
    int numElem = 0;
    for(unsigned int i = 0; i < elemTags.size(); i++)
      numElem += elemTags[i].size();
    std::cout << vertexTags.size() << " mesh vertices and "
              << numElem << " mesh elements on entity ("
              << dim << "," << tag << ")\n";
  }

  gmsh::finalize();
  return 0;
}
