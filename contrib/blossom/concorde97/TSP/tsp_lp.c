/***************************************************************************/
/*                                                                         */
/*            ROUTINES TO BUILD LPS AND CALL THE LP SOLVER                 */
/*                                                                         */
/*                           TSP CODE                                      */
/*                                                                         */
/*                                                                         */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook                       */
/*  Date: September 26, 1995                                               */
/*                                                                         */
/*                                                                         */
/*  EXPORTED FUNCTIONS:                                                    */
/*    void CCtsp_init_tsp_lp_struct (CCtsp_lp *lp)                         */
/*     INITIALIZES the CCtsp_lp struture with NULL values                  */
/*                                                                         */
/*    int CCtsp_init_lp (CCtsp_lp **lp, char *probname, int probnum,       */
/*           char *probfilename, int ncount, CCdatagroup *dat, int ecount, */
/*           int *elist, int *elen, int excount, int *exlist, int *exlen,  */
/*           int exvalid, int *ptour, double initial_ub,                   */
/*           CCtsp_lpcuts *pool)                                           */
/*     BUILDS/READS the problem, and loads it into the LP solver. If       */
/*      probnum < 0, init_lp will build an initial problem according to    */
/*      edgegengroup; otherwise it will read the problem from disk. If     */
/*      the problem is read from disk, then the elist is ignored.          */
/*      -lp is a handle to the tsp lp (filled in by init_lp)               */
/*      -probname is the name for the problem                              */
/*      -probnum is the number for the problem                             */
/*      -ncount is the number of nodes                                     */
/*      -dat is a handle on the complete graph                             */
/*      -plan says how to generate an initial edgeset                      */
/*      -ecount, elist, elen specify an initial edge set (they can be      */
/*       0, NULL, NULL); if a prob is read from a file, then this list     */
/*       is ignored                                                        */
/*      -excount, exlist, exlen specify an full edge set (they can be      */
/*       0, NULL, NULL); if the probfile already has an full edge set,     */
/*       then this values are ignored.                                     */
/*      -exvalid indicates whether or not the edges specified in exlist    */
/*       are a valid complete set of edges (0 no, 1 yes)                   */
/*      -pool is a pointer to a cutpool (can be NULL)                      */
/*     NOTE: If init_lp returns 2, then the LP is infeasible (even after   */
/*      considering the full edge set).                                    */
/*                                                                         */
/*    int CCtsp_bb_init_lp (CCtsp_lp **lp, char *probname, int probnum,    */
/*            int ncount, CCdatagroup *dat, int *ptour, double initial_ub, */
/*            CCtsp_lpcuts *pool)                                          */
/*      SHORT form of CCtsp_init_lp for use in the branch and bound.       */
/*                                                                         */
/*    int CCtsp_get_lp_result (CCtsp_lp *lp, double *lb, double *ub,       */
/*            int *ecount, int **elist, double **x, double **rc,           */
/*            double **node_pi, double **cut_pi)                           */
/*     RETURNS a copy of the values cached in lp->result. However, it      */
/*      allows a single point of locking for the threaded version. Any     */
/*      return argument can be NULL.                                       */
/*      -lp is a pointer to the tsp lp                                     */
/*      -obj returns the location for the current objective value          */
/*      -ecount returns the location for the number of nonzero edges       */
/*      -elist returns the  location for the nonzero edges in end1 end2    */
/*       format                                                            */
/*      -x returns location for the edge values                            */
/*      -rc returns location for the edge values                           */
/*      -node_pi returns the values on the degree constraints              */
/*      -cut_pi returns the dual values on the cuts                        */
/*     NOTE: node_pi and cut_pi go to the LP to fetch the results.         */
/*                                                                         */
/*    int CCtsp_add_cut (CCtsp_lp *lp, CCtsp_lpcut_in *d, CCtsp_lprow *cr) */
/*     ADDS cut d to the lp structure and to cr (a call to                 */
/*      CCtsp_add_multiple will put the cut into the lp solver)            */
/*                                                                         */
/*    int CCtsp_add_multiple_rows (CCtsp_lp *lp, CCtsp_lprow *cr)          */
/*     HANDS the cuts in cr to the lp solver.                              */
/*                                                                         */
/*    void CCtsp_add_cuts_to_queue (CCtsp_lp *lp, CCtsp_lpcut_in **clist)  */
/*     ADDS clist to the queue of cuts to be processed by the lp solver;   */
/*      clist will be set to NULL                                          */
/*      -lp is a pointer to the tsp lp                                     */
/*      -clist is the head of a NULL terminated linked list of cuts        */
/*                                                                         */
/*    int CCtsp_add_cut_to_cutlist (CCtsp_lpcuts *cuts, CCtsp_lpcut *c)    */
/*                                                                         */
/*    void CCtsp_delete_cut_from_cutlist (CCtsp_lpcuts *cuts, int ind)     */
/*                                                                         */
/*    int CCtsp_process_cuts (CCtsp_lp *lp, int *pnadded, int tighten)     */
/*      -lp is a pointer to the tsp lp                                     */
/*      -pnadded returns the location for the number of cuts added         */
/*      -tighten is a flag to indicate whether or not the tighten routine  */
/*       should be called for each cut before it is added to the LP        */
/*     NOTE: process_cuts runs through all the cuts in the queue;          */
/*      process_cuts also calls add_to_cutpool(). If process_cuts          */
/*      returns 2, then the LP is infeasible, even after considering the   */
/*      full edge set.                                                     */
/*                                                                         */
/*    int CCtsp_addbad_variables (CCtsp_lp *lp, struct edgegenerator *eg,  */
/*            double *ppenalty, int *pnadded, double rcthresh,             */
/*            double maxpenalty, int phase1, int *feasible)                */
/*     ADDS negative reduced cost edges to the LP; if phase1 is nonzero    */
/*      then the added edges attempt to make a feasible LP (in this        */
/*      case the eg variable is ignored and the edges are taked either     */
/*      from fulladj (if they are valid) or from dat)                      */
/*      -lp is a pointer to the tsp lp                                     */
/*      -eg is a generator for the edges to check                          */
/*      -ppenalty is the penalty from the last pass of pricing             */
/*      -pnadded is the number of negative reduced cost edges added        */
/*      -rcthresh is the threshold on the reduced cost of edges to be      */
/*       added (it should be something <= 0.0)                             */
/*      -maxpenalty is the maximum sum of penalties that is permitted      */
/*       before the rounds of pricing stop                                 */
/*      -phase1 should be 0 for normal column generation, and nonzero      */
/*       to try to fix an infeasible LP                                    */
/*      -feasible can be NULL, otherwise it is set to 1 if phase 1         */
/*       gets to a feasible LP and 0 if the LP really is infeasible        */
/*                                                                         */
/*    int CCtsp_eliminate_variables (CCtsp_lp *lp)                         */
/*     SETS edges to 0 or 1 if possible, based on reduced costs            */
/*      -lp is a pointer to the tsp lp                                     */
/*                                                                         */
/*    double CCtsp_cutprice (CCtsp_lpgraph *g, CCtsp_lpcut_in *c,          */
/*            double *x)                                                   */
/*     RETURNS the slack of cut c                                          */
/*      -g is a pointer to an CCtsp_lpgraph that matches the vector x      */
/*                                                                         */
/*    int CCtsp_add_vars_to_lp (CCtsp_lp *lp, CCtsp_predge *prlist, int n) */
/*     ADDS the columns to the lp.                                         */
/*      -n the number of edges listed in prlist                            */
/*                                                                         */
/*    int CCtsp_update_result (CCtsp_lp *lp)                               */
/*     UPDATES the solution information in the lp structure                */
/*                                                                         */
/*    int CCtsp_infeas_recover (CCtsp_lp *lp)                              */
/*     TRIES to add columns to lp to regain feasibiblity                   */
/*     NOTE: Returns 2 if the full lp is infeasible                        */
/*                                                                         */
/*    int CCtsp_build_lpgraph (CCtsp_lpgraph *g, int ncount,               */
/*            int ecount, int *elist, int *elen)                           */
/*     BUILDS the node and edge lists for the CCtsp_lpgraph pointed by g.  */
/*      -elen contains the edge lengths (it can be NULL, in which case     */
/*       the lengths are set to 0).                                        */
/*                                                                         */
/*    int CCtsp_build_lpadj (CCtsp_lpgraph *g, int estart, int eend)       */
/*     BUILDS the incidence list for the graph *g                          */
/*      -estart is the index of the first edge to include in the list      */
/*      -eend is the index of the last edge + 1                            */
/*                                                                         */
/*    void CCtsp_init_lpgraph_struct (CCtsp_lpgraph *g)              */
/*     INITIALIZES the CCtsp_lpgraph struct pointed to by g.               */
/*                                                                         */
/*    void CCtsp_free_lpgraph (CCtsp_lpgraph *g)                     */
/*     FREES the fields in the CCtsp_lpgraph pointed to by g.              */
/*                                                                         */
/*    void CCtsp_free_lpcut_in (CCtsp_lpcut_in *c)                         */
/*     FREES the fields in the CCtsp_lpcut pointed to by c.                */
/*                                                                         */
/*    CCtsp_free_lpclique (CCtsp_lpclique *c)                              */
/*     FREES the fields in the CCtsp_lpclique pointed to by c.             */
/*                                                                         */
/*    int CCtsp_register_cliques (CCtsp_lpcuts *cuts, CCtsp_lpcut_in *c,   */
/*            CCtsp_lpcut *new)                                            */
/*     BUILDS the references to the cliques in c into the cut strucure     */
/*     pointed to by cuts and creates an array of the indices of the       */
/*     the cliques in CCtsp_lpcut new                                      */
/*      -cuts is the structure holding the set of cuts                     */
/*      -c describes the cut to be added to the structure                  */
/*      -new returns the array of clique indices                           */
/*                                                                         */
/*    void CCtsp_unregister_cliques (CCtsp_lpcuts *cuts, CCtsp_lpcut *c)   */
/*     REMOVES the references to the cliques in cut c (and deletes the     */
/*      cliques if they have no more references) and frees the array       */
/*      of clique indices in c                                             */
/*      -cuts is the structure holding the set of cuts                     */
/*      -c is the cut containing the cliques to be removed                 */
/*                                                                         */
/*    int CCtsp_inspect_full_edges (CCtsp_lp *lp)                          */
/*     CHECKS that full edge set contains the current LP edge set; it      */
/*      returns 0 if it is okay and 1 if some edge is not present          */
/*      -lp is the CCtsp_lp                                                */
/*                                                                         */
/*    int CCtsp_read_probfile (CCtsp_lp *lp, char *fname, int ncount)      */
/*     READS a tsp file and loads the results into lp                      */
/*      -lp is an initialized lp (via a call to init_tsp_lp_struct; the    */
/*       results are returned in this struct                               */
/*      -fname is the tsp file                                             */
/*      -ncount is the number of nodes; it is used as a check to see if    */
/*       if the tsp file matches                                           */
/*                                                                         */
/*    int CCtsp_read_probfile_id (CCtsp_lp *lp, char *fname, int id,       */
/*            int ncount)                                                  */
/*     READS a tsp file and loads the results into lp, where the filename  */
/*      is obtained by using the id.                                       */
/*                                                                         */
/*    int CCtsp_dump_x (CCtsp_lp *lp, char *fname)                         */
/*     WRITES the lp solution to fname.                                    */
/*     Note: The vector contains the original node names.                  */
/*                                                                         */
/*                                                                         */
/***************************************************************************/

/*
Known TODO:
espace
make sure all seg loops are <=
change CCtsp_lpadj strategy - graph always complete graph, except for
   build_lp_cols

Remark:
  Sparified cut is viewed as cut + CCtsp_sparser*stars (ie, a positive value
  in the CCtsp_sparser means that the cut in the lp is the original cut + the
  star for that node
*/


#include "machdefs.h"
#include "util.h"
#include "macrorus.h"
#include "fmatch.h"
#include "edgegen.h"
#include "linkern.h"
#include "tsp.h"
#include "lp.h"
#include "bigguy.h"
#include "cut.h"

/*
   parameters for addbad_variables.  Addbad generates edges (x,y) with
   len(x,y) - pi_ub[x] - pi_ub[y] < 0 in chunks of PRICE_GEN, computes
   rc for that chunk, and adds those with rc(x,y) < CCtsp_PRICE_RCTHRESH to the
   pool.  This continues until the pool contains more than PRICE_POOL edges,
   at which point the worst PRICE_ADD edges are added to the lp, new reduced
   are computed for the pool, and only edges with rc(x,y) <
    CCtsp_PRICE_RCTHRESH are retained.  This overall process continues until
   the total penalty for a full pass through the edges without adding any is
   < CCtsp_PRICE_MAXPENALTY.
*/

/* Some of these should probably depend on the problem size */

#define REALLOC_FACTOR    1.25
#define PRICE_GEN         20000
#define PRICE_GEN_FACTOR  3
#define PRICE_POOL        1000     /* 10000 */
#define PRICE_ADD         100

#ifdef CC_PROTOTYPE_ANSI

static int
    first_lp (CCtsp_lp *lp, char *probname, int ncount, int ecount, int *elist,
        int *elen),
    find_edge_full (CCtsp_lp *lp, int from, int to),
    load_lp (CCtsp_lp *lp),
    build_lp_cols (CCtsp_lpgraph *g, CCtsp_lpcuts *cuts, int estart, int eend,
        int *pnzcnt, double **pobj, int **pmatbeg, int **pmatcnt,
        int **pmatind, double **pmatval, double **plb, double **pub),
    tsp_lpcut_nzlist (CCtsp_lpgraph *g, CCtsp_lpcut *c,
        CCtsp_lpclique *cliques),
    checkout_cut (CCtsp_lp *lp, CCtsp_lpcut_in *c, double *x, CCtsp_lprow *cr,
        int tighten),
    verify_lpcut_in (CCtsp_lpgraph *g, CCtsp_lpcut_in *d),
    update_newcuts (CCtsp_lp *lp),
    phase1_test_edge (int end1, int end2, double *node_piest),
    phase1_generate_edges (CCtsp_lp *lp, double *node_piest, int nwant,
        int *ngot, int *genlist, int *genlen, int start, int *ni, int *nj,
        int *finished),
    pricing_duals (CCtsp_lp *lp, double *node_pi,
        double *node_piest, double *cut_pi, double *clique_pi),
    price_list (CCtsp_lp *lp, int ecount, CCtsp_predge *elist,
        double *node_pi, double *clique_pi, int phase1),
    age_cuts (CCtsp_lp *lp, int *ndeleted),
    age_edges (CCtsp_lp *lp, int *ndeleted),
    get_pi (CCtsp_lp *lp, double *node_pi, double *cut_pi),
    addrow_to_list (int nzcnt, double drhs, char sense,
        int *rmatind, double *rmatval, CCtsp_lprow *cr),
    lp_addcols (CCtsp_lp *lp, int ncols, int nzcnt,
        double *obj, int *matbeg, int *matind, double *matval,
        double *lb, double *ub),
    lp_delete_cut_set (CCtsp_lp *lp, int *del),
    lp_delete_var_set (CCtsp_lp *lp, int *del),
    write_probfile (CCtsp_lp *lp, int saveit),
    read_probfile (CCtsp_lp *lp, CCtsp_PROB_FILE *p, int ncount);

