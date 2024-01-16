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

template <class T>
static void writeElementsINP(FILE *fp, GEntity *ge, std::vector<T *> &elements,
                             bool saveAll)
{
  if(elements.size() && (saveAll || ge->physicals.size())) {
    const char *typ = elements[0]->getStringForINP();
    if(typ) {
      const char *str = (ge->dim() == 3) ? "Volume" :
                        (ge->dim() == 2) ? "Surface" :
                        (ge->dim() == 1) ? "Line" :
                                           "Point"; // currently unused
      fprintf(fp, "*ELEMENT, type=%s, ELSET=%s%d\n", typ, str, ge->tag());
      for(std::size_t i = 0; i < elements.size(); i++)
        elements[i]->writeINP(fp, elements[i]->getNum());
    }
  }
}

static std::string physicalName(GModel *m, int dim, int num)
{
  std::string name = m->getPhysicalName(dim, num);
  if(name.empty()) {
    char tmp[256];
    sprintf(tmp, "%s%d",
            (dim == 3) ? "PhysicalVolume" :
            (dim == 2) ? "PhysicalSurface" :
            (dim == 1) ? "PhysicalLine" :
                         "PhysicalPoint",
            num);
    name = tmp;
  }
  for(std::size_t i = 0; i < name.size(); i++)
    if(name[i] == ' ') name[i] = '_';
  return name;
}

