#include <stdio.h>
#include "Gmsh.h"
#include "GModel.h"
#include "MElement.h"
#include "VertexArray.h"

int main(int argc, char **argv)
{
  GmshInitialize(argc, argv);
  GmshSetOption("Mesh", "Algorithm", 5.);
  GmshSetOption("General", "Terminal", 1.);

  GModel *m = new GModel();
  m->readMSH("bunny.msh");
  m->fillVertexArrays();

  std::vector<GEntity*> entities;
  m->getEntities(entities);

  for(unsigned int i = 0; i < entities.size(); i++){
    GEntity *ge = entities[i];
    printf("coucou entite %d (dimension %d)\n", ge->tag(), ge->dim());
    if(ge->va_triangles)
      printf("  j'ai un va de triangles: %d vertex\n", ge->va_triangles->getNumVertices());
    if(ge->va_lines)
      printf("  j'ai un va de lignes: %d vertex\n", ge->va_lines->getNumVertices());
  }

  delete m;
  GmshFinalize();
}
