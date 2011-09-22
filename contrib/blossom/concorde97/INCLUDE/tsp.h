/***************************************************************************/
/***************************************************************************/
/*                                                                         */
/*                      PROTOTYPES FOR FILES IN CUT                        */
/*                                                                         */
/***************************************************************************/
/***************************************************************************/


#ifndef __TSP_H
#define __TSP_H

#include "util.h"
#include "edgegen.h"
#include "bigguy.h"
#include "lp.h"
#include "cut.h"
#include "kdtree.h"

/*************** Tolerances for the LP and Cutting routines ***************/

#define CCtsp_MIN_VIOL (0.00001)   /* min violation for cut to be added to lp */
#define CCtsp_CUTS_NEXT_TOL (0.0001)       /* to try next level  */
#define CCtsp_CUTS_NEXT_ROUND (0.00000001) /* if improve is less, stop round */
#define CCtsp_PRICE_RCTHRESH  (-0.00001)   /* to add a bad edge */
#define CCtsp_PRICE_MAXPENALTY (0.49)      /* penalty permitted in addbad */
#define CCtsp_PHASE1_RCTHRESH (-0.000000001)
#define CCtsp_PHASE1_MAXPENALTY (0.00000001)
#define CCtsp_EDGE_LIFE (1000000) /* 200 */  /* Large for subtour runs */
#define CCtsp_CUT_LIFE  (50)
#define CCtsp_CUT_BATCH (250)     /* number of new cuts before lp optimize */
#define CCtsp_STORE_BATCH (50)    /* number of new cuts before lp addrows  */
#define CCtsp_INTTOL (0.0001)     /* used to check if lp soln is integral  */

/************************** Branching Strategies  ************************/

#define CCtsp_BRANCH_MIDDLE 1
#define CCtsp_BRANCH_STRONG 2

/*************************************************************************/

#define CCtsp_LP_MAXDOUBLE  1e30

#define CCtsp_CUTRHS(c) (3*(c)->cliquecount - (c)->handlecount - 1)

typedef struct CCtsp_lpnode {
    int                 deg;
    int                 mark;
    struct CCtsp_lpadj *adj;
} CCtsp_lpnode;

typedef struct CCtsp_lpedge {
    int ends[2];   /* ends[0] should always be < ends[1] */
    int fixed;
    int branch;    /* < 0 means set to 0 and > 0 means set to 1 */
    int len;
    int age;
    int coef;      /* should be maintained at zero */
    int coefnext;  /* should be maintained at -2 */
} CCtsp_lpedge;

typedef struct CCtsp_lpadj {
    int to;
    int edge;
} CCtsp_lpadj;

typedef struct CCtsp_lpgraph {
    int           ncount;
    int           espace;
    int           ecount;
    int           nodemarker;
    CCtsp_lpnode *nodes;
    CCtsp_lpedge *edges;
    CCtsp_lpadj  *adjspace;
    int           adjstart;
    int           adjend;
} CCtsp_lpgraph;

typedef struct CCtsp_predge {
    int    ends[2];
    int    len;
    double rc;
} CCtsp_predge;

typedef struct CCtsp_pricegroup {
    int                    ncount;
    int                    espace;
    int                    ecount;
    CCtsp_lpnode          *nodes;
    CCtsp_predge          *edges;
    int                    cliquecount;
    struct CCtsp_lpclique *cliques; /* just a copy of the pointer */
    CCtsp_lpgraph         *graph;   /* pointer to the copy in a CCtsp_lp */
    CCtsp_lpadj           *adjspace;
    double                *node_pi;
    double                *clique_pi;
    double                 penalty;
} CCtsp_pricegroup;

typedef struct CCtsp_extraedge {
    int ends[2];
} CCtsp_extraedge;

typedef struct CCtsp_sparser {
    unsigned int node : 24;
    unsigned int mult : 8;
} CCtsp_sparser;

typedef struct CCtsp_segment {
    int lo;
    int hi;
} CCtsp_segment;

typedef struct CCtsp_lpclique {
    int                   segcount;
    struct CCtsp_segment *nodes;
    int                   hashnext;
    int                   refcount;
} CCtsp_lpclique;

#define CC_FOREACH_NODE_IN_CLIQUE(i,c,tmp) \
    for(tmp=0;tmp<(c).segcount;tmp++) \
        for(i=(c).nodes[tmp].lo;i<=(c).nodes[tmp].hi;i++)

#define CCtsp_NEWCUT_AGE (-1)

typedef struct CCtsp_lpcut {
    int                   handlecount;
    int                   cliquecount;
    int                   modcount;
    int                   age;
    int                   rhs;
    char                  sense;
    char                  branch;
    int                  *cliques;
    struct CCtsp_sparser *mods;
} CCtsp_lpcut;

typedef struct CCtsp_lpcut_in {
    int                    handlecount;
    int                    cliquecount;
    int                    rhs;
    char                   sense;
    char                   branch;
    CCtsp_lpclique        *cliques;
    struct CCtsp_lpcut_in *next;
    struct CCtsp_lpcut_in *prev;
} CCtsp_lpcut_in;

typedef struct CCtsp_lp_result {
    double         ub;
    double         lb;
    int            ecount;
    int           *elist;
    double        *x;
    double        *rc;
} CCtsp_lp_result;

typedef struct CCtsp_lpcuts {
    int            cutcount;
    int            cliqueend;
    int            cutspace;
    int            cliquespace;
    int            cliquehashsize;
    int            cliquefree;
    int            *cliquehash;
    CCtsp_lpcut    *cuts;
    CCtsp_lpclique *cliques;
    CCgenhash      *cuthash;
    char           *tempcuthash;
    int            tempcuthashsize;
} CCtsp_lpcuts;

