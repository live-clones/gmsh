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
#include <string>

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
#include "StringUtils.h"
#include "Options.h"

//Write functions
void writeMSH4Entities(GModel *const model, FILE* fp, bool partition, bool binary, double scalingFactor);
void writeMSH4Physicals(FILE* fp, GEntity *const entity, bool binary);
void writeMSH4Nodes(GModel *const model, FILE* fp, bool partitioned, bool binary, bool saveParametric, double scalingFactor);
void writeMSH4Elements(GModel *const model, FILE* fp, bool partitioned, bool binary, bool saveAll);
void writeMSH4PeriodicNodes(GModel *const model, FILE* fp, bool partitioned, bool binary);

//Read functions
void readMSH4Entities(GModel *const model, FILE* fp, bool partition, bool binary);
void readMSH4Physicals(GModel *const model, GEntity *const entity, bool binary, char *str);
void readMSH4BoundingBox(GModel *const model, GEntity *const entity, bool binary, char *str);
std::pair<int, MVertex*> *readMSH4Nodes(GModel *const model, FILE* fp, bool binary, bool parametric, bool &dense, int &nbrNodes);
std::pair<int, MElement*> *readMSH4Elements(GModel *const model, FILE* fp, bool binary, bool &dense, int &nbrElements);
void readMSHPeriodicNodes(GModel *const model, FILE* fp, bool binary);

/********************************************************
 *
 *    Read functions
 *
 ********************************************************/

int GModel::_readMSH4(const std::string &name)
{
  FILE *fp = Fopen(name.c_str(), "rb");
  if(!fp)
  {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }
  
  char str[256] = "xxx";
  double version = 1.0;
  bool binary = false, swap = false, postpro = false;
  
  while(1)
  {
    while(str[0] != '$')
    {
      if(!fgets(str, sizeof(str), fp) || feof(fp))
        break;
    }
    
    std::string sectionName(&str[1]);
    std::string endSectionName = "End" + sectionName;
    if(feof(fp))
      break;
    
    if(!strncmp(&str[1], "MeshFormat", 10))
    {
      if(!fgets(str, sizeof(str), fp) || feof(fp))
      {
        fclose(fp);
        return 0;
      }
      
      int format, size;
      if(sscanf(str, "%lf %d %d", &version, &format, &size) != 3)
      {
        fclose(fp);
        return 0;
      }
      if(format)
      {
        binary = true;
        Msg::Debug("Mesh is in binary format");
        int one;
        if(fread(&one, sizeof(int), 1, fp) != 1)
        {
          fclose(fp);
          return 0;
        }
        if(one != 1)
        {
          swap = true;
          Msg::Debug("Swapping bytes from binary file");
        }
      }
    }
    else if(!strncmp(&str[1], "PhysicalNames", 13))
    {
      if(!fgets(str, sizeof(str), fp) || feof(fp))
      {
        fclose(fp); return 0;
      }
      int numPhysicalNames = 0;
      if(sscanf(str, "%d", &numPhysicalNames) != 1)
      {
        fclose(fp); return 0;
      }
      for(int i = 0; i < numPhysicalNames; i++)
      {
        int dim = 0, tag = 0;
        if(fscanf(fp, "%d %d", &dim, &tag) != 2)
        {
          fclose(fp);
          return 0;
          
        }
        char name[128];
        if(!fgets(name, sizeof(name), fp))
        {
          fclose(fp);
          return 0;
        }
        std::string physicalName = ExtractDoubleQuotedString(name, 128);
        if(physicalName.size()) setPhysicalName(physicalName, dim, tag);
      }
    }
    else if(!strncmp(&str[1], "Entities", 8))
    {
      readMSH4Entities(this, fp, false, binary);
    }
    else if(!strncmp(&str[1], "PartitionedEntities", 19))
    {
      readMSH4Entities(this, fp, true, binary);
    }
    else if(!strncmp(&str[1], "Nodes", 5))
    {
      bool dense = false;
      int nbrNodes = 0;
      std::pair<int, MVertex*> *vertexCache = readMSH4Nodes(this, fp, binary, false, dense, nbrNodes);
      if(vertexCache != NULL)
      {
        if(dense)
        {
          _vertexVectorCache.resize(nbrNodes+1, NULL);
          _vertexVectorCache[0] = 0;
          
          for(int i = 0; i < nbrNodes; i++)
          {
            if(_vertexVectorCache[vertexCache[i].first] == NULL)
            {
              _vertexVectorCache[vertexCache[i].first] = vertexCache[i].second;
            }
            else
            {
              Msg::Warning("Skipping duplicate vertex %d", vertexCache[i].first);
            }
          }
        }
        else
        {
          for(int i = 0; i < nbrNodes; i++)
          {
            if(_vertexMapCache.count(vertexCache[i].first) == 0)
            {
              _vertexMapCache[vertexCache[i].first] = vertexCache[i].second;
            }
            else
            {
              Msg::Warning("Skipping duplicate vertex %d", vertexCache[i].first);
            }
          }
        }
        
        delete[] vertexCache;
      }
      else
      {
        return 0;
      }
    }
    else if(!strncmp(&str[1], "ParametricNodes", 15))
    {
      bool dense = false;
      int nbrNodes = 0;
      std::pair<int, MVertex*> *vertexCache = readMSH4Nodes(this, fp, binary, true, dense, nbrNodes);
      if(vertexCache != NULL)
      {
        if(dense)
        {
          _vertexVectorCache.resize(nbrNodes+1, NULL);
          _vertexVectorCache[0] = 0;
          
          for(int i = 0; i < nbrNodes; i++)
          {
            if(_vertexVectorCache[vertexCache[i].first] == NULL)
            {
              _vertexVectorCache[vertexCache[i].first] = vertexCache[i].second;
            }
            else
            {
              Msg::Warning("Skipping duplicate vertex %d", vertexCache[i].first);
            }
          }
        }
        else
        {
          for(int i = 0; i < nbrNodes; i++)
          {
            if(_vertexMapCache.count(vertexCache[i].first) == 0)
            {
              _vertexMapCache[vertexCache[i].first] = vertexCache[i].second;
            }
            else
            {
              Msg::Warning("Skipping duplicate vertex %d", vertexCache[i].first);
            }
          }
        }
        
        delete[] vertexCache;
      }
      else
      {
        return 0;
      }
    }
    else if(!strncmp(&str[1], "Elements", 8))
    {
      bool dense = false;
      int nbrElements = 0;
      std::pair<int, MElement*> *elementCache = readMSH4Elements(this, fp, binary, dense, nbrElements);
      if(elementCache != NULL)
      {
        if(dense)
        {
          _elementVectorCache.resize(nbrElements+1, NULL);
          _elementVectorCache[0] = 0;
          
          for(int i = 0; i < nbrElements; i++)
          {
            if(_elementVectorCache[elementCache[i].first] == NULL)
            {
              _elementVectorCache[elementCache[i].first] = elementCache[i].second;
            }
            else
            {
              Msg::Warning("Skipping duplicate element %d", elementCache[i].first);
            }
          }
        }
        else
        {
          for(int i = 0; i < nbrElements; i++)
          {
            if(_elementMapCache.count(elementCache[i].first) == 0)
            {
              _elementMapCache[elementCache[i].first] = elementCache[i].second;
            }
            else
            {
              Msg::Warning("Skipping duplicate element %d", elementCache[i].first);
            }
          }
        }
        
        delete[] elementCache;
      }
      else
      {
        return 0;
      }
    }
    else if(!strncmp(&str[1], "Periodic", 8))
    {
      readMSHPeriodicNodes(this, fp, binary);
    }
    else if(!strncmp(&str[1], "NodeData", 8) || !strncmp(&str[1], "ElementData", 11) || !strncmp(&str[1], "ElementNodeData", 15))
    {
      postpro = true;
      break;
    }
    
    while(strncmp(&str[1], endSectionName.c_str(), endSectionName.size()))
    {
      if(!fgets(str, sizeof(str), fp) || feof(fp))
        break;
    }
    str[0] = 'a';
  }
  
  fclose(fp);
  
  return postpro ? 2 : 1;
}

