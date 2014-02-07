// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include "GModel.h"
#include "OS.h"
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

void writeMSHPeriodicNodes(FILE *fp, std::vector<GEntity*> &entities)
{
  int count = 0;
  for (unsigned int i = 0; i < entities.size(); i++)
    if (entities[i]->meshMaster() != entities[i]->tag()) count++;
  if (!count) return;
  fprintf(fp, "$Periodic\n");
  fprintf(fp, "%d\n", count);
  for(unsigned int i = 0; i < entities.size(); i++){
    GEntity *g_slave = entities[i];
    int meshMaster = g_slave->meshMaster();
    if (g_slave->tag() != meshMaster){
      GEntity *g_master = 0;
      switch(g_slave->dim()){
      case 0 : g_master = g_slave->model()->getVertexByTag(abs(meshMaster));break;
      case 1 : g_master = g_slave->model()->getEdgeByTag(abs(meshMaster));break;
      case 2 : g_master = g_slave->model()->getFaceByTag(abs(meshMaster));break;
      case 3 : g_master = g_slave->model()->getRegionByTag(abs(meshMaster));break;
      }
      fprintf(fp,"%d %d %d\n", g_slave->dim(), g_slave->tag(), g_master->tag());
      fprintf(fp,"%d\n", (int)g_slave->correspondingVertices.size());
      for (std::map<MVertex*,MVertex*>::iterator it = g_slave->correspondingVertices.begin();
           it != g_slave->correspondingVertices.end(); it++){
	MVertex *v1 = it->first;
	MVertex *v2 = it->second;
	fprintf(fp,"%d %d\n", v1->getIndex(), v2->getIndex());
      }
    }
  }
  fprintf(fp, "$EndPeriodic\n");
}

void readMSHPeriodicNodes(FILE *fp, GModel *gm)
{
  int count;
  if(fscanf(fp, "%d", &count) != 1) return;
  for(int i = 0; i < count; i++){
    int dim, slave, master;
    if(fscanf(fp, "%d %d %d", &dim, &slave, &master) != 3) continue;
    GEntity *s = 0, *m = 0;
    switch(dim){
    case 0 : s = gm->getVertexByTag(slave); m = gm->getVertexByTag(master); break;
    case 1 : s = gm->getEdgeByTag(slave); m = gm->getEdgeByTag(master); break;
    case 2 : s = gm->getFaceByTag(slave); m = gm->getFaceByTag(master); break;
    }
    if (s && m){
      s->setMeshMaster(m->tag());
      int numv;
      if(fscanf(fp, "%d", &numv) != 1) numv = 0;
      for(int j = 0; j < numv; j++){
	int v1, v2;
	if(fscanf(fp,"%d %d", &v1, &v2) != 2) continue;
	MVertex *mv1 = gm->getMeshVertexByTag(v1);
	MVertex *mv2 = gm->getMeshVertexByTag(v2);
	s->correspondingVertices[mv1] = mv2;
      }
    }
  }
}

