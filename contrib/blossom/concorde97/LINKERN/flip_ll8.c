/***************************************************************************/
/*                                                                         */
/*    TOUR MAINTANENCE ROUTINES FOR LIN-KERNIGHAN - 3-Level Linked List    */
/*                                                                         */
/*                             TSP CODE                                    */
/*                                                                         */
/*                                                                         */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook                       */
/*  Date: June 22, 1995                                                    */
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
/*       This version should be the best of the linked lists so far.       */
/*   It combines the oneway approach, with three levels for an express     */
/*   lane and a superexpress lane. Note that all superexpress nodes are    */
/*   also express nodes.                                                   */
/*                                                                         */
/***************************************************************************/

#include "machdefs.h"
#include "util.h"

/***************************************************************************/
/*                                                                         */
/* LINKDED LIST FLIPPER 8  (flip_ll8.c):                                   */
/*                                                                         */
/*     1. Uses three levels, the top having n**(1/3) nodes.                */
/*     2. The top level has explicit next and prevs, the other levels      */
/*        consist of two "oneway" cycles.                                  */
/*                                                                         */
/***************************************************************************/

#define SWAP(a, b, t) ((t) = (a), (a) = (b), (b) = (t))
#define FORWARD_TOUR  0
#define BACKWARD_TOUR 1

typedef struct oneway {
    struct oneway *next;
    int            name;
    char           mark;
    char           level;
} oneway;

typedef struct llnode {
    struct oneway  actual_fwd;
    struct oneway  actual_bwd;
    struct oneway  actual_fwd_express;
    struct oneway  actual_bwd_express;
    struct oneway  *fwd;
    struct oneway  *bwd;
    struct oneway  *fwd_express;
    struct oneway  *bwd_express;
    struct llnode  *next_super;
    struct llnode  *prev_super;
} llnode;

#ifdef CC_PROTOTYPE_ANSI

static void
    express_flip (int aprev, int a, int b, int bnext),
    super_flip (int a, int b);
static int
    express_flipper_sequence (int x, int y, int z),
    find_orientation (int s);

#else

static void
    express_flip (),
    super_flip ();
static int
    express_flipper_sequence (),
    find_orientation ();

#endif

static llnode *lltour = (llnode *) NULL;
static int cycle_size = 0;
static int reversed = 0;


