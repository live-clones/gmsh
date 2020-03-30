#include "hxt_rtree_wrapper.h"
#include "rtree.hpp"
#include "hxt_tools.h"
#include <vector>

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
