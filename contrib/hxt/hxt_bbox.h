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
} HXTBbox;

// /* create a new bounding box */
// HXTStatus hxtBboxCreate(HXTBbox** bboxP);

// /* delete a bounding box */
// HXTStatus hxtBboxDelete(HXTBbox** bboxP);

static inline void hxtBboxInit(HXTBbox* bbox){
  bbox->min[0] = DBL_MAX;
  bbox->min[1] = DBL_MAX;
  bbox->min[2] = DBL_MAX;
  bbox->max[0] = -DBL_MAX;
  bbox->max[1] = -DBL_MAX;
  bbox->max[2] = -DBL_MAX;
}

/* update the bounding box with one new vertex */
HXTStatus hxtBboxAddOne(HXTBbox* bbox, double* coord);

/* update the bounding box with an array of n vertices at once (far quicker) */
HXTStatus hxtBboxAdd(HXTBbox* bbox, double* coord, uint32_t n);

/* merge two bbox  (result can be a pointer to bbox1 or bbox2) */
HXTStatus hxtBboxMerge(HXTBbox* bbox1, HXTBbox* bbox2, HXTBbox* bboxResult);

#ifdef __cplusplus
}
#endif

#endif
