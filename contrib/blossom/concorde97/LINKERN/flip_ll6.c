/***************************************************************************/
/*                                                                         */
/*  TOUR MAINTANENCE ROUTINES FOR LIN-KERNIGHAN - Linked Lists (express)   */
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
/*       This version uses 2-levels.                                       */
/*                                                                         */
/***************************************************************************/

#include "machdefs.h"
#include "util.h"

/***************************************************************************/
/*                                                                         */
/* LINKDED LIST FLIPPER 6  (flip_ll6.c):                                   */
/*                                                                         */
/*     1. Like flip_ll5, but with an "express lane" subcircuit of about    */
/*        sqrt (n) nodes. All nodes in the express lane have their fwd and */
/*        and bwd pointers correctly oriented.                             */
/*     2. The express lane is maintained as a linked list with explicit    */
/*        nexts and prevs.                                                 */
/*                                                                         */
/***************************************************************************/

#define SWAP(a, b, t) ((t) = (a), (a) = (b), (b) = (t))
#define FORWARD_TOUR  0
#define BACKWARD_TOUR 1

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
} llnode;

#ifdef CC_PROTOTYPE_ANSI

static void
    express_flip (int a, int b),
    dump_cycle (void);
static int
    find_orientation (int s);

#else

static void
    express_flip (),
    dump_cycle ();
static int
    find_orientation ();

#endif

static llnode *lltour = (llnode *) NULL;
static cycle_size = 0;


#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_init (int ncount, int *cyc)
#else
int CClinkern_flipper_init (ncount, cyc)
int ncount;
int *cyc;
#endif
{
    int i, j;
    int groupsize;

    cycle_size = ncount;

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

    groupsize = (int) sqrt ((double) ncount);
    lltour[cyc[0]].actual_fwd.express = 1;
    lltour[cyc[0]].actual_bwd.express = 1;
    lltour[cyc[0]].next_express = &(lltour[cyc[groupsize]]);
    i = groupsize;
    j = ncount - groupsize;
    while (i < j) {
        lltour[cyc[i]].actual_fwd.express = 1;
        lltour[cyc[i]].actual_bwd.express = 1;
        lltour[cyc[i]].prev_express = &(lltour[cyc[i - groupsize]]);
        lltour[cyc[i]].next_express = &(lltour[cyc[i + groupsize]]);
        i += groupsize;
    }
    lltour[cyc[i]].actual_fwd.express = 1;
    lltour[cyc[i]].actual_bwd.express = 1;
    lltour[cyc[i]].next_express = &(lltour[cyc[0]]);
    lltour[cyc[i]].prev_express = &(lltour[cyc[i - groupsize]]);
    lltour[cyc[0]].prev_express = &(lltour[cyc[i]]);


/*
    dump_cycle ();
*/

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static void dump_cycle (void)
#else
static void dump_cycle ()
#endif
{
    int *getit, i;

    getit = CC_SAFE_MALLOC (cycle_size, int);
    CClinkern_flipper_cycle (getit);

    printf ("TOUR: ");

    for (i = 0; i < cycle_size; i++)
        printf ("%2d ", getit[i]);
    printf ("\n");
    fflush (stdout);

    {
        llnode *n, *start;
        oneway *p;

        printf ("Express TOUR: ");
        p = (find_orientation (getit[0]) ? lltour[getit[0]].bwd :
                                           lltour[getit[0]].fwd);
        while (!p->express)
            p = p->next;

        n = start = &(lltour[p->name]);
        do {
            printf ("%d ", n->fwd->name);
            n = n->next_express;
        } while (n != start);
        printf ("\n");
        fflush (stdout);
    }

    CC_FREE (getit, int);
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
    llnode *x = &(lltour[ix]);
    llnode *y = &(lltour[iy]);
    llnode *xprev, *ynext;
    llnode *n, *next;
    oneway *otemp;

    if (ix == iy) {
        SWAP (x->fwd, x->bwd, otemp);
        return;
    }

    xprev = x->prev_express;
    ynext = y->next_express;

    next = x->next_express;
    x->next_express = x->prev_express;
    x->prev_express = next;
    SWAP (x->fwd, x->bwd, otemp);

    do {
        n = next;
        next = n->next_express;
        n->next_express = n->prev_express;
        n->prev_express = next;
        SWAP (n->fwd, n->bwd, otemp);
    } while (n != y);

    if (xprev != y) {
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
    oneway *next, *prev;

    if (x == z || x == y) {
        return 1;
    } else {
        lltour[y].fwd->mark = 1;
        lltour[y].bwd->mark = 1;
        lltour[z].fwd->mark = 1;
        lltour[z].bwd->mark = 1;

        if (find_orientation (x)) {
            next = lltour[x].bwd;
            prev = lltour[x].fwd;
        } else {
            next = lltour[x].fwd;
            prev = lltour[x].bwd;
        }

        while (!next->mark && !prev->mark) {
            next = next->next;
            prev = prev->next;
        }

        if (next->mark) {
            lltour[y].fwd->mark = 0;
            lltour[y].bwd->mark = 0;
            lltour[z].fwd->mark = 0;
            lltour[z].bwd->mark = 0;
            return (next->name == y);
        } else {
            lltour[y].fwd->mark = 0;
            lltour[y].bwd->mark = 0;
            lltour[z].fwd->mark = 0;
            lltour[z].bwd->mark = 0;
            return (prev->name == z);
        }
    }
}

