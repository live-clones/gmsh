// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include <stdlib.h>
#include <string.h>
#include "GModel.h"
#include "OS.h"
#include "MElement.h"

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

int GModel::writeSU2(const std::string &name, bool saveAll, double scalingFactor)
{
  FILE *fp = Fopen(name.c_str(), "w");
  if(!fp){
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  int ndime = getDim();
  if(ndime != 2 && ndime != 3){
    Msg::Error("SU2 mesh output valid only for 2D or 3D models (not %dD)", ndime);
    fclose(fp);
    return 0;
  }

  if(noPhysicalGroups()) saveAll = true;

  fprintf(fp, "NDIME= %d\n", ndime);

  // all interior elements are printed in a single section; indices start at 0;
  // node ordering is the same as VTK
  int nelem = 0;
  if(ndime == 2){
    for(fiter it = firstFace(); it != lastFace(); it++)
      if(saveAll || (*it)->physicals.size()) nelem += (*it)->getNumMeshElements();
  }
  else{
    for(riter it = firstRegion(); it != lastRegion(); it++)
      if(saveAll || (*it)->physicals.size()) nelem += (*it)->getNumMeshElements();
  }
  int npoin = indexMeshVertices(saveAll);

  Msg::Info("Writing %d elements and %d vertices", nelem, npoin);

  // elements
  fprintf(fp, "NELEM= %d\n", nelem);
  int num = 0;
  if(ndime == 2){
    for(fiter it = firstFace(); it != lastFace(); it++)
      if(saveAll || (*it)->physicals.size())
        for(unsigned int i = 0; i < (*it)->getNumMeshElements(); i++)
          (*it)->getMeshElement(i)->writeSU2(fp, num++);
  }
  else{
    for(riter it = firstRegion(); it != lastRegion(); it++)
      if(saveAll || (*it)->physicals.size())
        for(unsigned int i = 0; i < (*it)->getNumMeshElements(); i++)
          (*it)->getMeshElement(i)->writeSU2(fp, num++);
  }

  // vertices
  fprintf(fp, "NPOIN= %d\n", npoin);
  std::vector<GEntity*> entities;
  getEntities(entities);
  for(unsigned int i = 0; i < entities.size(); i++)
    for(unsigned int j = 0; j < entities[i]->mesh_vertices.size(); j++)
      entities[i]->mesh_vertices[j]->writeSU2(fp, ndime, scalingFactor);

  // markers for physical groups of dimension (ndime - 1)
  std::map<int, std::vector<GEntity*> > groups[4];
  getPhysicalGroups(groups);
  int nmark = groups[ndime - 1].size();
  if(nmark){
    fprintf(fp, "NMARK= %d\n", nmark);
    for(std::map<int, std::vector<GEntity*> >::iterator it = groups[ndime - 1].begin();
        it != groups[ndime - 1].end(); it++){
      std::vector<GEntity *> &entities = it->second;
      int n = 0;
      for(unsigned int i = 0; i < entities.size(); i++)
        n += entities[i]->getNumMeshElements();
      if(n){
        fprintf(fp, "MARKER_TAG= %s\n", physicalName(this, ndime - 1, it->first).c_str());
        fprintf(fp, "MARKER_ELEMS= %d\n", n);
        for(unsigned int i = 0; i < entities.size(); i++)
          for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++)
            entities[i]->getMeshElement(j)->writeSU2(fp, -1);
      }
    }
  }

  fclose(fp);
  return 1;
}
