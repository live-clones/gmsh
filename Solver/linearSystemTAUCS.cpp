// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
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
                CSRList_Nbr(_a),
                (INDEX_TYPE *) _ptr->array,
                (INDEX_TYPE *) _jptr->array, 
                (INDEX_TYPE *) _ai->array, 
                (double*) _a->array);
  }
  sorted = true;
  
  taucs_ccs_matrix myVeryCuteTaucsMatrix;
  myVeryCuteTaucsMatrix.n = myVeryCuteTaucsMatrix.m = _b->size();
  //myVeryCuteTaucsMatrix.rowind = (INDEX_TYPE*)_ptr->array;
  //myVeryCuteTaucsMatrix.colptr = (INDEX_TYPE*)_ai->array;
  myVeryCuteTaucsMatrix.rowind = (INDEX_TYPE*)_ai->array;
  myVeryCuteTaucsMatrix.colptr = (INDEX_TYPE*)_jptr->array;
  myVeryCuteTaucsMatrix.values.d = (double*)_a->array;
  myVeryCuteTaucsMatrix.flags = TAUCS_SYMMETRIC | TAUCS_LOWER | TAUCS_DOUBLE; 
  
  char* options[] = { "taucs.factor.LLT=true", NULL };  
  clock_t t1 = clock();
  int result = taucs_linsolve(&myVeryCuteTaucsMatrix, 
                              NULL, 
                              1, 
                              &(*_x)[0],
                              &(*_b)[0],
                              options,
                              NULL);                         
  clock_t t2 = clock();
  Msg::Info("TAUCS has solved %d unknowns in %8.3f seconds", _b->size(),(double)(t2-t1)/CLOCKS_PER_SEC);
  if (result != TAUCS_SUCCESS){
    Msg::Error("Taucs Was Not Successfull %d",result);
  }  
  return 1;
}

#endif
