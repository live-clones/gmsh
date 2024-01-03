// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Paul Sharp

#include "GModel.h"
#include "OS.h"
#include "MPoint.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"

static std::string physicalName(GModel *m, int dim, int num)
{
  std::string name = m->getPhysicalName(dim, num);
  if(name.empty()) {
    char tmp[256];
    sprintf(tmp, "%s%d",
            (dim == 3) ? "PhysicalVolume" :
            (dim == 2) ? "PhysicalSurface" :
                         "PhysicalLine",
            num);
    name = tmp;
  }
  for(std::size_t i = 0; i < name.size(); i++)
    if(name[i] == ' ') name[i] = '_';
  return name;
}

static int partID(int dim, int num) { return dim * 1000000 + num; }

template <class T>
static void writeElementsRAD(FILE *fp, GEntity *ge, std::vector<T *> &elements,
                             bool saveAll)
{
  if(elements.size() && (saveAll || ge->physicals.size())) {
    const char *typ = elements[0]->getStringForRAD();
    int pid = partID(ge->dim(), ge->tag());
    if(typ) {
      fprintf(fp, "%s/%d\n#SET_ELEMENT=%s%d\n", typ, pid,
              physicalName(ge->model(), ge->dim(), ge->tag()).c_str(),
              ge->tag());
      for(std::size_t i = 0; i < elements.size(); i++)
        elements[i]->writeRAD(fp, elements[i]->getNum());
    }
  }
}

