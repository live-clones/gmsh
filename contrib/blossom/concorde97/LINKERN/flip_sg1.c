/***************************************************************************/
/*                                                                         */
/*     TOUR MAINTANENCE ROUTINES FOR LIN-KERNIGHAN - Segments with UNDO    */
/*                                                                         */
/*                               TSP CODE                                  */
/*                                                                         */
/*                                                                         */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook                       */
/*  Date: April 24, 1995 (but mainly from March, 1990)                     */
/*                                                                         */
/*                                                                         */
/* EXPORTED FUNCTIONS:                                                     */
/*   int CClinkern_flipper_init (int ncount, int *cyc)                     */
/*     initializes flipper1 to an initial cycle given in cyc.              */
/*     returns 0 on success, nonzero on failure.                           */
/*   int CClinkern_flipper_reset_temp (int ncount)                         */
/*     reinitializes the cycle to the current cycle - use this to keep the */
/*     number of segments small.                                           */
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
/*       This version is closest to our orignal segment code. It undos the */
/* flips that do not lead to an improvement.                               */
/*                                                                         */
/***************************************************************************/

#include "machdefs.h"
#include "util.h"

/* #define USE_TIMESTAMP */

/***************************************************************************/
/*                                                                         */
/* SEGMENT FLIPPER (flipper1):                                             */
/*                                                                         */
/*     1. flipper_cycle and flipper_cycle_inverse return the current       */
/*        number of segments.                                              */
/*                                                                         */
/*     2. The cycle should be renumbered, freed, and initialized now and   */
/*        and again to reduce the number of segments.                      */
/*                                                                         */
/*     3. This is the first pass - uses a straight cycle of segments, and  */
/*        a tree to find segment. No balance condition is maintained for   */
/*        the tree.                                                        */
/*                                                                         */
/***************************************************************************/


typedef struct flipper1 {
    struct {
        struct flipper1 *parent;
        struct flipper1 *lower;
        struct flipper1 *higher;
    } locate;
    struct {
        struct flipper1 *left;
        struct flipper1 *right;
    } order;
    int low;
    int high;
    int reverse;
    struct flipper1 *next;
} flipper1;

#ifdef  USE_TIMESTAMP
typedef struct cacheobj {
    struct flipper1 *segment;
    int              stamp;
} cacheobj;
#endif


#ifdef CC_PROTOTYPE_ANSI

static void
    flipper1_tree_delete (flipper1 *),
    flipper1_merge (flipper1 *),
    flipper1_checkmerge (flipper1 *),
    flipper1free (flipper1 *p),
    flipper1_tree_free (flipper1 *, flipper1 *);

static flipper1
   *flipper1_locate (int x),
   *flipper1_split (flipper1 *, int);

#else

static void
    flipper1_tree_delete (),
    flipper1_merge (),
    flipper1_checkmerge (),
    flipper1free (),
    flipper1_tree_free ();

static flipper1
   *flipper1_locate (),
   *flipper1_split ();

#endif

#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

#define LOCATE_CHILD(p, c) (*((p) ? ((p)->locate.lower == (c) ?              \
                              &(p)->locate.lower : &(p)->locate.higher) :    \
                              &locate_root))

#define PARENT_HOOKUP(q, p, c) (((q)->locate.parent = (p)),                  \
                                (LOCATE_CHILD((p),(c)) = (q)))

#define HIGHER_HOOKUP(p, c) (((p)->locate.higher = (c)),                     \
                       ((c) ? (c)->locate.parent = (p) : (flipper1 *) NULL))

#define LOWER_HOOKUP(p, c)  (((p)->locate.lower = (c)),                      \
                       ((c) ? (c)->locate.parent = (p) : (flipper1 *) NULL))

static flipper1 *locate_root = (flipper1 *) NULL;
static flipper1 *order_root = (flipper1 *) NULL;
#ifdef USE_TIMESTAMP
static cacheobj *locate_cache = (cacheobj *) NULL;
static int       locate_cache_magic = 0;
#else
static flipper1 **locate_cache = (flipper1 **) NULL;
#endif