#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_init (int ncount, int *cyc)
#else
int CClinkern_flipper_init (ncount, cyc)
int ncount;
int *cyc;
#endif
{
    int i, j;
    int groupsize, supergroupsize;

    cycle_size = ncount;
    reversed = 0;

    lltour = CC_SAFE_MALLOC (ncount, llnode);
    if (!lltour)
        return 1;

    lltour[cyc[0]].actual_fwd.name = cyc[0];
    lltour[cyc[0]].actual_fwd.mark = 0;
    lltour[cyc[0]].actual_fwd.level = 0;
    lltour[cyc[0]].actual_fwd.next = &(lltour[cyc[1]].actual_fwd);
    lltour[cyc[0]].fwd = &(lltour[cyc[0]].actual_fwd);
    lltour[cyc[0]].actual_bwd.name = cyc[0];
    lltour[cyc[0]].actual_bwd.mark = 0;
    lltour[cyc[0]].actual_bwd.level = 0;
    lltour[cyc[0]].actual_bwd.next = &(lltour[cyc[ncount - 1]].actual_bwd);
    lltour[cyc[0]].bwd = &(lltour[cyc[0]].actual_bwd);
    lltour[cyc[ncount - 1]].actual_fwd.name = cyc[ncount - 1];
    lltour[cyc[ncount - 1]].actual_fwd.mark = 0;
    lltour[cyc[ncount - 1]].actual_fwd.level = 0;
    lltour[cyc[ncount - 1]].actual_fwd.next = &(lltour[cyc[0]].actual_fwd);
    lltour[cyc[ncount - 1]].fwd = &(lltour[cyc[ncount - 1]].actual_fwd);
    lltour[cyc[ncount - 1]].actual_bwd.name = cyc[ncount - 1];
    lltour[cyc[ncount - 1]].actual_bwd.mark = 0;
    lltour[cyc[ncount - 1]].actual_bwd.level = 0;
    lltour[cyc[ncount - 1]].actual_bwd.next =
                        &(lltour[cyc[ncount - 2]].actual_bwd);
    lltour[cyc[ncount - 1]].bwd = &(lltour[cyc[ncount - 1]].actual_bwd);


    for (i = ncount - 2; i; i--) {
        lltour[cyc[i]].actual_fwd.name = cyc[i];
        lltour[cyc[i]].actual_fwd.mark = 0;
        lltour[cyc[i]].actual_fwd.level = 0;
        lltour[cyc[i]].actual_fwd.next = &(lltour[cyc[i + 1]].actual_fwd);
        lltour[cyc[i]].fwd = &(lltour[cyc[i]].actual_fwd);
        lltour[cyc[i]].actual_bwd.name = cyc[i];
        lltour[cyc[i]].actual_bwd.mark = 0;
        lltour[cyc[i]].actual_bwd.level = 0;
        lltour[cyc[i]].actual_bwd.next = &(lltour[cyc[i - 1]].actual_bwd);
        lltour[cyc[i]].bwd = &(lltour[cyc[i]].actual_bwd);
    }

    groupsize = (int) (pow ((double) ncount, 1.0 / 3.0)/ 1.5);
    supergroupsize = groupsize * groupsize;
    lltour[cyc[0]].actual_fwd.level = 1;
    lltour[cyc[0]].actual_bwd.level = 1;
    lltour[cyc[0]].fwd_express = &(lltour[cyc[0]].actual_fwd_express);
    lltour[cyc[0]].bwd_express = &(lltour[cyc[0]].actual_bwd_express);
    lltour[cyc[0]].actual_fwd_express.mark = 0;
    lltour[cyc[0]].actual_bwd_express.mark = 0;
    lltour[cyc[0]].actual_fwd_express.level = 1;
    lltour[cyc[0]].actual_bwd_express.level = 1;
    lltour[cyc[0]].actual_fwd_express.name = cyc[0];
    lltour[cyc[0]].actual_bwd_express.name = cyc[0];
    lltour[cyc[0]].actual_fwd_express.next =
                          &(lltour[cyc[groupsize]].actual_fwd_express);
    i = groupsize;
    j = ncount - groupsize;
    while (i < j) {
        lltour[cyc[i]].actual_fwd.level = 1;
        lltour[cyc[i]].actual_bwd.level = 1;
        lltour[cyc[i]].fwd_express = &(lltour[cyc[i]].actual_fwd_express);
        lltour[cyc[i]].bwd_express = &(lltour[cyc[i]].actual_bwd_express);
        lltour[cyc[i]].actual_fwd_express.mark = 0;
        lltour[cyc[i]].actual_bwd_express.mark = 0;
        lltour[cyc[i]].actual_fwd_express.level = 1;
        lltour[cyc[i]].actual_bwd_express.level = 1;
        lltour[cyc[i]].actual_fwd_express.name = cyc[i];
        lltour[cyc[i]].actual_bwd_express.name = cyc[i];
        lltour[cyc[i]].actual_fwd_express.next =
                          &(lltour[cyc[i + groupsize]].actual_fwd_express);
        lltour[cyc[i]].actual_bwd_express.next =
                          &(lltour[cyc[i - groupsize]].actual_bwd_express);
        i += groupsize;
    }

    lltour[cyc[i]].actual_fwd.level = 1;
    lltour[cyc[i]].actual_bwd.level = 1;
    lltour[cyc[i]].fwd_express = &(lltour[cyc[i]].actual_fwd_express);
    lltour[cyc[i]].bwd_express = &(lltour[cyc[i]].actual_bwd_express);
    lltour[cyc[i]].actual_fwd_express.mark = 0;
    lltour[cyc[i]].actual_bwd_express.mark = 0;
    lltour[cyc[i]].actual_fwd_express.level = 1;
    lltour[cyc[i]].actual_bwd_express.level = 1;
    lltour[cyc[i]].actual_fwd_express.name = cyc[i];
    lltour[cyc[i]].actual_bwd_express.name = cyc[i];
    lltour[cyc[i]].actual_fwd_express.next =
                          &(lltour[cyc[0]].actual_fwd_express);
    lltour[cyc[i]].actual_bwd_express.next =
                          &(lltour[cyc[i - groupsize]].actual_bwd_express);
    lltour[cyc[0]].actual_bwd_express.next =
                          &(lltour[cyc[i]].actual_bwd_express);

    lltour[cyc[0]].actual_fwd.level = 2;
    lltour[cyc[0]].actual_bwd.level = 2;
    lltour[cyc[0]].actual_fwd_express.level = 2;
    lltour[cyc[0]].actual_bwd_express.level = 2;
    lltour[cyc[0]].next_super = &(lltour[cyc[supergroupsize]]);
    i = supergroupsize;
    j = ncount - supergroupsize;
    while (i < j) {
        lltour[cyc[i]].actual_fwd.level = 2;
        lltour[cyc[i]].actual_bwd.level = 2;
        lltour[cyc[i]].actual_fwd_express.level = 2;
        lltour[cyc[i]].actual_bwd_express.level = 2;
        lltour[cyc[i]].prev_super = &(lltour[cyc[i - supergroupsize]]);
        lltour[cyc[i]].next_super = &(lltour[cyc[i + supergroupsize]]);
        i += supergroupsize;
    }
    lltour[cyc[i]].actual_fwd.level = 2;
    lltour[cyc[i]].actual_bwd.level = 2;
    lltour[cyc[i]].actual_fwd_express.level = 2;
    lltour[cyc[i]].actual_bwd_express.level = 2;
    lltour[cyc[i]].next_super = &(lltour[cyc[0]]);
    lltour[cyc[i]].prev_super = &(lltour[cyc[i - supergroupsize]]);
    lltour[cyc[0]].prev_super = &(lltour[cyc[i]]);

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

    while (!n->level)
        n = n->next;

    if (lltour[n->name].fwd == n)
        n = lltour[n->name].fwd_express;
    else
        n = lltour[n->name].bwd_express;

    while (n->level != 2)
        n = n->next;

    if (reversed)
        return (n != lltour[n->name].bwd_express);
    else
        return (n != lltour[n->name].fwd_express);
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
    oneway *o, *p, *oprev, *pnext;

    if (x == y)
        return;

    if (lltour[x].bwd->next->name == xprev)
        o = lltour[x].fwd;
    else
        o = lltour[x].bwd;

    while (!o->level && o->name != y)
        o = o->next;

    if (o->level) {
        if (lltour[o->name].fwd == o)
            oprev = lltour[o->name].bwd->next;
        else
            oprev = lltour[o->name].fwd->next;
        while (!oprev->level)
            oprev = oprev->next;
        if (lltour[y].fwd->next->name == ynext)
            p = lltour[y].bwd;
        else
            p = lltour[y].fwd;
        while (!p->level)
            p = p->next;
        if (lltour[p->name].fwd == p)
            pnext = lltour[p->name].bwd->next;
        else
            pnext = lltour[p->name].fwd->next;
        while (!pnext->level)
            pnext = pnext->next;
        express_flip (oprev->name, o->name, p->name, pnext->name);
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
        oneway *otemp;
        if (lltour[xprev].fwd->level) {
            SWAP (lltour[xprev].fwd, lltour[xprev].bwd, otemp);
        }
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void express_flip (int xprev, int x, int y, int ynext)
#else
static void express_flip (xprev, x, y, ynext)
int xprev, x, y, ynext;
#endif
{
    oneway *o, *p, *otemp;

    if (x == y) {
        SWAP (lltour[x].fwd, lltour[x].bwd, otemp);
        return;
    } else if (xprev == ynext) {
        SWAP (lltour[xprev].fwd, lltour[xprev].bwd, otemp);
        reversed ^= 1;
        return;
    }

    if (lltour[x].bwd_express->next->name == xprev) {
        o = lltour[x].fwd_express;
    } else {
        o = lltour[x].bwd_express;
    }

    while (o->level != 2 && o->name != y)
        o = o->next;

    if (o->level == 2) {
        if (lltour[y].fwd_express->next->name == ynext)
            p = lltour[y].bwd_express;
        else
            p = lltour[y].fwd_express;
        while (p->level != 2)
            p = p->next;
        super_flip (o->name, p->name);
    }


    if (x != ynext) {
        if (lltour[ynext].fwd_express->next->name == y) {
            if (lltour[x].fwd_express->next->name == xprev) {
                lltour[x].fwd_express->next = lltour[ynext].bwd_express;
                lltour[ynext].fwd_express->next = lltour[x].bwd_express;
            } else {
                lltour[x].bwd_express->next = lltour[ynext].bwd_express;
                lltour[ynext].fwd_express->next = lltour[x].fwd_express;
            }
        } else {
            if (lltour[x].fwd_express->next->name == xprev) {
                lltour[x].fwd_express->next = lltour[ynext].fwd_express;
                lltour[ynext].bwd_express->next = lltour[x].bwd_express;
            } else {
                lltour[x].bwd_express->next = lltour[ynext].fwd_express;
                lltour[ynext].bwd_express->next = lltour[x].fwd_express;
            }
        }

        if (lltour[xprev].fwd_express->next->name == x) {
            if (lltour[y].fwd_express->next->name == ynext) {
                lltour[y].fwd_express->next = lltour[xprev].bwd_express;
                lltour[xprev].fwd_express->next = lltour[y].bwd_express;
            } else {
                lltour[y].bwd_express->next = lltour[xprev].bwd_express;
                lltour[xprev].fwd_express->next = lltour[y].fwd_express;
            }
        } else {
            if (lltour[y].fwd_express->next->name == ynext) {
                lltour[y].fwd_express->next = lltour[xprev].fwd_express;
                lltour[xprev].bwd_express->next = lltour[y].bwd_express;
            } else {
                lltour[y].bwd_express->next = lltour[xprev].fwd_express;
                lltour[xprev].bwd_express->next = lltour[y].fwd_express;
            }
        }
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void super_flip (int ix, int iy)
#else
static void super_flip (ix, iy)
int ix, iy;
#endif
{
    llnode *x = &(lltour[ix]);
    llnode *y = &(lltour[iy]);
    llnode *xprev, *ynext;
    llnode *n, *next, *prev;
    oneway *otemp;

    if (x == y) {
        SWAP (x->fwd_express, x->bwd_express, otemp);
        SWAP (x->fwd, x->bwd, otemp);
        return;
    }

    if (reversed) {
        xprev = x->next_super;
        ynext = y->prev_super;

        next = x->prev_super;
        prev = xprev->next_super;

        while (next != y && prev != ynext) {
            next = next->prev_super;
            prev = prev->next_super;
        }

        if (next == y) {
            next = x->prev_super;
            x->prev_super = x->next_super;
            x->next_super = next;
            SWAP (x->fwd_express, x->bwd_express, otemp);
            SWAP (x->fwd, x->bwd, otemp);

            do {
                n = next;
                next = n->prev_super;
                n->prev_super = n->next_super;
                n->next_super = next;
                SWAP (n->fwd_express, n->bwd_express, otemp);
                SWAP (n->fwd, n->bwd, otemp);
            } while (n != y);

            if (xprev != y) {
                y->next_super = xprev;
                x->prev_super = ynext;
                xprev->prev_super = y;
                ynext->next_super = x;
            }
        } else {
            prev = xprev->next_super;
            xprev->next_super = xprev->prev_super;
            xprev->prev_super = prev;
            SWAP (xprev->fwd_express, xprev->bwd_express, otemp);
            SWAP (xprev->fwd, xprev->bwd, otemp);

            do {
                n = prev;
                prev = n->next_super;
                n->next_super = n->prev_super;
                n->prev_super = prev;
                SWAP (n->fwd_express, n->bwd_express, otemp);
                SWAP (n->fwd, n->bwd, otemp);
            } while (n != ynext);

            if (xprev != y) {
                y->prev_super = xprev;
                x->next_super = ynext;
                xprev->next_super = y;
                ynext->prev_super = x;
            }
            reversed = 0;
        }
    } else {
        xprev = x->prev_super;
        ynext = y->next_super;

        next = x->next_super;
        prev = xprev->prev_super;

        while (next != y && prev != ynext) {
            next = next->next_super;
            prev = prev->prev_super;
        }

        if (next == y) {
            next = x->next_super;
            x->next_super = x->prev_super;
            x->prev_super = next;
            SWAP (x->fwd_express, x->bwd_express, otemp);
            SWAP (x->fwd, x->bwd, otemp);

            do {
                n = next;
                next = n->next_super;
                n->next_super = n->prev_super;
                n->prev_super = next;
                SWAP (n->fwd_express, n->bwd_express, otemp);
                SWAP (n->fwd, n->bwd, otemp);
            } while (n != y);

            if (xprev != y) {
                y->prev_super = xprev;
                x->next_super = ynext;
                xprev->next_super = y;
                ynext->prev_super = x;
            }
        } else {
            prev = xprev->prev_super;
            xprev->prev_super = xprev->next_super;
            xprev->next_super = prev;
            SWAP (xprev->fwd_express, xprev->bwd_express, otemp);
            SWAP (xprev->fwd, xprev->bwd, otemp);

            do {
                n = prev;
                prev = n->prev_super;
                n->prev_super = n->next_super;
                n->next_super = prev;
                SWAP (n->fwd_express, n->bwd_express, otemp);
                SWAP (n->fwd, n->bwd, otemp);
            } while (n != ynext);

            if (xprev != y) {
                y->next_super = xprev;
                x->prev_super = ynext;
                xprev->prev_super = y;
                ynext->next_super = x;
            }
            reversed = 1;
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
    oneway *px, *py, *pz;

    if (x == z || x == y)
        return 1;
    if (find_orientation (x))
        px = lltour[x].bwd;
    else
        px = lltour[x].fwd;
    while (!px->level) {
        px = px->next;
        if (px->name == y)
            return 1;
        else if (px->name == z)
            return 0;
    }

    if (z == y)
        return 1;
    if (find_orientation (z))
        pz = lltour[z].fwd;
    else
        pz = lltour[z].bwd;
    while (!pz->level) {
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
    while (!py->level) {
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
    return express_flipper_sequence (px->name, py->name, pz->name);
}

#ifdef CC_PROTOTYPE_ANSI
static int express_flipper_sequence (int x, int y, int z)
#else
static int express_flipper_sequence (x, y, z)
int x, y, z;
#endif
{
    oneway *next, *prev;

    lltour[y].fwd_express->mark = 1;
    lltour[y].bwd_express->mark = 1;
    lltour[z].fwd_express->mark = 1;
    lltour[z].bwd_express->mark = 1;

    if (find_orientation (x)) {
        next = lltour[x].bwd_express;
        prev = lltour[x].fwd_express;
    } else {
        next = lltour[x].fwd_express;
        prev = lltour[x].bwd_express;
    }

    while (!next->mark && !prev->mark) {
        next = next->next;
        prev = prev->next;
    }

    if (next->mark) {
        lltour[y].fwd_express->mark = 0;
        lltour[y].bwd_express->mark = 0;
        lltour[z].fwd_express->mark = 0;
        lltour[z].bwd_express->mark = 0;
        return (next->name == y);
    } else {
        lltour[y].fwd_express->mark = 0;
        lltour[y].bwd_express->mark = 0;
        lltour[z].fwd_express->mark = 0;
        lltour[z].bwd_express->mark = 0;
        return (prev->name == z);
    }
}

