// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Anthony Royer

#include <cstdio>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <string>
#include <cstdlib>
#include <limits>
#include <stdexcept>

#include "GmshDefines.h"
#include "OS.h"
#include "Context.h"
#include "GModel.h"
#include "GEntity.h"
#include "partitionRegion.h"
#include "partitionFace.h"
#include "partitionEdge.h"
#include "partitionVertex.h"
#include "discreteEdge.h"
#include "ghostFace.h"
#include "ghostEdge.h"
#include "ghostRegion.h"
#include "overlapRegion.h"
#include "overlapRegionManager.h"
#include "overlapFace.h"
#include "overlapFaceManager.h"
#include "overlapEdge.h"
#include "overlapEdgeManager.h"
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

struct EntitiesPack {
  std::set<GEntity *, GEntityPtrFullLessThan> ghost;
  std::set<GRegion *, GEntityPtrLessThan> regions;
  std::set<GFace *, GEntityPtrLessThan> faces;
  std::set<GEdge *, GEntityPtrLessThan> edges;
  std::set<GVertex *, GEntityPtrLessThan> vertices;
};

static bool readMSH4Physicals(GModel *const model, FILE *fp,
                              GEntity *const entity, bool binary,
                              bool swap)
{
  std::size_t numPhy = 0;
  if(binary) {
    if(fread(&numPhy, sizeof(std::size_t), 1, fp) != 1) { return false; }
    if(swap) SwapBytes((char *)&numPhy, sizeof(std::size_t), 1);

    std::vector<int> phyTags(numPhy);
    if(fread(&phyTags[0], sizeof(int), numPhy, fp) != numPhy) { return false; }
    if(swap) SwapBytes((char *)&phyTags[0], sizeof(int), numPhy);

    for(std::size_t i = 0; i < numPhy; i++) {
      entity->addPhysicalEntity(phyTags[i]);
    }
  }
  else {
    if(fscanf(fp, "%lu", &numPhy) != 1){ return false; }
    for(std::size_t i = 0; i < numPhy; i++) {
      int phyTag = 0;
      if(fscanf(fp, "%d", &phyTag) != 1) { return false; }
      entity->addPhysicalEntity(phyTag);
    }
  }
  return true;
}

static bool readMSH4BoundingEntities(GModel *const model, FILE *fp,
                                     GEntity *const entity, bool binary,
                                     bool swap)
{
  std::size_t numBrep = 0;
  std::vector<GEntity *> boundingEntities;
  std::vector<int> boundingSign;

  if(binary) {
    if(fread(&numBrep, sizeof(std::size_t), 1, fp) != 1) { return false; }
    if(swap) SwapBytes((char *)&numBrep, sizeof(std::size_t), 1);

    std::vector<int> brepTags(numBrep);
    if(fread(&brepTags[0], sizeof(int), numBrep, fp) != numBrep) {
      return false;
    }
    if(swap) SwapBytes((char *)&brepTags[0], sizeof(int), numBrep);

    for(std::size_t i = 0; i < numBrep; i++) {
      GEntity *brep =
        model->getEntityByTag(entity->dim() - 1, std::abs(brepTags[i]));
      if(!brep) {
        Msg::Warning("Entity %d not found in the Brep of entity %d",
                     brepTags[i], entity->tag());
      }
      else {
        boundingEntities.push_back(brep);
        boundingSign.push_back((std::abs(brepTags[i]) == brepTags[i] ? 1 : -1));
      }
    }
  }
  else {
    if(fscanf(fp, "%lu", &numBrep) != 1) { return false; }
    for(std::size_t i = 0; i < numBrep; i++) {
      int entityTag = 0;
      if(fscanf(fp, "%d", &entityTag) != 1) { return false; }
      GEntity *brep =
        model->getEntityByTag(entity->dim() - 1, std::abs(entityTag));
      if(!brep) {
        Msg::Warning("Entity %d not found in the Brep of entity %d", entityTag,
                     entity->tag());
      }
      else {
        boundingEntities.push_back(brep);
        boundingSign.push_back((std::abs(entityTag) == entityTag ? 1 : -1));
      }
    }
  }

  switch(entity->dim()) {
  case 1:
    if(boundingEntities.size() == 2) {
      reinterpret_cast<GEdge *>(entity)->setBeginVertex(
        reinterpret_cast<GVertex *>(boundingEntities[0]));
      reinterpret_cast<GEdge *>(entity)->setEndVertex(
        reinterpret_cast<GVertex *>(boundingEntities[1]));
    }
    else if(boundingEntities.size() == 1) {
      if(boundingSign[0] == 1) {
        reinterpret_cast<GEdge *>(entity)->setBeginVertex(
          reinterpret_cast<GVertex *>(boundingEntities[0]));
      }
      else {
        reinterpret_cast<GEdge *>(entity)->setEndVertex(
          reinterpret_cast<GVertex *>(boundingEntities[0]));
      }
    }
    break;
  case 2: {
    std::vector<int> tags(boundingEntities.size());
    for(std::size_t i = 0; i < boundingEntities.size(); i++)
      tags[i] = std::abs(boundingEntities[i]->tag());
    reinterpret_cast<GFace *>(entity)->setBoundEdges(tags, boundingSign);
  } break;
  case 3: {
    std::vector<int> tags(boundingEntities.size());
    for(std::size_t i = 0; i < boundingEntities.size(); i++)
      tags[i] = std::abs(boundingEntities[i]->tag());
    reinterpret_cast<GRegion *>(entity)->setBoundFaces(tags, boundingSign);
  } break;
  default: break;
  }
  return true;
}

static bool readMSH4EntityInfo(FILE *fp, bool binary,
                               bool swap, double version, bool partition,
                               int dim, int &tag, int &parentDim,
                               int &parentTag, std::vector<int> &partitions,
                               double &minX, double &minY, double &minZ,
                               double &maxX, double &maxY, double &maxZ)
{
  if(partition) {
    if(binary) {
      int dataInt[3];
      if(fread(dataInt, sizeof(int), 3, fp) != 3) { return false; }
      if(swap) SwapBytes((char *)dataInt, sizeof(int), 3);
      tag = dataInt[0];
      parentDim = dataInt[1];
      parentTag = dataInt[2];
      std::size_t numPart;
      if(fread(&numPart, sizeof(std::size_t), 1, fp) != 1) { return false; }
      partitions.resize(numPart, 0);
      if(fread(&partitions[0], sizeof(int), numPart, fp) != numPart) {
        return false;
      }
      if(swap) SwapBytes((char *)&partitions[0], sizeof(int), numPart);
      double dataDouble[6];
      const std::size_t nbb = (dim > 0) ? 6 : 3;
      if(fread(dataDouble, sizeof(double), nbb, fp) != nbb) { return false; }
      if(swap) SwapBytes((char *)dataDouble, sizeof(double), nbb);
      minX = dataDouble[0];
      minY = dataDouble[1];
      minZ = dataDouble[2];
      maxX = dataDouble[(nbb == 6) ? 3 : 0];
      maxY = dataDouble[(nbb == 6) ? 4 : 1];
      maxZ = dataDouble[(nbb == 6) ? 5 : 2];
    }
    else {
      std::size_t numPart = 0;
      if(fscanf(fp, "%d %d %d %lu", &tag, &parentDim, &parentTag, &numPart) !=
         4) {
        return false;
      }
      partitions.resize(numPart, 0);
      for(std::size_t i = 0; i < numPart; i++) {
        if(fscanf(fp, "%d", &partitions[i]) != 1) { return false; }
      }
      if(version < 4.1 || dim > 0) {
        if(fscanf(fp, "%lf %lf %lf %lf %lf %lf", &minX, &minY, &minZ, &maxX,
                  &maxY, &maxZ) != 6) {
          return false;
        }
      }
      else {
        if(fscanf(fp, "%lf %lf %lf", &minX, &minY, &minZ) != 3) {
          return false;
        }
        maxX = minX;
        maxY = minY;
        maxZ = minZ;
      }
    }
  }
  else {
    if(binary) {
      int dataInt;
      if(fread(&dataInt, sizeof(int), 1, fp) != 1) { return false; }
      if(swap) SwapBytes((char *)&dataInt, sizeof(int), 1);
      double dataDouble[6];
      const std::size_t nbb = (dim > 0) ? 6 : 3;
      if(fread(dataDouble, sizeof(double), nbb, fp) != nbb) { return false; }
      if(swap) SwapBytes((char *)dataDouble, sizeof(double), nbb);
      tag = dataInt;
      minX = dataDouble[0];
      minY = dataDouble[1];
      minZ = dataDouble[2];
      maxX = dataDouble[(nbb == 6) ? 3 : 0];
      maxY = dataDouble[(nbb == 6) ? 4 : 1];
      maxZ = dataDouble[(nbb == 6) ? 5 : 2];
    }
    else {
      if(version < 4.1 || dim > 0) {
        if(fscanf(fp, "%d %lf %lf %lf %lf %lf %lf", &tag, &minX, &minY, &minZ,
                  &maxX, &maxY, &maxZ) != 7) {
          return false;
        }
      }
      else {
        if(fscanf(fp, "%d %lf %lf %lf", &tag, &minX, &minY, &minZ) != 4) {
          return false;
        }
        maxX = minX;
        maxY = minY;
        maxZ = minZ;
      }
    }
  }
  return true;
}

