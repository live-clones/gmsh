/***************************************************************************/
/*                                                                         */
/*       TOUR MAINTANENCE ROUTINES FOR LIN-KERNIGHAN - Basic Array         */
/*                                                                         */
/*                             TSP CODE                                    */
/*                                                                         */
/*                                                                         */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook                       */
/*  Date: April 21, 1995 (but mainly from March, 1990)                     */
/*                                                                         */
/*                                                                         */
/* EXPORTED FUNCTIONS:                                                     */
/*   int CClinkern_flipper_init (int ncount, int *cyc)                     */
/*     initializes flipper1 to an initial cycle given in cyc.              */
/*     returns 0 on success, nonzero on failure.                           */
/*   int CClinkern_flipper_cycle (int *p)                                  */
/*     places the current cycle in p.                                      */
/*     returns the number of segments in current representation.           */
/*   void CClinkern_flipper_finish (void)                                  */
/*     frees up temporary space allocated by CClinkern_flipper_init.       */
/*     every flipper_init should lead to a flipper_finish call.            */
/*   void CClinkern_flipper_free_world (void)                              */
/*     frees up all remaining space (including ptrs)                       */
/*     should be called when we are finished with linkern                  */
/*   int CClinkern_flipper_next (int x)                                    */
/*     returns the successor to x in the current cycle.                    */
/*   int CClinkern_flipper_prev (int x)                                    */
/*     returns the predecessor of x in the current cycle.                  */
/*   void CClinkern_flipper_flip (int x, int y)                            */
/*     flips the portion of the cycle from x to y (inclusive).             */
/*   int CClinkern_flipper_sequence (int * x, int y, int z)                */
/*     returns 1 if xyz occur as an increasing subsequence of the cycle,   */
/*     returns 0 otherwise.                                                */
/*                                                                         */
/* NOTES:                                                                  */
/*       This version uses very little memory, and is reasonably fast      */
/*   for small problems and for twoopts (but you should have SHORT_SIDE    */
/*   defined so that the smaller side a flip is carried out.               */
/*                                                                         */
/***************************************************************************/

#include "machdefs.h"
#include "util.h"

#define SHORT_SIDE

/***************************************************************************/
/*                                                                         */
/* ARRAY FLIPPER (flipper2):                                               */
/*                                                                         */
/*     1. Uses a raw cycle and its inverse.                                */
/*                                                                         */
/***************************************************************************/

/***************************************************************************/
/*                                                                         */
/* SHORT-SIDE-ARRAY FLIPPER (flipper3):                                    */
/*                                                                         */
/*     1. Uses a raw cycle and its inverse, but flips the shorter side.    */
/*                                                                         */
/*     2. Define SHORT_SIDE to use this.                                   */
/*                                                                         */
/***************************************************************************/


#define SWAP(a, b, t) ((t) = (a), (a) = (b), (b) = (t))

static int cycle_size = 0;
#ifdef SHORT_SIDE
static int reversed = 0;
static int short_size = 0;
#endif
static int *flip3_cyc = (int *) NULL;
static int *flip3_cyc_inv = (int *) NULL;

#ifdef WE_WANT_FLIP_STATS
int CClinkern_flipper_size (int a, int b);
#endif WE_WANT_FLIP_STATS

