//
// C++ Interface: terms
//
// Description: Function to Assemble the interface term
//              TODO Template this function with Solver/solverAlgorithms
//
// Author:  <Gauthier BECKER>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//


#ifndef ASSEMBLEINTERFACE_H_
#define ASSEMBLEINTERFACE_H_
#include "dofManager.h"
#include "C0DgPlateTerms.h"
#include "quadratureRules.h"
#include "MVertex.h"
#include "MInterfaceElement.h"

void AssembleInterface(BilinearTermBase &iterm,FunctionSpaceBase &space, groupOfElements* ve, std::vector<MInterfaceElement*> &vie, QuadratureBase &integrator,dofManager<double> &assembler){
  // creation of a matrix this matrix is resize and put = 0 in the function iterm.get()
  fullMatrix<double> localMatrix;
  // vector with dof the dof are append in space.getKeys()
  std::vector<Dof> R;
  // Loop on interface element
  for (int i = 0; i < vie.size(); i++)
  {
    MInterfaceElement *ie = vie[i];
    // get pointers on the elements linked to the interface element i
    MElement **elem = ie->getElem();
    // Clear the dof vector (has to be clear because getKeys is an append method)
    R.clear();
    // Compute the integration point
    IntPt *GP;
    int npts=integrator.getIntPoints(ie,&GP);
    // compute elementatry matrix
    if(ie->getElem(1) == ie->getElem(0)){ // Element is on the boundary
      iterm.getInterOnBoundary(ie,npts,GP,localMatrix);
      space.getKeys(ie->getElem(0),R); // dof
    }
    else{
      iterm.getInter(ie,npts,GP,localMatrix);
      // Dof of minus and plus elements
      space.getKeys(ie->getElem(0),R);
      space.getKeys(ie->getElem(1),R);
    }
    assembler.assemble(R, localMatrix);
  }

}

#endif // ASSEMBLEINTERFACE_H_
