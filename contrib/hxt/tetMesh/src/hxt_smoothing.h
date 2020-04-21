// Hxt - Copyright (C) 
// 2016 - 2020 UCLouvain
//
// See the LICENSE.txt file for license information.
//
// Contributor(s):
//   Célestin Marot

#ifndef HXT_SMOOTHING_H
#define HXT_SMOOTHING_H

#ifdef __cplusplus
extern "C" {
#endif

#include "hxt_tetOptiUtils.h"

/* return internal error (that you must catch) if:
 *    - the cavity overlap different partitions  => HXT_STATUS_CONFLICT
 *    - there is a contraint inside the cavity   => HXT_STATUS_CONSTRAINT
 *    - does'nt result in a better triangulation => HXT_STATUS_INTERNAL
 * a facet without neighbor (set to HXT_NO_ADJACENT) is also a constraint
 * a node n with n<numVerticesConstrained has its position constrained
 */
HXTStatus hxtSmoothing(ThreadLocal* local,
                       uint64_t oppositeFacet);


#ifdef __cplusplus
}
#endif

#endif