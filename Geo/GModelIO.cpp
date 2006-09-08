// $Id: GModelIO.cpp,v 1.45 2006-09-08 02:39:43 geuzaine Exp $
//
// Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include <map>
#include <string>

#include "Message.h"
#include "GmshDefines.h"
#include "gmshRegion.h"
#include "gmshFace.h"
#include "gmshEdge.h"
#include "MElement.h"
#include "SBoundingBox3d.h"

static void swapBytes(char *array, int size, int n)
{
  char *x = new char[size];
  for(int i = 0; i < n; i++) {
    char *a = &array[i * size];
    memcpy(x, a, size);
    for(int c = 0; c < size; c++)
      a[size - 1 - c] = x[c];
  }
  delete [] x;
}

template<class T>
static void addElements(std::vector<T*> &dst, const std::vector<MElement*> &src)
{
  for(unsigned int i = 0; i < src.size(); i++) dst.push_back((T*)src[i]);
}

static void storeElementsInEntities(GModel *m, 
				    std::map<int, std::vector<MElement*> > &map)
{
  std::map<int, std::vector<MElement*> >::const_iterator it = map.begin();
  for(; it != map.end(); ++it){
    if(!it->second.size()) continue;
    int numEdges = it->second[0]->getNumEdges();
    switch(numEdges){
    case 1: 
      {
	GEdge *e = m->edgeByTag(it->first);
	if(!e){
	  e = new gmshEdge(m, it->first);
	  m->add(e);
	}
	addElements(e->lines, it->second);
      }
      break;
    case 3: case 4: 
      {
	GFace *f = m->faceByTag(it->first);
	if(!f){
	  f = new gmshFace(m, it->first);
	  m->add(f);
	}
	if(numEdges == 3) addElements(f->triangles, it->second);
	else addElements(f->quadrangles, it->second);
      }
      break;
    case 6: case 12: case 9: case 8:
      {
	GRegion *r = m->regionByTag(it->first);
	if(!r){
	  r = new gmshRegion(m, it->first);
	  m->add(r);
	}
	if(numEdges == 6) addElements(r->tetrahedra, it->second);
	else if(numEdges == 12) addElements(r->hexahedra, it->second);
	else if(numEdges == 9) addElements(r->prisms, it->second);
	else addElements(r->pyramids, it->second);
      }
      break;
    }
  }
}

template<class T>
static void associateEntityWithVertices(GEntity *ge, std::vector<T*> &elements)
{
  for(unsigned int i = 0; i < elements.size(); i++)
    for(int j = 0; j < elements[i]->getNumVertices(); j++)
      elements[i]->getVertex(j)->setEntity(ge);
}

static void associateEntityWithVertices(GModel *m)
{
  // loop on regions, then on faces, edges and vertices and store the
  // entity pointer in the the elements' vertices (this way we
  // associate the entity of lowest geometrical degree with each
  // vertex)
  for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it){
    associateEntityWithVertices(*it, (*it)->tetrahedra);
    associateEntityWithVertices(*it, (*it)->hexahedra);
    associateEntityWithVertices(*it, (*it)->prisms);
    associateEntityWithVertices(*it, (*it)->pyramids);
  }
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it){
    associateEntityWithVertices(*it, (*it)->triangles);
    associateEntityWithVertices(*it, (*it)->quadrangles);
  }
  for(GModel::eiter it = m->firstEdge(); it != m->lastEdge(); ++it){
    associateEntityWithVertices(*it, (*it)->lines);
  }
  for(GModel::viter it = m->firstVertex(); it != m->lastVertex(); ++it){
    (*it)->mesh_vertices[0]->setEntity(*it);
  }
}

static void storeVerticesInEntities(std::map<int, MVertex*> &vertices)
{
  std::map<int, MVertex*>::const_iterator it = vertices.begin();
  for(; it != vertices.end(); ++it){
    MVertex *v = it->second;
    GEntity *ge = v->onWhat();
    if(ge) 
      ge->mesh_vertices.push_back(v);
    else
      delete v; // we delete all unused vertices
  }
}

static void storeVerticesInEntities(std::vector<MVertex*> &vertices)
{
  for(unsigned int i = 0; i < vertices.size(); i++){
    MVertex *v = vertices[i];
    if(v){ // the vector can have null entries (first or last element)
      GEntity *ge = v->onWhat();
      if(ge) 
	ge->mesh_vertices.push_back(v);
      else
	delete v; // we delete all unused vertices
    }
  }
}

static void storePhysicalTagsInEntities(GModel *m, int dim,
					std::map<int, std::map<int, std::string> > &map)
{
  std::map<int, std::map<int, std::string> >::const_iterator it = map.begin();
  for(; it != map.end(); ++it){
    GEntity *ge = 0;
    switch(dim){
    case 0: ge = m->vertexByTag(it->first); break;
    case 1: ge = m->edgeByTag(it->first); break;
    case 2: ge = m->faceByTag(it->first); break;
    case 3: ge = m->regionByTag(it->first); break;
    }
    if(ge){
      std::map<int, std::string>::const_iterator it2 = it->second.begin();
      for(; it2 != it->second.end(); ++it2)
	ge->physicals.push_back(it2->first);
    }
  }
}

static bool checkVertexIndex(int index, std::map<int, MVertex*> &map)
{
  if(!map.count(index)){
    Msg(GERROR, "Wrong vertex index %d", index);
    return false;
  }
  return true;
}

static bool checkVertexIndex(int index, std::vector<MVertex*> &vec)
{
  if(index < 0 || index > (int)(vec.size() - 1)){
    Msg(GERROR, "Wrong vertex index %d", index);
    return false;
  }
  return true;
}

static int getNumVerticesForElementTypeMSH(int type)
{
  switch (type) {
  case PNT_1  : return 1;
  case LIN_2  : return 2;
  case LIN_3  : return 2 + 1;
  case TRI_3  : return 3;
  case TRI_6  : return 3 + 3;
  case QUA_4  : return 4;
  case QUA_8  : return 4 + 4;
  case QUA_9  : return 4 + 4 + 1;
  case TET_4  : return 4;
  case TET_10 : return 4 + 6;
  case HEX_8  : return 8;
  case HEX_20 : return 8 + 12;
  case HEX_27 : return 8 + 12 + 6 + 1;
  case PRI_6  : return 6;
  case PRI_15 : return 6 + 9;
  case PRI_18 : return 6 + 9 + 3;
  case PYR_5  : return 5;
  case PYR_13 : return 5 + 8;
  case PYR_14 : return 5 + 8 + 1;
  default: 
    Msg(GERROR, "Unknown type of element %d", type);
    return 0;
  }
}

