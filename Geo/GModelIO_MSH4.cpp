// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include <cstdio>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

#include "GmshDefines.h"
#include "OS.h"
#include "Context.h"
#include "GModel.h"
#include "GEntity.h"
#include "partitionRegion.h"
#include "partitionFace.h"
#include "partitionEdge.h"
#include "partitionVertex.h"
#include "MPoint.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "MTrihedron.h"
#include "meshPartition.h"

//Write functions
void writeMSH4Entities(GModel *const model, FILE* fp, bool partition, bool binary, double scalingFactor);
void writeMSH4Physicals(FILE* fp, GEntity *const entity, bool binary);
void writeMSH4Nodes(GModel *const model, FILE* fp, bool partitioned, bool binary, bool saveParametric, double scalingFactor);
void writeMSH4Elements(GModel *const model, FILE* fp, bool partitioned, bool binary, bool saveAll);
void writeMSH4PeriodicNodes(GModel *const model, FILE* fp, bool partitioned, bool binary);

int GModel::_readMSH4(const std::string &name)
{
  return 1;
}

/********************************************************
 *
 *    Write functions
 *
 ********************************************************/

int GModel::_writeMSH4(const std::string &name, double version, bool binary, bool saveAll, bool saveParametric, double scalingFactor)
{
  FILE *fp = Fopen(name.c_str(), binary ? "wb" : "w");
  
  if(!fp)
  {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }
  
  // if there are no physicals we save all the elements
  if(noPhysicalGroups()) saveAll = true;
  
  // header
  fprintf(fp, "$MeshFormat\n");
  fprintf(fp, "%g %d %ld %ld\n", version, (binary ? 1 : 0), sizeof(double), sizeof(int));
  if(binary)
  {
    int one = 1;
    fwrite(&one, sizeof(int), 1, fp);//swapping byte
    fprintf(fp, "\n");
  }
  fprintf(fp, "$EndMeshFormat\n");
  
  // physicals
  if(numPhysicalNames() > 0)
  {
    fprintf(fp, "$PhysicalNames\n");
    fprintf(fp, "%d\n", numPhysicalNames());
    for(piter it = firstPhysicalName(); it != lastPhysicalName(); ++it)
    {
      std::string name = it->second;
      if(name.size() > 128) name.resize(128);
      fprintf(fp, "%d %d \"%s\"\n", it->first.first, it->first.second, name.c_str());
    }
    fprintf(fp, "$EndPhysicalNames\n");
  }
  
  // entities
  fprintf(fp, "$Entities\n");
  writeMSH4Entities(this, fp, false, binary, scalingFactor);
  fprintf(fp, "$EndEntities\n");
  
  // partitioned entities
  if(CTX::instance()->mesh.num_partitions > 0)
  {
    fprintf(fp, "$PartitionedEntities\n");
    writeMSH4Entities(this, fp, true, binary, scalingFactor);
    fprintf(fp, "$EndPartitionedEntities\n");
  }
  
  // nodes
  if(saveParametric)
  {
    fprintf(fp, "$ParametricNodes\n");
    writeMSH4Nodes(this, fp, CTX::instance()->mesh.num_partitions == 0 ? false : true, binary, saveParametric, scalingFactor);
    fprintf(fp, "$EndParametricNodes\n");
  }
  else
  {
    fprintf(fp, "$Nodes\n");
    writeMSH4Nodes(this, fp, CTX::instance()->mesh.num_partitions == 0 ? false : true, binary, saveParametric, scalingFactor);
    fprintf(fp, "$EndNodes\n");
  }
  
  // elements
  fprintf(fp, "$Element\n");
  writeMSH4Elements(this, fp, CTX::instance()->mesh.num_partitions == 0 ? false : true, binary, saveAll);
  fprintf(fp, "$EndElement\n");
  
  // periodic
  writeMSH4PeriodicNodes(this, fp, CTX::instance()->mesh.num_partitions == 0 ? false : true, binary);
  
  fclose(fp);
  
  return 1;
}

