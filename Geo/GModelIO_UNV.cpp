// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include <stdlib.h>
#include <string.h>
#include "GModel.h"
#include "OS.h"
#include "GmshIO.h"

#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "Context.h"

int GModel::readUNV(const std::string &name)
{
  gmshFILE fp = gmshopen(name.c_str(), "r");
  if(!fp){
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  char buffer[256];
  std::map<int, std::vector<MElement*> > elements[7];
  std::map<int, std::map<int, std::string> > physicals[4];

  _vertexMapCache.clear();

  while(!gmsheof(fp)) {
    if(!gmshgets(buffer, sizeof(buffer), fp)) break;
    if(!strncmp(buffer, "    -1", 6)){
      if(!gmshgets(buffer, sizeof(buffer), fp)) break;
      if(!strncmp(buffer, "    -1", 6))
        if(!gmshgets(buffer, sizeof(buffer), fp)) break;
      int record = 0;
      sscanf(buffer, "%d", &record);
      if(record == 2411){ // nodes
        Msg::Info("Reading nodes");
        while(gmshgets(buffer, sizeof(buffer), fp)){
          if(!strncmp(buffer, "    -1", 6)) break;
          int num, dum;
          if(sscanf(buffer, "%d %d %d %d", &num, &dum, &dum, &dum) != 4) break;
          if(!gmshgets(buffer, sizeof(buffer), fp)) break;
          double x, y, z;
          for(unsigned int i = 0; i < strlen(buffer); i++)
            if(buffer[i] == 'D') buffer[i] = 'E';
          if(sscanf(buffer, "%lf %lf %lf", &x, &y, &z) != 3) break;
          _vertexMapCache[num] = new MVertex(x, y, z, 0, num);
        }
      }
      else if(record == 2412){ // elements
        Msg::Info("Reading elements");
        std::map<int, int> warn;
        while(gmshgets(buffer, sizeof(buffer), fp)){
          if(strlen(buffer) < 3) continue; // possible line ending after last fscanf
          if(!strncmp(buffer, "    -1", 6)) break;
          int num, type, elementary, physical, color, numNodes;
	  if(!CTX::instance()->mesh.switchElementTags) {
            if(sscanf(buffer, "%d %d %d %d %d %d", &num, &type, &elementary, &physical,
                      &color, &numNodes) != 6) break;
	  }
          else {
            if(sscanf(buffer, "%d %d %d %d %d %d", &num, &type, &physical, &elementary,
                      &color, &numNodes) != 6) break;
	  }
          if(elementary < 0) elementary = getMaxElementaryNumber(-1) + 1;
          if(physical < 0) physical = 0;
          if(!type){
            if(warn[type]++ == 1)
              Msg::Warning("No element type: guessing from number of nodes");
            switch(numNodes){
            case 2: type = 11; break; // line
            case 3: type = 41; break; // tri
            case 4: type = 111; break; // tet
            }
          }

          switch(type){
          case 11: case 21: case 22: case 31:
          case 23: case 24: case 32:
            // beam elements
            if(!gmshgets(buffer, sizeof(buffer), fp)) break;
            int dum;
            if(sscanf(buffer, "%d %d %d", &dum, &dum, &dum) != 3) break;
            break;
          }
          std::vector<MVertex*> vertices(numNodes);
          for(int i = 0; i < numNodes; i++){
            int n;
            if(!gmshgets(buffer, 11, fp)){ gmshclose(fp); return 0; }
            if(strlen(buffer) < 10)
                if(!gmshgets(buffer, 11, fp)){ gmshclose(fp); return 0; }
            if(!sscanf(buffer, "%d", &n)){ gmshclose(fp); return 0; }
            vertices[i] = getMeshVertexByTag(n);
            if(!vertices[i]){
              Msg::Error("Wrong vertex index %d", n);
              gmshclose(fp);
              return 0;
            }
          }
          int dim = -1;
          switch(type){
          case 11: case 21: case 22: case 31:
            elements[0][elementary].push_back(new MLine(vertices, num));
            dim = 1;
            break;
          case 23: case 24: case 32:
            elements[0][elementary].push_back
              (new MLine3(vertices[0], vertices[2], vertices[1], num));
            dim = 1;
            break;
          case 41: case 51: case 61: case 74: case 81: case 91:
            elements[1][elementary].push_back(new MTriangle(vertices, num));
            dim = 2;
            break;
          case 42: case 52: case 62: case 72: case 82: case 92:
            elements[1][elementary].push_back
              (new MTriangle6(vertices[0], vertices[2], vertices[4], vertices[1],
                              vertices[3], vertices[5], num));
            dim = 2;
            break;
          case 44: case 54: case 64: case 71: case 84: case 94:
            elements[2][elementary].push_back(new MQuadrangle(vertices, num));
            dim = 2;
            break;
          case 45: case 55: case 65: case 75: case 85: case 95:
            elements[2][elementary].push_back
              (new MQuadrangle8(vertices[0], vertices[2], vertices[4], vertices[6],
                                vertices[1], vertices[3], vertices[5], vertices[7],
                                num));
            dim = 2;
            break;
          case 111:
            elements[3][elementary].push_back(new MTetrahedron(vertices, num));
            dim = 3;
            break;
          case 118:
            elements[3][elementary].push_back
              (new MTetrahedron10(vertices[0], vertices[2], vertices[4], vertices[9],
                                  vertices[1], vertices[3], vertices[5], vertices[6],
                                  vertices[8], vertices[7], num));
            dim = 3;
            break;
          case 104: case 115:
            elements[4][elementary].push_back(new MHexahedron(vertices, num));
            dim = 3;
            break;
          case 105: case 116:
            elements[4][elementary].push_back
              (new MHexahedron20(vertices[0], vertices[2], vertices[4], vertices[6],
                                 vertices[12], vertices[14], vertices[16], vertices[18],
                                 vertices[1], vertices[7], vertices[8], vertices[3],
                                 vertices[9], vertices[5], vertices[10], vertices[11],
                                 vertices[13], vertices[19], vertices[15], vertices[17],
                                 num));
            dim = 3;
            break;
          case 101: case 112:
            elements[5][elementary].push_back(new MPrism(vertices, num));
            dim = 3;
            break;
          case 102: case 113:
            elements[5][elementary].push_back
              (new MPrism15(vertices[0], vertices[2], vertices[4], vertices[9],
                            vertices[11], vertices[13], vertices[1], vertices[5],
                            vertices[6], vertices[3], vertices[7], vertices[8],
                            vertices[10], vertices[14], vertices[12], num));
            dim = 3;
            break;
          default:
            if(warn[type]++ == 1)
              Msg::Warning("Skipping unknown type of element %d", type);
            break;
          }

          if(dim >= 0 && physical && (!physicals[dim].count(elementary) ||
                                      !physicals[dim][elementary].count(physical)))
            physicals[dim][elementary][physical] = "unnamed";
        }
      }
      else if(record == 2477){ // groups elements
        Msg::Info("Discarding element/node groups: currently still reading physical "
                  "tags directly from elements");
      }
    }
  }

  for(int i = 0; i < (int)(sizeof(elements) / sizeof(elements[0])); i++)
    _storeElementsInEntities(elements[i]);
  _associateEntityWithMeshVertices();
  _storeVerticesInEntities(_vertexMapCache);

  for(int i = 0; i < 4; i++)
    _storePhysicalTagsInEntities(i, physicals[i]);

  gmshclose(fp);
  return 1;
}

static std::string physicalName(GModel *m, int dim, int num)
{
  std::string name = m->getPhysicalName(dim, num);
  if(name.empty()){
    char tmp[256];
    sprintf(tmp, "%s%d", (dim == 3) ? "PhysicalVolume" :
            (dim == 2) ? "PhysicalSurface" : "PhysicalLine", num);
    name = tmp;
  }
  for(unsigned int i = 0; i < name.size(); i++)
    if(name[i] == ' ') name[i] = '_';
  return name;
}

int GModel::writeUNV(const std::string &name, bool saveAll, bool saveGroupsOfNodes,
                     double scalingFactor)
{
  FILE *fp = Fopen(name.c_str(), "w");
  if(!fp){
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  if(noPhysicalGroups()) saveAll = true;

  indexMeshVertices(saveAll);

  std::vector<GEntity*> entities;
  getEntities(entities);

  // nodes
  fprintf(fp, "%6d\n", -1);
  fprintf(fp, "%6d\n", 2411);
  for(unsigned int i = 0; i < entities.size(); i++)
    for(unsigned int j = 0; j < entities[i]->mesh_vertices.size(); j++)
      entities[i]->mesh_vertices[j]->writeUNV(fp, scalingFactor);
  fprintf(fp, "%6d\n", -1);

  // elements
  fprintf(fp, "%6d\n", -1);
  fprintf(fp, "%6d\n", 2412);
  for(unsigned int i = 0; i < entities.size(); i++){
    if(saveAll || entities[i]->physicals.size()){
      for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++){
        MElement *e = entities[i]->getMeshElement(j);
        e->writeUNV(fp, e->getNum(), entities[i]->tag(), 0);
      }
    }
  }
  fprintf(fp, "%6d\n", -1);

  std::map<int, std::vector<GEntity*> > groups[4];
  getPhysicalGroups(groups);

  // save groups of elements (and groups of nodes if requested) for each
  // physical
  fprintf(fp, "%6d\n", -1);
  fprintf(fp, "%6d\n", 2477);
  for(int dim = 0; dim <= 3; dim++){
    for(std::map<int, std::vector<GEntity*> >::iterator it = groups[dim].begin();
        it != groups[dim].end(); it++){
      std::vector<GEntity *> &entities = it->second;

      std::set<MVertex*> nodes;
      if(saveGroupsOfNodes){
        for(unsigned int i = 0; i < entities.size(); i++){
          for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++){
            MElement *e = entities[i]->getMeshElement(j);
            for (int k = 0; k < e->getNumVertices(); k++)
              nodes.insert(e->getVertex(k));
          }
        }
      }

      int nele = 0;
      for(unsigned int i = 0; i < entities.size(); i++)
        nele += entities[i]->getNumMeshElements();

      fprintf(fp, "%10d%10d%10d%10d%10d%10d%10d%10d\n",
              it->first, 0, 0, 0, 0, 0, 0, (int)nodes.size() + nele);
      fprintf(fp, "%s\n", physicalName(this, dim, it->first).c_str());

      if(saveGroupsOfNodes){
        int row = 0;
        for(std::set<MVertex*>::iterator it2 = nodes.begin(); it2 != nodes.end(); it2++){
          if(row == 2) {
            fprintf(fp, "\n");
            row = 0;
          }
          fprintf(fp, "%10d%10d%10d%10d", 7, (*it2)->getIndex(), 0, 0);
          row++;
        }
        fprintf(fp, "\n");
      }

      {
        int row = 0;
        for(unsigned int i = 0; i < entities.size(); i++){
          for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++){
            MElement *e = entities[i]->getMeshElement(j);
            if(row == 2) {
              fprintf(fp, "\n");
              row = 0;
            }
            fprintf(fp, "%10d%10d%10d%10d", 8, e->getNum(), 0, 0);
            row++;
          }
        }
        fprintf(fp, "\n");
      }
    }
  }
  fprintf(fp, "%6d\n", -1);

  fclose(fp);
  return 1;
}
