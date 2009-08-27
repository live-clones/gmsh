// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "gmshLinearSystemCSR.h"

#define SWAP(a,b)  temp=(a);(a)=(b);(b)=temp;
#define SWAPI(a,b) tempi=(a);(a)=(b);(b)=tempi;

void *CSRMalloc(size_t size)
{
  void *ptr;
  if (!size) return(NULL);
  ptr = malloc(size);
  return(ptr);
}

void *CSRRealloc(void *ptr, size_t size)
{
  if (!size) return(NULL);
  ptr = realloc(ptr,size);
  return(ptr);
}

void CSRList_Realloc(CSRList_T *liste,int n)
{
  char* temp;
  if (n <= 0) return;
  if (liste->array == NULL) {
    liste->nmax = ((n - 1) / liste->incr + 1) * liste->incr;
    liste->array = (char *)CSRMalloc(liste->nmax * liste->size);
  }
  else {
    if (n > liste->nmax) {
      liste->nmax = ((n - 1) / liste->incr + 1) * liste->incr;
      temp = (char *)CSRRealloc(liste->array, liste->nmax * liste->size);
      liste->array = temp;
    }
  }
}


CSRList_T *CSRList_Create(int n, int incr, int size)
{
  CSRList_T *liste;

  if (n <= 0)  n = 1 ;
  if (incr <= 0) incr = 1;

  liste = (CSRList_T *)CSRMalloc(sizeof(CSRList_T));

  liste->nmax    = 0;
  liste->incr    = incr;
  liste->size    = size;
  liste->n       = 0;
  liste->isorder = 0;
  liste->array   = NULL;

  CSRList_Realloc(liste,n);
  return(liste);
}

void CSRList_Delete(CSRList_T *liste)
{
  if (liste != 0) {
    free(liste->array);
    free(liste);
  }
}

void CSRList_Add(CSRList_T *liste, void *data)
{
  liste->n++;

  CSRList_Realloc(liste,liste->n);
  liste->isorder = 0;
  memcpy(&liste->array[(liste->n - 1) * liste->size],data,liste->size);
}

int CSRList_Nbr(CSRList_T *liste)
{
  return(liste->n);
}

template<>
void gmshLinearSystemCSR<double>::allocate(int _nbRows)
{
  if(a_) {
    CSRList_Delete(a_);
    CSRList_Delete(ai_);
    CSRList_Delete(ptr_);
    CSRList_Delete(jptr_);
    delete _x;
    delete _b;
    delete something;
  }
  
  if(_nbRows == 0){
    a_ = 0; 
    ai_ = 0; 
    ptr_ = 0; 
    jptr_ = 0; 
    _b = 0;
    _x = 0;
    something = 0;
    return;
  }
  
  a_    = CSRList_Create (_nbRows, _nbRows, sizeof(double));
  ai_   = CSRList_Create (_nbRows, _nbRows, sizeof(INDEX_TYPE));
  ptr_  = CSRList_Create (_nbRows, _nbRows, sizeof(INDEX_TYPE));
  jptr_ = CSRList_Create (_nbRows+1, _nbRows, sizeof(INDEX_TYPE));

  something = new char[_nbRows];

  for (int i=0;i<_nbRows;i++)something[i] = 0;

  _b = new std::vector<double>(_nbRows);
  _x = new std::vector<double>(_nbRows);
}

const int NSTACK   = 50;
const unsigned int M_sort2  = 7;

static void free_ivector(int *v, long nl, long nh)
{
  // free an int vector allocated with ivector() 
  free((char*)(v+nl-1));
}

static int *ivector(long nl, long nh)
{
  // allocate an int vector with subscript range v[nl..nh] 
  int *v;  
  v=(int *)malloc((size_t) ((nh-nl+2)*sizeof(int)));
  if (!v) fprintf(stderr, "allocation failure in ivector()\n");
  return v-nl+1;
}