void readMSH4Entities(GModel *const model, FILE* fp, bool partition, bool binary)
{
  char str[256];

  if(partition)
  {
    int numPartitions = 0;
    if(fscanf(fp, "%d", &numPartitions) != 1)
    {
      fclose(fp);
      return;
    }
    opt_mesh_partition_num(0, GMSH_SET, numPartitions);
  }
  int numVert = 0, numEdges = 0, numFaces = 0, numReg = 0;
  if(fscanf(fp, "%d %d %d %d", &numVert, &numEdges, &numFaces, &numReg) != 4)
  {
    fclose(fp);
    return;
  }
  //Vertices
  for(int i = 0; i < numVert; i++)
  {
    int tag = 0;
    double minX = 0., minY = 0., minZ = 0., maxX = 0., maxY = 0., maxZ = 0.;
    int parentTag = 0;
    if(partition)
    {
      if(fscanf(fp, "%d %d %lf %lf %lf %lf %lf %lf %[0-9 ]", &tag, &parentTag, &minX, &minY, &minZ, &maxX, &maxY, &maxZ, str) != 9)
      {
        fclose(fp);
        return;
      }
    }
    else
    {
      if(fscanf(fp, "%d %lf %lf %lf %lf %lf %lf %[0-9 ]", &tag, &minX, &minY, &minZ, &maxX, &maxY, &maxZ, str) != 8)
      {
        fclose(fp);
        return;
      }
    }
    
    GVertex *gv = model->getVertexByTag(tag);
    if (!gv)
    {
      if(partition)
      {
        gv = new partitionVertex(model, tag);
        static_cast<partitionVertex*>(gv)->setParentEntity(model->getVertexByTag(parentTag));
      }
      else
      {
        gv = new discreteVertex(model, tag);
      }
      model->add(gv);
    }
    readMSH4Physicals(model, gv, binary, str);
    
    if(partition)
    {
      std::vector<unsigned short> partitions = getPartition(model, gv);
      static_cast<partitionVertex*>(gv)->setPartition(partitions);
    }
  }
  
  //Edges
  for(int i = 0; i < numEdges; i++)
  {
    int tag = 0;
    double minX = 0., minY = 0., minZ = 0., maxX = 0., maxY = 0., maxZ = 0.;
    int parentTag = 0;
    if(partition)
    {
      if(fscanf(fp, "%d %d %lf %lf %lf %lf %lf %lf %[0-9 ]", &tag, &parentTag, &minX, &minY, &minZ, &maxX, &maxY, &maxZ, str) != 9)
      {
        fclose(fp);
        return;
      }
    }
    else
    {
      if(fscanf(fp, "%d %lf %lf %lf %lf %lf %lf %[0-9 ]", &tag, &minX, &minY, &minZ, &maxX, &maxY, &maxZ, str) != 8)
      {
        fclose(fp);
        return;
      }
    }
    
    GEdge *ge = model->getEdgeByTag(tag);
    if (!ge)
    {
      if(partition)
      {
        ge = new partitionEdge(model, tag, NULL, NULL);
        static_cast<partitionEdge*>(ge)->setParentEntity(model->getEdgeByTag(parentTag));
      }
      else
      {
        ge = new discreteEdge(model, tag, NULL, NULL);
      }
      model->add(ge);
    }
    readMSH4Physicals(model, ge, binary, str);
    
    if(partition)
    {
      std::vector<unsigned short> partitions = getPartition(model, ge);
      static_cast<partitionEdge*>(ge)->setPartition(partitions);
    }
    
    readMSH4BoundingBox(model, ge, binary, str);
  }
  
  //Faces
  for(int i = 0; i < numFaces; i++)
  {
    int tag = 0;
    double minX = 0., minY = 0., minZ = 0., maxX = 0., maxY = 0., maxZ = 0.;
    int parentTag = 0;
    if(partition)
    {
      if(fscanf(fp, "%d %d %lf %lf %lf %lf %lf %lf %[0-9 ]", &tag, &parentTag, &minX, &minY, &minZ, &maxX, &maxY, &maxZ, str) != 9)
      {
        fclose(fp);
        return;
      }
    }
    else
    {
      if(fscanf(fp, "%d %lf %lf %lf %lf %lf %lf %[0-9 ]", &tag, &minX, &minY, &minZ, &maxX, &maxY, &maxZ, str) != 8)
      {
        fclose(fp);
        return;
      }
    }
    
    GFace *gf = model->getFaceByTag(tag);
    if (!gf)
    {
      if(partition)
      {
        gf = new partitionFace(model, tag);
        static_cast<partitionFace*>(gf)->setParentEntity(model->getFaceByTag(parentTag));
      }
      else
      {
        gf = new discreteFace(model, tag);
      }
      model->add(gf);
    }
    readMSH4Physicals(model, gf, binary, str);
    
    if(partition)
    {
      std::vector<unsigned short> partitions = getPartition(model, gf);
      static_cast<partitionFace*>(gf)->setPartition(partitions);
    }
    
    readMSH4BoundingBox(model, gf, binary, str);
  }
  
  //Regions
  for(int i = 0; i < numReg; i++)
  {
    int tag = 0;
    double minX = 0., minY = 0., minZ = 0., maxX = 0., maxY = 0., maxZ = 0.;
    int parentTag = 0;
    if(partition)
    {
      if(fscanf(fp, "%d %d %lf %lf %lf %lf %lf %lf %[0-9 ]", &tag, &parentTag, &minX, &minY, &minZ, &maxX, &maxY, &maxZ, str) != 9)
      {
        fclose(fp);
        return;
      }
    }
    else
    {
      if(fscanf(fp, "%d %lf %lf %lf %lf %lf %lf %[0-9 ]", &tag, &minX, &minY, &minZ, &maxX, &maxY, &maxZ, str) != 8)
      {
        fclose(fp);
        return;
      }
    }
    
    GRegion *gr = model->getRegionByTag(tag);
    if (!gr)
    {
      if(partition)
      {
        gr = new partitionRegion(model, tag);
        static_cast<partitionRegion*>(gr)->setParentEntity(model->getRegionByTag(parentTag));
      }
      else
      {
        gr = new discreteRegion(model, tag);
      }
      model->add(gr);
    }
    readMSH4Physicals(model, gr, binary, str);
    
    if(partition)
    {
      std::vector<unsigned short> partitions = getPartition(model, gr);
      static_cast<partitionRegion*>(gr)->setPartition(partitions);
    }
    
    readMSH4BoundingBox(model, gr, binary, str);
  }
}