typedef struct CCtsp_bigdual {
    int            cutcount;
    CCbigguy      *node_pi;
    CCbigguy      *cut_pi;
} CCtsp_bigdual;

typedef struct CCtsp_tighten_info {
    int    ncall;
    int    nfail;
    int    nadd;
    int    nadd_tied;
    int    ndel;
    int    ndel_tied;
    double add_delta;
    double del_delta;
    double time;
} CCtsp_tighten_info;

typedef struct CCtsp_branchobj {
    int             depth;
    int             rhs;
    int             ends[2];
    char            sense;
    CCtsp_lpclique *clique;
} CCtsp_branchobj;

typedef struct CCtsp_cutselect {
    int    cutpool;
    int    connect;
    int    segments;
    int    exactsubtour;
    int    tighten_lp;
    int    decker_lp;
    int    teething_lp;
    int    tighten_pool;
    int    decker_pool;
    int    teething_pool;
    int    maxchunksize;
    int    Xfastcuts;
    int    Xexactsubtours;
    int    Xslowcuts;
    int    consecutiveones;
    int    necklace;
    int    usetighten;     /* set to 1 to tighten before cuts are added */
    int    extra_connect;  /* set to 1 to force a connected solution */
    double nexttol;
    double roundtol;
} CCtsp_cutselect;

/* nodes are reordered to match compression tour */

typedef struct CCtsp_genadj {
    int                     deg;
    struct CCtsp_genadjobj *list;
} CCtsp_genadj;

typedef struct CCtsp_genadjobj {
    int end;
    int len;
} CCtsp_genadjobj;

typedef struct CCtsp_edgegenerator {
    double                    *node_piest;
    struct CCdatagroup        *dg;
    int                       *supply;
    CCkdtree                  *kdtree;
    CCxnear                   *xnear;
    struct CCtsp_xnorm_pricer *xprice;
    CCtsp_genadjobj           *adjobjspace;
    CCtsp_genadj              *adj;
    int                        ncount;
    int                        nneighbors;
    int                        start;
    int                        current;
    int                        supplyhead;
    int                        supplycount;
} CCtsp_edgegenerator;

typedef struct CCtsp_xnorm_pricer_val {
    double                         val;
    struct CCtsp_xnorm_pricer_val *next;
    struct CCtsp_xnorm_pricer_val *prev;
    int                            index;
} CCtsp_xnorm_pricer_val;

typedef struct CCtsp_xnorm_pricer {
    CCdatagroup            *dat;
    double                 *pi;
    int                    *order;
    CCtsp_xnorm_pricer_val *xminuspi_space;
    CCtsp_xnorm_pricer_val *xminuspi;
    int                    *invxminuspi;
    int                     ncount;
} CCtsp_xnorm_pricer;

typedef struct CCtsp_lp {
    CCtsp_lpgraph              graph;
    CCtsp_lpcuts               cuts;
    CCtsp_lpcuts              *pool;
    CClp                       lp;
    int                       *perm;
    CCdatagroup               *dat;
    int                        fullcount;
    struct CCtsp_genadj       *fulladj;
    struct CCtsp_genadjobj    *fulladjspace;
    int                        nfixededges;
    int                       *fixededges;
    struct CCtsp_qsparsegroup *sparsifier;
    int                        edge_life;
    int                        cut_life;
    char                      *name;
    int                        id;
    int                        parent_id;
    int                        root;
    double                     upperbound;
    double                     lowerbound;
    CCbigguy                   exact_lowerbound;
    CCtsp_bigdual             *exact_dual;
    int                        infeasible;
    int                        full_edges_valid;
    CClpbasis                 *basis;
    CCtsp_lpcut_in             cutqueue;    /* dummy entry for doubly-linked
                                               list */
    CCtsp_lp_result            result;
    CCtsp_tighten_info         tighten_stats;
    int                        branchdepth;
    CCtsp_branchobj           *branchhistory;
} CCtsp_lp;

typedef struct CCtsp_lprow {
    int           rowcnt;
    int           nzcnt;
    char         *sense;
    double       *rhs;
    int          *begin;      /* offset into the array for start of row */
    int           indexspace;
    int          *indices;    /* the column indices of the row entries  */
    int           entryspace;
    double       *entries;    /* the matrix entries                     */
} CCtsp_lprow;



/***************************************************************************/
/*                                                                         */
/*                             tsp_lp.c                                    */
/*                                                                         */
/***************************************************************************/

#ifdef CC_PROTOTYPE_ANSI

