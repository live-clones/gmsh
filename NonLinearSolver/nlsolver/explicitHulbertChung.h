//
// C++ explicit Newmark scheme
//
// Description: implementation of the explicit algorithms of alpha-generalized method
//              This system is derived from linearSystem from compatibility reason (use of Assemble function and DofManager
//              even if the system is not a no linear system FIX THIS ??
//              for now works only this PETsc
//
// Author:  <Gauthier BECKER>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef EXPLICITHULBERTCHUNGSYSTEM_H_
#define EXPLICITHULBERTCHUNGSYSTEM_H_

#include "GmshConfig.h"
#include "GmshMessage.h"
#include "linearSystem.h"
#include "partDomain.h"

#if defined(HAVE_PETSC)
#include <petsc.h>
#include <petscksp.h>

// 4 vectors are necessary per step and two step are kept
// current and next. Creation of a class regrouping the four vector
template<class scalar>
class explicitStep{
 private:
  void _try(int ierr) const { CHKERRABORT(PETSC_COMM_WORLD, ierr); }
 public : // Direct access by the system
  Vec _b, _x, _xdot, _xddot;
  explicitStep(){}
  ~explicitStep(){}
  void clear(){
   _try(VecDestroy(_b));
   _try(VecDestroy(_x));
   _try(VecDestroy(_xdot));
   _try(VecDestroy(_xddot));
  }

  void allocate(int nbRows){
    _try(VecCreate(PETSC_COMM_WORLD, &_x));
    _try(VecSetSizes(_x, nbRows, PETSC_DETERMINE));
    _try(VecSetFromOptions(_x)); // Usefull ??
    _try(VecDuplicate(_x, &_b));
    _try(VecDuplicate(_x, &_xdot));
    _try(VecDuplicate(_x, &_xddot));
  }
};

template<class scalar>
class explicitHulbertChung : public linearSystem<scalar>{
 public :
  enum state{current, next};
//  enum whatValue{position, velocity, acceleration};
  enum whichMatrix{stiff, mass};
 protected:
  int _blockSize; // for block Matrix (not used for now)
  bool _isAllocated, _whichStep, _imassAllocated;
  double _alpham, _beta,_gamma; // parameters of scheme
  double _timeStep; // value of time step
  int _nbRows; // To know the system size.
  // values used by solve function
  double _oneDivbyOneMinusAlpham,_minusAlphamDivbyOneMinusAlpham;
  double _oneMinusgammaDeltat,_gammaDeltat,_Deltat2halfMinusbeta,_Deltat2beta;
  explicitStep<scalar> *_currentStep, *_previousStep, *_step1, *_step2;
  Vec _M; // mass matrix
  Vec _invM; // inverse of mass matrix
  Vec _v2; // square of velocitie (kinetic energy)

  // function to invert mass matrix
  void invertMassMatrix(){
    _try(VecCopy(_M,_invM));
    _try(VecReciprocal(_invM));
    _imassAllocated=true;
  }

 private:
  void _try(int ierr) const { CHKERRABORT(PETSC_COMM_WORLD, ierr); }

 public:
  explicitHulbertChung(double alpham=0., double beta=0.,
                        double gamma=0.5) : _isAllocated(false), _whichStep(true), _blockSize(0),
                                                                  _alpham(alpham), _beta(beta), _gamma(gamma),
                                                                  _timeStep(0.), _nbRows(0), _imassAllocated(false){
    _oneDivbyOneMinusAlpham = 1./(1.-_alpham);
    _minusAlphamDivbyOneMinusAlpham = - _alpham * _oneDivbyOneMinusAlpham;
    _oneMinusgammaDeltat = (1.-_gamma)*_timeStep;
    _gammaDeltat = _gamma*_timeStep;
    _Deltat2halfMinusbeta = _timeStep*_timeStep *(0.5-_beta);
    _Deltat2beta = _timeStep * _timeStep * _beta;
    _step1 = new explicitStep<scalar>();
    _step2 = new explicitStep<scalar>();
    _currentStep = _step1;
    _previousStep = _step2;
  }
  ~explicitHulbertChung(){delete _step1; delete _step2;}