template<class T>
static void createElementMSH(GModel *m, int num, int type, int physical, 
			     int elementary, int partition, int n[30], T &v, 
			     std::map<int, std::vector<MVertex*> > &points,
			     std::map<int, std::vector<MElement*> > elements[7],
			     std::map<int, std::map<int, std::string> > physicals[4])
{
  int dim = 0;

  switch (type) {
  case PNT_1:
    points[elementary].push_back(v[n[0]]);
    dim = 0;
    break;
  case LIN_2:
    elements[0][elementary].push_back
      (new MLine(v[n[0]], v[n[1]], num, partition));
    dim = 1;
    break;
  case LIN_3:
    elements[0][elementary].push_back
      (new MLine3(v[n[0]], v[n[1]], v[n[2]], num, partition));
    dim = 1;
    break;
  case TRI_3:
    elements[1][elementary].push_back
      (new MTriangle(v[n[0]], v[n[1]], v[n[2]], num, partition));
    dim = 2;
    break;
  case TRI_6:
    elements[1][elementary].push_back
      (new MTriangle6(v[n[0]], v[n[1]], v[n[2]], v[n[3]], v[n[4]], v[n[5]], 
		      num, partition));
    dim = 2;
    break;
  case QUA_4:
    elements[2][elementary].push_back
      (new MQuadrangle(v[n[0]], v[n[1]], v[n[2]], v[n[3]], num, partition));
    dim = 2;
    break;
  case QUA_8:
    elements[2][elementary].push_back
      (new MQuadrangle8(v[n[0]], v[n[1]], v[n[2]], v[n[3]], v[n[4]], v[n[5]], 
			v[n[6]], v[n[7]], num, partition));
    dim = 2;
    break;
  case QUA_9:
    elements[2][elementary].push_back
      (new MQuadrangle9(v[n[0]], v[n[1]], v[n[2]], v[n[3]], v[n[4]], v[n[5]], 
			v[n[6]], v[n[7]], v[n[8]], num, partition));
    dim = 2;
    break;
  case TET_4:
    elements[3][elementary].push_back
      (new MTetrahedron(v[n[0]], v[n[1]], v[n[2]], v[n[3]], num, partition));
    dim = 3; 
    break;
  case TET_10:
    elements[3][elementary].push_back
      (new MTetrahedron10(v[n[0]], v[n[1]], v[n[2]], v[n[3]], v[n[4]], v[n[5]], 
			  v[n[6]], v[n[7]], v[n[8]], v[n[9]], num, partition));
    dim = 3; 
    break;
  case HEX_8:
    elements[4][elementary].push_back
      (new MHexahedron(v[n[0]], v[n[1]], v[n[2]], v[n[3]], v[n[4]], v[n[5]], 
		       v[n[6]], v[n[7]], num, partition));
    dim = 3; 
    break;
  case HEX_20:
    elements[4][elementary].push_back
      (new MHexahedron20(v[n[0]], v[n[1]], v[n[2]], v[n[3]], v[n[4]], v[n[5]], 
			 v[n[6]], v[n[7]], v[n[8]], v[n[9]], v[n[10]], v[n[11]], 
			 v[n[12]], v[n[13]], v[n[14]], v[n[15]], v[n[16]], v[n[17]], 
			 v[n[18]], v[n[19]], num, partition));
    dim = 3; 
    break;
  case HEX_27:
    elements[4][elementary].push_back
      (new MHexahedron27(v[n[0]], v[n[1]], v[n[2]], v[n[3]], v[n[4]], v[n[5]], 
			 v[n[6]], v[n[7]], v[n[8]], v[n[9]], v[n[10]], v[n[11]], 
			 v[n[12]], v[n[13]], v[n[14]], v[n[15]], v[n[16]], v[n[17]], 
			 v[n[18]], v[n[19]], v[n[20]], v[n[21]], v[n[22]], v[n[23]], 
			 v[n[24]], v[n[25]], v[n[26]], num, partition));
    dim = 3; 
    break;
  case PRI_6: 
    elements[5][elementary].push_back
      (new MPrism(v[n[0]], v[n[1]], v[n[2]], v[n[3]], v[n[4]], v[n[5]], 
		  num, partition));
    dim = 3; 
    break;
  case PRI_15: 
    elements[5][elementary].push_back
      (new MPrism15(v[n[0]], v[n[1]], v[n[2]], v[n[3]], v[n[4]], v[n[5]], 
		    v[n[6]], v[n[7]], v[n[8]], v[n[9]], v[n[10]], v[n[11]], 
		    v[n[12]], v[n[13]], v[n[14]], num, partition));
    dim = 3; 
    break;
  case PRI_18: 
    elements[5][elementary].push_back
      (new MPrism18(v[n[0]], v[n[1]], v[n[2]], v[n[3]], v[n[4]], v[n[5]], 
		    v[n[6]], v[n[7]], v[n[8]], v[n[9]], v[n[10]], v[n[11]], 
		    v[n[12]], v[n[13]], v[n[14]], v[n[15]], v[n[16]], v[n[17]], 
		    num, partition));
    dim = 3; 
    break;
  case PYR_5: 
    elements[6][elementary].push_back
      (new MPyramid(v[n[0]], v[n[1]], v[n[2]], v[n[3]], v[n[4]], num, partition));
    dim = 3; 
    break;
  case PYR_13: 
    elements[6][elementary].push_back
      (new MPyramid13(v[n[0]], v[n[1]], v[n[2]], v[n[3]], v[n[4]], v[n[5]], 
		      v[n[6]], v[n[7]], v[n[8]], v[n[9]], v[n[10]], v[n[11]], 
		      v[n[12]], num, partition));
    dim = 3; 
    break;
  case PYR_14: 
    elements[6][elementary].push_back
      (new MPyramid14(v[n[0]], v[n[1]], v[n[2]], v[n[3]], v[n[4]], v[n[5]], 
		      v[n[6]], v[n[7]], v[n[8]], v[n[9]], v[n[10]], v[n[11]], 
		      v[n[12]], v[n[13]], num, partition));
    dim = 3; 
    break;
  default:
    Msg(GERROR, "Unknown type (%d) for element %d", type, num); 
    break;
  }
  
  if(physical && (!physicals[dim].count(elementary) || 
		  !physicals[dim][elementary].count(physical)))
    physicals[dim][elementary][physical] = "unnamed";
  
  if(partition) m->getMeshPartitions().insert(partition);
}