int
    CCtsp_cutting_loop (CCtsp_lp *lp, CCtsp_cutselect *sel, int savelp),
    CCtsp_subtour_loop (CCtsp_lp *lp),
    CCtsp_pricing_loop (CCtsp_lp *lp, double *bnd),
    CCtsp_init_cutselect (CCtsp_lp *lp, CCtsp_cutselect *s),
    CCtsp_call_x_heuristic (CCtsp_lp *lp, double *val, int *outcyc),
    CCtsp_bb_cutting (char *probname, int probnum, int ncount,
            CCdatagroup *dat, int *ptour, double *upbound, CCtsp_lpcuts *pool,
            CCtsp_cutselect *sel, double *val, int *prune, int *foundtour,
            int *besttour),
    CCtsp_init_lp (CCtsp_lp **lp, char *probname, int probnum,
            char *probfilename, int ncount, CCdatagroup *dat, int ecount,
            int *elist, int *elen, int excount, int *exlist, int *exlen,
            int exvalid, int *ptour, double initial_ub, CCtsp_lpcuts *pool),
    CCtsp_bb_init_lp (CCtsp_lp **lp, char *probname, int probnum,
            int ncount, CCdatagroup *dat, int *ptour, double initial_ub,
            CCtsp_lpcuts *pool),
    CCtsp_get_lp_result (CCtsp_lp *lp, double *lb, double *ub, int *ecount,
            int **elist, double **x, double **rc, double **node_pi,
            double **cut_pi),
    CCtsp_process_cuts (CCtsp_lp *lp, int *pnadded, int tighten),
    CCtsp_add_cut_to_cutlist (CCtsp_lpcuts *cuts, CCtsp_lpcut *c),
    CCtsp_add_cut (CCtsp_lp *lp, CCtsp_lpcut_in *d, CCtsp_lprow *cr),
    CCtsp_lpcut_in_nzlist (CCtsp_lpgraph *g, CCtsp_lpcut_in *c),
    CCtsp_add_nzlist_to_lp (CCtsp_lp *lp, int nzlist, int rhs, char sense,
            CCtsp_lprow *cr),
    CCtsp_add_vars_to_lp (CCtsp_lp *lp, CCtsp_predge *prlist, int n),
    CCtsp_update_result (CCtsp_lp *lp),
    CCtsp_infeas_recover (CCtsp_lp *lp),
    CCtsp_test_cut_branch (CCtsp_lp *lp, CCtsp_lpclique *c, double *down,
            double *up),
    CCtsp_register_cliques (CCtsp_lpcuts *cuts, CCtsp_lpcut_in *c,
            CCtsp_lpcut *new),
    CCtsp_addbad_variables (CCtsp_lp *lp, struct CCtsp_edgegenerator *eg,
            double *ppenalty, int *pnadded, double rcthresh,
            double maxpenalty, int phase1, int *feasible),
    CCtsp_eliminate_variables (CCtsp_lp *lp),
    CCtsp_build_lpgraph (CCtsp_lpgraph *g, int ncount, int ecount,
            int *elist, int *elen),
    CCtsp_build_lpadj (CCtsp_lpgraph *g, int estart, int eend),
    CCtsp_add_multiple_rows (CCtsp_lp *lp, CCtsp_lprow *cr),
    CCtsp_delete_cut (CCtsp_lp *lp, int i),
    CCtsp_find_edge (CCtsp_lpgraph *g, int from, int to),
    CCtsp_find_branch (CCtsp_lp *lp, int nwant, int *ngot,
            CCtsp_branchobj **bobj, double *val, int **cyc, int usecliques),
    CCtsp_bb_find_branch (char *probname, int probnum, int ncount,
            CCdatagroup *dat, int *ptour, double *upperbound,
            CCtsp_lpcuts *pool, CCtsp_branchobj **b, int usecliques,
            int *foundtour, int *besttour),
    CCtsp_check_integral (CCtsp_lp *lp, double *val, int **cyc, int *yesno),
    CCtsp_find_branch_edge (CCtsp_lp *lp, int *n0, int *n1, double *val,
            int **cyc, int branchtype),
    CCtsp_find_branch_cliques (CCtsp_lp *lp, int nwant, int *ngot,
            CCtsp_lpclique **bcliques, double **bval),
    CCtsp_execute_branch (CCtsp_lp *lp, CCtsp_branchobj *b),
    CCtsp_execute_unbranch (CCtsp_lp *lp, CClpbasis *basis),
    CCtsp_splitprob (CCtsp_lp *lp, CCtsp_branchobj *b, int child0, int child1),
    CCtsp_bb_splitprob (char *probname, int probnum, int ncount,
            CCdatagroup *dat, int *ptour, double initial_ub, CCtsp_lpcuts *pool,
            CCtsp_branchobj *b, int child0, int child1, double *val0,
            double *val1, int *prune0, int *prune1),
    CCtsp_dumptour (int ncount, CCdatagroup *dat, int *perm, char *probname,
            int *tour),
    CCtsp_add_branchhistory_to_lp (CCtsp_lp *lp),
    CCtsp_easy_dfs_brancher (CCtsp_lp *lp, CCtsp_cutselect *sel, int depth,
            double *upbound, int *bbcount, int usecliques, int *besttour),
    CCtsp_bfs_brancher (char *probname, int id, double lowerbound,
            CCtsp_cutselect *sel, double *upbound, int *bbcount, int usecliques,
            CCdatagroup *mydat, int *ptour, CCtsp_lpcuts *pool, int ncount,
            int *besttour),
    CCtsp_do_interactive_branch (CCtsp_lp *lp),
    CCtsp_inspect_full_edges (CCtsp_lp *lp),
    CCtsp_read_probfile (CCtsp_lp *lp, char *fname, int ncount),
    CCtsp_read_probfile_id (CCtsp_lp *lp, char *fname, int id, int ncount),
    CCtsp_write_probfile_sav (CCtsp_lp *lp),
    CCtsp_write_probfile_id (CCtsp_lp *lp),
    CCtsp_dump_x (CCtsp_lp *lp, char *fname),
    CCtsp_exact_price (CCtsp_lp *lp, CCbigguy *bound, int phase1),
    CCtsp_edge_elimination (CCtsp_lp *lp),
    CCtsp_exact_dual (CCtsp_lp *lp),
    CCtsp_verify_infeasible_lp (CCtsp_lp *lp, int *yesno),
    CCtsp_verify_lp_prune (CCtsp_lp *lp, int *yesno),
    CCtsp_tighten_lpcut_in (CCtsp_lpgraph *g, CCtsp_lpcut_in *c,
            double *x, CCtsp_lpcut_in *d, CCtsp_tighten_info *stats,
            double *pimprove),
    CCtsp_tighten_lpcut (CCtsp_lpgraph *g, CCtsp_lpclique *cliques,
            CCtsp_lpcut *c, double *x, CCtsp_lpcut_in *d,
            CCtsp_tighten_info *stats, double *pimprove),
    CCtsp_test_pure_comb (int ncount, CCtsp_lpcut_in *c, int *yes_no,
            int *handle),
    CCtsp_test_pseudocomb (int ncount, CCtsp_lpcut_in *c, int handle,
            int *yes_no),
    CCtsp_test_teeth_disjoint (int ncount, CCtsp_lpcut_in *c, int handle,
            int *yes_no),
    CCtsp_find_pure_handle (int ncount, CCtsp_lpcut_in *c, int *handle),
    CCtsp_comb_to_double_decker (CCtsp_lpgraph *g, double *x,
            CCtsp_lpcut_in *c, CCtsp_lpcut_in **d),
    CCtsp_teething (CCtsp_lpgraph *g, double *x, CCtsp_lpcut_in *cut,
            CCtsp_lpcut_in **newcut),
    CCtsp_init_cutpool (int ncount, char *poolfilename, CCtsp_lpcuts **pool),
    CCtsp_write_cutpool (int ncount, char *poolfilename, CCtsp_lpcuts  *pool),
    CCtsp_search_cutpool (CCtsp_lpcuts *pool, CCtsp_lpcut_in **cuts,
            int *cutcount, int ncount, int ecount, int *elist, double *x),
    CCtsp_search_cutpool_cliques (CCtsp_lpcuts *pool, CCtsp_lpclique **cliques,
            int *cliquecount, int ncount, int ecount, int *elist, double *x,
            double maxdelta, int maxcliques, double **cliquevals),
    CCtsp_branch_cutpool_cliques (CCtsp_lpcuts *pool, CCtsp_lpclique **cliques,
            int *cliquecount, int ncount, int ecount, int *elist, double *x,
            int nwant, double **cliquevals),
    CCtsp_add_to_cutpool (CCtsp_lpcuts *pool, CCtsp_lpcuts *cuts,
            CCtsp_lpcut *c),
    CCtsp_add_to_cutpool_lpcut_in (CCtsp_lpcuts *pool, CCtsp_lpcut_in *cut),
    CCtsp_display_cutpool (CCtsp_lpcuts *pool),
    CCtsp_price_cuts (CCtsp_lpcuts *pool, int ncount, int ecount, int *elist,
            double *x, double *cutval),
    CCtsp_clique_to_array (CCtsp_lpclique *c, int **ar, int *count),
    CCtsp_clique_delta (CCtsp_lpgraph *g, double *x, CCtsp_lpclique *c,
            double *delta),
    CCtsp_x_greedy_tour (CCdatagroup *dat, int ncount, int ecount, int *elist,
            double *x, int *cyc, double *val),
    CCtsp_x_greedy_tour_lk (CCdatagroup *dat, int ncount, int ecount,
            int *elist, double *x, int *cyc, double *val);

