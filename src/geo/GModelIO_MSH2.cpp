// Gmsh - Copyright (C) 1997-2022 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdlib.h>
#include <string.h>
#include <map>
#include <string>
#include <sstream>
#include <cassert>
#include <iomanip>
#include "GModel.h"
#include "OS.h"
#include "GmshDefines.h"
#include "MPoint.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "MElementCut.h"
#include "StringUtils.h"
#include "GmshMessage.h"
#include "Context.h"
#include "OS.h"
#include "ghostEdge.h"
#include "ghostFace.h"
#include "ghostRegion.h"

// periodic nodes and entities backported from MSH3 format
extern void writeMSHPeriodicNodes(FILE *fp, std::vector<GEntity *> &entities,
                                  bool renumber, bool saveAll);
extern void readMSHPeriodicNodes(FILE *fp, GModel *gm);
extern void writeMSHEntities(FILE *fp, GModel *gm);

static bool getMeshVertices(int num, int *indices,
                            std::map<int, MVertex *> &map,
                            std::vector<MVertex *> &vertices)
{
  for(int i = 0; i < num; i++) {
    if(!map.count(indices[i])) {
      Msg::Error("Wrong node index %d", indices[i]);
      return false;
    }
    else
      vertices.push_back(map[indices[i]]);
  }
  return true;
}

static bool getMeshVertices(int num, int *indices, std::vector<MVertex *> &vec,
                            std::vector<MVertex *> &vertices, int minVertex = 0)
{
  for(int i = 0; i < num; i++) {
    if(indices[i] < minVertex ||
       indices[i] > (int)(vec.size() - 1 + minVertex)) {
      Msg::Error("Wrong node index %d", indices[i]);
      return false;
    }
    else
      vertices.push_back(vec[indices[i]]);
  }
  return true;
}

static MElement *
createElementMSH2(GModel *m, int num, int typeMSH, int physical, int reg,
                  unsigned int part, std::vector<MVertex *> &v,
                  std::map<int, std::vector<MElement *> > elements[10],
                  std::map<int, std::map<int, std::string> > physicals[4],
                  bool owner = false, MElement *parent = nullptr,
                  MElement *d1 = nullptr, MElement *d2 = nullptr)
{
  if(CTX::instance()->mesh.switchElementTags) {
    int tmp = reg;
    reg = physical;
    physical = tmp;
  }

  MElementFactory factory;
  MElement *e = factory.create(typeMSH, v, num, part, owner, 0, parent, d1, d2);

  if(!e) {
    Msg::Error("Unknown type of element %d", typeMSH);
    return nullptr;
  }

  int dim = e->getDim();
  if(physical &&
     (!physicals[dim].count(reg) || !physicals[dim][reg].count(physical)))
    physicals[dim][reg][physical] = "unnamed";

  if(part > m->getNumPartitions()) m->setNumPartitions(part);
  return e;
}

