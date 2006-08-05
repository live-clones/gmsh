#include <map>
#include <string>

#include "Message.h"
#include "GmshDefines.h"
#include "gmshRegion.h"
#include "gmshFace.h"
#include "gmshEdge.h"
#include "MElement.h"

static int getNumVerticesForElementType(int type)
{
  switch (type) {
  case PNT : return 1;
  case LGN1: return 2;
  case LGN2: return 2 + 1;
  case TRI1: return 3;
  case TRI2: return 3 + 3;
  case QUA1: return 4;
  case QUA2: return 4 + 4 + 1;
  case TET1: return 4;
  case TET2: return 4 + 6;
  case HEX1: return 8;
  case HEX2: return 8 + 12 + 6 + 1;
  case PRI1: return 6;
  case PRI2: return 6 + 9 + 3;
  case PYR1: return 5;
  case PYR2: return 5 + 8 + 1;
  default: return 0;
  }
}

template<class T>
static void associateEntityWithVertices(GEntity *ge, std::vector<T*> &elements)
{
  for(unsigned int i = 0; i < elements.size(); i++)
    for(int j = 0; j < elements[i]->getNumVertices(); j++)
      elements[i]->getVertex(j)->setEntity(ge);
}

template<class T>
void copyElements(std::vector<T*> &dst, const std::vector<MElement*> &src)
{
  dst.resize(src.size());
  for(unsigned int i = 0; i < src.size(); i++) dst[i] = (T*)src[i];
}

static void storeElementsInEntities(GModel *m, int type, 
				    std::map<int, std::vector<MElement*> > &map)
{
  std::map<int, std::vector<MElement*> >::const_iterator it = map.begin();
  std::map<int, std::vector<MElement*> >::const_iterator ite = map.end();
  for(; it != ite; ++it){
    switch(type){
    case LGN1:     
      {
	GEdge *e = m->edgeByTag(it->first);
	if(!e){
	  e = new gmshEdge(m, it->first);
	  m->add(e);
	}
	copyElements(e->lines, it->second);
      }
      break;
    case TRI1: case QUA1: 
      {
	GFace *f = m->faceByTag(it->first);
	if(!f){
	  f = new gmshFace(m, it->first);
	  m->add(f);
	}
	if(type == TRI1) copyElements(f->triangles, it->second);
	else if(type == QUA1) copyElements(f->quadrangles, it->second);
      }
      break;
    case TET1: case HEX1: case PRI1: case PYR1:
      {
	GRegion *r = m->regionByTag(it->first);
	if(!r){
	  r = new gmshRegion(m, it->first);
	  m->add(r);
	}
	if(type == TET1) copyElements(r->tetrahedra, it->second);
	else if(type == HEX1) copyElements(r->hexahedra, it->second);
	else if(type == PRI1) copyElements(r->prisms, it->second);
	else if(type == PYR1) copyElements(r->pyramids, it->second);
      }
      break;
    }
  }
}

static void storePhysicalTagsInEntities(GModel *m, int dim,
					std::map<int, std::map<int, std::string> > &map)
{
  std::map<int, std::map<int, std::string> >::const_iterator it = map.begin();
  std::map<int, std::map<int, std::string> >::const_iterator ite = map.end();
  for(; it != ite; ++it){
    GEntity *ge = 0;
    switch(dim){
    case 0: ge = m->vertexByTag(it->first); break;
    case 1: ge = m->edgeByTag(it->first); break;
    case 2: ge = m->faceByTag(it->first); break;
    case 3: ge = m->regionByTag(it->first); break;
    }
    if(ge){
      std::map<int, std::string>::const_iterator it2 = it->second.begin();
      std::map<int, std::string>::const_iterator ite2 = it->second.end();
      for(; it2 != ite2; ++it2)
	ge->physicals.push_back(it2->first);
    }
  }
}

