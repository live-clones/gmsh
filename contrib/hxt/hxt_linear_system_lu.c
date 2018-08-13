#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "hxt_tools.h"
#include "hxt_linear_system_lu.h"

#define CONMAX 200
static void connectivityInsert(int *connectivity, int i, int j)
{
  for (int k = 0; k < CONMAX; ++k) {
    int *p = connectivity + CONMAX*i + k;
    if (*p == -1)
      *p = j;
    if (*p == j)
      return;
  }
  printf("ERROR : node %i has more than %i neighbours\n", i, CONMAX);
}

struct HXTLinearSystemLUStruct{
  double *M;
  int *rowStart;
  int *rowEnd;
  int *rowLuEnd;
  double **rows;
  double *x;
  int *nodeMap;
  uint32_t *elements;
  int nNodesByElement;
  int nElements;
  int nNodes;
  int nFields;
  int n;
  int flaglu;
};

static void reverseCuthillMckee(HXTLinearSystemLU *system, int *ordering)
{
  int *nodeConnectivity = malloc(sizeof(int)*system->nNodes*CONMAX);
  for (int i = 0; i < system->nNodes*CONMAX; ++i) {
    nodeConnectivity[i] = -1;
  }
  for (int i = 0; i < system->nElements; ++i) {
    uint32_t *el = system->elements + i*system->nNodesByElement;
    for (int k = 0; k < system->nNodesByElement; ++k){
      for (int l = 0; l < system->nNodesByElement; ++l){
        if (k == l) continue;
        connectivityInsert(nodeConnectivity, el[k], el[l]);
        connectivityInsert(nodeConnectivity, el[l], el[k]);
      }
    }
  }
  int *nodeDegree = malloc(sizeof(int)*system->nNodes);
  for (int i = 0; i < system->nNodes; ++i) {
    nodeDegree[i] = 0;
    for (int j = 0; j < CONMAX; ++j) {
      if (nodeConnectivity[CONMAX*i+j] == -1)
        break;
      nodeDegree[i] += 1;
    }
  }
  int *queue = malloc(sizeof(int)*system->nNodes);
  queue[0] = 0;
  for (int i = 0; i < system->nNodes; ++i){
    ordering[i] = -1;
    if ((nodeDegree[queue[0]] == 0 || nodeDegree[queue[0]] > nodeDegree[i]) && nodeDegree[i] != 0){
      queue[0] = i;
    }
  }
  int stageStart = 0;
  int stageEnd = 1;
  int queueEnd = 1;
  int id = 0;
  while(stageStart != stageEnd) {
    for (int i = stageStart; i < stageEnd; ++i) {
      int c = queue[i];
      ordering[c] = id++;
      for(int j = 0; j < nodeDegree[c]; ++j) {
        int o = nodeConnectivity[c*CONMAX+j];
        if (ordering[o] == -1) {
          ordering[o] = -2;
#if 1
          queue[queueEnd++] = o;
#else
          int k = stageEnd;
          while(k < queueEnd && nodeDegree[queue[k]] < nodeDegree[o])
            k++;
          for (int l = queueEnd; l > k; --l)
            queue[l] = queue[l-1];
          queue[k] = o;
          queueEnd++;
#endif
        }
      }
    }
    stageStart = stageEnd;
    stageEnd = queueEnd;
  }
  for (int i = 0; i < system->nNodes; ++i)
    if(ordering[i] >= 0)
      ordering[i] = id-1-ordering[i];
  free(queue);
  free(nodeDegree);
  free(nodeConnectivity);
}


#define PADDING (SIMD_ALIGN/8)


typedef hxtDeclareAligned double alignedDouble;
#include <immintrin.h>
// y[from:to] += a*x[from:to]
// y and x must be 256-bit aligned
// memory should be allocated in consequence
static void rowAxpy(double a, double *__restrict__ px, double *__restrict__ py, int from, int to)
{
  // Can't use the aligned attribute on function arguments.
  hxtDeclareAligned double * __restrict__ x = px;
  hxtDeclareAligned double * __restrict__ y = py;

  int i = from;
  int pfrom = (from+7)&(~7);
  if (pfrom > to)
    pfrom = to;
  for (; i < pfrom; ++i)
    y[i] += a*x[i];
  for (; i+15 < to; i+=16) {
    hxtDeclareAligned double * __restrict__ X = x + i;
    hxtDeclareAligned double * __restrict__ Y = y + i;
    for (int j = 0; j < 16; ++j){
      Y[j] += a * X[j];
    }
  }
  for (; i+7 < to; i+=8) {
    hxtDeclareAligned double * __restrict__ X = x + i;
    hxtDeclareAligned double * __restrict__ Y = y + i;
    for (int j = 0; j < 8; ++j)
      Y[j] += a * X[j];
  }
  for (; i+3 < to; i+=4) {
    double * __restrict__ X = x + i;
    double * __restrict__ Y = y + i;
    for (int j = 0; j < 4; ++j)
      Y[j] += a * X[j];
  }
  for (; i < to; i++)
    y[i] += a*x[i];
}


