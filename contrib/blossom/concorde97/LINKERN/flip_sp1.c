/***************************************************************************/
/*                                                                         */
/* TOUR MAINTANENCE ROUTINES FOR LIN-KERNIGHAN  - Splay Trees  (no dummy)  */
/*                                                                         */
/*                               TSP CODE                                  */
/*                                                                         */
/*                                                                         */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook                       */
/*  Date: March 28, 1995 (but mainly from March, 1990)                     */
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
/*   int CClinkern_flipper_sequence (int x, int y, int z)                  */
/*     returns 1 if xyz occur as an increasing subsequence of the cycle,   */
/*     returns 0 otherwise.                                                */
/*   void CClinkern_flipper_sequence_burst_init (int x, int z)             */
/*     initilizes the tree for a sequence of (x, y, z) sequence queries.   */
/*   int CClinkern_flipper_sequence_burst (int x, int y, int z)            */
/*     can be called instead of CClinkern_flipper_sequence, after a call to*/
/*     CClinkern_flipper_sequence_burst_init (x, y), and before any flips  */
/*     (but it requires that NEXT_PREV_NOSPLAY be defined). Does not seem  */
/*     to improve the running time.                                        */
/*                                                                         */
/* NOTES:                                                                  */
/*       Should work well on very large problems.                          */
/*       One of NEXT_PREV_SPLAY, NEXT_PREV_NOSPLAY, NEXT_PREV_NOSPLAY1,    */
/*   or NEXT_PREV_NOSPLAY2 must be defined. (NEXT_PREV_NOSPLAY looks like  */
/*   the fastest.) One of SEQUENCE_SPLAY or SEQUENCE_NOSPLAY must be       */
/*   defined. (SEQUENCE_NOSPLAY looks like the fastest - it does not splay */
/*   the middle node in the query.)                                        */
/*                                                                         */
/*   If USE_UGLY_SPLAY is defined, an uglier (but perhaps faster) splay    */
/*   step is used.                                                         */
/*                                                                         */
/*   If SAVE_NEIGHBORS is defined, the neighbors of each node are          */
/*   remembered, saving some tree traversals for next and prev.            */
/*   In this case, the neighbor is never splayed, so NEXT_PREV_SPLAY       */
/*   and NEXT_PREV_NOSPLAY2 become equivalent, as do NEXT_PREV_NOSPLAY     */
/*   NEXT_PREV_NOSPLAY1.                                                   */
/*                                                                         */
/***************************************************************************/

#include "machdefs.h"
#include "util.h"

/*#define NEXT_PREV_SPLAY */     /* 1xxxx */
#define NEXT_PREV_NOSPLAY        /* 2xxxx */
/*#define NEXT_PREV_NOSPLAY1 */  /* 3xxxx */
/*#define NEXT_PREV_NOSPLAY2 */  /* 4xxxx */
/*#define SEQUENCE_SPLAY */      /* x1xxx */
#define SEQUENCE_NOSPLAY         /* x2xxx */
#define USE_UGLY_SPLAY           /* xx2xx */
#define SAVE_NEIGHBORS           /* xxx2x */

/***************************************************************************/
/*                                                                         */
/* SPLAY TREE FLIPPER (flipper4):                                          */
/*                                                                         */
/*     1. CClinkern_flipper_cycle and CClinkern_flipper_cycle_inverse return the number of     */
/*        nodes.                                                           */
/*                                                                         */
/*     2. The basic splay implementation - uses a splay tree with one node */
/*        per element.                                                     */
/*                                                                         */
/***************************************************************************/

typedef struct splay {
    struct splay *parent;
    struct splay *child[2];
#ifdef SAVE_NEIGHBORS
    struct splay *neigh[2];
#endif
    int reversed;
    int mark;
    int value;
} splay;

#define SWAP(a, b, t) ((t) = (a), (a) = (b), (b) = (t))

#ifdef CC_PROTOTYPE_ANSI

static int
    flipper4_cycle_fillin(int *x, int i, splay *p, int r);
static void
    flipper4_reverse (splay *p),
    flipper4_rotate (splay *x, splay *px),
    flipper4_splay (splay *x);
static splay
    *flipper4_make_tree (int a, int b, int *cyc);

#else

static int
    flipper4_cycle_fillin();
static void
    flipper4_reverse (),
    flipper4_rotate (),
    flipper4_splay ();
static splay
    *flipper4_make_tree ();

#endif

