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
#include "StringUtils.h"

static bool getVertices(int num, const std::vector<int> &indices,
                        std::map<int, MVertex*> &map,
                        std::vector<MVertex*> &vertices)
{
  for(int i = 0; i < num; i++){
    if(!map.count(indices[i])){
      Msg::Error("Wrong vertex index %d", indices[i]);
      return false;
    }
    else
      vertices.push_back(map[indices[i]]);
  }
  return true;
}

static bool getVertices(int num, const std::vector<int> &indices,
                        std::vector<MVertex*> &vec,
                        std::vector<MVertex*> &vertices, int minVertex = 0)
{
  for(int i = 0; i < num; i++){
    if(indices[i] < minVertex || indices[i] > (int)(vec.size() - 1 + minVertex)){
      Msg::Error("Wrong vertex index %d", indices[i]);
      return false;
    }
    else
      vertices.push_back(vec[indices[i]]);
  }
  return true;
}

int GModel::readMSH(const std::string &name)
{
  FILE *fp = fopen(name.c_str(), "rb");
  if(!fp){
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  char str[256] = "";
  double version = 0.;
  bool binary = false, swap = false, postpro = false;
  int minVertex = 0;
  std::map<int, std::vector<int> > entities[4];
  std::map<int, std::vector<MElement*> > elements[10];

  while(1) {

    while(str[0] != '$'){
      if(!fgets(str, sizeof(str), fp) || feof(fp))
        break;
    }

    if(feof(fp))
      break;

    // $MeshFormat section
    if(!strncmp(&str[1], "MeshFormat", 10)) {
      if(!fgets(str, sizeof(str), fp)) return 0;
      int format, size;
      if(sscanf(str, "%lf %d %d", &version, &format, &size) != 3) return 0;
      if(version < 3.) return _readMSH2(name);
      if(format){
        binary = true;
        Msg::Info("Mesh is in binary format");
        int one;
        if(fread(&one, sizeof(int), 1, fp) != 1) return 0;
        if(one != 1){
          swap = true;
          Msg::Info("Swapping bytes from binary file");
        }
      }
    }

    // $PhysicalNames section
    else if(!strncmp(&str[1], "PhysicalNames", 13)) {
      if(!fgets(str, sizeof(str), fp)) return 0;
      int numNames;
      if(sscanf(str, "%d", &numNames) != 1) return 0;
      for(int i = 0; i < numNames; i++) {
        int dim, num;
        if(fscanf(fp, "%d", &dim) != 1) return 0;
        if(fscanf(fp, "%d", &num) != 1) return 0;
        if(!fgets(str, sizeof(str), fp)) return 0;
        std::string name = ExtractDoubleQuotedString(str, 256);
        if(name.size()) setPhysicalName(name, dim, num);
      }
    }

    // $Entities section
    else if(!strncmp(&str[1], "Entities", 8)) {
      if(!fgets(str, sizeof(str), fp)) return 0;
      int numEntities;
      if(sscanf(str, "%d", &numEntities) != 1) return 0;
      for(int i = 0; i < numEntities; i++) {
        int num, dim, numPhysicals;
        if(fscanf(fp, "%d %d %d", &num, &dim, &numPhysicals) != 3) return 0;
        if(numPhysicals > 0){
          std::vector<int> physicals(numPhysicals);
          for(int j = 0; j < numPhysicals; j++){
            if(fscanf(fp, "%d", &physicals[j]) != 1) return 0;
          }
          entities[dim][num] = physicals;
        }
      }
    }

    // $Nodes section
    else if(!strncmp(&str[1], "Nodes", 5)) {
      if(!fgets(str, sizeof(str), fp)) return 0;
      int numVertices;
      if(sscanf(str, "%d", &numVertices) != 1) return 0;
      Msg::Info("%d vertices", numVertices);
      Msg::ResetProgressMeter();
      _vertexMapCache.clear();
      _vertexVectorCache.clear();
      int maxVertex = -1;
      minVertex = numVertices + 1;
      for(int i = 0; i < numVertices; i++) {
        int num, entity, dim;
        double xyz[3];
        MVertex *vertex = 0;
        if(!binary){
          if(fscanf(fp, "%d %lf %lf %lf %d %d", &num, &xyz[0], &xyz[1], &xyz[2],
                    &entity, &dim) != 6)
            return 0;
        }
        else{
          if(fread(&num, sizeof(int), 1, fp) != 1) return 0;
          if(swap) SwapBytes((char*)&num, sizeof(int), 1);
          if(fread(xyz, sizeof(double), 3, fp) != 3) return 0;
          if(swap) SwapBytes((char*)xyz, sizeof(double), 3);
          if(fread(&entity, sizeof(int), 1, fp) != 1) return 0;
          if(swap) SwapBytes((char*)&entity, sizeof(int), 1);
          if(fread(&dim, sizeof(int), 1, fp) != 1) return 0;
          if(swap) SwapBytes((char*)&dim, sizeof(int), 1);
        }
        if(entity){
          switch(dim){
          case 0:
            {
              GVertex *gv = getVertexByTag(entity);
              if(gv) gv->deleteMesh();
              vertex = new MVertex(xyz[0], xyz[1], xyz[2], gv, num);
            }
            break;
          case 1:
            {
              GEdge *ge = getEdgeByTag(entity);
              double u;
              if(!binary){
                if(fscanf(fp, "%lf", &u) != 1) return 0;
              }
              else{
                if(fread(&u, sizeof(double), 1, fp) != 1) return 0;
                if(swap) SwapBytes((char*)&u, sizeof(double), 1);
              }
              vertex = new MEdgeVertex(xyz[0], xyz[1], xyz[2], ge, u, -1.0, num);
            }
            break;
          case 2:
            {
              GFace *gf = getFaceByTag(entity);
              double uv[2];
              if(!binary){
                if(fscanf(fp, "%lf %lf", &uv[0], &uv[1]) != 2) return 0;
              }
              else{
                if(fread(uv, sizeof(double), 2, fp) != 2) return 0;
                if(swap) SwapBytes((char*)uv, sizeof(double), 2);
              }
              vertex = new MFaceVertex(xyz[0], xyz[1], xyz[2], gf, uv[0], uv[1], num);
            }
            break;
          case 3:
            {
              GRegion *gr = getRegionByTag(entity);
              double uvw[3];
              if(!binary){
                if(fscanf(fp, "%lf %lf %lf", &uvw[0], &uvw[1], &uvw[2]) != 2) return 0;
              }
              else{
                if(fread(uvw, sizeof(double), 3, fp) != 3) return 0;
                if(swap) SwapBytes((char*)uvw, sizeof(double), 3);
              }
              vertex = new MVertex(xyz[0], xyz[1], xyz[2], gr, num);
            }
            break;
          default:
            Msg::Error("Wrong entity dimension for vertex %d", num);
            return 0;
          }
        }
        minVertex = std::min(minVertex, num);
        maxVertex = std::max(maxVertex, num);
        if(_vertexMapCache.count(num))
          Msg::Warning("Skipping duplicate vertex %d", num);
        _vertexMapCache[num] = vertex;
        if(numVertices > 100000)
          Msg::ProgressMeter(i + 1, numVertices, true, "Reading nodes");
      }
      // if the vertex numbering is dense, transfer the map into a vector to
      // speed up element creation
      if((int)_vertexMapCache.size() == numVertices &&
         ((minVertex == 1 && maxVertex == numVertices) ||
          (minVertex == 0 && maxVertex == numVertices - 1))){
        Msg::Info("Vertex numbering is dense");
        _vertexVectorCache.resize(_vertexMapCache.size() + 1);
        if(minVertex == 1)
          _vertexVectorCache[0] = 0;
        else
          _vertexVectorCache[numVertices] = 0;
        for(std::map<int, MVertex*>::const_iterator it = _vertexMapCache.begin();
            it != _vertexMapCache.end(); ++it)
          _vertexVectorCache[it->first] = it->second;
        _vertexMapCache.clear();
      }
    }

    // $Elements section
    else if(!strncmp(&str[1], "Elements", 8)) {
      if(!fgets(str, sizeof(str), fp)) return 0;
      int numElements;
      if(sscanf(str, "%d", &numElements) != 1) return 0;
      Msg::Info("%d elements", numElements);
      Msg::ResetProgressMeter();
      _elementMapCache.clear();
      for(int i = 0; i < numElements; i++) {
        int num, type, entity, numData;
        if(!binary){
          if(fscanf(fp, "%d %d %d %d", &num, &type, &entity, &numData) != 4) return 0;
        }
        else{
          if(fread(&num, sizeof(int), 1, fp) != 1) return 0;
          if(swap) SwapBytes((char*)&num, sizeof(int), 1);
          if(fread(&type, sizeof(int), 1, fp) != 1) return 0;
          if(swap) SwapBytes((char*)&type, sizeof(int), 1);
          if(fread(&entity, sizeof(int), 1, fp) != 1) return 0;
          if(swap) SwapBytes((char*)&entity, sizeof(int), 1);
          if(fread(&numData, sizeof(int), 1, fp) != 1) return 0;
          if(swap) SwapBytes((char*)&numData, sizeof(int), 1);
        }
        std::vector<int> data;
        if(numData > 0){
          data.resize(numData);
          if(!binary){
            for(int j = 0; j < numData; j++){
              if(fscanf(fp, "%d", &data[j]) != 1) return 0;
            }
          }
          else{
            if(fread(&data[0], sizeof(int), numData, fp) != numData) return 0;
            if(swap) SwapBytes((char*)&data[0], sizeof(int), numData);
          }
        }
        MElementFactory factory;
        MElement *element = factory.create(num, type, data, this);
        switch(element->getType()){
        case TYPE_PNT: elements[0][entity].push_back(element); break;
        case TYPE_LIN: elements[1][entity].push_back(element); break;
        case TYPE_TRI: elements[2][entity].push_back(element); break;
        case TYPE_QUA: elements[3][entity].push_back(element); break;
        case TYPE_TET: elements[4][entity].push_back(element); break;
        case TYPE_HEX: elements[5][entity].push_back(element); break;
        case TYPE_PRI: elements[6][entity].push_back(element); break;
        case TYPE_PYR: elements[7][entity].push_back(element); break;
        case TYPE_POLYG: elements[8][entity].push_back(element); break;
        case TYPE_POLYH: elements[9][entity].push_back(element); break;
        }
        _elementMapCache[num] = element;
        if(numElements > 100000)
          Msg::ProgressMeter(i + 1, numElements, true, "Reading elements");
      }
    }

    // Post-processing sections
    else if(!strncmp(&str[1], "NodeData", 8) ||
            !strncmp(&str[1], "ElementData", 11) ||
            !strncmp(&str[1], "ElementNodeData", 15)) {
      postpro = true;
      break;
    }

    do {
      if(!fgets(str, sizeof(str), fp) || feof(fp))
        break;
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

  // store physicals in entities
  for(int dim = 0; dim < 4; dim++){
    for(std::map<int, std::vector<int> >::iterator it = entities[dim].begin();
        it != entities[dim].end(); it++){
      GEntity *ge = 0;
      switch(dim){
      case 0: ge = getVertexByTag(it->first); break;
      case 1: ge = getEdgeByTag(it->first); break;
      case 2: ge = getFaceByTag(it->first); break;
      case 3: ge = getRegionByTag(it->first); break;
      }
      ge->physicals = it->second;
    }
  }

  fclose(fp);

  return postpro ? 2 : 1;
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
