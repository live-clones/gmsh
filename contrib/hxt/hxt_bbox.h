#ifndef        _HXT_BBOX_H_
#define _HXT_BBOX_H_

#include <float.h>
#include "hxt_api.h"
#include "hxt_mesh.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct hxtBboxStruct{
    double hxtDeclareAligned min[3];
    double hxtDeclareAligned max[3];
} hxtBbox;

// /* create a new bounding box */
// HXTStatus hxtBboxCreate(hxtBbox** bboxP);

// /* delete a bounding box */
// HXTStatus hxtBboxDelete(hxtBbox** bboxP);

static inline void hxtBboxInit(hxtBbox* bbox){
  bbox->min[0] = DBL_MAX;
  bbox->min[1] = DBL_MAX;
  bbox->min[2] = DBL_MAX;
  bbox->max[0] = -DBL_MAX;
  bbox->max[1] = -DBL_MAX;
  bbox->max[2] = -DBL_MAX;
}

/* update the bounding box with one new vertex */
HXTStatus hxtBboxAddOne(hxtBbox* bbox, double* coord);

/* update the bounding box with an array of n vertices at once (far quicker) */
HXTStatus hxtBboxAdd(hxtBbox* bbox, double* coord, uint32_t n);

#ifdef __cplusplus
}
#endif

#endif
