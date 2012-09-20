// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <stdlib.h>
#include <string.h>
#include "GmshConfig.h"
#include "GModel.h"
#include "MTriangle.h"
#include "OS.h"

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewDataList.h"
#endif

static bool getVertices(int num, int *indices, std::vector<MVertex*> &vec,
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

static void replaceCommaByDot(const std::string name)
{
  char myCommand[1000], myCommand2[1000];
  sprintf(myCommand, "sed 's/,/./g' %s > temp.txt", name.c_str());
  SystemCall(myCommand, true);
  sprintf(myCommand2, "mv temp.txt %s ", name.c_str());
  SystemCall(myCommand2, true);
}

static bool getProperties(int num, int *indices, std::vector<double> &vec,
                        std::vector<double> &properties)
{
  for(int i = 0; i < num; i++){
    if(indices[i] < 0 || indices[i] > (int)(vec.size() - 1)){
      Msg::Error("Wrong vertex index %d", indices[i]);
      return false;
    }
    else
      properties.push_back(vec[indices[i]]);
  }
  return true;
}

int GModel::readPLY(const std::string &name)
{
  // this is crazy!?
  replaceCommaByDot(name);

  FILE *fp = fopen(name.c_str(), "r");
  if(!fp){
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  std::vector<MVertex*> vertexVector;
  std::map<int, std::vector<MElement*> > elements[5];
  std::map<int, std::vector<double> > properties;

  char buffer[256], str[256], str2[256], str3[256];
  std::string s1;
  int elementary = getMaxElementaryNumber(-1) + 1;
  int nbv, nbf;
  int nbprop = 0;
  int nbView = 0;
  std::vector<std::string> propName;
  while(!feof(fp)) {
    if(!fgets(buffer, sizeof(buffer), fp)) break;
    if(buffer[0] != '#'){ // skip comments
      sscanf(buffer, "%s %s", str, str2);
      if(!strcmp(str, "element") && !strcmp(str2, "vertex")){
	sscanf(buffer, "%s %s %d", str, str2, &nbv);
      }
      if(!strcmp(str, "format") && strcmp(str2, "ascii")){
	Msg::Error("Only reading of ascii PLY files implemented");
	return 0;
      }
      if(!strcmp(str, "property") && strcmp(str2, "list")){
	nbprop++;
	sscanf(buffer, "%s %s %s", str, str2, str3);
	if (nbprop > 3) propName.push_back(s1+str3);
      }
      if(!strcmp(str, "element") && !strcmp(str2, "face")){
	sscanf(buffer, "%s %s %d", str, str2, &nbf);
      }
      if(!strcmp(str, "end_header")){
	nbView = nbprop -3;
	Msg::Info("%d elements", nbv);
	Msg::Info("%d triangles", nbf);
	Msg::Info("%d properties", nbView);

	vertexVector.resize(nbv);
	for(int i = 0; i < nbv; i++) {
	  double x,y,z;
	  char line[10000], *pEnd, *pEnd2, *pEnd3;
	  if(!fgets(line, sizeof(line), fp)) return 0;
	  x = strtod(line, &pEnd);
	  y = strtod(pEnd, &pEnd2);
	  z = strtod(pEnd2, &pEnd3);
	  vertexVector[i] = new MVertex(x, y, z);

	  pEnd = pEnd3;
          std::vector<double> prop(nbView);
	  for (int k = 0; k < nbView; k++){
	    prop[k]=strtod(pEnd, &pEnd2);
	    pEnd = pEnd2;
	    properties[k].push_back(prop[k]);
	  }
	}

	for(int i = 0; i < nbf; i++) {
	  if(!fgets(buffer, sizeof(buffer), fp)) break;
	  int n[3], nbe;
	  sscanf(buffer, "%d %d %d %d", &nbe, &n[0], &n[1], &n[2]);
	  std::vector<MVertex*> vertices;
	  if(!getVertices(3, n, vertexVector, vertices)) return 0;
	  elements[0][elementary].push_back(new MTriangle(vertices));
	}

      }

    }
  }

  for(int i = 0; i < (int)(sizeof(elements) / sizeof(elements[0])); i++)
    _storeElementsInEntities(elements[i]);
  _associateEntityWithMeshVertices();
  _storeVerticesInEntities(vertexVector);

#if defined(HAVE_POST)
  // create PViews here
  std::vector<GEntity*> _entities;
  getEntities(_entities);
  for (int iV=0; iV< nbView; iV++){
    PView *view = new PView();
    PViewDataList *data = dynamic_cast<PViewDataList*>(view->getData());
    for(unsigned int ii = 0; ii < _entities.size(); ii++){
	for(unsigned int i = 0; i < _entities[ii]->getNumMeshElements(); i++){
	  MElement *e = _entities[ii]->getMeshElement(i);
	  int numNodes = e->getNumVertices();
	  std::vector<double> x(numNodes), y(numNodes), z(numNodes);
	  std::vector<double> *out = data->incrementList(1, e->getType());
	  for(int nod = 0; nod < numNodes; nod++) out->push_back((e->getVertex(nod))->x());
	  for(int nod = 0; nod < numNodes; nod++) out->push_back((e->getVertex(nod))->y());
	  for(int nod = 0; nod < numNodes; nod++) out->push_back((e->getVertex(nod))->z());
	  std::vector<double> props;
	  int n[3];
	  n[0] = e->getVertex(0)->getNum()-1;
	  n[1] = e->getVertex(1)->getNum()-1;
	  n[2] = e->getVertex(2)->getNum()-1;
	  if(!getProperties(3, n, properties[iV], props)) return 0;
	  for(int nod = 0; nod < numNodes; nod++) out->push_back(props[nod]);
	}
    }
    data->setName(propName[iV]);
    data->Time.push_back(0);
    data->setFileName("property.pos");
    data->finalize();
  }
#endif

  fclose(fp);

  return 1;
}

int GModel::readPLY2(const std::string &name)
{
  FILE *fp = fopen(name.c_str(), "r");
  if(!fp){
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  std::vector<MVertex*> vertexVector;
  std::map<int, std::vector<MElement*> > elements[5];

  char buffer[256];
  int elementary = getMaxElementaryNumber(-1) + 1;
  int nbv, nbf;
  while(!feof(fp)) {
    if(!fgets(buffer, sizeof(buffer), fp)) break;
    if(buffer[0] != '#'){ // skip comments
      sscanf(buffer, "%d", &nbv);
      if(!fgets(buffer, sizeof(buffer), fp)) break;
      sscanf(buffer, "%d", &nbf);
      Msg::Info("%d vertices", nbv);
      Msg::Info("%d triangles", nbf);
      vertexVector.resize(nbv);
      for(int i = 0; i < nbv; i++) {
	if(!fgets(buffer, sizeof(buffer), fp)) break;
	double x, y, z;
	int nb = sscanf(buffer, "%lf %lf %lf", &x, &y, &z);
	if (nb !=3){
	  if(!fgets(buffer, sizeof(buffer), fp)) break;
	  sscanf(buffer, "%lf",  &y);
	  if(!fgets(buffer, sizeof(buffer), fp)) break;
	  sscanf(buffer, "%lf",  &z);
	}
	vertexVector[i] = new MVertex(x, y, z);
      }
      for(int i = 0; i < nbf; i++) {
	if(!fgets(buffer, sizeof(buffer), fp)) break;
	int n[3], nbe;
	int nb = sscanf(buffer, "%d %d %d %d", &nbe, &n[0], &n[1], &n[2]);
	if (nb !=4){
	  if(!fgets(buffer, sizeof(buffer), fp)) break;
	  sscanf(buffer, "%d",  &n[0]);
	  if(!fgets(buffer, sizeof(buffer), fp)) break;
	  sscanf(buffer, "%d",  &n[1]);
	  if(!fgets(buffer, sizeof(buffer), fp)) break;
	  sscanf(buffer, "%d",  &n[2]);
	}
	std::vector<MVertex*> vertices;
	if(!getVertices(3, n, vertexVector, vertices)) return 0;
	elements[0][elementary].push_back(new MTriangle(vertices));
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

int GModel::writePLY2(const std::string &name)
{
  FILE *fp = fopen(name.c_str(), "w");
  if(!fp){
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  int numVertices = indexMeshVertices(true);
  int numTriangles = 0;
  for(fiter it = firstFace(); it != lastFace(); ++it){
    numTriangles += (*it)->triangles.size();
  }

  fprintf(fp, "%d\n", numVertices);
  fprintf(fp, "%d\n", numTriangles);

  std::vector<GEntity*> entities;
  getEntities(entities);
  for(unsigned int i = 0; i < entities.size(); i++)
    for(unsigned int j = 0; j < entities[i]->mesh_vertices.size(); j++)
      entities[i]->mesh_vertices[j]->writePLY2(fp);

  for(fiter it = firstFace(); it != lastFace(); ++it){
      for(unsigned int i = 0; i < (*it)->triangles.size(); i++)
        (*it)->triangles[i]->writePLY2(fp);
  }

  fclose(fp);
  return 1;
}