void writeMSH4Entities(GModel *const model, FILE *fp, bool partition, bool binary, double scalingFactor)
{
  std::set<GRegion*, GEntityLessThan> regions;
  std::set<GFace*, GEntityLessThan> faces;
  std::set<GEdge*, GEntityLessThan> edges;
  std::set<GVertex*, GEntityLessThan> vertices;
  
  if(partition)
  {
    for(GModel::viter it = model->firstVertex(); it != model->lastVertex(); ++it)
      if((*it)->geomType() == GEntity::PartitionVertex)
        vertices.insert(*it);
    for(GModel::eiter it = model->firstEdge(); it != model->lastEdge(); ++it)
      if((*it)->geomType() == GEntity::PartitionCurve)
        edges.insert(*it);
    for(GModel::fiter it = model->firstFace(); it != model->lastFace(); ++it)
      if((*it)->geomType() == GEntity::PartitionSurface)
        faces.insert(*it);
    for(GModel::riter it = model->firstRegion(); it != model->lastRegion(); ++it)
      if((*it)->geomType() == GEntity::PartitionVolume)
        regions.insert(*it);
  }
  else
  {
    for(GModel::viter it = model->firstVertex(); it != model->lastVertex(); ++it)
      if((*it)->geomType() != GEntity::PartitionVertex)
        vertices.insert(*it);
    for(GModel::eiter it = model->firstEdge(); it != model->lastEdge(); ++it)
      if((*it)->geomType() != GEntity::PartitionCurve)
        edges.insert(*it);
    for(GModel::fiter it = model->firstFace(); it != model->lastFace(); ++it)
      if((*it)->geomType() != GEntity::PartitionSurface)
        faces.insert(*it);
    for(GModel::riter it = model->firstRegion(); it != model->lastRegion(); ++it)
      if((*it)->geomType() != GEntity::PartitionVolume)
        regions.insert(*it);
  }
  
  if(binary)
  {
    if(partition) fwrite(&CTX::instance()->mesh.num_partitions, sizeof(int), 1, fp);
    int verticesSize = vertices.size();
    int edgesSize = edges.size();
    int facesSize = faces.size();
    int regionsSize = regions.size();
    fwrite(&verticesSize, sizeof(int), 1, fp);
    fwrite(&edgesSize, sizeof(int), 1, fp);
    fwrite(&facesSize, sizeof(int), 1, fp);
    fwrite(&regionsSize, sizeof(int), 1, fp);
        
    for(GModel::viter it = vertices.begin(); it != vertices.end(); ++it)
    {
      int entityTag = (*it)->tag();
      fwrite(&entityTag, sizeof(int), 1, fp);
      if(partition)
      {
        int parentEntityTag = static_cast<partitionVertex*>(*it)->getParentEntity()->tag();
        fwrite(&parentEntityTag, sizeof(int), 1, fp);
      }
      SBoundingBox3d boundBox = (*it)->bounds();
      boundBox *= scalingFactor;
      double minX = boundBox.min().x();
      double minY = boundBox.min().y();
      double minZ = boundBox.min().z();
      double maxX = boundBox.max().x();
      double maxY = boundBox.max().y();
      double maxZ = boundBox.max().z();
      fwrite(&minX, sizeof(double), 1, fp);
      fwrite(&minY, sizeof(double), 1, fp);
      fwrite(&minZ, sizeof(double), 1, fp);
      fwrite(&maxX, sizeof(double), 1, fp);
      fwrite(&maxY, sizeof(double), 1, fp);
      fwrite(&maxZ, sizeof(double), 1, fp);
      writeMSH4Physicals(fp, *it, binary);
    }
    
    for(GModel::eiter it = edges.begin(); it != edges.end(); ++it)
    {
      std::list<GVertex*> vertices;
      if((*it)->getBeginVertex()) vertices.push_back((*it)->getBeginVertex());
      if((*it)->getEndVertex()) vertices.push_back((*it)->getEndVertex());
      int verticesSize = vertices.size();
      
      int entityTag = (*it)->tag();
      fwrite(&entityTag, sizeof(int), 1, fp);
      if(partition)
      {
        int parentEntityTag = static_cast<partitionEdge*>(*it)->getParentEntity()->tag();
        fwrite(&parentEntityTag, sizeof(int), 1, fp);
      }
      
      fwrite(&verticesSize, sizeof(int), 1, fp);
      for(std::list<GVertex*>::iterator itv = vertices.begin(); itv != vertices.end(); itv++)
      {
        int brepTag = (*itv)->tag();
        fwrite(&brepTag, sizeof(int), 1, fp);
      }
      
      SBoundingBox3d boundBox = (*it)->bounds();
      double minX = boundBox.min().x();
      double minY = boundBox.min().y();
      double minZ = boundBox.min().z();
      double maxX = boundBox.max().x();
      double maxY = boundBox.max().y();
      double maxZ = boundBox.max().z();
      fwrite(&minX, sizeof(double), 1, fp);
      fwrite(&minY, sizeof(double), 1, fp);
      fwrite(&minZ, sizeof(double), 1, fp);
      fwrite(&maxX, sizeof(double), 1, fp);
      fwrite(&maxY, sizeof(double), 1, fp);
      fwrite(&maxZ, sizeof(double), 1, fp);
      writeMSH4Physicals(fp, *it, binary);
    }
    
    for(GModel::fiter it = faces.begin(); it != faces.end(); ++it)
    {
      std::list<GEdge*> edges = (*it)->edges();
      std::list<int> ori = (*it)->edgeOrientations();
      int edgesSize = edges.size();
      
      int entityTag = (*it)->tag();
      fwrite(&entityTag, sizeof(int), 1, fp);
      if(partition)
      {
        int parentEntityTag = static_cast<partitionFace*>(*it)->getParentEntity()->tag();
        fwrite(&parentEntityTag, sizeof(int), 1, fp);
      }
      
      fwrite(&edgesSize, sizeof(int), 1, fp);
      
      std::vector<int> tags, signs;
      for(std::list<GEdge*>::iterator ite = edges.begin(); ite != edges.end(); ite++)
        tags.push_back((*ite)->tag());
      for(std::list<int>::iterator ite = ori.begin(); ite != ori.end(); ite++)
        signs.push_back(*ite);
      
      if(tags.size() == signs.size())
      {
        for(unsigned int i = 0; i < tags.size(); i++)
          tags[i] *= (signs[i] > 0 ? 1 : -1);
      }
      
      for(unsigned int i = 0; i < tags.size(); i++)
      {
        int brepTag = tags[i];
        fwrite(&brepTag, sizeof(int), 1, fp);
      }
      
      SBoundingBox3d boundBox = (*it)->bounds();
      boundBox *= scalingFactor;
      double minX = boundBox.min().x();
      double minY = boundBox.min().y();
      double minZ = boundBox.min().z();
      double maxX = boundBox.max().x();
      double maxY = boundBox.max().y();
      double maxZ = boundBox.max().z();
      fwrite(&minX, sizeof(double), 1, fp);
      fwrite(&minY, sizeof(double), 1, fp);
      fwrite(&minZ, sizeof(double), 1, fp);
      fwrite(&maxX, sizeof(double), 1, fp);
      fwrite(&maxY, sizeof(double), 1, fp);
      fwrite(&maxZ, sizeof(double), 1, fp);
      
      writeMSH4Physicals(fp, *it, binary);
    }
    
    for(GModel::riter it = regions.begin(); it != regions.end(); ++it)
    {
      std::list<GFace*> faces = (*it)->faces();
      std::list<int> ori = (*it)->faceOrientations();
      int facesSize = faces.size();
      
      int entityTag = (*it)->tag();
      fwrite(&entityTag, sizeof(int), 1, fp);
      if(partition)
      {
        int parentEntityTag = static_cast<partitionRegion*>(*it)->getParentEntity()->tag();
        fwrite(&parentEntityTag, sizeof(int), 1, fp);
      }
      
      fwrite(&facesSize, sizeof(int), 1, fp);
      
      std::vector<int> tags, signs;
      for(std::list<GFace*>::iterator itf = faces.begin(); itf != faces.end(); itf++)
        tags.push_back((*itf)->tag());
      for(std::list<int>::iterator itf = ori.begin(); itf != ori.end(); itf++)
        signs.push_back(*itf);
      
      if(tags.size() == signs.size())
      {
        for(unsigned int i = 0; i < tags.size(); i++)
          tags[i] *= (signs[i] > 0 ? 1 : -1);
      }
      
      for(unsigned int i = 0; i < tags.size(); i++)
      {
        int brepTag = tags[i];
        fwrite(&brepTag, sizeof(int), 1, fp);
      }
      
      SBoundingBox3d boundBox = (*it)->bounds();
      double minX = boundBox.min().x();
      double minY = boundBox.min().y();
      double minZ = boundBox.min().z();
      double maxX = boundBox.max().x();
      double maxY = boundBox.max().y();
      double maxZ = boundBox.max().z();
      fwrite(&minX, sizeof(double), 1, fp);
      fwrite(&minY, sizeof(double), 1, fp);
      fwrite(&minZ, sizeof(double), 1, fp);
      fwrite(&maxX, sizeof(double), 1, fp);
      fwrite(&maxY, sizeof(double), 1, fp);
      fwrite(&maxZ, sizeof(double), 1, fp);
      
      writeMSH4Physicals(fp, *it, binary);
    }
  }
  else
  {
    if(partition) fprintf(fp, "%d", CTX::instance()->mesh.num_partitions);
    fprintf(fp, "%ld %ld %ld %ld", vertices.size(), edges.size(), faces.size(), regions.size());
    
    for(GModel::viter it = vertices.begin(); it != vertices.end(); ++it)
    {
      fprintf(fp, "%d ", (*it)->tag());
      if(partition) fprintf(fp, "%d ", static_cast<partitionVertex*>(*it)->getParentEntity()->tag());
      SBoundingBox3d boundBox = (*it)->bounds();
      boundBox *= scalingFactor;
      fprintf(fp, "%g %g %g ", boundBox.min().x(), boundBox.min().y(), boundBox.min().z());
      fprintf(fp, "%g %g %g\n", boundBox.max().x(), boundBox.max().y(), boundBox.max().z());
      writeMSH4Physicals(fp, *it, binary);
      fprintf(fp, "\n");
    }
    
    for(GModel::eiter it = edges.begin(); it != edges.end(); ++it)
    {
      std::list<GVertex*> vertices;
      if((*it)->getBeginVertex()) vertices.push_back((*it)->getBeginVertex());
      if((*it)->getEndVertex()) vertices.push_back((*it)->getEndVertex());
      
      fprintf(fp, "%d ", (*it)->tag());
      if(partition) fprintf(fp, "%d ", static_cast<partitionEdge*>(*it)->getParentEntity()->tag());
      fprintf(fp, "%ld ", vertices.size());
      for(std::list<GVertex*>::iterator itv = vertices.begin(); itv != vertices.end(); itv++)
        fprintf(fp, "%d ", (*itv)->tag());
      
      SBoundingBox3d boundBox = (*it)->bounds();
      boundBox *= scalingFactor;
      fprintf(fp, "%g %g %g ", boundBox.min().x(), boundBox.min().y(), boundBox.min().z());
      fprintf(fp, "%g %g %g\n", boundBox.max().x(), boundBox.max().y(), boundBox.max().z());
      writeMSH4Physicals(fp, *it, binary);
      fprintf(fp, "\n");
    }
    
    for(GModel::fiter it = faces.begin(); it != faces.end(); ++it)
    {
      std::list<GEdge*> edges = (*it)->edges();
      std::list<int> ori = (*it)->edgeOrientations();
      
      fprintf(fp, "%d ", (*it)->tag());
      if(partition) fprintf(fp, "%d ", static_cast<partitionFace*>(*it)->getParentEntity()->tag());
      fprintf(fp, "%ld ", edges.size());
      
      std::vector<int> tags, signs;
      for(std::list<GEdge*>::iterator ite = edges.begin(); ite != edges.end(); ite++)
        tags.push_back((*ite)->tag());
      for(std::list<int>::iterator ite = ori.begin(); ite != ori.end(); ite++)
        signs.push_back(*ite);
      
      if(tags.size() == signs.size())
      {
        for(unsigned int i = 0; i < tags.size(); i++)
          tags[i] *= (signs[i] > 0 ? 1 : -1);
      }
      
      for(unsigned int i = 0; i < tags.size(); i++)
        fprintf(fp, "%d ", tags[i]);
      
      SBoundingBox3d boundBox = (*it)->bounds();
      boundBox *= scalingFactor;
      fprintf(fp, "%g %g %g ", boundBox.min().x(), boundBox.min().y(), boundBox.min().z());
      fprintf(fp, "%g %g %g\n", boundBox.max().x(), boundBox.max().y(), boundBox.max().z());
      
      writeMSH4Physicals(fp, *it, binary);
      fprintf(fp, "\n");
    }
    
    for(GModel::riter it = regions.begin(); it != regions.end(); ++it)
    {
      std::list<GFace*> faces = (*it)->faces();
      std::list<int> ori = (*it)->faceOrientations();
      
      fprintf(fp, "%d ", (*it)->tag());
      if(partition) fprintf(fp, "%d ", static_cast<partitionRegion*>(*it)->getParentEntity()->tag());
      fprintf(fp, "%ld ", faces.size());
      
      std::vector<int> tags, signs;
      for(std::list<GFace*>::iterator itf = faces.begin(); itf != faces.end(); itf++)
        tags.push_back((*itf)->tag());
      for(std::list<int>::iterator itf = ori.begin(); itf != ori.end(); itf++)
        signs.push_back(*itf);
      
      if(tags.size() == signs.size())
      {
        for(unsigned int i = 0; i < tags.size(); i++)
          tags[i] *= (signs[i] > 0 ? 1 : -1);
      }
      
      for(unsigned int i = 0; i < tags.size(); i++)
        fprintf(fp, "%d ", tags[i]);
      
      SBoundingBox3d boundBox = (*it)->bounds();
      boundBox *= scalingFactor;
      fprintf(fp, "%g %g %g ", boundBox.min().x(), boundBox.min().y(), boundBox.min().z());
      fprintf(fp, "%g %g %g\n", boundBox.max().x(), boundBox.max().y(), boundBox.max().z());
      
      writeMSH4Physicals(fp, *it, binary);
      fprintf(fp, "\n");
    }
  }
}