int GModel::readMSH(const std::string &name)
{
  FILE *fp = fopen(name.c_str(), "rb");
  if(!fp){
    Msg(GERROR, "Unable to open file '%s'", name.c_str());
    return 0;
  }

  double version = 1.0;
  bool binary = false, swap = false;
  char str[256];
  std::map<int, MVertex*> vertexMap;
  std::vector<MVertex*> vertexVector;
  std::map<int, std::vector<MVertex*> > points;
  std::map<int, std::vector<MElement*> > elements[7];
  std::map<int, std::map<int, std::string> > physicals[4];

  while(1) {

    do {
      if(!fgets(str, sizeof(str), fp) || feof(fp))
        break;
    } while(str[0] != '$');

    if(feof(fp))
      break;

    if(!strncmp(&str[1], "MeshFormat", 10)) {

      if(!fgets(str, sizeof(str), fp)) return 0;
      int format, size;
      if(sscanf(str, "%lf %d %d", &version, &format, &size) != 3) return 0;

      if(format){
	binary = true;
	Msg(INFO, "Mesh is in binary format");
	int one;
	if(fread(&one, sizeof(int), 1, fp) != 1) return 0;
	if(one != 1){
	  swap = true;
	  Msg(INFO, "Swapping bytes from binary file");
	}
      }

    }
    else if(!strncmp(&str[1], "NO", 2) || !strncmp(&str[1], "Nodes", 5)) {

      if(!fgets(str, sizeof(str), fp)) return 0;
      int numVertices;
      if(sscanf(str, "%d", &numVertices) != 1) return 0;
      Msg(INFO, "%d vertices", numVertices);

      int progress = (numVertices > 100000) ? numVertices / 25 : 0;
      int minVertex = numVertices + 1, maxVertex = -1;
      for(int i = 0; i < numVertices; i++) {
	int num;
	double xyz[3];
	if(!binary){
	  if(fscanf(fp, "%d %lf %lf %lf", &num, &xyz[0], &xyz[1], &xyz[2]) != 4) return 0;
	}
	else{
	  if(fread(&num, sizeof(int), 1, fp) != 1) return 0;
	  if(swap) swapBytes((char*)&num, sizeof(int), 1);
	  if(fread(xyz, sizeof(double), 3, fp) != 3) return 0;
	  if(swap) swapBytes((char*)&xyz, sizeof(double), 3);
	}
	minVertex = std::min(minVertex, num);
	maxVertex = std::max(maxVertex, num);
	if(vertexMap.count(num))
	  Msg(WARNING, "Skipping duplicate vertex %d", num);
	else
	  vertexMap[num] = new MVertex(xyz[0], xyz[1], xyz[2]);
	if(progress && (i % progress == progress - 1))
	  Msg(PROGRESS, "Read %d vertices", i + 1);
      }
      if(progress) Msg(PROGRESS, "");
      
      // If the vertex numbering is dense, tranfer the map into a
      // vector to speed up element creation
      if((int)vertexMap.size() == numVertices && 
	 ((minVertex == 1 && maxVertex == numVertices) ||
	  (minVertex == 0 && maxVertex == numVertices - 1))){
	Msg(INFO, "Vertex numbering is dense");
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
      sscanf(str, "%d", &numElements);
      Msg(INFO, "%d elements", numElements);

      int progress = (numElements > 100000) ? numElements / 25 : 0;
      if(!binary){
	for(int i = 0; i < numElements; i++) {
	  int num, type, physical = 0, elementary = 0, partition = 0, numVertices;
	  if(version <= 1.0){
	    fscanf(fp, "%d %d %d %d %d", &num, &type, &physical, &elementary, &numVertices);
	    if(numVertices != getNumVerticesForElementTypeMSH(type)) return 0;
	  }
	  else{
	    int numTags;
	    fscanf(fp, "%d %d %d", &num, &type, &numTags);
	    for(int j = 0; j < numTags; j++){
	      int tag;
	      fscanf(fp, "%d", &tag);	    
	      if(j == 0)      physical = tag;
	      else if(j == 1) elementary = tag;
	      else if(j == 2) partition = tag;
	      // ignore any other tags for now
	    }
	    if(!(numVertices = getNumVerticesForElementTypeMSH(type))) return 0;
	  }
	  int indices[30];
	  for(int j = 0; j < numVertices; j++) fscanf(fp, "%d", &indices[j]);
	  if(vertexVector.size()){
	    for(int j = 0; j < numVertices; j++)
	      if(!checkVertexIndex(indices[j], vertexVector)) return 0;
	    createElementMSH(this, num, type, physical, elementary, partition, 
			     indices, vertexVector, points, elements, physicals);
	  }
	  else{
	    for(int j = 0; j < numVertices; j++)
	      if(!checkVertexIndex(indices[j], vertexMap)) return 0;
	    createElementMSH(this, num, type, physical, elementary, partition, 
			     indices, vertexMap, points, elements, physicals);
	  }
	  if(progress && (i % progress == progress - 1))
	    Msg(PROGRESS, "Read %d elements", i + 1);
	}
      }
      else{
	int numElementsPartial = 0;
	while(numElementsPartial < numElements){
	  int header[3];
	  if(fread(header, sizeof(int), 3, fp) != 3) return 0;
	  if(swap) swapBytes((char*)&header, sizeof(int), 3);
	  int type = header[0];
	  int numElms = header[1];
	  int numTags = header[2];
	  int numVertices = getNumVerticesForElementTypeMSH(type);
	  unsigned int n = 1 + numTags + numVertices;
	  int *data = new int[n];
	  for(int i = 0; i < numElms; i++) {
	    if(fread(data, sizeof(int), n, fp) != n) return 0;
	    if(swap) swapBytes((char*)&data, sizeof(int), n);
	    int num = data[0];
	    int physical = (numTags > 0) ? data[4 - numTags] : 0;
	    int elementary = (numTags > 1) ? data[4 - numTags + 1] : 0;
	    int partition = (numTags > 2) ? data[4 - numTags + 2] : 0;
	    int *indices = &data[numTags + 1];
	    if(vertexVector.size()){
	      for(int j = 0; j < numVertices; j++)
		if(!checkVertexIndex(indices[j], vertexVector)) return 0;
	      createElementMSH(this, num, type, physical, elementary, partition,
			       indices, vertexVector, points, elements, physicals);
	    }
	    else{
	      for(int j = 0; j < numVertices; j++)
		if(!checkVertexIndex(indices[j], vertexMap)) return 0;
	      createElementMSH(this, num, type, physical, elementary, partition, 
			       indices, vertexMap, points, elements, physicals);
	    }
	    if(progress && ((numElementsPartial + i) % progress == progress - 1))
	      Msg(PROGRESS, "Read %d elements", i + 1);
	  }
	  delete [] data;
	  numElementsPartial += numElms;
	}
      }
      if(progress) Msg(PROGRESS, "");

    }

    do {
      if(!fgets(str, sizeof(str), fp) || feof(fp))
	Msg(GERROR, "Prematured end of mesh file");
    } while(str[0] != '$');

  }

  // store the elements in their associated elementary entity. If the
  // entity does not exist, create a new one.
  for(int i = 0; i < (int)(sizeof(elements)/sizeof(elements[0])); i++) 
    storeElementsInEntities(this, elements[i]);

  // treat points separately
  {
    std::map<int, std::vector<MVertex*> >::const_iterator it = points.begin();
    for(; it != points.end(); ++it){
      GVertex *v = vertexByTag(it->first);
      if(!v){
	v = new gmshVertex(this, it->first);
	add(v);
      }
      for(unsigned int i = 0; i < it->second.size(); i++) 
	v->mesh_vertices.push_back(it->second[i]);
    }
  }

  // associate the correct geometrical entity with each mesh vertex
  associateEntityWithVertices(this);

  // special case for geometry vertices: now that the correct
  // geometrical entity has been associated with the vertices, we
  // reset mesh_vertices so that it can be filled again below
  for(viter it = firstVertex(); it != lastVertex(); ++it)
    (*it)->mesh_vertices.clear();

  // store the vertices in their associated geometrical entity
  if(vertexVector.size())
    storeVerticesInEntities(vertexVector);
  else
    storeVerticesInEntities(vertexMap);

  // store the physical tags
  for(int i = 0; i < 4; i++)  
    storePhysicalTagsInEntities(this, i, physicals[i]);

  fclose(fp);
  return 1;
}

static void writeElementHeaderMSH(bool binary, FILE *fp, std::map<int,int> &elements,
				  int t1, int t2=0, int t3=0)
{
  if(!binary) return;

  int numTags = 3;
  int data[3];
  if(elements.count(t1)){
    data[0] = t1;  data[1] = elements[t1];  data[2] = numTags;
    fwrite(data, sizeof(int), 3, fp);
  }
  else if(t2 && elements.count(t2)){
    data[0] = t2;  data[1] = elements[t2];  data[2] = numTags;
    fwrite(data, sizeof(int), 3, fp);
  }
  else if(t3 && elements.count(t3)){
    data[0] = t3;  data[1] = elements[t3];  data[2] = numTags;
    fwrite(data, sizeof(int), 3, fp);
  }
}

template<class T>
static void writeElementsMSH(FILE *fp, const std::vector<T*> &ele, int saveAll, 
			     double version, bool binary, int &num, int elementary, 
			     std::vector<int> &physicals)
{
  for(unsigned int i = 0; i < ele.size(); i++)
    if(saveAll)
      ele[i]->writeMSH(fp, version, binary, ++num, elementary, 0);
    else
      for(unsigned int j = 0; j < physicals.size(); j++)
	ele[i]->writeMSH(fp, version, binary, ++num, elementary, physicals[j]);
}

int GModel::writeMSH(const std::string &name, double version, bool binary, 
		     bool saveAll, double scalingFactor)
{
  FILE *fp = fopen(name.c_str(), binary ? "wb" : "w");
  if(!fp){
    Msg(GERROR, "Unable to open file '%s'", name.c_str());
    return 0;
  }

  // binary format exists only in version 2
  if(binary) version = 2.0;

  // if there are no physicals we save all the elements
  if(noPhysicalGroups()) saveAll = true;

  // get the number of vertices and renumber the vertices in a
  // continuous sequence
  int numVertices = renumberMeshVertices();
  
  // get the number of elements (we assume that all the elements in a
  // list have the same type, i.e., they are all of the same
  // polynomial order)
  std::map<int,int> elements;
  for(viter it = firstVertex(); it != lastVertex(); ++it){
    int p = (saveAll ? 1 : (*it)->physicals.size());
    int n = p * (*it)->mesh_vertices.size();
    if(n) elements[PNT_1] += n;
  }
  for(eiter it = firstEdge(); it != lastEdge(); ++it){
    int p = (saveAll ? 1 : (*it)->physicals.size());
    int n = p * (*it)->lines.size();
    if(n) elements[(*it)->lines[0]->getTypeForMSH()] += n;
  }
  for(fiter it = firstFace(); it != lastFace(); ++it){
    int p = (saveAll ? 1 : (*it)->physicals.size());
    int n = p * (*it)->triangles.size();
    if(n) elements[(*it)->triangles[0]->getTypeForMSH()] += n;
    n = p * (*it)->quadrangles.size();
    if(n) elements[(*it)->quadrangles[0]->getTypeForMSH()] += n;
  }
  for(riter it = firstRegion(); it != lastRegion(); ++it){
    int p = (saveAll ? 1 : (*it)->physicals.size());
    int n = p * (*it)->tetrahedra.size();
    if(n) elements[(*it)->tetrahedra[0]->getTypeForMSH()] += n;
    n = p * (*it)->hexahedra.size();
    if(n) elements[(*it)->hexahedra[0]->getTypeForMSH()] += n;
    n = p * (*it)->prisms.size();
    if(n) elements[(*it)->prisms[0]->getTypeForMSH()] += n;
    n = p * (*it)->pyramids.size();
    if(n) elements[(*it)->pyramids[0]->getTypeForMSH()] += n;
  }

  int numElements = 0;
  std::map<int,int>::const_iterator it = elements.begin();
  for(; it != elements.end(); ++it)
    numElements += it->second;

  if(version >= 2.0){
    fprintf(fp, "$MeshFormat\n");
    fprintf(fp, "%g %d %d\n", version, binary ? 1 : 0, (int)sizeof(double));
    if(binary){
      int one = 1;
      fwrite(&one, sizeof(int), 1, fp);
      fprintf(fp, "\n");
    }
    fprintf(fp, "$EndMeshFormat\n");
    fprintf(fp, "$Nodes\n");
  }
  else
    fprintf(fp, "$NOD\n");

  fprintf(fp, "%d\n", numVertices);
  for(viter it = firstVertex(); it != lastVertex(); ++it)
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++) 
      (*it)->mesh_vertices[i]->writeMSH(fp, binary, scalingFactor);
  for(eiter it = firstEdge(); it != lastEdge(); ++it)
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++)
      (*it)->mesh_vertices[i]->writeMSH(fp, binary, scalingFactor);
  for(fiter it = firstFace(); it != lastFace(); ++it)
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++) 
      (*it)->mesh_vertices[i]->writeMSH(fp, binary, scalingFactor);
  for(riter it = firstRegion(); it != lastRegion(); ++it)
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++) 
      (*it)->mesh_vertices[i]->writeMSH(fp, binary, scalingFactor);

  if(binary) fprintf(fp, "\n");

  if(version >= 2.0){
    fprintf(fp, "$EndNodes\n");
    fprintf(fp, "$Elements\n");
  }
  else{
    fprintf(fp, "$ENDNOD\n");
    fprintf(fp, "$ELM\n");
  }

  fprintf(fp, "%d\n", numElements);
  int num = 0;

  writeElementHeaderMSH(binary, fp, elements, PNT_1);
  for(viter it = firstVertex(); it != lastVertex(); ++it)
    writeElementsMSH(fp, (*it)->mesh_vertices, saveAll, version, binary, num,
		     (*it)->tag(), (*it)->physicals);
  writeElementHeaderMSH(binary, fp, elements, LIN_2, LIN_3);
  for(eiter it = firstEdge(); it != lastEdge(); ++it)
    writeElementsMSH(fp, (*it)->lines, saveAll, version, binary, num,
		     (*it)->tag(), (*it)->physicals);
  writeElementHeaderMSH(binary, fp, elements, TRI_3, TRI_6);
  for(fiter it = firstFace(); it != lastFace(); ++it)
    writeElementsMSH(fp, (*it)->triangles, saveAll, version, binary, num,
		     (*it)->tag(), (*it)->physicals);
  writeElementHeaderMSH(binary, fp, elements, QUA_4, QUA_9, QUA_8);
  for(fiter it = firstFace(); it != lastFace(); ++it)
    writeElementsMSH(fp, (*it)->quadrangles, saveAll, version, binary, num,
		     (*it)->tag(), (*it)->physicals);
  writeElementHeaderMSH(binary, fp, elements, TET_4, TET_10);
  for(riter it = firstRegion(); it != lastRegion(); ++it)
    writeElementsMSH(fp, (*it)->tetrahedra, saveAll, version, binary, num,
		     (*it)->tag(), (*it)->physicals);
  writeElementHeaderMSH(binary, fp, elements, HEX_8, HEX_27, HEX_20);
  for(riter it = firstRegion(); it != lastRegion(); ++it)
    writeElementsMSH(fp, (*it)->hexahedra, saveAll, version, binary, num,
		     (*it)->tag(), (*it)->physicals);
  writeElementHeaderMSH(binary, fp, elements, PRI_6, PRI_18, PRI_15);
  for(riter it = firstRegion(); it != lastRegion(); ++it)
    writeElementsMSH(fp, (*it)->prisms, saveAll, version, binary, num,
		     (*it)->tag(), (*it)->physicals);
  writeElementHeaderMSH(binary, fp, elements, PYR_5, PYR_14, PYR_13);
  for(riter it = firstRegion(); it != lastRegion(); ++it)
    writeElementsMSH(fp, (*it)->pyramids, saveAll, version, binary, num,
		     (*it)->tag(), (*it)->physicals);
  
  if(binary) fprintf(fp, "\n");

  if(version >= 2.0){
    fprintf(fp, "$EndElements\n");
  }
  else{
    fprintf(fp, "$ENDELM\n");
  }

  fclose(fp);
  return 1;
}