int GModel::writeINP(const std::string &name, bool saveAll,
                     int saveGroupsOfElements, int saveGroupsOfNodes,
                     double scalingFactor)
{
  FILE *fp = Fopen(name.c_str(), "w");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  if(noPhysicalGroups()) saveAll = true;

  indexMeshVertices(saveAll, 0, false);
  std::vector<GEntity *> entities;
  getEntities(entities);

  fprintf(fp, "*Heading\n");
  fprintf(fp, " %s\n", name.c_str());

  fprintf(fp, "*NODE\n");
  for(std::size_t i = 0; i < entities.size(); i++)
    for(std::size_t j = 0; j < entities[i]->mesh_vertices.size(); j++)
      entities[i]->mesh_vertices[j]->writeINP(fp, scalingFactor);

  fprintf(fp, "******* E L E M E N T S *************\n");
  // a negative value of saveGroupsOfElements can be used to prevent saving
  // elements of dimension dim, if the (dim+1)^th least significant digit of
  // -saveGroupsOfElements is equal to 0. This is useful to be able to e.g. only
  // have 3D elements in the output file, but node sets identified by physical
  // surfaces or curves. Cf. #1664 and the comments below for the underlying
  // rationale
  if(saveGroupsOfElements >= 0 || ((-saveGroupsOfElements / 1) % 10)){
    for(auto it = firstVertex(); it != lastVertex(); ++it) {
      writeElementsINP(fp, *it, (*it)->points, saveAll);
    }
  }
  if(saveGroupsOfElements >= 0 || ((-saveGroupsOfElements / 10) % 10)){
    for(auto it = firstEdge(); it != lastEdge(); ++it) {
      writeElementsINP(fp, *it, (*it)->lines, saveAll);
    }
  }
  if(saveGroupsOfElements >= 0 || ((-saveGroupsOfElements / 100) % 10)){
    for(auto it = firstFace(); it != lastFace(); ++it) {
      writeElementsINP(fp, *it, (*it)->triangles, saveAll);
      writeElementsINP(fp, *it, (*it)->quadrangles, saveAll);
    }
  }
  if(saveGroupsOfElements >= 0 || ((-saveGroupsOfElements / 1000) % 10)){
    for(auto it = firstRegion(); it != lastRegion(); ++it) {
      writeElementsINP(fp, *it, (*it)->tetrahedra, saveAll);
      writeElementsINP(fp, *it, (*it)->hexahedra, saveAll);
      writeElementsINP(fp, *it, (*it)->prisms, saveAll);
      writeElementsINP(fp, *it, (*it)->pyramids, saveAll);
    }
  }

  std::map<int, std::vector<GEntity *> > groups[4];
  getPhysicalGroups(groups);

  if(saveGroupsOfElements) {
    // save elements sets for each physical group (currently we don't save point
    // elements: is there this concept in Abaqus?) if saveGroupsOfElements is
    // positive; if saveGroupsOfElements is negative, only save groups of
    // dimension dim if the (dim+1)^th least significant digit of
    // -saveGroupsOfElements is 1 (for example: -100 will only save surfaces,
    // while -1010 will save volumes and curves)
    for(int dim = 1; dim <= 3; dim++) {
      if(saveGroupsOfElements > 0 ||
         (saveGroupsOfElements < 0 &&
          ((-saveGroupsOfElements / (int)std::pow(10, dim)) % 10) == 1)) {
        for(auto it = groups[dim].begin(); it != groups[dim].end(); it++) {
          std::vector<GEntity *> &ent = it->second;
          fprintf(fp, "*ELSET,ELSET=%s\n",
                  physicalName(this, dim, it->first).c_str());
          int n = 0;
          for(std::size_t i = 0; i < ent.size(); i++) {
            for(std::size_t j = 0; j < ent[i]->getNumMeshElements(); j++) {
              MElement *e = ent[i]->getMeshElement(j);
              if(n && !(n % 10)) fprintf(fp, "\n");
              fprintf(fp, "%lu, ", e->getNum());
              n++;
            }
          }
          fprintf(fp, "\n");
        }
      }
    }
  }

  if(saveGroupsOfNodes) {
    for(int dim = 0; dim <= 3; dim++) {
      // save a node set for each physical group (here we include node sets on
      // physical points) if saveGroupsOfNodes is positive; if saveGroupsOfNodes
      // is negative and the (dim+1)^th least significant digit of
      // -saveGroupsOfNodes is equal to 1, save groups of dimension dim
      if(saveGroupsOfNodes > 0 ||
         (saveGroupsOfNodes < 0 &&
          ((-saveGroupsOfNodes / (int)std::pow(10, dim)) % 10) == 1)) {
        for(auto it = groups[dim].begin(); it != groups[dim].end(); it++) {
          std::set<MVertex *, MVertexPtrLessThan> nodes;
          std::vector<GEntity *> &ent = it->second;
          for(std::size_t i = 0; i < ent.size(); i++) {
            for(std::size_t j = 0; j < ent[i]->getNumMeshElements(); j++) {
              MElement *e = ent[i]->getMeshElement(j);
              for(std::size_t k = 0; k < e->getNumVertices(); k++)
                nodes.insert(e->getVertex(k));
            }
          }
          fprintf(fp, "*NSET,NSET=%s\n",
                  physicalName(this, dim, it->first).c_str());
          int n = 0;
          for(auto it2 = nodes.begin(); it2 != nodes.end(); it2++) {
            if(n && !(n % 10)) fprintf(fp, "\n");
            fprintf(fp, "%ld, ", (*it2)->getIndex());
            n++;
          }
          fprintf(fp, "\n");
        }
      }

      // if saveGroupsOfNodes is negative and the (dim+1)^th least significant
      // digit of -saveGroupsOfNodes is equal to 2, save node sets for each
      // entity of dimension dim. This is dangerous (the nodes in the group
      // could reference nodes whose coordinates are not saved in the file), but
      // useful for some workflows (cf. #1664)
      if(saveGroupsOfNodes < 0  &&
         ((-saveGroupsOfNodes / (int)std::pow(10, dim)) % 10) == 2) {
        std::vector<GEntity *> ent;
        getEntities(ent, dim);
        for(std::size_t i = 0; i < ent.size(); i++) {
          std::set<MVertex *, MVertexPtrLessThan> nodes;
          for(std::size_t j = 0; j < ent[i]->getNumMeshElements(); j++) {
            MElement *e = ent[i]->getMeshElement(j);
            for(std::size_t k = 0; k < e->getNumVertices(); k++)
              nodes.insert(e->getVertex(k));
          }
          if(nodes.size()) {
            fprintf(fp, "*NSET,NSET=%s%d\n",
                    (dim == 3) ? "Volume" : (dim == 2) ? "Surface" :
                    (dim == 1) ? "Line" : "Point", ent[i]->tag());
            int n = 0;
            for(auto it2 = nodes.begin(); it2 != nodes.end(); it2++) {
              if(n && !(n % 10)) fprintf(fp, "\n");
              fprintf(fp, "%ld, ", (*it2)->getIndex());
              n++;
            }
            fprintf(fp, "\n");
          }
        }
      }
    }
  }

  fclose(fp);
  return 1;
}
