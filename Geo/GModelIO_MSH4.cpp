// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Anthony Royer

#include <cstdio>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <string>
#include <cstdlib>

#include "GmshDefines.h"
#include "OS.h"
#include "Context.h"
#include "GModel.h"
#include "GEntity.h"
#include "partitionRegion.h"
#include "partitionFace.h"
#include "partitionEdge.h"
#include "partitionVertex.h"
#include "ghostFace.h"
#include "ghostEdge.h"
#include "ghostRegion.h"
#include "MPoint.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "MTrihedron.h"
#include "StringUtils.h"

static bool readMSH4Physicals(GModel *const model, FILE *fp,
                              GEntity *const entity, bool binary, char *str,
                              bool swap)
{
  unsigned long numPhy = 0;
  if(binary) {
    if(fread(&numPhy, sizeof(unsigned long), 1, fp) != 1) {
      return false;
    }
    if(swap) SwapBytes((char *)&numPhy, sizeof(unsigned long), 1);

    int *phyTags = new int[numPhy];
    if(fread(phyTags, sizeof(int), numPhy, fp) != numPhy) {
      delete[] phyTags;
      return false;
    }
    if(swap) SwapBytes((char *)phyTags, sizeof(int), numPhy);

    for(unsigned int i = 0; i < numPhy; i++) {
      entity->addPhysicalEntity(phyTags[i]);
    }
    delete[] phyTags;
  }
  else {
    sscanf(str, "%lu %[0-9- ]", &numPhy, str);
    for(unsigned int i = 0; i < numPhy; i++) {
      int phyTag = 0;

      if(i == numPhy - 1 && entity->dim() == 0) {
        if(sscanf(str, "%d", &phyTag) != 1) {
          return false;
        }
      }
      else {
        if(sscanf(str, "%d %[0-9- ]", &phyTag, str) != 2) {
          return false;
        }
      }

      entity->addPhysicalEntity(phyTag);
    }
  }
  return true;
}

static bool readMSH4BoundingEntities(GModel *const model, FILE *fp,
                                     GEntity *const entity, bool binary,
                                     char *str, bool swap)
{
  unsigned long numBrep = 0;
  std::vector<GEntity *> boundingEntities;
  std::vector<int> boundingSign;

  if(binary) {
    if(fread(&numBrep, sizeof(unsigned long), 1, fp) != 1) {
      return false;
    }
    if(swap) SwapBytes((char *)&numBrep, sizeof(unsigned long), 1);

    int *brepTags = new int[numBrep];
    if(fread(brepTags, sizeof(int), numBrep, fp) != numBrep) {
      delete[] brepTags;
      return false;
    }
    if(swap) SwapBytes((char *)brepTags, sizeof(int), numBrep);

    for(unsigned int i = 0; i < numBrep; i++) {
      GEntity *brep =
        model->getEntityByTag(entity->dim() - 1, std::abs(brepTags[i]));
      if(!brep) {
        Msg::Warning("Entity %d not found in the Brep of entity %d",
                     brepTags[i], entity->tag());
        return false;
      }
      boundingEntities.push_back(brep);
      boundingSign.push_back((std::abs(brepTags[i]) == brepTags[i] ? 1 : -1));
    }
    delete[] brepTags;
  }
  else {
    sscanf(str, "%lu %[0-9- ]", &numBrep, str);
    for(unsigned int i = 0; i < numBrep; i++) {
      int entityTag = 0;

      if(i != numBrep - 1) {
        if(sscanf(str, "%d %[0-9- ]", &entityTag, str) != 2) {
          return false;
        }
      }
      else {
        if(sscanf(str, "%d", &entityTag) != 1) {
          return false;
        }
      }

      GEntity *brep =
        model->getEntityByTag(entity->dim() - 1, std::abs(entityTag));
      if(!brep) {
        Msg::Warning("Entity %d not found in the Brep of entity %d", entityTag,
                     entity->tag());
        return false;
      }
      boundingEntities.push_back(brep);
      boundingSign.push_back((std::abs(entityTag) == entityTag ? 1 : -1));
    }
  }

  switch(entity->dim()) {
  case 1:
    if(boundingEntities.size() == 2) {
      reinterpret_cast<discreteEdge *>(entity)->setBeginVertex(
        reinterpret_cast<GVertex *>(boundingEntities[0]));
      reinterpret_cast<discreteEdge *>(entity)->setEndVertex(
        reinterpret_cast<GVertex *>(boundingEntities[1]));
    }
    else if(boundingEntities.size() == 1) {
      if(boundingSign[0] == 1) {
        reinterpret_cast<discreteEdge *>(entity)->setBeginVertex(
          reinterpret_cast<GVertex *>(boundingEntities[0]));
      }
      else {
        reinterpret_cast<discreteEdge *>(entity)->setEndVertex(
          reinterpret_cast<GVertex *>(boundingEntities[0]));
      }
    }
    break;
  case 2: {
    std::vector<int> tags(boundingEntities.size());
    for(std::size_t i = 0; i < boundingEntities.size(); i++)
      tags[i] = std::abs(boundingEntities[i]->tag());
    reinterpret_cast<discreteFace *>(entity)->setBoundEdges(tags, boundingSign);
  } break;
  case 3: {
    std::vector<int> tags(boundingEntities.size());
    for(std::size_t i = 0; i < boundingEntities.size(); i++)
      tags[i] = std::abs(boundingEntities[i]->tag());
    reinterpret_cast<discreteRegion *>(entity)->setBoundFaces(tags,
                                                              boundingSign);
  } break;
  default: break;
  }
  return true;
}

static bool readMSH4EntityInfo(FILE *fp, bool binary, char *str, int sizeofstr,
                               bool swap, bool partition, int &tag,
                               int &parentDim, int &parentTag,
                               std::vector<unsigned int> &partitions,
                               double &minX, double &minY, double &minZ,
                               double &maxX, double &maxY, double &maxZ)
{
  if(partition) {
    if(binary) {
      int dataInt[4];
      double dataDouble[6];
      if(fread(dataInt, sizeof(int), 4, fp) != 4) {
        return false;
      }
      if(swap) SwapBytes((char *)dataInt, sizeof(int), 4);
      tag = dataInt[0];
      parentDim = dataInt[1];
      parentTag = dataInt[2];
      partitions.resize(dataInt[3], 0);
      if(fread(&partitions[0], sizeof(unsigned int), partitions.size(), fp) !=
         partitions.size()) {
        return false;
      }
      if(swap)
        SwapBytes((char *)&partitions[0], sizeof(unsigned int),
                  partitions.size());
      if(fread(dataDouble, sizeof(double), 6, fp) != 6) {
        return false;
      }
      if(swap) SwapBytes((char *)dataDouble, sizeof(double), 6);
      minX = dataDouble[0];
      minY = dataDouble[1];
      minZ = dataDouble[2];
      maxX = dataDouble[3];
      maxY = dataDouble[4];
      maxZ = dataDouble[5];
    }
    else {
      int numPartitions = 0;
      if(fscanf(fp, "%d %d %d %d", &tag, &parentDim, &parentTag, &numPartitions) !=
         4) {
        return false;
      }
      partitions.resize(numPartitions, 0);
      for(int i = 0; i < numPartitions; i++) {
        if(fscanf(fp, "%d", &partitions[i]) != 1) {
          return false;
        }
      }
      if(fscanf(fp, "%lf %lf %lf %lf %lf %lf", &minX, &minY, &minZ, &maxX,
                &maxY, &maxZ) != 6) {
        return false;
      }
      if(!fgets(str, sizeofstr, fp)) {
        return false;
      }
    }
  }
  else {
    if(binary) {
      int dataInt;
      double dataDouble[6];
      if(fread(&dataInt, sizeof(int), 1, fp) != 1) {
        return false;
      }
      if(swap) SwapBytes((char *)&dataInt, sizeof(int), 1);
      if(fread(dataDouble, sizeof(double), 6, fp) != 6) {
        return false;
      }
      if(swap) SwapBytes((char *)dataDouble, sizeof(double), 6);
      tag = dataInt;
      minX = dataDouble[0];
      minY = dataDouble[1];
      minZ = dataDouble[2];
      maxX = dataDouble[3];
      maxY = dataDouble[4];
      maxZ = dataDouble[5];
    }
    else {
      if(fscanf(fp, "%d %lf %lf %lf %lf %lf %lf", &tag, &minX, &minY, &minZ,
                &maxX, &maxY, &maxZ) != 7) {
        return false;
      }
      if(!fgets(str, sizeofstr, fp)) {
        return false;
      }
    }
  }
  return true;
}

static bool readMSH4Entities(GModel *const model, FILE *fp, bool partition,
                             bool binary, bool swap)
{
  if(partition) {
    int numPartitions = 0;
    unsigned int ghostSize = 0;
    int *ghostTags = 0;

    if(binary) {
      if(fread(&numPartitions, sizeof(int), 1, fp) != 1) {
        return false;
      }
      if(swap) SwapBytes((char *)&numPartitions, sizeof(int), 1);

      if(fread(&ghostSize, sizeof(int), 1, fp) != 1) {
        return false;
      }
      if(swap) SwapBytes((char *)&ghostSize, sizeof(int), 1);
      if(ghostSize) {
        ghostTags = new int[2 * ghostSize];
        if(fread(ghostTags, sizeof(int), 2 * ghostSize, fp) != 2 * ghostSize) {
          delete[] ghostTags;
          return false;
        }
        if(swap) SwapBytes((char *)ghostTags, sizeof(int), 2 * ghostSize);
      }
    }
    else {
      if(fscanf(fp, "%d", &numPartitions) != 1) {
        return false;
      }

      if(fscanf(fp, "%d", &ghostSize) != 1) {
        return false;
      }
      if(ghostSize) {
        ghostTags = new int[2 * ghostSize];
        for(unsigned int i = 0; i < 2 * ghostSize; i += 2) {
          if(fscanf(fp, "%d %d", &ghostTags[i], &ghostTags[i + 1]) != 2) {
            delete[] ghostTags;
            return false;
          }
        }
      }
    }

    model->setNumPartitions(numPartitions);
    Msg::Info("%lu partitions", model->getNumPartitions());
    for(unsigned int i = 0; i < 2 * ghostSize; i += 2) {
      switch(model->getDim()) {
      case 1: {
        ghostEdge *ghostEntities =
          new ghostEdge(model, ghostTags[i], ghostTags[i + 1]);
        model->add(ghostEntities);
      } break;
      case 2: {
        ghostFace *ghostEntities =
          new ghostFace(model, ghostTags[i], ghostTags[i + 1]);
        model->add(ghostEntities);
      } break;
      case 3: {
        ghostRegion *ghostEntities =
          new ghostRegion(model, ghostTags[i], ghostTags[i + 1]);
        model->add(ghostEntities);
      } break;
      default: break;
      }
    }

    if(ghostTags != 0){
      delete[] ghostTags;
    }
  }

  unsigned long numEntities[4] = {0, 0, 0, 0};
  if(binary) {
    if(fread(numEntities, sizeof(unsigned long), 4, fp) != 4) {
      return false;
    }
    if(swap) SwapBytes((char *)numEntities, sizeof(unsigned long), 4);
  }
  else {
    if(fscanf(fp, "%lu %lu %lu %lu", &numEntities[0], &numEntities[1],
              &numEntities[2], &numEntities[3]) != 4) {
      return false;
    }
  }

  // max length of line for ascii input file (should be large enough to handle
  // entities with many entities on their boundary)
  int nume = numEntities[0] + numEntities[1] + numEntities[2] + numEntities[3];
  unsigned int strl = std::max(4096, 128 * nume);
  char *str = new char[strl];

  for(int dim = 0; dim < 4; dim++) {
    for(unsigned int i = 0; i < numEntities[dim]; i++) {
      int tag = 0, parentDim = 0, parentTag = 0;
      std::vector<unsigned int> partitions;
      double minX = 0., minY = 0., minZ = 0., maxX = 0., maxY = 0., maxZ = 0.;
      if(!readMSH4EntityInfo(fp, binary, str, strl, swap, partition, tag,
                             parentDim, parentTag, partitions, minX, minY, minZ,
                             maxX, maxY, maxZ)){
        delete [] str;
        return false;
      }
      switch(dim) {
      case 0: {
        GVertex *gv = model->getVertexByTag(tag);
        if(!gv) {
          if(partition) {
            gv = new partitionVertex(model, tag, partitions);
            if(parentTag)
              static_cast<partitionVertex *>(gv)->setParentEntity(
                model->getEntityByTag(parentDim, parentTag));
          }
          else {
            gv = new discreteVertex(model, tag, minX, minY, minZ);
          }
          model->add(gv);
        }
        if(!readMSH4Physicals(model, fp, gv, binary, str, swap)){
          delete [] str;
          return false;
        }
      } break;
      case 1: {
        GEdge *ge = model->getEdgeByTag(tag);
        if(!ge) {
          if(partition) {
            ge = new partitionEdge(model, tag, 0, 0, partitions);
            if(parentTag)
              static_cast<partitionEdge *>(ge)->setParentEntity(
                model->getEntityByTag(parentDim, parentTag));
          }
          else {
            ge = new discreteEdge(model, tag, 0, 0);
          }
          model->add(ge);
        }
        if(!readMSH4Physicals(model, fp, ge, binary, str, swap)){
          delete [] str;
          return false;
        }
        if(!readMSH4BoundingEntities(model, fp, ge, binary, str, swap)){
          delete [] str;
          return false;
        }
      } break;
      case 2: {
        GFace *gf = model->getFaceByTag(tag);
        if(!gf) {
          if(partition) {
            gf = new partitionFace(model, tag, partitions);
            if(parentTag)
              static_cast<partitionFace *>(gf)->setParentEntity(
                model->getEntityByTag(parentDim, parentTag));
          }
          else {
            gf = new discreteFace(model, tag);
          }
          model->add(gf);
        }
        if(!readMSH4Physicals(model, fp, gf, binary, str, swap)){
          delete [] str;
          return false;
        }
        if(!readMSH4BoundingEntities(model, fp, gf, binary, str, swap)){
          delete [] str;
          return false;
        }
      } break;
      case 3: {
        GRegion *gr = model->getRegionByTag(tag);
        if(!gr) {
          if(partition) {
            gr = new partitionRegion(model, tag, partitions);
            if(parentTag)
              static_cast<partitionRegion *>(gr)->setParentEntity(
                model->getEntityByTag(parentDim, parentTag));
          }
          else {
            gr = new discreteRegion(model, tag);
          }
          model->add(gr);
        }
        if(!readMSH4Physicals(model, fp, gr, binary, str, swap)){
          delete [] str;
          return false;
        }
        if(!readMSH4BoundingEntities(model, fp, gr, binary, str, swap)){
          delete [] str;
          return false;
        }
      } break;
      }
    }
  }
  delete [] str;
  return true;
}

