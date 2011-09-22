/***************************************************************************/
/*                                                                         */
/* TOUR MAINTANENCE ROUTINES FOR LIN-KERNIGHAN - Linked Lists (fwd & bwd)  */
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
/*       Like flip_ll4, but with fwd and bwd pointers.                     */
/*                                                                         */
/***************************************************************************/

#include "machdefs.h"
#include "util.h"

/***************************************************************************/
/*                                                                         */
/* LINKDED LIST FLIPPER 5  (flip_ll5.c):                                   */
/*                                                                         */
/*     1. Same as flip_ll4, but fwd and bwd are now pointers.              */
/*     2. The code is easier, and flips should be faster, but the hunts    */
/*        should be slower(?).                                             */
/*                                                                         */
/***************************************************************************/

#define SWAP(a, b, t) ((t) = (a), (a) = (b), (b) = (t))
#define FORWARD_TOUR  0
#define BACKWARD_TOUR 1

typedef struct oneway {
    struct oneway *next;
    int            name;
    char           dir;
    char           orient;
    char           mark;
    char           express;
} oneway;

typedef struct llnode {
    struct oneway  actual_fwd;
    struct oneway  actual_bwd;
    struct oneway  *fwd;
    struct oneway  *bwd;
    struct llnode  *next_express;
    struct llnode  *prev_express;
} llnode;

#ifdef CC_PROTOTYPE_ANSI

static int
    find_orientation (int s);

#else

static int
    find_orientation ();

#endif

static llnode *lltour = (llnode *) NULL;
static llnode *orientnodes[2];
static cycle_size = 0;


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

    lltour[cyc[0]].actual_fwd.name = cyc[0];
    lltour[cyc[0]].actual_fwd.mark = 0;
    lltour[cyc[0]].actual_fwd.dir = FORWARD_TOUR;
    lltour[cyc[0]].actual_fwd.orient = 0;
    lltour[cyc[0]].actual_fwd.express = 0;
    lltour[cyc[0]].actual_fwd.next = &(lltour[cyc[1]].actual_fwd);
    lltour[cyc[0]].fwd = &(lltour[cyc[0]].actual_fwd);
    lltour[cyc[0]].actual_bwd.name = cyc[0];
    lltour[cyc[0]].actual_bwd.mark = 0;
    lltour[cyc[0]].actual_bwd.dir = BACKWARD_TOUR;
    lltour[cyc[0]].actual_bwd.orient = 0;
    lltour[cyc[0]].actual_bwd.express = 0;
    lltour[cyc[0]].actual_bwd.next = &(lltour[cyc[ncount - 1]].actual_bwd);
    lltour[cyc[0]].bwd = &(lltour[cyc[0]].actual_bwd);
    lltour[cyc[ncount - 1]].actual_fwd.name = cyc[ncount - 1];
    lltour[cyc[ncount - 1]].actual_fwd.mark = 0;
    lltour[cyc[ncount - 1]].actual_fwd.dir = FORWARD_TOUR;
    lltour[cyc[ncount - 1]].actual_fwd.orient = 0;
    lltour[cyc[ncount - 1]].actual_fwd.express = 0;
    lltour[cyc[ncount - 1]].actual_fwd.next = &(lltour[cyc[0]].actual_fwd);
    lltour[cyc[ncount - 1]].fwd = &(lltour[cyc[ncount - 1]].actual_fwd);
    lltour[cyc[ncount - 1]].actual_bwd.name = cyc[ncount - 1];
    lltour[cyc[ncount - 1]].actual_bwd.mark = 0;
    lltour[cyc[ncount - 1]].actual_bwd.dir = BACKWARD_TOUR;
    lltour[cyc[ncount - 1]].actual_bwd.orient = 0;
    lltour[cyc[ncount - 1]].actual_bwd.express = 0;
    lltour[cyc[ncount - 1]].actual_bwd.next =
                        &(lltour[cyc[ncount - 2]].actual_bwd);
    lltour[cyc[ncount - 1]].bwd = &(lltour[cyc[ncount - 1]].actual_bwd);


    for (i = ncount - 2; i; i--) {
        lltour[cyc[i]].actual_fwd.name = cyc[i];
        lltour[cyc[i]].actual_fwd.mark = 0;
        lltour[cyc[i]].actual_fwd.dir = FORWARD_TOUR;
        lltour[cyc[i]].actual_fwd.orient = 0;
        lltour[cyc[i]].actual_fwd.express = 0;
        lltour[cyc[i]].actual_fwd.next = &(lltour[cyc[i + 1]].actual_fwd);
        lltour[cyc[i]].fwd = &(lltour[cyc[i]].actual_fwd);
        lltour[cyc[i]].actual_bwd.name = cyc[i];
        lltour[cyc[i]].actual_bwd.mark = 0;
        lltour[cyc[i]].actual_bwd.dir = BACKWARD_TOUR;
        lltour[cyc[i]].actual_bwd.orient = 0;
        lltour[cyc[i]].actual_bwd.express = 0;
        lltour[cyc[i]].actual_bwd.next = &(lltour[cyc[i - 1]].actual_bwd);
        lltour[cyc[i]].bwd = &(lltour[cyc[i]].actual_bwd);
    }
    orientnodes[0] = &(lltour[cyc[0]]);
    orientnodes[1] = &(lltour[cyc[ncount/2]]);
    lltour[cyc[0]].fwd->orient = 1;
    lltour[cyc[0]].bwd->orient = 1;
    lltour[cyc[ncount/2]].fwd->orient = 1;
    lltour[cyc[ncount/2]].bwd->orient = 1;

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int find_orientation (int s)
#else
static int find_orientation (s)
int s;
#endif
{
    /* Returns 0 if next is fwd and 1 if next is bwd */

    oneway *n = lltour[s].fwd;

    while (!n->orient)
        n = n->next;

    return (n != lltour[n->name].fwd);
}