int GModel::readMSH(const std::string &name)
{
  FILE *fp = fopen(name.c_str(), "r");
  if(!fp){
    Msg(GERROR, "Unable to open file '%s'", name.c_str());
    return 0;
  }

  int elementTypes[7] = {LGN1, TRI1, QUA1, TET1, HEX1, PRI1, PYR1};
  double version = 1.0;
  char str[256];
  std::map<int, MVertex*> vertices;
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

      int format, size;
      fscanf(fp, "%lf %d %d\n", &version, &format, &size);

    }
    else if(!strncmp(&str[1], "NO", 2) || !strncmp(&str[1], "Nodes", 5)) {

      int numVertices;
      fscanf(fp, "%d", &numVertices);
      Msg(INFO, "%d vertices", numVertices);

      int progress = (numVertices > 100000) ? numVertices / 50 : numVertices / 10;
      for(int i = 0; i < numVertices; i++) {
	int num;
	double x, y, z;
        fscanf(fp, "%d %lf %lf %lf", &num, &x, &y, &z);
	if(vertices.count(num))
	  Msg(WARNING, "Skipping duplicate vertex %d", num);
	else
	  vertices[num] = new MVertex(x, y, z);
	if(progress && (i % progress == progress - 1))
	  Msg(PROGRESS, "Read %d vertices", i + 1);
      }
      Msg(PROGRESS, "");

    }
    else if(!strncmp(&str[1], "ELM", 3) || !strncmp(&str[1], "Elements", 8)) {

      int numElements;
      fscanf(fp, "%d", &numElements);
      Msg(INFO, "%d elements", numElements);

      int progress = (numElements > 100000) ? numElements / 50 : numElements / 10;
      for(int i = 0; i < numElements; i++) {
	int num, type, physical = 1, elementary = 1, partition = 1, numVertices;
	if(version <= 1.0){
	  fscanf(fp, "%d %d %d %d %d", &num, &type, &physical, &elementary, &numVertices);
	  int check = getNumVerticesForElementType(type);
	  if(!check){
	    Msg(GERROR, "Unknown type for element %d", num); 
	    continue;
	  }
	  if(numVertices != check){
	    Msg(GERROR, "Wrong number of vertices (%d) for element %d", numVertices, num);
	    continue;
	  }
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
	  numVertices = getNumVerticesForElementType(type);
	  if(!numVertices){
	    Msg(GERROR, "Unknown type (%d) for element %d", type, num); 
	    continue;
	  }
	}
	int n[30];
        for(int j = 0; j < numVertices; j++) fscanf(fp, "%d", &n[j]);
	int dim = 0;
        switch (type) {
        case PNT:
	  points[elementary].push_back(vertices[n[0]]);
	  dim = 0;
          break;
        case LGN1:
	  elements[0][elementary].push_back
	    (new MLine(vertices[n[0]], vertices[n[1]], num, partition));
	  dim = 1;
          break;
        case TRI1:
	  elements[1][elementary].push_back
	    (new MTriangle(vertices[n[0]], vertices[n[1]], vertices[n[2]], 
			   num, partition));
	  dim = 2;
          break;
        case QUA1:
	  elements[2][elementary].push_back
	    (new MQuadrangle(vertices[n[0]], vertices[n[1]], vertices[n[2]], 
			     vertices[n[3]], num, partition));
	  dim = 2;
          break;
	case TET1:
	  elements[3][elementary].push_back
	    (new MTetrahedron(vertices[n[0]], vertices[n[1]], vertices[n[2]], 
			      vertices[n[3]], num, partition));
	  dim = 3; 
	  break;
	case HEX1:
	  elements[4][elementary].push_back
	    (new MHexahedron(vertices[n[0]], vertices[n[1]], vertices[n[2]], 
			     vertices[n[3]], vertices[n[4]], vertices[n[5]], 
			     vertices[n[6]], vertices[n[7]], num, partition));
	  dim = 3; 
	  break;
	case PRI1: 
	  elements[5][elementary].push_back
	    (new MPrism(vertices[n[0]], vertices[n[1]], vertices[n[2]], 
			vertices[n[3]], vertices[n[4]], vertices[n[5]], 
			num, partition));
	  dim = 3; 
	  break;
	case PYR1: 
	  elements[6][elementary].push_back
	    (new MPyramid(vertices[n[0]], vertices[n[1]], vertices[n[2]], 
			  vertices[n[3]], vertices[n[4]], num, partition));
	  dim = 3; 
	  break;
        default:
	  Msg(GERROR, "Unknown type (%d) for element %d", type, num); 
          break;
        }

	if(!physicals[dim].count(elementary) || !physicals[dim][elementary].count(physical))
	  physicals[dim][elementary][physical] = "unnamed";
	
	if(progress && (i % progress == progress - 1))
	  Msg(PROGRESS, "Read %d elements", i + 1);
      }
      Msg(PROGRESS, "");

    }

    do {
      if(!fgets(str, sizeof(str), fp) || feof(fp))
	Msg(GERROR, "Prematured end of mesh file");
    } while(str[0] != '$');

  }

  // store the elements in their associated elementary entity. If the
  // entity does not exist, create a new one.
  for(int i = 0; i < 7; i++)
    storeElementsInEntities(this, elementTypes[i], elements[i]);

  // treat points separately
  {
    std::map<int, std::vector<MVertex*> >::const_iterator it = points.begin();
    std::map<int, std::vector<MVertex*> >::const_iterator ite = points.end();
    for(; it != ite; ++it){
      GVertex *v = vertexByTag(it->first);
      if(!v){
	v = new gmshVertex(this, it->first);
	add(v);
      }
      v->mesh_vertices.push_back(it->second[0]);
    }
  }
  
  // loop on regions, then on faces, edges and vertices and store the
  // entity pointer in the the elements' vertices (this way we
  // associate the entity of lowest geometrical degree with each
  // vertex)
  for(riter it = firstRegion(); it != lastRegion(); ++it){
    associateEntityWithVertices(*it, (*it)->tetrahedra);
    associateEntityWithVertices(*it, (*it)->hexahedra);
    associateEntityWithVertices(*it, (*it)->prisms);
    associateEntityWithVertices(*it, (*it)->pyramids);
  }
  for(fiter it = firstFace(); it != lastFace(); ++it){
    associateEntityWithVertices(*it, (*it)->triangles);
    associateEntityWithVertices(*it, (*it)->quadrangles);
  }
  for(eiter it = firstEdge(); it != lastEdge(); ++it){
    associateEntityWithVertices(*it, (*it)->lines);
  }
  for(viter it = firstVertex(); it != lastVertex(); ++it){
    // special case for points: the mesh vertex has been copied here
    // so that we can assign the entity:
    (*it)->mesh_vertices[0]->setEntity(*it);
    // now that this is done, we reset mesh_vertices so that it can be
    // filled again below
    (*it)->mesh_vertices.clear();
  }

  // store the vertices in their associated geometrical entity
  std::map<int, MVertex*>::const_iterator it = vertices.begin();
  std::map<int, MVertex*>::const_iterator ite = vertices.end();
  for(; it != ite; ++it){
    MVertex *v = it->second;
    GEntity *ge = v->onWhat();
    if(ge) 
      ge->mesh_vertices.push_back(v);
    else
      delete v; // we delete all unused vertices
  }

  // store the physical tags
  for(int i = 0; i < 4; i++)  
    storePhysicalTagsInEntities(this, i, physicals[i]);

  fclose(fp);
  return 1;
}

