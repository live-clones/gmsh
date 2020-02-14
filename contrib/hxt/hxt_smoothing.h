#ifndef _HXT_SMOOTHING_
#define _HXT_SMOOTHING_

#ifdef __cplusplus
extern "C" {
#endif

#include "hxt_tetSync.h"
#include "hxt_tetPartition.h"
#include "hxt_tetQuality.h"
#include "hxt_tetOptiDate.h"

typedef struct {
  HXTMesh *mesh;
  HXTDeleted* deleted;
  HXTPartition* partition;
  HXTTetQualities* quality;
  HXTTetDates* date;
  uint32_t numVerticesConstrained;
} HXTSmoothingData;


/* return internal error (that you must catch) if:
 *    - the cavity overlap different partitions  => HXT_STATUS_CONFLICT
 *    - there is a contraint inside the cavity   => HXT_STATUS_CONSTRAINT
 *    - does'nt result in a better triangulation => HXT_STATUS_NOTBETTER
 * a facet without neighbor (set to HXT_NO_ADJACENT) is also a constraint
 * a node n with n<numVerticesConstrained has its position constrained
 */
HXTStatus hxtSmoothing(HXTSmoothingData* data,
                       uint64_t oppositeFacet);


#ifdef __cplusplus
}
#endif

#endif