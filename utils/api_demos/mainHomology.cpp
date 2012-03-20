// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributed by Matti Pellikka <matti.pellikka@tut.fi>.
//

#include <stdio.h>
#include <sstream>
#include "Gmsh.h"
#include "GModel.h"
#include "MElement.h"
#include "CellComplex.h"
#include "Homology.h"

int main(int argc, char **argv)
{
  GmshInitialize(argc, argv);
  GModel *m = new GModel();

  m->readGEO("model.geo");
  m->mesh(3);
  // OR
  // m->readMSH("model.msh");

  // List of physical regions as domain for homology computation
  // (relative to subdomain).
  std::vector<int> domain;
  std::vector<int> subdomain;

  // initialize
  Homology* homology = new Homology(m, domain, subdomain);

  // find homology basis elements
  homology->findHomologyBasis();

  // find cohomology basis elements
  homology->findCohomologyBasis();

  // add 1 and 2 dimensional result chains to model
  homology->addChainsToModel(1);
  homology->addChainsToModel(2);
  homology->addCochainsToModel(1);
  homology->addCochainsToModel(2);

  // write mesh with (co)homology computation result chains
  m->writeMSH("model_hom.msh");

  delete homology;
  delete m;
  GmshFinalize();

}




