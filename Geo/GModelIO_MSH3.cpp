// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <sstream>
#include <iomanip>
#include <ctime>
#include "GModel.h"
#include "OS.h"
#include "Context.h"
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
#include "MTrihedron.h"
#include "StringUtils.h"
#include "discreteVertex.h"
#include "discreteEdge.h"
#include "discreteFace.h"
#include "discreteRegion.h"

static int readMSHPhysicals(FILE *fp, GEntity *ge)
{
  int nump;
  if(fscanf(fp, "%d", &nump) != 1) return 0;
  for(int i = 0; i < nump; i++) {
    int tag;
    if(fscanf(fp, "%d", &tag) != 1) return 0;
    ge->physicals.push_back(tag);
  }
  return 1;
}

static void readMSHEntities(FILE *fp, GModel *gm)
{
  int nv, ne, nf, nr;
  int tag;
  if(fscanf(fp, "%d %d %d %d", &nv, &ne, &nf, &nr) != 4) return;
  for(int i = 0; i < nv; i++) {
    if(fscanf(fp, "%d", &tag) != 1) return;
    GVertex *gv = gm->getVertexByTag(tag);
    if(!gv) {
      gv = new discreteVertex(gm, tag);
      gm->add(gv);
    }
    if(!readMSHPhysicals(fp, gv)) return;
  }
  for(int i = 0; i < ne; i++) {
    int n;
    if(fscanf(fp, "%d %d", &tag, &n) != 2) return;
    GEdge *ge = gm->getEdgeByTag(tag);
    if(!ge) {
      GVertex *v1 = nullptr, *v2 = nullptr;
      for(int j = 0; j < n; j++) {
        int tagv;
        if(fscanf(fp, "%d", &tagv) != 1) {
          delete ge;
          return;
        }
        GVertex *v = gm->getVertexByTag(tagv);
        if(!v) Msg::Error("Unknown GVertex %d", tagv);
        if(j == 0) v1 = v;
        if(j == 1) v2 = v;
      }
      ge = new discreteEdge(gm, tag, v1, v2);
      gm->add(ge);
    }
    if(!readMSHPhysicals(fp, ge)) return;
  }
  for(int i = 0; i < nf; i++) {
    int n;
    if(fscanf(fp, "%d %d", &tag, &n) != 2) return;
    GFace *gf = gm->getFaceByTag(tag);
    if(!gf) {
      discreteFace *df = new discreteFace(gm, tag);
      std::vector<int> edges, signs;
      for(int j = 0; j < n; j++) {
        int tage;
        if(fscanf(fp, "%d", &tage) != 1) {
          delete df;
          return;
        }
        edges.push_back(std::abs(tage));
        int sign = tage > 0 ? 1 : -1;
        signs.push_back(sign);
      }
      df->setBoundEdges(edges, signs);
      gm->add(df);
      gf = df;
    }
    if(!readMSHPhysicals(fp, gf)) return;
  }
  for(int i = 0; i < nr; i++) {
    int n;
    if(fscanf(fp, "%d %d", &tag, &n) != 2) return;
    GRegion *gr = gm->getRegionByTag(tag);
    if(!gr) {
      discreteRegion *dr = new discreteRegion(gm, tag);
      std::vector<int> faces, signs;
      for(int j = 0; j < n; j++) {
        int tagf;
        if(fscanf(fp, "%d", &tagf) != 1) {
          delete dr;
          return;
        }
        faces.push_back(std::abs(tagf));
        int sign = tagf > 0 ? 1 : -1;
        signs.push_back(sign);
      }
      dr->setBoundFaces(faces, signs);
      gm->add(dr);
      gr = dr;
    }
    if(!readMSHPhysicals(fp, gr)) return;
  }
}