int GModel::writePOS(const std::string &name, double scalingFactor)
{
  FILE *fp = fopen(name.c_str(), "w");
  if(!fp){
    Msg(GERROR, "Unable to open file '%s'", name.c_str());
    return 0;
  }

  if(numRegion()){
    fprintf(fp, "View \"Volumes\" {\n");
    fprintf(fp, "T2(1.e5,30,%d){\"Elementary Entity\", \"Element Number\", "
	    "\"Gamma\", \"Eta\", \"Rho\"};\n", (1<<16)|(4<<8));
    for(riter it = firstRegion(); it != lastRegion(); ++it) {
      for(unsigned int i = 0; i < (*it)->tetrahedra.size(); i++)
	(*it)->tetrahedra[i]->writePOS(fp, scalingFactor, (*it)->tag());
      for(unsigned int i = 0; i < (*it)->hexahedra.size(); i++)
	(*it)->hexahedra[i]->writePOS(fp, scalingFactor, (*it)->tag());
      for(unsigned int i = 0; i < (*it)->prisms.size(); i++)
	(*it)->prisms[i]->writePOS(fp, scalingFactor, (*it)->tag());
      for(unsigned int i = 0; i < (*it)->pyramids.size(); i++)
	(*it)->pyramids[i]->writePOS(fp, scalingFactor, (*it)->tag());
    }
    fprintf(fp, "};\n");
  }
  
  if(numFace()){
    fprintf(fp, "View \"Surfaces\" {\n");
    fprintf(fp, "T2(1.e5,30,%d){\"Elementary Entity\", \"Element Number\", "
	    "\"Gamma\", \"Eta\", \"Rho\"};\n", (1<<16)|(4<<8));
    for(fiter it = firstFace(); it != lastFace(); ++it) {
      for(unsigned int i = 0; i < (*it)->triangles.size(); i++)
	(*it)->triangles[i]->writePOS(fp, scalingFactor, (*it)->tag());
      for(unsigned int i = 0; i < (*it)->quadrangles.size(); i++)
	(*it)->quadrangles[i]->writePOS(fp, scalingFactor, (*it)->tag());
    }
    fprintf(fp, "};\n");
  }

  if(numEdge()){
    fprintf(fp, "View \"Lines\" {\n");
    fprintf(fp, "T2(1.e5,30,%d){\"Elementary Entity\", \"Element Number\", "
	    "\"Gamma\", \"Eta\", \"Rho\"};\n", (1<<16)|(4<<8));
    for(eiter it = firstEdge(); it != lastEdge(); ++it) {
      for(unsigned int i = 0; i < (*it)->lines.size(); i++)
 	(*it)->lines[i]->writePOS(fp, scalingFactor, (*it)->tag());
    }
    fprintf(fp, "};\n");
  }

  fclose(fp);
  return 1;
}

