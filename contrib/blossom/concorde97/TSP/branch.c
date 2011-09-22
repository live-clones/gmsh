/***************************************************************************/
/*                                                                         */
/*               ROUTINES TO BUILD EXECUTE BRANCHING                       */
/*                                                                         */
/*                           TSP CODE                                      */
/*                                                                         */
/*                                                                         */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook                       */
/*  Date: May 22, 1997                                                     */
/*  Modified: June 17, 1997 (bix)                                          */
/*            June 27, 1997 (bico)                                         */
/*                                                                         */
/*                                                                         */
/*  EXPORTED FUNCTIONS:                                                    */
/*                                                                         */
/*     int CCtsp_find_branch (CCtsp_lp *lp, int nwant, int *ngot,          */
/*             CCtsp_branchobj **bobj, double *val, int **tour,            */
/*             int usecliques)                                             */
/*      FINDS a set of branching edges and cliques.                        */
/*       -usecliques should be set to 1 to allow branching on cliques      */
/*       -val returns the length of a tour if one is detected.             */
/*       -tour returns the tour (it can be NULL)                           */
/*                                                                         */
/*    int CCtsp_find_branch_edge (CCtsp_lp *lp, int *n0, int *n1,          */
/*               double *val, int **tour, int branchtype)                  */
/*     FINDS a branching edge or detects that solution is integral.        */
/*      -lp points to an optimized lp.                                     */
/*      -n0, n1 return the edges of the branching edge; n0 is set to -1    */
/*           if the current lp solution is a tour                          */
/*      -val returns the value the tour if n0 is set to -1                 */
/*      -branchtype determines the strategy for choosing the branching     */
/*           edge; choices for branchtype are given in tsp.h               */
/*                                                                         */
/*    int CCtsp_check_integral (CCtsp_lp *lp, double *val, int **cyc,      */
/*                int *yesno)                                              */
/*     TESTS if the current x-vector is a tour.                            */
/*      -yesno is set to 1 if it is a tour and 0 otherwise.                */
/*                                                                         */
/*    int CCtsp_find_branch_cliques (CCtsp_lp *lp, int nwant, int *ngot,   */
/*            CCtsp_lpclique **bcliques, double *bval)                     */
/*     FINDS branching cliques (it may return ngot == 0)                   */
/*     -bval will return the stongbranching function evaluation for        */
/*      each clique (it can be NULL)                                       */
/*                                                                         */
/*    void CCtsp_init_branchobj (CCtsp_branchobj *b)                       */
/*     INITITALIZES the fields in the CCtsp_branchobj pointed to by b.     */
/*                                                                         */
/*    void CCtsp_free_branchobj (CCtsp_branchobj *b)                       */
/*     FREES the fields in the CCtsp_branchobj pointed to by b.            */
/*                                                                         */
/*    void CCtsp_print_branchhistory (CCtsp_lp *lp)                        */
/*     PRINT to stdout the branch history of the lp                        */
/*                                                                         */
/*    int CCtsp_execute_branch (CCtsp_lp *lp, CCtsp_branchobj *b)          */
/*     SETS the lp to realize the branch described in b                    */
/*     NOTE: returns 2 if the LP becomes infeasible.                       */
/*                                                                         */
/*    int CCtsp_execute_unbranch (CCtsp_lp *lp, CClpbasis *basis)          */
/*     UNDOS the changes to the lp caused by the most recent branch that   */
/*      has not yet been unbranched (used in dfs)                          */
/*      -basis can specify a basis and dual norms to help resolve the LP   */
/*       (in can be NULL)                                                  */
/*                                                                         */
/*    int CCtsp_add_branchhistory_to_lp (CCtsp_lp *lp)                     */
/*     SETS the lp to realize the branches in branch history               */
/*                                                                         */
/*    int CCtsp_splitprob (CCtsp_lp *lp, CCtsp_branchobj *b, int child0,   */
/*            int child1)                                                  */
/*     EXECUTES a branch on the lp and writes to two child lps             */
/*      -b contains the branching information (the rhs side value is set   */
/*       by this function to give 0 and 1 for edge branches and 2 & 4 for  */
/*       clique branches; the sense is set by this function for clique     */
/*       branches to realize <= 2 and >= 4)                                */
/*      -child0 and child1 are the ids of the children                     */
/*                                                                         */
/*    int CCtsp_bb_splitprob (char *probname, int probnum, int ncount,     */
/*            CCdatagroup *dat, int *ptour, double initial_ub,             */
/*            CCtsp_lpcuts *pool, CCtsp_branchobj *b, int child0,          */
/*            int child1, double *val0, double *val1, int *prune0,         */
/*            int *prune1)                                                 */
/*     CALLS splitprob after reading the lp file and building an lp; this  */
/*      function will also price the lp and attempt to verify infeasible   */
/*      lps.                                                               */
/*      -val0 and val1 return the (priced) lp-bounds for the children; if  */
/*       an lp is infeasible then the val is set to CCtsp_LP_MAXDOUBLE and */
/*       the lp is not written.                                            */
/*      -prune0 and prune1 will be set to 1 if the child can be pruned     */
/*       (in which case the lp is not written)                             */
/*                                                                         */
/*    int CCtsp_dumptour (int ncount, CCdatagroup *dat, int *perm,         */
/*            char *probname, int *tour)                                   */
/*     WRITES the tour file to probname.sol.                               */
/*      -dat is used to compute the length (it can be NULL)                */
/*      -perm is a permutation tour                                        */
/*      -tour gives the tour (perm[tour[i]] with be printed)               */
/*                                                                         */
/*                                                                         */
/***************************************************************************/

#include "machdefs.h"
#include "util.h"
#include "macrorus.h"
#include "tsp.h"
#include "lp.h"
#include "cut.h"


#define TSP_BRANCH_STRONG_ALL_CHOICES -1
#define TSP_BRANCH_STRONG_ITERATIONS  100
#define TSP_BRANCH_STRONG_CHOICES     50  /* SET TO ALL_CHOICES TO TRY ALL */

#define TSP_STRONG_CUT_ITER           100
#define TSP_STRONG_CUT_CHOICES        50
#define TSP_STRONG_CUT_CANDIDATES     1000

#define TSP_BRANCH_STRONG_FIRST_VAL(v0,v1)                                 \
    ((v0) < (v1) ? (10.0 * (v0) + (v1)) : (10.0 * (v1) + (v0)))

#define TSP_BRANCH_STRONG_VAL(v0,v1)                                       \
    ((v0) < (v1) ? (25.0 * (v0) + (v1)) : (25.0 * (v1) + (v0)))

#define TSP_BRANCH_STRONG_CUT_NORM_VAL(v0,v1)                              \
    ((v0) < (v1) ? (100.0 * (v0) + (v1)) : (100.0 * (v1) + (v0)))

typedef struct sbitem {
    int    name;
    double val;
} sbitem;


#ifdef CC_PROTOTYPE_ANSI

static int
    merge_edge_clique (CCtsp_lp *lp, int nwant, int *ngot,
            CCtsp_branchobj **bobj,
            int ecount, int *elist, double *eval,
            int ccount, CCtsp_lpclique *clist, double *cval),
    find_strong_branch (CCtsp_lp *lp, int *n0, int *n1),
    find_strongbranch_edges (CCtsp_lp *lp, int nwant, int *ngot, int **elist,
            double **eval),
    find_candidate_edges (CCtsp_lp *lp, int nwant, int *ngot, int **list),
    find_all_candidate_edges (CCtsp_lp *lp, int *ngot, int **list),
    find_candidate_cliques (CCtsp_lp *lp, int nwant, int *ngot,
            CCtsp_lpclique **list, int use_getweight),
    find_branched_clique (CCtsp_lp *lp, CCtsp_lpclique *c, char sense, int rhs,
            int *cutnum),
    branch_side (CCtsp_lp *lp, CCtsp_branchobj *b, int side, int child,
            double *val, int *prune);

static void
    print_branchobj (CCtsp_branchobj *b),
    init_sblist (sbitem *list, int count),
    insert_sblist (sbitem *list, double val, int name);

#else  /* CC_PROTOTYPE_ANSI */

static int
    merge_edge_clique (),
    find_strong_branch (),
    find_strongbranch_edges (),
    find_candidate_edges (),
    find_all_candidate_edges (),
    find_candidate_cliques (),
    find_branched_clique (),
    branch_side ();

static void
    print_branchobj (),
    init_sblist (),
    insert_sblist ();

#endif /* CC_PROTOTYPE_ANSI */

#ifdef CC_PROTOTYPE_ANSI
void CCtsp_init_branchobj (CCtsp_branchobj *b)
#else
void CCtsp_init_branchobj (b)
CCtsp_branchobj *b;
#endif
{
    b->depth     = 0;
    b->rhs       = 0;
    b->ends[0]   = -1;
    b->ends[1]   = -1;
    b->sense     = 'X';
    b->clique    = (CCtsp_lpclique *) NULL;
}

#ifdef CC_PROTOTYPE_ANSI
void CCtsp_free_branchobj (CCtsp_branchobj *b)
#else
void CCtsp_free_branchobj (b)
CCtsp_branchobj *b;
#endif
{
    if (!b) return;

    b->depth     = 0;
    b->rhs       = 0;
    b->ends[0]   = -1;
    b->ends[1]   = -1;
    b->sense     = 'X';
    if (b->clique) {
        CCtsp_free_lpclique (b->clique);
        CC_FREE (b->clique, CCtsp_lpclique);
    }
}

