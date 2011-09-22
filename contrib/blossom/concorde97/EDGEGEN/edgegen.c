/***************************************************************************/
/*                                                                         */
/*                   COMPUTING INITIAL EDGE SETS                           */
/*                                                                         */
/*                             TSP CODE                                    */
/*                                                                         */
/*                                                                         */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook                       */
/*  Date: May 9, 1995                                                      */
/*  Changes: 6.8.1996 (bico) fixed bug in f2match nearest                  */
/*                                                                         */
/*                                                                         */
/*  EXPORTED FUNCTIONS:                                                    */
/*    int CCedgegen_read (char *egname, CCedgegengroup *plan)              */
/*      READS an edgegen description from file egname.                     */
/*        -egname the name of a file                                       */
/*        -plan returns the description of the mix of edges (can be used   */
/*         in a call to edgegen () to obtain the edgeset.                  */
/*                                                                         */
/*    int CCedgegen_edges (CCedgegengroup *plan, int ncount,               */
/*            CCdatagroup *dat, double *wcoord, int *ecount, int **elist)  */
/*      RETURNS the set of edges described in plan.                        */
/*        -plan describes the mix of edges                                 */
/*        -ncount is the number of nodes                                   */
/*        -dat contains the info to generate edge lengths                  */
/*        -wcoord are nodeweights for Held-Karp style edge lengths, using  */
/*         len[i,j] + wcoord[i] + wcoord[j] (wcoord can be NULL)           */
/*        -ecount returns the number of edges                              */
/*        -elist returns the edges in end1 end2 format                     */
/*                                                                         */
/*    void CCedgegen_init_edgegengroup (CCedgegengroup *plan)              */
/*      SETS the fields in plan to 0 (since there are so many fields to    */
/*        to deal with)                                                    */
/*                                                                         */
/*  NOTES:                                                                 */
/*       To use edgegen, look at the defintion of edgegengroup in          */
/*    edgegen.h - you should be able to guess what the parmeters mean.     */
/*    Note that wcoord is only used by a limited number of the generating  */
/*    routines, for example nearest, but not linkern.                      */
/*       The functions edgegen and edgegen_read will return nonzero values */
/*    if they fail (for example, if they run out of memory.                */
/*       The description file passed to edgegen_read should contain a list */
/*    of some of the following commands:                                   */
/*            EDGEGEN NEAREST #                                            */
/*                    -find the nearest # edges                            */
/*            EDGEGEN QUADNEAREST #                                        */
/*                    -find the quadrant-nearest # edges                   */
/*            EDGEGEN FRAC_TWOMATCH_NEAREST # [PRICED] [BASIC]             */
/*                    -find the nearest # using the reduced costs of a     */
/*                     fractional 2-matching as the edgelengths. If either */
/*                     of the optional arguments PRICED or BASIC is        */
/*                     specified then the 2-matching used will be either   */
/*                     priced against the complete edgeset or converted to */
/*                     a basic optimal solution (or both).                 */
/*            EDGEGEN GREEDY_TOUR                                          */
/*                    -find a greedy tour                                  */
/*            EDGEGEN NN_TOUR #                                            */
/*                    -find # nearest-neighbor tours                       */
/*            EDGEGEN RANDOM_TOUR #                                        */
/*                    -find # random tours                                 */
/*            EDGEGEN TWOOPT_TOUR #                                        */
/*                    -find # 2-opt tours                                  */
/*            EDGEGEN TWOPT5_TOUR #                                        */
/*                    -find # 2.5-opt tours                                */
/*            EDGEGEN THREEOPT_TOUR #                                      */
/*                    -find # 3-opt tours                                  */
/*            EDGEGEN LINKERN #1 #2 [QUADNEAREST #3] [NEAREST #4]          */
/*                              [GREEDY_START | NN_START | RANDOM_START]   */
/*                    -find #1 Iterated Lin-Kernighan tours using #2 kicks.*/
/*                     The good edgeset can be specified by the optional   */
/*                     arguments QUADNEAREST and NEAREST (the two can be   */
/*                     used together). The initial tours can be specfied   */
/*                     by using one of GREEDY_START or NN_START or         */
/*                     RANDOM_START.                                       */
/*            EDGEGEN NN_TWOMATCH #                                        */
/*                    -find # nearest-neighbor 2-matchings                 */
/*            EDGEGEN TREE                                                 */
/*                    -find a minimum weight spanning tree.                */
/*            EDGEGEN FRAC_TWOMATCH [PRICED] [BASIC]                       */
/*                    -find a minmum weight 2-matching (priced against the */
/*                     complete edgeset) (that is a basic optimal solution)*/
/*                                                                         */
/***************************************************************************/

#include "machdefs.h"
#include "util.h"
#include "edgegen.h"
#include "kdtree.h"
#include "linkern.h"
#include "fmatch.h"

#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

typedef struct intptr {
    int this;
    struct intptr *next;
} intptr;

static intptr **table = (intptr **) NULL;
static int      tabletotal = 0;

#ifdef CC_PROTOTYPE_ANSI

static int
    call_kdtree_build (CCkdtree *kt, int ncount, CCdatagroup *dat,
        double *wcoord, int *built_a_tree),
    call_nearest (int ncount, CCdatagroup *dat, double *wcoord, int nearnum,
        CCkdtree *kt),
    work_nearest (CCkdtree *kt, int ncount, int nearnum, CCdatagroup *dat,
        double *wcoord, int *ecount, int **elist),
    call_quadnearest (int ncount, CCdatagroup *dat, double *wcoord, int nearnum,
        CCkdtree *kt),
    work_quadnearest (CCkdtree *kt, int ncount, int nearnum, CCdatagroup *dat,
        double *wcoord, int *ecount, int **elist),
    call_random_tour (int ncount, CCdatagroup *dat, int number),
    call_nearest_tour (int ncount, CCdatagroup *dat, int number, CCkdtree *kt),
    work_nearest_tour (CCkdtree *kt, int ncount, int start, CCdatagroup *dat,
        int *tour, double *val),
    call_greedy_tour (int ncount, CCdatagroup *dat, CCkdtree *kt),
    call_twoopt_tour (int ncount, CCdatagroup *dat, CCkdtree *kt, int number,
        int two_and_a_half, int use_3opt),
    call_linkern (int ncount, CCdatagroup *dat, CCkdtree *kt,
        CCedgegengroup *plan),
    call_nearest_twomatch (int ncount, CCdatagroup *dat, int number,
        CCkdtree *kt),
    call_f2match (int ncount, CCdatagroup *dat, CCkdtree *kt, int priceit,
        int basic),
    call_f2match_nearest (int ncount, CCdatagroup *dat, CCkdtree *kt,
        int number, int priceit, int basic),
    call_spanning_tree (int ncount, CCdatagroup *dat, double *wcoord,
        CCkdtree *kt),
    f2match_initial_edgeset (int ncount, CCdatagroup *dat, CCkdtree *kt,
        int *ecount, int **elist, int **elen),
    put_tour_in_table (int ncount, int *tour),
    put_in_table (int i, int j),
    general_put_in_table (int i, int j, int *added, intptr **tab);

static void
    randcycle (int ncount, int *cyc, CCdatagroup *dat, double *val);

#else

static int
    call_kdtree_build (),
    call_nearest (),
    work_nearest (),
    call_quadnearest (),
    work_quadnearest (),
    call_random_tour (),
    call_nearest_tour (),
    work_nearest_tour (),
    call_greedy_tour (),
    call_twoopt_tour (),
    call_linkern (),
    call_nearest_twomatch (),
    call_f2match (),
    call_f2match_nearest (),
    call_spanning_tree (),
    f2match_initial_edgeset (),
    put_tour_in_table (),
    put_in_table (),
    general_put_in_table ();

static void
    randcycle ();

#endif /* CC_PROTOTYPE_ANSI */

CC_PTR_ALLOC_ROUTINE (intptr, intptralloc, intptrchunklist, intptrfreelist)
CC_PTR_FREE_ROUTINE (intptr, intptrfree, intptrfreelist)
CC_PTR_FREE_WORLD_ROUTINE (intptr, intptrfree_world, intptrchunklist,
        intptrfreelist)
CC_PTR_LEAKS_ROUTINE (intptr, intptr_check_leaks, intptrchunklist,
        intptrfreelist, this, int)


