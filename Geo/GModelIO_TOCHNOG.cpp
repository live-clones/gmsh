// Gmsh - Copyright (C) 1997-2015 C. Geuzaine, J.-F. Remacle
//
// Authors: Roman Putanowicz and Fernando Lorenzo
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include "OS.h"
#include "MPoint.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "StringUtils.h"
#include "GModel.h"

int dimension;

template <class T>
static void writeElementsTOCHNOG(FILE *fp, GEntity *ge,
                                 std::vector<T *> &elements, bool saveAll)
{
  if(elements.size() && (saveAll || ge->physicals.size())) {
    const char *typ = elements[0]->getStringForTOCHNOG();
    if(typ) {
      // const char *str = (ge->dim() == 3) ? " 3 " : (ge->dim() == 2) ?
      //  " 2 " : (ge->dim() == 1) ? " 1 " : "Point";
      // fprintf(fp, "( 'number_of_space_dimensions   %s)\n", str);
      for(std::size_t i = 0; i < elements.size(); i++)
        elements[i]->writeTOCHNOG(fp, elements[i]->getNum());
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

int GModel::writeTOCHNOG(const std::string &name, bool saveAll,
                         bool saveGroupsOfNodes, double scalingFactor)
{
  FILE *fp = Fopen(name.c_str(), "w");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  fprintf(fp, "(----Tochnog Input File Created by Gmsh Version 2.13.1 ----)\n");
  fprintf(fp, " \n");
  fprintf(fp, "(**EDIT OR MODIFY THE ENTRIES BELOW AS REQUIRED**)\n"
              "echo  -yes \n"
              "number of space dimensions (add number here) \n"
              "derivatives \n"
              "materi_velocity \n"
              "materi_displacement \n"
              "materi_strain_total  \n"
              "materi_stress  \n"
              "condif_temperature \n"
              "number_of_integration_points (add number here) \n"
              "end_initia \n"
              "options_element_dof -yes  \n");
  fprintf(fp, "\n");

  // Nodes
  /* Save vertices */
  fprintf(fp, "(----------------Nodes----------------)\n");
  fprintf(fp, "\n");
  int dim = getDim();
  if(noPhysicalGroups()) saveAll = true;

  indexMeshVertices(saveAll, 0, false);
  std::vector<GEntity *> entities;
  getEntities(entities);

  for(std::size_t i = 0; i < entities.size(); i++)
    for(std::size_t j = 0; j < entities[i]->mesh_vertices.size(); j++)
      entities[i]->mesh_vertices[j]->writeTOCHNOG(fp, dim, scalingFactor);
  fprintf(fp, "\n");
  // Nodes
  // Elements
  fprintf(fp, "(++++++++++++++ E L E M E N T S ++++++++++++++)\n");
  fprintf(fp, "\n");
  for(auto it = firstVertex(); it != lastVertex(); ++it) {
    writeElementsTOCHNOG(fp, *it, (*it)->points, saveAll);
  }

  if(dim == 3) {
    for(auto it = firstRegion(); it != lastRegion(); ++it) {
      writeElementsTOCHNOG(fp, *it, (*it)->tetrahedra, saveAll);
      writeElementsTOCHNOG(fp, *it, (*it)->hexahedra, saveAll);
    }
  }
  else if(dim == 2) {
    for(auto it = firstFace(); it != lastFace(); ++it) {
      writeElementsTOCHNOG(fp, *it, (*it)->triangles, saveAll);
      writeElementsTOCHNOG(fp, *it, (*it)->quadrangles, saveAll);
    }
  }
  else if(dim == 1) {
    for(auto it = firstEdge(); it != lastEdge(); ++it) {
      writeElementsTOCHNOG(fp, *it, (*it)->lines, saveAll);
    }
  }

  fprintf(fp, "\n");

  // Elements

  std::map<int, std::vector<GEntity *> > groups[4];
  getPhysicalGroups(groups);
  fprintf(fp, "( +------------+---------Physical Groups "
              "Section----------+------------+\n");
  fprintf(fp, "\n");
  fprintf(fp, "- In Tochnog use Physical Groups to define 'element_group' "
              "entities to  -\n");
  fprintf(fp, "- identify materials, and groups of nodes to apply boundary "
              "conditions -)\n");
  fprintf(fp, "\n");
  fprintf(fp, "(- For example, groups of ELEMENTS chosen using gmsh 'physical "
              "groups' can be used as follows)\n");
  fprintf(fp, "(- element_group  -ra INSERT HERE GROUP OF ELEMENTS SAVED WITH "
              "GMSH -ra  Material number)\n");
  fprintf(fp, "\n");
  fprintf(fp, "(- For example, groups of nodes chosen using gmsh 'physical "
              "groups' can be used as follows)\n");
  fprintf(fp, "(- bounda_unknown 0  -ra INSERT HERE GROUP OF NODES SAVED WITH "
              "GMSH -ra   -velx -vely )\n");
  fprintf(fp,
          "(- bounda_time 0      0.000      0.000 1000000.000      0.000 )\n");
  fprintf(fp, "\n");
  fprintf(fp, "( +------------+---------Physical Groups "
              "Section----------+------------+\n");

  // Save elements sets for each physical group
  for(int dim = 1; dim <= 3; dim++) {
    for(auto it = groups[dim].begin(); it != groups[dim].end(); it++) {
      std::vector<GEntity *> &entities = it->second;
      fprintf(fp, "\n");
      fprintf(fp,
              "(Element sets ===> 'element_group' to identify DIFFERENT "
              "MATERIALS =%s)\n",
              physicalName(this, dim, it->first).c_str());
      int n = 0;
      for(std::size_t i = 0; i < entities.size(); i++) {
        for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++) {
          MElement *e = entities[i]->getMeshElement(j);
          if(n && !(n % 10)) fprintf(fp, "\n");
          fprintf(fp, "%lu ", e->getNum());
          n++;
        }
      }
      fprintf(fp, "\n");
    }
  }

  // Save node sets for each physical group (here we include node sets on
  // physical points)
  if(saveGroupsOfNodes) {
    for(int dim = 0; dim <= 3; dim++) {
      for(auto it = groups[dim].begin(); it != groups[dim].end(); it++) {
        std::set<MVertex *, MVertexPtrLessThan> nodes;
        std::vector<GEntity *> &entities = it->second;
        for(std::size_t i = 0; i < entities.size(); i++) {
          for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++) {
            MElement *e = entities[i]->getMeshElement(j);
            for(std::size_t k = 0; k < e->getNumVertices(); k++)
              nodes.insert(e->getVertex(k));
          }
        }
        fprintf(fp, "\n");
        fprintf(
          fp,
          "(Node sets ===> Used to set BOUNDARY CONDITIONS in Tochnog =%s)\n",
          physicalName(this, dim, it->first).c_str());
        fprintf(fp, "\n");
        int n = 0;
        for(auto it2 = nodes.begin(); it2 != nodes.end(); it2++) {
          if(n && !(n % 10)) fprintf(fp, "\n");
          fprintf(fp, "%ld ", (*it2)->getIndex());
          n++;
        }
        fprintf(fp, "\n");
      }
    }
  }

  fclose(fp);
  return 1;
}