static int imin(int a, int b) {
  return a < b ? a : b;
}

static double rowReduction(double *__restrict__ px, double *__restrict__ py, int from, int to)
{
  double r = 0;
  hxtDeclareAligned double * __restrict__ x = px;
  hxtDeclareAligned double * __restrict__ y = py;

  int i = from;
  int pfrom = (from+7)&(~7);
  for (; i < imin(pfrom, to); ++i)
    r += x[i] * y[i];
  double R[8];
  for (; i+7 < to; i+=8) {
    hxtDeclareAligned double * __restrict__ X = x + i;
    hxtDeclareAligned double * __restrict__ Y = y + i;
    for (int j = 0; j < 8; ++j)
      R[j] = X[j]*Y[j];
    r += R[0]+R[1]+R[2]+R[3]+R[4]+R[5]+R[6]+R[7];
  }
  for (; i < to; ++i)
    r += x[i] * y[i];
  return r;
}

static void rowZero(double *__restrict__ px, int from, int to)
{
  hxtDeclareAligned double * __restrict__ x = px;

  int i = from;
  int pfrom = (from+7)&(~7);
  for (; i < imin(pfrom, to); ++i)
    x[i] = 0;
  for (; i+7 < to; i+=8) {
    hxtDeclareAligned double * __restrict__ X = x + i;
    for (int j = 0; j < 8; ++j)
      X[j] = 0;
  }
  for (; i < to; ++i)
    x[i] = 0;
}

static HXTStatus LUPDecompose(HXTLinearSystemLU *system){
  int i,j;
  int N = system->n;
  double **A = system->rows;
  for(i=0;i<N;i++){
    for(j=i+1;j<system->rowLuEnd[i];j++){
      if (fabs(A[i][i]) < 1e-12)
        return HXT_ERROR_MSG(HXT_STATUS_FAILED, "zero pivot on line %i : %g", i, A[i][i]);
      if(i < system->rowStart[j] || A[j][i] == 0.)
        continue;
      A[j][i]/=A[i][i];
      rowAxpy(-A[j][i],A[i],A[j],i+1,system->rowEnd[i]);
    }
  }
  return(1);
}

static void LUPSolve(HXTLinearSystemLU *system, double *b){
  double *x = system->x;
  int N = system->n;
  double **A = system->rows;

  for(int i=0;i<N;i++){
    x[i] = b[i] - rowReduction(A[i], x, system->rowStart[i], i);
  }
  for(int i=N-1;i>=0;i--){
    x[i] -= rowReduction(A[i], x, i+1, imin(system->rowEnd[i], N));

    if(fabs(A[i][i])<1e-8)
      printf("pivot is close to be zero! %d\n",i);
    x[i] = x[i]/A[i][i];
  }
}

