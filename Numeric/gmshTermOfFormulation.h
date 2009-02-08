// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GMSH_TERM_OF_FORMULATION_H_
#define _GMSH_TERM_OF_FORMULATION_H_

#include <math.h>
#include <map>
#include <vector>
#include "GmshMatrix.h"
#include "gmshAssembler.h"
#include "GModel.h"
#include "MElement.h"

class gmshTermOfFormulation {  
 protected:
  GModel *_gm;
 public:
  gmshTermOfFormulation(GModel *gm) : _gm(gm) {}
  virtual ~gmshTermOfFormulation(){}
  virtual void addToMatrix(gmshAssembler<double> &) const = 0;
};

// a nodal finite element term : variables are always defined at nodes
// of the mesh
class gmshNodalFemTerm : public gmshTermOfFormulation {
 protected:
  // return the number of columns of the element matrix
  virtual int sizeOfC(MElement*) const = 0;
  // return the number of rows of the element matrix
  virtual int sizeOfR(MElement*) const = 0;
  // in a given element, return the dof key associated to a given row
  // of the local element matrix
  virtual void getLocalDofR(MElement *e, int iRow, MVertex **vR, 
                            int *iCompR, int *iFieldR) const = 0;
  virtual void getLocalDofC(MElement *e, int iCol, MVertex **vC, 
                            int *iCompC, int *iFieldC) const
  {
    getLocalDofR(e, iCol, vC, iCompC, iFieldC);
  }
 public:
  gmshNodalFemTerm(GModel *gm) : gmshTermOfFormulation(gm) {}
  virtual ~gmshNodalFemTerm (){}
  virtual void elementMatrix(MElement *e, gmshMatrix<double> &m) const = 0;
  void addToMatrix(gmshAssembler<double> &lsys) const
  {
    if (_gm->getNumRegions()){
      for(GModel::riter it = _gm->firstRegion(); it != _gm->lastRegion(); ++it){
        addToMatrix(lsys, *it);
      }
    }
    else if(_gm->getNumFaces()){
      for(GModel::fiter it = _gm->firstFace(); it != _gm->lastFace(); ++it){
        addToMatrix(lsys, *it);
      }
    }  
  }
  void addToMatrix(gmshAssembler<double> &lsys, GEntity *ge) const
  {
    for(unsigned int i = 0; i < ge->getNumMeshElements(); i++){
      MElement *e = ge->getMeshElement(i);
      addToMatrix(lsys, e);
    }
  }
  void addToMatrix(gmshAssembler<double> &lsys, MElement *e) const
  {
    const int nbR = sizeOfR(e);
    const int nbC = sizeOfC(e);
    gmshMatrix<double> localMatrix (nbR, nbC);
    elementMatrix(e, localMatrix);
    addToMatrix(lsys, localMatrix, e);
  }
  void addToMatrix(gmshAssembler<double> &lsys, const std::vector<MElement*> &v) const
  {
    for (unsigned int i = 0; i < v.size(); i++)
      addToMatrix(lsys, v[i]);
  }
  void addToMatrix(gmshAssembler<double> &lsys, gmshMatrix<double> &localMatrix, 
                   MElement *e) const
  {
    const int nbR = sizeOfR(e);
    const int nbC = sizeOfC(e);
    for (int j = 0; j < nbR; j++){
      MVertex *vR;
      int iCompR, iFieldR;
      getLocalDofR(e, j, &vR, &iCompR, &iFieldR);
      for (int k = 0; k < nbC; k++){
        MVertex *vC;
        int iCompC, iFieldC;
        getLocalDofC(e, k, &vC, &iCompC, &iFieldC);
        lsys.assemble(vR, iCompR, iFieldR, vC, iCompC, iFieldC, localMatrix(j, k));
      }
    }
  }
};

#endif