void readMSHPeriodicNodes(FILE *fp, GModel *gm) // also used in MSH2
{
  int count;
  if(fscanf(fp, "%d", &count) != 1) return;
  for(int i = 0; i < count; i++) {
    int dim, slave, master;

    if(fscanf(fp, "%d %d %d", &dim, &slave, &master) != 3) continue;

    GEntity *s = nullptr, *m = nullptr;
    switch(dim) {
    case 0:
      s = gm->getVertexByTag(slave);
      m = gm->getVertexByTag(master);
      break;
    case 1:
      s = gm->getEdgeByTag(slave);
      m = gm->getEdgeByTag(master);
      break;
    case 2:
      s = gm->getFaceByTag(slave);
      m = gm->getFaceByTag(master);
      break;
    }

    // we need to continue parsing, otherwise we end up reading on the wrong
    // position

    bool completePer = s && m;

    char token[7];
    fpos_t pos;
    fgetpos(fp, &pos);
    if(fscanf(fp, "%s", token) != 1) return;
    if(strcmp(token, "Affine") == 0) {
      std::vector<double> tfo(16);
      for(int i = 0; i < 16; i++) {
        if(fscanf(fp, "%lf", &tfo[i]) != 1) return;
      }
      if(completePer) s->setMeshMaster(m, tfo);
    }
    else {
      fsetpos(fp, &pos);
      if(completePer) s->setMeshMaster(m);
    }
    int numv;
    if(fscanf(fp, "%d", &numv) != 1) numv = 0;
    for(int j = 0; j < numv; j++) {
      int v1, v2;
      if(fscanf(fp, "%d %d", &v1, &v2) != 2) continue;
      MVertex *mv1 = gm->getMeshVertexByTag(v1);
      MVertex *mv2 = gm->getMeshVertexByTag(v2);
      if(completePer) s->correspondingVertices[mv1] = mv2;
    }
    if(!completePer) {
      if(!s)
        Msg::Info("Could not find periodic slave entity %d of dimension %d",
                  slave, dim);
      if(!m)
        Msg::Info("Could not find periodic master entity %d of dimension %d",
                  master, dim);
    }
  }
}

