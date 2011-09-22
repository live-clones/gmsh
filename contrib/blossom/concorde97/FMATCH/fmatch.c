/***************************************************************************/
/*                                                                         */
/*                 MIN WEIGHT FRACTIONAL 2-MATCHINGS                       */
/*                                                                         */
/*                           TSP CODE                                      */
/*                                                                         */
/*                                                                         */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook                       */
/*  Date: February 24, 1995 - Modified 10/4/95 (Bico)                      */
/*                                                                         */
/*                                                                         */
/*  EXPORTED FUNCTIONS:                                                    */
/*    int CCfmatch_fractional_2match (int ncount, int ecount, int *elist,  */
/*           int *elen, CCdatagroup *dat, double *val, int *thematching,   */
/*           int *thedual, int *thebasis, int wantbasic)                   */
/*       int ncount (the number of nodes in the graph)                     */
/*       int ecount (the number of edges)                                  */
/*       int *elist (the edgelist in end1 end2 format)                     */
/*       int *elen (the weights on the edges)                              */
/*       CCdatagroup *dat (the info to price edges - NULL if no pricing)   */
/*       double *xcoord (the x-coordinates for geometric problems - this   */
/*                       field can be NULL)                                */
/*       double *ycoord (the y-coordinates)                                */
/*       int innorm (the NORM for pricing the complete edgeset)            */
/*       double *val (returns the optimal weight)                          */
/*       int *thematching (if non-NULL, then returns the optimal matching  */
/*                         in end1 end2 value format, where value is 1 if  */
/*                         edge gets assigned 0.5 and value is 2 if edge   */
/*                         gets 1.0 - note that the array should be        */
/*                         allocated by the calling routine, and should    */
/*                         be 6 * nnodes + 1 long - it is terminated by a  */
/*                         -1)                                             */
/*       int *thedual (if non-NULL, then returns the optimal dual solution */
/*                     with values twice their actual value (so they will  */
/*                     be integers - the array should be alloced by the    */
/*                     calling routine, and should be nnodes long)         */
/*       int *thebasis (if non-NULL, then returns the edges in the optimal */
/*                      basis in end1 end2 format)                         */
/*       int wantbasis (if nonzero, then the optimal basic solution will   */
/*                      be found)                                          */
/*                                                                         */
/*                                                                         */
/*    NOTES:                                                               */
/*       Use to find an optimal basis for the initial tsp LP. By changing  */
/*    MATCHDEGREE to 1, it should find min-wieght fractional matchings.    */
/*       The nodes should be numbered from 0 up to ncount - 1. If dat      */
/*    is specified, then the code will use a price-repair loop to solve    */
/*    the problem over the complete graph.                                 */
/*                                                                         */
/***************************************************************************/

#include "machdefs.h"
#include "util.h"
#include "fmatch.h"
#include "kdtree.h"

#define MATCHDEGREE 2    /* Only set up for 1 or 2? */
#define MAXWEIGHT 1000000000

#define ZERO ((unsigned char) 0)
#define ONE ((unsigned char) 1)
#define TWO ((unsigned char) 2)
#ifdef FALSE
#undef FALSE
#endif
#define FALSE ((unsigned char) 0)
#ifdef TRUE
#undef TRUE
#endif
#define TRUE ((unsigned char) 1)

#define OTHEREND(e,n) (e->ends[0] == n ? e->ends[1] : e->ends[0])

typedef struct edgeptr {
    struct edge *this;
    struct node *other;
    struct edgeptr *next;
} edgeptr;

typedef struct edge {
    struct edge *next;
    struct edge *pnext;
    struct node *ends[2];
    int weight;
    int z;
    unsigned char x;
    unsigned char basic;
} edge;

typedef struct shortedge {
    struct node *ends[2];
    struct shortedge *next;
} shortedge;

typedef struct node {
    struct node *next;
    struct node *pnext;
    edgeptr *adj;
    edge *parentedge;
    int name;
    int y;
    int label;
    struct {
        int order;
        struct node *next;
        struct node **prev;
    } sort;
    unsigned char flag;
    unsigned char matchcnt;
} node;

static int norm = CC_EUCLIDEAN;

static node *nodellist = (node *) NULL;
static node **nodenames = (node **) NULL;
static edge *edgellist = (edge *) NULL;
static int nnodes;
static int nedges;
static int PLUS = 1, MINUS = 2;

static CCdatagroup *gdat = (CCdatagroup *) NULL;


#ifdef CC_PROTOTYPE_ANSI

static void
    free_graph (void),
    basic_grab_basic (node *n, int parity),
    basic_mark_component_as_done (node *n),
    basic_expand (node *n, int *hit_odd_circuit),
    basic_minalpha (node *n, node **new, int *alpha, int flip_plus_and_minus),
    basic_subalpha (node *n, int alpha, int flip_plus_and_minus),
    initmat (void),
    initlist (node *head, node *tail, node *head2, node *tail2),
    expand (node *n, int *found_one),
    minalpha (node *n, node **new, int *alpha),
    subalpha (node *n, int alpha),
    augmentpath (node *n),
    augmentpath1 (node *n),
    augmentplushalf (node *n, edge *e),
    augmentminushalf (node *n, edge *e),
    flipcycle (node *n, edge *e, unsigned char v),
    augmentpair (node *n, node *n1, edge *e),
    setflag (node *n, unsigned char v),
    flipseg (node *n, node *n2),
    stringup (node *n, node *n1, node *n2, edge *e),
    y_quicksort (node **list, int *y, int l, int u),
    free_linked_world (void);

static int
    buildgraph (int ncount, int ecount, int *elist, int *elen),
    basicrun (void),
    basicscan (node *n),
    basic_check_scan (node *n),
    basicgrow (node *n),
    basic_grab_ones (node *n, int parity, edge **odd_circuit),
    basic_checkout_basic (node *n, int parity, edge **odd_circuit),
    twomatch (void),
    chkmat (double *val),
    fixmatch (int *radded),
    kd_fixmatch (int *radded),
    x_fixmatch (int *radded),
    junk_fixmatch (int *radded),
    checkoutedge (node *n1, node *n2, int *hit),
    precheckoutedge (node *n1, node *n2, shortedge **list),
    addbadedge (node *n1, node *n2, int w),
    augment (node *n);

static node
    *basic_dualchange (node *n),
    *dualchange (node *n),
    *findflag (node *n),
    *findhole (node *n, node *n2);

static edge
    *newedge (node *n1, node *n2),
    *findedge (node *n1, node *n2);


#else  /* CC_PROTOTYPE_ANSI */

static void
    free_graph (),
    basic_grab_basic (),
    basic_mark_component_as_done (),
    basic_expand (),
    basic_minalpha (),
    basic_subalpha (),
    initmat (),
    initlist (),
    expand (),
    minalpha (),
    subalpha (),
    augmentpath (),
    augmentpath1 (),
    augmentplushalf (),
    augmentminushalf (),
    flipcycle (),
    augmentpair (),
    setflag (),
    flipseg (),
    stringup (),
    y_quicksort (),
    free_linked_world ();

static int
    buildgraph (),
    basicrun (),
    basicscan (),
    basic_check_scan (),
    basicgrow (),
    basic_grab_ones (),
    basic_checkout_basic (),
    twomatch (),
    chkmat (),
    fixmatch (),
    kd_fixmatch (),
    x_fixmatch (),
    junk_fixmatch (),
    checkoutedge (),
    precheckoutedge (),
    addbadedge (),
    augment ();

static node
    *basic_dualchange (),
    *dualchange (),
    *findflag (),
    *findhole ();

static edge
    *newedge (),
    *findedge ();


#endif /* CC_PROTOTYPE_ANSI */


/********** Allocation routines **********/


CC_PTR_ALLOC_ROUTINE (node, nodealloc, node_bigchunklist, node_freelist)
CC_PTR_FREE_ROUTINE (node, nodefree, node_freelist)
CC_PTR_FREE_WORLD_ROUTINE (node, nodefree_world, node_bigchunklist,
        node_freelist)
CC_PTR_LEAKS_ROUTINE (node, node_check_leaks, node_bigchunklist, node_freelist,
        flag, unsigned char)

CC_PTR_ALLOC_ROUTINE (edge, edgealloc, edge_bigchunklist, edge_freelist)
CC_PTR_FREE_ROUTINE (edge, edgefree, edge_freelist)
CC_PTR_FREE_WORLD_ROUTINE (edge, edgefree_world, edge_bigchunklist,
        edge_freelist)
