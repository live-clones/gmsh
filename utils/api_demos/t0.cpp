#include <iostream>
#include <gmsh.h>

int main(int argc, char **argv)
{
  if(argc < 2){
    std::cout << "Usage: " << argv[0] << " file.geo [options]\n";
    return 1;
  }
  gmshInitialize();
  gmshOptionSetNumber("General.Terminal", 1);
  gmshOptionSetNumber("Mesh.Algorithm", 5);
  gmshOpen(argv[1]);
  gmshModelMesh(3);

  std::vector<std::pair<int, int> > entities;
  gmshModelGetEntities(entities);
  for(unsigned int i = 0; i < entities.size(); i++){
    std::vector<int> vertexTags;
    std::vector<double> vertexCoords;
    int dim = entities[i].first, tag = entities[i].second;
    gmshModelGetMeshVertices(dim, tag, vertexTags, vertexCoords);
    std::vector<int> elemTypes;
    std::vector<std::vector<int> > elemTags, elemVertexTags;
    gmshModelGetMeshElements(dim, tag, elemTypes, elemTags, elemVertexTags);

    int numElem = 0;
    for(unsigned int i = 0; i < elemTags.size(); i++)
      numElem += elemTags[i].size();
    std::cout << vertexTags.size() << " mesh vertices and "
              << numElem << " mesh elements on entity ("
              << dim << "," << tag << ")\n";
  }

  gmshExport("test.msh");
  gmshExport("test.unv");
  gmshFinalize();
  return 0;
}
