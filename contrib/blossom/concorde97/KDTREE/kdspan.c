/***************************************************************************/
/*                                                                         */
/*            KD-TREE BASED MIN SPANNING TREE AND GREEDY TOUR              */
/*                                                                         */
/*  (Based on Jon Bentley's paper "Fast algorithms for geometric           */
/*   traveling salesman problems", ORSA Journal on Computing.)             */
/*                                                                         */
/*                           TSP CODE                                      */
/*                                                                         */
/*                                                                         */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook (mainly from Jon      */
/*               Bentley's paper)                                          */
/*  Date: February 16, 1995 (cofeb16)                                      */
/*                                                                         */
/*                                                                         */
/*  EXPORTED FUNCTIONS:                                                    */
/*    int CCkdtree_prim_spanningtree (CCkdtree *kt, int ncount,            */
/*            CCdatagroup *dat, double *wcoord, int *outtree, double *val) */
/*      RETURNS a min weight spanning tree.                                */
/*        -kt is a pointer to a CCkdtree built by a call to CCkdtree_build.*/
/*         If kt is NULL, then CCkdtree_build will be called.              */
/*        -If wcoord is not NULL, then the array should have nonnegative   */
/*         values. The code will use Held-Karp style distances.            */
/*        -If outtree is non NULL, it should point to an array of length   */
/*         at least 2*ncount - 2. The edges in the min spanning tree will  */
/*         be returned in the array in end end format.                     */
/*        -The length of the min tree is returned in val.                  */
/*    int CCkdtree_greedy_tour (CCkdtree *kt, int ncount, CCdatagroup *dat,*/
/*           int *outcycle, double *val)                                   */
/*       RETURNS a greedy tour. (No randomization (expect in building the  */
/*         CCkdtree) so there is no point in calling this more than once)  */
/*        -kt can be NULL.                                                 */
/*        -Does not use node weights.                                      */
/*        -If outcycle is non NUL, it should point to an array of length   */
/*         at least ncount. The cycle will be returned in node node node   */
/*         format.                                                         */
/*    int CCkdtree_far_add_tour (CCkdtree *kt, int ncount,                 */
/*            CCdatagroup *dat, int *outcycle, double *val, int start)     */
/*       RETURNS a farthest addition tour, beginning with node start.      */
/*        -like CCkdtree_greedy_tour.                                      */
/*                                                                         */
/*  NOTES:                                                                 */
/*       Uses around 20n bytes of memory for an n node problem (plus the   */
/*    memory for a CCkdtree), for a spanning tree, and 33n for a greedy    */
/*    tour. Both functions return 0 if successful, and nonzero if they     */
/*    failed (usually due to running out of memory.                        */
/*                                                                         */
/***************************************************************************/

#include "machdefs.h"
#include "util.h"
#include "kdtree.h"

typedef struct faobj {
   struct faobj *next;
   struct faobj *prev;
   int           name;
} faobj;

#define Fedgelen(n1, n2)                                                     \
    (datw != (double *) NULL ?                                               \
      CCutil_dat_edgelen ((n1), (n2), dat)                                   \
            + datw[(n1)] + datw[(n2)] :                                      \
      CCutil_dat_edgelen ((n1), (n2), dat))

#define SWAP(a, b, t) ((t) = (a), (a) = (b), (b) = (t))

#ifdef CC_PROTOTYPE_ANSI

static void
    add_primheap (CCdheap *prim_heap, CCkdtree *kt, int n, int *neighbor,
          CCdatagroup *dat, double *datw),
    greedy_add_primheap (CCdheap *prim_heap, CCkdtree *kt, int n, int *neighbor,
          CCdatagroup *dat),
    fa_add_primheap (CCdheap *prim_heap, int n, int len);

#ifdef USE_SPACEFILL
static int
    space_fill_curve (int ncount, CCdatagroup *dat, int *outcyc, double *len);
#endif

#else

static void
    add_primheap (),
    greedy_add_primheap (),
    fa_add_primheap ();

#ifdef USE_SPACEFILL
static int
    space_fill_curve (ncount, dat, outcyc, len);
#endif

#endif

#ifdef CC_PROTOTYPE_ANSI
int CCkdtree_prim_spanningtree (CCkdtree *kt, int ncount, CCdatagroup *dat,
           double *wcoord, int *outtree, double *val)
#else
int CCkdtree_prim_spanningtree (kt, ncount, dat, wcoord, outtree, val)
CCkdtree *kt;
int ncount;
CCdatagroup *dat;
double *wcoord;
int *outtree;
double *val;
#endif
{
    CCkdtree localkt, *thetree;
    double len;
    int i, n;
    int klist = 0;
    int newtree = 0;
    int *neighbor = (int *) NULL;
    CCdheap prim_heap;

    if (wcoord != (double *) NULL) {
        for (i = 0; i < ncount; i++) {
            if (wcoord[i] < -0.00000001) {
                fprintf (stderr, "Cannot kdtree with negative node weights\n");
                return 1;
            }
        }
    }

    if (kt == (CCkdtree *) NULL) {
        if (CCkdtree_build (&localkt, ncount, dat, wcoord)) {
            fprintf (stderr, "Unable to build CCkdtree\n");
            return 1;
        }
        thetree = &localkt;
        newtree = 1;
    } else {
        thetree = kt;
    }

    neighbor = CC_SAFE_MALLOC (ncount, int);
    if (!neighbor)
        return 1;

    printf ("Find minimum weight spanning tree\n");
    fflush (stdout);

    CCutil_dheap_init (&prim_heap, ncount);
    for (i = 0; i < ncount; i++)
        neighbor[i] = -1;

    CCkdtree_delete (thetree, 0);
    add_primheap (&prim_heap, thetree, 0, neighbor, dat, wcoord);

    len = 0.0;
    for (i = 1; i < ncount; i++) {
        if (i % 10000 == 1) {
            printf (".");
            fflush (stdout);
        }
        while (1) {
            n = CCutil_dheap_deletemin (&prim_heap);
            if (neighbor[neighbor[n]] == -1)
                break;
            else
                add_primheap (&prim_heap, thetree, n, neighbor, dat, wcoord);
        }
        if (outtree) {
            outtree[klist++] = n;
            outtree[klist++] = neighbor[n];
        }
        len += prim_heap.key[n];
        CCkdtree_delete (thetree, neighbor[n]);
        add_primheap (&prim_heap, thetree, neighbor[n], neighbor, dat, wcoord);
        add_primheap (&prim_heap, thetree, n, neighbor, dat, wcoord);
    }
    *val = len;
    printf ("\nLength of Spanning Tree: %.2f\n", len);
    if (wcoord != (double *) NULL) {
        double tval = 0.0;
        for (i = 0; i < ncount; i++)
            tval += wcoord[i];
        tval *= 2.0;
        printf ("TSP BOUND: %.2f\n", len - tval);
    }

    if (newtree)
        CCkdtree_free (&localkt);
    else
        CCkdtree_undelete_all (kt, ncount);
    CCutil_dheap_free (&prim_heap);
    if (neighbor) {
        CC_FREE (neighbor, int);
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static void add_primheap (CCdheap *prim_heap, CCkdtree *kt, int n,
        int *neighbor, CCdatagroup *dat, double *datw)
#else
static void add_primheap (prim_heap, kt, n, neighbor, dat, datw)
CCdheap *prim_heap;
CCkdtree *kt;
int n;
int *neighbor;
CCdatagroup *dat;
double *datw;
#endif
{
    neighbor[n] = CCkdtree_node_nearest (kt, n, dat, datw);
    prim_heap->key[n] = (double) Fedgelen (n, neighbor[n]);
    CCutil_dheap_insert (prim_heap, n);
}

#ifdef CC_PROTOTYPE_ANSI
int CCkdtree_greedy_tour (CCkdtree *kt, int ncount, CCdatagroup *dat,
                        int *outcycle, double *val)
#else
int CCkdtree_greedy_tour (kt, ncount, dat, outcycle, val)
CCkdtree *kt;
int ncount;
CCdatagroup *dat;
int *outcycle;
double *val;
#endif
{
    CCkdtree localkt, *thetree;
    double len;
    int i, x, y;
    char *degree = (char *) NULL;
    int *tail = (int *) NULL;
    int *tcyc = (int *) NULL;
    int tcount = 0;
    int rval = 0;
    int newtree = 0;
    int *neighbor = (int *) NULL;
    CCdheap prim_heap;

    if (kt == (CCkdtree *) NULL) {
        if (CCkdtree_build (&localkt, ncount, dat, (double *) NULL)) {
            fprintf (stderr, "Unable to build CCkdtree\n");
            return 1;
        }
        thetree = &localkt;
        newtree = 1;
    } else {
        thetree = kt;
    }

    printf ("Grow a greedy tour \n");
    fflush (stdout);

    if (outcycle) {
        tcyc = CC_SAFE_MALLOC (2 * ncount, int);
        if (!tcyc) {
            rval = 1;
            goto CLEANUP;
        }
    }

    neighbor = CC_SAFE_MALLOC (ncount, int);
    if (!neighbor) {
        rval = 1;
        goto CLEANUP;
    }
    degree = CC_SAFE_MALLOC (ncount, char);
    if (!degree) {
        rval = 1;
        goto CLEANUP;
    }
    tail = CC_SAFE_MALLOC (ncount, int);
    if (!tail) {
        rval = 1;
        goto CLEANUP;
    }
    if (CCutil_dheap_init (&prim_heap, ncount)) {
        rval = 1;
        goto CLEANUP;
    }

    for (i = 0; i < ncount; i++) {
        degree[i] = 0;
        tail[i] = -1;
        greedy_add_primheap (&prim_heap, thetree, i, neighbor, dat);
    }

    len = 0.0;
    for (i = 1; i < ncount; i++) {
        while (1) {
            x = CCutil_dheap_deletemin (&prim_heap);
            if (degree[x] == 2)
                continue;
            y = neighbor[x];
            if (degree[y] < 2 && y != tail[x])
                break;          /* add (x, y) to the tour */
            if (tail[x] != -1) {
                CCkdtree_delete (thetree, tail[x]);
                greedy_add_primheap (&prim_heap, thetree, x, neighbor, dat);
                CCkdtree_undelete (thetree, tail[x]);
            } else {
                greedy_add_primheap (&prim_heap, thetree, x, neighbor, dat);
            }
        }
        if (tcyc) {
            tcyc[tcount++] = x;
            tcyc[tcount++] = y;
        }
        len += prim_heap.key[x];
        (degree[x])++;
        if (degree[x] == 2)
            CCkdtree_delete (thetree, x);
        (degree[y])++;
        if (degree[y] == 2)
            CCkdtree_delete (thetree, y);
        if (tail[x] == -1) {
            if (tail[y] == -1) {
                tail[x] = y;
                tail[y] = x;
            } else {
                tail[x] = tail[y];
                tail[tail[y]] = x;
            }
        } else if (tail[y] == -1) {
            tail[tail[x]] = y;
            tail[y] = tail[x];
        } else {
            tail[tail[x]] = tail[y];
            tail[tail[y]] = tail[x];
        }
        if (degree[x] == 1) {
            CCkdtree_delete (thetree, tail[x]);
            greedy_add_primheap (&prim_heap, thetree, x, neighbor, dat);
            CCkdtree_undelete (thetree, tail[x]);
        }
        if (i % 10000 == 9999) {
            printf (".");
            fflush (stdout);
        }
    }
    for (x = 0; degree[x] != 1; x++);
    for (y = x + 1; degree[y] != 1; y++);
    if (tcyc) {
        tcyc[tcount++] = x;
        tcyc[tcount++] = y;
    }
    len += (double) CCutil_dat_edgelen (x, y, dat);
    *val = len;
    if (ncount >= 10000)
        printf ("\n");
    printf ("Length of Greedy Tour: %.2f\n", len);
    CCutil_dheap_free (&prim_heap);

    if (tcyc) {
        if (CCutil_edge_to_cycle (ncount, tcyc, outcycle)) {
            fprintf (stderr, "ERROR: greedy tour is not a tour\n");
            rval = 1;
            goto CLEANUP;
        }
    }

CLEANUP:

    if (newtree)
        CCkdtree_free (&localkt);
    else
        CCkdtree_undelete_all (kt, ncount);
    if (tcyc)
        CC_FREE (tcyc, int);
    if (neighbor)
        CC_FREE (neighbor, int);
    if (degree)
        CC_FREE (degree, char);
    if (tail)
        CC_FREE (tail, int);
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static void greedy_add_primheap (CCdheap *prim_heap, CCkdtree *kt, int n,
        int *neighbor, CCdatagroup *dat)
#else
static void greedy_add_primheap (prim_heap, kt, n, neighbor, dat)
CCdheap *prim_heap;
CCkdtree *kt;
int n;
int *neighbor;
CCdatagroup *dat;
#endif
{
    CCkdtree_delete (kt, n);
    neighbor[n] = CCkdtree_node_nearest (kt, n, dat, (double *) NULL);
    CCkdtree_undelete (kt, n);
    prim_heap->key[n] = (double) CCutil_dat_edgelen (n, neighbor[n], dat);
    CCutil_dheap_insert (prim_heap, n);
}

#ifdef CC_PROTOTYPE_ANSI
int CCkdtree_far_add_tour (CCkdtree *kt, int ncount, int start,
        CCdatagroup *dat, int *outcycle, double *val)
#else
int CCkdtree_far_add_tour (kt, ncount, start, dat, outcycle, val)
CCkdtree *kt;
int ncount;
int start;
CCdatagroup *dat;
int *outcycle;
double *val;
#endif
{
    CCkdtree localkt, *thetree;
    double len = 0.0;
    int i, x, y, oldx;
    int rval = 0;
    int newtree = 0;
    faobj *supply = (faobj *) NULL;
    faobj *fa, *fx;
    int *neighbor = (int *) NULL;
    CCdheap prim_heap;

    if (kt == (CCkdtree *) NULL) {
        if (CCkdtree_build (&localkt, ncount, dat, (double *) NULL)) {
            fprintf (stderr, "Unable to build CCkdtree\n");
            return 1;
        }
        thetree = &localkt;
        newtree = 1;
    } else {
        thetree = kt;
    }

    printf ("Grow a farthest addition tour from node %d \n", start);
    fflush (stdout);

    neighbor = CC_SAFE_MALLOC (ncount, int);
    if (!neighbor) {
        rval = 1;
        goto CLEANUP;
    }
    supply  = CC_SAFE_MALLOC (ncount, faobj);
    if (!supply) {
        rval = 1;
        goto CLEANUP;
    }
    if (CCutil_dheap_init (&prim_heap, ncount)) {
        rval = 1;
        goto CLEANUP;
    }

    CCkdtree_delete_all (thetree, ncount);
    CCkdtree_undelete (thetree, start);

    for (i = 0; i < ncount; i++) {
        if (i != start) {
            neighbor[i] = start;
            fa_add_primheap (&prim_heap, i, CCutil_dat_edgelen (i, start, dat));
        }
    }

    fa = &(supply[start]);
    fa->prev = fa;
    fa->next = fa;
    fa->name = start;

    y = CCutil_dheap_deletemin (&prim_heap);
    CCkdtree_undelete (thetree, y);
    fa = &(supply[y]);
    fa->name = y;
    fa->prev = &(supply[start]);
    fa->next = &(supply[start]);
    supply[start].next = fa;
    supply[start].prev = fa;

    for (i = 2; i < ncount; i++) {
        while (1) {
            y = CCutil_dheap_deletemin (&prim_heap);
            oldx = neighbor[y];
            x = CCkdtree_node_nearest (thetree, y, dat, (double *) NULL);
            if (x == oldx)
                break;
            fa_add_primheap (&prim_heap, y, CCutil_dat_edgelen (x, y, dat));
            neighbor[y] = x;
        }
        CCkdtree_undelete (thetree, y);

        fa = &(supply[y]);
        fa->name = y;
        fx = &(supply[x]);
        if (CCutil_dat_edgelen (y, fx->next->name, dat) -
            CCutil_dat_edgelen (x, fx->next->name, dat) <=
            CCutil_dat_edgelen (y, fx->prev->name, dat) -
            CCutil_dat_edgelen (x, fx->prev->name, dat)) {
            fa->prev = fx;
            fa->next = fx->next;
            fa->next->prev = fa;
            fx->next = fa;
        } else {
            fa->next = fx;
            fa->prev = fx->prev;
            fa->prev->next = fa;
            fx->prev = fa;
        }
        if (i % 10000 == 9999) {
            printf (".");
            fflush (stdout);
        }
    }

    fx = fa = &(supply[start]);
    if (outcycle) {
        i = 0;
        do {
            outcycle[i++] = fa->name;
            len += (double) CCutil_dat_edgelen (fa->name, fa->next->name, dat);
            fa = fa->next;
        } while (fa != fx);

    } else {
        do {
            len += (double) CCutil_dat_edgelen (fa->name, fa->next->name, dat);
            fa = fa->next;
        } while (fa != fx);
    }

    *val = len;
    if (ncount >= 10000)
        printf ("\n");
    printf ("Length of Farthest Addition Tour: %.2f\n", len);
    CCutil_dheap_free (&prim_heap);

CLEANUP:

    if (newtree)
        CCkdtree_free (&localkt);
    else
        CCkdtree_undelete_all (kt, ncount);
    if (neighbor)
        CC_FREE (neighbor, int);
    if (supply)
        CC_FREE (supply, faobj);
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static void fa_add_primheap (CCdheap *prim_heap, int n, int len)
#else
static void fa_add_primheap (prim_heap, n, len)
CCdheap *prim_heap;
int n;
int len;
#endif
{
    prim_heap->key[n] = (double) -len;
    CCutil_dheap_insert (prim_heap, n);
}

#ifdef CC_PROTOTYPE_ANSI
int CCkdtree_qboruvka_tour (CCkdtree *kt, int ncount, CCdatagroup *dat,
        int *outcycle, double *val)
#else
int CCkdtree_qboruvka_tour (kt, ncount, dat, outcycle, val)
CCkdtree *kt;
int ncount;
CCdatagroup *dat;
int *outcycle;
double *val;
#endif
{
    CCkdtree localkt, *thetree;
    double len;
    int i, x, y;
    char *degree = (char *) NULL;
    int *tail = (int *) NULL;
    int *tcyc = (int *) NULL;
    int tcount = 0, count;
    int rval = 0;
    int newtree = 0;
    int *perm = (int *) NULL;

    if (kt == (CCkdtree *) NULL) {
        if (CCkdtree_build (&localkt, ncount, dat, (double *) NULL)) {
            fprintf (stderr, "Unable to build CCkdtree\n");
            return 1;
        }
        thetree = &localkt;
        newtree = 1;
    } else {
        thetree = kt;
    }

    printf ("Grow a Quick-Boruvka tour \n");
    fflush (stdout);

    if (outcycle) {
        tcyc = CC_SAFE_MALLOC (2 * ncount, int);
        if (!tcyc) {
            rval = 1;
            goto CLEANUP;
        }
    }

    degree = CC_SAFE_MALLOC (ncount, char);
    if (!degree) {
        rval = 1;
        goto CLEANUP;
    }
    tail = CC_SAFE_MALLOC (ncount, int);
    if (!tail) {
        rval = 1;
        goto CLEANUP;
    }
    perm = CC_SAFE_MALLOC (ncount, int);
    if (!perm) {
        rval = 1;
        goto CLEANUP;
    }

    for (i = 0; i < ncount; i++) {
#ifndef USE_SPACEFILL
        perm[i] = i;
#endif
        degree[i] = 0;
        tail[i] = -1;

    }
#ifndef USE_SPACEFILL
    CCutil_double_perm_quicksort (perm, dat->x, ncount);
#endif

#ifdef USE_SPACEFILL
    if ((dat->norm & CC_NORM_SIZE_BITS) == CC_D2_NORM_SIZE) {
        double sflen;
        if (space_fill_curve (ncount, dat, perm, &sflen)) {
            fprintf (stderr, "space_fill_curve failed\n");
            rval = 1;
            goto CLEANUP;
        }
    } else {
        for (i = 0; i < ncount; i++)
            perm[i] = i;
        CCutil_double_perm_quicksort (perm, dat->x, ncount);
    }
#endif

    len = 0.0;
    count = 1;
    while (count < ncount) {
        for (i = 0;  i < ncount && count < ncount; i++) {
            x = perm[i];
            if (degree[x] != 2) {
                if (tail[x] != -1) {
                    CCkdtree_delete (thetree, tail[x]);
                    y = CCkdtree_node_nearest (thetree, x, dat,
                                               (double *) NULL);
                    CCkdtree_undelete (thetree, tail[x]);
                } else
                    y = CCkdtree_node_nearest (thetree, x, dat,
                                               (double *) NULL);

                /* add (x, y) to the tour */
                if (degree[x] != 0)
                    CCkdtree_delete (thetree, x);
                if (degree[y] != 0)
                    CCkdtree_delete (thetree, y);
                len += (double) CCutil_dat_edgelen (x, y, dat);
                degree[x]++;
                degree[y]++;
                if (tcyc) {
                    tcyc[tcount++] = x;
                    tcyc[tcount++] = y;
                }
                if (tail[x] == -1) {
                    if (tail[y] == -1) {
                        tail[x] = y;
                        tail[y] = x;
                    } else {
                        tail[x] = tail[y];
                        tail[tail[y]] = x;
                    }
                } else if (tail[y] == -1) {
                    tail[tail[x]] = y;
                    tail[y] = tail[x];
                } else {
                    tail[tail[x]] = tail[y];
                    tail[tail[y]] = tail[x];
                }
                if (count % 10000 == 9999) {
                    printf (".");
                    fflush (stdout);
                }
                count++;
            }
        }
    }
    for (x = 0; degree[x] != 1; x++);
    for (y = x + 1; degree[y] != 1; y++);
    if (tcyc) {
        tcyc[tcount++] = x;
        tcyc[tcount++] = y;
    }
    len += (double) CCutil_dat_edgelen (x, y, dat);
    *val = len;
    if (ncount >= 10000)
        printf ("\n");
    printf ("Length of Quick-Boruvka Tour: %.2f\n", len);

    if (tcyc) {
        if (CCutil_edge_to_cycle (ncount, tcyc, outcycle)) {
            fprintf (stderr, "ERROR: greedy tour is not a tour\n");
            rval = 1;
            goto CLEANUP;
        }
    }

CLEANUP:

    if (newtree)
        CCkdtree_free (&localkt);
    else
        CCkdtree_undelete_all (kt, ncount);
    CC_IFFREE (tcyc, int);
    CC_IFFREE (degree, char);
    CC_IFFREE (tail, int);
    CC_IFFREE (perm, int);
    return rval;
}


#ifdef CC_PROTOTYPE_ANSI
int CCkdtree_boruvka_tour (CCkdtree *kt, int ncount, CCdatagroup *dat,
        int *outcycle, double *val)
#else
int CCkdtree_boruvka_tour (kt, ncount, dat, outcycle, val)
CCkdtree *kt;
int ncount;
CCdatagroup *dat;
int *outcycle;
double *val;
#endif
{
    CCkdtree localkt, *thetree;
    double len;
    int i, x, y;
    char *degree = (char *) NULL;
    int *tail = (int *) NULL;
    int *tcyc = (int *) NULL;
    int tcount = 0, count;
    int rval = 0;
    int newtree = 0;
    int *getem = (int *) NULL;
    int *getemlen = (int *) NULL;
    int *perm = (int *) NULL;
    int getemcount, newgetemcount;
    int round = 0;
    int *neighbor = (int *) NULL;

    if (kt == (CCkdtree *) NULL) {
        if (CCkdtree_build (&localkt, ncount, dat, (double *) NULL)) {
            fprintf (stderr, "Unable to build CCkdtree\n");
            return 1;
        }
        thetree = &localkt;
        newtree = 1;
    } else {
        thetree = kt;
    }

    printf ("Grow a Boruvka tour \n");
    fflush (stdout);

    if (outcycle) {
        tcyc = CC_SAFE_MALLOC (2 * ncount, int);
        if (!tcyc) {
            rval = 1;
            goto CLEANUP;
        }
    }

    degree = CC_SAFE_MALLOC (ncount, char);
    if (!degree) {
        rval = 1;
        goto CLEANUP;
    }
    tail = CC_SAFE_MALLOC (ncount, int);
    if (!tail) {
        rval = 1;
        goto CLEANUP;
    }
    neighbor = CC_SAFE_MALLOC (ncount, int);
    if (!neighbor) {
        rval = 1;
        goto CLEANUP;
    }
    getem = CC_SAFE_MALLOC (ncount, int);
    if (!getem) {
        rval = 1;
        goto CLEANUP;
    }
    getemlen = CC_SAFE_MALLOC (ncount, int);
    if (!getemlen) {
        rval = 1;
        goto CLEANUP;
    }
    perm = CC_SAFE_MALLOC (ncount, int);
    if (!perm) {
        rval = 1;
        goto CLEANUP;
    }
    getemcount = ncount;

    for (i = 0; i < ncount; i++) {
        degree[i] = 0;
        tail[i] = -1;
        getem[i] = i;
    }

    len = 0.0;
    count = 1;
    while (count < ncount) {
        round++;
        i = 0;
        while (i < getemcount) {
            x = getem[i];
            if (degree[x] != 2) {
                if (tail[x] != -1) {
                    CCkdtree_delete (thetree, tail[x]);
                    neighbor[i] = CCkdtree_node_nearest (thetree, x, dat,
                                  (double *) NULL);
                    CCkdtree_undelete (thetree, tail[x]);
                } else {
                    neighbor[i] = CCkdtree_node_nearest (thetree, x, dat,
                                  (double *) NULL);
                }
                getemlen[i] = CCutil_dat_edgelen (x, neighbor[i], dat);
                perm[i] = i;
                i++;
            } else {
                getem[i] = getem[--getemcount];
            }
        }
        CCutil_int_perm_quicksort (perm, getemlen, getemcount);
        newgetemcount = 0;
        for (i = 0;  i < getemcount && count < ncount; i++) {
            x = getem[perm[i]];
            if (degree[x] != 2) {
                y = neighbor[perm[i]];
                if (degree[y] != 2 && tail[x] != y) {
                    /* add (x, y) to the tour */
                    if (degree[x] != 0)
                        CCkdtree_delete (thetree, x);
                    else
                        perm[newgetemcount++] = x;
                    if (degree[y] != 0)
                        CCkdtree_delete (thetree, y);
                    len += (double) CCutil_dat_edgelen (x, y, dat);
                    degree[x]++;
                    degree[y]++;
                    if (tcyc) {
                        tcyc[tcount++] = x;
                        tcyc[tcount++] = y;
                    }
                    if (tail[x] == -1) {
                        if (tail[y] == -1) {
                            tail[x] = y;
                            tail[y] = x;
                        } else {
                            tail[x] = tail[y];
                            tail[tail[y]] = x;
                        }
                    } else if (tail[y] == -1) {
                        tail[tail[x]] = y;
                        tail[y] = tail[x];
                    } else {
                        tail[tail[x]] = tail[y];
                        tail[tail[y]] = tail[x];
                    }
                    if (count % 10000 == 9999) {
                        printf (".");
                        fflush (stdout);
                    }
                    count++;
                } else {
                    perm[newgetemcount++] = x;
                }
            }
        }
        getemcount = newgetemcount;
        {
            int *temp;
            SWAP (getem, perm, temp);
        }
    }
    for (x = 0; degree[x] != 1; x++);
    for (y = x + 1; degree[y] != 1; y++);
    if (tcyc) {
        tcyc[tcount++] = x;
        tcyc[tcount++] = y;
    }
    len += (double) CCutil_dat_edgelen (x, y, dat);
    *val = len;
    if (ncount >= 10000)
        printf ("\n");
    printf ("Length of Boruvka Tour: %.0f  (%d Rounds)\n", len, round);

    if (tcyc) {
        if (CCutil_edge_to_cycle (ncount, tcyc, outcycle)) {
            fprintf (stderr, "ERROR: greedy tour is not a tour\n");
            rval = 1;
            goto CLEANUP;
        }
    }

CLEANUP:

    if (newtree)
        CCkdtree_free (&localkt);
    else
        CCkdtree_undelete_all (kt, ncount);
    if (tcyc)
        CC_FREE (tcyc, int);
    if (degree)
        CC_FREE (degree, char);
    if (tail)
        CC_FREE (tail, int);
    if (neighbor)
        CC_FREE (neighbor, int);
    if (getem)
        CC_FREE (getem, int);
    if (getemlen)
        CC_FREE (getemlen, int);
    if (perm)
        CC_FREE (perm, int);
    return rval;
}

#ifdef USE_SPACEFILL
#ifdef CC_PROTOTYPE_ANSI
static int space_fill_curve (int ncount, CCdatagroup *dat, int *outcyc,
                             double *len)
#else
static int space_fill_curve (ncount, dat, outcyc, len)
int ncount;
CCdatagroup *dat;
int *outcyc;
double *len;
#endif
{
    int i, h, M;
    int x, y, z;
    int k, nbits;
    int *th = (int *) NULL;
    int *cyc = (int *) NULL;
    double tx, ty, tM;

    /* From Platzman and Bartholdi, JACM 36 (1989) 719-737. */

    if ((dat->norm & CC_NORM_SIZE_BITS) != CC_D2_NORM_SIZE) {
        printf ("Need a 2-coordinate norm to use space filling curve\n");
        fflush (stdout);
        return 1;
    }

    th = CC_SAFE_MALLOC (ncount, int);
    if (!th)
        return 1;

    if (outcyc != (int *) NULL) {
        cyc = outcyc;
    } else {
        cyc = CC_SAFE_MALLOC (ncount, int);
        if (!cyc) {
            CC_FREE (th, int);
            return 1;
        }
    }

    tM = 0.0;
    tx = 0.0;
    ty = 0.0;

    for (i = 0; i < ncount; i++) {
        cyc[i] = i;
        if (dat->x[i] < tx)
            tx = dat->x[i];
        else if (dat->x[i] > tM)
            tM = dat->x[i];

        if (dat->y[i] < ty)
            ty = dat->y[i];
        else if (dat->y[i] > tM)
            tM = dat->y[i];
    }

    M = (int) (tM - tx - ty + 1.0);

    nbits = 0;
    while ((1 << nbits) < ncount)
       nbits++;
    nbits += 2;

    for (i = 0; i < ncount; i++) {
        x = (int) (dat->x[i] - tx);    /* To make coords nonnegative ints */
        y = (int) (dat->y[i] - ty);

        h = 0;
        k = 1;
        if (x > y) {
            h = 1;
            x = M - x;
            y = M - y;
        }

        while (k < nbits) {
            h <<= 1;
            k++;

            if (x + y > M) {
                h++;
                z = M - y;
                y = x;
                x = z;
            }

            if (k < nbits) {
                h <<= 1;
                k++;

                x <<= 1;
                y <<= 1;

                if (y > M) {
                    h++;
                    z = y - M;
                    y = M - x;
                    x = z;
                }
            }
        }
        th[i] = h;
    }

    CCutil_int_perm_quicksort (cyc, th, ncount);
    *len = (double) CCutil_dat_edgelen (cyc[ncount - 1], cyc[0], dat);
    for (i = 1; i < ncount; i++)
        (*len) += CCutil_dat_edgelen (cyc[i - 1], cyc[i], dat);
    printf ("Spacefilling Curve Tour: %.2f\n", *len);
    fflush (stdout);

    if (th)
        CC_FREE (th, int);
    if (!outcyc && cyc)
        CC_FREE (cyc, int);

    return 0;
}
#endif