#ifdef CC_PROTOTYPE_ANSI
void CCtsp_print_branchhistory (CCtsp_lp *lp)
#else
void CCtsp_print_branchhistory (lp)
CCtsp_lp *lp;
#endif
{
    int j;
    printf ("Branch History\n"); fflush (stdout);
    if (lp->branchdepth == 0) {
        printf ("    Root Node\n");
    } else {
        for (j = 0; j < lp->branchdepth; j++) {
            printf ("    ");
            print_branchobj (&lp->branchhistory[j]);
        }
    }
    fflush (stdout);
}

#ifdef CC_PROTOTYPE_ANSI
static void print_branchobj (CCtsp_branchobj *b)
#else
static void print_branchobj (b)
CCtsp_branchobj *b;
#endif
{
    int i;

    printf ("Depth %d:  ", b->depth);
    if (b->ends[0] != -1) {
        printf ("Edge (%d,%d) set to %d\n", b->ends[0], b->ends[1], b->rhs);
    } else {
        printf ("Clique ");
        for (i = 0; i < b->clique->segcount; i++) {
            printf ("%d->%d ", b->clique->nodes[i].lo, b->clique->nodes[i].hi);
        }
        if (b->sense == 'L') {
            printf ("at most %d\n", b->rhs);
        } else {
            printf ("at least %d\n", b->rhs);
        }
    }
    fflush (stdout);
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_find_branch (CCtsp_lp *lp, int nwant, int *ngot,
        CCtsp_branchobj **bobj, double *val, int **cyc, int usecliques)
#else
int CCtsp_find_branch (lp, nwant, ngot, bobj, val, cyc, usecliques)
CCtsp_lp *lp;
int nwant;
int *ngot;
CCtsp_branchobj **bobj;
double *val;
int **cyc;
int usecliques;
#endif
{
    int rval = 0;
    int egot = 0;
    int cgot = 0;
    int      *elist = (int *) NULL;
    CCtsp_lpclique *clist = (CCtsp_lpclique *) NULL;
    double   *eval  = (double *) NULL;
    double   *cval  = (double *) NULL;
    int i, n0, n1;

    *ngot = 0;
    *bobj = (CCtsp_branchobj *) NULL;
    if (cyc) *cyc = (int *) NULL;

    if (nwant <= 0) {
        fprintf (stderr, "CCtsp_find_branch called with no nwant\n");
        rval = 1; goto CLEANUP;
    }

    rval = CCtsp_find_branch_edge (lp, &n0, &n1, val, cyc, CCtsp_BRANCH_MIDDLE);
    if (rval) {
        fprintf (stderr, "CCtsp_find_branch failed\n"); goto CLEANUP;
    }

    if (n0 == -1 && n1 == -1) {
        printf ("Integral solution: %f\n", *val); fflush (stdout);
        goto CLEANUP;
    }

    rval = find_strongbranch_edges (lp, nwant, &egot, &elist, &eval);
    if (rval) {
        fprintf (stderr, "find_strongbranch_edges failed\n"); goto CLEANUP;
    }

    if (usecliques) {
        rval = CCtsp_find_branch_cliques (lp, nwant, &cgot, &clist, &cval);
        if (rval) {
            fprintf (stderr, "CCtsp_find_branch_cliques failed\n");
            goto CLEANUP;
        }
        printf ("Cliques found:\n"); fflush (stdout);
        for (i = 0; i < cgot; i++) {
            CCtsp_print_lpclique (&clist[i]);
        }
    }

    if (egot + cgot > 0) {
        rval = merge_edge_clique (lp, nwant, ngot, bobj, egot, elist, eval,
                                                         cgot, clist, cval);
        if (rval) {
            fprintf (stderr, "merge_edge_clique failed\n"); goto CLEANUP;
        }
    } else {
        CCtsp_branchobj *b;
        printf ("found no edges or cliques, use the middle branch edge\n");
        fflush (stdout);

        b = CC_SAFE_MALLOC (1, CCtsp_branchobj);
        if (!b) {
            fprintf (stderr, "out of memory in CCtsp_find_branch\n");
            rval = 1; goto CLEANUP;
        }
        CCtsp_init_branchobj (b);
        b->ends[0] = n0;
        b->ends[1] = n1;
        *bobj = b;
        *ngot = 1;
    }

CLEANUP:

    CC_IFFREE (elist, int);
    for (i = 0; i < cgot; i++) {
        CCtsp_free_lpclique (&clist[i]);
    }
    CC_IFFREE (clist, CCtsp_lpclique);
    CC_IFFREE (cval, double);
    CC_IFFREE (eval, double);
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static int merge_edge_clique (CCtsp_lp *lp, int nwant, int *ngot,
        CCtsp_branchobj **bobj, int ecount, int *elist, double *eval,
        int ccount, CCtsp_lpclique *clist, double *cval)
#else
static int merge_edge_clique (lp, nwant, ngot, bobj, ecount, elist, eval,
        ccount, clist, cval)
CCtsp_lp *lp;
int nwant;
int *ngot;
CCtsp_branchobj **bobj;
int ecount;
int *elist;
double *eval;
int ccount;
CCtsp_lpclique *clist;
double *cval;
#endif
{
    int rval = 0;
    int i, k;
    sbitem *slist = (sbitem *) NULL;
    CCtsp_branchobj *b;

    *ngot = 0;
    *bobj = (CCtsp_branchobj *) NULL;

    if (ecount + ccount == 0) {
        fprintf (stderr, "no elements in merge_edge_clique\n");
        rval = 1; goto CLEANUP;
    }

    slist = CC_SAFE_MALLOC (nwant + 1, sbitem);
    if (!slist) {
        fprintf (stderr, "out of memory in merge_edge_clique\n");
        rval = 1; goto CLEANUP;
    }
    init_sblist (slist, nwant);

    for (i = 0; i < ecount; i++) {
        insert_sblist (slist, eval[i], i);
    }
    for (i = 0; i < ccount; i++) {
        insert_sblist (slist, cval[i], i + ecount);
    }

    for (i = 0, k = 0; i < nwant; i++) {
        if (slist[i].name != -1) {
            k++;
        }
    }
    if (k == 0) {
        fprintf (stderr, "nothing appeares in merge_edge_clique\n");
        rval = 1; goto CLEANUP;
    }

    *bobj = CC_SAFE_MALLOC (k, CCtsp_branchobj);
    if (!(*bobj)) {
        fprintf (stderr, "out of memory in merge_edge_clique\n");
        rval = 1; goto CLEANUP;
    }

    for (i = 0, k = 0; i < nwant; i++) {
        if (slist[i].name != -1) {
            b = &((*bobj)[k]);
            CCtsp_init_branchobj (b);
            if (slist[i].name < ecount) {
                b->ends[0] = lp->graph.edges[elist[slist[i].name]].ends[0];
                b->ends[1] = lp->graph.edges[elist[slist[i].name]].ends[1];
            } else {
                b->clique = CC_SAFE_MALLOC (1, CCtsp_lpclique);
                if (!b->clique) {
                    fprintf (stderr, "out of memory in merge_edge_clique\n");
                    rval = 1; goto CLEANUP;
                } else {
                    rval = CCtsp_copy_lpclique (&clist[slist[i].name - ecount],
                                                b->clique);
                }
                if (!b->clique || rval) {
                    fprintf (stderr, "CCtsp_copy_clique failed\n");
                    for (i = 0; i < k; i++) {
                        if ((*bobj)[i].clique) {
                            CCtsp_free_lpclique ((*bobj)[i].clique);
                            CC_IFFREE ((*bobj)[i].clique, CCtsp_lpclique);
                        }
                    }
                    CC_IFFREE (b->clique, CCtsp_lpclique);
                    CC_FREE (*bobj, CCtsp_branchobj);
                    goto CLEANUP;
                }
            }
            k++;
        }
    }
    *ngot = k;

CLEANUP:

    CC_IFFREE (slist, sbitem);
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_check_integral (CCtsp_lp *lp, double *val, int **cyc, int *yesno)
#else
int CCtsp_check_integral (lp, val, cyc, yesno)
CCtsp_lp *lp;
double *val;
int **cyc;
int *yesno;
#endif
{
    int rval = 0;
    double *x = (double *) NULL;
    double eval = 0.0;
    int *xlist = (int *) NULL;
    int xcount;
    int *comps = (int *) NULL;
    int *compscount = (int *) NULL;
    int ncomp;
    int *elist = (int *) NULL;
    int ncount = lp->graph.ncount;
    int i, j, ecount;

    *yesno = 0;
    *val = 0.0;
    if (cyc) *cyc = (int *) NULL;

    rval = CCtsp_get_lp_result (lp, (double *) NULL, (double *) NULL, &xcount,
                          &xlist, &x, (double **) NULL, (double **) NULL,
                          (double **) NULL);
    if (rval) {
        fprintf (stderr, "CCtsp_get_lp_result failed\n"); goto CLEANUP;
    }

    for (i = 0; i < xcount; i++) {
        if (x[i] > 0.5) {
            if (1.0 - x[i] > CCtsp_INTTOL) goto CLEANUP;
        } else {
            if (x[i] > CCtsp_INTTOL) goto CLEANUP;
        }
    }

    elist = CC_SAFE_MALLOC (2*ncount, int);
    if (!elist) {
        fprintf (stderr, "out of memory in CCtsp_check_integral\n");
    }
    ecount = 0;

    for (i = 0; i < xcount; i++) {
        if (x[i] > CCtsp_INTTOL) {
            j = CCtsp_find_edge (&lp->graph, xlist[2*i], xlist[2*i+1]);
            if (j < 0) {
                fprintf (stderr, "x edge not in graph\n");
                rval = 1; goto CLEANUP;
            }
            eval += ((double) lp->graph.edges[j].len);
            elist[2*ecount]   = lp->graph.edges[j].ends[0];
            elist[2*ecount+1] = lp->graph.edges[j].ends[1];
            ecount++;
        }
    }

    rval = CCcut_connect_components (ncount, xcount, xlist, x,
                                     &ncomp, &compscount, &comps);
    if (rval) {
        fprintf (stderr, "CCcut_connect_components failed\n"); goto CLEANUP;
    }
    if (ncomp > 1) {
        printf ("integral solution not connected\n"); fflush (stdout);
        goto CLEANUP;
    }
    printf ("Integral Solution of Value %.2f\n", *val); fflush (stdout);

    if (cyc) {
        *cyc = CC_SAFE_MALLOC (ncount, int);
        if (!(*cyc)) {
            fprintf (stderr, "out of memory in CCtsp_check_integral\n");
            rval = 1; goto CLEANUP;
        }
        rval = CCutil_edge_to_cycle (ncount, elist, *cyc);
        if (rval) {
            fprintf (stderr, "CCutil_edge_to_cycle failed\n");
            CC_FREE (*cyc, int);
            goto CLEANUP;
        }
    }
    *yesno = 1;
    *val = eval;


CLEANUP:

    CC_IFFREE (x, double);
    CC_IFFREE (xlist, int);
    CC_IFFREE (comps, int);
    CC_IFFREE (compscount, int);
    CC_IFFREE (elist, int);

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_find_branch_edge (CCtsp_lp *lp, int *n0, int *n1, double *val,
        int **cyc, int branchtype)
#else
int CCtsp_find_branch_edge (lp, n0, n1, val, cyc, branchtype)
CCtsp_lp *lp;
int *n0, *n1;
double *val;
int **cyc;
int branchtype;
#endif
{
    int rval = 0;
    double *x = (double *) NULL;
    int *xlist = (int *) NULL;
    int xcount;
    double maxdiff = -1.0;
    int i, test, besti = 0;

    *n0 = -2;
    *n1 = -2;
    *val = 0.0;
    if (cyc) *cyc = (int *) NULL;

    rval = CCtsp_check_integral (lp, val, cyc, &test);
    if (rval) {
        fprintf (stderr, "CCtsp_check_integral failed\n");
        goto CLEANUP;
    }
    if (test) {
        printf ("Integral solution detected in CCtsp_find_branch_edge\n");
        fflush (stdout);
        *n0 = -1;
        *n1 = -1;
        goto CLEANUP;
    }

    rval = CCtsp_get_lp_result (lp, (double *) NULL, (double *) NULL, &xcount,
                          &xlist, &x, (double **) NULL, (double **) NULL,
                          (double **) NULL);
    if (rval) {
        fprintf (stderr, "CCtsp_get_lp_result failed\n"); goto CLEANUP;
    }

    for (i = 0; i < xcount; i++) {
        if (x[i] > 0.5) {
            if (1.0 - x[i] > maxdiff) {
                maxdiff = 1.0 - x[i];
                besti = i;
            }
        } else {
            if (x[i] > maxdiff) {
                maxdiff = x[i];
                besti = i;
            }
        }
    }

    switch (branchtype) {
    case CCtsp_BRANCH_MIDDLE:
        *n0 = xlist[2*besti];
        *n1 = xlist[2*besti+1];
        break;
    case CCtsp_BRANCH_STRONG:
        rval = find_strong_branch (lp, n0, n1);
        if (rval) {
            fprintf (stderr, "find_strong_branch failed\n");
            goto CLEANUP;
        }
        if (*n0 == -1) {
            *n0 = xlist[2*besti];
            *n1 = xlist[2*besti+1];
        }
        break;
    default:
        fprintf (stderr, "unknown branchtype\n");
        rval = 1; goto CLEANUP;
    }

CLEANUP:

    CC_IFFREE (x, double);
    CC_IFFREE (xlist, int);

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static int find_strong_branch (CCtsp_lp *lp, int *n0, int *n1)
#else
static int find_strong_branch (lp, n0, n1)
CCtsp_lp *lp;
int *n0, *n1;
#endif
{
    int rval = 0;
    int *elist = (int *) NULL;
    int ngot;

    *n0 = -1;
    *n1 = -1;

    rval = find_strongbranch_edges (lp, 1, &ngot, &elist, (double **) NULL);
    if (rval) {
        fprintf (stderr, "find_strongbranch_edges failed\n");
        goto CLEANUP;
    }

    if (ngot == 0) {
        printf ("WARNING: nothing came back from find_strongbranch_edges\n");
        goto CLEANUP;
    }

    *n0 = lp->graph.edges[elist[0]].ends[0];
    *n1 = lp->graph.edges[elist[0]].ends[1];

    printf ("STRONG branch edge: %d %d\n", *n0, *n1);
    fflush (stdout);

CLEANUP:

    CC_IFFREE (elist, int);
    return rval;
}


#ifdef CC_PROTOTYPE_ANSI
static int find_strongbranch_edges (CCtsp_lp *lp, int nwant, int *ngot,
        int **elist, double **eval)
#else
static int find_strongbranch_edges (lp, nwant, ngot, elist, eval)
CCtsp_lp *lp;
int nwant;
int *ngot;
int **elist;
double **eval;
#endif
{
    int rval = 0;
    int *candlist = (int *) NULL;
    int ncand = 0;
    int i, k;
    double *downpen = (double *) NULL;
    double *uppen   = (double *) NULL;
    double sval;
    double szeit;
    sbitem *slist = (sbitem *) NULL;

    *ngot = 0;
    *elist = (int *) NULL;
    if (eval) {
        *eval = (double *) NULL;
    }

    rval = find_candidate_edges (lp, TSP_BRANCH_STRONG_CHOICES, &ncand,
                             &candlist);
    if (rval) {
        fprintf (stderr, "find_candidate_edges failed\n");
        goto CLEANUP;
    }

    if (ncand == 0) {
        printf ("WARNING: find_candidate edges did not find anything\n");
        goto CLEANUP;
    }

    printf ("Run strongbranch with %d candidate edges\n", ncand);
    fflush (stdout);

    downpen = CC_SAFE_MALLOC (ncand, double);
    uppen   = CC_SAFE_MALLOC (ncand, double);
    if (!downpen || !uppen) {
        fprintf (stderr, "out of memory in find_strongbranch_edges\n");
        rval = 1; goto CLEANUP;
    }

    szeit = CCutil_zeit ();
    rval = CClp_strongbranch (&lp->lp, candlist, ncand, downpen, uppen,
                TSP_BRANCH_STRONG_ITERATIONS, &lp->upperbound);
    if (rval) {
        fprintf (stderr, "CClp_strongbranch failed\n"); goto CLEANUP;
    }
    printf ("Strongbranch used %.2f seconds\n", CCutil_zeit () - szeit);

    slist = CC_SAFE_MALLOC (nwant + 1, sbitem);
    if (!slist) {
        fprintf (stderr, "out of memory in find_strongbranch_edges\n");
        rval = 1; goto CLEANUP;
    }
    init_sblist (slist, nwant);

    for (i = 0; i < ncand; i++) {
        printf ("SB Edge (%d, %d):  %.4f  %.4f\n",
                    lp->graph.edges[candlist[i]].ends[0],
                    lp->graph.edges[candlist[i]].ends[1],
                    downpen[i], uppen[i]);
        fflush (stdout);
        sval = TSP_BRANCH_STRONG_VAL (downpen[i], uppen[i]);
        insert_sblist (slist, sval, candlist[i]);
    }

    for (i = 0, k = 0; i < nwant; i++) {
        if (slist[i].name != -1) {
            k++;
        }
    }
    if (k == 0) {
        printf ("WARNING: no edges appeared in strongbranch\n");
        goto CLEANUP;
    }

    *elist = CC_SAFE_MALLOC (k, int);
    if (!(*elist)) {
        fprintf (stderr, "out of memory in find_strongbranch_edges\n");
        rval = 1; goto CLEANUP;
    }
    if (eval) {
        *eval = CC_SAFE_MALLOC (k, double);
        if (!(*eval)) {
            fprintf (stderr, "out of memory in find_strongbranch_edges\n");
            CC_IFFREE (*elist, int);
            rval = 1; goto CLEANUP;
        }
    }
    *ngot = k;
    for (i = 0, k = 0; i < nwant; i++) {
        if (slist[i].name != -1) {
            (*elist)[k] = slist[i].name;
            if (eval) {
                (*eval)[k] = slist[i].val;
            }
            k++;
        }
    }

CLEANUP:

    CC_IFFREE (slist, sbitem);
    CC_IFFREE (candlist, int);
    CC_IFFREE (downpen, double);
    CC_IFFREE (uppen, double);

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static int find_candidate_edges (CCtsp_lp *lp, int nwant, int *ngot, int **list)
#else
static int find_candidate_edges (lp, nwant, ngot, list)
CCtsp_lp *lp;
int nwant;
int *ngot;
int **list;
#endif
{
    int *goodlist     = (int *) NULL;
    double *downpen = (double *) NULL;
    double *uppen   = (double *) NULL;
    double sval;
    int nrows, ngood;
    int i, k;
    sbitem *slist = (sbitem *) NULL;
    int rval = 0;

    *ngot = 0;
    *list = (int *) NULL;

    if (nwant == TSP_BRANCH_STRONG_ALL_CHOICES) {
        rval = find_all_candidate_edges (lp, ngot, list);
        if (rval) {
            fprintf (stderr, "find_all_candidate_edges failed\n");
            goto CLEANUP;
        }
        goto CLEANUP;
    }

    slist = CC_SAFE_MALLOC (nwant + 1, sbitem);
    if (!slist) {
        fprintf (stderr, "out of memory in find_strongbranch\n");
        rval = 1; goto CLEANUP;
    }
    init_sblist (slist, nwant);

    nrows     = lp->graph.ncount + lp->cuts.cutcount;
    goodlist  = CC_SAFE_MALLOC (nrows, int);
    downpen = CC_SAFE_MALLOC (nrows, double);
    uppen   = CC_SAFE_MALLOC (nrows, double);
    if (!goodlist || !downpen || !uppen) {
        fprintf (stderr, "out of memory in find_strongbranch\n");
        rval = 1; goto CLEANUP;
    }
    rval = CClp_getgoodlist (&lp->lp, goodlist, &ngood, downpen, uppen);
    if (rval) {
        fprintf (stderr, "CClp_getgoodlist failed\n"); goto CLEANUP;
    }
    printf ("Found %d good edges\n", ngood); fflush (stdout);

    for (i = 0; i < ngood; i++) {
        if (downpen[i] > lp->upperbound) downpen[i] = lp->upperbound;
        if (uppen[i] > lp->upperbound) uppen[i] = lp->upperbound;
        sval = TSP_BRANCH_STRONG_FIRST_VAL (downpen[i], uppen[i]);
        insert_sblist (slist, sval, goodlist[i]);
    }

    for (i = 0, k = 0; i < nwant; i++) {
        if (slist[i].name != -1) {
            k++;
        }
    }
    if (k == 0) {
        printf ("WARNING: CClp_getgoodlist returned no edges\n");
        goto CLEANUP;
    }

    *list = CC_SAFE_MALLOC (k, int);
    if (!(*list)) {
        fprintf (stderr, "out of memory in find_candidate list\n");
        rval = 1; goto CLEANUP;
    }
    *ngot = k;
    for (i = 0, k = 0; i < nwant; i++) {
        if (slist[i].name != -1) {
            (*list)[k++] = slist[i].name;
        }
    }

CLEANUP:

    CC_IFFREE (goodlist, int);
    CC_IFFREE (downpen, double);
    CC_IFFREE (uppen, double);
    CC_IFFREE (slist, sbitem);

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static int find_all_candidate_edges (CCtsp_lp *lp, int *ngot, int **list)
#else
static int find_all_candidate_edges (lp, ngot, list)
CCtsp_lp *lp;
int *ngot;
int **list;
#endif
{
    int rval = 0;
    double *x  = (double *) NULL;
    int *xlist = (int *) NULL;
    int i, j, xcount, count;

    *ngot = 0;
    *list = (int *) NULL;

    rval = CCtsp_get_lp_result (lp, (double *) NULL, (double *) NULL, &xcount,
                          &xlist, &x, (double **) NULL, (double **) NULL,
                          (double **) NULL);
    if (rval) {
        fprintf (stderr, "get_lp_result failed\n"); goto CLEANUP;
    }

    count = 0;
    for (i = 0; i < xcount; i++) {
        if (x[i] >= CCtsp_INTTOL && x[i] <= 1.0 - CCtsp_INTTOL) {
            count++;
        }
    }

    if (!count) {
        fprintf (stderr, "WARNING: The solution is integral\n");
        goto CLEANUP;
    }

    *list = CC_SAFE_MALLOC (count, int);
    if (!(*list)) {
        fprintf (stderr, "out of memory in find_all_candidate_edges\n");
        rval = 1; goto CLEANUP;
    }

    count = 0;
    for (i = 0; i < xcount; i++) {
        if (x[i] >= CCtsp_INTTOL && x[i] <= 1.0 - CCtsp_INTTOL) {
            j = CCtsp_find_edge (&lp->graph, xlist[2 * i], xlist[2 * i + 1]);
            if (j < 0) {
                fprintf (stderr, "edge not in lp in find_all_candiate_edges\n");
                CC_IFFREE (*list, int);
                rval = 1; goto CLEANUP;
            }
            (*list)[count++] = j;
        }
    }
    *ngot = count;

CLEANUP:

    CC_IFFREE (x, double);
    CC_IFFREE (xlist, int);

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static void init_sblist (sbitem *list, int count)
#else
static void init_sblist (list, count)
sbitem *list;
int count;
#endif
{
    int i;

    for (i = 0; i < count; i++) {
        list[i].val  = -1.0;
        list[i].name = -1;
    }
    list[count].val = CCtsp_LP_MAXDOUBLE;
}

#ifdef CC_PROTOTYPE_ANSI
static void insert_sblist (sbitem *list, double val, int name)
#else
static void insert_sblist (list, val, name)
sbitem *list;
double val;
int name;
#endif
{
    int k;

    if (list[0].val < val) {
        for (k = 0; list[k+1].val < val; k++) {
            list[k].name = list[k + 1].name;
            list[k].val = list[k + 1].val;
        }
        list[k].val = val;
        list[k].name = name;
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_find_branch_cliques (CCtsp_lp *lp, int nwant, int *ngot,
        CCtsp_lpclique **bcliques, double **bval)
#else
int CCtsp_find_branch_cliques (lp, nwant, ngot, bcliques, bval)
CCtsp_lp *lp;
int nwant;
int *ngot;
CCtsp_lpclique **bcliques;
double **bval;
#endif
{
    int      ccount   = 0;
    CCtsp_lpclique *cliques = (CCtsp_lpclique *) NULL;
    sbitem   *slist   = (sbitem *) NULL;
    int i, k;
    int rval = 0;
    double up, down, sval, szeit;
    double meanval = 0.0;

    *ngot     = 0;
    *bcliques = (CCtsp_lpclique *) NULL;
    if (bval) {
        *bval = (double *) NULL;
    }

    rval = find_candidate_cliques (lp, TSP_STRONG_CUT_CHOICES, &ccount,
                                   &cliques, 1);
    if (rval) {
        fprintf (stderr, "find_candidate_cliques failed\n"); goto CLEANUP;
    }
    printf ("Found %d candidate cliques\n", ccount); fflush (stdout);

    slist = CC_SAFE_MALLOC (nwant + 1, sbitem);
    if (!slist) {
        fprintf (stderr, "out of memory in find_strongbranch_edges\n");
        rval = 1; goto CLEANUP;
    }
    init_sblist (slist, nwant);


    for (i = 0; i < ccount; i++) {
        szeit = CCutil_zeit ();
        rval = CCtsp_test_cut_branch (lp, &cliques[i], &down, &up);
        if (rval) {
            fprintf (stderr, "CCtsp_test_cut_branch failed\n");
            goto CLEANUP;
        }
        printf ("SB CLIQUE %d:  %f  %f  (%.2f seconds)\n",
                   i, down, up, CCutil_zeit () - szeit);
        fflush (stdout);
        sval = TSP_BRANCH_STRONG_VAL (down, up);
        insert_sblist (slist, sval, i);
        meanval += sval;
    }

    if (ccount) {
        printf ("Average Clique Value: %f\n", meanval / ((double) ccount));
        fflush (stdout);
    }

    for (i = nwant - 1; i >= 0; i--) {
        if (slist[i].name != -1) {
            printf ("Top Clique: %d  (%f)\n", slist[i].name, slist[i].val);
            fflush (stdout);
            break;
        }
    }

    for (i = 0, k = 0; i < nwant; i++) {
        if (slist[i].name != -1) {
            k++;
        }
    }
    if (k == 0) {
        printf ("WARNING: no branching cliques were found\n");
        goto CLEANUP;
    }

    *bcliques = CC_SAFE_MALLOC (k, CCtsp_lpclique);
    if (!(*bcliques)) {
        fprintf (stderr, "out of memory in CCtsp_find_branch_cliques\n");
        rval = 1; goto CLEANUP;
    }
    if (bval) {
        *bval = CC_SAFE_MALLOC (k, double);
        if (!(*bval)) {
            fprintf (stderr, "out of memory in CCtsp_find_branch_cliques\n");
            CC_IFFREE (*bcliques, CCtsp_lpclique);
            rval = 1; goto CLEANUP;
        }
    }
    *ngot = k;
    for (i = 0, k = 0; i < nwant; i++) {
        if (slist[i].name != -1) {
            rval = CCtsp_copy_lpclique (&cliques[slist[i].name],
                                        &(*bcliques)[k]);
            if (rval) {
                fprintf (stderr, "CCtsp_copy_clique failed\n");
                for (i = 0; i < k; i++) {
                    CC_IFFREE ((*bcliques)[i].nodes, CCtsp_segment);
                }
                CC_FREE (*bcliques, CCtsp_lpclique);
                goto CLEANUP;
            }
            if (bval) {
                (*bval)[k] = slist[i].val;
            }
            k++;
        }
    }
    *ngot = k;


CLEANUP:

    CC_IFFREE (slist, sbitem);
    for (i = 0; i < ccount; i++) {
        CC_IFFREE (cliques[i].nodes, CCtsp_segment);
    }
    CC_IFFREE (cliques, CCtsp_lpclique);

    return 0;
}

#define TSP_STRONG_GETWEIGHT_BATCH 250

#ifdef CC_PROTOTYPE_ANSI
static int find_candidate_cliques (CCtsp_lp *lp, int nwant, int *ngot,
        CCtsp_lpclique **list, int use_getweight)
#else
static int find_candidate_cliques (lp, nwant, ngot, list, use_getweight)
CCtsp_lp *lp;
int nwant;
int *ngot;
CCtsp_lpclique **list;
int use_getweight;
#endif
{
    int      xcount   = 0;
    double   *x       = (double *) NULL;
    int      *xlist   = (int *) NULL;
    int      ccount   = 0;
    double   *cval    = (double *) NULL;
    CCtsp_lpclique *cliques = (CCtsp_lpclique *) NULL;
    double   *weights = (double *) NULL;
    sbitem   *slist   = (sbitem *) NULL;
    CCtsp_lprow cr;
    CCtsp_lpcut_in cu;
    int i, k, j, batch, ntry, nzlist;
    double down, up, t, sval;
    int rval = 0;

    CCtsp_init_lprow (&cr);

    rval = CCtsp_get_lp_result (lp, (double *) NULL, (double *) NULL, &xcount,
                     &xlist, &x, (double **) NULL, (double **) NULL,
                     (double **) NULL);
    if (rval) {
        fprintf (stderr, "CCtsp_get_lp_result failed\n"); goto CLEANUP;
    }

    ntry = (use_getweight ? TSP_STRONG_CUT_CANDIDATES : nwant);

    rval = CCtsp_branch_cutpool_cliques (lp->pool, &cliques, &ccount,
              lp->graph.ncount, xcount, xlist, x, ntry, &cval);
    if (rval) {
        fprintf (stderr, "CCtsp_branch_cutpool_cliques failed\n");
        goto CLEANUP;
    }
    if (ccount == 0) {
        fprintf (stderr, "WARNING: no cutpool cliques were found\n");
        goto CLEANUP;
    }

    if (use_getweight) {
        cu.handlecount = 0;
        cu.cliquecount = 1;
        cu.next = (CCtsp_lpcut_in *) NULL;
        cu.prev = (CCtsp_lpcut_in *) NULL;
        cu.rhs  = 2;

        weights = CC_SAFE_MALLOC (TSP_STRONG_GETWEIGHT_BATCH, double);
        if (!weights) {
            fprintf (stderr, "out of memory in find_candidate_cliques\n");
            rval = 1; goto CLEANUP;
        }

        slist = CC_SAFE_MALLOC (nwant + 1, sbitem);
        if (!slist) {
            fprintf (stderr, "out of memory in find_strongbranch_edges\n");
            rval = 1; goto CLEANUP;
        }
        init_sblist (slist, nwant);

        for (i = 0, batch = 0; i < ccount; i++) {
            cu.cliques = &(cliques[i]);
            nzlist = CCtsp_lpcut_in_nzlist (&lp->graph, &cu);
            rval = CCtsp_add_nzlist_to_lp (lp, nzlist, 2, 'G', &cr);
            if (rval) {
                fprintf (stderr, "CCtsp_add_nzlist_to_lp failed\n");
                goto CLEANUP;
            }
            if ((i+1) % TSP_STRONG_GETWEIGHT_BATCH == 0 || i == ccount - 1) {
                rval = CCutil_reallocrus_count ((void **) &(cr.begin),
                                      cr.rowcnt + 1, sizeof (int));
                if (rval) {
                    fprintf (stderr, "out of memory\n");
                    goto CLEANUP;
                }
                cr.begin[cr.rowcnt] = cr.nzcnt;
                rval = CClp_getweight (&lp->lp, cr.rowcnt, cr.begin,
                                       cr.indices, cr.entries, weights);
                if (rval) {
                    fprintf (stderr, "CClp_getweight failed\n"); goto CLEANUP;
                }

                for (j = 0; j < cr.rowcnt; j++) {
                    t = cval[j] - 2.0;
                    down = (t * t) /  weights[j];
                    t = 4.0 - cval[j];
                    up = (t * t) / weights[j];
                    sval = TSP_BRANCH_STRONG_CUT_NORM_VAL (down, up);
                    insert_sblist (slist, sval, batch+j);
                }
                CCtsp_free_lprow (&cr);
                batch = i+1;
            }
        }

        for (i = 0, k = 0; i < nwant; i++) {
            if (slist[i].name != -1) {
                k++;
            }
        }
        if (k == 0) {
            printf ("WARNING: no candidate branching cliques were found\n");
            goto CLEANUP;
        }

        *list = CC_SAFE_MALLOC (k, CCtsp_lpclique);
        if (!(*list)) {
            fprintf (stderr, "out of memory in CCtsp_find_branch_cliques\n");
            rval = 1; goto CLEANUP;
        }
        for (i = 0, k = 0; i < nwant; i++) {
            if (slist[i].name != -1) {
                rval = CCtsp_copy_lpclique (&cliques[slist[i].name],
                                            &(*list)[k++]);
                if (rval) {
                    fprintf (stderr, "CCtsp_copy_clique failed\n");
                    for (i = 0; i < k; i++) {
                        CC_IFFREE ((*list)[i].nodes, CCtsp_segment);
                    }
                    CC_FREE (*list, CCtsp_lpclique);
                    goto CLEANUP;
                }
            }
         }
        *ngot = k;
    } else {
        *list = cliques;
        *ngot = ccount;
    }

CLEANUP:

    CCtsp_free_lprow (&cr);
    CC_IFFREE (slist, sbitem);
    CC_IFFREE (x, double);
    CC_IFFREE (xlist, int);
    CC_IFFREE (cval, double);
    CC_IFFREE (weights, double);
    if (use_getweight) {
        for (i = 0; i < ccount; i++) {
            CC_IFFREE (cliques[i].nodes, CCtsp_segment);
        }
        CC_IFFREE (cliques, CCtsp_lpclique);
    }

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_test_cut_branch (CCtsp_lp *lp, CCtsp_lpclique *c, double *down,
        double *up)
#else
int CCtsp_test_cut_branch (lp, c, down, up)
CCtsp_lp *lp;
CCtsp_lpclique *c;
double *up, *down;
#endif
{
    CCtsp_lprow cr;
    CCtsp_lpcut_in cu;
    int nzlist, status;
    CClpbasis basis;
    int rval = 0;

    *down = -CCtsp_LP_MAXDOUBLE;
    *up   = -CCtsp_LP_MAXDOUBLE;
    CCtsp_init_lprow (&cr);

    cu.handlecount = 0;
    cu.cliquecount = 1;
    cu.cliques = c;
    cu.next = (CCtsp_lpcut_in *) NULL;
    cu.prev = (CCtsp_lpcut_in *) NULL;
    cu.rhs  = 2;

    CClp_init_basis (&basis);
    rval = CClp_get_basis_and_norms (&lp->lp, &basis);
    if (rval) {
        fprintf (stderr, "CClp_get_basis_and_norms failed\n"); goto CLEANUP;
    }

    nzlist = CCtsp_lpcut_in_nzlist (&lp->graph, &cu);
    rval = CCtsp_add_nzlist_to_lp (lp, nzlist, 2, 'L', &cr);
    if (rval) {
        fprintf (stderr, "CCtsp_add_nzlist_to_lp failed\n"); goto CLEANUP;
    }
    rval = CCtsp_add_multiple_rows (lp, &cr);
    if (rval) {
        fprintf (stderr, "CCtsp_add_multiple_rows failed\n"); goto CLEANUP;
    }
    rval = CClp_limited_dualopt (&lp->lp, TSP_STRONG_CUT_ITER,
                                 &status, &lp->upperbound);
    if (rval) {
        fprintf (stderr, "CClp_limited_dualopt failed\n"); goto CLEANUP;
    }
    if (status == CClp_INFEASIBLE) {
        printf ("Down side of cut branch is infeasible\n"); fflush (stdout);
        *down = lp->upperbound;
    } else if (status == CClp_UNKNOWN) {
        printf ("Down side information is not avaiable\n"); fflush (stdout);
        *down = lp->lowerbound;
    } else {
        rval = CClp_objval (&lp->lp, down);
        if (rval) {
            fprintf (stderr, "CClp_objval failed\n"); goto CLEANUP;
        }
    }

    rval = CCtsp_delete_cut (lp, lp->cuts.cutcount);
    if (rval) {
        fprintf (stderr, "CCtsp_delete_cut failed\n"); goto CLEANUP;
    }
    rval = CClp_load_basis_and_norms (&lp->lp, &basis);
    if (rval) {
        fprintf (stderr, "CClp_load_basis_and_norms failed\n"); goto CLEANUP;
    }

    cr.sense[0] = 'G';
    cr.rhs[0] = 4.0;
    rval = CCtsp_add_multiple_rows (lp, &cr);
    if (rval) {
        fprintf (stderr, "CCtsp_add_multiple_rows failed\n"); goto CLEANUP;
    }
    rval = CClp_limited_dualopt (&lp->lp, TSP_STRONG_CUT_ITER, &status,
                                 &lp->upperbound);
    if (rval) {
        fprintf (stderr, "CClp_limited_dualopt failed\n"); goto CLEANUP;
    }
    if (status == CClp_INFEASIBLE) {
        printf ("Up side of cut branch is infeasible\n"); fflush (stdout);
        *up = lp->upperbound;
    } else if (status == CClp_UNKNOWN) {
        printf ("Up side information is not avaiable\n"); fflush (stdout);
        *up = lp->lowerbound;
    } else {
        rval = CClp_objval (&lp->lp, up);
        if (rval) {
            fprintf (stderr, "CClp_objval failed\n"); goto CLEANUP;
        }
    }

    rval = CCtsp_delete_cut (lp, lp->cuts.cutcount);
    if (rval) {
        fprintf (stderr, "CCtsp_delete_cut failed\n"); goto CLEANUP;
    }
    rval = CClp_load_basis_and_norms (&lp->lp, &basis);
    if (rval) {
        fprintf (stderr, "CClp_load_basis_and_norms failed\n"); goto CLEANUP;
    }
    rval = CClp_opt (&lp->lp, CClp_METHOD_DUAL);
    if (rval) {
        fprintf (stderr, "CClp_opt failed\n");
    }

CLEANUP:

    CClp_free_basis (&basis);
    CCtsp_free_lprow (&cr);
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_execute_branch (CCtsp_lp *lp, CCtsp_branchobj *b)
#else
int CCtsp_execute_branch (lp, b)
CCtsp_lp *lp;
CCtsp_branchobj *b;
#endif
{
    int n0      = -1;
    int n1      = -1;
    CCtsp_lpclique *c = (CCtsp_lpclique *) NULL;
    int rval    = 0;
    int i, j;

    if (!b) {
        fprintf (stderr, "CCtsp_execute_branch called without a CCtsp_branchobj\n");
        rval = 1; goto CLEANUP;
    }

    if (b->ends[0] != -1) {
        n0 = b->ends[0];
        n1 = b->ends[1];
        printf ("Branch Edge (%d,%d), to value %d\n", n0, n1, b->rhs);
        fflush (stdout);

        if (n0 >= lp->graph.ncount || n0 < 0 ||
            n1 >= lp->graph.ncount || n1 < 0) {
            fprintf (stderr, "CCtsp_execute_branch has invalid nodes\n");
            rval = 1; goto CLEANUP;
        }

        if (n0 > n1) {
            CC_SWAP (n0, n1, j);
        }

        j = CCtsp_find_edge (&lp->graph, n0, n1);
        if  (j < 0) {
            fprintf (stderr, "branching edge is not in the LP edgeset\n");
            rval = 1; goto CLEANUP;
        }
        if (lp->graph.edges[j].fixed) {
            fprintf (stderr, "branching edge is fixed to 1 in the LP\n");
            rval = 1; goto CLEANUP;
        }
        if (lp->graph.edges[j].branch) {
            fprintf (stderr, "branching edge has already been branched\n");
            rval = 1; goto CLEANUP;
        }

        if (b->rhs) {
            rval = CClp_setbnd (&lp->lp, j, 'L', 1.0);
            if (rval) {
                fprintf (stderr, "CClp_setbnd failed\n");
                rval = 1; goto CLEANUP;
            }
            lp->graph.edges[j].branch = lp->branchdepth + 1;
        } else {
            rval = CClp_setbnd (&lp->lp, j, 'U', 0.0);
            if (rval) {
                fprintf (stderr, "CClp_setbnd failed\n");
                rval = 1; goto CLEANUP;
            }
            lp->graph.edges[j].branch = -(lp->branchdepth + 1);
        }
    } else {
        CCtsp_lprow cr;
        CCtsp_lpcut_in d;

        if (!b->clique) {
            fprintf (stderr, "CCtsp_branchobj has no edge or clique\n");
            rval = 1; goto CLEANUP;
        }

        printf ("Branch Clique "); fflush (stdout);
        for (i = 0; i < b->clique->segcount; i++) {
            printf ("%d->%d ", b->clique->nodes[i].lo, b->clique->nodes[i].hi);
            fflush (stdout);
        }
        if (b->sense == 'G') {
            printf ("to at least %d\n", b->rhs);
        } else {
            printf ("to at most %d\n", b->rhs);
        }
        fflush (stdout);

        c = CC_SAFE_MALLOC (1, CCtsp_lpclique);
        if (!c) {
            fprintf (stderr, "out of memory in CCtsp_execute_branch\n");
            rval = 1; goto CLEANUP;
        }
        rval = CCtsp_copy_lpclique (b->clique, c);
        if (rval) {
            fprintf (stderr, "CCtsp_copy_lpclique failed\n");
            rval = 1; goto CLEANUP;
        }

        CCtsp_init_lpcut_in (&d);
        d.handlecount = 0;
        d.cliquecount = 1;
        d.rhs = b->rhs;
        d.sense = b->sense;
        d.branch = 1;
        d.cliques = c;

        CCtsp_init_lprow (&cr);
        rval = CCtsp_add_cut (lp, &d, &cr);
        if (rval) {
            fprintf (stderr, "CCtsp_add_cut failed\n");
            rval = 1; goto CLEANUP;
        }
        rval = CCtsp_add_multiple_rows (lp, &cr);
        if (rval) {
            fprintf (stderr, "CCtsp_add_multiple_rows failed\n");
            rval = 1; goto CLEANUP;
        }
        CCtsp_free_lprow (&cr);
        CCtsp_free_lpcut_in (&d);
    }

    rval = CClp_dualopt (&lp->lp);
    if (rval == 2) {
        rval = CCtsp_infeas_recover (lp);
        if (rval == 2) {
            printf ("Problem is really infeasible (CCtsp_execute_branch)\n");
            goto CLEANUP;
        } else if (rval) {
            fprintf (stderr, "CCtsp_infeas_recover failed\n");
            rval = 1; goto CLEANUP;
        }
    } else if (rval) {
        fprintf (stderr, "CClp_dualopt failed\n");
        rval = 1; goto CLEANUP;
    }

    rval = CCtsp_update_result (lp);
    if (rval) {
        fprintf (stderr, "CCtsp_update_result failed\n");
        rval = 1; goto CLEANUP;
    }
    CCtsp_free_bigdual (&lp->exact_dual);

CLEANUP:

    if (rval == 0 || rval == 2) {
        int sval = 0;
        sval = CCutil_reallocrus_count ((void **) &(lp->branchhistory),
                   lp->branchdepth + 1, sizeof (CCtsp_branchobj));
        if (sval) {
            fprintf (stderr, "CCutil_reallocrus_count failed\n"); return 1;
        }
        CCtsp_init_branchobj (&lp->branchhistory[lp->branchdepth]);
        lp->branchhistory[lp->branchdepth].depth   = lp->branchdepth + 1;
        lp->branchhistory[lp->branchdepth].ends[0] = n0;
        lp->branchhistory[lp->branchdepth].ends[1] = n1;
        lp->branchhistory[lp->branchdepth].rhs     = b->rhs;
        if (b->clique) {
            c = CC_SAFE_MALLOC (1, CCtsp_lpclique);
            if (!c) {
                fprintf (stderr, "out of memory in CCtsp_execute_branch\n");
                return 1;
            }
            sval = CCtsp_copy_lpclique (b->clique, c);
            if (sval) {
                fprintf (stderr, "CCtsp_copy_lpclique failed\n"); return 1;
            }
            lp->branchhistory[lp->branchdepth].clique = c;
        } else {
            lp->branchhistory[lp->branchdepth].clique = (CCtsp_lpclique *) NULL;
        }
        lp->branchhistory[lp->branchdepth].sense = b->sense;
        lp->branchdepth++;
    }
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_execute_unbranch (CCtsp_lp *lp, CClpbasis *basis)
#else
int CCtsp_execute_unbranch (lp, basis)
CCtsp_lp *lp;
CClpbasis *basis;
#endif
{
    int rval = 0;
    int n0, n1;
    int num;
    int depth = lp->branchdepth;
    CCtsp_branchobj *b;
    int j;

    if (depth <= 0) {
        fprintf (stderr, "CCtsp_execute_unbranch called at depth 0\n");
        rval = 1; goto CLEANUP;
    }

    if (lp->branchhistory[depth - 1].depth != depth) {
        fprintf (stderr, "branchhistory is corrupted\n");
        rval = 1; goto CLEANUP;
    }
    b = &lp->branchhistory[depth - 1];

    if (lp->branchhistory[depth - 1].ends[0] != -1) {
        n0    = b->ends[0];
        n1    = b->ends[1];
        printf ("Unbranch Edge (%d,%d), from value %d\n", n0, n1, b->rhs);
        fflush (stdout);

        if (n0 > n1) {
            CC_SWAP (n0, n1, j);
        }

        j = CCtsp_find_edge (&lp->graph, n0, n1);
        if  (j < 0) {
            fprintf (stderr, "ERROR: unbranching 1-edge is not in LP\n");
            rval = 1; goto CLEANUP;
        }
        if (b->rhs) {
            if (lp->graph.edges[j].branch <= 0) {
                fprintf (stderr, "unbranching 1-edge not branched to 1\n");
                rval = 1; goto CLEANUP;
            }
            rval = CClp_setbnd (&lp->lp, j, 'L', 0.0);
            if (rval) {
                fprintf (stderr, "CClp_setbnd failed\n"); goto CLEANUP;
            }
        } else {
            if (lp->graph.edges[j].branch >= 0) {
                fprintf (stderr, "unbranching 0-edge not branched to 0\n");
                rval = 1; goto CLEANUP;
            }

            rval = CClp_setbnd (&lp->lp, j, 'U', 1.0);
            if (rval) {
                fprintf (stderr, "CClp_setbnd failed\n"); goto CLEANUP;
            }
        }
        lp->graph.edges[j].branch = 0;
    } else {
        if (!b->clique) {
            fprintf (stderr, "branchhistory has no edge or clique\n");
            rval = 1; goto CLEANUP;
        }
        rval = find_branched_clique (lp, b->clique, b->sense, b->rhs, &num);
        if (rval) {
            fprintf (stderr, "find_branched_clique failed\n");
            goto CLEANUP;
        }
        printf ("The unbranching clique is cut %d\n", num); fflush (stdout);
        if (lp->cuts.cuts[num].branch == 0) {
            fprintf (stderr, "the unbranching clique is not set to branch\n");
            rval = 1; goto CLEANUP;
        }

        {
            int q;
            CCtsp_lpcut *cu = &lp->cuts.cuts[num];
            CCtsp_lpclique *t;

            printf ("Sense: %c  RHS: %d  Cliques: %d  Branch: %d\n",
                 cu->sense, cu->rhs, cu->cliquecount, cu->branch);
            t = &lp->cuts.cliques[cu->cliques[0]];
            printf ("Clique: ");
            for (q = 0; q < t->segcount; q++) {
                printf ("%d->%d ", t->nodes[q].lo, t->nodes[q].hi);
            }
            printf ("\n"); fflush (stdout);
        }

        if (!basis) {
            CClp_pivotin (&lp->lp, lp->graph.ncount + num);
        }
        rval = CCtsp_delete_cut (lp, num);
        if (rval) {
            fprintf (stderr, "CCtsp_delete_cut failed\n"); goto CLEANUP;
        }
        CCtsp_delete_cut_from_cutlist (&lp->cuts, num);
    }

    if (basis) {
        rval = CClp_load_basis_and_norms (&lp->lp, basis);
        if (rval) {
            fprintf (stderr, "CClp_load_basis_and_norms failed\n");
            goto CLEANUP;
        }
    }

    rval = CClp_dualopt (&lp->lp);
    if (rval == 2) {
        fprintf (stderr, "infeasible lp in CCtsp_execute_unbranch\n");
        goto CLEANUP;
    } else if (rval) {
        fprintf (stderr, "CClp_dualopt failed\n"); goto CLEANUP;
    }

    rval = CCtsp_update_result (lp);
    if (rval) {
        fprintf (stderr, "CCtsp_update_result failed\n"); goto CLEANUP;
    }
    CCtsp_free_bigdual (&lp->exact_dual);

CLEANUP:

    if (!rval) {
        CCtsp_free_branchobj (&lp->branchhistory[lp->branchdepth - 1]);
        lp->branchdepth--;
    }
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_add_branchhistory_to_lp (CCtsp_lp *lp)
#else
int CCtsp_add_branchhistory_to_lp (lp)
CCtsp_lp *lp;
#endif
{
    int i, k, num;
    int rval = 0;
    CCtsp_branchobj *b;

    for (i = 0; i < lp->branchdepth; i++) {
        b = &lp->branchhistory[i];
        if (b->ends[0] != -1) {
            k = CCtsp_find_edge (&lp->graph, b->ends[0], b->ends[1]);
            if (k == -1) {
                fprintf (stderr, "edge in branch history is not in LP\n");
                rval = 1; goto CLEANUP;
            }
            if (lp->graph.edges[k].fixed || lp->graph.edges[k].branch) {
                fprintf (stderr, "edge in branch history is fixed/branched\n");
                rval = 1; goto CLEANUP;
            }
            if (b->rhs) {
                rval = CClp_setbnd (&lp->lp, k, 'L', 1.0);
                if (rval) {
                    fprintf (stderr, "CClp_setbnd failed\n"); goto CLEANUP;
                }
                lp->graph.edges[k].branch = b->depth;
            } else {
                rval = CClp_setbnd (&lp->lp, k, 'U', 0.0);
                if (rval) {
                    fprintf (stderr, "CClp_setbnd failed\n"); goto CLEANUP;
                }
                lp->graph.edges[k].branch = -(b->depth);
            }
        } else {
            rval = find_branched_clique (lp, b->clique, b->sense,
                                             b->rhs, &num);
            if (rval) {
                fprintf (stderr, "find_branch_clique failed\n");
                goto CLEANUP;
            }
            lp->cuts.cuts[num].branch = 1;
        }
    }

CLEANUP:

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static int find_branched_clique (CCtsp_lp *lp, CCtsp_lpclique *c, char sense,
        int rhs, int *cutnum)
#else
static int find_branched_clique (lp, c, sense, rhs, cutnum)
CCtsp_lp *lp;
CCtsp_lpclique *c;
char sense;
int rhs;
int *cutnum;
#endif
{
    int i;
    CCtsp_lpcut *cu;
    CCtsp_lpcut *cuts       = lp->cuts.cuts;
    CCtsp_lpclique *cliques = lp->cuts.cliques;
    int cutcount      = lp->cuts.cutcount;
    int diff = 0;

    *cutnum = -1;

    for (i = 0; i < cutcount; i++) {
        cu = &cuts[i];
        if (cu->cliquecount == 1 &&
            cu->sense == sense && cu->rhs == rhs) {
            CCtsp_lpclique_compare (&cliques[cu->cliques[0]], c, &diff);
            if (!diff) {
                *cutnum = i; return 0;
            }
        }
    }

    fprintf (stderr, "did not find branched clique\n");
    return 1;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_bb_find_branch (char *probname, int probnum, int ncount,
         CCdatagroup *dat, int *ptour, double *upperbound, CCtsp_lpcuts *pool,
         CCtsp_branchobj **b, int usecliques, int *foundtour, int *besttour)
#else
int CCtsp_bb_find_branch (probname, probnum, ncount, dat, ptour, upperbound,
         pool, b, usecliques, foundtour, besttour)
char *probname;
int probnum;
int ncount;
CCdatagroup *dat;
int *ptour;
double *upperbound;
CCtsp_lpcuts *pool;
CCtsp_branchobj **b;
int usecliques;
int *foundtour;
int *besttour;
#endif
{
    int rval = 0;
    double tval;
    CCtsp_lp *lp = (CCtsp_lp *) NULL;
    int *cyc = (int *) NULL;
    int i, ngot, test;

    *foundtour = 0;
    *b = (CCtsp_branchobj *) NULL;

    rval = CCtsp_bb_init_lp (&lp, probname, probnum, ncount, dat, ptour,
               *upperbound, pool);
    if (rval) {
        fprintf (stderr, "CCtsp_bb_init_lp failed\n"); goto CLEANUP;
    }

    rval = CCtsp_find_branch (lp, 1, &ngot, b, &tval, &cyc, usecliques);
    if (rval) {
        fprintf (stderr, "CCtsp_find_branch failed\n");
        goto CLEANUP;
    }

    if (ngot == 0) {
        printf ("No branch, found tour of value %.2f\n", tval);
        fflush (stdout);
        if (tval < lp->upperbound) lp->upperbound = tval;
        rval = CCtsp_verify_lp_prune (lp, &test);
        if (rval) {
            fprintf (stderr, "CCtsp_verify_lp_prune failed\n");
            goto CLEANUP;
        }
        if (test) {
            printf ("verified that LP can now be pruned\n"); fflush (stdout);
            *foundtour = 1;
            if (tval < *upperbound) {
                *upperbound = tval;
                if (besttour) {
                    for (i = 0; i < ncount; i++) {
                        besttour[i] = cyc[i];
                    }
                }
            }
            goto CLEANUP;
        } else {
            fprintf (stderr, "new tour did not permit exact pruning\n");
            rval = 1; goto CLEANUP;
        }
    } else {
        printf ("found branch\n"); fflush (stdout);
    }


CLEANUP:

    if (lp) CCtsp_free_tsp_lp_struct (&lp);
    CC_IFFREE (cyc, int);
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_bb_splitprob (char *probname, int probnum, int ncount,
         CCdatagroup *dat, int *ptour, double initial_ub, CCtsp_lpcuts *pool,
         CCtsp_branchobj *b, int child0, int child1, double *val0, double *val1,
         int *prune0, int *prune1)
#else
int CCtsp_bb_splitprob (probname, probnum, ncount, dat, ptour, initial_ub,
         pool, b, child0, child1, val0, val1, prune0, prune1)
char *probname;
int probnum;
int ncount;
CCdatagroup *dat;
int *ptour;
double initial_ub;
CCtsp_lpcuts *pool;
CCtsp_branchobj *b;
int child0, child1;
double *val0, *val1;
int *prune0, *prune1;
#endif
{
    int rval = 0;
    CCtsp_lp *lp = (CCtsp_lp *) NULL;

    *val0 = 0.0;
    *val1 = 0.0;
    *prune0 = 0;
    *prune1 = 0;

    rval = CCtsp_bb_init_lp (&lp, probname, probnum, ncount, dat, ptour,
               initial_ub, pool);
    if (rval) {
        fprintf (stderr, "CCtsp_bb_init_lp failed\n"); goto CLEANUP;
    }

    rval = branch_side (lp, b, 0, child0, val0, prune0);
    if (rval) {
        fprintf (stderr, "branch_side failed\n"); goto CLEANUP;
    }

    CCtsp_free_tsp_lp_struct (&lp);
    rval = CCtsp_bb_init_lp (&lp, probname, probnum, ncount, dat, ptour,
               initial_ub, pool);
    if (rval) {
        fprintf (stderr, "CCtsp_bb_init_lp failed\n"); goto CLEANUP;
    }

    rval = branch_side (lp, b, 1, child1, val1, prune1);
    if (rval) {
        fprintf (stderr, "branch_side failed\n"); goto CLEANUP;
    }


CLEANUP:

    if (lp) CCtsp_free_tsp_lp_struct (&lp);
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static int branch_side (CCtsp_lp *lp, CCtsp_branchobj *b, int side, int child,
        double *val, int *prune)
#else
static int branch_side (lp, b, side, child, val, prune)
CCtsp_lp *lp;
CCtsp_branchobj *b;
int side;
int child;
double *val;
int *prune;
#endif
{
    int rval = 0;
    int oldid       =  lp->id;
    int oldparent   =  lp->parent_id;
    double oldbound = lp->lowerbound;
    double newbound;
    int test;

    *val = 0.0;
    *prune = 0;

    if (b->ends[0] != -1) {
        printf ("Creating child %d of LP %d: Set Edge (%d, %d) to %d\n",
                         side, lp->id, b->ends[0], b->ends[1], side);
        if (side == 0) {
            b->rhs = 0;
        } else {
            b->rhs = 1;
        }
    } else {
        if (side == 0) {
            printf ("Creating child 0 of LP %d: Set Clique <= 2\n", lp->id);
            b->rhs = 2; b->sense = 'L';
        } else {
            printf ("Creating child 1 of LP %d: Set Clique >= 4\n", lp->id);
            b->rhs = 4; b->sense = 'G';
        }
    }
    fflush (stdout);

    rval = CCtsp_execute_branch (lp, b);
    if (rval && rval != 2) {
        fprintf (stderr, "CCtsp_execute_branch failed\n"); goto CLEANUP;
    } else if (rval == 2) {
        printf ("Branched-LP is infeasible\n"); fflush (stdout);
        rval = CCtsp_verify_infeasible_lp (lp, &test);
        if (rval) {
            fprintf (stderr, "CCtsp_verify_infeasible_lp failed\n");
            goto CLEANUP;
        }
        if (test) {
            printf ("Do not creat child node - infeasible\n"); fflush (stdout);
            /* for proof mode, write the infeasible LP here */
            *val = CCtsp_LP_MAXDOUBLE;
            *prune = 1;
            rval = 0;
        } else {
            fprintf (stderr, "did not verify an infeasible LP\n");
            rval = 1; goto CLEANUP;
        }
    } else {
        rval = CCtsp_pricing_loop (lp, &newbound);
        if (rval) {
            fprintf (stderr, "CCtsp_pricing_loop\n"); goto CLEANUP;
        }
        *val = newbound;
        lp->lowerbound = newbound;

        if (lp->lowerbound >= lp->upperbound - 0.9) {
            rval = CCtsp_verify_lp_prune (lp, &test);
            if (rval) {
                fprintf (stderr, "CCtsp_verify_lp_prune failed\n");
                goto CLEANUP;
            }
            if (test) {
                printf ("verified that child can be pruned\n"); fflush (stdout);
                *prune = 1;  /* for proof mode, write the lp file here */
            } else {
                fprintf (stderr, "exact pricing could not prune child\n");
                rval = 1; goto CLEANUP;
            }
        } else {
            lp->parent_id = oldid;
            lp->id = child;
            rval = CCtsp_write_probfile_id (lp);
            if (rval) {
                fprintf (stderr, "CCtsp_write_probfile_id failed\n");
                goto CLEANUP;
            }
            lp->parent_id = oldparent;
            lp->id = oldid;
        }
        lp->lowerbound = oldbound;
    }

CLEANUP:

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_splitprob (CCtsp_lp *lp, CCtsp_branchobj *b, int child0, int child1)
#else
int CCtsp_splitprob (lp, b, child0, child1)
CCtsp_lp *lp;
CCtsp_branchobj *b;
int child0, child1;
#endif
{
    int oldid     =  lp->id;
    int oldparent =  lp->parent_id;
    CClpbasis basis;
    int rval = 0;

    CClp_init_basis (&basis);
    rval = CClp_get_basis_and_norms (&lp->lp, &basis);
    if (rval) {
        fprintf (stderr, "CClp_get_basis_and_norms failed\n"); goto CLEANUP;
    }

    lp->parent_id = lp->id;

    if (b->ends[0] != -1) {
        b->rhs = 0;
    } else {
        b->rhs = 2;
        b->sense = 'L';
    }

    lp->id = child0;
    rval = CCtsp_execute_branch (lp, b);
    if (rval == 2) {
        rval = 0;
        printf ("The down side of the branch was infeasible\n");
        fflush (stdout);
    } else if (rval) {
        fprintf (stderr, "CCtsp_execute_branch failed\n"); goto CLEANUP;
    }
    rval = CCtsp_write_probfile_id (lp);
    if (rval) {
        fprintf (stderr, "CCtsp_write_probfile_id failed\n"); goto CLEANUP;
    }
    rval = CCtsp_execute_unbranch (lp, &basis);
    if (rval) {
        fprintf (stderr, "CCtsp_execute_unbranch failed\n"); goto CLEANUP;
    }

    if (b->ends[0] != -1) {
        b->rhs = 1;
    } else {
        b->rhs = 4;
        b->sense = 'G';
    }

    lp->id = child1;
    rval = CCtsp_execute_branch (lp, b);
    if (rval == 2) {
        rval = 0;
        printf ("The up side of the branch was infeasible\n");
        fflush (stdout);
    } else if (rval) {
        fprintf (stderr, "CCtsp_execute_branch failed\n"); goto CLEANUP;
    }
    rval = CCtsp_write_probfile_id (lp);
    if (rval) {
        fprintf (stderr, "CCtsp_write_probfile_id failed\n"); goto CLEANUP;
    }
    rval = CCtsp_execute_unbranch (lp, &basis);
    if (rval) {
        fprintf (stderr, "CCtsp_execute_unbranch failed\n"); goto CLEANUP;
    }


CLEANUP:

    CClp_free_basis (&basis);
    lp->parent_id = oldparent;
    lp->id = oldid;

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_dumptour (int ncount, CCdatagroup *dat, int *perm, char *probname,
        int *tour)
#else
int CCtsp_dumptour (ncount, dat, perm, probname, tour)
int ncount;
CCdatagroup *dat;
int *perm;
char *probname;
int *tour;
#endif
{
    int rval = 0;
    int *cyc = (int *) NULL;
    int i;
    double len = 0.0;
    char buf[1024];

    if (!perm || !tour) {
        fprintf (stderr, "bad input for CCtsp_dumptour\n");
        rval = 1; goto CLEANUP;
    }

    sprintf (buf, "%s.sol", probname);
    cyc = CC_SAFE_MALLOC (ncount, int);
    if (!cyc) {
        fprintf (stderr, "out of memory in CCtsp_dumptour\n");
        rval = 1; goto CLEANUP;
    }

    for (i = 0; i < ncount; i++) {
        cyc[i] = 0;
    }
    for (i = 0; i < ncount; i++) {
        cyc[tour[i]] = 1;
    }
    for (i = 0; i < ncount; i++) {
        if (cyc[i] == 0) {
            fprintf (stderr, "array is not a tour in CCtsp_dumptour\n");
            rval = 1; goto CLEANUP;
        }
    }
    for (i = 0; i < ncount; i++) {
        cyc[i] = perm[tour[i]];
    }

    if (dat) {
        for (i = 1; i < ncount; i++) {
            len += (double) CCutil_dat_edgelen (tour[i-1], tour[i], dat);
        }
        len += (double) CCutil_dat_edgelen (tour[ncount-1], tour[0], dat);
        printf ("Write tour of length %.2f to %s\n", len, buf);
        fflush (stdout);
    } else {
        printf ("Write tour to %s\n", buf);
        fflush (stdout);
    }

    rval = CCutil_writecycle (ncount, buf, cyc);
    if (rval) {
        fprintf (stderr, "writecycle failed\n"); goto CLEANUP;
    }

CLEANUP:

    CC_IFFREE (cyc, int);
    return rval;
}