static bool readMSH4Entities(GModel *const model, FILE *fp, bool partition,
                             bool binary, bool swap, double version)
{
  if(partition) {
    std::size_t numPartitions = 0;
    std::size_t ghostSize = 0;
    std::vector<int> ghostTags;

    if(binary) {
      if(fread(&numPartitions, sizeof(std::size_t), 1, fp) != 1) {
        return false;
      }
      if(swap) SwapBytes((char *)&numPartitions, sizeof(std::size_t), 1);

      if(fread(&ghostSize, sizeof(std::size_t), 1, fp) != 1) { return false; }
      if(swap) SwapBytes((char *)&ghostSize, sizeof(std::size_t), 1);
      if(ghostSize) {
        ghostTags.resize(2 * ghostSize);
        if(fread(&ghostTags[0], sizeof(int), 2 * ghostSize, fp) !=
           2 * ghostSize) {
          return false;
        }
        if(swap) SwapBytes((char *)&ghostTags[0], sizeof(int), 2 * ghostSize);
      }
    }
    else {
      if(fscanf(fp, "%lu", &numPartitions) != 1) { return false; }
      if(fscanf(fp, "%lu", &ghostSize) != 1) { return false; }
      if(ghostSize) {
        ghostTags.resize(2 * ghostSize);
        for(std::size_t i = 0; i < 2 * ghostSize; i += 2) {
          if(fscanf(fp, "%d %d", &ghostTags[i], &ghostTags[i + 1]) != 2) {
            return false;
          }
        }
      }
    }

    model->setNumPartitions(numPartitions);
    Msg::Info("%lu partitions", model->getNumPartitions());
    for(std::size_t i = 0; i < 2 * ghostSize; i += 2) {
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
  }

  std::size_t numEntities[4] = {0, 0, 0, 0};
  if(binary) {
    if(fread(numEntities, sizeof(std::size_t), 4, fp) != 4) { return false; }
    if(swap) SwapBytes((char *)numEntities, sizeof(std::size_t), 4);
  }
  else {
    if(fscanf(fp, "%lu %lu %lu %lu", &numEntities[0], &numEntities[1],
              &numEntities[2], &numEntities[3]) != 4) {
      return false;
    }
  }

  int nume = numEntities[0] + numEntities[1] + numEntities[2] + numEntities[3];
  if(partition)
    Msg::Info("%d partition entit%s", nume, nume > 1 ? "ies" : "y");
  else
    Msg::Info("%d entit%s", nume, nume > 1 ? "ies" : "y");

  for(int dim = 0; dim < 4; dim++) {
    for(std::size_t i = 0; i < numEntities[dim]; i++) {
      int tag = 0, parentDim = 0, parentTag = 0;
      std::vector<int> partitions;
      double minX = 0., minY = 0., minZ = 0., maxX = 0., maxY = 0., maxZ = 0.;
      if(!readMSH4EntityInfo(fp, binary, swap, version, partition,
                             dim, tag, parentDim, parentTag, partitions, minX,
                             minY, minZ, maxX, maxY, maxZ)) {
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
        if(!readMSH4Physicals(model, fp, gv, binary, swap)) {
          return false;
        }
      } break;
      case 1: {
        GEdge *ge = model->getEdgeByTag(tag);
        if(!ge) {
          if(partition) {
            ge = new partitionEdge(model, tag, nullptr, nullptr, partitions);
            if(parentTag)
              static_cast<partitionEdge *>(ge)->setParentEntity(
                model->getEntityByTag(parentDim, parentTag));
          }
          else {
            ge = new discreteEdge(model, tag, nullptr, nullptr);
          }
          model->add(ge);
        }
        if(!readMSH4Physicals(model, fp, ge, binary, swap)) {
          return false;
        }
        if(!readMSH4BoundingEntities(model, fp, ge, binary, swap)) {
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
        if(!readMSH4Physicals(model, fp, gf, binary, swap)) {
          return false;
        }
        if(!readMSH4BoundingEntities(model, fp, gf, binary, swap)) {
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
        if(!readMSH4Physicals(model, fp, gr, binary, swap)) {
          return false;
        }
        if(!readMSH4BoundingEntities(model, fp, gr, binary, swap)) {
          return false;
        }
      } break;
      }
    }
  }
  return true;
}

static GEntity *findChild(GModel *model, int dim, int parentTag, int partition)
{
  std::vector<GEntity *> entities;
  model->getEntities(entities, dim);
  for(GEntity *entity : entities) {
    auto parent = entity->getParentEntity();
    if(parent && parent->tag() == parentTag) {
      switch(dim) {
      case 1: {
        auto pe = dynamic_cast<partitionEdge *>(entity);
        if(pe->getPartitions().at(0) == partition) return entity;
        break;
      }
      case 2: {
        auto pf = dynamic_cast<partitionFace *>(entity);
        if(pf->getPartitions().at(0) == partition) return entity;
        break;
      }
      case 3: {
        auto pr = dynamic_cast<partitionRegion *>(entity);
        if(pr->getPartitions().at(0) == partition) return entity;
        break;
      }
      }
    }
  }
  return nullptr;
}

static bool readMSH4Overlaps(GModel *const model, FILE *fp, bool partition,
                             bool binary, bool swap, double version)
{
  size_t numPoints, numEdges, numFaces, numRegions;
  if (binary) {
    if(fread(&numPoints, sizeof(size_t), 1, fp) != 1) return false;
    if(fread(&numEdges, sizeof(size_t), 1, fp) != 1) return false;
    if(fread(&numFaces, sizeof(size_t), 1, fp) != 1) return false;
    if(fread(&numRegions, sizeof(size_t), 1, fp) != 1) return false;
  } else {
    if(fscanf(fp, "%lu %lu %lu %lu", &numPoints, &numEdges, &numFaces,
              &numRegions) != 4) {
      return false;
    }
  }
  Msg::Info("Reading overlaps: %lu points, %lu edges, %lu faces, %lu regions", numPoints,
            numEdges, numFaces, numRegions);
  for(size_t ipoint = 0; ipoint < numPoints; ++ipoint) {
    // Todo: implement 0D
  }
  // Read all edges.
  for(size_t iedge = 0; iedge < numEdges; ++iedge) {
    int tagParent, numOverlaps;
    if (binary) {
      if(fread(&tagParent, sizeof(int), 1, fp) != 1) return false;
      if(fread(&numOverlaps, sizeof(int), 1, fp) != 1) return false;
    } else {
      if(fscanf(fp, "%d %d", &tagParent, &numOverlaps) != 2) return false;
    }
    GEntity *ge = model->getEntityByTag(1, tagParent);
    GEdge *parentEdge = dynamic_cast<GEdge *>(ge);
    if(!parentEdge) {
      Msg::Error("Edge overlaps: Parent edge %d not found", tagParent);
      return false;
    }

    auto manager = std::make_unique<overlapEdgeManager>(model, tagParent);

    // For each (i,j) pair of the overlap of this entity, read its tag,
    // physical and elements
    for(size_t ioverlap = 0; ioverlap < numOverlaps; ++ioverlap) {
      int i, j, tagOverlap;
      size_t numElements;
      if(binary) {
        if(fread(&i, sizeof(int), 1, fp) != 1) return false;
        if(fread(&j, sizeof(int), 1, fp) != 1) return false;
        if(fread(&tagOverlap, sizeof(int), 1, fp) != 1) return false;
        if(fread(&numElements, sizeof(size_t), 1, fp) != 1) return false;
      }
      else {
        if(fscanf(fp, "%d %d %d %lu", &i, &j, &tagOverlap, &numElements) != 4) {
          Msg::Error("Edge overlaps: Could not read overlap %d", ioverlap);
          return false;
        }
      }

      // Should not happen
      GEntity *previousEntity = model->getEntityByTag(2, tagOverlap);
      if(previousEntity) {
        Msg::Warning("Edge overlap %d -> %d with tag %d already exsists as a "
                     "non-overlap entity. Deleting it",
                     i, j, tagOverlap);
        GEdge *f = dynamic_cast<GEdge *>(previousEntity);
        model->remove(f);
        delete previousEntity;
      }

      auto I = dynamic_cast<partitionEdge *>(findChild(model, 1, tagParent, i));
      auto J = dynamic_cast<partitionEdge *>(findChild(model, 1, tagParent, j));
      if(!I || !J) {
        Msg::Error(
          "Edge overlaps: could not find children %d and %d for overlap %d", i,
          j, tagOverlap);
        return false;
      }
      // Create the overlap entity and add it to the model
      overlapEdge *overlapEntity = new overlapEdge(model, tagOverlap, I, J);
      model->add(overlapEntity);
      manager->addOverlap(overlapEntity);
      overlapEntity->setManager(manager.get());
      if(!readMSH4Physicals(model, fp, overlapEntity, binary, swap)) {
        return false;
      }
      // Skipping BB for now
      /*if(!readMSH4BoundingEntities(model, fp, g, binary, swap)) {
        return false;
      }*/

      // Read elements
      for(size_t ielem = 0; ielem < numElements; ++ielem) {
        size_t tagElement;
        if (binary) {
          if(fread(&tagElement, sizeof(size_t), 1, fp) != 1) return false;
        } else {
          if(fscanf(fp, "%lu", &tagElement) != 1) return false;
        }
        auto elem = model->getMeshElementByTag(tagElement);
        if(!elem) {
          auto totalNumElem = model->getNumMeshElements();
          Msg::Error("Edge overlaps: Could not find element %d for overlap "
                     "%d. Total numEleme is %lu",
                     tagElement, tagOverlap, totalNumElem);
          return false;
        }
        overlapEntity->addElement(elem);
      }
    }

    // Add the manager to the model
    model->addOverlapEdgeManager(tagParent, std::move(manager));
  }
  for(size_t iface = 0; iface < numFaces; ++iface) {
    int tagParent, numOverlaps;
    if (binary) {
      if(fread(&tagParent, sizeof(int), 1, fp) != 1) return false;
      if(fread(&numOverlaps, sizeof(int), 1, fp) != 1) return false;
    } else {
      if(fscanf(fp, "%d %d", &tagParent, &numOverlaps) != 2) return false;
    }
    GEntity *ge = model->getEntityByTag(2, tagParent);
    GFace *parentFace = dynamic_cast<GFace *>(ge);
    if(!parentFace) {
      Msg::Error("Face overlaps: Parent face %d not found", tagParent);
      return false;
    }
    auto manager = std::make_unique<overlapFaceManager>(model, tagParent);
    // For each (i,j) pair of the overlap of this entity, read its tag,
    // physical and elements
    for(size_t ioverlap = 0; ioverlap < numOverlaps; ++ioverlap) {
      int of, on, tagOverlap;
      size_t numElements;
      if(binary) {
        if(fread(&of, sizeof(int), 1, fp) != 1) return false;
        if(fread(&on, sizeof(int), 1, fp) != 1) return false;
        if(fread(&tagOverlap, sizeof(int), 1, fp) != 1) return false;
        if(fread(&numElements, sizeof(size_t), 1, fp) != 1) return false;
      }
      else {
        if(fscanf(fp, "%d %d %d %lu", &of, &on, &tagOverlap, &numElements) != 4) {
          Msg::Error("Face overlaps: Could not read overlap %d", ioverlap);
          return false;
        }
      }
      GEntity* ofr = (model->getEntityByTag(2, of));
      GEntity* onr = (model->getEntityByTag(2, on));
      if (!ofr) {
        Msg::Error("Face overlaps: Could not find OF region %d", of);
        return false;
      }
      if (!onr) {
        Msg::Error("Face overlaps: Could not find ON region %d", on);
        return false;
      }

      partitionFace *I = dynamic_cast<partitionFace *>(ofr);
      partitionFace *J = dynamic_cast<partitionFace *>(onr);
      if(!I) {
        Msg::Error("Face overlaps: could not cast entity %d as "
                   "partitionFace for overlap %d. It is a %s",
                   of, tagOverlap, ofr->getTypeString().c_str());
        return false;
      }
      if(!J) {
        Msg::Error("Face overlaps: could not cast entity %d as "
                   "partitionFace for overlap %d. It is a %s",
                   on, tagOverlap, onr->getTypeString().c_str());
        return false;
      }

      // Should not happen
      GEntity *previousEntity = model->getEntityByTag(2, tagOverlap);
      if(previousEntity) {
        Msg::Warning("Face overlap %d -> %d with tag %d already exsists as a "
                     "non-overlap entity. Deleting it",
                     ofr->tag(), onr->tag(), tagOverlap);
        GFace *f = dynamic_cast<GFace *>(previousEntity);
        model->remove(f);
        delete previousEntity;
      }
      
      // Create the overlap entity and add it to the model
      overlapFace *overlapEntity = new overlapFace(model, tagOverlap, I, J);
      model->add(overlapEntity);
      manager->getOverlapsByPartition()[I->getPartitions()[0]].insert(overlapEntity);
      overlapEntity->setManager(manager.get());
      if(!readMSH4Physicals(model, fp, overlapEntity, binary, swap)) {
        return false;
      }
      // Skipping BB for now
      /*if(!readMSH4BoundingEntities(model, fp, g, binary, swap)) {
        return false;
      }*/

      // Read elements
      for(size_t ielem = 0; ielem < numElements; ++ielem) {
        size_t tagElement;
        if (binary) {
          if(fread(&tagElement, sizeof(size_t), 1, fp) != 1) return false;
        } else {
          if(fscanf(fp, "%lu", &tagElement) != 1) return false;
        }
        auto elem = model->getMeshElementByTag(tagElement);
        if(!elem) {
          auto totalNumElem = model->getNumMeshElements();
          Msg::Error("Region overlaps: Could not find element %d for overlap "
                     "%d. Total numEleme is %lu",
                     tagElement, tagOverlap, totalNumElem);
          return false;
        }
        overlapEntity->addElement(elem);
      }
    }

    // Add the manager to the model
    model->addOverlapFaceManager(tagParent, std::move(manager));
  }
  for(size_t iregion = 0; iregion < numRegions; ++iregion) {
    int tagParent, numOverlaps;
    if (binary) {
      if(fread(&tagParent, sizeof(int), 1, fp) != 1) return false;
      if(fread(&numOverlaps, sizeof(int), 1, fp) != 1) return false;
    } else {
      if(fscanf(fp, "%d %d", &tagParent, &numOverlaps) != 2) return false;
    }
    GEntity *ge = model->getEntityByTag(3, tagParent);
    GRegion *parentFace = dynamic_cast<GRegion *>(ge);
    if(!parentFace) {
      Msg::Error("Volume overlaps: Parent face %d not found", tagParent);
      return false;
    }
    auto manager = std::make_unique<overlapRegionManager>(model, tagParent);
    // For each (i,j) pair of the overlap of this entity, read its tag,
    // physical and elements
    for(size_t ioverlap = 0; ioverlap < numOverlaps; ++ioverlap) {
      int of, on, tagOverlap;
      size_t numElements;
      if(binary) {
        if(fread(&of, sizeof(int), 1, fp) != 1) return false;
        if(fread(&on, sizeof(int), 1, fp) != 1) return false;
        if(fread(&tagOverlap, sizeof(int), 1, fp) != 1) return false;
        if(fread(&numElements, sizeof(size_t), 1, fp) != 1) return false;
      }
      else {
        if(fscanf(fp, "%d %d %d %lu", &of, &on, &tagOverlap, &numElements) != 4) {
          Msg::Error("Volume overlaps: Could not read overlap %d", ioverlap);
          return false;
        }
      }
      GEntity* ofr = (model->getEntityByTag(3, of));
      GEntity* onr = (model->getEntityByTag(3, on));
      if (!ofr) {
        Msg::Error("Volume overlaps: Could not find OF region %d", of);
        return false;
      }
      if (!onr) {
        Msg::Error("Volume overlaps: Could not find ON region %d", on);
        return false;
      }

      partitionRegion *I = dynamic_cast<partitionRegion *>(ofr);
      partitionRegion *J = dynamic_cast<partitionRegion *>(onr);
      if(!I) {
        Msg::Error("Volume overlaps: could not cast entity %d as "
                   "partitionRegion for overlap %d. It is a %s",
                   of, tagOverlap, ofr->getTypeString().c_str());
        return false;
      }
      if(!J) {
        Msg::Error("Volume overlaps: could not cast entity %d as "
                   "partitionRegion for overlap %d. It is a %s",
                   on, tagOverlap, onr->getTypeString().c_str());
        return false;
      }

      // Should not happen
      GEntity *previousEntity = model->getEntityByTag(3, tagOverlap);
      if(previousEntity) {
        Msg::Warning("Volume overlap %d -> %d with tag %d already exsists as a "
                     "non-overlap entity. Deleting it",
                     ofr->tag(), onr->tag(), tagOverlap);
        GRegion *f = dynamic_cast<GRegion *>(previousEntity);
        model->remove(f);
        delete previousEntity;
      }
      
      // Create the overlap entity and add it to the model
      overlapRegion *overlapEntity = new overlapRegion(model, tagOverlap, I, J);
      model->add(overlapEntity);
      manager->getOverlapsByPartition()[I->getPartitions()[0]].insert(overlapEntity);
      overlapEntity->setManager(manager.get());
      if(!readMSH4Physicals(model, fp, overlapEntity, binary, swap)) {
        return false;
      }
      // Skipping BB for now
      /*if(!readMSH4BoundingEntities(model, fp, g, binary, swap)) {
        return false;
      }*/

      // Read elements
      for(size_t ielem = 0; ielem < numElements; ++ielem) {
        size_t tagElement;
        if (binary) {
          if(fread(&tagElement, sizeof(size_t), 1, fp) != 1) return false;
        } else {
          if(fscanf(fp, "%lu", &tagElement) != 1) return false;
        }
        auto elem = model->getMeshElementByTag(tagElement);
        if(!elem) {
          auto totalNumElem = model->getNumMeshElements();
          Msg::Error("Region overlaps: Could not find element %d for overlap "
                     "%d. Total numEleme is %lu",
                     tagElement, tagOverlap, totalNumElem);
          return false;
        }
        overlapEntity->addElement(elem);
      }
    }

    // Add the manager to the model
    model->addOverlapRegionManager(tagParent, std::move(manager));
  }
  Msg::Info("Number of managers created: %lu edges %lu faces %lu regions", model->getOverlapEdgeManagers().size(),
            model->getOverlapFaceManagers().size(), model->getOverlapRegionManagers().size());
  for(size_t ireg = 0; ireg < numRegions; ++ireg) {
    // Todo: implement 3D
  }

  return true;
}

static bool readMSH4OverlapBoundaries(GModel *const model, FILE *fp,
                                      bool partition, bool binary, bool swap,
                                      double version)
{
  int numBlocks;
  if(binary) {
    if(fread(&numBlocks, sizeof(int), 1, fp) != 1) return false;
  }
  else {
    if(fscanf(fp, "%d", &numBlocks) != 1) return false;
  }
  Msg::Info("Reading %d overlap boundaries", numBlocks);
  // Now read numBlocks lines of 5 int, formatted as dim parent i j tag
  int buffer[4];
  for(int k = 0; k < numBlocks; ++k) {
    if(binary) {
      if(fread(buffer, sizeof(int), 4, fp) != 4) return false;
    }
    else {
      if(fscanf(fp, "%d %d %d %d", &buffer[0], &buffer[1], &buffer[2],
                &buffer[3]) != 4) {
        return false;
      }
    }
    if(buffer[0] == 1) {
      int parentEdgeTag = buffer[1];
      auto it = model->getOverlapEdgeManagers().find(parentEdgeTag);
      if(it == model->getOverlapEdgeManagers().end()) {
        Msg::Error(
          "Edge overlap boundary: Could not find manager for parent edge %d",
          parentEdgeTag);
        return false;
      }
      partitionVertex *entity =
        dynamic_cast<partitionVertex *>(model->getEntityByTag(0, buffer[3]));
      if(!entity) {
        Msg::Error("Edge overlap boundary: Could not find entity %d",
                   buffer[3]);
        return false;
      }
      it->second->setFullBoundary(buffer[2], entity);
    }
    else if(buffer[0] == 2) {
      int parentFaceTag = buffer[1];
      auto it = model->getOverlapFaceManagers().find(parentFaceTag);
      if(it == model->getOverlapFaceManagers().end()) {
        Msg::Error(
          "Face overlap boundary: Could not find manager for parent face %d",
          parentFaceTag);
        return false;
      }
      partitionEdge *entity =
        dynamic_cast<partitionEdge *>(model->getEntityByTag(1, buffer[3]));
      if(!entity) {
        Msg::Error("Face overlap boundary: Could not find entity %d",
                   buffer[3]);
        return false;
      }
      it->second->getBoundariesByPartition()[buffer[2]].insert(entity);
    }
    else if(buffer[0] == 3) {
      int parentVolumeTag = buffer[1];
      auto it = model->getOverlapRegionManagers().find(parentVolumeTag);
      if(it == model->getOverlapRegionManagers().end()) {
        Msg::Error(
          "Region overlap boundary: Could not find manager for parent volume %d",
          parentVolumeTag);
        return false;
      }
      partitionFace *entity =
        dynamic_cast<partitionFace *>(model->getEntityByTag(2, buffer[3]));
      if(!entity) {
        Msg::Error("Region overlap boundary: Could not find entity %d",
                   buffer[3]);
        return false;
      }
      it->second->getBoundariesByPartition()[buffer[2]].insert(entity);
    }
  }
  return true;
}

static std::pair<std::size_t, MVertex *> *
readMSH4Nodes(GModel *const model, FILE *fp, bool binary, bool &dense,
              std::size_t &totalNumNodes, std::size_t &maxNodeNum, bool swap,
              double version)
{
  std::size_t numBlock = 0, minTag = 0, maxTag = 0;
  totalNumNodes = 0;
  maxNodeNum = 0;

  if(binary) {
    std::size_t data[4];
    if(fread(data, sizeof(std::size_t), 4, fp) != 4) { return nullptr; }
    if(swap) SwapBytes((char *)data, sizeof(std::size_t), 4);
    numBlock = data[0];
    totalNumNodes = data[1];
    minTag = data[2];
    maxTag = data[3];
  }
  else {
    if(version >= 4.1) {
      if(fscanf(fp, "%lu %lu %lu %lu", &numBlock, &totalNumNodes, &minTag,
                &maxTag) != 4) {
        return nullptr;
      }
    }
    else {
      if(fscanf(fp, "%lu %lu", &numBlock, &totalNumNodes) != 2) {
        return nullptr;
      }
    }
  }

  std::size_t nodeRead = 0;
  std::size_t minNodeNum = std::numeric_limits<std::size_t>::max();

  std::pair<std::size_t, MVertex *> *vertexCache =
    new std::pair<std::size_t, MVertex *>[totalNumNodes];

  Msg::Info("%lu node%s", totalNumNodes, totalNumNodes > 1 ? "s" : "");
  Msg::StartProgressMeter(totalNumNodes);

  for(std::size_t i = 0; i < numBlock; i++) {
    int parametric = 0;
    int entityTag = 0, entityDim = 0;
    std::size_t numNodes = 0;

    if(binary) {
      int data[3];
      if(fread(data, sizeof(int), 3, fp) != 3) {
        delete[] vertexCache;
        return nullptr;
      }
      if(swap) SwapBytes((char *)data, sizeof(int), 3);
      entityDim = data[0];
      entityTag = data[1];
      parametric = data[2];

      if(fread(&numNodes, sizeof(std::size_t), 1, fp) != 1) {
        delete[] vertexCache;
        return nullptr;
      }
      if(swap) SwapBytes((char *)&numNodes, sizeof(std::size_t), 1);
    }
    else {
      if(version >= 4.1) {
        if(fscanf(fp, "%d %d %d %lu", &entityDim, &entityTag, &parametric,
                  &numNodes) != 4) {
          delete[] vertexCache;
          return nullptr;
        }
      }
      else {
        if(fscanf(fp, "%d %d %d %lu", &entityTag, &entityDim, &parametric,
                  &numNodes) != 4) {
          delete[] vertexCache;
          return nullptr;
        }
      }
    }

    GEntity *entity = model->getEntityByTag(entityDim, entityTag);
    if(!entity) {
      switch(entityDim) {
      case 0: {
        Msg::Info("Creating discrete point %d", entityTag);
        GVertex *gv = new discreteVertex(model, entityTag);
        GModel::current()->add(gv);
        entity = gv;
        break;
      }
      case 1: {
        Msg::Info("Creating discrete curve %d", entityTag);
        GEdge *ge = new discreteEdge(model, entityTag, nullptr, nullptr);
        GModel::current()->add(ge);
        entity = ge;
        break;
      }
      case 2: {
        Msg::Info("Creating discrete surface %d", entityTag);
        GFace *gf = new discreteFace(model, entityTag);
        GModel::current()->add(gf);
        entity = gf;
        break;
      }
      case 3: {
        Msg::Info("Creating discrete volume %d", entityTag);
        GRegion *gr = new discreteRegion(model, entityTag);
        GModel::current()->add(gr);
        entity = gr;
        break;
      }
      default: {
        Msg::Error("Invalid dimension %d to create discrete entity", entityDim);
        delete[] vertexCache;
        return nullptr;
      }
      }
    }

    std::size_t n = 3;
    if(parametric) n += entityDim;

    std::vector<std::size_t> tags(numNodes);
    if(binary) {
      if(fread(&tags[0], sizeof(std::size_t), numNodes, fp) != numNodes) {
        delete[] vertexCache;
        return nullptr;
      }
      if(swap) SwapBytes((char *)&tags[0], sizeof(std::size_t), numNodes);
      std::vector<double> coord(n * numNodes);
      if(fread(&coord[0], sizeof(double), n * numNodes, fp) != n * numNodes) {
        delete[] vertexCache;
        return nullptr;
      }
      if(swap) SwapBytes((char *)&coord[0], sizeof(double), n * numNodes);
      std::size_t k = 0;
      for(std::size_t j = 0; j < numNodes; j++) {
        MVertex *mv = nullptr;
        std::size_t tagNode = tags[j];
        if(n == 5) {
          mv = new MFaceVertex(coord[k], coord[k + 1], coord[k + 2], entity,
                               coord[k + 3], coord[k + 4], tagNode);
        }
        else if(n == 4) {
          mv = new MEdgeVertex(coord[k], coord[k + 1], coord[k + 2], entity,
                               coord[k + 3], tagNode);
        }
        else {
          mv =
            new MVertex(coord[k], coord[k + 1], coord[k + 2], entity, tagNode);
        }
        k += n;
        entity->addMeshVertex(mv);
        mv->setEntity(entity);
        minNodeNum = std::min(minNodeNum, tagNode);
        maxNodeNum = std::max(maxNodeNum, tagNode);
        vertexCache[nodeRead] = std::make_pair(tagNode, mv);
        nodeRead++;
        if(totalNumNodes > 100000)
          Msg::ProgressMeter(nodeRead, true, "Reading nodes");
      }
    }
    else {
      if(version >= 4.1) {
        for(std::size_t j = 0; j < numNodes; j++) {
          if(fscanf(fp, "%lu", &tags[j]) != 1) {
            delete[] vertexCache;
            return nullptr;
          }
        }
      }
      for(std::size_t j = 0; j < numNodes; j++) {
        std::size_t tagNode = 0;
        if(version >= 4.1) { tagNode = tags[j]; }
        else {
          if(fscanf(fp, "%lu", &tagNode) != 1) {
            delete[] vertexCache;
            return nullptr;
          }
        }
        MVertex *mv = nullptr;
        if(n == 5) {
          double x, y, z, u, v;
          if(fscanf(fp, "%lf %lf %lf %lf %lf", &x, &y, &z, &u, &v) != 5) {
            delete[] vertexCache;
            return nullptr;
          }
          mv = new MFaceVertex(x, y, z, entity, u, v, tagNode);
        }
        else if(n == 4) {
          double x, y, z, u;
          if(fscanf(fp, "%lf %lf %lf %lf", &x, &y, &z, &u) != 4) {
            delete[] vertexCache;
            return nullptr;
          }
          mv = new MEdgeVertex(x, y, z, entity, u, tagNode);
        }
        else {
          double x, y, z;
          if(fscanf(fp, "%lf %lf %lf", &x, &y, &z) != 3) {
            delete[] vertexCache;
            return nullptr;
          }
          // discard extra parametric coordinates, as Gmsh does not use them
          for(std::size_t k = 3; k < n; k++) {
            double dummy;
            if(fscanf(fp, "%lf", &dummy) != 1) {
              delete[] vertexCache;
              return nullptr;
            }
          }
          mv = new MVertex(x, y, z, entity, tagNode);
        }
        entity->addMeshVertex(mv);
        mv->setEntity(entity);
        minNodeNum = std::min(minNodeNum, tagNode);
        maxNodeNum = std::max(maxNodeNum, tagNode);
        vertexCache[nodeRead] = std::make_pair(tagNode, mv);
        nodeRead++;
        if(totalNumNodes > 100000)
          Msg::ProgressMeter(nodeRead, true, "Reading nodes");
      }
    }
  }

  if(version >= 4.1) { // consistency check
    if(minTag != minNodeNum || maxTag != maxNodeNum)
      Msg::Warning("Min/Max node tags reported in section header are wrong: "
                   "(%d/%d) != (%d/%d)",
                   minTag, maxTag, minNodeNum, maxNodeNum);
  }

  // if the vertex numbering is (fairly) dense, we fill the vector cache,
  // otherwise we fill the map cache
  if(minNodeNum == 1 && maxNodeNum == totalNumNodes) {
    Msg::Debug("Vertex numbering is dense");
    dense = true;
  }
  else if(maxNodeNum < 10 * totalNumNodes) {
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

static std::pair<std::size_t, std::pair<MElement *, int> > *
readMSH4Elements(GModel *const model, FILE *fp, bool binary, bool &dense,
                 std::size_t &totalNumElements, std::size_t &maxElementNum,
                 bool swap, double version)
{
  char str[10000]; // 1000 nodes for order 9 hex, 10 digits each
  std::size_t numBlock = 0, minTag = 0, maxTag = 0;
  totalNumElements = 0;
  maxElementNum = 0;

  if(binary) {
    std::size_t data[4];
    if(fread(data, sizeof(std::size_t), 4, fp) != 4) { return nullptr; }
    if(swap) SwapBytes((char *)data, sizeof(std::size_t), 4);
    numBlock = data[0];
    totalNumElements = data[1];
    minTag = data[2];
    maxTag = data[3];
  }
  else {
    if(version >= 4.1) {
      if(fscanf(fp, "%lu %lu %lu %lu", &numBlock, &totalNumElements, &minTag,
                &maxTag) != 4) {
        return nullptr;
      }
    }
    else {
      if(fscanf(fp, "%lu %lu", &numBlock, &totalNumElements) != 2) {
        return nullptr;
      }
    }
  }

  std::size_t elementRead = 0;
  std::size_t minElementNum = std::numeric_limits<std::size_t>::max();

  std::pair<std::size_t, std::pair<MElement *, int> > *elementCache =
    new std::pair<std::size_t, std::pair<MElement *, int> >[totalNumElements];
  Msg::Info("%lu element%s", totalNumElements, totalNumElements > 1 ? "s" : "");
  Msg::StartProgressMeter(totalNumElements);

  for(std::size_t i = 0; i < numBlock; i++) {
    int entityTag = 0, entityDim = 0, elmType = 0;
    std::size_t numElements = 0;

    if(binary) {
      int data[3];
      if(fread(data, sizeof(int), 3, fp) != 3) {
        delete[] elementCache;
        return nullptr;
      }
      if(swap) SwapBytes((char *)data, sizeof(int), 3);
      entityDim = data[0];
      entityTag = data[1];
      elmType = data[2];

      if(fread(&numElements, sizeof(std::size_t), 1, fp) != 1) {
        delete[] elementCache;
        return nullptr;
      }
      if(swap) SwapBytes((char *)&numElements, sizeof(std::size_t), 1);
    }
    else {
      if(version >= 4.1) {
        if(fscanf(fp, "%d %d %d %lu", &entityDim, &entityTag, &elmType,
                  &numElements) != 4) {
          delete[] elementCache;
          return nullptr;
        }
      }
      else {
        if(fscanf(fp, "%d %d %d %lu", &entityTag, &entityDim, &elmType,
                  &numElements) != 4) {
          delete[] elementCache;
          return nullptr;
        }
      }
    }

    GEntity *entity = model->getEntityByTag(entityDim, entityTag);
    if(!entity) {
      Msg::Error("Unknown entity %d of dimension %d", entityTag, entityDim);
      delete[] elementCache;
      return nullptr;
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

    const int numVertPerElm = MElement::getInfoMSH(elmType);
    if(binary) {
      std::size_t n = 1 + numVertPerElm;
      std::vector<std::size_t> data(numElements * n);
      if(fread(&data[0], sizeof(std::size_t), numElements * n, fp) !=
         numElements * n) {
        delete[] elementCache;
        return nullptr;
      }
      if(swap)
        SwapBytes((char *)&data[0], sizeof(std::size_t), numElements * n);

      std::vector<MVertex *> vertices(numVertPerElm, (MVertex *)nullptr);
      for(std::size_t j = 0; j < numElements * n; j += n) {
        for(int k = 0; k < numVertPerElm; k++) {
          vertices[k] = model->getMeshVertexByTag(data[j + k + 1]);
          if(!vertices[k]) {
            Msg::Error("Unknown node %lu in element %lu", data[j + k + 1],
                       data[j]);
            delete[] elementCache;
            return nullptr;
          }
        }

        MElementFactory elementFactory;
        MElement *element = elementFactory.create(
          elmType, vertices, data[j], 0, false, 0, nullptr, nullptr, nullptr);
        if(!element) {
          Msg::Error("Could not create element %lu of type %d", data[j],
                     elmType);
          delete[] elementCache;
          return nullptr;
        }
        if(entity->geomType() != GEntity::GhostCurve &&
           entity->geomType() != GEntity::GhostSurface &&
           entity->geomType() != GEntity::GhostVolume) {
          entity->addElement(element);
        }

        minElementNum = std::min(minElementNum, data[j]);
        maxElementNum = std::max(maxElementNum, data[j]);

        elementCache[elementRead] =
          std::make_pair(data[j], std::make_pair(element, entityTag));
        elementRead++;

        if(totalNumElements > 100000)
          Msg::ProgressMeter(elementRead, true, "Reading elements");
      }
    }
    else {
      for(std::size_t j = 0; j < numElements; j++) {
        std::size_t elmTag = 0;
        if(fscanf(fp, "%lu", &elmTag) != 1) {
          delete[] elementCache;
          return nullptr;
        }

        // We read all node tags with a single fread() to improve
        // performance. Beware that this assumes that all node tags are on a
        // single line, which is not required by the MSH4 specification - we
        // might need to revert to multiple fscanf() calls instead (see
        // e.g. #2724)
        if(!fgets(str, sizeof(str), fp)) {
          delete[] elementCache;
          return nullptr;
        }

        std::vector<MVertex *> vertices(numVertPerElm, (MVertex *)nullptr);

        for(int k = 0; k < numVertPerElm; k++) {
          std::size_t vertexTag = 0;
          if(k != numVertPerElm - 1) {
            if(sscanf(str, "%lu %[0-9- ]", &vertexTag, str) != 2) {
              delete[] elementCache;
              return nullptr;
            }
          }
          else {
            if(sscanf(str, "%lu", &vertexTag) != 1) {
              delete[] elementCache;
              return nullptr;
            }
          }

          vertices[k] = model->getMeshVertexByTag(vertexTag);
          if(!vertices[k]) {
            Msg::Error("Unknown node %lu in element %lu", vertexTag, elmTag);
            delete[] elementCache;
            return nullptr;
          }
        }

        MElementFactory elementFactory;
        MElement *element = elementFactory.create(
          elmType, vertices, elmTag, 0, false, 0, nullptr, nullptr, nullptr);
        if(!element) {
          Msg::Error("Could not create element %lu of type %d", elmTag,
                     elmType);
          delete[] elementCache;
          return nullptr;
        }
        if(entity->geomType() != GEntity::GhostCurve &&
           entity->geomType() != GEntity::GhostSurface &&
           entity->geomType() != GEntity::GhostVolume) {
          entity->addElement(element);
        }

        minElementNum = std::min(minElementNum, elmTag);
        maxElementNum = std::max(maxElementNum, elmTag);

        elementCache[elementRead] =
          std::make_pair(elmTag, std::make_pair(element, entityTag));
        elementRead++;

        if(totalNumElements > 100000)
          Msg::ProgressMeter(elementRead, true, "Reading elements");
      }
    }
  }
  // if the vertex numbering is dense, we fill the vector cache, otherwise we
  // fill the map cache
  if(minElementNum == 1 && maxElementNum == totalNumElements) {
    Msg::Debug("Element numbering is dense");
    dense = true;
  }
  else if(maxElementNum < 10 * totalNumElements) {
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

// Returns a vector of (edgeTag, nodeTag1, nodeTag2) arrays
static std::vector<std::array<std::size_t, 3>>
readMSH4Edges(GModel *const model, FILE *fp, bool binary, double version)
{
  std::size_t numTags = 0;
  // First line indicates the number of edges, then one line per edge
  if(binary) {
    if(fread(&numTags, sizeof(std::size_t), 1, fp) != 1) {
      Msg::Info("readMSH4Edges: Error reading number of edges (binary).");
      return {};
    }
  }
  else {
    if(fscanf(fp, "%lu", &numTags) != 1) {
      Msg::Info("readMSH4Edges: Error reading number of edges (text).");
      return {};
    }
  }

  if(numTags == 0) return {};

  Msg::Info("readMSH4Edges with %lu elements", numTags);

  std::vector<std::array<std::size_t, 3>> output;
  output.reserve(numTags);

  // edge, v1, v2
  size_t buffer[3];

  for(std::size_t i = 0; i < numTags; i++) {
    if(binary) {
      if(fread(&buffer, sizeof(std::size_t), 3, fp) != 3) {
        Msg::Info("Error reading edge %lu.", i);
        return {};
      }
    }
    else {
      if(fscanf(fp, "%lu %lu %lu", &buffer[0], &buffer[1], &buffer[2]) != 3) {
        return {};
      }
    }
    output.push_back({buffer[0], buffer[1], buffer[2]});
  }

  return output;
}

// Returns a vector of pairs<faceTag, vector<nodeTag>>
static std::vector<std::pair<std::size_t, std::vector<std::size_t>>>
readMSH4Faces(GModel *const model, FILE *fp, bool binary, double version)
{
  std::size_t numTags = 0;

  if(binary) {
    if(fread(&numTags, sizeof(std::size_t), 1, fp) != 1) {
      Msg::Info("readMSH4Faces: Error reading number of faces (binary).");
      return {};
    }
  }
  else {
    if(fscanf(fp, "%lu", &numTags) != 1) {
      Msg::Info("readMSH4Faces: Error reading number of faces (binary).");

    }
  }

  if (numTags == 0)
    return {};

  Msg::Info("readMSH4Faces with %lu elements", numTags);

  std::vector<std::pair<std::size_t, std::vector<std::size_t>>> output;
  output.reserve(numTags);

  // TAG NUM_VERT VERT1 VERT2 ... VERTN
  size_t buffer[2]; // faceTag, numVerts (3 or 4)
  for(std::size_t i = 0; i < numTags; i++) {
    if(binary) {
      if(fread(&buffer, sizeof(std::size_t), 2, fp) != 2) {
        Msg::Info("Error reading face %lu.", i);
        return {};
      }
    }
    else {
      if(fscanf(fp, "%lu %lu", &buffer[0], &buffer[1]) != 2) { return {}; }
    }
    std::vector<size_t> nodes(buffer[1]);
    if(binary) {
      for(std::size_t j = 0; j < buffer[1]; j++) {
        if(fread(&nodes[j], sizeof(std::size_t), 1, fp) != 1) {
          throw std::runtime_error("Error reading node tag in a face.");
        }
      }
    }
    else {
      for(std::size_t j = 0; j < buffer[1]; j++) {
        if(fscanf(fp, "%lu", &nodes[j]) != 1) {
          throw std::runtime_error("Error reading node tag in a face.");
        }
      }
    }
    output.push_back(std::make_pair(buffer[0], std::move(nodes)));
  }

  return output;
}

static bool readMSH4PeriodicNodes(GModel *const model, FILE *fp, bool binary,
                                  bool swap, double version)
{
  std::size_t numPeriodicLinks = 0;
  if(binary) {
    if(fread(&numPeriodicLinks, sizeof(std::size_t), 1, fp) != 1) {
      return false;
    }
    if(swap) SwapBytes((char *)&numPeriodicLinks, sizeof(std::size_t), 1);
  }
  else {
    if(fscanf(fp, "%lu", &numPeriodicLinks) != 1) { return false; }
  }

  for(std::size_t i = 0; i < numPeriodicLinks; i++) {
    int slaveDim = 0, slaveTag = 0, masterTag = 0;

    if(binary) {
      int data[3];
      if(fread(data, sizeof(int), 3, fp) != 3) { return false; }
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

    GEntity *slave = nullptr, *master = nullptr;
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
      slave = model->getFaceByTag(slaveTag);
      master = model->getFaceByTag(masterTag);
      break;
    }

    if(!slave) {
      Msg::Info("Could not find periodic entity %d of dimension %d", slaveTag,
                slaveDim);
      continue;
    }
    if(!master) {
      Msg::Info("Could not find periodic source entity %d of dimension %d",
                masterTag, slaveDim);
      continue;
    }

    std::size_t correspondingVertexSize = 0;
    if(binary) {
      std::size_t numAffine;
      if(fread(&numAffine, sizeof(std::size_t), 1, fp) != 1) { return false; }
      if(swap) SwapBytes((char *)&numAffine, sizeof(std::size_t), 1);
      if(numAffine) {
        std::vector<double> tfo(numAffine);
        if(fread(&tfo[0], sizeof(double), numAffine, fp) != numAffine) {
          return false;
        }
        if(swap) SwapBytes((char *)&tfo[0], sizeof(double), numAffine);
        slave->setMeshMaster(master, tfo);
      }
      else {
        slave->setMeshMaster(master);
      }
      if(fread(&correspondingVertexSize, sizeof(std::size_t), 1, fp) != 1) {
        return false;
      }
      if(swap)
        SwapBytes((char *)&correspondingVertexSize, sizeof(std::size_t), 1);
    }
    else {
      if(version >= 4.1) {
        std::size_t numAffine;
        if(fscanf(fp, "%lu", &numAffine) != 1) { return false; }
        if(numAffine) {
          std::vector<double> tfo(numAffine);
          for(std::size_t i = 0; i < numAffine; i++) {
            if(fscanf(fp, "%lf", &tfo[i]) != 1) { return false; }
          }
          slave->setMeshMaster(master, tfo);
        }
        else {
          slave->setMeshMaster(master);
        }
        if(fscanf(fp, "%lu", &correspondingVertexSize) != 1) { return false; }
      }
      else {
        char affine[256];
        if(fscanf(fp, "%s", affine) != 1) { return false; }
        if(!strncmp(affine, "Affine", 6)) {
          if(!fgets(affine, sizeof(affine), fp)) { return false; }
          std::vector<double> tfo(16);
          if(sscanf(affine,
                    "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf "
                    "%lf %lf %lf %lf",
                    &tfo[0], &tfo[1], &tfo[2], &tfo[3], &tfo[4], &tfo[5],
                    &tfo[6], &tfo[7], &tfo[8], &tfo[9], &tfo[10], &tfo[11],
                    &tfo[12], &tfo[13], &tfo[14], &tfo[15]) != 16) {
            return false;
          }
          slave->setMeshMaster(master, tfo);
          if(fscanf(fp, "%lu", &correspondingVertexSize) != 1) { return false; }
        }
        else {
          slave->setMeshMaster(master);
          if(sscanf(affine, "%lu", &correspondingVertexSize) != 1) {
            return false;
          }
        }
      }
    }

    for(std::size_t j = 0; j < correspondingVertexSize; j++) {
      std::size_t v1 = 0, v2 = 0;
      if(binary) {
        std::size_t data[2];
        if(fread(data, sizeof(std::size_t), 2, fp) != 2) { return false; }
        if(swap) SwapBytes((char *)data, sizeof(std::size_t), 2);
        v1 = data[0];
        v2 = data[1];
      }
      else {
        if(fscanf(fp, "%lu %lu", &v1, &v2) != 2) { return false; }
      }
      MVertex *mv1 = model->getMeshVertexByTag(v1);
      MVertex *mv2 = model->getMeshVertexByTag(v2);

      if(mv1 && mv2) { slave->correspondingVertices[mv1] = mv2; }
      else {
        if(!mv1) { Msg::Info("Could not find periodic node %d", v1); }
        else if(!mv2) {
          Msg::Info("Could not find periodic node %d", v2);
        }
      }
    }
  }
  return true;
}

static bool readMSH4GhostElements(GModel *const model, FILE *fp, bool binary,
                                  bool swap)
{
  std::size_t numGhostCells = 0;
  if(binary) {
    if(fread(&numGhostCells, sizeof(std::size_t), 1, fp) != 1) { return false; }
    if(swap) SwapBytes((char *)&numGhostCells, sizeof(std::size_t), 1);
  }
  else {
    if(fscanf(fp, "%lu", &numGhostCells) != 1) { return false; }
  }

  std::multimap<std::pair<MElement *, int>, int> ghostCells;
  for(std::size_t i = 0; i < numGhostCells; i++) {
    std::size_t elmTag = 0;
    int partNum = 0;
    std::size_t numGhostPartitions = 0;

    if(binary) {
      if(fread(&elmTag, sizeof(std::size_t), 1, fp) != 1) { return false; }
      if(swap) SwapBytes((char *)&elmTag, sizeof(std::size_t), 1);
      if(fread(&partNum, sizeof(int), 1, fp) != 1) { return false; }
      if(swap) SwapBytes((char *)&partNum, sizeof(int), 1);
      if(fread(&numGhostPartitions, sizeof(std::size_t), 1, fp) != 1) {
        return false;
      }
      if(swap) SwapBytes((char *)&numGhostPartitions, sizeof(std::size_t), 1);
    }
    else {
      if(fscanf(fp, "%lu %d %lu", &elmTag, &partNum, &numGhostPartitions) !=
         3) {
        return false;
      }
    }

    MElement *elm = model->getMeshElementByTag(elmTag);
    if(!elm) {
      Msg::Error("No element with tag %lu", elmTag);
      continue;
    }

    for(std::size_t j = 0; j < numGhostPartitions; j++) {
      int ghostPartition = 0;

      if(binary) {
        if(fread(&ghostPartition, sizeof(int), 1, fp) != 1) { return false; }
        if(swap) SwapBytes((char *)&ghostPartition, sizeof(int), 1);
      }
      else {
        if(fscanf(fp, "%d", &ghostPartition) != 1) { return false; }
      }

      ghostCells.insert(std::make_pair(std::make_pair(elm, partNum),
                                       ghostPartition));
    }
  }

  std::vector<GEntity *> ghostEntities(model->getNumPartitions() + 1, nullptr);
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

  for(auto it = ghostCells.begin(); it != ghostCells.end(); ++it) {
    if(it->second >= (int)ghostEntities.size()) {
      Msg::Error("Invalid partition %d in ghost elements", it->second);
      return false;
    }
    GEntity *ge = ghostEntities[it->second];
    if(!ge) {
      Msg::Warning("Missing ghost entity on partition %d", it->second);
    }
    else if(ge->geomType() == GEntity::GhostCurve) {
      static_cast<ghostEdge *>(ge)->addElement(it->first.first, it->first.second);
    }
    else if(ge->geomType() == GEntity::GhostSurface) {
      static_cast<ghostFace *>(ge)->addElement(it->first.first, it->first.second);
    }
    else if(ge->geomType() == GEntity::GhostVolume) {
      static_cast<ghostRegion *>(ge)->addElement(it->first.first, it->first.second);
    }
  }
  return true;
}

static bool readMSH4Parametrizations(GModel *const model, FILE *fp, bool binary)
{
  if(CTX::instance()->mesh.ignoreParametrizationMsh4) return true;

  std::size_t nParamE, nParamF;

  if(binary) {
    if(fread(&nParamE, sizeof(std::size_t), 1, fp) != 1) { return false; }
    if(fread(&nParamF, sizeof(std::size_t), 1, fp) != 1) { return false; }
  }
  else {
    if(fscanf(fp, "%lu %lu", &nParamE, &nParamF) != 2) { return false; }
  }

  // only report surface parametrizations
  Msg::Info("%lu parametrization%s", nParamF, nParamF > 1 ? "s" : "");
  Msg::StartProgressMeter(nParamF);

  for(std::size_t edge = 0; edge < nParamE; edge++) {
    int tag;
    if(binary) {
      if(fread(&tag, sizeof(int), 1, fp) != 1) { return false; }
    }
    else {
      if(fscanf(fp, "%d", &tag) != 1) { return false; }
    }
    GEdge *ge = model->getEdgeByTag(tag);
    if(ge) {
      discreteEdge *de = dynamic_cast<discreteEdge *>(ge);
      if(de) {
        if(!de->readParametrization(fp, binary)) return false;
      }
    }
  }

  for(std::size_t face = 0; face < nParamF; face++) {
    int tag;
    if(binary) {
      if(fread(&tag, sizeof(int), 1, fp) != 1) { return false; }
    }
    else {
      if(fscanf(fp, "%d", &tag) != 1) { return false; }
    }
    GFace *gf = model->getFaceByTag(tag);
    if(gf) {
      discreteFace *df = dynamic_cast<discreteFace *>(gf);
      if(df) {
        if(!df->readParametrization(fp, binary)) return false;
      }
    }
    Msg::ProgressMeter(face, true, "Processing parametrizations");
  }

  Msg::StopProgressMeter();

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

    if(feof(fp)) break;

    std::string sectionName(&str[1]);
    std::string endSectionName = "End" + sectionName;

    if(!strncmp(&str[1], "MeshFormat", 10)) {
      if(!fgets(str, sizeof(str), fp) || feof(fp)) {
        fclose(fp);
        return 0;
      }

      int format;
      std::size_t size;
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

      if(binary && size != sizeof(std::size_t)) {
        Msg::Error("Binary file has sizeof(size_t) = %d, not matching "
                   "machine sizeof(size_t) = %d",
                   size, sizeof(std::size_t));
        return false;
      }
      if(binary && version < 4.1) {
        Msg::Error("Can only read MSH 4.0 format in ASCII mode");
        return false;
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
      if(!readMSH4Entities(this, fp, false, binary, swap, version)) {
        Msg::Error("Could not read entities");
        fclose(fp);
        return 0;
      }
    }
    else if(!strncmp(&str[1], "PartitionedEntities", 19)) {
      if(!readMSH4Entities(this, fp, true, binary, swap, version)) {
        Msg::Error("Could not read partitioned entities");
        fclose(fp);
        return 0;
      }
      partitioned = true;
    }
    else if(!strncmp(&str[1], "OverlapEntities", 15)) {
      Msg::Info("Reading overlap entities");
      if(!readMSH4Overlaps(this, fp, true, binary, swap, version)) {
        Msg::Error("Could not read overlap entities");
        fclose(fp);
        return 0;
      }
    }
    else if(!strncmp(&str[1], "OverlapBoundaries", 17)) {
      Msg::Info("Reading overlap boundaries");
      if(!readMSH4OverlapBoundaries(this, fp, true, binary, swap, version)) {
        Msg::Error("Could not read overlap boundaries");
        fclose(fp);
        return 0;
      }
    }
    else if(!strncmp(&str[1], "Nodes", 5)) {
      _vertexVectorCache.clear();
      _vertexMapCache.clear();
      bool dense = false;
      std::size_t totalNumNodes = 0, maxNodeNum;
      std::pair<std::size_t, MVertex *> *vertexCache = readMSH4Nodes(
        this, fp, binary, dense, totalNumNodes, maxNodeNum, swap, version);
      Msg::StopProgressMeter();
      if(!vertexCache) {
        Msg::Error("Could not read nodes");
        fclose(fp);
        return false;
      }
      if(dense) {
        _vertexVectorCache.resize(maxNodeNum + 1, nullptr);
        for(std::size_t i = 0; i < totalNumNodes; i++) {
          if(!_vertexVectorCache[vertexCache[i].first]) {
            _vertexVectorCache[vertexCache[i].first] = vertexCache[i].second;
          }
          else {
            Msg::Info("Skipping duplicate node %d", vertexCache[i].first);
          }
        }
      }
      else {
        for(std::size_t i = 0; i < totalNumNodes; i++) {
          if(_vertexMapCache.count(vertexCache[i].first) == 0) {
            _vertexMapCache[vertexCache[i].first] = vertexCache[i].second;
          }
          else {
            Msg::Info("Skipping duplicate node %d", vertexCache[i].first);
          }
        }
      }
      delete[] vertexCache;
    }
    else if(!strncmp(&str[1], "Elements", 8)) {
      bool dense = false;
      std::size_t totalNumElements = 0, maxElementNum = 0;
      std::pair<std::size_t, std::pair<MElement *, int> > *elementCache =
        readMSH4Elements(this, fp, binary, dense, totalNumElements,
                         maxElementNum, swap, version);
      Msg::StopProgressMeter();
      if(!elementCache) {
        Msg::Error("Could not read elements");
        fclose(fp);
        return 0;
      }
      if(dense) {
        _elementVectorCache.resize(maxElementNum + 1, std::make_pair(nullptr, 0));
        for(std::size_t i = 0; i < totalNumElements; i++) {
          if(!_elementVectorCache[elementCache[i].first].first) {
            _elementVectorCache[elementCache[i].first] = elementCache[i].second;
          }
          else {
            Msg::Info("Skipping duplicate element %d", elementCache[i].first);
          }
        }
      }
      else {
        for(std::size_t i = 0; i < totalNumElements; i++) {
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
    else if(!strncmp(&str[1], "EdgeTags", 8)) {
      auto edgeTags = 
        readMSH4Edges(this, fp, binary, version);
      Msg::Info("Read %lu edge tags from file", edgeTags.size());
      for (auto& elem: edgeTags) {
        // EdgeTag, nodeTag1, nodeTag2 format
        MVertex* v1 = getMeshVertexByTag(elem[1]);
        MVertex* v2 = getMeshVertexByTag(elem[2]);
        if(v1 != nullptr && v2 != nullptr) {
          // Should be enough for not adding edges on other partitions ?
          MEdge edge(v1, v2);
          this->_mapEdgeNum.insert({std::move(edge), elem[0]});
        }
      }
      Msg::Info("Total number of edges is now %lu", this->_mapEdgeNum.size());
    }
    else if(!strncmp(&str[1], "FaceTags", 8)) {
      auto faceTags = 
        readMSH4Faces(this, fp, binary, version);
      Msg::Info("Read %lu face tags from file", faceTags.size());
      for (auto& elem: faceTags) {
        // Always 3 or 4 nodes
        MVertex* v1 = getMeshVertexByTag(elem.second.at(0));
        MVertex* v2 = getMeshVertexByTag(elem.second.at(1));
        MVertex* v3 = getMeshVertexByTag(elem.second.at(2));
        bool isQuad = elem.second.size() == 4;
        MVertex* v4 = nullptr;
        if (isQuad) {
          v4 = getMeshVertexByTag(elem.second.at(3));
        }
        if(v1 && v2 && v3 && (v4 || !isQuad)) {
          MFace face(v1, v2, v3, v4);
          this->_mapFaceNum.insert({std::move(face), elem.first});
        }
      }
      Msg::Info("Total number of faces is now %lu", this->_mapFaceNum.size());
    }
    else if(!strncmp(&str[1], "Periodic", 8)) {
      if(!readMSH4PeriodicNodes(this, fp, binary, swap, version)) {
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
    else if(!strncmp(&str[1], "Parametrizations", 16)) {
      if(!readMSH4Parametrizations(this, fp, binary)) {
        Msg::Error("Could not read parametrizations");
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
    else if(strlen(&str[1]) > 0){
      if(!CTX::instance()->mesh.ignoreUnknownSections) {
        sectionName.pop_back();
        Msg::Info("Storing section $%s as model attribute", sectionName.c_str());
        std::vector<std::string> section;
        while(1) {
          if(!fgets(str, sizeof(str), fp) || feof(fp) ||
             !strncmp(&str[1], endSectionName.c_str(), endSectionName.size())) {
            break;
          }
          std::string s(str);
          if(s.back() == '\n') s.pop_back();
          if(s.back() == '\r') s.pop_back();
          section.push_back(s);
        }
        _attributes[sectionName] = section;
      }
    }

    while(strncmp(&str[1], endSectionName.c_str(), endSectionName.size())) {
      if(!fgets(str, sizeof(str), fp) || feof(fp)) { break; }
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
          const int part = pv->getPartition(0);
          for(std::size_t j = 0; j < pv->getNumMeshElements(); j++) {
            pv->getMeshElement(j)->setPartition(part);
          }
        }
      }
      else if(entities[i]->geomType() == GEntity::PartitionCurve) {
        partitionEdge *pe = static_cast<partitionEdge *>(entities[i]);
        if(pe->numPartitions() == 1) {
          const int part = pe->getPartition(0);
          for(std::size_t j = 0; j < pe->getNumMeshElements(); j++) {
            pe->getMeshElement(j)->setPartition(part);
          }
        }
      }
      else if(entities[i]->geomType() == GEntity::PartitionSurface) {
        partitionFace *pf = static_cast<partitionFace *>(entities[i]);
        if(pf->numPartitions() == 1) {
          const int part = pf->getPartition(0);
          for(std::size_t j = 0; j < pf->getNumMeshElements(); j++) {
            pf->getMeshElement(j)->setPartition(part);
          }
        }
      }
      else if(entities[i]->geomType() == GEntity::PartitionVolume) {
        partitionRegion *pr = static_cast<partitionRegion *>(entities[i]);
        if(pr->numPartitions() == 1) {
          const int part = pr->getPartition(0);
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
    std::size_t phySize = phys.size();
    fwrite(&phySize, sizeof(std::size_t), 1, fp);
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
                                 double scalingFactor, bool binary, int dim,
                                 double version)
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
  if(binary) { fwrite(bb, sizeof(double), (dim > 0) ? 6 : 3, fp); }
  else {
    std::size_t n = (version < 4.1 || dim > 0) ? 6 : 3;
    for(std::size_t i = 0; i < n; i++) fprintf(fp, "%.16g ", bb[i]);
  }
}

static std::set<int> getPartitionsNeighbors(GModel* const model, int partitionToSave) {
  if(partitionToSave == -1) { return {}; }

  std::set<int> result;

  if(partitionToSave == 0) {
    // Return all partitions
    for(int i = 1; i <= model->getNumPartitions(); i++) { result.insert(i); }
    return result;
  }
  result.insert(partitionToSave);

  const auto& regionsOvlp = model->getOverlapRegionManagers();
  for (const auto& [_, managerPtr]: regionsOvlp) {
    const auto& manager = *managerPtr;
    try {
      auto ovlpSet = manager.getOverlapsByPartition().at(partitionToSave);
      for(overlapRegion *reg : ovlpSet) { result.insert(reg->on()); }
    }
    catch (const std::out_of_range& e) {
      Msg::Error("Partition %d not found in overlaps", partitionToSave);
    }
    
  }

  // GUESS: We need to store boundaries of overlaps of me?


  Msg::Info("Partitions neighbors for partition %d: %u", partitionToSave, result.size());
  return result;
}

bool vectorSetIntersection(const std::vector<int>& a, const std::set<int>& b) {
  for (int elem: a) {
    if (b.count(elem) > 0) {
      return true;
    }
  }
  return false;
}

static void writeMSH4Entities(GModel *const model, FILE *fp, bool partition,
                              bool binary, double scalingFactor, double version,
                              std::map<GEntity*, SBoundingBox3d> *entityBounds, int partitionToSave = -1, EntitiesPack* outEntities = nullptr)
{
  std::set<GEntity *, GEntityPtrFullLessThan> ghost;
  std::set<GRegion *, GEntityPtrLessThan> regions;
  std::set<GFace *, GEntityPtrLessThan> faces;
  std::set<GEdge *, GEntityPtrLessThan> edges;
  std::set<GVertex *, GEntityPtrLessThan> vertices;

  using std::find;
  auto partitionsToInclude = getPartitionsNeighbors(model, partitionToSave);
  auto ovlpBoundaries = model->getAllOverlapBoundaries();
  
  std::set<overlapFace*> ovlpFacesToSave;

  if(partition) {
    std::set<GVertex *, GEntityPtrLessThan> embeddedVerticesToSave;
    for(GRegion *reg : model->getRegions()) {
      for(auto vert : reg->embeddedVertices()) {
        embeddedVerticesToSave.insert(vert);
        //Msg::Info("Adding embedded vertex %d", vert->tag());
      }
    }

    for(auto it = model->firstVertex(); it != model->lastVertex(); ++it) {
      if(CTX::instance()->mesh.saveWithoutOrphans && (*it)->isOrphan())
        continue;
      if((*it)->geomType() == GEntity::PartitionPoint) { 
        partitionVertex* pv = static_cast<partitionVertex *>(*it);
        const auto& parts = pv->getPartitions();
        if (partitionToSave == -1 || false || vectorSetIntersection(parts, partitionsToInclude))
          vertices.insert(*it);
        }
    }
    for(auto it = model->firstEdge(); it != model->lastEdge(); ++it) {
      if(CTX::instance()->mesh.saveWithoutOrphans && (*it)->isOrphan())
        continue;
      if((*it)->geomType() == GEntity::PartitionCurve) {
        partitionEdge* pe = static_cast<partitionEdge *>(*it);
        const auto& parts = pe->getPartitions();
        if (partitionToSave == -1 || false || vectorSetIntersection(parts, partitionsToInclude))
          edges.insert(*it);
      }
      if((*it)->geomType() == GEntity::GhostCurve) ghost.insert(*it);
    }
    for(auto it = model->firstFace(); it != model->lastFace(); ++it) {
      if(CTX::instance()->mesh.saveWithoutOrphans && (*it)->isOrphan())
        continue;
      if((*it)->geomType() == GEntity::PartitionSurface) {
        partitionFace* pf = static_cast<partitionFace *>(*it);
        const auto& parts = pf->getPartitions();
        if (partitionToSave == -1 || false || vectorSetIntersection(parts, partitionsToInclude))
          faces.insert(*it);
        else if (ovlpBoundaries.count(*it) > 0) {
          // If the face is an overlap boundary, we need to save it
          faces.insert(*it);
        }
      }
      if((*it)->geomType() == GEntity::GhostSurface) ghost.insert(*it);

      if ((*it)->geomType() == GEntity::OverlapSurface) {
        overlapFace* of = dynamic_cast<overlapFace *>(*it);
        if (!of) Msg::Error("Inconsistent overlapFace cast");
        if (partitionToSave == -1 || partitionsToInclude.count(of->on()) > 0) {
          ovlpFacesToSave.insert(of);
        }
      }

    }
    for(auto it = model->firstRegion(); it != model->lastRegion(); ++it) {
      if((*it)->geomType() == GEntity::PartitionVolume) {
        partitionRegion* pr = static_cast<partitionRegion *>(*it);
        const auto& parts = pr->getPartitions();
        if (partitionToSave == -1 || vectorSetIntersection(parts, partitionsToInclude))
          regions.insert(*it);
      }
      if((*it)->geomType() == GEntity::GhostVolume) ghost.insert(*it);
    }

    // Also ensure embedded vertices are included.
    for(auto it = model->firstVertex(); it != model->lastVertex(); ++it) {
      partitionVertex *pv = dynamic_cast<partitionVertex *>(*it);
      if(!pv) continue;
      GVertex *parent = dynamic_cast<GVertex *>(pv->getParentEntity());
      if(!parent) continue;
      if(embeddedVerticesToSave.count(parent) > 0) { vertices.insert(*it); }
    }

    // Add entities used in overlaps
    for (overlapFace* of: ovlpFacesToSave) {
      size_t numElem = of->getNumMeshElements();
      for (size_t e = 0; e < numElem; ++e) {
        for (size_t i = 0; i < of->getMeshElement(e)->getNumVertices(); ++i) {
         GEntity* entity = of->getMeshElement(e)->getVertex(i)->onWhat();
          if (entity->geomType() == GEntity::PartitionPoint) {
            vertices.insert(static_cast<GVertex *>(entity));
          }
          else if (entity->geomType() == GEntity::PartitionCurve) {
            edges.insert(static_cast<GEdge *>(entity));
          }
          else if (entity->geomType() == GEntity::PartitionSurface) {
            faces.insert(static_cast<GFace *>(entity));
          }
          else if (entity->geomType() == GEntity::PartitionVolume) {
            regions.insert(static_cast<GRegion *>(entity));
          }
          else {
            Msg::Error("Unknown entity type %d", entity->geomType());
          }
        }
      }
    }

    // Add overlap boundaries
    //for (const auto& managers: model->getAllOverlapBoundaries())
    // Ensure boundary consistency
    for(GRegion *reg : regions) {
      for(auto face : reg->faces()) { faces.insert(face); }
      for(auto edge: reg->edges()) { edges.insert(edge); }
      for(auto vertex: reg->vertices()) {vertices.insert(vertex);}
    }
    for(GFace *face : faces) {
      for(auto line : face->edges()) { edges.insert(line); }
      for(auto vertex: face->vertices()) {vertices.insert(vertex);}
    }
    for(GEdge *edge : edges) {
      for(auto vertex : edge->vertices()) { vertices.insert(vertex); }
    }
  }
  else {
    for(auto it = model->firstVertex(); it != model->lastVertex(); ++it) {
      if(CTX::instance()->mesh.saveWithoutOrphans && (*it)->isOrphan())
        continue;
      if((*it)->geomType() != GEntity::PartitionPoint) vertices.insert(*it);
    }
    for(auto it = model->firstEdge(); it != model->lastEdge(); ++it) {
      if(CTX::instance()->mesh.saveWithoutOrphans && (*it)->isOrphan())
        continue;
      if((*it)->geomType() != GEntity::PartitionCurve &&
         (*it)->geomType() != GEntity::GhostCurve && 
         (*it)->geomType() != GEntity::OverlapCurve)
        edges.insert(*it);
    }
    for(auto it = model->firstFace(); it != model->lastFace(); ++it) {
      if(CTX::instance()->mesh.saveWithoutOrphans && (*it)->isOrphan())
        continue;
      if((*it)->geomType() != GEntity::PartitionSurface &&
         (*it)->geomType() != GEntity::GhostSurface &&
         (*it)->geomType() != GEntity::OverlapSurface)
        faces.insert(*it);
    }
    for(auto it = model->firstRegion(); it != model->lastRegion(); ++it) {
      if((*it)->geomType() != GEntity::PartitionVolume &&
         (*it)->geomType() != GEntity::GhostVolume &&
         (*it)->geomType() != GEntity::OverlapVolume)
        regions.insert(*it);
    }
  }

  Msg::Info("Writing %lu vertices, %lu edges, %lu faces, %lu regions",
            vertices.size(), edges.size(), faces.size(), regions.size());

  if(partition)
    fprintf(fp, "$PartitionedEntities\n");
  else
    fprintf(fp, "$Entities\n");

  if(binary) {
    if(partition) {
      std::size_t numPartitions = model->getNumPartitions();
      fwrite(&numPartitions, sizeof(std::size_t), 1, fp);

      // write the ghostentities' tag
      std::size_t ghostSize = ghost.size();
      std::vector<int> tags;
      if(ghostSize) {
        tags.resize(2 * ghostSize);
        int index = 0;
        for(auto it = ghost.begin(); it != ghost.end(); ++it) {
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
      fwrite(&ghostSize, sizeof(std::size_t), 1, fp);
      if(ghostSize) { fwrite(&tags[0], sizeof(int), 2 * ghostSize, fp); }
    }
    std::size_t verticesSize = vertices.size();
    std::size_t edgesSize = edges.size();
    std::size_t facesSize = faces.size();
    std::size_t regionsSize = regions.size();
    fwrite(&verticesSize, sizeof(std::size_t), 1, fp);
    fwrite(&edgesSize, sizeof(std::size_t), 1, fp);
    fwrite(&facesSize, sizeof(std::size_t), 1, fp);
    fwrite(&regionsSize, sizeof(std::size_t), 1, fp);

    for(auto it = vertices.begin(); it != vertices.end(); ++it) {
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
        std::vector<int> partitions(pv->getPartitions().begin(),
                                    pv->getPartitions().end()); // FIXME
        std::size_t numPart = partitions.size();
        fwrite(&numPart, sizeof(std::size_t), 1, fp);
        fwrite(&partitions[0], sizeof(int), partitions.size(), fp);
      }
      SBoundingBox3d bb = entityBounds ? (*entityBounds)[*it] : (*it)->bounds();
      writeMSH4BoundingBox(bb, fp, scalingFactor, binary, 0, version);
      writeMSH4Physicals(fp, *it, binary);
    }

    for(auto it = edges.begin(); it != edges.end(); ++it) {
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
      std::size_t verticesSize = vertices.size();
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
        std::vector<int> partitions(pe->getPartitions().begin(),
                                    pe->getPartitions().end()); // FIXME
        std::size_t numPart = partitions.size();
        fwrite(&numPart, sizeof(std::size_t), 1, fp);
        fwrite(&partitions[0], sizeof(int), partitions.size(), fp);
      }
      SBoundingBox3d bb = entityBounds ? (*entityBounds)[*it] : (*it)->bounds();
      writeMSH4BoundingBox(bb, fp, scalingFactor, binary, 1, version);
      writeMSH4Physicals(fp, *it, binary);
      fwrite(&verticesSize, sizeof(std::size_t), 1, fp);
      int oriI = 0;
      for(auto itv = vertices.begin(); itv != vertices.end(); itv++) {
        int brepTag = ori[oriI] * (*itv)->tag();
        fwrite(&brepTag, sizeof(int), 1, fp);
        oriI++;
      }
    }

    for(auto it = faces.begin(); it != faces.end(); ++it) {
      std::vector<GEdge *> const &edges = (*it)->edges();
      std::vector<int> const &ori = (*it)->edgeOrientations();
      std::size_t edgesSize = edges.size();
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
        std::vector<int> partitions(pf->getPartitions().begin(),
                                    pf->getPartitions().end()); // FIXME
        std::size_t numPart = partitions.size();
        fwrite(&numPart, sizeof(std::size_t), 1, fp);
        fwrite(&partitions[0], sizeof(int), partitions.size(), fp);
      }
      SBoundingBox3d bb = entityBounds ? (*entityBounds)[*it] : (*it)->bounds();
      writeMSH4BoundingBox(bb, fp, scalingFactor, binary, 2, version);
      writeMSH4Physicals(fp, *it, binary);
      fwrite(&edgesSize, sizeof(std::size_t), 1, fp);
      std::vector<int> tags, signs;
      for(auto ite = edges.begin(); ite != edges.end(); ite++)
        tags.push_back((*ite)->tag());

      signs.insert(signs.end(), ori.begin(), ori.end());

      if(tags.size() == signs.size()) {
        for(std::size_t i = 0; i < tags.size(); i++)
          tags[i] *= (signs[i] > 0 ? 1 : -1);
      }
      for(std::size_t i = 0; i < tags.size(); i++) {
        int brepTag = tags[i];
        fwrite(&brepTag, sizeof(int), 1, fp);
      }
    }

    for(auto it = regions.begin(); it != regions.end(); ++it) {
      std::vector<GFace *> faces = (*it)->faces();
      std::vector<int> const &ori = (*it)->faceOrientations();
      std::size_t facesSize = faces.size();
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
        std::vector<int> partitions(pr->getPartitions().begin(),
                                    pr->getPartitions().end()); // FIXME
        std::size_t numPart = partitions.size();
        fwrite(&numPart, sizeof(std::size_t), 1, fp);
        fwrite(&partitions[0], sizeof(int), partitions.size(), fp);
      }
      SBoundingBox3d bb = entityBounds ? (*entityBounds)[*it] : (*it)->bounds();
      writeMSH4BoundingBox(bb, fp, scalingFactor, binary, 3, version);
      writeMSH4Physicals(fp, *it, binary);
      fwrite(&facesSize, sizeof(std::size_t), 1, fp);
      std::vector<int> tags, signs;
      for(auto itf = faces.begin(); itf != faces.end(); itf++)
        tags.push_back((*itf)->tag());
      for(auto itf = ori.begin(); itf != ori.end(); itf++)
        signs.push_back(*itf);
      if(tags.size() == signs.size()) {
        for(std::size_t i = 0; i < tags.size(); i++)
          tags[i] *= (signs[i] > 0 ? 1 : -1);
      }
      for(std::size_t i = 0; i < tags.size(); i++) {
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
      std::size_t ghostSize = ghost.size();
      std::vector<int> tags;
      if(ghostSize) {
        tags.resize(2 * ghostSize);
        int index = 0;
        for(auto it = ghost.begin(); it != ghost.end(); ++it) {
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
      fprintf(fp, "%lu\n", ghostSize);
      if(ghostSize) {
        for(std::size_t i = 0; i < 2 * ghostSize; i += 2) {
          fprintf(fp, "%d %d\n", tags[i], tags[i + 1]);
        }
      }
    }
    fprintf(fp, "%lu %lu %lu %lu\n", vertices.size(), edges.size(),
            faces.size(), regions.size());

    for(auto it = vertices.begin(); it != vertices.end(); ++it) {
      fprintf(fp, "%d ", (*it)->tag());
      if(partition) {
        partitionVertex *pv = static_cast<partitionVertex *>(*it);
        int parentEntityDim = 0, parentEntityTag = 0;
        if(pv->getParentEntity()) {
          parentEntityDim = pv->getParentEntity()->dim();
          parentEntityTag = pv->getParentEntity()->tag();
        }
        fprintf(fp, "%d %d ", parentEntityDim, parentEntityTag);
        std::vector<int> partitions(pv->getPartitions().begin(),
                                    pv->getPartitions().end()); // FIXME
        fprintf(fp, "%lu ", partitions.size());
        for(std::size_t i = 0; i < partitions.size(); i++)
          fprintf(fp, "%d ", partitions[i]);
      }
      SBoundingBox3d bb = entityBounds ? (*entityBounds)[*it] : (*it)->bounds();
      writeMSH4BoundingBox(bb, fp, scalingFactor, binary, 0, version);
      writeMSH4Physicals(fp, *it, binary);
      fprintf(fp, "\n");
    }

    for(auto it = edges.begin(); it != edges.end(); ++it) {
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
        std::vector<int> partitions(pe->getPartitions().begin(),
                                    pe->getPartitions().end()); // FIXME
        fprintf(fp, "%lu ", partitions.size());
        for(std::size_t i = 0; i < partitions.size(); i++)
          fprintf(fp, "%d ", partitions[i]);
      }
      SBoundingBox3d bb = entityBounds ? (*entityBounds)[*it] : (*it)->bounds();
      writeMSH4BoundingBox(bb, fp, scalingFactor, binary, 1, version);
      writeMSH4Physicals(fp, *it, binary);
      fprintf(fp, "%lu ", vertices.size());
      int oriI = 0;
      for(auto itv = vertices.begin(); itv != vertices.end(); itv++) {
        fprintf(fp, "%d ", ori[oriI] * (*itv)->tag());
        oriI++;
      }
      fprintf(fp, "\n");
    }

    for(auto it = faces.begin(); it != faces.end(); ++it) {
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
        std::vector<int> partitions(pf->getPartitions().begin(),
                                    pf->getPartitions().end()); // FIXME
        fprintf(fp, "%lu ", partitions.size());
        for(std::size_t i = 0; i < partitions.size(); i++)
          fprintf(fp, "%d ", partitions[i]);
      }
      SBoundingBox3d bb = entityBounds ? (*entityBounds)[*it] : (*it)->bounds();
      writeMSH4BoundingBox(bb, fp, scalingFactor, binary, 2, version);
      writeMSH4Physicals(fp, *it, binary);
      fprintf(fp, "%lu ", edges.size());
      std::vector<int> tags, signs;
      for(auto ite = edges.begin(); ite != edges.end(); ite++)
        tags.push_back((*ite)->tag());
      for(auto ite = ori.begin(); ite != ori.end(); ite++)
        signs.push_back(*ite);
      if(tags.size() == signs.size()) {
        for(std::size_t i = 0; i < tags.size(); i++)
          tags[i] *= (signs[i] > 0 ? 1 : -1);
      }
      for(std::size_t i = 0; i < tags.size(); i++) fprintf(fp, "%d ", tags[i]);
      fprintf(fp, "\n");
    }

    for(auto it = regions.begin(); it != regions.end(); ++it) {
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

        fprintf(fp, "%lu ", pr->getPartitions().size());

        for(auto const partition : pr->getPartitions()) {
          fprintf(fp, "%d ", partition);
        }
      }
      SBoundingBox3d bb = entityBounds ? (*entityBounds)[*it] : (*it)->bounds();
      writeMSH4BoundingBox(bb, fp, scalingFactor, binary, 3, version);
      writeMSH4Physicals(fp, *it, binary);
      fprintf(fp, "%lu ", faces.size());

      std::vector<int> tags(faces.size());
      std::transform(begin(faces), end(faces), begin(tags),
                     [](const GFace *const face) { return face->tag(); });

      std::vector<int> signs(ori.begin(), ori.end());

      if(tags.size() == signs.size()) {
        for(std::size_t i = 0; i < tags.size(); i++)
          tags[i] *= (signs[i] > 0 ? 1 : -1);
      }

      for(auto const tag : tags) { fprintf(fp, "%d ", tag); }
      fprintf(fp, "\n");
    }
  }

  if(partition)
    fprintf(fp, "$EndPartitionedEntities\n");
  else
    fprintf(fp, "$EndEntities\n");

  if (outEntities) {
    outEntities->vertices = vertices;
    outEntities->edges = edges;
    outEntities->faces = faces;
    outEntities->regions = regions;
  }
}

static void writeMSH4Overlaps(GModel *const model, FILE *fp,
                              int partitionToSave, bool binary,
                              double scalingFactor, double version,
                              std::map<GEntity *, SBoundingBox3d> *entityBounds)
{
  size_t numPoints{0}, numLines{0}, numFaces{0}, numRegions{0};
  numLines = model->getOverlapEdgeManagers().size();
  numFaces = model->getOverlapFaceManagers().size();
  numRegions = model->getOverlapRegionManagers().size();

  
    fprintf(fp, "$OverlapEntities\n");
    if (binary) {
      fwrite(&numPoints, sizeof(size_t), 1, fp);
      fwrite(&numLines, sizeof(size_t), 1, fp);
      fwrite(&numFaces, sizeof(size_t), 1, fp);
      fwrite(&numRegions, sizeof(size_t), 1, fp);
    }
    else {
      fprintf(fp, "%lu %lu %lu %lu\n", numPoints, numLines, numFaces, numRegions);
    }
    // For each edgeManagers, write number of subdomains
    for(auto const &[parentTag, manager] : model->getOverlapEdgeManagers()) {
      int numEntities = 0;
      if(partitionToSave == 0) {
        for(const auto [i, submap] : manager->getOverlaps()) {
          numEntities += submap.size();
        }
      }
      else {
        auto ptr = manager->getOverlapsOf(partitionToSave);
        if(ptr) numEntities = ptr->size();
      }
      if (binary) {
        fwrite(&parentTag, sizeof(int), 1, fp);
        fwrite(&numEntities, sizeof(int), 1, fp);
      }
      else {
        fprintf(fp, "%d %d\n", parentTag, numEntities);
      }
      // For each overlap entity (a ij pair) write first "i j tag numElements"
      // Then the physicals, then the elements
      for(const auto [i, submap] : manager->getOverlaps()) {
        if(partitionToSave != 0 && partitionToSave != i) {
          continue; // Only save this part unless we save all
        }
        for(const auto [j, overlap] : submap) {
          size_t numElements = overlap->getNumMeshElements();
          int entityTag = overlap->tag();
          if (binary) {
            fwrite(&i, sizeof(int), 1, fp);
            fwrite(&j, sizeof(int), 1, fp);
            fwrite(&entityTag, sizeof(int), 1, fp);
            fwrite(&numElements, sizeof(size_t), 1, fp);
          }
          else {
            fprintf(fp, "%d %d %d %lu ", i, j, entityTag, numElements);
          }
          // Not exporting BB so far, they were buggy
          writeMSH4Physicals(fp, overlap, binary);
          if(binary) {
            for(size_t k = 0; k < numElements; k++) {
              size_t num = overlap->getMeshElement(k)->getNum();
              fwrite(&num, sizeof(size_t), 1, fp);
            }
          }
          else {
            fprintf(fp, "\n");
            for(size_t k = 0; k < numElements; k++) {
              fprintf(fp, "%lu ", overlap->getMeshElement(k)->getNum());
            }
            fprintf(fp, "\n");
          }
        }
      }
    }
    // For each faceManager, write number of subdomains
    for(auto const &[parentTag, manager] : model->getOverlapFaceManagers()) {
      int numEntities = 0;
      if(partitionToSave == 0) {
        for(const auto [i, subset] : manager->getOverlapsByPartition()) {
          numEntities += subset.size();
        }
      }
      else {
        auto ptr = manager->getOverlapsByPartition().find(partitionToSave);
        if(ptr != manager->getOverlapsByPartition().end()) numEntities = ptr->second.size();
      }
      if (binary) {
        fwrite(&parentTag, sizeof(int), 1, fp);
        fwrite(&numEntities, sizeof(int), 1, fp);
      }
      else {
        fprintf(fp, "%d %d\n", parentTag, numEntities);
      }
      // New format : "of on tagOfOverlapNumElements"
      for (const auto [i, setOfOverlaps]: manager->getOverlapsByPartition()) {
        if(partitionToSave != 0 && partitionToSave != i) {
          continue; // Only save this part unless we save all
        }
        for (const auto overlap: setOfOverlaps) {
          size_t numElements = overlap->getNumMeshElements();
          int entityTag = overlap->tag();
          int of = overlap->getOverlapOf()->tag();
          int on = overlap->getOverlapOn()->tag();
          if(binary) {
            fwrite(&of, sizeof(int), 1, fp);
            fwrite(&on, sizeof(int), 1, fp);
            fwrite(&entityTag, sizeof(int), 1, fp);
            fwrite(&numElements, sizeof(size_t), 1, fp);
          }
          else {
            fprintf(fp, "%d %d %d %lu ", of, on, entityTag, numElements);
          }
          // Not exporting BB so far, they were buggy
          writeMSH4Physicals(fp, overlap, binary);
          if (binary) {
            for (size_t k = 0; k < numElements; k++) {
              size_t num = overlap->getMeshElement(k)->getNum();
              fwrite(&num, sizeof(size_t), 1, fp);
            }
          }
          else {
            fprintf(fp, "\n");
            for (size_t k = 0; k < numElements; k++) {
              fprintf(fp, "%lu ", overlap->getMeshElement(k)->getNum());
            }
            fprintf(fp, "\n");
          }
        }
      }
      
    }
    // For each regionManager, write number of subdomains
    for(auto const &[parentTag, manager] : model->getOverlapRegionManagers()) {
      int numEntities = 0;
      if(partitionToSave == 0) {
        for(const auto [i, subset] : manager->getOverlapsByPartition()) {
          numEntities += subset.size();
        }
      }
      else {
        auto ptr = manager->getOverlapsByPartition().find(partitionToSave);
        if(ptr != manager->getOverlapsByPartition().end()) numEntities = ptr->second.size();
      }
      if (binary) {
        fwrite(&parentTag, sizeof(int), 1, fp);
        fwrite(&numEntities, sizeof(int), 1, fp);
      }
      else {
        fprintf(fp, "%d %d\n", parentTag, numEntities);
      }
      // New format : "of on tagOfOverlapNumElements"
      for (const auto [i, setOfOverlaps]: manager->getOverlapsByPartition()) {
        if(partitionToSave != 0 && partitionToSave != i) {
          continue; // Only save this part unless we save all
        }
        for (const auto overlap: setOfOverlaps) {
          size_t numElements = overlap->getNumMeshElements();
          int entityTag = overlap->tag();
          int of = overlap->getOverlapOf()->tag();
          int on = overlap->getOverlapOn()->tag();
          if(binary) {
            fwrite(&of, sizeof(int), 1, fp);
            fwrite(&on, sizeof(int), 1, fp);
            fwrite(&entityTag, sizeof(int), 1, fp);
            fwrite(&numElements, sizeof(size_t), 1, fp);
          }
          else {
            fprintf(fp, "%d %d %d %lu ", of, on, entityTag, numElements);
          }
          // Not exporting BB so far, they were buggy
          writeMSH4Physicals(fp, overlap, binary);
          if (binary) {
            for (size_t k = 0; k < numElements; k++) {
              size_t num = overlap->getMeshElement(k)->getNum();
              fwrite(&num, sizeof(size_t), 1, fp);
            }
          }
          else {
            fprintf(fp, "\n");
            for (size_t k = 0; k < numElements; k++) {
              fprintf(fp, "%lu ", overlap->getMeshElement(k)->getNum());
            }
            fprintf(fp, "\n");
          }
        }
      }
      
    }
    if(binary) fprintf(fp, "\n");
    fprintf(fp, "$EndOverlapEntities\n");
}

static void
writeMSH4OverlapBoundaries(GModel *const model, FILE *fp, int partitionToSave,
                           bool binary, double scalingFactor, double version,
                           std::map<GEntity *, SBoundingBox3d> *entityBounds)
{
  fprintf(fp, "$OverlapBoundaries\n");
  using EntryType = std::array<int, 4>;
  // Dimension entity i tag (of the bnd)
  std::vector<EntryType> entries;
  for (auto it = model->getOverlapEdgeManagers().begin(); it != model->getOverlapEdgeManagers().end(); ++it) {
    int parent = it->first;
    int dim = 1;
    const auto &map = it->second->getFullBoundaries();
    for(const auto &[i, entity] : map) {
      if(partitionToSave != 0 && partitionToSave != i) {
        //continue; // Only save this part unless we save all
      }
      entries.push_back({dim, parent, i, entity->tag()});
    }
  }
  for (auto it = model->getOverlapFaceManagers().begin(); it != model->getOverlapFaceManagers().end(); ++it) {
    int parent = it->first;
    int dim = 2;
    const auto &map = it->second->getBoundariesByPartition();
    for(const auto &[i, set] : map) {
      if(partitionToSave != 0 && partitionToSave != i) {
        // continue; // Only save this part unless we save all
      }
      for(const auto &entity : set) {
        entries.push_back({dim, parent, i, entity->tag()});
      }
    }
  }
  for (auto it = model->getOverlapRegionManagers().begin(); it != model->getOverlapRegionManagers().end(); ++it) {
    int parent = it->first;
    int dim = 3;
    const auto &map = it->second->getBoundariesByPartition();
    for(const auto &[i, set] : map) {
      if(partitionToSave != 0 && partitionToSave != i) {
        //continue; // Only save this part unless we save all
      }
      for(const auto &entity : set) {
        entries.push_back({dim, parent, i, entity->tag()});
      }
    }
  }
  int numEntries = static_cast<int>(entries.size());
  if(binary) { fwrite(&numEntries, sizeof(int), 1, fp); }
  else {
    fprintf(fp, "%d\n", numEntries);
  }

  for (const auto& entry: entries) {
    if (binary) {
      fwrite(&entry[0], sizeof(int), 1, fp);
      fwrite(&entry[1], sizeof(int), 1, fp);
      fwrite(&entry[2], sizeof(int), 1, fp);
      fwrite(&entry[3], sizeof(int), 1, fp);
    }
    else {
      fprintf(fp, "%d %d %d %d\n", entry[0], entry[1], entry[2], entry[3]);
    }
  }
  if (binary)
    fprintf(fp, "\n");
  fprintf(fp, "$EndOverlapBoundaries\n");
}

static void writeMSH4EntityNodes(GEntity *ge, FILE *fp, bool binary,
                                 int saveParametric, double scalingFactor,
                                 double version, std::vector<MVertex*> *optionalRestrictedVertices = nullptr)
{
  int parametric = saveParametric;
  if(ge->dim() != 1 && ge->dim() != 2)
    parametric = 0; // Gmsh only stores parametric coordinates for dim 1 and 2

  std::size_t numVerts = ge->getNumMeshVertices();
  if(optionalRestrictedVertices) {
    numVerts = optionalRestrictedVertices->size();
  }
  if(binary) {
    int entityDim = ge->dim();
    int entityTag = ge->tag();
    fwrite(&entityDim, sizeof(int), 1, fp);
    fwrite(&entityTag, sizeof(int), 1, fp);
    fwrite(&parametric, sizeof(int), 1, fp);
    fwrite(&numVerts, sizeof(std::size_t), 1, fp);
  }
  else {
    fprintf(fp, "%d %d %d %lu\n", (version >= 4.1) ? ge->dim() : ge->tag(),
            (version >= 4.1) ? ge->tag() : ge->dim(), parametric,
            numVerts);
  }

  if(!numVerts) {
    return;
  }

  std::vector<MVertex *> nodesToSave(numVerts);
  if(optionalRestrictedVertices) { nodesToSave = *optionalRestrictedVertices; }
  else {
    for(std::size_t i = 0; i < numVerts; i++) {
      nodesToSave[i] = ge->getMeshVertex(i);
    }
  }

  std::size_t n = 3;
  if(parametric) n += ge->dim();

  if(binary) {
    std::vector<size_t> tags(numVerts);
    for(std::size_t i = 0; i < numVerts; i++) tags[i] = nodesToSave[i]->getNum();

    fwrite(&tags[0], sizeof(std::size_t), numVerts, fp);
    std::vector<double> coord(n * numVerts);
    std::size_t j = 0;
    for(std::size_t i = 0; i < numVerts; i++) {
      MVertex *mv = nodesToSave.at(i);
      coord[j++] = mv->x() * scalingFactor;
      coord[j++] = mv->y() * scalingFactor;
      coord[j++] = mv->z() * scalingFactor;
      if(n >= 4) mv->getParameter(0, coord[j++]);
      if(n == 5) mv->getParameter(1, coord[j++]);
    }
    fwrite(&coord[0], sizeof(double), n * numVerts, fp);
  }
  else {
    if(version >= 4.1) {
      for(std::size_t i = 0; i < numVerts; i++)
        fprintf(fp, "%lu\n", nodesToSave[i]->getNum());
    }
    for(std::size_t i = 0; i < numVerts; i++) {
      MVertex *mv = nodesToSave[i];
      double x = mv->x() * scalingFactor;
      double y = mv->y() * scalingFactor;
      double z = mv->z() * scalingFactor;
      if(version < 4.1) fprintf(fp, "%lu ", mv->getNum());
      if(n == 5) {
        double u, v;
        mv->getParameter(0, u);
        mv->getParameter(1, v);
        fprintf(fp, "%.16g %.16g %.16g %.16g %.16g\n", x, y, z, u, v);
      }
      else if(n == 4) {
        double u;
        mv->getParameter(0, u);
        fprintf(fp, "%.16g %.16g %.16g %.16g\n", x, y, z, u);
      }
      else {
        fprintf(fp, "%.16g %.16g %.16g\n", x, y, z);
      }
    }
  }
}

static std::size_t
getAdditionalEntities(std::set<GRegion *, GEntityPtrLessThan> &regions,
                      std::set<GFace *, GEntityPtrLessThan> &faces,
                      std::set<GEdge *, GEntityPtrLessThan> &edges,
                      std::set<GVertex *, GEntityPtrLessThan> &vertices,
                      const std::set<GEntity *, GEntityPtrFullLessThan> &toIgnore)
{
  std::size_t numVertices = 0;

  for(auto it = vertices.begin(); it != vertices.end(); ++it) {
    if(toIgnore.count(*it)) continue;

    numVertices += (*it)->getNumMeshVertices();
  }

  for(auto it = edges.begin(); it != edges.end(); ++it) {
    if(toIgnore.count(*it)) continue;

    numVertices += (*it)->getNumMeshVertices();
    for(std::size_t i = 0; i < (*it)->getNumMeshElements(); i++) {
      for(std::size_t j = 0; j < (*it)->getMeshElement(i)->getNumVertices();
          j++) {
        GEntity *entity = (*it)->getMeshElement(i)->getVertex(j)->onWhat();
        if(entity && entity != (*it)) {
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

  for(auto it = faces.begin(); it != faces.end(); ++it) {
    if(toIgnore.count(*it)) continue;

    numVertices += (*it)->getNumMeshVertices();
    for(std::size_t i = 0; i < (*it)->getNumMeshElements(); i++) {
      for(std::size_t j = 0; j < (*it)->getMeshElement(i)->getNumVertices();
          j++) {
        GEntity *entity = (*it)->getMeshElement(i)->getVertex(j)->onWhat();
        if(entity && entity != (*it)) {
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

  for(auto it = regions.begin(); it != regions.end(); ++it) {
    if(toIgnore.count(*it)) continue;

    numVertices += (*it)->getNumMeshVertices();
    for(std::size_t i = 0; i < (*it)->getNumMeshElements(); i++) {
      for(std::size_t j = 0; j < (*it)->getMeshElement(i)->getNumVertices();
          j++) {
        GEntity *entity = (*it)->getMeshElement(i)->getVertex(j)->onWhat();
        if(entity && entity != (*it)) {
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

// Find all entities that are to be saved but with only some nodes, and give
// these nodes. Returns the number of extra nodes
static std::size_t getPartialEntitiesToSaveForOverlaps(
  GModel *const model, int partitionToSave,
  const std::set<GRegion *, GEntityPtrLessThan> &regions,
  const std::set<GFace *, GEntityPtrLessThan> &faces,
  const std::set<GEdge *, GEntityPtrLessThan> &edges,
  const std::set<GVertex *, GEntityPtrLessThan> &vertices,
  std::map<GRegion *, std::vector<MVertex *>, GEntityPtrLessThan>
    &additionalRegions,
  std::map<GFace *, std::vector<MVertex *>, GEntityPtrLessThan>
    &additionalFaces,
  std::map<GEdge *, std::vector<MVertex *>, GEntityPtrLessThan>
    &additionalEdges,
  std::map<GVertex *, std::vector<MVertex *>, GEntityPtrLessThan>
    &additionalVertices)
{
  size_t numVertices = 0;

  // Build set then cast as vectors later
  std::map<GRegion *, std::set<MVertex *>, GEntityPtrLessThan>
    additionalRegionsSet;
  std::map<GFace *, std::set<MVertex *>, GEntityPtrLessThan> additionalFacesSet;
  std::map<GEdge *, std::set<MVertex *>, GEntityPtrLessThan> additionalEdgesSet;
  std::map<GVertex *, std::set<MVertex *>, GEntityPtrLessThan>
    additionalVerticeSet;

  for(const auto &[parentEdgeTag, manager] : model->_overlapEdgeManagers) {
    for(const auto &[i, submap] : manager->getOverlaps()) {
      if(i != partitionToSave) { continue; }
      for(const auto &[j, overlap] : submap) {
        Msg::Info("Edge overlap of %lu elements",
                  overlap->getNumMeshElements());
        for(std::size_t k = 0; k < overlap->getNumMeshElements(); k++) {
          MElement *elem = overlap->getMeshElement(k);
          if(!elem) {
            Msg::Error("Element %lu not found", k);
            continue;
          }
          size_t numVertices = elem->getNumVertices();
          for(std::size_t l = 0; l < numVertices; l++) {
            MVertex *vertex = elem->getVertex(l);
            GEntity *entity = vertex->onWhat();
            if(!entity) {
              Msg::Error("Vertex %lu has no entity", vertex->getNum());
              continue;
            }
            if(entity && entity != overlap) {
              switch(entity->dim()) {
              case 0:
                if(vertices.find(dynamic_cast<GVertex *>(entity)) ==
                   vertices.end()) {
                  additionalVerticeSet[static_cast<GVertex *>(entity)].insert(
                    vertex);
                }
                break;
              case 1:
                if(edges.find(dynamic_cast<GEdge *>(entity)) == edges.end()) {
                  additionalEdgesSet[static_cast<GEdge *>(entity)].insert(
                    vertex);
                }
                break;
              case 2:
                if(faces.find(dynamic_cast<GFace *>(entity)) == faces.end()) {
                  additionalFacesSet[static_cast<GFace *>(entity)].insert(
                    vertex);
                }
                break;
              case 3:
                if(regions.find(dynamic_cast<GRegion *>(entity)) ==
                   regions.end()) {
                  additionalRegionsSet[static_cast<GRegion *>(entity)].insert(
                    vertex);
                }
                break;
              default: break;
              }
            }
          }
        }
      }
    }
  }

  for(const auto &[parentFaceTag, manager] : model->_overlapFaceManagers) {
    for(const auto &[i, submap] : manager->getOverlaps()) {
      if(i != partitionToSave) { continue; }
      for(const auto &[j, overlap] : submap) {
        Msg::Info("Face overlap of %lu elements",
                  overlap->getNumMeshElements());
        for(std::size_t k = 0; k < overlap->getNumMeshElements(); k++) {
          MElement *elem = overlap->getMeshElement(k);
          if(!elem) {
            Msg::Error("Element %lu not found", k);
            continue;
          }
          size_t numVertices = elem->getNumVertices();
          for(std::size_t l = 0; l < numVertices; l++) {
            MVertex *vertex = elem->getVertex(l);
            GEntity *entity = vertex->onWhat();
            if(!entity) {
              Msg::Error("Vertex %lu has no entity", vertex->getNum());
              continue;
            }
            if(entity && entity != overlap) {
              switch(entity->dim()) {
              case 0:
                if(vertices.find(dynamic_cast<GVertex *>(entity)) ==
                   vertices.end()) {
                  additionalVerticeSet[static_cast<GVertex *>(entity)].insert(
                    vertex);
                }
                break;
              case 1:
                if(edges.find(dynamic_cast<GEdge *>(entity)) == edges.end()) {
                  additionalEdgesSet[static_cast<GEdge *>(entity)].insert(
                    vertex);
                }
                break;
              case 2:
                if(faces.find(dynamic_cast<GFace *>(entity)) == faces.end()) {
                  additionalFacesSet[static_cast<GFace *>(entity)].insert(
                    vertex);
                }
                break;
              case 3:
                if(regions.find(dynamic_cast<GRegion *>(entity)) ==
                   regions.end()) {
                  additionalRegionsSet[static_cast<GRegion *>(entity)].insert(
                    vertex);
                }
                break;
              default: break;
              }
            }
          }
        }
      }
    }
    for(const auto &[i, subset] : manager->getOverlapsByPartition()) {
      if(i != partitionToSave) { continue; }
      for(overlapFace* overlap : subset) {
        Msg::Info("Face overlap of %lu elements",
                  overlap->getNumMeshElements());
        for(std::size_t k = 0; k < overlap->getNumMeshElements(); k++) {
          MElement *elem = overlap->getMeshElement(k);
          if(!elem) {
            Msg::Error("Element %lu not found", k);
            continue;
          }
          size_t numVertices = elem->getNumVertices();
          for(std::size_t l = 0; l < numVertices; l++) {
            MVertex *vertex = elem->getVertex(l);
            GEntity *entity = vertex->onWhat();
            if(!entity) {
              Msg::Error("Vertex %lu has no entity", vertex->getNum());
              continue;
            }
            if(entity && entity != overlap) {
              switch(entity->dim()) {
              case 0:
                if(vertices.find(dynamic_cast<GVertex *>(entity)) ==
                   vertices.end()) {
                  additionalVerticeSet[static_cast<GVertex *>(entity)].insert(
                    vertex);
                }
                break;
              case 1:
                if(edges.find(dynamic_cast<GEdge *>(entity)) == edges.end()) {
                  additionalEdgesSet[static_cast<GEdge *>(entity)].insert(
                    vertex);
                }
                break;
              case 2:
                if(faces.find(dynamic_cast<GFace *>(entity)) == faces.end()) {
                  additionalFacesSet[static_cast<GFace *>(entity)].insert(
                    vertex);
                }
                break;
              case 3:
                if(regions.find(dynamic_cast<GRegion *>(entity)) ==
                   regions.end()) {
                  additionalRegionsSet[static_cast<GRegion *>(entity)].insert(
                    vertex);
                }
                break;
              default: break;
              }
            }
          }
        }
      }
    }
  }

  for(const auto &[parentRegionTag, manager] : model->_overlapRegionManagers) {
    for(const auto &[i, submap] : manager->getOverlapsByPartition()) {
      if(i != partitionToSave) { continue; }
      for(overlapRegion* overlap : submap) {
        Msg::Info("Region overlap of %lu elements",
                  overlap->getNumMeshElements());
        for(std::size_t k = 0; k < overlap->getNumMeshElements(); k++) {
          MElement *elem = overlap->getMeshElement(k);
          if(!elem) {
            Msg::Error("Element %lu not found", k);
            continue;
          }
          size_t numVertices = elem->getNumVertices();
          for(std::size_t l = 0; l < numVertices; l++) {
            MVertex *vertex = elem->getVertex(l);
            GEntity *entity = vertex->onWhat();
            if(!entity) {
              Msg::Error("Vertex %lu has no entity", vertex->getNum());
              continue;
            }
            if(entity && entity != overlap) {
              switch(entity->dim()) {
              case 0:
                if(vertices.find(dynamic_cast<GVertex *>(entity)) ==
                   vertices.end()) {
                  additionalVerticeSet[static_cast<GVertex *>(entity)].insert(
                    vertex);
                }
                break;
              case 1:
                if(edges.find(dynamic_cast<GEdge *>(entity)) == edges.end()) {
                  additionalEdgesSet[static_cast<GEdge *>(entity)].insert(
                    vertex);
                }
                break;
              case 2:
                if(faces.find(dynamic_cast<GFace *>(entity)) == faces.end()) {
                  additionalFacesSet[static_cast<GFace *>(entity)].insert(
                    vertex);
                }
                break;
              case 3:
                if(regions.find(dynamic_cast<GRegion *>(entity)) ==
                   regions.end()) {
                  additionalRegionsSet[static_cast<GRegion *>(entity)].insert(
                    vertex);
                }
                break;
              default: break;
              }
            }
          }
        }
      }
    }
  }

  // Convert sets to vectors
  for(const auto &[entity, nodes] : additionalVerticeSet) {
    additionalVertices[entity] =
      std::vector<MVertex *>(nodes.begin(), nodes.end());
  }
  for(const auto &[entity, nodes] : additionalEdgesSet) {
    additionalEdges[entity] =
      std::vector<MVertex *>(nodes.begin(), nodes.end());
  }
  for(const auto &[entity, nodes] : additionalFacesSet) {
    additionalFaces[entity] =
      std::vector<MVertex *>(nodes.begin(), nodes.end());
  }
  for(const auto &[entity, nodes] : additionalRegionsSet) {
    additionalRegions[entity] =
      std::vector<MVertex *>(nodes.begin(), nodes.end());
  }

  // Compute number of vertices
  for(const auto &[entity, nodes] : additionalVertices) {
    numVertices += nodes.size();
  }
  for(const auto &[entity, nodes] : additionalEdges) {
    numVertices += nodes.size();
  }
  for(const auto &[entity, nodes] : additionalFaces) {
    numVertices += nodes.size();
  }
  for(const auto &[entity, nodes] : additionalRegions) {
    numVertices += nodes.size();
  }

  Msg::Info("Number of entities partially saved: %lu %lu %lu %lu",
            additionalVertices.size(), additionalEdges.size(),
            additionalFaces.size(), additionalRegions.size());

  return numVertices;
}

static void
getEntitiesToSave(GModel *const model, bool partitioned,
                  int partitionToSave, bool saveAll,
                  std::set<GRegion *, GEntityPtrLessThan> &regions,
                  std::set<GFace *, GEntityPtrLessThan> &faces,
                  std::set<GEdge *, GEntityPtrLessThan> &edges,
                  std::set<GVertex *, GEntityPtrLessThan> &vertices)
{
  if(partitioned) {
    for(auto it = model->firstVertex(); it != model->lastVertex(); ++it) {
      if(CTX::instance()->mesh.saveWithoutOrphans && (*it)->isOrphan())
        continue;
      if((*it)->geomType() == GEntity::PartitionPoint) {
        partitionVertex *pv = static_cast<partitionVertex *>(*it);
        if(!partitionToSave ||
           std::find(pv->getPartitions().begin(), pv->getPartitions().end(),
                     partitionToSave) != pv->getPartitions().end())
          vertices.insert(pv);
      }
    }
    for(auto it = model->firstEdge(); it != model->lastEdge(); ++it) {
      if(CTX::instance()->mesh.saveWithoutOrphans && (*it)->isOrphan())
        continue;
      if((*it)->geomType() == GEntity::PartitionCurve) {
        partitionEdge *pe = static_cast<partitionEdge *>(*it);
        if(!partitionToSave ||
           std::find(pe->getPartitions().begin(), pe->getPartitions().end(),
                     partitionToSave) != pe->getPartitions().end())
          edges.insert(pe);
      }
      else if((*it)->geomType() == GEntity::GhostCurve) {
        ghostEdge *ge = static_cast<ghostEdge *>(*it);
        if(ge->getPartition() == partitionToSave)
          edges.insert(ge);
      }
    }
    for(auto it = model->firstFace(); it != model->lastFace(); ++it) {
      if(CTX::instance()->mesh.saveWithoutOrphans && (*it)->isOrphan())
        continue;
      if((*it)->geomType() == GEntity::PartitionSurface) {
        partitionFace *pf = static_cast<partitionFace *>(*it);
        if(!partitionToSave ||
           std::find(pf->getPartitions().begin(), pf->getPartitions().end(),
                     partitionToSave) != pf->getPartitions().end())
          faces.insert(pf);
      }
      else if((*it)->geomType() == GEntity::GhostSurface) {
        ghostFace *gf = static_cast<ghostFace *>(*it);
        if(gf->getPartition() == partitionToSave)
          faces.insert(gf);
      }
    }
    for(auto it = model->firstRegion(); it != model->lastRegion(); ++it) {
      if((*it)->geomType() == GEntity::PartitionVolume) {
        partitionRegion *pr = static_cast<partitionRegion *>(*it);
        if(!partitionToSave ||
           std::find(pr->getPartitions().begin(), pr->getPartitions().end(),
                     partitionToSave) != pr->getPartitions().end())
          regions.insert(pr);
      }
      else if((*it)->geomType() == GEntity::GhostVolume) {
        ghostRegion *gr = static_cast<ghostRegion *>(*it);
        if(gr->getPartition() == partitionToSave)
          regions.insert(gr);
      }
    }
  }
  else {
    for(auto it = model->firstVertex(); it != model->lastVertex(); ++it) {
      if(CTX::instance()->mesh.saveWithoutOrphans && (*it)->isOrphan())
        continue;
      if((*it)->geomType() != GEntity::PartitionPoint &&
         (saveAll || (!saveAll && (*it)->getPhysicalEntities().size() != 0)))
        vertices.insert(*it);
    }
    for(auto it = model->firstEdge(); it != model->lastEdge(); ++it) {
      if(CTX::instance()->mesh.saveWithoutOrphans && (*it)->isOrphan())
        continue;
      if((*it)->geomType() != GEntity::PartitionCurve &&
         (saveAll || (!saveAll && (*it)->getPhysicalEntities().size() != 0) ||
          (*it)->geomType() == GEntity::GhostCurve))
        edges.insert(*it);
    }
    for(auto it = model->firstFace(); it != model->lastFace(); ++it) {
      if(CTX::instance()->mesh.saveWithoutOrphans && (*it)->isOrphan())
        continue;
      if((*it)->geomType() != GEntity::PartitionSurface &&
         (saveAll || (!saveAll && (*it)->getPhysicalEntities().size() != 0) ||
          (*it)->geomType() == GEntity::GhostSurface))
        faces.insert(*it);
    }
    for(auto it = model->firstRegion(); it != model->lastRegion(); ++it) {
      if((*it)->geomType() != GEntity::PartitionVolume &&
         (saveAll || (!saveAll && (*it)->getPhysicalEntities().size() != 0) ||
          (*it)->geomType() == GEntity::GhostVolume))
        regions.insert(*it);
    }
  }

   // HOTFIX: If we save an entity which as an overlap, save ALL the embedded entities in the overlapped entity
   // 12 feb 25: only if parent is embedded
  //for (auto it = model->firstVertex(); it != model->lastVertex(); ++it)
  //      vertices.insert(*it);

  unsigned nEmbeddedSaved = 0;
  std::set<GEntity *, GEntityPtrLessThan> embeddedVerticesToSave;
  for(GRegion *reg : model->getRegions()) {
    for(auto vert : reg->embeddedVertices()) {
      embeddedVerticesToSave.insert(vert);
    }
  }
  for(auto it = model->firstVertex(); it != model->lastVertex(); ++it) {
    partitionVertex *pv = dynamic_cast<partitionVertex *>(*it);
    if(!pv) continue;
    if(pv->getParentEntity() &&
       embeddedVerticesToSave.find(pv->getParentEntity()) !=
         embeddedVerticesToSave.end()) {
      vertices.insert(pv);
      nEmbeddedSaved++;
    }
  }
  Msg::Info("Saved %d embedded vertices", embeddedVerticesToSave.size());

  /*for(auto it = model->firstRegion(); it != model->lastRegion(); ++it) {
    GRegion* gr = static_cast<GRegion*>(*it);
    auto embVertices = gr->embeddedVertices();
    for (GVertex* vertex : embVertices) {
      vertices.insert(vertex);
      int numMatches = 0;
      Msg::Info("Adding embedded vertex %d...", vertex->tag());
      for (auto it2 = model->firstVertex(); it2 != model->lastVertex(); ++it2) {
        if ((*it2)->geomType() == GEntity::PartitionPoint && (*it2)->getParentEntity() == vertex) {
          vertices.insert(*it2);
         Msg::Info("Adding partitioned vertex %d. It has %d elements", (*it2)->tag(), (*it2)->points.size());
          ++numMatches;
        }
      }
      Msg::Info("Added %d partitioned vertices", numMatches);
    }
   }*/
}

static void writeMSH4Nodes(GModel *const model, FILE *fp, bool partitioned,
                           int partitionToSave, bool binary, int saveParametric,
                           double scalingFactor, bool saveAll, double version, EntitiesPack* entities = nullptr)
{
  std::set<GRegion *, GEntityPtrLessThan> regions;
  std::set<GFace *, GEntityPtrLessThan> faces;
  std::set<GEdge *, GEntityPtrLessThan> edges;
  std::set<GVertex *, GEntityPtrLessThan> vertices;
  getEntitiesToSave(model, partitioned, partitionToSave, saveAll, regions,
                    faces, edges, vertices);

  std::size_t numNodes = (saveAll && !partitioned &&
                          !CTX::instance()->mesh.saveWithoutOrphans) ?
    model->getNumMeshVertices() :
    getAdditionalEntities(regions, faces, edges, vertices, model->getAllOverlapBoundaries());

  // If overlapping, fill additional entities, with only a subset of nodes.
  std::map<GRegion *, std::vector<MVertex *>, GEntityPtrLessThan>
    additionalRegions;
  std::map<GFace *, std::vector<MVertex *>, GEntityPtrLessThan> additionalFaces;
  std::map<GEdge *, std::vector<MVertex *>, GEntityPtrLessThan> additionalEdges;
  std::map<GVertex *, std::vector<MVertex *>, GEntityPtrLessThan>
    additionalVertices;
  if(partitioned && partitionToSave != 0 && model->hasOverlaps()) {
    size_t numAdditionalNodes = getPartialEntitiesToSaveForOverlaps(
      model, partitionToSave, regions, faces, edges, vertices,
      additionalRegions, additionalFaces, additionalEdges, additionalVertices);
    Msg::Debug("Adding %lu additional nodes to the %lu original ones for "
              "overlaps on partition %d",
              numAdditionalNodes, numNodes, partitionToSave);
    numNodes += numAdditionalNodes;
  }

  if(!numNodes) return;

  /* Checks */
  if (entities) {
    for(GRegion *region : regions) {
      if (entities->regions.count(region) == 0) {
        Msg::Warning("Region %d not found in entities pack on partition %d", region->tag(), partitionToSave);
      }
    }
    for (GFace* face: faces) {
      if (entities->faces.count(face) == 0) {
        Msg::Warning("Face %d not found in entities pack on partition %d", face->tag(), partitionToSave);
      }
    }
    for (GEdge* edge: edges) {
      if (entities->edges.count(edge) == 0) {
        Msg::Warning("Edge %d not found in entities pack on partition %d", edge->tag(), partitionToSave);
      }
    }
    for (GVertex* vertex: vertices) {
      if (entities->vertices.count(vertex) == 0) {
        Msg::Warning("Vertex %d not found in entities pack on partition %d", vertex->tag(), partitionToSave);
        partitionVertex* pv = dynamic_cast<partitionVertex*>(vertex);
        if (!pv)
        Msg::Warning("It is not a partitioned vertex");
        else {
          Msg::Warning(
            "It is a partitioned vertex with parent %d of dimension %d",
            pv->getParentEntity()->tag(), pv->getParentEntity()->dim());
            for (auto part: pv->getPartitions()) {
              Msg::Warning("Partition %d", part);
            }
        }
      }
    }

    // Now for additional entities
    for (auto [entity, vertices] : additionalVertices) {
      if (entities->vertices.count(entity) == 0) {
        Msg::Warning("Additional vertex %d not found in entities pack on partition %d", entity->tag(), partitionToSave);
      }
    }
    for (auto [entity, vertices] : additionalEdges) {
      if (entities->edges.count(entity) == 0) {
        Msg::Warning("Additional edge %d not found in entities pack on partition %d", entity->tag(), partitionToSave);
      }
    }
    for (auto [entity, vertices] : additionalFaces) {
      if (entities->faces.count(entity) == 0) {
        Msg::Warning("Additional face %d not found in entities pack on partition %d", entity->tag(), partitionToSave);
      }
    }
    for (auto [entity, vertices] : additionalRegions) {
      if (entities->regions.count(entity) == 0) {
        Msg::Warning("Additional region %d not found in entities pack on partition %d", entity->tag(), partitionToSave);
      }
    }
  }
  
  Msg::Info("Writing %lu vertices, %lu edges, %lu faces, %lu regions",
            vertices.size(), edges.size(), faces.size(), regions.size());

  Msg::Info("Writing %lu additional vertices, %lu additional edges, %lu additional faces, %lu additional regions",
            additionalVertices.size(), additionalEdges.size(), additionalFaces.size(), additionalRegions.size());

  fprintf(fp, "$Nodes\n");

  std::size_t minTag = std::numeric_limits<std::size_t>::max(), maxTag = 0;
  for(auto it = vertices.begin(); it != vertices.end(); ++it) {
    for(std::size_t i = 0; i < (*it)->getNumMeshVertices(); i++) {
      minTag = std::min(minTag, (*it)->getMeshVertex(i)->getNum());
      maxTag = std::max(maxTag, (*it)->getMeshVertex(i)->getNum());
    }
  }
  for(auto it = edges.begin(); it != edges.end(); ++it) {
    for(std::size_t i = 0; i < (*it)->getNumMeshVertices(); i++) {
      minTag = std::min(minTag, (*it)->getMeshVertex(i)->getNum());
      maxTag = std::max(maxTag, (*it)->getMeshVertex(i)->getNum());
    }
  }
  for(auto it = faces.begin(); it != faces.end(); ++it) {
    for(std::size_t i = 0; i < (*it)->getNumMeshVertices(); i++) {
      minTag = std::min(minTag, (*it)->getMeshVertex(i)->getNum());
      maxTag = std::max(maxTag, (*it)->getMeshVertex(i)->getNum());
    }
  }
  for(auto it = regions.begin(); it != regions.end(); ++it) {
    for(std::size_t i = 0; i < (*it)->getNumMeshVertices(); i++) {
      minTag = std::min(minTag, (*it)->getMeshVertex(i)->getNum());
      maxTag = std::max(maxTag, (*it)->getMeshVertex(i)->getNum());
    }
  }

  // Include additional entities for min-max
  for (auto [entity, vertices] : additionalVertices) {
    for (auto vertex : vertices) {
      minTag = std::min(minTag, vertex->getNum());
      maxTag = std::max(maxTag, vertex->getNum());
    }
  }
  for (auto [entity, vertices] : additionalEdges) {
    for (auto vertex : vertices) {
      minTag = std::min(minTag, vertex->getNum());
      maxTag = std::max(maxTag, vertex->getNum());
    }
  }
  for (auto [entity, vertices] : additionalFaces) {
    for (auto vertex : vertices) {
      minTag = std::min(minTag, vertex->getNum());
      maxTag = std::max(maxTag, vertex->getNum());
    }
  }
  for (auto [entity, vertices] : additionalRegions) {
    for (auto vertex : vertices) {
      minTag = std::min(minTag, vertex->getNum());
      maxTag = std::max(maxTag, vertex->getNum());
    }
  }

  size_t totalNumEntities = vertices.size() + edges.size() + faces.size() +
                            regions.size() + additionalVertices.size() +
                            additionalEdges.size() + additionalFaces.size() +
                            additionalRegions.size();

  if(binary) {
    fwrite(&totalNumEntities, sizeof(std::size_t), 1, fp);
    fwrite(&numNodes, sizeof(std::size_t), 1, fp);
    fwrite(&minTag, sizeof(std::size_t), 1, fp);
    fwrite(&maxTag, sizeof(std::size_t), 1, fp);
  }
  else {
    if(version >= 4.1) {
      fprintf(fp, "%lu %lu %lu %lu\n",
              totalNumEntities,
              numNodes, minTag, maxTag);
    }
    else {
      fprintf(fp, "%lu %lu\n",
              totalNumEntities,
              numNodes);
    }
  }

  for(auto it = vertices.begin(); it != vertices.end(); ++it) {
    writeMSH4EntityNodes(*it, fp, binary, saveParametric, scalingFactor,
                         version);
  }
  for (auto it = additionalVertices.begin(); it != additionalVertices.end(); ++it) {
    writeMSH4EntityNodes(it->first, fp, binary, saveParametric, scalingFactor,
                         version, &it->second);
  }
  for(auto it = edges.begin(); it != edges.end(); ++it) {
    writeMSH4EntityNodes(*it, fp, binary, saveParametric, scalingFactor,
                         version);
  }
  for (auto it = additionalEdges.begin(); it != additionalEdges.end(); ++it) {
    writeMSH4EntityNodes(it->first, fp, binary, saveParametric, scalingFactor,
                         version, &it->second);
  }
  for(auto it = faces.begin(); it != faces.end(); ++it) {
    writeMSH4EntityNodes(*it, fp, binary, saveParametric, scalingFactor,
                         version);
  }
  for (auto it = additionalFaces.begin(); it != additionalFaces.end(); ++it) {
    writeMSH4EntityNodes(it->first, fp, binary, saveParametric, scalingFactor,
                         version, &it->second);
  }
  for(auto it = regions.begin(); it != regions.end(); ++it) {
    writeMSH4EntityNodes(*it, fp, binary, saveParametric, scalingFactor,
                         version);
  }
  for (auto it = additionalRegions.begin(); it != additionalRegions.end(); ++it) {
    writeMSH4EntityNodes(it->first, fp, binary, saveParametric, scalingFactor,
                         version, &it->second);
  }

  if(binary) fprintf(fp, "\n");

  fprintf(fp, "$EndNodes\n");
}

static void writeMSH4Elements(GModel *const model, FILE *fp, bool partitioned,
                              int partitionToSave, bool binary, bool saveAll,
                              double version)
{
  std::set<GRegion *, GEntityPtrLessThan> regions;
  std::set<GFace *, GEntityPtrLessThan> faces;
  std::set<GEdge *, GEntityPtrLessThan> edges;
  std::set<GVertex *, GEntityPtrLessThan> vertices;
  getEntitiesToSave(model, partitioned, partitionToSave, saveAll, regions,
                    faces, edges, vertices);

  /*
  If we write only one partition, we don't save the neighboring entities, but the overlap entities
  They know their elements, but we will export them with the entity tag of the
  partitioned entity they cover
  */
  if(partitionToSave != 0) {
    for(const auto &[parentEdgeTag, manager] :
        model->getOverlapEdgeManagers()) {
      const auto overlapsOnPartition = manager->getOverlapsOf(partitionToSave);
      if(!overlapsOnPartition) { continue; }
      for(const auto &[j, overlapFace] : *overlapsOnPartition) {
        edges.insert(overlapFace);
      }
    }
    for(const auto &[parentFaceTag, manager] :
        model->getOverlapFaceManagers()) {
      /*const auto &overlapsOnPartition = manager->getOverlapsOf(partitionToSave);
      if(!overlapsOnPartition) { continue; }
      for(const auto &[j, overlapFace] : *overlapsOnPartition) {
        faces.insert(overlapFace);
      }*/
      auto it = manager->getOverlapsByPartition().find(partitionToSave);
      if(it == manager->getOverlapsByPartition().end()) { continue; }
      for(overlapFace *ovlpr : it->second) faces.insert(ovlpr);
    }
    for(const auto &[parentRegionTag, manager] :
        model->getOverlapRegionManagers()) {

      auto it = manager->getOverlapsByPartition().find(partitionToSave);
      if(it == manager->getOverlapsByPartition().end()) { continue; }
      for(overlapRegion *ovlpr : it->second) regions.insert(ovlpr);

    }
  }

  std::map<std::pair<int, int>, std::vector<MElement *> > elementsByType[4];
  std::size_t numElements = 0;

  for(auto it = vertices.begin(); it != vertices.end(); ++it) {
    GVertex *vertex = *it;
    if(!saveAll && vertex->physicals.size() == 0) continue;

    int entityTag = vertex->tag();
    // If it is an overlap, put the tag of the parent entity
    if (vertex->geomType() == GEntity::OverlapPoint) {
      //overlapVertex *or = static_cast<overlapVertex *>(vertex);
      //entityTag = or->getOverlapOn()->tag();
    }

    numElements += vertex->points.size();
    for(std::size_t i = 0; i < vertex->points.size(); i++) {
      std::pair<int, int> p(vertex->tag(), vertex->points[i]->getTypeForMSH());
      elementsByType[0][p].push_back(vertex->points[i]);
    }
  }

  for(auto it = edges.begin(); it != edges.end(); ++it) {
    GEdge *edge = *it;
    if(!saveAll && edge->physicals.size() == 0 &&
       edge->geomType() != GEntity::GhostCurve)
      continue;

    int entityTag = edge->tag();
    // If it is an overlap, put the tag of the parent entity
    if(edge->geomType() == GEntity::OverlapCurve) {
      overlapEdge *oe = static_cast<overlapEdge *>(edge);
      entityTag = oe->getOverlapOn()->tag();
    }

    numElements += edge->lines.size();
    for(std::size_t i = 0; i < edge->lines.size(); i++) {
      std::pair<int, int> p(entityTag, edge->lines[i]->getTypeForMSH());
      elementsByType[1][p].push_back(edge->lines[i]);
    }
  }

  for(auto it = faces.begin(); it != faces.end(); ++it) {
    GFace *face = *it;
    if(!saveAll && face->physicals.size() == 0 &&
       face->geomType() != GEntity::GhostSurface)
      continue;

    int entityTag = face->tag();
    // If it is an overlap, put the tag of the parent entity
    if(face->geomType() == GEntity::OverlapSurface) {
      overlapFace *of = static_cast<overlapFace *>(face);
      entityTag = of->getOverlapOn()->tag();
    }

    numElements += face->triangles.size();
    for(std::size_t i = 0; i < face->triangles.size(); i++) {
      std::pair<int, int> p(entityTag, face->triangles[i]->getTypeForMSH());
      elementsByType[2][p].push_back(face->triangles[i]);
    }
    numElements += face->quadrangles.size();
    for(std::size_t i = 0; i < face->quadrangles.size(); i++) {
      std::pair<int, int> p(face->tag(), face->quadrangles[i]->getTypeForMSH());
      elementsByType[2][p].push_back(face->quadrangles[i]);
    }
  }

  for(auto it = regions.begin(); it != regions.end(); ++it) {
    GRegion* region = *it;
    if(!saveAll && region->physicals.size() == 0 &&
       region->geomType() != GEntity::GhostVolume)
      continue;

    int entityTag = region->tag();
    // If it is an overlap, put the tag of the parent entity
    if (region->geomType() == GEntity::OverlapVolume) {
      // TODO: implement
      overlapRegion *oregion = static_cast<overlapRegion *>(region);
      entityTag = oregion->getOverlapOn()->tag();
    }

    numElements += region->tetrahedra.size();
    for(std::size_t i = 0; i < region->tetrahedra.size(); i++) {
      std::pair<int, int> p(entityTag,
                            region->tetrahedra[i]->getTypeForMSH());
      elementsByType[3][p].push_back(region->tetrahedra[i]);
    }
    numElements += region->hexahedra.size();
    for(std::size_t i = 0; i < region->hexahedra.size(); i++) {
      std::pair<int, int> p(entityTag, region->hexahedra[i]->getTypeForMSH());
      elementsByType[3][p].push_back(region->hexahedra[i]);
    }
    numElements += region->prisms.size();
    for(std::size_t i = 0; i < region->prisms.size(); i++) {
      std::pair<int, int> p(entityTag, region->prisms[i]->getTypeForMSH());
      elementsByType[3][p].push_back(region->prisms[i]);
    }
    numElements += region->pyramids.size();
    for(std::size_t i = 0; i < region->pyramids.size(); i++) {
      std::pair<int, int> p(entityTag, region->pyramids[i]->getTypeForMSH());
      elementsByType[3][p].push_back(region->pyramids[i]);
    }
    numElements += region->trihedra.size();
    for(std::size_t i = 0; i < region->trihedra.size(); i++) {
      std::pair<int, int> p(entityTag, region->trihedra[i]->getTypeForMSH());
      elementsByType[3][p].push_back(region->trihedra[i]);
    }
  }

  if(!numElements) return;

  fprintf(fp, "$Elements\n");

  std::size_t numSection = 0;
  for(int dim = 0; dim <= 3; dim++) numSection += elementsByType[dim].size();

  std::size_t minTag = std::numeric_limits<std::size_t>::max(), maxTag = 0;
  for(int dim = 0; dim <= 3; dim++) {
    for(auto it = elementsByType[dim].begin(); it != elementsByType[dim].end();
        ++it) {
      for(std::size_t i = 0; i < it->second.size(); i++) {
        minTag = std::min(minTag, it->second[i]->getNum());
        maxTag = std::max(maxTag, it->second[i]->getNum());
      }
    }
  }

  if(binary) {
    fwrite(&numSection, sizeof(std::size_t), 1, fp);
    fwrite(&numElements, sizeof(std::size_t), 1, fp);
    fwrite(&minTag, sizeof(std::size_t), 1, fp);
    fwrite(&maxTag, sizeof(std::size_t), 1, fp);
  }
  else {
    if(version >= 4.1)
      fprintf(fp, "%lu %lu %lu %lu\n", numSection, numElements, minTag, maxTag);
    else
      fprintf(fp, "%lu %lu\n", numSection, numElements);
  }

  for(int dim = 0; dim <= 3; dim++) {
    for(auto it = elementsByType[dim].begin(); it != elementsByType[dim].end();
        ++it) {
      int entityTag = it->first.first;
      int elmType = it->first.second;
      std::size_t numElm = it->second.size();
      if(binary) {
        fwrite(&dim, sizeof(int), 1, fp);
        fwrite(&entityTag, sizeof(int), 1, fp);
        fwrite(&elmType, sizeof(int), 1, fp);
        fwrite(&numElm, sizeof(std::size_t), 1, fp);
      }
      else {
        fprintf(fp, "%d %d %d %lu\n", (version >= 4.1) ? dim : entityTag,
                (version >= 4.1) ? entityTag : dim, elmType, numElm);
      }

      std::size_t N = it->second.size();
      if(binary) {
        const int numVertPerElm = MElement::getInfoMSH(elmType);
        std::size_t n = 1 + numVertPerElm;
        std::vector<std::size_t> tags(N * n);
        std::size_t k = 0;
        for(std::size_t i = 0; i < N; i++) {
          MElement *e = it->second[i];
          tags[k] = e->getNum();
          for(int j = 0; j < numVertPerElm; j++) {
            tags[k + 1 + j] = e->getVertex(j)->getNum();
          }
          k += n;
        }
        fwrite(&tags[0], sizeof(std::size_t), N * n, fp);
      }
      else {
        for(std::size_t i = 0; i < N; i++) {
          MElement *e = it->second[i];
          fprintf(fp, "%lu ", e->getNum());
          for(std::size_t i = 0; i < e->getNumVertices(); i++) {
            fprintf(fp, "%lu ", e->getVertex(i)->getNum());
          }
          fprintf(fp, "\n");
        }
      }
    }
  }

  if(binary) fprintf(fp, "\n");

  fprintf(fp, "$EndElements\n");
}

static void writeMSH4PeriodicNodes(GModel *const model, FILE *fp,
                                   bool binary, double version)
{
  // To avoid saving correspondences bwteen nodes that are not saved (either in
  // the same file or not at all, e.g. in the partitioned case, or simply if
  // some physical entities are not defined), we could only apply the code below
  // to the entities returned by getEntitiesForNodes().

  // The current choice is to save everything, and not complain if a node is not
  // found when reading the file. This should be reevaluated at some point.

  std::size_t count = 0;
  std::vector<GEntity *> entities;
  model->getEntities(entities);
  for(std::size_t i = 0; i < entities.size(); i++)
    if(entities[i]->getMeshMaster() != entities[i]) count++;

  if(!count) return;

  fprintf(fp, "$Periodic\n");

  if(binary) { fwrite(&count, sizeof(std::size_t), 1, fp); }
  else {
    fprintf(fp, "%lu\n", count);
  }

  for(std::size_t i = 0; i < entities.size(); i++) {
    GEntity *g_slave = entities[i];
    GEntity *g_master = g_slave->getMeshMaster();

    if(g_slave != g_master) {
      std::map<MVertex *, MVertex *, MVertexPtrLessThan> corrVert;
      corrVert.insert(g_slave->correspondingVertices.begin(),
                      g_slave->correspondingVertices.end());
      if(CTX::instance()->mesh.hoSavePeriodic)
        corrVert.insert(g_slave->correspondingHighOrderVertices.begin(),
                        g_slave->correspondingHighOrderVertices.end());

      if(binary) {
        int gSlaveDim = g_slave->dim();
        int gSlaveTag = g_slave->tag();
        int gMasterTag = g_master->tag();
        fwrite(&gSlaveDim, sizeof(int), 1, fp);
        fwrite(&gSlaveTag, sizeof(int), 1, fp);
        fwrite(&gMasterTag, sizeof(int), 1, fp);

        if(g_slave->affineTransform.size() == 16) {
          std::size_t numAffine = 16;
          fwrite(&numAffine, sizeof(std::size_t), 1, fp);
          for(int j = 0; j < 16; j++) {
            double value = g_slave->affineTransform[j];
            fwrite(&value, sizeof(double), 1, fp);
          }
        }
        else {
          std::size_t numAffine = 0;
          fwrite(&numAffine, sizeof(std::size_t), 1, fp);
        }

        std::size_t corrVertSize = corrVert.size();
        fwrite(&corrVertSize, sizeof(std::size_t), 1, fp);

        for(auto it = corrVert.begin(); it != corrVert.end(); ++it) {
          std::size_t numFirst = it->first->getNum();
          std::size_t numSecond = it->second->getNum();
          fwrite(&numFirst, sizeof(std::size_t), 1, fp);
          fwrite(&numSecond, sizeof(std::size_t), 1, fp);
        }
      }
      else {
        fprintf(fp, "%d %d %d\n", g_slave->dim(), g_slave->tag(),
                g_master->tag());

        if(version >= 4.1) {
          if(g_slave->affineTransform.size() == 16) {
            fprintf(fp, "16");
            for(int j = 0; j < 16; j++)
              fprintf(fp, " %.16g", g_slave->affineTransform[j]);
            fprintf(fp, "\n");
          }
          else {
            fprintf(fp, "0\n");
          }
        }
        else {
          if(g_slave->affineTransform.size() == 16) {
            fprintf(fp, "Affine");
            for(int j = 0; j < 16; j++)
              fprintf(fp, " %.16g", g_slave->affineTransform[j]);
            fprintf(fp, "\n");
          }
        }

        fprintf(fp, "%lu\n", corrVert.size());

        for(auto it = corrVert.begin(); it != corrVert.end(); ++it) {
          fprintf(fp, "%lu %lu\n", it->first->getNum(), it->second->getNum());
        }
      }
    }
  }

  if(binary) fprintf(fp, "\n");
  fprintf(fp, "$EndPeriodic\n");
}

static void writeMSH4GhostCells(GModel *const model, FILE *fp,
                                int partitionToSave, bool binary)
{
  std::vector<GEntity *> entities;
  model->getEntities(entities);
  std::map<MElement *, std::vector<int> > ghostCells;

  for(std::size_t i = 0; i < entities.size(); i++) {
    std::map<MElement *, int> ghostElements;
    int partition;

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

    if(!partitionToSave || partitionToSave == partition) {
      for(auto it = ghostElements.begin(); it != ghostElements.end(); ++it) {
        if(ghostCells[it->first].size() == 0)
          ghostCells[it->first].push_back(it->second);
        ghostCells[it->first].push_back(partition);
      }
    }
  }

  if(ghostCells.size() != 0) {
    fprintf(fp, "$GhostElements\n");
    if(binary) {
      std::size_t ghostCellsSize = ghostCells.size();
      fwrite(&ghostCellsSize, sizeof(std::size_t), 1, fp);

      for(auto it = ghostCells.begin(); it != ghostCells.end(); ++it) {
        std::size_t elmTag = it->first->getNum();
        int partNum = it->second[0];
        std::size_t numGhostPartitions = it->second.size() - 1;
        fwrite(&elmTag, sizeof(std::size_t), 1, fp);
        fwrite(&partNum, sizeof(int), 1, fp);
        fwrite(&numGhostPartitions, sizeof(std::size_t), 1, fp);
        for(std::size_t i = 1; i < it->second.size(); i++) {
          fwrite(&it->second[i], sizeof(int), 1, fp);
        }
      }
      fprintf(fp, "\n");
    }
    else {
      fprintf(fp, "%ld\n", ghostCells.size());

      for(auto it = ghostCells.begin(); it != ghostCells.end(); ++it) {
        fprintf(fp, "%lu %d %ld", it->first->getNum(), it->second[0],
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

static void writeMSH4Parametrizations(GModel *const model, FILE *fp,
                                      bool binary)
{
  std::size_t nParamE = 0, nParamF = 0;

  for(auto it = model->firstEdge(); it != model->lastEdge(); ++it) {
    discreteEdge *de = dynamic_cast<discreteEdge *>(*it);
    if(de && de->haveParametrization()) { nParamE++; }
  }
  for(auto it = model->firstFace(); it != model->lastFace(); ++it) {
    discreteFace *df = dynamic_cast<discreteFace *>(*it);
    if(df && df->haveParametrization()) { nParamF++; }
  }

  if(!nParamE && !nParamF) return;

  fprintf(fp, "$Parametrizations\n");

  if(binary) {
    fwrite(&nParamE, sizeof(std::size_t), 1, fp);
    fwrite(&nParamF, sizeof(std::size_t), 1, fp);
  }
  else {
    fprintf(fp, "%lu %lu\n", nParamE, nParamF);
  }

  for(auto it = model->firstEdge(); it != model->lastEdge(); ++it) {
    discreteEdge *de = dynamic_cast<discreteEdge *>(*it);
    if(de && de->haveParametrization()) {
      int t = de->tag();
      if(binary)
        fwrite(&t, sizeof(int), 1, fp);
      else
        fprintf(fp, "%d\n", t);
      de->writeParametrization(fp, binary);
    }
  }
  for(auto it = model->firstFace(); it != model->lastFace(); ++it) {
    discreteFace *df = dynamic_cast<discreteFace *>(*it);
    if(df && df->haveParametrization()) {
      int t = df->tag();
      if(binary)
        fwrite(&t, sizeof(int), 1, fp);
      else
        fprintf(fp, "%d\n", t);
      df->writeParametrization(fp, binary);
    }
  }

  if(binary) fprintf(fp, "\n");

  fprintf(fp, "$EndParametrizations\n");
}

static void writeMSH4Edges(GModel *const model, FILE *fp, bool partitioned,
                              int partitionToSave, bool binary, bool saveAll,
                              double version)
{
  if(model->getNumMEdges() == 0) return;
  // Future option: only save tags from overlaps and interfaces
  double t1 = TimeOfDay();

  std::set<GRegion *, GEntityPtrLessThan> regions;
  std::set<GFace *, GEntityPtrLessThan> faces;
  std::set<GEdge *, GEntityPtrLessThan> edges;
  std::set<GVertex *, GEntityPtrLessThan> vertices;
  getEntitiesToSave(model, partitioned, partitionToSave, saveAll, regions,
                    faces, edges, vertices);
  getAdditionalEntities(regions, faces, edges, vertices, model->getAllOverlapBoundaries());

  // Add overlaps. Overlap boundaries shouldn't be necessary!
  if(partitionToSave != 0) {
    for(const auto &[parentEdgeTag, manager] :
        model->getOverlapEdgeManagers()) {
      const auto overlapsOnPartition = manager->getOverlapsOf(partitionToSave);
      if(!overlapsOnPartition) { continue; }
      for(const auto &[j, overlapFace] : *overlapsOnPartition) {
        edges.insert(overlapFace);
      }
    }
    for(const auto &[parentFaceTag, manager] :
        model->getOverlapFaceManagers()) {
      const auto& dict = manager->getOverlapsByPartition();
      auto it = dict.find(partitionToSave);
      if (it == dict.end()) continue;

      for (auto ovlp : it->second) {
        faces.insert(ovlp);
      }
    }
    for(const auto &[parentVolumeTag, manager] :
        model->getOverlapRegionManagers()) {

      const auto& dict = manager->getOverlapsByPartition();
      auto it = dict.find(partitionToSave);
      if (it == dict.end()) continue;

      for (overlapRegion* oregion : it->second) {
        regions.insert(oregion);
      }
    }
  }

  // Additional entities ?
  std::unordered_map<MEdge, size_t, MEdgeHash, MEdgeEqual> edgeTagsDict;
  auto& allEdges = model->getMapEdgeNum();
  for(GRegion *r : regions) {
    for(size_t k = 0; k < r->getNumMeshElements(); ++k) {
      MElement *e = r->getMeshElement(k);
      for(std::size_t j = 0; j < e->getNumEdges(); j++) {
        MEdge edge = e->getEdge(j);
        if(edgeTagsDict.count(edge)) continue;
        auto it = allEdges.find(edge);
        if(it != allEdges.end()) { edgeTagsDict[edge] = it->second; }
      }
    }
  }
  for(GFace *f : faces) {
    for(size_t k = 0; k < f->getNumMeshElements(); ++k) {
      MElement *e = f->getMeshElement(k);
      for(std::size_t j = 0; j < e->getNumEdges(); j++) {
        MEdge edge = e->getEdge(j);
        if(edgeTagsDict.count(edge)) continue;
        auto it = allEdges.find(edge);
        if(it != allEdges.end()) { edgeTagsDict[edge] = it->second; }
      }
    }
  }
  for(GEdge *e : edges) {
    for(size_t k = 0; k < e->getNumMeshElements(); ++k) {
      MElement *el = e->getMeshElement(k);
      for(std::size_t j = 0; j < el->getNumEdges(); j++) {
        MEdge edge = el->getEdge(j);
        if(edgeTagsDict.count(edge)) continue;
        auto it = allEdges.find(edge);
        if(it != allEdges.end()) { edgeTagsDict[edge] = it->second; }
      }
    }
  }

  std::vector<std::size_t> edgeTags;
  std::vector<std::size_t> edgeNodes;
  edgeTags.reserve(model->getNumMEdges());
  edgeNodes.reserve(model->getNumMEdges() * 2);
  for(auto it = edgeTagsDict.begin(); it != edgeTagsDict.end(); ++it) {
    edgeTags.push_back(it->second);
    edgeNodes.push_back(it->first.getVertex(0)->getNum());
    edgeNodes.push_back(it->first.getVertex(1)->getNum());
  }

  fprintf(fp, "$EdgeTags\n");
  size_t numEdgeTags = edgeTags.size();
  if(binary)
    fwrite(&numEdgeTags, sizeof(size_t), 1, fp);
  else
    fprintf(fp, "%lu\n", numEdgeTags);

  if(binary) {
    for(std::size_t tag = 0; tag < edgeTags.size(); ++tag) {
      size_t buffer[3] = {edgeTags[tag], edgeNodes[2 * tag],
                          edgeNodes[2 * tag + 1]};
      fwrite(buffer, sizeof(size_t), 3, fp);
    }
  }
  else {
    for(std::size_t tag = 0; tag < edgeTags.size(); ++tag) {
      fprintf(fp, "%lu %lu %lu\n", edgeTags[tag], edgeNodes[2 * tag],
              edgeNodes[2 * tag + 1]);
    }
  }

  if(binary) fprintf(fp, "\n");

  fprintf(fp, "$EndEdgeTags\n");

  Msg::StatusBar(true, "Done writing %lu edges in %gs.", edgeTags.size(), TimeOfDay() - t1);
}

static void writeMSH4Faces(GModel *const model, FILE *fp, bool partitioned,
                           int partitionToSave, bool binary, bool saveAll,
                           double version)
{
  size_t numFaceTags = model->getNumMFaces();
  if(numFaceTags == 0) return;
  double t1 = TimeOfDay();

  std::set<GRegion *, GEntityPtrLessThan> regions;
  std::set<GFace *, GEntityPtrLessThan> faces;
  std::set<GEdge *, GEntityPtrLessThan> edges;
  std::set<GVertex *, GEntityPtrLessThan> vertices;
  getEntitiesToSave(model, partitioned, partitionToSave, saveAll, regions,
                    faces, edges, vertices);
  getAdditionalEntities(regions, faces, edges, vertices,
                        model->getAllOverlapBoundaries());

  // add overlaps
  if(partitionToSave != 0) {
    for(const auto &[parentEdgeTag, manager] :
        model->getOverlapEdgeManagers()) {
      const auto overlapsOnPartition = manager->getOverlapsOf(partitionToSave);
      if(!overlapsOnPartition) { continue; }
      for(const auto &[j, overlapFace] : *overlapsOnPartition) {
        edges.insert(overlapFace);
      }
    }
    for(const auto &[parentFaceTag, manager] :
        model->getOverlapFaceManagers()) {
      const auto &dict = manager->getOverlapsByPartition();
      auto it = dict.find(partitionToSave);
      if(it == dict.end()) continue;

      for(overlapFace *ovlp : it->second) { faces.insert(ovlp); }
    }
    for(const auto &[parentVolumeTag, manager] :
        model->getOverlapRegionManagers()) {
      const auto &dict = manager->getOverlapsByPartition();
      auto it = dict.find(partitionToSave);
      if(it == dict.end()) continue;

      for(overlapRegion *oregion : it->second) { regions.insert(oregion); }
    }
  }

  std::unordered_map<MFace, std::size_t, MFaceHash, MFaceEqual> faceTagsToKeep;

  for(GRegion *r : regions) {
    for(std::size_t k = 0; k < r->getNumMeshElements(); ++k) {
      MElement *e = r->getMeshElement(k);
      for(std::size_t j = 0; j < e->getNumFaces(); j++) {
        MFace face = e->getFace(j);
        if(faceTagsToKeep.find(face) == faceTagsToKeep.end()) {
          auto it = model->getMapFaceNum().find(face);
          if(it != model->getMapFaceNum().end()) {
            faceTagsToKeep[face] = it->second;
          }
        }
      }
    }
  }
  for(GFace *f : faces) {
    for(std::size_t k = 0; k < f->getNumMeshElements(); ++k) {
      MElement *e = f->getMeshElement(k);
      for(std::size_t j = 0; j < e->getNumFaces(); j++) {
        MFace face = e->getFace(j);
        if(faceTagsToKeep.find(face) == faceTagsToKeep.end()) {
          auto it = model->getMapFaceNum().find(face);
          if(it != model->getMapFaceNum().end()) {
            faceTagsToKeep[face] = it->second;
          }
        }
      }
    }
  }

  numFaceTags = faceTagsToKeep.size();
  fprintf(fp, "$FaceTags\n");
  if(binary) { fwrite(&numFaceTags, sizeof(std::size_t), 1, fp); }
  else {
    fprintf(fp, "%lu\n", numFaceTags);
  }
  // for(auto it = model->firstMFace(); it != model->lastMFace(); ++it) {
  for(auto it = faceTagsToKeep.begin(); it != faceTagsToKeep.end(); ++it) {
    // TAG NUM_VERT VERT1 VERT2 ... VERTN
    auto nVert = it->first.getNumVertices();
    std::size_t buffer[2] = {it->second, nVert};
    if(binary) { fwrite(buffer, sizeof(std::size_t), 2, fp); }
    else {
      fprintf(fp, "%lu %lu", it->second, nVert);
    }
    for(std::size_t i = 0; i < nVert; ++i) {
      std::size_t v = it->first.getVertex(i)->getNum();
      if(binary) { fwrite(&v, sizeof(std::size_t), 1, fp); }
      else {
        fprintf(fp, " %lu", v);
      }
    }
    if(!binary) { fprintf(fp, "\n"); }
  }

  if(binary) fprintf(fp, "\n");
  fprintf(fp, "$EndFaceTags\n");
  Msg::StatusBar(true, "Done writing %lu faces in %gs.", faceTagsToKeep.size(),
                 TimeOfDay() - t1);
}

int GModel::_writeMSH4(const std::string &name, double version, bool binary,
                       bool saveAll, bool saveParametric, double scalingFactor,
                       bool append, int partitionToSave,
                       std::map<GEntity*, SBoundingBox3d> *entityBounds)
{
  FILE *fp = nullptr;
  if(append)
    fp = Fopen(name.c_str(), binary ? "ab" : "a");
  else
    fp = Fopen(name.c_str(), binary ? "wb" : "w");

  if(!fp) {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  if(version < 4.1 && binary) {
    Msg::Error("Can only write MSH 4.0 format in ASCII mode");
    return 0;
  }

  // if there are no physicals we save all the elements
  if(noPhysicalGroups()) saveAll = true;

  // header
  fprintf(fp, "$MeshFormat\n");
  fprintf(fp, "%g %d %lu\n", version, (binary ? 1 : 0), sizeof(std::size_t));
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
    for(auto it = firstPhysicalName(); it != lastPhysicalName(); ++it) {
      std::string name = it->second;
      if(name.size() > 128) name.resize(128);
      fprintf(fp, "%d %d \"%s\"\n", it->first.first, it->first.second,
              name.c_str());
    }
    fprintf(fp, "$EndPhysicalNames\n");
  }

  // entities
  writeMSH4Entities(this, fp, false, binary, scalingFactor, version,
                    entityBounds);

  // check if the mesh is partitioned... and if we actually have elements in the
  // partitioned entities
  bool partitioned = getNumPartitions() > 0;
  if(partitioned) {
    std::vector<GEntity *> entities;
    getEntities(entities);
    std::size_t partEnt = 0;
    for(auto &ge : entities) {
      if(ge->geomType() == GEntity::PartitionPoint ||
         ge->geomType() == GEntity::PartitionCurve ||
         ge->geomType() == GEntity::PartitionSurface ||
         ge->geomType() == GEntity::PartitionVolume ||
         ge->geomType() == GEntity::GhostCurve ||
         ge->geomType() == GEntity::GhostSurface ||
         ge->geomType() == GEntity::GhostVolume)
        partEnt++;
    }
    if(!partEnt) {
      // this can happen when e.g. loading an old MSH2 files with partition tags
      // stored in elements
      Msg::Warning("No partition entities found, saving mesh as unpartitioned");
      partitioned = false;
    }
  }

  // partitioned entities
  EntitiesPack savePartitionedEntities;
  if(partitioned)
    writeMSH4Entities(this, fp, true, binary, scalingFactor, version,
                      entityBounds, partitionToSave, &savePartitionedEntities);

  // nodes
  writeMSH4Nodes(this, fp, partitioned, partitionToSave, binary,
                 saveParametric ? 1 : 0, scalingFactor, saveAll, version, &savePartitionedEntities);

  // elements
  writeMSH4Elements(this, fp, partitioned, partitionToSave, binary, saveAll,
                    version);

  // write overlaps, AFTER the elements
  if(partitioned && hasOverlaps()) {
    writeMSH4Overlaps(this, fp, partitionToSave, binary, scalingFactor, version,
                      entityBounds);
    writeMSH4OverlapBoundaries(this, fp, partitionToSave, binary, scalingFactor,
                               version, entityBounds);
  }

  // Edge tags
  writeMSH4Edges(this, fp, partitioned, partitionToSave, binary, saveAll,
                 version);

  // Face tags
  writeMSH4Faces(this, fp, partitioned, partitionToSave, binary, saveAll,
                 version);
  // periodic
  writeMSH4PeriodicNodes(this, fp, binary, version);

  // ghostCells
  writeMSH4GhostCells(this, fp, partitionToSave, binary);

  // parametrizations
  writeMSH4Parametrizations(this, fp, binary);

  // attributes
  for(auto &a : _attributes) {
    fprintf(fp, "$%s\n", a.first.c_str());
    for(auto &s : a.second) fprintf(fp, "%s\n", s.c_str());
    fprintf(fp, "$End%s\n", a.first.c_str());
  }

  fclose(fp);

  return 1;
}

int GModel::_writePartitionedMSH4(const std::string &baseName, double version,
                                  bool binary, bool saveAll,
                                  bool saveParametric, double scalingFactor)
{
  int nthreads = CTX::instance()->numThreads;
  if(!nthreads) nthreads = Msg::GetMaxThreads();

  // precompute entity bounding boxes (we write the full brep in each file, so
  // otherwise we would compute the bounding boxes as many times as we have
  // partitions)
  std::vector<GEntity*> entities;
  getEntities(entities);
  std::vector<SBoundingBox3d> bounds(entities.size());
#pragma omp parallel for num_threads(nthreads)
  for(std::size_t i = 0; i < entities.size(); i++) {
    bounds[i] = entities[i]->bounds();
  }
  std::map<GEntity*, SBoundingBox3d> entityBounds;
  for(std::size_t i = 0; i < entities.size(); i++) {
    entityBounds[entities[i]] = bounds[i];
  }

  bool exceptions = false;
#pragma omp parallel for num_threads(nthreads)
  for(std::size_t part = 1; part <= getNumPartitions(); part++) {
    if(exceptions) continue;
    std::ostringstream sstream;
    sstream << baseName << "_" << part << ".msh";
    if(getNumPartitions() > 100) {
      if(part % 100 == 1) {
        Msg::Info("Writing partition %d/%d in file '%s'", part, getNumPartitions(),
                  sstream.str().c_str());
      }
    }
    else {
      Msg::Info("Writing partition %d in file '%s'", part, sstream.str().c_str());
    }
    try { // OpenMP forbids leaving block via exception
      _writeMSH4(sstream.str(), version, binary, saveAll, saveParametric,
                 scalingFactor, false, part, &entityBounds);
    }
    catch(...) {
      exceptions = true;
    }
  }

  if(exceptions) throw std::runtime_error(Msg::GetLastError());

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
        allParts[entities[i]->dim()].insert
          (std::make_pair(physicals[j],
                          std::make_pair(parentPhysicalTag, partitions)));
      }
    }
  }

  FILE *fp = Fopen(name.c_str(), "w");
  if(!fp) {
    Msg::Error("Could not open file '%s'", name.c_str());
    return 0;
  }

  fprintf(fp, "Group{\n");
  fprintf(fp, "  // Part~{dim}~{parentPhysicalTag}~{part1}~{part2}~...\n\n");
  std::vector<std::map<int, std::string> > tagToString(4);
  for(size_t i = 4; i > 0; --i) {
    fprintf(fp, "  // Dim %lu\n", i - 1);
    for(auto it = allParts[i - 1].begin(); it != allParts[i - 1].end(); ++it) {
      std::string partName = "Part~{" + std::to_string(i - 1) + "}~{" +
                             std::to_string(it->second.first) + "}";
      fprintf(fp, "  Part~{%lu}~{%d}", i - 1, it->second.first);
      for(size_t j = 0; j < it->second.second.size(); ++j) {
        partName += "~{" + std::to_string(it->second.second[j]) + "}";
        fprintf(fp, "~{%d}", it->second.second[j]);
      }
      tagToString[i - 1].insert(std::make_pair(it->first, partName));
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
  for(auto it = allParts[omegaDim].begin(); it != allParts[omegaDim].end();
      ++it) {
    if(it->second.second.size() == 1) {
      omegas[it->second.second[0]].push_back(it->first);
    }
  }
  fprintf(fp, "  // Omega\n");
  for(auto it = omegas.begin(); it != omegas.end(); ++it) {
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
    for(auto it = allParts[omegaDim - 1].begin();
        it != allParts[omegaDim - 1].end(); ++it) {
      if(it->second.second.size() == 2) {
        sigmasij[std::make_pair(it->second.second[0],
                                it->second.second[1])]
          .push_back(it->first);
        sigmasij[std::make_pair(it->second.second[1],
                                it->second.second[0])]
          .push_back(it->first);
        sigmas[it->second.second[0]].push_back(it->first);
        sigmas[it->second.second[1]].push_back(it->first);
      }
    }
    fprintf(fp, "  // Sigma\n");
    for(auto it = sigmasij.begin(); it != sigmasij.end(); ++it) {
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

    for(auto it = sigmas.begin(); it != sigmas.end(); ++it) {
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
    for(auto it = allParts[omegaDim - 1].begin();
        it != allParts[omegaDim - 1].end(); ++it) {
      if(it->second.second.size() == 2) {
        neighbors[it->second.second[0]].insert(it->second.second[1]);
        neighbors[it->second.second[1]].insert(it->second.second[0]);
      }
    }
    for(size_t i = 1; i <= getNumPartitions(); ++i) {
      fprintf(fp, "  D~{%lu}() = {", i);
      for(auto it = neighbors[i].begin(); it != neighbors[i].end(); ++it) {
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