void
    CCtsp_init_tsp_lp_struct (CCtsp_lp *lp),
    CCtsp_free_tsp_lp_struct (CCtsp_lp **lp),
    CCtsp_add_cuts_to_queue (CCtsp_lp *lp, CCtsp_lpcut_in **c),
    CCtsp_delete_cut_from_cutlist (CCtsp_lpcuts *cuts, int ind),
    CCtsp_init_lprow (CCtsp_lprow *cr),
    CCtsp_free_lprow (CCtsp_lprow *cr),
    CCtsp_unregister_cliques (CCtsp_lpcuts *cuts, CCtsp_lpcut *c),
    CCtsp_free_cutpool (CCtsp_lpcuts **pool),
    CCtsp_init_lpgraph_struct (CCtsp_lpgraph *g),
    CCtsp_free_lpgraph (CCtsp_lpgraph *g),
    CCtsp_free_lpcut_in (CCtsp_lpcut_in *c),
    CCtsp_free_lpclique (CCtsp_lpclique *c),
    CCtsp_free_bigdual (CCtsp_bigdual **d),
    CCtsp_init_branchobj (CCtsp_branchobj *b),
    CCtsp_free_branchobj (CCtsp_branchobj *b),
    CCtsp_print_branchhistory (CCtsp_lp *lp),
    CCtsp_init_tighten_info (CCtsp_tighten_info *stats),
    CCtsp_print_tighten_info (CCtsp_tighten_info *stats),
    CCtsp_mark_clique (CCtsp_lpclique *c, int *marks, int marker),
    CCtsp_mark_clique_and_neighbors (CCtsp_lpgraph *g, CCtsp_lpclique *c,
           int *marks, int marker),
    CCtsp_mark_cut (CCtsp_lpcut_in *c, int *marks, int marker),
    CCtsp_mark_cut_and_neighbors (CCtsp_lpgraph *g, CCtsp_lpcut_in *c,
           int *marks, int marker),
    CCtsp_mark_clique_and_neighbors_double (CCtsp_lpgraph *g, CCtsp_lpclique *c,
           double *marks, double marker),
    CCtsp_is_clique_marked (CCtsp_lpclique *c, int *marks, int marker,
           int *yes_no),
    CCtsp_clique_count (CCtsp_lpclique *c, int *count);


