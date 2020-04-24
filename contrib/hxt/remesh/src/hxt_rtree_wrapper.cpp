#include "hxt_rtree_wrapper.h"
#include "rtree.hpp"
#include "hxt_tools.h"
#include <vector>
#include <float.h>

#include "hxt_post_debugging.h"

typedef struct {
  RTree<int, double, 3> *rtree;
} RTreeWrapperData;

HXTStatus hxtRTreeCreate(void ** data) {
  RTreeWrapperData *r;
  HXT_CHECK(hxtMalloc(&r, sizeof(RTreeWrapperData)));
  r->rtree = new RTree<int, double, 3>();
  *data = r;
  return HXT_STATUS_OK;
}

HXTStatus hxtRTreeDelete(void ** data) {
  RTreeWrapperData *r = (RTreeWrapperData*) *data;
  delete r->rtree;
  r->rtree = NULL;
  HXT_CHECK( hxtFree(&r) );
  return HXT_STATUS_OK;
}

HXTStatus hxtRTreeInsert(const double min[3], const double max[3], int id, void *data) {
  RTreeWrapperData *r = (RTreeWrapperData*) data;
  r->rtree->Insert(min, max, id);
  return HXT_STATUS_OK;
}

static bool rtreeCallbackPG(int id, void *ctx) {
  std::vector<int>* vec = reinterpret_cast< std::vector<int>* >(ctx);
  vec->push_back(id);
  return true;
}

HXTStatus hxtRTreeSearch(const double min[3], const double max[3], int* nb, int** ids, void *data) {
  RTreeWrapperData *r = (RTreeWrapperData*) data;
  std::vector<int> pts;
  r->rtree->Search(min, max, rtreeCallbackPG, &pts);
  *nb = pts.size();
  if (*nb > 0) {
    HXT_CHECK(hxtMalloc(ids, *nb * sizeof(int)));
    for (uint64_t i = 0; i < pts.size(); ++i) (*ids)[i] = pts[i];
  } else {
    ids = NULL;
  }
  return HXT_STATUS_OK;
}

HXTStatus hxtAddPointInRTree(double *point, double box, uint32_t id, void *data)
{
  double cpmin[3] = {point[0]-box, point[1]-box, point[2]-box};
  double cpmax[3] = {point[0]+box, point[1]+box, point[2]+box};
  HXT_CHECK(hxtRTreeInsert(cpmin,cpmax,id,data));
  return HXT_STATUS_OK;
}


//=============================================================================================
//=============================================================================================
//=============================================================================================

typedef struct {
  RTree<uint64_t, double, 3> *rtree;
} RTreeWrapperData64;

HXTStatus hxtRTreeCreate64(void ** data) {
  RTreeWrapperData64 *r;
  HXT_CHECK(hxtMalloc(&r, sizeof(RTreeWrapperData64)));
  r->rtree = new RTree<uint64_t, double, 3>();
  *data = r;
  return HXT_STATUS_OK;
}

HXTStatus hxtRTreeDelete64(void ** data) {
  RTreeWrapperData64 *r = (RTreeWrapperData64*) *data;
  delete r->rtree;
  r->rtree = NULL;
  HXT_CHECK( hxtFree(&r) );
  return HXT_STATUS_OK;
}

HXTStatus hxtRTreeInsert64(const double min[3], const double max[3], uint64_t id, void *data) {
  RTreeWrapperData64 *r = (RTreeWrapperData64*) data;
  r->rtree->Insert(min, max, id);
  return HXT_STATUS_OK;
}

static bool rtreeCallbackPG(uint64_t id, void *ctx) {
  std::vector<uint64_t>* vec = reinterpret_cast< std::vector<uint64_t>* >(ctx);
  vec->push_back(id);
  return true;
}

HXTStatus hxtRTreeSearch64(const double min[3], const double max[3], uint64_t* nb, uint64_t** ids, void *data) {
  RTreeWrapperData64 *r = (RTreeWrapperData64*) data;
  std::vector<uint64_t> pts;
  r->rtree->Search(min, max, rtreeCallbackPG, &pts);
  *nb = pts.size();
  if (*nb > 0) {
    HXT_CHECK(hxtMalloc(ids, *nb * sizeof(uint64_t)));
    for (uint64_t i = 0; i < pts.size(); ++i) (*ids)[i] = pts[i];
  } else {
    ids = NULL;
  }
  return HXT_STATUS_OK;
}