void writeMSH4Physicals(FILE *fp, GEntity *const entity, bool binary)
{
  if(binary)
  {
    std::vector<int> phys = entity->getPhysicalEntities();
    int phySize = phys.size();
    fwrite(&phySize, sizeof(int), 1, fp);
    for(unsigned int i = 0; i < phys.size(); i++)
    {
      int phy = phys[i];
      fwrite(&phy, sizeof(int), 1, fp);
    }
  }
  else
  {
    std::vector<int> phys = entity->getPhysicalEntities();
    fprintf(fp, "%ld ", phys.size());
    for(unsigned int i = 0; i < phys.size(); i++)
    {
      fprintf(fp, " %d", phys[i]);
    }
  }
}

void writeMSH4Nodes(GModel *const model, FILE *fp, bool partitioned, bool binary, bool saveParametric, double scalingFactor)
{
  std::set<GRegion*, GEntityLessThan> regions;
  std::set<GFace*, GEntityLessThan> faces;
  std::set<GEdge*, GEntityLessThan> edges;
  std::set<GVertex*, GEntityLessThan> vertices;
  
  if(partitioned)
  {
    for(GModel::viter it = model->firstVertex(); it != model->lastVertex(); ++it)
      if((*it)->geomType() == GEntity::PartitionVertex)
        vertices.insert(*it);
    for(GModel::eiter it = model->firstEdge(); it != model->lastEdge(); ++it)
      if((*it)->geomType() == GEntity::PartitionCurve)
        edges.insert(*it);
    for(GModel::fiter it = model->firstFace(); it != model->lastFace(); ++it)
      if((*it)->geomType() == GEntity::PartitionSurface)
        faces.insert(*it);
    for(GModel::riter it = model->firstRegion(); it != model->lastRegion(); ++it)
      if((*it)->geomType() == GEntity::PartitionVolume)
        regions.insert(*it);
  }
  else
  {
    for(GModel::viter it = model->firstVertex(); it != model->lastVertex(); ++it)
      if((*it)->geomType() != GEntity::PartitionVertex)
        vertices.insert(*it);
    for(GModel::eiter it = model->firstEdge(); it != model->lastEdge(); ++it)
      if((*it)->geomType() != GEntity::PartitionCurve)
        edges.insert(*it);
    for(GModel::fiter it = model->firstFace(); it != model->lastFace(); ++it)
      if((*it)->geomType() != GEntity::PartitionSurface)
        faces.insert(*it);
    for(GModel::riter it = model->firstRegion(); it != model->lastRegion(); ++it)
      if((*it)->geomType() != GEntity::PartitionVolume)
        regions.insert(*it);
  }
  
  if(binary)
  {
    int numSection = vertices.size() + edges.size() + faces.size() + regions.size();
    fwrite(&numSection, sizeof(int), 1, fp);
    //Todo : add the global size
  }
  else
  {
    fprintf(fp, "%ld", vertices.size() + edges.size() + faces.size() + regions.size());
  }
  
  for(GModel::viter it = vertices.begin(); it != vertices.end(); ++it)
  {
    if(binary)
    {
      int entityTag = (*it)->tag();
      int numVerts = (*it)->getNumMeshVertices();
      fwrite(&entityTag, sizeof(int), 1, fp);
      fwrite(&numVerts, sizeof(int), 1, fp);
    }
    else
    {
      fprintf(fp, "%d %d\n", (*it)->tag(), (*it)->getNumMeshVertices());
    }
    
    for(unsigned int i = 0; i < (*it)->getNumMeshVertices(); i++)
      (*it)->getMeshVertex(i)->writeMSH4(fp, binary, saveParametric, scalingFactor);
  }
    
  for(GModel::eiter it = edges.begin(); it != edges.end(); ++it)
  {
    if(binary)
    {
      int entityTag = (*it)->tag();
      int numVerts = (*it)->getNumMeshVertices();
      fwrite(&entityTag, sizeof(int), 1, fp);
      fwrite(&numVerts, sizeof(int), 1, fp);
    }
    else
    {
      fprintf(fp, "%d %d\n", (*it)->tag(), (*it)->getNumMeshVertices());
    }
    
    for(unsigned int i = 0; i < (*it)->getNumMeshVertices(); i++)
      (*it)->getMeshVertex(i)->writeMSH4(fp, binary, saveParametric, scalingFactor);
  }
    
  for(GModel::fiter it = faces.begin(); it != faces.end(); ++it)
  {
    if(binary)
    {
      int entityTag = (*it)->tag();
      int numVerts = (*it)->getNumMeshVertices();
      fwrite(&entityTag, sizeof(int), 1, fp);
      fwrite(&numVerts, sizeof(int), 1, fp);
    }
    else
    {
      fprintf(fp, "%d %d\n", (*it)->tag(), (*it)->getNumMeshVertices());
    }
    
    for(unsigned int i = 0; i < (*it)->getNumMeshVertices(); i++)
      (*it)->getMeshVertex(i)->writeMSH4(fp, binary, saveParametric, scalingFactor);
  }
    
  for(GModel::riter it = regions.begin(); it != regions.end(); ++it)
  {
    if(binary)
    {
      int entityTag = (*it)->tag();
      int numVerts = (*it)->getNumMeshVertices();
      fwrite(&entityTag, sizeof(int), 1, fp);
      fwrite(&numVerts, sizeof(int), 1, fp);
    }
    else
    {
      fprintf(fp, "%d %d\n", (*it)->tag(), (*it)->getNumMeshVertices());
    }
    
    for(unsigned int i = 0; i < (*it)->getNumMeshVertices(); i++)
      (*it)->getMeshVertex(i)->writeMSH4(fp, binary, saveParametric, scalingFactor);
  }
}