static void numVerticesAndElementsInModel(GModel *m, bool saveAll, 
					  int &numVertices, int &numElements)
{
  // get the number of vertices and elements in the msh file and
  // renumber the nodes in a continuous sequence
  numVertices = numElements = 0;
  for(GModel::viter it = m->firstVertex(); it != m->lastVertex(); ++it){
    int n = (*it)->mesh_vertices.size();
    numElements += (saveAll ? 1 : (*it)->physicals.size()) * n;
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++) 
      (*it)->mesh_vertices[i]->setNum(++numVertices);
  }
  for(GModel::eiter it = m->firstEdge(); it != m->lastEdge(); ++it){
    int n = (*it)->lines.size();
    numElements += (saveAll ? 1 : (*it)->physicals.size()) * n;
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++) 
      (*it)->mesh_vertices[i]->setNum(++numVertices);
  }
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it){
    int n = (*it)->triangles.size() + (*it)->quadrangles.size();
    numElements += (saveAll ? 1 : (*it)->physicals.size()) * n;
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++) 
      (*it)->mesh_vertices[i]->setNum(++numVertices);
  }
  for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it){
    int n = (*it)->tetrahedra.size() + (*it)->hexahedra.size() +
      (*it)->prisms.size() + (*it)->pyramids.size();
    numElements += (saveAll ? 1 : (*it)->physicals.size()) * n;
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++) 
      (*it)->mesh_vertices[i]->setNum(++numVertices);
  }
}

template<class T>
static void writeElementsMSH(FILE *fp, const std::vector<T*> &ele, int saveAll, 
			     double version, int &num, int elementary, 
			     std::vector<int> &physicals)
{
  for(unsigned int i = 0; i < ele.size(); i++)
    if(saveAll)
      ele[i]->writeMSH(fp, version, ++num, elementary, elementary);
    else
      for(unsigned int j = 0; j < physicals.size(); j++)
	ele[i]->writeMSH(fp, version, ++num, elementary, physicals[j]);
}

