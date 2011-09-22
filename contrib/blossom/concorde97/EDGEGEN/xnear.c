/***************************************************************************/
/*                                                                         */
/*              NEAREST NEIGHBORS FOR X-NORMS AND JUNK-NORMS               */
/*                                                                         */
/*                               TSP CODE                                  */
/*                                                                         */
/*                                                                         */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook                       */
/*  Date: March 2, 1995                                                    */
/*                                                                         */
/*                                                                         */
/* EXPORTED FUNCTIONS:                                                     */
/*   int CCedgegen_x_k_nearest (int ncount, int k, CCdatagroup *dat,       */
/*           double *wcoord, int wantlist, int *ecount, int **elist)       */
/*      RETURNS the k_nearest neighbor graph (for X-Norms)                 */
/*        -ncount is the number of nodes                                   */
/*        -k is the number of nearest neighbors wanted                     */
/*        -dat contains the info to generate edge lengths                  */
/*        -wcoord are nodeweights for Held-Karp style edge lengths, using  */
/*         len[i,j] + wcoord[i] + wcoord[j] (wcoord can be NULL)           */
/*        -wantlist should be set to 0 if you don't want the edges         */
/*        -ecount returns the number of edges if wantlist is 1             */
/*        -elist returns the edges in end1 end2 format if wantlist is 1    */
/*                                                                         */
/*   int CCedgegen_x_quadrant_k_nearest (int ncount, int k,                */
/*           CCdatagroup *dat, double *wcoord, int wantlist, int *ecount,  */
/*           int **elist)                                                  */
/*      RETURNS the quadrant k_nearest_graph (for X-Norms)                 */
/*                                                                         */
/*   int CCedgegen_x_node_k_nearest (CCxnear *xn, int n, int k,            */
/*               int ncount, int *list)                                    */
/*      RETURNS the k nearest neighbors from node n (for X-Norms           */
/*        -xn is a structure built by a call to xnear_build ()             */
/*        -list returns the neighbors of n. The calling routine should     */
/*         be sure that list points to an array of length at least num.    */
/*                                                                         */
/*   int CCedgegen_x_node_quadrant_k_nearest (CCxnear *xn, int n, int k,   */
/*           int ncount, int *list)                                        */
/*      RETURNS the quadrant k nearest to node n (for X-Norms)             */
/*        -xn is a structure built by a call to xnear_build ()             */
/*        -list returns the neighbors of n. The calling routine should     */
/*         be sure that list points to a sufficiently large array (4*num   */
/*         for D2_SIZE norms and 8*num for D3_SIZE norms)                  */
/*                                                                         */
/*   int CCedgegen_x_node_nearest (CCxnear *xn, int ncount, int ni,        */
/*           char *marks)                                                  */
/*      RETURNS the nearest unmarked node to node n (as the return value)  */
/*        -marks is an array. The entries that are nonzero correspond to   */
/*         nodes that will not be looked at in the search.                 */
/*                                                                         */
/*   int CCedgegen_x_nearest_neighbor_tour (int ncount, int start,         */
/*           CCdatagroup *dat, int *outcycle, double *val)                 */
/*      RETURNS a nearest neighbor tour, starting at node start.           */
/*        -outcycle will contain the tour if it is not NULL (the calling   */
/*         routine should be sure it points to an array of length at       */
/*         least ncount if it is not set to NULL)                          */
/*        -val will return the length of the tour.                         */
/*                                                                         */
/*   int CCedgegen_junk_k_nearest (int ncount, int k, CCdatagroup *dat,    */
/*             double *wcoord, int wantlist, int *ecount, int **elist)     */
/*      RETURNS the k-nearest graph (for JUNK-Norms)                       */
/*        -see x_k_nearest (above) for the variables                       */
/*                                                                         */
/*   int CCedgegen_junk_node_k_nearest (CCdatagroup *dat, double *wcoord,  */
/*           int n, int k, int ncount, int *list)                          */
/*      RETURNS the k nearest neighbors to node n (for JUNK-Norms)         */
/*        -list returns the neighbors of n. The calling routine should     */
/*         be sure that list points to an array of length at least num.    */
/*                                                                         */
/*   int CCedgegen_junk_node_nearest (CCdatagroup *dat, double *wcoord,    */
/*           int ncount, int n, char *marks)                               */
/*      RETURNS the nearest unmarked node to node n (as the return value)  */
/*        -marks is an array, the nodes with marks[i] nonzero are ignored. */
/*                                                                         */
/*   int CCedgegen_junk_nearest_neighbor_tour (int ncount, int start,      */
/*           CCdatagroup *dat, int *outcycle, double *val)                 */
/*      RETURNS a nearest neighbor tour starting at node start. Note that  */
/*        this will be slow for large problems (it is a quadratic routine) */
/*        -see the describtion of x_nearest_neighbor_tour above            */
/*                                                                         */
/*   int CCedgegen_xnear_build (int ncount, CCdatagroup *dat,              */
/*           double *wcoord, CCxnear *xn)                                  */
/*      RETURNS the structure needed for calls to x_node_k_nearest and     */
/*        x_quadrant_node_k_nearest (the calling routine should            */
/*        be sure that xn points to such a structure). All this            */
/*        routine does is permute the data so that the x coordinates       */
/*        are in nonincreasing order.                                      */
/*                                                                         */
/*   void CCedgegen_xnear_free (int ncount, CCxnear *xn)                   */
/*      FREES the xnear structure pointed to by xn                         */
/*                                                                         */
/*  NOTES:                                                                 */
/*       All routines other than CCedgegen_xnear_free and                  */
/*    CCedgegen_x_node_nearest return 0 on success and 1 on failure        */
/*    (normally due to running out of memory).                             */
/*       The X-Norm functions will also work for KD-Norms, but they are    */
/*    much slower than the KD-Norm functions.                              */
/*                                                                         */
/***************************************************************************/

