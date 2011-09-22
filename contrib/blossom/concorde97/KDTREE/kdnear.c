/***************************************************************************/
/*                                                                         */
/*                 ROUTINES FOR FINDING NEAREST NEIGHBORS                  */
/*                                                                         */
/*  (Based on Jon Bentley's paper "K-d trees for semidynamic point sets")  */
/*                                                                         */
/*                           TSP CODE                                      */
/*                                                                         */
/*                                                                         */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook                       */
/*  Date: February 24, 1995  (cofeb24)                                     */
/*  Changes: August 6 (bico)  -  added wcoord to fixed radius search       */
/*                                                                         */
/*                                                                         */
/*  EXPORTED FUNCTIONS:                                                    */
/*    int CCkdtree_k_nearest (CCkdtree *kt, int ncount, int k,             */
/*            CCdatagroup *dat, double *wcoord, int wantlist, int *ocount, */
/*            int **olist)                                                 */
/*      RETURNS the k-nearest neighbor graph.                              */
/*        -kt can be NULL, otherwise it should point to a CCkdtree buildt  */
/*         by a call to kdbuild ()                                         */
/*        -ncount is the number of points.                                 */
/*        -k is the number of nearest neighbors wanted.                    */
/*        -wcoord is an array of node weights (like Held-Karp), it can     */
/*         be NULL. The weights should be nonnegative.                     */
/*        -wantlist is 1 if you want the function to return the edges.     */
/*        -ocount returns the number of edges (if wantlist is 1) and       */
/*         olist returns the edgelist is end1 end2 format.                 */
/*    int CCkdtree_quadrant_k_nearest (CCkdtree *kt, int ncount, int k,    */
/*           CCdatagroup *dat, double *wcoord,                             */
/*           int wantlist, int *ocount, int **olist)                       */
/*      RETURNS the quadrant k-nearest neighbor graph.                     */
/*        -see CCkdtree_k_nearest.                                         */
/*    int CCkdtree_node_k_nearest (CCkdtree *kt, int ncount, int n, int k, */
/*           CCdatagroup *dat, double *wcoord, int *list)                  */
/*      RETURNS the k nearest points to point n.                           */
/*        -The k points are return in list (and list must be allocated by  */
/*         calling routine.                                                */
/*        -kt is a pointer to a CCkdtree previously built by               */
/*         CCkdtree_build.                                                 */
/*    int CCkdtree_node_quadrant_k_nearest (CCkdtree *kt, int ncount,      */
/*            int n, int k, CCdatagroup *dat, double *wcoord, int *list)   */
/*      RETURNS the quadrant k nearest point to point n.                   */
/*        -see CCkdtree_node_k_nearest.                                    */
/*    int CCkdtree_node_nearest (ktree *kt, int n, CCdatagroup *dat,       */
/*          double *wcoord)                                                */
/*      RETURNS the nearest point to point n.                              */
/*        -kt CANNOT be NULL.                                              */
/*        -The point is returned as the function value. kt is a pointer    */
/*         to a CCkdtree (previously buildt by a call to CCkdtree_build)   */
/*    int CCkdtree_fixed_radius_nearest (CCkdtree *kt, CCdatagroup *dat,   */
/*           double *wcoord, int n, double rad,                            */
/*           int (*doit_fn) (int, int, void *), void *pass_param)          */
/*      ACTION: Calls the function doit_fn (n, a, void *), where a ranges  */
/*              over all points within distance rad of the point n. The    */
/*              void * field can be used to bundle a group of parmeters    */
/*              into pass_param that will be passed to doit_fn.            */
/*        -kt CANNOT be NULL.                                              */
/*        -doit_fn can also call CCkdtree_fixed_radius_nearest (no globals */
/*         are set by the function calls)                                  */
/*        -pass_param can be NULL or used to point to a structure with     */
/*         with parameters for doit_fn.                                    */
/*    int CCkdtree_nearest_neighbor_tour (CCkdtree *kt, int ncount,        */
/*            int start, CCdatagroup *dat, int *outcycle, double *val)     */
/*        -kt can be NULL.                                                 */
/*        -Node weights are not used.                                      */
/*        -start is the starting node for the tour.                        */
/*        -if outcycle is not NULL, then it should point to a array of     */
/*         length at least ncount (allocated by the calling routine). The  */
/*         cycle will be returned in the array in node node node format.   */
/*        -the length of the tour is return in val.                        */
/*    int CCkdtree_nearest_neighbor_2match (CCkdtree *kt, int ncount,      */
/*           int start, CCdatagroup *dat, int *outmatch, double *val)      */
/*        -Like CCkdtree_nearest_neighbor_tour. If outmatch is not NULL    */
/*         then it should point to an array of length at leaast 2*ncount.  */
/*                                                                         */
/*  NOTES:                                                                 */
/*       If memory is tight, use CCkdtree_node_k_nearest to get the edges  */
/*    one node at a time. (CCkdtree_k_nearest () builds a hash table to    */
/*    avoid duplicate edges, and it will use 8 * nedges bytes.)            */
/*       CCkdtree_node_nearest returns the nearest point as the function   */
/*    value; CCkdtree_fixed_radius_nearest returns 1 if doit_fn returns a  */
/*    a nonzero value, otherwise it returns 0; all other routines return 0 */
/*    if successful and 1 otherwise.                                       */
/*                                                                         */
/***************************************************************************/


#include "machdefs.h"
#include "util.h"
#include "kdtree.h"

#define BIGDOUBLE 100000000.0
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
#define NEAR_HEAP_CUTOFF 100  /* When to switch from list to heap       */
                              /* On an RS6000, the heap started winning */
                              /* at 100 (by 200 it was 3 times faster)  */

typedef struct shortedge {
    int end;
    double length;
} shortedge;

typedef struct intptr {
    int this;
    struct intptr *next;
} intptr;

#define Fedgelen(n1, n2)                                                     \
    (datw != (double *) NULL ?                                               \
      CCutil_dat_edgelen ((n1), (n2), dat)                                   \
            + datw[(n1)] + datw[(n2)] :                                      \
      CCutil_dat_edgelen ((n1), (n2), dat))

