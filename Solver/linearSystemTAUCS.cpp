// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linearSystemTAUCS.h"

#if defined(HAVE_TAUCS)
extern "C" {
#include "taucs.h"
}

template <class scalar>
void sortColumns_(int NbLines, 
                 int nnz, 
                 INDEX_TYPE *ptr, 
                 INDEX_TYPE *jptr, 
                 INDEX_TYPE *ai, 
                 scalar *a);

template<>
int linearSystemCSRTaucs<double>::systemSolve()
{
  if(!sorted){
    sortColumns_(_b->size(),
                CSRList_Nbr(a_),
                (INDEX_TYPE *) ptr_->array,
                (INDEX_TYPE *) jptr_->array, 
                (INDEX_TYPE *) ai_->array, 
                (double*) a_->array);
  }
  sorted = true;
  
  taucs_ccs_matrix myVeryCuteTaucsMatrix;
  myVeryCuteTaucsMatrix.n = myVeryCuteTaucsMatrix.m =  _b->size();
  //myVeryCuteTaucsMatrix.rowind = (INDEX_TYPE*)ptr_->array;
  //myVeryCuteTaucsMatrix.colptr = (INDEX_TYPE*)ai_->array;
  myVeryCuteTaucsMatrix.rowind = (INDEX_TYPE*)ai_->array;
  myVeryCuteTaucsMatrix.colptr = (INDEX_TYPE*)jptr_->array;
  myVeryCuteTaucsMatrix.values.d = (double*) a_->array;
  myVeryCuteTaucsMatrix.flags = TAUCS_SYMMETRIC | TAUCS_LOWER | TAUCS_DOUBLE; 
  
  char* options[] = { "taucs.factor.LLT=true", NULL };  
  Msg::Info("TAUCS solves %d unknowns", _b->size());
  int result = taucs_linsolve(&myVeryCuteTaucsMatrix, 
                              NULL, 
                              1, 
                              &(*_x)[0],
                              &(*_b)[0],
                              options,
                              NULL);                         
  if (result != TAUCS_SUCCESS){
    Msg::Error("Taucs Was Not Successfull %d",result);
  }  
  return 1;
}

#endif
