#ifndef  __LINKERN_H
#define  __LINKERN_H

#include "util.h"

#ifdef CC_PROTOTYPE_ANSI

int
    CClinkern_tour (int ncount, CCdatagroup *dat, int ecount,
            int *elist, int stallcount, int repeatcount, int *incycle,
            int *outcycle, double *val, int run_silently, double time_bound,
            double length_bound, char *saveit_name);

#else

int
    CClinkern_tour ();

#endif



/***************************************************************************/
/*                                                                         */
/* Must define exactly one of:                                             */
/*                                                                         */
/*          CC_LINKED_LIST_FLIPPER       (flip_llX)                        */
/*          CC_ARRAY_FLIPPER             (flip_ary)                        */
/*          CC_TWO_LEVEL_FLIPPER         (flip_two)                        */
/*          CC_SEGMENTS_FLIPPER          (flip_sg1)                        */
/*          CC_NO_UNDO_SEGMENTS_FLIPPER  (flip_sg2)                        */
/*          CC_FULL_SEGMENTS_FLIPPER     (flip_sg3)                        */
/*          CC_SPLAY_FLIPPER             (flip_sp2)                        */
/*          CC_BTREE_FLIPPER             (flip_btr)                        */
/*                                                                         */
/* NOTE: If MARK_NEIGHBORS is not defined in linkern.c, then               */
/*       NO_UNDO_SEGMENTS may follow a different improving sequence then   */
/*       the other flippers, since the next and prevs in turn () will be   */
/*       with respect to an out-of-date-tour.                              */
/*                                                                         */
/***************************************************************************/


#define CC_TWO_LEVEL_FLIPPER
/* #define BTREE_FLIPPER */

#ifdef CC_LINKED_LIST_FLIPPER
#define CC_EXTRA_INFO_FLIP
#endif

#ifdef CC_ARRAY_FLIPPER
#define CC_USE_FLIP_CLEANING
#endif

#ifdef CC_TWO_LEVEL_FLIPPER
#define CC_USE_FLIP_CLEANING
#endif

#ifdef CC_NO_UNDO_SEGMENTS_FLIPPER
#define CC_USE_FLIP_CLEANING
#define CC_USE_QUICK_FLIPS
#endif

#ifdef CC_FULL_SEGMENTS_FLIPPER
#define CC_USE_FLIP_CLEANING
#endif

#ifdef CC_SPLAY_FLIPPER
#define CC_USE_FLIP_CLEANING
#define CC_EXTRA_INFO_FLIP
#endif

#ifdef CC_BTREE_FLIPPER
#define CC_USE_FLIP_CLEANING
#define CC_EXTRA_INFO_FLIP
#endif

#ifdef CC_PROTOTYPE_ANSI

int
    CClinkern_flipper_init (int ncount, int *cyc),
    CClinkern_flipper_reset_perm (int ncount),
    CClinkern_flipper_reset_temp (int ncount),
    CClinkern_flipper_next (int x),
    CClinkern_flipper_prev (int x),
    CClinkern_flipper_cycle (int *x),
    CClinkern_flipper_sequence_burst (int x, int y, int z),
    CClinkern_flipper_sequence (int x, int y, int z);

void
#ifdef CC_EXTRA_INFO_FLIP
    CClinkern_flipper_flip (int xprev, int x, int y, int ynext),
#else
    CClinkern_flipper_flip (int x, int y),
#endif
    CClinkern_flipper_flip_quick (int x, int y),
    CClinkern_flipper_flip_perm (int x, int y),
    CClinkern_flipper_sequence_burst_init (int x, int z),
    CClinkern_flipper_finish (void),
    CClinkern_flipper_free_world (void);

#else

int
    CClinkern_flipper_init (),
    CClinkern_flipper_reset_perm (),
    CClinkern_flipper_reset_temp (),
    CClinkern_flipper_next (),
    CClinkern_flipper_prev (),
    CClinkern_flipper_cycle (),
    CClinkern_flipper_sequence_burst (),
    CClinkern_flipper_sequence ();

void
    CClinkern_flipper_flip (),
    CClinkern_flipper_flip_quick (),
    CClinkern_flipper_flip_perm (),
    CClinkern_flipper_sequence_burst_init (),
    CClinkern_flipper_finish (),
    CClinkern_flipper_free_world ();

#endif

#endif  /* __LINKERN_H */