void writeMSH4Elements(GModel *const model, FILE *fp, bool partitioned, bool binary, bool saveAll)
{
  std::set<GRegion*, GEntityLessThan> regions;
  std::set<GFace*, GEntityLessThan> faces;
  std::set<GEdge*, GEntityLessThan> edges;
  std::set<GVertex*, GEntityLessThan> vertices;
  
  if(partitioned)
  {
    for(GModel::viter it = model->firstVertex(); it != model->lastVertex(); ++it)
      if((*it)->geomType() == GEntity::PartitionVertex)
        vertices.insert(*it);
    for(GModel::eiter it = model->firstEdge(); it != model->lastEdge(); ++it)
      if((*it)->geomType() == GEntity::PartitionCurve)
        edges.insert(*it);
    for(GModel::fiter it = model->firstFace(); it != model->lastFace(); ++it)
      if((*it)->geomType() == GEntity::PartitionSurface)
        faces.insert(*it);
    for(GModel::riter it = model->firstRegion(); it != model->lastRegion(); ++it)
      if((*it)->geomType() == GEntity::PartitionVolume)
        regions.insert(*it);
  }
  else
  {
    for(GModel::viter it = model->firstVertex(); it != model->lastVertex(); ++it)
      if((*it)->geomType() != GEntity::PartitionVertex)
        vertices.insert(*it);
    for(GModel::eiter it = model->firstEdge(); it != model->lastEdge(); ++it)
      if((*it)->geomType() != GEntity::PartitionCurve)
        edges.insert(*it);
    for(GModel::fiter it = model->firstFace(); it != model->lastFace(); ++it)
      if((*it)->geomType() != GEntity::PartitionSurface)
        faces.insert(*it);
    for(GModel::riter it = model->firstRegion(); it != model->lastRegion(); ++it)
      if((*it)->geomType() != GEntity::PartitionVolume)
        regions.insert(*it);
  }
  
  std::map<int, std::vector< std::pair<MElement*, GEntity*> > > elementsByDegree;
  
  for(GModel::viter it = vertices.begin(); it != vertices.end(); ++it)
  {
    if(!saveAll && (*it)->physicals.size() == 0) continue;
    for(unsigned int i = 0; i < (*it)->points.size(); i++)
      elementsByDegree[(*it)->points[i]->getTypeForMSH()].push_back(std::pair<MElement*, GEntity*>((*it)->points[i], *it));
  }
  
  for(GModel::eiter it = edges.begin(); it != edges.end(); ++it)
  {
    if(!saveAll && (*it)->physicals.size() == 0) continue;
    for(unsigned int i = 0; i < (*it)->lines.size(); i++)
      elementsByDegree[(*it)->lines[i]->getTypeForMSH()].push_back(std::pair<MElement*, GEntity*>((*it)->lines[i], *it));
  }
  
  for(GModel::fiter it = faces.begin(); it != faces.end(); ++it)
  {
    if(!saveAll && (*it)->physicals.size() == 0) continue;
    for(unsigned int i = 0; i < (*it)->triangles.size(); i++)
      elementsByDegree[(*it)->triangles[i]->getTypeForMSH()].push_back(std::pair<MElement*, GEntity*>((*it)->triangles[i], *it));
    
    for(unsigned int i = 0; i < (*it)->quadrangles.size(); i++)
      elementsByDegree[(*it)->quadrangles[i]->getTypeForMSH()].push_back(std::pair<MElement*, GEntity*>((*it)->quadrangles[i], *it));
  }
  
  for(GModel::riter it = regions.begin(); it != regions.end(); ++it)
  {
    if(!saveAll && (*it)->physicals.size() == 0) continue;
    for(unsigned int i = 0; i < (*it)->tetrahedra.size(); i++)
      elementsByDegree[(*it)->tetrahedra[i]->getTypeForMSH()].push_back(std::pair<MElement*, GEntity*>((*it)->tetrahedra[i], *it));
    
    for(unsigned int i = 0; i < (*it)->hexahedra.size(); i++)
      elementsByDegree[(*it)->hexahedra[i]->getTypeForMSH()].push_back(std::pair<MElement*, GEntity*>((*it)->hexahedra[i], *it));
    
    for(unsigned int i = 0; i < (*it)->prisms.size(); i++)
      elementsByDegree[(*it)->prisms[i]->getTypeForMSH()].push_back(std::pair<MElement*, GEntity*>((*it)->prisms[i], *it));
    
    for(unsigned int i = 0; i < (*it)->pyramids.size(); i++)
      elementsByDegree[(*it)->pyramids[i]->getTypeForMSH()].push_back(std::pair<MElement*, GEntity*>((*it)->pyramids[i], *it));
    
    for(unsigned int i = 0; i < (*it)->trihedra.size(); i++)
      elementsByDegree[(*it)->trihedra[i]->getTypeForMSH()].push_back(std::pair<MElement*, GEntity*>((*it)->trihedra[i], *it));
  }
  
  if(binary)
  {
    int numSection = elementsByDegree.size();
    fwrite(&numSection, sizeof(int), 1, fp);
    //Todo : add the global size
  }
  else
  {
    fprintf(fp, "%ld\n", elementsByDegree.size());
  }
  
  for(std::map<int, std::vector< std::pair<MElement*, GEntity*> > >::iterator it = elementsByDegree.begin(); it != elementsByDegree.end(); ++it)
  {
    if(binary)
    {
      int entityTag = it->second[0].second->tag();
      int elmType = it->first;
      int numElm = it->second.size();
      fwrite(&entityTag, sizeof(int), 1, fp);
      fwrite(&elmType, sizeof(int), 1, fp);
      fwrite(&numElm, sizeof(int), 1, fp);
    }
    else
    {
      fprintf(fp, "%d %d %ld\n", it->second[0].second->tag(), it->first, it->second.size());
    }
    
    for(unsigned int i = 0; i < it->second.size(); i++)
    {
      it->second[i].first->writeMSH4(fp, binary);
    }
  }
}