#include "machdefs.h"
#include "util.h"
#include "edgegen.h"

#define BIGDOUBLE (1e30)
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
#define NEAR_HEAP_CUTOFF 100  /* When to switch from list to heap       */

typedef struct shortedge {
    double length;
    int end;
} shortedge;

typedef struct intptr {
    int this;
    struct intptr *next;
} intptr;

static intptr **table = (intptr **) NULL;

#ifdef CC_PROTOTYPE_ANSI

static void
    add_to_list_and_reset (int *list, int *lcount, shortedge *nearlist,
        int nearnum, int *nodenames),
    insert (int n, int m, shortedge *nearlist, CCdatagroup *dat,
        double *wcoord),
    x_quicksort (int *list, double *x, int l, int u);
static int
    run_x_k_nearest (int ncount, int num, CCdatagroup *dat, double *wcoord,
        int wantlist, int *ecount, int **elist, int doquad),
    put_in_table (int i, int j, int *added);

#else

static void
    add_to_list_and_reset (),
    insert (),
    x_quicksort ();
static int
    run_x_k_nearest (),
    put_in_table ();

#endif


CC_PTR_ALLOC_ROUTINE (intptr, intptralloc, intptrchunklist, intptrfreelist)
CC_PTR_FREE_ROUTINE (intptr, intptrfree, intptrfreelist)
CC_PTR_FREE_WORLD_ROUTINE (intptr, intptrfree_world, intptrchunklist,
        intptrfreelist)
CC_PTR_LEAKS_ROUTINE (intptr, intptr_check_leaks, intptrchunklist,
        intptrfreelist, this, int)


#ifdef CC_PROTOTYPE_ANSI
int CCedgegen_x_k_nearest (int ncount, int num, CCdatagroup *dat,
       double *wcoord, int wantlist, int *ecount, int **elist)
#else
int CCedgegen_x_k_nearest (ncount, num, dat, wcoord, wantlist, ecount, elist)
int ncount, num;
CCdatagroup *dat;
double *wcoord;
int wantlist, *ecount, **elist;
#endif
{
    return run_x_k_nearest (ncount, num, dat, wcoord, wantlist, ecount,
                            elist, 0);
}

#ifdef CC_PROTOTYPE_ANSI
int CCedgegen_x_quadrant_k_nearest (int ncount, int num, CCdatagroup *dat,
       double *wcoord, int wantlist, int *ecount, int **elist)
#else
int CCedgegen_x_quadrant_k_nearest (ncount, num, dat, wcoord, wantlist,
       ecount, elist)
int ncount, num;
CCdatagroup *dat;
double *wcoord;
int wantlist, *ecount, **elist;
#endif
{
    return run_x_k_nearest (ncount, num, dat, wcoord, wantlist, ecount,
                            elist, 1);
}

#ifdef CC_PROTOTYPE_ANSI
int CCedgegen_junk_k_nearest (int ncount, int num, CCdatagroup *dat,
       double *wcoord, int wantlist, int *ecount, int **elist)
#else
int CCedgegen_junk_k_nearest (ncount, num, dat, wcoord, wantlist, ecount, elist)
int ncount, num;
CCdatagroup *dat;
double *wcoord;
int wantlist, *ecount, **elist;
#endif
{
    return run_x_k_nearest (ncount, num, dat, wcoord, wantlist, ecount,
                            elist, 0);
}


