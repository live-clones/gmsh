/***************************************************************************/
/*                                                                         */
/*      TOUR MAINTANENCE ROUTINES FOR LIN-KERNIGHAN - Two-level Tree       */
/*                                                                         */
/*                             TSP CODE                                    */
/*                                                                         */
/*                                                                         */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook                       */
/*  Date: May 2, 1995                                                      */
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
/*       This is desribed in the paper "Data structures for traveling      */
/*   salesman" by Fredman, Johnson, McGeoch, and Ostheimer.                */
/*                                                                         */
/***************************************************************************/

#include "machdefs.h"
#include "util.h"
#include "linkern.h"

/***************************************************************************/
/*                                                                         */
/* TWO-LEVEL TREES:                                                        */
/*                                                                         */
/*     1. Uses the "groupsize" approach described in the paper.            */
/*                                                                         */
/***************************************************************************/

#define USE_SEGMENT_SPLIT
#define GROUPSIZE_FACTOR 0.50
#define SEGMENT_SPLIT_CUTOFF 0.35

typedef struct parentnode {
    struct parentnode *adj[2];
    struct childnode  *ends[2];
    int                size;
    int                id;
    int                rev;
} parentnode;

typedef struct childnode {
    struct parentnode *parent;
    struct childnode  *adj[2];
    int                id;
    int                name;
} childnode;

#ifdef CC_PROTOTYPE_ANSI

static void
    same_segment_flip (childnode *a, childnode *b),
    consecutive_segment_flip (parentnode *a, parentnode *b),
    segment_split (parentnode *p, childnode *aprev, childnode *a,
                   int left_or_right);

#else

static void
    same_segment_flip (),
    consecutive_segment_flip (),
    segment_split ();

#endif

static parentnode *parents = (parentnode *) NULL;
static childnode *children = (childnode *) NULL;
static int reversed = 0;
static cycle_size = 0;
static int nsegments = 0;
static groupsize = 100;
#ifdef USE_SEGMENT_SPLIT
static int split_cutoff = 100;
#endif

#define SAME_SEGMENT(a, b)                                                  \
     (a->parent == b->parent &&                                             \
      ((!(reversed^(a->parent->rev)) && a->id <= b->id) ||                  \
       ((reversed^(a->parent->rev)) && a->id >= b->id)))