static std::pair<int, MVertex *> *
readMSH4Nodes(GModel *const model, FILE *fp, bool binary, bool &dense,
              unsigned long &nbrNodes, unsigned long &maxNodeNum, bool swap)
{
  unsigned long numBlock = 0;
  nbrNodes = 0;
  maxNodeNum = 0;
  if(binary) {
    unsigned long data[2];
    if(fread(data, sizeof(unsigned long), 2, fp) != 2) {
      return 0;
    }
    if(swap) SwapBytes((char *)data, sizeof(unsigned long), 2);
    numBlock = data[0];
    nbrNodes = data[1];
  }
  else {
    if(fscanf(fp, "%lu %lu", &numBlock, &nbrNodes) != 2) {
      return 0;
    }
  }

  unsigned long nodeRead = 0;
  unsigned long minNodeNum = nbrNodes + 1;
  std::pair<int, MVertex *> *vertexCache =
    new std::pair<int, MVertex *>[nbrNodes];
  Msg::Info("%lu vertices", nbrNodes);
  for(unsigned int i = 0; i < numBlock; i++) {
    int parametric = 0;
    int entityTag = 0, entityDim = 0;
    unsigned long numNodes = 0;

    if(binary) {
      int data[3];
      if(fread(data, sizeof(int), 3, fp) != 3) {
        delete [] vertexCache;
        return 0;
      }
      if(swap) SwapBytes((char *)data, sizeof(int), 3);
      entityTag = data[0];
      entityDim = data[1];
      parametric = data[2];

      unsigned long dataLong;
      if(fread(&dataLong, sizeof(unsigned long), 1, fp) != 1) {
        delete [] vertexCache;
        return 0;
      }
      if(swap) SwapBytes((char *)&dataLong, sizeof(unsigned long), 1);
      numNodes = dataLong;
    }
    else {
      if(fscanf(fp, "%d %d %d %lu", &entityTag, &entityDim, &parametric,
                &numNodes) != 4) {
        delete [] vertexCache;
        return 0;
      }
    }

    GEntity *entity = model->getEntityByTag(entityDim, entityTag);
    if(!entity) {
      Msg::Error("Unknown entity %d of dimension %d", entityTag, entityDim);
      delete [] vertexCache;
      return 0;
    }

    for(unsigned int j = 0; j < numNodes; j++) {
      double xyz[3];
      int nodeTag = 0;
      MVertex *vertex = 0;

      if(parametric) {
        double u = 0., v = 0.;

        switch(entityDim) {
        case 0:
          if(binary) {
            if(fread(&nodeTag, sizeof(int), 1, fp) != 1) {
              delete [] vertexCache;
              return 0;
            }
            if(swap) SwapBytes((char *)&nodeTag, sizeof(int), 1);

            if(fread(xyz, sizeof(double), 3, fp) != 3) {
              delete [] vertexCache;
              return 0;
            }
            if(swap) SwapBytes((char *)xyz, sizeof(double), 3);
          }
          else {
            if(fscanf(fp, "%d %lf %lf %lf", &nodeTag, &xyz[0], &xyz[1],
                      &xyz[2]) != 4) {
              delete [] vertexCache;
              return 0;
            }
          }
          vertex = new MVertex(xyz[0], xyz[1], xyz[2], entity, nodeTag);
          break;
        case 1:
          if(binary) {
            if(fread(&nodeTag, sizeof(int), 1, fp) != 1) {
              delete [] vertexCache;
              return 0;
            }
            if(swap) SwapBytes((char *)&nodeTag, sizeof(int), 1);

            if(fread(xyz, sizeof(double), 3, fp) != 3) {
              delete [] vertexCache;
              return 0;
            }
            if(swap) SwapBytes((char *)xyz, sizeof(double), 3);

            if(fread(&u, sizeof(double), 1, fp) != 1) {
              delete [] vertexCache;
              return 0;
            }
            if(swap) SwapBytes((char *)&u, sizeof(double), 1);
          }
          else {
            if(fscanf(fp, "%d %lf %lf %lf %lf", &nodeTag, &xyz[0], &xyz[1],
                      &xyz[2], &u) != 5) {
              delete [] vertexCache;
              return 0;
            }
          }
          vertex =
            new MEdgeVertex(xyz[0], xyz[1], xyz[2], entity, u, nodeTag);
          break;
        case 2:
          if(binary) {
            if(fread(&nodeTag, sizeof(int), 1, fp) != 1) {
              delete [] vertexCache;
              return 0;
            }
            if(swap) SwapBytes((char *)&nodeTag, sizeof(int), 1);

            if(fread(xyz, sizeof(double), 3, fp) != 3) {
              delete [] vertexCache;
              return 0;
            }
            if(swap) SwapBytes((char *)xyz, sizeof(double), 3);

            double uv[2];
            if(fread(uv, sizeof(double), 2, fp) != 2) {
              delete [] vertexCache;
              return 0;
            }
            if(swap) SwapBytes((char *)uv, sizeof(double), 2);

            u = uv[0];
            v = uv[1];
          }
          else {
            if(fscanf(fp, "%d %lf %lf %lf %lf %lf", &nodeTag, &xyz[0], &xyz[1],
                      &xyz[2], &u, &v) != 6) {
              delete [] vertexCache;
              return 0;
            }
          }
          vertex =
            new MFaceVertex(xyz[0], xyz[1], xyz[2], entity, u, v, nodeTag);
          break;
        case 3:
          if(binary) {
            if(fread(&nodeTag, sizeof(int), 1, fp) != 1) {
              delete [] vertexCache;
              return 0;
            }
            if(swap) SwapBytes((char *)&nodeTag, sizeof(int), 1);

            if(fread(xyz, sizeof(double), 3, fp) != 3) {
              delete [] vertexCache;
              return 0;
            }
            if(swap) SwapBytes((char *)xyz, sizeof(double), 3);
          }
          else {
            if(fscanf(fp, "%d %lf %lf %lf", &nodeTag, &xyz[0], &xyz[1],
                      &xyz[2]) != 4) {
              delete [] vertexCache;
              return 0;
            }
          }
          vertex = new MVertex(xyz[0], xyz[1], xyz[2], entity, nodeTag);
          break;
        default: delete[]vertexCache; return 0; break;
        }
      }
      else {
        if(binary) {
          if(fread(&nodeTag, sizeof(int), 1, fp) != 1) {
            delete [] vertexCache;
            return 0;
          }
          if(swap) SwapBytes((char *)&nodeTag, sizeof(int), 1);

          if(fread(xyz, sizeof(double), 3, fp) != 3) {
            delete [] vertexCache;
            return 0;
          }
          if(swap) SwapBytes((char *)xyz, sizeof(double), 3);
        }
        else {
          if(fscanf(fp, "%d %lf %lf %lf", &nodeTag, &xyz[0], &xyz[1],
                    &xyz[2]) != 4) {
            delete [] vertexCache;
            return 0;
          }
        }
        vertex = new MVertex(xyz[0], xyz[1], xyz[2], entity, nodeTag);
      }
      entity->addMeshVertex(vertex);
      vertex->setEntity(entity);
      minNodeNum = std::min(minNodeNum, (unsigned long)nodeTag);
      maxNodeNum = std::max(maxNodeNum, (unsigned long)nodeTag);

      vertexCache[nodeRead] = std::pair<int, MVertex *>(nodeTag, vertex);
      nodeRead++;

      if(nbrNodes > 100000)
        Msg::ProgressMeter(nodeRead, nbrNodes, true, "Reading nodes");
    }
  }
  // if the vertex numbering is (fairly) dense, we fill the vector cache,
  // otherwise we fill the map cache
  if(minNodeNum == 1 && maxNodeNum == nbrNodes) {
    Msg::Debug("Vertex numbering is dense");
    dense = true;
  }
  else if(maxNodeNum < 10 * nbrNodes) { //
    Msg::Debug(
      "Vertex numbering is fairly dense - still caching with a vector");
    dense = true;
  }
  else {
    Msg::Debug("Vertex numbering is not dense");
    dense = false;
  }

  return vertexCache;
}

static std::pair<int, MElement *> *
readMSH4Elements(GModel *const model, FILE *fp, bool binary, bool &dense,
                 unsigned long &nbrElements, unsigned long &maxElementNum,
                 bool swap)
{
  char str[1024];
  unsigned long numBlock = 0;
  nbrElements = 0;
  maxElementNum = 0;
  if(binary) {
    unsigned long data[2];
    if(fread(data, sizeof(unsigned long), 2, fp) != 2) {
      return 0;
    }
    if(swap) SwapBytes((char *)data, sizeof(unsigned long), 2);

    numBlock = data[0];
    nbrElements = data[1];
  }
  else {
    if(fscanf(fp, "%lu %lu", &numBlock, &nbrElements) != 2) {
      return 0;
    }
  }

  unsigned long elementRead = 0;
  unsigned long minElementNum = nbrElements + 1;
  std::pair<int, MElement *> *elementCache =
    new std::pair<int, MElement *>[nbrElements];
  Msg::Info("%lu elements", nbrElements);
  for(unsigned int i = 0; i < numBlock; i++) {
    int entityTag = 0, entityDim = 0, elmType = 0;
    unsigned long numElements = 0;

    if(binary) {
      int data[3];
      if(fread(data, sizeof(int), 3, fp) != 3) {
        delete[] elementCache;
        return 0;
      }
      if(swap) SwapBytes((char *)data, sizeof(int), 3);

      entityTag = data[0];
      entityDim = data[1];
      elmType = data[2];

      unsigned long dataLong;
      if(fread(&dataLong, sizeof(unsigned long), 1, fp) != 1) {
        delete[] elementCache;
        return 0;
      }
      if(swap) SwapBytes((char *)&dataLong, sizeof(unsigned long), 1);
      numElements = dataLong;
    }
    else {
      if(fscanf(fp, "%d %d %d %lu", &entityTag, &entityDim, &elmType,
                &numElements) != 4) {
        delete[] elementCache;
        return 0;
      }
    }

    GEntity *entity = model->getEntityByTag(entityDim, entityTag);
    if(!entity) {
      Msg::Error("Unknown entity %d of dimension %d", entityTag, entityDim);
      delete[] elementCache;
      return 0;
    }
    if(entity->geomType() == GEntity::GhostCurve) {
      static_cast<ghostEdge *>(entity)->haveMesh(true);
    }
    else if(entity->geomType() == GEntity::GhostSurface) {
      static_cast<ghostFace *>(entity)->haveMesh(true);
    }
    else if(entity->geomType() == GEntity::GhostVolume) {
      static_cast<ghostRegion *>(entity)->haveMesh(true);
    }

    int nbrVertices = MElement::getInfoMSH(elmType);
    if(binary) {
      int *data = new int[numElements * (nbrVertices + 1)];
      if(fread(data, sizeof(int), numElements * (nbrVertices + 1), fp) !=
         numElements * (nbrVertices + 1)) {
        delete[] elementCache;
        delete[] data;
        return 0;
      }
      if(swap)
        SwapBytes((char *)data, sizeof(int), numElements * (nbrVertices + 1));

      std::vector<MVertex *> vertices(nbrVertices, (MVertex *)0);
      for(unsigned int j = 0; j < numElements * (nbrVertices + 1);
          j += (nbrVertices + 1)) {
        for(int k = 0; k < nbrVertices; k++) {
          vertices[k] = model->getMeshVertexByTag(data[j + k + 1]);
          if(!vertices[k]) {
            Msg::Error("Unknown vertex %d in element %d", data[j + k + 1],
                       data[j]);
            delete[] elementCache;
            return 0;
          }
        }

        MElementFactory elementFactory;
        MElement *element = elementFactory.create(elmType, vertices, data[j], 0,
                                                  false, 0, 0, 0, 0);

        if(entity->geomType() != GEntity::GhostCurve &&
           entity->geomType() != GEntity::GhostSurface &&
           entity->geomType() != GEntity::GhostVolume) {
          entity->addElement(element->getType(), element);
        }

        minElementNum = std::min(minElementNum, (unsigned long)data[j]);
        maxElementNum = std::max(maxElementNum, (unsigned long)data[j]);

        elementCache[elementRead] =
          std::pair<int, MElement *>(data[j], element);
        elementRead++;

        if(nbrElements > 100000)
          Msg::ProgressMeter(elementRead, nbrElements, true,
                             "Reading elements");
      }

      delete[] data;
    }
    else {
      for(unsigned int j = 0; j < numElements; j++) {
        int elmTag = 0;
        if(fscanf(fp, "%d", &elmTag) != 1) {
          delete[] elementCache;
          return 0;
        }
        if(!fgets(str, sizeof(str), fp)) {
          delete[] elementCache;
          return 0;
        }

        std::vector<MVertex *> vertices(nbrVertices, (MVertex *)0);

        for(int k = 0; k < nbrVertices; k++) {
          int vertexTag = 0;
          if(k != nbrVertices - 1) {
            if(sscanf(str, "%d %[0-9- ]", &vertexTag, str) != 2) {
              delete[] elementCache;
              return 0;
            }
          }
          else {
            if(sscanf(str, "%d", &vertexTag) != 1) {
              delete[] elementCache;
              return 0;
            }
          }

          vertices[k] = model->getMeshVertexByTag(vertexTag);
          if(!vertices[k]) {
            Msg::Error("Unknown vertex %d in element %d", vertexTag, elmTag);
            delete[] elementCache;
            return 0;
          }
        }

        MElementFactory elementFactory;
        MElement *element = elementFactory.create(elmType, vertices, elmTag, 0,
                                                  false, 0, 0, 0, 0);

        if(entity->geomType() != GEntity::GhostCurve &&
           entity->geomType() != GEntity::GhostSurface &&
           entity->geomType() != GEntity::GhostVolume) {
          entity->addElement(element->getType(), element);
        }

        minElementNum = std::min(minElementNum, (unsigned long)elmTag);
        maxElementNum = std::max(maxElementNum, (unsigned long)elmTag);

        elementCache[elementRead] = std::pair<int, MElement *>(elmTag, element);
        elementRead++;

        if(nbrElements > 100000)
          Msg::ProgressMeter(elementRead, nbrElements, true,
                             "Reading elements");
      }
    }
  }
  // if the vertex numbering is dense, we fill the vector cache, otherwise we
  // fill the map cache
  if(minElementNum == 1 && maxElementNum == nbrElements) {
    Msg::Debug("Element numbering is dense");
    dense = true;
  }
  else if(maxElementNum < 10 * nbrElements) {
    Msg::Debug(
      "Element numbering is fairly dense - still caching with a vector");
    dense = true;
  }
  else {
    Msg::Debug("Element numbering is not dense");
    dense = false;
  }

  return elementCache;
}

