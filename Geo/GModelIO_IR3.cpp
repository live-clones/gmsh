// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GModel.h"
#include "MElement.h"

int GModel::writeIR3(const std::string &name, int elementTagType,
                     bool saveAll, double scalingFactor)
{
  FILE *fp = fopen(name.c_str(), "w");
  if(!fp){
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  if(noPhysicalGroups()) saveAll = true;

  int numVertices = indexMeshVertices(saveAll), num2D = 0, num3D = 0;
  for(fiter it = firstFace(); it != lastFace(); ++it)
    if(saveAll || (*it)->physicals.size())
      num2D += (*it)->getNumMeshElements();
  for(riter it = firstRegion(); it != lastRegion(); ++it)
    if(saveAll || (*it)->physicals.size())
      num3D += (*it)->getNumMeshElements();

  fprintf(fp,"33\n");
  if(num2D && num3D)
    fprintf(fp,"%d %d %d\n", numVertices, num2D, num3D);
  else
    fprintf(fp,"%d %d\n", numVertices, num2D ? num2D : num3D);

  std::vector<GEntity*> entities;
  getEntities(entities);

  for(unsigned int i = 0; i < entities.size(); i++)
    for(unsigned int j = 0; j < entities[i]->mesh_vertices.size(); j++)
      if(entities[i]->mesh_vertices[j]->getIndex() >= 0)
        fprintf(fp,"%d %.16g %.16g %.16g\n", entities[i]->mesh_vertices[j]->getIndex(),
                entities[i]->mesh_vertices[j]->x() * scalingFactor,
                entities[i]->mesh_vertices[j]->y() * scalingFactor,
                entities[i]->mesh_vertices[j]->z() * scalingFactor);

  int iElement = 1;
  for(fiter it = firstFace(); it != lastFace(); ++it){
    int numPhys = (*it)->physicals.size();
    if(saveAll || numPhys)
      for(unsigned int i = 0; i < (*it)->getNumMeshElements(); i++)
        (*it)->getMeshElement(i)->writeIR3
          (fp, elementTagType, iElement++, (*it)->tag(),
           numPhys ? (*it)->physicals[0] : 0);
  }

  iElement = 1;
  for(riter it = firstRegion(); it != lastRegion(); ++it){
    int numPhys = (*it)->physicals.size();
    if(saveAll || numPhys)
      for(unsigned int i = 0; i < (*it)->getNumMeshElements(); i++)
        (*it)->getMeshElement(i)->writeIR3
          (fp, elementTagType, iElement++, (*it)->tag(),
           numPhys ? (*it)->physicals[0] : 0);
  }

  fclose(fp);
  return 1;
}

