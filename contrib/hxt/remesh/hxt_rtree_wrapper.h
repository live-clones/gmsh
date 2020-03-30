#ifndef HXT_RTREE_WRAPPER_H
#define HXT_RTREE_WRAPPER_H

#include "hxt_api.h"

#ifdef __cplusplus
extern "C" {
#endif

HXTStatus hxtRTreeCreate(void ** data);
HXTStatus hxtRTreeDelete(void ** data);
HXTStatus hxtRTreeInsert(const double min[3], const double max[3], int id, void *data);
HXTStatus hxtRTreeSearch(const double min[3], const double max[3], int* nb, int** ids, void *data);

HXTStatus hxtAddPointInRTree(double *point, double box, uint32_t id, void *data);

#ifdef __cplusplus
}
#endif

#endif
