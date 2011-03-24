//
//
// Description: Class to set Boundary Conditions
//
//
// Author:  <Gauthier BECKER>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//
// Has to be regroup with BoundaryCondition defined in elasticitySolver.h These BC have to be defined in a separated file
// I add nonLinear above to avoid ambiguities
#ifndef NONLINEARBC_H_
#define NONLINEARBC_H_
#ifndef SWIG
#include "groupOfElements.h"
#include "simpleFunction.h"
#include "SVector3.h"
#include "quadratureRules.h"
#include "timeFunction.h"
#include "contactFunctionSpace.h"
#include "solverAlgorithms.h" // change this
class nonLinearBoundaryCondition
{
 public:
  enum location{UNDEF,ON_VERTEX,ON_EDGE,ON_FACE,ON_VOLUME,PRESSURE,RIGIDCONTACT};
  location onWhat; // on vertices or elements
  int _tag; // tag for the dofManager
  groupOfElements *g; // support for this BC
  nonLinearBoundaryCondition() : g(0),_tag(0),onWhat(UNDEF) {};
  nonLinearBoundaryCondition(const nonLinearBoundaryCondition &source){
    this->onWhat = source.onWhat;
    this->_tag = source._tag;
    this->g = source.g;
  }
};

class nonLinearDirichletBC : public nonLinearBoundaryCondition
{
 public:
  int _comp; // component
  simpleFunctionTime<double> _f;
  FilterDof *_filter;
  FunctionSpaceBase *_space;
  nonLinearDirichletBC() : nonLinearBoundaryCondition(),_comp(0),_f(0), _space(NULL), _filter(NULL){}
  nonLinearDirichletBC(const nonLinearDirichletBC &source) : nonLinearBoundaryCondition(source){
    this->_comp = source._comp;
    this->_f = source._f;
    this->_space = source._space;
    this->_filter = source._filter;
  }
};

// group will be not used but allow to store in same vector
// tag == Master physical number
class rigidContactBC : public nonLinearBoundaryCondition
{
 public:
  rigidContactSpace *space;
  int _comp; // component
  simpleFunctionTime<double> _f;
  rigidContactBC(const int physMaster) : nonLinearBoundaryCondition(){
    _tag = physMaster;
    onWhat = RIGIDCONTACT;
  }
  rigidContactBC(const rigidContactBC &source) : nonLinearBoundaryCondition(source)
  {
    _comp = source._comp;
    space = source.space;
    _f = source._f;
  }
  ~rigidContactBC(){}
  void setSpace(rigidContactSpace *sp){space = sp;}
};
#endif
class nonLinearNeumannBC  : public nonLinearBoundaryCondition
{
 public:
  simpleFunction<double> *_f;
  QuadratureBase* integ; // given by partDomain
  FunctionSpaceBase *_space; // given by partDomain
  LinearTermBase<double> *_term; // given by partDomain
  int _comp; // component x, y or z to create function space
  nonLinearNeumannBC () : nonLinearBoundaryCondition(),_f(NULL), integ(NULL), _space(NULL), _term(NULL) {}
  nonLinearNeumannBC (const int tag, const int ow, simpleFunction<double>* f): nonLinearBoundaryCondition(), _f(f),
                                                                                   integ(NULL), _space(NULL), _term(NULL),
                                                                                   _comp(0)
  {
    _tag = tag;
    switch(ow){
     case 0:
      this->onWhat = nonLinearBoundaryCondition::UNDEF;
      break;
     case 1:
      this->onWhat = nonLinearBoundaryCondition::ON_VERTEX;
      g = new groupOfElements(0,tag);
      break;
     case 2:
      onWhat = nonLinearBoundaryCondition::ON_EDGE;
      g = new groupOfElements(1,tag);
      break;
     case 3:
      onWhat = nonLinearBoundaryCondition::ON_FACE;
      g = new groupOfElements(2,tag);
      break;
     case 4:
      onWhat = nonLinearBoundaryCondition::ON_VOLUME;
      g = new groupOfElements(3,tag);
      break;
     case 5:
      onWhat = nonLinearBoundaryCondition::PRESSURE;
      g = new groupOfElements(2,tag);
      break;
    }
  }
  nonLinearNeumannBC(const nonLinearNeumannBC &source) : _f(source._f), nonLinearBoundaryCondition(source),
                                                          integ(source.integ), _space(source._space), _term(source._term),
                                                          _comp(source._comp){}
};
#ifndef SWIG
class initialCondition : public nonLinearDirichletBC {
 public:
  enum whichCondition{position=0, velocity=1, acceleration=2};
  double _value;
  whichCondition _wc;
  initialCondition(double val, int comp, whichCondition wc) : nonLinearDirichletBC(), _value(val), _wc(wc){_comp=comp;}
  ~initialCondition(){}
  initialCondition(const initialCondition &source) : nonLinearDirichletBC(source){
    _value = source._value;
    _wc = source._wc;
  }
};
#endif
#endif // non linear Boundary Conditions
