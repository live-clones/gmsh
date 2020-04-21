#ifdef HXT_HAVE_PETSC
#include "hxt_linear_system_petsc.h"
#include "petscksp.h"
#include "petscvec.h"
#include "hxt_message.h"
#define HXT_PETSC_CHECK(status) HXT_CHECK_MSG(status == 0 ? HXT_STATUS_OK : HXT_STATUS_FAILED, "PETSc error")

#if PETSC_VERSION_MAJOR != 3 || PETSC_VERSION_MINOR < 6
#error PETSc version >= 3.6 is required
#endif


struct HXTLinearSystemPETScStruct {
  int nElements;
  int nNodesByElement;
  uint32_t nMappedNodes;
  uint32_t nNodes;
  uint32_t *elements;
  uint32_t nDofs;
  int nFields;
  uint32_t *nodeMap;
  uint32_t *inverseNodeMap;
  double *fixed;
  KSP ksp;
  Mat a;
  Vec x;
  int assemblyNeeded;
};

#define CSIZE 10
typedef struct SparsityChunkStruct {
  int n[CSIZE];
  struct SparsityChunkStruct *next;
}SparsityChunk;

static HXTStatus sparsityChunkNew(SparsityChunk** new)
{
  HXT_CHECK( hxtMalloc(new, sizeof(SparsityChunk)) );
  for (int i = 0; i < CSIZE; ++i)
    (*new)->n[i] = -1;
  (*new)->next = NULL;
}

static HXTStatus sparsityChunkInsert(SparsityChunk *s, int id)
{
  for (int i=0; i<CSIZE; ++i) {
    if (s->n[i] == -1) s->n[i] = id;
    if (s->n[i] == id) return;
  }
  if (s->next == NULL) {
    HXT_CHECK( sparsityChunkNew(&s->next) );
  }
  HXT_CHECK( sparsityChunkInsert(s->next, id) );
}

static HXTStatus sparsityChunkFree(SparsityChunk *s)
{
  if (s->next) {
    HXT_CHECK( hxtFree(s->next) );
  }
  HXT_CHECK( hxtFree(&s) );
}

static HXTStatus assembleIfNeeded(HXTLinearSystemPETSc *system)
{
  if(system->assemblyNeeded) {
    HXT_PETSC_CHECK(MatAssemblyBegin(system->a, MAT_FINAL_ASSEMBLY));
    HXT_PETSC_CHECK(MatAssemblyEnd(system->a, MAT_FINAL_ASSEMBLY));
    system->assemblyNeeded = 0;
  }
  return HXT_STATUS_OK;
}

static HXTStatus linearSystemPreAllocateMatrix(HXTLinearSystemPETSc *system)
{
  SparsityChunk **sparsity;
  HXT_CHECK( hxtMalloc(&sparsity, sizeof(SparsityChunk*)*system->nMappedNodes) );
  for (int i = 0; i < system->nMappedNodes; ++i){
    HXT_CHECK( sparsityChunkNew(&sparsity[i]) );
  }
  for (int i = 0; i < system->nElements; ++i) {
    uint32_t *el = system->elements + system->nNodesByElement * i;
    for (int k = 0; k < system->nNodesByElement; ++k) {
      uint32_t nk = system->nodeMap[el[k]];
      if (nk == -1)
        continue;
      for (int l = 0; l < system->nNodesByElement; ++l) {
        uint32_t nl = system->nodeMap[el[l]];
        if (nl == -1)
          continue;
        HXT_CHECK( sparsityChunkInsert(sparsity[nk], nl) );
      }
    }
  }
  int *nByRow;
  HXT_CHECK( hxtMalloc(&nByRow, sizeof(int) * system->nMappedNodes*system->nFields) );
  for (uint32_t i = 0; i < system->nMappedNodes; ++i){
    int n = 0;
    SparsityChunk *c = sparsity[i];
    while (c->next) {
      n += CSIZE;
      c = c->next;
    }
    for (int j = 0; j < CSIZE; ++j)
      if(c->n[j] != -1)
        n++;
    HXT_CHECK( sparsityChunkFree(sparsity[i]) );
    for (uint32_t j = 0; j < system->nFields; ++j){
      nByRow[i*system->nFields+j] = n*system->nFields;
    }
  }
  HXT_CHECK( hxtFree(&sparsity) );
  HXT_PETSC_CHECK(MatSeqAIJSetPreallocation(system->a, 0, nByRow));
  HXT_CHECK( hxtFree(&nByRow) );
  return HXT_STATUS_OK;
}