#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_cycle (int *x)
#else
int CClinkern_flipper_cycle (x)
int *x;
#endif
{
    oneway *start, *n;
    int k = 0;

    start = (find_orientation (0) ? lltour[0].bwd : lltour[0].fwd);
    n = start;
    do {
        x[k++] = n->name;
        n = n->next;
    } while (n != start);

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
    if (find_orientation (x))
        return lltour[x].bwd->next->name;
    else
        return lltour[x].fwd->next->name;
}

#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_prev (int x)
#else
int CClinkern_flipper_prev (x)
int x;
#endif
{
    if (find_orientation (x))
        return lltour[x].fwd->next->name;
    else
        return lltour[x].bwd->next->name;
}

#ifdef CC_PROTOTYPE_ANSI
void CClinkern_flipper_flip (int xprev, int x, int y, int ynext)
#else
void CClinkern_flipper_flip (xprev, x, y, ynext)
int xprev, x, y, ynext;
#endif
{
    int xnext, yprev;
    oneway *otemp;

    if (x == y)
        return;

    orientnodes[0]->fwd->orient = 0;
    orientnodes[0]->bwd->orient = 0;
    orientnodes[1]->fwd->orient = 0;
    orientnodes[1]->bwd->orient = 0;
    orientnodes[0] = &(lltour[x]);
    orientnodes[1] = &(lltour[y]);
    orientnodes[0]->fwd->orient = 1;
    orientnodes[0]->bwd->orient = 1;
    orientnodes[1]->fwd->orient = 1;
    orientnodes[1]->bwd->orient = 1;

    if (lltour[x].bwd->next->name == xprev)
        xnext = lltour[x].fwd->next->name;
    else
        xnext = lltour[x].bwd->next->name;

    if (lltour[y].bwd->next->name == ynext)
        yprev = lltour[y].fwd->next->name;
    else
        yprev = lltour[y].bwd->next->name;

    if (xprev == y) {
        if (lltour[x].fwd->next->name != y) {
            SWAP (lltour[x].fwd, lltour[x].bwd, otemp);
        }
        if (lltour[y].bwd->next->name != x) {
            SWAP (lltour[y].fwd, lltour[y].bwd, otemp);
        }
    } else {
        if (lltour[x].bwd->next->name == xprev) {
            SWAP (lltour[x].fwd, lltour[x].bwd, otemp);
        }
        if (lltour[y].fwd->next->name == ynext) {
            SWAP (lltour[y].fwd, lltour[y].bwd, otemp);
        }
        if (xprev == ynext) {
            if (lltour[ynext].fwd->next->name == y) {
                lltour[y].bwd->next = lltour[ynext].bwd;
                lltour[x].fwd->next = lltour[ynext].fwd;
            } else {
                lltour[y].bwd->next = lltour[ynext].fwd;
                lltour[x].fwd->next = lltour[ynext].bwd;
            }
        } else {
            if (lltour[ynext].fwd->next->name == y) {
                lltour[x].fwd->next = lltour[ynext].bwd;
                lltour[ynext].fwd->next = lltour[x].bwd;
            } else {
                lltour[x].fwd->next = lltour[ynext].fwd;
                lltour[ynext].bwd->next = lltour[x].bwd;
            }

            if (lltour[xprev].fwd->next->name == x) {
                lltour[y].bwd->next = lltour[xprev].bwd;
                lltour[xprev].fwd->next = lltour[y].fwd;
            } else {
                lltour[y].bwd->next = lltour[xprev].fwd;
                lltour[xprev].bwd->next = lltour[y].fwd;
            }
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
    oneway *n;

    if (x == z || x == y) {
        return 1;
    } else {
        lltour[y].fwd->mark = 1;
        lltour[y].bwd->mark = 1;
        lltour[z].fwd->mark = 1;
        lltour[z].bwd->mark = 1;

        if (find_orientation (x))
            n = lltour[x].bwd;
        else
            n = lltour[x].fwd;

        while (!n->mark) {
            n = n->next;
        }
        lltour[y].fwd->mark = 0;
        lltour[y].bwd->mark = 0;
        lltour[z].fwd->mark = 0;
        lltour[z].bwd->mark = 0;

        return (n->name == y);
    }
}
