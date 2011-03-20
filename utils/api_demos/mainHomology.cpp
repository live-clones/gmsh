// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
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

  // save all resulting chains to a file as physical groups
  homology->setFileName("homology.msh");

  // construct cell complex of the meshed domain
  CellComplex cc = homology->createCellComplex();

  // find homology generator chains
  homology->findGenerators(cc);

  // restore cell complex for a new run
  cc->restoreComplex(); 

  // find thick cuts
  homology->findDualGenerators(cc);

  delete cc;
  delete homology;
  delete m;
  GmshFinalize();
  
}