int GModel::readMSH(const std::string &name)
{
  FILE *fp = Fopen(name.c_str(), "rb");
  if(!fp){
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  char str[256] = "";

  // detect prehistoric MSH files
  if(!fgets(str, sizeof(str), fp)){ fclose(fp); return 0; }
  if(!strncmp(&str[1], "NOD", 3) || !strncmp(&str[1], "NOE", 3)){
    fclose(fp);
    return _readMSH2(name);
  }
  strcpy(str, "");
  rewind(fp);

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
      if(!fgets(str, sizeof(str), fp)){ fclose(fp); return 0; }
      int format, size;
      if(sscanf(str, "%lf %d %d", &version, &format, &size) != 3){
        fclose(fp);
        return 0;
      }
      if(version < 3.){
        fclose(fp);
        return _readMSH2(name);
      }
      if(format){
        binary = true;
        Msg::Info("Mesh is in binary format");
        int one;
        if(fread(&one, sizeof(int), 1, fp) != 1){ fclose(fp); return 0; }
        if(one != 1){
          swap = true;
          Msg::Info("Swapping bytes from binary file");
        }
      }
    }

    // FIXME:
    // change this into "$PhysicalAttributes"
    //  #attribs
    //    dim num #nums num1 num2... #str str1 str2...
    //    dum num ...

    // $PhysicalNames section
    else if(!strncmp(&str[1], "PhysicalNames", 13)) {
      if(!fgets(str, sizeof(str), fp)){ fclose(fp); return 0; }
      int numNames;
      if(sscanf(str, "%d", &numNames) != 1){ fclose(fp); return 0; }
      for(int i = 0; i < numNames; i++) {
        int dim, num;
        if(fscanf(fp, "%d", &dim) != 1){ fclose(fp); return 0; }
        if(fscanf(fp, "%d", &num) != 1){ fclose(fp); return 0; }
        if(!fgets(str, sizeof(str), fp)){ fclose(fp); return 0; }
        std::string name = ExtractDoubleQuotedString(str, 256);
        if(name.size()) setPhysicalName(name, dim, num);
      }
    }

    // $Entities section
    else if(!strncmp(&str[1], "Entities", 8)) {
      if(!fgets(str, sizeof(str), fp)){ fclose(fp); return 0; }
      int numEntities;
      if(sscanf(str, "%d", &numEntities) != 1){ fclose(fp); return 0; }
      for(int i = 0; i < numEntities; i++) {
        int num, dim, numPhysicals;
        if(fscanf(fp, "%d %d %d", &num, &dim, &numPhysicals) != 3){
          fclose(fp);
          return 0;
        }
        if(numPhysicals > 0){
          std::vector<int> physicals(numPhysicals);
          for(int j = 0; j < numPhysicals; j++){
            if(fscanf(fp, "%d", &physicals[j]) != 1){ fclose(fp); return 0; }
          }
          entities[dim][num] = physicals;
        }
      }
    }

    // $Nodes section
    else if(!strncmp(&str[1], "Nodes", 5)) {
      if(!fgets(str, sizeof(str), fp)){  return 0; fclose(fp); }
      int numVertices;
      if(sscanf(str, "%d", &numVertices) != 1){ fclose(fp); return 0; }
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
          if(fscanf(fp, "%d %lf %lf %lf %d", &num, &xyz[0], &xyz[1], &xyz[2],
                    &entity) != 5) {
            fclose(fp);
            return 0;
          }
        }
        else{
          if(fread(&num, sizeof(int), 1, fp) != 1){ fclose(fp); return 0; }
          if(swap) SwapBytes((char*)&num, sizeof(int), 1);
          if(fread(xyz, sizeof(double), 3, fp) != 3){ fclose(fp); return 0; }
          if(swap) SwapBytes((char*)xyz, sizeof(double), 3);
          if(fread(&entity, sizeof(int), 1, fp) != 1){ fclose(fp); return 0; }
          if(swap) SwapBytes((char*)&entity, sizeof(int), 1);
        }
        if(!entity){
          vertex = new MVertex(xyz[0], xyz[1], xyz[2], 0, num);
        }
        else{
          if(!binary){
            if(fscanf(fp, "%d", &dim) != 1){ fclose(fp); return 0; }
          }
          else{
            if(fread(&dim, sizeof(int), 1, fp) != 1){ fclose(fp); return 0; }
            if(swap) SwapBytes((char*)&dim, sizeof(int), 1);
          }
          switch(dim){
          case 0:
            {
              GVertex *gv = getVertexByTag(entity);
              // FIXME -- cannot call this: it destroys _vertexMapCache
              //if(gv) gv->deleteMesh();
              vertex = new MVertex(xyz[0], xyz[1], xyz[2], gv, num);
            }
            break;
          case 1:
            {
              GEdge *ge = getEdgeByTag(entity);
              double u;
              if(!binary){
                if(fscanf(fp, "%lf", &u) != 1){ fclose(fp); return 0; }
              }
              else{
                if(fread(&u, sizeof(double), 1, fp) != 1){ fclose(fp); return 0; }
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
                if(fscanf(fp, "%lf %lf", &uv[0], &uv[1]) != 2){ fclose(fp); return 0; }
              }
              else{
                if(fread(uv, sizeof(double), 2, fp) != 2){ fclose(fp); return 0; }
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
                if(fscanf(fp, "%lf %lf %lf", &uvw[0], &uvw[1], &uvw[2]) != 2){
                  fclose(fp);
                  return 0;
                }
              }
              else{
                if(fread(uvw, sizeof(double), 3, fp) != 3){ fclose(fp); return 0; }
                if(swap) SwapBytes((char*)uvw, sizeof(double), 3);
              }
              vertex = new MVertex(xyz[0], xyz[1], xyz[2], gr, num);
            }
            break;
          default:
            Msg::Error("Wrong entity dimension for vertex %d", num);
            fclose(fp);
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
      if(!fgets(str, sizeof(str), fp)){ fclose(fp); return 0; }
      int numElements;
      if(sscanf(str, "%d", &numElements) != 1){ fclose(fp); return 0; }
      Msg::Info("%d elements", numElements);
      Msg::ResetProgressMeter();
      for(int i = 0; i < numElements; i++) {
        int num, type, entity, numData;
        if(!binary){
          if(fscanf(fp, "%d %d %d %d", &num, &type, &entity, &numData) != 4){
            fclose(fp);
            return 0;
          }
        }
        else{
          if(fread(&num, sizeof(int), 1, fp) != 1){ fclose(fp); return 0; }
          if(swap) SwapBytes((char*)&num, sizeof(int), 1);
          if(fread(&type, sizeof(int), 1, fp) != 1){ fclose(fp); return 0; }
          if(swap) SwapBytes((char*)&type, sizeof(int), 1);
          if(fread(&entity, sizeof(int), 1, fp) != 1){ fclose(fp); return 0; }
          if(swap) SwapBytes((char*)&entity, sizeof(int), 1);
          if(fread(&numData, sizeof(int), 1, fp) != 1){ fclose(fp); return 0; }
          if(swap) SwapBytes((char*)&numData, sizeof(int), 1);
        }
        std::vector<int> data;
        if(numData > 0){
          data.resize(numData);
          if(!binary){
            for(int j = 0; j < numData; j++){
              if(fscanf(fp, "%d", &data[j]) != 1){ fclose(fp); return 0; }
            }
          }
          else{
            if((int) fread(&data[0], sizeof(int), numData, fp) != numData){
              fclose(fp);
              return 0;
            }
            if(swap) SwapBytes((char*)&data[0], sizeof(int), numData);
          }
        }
        MElementFactory f;
        MElement *element = f.create(num, type, data, this);
        if(!element){ fclose(fp); return 0; }
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
    else if(!strncmp(&str[1], "Periodical", 10)) {
      readMSHPeriodicNodes (fp, this);
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
      if(ge)
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
                     int saveSinglePartition, bool multipleView)
{
  if(version < 3)
    return _writeMSH2(name, version, binary, saveAll, saveParametric,
                      scalingFactor, elementStartNum, saveSinglePartition,
                      multipleView);

  FILE *fp;
  if(multipleView)
    fp = Fopen(name.c_str(), binary ? "ab" : "a");
  else
    fp = Fopen(name.c_str(), binary ? "wb" : "w");
  if(!fp){
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  // FIXME: should make this available to users, and should allow to renumber
  // elements, too. Renumbering should be disabled by default.
  bool renumber = false;

  // if there are no physicals we save all the elements
  if(noPhysicalGroups()) saveAll = true;

  // get the number of vertices and index the vertices in a continuous
  // sequence
  int numVertices = indexMeshVertices(saveAll, saveSinglePartition, renumber);

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
      entities[i]->mesh_vertices[j]->writeMSH(fp, binary, saveParametric, scalingFactor);

  if(binary) fprintf(fp, "\n");
  fprintf(fp, "$EndNodes\n");

  fprintf(fp, "$Elements\n");
  fprintf(fp, "%d\n", numElements);

  _elementIndexCache.clear();

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
  for(fiter it = firstFace(); it != lastFace(); ++it)
    writeElementsMSH(fp, this, *it, (*it)->triangles, saveAll, saveSinglePartition,
                     binary);
  for(fiter it = firstFace(); it != lastFace(); ++it)
    writeElementsMSH(fp, this, *it, (*it)->quadrangles, saveAll, saveSinglePartition,
                     binary);
  for(eiter it = firstEdge(); it != lastEdge(); ++it)
    writeElementsMSH(fp, this, *it, (*it)->lines, saveAll, saveSinglePartition,
                     binary);
  for(viter it = firstVertex(); it != lastVertex(); ++it)
    writeElementsMSH(fp, this, *it, (*it)->points, saveAll, saveSinglePartition,
                     binary);

  if(binary) fprintf(fp, "\n");

  fprintf(fp, "$EndElements\n");

  //save periodic nodes
  writeMSHPeriodicNodes (fp,entities);

  fclose(fp);

  return 1;
}
