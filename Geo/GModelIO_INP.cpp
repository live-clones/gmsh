// Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include "GModel.h"
#include "MPoint.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"

template <class T>
static void writeElementsINP(FILE *fp, GEntity *ge, std::vector<T*> &elements,
                             bool saveAll, int &ne)
{
  if(elements.size() && (saveAll || ge->physicals.size())){
    const char *typ = elements[0]->getStringForINP();
    if(typ){
      int np = (saveAll ? 1 : ge->physicals.size());
      for(int p = 0; p < np; p++){
        int part = (saveAll ? ge->tag() : ge->physicals[p]);
        const char *str1 = (saveAll ? "Elementary" : "Physical");
        const char *str2 = (ge->dim() == 3) ? "Volume" : (ge->dim() == 2) ?
          "Surface" : (ge->dim() == 1) ? "Line" : "Point";
        fprintf(fp, "*Element, type=%s, ELSET=%s%s%d\n", typ, str1, str2, part);
        for(unsigned int i = 0; i < elements.size(); i++)
          elements[i]->writeINP(fp, ne++);
      }
    }
  }
}

int GModel::writeINP(const std::string &name, bool saveAll, bool saveGroupsOfNodes,
                     double scalingFactor)
{
  FILE *fp = fopen(name.c_str(), "w");
  if(!fp){
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  if(noPhysicalGroups()) saveAll = true;

  indexMeshVertices(saveAll);
  std::vector<GEntity*> entities;
  getEntities(entities);

  fprintf(fp, "*Heading\n");
  fprintf(fp, " %s\n", name.c_str());

  fprintf(fp, "*Node\n");
  for(unsigned int i = 0; i < entities.size(); i++)
    for(unsigned int j = 0; j < entities[i]->mesh_vertices.size(); j++)
      entities[i]->mesh_vertices[j]->writeINP(fp, scalingFactor);

  int ne = 1;
  for(viter it = firstVertex(); it != lastVertex(); ++it){
    writeElementsINP(fp, *it, (*it)->points, saveAll, ne);
  }
  for(eiter it = firstEdge(); it != lastEdge(); ++it){
    writeElementsINP(fp, *it, (*it)->lines, saveAll, ne);
  }
  for(fiter it = firstFace(); it != lastFace(); ++it){
    writeElementsINP(fp, *it, (*it)->triangles, saveAll, ne);
    writeElementsINP(fp, *it, (*it)->quadrangles, saveAll, ne);
  }
  for(riter it = firstRegion(); it != lastRegion(); ++it){
    writeElementsINP(fp, *it, (*it)->tetrahedra, saveAll, ne);
    writeElementsINP(fp, *it, (*it)->hexahedra, saveAll, ne);
    writeElementsINP(fp, *it, (*it)->prisms, saveAll, ne);
    writeElementsINP(fp, *it, (*it)->pyramids, saveAll, ne);
  }

  // groups of nodes for physical groups
  if(saveGroupsOfNodes){
    std::map<int, std::vector<GEntity*> > groups[4];
    getPhysicalGroups(groups);
    for(int dim = 1; dim <= 3; dim++){
      for(std::map<int, std::vector<GEntity*> >::iterator it = groups[dim].begin();
          it != groups[dim].end(); it++){
        std::set<MVertex*> nodes;
        std::vector<GEntity *> &entities = it->second;
        for(unsigned int i = 0; i < entities.size(); i++){
          for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++){
            MElement *e = entities[i]->getMeshElement(j);
            for (int k = 0; k < e->getNumVertices(); k++)
              nodes.insert(e->getVertex(k));
          }
        }
        const char *str = (dim == 3) ? "PhysicalVolume" : (dim == 2) ?
          "PhysicalSurface" : "PhysicalLine";
        fprintf(fp, "*NSET,NSET=%s%d\n", str, it->first);
        int n = 0;
        for(std::set<MVertex*>::iterator it2 = nodes.begin(); it2 != nodes.end(); it2++){
          if(n && !(n % 10)) fprintf(fp, "\n");
          fprintf(fp, "%d, ", (*it2)->getIndex());
          n++;
        }
        fprintf(fp, "\n");
      }
    }
  }

  fclose(fp);
  return 1;
}

