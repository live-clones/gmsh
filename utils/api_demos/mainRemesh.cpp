#include <stdio.h>
#include "Gmsh.h"
#include "GModel.h"
#include "MElement.h"
#include "discreteRegion.h"

int main(int argc, char **argv)
{
  GmshInitialize(argc, argv);
  GmshSetOption("General", "Terminal", 1.);
  GmshSetOption("General", "Verbosity", 4.);
  GmshSetOption("Mesh", "CharacteristicLengthExtendFromBoundary", 1.);
  GmshSetOption("Mesh", "OldRefinement", 1.);
  GmshSetOption("Mesh", "CharacteristicLengthMin", 0.1);
  GmshSetOption("Mesh", "CharacteristicLengthMax", 0.1);

  GmshSetOption("Mesh", "Optimize", 0.); // not yet: need boundary!

  GModel *m = new GModel();

  m->readMSH("cube.msh");

  // discreteRegion *gr = new discreteRegion(m);
  // MVertex *v0 = new MVertex(x, y, z, gr, tag);
  // MVertex *v1 = new MVertex(x, y, z, gr, tag);
  // ...
  // gr->mesh_vertices.push_back(v0);
  // ...
  // MTetrahedron *t = new MTetrahedron(v0, v1, v2, v3, tag);
  // gr->tetrahedra.push_back(t);

  //MVertex *v2 = gr->mesh_vertices[2];

  for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it){
    discreteRegion *r = dynamic_cast<discreteRegion*>(*it);
    if(r){
      printf("found a discrete region (%d) with %d tetrahedra\n", r->tag(), r->tetrahedra.size());
      r->remesh();
      printf("after remeshing: %d tetrahedra\n", r->tetrahedra.size());
    }
  }
  m->writeMSH("new.msh");
  delete m;
  GmshFinalize();
}
