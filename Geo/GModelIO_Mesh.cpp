// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <limits>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <string>
#include <sstream>
#include <iomanip>
#include "GModel.h"
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
#include "SBoundingBox3d.h"
#include "StringUtils.h"
#include "GmshMessage.h"
#include "discreteVertex.h"
#include "discreteEdge.h"
#include "discreteFace.h"
#include "discreteRegion.h"
#include "MElement.h"
#include "GEdgeCompound.h"
#include "GFaceCompound.h"

#if defined(HAVE_ANN)
#include "ANN/ANN.h"
#endif

void GModel::_storePhysicalTagsInEntities(int dim,
                                          std::map<int, std::map<int, std::string> > &map)
{
  std::map<int, std::map<int, std::string> >::const_iterator it = map.begin();
  for(; it != map.end(); ++it){
    GEntity *ge = 0;
    switch(dim){
    case 0: ge = getVertexByTag(it->first); break;
    case 1: ge = getEdgeByTag(it->first); break;
    case 2: ge = getFaceByTag(it->first); break;
    case 3: ge = getRegionByTag(it->first); break;
    }
    if(ge){
      std::map<int, std::string>::const_iterator it2 = it->second.begin();
      for(; it2 != it->second.end(); ++it2){
        if(std::find(ge->physicals.begin(), ge->physicals.end(), it2->first) == 
           ge->physicals.end())
          ge->physicals.push_back(it2->first);
      }
    }
  }
}

