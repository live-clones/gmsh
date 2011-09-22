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
/*       Like FLIPPER 6, but with reversal bit for the express cycle, and  */
/*   and smaller groupsize (since flipping should be faster on bigger      */
/*   cycles, so we can use the smaller groupsize to pick up the speed of   */
/*   of the orientation finding routines).                                 */
/*                                                                         */
/***************************************************************************/

#include "machdefs.h"
#include "util.h"

/***************************************************************************/
/*                                                                         */
/* LINKDED LIST FLIPPER 7  (flip_ll7.c):  (ADDS INDEX)                     */
/*                                                                         */
/*     1. Like flip_ll6, but with reversal and smaller groupsize.          */
/*                                                                         */
/***************************************************************************/

#define SWAP(a, b, t) ((t) = (a), (a) = (b), (b) = (t))
#define FORWARD_TOUR  0
#define BACKWARD_TOUR 1
#define GROUP_FACTOR 8.0

typedef struct oneway {
    struct oneway *next;
    int            name;
    char           dir;
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
    int            index;
} llnode;

#ifdef CC_PROTOTYPE_ANSI

static void
    express_flip (int a, int b),
    express_flip_work (llnode *x, llnode *y);
static int
    find_orientation (int s);

#else

static void
    express_flip (),
    express_flip_work ();
static int
    find_orientation ();

#endif

static llnode *lltour = (llnode *) NULL;
static int cycle_size = 0;
static int express_cycle_size = 0;
static int reversed = 0;