int GModel::readSTL(const std::string &name, double tolerance)
{
  FILE *fp = fopen(name.c_str(), "rb");
  if(!fp){
    Msg(GERROR, "Unable to open file '%s'", name.c_str());
    return 0;
  }

  // read all facets and store triplets of points
  std::vector<SPoint3> points;
  SBoundingBox3d bbox;

  // "solid", or binary data header
  char buffer[256];
  fgets(buffer, sizeof(buffer), fp);

  if(!strncmp(buffer, "solid", 5)) { 
    // ASCII STL
    while(!feof(fp)) {
      // "facet normal x y z", or "endsolid"
      if(!fgets(buffer, sizeof(buffer), fp)) break;
      if(!strncmp(buffer, "endsolid", 8)) break;
      char s1[256], s2[256];
      float x, y, z;
      sscanf(buffer, "%s %s %f %f %f", s1, s2, &x, &y, &z);
      // "outer loop"
      if(!fgets(buffer, sizeof(buffer), fp)) break;
      // "vertex x y z"
      for(int i = 0; i < 3; i++){
	if(!fgets(buffer, sizeof(buffer), fp)) break;
	sscanf(buffer, "%s %f %f %f", s1, &x, &y, &z);
	SPoint3 p(x, y, z);
	points.push_back(p);
	bbox += p;
      }
      // "endloop"
      if(!fgets(buffer, sizeof(buffer), fp)) break;
      // "endfacet"
      if(!fgets(buffer, sizeof(buffer), fp)) break;
    }
  }
  else{
    // Binary STL
    Msg(INFO, "Mesh is in binary format");
    rewind(fp);
    char header[80];
    if(fread(header, sizeof(char), 80, fp)){
      unsigned int nfacets = 0;
      size_t ret = fread(&nfacets, sizeof(unsigned int), 1, fp);
      bool swap = false;
      if(nfacets > 10000000){
	Msg(INFO, "Swapping bytes from binary file");
	swap = true;
	swapBytes((char*)&nfacets, sizeof(unsigned int), 1);
      }
      if(ret && nfacets){
	char *data = new char[nfacets * 50 * sizeof(char)];
	ret = fread(data, sizeof(char), nfacets * 50, fp);
	if(ret == nfacets * 50){
	  for(unsigned int i = 0; i < nfacets; i++) {
	    float *xyz = (float *)&data[i * 50 * sizeof(char)];
	    if(swap) swapBytes((char*)xyz, sizeof(float), 12);
	    for(int j = 0; j < 3; j++){
	      SPoint3 p(xyz[3 + 3 * j], xyz[3 + 3 * j + 1], xyz[3 + 3 * j + 2]);
	      points.push_back(p);
	      bbox += p;
	    }
	  }
	}
	delete data;
      }
    }
  }

  if(!points.size()){
    Msg(GERROR, "No facets found in STL file");
    return 0;
  }
  
  if(points.size() % 3){
    Msg(GERROR, "Wrong number of points in STL file");
    return 0;
  }

  Msg(INFO, "%d facets", points.size() / 3);

  // create face
  GFace *face = new gmshFace(this, numFace() + 1);
  add(face);

  // create (unique) vertices and triangles
  double lc = norm(SVector3(bbox.max(), bbox.min()));
  MVertexLessThanLexicographic::tolerance = lc * tolerance;
  std::set<MVertex*, MVertexLessThanLexicographic> vertices;
  for(unsigned int i = 0; i < points.size(); i += 3){
    MVertex *v[3];
    for(int j = 0; j < 3; j++){
      double x = points[i + j].x(), y = points[i + j].y(), z = points[i + j].z();
      MVertex w(x, y, z);
      std::set<MVertex*, MVertexLessThanLexicographic>::iterator it = vertices.find(&w);
      if(it != vertices.end()) {
        v[j] = *it;
      }
      else {
        v[j] = new MVertex(x, y, z);
	vertices.insert(v[j]);
	face->mesh_vertices.push_back(v[j]);
      }
    }
    face->triangles.push_back(new MTriangle(v[0], v[1], v[2]));
  }

  fclose(fp);
  return 1;
}

int GModel::writeSTL(const std::string &name, bool binary, double scalingFactor)
{
  FILE *fp = fopen(name.c_str(), binary ? "wb" : "w");
  if(!fp){
    Msg(GERROR, "Unable to open file '%s'", name.c_str());
    return 0;
  }

  if(!binary)
    fprintf(fp, "solid Created by Gmsh\n");
  else{
    char header[80];
    strncpy(header, "Created by Gmsh", 80);
    fwrite(header, sizeof(char), 80, fp);
    unsigned int nfacets = 0;
    for(fiter it = firstFace(); it != lastFace(); ++it)
      nfacets += (*it)->triangles.size() + 2 * (*it)->quadrangles.size();
    fwrite(&nfacets, sizeof(unsigned int), 1, fp);
  }
    
  for(fiter it = firstFace(); it != lastFace(); ++it) {
    for(unsigned int i = 0; i < (*it)->triangles.size(); i++)
      (*it)->triangles[i]->writeSTL(fp, binary, scalingFactor);
    for(unsigned int i = 0; i < (*it)->quadrangles.size(); i++)
      (*it)->quadrangles[i]->writeSTL(fp, binary, scalingFactor);
  }

  if(!binary)
    fprintf(fp, "endsolid Created by Gmsh\n");
  
  fclose(fp);
  return 1;
}

static int skipUntil(FILE *fp, char *key)
{
  char str[256];
  while(fscanf(fp, "%s", str)){
    if(!strcmp(str, key)) return 1;
  }
  return 0;
}

static int readVerticesVRML(FILE *fp, std::map<int, MVertex*> &vertices,
			    std::vector<MVertex*> &allvertices)
{
  double x, y, z;
  if(fscanf(fp, " [ %lf %lf %lf", &x, &y, &z) != 3) return 0;
  int num = 0;
  vertices[num++] = new MVertex(x, y, z);
  while(fscanf(fp, " , %lf %lf %lf", &x, &y, &z) == 3)
    vertices[num++] = new MVertex(x, y, z);
  for(unsigned int i = 0; i < vertices.size(); i++)
    allvertices.push_back(vertices[i]);
  Msg(INFO, "%d vertices", vertices.size());
  return 1;
}

static int readElementsVRML(FILE *fp, std::map<int, MVertex*> &v, int region,
			    std::map<int, std::vector<MElement*> > elements[3], 
			    bool strips=false)
{
  int i;
  std::vector<int> idx;
  if(fscanf(fp, " [ %d", &i) != 1) return 0;
  idx.push_back(i);
  while(fscanf(fp, " , %d", &i) == 1){
    if(i != -1){
      idx.push_back(i);
    }
    else{
      for(unsigned int j = 0; j < idx.size(); j++)
	if(!checkVertexIndex(idx[j], v)) return 0;
      
      if(idx.size() < 2){
	Msg(INFO, "Skipping %d-vertex element", (int)idx.size());
      }
      else if(idx.size() == 2){
	elements[0][region].push_back(new MLine(v[idx[0]], v[idx[1]]));
      }
      else if(idx.size() == 3){
	elements[1][region].push_back
	  (new MTriangle(v[idx[0]], v[idx[1]], v[idx[2]]));
      }
      else if(!strips && idx.size() == 4){
	elements[2][region].push_back
	  (new MQuadrangle(v[idx[0]], v[idx[1]], v[idx[2]], v[idx[3]]));
      }
      else if(strips){ // triangle strip
	for(unsigned int j = 2; j < idx.size(); j++){
	  if(j % 2)
	    elements[1][region].push_back
	      (new MTriangle(v[idx[j]], v[idx[j - 1]], v[idx[j - 2]]));
	  else
	    elements[1][region].push_back
	      (new MTriangle(v[idx[j - 2]], v[idx[j - 1]], v[idx[j]]));
	}
      }
      else{ // import polygon as triangle fan
	for(unsigned int j = 2; j < idx.size(); j++){
	  elements[1][region].push_back
	    (new MTriangle(v[idx[0]], v[idx[j-1]], v[idx[j]]));
	}
      }
      idx.clear();
    }
  }
  if(idx.size()){
    Msg(GERROR, "Prematured end of VRML file");
    return 0;
  }
  Msg(INFO, "%d elements", elements[0][region].size() + 
      elements[1][region].size() + elements[2][region].size());
  return 1;
}

int GModel::readVRML(const std::string &name)
{
  FILE *fp = fopen(name.c_str(), "r");
  if(!fp){
    Msg(GERROR, "Unable to open file '%s'", name.c_str());
    return 0;
  }

  // This is by NO means a complete VRML/Inventor parser (but it's
  // sufficient for reading simple Inventor files... which is all I
  // need)
  std::map<int, MVertex*> vertices;
  std::vector<MVertex*> allvertices;
  std::map<int, std::vector<MElement*> > elements[3];
  int region = 0;
  char buffer[256], str[256];
  while(!feof(fp)) {
    if(!fgets(buffer, sizeof(buffer), fp)) break;
    if(buffer[0] != '#'){ // skip comments
      sscanf(buffer, "%s", str);
      if(!strcmp(str, "IndexedTriangleStripSet")){
	region++;
	vertices.clear();
	if(!skipUntil(fp, "vertex")) break;
	if(!readVerticesVRML(fp, vertices, allvertices)) break;
	if(!skipUntil(fp, "coordIndex")) break;
	if(!readElementsVRML(fp, vertices, region, elements, true)) break;
      }
      else if(!strcmp(str, "Coordinate3")){
	vertices.clear();
	if(!skipUntil(fp, "point")) break;
	if(!readVerticesVRML(fp, vertices, allvertices)) break;
      }
      else if(!strcmp(str, "IndexedFaceSet") || !strcmp(str, "IndexedLineSet")){
	region++;
	if(!skipUntil(fp, "coordIndex")) break;
	if(!readElementsVRML(fp, vertices, region, elements)) break;
      }
      else if(!strcmp(str, "DEF")){
	char str1[256], str2[256];
	if(!sscanf(buffer, "%s %s %s", str1, str2, str)) break;
	if(!strcmp(str, "IndexedFaceSet") || !strcmp(str, "IndexedLineSet")){
	  region++;
	  if(!skipUntil(fp, "coordIndex")) break;
	  if(!readElementsVRML(fp, vertices, region, elements)) break;
	}
      }
    }
  }

  for(int i = 0; i < (int)(sizeof(elements)/sizeof(elements[0])); i++) 
    storeElementsInEntities(this, elements[i]);
  associateEntityWithVertices(this);
  storeVerticesInEntities(allvertices);

  fclose(fp);
  return 1;
}