HXTStatus hxtLinearSystemPETScAddToMatrix(HXTLinearSystemPETSc *system, int el0, int el1, const double *localMatrix){
  int nf = system->nFields;
  int nn = system->nNodesByElement;
  uint32_t *e0 = system->elements + el0*nn;
  uint32_t *e1 = system->elements + el1*nn;
  int *map0, *map1;
  HXT_CHECK( hxtMalloc(&map0, sizeof(int)*nn*nf) );
  HXT_CHECK( hxtMalloc(&map1, sizeof(int)*nn*nf) );
  for(int i=0; i<nn; ++i){
    for (int j=0; j<nf; ++j){
      map0[j*nn+i] = system->nodeMap[e0[i]]*nf+j;
      map1[j*nn+i] = system->nodeMap[e1[i]]*nf+j;
    }
  }
  HXT_PETSC_CHECK(MatSetValues(system->a,nn*nf,map0,nn*nf,map1,localMatrix,ADD_VALUES));
  HXT_CHECK( hxtFree(&map0) );
  HXT_CHECK( hxtFree(&map1) );
  system->assemblyNeeded = 1;
  return HXT_STATUS_OK;
}

HXTStatus hxtLinearSystemPETScAddToRhs(HXTLinearSystemPETSc *system, double *rhs, int el0, const double *localVector)
{
  int nf = system->nFields;
  int nn = system->nNodesByElement;
  uint32_t *e0 = system->elements + el0*nn;
  for(int i=0; i<nn; ++i){
    uint32_t n = system->nodeMap[e0[i]];
    for (int j=0; j<nf; ++j){
      rhs[n*nf+j] += localVector[j*nn+i];
    }
  }
  return HXT_STATUS_OK;
}

HXTStatus hxtLinearSystemPETScZeroMatrix(HXTLinearSystemPETSc *system)
{
  HXT_CHECK(assembleIfNeeded(system));
  HXT_PETSC_CHECK(MatZeroEntries(system->a));
  return HXT_STATUS_OK;
}

HXTStatus hxtLinearSystemPETScSetMatrixRowIdentity(HXTLinearSystemPETSc *system, int node, int field)
{
  if (node >= system->nMappedNodes || system->nodeMap[node] == -1) {
    HXT_WARNING("ignoring boundary condition on node %i", node);
    return HXT_STATUS_OK;
  }
  HXT_CHECK(assembleIfNeeded(system));
  int row = system->nodeMap[node]*system->nFields + field;
  int ncols;
  const int *cols;
  const double *v;
  HXT_PETSC_CHECK(MatGetRow(system->a, row, &ncols, &cols, &v));
  for (int i = 0; i < ncols; ++i) {
    // I know this is not correct but it works and using MatSetValues or MatZeroRows is much slower
    ((double*)v)[i] = cols[i] == row ? 1. : 0.;
  }
  HXT_PETSC_CHECK(MatRestoreRow(system->a, row, &ncols, &cols, &v));
  //HXT_PETSC_CHECK(MatZeroRows(system->a, 1, &row,1., NULL, NULL));
  return HXT_STATUS_OK;
}


HXTStatus hxtLinearSystemPETScSetMatrixRowFieldCombinaison(HXTLinearSystemPETSc *system, int node, int field, double *coeff)
{
  if (node >= system->nMappedNodes || system->nodeMap[node] == -1) {
    HXT_WARNING("ignoring boundary condition on node %i", node);
    return HXT_STATUS_OK;
  }
  HXT_CHECK(assembleIfNeeded(system));
  int row = system->nodeMap[node]*system->nFields + field;
  HXT_PETSC_CHECK(MatZeroRows(system->a, 1, &row, 0., NULL, NULL));
  row = system->nodeMap[node]*system->nFields;
  for (int i = 0; i < system->nFields; ++i) {
    HXT_PETSC_CHECK(MatSetValue(system->a, row+field, row+i, coeff[i], ADD_VALUES));
  }
  system->assemblyNeeded = 1;
  return HXT_STATUS_OK;
}

HXTStatus hxtLinearSystemPETScSetRhsEntry(HXTLinearSystemPETSc *system, double *rhs, int node, int field, double v)
{
  if (node >= system->nMappedNodes || system->nodeMap[node] == -1) {
    HXT_WARNING("ignoring boundary condition on node %i", node);
    return HXT_STATUS_OK;
  }
  int row = system->nodeMap[node]*system->nFields + field;
  rhs[row] = v;
  return HXT_STATUS_OK;
}

