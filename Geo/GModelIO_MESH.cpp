// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <stdlib.h>
#include <string.h>
#include "GModel.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"

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
  std::map<int, std::vector<MElement*> > elements[5];

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
          elements[0][cl].push_back(new MLine(vertices));
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
          elements[1][cl].push_back(new MTriangle(vertices));
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
          elements[2][cl].push_back(new MQuadrangle(vertices));
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
          elements[3][cl].push_back(new MTetrahedron(vertices));
        }
      }
      else if(!strcmp(str, "Hexahedra")) {
        if(!fgets(buffer, sizeof(buffer), fp)) break;
        int nbe;
        sscanf(buffer, "%d", &nbe);
        Msg::Info("%d hexahedra", nbe);
        for(int i = 0; i < nbe; i++) {
          if(!fgets(buffer, sizeof(buffer), fp)) break;
          int n[8], cl;
          sscanf(buffer, "%d %d %d %d %d %d %d %d %d", &n[0], &n[1], &n[2], &n[3],
                 &n[4], &n[5], &n[6], &n[7], &cl);
          for(int j = 0; j < 8; j++) n[j]--;
          std::vector<MVertex*> vertices;
          if(!getVertices(8, n, vertexVector, vertices)) return 0;
          elements[4][cl].push_back(new MHexahedron(vertices));
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

  int numEdges = 0, numTriangles = 0, numQuadrangles = 0;
  int numTetrahedra = 0, numHexahedra = 0;
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
      numHexahedra += (*it)->hexahedra.size();
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
  if(numHexahedra){
    fprintf(fp, " Hexahedra\n");
    fprintf(fp, " %d\n", numHexahedra);
    for(riter it = firstRegion(); it != lastRegion(); ++it){
      int numPhys = (*it)->physicals.size();
      if(saveAll || numPhys){
        for(unsigned int i = 0; i < (*it)->hexahedra.size(); i++)
          (*it)->hexahedra[i]->writeMESH(fp, elementTagType, (*it)->tag(),
                                         numPhys ? (*it)->physicals[0] : 0);
      }
    }
  }

  fprintf(fp, " End\n");

  fclose(fp);
  return 1;
}






