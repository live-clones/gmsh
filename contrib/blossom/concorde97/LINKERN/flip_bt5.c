/***************************************************************************/
/*                                                                         */
/* TOUR MAINTANENCE ROUTINES FOR LIN-KERNIGHAN  - Binary Trees (unbalanced)*/
/*                                              - Uses SKIMPY_NULLS,       */
/*                                                NO_CLEAR_TO_ROOT, and    */
/*                                                SEQUENCE_2SPLIT          */
/*                                              - Adds splays              */
/*                                                                         */
/*                               TSP CODE                                  */
/*                                                                         */
/*                                                                         */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook                       */
/*  Date: November 16, 1995                                                */
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
/*                                                                         */
/*   If SAVE_NEIGHBORS is defined, the neighbors of each node are          */
/*   remembered, saving some tree traversals for next and prev.            */
/*                                                                         */
/***************************************************************************/

#include "machdefs.h"
#include "util.h"

#define USE_SPLAY_SEQUENCE
#define USE_SPLAY_FLIPS

typedef struct btree {
    struct btree *parent;
    struct btree *child[2];
    int reversed;
    int mark;
} btree;

#ifdef CC_PROTOTYPE_ANSI

static int
    cycle_fillin(int *x, int i, btree *p, int r);

static btree
    *make_tree (int a, int b, int *cyc),
    *split (btree **left, btree *i, btree **right),
    *find_root (btree *i);

static void
    join (btree *left, btree *i, btree *right);

#else

static int
    cycle_fillin();

static btree
    *make_tree (),
    *split (),
    *find_root ();

static void
    join ();

#endif

#if defined(USE_SPLAY_SEQUENCE) || defined(USE_SPLAY_FLIPS)
#ifdef CC_PROTOTYPE_ANSI

static void
    rotate (btree *x, btree *px),
    splay (btree *x),
    reverse (btree *p);

#else

static void
    rotate (),
    splay (),
    reverse ();

#endif
#endif

#define SWAP(a, b, t) ((t) = (a), (a) = (b), (b) = (t))

static btree *btree_space = (btree *) NULL;
static btree *root = (btree *) NULL;

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

    printf ("SIZE OF BTREE: %d\n", sizeof (btree));
    fflush (stdout);

    btree_space = CC_SAFE_MALLOC (ncount, btree);
    if (!btree_space)
        return 1;

    for (i = 0; i < ncount; i++) {
        btree_space[i].reversed = 0;
        btree_space[i].mark = 0;
    }

    root = make_tree (0, ncount - 1, cyc);
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int cycle_fillin(int *x, int i, btree *p, int r)
#else
static int cycle_fillin(x, i, p, r)
int *x;
int i;
btree *p;
int r;
#endif
{
    if (p == (btree *) NULL)
        return i;

    r ^= p->reversed;
    i = cycle_fillin (x, i, p->child[r], r);
    x[i++] = p - btree_space;
    i = cycle_fillin (x, i, p->child[1 - r], r);

    return i;
}

#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_cycle (int *x)
#else
int CClinkern_flipper_cycle (x)
int *x;
#endif
{
    return cycle_fillin (x, 0, root, 0);
}

