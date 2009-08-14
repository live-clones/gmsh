// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GMSH_LINEAR_SYSTEM_TAUCS_H_
#define _GMSH_LINEAR_SYSTEM_TAUCS_H_

// Interface to TAUCS

#include "GmshConfig.h"
#include "GmshMessage.h"
#include "gmshLinearSystem.h"

#include <vector>

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
class gmshLinearSystemCSR : public gmshLinearSystem<scalar> {
 protected:
  bool sorted;
  char *something;
  CSRList_T *a_,*ai_,*ptr_,*jptr_; 
  std::vector<scalar> *_b, *_x;
 public:
  gmshLinearSystemCSR()
  : sorted(false), a_(0) {}
  virtual bool isAllocated() const { return a_ != 0; }
  virtual void allocate(int) ;
  virtual ~gmshLinearSystemCSR()
  {
    allocate(0);
  }
  void addToMatrix ( int il, int ic, double val) 
  {
    //    if (sorted)throw;

    INDEX_TYPE  *jptr  = (INDEX_TYPE*) jptr_->array;
    INDEX_TYPE  *ptr   = (INDEX_TYPE*) ptr_->array;
    INDEX_TYPE  *ai    = (INDEX_TYPE*) ai_->array;
    scalar      *a     = ( scalar * ) a_->array;

    INDEX_TYPE  position_ = jptr[il];

    if(something[il]) {
      while(1){
        if(ai[position_] == ic){
          a[position_] += val;
          //      if (il == 0)    printf("FOUND %d %d %d\n",il,ic,position_);
          return;
        }
        if (ptr[position_] == 0)break;
        position_ = ptr[position_];
      }
    }  
  
    INDEX_TYPE zero = 0;
    CSRList_Add (a_, &val);
    CSRList_Add (ai_, &ic);
    CSRList_Add (ptr_, &zero);
    // The pointers may have been modified
    // if there has been a reallocation in CSRList_Add  
    
    ptr = (INDEX_TYPE*) ptr_->array;
    ai  = (INDEX_TYPE*) ai_->array;
    a   = (scalar*) a_->array;
    
    INDEX_TYPE n = CSRList_Nbr(a_) - 1;

    //    if (il == 0)  printf("NOT FOUND %d %d %d\n",il,ic,n);
    
    if(!something[il]) {
      jptr[il] = n;
      something[il] = 1;      
    }
    else ptr[position_] = n;

/*     for (int i=0;i<_b->size();i++)printf("%d ",something[i]?jptr[i]:-1); */
/*     printf("\n"); */
/*     for (int i=0;i<CSRList_Nbr(ai_);i++)printf("(%d %d %g)",ai[i],ptr[i],a[i]); */
/*     printf("\n"); */

  }
  
  virtual scalar getFromMatrix (int _row, int _col) const
  {
    throw;
  }
  virtual void addToRightHandSide(int _row, scalar _val) 
  {
    if(_val != 0.0) (*_b)[_row] += _val;
  }
  virtual scalar getFromRightHandSide(int _row) const 
  {
    return (*_b)[_row];
  }
  virtual scalar getFromSolution(int _row) const
  {
    return (*_x)[_row];
  }
  virtual void zeroMatrix()
  {
    int N=CSRList_Nbr(a_);
    scalar *a = (scalar*) a_->array;
    for (int i=0;i<N;i++)a[i]=0;
  }
  virtual void zeroRightHandSide() 
  {
    for(unsigned int i = 0; i < _b->size(); i++) (*_b)[i] = 0.;
  }
};


template <class scalar>
class gmshLinearSystemCSRGmm : public gmshLinearSystemCSR<scalar> {
 private:
  double _prec;
  int _noisy, _gmres;
 public:
  gmshLinearSystemCSRGmm()
    : _prec(1.e-8), _noisy(0), _gmres(0) {}
  virtual ~gmshLinearSystemCSRGmm()
    {}
  void setPrec(double p){ _prec = p; }
  void setNoisy(int n){ _noisy = n; }
  void setGmres(int n){ _gmres = n; }
  virtual int systemSolve() 
#if defined(HAVE_GMM)
    ;
#else
  {
    Msg::Error("Gmm++ is not available in this version of Gmsh");
    return 0;
  }
#endif
  virtual int checkSystem() 
#if defined(HAVE_GMM)
    ;
#else
  {
    Msg::Error("Gmm++ is not available in this version of Gmsh");
  }
#endif

};

template <class scalar>
class gmshLinearSystemCSRTaucs : public gmshLinearSystemCSR<scalar> {
 private:
 public:
  gmshLinearSystemCSRTaucs()
    {}
  virtual ~gmshLinearSystemCSRTaucs()
    {}
  virtual int systemSolve() 
#if defined(HAVE_TAUCS)
    ;
#else
  {
    Msg::Error("Taucs is not available in this version of Gmsh");
    return 0;
  }
#endif
};


#endif