#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_reset (int ncount)
#else
int CClinkern_flipper_reset (ncount)
int ncount;
#endif
{
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_init (int ncount, int *cyc)
#else
int CClinkern_flipper_init (ncount, cyc)
int ncount;
int *cyc;
#endif
{
    int i;

    flip3_cyc = CC_SAFE_MALLOC (ncount, int);
    if (!flip3_cyc)
        return 1;
    flip3_cyc_inv = CC_SAFE_MALLOC (ncount, int);
    if (!flip3_cyc_inv) {
        CC_FREE (cyc, int);
        return 1;
    }

    for (i = 0; i < ncount; i++) {
        flip3_cyc[i] = cyc[i];
        flip3_cyc_inv[cyc[i]] = i;
    }
    cycle_size = ncount;
#ifdef SHORT_SIDE
    short_size = ncount/2;
    reversed = 0;
#endif
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_cycle (int *x)
#else
int CClinkern_flipper_cycle (x)
int *x;
#endif
{
    int *p;

#ifdef SHORT_SIDE
    if (reversed) {
        p = flip3_cyc + cycle_size;
        while (p > flip3_cyc) {
            *x++ = *--p;
        }
    } else {
#endif
        p = flip3_cyc + cycle_size;
        x += cycle_size;
        while (p > flip3_cyc) {
            *--x = *--p;
        }
#ifdef SHORT_SIDE
    }
#endif

    return cycle_size;
}

#ifdef CC_PROTOTYPE_ANSI
void CClinkern_flipper_finish (void)
#else
void CClinkern_flipper_finish ()
#endif
{
    CC_FREE (flip3_cyc, int);
    CC_FREE (flip3_cyc_inv, int);
    cycle_size = 0;
#ifdef SHORT_SIDE
    short_size = 0;
    reversed = 0;
#endif
}

#ifdef CC_PROTOTYPE_ANSI
void CClinkern_flipper_free_world (void)
#else
void CClinkern_flipper_free_world ()
#endif
{
    return;
}

#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_next (int x)
#else
int CClinkern_flipper_next (x)
int x;
#endif
{
    int y;

#ifdef SHORT_SIDE
    if (reversed) {
        y = flip3_cyc_inv[x] - 1;
        return (y >= 0) ? flip3_cyc[y] : flip3_cyc[cycle_size-1];
    } else {
#endif
        y = flip3_cyc_inv[x] + 1;
        return (y < cycle_size) ? flip3_cyc[y] : flip3_cyc[0];
#ifdef SHORT_SIDE
    }
#endif
}

#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_prev (int x)
#else
int CClinkern_flipper_prev (x)
int x;
#endif
{
    int y;

#ifdef SHORT_SIDE
    if (reversed) {
        y = flip3_cyc_inv[x] + 1;
        return (y < cycle_size) ? flip3_cyc[y] : flip3_cyc[0];
    } else {
#endif
        y = flip3_cyc_inv[x] - 1;
        return (y >= 0) ? flip3_cyc[y] : flip3_cyc[cycle_size-1];
#ifdef SHORT_SIDE
    }
#endif
}

#ifdef CC_PROTOTYPE_ANSI
void CClinkern_flipper_flip (int x, int y)
#else
void CClinkern_flipper_flip (x, y)
int x,y;
#endif
{
    int xloc = flip3_cyc_inv[x];
    int yloc = flip3_cyc_inv[y];
    int temp;
    int gap;

#ifdef SHORT_SIDE
    if (reversed) {
        SWAP (xloc, yloc, temp);
    }
    gap = yloc - xloc;
    if (gap < 0) gap += cycle_size;
    if (gap > short_size) {
        SWAP (xloc, yloc, temp);
        reversed ^= 1;
        xloc++;
        if (xloc >= cycle_size)
            xloc = 0;
        yloc--;
        if (yloc < 0)
            yloc = cycle_size - 1;
        gap = cycle_size - gap - 2;
    }

    if (xloc > yloc) {
        gap++;
        gap /= 2;
        for (; gap; gap--) {
            x = flip3_cyc[xloc];
            y = flip3_cyc[yloc];
            flip3_cyc[xloc] = y;
            flip3_cyc[yloc] = x;
            flip3_cyc_inv[x] = yloc--;
            flip3_cyc_inv[y] = xloc++;
            if (xloc >= cycle_size)
                xloc = 0;
            if (yloc < 0)
                yloc = cycle_size - 1;
        }
    } else {
        gap++;
        gap /= 2;
        for (; gap; gap--) {
            x = flip3_cyc[xloc];
            y = flip3_cyc[yloc];
            flip3_cyc[xloc] = y;
            flip3_cyc[yloc] = x;
            flip3_cyc_inv[x] = yloc--;
            flip3_cyc_inv[y] = xloc++;
        }
    }
#else
    if (xloc > yloc) {
        gap = yloc - xloc + cycle_size;
        gap++;
        gap /= 2;
        for (; gap; gap--) {
            x = flip3_cyc[xloc];
            y = flip3_cyc[yloc];
            flip3_cyc[xloc] = y;
            flip3_cyc[yloc] = x;
            flip3_cyc_inv[x] = yloc--;
            flip3_cyc_inv[y] = xloc++;
            if (xloc >= cycle_size)
                xloc = 0;
            if (yloc < 0)
                yloc = cycle_size - 1;
        }
    } else {
        gap = yloc - xloc;
        gap++;
        gap /= 2;
        for (; gap; gap--) {
            x = flip3_cyc[xloc];
            y = flip3_cyc[yloc];
            flip3_cyc[xloc] = y;
            flip3_cyc[yloc] = x;
            flip3_cyc_inv[x] = yloc--;
            flip3_cyc_inv[y] = xloc++;
        }
    }
#endif
}

#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_sequence (int x, int y, int z)
#else
int CClinkern_flipper_sequence (x, y, z)
int x, y, z;
#endif
{
    int xloc = flip3_cyc_inv[x];
    int yloc = flip3_cyc_inv[y];
    int zloc = flip3_cyc_inv[z];

#ifdef SHORT_SIDE
    if (reversed) {
        if (xloc >= yloc)
            return yloc >= zloc || zloc >= xloc;
        else
            return yloc >= zloc && zloc >= xloc;
    } else {
#endif
        if (xloc <= yloc)
            return yloc <= zloc || zloc <= xloc;
        else
            return yloc <= zloc && zloc <= xloc;
#ifdef SHORT_SIDE
    }
#endif
}

#ifdef WE_WANT_FLIP_STATS
#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_size (int x, int y)
#else
int CClinkern_flipper_size (x, y)
int x,y;
#endif
{
    int xloc = flip3_cyc_inv[x];
    int yloc = flip3_cyc_inv[y];
    int temp, gap;

    if (reversed) {
        SWAP (xloc, yloc, temp);
    }
    gap = yloc - xloc;
    if (gap < 0) gap += cycle_size;
    if (gap > short_size) {
        gap = cycle_size - gap - 2;
    }

    return gap + 1;
}
#endif /* WE_WANT_FLIP_STATS */

