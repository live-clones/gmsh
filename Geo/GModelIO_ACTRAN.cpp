// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdlib.h>
#include <string.h>
#include "GModel.h"
#include "OS.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "Context.h"

static bool getMeshVertices(GModel *m, int num, int *n,
                            std::vector<MVertex *> &vec)
{
  for(int i = 0; i < num; i++) {
    MVertex *v = m->getMeshVertexByTag(n[i]);
    if(!v) {
      Msg::Error("Wrong node tag %d", n[i]);
      return false;
    }
    else
      vec.push_back(v);
  }
  return true;
}

int GModel::readACTRAN(const std::string &name)
{
  FILE *fp = Fopen(name.c_str(), "r");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  char buffer[256];
  if(!fgets(buffer, sizeof(buffer), fp)) {
    fclose(fp);
    return 0;
  }

  if(strncmp(buffer, "BEGIN ACTRAN", 12)) {
    Msg::Error("Did not find ACTRAN header");
    fclose(fp);
    return 0;
  }

  _vertexMapCache.clear();
  std::map<int, std::vector<MElement *> > elements[3];
  int nbv = 0, nbe = 0, dim = 0;

  while(!feof(fp)) {
    if(!fgets(buffer, 256, fp)) break;
    char str[256], str2[256];
    sscanf(buffer, "%s %s", str, str2);
    if(!strcmp(str, "BEGIN") && !strcmp(str2, "MESH")) {
      if(!fgets(buffer, sizeof(buffer), fp)) break;
      sscanf(buffer, "%d %d %d", &nbv, &nbe, &dim);
      if(dim == 3 || dim == 2)
        Msg::Info("ACTRAN mesh dimension %d", dim);
      else {
        Msg::Error("Cannot read ACTRAN mesh of dimension %d", dim);
        break;
      }
    }
    else if(!strcmp(str, "BEGIN") && !strcmp(str2, "NODE")) {
      Msg::Info("%d nodes", nbv);
      for(int i = 0; i < nbv; i++) {
        if(!fgets(buffer, sizeof(buffer), fp)) break;
        int num;
        double x, y, z = 0.;
        if(dim == 3)
          sscanf(buffer, "%d %lf %lf %lf", &num, &x, &y, &z);
        else
          sscanf(buffer, "%d %lf %lf", &num, &x, &y);
        _vertexMapCache[num] = new MVertex(x, y, z, nullptr, num);
      }
    }
    else if(!strcmp(str, "BEGIN") && !strcmp(str2, "ELEMENT")) {
      Msg::Info("%d elements", nbe);
      for(int i = 0; i < nbe; i++) {
        if(!fgets(buffer, sizeof(buffer), fp)) break;
        int num, type, reg, n[8];
        sscanf(buffer, "%d %d %d", &num, &type, &reg);
        std::vector<MVertex *> vertices;
        if(type == 2) {
          sscanf(buffer, "%d %d %d %d %d", &num, &type, &reg, &n[0], &n[1]);
          if(!getMeshVertices(this, 2, n, vertices)) break;
          elements[0][reg].push_back(new MLine(vertices, num));
        }
        else if(type == 4) {
          sscanf(buffer, "%d %d %d %d %d %d", &num, &type, &reg, &n[0], &n[1],
                 &n[2]);
          if(!getMeshVertices(this, 3, n, vertices)) break;
          elements[0][reg].push_back(new MTriangle(vertices, num));
        }
        else if(type == 8) {
          sscanf(buffer, "%d %d %d %d %d %d %d", &num, &type, &reg, &n[0],
                 &n[1], &n[2], &n[3]);
          if(!getMeshVertices(this, 4, n, vertices)) break;
          elements[1][reg].push_back(new MTetrahedron(vertices, num));
        }
        else {
          Msg::Error("Unknown type %d for element %d", type, num);
        }
      }
    }
  }

  for(int i = 0; i < (int)(sizeof(elements) / sizeof(elements[0])); i++)
    _storeElementsInEntities(elements[i]);
  _associateEntityWithMeshVertices();
  _storeVerticesInEntities(_vertexMapCache);

  fclose(fp);
  return 1;
}