int GModel::_readMSH3(const std::string &name)
{
  FILE *fp = Fopen(name.c_str(), "rb");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  char str[256] = "";
  double version = 0.;
  bool binary = false, swap = false, postpro = false;
  int minVertex = 0;
  std::map<int, std::vector<MElement *> > elements[11];
  std::size_t oldNumPartitions = getNumPartitions();

  while(1) {
    while(str[0] != '$') {
      if(!fgets(str, sizeof(str), fp) || feof(fp)) break;
    }

    if(feof(fp)) break;

    // $MeshFormat section
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
      if(version < 3. || version >= 4.) {
        Msg::Error("Wrong MSH file version %g for MSH3 reader", version);
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

    // $PhysicalNames section
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
        int dim, num;
        if(fscanf(fp, "%d", &dim) != 1) {
          fclose(fp);
          return 0;
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

    // $Entities section
    else if(!strncmp(&str[1], "Entities", 8)) {
      readMSHEntities(fp, this);
    }

    // $Nodes section
    else if(!strncmp(&str[1], "Nodes", 5)) {
      if(!fgets(str, sizeof(str), fp)) {
        fclose(fp);
        return 0;
      }
      int numVertices;
      if(sscanf(str, "%d", &numVertices) != 1) {
        fclose(fp);
        return 0;
      }
      Msg::Info("%d nodes", numVertices);
      Msg::StartProgressMeter(numVertices);
      _vertexMapCache.clear();
      _vertexVectorCache.clear();
      int maxVertex = -1;
      minVertex = numVertices + 1;
      for(int i = 0; i < numVertices; i++) {
        int num, entity, dim;
        double xyz[3];
        MVertex *vertex = nullptr;
        if(!binary) {
          if(fscanf(fp, "%d %lf %lf %lf %d", &num, &xyz[0], &xyz[1], &xyz[2],
                    &entity) != 5) {
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
          if(fread(&entity, sizeof(int), 1, fp) != 1) {
            fclose(fp);
            return 0;
          }
          if(swap) SwapBytes((char *)&entity, sizeof(int), 1);
        }
        if(!entity) {
          vertex = new MVertex(xyz[0], xyz[1], xyz[2], nullptr, num);
        }
        else {
          if(!binary) {
            if(fscanf(fp, "%d", &dim) != 1) {
              fclose(fp);
              return 0;
            }
          }
          else {
            if(fread(&dim, sizeof(int), 1, fp) != 1) {
              fclose(fp);
              return 0;
            }
            if(swap) SwapBytes((char *)&dim, sizeof(int), 1);
          }
          switch(dim) {
          case 0: {
            GVertex *gv = getVertexByTag(entity);
            // FIXME -- cannot call this: it destroys _vertexMapCache
            // if(gv) gv->deleteMesh();
            vertex = new MVertex(xyz[0], xyz[1], xyz[2], gv, num);
          } break;
          case 1: {
            GEdge *ge = getEdgeByTag(entity);
            double u;
            if(!binary) {
              if(fscanf(fp, "%lf", &u) != 1) {
                fclose(fp);
                return 0;
              }
            }
            else {
              if(fread(&u, sizeof(double), 1, fp) != 1) {
                fclose(fp);
                return 0;
              }
              if(swap) SwapBytes((char *)&u, sizeof(double), 1);
            }
            vertex = new MEdgeVertex(xyz[0], xyz[1], xyz[2], ge, u, num);
          } break;
          case 2: {
            GFace *gf = getFaceByTag(entity);
            double uv[2];
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
            vertex =
              new MFaceVertex(xyz[0], xyz[1], xyz[2], gf, uv[0], uv[1], num);
          } break;
          case 3: {
            GRegion *gr = getRegionByTag(entity);
            double uvw[3];
            if(!binary) {
              if(fscanf(fp, "%lf %lf %lf", &uvw[0], &uvw[1], &uvw[2]) != 3) {
                fclose(fp);
                return 0;
              }
            }
            else {
              if(fread(uvw, sizeof(double), 3, fp) != 3) {
                fclose(fp);
                return 0;
              }
              if(swap) SwapBytes((char *)uvw, sizeof(double), 3);
            }
            vertex = new MVertex(xyz[0], xyz[1], xyz[2], gr, num);
          } break;
          default:
            Msg::Error("Wrong entity dimension for node %d", num);
            fclose(fp);
            return 0;
          }
        }
        minVertex = std::min(minVertex, num);
        maxVertex = std::max(maxVertex, num);
        if(_vertexMapCache.count(num))
          Msg::Warning("Skipping duplicate node %d", num);
        _vertexMapCache[num] = vertex;
        if(numVertices > 100000)
          Msg::ProgressMeter(i + 1, true, "Reading nodes");
      }
      Msg::StopProgressMeter();
      // if the vertex numbering is dense, transfer the map into a vector to
      // speed up element creation
      if((int)_vertexMapCache.size() == numVertices &&
         ((minVertex == 1 && maxVertex == numVertices) ||
          (minVertex == 0 && maxVertex == numVertices - 1))) {
        Msg::Debug("Vertex numbering is dense");
        _vertexVectorCache.resize(_vertexMapCache.size() + 1);
        if(minVertex == 1)
          _vertexVectorCache[0] = nullptr;
        else
          _vertexVectorCache[numVertices] = nullptr;
        for(auto it = _vertexMapCache.begin(); it != _vertexMapCache.end(); ++it)
          _vertexVectorCache[it->first] = it->second;
        _vertexMapCache.clear();
      }
    }

    // $Elements section
    else if(!strncmp(&str[1], "Elements", 8)) {
      if(!fgets(str, sizeof(str), fp)) {
        fclose(fp);
        return 0;
      }
      int numElements;
      if(sscanf(str, "%d", &numElements) != 1) {
        fclose(fp);
        return 0;
      }
      Msg::Info("%d elements", numElements);
      Msg::StartProgressMeter(numElements);
      for(int i = 0; i < numElements; i++) {
        int num, type, entity, numData;
        if(!binary) {
          if(fscanf(fp, "%d %d %d %d", &num, &type, &entity, &numData) != 4) {
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
          if(fread(&type, sizeof(int), 1, fp) != 1) {
            fclose(fp);
            return 0;
          }
          if(swap) SwapBytes((char *)&type, sizeof(int), 1);
          if(fread(&entity, sizeof(int), 1, fp) != 1) {
            fclose(fp);
            return 0;
          }
          if(swap) SwapBytes((char *)&entity, sizeof(int), 1);
          if(fread(&numData, sizeof(int), 1, fp) != 1) {
            fclose(fp);
            return 0;
          }
          if(swap) SwapBytes((char *)&numData, sizeof(int), 1);
        }
        std::vector<int> data;
        if(numData > 0) {
          data.resize(numData);
          if(!binary) {
            for(int j = 0; j < numData; j++) {
              if(fscanf(fp, "%d", &data[j]) != 1) {
                fclose(fp);
                return 0;
              }
            }
          }
          else {
            if((int)fread(&data[0], sizeof(int), numData, fp) != numData) {
              fclose(fp);
              return 0;
            }
            if(swap) SwapBytes((char *)&data[0], sizeof(int), numData);
          }
        }
        MElementFactory f;
        MElement *element = f.create(num, type, data, this);
        if(!element) {
          fclose(fp);
          return 0;
        }
        switch(element->getType()) {
        case TYPE_PNT: elements[0][entity].push_back(element); break;
        case TYPE_LIN: elements[1][entity].push_back(element); break;
        case TYPE_TRI: elements[2][entity].push_back(element); break;
        case TYPE_QUA: elements[3][entity].push_back(element); break;
        case TYPE_TET: elements[4][entity].push_back(element); break;
        case TYPE_HEX: elements[5][entity].push_back(element); break;
        case TYPE_PRI: elements[6][entity].push_back(element); break;
        case TYPE_PYR: elements[7][entity].push_back(element); break;
        case TYPE_TRIH: elements[8][entity].push_back(element); break;
        case TYPE_POLYG: elements[9][entity].push_back(element); break;
        case TYPE_POLYH: elements[10][entity].push_back(element); break;
        }
        if(numElements > 100000)
          Msg::ProgressMeter(i + 1, true, "Reading elements");
      }
      Msg::StopProgressMeter();
    }

    // $Periodical section
    else if(!strncmp(&str[1], "Periodic", 8)) {
      readMSHPeriodicNodes(fp, this);
    }

    // Post-processing sections
    else if(!strncmp(&str[1], "NodeData", 8) ||
            !strncmp(&str[1], "ElementData", 11) ||
            !strncmp(&str[1], "ElementNodeData", 15)) {
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
  if(_vertexVectorCache.size())
    _storeVerticesInEntities(_vertexVectorCache);
  else
    _storeVerticesInEntities(_vertexMapCache);

  for(int i = 0; i < (int)(sizeof(elements) / sizeof(elements[0])); i++)
    _storeParentsInSubElements(elements[i]);

  fclose(fp);

  // create new partition entities if the mesh is partitioned
  if(CTX::instance()->mesh.partitionConvertMsh2 &&
     getNumPartitions() > oldNumPartitions)
    convertOldPartitioningToNewOne();

  return postpro ? 2 : 1;
}

static void writeMSHPhysicals(FILE *fp, GEntity *ge)
{
  std::vector<int> phys = ge->physicals;
  fprintf(fp, "%d ", (int)phys.size());
  for(auto itp = phys.begin(); itp != phys.end(); itp++)
    fprintf(fp, "%d ", *itp);
}

void writeMSHEntities(FILE *fp, GModel *gm) // also used in MSH2
{
  fprintf(fp, "$Entities\n");
  fprintf(fp, "%lu %lu %lu %lu\n", gm->getNumVertices(), gm->getNumEdges(),
          gm->getNumFaces(), gm->getNumRegions());
  for(auto it = gm->firstVertex(); it != gm->lastVertex(); ++it) {
    fprintf(fp, "%d ", (*it)->tag());
    writeMSHPhysicals(fp, *it);
    fprintf(fp, "\n");
  }
  for(auto it = gm->firstEdge(); it != gm->lastEdge(); ++it) {
    std::list<GVertex *> vertices;
    if((*it)->getBeginVertex()) vertices.push_back((*it)->getBeginVertex());
    if((*it)->getEndVertex()) vertices.push_back((*it)->getEndVertex());
    fprintf(fp, "%d %d ", (*it)->tag(), (int)vertices.size());
    for(auto itv = vertices.begin(); itv != vertices.end(); itv++) {
      fprintf(fp, "%d ", (*itv)->tag());
    }
    writeMSHPhysicals(fp, *it);
    fprintf(fp, "\n");
  }
  for(auto it = gm->firstFace(); it != gm->lastFace(); ++it) {
    std::vector<GEdge *> const &edges = (*it)->edges();
    std::vector<int> const &ori = (*it)->edgeOrientations();
    fprintf(fp, "%d %d ", (*it)->tag(), (int)edges.size());
    std::vector<int> tags;
    for(auto ite = edges.begin(); ite != edges.end(); ite++)
      tags.push_back((*ite)->tag());

    std::vector<int> signs(ori.begin(), ori.end());

    if(tags.size() == signs.size()) {
      for(std::size_t i = 0; i < tags.size(); i++)
        tags[i] *= (signs[i] > 0 ? 1 : -1);
    }
    for(std::size_t i = 0; i < tags.size(); i++) fprintf(fp, "%d ", tags[i]);
    writeMSHPhysicals(fp, *it);
    fprintf(fp, "\n");
  }
  for(auto it = gm->firstRegion(); it != gm->lastRegion(); ++it) {
    std::vector<GFace *> faces = (*it)->faces();
    std::vector<int> ori = (*it)->faceOrientations();
    fprintf(fp, "%d %d ", (*it)->tag(), (int)faces.size());
    std::vector<int> tags, signs;
    for(auto itf = faces.begin(); itf != faces.end(); itf++)
      tags.push_back((*itf)->tag());
    for(auto itf = ori.begin(); itf != ori.end(); itf++)
      signs.push_back(*itf);
    if(tags.size() == signs.size()) {
      for(std::size_t i = 0; i < tags.size(); i++)
        tags[i] *= (signs[i] > 0 ? 1 : -1);
    }
    for(std::size_t i = 0; i < tags.size(); i++) fprintf(fp, "%d ", tags[i]);
    writeMSHPhysicals(fp, *it);
    fprintf(fp, "\n");
  }
  fprintf(fp, "$EndEntities\n");
}

static int getNumElementsMSH(GEntity *ge, bool saveAll, int saveSinglePartition)
{
  int n = 0;
  if(saveAll || ge->physicals.size()) {
    if(saveSinglePartition <= 0)
      n = ge->getNumMeshElements();
    else
      for(std::size_t i = 0; i < ge->getNumMeshElements(); i++)
        if(ge->getMeshElement(i)->getPartition() == saveSinglePartition) n++;
  }
  return n;
}

static void writeElementMSH(FILE *fp, GModel *model, MElement *ele, bool binary,
                            int elementary)
{
  if(model->getGhostCells().size()) {
    std::vector<short> ghosts;
    auto itp = model->getGhostCells().equal_range(ele);
    for(auto it = itp.first; it != itp.second; it++)
      ghosts.push_back(it->second);
    ele->writeMSH3(fp, binary, elementary, &ghosts);
  }
  else
    ele->writeMSH3(fp, binary, elementary);
}

template <class T>
static void writeElementsMSH(FILE *fp, GModel *model, GEntity *ge,
                             std::vector<T *> &ele, bool saveAll,
                             int saveSinglePartition, bool binary)
{
  if(saveAll || ge->physicals.size()) {
    for(std::size_t i = 0; i < ele.size(); i++) {
      if(saveSinglePartition && ele[i]->getPartition() != saveSinglePartition)
        continue;
      writeElementMSH(fp, model, ele[i], binary, ge->tag());
    }
  }
}

void writeMSHPeriodicNodes(FILE *fp, std::vector<GEntity *> &entities,
                           bool renumber, bool saveAll) // also used in MSH2
{
  int count = 0;
  for(std::size_t i = 0; i < entities.size(); i++) {
    if(entities[i]->getMeshMaster() != entities[i] &&
       (saveAll || (entities[i]->physicals.size() &&
                    entities[i]->getMeshMaster()->physicals.size()))) {
      count++;
    }
  }
  if(!count) return;
  fprintf(fp, "$Periodic\n");
  fprintf(fp, "%d\n", count);
  for(std::size_t i = 0; i < entities.size(); i++) {
    GEntity *g_slave = entities[i];
    GEntity *g_master = g_slave->getMeshMaster();
    if(g_slave != g_master &&
       (saveAll || (entities[i]->physicals.size() &&
                    entities[i]->getMeshMaster()->physicals.size()))) {
      fprintf(fp, "%d %d %d\n", g_slave->dim(), g_slave->tag(),
              g_master->tag());

      if(g_slave->affineTransform.size() == 16) {
        fprintf(fp, "Affine");
        for(int i = 0; i < 16; i++)
          fprintf(fp, " %.16g", g_slave->affineTransform[i]);
        fprintf(fp, "\n");
      }

      std::map<MVertex *, MVertex *> corrVert = g_slave->correspondingVertices;
      if(CTX::instance()->mesh.hoSavePeriodic)
        corrVert.insert(g_slave->correspondingHighOrderVertices.begin(),
                        g_slave->correspondingHighOrderVertices.end());

      fprintf(fp, "%d\n", (int)corrVert.size());
      for(auto it = corrVert.begin(); it != corrVert.end(); it++) {
        MVertex *v1 = it->first;
        MVertex *v2 = it->second;
        if(renumber)
          fprintf(fp, "%ld %ld\n", v1->getIndex(), v2->getIndex());
        else
          fprintf(fp, "%lu %lu\n", v1->getNum(), v2->getNum());
      }
    }
  }
  fprintf(fp, "$EndPeriodic\n");
}

int GModel::_writeMSH3(const std::string &name, double version, bool binary,
                       bool saveAll, bool saveParametric, double scalingFactor,
                       int elementStartNum, int saveSinglePartition,
                       bool append)
{
  if(version < 3. || version >= 4.) {
    Msg::Error("Wrong MSH file version %g for MSH3 writer", version);
    return 0;
  }

  FILE *fp;
  if(append)
    fp = Fopen(name.c_str(), binary ? "ab" : "a");
  else
    fp = Fopen(name.c_str(), binary ? "wb" : "w");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  // should make this available to users, and should allow to renumber elements,
  // too. Renumbering should be disabled by default.
  bool renumber = false;

  // if there are no physicals we save all the elements
  if(noPhysicalGroups()) saveAll = true;

  // get the number of vertices and index the vertices in a continuous
  // sequence
  int numVertices = indexMeshVertices(saveAll, saveSinglePartition, renumber);

  // get the number of elements we need to save
  std::vector<GEntity *> entities;
  getEntities(entities);
  int numElements = 0;
  for(std::size_t i = 0; i < entities.size(); i++)
    numElements += getNumElementsMSH(entities[i], saveAll, saveSinglePartition);

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
      if(name.size() > 254) name.resize(254);
      fprintf(fp, "%d %d \"%s\"\n", it->first.first, it->first.second,
              name.c_str());
    }
    fprintf(fp, "$EndPhysicalNames\n");
  }

  writeMSHEntities(fp, this);

  fprintf(fp, "$Nodes\n");
  fprintf(fp, "%d\n", numVertices);
  for(std::size_t i = 0; i < entities.size(); i++)
    for(std::size_t j = 0; j < entities[i]->mesh_vertices.size(); j++)
      entities[i]->mesh_vertices[j]->writeMSH(fp, binary, saveParametric,
                                              scalingFactor);

  if(binary) fprintf(fp, "\n");
  fprintf(fp, "$EndNodes\n");

  fprintf(fp, "$Elements\n");
  fprintf(fp, "%d\n", numElements);

  _elementIndexCache.clear();

  for(auto it = firstRegion(); it != lastRegion(); ++it)
    writeElementsMSH(fp, this, *it, (*it)->tetrahedra, saveAll,
                     saveSinglePartition, binary);
  for(auto it = firstRegion(); it != lastRegion(); ++it)
    writeElementsMSH(fp, this, *it, (*it)->hexahedra, saveAll,
                     saveSinglePartition, binary);
  for(auto it = firstRegion(); it != lastRegion(); ++it)
    writeElementsMSH(fp, this, *it, (*it)->prisms, saveAll, saveSinglePartition,
                     binary);
  for(auto it = firstRegion(); it != lastRegion(); ++it)
    writeElementsMSH(fp, this, *it, (*it)->pyramids, saveAll,
                     saveSinglePartition, binary);
  for(auto it = firstRegion(); it != lastRegion(); ++it)
    writeElementsMSH(fp, this, *it, (*it)->trihedra, saveAll,
                     saveSinglePartition, binary);
  for(auto it = firstFace(); it != lastFace(); ++it)
    writeElementsMSH(fp, this, *it, (*it)->triangles, saveAll,
                     saveSinglePartition, binary);
  for(auto it = firstFace(); it != lastFace(); ++it)
    writeElementsMSH(fp, this, *it, (*it)->quadrangles, saveAll,
                     saveSinglePartition, binary);
  for(auto it = firstEdge(); it != lastEdge(); ++it)
    writeElementsMSH(fp, this, *it, (*it)->lines, saveAll, saveSinglePartition,
                     binary);
  for(auto it = firstVertex(); it != lastVertex(); ++it)
    writeElementsMSH(fp, this, *it, (*it)->points, saveAll, saveSinglePartition,
                     binary);

  if(binary) fprintf(fp, "\n");

  fprintf(fp, "$EndElements\n");

  // save periodic nodes
  writeMSHPeriodicNodes(fp, entities, renumber, saveAll);

  fclose(fp);

  return 1;
}

int GModel::_writePartitionedMSH3(const std::string &baseName, double version,
                                  bool binary, bool saveAll,
                                  bool saveParametric, double scalingFactor)
{
  if(version < 3. || version >= 4.) {
    Msg::Error("Wrong MSH file version %g for MSH3 writer", version);
    return 0;
  }

  for(std::size_t partition = 0; partition < getNumPartitions(); partition++) {
    std::ostringstream sstream;
    sstream << baseName << "_" << std::setw(6) << std::setfill('0')
            << partition;
    Msg::Info("Writing partition %d in file '%s'", partition,
              sstream.str().c_str());
    _writeMSH3(sstream.str(), version, binary, saveAll, saveParametric,
               scalingFactor, 0, partition, false);
  }
  return 1;
}
