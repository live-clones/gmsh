// Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Anthony Royer
//   Boris Martin

#include <cstddef>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <string>
#include <cstdlib>
#include <limits>
#include <stdexcept>
#include <variant>

#include "GmshDefines.h"
#include "MElement.h"
#include "OS.h"
#include "Context.h"
#include "GModel.h"
#include "GModelIO_MSH4.h"
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
#include "Overlap.h"

#if defined(HAVE_POST)
#include "PView.h"
#endif

static std::pair<MElement *, GEntity *> *
readMSH5Polytopes(GModel *const model, FILE *fp, bool binary, bool &dense,
                  std::size_t &totalNumRead, std::size_t &maxElementNum,
                  bool swap, double version)
{
  char str[10000]; // 1000 nodes for order 9 hex, 10 digits each
  std::size_t numBlock = 0, minTag = 0, maxTag = 0;
  totalNumRead = 0;
  maxElementNum = 0;

  if(binary) {
    std::size_t data[4];
    if(fread(data, sizeof(std::size_t), 4, fp) != 4) { return nullptr; }
    if(swap) SwapBytes((char *)data, sizeof(std::size_t), 4);
    numBlock = data[0];
    totalNumRead = data[1];
    minTag = data[2];
    maxTag = data[3];
  }
  else {
    if(fscanf(fp, "%zu %zu %zu %zu", &numBlock, &totalNumRead, &minTag,
              &maxTag) != 4) {
      return nullptr;
    }
  }

  std::size_t elementRead = 0;
  std::size_t minElementNum = std::numeric_limits<std::size_t>::max();

  std::pair<MElement *, GEntity *> *elementsRead =
    new std::pair<MElement *, GEntity *>[totalNumRead];
  Msg::StartProgressMeter(totalNumRead);

  for(std::size_t i = 0; i < numBlock; i++) {
    int entityTag = 0, entityDim = 0, elmType = 0;
    std::size_t numElements = 0;

    if(binary) {
      int data[3];
      if(fread(data, sizeof(int), 3, fp) != 3) {
        delete[] elementsRead;
        return nullptr;
      }
      if(swap) SwapBytes((char *)data, sizeof(int), 3);
      entityDim = data[0];
      entityTag = data[1];
      elmType = data[2];

      if(fread(&numElements, sizeof(std::size_t), 1, fp) != 1) {
        delete[] elementsRead;
        return nullptr;
      }
      if(swap) SwapBytes((char *)&numElements, sizeof(std::size_t), 1);
    }
    else {
      if(fscanf(fp, "%d %d %d %zu", &entityDim, &entityTag, &elmType,
                &numElements) != 4) {
        delete[] elementsRead;
        return nullptr;
      }
    }

    if(elmType != MSH_POLYG_ && elmType != MSH_POLYH_) {
      Msg::Error("Element type %d is not a polygon or polyhedron. Please "
                 "define it in $Elements instead of $Polytopes.",
                 elmType);
      delete[] elementsRead;
      return nullptr;
    }

    GEntity *entity = model->getEntityByTag(entityDim, entityTag);
    if(!entity) {
      Msg::Error("Unknown entity %d of dimension %d", entityTag, entityDim);
      delete[] elementsRead;
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

    const int numVertPerSimplex = entityDim + 1;
    if(binary) {
      for(int i = 0; i < numElements; ++i) {
        std::size_t elemTag, numSimplices;
        if(fread(&elemTag, sizeof(std::size_t), 1, fp) != 1) {
          delete[] elementsRead;
          return nullptr;
        }
        if(swap) SwapBytes((char *)&elemTag, sizeof(std::size_t), 1);
        if(fread(&numSimplices, sizeof(std::size_t), 1, fp) != 1) {
          delete[] elementsRead;
          return nullptr;
        }
        if(swap) SwapBytes((char *)&numSimplices, sizeof(std::size_t), 1);

        std::size_t n = numSimplices * numVertPerSimplex;
        std::vector<std::size_t> data(n);
        if(fread(&data[0], sizeof(std::size_t), n, fp) != n) {
          delete[] elementsRead;
          return nullptr;
        }
        if(swap) SwapBytes((char *)&data[0], sizeof(std::size_t), n);

        std::vector<MVertex *> vertices(n, (MVertex *)nullptr);
        for(int k = 0; k < n; k++) {
          vertices[k] = model->getMeshVertexByTag(data[k]);
          if(!vertices[k]) {
            Msg::Error("Unknown node %zu in element %zu, for entity %d %d and "
                       "element type %d",
                       data[k], elemTag, entityDim, entityTag, elmType);
            delete[] elementsRead;
            return nullptr;
          }
        }

        MElementFactory elementFactory;
        MElement *element = elementFactory.create(
          elmType, vertices, elemTag, 0, false, 0, nullptr, nullptr, nullptr);
        if(!element) {
          Msg::Error("Could not create element %zu of type %d", elemTag,
                     elmType);
          delete[] elementsRead;
          return nullptr;
        }

        minElementNum = std::min(minElementNum, elemTag);
        maxElementNum = std::max(maxElementNum, elemTag);

        elementsRead[elementRead] = std::make_pair(element, entity);
        elementRead++;

        if(totalNumRead > 100000)
          Msg::ProgressMeter(elementRead, true, "Reading elements");
      }
    }
    else {
      for(std::size_t j = 0; j < numElements; j++) {
        std::size_t elmTag = 0;
        if(fscanf(fp, "%zu", &elmTag) != 1) {
          delete[] elementsRead;
          return nullptr;
        }

        std::size_t numSimplices = 0;
        if(fscanf(fp, "%zu", &numSimplices) != 1) {
          delete[] elementsRead;
          return nullptr;
        }

        // We read all node tags with a single fread() to improve
        // performance. Beware that this assumes that all node tags are on a
        // single line, which is not required by the MSH5 specification - we
        // might need to revert to multiple fscanf() calls instead (see
        // e.g. #2724)
        if(!fgets(str, sizeof(str), fp)) {
          delete[] elementsRead;
          return nullptr;
        }

        std::size_t numVertPerSimplex = entityDim + 1;
        std::size_t n = numVertPerSimplex * numSimplices;
        std::vector<MVertex *> vertices(n, (MVertex *)nullptr);

        for(int k = 0; k < n; k++) {
          std::size_t vertexTag = 0;
          if(k != n - 1) {
            if(sscanf(str, "%zu %[0-9- ]", &vertexTag, str) != 2) {
              delete[] elementsRead;
              return nullptr;
            }
          }
          else {
            if(sscanf(str, "%zu", &vertexTag) != 1) {
              delete[] elementsRead;
              return nullptr;
            }
          }

          vertices[k] = model->getMeshVertexByTag(vertexTag);
          if(!vertices[k]) {
            auto parts = getEntityPartition(entity, false);
            std::string partitionInfo = "";
            if(!parts.empty()) {
              partitionInfo = " (partitions:";
              for(auto p : parts) partitionInfo += " " + std::to_string(p);
              partitionInfo += ")";
            }
            Msg::Error(
              "Unknown node %zu in element %zu in entity %d %d and elementType "
              "%d. Entity type is %s. Partition data is %s",
              vertexTag, elmTag, entityDim, entityTag, elmType,
              entity->getTypeString().c_str(), partitionInfo.c_str());
            delete[] elementsRead;
            return nullptr;
          }
        }

        MElementFactory elementFactory;
        MElement *element = elementFactory.create(
          elmType, vertices, elmTag, 0, false, 0, nullptr, nullptr, nullptr);
        if(!element) {
          Msg::Error("Could not create element %zu of type %d", elmTag,
                     elmType);
          delete[] elementsRead;
          return nullptr;
        }

        minElementNum = std::min(minElementNum, elmTag);
        maxElementNum = std::max(maxElementNum, elmTag);

        elementsRead[elementRead] = std::make_pair(element, entity);
        elementRead++;

        if(totalNumRead > 100000)
          Msg::ProgressMeter(elementRead, true, "Reading elements");
      }
    }
  }
  // if the vertex numbering is dense, we fill the vector cache, otherwise we
  // fill the map cache
  if(minElementNum == 1 && maxElementNum == totalNumRead) {
    Msg::Debug("Element numbering is dense");
    dense = true;
  }
  else if(maxElementNum < 10 * totalNumRead) {
    Msg::Debug(
      "Element numbering is fairly dense - still caching with a vector");
    dense = true;
  }
  else {
    Msg::Debug("Element numbering is not dense");
    dense = false;
  }

  return elementsRead;
}

int GModel::_readMSH5(const std::string &name)
{
  bool partitioned = false;
  FILE *fp = Fopen(name.c_str(), "rb");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  char str[1024] = "x";
  double version = 1.0;
  bool binary = false, swap = false;

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
      if(sscanf(str, "%lf %d %zu", &version, &format, &size) != 3) {
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
    else if(!strncmp(&str[1], "Nodes", 5)) {
      bool hadNodesBefore =
        !_vertexVectorCache.empty() || !_vertexMapCache.empty();
      bool dense = false;
      std::size_t totalNumRead = 0, maxNodeNum;
      MVertex **verticesRead = readMSH4Nodes(
        this, fp, binary, dense, totalNumRead, maxNodeNum, swap, version);
      Msg::StopProgressMeter();
      if(!verticesRead) {
        Msg::Error("Could not read nodes");
        fclose(fp);
        return false;
      }
      if(hadNodesBefore) {
        // assume numbering is not dense, and fill map cache with previous
        // vertices in the vector cache (if any)
        dense = false;
        for(std::size_t i = 0; i < _vertexVectorCache.size(); i++) {
          MVertex *v = _vertexVectorCache[i];
          if(v) _vertexMapCache[v->getNum()] = v;
        }
        _vertexVectorCache.clear();
      }
      // populate map cache with just-read nodes, and put them in entity if not
      // already in cache
      if(dense) {
        _vertexVectorCache.resize(maxNodeNum + 1, nullptr);
        for(std::size_t i = 0; i < totalNumRead; i++) {
          MVertex *v = verticesRead[i];
          if(!_vertexVectorCache[v->getNum()]) {
            _vertexVectorCache[v->getNum()] = v;
            if(v->onWhat())
              v->onWhat()->addMeshVertex(v);
            else // should not happen
              Msg::Error("Node %zu not classified on any entity", v->getNum());
          }
          else {
            // should not happen
            Msg::Warning("Skipping duplicate node %zu", v->getNum());
            delete v;
          }
        }
      }
      else {
        for(std::size_t i = 0; i < totalNumRead; i++) {
          MVertex *v = verticesRead[i];
          if(_vertexMapCache.count(v->getNum()) == 0) {
            _vertexMapCache[v->getNum()] = v;
            if(v->onWhat())
              v->onWhat()->addMeshVertex(v);
            else // should not happen
              Msg::Error("Node %zu not classified on any entity", v->getNum());
          }
          else {
            if(!hadNodesBefore) // should not happen
              Msg::Warning("Skipping duplicate node %zu", v->getNum());
            delete v;
          }
        }
      }
      delete[] verticesRead;
    }
    else if(!strncmp(&str[1], "Elements", 8) ||
            !strncmp(&str[1], "Polytopes", 9)) {
      bool hadElementsBefore =
        !_elementVectorCache.empty() || !_elementMapCache.empty();
      bool dense = false;
      std::size_t totalNumRead = 0, maxElementNum = 0;
      std::pair<MElement *, GEntity *> *elementsRead = nullptr;
      if(!strncmp(&str[1], "Elements", 8)) {
        elementsRead = readMSH4Elements(this, fp, binary, dense, totalNumRead,
                                        maxElementNum, swap, version);
      }
      else if(!strncmp(&str[1], "Polytopes", 9)) {
        elementsRead = readMSH5Polytopes(this, fp, binary, dense, totalNumRead,
                                         maxElementNum, swap, version);
      }
      Msg::StopProgressMeter();
      if(!elementsRead) {
        Msg::Error("Could not read elements");
        fclose(fp);
        return 0;
      }
      if(hadElementsBefore) {
        // assume numbering is not dense, and fill map cache with previous
        // elements in the vector cache (if any)
        dense = false;
        for(std::size_t i = 0; i < _elementVectorCache.size(); i++) {
          std::pair<MElement *, int> p = _elementVectorCache[i];
          if(p.first) _elementMapCache[p.first->getNum()] = p;
        }
        _elementVectorCache.clear();
      }
      if(dense) {
        _elementVectorCache.resize(maxElementNum + 1,
                                   std::make_pair(nullptr, 0));
        for(std::size_t i = 0; i < totalNumRead; i++) {
          MElement *e = elementsRead[i].first;
          GEntity *entity = elementsRead[i].second;
          if(!_elementVectorCache[e->getNum()].first) {
            _elementVectorCache[e->getNum()] = std::make_pair(e, entity->tag());
            if(entity->geomType() != GEntity::GhostCurve &&
               entity->geomType() != GEntity::GhostSurface &&
               entity->geomType() != GEntity::GhostVolume) {
              entity->addElement(e);
            }
          }
          else { // should not happen
            Msg::Warning("Skipping duplicate element %zu", e->getNum());
            delete e;
          }
        }
      }
      else {
        for(std::size_t i = 0; i < totalNumRead; i++) {
          MElement *e = elementsRead[i].first;
          GEntity *entity = elementsRead[i].second;
          if(_elementMapCache.count(e->getNum()) == 0) {
            _elementMapCache[e->getNum()] = std::make_pair(e, entity->tag());
            if(entity->geomType() != GEntity::GhostCurve &&
               entity->geomType() != GEntity::GhostSurface &&
               entity->geomType() != GEntity::GhostVolume) {
              entity->addElement(e);
            }
          }
          else {
            if(!hadElementsBefore) // should not happen
              Msg::Warning("Skipping duplicate element %zu", e->getNum());
            delete e;
          }
        }
      }
      delete[] elementsRead;
    }
    else if(!strncmp(&str[1], "Edges", 5)) {
      if(!readMSH4Edges(this, fp, binary)) {
        Msg::Error("Could not read edges");
        fclose(fp);
        return 0;
      }
    }
    else if(!strncmp(&str[1], "Faces", 5)) {
      if(!readMSH4Faces(this, fp, binary)) {
        Msg::Error("Could not read faces");
        fclose(fp);
        return 0;
      }
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
    else if(!strncmp(&str[1], "Overlaps2D", 10)) {
      if(!readMSH4Overlaps<2>(this, fp, binary)) {
        Msg::Error("Could not read 2D volume overlaps");
        fclose(fp);
        return 0;
      }
    }
    else if(!strncmp(&str[1], "Overlaps3D", 10)) {
      if(!readMSH4Overlaps<3>(this, fp, binary)) {
        Msg::Error("Could not read 3D volume overlaps");
        fclose(fp);
        return 0;
      }
    }
    else if(!strncmp(&str[1], "OverlapBoundaries2D", 19)) {
      if(!readMSH4OverlapBoundaries<2>(this, fp, binary)) {
        Msg::Error("Could not read 2D boundary overlaps");
        fclose(fp);
        return 0;
      }
    }
    else if(!strncmp(&str[1], "OverlapBoundaries3D", 19)) {
      if(!readMSH4OverlapBoundaries<3>(this, fp, binary)) {
        Msg::Error("Could not read 3D boundary overlaps");
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
#if defined(HAVE_POST)
    else if(!strncmp(&str[1], "InterpolationScheme", 19)) {
      if(!PView::readMSHInterpolationScheme(fp)) {
        fclose(fp);
        return 0;
      }
    }
    else if(!strncmp(&str[1], "NodeData", 8) ||
            !strncmp(&str[1], "ElementData", 11) ||
            !strncmp(&str[1], "ElementNodeData", 15)) {
      if(!PView::readMSHViewData(name, fp, binary, swap, &str[1])) {
        fclose(fp);
        return 0;
      }
    }
#endif
    else if(strlen(&str[1]) > 0) {
      if(!CTX::instance()->mesh.ignoreUnknownSections) {
        sectionName.pop_back();
        Msg::Info("Storing section $%s as model attribute",
                  sectionName.c_str());
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

  return 1;
}

void getElementsAndPolytopesToSave(
  GModel *const model, bool partitioned, int partitionToSave, bool saveAll,
  const std::variant<
    std::monostate,
    decltype(findCoveredEntitiesAndElementsToSave<2>(model, partitionToSave)),
    decltype(findCoveredEntitiesAndElementsToSave<3>(model, partitionToSave))>
    &overlapElements,
  std::map<std::pair<int, int>, std::vector<MElement *>> *elementsByType,
  std::size_t &numElements)
{
  /**
   * If the mesh is partitioned and only one partition is saved, we save
   * 1) elements on an enitity belonging to (at least) this partition
   * 2) overlap boundary elements if there is an overlap
   * 3) overlapped entities, with only the subset of elements actually used by
   * the overlaps
   */

  std::set<GRegion *, GEntityPtrLessThan> regions;
  std::set<GFace *, GEntityPtrLessThan> faces;
  std::set<GEdge *, GEntityPtrLessThan> edges;
  std::set<GVertex *, GEntityPtrLessThan> vertices;
  getEntitiesToSave(model, partitioned, partitionToSave, saveAll, regions,
                    faces, edges, vertices);

  const int overlapDim = model->overlapDim();
  std::unordered_set<GEdge *> overlapBnd2D;
  std::unordered_set<GFace *> overlapBnd3D;

  auto addOverlapBoundaries = [&](const auto &map, auto &container) {
    using ContainerType =
      std::remove_cv_t<std::remove_reference_t<decltype(container)>>;
    for(const auto &[parent, vecOfEntities] : map) {
      for(const auto &entity : vecOfEntities) {
        auto partitions = entity->getPartitions();
        if(partitions.size() != 1)
          Msg::Error("Overlap boundary with more than one partition.");
        int partition = *partitions.begin();
        if(partition == partitionToSave) {
          if constexpr(std::is_same_v<ContainerType,
                                      std::unordered_set<GEdge *>>) {
            auto cast = static_cast<GEdge *>(entity);
            if(!cast) Msg::Error("Expected GEdge for 2D overlap boundary.");
            edges.insert(cast);
            overlapBnd2D.insert(cast);
          }
          else if constexpr(std::is_same_v<ContainerType,
                                           std::unordered_set<GFace *>>) {
            auto cast = static_cast<GFace *>(entity);
            if(!cast) Msg::Error("Expected GFace for 3D overlap boundary.");
            faces.insert(cast);
            overlapBnd3D.insert(cast);
          }
          else {
            Msg::Error("Unsupported overlap boundary type.");
          }
        }
      }
    }
  };

  addOverlapBoundaries(model->getOverlapInnerBoundaries2D(), overlapBnd2D);
  addOverlapBoundaries(model->getOverlapOfBoundaries2D(), overlapBnd2D);
  addOverlapBoundaries(model->getOverlapInnerBoundaries3D(), overlapBnd3D);
  addOverlapBoundaries(model->getOverlapOfBoundaries3D(), overlapBnd3D);

  // std::map<std::pair<int, int>, std::vector<MElement *>> elementsByType[4];
  // std::size_t numElements = 0;
  elementsByType[0].clear();
  elementsByType[1].clear();
  elementsByType[2].clear();
  elementsByType[3].clear();
  numElements = 0;

  for(auto it = vertices.begin(); it != vertices.end(); ++it) {
    if(!saveAll && (*it)->physicals.size() == 0) continue;

    numElements += (*it)->points.size();
    for(std::size_t i = 0; i < (*it)->points.size(); i++) {
      std::pair<int, int> p((*it)->tag(), (*it)->points[i]->getTypeForMSH());
      elementsByType[0][p].push_back((*it)->points[i]);
    }
  }

  for(auto it = edges.begin(); it != edges.end(); ++it) {
    if(!saveAll && (*it)->physicals.size() == 0 &&
       (*it)->geomType() != GEntity::GhostCurve && overlapBnd2D.count(*it) == 0)
      continue;

    numElements += (*it)->lines.size();
    for(std::size_t i = 0; i < (*it)->lines.size(); i++) {
      std::pair<int, int> p((*it)->tag(), (*it)->lines[i]->getTypeForMSH());
      elementsByType[1][p].push_back((*it)->lines[i]);
    }
  }

  for(auto it = faces.begin(); it != faces.end(); ++it) {
    if(!saveAll && (*it)->physicals.size() == 0 &&
       (*it)->geomType() != GEntity::GhostSurface &&
       overlapBnd3D.count(*it) == 0)
      continue;

    numElements += (*it)->triangles.size();
    for(std::size_t i = 0; i < (*it)->triangles.size(); i++) {
      std::pair<int, int> p((*it)->tag(), (*it)->triangles[i]->getTypeForMSH());
      elementsByType[2][p].push_back((*it)->triangles[i]);
    }
    numElements += (*it)->quadrangles.size();
    for(std::size_t i = 0; i < (*it)->quadrangles.size(); i++) {
      std::pair<int, int> p((*it)->tag(),
                            (*it)->quadrangles[i]->getTypeForMSH());
      elementsByType[2][p].push_back((*it)->quadrangles[i]);
    }
    numElements += (*it)->polygons.size();
    for(std::size_t i = 0; i < (*it)->polygons.size(); i++) {
      std::pair<int, int> p((*it)->tag(), (*it)->polygons[i]->getTypeForMSH());
      elementsByType[2][p].push_back((*it)->polygons[i]);
    }
  }

  // Overlap faces - TODO: ensure it's exported only if not all partitions are
  // saved
  if(overlapDim == 2) {
    auto overlapFaces =
      std::get_if<decltype(findCoveredEntitiesAndElementsToSave<2>(
        model, partitionToSave))>(&overlapElements);
    if(overlapFaces) {
      for(const auto &[pface, elements] : *overlapFaces) {
        int tag = pface->tag();
        if(faces.count(pface)) continue; // already saved
        if(!saveAll && pface->physicals.size() == 0 &&
           pface->geomType() != GEntity::GhostSurface)
          continue;

        numElements += elements.size();
        for(const auto &element : elements) {
          std::pair<int, int> p(tag, element->getTypeForMSH());
          elementsByType[2][p].push_back(element);
        }
      }
    }
  }

  for(auto it = regions.begin(); it != regions.end(); ++it) {
    if(!saveAll && (*it)->physicals.size() == 0 &&
       (*it)->geomType() != GEntity::GhostVolume)
      continue;

    numElements += (*it)->tetrahedra.size();
    for(std::size_t i = 0; i < (*it)->tetrahedra.size(); i++) {
      std::pair<int, int> p((*it)->tag(),
                            (*it)->tetrahedra[i]->getTypeForMSH());
      elementsByType[3][p].push_back((*it)->tetrahedra[i]);
    }
    numElements += (*it)->hexahedra.size();
    for(std::size_t i = 0; i < (*it)->hexahedra.size(); i++) {
      std::pair<int, int> p((*it)->tag(), (*it)->hexahedra[i]->getTypeForMSH());
      elementsByType[3][p].push_back((*it)->hexahedra[i]);
    }
    numElements += (*it)->prisms.size();
    for(std::size_t i = 0; i < (*it)->prisms.size(); i++) {
      std::pair<int, int> p((*it)->tag(), (*it)->prisms[i]->getTypeForMSH());
      elementsByType[3][p].push_back((*it)->prisms[i]);
    }
    numElements += (*it)->pyramids.size();
    for(std::size_t i = 0; i < (*it)->pyramids.size(); i++) {
      std::pair<int, int> p((*it)->tag(), (*it)->pyramids[i]->getTypeForMSH());
      elementsByType[3][p].push_back((*it)->pyramids[i]);
    }
    numElements += (*it)->trihedra.size();
    for(std::size_t i = 0; i < (*it)->trihedra.size(); i++) {
      std::pair<int, int> p((*it)->tag(), (*it)->trihedra[i]->getTypeForMSH());
      elementsByType[3][p].push_back((*it)->trihedra[i]);
    }
    numElements += (*it)->polyhedra.size();
    for(std::size_t i = 0; i < (*it)->polyhedra.size(); i++) {
      std::pair<int, int> p((*it)->tag(), (*it)->polyhedra[i]->getTypeForMSH());
      elementsByType[3][p].push_back((*it)->polyhedra[i]);
    }
  }

  // Overlap regions - TODO: ensure it's exported only if not all partitions are
  // saved
  if(overlapDim == 3) {
    auto overlapRegions =
      std::get_if<decltype(findCoveredEntitiesAndElementsToSave<3>(
        model, partitionToSave))>(&overlapElements);
    if(overlapRegions) {
      for(const auto &[pregion, elements] : *overlapRegions) {
        int tag = pregion->tag();
        if(regions.count(pregion)) continue; // already saved
        if(!saveAll && pregion->physicals.size() == 0 &&
           pregion->geomType() != GEntity::GhostVolume)
          continue;

        numElements += elements.size();
        for(const auto &element : elements) {
          std::pair<int, int> p(tag, element->getTypeForMSH());
          elementsByType[3][p].push_back(element);
        }
      }
    }
  }
}

void extractPolytopesToSave(
  std::map<std::pair<int, int>, std::vector<MElement *>> *elementsByType,
  std::size_t &numElements,
  std::map<std::pair<int, int>, std::vector<MElement *>> *polytopesByType,
  std::size_t &numPolytopes)
{
  polytopesByType[0].clear();
  polytopesByType[1].clear();
  polytopesByType[2].clear();
  polytopesByType[3].clear();
  numPolytopes = 0;

  for(int dim = 0; dim < 4; ++dim) {
    for(auto it = elementsByType[dim].begin();
        it != elementsByType[dim].end();) {
      int type = it->first.second;
      if(type != MSH_POLYG_ && type != MSH_POLYH_) {
        ++it;
        continue;
      }

      numElements -= it->second.size();
      numPolytopes += it->second.size();
      polytopesByType[dim][it->first] = it->second;
      it = elementsByType[dim].erase(it);
    }
  }
}

void writeMSH5Elements(
  FILE *fp, bool binary, double version,
  std::map<std::pair<int, int>, std::vector<MElement *>> *elementsByType,
  std::size_t &numElements)
{
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
      fprintf(fp, "%zu %zu %zu %zu\n", numSection, numElements, minTag, maxTag);
    else
      fprintf(fp, "%zu %zu\n", numSection, numElements);
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
        fprintf(fp, "%d %d %d %zu\n", (version >= 4.1) ? dim : entityTag,
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
          fprintf(fp, "%zu ", e->getNum());
          for(std::size_t i = 0; i < e->getNumVertices(); i++) {
            fprintf(fp, "%zu ", e->getVertex(i)->getNum());
          }
          fprintf(fp, "\n");
        }
      }
    }
  }

  if(binary) fprintf(fp, "\n");

  fprintf(fp, "$EndElements\n");
}

void writeMSH5Polytopes(
  FILE *fp, bool binary, double version,
  std::map<std::pair<int, int>, std::vector<MElement *>> *polytopesByType,
  std::size_t &numPolytopes)
{
  if(!numPolytopes) return;

  fprintf(fp, "$Polytopes\n");

  std::size_t numSection = 0;
  for(int dim = 0; dim <= 3; dim++) numSection += polytopesByType[dim].size();

  std::size_t minTag = std::numeric_limits<std::size_t>::max(), maxTag = 0;
  for(int dim = 0; dim <= 3; dim++) {
    for(auto it = polytopesByType[dim].begin();
        it != polytopesByType[dim].end(); ++it) {
      for(std::size_t i = 0; i < it->second.size(); i++) {
        minTag = std::min(minTag, it->second[i]->getNum());
        maxTag = std::max(maxTag, it->second[i]->getNum());
      }
    }
  }

  if(binary) {
    fwrite(&numSection, sizeof(std::size_t), 1, fp);
    fwrite(&numPolytopes, sizeof(std::size_t), 1, fp);
    fwrite(&minTag, sizeof(std::size_t), 1, fp);
    fwrite(&maxTag, sizeof(std::size_t), 1, fp);
  }
  else {
    if(version >= 4.1)
      fprintf(fp, "%zu %zu %zu %zu\n", numSection, numPolytopes, minTag,
              maxTag);
    else
      fprintf(fp, "%zu %zu\n", numSection, numPolytopes);
  }

  for(int dim = 0; dim <= 3; dim++) {
    for(auto it = polytopesByType[dim].begin();
        it != polytopesByType[dim].end(); ++it) {
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
        fprintf(fp, "%d %d %d %zu\n", (version >= 4.1) ? dim : entityTag,
                (version >= 4.1) ? entityTag : dim, elmType, numElm);
      }

      std::size_t N = it->second.size();
      if(binary) {
        std::vector<std::size_t> tags;
        for(std::size_t i = 0; i < N; i++) {
          MElement *e = it->second[i];
          tags.push_back(e->getNum());
          if(e->getTypeForMSH() == MSH_POLYG_) {
            MPolygon *polygon = static_cast<MPolygon *>(e);
            const int numSimplices = polygon->getNumSimplices();
            tags.push_back(numSimplices);
            for(int j = 0; j < numSimplices; j++) {
              MTriangle simplex = polygon->getSimplex(j);
              for(int k = 0; k < 3; k++) {
                tags.push_back(simplex.getVertex(k)->getNum());
              }
            }
          }
          else if(e->getTypeForMSH() == MSH_POLYH_) {
            MPolyhedron *polyhedron = static_cast<MPolyhedron *>(e);
            const int numSimplices = polyhedron->getNumSimplices();
            tags.push_back(numSimplices);
            for(int j = 0; j < numSimplices; j++) {
              MTetrahedron simplex = polyhedron->getSimplex(j);
              for(int k = 0; k < 4; k++) {
                tags.push_back(simplex.getVertex(k)->getNum());
              }
            }
          }
        }
        fwrite(&tags[0], sizeof(std::size_t), tags.size(), fp);
      }
      else {
        for(std::size_t i = 0; i < N; i++) {
          MElement *e = it->second[i];
          fprintf(fp, "%zu ", e->getNum());
          if(e->getTypeForMSH() == MSH_POLYG_) {
            MPolygon *polygon = static_cast<MPolygon *>(e);
            const int numSimplices = polygon->getNumSimplices();
            fprintf(fp, "%d ", numSimplices);
            for(int j = 0; j < numSimplices; j++) {
              MTriangle simplex = polygon->getSimplex(j);
              for(int k = 0; k < 3; k++) {
                fprintf(fp, "%zu ", simplex.getVertex(k)->getNum());
              }
            }
          }
          else if(e->getTypeForMSH() == MSH_POLYH_) {
            MPolyhedron *polyhedron = static_cast<MPolyhedron *>(e);
            const int numSimplices = polyhedron->getNumSimplices();
            fprintf(fp, "%d ", numSimplices);
            for(int j = 0; j < numSimplices; j++) {
              MTetrahedron simplex = polyhedron->getSimplex(j);
              for(int k = 0; k < 4; k++) {
                fprintf(fp, "%zu ", simplex.getVertex(k)->getNum());
              }
            }
          }
          fprintf(fp, "\n");
        }
      }
    }
  }

  if(binary) fprintf(fp, "\n");

  fprintf(fp, "$EndPolytopes\n");
}

int GModel::_writeMSH5(const std::string &name, double version, bool binary,
                       bool saveAll, bool saveParametric, double scalingFactor,
                       bool append, int partitionToSave,
                       std::map<GEntity *, SBoundingBox3d> *entityBounds)
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
  fprintf(fp, "%.1lf %d %zu\n", version, (binary ? 1 : 0), sizeof(std::size_t));
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

  // entities (the non-partitioned ones)
  writeMSH4Entities(this, fp, false, binary, scalingFactor, version,
                    entityBounds, 0, {});

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

  // Optimized export in the partitioned case:
  // partitionToSave = 0 -> full export
  // partitionToSave > 0, no overlap -> only export what is owned by the
  // partition partitionToSave > 0, with overlap -> export what is owned + what
  // is needed
  std::variant<
    std::monostate,
    decltype(findCoveredEntitiesAndElementsToSave<2>(this, partitionToSave)),
    decltype(findCoveredEntitiesAndElementsToSave<3>(this, partitionToSave))>
    nonOwnedEntitiesToSave;
  int overlapDim = this->overlapDim(); // 0, 2 or 3
  // Find entities of other partitions that are needed in the overlap case.
  if(partitionToSave > 0) {
    if(overlapDim == 2)
      nonOwnedEntitiesToSave =
        findCoveredEntitiesAndElementsToSave<2>(this, partitionToSave);
    else if(overlapDim == 3)
      nonOwnedEntitiesToSave =
        findCoveredEntitiesAndElementsToSave<3>(this, partitionToSave);
  }

  // On those entities, find nodes and entities that must be saved partially.
  // Note that some owned entities will end up there.
  std::unordered_map<GEntity *, std::unordered_set<MVertex *>>
    entitiesWithSubsetToExport;
  if(partitionToSave > 0 && overlapDim > 0) {
    if(overlapDim == 2)
      entitiesWithSubsetToExport = findNonOwnedVerticesToSave<2>(
        this, partitionToSave, std::get<1>(nonOwnedEntitiesToSave));
    else if(overlapDim == 3)
      entitiesWithSubsetToExport = findNonOwnedVerticesToSave<3>(
        this, partitionToSave, std::get<2>(nonOwnedEntitiesToSave));
  }

  // partitioned entities (use entitiesWithSubsetToExport to limit nodes)
  if(partitioned)
    writeMSH4Entities(this, fp, true, binary, scalingFactor, version,
                      entityBounds, partitionToSave,
                      entitiesWithSubsetToExport);

  // nodes
  writeMSH4Nodes(this, fp, partitioned, partitionToSave, binary,
                 saveParametric ? 1 : 0, scalingFactor, saveAll, version,
                 entitiesWithSubsetToExport);

  std::map<std::pair<int, int>, std::vector<MElement *>> elementsByType[4],
    polytopesByType[4];
  std::size_t numElements, numPolytopes;
  getElementsAndPolytopesToSave(this, partitioned, partitionToSave, saveAll,
                                nonOwnedEntitiesToSave, elementsByType,
                                numElements);
  extractPolytopesToSave(elementsByType, numElements, polytopesByType,
                         numPolytopes);

  // elements
  writeMSH5Elements(fp, binary, version, elementsByType, numElements);

  // polytopes
  writeMSH5Polytopes(fp, binary, version, polytopesByType, numPolytopes);

  // edges
  writeMSH4Edges(this, fp, binary, partitioned, partitionToSave);

  // faces
  writeMSH4Faces(this, fp, binary, partitioned, partitionToSave);

  // periodic
  writeMSH4PeriodicNodes(this, fp, binary, version);

  // ghostCells
  writeMSH4GhostCells(this, fp, partitionToSave, binary);

  // overlaps
  if(partitioned && overlapDim > 0) {
    if(overlapDim == 2) {
      writeMSH4Overlaps<2>(this, fp, partitionToSave, binary);
      writeMSH4OverlapBoundaries<2>(this, fp, partitionToSave, binary);
    }
    else if(overlapDim == 3) {
      writeMSH4Overlaps<3>(this, fp, partitionToSave, binary);
      writeMSH4OverlapBoundaries<3>(this, fp, partitionToSave, binary);
    }
  }

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

int GModel::_writePartitionedMSH5(const std::string &baseName, double version,
                                  bool binary, bool saveAll,
                                  bool saveParametric, double scalingFactor)
{
  int nthreads = CTX::instance()->numThreads;
  if(!nthreads) nthreads = Msg::GetMaxThreads();

  // precompute entity bounding boxes (we write the full brep in each file, so
  // otherwise we would compute the bounding boxes as many times as we have
  // partitions)
  std::vector<GEntity *> entities;
  getEntities(entities);
  std::vector<SBoundingBox3d> bounds(entities.size());
#pragma omp parallel for num_threads(nthreads)
  for(std::size_t i = 0; i < entities.size(); i++) {
    bounds[i] = entities[i]->bounds();
  }
  std::map<GEntity *, SBoundingBox3d> entityBounds;
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
        Msg::Info("Writing partition %d/%d in file '%s'", part,
                  getNumPartitions(), sstream.str().c_str());
      }
    }
    else {
      Msg::Info("Writing partition %d in file '%s'", part,
                sstream.str().c_str());
    }
    try { // OpenMP forbids leaving block via exception
      _writeMSH5(sstream.str(), version, binary, saveAll, saveParametric,
                 scalingFactor, false, part, &entityBounds);
    } catch(...) {
      exceptions = true;
    }
  }

  if(exceptions) throw std::runtime_error(Msg::GetLastError());

  return 1;
}