#ifdef CC_PROTOTYPE_ANSI

static void
    node_k_nearest_work (CCkdtree *thetree, CCdatagroup *dat, double *datw,
        CCkdnode *p, CCdheap *near_heap, int *heap_names, int *heap_count,
        int target, int num, shortedge *nearlist, double *worst_on_list,
        CCkdbnds *box),
    node_nearest_work (CCkdtree *thetree, CCdatagroup *dat, double *datw,
         CCkdnode *p, int target, double *ndist, int *nnode);
static int
    run_kdtree_k_nearest (CCkdtree *kt, int ncount, int k, CCdatagroup *dat,
         double *wcoord, int wantlist, int *ocount, int **olist, int doquad),
    put_in_table (int i, int j, int *added, intptr **table),
    q_run_it (CCkdtree *thetree, CCdatagroup *dat, double *datw, int *llist,
         int *lcount, int *list, int target, int num, CCkdbnds *box),
    run_kdtree_node_k_nearest (CCkdtree *thetree, CCdatagroup *dat,
         double *datw,
         int *list, int target, int num, CCkdbnds *box),
    ball_in_bounds (CCdatagroup *dat, CCkdbnds *bnds, int n, double dist),
    fixed_radius_nearest_work (CCkdtree *thetree, CCkdnode *p,
         int (*doit_fn) (int, int, void *),
         int target, double dist, CCdatagroup *dat, double *wcoord,
         double xtarget, double ytarget, void *pass_param);

#else

static void
    node_k_nearest_work (),
    node_nearest_work ();
static int
    run_kdtree_k_nearest (),
    put_in_table (),
    q_run_it (),
    run_kdtree_node_k_nearest (),
    ball_in_bounds (),
    fixed_radius_nearest_work ();

#endif

CC_PTR_ALLOC_ROUTINE (intptr, intptralloc, intptrchunklist, intptrfreelist)
CC_PTR_FREE_ROUTINE (intptr, intptrfree, intptrfreelist)
CC_PTR_FREE_WORLD_ROUTINE (intptr, intptrfree_world, intptrchunklist,
        intptrfreelist)
CC_PTR_LEAKS_ROUTINE (intptr, intptr_check_leaks, intptrchunklist,
        intptrfreelist, this, int)

#ifdef CC_PROTOTYPE_ANSI
int CCkdtree_k_nearest (CCkdtree *kt, int ncount, int k, CCdatagroup *dat,
        double *wcoord, int wantlist, int *ocount, int **olist)
#else
int CCkdtree_k_nearest (kt, ncount, k, dat, wcoord, wantlist, ocount, olist)
CCkdtree *kt;
int ncount, k;
CCdatagroup *dat;
double *wcoord;
int wantlist, *ocount, **olist;
#endif
{
    return run_kdtree_k_nearest (kt, ncount, k, dat, wcoord,
                                 wantlist, ocount, olist, 0);
}

#ifdef CC_PROTOTYPE_ANSI
int CCkdtree_quadrant_k_nearest (CCkdtree *kt, int ncount, int k,
        CCdatagroup *dat, double *wcoord, int wantlist, int *ocount,
        int **olist)
#else
int CCkdtree_quadrant_k_nearest (kt, ncount, k, dat, wcoord, wantlist, ocount,
        olist)
CCkdtree *kt;
int ncount, k;
CCdatagroup *dat;
double *wcoord;
int wantlist, *ocount, **olist;
#endif
{
    return run_kdtree_k_nearest (kt, ncount, k, dat, wcoord,
                                 wantlist, ocount, olist, 1);
}


#ifdef CC_PROTOTYPE_ANSI
static int run_kdtree_k_nearest (CCkdtree *kt, int ncount, int k,
        CCdatagroup *dat, double *wcoord, int wantlist, int *ocount,
        int **olist, int doquad)
#else
static int run_kdtree_k_nearest (kt, ncount, k, dat, wcoord, wantlist, ocount,
        olist, doquad)