#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_init (int ncount, int *cyc)
#else
int CClinkern_flipper_init (ncount, cyc)
int ncount;
int *cyc;
#endif
{
    int i, j, k;
    int groupsize;

    cycle_size = ncount;
    reversed = 0;

    lltour = CC_SAFE_MALLOC (ncount, llnode);
    if (!lltour)
        return 1;

    lltour[cyc[0]].actual_fwd.name = cyc[0];
    lltour[cyc[0]].actual_fwd.mark = 0;
    lltour[cyc[0]].actual_fwd.dir = FORWARD_TOUR;
    lltour[cyc[0]].actual_fwd.express = 0;
    lltour[cyc[0]].actual_fwd.next = &(lltour[cyc[1]].actual_fwd);
    lltour[cyc[0]].fwd = &(lltour[cyc[0]].actual_fwd);
    lltour[cyc[0]].actual_bwd.name = cyc[0];
    lltour[cyc[0]].actual_bwd.mark = 0;
    lltour[cyc[0]].actual_bwd.dir = BACKWARD_TOUR;
    lltour[cyc[0]].actual_bwd.express = 0;
    lltour[cyc[0]].actual_bwd.next = &(lltour[cyc[ncount - 1]].actual_bwd);
    lltour[cyc[0]].bwd = &(lltour[cyc[0]].actual_bwd);
    lltour[cyc[ncount - 1]].actual_fwd.name = cyc[ncount - 1];
    lltour[cyc[ncount - 1]].actual_fwd.mark = 0;
    lltour[cyc[ncount - 1]].actual_fwd.dir = FORWARD_TOUR;
    lltour[cyc[ncount - 1]].actual_fwd.express = 0;
    lltour[cyc[ncount - 1]].actual_fwd.next = &(lltour[cyc[0]].actual_fwd);
    lltour[cyc[ncount - 1]].fwd = &(lltour[cyc[ncount - 1]].actual_fwd);
    lltour[cyc[ncount - 1]].actual_bwd.name = cyc[ncount - 1];
    lltour[cyc[ncount - 1]].actual_bwd.mark = 0;
    lltour[cyc[ncount - 1]].actual_bwd.dir = BACKWARD_TOUR;
    lltour[cyc[ncount - 1]].actual_bwd.express = 0;
    lltour[cyc[ncount - 1]].actual_bwd.next =
                        &(lltour[cyc[ncount - 2]].actual_bwd);
    lltour[cyc[ncount - 1]].bwd = &(lltour[cyc[ncount - 1]].actual_bwd);


    for (i = ncount - 2; i; i--) {
        lltour[cyc[i]].actual_fwd.name = cyc[i];
        lltour[cyc[i]].actual_fwd.mark = 0;
        lltour[cyc[i]].actual_fwd.dir = FORWARD_TOUR;
        lltour[cyc[i]].actual_fwd.express = 0;
        lltour[cyc[i]].actual_fwd.next = &(lltour[cyc[i + 1]].actual_fwd);
        lltour[cyc[i]].fwd = &(lltour[cyc[i]].actual_fwd);
        lltour[cyc[i]].actual_bwd.name = cyc[i];
        lltour[cyc[i]].actual_bwd.mark = 0;
        lltour[cyc[i]].actual_bwd.dir = BACKWARD_TOUR;
        lltour[cyc[i]].actual_bwd.express = 0;
        lltour[cyc[i]].actual_bwd.next = &(lltour[cyc[i - 1]].actual_bwd);
        lltour[cyc[i]].bwd = &(lltour[cyc[i]].actual_bwd);
    }

    groupsize = (int) (sqrt ((double) ncount) / GROUP_FACTOR);
    if (groupsize < 3)
        groupsize = 3;
    lltour[cyc[0]].actual_fwd.express = 1;
    lltour[cyc[0]].actual_bwd.express = 1;
    lltour[cyc[0]].next_express = &(lltour[cyc[groupsize]]);
    lltour[cyc[0]].index = 0;
    i = groupsize;
    j = ncount - groupsize;
    k = 1;
    while (i < j) {
        lltour[cyc[i]].actual_fwd.express = 1;
        lltour[cyc[i]].actual_bwd.express = 1;
        lltour[cyc[i]].prev_express = &(lltour[cyc[i - groupsize]]);
        lltour[cyc[i]].next_express = &(lltour[cyc[i + groupsize]]);
        lltour[cyc[i]].index = k++;
        i += groupsize;
    }
    lltour[cyc[i]].actual_fwd.express = 1;
    lltour[cyc[i]].actual_bwd.express = 1;
    lltour[cyc[i]].index = k;
    lltour[cyc[i]].next_express = &(lltour[cyc[0]]);
    lltour[cyc[i]].prev_express = &(lltour[cyc[i - groupsize]]);
    lltour[cyc[0]].prev_express = &(lltour[cyc[i]]);
    express_cycle_size = k+1;

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

    while (!n->express)
        n = n->next;

    if (reversed)
        return (n != lltour[n->name].bwd);
    else
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
    oneway *o, *p, *otemp;

    if (x == y)
        return;

    if (lltour[x].bwd->next->name == xprev)
        o = lltour[x].fwd;
    else
        o = lltour[x].bwd;

    while (!o->express && o->name != y)
        o = o->next;

    if (o->express) {
        if (lltour[y].fwd->next->name == ynext)
            p = lltour[y].bwd;
        else
            p = lltour[y].fwd;
        while (!p->express)
            p = p->next;
        express_flip (o->name, p->name);
    }


    if (x != ynext && xprev != ynext) {
        if (lltour[ynext].fwd->next->name == y) {
            if (lltour[x].fwd->next->name == xprev) {
                lltour[x].fwd->next = lltour[ynext].bwd;
                lltour[ynext].fwd->next = lltour[x].bwd;
            } else {
                lltour[x].bwd->next = lltour[ynext].bwd;
                lltour[ynext].fwd->next = lltour[x].fwd;
            }
        } else {
            if (lltour[x].fwd->next->name == xprev) {
                lltour[x].fwd->next = lltour[ynext].fwd;
                lltour[ynext].bwd->next = lltour[x].bwd;
            } else {
                lltour[x].bwd->next = lltour[ynext].fwd;
                lltour[ynext].bwd->next = lltour[x].fwd;
            }
        }

        if (lltour[xprev].fwd->next->name == x) {
            if (lltour[y].fwd->next->name == ynext) {
                lltour[y].fwd->next = lltour[xprev].bwd;
                lltour[xprev].fwd->next = lltour[y].bwd;
            } else {
                lltour[y].bwd->next = lltour[xprev].bwd;
                lltour[xprev].fwd->next = lltour[y].fwd;
            }
        } else {
            if (lltour[y].fwd->next->name == ynext) {
                lltour[y].fwd->next = lltour[xprev].fwd;
                lltour[xprev].bwd->next = lltour[y].bwd;
            } else {
                lltour[y].bwd->next = lltour[xprev].fwd;
                lltour[xprev].bwd->next = lltour[y].fwd;
            }
        }
    } else if (x != ynext) {
        if (lltour[xprev].fwd->express) {
            SWAP (lltour[xprev].fwd, lltour[xprev].bwd, otemp);
        }
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void express_flip (int ix, int iy)
#else
static void express_flip (ix, iy)
int ix, iy;
#endif
{
    int side;
    llnode *x = &(lltour[ix]);
    llnode *y = &(lltour[iy]);
    llnode *xprev, *ynext;
    oneway *otemp;

    if (x == y) {
        SWAP (x->fwd, x->bwd, otemp);
        return;
    }

    if (reversed) {
        xprev = lltour[ix].next_express;
        ynext = lltour[iy].prev_express;
    } else {
        xprev = lltour[ix].prev_express;
        ynext = lltour[iy].next_express;
    }

    if (xprev == ynext) {
        SWAP (xprev->fwd, xprev->bwd, otemp);
        reversed ^= 1;
        return;
    }

    if (xprev == y) {
        reversed ^= 1;
        return;
    }

    if (reversed)
        side = x->index - y->index;
    else
        side = y->index - x->index;
    if (side < 0)
        side += express_cycle_size;

    if (side < express_cycle_size / 2)
        express_flip_work (x, y);
    else {
        express_flip_work (ynext, xprev);
        reversed ^= 1;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void express_flip_work (llnode *x, llnode *y)
#else
static void express_flip_work (x, y)
llnode *x, *y;
#endif
{
    llnode *xprev, *ynext;
    llnode *n, *next;
    oneway *otemp;
    int id = x->index;

    if (reversed) {
        xprev = x->next_express;
        ynext = y->prev_express;

        n = y->next_express;
        y->next_express = y->prev_express;
        y->prev_express = n;
        y->index = id--;
        SWAP (y->fwd, y->bwd, otemp);
        while (n != x) {
            next = n->next_express;
            n->next_express = n->prev_express;
            n->prev_express = next;
            n->index = id--;
            SWAP (n->fwd, n->bwd, otemp);
            n = next;
        }
        next = x->next_express;
        x->next_express = x->prev_express;
        x->prev_express = next;
        x->index = id;
        SWAP (x->fwd, x->bwd, otemp);

        y->next_express = xprev;
        x->prev_express = ynext;
        xprev->prev_express = y;
        ynext->next_express = x;
    } else {
        xprev = x->prev_express;
        ynext = y->next_express;

        n = y->prev_express;
        y->prev_express = y->next_express;
        y->next_express = n;
        y->index = id++;
        SWAP (y->fwd, y->bwd, otemp);
        while (n != x) {
            next = n->prev_express;
            n->prev_express = n->next_express;
            n->next_express = next;
            n->index = id++;
            SWAP (n->fwd, n->bwd, otemp);
            n = next;
        }
        next = x->prev_express;
        x->prev_express = x->next_express;
        x->next_express = next;
        x->index = id;
        SWAP (x->fwd, x->bwd, otemp);
        y->prev_express = xprev;
        x->next_express = ynext;
        xprev->next_express = y;
        ynext->prev_express = x;
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_sequence (int x, int y, int z)
#else
int CClinkern_flipper_sequence (x, y, z)
int x, y, z;
#endif
{
    oneway *px, *py, *pz;
    int a, b, c;

    if (x == z || x == y) {
        return 1;
    }

    if (find_orientation (x))
        px = lltour[x].bwd;
    else
        px = lltour[x].fwd;

    while (!px->express) {
        px = px->next;
        if (px->name == y) {
            return 1;
        } else if (px->name == z) {
            return 0;
        }
    }

    if (z == y)
        return 1;
    if (find_orientation (z))
        pz = lltour[z].fwd;
    else
        pz = lltour[z].bwd;
    while (!pz->express) {
        pz = pz->next;
        if (pz->name == y) {
            return 1;
        } else if (pz->name == x) {
            return 0;
        } else if (px->name == pz->name) {
            return 0;
        }
    }

    if (find_orientation (y))
        py = lltour[y].bwd;
    else
        py = lltour[y].fwd;
    while (!py->express) {
        py = py->next;
        if (py->name == z) {
            return 1;
        } else if (py->name == x) {
            return 0;
        } else if (py->name == pz->name) {
            return 1;
        } else if (py->name == px->name) {
            return 0;
        }
    }

    a = lltour[px->name].index;
    b = lltour[py->name].index;
    c = lltour[pz->name].index;

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
