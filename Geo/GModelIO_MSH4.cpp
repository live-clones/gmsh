// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

#include "GmshDefines.h"
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
void writeMSH4Entities(GModel *const model, std::ofstream &file, bool partition, bool binary, double scalingFactor);
void writeMSH4Physicals(std::ofstream &file, GEntity *const entity, bool binary);
void writeMSH4Nodes(GModel *const model, std::ofstream &file, bool partitioned, bool binary, bool saveParametric, double scalingFactor);
void writeMSH4Elements(GModel *const model, std::ofstream &file, bool partitioned, bool binary, bool saveAll);
void writeMSH4PeriodicNodes(GModel *const model, std::ofstream &file, bool partitioned, bool binary);

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
  std::ofstream file;
  if(binary)
  {
    file.open(name, std::ios::binary);
  }
  else
  {
    file.open(name);
    file.precision(16);
  }
  
  if(!file.is_open()){
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }
  
  // if there are no physicals we save all the elements
  if(noPhysicalGroups()) saveAll = true;
  
  // header
  file << "$MeshFormat" << std::endl;
  file << version << " " << (binary ? 1 : 0) << " " << sizeof(double) << " ";
  if(binary)
  {
    int one = 1;
    file.write((char *)(&one), sizeof(int));//swapping byte
  }
  file << std::endl;
  file << "$EndMeshFormat" << std::endl;
  
  // physicals
  file << "$PhysicalNames" << std::endl;
  file << numPhysicalNames() << std::endl;
  for(piter it = firstPhysicalName(); it != lastPhysicalName(); ++it)
  {
    std::string name = it->second;
    if(name.size() > 128) name.resize(128);
    file << it->first.first << " " << it->first.second << " \"" << name << "\"" << std::endl;
  }
  file << "$EndPhysicalNames" << std::endl;
  
  // entities
  file << "$Entities" << std::endl;
  writeMSH4Entities(this, file, false, binary, scalingFactor);
  file << "$EndEntities" << std::endl;
  
  // partitioned entities
  file << "$PartitionedEntities" << std::endl;
  writeMSH4Entities(this, file, true, binary, scalingFactor);
  file << "$EndPartitionedEntities" << std::endl;
  
  // nodes
  if(saveParametric)
  {
    file << "$ParametricNodes" << std::endl;
    writeMSH4Nodes(this, file, CTX::instance()->mesh.num_partitions != 0 ? false : true, binary, saveParametric, scalingFactor);
    file << "$EndParametricNodes" << std::endl;
  }
  else
  {
    file << "$Nodes" << std::endl;
    writeMSH4Nodes(this, file, CTX::instance()->mesh.num_partitions != 0 ? false : true, binary, saveParametric, scalingFactor);
    file << "$EndNodes" << std::endl;
  }
  
  // elements
  file << "$Element" << std::endl;
  writeMSH4Elements(this, file, CTX::instance()->mesh.num_partitions != 0 ? false : true, binary, saveAll);
  file << "$EndElement" << std::endl;
  
  // periodic
  file << "$Periodic" << std::endl;
  writeMSH4PeriodicNodes(this, file, CTX::instance()->mesh.num_partitions != 0 ? false : true, binary);
  file << "$EndPeriodic" << std::endl;
  
  file.close();
  
  return 1;
}

