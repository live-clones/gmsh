// Hxt - Copyright (C) 
// 2016 - 2020 UCLouvain
//
// See the LICENSE.txt file for license information.
//
// Contributor(s):
//   Célestin Marot

#ifndef HXT_BBOX_H
#define HXT_BBOX_H

#ifdef __cplusplus
extern "C" {
#endif

#include <hxt_tools.h> // for stdint.h and hxtDeclareAligned32 only
#include <float.h>

// the fourth member is unused...
typedef struct hxtBboxStruct{
  double hxtDeclareAligned32 min[3];
  uint64_t pad_u64; // padding U can use however you want
  double hxtDeclareAligned32 max[3];
  double pad_double; // padding U can use however you want
} HXTBbox;

static inline void hxtBboxInit(HXTBbox* bbox){
  bbox->min[0] = DBL_MAX;
  bbox->min[1] = DBL_MAX;
  bbox->min[2] = DBL_MAX;
  bbox->max[0] = -DBL_MAX;
  bbox->max[1] = -DBL_MAX;
  bbox->max[2] = -DBL_MAX;
}

static inline void hxtBboxFrom(HXTBbox* bbox,
                               double* coord)
{
  for (unsigned i=0; i<3; i++)
  {
    bbox->min[i] = coord[i];
    bbox->max[i] = coord[i];
  }
}

/* update the bounding box with one new vertex */
static inline void hxtBboxAddOne(HXTBbox* bbox,
                                 double* coord)
{
  for (unsigned i=0; i<3; i++)
  {
    if(coord[i]<bbox->min[i])
      bbox->min[i] = coord[i];
    if(coord[i]>bbox->max[i])
      bbox->max[i] = coord[i];
  }
}

/* update the bounding box with an array of n vertices at once (far quicker) */
void hxtBboxAdd(HXTBbox* bbox, double* coord, const uint32_t n);

static inline int hxtBboxesIntersect(HXTBbox* bb0, HXTBbox* bb1) {
  if(bb0->min[0] > bb1->max[0] ||
     bb0->min[1] > bb1->max[1] ||
     bb0->min[2] > bb1->max[2] ||
     bb0->max[0] < bb1->min[0] ||
     bb0->max[1] < bb1->min[1] ||
     bb0->max[2] < bb1->min[2])
    return 0;
  return 1;
}

/* merge two bbox  (result can be a pointer to bbox1 or bbox2) */
// void hxtBboxMerge(HXTBbox* bbox1, HXTBbox* bbox2, HXTBbox* bboxResult);

#ifdef __cplusplus
}
#endif

#endif
