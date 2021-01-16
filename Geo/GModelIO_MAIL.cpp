// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GModel.h"
#include "OS.h"
#include "MTriangle.h"

int GModel::writeMAIL(const std::string &name, bool saveAll,
                      double scalingFactor)
{
  // CEA triangulation (.mail format) for Eric Darrigrand. Note that
  // we currently don't save the edges of the triangulation (the last
  // part of the file).
  FILE *fp = Fopen(name.c_str(), "w");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  if(noPhysicalGroups()) saveAll = true;

  int numVertices = indexMeshVertices(saveAll), numTriangles = 0;
  for(auto it = firstFace(); it != lastFace(); ++it)
    if(saveAll || (*it)->physicals.size())
      numTriangles += (*it)->triangles.size();

  fprintf(fp, " %d %d\n", numVertices, numTriangles);

  std::vector<GEntity *> entities;
  getEntities(entities);
  for(std::size_t i = 0; i < entities.size(); i++) {
    for(std::size_t j = 0; j < entities[i]->mesh_vertices.size(); j++) {
      MVertex *v = entities[i]->mesh_vertices[j];
      fprintf(fp, " %19.10E %19.10E %19.10E\n", v->x() * scalingFactor,
              v->y() * scalingFactor, v->z() * scalingFactor);
    }
  }

  for(auto it = firstFace(); it != lastFace(); ++it) {
    if(saveAll || (*it)->physicals.size()) {
      for(std::size_t i = 0; i < (*it)->triangles.size(); i++) {
        MTriangle *t = (*it)->triangles[i];
        fprintf(fp, " %ld %ld %ld\n", t->getVertex(0)->getIndex(),
                t->getVertex(1)->getIndex(), t->getVertex(2)->getIndex());
      }
    }
  }

  // TODO write edges (with signs)
  for(auto it = firstFace(); it != lastFace(); ++it) {
    if(saveAll || (*it)->physicals.size()) {
      for(std::size_t i = 0; i < (*it)->triangles.size(); i++) {
        // MTriangle *t = (*it)->triangles[i];
        fprintf(fp, " %d %d %d\n", 0, 0, 0);
      }
    }
  }

  fclose(fp);
  return 1;
}