void writeMSH4Entities(GModel *const model, std::ofstream &file, bool partition, bool binary, double scalingFactor)
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
    if(partition) file.write((char*)&CTX::instance()->mesh.num_partitions, sizeof(int));
    int verticesSize = vertices.size();
    int edgesSize = edges.size();
    int facesSize = faces.size();
    int regionsSize = regions.size();
    file.write((char*)&verticesSize, sizeof(int));
    file.write((char*)&edgesSize, sizeof(int));
    file.write((char*)&facesSize, sizeof(int));
    file.write((char*)&regionsSize, sizeof(int));
        
    for(GModel::viter it = vertices.begin(); it != vertices.end(); ++it)
    {
      int entityTag = (*it)->tag();
      file.write((char*)&entityTag, sizeof(int));
      if(partition)
      {
        int parentEntityTag = static_cast<partitionVertex*>(*it)->getParentEntity()->tag();
        file.write((char*)&parentEntityTag, sizeof(int));
      }
      SBoundingBox3d boundBox = (*it)->bounds();
      boundBox *= scalingFactor;
      double minX = boundBox.min().x();
      double minY = boundBox.min().y();
      double minZ = boundBox.min().z();
      double maxX = boundBox.max().x();
      double maxY = boundBox.max().y();
      double maxZ = boundBox.max().z();
      file.write((char*)&minX, sizeof(double));
      file.write((char*)&minY, sizeof(double));
      file.write((char*)&minZ, sizeof(double));
      file.write((char*)&maxX, sizeof(double));
      file.write((char*)&maxY, sizeof(double));
      file.write((char*)&maxZ, sizeof(double));
      writeMSH4Physicals(file, *it, binary);
    }
    
    for(GModel::eiter it = edges.begin(); it != edges.end(); ++it)
    {
      std::list<GVertex*> vertices;
      if((*it)->getBeginVertex()) vertices.push_back((*it)->getBeginVertex());
      if((*it)->getEndVertex()) vertices.push_back((*it)->getEndVertex());
      int verticesSize = vertices.size();
      
      int entityTag = (*it)->tag();
      file.write((char*)&entityTag, sizeof(int));
      if(partition)
      {
        int parentEntityTag = static_cast<partitionEdge*>(*it)->getParentEntity()->tag();
        file.write((char*)&parentEntityTag, sizeof(int));
      }
      
      file.write((char*)&verticesSize, sizeof(int));
      for(std::list<GVertex*>::iterator itv = vertices.begin(); itv != vertices.end(); itv++)
      {
        int brepTag = (*itv)->tag();
        file.write((char*)&brepTag, sizeof(int));
      }
      
      SBoundingBox3d boundBox = (*it)->bounds();
      double minX = boundBox.min().x();
      double minY = boundBox.min().y();
      double minZ = boundBox.min().z();
      double maxX = boundBox.max().x();
      double maxY = boundBox.max().y();
      double maxZ = boundBox.max().z();
      file.write((char*)&minX, sizeof(double));
      file.write((char*)&minY, sizeof(double));
      file.write((char*)&minZ, sizeof(double));
      file.write((char*)&maxX, sizeof(double));
      file.write((char*)&maxY, sizeof(double));
      file.write((char*)&maxZ, sizeof(double));
      writeMSH4Physicals(file, *it, binary);
    }
    
    for(GModel::fiter it = faces.begin(); it != faces.end(); ++it)
    {
      std::list<GEdge*> edges = (*it)->edges();
      std::list<int> ori = (*it)->edgeOrientations();
      int edgesSize = edges.size();
      
      int entityTag = (*it)->tag();
      file.write((char*)&entityTag, sizeof(int));
      if(partition)
      {
        int parentEntityTag = static_cast<partitionFace*>(*it)->getParentEntity()->tag();
        file.write((char*)&parentEntityTag, sizeof(int));
      }
      
      file.write((char*)&edgesSize, sizeof(int));
      
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
        file.write((char*)&brepTag, sizeof(int));
      }
      
      SBoundingBox3d boundBox = (*it)->bounds();
      boundBox *= scalingFactor;
      double minX = boundBox.min().x();
      double minY = boundBox.min().y();
      double minZ = boundBox.min().z();
      double maxX = boundBox.max().x();
      double maxY = boundBox.max().y();
      double maxZ = boundBox.max().z();
      file.write((char*)&minX, sizeof(double));
      file.write((char*)&minY, sizeof(double));
      file.write((char*)&minZ, sizeof(double));
      file.write((char*)&maxX, sizeof(double));
      file.write((char*)&maxY, sizeof(double));
      file.write((char*)&maxZ, sizeof(double));
      
      writeMSH4Physicals(file, *it, binary);
    }
    
    for(GModel::riter it = regions.begin(); it != regions.end(); ++it)
    {
      std::list<GFace*> faces = (*it)->faces();
      std::list<int> ori = (*it)->faceOrientations();
      int facesSize = faces.size();
      
      int entityTag = (*it)->tag();
      file.write((char*)&entityTag, sizeof(int));
      if(partition)
      {
        int parentEntityTag = static_cast<partitionRegion*>(*it)->getParentEntity()->tag();
        file.write((char*)&parentEntityTag, sizeof(int));
      }
      
      file.write((char*)&facesSize, sizeof(int));
      
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
        file.write((char*)&brepTag, sizeof(int));
      }
      
      SBoundingBox3d boundBox = (*it)->bounds();
      double minX = boundBox.min().x();
      double minY = boundBox.min().y();
      double minZ = boundBox.min().z();
      double maxX = boundBox.max().x();
      double maxY = boundBox.max().y();
      double maxZ = boundBox.max().z();
      file.write((char*)&minX, sizeof(double));
      file.write((char*)&minY, sizeof(double));
      file.write((char*)&minZ, sizeof(double));
      file.write((char*)&maxX, sizeof(double));
      file.write((char*)&maxY, sizeof(double));
      file.write((char*)&maxZ, sizeof(double));
      
      writeMSH4Physicals(file, *it, binary);
    }
  }
  else
  {
    if(partition) file << CTX::instance()->mesh.num_partitions << std::endl;
    file << vertices.size() << " " << edges.size() << " " << faces.size() << " " << regions.size() << std::endl;
    
    for(GModel::viter it = vertices.begin(); it != vertices.end(); ++it)
    {
      file << (*it)->tag() << " ";
      if(partition) file << static_cast<partitionVertex*>(*it)->getParentEntity()->tag() << " ";
      SBoundingBox3d boundBox = (*it)->bounds();
      boundBox *= scalingFactor;
      file << boundBox.min().x() << " " << boundBox.min().y() << " " << boundBox.min().z() << " ";
      file << boundBox.max().x() << " " << boundBox.max().y() << " " << boundBox.max().z() << " ";
      writeMSH4Physicals(file, *it, binary);
      file << std::endl;
    }
    
    for(GModel::eiter it = edges.begin(); it != edges.end(); ++it)
    {
      std::list<GVertex*> vertices;
      if((*it)->getBeginVertex()) vertices.push_back((*it)->getBeginVertex());
      if((*it)->getEndVertex()) vertices.push_back((*it)->getEndVertex());
      
      file << (*it)->tag() << " ";
      if(partition) file << static_cast<partitionEdge*>(*it)->getParentEntity()->tag() << " ";
      file << vertices.size() << " ";
      for(std::list<GVertex*>::iterator itv = vertices.begin(); itv != vertices.end(); itv++)
        file << (*itv)->tag() << " ";
      
      SBoundingBox3d boundBox = (*it)->bounds();
      boundBox *= scalingFactor;
      file << boundBox.min().x() << " " << boundBox.min().y() << " " << boundBox.min().z() << " ";
      file << boundBox.max().x() << " " << boundBox.max().y() << " " << boundBox.max().z() << " ";
      writeMSH4Physicals(file, *it, binary);
      file << std::endl;
    }
    
    for(GModel::fiter it = faces.begin(); it != faces.end(); ++it)
    {
      std::list<GEdge*> edges = (*it)->edges();
      std::list<int> ori = (*it)->edgeOrientations();
      
      file << (*it)->tag() << " ";
      if(partition) file << static_cast<partitionFace*>(*it)->getParentEntity()->tag() << " ";
      file << edges.size() << " ";
      
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
        file << tags[i] << " ";
      
      SBoundingBox3d boundBox = (*it)->bounds();
      boundBox *= scalingFactor;
      file << boundBox.min().x() << " " << boundBox.min().y() << " " << boundBox.min().z() << " ";
      file << boundBox.max().x() << " " << boundBox.max().y() << " " << boundBox.max().z() << " ";
      
      writeMSH4Physicals(file, *it, binary);
      file << std::endl;
    }
    
    for(GModel::riter it = regions.begin(); it != regions.end(); ++it)
    {
      std::list<GFace*> faces = (*it)->faces();
      std::list<int> ori = (*it)->faceOrientations();
      
      file << (*it)->tag() << " ";
      if(partition) file << static_cast<partitionRegion*>(*it)->getParentEntity()->tag() << " ";
      file << faces.size() << " ";
      
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
        file << tags[i] << " ";
      
      SBoundingBox3d boundBox = (*it)->bounds();
      boundBox *= scalingFactor;
      file << boundBox.min().x() << " " << boundBox.min().y() << " " << boundBox.min().z() << " ";
      file << boundBox.max().x() << " " << boundBox.max().y() << " " << boundBox.max().z() << " ";
      
      writeMSH4Physicals(file, *it, binary);
      file << std::endl;
    }
  }
}

