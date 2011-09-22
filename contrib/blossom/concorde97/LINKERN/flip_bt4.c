/***************************************************************************/
/*                                                                         */
/* TOUR MAINTANENCE ROUTINES FOR LIN-KERNIGHAN  - Binary Trees (unbalanced)*/
/*                                              - added dummy children     */
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

/* #define TRACE */
/* #define NEIGHTRACE */
#define SAVE_NEIGHBORS
/* #define REPORT_DEPTH */
#define DUMMY_LEAF
#define NO_CLEAR_TO_ROOT
/* #define INLINE_CLEAR_TO_ROOT */
/* #define INLINE_CLEAR_TO_ROOT2 */
#define SKIMPY_NULLS
/* #define MUNCHED_SEQUENCE_CODE */
#define SEQUENCE_2SPLIT
#define UGLY_SPLIT

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
    *split (btree **left, btree *i, btree **right),
    *find_root (btree *i);

static void
    join (btree *left, btree *i, btree *right),
    reverse (btree *p),
    clearrev_toroot (btree *p);

#else

static int
    cycle_fillin();

static btree
    *make_tree (),
    *split (),
    *find_root ();

static void
    join (),
    reverse (),
    clearrev_toroot ();

#endif

#ifdef    REPORT_DEPTH

static double probecount = 1.0;
static double probedepth = 1.0;

#ifdef CC_PROTOTYPE_ANSI
static void
    find_depth (int x);
#else
static void
    find_depth ();
#endif

#endif /* REPORT_DEPTH */

#define SWAP(a, b, t) ((t) = (a), (a) = (b), (b) = (t))

static btree *btree_space = (btree *) NULL;
static int btree_size;
static btree *root = (btree *) NULL;
#ifdef DUMMY_LEAF
static btree dummy_leaf;
#endif

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

    printf ("Flipper flags:");
#ifdef SAVE_NEIGHBORS
    printf (" SAVE_NEIGHBORS");
#endif
#ifdef DUMMY_LEAF
    printf (" DUMMY_LEAF");
#endif
#ifdef NO_CLEAR_TO_ROOT
    printf (" NO_CLEAR_TO_ROOT");
#else
#ifdef INLINE_CLEAR_TO_ROOT
    printf (" INLINE_CLEAR_TO_ROOT");
#else
#ifdef INLINE_CLEAR_TO_ROOT2
    printf (" INLINE_CLEAR_TO_ROOT2");
#endif
#endif
#endif
#ifdef SKIMPY_NULLS
    printf (" SKIMPY_NULLS");
#endif
#ifdef SEQUENCE_2SPLIT
    printf (" SEQUENCE_2SPLIT");
#else
#ifdef MUNCHED_SEQUENCE_CODE
    printf (" MUNCHED_SEQUENCE_CODE");
#endif
#endif
#ifdef UGLY_SPLIT
    printf (" UGLY_SPLIT");
#endif
    printf ("\n");
    fflush (stdout);

    btree_space = CC_SAFE_MALLOC (ncount, btree);
    btree_size = ncount;
    if (!btree_space)
        return 1;

#ifdef TRACE
    printf ("init:");
    for (i=0; i<ncount; i++) {
        printf (" %d", cyc[i]);
    }
    printf ("\n");
    fflush (stdout);
#endif /* TRACE */
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
#ifdef DUMMY_LEAF
    if (p == &dummy_leaf)
#else
    if (p == (btree *) NULL)
#endif
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
#ifdef REPORT_DEPTH
    printf ("Number of Probes: %.0f   Average Depth: %.2f\n",
             probecount, probedepth / probecount);
    fflush (stdout);
#endif
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

#ifdef REPORT_DEPTH
#ifdef CC_PROTOTYPE_ANSI
static void find_depth (int x)
#else
static void find_depth (x)
int x;
#endif
{
    btree *q = btree_space + x;

    probecount += 1.0;
    while (q) {
        probedepth += 1.0;
        q = q->parent;
    }
}
#endif


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