static bool getVertices(int num, int *indices, std::map<int, MVertex*> &map, 
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

static bool getVertices(int num, int *indices, std::vector<MVertex*> &vec,
                        std::vector<MVertex*> &vertices)
{
  for(int i = 0; i < num; i++){
    if(indices[i] < 0 || indices[i] > (int)(vec.size() - 1)){
      Msg::Error("Wrong vertex index %d", indices[i]);
      return false;
    }
    else
      vertices.push_back(vec[indices[i]]);
  }
  return true;
}

static MElement *createElementMSH(GModel *m, int num, int typeMSH, int physical,
                                  int reg, int part, std::vector<MVertex*> &v,
                                  std::map<int, std::vector<MElement*> > elements[10],
                                  std::map<int, std::map<int, std::string> > physicals[4])
{
  MElementFactory factory;
  MElement *e = factory.create(typeMSH, v, num, part);

  if(!e){
    Msg::Error("Unknown type of element %d", typeMSH);
    return NULL;
  }

  switch(e->getType()){
  case TYPE_PNT :
    elements[0][reg].push_back(e); break;
  case TYPE_LIN :
    elements[1][reg].push_back(e); break;
  case TYPE_TRI :
    elements[2][reg].push_back(e); break;
  case TYPE_QUA :
    elements[3][reg].push_back(e); break;
  case TYPE_TET :
    elements[4][reg].push_back(e); break;
  case TYPE_HEX :
    elements[5][reg].push_back(e); break;
  case TYPE_PRI :
    elements[6][reg].push_back(e); break;
  case TYPE_PYR :
    elements[7][reg].push_back(e); break;
  case TYPE_POLYG :
    elements[8][reg].push_back(e); break;
  case TYPE_POLYH :
    elements[9][reg].push_back(e); break;
  default : Msg::Error("Wrong type of element"); return NULL;
  }
  
  int dim = e->getDim();
  if(physical && (!physicals[dim].count(reg) || !physicals[dim][reg].count(physical)))
    physicals[dim][reg][physical] = "unnamed";
  
  if(part) m->getMeshPartitions().insert(part);
  return e;
}

static MElement *getParent(int parentNum, std::map<int, std::vector<MElement*> > &elements)
{
  std::map<int, std::vector<MElement*> >::iterator it = elements.begin();
  for(; it != elements.end(); ++it) {
    std::vector<MElement*>::iterator itE = it->second.begin();
    for(; itE != it->second.end(); itE++)
      if((*itE)->getNum() == parentNum) {
        MElement *p = (*itE);
        it->second.erase(itE);
        return p;
      }
  }
  return NULL;
}

static MElement *getParent(int parentNum, int dim,
                           std::map<int, std::vector<MElement*> > elements[10])
{
  MElement *parent = NULL;
  switch(dim){
  case 0 :
    return getParent(parentNum, elements[0]);
  case 1 :
    return getParent(parentNum, elements[1]);
  case 2 :
    if(parent = getParent(parentNum, elements[2])) return parent;
    if(parent = getParent(parentNum, elements[3])) return parent;
    if(parent = getParent(parentNum, elements[8])) return parent;
    return parent;
  case 3 :
    if(parent = getParent(parentNum, elements[4])) return parent;
    if(parent = getParent(parentNum, elements[5])) return parent;
    if(parent = getParent(parentNum, elements[6])) return parent;
    if(parent = getParent(parentNum, elements[7])) return parent;
    if(parent = getParent(parentNum, elements[9])) return parent;
    return parent;
  default : return parent;
  }
}

int GModel::readMSH(const std::string &name)
{
  FILE *fp = fopen(name.c_str(), "rb");
  if(!fp){
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  char str[256] = "XXX";
  double version = 1.0;
  bool binary = false, swap = false, postpro = false;
  std::map<int, std::vector<MElement*> > elements[10];
  std::map<int, std::map<int, std::string> > physicals[4];
  std::map<int, MVertex*> vertexMap;
  std::vector<MVertex*> vertexVector;
 
  while(1) {

    while(str[0] != '$'){
      if(!fgets(str, sizeof(str), fp) || feof(fp))
        break;
    }
    
    if(feof(fp))
      break;

    if(!strncmp(&str[1], "MeshFormat", 10)) {

      if(!fgets(str, sizeof(str), fp)) return 0;
      int format, size;
      if(sscanf(str, "%lf %d %d", &version, &format, &size) != 3) return 0;
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
    else if(!strncmp(&str[1], "PhysicalNames", 13)) {

      if(!fgets(str, sizeof(str), fp)) return 0;
      int numNames;
      if(sscanf(str, "%d", &numNames) != 1) return 0;
      for(int i = 0; i < numNames; i++) {
        int dim = -1, num;
        if(version > 2.0){
          if(fscanf(fp, "%d", &dim) != 1) return 0;
        }
        if(fscanf(fp, "%d", &num) != 1) return 0;
        if(!fgets(str, sizeof(str), fp)) return 0;
        std::string name = ExtractDoubleQuotedString(str, 256);
        if(name.size()) setPhysicalName(name, dim, num);
      }

    }
    else if(!strncmp(&str[1], "NO", 2) || !strncmp(&str[1], "Nodes", 5) ||
            !strncmp(&str[1], "ParametricNodes", 15)) {
      
      const bool parametric = !strncmp(&str[1], "ParametricNodes", 15);
      if(!fgets(str, sizeof(str), fp)) return 0;
      int numVertices;
      if(sscanf(str, "%d", &numVertices) != 1) return 0;
      Msg::Info("%d vertices", numVertices);
      Msg::ResetProgressMeter();
      vertexVector.clear();
      vertexMap.clear();
      int minVertex = numVertices + 1, maxVertex = -1;
      for(int i = 0; i < numVertices; i++) {
        int num;        
        double xyz[3], uv[2];
        MVertex *newVertex = 0;
        if (!parametric){
          if(!binary){
            if (fscanf(fp, "%d %lf %lf %lf", &num, &xyz[0], &xyz[1], &xyz[2]) != 4)
              return 0;   
          }
          else{
            if(fread(&num, sizeof(int), 1, fp) != 1) return 0;
            if(swap) SwapBytes((char*)&num, sizeof(int), 1);
            if(fread(xyz, sizeof(double), 3, fp) != 3) return 0;
            if(swap) SwapBytes((char*)xyz, sizeof(double), 3);
          }
          newVertex = new MVertex(xyz[0], xyz[1], xyz[2], 0, num);
        }
        else{
          int iClasDim, iClasTag;
          if(!binary){      
            if (fscanf(fp, "%d %lf %lf %lf %d %d", &num, &xyz[0], &xyz[1], &xyz[2],
                       &iClasDim, &iClasTag) != 6)
              return 0;
          }
          else{
            if(fread(&num, sizeof(int), 1, fp) != 1) return 0;
            if(swap) SwapBytes((char*)&num, sizeof(int), 1);
            if(fread(xyz, sizeof(double), 3, fp) != 3) return 0;
            if(swap) SwapBytes((char*)xyz, sizeof(double), 3);
            if(fread(&iClasDim, sizeof(int), 1, fp) != 1) return 0;
            if(swap) SwapBytes((char*)&iClasDim, sizeof(int), 1);
            if(fread(&iClasTag, sizeof(int), 1, fp) != 1) return 0;
            if(swap) SwapBytes((char*)&iClasTag, sizeof(int), 1);
          }
          if (iClasDim == 0){
            GVertex *gv = getVertexByTag(iClasTag);
            if (gv) gv->deleteMesh();
            newVertex = new MVertex(xyz[0], xyz[1], xyz[2], gv, num);
          }
          else if (iClasDim == 1){
            GEdge *ge = getEdgeByTag(iClasTag);
            if(!binary){            
              if (fscanf(fp, "%lf", &uv[0]) != 1) return 0;
            }
            else{
              if(fread(uv, sizeof(double), 1, fp) != 1) return 0;
              if(swap) SwapBytes((char*)uv, sizeof(double), 1);
            }
            newVertex = new MEdgeVertex(xyz[0], xyz[1], xyz[2], ge, uv[0], -1.0, num);
          }
          else if (iClasDim == 2){
            GFace *gf = getFaceByTag(iClasTag);
            if(!binary){            
              if (fscanf(fp, "%lf %lf", &uv[0], &uv[1]) != 2) return 0;
            }
            else{
              if(fread(uv, sizeof(double), 2, fp) != 2) return 0;
              if(swap) SwapBytes((char*)uv, sizeof(double), 2);
            }       
            newVertex = new MFaceVertex(xyz[0], xyz[1], xyz[2], gf, uv[0], uv[1], num);
          }
          else if (iClasDim == 3){
            GRegion *gr = getRegionByTag(iClasTag);
            newVertex = new MVertex(xyz[0], xyz[1], xyz[2], gr, num);         
          }
        }
        minVertex = std::min(minVertex, num);
        maxVertex = std::max(maxVertex, num);
        if(vertexMap.count(num))
          Msg::Warning("Skipping duplicate vertex %d", num);
        vertexMap[num] = newVertex;
        if(numVertices > 100000) 
          Msg::ProgressMeter(i + 1, numVertices, "Reading nodes");
      }
      // if the vertex numbering is dense, tranfer the map into a
      // vector to speed up element creation
      if((int)vertexMap.size() == numVertices && 
         ((minVertex == 1 && maxVertex == numVertices) ||
          (minVertex == 0 && maxVertex == numVertices - 1))){
        Msg::Info("Vertex numbering is dense");
        vertexVector.resize(vertexMap.size() + 1);
        if(minVertex == 1) 
          vertexVector[0] = 0;
        else
          vertexVector[numVertices] = 0;
        std::map<int, MVertex*>::const_iterator it = vertexMap.begin();
        for(; it != vertexMap.end(); ++it)
          vertexVector[it->first] = it->second;
        vertexMap.clear();
      }

    }
    else if(!strncmp(&str[1], "ELM", 3) || !strncmp(&str[1], "Elements", 8)) {

      if(!fgets(str, sizeof(str), fp)) return 0;
      int numElements;
      std::map<int, MElement*> parents;
      sscanf(str, "%d", &numElements);
      Msg::Info("%d elements", numElements);
      Msg::ResetProgressMeter();
      if(!binary){
        for(int i = 0; i < numElements; i++) {
          int num, type, physical = 0, elementary = 0, partition = 0, parent = 0;
          int numVertices;
          std::vector<short> ghosts;
          if(version <= 1.0){
            if(fscanf(fp, "%d %d %d %d %d", &num, &type, &physical, &elementary, 
                      &numVertices) != 5)
              return 0;
            if(numVertices != MElement::getInfoMSH(type)) return 0;
          }
          else{
            int numTags;
            if(fscanf(fp, "%d %d %d", &num, &type, &numTags) != 3) return 0;
            std::vector<int> tags(numTags);
            int numPartitions = 0;
            for(int j = 0; j < numTags; j++){
              int tag;
              if(fscanf(fp, "%d", &tag) != 1) return 0;
              if(j == 0) physical = tag;
              else if(j == 1) elementary = tag;
              else if(version < 2.2 && j == 2) partition = tag;
              else if(version >= 2.2 && j == 2) numPartitions = tag;
              else if(version >= 2.2 && j == 3) partition = tag;
              else if(j >= 4 && j < 4 + numPartitions) ghosts.push_back(-tag);
              else if(j == numTags - 1) parent = tag;
            }
            if(!(numVertices = MElement::getInfoMSH(type))) {
              if(type != MSH_POLYG_ && type != MSH_POLYH_) return 0;
              if(fscanf(fp, "%d", &numVertices) != 1) return 0;
            }
          }
          int *indices = new int[numVertices];
          for(int j = 0; j < numVertices; j++)
            if(fscanf(fp, "%d", &indices[j]) != 1) return 0;
          std::vector<MVertex*> vertices;
          if(vertexVector.size()){
            if(!getVertices(numVertices, indices, vertexVector, vertices)) return 0;
          }
          else{
            if(!getVertices(numVertices, indices, vertexMap, vertices)) return 0;
          }
          MElement *e = createElementMSH(this, num, type, physical, elementary,
                                         partition, vertices, elements, physicals);
          for(unsigned int j = 0; j < ghosts.size(); j++)
            _ghostCells.insert(std::pair<MElement*, short>(e, ghosts[j]));
          if(parent) {
            MElement *p = 0;
            if(parents.find(parent) == parents.end()){
              p = getParent(parent, e->getDim(), elements);
              if(p) parents[parent] = p;
              else Msg::Error("Parent element %d not found", parent);
            }
            else p = parents.find(parent)->second;
            e->setParent(p);
          }
          if(numElements > 100000) 
            Msg::ProgressMeter(i + 1, numElements, "Reading elements");
          delete [] indices;
        }
      }
      else{
        int numElementsPartial = 0;
        while(numElementsPartial < numElements){
          int header[3];
          if(fread(header, sizeof(int), 3, fp) != 3) return 0;
          if(swap) SwapBytes((char*)header, sizeof(int), 3);
          int type = header[0];
          int numElms = header[1];
          int numTags = header[2];
          int numVertices = MElement::getInfoMSH(type);
          unsigned int n = 1 + numTags + numVertices;
          int *data = new int[n];
          for(int i = 0; i < numElms; i++) {
            if(fread(data, sizeof(int), n, fp) != n) return 0;
            if(swap) SwapBytes((char*)data, sizeof(int), n);
            int num = data[0];
            int physical = (numTags > 0) ? data[1] : 0;
            int elementary = (numTags > 1) ? data[2] : 0;
            int numPartitions = (version >= 2.2 && numTags > 2) ? data[3] : 0;
            int partition = (version < 2.2 && numTags > 2) ? data[3] : 
              (version >= 2.2 && numTags > 3) ? data[4] : 0;
            int *indices = &data[numTags + 1];
            std::vector<MVertex*> vertices;
            if(vertexVector.size()){
              if(!getVertices(numVertices, indices, vertexVector, vertices)) return 0;
            }
            else{
              if(!getVertices(numVertices, indices, vertexMap, vertices)) return 0;
            }
            MElement *e = createElementMSH(this, num, type, physical, elementary,
                                           partition, vertices, elements, physicals);
            if(numPartitions > 1)
              for(int j = 0; j < numPartitions - 1; j++)
                _ghostCells.insert(std::pair<MElement*, short>(e, -data[5 + j]));
            if(numElements > 100000)
              Msg::ProgressMeter(numElementsPartial + i + 1, numElements, 
                                 "Reading elements");
          }
          delete [] data;
          numElementsPartial += numElms;
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
  if(vertexVector.size())
    _storeVerticesInEntities(vertexVector);
  else
    _storeVerticesInEntities(vertexMap);

  // store the physical tags
  for(int i = 0; i < 4; i++)
    _storePhysicalTagsInEntities(i, physicals[i]);

  fclose(fp);

  return postpro ? 2 : 1;
}

template<class T>
static void writeElementMSH(FILE *fp, GModel *model, T *ele, bool saveAll, 
                            double version, bool binary, int &num, int elementary, 
                            std::vector<int> &physicals, int parentNum)
{
  std::vector<short> ghosts;
  if(model->getGhostCells().size()){
    std::pair<std::multimap<MElement*, short>::iterator,
              std::multimap<MElement*, short>::iterator> itp =
      model->getGhostCells().equal_range(ele);
    for(std::multimap<MElement*, short>::iterator it = itp.first;
        it != itp.second; it++)
      ghosts.push_back(it->second);
  }
  
  if(saveAll)
    ele->writeMSH(fp, version, binary, ++num, elementary, 0, parentNum, &ghosts);
  else
    for(unsigned int j = 0; j < physicals.size(); j++)
      ele->writeMSH(fp, version, binary, ++num, elementary, physicals[j],
                    parentNum, &ghosts);
}

template<class T>
static void writeElementsMSH(FILE *fp, GModel *model, std::vector<T*> &ele, 
                             bool saveAll, int saveSinglePartition, double version,
                             bool binary, int &num, int elementary,
                             std::vector<int> &physicals,
                             std::map<MElement*, int> *parentsNum=0)
{
  for(unsigned int i = 0; i < ele.size(); i++){
    if(saveSinglePartition && ele[i]->getPartition() != saveSinglePartition)
      continue;
    int parentNum = 0;
    if(parentsNum){
      MElement *parent = ele[i]->getParent();
      if(parent){
        std::map<MElement*, int>::iterator it = parentsNum->find(parent);
        if(it != parentsNum->end()) parentNum = it->second;
      }
    }
    writeElementMSH(fp, model, ele[i], saveAll, version, binary, num,
                    elementary, physicals, parentNum);
  }
}

static int getNumElementsMSH(GEntity *ge, bool saveAll, int saveSinglePartition)
{
  int n = 0, p = saveAll ? 1 : ge->physicals.size();
  if(!saveSinglePartition)
    n = p * ge->getNumMeshElements();
  else
    for(unsigned int i = 0; i < ge->getNumMeshElements(); i++)
      if(ge->getMeshElement(i)->getPartition() == saveSinglePartition)
        n += p;
  return n;
}

static int getNumElementsMSH(GModel *m, bool saveAll, int saveSinglePartition)
{
  int n = 0;
  for(GModel::viter it = m->firstVertex(); it != m->lastVertex(); ++it)
    n += getNumElementsMSH(*it, saveAll, saveSinglePartition);
  for(GModel::eiter it = m->firstEdge(); it != m->lastEdge(); ++it)
    n += getNumElementsMSH(*it, saveAll, saveSinglePartition);
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it){
    n += getNumElementsMSH(*it, saveAll, saveSinglePartition);
    for(unsigned int i = 0; i < (*it)->polygons.size(); i++)
      if((*it)->polygons[i]->ownsParent())
        n += (saveAll ? 1 : (*it)->physicals.size());
  }
  for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it){
    n += getNumElementsMSH(*it, saveAll, saveSinglePartition);
    for(unsigned int i = 0; i < (*it)->polyhedra.size(); i++)
      if((*it)->polyhedra[i]->ownsParent())
        n += (saveAll ? 1 : (*it)->physicals.size());
  }
  return n;
}

int GModel::writeMSH(const std::string &name, double version, bool binary,
                     bool saveAll, bool saveParametric, double scalingFactor,
                     int elementStartNum, int saveSinglePartition)
{
  FILE *fp = fopen(name.c_str(), binary ? "wb" : "w");
  if(!fp){
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  // if there are no physicals we save all the elements
  if(noPhysicalGroups()) saveAll = true;

  // get the number of vertices and index the vertices in a continuous
  // sequence
  int numVertices = indexMeshVertices(saveAll);

  // FIXME if saveSinglePartition, re-tag some nodes with '0' index
  // and recompute numVertices
  
  // binary format exists only in version 2
  if(version > 1 || binary) 
    version = 2.2;
  else
    version = 1.0;
  
  // get the number of elements we need to save
  int numElements = getNumElementsMSH(this, saveAll, saveSinglePartition);

  // get parent elements for polygons and polyhedra
  std::map<MElement*, GEntity*> parents[2];
  for(fiter it = firstFace(); it != lastFace(); ++it)
    for(unsigned int i = 0; i < (*it)->polygons.size(); i++)
      if((*it)->polygons[i]->ownsParent())
        parents[0][(*it)->polygons[i]->getParent()] = (*it);
  for(riter it = firstRegion(); it != lastRegion(); ++it)
    for(unsigned int i = 0; i < (*it)->polyhedra.size(); i++)
      if((*it)->polyhedra[i]->ownsParent())
        parents[1][(*it)->polyhedra[i]->getParent()] = (*it);

  // get ghost cells
  std::multimap<MElement*, int> ghostCells;
  if(saveSinglePartition && getGhostCells().size()){
    // XXXX
    numElements += ghostCells.size();    
  }

  if(version >= 2.0){
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

    if (saveParametric)
      fprintf(fp, "$ParametricNodes\n");
    else
      fprintf(fp, "$Nodes\n");
  }
  else
    fprintf(fp, "$NOD\n");

  fprintf(fp, "%d\n", numVertices);

  std::vector<GEntity*> entities;
  getEntities(entities);
  for(unsigned int i = 0; i < entities.size(); i++)
    for(unsigned int j = 0; j < entities[i]->mesh_vertices.size(); j++)
      entities[i]->mesh_vertices[j]->writeMSH(fp, binary, saveParametric, 
                                              scalingFactor);
  
  if(binary) fprintf(fp, "\n");
  
  if(version >= 2.0){
    if(saveParametric)
      fprintf(fp, "$EndParametricNodes\n");
    else
      fprintf(fp, "$EndNodes\n");
    fprintf(fp, "$Elements\n");
  }
  else{
    fprintf(fp, "$ENDNOD\n");
    fprintf(fp, "$ELM\n");
  }

  fprintf(fp, "%d\n", numElements);
  int num = elementStartNum;
  std::map<MElement*, int> parentsNum;

  // points
  for(viter it = firstVertex(); it != lastVertex(); ++it)
    writeElementsMSH(fp, this, (*it)->points, saveAll, saveSinglePartition,
                     version, binary, num, (*it)->tag(), (*it)->physicals);

  // lines
  for(eiter it = firstEdge(); it != lastEdge(); ++it)
    writeElementsMSH(fp, this, (*it)->lines, saveAll, saveSinglePartition,
                     version, binary, num, (*it)->tag(), (*it)->physicals);
  
  // triangles
  for(std::map<MElement*, GEntity*>::const_iterator it = parents[0].begin(); 
      it != parents[0].end(); it++)
    if(it->first->getType() == TYPE_TRI) {
      writeElementMSH(fp, this, it->first, saveAll, version, binary, num,
                      it->second->tag(), it->second->physicals, 0);
      parentsNum[it->first] = num;
    }
  for(fiter it = firstFace(); it != lastFace(); ++it)
    writeElementsMSH(fp, this, (*it)->triangles, saveAll, saveSinglePartition,
                     version, binary, num, (*it)->tag(), (*it)->physicals);

  // quads
  for(std::map<MElement*, GEntity*>::const_iterator it = parents[0].begin(); 
      it != parents[0].end(); it++)
    if(it->first->getType() == TYPE_QUA) {
      writeElementMSH(fp, this, it->first, saveAll, version, binary, num,
                      it->second->tag(), it->second->physicals, 0);
      parentsNum[it->first] = num;
    }
  for(fiter it = firstFace(); it != lastFace(); ++it)
    writeElementsMSH(fp, this, (*it)->quadrangles, saveAll, saveSinglePartition,
                     version, binary, num, (*it)->tag(), (*it)->physicals);

  // polygons
  for(std::map<MElement*, GEntity*>::const_iterator it = parents[0].begin();
      it != parents[0].end(); it++)
    if(it->first->getType() == TYPE_POLYG) {
      writeElementMSH(fp, this, it->first, saveAll, version, binary, num,
                      it->second->tag(), it->second->physicals, 0);
      parentsNum[it->first] = num;
    }
  for(fiter it = firstFace(); it != lastFace(); it++)
    writeElementsMSH(fp, this, (*it)->polygons, saveAll, saveSinglePartition,
                     version, binary, num, (*it)->tag(), (*it)->physicals, 
                     &parentsNum);

  // tets
  for(std::map<MElement*, GEntity*>::const_iterator it = parents[1].begin();
      it != parents[1].end(); it++)
    if(it->first->getType() == TYPE_TET) {
      writeElementMSH(fp, this, it->first, saveAll, version, binary, num,
                      it->second->tag(), it->second->physicals, 0);
      parentsNum[it->first] = num;
    }
  for(riter it = firstRegion(); it != lastRegion(); ++it)
    writeElementsMSH(fp, this, (*it)->tetrahedra, saveAll, saveSinglePartition,
                     version, binary, num, (*it)->tag(), (*it)->physicals);

  // hexas
  for(std::map<MElement*, GEntity*>::const_iterator it = parents[1].begin();
      it != parents[1].end(); it++)
    if(it->first->getType() == TYPE_HEX) {
      writeElementMSH(fp, this, it->first, saveAll, version, binary, num,
                      it->second->tag(), it->second->physicals, 0);
      parentsNum[it->first] = num;
    }
  for(riter it = firstRegion(); it != lastRegion(); ++it)
    writeElementsMSH(fp, this, (*it)->hexahedra, saveAll, saveSinglePartition,
                     version, binary, num, (*it)->tag(), (*it)->physicals);

  // prisms
  for(std::map<MElement*, GEntity*>::const_iterator it = parents[1].begin();
      it != parents[1].end(); it++)
    if(it->first->getType() == TYPE_PRI) {
      writeElementMSH(fp, this, it->first, saveAll, version, binary, num,
                      it->second->tag(), it->second->physicals, 0);
      parentsNum[it->first] = num;
    }
  for(riter it = firstRegion(); it != lastRegion(); ++it)
    writeElementsMSH(fp, this, (*it)->prisms, saveAll, saveSinglePartition,
                     version, binary, num, (*it)->tag(), (*it)->physicals);
  
  // pyramids
  for(std::map<MElement*, GEntity*>::const_iterator it = parents[1].begin();
      it != parents[1].end(); it++)
    if(it->first->getType() == TYPE_PYR) {
      writeElementMSH(fp, this, it->first, saveAll, version, binary, num,
                      it->second->tag(), it->second->physicals, 0);
      parentsNum[it->first] = num;
    }
  for(riter it = firstRegion(); it != lastRegion(); ++it)
    writeElementsMSH(fp, this, (*it)->pyramids, saveAll, saveSinglePartition,
                     version, binary, num, (*it)->tag(), (*it)->physicals);

  // polyhedra
  for(std::map<MElement*, GEntity*>::const_iterator it = parents[1].begin();
      it != parents[1].end(); it++)
    if(it->first->getType() == TYPE_POLYH) {
      writeElementMSH(fp, this, it->first, saveAll, version, binary, num,
                      it->second->tag(), it->second->physicals, 0);
      parentsNum[it->first] = num;
    }
  for(riter it = firstRegion(); it != lastRegion(); ++it)
    writeElementsMSH(fp, this, (*it)->polyhedra, saveAll, saveSinglePartition,
                     version, binary, num, (*it)->tag(), (*it)->physicals,
                     &parentsNum);
  
  if(binary) fprintf(fp, "\n");

  if(version >= 2.0){
    fprintf(fp, "$EndElements\n");
  }
  else{
    fprintf(fp, "$ENDELM\n");
  }

  fclose(fp);

#if 1
  if(_ghostCells.size()){
    Msg::Info("Wrinting ghost cells in debug file");
    fp = fopen("ghosts.pos", "w");
    fprintf(fp, "View \"ghosts\"{\n");
    for(std::multimap<MElement*, short>::iterator it = _ghostCells.begin();
        it != _ghostCells.end(); it++)
      it->first->writePOS(fp, false, true, false, false, false, false);
    fprintf(fp, "};\n");
    fclose(fp);
  }
#endif

  return 1;
}

int GModel::writePartitionedMSH(const std::string &baseName, bool binary,
                                bool saveAll, bool saveParametric,
                                double scalingFactor)
{
  int index = 0;
  for(std::set<int>::iterator it = meshPartitions.begin(); 
      it != meshPartitions.end(); it++){
    int partition = *it;
    
    std::ostringstream sstream;
    sstream << baseName << "_" << std::setw(3) << std::setfill('0') << partition;

    int startNum = index ? getNumElementsMSH(this, saveAll, partition) : 0;
    writeMSH(sstream.str(), 2.2, binary, saveAll, saveParametric, 
             scalingFactor, startNum, partition);
    index++;
  }
  return 1;
}

int GModel::writeDistanceMSH(const std::string &name, double version, bool binary,
			     bool saveAll, bool saveParametric, double scalingFactor)
{
  std::vector<GEntity*> entities;
  getEntities(entities);

  int numnodes = 0;
  for(unsigned int i = 0; i < entities.size()-1; i++)
    numnodes += entities[i]->mesh_vertices.size();

  int totNumNodes = numnodes + entities[entities.size()-1]->mesh_vertices.size();
  std::map<MVertex*,double > distance;

  // EMI: TODO COMPUTE this with EDP distanceTERM instead of ANN write
  // solution for elements

  // CG: Emi -- pourquoi ne pas en faire un plugin, plutot ?

#if defined(HAVE_ANN)
  Msg::Info("Computing Distance function to the boundaries with ANN");
 
 // add all points from boundaries into kdtree
  ANNpointArray kdnodes = annAllocPts(numnodes, 4);
  int k = 0;
  for(unsigned int i = 0; i < entities.size()-1; i++)
    for(unsigned int j = 0; j < entities[i]->mesh_vertices.size(); j++){
      MVertex *v =  entities[i]->mesh_vertices[j];
      distance.insert(std::make_pair(v, 0.0));
      kdnodes[k][0] = v->x();
      kdnodes[k][1] = v->y();
      kdnodes[k][2] = v->z();
      k++;
    }  
  ANNkd_tree *kdtree = new ANNkd_tree(kdnodes, numnodes, 3);

  // compute the distances with the kdtree
  ANNidxArray index = new ANNidx[1];
  ANNdistArray dist = new ANNdist[1];
  GEntity* g = entities[entities.size()-1];
  for(unsigned int j = 0; j < g->mesh_vertices.size(); j++){
    MVertex *v = g->mesh_vertices[j];
    double xyz[3] = {v->x(), v->y(), v->z()};
    kdtree->annkSearch(xyz, 1, index, dist);
    double d = sqrt(dist[0]);
    distance.insert(std::make_pair(v, d));
  }
  delete [] index;
  delete [] dist;
  delete kdtree;
  annDeallocPts(kdnodes);
#endif

  //write distance in msh file
  Msg::Info("Writing distance.pos");
  FILE * f = fopen("distance.pos","w");
  fprintf(f,"View \"distance\"{\n");
  for(std::map<MVertex*, double>::iterator it = distance.begin(); it != distance.end(); it++) {
      fprintf(f,"SP(%g,%g,%g){%g};\n",
	      it->first->x(), it->first->y(), it->first->z(),
	      it->second);     
  }
  fprintf(f,"};\n");
  fclose(f);

//   Msg::Info("Writing distance-bgm.pos");
//   FILE * f2 = fopen("distance-bgm.pos","w");
//   fprintf(f,"View \"distance\"{\n");
//   GEntity* ge = entities[entities.size()-1];
//   for(unsigned int i = 0; i < ge->getNumMeshElements(); i++){ 
//     MElement *e = ge->getMeshElement(i);
//     fprintf(f2,"ST(");//TO DO CHANGE this
//     std::vector<double> dist;
//     for(int j = 0; j < e->getNumVertices(); j++) {
//       MVertex *v =  e->getVertex(j);
//       if(j) fprintf(f2,",%g,%g,%g",v->x(),v->y(), v->z());
//       else fprintf(f2,"%g,%g,%g", v->x(),v->y(), v->z());
//       std::map<MVertex*, double>::iterator it = distance.find(v);
//       dist.push_back(it->second);
//     }
//     fprintf(f2,"){");
//     for (int i=0; i<dist.size(); i++){
//       if (i) fprintf(f2,",%g", dist[i]);
//       else fprintf(f2,"%g", dist[i]);
//     }   
//     fprintf(f2,"};\n");
//   }
//   fprintf(f,"};\n");
//   fclose(f2);
   
  return 1;
}

int GModel::writePOS(const std::string &name, bool printElementary, 
                     bool printElementNumber, bool printGamma, bool printEta, 
                     bool printRho, bool printDisto, bool saveAll, 
                     double scalingFactor)
{
  FILE *fp = fopen(name.c_str(), "w");
  if(!fp){
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  bool f[6] = {printElementary, printElementNumber, printGamma, printEta, printRho,
               printDisto};

  bool first = true; 
  std::string names;
  if(f[0]){
    if(first) first = false; else names += ",";
    names += "\"Elementary Entity\"";
  }
  if(f[1]){
    if(first) first = false; else names += ",";
    names += "\"Element Number\"";
  }
  if(f[2]){
    if(first) first = false; else names += ",";
    names += "\"Gamma\"";
  }
  if(f[3]){
    if(first) first = false; else names += ",";
    names += "\"Eta\"";
  }
  if(f[4]){
    if(first) first = false; else names += ",";
    names += "\"Rho\"";
  }
  if(f[5]){
    if(first) first = false; else names += ",";
    names += "\"Disto\"";
  }

  if(names.empty()) return 0;

  if(noPhysicalGroups()) saveAll = true;

  fprintf(fp, "View \"Statistics\" {\n");
  fprintf(fp, "T2(1.e5,30,%d){%s};\n", (1<<16)|(4<<8), names.c_str());

  std::vector<GEntity*> entities;
  getEntities(entities);
  for(unsigned int i = 0; i < entities.size(); i++)
    if(saveAll || entities[i]->physicals.size())
      for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++)
        entities[i]->getMeshElement(j)->writePOS
          (fp, f[0], f[1], f[2], f[3], f[4], f[5], scalingFactor, entities[i]->tag());
  fprintf(fp, "};\n");

  fclose(fp);
  return 1;
}

int GModel::readSTL(const std::string &name, double tolerance)
{
  FILE *fp = fopen(name.c_str(), "rb");
  if(!fp){
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  // store triplets of points for each solid found in the file
  std::vector<std::vector<SPoint3> > points;
  SBoundingBox3d bbox;

  // "solid", or binary data header
  char buffer[256];
  if(!fgets(buffer, sizeof(buffer), fp)) return 0;

  bool binary = strncmp(buffer, "solid", 5);

  // ASCII STL
  if(!binary){
    points.resize(1);
    while(!feof(fp)) {
      // "facet normal x y z" or "endsolid"
      if(!fgets(buffer, sizeof(buffer), fp)) break;
      if(!strncmp(buffer, "endsolid", 8)){
        // "solid"
        if(!fgets(buffer, sizeof(buffer), fp)) break;
        if(!strncmp(buffer, "solid", 5)){
          points.resize(points.size() + 1);
          // "facet normal x y z"
          if(!fgets(buffer, sizeof(buffer), fp)) break;
        }
      }
      // "outer loop"
      if(!fgets(buffer, sizeof(buffer), fp)) break;
      // "vertex x y z"
      for(int i = 0; i < 3; i++){
        if(!fgets(buffer, sizeof(buffer), fp)) break;
        char s1[256];
        double x, y, z;
        if(sscanf(buffer, "%s %lf %lf %lf", s1, &x, &y, &z) != 4) break;
        SPoint3 p(x, y, z);
        points.back().push_back(p);
        bbox += p;
      }
      // "endloop"
      if(!fgets(buffer, sizeof(buffer), fp)) break;
      // "endfacet"
      if(!fgets(buffer, sizeof(buffer), fp)) break;
    }
  }

  // check if we could parse something
  bool empty = true;
  for(unsigned int i = 0; i < points.size(); i++){
    if(points[i].size()){
      empty = false;
      break;
    }
  }
  if(empty) points.clear();

  // binary STL (we also try to read in binary mode if the header told
  // us the format was ASCII but we could not read any vertices)
  if(binary || empty){
    if(binary) Msg::Info("Mesh is in binary format");
    else Msg::Info("Wrong ASCII header or empty file: trying binary read");
    rewind(fp);
    while(!feof(fp)) {
      char header[80];
      if(!fread(header, sizeof(char), 80, fp)) break;
      unsigned int nfacets = 0;
      size_t ret = fread(&nfacets, sizeof(unsigned int), 1, fp);
      bool swap = false;
      if(nfacets > 100000000){
        Msg::Info("Swapping bytes from binary file");
        swap = true;
        SwapBytes((char*)&nfacets, sizeof(unsigned int), 1);
      }
      if(ret && nfacets){
        points.resize(points.size() + 1);
        char *data = new char[nfacets * 50 * sizeof(char)];
        ret = fread(data, sizeof(char), nfacets * 50, fp);
        if(ret == nfacets * 50){
          for(unsigned int i = 0; i < nfacets; i++) {
            float *xyz = (float *)&data[i * 50 * sizeof(char)];
            if(swap) SwapBytes((char*)xyz, sizeof(float), 12);
            for(int j = 0; j < 3; j++){
              SPoint3 p(xyz[3 + 3 * j], xyz[3 + 3 * j + 1], xyz[3 + 3 * j + 2]);
              points.back().push_back(p);
              bbox += p;
            }
          }
        }
        delete data;
      }
    }
  }

  std::vector<GFace*> faces;
  for(unsigned int i = 0; i < points.size(); i++){
    if(points[i].empty()){
      Msg::Error("No facets found in STL file for solid %d", i);
      return 0;
    }
    if(points[i].size() % 3){
      Msg::Error("Wrong number of points (%d) in STL file for solid %d",
                 points[i].size(), i);
      return 0;
    }
    Msg::Info("%d facets in solid %d", points[i].size() / 3, i);
    // create face
    GFace *face = new discreteFace(this, getNumFaces() + 1);
    faces.push_back(face);
    add(face);
  }

  // create (unique) vertices and triangles
  double lc = norm(SVector3(bbox.max(), bbox.min()));
  double old_tol = MVertexLessThanLexicographic::tolerance;
  MVertexLessThanLexicographic::tolerance = lc * tolerance;
  std::set<MVertex*, MVertexLessThanLexicographic> vertices;
  for(unsigned int i = 0; i < points.size(); i ++){
    for(unsigned int j = 0; j < points[i].size(); j += 3){
      MVertex *v[3];
      for(int k = 0; k < 3; k++){
        double x = points[i][j + k].x();
        double y = points[i][j + k].y();
        double z = points[i][j + k].z();
        MVertex w(x, y, z);
        std::set<MVertex*, MVertexLessThanLexicographic>::iterator it = vertices.find(&w);
        if(it != vertices.end()) {
          v[k] = *it;
        }
        else {
          v[k] = new MVertex(x, y, z, faces[i]);
          vertices.insert(v[k]);
          faces[i]->mesh_vertices.push_back(v[k]);
        }
      }
      faces[i]->triangles.push_back(new MTriangle(v[0], v[1], v[2]));
    }
  }

  MVertexLessThanLexicographic::tolerance = old_tol;

  fclose(fp);
  return 1;
}

int GModel::writeSTL(const std::string &name, bool binary, bool saveAll,
                     double scalingFactor)
{
  FILE *fp = fopen(name.c_str(), binary ? "wb" : "w");
  if(!fp){
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  if(noPhysicalGroups()) saveAll = true;

  if(!binary){
    fprintf(fp, "solid Created by Gmsh\n");
  }
  else{
    char header[80];
    strncpy(header, "Created by Gmsh", 80);
    fwrite(header, sizeof(char), 80, fp);
    unsigned int nfacets = 0;
    for(fiter it = firstFace(); it != lastFace(); ++it){
      if(saveAll || (*it)->physicals.size()){
        nfacets += (*it)->triangles.size() + 2 * (*it)->quadrangles.size();
      }
    }
    fwrite(&nfacets, sizeof(unsigned int), 1, fp);
  }
    
  for(fiter it = firstFace(); it != lastFace(); ++it) {
    if(saveAll || (*it)->physicals.size()){
      for(unsigned int i = 0; i < (*it)->triangles.size(); i++)
        (*it)->triangles[i]->writeSTL(fp, binary, scalingFactor);
      for(unsigned int i = 0; i < (*it)->quadrangles.size(); i++)
        (*it)->quadrangles[i]->writeSTL(fp, binary, scalingFactor);
    }
  }

  if(!binary)
    fprintf(fp, "endsolid Created by Gmsh\n");
  
  fclose(fp);
  return 1;
}

static int skipUntil(FILE *fp, const char *key)
{
  char str[256], key_bracket[256];
  strcpy(key_bracket, key);
  strcat(key_bracket, "[");
  while(fscanf(fp, "%s", str)){
    if(!strcmp(str, key)){ 
      while(!feof(fp) && fgetc(fp) != '['){}
      return 1; 
    }
    if(!strcmp(str, key_bracket)){
      return 1;
    }
  }
  return 0;
}

static int readVerticesVRML(FILE *fp, std::vector<MVertex*> &vertexVector,
                            std::vector<MVertex*> &allVertexVector)
{
  double x, y, z;
  if(fscanf(fp, "%lf %lf %lf", &x, &y, &z) != 3) return 0;
  vertexVector.push_back(new MVertex(x, y, z));
  while(fscanf(fp, " , %lf %lf %lf", &x, &y, &z) == 3)
    vertexVector.push_back(new MVertex(x, y, z));
  for(unsigned int i = 0; i < vertexVector.size(); i++)
    allVertexVector.push_back(vertexVector[i]);
  Msg::Info("%d vertices", vertexVector.size());
  return 1;
}

static int readElementsVRML(FILE *fp, std::vector<MVertex*> &vertexVector, int region,
                            std::map<int, std::vector<MElement*> > elements[3], 
                            bool strips=false)
{
  int i;
  std::vector<int> idx;
  if(fscanf(fp, "%d", &i) != 1) return 0;
  idx.push_back(i);

  // check if vertex indices are separated by commas
  char tmp[256];
  const char *format;
  fpos_t position;
  fgetpos(fp, &position);
  if(!fgets(tmp, sizeof(tmp), fp)) return 0;;
  fsetpos(fp, &position);
  if(strstr(tmp, ","))
    format = " , %d";
  else
    format = " %d";

  while(fscanf(fp, format, &i) == 1){
    if(i != -1){
      idx.push_back(i);
    }
    else{
      std::vector<MVertex*> vertices;
      if(!getVertices(idx.size(), &idx[0], vertexVector, vertices)) return 0;
      idx.clear();
      if(vertices.size() < 2){
        Msg::Info("Skipping %d-vertex element", (int)vertices.size());
      }
      else if(vertices.size() == 2){
        elements[0][region].push_back(new MLine(vertices));
      }
      else if(vertices.size() == 3){
        elements[1][region].push_back(new MTriangle(vertices));
      }
      else if(!strips && vertices.size() == 4){
        elements[2][region].push_back(new MQuadrangle(vertices));
      }
      else if(strips){ // triangle strip
        for(unsigned int j = 2; j < vertices.size(); j++){
          if(j % 2)
            elements[1][region].push_back
              (new MTriangle(vertices[j], vertices[j - 1], vertices[j - 2]));
          else
            elements[1][region].push_back
              (new MTriangle(vertices[j - 2], vertices[j - 1], vertices[j]));
        }
      }
      else{ // import polygon as triangle fan
        for(unsigned int j = 2; j < vertices.size(); j++){
          elements[1][region].push_back
            (new MTriangle(vertices[0], vertices[j-1], vertices[j]));
        }
      }
    }
  }
  if(idx.size()){
    Msg::Error("Prematured end of VRML file");
    return 0;
  }
  Msg::Info("%d elements", elements[0][region].size() + 
            elements[1][region].size() + elements[2][region].size());
  return 1;
}

int GModel::readVRML(const std::string &name)
{
  FILE *fp = fopen(name.c_str(), "r");
  if(!fp){
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  // This is by NO means a complete VRML/Inventor parser (but it's
  // sufficient for reading simple Inventor files... which is all I
  // need)
  std::vector<MVertex*> vertexVector, allVertexVector;
  std::map<int, std::vector<MElement*> > elements[3];
  int region = 0;
  char buffer[256], str[256];
  while(!feof(fp)) {
    if(!fgets(buffer, sizeof(buffer), fp)) break;
    if(buffer[0] != '#'){ // skip comments
      sscanf(buffer, "%s", str);
      if(!strcmp(str, "Coordinate3")){
        vertexVector.clear();
        if(!skipUntil(fp, "point")) break;
        if(!readVerticesVRML(fp, vertexVector, allVertexVector)) break;
      }
      else if(!strcmp(str, "coord")){
        vertexVector.clear();
        if(!skipUntil(fp, "point")) break;
        if(!readVerticesVRML(fp, vertexVector, allVertexVector)) break;
        if(!skipUntil(fp, "coordIndex")) break;
        if(!readElementsVRML(fp, vertexVector, region, elements, true)) break;
      }
      else if(!strcmp(str, "IndexedTriangleStripSet")){
        region++;
        vertexVector.clear();
        if(!skipUntil(fp, "vertex")) break;
        if(!readVerticesVRML(fp, vertexVector, allVertexVector)) break;
        if(!skipUntil(fp, "coordIndex")) break;
        if(!readElementsVRML(fp, vertexVector, region, elements, true)) break;
      }
      else if(!strcmp(str, "IndexedFaceSet") || !strcmp(str, "IndexedLineSet")){
        region++;
        if(!skipUntil(fp, "coordIndex")) break;
        if(!readElementsVRML(fp, vertexVector, region, elements)) break;
      }
      else if(!strcmp(str, "DEF")){
        char str1[256], str2[256];
        if(!sscanf(buffer, "%s %s %s", str1, str2, str)) break;
        if(!strcmp(str, "Coordinate")){
          vertexVector.clear();
          if(!skipUntil(fp, "point")) break;
          if(!readVerticesVRML(fp, vertexVector, allVertexVector)) break;
        }
        else if(!strcmp(str, "IndexedFaceSet") || !strcmp(str, "IndexedLineSet")){
          region++;
          if(!skipUntil(fp, "coordIndex")) break;
          if(!readElementsVRML(fp, vertexVector, region, elements)) break;
        }
      }
    }
  }

  for(int i = 0; i < (int)(sizeof(elements) / sizeof(elements[0])); i++) 
    _storeElementsInEntities(elements[i]);
  _associateEntityWithMeshVertices();
  _storeVerticesInEntities(allVertexVector);

  fclose(fp);
  return 1;
}

int GModel::writeVRML(const std::string &name, bool saveAll, double scalingFactor)
{
  FILE *fp = fopen(name.c_str(), "w");
  if(!fp){
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  if(noPhysicalGroups()) saveAll = true;

  indexMeshVertices(saveAll);

  fprintf(fp, "#VRML V1.0 ascii\n");
  fprintf(fp, "#created by Gmsh\n");
  fprintf(fp, "Coordinate3 {\n");
  fprintf(fp, "  point [\n");

  for(viter it = firstVertex(); it != lastVertex(); ++it)
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++) 
      (*it)->mesh_vertices[i]->writeVRML(fp, scalingFactor);
  for(eiter it = firstEdge(); it != lastEdge(); ++it)
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++)
      (*it)->mesh_vertices[i]->writeVRML(fp, scalingFactor);
  for(fiter it = firstFace(); it != lastFace(); ++it)
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++) 
      (*it)->mesh_vertices[i]->writeVRML(fp, scalingFactor);

  fprintf(fp, "  ]\n");
  fprintf(fp, "}\n");

  for(eiter it = firstEdge(); it != lastEdge(); ++it){
    if(saveAll || (*it)->physicals.size()){
      fprintf(fp, "DEF Curve%d IndexedLineSet {\n", (*it)->tag());
      fprintf(fp, "  coordIndex [\n");
      for(unsigned int i = 0; i < (*it)->lines.size(); i++)
        (*it)->lines[i]->writeVRML(fp);
      fprintf(fp, "  ]\n");
      fprintf(fp, "}\n");
    }
  }

  for(fiter it = firstFace(); it != lastFace(); ++it){
    if(saveAll || (*it)->physicals.size()){
      fprintf(fp, "DEF Surface%d IndexedFaceSet {\n", (*it)->tag());
      fprintf(fp, "  coordIndex [\n");
      for(unsigned int i = 0; i < (*it)->triangles.size(); i++)
        (*it)->triangles[i]->writeVRML(fp);
      for(unsigned int i = 0; i < (*it)->quadrangles.size(); i++)
        (*it)->quadrangles[i]->writeVRML(fp);
      fprintf(fp, "  ]\n");
      fprintf(fp, "}\n");
    }
  }

  fclose(fp);
  return 1;
}

int GModel::readUNV(const std::string &name)
{
  FILE *fp = fopen(name.c_str(), "r");
  if(!fp){
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  char buffer[256];
  std::map<int, MVertex*> vertexMap;
  std::map<int, std::vector<MElement*> > elements[7];
  std::map<int, std::map<int, std::string> > physicals[4];

  while(!feof(fp)) {
    if(!fgets(buffer, sizeof(buffer), fp)) break;
    if(!strncmp(buffer, "    -1", 6)){
      if(!fgets(buffer, sizeof(buffer), fp)) break;     
      if(!strncmp(buffer, "    -1", 6))
        if(!fgets(buffer, sizeof(buffer), fp)) break;
      int record = 0;
      sscanf(buffer, "%d", &record);
      if(record == 2411){ // nodes
        while(fgets(buffer, sizeof(buffer), fp)){
          if(!strncmp(buffer, "    -1", 6)) break;
          int num, dum;
          if(sscanf(buffer, "%d %d %d %d", &num, &dum, &dum, &dum) != 4) break;
          if(!fgets(buffer, sizeof(buffer), fp)) break;
          double x, y, z;
          for(unsigned int i = 0; i < strlen(buffer); i++)
            if(buffer[i] == 'D') buffer[i] = 'E';
          if(sscanf(buffer, "%lf %lf %lf", &x, &y, &z) != 3) break;
          vertexMap[num] = new MVertex(x, y, z, 0, num);
        }
      }
      else if(record == 2412){ // elements
        while(fgets(buffer, sizeof(buffer), fp)){
          if(strlen(buffer) < 3) continue; // possible line ending after last fscanf
          if(!strncmp(buffer, "    -1", 6)) break;
          int num, type, elementary, physical, color, numNodes;
          if(sscanf(buffer, "%d %d %d %d %d %d", &num, &type, &elementary, &physical, 
                    &color, &numNodes) != 6) break;
          if(elementary < 0) elementary = 1;
          if(physical < 0) physical = 0;
          switch(type){
          case 11: case 21: case 22: case 31:
          case 23: case 24: case 32:
            // beam elements
            if(!fgets(buffer, sizeof(buffer), fp)) break;
            int dum;
            if(sscanf(buffer, "%d %d %d", &dum, &dum, &dum) != 3) break;
            break;
          }
          int n[30];
          for(int i = 0; i < numNodes; i++) if(!fscanf(fp, "%d", &n[i])) return 0;
          std::vector<MVertex*> vertices;
          if(!getVertices(numNodes, n, vertexMap, vertices)) return 0;

          int dim = -1;
          switch(type){
          case 11: case 21: case 22: case 31:
            elements[0][elementary].push_back(new MLine(vertices, num));
            dim = 1;
            break;
          case 23: case 24: case 32:
            elements[0][elementary].push_back
              (new MLine3(vertices[0], vertices[2], vertices[1], num));
            dim = 1;
            break;
          case 41: case 51: case 61: case 74: case 81: case 91: 
            elements[1][elementary].push_back(new MTriangle(vertices, num));
            dim = 2;
            break;
          case 42: case 52: case 62: case 72: case 82: case 92: 
            elements[1][elementary].push_back
              (new MTriangle6(vertices[0], vertices[2], vertices[4], vertices[1], 
                              vertices[3], vertices[5], num));
            dim = 2;
            break;
          case 44: case 54: case 64: case 71: case 84: case 94: 
            elements[2][elementary].push_back(new MQuadrangle(vertices, num));
            dim = 2;
            break;
          case 45: case 55: case 65: case 75: case 85: case 95:
            elements[2][elementary].push_back
              (new MQuadrangle8(vertices[0], vertices[2], vertices[4], vertices[6],
                                vertices[1], vertices[3], vertices[5], vertices[7],
                                num));
            dim = 2;
            break;
          case 111:
            elements[3][elementary].push_back(new MTetrahedron(vertices, num));
            dim = 3; 
            break;
          case 118: 
            elements[3][elementary].push_back
              (new MTetrahedron10(vertices[0], vertices[2], vertices[4], vertices[9],
                                  vertices[1], vertices[3], vertices[5], vertices[6],
                                  vertices[8], vertices[7], num));
            dim = 3;
            break;
          case 104: case 115:  
            elements[4][elementary].push_back(new MHexahedron(vertices, num));
            dim = 3; 
            break;
          case 105: case 116:
            elements[4][elementary].push_back
              (new MHexahedron20(vertices[0], vertices[2], vertices[4], vertices[6], 
                                 vertices[12], vertices[14], vertices[16], vertices[18],
                                 vertices[1], vertices[7], vertices[8], vertices[3],
                                 vertices[9], vertices[5], vertices[10], vertices[11],
                                 vertices[13], vertices[19], vertices[15], vertices[17], 
                                 num));
            dim = 3; 
            break;
          case 101: case 112:
            elements[5][elementary].push_back(new MPrism(vertices, num));
            dim = 3; 
            break;
          case 102: case 113:
            elements[5][elementary].push_back
              (new MPrism15(vertices[0], vertices[2], vertices[4], vertices[9], 
                            vertices[11], vertices[13], vertices[1], vertices[5], 
                            vertices[6], vertices[3], vertices[7], vertices[8],
                            vertices[10], vertices[14], vertices[12], num));
            dim = 3;
            break;
          }
  
          if(dim >= 0 && physical && (!physicals[dim].count(elementary) || 
                                      !physicals[dim][elementary].count(physical)))
            physicals[dim][elementary][physical] = "unnamed";
        }
      }
    }
  }
  
  for(int i = 0; i < (int)(sizeof(elements) / sizeof(elements[0])); i++) 
    _storeElementsInEntities(elements[i]);
  _associateEntityWithMeshVertices();
  _storeVerticesInEntities(vertexMap);

  for(int i = 0; i < 4; i++)  
    _storePhysicalTagsInEntities(i, physicals[i]);

  fclose(fp);
  return 1;
}

int GModel::writeUNV(const std::string &name, bool saveAll, bool saveGroupsOfNodes, 
                     double scalingFactor)
{
  FILE *fp = fopen(name.c_str(), "w");
  if(!fp){
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  if(noPhysicalGroups()) saveAll = true;

  indexMeshVertices(saveAll);

  std::vector<GEntity*> entities;
  getEntities(entities);

  // nodes
  fprintf(fp, "%6d\n", -1);
  fprintf(fp, "%6d\n", 2411);
  for(unsigned int i = 0; i < entities.size(); i++)
    for(unsigned int j = 0; j < entities[i]->mesh_vertices.size(); j++) 
      entities[i]->mesh_vertices[j]->writeUNV(fp, scalingFactor);
  fprintf(fp, "%6d\n", -1); 

  // elements
  fprintf(fp, "%6d\n", -1);
  fprintf(fp, "%6d\n", 2412);
  int num = 0;
  for(unsigned int i = 0; i < entities.size(); i++){
    for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++){
      MElement *e = entities[i]->getMeshElement(j);
      if(saveAll)
        e->writeUNV(fp, ++num, entities[i]->tag(), 0);
      else
        for(unsigned int k = 0; k < entities[i]->physicals.size(); k++)
          e->writeUNV(fp, ++num, entities[i]->tag(), entities[i]->physicals[k]);
    }
  }
  fprintf(fp, "%6d\n", -1);

  // groups of nodes for physical groups
  if(saveGroupsOfNodes){
    fprintf(fp, "%6d\n", -1);
    fprintf(fp, "%6d\n", 2477);
    std::map<int, std::vector<GEntity*> > groups[4];
    getPhysicalGroups(groups);
    int gr = 1;
    for(int dim = 1; dim <= 3; dim++){
      for(std::map<int, std::vector<GEntity*> >::iterator it = groups[dim].begin();
          it != groups[dim].end(); it++){
        std::set<MVertex*> nodes;
        std::vector<GEntity *> &entities = it->second;
        for(unsigned int i = 0; i < entities.size(); i++){
          for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++){
            MElement *e = entities[i]->getMeshElement(j);
            for (int k = 0; k < e->getNumVertices(); k++)
              nodes.insert(e->getVertex(k));
          }
        }
        fprintf(fp, "%10d%10d%10d%10d%10d%10d%10d%10d\n", 
                gr, 0, 0, 0, 0, 0, 0, (int)nodes.size());
        fprintf(fp, "PERMANENT GROUP%d\n", gr++);
        int row = 0;
        for(std::set<MVertex*>::iterator it2 = nodes.begin(); it2 != nodes.end(); it2++){
          if(row == 2) {
            fprintf(fp, "\n");
            row = 0;
          }
          fprintf(fp, "%10d%10d%10d%10d", 7, (*it2)->getIndex(), 0, 0);
          row++;
        }
        fprintf(fp, "\n");
      }
    }
    fprintf(fp, "%6d\n", -1);
  }

  fclose(fp);
  return 1;
}

int GModel::readMESH(const std::string &name)
{
  FILE *fp = fopen(name.c_str(), "r");
  if(!fp){
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  char buffer[256];
  if(!fgets(buffer, sizeof(buffer), fp)) return 0;

  char str[256];
  int format;
  sscanf(buffer, "%s %d", str, &format);
  if(format == 3){
    Msg::Error("Medit mesh import only available for ASCII files");
    return 0;
  }

  std::vector<MVertex*> vertexVector;
  std::map<int, std::vector<MElement*> > elements[4];

  while(!feof(fp)) {
    if(!fgets(buffer, 256, fp)) break;
    if(buffer[0] != '#'){ // skip comments and empty lines
      str[0]='\0';
      sscanf(buffer, "%s", str);
      if(!strcmp(str, "Dimension")){
        if(!fgets(buffer, sizeof(buffer), fp)) break;
      }
      else if(!strcmp(str, "Vertices")){
        if(!fgets(buffer, sizeof(buffer), fp)) break;
        int nbv;
        sscanf(buffer, "%d", &nbv);
        Msg::Info("%d vertices", nbv);
        vertexVector.resize(nbv);
        for(int i = 0; i < nbv; i++) {
          if(!fgets(buffer, sizeof(buffer), fp)) break;
          int dum;
          double x, y, z;
          sscanf(buffer, "%lf %lf %lf %d", &x, &y, &z, &dum);
          vertexVector[i] = new MVertex(x, y, z);
        }
      }
      else if(!strcmp(str, "Edges")){
        if(!fgets(buffer, sizeof(buffer), fp)) break;
        int nbe;
        sscanf(buffer, "%d", &nbe);
        Msg::Info("%d edges", nbe);
        for(int i = 0; i < nbe; i++) {
          if(!fgets(buffer, sizeof(buffer), fp)) break;
          int n[2], cl;
          sscanf(buffer, "%d %d %d", &n[0], &n[1], &cl);
          for(int j = 0; j < 2; j++) n[j]--;
          std::vector<MVertex*> vertices;
          if(!getVertices(2, n, vertexVector, vertices)) return 0;
          elements[3][cl].push_back(new MLine(vertices));
        }
      }
      else if(!strcmp(str, "Triangles")){
        if(!fgets(buffer, sizeof(buffer), fp)) break;
        int nbe;
        sscanf(buffer, "%d", &nbe);
        Msg::Info("%d triangles", nbe);
        for(int i = 0; i < nbe; i++) {
          if(!fgets(buffer, sizeof(buffer), fp)) break;
          int n[3], cl;
          sscanf(buffer, "%d %d %d %d", &n[0], &n[1], &n[2], &cl);
          for(int j = 0; j < 3; j++) n[j]--;
          std::vector<MVertex*> vertices;
          if(!getVertices(3, n, vertexVector, vertices)) return 0;
          elements[0][cl].push_back(new MTriangle(vertices));
        }
      }
      else if(!strcmp(str, "Quadrilaterals")) {
        if(!fgets(buffer, sizeof(buffer), fp)) break;
        int nbe;
        sscanf(buffer, "%d", &nbe);
        Msg::Info("%d quadrangles", nbe);
        for(int i = 0; i < nbe; i++) {
          if(!fgets(buffer, sizeof(buffer), fp)) break;
          int n[4], cl;
          sscanf(buffer, "%d %d %d %d %d", &n[0], &n[1], &n[2], &n[3], &cl);
          for(int j = 0; j < 4; j++) n[j]--;
          std::vector<MVertex*> vertices;
          if(!getVertices(4, n, vertexVector, vertices)) return 0;
          elements[1][cl].push_back(new MQuadrangle(vertices));
        }
      }
      else if(!strcmp(str, "Tetrahedra")) {
        if(!fgets(buffer, sizeof(buffer), fp)) break;
        int nbe;
        sscanf(buffer, "%d", &nbe);
        Msg::Info("%d tetrahedra", nbe);
        for(int i = 0; i < nbe; i++) {
          if(!fgets(buffer, sizeof(buffer), fp)) break;
          int n[4], cl;
          sscanf(buffer, "%d %d %d %d %d", &n[0], &n[1], &n[2], &n[3], &cl);
          for(int j = 0; j < 4; j++) n[j]--;
          std::vector<MVertex*> vertices;
          if(!getVertices(4, n, vertexVector, vertices)) return 0;
          elements[2][cl].push_back(new MTetrahedron(vertices));
        }
      }
    }
  }

  for(int i = 0; i < (int)(sizeof(elements) / sizeof(elements[0])); i++) 
    _storeElementsInEntities(elements[i]);
  _associateEntityWithMeshVertices();
  _storeVerticesInEntities(vertexVector);

  fclose(fp);
  return 1;
}

int GModel::writeMESH(const std::string &name, int elementTagType, 
                      bool saveAll, double scalingFactor)
{
  FILE *fp = fopen(name.c_str(), "w");
  if(!fp){
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  if(noPhysicalGroups()) saveAll = true;

  int numVertices = indexMeshVertices(saveAll);

  fprintf(fp, " MeshVersionFormatted 1\n");
  fprintf(fp, " Dimension\n");
  fprintf(fp, " 3\n");

  fprintf(fp, " Vertices\n");
  fprintf(fp, " %d\n", numVertices);
  std::vector<GEntity*> entities;
  getEntities(entities);
  for(unsigned int i = 0; i < entities.size(); i++)
    for(unsigned int j = 0; j < entities[i]->mesh_vertices.size(); j++) 
      entities[i]->mesh_vertices[j]->writeMESH(fp, scalingFactor);
  
  int numEdges = 0, numTriangles = 0, numQuadrangles = 0, numTetrahedra = 0;
  for(eiter it = firstEdge(); it != lastEdge(); ++it){
    if(saveAll || (*it)->physicals.size()){
      numEdges += (*it)->lines.size();
    }
  }
  for(fiter it = firstFace(); it != lastFace(); ++it){
    if(saveAll || (*it)->physicals.size()){
      numTriangles += (*it)->triangles.size();
      numQuadrangles += (*it)->quadrangles.size();
    }
  }
  for(riter it = firstRegion(); it != lastRegion(); ++it){
    if(saveAll || (*it)->physicals.size()){
      numTetrahedra += (*it)->tetrahedra.size();
    }
  }

  if(numEdges){
    fprintf(fp, " Edges\n");
    fprintf(fp, " %d\n", numEdges);
    for(eiter it = firstEdge(); it != lastEdge(); ++it){
      int numPhys = (*it)->physicals.size();
      if(saveAll || numPhys){
        for(unsigned int i = 0; i < (*it)->lines.size(); i++)
          (*it)->lines[i]->writeMESH(fp, elementTagType, (*it)->tag(), 
                                     numPhys ? (*it)->physicals[0] : 0);
      }
    }
  }
  if(numTriangles){
    fprintf(fp, " Triangles\n");
    fprintf(fp, " %d\n", numTriangles);
    for(fiter it = firstFace(); it != lastFace(); ++it){
      int numPhys = (*it)->physicals.size();
      if(saveAll || numPhys){
        for(unsigned int i = 0; i < (*it)->triangles.size(); i++)
          (*it)->triangles[i]->writeMESH(fp, elementTagType, (*it)->tag(), 
                                         numPhys ? (*it)->physicals[0] : 0);
      }
    }
  }
  if(numQuadrangles){
    fprintf(fp, " Quadrilaterals\n");
    fprintf(fp, " %d\n", numQuadrangles);
    for(fiter it = firstFace(); it != lastFace(); ++it){
      int numPhys = (*it)->physicals.size();
      if(saveAll || numPhys){
        for(unsigned int i = 0; i < (*it)->quadrangles.size(); i++)
          (*it)->quadrangles[i]->writeMESH(fp, elementTagType, (*it)->tag(),
                                           numPhys ? (*it)->physicals[0] : 0);
      }
    }
  }
  if(numTetrahedra){
    fprintf(fp, " Tetrahedra\n");
    fprintf(fp, " %d\n", numTetrahedra);
    for(riter it = firstRegion(); it != lastRegion(); ++it){
      int numPhys = (*it)->physicals.size();
      if(saveAll || numPhys){
        for(unsigned int i = 0; i < (*it)->tetrahedra.size(); i++)
          (*it)->tetrahedra[i]->writeMESH(fp, elementTagType, (*it)->tag(),
                                          numPhys ? (*it)->physicals[0] : 0);
      }
    }
  }

  fprintf(fp, " End\n");
  
  fclose(fp);
  return 1;
}

int GModel::writeFEA(const std::string &name, int elementTagType, 
                     bool saveAll, double scalingFactor)
{
  FILE *fp = fopen(name.c_str(), "w");
  if(!fp){
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  if(noPhysicalGroups()) saveAll = true;

  int numVertices = indexMeshVertices(saveAll), num2D = 0, num3D = 0;
  for(fiter it = firstFace(); it != lastFace(); ++it)
    if(saveAll || (*it)->physicals.size()) 
      num2D += (*it)->getNumMeshElements();
  for(riter it = firstRegion(); it != lastRegion(); ++it)
    if(saveAll || (*it)->physicals.size())
      num3D += (*it)->getNumMeshElements();

  fprintf(fp,"33\n");
  if(num2D && num3D)
    fprintf(fp,"%d %d %d\n", numVertices, num2D, num3D);
  else
    fprintf(fp,"%d %d\n", numVertices, num2D ? num2D : num3D);
  
  std::vector<GEntity*> entities;
  getEntities(entities);

  for(unsigned int i = 0; i < entities.size(); i++)
    for(unsigned int j = 0; j < entities[i]->mesh_vertices.size(); j++) 
      if(entities[i]->mesh_vertices[j]->getIndex() >= 0)
	fprintf(fp,"%d %g %g %g\n", entities[i]->mesh_vertices[j]->getIndex(),
		entities[i]->mesh_vertices[j]->x() * scalingFactor,
		entities[i]->mesh_vertices[j]->y() * scalingFactor,
		entities[i]->mesh_vertices[j]->z() * scalingFactor);

  int iElement = 1;
  for(fiter it = firstFace(); it != lastFace(); ++it){
    int numPhys = (*it)->physicals.size();
    if(saveAll || numPhys)
      for(unsigned int i = 0; i < (*it)->getNumMeshElements(); i++)
        (*it)->getMeshElement(i)->writeFEA
          (fp, elementTagType, iElement++, (*it)->tag(), 
           numPhys ? (*it)->physicals[0] : 0);
  }

  for(riter it = firstRegion(); it != lastRegion(); ++it){
    int numPhys = (*it)->physicals.size();
    if(saveAll || numPhys)
      for(unsigned int i = 0; i < (*it)->getNumMeshElements(); i++)
        (*it)->getMeshElement(i)->writeFEA
          (fp, elementTagType, iElement++, (*it)->tag(), 
           numPhys ? (*it)->physicals[0] : 0);
  }
  
  fclose(fp);
  return 1;
}

static int getFormatBDF(char *buffer, int &keySize)
{
  if(buffer[keySize] == '*'){ keySize++; return 2; } // long fields
  for(unsigned int i = 0; i < strlen(buffer); i++)
    if(buffer[i] == ',') return 0; // free fields
  return 1; // small fields;
}

static double atofBDF(char *str)
{
  int len = strlen(str);
  // classic numbers with E or D exponent notation
  for(int i = 0; i < len; i++){
    if(str[i] == 'E' || str[i] == 'e') {
      return atof(str);
    }
    else if(str[i] == 'D' || str[i] == 'd'){ 
      str[i] = 'E'; 
      return atof(str);
    }
  }
  // special Nastran floating point format (e.g. "-7.-1" instead of
  // "-7.E-01" or "2.3+2" instead of "2.3E+02")
  char tmp[32];
  int j = 0, leading_minus = 1;
  for(int i = 0; i < len; i++){
    if(leading_minus && str[i] != ' '  && str[i] != '-') leading_minus = 0;
    if(!leading_minus && str[i] == '-') tmp[j++] = 'E';
    if(str[i] == '+') tmp[j++] = 'E';
    tmp[j++] = str[i];
  }
  tmp[j] = '\0';
  return atof(tmp);
}

static int readVertexBDF(FILE *fp, char *buffer, int keySize, 
                         int *num, double *x, double *y, double *z)
{
  char tmp[5][32];
  int j = keySize;

  switch(getFormatBDF(buffer, keySize)){
  case 0: // free field
    for(int i = 0; i < 5; i++){
      tmp[i][16] = '\0';
      strncpy(tmp[i], &buffer[j + 1], 16);
      for(int k = 0; k < 16; k++){ if(tmp[i][k] == ',') tmp[i][k] = '\0'; }
      j++;
      while(j < (int)strlen(buffer) && buffer[j] != ',') j++;
    }
    break;
  case 1: // small field
    for(int i = 0; i < 5; i++) tmp[i][8] = '\0';
    strncpy(tmp[0], &buffer[8], 8);
    strncpy(tmp[2], &buffer[24], 8); 
    strncpy(tmp[3], &buffer[32], 8); 
    strncpy(tmp[4], &buffer[40], 8); 
    break;
  case 2: // long field
    for(int i = 0; i < 5; i++) tmp[i][16] = '\0';
    strncpy(tmp[0], &buffer[8], 16);
    strncpy(tmp[2], &buffer[40], 16);
    strncpy(tmp[3], &buffer[56], 16);
    char buffer2[256];
    for(unsigned int i = 0; i < sizeof(buffer2); i++) buffer2[i] = '\0';
    if(!fgets(buffer2, sizeof(buffer2), fp)) return 0;
    strncpy(tmp[4], &buffer2[8], 16);
    break;
  }

  *num = atoi(tmp[0]);
  *x = atofBDF(tmp[2]);
  *y = atofBDF(tmp[3]);
  *z = atofBDF(tmp[4]);
  return 1;
}

static bool emptyFieldBDF(char *field, int length)
{
  for(int i = 0; i < length; i++)
    if(field[i] != '\0' && field[i] != ' ' && field[i] != '\n' && field[i] != '\r')
      return false;
  return true;
}

static void readLineBDF(char *buffer, int format, std::vector<char*> &fields)
{
  int cmax = (format == 2) ? 16 : 8; // max char per (center) field
  int nmax = (format == 2) ? 4 : 8; // max num of (center) fields per line

  if(format == 0){ // free fields
    for(unsigned int i = 0; i < strlen(buffer); i++){
      if(buffer[i] == ',') fields.push_back(&buffer[i + 1]);
    }
  }
  else{ // small or long fields
    for(int i = 0; i < nmax + 1; i++){
      if(!emptyFieldBDF(&buffer[8 + cmax * i], cmax))
        fields.push_back(&buffer[8 + cmax * i]);
    }
  }
}

static int readElementBDF(FILE *fp, char *buffer, int keySize, int numVertices, 
                          int &num, int &region, std::vector<MVertex*> &vertices,
                          std::map<int, MVertex*> &vertexMap)
{
  char buffer2[256], buffer3[256];
  std::vector<char*> fields;
  int format = getFormatBDF(buffer, keySize);

  for(unsigned int i = 0; i < sizeof(buffer2); i++) buffer2[i] = buffer3[i] = '\0';

  readLineBDF(buffer, format, fields);

  if(((int)fields.size() - 2 < abs(numVertices)) || 
     (numVertices < 0 && (fields.size() == 9))){
    if(fields.size() == 9) fields.pop_back();
    if(!fgets(buffer2, sizeof(buffer2), fp)) return 0;
    readLineBDF(buffer2, format, fields);
  }

  if(((int)fields.size() - 2 < abs(numVertices)) || 
     (numVertices < 0 && (fields.size() == 17))){
    if(fields.size() == 17) fields.pop_back();
    if(!fgets(buffer3, sizeof(buffer3), fp)) return 0;
    readLineBDF(buffer3, format, fields);
  }

  // negative 'numVertices' gives the minimum required number of vertices
  if((int)fields.size() - 2 < abs(numVertices)){
    Msg::Error("Wrong number of vertices %d for element", fields.size() - 2);
    return 0;
  }

  int n[30], cmax = (format == 2) ? 16 : 8; // max char per (center) field
  char tmp[32];
  tmp[cmax] = '\0';
  strncpy(tmp, fields[0], cmax); num = atoi(tmp);
  strncpy(tmp, fields[1], cmax); region = atoi(tmp);
  for(unsigned int i = 2; i < fields.size(); i++){
    strncpy(tmp, fields[i], cmax); n[i - 2] = atoi(tmp);
  }

  // ignore the extra fields when we know how many vertices we need
  int numCheck = (numVertices > 0) ? numVertices : fields.size() - 2;
  if(!getVertices(numCheck, n, vertexMap, vertices)) return 0;
  return 1;
}

int GModel::readBDF(const std::string &name)
{
  FILE *fp = fopen(name.c_str(), "r");
  if(!fp){
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  char buffer[256];
  std::map<int, MVertex*> vertexMap;
  std::map<int, std::vector<MElement*> > elements[7];

  // nodes can be defined after elements, so parse the file twice

  while(!feof(fp)) {
    for(unsigned int i = 0; i < sizeof(buffer); i++) buffer[i] = '\0';
    if(!fgets(buffer, sizeof(buffer), fp)) break;
    if(buffer[0] != '$'){ // skip comments
      if(!strncmp(buffer, "GRID", 4)){
        int num;
        double x, y, z;
        if(!readVertexBDF(fp, buffer, 4, &num, &x, &y, &z)) break;
        vertexMap[num] = new MVertex(x, y, z, 0, num);
      }
    }
  }
  Msg::Info("%d vertices", vertexMap.size());

  rewind(fp);
  while(!feof(fp)) {
    for(unsigned int i = 0; i < sizeof(buffer); i++) buffer[i] = '\0';
    if(!fgets(buffer, sizeof(buffer), fp)) break;
    if(buffer[0] != '$'){ // skip comments
      int num, region;
      std::vector<MVertex*> vertices;
      if(!strncmp(buffer, "CBAR", 4)){
        if(readElementBDF(fp, buffer, 4, 2, num, region, vertices, vertexMap))
          elements[0][region].push_back(new MLine(vertices, num));
      }
      else if(!strncmp(buffer, "CROD", 4)){
        if(readElementBDF(fp, buffer, 4, 2, num, region, vertices, vertexMap))
          elements[0][region].push_back(new MLine(vertices, num));
      }
      else if(!strncmp(buffer, "CBEAM", 5)){
        if(readElementBDF(fp, buffer, 5, 2, num, region, vertices, vertexMap))
          elements[0][region].push_back(new MLine(vertices, num));
      }
      else if(!strncmp(buffer, "CTRIA3", 6)){
        if(readElementBDF(fp, buffer, 6, 3, num, region, vertices, vertexMap))
          elements[1][region].push_back(new MTriangle(vertices, num));
      }
      else if(!strncmp(buffer, "CTRIA6", 6)){
        if(readElementBDF(fp, buffer, 6, 6, num, region, vertices, vertexMap))
          elements[1][region].push_back(new MTriangle6(vertices, num));
      }
      else if(!strncmp(buffer, "CQUAD4", 6)){
        if(readElementBDF(fp, buffer, 6, 4, num, region, vertices, vertexMap))
          elements[2][region].push_back(new MQuadrangle(vertices, num));
      }
      else if(!strncmp(buffer, "CQUAD8", 6)){
        if(readElementBDF(fp, buffer, 6, 8, num, region, vertices, vertexMap))
          elements[2][region].push_back(new MQuadrangle8(vertices, num));
      }
      else if(!strncmp(buffer, "CQUAD", 5)){
        if(readElementBDF(fp, buffer, 5, -4, num, region, vertices, vertexMap)){
          if(vertices.size() == 9)
            elements[2][region].push_back(new MQuadrangle9(vertices, num));
          else if(vertices.size() == 8)
            elements[2][region].push_back(new MQuadrangle8(vertices, num));
          else
            elements[2][region].push_back(new MQuadrangle(vertices, num));
        }
      }
      else if(!strncmp(buffer, "CTETRA", 6)){
        if(readElementBDF(fp, buffer, 6, -4, num, region, vertices, vertexMap)){
          if(vertices.size() == 10)
            elements[3][region].push_back
              (new MTetrahedron10(vertices[0], vertices[1], vertices[2], vertices[3], 
                                  vertices[4], vertices[5], vertices[6], vertices[7], 
                                  vertices[9], vertices[8], num));
          else
            elements[3][region].push_back(new MTetrahedron(vertices, num));
        }
      }
      else if(!strncmp(buffer, "CHEXA", 5)){
        if(readElementBDF(fp, buffer, 5, -8, num, region, vertices, vertexMap)){
          if(vertices.size() == 20)
            elements[4][region].push_back
              (new MHexahedron20(vertices[0], vertices[1], vertices[2], vertices[3], 
                                 vertices[4], vertices[5], vertices[6], vertices[7], 
                                 vertices[8], vertices[11], vertices[12], vertices[9], 
                                 vertices[13], vertices[10], vertices[14], vertices[15], 
                                 vertices[16], vertices[19], vertices[17], vertices[18], 
                                 num));
          else
            elements[4][region].push_back(new MHexahedron(vertices, num));
        }
      }
      else if(!strncmp(buffer, "CPENTA", 6)){
        if(readElementBDF(fp, buffer, 6, -6, num, region, vertices, vertexMap)){
          if(vertices.size() == 15)
            elements[5][region].push_back
              (new MPrism15(vertices[0], vertices[1], vertices[2], vertices[3],
                            vertices[4], vertices[5], vertices[6], vertices[8],
                            vertices[9], vertices[7], vertices[10], vertices[11],
                            vertices[12], vertices[14], vertices[13], num));
          else
            elements[5][region].push_back(new MPrism(vertices, num));
        }
      }
      else if(!strncmp(buffer, "CPYRAM", 6)){
        if(readElementBDF(fp, buffer, 6, 5, num, region, vertices, vertexMap))
          elements[6][region].push_back(new MPyramid(vertices, num));
      }
    }
  }
  
  for(int i = 0; i < (int)(sizeof(elements) / sizeof(elements[0])); i++) 
    _storeElementsInEntities(elements[i]);
  _associateEntityWithMeshVertices();
  _storeVerticesInEntities(vertexMap);

  fclose(fp);
  return 1;
}

int GModel::writeBDF(const std::string &name, int format, int elementTagType, 
                     bool saveAll, double scalingFactor)
{
  FILE *fp = fopen(name.c_str(), "w");
  if(!fp){
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  if(noPhysicalGroups()) saveAll = true;

  indexMeshVertices(saveAll);

  fprintf(fp, "$ Created by Gmsh\n");

  std::vector<GEntity*> entities;
  getEntities(entities);

  // nodes
  for(unsigned int i = 0; i < entities.size(); i++)
    for(unsigned int j = 0; j < entities[i]->mesh_vertices.size(); j++) 
      entities[i]->mesh_vertices[j]->writeBDF(fp, format, scalingFactor);

  // elements
  for(unsigned int i = 0; i < entities.size(); i++)
    for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++){
      int numPhys = entities[i]->physicals.size();
      if(saveAll || numPhys)
        entities[i]->getMeshElement(j)->writeBDF
          (fp, format, elementTagType, entities[i]->tag(), 
           numPhys ? entities[i]->physicals[0] : 0);
    }

  fprintf(fp, "ENDDATA\n");
   
  fclose(fp);
  return 1;
}

int GModel::readP3D(const std::string &name)
{
  FILE *fp = fopen(name.c_str(), "r");
  if(!fp){
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  int numBlocks = 0;
  if(fscanf(fp, "%d", &numBlocks) != 1 || numBlocks <= 0) return 0;

  std::vector<int> Ni(numBlocks), Nj(numBlocks), Nk(numBlocks);
  for(int n = 0; n < numBlocks; n++)
    if(fscanf(fp, "%d %d %d", &Ni[n], &Nj[n], &Nk[n]) != 3) return 0;

  for(int n = 0; n < numBlocks; n++){
    if(Nk[n] == 1){
      GFace *gf = new discreteFace(this, getNumFaces() + 1);
      add(gf);
      gf->transfinite_vertices.resize(Ni[n]);
      for(int i = 0; i < Ni[n]; i++)
        gf->transfinite_vertices[i].resize(Nj[n]);
      for(int coord = 0; coord < 3; coord++){
        for(int i = 0; i < Ni[n]; i++){
          for(int j = 0; j < Nj[n]; j++){
            double d;
            if(fscanf(fp, "%lf", &d) != 1) return 0;
            if(coord == 0){
              MVertex *v = new MVertex(d, 0., 0., gf);
              gf->transfinite_vertices[i][j] = v;
              gf->mesh_vertices.push_back(v);
            }
            else if(coord == 1){
              gf->transfinite_vertices[i][j]->y() = d;
            }
            else if(coord == 2){
              gf->transfinite_vertices[i][j]->z() = d;
            }
          }
        }
      }
      for(unsigned int i = 0; i < gf->transfinite_vertices.size() - 1; i++)
        for(unsigned int j = 0; j < gf->transfinite_vertices[0].size() - 1; j++)
          gf->quadrangles.push_back
            (new MQuadrangle(gf->transfinite_vertices[i    ][j    ],
                             gf->transfinite_vertices[i + 1][j    ],
                             gf->transfinite_vertices[i + 1][j + 1],
                             gf->transfinite_vertices[i    ][j + 1]));
    }
    else{
      GRegion *gr = new discreteRegion(this, getNumRegions() + 1);
      add(gr);
      gr->transfinite_vertices.resize(Ni[n]);
      for(int i = 0; i < Ni[n]; i++){
        gr->transfinite_vertices[i].resize(Nj[n]);
        for(int j = 0; j < Nj[n]; j++){
          gr->transfinite_vertices[i][j].resize(Nk[n]);
        }
      }
      for(int coord = 0; coord < 3; coord++){
        for(int i = 0; i < Ni[n]; i++){
          for(int j = 0; j < Nj[n]; j++){
            for(int k = 0; k < Nk[n]; k++){
              double d;
              if(fscanf(fp, "%lf", &d) != 1) return 0;
              if(coord == 0){
                MVertex *v = new MVertex(d, 0., 0., gr);
                gr->transfinite_vertices[i][j][k] = v;
                gr->mesh_vertices.push_back(v);
              }
              else if(coord == 1){
                gr->transfinite_vertices[i][j][k]->y() = d;
              }
              else if(coord == 2){
                gr->transfinite_vertices[i][j][k]->z() = d;
              }
            }
          }
        }
      }
      for(unsigned int i = 0; i < gr->transfinite_vertices.size() - 1; i++)
        for(unsigned int j = 0; j < gr->transfinite_vertices[0].size() - 1; j++)
          for(unsigned int k = 0; k < gr->transfinite_vertices[0][0].size() - 1; k++)
            gr->hexahedra.push_back
              (new MHexahedron(gr->transfinite_vertices[i    ][j    ][k    ],
                               gr->transfinite_vertices[i + 1][j    ][k    ],
                               gr->transfinite_vertices[i + 1][j + 1][k    ],
                               gr->transfinite_vertices[i    ][j + 1][k    ],
                               gr->transfinite_vertices[i    ][j    ][k + 1],
                               gr->transfinite_vertices[i + 1][j    ][k + 1],
                               gr->transfinite_vertices[i + 1][j + 1][k + 1],
                               gr->transfinite_vertices[i    ][j + 1][k + 1]));
    }
  }  
  
  fclose(fp);
  return 1;
}

int GModel::writeP3D(const std::string &name, bool saveAll, double scalingFactor)
{
  FILE *fp = fopen(name.c_str(), "w");
  if(!fp){
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  if(noPhysicalGroups()) saveAll = true;

  std::vector<GFace*> faces;
  for(fiter it = firstFace(); it != lastFace(); ++it)
    if((*it)->transfinite_vertices.size() && 
       (*it)->transfinite_vertices[0].size() &&
       ((*it)->physicals.size() || saveAll)) faces.push_back(*it);

  std::vector<GRegion*> regions;
  for(riter it = firstRegion(); it != lastRegion(); ++it)
    if((*it)->transfinite_vertices.size() && 
       (*it)->transfinite_vertices[0].size() && 
       (*it)->transfinite_vertices[0][0].size() && 
       ((*it)->physicals.size() || saveAll)) regions.push_back(*it);
  
  if(faces.empty() && regions.empty()){
    Msg::Warning("No structured grids to save");
    fclose(fp);
    return 0;
  }

  fprintf(fp, "%d\n", (int)(faces.size() + regions.size()));
  
  for(unsigned int i = 0; i < faces.size(); i++)
    fprintf(fp, "%d %d 1\n", 
            (int)faces[i]->transfinite_vertices.size(),
            (int)faces[i]->transfinite_vertices[0].size());

  for(unsigned int i = 0; i < regions.size(); i++)
    fprintf(fp, "%d %d %d\n", 
            (int)regions[i]->transfinite_vertices.size(),
            (int)regions[i]->transfinite_vertices[0].size(),
            (int)regions[i]->transfinite_vertices[0][0].size());
  
  for(unsigned int i = 0; i < faces.size(); i++){
    GFace *gf = faces[i];
    for(int coord = 0; coord < 3; coord++){
      for(unsigned int j = 0; j < gf->transfinite_vertices.size(); j++){
        for(unsigned int k = 0; k < gf->transfinite_vertices[j].size(); k++){
          MVertex *v = gf->transfinite_vertices[j][k];
          double d = (coord == 0) ? v->x() : (coord == 1) ? v->y() : v->z();
          fprintf(fp, "%g ", d * scalingFactor);
        }
        fprintf(fp, "\n");
      }
    }
  }
  
  for(unsigned int i = 0; i < regions.size(); i++){
    GRegion *gr = regions[i];
    for(int coord = 0; coord < 3; coord++){
      for(unsigned int j = 0; j < gr->transfinite_vertices.size(); j++){
        for(unsigned int k = 0; k < gr->transfinite_vertices[j].size(); k++){
          for(unsigned int l = 0; l < gr->transfinite_vertices[j][k].size(); l++){
            MVertex *v = gr->transfinite_vertices[j][k][l];
            double d = (coord == 0) ? v->x() : (coord == 1) ? v->y() : v->z();
            fprintf(fp, "%g ", d * scalingFactor);
          }
          fprintf(fp, "\n");
        }
      }
    }
  }
  
  fclose(fp);
  return 1;
}

int GModel::writeVTK(const std::string &name, bool binary, bool saveAll,
                     double scalingFactor, bool bigEndian)
{
  FILE *fp = fopen(name.c_str(), binary ? "wb" : "w");
  if(!fp){
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  if(noPhysicalGroups()) saveAll = true;

  // get the number of vertices and index the vertices in a continuous
  // sequence
  int numVertices = indexMeshVertices(saveAll);

  fprintf(fp, "# vtk DataFile Version 2.0\n");
  fprintf(fp, "%s, Created by Gmsh\n", getName().c_str());
  if(binary)
    fprintf(fp, "BINARY\n");
  else
    fprintf(fp, "ASCII\n");
  fprintf(fp, "DATASET UNSTRUCTURED_GRID\n");

  // get all the entities in the model
  std::vector<GEntity*> entities;
  getEntities(entities);

  // write mesh vertices
  fprintf(fp, "POINTS %d double\n", numVertices);
  for(unsigned int i = 0; i < entities.size(); i++)
    for(unsigned int j = 0; j < entities[i]->mesh_vertices.size(); j++) 
      entities[i]->mesh_vertices[j]->writeVTK(fp, binary, scalingFactor, bigEndian);
  fprintf(fp, "\n");
  
  // loop over all elements we need to save and count vertices
  int numElements = 0, totalNumInt = 0;
  for(unsigned int i = 0; i < entities.size(); i++){
    if(entities[i]->physicals.size() || saveAll){
      for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++){
        if(entities[i]->getMeshElement(j)->getTypeForVTK()){
          numElements++;
          totalNumInt += entities[i]->getMeshElement(j)->getNumVertices() + 1;
        }
      }
    }
  }
  
  // print vertex indices in ascii or binary
  fprintf(fp, "CELLS %d %d\n", numElements, totalNumInt);
  for(unsigned int i = 0; i < entities.size(); i++){
    if(entities[i]->physicals.size() || saveAll){
      for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++){
        if(entities[i]->getMeshElement(j)->getTypeForVTK())
          entities[i]->getMeshElement(j)->writeVTK(fp, binary, bigEndian);
      }
    }
  }
  fprintf(fp, "\n");
  
  // print element types in ascii or binary  
  fprintf(fp, "CELL_TYPES %d\n", numElements);
  for(unsigned int i = 0; i < entities.size(); i++){
    if(entities[i]->physicals.size() || saveAll){
      for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++){
        int type = entities[i]->getMeshElement(j)->getTypeForVTK();
        if(type){
          if(binary){
            // VTK always expects big endian binary data
            if(!bigEndian) SwapBytes((char*)&type, sizeof(int), 1);
            fwrite(&type, sizeof(int), 1, fp);
          }
          else
            fprintf(fp, "%d\n", type);
        }
      }
    }
  }
  
  fclose(fp);
  return 1;
}

int GModel::readVTK(const std::string &name, bool bigEndian)
{
  FILE *fp = fopen(name.c_str(), "rb");
  if(!fp){
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }
  
  char buffer[256], buffer2[256];
  
  if(!fgets(buffer, sizeof(buffer), fp)) return 0; // version line
  if(!fgets(buffer, sizeof(buffer), fp)) return 0; // title
  
  if(fscanf(fp, "%s", buffer) != 1) // ASCII or BINARY
    Msg::Error("Failed reading buffer");
  bool binary = false;
  if(!strcmp(buffer, "BINARY")) binary = true;
  
  if(fscanf(fp, "%s %s", buffer, buffer2) != 2) return 0;
  if(strcmp(buffer, "DATASET") || strcmp(buffer2, "UNSTRUCTURED_GRID")){
    Msg::Error("VTK reader can only read unstructured datasets");
    return 0;
  }
  
  // read mesh vertices
  int numVertices;
  if(fscanf(fp, "%s %d %s\n", buffer, &numVertices, buffer2) != 3) return 0;
  if(strcmp(buffer, "POINTS") || !numVertices){
    Msg::Warning("No points in dataset");
    return 0;
  }
  int datasize;
  if(!strcmp(buffer2, "double"))
    datasize = sizeof(double);
  else if(!strcmp(buffer2, "float"))
    datasize = sizeof(float);
  else{
    Msg::Warning("VTK reader only accepts float or double datasets");
    return 0;
  }

  Msg::Info("Reading %d points", numVertices);
  std::vector<MVertex*> vertices(numVertices);
  for(int i = 0 ; i < numVertices; i++){
    double xyz[3];
    if(binary){
      if(datasize == sizeof(float)){
        float f[3];
        if(fread(f, sizeof(float), 3, fp) != 3) return 0;
        if(!bigEndian) SwapBytes((char*)f, sizeof(float), 3);
        for(int j = 0; j < 3; j++) xyz[j] = f[j];
      }
      else{
        if(fread(xyz, sizeof(double), 3, fp) != 3) return 0;
        if(!bigEndian) SwapBytes((char*)xyz, sizeof(double), 3);
      }
    }
    else{
      if(fscanf(fp, "%lf %lf %lf", &xyz[0], &xyz[1], &xyz[2]) != 3) return 0;
    }
    vertices[i] = new MVertex(xyz[0], xyz[1], xyz[2]);
  }

  // read mesh elements
  int numElements, totalNumInt;
  if(fscanf(fp, "%s %d %d\n", buffer, &numElements, &totalNumInt) != 3) return 0;
  if(strcmp(buffer, "CELLS") || !numElements){
    Msg::Warning("No cells in dataset");
    return 0;
  }
  Msg::Info("Reading %d cells", numElements);
  std::vector<std::vector<MVertex*> > cells(numElements);
  for(unsigned int i = 0; i < cells.size(); i++){
    int numVerts, n[100];
    if(binary){
      if(fread(&numVerts, sizeof(int), 1, fp) != 1) return 0;
      if(!bigEndian) SwapBytes((char*)&numVerts, sizeof(int), 1);
      if((int)fread(n, sizeof(int), numVerts, fp) != numVerts) return 0;
      if(!bigEndian) SwapBytes((char*)n, sizeof(int), numVerts);
    }
    else{
      if(fscanf(fp, "%d", &numVerts) != 1) return 0;
      for(int j = 0; j < numVerts; j++){
        if(fscanf(fp, "%d", &n[j]) != 1) return 0;
      }
    }
    for(int j = 0; j < numVerts; j++){
      if(n[j] >= 0 && n[j] < (int)vertices.size())
        cells[i].push_back(vertices[n[j]]);
      else
        Msg::Error("Bad vertex index");
    }
  }
  if(fscanf(fp, "%s %d\n", buffer, &numElements) != 2) return 0;
  if(strcmp(buffer, "CELL_TYPES") || numElements != (int)cells.size()){
    Msg::Error("No or invalid number of cells types");
    return 0;
  }
  std::map<int, std::vector<MElement*> > elements[8];
  for(unsigned int i = 0; i < cells.size(); i++){
    int type;
    if(binary){
      if(fread(&type, sizeof(int), 1, fp) != 1) return 0;
      if(!bigEndian) SwapBytes((char*)&type, sizeof(int), 1);
    }
    else{
      if(fscanf(fp, "%d", &type) != 1) return 0;
    }
    switch(type){
    case 1: elements[0][1].push_back(new MPoint(cells[i])); break;
    case 3: elements[1][1].push_back(new MLine(cells[i])); break;
    case 5: elements[2][1].push_back(new MTriangle(cells[i])); break;
    case 9: elements[3][1].push_back(new MQuadrangle(cells[i])); break;
    case 10: elements[4][1].push_back(new MTetrahedron(cells[i])); break;
    case 12: elements[5][1].push_back(new MHexahedron(cells[i])); break;
    case 13: elements[6][1].push_back(new MPrism(cells[i])); break;
    case 14: elements[7][1].push_back(new MPyramid(cells[i])); break;
    default: 
      Msg::Error("Unknown type of cell %d", type);
      break;
    }
  }  
  
  for(int i = 0; i < (int)(sizeof(elements) / sizeof(elements[0])); i++) 
    _storeElementsInEntities(elements[i]);
  _associateEntityWithMeshVertices();
  _storeVerticesInEntities(vertices);
  
  fclose(fp);
  return 1;
}

int GModel::readDIFF(const std::string &name)
{
  FILE *fp = fopen(name.c_str(), "r");
  if(!fp){
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  char str[256] = "XXX";
  std::map<int, std::vector<MElement*> > elements[10];
  std::map<int, std::map<int, std::string> > physicals[4];
  std::map<int, MVertex*> vertexMap;
  std::vector<MVertex*> vertexVector;
 
  while(1) {

    while(strstr(str, "Number of space dim. =") == NULL){
      if(!fgets(str, sizeof(str), fp) || feof(fp))
        break;
    }
    
    int dim;
    if(sscanf(str, "%*s %*s %*s %*s %*s %d", &dim) != 1) return 0;
    Msg::Info("dimension %d", dim); 

    int numElements;
    if(!fgets(str, sizeof(str), fp) || feof(fp)) return 0;
    while(strstr(str, "Number of elements   =") == NULL){
      if(!fgets(str, sizeof(str), fp) || feof(fp))
        break;
    }
    if(sscanf(str, "%*s %*s %*s %*s %d", &numElements) != 1) return 0;
    Msg::Info("%d elements", numElements); 

    int numVertices;
    if(!fgets(str, sizeof(str), fp) || feof(fp)) return 0;
    while(strstr(str, "Number of nodes      =") == NULL){
      if(!fgets(str, sizeof(str), fp) || feof(fp))
        break;
    }
    if(sscanf(str, "%*s %*s %*s %*s %d", &numVertices) != 1) return 0;
    Msg::Info("%d vertices", numVertices); 

    int numVerticesPerElement;
    if(!fgets(str, sizeof(str), fp)||feof(fp)) return 0;
    while(strstr(str, "Max number of nodes in an element:")==NULL){
      if(!fgets(str, sizeof(str), fp) || feof(fp))
        break;
    }
    if(sscanf(str, "%*s %*s %*s %*s %*s %*s %*s %d", &numVerticesPerElement) != 1)
      return 0;
    Msg::Info("numVerticesPerElement %d",numVerticesPerElement); 

    bool several_subdomains;
    if(!fgets(str, sizeof(str), fp) || feof(fp)) return 0;
    while(strstr(str, "Only one subdomain el              :") == NULL){
      if(!fgets(str, sizeof(str), fp) || feof(fp))
        break;
    }
    if(!strncmp(&str[39], "dpFALSE", 6))
      several_subdomains = true;
    else
      several_subdomains = false;
    Msg::Info("several_subdomains %x", several_subdomains); 
    
    int nbi;
    std::vector<int> bi;
    if(!fgets(str, sizeof(str), fp) || feof(fp)) return 0;
    while(strstr(str, "Boundary indicators:") == NULL){
      if(!fgets(str, sizeof(str), fp) || feof(fp))
        break;
    }
    if(sscanf(str, "%d %*s %*s", &nbi) != 1) return 0;
    Msg::Info("nbi %d", nbi);
    if(nbi != 0)
      bi.resize(nbi);
    std::string format_read_bi = "%*d %*s %*s";
    for(int i = 0; i < nbi; i++){
      if(format_read_bi[format_read_bi.size()-1] == 'd') {
        format_read_bi[format_read_bi.size()-1] = '*';
        format_read_bi += "d %d";
      }
      else
        format_read_bi += " %d";
      if(sscanf(str, format_read_bi.c_str(), &bi[i]) != 1) return 0;
      Msg::Info("bi[%d]=%d", i, bi[i]); 
    }
    
    while(str[0] != '#'){
      if(!fgets(str, sizeof(str), fp) || feof(fp))
        break;
    }
    vertexVector.clear();
    vertexMap.clear();
    int minVertex = numVertices + 1, maxVertex = -1;
    int num = 0;
    std::vector<std::vector<int> > elementary(numVertices);

    Msg::ResetProgressMeter();
    for(int i = 0; i < numVertices; i++){
      if(!fgets(str, sizeof(str), fp)) return 0;
      double xyz[3];
      int tmp;
      if(sscanf(str, "%d ( %lf , %lf , %lf ) [%d]", &num, &xyz[0], &xyz[1], &xyz[2], 
                &tmp) != 5) return 0;
      elementary[i].resize(tmp + 1);
      elementary[i][0] = tmp;
      minVertex = std::min(minVertex, num);
      maxVertex = std::max(maxVertex, num);
      if(vertexMap.count(num))
        Msg::Warning("Skipping duplicate vertex %d", num);
      else
        vertexMap[num] = new MVertex(xyz[0], xyz[1], xyz[2], 0, num);
      if(numVertices > 100000) 
        Msg::ProgressMeter(i + 1, numVertices, "Reading nodes");
      // If the vertex numbering is dense, tranfer the map into a
      // vector to speed up element creation
      if((int)vertexMap.size() == numVertices && 
         ((minVertex == 1 && maxVertex == numVertices) ||
          (minVertex == 0 && maxVertex == numVertices - 1))){
        Msg::Info("Vertex numbering is dense");
        vertexVector.resize(vertexMap.size() + 1);
        if(minVertex == 1) 
          vertexVector[0] = 0;
        else
          vertexVector[numVertices] = 0;
        std::map<int, MVertex*>::const_iterator it = vertexMap.begin();
        for(; it != vertexMap.end(); ++it)
          vertexVector[it->first] = it->second;
        vertexMap.clear();
      }
      Msg::Info("%d ( %lf , %lf , %lf ) [%d]",i, xyz[0], xyz[1], xyz[2], 
                elementary[i][0]);
      std::string format_read_bi = "%*d ( %*lf , %*lf , %*lf ) [%*d]";
      for(int j = 0; j < elementary[i][0]; j++){
        if(format_read_bi[format_read_bi.size() - 1] == 'd') {
          format_read_bi[format_read_bi.size() - 1] = '*';
          format_read_bi += "d %d";
        }
        else
          format_read_bi += " %d";
        if(sscanf(str, format_read_bi.c_str(), &(elementary[i][j + 1])) != 1) 
          return 0;
        Msg::Info("elementary[%d][%d]=%d", i + 1, j + 1, elementary[i][j + 1]); 
      }
    }
    while(str[0] != '#'){
      if(!fgets(str, sizeof(str), fp) || feof(fp))
        break;
    }
    std::vector<int> material(numElements);
    std::vector<std::vector<int> > ElementsNodes(numElements);
    for(int i = 0; i < numVertices; i++){
      ElementsNodes[i].resize(numVerticesPerElement);
    }
    char eleTypec[20]="";
    std::string eleType;
    Msg::ResetProgressMeter();
    std::vector<int> mapping;
    for(int i = 1; i <= numElements; i++){
      if(!fgets(str, sizeof(str), fp)) return 0;
      int num = 0, type, physical = 0, partition = 0;
      int indices[60];
      if(sscanf(str, "%*d %s %d", eleTypec, &material[i-1]) != 2) return 0;
      eleType = std::string(eleTypec);
      int k2; // local number for the element
      int NoVertices; // number of vertices per element
      if(eleType == "ElmT3n2D"){ 
        NoVertices = 3;
        static int map[3] = {0, 1, 2}; // identical to gmsh
        mapping=std::vector<int>(map, map + sizeof(map) / sizeof(int));
        type = MSH_TRI_3;
      }
      else if(eleType == "ElmT6n2D"){ 
        NoVertices = 6;
        static int map[6] = {0, 1, 2, 3, 4, 5}; // identical to gmsh
        mapping = std::vector<int>(map, map + sizeof(map) / sizeof(int));
        type = MSH_TRI_6;
      }
      else if(eleType == "ElmB4n2D"){ 
        NoVertices = 4;
        static int map[4] = {0, 1, 3, 2}; // local numbering
        mapping = std::vector<int>(map, map + sizeof(map) / sizeof(int));
        type = MSH_QUA_4;
      }
      else if(eleType == "ElmB8n2D"){ 
        NoVertices = 8;
        static int map[8] = {0, 1, 3, 2, 4, 6, 7, 5}; // local numbering
        mapping = std::vector<int>(map, map + sizeof(map) / sizeof(int));
        type = MSH_QUA_8;
      }
      else if(eleType == "ElmB9n2D"){ 
        NoVertices = 9;
        static int map[9] = {0, 4, 1, 7, 8, 5, 3, 6, 2}; // local numbering
        mapping = std::vector<int>(map, map + sizeof(map) / sizeof(int));
        type = MSH_QUA_9;
      }
      else if(eleType == "ElmT4n3D"){
        NoVertices = 4;
        static int map[4] = {0, 1, 2, 3}; // identical to gmsh
        mapping = std::vector<int>(map, map + sizeof(map) / sizeof(int));
        type = MSH_TET_4;
      } 
      else if(eleType == "ElmT10n3D"){ 
        NoVertices = 10;
        static int map[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // local numbering
        mapping = std::vector<int>(map, map + sizeof(map) / sizeof(int));
        type = MSH_TET_10;
      }
      else if(eleType == "ElmB8n3D"){
        NoVertices = 8;
        static int map[8] = {4, 5, 0, 1, 7, 6, 3, 2};
        mapping = std::vector<int>(map, map + sizeof(map) / sizeof(int));
        type = MSH_HEX_8;
      } 
      else if(eleType == "ElmB20n3D"){
        NoVertices = 20;
        static int map[20] = {4, 5, 0, 1, 7, 6, 3, 2, 16, 8, 19, 13, 15, 12, 
                              14, 17, 18, 9, 11};
        mapping = std::vector<int>(map, map + sizeof(map) / sizeof(int));
        type = MSH_HEX_20;
      } 
      else if(eleType == "ElmB27n3D"){
        NoVertices = 27;
        static int map[27] = {4, 16, 5, 10, 21, 12, 0, 8, 1, 17, 25, 18, 22, 
                              26, 23, 9, 20, 11, 7, 19, 6, 15, 24, 14, 3, 13, 2};
        mapping = std::vector<int>(map, map + sizeof(map) / sizeof(int));
        type = MSH_HEX_27;
      } 
      else{
        return 0;
      }
      std::string format_read_vertices = "%*d %*s %*d";
      for(int k = 0; k < NoVertices; k++){
        if(format_read_vertices[format_read_vertices.size()-2] != '*') {
          format_read_vertices[format_read_vertices.size()-1] = '*';
          format_read_vertices += "d %d";
        } 
        else
          format_read_vertices += " %d";
        k2 = mapping[k];
        if(sscanf(str, format_read_vertices.c_str(), &ElementsNodes[i-1][k2]) != 1) 
          return 0;
      }
      mapping.clear();
      for(int j = 0; j < NoVertices; j++)
        indices[j] = ElementsNodes[i - 1][j];
      std::vector<MVertex*> vertices;
      if(vertexVector.size()){
        if(!getVertices(numVerticesPerElement, indices, vertexVector, vertices)) 
          return 0;
      }
      else{
        if(!getVertices(numVerticesPerElement, indices, vertexMap, vertices)) 
          return 0;
      }
      createElementMSH(this, num, type, physical, elementary[i-1][1], partition, 
                       vertices, elements, physicals); 
      // trouble if elementary[i-1][0]>1 nodal post-processing needed ?
      if(numElements > 100000) 
        Msg::ProgressMeter(i + 1, numElements, "Reading elements");
    }
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
  for(int i = 0; i < 4; i++)
    _storePhysicalTagsInEntities(i, physicals[i]);

  fclose(fp);
  return 1;
}

int GModel::writeDIFF(const std::string &name, bool binary, bool saveAll,
                      double scalingFactor)
{
  if(binary){
    Msg::Error("Binary DIFF output is not implemented");
    return 0;
  }

  FILE *fp = fopen(name.c_str(), binary ? "wb" : "w");
  if(!fp){
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }
  
  if(noPhysicalGroups()) saveAll = true;

  // get the number of vertices and index the vertices in a continuous
  // sequence
  int numVertices = indexMeshVertices(saveAll);

  // tag the vertices according to which surface they belong to (Note
  // that we use a brute force approach here, so that we can deal with
  // models with incomplete topology. For example, when we merge 2 STL
  // triangulations we don't have the boundary information between the
  // faces, and the vertices would end up categorized on either one.)
  std::vector<std::list<int> > vertexTags(numVertices);
  std::list<int> boundaryIndicators;
  for(riter it = firstRegion(); it != lastRegion(); it++){
    std::list<GFace*> faces = (*it)->faces();
    for(std::list<GFace*>::iterator itf = faces.begin(); itf != faces.end(); itf++){
      GFace *gf = *itf;
      boundaryIndicators.push_back(gf->tag());
      for(unsigned int i = 0; i < gf->getNumMeshElements(); i++){
        MElement *e = gf->getMeshElement(i);
        for(int j = 0; j < e->getNumVertices(); j++){
          MVertex *v = e->getVertex(j);
          if(v->getIndex() > 0)
            vertexTags[v->getIndex() - 1].push_back(gf->tag());
        }
      }
    }
  }
  boundaryIndicators.sort();
  boundaryIndicators.unique();
  for(int i = 0; i < numVertices; i++){
    vertexTags[i].sort();
    vertexTags[i].unique();
  }

  // get all the entities in the model
  std::vector<GEntity*> entities;
  getEntities(entities);

  // find max dimension of mesh elements we need to save
  int dim = 0;
  for(unsigned int i = 0; i < entities.size(); i++)
    if(entities[i]->physicals.size() || saveAll)
      for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++)
        dim = std::max(dim, entities[i]->getMeshElement(j)->getDim());
  
  // loop over all elements we need to save
  int numElements = 0, maxNumNodesPerElement = 0;
  for(unsigned int i = 0; i < entities.size(); i++){
    if(entities[i]->physicals.size() || saveAll){
      for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++){
        MElement *e = entities[i]->getMeshElement(j);
        if(e->getStringForDIFF() && e->getDim() == dim){
          numElements++;
          maxNumNodesPerElement = std::max(maxNumNodesPerElement, e->getNumVertices());
        }
      }
    }
  }

  fprintf(fp, "\n\n");
  fprintf(fp, " Finite element mesh (GridFE):\n\n");
  fprintf(fp, " Number of space dim. =   3\n");
  fprintf(fp, " Number of elements   =  %d\n", numElements);
  fprintf(fp, " Number of nodes      =  %d\n\n", numVertices);
  fprintf(fp, " All elements are of the same type : dpTRUE\n");
  fprintf(fp, " Max number of nodes in an element: %d \n", maxNumNodesPerElement);
  fprintf(fp, " Only one subdomain el              : dpFALSE\n");
  fprintf(fp, " Lattice data                     ? 0\n\n\n\n");
  fprintf(fp, " %d Boundary indicators:  ", (int)boundaryIndicators.size());
  for(std::list<int>::iterator it = boundaryIndicators.begin();
      it != boundaryIndicators.end(); it++)
    fprintf(fp, " %d", *it);
  
  fprintf(fp, "\n\n\n");
  fprintf(fp,"  Nodal coordinates and nodal boundary indicators,\n");
  fprintf(fp,"  the columns contain:\n");
  fprintf(fp,"   - node number\n");
  fprintf(fp,"   - coordinates\n");
  fprintf(fp,"   - no of boundary indicators that are set (ON)\n");
  fprintf(fp,"   - the boundary indicators that are set (ON) if any.\n");
  fprintf(fp,"#\n");
  
  // write mesh vertices
  for(unsigned int i = 0; i < entities.size(); i++){
    for(unsigned int j = 0; j < entities[i]->mesh_vertices.size(); j++){
      MVertex *v = entities[i]->mesh_vertices[j];
      if(v->getIndex() > 0){
        v->writeDIFF(fp, binary, scalingFactor);
        fprintf(fp, " [%d] ", (int)vertexTags[v->getIndex() - 1].size());
        for(std::list<int>::iterator it = vertexTags[v->getIndex() - 1].begin();
            it != vertexTags[v->getIndex() - 1].end(); it++)
          fprintf(fp," %d ", *it);
        fprintf(fp,"\n");
      }
    }
  }
  
  fprintf(fp, "\n");
  fprintf(fp, "\n");
  fprintf(fp,     "  Element types and connectivity\n");
  fprintf(fp,     "  the columns contain:\n");
  fprintf(fp,     "   - element number\n");
  fprintf(fp,     "   - element type\n");
  fprintf(fp,     "   - subdomain number \n");
  fprintf(fp,     "   - the global node numbers of the nodes in the element.\n");
  fprintf(fp,     "#\n");

  // write mesh elements
  int num = 0;
  for(unsigned int i = 0; i < entities.size(); i++){
    if(entities[i]->physicals.size() || saveAll){
      for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++){
        MElement *e = entities[i]->getMeshElement(j);
        if(e->getStringForDIFF() && e->getDim() == dim)
          e->writeDIFF(fp, ++num, binary, entities[i]->tag());
      }
    }
  }
  fprintf(fp, "\n");
  
  fclose(fp);
  return 1;
}

GModel *GModel::createGModel(std::map<int, MVertex*> &vertexMap,  
                             std::vector<int> &elementNum,
                             std::vector<std::vector<int> > &vertexIndices,
                             std::vector<int> &elementType,
                             std::vector<int> &physical,
                             std::vector<int> &elementary,
                             std::vector<int> &partition)
{
  GModel *gm = new GModel();
  std::map<int, std::vector<MElement*> > elements[10];
  std::map<int, std::map<int, std::string> > physicals[4];
  std::vector<MVertex*> vertexVector;
  
  int numVertices = (int)vertexMap.size();
  int numElement = (int)elementNum.size();
  
  if(numElement != (int)vertexIndices.size())
    Msg::Error("Dimension in vertices numbers");
  if(numElement != (int)elementType.size())
    Msg::Error("Dimension in elementType numbers");
  if(numElement != (int)physical.size())
    Msg::Error("Dimension in physical numbers");
  if(numElement != (int)elementary.size())
    Msg::Error("Dimension in elementary numbers");
  if(numElement != (int)partition.size())
    Msg::Error("Dimension in partition numbers");

  std::map<int, MVertex*>::const_iterator it = vertexMap.begin();
  std::map<int, MVertex*>::const_iterator end = vertexMap.end();
	
  int maxVertex = std::numeric_limits<int>::min();
  int minVertex = std::numeric_limits<int>::max();
  int num;
	
  for(it; it != end; ++it){
    num = it->first;
    minVertex = std::min(minVertex, num);
    maxVertex = std::max(maxVertex, num);
  }
  if(minVertex == std::numeric_limits<int>::max())
    Msg::Error("Could not determine the min index of vertices");
  
  // If the vertex numbering is dense, tranfer the map into a
  // vector to speed up element creation
  if((minVertex == 1 && maxVertex == numVertices) ||
     (minVertex == 0 && maxVertex == numVertices - 1)){
    Msg::Info("Vertex numbering is dense");
    vertexVector.resize(vertexMap.size() + 1);
    if(minVertex == 1) 
      vertexVector[0] = 0;
    else
      vertexVector[numVertices] = 0;
    std::map<int, MVertex*>::const_iterator it = vertexMap.begin();
    for(; it != vertexMap.end(); ++it)
      vertexVector[it->first] = it->second;
    vertexMap.clear();
  }
  
  int *indices;
  int nbVertices;
  for(int i = 0; i < numElement; ++i){
    num=elementNum[i];
    std::vector<MVertex*> vertices;
    nbVertices = (int)vertexIndices[i].size();
    indices = &vertexIndices[i][0];
    if(vertexVector.size()){
      Msg::Error("Vertex not found aborting");
      if(!getVertices(nbVertices, indices, vertexVector, vertices)){
        delete gm;
        return 0;
      }
    }
    else{
      Msg::Error("Vertex not found aborting");
      if(!getVertices(nbVertices, indices, vertexMap, vertices)){
        delete gm;
        return 0;
      }
    }
    
    createElementMSH(gm, num, elementType[i], physical[i], elementary[i],
                     partition[i], vertices, elements, physicals);
  }
  
  // store the elements in their associated elementary entity. If the
  // entity does not exist, create a new (discrete) one.
  for(int i = 0; i < (int)(sizeof(elements) / sizeof(elements[0])); i++)
    gm->_storeElementsInEntities(elements[i]);
  
  // associate the correct geometrical entity with each mesh vertex
  gm->_associateEntityWithMeshVertices();
  
  // store the vertices in their associated geometrical entity
  if(vertexVector.size())
    gm->_storeVerticesInEntities(vertexVector);
  else
    gm->_storeVerticesInEntities(vertexMap);
  
  // store the physical tags
  for(int i = 0; i < 4; i++)
    gm->_storePhysicalTagsInEntities(i, physicals[i]);
  
  return gm;
}