  void nextStep(){
    if(_whichStep){
      _currentStep = _step2;
      _previousStep = _step1;
      _whichStep =false;
    }
    else{
     _currentStep = _step1;
     _previousStep = _step2;
     _whichStep = true;
    }
  }

  virtual void clear(){
    if(_isAllocated){
      _try(VecDestroy(_M));
      _try(VecDestroy(_invM));
      _try(VecDestroy(_v2));
      _step1->clear();
      _step2->clear();
      _nbRows=0;
    }
    _isAllocated=false;
    _imassAllocated=false;
  }
  // Or compute directly the time step here ??
  virtual void setTimeStep(const double dt){
    _timeStep = dt;
    // update variables which depends on _timeStep
    _oneMinusgammaDeltat = (1.-_gamma)*_timeStep;
    _gammaDeltat = _gamma*_timeStep;
    _Deltat2halfMinusbeta = _timeStep*_timeStep *(0.5-_beta);
    _Deltat2beta = _timeStep * _timeStep * _beta;

  }
  virtual bool isAllocated() const { return _isAllocated; }
  virtual void allocate(int nbRows){
    clear();
    _try(VecCreate(PETSC_COMM_WORLD, &_M));
    _try(VecSetSizes(_M, nbRows, PETSC_DETERMINE));
    _try(VecSetFromOptions(_M)); // Usefull ??
    _try(VecDuplicate(_M, &_invM));
    _try(VecDuplicate(_M, &_v2));
    _step1->allocate(nbRows);
    _step2->allocate(nbRows);
    _isAllocated = true;
    _nbRows=nbRows;
  }
  // get the value of diagonalized mass matrix col is not used
  virtual void getFromMatrix(int row, int col, scalar &val) const{
#if defined(PETSC_USE_COMPLEX)
    PetscScalar *tmp;
    _try(VecGetArray(_M, &tmp));
    PetscScalar s = tmp[row];
    _try(VecRestoreArray(_M, &tmp));
    // FIXME specialize this routine
    val = s.real();
#else
    VecGetValues(_M, 1, &row, &val);
#endif
  }
  virtual void addToRightHandSide(int row, const scalar &val)
  {
    PetscInt i = row;
    PetscScalar s = val;
    _try(VecSetValues(_currentStep->_b, 1, &i, &s, ADD_VALUES));
  }

  virtual void getFromRightHandSide(int row, scalar &val) const
  {
#if defined(PETSC_USE_COMPLEX)
    PetscScalar *tmp;
    _try(VecGetArray(_currentStep->_b, &tmp));
    PetscScalar s = tmp[row];
    _try(VecRestoreArray(_currentStep->_b, &tmp));
    // FIXME specialize this routine
    val = s.real();
#else
    VecGetValues(_currentStep->_b, 1, &row, &val);
#endif
  }

  virtual double normInfRightHandSide() const
  {
    PetscReal nor;
    _try(VecNorm(_currentStep->_b, NORM_INFINITY, &nor));
    return nor;
  }

  // Add to mass matrix (which is diagonalized)
  virtual void addToMatrix(int row, int col, const scalar &val){
    Msg::Error("No stiffness matrix for an explicit newmark scheme");
  }
  virtual void addToMatrix(int row, int col, const scalar &val, const whichMatrix wm)
  {
    if(wm == stiff){
      this->addToMatrix(row,col,val);
    }
    else if( wm == mass){
      PetscInt i = row;
      PetscScalar s = val;
      _try(VecSetValues(_M, 1, &i, &s, ADD_VALUES));
    }
    else{
     Msg::Error("stiff and mass are the only possible matrix choice");
    }

  }