#ifdef TRACE
    printf ("next %d", x);
    fflush (stdout);
#endif /* TRACE */
#ifdef REPORT_DEPTH
    find_depth (x);
#endif

    r = 0;
    for (pnext = p, r = 0; pnext; pnext = pnext->parent)
        r ^= pnext->reversed;
#ifdef SAVE_NEIGHBORS
#ifdef TRACE
    printf ("==> %d (%d)\n", p->neigh[1-r] - btree_space, p->neigh[1-r]->value);
    fflush (stdout);
#endif /* TRACE */
    return p->neigh[1-r]->value;
#else /* SAVE_NEIGHBORS */
    pnext = p->child[1 - r];
#ifdef DUMMY_LEAF
    if (pnext != &dummy_leaf) {
#else
    if (pnext) {
#endif
        p = pnext;
        for (;;) {
            r ^= p->reversed;
            pnext = p->child[r];
#ifdef DUMMY_LEAF
            if (pnext == &dummy_leaf) {
#else
            if (!pnext) {
#endif
#ifdef TRACE
                printf ("==> %d (%d)\n", p - btree_space, p->value);
                fflush (stdout);
#endif /* TRACE */
                return p->value;
            }
            p = pnext;
        }
    } else {
        r ^= p->reversed;
        pnext = p->parent;
        while (pnext) {
            if (pnext->child[r] == p) {
#ifdef TRACE
                printf ("==> %d (%d)\n", pnext - btree_space, pnext->value);
                fflush (stdout);
#endif /* TRACE */
                return pnext->value;
            }
            r ^= pnext->reversed;
            p = pnext;
            pnext = p->parent;
        }
        for (;;) {
            r ^= p->reversed;
            pnext = p->child[r];
#ifdef DUMMY_LEAF
            if (pnext == &dummy_leaf) {
#else
            if (!pnext) {
#endif
#ifdef TRACE
                printf ("==> %d (%d)\n", p - btree_space, p->value);
                fflush (stdout);
#endif /* TRACE */
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

#ifdef TRACE
    printf ("prev %d", x);
    fflush (stdout);
#endif /* TRACE */
#ifdef REPORT_DEPTH
    find_depth (x);
#endif

    r = 0;
    for (pnext = p, r = 0; pnext; pnext = pnext->parent)
        r ^= pnext->reversed;
#ifdef SAVE_NEIGHBORS
#ifdef TRACE
    printf ("==> %d (%d)\n", p->neigh[r] - btree_space, p->neigh[r]->value);
    fflush (stdout);
#endif /* TRACE */
    return p->neigh[r]->value;
#else /* SAVE_NEIGHBORS */
    pnext = p->child[r];
#ifdef DUMMY_LEAF
    if (pnext != &dummy_leaf) {
#else
    if (pnext) {
#endif
        p = pnext;
        for (;;) {
            r ^= p->reversed;
            pnext = p->child[1 - r];
#ifdef DUMMY_LEAF
            if (pnext == &dummy_leaf) {
#else
            if (!pnext) {
#endif
#ifdef TRACE
                printf ("==> %d (%d)\n", p - btree_space, p->value);
                fflush (stdout);
#endif /* TRACE */
                return p->value;
            }
            p = pnext;
        }
    } else {
        r ^= p->reversed;
        pnext = p->parent;
        while (pnext) {
            if (pnext->child[1 - r] == p) {
#ifdef TRACE
                printf ("==> %d (%d)\n", pnext - btree_space, pnext->value);
                fflush (stdout);
#endif /* TRACE */
                return pnext->value;
            }
            r ^= pnext->reversed;
            p = pnext;
            pnext = p->parent;
        }
        for (;;) {
            r ^= p->reversed;
            pnext = p->child[1 - r];
#ifdef DUMMY_LEAF
            if (pnext == &dummy_leaf) {
#else
            if (!pnext) {
#endif
#ifdef TRACE
                printf ("==> %d (%d)\n", p - btree_space, p->value);
                fflush (stdout);
#endif /* TRACE */
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
#ifdef SAVE_NEIGHBORS
    btree *temp, *temp2;
#endif
    btree *a, *b, *c, *d;

#ifdef TRACE
    printf ("flip %d-%d %d-%d\n", xprev, x, y, ynext);
    fflush (stdout);
#endif /* TRACE */

#ifdef REPORT_DEPTH
    find_depth (x);
    find_depth (y);
#endif

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
#ifdef NEIGHTRACE
    printf ("neigh before:");
    printf (" %d-%d-%d", px->neigh[0]-btree_space,px-btree_space,px->neigh[1]-btree_space);
    printf (" %d-%d-%d", py->neigh[0]-btree_space,py-btree_space,py->neigh[1]-btree_space);
    printf (" %d-%d-%d", px->neigh[0]->neigh[0]-btree_space,px->neigh[0]-btree_space,px->neigh[0]->neigh[1]-btree_space);
    printf (" %d-%d-%d", px->neigh[1]->neigh[0]-btree_space,px->neigh[1]-btree_space,px->neigh[1]->neigh[1]-btree_space);
    printf (" %d-%d-%d", py->neigh[0]->neigh[0]-btree_space,py->neigh[0]-btree_space,py->neigh[0]->neigh[1]-btree_space);
    printf (" %d-%d-%d", py->neigh[1]->neigh[0]-btree_space,py->neigh[1]-btree_space,py->neigh[1]->neigh[1]-btree_space);
    printf ("\n");
    fflush (stdout);
#endif

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
#ifdef NEIGHTRACE
    printf ("neigh after:");
    printf (" %d-%d-%d", px->neigh[0]-btree_space,px-btree_space,px->neigh[1]-btree_space);
    printf (" %d-%d-%d", py->neigh[0]-btree_space,py-btree_space,py->neigh[1]-btree_space);
    printf (" %d-%d-%d", px->neigh[0]->neigh[0]-btree_space,px->neigh[0]-btree_space,px->neigh[0]->neigh[1]-btree_space);
    printf (" %d-%d-%d", px->neigh[1]->neigh[0]-btree_space,px->neigh[1]-btree_space,px->neigh[1]->neigh[1]-btree_space);
    printf (" %d-%d-%d", py->neigh[0]->neigh[0]-btree_space,py->neigh[0]-btree_space,py->neigh[0]->neigh[1]-btree_space);
    printf (" %d-%d-%d", py->neigh[1]->neigh[0]-btree_space,py->neigh[1]-btree_space,py->neigh[1]->neigh[1]-btree_space);
    printf ("\n");
    fflush (stdout);
#endif
#endif
}

#if defined(MUNCHED_SEQUENCE_CODE) || defined(SEQUENCE_2SPLIT)

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

#ifdef TRACE
    printf ("sequence %d %d %d", x, y, z);
    fflush (stdout);
#endif /* TRACE */
#ifdef REPORT_DEPTH
    find_depth (x);
    find_depth (y);
    find_depth (z);
#endif

    if (y == z || x == z || x == y) {
#ifdef TRACE
        printf (" ==> 1\n");
        fflush (stdout);
#endif /* TRACE */
        return 1;
    }

    split (&a, px, &b);
    if (split (&c, pz, &d) == a) { /* c z d x b */
#ifdef SEQUENCE_2SPLIT
        r = find_root (py);
        join (c,pz,d);
        join (pz,px,b);
        root = px;
#ifdef TRACE
        printf (" ==> %d\n", r!=d);
        fflush (stdout);
#endif /* TRACE */
        return (r!=d);
#else /* SEQUENCE_2SPLIT */
        r = split (&e, py, &f);
        if (r == c) { /* e y f z d x b */
            join (e, py, f);
            join (py, pz, d);
            join (pz, px, b);
            root = px;
#ifdef TRACE
            printf (" ==> 1\n");
            fflush (stdout);
#endif /* TRACE */
            return 1;
        } else if (r == d) { /* c z e y f x b */
            join (c, pz, e);
            join (pz, py, f);
            join (py, px, b);
            root = px;
#ifdef TRACE
            printf (" ==> 0\n");
            fflush (stdout);
#endif /* TRACE */
            return 0;
        } else { /* c z d x e y f */
            join (c, pz, d);
            join (e, py, f);
            join (pz, px, py);
            root = px;
#ifdef TRACE
            printf (" ==> 1\n");
            fflush (stdout);
#endif /* TRACE */
            return 1;
        }
#endif /* SEQUENCE_2SPLIT */
    } else { /* a x c z d */
#ifdef SEQUENCE_2SPLIT
        r = find_root (py);
        join (c,pz,d);
        join (a,px,pz);
        root = px;
#ifdef TRACE
        printf (" ==> %d\n", r==c);
        fflush (stdout);
#endif /* TRACE */
        return (r==c);
#else /* SEQUENCE_2SPLIT */
        r = split (&e, py, &f);
        if (r == a) { /* e y f x c z d */
            join (e, py, f);
            join (c, pz, d);
            join (py, px, pz);
            root = px;
#ifdef TRACE
            printf (" ==> 0\n");
            fflush (stdout);
#endif /* TRACE */
            return 0;
        } else if (r == c) { /* a x e y f z d */
            join (e, py, f);
            join (py, pz, d);
            join (a, px, pz);
            root = px;
#ifdef TRACE
            printf (" ==> 1\n");
            fflush (stdout);
#endif /* TRACE */
            return 1;
        } else { /* a x c z e y f */
            join (e, py, f);
            join (c, pz, py);
            join (a, px, pz);
            root = px;
#ifdef TRACE
            printf (" ==> 0\n");
            fflush (stdout);
#endif /* TRACE */
            return 0;
        }
#endif /* SEQUENCE_2SPLIT */
    }
}

#else /* defined(MUNCHED_SEQUENCE_CODE) || defined(SEQUENCE_2SPLIT) */

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

#ifdef TRACE
    printf ("sequence %d %d %d", x, y, z);
    fflush (stdout);
#endif /* TRACE */
#ifdef REPORT_DEPTH
    find_depth (x);
    find_depth (y);
    find_depth (z);
#endif

    if (y == z || x == z || x == y) {
#ifdef TRACE
        printf (" ==> 1\n");
        fflush (stdout);
#endif /* TRACE */
        return 1;
    }

    split (&a, px, &b);
    if (split (&c, py, &d) == a) { /* c y d x b */
        r = split (&e, pz, &f);
        if (r == c) { /* e z f y d x b */
            join (e, pz, f);
            join (d, px, b);
            join (pz, py, px);
            root = py;
#ifdef TRACE
            printf (" ==> 0\n");
            fflush (stdout);
#endif /* TRACE */
            return 0;
        } else if (r == d) { /* c y e z f x b */
            join (c, py, e);
            join (f, px, b);
            join (py, pz, px);
            root = pz;
#ifdef TRACE
            printf (" ==> 1\n");
            fflush (stdout);
#endif /* TRACE */
            return 1;
        } else { /* c y d x e z f */
            join (c, py, d);
            join (e, pz, f);
            join (py, px, pz);
            root = px;
#ifdef TRACE
            printf (" ==> 0\n");
            fflush (stdout);
#endif /* TRACE */
            return 0;
        }
    } else { /* a x c y d */
        r = split (&e, pz, &f);
        if (r == a) { /* e z f x c y d */
            join (e, pz, f);
            join (c, py, d);
            join (pz, px, py);
            root = px;
#ifdef TRACE
            printf (" ==> 1\n");
            fflush (stdout);
#endif /* TRACE */
            return 1;
        } else if (r == c) { /* a x e z f y d */
            join (a, px, e);
            join (f, py, d);
            join (px, pz, py);
            root = pz;
#ifdef TRACE
            printf (" ==> 0\n");
            fflush (stdout);
#endif /* TRACE */
            return 0;
        } else { /* a x c y e z f */
            join (a, px, c);
            join (e, pz, f);
            join (px, py, pz);
            root = py;
#ifdef TRACE
            printf (" ==> 1\n");
            fflush (stdout);
#endif /* TRACE */
            return 1;
        }
    }
}

#endif /* defined(MUNCHED_SEQUENCE_CODE) || defined(SEQUENCE_2SPLIT) */

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
/*   btree *find_root (btree *i)                                           */
/*     returns the root of the tree containing i                           */
/*                                                                         */
/***************************************************************************/

#ifdef TRACE
void dump_tree (btree *r, int rev)
{
    if (!r) {
        printf ("()");
        return;
    }
    rev ^= r->reversed;
    putchar ('(');
    if (r->child[rev]) dump_tree (r->child[rev], rev);
    printf (" %d%s ", r-btree_space, r->reversed?"R":"");
    if (r->child[1-rev]) dump_tree (r->child[1-rev], rev);
    putchar (')');
}
#endif

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
#ifdef  DUMMY_LEAF
        return &dummy_leaf;
#else
        return (btree *) NULL;
#endif

    center = (a + b)/2;
    p = btree_space + cyc[center];
    p->child[0] = make_tree (a, center-1, cyc);
#ifdef  DUMMY_LEAF
    p->child[0]->parent = p;
#else
    if (p->child[0]) p->child[0]->parent = p;
#endif
    p->child[1] = make_tree (center+1, b, cyc);
#ifdef  DUMMY_LEAF
    p->child[1]->parent = p;
#else
    if (p->child[1]) p->child[1]->parent = p;
#endif
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
#ifdef TRACE
    printf ("join ");
    dump_tree (left, 0);
    printf (" %d ", i - btree_space);
    dump_tree (right, 0);
    printf ("\n");
    fflush (stdout);
#endif /* TRACE */
#ifdef DUMMY_LEAF
    left->parent = i;
    right->parent = i;
#else
    if (left) left->parent = i;
    if (right) right->parent = i;
#endif
    i->child[0] = left;
    i->child[1] = right;
    i->reversed = 0;
#ifdef SKIMPY_NULLS
    i->parent = (btree *) NULL;
#endif
#ifdef TRACE
    printf ("==> ");
    dump_tree (i, 0);
    printf ("\n");
    fflush (stdout);
#endif /* TRACE */
}

#ifdef UGLY_SPLIT

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
#if defined(SAVE_NEIGHBORS) && defined(NO_CLEAR_TO_ROOT)
    int rev = i->reversed;
    btree *t;
#endif

#ifdef TRACE
    printf ("split %d ", i - btree_space);
    dump_tree (find_root (i), 0);
    printf ("\n");
    fflush (stdout);
#endif /* TRACE */

#ifdef NO_CLEAR_TO_ROOT
    if (i->reversed) {
        l = i->child[1];
        r = i->child[0];
#ifdef DUMMY_LEAF
        l->reversed ^= 1;
        r->reversed ^= 1;
#else
        if (l) l->reversed ^= 1;
        if (r) r->reversed ^= 1;
#endif
#ifndef SKIMPY_NULLS
        i->reversed = 0;
#endif
    } else {
        l = i->child[0];
        r = i->child[1];
    }
#else
    clearrev_toroot (i);
    l = i->child[0];
    r = i->child[1];
#endif

#ifndef SKIMPY_NULLS
#ifdef  DUMMY_LEAF
    i->child[0] = &dummy_leaf;
    i->child[1] = &dummy_leaf;
#else
    i->child[0] = (btree *) NULL;
    i->child[1] = (btree *) NULL;
#endif
#endif

    p = i->parent;
    if (!p) {p = i; goto FINISH;}
    else if (p->child[0] == i) goto START_0;
    else goto START_1;

I_IS_L:
    if (p->parent == (btree *) NULL) goto FINISH;
    p = p->parent;
    if (p->child[1] == l) {
#ifdef NO_CLEAR_TO_ROOT
        if (p->reversed) {
            l = r;
            r = p;
#ifdef DUMMY_LEAF
            l->reversed ^= 1;
#else
            if (l) l->reversed ^= 1;
#endif
#ifdef SAVE_NEIGHBORS
            rev ^= 1;
#endif
            goto I_IS_R;
        } else {
            l = p;
            goto I_IS_L;
        }
#else
        l = p;
        goto I_IS_L;
#endif
    } else {
START_0:
        p->child[0] = r;
#ifdef DUMMY_LEAF
        r->parent = p;
#else
        if (r) r->parent = p;
#endif
#ifdef NO_CLEAR_TO_ROOT
        if (p->reversed) {
            r = l;
            l = p;
#ifdef DUMMY_LEAF
            r->reversed ^= 1;
#else
            if (r) r->reversed ^= 1;
#endif
#ifdef SAVE_NEIGHBORS
            rev ^= 1;
#endif
            goto I_IS_L;
        } else {
            r = p;
            goto I_IS_R;
        }
#else
        r = p;
        goto I_IS_R;
#endif
    }
I_IS_R:
    if (p->parent == (btree *) NULL) goto FINISH;
    p = p->parent;
    if (p->child[0] == r) {
#ifdef NO_CLEAR_TO_ROOT
        if (p->reversed) {
            r = l;
            l = p;
#ifdef DUMMY_LEAF
            r->reversed ^= 1;
#else
            if (r) r->reversed ^= 1;
#endif
#ifdef SAVE_NEIGHBORS
            rev ^= 1;
#endif
            goto I_IS_L;
        } else {
            r = p;
            goto I_IS_R;
        }
#else
        r = p;
        goto I_IS_R;
#endif
    } else {
START_1:
        p->child[1] = l;
#ifdef DUMMY_LEAF
        l->parent = p;
#else
        if (l) l->parent = p;
#endif
#ifdef NO_CLEAR_TO_ROOT
        if (p->reversed) {
            l = r;
            r = p;
#ifdef DUMMY_LEAF
            l->reversed ^= 1;
#else
            if (l) l->reversed ^= 1;
#endif
#ifdef SAVE_NEIGHBORS
            rev ^= 1;
#endif
            goto I_IS_R;
        } else {
            l = p;
            goto I_IS_L;
        }
#else
        l = p;
        goto I_IS_L;
#endif
    }

FINISH:
#ifdef DUMMY_LEAF
    l->parent = (btree *) NULL;
    r->parent = (btree *) NULL;
#else
    if (l) l->parent = (btree *) NULL;
    if (r) r->parent = (btree *) NULL;
#endif
    *left = l;
    *right = r;
#ifndef SKIMPY_NULLS
    i->parent = (btree *) NULL;
#endif
#if defined(SAVE_NEIGHBORS) && defined(NO_CLEAR_TO_ROOT)
    if (rev) SWAP (i->neigh[0], i->neigh[1], t);
#endif

#ifdef TRACE
    printf ("==> ");
    dump_tree (l, 0);
    printf (" %d ", i - btree_space);
    dump_tree (r, 0);
    printf (" ret %d\n", p - btree_space);
    fflush (stdout);
#endif /* TRACE */
    return p;
}

#else /* UGLY_SPLIT */

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
#if defined(SAVE_NEIGHBORS) || !defined(SKIMPY_NULLS)
    btree *isave = i;
#endif
#if defined(SAVE_NEIGHBORS) && defined(NO_CLEAR_TO_ROOT)
    int rev = i->reversed;
#endif

#ifdef TRACE
    printf ("split %d ", i - btree_space);
    dump_tree (find_root (i), 0);
    printf ("\n");
    fflush (stdout);
#endif /* TRACE */

#ifdef NO_CLEAR_TO_ROOT
    if (i->reversed) {
        l = i->child[1];
        r = i->child[0];
#ifdef DUMMY_LEAF
        l->reversed ^= 1;
        r->reversed ^= 1;
#else
        if (l) l->reversed ^= 1;
        if (r) r->reversed ^= 1;
#endif
#ifndef SKIMPY_NULLS
        i->reversed = 0;
#endif
    } else {
        l = i->child[0];
        r = i->child[1];
    }
#else
    clearrev_toroot (i);
    l = i->child[0];
    r = i->child[1];
#endif

#ifndef SKIMPY_NULLS
#ifdef  DUMMY_LEAF
    i->child[0] = &dummy_leaf;
    i->child[1] = &dummy_leaf;
#else
    i->child[0] = (btree *) NULL;
    i->child[1] = (btree *) NULL;
#endif
#endif

    while ((p = i->parent) != (btree *) NULL) {
        if (p->child[0] == i) {
            p->child[0] = r;
#ifdef DUMMY_LEAF
            r->parent = p;
#else
            if (r) r->parent = p;
#endif
#ifdef NO_CLEAR_TO_ROOT
            if (p->reversed) {
                r = l;
                l = p;
#ifdef DUMMY_LEAF
                r->reversed ^= 1;
#else
                if (r) r->reversed ^= 1;
#endif
#ifdef SAVE_NEIGHBORS
                rev ^= 1;
#endif
            } else {
                r = p;
            }
#else
            r = p;
#endif
        } else {
            p->child[1] = l;
#ifdef DUMMY_LEAF
            l->parent = p;
#else
            if (l) l->parent = p;
#endif
#ifdef NO_CLEAR_TO_ROOT
            if (p->reversed) {
                l = r;
                r = p;
#ifdef DUMMY_LEAF
                l->reversed ^= 1;
#else
                if (l) l->reversed ^= 1;
#endif
#ifdef SAVE_NEIGHBORS
                rev ^= 1;
#endif
            } else {
                l = p;
            }
#else
            l = p;
#endif
        }
        i = p;
    }
#ifdef DUMMY_LEAF
    l->parent = (btree *) NULL;
    r->parent = (btree *) NULL;
#else
    if (l) l->parent = (btree *) NULL;
    if (r) r->parent = (btree *) NULL;
#endif
    *left = l;
    *right = r;
#ifndef SKIMPY_NULLS
    isave->parent = (btree *) NULL;
#endif
#if defined(SAVE_NEIGHBORS) && defined(NO_CLEAR_TO_ROOT)
    if (rev) SWAP (isave->neigh[0], isave->neigh[1], p);
#endif

#ifdef TRACE
    printf ("==> ");
    dump_tree (l, 0);
    printf (" %d ", isave - btree_space);
    dump_tree (r, 0);
    printf (" ret %d\n", i - btree_space);
    fflush (stdout);
#endif /* TRACE */
    return i;
}

#endif /* UGLY_SPLIT */

#ifdef CC_PROTOTYPE_ANSI
static void reverse (btree *p)
#else
static void reverse (p)
btree *p;
#endif
{
    btree *t;

    SWAP(p->child[0], p->child[1], t);
#ifdef DUMMY_LEAF
    p->child[0]->reversed ^= 1;
    p->child[1]->reversed ^= 1;
#else
    if (p->child[0]) p->child[0]->reversed ^= 1;
    if (p->child[1]) p->child[1]->reversed ^= 1;
#endif
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
#ifdef INLINE_CLEAR_TO_ROOT
    p->next = (btree *) NULL;
    while (p->parent) {
        p->parent->next = p;
        p = p->parent;
    }
    while (p) {
        if (p->reversed) reverse (p);
        p = p->next;
    }
#else
#ifdef INLINE_CLEAR_TO_ROOT2
    int rev;
    btree *q;

    for (q = p, rev = 0; q; q = q->parent) rev ^= q->reversed;
    if (rev) reverse(p);
    while (p->parent) {
      if (p->reversed) reverse(p->parent);
      p = p->parent;
    }
#else
    if (p->parent) clearrev_toroot (p->parent);
    if (p->reversed) reverse (p);
#endif
#endif
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