void writeMSH4Physicals(std::ofstream &file, GEntity *const entity, bool binary)
{
  if(binary)
  {
    std::vector<int> phys = entity->getPhysicalEntities();
    int phySize = phys.size();
    file.write((char*)&phySize, sizeof(int));
    for(unsigned int i = 0; i < phys.size(); i++)
    {
      int phy = phys[i];
      file.write((char*)&phy, sizeof(int));
    }
  }
  else
  {
    std::vector<int> phys = entity->getPhysicalEntities();
    file << phys.size() << " ";
    for(unsigned int i = 0; i < phys.size(); i++)
    {
      file << phys[i] << " ";
    }
  }
}

void writeMSH4Nodes(GModel *const model, std::ofstream &file, bool partitioned, bool binary, bool saveParametric, double scalingFactor)
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
    file.write((char*)&numSection, sizeof(int));
    //Todo : add the global size
  }
  else
  {
    file << vertices.size() + edges.size() + faces.size() + regions.size() << std::endl;
  }
  
  for(GModel::viter it = vertices.begin(); it != vertices.end(); ++it)
  {
    if(binary)
    {
      int entityTag = (*it)->tag();
      int numVerts = (*it)->getNumMeshVertices();
      file.write((char*)&entityTag, sizeof(int));
      file.write((char*)&numVerts, sizeof(int));
    }
    else
    {
      file << (*it)->tag() << " " << (*it)->getNumMeshVertices() << std::endl;
    }
    
    for(unsigned int i = 0; i < (*it)->getNumMeshVertices(); i++)
      (*it)->getMeshVertex(i)->writeMSH4(file, binary, saveParametric, scalingFactor);
  }
    
  for(GModel::eiter it = edges.begin(); it != edges.end(); ++it)
  {
    if(binary)
    {
      int entityTag = (*it)->tag();
      int numVerts = (*it)->getNumMeshVertices();
      file.write((char*)&entityTag, sizeof(int));
      file.write((char*)&numVerts, sizeof(int));
    }
    else
    {
      file << (*it)->tag() << " " << (*it)->getNumMeshVertices() << std::endl;
    }
    
    for(unsigned int i = 0; i < (*it)->getNumMeshVertices(); i++)
      (*it)->getMeshVertex(i)->writeMSH4(file, binary, saveParametric, scalingFactor);
  }
    
  for(GModel::fiter it = faces.begin(); it != faces.end(); ++it)
  {
    if(binary)
    {
      int entityTag = (*it)->tag();
      int numVerts = (*it)->getNumMeshVertices();
      file.write((char*)&entityTag, sizeof(int));
      file.write((char*)&numVerts, sizeof(int));
    }
    else
    {
      file << (*it)->tag() << " " << (*it)->getNumMeshVertices() << std::endl;
    }
    
    for(unsigned int i = 0; i < (*it)->getNumMeshVertices(); i++)
      (*it)->getMeshVertex(i)->writeMSH4(file, binary, saveParametric, scalingFactor);
  }
    
  for(GModel::riter it = regions.begin(); it != regions.end(); ++it)
  {
    if(binary)
    {
      int entityTag = (*it)->tag();
      int numVerts = (*it)->getNumMeshVertices();
      file.write((char*)&entityTag, sizeof(int));
      file.write((char*)&numVerts, sizeof(int));
    }
    else
    {
      file << (*it)->tag() << " " << (*it)->getNumMeshVertices() << std::endl;
    }
    
    for(unsigned int i = 0; i < (*it)->getNumMeshVertices(); i++)
      (*it)->getMeshVertex(i)->writeMSH4(file, binary, saveParametric, scalingFactor);
  }
}

