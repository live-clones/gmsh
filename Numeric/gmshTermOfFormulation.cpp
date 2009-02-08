// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "Gmsh.h"
#include "GModel.h"
#include "MElement.h"
#include "GmshMatrix.h"
#include "gmshTermOfFormulation.h"
#include "gmshFunction.h"
#include "gmshAssembler.h"

gmshNodalFemTerm::~gmshNodalFemTerm ()
{
}

void gmshNodalFemTerm::addDirichlet(int physical, 
				    int dim, 
				    int comp, 
				    int field, 
				    const gmshFunction & e,
				    gmshAssembler &lsys)
{
}

void gmshNodalFemTerm::addNeumann(int physical, 
				  int dim, 
				  int comp, 
				  int field, 
				  const gmshFunction & fct, 
				  gmshAssembler &lsys)
{
}

void gmshNodalFemTerm::addToMatrix(gmshAssembler &lsys) const
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

void gmshNodalFemTerm::addToMatrix(gmshAssembler &lsys,const std::vector<MElement*> &v) const
{
  for (unsigned int i = 0; i < v.size(); i++)
    addToMatrix(lsys, v[i]);
}

void gmshNodalFemTerm::addToMatrix(gmshAssembler &lsys, 
                                   gmshMatrix<double> &localMatrix, 
                                   MElement *e) const
{
  const int nbR = sizeOfR(e);
  const int nbC = sizeOfC(e);
  for (int j = 0; j < nbR; j++){
    MVertex *vR;int iCompR,iFieldR;
    getLocalDofR (e, j, &vR, &iCompR, &iFieldR);
    for (int k = 0; k < nbC; k++){
      MVertex *vC;
      int iCompC, iFieldC;
      getLocalDofC(e, k, &vC, &iCompC, &iFieldC);
      lsys.assemble(vR, iCompR, iFieldR,
		    vC, iCompC, iFieldC,
		    localMatrix(j, k));
    }
  }
}

void gmshNodalFemTerm::addToMatrix(gmshAssembler &lsys, MElement *e) const
{
  const int nbR = sizeOfR(e);
  const int nbC = sizeOfC(e);
  gmshMatrix<double> localMatrix (nbR, nbC);
  elementMatrix(e, localMatrix);
  addToMatrix(lsys, localMatrix, e);
}

void gmshNodalFemTerm::addToMatrix(gmshAssembler &lsys, GEntity *ge) const
{
  for(unsigned int i = 0; i < ge->getNumMeshElements(); i++){
    MElement *e = ge->getMeshElement(i);
    addToMatrix(lsys, e);
  }
}

void gmshNodalFemTerm::addToRightHandSide(gmshAssembler &lsys) const
{
  if (_gm->getNumRegions()){
    for(GModel::riter it = _gm->firstRegion(); it != _gm->lastRegion(); ++it){
      addToRightHandSide(lsys, *it);
    }
  }
  else if(_gm->getNumFaces()){
    for(GModel::fiter it = _gm->firstFace(); it != _gm->lastFace(); ++it){
      addToRightHandSide(lsys, *it);
    }
  }  
}

void gmshNodalFemTerm::addToRightHandSide(gmshAssembler &lsys, GEntity *ge) const
{
  throw;
}
