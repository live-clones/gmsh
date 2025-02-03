// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GModel.h"
#include "OS.h"
#include "MPoint.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "StringUtils.h"
#include "GmshVersion.h"

int GModel::writeVTK(const std::string &name, bool binary, bool saveAll,
                     double scalingFactor, bool bigEndian)
{
  FILE *fp = Fopen(name.c_str(), binary ? "wb" : "w");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  if(noPhysicalGroups()) saveAll = true;

  // get the number of vertices and index the vertices in a continuous
  // sequence
  int numVertices = indexMeshVertices(saveAll);

  fprintf(fp, "# vtk DataFile Version 2.0\n");
  fprintf(fp, "%s, Created by Gmsh %s \n", getName().c_str(), GMSH_VERSION);
  if(binary)
    fprintf(fp, "BINARY\n");
  else
    fprintf(fp, "ASCII\n");
  fprintf(fp, "DATASET UNSTRUCTURED_GRID\n");

  // get all the entities in the model
  std::vector<GEntity *> entities;
  getEntities(entities);

  // write mesh vertices
  fprintf(fp, "POINTS %d double\n", numVertices);
  for(std::size_t i = 0; i < entities.size(); i++)
    for(std::size_t j = 0; j < entities[i]->mesh_vertices.size(); j++)
      entities[i]->mesh_vertices[j]->writeVTK(fp, binary, scalingFactor,
                                              bigEndian);
  fprintf(fp, "\n");

  // loop over all elements we need to save and count vertices
  int numElements = 0, totalNumInt = 0;
  for(std::size_t i = 0; i < entities.size(); i++) {
    if(entities[i]->physicals.size() || saveAll) {
      for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++) {
        if(entities[i]->getMeshElement(j)->getTypeForVTK()) {
          numElements++;
          totalNumInt += entities[i]->getMeshElement(j)->getNumVertices() + 1;
        }
      }
    }
  }

  // print vertex indices in ascii or binary
  fprintf(fp, "CELLS %d %d\n", numElements, totalNumInt);
  for(std::size_t i = 0; i < entities.size(); i++) {
    if(entities[i]->physicals.size() || saveAll) {
      for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++) {
        if(entities[i]->getMeshElement(j)->getTypeForVTK())
          entities[i]->getMeshElement(j)->writeVTK(fp, binary, bigEndian);
      }
    }
  }
  fprintf(fp, "\n");

  bool havePhysicals = false;
  std::vector<int> physicals;

  // print element types in ascii or binary
  fprintf(fp, "CELL_TYPES %d\n", numElements);
  for(std::size_t i = 0; i < entities.size(); i++) {
    if(entities[i]->physicals.size() || saveAll) {
      for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++) {
        int type = entities[i]->getMeshElement(j)->getTypeForVTK();
        if(type) {
          if(binary) {
            // VTK always expects big endian binary data
            if(!bigEndian) SwapBytes((char *)&type, sizeof(int), 1);
            fwrite(&type, sizeof(int), 1, fp);
          }
          else {
            fprintf(fp, "%d\n", type);
          }
          if(entities[i]->physicals.size()) {
            physicals.push_back(entities[i]->physicals[0]);
            havePhysicals = true;
          }
          else {
            physicals.push_back(-1);
          }
        }
      }
    }
  }

  if(havePhysicals && numElements == (int)physicals.size()) {
    fprintf(fp, "\n");
    fprintf(fp, "CELL_DATA %d\n", numElements);
    fprintf(fp, "SCALARS CellEntityIds int 1\n");
    fprintf(fp, "LOOKUP_TABLE default\n");
    for(int i = 0; i < numElements; i++) {
      int type = physicals[i];
      if(binary) {
        // VTK always expects big endian binary data
        if(!bigEndian) SwapBytes((char *)&type, sizeof(int), 1);
        fwrite(&type, sizeof(int), 1, fp);
      }
      else {
        fprintf(fp, "%d\n", type);
      }
    }
  }

  fclose(fp);
  return 1;
}

