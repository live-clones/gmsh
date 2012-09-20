// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GModel.h"
#include "MPoint.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "StringUtils.h"

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
  std::map<int, std::map<int, std::string> > physicals[4];

  if(!fgets(buffer, sizeof(buffer), fp)) return 0; // version line
  if(!fgets(buffer, sizeof(buffer), fp)) return 0; // title

  if(fscanf(fp, "%s", buffer) != 1) // ASCII or BINARY
    Msg::Error("Failed reading buffer");
  bool binary = false;
  if(!strcmp(buffer, "BINARY")) binary = true;

  if(fscanf(fp, "%s %s", buffer, buffer2) != 2) return 0;

  bool unstructured = false;
  if(!strcmp(buffer, "DATASET") && !strcmp(buffer2, "UNSTRUCTURED_GRID"))
    unstructured = true;

  if((strcmp(buffer, "DATASET") &&  strcmp(buffer2, "UNSTRUCTURED_GRID")) ||
     (strcmp(buffer, "DATASET") &&  strcmp(buffer2, "POLYDATA"))){
    Msg::Error("VTK reader can only read unstructured or polydata datasets");
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

  bool haveCells = true;
  bool haveLines = false;
  if( !strcmp(buffer, "CELLS") && numElements > 0)
    Msg::Info("Reading %d cells", numElements);
  else if (!strcmp(buffer, "POLYGONS") && numElements > 0)
    Msg::Info("Reading %d polygons", numElements);
  else if (!strcmp(buffer, "LINES") && numElements > 0){
    haveCells = false;
    haveLines = true;
    Msg::Info("Reading %d lines", numElements);
  }
  else{
    Msg::Warning("No cells or polygons in dataset");
    return 0;
  }

  std::map<int, std::vector<MElement*> > elements[8];

  if (haveCells){
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

    if (unstructured){
      if(fscanf(fp, "%s %d\n", buffer, &numElements) != 2 ) return 0;
      if(strcmp(buffer, "CELL_TYPES") || numElements != (int)cells.size()){
	Msg::Error("No or invalid number of cells types");
	return 0;
      }
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
    }
    else{
      for(unsigned int i = 0; i < cells.size(); i++){
	int nbNodes = (int)cells[i].size();
	switch(nbNodes){
	case 1: elements[0][1].push_back(new MPoint(cells[i])); break;
	case 2: elements[1][1].push_back(new MLine(cells[i])); break;
	case 3: elements[2][1].push_back(new MTriangle(cells[i])); break;
	case 4: elements[3][1].push_back(new MQuadrangle(cells[i])); break;
	default:
	  Msg::Error("Unknown type of mesh element with %d nodes", nbNodes);
	  break;
	}
      }
    }
  }
  else if (haveLines){
    if(!binary){
      int v0, v1;
      char line[100000], *p, *pEnd, *pEnd2;
      int iLine = 1;
      for (int k= 0; k < numElements; k++){
	physicals[1][iLine][1] = "centerline";
	if(!fgets(line, sizeof(line), fp)) return 0;
	v0 = (int)strtol(line, &pEnd, 10); //ignore first line
	v0 = (int)strtol(pEnd, &pEnd2, 10);
	p=pEnd2;
	while(1){
	  v1 = strtol(p, &pEnd, 10);
	  if (p == pEnd )  break;
	  elements[1][iLine].push_back(new MLine(vertices[v0],vertices[v1]));
	  p = pEnd;
	  v0 = v1;
	}
	iLine++;
      }
    }
    else{
      Msg::Error("TODO: implement reading lines for binary files \n");
    }
  }

  for(int i = 0; i < (int)(sizeof(elements) / sizeof(elements[0])); i++)
    _storeElementsInEntities(elements[i]);
  _associateEntityWithMeshVertices();
  _storeVerticesInEntities(vertices);

  // store the physical tags
  for(int i = 0; i < 4; i++)
    _storePhysicalTagsInEntities(i, physicals[i]);

  fclose(fp);
  return 1;
}