int GModel::writeVRML(const std::string &name, double scalingFactor)
{
  FILE *fp = fopen(name.c_str(), "w");
  if(!fp){
    Msg(GERROR, "Unable to open file '%s'", name.c_str());
    return 0;
  }

  renumberMeshVertices();

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
    fprintf(fp, "DEF Curve%d IndexedLineSet {\n", (*it)->tag());
    fprintf(fp, "  coordIndex [\n");
    for(unsigned int i = 0; i < (*it)->lines.size(); i++)
      (*it)->lines[i]->writeVRML(fp);
    fprintf(fp, "  ]\n");
    fprintf(fp, "}\n");
  }

  for(fiter it = firstFace(); it != lastFace(); ++it){
    fprintf(fp, "DEF Surface%d IndexedFaceSet {\n", (*it)->tag());
    fprintf(fp, "  coordIndex [\n");
    for(unsigned int i = 0; i < (*it)->triangles.size(); i++)
      (*it)->triangles[i]->writeVRML(fp);
    for(unsigned int i = 0; i < (*it)->quadrangles.size(); i++)
      (*it)->quadrangles[i]->writeVRML(fp);
    fprintf(fp, "  ]\n");
    fprintf(fp, "}\n");
  }
  
  fclose(fp);
  return 1;
}

int GModel::readUNV(const std::string &name)
{
  FILE *fp = fopen(name.c_str(), "r");
  if(!fp){
    Msg(GERROR, "Unable to open file '%s'", name.c_str());
    return 0;
  }

  char buffer[256];
  std::map<int, MVertex*> vertices;
  std::map<int, std::vector<MVertex*> > points;
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
	  vertices[num] = new MVertex(x, y, z);
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
	  if(type >= 21 && type <= 24){ // beam elements
	    if(!fgets(buffer, sizeof(buffer), fp)) break;
	    int dum;
	    if(sscanf(buffer, "%d %d %d", &dum, &dum, &dum) != 3) break;
	  }
	  int n[30];
	  for(int i = 0; i < numNodes; i++){
	    if(!fscanf(fp, "%d", &n[i])) return 0;
	    if(!checkVertexIndex(n[i], vertices)) return 0;
	  }

	  int dim = -1;
	  switch(type){
	  case 11: case 21: case 22: case 31:
	    elements[0][elementary].push_back
	      (new MLine(vertices[n[0]], vertices[n[1]], num));
	    dim = 1;
	    break;
	  case 23: case 24: case 32:
	    elements[0][elementary].push_back
	      (new MLine3(vertices[n[0]], vertices[n[2]], vertices[n[1]], num));
	    dim = 1;
	    break;
	  case 41: case 51: case 61: case 74: case 81: case 91: 
	    elements[1][elementary].push_back
	      (new MTriangle(vertices[n[0]], vertices[n[1]], vertices[n[2]], num));
	    dim = 2;
	    break;
	  case 42: case 52: case 62: case 72: case 82: case 92: 
	    elements[1][elementary].push_back
	      (new MTriangle6(vertices[n[0]], vertices[n[2]], vertices[n[4]], 
			      vertices[n[1]], vertices[n[3]], vertices[n[5]], num));
	    dim = 2;
	    break;
	  case 44: case 54: case 64: case 71: case 84: case 94: 
	    elements[2][elementary].push_back
	      (new MQuadrangle(vertices[n[0]], vertices[n[1]], vertices[n[2]], 
			       vertices[n[3]], num));
	    dim = 2;
	    break;
	  case 45: case 55: case 65: case 75: case 85: case 95:
	    elements[2][elementary].push_back
	      (new MQuadrangle8(vertices[n[0]], vertices[n[2]], vertices[n[4]], 
				vertices[n[6]], vertices[n[1]], vertices[n[3]], 
				vertices[n[5]], vertices[n[7]], num));
	    dim = 2;
	    break;
	  case 111:
	    elements[3][elementary].push_back
	      (new MTetrahedron(vertices[n[0]], vertices[n[1]], vertices[n[2]], 
				vertices[n[3]], num));
	    dim = 3; 
	    break;
	  case 118: 
	    elements[3][elementary].push_back
	      (new MTetrahedron10(vertices[n[0]], vertices[n[2]], vertices[n[4]], 
				  vertices[n[9]], vertices[n[1]], vertices[n[3]], 
				  vertices[n[5]], vertices[n[8]], vertices[n[6]], 
				  vertices[n[7]], num));
	    dim = 3;
	    break;
	  case 104: case 115:  
	    elements[4][elementary].push_back
	      (new MHexahedron(vertices[n[0]], vertices[n[1]], vertices[n[2]], 
			       vertices[n[3]], vertices[n[4]], vertices[n[5]], 
			       vertices[n[6]], vertices[n[7]], num));
	    dim = 3; 
	    break;
	  case 105: case 116:
	    elements[4][elementary].push_back
	      (new MHexahedron20(vertices[n[0]], vertices[n[2]], vertices[n[4]],  
				 vertices[n[6]], vertices[n[12]], vertices[n[14]], 
				 vertices[n[16]], vertices[n[18]], vertices[n[1]],  
				 vertices[n[7]], vertices[n[8]], vertices[n[3]],  
				 vertices[n[9]], vertices[n[5]], vertices[n[10]], 
				 vertices[n[11]], vertices[n[13]], vertices[n[19]], 
				 vertices[n[15]], vertices[n[17]], num));
	    dim = 3; 
	    break;
	  case 101: case 112:
	    elements[5][elementary].push_back
	      (new MPrism(vertices[n[0]], vertices[n[1]], vertices[n[2]], 
			  vertices[n[3]], vertices[n[4]], vertices[n[5]], num));
	    dim = 3; 
	    break;
	  case 102: case 113:
	    elements[5][elementary].push_back
	      (new MPrism15(vertices[n[0]], vertices[n[2]], vertices[n[4]], 
			    vertices[n[9]], vertices[n[11]], vertices[n[13]], 
			    vertices[n[1]], vertices[n[5]], vertices[n[6]],  
			    vertices[n[3]], vertices[n[7]], vertices[n[8]],  
			    vertices[n[10]], vertices[n[14]], vertices[n[12]], num));
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
  
  for(int i = 0; i < (int)(sizeof(elements)/sizeof(elements[0])); i++) 
    storeElementsInEntities(this, elements[i]);
  associateEntityWithVertices(this);
  storeVerticesInEntities(vertices);
  for(int i = 0; i < 4; i++)  
    storePhysicalTagsInEntities(this, i, physicals[i]);

  fclose(fp);
  return 1;
}

template<class T>
static void writeElementsUNV(FILE *fp, const std::vector<T*> &ele, int saveAll, 
			     int &num, int elementary, std::vector<int> &physicals)
{
  for(unsigned int i = 0; i < ele.size(); i++)
    if(saveAll)
      ele[i]->writeUNV(fp, ++num, elementary, 0);
    else
      for(unsigned int j = 0; j < physicals.size(); j++)
	ele[i]->writeUNV(fp, ++num, elementary, physicals[j]);
}

int GModel::writeUNV(const std::string &name, bool saveAll, double scalingFactor)
{
  FILE *fp = fopen(name.c_str(), "w");
  if(!fp){
    Msg(GERROR, "Unable to open file '%s'", name.c_str());
    return 0;
  }

  // if there are no physicals we save all the elements
  if(noPhysicalGroups()) saveAll = true;

  renumberMeshVertices();

  // nodes
  fprintf(fp, "%6d\n", -1);
  fprintf(fp, "%6d\n", 2411);
  for(viter it = firstVertex(); it != lastVertex(); ++it)
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++) 
      (*it)->mesh_vertices[i]->writeUNV(fp, scalingFactor);
  for(eiter it = firstEdge(); it != lastEdge(); ++it)
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++)
      (*it)->mesh_vertices[i]->writeUNV(fp, scalingFactor);
  for(fiter it = firstFace(); it != lastFace(); ++it)
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++) 
      (*it)->mesh_vertices[i]->writeUNV(fp, scalingFactor);
  for(riter it = firstRegion(); it != lastRegion(); ++it)
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++) 
      (*it)->mesh_vertices[i]->writeUNV(fp, scalingFactor);
  fprintf(fp, "%6d\n", -1);  

  // elements
  fprintf(fp, "%6d\n", -1);
  fprintf(fp, "%6d\n", 2412);
  int num = 0;
  for(eiter it = firstEdge(); it != lastEdge(); ++it){
    writeElementsUNV(fp, (*it)->lines, saveAll, num, (*it)->tag(), (*it)->physicals);
  }
  for(fiter it = firstFace(); it != lastFace(); ++it){
    writeElementsUNV(fp, (*it)->triangles, saveAll, num, (*it)->tag(), (*it)->physicals);
    writeElementsUNV(fp, (*it)->quadrangles, saveAll, num, (*it)->tag(), (*it)->physicals);
  }
  for(riter it = firstRegion(); it != lastRegion(); ++it){
    writeElementsUNV(fp, (*it)->tetrahedra, saveAll, num, (*it)->tag(), (*it)->physicals);
    writeElementsUNV(fp, (*it)->hexahedra, saveAll, num, (*it)->tag(), (*it)->physicals);
    writeElementsUNV(fp, (*it)->prisms, saveAll, num, (*it)->tag(), (*it)->physicals);
  }
  fprintf(fp, "%6d\n", -1);

  fclose(fp);
  return 1;
}

