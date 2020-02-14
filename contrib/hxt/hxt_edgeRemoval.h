#ifndef _HXT_EDGEREMOVAL_
#define _HXT_EDGEREMOVAL_

#include "hxt_tetSync.h"
#include "hxt_tetPartition.h"
#include "hxt_tetQuality.h"
#include "hxt_tetOptiDate.h"

#define HXT_EDGE_REMOVAL_MAX 7 // you cannot increase it above 7 ATM

typedef struct { // bipyramidal cavity for the edge-removal
    uint64_t neigh_up  [HXT_EDGE_REMOVAL_MAX];
    uint64_t neigh_down[HXT_EDGE_REMOVAL_MAX];
    uint16_t flag      [HXT_EDGE_REMOVAL_MAX];
    uint32_t annulus   [HXT_EDGE_REMOVAL_MAX];
    uint32_t v_up;
    uint32_t v_down;
    uint32_t num;
} HXTBipyramid;


typedef struct {
  HXTBipyramid cavity; // bipyramid cavity is specific to edge removal, that's why it is not a ptr
  HXTDeleted* deleted;
  HXTPartition* partition;
  HXTTetQualities* quality;
  HXTTetDates* date;
  HXT2Sync* toSync;
} HXTEdgeRemovalData;


/* return internal error (that you must catch) if:
 *    - the cavity overlap different partitions  => HXT_STATUS_CONFLICT
 *    - there is a contraint inside the cavity   => HXT_STATUS_CONSTRAINT
 *    - does'nt result in a better triangulation => HXT_STATUS_NOTBETTER
 *    - there is more than 7 pts around the edge => HXT_STATUS_INTERNAL
 * a facet without neighbor (set to HXT_NO_ADJACENT) is also a constraint.
 */
HXTStatus hxtEdgeRemoval_opti(HXTEdgeRemovalData* data,
                              uint64_t badTet,
                              unsigned edgeID);

#endif