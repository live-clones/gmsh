/***************************************************************************/
/*                                                                         */
/*  TOUR MAINTANENCE ROUTINES FOR LIN-KERNIGHAN - Segments with no UNDO    */
/*                                                                         */
/*                               TSP CODE                                  */
/*                                                                         */
/*                                                                         */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook                       */
/*  Date: March 13, 1995 (but mainly from March, 1990)                     */
/*                                                                         */
/*                                                                         */
/* EXPORTED FUNCTIONS:                                                     */
/*   int CClinkern_flipper_init (int ncount, int *cyc)                     */
/*     initializes flipper1 to an initial cycle given in cyc.              */
/*     returns 0 on success, nonzero on failure.                           */
/*   int CClinkern_flipper_reset_perm (int ncount)                         */
/*     reinitializes the cycle to the one current in the perm array.       */
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
/*   void CClinkern_flipper_flip_perm (int x, int y)                       */
/*     performs the flip on the reference (perm) cycle - use this to avoid */
/*     a reinitialization when there have not been too many flips.         */
/*   int CClinkern_flipper_sequence (int * x, int y, int z)                */
/*     returns 1 if xyz occur as an increasing subsequence of the cycle,   */
/*     returns 0 otherwise.                                                */
/*                                                                         */
/* NOTES:                                                                  */
/*     This is similar to the version of segments proposed by FJMO. It is  */
/* faster on smaller problems, but is not as flexible since it makes it    */
/* expensive to backtrack deep in the search.                              */
/*                                                                         */
/***************************************************************************/

#include "machdefs.h"
#include "util.h"

/***************************************************************************/
/*                                                                         */
/* SEGMENT FLIPPER (flipper1):                                             */
/*                                                                         */
/*     1. CClinkern_flipper_cycle and CClinkern_flipper_cycle_inverse      */
/*        return the current number of segments.                           */
/*                                                                         */
/*     2. This is the first pass - uses a straight cycle of segments, and  */
/*        a tree to find segment.                                          */
/*                                                                         */
/***************************************************************************/

/* #define CC_USE_QUICK_FLIPS  */