int GModel::readMESH(const std::string &name)
{
  FILE *fp = fopen(name.c_str(), "r");
  if(!fp){
    Msg(GERROR, "Unable to open file '%s'", name.c_str());
    return 0;
  }

  char buffer[256];
  fgets(buffer, sizeof(buffer), fp);

  char str[256];
  int format;
  sscanf(buffer, "%s %d", str, &format);

  if(format != 1){
    Msg(GERROR, "Medit mesh import only available for ASCII files");
    return 0;
  }

  std::vector<MVertex*> vertices;
  std::map<int, std::vector<MElement*> > elements[3];

  int nbv, nbe, n[30], cl;

  while(!feof(fp)) {
    if(!fgets(buffer, sizeof(buffer), fp)) break;
    if(buffer[0] != '#'){ // skip comments
      sscanf(buffer, "%s", str);
      if(!strcmp(str, "Dimension")){
	if(!fgets(buffer, sizeof(buffer), fp)) break;
      }
      else if(!strcmp(str, "Vertices")){
	if(!fgets(buffer, sizeof(buffer), fp)) break;
	sscanf(buffer, "%d", &nbv);
	Msg(INFO, "%d vertices", nbv);
	vertices.resize(nbv);
	for(int i = 0; i < nbv; i++) {
	  if(!fgets(buffer, sizeof(buffer), fp)) break;
	  double x, y, z;
	  sscanf(buffer, "%lf %lf %lf %d", &x, &y, &z, &cl);
	  vertices[i] = new MVertex(x, y, z);
	}
      }
      else if(!strcmp(str, "Triangles")){
	if(!fgets(buffer, sizeof(buffer), fp)) break;
	sscanf(buffer, "%d", &nbe);
	Msg(INFO, "%d triangles", nbe);
	for(int i = 0; i < nbe; i++) {
	  if(!fgets(buffer, sizeof(buffer), fp)) break;
	  sscanf(buffer, "%d %d %d %d", &n[0], &n[1], &n[2], &cl);
	  for(int j = 0; j < 3; j++)
	    if(!checkVertexIndex(n[j] - 1, vertices)) return 0;
	  elements[0][cl].push_back
	    (new MTriangle(vertices[n[0] - 1], vertices[n[1] - 1], vertices[n[2] - 1]));
	}
      }
      else if(!strcmp(str, "Quadrilaterals")) {
	if(!fgets(buffer, sizeof(buffer), fp)) break;
	sscanf(buffer, "%d", &nbe);
	Msg(INFO, "%d quadrangles", nbe);
	for(int i = 0; i < nbe; i++) {
	  if(!fgets(buffer, sizeof(buffer), fp)) break;
	  sscanf(buffer, "%d %d %d %d %d", &n[0], &n[1], &n[2], &n[3], &cl);
	  for(int j = 0; j < 4; j++) 
	    if(!checkVertexIndex(n[j] - 1, vertices)) return 0;
	  elements[1][cl].push_back
	    (new MQuadrangle(vertices[n[0] - 1], vertices[n[1] - 1], 
			     vertices[n[2] - 1], vertices[n[3] - 1]));
	}
      }
      else if(!strcmp(str, "Tetrahedra")) {
	if(!fgets(buffer, sizeof(buffer), fp)) break;
	sscanf(buffer, "%d", &nbe);
	Msg(INFO, "%d tetrahedra", nbe);
	for(int i = 0; i < nbe; i++) {
	  if(!fgets(buffer, sizeof(buffer), fp)) break;
	  sscanf(buffer, "%d %d %d %d %d", &n[0], &n[1], &n[2], &n[3], &cl);
	  for(int j = 0; j < 4; j++) 
	    if(!checkVertexIndex(n[j] - 1, vertices)) return 0;
	  elements[2][cl].push_back
	    (new MTetrahedron(vertices[n[0] - 1], vertices[n[1] - 1], 
			      vertices[n[2] - 1], vertices[n[3] - 1]));
	}
      }
    }
  }

  for(int i = 0; i < (int)(sizeof(elements)/sizeof(elements[0])); i++) 
    storeElementsInEntities(this, elements[i]);
  associateEntityWithVertices(this);
  storeVerticesInEntities(vertices);

  fclose(fp);
  return 1;
}

int GModel::writeMESH(const std::string &name, double scalingFactor)
{
  FILE *fp = fopen(name.c_str(), "w");
  if(!fp){
    Msg(GERROR, "Unable to open file '%s'", name.c_str());
    return 0;
  }

  fprintf(fp, " MeshVersionFormatted 1\n");
  fprintf(fp, " Dimension\n");
  fprintf(fp, " 3\n");

  int numVertices = renumberMeshVertices();
  fprintf(fp, " Vertices\n");
  fprintf(fp, " %d\n", numVertices);
  for(viter it = firstVertex(); it != lastVertex(); ++it)
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++) 
      (*it)->mesh_vertices[i]->writeMESH(fp, scalingFactor);
  for(eiter it = firstEdge(); it != lastEdge(); ++it)
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++)
      (*it)->mesh_vertices[i]->writeMESH(fp, scalingFactor);
  for(fiter it = firstFace(); it != lastFace(); ++it)
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++) 
      (*it)->mesh_vertices[i]->writeMESH(fp, scalingFactor);
  for(riter it = firstRegion(); it != lastRegion(); ++it)
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++) 
      (*it)->mesh_vertices[i]->writeMESH(fp, scalingFactor);
  
  int numTriangles = 0, numQuadrangles = 0, numTetrahedra = 0;
  for(fiter it = firstFace(); it != lastFace(); ++it){
    numTriangles += (*it)->triangles.size();
    numQuadrangles += (*it)->quadrangles.size();
  }
  for(riter it = firstRegion(); it != lastRegion(); ++it){
    numTetrahedra += (*it)->tetrahedra.size();
  }
  if(numTriangles){
    fprintf(fp, " Triangles\n");
    fprintf(fp, " %d\n", numTriangles);
    for(fiter it = firstFace(); it != lastFace(); ++it)
      for(unsigned int i = 0; i < (*it)->triangles.size(); i++)
	(*it)->triangles[i]->writeMESH(fp, (*it)->tag());
  }
  if(numQuadrangles){
    fprintf(fp, " Quadrilaterals\n");
    fprintf(fp, " %d\n", numQuadrangles);
    for(fiter it = firstFace(); it != lastFace(); ++it)
      for(unsigned int i = 0; i < (*it)->triangles.size(); i++)
	(*it)->quadrangles[i]->writeMESH(fp, (*it)->tag());
  }
  if(numTetrahedra){
    fprintf(fp, " Tetrahedra\n");
    fprintf(fp, " %d\n", numTetrahedra);
    for(riter it = firstRegion(); it != lastRegion(); ++it)
      for(unsigned int i = 0; i < (*it)->tetrahedra.size(); i++)
	(*it)->tetrahedra[i]->writeMESH(fp, (*it)->tag());
  }

  fprintf(fp, " End\n");
  
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
  for(int i = 0; i < len; i++)
    if(str[i] == 'E') return atof(str);
  // treat special Nastran floating point formats (e.g. "-7.-1"
  // instead of "-7.E-01" or "2.3+2" instead of "2.3E+02")
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

