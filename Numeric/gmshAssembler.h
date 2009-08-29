// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GMSH_ASSEMBLER_H_
#define _GMSH_ASSEMBLER_H_

#include <map>
#include <vector>
#include "gmshLinearSystem.h"
#include <stdlib.h>

class MVertex;
class MElement;

struct gmshDofKey{
  MVertex *v;
  int comp;
  int field;
  gmshDofKey (MVertex *V, int iComp, int iField)
    : v(V), comp(iComp), field(iField) {} 
  bool operator < (const gmshDofKey& d) const
  {
    if (v < d.v) return true;
    if (v > d.v) return false;
    if (comp < d.comp) return true;
    if (comp > d.comp) return false;
    if (field < d.field) return true;
    return false;
  }
};

template<class scalar>
class gmshAssembler {
 private:
  std::map<gmshDofKey, int> numbering;
  std::map<gmshDofKey, scalar> fixed;
  std::map<gmshDofKey, scalar> fixedFULL;
  std::map<gmshDofKey, std::vector<std::pair<gmshDofKey, scalar> > > constraints;
  gmshLinearSystem<scalar> *lsys;
 public:
  gmshAssembler(gmshLinearSystem<scalar> *l) : lsys(l) {}
  inline void constraintVertex(MVertex*v, int iComp, int iField,
                               std::vector<MVertex*> &verts,
                               std::vector<scalar> &coeffs)
  {
    std::vector<std::pair<gmshDofKey, scalar> > constraint;
    gmshDofKey key(v, iComp, iField);
    for (unsigned int i = 0; i < verts.size(); i++){
      gmshDofKey key2(verts[i], iComp, iField);
      constraint.push_back(std::make_pair(key2, coeffs[i]));
    }
    constraints[key] = constraint;
  }
  inline void numberVertex(MVertex*v, int iComp, int iField)
  {
    gmshDofKey key(v, iComp, iField);
    if (fixed.find(key) != fixed.end()) return;
    if (constraints.find(key) != constraints.end()) return;
    std::map<gmshDofKey, int>::iterator it = numbering.find(key);
    if (it == numbering.end()){
      int size = numbering.size();
      numbering[key] = size;
    }
  }
  inline void numberVertex(MVertex*v, int iComp, int iField, int iField2)
  {
    gmshDofKey key(v, iComp, iField);
    gmshDofKey key2(v, iComp, iField2);
    if (fixed.find(key) != fixed.end()) return;
    if (fixed.find(key2) != fixed.end()) return;
    if (constraints.find(key) != constraints.end()) return;
    std::map<gmshDofKey, int> :: iterator it = numbering.find(key);
    if (it == numbering.end()){
      int size = numbering.size();
      numbering[key] = size;
    }
  }
  inline void fixVertex(MVertex*v, int iComp, int iField, scalar val)
  {
    fixed[gmshDofKey(v, iComp, iField)] = val;
  }
  inline void fixVertexFULL(MVertex*v, int iComp, int iField, scalar val)
  {
    fixedFULL[gmshDofKey(v, iComp, iField)] = val;
  }
  inline scalar getDofValue(MVertex *v, int iComp, int iField) const
  {
    gmshDofKey key(v, iComp, iField);
    {
      typename std::map<gmshDofKey, scalar>::const_iterator it = fixed.find(key);
      if (it != fixed.end()) return it->second;
    }
    {
      std::map<gmshDofKey, int>::const_iterator it = numbering.find(key);
      if (it != numbering.end())
        return lsys->getFromSolution(it->second);
    }
    {
      typename std::map<gmshDofKey, std::vector<std::pair<gmshDofKey, scalar> > >::
        const_iterator itConstr = constraints.find(key);
      if (itConstr != constraints.end()){
        scalar val = 0.;
        for (unsigned int i = 0; i < itConstr->second.size(); i++){
          const gmshDofKey &dofKeyConstr = itConstr->second[i].first;
          scalar valConstr = itConstr->second[i].second;
          val += getDofValue(dofKeyConstr.v, dofKeyConstr.comp, dofKeyConstr.field)
            * valConstr;
        }
        return val;
      }
    }
    return 0.0;
  }
  void assemble(MVertex *vR, int iCompR, int iFieldR,
                MVertex *vC, int iCompC, int iFieldC, scalar val)
  {
    if (!lsys->isAllocated()) lsys->allocate(numbering.size());

    std::map<gmshDofKey, int>::iterator 
      itR = numbering.find(gmshDofKey(vR, iCompR, iFieldR));
    if (itR != numbering.end()){
      std::map<gmshDofKey, int>::iterator 
        itC = numbering.find(gmshDofKey(vC, iCompC, iFieldC));
      typename std::map<gmshDofKey, scalar>::iterator 
        itFF = fixedFULL.find(gmshDofKey(vR, iCompR, iFieldR));
      if (itC != numbering.end() && itFF ==  fixedFULL.end()){
        lsys->addToMatrix(itR->second, itC->second, val);
      }
      else if (itFF != fixedFULL.end()){
        //printf("RHS = %g,  ligne=%d \n",  itFF->second, itR->second);
        lsys->addToMatrix(itR->second,itR->second, 1. );
        lsys->addToRightHandSide(itR->second, itFF->second);
      }
      else {
        typename std::map<gmshDofKey, scalar>::iterator 
          itF = fixed.find(gmshDofKey(vC, iCompC, iFieldC));
        if (itF != fixed.end()){
          //printf("RHS = val%g itF=%g \n", val, itF->second);
          lsys->addToRightHandSide(itR->second, -val*itF->second);
        }
        else{
          typename std::map<gmshDofKey, std::vector<std::pair<gmshDofKey, scalar> > >::
            iterator itConstrC = constraints.find(gmshDofKey(vC, iCompC, iFieldC));
          if (itConstrC != constraints.end()){
            for (unsigned int i = 0; i < itConstrC->second.size(); i++){
              gmshDofKey &dofKeyConstrC = itConstrC->second[i].first;
              scalar valConstrC = itConstrC->second[i].second;
              assemble(vR, iCompR, iFieldR,
                       dofKeyConstrC.v, dofKeyConstrC.comp, dofKeyConstrC.field,
                       val * valConstrC);
            }
          }
        }
      }
    }
    else{
      typename std::map<gmshDofKey, std::vector<std::pair<gmshDofKey, scalar> > >::
        iterator itConstrR = constraints.find(gmshDofKey(vR, iCompR, iFieldR));
      if (itConstrR != constraints.end()){
        for (unsigned int i = 0; i < itConstrR->second.size(); i++){
          gmshDofKey &dofKeyConstrR = itConstrR->second[i].first;
          scalar valConstrR = itConstrR->second[i].second;
          assemble(dofKeyConstrR.v, dofKeyConstrR.comp, dofKeyConstrR.field,
                   vC, iCompC, iFieldC, 
                   val * valConstrR);
        }
      }
    }
  }
  void assemble(MVertex *vR, int iCompR, int iFieldR, scalar val)
  {
    if (!lsys->isAllocated())lsys->allocate(numbering.size());
    std::map<gmshDofKey, int>::iterator 
      itR = numbering.find(gmshDofKey(vR, iCompR, iFieldR));
    if (itR != numbering.end()){
      lsys->addToRightHandSide(itR->second, val);
    }
  }
  int sizeOfR() const { return numbering.size(); }
  int sizeOfF() const { return fixed.size(); }
  void systemSolve(){
    lsys->systemSolve();
  }  
  void systemClear(){
    lsys->zeroMatrix();
    lsys->zeroRightHandSide();
  }  
};

#endif
