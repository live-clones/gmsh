// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef LINEAR_SYSTEM_CSR_H
#define LINEAR_SYSTEM_CSR_H

#include <vector>
#include <string>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "linearSystem.h"
#include "sparsityPattern.h"

typedef int INDEX_TYPE;
typedef struct {
  int nmax;
  int size;
  int incr;
  int n;
  int isorder;
  char *array;
} CSRList_T;

void CSRList_Add(CSRList_T *liste, const void *data);
int CSRList_Nbr(CSRList_T *liste);

template <class scalar> class linearSystemCSR : public linearSystem<scalar> {
protected:
  bool sorted;
  bool _entriesPreAllocated;
  char *something;
  CSRList_T *_a, *_ai, *_ptr, *_jptr;
  std::vector<scalar> *_b, *_x;
  sparsityPattern _sparsity; // only used for pre-allocation, does not store the
                             // sparsity once allocated
public:
  int getNNZ() { return CSRList_Nbr(linearSystemCSR<scalar>::_a); }
  int getNbUnk() { return linearSystemCSR<scalar>::_b->size(); }
  linearSystemCSR()
    : sorted(false), _entriesPreAllocated(false), _a(nullptr), _b(0), _x(0)
  {
  }
  virtual bool isAllocated() const { return _a != nullptr; }
  virtual void allocate(int);
  virtual void clear() { allocate(0); }
  virtual ~linearSystemCSR() { allocate(0); }
  virtual void insertInSparsityPattern(int i, int j)
  {
    _sparsity.insertEntry(i, j);
  }
  virtual void preAllocateEntries();
  virtual void addToMatrix(int il, int ic, const scalar &val)
  {
    if(!_entriesPreAllocated) preAllocateEntries();
    INDEX_TYPE *jptr = (INDEX_TYPE *)_jptr->array;
    INDEX_TYPE *ptr = (INDEX_TYPE *)_ptr->array;
    INDEX_TYPE *ai = (INDEX_TYPE *)_ai->array;
    scalar *a = (scalar *)_a->array;

    INDEX_TYPE position = jptr[il];

    if(sorted) { // use bisection and direct adressing if sorted
      int p0 = jptr[il];
      int p1 = jptr[il + 1];
      while(p1 - p0 > 20) {
        position = ((p0 + p1) / 2);
        if(ai[position] > ic)
          p1 = position;
        else if(ai[position] < ic)
          p0 = position + 1;
        else {
          a[position] += val;
          return;
        }
      }
      for(position = p0; position < p1; position++) {
        if(ai[position] >= ic) {
          if(ai[position] == ic) {
            a[position] += val;
            return;
          }
          break;
        }
      }
    }
    else if(something[il]) {
      while(1) {
        if(ai[position] == ic) {
          a[position] += val;
          return;
        }
        if(ptr[position] == 0) break;
        position = ptr[position];
      }
    }

    INDEX_TYPE zero = 0;
    CSRList_Add(_a, &val);
    CSRList_Add(_ai, &ic);
    CSRList_Add(_ptr, &zero);
    // The pointers may have been modified if there has been a
    // reallocation in CSRList_Add

    ptr = (INDEX_TYPE *)_ptr->array;
    ai = (INDEX_TYPE *)_ai->array;
    a = (scalar *)_a->array;

    INDEX_TYPE n = CSRList_Nbr(_a) - 1;

    if(!something[il]) {
      jptr[il] = n;
      something[il] = 1;
    }
    else
      ptr[position] = n;
  }
  virtual void getMatrix(INDEX_TYPE *&jptr, INDEX_TYPE *&ai, double *&a);

  virtual void getFromMatrix(int row, int col, scalar &val) const
  {
    Msg::Error("getFromMatrix not implemented for CSR");
  }
  virtual void addToRightHandSide(int row, const scalar &val, int ith = 0)
  {
    if(!_b) return;
    if(val != scalar()) (*_b)[row] += val;
  }
  virtual void addToSolution(int row, const scalar &val)
  {
    if(!_x) return;
    if(val != scalar()) (*_x)[row] += val;
  }
  virtual void getFromRightHandSide(int row, scalar &val) const
  {
    if(!_b) return;
    val = (*_b)[row];
  }
  virtual void getFromSolution(int row, scalar &val) const
  {
    if(!_x) return;
    val = (*_x)[row];
  }
  virtual void zeroMatrix()
  {
    if(!_a) return;
    int N = CSRList_Nbr(_a);
    scalar *a = (scalar *)_a->array;
    for(int i = 0; i < N; i++) a[i] = scalar();
  }
  virtual void zeroRightHandSide()
  {
    if(!_b) return;
    for(std::size_t i = 0; i < _b->size(); i++) (*_b)[i] = scalar();
  }
  virtual void zeroSolution()
  {
    if(!_x) return;
    for(std::size_t i = 0; i < _x->size(); i++) (*_x)[i] = scalar();
  }
  virtual double normInfRightHandSide() const
  {
    if(!_b) return 0.;
    double nor = 0.;
    double temp;
    for(std::size_t i = 0; i < _b->size(); i++) {
      temp = std::abs((*_b)[i]);
      if(nor < temp) nor = temp;
    }
    return nor;
  }
};

template <class scalar>
class linearSystemCSRGmm : public linearSystemCSR<scalar> {
private:
  std::string _method;
  double _tol;
  int _noisy;

public:
  linearSystemCSRGmm(const std::string &method = "gmres", double tol = 1e-8,
                     int noisy = 0)
    : _method(method), _tol(tol), _noisy(noisy) {}
  virtual ~linearSystemCSRGmm() {}
  void setPrec(double p) { _tol = p; }
  void setNoisy(int n) { _noisy = n; }
  void setGmres(int n) { _method = (n ? "gmres" : "cg"); }
  virtual int systemSolve()
#if !defined(HAVE_GMM)
  {
    Msg::Error("Gmm++ is not available in this version of Gmsh");
    return 0;
  }
#endif
  ;
};

#endif