HXTStatus hxtLinearSystemPETScAddMatrixEntry(HXTLinearSystemPETSc *system, int node0, int field0, int node1, int field1, double v)
{
  if (system->nodeMap[node0] == -1 || system->nodeMap[node1] == -1)
    HXT_ERROR_MSG(HXT_STATUS_FAILED, "node %i or %i not in the domain", node0, node1);
  int row0 = system->nodeMap[node0]*system->nFields + field0;
  int col1 = system->nodeMap[node1]*system->nFields + field1;
  
  HXT_PETSC_CHECK(MatSetValue(system->a, row0, col1, v, ADD_VALUES));

  system->assemblyNeeded = 1;
  
  return HXT_STATUS_OK;
}

HXTStatus hxtLinearSystemPETScAddRhsEntry(HXTLinearSystemPETSc *system, double *rhs, int node, int field, double v)
{
  if (system->nodeMap[node] == -1)
    return HXT_STATUS_OK;
  int row = system->nodeMap[node]*system->nFields + field;
  rhs[row] += v;
  return HXT_STATUS_OK;
}


HXTStatus hxtLinearSystemPETScSolve(HXTLinearSystemPETSc *system, double *rhs, double *solution){
  Vec b;
  HXT_PETSC_CHECK(VecCreateSeqWithArray(PETSC_COMM_SELF, 1, system->nDofs, rhs, &b));
  if(system->assemblyNeeded) {
    HXT_PETSC_CHECK(MatAssemblyBegin(system->a, MAT_FINAL_ASSEMBLY));
    HXT_PETSC_CHECK(MatAssemblyEnd(system->a, MAT_FINAL_ASSEMBLY));
    system->assemblyNeeded = 0;
  }
  HXT_PETSC_CHECK(KSPSetOperators(system->ksp, system->a, system->a));
  HXT_PETSC_CHECK(KSPSolve(system->ksp, b, system->x));
  HXT_PETSC_CHECK(VecDestroy(&b));
  HXT_CHECK(hxtLinearSystemPETScMapFromVec(system, system->x, solution));
  return HXT_STATUS_OK;
}

HXTStatus hxtLinearSystemPETScCreate(HXTLinearSystemPETSc **pSystem, int nElements, int nNodesByElement, int nFields, uint32_t *elements, const char *petscOptions)
{
  static int prefixid = 0;
  char prefix[256];
  sprintf(prefix, "hxtsys%i", prefixid++);
  #if PETSC_VERSION_MINOR < 7
  HXT_PETSC_CHECK(PetscOptionsPrefixPush(prefix));
  HXT_PETSC_CHECK(PetscOptionsInsertString(petscOptions));
  HXT_PETSC_CHECK(PetscOptionsPrefixPop());
  #else
  HXT_PETSC_CHECK(PetscOptionsPrefixPush(NULL, prefix));
  HXT_PETSC_CHECK(PetscOptionsInsertString(NULL, petscOptions));
  HXT_PETSC_CHECK(PetscOptionsPrefixPop(NULL));
  #endif
  HXTLinearSystemPETSc *system;
  HXT_CHECK( hxtMalloc(&system, sizeof(HXTLinearSystemPETSc)) );
  *pSystem = system;
  system->nElements = nElements;
  system->nNodesByElement = nNodesByElement;
  system->nFields = nFields;
  system->elements = elements;
  uint32_t nNodes = 0;
  for (int i = 0; i < nElements*nNodesByElement; ++i) {
    if (elements[i] >= nNodes)
      nNodes = elements[i]+1;
  }
  system->nNodes = nNodes;
  uint32_t *nodeMap;
  HXT_CHECK( hxtMalloc(&nodeMap, sizeof(uint32_t) * nNodes) );
  for (uint32_t i = 0; i < nNodes; ++i) {
    nodeMap[i] = -1;
  }
  uint32_t nMappedNodes = 0;
  for (int i = 0; i < nElements*nNodesByElement; ++i) {
    if (nodeMap[elements[i]] == -1)
      nodeMap[elements[i]] = nMappedNodes++;
  }
  system->nodeMap = nodeMap;
  system->nMappedNodes = nMappedNodes;
  uint32_t nDofs = nMappedNodes * nFields;
  system->nDofs = nDofs;
  HXT_PETSC_CHECK(MatCreate(MPI_COMM_WORLD, &system->a));
  HXT_PETSC_CHECK(MatSetSizes(system->a, nDofs, nDofs, PETSC_DETERMINE, PETSC_DETERMINE));
  HXT_PETSC_CHECK(MatSetOptionsPrefix(system->a, prefix));
  HXT_PETSC_CHECK(MatSetFromOptions(system->a));
  HXT_PETSC_CHECK(MatSetOption(system->a,MAT_KEEP_NONZERO_PATTERN,PETSC_TRUE));
  HXT_PETSC_CHECK(MatSetOption(system->a,MAT_NO_OFF_PROC_ZERO_ROWS,PETSC_TRUE));
  HXT_CHECK(linearSystemPreAllocateMatrix(system));
  //HXT_PETSC_CHECK(MatSetOption(system->a,MAT_NEW_NONZERO_ALLOCATION_ERR, PETSC_FALSE));//
  HXT_PETSC_CHECK(VecCreate(MPI_COMM_WORLD, &system->x));
  HXT_PETSC_CHECK(VecSetSizes(system->x, nDofs, PETSC_DETERMINE));
  HXT_PETSC_CHECK(VecSetOptionsPrefix(system->x, prefix));
  HXT_PETSC_CHECK(VecSetFromOptions(system->x));
  HXT_PETSC_CHECK(KSPCreate(MPI_COMM_WORLD, &system->ksp));
  HXT_PETSC_CHECK(KSPSetOptionsPrefix(system->ksp, prefix));
  HXT_PETSC_CHECK(KSPSetFromOptions(system->ksp));
  system->assemblyNeeded = 0;
  return HXT_STATUS_OK;
}

