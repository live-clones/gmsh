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
  if(!fgets(tmp, sizeof(tmp), fp)) return 0;
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
      for(unsigned int j = 0; j < idx.size(); j++){
        if(idx[j] < 0 || idx[j] > (int)(vertexVector.size() - 1)){
          Msg::Error("Wrong vertex index %d", idx[j]);
          return 0;
        }
        else
          vertices.push_back(vertexVector[idx[j]]);
      }
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
  int region = getMaxElementaryNumber(-1);
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
        region++;
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
