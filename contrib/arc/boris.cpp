#include <stdio.h>
#include "Gmsh.h"
#include "GModel.h"
#include "MElement.h"
#include "gmshLevelset.h"

int main(int argc, char **argv)
{
  GmshInitialize(argc, argv);
  GModel *m = new GModel();

  m->readMSH("toto.msh");
  double a(1.), b(0.), c(0.), d(-0.05);
  int n(1);
  gLevelset *ls = new gLevelsetPlane(a, b, c, d, n);
  GModel *m2 = m->buildCutGModel(ls);
  m2->writeMSH("toto2.msh", 2.1, false, true);

  delete m;
  GmshFinalize();
}