double
    CCtsp_cutprice (CCtsp_lpgraph *g, CCtsp_lpcut_in *c, double *x);

#else

int
    CCtsp_cutting_loop (),
    CCtsp_subtour_loop (),
    CCtsp_pricing_loop (),
    CCtsp_init_cutselect (),
    CCtsp_call_x_heuristic (),
    CCtsp_bb_cutting (),
    CCtsp_init_lp (),
    CCtsp_bb_init_lp (),
    CCtsp_get_lp_result (),
    CCtsp_process_cuts (),
    CCtsp_add_cut_to_cutlist (),
    CCtsp_add_cut (),
    CCtsp_lpcut_in_nzlist (),
    CCtsp_add_nzlist_to_lp (),
    CCtsp_add_vars_to_lp (),
    CCtsp_update_result (),
    CCtsp_infeas_recover (),
    CCtsp_test_cut_branch (),
    CCtsp_register_cliques (),
    CCtsp_addbad_variables (),
    CCtsp_eliminate_variables (),
    CCtsp_build_lpgraph (),
    CCtsp_build_lpadj (),
    CCtsp_add_multiple_rows (),
    CCtsp_delete_cut (),
    CCtsp_find_edge (),
    CCtsp_find_branch (),
    CCtsp_bb_find_branch (),
    CCtsp_check_integral (),
    CCtsp_find_branch_edge (),
    CCtsp_find_branch_cliques (),
    CCtsp_execute_branch (),
    CCtsp_execute_unbranch (),
    CCtsp_splitprob (),
    CCtsp_bb_splitprob (),
    CCtsp_dumptour (),
    CCtsp_add_branchhistory_to_lp (),
    CCtsp_easy_dfs_brancher (),
    CCtsp_bfs_brancher (),
    CCtsp_do_interactive_branch (),
    CCtsp_inspect_full_edges (),
    CCtsp_read_probfile (),
    CCtsp_read_probfile_id (),
    CCtsp_write_probfile_sav (),
    CCtsp_write_probfile_id (),
    CCtsp_dump_x (),
    CCtsp_exact_price (),
    CCtsp_edge_elimination (),
    CCtsp_exact_dual (),
    CCtsp_verify_infeasible_lp (),
    CCtsp_verify_lp_prune (),
    CCtsp_tighten_lpcut_in (),
    CCtsp_tighten_lpcut (),
    CCtsp_test_pure_comb (),
    CCtsp_test_pseudocomb (),
    CCtsp_test_teeth_disjoint (),
    CCtsp_find_pure_handle (),
    CCtsp_comb_to_double_decker (),
    CCtsp_teething (),
    CCtsp_init_cutpool (),
    CCtsp_write_cutpool (),
    CCtsp_search_cutpool (),
    CCtsp_search_cutpool_cliques (),
    CCtsp_branch_cutpool_cliques (),
    CCtsp_add_to_cutpool (),
    CCtsp_add_to_cutpool_lpcut_in (),
    CCtsp_display_cutpool (),
    CCtsp_price_cuts (),
    CCtsp_clique_to_array (),
    CCtsp_clique_delta (),
    CCtsp_x_greedy_tour (),
    CCtsp_x_greedy_tour_lk ();

void
    CCtsp_init_tsp_lp_struct (),
    CCtsp_free_tsp_lp_struct (),
    CCtsp_add_cuts_to_queue (),
    CCtsp_delete_cut_from_cutlist (),
    CCtsp_init_lprow (),
    CCtsp_free_lprow (),
    CCtsp_unregister_cliques (),
    CCtsp_free_cutpool (),
    CCtsp_init_lpgraph_struct (),
    CCtsp_free_lpgraph (),
    CCtsp_free_lpcut_in (),
    CCtsp_free_lpclique (),
    CCtsp_free_bigdual (),
    CCtsp_init_branchobj (),
    CCtsp_free_branchobj (),
    CCtsp_print_branchhistory (),
    CCtsp_init_tighten_info (),
    CCtsp_print_tighten_info (),
    CCtsp_mark_clique (),
    CCtsp_mark_clique_and_neighbors (),
    CCtsp_mark_cut (),
    CCtsp_mark_cut_and_neighbors (),
    CCtsp_mark_clique_and_neighbors_double (),
    CCtsp_is_clique_marked (),
    CCtsp_clique_count ();


double
    CCtsp_cutprice ();

#endif

/***************************************************************************/
/*                                                                         */
/*                             cliqhash.c                                  */
/*                                                                         */
/***************************************************************************/

#ifdef CC_PROTOTYPE_ANSI

int
    CCtsp_init_cliquehash (CCtsp_lpcuts *cuts, int size),
    CCtsp_register_clique (CCtsp_lpcuts *cuts, CCtsp_lpclique *c);

void
    CCtsp_free_cliquehash (CCtsp_lpcuts *cuts),
    CCtsp_unregister_clique (CCtsp_lpcuts *cuts, int c);

#else

int
    CCtsp_init_cliquehash (),
    CCtsp_register_clique ();

void
    CCtsp_free_cliquehash (),
    CCtsp_unregister_clique ();

#endif



/***************************************************************************/
/*                                                                         */
/*                             cutcall.c                                   */
/*                                                                         */
/***************************************************************************/