#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_init (int ncount, int *cyc)
#else
int CClinkern_flipper_init (ncount, cyc)
int ncount;
int *cyc;
#endif
{
    int i, j, cind, remain;
    childnode *c, *cprev, *cnext;
    parentnode *p;

    reversed = 0;
    cycle_size = ncount;
    groupsize = (int) (sqrt ((double) ncount) * GROUPSIZE_FACTOR);
    nsegments =  (ncount + groupsize - 1) / groupsize;
#ifdef USE_SEGMENT_SPLIT
    split_cutoff = (int) (groupsize * SEGMENT_SPLIT_CUTOFF);
#endif

    parents = CC_SAFE_MALLOC (nsegments, parentnode);
    if (!parents)
        return 1;

    children = CC_SAFE_MALLOC (ncount + 1, childnode);
                 /* The +1 will stop a purify burp later */
    if (!children) {
        CC_FREE (parents, parentnode);
        return 1;
    }

    remain = ncount;
    i = 0;
    j = 2 * groupsize;
    while (remain >= j) {
        parents[i].size = groupsize;
        remain -= groupsize;
        i++;
    }
    if (remain > groupsize) {
        parents[i].size = remain / 2;
        remain -= (remain / 2);
        i++;
    }
    parents[i].size = remain;
    i++;

    if (i != nsegments) {
        printf ("seg count is wrong\n");
        fflush (stdout);
        CC_FREE (parents, parentnode);
        CC_FREE (children, childnode);
        return 1;
    }

    c = (childnode *) NULL;
    cnext = &(children[cyc[0]]);
    for (i = 0, p = parents, c = children, cind = 0; i < nsegments; p++, i++) {
        p->id = i;
        p->rev = 0;
        p->ends[0] = cnext;
        for (j = p->size; j > 0; j--) {
            cprev = c;
            c = cnext;
            c->id = cind;
            c->name = cyc[cind];
            c->parent = p;
            c->adj[0] = cprev;
            cind++;
            if (cind != ncount) {
                cnext = &(children[cyc[cind]]);
                c->adj[1] = cnext;
            }
        }
        p->ends[1] = c;
        p->adj[0] = p - 1;
        p->adj[1] = p + 1;
    }
    parents[0].adj[0] = &(parents[nsegments - 1]);
    parents[nsegments - 1].adj[1] = &(parents[0]);
    children[cyc[0]].adj[0] = &(children[cyc[ncount - 1]]);
    children[cyc[ncount - 1]].adj[1] = &(children[cyc[0]]);

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_cycle (int *x)
#else
int CClinkern_flipper_cycle (x)
int *x;
#endif
{
    childnode *c, *start;
    int k = 0;

    start = &(children[0]);
    c = start->adj[!(reversed^(start->parent->rev))];

    x[k++] = start->name;
    while (c != start) {
        x[k++] = c->name;
        c = c->adj[!(reversed^(c->parent->rev))];
    }
    return cycle_size;
}

#ifdef CC_PROTOTYPE_ANSI
void CClinkern_flipper_finish (void)
#else
void CClinkern_flipper_finish ()
#endif
{
    if (parents)
        CC_FREE (parents, parentnode);
    if (children)
        CC_FREE (children, childnode);
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
    return children[x].adj[!(reversed^(children[x].parent->rev))]->name;
}

#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_prev (int x)
#else
int CClinkern_flipper_prev (x)
int x;
#endif
{
    return children[x].adj[reversed^(children[x].parent->rev)]->name;
}

#ifdef CC_PROTOTYPE_ANSI
void CClinkern_flipper_flip (int x, int y)
#else
void CClinkern_flipper_flip (x, y)
int x,y;
#endif
{
    childnode *xc = &(children[x]);
    childnode *yc = &(children[y]);

    if (SAME_SEGMENT (xc, yc)) {
        if (xc != yc) {
            same_segment_flip (xc, yc);
        }
    } else {
        int xdir = (reversed^(xc->parent->rev));
        int ydir = (reversed^(yc->parent->rev));
        childnode *xprev = xc->adj[xdir];
        childnode *ynext = yc->adj[!ydir];
        if (SAME_SEGMENT (ynext, xprev)) {
            if (ynext != xprev) {
                same_segment_flip (ynext, xprev);
            }
            reversed ^= 1;
        } else {
            int side;
            if (xc->parent->ends[xdir] == xc &&
                yc->parent->ends[!ydir] == yc) {
                if (reversed)
                    side = xc->parent->id - yc->parent->id;
                else
                    side = yc->parent->id - xc->parent->id;
                if (side < 0)
                    side += nsegments;
                if (side < nsegments / 2) {
                    consecutive_segment_flip (xc->parent, yc->parent);
                } else {
                    consecutive_segment_flip(yc->parent->adj[!reversed],
                                             xc->parent->adj[reversed]);
                    reversed ^= 1;
                }
            } else {
                if (xprev->parent == xc->parent) {
                    segment_split (xc->parent, xprev, xc, 0);
                    if (SAME_SEGMENT (xc, yc)) {
                        if (xc != yc)
                            same_segment_flip (xc, yc);
                        return;
                    } else if (SAME_SEGMENT (ynext, xprev)) {
                        if (ynext != xprev) {
                            same_segment_flip (ynext, xprev);
                        }
                        reversed ^= 1;
                        return;
                    }
                }
                if (ynext->parent == yc->parent) {
                    segment_split (yc->parent, yc, ynext, 0);
                    if (SAME_SEGMENT (xc, yc)) {
                        if (xc != yc)
                            same_segment_flip (xc, yc);
                        return;
                    } else if (SAME_SEGMENT (ynext, xprev)) {
                        if (ynext != xprev) {
                            same_segment_flip (ynext, xprev);
                        }
                        reversed ^= 1;
                        return;
                    }
                }
                if (reversed)
                    side = xc->parent->id - yc->parent->id;
                else
                    side = yc->parent->id - xc->parent->id;
                if (side < 0)
                    side += nsegments;
                if (side < nsegments / 2) {
                    consecutive_segment_flip (xc->parent, yc->parent);
                } else {
                    consecutive_segment_flip(yc->parent->adj[!reversed],
                                             xc->parent->adj[reversed]);
                    reversed ^= 1;
                }

            }
        }
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void same_segment_flip (childnode *a, childnode *b)
#else
static void same_segment_flip (a, b)
childnode *a, *b;
#endif
{
    parentnode *parent = a->parent;
    int dir = (reversed^(parent->rev));
    childnode *aprev = a->adj[dir];
    childnode *bnext = b->adj[!dir];
    childnode *c, *cnext;

#ifdef USE_SEGMENT_SPLIT
    if ((dir && a->id - b->id > split_cutoff) ||
       (!dir && b->id - a->id > split_cutoff)) {
        if (aprev->parent == parent)
            segment_split (parent, aprev, a, 1);
        if (bnext->parent == parent)
            segment_split (parent, b, bnext, 2);
        aprev->adj[!(reversed^(aprev->parent->rev))] = b;
        bnext->adj[reversed^(bnext->parent->rev)] = a;
        a->adj[dir] = bnext;
        b->adj[!dir] = aprev;
        parent->rev ^= 1;
        return;
    }
#endif

    if (dir) {
        int id = a->id;
        aprev->adj[!(reversed^(aprev->parent->rev))] = b;
        bnext->adj[reversed^(bnext->parent->rev)] = a;
        cnext = b->adj[1];
        b->adj[1] = aprev;
        b->adj[0] = cnext;
        b->id = id--;
        c = cnext;
        while (c != a) {
            cnext = c->adj[1];
            c->adj[1] = c->adj[0];
            c->adj[0] = cnext;
            c->id = id--;
            c = cnext;
        }
        a->adj[1] = a->adj[0];
        a->adj[0] = bnext;
        a->id = id;
        if (parent->ends[1] == a)
            parent->ends[1] = b;
        if (parent->ends[0] == b)
            parent->ends[0] = a;
    } else {
        int id = a->id;
        aprev->adj[!(reversed^(aprev->parent->rev))] = b;
        bnext->adj[reversed^(bnext->parent->rev)] = a;
        c = b->adj[0];
        b->adj[0] = aprev;
        b->adj[1] = c;
        b->id = id++;
        while (c != a) {
            cnext = c->adj[0];
            c->adj[0] = c->adj[1];
            c->adj[1] = cnext;
            c->id = id++;
            c = cnext;
        }
        a->adj[0] = a->adj[1];
        a->adj[1] = bnext;
        a->id = id;
        if (parent->ends[0] == a)
            parent->ends[0] = b;
        if (parent->ends[1] == b)
            parent->ends[1] = a;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void consecutive_segment_flip (parentnode *a, parentnode *b)
#else
static void consecutive_segment_flip (a, b)
parentnode *a, *b;
#endif
{
    parentnode *aprev = a->adj[reversed];
    parentnode *bnext = b->adj[!reversed];
    parentnode *c, *cnext;
    childnode *achild = a->ends[reversed^(a->rev)];
    childnode *bchild = b->ends[!(reversed^(b->rev))];
    childnode *childprev, *childnext;
    int id = a->id;

    if (reversed) {
        childprev = achild->adj[!a->rev];
        childnext = bchild->adj[b->rev];
        childprev->adj[childprev->parent->rev] = bchild;
        childnext->adj[!childnext->parent->rev] = achild;
        bchild->adj[b->rev] = childprev;
        achild->adj[!a->rev] = childnext;

        aprev->adj[0] = b;
        bnext->adj[1] = a;
        c = b->adj[1];
        b->adj[1] = aprev;
        b->adj[0] = c;
        b->id = id--;
        b->rev ^= 1;
        while (c != a) {
            cnext = c->adj[1];
            c->adj[1] = c->adj[0];
            c->adj[0] = cnext;
            c->id = id--;
            c->rev ^= 1;
            c = cnext;
        }
        a->adj[1] = a->adj[0];
        a->adj[0] = bnext;
        a->id = id;
        a->rev ^= 1;
    } else {
        childprev = achild->adj[a->rev];
        childnext = bchild->adj[!b->rev];
        childprev->adj[!childprev->parent->rev] = bchild;
        childnext->adj[childnext->parent->rev] = achild;
        bchild->adj[!b->rev] = childprev;
        achild->adj[a->rev] = childnext;

        aprev->adj[1] = b;
        bnext->adj[0] = a;
        c = b->adj[0];
        b->adj[0] = aprev;
        b->adj[1] = c;
        b->id = id++;
        b->rev ^= 1;
        while (c != a) {
            cnext = c->adj[0];
            c->adj[0] = c->adj[1];
            c->adj[1] = cnext;
            c->id = id++;
            c->rev ^= 1;
            c = cnext;
        }
        a->adj[0] = a->adj[1];
        a->adj[1] = bnext;
        a->id = id;
        a->rev ^= 1;
    }
}

/* split between a and aprev */

#ifdef CC_PROTOTYPE_ANSI
static void segment_split (parentnode *p, childnode *aprev, childnode *a,
                           int left_or_right)
#else
static void segment_split (p, aprev, a, left_or_right)
parentnode *p;
childnode *aprev, *a;
int left_or_right;
#endif
{
    int side;
    int dir = (reversed^(p->rev));
    int id;
    parentnode *pnext;
    childnode *b, *bnext;

    if (dir)
        side = p->ends[1]->id - aprev->id + 1;
    else
        side = aprev->id - p->ends[0]->id + 1;

    if ((left_or_right == 0 && side <= p->size / 2) || left_or_right == 1) {
        pnext = p->adj[reversed];
        pnext->size += side;
        p->size -= side;
        if (pnext->rev == p->rev) {
            b = pnext->ends[!dir];
            id = b->id;
            if (dir) {
                do {
                    b = b->adj[0];
                    b->id = --id;
                    b->parent = pnext;
                } while (b != aprev);
            } else {
                do {
                    b = b->adj[1];
                    b->id = ++id;
                    b->parent = pnext;
                } while (b != aprev);
            }
            pnext->ends[!dir] = aprev;
            p->ends[dir] = a;
        } else {
            b = pnext->ends[dir];
            id = b->id;
            if (!dir) {
                bnext = b->adj[0];
                do {
                    b = bnext;
                    b->id = --id;
                    b->parent = pnext;
                    bnext = b->adj[1];
                    b->adj[1] = b->adj[0];
                    b->adj[0] = bnext;
                } while (b != aprev);
            } else {
                bnext = b->adj[1];
                do {
                    b = bnext;
                    b->id = ++id;
                    b->parent = pnext;
                    bnext = b->adj[0];
                    b->adj[0] = b->adj[1];
                    b->adj[1] = bnext;
                } while (b != aprev);
            }
            pnext->ends[dir] = aprev;
            p->ends[dir] = a;
        }
    } else {
        pnext = p->adj[!reversed];
        pnext->size += (p->size - side);
        p->size = side;
        if (pnext->rev == p->rev) {
            b = pnext->ends[dir];
            id = b->id;
            if (dir) {
                do {
                    b = b->adj[1];
                    b->id = ++id;
                    b->parent = pnext;
                } while (b != a);
            } else {
                do {
                    b = b->adj[0];
                    b->id = --id;
                    b->parent = pnext;
                } while (b != a);
            }
            pnext->ends[dir] = a;
            p->ends[!dir] = aprev;
        } else {
            b = pnext->ends[!dir];
            id = b->id;
            if (!dir) {
                bnext = b->adj[1];
                do {
                    b = bnext;
                    b->id = ++id;
                    b->parent = pnext;
                    bnext = b->adj[0];
                    b->adj[0] = b->adj[1];
                    b->adj[1] = bnext;
                } while (b != a);
            } else {
                bnext = b->adj[0];
                do {
                    b = bnext;
                    b->id = --id;
                    b->parent = pnext;
                    bnext = b->adj[1];
                    b->adj[1] = b->adj[0];
                    b->adj[0] = bnext;
                } while (b != a);
            }
            pnext->ends[!dir] = a;
            p->ends[!dir] = aprev;
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
    childnode *a = &(children[x]);
    childnode *b = &(children[y]);
    childnode *c = &(children[z]);
    parentnode *pa = a->parent;
    parentnode *pb = b->parent;
    parentnode *pc = c->parent;

    if (pa == pb) {
        if (pa == pc) {
            if (reversed^(pa->rev)) {
                if (a->id >= b->id) {
                    return (b->id >= c->id || c->id >= a->id);
                } else {
                    return (b->id >= c->id && c->id >= a->id);
                }
            } else {
                if (a->id <= b->id) {
                    return (b->id <= c->id || c->id <= a->id);
                } else {
                    return (b->id <= c->id && c->id <= a->id);
                }
            }
        } else {
            if (reversed^(pa->rev)) {
                return (a->id >= b->id);
            } else {
                return (a->id <= b->id);
            }
        }
    } else if (pa == pc) {
            if (reversed^(pa->rev)) {
                return (a->id <= c->id);
            } else {
                return (a->id >= c->id);
            }
    } else if (pb == pc) {
            if (reversed^(pb->rev)) {
                return (b->id >= c->id);
            } else {
                return (b->id <= c->id);
            }
    } else {
        if (reversed) {
            if (pa->id >= pb->id) {
                return (pb->id >= pc->id || pc->id >= pa->id);
            } else {
                return (pb->id >= pc->id && pc->id >= pa->id);
            }
        } else {
            if (pa->id <= pb->id) {
                return (pb->id <= pc->id || pc->id <= pa->id);
            } else {
                return (pb->id <= pc->id && pc->id <= pa->id);
            }
        }
    }
}