void readMSH4Physicals(GModel *const model, GEntity *const entity, bool binary, char *str)
{
  int numPhy = 0;
  char strTmp[265];
  sscanf(str, "%d %[0-9 ]", &numPhy, strTmp);
  strcpy(str, strTmp);
  for(int i = 0; i < numPhy; i++)
  {
    int phyTag = 0;
    
    if(sscanf(str, "%d %s", &phyTag, strTmp) != 2)
    {
      return;
    }
    strcpy(str, strTmp);
    
    entity->addPhysicalEntity(phyTag);
  }
}

void readMSH4BoundingBox(GModel *const model, GEntity *const entity, bool binary, char *str)
{
  int numBrep = 0;
  char strTmp[265];
  sscanf(str, "%d %[0-9 ]", &numBrep, strTmp);
  strcpy(str, strTmp);
  std::vector<GEntity*> boundingEntities;
  std::vector<int> boundingSign;
  for(int i = 0; i < numBrep; i++)
  {
    int entityTag = 0;
    
    if(i != numBrep-1)
    {
      if(sscanf(str, "%d %s", &entityTag, strTmp) != 2)
      {
        return;
      }
    }
    else
    {
      if(sscanf(str, "%d", &entityTag) != 1)
      {
        return;
      }
    }
    strcpy(str, strTmp);
    
    GEntity *brep = model->getEntityByTag(entity->dim()-1, std::abs(entityTag));
    if(brep == NULL)
    {
      Msg::Warning("Entity %d not found in the Brep of entity %d", entityTag, entity->tag());
      return;
    }
    boundingEntities.push_back(entity);
    boundingSign.push_back((std::abs(entityTag) == entityTag ? 1 : -1));
  }
  
  switch (entity->dim()) {
    case 1:
      if(boundingEntities.size() == 2)
      {
        reinterpret_cast<discreteEdge*>(entity)->setBeginVertex(reinterpret_cast<GVertex*>(boundingEntities[0]));
        reinterpret_cast<discreteEdge*>(entity)->setBeginVertex(reinterpret_cast<GVertex*>(boundingEntities[1]));
      }
      break;
    case 2:
    {
      std::vector<int> tags(boundingEntities.size());
      for(unsigned int i = 0; i < boundingEntities.size(); i++)
        tags[i] = boundingEntities[i]->tag();
      reinterpret_cast<discreteFace*>(entity)->setBoundEdges(tags, boundingSign);
    }
      break;
    case 3:
    {
      std::vector<int> tags(boundingEntities.size());
      for(unsigned int i = 0; i < boundingEntities.size(); i++)
        tags[i] = boundingEntities[i]->tag();
      reinterpret_cast<discreteRegion*>(entity)->setBoundFaces(tags, boundingSign);
    }
      break;
    default:
      break;
  }
}

