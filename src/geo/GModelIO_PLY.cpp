// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdlib.h>
#include <string.h>
#include "GmshConfig.h"
#include "GModel.h"
#include "MTriangle.h"
#include "OS.h"
#include "StringUtils.h"

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewDataList.h"
#endif

static bool getMeshVertices(int num, int *indices, std::vector<MVertex *> &vec,
                            std::vector<MVertex *> &vertices)
{
  for(int i = 0; i < num; i++) {
    if(indices[i] < 0 || indices[i] > (int)(vec.size() - 1)) {
      Msg::Error("Wrong node index %d", indices[i]);
      return false;
    }
    else
      vertices.push_back(vec[indices[i]]);
  }
  return true;
}

#if defined(HAVE_POST)
static bool getProperties(int num, int *indices, std::vector<double> &vec,
                          std::vector<double> &properties)
{
  for(int i = 0; i < num; i++) {
    if(indices[i] < 0 || indices[i] > (int)(vec.size() - 1)) {
      Msg::Error("Wrong node index %d", indices[i]);
      return false;
    }
    else
      properties.push_back(vec[indices[i]]);
  }
  return true;
}
#endif

int GModel::readPLY(const std::string &name)
{
  FILE *fp = Fopen(name.c_str(), "rb");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  std::vector<MVertex *> vertexVector;
  std::map<int, std::vector<MElement *> > elements[5];
  std::map<int, std::vector<double> > properties;

  char buffer[256], str[256], str2[256], str3[256];
  std::string s1;
  int elementary = getMaxElementaryNumber(-1) + 1;
  int nbv = 0, nbf = 0;
  int nbprop = 0;
  int nbView = 0;
  std::vector<std::string> propName;
  bool binary = false;
  bool swap = false;
  while(!feof(fp)) {
    if(!fgets(buffer, sizeof(buffer), fp)) break;
    if(buffer[0] != '#') { // skip comments
      sscanf(buffer, "%s %s", str, str2);
      if(!strcmp(str, "element") && !strcmp(str2, "vertex")) {
        sscanf(buffer, "%s %s %d", str, str2, &nbv);
      }
      if(!strcmp(str, "format") && strcmp(str2, "ascii")) {
        Msg::Warning("Reading binary PLY files is experimental");
        binary = true;
        if(!strcmp(str2, "binary_big_endian")) {
          Msg::Debug("Reading binary PLY file as big-endian");
          swap = true;
        }
      }
      if(!strcmp(str, "property") && strcmp(str2, "list")) {
        nbprop++;
        sscanf(buffer, "%s %s %s", str, str2, str3);
        if(nbprop > 3) propName.push_back(s1 + str3);
      }
      if(!strcmp(str, "element") && !strcmp(str2, "face")) {
        sscanf(buffer, "%s %s %d", str, str2, &nbf);
      }
      if(!strcmp(str, "end_header")) {
        nbView = nbprop - 3;
        Msg::Info("%d elements", nbv);
        Msg::Info("%d triangles", nbf);
        Msg::Info("%d properties", nbView);
        vertexVector.resize(nbv);
        if(!binary) {
          for(int i = 0; i < nbv; i++) {
            double x, y, z;
            char line[10000], *pEnd, *pEnd2, *pEnd3;
            if(!fgets(line, sizeof(line), fp)) {
              fclose(fp);
              return 0;
            }
            x = strtod(line, &pEnd);
            y = strtod(pEnd, &pEnd2);
            z = strtod(pEnd2, &pEnd3);
            vertexVector[i] = new MVertex(x, y, z);

            pEnd = pEnd3;
            std::vector<double> prop(nbView);
            for(int k = 0; k < nbView; k++) {
              prop[k] = strtod(pEnd, &pEnd2);
              pEnd = pEnd2;
              properties[k].push_back(prop[k]);
            }
          }

          for(int i = 0; i < nbf; i++) {
            if(!fgets(buffer, sizeof(buffer), fp)) break;
            int n[3], nbe;
            sscanf(buffer, "%d %d %d %d", &nbe, &n[0], &n[1], &n[2]);
            std::vector<MVertex *> vertices;
            if(!getMeshVertices(3, n, vertexVector, vertices)) {
              fclose(fp);
              return 0;
            }
            elements[0][elementary].push_back(new MTriangle(vertices));
          }
        }
        else { // binary
          std::size_t num_coords = 3 * nbv;
          std::vector<float> coord(num_coords);
          if(fread(&coord[0], sizeof(float), num_coords, fp) != num_coords) {
            return 0;
          }
          for(int i = 0; i < nbv; i++) {
            vertexVector[i] =
              new MVertex(coord[3 * i], coord[3 * i + 1], coord[3 * i + 2]);
          }
          // TODO add properties
          for(int i = 0; i < nbf; i++) {
            unsigned char nbe;
            int n[3]; // only handle triangles
            if(fread(&nbe, sizeof(char), 1, fp) != 1) {
              fclose(fp);
              return 0;
            }
            if(fread(n, sizeof(int), 3, fp) != 3) {
              fclose(fp);
              return 0;
            }
            if(swap) SwapBytes((char *)n, sizeof(int), 3);
            std::vector<MVertex *> vertices;
            if(!getMeshVertices(3, n, vertexVector, vertices)) {
              fclose(fp);
              return 0;
            }
            elements[0][elementary].push_back(new MTriangle(vertices));
          }
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
  std::vector<GEntity *> _entities;
  getEntities(_entities);
  for(int iV = 0; iV < nbView; iV++) {
    PView *view = new PView();
    PViewDataList *data = dynamic_cast<PViewDataList *>(view->getData());
    for(std::size_t ii = 0; ii < _entities.size(); ii++) {
      for(std::size_t i = 0; i < _entities[ii]->getNumMeshElements(); i++) {
        MElement *e = _entities[ii]->getMeshElement(i);
        int numNodes = e->getNumVertices();
        std::vector<double> x(numNodes), y(numNodes), z(numNodes);
        std::vector<double> *out = data->incrementList(1, e->getType());
        for(int nod = 0; nod < numNodes; nod++)
          out->push_back((e->getVertex(nod))->x());
        for(int nod = 0; nod < numNodes; nod++)
          out->push_back((e->getVertex(nod))->y());
        for(int nod = 0; nod < numNodes; nod++)
          out->push_back((e->getVertex(nod))->z());
        std::vector<double> props;
        int n[3];
        n[0] = e->getVertex(0)->getNum() - 1;
        n[1] = e->getVertex(1)->getNum() - 1;
        n[2] = e->getVertex(2)->getNum() - 1;
        if(!getProperties(3, n, properties[iV], props)) {
          fclose(fp);
          return 0;
        }
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
  FILE *fp = Fopen(name.c_str(), "r");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  std::vector<MVertex *> vertexVector;
  std::map<int, std::vector<MElement *> > elements[5];

  char buffer[256];
  int elementary = getMaxElementaryNumber(-1) + 1;
  int nbv, nbf;
  while(!feof(fp)) {
    if(!fgets(buffer, sizeof(buffer), fp)) break;
    if(buffer[0] != '#') { // skip comments
      sscanf(buffer, "%d", &nbv);
      if(!fgets(buffer, sizeof(buffer), fp)) break;
      sscanf(buffer, "%d", &nbf);
      Msg::Info("%d nodes", nbv);
      Msg::Info("%d triangles", nbf);
      vertexVector.resize(nbv);
      for(int i = 0; i < nbv; i++) {
        if(!fgets(buffer, sizeof(buffer), fp)) break;
        double x, y, z;
        int nb = sscanf(buffer, "%lf %lf %lf", &x, &y, &z);
        if(nb != 3) {
          if(!fgets(buffer, sizeof(buffer), fp)) break;
          sscanf(buffer, "%lf", &y);
          if(!fgets(buffer, sizeof(buffer), fp)) break;
          sscanf(buffer, "%lf", &z);
        }
        vertexVector[i] = new MVertex(x, y, z);
      }
      for(int i = 0; i < nbf; i++) {
        if(!fgets(buffer, sizeof(buffer), fp)) break;
        int n[3], nbe;
        int nb = sscanf(buffer, "%d %d %d %d", &nbe, &n[0], &n[1], &n[2]);
        if(nb != 4) {
          if(!fgets(buffer, sizeof(buffer), fp)) break;
          sscanf(buffer, "%d", &n[0]);
          if(!fgets(buffer, sizeof(buffer), fp)) break;
          sscanf(buffer, "%d", &n[1]);
          if(!fgets(buffer, sizeof(buffer), fp)) break;
          sscanf(buffer, "%d", &n[2]);
        }
        std::vector<MVertex *> vertices;
        if(!getMeshVertices(3, n, vertexVector, vertices)) {
          fclose(fp);
          return 0;
        }
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
  FILE *fp = Fopen(name.c_str(), "w");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  int numVertices = indexMeshVertices(true);
  int numTriangles = 0;
  for(auto it = firstFace(); it != lastFace(); ++it) {
    numTriangles += (*it)->triangles.size();
  }

  fprintf(fp, "%d\n", numVertices);
  fprintf(fp, "%d\n", numTriangles);

  std::vector<GEntity *> entities;
  getEntities(entities);
  for(std::size_t i = 0; i < entities.size(); i++)
    for(std::size_t j = 0; j < entities[i]->mesh_vertices.size(); j++)
      entities[i]->mesh_vertices[j]->writePLY2(fp);

  for(auto it = firstFace(); it != lastFace(); ++it) {
    for(std::size_t i = 0; i < (*it)->triangles.size(); i++)
      (*it)->triangles[i]->writePLY2(fp);
  }

  fclose(fp);
  return 1;
}