HXTStatus hxtAddTriangleInRTree64(double *p0,
                                  double *p1,
                                  double *p2, 
                                  double box, uint64_t id, void *data)
{

  double cpmin[3] = {DBL_MAX,DBL_MAX,DBL_MAX};
  double cpmax[3] = {-DBL_MAX,-DBL_MAX,-DBL_MAX};
    
  if (p0[0] < cpmin[0]) cpmin[0] = p0[0];
  if (p0[1] < cpmin[1]) cpmin[1] = p0[1];
  if (p0[2] < cpmin[2]) cpmin[2] = p0[2];
  if (p0[0] > cpmax[0]) cpmax[0] = p0[0];
  if (p0[1] > cpmax[1]) cpmax[1] = p0[1];
  if (p0[2] > cpmax[2]) cpmax[2] = p0[2];

  if (p1[0] < cpmin[0]) cpmin[0] = p1[0];
  if (p1[1] < cpmin[1]) cpmin[1] = p1[1];
  if (p1[2] < cpmin[2]) cpmin[2] = p1[2];
  if (p1[0] > cpmax[0]) cpmax[0] = p1[0];
  if (p1[1] > cpmax[1]) cpmax[1] = p1[1];
  if (p1[2] > cpmax[2]) cpmax[2] = p1[2];

  if (p2[0] < cpmin[0]) cpmin[0] = p2[0];
  if (p2[1] < cpmin[1]) cpmin[1] = p2[1];
  if (p2[2] < cpmin[2]) cpmin[2] = p2[2];
  if (p2[0] > cpmax[0]) cpmax[0] = p2[0];
  if (p2[1] > cpmax[1]) cpmax[1] = p2[1];
  if (p2[2] > cpmax[2]) cpmax[2] = p2[2];

  cpmin[0] = cpmin[0]-box;
  cpmin[1] = cpmin[1]-box;
  cpmin[2] = cpmin[2]-box;
  cpmax[0] = cpmax[0]+box;
  cpmax[1] = cpmax[1]+box;
  cpmax[2] = cpmax[2]+box;

  HXT_CHECK(hxtRTreeInsert(cpmin,cpmax,id,data));
  return HXT_STATUS_OK;
}

HXTStatus hxtAddLineInRTree64(double *p0,
                              double *p1,
                              double box, uint64_t id, void *data)
{

  double cpmin[3] = {DBL_MAX,DBL_MAX,DBL_MAX};
  double cpmax[3] = {-DBL_MAX,-DBL_MAX,-DBL_MAX};
    
  if (p0[0] < cpmin[0]) cpmin[0] = p0[0];
  if (p0[1] < cpmin[1]) cpmin[1] = p0[1];
  if (p0[2] < cpmin[2]) cpmin[2] = p0[2];
  if (p0[0] > cpmax[0]) cpmax[0] = p0[0];
  if (p0[1] > cpmax[1]) cpmax[1] = p0[1];
  if (p0[2] > cpmax[2]) cpmax[2] = p0[2];

  if (p1[0] < cpmin[0]) cpmin[0] = p1[0];
  if (p1[1] < cpmin[1]) cpmin[1] = p1[1];
  if (p1[2] < cpmin[2]) cpmin[2] = p1[2];
  if (p1[0] > cpmax[0]) cpmax[0] = p1[0];
  if (p1[1] > cpmax[1]) cpmax[1] = p1[1];
  if (p1[2] > cpmax[2]) cpmax[2] = p1[2];

  cpmin[0] = cpmin[0]-box;
  cpmin[1] = cpmin[1]-box;
  cpmin[2] = cpmin[2]-box;
  cpmax[0] = cpmax[0]+box;
  cpmax[1] = cpmax[1]+box;
  cpmax[2] = cpmax[2]+box;

  HXT_CHECK(hxtRTreeInsert(cpmin,cpmax,id,data));
  return HXT_STATUS_OK;
}


