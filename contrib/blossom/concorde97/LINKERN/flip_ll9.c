/***************************************************************************/
/*                                                                         */
/* TOUR MAINTANENCE ROUTINES FOR LIN-KERNIGHAN - Basic Linked List w/ Rev  */
/*                                             - USES INDEX                */
/*                                                                         */
/*                             TSP CODE                                    */
/*                                                                         */
/*                                                                         */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook                       */
/*  Date: May 22, 1995                                                     */
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
/*   void CClinkern_flipper_flip (int xprev, int x, int y, int ynext)      */
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

/***************************************************************************/
/*                                                                         */
/* LINKDED LIST FLIPPER 0  (flip_ll0.c):  ADDS INDEX                       */
/*                                                                         */
/*     1. Uses linked list with known prev and next.                       */
/*     2. Tour reversal bit.                                               */
/*     2. Next and prev given explicitly.                                  */
/*                                                                         */
/***************************************************************************/

#define SWAP(a, b, t) ((t) = (a), (a) = (b), (b) = (t))

typedef struct llnode {
    struct llnode *next;
    struct llnode *prev;
    int            name;
    int            mark;
    int            index;
} llnode;

static llnode *lltour = (llnode *) NULL;
static cycle_size = 0;
static int reversed = 0;

#ifdef CC_PROTOTYPE_ANSI
static void
    flipper_flip_work (int xprev, int x, int y, int ynext);
#else
static void
    flipper_flip_work ();
#endif

#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_init (int ncount, int *cyc)
#else
int CClinkern_flipper_init (ncount, cyc)
int ncount;
int *cyc;
#endif
{
    int i;

    cycle_size = ncount;
    lltour = CC_SAFE_MALLOC (ncount, llnode);
    if (!lltour)
        return 1;

    reversed = 0;
    lltour[cyc[0]].name = cyc[0];
    lltour[cyc[0]].mark = 0;
    lltour[cyc[0]].next = &(lltour[cyc[1]]);
    lltour[cyc[0]].prev = &(lltour[cyc[ncount - 1]]);
    lltour[cyc[0]].index = 0;
    lltour[cyc[ncount - 1]].name = cyc[ncount - 1];
    lltour[cyc[ncount - 1]].mark = 0;
    lltour[cyc[ncount - 1]].next = &(lltour[cyc[0]]);
    lltour[cyc[ncount - 1]].prev = &(lltour[cyc[ncount - 2]]);
    lltour[cyc[ncount - 1]].index = ncount - 1;

    for (i = ncount - 2; i; i--) {
        lltour[cyc[i]].name = cyc[i];
        lltour[cyc[i]].mark = 0;
        lltour[cyc[i]].next = &(lltour[cyc[i + 1]]);
        lltour[cyc[i]].prev = &(lltour[cyc[i - 1]]);
        lltour[cyc[i]].index = i;
    }

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_cycle (int *x)
#else
int CClinkern_flipper_cycle (x)
int *x;
#endif
{
    llnode *n, *start;
    int k = 0;

    n = start = &(lltour[0]);

    if (reversed) {
        do {
            x[k++] = n->name;
            n = n->prev;
        } while (n != start && k < cycle_size);
    } else {
        do {
            x[k++] = n->name;
            n = n->next;
        } while (n != start && k < cycle_size);
    }

    return cycle_size;
}

#ifdef CC_PROTOTYPE_ANSI
void CClinkern_flipper_finish (void)
#else
void CClinkern_flipper_finish ()
#endif
{
    if (lltour)
        CC_FREE (lltour, llnode);
}


#ifdef CC_PROTOTYPE_ANSI
void CClinkern_flipper_free_world (void)
#else
void CClinkern_flipper_free_world ()
#endif
{
}

#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_next (int x)
#else
int CClinkern_flipper_next (x)
int x;
#endif
{
    if (reversed)
        return lltour[x].prev->name;
    else
        return lltour[x].next->name;
}

#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_prev (int x)
#else
int CClinkern_flipper_prev (x)
int x;
#endif
{
    if (reversed)
        return lltour[x].next->name;
    else
        return lltour[x].prev->name;
}

#ifdef CC_PROTOTYPE_ANSI
void CClinkern_flipper_flip (int xprev, int x, int y, int ynext)
#else
void CClinkern_flipper_flip (xprev, x, y, ynext)
int xprev, x, y, ynext;
#endif
{
    int side;

    if (reversed)
        side = lltour[x].index - lltour[y].index;
    else
        side = lltour[y].index - lltour[x].index;
    if (side < 0)
        side += cycle_size;

    if (side < cycle_size / 2)
         flipper_flip_work (xprev, x, y, ynext);
    else {
         flipper_flip_work (y, ynext, xprev, x);
         reversed ^= 1;
    }
}


#ifdef CC_PROTOTYPE_ANSI
static void flipper_flip_work (int xprev, int x, int y, int ynext)
#else
static void flipper_flip_work (xprev, x, y, ynext)
int xprev, x, y, ynext;
#endif
{
    llnode *nxprev = &(lltour[xprev]);
    llnode *nynext = &(lltour[ynext]);
    llnode *nx = &(lltour[x]);
    llnode *ny = &(lltour[y]);
    llnode *n, *next;
    int id = lltour[x].index;

    if (x == y)
        return;

    if (reversed) {
        n = ny->next;
        ny->next = ny->prev;
        ny->prev = n;
        ny->index = id--;
        while (n != nx) {
            next = n->next;
            n->next = n->prev;
            n->prev = next;
            n->index = id--;
            n = next;
        }
        next = nx->next;
        nx->next = nx->prev;
        nx->prev = next;
        nx->index = id;
        if (nxprev != ny) {
            ny->next = nxprev;
            nx->prev = nynext;
            nxprev->prev = ny;
            nynext->next = nx;
        }
    } else {
        n = ny->prev;
        ny->prev = ny->next;
        ny->next = n;
        ny->index = id++;
        while (n != nx) {
            next = n->prev;
            n->prev = n->next;
            n->next = next;
            n->index = id++;
            n = next;
        }
        next = nx->prev;
        nx->prev = nx->next;
        nx->next = next;
        nx->index = id;
        if (nxprev != ny) {
            ny->prev = nxprev;
            nx->next = nynext;
            nxprev->next = ny;
            nynext->prev = nx;
        }
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_sequence (int x, int y, int z)
#else
int CClinkern_flipper_sequence (x, y, z)
int x, y, z;
#endif
{
    int a = lltour[x].index;
    int b = lltour[y].index;
    int c = lltour[z].index;

    if (reversed) {
        if (a >= b)
            return (b >= c || c >= a);
        else
            return (b >= c && c >= a);
    } else {
        if (a <= b)
            return (b <= c || c <= a);
        else
            return (b <= c && c <= a);
    }
}