static bool readMSH4PeriodicNodes(GModel *const model, FILE *fp, bool binary,
                                  bool swap)
{
  int numPeriodicLinks = 0;
  if(binary) {
    if(fread(&numPeriodicLinks, sizeof(int), 1, fp) != 1) {
      return false;
    }
    if(swap) SwapBytes((char *)&numPeriodicLinks, sizeof(int), 1);
  }
  else {
    if(fscanf(fp, "%d", &numPeriodicLinks) != 1) {
      return false;
    }
  }

  for(int i = 0; i < numPeriodicLinks; i++) {
    int slaveDim = 0, slaveTag = 0, masterTag = 0;

    if(binary) {
      int data[3];
      if(fread(&data, sizeof(int), 3, fp) != 3) {
        return false;
      }
      if(swap) SwapBytes((char *)data, sizeof(int), 3);
      slaveDim = data[0];
      slaveTag = data[1];
      masterTag = data[2];
    }
    else {
      if(fscanf(fp, "%d %d %d", &slaveDim, &slaveTag, &masterTag) != 3) {
        return false;
      }
    }

    GEntity *slave = 0, *master = 0;
    switch(slaveDim) {
    case 0:
      slave = model->getVertexByTag(slaveTag);
      master = model->getVertexByTag(masterTag);
      break;
    case 1:
      slave = model->getEdgeByTag(slaveTag);
      master = model->getEdgeByTag(masterTag);
      break;
    case 2:
      slave = model->getFaceByTag(masterTag);
      master = model->getFaceByTag(masterTag);
      break;
    }

    if(!slave) {
      Msg::Error("Could not find periodic slave entity %d of dimension %d",
                 slaveTag, slaveDim);
      return false;
    }
    if(!master) {
      Msg::Error("Could not find periodic master entity %d of dimension %d",
                 masterTag, slaveDim);
      return false;
    }

    long correspondingVertexSize = 0;
    if(binary) {
      if(fread(&correspondingVertexSize, sizeof(long), 1, fp) != 1) {
        return false;
      }
      if(swap) SwapBytes((char *)&correspondingVertexSize, sizeof(long), 1);

      if(correspondingVertexSize < 0) { // If there is an affine parameter
        double data[16];
        if(fread(&data, sizeof(double), 16, fp) != 16) {
          return false;
        }
        if(swap) SwapBytes((char *)data, sizeof(double), 16);

        std::vector<double> tfo(16);
        for(int j = 0; j < 16; j++) {
          tfo[j] = data[j];
        }
        slave->setMeshMaster(master, tfo);

        if(fread(&correspondingVertexSize, sizeof(long), 1, fp) != 1) {
          return false;
        }
        if(swap) SwapBytes((char *)&correspondingVertexSize, sizeof(long), 1);
      }
    }
    else {
      char affine[256];
      if(!fscanf(fp, "%s", affine)) {
        return false;
      }
      if(!strncmp(affine, "Affine", 6)) {
        if(!fgets(affine, sizeof(affine), fp)) {
          return false;
        }
        std::vector<double> tfo(16);
        if(sscanf(affine,
                  "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf "
                  "%lf %lf %lf %lf",
                  &tfo[0], &tfo[1], &tfo[2], &tfo[3], &tfo[4], &tfo[5], &tfo[6],
                  &tfo[7], &tfo[8], &tfo[9], &tfo[10], &tfo[11], &tfo[12],
                  &tfo[13], &tfo[14], &tfo[15]) != 16) {
          return false;
        }
        slave->setMeshMaster(master, tfo);
        if(fscanf(fp, "%lu", &correspondingVertexSize) != 1) {
          return false;
        }
      }
      else {
        slave->setMeshMaster(master);
        if(sscanf(affine, "%lu", &correspondingVertexSize) != 1) {
          return false;
        }
      }
    }

    for(long j = 0; j < correspondingVertexSize; j++) {
      int v1 = 0, v2 = 0;
      if(binary) {
        int data[2];
        if(fread(&data, sizeof(int), 2, fp) != 2) {
          return false;
        }
        if(swap) SwapBytes((char *)data, sizeof(int), 2);

        v1 = data[0];
        v2 = data[1];
      }
      else {
        if(fscanf(fp, "%d %d", &v1, &v2) != 2) {
          return false;
        }
      }
      MVertex *mv1 = model->getMeshVertexByTag(v1);
      MVertex *mv2 = model->getMeshVertexByTag(v2);

      if(!mv1) {
        Msg::Error("Could not find periodic vertex %d", v1);
      }
      if(!mv2) {
        Msg::Error("Could not find periodic vertex %d", v2);
      }

      slave->correspondingVertices[mv1] = mv2;
    }
  }
  return true;
}

static bool readMSH4GhostElements(GModel *const model, FILE *fp, bool binary,
                                  bool swap)
{
  int numGhostCells = 0;
  if(binary) {
    if(fread(&numGhostCells, sizeof(int), 1, fp) != 1) {
      return false;
    }
    if(swap) SwapBytes((char *)&numGhostCells, sizeof(int), 1);
  }
  else {
    if(fscanf(fp, "%d", &numGhostCells) != 1) {
      return false;
    }
  }

  std::multimap<std::pair<MElement *, unsigned int>, unsigned int> ghostCells;
  for(int i = 0; i < numGhostCells; i++) {
    int elmTag = 0;
    int partNum = 0;
    unsigned int numGhostPartitions = 0;
    char str[1024];

    if(binary) {
      int data[3];
      if(fread(&data, sizeof(int), 3, fp) != 3) {
        return false;
      }
      if(swap) SwapBytes((char *)data, sizeof(int), 3);
      elmTag = data[0];
      partNum = data[1];
      numGhostPartitions = data[2];
    }
    else {
      if(fscanf(fp, "%d %d %d", &elmTag, &partNum, &numGhostPartitions) != 3) {
        return false;
      }
      if(!fgets(str, sizeof(str), fp)) {
        return false;
      }
    }

    MElement *elm = model->getMeshElementByTag(elmTag);
    if(!elm) {
      Msg::Error("No element with tag %d", elmTag);
      continue;
    }

    for(unsigned int j = 0; j < numGhostPartitions; j++) {
      int ghostPartition = 0;

      if(binary) {
        if(fread(&ghostPartition, sizeof(int), 1, fp) != 1) {
          return false;
        }
        if(swap) SwapBytes((char *)&ghostPartition, sizeof(int), 1);
      }
      else {
        if(j == numGhostPartitions - 1) {
          if(sscanf(str, "%d", &ghostPartition) != 1) {
            return false;
          }
        }
        else {
          if(sscanf(str, "%d %[0-9- ]", &ghostPartition, str) != 2) {
            return false;
          }
        }
      }

      ghostCells.insert(
        std::pair<std::pair<MElement *, unsigned int>, unsigned int>(
          std::pair<MElement *, unsigned int>(elm, partNum), ghostPartition));
    }
  }

  std::vector<GEntity *> ghostEntities(model->getNumPartitions() + 1, 0);
  std::vector<GEntity *> entities;
  model->getEntities(entities);
  for(std::size_t i = 0; i < entities.size(); i++) {
    GEntity *ge = entities[i];
    int partNum = -1;
    if(ge->geomType() == GEntity::GhostCurve)
      partNum = static_cast<ghostEdge *>(ge)->getPartition();
    else if(ge->geomType() == GEntity::GhostSurface)
      partNum = static_cast<ghostFace *>(ge)->getPartition();
    else if(ge->geomType() == GEntity::GhostVolume)
      partNum = static_cast<ghostRegion *>(ge)->getPartition();
    if(partNum >= 0 && partNum < (int)ghostEntities.size())
      ghostEntities[partNum] = ge;
  }

  for(std::multimap<std::pair<MElement *, unsigned int>, unsigned int>::iterator
        it = ghostCells.begin(); it != ghostCells.end(); ++it) {
    if(it->second >= ghostEntities.size()){
      Msg::Error("Invalid partition %d in ghost elements", it->second);
      return false;
    }
    GEntity *ge = ghostEntities[it->second];
    if(!ge){
      Msg::Warning("Missing ghost entity on partition %d", it->second);
    }
    else if(ge->geomType() == GEntity::GhostCurve) {
      static_cast<ghostEdge *>(ge)->addElement
        (it->first.first->getType(), it->first.first, it->first.second);
    }
    else if(ge->geomType() == GEntity::GhostSurface) {
      static_cast<ghostFace *>(ge)->addElement
        (it->first.first->getType(), it->first.first, it->first.second);
    }
    else if(ge->geomType() == GEntity::GhostVolume) {
      static_cast<ghostRegion *>(ge)->addElement
        (it->first.first->getType(), it->first.first, it->first.second);
    }
  }
  return true;
}

int GModel::_readMSH4(const std::string &name)
{
  bool partitioned = false;
  FILE *fp = Fopen(name.c_str(), "rb");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  char str[1024] = "x";
  double version = 1.0;
  bool binary = false, swap = false, postpro = false;

  while(1) {
    while(str[0] != '$') {
      if(!fgets(str, sizeof(str), fp) || feof(fp)) break;
    }

    std::string sectionName(&str[1]);
    std::string endSectionName = "End" + sectionName;
    if(feof(fp)) break;

    if(!strncmp(&str[1], "MeshFormat", 10)) {
      if(!fgets(str, sizeof(str), fp) || feof(fp)) {
        fclose(fp);
        return 0;
      }

      int format;
      unsigned long size;
      if(sscanf(str, "%lf %d %lu", &version, &format, &size) != 3) {
        fclose(fp);
        return 0;
      }
      if(format) {
        binary = true;
        Msg::Debug("Mesh is in binary format");
        int one;
        if(fread(&one, sizeof(int), 1, fp) != 1) {
          fclose(fp);
          return 0;
        }
        if(one != 1) {
          swap = true;
          Msg::Debug("Swapping bytes from binary file");
        }
      }
    }
    else if(!strncmp(&str[1], "PhysicalNames", 13)) {
      if(!fgets(str, sizeof(str), fp) || feof(fp)) {
        fclose(fp);
        return 0;
      }
      int numPhysicalNames = 0;
      if(sscanf(str, "%d", &numPhysicalNames) != 1) {
        fclose(fp);
        return 0;
      }
      std::vector<GModel::piter> iterators;
      getInnerPhysicalNamesIterators(iterators);
      for(int i = 0; i < numPhysicalNames; i++) {
        int dim = 0, tag = 0;
        if(fscanf(fp, "%d %d", &dim, &tag) != 2) {
          fclose(fp);
          return 0;
        }
        char name[256];
        if(!fgets(name, sizeof(name), fp)) {
          fclose(fp);
          return 0;
        }
        std::string physicalName = ExtractDoubleQuotedString(name, 256);
        if(physicalName.size())
          iterators[dim] =
            setPhysicalName(iterators[dim], physicalName, dim, tag);
      }
    }
    else if(!strncmp(&str[1], "Entities", 8)) {
      if(!readMSH4Entities(this, fp, false, binary, swap)) {
        Msg::Error("Could not read entities");
        fclose(fp);
        return 0;
      }
    }
    else if(!strncmp(&str[1], "PartitionedEntities", 19)) {
      if(!readMSH4Entities(this, fp, true, binary, swap)) {
        Msg::Error("Could not read partitioned entities");
        fclose(fp);
        return 0;
      }
      partitioned = true;
    }
    else if(!strncmp(&str[1], "Nodes", 5)) {
      _vertexVectorCache.clear();
      _vertexMapCache.clear();
      Msg::ResetProgressMeter();
      bool dense = false;
      unsigned long nbrNodes = 0, maxNodeNum;
      std::pair<int, MVertex *> *vertexCache =
        readMSH4Nodes(this, fp, binary, dense, nbrNodes, maxNodeNum, swap);
      if(!vertexCache) {
        Msg::Error("Could not read vertices");
        fclose(fp);
        return false;
      }
      if(dense) {
        _vertexVectorCache.resize(maxNodeNum + 1, 0);
        for(unsigned int i = 0; i < nbrNodes; i++) {
          if(!_vertexVectorCache[vertexCache[i].first]) {
            _vertexVectorCache[vertexCache[i].first] = vertexCache[i].second;
          }
          else {
            Msg::Info("Skipping duplicate vertex %d", vertexCache[i].first);
          }
        }
      }
      else {
        for(unsigned int i = 0; i < nbrNodes; i++) {
          if(_vertexMapCache.count(vertexCache[i].first) == 0) {
            _vertexMapCache[vertexCache[i].first] = vertexCache[i].second;
          }
          else {
            Msg::Info("Skipping duplicate vertex %d", vertexCache[i].first);
          }
        }
      }
      delete[] vertexCache;
    }
    else if(!strncmp(&str[1], "Elements", 8)) {
      Msg::ResetProgressMeter();
      bool dense = false;
      unsigned long nbrElements = 0, maxElementNum = 0;
      std::pair<int, MElement *> *elementCache = readMSH4Elements(
        this, fp, binary, dense, nbrElements, maxElementNum, swap);
      if(!elementCache) {
        Msg::Error("Could not read elements");
        fclose(fp);
        return 0;
      }
      if(dense) {
        _elementVectorCache.resize(maxElementNum + 1, (MElement *)0);
        for(unsigned int i = 0; i < nbrElements; i++) {
          if(!_elementVectorCache[elementCache[i].first]) {
            _elementVectorCache[elementCache[i].first] = elementCache[i].second;
          }
          else {
            Msg::Info("Skipping duplicate element %d", elementCache[i].first);
          }
        }
      }
      else {
        for(unsigned int i = 0; i < nbrElements; i++) {
          if(_elementMapCache.count(elementCache[i].first) == 0) {
            _elementMapCache[elementCache[i].first] = elementCache[i].second;
          }
          else {
            Msg::Info("Skipping duplicate element %d", elementCache[i].first);
          }
        }
      }
      delete[] elementCache;
    }
    else if(!strncmp(&str[1], "Periodic", 8)) {
      if(!readMSH4PeriodicNodes(this, fp, binary, swap)) {
        Msg::Error("Could not read periodic section");
        fclose(fp);
        return 0;
      }
    }
    else if(!strncmp(&str[1], "GhostElements", 13)) {
      if(!readMSH4GhostElements(this, fp, binary, swap)) {
        Msg::Error("Could not read ghost elements");
        fclose(fp);
        return 0;
      }
    }
    else if(!strncmp(&str[1], "NodeData", 8) ||
            !strncmp(&str[1], "ElementData", 11) ||
            !strncmp(&str[1], "ElementNodeData", 15)) {
      postpro = true;
      break;
    }

    while(strncmp(&str[1], endSectionName.c_str(), endSectionName.size())) {
      if(!fgets(str, sizeof(str), fp) || feof(fp)) {
        break;
      }
    }
    str[0] = 'a';
  }

  fclose(fp);

  if(partitioned) {
    // This part is added to ensure the compatibility between the new
    // partitioning and the old one.
    std::vector<GEntity *> entities;
    getEntities(entities);
    for(std::size_t i = 0; i < entities.size(); i++) {
      if(entities[i]->geomType() == GEntity::PartitionPoint) {
        partitionVertex *pv = static_cast<partitionVertex *>(entities[i]);
        if(pv->numPartitions() == 1) {
          const unsigned int part = pv->getPartition(0);
          for(std::size_t j = 0; j < pv->getNumMeshElements(); j++) {
            pv->getMeshElement(j)->setPartition(part);
          }
        }
      }
      else if(entities[i]->geomType() == GEntity::PartitionCurve) {
        partitionEdge *pe = static_cast<partitionEdge *>(entities[i]);
        if(pe->numPartitions() == 1) {
          const unsigned int part = pe->getPartition(0);
          for(std::size_t j = 0; j < pe->getNumMeshElements(); j++) {
            pe->getMeshElement(j)->setPartition(part);
          }
        }
      }
      else if(entities[i]->geomType() == GEntity::PartitionSurface) {
        partitionFace *pf = static_cast<partitionFace *>(entities[i]);
        if(pf->numPartitions() == 1) {
          const unsigned int part = pf->getPartition(0);
          for(std::size_t j = 0; j < pf->getNumMeshElements(); j++) {
            pf->getMeshElement(j)->setPartition(part);
          }
        }
      }
      else if(entities[i]->geomType() == GEntity::PartitionVolume) {
        partitionRegion *pr = static_cast<partitionRegion *>(entities[i]);
        if(pr->numPartitions() == 1) {
          const unsigned int part = pr->getPartition(0);
          for(std::size_t j = 0; j < pr->getNumMeshElements(); j++) {
            pr->getMeshElement(j)->setPartition(part);
          }
        }
      }
    }
  }

  return postpro ? 2 : 1;
}

