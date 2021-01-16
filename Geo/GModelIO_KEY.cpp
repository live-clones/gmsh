// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

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
static void writeElementsKEY(FILE *fp, GEntity *ge, std::vector<T *> &elements,
                             bool saveAll)
{
  if(elements.size() && (saveAll || ge->physicals.size())) {
    const char *typ = elements[0]->getStringForKEY();
    int pid = partID(ge->dim(), ge->tag());
    if(typ) {
      fprintf(fp, "*ELEMENT%s\n$#SET_ELEMENT=%s%d\n", typ,
              physicalName(ge->model(), ge->dim(), ge->tag()).c_str(),
              ge->tag());
      for(std::size_t i = 0; i < elements.size(); i++)
        elements[i]->writeKEY(fp, pid, elements[i]->getNum());
    }
  }
}

int GModel::writeKEY(const std::string &name, int saveAll,
                     int saveGroupsOfNodes, double scalingFactor)
{
  FILE *fp = Fopen(name.c_str(), "w");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  if(noPhysicalGroups()) saveAll = 0x51;

  indexMeshVertices(saveAll & 0x51, 0, false);
  std::vector<GEntity *> entities;
  getEntities(entities);

  fprintf(fp, "$# LS-DYNA Keyword file created by Gmsh\n*KEYWORD\n*TITLE\n");
  fprintf(fp, " %s\n", name.c_str());

  fprintf(fp, "*NODE\n");
  for(std::size_t i = 0; i < entities.size(); i++)
    for(std::size_t j = 0; j < entities[i]->mesh_vertices.size(); j++)
      entities[i]->mesh_vertices[j]->writeKEY(fp, scalingFactor);

  if(!(saveAll & 0x2)) // save or ignore points (not in GUI)
    for(auto it = firstVertex(); it != lastVertex(); ++it) {
      writeElementsKEY(fp, *it, (*it)->points, saveAll & 0x1);
    }
  if(!(saveAll & 0x8)) // save or ignore line
    for(auto it = firstEdge(); it != lastEdge(); ++it) {
      writeElementsKEY(fp, *it, (*it)->lines, saveAll & 0x4);
    }
  if(!(saveAll & 0x20)) // save or ignore surface
    for(auto it = firstFace(); it != lastFace(); ++it) {
      writeElementsKEY(fp, *it, (*it)->triangles, saveAll & 0x10);
      writeElementsKEY(fp, *it, (*it)->quadrangles, saveAll & 0x10);
    }
  if(!(saveAll & 0x80)) // save or ignore volume
    for(auto it = firstRegion(); it != lastRegion(); ++it) {
      writeElementsKEY(fp, *it, (*it)->tetrahedra, saveAll & 0x40);
      writeElementsKEY(fp, *it, (*it)->hexahedra, saveAll & 0x40);
      writeElementsKEY(fp, *it, (*it)->prisms, saveAll & 0x40);
      writeElementsKEY(fp, *it, (*it)->pyramids, saveAll & 0x40);
    }

  std::map<int, std::vector<GEntity *> > groups[4];
  getPhysicalGroups(groups);

  int setid = 0;
  // save elements sets for each physical group
  if(saveGroupsOfNodes & 0x2) {
    for(int dim = 0; dim <= 3; dim++) {
      if(saveAll & (0x2 << (2 * dim))) continue; // elements are ignored
      for(auto it = groups[dim].begin(); it != groups[dim].end(); it++) {
        std::vector<GEntity *> &entities = it->second;
        int n = 0;
        for(std::size_t i = 0; i < entities.size(); i++) {
          for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++) {
            MElement *e = entities[i]->getMeshElement(j);
            if(!n) {
              const char *str = (e->getDim() == 3) ? "SOLID" :
                                (e->getDim() == 2) ? "SHELL" :
                                (e->getDim() == 1) ? "BEAM" :
                                                     "NODE";
              fprintf(fp, "*SET_%s_LIST\n$# %s\n%d", str,
                      physicalName(this, dim, it->first).c_str(), ++setid);
            }
            if(!(n % 8))
              fprintf(fp, "\n%lu", e->getNum());
            else
              fprintf(fp, ", %lu", e->getNum());
            n++;
          }
        }
        if(n) fprintf(fp, "\n");
      }
    }
  }

  // save node sets for each physical group, for easier load/b.c.
  if(saveGroupsOfNodes & 0x1) {
    for(int dim = 1; dim <= 3; dim++) {
      for(auto it = groups[dim].begin(); it != groups[dim].end(); it++) {
        std::set<MVertex *> nodes;
        std::vector<GEntity *> &entities = it->second;
        for(std::size_t i = 0; i < entities.size(); i++) {
          for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++) {
            MElement *e = entities[i]->getMeshElement(j);
            for(std::size_t k = 0; k < e->getNumVertices(); k++)
              nodes.insert(e->getVertex(k));
          }
        }
        fprintf(fp, "*SET_NODE_LIST\n$# %s\n%d",
                physicalName(this, dim, it->first).c_str(), ++setid);
        int n = 0;
        for(auto it2 = nodes.begin(); it2 != nodes.end(); it2++) {
          if(!(n % 8))
            fprintf(fp, "\n%ld", (*it2)->getIndex());
          else
            fprintf(fp, ", %ld", (*it2)->getIndex());
          n++;
        }
        if(n) fprintf(fp, "\n");
      }
    }
  }

  fprintf(fp, "*END\n");
  fclose(fp);
  return 1;
}
