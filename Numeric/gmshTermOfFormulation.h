// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GMSH_TERM_OF_FORMULATION_H_
#define _GMSH_TERM_OF_FORMULATION_H_

class GModel;
class GEntity;
class MElement;
class MVertex;
class gmshLinearSystem;
class gmshFunction;

#include <math.h>
#include <GmshMatrix.h>
#include <map>
#include <vector>

class gmshAssembler;

class gmshTermOfFormulation {  
protected:
  GModel *_gm;
public:
  gmshTermOfFormulation(GModel *gm) : _gm(gm) {}
  virtual ~gmshTermOfFormulation(){}
  virtual void addToMatrix(gmshAssembler&) const = 0;
  virtual void addToRightHandSide(gmshAssembler&) const = 0;
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
  virtual ~gmshNodalFemTerm ();
  // compute the element matrix
  virtual void elementMatrix(MElement *e, Double_Matrix &m) const = 0;

  void addToMatrix(gmshAssembler &J, MElement *e) const;
  void addToMatrix(gmshAssembler &J, GEntity *ge) const;
  void addToMatrix(gmshAssembler &J) const;
  void addToMatrix(gmshAssembler &J,const std::vector<MElement*> &) const;
  void addToMatrix(gmshAssembler &Jac, Double_Matrix &localMatrix, MElement *e) const;

  void addDirichlet(int physical, int dim, int comp, int field, const gmshFunction &e, 
                    gmshAssembler &);
  void addNeumann(int physical, int dim, int icomp, int field, const gmshFunction &e, 
                  gmshAssembler &);
  void addToRightHandSide(gmshAssembler &J, GEntity *ge) const;
  void addToRightHandSide(gmshAssembler &r) const;

};

#endif