static void writeMSH4Physicals(FILE *fp, GEntity *const entity, bool binary)
{
  if(binary) {
    std::vector<int> phys = entity->getPhysicalEntities();
    unsigned long phySize = phys.size();
    fwrite(&phySize, sizeof(unsigned long), 1, fp);
    for(std::size_t i = 0; i < phys.size(); i++) {
      int phy = phys[i];
      fwrite(&phy, sizeof(int), 1, fp);
    }
  }
  else {
    std::vector<int> phys = entity->getPhysicalEntities();
    fprintf(fp, "%lu", phys.size());
    for(std::size_t i = 0; i < phys.size(); i++) {
      fprintf(fp, " %d", phys[i]);
    }
    fprintf(fp, " ");
  }
}

static void writeMSH4BoundingBox(SBoundingBox3d boundBox, FILE *fp,
                                 double scalingFactor, bool binary)
{
  double bb[6] = {0., 0., 0., 0., 0., 0.};
  if(!boundBox.empty()) {
    boundBox *= scalingFactor;
    bb[0] = boundBox.min().x();
    bb[1] = boundBox.min().y();
    bb[2] = boundBox.min().z();
    bb[3] = boundBox.max().x();
    bb[4] = boundBox.max().y();
    bb[5] = boundBox.max().z();
  }
  if(binary) {
    fwrite(bb, sizeof(double), 6, fp);
  }
  else {
    for(int i = 0; i < 6; i++) fprintf(fp, "%.16g ", bb[i]);
  }
}