static int cmpij(INDEX_TYPE ai,INDEX_TYPE aj,INDEX_TYPE bi,INDEX_TYPE bj)
{
  if(ai<bi)return -1;
  if(ai>bi)return 1;
  if(aj<bj)return -1;
  if(aj>bj)return 1;
  return 0;
}

template <class scalar>
void _sort2_xkws(unsigned long n, double arr[], INDEX_TYPE ai[], INDEX_TYPE aj[])
{
  unsigned long i,ir=n,j,k,l=1;
  int *istack,jstack=0;
  INDEX_TYPE tempi;
  scalar a,temp;
  int    b,c;
    
  istack=ivector(1,NSTACK);
  for (;;) {
    if (ir-l < M_sort2) {
      for (j=l+1;j<=ir;j++) {
        a=arr[j -1];
        b=ai[j -1];
        c=aj[j -1];
        for (i=j-1;i>=1;i--) {
          if (cmpij(ai[i -1],aj[i -1],b,c) <= 0) break;
          arr[i+1 -1]=arr[i -1];
          ai[i+1 -1]=ai[i -1];
          aj[i+1 -1]=aj[i -1];
        }
        arr[i+1 -1]=a;
        ai[i+1 -1]=b;
        aj[i+1 -1]=c;
      }
      if (!jstack) {
        free_ivector(istack,1,NSTACK);
        return;
      }
      ir=istack[jstack];
      l=istack[jstack-1];
      jstack -= 2;
    } 
    else {
      k=(l+ir) >> 1;
      SWAP(arr[k -1],arr[l+1 -1])
      SWAPI(ai[k -1],ai[l+1 -1])
      SWAPI(aj[k -1],aj[l+1 -1])
      if (cmpij(ai[l+1 -1],aj[l+1 -1],ai[ir -1],aj[ir -1])>0){
        SWAP(arr[l+1 -1],arr[ir -1])
        SWAPI(ai[l+1 -1],ai[ir -1])
        SWAPI(aj[l+1 -1],aj[ir -1])
      }
      if (cmpij(ai[l -1],aj[l -1],ai[ir -1],aj[ir -1])>0){
        SWAP(arr[l -1],arr[ir -1])
        SWAPI(ai[l -1],ai[ir -1])
        SWAPI(aj[l -1],aj[ir -1])
      }
      if (cmpij(ai[l+1 -1],aj[l+1 -1],ai[l -1],aj[l -1])>0){
        SWAP(arr[l+1 -1],arr[l -1])
        SWAPI(ai[l+1 -1],ai[l -1])
        SWAPI(aj[l+1 -1],aj[l -1])
      }
      i=l+1;
      j=ir;
      a=arr[l -1];
      b=ai[l -1];
      c=aj[l -1];
      for (;;) {
        do i++; while (cmpij(ai[i -1],aj[i -1],b,c) < 0);
        do j--; while (cmpij(ai[j -1],aj[j -1],b,c) > 0);
        if (j < i) break;
        SWAP(arr[i -1],arr[j -1])
        SWAPI(ai[i -1],ai[j -1])
        SWAPI(aj[i -1],aj[j -1])
        }
      arr[l -1]=arr[j -1];
      arr[j -1]=a;
      ai[l -1]=ai[j -1];
      ai[j -1]=b;
      aj[l -1]=aj[j -1];
      aj[j -1]=c;
      jstack += 2;
      if (jstack > NSTACK) {
        Msg::Fatal("NSTACK too small while sorting the columns of the matrix");
        throw;
      }
      if (ir-i+1 >= j-l) {
        istack[jstack]=ir;
        istack[jstack-1]=i;
        ir=j-1;
      } 
      else {
        istack[jstack]=j-1;
        istack[jstack-1]=l;
        l=i;
      }
    }
  }
}

