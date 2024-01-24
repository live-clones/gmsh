// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GModel.h"
#include "OS.h"
#include "MElement.h"

int GModel::writeIR3(const std::string &name, int elementTagType, bool saveAll,
                     double scalingFactor)
{
  FILE *fp = Fopen(name.c_str(), "w");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  if(noPhysicalGroups()) saveAll = true;

  int numVertices = indexMeshVertices(saveAll), num2D = 0, num3D = 0;
  for(auto it = firstFace(); it != lastFace(); ++it)
    if(saveAll || (*it)->physicals.size()) num2D += (*it)->getNumMeshElements();
  for(auto it = firstRegion(); it != lastRegion(); ++it)
    if(saveAll || (*it)->physicals.size()) num3D += (*it)->getNumMeshElements();

  fprintf(fp, "33\n");
  if(num2D && num3D)
    fprintf(fp, "%d %d %d\n", numVertices, num2D, num3D);
  else
    fprintf(fp, "%d %d\n", numVertices, num2D ? num2D : num3D);

  std::vector<GEntity *> entities;
  getEntities(entities);

  for(std::size_t i = 0; i < entities.size(); i++)
    for(std::size_t j = 0; j < entities[i]->mesh_vertices.size(); j++)
      if(entities[i]->mesh_vertices[j]->getIndex() >= 0)
        fprintf(fp, "%ld %.16g %.16g %.16g\n",
                entities[i]->mesh_vertices[j]->getIndex(),
                entities[i]->mesh_vertices[j]->x() * scalingFactor,
                entities[i]->mesh_vertices[j]->y() * scalingFactor,
                entities[i]->mesh_vertices[j]->z() * scalingFactor);

  int iElement = 1;
  for(auto it = firstFace(); it != lastFace(); ++it) {
    int numPhys = (*it)->physicals.size();
    if(saveAll || numPhys)
      for(std::size_t i = 0; i < (*it)->getNumMeshElements(); i++)
        (*it)->getMeshElement(i)->writeIR3(fp, elementTagType, iElement++,
                                           (*it)->tag(),
                                           numPhys ? (*it)->physicals[0] : 0);
  }

  iElement = 1;
  for(auto it = firstRegion(); it != lastRegion(); ++it) {
    int numPhys = (*it)->physicals.size();
    if(saveAll || numPhys)
      for(std::size_t i = 0; i < (*it)->getNumMeshElements(); i++)
        (*it)->getMeshElement(i)->writeIR3(fp, elementTagType, iElement++,
                                           (*it)->tag(),
                                           numPhys ? (*it)->physicals[0] : 0);
  }

  fclose(fp);
  return 1;
}