static void writeMSH4Entities(GModel *const model, FILE *fp, bool partition,
                              bool binary, double scalingFactor)
{
  std::set<GEntity *, GEntityLessThan> ghost;
  std::set<GRegion *, GEntityLessThan> regions;
  std::set<GFace *, GEntityLessThan> faces;
  std::set<GEdge *, GEntityLessThan> edges;
  std::set<GVertex *, GEntityLessThan> vertices;

  if(partition) {
    for(GModel::viter it = model->firstVertex(); it != model->lastVertex();
        ++it) {
      if((*it)->geomType() == GEntity::PartitionPoint) vertices.insert(*it);
    }
    for(GModel::eiter it = model->firstEdge(); it != model->lastEdge(); ++it) {
      if((*it)->geomType() == GEntity::PartitionCurve) edges.insert(*it);
      if((*it)->geomType() == GEntity::GhostCurve) ghost.insert(*it);
    }
    for(GModel::fiter it = model->firstFace(); it != model->lastFace(); ++it) {
      if((*it)->geomType() == GEntity::PartitionSurface) faces.insert(*it);
      if((*it)->geomType() == GEntity::GhostSurface) ghost.insert(*it);
    }
    for(GModel::riter it = model->firstRegion(); it != model->lastRegion();
        ++it) {
      if((*it)->geomType() == GEntity::PartitionVolume) regions.insert(*it);
      if((*it)->geomType() == GEntity::GhostVolume) ghost.insert(*it);
    }
  }
  else {
    for(GModel::viter it = model->firstVertex(); it != model->lastVertex();
        ++it)
      if((*it)->geomType() != GEntity::PartitionPoint) vertices.insert(*it);
    for(GModel::eiter it = model->firstEdge(); it != model->lastEdge(); ++it)
      if((*it)->geomType() != GEntity::PartitionCurve &&
         (*it)->geomType() != GEntity::GhostCurve)
        edges.insert(*it);
    for(GModel::fiter it = model->firstFace(); it != model->lastFace(); ++it)
      if((*it)->geomType() != GEntity::PartitionSurface &&
         (*it)->geomType() != GEntity::GhostSurface)
        faces.insert(*it);
    for(GModel::riter it = model->firstRegion(); it != model->lastRegion();
        ++it)
      if((*it)->geomType() != GEntity::PartitionVolume &&
         (*it)->geomType() != GEntity::GhostVolume)
        regions.insert(*it);
  }

  if(binary) {
    if(partition) {
      unsigned int numPartitions = model->getNumPartitions();
      fwrite(&numPartitions, sizeof(unsigned int), 1, fp);

      // write the ghostentities' tag
      unsigned int ghostSize = ghost.size();
      int *tags = 0;
      if(ghostSize) {
        tags = new int[2 * ghostSize];
        int index = 0;
        for(std::set<GEntity *, GEntityLessThan>::iterator it = ghost.begin();
            it != ghost.end(); ++it) {
          if((*it)->geomType() == GEntity::GhostCurve) {
            tags[index] = (*it)->tag();
            tags[++index] = static_cast<ghostEdge *>(*it)->getPartition();
          }
          else if((*it)->geomType() == GEntity::GhostSurface) {
            tags[index] = (*it)->tag();
            tags[++index] = static_cast<ghostFace *>(*it)->getPartition();
          }
          else if((*it)->geomType() == GEntity::GhostVolume) {
            tags[index] = (*it)->tag();
            tags[++index] = static_cast<ghostRegion *>(*it)->getPartition();
          }
          index++;
        }
      }
      fwrite(&ghostSize, sizeof(int), 1, fp);
      if(tags) {
        fwrite(tags, sizeof(int), 2 * ghostSize, fp);
        delete[] tags;
      }
    }
    unsigned long verticesSize = vertices.size();
    unsigned long edgesSize = edges.size();
    unsigned long facesSize = faces.size();
    unsigned long regionsSize = regions.size();
    fwrite(&verticesSize, sizeof(unsigned long), 1, fp);
    fwrite(&edgesSize, sizeof(unsigned long), 1, fp);
    fwrite(&facesSize, sizeof(unsigned long), 1, fp);
    fwrite(&regionsSize, sizeof(unsigned long), 1, fp);

    for(GModel::viter it = vertices.begin(); it != vertices.end(); ++it) {
      int entityTag = (*it)->tag();
      fwrite(&entityTag, sizeof(int), 1, fp);
      if(partition) {
        partitionVertex *pv = static_cast<partitionVertex *>(*it);
        int parentEntityDim = 0, parentEntityTag = 0;
        if(pv->getParentEntity()) {
          parentEntityDim = pv->getParentEntity()->dim();
          parentEntityTag = pv->getParentEntity()->tag();
        }
        fwrite(&parentEntityDim, sizeof(int), 1, fp);
        fwrite(&parentEntityTag, sizeof(int), 1, fp);
        std::vector<unsigned int> partitions = pv->getPartitions();
        partitions.insert(partitions.begin(), partitions.size());
        fwrite(&partitions[0], sizeof(unsigned int), partitions.size(), fp);
      }
      writeMSH4BoundingBox((*it)->bounds(), fp, scalingFactor, binary);
      writeMSH4Physicals(fp, *it, binary);
    }

    for(GModel::eiter it = edges.begin(); it != edges.end(); ++it) {
      std::vector<GVertex *> vertices;
      std::vector<int> ori;
      if((*it)->getBeginVertex()) {
        vertices.push_back((*it)->getBeginVertex());
        ori.push_back(1);
      }
      if((*it)->getEndVertex()) { // convention that the end vertex is negative
        vertices.push_back((*it)->getEndVertex());
        ori.push_back(-1);
      }
      unsigned long verticesSize = vertices.size();
      int entityTag = (*it)->tag();
      fwrite(&entityTag, sizeof(int), 1, fp);
      if(partition) {
        partitionEdge *pe = static_cast<partitionEdge *>(*it);
        int parentEntityDim = 0, parentEntityTag = 0;
        if(pe->getParentEntity()) {
          parentEntityDim = pe->getParentEntity()->dim();
          parentEntityTag = pe->getParentEntity()->tag();
        }
        fwrite(&parentEntityDim, sizeof(int), 1, fp);
        fwrite(&parentEntityTag, sizeof(int), 1, fp);
        std::vector<unsigned int> partitions = pe->getPartitions();
        partitions.insert(partitions.begin(), partitions.size());
        fwrite(&partitions[0], sizeof(unsigned int), partitions.size(), fp);
      }
      writeMSH4BoundingBox((*it)->bounds(), fp, scalingFactor, binary);
      writeMSH4Physicals(fp, *it, binary);
      fwrite(&verticesSize, sizeof(unsigned long), 1, fp);
      int oriI = 0;
      for(std::vector<GVertex *>::const_iterator itv = vertices.begin();
          itv != vertices.end(); itv++) {
        int brepTag = ori[oriI] * (*itv)->tag();
        fwrite(&brepTag, sizeof(int), 1, fp);
        oriI++;
      }
    }

    for(GModel::fiter it = faces.begin(); it != faces.end(); ++it) {
      std::vector<GEdge *> const &edges = (*it)->edges();
      std::vector<int> const &ori = (*it)->edgeOrientations();
      unsigned long edgesSize = edges.size();
      int entityTag = (*it)->tag();
      fwrite(&entityTag, sizeof(int), 1, fp);
      if(partition) {
        partitionFace *pf = static_cast<partitionFace *>(*it);
        int parentEntityDim = 0, parentEntityTag = 0;
        if(pf->getParentEntity()) {
          parentEntityDim = pf->getParentEntity()->dim();
          parentEntityTag = pf->getParentEntity()->tag();
        }
        fwrite(&parentEntityDim, sizeof(int), 1, fp);
        fwrite(&parentEntityTag, sizeof(int), 1, fp);
        std::vector<unsigned int> partitions = pf->getPartitions();
        partitions.insert(partitions.begin(), partitions.size());
        fwrite(&partitions[0], sizeof(unsigned int), partitions.size(), fp);
      }
      writeMSH4BoundingBox((*it)->bounds(), fp, scalingFactor, binary);
      writeMSH4Physicals(fp, *it, binary);
      fwrite(&edgesSize, sizeof(unsigned long), 1, fp);
      std::vector<int> tags, signs;
      for(std::vector<GEdge *>::const_iterator ite = edges.begin();
          ite != edges.end(); ite++)
        tags.push_back((*ite)->tag());

      signs.insert(signs.end(), ori.begin(), ori.end());

      if(tags.size() == signs.size()) {
        for(unsigned int i = 0; i < tags.size(); i++)
          tags[i] *= (signs[i] > 0 ? 1 : -1);
      }
      for(unsigned int i = 0; i < tags.size(); i++) {
        int brepTag = tags[i];
        fwrite(&brepTag, sizeof(int), 1, fp);
      }
    }

    for(GModel::riter it = regions.begin(); it != regions.end(); ++it) {
      std::vector<GFace *> faces = (*it)->faces();
      std::vector<int> const &ori = (*it)->faceOrientations();
      unsigned long facesSize = faces.size();
      int entityTag = (*it)->tag();
      fwrite(&entityTag, sizeof(int), 1, fp);
      if(partition) {
        partitionRegion *pr = static_cast<partitionRegion *>(*it);
        int parentEntityDim = 0, parentEntityTag = 0;
        if(pr->getParentEntity()) {
          parentEntityDim = pr->getParentEntity()->dim();
          parentEntityTag = pr->getParentEntity()->tag();
        }
        fwrite(&parentEntityDim, sizeof(int), 1, fp);
        fwrite(&parentEntityTag, sizeof(int), 1, fp);
        std::vector<unsigned int> partitions = pr->getPartitions();
        partitions.insert(partitions.begin(), partitions.size());
        fwrite(&partitions[0], sizeof(unsigned int), partitions.size(), fp);
      }
      writeMSH4BoundingBox((*it)->bounds(), fp, scalingFactor, binary);
      writeMSH4Physicals(fp, *it, binary);
      fwrite(&facesSize, sizeof(unsigned long), 1, fp);
      std::vector<int> tags, signs;
      for(std::vector<GFace *>::iterator itf = faces.begin();
          itf != faces.end(); itf++)
        tags.push_back((*itf)->tag());
      for(std::vector<int>::const_iterator itf = ori.begin(); itf != ori.end();
          itf++)
        signs.push_back(*itf);
      if(tags.size() == signs.size()) {
        for(unsigned int i = 0; i < tags.size(); i++)
          tags[i] *= (signs[i] > 0 ? 1 : -1);
      }
      for(unsigned int i = 0; i < tags.size(); i++) {
        int brepTag = tags[i];
        fwrite(&brepTag, sizeof(int), 1, fp);
      }
    }
    fprintf(fp, "\n");
  }
  else {
    if(partition) {
      fprintf(fp, "%lu\n", model->getNumPartitions());

      // write the ghostentities' tag
      unsigned int ghostSize = ghost.size();
      int *tags = 0;
      if(ghostSize) {
        tags = new int[2 * ghostSize];
        int index = 0;
        for(std::set<GEntity *, GEntityLessThan>::iterator it = ghost.begin();
            it != ghost.end(); ++it) {
          if((*it)->geomType() == GEntity::GhostCurve) {
            tags[index] = (*it)->tag();
            tags[++index] = static_cast<ghostEdge *>(*it)->getPartition();
          }
          else if((*it)->geomType() == GEntity::GhostSurface) {
            tags[index] = (*it)->tag();
            tags[++index] = static_cast<ghostFace *>(*it)->getPartition();
          }
          else if((*it)->geomType() == GEntity::GhostVolume) {
            tags[index] = (*it)->tag();
            tags[++index] = static_cast<ghostRegion *>(*it)->getPartition();
          }
          index++;
        }
      }
      fprintf(fp, "%d\n", ghostSize);
      if(tags) {
        for(unsigned int i = 0; i < 2 * ghostSize; i += 2) {
          fprintf(fp, "%d %d\n", tags[i], tags[i + 1]);
        }
        delete[] tags;
      }
    }
    fprintf(fp, "%lu %lu %lu %lu\n", vertices.size(), edges.size(),
            faces.size(), regions.size());

    for(GModel::viter it = vertices.begin(); it != vertices.end(); ++it) {
      fprintf(fp, "%d ", (*it)->tag());
      if(partition) {
        partitionVertex *pv = static_cast<partitionVertex *>(*it);
        int parentEntityDim = 0, parentEntityTag = 0;
        if(pv->getParentEntity()) {
          parentEntityDim = pv->getParentEntity()->dim();
          parentEntityTag = pv->getParentEntity()->tag();
        }
        fprintf(fp, "%d %d ", parentEntityDim, parentEntityTag);
        std::vector<unsigned int> partitions = pv->getPartitions();
        fprintf(fp, "%d ", (int)partitions.size());
        for(std::size_t i = 0; i < partitions.size(); i++)
          fprintf(fp, "%d ", partitions[i]);
      }
      writeMSH4BoundingBox((*it)->bounds(), fp, scalingFactor, binary);
      writeMSH4Physicals(fp, *it, binary);
      fprintf(fp, "\n");
    }

    for(GModel::eiter it = edges.begin(); it != edges.end(); ++it) {
      std::vector<GVertex *> vertices;
      std::vector<int> ori;
      if((*it)->getBeginVertex()) {
        vertices.push_back((*it)->getBeginVertex());
        ori.push_back(1);
      }
      if((*it)->getEndVertex()) { // I use the convention that the end vertex is
                                  // negative
        vertices.push_back((*it)->getEndVertex());
        ori.push_back(-1);
      }
      fprintf(fp, "%d ", (*it)->tag());
      if(partition) {
        partitionEdge *pe = static_cast<partitionEdge *>(*it);
        int parentEntityDim = 0, parentEntityTag = 0;
        if(pe->getParentEntity()) {
          parentEntityDim = pe->getParentEntity()->dim();
          parentEntityTag = pe->getParentEntity()->tag();
        }
        fprintf(fp, "%d %d ", parentEntityDim, parentEntityTag);
        std::vector<unsigned int> partitions = pe->getPartitions();
        fprintf(fp, "%d ", (int)partitions.size());
        for(std::size_t i = 0; i < partitions.size(); i++)
          fprintf(fp, "%d ", partitions[i]);
      }
      writeMSH4BoundingBox((*it)->bounds(), fp, scalingFactor, binary);
      writeMSH4Physicals(fp, *it, binary);
      fprintf(fp, "%lu ", vertices.size());
      int oriI = 0;
      for(std::vector<GVertex *>::iterator itv = vertices.begin();
          itv != vertices.end(); itv++) {
        fprintf(fp, "%d ", ori[oriI] * (*itv)->tag());
        oriI++;
      }
      fprintf(fp, "\n");
    }

    for(GModel::fiter it = faces.begin(); it != faces.end(); ++it) {
      std::vector<GEdge *> const &edges = (*it)->edges();
      std::vector<int> const &ori = (*it)->edgeOrientations();
      fprintf(fp, "%d ", (*it)->tag());
      if(partition) {
        partitionFace *pf = static_cast<partitionFace *>(*it);
        int parentEntityDim = 0, parentEntityTag = 0;
        if(pf->getParentEntity()) {
          parentEntityDim = pf->getParentEntity()->dim();
          parentEntityTag = pf->getParentEntity()->tag();
        }
        fprintf(fp, "%d %d ", parentEntityDim, parentEntityTag);
        std::vector<unsigned int> partitions = pf->getPartitions();
        fprintf(fp, "%d ", (int)partitions.size());
        for(std::size_t i = 0; i < partitions.size(); i++)
          fprintf(fp, "%d ", partitions[i]);
      }
      writeMSH4BoundingBox((*it)->bounds(), fp, scalingFactor, binary);
      writeMSH4Physicals(fp, *it, binary);
      fprintf(fp, "%lu ", edges.size());
      std::vector<int> tags, signs;
      for(std::vector<GEdge *>::const_iterator ite = edges.begin();
          ite != edges.end(); ite++)
        tags.push_back((*ite)->tag());
      for(std::vector<int>::const_iterator ite = ori.begin(); ite != ori.end();
          ite++)
        signs.push_back(*ite);
      if(tags.size() == signs.size()) {
        for(std::size_t i = 0; i < tags.size(); i++)
          tags[i] *= (signs[i] > 0 ? 1 : -1);
      }
      for(std::size_t i = 0; i < tags.size(); i++) fprintf(fp, "%d ", tags[i]);
      fprintf(fp, "\n");
    }

    for(GModel::riter it = regions.begin(); it != regions.end(); ++it) {
      std::vector<GFace *> const &faces = (*it)->faces();
      std::vector<int> const &ori = (*it)->faceOrientations();
      fprintf(fp, "%d ", (*it)->tag());
      if(partition) {
        partitionRegion *pr = static_cast<partitionRegion *>(*it);
        int parentEntityDim = 0, parentEntityTag = 0;
        if(pr->getParentEntity()) {
          parentEntityDim = pr->getParentEntity()->dim();
          parentEntityTag = pr->getParentEntity()->tag();
        }
        fprintf(fp, "%d %d ", parentEntityDim, parentEntityTag);
        std::vector<unsigned int> partitions = pr->getPartitions();
        fprintf(fp, "%d ", (int)partitions.size());
        for(std::size_t i = 0; i < partitions.size(); i++)
          fprintf(fp, "%d ", partitions[i]);
      }
      writeMSH4BoundingBox((*it)->bounds(), fp, scalingFactor, binary);
      writeMSH4Physicals(fp, *it, binary);
      fprintf(fp, "%lu ", faces.size());
      // TODO C++11 std::transform or similiar
      std::vector<int> tags;
      tags.reserve(faces.size());
      for(std::vector<GFace *>::const_iterator itf = faces.begin();
          itf != faces.end(); itf++)
        tags.push_back((*itf)->tag());

      std::vector<int> signs(ori.begin(), ori.end());

      if(tags.size() == signs.size()) {
        for(std::size_t i = 0; i < tags.size(); i++)
          tags[i] *= (signs[i] > 0 ? 1 : -1);
      }
      for(std::size_t i = 0; i < tags.size(); i++) fprintf(fp, "%d ", tags[i]);
      fprintf(fp, "\n");
    }
  }
}

static unsigned long
getAdditionalEntities(std::set<GRegion *, GEntityLessThan> &regions,
                      std::set<GFace *, GEntityLessThan> &faces,
                      std::set<GEdge *, GEntityLessThan> &edges,
                      std::set<GVertex *, GEntityLessThan> &vertices)
{
  unsigned long numVertices = 0;

  for(std::set<GVertex *, GEntityLessThan>::iterator it = vertices.begin();
      it != vertices.end(); ++it) {
    numVertices += (*it)->getNumMeshVertices();
  }

  for(std::set<GEdge *, GEntityLessThan>::iterator it = edges.begin();
      it != edges.end(); ++it) {
    numVertices += (*it)->getNumMeshVertices();
    for(std::size_t i = 0; i < (*it)->getNumMeshElements(); i++) {
      for(std::size_t j = 0;
          j < (*it)->getMeshElement(i)->getNumVertices(); j++) {
        if((*it)->getMeshElement(i)->getVertex(j)->onWhat() != (*it)) {
          GEntity *entity = (*it)->getMeshElement(i)->getVertex(j)->onWhat();

          switch(entity->dim()) {
          case 0:
            if(vertices.find(static_cast<GVertex *>(entity)) ==
               vertices.end()) {
              vertices.insert(static_cast<GVertex *>(entity));
              numVertices += entity->getNumMeshVertices();
            }
            break;
          case 1:
            if(edges.find(static_cast<GEdge *>(entity)) == edges.end()) {
              edges.insert(static_cast<GEdge *>(entity));
              numVertices += entity->getNumMeshVertices();
            }
            break;
          case 2:
            if(faces.find(static_cast<GFace *>(entity)) == faces.end()) {
              faces.insert(static_cast<GFace *>(entity));
              numVertices += entity->getNumMeshVertices();
            }
            break;
          case 3:
            if(regions.find(static_cast<GRegion *>(entity)) == regions.end()) {
              regions.insert(static_cast<GRegion *>(entity));
              numVertices += entity->getNumMeshVertices();
            }
            break;
          default: break;
          }
        }
      }
    }
  }

  for(std::set<GFace *, GEntityLessThan>::iterator it = faces.begin();
      it != faces.end(); ++it) {
    numVertices += (*it)->getNumMeshVertices();
    for(std::size_t i = 0; i < (*it)->getNumMeshElements(); i++) {
      for(std::size_t j = 0;
          j < (*it)->getMeshElement(i)->getNumVertices(); j++) {
        if((*it)->getMeshElement(i)->getVertex(j)->onWhat() != (*it)) {
          GEntity *entity = (*it)->getMeshElement(i)->getVertex(j)->onWhat();

          switch(entity->dim()) {
          case 0:
            if(vertices.find(static_cast<GVertex *>(entity)) ==
               vertices.end()) {
              vertices.insert(static_cast<GVertex *>(entity));
              numVertices += entity->getNumMeshVertices();
            }
            break;
          case 1:
            if(edges.find(static_cast<GEdge *>(entity)) == edges.end()) {
              edges.insert(static_cast<GEdge *>(entity));
              numVertices += entity->getNumMeshVertices();
            }
            break;
          case 2:
            if(faces.find(static_cast<GFace *>(entity)) == faces.end()) {
              faces.insert(static_cast<GFace *>(entity));
              numVertices += entity->getNumMeshVertices();
            }
            break;
          case 3:
            if(regions.find(static_cast<GRegion *>(entity)) == regions.end()) {
              regions.insert(static_cast<GRegion *>(entity));
              numVertices += entity->getNumMeshVertices();
            }
            break;
          default: break;
          }
        }
      }
    }
  }

  for(std::set<GRegion *, GEntityLessThan>::iterator it = regions.begin();
      it != regions.end(); ++it) {
    numVertices += (*it)->getNumMeshVertices();
    for(std::size_t i = 0; i < (*it)->getNumMeshElements(); i++) {
      for(std::size_t j = 0;
          j < (*it)->getMeshElement(i)->getNumVertices(); j++) {
        if((*it)->getMeshElement(i)->getVertex(j)->onWhat() != (*it)) {
          GEntity *entity = (*it)->getMeshElement(i)->getVertex(j)->onWhat();

          switch(entity->dim()) {
          case 0:
            if(vertices.find(static_cast<GVertex *>(entity)) ==
               vertices.end()) {
              vertices.insert(static_cast<GVertex *>(entity));
              numVertices += entity->getNumMeshVertices();
            }
            break;
          case 1:
            if(edges.find(static_cast<GEdge *>(entity)) == edges.end()) {
              edges.insert(static_cast<GEdge *>(entity));
              numVertices += entity->getNumMeshVertices();
            }
            break;
          case 2:
            if(faces.find(static_cast<GFace *>(entity)) == faces.end()) {
              faces.insert(static_cast<GFace *>(entity));
              numVertices += entity->getNumMeshVertices();
            }
            break;
          case 3:
            if(regions.find(static_cast<GRegion *>(entity)) == regions.end()) {
              regions.insert(static_cast<GRegion *>(entity));
              numVertices += entity->getNumMeshVertices();
            }
            break;
          default: break;
          }
        }
      }
    }
  }

  return numVertices;
}