static splay *splay_space = (splay *) NULL;
static splay root;

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
static splay *flipper4_make_tree (int a, int b, int *cyc)
#else
static splay *flipper4_make_tree (a, b, cyc)
int a;
int b;
int *cyc;
#endif
{
    splay *p;
    int center;

    if (b < a)
        return (splay *) NULL;

    center = (a + b)/2;
    p = splay_space + cyc[center];
    if ((p->child[0] = flipper4_make_tree (a, center-1, cyc)) != (splay *) NULL)
        p->child[0]->parent = p;
    if ((p->child[1] = flipper4_make_tree (center+1, b, cyc)) != (splay *) NULL)
        p->child[1]->parent = p;
    return p;
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

/*
    printf ("Flipper flags:");
#ifdef NEXT_PREV_SPLAY
    printf (" NEXT_PREV_SPLAY");
#endif
#ifdef NEXT_PREV_NOSPLAY
    printf (" NEXT_PREV_NOSPLAY");
#endif
#ifdef NEXT_PREV_NOSPLAY1
    printf (" NEXT_PREV_NOSPLAY1");
#endif
#ifdef NEXT_PREV_NOSPLAY2
    printf (" NEXT_PREV_NOSPLAY2");
#endif
#ifdef SEQUENCE_SPLAY
    printf (" SEQUENCE_SPLAY");
#endif
#ifdef SEQUENCE_NOSPLAY
    printf (" SEQUENCE_NOSPLAY");
#endif
#ifdef USE_UGLY_SPLAY
    printf (" USE_UGLY_SPLAY");
#else
    printf (" !USE_UGLY_SPLAY");
#endif
#ifdef SAVE_NEIGHBORS
    printf (" SAVE_NEIGHBORS");
#else
    printf (" !SAVE_NEIGHBORS");
#endif
    printf (" !DUMMY_LEAF\n");
*/

    root.reversed = 0;
    root.parent = (splay *) NULL;
    root.child[1] = (splay *) NULL;
    root.value = ncount;

    splay_space = CC_SAFE_MALLOC (ncount, splay);
    if (!splay_space)
        return 1;

    for (i = 0; i < ncount; i++) {
        splay_space[i].reversed = 0;
        splay_space[i].value = i;
        splay_space[i].mark = 0;
#ifdef SAVE_NEIGHBORS
        if (i==0) {
            splay_space[cyc[0]].neigh[0] = &splay_space[cyc[ncount-1]];
            splay_space[cyc[ncount-1]].neigh[1] = &splay_space[cyc[0]];
        } else {
            splay_space[cyc[i]].neigh[0] = &splay_space[cyc[i-1]];
            splay_space[cyc[i-1]].neigh[1] = &splay_space[cyc[i]];
        }
#endif
    }

    root.child[0] = flipper4_make_tree (0, ncount - 1, cyc);
    root.child[0]->parent = &root;
    root.mark = 1;

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int flipper4_cycle_fillin(int *x, int i, splay *p, int r)
#else
static int flipper4_cycle_fillin(x, i, p, r)
int *x;
int i;
splay *p;
int r;
#endif
{
    if (!p)
        return i;

    r ^= p->reversed;
    i = flipper4_cycle_fillin (x, i, p->child[r], r);
    x[i++] = p->value;
    i = flipper4_cycle_fillin (x, i, p->child[1 - r], r);

    return i;
}

#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_cycle (int *x)
#else
int CClinkern_flipper_cycle (x)
int *x;
#endif
{
    return flipper4_cycle_fillin (x, 0, root.child[0], 0);
}

#ifdef CC_PROTOTYPE_ANSI
void CClinkern_flipper_finish (void)
#else
void CClinkern_flipper_finish ()
#endif
{
    if (splay_space)
        CC_FREE (splay_space, splay);

    root.child[0] = (splay *) NULL;
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
static void flipper4_reverse (splay *p)
#else
static void flipper4_reverse (p)
splay *p;
#endif
{
    splay *temp;

    SWAP (p->child[0], p->child[1], temp);
    if (p->child[0])
        p->child[0]->reversed ^= 1;
    if (p->child[1])
        p->child[1]->reversed ^= 1;
    p->reversed ^= 1;
#ifdef SAVE_NEIGHBORS
    SWAP (p->neigh[0], p->neigh[1], temp);
#endif
}

#ifdef CC_PROTOTYPE_ANSI
static void flipper4_rotate (splay *x, splay *px)
#else
static void flipper4_rotate (x, px)
splay *x, *px;
#endif
{
    splay *b;

    if (px->child[0] == x) {
        b = x->child[1];
        if (b) b->parent = px;
        x->child[1] = px;
        x->parent = px->parent;
        if (x->parent->child[0] == px) {
            x->parent->child[0] = x;
        } else {
            x->parent->child[1] = x;
        }
        px->child[0] = b;
        px->parent = x;
    } else {
        b = x->child[0];
        if (b) b->parent = px;
        x->child[0] = px;
        x->parent = px->parent;
        if (x->parent->child[0] == px) {
            x->parent->child[0] = x;
        } else {
            x->parent->child[1] = x;
        }
        px->child[1] = b;
        px->parent = x;
    }
}

#ifdef USE_UGLY_SPLAY

#ifdef CC_PROTOTYPE_ANSI
static void flipper4_splay (splay *x)
#else
static void flipper4_splay (x)
splay *x;
#endif
{
    splay *px;
    splay *ppx;
    splay *b, *c;

    for (;;) {
        px = x->parent;
        if (px->mark)
            return;
        ppx = px->parent;
        if (ppx->mark) {
            if (px->reversed)
                flipper4_reverse (px);
            if (x->reversed)
                flipper4_reverse (x);
            flipper4_rotate (x, px);
            return;
        }
        if (ppx->reversed)
            flipper4_reverse (ppx);
        if (px->reversed)
            flipper4_reverse (px);
        if (x->reversed)
            flipper4_reverse (x);

        x->parent = ppx->parent;
        if (x->parent->child[0] == ppx) {
            x->parent->child[0] = x;
        } else {
            x->parent->child[1] = x;
        }

        if (ppx->child[0] == px) {
            if (px->child[0] == x) {
                b = x->child[1];
                c = px->child[1];
                if (b) b->parent = px;
                if (c) c->parent = ppx;
                x->child[1] = px;
                px->child[0] = b;
                px->child[1] = ppx;
                ppx->child[0] = c;
                px->parent = x;
                ppx->parent = px;
            } else {
                b = x->child[0];
                c = x->child[1];
                if (b) b->parent = px;
                if (c) c->parent = ppx;
                x->child[0] = px;
                x->child[1] = ppx;
                px->child[1] = b;
                ppx->child[0] = c;
                px->parent = x;
                ppx->parent = x;
            }
        } else {
            if (px->child[1] == x) {
                b = px->child[0];
                c = x->child[0];
                if (b) b->parent = ppx;
                if (c) c->parent = px;
                x->child[0] = px;
                px->child[0] = ppx;
                px->child[1] = c;
                ppx->child[1] = b;
                px->parent = x;
                ppx->parent = px;
            } else {
                b = x->child[0];
                c = x->child[1];
                if (b) b->parent = ppx;
                if (c) c->parent = px;
                x->child[0] = ppx;
                x->child[1] = px;
                ppx->child[1] = b;
                px->child[0] = c;
                px->parent = x;
                ppx->parent = x;
            }
        }
    }
}

#else /* USE_UGLY_SPLAY */

#ifdef CC_PROTOTYPE_ANSI
static void flipper4_splay (splay *x)
#else
static void flipper4_splay (x)
splay *x;
#endif
{
    splay *px;
    splay *ppx;

    for (;;) {
        px = x->parent;
        if (px->mark)
            return;
        ppx = px->parent;
        if (ppx->mark) {
            if (px->reversed)
                flipper4_reverse (px);
            if (x->reversed)
                flipper4_reverse (x);
            flipper4_rotate (x, px);
            return;
        }
        if (ppx->reversed)
            flipper4_reverse (ppx);
        if (px->reversed)
            flipper4_reverse (px);
        if (x->reversed)
            flipper4_reverse (x);
        if (ppx->child[0] == px) {
            if (px->child[0] == x) {
                flipper4_rotate (px, ppx);
                flipper4_rotate (x, px);
            } else {
                flipper4_rotate (x, px);
                flipper4_rotate (x, ppx);
            }
        } else {
            if (px->child[1] == x) {
                flipper4_rotate (px, ppx);
                flipper4_rotate (x, px);
            } else {
                flipper4_rotate (x, px);
                flipper4_rotate (x, ppx);
            }
        }
    }
}

#endif /* USE_UGLY_SPLAY */

#ifdef NEXT_PREV_SPLAY
#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_next (int x)
#else
int CClinkern_flipper_next (x)
int x;
#endif
{
    splay *p = splay_space+x;
    splay *pnext;
    int r;

    flipper4_splay (p);
    if (p->reversed)
        flipper4_reverse (p);
#ifdef SAVE_NEIGHBORS
    return p->neigh[1]->value;
#else /* SAVE_NEIGHBORS */
    if (p->child[1])
        p = p->child[1];
    r = 0;
    for (;;) {
        r ^= p->reversed;
        pnext = p->child[r];
        if (!pnext) break;
        p = pnext;
    }
    flipper4_splay (p);
    return p->value;
#endif /* SAVE_NEIGHBORS */
}

#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_prev (int x)
#else
int CClinkern_flipper_prev (x)
int x;
#endif
{
    splay *p = splay_space+x;
    splay *pnext;
    int r;

    flipper4_splay (p);
    if (p->reversed)
        flipper4_reverse (p);
#ifdef SAVE_NEIGHBORS
    return p->neigh[0]->value;
#else /* SAVE_NEIGHBORS */
    if (p->child[0])
        p = p->child[0];
    r = 0;
    for (;;) {
        r ^= p->reversed;
        pnext = p->child[1 - r];
        if (!pnext) break;
        p = pnext;
    }
    flipper4_splay (p);
    return p->value;
#endif /* SAVE_NEIGHBORS */
}
#endif /* NEXT_PREV_SPLAY */


#ifdef NEXT_PREV_NOSPLAY
#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_next (int x)      /* CClinkern_flipper_next_nspl */
#else
int CClinkern_flipper_next (x)
int x;
#endif
{
    splay *p = splay_space + x;
    splay *pnext;
    int r;

    r = 0;
    for (pnext = p, r = 0; !pnext->mark; pnext = pnext->parent)
        r ^= pnext->reversed;
#ifdef SAVE_NEIGHBORS
    return p->neigh[1-r]->value;
#else /* SAVE_NEIGHBORS */
    pnext = p->child[1 - r];
    if (pnext) {
        p = pnext;
        for (;;) {
            r ^= p->reversed;
            pnext = p->child[r];
            if (!pnext) {
                return p->value;
            }
            p = pnext;
        }
    } else {
        r ^= p->reversed; /* change */
        pnext = p->parent;
        while (!pnext->mark) {
            if (pnext->child[r] == p) {
                return pnext->value;
            }
            r ^= pnext->reversed;
            p = pnext;
            pnext = p->parent;
        }
        for (;;) {
            r ^= p->reversed;
            pnext = p->child[r];
            if (!pnext) {
                return p->value;
            }
            p = pnext;
        }
    }
#endif /* SAVE_NEIGHBORS */
}

#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_prev (int x)      /* CClinkern_flipper_prev_nspl */
#else
int CClinkern_flipper_prev (x)
int x;
#endif
{
    splay *p = splay_space + x;
    splay *pnext;
    int r;

    r = 0;
    for (pnext = p, r = 0; !pnext->mark; pnext = pnext->parent)
        r ^= pnext->reversed;
#ifdef SAVE_NEIGHBORS
    return p->neigh[r]->value;
#else /* SAVE_NEIGHBORS */
    pnext = p->child[r];
    if (pnext) {
        p = pnext;
        for (;;) {
            r ^= p->reversed;
            pnext = p->child[1 - r];
            if (!pnext) {
                return p->value;
            }
            p = pnext;
        }
    } else {
        r ^= p->reversed; /* change */
        pnext = p->parent;
        while (!pnext->mark) {
            if (pnext->child[1 - r] == p) {
                return pnext->value;
            }
            r ^= pnext->reversed;
            p = pnext;
            pnext = p->parent;
        }
        for (;;) {
            r ^= p->reversed;
            pnext = p->child[1 - r];
            if (!pnext) {
                return p->value;
            }
            p = pnext;
        }
    }
#endif /* SAVE_NEIGHBORS */
}
#endif /* NEXT_PREV_NOSPLAY */


#ifdef NEXT_PREV_NOSPLAY1
#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_next (int x)      /* CClinkern_flipper_next_nspl1 */
#else
int CClinkern_flipper_next (x)
int x;
#endif
{
    splay *p = splay_space+x;
    splay *pnext;
    int r;

    r = 0;
    for (pnext = p, r = 0; !pnext->mark; pnext = pnext->parent)
        r ^= pnext->reversed;
#ifdef SAVE_NEIGHBORS
    return p->neigh[1-r]->value;
#else /* SAVE_NEIGHBORS */
    pnext = p->child[1 - r];
    if (pnext) {
        p = pnext;
        for (;;) {
            r ^= p->reversed;
            pnext = p->child[r];
            if (!pnext) {
                flipper4_splay (p);
                return p->value;
            }
            p = pnext;
        }
    } else {
        r ^= p->reversed; /* change */
        pnext = p->parent;
        while (!pnext->mark) {
            if (pnext->child[r] == p) {
                flipper4_splay (pnext);
                return pnext->value;
            }
            r ^= pnext->reversed;
            p = pnext;
            pnext = p->parent;
        }
        for (;;) {
            r ^= p->reversed;
            pnext = p->child[r];
            if (!pnext) {
                flipper4_splay (p);
                return p->value;
            }
            p = pnext;
        }
    }
#endif /* SAVE_NEIGHBORS */
}


#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_prev (int x)      /* CClinkern_flipper_prev_nspl1 */
#else
int CClinkern_flipper_prev (x)
int x;
#endif
{
    splay *p = splay_space+x;
    splay *pnext;
    int r;

    r = 0;
    for (pnext = p, r = 0; !pnext->mark; pnext = pnext->parent)
        r ^= pnext->reversed;
#ifdef SAVE_NEIGHBORS
    return p->neigh[r]->value;
#else /* SAVE_NEIGHBORS */
    pnext = p->child[r];
    if (pnext) {
        p = pnext;
        for (;;) {
            r ^= p->reversed;
            pnext = p->child[1 - r];
            if (!pnext) {
                flipper4_splay (p);
                return p->value;
            }
            p = pnext;
        }
    } else {
        r ^= p->reversed; /* change */
        pnext = p->parent;
        while (!pnext->mark) {
            if (pnext->child[1 - r] == p) {
                flipper4_splay (pnext);
                return pnext->value;
            }
            r ^= pnext->reversed;
            p = pnext;
            pnext = p->parent;
        }
        for (;;) {
            r ^= p->reversed;
            pnext = p->child[1 - r];
            if (!pnext) {
                flipper4_splay (p);
                return p->value;
            }
            p = pnext;
        }
    }
#endif /* SAVE_NEIGHBORS */
}
#endif /* NEXT_PREV_NOSPLAY1 */


#ifdef NEXT_PREV_NOSPLAY2
#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_next (int x)      /* CClinkern_flipper_next_nospl2 */
#else
int CClinkern_flipper_next (x)
int x;
#endif
{
    splay *p = splay_space+x;
    splay *pnext;
    int r;

    flipper4_splay (p);
    if (p->reversed)
        flipper4_reverse (p);
#ifdef SAVE_NEIGHBORS
    return p->neigh[1]->value;
#else /* SAVE_NEIGHBORS */
    if (p->child[1])
        p = p->child[1];
    r = 0;
    for (;;) {
        r ^= p->reversed;
        pnext = p->child[r];
        if (!pnext) break;
        p = pnext;
    }
    return p->value;
#endif /* SAVE_NEIGHBORS */
}


#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_prev (int x)      /* CClinkern_flipper_prev_nospl2 */
#else
int CClinkern_flipper_prev (x)
int x;
#endif
{
    splay *p = splay_space+x;
    splay *pnext;
    int r;

    flipper4_splay (p);
    if (p->reversed)
        flipper4_reverse (p);
#ifdef SAVE_NEIGHBORS
    return p->neigh[0]->value;
#else /* SAVE_NEIGHBORS */
    if (p->child[0])
        p = p->child[0];
    r = 0;
    for (;;) {
        r ^= p->reversed;
        pnext = p->child[1 - r];
        if (!pnext) break;
        p = pnext;
    }
    return p->value;
#endif /* SAVE_NEIGHBORS */
}
#endif /* NEXT_PREV_NOSPLAY2 */

#ifdef CC_PROTOTYPE_ANSI
void CClinkern_flipper_flip (int xprev, int x, int y, int ynext)
#else
void CClinkern_flipper_flip (xprev, x, y, ynext)
int xprev, x, y, ynext;
#endif
{
    splay *px = splay_space + x;
    splay *py = splay_space + y;
    splay *temp, *temp2;

    if (x == y) return;
    if (xprev == ynext) {
        root.child[0]->reversed ^= 1;
        return;
    }

    flipper4_splay (px);
    px->mark = 1;
    flipper4_splay (py);
    px->mark = 0;

    if (px->reversed)
        flipper4_reverse (px);
    if (py->reversed)
        flipper4_reverse (py);
    if (px->child[1] == py) {
#ifdef SAVE_NEIGHBORS
        temp = px->neigh[0];
        temp2 = py->neigh[1];
        px->neigh[0] = px->neigh[1];
        py->neigh[1] = py->neigh[0];
        py->neigh[0] = temp;
        px->neigh[1] = temp2;
        if (temp->neigh[0] == px) temp->neigh[0] = py;
        else temp->neigh[1] = py;
        if (temp2->neigh[0] == py) temp2->neigh[0] = px;
        else temp2->neigh[1] = px;
#endif
        if (py->child[0])
            py->child[0]->reversed ^= 1;
        SWAP (px->child[0], py->child[0], temp);
        if (px->child[0])
            px->child[0]->parent = px;
        if (py->child[0])
            py->child[0]->parent = py;
        px->child[1] = py->child[1];
        if (px->child[1])
            px->child[1]->parent = px;
        py->child[1] = px;
        px->parent = py;
        py->parent = &root;
        root.child[0] = py;
    } else {
#ifdef SAVE_NEIGHBORS
        temp = px->neigh[0];
        temp2 = py->neigh[1];
        py->neigh[1] = temp;
        px->neigh[0] = temp2;
        if (temp->neigh[0] == px) temp->neigh[0] = py;
        else temp->neigh[1] = py;
        if (temp2->neigh[0] == py) temp2->neigh[0] = px;
        else temp2->neigh[1] = px;
#endif
        px->reversed ^= 1;
        if (py->child[1])
            py->child[1]->reversed ^= 1;
    }
}

#ifdef SEQUENCE_SPLAY
#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_sequence (int x, int y, int z)
#else
int CClinkern_flipper_sequence (x, y, z)
int x, y, z;
#endif
{
    splay *px = splay_space + x;
    splay *py = splay_space + y;
    splay *pz = splay_space + z;

    if (y == z || x == z || x == y)
        return 1;

    flipper4_splay (px);
    px->mark = 1;
    flipper4_splay (py);
    py->mark = 1;
    flipper4_splay (pz);
    py->mark = 0;
    px->mark = 0;

    if (px->reversed)
        flipper4_reverse (px);
    if (py->reversed)
        flipper4_reverse (py);

    if (pz->parent == px)
        return px->child[0] == pz;
    else
        return py->child[1] == pz;
}
#endif /* SEQUENCE_SPLAY */

#ifdef SEQUENCE_NOSPLAY
#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_sequence (int x, int y, int z)   /* CClinkern_flipper_sequence_nospl */
#else
int CClinkern_flipper_sequence (x, y, z)
int x, y, z;
#endif
{
    splay *px = splay_space + x;
    splay *py = splay_space + y;
    splay *pz = splay_space + z;

    if (y == z || x == z || x == y)
        return 1;

    flipper4_splay (px);
    px->mark = 1;
    flipper4_splay (pz);
    px->mark = 0;

    if (px->reversed)
        flipper4_reverse (px);
    if (pz->reversed)
        flipper4_reverse (pz);

    for (;;) {
        if (py->parent == px) {
            return px->child[1] == py;
        } else if (py->parent == pz) {
            return pz->child[0] == py;
        } else {
            py = py->parent;
        }
    }
}
#endif /* SEQUENCE_NOSPLAY */

#ifdef CC_PROTOTYPE_ANSI
void CClinkern_flipper_sequence_burst_init (int x, int z)
#else
void CClinkern_flipper_sequence_burst_init (x, z)
int x, z;
#endif
{
    splay *px = splay_space + x;
    splay *pz = splay_space + z;

    flipper4_splay (px);
    px->mark = 1;
    flipper4_splay (pz);
    px->mark = 0;

    if (px->reversed)
        flipper4_reverse (px);
    if (pz->reversed)
        flipper4_reverse (pz);
}

#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_sequence_burst (int x, int y, int z)
#else
int CClinkern_flipper_sequence_burst (x, y, z)
int x, y, z;
#endif
{
    splay *px = splay_space + x;
    splay *py = splay_space + y;
    splay *pz = splay_space + z;

    if (y == z || y == x)
        return 1;

    for (;;) {
        if (py->parent == px) {
            return px->child[1] == py;
        } else if (py->parent == pz) {
            return pz->child[0] == py;
        } else {
            py = py->parent;
        }
    }
}