#ifdef CC_PROTOTYPE_ANSI
static int run_x_k_nearest (int ncount, int num, CCdatagroup *dat,
       double *wcoord, int wantlist, int *ecount, int **elist, int doquad)
#else
static int run_x_k_nearest (ncount, num, dat, wcoord, wantlist, ecount, elist,
       doquad)
int ncount, num;
CCdatagroup *dat;
double *wcoord;
int wantlist, *ecount, **elist;
int doquad;
#endif
{
    int rval = 0;
    int i, n;
    intptr *ip, *ipnext;
    int total, onlist;
    int added, ntotal = 0;
    int *list = (int *) NULL;
    int goal, usex;
    CCxnear xn;

    xn.nodenames = (int *) NULL;
    xn.invnames = (int *) NULL;
    xn.w = (double *) NULL;
    xn.dat.x = (double *) NULL;
    xn.dat.y = (double *) NULL;
    xn.dat.z = (double *) NULL;
    xn.dat.adj = (int **) NULL;

    if (wantlist) {
        *ecount = 0;
        *elist = (int *) NULL;
    }

    if ((dat->norm & CC_NORM_BITS) == CC_X_NORM_TYPE ||
        (dat->norm & CC_NORM_BITS) == CC_KD_NORM_TYPE) {
        printf ("Using x-norm nearest code\n");
        usex = 1;
    } else {
        printf ("Using junk-norm nearest code\n");
        usex = 0;
    }

    if (wcoord != (double *) NULL) {
        for (i = 0; i < ncount; i++) {
            if (wcoord[i] < -0.00000001) {
                fprintf (stderr, "Cannot use xnear with negative weights\n");
                return 1;
            }
        }
    }

    if (doquad && dat->z != (double *) NULL)
        goal = 8 * num;
    else if (doquad)
        goal = 4 * num;
    else
        goal = num;

    if (usex) {
        if (CCedgegen_xnear_build (ncount, dat, wcoord, &xn)) {
            fprintf (stderr, "build_nodes failed\n");
            rval = 1;
            goto CLEANUP;
        }
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

    if (!usex && doquad) {
        printf ("NOTE: Cannot run quadrant nearest with a JUNK norm.\n");
        printf ("      Running nearest instead.\n");
        fflush (stdout);
    }

    for (n = 0; n < ncount; n++) {
        if (usex) {
            if (doquad) {
                if (CCedgegen_x_node_quadrant_k_nearest (&xn, n, num, ncount,
                                                         list)) {
                    fprintf (stderr, "x_node_quadrant_k_nearest failed\n");
                    rval = 1;
                    goto CLEANUP;
                }
            } else {
                if (CCedgegen_x_node_k_nearest (&xn, n, num, ncount, list)) {
                    fprintf (stderr, "x_node_k_nearest failed\n");
                    rval = 1;
                    goto CLEANUP;
                }
            }
        } else {
            if (CCedgegen_junk_node_k_nearest (dat, wcoord, n, num, ncount,
                                               list)) {
                fprintf (stderr, "junk_node_k_nearest_failed\n");
                rval = 1;
                goto CLEANUP;
            }
        }
        for (i = 0; i < goal; i++) {
            if (list[i] != -1) {
                if (put_in_table (n, list[i], &added))  {
                    fprintf (stderr, "put_in_table failed\n");
                    rval = 1;
                    goto CLEANUP;
                } else {
                    ntotal += added;
                }
            }
        }
        if (n % 1000 == 999) {
            printf (".");
            fflush (stdout);
        }
    }
    printf (" %d edges\n", ntotal);
    fflush (stdout);

    if (wantlist) {
        int j = 0;
        *elist = CC_SAFE_MALLOC (2 * ntotal, int);
        if (!(*elist)) {
            rval = 1;
            goto CLEANUP;
        }
        *ecount = ntotal;
        for (i = 0; i < ncount; i++) {
            for (ip = table[i]; ip; ip = ipnext) {
                ipnext =  ip->next;
                (*elist)[j++] = i;
                (*elist)[j++] = ip->this;
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
    CC_IFFREE (list, int);
    CC_IFFREE (table, intptr *);
    if (usex)
        CCedgegen_xnear_free (ncount, &xn);

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CCedgegen_x_node_quadrant_k_nearest (CCxnear *xn, int ni, int nearnum,
       int ncount, int *list)
#else
int CCedgegen_x_node_quadrant_k_nearest (xn, ni, nearnum, ncount, list)
CCxnear *xn;
int ni, nearnum, ncount;
int *list;
#endif
{
    int i, j, ntotal = 0;
    shortedge *nearlist = (shortedge *) NULL;
    double scale;
    int goal = (xn->dat.z == (double *) NULL ? 4 * nearnum : 8 * nearnum);
    int n = xn->invnames[ni];

    nearlist = CC_SAFE_MALLOC (nearnum + 1, shortedge);
    if (!nearlist)
        return 1;
    for (i = 0; i < nearnum; i++)
        nearlist[i].length = BIGDOUBLE;
    nearlist[nearnum].length = -BIGDOUBLE;

    if (xn->dat.norm == CC_GEOGRAPHIC)
        scale = CC_GEOGRAPHIC_SCALE;
    else if (xn->dat.norm == CC_ATT)
        scale = CC_ATT_SCALE;
    else
    scale = 1.0;
    if ((xn->dat.norm & CC_NORM_SIZE_BITS) == CC_D3_NORM_SIZE) {
        double ny = xn->dat.y[n];
        double nz = xn->dat.z[n];
        for (j = n - 1; j >= 0 &&
                    (double) ((int)((xn->dat.x[n] - xn->dat.x[j]) * scale))
                    < nearlist[0].length; --j)  {
            if (xn->dat.y[j] <= ny && xn->dat.z[j] <= nz)
                insert (n, j, nearlist, &(xn->dat), xn->w);
        }
        add_to_list_and_reset (list, &ntotal, nearlist, nearnum,
                               xn->nodenames);
        for (j = n - 1; j >= 0 &&
                    (double) ((int)((xn->dat.x[n] - xn->dat.x[j]) * scale))
                    < nearlist[0].length; --j)  {
            if (xn->dat.y[j] <= ny && xn->dat.z[j] >= nz)
                insert (n, j, nearlist, &(xn->dat), xn->w);
        }
        add_to_list_and_reset (list, &ntotal, nearlist, nearnum,
                               xn->nodenames);
        for (j = n - 1; j >= 0 &&
                    (double) ((int)((xn->dat.x[n] - xn->dat.x[j]) * scale))
                    < nearlist[0].length; --j)  {
            if (xn->dat.y[j] >= ny && xn->dat.z[j] <= nz)
                insert (n, j, nearlist, &(xn->dat), xn->w);
        }
        add_to_list_and_reset (list, &ntotal, nearlist, nearnum,
                               xn->nodenames);
        for (j = n - 1; j >= 0 &&
                    (double) ((int)((xn->dat.x[n] - xn->dat.x[j]) * scale))
                    < nearlist[0].length; --j)  {
            if (xn->dat.y[j] >= ny && xn->dat.z[j] >= nz)
                insert (n, j, nearlist, &(xn->dat), xn->w);
        }
        add_to_list_and_reset (list, &ntotal, nearlist, nearnum,
                               xn->nodenames);
        for (j = n + 1; j < ncount &&
                    (double) ((int)((xn->dat.x[j] - xn->dat.x[n]) * scale))
                        < nearlist[0].length; j++) {
            if (xn->dat.y[j] <= ny && xn->dat.z[j] <= nz)
                insert (n, j, nearlist, &(xn->dat), xn->w);
        }
        add_to_list_and_reset (list, &ntotal, nearlist, nearnum,
                               xn->nodenames);
        for (j = n + 1; j < ncount &&
                    (double) ((int)((xn->dat.x[j] - xn->dat.x[n]) * scale))
                    < nearlist[0].length; j++) {
            if (xn->dat.y[j] <= ny && xn->dat.z[j] >= nz)
                insert (n, j, nearlist, &(xn->dat), xn->w);
        }
        add_to_list_and_reset (list, &ntotal, nearlist, nearnum,
                               xn->nodenames);
        for (j = n + 1; j < ncount &&
                    (double) ((int)((xn->dat.x[j] - xn->dat.x[n]) * scale))
                    < nearlist[0].length; j++) {
            if (xn->dat.y[j] >= ny && xn->dat.z[j] <= nz)
                insert (n, j, nearlist, &(xn->dat), xn->w);
        }
        add_to_list_and_reset (list, &ntotal, nearlist, nearnum,
                               xn->nodenames);
        for (j = n + 1; j < ncount &&
                    (double) ((int)((xn->dat.x[j] - xn->dat.x[n]) * scale))
                    < nearlist[0].length; j++) {
            if (xn->dat.y[j] >= ny && xn->dat.z[j] >= nz)
                insert (n, j, nearlist, &(xn->dat), xn->w);
        }
        add_to_list_and_reset (list, &ntotal, nearlist, nearnum,
                               xn->nodenames);
    } else {
        double ny = xn->dat.y[n];
        for (j = n - 1; j >= 0 &&
                    (double) ((int)((xn->dat.x[n] - xn->dat.x[j]) * scale))
                    < nearlist[0].length; --j)  {
            if (xn->dat.y[j] <= ny)
                insert (n, j, nearlist, &(xn->dat), xn->w);
        }
        add_to_list_and_reset (list, &ntotal, nearlist, nearnum,
                               xn->nodenames);
            for (j = n - 1; j >= 0 &&
                    (double) ((int)((xn->dat.x[n] - xn->dat.x[j]) * scale))
                    < nearlist[0].length; --j)  {
            if (xn->dat.y[j] >= ny)
                insert (n, j, nearlist, &(xn->dat), xn->w);
        }
        add_to_list_and_reset (list, &ntotal, nearlist, nearnum,
                               xn->nodenames);
        for (j = n + 1; j < ncount &&
                    (double) ((int)((xn->dat.x[j] - xn->dat.x[n]) * scale))
                    < nearlist[0].length; j++) {
            if (xn->dat.y[j] <= ny)
                insert (n, j, nearlist, &(xn->dat), xn->w);
        }
        add_to_list_and_reset (list, &ntotal, nearlist, nearnum,
                               xn->nodenames);
        for (j = n + 1; j < ncount &&
                    (double) ((int)((xn->dat.x[j] - xn->dat.x[n]) * scale))
                    < nearlist[0].length; j++) {
            if (xn->dat.y[j] >= ny)
                insert (n, j, nearlist, &(xn->dat), xn->w);
        }
        add_to_list_and_reset (list, &ntotal, nearlist, nearnum,
                               xn->nodenames);
    }

    if (ntotal < goal) {
        for (i = ntotal; i < goal; i++)
            list[i] = -1;
    }
    CC_IFFREE (nearlist, shortedge);
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static void add_to_list_and_reset (int *list, int *lcount, shortedge *nearlist,
        int nearnum, int *nodenames)
#else
static void add_to_list_and_reset (list, lcount, nearlist, nearnum, nodenames)
int *list, *lcount;
shortedge *nearlist;
int nearnum;
int *nodenames;
#endif
{
    int i;

    for (i = 0; i < nearnum; i++) {
        if (nearlist[i].length < BIGDOUBLE) {
            list[(*lcount)++] = nodenames[nearlist[i].end];
            nearlist[i].length = BIGDOUBLE;
        }
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CCedgegen_x_node_k_nearest (CCxnear *xn, int ni, int nearnum, int ncount,
        int *list)
#else
int CCedgegen_x_node_k_nearest (xn, ni, nearnum, ncount, list)
CCxnear *xn;
int ni, nearnum, ncount;
int *list;
#endif
{
    int i, j, ntotal;
    shortedge *nearlist = (shortedge *) NULL;
    double scale;
    int n = xn->invnames[ni];

    nearlist = CC_SAFE_MALLOC (nearnum + 1, shortedge);
    if (!nearlist)
        return 1;
    for (i = 0; i < nearnum; i++)
        nearlist[i].length = BIGDOUBLE;
    nearlist[nearnum].length = -BIGDOUBLE;

    if (xn->dat.norm == CC_GEOGRAPHIC)
        scale = CC_GEOGRAPHIC_SCALE;
    else if (xn->dat.norm == CC_ATT)
        scale = CC_ATT_SCALE;
    else
        scale = 1.0;
    for (j = n - 1; j >= 0 &&
               (double) ((int)((xn->dat.x[n] - xn->dat.x[j]) * scale))
               < nearlist[0].length; --j)
        insert (n, j, nearlist, &(xn->dat), xn->w);
    for (j = n + 1; j < ncount &&
               (double) ((int)((xn->dat.x[j] - xn->dat.x[n]) * scale))
               < nearlist[0].length; j++)
        insert (n, j, nearlist, &(xn->dat), xn->w);

    ntotal = 0;
    for (i = 0; i < nearnum; i++) {
        if (nearlist[i].length < BIGDOUBLE)
            list[ntotal++] = xn->nodenames[nearlist[i].end];
    }
    if (ntotal < nearnum) {
        fprintf (stderr, "WARNING: There do not exist %d neighbors\n", nearnum);
        for (i = ntotal; i < nearnum; i++)
            list[i] = -1;
        return 1;
    }

    CC_IFFREE (nearlist, shortedge);
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCedgegen_x_node_nearest (CCxnear *xn, int ncount, int ni, char *marks)
#else
int CCedgegen_x_node_nearest (xn, ncount, ni, marks)
CCxnear *xn;
int ncount, ni;
char *marks;
#endif
{
    int n = xn->invnames[ni];
    int j, bestnode = 0;
    double scale, thisdist, bestdist = BIGDOUBLE;

    if (xn->dat.norm == CC_GEOGRAPHIC)
        scale = CC_GEOGRAPHIC_SCALE;
    else if (xn->dat.norm == CC_ATT)
        scale = CC_ATT_SCALE;
    else
        scale = 1.0;
    for (j = n - 1; j >= 0 &&
               (double) ((int)((xn->dat.x[n] - xn->dat.x[j]) * scale))
               < bestdist; --j) {
        if (!marks[xn->nodenames[j]]) {
            thisdist = CCutil_dat_edgelen (n, j, &(xn->dat));
            if (xn->w)
                thisdist += (xn->w[n] + xn->w[j]);
            if (thisdist < bestdist) {
                bestdist = thisdist;
                bestnode = j;
            }
        }
    }
    for (j = n + 1; j < ncount &&
               (double) ((int)((xn->dat.x[j] - xn->dat.x[n]) * scale))
               < bestdist; j++) {
        if (!marks[xn->nodenames[j]]) {
            thisdist = CCutil_dat_edgelen (n, j, &(xn->dat));
            if (xn->w)
                thisdist += (xn->w[n] + xn->w[j]);
            if (thisdist < bestdist) {
                bestdist = thisdist;
                bestnode = j;
            }
        }
    }
    return xn->nodenames[bestnode];
}

#ifdef CC_PROTOTYPE_ANSI
static void insert (int n, int m, shortedge *nearlist, CCdatagroup *dat,
        double *wcoord)
#else
static void insert (n, m, nearlist, dat, wcoord)
int n, m;
shortedge *nearlist;
CCdatagroup *dat;
double *wcoord;
#endif
{
    int i;
    int thisdist;

    thisdist = CCutil_dat_edgelen (n, m, dat);

    if (wcoord != (double *) NULL)
        thisdist += (wcoord[n] + wcoord[m]);

    if (thisdist < nearlist[0].length) {
        for (i = 0; nearlist[i+1].length > thisdist; i++) {
            nearlist[i].end = nearlist[i + 1].end;
            nearlist[i].length = nearlist[i + 1].length;
        }
        nearlist[i].length = thisdist;
        nearlist[i].end = m;
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CCedgegen_junk_node_k_nearest (CCdatagroup *dat, double *wcoord, int n,
        int nearnum, int ncount, int *list)
#else
int CCedgegen_junk_node_k_nearest (dat, wcoord, n, nearnum, ncount, list)
CCdatagroup *dat;
double *wcoord;
int n, nearnum, ncount;
int *list;
#endif
{
    int i, j, ntotal;
    shortedge *nearlist = (shortedge *) NULL;

    nearlist = CC_SAFE_MALLOC (nearnum + 1, shortedge);
    if (!nearlist)
        return 1;
    for (i = 0; i < nearnum; i++)
        nearlist[i].length = BIGDOUBLE;
    nearlist[nearnum].length = -BIGDOUBLE;

    for (j = n - 1; j >= 0; j--) {
        insert (n, j, nearlist, dat, wcoord);
    }
    for (j = n + 1; j < ncount; j++) {
        insert (n, j, nearlist, dat, wcoord);
    }

    ntotal = 0;
    for (i = 0; i < nearnum; i++) {
        if (nearlist[i].length < BIGDOUBLE)
            list[ntotal++] = nearlist[i].end;
    }
    if (ntotal < nearnum) {
        fprintf (stderr, "WARNING: There do not exist %d neighbors\n", nearnum);
        for (i = ntotal; i < nearnum; i++)
            list[i] = -1;
        return 1;
    }

    CC_IFFREE (nearlist, shortedge);
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCedgegen_junk_node_nearest (CCdatagroup *dat, double *wcoord, int ncount,
        int n, char *marks)
#else
int CCedgegen_junk_node_nearest (dat, wcoord, ncount, n, marks)
CCdatagroup *dat;
double *wcoord;
int ncount, n;
char *marks;
#endif
{
    int j, bestnode = 0;
    double thisdist, bestdist = BIGDOUBLE;


    if (wcoord) {
        for (j = n - 1; j >= 0; j--) {
            if (!marks[j]) {
                thisdist = CCutil_dat_edgelen (n, j, dat) +
                                       (wcoord[n] + wcoord[j]);
                if (thisdist < bestdist) {
                    bestdist = thisdist;
                    bestnode = j;
                }
            }
        }
        for (j = n + 1; j < ncount; j++) {
            if (!marks[j]) {
                thisdist = CCutil_dat_edgelen (n, j, dat) +
                                       (wcoord[n] + wcoord[j]);
                if (thisdist < bestdist) {
                    bestdist = thisdist;
                    bestnode = j;
                }
            }
        }
    } else {
        for (j = n - 1; j >= 0; j--) {
            if (!marks[j]) {
                thisdist = CCutil_dat_edgelen (n, j, dat);
                if (thisdist < bestdist) {
                    bestdist = thisdist;
                    bestnode = j;
                }
            }
        }
        for (j = n + 1; j < ncount; j++) {
            if (!marks[j]) {
                thisdist = CCutil_dat_edgelen (n, j, dat);
                if (thisdist < bestdist) {
                    bestdist = thisdist;
                    bestnode = j;
                }
            }
        }
    }

    return bestnode;
}

#ifdef CC_PROTOTYPE_ANSI
int CCedgegen_x_nearest_neighbor_tour (int ncount, int start, CCdatagroup *dat,
        int *outcycle, double *val)
#else
int CCedgegen_x_nearest_neighbor_tour (ncount, start, dat, outcycle, val)
int ncount, start;
CCdatagroup *dat;
int *outcycle;
double *val;
#endif
{
    double len;
    int i, current, next;
    CCxnear xn;
    char *marks;

    /*
        printf ("Grow nearest neighbor tour from node %d\n", start);
        fflush (stdout);
    */

    if (ncount < 3) {
        fprintf (stderr, "Cannot find tour in an %d node graph\n", ncount);
        return 1;
    }
    if ((dat->norm & CC_NORM_BITS) != CC_X_NORM_TYPE &&
        (dat->norm & CC_NORM_BITS) != CC_KD_NORM_TYPE) {
        fprintf (stderr, "Cannot run x_nearest with norm %d\n", dat->norm);
        return 1;
    }

    if (CCedgegen_xnear_build (ncount, dat, (double *) NULL, &xn)) {
        fprintf (stderr, "Unable to build xnear\n");
        return 1;
    }

    marks = CC_SAFE_MALLOC (ncount, char );
    if (!marks) {
        CCedgegen_xnear_free (ncount, &xn);
        return 1;
    }

    for (i = 0; i < ncount; i++)
        marks[i] = 0;


    len = 0.0;
    current = start;
    if (outcycle != (int *) NULL)
        outcycle[0] = start;

    for (i = 1; i < ncount; i++) {
        marks[current] = 1;
        next = CCedgegen_x_node_nearest (&xn, ncount, current, marks);
        if (outcycle != (int *) NULL)
            outcycle [i] = next;
        len += (double) CCutil_dat_edgelen (current, next, dat);
        current = next;
    }
    len += (double) CCutil_dat_edgelen (current, start, dat);
    *val = len;
    CCedgegen_xnear_free (ncount, &xn);
    CC_IFFREE (marks, char);
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCedgegen_junk_nearest_neighbor_tour (int ncount, int start,
        CCdatagroup *dat, int *outcycle, double *val)
#else
int CCedgegen_junk_nearest_neighbor_tour (ncount, start, dat, outcycle, val)
int ncount, start;
CCdatagroup *dat;
int *outcycle;
double *val;
#endif
{
    double len;
    int i, current, next;
    char *marks;

    printf ("Grow nearest neighbor tour from node %d\n", start);
    printf ("This is a JUNK norm, so expect a quadratic running time\n");
    fflush (stdout);

    if (ncount < 3) {
        fprintf (stderr, "Cannot find tour in an %d node graph\n", ncount);
        return 1;
    }

    marks = CC_SAFE_MALLOC (ncount, char );
    if (!marks) {
        return 1;
    }

    for (i = 0; i < ncount; i++)
        marks[i] = 0;

    len = 0.0;
    current = start;
    if (outcycle != (int *) NULL)
        outcycle[0] = start;

    for (i = 1; i < ncount; i++) {
        marks[current] = 1;
        next = CCedgegen_junk_node_nearest (dat, (double *) NULL, ncount,
                                            current, marks);
        if (outcycle != (int *) NULL)
            outcycle [i] = next;
        len += (double) CCutil_dat_edgelen (current, next, dat);
        current = next;
    }
    len += (double) CCutil_dat_edgelen (current, start, dat);
    *val = len;
    CC_IFFREE (marks, char);
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int put_in_table (int i, int j, int *added)
#else
static int put_in_table (i, j, added)
int i, j;
int *added;
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
int CCedgegen_xnear_build (int ncount, CCdatagroup *dat, double *wcoord,
        CCxnear *xn)
#else
int CCedgegen_xnear_build (ncount, dat, wcoord, xn)
int ncount;
CCdatagroup *dat;
double *wcoord;
CCxnear *xn;
#endif
{
    int i;

    xn->nodenames = (int *) NULL;
    xn->invnames = (int *) NULL;
    xn->w = (double *) NULL;
    xn->dat.x = (double *) NULL;
    xn->dat.y = (double *) NULL;
    xn->dat.z = (double *) NULL;
    xn->dat.adj = (int **) NULL;

    xn->dat.norm = dat->norm;

    xn->nodenames = CC_SAFE_MALLOC (ncount, int);
    if (!xn->nodenames)
        return 1;
    for (i = 0; i < ncount; i++)
        xn->nodenames[i] = i;
    xn->dat.x = CC_SAFE_MALLOC (ncount, double);
    if (!xn->dat.x) {
        CC_FREE (xn->nodenames, int);
        return 1;
    }
    for (i = 0; i < ncount; i++)
        xn->dat.x[i] = dat->x[i];

    for (i = 1; i < ncount && dat->x[i] >= dat->x[i - 1]; i++);
    if (i < ncount) {
        x_quicksort (xn->nodenames, xn->dat.x, 0, ncount - 1);
    }

    xn->invnames = CC_SAFE_MALLOC (ncount, int);
    if (!xn->invnames) {
        CC_FREE (xn->nodenames, int);
        CCutil_freedatagroup (ncount, &(xn->dat));
        return 1;
    }
    for (i = 0; i < ncount; i++)
        xn->invnames[xn->nodenames[i]] = i;

    xn->dat.y = CC_SAFE_MALLOC (ncount, double);
    if (!xn->dat.y) {
        CC_FREE (xn->nodenames, int);
        CC_FREE (xn->invnames, int);
        CCutil_freedatagroup (ncount, &(xn->dat));
        return 1;
    }
    for (i = 0; i < ncount; i++)
        xn->dat.y[i] = dat->y[xn->nodenames[i]];
    if (dat->z != (double *) NULL) {
        xn->dat.z = CC_SAFE_MALLOC (ncount, double);
        if (!xn->dat.z) {
            CC_FREE (xn->nodenames, int);
            CC_FREE (xn->invnames, int);
            CCutil_freedatagroup (ncount, &(xn->dat));
            return 1;
        }
        for (i = 0; i < ncount; i++)
            xn->dat.z[i] = dat->z[xn->nodenames[i]];
    }
    if (wcoord != (double *) NULL) {
        xn->w = CC_SAFE_MALLOC (ncount, double);
        if (!xn->w) {
            CC_FREE (xn->nodenames, int);
            CC_FREE (xn->invnames, int);
            CCutil_freedatagroup (ncount, &(xn->dat));
            return 1;
        }
        for (i = 0; i < ncount; i++)
            xn->w[i] = wcoord[xn->nodenames[i]];
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
void CCedgegen_xnear_free (int ncount, CCxnear *xn)
#else
void CCedgegen_xnear_free (ncount, xn)
int ncount;
CCxnear *xn;
#endif
{
    CC_IFFREE (xn->nodenames, int);
    CC_IFFREE (xn->invnames, int);
    CC_IFFREE (xn->w, double);
    CCutil_freedatagroup (ncount, &(xn->dat));
}

#ifdef CC_PROTOTYPE_ANSI
static void x_quicksort (int *list, double *x, int l, int u)
#else
static void x_quicksort (list, x, l, u)
int *list;
double *x;
int l, u;
#endif
{
    int i, j, itemp;
    double t, dtemp;

    if (l >= u)
        return;

    SWAP (x[l], x[(l+u)/2], dtemp);
    SWAP (list[l], list[(l+u)/2], itemp);

    i = l;
    j = u + 1;
    t = x[l];

    while (1) {
        do i++; while (i <= u && x[i] < t);
        do j--; while (x[j] > t);
        if (j < i) break;
        SWAP (x[i], x[j], dtemp);
        SWAP (list[i], list[j], itemp);
    }
    SWAP (x[l], x[j], dtemp);
    SWAP (list[l], list[j], itemp);
    x_quicksort (list, x, l, j - 1);
    x_quicksort (list, x, i, u);
}
