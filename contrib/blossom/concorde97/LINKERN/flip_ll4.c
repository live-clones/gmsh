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
/*       This version should be slow, since next and prev have to          */
/*   hunt down an orientation node (since each node knows its neighbors    */
/*   but not the direction), like flip_ll3, but the two copies of the tour */
/*   (one in each direction) lets us avoid lost of if tests during the     */
/*   hunt.                                                                 */
/*                                                                         */
/***************************************************************************/

#include "machdefs.h"
#include "util.h"

/***************************************************************************/
/*                                                                         */
/* LINKDED LIST FLIPPER 4  (flip_ll4.c):                                   */
/*                                                                         */
/*     1. Uses two linked lists (forward and backward)                     */
/*     2. Need to track down a node of known orientation (the extra info   */
/*        in the flips provides this).                                     */
/*     3. The hunt is done by a moving along one of the tours, till we hit */
/*        an orientation node that will tell us if we are on the forward   */
/*        or backward tour.                                                */
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
} oneway;

typedef struct llnode {
    struct oneway  fwd;
    struct oneway  bwd;
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

    lltour[cyc[0]].fwd.name = cyc[0];
    lltour[cyc[0]].fwd.mark = 0;
    lltour[cyc[0]].fwd.dir = FORWARD_TOUR;
    lltour[cyc[0]].fwd.orient = 0;
    lltour[cyc[0]].fwd.next = &(lltour[cyc[1]].fwd);
    lltour[cyc[0]].bwd.name = cyc[0];
    lltour[cyc[0]].bwd.mark = 0;
    lltour[cyc[0]].bwd.dir = BACKWARD_TOUR;
    lltour[cyc[0]].bwd.orient = 0;
    lltour[cyc[0]].bwd.next = &(lltour[cyc[ncount - 1]].bwd);
    lltour[cyc[ncount - 1]].fwd.name = cyc[ncount - 1];
    lltour[cyc[ncount - 1]].fwd.mark = 0;
    lltour[cyc[ncount - 1]].fwd.dir = FORWARD_TOUR;
    lltour[cyc[ncount - 1]].fwd.orient = 0;
    lltour[cyc[ncount - 1]].fwd.next = &(lltour[cyc[0]].fwd);
    lltour[cyc[ncount - 1]].bwd.name = cyc[ncount - 1];
    lltour[cyc[ncount - 1]].bwd.mark = 0;
    lltour[cyc[ncount - 1]].bwd.dir = BACKWARD_TOUR;
    lltour[cyc[ncount - 1]].bwd.orient = 0;
    lltour[cyc[ncount - 1]].bwd.next = &(lltour[cyc[ncount - 2]].bwd);

    for (i = ncount - 2; i; i--) {
        lltour[cyc[i]].fwd.name = cyc[i];
        lltour[cyc[i]].fwd.mark = 0;
        lltour[cyc[i]].fwd.dir = FORWARD_TOUR;
        lltour[cyc[i]].fwd.orient = 0;
        lltour[cyc[i]].fwd.next = &(lltour[cyc[i + 1]].fwd);
        lltour[cyc[i]].bwd.name = cyc[i];
        lltour[cyc[i]].bwd.mark = 0;
        lltour[cyc[i]].bwd.dir = BACKWARD_TOUR;
        lltour[cyc[i]].bwd.orient = 0;
        lltour[cyc[i]].bwd.next = &(lltour[cyc[i - 1]].bwd);
    }
    orientnodes[0] = &(lltour[cyc[0]]);
    orientnodes[1] = &(lltour[cyc[ncount/2]]);
    lltour[cyc[0]].fwd.orient = 1;
    lltour[cyc[0]].bwd.orient = 1;
    lltour[cyc[ncount/2]].fwd.orient = 1;
    lltour[cyc[ncount/2]].bwd.orient = 1;

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

    oneway *n = &(lltour[s].fwd);

    while (!n->orient)
        n = n->next;

    return (n->dir != FORWARD_TOUR);
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

    n = start = (find_orientation (0) ? &(lltour[0].bwd) : &(lltour[0].fwd));
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
        return lltour[x].bwd.next->name;
    else
        return lltour[x].fwd.next->name;
}

#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_prev (int x)
#else
int CClinkern_flipper_prev (x)
int x;
#endif
{
    if (find_orientation (x))
        return lltour[x].fwd.next->name;
    else
        return lltour[x].bwd.next->name;
}