CC_PTR_LEAKS_ROUTINE (edge, edge_check_leaks, edge_bigchunklist, edge_freelist,
        basic, unsigned char)

CC_PTR_ALLOC_ROUTINE (edgeptr, edgeptralloc, edgeptr_bigchunklist,
        edgeptr_freelist)
CC_PTR_FREE_ROUTINE (edgeptr, edgeptrfree, edgeptr_freelist)
CC_PTR_FREE_LIST_ROUTINE (edgeptr, edgeptrfree_list, edgeptrfree)
CC_PTR_FREE_WORLD_ROUTINE (edgeptr, edgeptrfree_world, edgeptr_bigchunklist,
        edgeptr_freelist)
CC_PTR_LEAKS_ROUTINE (edgeptr, edgeptr_check_leaks, edgeptr_bigchunklist,
        edgeptr_freelist, this, edge *)

CC_PTR_ALLOC_ROUTINE (shortedge, shortedgealloc, shortedge_bigchunklist,
        shortedge_freelist)
CC_PTR_FREE_ROUTINE (shortedge, shortedgefree, shortedge_freelist)
CC_PTR_FREE_WORLD_ROUTINE (shortedge, shortedgefree_world,
        shortedge_bigchunklist, shortedge_freelist)
CC_PTR_LEAKS_ROUTINE (shortedge, shortedge_check_leaks, shortedge_bigchunklist,
        shortedge_freelist, ends[0], node *)


#ifdef CC_PROTOTYPE_ANSI
static void free_linked_world (void)
#else
static void free_linked_world ()
#endif
{
    nodefree_world ();
    edgefree_world ();
    edgeptrfree_world ();
    shortedgefree_world ();
}


/********** main routines **********/


