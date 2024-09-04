// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdio.h>
#include <string>
#include "GModel.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "OS.h"
#include "discreteFace.h"

int GModel::readOFF(const std::string &name)
{
  FILE *fp = Fopen(name.c_str(), "r");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  int numVertices, numFaces, numEdges;
  if(fscanf(fp, "OFF %d %d %d", &numVertices, &numFaces, &numEdges) != 3) {
    Msg::Error("Invalid OFF header");
    return 0;
  }

  if(!numVertices || !numFaces) {
    Msg::Info("Empty OFF mesh");
    return 1;
  }

  GFace *gf = new discreteFace(this, getMaxElementaryNumber(2) + 1);
  add(gf);

  std::vector<MVertex*> vertices(numVertices);
  for(int i = 0; i < numVertices; i++) {
    double x, y, z;
    if(fscanf(fp, "%lf %lf %lf", &x, &y, &z) != 3) {
      Msg::Error("Could not read vertex");
      return 0;
    }
    vertices[i] = new MVertex(x, y, z, gf);
  }

  for(int i = 0; i < numFaces; i++) {
    int n;
    if(fscanf(fp, "%d", &n) != 1) {
      Msg::Error("Could not read face");
    }
    int v[4] = {-1, -1, -1, -1};
    if(n == 3) {
      if(fscanf(fp, "%d %d %d", &v[0], &v[1], &v[2]) != 3) {
        Msg::Error("Could not read face");
        return 0;
      }
      gf->triangles.push_back(new MTriangle(vertices[v[0]], vertices[v[1]],
                                            vertices[v[2]]));
    }
    else if(n == 4) {
      if(fscanf(fp, "%d %d %d %d", &v[0], &v[1], &v[2], &v[3]) != 4) {
        Msg::Error("Could not read face");
        return 0;
      }
      gf->quadrangles.push_back(new MQuadrangle(vertices[v[0]], vertices[v[1]],
                                                vertices[v[2]], vertices[v[3]]));
    }
    else{
      char buffer[4096];
      if(!fgets(buffer, sizeof(buffer), fp))
        Msg::Error("Could not read line");
      Msg::Warning("Ignoring %d-node face", n);
      continue;
    }
  }

  _associateEntityWithMeshVertices();
  _storeVerticesInEntities(vertices); // will delete unused vertices
  fclose(fp);
  return 1;
}

int GModel::writeOFF(const std::string &name, bool saveAll, double scalingFactor)
{
  FILE *fp = Fopen(name.c_str(), "w");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  if(noPhysicalGroups()) saveAll = true;
  int numVertices = indexMeshVertices(saveAll);
  int numFaces = 0;
  for(auto it = faces.begin(); it != faces.end(); ++it) {
    GFace *gf = *it;
    if(saveAll || gf->physicals.size())
      numFaces += gf->getNumMeshElements();
  }

  fprintf(fp, "OFF %d %d 0\n", numVertices, numFaces);

  std::vector<GEntity *> entities;
  getEntities(entities);
  for(std::size_t i = 0; i < entities.size(); i++)
    for(std::size_t j = 0; j < entities[i]->mesh_vertices.size(); j++)
      entities[i]->mesh_vertices[j]->writeOFF(fp, scalingFactor);

  for(auto it = faces.begin(); it != faces.end(); ++it) {
    GFace *gf = *it;
    if(saveAll || gf->physicals.size()) {
      for(std::size_t i = 0; i < gf->triangles.size(); i++)
        fprintf(fp, "3 %d %d %d\n",
                (int)gf->triangles[i]->getVertex(0)->getIndex() - 1,
                (int)gf->triangles[i]->getVertex(1)->getIndex() - 1,
                (int)gf->triangles[i]->getVertex(2)->getIndex() - 1);
      for(std::size_t i = 0; i < gf->quadrangles.size(); i++)
        fprintf(fp, "4 %d %d %d %d\n",
                (int)gf->quadrangles[i]->getVertex(0)->getIndex() - 1,
                (int)gf->quadrangles[i]->getVertex(1)->getIndex() - 1,
                (int)gf->quadrangles[i]->getVertex(2)->getIndex() - 1,
                (int)gf->quadrangles[i]->getVertex(3)->getIndex() - 1);
    }
  }

  fclose(fp);
  return 1;
}
