// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
// 
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
// 
// Contributed by Matti Pellikka <matti.pellikka@tut.fi>.
// 

#include <stdio.h>
#include <sstream>
#include <gmsh/Gmsh.h>
#include <gmsh/GModel.h>
#include <gmsh/MElement.h>
#include <gmsh/CellComplex.h>
#include <gmsh/ChainComplex.h>
#include <gmsh/Homology.h>

int main(int argc, char **argv)
{
  GmshInitialize(argc, argv);
  GModel *m = new GModel();
  
  m->readGEO("model.geo");
  m->mesh(3);
  // OR
  // m->readMSH("model.msh");
  
  // List of physical regions as domain for homology computation (relative to subdomain).
  std::vector<int> domain;
  std::vector<int> subdomain;
  
  Homology* homology1 = new Homology(m, domain, subdomain);
  std::string fileName = "homology.msh";
  homology->findGenerators(fileName);
  delete homology1;
  
  Homology* homology2 = new Homology(m, domain, subdomain);
  fileName = "homology.msh";
  homology->findDualGenerators(fileName);
  delete homology2;
  
  Homology* homology3 = new Homology(m, domain, subdomain);
  homology->computeBettiNumbers();
  delete homology3;
  
  delete m;
  GmshFinalize();
  
}




