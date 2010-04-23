// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _LINEAR_SYSTEM_CSR_H_
#define _LINEAR_SYSTEM_CSR_H_

#include <vector>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "linearSystem.h"

class binding;

typedef int INDEX_TYPE ;  
typedef struct {
  int nmax;
  int size;
  int incr;
  int n;
  int isorder;
  char *array;
} CSRList_T;
  
void CSRList_Add(CSRList_T *liste, void *data);
int  CSRList_Nbr(CSRList_T *liste);

template <class scalar>
class linearSystemCSR : public linearSystem<scalar> {
 protected:
  bool sorted;
  char *something;
  CSRList_T *_a, *_ai, *_ptr, *_jptr; 
  std::vector<scalar> *_b, *_x;
 public:
  linearSystemCSR()
    : sorted(false), _a(0) {}
  virtual bool isAllocated() const { return _a != 0; }
  virtual void allocate(int) ;
  virtual void clear()
  {
    allocate(0);
  }
  virtual ~linearSystemCSR()
  {
    allocate(0);
  }
  virtual void addToMatrix(int il, int ic, double val) 
  {
    INDEX_TYPE  *jptr  = (INDEX_TYPE*) _jptr->array;
    INDEX_TYPE  *ptr   = (INDEX_TYPE*) _ptr->array;
    INDEX_TYPE  *ai    = (INDEX_TYPE*) _ai->array;
    scalar      *a     = ( scalar * ) _a->array;
    
    INDEX_TYPE  position = jptr[il];
    
    if(something[il]) {
      while(1){
        if(ai[position] == ic){
          a[position] += val;
          return;
        }
        if (ptr[position] == 0) break;
        position = ptr[position];
      }
    }  
    
    INDEX_TYPE zero = 0;
    CSRList_Add(_a, &val);
    CSRList_Add(_ai, &ic);
    CSRList_Add(_ptr, &zero);
    // The pointers may have been modified
    // if there has been a reallocation in CSRList_Add  
    
    ptr = (INDEX_TYPE*) _ptr->array;
    ai  = (INDEX_TYPE*) _ai->array;
    a   = (scalar*) _a->array;
    
    INDEX_TYPE n = CSRList_Nbr(_a) - 1;
    
    if(!something[il]) {
      jptr[il] = n;
      something[il] = 1;      
    }
    else ptr[position] = n;
  }
  virtual void getMatrix(INDEX_TYPE*& jptr,INDEX_TYPE*& ai,double*& a);

  virtual scalar getFromMatrix (int row, int col) const
  {
    Msg::Error("getFromMatrix not implemented for CSR");
    return 0;
  }
  virtual void addToRightHandSide(int row, scalar val) 
  {
    if(val != 0.0) (*_b)[row] += val;
  }
  virtual scalar getFromRightHandSide(int row) const 
  {
    return (*_b)[row];
  }
  virtual scalar getFromSolution(int row) const
  {
    return (*_x)[row];
  }
  virtual void zeroMatrix()
  {
    int N = CSRList_Nbr(_a);
    scalar *a = (scalar*) _a->array;
    for (int i = 0; i < N; i++) a[i] = 0;
  }
  virtual void zeroRightHandSide() 
  {
    for(unsigned int i = 0; i < _b->size(); i++) (*_b)[i] = 0.;
  }
};

template <class scalar>
class linearSystemCSRGmm : public linearSystemCSR<scalar> {
 private:
  double _prec;
  int _noisy, _gmres;
 public:
  linearSystemCSRGmm() : _prec(1.e-8), _noisy(0), _gmres(0) {}
  virtual ~linearSystemCSRGmm(){}
  void setPrec(double p){ _prec = p; }
  void setNoisy(int n){ _noisy = n; }
  void setGmres(int n){ _gmres = n; }
  virtual int systemSolve() 
#if !defined(HAVE_GMM)
  {
    Msg::Error("Gmm++ is not available in this version of Gmsh");
    return 0;
  }
#endif
  ;
  static void registerBindings(binding *b);
};

template <class scalar>
class linearSystemCSRTaucs : public linearSystemCSR<scalar> {
 public:
  linearSystemCSRTaucs(){}
  virtual ~linearSystemCSRTaucs(){}
  virtual void addToMatrix(int il, int ic, double val)
  {
    if (il <= ic)
      linearSystemCSR<scalar>::addToMatrix(il, ic, val);
  }
  virtual int systemSolve()     
#if !defined(HAVE_TAUCS)
  {
    Msg::Error("TAUCS is not available in this version of Gmsh");
    return 0;
  }
#endif
  ;
 int getNNZ() {return CSRList_Nbr(linearSystemCSR<scalar>::_a);}
 int getNbUnk() {return linearSystemCSR<scalar>::_b->size();}
};

#endif