#ifdef CC_PROTOTYPE_ANSI
int CCedgegen_edges (CCedgegengroup *plan, int ncount, CCdatagroup *dat,
        double *wcoord, int *ecount, int **elist)
#else
int CCedgegen_edges (plan, ncount, dat, wcoord, ecount, elist)
CCedgegengroup *plan;
int ncount;
CCdatagroup *dat;
double *wcoord;
int *ecount;
int **elist;
#endif
{
    int rval = 0;
    int i;
    int total, onlist;
    CCkdtree kt;
    int built_a_tree = 0;
    double szeit = CCutil_zeit ();

    *ecount = 0;
    *elist = (int *) NULL;

    if (ncount < 3) {
        fprintf (stderr, "Cannot run edgegen in an %d node graph\n", ncount);
        return 1;
    }

    table = CC_SAFE_MALLOC (ncount, intptr *);
    if (!table) {
        rval = 1;
        goto CLEANUP;
    }
    for (i = 0; i < ncount; i++)
        table[i] = (intptr *) NULL;
    tabletotal = 0;

    if (plan->nearest) {
        if (!built_a_tree) {
            if (call_kdtree_build (&kt, ncount, dat, wcoord, &built_a_tree)) {
                fprintf (stderr, "call_kdtree_build failed\n");
                rval = 1;
                goto CLEANUP;
            }
        }
        if (call_nearest (ncount, dat, wcoord, plan->nearest, &kt)) {
            fprintf (stderr, "call_nearest failed\n");
            rval = 1;
            goto CLEANUP;
        }
    }
    if (plan->quadnearest) {
        if (!built_a_tree) {
            if (call_kdtree_build (&kt, ncount, dat, wcoord, &built_a_tree)) {
                fprintf (stderr, "call_kdtree_build failed\n");
                rval = 1;
                goto CLEANUP;
            }
        }
        if (call_quadnearest (ncount, dat, wcoord, plan->quadnearest, &kt)) {
            fprintf (stderr, "call_quadnearest failed\n");
            rval = 1;
            goto CLEANUP;
        }
    }
    if (plan->tour.random_count) {
        if (call_random_tour (ncount, dat, plan->tour.random_count)) {
            fprintf (stderr, "call_random_tour failed\n");
            rval = 1;
            goto CLEANUP;
        }
    }
    if (plan->tour.nearest_count) {
        if (!built_a_tree) {
            if (call_kdtree_build (&kt, ncount, dat, wcoord, &built_a_tree)) {
                fprintf (stderr, "call_kdtree_build failed\n");
                rval = 1;
                goto CLEANUP;
            }
        }
        if (call_nearest_tour (ncount, dat, plan->tour.nearest_count, &kt)) {
            fprintf (stderr, "call_nearest_tour failed\n");
            rval = 1;
            goto CLEANUP;
        }
    }
    if (plan->tour.greedy) {
        if (!built_a_tree) {
            if (call_kdtree_build (&kt, ncount, dat, wcoord, &built_a_tree)) {
                fprintf (stderr, "call_kdtree_build failed\n");
                rval = 1;
                goto CLEANUP;
            }
        }
        if (call_greedy_tour (ncount, dat, &kt)) {
            fprintf (stderr, "call_greedy_tour failed\n");
            rval = 1;
            goto CLEANUP;
        }
    }
    if (plan->tour.twoopt_count) {
        if (!built_a_tree) {
            if (call_kdtree_build (&kt, ncount, dat, wcoord, &built_a_tree)) {
                fprintf (stderr, "call_kdtree_build failed\n");
                rval = 1;
                goto CLEANUP;
            }
        }
        if (call_twoopt_tour (ncount, dat, &kt, plan->tour.twoopt_count,
                              0, 0)) {
            fprintf (stderr, "call_twoopt_tour failed\n");
            rval = 1;
            goto CLEANUP;
        }
    }
    if (plan->tour.twoopt5_count) {
        if (!built_a_tree) {
            if (call_kdtree_build (&kt, ncount, dat, wcoord, &built_a_tree)) {
                fprintf (stderr, "call_kdtree_build failed\n");
                rval = 1;
                goto CLEANUP;
            }
        }
        if (call_twoopt_tour (ncount, dat, &kt, plan->tour.twoopt5_count,
                              1, 0)) {
            fprintf (stderr, "call_twoopt_tour failed\n");
            rval = 1;
            goto CLEANUP;
        }
    }
    if (plan->tour.threeopt_count) {
        if (!built_a_tree) {
            if (call_kdtree_build (&kt, ncount, dat, wcoord, &built_a_tree)) {
                fprintf (stderr, "call_kdtree_build failed\n");
                rval = 1;
                goto CLEANUP;
            }
        }
        if (call_twoopt_tour (ncount, dat, &kt, plan->tour.threeopt_count,
                              0, 1)) {
            fprintf (stderr, "call_threeopt_tour failed\n");
            rval = 1;
            goto CLEANUP;
        }
    }
    if (plan->linkern.count) {
        if (!built_a_tree) {
            if (call_kdtree_build (&kt, ncount, dat, wcoord, &built_a_tree)) {
                fprintf (stderr, "call_kdtree_build failed\n");
                rval = 1;
                goto CLEANUP;
            }
        }
        if (call_linkern (ncount, dat, &kt, plan)) {
            fprintf (stderr, "call_linkern failed\n");
            rval = 1;
            goto CLEANUP;
        }
    }
    if (plan->want_tree) {
        if (!built_a_tree) {
            if (call_kdtree_build (&kt, ncount, dat, wcoord, &built_a_tree)) {
                fprintf (stderr, "call_kdtree_build failed\n");
                rval = 1;
                goto CLEANUP;
            }
        }
        if (call_spanning_tree (ncount, dat, wcoord, &kt)) {
            fprintf (stderr, "call_spanning_tree failed\n");
            rval = 1;
            goto CLEANUP;
        }
    }
    if (plan->nearest_twomatch_count) {
        if (!built_a_tree) {
            if (call_kdtree_build (&kt, ncount, dat, wcoord, &built_a_tree)) {
                fprintf (stderr, "call_kdtree_build failed\n");
                rval = 1;
                goto CLEANUP;
            }
        }
        if (call_nearest_twomatch (ncount, dat, plan->nearest_twomatch_count,
                                   &kt)) {
            fprintf (stderr, "call_nearest_twomatch failed\n");
            rval = 1;
            goto CLEANUP;
        }
    }
    if (plan->f2match.wantit) {
        if (!built_a_tree) {
            if (call_kdtree_build (&kt, ncount, dat, wcoord, &built_a_tree)) {
                fprintf (stderr, "call_kdtree_build failed\n");
                rval = 1;
                goto CLEANUP;
            }
        }
        if (call_f2match (ncount, dat, &kt, plan->f2match.priced,
                          plan->f2match.basic)) {
            fprintf (stderr, "call_f2match failed\n");
            rval = 1;
            goto CLEANUP;
        }
    }
    if (plan->f2match_nearest.number) {
        if (!built_a_tree) {
            if (call_kdtree_build (&kt, ncount, dat, wcoord, &built_a_tree)) {
                fprintf (stderr, "call_kdtree_build failed\n");
                rval = 1;
                goto CLEANUP;
            }
        }
        if (call_f2match_nearest (ncount, dat, &kt,
               plan->f2match_nearest.number, plan->f2match_nearest.priced,
               plan->f2match_nearest.basic)) {
            fprintf (stderr, "call f2match_nearest failed\n");
            rval = 1;
            goto CLEANUP;
        }
    }

    printf ("Edgegen total edges: %d (%.2f seconds)\n", tabletotal,
                                             CCutil_zeit () - szeit);
    fflush (stdout);

    if (tabletotal) {
        int j = 0;
        intptr *ip, *ipnext;

        *elist = CC_SAFE_MALLOC (2 * tabletotal, int);
        if (!(*elist)) {
            rval = 1;
            goto CLEANUP;
        }
        *ecount = tabletotal;
        for (i = 0; i < ncount; i++) {
            for (ip = table[i]; ip; ip = ipnext) {
                ipnext =  ip->next;
                (*elist)[j++] = i;
                (*elist)[j++] = ip->this;
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

    if (built_a_tree)
        CCkdtree_free (&kt);
    intptrfree_world ();
    CC_IFFREE (table, intptr *);

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static int call_kdtree_build (CCkdtree *kt, int ncount, CCdatagroup *dat,
        double *wcoord, int *built_a_tree)
#else
static int call_kdtree_build (kt, ncount, dat, wcoord, built_a_tree)
CCkdtree *kt;
int ncount;
CCdatagroup *dat;
double *wcoord;
int *built_a_tree;
#endif
{
    double tzeit;

    *built_a_tree = 0;
    if ((dat->norm & CC_NORM_BITS) == CC_KD_NORM_TYPE) {
        tzeit = CCutil_zeit ();
        if (CCkdtree_build (kt, ncount, dat, wcoord)) {
            fprintf (stderr, "CCkdtree_build failed\n");
            return 1;
        }
        printf ("Built CCkdtree: %.2f (seconds)\n", CCutil_zeit () - tzeit);
        *built_a_tree = 1;
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
void CCedgegen_init_edgegengroup (CCedgegengroup *plan)
#else
void CCedgegen_init_edgegengroup (plan)
CCedgegengroup *plan;
#endif
{
    plan->linkern.count = 0;
    plan->linkern.quadnearest = 0;
    plan->linkern.nearest = 0;
    plan->linkern.greedy_start = 0;
    plan->linkern.random_start = 0;
    plan->linkern.nearest_start = 0;
    plan->linkern.nkicks = 0;

    plan->tour.twoopt_count = 0;
    plan->tour.twoopt5_count = 0;
    plan->tour.threeopt_count = 0;
    plan->tour.greedy = 0;
    plan->tour.nearest_count = 0;
    plan->tour.random_count = 0;

    plan->f2match.wantit = 0;
    plan->f2match.basic = 0;
    plan->f2match.priced = 0;

    plan->f2match_nearest.number = 0;
    plan->f2match_nearest.basic = 0;
    plan->f2match_nearest.priced = 0;

    plan->nearest = 0;
    plan->quadnearest = 0;
    plan->want_tree = 0;
    plan->nearest_twomatch_count = 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int call_nearest (int ncount, CCdatagroup *dat, double *wcoord,
        int nearnum, CCkdtree *kt)
#else
static int call_nearest (ncount, dat, wcoord, nearnum, kt)
int ncount;
CCdatagroup *dat;
double *wcoord;
int nearnum;
CCkdtree *kt;
#endif
{
    double szeit = CCutil_zeit ();
    int current = tabletotal;
    int tcount = 0;
    int *tlist = (int *) NULL;
    int i;


    if (work_nearest (kt, ncount, nearnum, dat, wcoord, &tcount, &tlist)) {
        fprintf (stderr, "work_nearest failed\n");
        return 1;
    }
    for (i = 0; i < tcount; i++) {
        if (put_in_table (tlist[2 * i], tlist[(2 * i) + 1])) {
            fprintf (stderr, "put_in_table failed\n");
            CC_IFFREE (tlist, int);
            return 1;
        }
    }

    printf ("Nearest added %d edges (%.2f seconds)\n",
                 tabletotal - current, CCutil_zeit () - szeit);
    fflush (stdout);

    CC_IFFREE (tlist, int);

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int work_nearest (CCkdtree *kt, int ncount, int nearnum,
         CCdatagroup *dat, double *wcoord, int *ecount, int **elist)
#else
static int work_nearest (kt, ncount, nearnum, dat, wcoord, ecount, elist)
CCkdtree *kt;
int ncount, nearnum;
CCdatagroup *dat;
double *wcoord;
int *ecount, **elist;
#endif
{
    if ((dat->norm & CC_NORM_BITS) == CC_KD_NORM_TYPE) {
        if (CCkdtree_k_nearest (kt, ncount, nearnum, dat, wcoord,
                               1, ecount, elist)) {
            fprintf (stderr, "CCkdtree_k-nearest failed\n");
            return 1;
        }
    } else if ((dat->norm & CC_NORM_BITS) == CC_X_NORM_TYPE) {
        if (CCedgegen_x_k_nearest (ncount, nearnum, dat, wcoord, 1, ecount,
                                   elist)) {
            fprintf (stderr, "CCedgegen_x_k_nearest failed\n");
            return 1;
        }
    } else {
        if (CCedgegen_junk_k_nearest (ncount, nearnum, dat, wcoord, 1, ecount,
                                      elist)) {
            fprintf (stderr, "CCedgegen_junk_k_nearest failed\n");
            return 1;
        }
    }
    return 0;
}


#ifdef CC_PROTOTYPE_ANSI
static int call_quadnearest (int ncount, CCdatagroup *dat, double *wcoord,
        int nearnum, CCkdtree *kt)
#else
static int call_quadnearest (ncount, dat, wcoord, nearnum, kt)
int ncount;
CCdatagroup *dat;
double *wcoord;
int nearnum;
CCkdtree *kt;
#endif
{
    double szeit = CCutil_zeit ();
    int current = tabletotal;
    int tcount = 0;
    int *tlist = (int *) NULL;
    int i;

    if (work_quadnearest (kt, ncount, nearnum, dat, wcoord, &tcount, &tlist)) {
        fprintf (stderr, "work_nearest failed\n");
        return 1;
    }

    for (i = 0; i < tcount; i++) {
        if (put_in_table (tlist[2 * i], tlist[(2 * i) + 1])) {
            fprintf (stderr, "put_in_table failed\n");
            CC_IFFREE (tlist, int);
            return 1;
        }
    }

    printf ("Quad Nearest added %d edges (%.2f seconds)\n",
                 tabletotal - current, CCutil_zeit () - szeit);
    fflush (stdout);

    CC_IFFREE (tlist, int);

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int work_quadnearest (CCkdtree *kt, int ncount, int nearnum,
        CCdatagroup *dat, double *wcoord, int *ecount, int **elist)
#else
static int work_quadnearest (kt, ncount, nearnum, dat, wcoord, ecount, elist)
CCkdtree *kt;
int ncount, nearnum;
CCdatagroup *dat;
double *wcoord;
int *ecount, **elist;
#endif
{
    if ((dat->norm & CC_NORM_BITS) == CC_KD_NORM_TYPE) {
        if (CCkdtree_quadrant_k_nearest (kt, ncount, nearnum, dat, wcoord,
                               1, ecount, elist)) {
            fprintf (stderr, "CCkdtree_k-nearest failed\n");
            return 1;
        }
    } else if ((dat->norm & CC_NORM_BITS) == CC_X_NORM_TYPE) {
        if (CCedgegen_x_quadrant_k_nearest (ncount, nearnum, dat, wcoord, 1,
                                  ecount, elist)) {
            fprintf (stderr, "CCedgegen_x_k_nearest failed\n");
            return 1;
        }
    } else {
        printf ("Cannot run quadrant nearest with JUNK norms\n");
        printf ("Trying %d-nearest instead\n", 2 * nearnum);
        fflush (stdout);
        if (CCedgegen_junk_k_nearest (ncount, 2 * nearnum, dat, wcoord, 1,
                            ecount, elist)) {
            fprintf (stderr, "CCedgegen_junk_k_nearest failed\n");
            return 1;
        }
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int call_random_tour (int ncount, CCdatagroup *dat, int number)
#else
static int call_random_tour (ncount, dat, number)
int ncount;
CCdatagroup *dat;
int number;
#endif
{
    double szeit = CCutil_zeit ();
    int current = tabletotal;
    int round;
    int *tour = (int *) NULL;
    double tzeit, val;
    int k;

    printf ("Generate %d Random Tours\n", number);
    fflush (stdout);

    tour = CC_SAFE_MALLOC (ncount, int);
    if (!tour)
        return 1;

    for (round = 0; round < number; round++) {
        k = tabletotal;
        tzeit = CCutil_zeit ();
        randcycle (ncount, tour, dat, &val);
        if (put_tour_in_table (ncount, tour)) {
            fprintf (stderr, "put_tour_in_table failed\n");
            CC_FREE (tour, int);
            return 1;
        }
        printf ("  Random tour %d: %.0f, added %d edges (%.2f seconds)\n",
                 round, val, tabletotal - k, CCutil_zeit () - tzeit);
        fflush (stdout);
    }

    printf ("  TOTAL: Random tours added %d edges (%.2f seconds)\n",
                 tabletotal - current, CCutil_zeit () - szeit);
    fflush (stdout);

    CC_IFFREE (tour, int);
    return 0;
}


#ifdef CC_PROTOTYPE_ANSI
static int call_nearest_tour (int ncount, CCdatagroup *dat, int number,
        CCkdtree *kt)
#else
static int call_nearest_tour (ncount, dat, number, kt)
int ncount;
CCdatagroup *dat;
int number;
CCkdtree *kt;
#endif
{
    double szeit = CCutil_zeit ();
    int current = tabletotal;
    int round;
    int *tour = (int *) NULL;
    double tzeit, val;
    int k;

    printf ("Generate %d Nearest Neighbor Tours\n", number);
    fflush (stdout);

    tour = CC_SAFE_MALLOC (ncount, int);
    if (!tour)
        return 1;

    for (round = 0; round < number; round++) {
        k = tabletotal;
        tzeit = CCutil_zeit ();
        if (work_nearest_tour (kt, ncount, CCutil_lprand () % ncount,
                                        dat, tour, &val)) {
            fprintf (stderr, "work_nearest_tour failed\n");
            CC_FREE (tour, int);
            return 1;
        }
        if (put_tour_in_table (ncount, tour)) {
            fprintf (stderr, "put_tour_in_table failed\n");
            CC_FREE (tour, int);
            return 1;
        }
        printf ("  NN tour %d: %.0f, added %d edges (%.2f seconds)\n",
                 round, val, tabletotal - k, CCutil_zeit () - tzeit);
        fflush (stdout);
    }

    printf ("  TOTAL: Nearest tours added %d edges (%.2f seconds)\n",
                 tabletotal - current, CCutil_zeit () - szeit);
    fflush (stdout);

    CC_IFFREE (tour, int);
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int work_nearest_tour (CCkdtree *kt, int ncount, int start,
        CCdatagroup *dat, int *tour, double *val)
#else
static int work_nearest_tour (kt, ncount, start, dat, tour, val)
CCkdtree *kt;
int ncount, start;
CCdatagroup *dat;
int *tour;
double *val;
#endif
{
    if ((dat->norm & CC_NORM_BITS) == CC_KD_NORM_TYPE) {
        if (CCkdtree_nearest_neighbor_tour (kt, ncount, start, dat, tour, val)) {
            fprintf (stderr, "CCkdtree_nearest_neighbor_tour failed\n");
            return 1;
        }
    } else if ((dat->norm & CC_NORM_BITS) == CC_X_NORM_TYPE) {
        if (CCedgegen_x_nearest_neighbor_tour (ncount, start, dat, tour, val)) {
            fprintf (stderr, "CCedgegen_x_nearest_neighbor_tour failed\n");
            return 1;
        }
    } else {
        if (CCedgegen_junk_nearest_neighbor_tour (ncount, start, dat, tour,
                                                  val)) {
            fprintf (stderr, "CCedgegen_junk_nearest_neighbor_tour failed\n");
            return 1;
        }
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int call_greedy_tour (int ncount, CCdatagroup *dat, CCkdtree *kt)
#else
static int call_greedy_tour (ncount, dat, kt)
int ncount;
CCdatagroup *dat;
CCkdtree *kt;
#endif
{
    double szeit = CCutil_zeit ();
    int current = tabletotal;
    int *tour = (int *) NULL;
    double val;

    tour = CC_SAFE_MALLOC (ncount, int);
    if (!tour)
        return 1;

    if ((dat->norm & CC_NORM_BITS) == CC_KD_NORM_TYPE) {
        if (CCkdtree_greedy_tour (kt, ncount, dat, tour, &val)) {
            fprintf (stderr, "CCkdtree_greedy_tour failed\n");
            CC_FREE (tour, int);
            return 1;
        }
        if (put_tour_in_table (ncount, tour)) {
            fprintf (stderr, "put_tour_in_table failed\n");
            CC_FREE (tour, int);
            return 1;
        }
        printf ("Greedy tour: %.0f, added %d edges (%.2f seconds)\n",
                     val, tabletotal - current, CCutil_zeit () - szeit);
        fflush (stdout);
    } else if ((dat->norm & CC_NORM_BITS) == CC_X_NORM_TYPE) {
        printf ("No X_NORM greedy tours, using nearest neighbor\n");
        CC_FREE (tour, int);
        return call_nearest_tour (ncount, dat, 1, kt);
    } else {
        printf ("No JUNK_NORM greedy tours, using nearest neighbor\n");
        CC_FREE (tour, int);
        return call_nearest_tour (ncount, dat, 1, kt);
    }

    CC_IFFREE (tour, int);
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int call_twoopt_tour (int ncount, CCdatagroup *dat, CCkdtree *kt,
        int number, int two_and_a_half, int use_3opt)
#else
static int call_twoopt_tour (ncount, dat, kt, number, two_and_a_half,
        use_3opt)
int ncount;
CCdatagroup *dat;
CCkdtree *kt;
int number;
int two_and_a_half;
int use_3opt;
#endif
{
    double szeit = CCutil_zeit ();
    double ival, val, tzeit;
    int k, round, current = tabletotal;
    int *tour1 = (int *) NULL, *tour2 = (int *) NULL;

    if (use_3opt)
        printf ("Generate %d 3OPT Tours from Nearest Neighbor\n", number);
    else if (two_and_a_half)
        printf ("Generate %d 2.5OPT Tours from Nearest Neighbor\n", number);
    else
        printf ("Generate %d 2OPT Tours from Nearest Neighbor\n", number);
    fflush (stdout);

    tour1 = CC_SAFE_MALLOC (ncount, int);
    if (!tour1)
        return 1;
    tour2 = CC_SAFE_MALLOC (ncount, int);
    if (!tour2) {
        CC_FREE (tour1, int);
        return 1;
    }

    if ((dat->norm & CC_NORM_BITS) == CC_KD_NORM_TYPE) {
        for (round = 0; round < number; round++) {
            k = tabletotal;
            tzeit = CCutil_zeit ();
            if (work_nearest_tour (kt, ncount, CCutil_lprand () % ncount,
                                        dat, tour1, &val)) {
                fprintf (stderr, "work_nearest_tour failed\n");
                CC_FREE (tour1, int);
                CC_FREE (tour2, int);
                return 1;
            }
            ival = val;
            if (use_3opt) {
                if (CCkdtree_3opt_tour (kt, ncount, dat, tour1, tour2, &val,
                                      1)) {
                    fprintf (stderr, "CCkdtree_3opt_tour failed\n");
                    CC_FREE (tour1, int);
                    CC_FREE (tour2, int);
                    return 1;
                }

            } else {
                if (CCkdtree_twoopt_tour (kt, ncount, dat, tour1, tour2, &val,
                                        two_and_a_half, 1)) {
                    fprintf (stderr, "CCkdtree_twoopt_tour failed\n");
                    CC_FREE (tour1, int);
                    CC_FREE (tour2, int);
                    return 1;
                }
            }
            if (put_tour_in_table (ncount, tour2)) {
                fprintf (stderr, "put_tour_in_table failed\n");
                CC_FREE (tour1, int);
                CC_FREE (tour2, int);
                return 1;
            }
            if (use_3opt)
                printf ("  3OPT tour %d (from %.0f): %.0f, added %d edges (%.2f sec)\n",
                 round, ival, val, tabletotal - k, CCutil_zeit () - tzeit);
            else if (two_and_a_half)
                printf ("  2.5OPT tour %d (from %.0f): %.0f, added %d edges (%.2f sec)\n",
                 round, ival, val, tabletotal - k, CCutil_zeit () - tzeit);
            else
                printf ("  2OPT tour %d (from %.0f): %.0f, added %d edges (%.2f sec)\n",
                 round, ival, val, tabletotal - k, CCutil_zeit () - tzeit);
            fflush (stdout);
        }
    } else if ((dat->norm & CC_NORM_BITS) == CC_X_NORM_TYPE) {
        if (use_3opt)
            printf ("No X_NORM three-opt, using nearest neighbor\n");
        else
            printf ("No X_NORM two-opt, using nearest neighbor\n");
        fflush (stdout);
        CC_FREE (tour1, int);
        CC_FREE (tour2, int);
        return call_nearest_tour (ncount, dat, number, kt);
    } else {
        if (use_3opt)
            printf ("No JUNK_NORM three-opt, using nearest neighbor\n");
        else
            printf ("No JUNK_NORM two-opt, using nearest neighbor\n");
        fflush (stdout);
        CC_FREE (tour1, int);
        CC_FREE (tour2, int);
        return call_nearest_tour (ncount, dat, number, kt);
    }

    if (use_3opt)
        printf ("  TOTAL: 3-opt tours added %d edges (%.2f seconds)\n",
                     tabletotal - current, CCutil_zeit () - szeit);
    else if (two_and_a_half)
        printf ("  TOTAL: 2.5-opt tours added %d edges (%.2f seconds)\n",
                    tabletotal - current, CCutil_zeit () - szeit);
    else
        printf ("  TOTAL: 2-opt tours added %d edges (%.2f seconds)\n",
                     tabletotal - current, CCutil_zeit () - szeit);
    fflush (stdout);

    CC_IFFREE (tour1, int);
    CC_IFFREE (tour2, int);

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int call_linkern (int ncount, CCdatagroup *dat, CCkdtree *kt,
        CCedgegengroup *plan)
#else
static int call_linkern (ncount, dat, kt, plan)
int ncount;
CCdatagroup *dat;
CCkdtree *kt;
CCedgegengroup *plan;
#endif
{
    int *tour = (int *) NULL, *gtour = (int *) NULL, *itour = (int *) NULL;
    double val, gval, ival;
    double szeit = CCutil_zeit ();
    double tzeit;
    int i, k, round;
    int current = tabletotal;
    int ecount = 0, *elist = (int *) NULL;
    int rval = 0;

    printf ("Generate %d Linkern Tours (", plan->linkern.count);
    if (plan->linkern.greedy_start)
        printf ("Greedy, ");
    else if (plan->linkern.random_start)
        printf ("Random, ");
    else
        printf ("Nneigh, ");
    printf ("%d kicks, ", plan->linkern.nkicks);
    if (plan->linkern.nearest == 0) {
        printf ("Quad-%d Edgeset)\n", (plan->linkern.quadnearest ?
                               plan->linkern.quadnearest : 3));
    } else {
        if (plan->linkern.quadnearest == 0) {
            printf ("Near-%d Edgeset)\n", plan->linkern.nearest);
        } else {
            printf ("Quad-%d + Near-%d Edgeset)\n",
                plan->linkern.quadnearest, plan->linkern.nearest);
        }
    }

    /* Build an initial edgeset */

    if (plan->linkern.nearest == 0 && plan->linkern.quadnearest == 0) {
        if (work_quadnearest (kt, ncount, 3, dat, (double *) NULL,
                              &ecount, &elist)) {
            fprintf (stderr, "work_quadnearest failed\n");
            return 1;
        }
    } else {
        if (plan->linkern.nearest == 0) {
            if (work_quadnearest (kt, ncount, plan->linkern.quadnearest,
                                  dat, (double *) NULL, &ecount, &elist)) {
                fprintf (stderr, "work_quadnearest failed\n");
                return 1;
            }
        } else if (plan->linkern.quadnearest == 0) {
            if (work_nearest (kt, ncount, plan->linkern.nearest,
                              dat, (double *) NULL, &ecount, &elist)) {
                fprintf (stderr, "work_nearest failed\n");
                return 1;
            }
        } else {
            intptr **tab = (intptr **) NULL;
            int tcount, *tlist = (int *) NULL;
            int j, added;
            intptr *ip, *ipnext;

            tab = CC_SAFE_MALLOC (ncount, intptr *);
            if (!tab)
                return 1;
            for (i = 0; i < ncount; i++)
                tab[i] = (intptr *) NULL;
            ecount = 0;

            if (work_quadnearest (kt, ncount, plan->linkern.quadnearest,
                                  dat, (double *) NULL, &tcount, &tlist)) {
                fprintf (stderr, "work_quadnearest failed\n");
                return 1;
            }
            for (i = 0; i < tcount; i++) {
                if (general_put_in_table (tlist[2 * i], tlist[(2 * i) + 1],
                                          &added, tab)) {
                    fprintf (stderr, "general_put_in_table failed\n");
                    CC_FREE (tab, intptr *);
                    return 1;
                }
                ecount += added;
            }
            CC_IFFREE (tlist, int);

            if (work_nearest (kt, ncount, plan->linkern.nearest,
                                  dat, (double *) NULL, &tcount, &tlist)) {
                fprintf (stderr, "work_quadnearest failed\n");
                return 1;
            }
            for (i = 0; i < tcount; i++) {
                if (general_put_in_table (tlist[2 * i], tlist[(2 * i) + 1],
                                          &added, tab)) {
                    fprintf (stderr, "general_put_in_table failed\n");
                    CC_FREE (tab, intptr *);
                    return 1;
                }
                ecount += added;
            }
            CC_IFFREE (tlist, int);

            elist = CC_SAFE_MALLOC (2 * ecount, int);
            if (!elist) {
                CC_FREE (tab, intptr *);
                return 1;
            }
            for (j = 0, i = 0; i < ncount; i++) {
                for (ip = tab[i]; ip; ip = ipnext) {
                    ipnext =  ip->next;
                    elist[j++] = i;
                    elist[j++] = ip->this;
                    intptrfree (ip);
                }
                tab[i] = (intptr *) NULL;
            }
            CC_FREE (tab, intptr *);
        }
    }
    printf ("Initial Edgeset: %d\n", ecount);
    fflush (stdout);

    if (plan->linkern.greedy_start &&
       ((dat->norm & CC_NORM_BITS) == CC_KD_NORM_TYPE)) {
        gtour = CC_SAFE_MALLOC (ncount, int);
        if (!gtour) {
            rval = 1;
            goto CLEANUP;
        }
        tzeit = CCutil_zeit ();
        if (CCkdtree_greedy_tour (kt, ncount, dat, gtour, &gval)) {
            fprintf (stderr, "CCkdtree_greedy_tour failed\n");
            rval = 1;
            goto CLEANUP;
        }
        printf ("Greedy tour: %.0f (%.2f seconds)\n",
                     gval, CCutil_zeit () - tzeit);
        fflush (stdout);
    }

    tour = CC_SAFE_MALLOC (ncount, int);
    if (!tour) {
        rval = 1;
        goto CLEANUP;
    }
    itour = CC_SAFE_MALLOC (ncount, int);
    if (!itour) {
        rval = 1;
        goto CLEANUP;
    }

    for (round = 0; round < plan->linkern.count; round++) {
        tzeit = CCutil_zeit ();
        k = tabletotal;
        if (gtour != (int *) NULL) {
            for (i = 0; i < ncount; i++)
                itour[i] = gtour[i];
            val = gval;
            ival = gval;
        } else if (plan->linkern.random_start) {
            randcycle (ncount, itour, dat, &val);
            ival = val;
        } else {
            if (work_nearest_tour (kt, ncount, CCutil_lprand () % ncount,
                                        dat, itour, &val)) {
                fprintf (stderr, "work_nearest_tour failed\n");
                rval = 1;
                goto CLEANUP;
            }
            ival = val;
        }

        if (CClinkern_tour (ncount, dat, ecount, elist, 100000000,
             plan->linkern.nkicks, itour, tour, &val, 1, -1.0, -1.0,
            (char *) NULL)) {
            fprintf (stderr, "CClinkern_tour failed\n");
            rval = 1;
            goto CLEANUP;
        }

        if (put_tour_in_table (ncount, tour)) {
            fprintf (stderr, "put_tour_in_table failed\n");
            rval = 1;
            goto CLEANUP;
        }
        printf ("  LK tour %d (from %.0f): %.0f, added %d edges (%.2f sec)\n",
                 round, ival, val, tabletotal - k, CCutil_zeit () - tzeit);
        fflush (stdout);
    }

    printf ("  TOTAL: Linkern tours added %d edges (%.2f seconds)\n",
                 tabletotal - current, CCutil_zeit () - szeit);
    fflush (stdout);

CLEANUP:

    CC_IFFREE (tour, int);
    CC_IFFREE (itour, int);
    CC_IFFREE (gtour, int);
    CC_IFFREE (elist, int);

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static int call_f2match (int ncount, CCdatagroup *dat, CCkdtree *kt,
        int priceit, int basic)
#else
static int call_f2match (ncount, dat, kt, priceit, basic)
int ncount;
CCdatagroup *dat;
CCkdtree *kt;
int priceit, basic;
#endif
{
    int *mat = (int *) NULL;
    int ecount;
    int *elist = (int *) NULL;
    int *elen = (int *) NULL;
    int i;
    double val;

    if (f2match_initial_edgeset (ncount, dat, kt, &ecount, &elist, &elen)) {
        fprintf (stderr, "f2match_initial_edgeset failed\n");
        return 1;
    }

    mat = CC_SAFE_MALLOC((6 * ncount) + 1, int);
    if (!mat) {
        CC_FREE (elist, int);
        CC_FREE (elen, int);
        return 1;
    }

    if (priceit)
        i = CCfmatch_fractional_2match (ncount, ecount, elist, elen, dat, &val,
                    mat, (int *) NULL, (int *) NULL, basic);
    else
        i = CCfmatch_fractional_2match (ncount, ecount, elist, elen,
                   (CCdatagroup *) NULL, &val, mat, (int *) NULL,
                   (int *) NULL, basic);
    if (i) {
        fprintf (stderr, "CCfmatch_fractional_2match failed\n");
        CC_FREE (mat, int);
        CC_FREE (elist, int);
        CC_FREE (elen, int);
        return 1;
    }

    i = 0;
    while (mat[i] != -1) {
        if (put_in_table (mat[i], mat[i + 1])) {
            fprintf (stderr, "put_in_table failed\n");
            CC_FREE (mat, int);
            CC_FREE (elist, int);
            CC_FREE (elen, int);
            return 1;
        }
        i += 3;
    }

    CC_IFFREE (mat, int);
    CC_IFFREE (elist, int);
    CC_IFFREE (elen, int);

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int call_f2match_nearest (int ncount, CCdatagroup *dat, CCkdtree *kt,
        int number, int priceit, int basic)
#else
static int call_f2match_nearest (ncount, dat, kt, number, priceit, basic)
int ncount;
CCdatagroup *dat;
CCkdtree *kt;
int number, priceit, basic;
#endif
{
    int ecount;
    int *elist = (int *) NULL;
    int *elen = (int *) NULL;
    int *dual = (int *) NULL;
    int dualmax, i;
    double *dcoord = (double *) NULL;
    double val;
    int rval = 0;
    int current = tabletotal;
    double szeit = CCutil_zeit ();

    if (f2match_initial_edgeset (ncount, dat, kt, &ecount, &elist, &elen)) {
        fprintf (stderr, "f2match_initial_edgeset failed\n");
        return 1;
    }

    dual = CC_SAFE_MALLOC (ncount, int);
    if (!dual) {
        rval = 1;
        goto CLEANUP;
    }

    if (priceit)
        i = CCfmatch_fractional_2match (ncount, ecount, elist, elen, dat, &val,
                    (int *) NULL, dual, (int *) NULL, basic);
    else
        i = CCfmatch_fractional_2match (ncount, ecount, elist, elen,
                    (CCdatagroup *) NULL, &val, (int *) NULL, dual,
                    (int *) NULL, basic);
    if (i) {
        fprintf (stderr, "CCfmatch_fractional_2match failed\n");
        rval = 1;
        goto CLEANUP;
    }
    CC_FREE (elist, int);
    CC_FREE (elen, int);
    ecount = 0;

    dualmax = dual[0];
    for (i = 1; i < ncount; i++) {
        if (dual[i] > dualmax)
            dualmax = dual[i];
    }

    dcoord = CC_SAFE_MALLOC (ncount, double);
    if (!dcoord) {
        rval = 1;
        goto CLEANUP;
    }
    for (i = 0; i < ncount; i++)
        dcoord[i] = (dualmax - dual[i]) * 0.5;
    CC_FREE (dual, int);

    if (work_nearest (kt, ncount, number, dat, dcoord, &ecount, &elist)) {
        fprintf (stderr, "work_nearest failed\n");
        rval = 1;
        goto CLEANUP;
    }
    for (i = 0; i < ecount; i++) {
        if (put_in_table (elist[2 * i], elist[(2 * i) + 1])) {
            fprintf (stderr, "put_in_table failed\n");
            rval = 1;
            goto CLEANUP;
        }
    }
    printf ("Fractional 2-match Nearest-%d added %d edges (%.2f seconds)\n",
                 number, tabletotal - current, CCutil_zeit () - szeit);
    fflush (stdout);


CLEANUP:

    CC_IFFREE (elist, int);
    CC_IFFREE (elen, int);
    CC_IFFREE (dual, int);
    CC_IFFREE (dcoord, double);

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static int f2match_initial_edgeset (int ncount, CCdatagroup *dat, CCkdtree *kt,
        int *ecount, int **elist, int **elen)
#else
static int f2match_initial_edgeset (ncount, dat, kt, ecount, elist, elen)
int ncount;
CCdatagroup *dat;
CCkdtree *kt;
int *ecount;
int **elist, **elen;
#endif
{
    intptr **tab = (intptr **) NULL;
    int tcount, *tlist = (int *) NULL;
    int *ttour = (int *) NULL;
    int i, j, added;
    intptr *ip, *ipnext;
    double tval;
    int count;

    *ecount = 0;
    *elist = (int *) NULL;
    *elen = (int *) NULL;

    tab = CC_SAFE_MALLOC (ncount, intptr *);
    if (!tab)
        return 1;
    for (i = 0; i < ncount; i++)
        tab[i] = (intptr *) NULL;
    count = 0;

    if (work_quadnearest (kt, ncount, 3, dat, (double *) NULL, &tcount,
                          &tlist)) {
        fprintf (stderr, "work_quadnearest failed\n");
        CC_FREE (tab, intptr *);
        return 1;
    }
    for (i = 0; i < tcount; i++) {
        if (general_put_in_table (tlist[2 * i], tlist[(2 * i) + 1],
                                  &added, tab)) {
            fprintf (stderr, "general_put_in_table failed\n");
            CC_FREE (tab, intptr *);
            return 1;
        }
        count += added;
    }
    CC_IFFREE (tlist, int);

    ttour = CC_SAFE_MALLOC (ncount, int);
    if (!ttour) {
        CC_FREE (tab, intptr *);
        return 1;
    }
    if (work_nearest_tour (kt, ncount, CCutil_lprand () % ncount, dat, ttour,
                           &tval)) {
        fprintf (stderr, "work_nearest_tour failed\n");
        CC_FREE (ttour, int);
        return 1;
    }
    for (i = 1; i < ncount; i++) {
        if (general_put_in_table (ttour[i-1], ttour[i], &added, tab)) {
            fprintf (stderr, "general_put_in_table failed\n");
            CC_FREE (tab, intptr *);
            CC_FREE (ttour, int);
            return 1;
        }
        count += added;
    }
    if (general_put_in_table (ttour[ncount - 1], ttour[0], &added, tab)) {
        fprintf (stderr, "general_put_in_table failed\n");
        CC_FREE (tab, intptr *);
        CC_FREE (ttour, int);
        return 1;
    }
    count += added;
    CC_FREE (ttour, int);

    *elist = CC_SAFE_MALLOC (2 * count, int);
    if (!elist) {
        CC_FREE (tab, intptr *);
        return 1;
    }
    *elen = CC_SAFE_MALLOC (count, int);
    if (!elen) {
        CC_FREE (tab, intptr *);
        CC_FREE (*elist, int);
    }
    *ecount = count;
    for (j = 0, i = 0; i < ncount; i++) {
        for (ip = tab[i]; ip; ip = ipnext) {
            ipnext =  ip->next;
            (*elist)[2 * j] = i;
            (*elist)[(2 * j) + 1] = ip->this;
            (*elen)[j++] = CCutil_dat_edgelen (i, ip->this, dat);
            intptrfree (ip);
        }
        tab[i] = (intptr *) NULL;
    }
    CC_FREE (tab, intptr *);

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int call_spanning_tree (int ncount, CCdatagroup *dat, double *wcoord,
        CCkdtree *kt)
#else
static int call_spanning_tree (ncount, dat, wcoord, kt)
int ncount;
CCdatagroup *dat;
double *wcoord;
CCkdtree *kt;
#endif
{
    double szeit = CCutil_zeit ();
    int current = tabletotal;
    int *tree = (int *) NULL;
    int i;
    double val;

    tree = CC_SAFE_MALLOC ((2 * ncount) - 2, int);
    if (!tree)
        return 1;

    if ((dat->norm & CC_NORM_BITS) == CC_KD_NORM_TYPE) {
        if (CCkdtree_prim_spanningtree (kt, ncount, dat, wcoord, tree, &val)) {
            fprintf (stderr, "CCkdtree_prim_spanningtree failed\n");
            CC_FREE (tree, int);
            return 1;
        }
    } else if ((dat->norm & CC_NORM_BITS) == CC_X_NORM_TYPE) {
        printf ("No X_NORM spanning tree\n");
        CC_FREE (tree, int);
        return 0;
    } else {
        printf ("No JUNK_NORM spanning tree\n");
        CC_FREE (tree, int);
        return 0;
    }

    for (i = 0; i < (ncount - 1); i++) {
        if (put_in_table (tree[2 * i], tree[(2 * i) + 1])) {
            fprintf (stderr, "put_in_table failed\n");
            CC_FREE (tree, int);
            return 0;
        }
    }
    printf ("Spanning tree: %.0f, added %d edges (%.2f seconds)\n",
             val, tabletotal - current, CCutil_zeit () - szeit);

    CC_IFFREE (tree, int);

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int call_nearest_twomatch (int ncount, CCdatagroup *dat, int number,
        CCkdtree *kt)
#else
static int call_nearest_twomatch (ncount, dat, number, kt)
int ncount;
CCdatagroup *dat;
int number;
CCkdtree *kt;
#endif
{
    double szeit = CCutil_zeit ();
    int current = tabletotal;
    int round;
    int *mat = (int *) NULL;
    double tzeit, val;
    int i, k;

    printf ("Generate %d Nearest Neighbor 2-matchings\n", number);
    fflush (stdout);

    mat = CC_SAFE_MALLOC (2 * ncount, int);
    if (!mat)
        return 1;

    if ((dat->norm & CC_NORM_BITS) == CC_KD_NORM_TYPE) {
        for (round = 0; round < number; round++) {
            k = tabletotal;
            tzeit = CCutil_zeit ();
            if (CCkdtree_nearest_neighbor_2match (kt, ncount,
                            CCutil_lprand () % ncount, dat, mat, &val)) {
                fprintf (stderr, "CCkdtree_nearest_neighbor_2match failed\n");
                CC_FREE (mat, int);
                return 1;
            }
            for (i = 0; i < ncount; i++) {
                if (put_in_table (mat[2 * i], mat[(2 * i) + 1])) {
                    fprintf (stderr, "put_in_table failed\n");
                    CC_FREE (mat, int);
                    return 1;
                }
            }
            printf ("  NN 2-mat %d: %.0f, added %d edges (%.2f seconds)\n",
                     round, val, tabletotal - k, CCutil_zeit () - tzeit);
            fflush (stdout);
        }
    } else if ((dat->norm & CC_NORM_BITS) == CC_X_NORM_TYPE) {
        printf ("No X_NORM NN-2match, using NN-tour instead\n");
        fflush (stdout);
        CC_FREE (mat, int);
        return call_nearest_tour (ncount, dat, number, kt);
    } else {
        printf ("No JUNK_NORM NN-2match, using NN-tour instead\n");
        fflush (stdout);
        CC_FREE (mat, int);
        return call_nearest_tour (ncount, dat, number, kt);
    }

    printf ("  TOTAL: Nearest 2-matchings added %d edges (%.2f seconds)\n",
                 tabletotal - current, CCutil_zeit () - szeit);
    fflush (stdout);

    CC_IFFREE (mat, int);
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int put_tour_in_table (int ncount, int *tour)
#else
static int put_tour_in_table (ncount, tour)
int ncount;
int *tour;
#endif
{
    int i;

    for (i = 1; i < ncount; i++) {
        if (put_in_table (tour[i-1], tour[i])) {
            fprintf (stderr, "put_in_table failed\n");
            return 1;
        }
    }
    if (put_in_table (tour[ncount - 1], tour[0])) {
        fprintf (stderr, "put_in_table failed\n");
        return 1;
    }

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int put_in_table (int i, int j)
#else
static int put_in_table (i, j)
int i, j;
#endif
{
    intptr *ip;

    if (j < i) {
        int temp;
        SWAP(i, j, temp);
    }

    for (ip = table[i]; ip; ip = ip->next) {
        if (ip->this == j) {
            return 0;
        }
    }
    ip = intptralloc ();
    if (!ip) {
        return 1;
    }
    ip->this = j;
    ip->next = table[i];
    table[i] = ip;
    tabletotal++;
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int general_put_in_table (int i, int j, int *added, intptr **tab)
#else
static int general_put_in_table (i, j, added, tab)
int i, j;
int *added;
intptr **tab;
#endif
{
    intptr *ip;

    if (j < i) {
        int temp;
        SWAP(i, j, temp);
    }

    for (ip = tab[i]; ip; ip = ip->next) {
        if (ip->this == j) {
            *added = 0;
            return 0;
        }
    }
    ip = intptralloc ();
    if (!ip) {
        *added = 0;
        return 1;
    }
    ip->this = j;
    ip->next = tab[i];
    tab[i] = ip;
    *added = 1;
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static void randcycle (int ncount, int *cyc, CCdatagroup *dat, double *val)
#else
static void randcycle (ncount, cyc, dat, val)
int ncount;
int *cyc;
CCdatagroup *dat;
double *val;
#endif
{
    int i, k, temp;

    for (i = 0; i < ncount; i++)
        cyc[i] = i;

    for (i = ncount; i > 1; i--) {
        k = CCutil_lprand () % i;
        SWAP (cyc[i - 1], cyc[k], temp);
    }

    *val = CCutil_dat_edgelen (cyc[ncount - 1], cyc[0], dat);
    for (i = 1; i < ncount; i++)
        (*val) += CCutil_dat_edgelen (cyc[i - 1], cyc[i], dat);
}


#ifdef CC_PROTOTYPE_ANSI
int CCedgegen_read (char *egname, CCedgegengroup *plan)
#else
int CCedgegen_read (egname, plan)
char *egname;
CCedgegengroup *plan;
#endif
{
    char buf[256];
    char area[256];
    char key[256];
    char field[256];
    char *p;
    FILE *in;

    CCedgegen_init_edgegengroup (plan);

    in = fopen (egname, "r");
    if (!in) {
        perror (egname);
        fprintf (stderr, "can't open %s for input\n", egname);
        return 1;
    }

    while (fgets (buf, 254, in) != (char *) NULL) {
        p = buf;
        while (*p != '\0') {
            if (*p == ':')
                *p = ' ';
             p++;
        }
        p = buf;
        if (sscanf (p, "%s", area) != EOF) {
            p += strlen (area);
            while (*p == ' ')
                p++;
            if (!strcmp (area, "EDGEGEN")) {
                if (sscanf (p, "%s", key) == EOF) {
                    fprintf (stderr, "ERROR in EDGEGEN LINE - no keyword\n");
                    return 1;
                }
                if (!strcmp (key, "NEAREST")) {
                    p += strlen (key);
                    while (*p == ' ')
                        p++;
                    if (sscanf (p, "%s", field) != EOF) {
                        plan->nearest = atoi (field);
                    } else {
                        printf ("NEAREST count not given, using 1\n");
                        plan->nearest = 1;
                    }
                } else if (!strcmp (key, "QUADNEAREST")) {
                    p += strlen (key);
                    while (*p == ' ')
                        p++;
                    if (sscanf (p, "%s", field) != EOF) {
                        plan->quadnearest = atoi (field);
                    } else {
                        printf ("QUADNEAREST count not given, using 1\n");
                        plan->quadnearest = 1;
                    }
                } else if (!strcmp (key, "TREE")) {
                    plan->want_tree = 1;
                } else if (!strcmp (key, "NN_TWOMATCH")) {
                    p += strlen (key);
                    while (*p == ' ')
                        p++;
                    if (sscanf (p, "%s", field) != EOF) {
                        plan->nearest_twomatch_count = atoi (field);
                    } else {
                        printf ("NN_TWOMATCH count not given, using 1\n");
                        plan->nearest_twomatch_count = 1;
                    }
                } else if (!strcmp (key, "GREEDY_TOUR")) {
                    plan->tour.greedy = 1;
                } else if (!strcmp (key, "NN_TOUR")) {
                    p += strlen (key);
                    while (*p == ' ')
                        p++;
                    if (sscanf (p, "%s", field) != EOF) {
                        plan->tour.nearest_count = atoi (field);
                    } else {
                        printf ("NN_TOUR count not given, using 1\n");
                        plan->tour.nearest_count = 1;
                    }
                } else if (!strcmp (key, "RANDOM_TOUR")) {
                    p += strlen (key);
                    while (*p == ' ')
                        p++;
                    if (sscanf (p, "%s", field) != EOF) {
                        plan->tour.random_count = atoi (field);
                    } else {
                        printf ("RANDOM_TOUR count not given, using 1\n");
                        plan->tour.random_count = 1;
                    }
                } else if (!strcmp (key, "TWOOPT_TOUR")) {
                    p += strlen (key);
                    while (*p == ' ')
                        p++;
                    if (sscanf (p, "%s", field) != EOF) {
                        plan->tour.twoopt_count = atoi (field);
                    } else {
                        printf ("TWOOPT_TOUR count not given, using 1\n");
                        plan->tour.twoopt_count = 1;
                    }
                } else if (!strcmp (key, "TWOOPT5_TOUR")) {
                    p += strlen (key);
                    while (*p == ' ')
                        p++;
                    if (sscanf (p, "%s", field) != EOF) {
                        plan->tour.twoopt5_count = atoi (field);
                    } else {
                        printf ("TWOOPT5_TOUR count not given, using 1\n");
                        plan->tour.twoopt5_count = 1;
                    }
                } else if (!strcmp (key, "THREEOPT_TOUR")) {
                    p += strlen (key);
                    while (*p == ' ')
                        p++;
                    if (sscanf (p, "%s", field) != EOF) {
                        plan->tour.threeopt_count = atoi (field);
                    } else {
                        printf ("THREEOPT_TOUR count not given, using 1\n");
                        plan->tour.threeopt_count = 1;
                    }
                } else if (!strcmp (key, "FRAC_TWOMATCH")) {
                    plan->f2match.wantit = 1;
                    p += strlen (key);
                    while (*p == ' ')
                        p++;
                    while (sscanf (p, "%s", field) != EOF) {
                        if (!strcmp (field, "BASIC"))
                            plan->f2match.basic = 1;
                        else if (!strcmp (field, "PRICED"))
                            plan->f2match.priced = 1;
                        else
                            printf ("Unknown option in FRAC_TWOMATCH\n");
                        p += strlen (field);
                        while (*p == ' ')
                            p++;
                    }
                } else if (!strcmp (key, "FRAC_TWOMATCH_NEAREST")) {
                    p += strlen (key);
                    while (*p == ' ')
                        p++;
                    while (sscanf (p, "%s", field) != EOF) {
                        if (!strcmp (field, "BASIC"))
                            plan->f2match_nearest.basic = 1;
                        else if (!strcmp (field, "PRICED"))
                            plan->f2match_nearest.priced = 1;
                        else
                            plan->f2match_nearest.number = atoi (field);
                        p += strlen (field);
                        while (*p == ' ')
                            p++;
                    }
                    if (plan->f2match_nearest.number == 0) {
                        printf ("FRAC_TWOMATCH_NEAREST count not given, using 1\n");
                        plan->f2match_nearest.number = 1;
                    }
                } else if (!strcmp (key, "LINKERN")) {
                    p += strlen (key);
                    while (*p == ' ')
                        p++;
                    if (sscanf (p, "%s", field) != EOF) {
                        plan->linkern.count = atoi (field);
                        p += strlen (field);
                        while (*p == ' ')
                            p++;
                    } else {
                        printf ("LINKERN count not given, using 1\n");
                        plan->linkern.count = 1;
                    }
                    if (sscanf (p, "%s", field) != EOF) {
                        plan->linkern.nkicks = atoi (field);
                        p += strlen (field);
                        while (*p == ' ')
                            p++;
                    } else {
                        printf ("LINKERN nkicks not given, using 10\n");
                        plan->linkern.nkicks = 10;
                    }
                    while (sscanf (p, "%s", field) != EOF) {
                        if (!strcmp (field, "GREEDY_START"))
                            plan->linkern.greedy_start = 1;
                        else if (!strcmp (field, "RANDOM_START"))
                            plan->linkern.random_start = 1;
                        else if (!strcmp (field, "NN_START"))
                            plan->linkern.nearest_start = 1;
                        else if (!strcmp (field, "NEAREST")) {
                            p += strlen (field);
                            while (*p == ' ')
                                p++;
                            if (sscanf (p, "%s", field) != EOF) {
                                plan->linkern.nearest = atoi (field);
                            } else {
                                printf ("LINKERN NEAREST COUNT not given, using 5\n");
                                plan->linkern.nearest = 5;
                                break;
                            }
                        } else if (!strcmp (field, "QUADNEAREST")) {
                            p += strlen (field);
                            while (*p == ' ')
                                p++;
                            if (sscanf (p, "%s", field) != EOF) {
                                plan->linkern.quadnearest = atoi (field);
                            } else {
                                printf ("LINKERN QUADNEAREST COUNT not given, using 3\n");
                                plan->linkern.quadnearest = 3;
                                break;
                            }
                        } else {
                            printf ("Unknown EDGEGEN LINKERN command %s\n",
                                    field);
                            fflush (stdout);
                        }
                        p += strlen (field);
                        while (*p == ' ')
                            p++;
                    }
                } else {
                    printf ("Unknown EDGEGEN command: %s\n", key);
                    fflush (stdout);
                }
            } else {
                printf ("Cannot parse command line: %s\n", area);
                fflush (stdout);
            }
        }
    }
    fclose (in);
    printf ("\n");

    if (plan->linkern.count) {
        if (!plan->linkern.quadnearest && !plan->linkern.nearest)
            plan->linkern.quadnearest = 3;
        if (!plan->linkern.greedy_start && !plan->linkern.random_start)
            plan->linkern.nearest_start = 1;
        if (!plan->linkern.nkicks)
            plan->linkern.nkicks = 10;
    }

    printf ("Edgegen Request:\n");
    if (plan->nearest)
        printf ("  Nearest %d\n", plan->nearest);
    if (plan->quadnearest)
        printf ("  Quad-Nearest %d\n", plan->quadnearest);
    if (plan->f2match_nearest.number) {
        printf ("  Frac 2-match Nearest %d (", plan->f2match_nearest.number);
        if (plan->f2match_nearest.basic)
            printf ("Basic ");
        if (plan->f2match_nearest.priced)
            printf ("Priced)\n");
        else
            printf ("Not Priced)\n");
    }
    if (plan->want_tree)
        printf ("  Minimum Spanning Tree\n");
    if (plan->nearest_twomatch_count)
        printf ("  NN 2-matchings: %d\n", plan->nearest_twomatch_count);
    if (plan->tour.random_count)
        printf ("  Random Tours: %d\n", plan->tour.random_count);
    if (plan->tour.nearest_count)
        printf ("  NN Tours: %d\n", plan->tour.nearest_count);
    if (plan->tour.greedy)
        printf ("  Greedy Tour\n");
    if (plan->tour.twoopt_count)
        printf ("  2OPT Tours: %d\n", plan->tour.twoopt_count);
    if (plan->tour.twoopt5_count)
        printf ("  2.5OPT Tours: %d\n", plan->tour.twoopt5_count);
    if (plan->tour.threeopt_count)
        printf ("  3OPT Tours: %d\n", plan->tour.threeopt_count);
    if (plan->linkern.count) {
        printf ("  LK Tours: %d (", plan->linkern.count);
        if (plan->linkern.greedy_start)
            printf ("Greedy, ");
        else if (plan->linkern.random_start)
            printf ("Random, ");
        else
            printf ("NN, ");
        if (!plan->linkern.nearest) {
            printf ("Quad-%d, ", plan->linkern.quadnearest);
        } else {
            if (!plan->linkern.quadnearest) {
                printf ("Near-%d, ", plan->linkern.nearest);
            } else {
                printf ("Quad-%d + Near-%d, ", plan->linkern.quadnearest,
                                               plan->linkern.nearest);
            }
        }
        printf ("%d Kicks)\n", plan->linkern.nkicks);
    }
    if (plan->f2match.wantit) {
        printf ("  Frac 2-matching (");
        if (plan->f2match.basic)
            printf ("Basic ");
        if (plan->f2match.priced)
            printf ("Priced)\n");
        else
            printf ("Not Priced)\n");
    }
    printf ("\n");
    fflush (stdout);

    return 0;
}