#ifdef CC_PROTOTYPE_ANSI
void CClinkern_flipper_flip (int xprev, int x, int y, int ynext)
#else
void CClinkern_flipper_flip (xprev, x, y, ynext)
int xprev, x, y, ynext;
#endif
{
    int xnext, yprev;

    if (x == y)
        return;

    orientnodes[0]->fwd.orient = 0;
    orientnodes[0]->bwd.orient = 0;
    orientnodes[1]->fwd.orient = 0;
    orientnodes[1]->bwd.orient = 0;
    orientnodes[0] = &(lltour[x]);
    orientnodes[1] = &(lltour[y]);
    orientnodes[0]->fwd.orient = 1;
    orientnodes[0]->bwd.orient = 1;
    orientnodes[1]->fwd.orient = 1;
    orientnodes[1]->bwd.orient = 1;

    if (lltour[x].bwd.next->name == xprev)
        xnext = lltour[x].fwd.next->name;
    else
        xnext = lltour[x].bwd.next->name;

    if (lltour[y].bwd.next->name == ynext)
        yprev = lltour[y].fwd.next->name;
    else
        yprev = lltour[y].bwd.next->name;

    if (xprev == y) {
        if (lltour[xnext].fwd.next->name == x) {
            lltour[xnext].fwd.next = &(lltour[x].fwd);
            lltour[x].bwd.next = &(lltour[xnext].bwd);
        } else {
            lltour[xnext].bwd.next = &(lltour[x].fwd);
            lltour[x].bwd.next = &(lltour[xnext].fwd);
        }

        if (lltour[yprev].fwd.next->name == y) {
            lltour[yprev].fwd.next = &(lltour[y].bwd);
            lltour[y].fwd.next = &(lltour[yprev].bwd);
        } else {
            lltour[yprev].bwd.next = &(lltour[y].bwd);
            lltour[y].fwd.next = &(lltour[yprev].fwd);
        }

        lltour[x].fwd.next = &(lltour[y].fwd);
        lltour[y].bwd.next = &(lltour[x].bwd);
    } else if (xnext == y) {
        if (lltour[xprev].fwd.next->name == x) {
            lltour[xprev].fwd.next = &(lltour[y].fwd);
            lltour[y].bwd.next = &(lltour[xprev].bwd);
        } else {
            lltour[xprev].bwd.next = &(lltour[y].fwd);
            lltour[y].bwd.next = &(lltour[xprev].fwd);
        }

        if (lltour[ynext].bwd.next->name == y) {
            lltour[ynext].bwd.next = &(lltour[x].bwd);
            lltour[x].fwd.next = &(lltour[ynext].fwd);
        } else {
            lltour[ynext].fwd.next = &(lltour[x].bwd);
            lltour[x].fwd.next = &(lltour[ynext].bwd);
        }

        lltour[x].bwd.next = &(lltour[y].bwd);
        lltour[y].fwd.next = &(lltour[x].fwd);
    } else {
        if (xnext == yprev) {
            if (lltour[xnext].bwd.next->name == x) {
                lltour[xnext].bwd.next = &(lltour[x].fwd);
                lltour[x].bwd.next = &(lltour[xnext].fwd);
                lltour[xnext].fwd.next = &(lltour[y].bwd);
                lltour[y].fwd.next = &(lltour[yprev].bwd);
            } else {
                lltour[xnext].fwd.next = &(lltour[x].fwd);
                lltour[x].bwd.next = &(lltour[xnext].bwd);
                lltour[xnext].bwd.next = &(lltour[y].bwd);
                lltour[y].fwd.next = &(lltour[yprev].fwd);
            }
        } else {
            if (lltour[xnext].bwd.next->name == x) {
                lltour[xnext].bwd.next = &(lltour[x].fwd);
                lltour[x].bwd.next = &(lltour[xnext].fwd);
            } else {
                lltour[xnext].fwd.next = &(lltour[x].fwd);
                lltour[x].bwd.next = &(lltour[xnext].bwd);
            }
            if (lltour[yprev].fwd.next->name == y) {
                lltour[yprev].fwd.next = &(lltour[y].bwd);
                lltour[y].fwd.next = &(lltour[yprev].bwd);
            } else {
                lltour[yprev].bwd.next = &(lltour[y].bwd);
                lltour[y].fwd.next = &(lltour[yprev].fwd);
            }
        }

        if (xprev == ynext) {
            if (lltour[xprev].fwd.next->name == x) {
                lltour[xprev].fwd.next = &(lltour[y].fwd);
                lltour[y].bwd.next = &(lltour[xprev].bwd);
                lltour[xprev].bwd.next = &(lltour[x].bwd);
                lltour[x].fwd.next = &(lltour[xprev].fwd);
            } else {
                lltour[xprev].bwd.next = &(lltour[y].fwd);
                lltour[y].bwd.next = &(lltour[xprev].fwd);
                lltour[xprev].fwd.next = &(lltour[x].bwd);
                lltour[x].fwd.next = &(lltour[xprev].bwd);
            }
        } else {
            if (lltour[ynext].bwd.next->name == y) {
                lltour[ynext].bwd.next = &(lltour[x].bwd);
                lltour[x].fwd.next = &(lltour[ynext].fwd);
            } else {
                lltour[ynext].fwd.next = &(lltour[x].bwd);
                lltour[x].fwd.next = &(lltour[ynext].bwd);
            }
            if (lltour[xprev].fwd.next->name == x) {
                lltour[xprev].fwd.next = &(lltour[y].fwd);
                lltour[y].bwd.next = &(lltour[xprev].bwd);
            } else {
                lltour[xprev].bwd.next = &(lltour[y].fwd);
                lltour[y].bwd.next = &(lltour[xprev].fwd);
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
        lltour[y].fwd.mark = 1;
        lltour[y].bwd.mark = 1;
        lltour[z].fwd.mark = 1;
        lltour[z].bwd.mark = 1;

        if (find_orientation (x))
            n = &(lltour[x].bwd);
        else
            n = &(lltour[x].fwd);

        while (!n->mark) {
            n = n->next;
        }
        lltour[y].fwd.mark = 0;
        lltour[y].bwd.mark = 0;
        lltour[z].fwd.mark = 0;
        lltour[z].bwd.mark = 0;

        return (n->name == y);
    }
}
