/***************************************************************************/
/*                                                                         */
/* TOUR MAINTANENCE ROUTINES FOR LIN-KERNIGHAN  - Binary Trees (unbalanced)*/
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

/* #define SAVE_NEIGHBORS */
#define INLINE_CLEAR_TO_ROOT

typedef struct btree {
    struct btree *parent;
    struct btree *child[2];
#ifdef INLINE_CLEAR_TO_ROOT
    struct btree *next;
#endif
#ifdef SAVE_NEIGHBORS
    struct btree *neigh[2];
#endif
    int reversed;
    int value;
} btree;

#ifdef CC_PROTOTYPE_ANSI

static int
    cycle_fillin(int *x, int i, btree *p, int r);

static btree
    *make_tree (int a, int b, int *cyc),
    *split (btree **left, btree *i, btree **right);

static void
    join (btree *left, btree *i, btree *right),
    reverse (btree *p),
    clearrev_toroot (btree *p);

#else

static int
    cycle_fillin();

static btree
    *make_tree (),
    *split ();

static void
    join (),
    reverse (),
    clearrev_toroot ();

#endif

#define SWAP(a, b, t) ((t) = (a), (a) = (b), (b) = (t))

static btree *btree_space = (btree *) NULL;
static int btree_size;
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

/*
    printf ("Flipper flags:");
#ifdef SAVE_NEIGHBORS
    printf (" SAVE_NEIGHBORS");
#else
    printf (" !SAVE_NEIGHBORS");
#endif
*/

    btree_space = CC_SAFE_MALLOC (ncount, btree);
    btree_size = ncount;
    if (!btree_space)
        return 1;

    for (i = 0; i < ncount; i++) {
        btree_space[i].reversed = 0;
        btree_space[i].value = i;
#ifdef SAVE_NEIGHBORS
        if (i==0) {
            btree_space[cyc[0]].neigh[0] = &btree_space[cyc[ncount-1]];
            btree_space[cyc[ncount-1]].neigh[1] = &btree_space[cyc[0]];
        } else {
            btree_space[cyc[i]].neigh[0] = &btree_space[cyc[i-1]];
            btree_space[cyc[i-1]].neigh[1] = &btree_space[cyc[i]];
        }
#endif
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
    if (!p)
        return i;

    r ^= p->reversed;
    i = cycle_fillin (x, i, p->child[r], r);
    x[i++] = p->value;
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
    CC_IFFREE (btree_space, btree);

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
        r ^= p->reversed;
        pnext = p->parent;
        while (pnext) {
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
    btree *p = btree_space + x;
    btree *pnext;
    int r;

    r = 0;
    for (pnext = p, r = 0; pnext; pnext = pnext->parent)
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
        r ^= p->reversed;
        pnext = p->parent;
        while (pnext) {
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

#ifdef CC_PROTOTYPE_ANSI
void CClinkern_flipper_flip (int xprev, int x, int y, int ynext)
#else
void CClinkern_flipper_flip (xprev, x, y, ynext)
int xprev, x, y, ynext;
#endif
{
    btree *px = btree_space + x;
    btree *py = btree_space + y;
    btree *temp, *temp2;
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
}

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
    btree *a, *b, *c, *d, *e, *f;
    btree *r;

    if (y == z || x == z || x == y)
        return 1;

    split (&a, px, &b);
    if (split (&c, py, &d) == a) { /* c y d x b */
        r = split (&e, pz, &f);
        if (r == c) { /* e z f y d x b */
            join (e, pz, f);
            join (d, px, b);
            join (pz, py, px);
            root = py;
            return 0;
        } else if (r == d) { /* c y e z f x b */
            join (c, py, e);
            join (f, px, b);
            join (py, pz, px);
            root = pz;
            return 1;
        } else { /* c y d x e z f */
            join (c, py, d);
            join (e, pz, f);
            join (py, px, pz);
            root = px;
            return 0;
        }
    } else { /* a x c y d */
        r = split (&e, pz, &f);
        if (r == a) { /* e z f x c y d */
            join (e, pz, f);
            join (c, py, d);
            join (pz, px, py);
            root = px;
            return 1;
        } else if (r == c) { /* a x e z f y d */
            join (a, px, e);
            join (f, py, d);
            join (px, pz, py);
            root = pz;
            return 0;
        } else { /* a x c y e z f */
            join (a, px, c);
            join (e, pz, f);
            join (px, py, pz);
            root = py;
            return 1;
        }
    }
}

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
/*   void reverse (btree *p)                                               */
/*     toggles the reversal bit of node p (and fixes the tree).            */
/*   void clearrev_toroot (btree *p)                                       */
/*     clears the reversal bits on the path from p to the root (and fixes  */
/*     the tree).                                                          */
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
    if ((p->child[0] = make_tree (a, center-1, cyc)) != (btree *) NULL)
        p->child[0]->parent = p;
    if ((p->child[1] = make_tree (center+1, b, cyc)) != (btree *) NULL)
        p->child[1]->parent = p;
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
    btree *isave = i;

    clearrev_toroot (i);
    l = i->child[0];
    r = i->child[1];
    i->child[0] = (btree *) NULL;
    i->child[1] = (btree *) NULL;

    while ((p = i->parent) != (btree *) NULL) {
        if (p->child[0] == i) {
            p->child[0] = r;
            if (r) r->parent = p;
            r = p;
        } else {
            p->child[1] = l;
            if (l) l->parent = p;
            l = p;
        }
        i = p;
    }
    if (l) l->parent = (btree *) NULL;
    if (r) r->parent = (btree *) NULL;
    *left = l;
    *right = r;
    if (isave) isave->parent = (btree *) NULL;

    return i;
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
#ifdef SAVE_NEIGHBORS
    SWAP (p->neigh[0], p->neigh[1], t);
#endif
}

#ifdef CC_PROTOTYPE_ANSI
static void clearrev_toroot (btree *p)
#else
static void clearrev_toroot (p)
btree *p;
#endif
{
#ifndef INLINE_CLEAR_TO_ROOT
    if (p->parent) clearrev_toroot (p->parent);
    if (p->reversed) reverse (p);
#else
    p->next = (btree *) NULL;
    while (p->parent) {
        p->parent->next = p;
        p = p->parent;
    }
    while (p) {
        if (p->reversed) reverse (p);
        p = p->next;
    }
#endif
}