std::pair<int, MVertex*> *readMSH4Nodes(GModel *const model, FILE* fp, bool binary, bool parametric, bool &dense, int &nbrNodes)
{
  int numBlock = 0;
  nbrNodes = 0;
  if(fscanf(fp, "%d %d", &numBlock, &nbrNodes) != 2)
  {
    fclose(fp);
    return NULL;
  }
  
  int nodeRead = 0;
  int minVertex = nbrNodes+1, maxVertex = 0;
  std::pair<int, MVertex*> *vertexCache = new std::pair<int, MVertex*>[nbrNodes];
  Msg::Info("%d vertices", nbrNodes);
  for(int i = 0; i < numBlock; i++)
  {
    int entityTag = 0, entityDim = 0, numNodes = 0;
    
    if(fscanf(fp, "%d %d %d", &entityTag, &entityDim, &numNodes) != 3)
    {
      fclose(fp);
      return NULL;
    }
    
    GEntity *entity = model->getEntityByTag(entityDim, entityTag);
    if(entity == NULL)
    {
      fclose(fp);
      Msg::Error("Unknow entity %d of dimension %d", entityTag, entityDim);
      return NULL;
    }
    
    for(int j = 0; j < numNodes; j++)
    {
      double xyz[3];
      int nodeTag = 0;
      MVertex *vertex = NULL;
      
      if(parametric)
      {
        double u = 0., v = 0.;
        
        switch (entityDim)
        {
          case 0:
            if(fscanf(fp, "%d %lf %lf %lf", &nodeTag, &xyz[0], &xyz[1], &xyz[2]) != 4)
            {
              fclose(fp);
              return NULL;
            }
            vertex = new MVertex(xyz[0], xyz[1], xyz[2], entity, nodeTag);
            break;
          case 1:
            if(fscanf(fp, "%d %lf %lf %lf %lf", &nodeTag, &xyz[0], &xyz[1], &xyz[2], &u) != 5)
            {
              fclose(fp);
              return NULL;
            }
            vertex = new MEdgeVertex(xyz[0], xyz[1], xyz[2], entity, u, -1.0, nodeTag);
            break;
          case 2:
            if(fscanf(fp, "%d %lf %lf %lf %lf %lf", &nodeTag, &xyz[0], &xyz[1], &xyz[2], &u, &v) != 6)
            {
              fclose(fp);
              return NULL;
            }
            vertex = new MFaceVertex(xyz[0], xyz[1], xyz[2], entity, u, v, nodeTag);
            break;
          case 3:
            if(fscanf(fp, "%d %lf %lf %lf", &nodeTag, &xyz[0], &xyz[1], &xyz[2]) != 4)
            {
              fclose(fp);
              return NULL;
            }
            vertex = new MVertex(xyz[0], xyz[1], xyz[2], entity, nodeTag);
            break;
          default:
            fclose(fp);
            return NULL;
            break;
        }
      }
      else
      {
        if(fscanf(fp, "%d %lf %lf %lf", &nodeTag, &xyz[0], &xyz[1], &xyz[2]) != 4)
        {
          fclose(fp);
          return NULL;
        }
        vertex = new MVertex(xyz[0], xyz[1], xyz[2], entity, nodeTag);
      }
      entity->addMeshVertex(vertex);
      vertex->setEntity(entity);
      minVertex = std::min(minVertex, nodeTag);
      maxVertex = std::max(maxVertex, nodeTag);
      
      vertexCache[nodeRead] = std::pair<int, MVertex*>(nodeTag, vertex);
      nodeRead ++;
      
      if(nbrNodes > 100000) Msg::ProgressMeter(nodeRead, nbrNodes, true, "Reading nodes");
    }
  }
  // if the vertex numbering is dense, we fill the vector cache, otherwise we fill the map cache
  if(minVertex == 1 && maxVertex == nbrNodes)//If dense
  {
    Msg::Debug("Vertex numbering is dense");
    dense = true;
  }
  else
  {
    Msg::Debug("Vertex numbering is not dense");
    dense = false;
  }
  
  return vertexCache;
}

