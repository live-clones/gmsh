// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "MVertex.h"
#include "gmshAssembler.h"
#include "gmshLinearSystem.h"

void gmshAssembler::assemble(MVertex *vR, int iCompR, int iFieldR,
                             MVertex *vC, int iCompC, int iFieldC,
                             double val)
{
  if (!lsys->isAllocated()){
    lsys->allocate(numbering.size());
  }

  std::map<gmshDofKey, int>::iterator itR = numbering.find(gmshDofKey(vR, iCompR, iFieldR));
  if (itR != numbering.end()){
    std::map<gmshDofKey, int>::iterator itC = numbering.find(gmshDofKey(vC, iCompC, iFieldC));
    if (itC != numbering.end()){
      lsys->addToMatrix(itR->second, itC->second, val);
    }
    else {
      std::map<gmshDofKey, double>::iterator itF = fixed.find(gmshDofKey(vC, iCompC, iFieldC));
      if (itF != fixed.end()){
	lsys->addToRightHandSide(itR->second, -val*itF->second);
      }
      else{
	std::map<gmshDofKey, std::vector<std::pair<gmshDofKey, double> > >::iterator itConstrC =
	  constraints.find(gmshDofKey(vC, iCompC, iFieldC));
	if (itConstrC != constraints.end()){
	  for (unsigned int i = 0; i < itConstrC->second.size(); i++){
	    gmshDofKey &dofKeyConstrC = itConstrC->second[i].first;
	    double valConstrC = itConstrC->second[i].second;
	    assemble(vR, iCompR, iFieldR,
                     dofKeyConstrC.v,dofKeyConstrC.comp, dofKeyConstrC.field,
                     val * valConstrC);
	  }
	}
      }
    }
  }
  else{
    std::map<gmshDofKey, std::vector<std::pair<gmshDofKey, double> > >::iterator itConstrR =
      constraints.find(gmshDofKey(vR, iCompR, iFieldR));
    if (itConstrR != constraints.end()){
      for (unsigned int i = 0; i < itConstrR->second.size(); i++){
	gmshDofKey &dofKeyConstrR = itConstrR->second[i].first;
	double valConstrR = itConstrR->second[i].second;
	assemble(dofKeyConstrR.v,dofKeyConstrR.comp, dofKeyConstrR.field,
                 vC, iCompC, iFieldC,
                 val * valConstrR);
      }
    }
  }
}

void gmshAssembler::assemble(MVertex *vR, int iCompR, int iFieldR,
                             double val)
{
  if (!lsys->isAllocated())lsys->allocate(numbering.size());
  std::map<gmshDofKey, int>::iterator itR = numbering.find(gmshDofKey(vR, iCompR, iFieldR));
  if (itR != numbering.end()){
    lsys->addToRightHandSide(itR->second, val);
  }
}