void writeMSH4PeriodicNodes(GModel *const model, FILE *fp, bool partitioned, bool binary)
{
  int count = 0;
  std::vector<GEntity*> entities;
  model->getEntities(entities);
  for(unsigned int i = 0; i < entities.size(); i++)
    if(entities[i]->meshMaster() != entities[i]) count++;
  
  if(!count) return;
  
  fprintf(fp, "$Periodic\n");
  
  if(binary)
  {
    fwrite(&count, sizeof(int), 1, fp);
  }
  else
  {
    fprintf(fp, "%d\n", count);
  }
  
  for(unsigned int i = 0; i < entities.size(); i++)
  {
    GEntity *g_slave = entities[i];
    GEntity *g_master = g_slave->meshMaster();
    
    if(g_slave != g_master)
    {
      if(binary)
      {
        int gSlaveDim = g_slave->dim();
        int gSlaveTag = g_slave->tag();
        int gMasterTag = g_master->tag();
        fwrite(&gSlaveDim, sizeof(int), 1, fp);
        fwrite(&gSlaveTag, sizeof(int), 1, fp);
        fwrite(&gMasterTag, sizeof(int), 1, fp);
        
        if(g_slave->affineTransform.size() == 16)
        {
          //Todo : In binary?
          fprintf(fp, "Affine");
          for(int j = 0; j < 16; j++) fprintf(fp, " %g", g_slave->affineTransform[i]);
          fprintf(fp, "\n");
        }
        
        int corrVertSize = g_slave->correspondingVertices.size();
        fwrite(&corrVertSize, sizeof(int), 1, fp);
        
        for (std::map<MVertex*,MVertex*>::iterator it = g_slave->correspondingVertices.begin(); it != g_slave->correspondingVertices.end(); ++it)
        {
          int numFirst = it->first->getNum();
          int numSecond = it->second->getNum();
          fwrite(&numFirst, sizeof(int), 1, fp);
          fwrite(&numSecond, sizeof(int), 1, fp);
        }
      }
      else
      {
        fprintf(fp, "%d %d %d\n", g_slave->dim(), g_slave->tag(), g_master->tag());
      
        if(g_slave->affineTransform.size() == 16)
        {
          //Todo : What is it?
          fprintf(fp, "Affine");
          for(int j = 0; j < 16; j++) fprintf(fp, " %g", g_slave->affineTransform[i]);
          fprintf(fp, "\n");
        }
      
        fprintf(fp, "%ld\n", g_slave->correspondingVertices.size());
      
        for (std::map<MVertex*,MVertex*>::iterator it = g_slave->correspondingVertices.begin(); it != g_slave->correspondingVertices.end(); ++it)
        {
          fprintf(fp, "%d %d\n", it->first->getNum(), it->second->getNum());
        }
      }
    }
  }
  
  fprintf(fp, "$EndPeriodic\n");
}