#ifdef CC_PROTOTYPE_ANSI
static int buildgraph (int ncount, int ecount, int *elist, int *elen)
#else
static int buildgraph (ncount, ecount, elist, elen)
int ncount, ecount, *elist, *elen;
#endif
{
    int i;
    node *n;
    edge *e;

    nnodes = ncount;
    nedges = 0;

    nodenames = CC_SAFE_MALLOC(nnodes, node *);
    if (!nodenames)
        return 1;

    for (i = 0; i < nnodes; i++) {
        n = nodealloc ();
        if (!n)
            return 1;
        n->name = i;
        n->adj = (edgeptr *) NULL;
        n->next = nodellist;
        nodellist = n;
        nodenames[i] = n;
    }
    for (i = 0; i < ecount; i++) {
        e = newedge (nodenames[elist[2 * i]], nodenames[elist[(2 * i) + 1]]);
        if (!e)
            return 1;
        e->weight = elen[i] + elen[i];
    }

    if (nedges != ecount) {
        fprintf (stderr, "Should have %d edges, not %d\n", ecount, nedges);
        free_graph ();
        return 1;
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static void free_graph (void)
#else
static void free_graph ()
#endif
{
    node *n, *nnext;
    edge *e, *enext;

    for (n = nodellist; n; n = nnext) {
        nnext = n->next;
        edgeptrfree_list (n->adj);
        nodefree (n);
    }
    nodellist = (node *) NULL;
    for (e = edgellist; e; e = enext) {
        enext = e->next;
        edgefree (e);
    }
    edgellist = (edge *) NULL;
    CC_IFFREE (nodenames, node *);
}


#ifdef CC_PROTOTYPE_ANSI
static edge *newedge (node *n1, node *n2)
#else
static edge *newedge (n1, n2)
node *n1, *n2;
#endif
{
    edge *e;
    edgeptr *ep;

    e = edgealloc ();
    if (!e)
        return (edge *) NULL;
    e->ends[0] = n1;
    e->ends[1] = n2;
    e->next = edgellist;
    edgellist = e;
    nedges++;

    ep = edgeptralloc ();
    if (!ep) {
        edgefree (e);
        return (edge *) NULL;
    }
    ep->this = e;
    ep->other = n2;
    ep->next = n1->adj;
    n1->adj = ep;

    ep = edgeptralloc ();
    if (!ep) {
        edgefree (e);
        return (edge *) NULL;
    }
    ep->this = e;
    ep->other = n1;
    ep->next = n2->adj;
    n2->adj = ep;

    return e;
}

#ifdef CC_PROTOTYPE_ANSI
int CCfmatch_fractional_2match (int ncount, int ecount, int *elist, int *elen,
        CCdatagroup *dat, double *val, int *thematching, int *thedual,
        int *thebasis, int wantbasic)
#else
int CCfmatch_fractional_2match (ncount, ecount, elist, elen, dat, val,
        thematching, thedual, thebasis, wantbasic)
int ncount, ecount;
int *elist, *elen;
CCdatagroup *dat;
double *val;
int *thematching, *thedual, *thebasis;
int wantbasic;
#endif
{
    int ntotal, nreserve;
    double v, vbasic, szeit, tzeit;
    int added;
    int rval = 0;

    tzeit = CCutil_zeit ();

    if (dat)
        norm = dat->norm;
    else
        norm = 2;
    gdat = dat;
    if (buildgraph (ncount, ecount, elist, elen)) {
        rval = 1;
        goto CLEANUP;
    }

    initmat ();
    if (twomatch ()) {
        rval = 1;
        goto CLEANUP;
    }
    if (chkmat (&v)) {
        fprintf (stderr, "Chkmat found error in matching\n");
        rval = 1;
        goto CLEANUP;
    }
    printf ("Fractional Matching: %.1f\n", v);
    printf ("Initial Running Time: %.2f (seconds)\n", CCutil_zeit () - tzeit);
    fflush (stdout);

    if (wantbasic) {
        szeit = CCutil_zeit ();
        if (basicrun ()) {
            fprintf (stderr, "Did not find a basic optimal solution\n");
            rval = 1;
            goto CLEANUP;
        }
        if (chkmat (&vbasic)) {
            fprintf (stderr, "Chkmat found error in matching\n");
            rval = 1;
            goto CLEANUP;
        }
        if (vbasic != v) {
            fprintf (stderr, "ERROR: Basis routine altered objective\n");
            rval = 1;
            goto CLEANUP;
        }
        printf ("Basis Running Time: %.2f (seconds)\n", CCutil_zeit () - szeit);
        fflush (stdout);
    }

    if (dat != (CCdatagroup *) NULL) {
        printf ("Price-Repair ...\n");
        fflush (stdout);
        szeit = CCutil_zeit ();
        if (fixmatch(&added)) {
            fprintf (stderr, "fixmatch failed\n");
            rval = 1;
            goto CLEANUP;
        }
        if (chkmat (&v)) {
            fprintf (stderr, "Chkmat found error in matching\n");
            rval = 1;
            goto CLEANUP;
        }
        if (wantbasic) {
            do  {
                printf ("Find basis ...\n");
                fflush (stdout);
                if (basicrun ()) {
                    fprintf (stderr, "Did not find a basic solution\n");
                    rval = 1;
                    goto CLEANUP;
                }
                if (chkmat (&vbasic)) {
                    fprintf (stderr, "Chkmat found error in matching\n");
                    rval = 1;
                    goto CLEANUP;
                }
                if (vbasic != v) {
                    fprintf (stderr, "ERROR: Basis routine altered obj\n");
                    rval = 1;
                    goto CLEANUP;
                }

                printf ("Price-repair basic solution ...\n");
                fflush (stdout);
                if (fixmatch(&added)) {
                    fprintf (stderr, "fixmatch failed\n");
                    rval = 1;
                    goto CLEANUP;
                }
                if (chkmat (&v)) {
                    fprintf (stderr, "Chkmat found error in matching\n");
                    rval = 1;
                    goto CLEANUP;
                }
            } while (added);
        }
        printf ("Running Time for Price-Repair: %.2f\n",
                                         CCutil_zeit () - szeit);
        printf ("Fractional Matching on Complete Graph: %.1f\n",v);
        fflush (stdout);
    }

    *val = v;

    if (thematching != (int *) NULL) {
        int k = 0;
        edge *e;
        for (e = edgellist; e; e = e->next) {
            if (e->x != ZERO) {
                thematching[k++] = e->ends[0]->name;
                thematching[k++] = e->ends[1]->name;
                thematching[k++] = (e->x == ONE ? 1 : 2);
            }
        }
        thematching[k] = -1;
    }
    if (thedual != (int *) NULL) {
        int i;
        for (i = 0; i < nnodes; i++)
            thedual[i] = nodenames[i]->y;
    }
    if (wantbasic && thebasis != (int *) NULL) {
        int k = 0;
        edge *e;
        for (e = edgellist; e; e = e->next) {
            if (e->basic) {
                thebasis[k++] = e->ends[0]->name;
                thebasis[k++] = e->ends[1]->name;
            }
        }
    }

CLEANUP:

    free_graph ();
    if (node_check_leaks (&ntotal, &nreserve)) {
        printf ("Outstanding nodes %d (total %d)\n",
                 ntotal - nreserve, ntotal);
    }
    if (edge_check_leaks (&ntotal, &nreserve)) {
        printf ("Outstanding edges %d (total %d)\n",
                 ntotal - nreserve, ntotal);
    }
    if (edgeptr_check_leaks (&ntotal, &nreserve)) {
        printf ("Outstanding edgeptrs %d (total %d)\n",
                 ntotal - nreserve, ntotal);
    }
    if (shortedge_check_leaks (&ntotal, &nreserve)) {
        printf ("Outstanding shortedges %d (total %d)\n",
                 ntotal - nreserve, ntotal);
    }
    free_linked_world ();

    printf ("Total fractional matching time: %.2f (seconds)\n",
             CCutil_zeit () - tzeit);
    fflush (stdout);

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static void initmat (void)
#else
static void initmat ()
#endif
{
    node *n;
    edge *e;

    for (n = nodellist; n; n = n->next) {
        n->y = 0;
        n->matchcnt = 2 - MATCHDEGREE;
        n->parentedge = (edge *) NULL;
        n->label = 0;
    }
    for (e = edgellist; e; e = e->next) {
        e->z = 0;
        e->x = ZERO;
        e->pnext = (edge *) NULL;
    }
    PLUS = 1;
    MINUS = 2;
}

#ifdef CC_PROTOTYPE_ANSI
static int chkmat (double *val)   /* val may be 1/2 integer and big */
#else
static int chkmat (val)
double *val;
#endif
{
    int k;
    double v = 0.0, dualval = 0.0;
    node *n;
    edge *e;
    edgeptr *ep;

    for (n = nodellist; n; n = n->next) {
        k = 0;
        for (ep = n->adj; ep; ep = ep->next)
            k += ep->this->x;
        if (k != 2 * MATCHDEGREE) {
            fprintf (stderr, "Not a matching, node %d has 2-degree %d\n",
                                                               n->name, k);
            return 1;
        }
        dualval += (double) n->y;
    }
    dualval *= (double) MATCHDEGREE;
    for (e = edgellist; e; e = e->next) {
        switch (e->x) {
        case TWO:
            if (e->z < 0 ||
                    e->z != e->ends[0]->y + e->ends[1]->y - e->weight) {
                fprintf (stderr, "Error in dual solution - 2\n");
                return 1;
            }
            v += (double) e->weight;
            v += (double) e->weight;
            dualval -= (double) e->z;
            break;
        case ONE:
            if (e->z != 0 ||
                    e->ends[0]->y + e->ends[1]->y != e->weight) {
                fprintf (stderr, "Error in dual solution - 1\n");
                return 1;
            }
            v += (double) e->weight;
            break;
        case ZERO:
            if (e->z != 0 || e->ends[0]->y + e->ends[1]->y > e->weight) {
                fprintf (stderr, "Error in dual solution - 0\n");
                return 1;
            }
            break;
        default:
            fprintf (stderr, "Error in matching values\n");
            return 1;
        }
    }
    v /= 4.0;
    dualval /= 2.0;

    if (v != dualval) {
        fprintf (stderr, "The primal and dual objective values differ.\n");
        return 1;
    }
    *val = v;
    return 0;
}


/**********  Core fractional matching routines **********/


#ifdef CC_PROTOTYPE_ANSI
static int twomatch (void)
#else
static int twomatch ()
#endif
{
    node *n;

    for (n = nodellist; n; n = n->next) {
        while (n->matchcnt != TWO) {
            if (augment (n)) {
                fprintf (stderr, "augment failed - probably no fmatching\n");
                return 1;
            }
        }
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int augment (node *n)
#else
static int augment (n)
node *n;
#endif
{
    node *auglist;
    int found_augmenting_path = 0;

    PLUS += 2;
    MINUS += 2;
    n->label = PLUS;
    n->parentedge = (edge *) NULL;
    n->matchcnt++;
    expand (n, &found_augmenting_path);
    if (found_augmenting_path)
        return 0;
    while ((auglist = dualchange (n)) != (node *) NULL) {
        while (auglist) {
            expand (auglist, &found_augmenting_path);
            if (found_augmenting_path)
                return 0;
            auglist = auglist->pnext;
        }
    }
    fprintf (stderr, "Error - dual change did not create new edges\n");
    return 1;
}

#ifdef CC_PROTOTYPE_ANSI
static void expand (node *n, int *found_one)
#else
static void expand (n, found_one)
node *n;
int *found_one;
#endif
{
    node *n1;
    edgeptr *ep;
    edge *e;

    if (n->label == PLUS) {
        for (ep = n->adj; ep; ep = ep->next) {
            if (ep->this->x == ONE) {
                augmentplushalf (n, ep->this);
                *found_one = 1;
                return;
            }
        }
        for (ep = n->adj; ep; ep = ep->next) {
            if (ep->this->x == ZERO &&
                        ep->other->y + n->y == ep->this->weight) {
                e = ep->this;
                n1 = ep->other;
                if (n1->label < PLUS) {         /* n1 has no label */
                    n1->label = MINUS;
                    n1->parentedge = e;
                    if (n1->matchcnt != TWO) {
                        augmentpath (n1);
                        *found_one = 1;
                        return;
                    }
                    expand (n1, found_one);
                    if (*found_one)
                        return;
                } else if (n1->label == PLUS) {
                    augmentpair (n, n1, e);
                    *found_one = 1;
                    return;
                }
            }
        }
    } else {                    /* MINUS */
        for (ep = n->adj; ep; ep = ep->next) {
            if (ep->this->x == ONE) {
                augmentminushalf (n, ep->this);
                *found_one = 1;
                return;
            }
        }
        for (ep = n->adj; ep; ep = ep->next) {
            if (ep->this->x == TWO && ep->this->z == 0) {
                e = ep->this;
                n1 = ep->other;
                if (n1->label < PLUS) {         /* n1 has no label */
                    n1->label = PLUS;
                    n1->parentedge = e;
                    expand (n1, found_one);
                    if (*found_one)
                        return;
                } else if (n1->label == MINUS) {
                    augmentpair (n, n1, e);
                    *found_one = 1;
                    return;
                }
            }
        }
    }
    return;
}

#ifdef CC_PROTOTYPE_ANSI
static node *dualchange (node *n)
#else
static node *dualchange (n)
node *n;
#endif
{
    node *new = (node *) NULL;
    int alpha = MAXWEIGHT;

    minalpha (n, &new, &alpha);
    if (alpha == MAXWEIGHT) {
        fprintf (stderr, "Dual change required, but no candidate edges\n");
        return (node *) NULL;
    }
    if (alpha & 0x1) {
        fprintf (stderr, "Whoops, 2 * alpha = %d, not even\n", alpha);
        return (node *) NULL;
    }
    alpha /= 2;
    subalpha (n, alpha);
    return new;
}

#ifdef CC_PROTOTYPE_ANSI
static void minalpha (node *n, node **new, int *alpha)
#else
static void minalpha (n, new, alpha)
node *n;
node **new;
int *alpha;
#endif
{
    int minv = MAXWEIGHT;
    int thisv;
    node *n1;
    edgeptr *ep;
    edge *e;

    if (n->label == PLUS) {
        for (ep = n->adj; ep; ep = ep->next) {
            e = ep->this;
            if (e->x == ZERO) {
                n1 = ep->other;
                if (n1->label < PLUS) {         /* n1 is unlabeled */
                    thisv = e->weight - n->y - n1->y;
                    thisv += thisv;
                    if (thisv < minv)
                        minv = thisv;
                } else if (n1->label == PLUS) {
                    thisv = e->weight - n->y - n1->y;
                    if (thisv < minv)
                        minv = thisv;
                } else {        /* n1 has a minus label */
                    if (n1->parentedge == e)
                        minalpha (n1, new, alpha);
                }
            }
        }
    } else {                    /* MINUS case */
        for (ep = n->adj; ep; ep = ep->next) {
            e = ep->this;
            if (e->x == TWO) {
                n1 = ep->other;
                if (n1->label < PLUS) {
                    thisv = e->z + e->z;
                    if (thisv < minv)
                        minv = thisv;
                } else if (n1->label == PLUS) {
                    if (n1->parentedge == e)
                        minalpha (n1, new, alpha);
                } else {        /* n1 has a MINUS label */
                    thisv = e->z;
                    if (thisv < minv)
                        minv = thisv;
                }
            }
        }
    }
    if (minv < *alpha) {
        *new = n;
        n->pnext = (node *) NULL;
        *alpha = minv;
    } else if (minv == *alpha) {
        n->pnext = *new;
        *new = n;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void subalpha (node *n, int alpha)
#else
static void subalpha (n, alpha)
node *n;
int alpha;
#endif
{
    edgeptr *ep;
    edge *e;
    node *n1;

    if (n->label == PLUS) {
        n->y += alpha;
        for (ep = n->adj; ep; ep = ep->next) {
            e = ep->this;
            if (e->x == TWO)
                e->z += alpha;
            else if (e->x == ZERO) {
                n1 = ep->other;
                if (n1->parentedge == e && n1->label >= PLUS)
                    subalpha (n1, alpha);
            }
        }
    } else {                    /* MINUS */
        n->y -= alpha;
        for (ep = n->adj; ep; ep = ep->next) {
            e = ep->this;
            if (e->x == TWO) {
                e->z -= alpha;
                n1 = ep->other;
                if (n1->parentedge == e && n1->label >= PLUS)
                    subalpha (n1, alpha);
            }
        }
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void augmentpath (node *n)
#else
static void augmentpath (n)
node *n;
#endif
{
    n->matchcnt++;
    augmentpath1 (n);
}

#ifdef CC_PROTOTYPE_ANSI
static void augmentpath1 (node *n)
#else
static void augmentpath1 (n)
node *n;
#endif
{
    while (n->parentedge != (edge *) NULL) {
        n->parentedge->x = TWO - n->parentedge->x;
        n = OTHEREND(n->parentedge, n);
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void augmentplushalf (node *n, edge *e)
#else
static void augmentplushalf (n, e)
node *n;
edge *e;
#endif
{
    flipcycle (n, e, TWO);
    augmentpath1 (n);
}

#ifdef CC_PROTOTYPE_ANSI
static void augmentminushalf (node *n, edge *e)
#else
static void augmentminushalf (n, e)
node *n;
edge *e;
#endif
{
    flipcycle (n, e, ZERO);
    augmentpath1 (n);
}

#ifdef CC_PROTOTYPE_ANSI
static void flipcycle (node *n, edge *e, unsigned char v)
#else
static void flipcycle (n, e, v)
node *n;
edge *e;
unsigned char v;
#endif
{
    edge *e1;
    edge *e2;

    e1 = e->pnext;
    if (e1->ends[0] == n || e1->ends[1] == n)
        e = e1;
    e1 = e;
    do {
        e1->x = v;
        v = TWO - v;
        e2 = e1->pnext;
        e1->pnext = (edge *) NULL;
        e1 = e2;
    } while (e1 != e);
}

#ifdef CC_PROTOTYPE_ANSI
static void augmentpair (node *n, node *n1, edge *e)
#else
static void augmentpair (n, n1, e)
node *n;
node *n1;
edge *e;
#endif
{
    node *n2, *n3;

    setflag (n, FALSE);
    setflag (n1, TRUE);
    n2 = findflag (n);
    if ((n3 = findhole (n, n2)) != (node *) NULL) {
        n3->matchcnt++;
        flipseg (n, n3);
        e->x = TWO - e->x;
        augmentpath1 (n1);
        return;
    }
    if ((n3 = findhole (n1, n2)) != (node *) NULL) {
        n3->matchcnt++;
        flipseg (n1, n3);
        e->x = TWO - e->x;
        augmentpath1 (n);
        return;
    }
    stringup (n, n1, n2, e);
    augmentpath1 (n2);
}

#ifdef CC_PROTOTYPE_ANSI
static void setflag (node *n, unsigned char v)
#else
static void setflag (n, v)
node *n;
unsigned char v;
#endif
{
    n->flag = v;
    while (n->parentedge != (edge *) NULL) {
        n = OTHEREND(n->parentedge, n);
        n->flag = v;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static node *findflag (node *n)
#else
static node *findflag (n)
node *n;
#endif
{
    while (!n->flag) {
        n = OTHEREND(n->parentedge, n);
    }
    return n;
}

#ifdef CC_PROTOTYPE_ANSI
static node *findhole (node *n, node *n2)
#else
static node *findhole (n, n2)
node *n;
node *n2;
#endif
{
    while (n != n2) {
        if (n->matchcnt != TWO)
            return n;
        n = OTHEREND(n->parentedge, n);
    }
    return n2->matchcnt != TWO ? n2 : (node *) NULL;
}

#ifdef CC_PROTOTYPE_ANSI
static void flipseg (node *n, node *n2)
#else
static void flipseg (n, n2)
node *n;
node *n2;
#endif
{
    while (n != n2) {
        n->parentedge->x = TWO - n->parentedge->x;
        n = OTHEREND(n->parentedge, n);
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void stringup (node *n, node *n1, node *n2, edge *e)
#else
static void stringup (n, n1, n2, e)
node *n;
node *n1;
node *n2;
edge *e;
#endif
{
    edge *preve, *savee;

    preve = e;
    while (n != n2) {
        n->parentedge->x = ONE;
        preve->pnext = n->parentedge;
        preve = n->parentedge;
        n = OTHEREND(n->parentedge, n);
    }
    savee = preve;
    preve = e;
    while (n1 != n2) {
        n1->parentedge->x = ONE;
        n1->parentedge->pnext = preve;
        preve = n1->parentedge;
        n1 = OTHEREND(n1->parentedge, n1);
    }
    savee->pnext = preve;
    e->x = ONE;
}

#ifdef CC_PROTOTYPE_ANSI
static edge *findedge (node *n1, node *n2)
#else
static edge *findedge (n1, n2)
node *n1;
node *n2;
#endif
{
    edgeptr *ep;

    for (ep = n1->adj; ep; ep = ep->next) {
        if (ep->other == n2)
            return ep->this;
    }
    return  (edge *) NULL;
}


/********** Basis finding routines **********/


#ifdef CC_PROTOTYPE_ANSI
static int basicrun (void)
#else
static int basicrun ()
#endif
{
    node *n;
    edge *e;

    PLUS = 1;
    MINUS = 2;

    for (n = nodellist; n; n = n->next) {
        n->label = 0;
        n->flag = 0;
    }
    for (e = edgellist; e; e = e->next)
        e->basic = 0;

    for (n = nodellist; n; n = n->next) {
        if (n->label == 0) {
            if (basicscan (n))
                return 1;
        }
    }
    for (n = nodellist; n; n = n->next) {
        if (n->flag == 0) {
            if (basicgrow (n))
                return 1;
        }
    }

    for (n = nodellist; n; n = n->next)
        n->label = 0;
    for (n = nodellist; n; n = n->next) {
        if (n->label == 0) {
            if (basic_check_scan (n))
                return 1;
        }
    }

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int basicscan (node *n)
#else
static int basicscan (n)
node *n;
#endif
{
    edge *odd_circuit = (edge *) NULL;

    PLUS += 2;
    MINUS += 2;
    n->parentedge = (edge *) NULL;
    if (basic_grab_ones (n, 0, &odd_circuit))
        return 1;
    if (odd_circuit != (edge *) NULL) {
        basic_mark_component_as_done (n);
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int basic_check_scan (node *n)
#else
static int basic_check_scan (n)
node *n;
#endif
{
    edge *odd_circuit = (edge *) NULL;

    PLUS += 2;
    MINUS += 2;
    n->parentedge = (edge *) NULL;
    if (basic_checkout_basic (n, 0, &odd_circuit))
        return 1;
    if (odd_circuit == (edge *) NULL) {
        printf ("No odd circuit\n");
        return 1;
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int basicgrow (node *n)
#else
static int basicgrow (n)
node *n;
#endif
{
    int hit_odd_circuit = 0;
    node *expandlist;

    PLUS += 2;
    MINUS += 2;
    basic_grab_basic (n, 0);

    n->parentedge = (edge *) NULL;
    basic_expand (n, &hit_odd_circuit);
    if (hit_odd_circuit)
        return 0;
    else {
        while ((expandlist = basic_dualchange (n)) != (node *) NULL) {
            while (expandlist) {
                basic_expand (expandlist, &hit_odd_circuit);
                if (hit_odd_circuit)
                    return 0;
                expandlist = expandlist->pnext;
            }
        }
        fprintf (stderr, "ERROR: No dual change in basis finding code\n");
        return 1;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static int basic_grab_ones (node *n, int parity, edge **odd_circuit)
#else
static int basic_grab_ones (n, parity, odd_circuit)
node *n;
int parity;
edge **odd_circuit;
#endif
{
    edge *e;
    edgeptr *ep;
    node *n1;

    n->label = (parity == 0 ? PLUS : MINUS);
    for (ep = n->adj; ep; ep = ep->next) {
        e = ep->this;
        if (e->x == ONE && e != n->parentedge) {
            n1 = ep->other;
            if (n1->label == 0) {
                n1->parentedge = e;
                e->basic = 1;
                if (basic_grab_ones (n1, 1 - parity, odd_circuit))
                    return 1;
            } else if (n1->label == n->label) {
                if (*odd_circuit == (edge *) NULL) {
                    *odd_circuit = e;
                    e->basic = 1;
                } else if (*odd_circuit != e) {
                    fprintf (stderr, "ERROR: Two odd circuits in 1-graph\n");
                    printf ("Circuit forming edges: %d-%d  %d-%d\n",
                         (*odd_circuit)->ends[0]->name,
                         (*odd_circuit)->ends[1]->name,
                         e->ends[0]->name,
                         e->ends[1]->name);
                    return 1;
                }
            } else {
                fprintf (stderr, "ERROR: Even circuit in 1-graph\n");
                printf ("Circuit forming edge: %d-%d\n",
                              e->ends[0]->name,
                              e->ends[1]->name);
                return 1;
            }
        }
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int basic_checkout_basic (node *n, int parity, edge **odd_circuit)
#else
static int basic_checkout_basic (n, parity, odd_circuit)
node *n;
int parity;
edge **odd_circuit;
#endif
{
    edge *e;
    edgeptr *ep;
    node *n1;

    n->label = (parity == 0 ? PLUS : MINUS);
    for (ep = n->adj; ep; ep = ep->next) {
        e = ep->this;
        if (e->basic && e != n->parentedge) {
            n1 = ep->other;
            if (n1->label == 0) {
                n1->parentedge = e;
                if (basic_checkout_basic (n1, 1 - parity, odd_circuit))
                    return 1;
            } else if (n1->label == n->label) {
                if (*odd_circuit == (edge *) NULL) {
                    *odd_circuit = e;
                } else if (*odd_circuit != e) {
                    fprintf (stderr, "ERROR: Two odd circuits in basish\n");
                    printf ("Circuit forming edges: %d-%d  %d-%d\n",
                         (*odd_circuit)->ends[0]->name,
                         (*odd_circuit)->ends[1]->name,
                         e->ends[0]->name,
                         e->ends[1]->name);
                    return 1;
                }
            } else {
                fprintf (stderr, "ERROR: Even circuit in basis\n");
                printf ("Circuit forming edge: %d-%d\n",
                              e->ends[0]->name,
                              e->ends[1]->name);
                return 1;
            }
        }
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static void basic_grab_basic (node *n, int parity)
#else
static void basic_grab_basic (n, parity)
node *n;
int parity;
#endif
{
    edgeptr *ep;

    n->label = (parity == 0 ? PLUS : MINUS);
    n->flag = 1;
    for (ep = n->adj; ep; ep = ep->next) {
        if (ep->this->basic) {
            if (!ep->other->flag)
                basic_grab_basic (ep->other, 1 - parity);
        }
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void basic_mark_component_as_done (node *n)
#else
static void basic_mark_component_as_done (n)
node *n;
#endif
{
    edgeptr *ep;

    n->flag = 1;
    for (ep = n->adj; ep; ep = ep->next) {
        if (ep->this->basic) {
            if (!ep->other->flag)
                basic_mark_component_as_done (ep->other);
        }
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void basic_expand (node *n, int *hit_odd_circuit)
#else
static void basic_expand (n, hit_odd_circuit)
node *n;
int *hit_odd_circuit;
#endif
{
    edge *e;
    edgeptr *ep;
    node *n1;

    for (ep = n->adj; ep; ep = ep->next) {
        e = ep->this;
        if (e != n->parentedge) {
            n1 = ep->other;
            if (e->basic) {
                n1->parentedge = e;
                basic_expand (n1, hit_odd_circuit);
                if (*hit_odd_circuit)
                    return;
            } else if (n->y + n1->y == e->weight) {
                if (n1->label < PLUS) {
                    e->basic = 1;
                    if (n1->flag) {
                        *hit_odd_circuit = 1;
                        return;
                    } else {
                        n1->parentedge = e;
                        if (n->label == PLUS)
                            basic_grab_basic (n1, 1);
                        else
                            basic_grab_basic (n1, 0);
                        basic_expand (n1, hit_odd_circuit);
                        if (*hit_odd_circuit)
                            return;
                    }
                } else if (n1->label == n->label) {
                    e->basic = 1;
                    *hit_odd_circuit = 1;
                    return;
                }
            }
        }
    }
}

#ifdef CC_PROTOTYPE_ANSI
static node *basic_dualchange (node *n)
#else
static node *basic_dualchange (n)
node *n;
#endif
{
    node *new = (node *) NULL;
    int alpha = MAXWEIGHT;

    basic_minalpha (n, &new, &alpha, 0);
    if (alpha != MAXWEIGHT) {
        alpha /= 2;
        basic_subalpha (n, alpha, 0);
    } else {
        /* reverse sense of PLUS and MINUS */
        basic_minalpha (n, &new, &alpha, 1);
        if (alpha == MAXWEIGHT) {
            printf ("Basic dual change required, but no candidate edges\n");
            return (node *) NULL;
        }
        alpha /= 2;
        basic_subalpha (n, alpha, 1);
    }
    return new;
}

#ifdef CC_PROTOTYPE_ANSI
static void basic_minalpha (node *n, node **new, int *alpha,
                           int flip_plus_and_minus)
#else
static void basic_minalpha (n, new, alpha, flip_plus_and_minus)
node *n;
node **new;
int *alpha;
int flip_plus_and_minus;
#endif
{
    int minv = MAXWEIGHT;
    int thisv;
    node *n1;
    edge *e;
    edgeptr *ep;

    if ((n->label == PLUS && !flip_plus_and_minus) ||
        (n->label == MINUS && flip_plus_and_minus)) {
        for (ep = n->adj; ep; ep = ep->next) {
            e = ep->this;
            n1 = ep->other;
            if (e->x != TWO) {
                if (n1->label < PLUS) {         /* n1 is unlabeled */
                    thisv = e->weight - n->y - n1->y;
                    thisv += thisv;
                    if (thisv < minv)
                        minv = thisv;
                } else if ((n1->label == PLUS && !flip_plus_and_minus) ||
                           (n1->label == MINUS && flip_plus_and_minus)) {
                    thisv = e->weight - n->y - n1->y;
                    if (thisv < minv)
                        minv = thisv;
                } else {        /* n1 has a minus label */
                    if (n1->parentedge == e)
                        basic_minalpha (n1, new, alpha, flip_plus_and_minus);
                }
            } else if (e->basic && n1->parentedge == e) {
                basic_minalpha (n1, new, alpha, flip_plus_and_minus);
            }
        }
    } else {                    /* MINUS case */
        for (ep = n->adj; ep; ep = ep->next) {
            e = ep->this;
            n1 = ep->other;
            if (e->x == TWO) {
                if (n1->label < PLUS) {
                    thisv = e->z + e->z;
                    if (thisv < minv)
                        minv = thisv;
                } else if ((n1->label == PLUS && !flip_plus_and_minus) ||
                           (n1->label == MINUS && flip_plus_and_minus)) {
                    if (n1->parentedge == e)
                        basic_minalpha (n1, new, alpha, flip_plus_and_minus);
                } else {        /* n1 has a MINUS label */
                    thisv = e->z;
                    if (thisv < minv)
                        minv = thisv;
                }
            } else if (e->basic && n1->parentedge == e) {
                basic_minalpha (n1, new, alpha, flip_plus_and_minus);
            }
        }
    }

    if (minv < *alpha) {
        *new = n;
        n->pnext = (node *) NULL;
        *alpha = minv;
    } else if (minv == *alpha) {
        n->pnext = *new;
        *new = n;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void basic_subalpha (node *n, int alpha, int flip_plus_and_minus)
#else
static void basic_subalpha (n, alpha, flip_plus_and_minus)
node *n;
int alpha;
int flip_plus_and_minus;
#endif
{
    edge *e;
    edgeptr *ep;

    if ((n->label == PLUS && !flip_plus_and_minus) ||
        (n->label == MINUS && flip_plus_and_minus)) {
        n->y += alpha;
        for (ep = n->adj; ep; ep = ep->next) {
            e = ep->this;
            if (e->x == TWO)
                e->z += alpha;
            if (e->basic) {
                if (ep->other->parentedge == e)
                    basic_subalpha (ep->other, alpha, flip_plus_and_minus);
            }
        }
    } else {                    /* MINUS */
        n->y -= alpha;
        for (ep = n->adj; ep; ep = ep->next) {
            e = ep->this;
            if (e->x == TWO)
                e->z -= alpha;
            if (e->basic) {
                if (ep->other->parentedge == e)
                    basic_subalpha (ep->other, alpha, flip_plus_and_minus);
            }
        }
    }
}


/********** Price - Repair routines **********/


#ifdef CC_PROTOTYPE_ANSI
static int checkoutedge (node *n1, node *n2, int *hit)
#else
static int checkoutedge (n1, n2, hit)
node *n1;
node *n2;
int *hit;
#endif
{
    int w, wbar;
    edge *e;

    *hit = 0;
    w = CCutil_dat_edgelen (n1->name, n2->name, gdat);
    w += w;
    wbar = w - n1->y - n2->y;
    if (wbar < 0) {
        if ((e = findedge (n1, n2)) != (edge *) NULL) {
            if (e->z != -wbar) {
                printf ("Hmmm.  edge (%d-%d) has z %d, wbar %d\n",
                e->ends[0]->name, e->ends[1]->name, e->z, wbar);
            }
        } else {
            if (addbadedge (n1, n2, w)) {
                fprintf (stderr, "addbadedge failed\n");
                return 1;
            }
            *hit = 1;
        }
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int precheckoutedge (node *n1, node *n2, shortedge **list)
#else
static int precheckoutedge (n1, n2, list)
node *n1;
node *n2;
shortedge **list;
#endif
{
    int w, wbar;
    edge *e;
    shortedge *s;

    w = CCutil_dat_edgelen (n1->name, n2->name, gdat);
    w += w;
    wbar = w - n1->y - n2->y;
    if (wbar < 0) {
        if ((e = findedge (n1, n2)) != (edge *) NULL) {
            if (e->z != -wbar) {
                printf ("Hmmm.  edge (%d-%d) has z %d, wbar %d\n",
                e->ends[0]->name, e->ends[1]->name, e->z, wbar);
            }
        } else {
            s = shortedgealloc ();
            s->ends[0] = n1;
            s->ends[1] = n2;
            s->next = *list;
            *list = s;
            return 1;
        }
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int fixmatch (int *radded)
#else
static int fixmatch (radded)
int *radded;
#endif
{
    if ((gdat->norm & CC_NORM_BITS) == CC_KD_NORM_TYPE)
        return kd_fixmatch (radded);
    else if ((gdat->norm & CC_NORM_BITS) == CC_X_NORM_TYPE)
        return x_fixmatch (radded);
    else
        return junk_fixmatch (radded);
}

#define NEAR_TRY_NUM 1   /* The number of nearest (wbar) neighbors         */

#define PULL_DIVISOR 100 /* Do not pull more than nnodes/PULL_DIVISOR.     */
#define PULL_UNIT    100 /* Pull if PULL_UNIT nodes will cut the spread.   */
#define PULL_CUT       2 /* A unit must cut at least spread/PULL_CUT.      */

#ifdef CC_PROTOTYPE_ANSI
static int kd_fixmatch (int *radded)
#else
static int kd_fixmatch (radded)
int *radded;
#endif
{
    int rval = 0;
    int i, j, added, totaladded = 0;
    int hit, passcount = 0;
    int maxy = -MAXWEIGHT;
    int miny =  MAXWEIGHT;
    double *xcoord = (double *) NULL;
    double *ycoord = (double *) NULL;
    double *wcoord = (double *) NULL;
    CCdatagroup ldat;
    node *n;
/*
    NEEDED WHEN RADIX SORT IS WORKING
    node *ysorted;
*/
    node **heavy, **light, **order = (node **) NULL;
    int top, bottom, nlight, nheavy = 0;  /* nheavy should be set to 0 */
    int *invnames = (int *) NULL;
    double *lbnds = (double *) NULL, *gbnds = (double *) NULL;

    *radded = 0;

    ldat.x = (double *) NULL;
    ldat.y = (double *) NULL;
    ldat.z = (double *) NULL;
    ldat.adj = (int **) NULL;
    ldat.norm = gdat->norm;


    for (n = nodellist; n; n = n->next) {
        if (n->y < miny)
            miny = n->y;
        if (n->y > maxy)
            maxy = n->y;
    }
    printf ("Node weight spread: (%d, %d)\n", miny, maxy);
    fflush (stdout);

/*
    THIS CODE CANNOT BE USED UNDER OS2 WITH CURRENT RADIX
    for (n = nodellist; n; n = n->next)
        n->pnext = n->next;
    ysorted = (node *) CCutil_linked_radixsort ((char *) nodellist,
        (char *) &(nodellist->pnext),
        (char *) &(nodellist->y), sizeof (int));

    order = CC_SAFE_MALLOC (nnodes, node *);
    if (!order) {
        rval = 1;
        goto CLEANUP;
    }

    THIS IS THE CODE WHEN RADIXSORT WORKS WITH NEGATIVES
    for (i = 0, n = ysorted; n; i++, n = n->pnext) {
        order[i] = n;
    }

    INSTEAD, THIS CODE WORKS WITH CURRENT RADIX ON THE RS6000
    for (n = ysorted; n; n = n->pnext)
        if (n->y < 0)
            break;
    for (i = 0; n; n = n->pnext, i++)
        order[i] = n;
    for (n = ysorted; n && n->y >= 0; n = n->pnext, i++)
        order[i] = n;
*/

    {
        /* ONLY HERE UNTIL RADIX WORKS */
        int *y;

        order = CC_SAFE_MALLOC (nnodes, node *);
        if (!order) {
            rval = 1;
            goto CLEANUP;
        }
        y = CC_SAFE_MALLOC (nnodes, int);
        if (!y) {
            rval = 1;
            goto CLEANUP;
        }
        for (i = 0; i < nnodes; i++) {
            order[i] = nodenames[i];
            y[i] = nodenames[i]->y;
        }
        y_quicksort (order, y, 0, nnodes - 1);

        CC_FREE (y, int);
    }


    {
        int new, newspread, newtop, newbottom, spread;

        newtop = top = -1;
        newbottom = bottom = nnodes;
        nheavy = 0;
        spread = maxy - miny;

        do {
            new = 0;
            while (new < PULL_UNIT && nheavy + new < nnodes/ PULL_DIVISOR) {
                if (order[newbottom - 1]->y > -2 * order[newtop + 1]->y)
                    newbottom--;
                else
                    newtop++;
                new++;
            }
            newspread = order[newbottom - 1]->y - order[newtop + 1]->y;
            if (spread - newspread > spread / PULL_CUT) {
                spread = newspread;
                bottom = newbottom;
                top = newtop;
                nheavy += new;
            }
        } while (spread == newspread && nheavy < nnodes / PULL_DIVISOR);
    }


    printf ("Truncated %d nodes to get spread: (%d, %d)\n",
        nheavy, order[top + 1]->y, order[bottom - 1]->y);
    fflush (stdout);


    if (nheavy) {
        heavy = order;
        light = order + nheavy;
        nlight = nnodes - nheavy;
/*
        THIS IS THE CODE WHEN RADIXSORT WORKS WITH NEGATIVES
        for (i = 0, n = ysorted; i <= top; i++, n = n->pnext) {
            heavy[i] = n;
        }
        for (i = 0; i < nlight; i++, n = n->pnext) {
            light[i] = n;
        }
        for (i = top + 1; i < nheavy; i++, n = n->pnext) {
            heavy[i] = n;
        }
*/
        {
            node **temporder = (node **) NULL;
            int k;

            temporder = CC_SAFE_MALLOC (nnodes, node *);
            if (!temporder) {
                rval = 1;
                goto CLEANUP;
            }
            for (i = 0; i < nnodes; i++)
                temporder[i] = order[i];

            for (i = 0, k = 0; i <= top; i++)
                heavy[i] = temporder[k++];
            for (i = 0; i < nlight; i++)
                light[i] = temporder[k++];
            for (i = top + 1; i < nheavy; i++)
                heavy[i] = temporder[k++];
                CC_FREE (temporder, node *);
        }

        lbnds = CC_SAFE_MALLOC (nheavy, double);
        if (!lbnds) {
            rval = 1;
            goto CLEANUP;
        }
        gbnds = CC_SAFE_MALLOC (nheavy, double);
        if (!gbnds) {
            rval = 1;
            goto CLEANUP;
        }
        xcoord = CC_SAFE_MALLOC (nlight, double);
        if (!xcoord) {
            rval = 1;
            goto CLEANUP;
        }
        ldat.x = xcoord;
        ycoord = CC_SAFE_MALLOC (nlight, double);
        if (!ycoord) {
            rval = 1;
            goto CLEANUP;
        }
        ldat.y = ycoord;
        for (i = 0; i < nlight; i++) {
            xcoord[i] = gdat->x[light[i]->name];
            ycoord[i] = gdat->y[light[i]->name];
        }
    } else {
        nlight = nnodes;
        light = nodenames;
        heavy = (node **) NULL;
        xcoord = gdat->x;
        ycoord = gdat->y;
        ldat.x = xcoord;
        ldat.y = ycoord;
        CC_FREE (order, node *);
    }

    wcoord = CC_SAFE_MALLOC (nlight, double);
    if (!wcoord) {
        rval = 1;
        goto CLEANUP;
    }
    invnames = CC_SAFE_MALLOC (nnodes, int);
    if (!invnames) {
        rval = 1;
        goto CLEANUP;
    }
    for (i = 0; i < nlight; i++)
        invnames[light[i]->name] = i;
    for (i = 0; i < nheavy; i++)
        invnames[heavy[i]->name] = -i;


    do {
        int nodeschecked = 0;
        int saver = 0;
        int list[NEAR_TRY_NUM];
        shortedge *s, *snext, *slist = (shortedge *) NULL;
        CCkdtree localkt;
        added = 0;
        maxy = -MAXWEIGHT;
        for (i = 0; i < nlight; i++) {
            if (light[i]->y > maxy)
                maxy = light[i]->y;
        }
        for (i = 0; i < nlight; i++)
            wcoord[i] = ((double) (maxy - light[i]->y)) * 0.5;
        if (CCkdtree_build (&localkt, nlight, &ldat, wcoord)) {
            fprintf (stderr, "Unable to build CCkdtree\n");
            rval = 1;
            goto CLEANUP;
        }
        for (i = 0; i < nheavy; i++) {                    /* 1.0 for floats */
            lbnds[i] = gdat->x[heavy[i]->name] -
                          (((double) (heavy[i]->y)) * 0.5) - 1.0;
            gbnds[i] = gdat->x[heavy[i]->name] +
                          (((double) (heavy[i]->y)) * 0.5) + 1.0;
        }

        for (i = 0; i < nlight; i++) {
            if (light[i]->label != -1) {
                edgeptr *ep;
                hit = 0;
                for (ep = light[i]->adj; ep; ep = ep->next) {
                    if (ep->this->x != ZERO && invnames[ep->other->name] >= 0)
                        CCkdtree_delete (&localkt, invnames[ep->other->name]);
                }
                nodeschecked++;
                if (CCkdtree_node_k_nearest (&localkt, nlight, i, NEAR_TRY_NUM,
                                           &ldat, wcoord, list)) {
                    fprintf (stderr, "node nearest failed\n");
                    CCkdtree_free (&localkt);
                    rval = 1;
                    goto CLEANUP;
                }
                for (j = NEAR_TRY_NUM - 1; j >= 0; j--) {
                    if (list[j] != -1)
                        hit += precheckoutedge (light[i],
                                                light[list[j]], &slist);
                }
                for (j = 0; j < nheavy; j++) {
                    if (heavy[j]->label == -1) {
                        if (xcoord[i] +
                               (((double) light[i]->y) * 0.5) > lbnds[j] &&
                            xcoord[i] -
                               (((double) light[i]->y) * 0.5) < gbnds[j]) {
                            hit += precheckoutedge (light[i], heavy[j], &slist);
                        } else {
                            saver++;
                        }
                    }
                }
                added += hit;
                if (hit == 0)
                    light[i]->label = -1;
                for (ep = light[i]->adj; ep; ep = ep->next) {
                    if (ep->this->x != ZERO && invnames[ep->other->name] >= 0)
                        CCkdtree_undelete (&localkt, invnames[ep->other->name]);
                }
            }
        }
        for (j = 0; j < nheavy; j++) {
            if (heavy[j]->label != -1) {
                hit = 0;
                nodeschecked++;
                for (i = 0; i < nlight; i++) {
                    if (xcoord[i] + (((double) light[i]->y) * 0.5) > lbnds[j] &&
                        xcoord[i] - (((double) light[i]->y) * 0.5) < gbnds[j]) {
                        hit += precheckoutedge (light[i], heavy[j], &slist);
                    } else {
                        saver++;
                    }
                }
                for (i = 0; i < j; i++) {
                    if (gdat->x[heavy[i]->name] +
                          (((double) heavy[i]->y) * 0.5) > lbnds[j] &&
                        gdat->x[heavy[i]->name] -
                          (((double) heavy[i]->y) * 0.5) < gbnds[j]) {
                        hit += precheckoutedge (heavy[i], heavy[j], &slist);
                    }
                }
                for (i = j + 1; i < nheavy; i++) {
                    if (heavy[i]->label == -1) {
                        if (gdat->x[heavy[i]->name] +
                              (((double) heavy[i]->y) * 0.5) > lbnds[j] &&
                            gdat->x[heavy[i]->name] -
                              (((double) heavy[i]->y) * 0.5) < gbnds[j]) {
                            hit += precheckoutedge (heavy[i], heavy[j], &slist);
                        }
                    }
                }
                added += hit;
                if (hit == 0)
                    heavy[j]->label = -1;
            }
        }

        printf ("Need to check %d edges (saved %d checks)\n", added, saver);
        fflush (stdout);
        CCkdtree_free (&localkt);

        added = 0;
        for (s = slist; s; s = snext) {
            snext = s->next;
            if (checkoutedge (s->ends[0], s->ends[1], &hit)) {
                fprintf (stderr, "checkoutedge failed\n");
                rval = 1;
                goto CLEANUP;
            }
            added += hit;
            shortedgefree (s);
        }
        totaladded += added;
        printf ("Pass %d: %d edges added (%d total), %d nodes checked\n",
                              passcount++, added, totaladded, nodeschecked);
        fflush (stdout);
    } while (added);
    *radded = totaladded;

CLEANUP:

    CC_IFFREE (invnames, int);
    CC_IFFREE (wcoord, double);
    CC_IFFREE (order, node *);
    if (nheavy) {
        CC_IFFREE (xcoord, double);
        CC_IFFREE (ycoord, double);
        CC_IFFREE (lbnds, double);
        CC_IFFREE (gbnds, double);
    }
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static void initlist (node *head, node *tail, node *head2, node *tail2)
#else
static void initlist (head, tail, head2, tail2)
node *head;
node *tail;
node *head2;
node *tail2;
#endif
{
    node *n, *p;
    int bound;
    double *xcoord = gdat->x;
    double scale;

    if (gdat->norm == CC_GEOGRAPHIC)
        scale = CC_GEOGRAPHIC_SCALE;
    else if (gdat->norm == CC_ATT)
        scale = CC_ATT_SCALE;
    else
        scale = 1.0;

    head->sort.order = -MAXWEIGHT;
    tail->sort.order = MAXWEIGHT;
    head->sort.next = tail;
    head->sort.prev = (node **) NULL;
    tail->sort.next = (node *) NULL;
    tail->sort.prev = &(head->sort.next);
    head2->sort.order = MAXWEIGHT;
    tail2->sort.order = -MAXWEIGHT;
    head2->sort.next = tail2;
    head2->sort.prev = (node **) NULL;
    tail2->sort.next = (node *) NULL;
    tail2->sort.prev = &(head2->sort.next);

    for (n = nodellist; n; n = n->next) {
        bound = (2 * ((int) (scale * xcoord[n->name]))) - n->y;
        for (p = head->sort.next; p->sort.order < bound; p = p->sort.next);
        n->sort.order = bound;
        n->sort.next = p;
        n->sort.prev = p->sort.prev;
        *(n->sort.prev) = n;
        p->sort.prev = &(n->sort.next);
    }
}

#ifdef CC_PROTOTYPE_ANSI
static int x_fixmatch (int *radded)
#else
static int x_fixmatch (radded)
int *radded;
#endif
{
    node *n1, *n2;
    int i;
    int added, hit;
    int nodeschecked;
    int edgeschecked;
    int totaladded = 0;
    node high_fakehead, high_faketail, low_fakehead, low_faketail;
    int bound;
    double *xcoord = gdat->x;
    double scale;

    if ((gdat->norm & CC_NORM_BITS) != CC_X_NORM_TYPE &&
        (gdat->norm & CC_NORM_BITS) != CC_KD_NORM_TYPE) {
        fprintf (stderr, "Cannot run x_fixmatch with norm %d\n", gdat->norm);
        return 1;
    }

    if (gdat->norm == CC_GEOGRAPHIC)
        scale = CC_GEOGRAPHIC_SCALE;
    else if (gdat->norm == CC_ATT)
        scale = CC_ATT_SCALE;
    else
        scale = 1.0;

    initlist (&high_fakehead, &high_faketail, &low_fakehead, &low_faketail);

    do {
        added = 0;
        nodeschecked = 0;
        edgeschecked = 0;
        for (i = 0; i < nnodes; i++) {
            n1 = nodenames[i];
            *(n1->sort.prev) = n1->sort.next;
            n1->sort.next->sort.prev = n1->sort.prev;
            if (n1->label != -1) {
                nodeschecked++;
                n1->label = -1;
                bound = (2 * ((int) (scale * xcoord[n1->name]))) + n1->y + 3;
                 /* Need the +3 to handle floating point data */
                for (n2 = high_fakehead.sort.next; n2->sort.order < bound;
                     n2 = n2->sort.next) {
                    edgeschecked++;
                    if (checkoutedge (n1, n2, &hit)) {
                        fprintf (stderr, "checkoutedge failed\n");
                        return 1;
                    }
                    added += hit;
                }
                bound = (2 * ((int) (scale * xcoord[n1->name]))) - n1->y - 3;
                for (n2 = low_fakehead.sort.next; n2->sort.order > bound;
                     n2 = n2->sort.next) {
                    edgeschecked++;
                    if (checkoutedge (n1, n2, &hit)) {
                        fprintf (stderr, "checkoutedge failed\n");
                        return 1;
                    }
                    added += hit;
                }
            }
            bound = (2 * ((int) (scale * xcoord[n1->name]))) + n1->y;
            for (n2 = low_fakehead.sort.next; n2->sort.order > bound;
                 n2 = n2->sort.next);
            n1->sort.order = bound;
            n1->sort.next = n2;
            n1->sort.prev = n2->sort.prev;
            *(n1->sort.prev) = n1;
            n2->sort.prev = &n1->sort.next;
        }
        totaladded += added;
        printf ("Forward pass completed, %d nodes checked, %d edges checked\n",
                nodeschecked, edgeschecked);
        printf ("    %d edges added, total %d edges added\n",
                added, totaladded);
        if (added == 0)
            break;
        added = 0;
        nodeschecked = 0;
        edgeschecked = 0;
        for (i = nnodes - 1; i >= 0; i--) {
            n1 = nodenames[i];
            *(n1->sort.prev) = n1->sort.next;
            n1->sort.next->sort.prev = n1->sort.prev;
            if (n1->label != -1) {
                nodeschecked++;
                n1->label = -1;
                bound = (2 * ((int) (scale * xcoord[n1->name]))) + n1->y + 3;
                for (n2 = high_fakehead.sort.next; n2->sort.order < bound;
                     n2 = n2->sort.next) {
                    edgeschecked++;
                    if (checkoutedge (n1, n2, &hit)) {
                        fprintf (stderr, "checkoutedge failed\n");
                        return 1;
                    }
                    added += hit;
                }
                bound = (2 * ((int) (scale * xcoord[n1->name]))) - n1->y - 3;
                for (n2 = low_fakehead.sort.next; n2->sort.order > bound;
                     n2 = n2->sort.next) {
                    edgeschecked++;
                    if (checkoutedge (n1, n2, &hit)) {
                        fprintf (stderr, "checkoutedge failed\n");
                        return 1;
                    }
                    added += hit;
                }
            }
            bound = (2 * ((int) (scale * xcoord[n1->name]))) - n1->y;
            for (n2 = high_fakehead.sort.next; n2->sort.order < bound;
                 n2 = n2->sort.next);
            n1->sort.order = bound;
            n1->sort.next = n2;
            n1->sort.prev = n2->sort.prev;
            *(n1->sort.prev) = n1;
            n2->sort.prev = &n1->sort.next;
        }
        totaladded += added;
        printf ("Backward pass completed, %d nodes checked, %d edges checked\n",
                nodeschecked, edgeschecked);
        printf ("    %d edges added, total %d edges added\n",
                added, totaladded);
    } while (added);
    *radded = totaladded;
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int junk_fixmatch (int *radded)
#else
static int junk_fixmatch (radded)
int *radded;
#endif
{
    int added, hit, totaladded = 0;
    node *n1, *n2;

    *radded = 0;

    do {
        added = 0;
        for (n1 = nodellist; n1; n1 = n1->next) {
            for (n2 = n1->next; n2; n2 = n2->next) {
                if (checkoutedge (n1, n2, &hit)) {
                    fprintf (stderr, "checkoutedge failed\n");
                    return 1;
                }
                added += hit;
            }
        }
        totaladded += added;
        printf ("Pass completed: %d edges added, total %d edges added\n",
                 added, totaladded);
        fflush (stdout);
    } while (added);

    *radded = totaladded;
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int addbadedge (node *n1, node *n2, int w)
#else
static int addbadedge (n1, n2, w)
node *n1;
node *n2;
int w;
#endif
{
    int wbar = -(w - n1->y - n2->y);
    edgeptr *ep;
    edge *newe;
    node *other1 = 0, *other2 = 0;

    for (ep = n1->adj; ep; ep = ep->next) {
        switch (ep->this->x) {
        case ONE:
            flipcycle (n1, ep->this, ZERO);
            n1->matchcnt--;
            break;
        case TWO:
            if ((ep->this->z -= wbar) < 0) {
                ep->this->z = 0;
                ep->this->x = ZERO;
                n1->matchcnt--;
                ep->other->matchcnt--;
                other2 = other1;
                other1 = ep->other;
            }
            break;
        }
    }
    n1->y -= wbar;
    newe = newedge (n1, n2);
    if (!newe)
        return 1;
    newe->weight = w;
    newe->z = 0;
    newe->x = ZERO;
    newe->pnext = (edge *) NULL;
    while (n1->matchcnt != TWO)
        augment (n1);
    if (other1) {
        while (other1->matchcnt != TWO)
            augment (other1);
    }
    if (other2) {
        while (other2->matchcnt != TWO)
            augment (other2);
    }
    return 0;
}

#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

#ifdef CC_PROTOTYPE_ANSI
static void y_quicksort (node **list, int *y, int l, int u)
#else
static void y_quicksort (list, y, l, u)
node **list;
int *y;
int l, u;
#endif
{
    int i, j, t;
    int itemp;
    node *ntemp;

    if (l >= u)
        return;

    SWAP (y[l], y[(l+u)/2], itemp);
    SWAP (list[l], list[(l+u)/2], ntemp);

    i = l;
    j = u + 1;
    t = y[l];

    while (1) {
        do i++; while (i <= u && y[i] < t);
        do j--; while (y[j] > t);
        if (j < i) break;
        SWAP (y[i], y[j], itemp);
        SWAP (list[i], list[j], ntemp);
    }
    SWAP (y[l], y[j], itemp);
    SWAP (list[l], list[j], ntemp);
    y_quicksort (list, y, l, j - 1);
    y_quicksort (list, y, i, u);
}
