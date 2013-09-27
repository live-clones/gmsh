#include <stdio.h>
#include "Gmsh.h"
#include "GModel.h"

int main(int argc, char **argv)
{
  GmshInitialize(argc, argv);
  GModel *m = new GModel();

  m->setFactory("Gmsh");

  GVertex *v1 = m->addVertex(0, 0, 0, 0.1);
  GVertex *v2 = m->addVertex(1, 0, 0, 0.1);
  GVertex *v3 = m->addVertex(1, 1, 0, 0.1);
  GVertex *v4 = m->addVertex(0, 1, 0, 0.1);

  std::vector<GEdge*> edges;
  edges.push_back(m->addLine(v1, v2));
  edges.push_back(m->addLine(v2, v3));
  edges.push_back(m->addLine(v3, v4));
  edges.push_back(m->addLine(v4, v1));

  std::vector<std::vector<GEdge*> > loop;
  loop.push_back(edges);
  GFace *f = m->addPlanarFace(loop);

  m->mesh(2);
  m->writeMSH("test.msh");
  delete m;
  GmshFinalize();
}