  virtual void getFromSolution(int row, scalar &val) const
  {
#if defined(PETSC_USE_COMPLEX)
    PetscScalar *tmp;
    _try(VecGetArray(_currentStep->_x, &tmp));
    PetscScalar s = tmp[row];
    _try(VecRestoreArray(_currentStep->_x, &tmp));
    val = s.real();
#else
    VecGetValues(_currentStep->_x, 1, &row, &val);
#endif
  }

  virtual void getFromSolution(int row, scalar &val, const initialCondition::whichCondition wv) const
  {
    switch(wv){
     case initialCondition::position:
       this->getFromSolution(row,val);
     break;
     case initialCondition::velocity:
#if defined(PETSC_USE_COMPLEX)
      PetscScalar *tmp;
      _try(VecGetArray(_currentStep->_xdot, &tmp));
      PetscScalar s = tmp[row];
      _try(VecRestoreArray(_currentStep->_xdot, &tmp));
      val = s.real();
#else
      VecGetValues(_currentStep->_xdot, 1, &row, &val);
#endif
     break;
     case initialCondition::acceleration:
#if defined(PETSC_USE_COMPLEX)
      PetscScalar *tmp;
      _try(VecGetArray(_currentStep->_xddot, &tmp));
      PetscScalar s = tmp[row];
      _try(VecRestoreArray(_currentStep->_xddot, &tmp));
      val = s.real();
#else
      VecGetValues(_currentStep->_xddot, 1, &row, &val);
#endif
     break;
     default:
       Msg::Error("Impossible to get value from solution. Only possible choices position, velocity, acceleration ");
    }

  }

/*  virtual void getFromSolution(int row, scalar &val) const
  {
#if defined(PETSC_USE_COMPLEX)
      PetscScalar *tmp;
      _try(VecGetArray(_currentStep->_x, &tmp));
      PetscScalar s = tmp[row];
      _try(VecRestoreArray(_currentStep->_x, &tmp));
      val = s.real();
#else
      VecGetValues(_currentStep->_x, 1, &row, &val);
#endif
  }*/


  virtual void zeroMatrix(){
    if (_isAllocated) {
      _try(VecAssemblyBegin(_M));
      _try(VecAssemblyEnd(_M));
      _try(VecZeroEntries(_M));
    }
  }

  virtual void zeroRightHandSide()
  {
    if (_isAllocated) {
      _try(VecAssemblyBegin(_currentStep->_b));
      _try(VecAssemblyEnd(_currentStep->_b));
      _try(VecZeroEntries(_currentStep->_b));
    }
  }

  int systemSolve(){
#if defined(PETSC_USE_COMPLEX)
  Msg::Error("explicit Newmark resolution is not implemented for complex number\n");
#else
    // check if the mass matrix is computed or not
    if(!_imassAllocated) this->invertMassMatrix();

// The following comment are kept to explain what is done component by component
//    double x,xdot,xddot,fextMinusfint, imasse, xddotn, xdotn, xn;
//    for(PetscInt i=0;i<_nbRows;i++){

      // accelerations n+1
//      VecGetValues(_previousStep->_b, 1, &i, &fextMinusfint);
//      VecGetValues(_invM, 1, &i, &imasse);
//      VecGetValues(_previousStep->_xddot, 1 , &i, &xddotn);
//      xddot = _oneDivbyOneMinusAlpham*imasse*fextMinusfint + _minusAlphamDivbyOneMinusAlpham * xddotn;
//      _try(VecSetValues(_currentStep->_xddot, 1, &i, &xddot, INSERT_VALUES));
      _try(VecPointwiseMult(_currentStep->_xddot,_invM,_previousStep->_b));
      _try(VecScale(_currentStep->_xddot,_oneDivbyOneMinusAlpham));
      _try(VecAXPY(_currentStep->_xddot,_minusAlphamDivbyOneMinusAlpham,_previousStep->_xddot));

      // velocities n+1
//      VecGetValues(_previousStep->_xdot, 1 , &i, &xdotn);
//      xdot = xdotn + _oneMinusgammaDeltat*xddotn + _gammaDeltat*xddot;
//      _try(VecSetValues(_currentStep->_xdot, 1 , &i, &xdot, INSERT_VALUES));
      _try(VecCopy(_previousStep->_xdot,_currentStep->_xdot));
      // Regroups the two in one operation with VecMAXPY ??
      _try(VecAXPY(_currentStep->_xdot,_oneMinusgammaDeltat,_previousStep->_xddot));
      _try(VecAXPY(_currentStep->_xdot,_gammaDeltat,_currentStep->_xddot));

      // positions n+1
//      VecGetValues(_previousStep->_x, 1 , &i, &xn);
//      x = xn + _timeStep * xdotn + _Deltat2halfMinusbeta * xddotn + _Deltat2beta * xddot;
//      _try(VecSetValues(_currentStep->_x, 1 , &i, &x, INSERT_VALUES));
      _try(VecCopy(_previousStep->_x,_currentStep->_x));
      // Regroups the three in one operation with VecMAXPY ??
      _try(VecAXPY(_currentStep->_x,_timeStep,_previousStep->_xdot));
      _try(VecAXPY(_currentStep->_x,_Deltat2halfMinusbeta,_previousStep->_xddot));
      _try(VecAXPY(_currentStep->_x,_Deltat2beta,_currentStep->_xddot));
 //   }
#endif
    return 1;
  }

