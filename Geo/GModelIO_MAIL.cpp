// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GModel.h"
#include "MTriangle.h"

int GModel::writeMAIL(const std::string &name, bool saveAll, double scalingFactor)
{
  // CEA triangulation (.mail format) for Eric Darrigrand. Note that
  // we currently don't save the edges of the triangulation (the last
  // part of the file).
  FILE *fp = fopen(name.c_str(), "w");
  if(!fp){
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  if(noPhysicalGroups()) saveAll = true;

  int numVertices = indexMeshVertices(saveAll), numTriangles = 0;
  for(fiter it = firstFace(); it != lastFace(); ++it)
    if(saveAll || (*it)->physicals.size())
      numTriangles += (*it)->triangles.size();

  fprintf(fp, " %d %d\n", numVertices, numTriangles);

  std::vector<GEntity*> entities;
  getEntities(entities);
  for(unsigned int i = 0; i < entities.size(); i++){
    for(unsigned int j = 0; j < entities[i]->mesh_vertices.size(); j++){
      MVertex *v = entities[i]->mesh_vertices[j];
      fprintf(fp, " %19.10E %19.10E %19.10E\n", v->x() * scalingFactor,
              v->y() * scalingFactor, v->z() * scalingFactor);
    }
  }

  for(fiter it = firstFace(); it != lastFace(); ++it){
    if(saveAll || (*it)->physicals.size()){
      for(unsigned int i = 0; i < (*it)->triangles.size(); i++){
        MTriangle *t = (*it)->triangles[i];
        fprintf(fp, " %d %d %d\n", t->getVertex(0)->getIndex(),
                t->getVertex(1)->getIndex(), t->getVertex(2)->getIndex());
      }
    }
  }

  // TODO write edges (with signs)
  for(fiter it = firstFace(); it != lastFace(); ++it){
    if(saveAll || (*it)->physicals.size()){
      for(unsigned int i = 0; i < (*it)->triangles.size(); i++){
        //MTriangle *t = (*it)->triangles[i];
        fprintf(fp, " %d %d %d\n", 0, 0, 0);
      }
    }
  }

  fclose(fp);
  return 1;
}