int GModel::writeRAD(const std::string &name, int saveAll,
                     int saveGroupsOfNodes, double scalingFactor)
{
  FILE *fp = Fopen(name.c_str(), "w");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  // FIXME: we should probably use the same conventions here as in the UNV, INP
  // and TOCHNOG writer, i.e. not mess around with saveAll, and use negative
  // saveGroupsOfNodes to selectively save groups of different dimensions.

  if(noPhysicalGroups()) saveAll = 0x51;

  indexMeshVertices(saveAll & 0x51, 0, false);
  std::vector<GEntity *> entities;
  getEntities(entities);
  std::string beginname = name;
  std::size_t n = name.find_last_of("/");
  if(n != std::string::npos) { beginname = name.substr(n + 1); }

  n = beginname.find("_0000.rad");
  if(n != std::string::npos) { beginname = beginname.substr(0, n); }

  n = beginname.find(".rad");
  if(n != std::string::npos) { beginname = beginname.substr(0, n); }

  fprintf(fp, "#RADIOSS STARTER\n");
  fprintf(fp, "#---1----|----2----|----3----|----4----|----5----|----6----|"
              "----7----|----8----|----9----|---10----|\n");
  fprintf(fp, "# Created by Gmsh, Radioss Mesh Interface by PaulAltair "
              "sharp@altair.com\n");
  fprintf(fp, "#---1----|----2----|----3----|----4----|----5----|----6----|"
              "----7----|----8----|----9----|---10----|\n");
  fprintf(fp, "/BEGIN\n");
  fprintf(fp, "%s\n", beginname.c_str());
  fprintf(fp, "      2022         0\n");
  fprintf(fp, "                  Mg                  mm                   s\n");
  fprintf(fp, "                  Mg                  mm                   s\n");
  fprintf(fp, "/NODE\n");
  for(std::size_t i = 0; i < entities.size(); i++)
    for(std::size_t j = 0; j < entities[i]->mesh_vertices.size(); j++)
      entities[i]->mesh_vertices[j]->writeRAD(fp, scalingFactor);

  if(!(saveAll & 0x2)) // save or ignore points (not in GUI)
    for(auto it = firstVertex(); it != lastVertex(); ++it) {
      writeElementsRAD(fp, *it, (*it)->points, saveAll & 0x1);
    }
  if(!(saveAll & 0x8)) // save or ignore line
    for(auto it = firstEdge(); it != lastEdge(); ++it) {
      writeElementsRAD(fp, *it, (*it)->lines, saveAll & 0x4);
    }
  if(!(saveAll & 0x20)) // save or ignore surface
    for(auto it = firstFace(); it != lastFace(); ++it) {
      writeElementsRAD(fp, *it, (*it)->triangles, saveAll & 0x10);
      writeElementsRAD(fp, *it, (*it)->quadrangles, saveAll & 0x10);
    }
  if(!(saveAll & 0x80)) // save or ignore volume
    for(auto it = firstRegion(); it != lastRegion(); ++it) {
      writeElementsRAD(fp, *it, (*it)->tetrahedra, saveAll & 0x40);
      writeElementsRAD(fp, *it, (*it)->hexahedra, saveAll & 0x40);
      writeElementsRAD(fp, *it, (*it)->prisms, saveAll & 0x40);
    }

  std::map<int, std::vector<GEntity *> > groups[4];
  getPhysicalGroups(groups);

  int setid = 0;
  // save elements sets for each physical group
  if(saveGroupsOfNodes & 0x2) {
    for(int dim = 0; dim <= 3; dim++) {
      if(saveAll & (0x2 << (2 * dim))) continue; // elements are ignored
      if(dim == 2) { // Handle SH3N elements
        for(auto it = groups[dim].begin(); it != groups[dim].end(); it++) {
          std::vector<GEntity *> &entities = it->second;
          if(entities.empty()) continue; // Skip empty sets
          int n = 0;
          for(std::size_t i = 0; i < entities.size(); i++) {
            for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++) {
              MElement *e = entities[i]->getMeshElement(j);
              if(e->getNumVertices() == 3) { // Process only SH3N elements (3 vertices)
                if(!n) {
                  fprintf(fp, "/GRSH3N/SH3N/%d\n%s", ++setid, physicalName(this, dim, it->first).c_str());
                }
                if(!(n % 8))
                  fprintf(fp, "\n%10ld", e->getNum());
                else
                  fprintf(fp, "%10ld", e->getNum());
                n++;
              }
            }
          }
          if(n) fprintf(fp, "\n");
        }
      }
    }
  }
  if(saveGroupsOfNodes & 0x2) {
    for(int dim = 0; dim <= 3; dim++) {
      if(saveAll & (0x2 << (2 * dim))) continue; // elements are ignored
      if(dim == 2) { // Handle SHEL elements
        for(auto it = groups[dim].begin(); it != groups[dim].end(); it++) {
          std::vector<GEntity *> &entities = it->second;
          if(entities.empty()) continue; // Skip empty sets
          int n = 0;
          for(std::size_t i = 0; i < entities.size(); i++) {
            for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++) {
              MElement *e = entities[i]->getMeshElement(j);
              if(e->getNumVertices() == 4) { // Process only SHEL elements (4 vertices)
                if(!n) {
                  fprintf(fp, "/GRSHEL/SHEL/%d\n%s", ++setid, physicalName(this, dim, it->first).c_str());
                }
                if(!(n % 8))
                  fprintf(fp, "\n%10ld", e->getNum());
                else
                  fprintf(fp, "%10ld", e->getNum());
                n++;
              }
            }
          }
          if(n) fprintf(fp, "\n");
        }
      }
    }
  }

  if(saveGroupsOfNodes & 0x2) {
    for(int dim = 0; dim <= 3; dim++) {
      if(dim == 3) { // Handle BRIC elements
        if(saveAll & (0x2 << (2 * dim))) continue; // elements are ignored
        for(auto it = groups[dim].begin(); it != groups[dim].end(); it++) {
          std::vector<GEntity *> &entities = it->second;
          if(entities.empty()) continue; // Skip empty sets
          int n = 0;
          for(std::size_t i = 0; i < entities.size(); i++) {
            for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++) {
              MElement *e = entities[i]->getMeshElement(j);
              if(e->getDim() == 3) { // Process only BRIC elements with three dimensions
                if(!n) {
                  fprintf(fp, "/GRBRIC/BRIC/%d\n%s", ++setid, physicalName(this, dim, it->first).c_str());
                }
                if(!(n % 8))
                  fprintf(fp, "\n%10ld", e->getNum());
                else
                  fprintf(fp, "%10ld", e->getNum());
                n++;
              }
            }
          }
          if(n) fprintf(fp, "\n");
        }
      }
    }
  }

  // save node sets for each physical group, for easier load/b.c.
  if(saveGroupsOfNodes & 0x1) {
    for(int dim = 1; dim <= 3; dim++) {
      for(auto it = groups[dim].begin(); it != groups[dim].end(); it++) {
        std::set<MVertex *> nodes;
        std::vector<GEntity *> &entities = it->second;
        bool hasNodes = false; // Flag to track if there are any nodes
        for(std::size_t i = 0; i < entities.size(); i++) {
          for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++) {
            MElement *e = entities[i]->getMeshElement(j);
            for(std::size_t k = 0; k < e->getNumVertices(); k++) {
              nodes.insert(e->getVertex(k));
              hasNodes = true;
            }
          }
        }
        if (!hasNodes) continue; // Skip empty sets
        fprintf(fp, "/GRNOD/NODE/%d\n%s",
                ++setid, physicalName(this, dim, it->first).c_str());
        int n = 0;
        for(auto it2 = nodes.begin(); it2 != nodes.end(); it2++) {
          if(!(n % 8))
            fprintf(fp, "\n%10ld", (*it2)->getIndex());
          else
            fprintf(fp, "%10ld", (*it2)->getIndex());
          n++;
        }
        if(n) fprintf(fp, "\n");
      }
    }
  }

  fprintf(fp, "/END");
  fclose(fp);
  return 1;
}