#ifdef CC_PROTOTYPE_ANSI
void CClinkern_flipper_finish (void)
#else
void CClinkern_flipper_finish ()
#endif
{
    if (btree_space)
        CC_FREE (btree_space, btree);

    root = (btree *) NULL;
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
    btree *p = btree_space + x;
    btree *pnext;
    int r;

    r = 0;
    for (pnext = p, r = 0; pnext; pnext = pnext->parent)
        r ^= pnext->reversed;
    pnext = p->child[1 - r];
    if (pnext) {
        p = pnext;
        for (;;) {
            r ^= p->reversed;
            pnext = p->child[r];
            if (!pnext) {
                return p - btree_space;
            }
            p = pnext;
        }
    } else {
        r ^= p->reversed;
        pnext = p->parent;
        while (pnext) {
            if (pnext->child[r] == p) {
                return pnext - btree_space;
            }
            r ^= pnext->reversed;
            p = pnext;
            pnext = p->parent;
        }
        for (;;) {
            r ^= p->reversed;
            pnext = p->child[r];
            if (!pnext) {
                return p - btree_space;
            }
            p = pnext;
        }
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_prev (int x)
#else
int CClinkern_flipper_prev (x)
int x;
#endif
{
    btree *p = btree_space + x;
    btree *pnext;
    int r;

    r = 0;
    for (pnext = p, r = 0; pnext; pnext = pnext->parent)
        r ^= pnext->reversed;
    pnext = p->child[r];
    if (pnext) {
        p = pnext;
        for (;;) {
            r ^= p->reversed;
            pnext = p->child[1 - r];
            if (!pnext) {
                return p - btree_space;
            }
            p = pnext;
        }
    } else {
        r ^= p->reversed;
        pnext = p->parent;
        while (pnext) {
            if (pnext->child[1 - r] == p) {
                return pnext - btree_space;
            }
            r ^= pnext->reversed;
            p = pnext;
            pnext = p->parent;
        }
        for (;;) {
            r ^= p->reversed;
            pnext = p->child[1 - r];
            if (!pnext) {
                return p - btree_space;
            }
            p = pnext;
        }
    }
}


#ifdef USE_SPLAY_FLIPS
#ifdef CC_PROTOTYPE_ANSI
void CClinkern_flipper_flip (int xprev, int x, int y, int ynext)
#else
void CClinkern_flipper_flip (xprev, x, y, ynext)
int xprev, x, y, ynext;
#endif
{
    btree *px = btree_space + x;
    btree *py = btree_space + y;
    btree *temp;

    if (x == y) return;
    if (xprev == ynext) {
        root->reversed ^= 1;
        return;
    }

    splay (px);
    px->mark = 1;
    splay (py);
    px->mark = 0;

    splay (px);
    px->mark = 1;
    splay (py);
    px->mark = 0;

    if (px->reversed)
        reverse (px);
    if (py->reversed)
        reverse (py);
    if (px->child[1] == py) {
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
        py->parent = (btree *) NULL;
        root = py;
    } else {
        px->reversed ^= 1;
        py->child[1]->reversed ^= 1;
    }
}

#else

#ifdef CC_PROTOTYPE_ANSI
void CClinkern_flipper_flip (int xprev, int x, int y, int ynext)
#else
void CClinkern_flipper_flip (xprev, x, y, ynext)
int xprev, x, y, ynext;
#endif
{
    btree *px = btree_space + x;
    btree *py = btree_space + y;
    btree *a, *b, *c, *d;

    if (x == y) return;
    if (xprev == ynext) {
        root->reversed ^= 1;
        return;
    }

    split (&a, px, &b);
    if (split (&c, py, &d) == a) { /* c y d x b ==> b^r x d y c^r */
        if (b) b->reversed ^= 1;
        if (c) c->reversed ^= 1;
        join (d,py,c);
        join (b,px,py);
        root = px;
    } else { /* a x c y d  ==> a y c^r x d */
        if (c) c->reversed ^= 1;
        join (a,py,c);
        join (py,px,d);
        root = px;
    }
}
#endif

#ifdef USE_SPLAY_SEQUENCE
#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_sequence (int x, int y, int z)
#else
int CClinkern_flipper_sequence (x, y, z)
int x, y, z;
#endif
{
    btree *px = btree_space + x;
    btree *py = btree_space + y;
    btree *pz = btree_space + z;

    if (y == z || x == z || x == y)
        return 1;

    splay (px);
    px->mark = 1;
    splay (pz);
    px->mark = 0;

    if (px->reversed)
        reverse (px);
    if (pz->reversed)
        reverse (pz);

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

#else

#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_sequence (int x, int y, int z)
#else
int CClinkern_flipper_sequence (x, y, z)
int x, y, z;
#endif
{
    btree *px = btree_space + x;
    btree *py = btree_space + y;
    btree *pz = btree_space + z;
    btree *a, *b, *c, *d;
    btree *r;

    if (y == z || x == z || x == y) {
        return 1;
    }

    split (&a, px, &b);
    if (split (&c, pz, &d) == a) { /* c z d x b */
        r = find_root (py);
        join (c,pz,d);
        join (pz,px,b);
        root = px;
        return (r!=d);
    } else { /* a x c z d */
        r = find_root (py);
        join (c,pz,d);
        join (a,px,pz);
        root = px;
        return (r==c);
    }
}
#endif

/***************************************************************************/
/*                                                                         */
/*                REVERSIBLE BINARY TREE ROUTINES (UNBALANCED)             */
/*                                                                         */
/*                               TSP CODE                                  */
/*                                                                         */
/*                                                                         */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook                       */
/*  Date: November 16, 1995                                                */
/*                                                                         */
/*                                                                         */
/*   btree *make_tree (int a, int b, int *cyc)                             */
/*     builds a binary tree for cyc[a..b] and returns the root.            */
/*     This assumes that btree_space has been allocated and initialized.   */
/*   void join (btree *left, btree *i, btree *right)                       */
/*     makes left and right the children of i.                             */
/*   btree *split (btree **left, btree *i, btree **right)                  */
/*     splits the tree into *left (nodes < i) and *right (nodes > i)       */
/*     returns the root of the (old) tree containing i.                    */
/*   btree *find_root (btree *i)                                           */
/*     returns the root of the tree containing i                           */
/*                                                                         */
/***************************************************************************/

#ifdef CC_PROTOTYPE_ANSI
static btree *make_tree (int a, int b, int *cyc)
#else
static btree *make_tree (a, b, cyc)
int a;
int b;
int *cyc;
#endif
{
    btree *p;
    int center;

    if (b < a)
        return (btree *) NULL;

    center = (a + b)/2;
    p = btree_space + cyc[center];
    p->child[0] = make_tree (a, center-1, cyc);
    if (p->child[0]) p->child[0]->parent = p;
    p->child[1] = make_tree (center+1, b, cyc);
    if (p->child[1]) p->child[1]->parent = p;
    return p;
}

#ifdef CC_PROTOTYPE_ANSI
static void join (btree *left, btree *i, btree *right)
#else
static void join (left, i, right)
btree *left;
btree *i;
btree *right;
#endif
{
    if (left) left->parent = i;
    if (right) right->parent = i;
    i->child[0] = left;
    i->child[1] = right;
    i->reversed = 0;
    i->parent = (btree *) NULL;
}

#ifdef CC_PROTOTYPE_ANSI
static btree *split (btree **left, btree *i, btree **right)
#else
static btree *split (left, i, right)
btree **left;
btree *i;
btree **right;
#endif
{
    btree *l;
    btree *r;
    btree *p;

    if (i->reversed) {
        l = i->child[1];
        r = i->child[0];
        if (l) l->reversed ^= 1;
        if (r) r->reversed ^= 1;
    } else {
        l = i->child[0];
        r = i->child[1];
    }

    while ((p = i->parent) != (btree *) NULL) {
        if (p->child[0] == i) {
            p->child[0] = r;
            if (r) r->parent = p;
            if (p->reversed) {
                r = l;
                l = p;
                if (r) r->reversed ^= 1;
            } else {
                r = p;
            }
        } else {
            p->child[1] = l;
            if (l) l->parent = p;
            if (p->reversed) {
                l = r;
                r = p;
                if (l) l->reversed ^= 1;
            } else {
                l = p;
            }
        }
        i = p;
    }
    if (l) l->parent = (btree *) NULL;
    if (r) r->parent = (btree *) NULL;
    *left = l;
    *right = r;

    return i;
}

#ifdef CC_PROTOTYPE_ANSI
static btree *find_root (btree *i)
#else
static btree *find_root (i)
btree *i;
#endif
{
    while (i->parent) i = i->parent;
    return i;
}


/**************************** SPLAY STUFF ****************************/

#ifdef CC_PROTOTYPE_ANSI
static void rotate (btree *x, btree *px)
#else
static void rotate (x, px)
btree *x, *px;
#endif
{
    btree *b;

    if (px->child[0] == x) {
        b = x->child[1];
        if (b)
            b->parent = px;
        x->child[1] = px;
        x->parent = px->parent;
        if (x->parent) {
            if (x->parent->child[0] == px) {
                x->parent->child[0] = x;
            } else {
                x->parent->child[1] = x;
            }
        }
        px->child[0] = b;
        px->parent = x;
    } else {
        b = x->child[0];
        if (b)
            b->parent = px;
        x->child[0] = px;
        x->parent = px->parent;
        if (x->parent) {
            if (x->parent->child[0] == px) {
                x->parent->child[0] = x;
            } else {
                x->parent->child[1] = x;
            }
        }
        px->child[1] = b;
        px->parent = x;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void splay (btree *x)
#else
static void splay (x)
btree *x;
#endif
{
    btree *px;
    btree *ppx;

    for (;;) {
        px = x->parent;
        if (!px) {
            root = x;
            return;
        }
        if (px->mark)
            return;
        ppx = px->parent;
        if (!ppx) {
            if (px->reversed)
                reverse (px);
            if (x->reversed)
                reverse (x);
            rotate (x, px);
            root = x;
            return;
        }
        if (ppx->mark) {
            if (px->reversed)
                reverse (px);
            if (x->reversed)
                reverse (x);
            rotate (x, px);
            return;
        }
        if (ppx->reversed)
            reverse (ppx);
        if (px->reversed)
            reverse (px);
        if (x->reversed)
            reverse (x);
        if (ppx->child[0] == px) {
            if (px->child[0] == x) {
                rotate (px, ppx);
                rotate (x, px);
            } else {
                rotate (x, px);
                rotate (x, ppx);
            }
        } else {
            if (px->child[1] == x) {
                rotate (px, ppx);
                rotate (x, px);
            } else {
                rotate (x, px);
                rotate (x, ppx);
            }
        }
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void reverse (btree *p)
#else
static void reverse (p)
btree *p;
#endif
{
    btree *t;

    SWAP(p->child[0], p->child[1], t);
    if (p->child[0]) p->child[0]->reversed ^= 1;
    if (p->child[1]) p->child[1]->reversed ^= 1;
    p->reversed ^= 1;
}