    // Specific functions (To put initial conditions)
    // set on current step a next step operation is necessary after the prescribtion of initial value step0->step1
    void setInitialCondition(int row, scalar val, const typename initialCondition::whichCondition wc=initialCondition::position){ //CANNOT PASS VAL BY REF WHY ??
      PetscInt i = row;
      switch(wc){
       case initialCondition::position:
        _try(VecSetValues(_currentStep->_x, 1, &i, &val, INSERT_VALUES));
        break;
       case initialCondition::velocity:
        _try(VecSetValues(_currentStep->_xdot, 1, &i, &val, INSERT_VALUES));
        break;
       case initialCondition::acceleration:
        _try(VecSetValues(_currentStep->_xddot, 1 , &i, &val, INSERT_VALUES));
        break;
       default:
        Msg::Warning("Invalid initial conditions");
      }
    }

    // Get mass of system
    virtual double getSystemMass(){
      double m,mele;
      m=0.;
      for(PetscInt i=0;i<_nbRows;i++){
      VecGetValues(_M, 1, &i, &mele);
        m+=mele;
      }
      return m;
    }
  // function to get the kinetic energy
  double getKineticEnergy(){
    if(isAllocated()){
      PetscScalar ener;
      _try(VecPointwiseMult(_v2,_currentStep->_xdot,_currentStep->_xdot));
      _try(VecDot(_M,_v2,&ener));
      return 0.5*ener;
    }
    else return 0.;
  }
};

#else
template <class scalar>
class explicitHulbertChung : public linearSystem<scalar> {
 public :
  explicitHulbertChung()
  {
    Msg::Error("PETSc is not available in this version of Gmsh and so it is impossible to use explicit alpha generalized scheme");
  }
  virtual bool isAllocated() const { return false; }
  virtual void allocate(int nbRows) {}
  virtual void clear(){}
  virtual void addToMatrix(int row, int col, const scalar &val) {}
  virtual void getFromMatrix(int row, int col, scalar &val) const {}
  virtual void addToRightHandSide(int row, const scalar &val) {}
  virtual void getFromRightHandSide(int row, scalar &val) const { return 0.; }
  virtual void getFromSolution(int row, scalar &val) const { return 0.; }
  virtual void zeroMatrix() {}
  virtual void zeroRightHandSide() {}
  virtual int systemSolve() { return 0; }
  virtual double normInfRightHandSide() const{return 0;}
};

#endif

#endif // EXPLICITHULBERTCHUNGSYSTEM_H_