typedef struct cutinfo {
    CC_SRKexpinfo expand;
    CCtsp_lpcut_in **clist;
    CCtsp_lpcut_in *current;
    int *cutcount;
} cutinfo;

#ifdef CC_PROTOTYPE_ANSI

int
    CCtsp_connect_cuts (CCtsp_lpcut_in **cuts, int *cutcount, int ncount,
            int ecount, int *elist, double *x),
    CCtsp_segment_cuts (CCtsp_lpcut_in **cuts, int *cutcount, int ncount,
            int ecount, int *elist, double *x),
    CCtsp_exact_subtours (CCtsp_lpcut_in **cuts, int *cutcount, int ncount,
            int ecount, int *elist, double *x),
    CCtsp_tighten_lp (CCtsp_lpcuts *cuts, CCtsp_tighten_info *stats,
            CCtsp_lpcut_in **cutsout, int *cutcount, int ncount, int ecount,
            int *elist, double *x, double testtol, int maxcuts),
    CCtsp_double_decker_lp (CCtsp_lpcuts *cuts, CCtsp_tighten_info *stats,
            CCtsp_lpcut_in **cutsout, int *cutcount, int ncount, int ecount,
            int *elist, double *x, double testtol, int maxcuts),
    CCtsp_teething_lp (CCtsp_lpcuts *cuts, CCtsp_tighten_info *stats,
            CCtsp_lpcut_in **cutsout, int *cutcount, int ncount, int ecount,
            int *elist, double *x, double testtol, int maxcuts),
    CCtsp_copy_lpcut_in (CCtsp_lpcut_in *c, CCtsp_lpcut_in *new),
    CCtsp_segment_to_subtour (CCtsp_lpcut_in **cut, int a, int b),
    CCtsp_array_to_subtour (CCtsp_lpcut_in **cut, int *ar, int acount),
    CCtsp_array_to_lpclique (int *ar, int acount, CCtsp_lpclique *cliq),
    CCtsp_seglist_to_lpclique (int nseg, int *list, CCtsp_lpclique *cliq),
    CCtsp_add_node_to_lpclique (CCtsp_lpclique *cin, CCtsp_lpclique *cout,
            int n),
    CCtsp_delete_node_from_lpclique (CCtsp_lpclique *cin,
            CCtsp_lpclique *cout, int n),
    CCtsp_lpcut_to_lpcut_in (CCtsp_lpcuts *cuts, CCtsp_lpcut *c,
            CCtsp_lpcut_in *new),
    CCtsp_copy_lpclique (CCtsp_lpclique *c, CCtsp_lpclique *new),
    CCtsp_file_cuts (char *cutfile, CCtsp_lpcut_in **cuts, int *cutcount,
            int ncount, int *tour),
    CCtsp_file_cuts_write (char *cutfile, CCtsp_lpcuts *cuts, int *tour),
    CCtsp_buildcut_begin (cutinfo *cuts, int init_cliquecount),
    CCtsp_buildcut_addclique (cutinfo *cuts, int *arr, int size, int handle);

void
    CCtsp_init_lpcut_in (CCtsp_lpcut_in *c),
    CCtsp_init_lpclique (CCtsp_lpclique *c),
    CCtsp_print_lpcut_in (CCtsp_lpcut_in *c),
    CCtsp_print_lpclique (CCtsp_lpclique *c),
    CCtsp_lpclique_compare (CCtsp_lpclique *a, CCtsp_lpclique *b, int *diff),
    CCtsp_buildcut_abort (cutinfo *cuts),
    CCtsp_buildcut_finish (cutinfo *cuts, int rhs);

#else

int
    CCtsp_connect_cuts (),
    CCtsp_segment_cuts (),
    CCtsp_exact_subtours (),
    CCtsp_tighten_lp (),
    CCtsp_double_decker_lp (),
    CCtsp_teething_lp (),
    CCtsp_copy_lpcut_in (),
    CCtsp_segment_to_subtour (),
    CCtsp_array_to_subtour (),
    CCtsp_array_to_lpclique (),
    CCtsp_seglist_to_lpclique (),
    CCtsp_add_node_to_lpclique (),
    CCtsp_delete_node_from_lpclique (),
    CCtsp_lpcut_to_lpcut_in (),
    CCtsp_copy_lpclique (),
    CCtsp_file_cuts (),
    CCtsp_file_cuts_write (),
    CCtsp_buildcut_begin (),
    CCtsp_buildcut_addclique ();

void
    CCtsp_init_lpcut_in (),
    CCtsp_init_lpclique (),
    CCtsp_print_lpcut_in (),
    CCtsp_print_lpclique (),
    CCtsp_lpclique_compare (),
    CCtsp_buildcut_abort (),
    CCtsp_buildcut_finish ();

#endif



/***************************************************************************/
/*                                                                         */
/*                             edgemap.c                                   */
/*                                                                         */
/***************************************************************************/

typedef struct CCtsp_edgeinf {
    int ends[2];
    int val;
    struct CCtsp_edgeinf *next;
} CCtsp_edgeinf;

typedef struct CCtsp_edgehash {
    struct CCtsp_edgeinf **table;
    unsigned int size;
    unsigned int mult;
} CCtsp_edgehash;


#ifdef CC_PROTOTYPE_ANSI

int
    CCtsp_edgehash_init (CCtsp_edgehash *h, int size),
    CCtsp_edgehash_add (CCtsp_edgehash *h, int end1, int end2, int val),
    CCtsp_edgehash_del (CCtsp_edgehash *h, int end1, int end2),
    CCtsp_edgehash_find (CCtsp_edgehash *h, int end1, int end2);