int GModel::_readMSH2(const std::string &name)
{
  FILE *fp = Fopen(name.c_str(), "rb");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  char str[256] = "XXX";
  double version = 1.0;
  bool binary = false, swap = false, postpro = false;
  std::map<int, std::vector<MElement *> > elements[10];
  std::map<int, std::map<int, std::string> > physicals[4];
  std::map<int, MVertex *> vertexMap;
  std::vector<MVertex *> vertexVector;
  int minVertex = 0;
  std::size_t oldNumPartitions = getNumPartitions();

  while(1) {
    while(str[0] != '$') {
      if(!fgets(str, sizeof(str), fp) || feof(fp)) break;
    }

    if(feof(fp)) break;

    if(!strncmp(&str[1], "MeshFormat", 10)) {
      if(!fgets(str, sizeof(str), fp)) {
        fclose(fp);
        return 0;
      }
      int format, size;
      if(sscanf(str, "%lf %d %d", &version, &format, &size) != 3) {
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
      if(!fgets(str, sizeof(str), fp)) {
        fclose(fp);
        return 0;
      }
      int numNames;
      if(sscanf(str, "%d", &numNames) != 1) {
        fclose(fp);
        return 0;
      }
      for(int i = 0; i < numNames; i++) {
        int dim = -1, num;
        if(version > 2.0) {
          if(fscanf(fp, "%d", &dim) != 1) {
            fclose(fp);
            return 0;
          }
        }
        if(fscanf(fp, "%d", &num) != 1) {
          fclose(fp);
          return 0;
        }
        if(!fgets(str, sizeof(str), fp)) {
          fclose(fp);
          return 0;
        }
        std::string name = ExtractDoubleQuotedString(str, 256);
        if(name.size()) setPhysicalName(name, dim, num);
      }
    }
    else if(!strncmp(&str[1], "NO", 2) || !strncmp(&str[1], "Nodes", 5) ||
            !strncmp(&str[1], "ParametricNodes", 15)) {
      const bool parametric = !strncmp(&str[1], "ParametricNodes", 15);
      if(!fgets(str, sizeof(str), fp)) {
        fclose(fp);
        return 0;
      }
      int numVertices = -1;
      if(sscanf(str, "%d", &numVertices) != 1) {
        fclose(fp);
        return 0;
      }
      Msg::Info("%d nodes", numVertices);
      Msg::StartProgressMeter(numVertices);
      vertexVector.clear();
      vertexMap.clear();
      minVertex = numVertices + 1;
      int maxVertex = -1;
      for(int i = 0; i < numVertices; i++) {
        int num;
        double xyz[3], uv[2];
        MVertex *newVertex = nullptr;
        if(!parametric) {
          if(!binary) {
            if(fscanf(fp, "%d %lf %lf %lf", &num, &xyz[0], &xyz[1], &xyz[2]) !=
               4) {
              fclose(fp);
              return 0;
            }
          }
          else {
            if(fread(&num, sizeof(int), 1, fp) != 1) {
              fclose(fp);
              return 0;
            }
            if(swap) SwapBytes((char *)&num, sizeof(int), 1);
            if(fread(xyz, sizeof(double), 3, fp) != 3) {
              fclose(fp);
              return 0;
            }
            if(swap) SwapBytes((char *)xyz, sizeof(double), 3);
          }
          newVertex = new MVertex(xyz[0], xyz[1], xyz[2], nullptr, num);
        }
        else {
          int iClasDim, iClasTag;
          if(!binary) {
            if(fscanf(fp, "%d %lf %lf %lf %d %d", &num, &xyz[0], &xyz[1],
                      &xyz[2], &iClasDim, &iClasTag) != 6) {
              fclose(fp);
              return 0;
            }
          }
          else {
            if(fread(&num, sizeof(int), 1, fp) != 1) {
              fclose(fp);
              return 0;
            }
            if(swap) SwapBytes((char *)&num, sizeof(int), 1);
            if(fread(xyz, sizeof(double), 3, fp) != 3) {
              fclose(fp);
              return 0;
            }
            if(swap) SwapBytes((char *)xyz, sizeof(double), 3);
            if(fread(&iClasDim, sizeof(int), 1, fp) != 1) {
              fclose(fp);
              return 0;
            }
            if(swap) SwapBytes((char *)&iClasDim, sizeof(int), 1);
            if(fread(&iClasTag, sizeof(int), 1, fp) != 1) {
              fclose(fp);
              return 0;
            }
            if(swap) SwapBytes((char *)&iClasTag, sizeof(int), 1);
          }
          if(iClasDim == 0) {
            GVertex *gv = getVertexByTag(iClasTag);
            if(gv) gv->mesh_vertices.clear();
            newVertex = new MVertex(xyz[0], xyz[1], xyz[2], gv, num);
          }
          else if(iClasDim == 1) {
            GEdge *ge = getEdgeByTag(iClasTag);
            if(!binary) {
              if(fscanf(fp, "%lf", &uv[0]) != 1) {
                fclose(fp);
                return 0;
              }
            }
            else {
              if(fread(uv, sizeof(double), 1, fp) != 1) {
                fclose(fp);
                return 0;
              }
              if(swap) SwapBytes((char *)uv, sizeof(double), 1);
            }
            newVertex = new MEdgeVertex(xyz[0], xyz[1], xyz[2], ge, uv[0], num);
          }
          else if(iClasDim == 2) {
            GFace *gf = getFaceByTag(iClasTag);
            if(!binary) {
              if(fscanf(fp, "%lf %lf", &uv[0], &uv[1]) != 2) {
                fclose(fp);
                return 0;
              }
            }
            else {
              if(fread(uv, sizeof(double), 2, fp) != 2) {
                fclose(fp);
                return 0;
              }
              if(swap) SwapBytes((char *)uv, sizeof(double), 2);
            }
            newVertex =
              new MFaceVertex(xyz[0], xyz[1], xyz[2], gf, uv[0], uv[1], num);
          }
          else if(iClasDim == 3) {
            GRegion *gr = getRegionByTag(iClasTag);
            newVertex = new MVertex(xyz[0], xyz[1], xyz[2], gr, num);
          }
        }
        minVertex = std::min(minVertex, num);
        maxVertex = std::max(maxVertex, num);
        if(vertexMap.count(num))
          Msg::Warning("Skipping duplicate node %d", num);
        vertexMap[num] = newVertex;
        if(numVertices > 100000)
          Msg::ProgressMeter(i + 1, true, "Reading nodes");
      }
      Msg::StopProgressMeter();
      // If the vertex numbering is dense, transfer the map into a
      // vector to speed up element creation
      if((int)vertexMap.size() == numVertices &&
         ((minVertex == 1 && maxVertex == numVertices) ||
          (minVertex == 0 && maxVertex == numVertices - 1))) {
        Msg::Debug("Vertex numbering is dense");
        vertexVector.resize(vertexMap.size() + 1);
        if(minVertex == 1)
          vertexVector[0] = nullptr;
        else
          vertexVector[numVertices] = nullptr;
        for(auto it = vertexMap.begin(); it != vertexMap.end(); ++it)
          vertexVector[it->first] = it->second;
        vertexMap.clear();
      }
    }
    else if(!strncmp(&str[1], "ELM", 3) || !strncmp(&str[1], "Elements", 8)) {
      if(!fgets(str, sizeof(str), fp)) {
        fclose(fp);
        return 0;
      }
      int numElements;

      std::map<int, MElement *> elems;
      std::map<int, MElement *> parents;
      std::map<int, MElement *> domains;
      std::map<int, int> elemreg;
      std::map<int, int> elemphy;

      std::set<MElement *> parentsOwned;
      sscanf(str, "%d", &numElements);
      Msg::Info("%d elements", numElements);
      Msg::StartProgressMeter(numElements);
      if(!binary) {
        for(int i = 0; i < numElements; i++) {
          int num, type, physical = 0, elementary = 0, partition = 0,
                         parent = 0;
          int dom1 = 0, dom2 = 0, numVertices;
          std::vector<short> ghosts;
          if(version <= 1.0) {
            if(fscanf(fp, "%d %d %d %d %d", &num, &type, &physical, &elementary,
                      &numVertices) != 5) {
              fclose(fp);
              return 0;
            }
            if(numVertices != (int)MElement::getInfoMSH(type)) {
              fclose(fp);
              return 0;
            }
          }
          else {
            int numTags;
            if(fscanf(fp, "%d %d %d", &num, &type, &numTags) != 3) {
              fclose(fp);
              return 0;
            }
            int numPartitions = 0;
            for(int j = 0; j < numTags; j++) {
              int tag;
              if(fscanf(fp, "%d", &tag) != 1) {
                fclose(fp);
                return 0;
              }
              if(j == 0)
                physical = tag;
              else if(j == 1)
                elementary = tag;
              else if(version < 2.2 && j == 2)
                partition = tag;
              else if(version >= 2.2 && j == 2 && numTags > 3)
                numPartitions = tag;
              else if(version >= 2.2 && j == 3)
                partition = tag;
              else if(j >= 4 && j < 4 + numPartitions - 1)
                ghosts.push_back(-tag);
              else if(j == 3 + numPartitions && (numTags == 4 + numPartitions))
                parent = tag;
              else if(j == 3 + numPartitions &&
                      (numTags == 5 + numPartitions)) {
                dom1 = tag;
                j++;
                if(fscanf(fp, "%d", &dom2) != 1) {
                  fclose(fp);
                  return 0;
                }
              }
            }
            if(!(numVertices = MElement::getInfoMSH(type))) {
              if(type != MSH_POLYG_ && type != MSH_POLYH_ &&
                 type != MSH_POLYG_B) {
                fclose(fp);
                return 0;
              }
              if(fscanf(fp, "%d", &numVertices) != 1) {
                fclose(fp);
                return 0;
              }
            }
          }
          int *indices = new int[numVertices];
          for(int j = 0; j < numVertices; j++) {
            if(fscanf(fp, "%d", &indices[j]) != 1) {
              delete[] indices;
              fclose(fp);
              return 0;
            }
          }
          std::vector<MVertex *> vertices;
          if(vertexVector.size()) {
            if(!getMeshVertices(numVertices, indices, vertexVector, vertices,
                                minVertex)) {
              delete[] indices;
              fclose(fp);
              return 0;
            }
          }
          else {
            if(!getMeshVertices(numVertices, indices, vertexMap, vertices)) {
              delete[] indices;
              fclose(fp);
              return 0;
            }
          }
          MElement *p = nullptr;
          bool own = false;

          // search parent element
          if(parent != 0) {
            auto ite = elems.find(parent);
            if(ite == elems.end())
              Msg::Error(
                "Parent element (ascii) %d not found for element %d of type %d",
                parent, num, type);
            else {
              p = ite->second;
              parents[parent] = p;
            }
            auto itpo = parentsOwned.find(p);
            if(itpo == parentsOwned.end()) {
              own = true;
              parentsOwned.insert(p);
            }
            assert(p != nullptr);
          }

          // search domains
          MElement *doms[2] = {nullptr, nullptr};
          if(dom1) {
            auto ite = elems.find(dom1);
            if(ite == elems.end())
              Msg::Error("Domain element %d not found for element %d", dom1,
                         num);
            else
              doms[0] = ite->second;

            ite = elems.find(dom2);
            if(ite != elems.end()) doms[1] = ite->second;

            if(!doms[0])
              Msg::Error("Domain element %d not found for element %d", dom1,
                         num);
            if(dom2 && !doms[1])
              Msg::Error("Domain element %d not found for element %d", dom2,
                         num);
          }
          delete[] indices;

          if(elementary < 0) continue;
          MElement *e = createElementMSH2(this, num, type, physical, elementary,
                                          partition, vertices, elements,
                                          physicals, own, p, doms[0], doms[1]);
          elems[num] = e;
          elemreg[num] = elementary;
          elemphy[num] = physical;
          for(std::size_t j = 0; j < ghosts.size(); j++)
            _ghostCells.insert(std::pair<MElement *, short>(e, ghosts[j]));
          if(numElements > 100000)
            Msg::ProgressMeter(i + 1, true, "Reading elements");
        }
      }
      else {
        int numElementsPartial = 0;
        while(numElementsPartial < numElements) {
          int header[3];
          if(fread(header, sizeof(int), 3, fp) != 3) {
            fclose(fp);
            return 0;
          }
          if(swap) SwapBytes((char *)header, sizeof(int), 3);
          int type = header[0];
          int numElms = header[1];
          int numTags = header[2];
          int numVertices = MElement::getInfoMSH(type);
          unsigned int n = 1 + numTags + numVertices;
          int *data = new int[n];
          for(int i = 0; i < numElms; i++) {
            if(fread(data, sizeof(int), n, fp) != n) {
              delete[] data;
              fclose(fp);
              return 0;
            }
            if(swap) SwapBytes((char *)data, sizeof(int), n);
            int num = data[0];
            int physical = (numTags > 0) ? data[1] : 0;
            int elementary = (numTags > 1) ? data[2] : 0;
            int numPartitions = (version >= 2.2 && numTags > 3) ? data[3] : 0;
            int partition = (version < 2.2 && numTags > 2)  ? data[3] :
                            (version >= 2.2 && numTags > 3) ? data[4] :
                                                              0;
            int parent = (version < 2.2 && numTags > 3) ||
                             (version >= 2.2 && numPartitions &&
                              numTags > 3 + numPartitions) ||
                             (version >= 2.2 && !numPartitions && numTags > 2) ?
                           data[numTags] :
                           0;
            int *indices = &data[numTags + 1];
            std::vector<MVertex *> vertices;
            if(vertexVector.size()) {
              if(!getMeshVertices(numVertices, indices, vertexVector, vertices,
                                  minVertex)) {
                delete[] data;
                fclose(fp);
                return 0;
              }
            }
            else {
              if(!getMeshVertices(numVertices, indices, vertexMap, vertices)) {
                delete[] data;
                fclose(fp);
                return 0;
              }
            }
            MElement *p = nullptr;
            bool own = false;
            if(parent) {
              auto ite = elems.find(parent);
              if(ite == elems.end())
                Msg::Error(
                  "Parent (binary) element %d not found for element %d", parent,
                  num);
              else {
                p = ite->second;
                parents[parent] = p;
              }
              auto itpo = parentsOwned.find(p);
              if(itpo == parentsOwned.end()) {
                own = true;
                parentsOwned.insert(p);
              }
              assert(p != nullptr);
            }
            MElement *e = createElementMSH2(this, num, type, physical,
                                            elementary, partition, vertices,
                                            elements, physicals, own, p);
            elems[num] = e;
            elemreg[num] = elementary;
            elemphy[num] = physical;
            if(numPartitions > 1)
              for(int j = 0; j < numPartitions - 1; j++)
                _ghostCells.insert(
                  std::pair<MElement *, short>(e, -data[5 + j]));
            if(numElements > 100000)
              Msg::ProgressMeter(numElementsPartial + i + 1, true,
                                 "Reading elements");
          }
          delete[] data;
          numElementsPartial += numElms;
        }
      }
      Msg::StopProgressMeter();

      for(int i = 0; i < 10; i++) elements[i].clear();

      for(auto ite = elems.begin(); ite != elems.end(); ite++) {
        int num = ite->first;
        MElement *e = ite->second;
        if(parents.find(num) == parents.end()) {
          int reg;
          if(CTX::instance()->mesh.switchElementTags) { reg = elemphy[num]; }
          else {
            reg = elemreg[num];
          }
          switch(e->getType()) {
          case TYPE_PNT: elements[0][reg].push_back(e); break;
          case TYPE_LIN: elements[1][reg].push_back(e); break;
          case TYPE_TRI: elements[2][reg].push_back(e); break;
          case TYPE_QUA: elements[3][reg].push_back(e); break;
          case TYPE_TET: elements[4][reg].push_back(e); break;
          case TYPE_HEX: elements[5][reg].push_back(e); break;
          case TYPE_PRI: elements[6][reg].push_back(e); break;
          case TYPE_PYR: elements[7][reg].push_back(e); break;
          case TYPE_POLYG: elements[8][reg].push_back(e); break;
          case TYPE_POLYH: elements[9][reg].push_back(e); break;
          default:
            Msg::Error("Wrong type of element");
            fclose(fp);
            return 0;
          }
        }
      }
    }
    else if(!strncmp(&str[1], "NodeData", 8)) {
      // there's some nodal post-processing data to read later on, so
      // cache the vertex indexing data
      if(vertexVector.size())
        _vertexVectorCache = vertexVector;
      else
        _vertexMapCache = vertexMap;
      postpro = true;
      break;
    }
    else if(!strncmp(&str[1], "ElementData", 11) ||
            !strncmp(&str[1], "ElementNodeData", 15)) {
      // there's some element post-processing data to read later on
      postpro = true;
      break;
    }

    do {
      if(!fgets(str, sizeof(str), fp) || feof(fp)) break;
    } while(str[0] != '$');
  }

  // store the elements in their associated elementary entity. If the
  // entity does not exist, create a new (discrete) one.
  for(int i = 0; i < (int)(sizeof(elements) / sizeof(elements[0])); i++)
    _storeElementsInEntities(elements[i]);

  // associate the correct geometrical entity with each mesh vertex
  _associateEntityWithMeshVertices();

  // store the vertices in their associated geometrical entity
  if(vertexVector.size())
    _storeVerticesInEntities(vertexVector);
  else
    _storeVerticesInEntities(vertexMap);

  // store the physical tags
  for(int i = 0; i < 4; i++) _storePhysicalTagsInEntities(i, physicals[i]);

  // Reading periodic node information is optional in the MSH2 reader, because
  // the full topology of the model is not stored in MSH2 files. If the full
  // mesh is not saved (e.g. because only volume mesh elements are saved), some
  // or all master/slave (lower dimensional) entities will not have been created
  // when reading the file, which means that no model entities will exist to
  // store the periodic node information.
  if(!CTX::instance()->mesh.ignorePeriodicityMsh2) {
    rewind(fp);

    while(1) {
      while(str[0] != '$') {
        if(!fgets(str, sizeof(str), fp) || feof(fp)) break;
      }
      if(feof(fp)) break;

      if(!strncmp(&str[1], "Periodic", 8) &&
         strncmp(&str[1], "PeriodicNodes", 13)) {
        readMSHPeriodicNodes(fp, this);
        break;
      }
      do {
        if(!fgets(str, sizeof(str), fp) || feof(fp)) break;
      } while(str[0] != '$');
    }
  }

  fclose(fp);

  // this post-processing step for periodic boundaries should be removed from
  // the MSH2 reader. Until then, we also disable it by default.
  if(!CTX::instance()->mesh.ignorePeriodicityMsh2) {
    alignPeriodicBoundaries();
  }

  // attempt to (re)create the model topology
  if(CTX::instance()->mesh.createTopologyMsh2) { createTopologyFromMesh(); }

  // create new partition entities if the mesh is partitioned
  if(CTX::instance()->mesh.partitionConvertMsh2 &&
     getNumPartitions() > oldNumPartitions) {
    convertOldPartitioningToNewOne();
  }

  return postpro ? 2 : 1;
}

template <class T>
static void writeElementMSH(FILE *fp, GModel *model, GEntity *ge, T *ele,
                            bool saveAll, double version, bool binary, int &num,
                            int elementary, std::vector<int> &physicals,
                            int parentNum = 0, int dom1Num = 0, int dom2Num = 0)
{
  if(CTX::instance()->mesh.partitionOldStyleMsh2 && ge->getParentEntity() &&
     ge->getParentEntity()->dim() > ge->dim())
    return; // ignore partition boundaries

  if(CTX::instance()->mesh.partitionOldStyleMsh2 &&
     (ge->geomType() == GEntity::GhostCurve ||
      ge->geomType() == GEntity::GhostSurface ||
      ge->geomType() == GEntity::GhostVolume))
    return; // ignore ghost entities

  std::vector<short> ghosts;
  if(model->getGhostCells().size()) {
    auto itp = model->getGhostCells().equal_range(ele);
    for(auto it = itp.first; it != itp.second; it++)
      ghosts.push_back(it->second);
  }

  if(saveAll)
    ele->writeMSH2(fp, version, binary, ++num, elementary, 0, parentNum,
                   dom1Num, dom2Num, &ghosts);
  else {
    if(parentNum) parentNum = parentNum - physicals.size() + 1;
    for(std::size_t j = 0; j < physicals.size(); j++) {
      ele->writeMSH2(fp, version, binary, ++num, elementary, physicals[j],
                     parentNum, dom1Num, dom2Num, &ghosts);
      if(parentNum) parentNum++;
    }
  }

  model->setMeshElementIndex(ele, num); // should really be a multimap...

  if(CTX::instance()->mesh.saveTri && ele->getNumChildren())
    num += ele->getNumChildren() - 1;
}

template <class T>
static void writeElementsMSH(FILE *fp, GModel *model, GEntity *ge,
                             std::vector<T *> &ele, bool saveAll,
                             int saveSinglePartition, double version,
                             bool binary, int &num, int elementary,
                             std::vector<int> &physicals)
{
  if(CTX::instance()->mesh.partitionOldStyleMsh2 && ge->getParentEntity() &&
     ge->getParentEntity()->dim() > ge->dim())
    return; // ignore partition boundaries

  if(CTX::instance()->mesh.partitionOldStyleMsh2 &&
     (ge->geomType() == GEntity::GhostCurve ||
      ge->geomType() == GEntity::GhostSurface ||
      ge->geomType() == GEntity::GhostVolume))
    return; // ignore ghost entities

  // Hack to save each partition as a separate physical entity
  if(saveSinglePartition < 0) {
    if(ele.empty()) return;
    int offset = -saveSinglePartition;
    int maxPhysical = model->getMaxPhysicalNumber(ele[0]->getDim());
    for(std::size_t i = 0; i < ele.size(); i++) {
      std::vector<int> newPhysicals;
      int newElementary = elementary;
      if(elementary > 0) { // classical entity
        newElementary = elementary * offset + ele[i]->getPartition();
        for(std::size_t j = 0; j < physicals.size(); j++)
          newPhysicals.push_back(physicals[j] * offset +
                                 ele[i]->getPartition());
      }
      else if(elementary < 0) { // partition boundary
        newPhysicals.push_back((maxPhysical - elementary) * offset);
      }
      ele[i]->setPartition(0);
      writeElementMSH(fp, model, ge, ele[i], saveAll, version, binary, num,
                      newElementary, newPhysicals);
    }
    return;
  }

  for(std::size_t i = 0; i < ele.size(); i++) {
    if(saveSinglePartition && ele[i]->getPartition() != saveSinglePartition)
      continue;
    if(ele[i]->getDomain(0)) continue;
    int parentNum = 0;
    MElement *parent = ele[i]->getParent();
    if(parent) parentNum = model->getMeshElementIndex(parent);
    writeElementMSH(fp, model, ge, ele[i], saveAll, version, binary, num,
                    elementary, physicals, parentNum);
  }
}

static int getNumElementsMSH(GEntity *ge, bool saveAll, int saveSinglePartition)
{
  if(CTX::instance()->mesh.partitionOldStyleMsh2 && ge->getParentEntity() &&
     ge->getParentEntity()->dim() > ge->dim())
    return 0; // ignore partition boundaries

  if(CTX::instance()->mesh.partitionOldStyleMsh2 &&
     (ge->geomType() == GEntity::GhostCurve ||
      ge->geomType() == GEntity::GhostSurface ||
      ge->geomType() == GEntity::GhostVolume))
    return 0; // ignore ghost entities

  int n = 0, p = saveAll ? 1 : ge->physicals.size();

  if(saveSinglePartition < 0 && ge->tag() < 0) p = 1; // partition boundary

  if(saveSinglePartition <= 0)
    n = p * ge->getNumMeshElements();
  else
    for(std::size_t i = 0; i < ge->getNumMeshElements(); i++)
      if(ge->getMeshElement(i)->getPartition() == saveSinglePartition) n += p;
  return n;
}

static int getNumElementsMSH(GModel *m, bool saveAll, int saveSinglePartition)
{
  int n = 0;
  for(auto it = m->firstVertex(); it != m->lastVertex(); ++it) {
    n += getNumElementsMSH(*it, saveAll, saveSinglePartition);
    if(!CTX::instance()->mesh.saveTri) {
      for(std::size_t i = 0; i < (*it)->points.size(); i++)
        if((*it)->points[i]->ownsParent())
          n += (saveAll ? 1 : (*it)->physicals.size());
    }
  }
  for(auto it = m->firstEdge(); it != m->lastEdge(); ++it) {
    n += getNumElementsMSH(*it, saveAll, saveSinglePartition);
    if(!CTX::instance()->mesh.saveTri) {
      for(std::size_t i = 0; i < (*it)->lines.size(); i++)
        if((*it)->lines[i]->ownsParent())
          n += (saveAll ? 1 : (*it)->physicals.size());
    }
  }
  for(auto it = m->firstFace(); it != m->lastFace(); ++it) {
    n += getNumElementsMSH(*it, saveAll, saveSinglePartition);
    if(CTX::instance()->mesh.saveTri) {
      for(std::size_t i = 0; i < (*it)->polygons.size(); i++) {
        int nbC = (*it)->polygons[i]->getNumChildren() - 1;
        n += (saveAll ? nbC : nbC * (*it)->physicals.size());
      }
    }
    else {
      for(std::size_t i = 0; i < (*it)->triangles.size(); i++)
        if((*it)->triangles[i]->ownsParent())
          n += (saveAll ? 1 : (*it)->physicals.size());
      for(std::size_t i = 0; i < (*it)->polygons.size(); i++)
        if((*it)->polygons[i]->ownsParent())
          n += (saveAll ? 1 : (*it)->physicals.size());
    }
  }
  for(auto it = m->firstRegion(); it != m->lastRegion(); ++it) {
    n += getNumElementsMSH(*it, saveAll, saveSinglePartition);
    if(CTX::instance()->mesh.saveTri) {
      for(std::size_t i = 0; i < (*it)->polyhedra.size(); i++) {
        int nbC = (*it)->polyhedra[i]->getNumChildren() - 1;
        n += (saveAll ? nbC : nbC * (*it)->physicals.size());
      }
    }
    else {
      for(std::size_t i = 0; i < (*it)->tetrahedra.size(); i++)
        if((*it)->tetrahedra[i]->ownsParent())
          n += (saveAll ? 1 : (*it)->physicals.size());
      for(std::size_t i = 0; i < (*it)->polyhedra.size(); i++)
        if((*it)->polyhedra[i]->ownsParent())
          n += (saveAll ? 1 : (*it)->physicals.size());
    }
    n -= (*it)->trihedra.size();
  }
  return n;
}

static int _getElementary(GEntity *ge)
{
  if(CTX::instance()->mesh.partitionOldStyleMsh2 && ge->getParentEntity() &&
     ge->getParentEntity()->dim() == ge->dim()) {
    // hack for backward compatibility of partitioned meshes in MSH2 format: use
    // elementary tag of parent entity if they are of the same dimension
    // (i.e. if they are not partition boundaries)
    return ge->getParentEntity()->tag();
  }
  else {
    return ge->tag();
  }
}

int GModel::_writeMSH2(const std::string &name, double version, bool binary,
                       bool saveAll, bool saveParametric, double scalingFactor,
                       int elementStartNum, int saveSinglePartition,
                       bool append, bool renumberVertices)
{
  FILE *fp;
  if(append)
    fp = Fopen(name.c_str(), binary ? "ab" : "a");
  else
    fp = Fopen(name.c_str(), binary ? "wb" : "w");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  // binary format exists only in version 2
  if(version > 1 || binary)
    version = 2.2;
  else
    version = 1.0;

  // if there are no physicals we save all the elements
  if(noPhysicalGroups()) saveAll = true;

  // get the number of vertices and index the vertices in a continuous
  // sequence

  int numVertices =
    indexMeshVertices(saveAll, saveSinglePartition, renumberVertices);

  // get the number of elements we need to save
  int numElements = getNumElementsMSH(this, saveAll, saveSinglePartition);

  if(version >= 2.0) {
    fprintf(fp, "$MeshFormat\n");
    fprintf(fp, "%g %d %d\n", version, binary ? 1 : 0, (int)sizeof(double));
    if(binary) {
      int one = 1;
      fwrite(&one, sizeof(int), 1, fp);
      fprintf(fp, "\n");
    }
    fprintf(fp, "$EndMeshFormat\n");

    if(numPhysicalNames()) {
      fprintf(fp, "$PhysicalNames\n");
      fprintf(fp, "%d\n", numPhysicalNames());
      for(auto it = firstPhysicalName(); it != lastPhysicalName(); it++) {
        std::string name = it->second;
        if(name.size() > 128) name.resize(128);
        fprintf(fp, "%d %d \"%s\"\n", it->first.first, it->first.second,
                name.c_str());
      }
      fprintf(fp, "$EndPhysicalNames\n");
    }

    if(CTX::instance()->mesh.saveTopology) writeMSHEntities(fp, this);

    if(saveParametric)
      fprintf(fp, "$ParametricNodes\n");
    else
      fprintf(fp, "$Nodes\n");
  }
  else
    fprintf(fp, "$NOD\n");

  fprintf(fp, "%d\n", numVertices);

  std::vector<GEntity *> entities;
  getEntities(entities);
  for(std::size_t i = 0; i < entities.size(); i++)
    for(std::size_t j = 0; j < entities[i]->mesh_vertices.size(); j++)
      entities[i]->mesh_vertices[j]->writeMSH2(fp, binary, saveParametric,
                                               scalingFactor);

  if(binary) fprintf(fp, "\n");

  if(version >= 2.0) {
    if(saveParametric)
      fprintf(fp, "$EndParametricNodes\n");
    else
      fprintf(fp, "$EndNodes\n");
    fprintf(fp, "$Elements\n");
  }
  else {
    fprintf(fp, "$ENDNOD\n");
    fprintf(fp, "$ELM\n");
  }

  fprintf(fp, "%d\n", numElements);
  int num = elementStartNum;

  _elementIndexCache.clear();

  // parents
  if(!CTX::instance()->mesh.saveTri) {
    for(auto it = firstVertex(); it != lastVertex(); ++it) {
      for(std::size_t i = 0; i < (*it)->points.size(); i++)
        if((*it)->points[i]->ownsParent())
          writeElementMSH(fp, this, *it, (*it)->points[i]->getParent(), saveAll,
                          version, binary, num, _getElementary(*it),
                          (*it)->physicals);
    }
    for(auto it = firstEdge(); it != lastEdge(); ++it) {
      for(std::size_t i = 0; i < (*it)->lines.size(); i++)
        if((*it)->lines[i]->ownsParent())
          writeElementMSH(fp, this, *it, (*it)->lines[i]->getParent(), saveAll,
                          version, binary, num, _getElementary(*it),
                          (*it)->physicals);
    }
    for(auto it = firstFace(); it != lastFace(); ++it) {
      for(std::size_t i = 0; i < (*it)->triangles.size(); i++)
        if((*it)->triangles[i]->ownsParent())
          writeElementMSH(fp, this, *it, (*it)->triangles[i]->getParent(),
                          saveAll, version, binary, num, _getElementary(*it),
                          (*it)->physicals);
    }
    for(auto it = firstRegion(); it != lastRegion(); ++it) {
      for(std::size_t i = 0; i < (*it)->tetrahedra.size(); i++)
        if((*it)->tetrahedra[i]->ownsParent())
          writeElementMSH(fp, this, *it, (*it)->tetrahedra[i]->getParent(),
                          saveAll, version, binary, num, _getElementary(*it),
                          (*it)->physicals);
    }
    for(auto it = firstFace(); it != lastFace(); ++it) {
      for(std::size_t i = 0; i < (*it)->polygons.size(); i++)
        if((*it)->polygons[i]->ownsParent())
          writeElementMSH(fp, this, *it, (*it)->polygons[i]->getParent(),
                          saveAll, version, binary, num, _getElementary(*it),
                          (*it)->physicals);
    }
    for(auto it = firstRegion(); it != lastRegion(); ++it) {
      for(std::size_t i = 0; i < (*it)->polyhedra.size(); i++)
        if((*it)->polyhedra[i]->ownsParent())
          writeElementMSH(fp, this, *it, (*it)->polyhedra[i]->getParent(),
                          saveAll, version, binary, num, _getElementary(*it),
                          (*it)->physicals);
    }
  }
  // points
  for(auto it = firstVertex(); it != lastVertex(); ++it) {
    writeElementsMSH(fp, this, *it, (*it)->points, saveAll, saveSinglePartition,
                     version, binary, num, _getElementary(*it),
                     (*it)->physicals);
  }
  // lines
  for(auto it = firstEdge(); it != lastEdge(); ++it) {
    writeElementsMSH(fp, this, *it, (*it)->lines, saveAll, saveSinglePartition,
                     version, binary, num, _getElementary(*it),
                     (*it)->physicals);
  }
  // triangles
  for(auto it = firstFace(); it != lastFace(); ++it) {
    writeElementsMSH(fp, this, *it, (*it)->triangles, saveAll,
                     saveSinglePartition, version, binary, num,
                     _getElementary(*it), (*it)->physicals);
  }
  // quads
  for(auto it = firstFace(); it != lastFace(); ++it) {
    writeElementsMSH(fp, this, *it, (*it)->quadrangles, saveAll,
                     saveSinglePartition, version, binary, num,
                     _getElementary(*it), (*it)->physicals);
  }
  // polygons
  for(auto it = firstFace(); it != lastFace(); it++) {
    writeElementsMSH(fp, this, *it, (*it)->polygons, saveAll,
                     saveSinglePartition, version, binary, num,
                     _getElementary(*it), (*it)->physicals);
  }
  // tets
  for(auto it = firstRegion(); it != lastRegion(); ++it) {
    writeElementsMSH(fp, this, *it, (*it)->tetrahedra, saveAll,
                     saveSinglePartition, version, binary, num,
                     _getElementary(*it), (*it)->physicals);
  }
  // hexas
  for(auto it = firstRegion(); it != lastRegion(); ++it) {
    writeElementsMSH(fp, this, *it, (*it)->hexahedra, saveAll,
                     saveSinglePartition, version, binary, num,
                     _getElementary(*it), (*it)->physicals);
  }
  // prisms
  for(auto it = firstRegion(); it != lastRegion(); ++it) {
    writeElementsMSH(fp, this, *it, (*it)->prisms, saveAll, saveSinglePartition,
                     version, binary, num, _getElementary(*it),
                     (*it)->physicals);
  }
  // pyramids
  for(auto it = firstRegion(); it != lastRegion(); ++it) {
    writeElementsMSH(fp, this, *it, (*it)->pyramids, saveAll,
                     saveSinglePartition, version, binary, num,
                     _getElementary(*it), (*it)->physicals);
  }
  // polyhedra
  for(auto it = firstRegion(); it != lastRegion(); ++it) {
    writeElementsMSH(fp, this, *it, (*it)->polyhedra, saveAll,
                     saveSinglePartition, version, binary, num,
                     _getElementary(*it), (*it)->physicals);
  }
  // level set faces
  for(auto it = firstFace(); it != lastFace(); ++it) {
    for(std::size_t i = 0; i < (*it)->triangles.size(); i++) {
      MTriangle *t = (*it)->triangles[i];
      if(t->getDomain(0))
        writeElementMSH(fp, this, *it, t, saveAll, version, binary, num,
                        _getElementary(*it), (*it)->physicals, 0,
                        getMeshElementIndex(t->getDomain(0)),
                        getMeshElementIndex(t->getDomain(1)));
    }
    for(std::size_t i = 0; i < (*it)->polygons.size(); i++) {
      MPolygon *p = (*it)->polygons[i];
      if(p->getDomain(0))
        writeElementMSH(fp, this, *it, p, saveAll, version, binary, num,
                        _getElementary(*it), (*it)->physicals, 0,
                        getMeshElementIndex(p->getDomain(0)),
                        getMeshElementIndex(p->getDomain(1)));
    }
  }
  // level set lines
  for(auto it = firstEdge(); it != lastEdge(); ++it) {
    for(std::size_t i = 0; i < (*it)->lines.size(); i++) {
      MLine *l = (*it)->lines[i];
      if(l->getDomain(0))
        writeElementMSH(fp, this, *it, l, saveAll, version, binary, num,
                        _getElementary(*it), (*it)->physicals, 0,
                        getMeshElementIndex(l->getDomain(0)),
                        getMeshElementIndex(l->getDomain(1)));
    }
  }

  if(binary) fprintf(fp, "\n");

  if(version >= 2.0) { fprintf(fp, "$EndElements\n"); }
  else {
    fprintf(fp, "$ENDELM\n");
  }

  writeMSHPeriodicNodes(fp, entities, renumberVertices, saveAll);

  fclose(fp);

  return 1;
}

int GModel::_writePartitionedMSH2(const std::string &baseName, bool binary,
                                  bool saveAll, bool saveParametric,
                                  double scalingFactor)
{
  int numElements;
  int startNum = 0;
  for(std::size_t partition = 1; partition <= getNumPartitions(); partition++) {
    std::ostringstream sstream;
    sstream << baseName << "_" << partition << ".msh";

    numElements = getNumElementsMSH(this, saveAll, partition);
    Msg::Info("Writing partition %d in file '%s'", partition,
              sstream.str().c_str());
    _writeMSH2(sstream.str(), 2.2, binary, saveAll, saveParametric,
               scalingFactor, startNum, partition, false,
               false); // NO RENUMBERING!
    startNum += numElements; // update for next iteration in the loop
  }

#if 0
  if(_ghostCells.size()){
    Msg::Info("Writing ghost cells in debug file 'ghosts.pos'");
    FILE *fp = Fopen("ghosts.pos", "w");
    fprintf(fp, "View \"ghosts\"{\n");
    for(auto it = _ghostCells.begin(); it != _ghostCells.end(); it++)
      it->first->writePOS(fp, false, true, false, false, false, false);
    fprintf(fp, "};\n");
    fclose(fp);
  }
#endif

  return 1;
}