void writeMSH4Elements(GModel *const model, std::ofstream &file, bool partitioned, bool binary, bool saveAll)
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
    file.write((char*)&numSection, sizeof(int));
    //Todo : add the global size
  }
  else
  {
    file << elementsByDegree.size() << std::endl;
  }
  
  for(std::map<int, std::vector< std::pair<MElement*, GEntity*> > >::iterator it = elementsByDegree.begin(); it != elementsByDegree.end(); ++it)
  {
    if(binary)
    {
      int entityTag = it->second[0].second->tag();
      int elmType = it->first;
      int numElm = it->second.size();
      file.write((char*)&entityTag, sizeof(int));
      file.write((char*)&elmType, sizeof(int));
      file.write((char*)&numElm, sizeof(int));
    }
    else
    {
      file << it->second[0].second->tag() << " " << it->first << " " << it->second.size() << std::endl;
    }
    
    for(unsigned int i = 0; i < it->second.size(); i++)
    {
      it->second[i].first->writeMSH4(file, binary);
    }
  }
}

void writeMSH4PeriodicNodes(GModel *const model, std::ofstream &file, bool partitioned, bool binary)
{
  int count = 0;
  std::vector<GEntity*> entities;
  model->getEntities(entities);
  for(unsigned int i = 0; i < entities.size(); i++)
    if(entities[i]->meshMaster() != entities[i]) count++;
  
  if(binary)
  {
    file.write((char*)&count, sizeof(int));
  }
  else
  {
    file << count << std::endl;
  }
  if(!count) return;
  
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
        file.write((char*)&gSlaveDim, sizeof(int));
        file.write((char*)&gSlaveTag, sizeof(int));
        file.write((char*)&gMasterTag, sizeof(int));
        
        if(g_slave->affineTransform.size() == 16)
        {
          //Todo : In binary?
          file << "Affine ";
          for(int j = 0; j < 16; j++) file << g_slave->affineTransform[i] << " ";
          file << std::endl;
        }
        
        int corrVertSize = g_slave->correspondingVertices.size();
        file.write((char*)&corrVertSize, sizeof(int));
        
        for (std::map<MVertex*,MVertex*>::iterator it = g_slave->correspondingVertices.begin(); it != g_slave->correspondingVertices.end(); ++it)
        {
          int numFirst = it->first->getNum();
          int numSecond = it->second->getNum();
          file.write((char*)&numFirst, sizeof(int));
          file.write((char*)&numSecond, sizeof(int));
        }
      }
      else
      {
        file << g_slave->dim() << " " << g_slave->tag() << " " << g_master->tag() << std::endl;
      
        if(g_slave->affineTransform.size() == 16)
        {
          //Todo : What is it?
          file << "Affine ";
          for(int j = 0; j < 16; j++) file << g_slave->affineTransform[i] << " ";
          file << std::endl;
        }
      
        file << g_slave->correspondingVertices.size() << std::endl;
      
        for (std::map<MVertex*,MVertex*>::iterator it = g_slave->correspondingVertices.begin(); it != g_slave->correspondingVertices.end(); ++it)
        {
          file << it->first->getNum() << " " << it->second->getNum() << std::endl;
        }
      }
    }
  }
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