void
    CCtsp_edgehash_delall (CCtsp_edgehash *h),
    CCtsp_edgehash_free (CCtsp_edgehash *h);

#else

int
    CCtsp_edgehash_init (),
    CCtsp_edgehash_add (),
    CCtsp_edgehash_del (),
    CCtsp_edgehash_find ();

void
    CCtsp_edgehash_delall (),
    CCtsp_edgehash_free ();

#endif


/***************************************************************************/
/*                                                                         */
/*                             generate.c                                  */
/*                                                                         */
/***************************************************************************/

#define CCtsp_PRICE_COMPLETE_GRAPH -1
#define CCtsp_GEN_PRICE_EPSILON 0.0001 /* 0.0000001 */
#define CCtsp_GEN_USE_ADJ 50           /* Cutoff for using explicit adj list */

#ifdef CC_PROTOTYPE_ANSI

void
    CCtsp_free_edgegenerator (CCtsp_edgegenerator *eg);

int
    CCtsp_init_edgegenerator (CCtsp_edgegenerator *eg, int ncount,
            CCdatagroup *dg, CCtsp_genadj *adj, int nneighbors),
    CCtsp_reset_edgegenerator (CCtsp_edgegenerator *eg, double *node_piest),
    CCtsp_generate_edges (CCtsp_edgegenerator *eg, int nwant, int *pngot,
            int *elist, int *elen, int *finished),
    CCtsp_edgelist_to_genadj (int ncount, int ecount, int *elist, int *elen,
            CCtsp_genadj **adj, CCtsp_genadjobj **adjobjspace);

#else

void
    CCtsp_free_edgegenerator ();

int
    CCtsp_init_edgegenerator (),
    CCtsp_reset_edgegenerator (),
    CCtsp_generate_edges (),
    CCtsp_edgelist_to_genadj ();

#endif



/***************************************************************************/
/*                                                                         */
/*                             prob_io.c                                   */
/*                                                                         */
/***************************************************************************/

#define CCtsp_PROB_IO_VERSION  1
#define CCtsp_PROB_FILE_NAME_LEN 128

#define CCtsp_PROB_IO_CUTS_VERSION_BASE  -1000
#define CCtsp_PROB_IO_CUTS_VERSION       -1001   /* Should be <= BASE (-1000) */

typedef struct CCtsp_PROB_FILE {
    CC_SFILE *f;
    char name[CCtsp_PROB_FILE_NAME_LEN];
    int id;
    int parent;
    double ub;
    double lb;
    CCbigguy exactlb;
    int nnodes;
    int child0;
    int child1;
    int real;       /* Set to 1 when we know this is a real child */
    int processed;
    int infeasible;
    struct {
        int dat;
        int edge;
        int fulladj;
        int cut;
        int tour;
        int basis;
        int norms;
        int fix;
        int exactdual;
        int history;
    } offsets;
} CCtsp_PROB_FILE;


#ifdef CC_PROTOTYPE_ANSI

CCtsp_PROB_FILE
    *CCtsp_prob_read (char *f, int n),
    *CCtsp_prob_read_name (char *f),
    *CCtsp_prob_write (char *f, int n),
    *CCtsp_prob_write_name (char *fname, char *pname);

int
    CCtsp_prob_file_delete (char *f, int n),
    CCtsp_prob_getname (CCtsp_PROB_FILE *p, char *name),
    CCtsp_prob_getid (CCtsp_PROB_FILE *p, int *id),
    CCtsp_prob_getparent (CCtsp_PROB_FILE *p, int *parent),
    CCtsp_prob_getub (CCtsp_PROB_FILE *p, double *ub),
    CCtsp_prob_getlb (CCtsp_PROB_FILE *p, double *lb),
    CCtsp_prob_getexactlb (CCtsp_PROB_FILE *p, CCbigguy *lb),
    CCtsp_prob_getnnodes (CCtsp_PROB_FILE *p, int *nnodes),
    CCtsp_prob_getchildren (CCtsp_PROB_FILE *p, int *child0, int *child1),
    CCtsp_prob_getreal (CCtsp_PROB_FILE *p, int *real),
    CCtsp_prob_getprocessed (CCtsp_PROB_FILE *p, int *processed),
    CCtsp_prob_getinfeasible (CCtsp_PROB_FILE *p, int *infeasible),
    CCtsp_prob_gettour (CCtsp_PROB_FILE *p, int **tour),
    CCtsp_prob_getedges (CCtsp_PROB_FILE *p, int *nedges, int **elist,
        int **elen),
    CCtsp_prob_getcuts (CCtsp_PROB_FILE *p, CC_SFILE *s, CCtsp_lpcuts *cuts),
    CCtsp_prob_getbasis (CCtsp_PROB_FILE *p, int *ccount, int *rcount,
        int **cstat, int **rstat),
    CCtsp_prob_getnorms (CCtsp_PROB_FILE *p, int *rcount, double **dnorm),
    CCtsp_prob_getfulladj (CCtsp_PROB_FILE *p, int ncount, int *fullcount,
        CCtsp_genadj **adj, CCtsp_genadjobj **adjspace),
    CCtsp_prob_getfixed (CCtsp_PROB_FILE *p, int *ecount, int **elist),
    CCtsp_prob_getexactdual (CCtsp_PROB_FILE *p, int ncount,
        CCtsp_bigdual **d),
    CCtsp_prob_gethistory (CCtsp_PROB_FILE *p, int *depth,
        CCtsp_branchobj **history),
    CCtsp_prob_rclose (CCtsp_PROB_FILE *p),

    CCtsp_prob_putname (CCtsp_PROB_FILE *p, char *name),
    CCtsp_prob_putid (CCtsp_PROB_FILE *p, int id),
    CCtsp_prob_putparent (CCtsp_PROB_FILE *p, int parent),
    CCtsp_prob_putub (CCtsp_PROB_FILE *p, double ub),
    CCtsp_prob_putlb (CCtsp_PROB_FILE *p, double lb),
    CCtsp_prob_putexactlb (CCtsp_PROB_FILE *p, CCbigguy lb),
    CCtsp_prob_putnnodes (CCtsp_PROB_FILE *p, int nnodes),
    CCtsp_prob_putchildren (CCtsp_PROB_FILE *p, int child0, int child1),
    CCtsp_prob_putreal (CCtsp_PROB_FILE *p, int real),
    CCtsp_prob_putprocessed (CCtsp_PROB_FILE *p, int processed),
    CCtsp_prob_putinfeasible (CCtsp_PROB_FILE *p, int infeasible),
    CCtsp_prob_puttour (CCtsp_PROB_FILE *p, int *tour),
    CCtsp_prob_putedges (CCtsp_PROB_FILE *p, int nedges, int *elist, int *elen),
    CCtsp_prob_putcuts (CCtsp_PROB_FILE *p, CC_SFILE *s, CCtsp_lpcuts *cuts),
    CCtsp_prob_putbasis (CCtsp_PROB_FILE *p, int ccount, int rcount, int *cstat,
        int *rstat),
    CCtsp_prob_putnorms (CCtsp_PROB_FILE *p, int rcount, double *dnorm),
    CCtsp_prob_putfulladj (CCtsp_PROB_FILE *p, int ncount, int fullcount,
        CCtsp_genadj *adj),
    CCtsp_prob_putfixed (CCtsp_PROB_FILE *p, int ecount, int *elist),
    CCtsp_prob_putexactdual (CCtsp_PROB_FILE *p, CCtsp_bigdual *d, int ncount),
    CCtsp_prob_puthistory (CCtsp_PROB_FILE *p, int depth,
        CCtsp_branchobj *history),
    CCtsp_prob_wclose (CCtsp_PROB_FILE *p);