int GModel::readVTK(const std::string &name, bool bigEndian)
{
  FILE *fp = Fopen(name.c_str(), "rb");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  char buffer[256], buffer2[256];
  // physicals: one per dimension (0: points, 1: curves, 2: surfaces, 3: volumes)
  std::map<int, std::map<int, std::string> > physicals[4];

  // Read header lines (version and title)
  if(!fgets(buffer, sizeof(buffer), fp)) { fclose(fp); return 0; }
  if(!fgets(buffer, sizeof(buffer), fp)) { fclose(fp); return 0; }

  if(fscanf(fp, "%s", buffer) != 1)
    Msg::Error("Failed reading buffer");
  bool binary = false;
  if(!strcmp(buffer, "BINARY"))
    binary = true;

  if(fscanf(fp, "%s %s", buffer, buffer2) != 2) {
    fclose(fp);
    return 0;
  }

  bool unstructured = false;
  if(!strcmp(buffer, "DATASET") && !strcmp(buffer2, "UNSTRUCTURED_GRID"))
    unstructured = true;

  if((strcmp(buffer, "DATASET") && strcmp(buffer2, "UNSTRUCTURED_GRID")) ||
     (strcmp(buffer, "DATASET") && strcmp(buffer2, "POLYDATA"))) {
    Msg::Error("VTK reader can only read unstructured or polydata datasets");
    fclose(fp);
    return 0;
  }

  // Read mesh vertices
  int numVertices;
  if(fscanf(fp, "%s %d %s", buffer, &numVertices, buffer2) != 3) { fclose(fp); return 0; }
  if(strcmp(buffer, "POINTS") || !numVertices) {
    Msg::Warning("No points in dataset");
    fclose(fp);
    return 0;
  }
  int datasize;
  if(!strcmp(buffer2, "double"))
    datasize = sizeof(double);
  else if(!strcmp(buffer2, "float"))
    datasize = sizeof(float);
  else {
    Msg::Warning("VTK reader only accepts float or double datasets");
    fclose(fp);
    return 0;
  }
  Msg::Info("Reading %d points", numVertices);
  std::vector<MVertex *> vertices(numVertices);
  for(int i = 0; i < numVertices; i++){
    double xyz[3];
    if(binary) {
      if(datasize == sizeof(float)) {
        float f[3];
        if(fread(f, sizeof(float), 3, fp) != 3) { fclose(fp); return 0; }
        if(!bigEndian) SwapBytes((char *)f, sizeof(float), 3);
        for(int j = 0; j < 3; j++) xyz[j] = f[j];
      }
      else {
        if(fread(xyz, sizeof(double), 3, fp) != 3) { fclose(fp); return 0; }
        if(!bigEndian) SwapBytes((char *)xyz, sizeof(double), 3);
      }
    }
    else {
      if(fscanf(fp, "%lf %lf %lf", &xyz[0], &xyz[1], &xyz[2]) != 3) { fclose(fp); return 0; }
    }
    vertices[i] = new MVertex(xyz[0], xyz[1], xyz[2]);
  }

  // Read mesh elements (cells)
  int numElements, totalNumInt;
  if(fscanf(fp, "%s %d %d", buffer, &numElements, &totalNumInt) != 3) {
    fclose(fp);
    return 0;
  }

  bool haveCells = true;
  bool haveLines = false;
  if(!strcmp(buffer, "CELLS") && numElements > 0)
    Msg::Info("Reading %d cells", numElements);
  else if(!strcmp(buffer, "POLYGONS") && numElements > 0)
    Msg::Info("Reading %d polygons", numElements);
  else if(!strcmp(buffer, "LINES") && numElements > 0) {
    haveCells = false;
    haveLines = true;
    Msg::Info("Reading %d lines", numElements);
  }
  else {
    Msg::Warning("No cells or polygons in dataset");
    fclose(fp);
    return 0;
  }

  // Initialize counters using current maximum elementary numbers:
  int iPoint   = getMaxElementaryNumber(0) + 1;
  int iCurve   = getMaxElementaryNumber(1) + 1;
  int iSurface = getMaxElementaryNumber(2) + 1;
  int iVolume  = getMaxElementaryNumber(3) + 1;

  // We'll build our elements in two ways:
  // (1) In the "elements" array (an array of maps for different element types, as in the original code)
  std::map<int, std::vector<MElement *> > elements[8];
  // (2) In vectors that preserve the VTK cell order:
  std::vector<MElement*> elementOrder;       // pointer to each element (in file order)
  std::vector<int>        elementDim;         // geometric dimension (0,1,2,3) of each element
  std::vector<int>        elementOldId;       // the elementary id assigned at creation (from switch-case)

  // Read the cells (vertices per cell)
  std::vector< std::vector<MVertex *> > cells(numElements);
  for(std::size_t i = 0; i < cells.size(); i++){
    int numVerts, n[100];
    if(binary) {
      if(fread(&numVerts, sizeof(int), 1, fp) != 1) { fclose(fp); return 0; }
      if(!bigEndian) SwapBytes((char *)&numVerts, sizeof(int), 1);
      if((int)fread(n, sizeof(int), numVerts, fp) != numVerts) { fclose(fp); return 0; }
      if(!bigEndian) SwapBytes((char *)n, sizeof(int), numVerts);
    }
    else {
      if(fscanf(fp, "%d", &numVerts) != 1) { fclose(fp); return 0; }
      for(int j = 0; j < numVerts; j++){
        if(fscanf(fp, "%d", &n[j]) != 1) { fclose(fp); return 0; }
      }
    }
    for(int j = 0; j < numVerts; j++){
      if(n[j] >= 0 && n[j] < (int)vertices.size())
        cells[i].push_back(vertices[n[j]]);
      else
        Msg::Error("Wrong node index %d", n[j]);
    }
  }

  if(unstructured) {
    if(fscanf(fp, "%s %d", buffer, &numElements) != 2) { fclose(fp); return 0; }
    if(strcmp(buffer, "CELL_TYPES") || numElements != (int)cells.size()){
      Msg::Error("No or invalid number of cells types");
      fclose(fp);
      return 0;
    }
    
    for(std::size_t i = 0; i < cells.size(); i++){
      int type;
      if(binary) {
        if(fread(&type, sizeof(int), 1, fp) != 1) { fclose(fp); return 0; }
        if(!bigEndian) SwapBytes((char *)&type, sizeof(int), 1);
      }
      else {
        if(fscanf(fp, "%d", &type) != 1) { fclose(fp); return 0; }
      }
      MElement *elem = NULL;
      int oldId = -1;
      int d = -1; // dimension

      switch(type){
        case 1:
          elem = new MPoint(cells[i]);
          oldId = iPoint;
          d = 0;
          elements[0][iPoint++].push_back(elem);
          break;
        // first order elements
        case 3:
          elem = new MLine(cells[i]);
          oldId = iCurve;
          d = 1;
          elements[1][iCurve++].push_back(elem);
          break;
        case 5:
          elem = new MTriangle(cells[i]);
          oldId = iSurface;
          d = 2;
          elements[2][iSurface++].push_back(elem);
          break;
        case 9:
          elem = new MQuadrangle(cells[i]);
          oldId = iSurface;
          d = 2;
          elements[3][iSurface++].push_back(elem);
          break;
        case 10:
          elem = new MTetrahedron(cells[i]);
          oldId = iVolume;
          d = 3;
          elements[4][iVolume++].push_back(elem);
          break;
        case 12:
          elem = new MHexahedron(cells[i]);
          oldId = iVolume;
          d = 3;
          elements[5][iVolume++].push_back(elem);
          break;
        case 13:
          elem = new MPrism(cells[i]);
          oldId = iVolume;
          d = 3;
          elements[6][iVolume++].push_back(elem);
          break;
        case 14:
          elem = new MPyramid(cells[i]);
          oldId = iVolume;
          d = 3;
          elements[7][iVolume++].push_back(elem);
          break;
        // second order elements (adjust constructors as needed)
        case 21:
          elem = new MLine(cells[i]); // Replace with MLine3 if available
          oldId = iCurve;
          d = 1;
          elements[1][iCurve++].push_back(elem);
          break;
        case 22:
          elem = new MTriangle(cells[i]); // Replace with MTriangle6 if available
          oldId = iSurface;
          d = 2;
          elements[2][iSurface++].push_back(elem);
          break;
        case 23:
          elem = new MQuadrangle(cells[i]); // Replace with MQuadrangle8 if available
          oldId = iSurface;
          d = 2;
          elements[3][iSurface++].push_back(elem);
          break;
        case 28:
          elem = new MQuadrangle(cells[i]); // Replace with MQuadrangle9 if available
          oldId = iSurface;
          d = 2;
          elements[3][iSurface++].push_back(elem);
          break;
        case 24:
          elem = new MTetrahedron(cells[i]); // Replace with MTetrahedron10 if needed
          oldId = iVolume;
          d = 3;
          elements[4][iVolume++].push_back(elem);
          break;
        case 25:
          elem = new MHexahedron(cells[i]); // Replace with MHexahedron20 if needed
          oldId = iVolume;
          d = 3;
          elements[5][iVolume++].push_back(elem);
          break;
        case 29:
          elem = new MHexahedron(cells[i]); // Replace with MHexahedron27 if needed
          oldId = iVolume;
          d = 3;
          elements[5][iVolume++].push_back(elem);
          break;
        case 26:
          elem = new MPrism(cells[i]); // Replace with MPrism15 if needed
          oldId = iVolume;
          d = 3;
          elements[6][iVolume++].push_back(elem);
          break;
        case 32:
          elem = new MPrism(cells[i]); // Replace with MPrism18 if needed
          oldId = iVolume;
          d = 3;
          elements[6][iVolume++].push_back(elem);
          break;
        default:
          Msg::Error("Unknown type of cell %d", type);
          break;
      }
      // Save the element and its original elementary id and dimension in file order:
      if(elem) {
        elementOrder.push_back(elem);
        elementDim.push_back(d);
        elementOldId.push_back(oldId);
      }
    }

    // Now read the CELL_DATA section.
    if(fscanf(fp, "%s %d", buffer, &numElements) == 2 && !strcmp(buffer, "CELL_DATA")) {
      Msg::Info("Reading CELL_DATA with %d entries", numElements);
      
      char dataName[256], dataType[256];
      int numComponents;
      if(fscanf(fp, "%s %s %s %d", buffer, dataName, dataType, &numComponents) != 4 || strcmp(buffer, "SCALARS")) {
          Msg::Error("Invalid SCALARS line after CELL_DATA");
          fclose(fp);
          return 0;
      }
      
      if(fscanf(fp, "%s %s", buffer, buffer2) != 2 || strcmp(buffer, "LOOKUP_TABLE")) {
          Msg::Error("Expected LOOKUP_TABLE after SCALARS, got %s", buffer);
          fclose(fp);
          return 0;
      }
      
      // We now want to re-group cells so that elements sharing the same (dimension, physical tag)
      // receive the same elementary id. We do not want one elementary entity per cell.
      // First, for each cell (in file order) record its physical tag and build a mapping per dimension.
      std::vector<int> cellPhysTag(numElements, -1);
      // newGroup[d][physical tag] -> new elementary id
      std::map<int,int> newGroup[4];
      // New counters for each dimension:
      int newCounter[4];
      newCounter[0] = getMaxElementaryNumber(0) + 1;
      newCounter[1] = getMaxElementaryNumber(1) + 1;
      newCounter[2] = getMaxElementaryNumber(2) + 1;
      newCounter[3] = getMaxElementaryNumber(3) + 1;
      
      // For each cell (in the same order as elementOrder):
      for (int i = 0; i < numElements; i++) {
          int val;
          if (fscanf(fp, "%d", &val) != 1) {
              Msg::Error("Error reading CELL_DATA value at index %d", i);
              fclose(fp);
              return 0;
          }
          cellPhysTag[i] = val;
          int d = elementDim[i];
          // If no group exists for this physical tag in dimension d, create one.
          if(newGroup[d].find(val) == newGroup[d].end()){
              newGroup[d][val] = newCounter[d]++;
              physicals[d][ newGroup[d][val] ][ val ] = "";
          }
      }
      
      // Build a mapping from each element pointer (in file order) to its new elementary id:
      std::map<MElement*, int> elementNewId;
      for (int i = 0; i < numElements; i++){
          int d = elementDim[i];
          int newId = newGroup[d][ cellPhysTag[i] ];
          elementNewId[elementOrder[i]] = newId;
      }
      
      // Now update the original 'elements' array by re-grouping based on the new elementary id.
      // Create a new array for elements; note that we have 8 element-type groups in the original.
      std::map<int, std::vector<MElement *>> newElements[8];
      for (int t = 0; t < 8; t++){
          for (auto &pair : elements[t]) {
              for (MElement* elem : pair.second) {
                  int newId = elementNewId[elem];
                  newElements[t][newId].push_back(elem);
              }
          }
      }
      // Replace the original grouping with the new grouping:
      for (int t = 0; t < 8; t++){
          elements[t] = newElements[t];
      }
    }
  }
  else if(haveLines) {
    // Import lines if necessary (this branch is unchanged)
    if(!binary) {
      int v0, v1;
      char line[100000], *p, *pEnd, *pEnd2;
      for(int k = 0; k < numElements; k++){
        physicals[1][iCurve][1] = "centerline";
        if(!fgets(line, sizeof(line), fp)){
          fclose(fp);
          return 0;
        }
        v0 = (int)strtol(line, &pEnd, 10); // ignore first number
        v0 = (int)strtol(pEnd, &pEnd2, 10);
        p = pEnd2;
        while(1){
          v1 = strtol(p, &pEnd, 10);
          if(p == pEnd) break;
          elements[1][iCurve].push_back(new MLine(vertices[v0], vertices[v1]));
          p = pEnd;
          v0 = v1;
        }
        iCurve++;
      }
    }
    else {
      Msg::Error("Line import not done for binary VTK files");
    }
  }

  // Now store the elements into the model as usual.
  for(int i = 0; i < (int)(sizeof(elements) / sizeof(elements[0])); i++)
    _storeElementsInEntities(elements[i]);
  _associateEntityWithMeshVertices();
  _storeVerticesInEntities(vertices);

  // Finally, store the physical tags into the entities.
  for(int d = 0; d < 4; d++)
    _storePhysicalTagsInEntities(d, physicals[d]);

  fclose(fp);
  return 1;
}
