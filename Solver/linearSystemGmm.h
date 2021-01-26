// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef LINEAR_SYSTEM_GMM_H
#define LINEAR_SYSTEM_GMM_H

#include <string>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "linearSystem.h"

#if defined(HAVE_GMM)

#undef BB // can be defined by FlGui.h, and clashes with gmm arg name
#include <gmm.h>

// Consider using linearSystemCSRGmm instead: assembly is much faster
template <class scalar> class linearSystemGmm : public linearSystem<scalar> {
protected:
  std::vector<scalar> *_x; // nonLinearSystemGmm has to access to this vector
  std::vector<scalar> *_b; // idem
  gmm::row_matrix<gmm::wsvector<scalar> > *_a;

private:
  std::string _method;
  double _tol;
  int _noisy;

public:
  linearSystemGmm(const std::string &method = "gmres", double tol = 1e-8,
                  int noisy = 0)
    : _x(0), _b(0), _a(0), _method(method), _tol(tol), _noisy(noisy) {}
  virtual bool isAllocated() const { return _a != 0; }
  virtual void allocate(int nbRows)
  {
    clear();
    _a = new gmm::row_matrix<gmm::wsvector<scalar> >(nbRows, nbRows);
    _b = new std::vector<scalar>(nbRows);
    _x = new std::vector<scalar>(nbRows);
  }
  virtual ~linearSystemGmm() { clear(); }
  virtual void clear()
  {
    if(_a) {
      delete _a;
      delete _b;
      delete _x;
    }
    _a = 0;
  }
  virtual void addToMatrix(int row, int col, const scalar &val)
  {
    if(val != 0.0) (*_a)(row, col) += val;
  }
  virtual void getFromMatrix(int row, int col, scalar &val) const
  {
    val = (*_a)(row, col);
  }
  virtual void addToRightHandSide(int row, const scalar &val, int ith = 0)
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
  virtual void getFromSolution(int row, scalar &val) const { val = (*_x)[row]; }
  virtual void zeroMatrix() { gmm::clear(*_a); }
  virtual void zeroRightHandSide()
  {
    for(std::size_t i = 0; i < _b->size(); i++) (*_b)[i] = 0.;
  }
  virtual void zeroSolution()
  {
    for(std::size_t i = 0; i < _x->size(); i++) (*_x)[i] = 0.;
  }
  virtual double normInfRightHandSide() const
  {
    double nor = 0.;
    double temp;
    for(std::size_t i = 0; i < _b->size(); i++) {
      temp = abs((*_b)[i]); // this is valid also for complex
      // if(temp<0) temp = -temp;
      if(nor < temp) nor = temp;
    }
    return nor;
  }
  void setPrec(double p) { _tol = p; }
  void setNoisy(int n) { _noisy = n; }
  void setGmres(int n) { _method = (n ? "gmres" : "cg"); }
  virtual int systemSolve()
  {
#if defined(HAVE_MUMPS)
    if(_method == "mumps"){
      gmm::MUMPS_solve(*_a, *_x, *_b);
      return 1;
    }
#else
    //gmm::ilutp_precond<gmm::row_matrix<gmm::wsvector<scalar> > > P(*_a, 25, 0.);
    gmm::ildltt_precond<gmm::row_matrix<gmm::wsvector<scalar> > > P(*_a, 30, 1.e-10);
    //gmm::ilu_precond<gmm::row_matrix<gmm::wsvector<scalar> > > P(*_a);
    gmm::iteration iter(_tol);
    iter.set_noisy(_noisy);
    if(_method == "gmres")
      gmm::gmres(*_a, *_x, *_b, P, 100, iter);
    else
      gmm::cg(*_a, *_x, *_b, P, iter);
    if(!iter.converged())
      Msg::Warning("Iterative linear solver has not converged (res = %g)",
                   iter.get_res());
#endif
    return 1;
  }
};

#else

template <class scalar> class linearSystemGmm : public linearSystem<scalar> {
public:
  linearSystemGmm(const std::string &method = "gmres", double tol = 1e-8,
                  int noisy = 0)
  {
    Msg::Error("Gmm++ is not available in this version of Gmsh");
  }
  virtual bool isAllocated() const { return false; }
  virtual void allocate(int nbRows) {}
  virtual void addToMatrix(int row, int col, const scalar &val) {}
  virtual void getFromMatrix(int row, int col, scalar &val) const {}
  virtual void addToRightHandSide(int row, const scalar &val, int ith = 0) {}
  virtual void getFromRightHandSide(int row, scalar &val) const {}
  virtual void addToSolution(int row, const scalar &val) {}
  virtual void getFromSolution(int row, scalar &val) const {}
  virtual void zeroMatrix() {}
  virtual void zeroRightHandSide() {}
  virtual void zeroSolution() {}
  virtual int systemSolve() { return 0; }
  virtual double normInfRightHandSide() const { return 0.; }
  void setPrec(double p) {}
  virtual void clear() {}
  void setNoisy(int n) {}
  void setGmres(int n) {}
};

#endif

#endif
