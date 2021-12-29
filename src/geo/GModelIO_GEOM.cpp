// Gmsh - Copyright (C) 1997-2022 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GModel.h"
#include "OS.h"
#include "MTriangle.h"

static bool getMeshVertices(int num, int *indices, std::vector<MVertex *> &vec,
                            std::vector<MVertex *> &vertices)
{
  for(int i = 0; i < num; i++) {
    if(indices[i] < 0 || indices[i] > (int)(vec.size() - 1)) {
      Msg::Error("Wrong node index %d", indices[i]);
      return false;
    }
    else
      vertices.push_back(vec[indices[i]]);
  }
  return true;
}

int GModel::readGEOM(const std::string &name)
{
  // this is a format (from geomview?) that Bruno Levy's Graphite code
  // can write
  FILE *fp = Fopen(name.c_str(), "r");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  int numNodes, numElements, dummy;
  if(fscanf(fp, "%d %d %d", &numNodes, &numElements, &dummy) != 3) {
    fclose(fp);
    return 0;
  }

  if(!numNodes || !numElements) {
    Msg::Warning("No nodes or elements found");
    fclose(fp);
    return 0;
  }

  Msg::Info("%d nodes, %d elements", numNodes, numElements);

  std::vector<MVertex *> vertexVector;
  std::map<int, std::vector<MElement *> > elements[1];

  vertexVector.resize(numNodes);
  for(int i = 0; i < numNodes; i++) {
    double x, y, z;
    if(fscanf(fp, "%lf %lf %lf", &x, &y, &z) != 3) break;
    vertexVector[i] = new MVertex(x, y, z);
  }

  for(int i = 0; i < numElements; i++) {
    int N, n[3];
    if(fscanf(fp, "%d", &N) != 1) break;
    switch(N) {
    case 3: {
      if(fscanf(fp, "%d %d %d", &n[0], &n[1], &n[2]) != 3) break;
      for(int i = 0; i < 3; i++) n[i]--;
      std::vector<MVertex *> vertices;
      if(!getMeshVertices(3, n, vertexVector, vertices)) break;
      elements[0][1].push_back(new MTriangle(vertices));
    } break;
    default: Msg::Error("Unknown element type in .geom reader"); break;
    }
  }

  for(int i = 0; i < (int)(sizeof(elements) / sizeof(elements[0])); i++)
    _storeElementsInEntities(elements[i]);
  _associateEntityWithMeshVertices();
  _storeVerticesInEntities(vertexVector);

  fclose(fp);
  return 1;
}
