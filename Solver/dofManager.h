// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _DOF_MANAGER_H_
#define _DOF_MANAGER_H_

#include <vector>
#include <string>
#include <map>
#include "MVertex.h"
#include "linearSystem.h"

namespace gsolver {

  class Dof{
  private:
    // v(x) = \sum_f \sum_i v_{fi} s^f_i(x)
    long int _entity; // "i": node, edge, group, etc.
    int _type; // "f": basis function type index, etc.
    
  public:
  Dof(long int entity, int type) : _entity(entity), _type(type) {}
    inline long int getEntity() const { return _entity; }
    inline int getType() const { return _type; }
    static int createTypeWithTwoInts( int i1, int i2 ){
      return i1 + 10000 * i2;
    }
    static void getTwoIntsFromType( int t, int &i1, int &i2){
      i1 = t % 10000;
      i2 = t / 10000;
    }
    bool operator < ( const Dof & other) const{
      if (_entity < other._entity)return true;
      if (_entity > other._entity)return false;
      if (_type < other._type)return true;
      return false;
    }
  };


  template<class dataVec, class dataMat>
    class DofAffineConstraint{
  public:
    std::vector<std::pair<Dof, dataMat> > linear;
    dataVec shift;
  };
  
  // data=float, double, complex<double>, smallVec<double>, smallVec<complex<double> >...
  template <class dataVec, class dataMat>
    class dofManager{
  private:
    // general affine constraint on sub-blocks, treated by adding
    // equations:
    //   dataMat * DofVec = \sum_i dataMat_i * DofVec_i + dataVec
    //std::map<std::pair<Dof, dataMat>, DofAffineConstraint> constraints;
    
    // fixations on full blocks, treated by eliminating equations:
    //   DofVec = dataVec    
    std::map<Dof, dataVec> fixed, initial;
    
    // numbering of unknown dof blocks
    std::map<Dof, int> unknown;
    
    // associatations
    std::map<Dof, Dof> associatedWith;
    
    // linearSystems
    std::map<const std::string, linearSystem<dataMat>* > _linearSystems;
    linearSystem<dataMat>* _current;  
    
  private:
  public:
    dofManager(linearSystem<dataMat> *l) : _current(l){
      _linearSystems["A"]= l;
    }
    inline void fixDof(long int ent, int type, const dataVec & value)
    {
      fixed [Dof(ent, type)] = value;
    }
    inline void fixVertex(MVertex*v, int iComp, int iField, const dataVec & value)
    {
      fixDof (v->getNum(), Dof::createTypeWithTwoInts(iComp, iField ),value);
    }
    inline void numberDof(long int ent, int type){
      Dof key (ent, type);
      if (fixed.find(key) != fixed.end()) return;
      //      if (constraints.find(key) != constraints.end()) return;
      std::map<Dof, int> :: iterator it = unknown.find(key);
      if (it == unknown.end()){
	unsigned int size = unknown.size();
	unknown[key] = size;
      }
    }
    inline void numberVertex(MVertex*v, int iComp, int iField){
      numberDof(v->getNum(), Dof::createTypeWithTwoInts(iComp,iField ));
    }
    inline dataVec getDofValue(int ent, int type) const
    {
      Dof key (ent, type);
      {
	typename std::map<Dof, dataVec>::const_iterator it = fixed.find(key);
	if (it != fixed.end()) return it->second;
      }
      {
	std::map<Dof, int>::const_iterator it = unknown.find(key);
	if (it != unknown.end())
	  return _current->getFromSolution(it->second);
      }
      return dataVec(0.0);
    }
    inline dataVec getDofValue(MVertex *v, int iComp, int iField) const
    {
      return getDofValue(v->getNum(), Dof::createTypeWithTwoInts(iComp,iField ));
    }
    
    inline void assemble(const Dof &R, const Dof &C, const dataMat &value)
    {
      if (!_current->isAllocated()) _current->allocate(unknown.size());
      
      std::map<Dof, int>::iterator itR = unknown.find(R);
      if (itR != unknown.end()){
	std::map<Dof, int>::iterator itC = unknown.find(C);
	if (itC != unknown.end()){
	  _current->addToMatrix(itR->second, itC->second, value);
	}
	else{
	  typename std::map<Dof,  dataVec>::iterator itFixed = fixed.find(C);
	  if (itFixed != fixed.end()){
	    _current->addToRightHandSide(itR->second, -value*itFixed->second);
	  }
	}
      }
    }

    inline void assemble(int entR, int typeR, int entC, int typeC, const dataMat &value)
    {
      assemble (Dof(entR,typeR),Dof(entC,typeC), value);
    }
    
    inline void assemble(MVertex *vR, int iCompR, int iFieldR,
			 MVertex *vC, int iCompC, int iFieldC,
			 const dataMat &value){
      assemble (vR->getNum(), Dof::createTypeWithTwoInts(iCompR,iFieldR),
		vC->getNum(), Dof::createTypeWithTwoInts(iCompC,iFieldC),
		value);
    } 
    
    inline void assemble(const Dof &R, const dataMat &value)
    {
      if (!_current->isAllocated())_current->allocate(unknown.size());
      std::map<Dof, int>::iterator itR = unknown.find(R);
      if (itR != unknown.end()){
	_current->addToRightHandSide(itR->second, value);
      }
    }
    inline void assemble(int entR, int typeR, const dataMat &value)
    {
      assemble(Dof(entR,typeR),value);
    }
    inline void assemble(MVertex *vR, int iCompR, int iFieldR,
			 const dataMat &value){
      assemble (vR->getNum(), Dof::createTypeWithTwoInts(iCompR,iFieldR),
		value);
    } 
    int sizeOfR() const { return unknown.size(); }
    int sizeOfF() const { return fixed.size(); }
    void systemSolve(){
      _current->systemSolve();
    }  
    void systemClear(){
      _current->zeroMatrix();
      _current->zeroRightHandSide();
    }  
  };
}
#endif