std::pair<int, MElement*> *readMSH4Elements(GModel *const model, FILE* fp, bool binary, bool &dense, int &nbrElements)
{
  char str[256];
  char strTmp[256];
  int numBlock = 0;
  nbrElements = 0;
  if(fscanf(fp, "%d %d", &numBlock, &nbrElements) != 2)
  {
    fclose(fp);
    return NULL;
  }
  
  int elementRead = 0;
  int minElement = nbrElements+1, maxElement = 0;
  std::pair<int, MElement*> *elementCache = new std::pair<int, MElement*>[nbrElements];
  Msg::Info("%d elements", nbrElements);
  for(int i = 0; i < numBlock; i++)
  {
    int entityTag = 0, entityDim = 0, elmType = 0, numElements = 0;

    if(fscanf(fp, "%d %d %d %d", &entityTag, &entityDim, &elmType, &numElements) != 4)
    {
      fclose(fp);
      return NULL;
    }
    
    GEntity *entity = model->getEntityByTag(entityDim, entityTag);
    if(entity == NULL)
    {
      fclose(fp);
      Msg::Error("Unknow entity %d of dimension %d", entityTag, entityDim);
      return NULL;
    }
    
    int nbrVertices = MElement::getInfoMSH(elmType);
    for(int j = 0; j < numElements; j++)
    {
      int elmTag = 0;
      if(fscanf(fp, "%d %[0-9 ]", &elmTag, str) != 2)
      {
        fclose(fp);
        return NULL;
      }
      
      std::vector<MVertex*> vertices(nbrVertices, NULL);
      
      for(int k = 0; k < nbrVertices; k++)
      {
        int vertexTag = 0;
        if(k != nbrVertices-1)
        {
          if(sscanf(str, "%d %[0-9 ]", &vertexTag, strTmp) != 2)
          {
            fclose(fp);
            return NULL;
          }
        }
        else
        {
          if(sscanf(str, "%d", &vertexTag) != 1)
          {
            fclose(fp);
            return NULL;
          }
        }
        strcpy(str, strTmp);
        
        vertices[k] = model->getMeshVertexByTag(vertexTag);
        if(vertices[k] == NULL)
        {
          Msg::Error("Unknow vertex %d in element %d", vertexTag, elmTag);
          fclose(fp);
          return NULL;
        }
      }
      
      MElementFactory elementFactory;
      MElement *element = elementFactory.create(elmType, vertices, elmTag, 0, false, 0, NULL, NULL, NULL);
      
      entity->addElement(element->getType(), element);
      
      minElement = std::min(minElement, elmTag);
      maxElement = std::max(maxElement, elmTag);
      
      elementCache[elementRead] = std::pair<int, MElement*>(elmTag, element);
      elementRead ++;
      
      if(nbrElements > 100000) Msg::ProgressMeter(elementRead, nbrElements, true, "Reading elements");
    }
  }
  // if the vertex numbering is dense, we fill the vector cache, otherwise we fill the map cache
  if(minElement == 1 && maxElement == nbrElements)//If dense
  {
    Msg::Debug("Element numbering is dense");
    dense = true;
  }
  else
  {
    Msg::Debug("Element numbering is not dense");
    dense = false;
  }
  
  return elementCache;
}