typedef struct flipper1 {
    struct {
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

typedef struct cacheobj {
    struct flipper1 *segment;
    int              stamp;
} cacheobj;

#ifdef CC_USE_QUICK_FLIPS
typedef struct quickpair {
    int first;
    int last;
    int dir;
    int reversed;
} quickpair;
#endif


#ifdef CC_PROTOTYPE_ANSI

static void
#ifdef CC_USE_QUICK_FLIPS
    undo_quick_flips (void),
#endif
    flipper1free (flipper1 *p),
    flipper1_tree_free (flipper1 *);

static flipper1
   *flipper1_locate (int x),
   *flipper1_split (flipper1 *, int);

#else

static void
#ifdef CC_USE_QUICK_FLIPS
    undo_quick_flips (),
#endif
    flipper1free (),
    flipper1_tree_free ();

static flipper1
   *flipper1_locate (),
   *flipper1_split ();

#endif

#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

static flipper1 *locate_root = (flipper1 *) NULL;
static flipper1 *order_root = (flipper1 *) NULL;
static cacheobj *locate_cache = (cacheobj *) NULL;
static int       locate_cache_magic = 0;

#ifdef CC_USE_QUICK_FLIPS
static quickpair quickstack[1000];
static top_quickstack = 0;
#endif

static int *flip1_cyc = (int *) NULL;
static int *flip1_inv = (int *) NULL;
static int reversed = 0;
static int short_size = 0;
static int cycle_size = 0;
static int segment_count = 1;

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
}

#ifdef CC_PROTOTYPE_ANSI
static void flipper1_tree_free (flipper1 *h)
#else
static void flipper1_tree_free (h)
flipper1 *h;
#endif
{
    flipper1 *p = order_root, *q = order_root;

    if (!p)
        return;

    do {
        p->next = flipper1freelist;   /* this does flipper1free (p) */
        flipper1freelist = p;
        p = p->order.right;
    } while (p != q);
}

#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_reset_perm (int keeper)
#else
int CClinkern_flipper_reset_perm (keeper)
int keeper;
#endif
{
/*
    printf ("CClinkern_flipper_reset_perm (%d)\n", keeper);
    fflush (stdout);
*/

#ifdef CC_USE_QUICK_FLIPS
    if (!keeper) {
        undo_quick_flips ();
    } else {
        top_quickstack = 0;
    }
#endif

    flipper1_tree_free (locate_root);

    locate_root = flipper1alloc ();
    if (!locate_root)
        return 1;

    order_root = locate_root;
    locate_root->locate.lower = (flipper1 *) NULL;
    locate_root->locate.higher = (flipper1 *) NULL;
    locate_root->order.left = locate_root;
    locate_root->order.right = locate_root;
    locate_root->low = 0;
    locate_root->high = cycle_size - 1;
    locate_root->reverse = reversed;
    segment_count = 1;
    locate_cache_magic++;

    return 0;
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

    printf ("CClinkern_flipper_reset_temp ...\n");
    fflush (stdout);

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
        CC_FREE (locate_cache, cacheobj);
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
    }
    for (i = 0; i < bigp->low; i++) {
        flip1_cyc[i] = cyc[i];
        flip1_inv[cyc[i]] = i;
    }
    if (cyc)
        CC_FREE (cyc, int);


    flipper1_tree_free (locate_root);
    locate_root = flipper1alloc ();
    if (!locate_root)
        return 1;

    order_root = locate_root;
    locate_root->locate.lower = (flipper1 *) NULL;
    locate_root->locate.higher = (flipper1 *) NULL;
    locate_root->order.left = locate_root;
    locate_root->order.right = locate_root;
    locate_root->low = 0;
    locate_root->high = ncount - 1;
    locate_root->reverse = bigreverse;
    segment_count = 1;
    reversed = bigreverse;
    locate_cache_magic++;

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

    locate_root->locate.lower = (flipper1 *) NULL;
    locate_root->locate.higher = (flipper1 *) NULL;
    locate_root->order.left = locate_root;
    locate_root->order.right = locate_root;
    locate_root->low = 0;
    locate_root->high = ncount - 1;
    locate_root->reverse = 0;
    segment_count = 1;

    flip1_cyc = CC_SAFE_MALLOC (ncount, int);
    if (!flip1_cyc) {
        CC_FREE (locate_cache, cacheobj);
        return 1;
    }
    flip1_inv = CC_SAFE_MALLOC (ncount, int);
    if (!flip1_inv) {
        CC_FREE (locate_cache, cacheobj);
        CC_FREE (flip1_cyc, int);
        return 1;
    }

    for (i = 0; i < ncount; i++) {
        flip1_cyc[i] = cyc[i];
        flip1_inv[cyc[i]] = i;
    }
    cycle_size = ncount;
    short_size = ncount/2;
    reversed = 0;

#ifdef CC_USE_QUICK_FLIPS
    top_quickstack = 0;
#endif

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_cycle (int *x)
#else
int CClinkern_flipper_cycle (x)
int *x;
#endif
{
    int *p;

/*
    printf ("CClinkern_flipper_cycle ...\n");
    fflush (stdout);
*/

#ifdef CC_USE_QUICK_FLIPS
    while (top_quickstack) {
        undo_quick_flips ();
    }
#endif

    if (reversed) {
        p = flip1_cyc + cycle_size;
        while (p > flip1_cyc) {
            *x++ = *--p;
        }
    } else {
        p = flip1_cyc + cycle_size;
        x += cycle_size;
        while (p > flip1_cyc) {
            *--x = *--p;
        }
    }

    return cycle_size;
}

#ifdef CC_PROTOTYPE_ANSI
void CClinkern_flipper_finish (void)
#else
void CClinkern_flipper_finish ()
#endif
{
    flipper1_tree_free (locate_root);
    locate_root = (flipper1 *) NULL;
    order_root = (flipper1 *) NULL;

    if (flip1_cyc)
        CC_FREE (flip1_cyc, int);
    if (flip1_inv)
        CC_FREE (flip1_inv, int);
    cycle_size = 0;
    short_size = 0;
    reversed = 0;
#ifdef CC_USE_QUICK_FLIPS
    top_quickstack = 0;
#endif
}

#ifdef CC_PROTOTYPE_ANSI
void CClinkern_flipper_free_world (void)
#else
void CClinkern_flipper_free_world ()
#endif
{
    int total, onlist;

    if (locate_cache)
        CC_FREE (locate_cache, cacheobj);

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

    if (locate_cache[x].stamp == locate_cache_magic) {
        p = locate_cache[x].segment;
    } else {
        p = locate_root;
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

    locate_cache[x].segment = p;
    locate_cache[x].stamp = locate_cache_magic;

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

    if (segment_count == 1) {
        int y;
        if (locate_root->reverse) {
            y = x - 1;
            return (y >= 0) ? flip1_cyc[y] : flip1_cyc[cycle_size-1];
        } else {
            y = x + 1;
            return (y < cycle_size) ? flip1_cyc[y] : flip1_cyc[0];
        }
    }

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

    if (segment_count == 1) {
        int y;
        if (locate_root->reverse) {
            y = x + 1;
            return (y < cycle_size) ? flip1_cyc[y] : flip1_cyc[0];
        } else {
            y = x - 1;
            return (y >= 0) ? flip1_cyc[y] : flip1_cyc[cycle_size-1];
        }
    }

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

/*
   flipper1_split breaks p between x-1 and x.  returns segment containing x.
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
        q->locate.higher = p->locate.higher;
        p->locate.higher = q;
        q->locate.lower = (flipper1 *) NULL;;
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
        side = 1;
        return q;
    } else {
        q->locate.lower = p->locate.lower;
        p->locate.lower = q;
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
        side = 0;
        return p;
    }
}

#ifdef CC_USE_QUICK_FLIPS
#define HITSIZE 10   /* Cannot run problems of size < 2 * HITSIZE */
#endif

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

#ifdef CC_USE_QUICK_FLIPS
    if (y >= xp->low && y <= xp->high) {
        if (xp->reverse) {
            if (x > y && x - y <= HITSIZE) {
                int gap = x - y;
                quickstack[top_quickstack].first = ix;
                quickstack[top_quickstack].last = iy;
                quickstack[top_quickstack].reversed = reversed;
                quickstack[top_quickstack++].dir = 1;
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
                quickstack[top_quickstack].first = ix;
                quickstack[top_quickstack].last = iy;
                quickstack[top_quickstack].reversed = reversed;
                quickstack[top_quickstack++].dir = 0;
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
#endif


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
}

#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_sequence (int x, int y, int z)
#else
int CClinkern_flipper_sequence (x, y, z)
int x, y, z;
#endif
{
    int xloc = flip1_inv[x];
    int yloc = flip1_inv[y];
    int zloc = flip1_inv[z];

    if (reversed) {
        if (xloc >= yloc)
            return yloc >= zloc || zloc >= xloc;
        else
            return yloc >= zloc && zloc >= xloc;
    } else {
        if (xloc <= yloc)
            return yloc <= zloc || zloc <= xloc;
        else
            return yloc <= zloc && zloc <= xloc;
    }
}

#ifdef CC_PROTOTYPE_ANSI
void CClinkern_flipper_flip_perm (int x, int y)
#else
void CClinkern_flipper_flip_perm (x, y)
int x,y;
#endif
{
    int xloc = flip1_inv[x];
    int yloc = flip1_inv[y];
    int temp;
    int gap;

/*
    printf ("CClinkern_flipper_flip_perm (%d, %d)\n", x, y); fflush (stdout);
*/

    if (reversed) {
        SWAP (xloc, yloc, temp);
    }
    gap = yloc - xloc;
    if (gap < 0) gap += cycle_size;

    if (gap > short_size) {
        SWAP (xloc, yloc, temp);
        reversed ^= 1;
        xloc++;
        if (xloc >= cycle_size)
            xloc = 0;
        yloc--;
        if (yloc < 0)
            yloc = cycle_size - 1;
        gap = cycle_size - gap - 2;
    }

    if (xloc > yloc) {
        gap++;
        gap /= 2;
        for (; gap; gap--) {
            x = flip1_cyc[xloc];
            y = flip1_cyc[yloc];
            flip1_cyc[xloc] = y;
            flip1_cyc[yloc] = x;
            flip1_inv[x] = yloc--;
            flip1_inv[y] = xloc++;
            if (xloc >= cycle_size)
                xloc = 0;
            if (yloc < 0)
                yloc = cycle_size - 1;
        }
    } else {
        gap++;
        gap /= 2;
        for (; gap; gap--) {
            x = flip1_cyc[xloc];
            y = flip1_cyc[yloc];
            flip1_cyc[xloc] = y;
            flip1_cyc[yloc] = x;
            flip1_inv[x] = yloc--;
            flip1_inv[y] = xloc++;
        }
    }
}

#ifdef CC_USE_QUICK_FLIPS
#ifdef CC_PROTOTYPE_ANSI
static void undo_quick_flips (void)
#else
static void undo_quick_flips ()
#endif
{
    int x, y, ix, iy, gap;

/*
    printf ("undo_quick_flips (%d)\n", top_quickstack);
    fflush (stdout);
*/

    while (top_quickstack) {
        top_quickstack--;

        assert (reversed == quickstack[top_quickstack].reversed);

        x = flip1_inv[quickstack[top_quickstack].first];
        y = flip1_inv[quickstack[top_quickstack].last];
        if (quickstack[top_quickstack].dir) {
            SWAP (x, y , ix);
        }
        gap = x - y + 1;
        if (gap < 0) {
            printf ("AARG: %d\n", gap); fflush (stdout);
        }
        gap /= 2;
        for (; gap; gap--) {
           ix = flip1_cyc[x];
           iy = flip1_cyc[y];
           flip1_cyc[x] = iy;
           flip1_cyc[y] = ix;
           flip1_inv[ix] = y++;
           flip1_inv[iy] = x--;
        }
    }
}
#endif
