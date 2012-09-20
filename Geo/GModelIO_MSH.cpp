// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GModel.h"
#include "GmshMessage.h"
#include "MElement.h"
#include "MPoint.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"

int GModel::readMSH(const std::string &name)
{
  double version = 2.2;
  if(version < 3)
    return _readMSH2(name);

  return 0;
}

static int getNumElementsMSH(GEntity *ge, bool saveAll, int saveSinglePartition)
{
  if(!saveAll && ge->physicals.empty()) return 0;

  int n = 0;
  if(saveSinglePartition <= 0)
    n = ge->getNumMeshElements();
  else
    for(unsigned int i = 0; i < ge->getNumMeshElements(); i++)
      if(ge->getMeshElement(i)->getPartition() == saveSinglePartition)
        n++;
  return n;
}

static void writeElementMSH(FILE *fp, GModel *model, MElement *ele, bool binary,
                            int elementary)
{
  if(model->getGhostCells().size()){
    std::vector<short> ghosts;
    std::pair<std::multimap<MElement*, short>::iterator,
              std::multimap<MElement*, short>::iterator> itp =
      model->getGhostCells().equal_range(ele);
    for(std::multimap<MElement*, short>::iterator it = itp.first;
        it != itp.second; it++)
      ghosts.push_back(it->second);
    ele->writeMSH(fp, binary, elementary, &ghosts);
  }
  else
    ele->writeMSH(fp, binary, elementary);
}

template<class T>
static void writeElementsMSH(FILE *fp, GModel *model, GEntity *ge, std::vector<T*> &ele,
                             bool saveAll, int saveSinglePartition, bool binary)
{
  if(!saveAll && ge->physicals.empty()) return;

  for(unsigned int i = 0; i < ele.size(); i++){
    if(saveSinglePartition && ele[i]->getPartition() != saveSinglePartition)
      continue;
    writeElementMSH(fp, model, ele[i], binary, ge->tag());
  }
}

int GModel::writeMSH(const std::string &name, double version, bool binary,
                     bool saveAll, bool saveParametric,
                     double scalingFactor, int elementStartNum,
                     int saveSinglePartition)
{
  if(version < 3)
    return _writeMSH2(name, version, binary, saveAll, saveParametric,
                      scalingFactor, elementStartNum, saveSinglePartition);

  FILE *fp = fopen(name.c_str(), binary ? "wb" : "w");
  if(!fp){
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  // if there are no physicals we save all the elements
  if(noPhysicalGroups()) saveAll = true;

  // get the number of vertices and index the vertices in a continuous
  // sequence
  int numVertices = indexMeshVertices(saveAll, saveSinglePartition);

  // get the number of elements we need to save
  std::vector<GEntity*> entities;
  getEntities(entities);
  int numElements = 0;
  for(unsigned int i = 0; i < entities.size(); i++)
    numElements += getNumElementsMSH(entities[i], saveAll, saveSinglePartition);

  fprintf(fp, "$MeshFormat\n");
  fprintf(fp, "%g %d %d\n", version, binary ? 1 : 0, (int)sizeof(double));
  if(binary){
    int one = 1;
    fwrite(&one, sizeof(int), 1, fp);
    fprintf(fp, "\n");
  }
  fprintf(fp, "$EndMeshFormat\n");

  if(numPhysicalNames()){
    fprintf(fp, "$PhysicalNames\n");
    fprintf(fp, "%d\n", numPhysicalNames());
    for(piter it = firstPhysicalName(); it != lastPhysicalName(); it++)
      fprintf(fp, "%d %d \"%s\"\n", it->first.first, it->first.second,
              it->second.c_str());
    fprintf(fp, "$EndPhysicalNames\n");
  }

  fprintf(fp, "$Entities\n");
  std::vector<GEntity*> entitiesWithPhysical;
  if(saveAll)
    entitiesWithPhysical = entities;
  else{
    for(unsigned int i = 0; i < entities.size(); i++){
      GEntity *ge = entities[i];
      std::vector<int> physicallist = ge->getPhysicalEntities();
      if(physicallist.size()) entitiesWithPhysical.push_back(ge);
    }
  }
  fprintf(fp, "%d\n", (int)entitiesWithPhysical.size());
  for(unsigned int i = 0; i < entitiesWithPhysical.size(); i++){
    GEntity *ge = entitiesWithPhysical[i];
    std::vector<int> physicallist = ge->getPhysicalEntities();
    fprintf(fp, "%d %d %d", ge->tag(), ge->dim(), (int)physicallist.size());
    for(unsigned int j = 0; j < physicallist.size(); j++)
      fprintf(fp, " %d", physicallist[j]);
    fprintf(fp, "\n");
  }
  fprintf(fp, "$EndEntities\n");

  fprintf(fp, "$Nodes\n");
  fprintf(fp, "%d\n", numVertices);
  for(unsigned int i = 0; i < entities.size(); i++)
    for(unsigned int j = 0; j < entities[i]->mesh_vertices.size(); j++)
      entities[i]->mesh_vertices[j]->writeMSH(fp, binary, scalingFactor);

  if(binary) fprintf(fp, "\n");
  fprintf(fp, "$EndNodes\n");

  fprintf(fp, "$Elements\n");
  fprintf(fp, "%d\n", numElements);

  _elementIndexCache.clear();

  for(viter it = firstVertex(); it != lastVertex(); ++it)
    writeElementsMSH(fp, this, *it, (*it)->points, saveAll, saveSinglePartition,
                     binary);
  for(eiter it = firstEdge(); it != lastEdge(); ++it)
    writeElementsMSH(fp, this, *it, (*it)->lines, saveAll, saveSinglePartition,
                     binary);
  for(fiter it = firstFace(); it != lastFace(); ++it)
    writeElementsMSH(fp, this, *it, (*it)->triangles, saveAll, saveSinglePartition,
                     binary);
  for(fiter it = firstFace(); it != lastFace(); ++it)
    writeElementsMSH(fp, this, *it, (*it)->quadrangles, saveAll, saveSinglePartition,
                     binary);
  for(riter it = firstRegion(); it != lastRegion(); ++it)
    writeElementsMSH(fp, this, *it, (*it)->tetrahedra, saveAll, saveSinglePartition,
                     binary);
  for(riter it = firstRegion(); it != lastRegion(); ++it)
    writeElementsMSH(fp, this, *it, (*it)->hexahedra, saveAll, saveSinglePartition,
                     binary);
  for(riter it = firstRegion(); it != lastRegion(); ++it)
    writeElementsMSH(fp, this, *it, (*it)->prisms, saveAll, saveSinglePartition,
                     binary);
  for(riter it = firstRegion(); it != lastRegion(); ++it)
    writeElementsMSH(fp, this, *it, (*it)->pyramids, saveAll, saveSinglePartition,
                     binary);

  if(binary) fprintf(fp, "\n");

  fprintf(fp, "$EndElements\n");
  fclose(fp);

  return 1;
}