void readMSHPeriodicNodes(GModel *const model, FILE* fp, bool binary)
{
  int numPeriodicLinks;
  if(fscanf(fp, "%d", &numPeriodicLinks) != 1)
  {
    fclose(fp);
    return;
  }
  
  for(int i = 0; i < numPeriodicLinks; i++)
  {
    int slaveDim = 0, slaveTag = 0, masterTag = 0;
    
    if(fscanf(fp, "%d %d %d", &slaveDim, &slaveTag, &masterTag) != 3)
    {
      fclose(fp);
      return;
    }
    
    GEntity *slave = NULL, *master = NULL;
    switch(slaveDim)
    {
      case 0 : slave = model->getVertexByTag(slaveTag); master = model->getVertexByTag(masterTag); break;
      case 1 : slave = model->getEdgeByTag(slaveTag);   master = model->getEdgeByTag(masterTag);   break;
      case 2 : slave = model->getFaceByTag(masterTag);  master = model->getFaceByTag(masterTag);   break;
    }
    
    if(slave == NULL)
    {
      Msg::Error("Could not find periodic slave entity %d of dimension %d", slaveTag, slaveDim);
    }
    if(master == NULL)
    {
      Msg::Error("Could not find periodic master entity %d of dimension %d", masterTag, slaveDim);
    }
    
    char affine[256];

    if(fscanf(fp, "%s", affine) != 1)
    {
      fclose(fp);
      return;
    }
    
    if(strncmp(affine, "Affine", 6) == 0)
    {
      std::vector<double> tfo(16);
      for(int i = 0; i < 16; i++)
      {
        if(sscanf(affine, "%*s %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", &tfo[0], &tfo[1], &tfo[2], &tfo[3], &tfo[4], &tfo[5], &tfo[6], &tfo[7], &tfo[8], &tfo[9], &tfo[10], &tfo[11], &tfo[12], &tfo[13], &tfo[14], &tfo[15]) != 16)
        {
          fclose(fp);
          return;
        }
      }
      slave->setMeshMaster(master, tfo);
    }
    else
    {
      slave->setMeshMaster(master);
    }
    
    int correspondingVertexSize = 0;
    if(fscanf(fp, "%d", &correspondingVertexSize) != 1)
    {
      fclose(fp);
      return;
    }
    
    for(int j = 0; j < correspondingVertexSize; j++)
    {
      int v1 = 0, v2 = 0;
      if(fscanf(fp, "%d %d", &v1, &v2) != 2)
      {
        fclose(fp);
        return;
      }
      MVertex *mv1 = model->getMeshVertexByTag(v1);
      MVertex *mv2 = model->getMeshVertexByTag(v2);
      
      if(mv1 == NULL)
      {
        Msg::Error("Could not find periodic vertex %d", v1);
      }
      if(mv2 == NULL)
      {
        Msg::Error("Could not find periodic vertex %d", v2);
      }
      
      slave->correspondingVertices[mv1] = mv2;
    }
  }
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
  fprintf(fp, "%g %d %ld\n", version, (binary ? 1 : 0), sizeof(double));
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
  fprintf(fp, "$Elements\n");
  writeMSH4Elements(this, fp, CTX::instance()->mesh.num_partitions == 0 ? false : true, binary, saveAll);
  fprintf(fp, "$EndElements\n");
  
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
      
      fwrite(&verticesSize, sizeof(int), 1, fp);
      for(std::list<GVertex*>::iterator itv = vertices.begin(); itv != vertices.end(); itv++)
      {
        int brepTag = (*itv)->tag();
        fwrite(&brepTag, sizeof(int), 1, fp);
      }
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
    }
  }
  else
  {
    if(partition) fprintf(fp, "%d", CTX::instance()->mesh.num_partitions);
    fprintf(fp, "%ld %ld %ld %ld\n", vertices.size(), edges.size(), faces.size(), regions.size());
    
    for(GModel::viter it = vertices.begin(); it != vertices.end(); ++it)
    {
      fprintf(fp, "%d ", (*it)->tag());
      if(partition) fprintf(fp, "%d ", static_cast<partitionVertex*>(*it)->getParentEntity()->tag());
      SBoundingBox3d boundBox = (*it)->bounds();
      boundBox *= scalingFactor;
      fprintf(fp, "%.16g %.16g %.16g ", boundBox.min().x(), boundBox.min().y(), boundBox.min().z());
      fprintf(fp, "%.16g %.16g %.16g ", boundBox.max().x(), boundBox.max().y(), boundBox.max().z());
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
      
      SBoundingBox3d boundBox = (*it)->bounds();
      boundBox *= scalingFactor;
      fprintf(fp, "%.16g %.16g %.16g ", boundBox.min().x(), boundBox.min().y(), boundBox.min().z());
      fprintf(fp, "%.16g %.16g %.16g ", boundBox.max().x(), boundBox.max().y(), boundBox.max().z());
      
      writeMSH4Physicals(fp, *it, binary);
      
      fprintf(fp, "%ld ", vertices.size());
      for(std::list<GVertex*>::iterator itv = vertices.begin(); itv != vertices.end(); itv++)
        fprintf(fp, "%d ", (*itv)->tag());
      
      fprintf(fp, "\n");
    }
    
    for(GModel::fiter it = faces.begin(); it != faces.end(); ++it)
    {
      std::list<GEdge*> edges = (*it)->edges();
      std::list<int> ori = (*it)->edgeOrientations();
      
      fprintf(fp, "%d ", (*it)->tag());
      if(partition) fprintf(fp, "%d ", static_cast<partitionFace*>(*it)->getParentEntity()->tag());
      
      SBoundingBox3d boundBox = (*it)->bounds();
      boundBox *= scalingFactor;
      fprintf(fp, "%.16g %.16g %.16g ", boundBox.min().x(), boundBox.min().y(), boundBox.min().z());
      fprintf(fp, "%.16g %.16g %.16g ", boundBox.max().x(), boundBox.max().y(), boundBox.max().z());
      
      writeMSH4Physicals(fp, *it, binary);
      
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
      
      fprintf(fp, "\n");
    }
    
    for(GModel::riter it = regions.begin(); it != regions.end(); ++it)
    {
      std::list<GFace*> faces = (*it)->faces();
      std::list<int> ori = (*it)->faceOrientations();
      
      fprintf(fp, "%d ", (*it)->tag());
      if(partition) fprintf(fp, "%d ", static_cast<partitionRegion*>(*it)->getParentEntity()->tag());
      
      SBoundingBox3d boundBox = (*it)->bounds();
      boundBox *= scalingFactor;
      fprintf(fp, "%.16g %.16g %.16g ", boundBox.min().x(), boundBox.min().y(), boundBox.min().z());
      fprintf(fp, "%.16g %.16g %.16g ", boundBox.max().x(), boundBox.max().y(), boundBox.max().z());
      
      writeMSH4Physicals(fp, *it, binary);
      
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
    fprintf(fp, "%ld", phys.size());
    for(unsigned int i = 0; i < phys.size(); i++)
    {
      fprintf(fp, " %d", phys[i]);
    }
    fprintf(fp, " ");
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
    int globalSize = numSection*3*sizeof(int);
    if(saveParametric)
    {
      int nbrVerticesInEdge = 0, nbrVerticesInFace = 0;

      for(GModel::eiter it = edges.begin(); it != edges.end(); ++it)
      {
        nbrVerticesInEdge += (*it)->getNumMeshVertices();
      }
      for(GModel::fiter it = faces.begin(); it != faces.end(); ++it)
      {
        nbrVerticesInFace += (*it)->getNumMeshVertices();
      }
      
      globalSize += model->getNumMeshVertices()*(sizeof(int) + 3*sizeof(double)) + nbrVerticesInEdge*sizeof(double) + 2*nbrVerticesInFace*sizeof(double);
    }
    else
    {
      globalSize += model->getNumMeshVertices()*(sizeof(int) + 3*sizeof(double));
    }
    fwrite(&globalSize, sizeof(int), 1, fp);
  }
  else
  {
    fprintf(fp, "%ld %d\n", vertices.size() + edges.size() + faces.size() + regions.size(), model->getNumMeshVertices());
  }
  
  for(GModel::viter it = vertices.begin(); it != vertices.end(); ++it)
  {
    if(binary)
    {
      int entityTag = (*it)->tag();
      int entityDim = (*it)->dim();
      int numVerts = (*it)->getNumMeshVertices();
      fwrite(&entityTag, sizeof(int), 1, fp);
      fwrite(&entityDim, sizeof(int), 1, fp);
      fwrite(&numVerts, sizeof(int), 1, fp);
    }
    else
    {
      fprintf(fp, "%d %d %d\n", (*it)->tag(), (*it)->dim(), (*it)->getNumMeshVertices());
    }
    
    for(unsigned int i = 0; i < (*it)->getNumMeshVertices(); i++)
      (*it)->getMeshVertex(i)->writeMSH4(fp, binary, saveParametric, scalingFactor);
  }
    
  for(GModel::eiter it = edges.begin(); it != edges.end(); ++it)
  {
    if(binary)
    {
      int entityTag = (*it)->tag();
      int entityDim = (*it)->dim();
      int numVerts = (*it)->getNumMeshVertices();
      fwrite(&entityTag, sizeof(int), 1, fp);
      fwrite(&entityDim, sizeof(int), 1, fp);
      fwrite(&numVerts, sizeof(int), 1, fp);
    }
    else
    {
      fprintf(fp, "%d %d %d\n", (*it)->tag(), (*it)->dim(), (*it)->getNumMeshVertices());
    }
    
    for(unsigned int i = 0; i < (*it)->getNumMeshVertices(); i++)
      (*it)->getMeshVertex(i)->writeMSH4(fp, binary, saveParametric, scalingFactor);
  }
    
  for(GModel::fiter it = faces.begin(); it != faces.end(); ++it)
  {
    if(binary)
    {
      int entityTag = (*it)->tag();
      int entityDim = (*it)->dim();
      int numVerts = (*it)->getNumMeshVertices();
      fwrite(&entityTag, sizeof(int), 1, fp);
      fwrite(&entityDim, sizeof(int), 1, fp);
      fwrite(&numVerts, sizeof(int), 1, fp);
    }
    else
    {
      fprintf(fp, "%d %d %d\n", (*it)->tag(), (*it)->dim(), (*it)->getNumMeshVertices());
    }
    
    for(unsigned int i = 0; i < (*it)->getNumMeshVertices(); i++)
      (*it)->getMeshVertex(i)->writeMSH4(fp, binary, saveParametric, scalingFactor);
  }
    
  for(GModel::riter it = regions.begin(); it != regions.end(); ++it)
  {
    if(binary)
    {
      int entityTag = (*it)->tag();
      int entityDim = (*it)->dim();
      int numVerts = (*it)->getNumMeshVertices();
      fwrite(&entityTag, sizeof(int), 1, fp);
      fwrite(&entityDim, sizeof(int), 1, fp);
      fwrite(&numVerts, sizeof(int), 1, fp);
    }
    else
    {
      fprintf(fp, "%d %d %d\n", (*it)->tag(), (*it)->dim(), (*it)->getNumMeshVertices());
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
  
  std::map<std::pair<int, GEntity*>, std::vector<MElement*> > elementsByDegree;
  
  for(GModel::viter it = vertices.begin(); it != vertices.end(); ++it)
  {
    if(!saveAll && (*it)->physicals.size() == 0) continue;
    for(unsigned int i = 0; i < (*it)->points.size(); i++)
      elementsByDegree[ std::pair<int, GEntity*>((*it)->points[i]->getTypeForMSH(), *it) ].push_back((*it)->points[i]);
  }
  
  for(GModel::eiter it = edges.begin(); it != edges.end(); ++it)
  {
    if(!saveAll && (*it)->physicals.size() == 0) continue;
    for(unsigned int i = 0; i < (*it)->lines.size(); i++)
      elementsByDegree[ std::pair<int, GEntity*>((*it)->lines[i]->getTypeForMSH(), *it) ].push_back((*it)->lines[i]);
  }
  
  for(GModel::fiter it = faces.begin(); it != faces.end(); ++it)
  {
    if(!saveAll && (*it)->physicals.size() == 0) continue;
    for(unsigned int i = 0; i < (*it)->triangles.size(); i++)
      elementsByDegree[ std::pair<int, GEntity*>((*it)->triangles[i]->getTypeForMSH(), *it) ].push_back((*it)->triangles[i]);
    
    for(unsigned int i = 0; i < (*it)->quadrangles.size(); i++)
      elementsByDegree[ std::pair<int, GEntity*>((*it)->quadrangles[i]->getTypeForMSH(), *it) ].push_back((*it)->quadrangles[i]);
  }
  
  for(GModel::riter it = regions.begin(); it != regions.end(); ++it)
  {
    if(!saveAll && (*it)->physicals.size() == 0) continue;
    for(unsigned int i = 0; i < (*it)->tetrahedra.size(); i++)
      elementsByDegree[ std::pair<int, GEntity*>((*it)->tetrahedra[i]->getTypeForMSH(), *it) ].push_back((*it)->tetrahedra[i]);
    
    for(unsigned int i = 0; i < (*it)->hexahedra.size(); i++)
      elementsByDegree[ std::pair<int, GEntity*>((*it)->hexahedra[i]->getTypeForMSH(), *it) ].push_back((*it)->hexahedra[i]);
    
    for(unsigned int i = 0; i < (*it)->prisms.size(); i++)
      elementsByDegree[ std::pair<int, GEntity*>((*it)->prisms[i]->getTypeForMSH(), *it) ].push_back((*it)->prisms[i]);
    
    for(unsigned int i = 0; i < (*it)->pyramids.size(); i++)
      elementsByDegree[ std::pair<int, GEntity*>((*it)->pyramids[i]->getTypeForMSH(), *it) ].push_back((*it)->pyramids[i]);
    
    for(unsigned int i = 0; i < (*it)->trihedra.size(); i++)
      elementsByDegree[ std::pair<int, GEntity*>((*it)->trihedra[i]->getTypeForMSH(), *it) ].push_back((*it)->trihedra[i]);
  }
  
  if(binary)
  {
    int numSection = elementsByDegree.size();
    fwrite(&numSection, sizeof(int), 1, fp);
    
    int globalSize = numSection*4*sizeof(int);
    for(std::map<std::pair<int, GEntity*>, std::vector<MElement*> >::iterator it = elementsByDegree.begin(); it != elementsByDegree.end(); ++it)
    {
      const int numElm = it->second[0]->getNumVertices();
      globalSize += numElm*sizeof(int);//elementTag
      globalSize += numElm*numElm*sizeof(int);//vertexTags
    }

    fwrite(&globalSize, sizeof(int), 1, fp);
  }
  else
  {
    fprintf(fp, "%ld %d\n", elementsByDegree.size(), model->getNumMeshElements());
  }
  
  for(std::map<std::pair<int, GEntity*>, std::vector<MElement*> >::iterator it = elementsByDegree.begin(); it != elementsByDegree.end(); ++it)
  {
    if(binary)
    {
      int entityTag = it->first.second->tag();
      int entityDim = it->first.second->dim();
      int elmType = it->first.first;
      int numElm = it->second.size();
      fwrite(&entityTag, sizeof(int), 1, fp);
      fwrite(&entityDim, sizeof(int), 1, fp);
      fwrite(&elmType, sizeof(int), 1, fp);
      fwrite(&numElm, sizeof(int), 1, fp);
    }
    else
    {
      fprintf(fp, "%d %d %d %ld\n", it->first.second->tag(), it->first.second->dim(), it->first.first, it->second.size());
    }
    
    for(unsigned int i = 0; i < it->second.size(); i++)
    {
      it->second[i]->writeMSH4(fp, binary);
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
          fprintf(fp, "Affine");
          for(int j = 0; j < 16; j++)
          {
            double value = g_slave->affineTransform[i];
            fwrite(&value, sizeof(double), 1, fp);
          }
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
          fprintf(fp, "Affine");
          for(int j = 0; j < 16; j++) fprintf(fp, " %.16g", g_slave->affineTransform[i]);
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