static void writeMSH4Nodes(GModel *const model, FILE *fp, bool partitioned,
                           bool binary, int saveParametric,
                           double scalingFactor, bool saveAll)
{
  std::set<GRegion *, GEntityLessThan> regions;
  std::set<GFace *, GEntityLessThan> faces;
  std::set<GEdge *, GEntityLessThan> edges;
  std::set<GVertex *, GEntityLessThan> vertices;

  if(partitioned) {
    for(GModel::viter it = model->firstVertex(); it != model->lastVertex();
        ++it)
      if((*it)->geomType() == GEntity::PartitionPoint) vertices.insert(*it);
    for(GModel::eiter it = model->firstEdge(); it != model->lastEdge(); ++it) {
      if((*it)->geomType() == GEntity::PartitionCurve)
        edges.insert(*it);
      else if((*it)->geomType() == GEntity::GhostCurve)
        if(static_cast<ghostEdge *>(*it)->saveMesh()) edges.insert(*it);
    }
    for(GModel::fiter it = model->firstFace(); it != model->lastFace(); ++it) {
      if((*it)->geomType() == GEntity::PartitionSurface)
        faces.insert(*it);
      else if((*it)->geomType() == GEntity::GhostSurface)
        if(static_cast<ghostFace *>(*it)->saveMesh()) faces.insert(*it);
    }
    for(GModel::riter it = model->firstRegion(); it != model->lastRegion();
        ++it) {
      if((*it)->geomType() == GEntity::PartitionVolume)
        regions.insert(*it);
      else if((*it)->geomType() == GEntity::GhostVolume)
        if(static_cast<ghostRegion *>(*it)->saveMesh()) regions.insert(*it);
    }
  }
  else {
    for(GModel::viter it = model->firstVertex(); it != model->lastVertex();
        ++it)
      if((*it)->geomType() != GEntity::PartitionPoint &&
         (saveAll || (!saveAll && (*it)->getPhysicalEntities().size() != 0)))
        vertices.insert(*it);
    for(GModel::eiter it = model->firstEdge(); it != model->lastEdge(); ++it)
      if((*it)->geomType() != GEntity::PartitionCurve &&
         (saveAll || (!saveAll && (*it)->getPhysicalEntities().size() != 0) ||
          (*it)->geomType() == GEntity::GhostCurve))
        edges.insert(*it);
    for(GModel::fiter it = model->firstFace(); it != model->lastFace(); ++it)
      if((*it)->geomType() != GEntity::PartitionSurface &&
         (saveAll || (!saveAll && (*it)->getPhysicalEntities().size() != 0) ||
          (*it)->geomType() == GEntity::GhostSurface))
        faces.insert(*it);
    for(GModel::riter it = model->firstRegion(); it != model->lastRegion();
        ++it)
      if((*it)->geomType() != GEntity::PartitionVolume &&
         (saveAll || (!saveAll && (*it)->getPhysicalEntities().size() != 0) ||
          (*it)->geomType() == GEntity::GhostVolume))
        regions.insert(*it);
  }

  unsigned long numVertices = model->getNumMeshVertices();
  if(!saveAll && !partitioned) {
    numVertices = getAdditionalEntities(regions, faces, edges, vertices);
  }

  if(binary) {
    unsigned long numSection =
      vertices.size() + edges.size() + faces.size() + regions.size();
    fwrite(&numSection, sizeof(unsigned long), 1, fp);
    fwrite(&numVertices, sizeof(unsigned long), 1, fp);
  }
  else {
    fprintf(fp, "%lu %lu\n",
            vertices.size() + edges.size() + faces.size() + regions.size(),
            numVertices);
  }

  for(GModel::viter it = vertices.begin(); it != vertices.end(); ++it) {
    if(binary) {
      int entityTag = (*it)->tag();
      int entityDim = (*it)->dim();
      unsigned long numVerts = (*it)->getNumMeshVertices();
      fwrite(&entityTag, sizeof(int), 1, fp);
      fwrite(&entityDim, sizeof(int), 1, fp);
      fwrite(&saveParametric, sizeof(int), 1, fp);
      fwrite(&numVerts, sizeof(unsigned long), 1, fp);
    }
    else {
      fprintf(fp, "%d %d %d %lu\n", (*it)->tag(), (*it)->dim(), saveParametric,
              (unsigned long)(*it)->getNumMeshVertices());
    }

    for(std::size_t i = 0; i < (*it)->getNumMeshVertices(); i++)
      (*it)->getMeshVertex(i)->writeMSH4(fp, binary, saveParametric,
                                         scalingFactor);
  }

  for(GModel::eiter it = edges.begin(); it != edges.end(); ++it) {
    if(binary) {
      int entityTag = (*it)->tag();
      int entityDim = (*it)->dim();
      unsigned long numVerts = (*it)->getNumMeshVertices();
      fwrite(&entityTag, sizeof(int), 1, fp);
      fwrite(&entityDim, sizeof(int), 1, fp);
      fwrite(&saveParametric, sizeof(int), 1, fp);
      fwrite(&numVerts, sizeof(unsigned long), 1, fp);
    }
    else {
      fprintf(fp, "%d %d %d %lu\n", (*it)->tag(), (*it)->dim(), saveParametric,
              (unsigned long)(*it)->getNumMeshVertices());
    }

    for(std::size_t i = 0; i < (*it)->getNumMeshVertices(); i++)
      (*it)->getMeshVertex(i)->writeMSH4(fp, binary, saveParametric,
                                         scalingFactor);
  }

  for(GModel::fiter it = faces.begin(); it != faces.end(); ++it) {
    if(binary) {
      int entityTag = (*it)->tag();
      int entityDim = (*it)->dim();
      unsigned long numVerts = (*it)->getNumMeshVertices();
      fwrite(&entityTag, sizeof(int), 1, fp);
      fwrite(&entityDim, sizeof(int), 1, fp);
      fwrite(&saveParametric, sizeof(int), 1, fp);
      fwrite(&numVerts, sizeof(unsigned long), 1, fp);
    }
    else {
      fprintf(fp, "%d %d %d %lu\n", (*it)->tag(), (*it)->dim(), saveParametric,
              (unsigned long)(*it)->getNumMeshVertices());
    }

    for(std::size_t i = 0; i < (*it)->getNumMeshVertices(); i++)
      (*it)->getMeshVertex(i)->writeMSH4(fp, binary, saveParametric,
                                         scalingFactor);
  }

  for(GModel::riter it = regions.begin(); it != regions.end(); ++it) {
    if(binary) {
      int entityTag = (*it)->tag();
      int entityDim = (*it)->dim();
      unsigned long numVerts = (*it)->getNumMeshVertices();
      fwrite(&entityTag, sizeof(int), 1, fp);
      fwrite(&entityDim, sizeof(int), 1, fp);
      fwrite(&saveParametric, sizeof(int), 1, fp);
      fwrite(&numVerts, sizeof(unsigned long), 1, fp);
    }
    else {
      fprintf(fp, "%d %d %d %lu\n", (*it)->tag(), (*it)->dim(), saveParametric,
              (unsigned long)(*it)->getNumMeshVertices());
    }

    for(std::size_t i = 0; i < (*it)->getNumMeshVertices(); i++)
      (*it)->getMeshVertex(i)->writeMSH4(fp, binary, saveParametric,
                                         scalingFactor);
  }

  if(binary) fprintf(fp, "\n");
}

static void writeMSH4Elements(GModel *const model, FILE *fp, bool partitioned,
                              bool binary, bool saveAll)
{
  std::set<GRegion *, GEntityLessThan> regions;
  std::set<GFace *, GEntityLessThan> faces;
  std::set<GEdge *, GEntityLessThan> edges;
  std::set<GVertex *, GEntityLessThan> vertices;

  if(partitioned) {
    for(GModel::viter it = model->firstVertex(); it != model->lastVertex();
        ++it)
      if((*it)->geomType() == GEntity::PartitionPoint) vertices.insert(*it);
    for(GModel::eiter it = model->firstEdge(); it != model->lastEdge(); ++it) {
      if((*it)->geomType() == GEntity::PartitionCurve)
        edges.insert(*it);
      else if((*it)->geomType() == GEntity::GhostCurve)
        if(static_cast<ghostEdge *>(*it)->saveMesh()) edges.insert(*it);
    }
    for(GModel::fiter it = model->firstFace(); it != model->lastFace(); ++it) {
      if((*it)->geomType() == GEntity::PartitionSurface)
        faces.insert(*it);
      else if((*it)->geomType() == GEntity::GhostSurface)
        if(static_cast<ghostFace *>(*it)->saveMesh()) faces.insert(*it);
    }
    for(GModel::riter it = model->firstRegion(); it != model->lastRegion();
        ++it) {
      if((*it)->geomType() == GEntity::PartitionVolume)
        regions.insert(*it);
      else if((*it)->geomType() == GEntity::GhostVolume)
        if(static_cast<ghostRegion *>(*it)->saveMesh()) regions.insert(*it);
    }
  }
  else {
    for(GModel::viter it = model->firstVertex(); it != model->lastVertex();
        ++it)
      if((*it)->geomType() != GEntity::PartitionPoint) vertices.insert(*it);
    for(GModel::eiter it = model->firstEdge(); it != model->lastEdge(); ++it)
      if((*it)->geomType() != GEntity::PartitionCurve &&
         (*it)->geomType() != GEntity::GhostCurve)
        edges.insert(*it);
    for(GModel::fiter it = model->firstFace(); it != model->lastFace(); ++it)
      if((*it)->geomType() != GEntity::PartitionSurface &&
         (*it)->geomType() != GEntity::GhostSurface)
        faces.insert(*it);
    for(GModel::riter it = model->firstRegion(); it != model->lastRegion();
        ++it)
      if((*it)->geomType() != GEntity::PartitionVolume &&
         (*it)->geomType() != GEntity::GhostVolume)
        regions.insert(*it);
  }

  std::map<std::pair<int, int>, std::vector<MElement *> > elementsByDegree[4];
  unsigned long numElements = 0;

  for(GModel::viter it = vertices.begin(); it != vertices.end(); ++it) {
    if(!saveAll && (*it)->physicals.size() == 0) continue;

    numElements += (*it)->points.size();
    for(std::size_t i = 0; i < (*it)->points.size(); i++) {
      std::pair<int, int> p((*it)->tag(), (*it)->points[i]->getTypeForMSH());
      elementsByDegree[0][p].push_back((*it)->points[i]);
    }
  }

  for(GModel::eiter it = edges.begin(); it != edges.end(); ++it) {
    if(!saveAll && (*it)->physicals.size() == 0 &&
       (*it)->geomType() != GEntity::GhostCurve)
      continue;

    numElements += (*it)->lines.size();
    for(std::size_t i = 0; i < (*it)->lines.size(); i++) {
      std::pair<int, int> p((*it)->tag(), (*it)->lines[i]->getTypeForMSH());
      elementsByDegree[1][p].push_back((*it)->lines[i]);
    }
  }

  for(GModel::fiter it = faces.begin(); it != faces.end(); ++it) {
    if(!saveAll && (*it)->physicals.size() == 0 &&
       (*it)->geomType() != GEntity::GhostSurface)
      continue;

    numElements += (*it)->triangles.size();
    for(std::size_t i = 0; i < (*it)->triangles.size(); i++) {
      std::pair<int, int> p((*it)->tag(), (*it)->triangles[i]->getTypeForMSH());
      elementsByDegree[2][p].push_back((*it)->triangles[i]);
    }
    numElements += (*it)->quadrangles.size();
    for(std::size_t i = 0; i < (*it)->quadrangles.size(); i++) {
      std::pair<int, int> p((*it)->tag(),
                            (*it)->quadrangles[i]->getTypeForMSH());
      elementsByDegree[2][p].push_back((*it)->quadrangles[i]);
    }
  }

  for(GModel::riter it = regions.begin(); it != regions.end(); ++it) {
    if(!saveAll && (*it)->physicals.size() == 0 &&
       (*it)->geomType() != GEntity::GhostVolume)
      continue;

    numElements += (*it)->tetrahedra.size();
    for(std::size_t i = 0; i < (*it)->tetrahedra.size(); i++) {
      std::pair<int, int> p((*it)->tag(),
                            (*it)->tetrahedra[i]->getTypeForMSH());
      elementsByDegree[3][p].push_back((*it)->tetrahedra[i]);
    }
    numElements += (*it)->hexahedra.size();
    for(std::size_t i = 0; i < (*it)->hexahedra.size(); i++) {
      std::pair<int, int> p((*it)->tag(), (*it)->hexahedra[i]->getTypeForMSH());
      elementsByDegree[3][p].push_back((*it)->hexahedra[i]);
    }
    numElements += (*it)->prisms.size();
    for(std::size_t i = 0; i < (*it)->prisms.size(); i++) {
      std::pair<int, int> p((*it)->tag(), (*it)->prisms[i]->getTypeForMSH());
      elementsByDegree[3][p].push_back((*it)->prisms[i]);
    }
    numElements += (*it)->pyramids.size();
    for(std::size_t i = 0; i < (*it)->pyramids.size(); i++) {
      std::pair<int, int> p((*it)->tag(), (*it)->pyramids[i]->getTypeForMSH());
      elementsByDegree[3][p].push_back((*it)->pyramids[i]);
    }
    numElements += (*it)->trihedra.size();
    for(std::size_t i = 0; i < (*it)->trihedra.size(); i++) {
      std::pair<int, int> p((*it)->tag(), (*it)->trihedra[i]->getTypeForMSH());
      elementsByDegree[3][p].push_back((*it)->trihedra[i]);
    }
  }

  unsigned long numSection = 0;
  for(int dim = 0; dim <= 3; dim++) numSection += elementsByDegree[dim].size();

  if(binary) {
    fwrite(&numSection, sizeof(unsigned long), 1, fp);
    fwrite(&numElements, sizeof(unsigned long), 1, fp);
  }
  else {
    fprintf(fp, "%lu %lu\n", numSection, numElements);
  }

  for(int dim = 0; dim <= 3; dim++) {
    for(std::map<std::pair<int, int>, std::vector<MElement *> >::iterator it =
          elementsByDegree[dim].begin();
        it != elementsByDegree[dim].end(); ++it) {
      int entityTag = it->first.first;
      int elmType = it->first.second;
      unsigned long elmTag = it->second.size();
      if(binary) {
        fwrite(&entityTag, sizeof(int), 1, fp);
        fwrite(&dim, sizeof(int), 1, fp);
        fwrite(&elmType, sizeof(int), 1, fp);
        fwrite(&elmTag, sizeof(unsigned long), 1, fp);
      }
      else {
        fprintf(fp, "%d %d %d %lu\n", entityTag, dim, elmType, elmTag);
      }

      if(binary) {
        const int nbrVertices = MElement::getInfoMSH(elmType);
        int indexElement = 0;
        int *elementData = new int[it->second.size() * (nbrVertices + 1)];
        for(std::size_t i = 0; i < it->second.size() * (nbrVertices + 1);
            i += (nbrVertices + 1)) {
          elementData[i] = it->second[indexElement]->getNum();
          for(int j = 0; j < nbrVertices; j++) {
            elementData[i + 1 + j] =
              it->second[indexElement]->getVertex(j)->getNum();
          }
          indexElement++;
        }
        fwrite(elementData, sizeof(int), it->second.size() * (nbrVertices + 1),
               fp);
        delete[] elementData;
      }
      else {
        for(std::size_t i = 0; i < it->second.size(); i++) {
          it->second[i]->writeMSH4(fp, binary);
        }
      }
    }
  }

  if(binary) fprintf(fp, "\n");
}