static void
    tsp_lpcut_nonzero_work (CCtsp_lpgraph *g, CCtsp_lpclique *c, int *pnzlist),
    tsp_lpcut_nonzero_modify (CCtsp_lpgraph *g, int modcount,
        CCtsp_sparser *mods, int *pnzlist),
    clear_nzlist (CCtsp_lpgraph *g, int nzlist),
    pr_select (int nsel, int n, CCtsp_predge *list),
    add_cut_to_queue (CCtsp_lp *lp, CCtsp_lpcut_in *c);

#else  /* CC_PROTOTYPE_ANSI */

static int
    first_lp (),
    find_edge_full (),
    load_lp (),
    build_lp_cols (),
    tsp_lpcut_nzlist (),
    checkout_cut (),
    verify_lpcut_in (),
    update_newcuts (),
    phase1_test_edge (),
    phase1_generate_edges (),
    pricing_duals (),
    price_list (),
    age_cuts (),
    age_edges (),
    get_pi (),
    addrow_to_list (),
    lp_addcols (),
    lp_delete_cut_set (),
    lp_delete_var_set (),
    write_probfile (),
    read_probfile ();

static void
    tsp_lpcut_nonzero_work (),
    tsp_lpcut_nonzero_modify (),
    clear_nzlist (),
    pr_select (),
    add_cut_to_queue ();

#endif /* CC_PROTOTYPE_ANSI */


#ifdef CC_PROTOTYPE_ANSI
int CCtsp_bb_init_lp (CCtsp_lp **lp, char *probname, int probnum, int ncount,
        CCdatagroup *dat, int *ptour, double initial_ub, CCtsp_lpcuts *pool)
#else
int CCtsp_bb_init_lp (lp, probname, probnum, ncount, dat, ptour, initial_ub,
        pool)
