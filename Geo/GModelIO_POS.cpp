// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <stdio.h>
#include "GModel.h"
#include "MElement.h"

int GModel::writePOS(const std::string &name, bool printElementary,
                     bool printElementNumber, bool printGamma, bool printEta,
                     bool printRho, bool printDisto,
                     bool saveAll, double scalingFactor)
{
  FILE *fp = fopen(name.c_str(), "w");
  if(!fp){
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  /*
  bool printVertices = true;
  if(printVertices){
    fprintf(fp, "View \"Vertices\" {\n");
    std::vector<GEntity*> entities;
    getEntities(entities);
    for(unsigned int i = 0; i < entities.size(); i++)
      for(unsigned int j = 0; j < entities[i]->mesh_vertices.size(); j++){
        MVertex *v = entities[i]->mesh_vertices[j];
        fprintf(fp, "SP(%g,%g,%g){1};\n", v->x(), v->y(), v->z());
      }
    fprintf(fp, "};\n");
    fclose(fp);
    return 1;
  }
  */

  bool f[6] = {printElementary, printElementNumber, printGamma, printEta, printRho,
               printDisto};

  bool first = true;
  std::string names;
  if(f[0]){
    if(first) first = false; else names += ",";
    names += "\"Elementary Entity\"";
  }
  if(f[1]){
    if(first) first = false; else names += ",";
    names += "\"Element Number\"";
  }
  if(f[2]){
    if(first) first = false; else names += ",";
    names += "\"Gamma\"";
  }
  if(f[3]){
    if(first) first = false; else names += ",";
    names += "\"Eta\"";
  }
  if(f[4]){
    if(first) first = false; else names += ",";
    names += "\"Rho\"";
  }
  if(f[5]){
    if(first) first = false; else names += ",";
    names += "\"Disto\"";
  }

  if(names.empty()) return 0;

  if(noPhysicalGroups()) saveAll = true;

  fprintf(fp, "View \"Statistics\" {\n");
  fprintf(fp, "T2(1.e5,30,%d){%s};\n", (1<<16)|(4<<8), names.c_str());

  std::vector<GEntity*> entities;
  getEntities(entities);
  for(unsigned int i = 0; i < entities.size(); i++)
    if(saveAll || entities[i]->physicals.size())
      for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++)
        entities[i]->getMeshElement(j)->writePOS
          (fp, f[0], f[1], f[2], f[3], f[4], f[5], scalingFactor, entities[i]->tag());
  fprintf(fp, "};\n");

  fclose(fp);
  return 1;
}