static void writeMSH4PeriodicNodes(GModel *const model, FILE *fp,
                                   bool partitioned, bool binary)
{
  int count = 0;
  std::vector<GEntity *> entities;
  model->getEntities(entities);
  for(std::size_t i = 0; i < entities.size(); i++)
    if(entities[i]->getMeshMaster() != entities[i]) count++;

  if(!count) return;

  fprintf(fp, "$Periodic\n");

  if(binary) {
    fwrite(&count, sizeof(int), 1, fp);
  }
  else {
    fprintf(fp, "%d\n", count);
  }

  for(std::size_t i = 0; i < entities.size(); i++) {
    GEntity *g_slave = entities[i];
    GEntity *g_master = g_slave->getMeshMaster();

    if(g_slave != g_master) {
      if(binary) {
        int gSlaveDim = g_slave->dim();
        int gSlaveTag = g_slave->tag();
        int gMasterTag = g_master->tag();
        fwrite(&gSlaveDim, sizeof(int), 1, fp);
        fwrite(&gSlaveTag, sizeof(int), 1, fp);
        fwrite(&gMasterTag, sizeof(int), 1, fp);

        if(g_slave->affineTransform.size() == 16) {
          long AffineTag = -1;
          fwrite(&AffineTag, sizeof(long), 1, fp);
          for(int j = 0; j < 16; j++) {
            double value = g_slave->affineTransform[j];
            fwrite(&value, sizeof(double), 1, fp);
          }
        }

        long corrVertSize = g_slave->correspondingVertices.size();
        fwrite(&corrVertSize, sizeof(long), 1, fp);

        for(std::map<MVertex *, MVertex *>::iterator it =
              g_slave->correspondingVertices.begin();
            it != g_slave->correspondingVertices.end(); ++it) {
          int numFirst = it->first->getNum();
          int numSecond = it->second->getNum();
          fwrite(&numFirst, sizeof(int), 1, fp);
          fwrite(&numSecond, sizeof(int), 1, fp);
        }
      }
      else {
        fprintf(fp, "%d %d %d\n", g_slave->dim(), g_slave->tag(),
                g_master->tag());

        if(g_slave->affineTransform.size() == 16) {
          fprintf(fp, "Affine");
          for(int j = 0; j < 16; j++)
            fprintf(fp, " %.16g", g_slave->affineTransform[j]);
          fprintf(fp, "\n");
        }

        fprintf(fp, "%lu\n", g_slave->correspondingVertices.size());

        for(std::map<MVertex *, MVertex *>::iterator it =
              g_slave->correspondingVertices.begin();
            it != g_slave->correspondingVertices.end(); ++it) {
          fprintf(fp, "%lu %lu\n", it->first->getNum(), it->second->getNum());
        }
      }
    }
  }

  if(binary) fprintf(fp, "\n");
  fprintf(fp, "$EndPeriodic\n");
}

static void writeMSH4GhostCells(GModel *const model, FILE *fp, bool binary)
{
  std::vector<GEntity *> entities;
  model->getEntities(entities);
  std::map<MElement *, std::vector<unsigned int> > ghostCells;

  for(std::size_t i = 0; i < entities.size(); i++) {
    std::map<MElement *, unsigned int> ghostElements;
    unsigned int partition;

    if(entities[i]->geomType() == GEntity::GhostCurve) {
      ghostElements = static_cast<ghostEdge *>(entities[i])->getGhostCells();
      partition = static_cast<ghostEdge *>(entities[i])->getPartition();
    }
    else if(entities[i]->geomType() == GEntity::GhostSurface) {
      ghostElements = static_cast<ghostFace *>(entities[i])->getGhostCells();
      partition = static_cast<ghostFace *>(entities[i])->getPartition();
    }
    else if(entities[i]->geomType() == GEntity::GhostVolume) {
      ghostElements = static_cast<ghostRegion *>(entities[i])->getGhostCells();
      partition = static_cast<ghostRegion *>(entities[i])->getPartition();
    }

    for(std::map<MElement *, unsigned int>::iterator it = ghostElements.begin();
        it != ghostElements.end(); ++it) {
      if(ghostCells[it->first].size() == 0)
        ghostCells[it->first].push_back(it->second);
      ghostCells[it->first].push_back(partition);
    }
  }

  if(ghostCells.size() != 0) {
    fprintf(fp, "$GhostElements\n");
    if(binary) {
      int ghostCellsSize = ghostCells.size();
      fwrite(&ghostCellsSize, sizeof(int), 1, fp);

      for(std::map<MElement *, std::vector<unsigned int> >::iterator it =
            ghostCells.begin(); it != ghostCells.end(); ++it) {
        int elmTag = it->first->getNum();
        unsigned int partNum = it->second[0];
        unsigned int numGhostPartitions = it->second.size() - 1;
        fwrite(&elmTag, sizeof(int), 1, fp);
        fwrite(&partNum, sizeof(unsigned int), 1, fp);
        fwrite(&numGhostPartitions, sizeof(unsigned int), 1, fp);
        for(std::size_t i = 1; i < it->second.size(); i++) {
          fwrite(&it->second[i], sizeof(int), 1, fp);
        }
      }
      fprintf(fp, "\n");
    }
    else {
      fprintf(fp, "%ld\n", ghostCells.size());

      for(std::map<MElement *, std::vector<unsigned int> >::iterator it =
            ghostCells.begin();
          it != ghostCells.end(); ++it) {
        fprintf(fp, "%d %d %ld", it->first->getNum(), it->second[0],
                it->second.size() - 1);
        for(std::size_t i = 1; i < it->second.size(); i++) {
          fprintf(fp, " %d", it->second[i]);
        }
        fprintf(fp, "\n");
      }
    }
    fprintf(fp, "$EndGhostElements\n");
  }
}