CCtsp_lp **lp;
char *probname;
int probnum;
int ncount;
CCdatagroup *dat;
int *ptour;
double initial_ub;
CCtsp_lpcuts *pool;
#endif
{
    return CCtsp_init_lp (lp, probname, probnum, (char *) NULL,
                  ncount, dat,
                  0, (int *) NULL, (int *) NULL,       /* elist  */
                  0, (int *) NULL, (int *) NULL, 0,    /* exlist */
                  ptour, initial_ub, pool);
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_init_lp (CCtsp_lp **lp, char *probname, int probnum,
        char *probfilename, int ncount, CCdatagroup *dat,
        int ecount, int *elist, int *elen, int excount,
        int *exlist, int *exlen, int exvalid, int *ptour,
        double initial_ub, CCtsp_lpcuts *pool)
#else
int CCtsp_init_lp (lp, probname, probnum, probfilename, ncount, dat, ecount,
        elist, elen, excount, exlist, exlen, exvalid, ptour,
        initial_ub, pool)
CCtsp_lp **lp;
char *probname;
int probnum;
char *probfilename;
int ncount;
CCdatagroup *dat;
int ecount;
int *elist, *elen;
int excount;
int *exlist, *exlen;
int exvalid;
int *ptour;
double initial_ub;
CCtsp_lpcuts *pool;
#endif
{
    int rval = 0;
    double tet;

    if (!ptour) {
        fprintf (stderr, "must have a permutation tour in CCtsp_init_lp\n");
        rval = 1; goto CLEANUP;
    }

    *lp = CC_SAFE_MALLOC (1, CCtsp_lp);
    if ( !(*lp) ) {
       rval = 1; goto CLEANUP;
    }

    CCtsp_init_tsp_lp_struct (*lp);
    (*lp)->perm = ptour;
    (*lp)->dat = dat;
    (*lp)->pool = pool;

    if (probfilename) {
        rval = CCtsp_read_probfile (*lp, probfilename, ncount);
        CCtsp_free_bigdual (&((*lp)->exact_dual));
    } else if (probnum != -1) {
        rval = CCtsp_read_probfile_id (*lp, probname, probnum, ncount);
        CCtsp_free_bigdual (&((*lp)->exact_dual));
    } else {
        rval = first_lp (*lp, probname, ncount, ecount, elist, elen);
    }
    if (rval) {
        fprintf (stderr, "CCtsp_read_probfile or first_lp failed\n");
        CCtsp_free_tsp_lp_struct (lp);
        rval = 1; goto CLEANUP;
    }

    if ((*lp)->fullcount == 0) {
        if (excount) {
            rval = CCtsp_edgelist_to_genadj (ncount, excount, exlist, exlen,
                           &((*lp)->fulladj), &((*lp)->fulladjspace));
            if (rval) {
                fprintf (stderr, "CCtsp_edgelist_to_genadj failed\n");
                CCtsp_free_tsp_lp_struct (lp);
                rval = 1; goto CLEANUP;
            }
            (*lp)->fullcount = excount;
            if (exvalid)
                (*lp)->full_edges_valid = 1;
        }
    }

    if (initial_ub < (*lp)->upperbound) {
        printf ("Setting upperbound to the initial bound: %.2f\n", initial_ub);
        fflush (stdout);
        (*lp)->upperbound = initial_ub;
    }

    rval = CClp_init (&((*lp)->lp));
    if (rval) {
        fprintf (stderr, "CClp_init failed\n");
        CCtsp_free_tsp_lp_struct (lp);
        rval = 1; goto CLEANUP;
    }

    rval = load_lp (*lp);
    if (rval) {
        fprintf (stderr, "load_lp failed\n");
        CCtsp_free_tsp_lp_struct (lp);
        rval = 1; goto CLEANUP;
    }

    if ((*lp)->basis) {
        CClp_free_basis ((*lp)->basis);
        CC_FREE ((*lp)->basis, CClpbasis);
    }

    (*lp)->edge_life = CCtsp_EDGE_LIFE;
    (*lp)->cut_life  = CCtsp_CUT_LIFE;

    rval = CCtsp_add_branchhistory_to_lp (*lp);
    if (rval) {
        fprintf (stderr, "CCtsp_add_branchhistory_to_lp failed\n");
        rval = 1; goto CLEANUP;
    }

    tet = CCutil_zeit ();
    rval = CClp_opt (&((*lp)->lp), CClp_METHOD_DUAL);
    printf ("Dual opt returned after %.2f seconds\n", CCutil_zeit () - tet);
    fflush (stdout);
    if (rval == 2) {
        fprintf (stderr, "Initial lp infeasible\n");
        goto CLEANUP;
    } else if (rval) {
        fprintf (stderr, "CClp_opt failed\n");
        rval = 1; goto CLEANUP;
    }

    rval = CCtsp_update_result (*lp);
    if (rval) {
        fprintf (stderr, "CCtsp_update_result failed\n");
        rval = 1; goto CLEANUP;
    }

CLEANUP:

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static int first_lp (CCtsp_lp *lp, char *probname, int ncount,
        int ecount, int *elist, int *elen)
#else
static int first_lp (lp, probname, ncount, ecount, elist, elen)
CCtsp_lp *lp;
char *probname;
int ncount;
int ecount;
int *elist, *elen;
#endif
{
    double v, szeit;
    int *basis = (int *) NULL;
    int *match = (int *) NULL;
    int rval = 0;
    int i;
    int e;
    CClpbasis *b = (CClpbasis *) NULL;


    szeit = CCutil_zeit ();

    rval = CCtsp_init_cliquehash (&lp->cuts, 2*ncount);
    if (rval) goto CLEANUP;
    rval = CCtsp_build_lpgraph (&lp->graph, ncount, ecount, elist, elen);
    if (rval) goto CLEANUP;
    rval = CCtsp_build_lpadj (&lp->graph, 0, ecount);
    if (rval) goto CLEANUP;

    lp->name = CC_SAFE_MALLOC (strlen (probname)+1, char);
    if (!lp->name) {
        rval = 1;
        goto CLEANUP;
    }
    strcpy (lp->name, probname);

    lp->id = 0;
    lp->parent_id = -1;
    lp->full_edges_valid = 0;

    basis = CC_SAFE_MALLOC (2 * ncount, int);
    if (!basis) {
        rval = 1;
        goto CLEANUP;
    }
    match = CC_SAFE_MALLOC ((6 * ncount) + 1, int);
    if (!match) {
        rval = 1;
        goto CLEANUP;
    }

    rval = CCfmatch_fractional_2match (ncount, ecount, elist, elen,
                   (CCdatagroup *) NULL, &v, match, (int *) NULL, basis, 1);
    if (rval) {
        fprintf (stderr, "Fractional matching routine failed\n");
        CC_FREE (basis, int);
        CC_FREE (match, int);
        return 0;
    }

    b = CC_SAFE_MALLOC (1, CClpbasis);
    if (!b) {
        fprintf (stderr, "out of memory in first_lp\n");
        rval = 1; goto CLEANUP;
    }
    CClp_init_basis (b);

    b->cstat = CC_SAFE_MALLOC (ecount, int);
    b->rstat = CC_SAFE_MALLOC (ncount, int);
    if (!b->cstat || !b->rstat) {
        fprintf (stderr, "out of memory in first_lp\n");
        rval = 1; goto CLEANUP;
    }

    for (i=0; i<ecount; i++) b->cstat[i] = 0;
    for (i=0; i<ncount; i++) b->rstat[i] = 0;

    for (i = 0; i < ncount; i++) {
        e = CCtsp_find_edge (&lp->graph, basis[2*i], basis[2*i+1]);
        if (e < 0) {
            fprintf (stderr, "Basis contains edge %d,%d not in edgelist\n",
                     basis[2*i],basis[2*i+1]);
        } else {
            b->cstat[e] = 1;
        }
    }

    for (i=0; i <= 6*ncount && match[i] > -1; i += 3) {
        e = CCtsp_find_edge (&lp->graph, match[i], match[i+1]);
        if (e < 0) {
            fprintf (stderr, "Matching contains edge %d,%d not in edgelist\n",
                     match[i], match[i+1]);
        } else {
            if (b->cstat[e] == 0) {
                if (match[i+2] == 1) {
                    fprintf (stderr, "Edge at 0.5 not in basis\n");
                }
                b->cstat[e] = 2;
            }
        }
    }

    CC_FREE (basis, int);
    CC_FREE (match, int);
    lp->basis = b;

    printf ("Total Time for first_lp: %.2f (seconds)\n",
            CCutil_zeit () - szeit);

    return 0;

CLEANUP:

    CC_IFFREE (basis, int);
    CC_IFFREE (match, int);
    if (b) {
        CClp_free_basis (b);
        CC_FREE (b, CClpbasis);
    }

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_build_lpgraph (CCtsp_lpgraph *g, int ncount, int ecount,
        int *elist, int *elen)
#else
int CCtsp_build_lpgraph (g, ncount, ecount, elist, elen)
CCtsp_lpgraph *g;
int ncount;
int ecount;
int *elist;
int *elen;
#endif
{
    int i;
    CCtsp_lpnode *n;
    CCtsp_lpedge *e;

    g->ncount = ncount;
    g->ecount = ecount;
    g->nodes = CC_SAFE_MALLOC (ncount, CCtsp_lpnode);
    if (!g->nodes) {
        return 1;
    }
    g->edges = CC_SAFE_MALLOC (ecount, CCtsp_lpedge);
    if (!g->edges) {
        CC_FREE (g->nodes, CCtsp_lpnode);
        return 1;
    }
    g->espace = ecount;
    n = g->nodes;
    e = g->edges;

    for (i = 0; i < ncount; i++) {
        n[i].mark = 0;
    }
    for (i=0; i<ecount; i++) {
        if (elist[2*i] < elist[2*i+1]) {
            e[i].ends[0] = elist[2*i];
            e[i].ends[1] = elist[2*i+1];
        } else {
            e[i].ends[0] = elist[2*i+1];
            e[i].ends[1] = elist[2*i];
        }
        e[i].fixed = 0;
        e[i].branch = 0;
        e[i].age = 0;
        if (elen) {
            e[i].len = elen[i];
        } else {
            e[i].len = 0;
        }
        e[i].coefnext = -2;
        e[i].coef = 0;
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_build_lpadj (CCtsp_lpgraph *g, int estart, int eend)
#else
int CCtsp_build_lpadj (g, estart, eend)
CCtsp_lpgraph *g;
int estart;
int eend;
#endif
{
    CCtsp_lpadj *a;
    CCtsp_lpnode *n = g->nodes;
    CCtsp_lpedge *e = g->edges;
    int i, j;

    if (g->adjspace) {
        if (g->adjstart == estart && g->adjend == eend) {
            return 0;
        } else {
            CC_FREE (g->adjspace, CCtsp_lpadj);
        }
    }

    if (estart >= eend) {
        g->adjstart = estart;
        g->adjend = eend;
        for (i=0; i<g->ncount; i++) {
            n[i].deg = 0;
            n[i].adj = (CCtsp_lpadj *) NULL;
        }
        return 0;
    }

    g->adjspace = CC_SAFE_MALLOC ((eend - estart)*2, CCtsp_lpadj);
    if (!g->adjspace) {
        return 1;
    }
    a = g->adjspace;
    for (i=0; i<g->ncount; i++) {
        n[i].deg = 0;
    }
    for (i=estart; i<eend; i++) {
        n[e[i].ends[0]].deg++;
        n[e[i].ends[1]].deg++;
    }
    for (i=0; i<g->ncount; i++) {
        n[i].adj = a;
        a += n[i].deg;
        n[i].deg = 0;
    }
    for (i=estart; i<eend; i++) {
        j = e[i].ends[0];
        a = &n[j].adj[n[j].deg];
        a->to = e[i].ends[1];
        a->edge = i;
        n[j].deg++;
        j = e[i].ends[1];
        a = &n[j].adj[n[j].deg];
        a->to = e[i].ends[0];
        a->edge = i;
        n[j].deg++;
    }
    g->adjstart = estart;
    g->adjend = eend;

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_find_edge (CCtsp_lpgraph *g, int from, int to)
#else
int CCtsp_find_edge (g, from, to)
CCtsp_lpgraph *g;
int from;
int to;
#endif
{
    int t;
    int i;
    CCtsp_lpnode *f;

    if (from > to) {
        CC_SWAP (from, to, t);
    }

    f = &g->nodes[from];
    for (i=0; i<f->deg; i++) {
        if (f->adj[i].to == to) {
            return f->adj[i].edge;
        }
    }
    return -1;
}

#ifdef CC_PROTOTYPE_ANSI
static int find_edge_full (CCtsp_lp *lp, int from, int to)
#else
static int find_edge_full (lp, from, to)
CCtsp_lp *lp;
int from;
int to;
#endif
{
    int i;
    CCtsp_genadjobj *a;

    /* returns 1 if it is there */

    if (!lp->fulladj)
        return 0;

    if (from > to) {
        CC_SWAP (from, to, i);
    }

    a = lp->fulladj[from].list;
    for (i = lp->fulladj[from].deg-1; i >= 0; i--) {
        if (a[i].end == to) {
            return 1;
        }
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_inspect_full_edges (CCtsp_lp *lp)
#else
int CCtsp_inspect_full_edges (lp)
CCtsp_lp *lp;
#endif
{
    int i;
    int ecount = lp->graph.ecount;
    CCtsp_lpedge *edges = lp->graph.edges;

    for (i = 0; i < ecount; i++) {
        if (find_edge_full (lp, edges[i].ends[0], edges[i].ends[1]) == 0) {
            printf ("edge (%d,%d) not in full list\n",
                                 edges[i].ends[0], edges[i].ends[1]);
            fflush (stdout);
            return 1;
        }
    }
    return 0;
}


#ifdef CC_PROTOTYPE_ANSI
void CCtsp_init_tsp_lp_struct (CCtsp_lp *lp)
#else
void CCtsp_init_tsp_lp_struct (lp)
CCtsp_lp *lp;
#endif
{
    CCtsp_init_lpgraph_struct (&(lp->graph));

    lp->sparsifier = (CCtsp_qsparsegroup *) NULL;
    lp->perm = (int *) NULL;
    lp->dat = (CCdatagroup *) NULL;
    CClp_init_struct (&lp->lp);

    lp->cuts.cutcount = 0;
    lp->cuts.cuts = (CCtsp_lpcut *) NULL;
    lp->cuts.cutspace = 0;
    lp->cuts.cliqueend = 0;
    lp->cuts.cliques = (CCtsp_lpclique *) NULL;
    lp->cuts.cliquespace = 0;
    lp->cuts.cliquehash = (int *) NULL;
    lp->cuts.cliquehashsize = 0;
    lp->cuts.cuthash = (CCgenhash *) NULL;

    lp->pool = (CCtsp_lpcuts *) NULL;

    lp->fullcount = 0;
    lp->fulladj = (CCtsp_genadj *) NULL;
    lp->fulladjspace = (CCtsp_genadjobj *) NULL;
    lp->fixededges = (int *) NULL;
    lp->nfixededges = 0;
    lp->name = (char *) NULL;
    lp->id = -1;
    lp->parent_id = -1;
    lp->root = 0;
    lp->upperbound =  CCtsp_LP_MAXDOUBLE;
    lp->lowerbound = -CCtsp_LP_MAXDOUBLE;
    lp->exact_lowerbound = CCbigguy_MINBIGGUY;
    lp->exact_dual = (CCtsp_bigdual *) NULL;
    lp->infeasible = 0;
    lp->full_edges_valid = 0;
    lp->basis = (CClpbasis *) NULL;

    lp->cutqueue.cliquecount = 0;
    lp->cutqueue.handlecount = 0;
    lp->cutqueue.cliques = (CCtsp_lpclique *) NULL;
    lp->cutqueue.next = &lp->cutqueue;
    lp->cutqueue.prev = &lp->cutqueue;

    lp->result.ub = 0.0;
    lp->result.lb = 0.0;
    lp->result.ecount = 0;
    lp->result.elist = (int *) NULL;
    lp->result.x = (double *) NULL;
    lp->result.rc = (double *) NULL;

    lp->branchhistory = (CCtsp_branchobj *) NULL;
    lp->branchdepth   = 0;

    CCtsp_init_tighten_info (&lp->tighten_stats);
}

#ifdef CC_PROTOTYPE_ANSI
void CCtsp_free_tsp_lp_struct (CCtsp_lp **lp)
#else
void CCtsp_free_tsp_lp_struct (lp)
CCtsp_lp **lp;
#endif
{
    int i;

    if (!(*lp))  return;

    CCtsp_free_lpgraph (&((*lp)->graph));

    (*lp)->perm = (int *) NULL;      /* perm is owned by calling program */
    if ((*lp)->sparsifier) {
        CCtsp_free_qsparsify (&((*lp)->sparsifier));
    }
    (*lp)->dat = (CCdatagroup *) NULL; /* dat is owned by the calling program */
    if ((*lp)->dat) {
        CCutil_freedatagroup ((*lp)->graph.ncount, (*lp)->dat);
        CC_FREE ((*lp)->dat, CCdatagroup);
    }
    if ((*lp)->fulladjspace) {
        CC_FREE ((*lp)->fulladjspace, CCtsp_genadjobj);
        CC_IFFREE ((*lp)->fulladj, CCtsp_genadj);
    }
    (*lp)->fullcount = 0;
    CC_IFFREE ((*lp)->fixededges, int);
    (*lp)->nfixededges = 0;

    if ((*lp)->lp.lp_allocated) {
        CClp_free (&((*lp)->lp));
    }

    if ((*lp)->cuts.cuts) {
        for (i=0; i<(*lp)->cuts.cutcount; i++) {
            CC_FREE ((*lp)->cuts.cuts[i].cliques, int);
            CC_IFFREE ((*lp)->cuts.cuts[i].mods, CCtsp_sparser);
        }
        CC_FREE ((*lp)->cuts.cuts, CCtsp_lpcut);
    }
    if ((*lp)->cuts.cliques) {
        for (i=0; i<(*lp)->cuts.cliqueend; i++) {
            CC_IFFREE ((*lp)->cuts.cliques[i].nodes, CCtsp_segment);
        }
        CC_FREE ((*lp)->cuts.cliques, CCtsp_lpclique);
    }

    (*lp)->pool = (CCtsp_lpcuts *) NULL;  /* owned by calling routine */

    if ((*lp)->exact_dual) {
        CC_IFFREE ((*lp)->exact_dual->node_pi, CCbigguy);
        CC_IFFREE ((*lp)->exact_dual->cut_pi, CCbigguy);
        CC_FREE ((*lp)->exact_dual, CCtsp_bigdual);
    }
    CC_IFFREE ((*lp)->cuts.cliquehash, int);
    CC_IFFREE ((*lp)->name, char);
    if ((*lp)->basis) {
        CClp_free_basis ((*lp)->basis);
        CC_FREE ((*lp)->basis, CClpbasis);
    }
    CC_IFFREE ((*lp)->result.elist, int);
    CC_IFFREE ((*lp)->result.x, double);
    CC_IFFREE ((*lp)->result.rc, double);

    if ((*lp)->branchhistory) {
        for (i = 0; i < (*lp)->branchdepth; i++) {
            CCtsp_free_branchobj (&((*lp)->branchhistory[i]));
        }
        CC_FREE ((*lp)->branchhistory, CCtsp_branchobj);
        (*lp)->branchdepth = 0;
    }

    CC_IFFREE (*lp, CCtsp_lp);
}

#ifdef CC_PROTOTYPE_ANSI
void CCtsp_init_lpgraph_struct (CCtsp_lpgraph *g)
#else
void CCtsp_init_lpgraph_struct (g)
CCtsp_lpgraph *g;
#endif
{
    g->ncount = 0;
    g->ecount = 0;
    g->nodes = (CCtsp_lpnode *) NULL;
    g->edges = (CCtsp_lpedge *) NULL;
    g->adjspace = (CCtsp_lpadj *) NULL;
    g->adjstart = 0;
    g->adjend = 0;
    g->nodemarker = 0;
    g->espace = 0;
}

#ifdef CC_PROTOTYPE_ANSI
void CCtsp_free_lpgraph (CCtsp_lpgraph *g)
#else
void CCtsp_free_lpgraph (g)
CCtsp_lpgraph *g;
#endif
{
    CC_IFFREE (g->nodes, CCtsp_lpnode);
    CC_IFFREE (g->edges, CCtsp_lpedge);
    CC_IFFREE (g->adjspace, CCtsp_lpadj);
    g->espace = 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int load_lp (CCtsp_lp *lp)
#else
static int load_lp (lp)
CCtsp_lp *lp;
#endif
{
    int rval = 0;
    int nzcnt;
    int i, j;
    int xrhs;
    double sz = CCutil_zeit ();

    double *obj    = (double *) NULL;
    double *rhs    = (double *) NULL;
    char   *sense  = (char *)   NULL;
    int    *matbeg = (int *)    NULL;
    int    *matcnt = (int *)    NULL;
    int    *matind = (int *)    NULL;
    double *matval = (double *) NULL;
    double *lb     = (double *) NULL;
    double *ub     = (double *) NULL;

    printf ("Loading lp..."); fflush (stdout);

    rhs      = CC_SAFE_MALLOC (lp->graph.ncount + lp->cuts.cutcount, double);
    sense    = CC_SAFE_MALLOC (lp->graph.ncount + lp->cuts.cutcount, char);
    if (!rhs || !sense ) {
       fprintf (stderr, "not enough memory to load problem\n");
       rval = 1;
       goto CLEANUP;
    }

    rval = build_lp_cols (&lp->graph, &lp->cuts, 0, lp->graph.ecount,
                          &nzcnt, &obj, &matbeg, &matcnt, &matind, &matval,
                          &lb, &ub);
    if (rval)  goto CLEANUP;

    for (i = 0; i < lp->graph.ncount; i++) {
        rhs[i] = 2.0;
        sense[i] = 'E';
    }
    for (i = 0; i < lp->cuts.cutcount; i++) {
        xrhs = lp->cuts.cuts[i].rhs;
        for (j = 0; j < lp->cuts.cuts[i].modcount; j++) {
            xrhs += 2*(((int) lp->cuts.cuts[i].mods[j].mult)-128);
        }
        rhs[lp->graph.ncount + i] = xrhs;
        sense[lp->graph.ncount + i] = lp->cuts.cuts[i].sense;
    }

    rval = CClp_loadlp (&lp->lp, lp->name, lp->graph.ecount,
                        lp->graph.ncount + lp->cuts.cutcount, 1,
                        obj, rhs, sense, matbeg, matcnt, matind, matval,
                        lb, ub);

    if (rval) {
        fprintf (stderr, "couldn't load problem\n");
        goto CLEANUP;
    }

    if (lp->basis) {
        rval = CClp_load_basis_and_norms (&lp->lp, lp->basis);
        if (rval) {
            fprintf (stderr, "Couln't load basis and norms\n");
        }
    } else {
        fprintf (stderr, "No basis to load, stumbling on anyway\n");
    }

    printf ("done in %.2f seconds\n", CCutil_zeit () - sz); fflush (stdout);

CLEANUP:

    CC_IFFREE (obj, double);
    CC_IFFREE (rhs, double);
    CC_IFFREE (sense, char);
    CC_IFFREE (matbeg, int);
    CC_IFFREE (matcnt, int);
    CC_IFFREE (matind, int);
    CC_IFFREE (matval, double);
    CC_IFFREE (lb, double);
    CC_IFFREE (ub, double);

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static int build_lp_cols (CCtsp_lpgraph *g, CCtsp_lpcuts *cuts, int estart, int eend,
                          int *pnzcnt, double **pobj, int **pmatbeg,
                          int **pmatcnt, int **pmatind, double **pmatval,
                          double **plb, double **pub)
#else
static int build_lp_cols (g, cuts, estart, eend, pnzcnt, pobj, pmatbeg,
                          pmatcnt, pmatind, pmatval, plb, pub)
CCtsp_lpgraph *g;
CCtsp_lpcuts *cuts;
int estart;
int eend;
int *pnzcnt;
double **pobj;
int **pmatbeg;
int **pmatcnt;
int **pmatind;
double **pmatval;
double **plb;
double **pub;
#endif
{
    int rval;
    int nzcnt;
    int ncols = eend - estart;
    double *obj = (double *) NULL;
    int *matbeg = (int *) NULL;
    int *matcnt = (int *) NULL;
    int *matind = (int *) NULL;
    double *matval = (double *) NULL;
    double *lb = (double *) NULL;
    double *ub = (double *) NULL;
    int i;
    int nzlist, nznext;

    if (estart >= eend) {
        fprintf (stderr, "No columns for build_lp_cols to build\n");
        return 1;
    }

    rval = CCtsp_build_lpadj (g, estart, eend);
    if (rval) goto CLEANUP;

    obj = CC_SAFE_MALLOC (ncols, double);
    lb = CC_SAFE_MALLOC (ncols, double);
    ub = CC_SAFE_MALLOC (ncols, double);
    matbeg = CC_SAFE_MALLOC (ncols, int);
    matcnt = CC_SAFE_MALLOC (ncols, int);
    if (!obj || !lb || !ub || !matbeg || !matcnt) {
        rval = 1;
        goto CLEANUP;
    }
    for (i = 0; i < ncols; i++) {
        obj[i] = g->edges[i+estart].len;
        if (g->edges[i+estart].fixed || g->edges[i+estart].branch > 0) {
            lb[i] = 1.0;
        } else {
            lb[i] = 0.0;
        }
        if (g->edges[i+estart].branch < 0) {
            ub[i] = 0.0;
        } else {
            ub[i] = 1.0;
        }
        matcnt[i] = 2;
    }

    for (i=0; i<cuts->cutcount; i++) {
        nzlist = tsp_lpcut_nzlist (g, &cuts->cuts[i], cuts->cliques);
        while (nzlist != -1) {
            nznext = g->edges[nzlist].coefnext;
            g->edges[nzlist].coefnext = -2;
            if (g->edges[nzlist].coef) {
                g->edges[nzlist].coef = 0;
                matcnt[nzlist - estart]++;
            }
            nzlist = nznext;
        }
    }

    nzcnt = 0;
    for (i=0; i<ncols; i++) {
        matbeg[i] = nzcnt;
        nzcnt += matcnt[i];
        matcnt[i] = 0;
    }
    matind = CC_SAFE_MALLOC (nzcnt, int);
    matval = CC_SAFE_MALLOC (nzcnt, double);
    if (!matind || !matval) {
        rval = 1;
        goto CLEANUP;
    }

    for (i=0; i<ncols; i++) {
        matval[matbeg[i] + matcnt[i]] = 1.0;
        matind[matbeg[i] + matcnt[i]] = g->edges[estart+i].ends[0];
        matcnt[i]++;
        matval[matbeg[i] + matcnt[i]] = 1.0;
        matind[matbeg[i] + matcnt[i]] = g->edges[estart+i].ends[1];
        matcnt[i]++;
    }

    for (i=0; i<cuts->cutcount; i++) {
        nzlist = tsp_lpcut_nzlist (g, &cuts->cuts[i], cuts->cliques);
        while (nzlist != -1) {
            nznext = g->edges[nzlist].coefnext;
            g->edges[nzlist].coefnext = -2;
            if (g->edges[nzlist].coef) {
                matval[matbeg[nzlist-estart] + matcnt[nzlist-estart]] =
                                                      g->edges[nzlist].coef;
                matind[matbeg[nzlist-estart] + matcnt[nzlist-estart]] =
                                                      g->ncount + i;
                matcnt[nzlist-estart]++;
                g->edges[nzlist].coef = 0;
            }
            nzlist = nznext;
        }
    }

    if (pnzcnt) *pnzcnt = nzcnt;
    if (pobj) *pobj = obj;
    else CC_FREE (obj, double);
    if (pmatbeg) *pmatbeg = matbeg;
    else CC_FREE (matbeg, int);
    if (pmatcnt) *pmatcnt = matcnt;
    else CC_FREE (matcnt, int);
    if (pmatind) *pmatind = matind;
    else CC_FREE (matind, int);
    if (pmatval) *pmatval = matval;
    else CC_FREE (matval, double);
    if (plb) *plb = lb;
    else CC_FREE (lb, double);
    if (pub) *pub = ub;
    else CC_FREE (ub, double);

    return 0;

CLEANUP:

    CC_IFFREE (obj, double);
    CC_IFFREE (matbeg, int);
    CC_IFFREE (matcnt, int);
    CC_IFFREE (matind, int);
    CC_IFFREE (matval, double);
    CC_IFFREE (lb, double);
    CC_IFFREE (ub, double);

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_update_result (CCtsp_lp *lp)
#else
int CCtsp_update_result (lp)
CCtsp_lp *lp;
#endif
{
    CCtsp_lp_result new;
    int i;

    if (CClp_objval (&lp->lp, &new.lb)) {
        return 1;
    }
    new.ub = lp->upperbound;
    new.elist = CC_SAFE_MALLOC (lp->graph.ecount*2, int);
    if (!new.elist) return 1;
    new.x = CC_SAFE_MALLOC (lp->graph.ecount, double);
    if (!new.x) {
        CC_FREE (new.elist, int);
        return 1;
    }
    new.rc = CC_SAFE_MALLOC (lp->graph.ecount, double);
    if (!new.rc) {
        CC_FREE (new.x, double);
        CC_FREE (new.elist, int);
        return 1;
    }

    if (CClp_x (&lp->lp, new.x)) {
        CC_FREE (new.rc, double);
        CC_FREE (new.x, double);
        CC_FREE (new.elist, int);
        return 1;
    }

    if (CClp_rc (&lp->lp, new.rc)) {
        CC_FREE (new.rc, double);
        CC_FREE (new.x, double);
        CC_FREE (new.elist, int);
        return 1;
    }

    new.ecount = lp->graph.ecount;
    for (i=0; i<new.ecount; i++) {
        new.elist[2*i] = lp->graph.edges[i].ends[0];
        new.elist[2*i+1] = lp->graph.edges[i].ends[1];
    }

    CC_IFFREE (lp->result.elist, int);
    CC_IFFREE (lp->result.x, double);
    CC_IFFREE (lp->result.rc, double);

    lp->result = new;

    printf ("Optimized, val = %.6f\n", lp->result.lb);
    fflush (stdout);
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_get_lp_result (CCtsp_lp *lp, double *lb, double *ub, int *ecount,
        int **elist, double **x, double **rc, double **node_pi,
        double **cut_pi)
#else
int CCtsp_get_lp_result (lp, lb, ub, ecount, elist, x, rc, node_pi, cut_pi)
CCtsp_lp *lp;
double *lb;
double *ub;
int *ecount;
int **elist;
double **x;
double **rc;
double **node_pi;
double **cut_pi;
#endif
{
    int *myelist = (int *) NULL;
    double *myx = (double *) NULL;
    double *myrc = (double *) NULL;
    double *mynode_pi = (double *) NULL;
    double *mycut_pi = (double *) NULL;
    int i;
    int rval = 0;

    if ((elist || x || rc) && lp->result.ecount == 0){
       fprintf (stderr, "lp->result is not initialized\n");
       return 1;
    }

    if (elist) {
        myelist = CC_SAFE_MALLOC (2*lp->result.ecount, int);
        if (!myelist) {
            fprintf (stderr, "out of memory in CCtsp_get_lp_result\n");
            rval = 1;
            goto CLEANUP;
        }
    }
    if (x) {
        myx = CC_SAFE_MALLOC (lp->result.ecount, double);
        if (!myx) {
            fprintf (stderr, "out of memory in CCtsp_get_lp_result\n");
            rval = 1;
            goto CLEANUP;
        }
    }
    if (rc) {
        myrc = CC_SAFE_MALLOC (lp->result.ecount, double);
        if (!myrc) {
            fprintf (stderr, "out of memory in CCtsp_get_lp_result\n");
            rval = 1;
            goto CLEANUP;
        }
    }
    if (node_pi) {
        mynode_pi = CC_SAFE_MALLOC (lp->graph.ncount, double);
        if (!mynode_pi) {
            fprintf (stderr, "out of memory in CCtsp_get_lp_result\n");
            rval = 1;
            goto CLEANUP;
        }
    }
    if (cut_pi && lp->cuts.cutcount) {
        mycut_pi = CC_SAFE_MALLOC (lp->cuts.cutcount, double);
        if (!mycut_pi) {
            fprintf (stderr, "out of memory in CCtsp_get_lp_result\n");
            rval = 1;
            goto CLEANUP;
        }
    }

    if (elist) {
        for (i=0; i<2*lp->result.ecount; i++) {
            myelist[i] = lp->result.elist[i];
        }
        *elist = myelist;
    }
    if (x) {
        for (i=0; i<lp->result.ecount; i++) {
            myx[i] = lp->result.x[i];
        }
        *x = myx;
    }
    if (rc) {
        for (i=0; i<lp->result.ecount; i++) {
            myrc[i] = lp->result.rc[i];
        }
        *rc = myrc;
    }
    if (node_pi || cut_pi) {
        rval = get_pi (lp, mynode_pi, mycut_pi);
        if (rval) {
            fprintf (stderr, "get_pi failed\n");
            goto CLEANUP;
        }
        *node_pi = mynode_pi;
        *cut_pi = mycut_pi;
    }
    if (lb) *lb = lp->result.lb;
    if (ub) *ub = lp->result.ub;
    if (ecount) *ecount = lp->result.ecount;

    return 0;

CLEANUP:

    CC_IFFREE (myelist, int);
    CC_IFFREE (myx, double);
    CC_IFFREE (myrc, double);
    CC_IFFREE (mynode_pi, double);
    CC_IFFREE (mycut_pi, double);

    return rval;
}


#ifdef CC_PROTOTYPE_ANSI
void CCtsp_add_cuts_to_queue (CCtsp_lp *lp, CCtsp_lpcut_in **clist)
#else
void CCtsp_add_cuts_to_queue (lp, clist)
CCtsp_lp *lp;
CCtsp_lpcut_in **clist;
#endif
{
    CCtsp_lpcut_in *c, *cnext;

    for (c = *clist; c; c = cnext) {
        cnext = c->next;
        add_cut_to_queue (lp, c);
    }
    *clist = (CCtsp_lpcut_in *) NULL;
}

#ifdef CC_PROTOTYPE_ANSI
static void add_cut_to_queue (CCtsp_lp *lp, CCtsp_lpcut_in *c)
#else
static void add_cut_to_queue (lp, c)
CCtsp_lp *lp;
CCtsp_lpcut_in *c;
#endif
{
    assert (c->sense == 'G' || c->branch != 0);
    c->next = &lp->cutqueue;
    c->prev = lp->cutqueue.prev;
    c->next->prev = c;
    c->prev->next = c;
}

#ifdef CC_PROTOTYPE_ANSI
double CCtsp_cutprice (CCtsp_lpgraph *g, CCtsp_lpcut_in *c, double *x)
#else
double CCtsp_cutprice (g, c, x)
CCtsp_lpgraph *g;
CCtsp_lpcut_in *c;
double *x;
#endif
{
    double slack;
    int nzlist, nznext;

    slack =  (double) -(c->rhs);

    nzlist = CCtsp_lpcut_in_nzlist (g, c);

    while (nzlist != -1) {
        nznext = g->edges[nzlist].coefnext;
        g->edges[nzlist].coefnext = -2;
        slack += g->edges[nzlist].coef * x[nzlist];
        g->edges[nzlist].coef = 0;
        nzlist = nznext;
    }
    return slack;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_lpcut_in_nzlist (CCtsp_lpgraph *g, CCtsp_lpcut_in *c)
#else
int CCtsp_lpcut_in_nzlist (g, c)
CCtsp_lpgraph *g;
CCtsp_lpcut_in *c;
#endif
{
    int nzlist = -1;
    int i;

    for (i = 0; i < c->cliquecount; i++) {
        tsp_lpcut_nonzero_work (g, &c->cliques[i], &nzlist);
    }
    return nzlist;
}

#ifdef CC_PROTOTYPE_ANSI
static int tsp_lpcut_nzlist (CCtsp_lpgraph *g, CCtsp_lpcut *c,
        CCtsp_lpclique *cliques)
#else
static int tsp_lpcut_nzlist (g, c, cliques)
CCtsp_lpgraph *g;
CCtsp_lpcut *c;
CCtsp_lpclique *cliques;
#endif
{
    int nzlist = -1;
    int i;

    for (i = 0; i < c->cliquecount; i++) {
        tsp_lpcut_nonzero_work (g, &cliques[c->cliques[i]], &nzlist);
    }
    tsp_lpcut_nonzero_modify (g, c->modcount, c->mods, &nzlist);
    return nzlist;
}

#ifdef CC_PROTOTYPE_ANSI
static void tsp_lpcut_nonzero_work (CCtsp_lpgraph *g, CCtsp_lpclique *c,
        int *pnzlist)
#else
static void tsp_lpcut_nonzero_work (g, c, pnzlist)
CCtsp_lpgraph *g;
CCtsp_lpclique *c;
int *pnzlist;
#endif
{
    int nzlist = *pnzlist;
    int nodemarker;
    CCtsp_lpadj *a;
    int e;
    int j, k, l;

    g->nodemarker++;
    nodemarker = g->nodemarker;

    for (j=0; j<c->segcount; j++) {
        for (k=c->nodes[j].lo; k<=c->nodes[j].hi; k++) {
            g->nodes[k].mark = nodemarker;
        }
    }

    for (j=0; j<c->segcount; j++) {
        for (k=c->nodes[j].lo; k<=c->nodes[j].hi; k++) {
            a = g->nodes[k].adj;
            for (l=0; l<g->nodes[k].deg; l++) {
                if (g->nodes[a[l].to].mark != nodemarker) {
                    e = a[l].edge;
                    if (g->edges[e].coefnext == -2) {
                        g->edges[e].coefnext = nzlist;
                        nzlist = e;
                    }
                    g->edges[e].coef++;
                }
            }
        }
    }
    *pnzlist = nzlist;
}

#ifdef CC_PROTOTYPE_ANSI
static void tsp_lpcut_nonzero_modify (CCtsp_lpgraph *g, int modcount,
        CCtsp_sparser *mods, int *pnzlist)
#else
static void tsp_lpcut_nonzero_modify (g, modcount, mods, pnzlist)
CCtsp_lpgraph *g;
int modcount;
CCtsp_sparser *mods;
int *pnzlist;
#endif
{
    int nzlist = *pnzlist;
    int i,j,k,l;
    CCtsp_lpadj *a;
    int e;

    for (i=0; i<modcount; i++) {
        k = mods[i].node;
        j = ((int) mods[i].mult) - 128;
        a = g->nodes[k].adj;
        for (l=0; l<g->nodes[k].deg; l++) {
            e = a[l].edge;
            if (g->edges[e].coefnext == -2) {
                g->edges[e].coefnext = nzlist;
                nzlist = e;
            }
            g->edges[e].coef += j;
        }
    }
    *pnzlist = nzlist;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_process_cuts (CCtsp_lp *lp, int *pnadded, int tighten)
#else
int CCtsp_process_cuts (lp, pnadded, tighten)
CCtsp_lp *lp;
int *pnadded;
int tighten;
#endif
{
    int nadded = 0;
    int addpiece = 0;
    CCtsp_lpcut_in *c = (CCtsp_lpcut_in *) NULL;
    double *x = (double *) NULL;
    int ecount_save;
    int rval;
    CCtsp_lprow cr;

    *pnadded = 0;
    CCtsp_init_lprow (&cr);
    ecount_save = lp->graph.ecount;
    x = CC_SAFE_MALLOC (ecount_save, double);
    if (!x) {
        return 1;
    }

    rval = CClp_x (&lp->lp, x);
    if (rval) {
        CC_FREE (x, double);
        return rval;
    }

    nadded = 0;
    addpiece = 0;
    while (lp->cutqueue.next != &lp->cutqueue) {
        c = lp->cutqueue.next;
        c->next->prev = c->prev;
        c->prev->next = c->next;
        rval = checkout_cut (lp, c, x, &cr, tighten);
        if (rval > 1) {
            rval = 1;
            goto CLEANUP;
        } else if (rval == 1) {
            nadded++;
            addpiece++;
            if (cr.rowcnt >= CCtsp_STORE_BATCH) {
                if (cr.rowcnt > 0) {
                    rval = CCtsp_add_multiple_rows (lp, &cr);
                    if (rval) {
                        fprintf (stderr, "CCtsp_add_multiple_rows failed\n");
                        goto CLEANUP;
                    }
                    CCtsp_free_lprow (&cr);
                }
            }
            if (addpiece >= CCtsp_CUT_BATCH) {
                if (cr.rowcnt > 0) {
                    rval = CCtsp_add_multiple_rows (lp, &cr);
                    if (rval) {
                        fprintf (stderr, "CCtsp_add_multiple_rows failed\n");
                        goto CLEANUP;
                    }
                    CCtsp_free_lprow (&cr);
                }
                rval = update_newcuts (lp);
                if (rval == 2) {
                    printf ("LP is really infeasible (processs_cuts)\n");
                    fflush (stdout);
                    goto CLEANUP;
                } else if (rval) {
                    goto CLEANUP;
                }
                if (lp->graph.ecount != ecount_save) {
                    CC_FREE (x, double);
                    ecount_save = lp->graph.ecount;
                    x = CC_SAFE_MALLOC (ecount_save, double);
                    if (!x) {
                        rval = 1;
                        goto CLEANUP;
                    }
                }
                rval = CClp_x (&lp->lp, x);
                if (rval) {
                    goto CLEANUP;
                }
                addpiece = 0;
            }
        }
        CCtsp_free_lpcut_in (c);
        CC_FREE (c, CCtsp_lpcut_in);
    }
    if (addpiece > 0) {
        if (cr.rowcnt > 0) {
            rval = CCtsp_add_multiple_rows (lp, &cr);
            if (rval) {
                fprintf (stderr, "CCtsp_add_multiple_rows failed\n");
                goto CLEANUP;
            }
            CCtsp_free_lprow (&cr);
        }
        rval = update_newcuts (lp);
        if (rval == 2) {
            printf ("LP is really infeasible (processs_cuts)\n");
            fflush (stdout);
            goto CLEANUP;
        } else if (rval) {
            goto CLEANUP;
        }
    }
    CC_FREE (x, double);
    *pnadded = nadded;

    rval = CCtsp_update_result (lp);
    if (rval) goto CLEANUP;

    return 0;

CLEANUP:

    CCtsp_free_lprow (&cr);
    if (c) {
        CCtsp_free_lpcut_in (c);
        CC_FREE (c, CCtsp_lpcut_in);
    }
    CC_IFFREE (x, double);
    *pnadded = nadded;
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
void CCtsp_init_lprow (CCtsp_lprow *cr)
#else
void CCtsp_init_lprow (cr)
CCtsp_lprow *cr;
#endif
{
    cr->rowcnt = 0;
    cr->nzcnt = 0;
    cr->sense = (char *) NULL;
    cr->rhs = (double *) NULL;
    cr->begin = (int *) NULL;
    cr->indexspace = 0;
    cr->indices = (int *) NULL;
    cr->entryspace = 0;
    cr->entries = (double *) NULL;
}

#ifdef CC_PROTOTYPE_ANSI
void CCtsp_free_lprow (CCtsp_lprow *cr)
#else
void CCtsp_free_lprow (cr)
CCtsp_lprow *cr;
#endif
{
    if (cr) {
        cr->rowcnt = 0;
        cr->nzcnt = 0;
        CC_IFFREE (cr->sense, char);
        CC_IFFREE (cr->rhs, double);
        CC_IFFREE (cr->begin, int);
        CC_IFFREE (cr->indices, int);
        cr->indexspace = 0;
        CC_IFFREE (cr->entries, double);
        cr->entryspace = 0;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static int checkout_cut (CCtsp_lp *lp, CCtsp_lpcut_in *c, double *x,
        CCtsp_lprow *cr, int tighten)
#else
static int checkout_cut (lp, c, x, cr, tighten)
CCtsp_lp *lp;
CCtsp_lpcut_in *c;
double *x;
CCtsp_lprow *cr;
int tighten;
#endif
{
    int rval;
    CCtsp_lpcut_in d;
    double slack;
    CCtsp_lpgraph *g = &lp->graph;

    if (tighten) {
        rval = CCtsp_tighten_lpcut_in (g, c, x, &d, &lp->tighten_stats,
                                       (double *) NULL);
        if (rval) {
            fprintf (stderr, "CCtsp_tighten_lpcut_in failed\n");
            return 2;
        }
    } else {
        rval = CCtsp_copy_lpcut_in (c, &d);
        if (rval) {
            fprintf (stderr, "CCtsp_copy_lpcut_in failed\n");
            return 2;
        }
    }

    slack = CCtsp_cutprice (g, &d, x);
    if (slack >= -CCtsp_MIN_VIOL) {
        CCtsp_free_lpcut_in (&d);
        return 0;
    }

    rval = verify_lpcut_in (g, &d);
    if (rval) {
        fprintf (stderr, "Discarding invalid cut\n");
        CCtsp_print_lpcut_in (&d);
        CCtsp_free_lpcut_in (&d);
        return 2;
    }

    rval = CCtsp_add_cut (lp, &d, cr);
    if (rval) {
        CCtsp_free_lpcut_in (&d);
        return 2;
    }
    CCtsp_free_lpcut_in (&d);
    return 1;
}

#ifdef CC_PROTOTYPE_ANSI
void CCtsp_free_lpcut_in (CCtsp_lpcut_in *c)
#else
void CCtsp_free_lpcut_in (c)
CCtsp_lpcut_in *c;
#endif
{
    int i;

    if (c) {
        for (i = 0; i < c->cliquecount; i++) {
            CCtsp_free_lpclique (&c->cliques[i]);
        }
        CC_IFFREE (c->cliques, CCtsp_lpclique);
    }
}

#ifdef CC_PROTOTYPE_ANSI
void CCtsp_free_lpclique (CCtsp_lpclique *c)
#else
void CCtsp_free_lpclique (c)
CCtsp_lpclique *c;
#endif
{
    if (c) {
        CC_IFFREE (c->nodes, CCtsp_segment);
        c->segcount = 0;
        c->hashnext = 0;
        c->refcount = 0;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static int verify_lpcut_in (CCtsp_lpgraph *g, CCtsp_lpcut_in *d)
#else
static int verify_lpcut_in (g, d)
CCtsp_lpgraph *g;
CCtsp_lpcut_in *d;
#endif
{
    /* Verify not yet written. */

    if (!d || !g) return 1;

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int update_newcuts (CCtsp_lp *lp)
#else
static int update_newcuts (lp)
CCtsp_lp *lp;
#endif
{
    int rval;
    int ndeleted;

    rval = CClp_opt (&lp->lp, CClp_METHOD_DUAL);
    if (rval == 2) {
        rval = CCtsp_infeas_recover (lp);
        if (rval == 2) {
            printf ("Problem is really infeasible (update_newcuts)\n");
            return 2;
        } else if (rval) {
            return 1;
        }
    } else if (rval) {
        fprintf (stderr, "CClp_opt failed\n");
        return 1;
    }
    rval = age_cuts (lp, &ndeleted);
    if (rval) {
        fprintf (stderr, "age_cuts failed\n");
        return 1;
    }
    rval = CClp_opt (&lp->lp, CClp_METHOD_DUAL);
    if (rval) {
        fprintf (stderr, "CClp_opt failed\n");
        return 1;
    }

    ndeleted = 0;
    rval = age_edges (lp, &ndeleted);
    if (rval) {
        fprintf (stderr, "age_edges failed\n");
        return 1;
    }
    rval = CClp_opt (&lp->lp, CClp_METHOD_DUAL);
    if (rval) {
        fprintf (stderr, "CClp_opt failed\n");
        return 1;
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_infeas_recover (CCtsp_lp *lp)
#else
int CCtsp_infeas_recover (lp)
CCtsp_lp *lp;
#endif
{
    double penalty;
    int nadded, feasible;
    int rval;

    printf ("infeas_recover ...\n"); fflush (stdout);

    rval = CCtsp_addbad_variables (lp, (CCtsp_edgegenerator *) NULL, &penalty,
                   &nadded, CCtsp_PHASE1_RCTHRESH, CCtsp_PHASE1_MAXPENALTY,
                   1, &feasible);
    if (rval) {
        fprintf (stderr, "CCtsp_addbad_variables failed\n");
        return 1;
    }

    if (feasible) {
        printf ("Recovered a feasible LP\n");
        fflush (stdout);
        return 0;
    } else {
        printf ("Could not recover a feasible LP\n");
        fflush (stdout);
        return 2;
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_add_cut (CCtsp_lp *lp, CCtsp_lpcut_in *d, CCtsp_lprow *cr)
#else
int CCtsp_add_cut (lp, d, cr)
CCtsp_lp *lp;
CCtsp_lpcut_in *d;
CCtsp_lprow *cr;
#endif
{
    int nzlist;
    CCtsp_lpgraph *g = &lp->graph;
    int saved;
    CCtsp_lpcut new;
    int rval;
    int newloc;
    int rhs;
    int i;

    assert (d->sense == 'G' || d->branch != 0);

    new.rhs         = d->rhs;
    new.sense       = d->sense;
    new.branch      = d->branch;
    new.modcount    = 0;
    new.mods        = (CCtsp_sparser *) NULL;
    new.cliquecount = 0;
    new.handlecount = 0;
    new.cliques     = (int *) NULL;
    rval = CCtsp_register_cliques (&lp->cuts, d, &new);
    if (rval) {
        return rval;
    }
    nzlist = CCtsp_lpcut_in_nzlist (g, d);
    rval = CCtsp_qsparsify (&lp->sparsifier, g, &nzlist, &new.modcount,
                      &new.mods, &saved);
    if (rval) {
        CCtsp_unregister_cliques (&lp->cuts, &new);
        CC_IFFREE (new.mods, CCtsp_sparser);
        clear_nzlist (g, nzlist);
        return rval;
    }
    new.age = CCtsp_NEWCUT_AGE;
    newloc = CCtsp_add_cut_to_cutlist (&lp->cuts, &new);
    if (newloc == -1) {
        CCtsp_unregister_cliques (&lp->cuts, &new);
        CC_IFFREE (new.mods, CCtsp_sparser);
        clear_nzlist (g, nzlist);
        return 1;
    }
    rhs = new.rhs;
    for (i=0; i<new.modcount; i++) {
        rhs += 2*(((int) new.mods[i].mult) - 128);
    }
    rval = CCtsp_add_nzlist_to_lp (lp, nzlist, rhs, new.sense, cr);
    if (rval) {
        fprintf (stderr, "CCtsp_add_nzlist_to_lp failed\n");
        CCtsp_delete_cut_from_cutlist (&lp->cuts, newloc);
        return rval;
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_register_cliques (CCtsp_lpcuts *cuts, CCtsp_lpcut_in *c,
        CCtsp_lpcut *new)
#else
int CCtsp_register_cliques (cuts, c, new)
CCtsp_lpcuts *cuts;
CCtsp_lpcut_in *c;
CCtsp_lpcut *new;
#endif
{
    int i, j;

    new->cliques = CC_SAFE_MALLOC (c->cliquecount, int);
    if (!new->cliques) return 1;
    new->handlecount = c->handlecount;
    new->cliquecount = c->cliquecount;
    for (i = 0; i < c->cliquecount; i++) {
        new->cliques[i] = CCtsp_register_clique (cuts, &c->cliques[i]);
        if (new->cliques[i] == -1) {
            for (j=0; j<i; j++) {
                CCtsp_unregister_clique (cuts, new->cliques[j]);
            }
            CC_FREE (new->cliques, int);
            return 1;
        }
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
void CCtsp_unregister_cliques (CCtsp_lpcuts *cuts, CCtsp_lpcut *c)
#else
void CCtsp_unregister_cliques (cuts, c)
CCtsp_lpcuts *cuts;
CCtsp_lpcut *c;
#endif
{
    int i;

    for (i = 0; i < c->cliquecount; i++) {
        CCtsp_unregister_clique (cuts, c->cliques[i]);
    }
    CC_FREE (c->cliques, int);
    c->cliquecount = 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_add_cut_to_cutlist (CCtsp_lpcuts *cuts, CCtsp_lpcut *c)
#else
int CCtsp_add_cut_to_cutlist (cuts, c)
CCtsp_lpcuts *cuts;
CCtsp_lpcut *c;
#endif
{
    if (cuts->cutcount >= cuts->cutspace) {
        if (CCutil_reallocrus_scale ((void **) &cuts->cuts, &cuts->cutspace,
                         cuts->cutcount + 1, 1.3, sizeof (CCtsp_lpcut))) {
            return -1;
        }
    }
    cuts->cuts[cuts->cutcount] = *c;
    return cuts->cutcount++;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_add_nzlist_to_lp (CCtsp_lp *lp, int nzlist, int rhs, char sense,
        CCtsp_lprow *cr)
#else
int CCtsp_add_nzlist_to_lp (lp, nzlist, rhs, sense, cr)
CCtsp_lp *lp;
int nzlist;
int rhs;
char sense;
CCtsp_lprow *cr;
#endif
{
    int nzcnt;
    int i;
    CCtsp_lpgraph *g = &lp->graph;
    int *rmatind = (int *) NULL;
    double *rmatval = (double *) NULL;
    double drhs = (double) rhs;
    int rval;

    nzcnt = 0;
    for (i=nzlist; i != -1; i = g->edges[i].coefnext) {
        if (g->edges[i].coef) nzcnt++;
    }

    if (nzcnt != 0) {
        rmatind = CC_SAFE_MALLOC (nzcnt, int);
        if (!rmatind) {
            clear_nzlist (g, nzlist);
            return 1;
        }
        rmatval = CC_SAFE_MALLOC (nzcnt, double);
        if (!rmatval) {
            CC_FREE (rmatind, int);
            clear_nzlist (g, nzlist);
            return 1;
        }
        for (nzcnt = 0; nzlist != -1; nzlist = i) {
            i = g->edges[nzlist].coefnext;
            g->edges[nzlist].coefnext = -2;
            if (g->edges[nzlist].coef) {
                rmatind[nzcnt] = nzlist;
                rmatval[nzcnt] = g->edges[nzlist].coef;
                g->edges[nzlist].coef = 0;
                nzcnt++;
            }
        }
    } else {
        printf ("WARNING: Adding an empty cut to the LP\n");
        fflush (stdout);
    }

    rval = addrow_to_list (nzcnt, drhs, sense, rmatind, rmatval, cr);

    CC_FREE (rmatind, int);
    CC_FREE (rmatval, double);

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
void CCtsp_delete_cut_from_cutlist (CCtsp_lpcuts *cuts, int ind)
#else
void CCtsp_delete_cut_from_cutlist (cuts, ind)
CCtsp_lpcuts *cuts;
int ind;
#endif
{
    int i;

    CCtsp_unregister_cliques (cuts, &cuts->cuts[ind]);
    CC_IFFREE (cuts->cuts[ind].mods, CCtsp_sparser);
    for (i = ind+1; i < cuts->cutcount; i++) {
        cuts->cuts[i-1] = cuts->cuts[i];
    }
    cuts->cutcount--;
}

#ifdef CC_PROTOTYPE_ANSI
static void clear_nzlist (CCtsp_lpgraph *g, int nzlist)
#else
static void clear_nzlist (g, nzlist)
CCtsp_lpgraph *g;
int nzlist;
#endif
{
    int nznext;

    while (nzlist != -1) {
        nznext = g->edges[nzlist].coefnext;
        g->edges[nzlist].coefnext = -2;
        g->edges[nzlist].coef = 0;
        nzlist = nznext;
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_addbad_variables (CCtsp_lp *lp, struct CCtsp_edgegenerator *eg,
        double *ppenalty, int *pnadded, double rcthresh, double maxpenalty,
        int phase1, int *feasible)
#else
int CCtsp_addbad_variables (lp, eg, ppenalty, pnadded, rcthresh, maxpenalty,
        phase1, feasible)
CCtsp_lp *lp;
struct CCtsp_edgegenerator *eg;
double *ppenalty;
int *pnadded;
double rcthresh, maxpenalty;
int phase1;
int *feasible;
#endif
{
    int nadded;
    double penalty;
    int finished;
    CCtsp_edgehash eh;
    int rval;
    int *genlist = (int *) NULL;
    int *genlen = (int *) NULL;
    int gencount;
    CCtsp_predge *inlist = (CCtsp_predge *) NULL;
    int incount;
    CCtsp_predge *prlist = (CCtsp_predge *) NULL;
    int prcount;
    double *node_pi = (double *) NULL;
    double *node_piest = (double *) NULL;
    double *clique_pi = (double *) NULL;
    double *cut_pi = (double *) NULL;
    int i, iend, n;
    int start = 0, ni, nj;
    int ngen = PRICE_GEN + PRICE_GEN_FACTOR * lp->graph.ncount;

    if (phase1) {
        printf ("phase 1 addbad_variables\n"); fflush (stdout);
    }

    if (feasible)
        *feasible = 0;

    rval = CCtsp_edgehash_init (&eh, (int) (ngen * 1.5));
    if (rval) return rval;

    gencount = 0;
    incount = 0;
    prcount = 0;

    genlist    = CC_SAFE_MALLOC (ngen*2, int);
    genlen     = CC_SAFE_MALLOC (ngen, int);
    inlist     = CC_SAFE_MALLOC (ngen, CCtsp_predge);
    prlist     = CC_SAFE_MALLOC (PRICE_POOL + ngen, CCtsp_predge);
    node_pi    = CC_SAFE_MALLOC (lp->graph.ncount, double);
    node_piest = CC_SAFE_MALLOC (lp->graph.ncount, double);
    if (!genlist || !genlen || !inlist || !prlist || !node_pi || !node_piest) {
        fprintf (stderr, "out of memory in CCtsp_addbad_variables\n");
        rval = 1; goto CLEANUP;
    }

    if (lp->cuts.cliqueend) {
        clique_pi = CC_SAFE_MALLOC (lp->cuts.cliqueend, double);
        if (!clique_pi) {
            fprintf (stderr, "out of memory in CCtsp_addbad_variables\n");
            rval = 1; goto CLEANUP;
        }
    }
    if (lp->cuts.cutcount) {
        cut_pi = CC_SAFE_MALLOC (lp->cuts.cutcount, double);
        if (!cut_pi) {
            fprintf (stderr, "out of memory in CCtsp_addbad_variables\n");
            rval = 1; goto CLEANUP;
        }
    }

    *pnadded = 0;
    rval = pricing_duals (lp, node_pi, node_piest, cut_pi, clique_pi);
    if (rval) {
        fprintf (stderr, "pricing_duals failed\n");
        goto CLEANUP;
    }
    if (phase1) {
        start = ni = 0;
        nj = (lp->full_edges_valid ? 0 : start + 1);
    } else {
        rval = CCtsp_reset_edgegenerator (eg, node_piest);
        if (rval) goto CLEANUP;
    }
    finished = 0;
    nadded = 0;
    penalty = 0.0;
    while (!finished) {
        if (phase1) {
            rval = phase1_generate_edges (lp, node_piest, ngen,
                 &gencount, genlist, genlen, start, &ni, &nj, &finished);
            if (rval) {
                fprintf (stderr, "phase1_generate_edges failed\n");
                goto CLEANUP;
            }
        } else {
            rval = CCtsp_generate_edges (eg, ngen, &gencount, genlist, genlen,
                                   &finished);
            if (rval) {
                fprintf (stderr, "CCtsp_generate_edges failed\n");
                goto CLEANUP;
            }
        }

        for (i = 0, incount = 0; i < gencount; i++) {
            if (CCtsp_edgehash_find (&eh, genlist[2*i], genlist[2*i+1]) == -1
             && CCtsp_find_edge (&lp->graph, genlist[2*i],
                                             genlist[2*i+1]) == -1) {
                CCtsp_edgehash_add (&eh, genlist[2*i], genlist[2*i+1], 1);
                if (genlist[2*i] < genlist[2*i+1]) {
                    inlist[incount].ends[0] = genlist[2*i];
                    inlist[incount].ends[1] = genlist[2*i+1];
                } else {
                    inlist[incount].ends[0] = genlist[2*i+1];
                    inlist[incount].ends[1] = genlist[2*i];
                }
                inlist[incount].len = genlen[i];
                incount++;
            }
        }
        rval = price_list (lp, incount, inlist, node_pi, clique_pi, phase1);
        if (rval) goto CLEANUP;
        for (i=0; i<incount; i++) {
            if (inlist[i].rc < 0.0) penalty += inlist[i].rc;
            if (inlist[i].rc < rcthresh) {
                prlist[prcount++] = inlist[i];
            } else {
                rval = CCtsp_edgehash_del (&eh, inlist[i].ends[0],
                                                inlist[i].ends[1]);
                if (rval) goto CLEANUP;
            }
        }
        nadded = 0;
        while ((!finished && prcount >= PRICE_POOL) ||
                (finished && penalty < -maxpenalty && prcount > 0)) {
            n = PRICE_ADD;
            if (n >= prcount) {
                n = prcount;
            } else {
                pr_select (prcount - n, prcount, prlist);
            }
            printf ("Add %d\n", n); fflush (stdout);
            rval = CCtsp_add_vars_to_lp (lp, prlist + prcount - n, n);
            if (rval) goto CLEANUP;
            nadded += n;
            *pnadded += n;
            prcount -= n;
            rval = CClp_opt (&lp->lp, CClp_METHOD_DUAL);
            if (phase1) {
                if (rval == 0) {
                    printf ("LP is now feasible\n"); fflush (stdout);
                    if (feasible) *feasible = 1;
                    goto DONE;
                } else if (rval != 2) {
                    fprintf (stderr, "CClp_opt failed\n");
                    goto CLEANUP;
                }
            } else {
                if (rval == 2) {
                    fprintf (stderr, "Adding variables made LP infeasible!\n");
                    rval = 1;
                    goto CLEANUP;
                } else if (rval) {
                    fprintf (stderr, "CClp_opt failed\n");
                    goto CLEANUP;
                }
            }
            rval = pricing_duals (lp, node_pi, node_piest, cut_pi,
                                  clique_pi);
            if (rval) {
                fprintf (stderr, "pricing_duals failed\n");
                goto CLEANUP;
            }
            rval = price_list (lp, prcount, prlist, node_pi, clique_pi, phase1);
            if (rval) {
                fprintf (stderr, "price_list failed\n");
                goto CLEANUP;
            }
            penalty = 0.0;
            for (i=0, iend = prcount, prcount = 0; i<iend; i++) {
                if (prlist[i].rc < 0.0) penalty += prlist[i].rc;
                if (prlist[i].rc < rcthresh &&
                    CCtsp_find_edge (&lp->graph, prlist[i].ends[0],
                                               prlist[i].ends[1]) == -1) {
                    prlist[prcount++] = prlist[i];
                }
            }
        }
        if (nadded > 0) {
            if (phase1) {
                start = ni;
                nj = (lp->full_edges_valid ? 0 : start + 1);
            } else {
                rval = CCtsp_reset_edgegenerator (eg, node_piest);
                if (rval) goto CLEANUP;
            }
            finished = 0;
            CCtsp_edgehash_delall (&eh);
            for (i = 0; i < prcount; i++) {
                CCtsp_edgehash_add (&eh, prlist[i].ends[0],
                                         prlist[i].ends[1], 1);
            }
        }
    }

DONE:

    *ppenalty = penalty;
    if (!phase1 || (feasible && *feasible))
        rval = CCtsp_update_result (lp);

CLEANUP:

    CC_IFFREE (cut_pi, double);
    CC_IFFREE (clique_pi, double);
    CC_IFFREE (node_piest, double);
    CC_IFFREE (node_pi, double);
    CC_IFFREE (prlist, CCtsp_predge);
    CC_IFFREE (inlist, CCtsp_predge);
    CC_IFFREE (genlen, int);
    CC_IFFREE (genlist, int);
    CCtsp_edgehash_free (&eh);
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static int phase1_generate_edges (CCtsp_lp *lp, double *node_piest, int nwant,
        int *ngot, int *genlist, int *genlen, int start, int *ni, int *nj,
        int *finished)
#else
static int phase1_generate_edges (lp, node_piest, nwant, ngot, genlist, genlen,
       start, ni, nj, finished)
CCtsp_lp *lp;
double *node_piest;
int nwant;
int *ngot, *genlist, *genlen;
int start;
int *ni, *nj, *finished;
#endif
{
    int i = *ni;
    int j = *nj;
    CCtsp_genadj *adj;
    CCdatagroup *dat;
    int cnt = 0;
    int ncount = lp->graph.ncount;

    *ngot = 0;
    *finished = 0;

    if (!lp->dat && !lp->full_edges_valid) {
        fprintf (stderr, "no source of edges to generate\n");
        return 1;
    }

    if (i >= ncount) {
        i = 0;
        j = (lp->full_edges_valid ? 0 : i + 1);
    }

    if (lp->full_edges_valid) {
        adj = lp->fulladj;
        for (; j < adj[i].deg; j++) {
            if (phase1_test_edge (i, adj[i].list[j].end, node_piest)) {
                genlist[2*cnt] = i;
                genlist[2*cnt+1] = adj[i].list[j].end;
                genlen[cnt] = adj[i].list[j].len;
                cnt++;
                if (cnt == nwant) {
                    goto NOT_FINISHED;
                }
            }
        }
        while ((i = (i+1) % ncount) != start) {
            for (j = 0; j < adj[i].deg; j++) {
                if (phase1_test_edge (i, adj[i].list[j].end, node_piest)) {
                    genlist[2*cnt] = i;
                    genlist[2*cnt+1] = adj[i].list[j].end;
                    genlen[cnt] = adj[i].list[j].len;
                    cnt++;
                    if (cnt == nwant) {
                        goto NOT_FINISHED;
                    }
                }
            }
        }
    } else {
        dat = lp->dat;
        for (; j < ncount; j++) {
            if (phase1_test_edge (i, j, node_piest)) {
                genlist[2*cnt] = i;
                genlist[2*cnt+1] = j;
                genlen[cnt] = CCutil_dat_edgelen (i, j, dat);
                cnt++;
                if (cnt == nwant) {
                    goto NOT_FINISHED;
                }
            }
        }
        while ((i = (i+1) % ncount) != start) {
            for  (j = i + 1; j < ncount; j++) {
                if (phase1_test_edge (i, j, node_piest)) {
                    genlist[2*cnt] = i;
                    genlist[2*cnt+1] = j;
                    genlen[cnt] = CCutil_dat_edgelen (i, j, dat);
                    cnt++;
                    if (cnt == nwant) {
                        goto NOT_FINISHED;
                    }
                }
            }
        }
    }

    *finished = 1;
    return 0;

NOT_FINISHED:

    *finished = 0;
    *ngot = cnt;
    *ni = i; *nj = j + 1;
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int phase1_test_edge (int end1, int end2, double *node_piest)
#else
static int phase1_test_edge (end1, end2, node_piest)
int end1, end2;
double *node_piest;
#endif
{
    return (node_piest[end1] + node_piest[end2] > 0.0);
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_eliminate_variables (CCtsp_lp *lp)
#else
int CCtsp_eliminate_variables (lp)
CCtsp_lp *lp;
#endif
{
    int i, j, k;
    int rval;
    CCbigguy ub;

    /* This function should not create an infeasible LP */

    if (lp->upperbound == CCtsp_LP_MAXDOUBLE ||
            CCbigguy_cmp (lp->exact_lowerbound, CCbigguy_MINBIGGUY) == 0) {
        printf ("Can't elmininate without upper and lower bounds\n");
        fflush (stdout);
        return 0;
    }

    ub = CCbigguy_dtobigguy (lp->upperbound - 1.0);
    if (CCbigguy_cmp (lp->exact_lowerbound, ub) > 0) {
        printf ("No need for elimination, bounds are optimal\n");
        fflush (stdout);
        return 0;
    }

    assert (lp->infeasible == 0);

    rval = CCtsp_edge_elimination (lp);
    if (rval) {
        fprintf (stderr, "tsp_edge_elimination failed\n");
        return rval;
    }

    assert (lp->infeasible == 0);

    for (i = 0; i < lp->nfixededges; i++) {
        k = CCtsp_find_edge (&(lp->graph), lp->fixededges[2*i],
                                           lp->fixededges[2*i+1]);
        if (k != -1) {
            rval = CClp_setbnd (&lp->lp, k, 'L', 1.0);
            lp->graph.edges[k].fixed = 1;
        } else {
            printf ("WARNING: Fixed edge is not in LP\n");
            fflush (stdout);
        }
    }

    CC_IFFREE (lp->graph.adjspace, CCtsp_lpadj);
    for (i = lp->graph.ecount - 1; i >= 0; i--) {
        if (!find_edge_full (lp, lp->graph.edges[i].ends[0],
                                 lp->graph.edges[i].ends[1])) {
            if (!lp->graph.edges[i].fixed && !lp->graph.edges[i].branch) {
                rval = CClp_delete_column (&lp->lp, i);
                if (rval) {
                    fprintf (stderr, "CClp_delete_column failed\n");
                    return rval;
                }
                lp->graph.edges[i].ends[0] = 0;
                lp->graph.edges[i].ends[1] = 0;
            } else {
                printf ("WARNING: Tried to eliminate a fixed/branch edge\n");
                fflush (stdout);
            }
        }
    }
    for (i = 0, j = 0; i < lp->graph.ecount; i++) {
        if (lp->graph.edges[i].ends[1] != 0 ||
            lp->graph.edges[i].ends[0] != 0) {
            lp->graph.edges[j] = lp->graph.edges[i];
            j++;
        }
    }
    printf ("Eliminated %d LP edges\n", lp->graph.ecount - j);
    fflush (stdout);

    assert (lp->infeasible == 0);

    lp->graph.ecount = j;
    rval = CCtsp_build_lpadj (&lp->graph, 0, lp->graph.ecount);
    if (rval) {
        fprintf (stderr, "CCtsp_build_lpadj failed\n");
        return rval;
    }

    rval = CClp_opt (&lp->lp, CClp_METHOD_DUAL);
    if (rval == 2) {
        fprintf (stderr, "ERROR: edge_elimination created an infeasible LP\n");
        return 1;
    } else if (rval) {
        fprintf (stderr, "CClp_opt failed\n");
        return rval;
    }
    rval = CCtsp_update_result (lp);
    if (rval) {
        fprintf (stderr, "CCtsp_update_result failed\n");
        return rval;
    }

    assert (lp->infeasible == 0);

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int pricing_duals (CCtsp_lp *lp, double *node_pi,
        double *node_piest, double *cut_pi, double *clique_pi)
#else
static int pricing_duals (lp, node_pi, node_piest, cut_pi, clique_pi)
CCtsp_lp *lp;
double *node_pi;
double *node_piest;
double *cut_pi;
double *clique_pi;
#endif
{
    double x;
    int i, j, k;
    int rval;

    rval = get_pi (lp, node_pi, cut_pi);
    if (rval) {
        fprintf (stderr, "get_pi failed\n");
        return rval;
    }

    for (i = 0; i < lp->cuts.cliqueend; i++) {
        clique_pi[i] = 0.0;
    }

    for (i = 0; i < lp->cuts.cutcount; i++) {
        x = cut_pi[i];
        for (j = 0; j < lp->cuts.cuts[i].modcount; j++) {
            node_pi[lp->cuts.cuts[i].mods[j].node] += x *
                (((int) lp->cuts.cuts[i].mods[j].mult) - 128);
        }
        for (j = 0; j < lp->cuts.cuts[i].cliquecount; j++) {
            clique_pi[lp->cuts.cuts[i].cliques[j]] += x;
        }
    }

    for (i = 0; i < lp->graph.ncount; i++) {
        node_piest[i] = node_pi[i];
    }

    for (i = 0; i < lp->cuts.cliqueend; i++) {
        x = clique_pi[i];
        if (x > 0.0) {
            for (j = 0; j < lp->cuts.cliques[i].segcount; j++) {
                for (k = lp->cuts.cliques[i].nodes[j].lo;
                     k <= lp->cuts.cliques[i].nodes[j].hi; k++) {
                    node_pi[k] += x;
                    node_piest[k] += x;
                }
            }
        } else if (x < 0.0) {
            for (j = 0; j < lp->cuts.cliques[i].segcount; j++) {
                for (k = lp->cuts.cliques[i].nodes[j].lo;
                     k <= lp->cuts.cliques[i].nodes[j].hi; k++) {
                    node_pi[k] += x;
                }
            }
        }
    }

    /* For now, no munching of edges.  To do in future, just add
       loop here for each edge clique, (if find_edge,)? zero the edge
       clique's pi */

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int price_list (CCtsp_lp *lp, int ecount, CCtsp_predge *elist,
        double *node_pi, double *clique_pi, int phase1)
#else
static int price_list (lp, ecount, elist, node_pi, clique_pi, phase1)
CCtsp_lp *lp;
int ecount;
CCtsp_predge *elist;
double *node_pi;
double *clique_pi;
int phase1;
#endif
{
    CCtsp_lpadj *adjspace = (CCtsp_lpadj *) NULL;
    CCtsp_lpnode *n = (CCtsp_lpnode *) NULL;
    int i, j, k, l;
    CCtsp_lpadj *a;
    int marker = 0;
    double x;
    int ncount = lp->graph.ncount;
    int ccount = lp->cuts.cliqueend;
    CCtsp_lpclique *c = lp->cuts.cliques;

    if (ecount == 0) return 0;

    n = CC_SAFE_MALLOC (ncount, CCtsp_lpnode);
    if (!n) return 1;
    adjspace = CC_SAFE_MALLOC (2*ecount, CCtsp_lpadj);
    if (!adjspace) {
        CC_FREE (n, CCtsp_lpnode);
        return 1;
    }

    for (i = 0; i < ncount; i++) {
        n[i].deg = 0;
        n[i].mark = 0;
    }
    for (i = 0; i < ecount; i++) {
        if (phase1) {
            elist[i].rc = - node_pi[elist[i].ends[0]]
                          - node_pi[elist[i].ends[1]];

        } else {
            elist[i].rc = elist[i].len
                          - node_pi[elist[i].ends[0]]
                          - node_pi[elist[i].ends[1]];
        }

        n[elist[i].ends[0]].deg++;
        n[elist[i].ends[1]].deg++;
    }
    a = adjspace;
    for (i = 0; i < ncount; i++) {
        n[i].adj = a;
        a += n[i].deg;
        n[i].deg = 0;
    }
    for (i=0; i<ecount; i++) {
        j = elist[i].ends[0];
        n[j].adj[n[j].deg].to = elist[i].ends[1];
        n[j].adj[n[j].deg].edge = i;
        n[j].deg++;
        j = elist[i].ends[1];
        n[j].adj[n[j].deg].to = elist[i].ends[0];
        n[j].adj[n[j].deg].edge = i;
        n[j].deg++;
    }

    for (i = 0; i < ccount; i++) {
        if (clique_pi[i]) {
            x = clique_pi[i] * 2;
            marker++;
            for (j = 0; j < c[i].segcount; j++) {
                for (k = c[i].nodes[j].lo; k <= c[i].nodes[j].hi; k++) {
                    a = n[k].adj;
                    for (l = 0; l < n[k].deg; l++) {
                        if (n[a[l].to].mark == marker) {
                            elist[a[l].edge].rc += x;
                            /* We could test if rc>0, and delete e from adj*/
                        }
                    }
                    n[k].mark = marker;
                }
            }
        }
    }
    CC_FREE (n, CCtsp_lpnode);
    CC_FREE (adjspace, CCtsp_lpadj);
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static void pr_select (int nsel, int n, CCtsp_predge *list)
#else
static void pr_select (nsel, n, list)
int nsel;
int n;
CCtsp_predge *list;
#endif
{
    double s1, s2, s3, s;
    int i, j, k, l;
    CCtsp_predge t;

    s1 = list[n/4].rc;
    s2 = list[n/2].rc;
    s3 = list[3*n/4].rc;
    if (s1 < s2) {
        if (s2 < s3) s = s2;
        else if (s1 < s3) s = s3;
        else s = s1;
    } else {
        if (s1 < s3) s = s1;
        else if (s2 < s3) s = s3;
        else s = s2;
    }

    /* 0 <= x < i ==> r[i] == s
     * i <= x < j ==> r[i] > s
     * j <= x <= k ==> r[i] unknown
     * k < x <= l ==> r[i] < s
     * l < x < n ==> r[i] == s
     */

    i = j = 0;
    k = l = n-1;
    while (j <= k) {
        while (j <= k && list[j].rc >= s) {
            if (list[j].rc == s) {
                CC_SWAP (list[i], list[j], t);
                i++;
            }
            j++;
        }
        while (j <= k && list[k].rc <= s) {
            if (list[k].rc == s) {
                CC_SWAP (list[l], list[k], t);
                l--;
            }
            k--;
        }
        if (j <= k) {
            CC_SWAP (list[j], list[k], t);
            j++;
            k--;
        }
    }
    while (i > 0) {
        i--;
        j--;
        CC_SWAP (list[i], list[j], t);
    }
    while (l < n-1) {
        k++;
        l++;
        CC_SWAP (list[k], list[l], t);
    }
    /* 0 <= x < j ==> r[i] > s
     * j <= x <= k ==> r[i] == s
     * k < x < n ==> r[i] < s
     */
    if (nsel < j) {
        pr_select (nsel, j, list);
    } else if (nsel > k) {
        pr_select (nsel - (k+1), n - (k+1), list + (k+1));
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_add_vars_to_lp (CCtsp_lp *lp, CCtsp_predge *prlist, int n)
#else
int CCtsp_add_vars_to_lp (lp, prlist, n)
CCtsp_lp *lp;
CCtsp_predge *prlist;
int n;
#endif
{
    int i;
    CCtsp_lpedge *e;
    int rval;
    int nzcnt;
    double *obj;
    int *matbeg;
    int *matind;
    double *matval;
    double *lb;
    double *ub;

    while (lp->graph.ecount + n > lp->graph.espace) {
        if (CCutil_reallocrus_scale ((void **) &lp->graph.edges,
                &lp->graph.espace,
                lp->graph.ecount + n, 1.3, sizeof (CCtsp_lpedge))) {
            return 1;
        }
    }
    e = lp->graph.edges + lp->graph.ecount;
    for (i = 0; i < n; i++) {
        e[i].ends[0] = prlist[i].ends[0];
        e[i].ends[1] = prlist[i].ends[1];
        e[i].fixed = 0;
        e[i].branch = 0;
        e[i].age = 0;
        e[i].len = prlist[i].len;
        e[i].coefnext = -2;
        e[i].coef = 0;
    }

    rval = build_lp_cols (&lp->graph, &lp->cuts, lp->graph.ecount,
                          lp->graph.ecount + n, &nzcnt, &obj, &matbeg,
                          (int **) NULL, &matind, &matval, &lb, &ub);
    if (rval) return rval;

    rval = lp_addcols (lp, n, nzcnt, obj, matbeg, matind, matval,
                          lb, ub);
    if (rval) goto CLEANUP;

    lp->graph.ecount += n;
    rval = CCtsp_build_lpadj (&lp->graph, 0, lp->graph.ecount);
    if (rval) goto CLEANUP;
    rval = 0;

CLEANUP:

    CC_IFFREE (obj, double);
    CC_IFFREE (matbeg, int);
    CC_IFFREE (matind, int);
    CC_IFFREE (matval, double);
    CC_IFFREE (lb, double);
    CC_IFFREE (ub, double);
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static int age_cuts (CCtsp_lp *lp, int *ndeleted)
#else
static int age_cuts (lp, ndeleted)
CCtsp_lp *lp;
int *ndeleted;
#endif
{
    int *rstat = (int *) NULL;
    int *cutstat = (int *) NULL;
    int *del = (int *) NULL;
    double *cut_pi = (double *) NULL;
    int ncount = lp->graph.ncount;
    int rval;
    int i, j;

    *ndeleted = 0;

    rstat = CC_SAFE_MALLOC (ncount + lp->cuts.cutcount, int);
    if (!rstat) {
        return 1;
    }
    rval = CClp_basis (&lp->lp, (int *) NULL, rstat);
    if (rval) {
        CC_FREE (rstat, int);
        return rval;
    }
    cutstat = rstat + ncount;
    if (lp->cuts.cutcount) {
        cut_pi = CC_SAFE_MALLOC (lp->cuts.cutcount, double);
        if (!cut_pi) {
            CC_FREE (rstat, int);
            return 1;
        }
    }
    rval = get_pi (lp, (double *) NULL, cut_pi);
    if (rval) {
        fprintf (stderr, "get_pi failed\n");
        CC_IFFREE (cut_pi, double);
        CC_FREE (rstat, int);
        return rval;
    }

    for (i = lp->cuts.cutcount-1; i >= 0; i--) {
        if (lp->cuts.cuts[i].branch == 0) {
            if (cut_pi[i]) {
                if (lp->cuts.cuts[i].age == CCtsp_NEWCUT_AGE) {
                    rval = CCtsp_add_to_cutpool (lp->pool, &lp->cuts,
                                                 &lp->cuts.cuts[i]);
                    if (rval) {
                        fprintf (stderr, "add_to_cutpool failed\n");
                        CC_FREE (cut_pi, double);
                        CC_FREE (rstat, int);
                        return rval;
                    }
                }
                lp->cuts.cuts[i].age = 0;
            } else {
                if (lp->cuts.cuts[i].age != CCtsp_NEWCUT_AGE) {
                    lp->cuts.cuts[i].age++;
                }
                if (cutstat[i] == 1 &&
                    (lp->cuts.cuts[i].age == CCtsp_NEWCUT_AGE ||
                     lp->cuts.cuts[i].age >= lp->cut_life)) {
                    CCtsp_unregister_cliques (&lp->cuts, &lp->cuts.cuts[i]);
                    CC_IFFREE (lp->cuts.cuts[i].mods, CCtsp_sparser);
                    lp->cuts.cuts[i].handlecount = 0;
                    lp->cuts.cuts[i].cliquecount = 0;
                    lp->cuts.cuts[i].modcount = 0;
                }
            }
        }
    }
    CC_FREE (rstat, int);
    CC_IFFREE (cut_pi, double);

    del = CC_SAFE_MALLOC (lp->cuts.cutcount, int);
    if (!del) {
        fprintf (stderr, "out of memory in age_cuts\n");
        return 1;
    }
    for (i = 0, j = 0; i < lp->cuts.cutcount; i++) {
        if (lp->cuts.cuts[i].cliquecount) {
            lp->cuts.cuts[j] = lp->cuts.cuts[i];
            j++;
            del[i] = 0;
        } else {
            del[i] = 1;
        }
    }
    if (j < lp->cuts.cutcount) {
        rval = lp_delete_cut_set (lp, del);
        if (rval) {
            fprintf (stderr, "lp_delete_cut_set failed\n");
            CC_FREE (del, int);
            return rval;
        }
    }
    CC_FREE (del, int);

    *ndeleted = lp->cuts.cutcount - j;
    lp->cuts.cutcount = j;
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int age_edges (CCtsp_lp *lp, int *ndeleted)
#else
static int age_edges (lp, ndeleted)
CCtsp_lp *lp;
int *ndeleted;
#endif
{
    int *cstat = (int *) NULL;
    int *del = (int *) NULL;
    int rval;
    int i, j;

    *ndeleted = 0;

    cstat = CC_SAFE_MALLOC (lp->graph.ecount, int);
    if (!cstat) {
        fprintf (stderr, "out of memory in age_edges\n");
        return 1;
    }
    rval = CClp_basis (&lp->lp, cstat, (int *) NULL);
    if (rval) {
        CC_FREE (cstat, int);
        return rval;
    }

    CC_IFFREE (lp->graph.adjspace, CCtsp_lpadj);

    for (i = lp->graph.ecount-1; i >= 0; i--) {
        if (cstat[i] == 0) {
            lp->graph.edges[i].age++;
            if (lp->graph.edges[i].age >= lp->edge_life &&
                !lp->graph.edges[i].fixed && !lp->graph.edges[i].branch) {
                lp->graph.edges[i].ends[0] = 0;
                lp->graph.edges[i].ends[1] = 0;
            }
        } else {
            lp->graph.edges[i].age = 0;
        }
    }
    CC_FREE (cstat, int);

    del = CC_SAFE_MALLOC (lp->graph.ecount, int);
    if (!del) {
        fprintf (stderr, "out of memory in age_edges\n");
        return 1;
    }
    for (i = 0, j = 0; i < lp->graph.ecount; i++) {
        if (lp->graph.edges[i].ends[1] != 0 ||
            lp->graph.edges[i].ends[0] != 0) {
            lp->graph.edges[j] = lp->graph.edges[i];
            j++;
            del[i] = 0;
        } else {
            del[i] = 1;
        }
    }
    if (j < lp->graph.ecount) {
        rval = lp_delete_var_set (lp, del);
        if (rval) {
            fprintf (stderr, "lp_delete_var_set failed\n");
            CC_FREE (del, int);
            return rval;
        }
    }
    CC_FREE (del, int);

    *ndeleted = lp->graph.ecount - j;
    lp->graph.ecount = j;
    rval = CCtsp_build_lpadj (&lp->graph, 0, lp->graph.ecount);
    if (rval) {
        fprintf (stderr, "CCtsp_build_lpadj failed\n");
        return rval;
    }

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int get_pi (CCtsp_lp *lp, double *node_pi, double *cut_pi)
#else
static int get_pi (lp, node_pi, cut_pi)
CCtsp_lp *lp;
double *node_pi;
double *cut_pi;
#endif
{
    int rval;

    if (node_pi) {
        rval = CClp_pi_range (&lp->lp, node_pi, 0, lp->graph.ncount-1);
        if (rval) {
            fprintf (stderr, "CClp_pi_range failed\n");
            return 1;
        }
    }
    if (cut_pi) {
        rval = CClp_pi_range (&lp->lp, cut_pi, lp->graph.ncount,
                              lp->graph.ncount + lp->cuts.cutcount - 1);
        if (rval) {
            fprintf (stderr, "CClp_pi_range failed\n");
            return 1;
        }
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_add_multiple_rows (CCtsp_lp *lp, CCtsp_lprow *cr)
#else
int CCtsp_add_multiple_rows (lp, cr)
CCtsp_lp *lp;
CCtsp_lprow *cr;
#endif
{
    int rval = 0;

    if (!cr->rowcnt)
        return 0;

    rval = CClp_addrows (&lp->lp, cr->rowcnt, cr->nzcnt, cr->rhs, cr->sense,
                         cr->begin, cr->indices, cr->entries);
    if (rval) {
        fprintf (stderr, "Couldn't add rows into LP\n");
    }
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static int addrow_to_list (int nzcnt, double drhs, char sense,
        int *rmatind, double *rmatval, CCtsp_lprow *cr)
#else
static int addrow_to_list (nzcnt, drhs, sense, rmatind, rmatval, cr)
int nzcnt;
double drhs;
char sense;
int *rmatind;
double *rmatval;
CCtsp_lprow *cr;
#endif
{
    int i, rval;
    int *ip;
    double *dp;
    double rhs = drhs; /* copy to work around problem with sun cc -dalign */

    rval = CCutil_reallocrus_count ((void **) &(cr->sense), cr->rowcnt + 1,
                             sizeof (char));
    if (rval) goto CLEANUP;
    rval = CCutil_reallocrus_count ((void **) &(cr->rhs), cr->rowcnt + 1,
                             sizeof (double));
    if (rval) goto CLEANUP;
    rval = CCutil_reallocrus_count ((void **) &(cr->begin), cr->rowcnt + 1,
                             sizeof (int));
    if (rval) goto CLEANUP;

    if (nzcnt + cr->nzcnt > cr->indexspace) {
        rval = CCutil_reallocrus_scale ((void **) &(cr->indices),
               &(cr->indexspace), nzcnt + cr->nzcnt, 1.3, sizeof (int));
        if (rval) goto CLEANUP;
    }
    if (nzcnt + cr->nzcnt > cr->entryspace) {
        rval = CCutil_reallocrus_scale ((void **) &(cr->entries),
               &(cr->entryspace), nzcnt + cr->nzcnt, 1.3, sizeof (double));
        if (rval) goto CLEANUP;
    }

    cr->sense[cr->rowcnt] = sense;
    cr->rhs[cr->rowcnt] = rhs;
    cr->begin[cr->rowcnt] = cr->nzcnt;
    cr->rowcnt++;

    ip = cr->indices + cr->nzcnt;
    dp = cr->entries + cr->nzcnt;
    for (i = 0; i < nzcnt; i++) {
        ip[i] = rmatind[i];
        dp[i] = rmatval[i];
    }
    cr->nzcnt += nzcnt;

    return 0;

CLEANUP:

    fprintf (stderr, "out of memory in addrow_to_list\n");
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static int lp_addcols (CCtsp_lp *lp, int ncols, int nzcnt,
        double *obj, int *matbeg, int *matind, double *matval,
        double *lb, double *ub)
#else
static int lp_addcols (lp, ncols, nzcnt, obj, matbeg, matind, matval, lb, ub)
CCtsp_lp *lp;
int ncols;
int nzcnt;
double *obj;
int *matbeg;
int *matind;
double *matval;
double *lb;
double *ub;
#endif
{
    int rval = 0;

    rval = CClp_addcols (&lp->lp, ncols, nzcnt, obj,
                         matbeg, matind, matval, lb, ub);
    if (rval) {
        fprintf (stderr, "Couldn't add columns into LP\n");
    }
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_delete_cut (CCtsp_lp *lp, int i)
#else
int CCtsp_delete_cut (lp, i)
CCtsp_lp *lp;
int i;
#endif
{
    int rval = 0;
    rval = CClp_delete_row(&lp->lp, lp->graph.ncount + i);
    if (rval) fprintf (stderr, "CClp_delete_row failed\n");
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static int lp_delete_cut_set (CCtsp_lp *lp, int *del)
#else
static int lp_delete_cut_set (lp, del)
CCtsp_lp *lp;
int *del;
#endif
{
    int i, rval = 0;
    int *delstat = (int *) NULL;
    int ncount = lp->graph.ncount;
    int cutcount = lp->cuts.cutcount;

    delstat = CC_SAFE_MALLOC (ncount + cutcount, int);
    if (!delstat) {
        fprintf (stderr, "out of memory in lp_delete_cut_set\n");
        return 1;
    }
    for (i = 0; i < ncount; i++)
        delstat[i] = 0;
    for (i = 0; i < cutcount; i++)
        delstat[i + ncount] = del[i];

    rval = CClp_delete_set_of_rows (&lp->lp, delstat);
    if (rval) {
        fprintf (stderr, "CClp_delete_set_of_rows failed\n");
    }

    CC_FREE (delstat, int);
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static int lp_delete_var_set (CCtsp_lp *lp, int *del)
#else
static int lp_delete_var_set (lp, del)
CCtsp_lp *lp;
int *del;
#endif
{
    int rval = 0;

    rval = CClp_delete_set_of_columns (&lp->lp, del);
    if (rval) {
        fprintf (stderr, "CClp_delete_set_of_columns failed\n");
    }
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_write_probfile_sav (CCtsp_lp *lp)
#else
int CCtsp_write_probfile_sav (lp)
CCtsp_lp *lp;
#endif
{
    return write_probfile (lp, 1);
}


#ifdef CC_PROTOTYPE_ANSI
int CCtsp_write_probfile_id (CCtsp_lp *lp)
#else
int CCtsp_write_probfile_id (lp)
CCtsp_lp *lp;
#endif
{
    return write_probfile (lp, 0);
}

#ifdef CC_PROTOTYPE_ANSI
static int write_probfile (CCtsp_lp *lp, int saveit)
#else
static int write_probfile (lp, saveit)
CCtsp_lp *lp;
int saveit;  /* set to 1 to write to prob.sav */
#endif
{
    CCtsp_PROB_FILE *p = (CCtsp_PROB_FILE *) NULL;
    char fname[1024];
    int len;

    if (!lp) {
        fprintf (stderr, "CCtsp_write_probfile called without an lp\n");
        return 1;
    }
    if (!lp->graph.ecount) {
        fprintf (stderr, "CCtsp_write_probfile called with an edgeset\n");
        return 1;
    }

    if (saveit) {
        len = strlen (lp->name);
        if (len + 40 > 1024) {
            sprintf (fname, "probfile.sav");
        } else {
            sprintf (fname, "%s.sav", lp->name);
        }

        p = CCtsp_prob_write_name (fname, lp->name);
        if (!p) {
            fprintf (stderr, "CCtsp_prob_write_name failed\n");
            return 1;
        }
    } else {
        p = CCtsp_prob_write (lp->name, lp->id);
        if (!p) {
            fprintf (stderr, "CCtsp_prob_write failed\n");
            return 1;
        }
    }

    if (CCtsp_prob_putname (p, lp->name)) goto CLEANUP;
    if (CCtsp_prob_putid (p, lp->id)) goto CLEANUP;
    if (CCtsp_prob_putparent (p, lp->parent_id)) goto CLEANUP;
    if (CCtsp_prob_putnnodes (p, lp->graph.ncount)) goto CLEANUP;
    if (CCtsp_prob_putub (p, lp->upperbound)) goto CLEANUP;
    if (CCtsp_prob_putlb (p, lp->lowerbound)) goto CLEANUP;
    if (CCtsp_prob_putexactlb (p, lp->exact_lowerbound)) goto CLEANUP;
    if (CCtsp_prob_putinfeasible (p, lp->infeasible)) goto CLEANUP;

    {
        int *elist = (int *) NULL;
        int *elen = (int *) NULL;
        int ecount = lp->graph.ecount;
        int i;

        elist = CC_SAFE_MALLOC (2 * ecount, int);
        elen = CC_SAFE_MALLOC (ecount, int);

        if (!elist || !elen) {
            fprintf (stderr, "out of memory in CCtsp_write_probfile\n");
            CC_IFFREE (elist, int);
            CC_IFFREE (elen, int);
            goto CLEANUP;
        }

        for (i = 0; i < ecount; i++) {
            elist[2*i]     = lp->graph.edges[i].ends[0];
            elist[2*i + 1] = lp->graph.edges[i].ends[1];
            elen[i]        = lp->graph.edges[i].len;
        }

        if (CCtsp_prob_putedges (p, ecount, elist, elen)) {
            CC_FREE (elist, int);
            CC_FREE (elen, int);
            goto CLEANUP;
        }
        CC_FREE (elist, int);
        CC_FREE (elen, int);
    }

    if (CCtsp_prob_putcuts (p, (CC_SFILE *) NULL, &(lp->cuts))) goto CLEANUP;

    {
        CClpbasis b;
        int ccount = lp->graph.ecount;
        int rcount = lp->graph.ncount + lp->cuts.cutcount;

        CClp_init_basis (&b);

        if (CClp_get_basis_and_norms (&lp->lp, &b)) {
            printf ("No basis/norms to add to probfile\n");
            fflush (stdout);
        } else {
            if (CCtsp_prob_putbasis (p, ccount, rcount, b.cstat, b.rstat)) {
                CClp_free_basis (&b);
                goto CLEANUP;
            }
            if (CCtsp_prob_putnorms (p, rcount, b.dnorm)) {
                CClp_free_basis (&b);
                goto CLEANUP;
            }
        }
        CClp_free_basis (&b);
    }

    if (lp->nfixededges > 0) {
        if (CCtsp_prob_putfixed (p, lp->nfixededges, lp->fixededges)) {
            fprintf (stderr, "CCtsp_prob_putfixed failed\n");
            goto CLEANUP;
        }
    }

    if (lp->fullcount > 0 && lp->full_edges_valid) {
        if (CCtsp_prob_putfulladj (p, lp->graph.ncount, lp->fullcount,
                              lp->fulladj)) {
            fprintf (stderr, "CCtsp_prob_putfulladj failed\n");
            goto CLEANUP;
        }
    }

    if (lp->exact_dual) {
        if (CCtsp_prob_putexactdual (p, lp->exact_dual, lp->graph.ncount)) {
            fprintf (stderr, "CCtsp_prob_putexact_dual failed\n");
            goto CLEANUP;
        }
    }

    if (CCtsp_prob_puthistory (p, lp->branchdepth, lp->branchhistory)) {
        fprintf (stderr, "CCtsp_prob_puthistory failed\n");
        goto CLEANUP;
    }

    if (CCtsp_prob_wclose (p)) {
        fprintf (stderr, "CCtsp_prob_wclose failed\n");
        return 1;
    }

    return 0;

CLEANUP:

    fprintf (stderr, "CCtsp_write_probfile failed\n");

    if (p)
        CCtsp_prob_wclose (p);
    return 1;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_read_probfile (CCtsp_lp *lp, char *fname, int ncount)
#else
int CCtsp_read_probfile (lp, fname, ncount)
CCtsp_lp *lp;
char *fname;
int ncount;
#endif
{
    CCtsp_PROB_FILE *p = (CCtsp_PROB_FILE *) NULL;

    p = CCtsp_prob_read_name (fname);
    if (!p) {
        fprintf (stderr, "could not open %s for reading\n", fname);
        return 1;
    }

    return read_probfile (lp, p, ncount);
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_read_probfile_id (CCtsp_lp *lp, char *name, int id, int ncount)
#else
int CCtsp_read_probfile_id (lp, name, id, ncount)
CCtsp_lp *lp;
char *name;
int id;
int ncount;
#endif
{
    CCtsp_PROB_FILE *p = (CCtsp_PROB_FILE *) NULL;

    p = CCtsp_prob_read (name, id);
    if (!p) {
        fprintf (stderr, "could not open %s for reading\n", name);
        return 1;
    }

    return read_probfile (lp, p, ncount);
}

#ifdef CC_PROTOTYPE_ANSI
static int read_probfile (CCtsp_lp *lp, CCtsp_PROB_FILE *p, int ncount)
#else
static int read_probfile (lp, p, ncount)
CCtsp_lp *lp;
CCtsp_PROB_FILE *p;
int ncount;
#endif
{
    int tncount, ecount, ccount, rcount;
    int *elist = (int *) NULL;
    int *elen = (int *) NULL;
    int i, k;
    int rval = 0;
    CClpbasis *b = (CClpbasis *) NULL;

    rval = CCtsp_init_cliquehash (&lp->cuts, 2*ncount);
    if (rval) return rval;

    lp->name = CC_SAFE_MALLOC (CCtsp_PROB_FILE_NAME_LEN, char);
    if (!lp->name) {
        fprintf (stderr, "out of memory in read_probfile\n");
        rval = 1;
        goto CLEANUP;
    }
    rval = CCtsp_prob_getname (p, lp->name);
    if (rval == -1) goto CLEANUP;
    printf ("Prob Name: %s\n", lp->name); fflush (stdout);

    rval = CCtsp_prob_getid (p, &(lp->id));
    if (rval == -1) goto CLEANUP;
    printf ("Prob ID: %d\n", lp->id); fflush (stdout);

    rval = CCtsp_prob_getparent (p, &(lp->parent_id));
    if (rval == -1) goto CLEANUP;
    printf ("Prob Parent ID: %d\n", lp->parent_id); fflush (stdout);

    rval = CCtsp_prob_getub (p, &(lp->upperbound));
    if (rval == -1) goto CLEANUP;
    rval = CCtsp_prob_getlb (p, &(lp->lowerbound));
    if (rval == -1) goto CLEANUP;
    printf ("Prob Bounds: (%f, %f)\n", lp->lowerbound, lp->upperbound);
    fflush (stdout);

    rval = CCtsp_prob_getexactlb (p, &(lp->exact_lowerbound));
    if (rval == -1) goto CLEANUP;
    if (CCbigguy_cmp (lp->exact_lowerbound, CCbigguy_MINBIGGUY) != 0) {
        printf ("Prob Exact Lowerbound: %f\n",
                             CCbigguy_bigguytod (lp->exact_lowerbound));
        fflush (stdout);
    }

    rval = CCtsp_prob_getinfeasible (p, &(lp->infeasible));
    if (rval == -1) goto CLEANUP;
    if (lp->infeasible) {
        printf ("Prob stored is tagged as infeasible\n");
        fflush (stdout);
    }

    rval = CCtsp_prob_getnnodes (p, &tncount);
    if (rval == -1) goto CLEANUP;
    if (!rval) {
        if (tncount != ncount) {
            fprintf (stderr, "node counts differ in probfile and input\n");
            rval = 1;
            goto CLEANUP;
        }
    }

    rval = CCtsp_prob_getcuts (p, (CC_SFILE *) NULL, &(lp->cuts));
    if (rval == -1) goto CLEANUP;

    rval = CCtsp_prob_getedges (p, &ecount, &elist, &elen);
    if (rval == -1) goto CLEANUP;
    if (!rval) {
        rval = CCtsp_build_lpgraph (&lp->graph, ncount, ecount, elist, elen);
        if (rval) goto CLEANUP;
        rval = CCtsp_build_lpadj (&lp->graph, 0, ecount);
        if (rval) goto CLEANUP;
        CC_FREE (elist, int);
        CC_FREE (elen, int);
    }

    rval = CCtsp_prob_getfixed (p, &(lp->nfixededges), &(lp->fixededges));
    if (rval == -1) goto CLEANUP;
    if (!rval) {
        printf ("Read %d LP fixed edges\n", lp->nfixededges); fflush (stdout);
        for (i = 0; i < lp->nfixededges; i++) {
            k = CCtsp_find_edge (&(lp->graph), lp->fixededges[2*i],
                                               lp->fixededges[2*i+1]);
            if (k != -1) {
                lp->graph.edges[k].fixed = 1;
            } else {
                printf ("WARNING: File want's to fix a non-lp edge\n");
                fflush (stdout);
            }
        }
    }

    b = CC_SAFE_MALLOC (1, CClpbasis);
    if (!b) {
        fprintf (stderr, "out of memory in read_probfile\n");
        rval = 1; goto CLEANUP;
    }
    CClp_init_basis (b);
    lp->basis = b;

    rval = CCtsp_prob_getbasis (p, &ccount, &rcount, &b->cstat, &b->rstat);
    if (rval == -1) goto CLEANUP;
    if (!rval) {
        if (ccount !=  lp->graph.ecount) {
            fprintf (stderr, "column counts differs in basis probfile\n");
            rval = 1;
            goto CLEANUP;
        }
        if (rcount != lp->graph.ncount + lp->cuts.cutcount) {
            fprintf (stderr, "rcount differs in basis probfile\n");
            rval = 1;
            goto CLEANUP;
        }
    }

    rval = CCtsp_prob_getnorms (p, &rcount, &b->dnorm);
    if (rval == -1) goto CLEANUP;
    if (!rval) {
        if (rcount != lp->graph.ncount + lp->cuts.cutcount) {
            fprintf (stderr, "rcount differs in norms probfile\n");
            rval = 1; goto CLEANUP;
        }
    }

    rval = CCtsp_prob_getfulladj (p, ncount, &(lp->fullcount),
                             &(lp->fulladj), &(lp->fulladjspace));
    if (rval == -1) {
        fprintf (stderr, "CCtsp_prob_getfulladj failed\n");
        goto CLEANUP;
    }
    if (!rval) {
        printf ("Read LP full adj\n"); fflush (stdout);
        if (lp->fullcount) {
            lp->full_edges_valid = 1;
        }
    }

    rval = CCtsp_prob_getexactdual (p, ncount, &(lp->exact_dual));
    if (rval == -1) {
        fprintf (stderr, "CCtsp_prob_getexactdual failed\n");
        goto CLEANUP;
    }
    if (!rval) {
        printf ("Read LP exact dual values\n"); fflush (stdout);
    }

    rval = CCtsp_prob_gethistory (p, &lp->branchdepth, &lp->branchhistory);
    if (rval == -1) {
        fprintf (stderr, "CCtsp_prob_gethistory failed\n");
        goto CLEANUP;
    }
    if (!rval) {
        CCtsp_print_branchhistory (lp);
    }

    rval = 0;


CLEANUP:

    if (CCtsp_prob_rclose (p)) {
        fprintf (stderr, "CCtsp_prob_rclose failed\n");
        return 1;
    }

    printf ("Done with read_probfile\n"); fflush (stdout);
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_dump_x (CCtsp_lp *lp, char *fname)
#else
int CCtsp_dump_x (lp, fname)
CCtsp_lp *lp;
char *fname;
#endif
{
    int i, xcount;
    int nonzero = 0;
    int *xlist = (int *) NULL;
    double *x  = (double *) NULL;
    FILE *out;
    int rval = 0;

    printf ("Dumping the x vector to %s ... ", fname); fflush (stdout);

    rval = CCtsp_get_lp_result (lp, (double *) NULL, (double *) NULL, &xcount,
             &xlist, &x, (double **) NULL, (double **) NULL, (double **) NULL);
    if (rval) {
        fprintf (stderr, "CCtsp_get_lp_result failed\n"); return rval;
    }

    for (i = 0; i < xcount; i++) {
        if (x[i] > CCtsp_INTTOL) {
            nonzero++;
        }
    }

    out = fopen (fname, "w");
    if (out == (FILE *) NULL) {
        fprintf (stderr, "could not open %s for writing\n", fname);
        rval = 1; goto CLEANUP;
    }

    fprintf (out, "%d %d\n", lp->graph.ncount, nonzero);
    for (i = 0; i < xcount; i++) {
        if (x[i] > CCtsp_INTTOL) {
            fprintf (out, "%d %d %f\n", lp->perm[xlist[2*i]],
                                        lp->perm[ xlist[2*i+1]],
                                        x[i]);
        }
    }
    fclose (out);
    printf ("DONE\n"); fflush (stdout);

CLEANUP:

    CC_IFFREE (xlist, int);
    CC_IFFREE (x, double);
    return rval;
}