#else

CCtsp_PROB_FILE
    *CCtsp_prob_read (),
    *CCtsp_prob_read_name (),
    *CCtsp_prob_write (),
    *CCtsp_prob_write_name ();

int
    CCtsp_prob_file_delete (),
    CCtsp_prob_getname (),
    CCtsp_prob_getid (),
    CCtsp_prob_getparent (),
    CCtsp_prob_getub (),
    CCtsp_prob_getlb (),
    CCtsp_prob_getexactlb (),
    CCtsp_prob_getnnodes (),
    CCtsp_prob_getchildren (),
    CCtsp_prob_getreal (),
    CCtsp_prob_getprocessed (),
    CCtsp_prob_getinfeasible (),
    CCtsp_prob_gettour (),
    CCtsp_prob_getedges (),
    CCtsp_prob_getcuts (),
    CCtsp_prob_getbasis (),
    CCtsp_prob_getnorms (),
    CCtsp_prob_getfulladj (),
    CCtsp_prob_getfixed (),
    CCtsp_prob_getexactdual (),
    CCtsp_prob_gethistory (),
    CCtsp_prob_rclose (),

    CCtsp_prob_putname (),
    CCtsp_prob_putid (),
    CCtsp_prob_putparent (),
    CCtsp_prob_putub (),
    CCtsp_prob_putlb (),
    CCtsp_prob_putexactlb (),
    CCtsp_prob_putnnodes (),
    CCtsp_prob_putchildren (),
    CCtsp_prob_putreal (),
    CCtsp_prob_putprocessed (),
    CCtsp_prob_putinfeasible (),
    CCtsp_prob_puttour (),
    CCtsp_prob_putedges (),
    CCtsp_prob_putcuts (),
    CCtsp_prob_putbasis (),
    CCtsp_prob_putnorms (),
    CCtsp_prob_putfulladj (),
    CCtsp_prob_putfixed (),
    CCtsp_prob_putexactdual (),
    CCtsp_prob_puthistory (),
    CCtsp_prob_wclose ();

#endif



/***************************************************************************/
/*                                                                         */
/*                             qsparse.c                                   */
/*                                                                         */
/***************************************************************************/

typedef struct CCtsp_qsparsegroup {
    CCdheap *add_queue;   /* An empty heap will be maintained */
    CCdheap *sub_queue;   /* An empty heap will be maintained */
    int *count_m1;        /* The array will be maintained at 0 */
    int *count_non0;      /* The array will be maintained at 0 */
    int *count_1;         /* The array will be maintained at 0 */
    int *on_add_queue;    /* The array will be maintained at 0 */
    int *on_sub_queue;    /* The array will be maintained at 0 */
    int *mults;           /* The array will be maintained at 0 */
} CCtsp_qsparsegroup;

#ifdef CC_PROTOTYPE_ANSI

void
    CCtsp_free_qsparsify (CCtsp_qsparsegroup **pqs);
int
    CCtsp_qsparsify (CCtsp_qsparsegroup **pqs, struct CCtsp_lpgraph *g,
            int *pnzlist, int *scount, struct CCtsp_sparser **slist,
            int *savedcount);
#else

void
    CCtsp_free_qsparsify ();
int
    CCtsp_qsparsify ();

#endif

#endif  /* __TSP_H */
