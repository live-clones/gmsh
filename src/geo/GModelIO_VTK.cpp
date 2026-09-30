// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Florian Blachère

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
#include "MElement.h"
#include "ElementType.h"
#include "VTKXML.h"
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
  std::size_t numVertices = indexMeshVertices(saveAll);

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
  fprintf(fp, "POINTS %zu double\n", numVertices);
  for(std::size_t i = 0; i < entities.size(); i++)
    for(std::size_t j = 0; j < entities[i]->mesh_vertices.size(); j++)
      entities[i]->mesh_vertices[j]->writeVTK(fp, binary, scalingFactor,
                                              bigEndian);
  fprintf(fp, "\n");

  // loop over all elements we need to save and count vertices
  std::size_t numElements = 0, totalNumInt = 0;
  for(std::size_t i = 0; i < entities.size(); i++) {
    if(entities[i]->physicals.size() || saveAll) {
      for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++) {
        if(entities[i]->getMeshElement(j)->getTypeForVTK()) {
          numElements++;
          totalNumInt +=
            entities[i]->getMeshElement(j)->getNumVerticesVTK() + 1;
        }
      }
    }
  }

  // print vertex indices in ascii or binary
  fprintf(fp, "CELLS %zu %zu\n", numElements, totalNumInt);
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
  fprintf(fp, "CELL_TYPES %zu\n", numElements);
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

  if(havePhysicals && numElements == physicals.size()) {
    fprintf(fp, "\n");
    fprintf(fp, "CELL_DATA %zu\n", numElements);
    fprintf(fp, "SCALARS CellEntityIds int 1\n");
    fprintf(fp, "LOOKUP_TABLE default\n");
    for(std::size_t i = 0; i < numElements; i++) {
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

// binary data starts on the line after the keyword that announces it
static void skipToNextLine(FILE *fp)
{
  int c;
  while((c = fgetc(fp)) != EOF && c != '\n') {}
}

int GModel::readVTK(const std::string &name, bool bigEndian)
{
  FILE *fp = Fopen(name.c_str(), "rb");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  char buffer[256], buffer2[256];
  std::map<int, std::map<int, std::string>> physicals[4];

  if(!fgets(buffer, sizeof(buffer), fp)) {
    fclose(fp);
    return 0;
  } // version line
  if(!fgets(buffer, sizeof(buffer), fp)) {
    fclose(fp);
    return 0;
  } // title

  if(fscanf(fp, "%s", buffer) != 1) // ASCII or BINARY
    Msg::Error("Failed reading buffer");
  bool binary = false;
  if(!strcmp(buffer, "BINARY")) binary = true;

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

  // read mesh vertices
  std::size_t numVertices;
  if(fscanf(fp, "%s %zu %s", buffer, &numVertices, buffer2) != 3) return 0;
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
  Msg::Info("Reading %zu points", numVertices);
  if(binary) skipToNextLine(fp);
  std::vector<MVertex *> vertices(numVertices);
  for(std::size_t i = 0; i < numVertices; i++) {
    double xyz[3];
    if(binary) {
      if(datasize == sizeof(float)) {
        float f[3];
        if(fread(f, sizeof(float), 3, fp) != 3) {
          fclose(fp);
          return 0;
        }
        if(!bigEndian) SwapBytes((char *)f, sizeof(float), 3);
        for(int j = 0; j < 3; j++) xyz[j] = f[j];
      }
      else {
        if(fread(xyz, sizeof(double), 3, fp) != 3) {
          fclose(fp);
          return 0;
        }
        if(!bigEndian) SwapBytes((char *)xyz, sizeof(double), 3);
      }
    }
    else {
      if(fscanf(fp, "%lf %lf %lf", &xyz[0], &xyz[1], &xyz[2]) != 3) {
        fclose(fp);
        return 0;
      }
    }
    vertices[i] = new MVertex(xyz[0], xyz[1], xyz[2]);
  }

  // read mesh elements
  std::size_t numElements, totalNumInt;
  if(fscanf(fp, "%s %zu %zu", buffer, &numElements, &totalNumInt) != 3) {
    fclose(fp);
    return 0;
  }

  if(binary) skipToNextLine(fp);

  bool haveCells = true;
  bool haveLines = false;
  if(!strcmp(buffer, "CELLS") && numElements > 0)
    Msg::Info("Reading %zu cells", numElements);
  else if(!strcmp(buffer, "POLYGONS") && numElements > 0)
    Msg::Info("Reading %zu polygons", numElements);
  else if(!strcmp(buffer, "LINES") && numElements > 0) {
    haveCells = false;
    haveLines = true;
    Msg::Info("Reading %zu lines", numElements);
  }
  else {
    Msg::Warning("No cells or polygons in dataset");
    fclose(fp);
    return 0;
  }

  int iPoint = getMaxElementaryNumber(0) + 1;
  int iCurve = getMaxElementaryNumber(1) + 1;
  int iSurface = getMaxElementaryNumber(2) + 1;
  int iVolume = getMaxElementaryNumber(3) + 1;

  std::map<int, std::vector<MElement *>> elements[8];

  if(haveCells) {
    std::vector<std::vector<MVertex *>> cells(numElements);
    for(std::size_t i = 0; i < cells.size(); i++) {
      int numVerts, n[100];
      if(binary) {
        if(fread(&numVerts, sizeof(int), 1, fp) != 1) {
          fclose(fp);
          return 0;
        }
        if(!bigEndian) SwapBytes((char *)&numVerts, sizeof(int), 1);
        if((int)fread(n, sizeof(int), numVerts, fp) != numVerts) {
          fclose(fp);
          return 0;
        }
        if(!bigEndian) SwapBytes((char *)n, sizeof(int), numVerts);
      }
      else {
        if(fscanf(fp, "%d", &numVerts) != 1) {
          fclose(fp);
          return 0;
        }
        for(int j = 0; j < numVerts; j++) {
          if(fscanf(fp, "%d", &n[j]) != 1) {
            fclose(fp);
            return 0;
          }
        }
      }
      for(int j = 0; j < numVerts; j++) {
        if(n[j] >= 0 && n[j] < (int)vertices.size())
          cells[i].push_back(vertices[n[j]]);
        else
          Msg::Error("Wrong node index %d", n[j]);
      }
    }

    if(unstructured) {
      if(fscanf(fp, "%s %zu", buffer, &numElements) != 2) {
        fclose(fp);
        return 0;
      }
      if(strcmp(buffer, "CELL_TYPES") || numElements != cells.size()) {
        Msg::Error("No or invalid number of cells types");
        fclose(fp);
        return 0;
      }
      if(binary) skipToNextLine(fp);
      MElementFactory factory;
      std::vector<MElement *> created(cells.size(), nullptr);
      for(std::size_t i = 0; i < cells.size(); i++) {
        int type;
        if(binary) {
          if(fread(&type, sizeof(int), 1, fp) != 1) {
            fclose(fp);
            return 0;
          }
          if(!bigEndian) SwapBytes((char *)&type, sizeof(int), 1);
        }
        else {
          if(fscanf(fp, "%d", &type) != 1) {
            fclose(fp);
            return 0;
          }
        }
        // the element and its node ordering, as for the .vtu files
        int numVerts = cells[i].size();
        int mshType = getMSHTypeOfVTKXMLCell(type, numVerts);
        if(!mshType) {
          Msg::Error("Unknown type of cell %d (with %d nodes)", type, numVerts);
          continue;
        }
        const vtkXMLCell &cell = getVTKXMLCell(mshType);
        if(type == 72) {
          // as VTK reads the Lagrange hexahedra of this version of the
          // format: with the 11th and 12th edges swapped
          int perEdge = ElementType::getOrder(mshType) - 1;
          for(int k = 0; k < perEdge; k++)
            std::swap(cells[i][8 + 10 * perEdge + k],
                      cells[i][8 + 11 * perEdge + k]);
        }
        std::vector<MVertex *> v(numVerts);
        for(int k = 0; k < numVerts; k++) v[cell.nodes[k]] = cells[i][k];
        created[i] = factory.create(mshType, v);
      }

      // the physical groups, as Gmsh writes them: an entity per group
      std::vector<int> ids;
      int numComp = 0;
      std::size_t numData = 0;
      if(fscanf(fp, "%s %zu", buffer, &numData) == 2 &&
         !strcmp(buffer, "CELL_DATA") && numData == cells.size() &&
         fscanf(fp, "%s %s %s %d", buffer, buffer2, buffer, &numComp) == 4 &&
         !strcmp(buffer2, "CellEntityIds") && !strcmp(buffer, "int") &&
         numComp == 1 && fscanf(fp, "%s %s", buffer, buffer2) == 2) {
        ids.resize(cells.size(), 0);
        if(binary) {
          skipToNextLine(fp);
          if(fread(&ids[0], sizeof(int), ids.size(), fp) != ids.size())
            ids.clear();
          else if(!bigEndian)
            SwapBytes((char *)&ids[0], sizeof(int), ids.size());
        }
        else {
          for(auto &id : ids)
            if(fscanf(fp, "%d", &id) != 1) id = 0;
        }
      }

      for(std::size_t i = 0; i < cells.size(); i++) {
        MElement *e = created[i];
        if(!e) continue;
        int id = (i < ids.size() && ids[i] > 0) ? ids[i] : 0;
        int dim = e->getDim();
        int tag = (dim == 0) ? iPoint++ :
                  ((dim == 1) ? iCurve : (dim == 2) ? iSurface : iVolume) + id;
        if(id) physicals[dim][tag][id] = "";
        switch(e->getType()) {
        case TYPE_PNT: elements[0][tag].push_back(e); break;
        case TYPE_LIN: elements[1][tag].push_back(e); break;
        case TYPE_TRI: elements[2][tag].push_back(e); break;
        case TYPE_QUA: elements[3][tag].push_back(e); break;
        case TYPE_TET: elements[4][tag].push_back(e); break;
        case TYPE_HEX: elements[5][tag].push_back(e); break;
        case TYPE_PRI: elements[6][tag].push_back(e); break;
        case TYPE_PYR: elements[7][tag].push_back(e); break;
        default: delete e; break;
        }
      }
    }
    else {
      for(std::size_t i = 0; i < cells.size(); i++) {
        int nbNodes = (int)cells[i].size();
        switch(nbNodes) {
        case 1: elements[0][iPoint++].push_back(new MPoint(cells[i])); break;
        case 2: elements[1][iCurve].push_back(new MLine(cells[i])); break;
        case 3: elements[2][iSurface].push_back(new MTriangle(cells[i])); break;
        case 4:
          elements[3][iSurface].push_back(new MQuadrangle(cells[i]));
          break;
        default:
          Msg::Error("Unknown type of mesh element with %d nodes", nbNodes);
          break;
        }
      }
    }
  }
  else if(haveLines) {
    if(!binary) {
      int v0, v1;
      char line[100000], *p, *pEnd, *pEnd2;
      for(std::size_t k = 0; k < numElements; k++) {
        physicals[1][iCurve][1] = "centerline";
        if(!fgets(line, sizeof(line), fp)) {
          fclose(fp);
          return 0;
        }
        v0 = (int)strtol(line, &pEnd, 10); // ignore first line
        v0 = (int)strtol(pEnd, &pEnd2, 10);
        p = pEnd2;
        while(1) {
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

  for(int i = 0; i < (int)(sizeof(elements) / sizeof(elements[0])); i++)
    _storeElementsInEntities(elements[i]);
  _associateEntityWithMeshVertices();
  _storeVerticesInEntities(vertices);

  // store the physical tags
  for(int i = 0; i < 4; i++) _storePhysicalTagsInEntities(i, physicals[i]);

  fclose(fp);
  return 1;
}
