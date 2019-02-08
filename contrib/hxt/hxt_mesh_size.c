#include "hxt_api.h"
#include "hxt_tools.h"
#include "hxt_mesh_size.h"
#include <math.h>

//typedef struct hxtMeshSizeStruct HXTMeshSize; // already defined in hxt_api.h

HXTStatus hxtMeshSizeCellEvaluate(HXTMeshSizeCell *cell, double x, double y, double z, double *v) {
  if (cell->isleaf){
    *v = *(double*)cell->data;
    return HXT_STATUS_OK;
  }
  HXTMeshSizeCell *sub = (HXTMeshSizeCell*)cell->data;
  int i = x > 0.5 ? 1 : 0;
  int j = y > 0.5 ? 1 : 0;
  int k = z > 0.5 ? 1 : 0;
  return hxtMeshSizeCellEvaluate(&sub[i*4+j*2+k],2*x-i, 2*y-j, 2*z-k, v);
}

HXTStatus hxtMeshSizeCreate (HXTContext* context, HXTMeshSize **meshSizePtr)
{
  HXTMeshSize *meshSize;
  HXT_CHECK(
    hxtMalloc(&meshSize, sizeof(HXTMeshSize)));

  meshSize->context = context;
  meshSize->root.data = NULL;
  *meshSizePtr = meshSize;
  return HXT_STATUS_OK;
}

HXTStatus hxtMeshSizeCellReleaseMemory(HXTMeshSizeCell *cell)
{
  if(!cell->data)
    return HXT_STATUS_OK;
  if(!cell->isleaf) {
    HXTMeshSizeCell *sub = (HXTMeshSizeCell*) cell->data;
    for (int i = 0; i < 8; ++i)
      HXT_CHECK(hxtMeshSizeCellReleaseMemory(&sub[i]));
  }
  HXT_CHECK(hxtFree(&cell->data));
  return HXT_STATUS_OK;
}



HXTStatus hxtMeshSizeCellInit(HXTMeshSizeCell *cell, double x0, double y0, double z0, double l, HXTMeshSizeCallback cb, void *data, int level) {
#if 0
  double v[8] = {
    field(x0,y0,z0),field(x0,y0,z0+l),field(x0,y0+l,z0),field(x0,y0+l,z0+l),
    field(x0+l,y0,z0),field(x0+l,y0,z0+l),field(x0+l,y0+l,z0),field(x0+l,y0+l,z0+l)
  };
  double dmax = 0;
  double vmin = v[0];
  double vc = field(x0+l/2,y0+l/2,z0+l/2);
  for (int i = 0; i < 8; ++i){
    dmax = fmax(dmax, std::abs(vc-v[i]));
    vmin = fmin(vmin, v[i]);
  }
#else
  double dmax = 0;
  double x[3] = {x0+l/2, y0+l/2, z0+l/2};
  double vc;
  HXT_CHECK(cb(x, data, &vc));
  double vmin = vc;
  int split = level > 0;
  if (level > -4) {
#define NSAMPLE 4
    double dl = l/NSAMPLE;
    for (int i = 0; i <= NSAMPLE; ++i){
      for (int j = 0; j <= NSAMPLE; ++j){
        for (int k = 0; k <= NSAMPLE; ++k){
          double xs[3] = {x0 + i*dl, y0+j*dl, z0+k*dl};
          double w;
          HXT_CHECK(cb(xs, data, &w));
          dmax = fmax(dmax, fabs(vc-w));
          vmin = fmin(vmin, w);
          split |= (dmax/vmin > 0.2 && vmin < l);
          if(split)
            break;
        }
      }
    }
#endif
  }
  if (split) {
    cell->isleaf = 0;
    HXTMeshSizeCell *sub;
    HXT_CHECK(hxtMalloc(&sub, sizeof(HXTMeshSizeCell)*8));
    double l2 = l/2;
    HXT_CHECK(hxtMeshSizeCellInit(sub+0, x0, y0, z0, l2, cb, data, level-1));
    HXT_CHECK(hxtMeshSizeCellInit(sub+1, x0, y0, z0+l2, l2, cb, data, level-1));
    HXT_CHECK(hxtMeshSizeCellInit(sub+2, x0, y0+l2, z0, l2, cb, data, level-1));
    HXT_CHECK(hxtMeshSizeCellInit(sub+3, x0, y0+l2, z0+l2, l2, cb, data, level-1));
    HXT_CHECK(hxtMeshSizeCellInit(sub+4, x0+l2, y0, z0, l2, cb, data, level-1));
    HXT_CHECK(hxtMeshSizeCellInit(sub+5, x0+l2, y0, z0+l2, l2, cb, data, level-1));
    HXT_CHECK(hxtMeshSizeCellInit(sub+6, x0+l2, y0+l2, z0, l2, cb, data, level-1));
    HXT_CHECK(hxtMeshSizeCellInit(sub+7, x0+l2, y0+l2, z0+l2, l2, cb, data, level-1));
    cell->data = (void*)sub;
  }
  else {
    cell->isleaf = 1;
    HXT_CHECK(hxtMalloc(&cell->data, sizeof(double)));
    *(double*)cell->data = vc;
  }
  return HXT_STATUS_OK;
}

HXTStatus hxtMeshSizeDelete(HXTMeshSize **meshSizePtr)
{
  HXTMeshSize *meshSize = *meshSizePtr;
  if (meshSize == NULL)
    return HXT_STATUS_OK;
  HXT_CHECK(hxtMeshSizeCellReleaseMemory(&meshSize->root));
  HXT_CHECK(hxtFree(&meshSize));
  *meshSizePtr = NULL;
  return HXT_STATUS_OK;
}

HXTStatus hxtMeshSizeEvaluate(HXTMeshSize *meshSize, double x[3], double *v)
{
  if(!meshSize->root.data) {
    //hxtMessageError(meshSize->context, "meshSize has not been computed\n");
    return HXT_ERROR_MSG(HXT_STATUS_FAILED, "meshSize has not been computed");
  }
  double *bbmin = meshSize->bbmin;
  double l = meshSize->l0;
  HXT_CHECK(hxtMeshSizeCellEvaluate(&meshSize->root, (x[0]-bbmin[0])/l, (x[1]-bbmin[1])/l, (x[2]-bbmin[2])/l, v));
  return HXT_STATUS_OK;
}

HXTStatus  hxtMeshSizeCompute( HXTMeshSize *meshSize , double min[3], double max[3], HXTMeshSizeCallback cb, void *data)
{
  if (meshSize->root.data) {
    HXT_CHECK(hxtMeshSizeCellReleaseMemory(&meshSize->root));
  }
  for (int i = 0; i < 3; ++i) {
    meshSize->bbmin[i] = min[i];
    meshSize->bbmax[i] = max[i];
  }
  double l = fmax(max[0]-min[0], fmax(max[1]-min[1], max[2]-min[2]));
  meshSize->l0 = l;
  HXT_CHECK(hxtMeshSizeCellInit(&meshSize->root,min[0],min[1],min[2],l, cb, data, 4));
  return HXT_STATUS_OK;
}