HXTStatus hxtLinearSystemLUCreate(HXTLinearSystemLU **pSystem, int nElements, int nNodesByElement, int nFields, uint32_t *elements)
{
  HXTLinearSystemLU *system = malloc(sizeof(HXTLinearSystemLU));
  *pSystem = system;
  system->nFields = nFields;
  system->nNodesByElement = nNodesByElement;
  system->nElements = nElements;
  system->elements = elements;
  int nNodes = 0;
  for (int i = 0; i < nElements*nNodesByElement; ++i)
    if(elements[i]+1 > nNodes)
      nNodes = elements[i]+1;
  system->nNodes = nNodes;
  system->n = nNodes *nFields;
  system->nodeMap = malloc(sizeof(int)*nNodes);
  reverseCuthillMckee(system, system->nodeMap);
  int nUsedNodes = 0;
  for (int i = 0; i < nNodes; ++i)
    if (system->nodeMap[i] >= 0)
      nUsedNodes ++;
  system->n = nUsedNodes*system->nFields;
  int *nodeRowStart = malloc(sizeof(int)*nUsedNodes);
  int *nodeRowEnd = malloc(sizeof(int)*nUsedNodes);
  for (int i = 0; i < nUsedNodes; ++i) {
    nodeRowEnd[i] = 0;
    nodeRowStart[i] = nUsedNodes;
  }
  for (int i = 0; i < nElements; ++i) {
    uint32_t *el = elements + i*nNodesByElement;
    for (int j = 0; j < nNodesByElement; ++j) {
      int n0 = system->nodeMap[el[j]];
      for (int k = 0; k < nNodesByElement; ++k) {
        int n1 = system->nodeMap[el[k]];
        if (n1 < 0 || n0 < 0) continue;
        if (nodeRowStart[n0] > n1)
          nodeRowStart[n0] = n1;
        if (nodeRowEnd[n0] < n1)
          nodeRowEnd[n0] = n1;
      }
    }
  }
  int totalSize = 0;
  system->rowStart = malloc(sizeof(int)*system->n);
  system->rowEnd = malloc(sizeof(int)*system->n);
  system->rowLuEnd = malloc(sizeof(int)*system->n);
  for (int i = 0; i < nUsedNodes; ++i) {
    for (int j = 0; j < nFields; ++j) {
      int k = i*nFields +j;
      system->rowStart[k] = nodeRowStart[i]*nFields;
      system->rowEnd[k] = nodeRowEnd[i]*nFields+nFields;
      system->rowLuEnd[k] = k;
    }
  }
  for (int i = 0; i < system->n; ++i) {
    for (int j = system->rowStart[i]; j < i; ++j) {
      if (system->rowLuEnd[j] < i+1) system->rowLuEnd[j] = i+1;
      if (system->rowEnd[i] < system->rowEnd[j]) system->rowEnd[i] = system->rowEnd[j];
    }
  }
  for (int i = 0; i < system->n; ++i) {
    int start = totalSize - system->rowStart[i];
    int paddedStart = (start+PADDING-1)&~(PADDING-1);
    totalSize += system->rowEnd[i]-system->rowStart[i]+(paddedStart-start);
  }
  free(nodeRowStart);
  free(nodeRowEnd);
  system->M = malloc(sizeof(double)*totalSize); // FIXME Gmsh instead of _mm_malloc
  system->rows = malloc(sizeof(double*)*system->n);
  for (int i = 0; i < totalSize; ++i)
    system->M[i] = 0;
  system->rows[0] = system->M;
  totalSize = 0;
  for (int i = 0; i < system->n; ++i){
    int start = totalSize - system->rowStart[i];
    int paddedStart = (start+PADDING-1)&~(PADDING-1);
    totalSize += system->rowEnd[i]-system->rowStart[i]+(paddedStart-start);
    system->rows[i] = system->M + paddedStart;
  }
  system->x = malloc(sizeof(double)*system->n); // FIXME Gmsh instead of _mm_malloc
  return HXT_STATUS_OK;
}

HXTStatus hxtLinearSystemLUAddToMatrix(HXTLinearSystemLU *system, int el0, int el1, const double *localMatrix){
  if(system->flaglu==1)
    HXT_ERROR_MSG(HXT_STATUS_FAILED, "the system has been already factorised!");
  int nn = system->nNodesByElement;
  uint32_t *e0 = system->elements + el0*nn;
  uint32_t *e1 = system->elements + el1*nn;
  int nf = system->nFields;
  for (int i = 0; i < nn; ++i) {
    for (int inf = 0; inf < nf; ++inf) {
      int ii = system->nodeMap[e0[i]]*nf + inf;
      for (int j = 0; j < nn; ++j) {
        for (int jnf = 0; jnf < nf; ++jnf) {
          int jj = system->nodeMap[e1[j]]*nf + jnf;
          system->rows[ii][jj] += localMatrix[(inf*nn+i)*nf*nn+jnf*nn+j];
        }
      }
    }
  }
  return HXT_STATUS_OK;
}

HXTStatus hxtLinearSystemLUAddToRhs(HXTLinearSystemLU *system, double *rhs, int el0, const double *localVector)
{
  int nFields = system->nFields;
  int nn = system->nNodesByElement;
  uint32_t *e0 = system->elements + el0*nn;
  for (int i = 0; i < nFields; ++i) {
    for (int j = 0; j < nn; ++j) {
      int m = system->nodeMap[e0[j]]*nFields+i;
      rhs[m] += localVector[i*nn+j];
    }
  }
  return HXT_STATUS_OK;
}

HXTStatus hxtLinearSystemLUZeroMatrix(HXTLinearSystemLU *system)
{
  system->flaglu = 0;
  for (int i = 0; i < system->n; ++i){
    rowZero(system->rows[i], system->rowStart[i], system->rowEnd[i]);
  }
  return HXT_STATUS_OK;
}