static int *flip1_cyc = (int *) NULL;
static int *flip1_inv = (int *) NULL;
static int segment_count = 1;

/*
static int seghit = 0;
static int segtotal = 0;
*/

CC_PTR_ALLOC_ROUTINE (flipper1, flipper1alloc, flipper1chunklist,
                  flipper1freelist)
CC_PTR_FREE_WORLD_ROUTINE( flipper1, flipper1free_world, flipper1chunklist,
                  flipper1freelist)
CC_PTR_LEAKS_ROUTINE (flipper1, flipper1_check_leaks, flipper1chunklist,
                  flipper1freelist, reverse, int)

#ifdef CC_PROTOTYPE_ANSI
static void flipper1free (flipper1 *p)
#else
static void flipper1free (p)
flipper1 *p;
#endif
{
    p->next = flipper1freelist;
    flipper1freelist = p;
    p->low = p->high = -1;
}

#ifdef CC_PROTOTYPE_ANSI
static void flipper1_tree_free (flipper1 *p, flipper1 *bigp)
#else
static void flipper1_tree_free (p, bigp)
flipper1 *p, *bigp;
#endif
{
    if (p) {
        flipper1_tree_free (p->locate.lower, bigp);
        flipper1_tree_free (p->locate.higher, bigp);
        if (p != bigp)
           flipper1free (p);
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_reset_temp (int ncount)
#else
int CClinkern_flipper_reset_temp (ncount)
int ncount;
#endif
{
    int i, n, *cyc = (int *) NULL;
    int nseg = 0, big = 0, bigreverse = 0;
    flipper1 *p, *bigp = (flipper1 *) NULL;

    p = order_root;
    do {
        if (p->high - p->low > big) {
            big = p->high - p->low;
            bigp = p;
        }
        nseg++;
        p = p->order.right;
    } while (p != order_root);

    if (nseg == 1)
        return 0;

    cyc = CC_SAFE_MALLOC (ncount, int);
    if (!cyc) {
#ifdef USE_TIMESTAMP
        CC_FREE (locate_cache, cacheobj);
#else
        CC_FREE (locate_cache, flipper1 *);
#endif
        return 1;
    }
    if (bigp->reverse) {
        bigreverse = 1;
        p = bigp->order.left;
        n = bigp->high + 1;
        do {
            if (!p->reverse) {
                for (i = p->high; i >= p->low; i--) {
                    if (n == ncount)
                        n = 0;
                    cyc[n++] = flip1_cyc[i];
                }
            } else {
                for (i = p->low; i <= p->high; i++) {
                    if (n == ncount)
                        n = 0;
                    cyc[n++] = flip1_cyc[i];
                }
            }
            p = p->order.left;
        } while (p != bigp);
    } else {
        bigreverse = 0;
        p = bigp->order.right;
        n = bigp->high + 1;
        do {
            if (p->reverse) {
                for (i = p->high; i >= p->low; i--) {
                    if (n == ncount)
                        n = 0;
                    cyc[n++] = flip1_cyc[i];
                }
            } else {
                for (i = p->low; i <= p->high; i++) {
                    if (n == ncount)
                        n = 0;
                    cyc[n++] = flip1_cyc[i];
                }
            }
            p = p->order.right;
        } while (p != bigp);
    }

    for (i = bigp->high + 1; i < ncount; i++) {
        flip1_cyc[i] = cyc[i];
        flip1_inv[cyc[i]] = i;
#ifndef USE_TIMESTAMP
        locate_cache[i] = bigp;
#endif
    }
    for (i = 0; i < bigp->low; i++) {
        flip1_cyc[i] = cyc[i];
        flip1_inv[cyc[i]] = i;
#ifndef USE_TIMESTAMP
        locate_cache[i] = bigp;
#endif
    }
    if (cyc)
        CC_FREE (cyc, int);


#ifdef USE_TIMESTAMP
    flipper1_tree_free (locate_root, (flipper1 *) NULL);
    locate_root = flipper1alloc ();
    if (!locate_root)
        return 1;
#else
    flipper1_tree_free (locate_root, bigp);
    locate_root = bigp;
#endif

    order_root = locate_root;
    locate_root->locate.parent = (flipper1 *) NULL;
    locate_root->locate.lower = (flipper1 *) NULL;
    locate_root->locate.higher = (flipper1 *) NULL;
    locate_root->order.left = locate_root;
    locate_root->order.right = locate_root;
    locate_root->low = 0;
    locate_root->high = ncount - 1;
    locate_root->reverse = bigreverse;
    segment_count = 1;

#ifdef USE_TIMESTAMP
    locate_cache_magic++;
#endif

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

    locate_root = flipper1alloc ();
    if (!locate_root)
        return 1;
    order_root = locate_root;

#ifdef USE_TIMESTAMP
    if (!locate_cache) {
        locate_cache = CC_SAFE_MALLOC (ncount, cacheobj);
        if (!locate_cache) {
            flipper1free (locate_root);
            return 1;
        }
        for (i = 0; i < ncount; i++) {
            locate_cache[i].segment = locate_root;
            locate_cache[i].stamp = 0;
        }
        locate_cache_magic = 0;
    } else {
        locate_cache_magic++;
    }
#else
    if (!locate_cache) {
        locate_cache = CC_SAFE_MALLOC (ncount, flipper1 *);
        if (!locate_cache) {
            flipper1free (locate_root);
            return 1;
        }
    }
#endif

    locate_root->locate.parent = (flipper1 *) NULL;
    locate_root->locate.lower = (flipper1 *) NULL;
    locate_root->locate.higher = (flipper1 *) NULL;
    locate_root->order.left = locate_root;
    locate_root->order.right = locate_root;
    locate_root->low = 0;
    locate_root->high = ncount - 1;
    locate_root->reverse = 0;
    segment_count = 1;

#ifndef USE_TIMESTAMP
    for (i = 0; i < ncount; i++) {
        locate_cache[i] = locate_root;
    }
#endif

    flip1_cyc = CC_SAFE_MALLOC (ncount, int);
    if (!flip1_cyc) {
#ifdef USE_TIMESTAMP
        CC_FREE (locate_cache, cacheobj);
#else
        CC_FREE (locate_cache, flipper1 *);
#endif
        return 1;
    }
    flip1_inv = CC_SAFE_MALLOC (ncount, int);
    if (!flip1_inv) {
#ifdef USE_TIMESTAMP
        CC_FREE (locate_cache, cacheobj);
#else
        CC_FREE (locate_cache, flipper1 *);
#endif
        CC_FREE (flip1_cyc, int);
        return 1;
    }

    for (i = 0; i < ncount; i++) {
        flip1_cyc[i] = cyc[i];
        flip1_inv[cyc[i]] = i;
    }

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_cycle (int *x)
#else
int CClinkern_flipper_cycle (x)
int *x;
#endif
{
    flipper1 *p;
    int i;
    int n = 0;
    int nseg = 0;

    p = order_root;
    do {
        nseg++;
        if (p->reverse) {
            for (i = p->high; i >= p->low; i--)
                x[n++] = flip1_cyc[i];
        } else {
            for (i = p->low; i <= p->high; i++)
                x[n++] = flip1_cyc[i];
        }
        p = p->order.right;
    } while (p != order_root);

    assert (nseg == segment_count);
/*
    printf ("Segment Hits: %d  (Total %d) (%.2f)\n", seghit, segtotal,
                (double) seghit / (double) segtotal);
    fflush (stdout);
*/
    return nseg;
}

#ifdef CC_PROTOTYPE_ANSI
void CClinkern_flipper_finish (void)
#else
void CClinkern_flipper_finish ()
#endif
{
    flipper1_tree_free (locate_root, (flipper1 *) NULL);
    locate_root = (flipper1 *) NULL;
    order_root = (flipper1 *) NULL;

    if (flip1_cyc)
        CC_FREE (flip1_cyc, int);
    if (flip1_inv)
        CC_FREE (flip1_inv, int);
}

#ifdef CC_PROTOTYPE_ANSI
void CClinkern_flipper_free_world (void)
#else
void CClinkern_flipper_free_world ()
#endif
{
    int total, onlist;

    if (locate_cache)
#ifdef USE_TIMESTAMP
        CC_FREE (locate_cache, cacheobj);
#else
        CC_FREE (locate_cache, flipper1 *);
#endif

    if (flipper1_check_leaks (&total, &onlist)) {
        fprintf (stderr, "WARNING: %d outstanding flippers\n", total - onlist);
    }
    flipper1free_world ();
}


#ifdef CC_PROTOTYPE_ANSI
static flipper1 *flipper1_locate (int x)
#else
static flipper1 *flipper1_locate (x)
int x;
#endif
{
    flipper1 *p;

#ifdef USE_TIMESTAMP
    if (locate_cache[x].stamp == locate_cache_magic) {
        p = locate_cache[x].segment;
    } else {
        p = locate_root;
    }
#else
    p = locate_cache[x];
#endif

    if (p->high < x) {
        if (p->high != -1) {
            if (p->locate.higher && p->locate.higher->high >= x) {
                p = p->locate.higher;
            } else if (p->locate.parent && p->locate.parent->high >= x) {
                p = p->locate.parent;
            } else {
                p = locate_root;
            }
        } else {
            p = locate_root;
        }
    } else if (p->low > x) {
        if (p->locate.lower && p->locate.lower->low <= x) {
            p = p->locate.lower;
        } else if (p->locate.parent && p->locate.parent->low <= x) {
            p = p->locate.parent;
        } else {
            p = locate_root;
        }
    } else {
        return p;
    }

/*
    while (p) {       For some reason this is faster under linux
*/
    while (1) {
        if (x < p->low)
            p = p->locate.lower;
        else if (x > p->high)
            p = p->locate.higher;
        else
            break;
    }
#ifdef USE_TIMESTAMP
    locate_cache[x].segment = p;
    locate_cache[x].stamp = locate_cache_magic;
#else
    locate_cache[x] = p;
#endif

    return p;
}

#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_next (int ix)
#else
int CClinkern_flipper_next (ix)
int ix;
#endif
{
    int x = flip1_inv[ix];
    flipper1 *p;

    p = flipper1_locate (x);

    if (p->reverse) {
        return x == p->low ? (p->order.right->reverse
                              ? flip1_cyc[p->order.right->high]
                              : flip1_cyc[p->order.right->low])
            : flip1_cyc[x - 1];
    } else {
        return x == p->high ? (p->order.right->reverse
                               ? flip1_cyc[p->order.right->high]
                               : flip1_cyc[p->order.right->low])
            : flip1_cyc[x + 1];
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_prev (int ix)
#else
int CClinkern_flipper_prev (ix)
int ix;
#endif
{
    int x = flip1_inv[ix];
    flipper1 *p;

    p = flipper1_locate (x);

    if (p->reverse) {
        return x == p->high ? (p->order.left->reverse
                               ? flip1_cyc[p->order.left->low]
                               : flip1_cyc[p->order.left->high])
            : flip1_cyc[x + 1];
    } else {
        return x == p->low ? (p->order.left->reverse
                              ? flip1_cyc[p->order.left->low]
                              : flip1_cyc[p->order.left->high])
            : flip1_cyc[x - 1];
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void flipper1_tree_delete (flipper1 *p)
#else
static void flipper1_tree_delete (p)
flipper1 *p;
#endif
{
    flipper1 *q;

    if (p->locate.lower == (flipper1 *) NULL) {
        if (p->locate.higher) {
            PARENT_HOOKUP (p->locate.higher, p->locate.parent, p);
        } else {
            LOCATE_CHILD (p->locate.parent, p) = (flipper1 *) NULL;
        }
    } else if (p->locate.higher == (flipper1 *) NULL) {
        PARENT_HOOKUP (p->locate.lower, p->locate.parent, p);
    } else {
        q = p->locate.lower;
        while (q->locate.higher)
            q = q->locate.higher;
        if (q->locate.parent == p) {
            PARENT_HOOKUP (q, p->locate.parent, p);
            HIGHER_HOOKUP (q, p->locate.higher);
        } else {
            HIGHER_HOOKUP (q->locate.parent, q->locate.lower);
            PARENT_HOOKUP (q, p->locate.parent, p);
            LOWER_HOOKUP (q, p->locate.lower);
            HIGHER_HOOKUP (q, p->locate.higher);
        }
    }
}

/*
   flipper1_split breaks p between x-1 and x.
*/

#ifdef CC_PROTOTYPE_ANSI
static flipper1 *flipper1_split (flipper1 *p, int x)
#else
static flipper1 *flipper1_split (p, x)
flipper1 *p;
int x;
#endif
{
    flipper1 *q = flipper1alloc ();  /* This will not fail - initial supply */
    static int side = 0;

    segment_count++;
    if (side) {
        HIGHER_HOOKUP (q, p->locate.higher);
        HIGHER_HOOKUP (p, q);
        q->locate.lower = (flipper1 *) NULL;
        q->low = x;
        q->high = p->high;
        p->high = x - 1;
        q->reverse = p->reverse;
        if (p->reverse) {
            p->order.left->order.right = q;
            q->order.left = p->order.left;
            q->order.right = p;
            p->order.left = q;
        } else {
            p->order.right->order.left = q;
            q->order.right = p->order.right;
            q->order.left = p;
            p->order.right = q;
        }
        side = 0;
        return q;
    } else {
        LOWER_HOOKUP (q, p->locate.lower);
        LOWER_HOOKUP (p, q);
        q->locate.higher =  (flipper1 *) NULL;
        q->low = p->low;
        q->high = x - 1;
        p->low = x;
        q->reverse = p->reverse;
        if (p->reverse) {
            p->order.right->order.left = q;
            q->order.right = p->order.right;
            q->order.left = p;
            p->order.right = q;
        } else {
            p->order.left->order.right = q;
            q->order.left = p->order.left;
            q->order.right = p;
            p->order.left = q;
        }
        side = 1;
        return p;
    }
}

/* flipper1_merge merges p->right into p.  */

#ifdef CC_PROTOTYPE_ANSI
static void flipper1_merge (flipper1 *p)
#else
static void flipper1_merge (p)
flipper1 *p;
#endif
{
    flipper1 *pr = p->order.right;

    if (pr->high > p->high)
        p->high = pr->high;
    if (pr->low < p->low)
        p->low = pr->low;
    p->order.right = pr->order.right;
    p->order.right->order.left = p;
    flipper1_tree_delete (pr);
    if (order_root == pr)
        order_root = p;
    flipper1free (pr);
    segment_count--;
}

#ifdef CC_PROTOTYPE_ANSI
static void flipper1_checkmerge (flipper1 *x)
#else
static void flipper1_checkmerge (x)
flipper1 *x;
#endif
{
    flipper1 *xr = x->order.right;

    if (x->reverse || x->low == x->high) {
        if ((xr->reverse || xr->low == xr->high) && xr->high + 1 == x->low) {
            x->reverse = 1;
            flipper1_merge (x);
        }
    }
    if (!x->reverse || x->low == x->high) {
        if ((!xr->reverse || xr->low == xr->high) && x->high + 1 == xr->low) {
            x->reverse = 0;
            flipper1_merge (x);
        }
    }
}

#define HITSIZE 100

#ifdef CC_PROTOTYPE_ANSI
void CClinkern_flipper_flip (int ix, int iy)
#else
void CClinkern_flipper_flip (ix, iy)
int ix, iy;
#endif
{
    flipper1 *xp, *yp, *p, *ptemp, *rp, *lp;
    int x, y;

    x = flip1_inv[ix];
    y = flip1_inv[iy];

    xp = flipper1_locate (x);

    if (y >= xp->low && y <= xp->high) {
        if (xp->reverse) {
            if (x > y && x - y <= HITSIZE) {
                int gap = x - y;
                gap++;
                gap /= 2;
                for (; gap; gap--) {
                   ix = flip1_cyc[x];
                   iy = flip1_cyc[y];
                   flip1_cyc[x] = iy;
                   flip1_cyc[y] = ix;
                   flip1_inv[ix] = y++;
                   flip1_inv[iy] = x--;
                }
                return;
            }
        } else {
            if (x < y && y - x <= HITSIZE) {
                int gap = y - x;
                gap++;
                gap /= 2;
                for (; gap; gap--) {
                   ix = flip1_cyc[x];
                   iy = flip1_cyc[y];
                   flip1_cyc[x] = iy;
                   flip1_cyc[y] = ix;
                   flip1_inv[ix] = y--;
                   flip1_inv[iy] = x++;
                }
                return;
            }
        }
    }


    /* split segments if necessary */
    if (xp->reverse) {
        if (x != xp->high) {
            xp = flipper1_split (xp, x + 1);
            xp = xp->order.right;
        }
    } else {
        if (x != xp->low) {
            xp = flipper1_split (xp, x);
        }
    }

    yp = flipper1_locate (y);
    if (yp->reverse) {
        if (y != yp->low) {
            yp = flipper1_split (yp, y);
        }
    } else {
        if (y != yp->high) {
            yp = flipper1_split (yp, y + 1);
            yp = yp->order.left;
        }
    }
    xp = flipper1_locate (x);

    /* reverse */
    p = xp;
    for (;;) {
        SWAP (p->order.right, p->order.left, ptemp);
        p->reverse ^= 1;
        if (p == yp)
            break;
        p = p->order.left;
    }

    if (xp->order.right != yp) {
        lp = xp->order.right;
        rp = yp->order.left;

        lp->order.right = yp;
        rp->order.left = xp;
        xp->order.right = rp;
        yp->order.left = lp;
    }
    /* merge segments if necessary */
    rp = xp->order.right;
    if (yp != xp->order.right) {
        flipper1_checkmerge (xp);
        flipper1_checkmerge (yp->order.left);
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_sequence (int ix, int iy, int iz)
#else
int CClinkern_flipper_sequence (ix, iy, iz)
int ix, iy, iz;
#endif
{
    flipper1 *xp, *yp, *zp;
    int x, y, z;

    x = flip1_inv[ix];
    y = flip1_inv[iy];
    z = flip1_inv[iz];

    if (segment_count == 1) {
        if (locate_root->reverse) {
            if (x >= y)
                return y >= z || z >= x;
            else
                return y >= z && z >= x;
        } else {
            if (x <= y)
                return y <= z || z <= x;
            else
                return y <= z && z <= x;
        }
    }

    xp = flipper1_locate (x);
    yp = flipper1_locate (y);
    zp = flipper1_locate (z);

    if (xp == yp) {
        if (xp == zp) {
            if (xp->reverse) {
                if (x >= y) {
                    return y >= z || z >= x;
                } else {
                    return y >= z && z >= x;
                }
            } else {
                if (x <= y) {
                    return y <= z || z <= x;
                } else {
                    return y <= z && z <= x;
                }
            }
        } else {
            if (xp->reverse) {
                return x >= y;
            } else {
                return x <= y;
            }
        }
    } else if (xp == zp) {
        if (xp->reverse) {
            return z >= x;
        } else {
            return z <= x;
        }
    } else if (yp == zp) {
        if (yp->reverse) {
            return y >= z;
        } else {
            return y <= z;
        }
    } else {
        while (xp != yp) {
            if (xp == zp) {
                return 0;
            }
            xp = xp->order.right;
        }
        return 1;
    }
}