HXTStatus hxtLinearSystemPETScDelete(HXTLinearSystemPETSc **pSystem)
{
  HXTLinearSystemPETSc *system = *pSystem;
  if (system == NULL)
    return HXT_STATUS_OK;
  HXT_PETSC_CHECK(KSPDestroy(&system->ksp));
  HXT_PETSC_CHECK(VecDestroy(&system->x));
  HXT_PETSC_CHECK(MatDestroy(&system->a));
  HXT_CHECK( hxtFree(&system->nodeMap) );
  HXT_CHECK( hxtFree(&system) );
  *pSystem = NULL;
  return HXT_STATUS_OK;
}

HXTStatus hxtLinearSystemPETScGetRhsNorm(HXTLinearSystemPETSc *system, double *rhs, double *pNorm)
{
  uint32_t nn = system->nNodes * system->nFields;
  double norm = 0;
  for (uint32_t i = 0; i < nn ; i++)
    norm += rhs[i]*rhs[i];
  *pNorm = sqrt(norm);
  return HXT_STATUS_OK;
}

HXTStatus hxtInitializePETSc(int *argc, char ***argv) {
  HXT_PETSC_CHECK(PetscInitialize(argc, argv, NULL, NULL));
  return HXT_STATUS_OK;
}

HXTStatus hxtLinearSystemPETScHasConverged(HXTLinearSystemPETSc *lsys, int *converged)
{
  KSPConvergedReason reason;
  HXT_PETSC_CHECK(KSPGetConvergedReason(lsys->ksp,&reason));
  *converged = (reason>0);
  return HXT_STATUS_OK;
}

HXTStatus hxtLinearSystemPETScSize(HXTLinearSystemPETSc *lsys, int *size)
{
  *size = lsys->nDofs;
  return HXT_STATUS_OK;
}

HXTStatus hxtLinearSystemPETScGetMat(HXTLinearSystemPETSc *lsys, Mat *mat)
{
  *mat = lsys->a;
  return HXT_STATUS_OK;
}

HXTStatus hxtLinearSystemPETScMapToVec(HXTLinearSystemPETSc *system, double *v, Vec vec)
{
  double *vv;
  HXT_PETSC_CHECK(VecGetArray(vec, &vv));
  int nf = system->nFields;
  for (int i=0; i< system->nNodes; ++i) {
    uint32_t n= system->nodeMap[i];
    for (int j = 0; j < nf; ++j)
      vv[n*nf+j] = v[i*nf+j];
  }
  HXT_PETSC_CHECK(VecRestoreArray(vec, &vv));
  return HXT_STATUS_OK;
}

HXTStatus hxtLinearSystemPETScMapFromVec(HXTLinearSystemPETSc *system, Vec vec, double *v)
{
  const double *vv;
  HXT_PETSC_CHECK(VecGetArrayRead(vec, &vv));
  int nf = system->nFields;
  for (int i=0; i< system->nNodes; ++i) {
    uint32_t n= system->nodeMap[i];
    for (int j = 0; j < nf; ++j)
      v[i*nf+j] = vv[n*nf+j];
  }
  HXT_PETSC_CHECK(VecRestoreArrayRead(vec, &vv));
  return HXT_STATUS_OK;
}

#endif