HXTStatus hxtLinearSystemLUSetMatrixRowIdentity(HXTLinearSystemLU *system, int node, int field)
{
  if (node >= system->nNodes || system->nodeMap[node] < 0) {
    HXT_WARNING("ignoring boundary condition on node %i", node);
    return HXT_STATUS_OK;
  }
  int row = system->nodeMap[node]*system->nFields + field;
  rowZero(system->rows[row], system->rowStart[row], system->rowEnd[row]);
  system->rows[row][row] = 1.;
  return HXT_STATUS_OK;
}

HXTStatus hxtLinearSystemLUSetMatrixRowFieldCombinaison(HXTLinearSystemLU *system, int node, int field, double *coeff)
{
  if (system->nodeMap[node] < 0) {
    HXT_WARNING("ignoring boundary condition on node %i", node);
    return HXT_STATUS_OK;
  }
  int row0 = system->nodeMap[node]*system->nFields;
  int row = row0+field;
  rowZero(system->rows[row], system->rowStart[row], system->rowEnd[row]);
  for (int i = 0; i < system->nFields; ++i) {
    system->rows[row][row0+i] = coeff[i];
  }
  return HXT_STATUS_OK;
}

HXTStatus hxtLinearSystemLUSetRhsEntry(HXTLinearSystemLU *system, double *rhs, int node, int field, double v)
{
  if (system->nodeMap[node] < 0) {
    return HXT_STATUS_OK;
  }
  int row = system->nodeMap[node]*system->nFields + field;
  rhs[row] = v;
  return HXT_STATUS_OK;
}

HXTStatus hxtLinearSystemLUAddMatrixEntry(HXTLinearSystemLU *system, int node0, int field0, int node1, int field1, double v)
{
  if(system->flaglu==1)
    HXT_ERROR_MSG(HXT_STATUS_FAILED, "the system has been already factorised!");
  if (system->nodeMap[node0] < 0 || system->nodeMap[node1] < 0)
    HXT_ERROR_MSG(HXT_STATUS_FAILED, "node %i or %i not in the domain", node0, node1);
  int row0 = system->nodeMap[node0]*system->nFields + field0;
  int col1 = system->nodeMap[node1]*system->nFields + field1;

  system->rows[row0][col1] += v;
  return HXT_STATUS_OK;
}

HXTStatus hxtLinearSystemLUAddRhsEntry(HXTLinearSystemLU *system, double *rhs, int node, int field, double v)
{
  if (system->nodeMap[node] < 0)
    return HXT_STATUS_OK;
  int row = system->nodeMap[node]*system->nFields + field;
  rhs[row] += v;
  return HXT_STATUS_OK;
}

HXTStatus hxtLinearSystemLUSolve(HXTLinearSystemLU *system, double *rhs, double *solution){
  if(system->flaglu==0){
    LUPDecompose(system);
    system->flaglu=1;
  }

  LUPSolve(system, rhs);
  for (int i = 0; i < system->nNodes; ++i){
    int ii = system->nodeMap[i];
    for (int j = 0; j < system->nFields; ++j){
      solution[i*system->nFields+j] = ii < 0 ? 0. : system->x[ii*system->nFields+j];
    }
  }
  return HXT_STATUS_OK;
}

HXTStatus hxtLinearSystemLUHasConverged(HXTLinearSystemLU *lsys, int *converged)
{
  *converged = 1;
  return HXT_STATUS_OK;
}

HXTStatus hxtLinearSystemLUDelete(HXTLinearSystemLU **pSystem)
{
  HXTLinearSystemLU *system = *pSystem;
  if (system == NULL)
    return HXT_STATUS_OK;
  free(system->x);
  free(system->M);
  free(system->rows);
  free(system->rowStart);
  free(system->rowEnd);
  free(system->rowLuEnd);
  free(system->nodeMap);
  free(system);
  *pSystem = NULL;
  return HXT_STATUS_OK;
}

HXTStatus hxtLinearSystemLUGetRhsNorm(HXTLinearSystemLU *system, double *rhs, double *pNorm)
{
  double norm = 0;
  for (int i = 0; i < system->n;++i)
      norm += rhs[i]*rhs[i];
  *pNorm =  sqrt(norm);
  return HXT_STATUS_OK;
}

HXTStatus hxtLinearSystemLUSize(HXTLinearSystemLU *lsys, int *size)
{
  *size = lsys->n;
  return HXT_STATUS_OK;
}