static int readElementBDF(FILE *fp, char *buffer, int keySize, unsigned int numNodes, 
			  int *num, int *region, std::vector<MVertex*> &vertices,
			  std::map<int, MVertex*> &vertexMap)
{
  // This routine is not completely general: when there is a
  // continuation tag we just parse the next line. To follow the spec:
  // 1. we should parse the whole remainder of the file to find
  //    the corresponding continuation tag
  // 2. we should parse more than one continuation line for elements
  //    with more than 14 nodes (but since we don't import such
  //    elements at the moment parsing just one continuation line is
  //    OK)

  char buffer2[256];
  std::vector<char*> vals;
  int format = getFormatBDF(buffer, keySize);
  int cmax = (format == 2) ? 16 : 8; // max char per (center) field
  int nmax = (format == 2) ? 4 : 8; // max num of (center) fields per line

  for(unsigned int i = 0; i < sizeof(buffer2); i++) buffer2[i] = '\0';

  if(format == 0){ // free fields
    for(unsigned int i = 0; i < strlen(buffer); i++){
      if(buffer[i] == ',') vals.push_back(&buffer[i + 1]);
      if(vals.size() == 9) vals.pop_back(); // continuation field
    }
    if(vals.size() < 2 + numNodes){
      if(!fgets(buffer2, sizeof(buffer2), fp)) return 0;
      for(unsigned int i = 0; i < strlen(buffer2); i++){
	if(buffer2[i] == ',') vals.push_back(&buffer2[i + 1]);
      }
    }
  }
  else{ // small or long fields
    for(int i = 0; i < nmax; i++){
      if(vals.size() < 2 + numNodes) vals.push_back(&buffer[8 + cmax * i]);
    }
    if(vals.size() < 2 + numNodes){
      if(!fgets(buffer2, sizeof(buffer2), fp)) return 0;
      for(int i = 0; i < nmax; i++){
	if(vals.size() < 2 + numNodes) vals.push_back(&buffer2[8 + cmax * i]);
      }
    }    
  }
  
  if(vals.size() < 2 + numNodes){
    Msg(GERROR, "Missing nodes for element (%d < numNodes)", vals.size() - 2);
    return 0;
  }

  int n[30];
  char tmp[32];
  tmp[cmax] = '\0';
  strncpy(tmp, vals[0], cmax); *num = atoi(tmp);
  strncpy(tmp, vals[1], cmax); *region = atoi(tmp);
  for(unsigned int i = 0; i < numNodes; i++){
    strncpy(tmp, vals[i + 2], cmax); n[i] = atoi(tmp);
  }

  for(unsigned int i = 0; i < numNodes; i++){
    if(!checkVertexIndex(n[i], vertexMap)) return 0;
    vertices.push_back(vertexMap[n[i]]);
  }
  return 1;
}

int GModel::readBDF(const std::string &name)
{
  FILE *fp = fopen(name.c_str(), "r");
  if(!fp){
    Msg(GERROR, "Unable to open file '%s'", name.c_str());
    return 0;
  }

  char buffer[256];
  std::map<int, MVertex*> vertices;
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
	vertices[num] = new MVertex(x, y, z);
      }
    }
  }
  Msg(INFO, "%d vertices", vertices.size());

  rewind(fp);
  while(!feof(fp)) {
    for(unsigned int i = 0; i < sizeof(buffer); i++) buffer[i] = '\0';
    if(!fgets(buffer, sizeof(buffer), fp)) break;
    if(buffer[0] != '$'){ // skip comments
      int num, region;
      std::vector<MVertex*> n;
      if(!strncmp(buffer, "CBAR", 4)){
	if(readElementBDF(fp, buffer, 4, 2, &num, &region, n, vertices))
	  elements[0][region].push_back(new MLine(n, num));
      }
      else if(!strncmp(buffer, "CTRIA3", 6)){
	if(readElementBDF(fp, buffer, 6, 3, &num, &region, n, vertices))
	  elements[1][region].push_back(new MTriangle(n, num));
      }
      else if(!strncmp(buffer, "CTRIA6", 6)){
	// not sure about the node ordering
	if(readElementBDF(fp, buffer, 6, 6, &num, &region, n, vertices))
	  elements[1][region].push_back(new MTriangle6(n, num));
      }
      else if(!strncmp(buffer, "CQUAD4", 6)){
	if(readElementBDF(fp, buffer, 6, 4, &num, &region, n, vertices))
	  elements[2][region].push_back(new MQuadrangle(n, num));
      }
      else if(!strncmp(buffer, "CQUAD8", 6)){
	// not sure about the node ordering
	if(readElementBDF(fp, buffer, 6, 8, &num, &region, n, vertices))
	  elements[2][region].push_back(new MQuadrangle8(n, num));
      }
      else if(!strncmp(buffer, "CTETRA", 6)){
	if(readElementBDF(fp, buffer, 6, 4, &num, &region, n, vertices))
	  elements[3][region].push_back(new MTetrahedron(n, num));
      }
      else if(!strncmp(buffer, "CHEXA", 5)){
	if(readElementBDF(fp, buffer, 5, 8, &num, &region, n, vertices))
	  elements[4][region].push_back(new MHexahedron(n, num));
      }
      else if(!strncmp(buffer, "CPENTA", 6)){
	if(readElementBDF(fp, buffer, 6, 6, &num, &region, n, vertices))
	  elements[5][region].push_back(new MPrism(n, num));
      }
      else if(!strncmp(buffer, "CPYRAM", 6)){
	if(readElementBDF(fp, buffer, 6, 5, &num, &region, n, vertices))
	  elements[6][region].push_back(new MPyramid(n, num));
      }
    }
  }
  
  for(int i = 0; i < (int)(sizeof(elements)/sizeof(elements[0])); i++) 
    storeElementsInEntities(this, elements[i]);
  associateEntityWithVertices(this);
  storeVerticesInEntities(vertices);

  fclose(fp);
  return 1;
}

int GModel::writeBDF(const std::string &name, int format, bool saveAll, 
		     double scalingFactor)
{
  FILE *fp = fopen(name.c_str(), "w");
  if(!fp){
    Msg(GERROR, "Unable to open file '%s'", name.c_str());
    return 0;
  }

  renumberMeshVertices();

  fprintf(fp, "$ Created by Gmsh\n");

  for(viter it = firstVertex(); it != lastVertex(); ++it)
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++) 
      (*it)->mesh_vertices[i]->writeBDF(fp, format, scalingFactor);
  for(eiter it = firstEdge(); it != lastEdge(); ++it)
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++)
      (*it)->mesh_vertices[i]->writeBDF(fp, format, scalingFactor);
  for(fiter it = firstFace(); it != lastFace(); ++it)
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++) 
      (*it)->mesh_vertices[i]->writeBDF(fp, format, scalingFactor);
  for(riter it = firstRegion(); it != lastRegion(); ++it)
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++) 
      (*it)->mesh_vertices[i]->writeBDF(fp, format, scalingFactor);
  
  for(eiter it = firstEdge(); it != lastEdge(); ++it){
    for(unsigned int i = 0; i < (*it)->lines.size(); i++)
      (*it)->lines[i]->writeBDF(fp, format, (*it)->tag());
  }
  for(fiter it = firstFace(); it != lastFace(); ++it){
    for(unsigned int i = 0; i < (*it)->triangles.size(); i++)
      (*it)->triangles[i]->writeBDF(fp, format, (*it)->tag());
    for(unsigned int i = 0; i < (*it)->quadrangles.size(); i++)
      (*it)->quadrangles[i]->writeBDF(fp, format, (*it)->tag());
  }
  for(riter it = firstRegion(); it != lastRegion(); ++it){
    for(unsigned int i = 0; i < (*it)->tetrahedra.size(); i++)
      (*it)->tetrahedra[i]->writeBDF(fp, format, (*it)->tag());
    for(unsigned int i = 0; i < (*it)->hexahedra.size(); i++)
      (*it)->hexahedra[i]->writeBDF(fp, format, (*it)->tag());
    for(unsigned int i = 0; i < (*it)->prisms.size(); i++)
      (*it)->prisms[i]->writeBDF(fp, format, (*it)->tag());
    for(unsigned int i = 0; i < (*it)->pyramids.size(); i++)
      (*it)->pyramids[i]->writeBDF(fp, format, (*it)->tag());
  }
  
  fprintf(fp, "ENDDATA\n");
   
  fclose(fp);
  return 1;
}
