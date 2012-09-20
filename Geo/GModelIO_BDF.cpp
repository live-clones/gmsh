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
