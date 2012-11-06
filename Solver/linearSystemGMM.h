// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _LINEAR_SYSTEM_GMM_H_
#define _LINEAR_SYSTEM_GMM_H_

// Interface to GMM++

#include "GmshConfig.h"
#include "GmshMessage.h"
#include "linearSystem.h"

#if defined(HAVE_GMM)
#include <gmm.h>

template <class scalar>
class linearSystemGmm : public linearSystem<scalar> {
 protected:
  std::vector<scalar> *_x; // the nonLinearSystemGmm has to access to this vector
  std::vector<scalar> *_b; // idem
  gmm::row_matrix<gmm::wsvector<scalar> > *_a;
 private:
  double _prec;
  int _noisy, _gmres;
 public:
  linearSystemGmm()
    : _x(0), _b(0), _a(0), _prec(1.e-8), _noisy(0), _gmres(0) {}
  virtual bool isAllocated() const { return _a != 0; }
  virtual void allocate(int nbRows)
  {
    clear();
    _a = new gmm::row_matrix< gmm::wsvector<scalar> >(nbRows, nbRows);
    _b = new std::vector<scalar>(nbRows);
    _x = new std::vector<scalar>(nbRows);
  }
  virtual ~linearSystemGmm()
  {
    clear();
  }
  virtual void clear()
  {
    if (_a){
      delete _a;
      delete _b;
      delete _x;
    }
    _a = 0;
  }

  virtual void  addToMatrix(int row, int col, const scalar &val)
  {
    if(val != 0.0) (*_a)(row, col) += val;
  }
  virtual void getFromMatrix (int row, int col, scalar &val) const
  {
    val = (*_a)(row, col);
  }

  virtual void addToRightHandSide(int row, const scalar &val)
  {
    if(val != 0.0) (*_b)[row] += val;
  }

  virtual void getFromRightHandSide(int row, scalar &val) const
  {
    val = (*_b)[row];
  }

  virtual void addToSolution(int row, const scalar &val)
  {
    if(val != 0.0) (*_x)[row] += val;
  }

  virtual void getFromSolution(int row, scalar &val) const
  {
    val = (*_x)[row];
  }
  virtual void zeroMatrix()
  {
    gmm::clear(*_a);
  }
  virtual void zeroRightHandSide()
  {
    for(unsigned int i = 0; i < _b->size(); i++) (*_b)[i] = 0.;
  }
  virtual void zeroSolution()
  {
    for(unsigned int i = 0; i < _x->size(); i++) (*_x)[i] = 0.;
  }

  virtual double normInfRightHandSide() const {
    double nor = 0.;
    double temp;
    for(unsigned int i=0;i<_b->size();i++){
      temp = abs((*_b)[i]); // this is valid also for complex
      //if(temp<0) temp = -temp;
      if(nor<temp) nor=temp;
    }
    return nor;
  }

  void setPrec(double p){ _prec = p; }
  void setNoisy(int n){ _noisy = n; }
  void setGmres(int n){ _gmres = n; }
  virtual int systemSolve()
  {
    //gmm::ilutp_precond<gmm::row_matrix<gmm::wsvector<scalar> > > P(*_a, 25, 0.);
    gmm::ildltt_precond<gmm::row_matrix<gmm::wsvector<scalar> > > P(*_a, 30, 1.e-10);
    gmm::iteration iter(_prec);
    iter.set_noisy(_noisy);
    if(_gmres) gmm::gmres(*_a, *_x, *_b, P, 100, iter);
    else gmm::cg(*_a, *_x, *_b, P, iter);
    return 1;
  }
};

#else

template <class scalar>
class linearSystemGmm : public linearSystem<scalar> {
 public :
  linearSystemGmm()
  {
    Msg::Error("Gmm++ is not available in this version of Gmsh");
  }
  virtual bool isAllocated() const { return false; }
  virtual void allocate(int nbRows) {}
  virtual void addToMatrix(int row, int col, const scalar &val) {}
  virtual void getFromMatrix(int row, int col, scalar &val) const {}
  virtual void addToRightHandSide(int row, const scalar &val) {}
  virtual void getFromRightHandSide(int row, scalar &val) const {}
  virtual void addToSolution(int row, const scalar &val) {}
  virtual void getFromSolution(int row, scalar &val) const {}
  virtual void zeroMatrix() {}
  virtual void zeroRightHandSide() {}
  virtual void zeroSolution() {}
  virtual int systemSolve() { return 0; }
  virtual double normInfRightHandSide() const { return 0.; }
  void setPrec(double p){}
  virtual void clear(){}
  void setNoisy(int n){}
  void setGmres(int n){}
};

#endif

#endif
