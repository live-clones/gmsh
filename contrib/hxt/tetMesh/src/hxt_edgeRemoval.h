// Hxt - Copyright (C) 
// 2016 - 2020 UCLouvain
//
// See the LICENSE.txt file for license information.
//
// Contributor(s):
//   Célestin Marot

#ifndef HXT_EDGEREMOVAL_H
#define HXT_EDGEREMOVAL_H

#include "hxt_tetOptiUtils.h"


/* return internal error (that you must catch) if:
 *    - the cavity overlap different partitions  => HXT_STATUS_CONFLICT
 *    - there is a constraint inside the cavity   => HXT_STATUS_CONSTRAINT
 *    - doesn't result in a better triangulation => HXT_STATUS_NOTBETTER
 *    - there is more than 7 pts around the edge => HXT_STATUS_INTERNAL
 * a facet without neighbor (set to HXT_NO_ADJACENT) is also a constraint.
 */
HXTStatus hxtEdgeRemoval_opti(ThreadLocal* local,
                              uint64_t badTet,
                              unsigned edgeID);

#endif