CCkdtree *kt;
int ncount, k;
CCdatagroup *dat;
double *wcoord;
int wantlist, *ocount, **olist;
int doquad;
#endif
{
    int i, n;
    intptr *ip, *ipnext;
    int total, onlist;
    CCkdtree localkt, *mykt;
    int added, ntotal = 0;
    int rval = 0;
    int *list = (int *) NULL;
    int goal = (doquad ? (4 * k) : k);
    int newtree = 0;
    intptr **table = (intptr **) NULL;

    if (wcoord != (double *) NULL) {
        for (i = 0; i < ncount; i++) {
            if (wcoord[i] < -0.00000001) {
                fprintf (stderr, "Cannot CCkdtree with negative node weights\n");
                return 1;
            }
        }
    }

    if (wantlist) {
        *ocount = 0;
        *olist = (int *) NULL;
    }

    if (kt == (CCkdtree *) NULL) {
        if (CCkdtree_build (&localkt, ncount, dat, wcoord)) {
            fprintf (stderr, "Unable to build CCkdtree\n");
            return 1;
        }
        mykt = &localkt;
        newtree = 1;
    } else {
        mykt = kt;
    }


    table = CC_SAFE_MALLOC (ncount, intptr *);
    if (!table) {
        rval = 1;
        goto CLEANUP;
    }
    for (i = 0; i < ncount; i++)
        table[i] = (intptr *) NULL;
    list = CC_SAFE_MALLOC (goal, int);
    if (!list) {
        rval = 1;
        goto CLEANUP;
    }

    for (n = 0; n < ncount; n++) {
        if (doquad) {
            if (CCkdtree_node_quadrant_k_nearest (mykt, ncount, n, k, dat,
                       wcoord, list)) {
                rval = 1;
                goto CLEANUP;
            }
        } else {
            if (CCkdtree_node_k_nearest (mykt, ncount, n, k, dat, wcoord,
                                         list)) {
                rval = 1;
                goto CLEANUP;
            }
        }
        for (i = 0; i < goal; i++) {
            if (list[i] != -1) {
                if (put_in_table (n, list[i], &added, table))  {
                    rval = 1;
                    goto CLEANUP;
                } else {
                    ntotal += added;
                }
            }
        }
/*
        if (n == 0) {
            printf ("Neighbors of Node %d (%d, %d) :\n", n,
                                      (int) dat->x[n], (int) dat->y[n]);
            for (i = 0; i < goal; i++) {
                if (list[i] != -1) {
                    printf ("%d  %d (%d, %d)\n", list[i],
                      CCutil_dat_edgelen (n, list[i], dat),
                      (int) dat->x[list[i]], (int) dat->y[list[i]]);
                }
            }
        }
*/
        if (n % 1000 == 999) {
            printf (".");
            fflush (stdout);
        }
    }
    printf (" %d edges\n", ntotal);
    fflush (stdout);

    if (wantlist) {
        int j = 0;
        *olist = CC_SAFE_MALLOC (2 * ntotal, int);
        if (!(*olist)) {
            rval = 1;
            goto CLEANUP;
        }
        *ocount = ntotal;
        for (i = 0; i < ncount; i++) {
            for (ip = table[i]; ip; ip = ipnext) {
                ipnext =  ip->next;
                (*olist)[j++] = i;
                (*olist)[j++] = ip->this;
                intptrfree (ip);
            }
            table[i] = (intptr *) NULL;
        }
    } else {
        for (i = 0; i < ncount; i++) {
            for (ip = table[i]; ip; ip = ipnext) {
                ipnext =  ip->next;
                intptrfree (ip);
            }
            table[i] = (intptr *) NULL;
        }
    }
    if (intptr_check_leaks (&total, &onlist)) {
        fprintf (stderr, "WARNING: %d outstanding intptrs in kdnear\n",
                 total - onlist);
    }

CLEANUP:

    intptrfree_world ();
    if (table)
        CC_FREE (table, intptr *);
    if (list)
        CC_FREE (list, int);
    if (newtree)
        CCkdtree_free (&localkt);

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static int put_in_table (int i, int j, int *added, intptr **table)
#else
static int put_in_table (i, j, added, table)
int i, j;
int *added;
intptr **table;
#endif
{
    intptr *ip;

    if (j < i) {
        int temp;
        SWAP(i, j, temp);
    }

    for (ip = table[i]; ip; ip = ip->next)
        if (ip->this == j) {
            *added = 0;
            return 0;
        }
    ip = intptralloc ();
    if (!ip) {
        *added = 0;
        return 1;
    }
    ip->this = j;
    ip->next = table[i];
    table[i] = ip;
    *added = 1;
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCkdtree_node_quadrant_k_nearest (CCkdtree *kt, int ncount, int n, int k,
        CCdatagroup *dat, double *wcoord, int *list)
#else
int CCkdtree_node_quadrant_k_nearest (kt, ncount, n, k, dat, wcoord, list)
CCkdtree *kt;
int ncount, n, k;
CCdatagroup *dat;
double *wcoord;
int *list;
#endif
{
    CCkdbnds localbnds;
    int i, lcount = 0;
    int *llist = (int *) NULL;
    int rval = 0;
    CCkdtree localkt;
    CCkdtree *thetree;
    int newtree = 0;

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

    llist = CC_SAFE_MALLOC (k, int);
    if (!llist) {
        rval = 1;
        goto CLEANUP;
    }

    localbnds.x[0] = dat->x[n];
    localbnds.x[1] = BIGDOUBLE;
    localbnds.y[0] = dat->y[n];
    localbnds.y[1] = BIGDOUBLE;
    if (q_run_it (thetree, dat, wcoord, llist, &lcount, list, n, k,
                  &localbnds)) {
        fprintf (stderr, "run_kdtree_node_k_nearest failed\n");
        rval = 1;
        goto CLEANUP;
    }

    localbnds.x[0] = dat->x[n];
    localbnds.x[1] = BIGDOUBLE;
    localbnds.y[0] = -BIGDOUBLE;
    localbnds.y[1] = dat->y[n];
    if (q_run_it (thetree, dat, wcoord, llist, &lcount, list, n, k,
                  &localbnds)) {
        fprintf (stderr, "run_kdtree_node_k_nearest failed\n");
        rval = 1;
        goto CLEANUP;
    }

    localbnds.x[0] = -BIGDOUBLE;
    localbnds.x[1] = dat->x[n];
    localbnds.y[0] = -BIGDOUBLE;
    localbnds.y[1] = dat->y[n];
    if (q_run_it (thetree, dat, wcoord, llist, &lcount, list, n, k,
                  &localbnds)) {
        fprintf (stderr, "run_kdtree_node_k_nearest failed\n");
        rval = 1;
        goto CLEANUP;
    }

    localbnds.x[0] = -BIGDOUBLE;
    localbnds.x[1] = dat->x[n];
    localbnds.y[0] = dat->y[n];
    localbnds.y[1] = BIGDOUBLE;
    if (q_run_it (thetree, dat, wcoord, llist, &lcount, list, n, k,
                  &localbnds)) {
        fprintf (stderr, "run_kdtree_node_k_nearest failed\n");
        rval = 1;
        goto CLEANUP;
    }

    for (i = lcount; i < (4 * k); i++)
        list[i] = -1;

CLEANUP:

    CC_FREE (llist, int);
    if (newtree)
        CCkdtree_free (&localkt);

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static int q_run_it (CCkdtree *thetree, CCdatagroup *dat, double *datw,
        int *llist, int *lcount, int *list, int target, int num, CCkdbnds *box)
#else
static int q_run_it (thetree, dat, datw, llist, lcount, list, target, num, box)
CCkdtree *thetree;
CCdatagroup *dat;
double *datw;
int *llist;
int *lcount;
int *list;
int target;
int num;
CCkdbnds *box;
#endif
{
    int i, j;

    if (run_kdtree_node_k_nearest (thetree, dat, datw, llist, target, num,
                                   box))
        return 1;
    for (i = 0; i < num; i++) {
        if (llist[i] != -1) {
            for (j = 0; j < *lcount; j++)
                if (list[j] == llist[i])
                    break;
            if (j == *lcount)
                list[(*lcount)++] = llist[i];
        }
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCkdtree_node_k_nearest (CCkdtree *kt, int ncount, int n, int k,
        CCdatagroup *dat, double *wcoord, int *list)
#else
int CCkdtree_node_k_nearest (kt, ncount, n, k, dat, wcoord, list)
CCkdtree *kt;
int ncount, n, k;
CCdatagroup *dat;
double *wcoord;
int *list;
#endif
{
    CCkdtree localkt;
    CCkdtree *thetree;
    int newtree = 0;
    int rval = 0;

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

    rval = run_kdtree_node_k_nearest (thetree, dat, wcoord, list, n, k,
                                      (CCkdbnds *) NULL);
    if (newtree)
        CCkdtree_free (&localkt);
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static int run_kdtree_node_k_nearest (CCkdtree *thetree, CCdatagroup *dat,
        double *datw, int *list, int target, int num, CCkdbnds *box)
#else
static int run_kdtree_node_k_nearest (thetree, dat, datw, list, target, num,
        box)
CCkdtree *thetree;
CCdatagroup *dat;
double *datw;
int *list;
int target;
int num;
CCkdbnds *box;
#endif
{
    int i;
    CCkdnode *p, *lastp;
    double diff;
    CCdheap near_heap;
    int *heap_names =  (int *) NULL;
    int heap_count = 0;
    shortedge *nearlist = (shortedge *) NULL;
    double worst_on_list = BIGDOUBLE;

    if (num >= NEAR_HEAP_CUTOFF) {
        if (CCutil_dheap_init (&near_heap, num))
            return 1;
        heap_names = CC_SAFE_MALLOC (num, int);
        if (!heap_names) {
            CCutil_dheap_free (&near_heap);
            return 1;
        }
        heap_count = 0;
    } else {
        nearlist = CC_SAFE_MALLOC (num + 1, shortedge);
        if (!nearlist) {
            CCutil_dheap_free (&near_heap);
            CC_FREE (heap_names, int);
            return 1;
        }
        for (i = 0; i < num; i++)
            nearlist[i].length = BIGDOUBLE;
        nearlist[num].length = -BIGDOUBLE;
    }

/*
    To do top down search just use:

        node_k_nearest_work (thetree->root);
*/

    p = thetree->bucketptr[target];
    node_k_nearest_work (thetree, dat, datw, p, &near_heap, heap_names,
                         &heap_count, target, num, nearlist, &worst_on_list,
                         box);
    while (1) {
        lastp = p;
        p = p->father;
        if (p == (CCkdnode *) NULL)
            break;
        switch (p->cutdim) {
        case 0:
            diff = p->cutval - dat->x[target];
            if (lastp == p->loson) {    /* So target is on low side */
               if (worst_on_list > (double) ((int) diff))
                   if (box == (CCkdbnds *) NULL || p->cutval <= box->x[1])
                       node_k_nearest_work (thetree, dat, datw, p->hison,
                              &near_heap, heap_names, &heap_count, target,
                              num, nearlist, &worst_on_list, box);
            } else {
               if (worst_on_list > (double) ((int) -diff))
                   if (box == (CCkdbnds *) NULL || p->cutval >= box->x[0])
                       node_k_nearest_work (thetree, dat, datw, p->loson,
                              &near_heap, heap_names, &heap_count, target,
                              num, nearlist, &worst_on_list, box);
            }
            break;
        case 1:
            diff = p->cutval - dat->y[target];
            if (lastp == p->loson) {
               if (worst_on_list > (double) ((int) diff))
                   if (box == (CCkdbnds *) NULL || p->cutval <= box->y[1])
                       node_k_nearest_work (thetree, dat, datw, p->hison,
                              &near_heap, heap_names, &heap_count, target,
                              num, nearlist, &worst_on_list, box);
            } else {
               if (worst_on_list > (double) ((int) -diff))
                   if (box == (CCkdbnds *) NULL || p->cutval >= box->y[0])
                       node_k_nearest_work (thetree, dat, datw, p->loson,
                              &near_heap, heap_names, &heap_count, target,
                              num, nearlist, &worst_on_list, box);
            }
            break;
        case 2:
            if (lastp == p->loson) {
                if (worst_on_list > p->cutval + datw[target])
                    node_k_nearest_work (thetree, dat, datw, p->hison,
                              &near_heap, heap_names, &heap_count, target,
                              num, nearlist, &worst_on_list, box);
            } else {
                node_k_nearest_work (thetree, dat, datw, p->loson, &near_heap,
                              heap_names, &heap_count, target, num, nearlist,
                              &worst_on_list, box);
            }
            break;
        }
        if (datw == (double *) NULL && p->bnds &&
               ball_in_bounds (dat, p->bnds, target, worst_on_list))
              /* Doing extra check for box with quad-nearest appears to slow */
              /* things down.                                                */
            break;
    }

    if (num >= NEAR_HEAP_CUTOFF) {
        if (heap_count < num) {
            if (box == (CCkdbnds *) NULL) {
                fprintf (stderr, "WARNING: There do not exist %d neighbors\n",
                         num);
            }
            for (i = 0; i < heap_count; i++) {
                list[i] = heap_names[i];
            }
            for (; i < num; i++)
                list[i] = -1;
        } else {
            for (i = 0; i < num; i++)
                list[i] = heap_names[i];
        }
    } else {
        int ntot = 0;
        for (i = 0; i < num; i++) {
            if (nearlist[i].length < BIGDOUBLE)
                list[ntot++] = nearlist[i].end;
        }
        if (ntot < num) {
            if (box == (CCkdbnds *) NULL) {
                fprintf (stderr, "WARNING: There do not exist %d neighbors\n",
                         num);
            }
            for (i = ntot; i < num; i++)
                list[i] = -1;
        }
    }

    if (num >= NEAR_HEAP_CUTOFF) {
        CC_FREE (heap_names, int);
        CCutil_dheap_free (&near_heap);
    } else {
        CC_FREE (nearlist, shortedge);
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static void node_k_nearest_work (CCkdtree *thetree, CCdatagroup *dat,
        double *datw, CCkdnode *p, CCdheap *near_heap, int *heap_names,
        int *heap_count, int target, int num, shortedge *nearlist,
        double *worst_on_list, CCkdbnds *box)
#else
static void node_k_nearest_work (thetree, dat, datw, p, near_heap, heap_names,
        heap_count, target, num, nearlist, worst_on_list, box)
CCkdtree *thetree;
CCdatagroup *dat;
double *datw;
CCkdnode *p;
CCdheap *near_heap;
int *heap_names;
int *heap_count;
int target, num;
shortedge *nearlist;
double *worst_on_list;
CCkdbnds *box;
#endif
{
    int i, h, k;
    double val, thisx, thisdist;

    if (p->bucket) {
        if (num >= NEAR_HEAP_CUTOFF) {
            for (i = p->lopt; i <= p->hipt; i++) {
                if (thetree->perm[i] != target) {
                    if (box == (CCkdbnds *) NULL ||
                       (dat->x[thetree->perm[i]] >= box->x[0] &&
                        dat->x[thetree->perm[i]] <= box->x[1] &&
                        dat->y[thetree->perm[i]] >= box->y[0] &&
                        dat->y[thetree->perm[i]] <= box->y[1])) {
                        thisdist = Fedgelen (thetree->perm[i], target);
                        if (*heap_count < num) {
                            near_heap->key[*heap_count] = -thisdist;
                            heap_names[*heap_count] = thetree->perm[i];
                            CCutil_dheap_insert (near_heap, *heap_count);
                            (*heap_count)++;
                        } else if (*worst_on_list > thisdist) {
                            h = CCutil_dheap_deletemin (near_heap);
                            heap_names[h] = thetree->perm[i];
                            near_heap->key[h] = -thisdist;
                            CCutil_dheap_insert (near_heap, h);
                            h = CCutil_dheap_findmin (near_heap);
                            *worst_on_list = -near_heap->key[h];
                        }
                    }
                }
            }
        } else {
            for (i = p->lopt; i <= p->hipt; i++) {
                if (thetree->perm[i] != target) {
                    if (box == (CCkdbnds *) NULL ||
                       (dat->x[thetree->perm[i]] >= box->x[0] &&
                        dat->x[thetree->perm[i]] <= box->x[1] &&
                        dat->y[thetree->perm[i]] >= box->y[0] &&
                        dat->y[thetree->perm[i]] <= box->y[1])) {
                        thisdist = Fedgelen (thetree->perm[i], target);
                        if (*worst_on_list > thisdist) {
                            for (k = 0; nearlist[k+1].length > thisdist; k++) {
                                nearlist[k].end = nearlist[k + 1].end;
                                nearlist[k].length = nearlist[k + 1].length;
                            }
                            nearlist[k].length = thisdist;
                            nearlist[k].end = thetree->perm[i];
                            *worst_on_list = nearlist[0].length;
                        }
                    }
                }
            }
        }
    } else {
        val = p->cutval;
        switch (p->cutdim) {
        case 0:
            thisx = dat->x[target];
            if (thisx < val) {
                node_k_nearest_work (thetree, dat, datw, p->loson, near_heap,
                        heap_names, heap_count, target, num, nearlist,
                        worst_on_list, box);
                /* Truncation for floating point coords */
                if (*worst_on_list > (double) ((int) (val - thisx)))
                    if (box == (CCkdbnds *) NULL || val >= box->x[0])
                        node_k_nearest_work (thetree, dat, datw, p->hison,
                               near_heap, heap_names, heap_count, target,
                               num, nearlist, worst_on_list, box);
            } else {
                node_k_nearest_work (thetree, dat, datw, p->hison, near_heap,
                               heap_names, heap_count, target, num, nearlist,
                               worst_on_list, box);
                if (*worst_on_list > (double) ((int) (thisx - val)))
                    if (box == (CCkdbnds *) NULL || val <= box->x[1])
                        node_k_nearest_work (thetree, dat, datw, p->loson,
                               near_heap, heap_names, heap_count, target,
                               num, nearlist, worst_on_list, box);
            }
            break;
        case 1:
            thisx = dat->y[target];
            if (thisx < val) {
                node_k_nearest_work (thetree, dat, datw, p->loson, near_heap,
                               heap_names, heap_count, target, num, nearlist,
                               worst_on_list, box);
                if (*worst_on_list > (double) ((int) (val - thisx)))
                    if (box == (CCkdbnds *) NULL || val >= box->y[0])
                        node_k_nearest_work (thetree, dat, datw, p->hison,
                               near_heap, heap_names, heap_count, target,
                               num, nearlist, worst_on_list, box);
            } else {
                node_k_nearest_work (thetree, dat, datw, p->hison, near_heap,
                               heap_names, heap_count, target, num, nearlist,
                               worst_on_list, box);
                if (*worst_on_list > (double) ((int) (thisx - val)))
                    if (box == (CCkdbnds *) NULL || val <= box->y[1])
                        node_k_nearest_work (thetree, dat, datw, p->loson,
                               near_heap, heap_names, heap_count, target,
                               num, nearlist, worst_on_list, box);
            }
            break;
        case 2:
            thisx = datw[target];
            node_k_nearest_work (thetree, dat, datw, p->loson, near_heap,
                               heap_names, heap_count, target, num, nearlist,
                               worst_on_list, box);
            if (*worst_on_list > val + thisx)
                node_k_nearest_work (thetree, dat, datw, p->hison, near_heap,
                               heap_names, heap_count, target, num, nearlist,
                               worst_on_list, box);
            break;
        }
    }
}


#ifdef CC_PROTOTYPE_ANSI
int CCkdtree_node_nearest (CCkdtree *kt, int n, CCdatagroup *dat,
        double *wcoord)
#else
int CCkdtree_node_nearest (kt, n, dat, wcoord)
CCkdtree *kt;
int n;
CCdatagroup *dat;
double *wcoord;
#endif
{
    CCkdnode *p, *lastp;
    double diff;
    double ndist = BIGDOUBLE;
    int nnode;
    CCkdtree *thetree = (CCkdtree *) NULL;

    if (kt == (CCkdtree *) NULL) {
        fprintf (stderr, "ERROR: kt cannot be NULL in CCkdtree_node_nearest)\n");
        return n;
    }

    thetree = kt;

    ndist = BIGDOUBLE;
    nnode = n;

/*
    To do top down search just use:

        node_nearest_work (kt->root);
        return nnode;
*/

    p = kt->bucketptr[n];
    node_nearest_work (thetree, dat, wcoord, p, n, &ndist, &nnode);
    while (1) {
        lastp = p;
        p = p->father;
        if (p == (CCkdnode *) NULL)
            break;
        switch (p->cutdim) {
        case 0:
            diff = p->cutval - dat->x[n];
            if (lastp == p->loson) {
                if (ndist > (double) ((int) diff))
                   node_nearest_work (thetree, dat, wcoord, p->hison, n,
                                      &ndist, &nnode);
            } else {
                if (ndist > (double) ((int) (-diff)))
                   node_nearest_work (thetree, dat, wcoord, p->loson, n,
                                      &ndist, &nnode);
            }
            break;
        case 1:
            diff = p->cutval - dat->y[n];
            if (lastp == p->loson) {
                if (ndist > (double) ((int) diff))
                   node_nearest_work (thetree, dat, wcoord, p->hison, n,
                                      &ndist, &nnode);
            } else {
                if (ndist > (double) ((int) (-diff)))
                   node_nearest_work (thetree, dat, wcoord, p->loson, n,
                                      &ndist, &nnode);
            }
            break;
        case 2:
            if (lastp == p->loson) {
                if (ndist > p->cutval + wcoord[n])
                    node_nearest_work (thetree, dat, wcoord, p->hison, n,
                                      &ndist, &nnode);
            } else {
                node_nearest_work (thetree, dat, wcoord, p->loson, n,
                                   &ndist, &nnode);
            }
            break;
        }
        if (wcoord == (double *) NULL && p->bnds &&
               ball_in_bounds (dat, p->bnds, n, ndist))
            break;
    }
    return nnode;
}

#ifdef CC_PROTOTYPE_ANSI
static int ball_in_bounds (CCdatagroup *dat, CCkdbnds *bnds, int n, double dist)
#else
static int ball_in_bounds (dat, bnds, n, dist)
CCdatagroup *dat;
CCkdbnds *bnds;
int n;
double dist;
#endif
{
    if ((double) ((int) (dat->x[n] - bnds->x[0])) < dist ||
        (double) ((int) (bnds->x[1] - dat->x[n])) < dist ||
        (double) ((int) (dat->y[n] - bnds->y[0])) < dist ||
        (double) ((int) (bnds->y[1] - dat->y[n])) < dist)
        return 0;
    return 1;
}

#ifdef CC_PROTOTYPE_ANSI
static void node_nearest_work (CCkdtree *thetree, CCdatagroup *dat,
        double *datw, CCkdnode *p, int target, double *ndist, int *nnode)
#else
static void node_nearest_work (thetree, dat, datw, p, target, ndist, nnode)
CCkdtree *thetree;
CCdatagroup *dat;
double *datw;
CCkdnode *p;
int target;
double *ndist;
int *nnode;
#endif
{
    int i;
    double val, thisx, thisdist;

    if (!p->empty) {
        if (p->bucket) {
            for (i = p->lopt; i <= p->hipt; i++) {
                if (thetree->perm[i] != target) {
                    thisdist = Fedgelen (thetree->perm[i], target);
                    if (*ndist > thisdist) {
                        *ndist = thisdist;
                        *nnode = thetree->perm[i];
                    }
                }
            }
        } else {
            val = p->cutval;
            switch (p->cutdim) {
            case 0:
                thisx = dat->x[target];
                if (thisx < val) {
                    node_nearest_work (thetree, dat, datw, p->loson, target,
                                       ndist, nnode);
                    if (*ndist >  (double) ((int) (val - thisx)))
                        node_nearest_work (thetree, dat, datw, p->hison,
                                       target, ndist, nnode);
                } else {
                    node_nearest_work (thetree, dat, datw, p->hison, target,
                                       ndist, nnode);
                    if (*ndist > (double) ((int) (thisx - val)))
                        node_nearest_work (thetree, dat, datw, p->loson,
                                       target, ndist, nnode);
                }
                break;
            case 1:
                thisx = dat->y[target];
                if (thisx < val) {
                    node_nearest_work (thetree, dat, datw, p->loson, target,
                                       ndist, nnode);
                    if (*ndist >  (double) ((int) (val - thisx)))
                        node_nearest_work (thetree, dat, datw, p->hison,
                                       target, ndist, nnode);
                } else {
                    node_nearest_work (thetree, dat, datw, p->hison, target,
                                       ndist, nnode);
                    if (*ndist > (double) ((int) (thisx - val)))
                        node_nearest_work (thetree, dat, datw, p->loson,
                                       target, ndist, nnode);
                }
                break;
            case 2:
                thisx = datw[target];
                node_nearest_work (thetree, dat, datw, p->loson, target, ndist,
                                       nnode);
                if (*ndist > val + thisx)
                    node_nearest_work (thetree, dat, datw, p->hison, target,
                                       ndist, nnode);
                break;
            }
        }
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CCkdtree_fixed_radius_nearest (CCkdtree *kt, CCdatagroup *dat,
        double *datw, int n, double rad, int (*doit_fn) (int, int, void *),
        void *pass_param)
#else
int CCkdtree_fixed_radius_nearest (kt, dat, datw, n, rad, doit_fn, pass_param)
CCkdtree  *kt;
CCdatagroup *dat;
double *datw;
int n;
double rad;
int (*doit_fn)();
void *pass_param;
#endif
{
    CCkdnode *p, *lastp;
    double dist, diff, xtarget, ytarget;
    int target;

    if (kt == (CCkdtree *) NULL) {
        fprintf (stderr, "ERROR: fixed_radius_nearest needs a CCkdtree\n");
        return 0;
    }

    dist = (double) rad;
    target = n;
    xtarget = dat->x[target];
    ytarget = dat->y[target];

    p = kt->bucketptr[target];
    if (fixed_radius_nearest_work (kt, p, doit_fn, target, dist, dat, datw,
                                   xtarget, ytarget, pass_param))
        return 1;

    if (datw) {
        double wdist = dist - datw[target];
        while (1) {
            lastp = p;
            p = p->father;
            if (p == (CCkdnode *) NULL)
                return 0;
            if (p->cutdim == 0)
                diff = p->cutval - xtarget;
            else if (p->cutdim == 1)
                diff = p->cutval - ytarget;
            else
                diff = p->cutval;
            if (lastp == p->loson) {
                if (wdist > (double) ((int) diff)) {
                    if (fixed_radius_nearest_work (kt, p->hison, doit_fn,
                              target, dist, dat, datw, xtarget, ytarget,
                              pass_param))
                        return 1;
                }
            } else {
                if (wdist > (double) ((int) -diff)) {
                    if (fixed_radius_nearest_work (kt, p->loson, doit_fn,
                              target, dist, dat, datw, xtarget, ytarget,
                              pass_param))
                        return 1;
                }
            }
            if (p->bnds &&  /* ball_in_bounds */
              !((double) ((int) (xtarget - p->bnds->x[0])) < wdist ||
                (double) ((int) (p->bnds->x[1] - xtarget)) < wdist ||
                (double) ((int) (ytarget - p->bnds->y[0])) < wdist ||
                (double) ((int) (p->bnds->y[1] - ytarget)) < wdist))
                return 0;
        }
    } else {
        while (1) {
            lastp = p;
            p = p->father;
            if (p == (CCkdnode *) NULL)
                return 0;
            if (p->cutdim == 0)
                diff = p->cutval - xtarget;
            else
                diff = p->cutval - ytarget;

            if (lastp == p->loson) {
                if (dist > (double) ((int) diff)) {
                    if (fixed_radius_nearest_work (kt, p->hison, doit_fn,
                              target, dist, dat, datw, xtarget, ytarget,
                              pass_param))
                        return 1;
                }
            } else {
                if (dist > (double) ((int) -diff) || p->cutdim == 2) {
                    if (fixed_radius_nearest_work (kt, p->loson, doit_fn,
                              target, dist, dat, datw, xtarget, ytarget,
                              pass_param))
                        return 1;
                }
            }
            if (p->bnds &&  /* ball_in_bounds */
                !((double) ((int) (xtarget - p->bnds->x[0])) < dist ||
                  (double) ((int) (p->bnds->x[1] - xtarget)) < dist ||
                  (double) ((int) (ytarget - p->bnds->y[0])) < dist ||
                  (double) ((int) (p->bnds->y[1] - ytarget)) < dist))
                return 0;
        }
    }
}

#ifdef CC_PROTOTYPE_ANSI
static int fixed_radius_nearest_work (CCkdtree *thetree, CCkdnode *p,
        int (*doit_fn) (int, int, void *), int target, double dist,
        CCdatagroup *dat, double *datw,  double xtarget, double ytarget,
        void *pass_param)
#else
static int fixed_radius_nearest_work (thetree, p, doit_fn, target, dist, dat,
        datw, xtarget, ytarget, pass_param)
CCkdtree *thetree;
CCkdnode *p;
int (*doit_fn)();
int target;
double dist;
CCdatagroup *dat;
double *datw;
double xtarget, ytarget;
void *pass_param;
#endif
{
    int i, c;
    double val, thisx, thisdist;

    if (p->empty)
        return 0;

    if (p->bucket) {
        for (i = p->lopt; i <= p->hipt; i++) {
            c = thetree->perm[i];
            if (c != target) {
                thisdist = Fedgelen (c, target);
                if (thisdist < dist) {
                    if (doit_fn (target, c, pass_param)) {
                        return 1;
                    }
                }
            }
        }
        return 0;
    } else {
        if (datw) {
            double wdist = dist - datw[target];

            val = p->cutval;
            switch (p->cutdim) {
            case 0:
                thisx = xtarget;
                break;
            case 1:
                thisx = ytarget;
                break;
            case 2:
                if (fixed_radius_nearest_work (thetree, p->loson, doit_fn,
                     target, dist, dat, datw, xtarget, ytarget, pass_param)) {
                    return 1;
                }
                if (p->cutval <= wdist) {
                    if (fixed_radius_nearest_work (thetree, p->hison, doit_fn,
                         target, dist, dat, datw, xtarget, ytarget,
                         pass_param)) {
                        return 1;
                    }
                }
                return 0;
            default:
                return 0;
            }
            if (thisx < val) {
                if (fixed_radius_nearest_work (thetree, p->loson, doit_fn,
                     target, dist, dat, datw, xtarget, ytarget, pass_param)) {
                    return 1;
                }
                if (wdist > (double) ((int) (val - thisx))) {
                    if (fixed_radius_nearest_work (thetree, p->hison, doit_fn,
                       target, dist, dat, datw, xtarget, ytarget, pass_param)) {
                        return 1;
                    }
                }
            } else {
                if (fixed_radius_nearest_work (thetree, p->hison, doit_fn,
                     target, dist, dat, datw, xtarget, ytarget, pass_param)) {
                    return 1;
                }
                if (wdist > (double) ((int) (thisx - val))) {
                    if (fixed_radius_nearest_work (thetree, p->loson, doit_fn,
                       target, dist, dat, datw, xtarget, ytarget, pass_param)) {
                        return 1;
                    }
                }
            }
        } else {
            val = p->cutval;
            switch (p->cutdim) {
            case 0:
                thisx = xtarget;
                break;
            case 1:
                thisx = ytarget;
                break;
            case 2:
            default:
                fprintf (stderr, "ERROR: split on w without node weights\n");
                return 0;
            }
            if (thisx < val) {
                if (fixed_radius_nearest_work (thetree, p->loson, doit_fn,
                     target, dist, dat, datw, xtarget, ytarget, pass_param)) {
                    return 1;
                }
                if (dist > (double) ((int) (val - thisx))) {
                    if (fixed_radius_nearest_work (thetree, p->hison, doit_fn,
                       target, dist, dat, datw, xtarget, ytarget, pass_param)) {
                        return 1;
                    }
                }
            } else {
                if (fixed_radius_nearest_work (thetree, p->hison, doit_fn,
                     target, dist, dat, datw, xtarget, ytarget, pass_param)) {
                    return 1;
                }
                if (dist > (double) ((int) (thisx - val))) {
                    if (fixed_radius_nearest_work (thetree, p->loson, doit_fn,
                       target, dist, dat, datw, xtarget, ytarget, pass_param)) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCkdtree_nearest_neighbor_tour (CCkdtree *kt, int ncount, int start,
        CCdatagroup *dat, int *outcycle, double *val)
#else
int CCkdtree_nearest_neighbor_tour (kt, ncount, start, dat, outcycle, val)
CCkdtree *kt;
int ncount, start;
CCdatagroup *dat;
int *outcycle;
double *val;
#endif
{
    double len;
    int i, current, next;
    CCkdtree localkt, *mykt;
    int newtree = 0;

    if (ncount < 3) {
        fprintf (stderr, "Cannot find tour in an %d node graph\n", ncount);
        return 1;
    }

    if (kt == (CCkdtree *) NULL) {
        if (CCkdtree_build (&localkt, ncount, dat, (double *) NULL)) {
            fprintf (stderr, "Unable to build CCkdtree\n");
            return 1;
        }
        mykt = &localkt;
        newtree = 1;
    } else {
        mykt = kt;
    }

    /*
        printf ("Grow nearest neighbor tour from node %d\n", start);
        fflush (stdout);
    */

    len = 0.0;
    current = start;
    if (outcycle != (int *) NULL)
        outcycle[0] = start;
    for (i = 1; i < ncount; i++) {
        CCkdtree_delete (mykt, current);
        next = CCkdtree_node_nearest (mykt, current, dat, (double *) NULL);
        if (outcycle != (int *) NULL)
            outcycle [i] = next;
        len += (double) CCutil_dat_edgelen (current, next, dat);
        current = next;
    }
    len += (double) CCutil_dat_edgelen (current, start, dat);
    *val = len;
    if (newtree)
        CCkdtree_free (&localkt);
    else
        CCkdtree_undelete_all (kt, ncount);
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCkdtree_nearest_neighbor_2match (CCkdtree *kt, int ncount, int start,
        CCdatagroup *dat, int *outmatch, double *val)
#else
int CCkdtree_nearest_neighbor_2match (kt, ncount, start, dat, outmatch, val)
CCkdtree *kt;
int ncount, start;
CCdatagroup *dat;
int *outmatch;
double *val;
#endif
{
    double len;
    int i, j, cur, next;
    CCkdtree localkt, *mykt;
    double szeit;
    int count = 0, cyccount = 0;
    char *mark = (char *) NULL;
    int newtree = 0;
    int rval = 0;

    if (ncount < 3) {
        fprintf (stderr, "Cannot find 2-matching in an %d node graph\n",
                 ncount);
        return 1;
    }

    if (kt == (CCkdtree *) NULL) {
        if (CCkdtree_build (&localkt, ncount, dat, (double *) NULL)) {
            fprintf (stderr, "Unable to build CCkdtree\n");
            return 1;
        }
        mykt = &localkt;
        newtree = 1;
    } else {
        mykt = kt;
    }

    mark = CC_SAFE_MALLOC (ncount, char);
    if (!mark) {
        rval = 1;
        goto CLEANUP;
    }
    for (i = 0 ; i < ncount; i++)
        mark[i] = 0;

    printf ("Grow nearest neighbor 2-matching from node %d\n", start);
    fflush (stdout);
    szeit = CCutil_zeit ();
    len = 0.0;

    while (count < ncount) {
        for (j = start; j < ncount && mark[j]; j++);
        if (j == ncount) {
            for (j = 0; j < start && mark[j]; j++);
            if (j == start) {
                fprintf (stderr, "ERROR in near-2match\n");
                rval = 1;
                goto CLEANUP;
            }
        }
        start = j;
        mark[start] = 1;
        CCkdtree_delete (mykt, start);
        next = CCkdtree_node_nearest (mykt, start, dat, (double *) NULL);
        mark[next] = 1;
        len += (double) CCutil_dat_edgelen (start, next, dat);
        if (outmatch != (int *) NULL) {
            outmatch[2 * count] = start;
            outmatch[(2 * count) + 1] = next;
        }
        count++;
        CCkdtree_delete (mykt, next);
        cur = CCkdtree_node_nearest (mykt, next, dat, (double *) NULL);
        len += (double) CCutil_dat_edgelen (next, cur, dat);
        if (outmatch != (int *) NULL) {
            outmatch[2 * count] = next;
            outmatch[(2 * count) + 1] = cur;
        }
        count++;
        CCkdtree_undelete (mykt, start);
        while (cur != start && count < ncount - 3) {
            mark[cur] = 1;
            CCkdtree_delete (mykt, cur);
            next = CCkdtree_node_nearest (mykt, cur, dat, (double *) NULL);
            len += (double) (*CCutil_dat_edgelen) (cur, next, dat);
            if (outmatch != (int *) NULL) {
                outmatch[2 * count] = cur;
                outmatch[(2 * count) + 1] = next;
            }
            count++;
            cur = next;
        }
        CCkdtree_delete (mykt, start);

        if (cur != start) {   /* Not enough nodes for another circuit */
            while (count < ncount - 1) {
                mark[cur] = 1;
                CCkdtree_delete (mykt, cur);
                next = CCkdtree_node_nearest (mykt, cur, dat, (double *) NULL);
                len += (double) CCutil_dat_edgelen (cur, next, dat);
                if (outmatch != (int *) NULL) {
                    outmatch[2 * count] = cur;
                    outmatch[(2 * count) + 1] = next;
                }
                count++;
                cur = next;
            }
            len += (double) CCutil_dat_edgelen (cur, start, dat);
            if (outmatch != (int *) NULL) {
                outmatch[2 * count] = cur;
                outmatch[(2 * count) + 1] = start;
            }
            count++;
        }
        cyccount++;
    }

    *val = len;
    printf ("%d cycles in 2-matching\n", cyccount);
    printf ("Running time for Nearest Neighbor 2-match: %.2f\n",
                                                  CCutil_zeit () - szeit);
    fflush (stdout);

CLEANUP:

    if (newtree)
        CCkdtree_free (&localkt);
    else
        CCkdtree_undelete_all (kt, ncount);
    if (mark)
        CC_FREE (mark, char);
    return rval;
}