int GModel::writeMSH(const std::string &name, double version, bool saveAll, 
		     double scalingFactor)
{
  FILE *fp = fopen(name.c_str(), "w");
  if(!fp){
    Msg(GERROR, "Unable to open file '%s'", name.c_str());
    return 0;
  }

  if(version > 2.0){
    fprintf(fp, "$MeshFormat\n");
    fprintf(fp, "%g %d %d\n", version, 0, (int)sizeof(double));
    fprintf(fp, "$EndMeshFormat\n");
    fprintf(fp, "$Nodes\n");
  }
  else
    fprintf(fp, "$NOD\n");

  int numVertices, numElements;
  numVerticesAndElementsInModel(this, saveAll, numVertices, numElements);

  fprintf(fp, "%d\n", numVertices);
  for(viter it = firstVertex(); it != lastVertex(); ++it)
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++) 
      (*it)->mesh_vertices[i]->writeMSH(fp, scalingFactor);
  for(eiter it = firstEdge(); it != lastEdge(); ++it)
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++)
      (*it)->mesh_vertices[i]->writeMSH(fp, scalingFactor);
  for(fiter it = firstFace(); it != lastFace(); ++it)
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++) 
      (*it)->mesh_vertices[i]->writeMSH(fp, scalingFactor);
  for(riter it = firstRegion(); it != lastRegion(); ++it)
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++) 
      (*it)->mesh_vertices[i]->writeMSH(fp, scalingFactor);

  if(version > 2.0){
    fprintf(fp, "$EndNodes\n");
    fprintf(fp, "$Elements\n");
  }
  else{
    fprintf(fp, "$ENDNOD\n");
    fprintf(fp, "$ELM\n");
  }

  fprintf(fp, "%d\n", numElements);
  int num = 0;

  for(viter it = firstVertex(); it != lastVertex(); ++it){
    writeElementsMSH(fp, (*it)->mesh_vertices, saveAll, version, num,
		     (*it)->tag(), (*it)->physicals);
  }
  for(eiter it = firstEdge(); it != lastEdge(); ++it){
    writeElementsMSH(fp, (*it)->lines, saveAll, version, num,
		     (*it)->tag(), (*it)->physicals);
  }
  for(fiter it = firstFace(); it != lastFace(); ++it){
    writeElementsMSH(fp, (*it)->triangles, saveAll, version, num,
		     (*it)->tag(), (*it)->physicals);
    writeElementsMSH(fp, (*it)->quadrangles, saveAll, version, num,
		     (*it)->tag(), (*it)->physicals);
  }
  for(riter it = firstRegion(); it != lastRegion(); ++it){
    writeElementsMSH(fp, (*it)->tetrahedra, saveAll, version, num,
		     (*it)->tag(), (*it)->physicals);
    writeElementsMSH(fp, (*it)->hexahedra, saveAll, version, num,
		     (*it)->tag(), (*it)->physicals);
    writeElementsMSH(fp, (*it)->prisms, saveAll, version, num,
		     (*it)->tag(), (*it)->physicals);
    writeElementsMSH(fp, (*it)->pyramids, saveAll, version, num,
		     (*it)->tag(), (*it)->physicals);
  }
  
  if(version > 2.0){
    fprintf(fp, "$EndElements\n");
  }
  else{
    fprintf(fp, "$ENDELM\n");
  }

  return 1;
}

int GModel::writePOS(const std::string &name)
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
	(*it)->tetrahedra[i]->writePOS(fp);
      for(unsigned int i = 0; i < (*it)->hexahedra.size(); i++)
	(*it)->hexahedra[i]->writePOS(fp);
      for(unsigned int i = 0; i < (*it)->prisms.size(); i++)
	(*it)->prisms[i]->writePOS(fp);
      for(unsigned int i = 0; i < (*it)->pyramids.size(); i++)
	(*it)->pyramids[i]->writePOS(fp);
    }
    fprintf(fp, "};\n");
  }
  
  if(numFace()){
    fprintf(fp, "View \"Surfaces\" {\n");
    fprintf(fp, "T2(1.e5,30,%d){\"Elementary Entity\", \"Element Number\", "
	    "\"Gamma\", \"Eta\", \"Rho\"};\n", (1<<16)|(4<<8));
    for(fiter it = firstFace(); it != lastFace(); ++it) {
      for(unsigned int i = 0; i < (*it)->triangles.size(); i++)
	(*it)->triangles[i]->writePOS(fp);
      for(unsigned int i = 0; i < (*it)->quadrangles.size(); i++)
	(*it)->quadrangles[i]->writePOS(fp);
    }
    fprintf(fp, "};\n");
  }

  if(numEdge()){
    fprintf(fp, "View \"Lines\" {\n");
    fprintf(fp, "T2(1.e5,30,%d){\"Elementary Entity\", \"Element Number\", "
	    "\"Gamma\", \"Eta\", \"Rho\"};\n", (1<<16)|(4<<8));
    for(eiter it = firstEdge(); it != lastEdge(); ++it) {
      for(unsigned int i = 0; i < (*it)->lines.size(); i++)
 	(*it)->lines[i]->writePOS(fp);
    }
    fprintf(fp, "};\n");
  }

  fclose(fp);
  return 1;
}