template <class scalar>
void sortColumns(int NbLines, 
                 int nnz, 
                 INDEX_TYPE *ptr, 
                 INDEX_TYPE *jptr, 
                 INDEX_TYPE *ai, 
                 scalar *a)
{
  // replace pointers by lines
  int *count = new int [NbLines];

  for(int i=0;i<NbLines;i++){
    count[i] = 0;
    INDEX_TYPE _position =  jptr[i];
    while(1){
      count[i]++;
      INDEX_TYPE _position_temp = _position;
      _position = ptr[_position];
      ptr[_position_temp] = i;
      if (_position == 0) break;
    }
  }   
  _sort2_xkws<double>(nnz,a,ptr,ai);   
  jptr[0] = 0;
  for(int i=1;i<=NbLines;i++){
    jptr[i] = jptr[i-1] + count[i-1];
  }
  
  for(int i=0;i<NbLines;i++){
    for (int j= jptr[i] ; j<jptr[i+1]-1 ; j++){
      ptr[j] = j+1;
    }
    ptr[jptr[i+1]] = 0;
  }
  
  delete[] count;
}

#if defined(HAVE_GMM)
#include "gmm.h"
template<>
int gmshLinearSystemCSRGmm<double>::systemSolve()
{
  if (!sorted)
    sortColumns(_b->size(),
		CSRList_Nbr(a_),
		(INDEX_TYPE *) ptr_->array,
		(INDEX_TYPE *) jptr_->array, 
		(INDEX_TYPE *) ai_->array, 
		(double*) a_->array);
  sorted = true;

  gmm::csr_matrix_ref<double*,INDEX_TYPE *,INDEX_TYPE *, 0>  
    ref((double*)a_->array, (INDEX_TYPE *) ai_->array,
        (INDEX_TYPE *)jptr_->array, _b->size(), _b->size());
  gmm::csr_matrix<double,0> M;
  M.init_with(ref);

  gmm::ildltt_precond<gmm::csr_matrix<double, 0> > P(M, 10, 1.e-10);
  gmm::iteration iter(_prec);
  iter.set_noisy(_noisy);
  if(_gmres) gmm::gmres(M, *_x, *_b, P, 100, iter);
  else gmm::cg(M, *_x, *_b, P, iter);
  return 1;
}
#endif

#if defined(HAVE_GMM)
#include "gmm.h"
template<>
int gmshLinearSystemCSRGmm<double>::checkSystem()
{
  if(!sorted)
    sortColumns(_b->size(),
		CSRList_Nbr(a_),
		(INDEX_TYPE *) ptr_->array,
		(INDEX_TYPE *) jptr_->array, 
		(INDEX_TYPE *) ai_->array, 
		(double*) a_->array);
  sorted = true;

  printf("Coucou check system \n");
  for (unsigned int i = 0; i < _b->size(); i++)
    printf("%d ",((INDEX_TYPE *) jptr_->array)[i]);
  printf("\n");

  return 1;
}
#endif

#if defined(HAVE_TAUCS)
#include "taucs.h"
template<>
int gmshLinearSystemCSRTaucs<double>::systemSolve()
{
  if(!sorted)
    sortColumns(_b->size(),
		CSRList_Nbr(a_),
		(INDEX_TYPE *) ptr_->array,
		(INDEX_TYPE *) jptr_->array, 
		(INDEX_TYPE *) ai_->array, 
		(double*) a_->array);
  sorted = true;

  taucs_ccs_matrix myVeryCuteTaucsMatrix;
  myVeryCuteTaucsMatrix.n = myVeryCuteTaucsMatrix.m =  _b->size();
  myVeryCuteTaucsMatrix.rowind = (INDEX_TYPE*)jptr_->array;
  myVeryCuteTaucsMatrix.colptr = (INDEX_TYPE*)ai_->array;
  myVeryCuteTaucsMatrix.values.d = (double*) a_->array;
  char* options[] = { "taucs.factor.LLT=true", NULL };  
  int result = taucs_linsolve(&myVeryCuteTaucsMatrix, 
                              NULL, 1, &(*_x)[0],&(*_b)[0],
                              options,NULL);                         
  if (result != TAUCS_SUCCESS){
    Msg::Error("Taucs Was Not Successfull");
  }  
  return 1;
}
#endif
