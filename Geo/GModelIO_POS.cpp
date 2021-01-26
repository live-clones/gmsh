// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdio.h>
#include "GModel.h"
#include "OS.h"
#include "MElement.h"

int GModel::writePOS(const std::string &name, bool printElementary,
                     bool printElementNumber, bool printSICN, bool printSIGE,
                     bool printGamma, bool printDisto, bool saveAll,
                     double scalingFactor)
{
  FILE *fp = Fopen(name.c_str(), "w");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  /*
  bool printVertices = true;
  if(printVertices){
    fprintf(fp, "View \"Vertices\" {\n");
    std::vector<GEntity*> entities;
    getEntities(entities);
    for(std::size_t i = 0; i < entities.size(); i++)
      for(std::size_t j = 0; j < entities[i]->mesh_vertices.size(); j++){
        MVertex *v = entities[i]->mesh_vertices[j];
        fprintf(fp, "SP(%g,%g,%g){1};\n", v->x(), v->y(), v->z());
      }
    fprintf(fp, "};\n");
    fclose(fp);
    return 1;
  }
  */

  bool first = true;
  std::string names;
  if(printElementary) {
    if(first)
      first = false;
    else
      names += ",";
    names += "\"Elementary Entity\"";
  }
  if(printElementNumber) {
    if(first)
      first = false;
    else
      names += ",";
    names += "\"Element Number\"";
  }
  if(printSICN) {
    if(first)
      first = false;
    else
      names += ",";
    names += "\"SICN\"";
  }
  if(printSIGE) {
    if(first)
      first = false;
    else
      names += ",";
    names += "\"SIGE\"";
  }
  if(printGamma) {
    if(first)
      first = false;
    else
      names += ",";
    names += "\"Gamma\"";
  }
  if(printDisto) {
    if(first)
      first = false;
    else
      names += ",";
    names += "\"Disto\"";
  }

  if(names.empty()) {
    fclose(fp);
    return 0;
  }

  if(noPhysicalGroups()) saveAll = true;

  fprintf(fp, "View \"Statistics\" {\n");
  fprintf(fp, "T2(1.e5,30,%d){%s};\n", (1 << 16) | (4 << 8), names.c_str());

  std::vector<GEntity *> entities;
  getEntities(entities);
  for(std::size_t i = 0; i < entities.size(); i++)
    if(saveAll || entities[i]->physicals.size())
      for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++)
        entities[i]->getMeshElement(j)->writePOS(
          fp, printElementary, printElementNumber, printSICN, printSIGE,
          printGamma, printDisto, scalingFactor, entities[i]->tag());
  fprintf(fp, "};\n");

  fclose(fp);
  return 1;
}