/********************************************************
 *
 *    Write partitioned functions
 *
 ********************************************************/

int GModel::_writePartitionedMSH4(const std::string &baseName, double version, bool binary, bool saveAll, bool saveParametric, double scalingFactor)
{
  for(int i = 0; i < CTX::instance()->mesh.num_partitions; i++)
  {
    // Create a temporitary model
    GModel *tmp = new GModel();
    for(GModel::piter it = this->firstPhysicalName(); it != this->lastPhysicalName(); ++it)
    {
      tmp->setPhysicalName(it->second, it->first.first, it->first.second);
    }
    
    std::vector<GEntity*> entities;
    this->getEntities(entities);
    for(unsigned int i = 0; i < entities.size(); i++)
    {
      switch(entities[i]->geomType())
      {
        case GEntity::PartitionVolume:
          if(std::find(static_cast<partitionRegion*>(entities[i])->_partitions.begin(), static_cast<partitionRegion*>(entities[i])->_partitions.end(), i) != static_cast<partitionRegion*>(entities[i])->_partitions.end())
          {
            tmp->add(static_cast<partitionRegion*>(entities[i]));
            tmp->add(static_cast<partitionRegion*>(entities[i])->getParentEntity());
          }
          break;
        case GEntity::PartitionSurface:
          if(std::find(static_cast<partitionFace*>(entities[i])->_partitions.begin(), static_cast<partitionFace*>(entities[i])->_partitions.end(), i) != static_cast<partitionFace*>(entities[i])->_partitions.end())
          {
            tmp->add(static_cast<partitionFace*>(entities[i]));
            tmp->add(static_cast<partitionFace*>(entities[i])->getParentEntity());
          }
          break;
        case GEntity::PartitionCurve:
          if(std::find(static_cast<partitionEdge*>(entities[i])->_partitions.begin(), static_cast<partitionEdge*>(entities[i])->_partitions.end(), i) != static_cast<partitionEdge*>(entities[i])->_partitions.end())
          {
            tmp->add(static_cast<partitionEdge*>(entities[i]));
            tmp->add(static_cast<partitionEdge*>(entities[i])->getParentEntity());
          }
          break;
        case GEntity::PartitionVertex:
          if(std::find(static_cast<partitionVertex*>(entities[i])->_partitions.begin(), static_cast<partitionVertex*>(entities[i])->_partitions.end(), i) != static_cast<partitionVertex*>(entities[i])->_partitions.end())
          {
            tmp->add(static_cast<partitionVertex*>(entities[i]));
            tmp->add(static_cast<partitionVertex*>(entities[i])->getParentEntity());
          }
          break;
        default:
          break;
      }
    }
    AssignMeshVertices(tmp);
    std::ostringstream sstream;
    sstream << baseName << "_" << i << ".msh";
    
    tmp->_writeMSH4(sstream.str(), version, binary, saveAll, saveParametric, scalingFactor);
    tmp->remove();
    delete tmp;
  }
  
  return 1;
}