int GModel::_writeMSH4(const std::string &name, double version, bool binary,
                       bool saveAll, bool saveParametric, double scalingFactor,
                       bool append)
{
  FILE *fp = 0;
  if(append)
    fp = Fopen(name.c_str(), binary ? "ab" : "a");
  else
    fp = Fopen(name.c_str(), binary ? "wb" : "w");

  if(!fp) {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  // if there are no physicals we save all the elements
  if(noPhysicalGroups()) saveAll = true;

  // header
  fprintf(fp, "$MeshFormat\n");
  fprintf(fp, "%g %d %lu\n", version, (binary ? 1 : 0), sizeof(double));
  if(binary) {
    int one = 1;
    fwrite(&one, sizeof(int), 1, fp); // swapping byte
    fprintf(fp, "\n");
  }
  fprintf(fp, "$EndMeshFormat\n");

  // physicals
  if(numPhysicalNames() > 0) {
    fprintf(fp, "$PhysicalNames\n");
    fprintf(fp, "%d\n", numPhysicalNames());
    for(piter it = firstPhysicalName(); it != lastPhysicalName(); ++it) {
      std::string name = it->second;
      if(name.size() > 128) name.resize(128);
      fprintf(fp, "%d %d \"%s\"\n", it->first.first, it->first.second,
              name.c_str());
    }
    fprintf(fp, "$EndPhysicalNames\n");
  }

  // entities
  fprintf(fp, "$Entities\n");
  writeMSH4Entities(this, fp, false, binary, scalingFactor);
  fprintf(fp, "$EndEntities\n");

  // partitioned entities
  if(getNumPartitions() > 0) {
    fprintf(fp, "$PartitionedEntities\n");
    writeMSH4Entities(this, fp, true, binary, scalingFactor);
    fprintf(fp, "$EndPartitionedEntities\n");
  }

  // nodes
  fprintf(fp, "$Nodes\n");
  writeMSH4Nodes(this, fp, getNumPartitions() == 0 ? false : true, binary,
                 saveParametric ? 1 : 0, scalingFactor, saveAll);
  fprintf(fp, "$EndNodes\n");

  // elements
  fprintf(fp, "$Elements\n");
  writeMSH4Elements(this, fp, getNumPartitions() == 0 ? false : true, binary,
                    saveAll);
  fprintf(fp, "$EndElements\n");

  // periodic
  writeMSH4PeriodicNodes(this, fp, getNumPartitions() == 0 ? false : true,
                         binary);

  // ghostCells
  writeMSH4GhostCells(this, fp, binary);

  fclose(fp);

  return 1;
}

static void associateVertices(GModel *model)
{
  for(GModel::const_viter it = model->firstVertex(); it != model->lastVertex();
      ++it) {
    for(std::size_t j = 0; j < (*it)->getNumMeshElements(); j++) {
      for(std::size_t k = 0; k < (*it)->getMeshElement(j)->getNumVertices(); k++) {
        (*it)->getMeshElement(j)->getVertex(k)->setEntity(0);
      }
    }
    (*it)->mesh_vertices.clear();
  }
  for(GModel::const_eiter it = model->firstEdge(); it != model->lastEdge();
      ++it) {
    for(std::size_t j = 0; j < (*it)->getNumMeshElements(); j++) {
      for(std::size_t k = 0; k < (*it)->getMeshElement(j)->getNumVertices(); k++) {
        (*it)->getMeshElement(j)->getVertex(k)->setEntity(0);
      }
    }
    (*it)->mesh_vertices.clear();
  }
  for(GModel::const_fiter it = model->firstFace(); it != model->lastFace();
      ++it) {
    for(std::size_t j = 0; j < (*it)->getNumMeshElements(); j++) {
      for(std::size_t k = 0; k < (*it)->getMeshElement(j)->getNumVertices(); k++) {
        (*it)->getMeshElement(j)->getVertex(k)->setEntity(0);
      }
    }
    (*it)->mesh_vertices.clear();
  }
  for(GModel::const_riter it = model->firstRegion(); it != model->lastRegion();
      ++it) {
    for(std::size_t j = 0; j < (*it)->getNumMeshElements(); j++) {
      for(std::size_t k = 0; k < (*it)->getMeshElement(j)->getNumVertices(); k++) {
        (*it)->getMeshElement(j)->getVertex(k)->setEntity(0);
      }
    }
    (*it)->mesh_vertices.clear();
  }

  for(GModel::const_viter it = model->firstVertex(); it != model->lastVertex();
      ++it) {
    for(std::size_t j = 0; j < (*it)->getNumMeshElements(); j++) {
      for(std::size_t k = 0; k < (*it)->getMeshElement(j)->getNumVertices(); k++) {
        if((*it)->getMeshElement(j)->getVertex(k)->onWhat() == 0) {
          (*it)->getMeshElement(j)->getVertex(k)->setEntity(*it);
          (*it)->mesh_vertices.push_back(
            (*it)->getMeshElement(j)->getVertex(k));
        }
      }
    }
  }
  for(GModel::const_eiter it = model->firstEdge(); it != model->lastEdge();
      ++it) {
    for(std::size_t j = 0; j < (*it)->getNumMeshElements(); j++) {
      for(std::size_t k = 0; k < (*it)->getMeshElement(j)->getNumVertices(); k++) {
        if((*it)->getMeshElement(j)->getVertex(k)->onWhat() == 0) {
          (*it)->getMeshElement(j)->getVertex(k)->setEntity(*it);
          (*it)->mesh_vertices.push_back(
            (*it)->getMeshElement(j)->getVertex(k));
        }
      }
    }
  }
  for(GModel::const_fiter it = model->firstFace(); it != model->lastFace();
      ++it) {
    for(std::size_t j = 0; j < (*it)->getNumMeshElements(); j++) {
      for(std::size_t k = 0; k < (*it)->getMeshElement(j)->getNumVertices(); k++) {
        if((*it)->getMeshElement(j)->getVertex(k)->onWhat() == 0) {
          (*it)->getMeshElement(j)->getVertex(k)->setEntity(*it);
          (*it)->mesh_vertices.push_back(
            (*it)->getMeshElement(j)->getVertex(k));
        }
      }
    }
  }
  for(GModel::const_riter it = model->firstRegion(); it != model->lastRegion();
      ++it) {
    for(std::size_t j = 0; j < (*it)->getNumMeshElements(); j++) {
      for(std::size_t k = 0; k < (*it)->getMeshElement(j)->getNumVertices(); k++) {
        if((*it)->getMeshElement(j)->getVertex(k)->onWhat() == 0) {
          (*it)->getMeshElement(j)->getVertex(k)->setEntity(*it);
          (*it)->mesh_vertices.push_back(
            (*it)->getMeshElement(j)->getVertex(k));
        }
      }
    }
  }
}

int GModel::_writePartitionedMSH4(const std::string &baseName, double version,
                                  bool binary, bool saveAll,
                                  bool saveParametric, double scalingFactor)
{
  std::vector<GEntity *> ghostEntities;
  std::vector<GEntity *> entities;
  getEntities(entities);
  for(std::size_t i = 0; i < entities.size(); i++) {
    if(entities[i]->geomType() == GEntity::GhostCurve ||
       entities[i]->geomType() == GEntity::GhostSurface ||
       entities[i]->geomType() == GEntity::GhostVolume) {
      ghostEntities.push_back(entities[i]);
    }
  }

  // Create a temporary model
  GModel *tmp = new GModel();
  tmp->setPhysicalNames(getPhysicalNames());
  tmp->setNumPartitions(getNumPartitions());

  for(std::size_t i = 1; i <= getNumPartitions(); i++) {
    std::set<GEntity *> entitiesSet;
    GEntity *ghostEntity = 0;

    for(std::size_t j = 0; j < entities.size(); j++) {
      GEntity *ge = entities[j];
      switch(ge->geomType()) {
      case GEntity::PartitionVolume: {
        partitionRegion *pr = static_cast<partitionRegion *>(ge);
        if(std::find(pr->getPartitions().begin(), pr->getPartitions().end(),
                     i) != pr->getPartitions().end()) {
          tmp->add(pr);
          if(ghostEntities.size()) entitiesSet.insert(pr);
        }
      } break;
      case GEntity::PartitionSurface: {
        partitionFace *pf = static_cast<partitionFace *>(ge);
        if(std::find(pf->getPartitions().begin(), pf->getPartitions().end(),
                     i) != pf->getPartitions().end()) {
          tmp->add(pf);
          if(ghostEntities.size()) entitiesSet.insert(pf);
        }
      } break;
      case GEntity::PartitionCurve: {
        partitionEdge *pe = static_cast<partitionEdge *>(ge);
        if(std::find(pe->getPartitions().begin(), pe->getPartitions().end(),
                     i) != pe->getPartitions().end()) {
          tmp->add(pe);
          if(ghostEntities.size()) entitiesSet.insert(pe);
        }
      } break;
      case GEntity::PartitionPoint: {
        partitionVertex *pv = static_cast<partitionVertex *>(ge);
        if(std::find(pv->getPartitions().begin(), pv->getPartitions().end(),
                     i) != pv->getPartitions().end()) {
          tmp->add(pv);
          if(ghostEntities.size()) entitiesSet.insert(pv);
        }
      } break;
      case GEntity::GhostCurve:
        if(i == static_cast<ghostEdge *>(ge)->getPartition()) {
          static_cast<ghostEdge *>(ge)->saveMesh(true);
          tmp->add(static_cast<ghostEdge *>(ge));
          if(ghostEntities.size()) entitiesSet.insert(ge);
          ghostEntity = ge;
        }
        break;
      case GEntity::GhostSurface:
        if(i == static_cast<ghostFace *>(ge)->getPartition()) {
          static_cast<ghostFace *>(ge)->saveMesh(true);
          tmp->add(static_cast<ghostFace *>(ge));
          if(ghostEntities.size()) entitiesSet.insert(ge);
          ghostEntity = ge;
        }
        break;
      case GEntity::GhostVolume:
        if(i == static_cast<ghostRegion *>(ge)->getPartition()) {
          static_cast<ghostRegion *>(ge)->saveMesh(true);
          tmp->add(static_cast<ghostRegion *>(ge));
          if(ghostEntities.size()) entitiesSet.insert(ge);
          ghostEntity = ge;
        }
        break;
      default:
        switch(ge->dim()){
        case 0: tmp->add(static_cast<GVertex *>(ge)); break;
        case 1: tmp->add(static_cast<GEdge *>(ge)); break;
        case 2: tmp->add(static_cast<GFace *>(ge)); break;
        case 3: tmp->add(static_cast<GRegion *>(ge)); break;
        }
        if(ghostEntities.size()) entitiesSet.insert(ge);
        break;
      }
    }

    associateVertices(tmp);

    if(ghostEntity) {
      for(std::size_t j = 0; j < ghostEntity->getNumMeshElements(); j++) {
        MElement *e = ghostEntity->getMeshElement(j);
        for(std::size_t k = 0; k < e->getNumVertices(); k++) {
          MVertex *v = e->getVertex(k);
          if(entitiesSet.find(v->onWhat()) == entitiesSet.end()) {
            v->setEntity(ghostEntity);
            ghostEntity->addMeshVertex(v);
          }
        }
      }
    }

    std::ostringstream sstream;
    sstream << baseName << "_" << i << ".msh";

    if(getNumPartitions() > 100) {
      if(i % 100 == 1) {
        Msg::Info("Writing partition %d/%d in file '%s'", i, getNumPartitions(),
                  sstream.str().c_str());
      }
    }
    else {
      Msg::Info("Writing partition %d in file '%s'", i, sstream.str().c_str());
    }

    tmp->_writeMSH4(sstream.str(), version, binary, saveAll, saveParametric,
                    scalingFactor, false);
    tmp->remove();
  }
  delete tmp;

  associateVertices(this);

  return 1;
}

static bool getPhyscialNameInfo(const std::string &name, int &parentPhysicalTag,
                                std::vector<int> &partitions)
{
  if(name[0] != '_') return false;

  const std::string part = "_part{";
  const std::string physical = "_physical{";

  size_t firstPart = name.find(part) + part.size();
  size_t lastPart = name.find_first_of('}', firstPart);
  const std::string partString = name.substr(firstPart, lastPart - firstPart);

  size_t firstPhysical = name.find(physical) + physical.size();
  size_t lastPhysical = name.find_first_of('}', firstPhysical);
  const std::string physicalString =
    name.substr(firstPhysical, lastPhysical - firstPhysical);

  std::string number;
  for(size_t i = 0; i < partString.size(); ++i) {
    if(partString[i] == ',') {
      partitions.push_back(atoi(number.c_str()));
      number.clear();
    }
    else {
      number += partString[i];
    }
  }
  partitions.push_back(atoi(number.c_str()));

  parentPhysicalTag = atoi(physicalString.c_str());

  return true;
}

int GModel::writePartitionedTopology(std::string &name)
{
  Msg::Info("Writing '%s'", name.c_str());

  std::vector<std::map<int, std::pair<int, std::vector<int> > > > allParts(4);
  std::vector<GEntity *> entities;
  getEntities(entities);
  for(size_t i = 0; i < entities.size(); i++) {
    std::vector<int> physicals = entities[i]->getPhysicalEntities();
    for(size_t j = 0; j < physicals.size(); ++j) {
      const std::string phyName =
        this->getPhysicalName(entities[i]->dim(), physicals[j]);
      int parentPhysicalTag;
      std::vector<int> partitions;
      if(getPhyscialNameInfo(phyName, parentPhysicalTag, partitions)) {
        allParts[entities[i]->dim()].insert(
          std::pair<int, std::pair<int, std::vector<int> > >(
            physicals[j],
            std::pair<int, std::vector<int> >(parentPhysicalTag, partitions)));
      }
    }
  }

  FILE *fp = Fopen(name.c_str(), "w");
  if(!fp) {
    Msg::Error("Could not open file '%s'", name.c_str());
    return 0;
  }

#if __cplusplus < 201103L
  char intToChar[20];
#endif
  fprintf(fp, "Group{\n");
  fprintf(fp, "  // Part~{dim}~{parentPhysicalTag}~{part1}~{part2}~...\n\n");
  std::vector<std::map<int, std::string> > tagToString(4);
  for(size_t i = 4; i > 0; --i) {
    fprintf(fp, "  // Dim %lu\n", i - 1);
    for(std::multimap<int, std::pair<int, std::vector<int> > >::iterator it =
          allParts[i - 1].begin();
        it != allParts[i - 1].end(); ++it) {
#if __cplusplus >= 201103L
      std::string partName = "Part~{" + std::to_string(i - 1) + "}~{" +
                             std::to_string(it->second.first) + "}";
#else
      std::string partName = "Part~{";
      sprintf(intToChar, "%lu", i - 1);
      partName += intToChar;
      partName += "}~{";
      sprintf(intToChar, "%d", it->second.first);
      partName += intToChar;
      partName += "}";
#endif
      fprintf(fp, "  Part~{%lu}~{%d}", i - 1, it->second.first);
      for(size_t j = 0; j < it->second.second.size(); ++j) {
#if __cplusplus >= 201103L
        partName += "~{" + std::to_string(it->second.second[j]) + "}";
#else
        partName += "~{";
        sprintf(intToChar, "%d", it->second.second[j]);
        partName += intToChar;
        partName += "}";
#endif
        fprintf(fp, "~{%d}", it->second.second[j]);
      }
      tagToString[i - 1].insert(
        std::pair<int, std::string>(it->first, partName));
      fprintf(fp, " = Region[{%d}];\n", it->first);
    }
    fprintf(fp, "\n");
  }

  fprintf(fp, "  // Global names\n\n");
  std::map<int, std::vector<int> > omegas;
  std::map<std::pair<int, int>, std::vector<int> > sigmasij;
  std::map<int, std::vector<int> > sigmas;
  std::map<int, std::set<int> > neighbors;
  std::size_t omegaDim = 0;
  for(size_t i = 4; i > 0; --i) {
    if(allParts[i - 1].size() != 0) {
      omegaDim = i - 1;
      break;
    }
  }

  // omega
  for(std::multimap<int, std::pair<int, std::vector<int> > >::iterator it =
        allParts[omegaDim].begin();
      it != allParts[omegaDim].end(); ++it) {
    if(it->second.second.size() == 1) {
      omegas[it->second.second[0]].push_back(it->first);
    }
  }
  fprintf(fp, "  // Omega\n");
  for(std::map<int, std::vector<int> >::iterator it = omegas.begin();
      it != omegas.end(); ++it) {
    fprintf(fp, "  Omega~{%d} = Region[{", it->first);
    for(size_t j = 0; j < it->second.size(); ++j) {
      if(j == 0)
        fprintf(fp, "%s", tagToString[omegaDim][it->second[j]].c_str());
      else
        fprintf(fp, ", %s", tagToString[omegaDim][it->second[j]].c_str());
    }
    fprintf(fp, "}];\n");
  }
  fprintf(fp, "\n");

  if(omegaDim > 0) {
    // sigma
    for(std::multimap<int, std::pair<int, std::vector<int> > >::iterator it =
          allParts[omegaDim - 1].begin();
        it != allParts[omegaDim - 1].end(); ++it) {
      if(it->second.second.size() == 2) {
        sigmasij[std::pair<int, int>(it->second.second[0],
                                     it->second.second[1])]
          .push_back(it->first);
        sigmasij[std::pair<int, int>(it->second.second[1],
                                     it->second.second[0])]
          .push_back(it->first);
        sigmas[it->second.second[0]].push_back(it->first);
        sigmas[it->second.second[1]].push_back(it->first);
      }
    }
    fprintf(fp, "  // Sigma\n");
    for(std::map<std::pair<int, int>, std::vector<int> >::iterator it =
          sigmasij.begin();
        it != sigmasij.end(); ++it) {
      fprintf(fp, "  Sigma~{%d}~{%d} = Region[{", it->first.first,
              it->first.second);
      for(size_t j = 0; j < it->second.size(); ++j) {
        if(j == 0)
          fprintf(fp, "%s", tagToString[omegaDim - 1][it->second[j]].c_str());
        else
          fprintf(fp, ", %s", tagToString[omegaDim - 1][it->second[j]].c_str());
      }
      fprintf(fp, "}];\n");
    }
    fprintf(fp, "\n");

    for(std::map<int, std::vector<int> >::iterator it = sigmas.begin();
        it != sigmas.end(); ++it) {
      fprintf(fp, "  Sigma~{%d} = Region[{", it->first);
      for(size_t j = 0; j < it->second.size(); ++j) {
        if(j == 0)
          fprintf(fp, "%s", tagToString[omegaDim - 1][it->second[j]].c_str());
        else
          fprintf(fp, ", %s", tagToString[omegaDim - 1][it->second[j]].c_str());
      }
      fprintf(fp, "}];\n");
    }
    fprintf(fp, "\n");
  }

  // D
  fprintf(fp, "  D() = {");
  for(size_t i = 1; i <= getNumPartitions(); ++i) {
    if(i != 1) fprintf(fp, ", ");
    fprintf(fp, "%lu", i);
  }
  fprintf(fp, "};\n");

  if(omegaDim > 0) {
    // D~{i}
    for(std::multimap<int, std::pair<int, std::vector<int> > >::iterator it =
          allParts[omegaDim - 1].begin();
        it != allParts[omegaDim - 1].end(); ++it) {
      if(it->second.second.size() == 2) {
        neighbors[it->second.second[0]].insert(it->second.second[1]);
        neighbors[it->second.second[1]].insert(it->second.second[0]);
      }
    }
    for(size_t i = 1; i <= getNumPartitions(); ++i) {
      fprintf(fp, "  D~{%lu}() = {", i);
      for(std::set<int>::iterator it = neighbors[i].begin();
          it != neighbors[i].end(); ++it) {
        if(it != neighbors[i].begin()) fprintf(fp, ", ");
        fprintf(fp, "%d", *it);
      }
      fprintf(fp, "};\n");
    }
  }

  fprintf(fp, "}\n\n");

  fclose(fp);

  Msg::Info("Done writing '%s'", name.c_str());

  return 1;
}
