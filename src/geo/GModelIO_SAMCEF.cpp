// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdlib.h>
#include <string.h>
#include <sstream>
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
      Msg::Error("Wrong node number %d", n[i]);
      return false;
    }
    else
      vec.push_back(v);
  }
  return true;
}

int GModel::readSAMCEF(const std::string &name)
{
  FILE *fp = Fopen(name.c_str(), "r");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  _vertexMapCache.clear();
  std::map<int, std::vector<MElement *> > elements[2];
  char buffer[256], dummy[256];

  while(!feof(fp)) {
    if(!fgets(buffer, 256, fp)) break;
    if(!strncmp(buffer, ".NOE", 4)) {
      while(!feof(fp)) {
        if(!fgets(buffer, 256, fp)) break;
        if(buffer[0] == '!') continue;
        if(buffer[0] == ';') break;
        int num;
        double x, y, z;
        if(sscanf(buffer, "%s %d %s %lf %s %lf %s %lf", dummy, &num, dummy, &x,
                  dummy, &y, dummy, &z) != 8)
          return 0;
        _vertexMapCache[num] = new MVertex(x, y, z, nullptr, num);
      }
      Msg::Info("Read %d mesh nodes", (int)_vertexMapCache.size());
    }
    else if(!strncmp(buffer, ".MAI", 4)) {
      while(!feof(fp)) {
        if(!fgets(buffer, 256, fp)) break;
        if(buffer[0] == '!') continue;
        if(buffer[0] == ';') break;
        std::stringstream s(buffer);
        std::string word;
        int nn = 0;
        while(s >> word) nn++;
        int num, reg, n[4];
        std::vector<MVertex *> vertices;
        if(nn == 8) { // TRIA3
          if(sscanf(buffer, "%s %d %s %d %s %d %d %d", dummy, &num, dummy, &reg,
                    dummy, &n[0], &n[1], &n[2]) != 8)
            return 0;
          if(!getMeshVertices(this, 3, n, vertices)) break;
          elements[0][reg].push_back(new MTriangle(vertices, num));
        }
        else if(nn == 9) { // QUAD4
          if(sscanf(buffer, "%s %d %s %d %s %d %d %d %d", dummy, &num, dummy,
                    &reg, dummy, &n[0], &n[1], &n[2], &n[3]) != 9)
            return 0;
          if(!getMeshVertices(this, 4, n, vertices)) break;
          elements[1][reg].push_back(new MQuadrangle(vertices, num));
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
