/************************************************************************/
/*                                                                      */
/*             ROUTINE FOR WEIGHTED PERFECT MATCHING PROBLEMS           */
/*                                                                      */
/*  Written by:  A. Rohe                                                */
/*  Date:  November 7, 1995  (rohe)                                     */
/*         November 12, 1995 (rohe)                                     */
/*         February 7, 1996  (rohe - short look at program)             */
/*         July, 1996        (rohe - change from tree to forest)        */
/*         October, 1996     (bico - change to concorde format)         */
/*                                                                      */
/*                                                                      */
/* EXPORTED FUNCTION:                                                   */
/*   int perfect_match (int ncount, CCdatagroup *dat, int ecount,       */
/*          int **elist, int **elen, char *blo_filename,                */
/*          char *mat_filename, int just_fractional, int no_fractional, */
/*          int use_all_trees, int use_tree, int partialprice,          */
/*          double *totalzeit)                                          */
/*     COMPUTES a minumum weight perfect matching.                      */
/*         -ncount is the number of nodes in the graph                  */
/*         -dat gives the data to generate edge lengths (if the         */
/*            matching is over the complete graph), it can be NULL      */
/*         -ecount is the number of edges in the initial edge set       */
/*         -elist is a pointer to an array of edges in end end format,  */
/*            this array will be freed by perfect_match to save on      */
/*            memory                                                    */
/*         -elen is a pointer to an array of edge lengths for the edges */
/*            in elist, it will be freed by the perfect_match           */
/*         -blo_filename is the name of a file (it can be NULL), if it  */
/*            is not NULL then the blossoms and weights will be written */
/*            to it                                                     */
/*         -mat_filename is the name of a file (it can be NULL), if it  */
/*            is not null, then the matching will be writtien to it     */
/*         -just_fractional should be 0 to compute a matching, and 1    */
/*            to only compute a fractional matching                     */
/*         -if no_fractional is nonzero, then a fractional jumpstart    */
/*            will not be used                                          */
/*         -if use_all_trees is 1, then a common delta is               */
/*            computed for all trees in the forest; if it is 2, then    */
/*            a single tree is grown                                    */
/*         -if partialprice is > 0, then the pricing routine will first */
/*            price the partialprice nearest neighbors before moving to */
/*            the complete edge set                                     */
/*         -totalzeit will return the time used by the matching routine */
/*            (excluding the time needed for a final check that the     */
/*            matching is indeed optimal, if this checking is turned    */
/*            on)                                                       */
/*                                                                      */
/*  NOTES:                                                              */
/*                                                                      */
/*    Returns 0 if it worked and 1 otherwise (for example, when one     */
/*    of the mallocs failed). The nodes in the graph should be named    */
/*    0 through #nodes - 1.                                             */
/*                                                                      */
/************************************************************************/
#include "concorde.h"
#include "match.h"
#define NDEBUG   /* remove this to turn assertions on */
#include <assert.h>

#define CARELESS_REPAIRS 
/* #define BALL_DERIGS_REPAIRS */
#define GREEDY_DUAL_CHANGE 
#define SWITCH_LEVEL 32
#define MAX_BAD_PORTION 0.25

#define PRINT_LEVEL 0
#define SHRINKS_SIZE 1000
/* infinity */
#define INTEGER_MIN -999999999
#define INTEGER_MAX  999999999
/* for labels */
#define NIX 0
#define PLUS 1
#define MINUS 2
/* for status */
#define UNMATCHED 0
#define HALVES 1
#define MATCHED 2
/* for x */
#define HALF 2

int FAILED_NODE;

/*
#define OTHEREND(e,n,list)  ((list) + (e)->nod1 + (e)->nod2 - ((n) - (list)))
*/
#define OTHEREND(e,n,list) (((e)->nod1 + (list)) == (n) ?                \
                             (e)->nod2 + (list) : (e)->nod1 + (list))
#define OTHEREND_INT(e,n) ((e)->nod1 + (e)->nod2 - (n))

#define FIND_SURFACE(n) {                                                \
            while((n)->blossom_parent != -1) {                           \
                (n)=G->nodelist+(n)->blossom_parent;                     \
            }                                                            \
        }

#define SHRINK_SORT_CONST 3
#define BADCOUNT_CONST 10000
#define PNODE(n) (G->nodelist + (n))
#define PEDGE(e) (G->edgelist + (e))

#define INODE(n) ((n) - G->nodelist)
#define IEDGE(e) ((e) - G->edgelist)

typedef struct edge {
    int   slack;
    char  mark;  
    char  x; 
    int   ptrs[2];
    int   nod1;
    int   nod2;
    int   orig_nod1;
    int   orig_nod2;
} edge;

typedef struct node {
    int   edg_list;
    int   matched_edge;

    /* These are for the augmenting path tree */
    int   child;
    int   sibling;
    int   parent;
    int   parent_edge;

    /* These are for the blossom_tree */
    int   blossom_next;
    int   blossom_parent;
    int   blossom_root;
    int   blossom_next_edge;
    int   penultimate;

    int   pi;
    int   mark;      /* unused pseudo nodes are linked by mark */
    int   tree_root;

    char  status;
    char  label;
    char  hit;

    int   dummy;    /* just to pad to multiple of 8 bytes */
} node;

typedef struct nodeptr {
    int next;
    int surf;
    int delta;
    int dad;
    int sum;
    int status;
#ifdef GREEDY_DUAL_CHANGE
    char tree_processed;
    int gnext;      /* used to pad to multiple of 8 bytes and in reordering */
#endif
} nodeptr;

typedef struct shrink_ary_T {
    int node_i;
    int node_j;
    int node_k;
    int edge;
    int size;
    int next;
} shrink_ary_T;

typedef struct shrink_T {
    shrink_ary_T *ary;
    int length;
} shrink_T;

typedef struct expand_T {
    int *node;
    int length;
} expand_T;

typedef struct stats {
    int expand_count;
    int shrink_count;
    int dualchange_count;
    int dualzero_count;
} stats;

typedef struct graph {
    edge *edgelist;
    node *nodelist;
    int nnodes;
    int nedges;
    int max_nedges;
    int unused;
    int unmatched;
    nodeptr *roots;
    int unmatched_count;
}graph;

typedef struct srkstuff {
    expand_T expands;
    shrink_T shrinks;
    int shrinks_max;
    int expands_max;
    int shrinks_[SHRINKS_SIZE];
} srkstuff;

typedef struct stack {
    int*             ary;
    int              count;
} stack;

#ifdef  CC_PROTOTYPE_ANSI

static void
    adjust_match (graph *G),
    print_node (graph *G, node *n),
    print_edges (graph *G),
    init_tree (graph *G, node *n),
    clear_tree (graph *G, node *n),
    make_cycle_halves (graph *G, node *node_i, node *node_j, node *node_k,
        edge *e),
    shrink_tree (graph *G, node *newnode),
    label_penultimate (graph *G, node *n, int label),
    fix_matching (graph *G, node *oldnode, node *x),
    fix_tree (graph *G, node *oldnode, node *x, node *y),
    flip_cycle (graph *G, node *node_i),
    augment_path (graph *G, node *node_i, int fractional),
    vereinigung (graph *G, int x, int y),
    set_vereinigung (graph *G, node *n),
    unmatch_edge (graph *G, edge *e),
    dual_match_len (graph *G, int fractional, double *val),
    fix_match (graph *G, int blossom);

static int 
    build_graph (graph *G, int ncount, int ecount, int *elist, int *elen),
    init (graph *G, srkstuff *srk),
    match_main_frac (graph *G, stats *scount, srkstuff *srk),
    match_main (graph *G, stats *scount, srkstuff *srk, int use_all),
    augment_blossom (graph *G, edge *, int fractional, srkstuff *srk),
    lower_edges (graph *G, node *old),
    expand_blossom (graph *G, node *oldnode, stats *scount),
    lift_edges (graph *G, node *newnode),
    add_to_tree (graph *G, edge *e, node *node_i, node *node_j, int fractional),
    checkout_node (graph *G, node *n, int fractional, srkstuff *srk),
    grow_tree_no_shrink (graph *G, node *n, int fractional, srkstuff *srk),
    grow_tree (graph *G, node *n, int fractional, stats *scount, srkstuff *srk,
               int *found_aug),
    apply_dual_change (graph *G, node *n, int delta),
    find_parity_sum (graph *G, int n),
    parity_correction (graph *G, stats *scount),
    find_single_dual_change (graph *G, node *n),
    find_dual_change_forest (graph *G, node *n),
    make_dual_change_forest (graph *G, stats *scount),
    match_main_more_in_forest (graph *G, stats *scount, srkstuff *srk),
    match_main_forest (graph *G, stats *scount, srkstuff *srk),
    match_main_tree (graph *G, stats *scount, srkstuff *srk),
    make_match (graph *G),
    test_matching (graph *G, CCdatagroup *dat, int *elen, int fractional,
                   int *bad),
    price_repair (graph *G, int *finished, CCdatagroup *dat, stats *scount,
       srkstuff *srk, int partialprice),
    pricing (graph *G, CCdatagroup *dat, stats *scount, srkstuff *srk, 
       int *badcount, int **badlist, int **badlen, CCtsp_edgegenerator *eg,
       int usehit),
    bring_to_surface (graph *G, node *p, stats *scount, srkstuff *srk),
    add_repair_edge (graph *G, int n1, int n2, int len, stats *scount,
       srkstuff *srk),
    run_repair (graph *G, int badcount,int* badlist,int* badlen, stats *scount,
       srkstuff *srk),
    add_edges (graph *G, CCdatagroup *dat, int badcount,int* badlist,int* badlen),
  write_match (graph *G, CCdatagroup *dat, int *elen, char* match_file, int *outp),
    write_blossom_tree (graph *G, char* blossom_tree_file);

static node
    *shrink_blossom (graph *G, node *node_i, node *node_j, node *node_k,
        edge *e, stats *scount),
    *common_parent (graph *G, node *node_i, node *node_j, int *size),
    *find_below (graph *G, node *n, int blossom);

#else

static void
    adjust_match (),
    print_node (),
    print_edges (),
    init_tree (),
    clear_tree (),
    make_cycle_halves (),
    shrink_tree (),
    label_penultimate (),
    fix_matching (),
    fix_tree (),
    flip_cycle (),
    augment_path (),
    vereinigung (),
    set_vereinigung (),
    unmatch_edge (),
    dual_match_len (),
    fix_match ();

static int
    build_graph (),
    init (),
    match_main_frac (),
    match_main (),
    augment_blossom (),
    lower_edges (),
    expand_blossom (),
    lift_edges (),
    add_to_tree (),
    checkout_node (),
    grow_tree_no_shrink (),
    grow_tree (),
    apply_dual_change (),
    find_parity_sum (),
    parity_correction (),
    find_single_dual_change (),
    find_dual_change_forest (),
    make_dual_change_forest (),
    make_match (),
    match_main_more_in_forest (),
    match_main_forest (),
    match_main_tree (),
    test_matching (),
    price_repair (),
    pricing (),
    add_repair_edge (),
    bring_to_surface (),
    run_repair (),
    add_edges (),
    write_match (),
    write_blossom_tree ();

static node
    *shrink_blossom (),
    *common_parent (),
    *find_below ();

#endif

#if PRINT_LEVEL
static graph *PG = (graph *) NULL;
#endif

#ifdef CC_PROTOTYPE_ANSI
int perfect_match (int ncount, CCdatagroup *dat, int ecount, int **elist,
                   int **elen, char *blo_filename, char *mat_filename,
                   int just_fractional, int no_fractional,
                   int use_all_trees, int partialprice, double *totalzeit)
#else
int perfect_match (ncount, dat, ecount, elist, elen, blo_filename,
                   mat_filename, just_fractional, no_fractional,
                   use_all_trees, partialprice, totalzeit)
int ncount;
CCdatagroup *dat;
int ecount;
int **elist, **elen;
char *blo_filename, *mat_filename;
int use_all_trees;
int partialprice;
double *totalzeit;
#endif
{
    graph G;
    srkstuff srk;
    stats scount;
    double val, startzeit;
    int finished = 1;
    int bad;
    int sedges = 0;
    double zero_zeit = CCutil_zeit ();

#if PRINT_LEVEL
    PG = &G;
#endif

    int status = 0;

    *totalzeit = 0.0;

    G.edgelist = (edge *) NULL;
    G.nodelist = (node *) NULL;
    G.unused = -1;
    G.unmatched = -1;
    G.roots = (nodeptr *) NULL;

    srk.expands.node = (int *) NULL;
    srk.shrinks.ary = (shrink_ary_T *) NULL;

    if (build_graph (&G, ncount, ecount, *elist, *elen)) {
      //        fprintf (stderr, "build_graph failed\n");
        CC_FREE (*elist, int);
        CC_FREE (*elen, int);
	status = 1;
        goto CLEANUP;
    }
    CC_FREE (*elist, int);
    if (dat) {
        CC_FREE (*elen, int);
    }
    sedges = G.nedges;
  
    do {
      //	printf (" Starting Init...");
	fflush (stdout);
	startzeit = CCutil_zeit ();
	if (init (&G, &srk)) {
	  //            fprintf (stderr, "init failed\n");
	    status = 1;
            goto CLEANUP;
        }
	//	printf (" ... ready in %.2f sec !! \n", CCutil_zeit () - startzeit);
        fflush (stdout);

	if (no_fractional == 0) {
	  //	    printf (" Matching with %i nodes and %i edges ...\n",
	  //                    G.nnodes, G.nedges);
	  //	    fflush (stdout);
	    //	    printf (" Make a fractional Matching...\n");
	    fflush (stdout);
	    startzeit = CCutil_zeit ();
            scount.expand_count = 0;
            scount.shrink_count = 0;
            scount.dualchange_count = 0;
            scount.dualzero_count = 0;
	    if (match_main_frac (&G, &scount, &srk)) {
	      //                fprintf (stderr, "match_main_frac failed\n");
		status = 1;
                goto CLEANUP;
            }
	    //	    printf (" ... ready in %.2f sec !! \n", CCutil_zeit () - startzeit);
	    //            fflush (stdout);
	}

	if (just_fractional == 0) {
	  //	    printf (" Make an integral Matching ...\n");
	  //	    fflush (stdout);
	    startzeit = CCutil_zeit ();
	    if (make_match (&G)) {
	      //                fprintf (stderr, "make_match failed\n");
	      //                fflush (stdout);
            }
	    //	    printf (" ... ready in %.2f sec !! \n", CCutil_zeit () - startzeit);
	    //            fflush (stdout);

	    //	    printf (" Starting Integral Matching-Code...\n");
	    //	    fflush (stdout);
	    startzeit = CCutil_zeit ();
            scount.expand_count = 0;
            scount.shrink_count = 0;
            scount.dualchange_count = 0;
            scount.dualzero_count = 0;
	    if (match_main (&G, &scount, &srk, use_all_trees)) {
	      //                fprintf (stderr, "match_main failed\n");
	      status = 1;
	      goto CLEANUP;
            }
	    //	    printf (" ... ready in %.2f sec !! \n", CCutil_zeit () - startzeit);
	    //            fflush (stdout);
            dual_match_len (&G, 0, &val);
	    //            printf ("     Dual Matching Length: %.1f\n", val);
	    //            fflush (stdout);
	    if (dat) {
	      //		printf ("Start Price-Repair Phase ...\n");
	      //		fflush (stdout);
		startzeit = CCutil_zeit ();
                if (price_repair (&G, &finished, dat, &scount, &srk,
                                  partialprice)) {
		  //                    fprintf (stderr, "pricing failed\n");
                    return 1;
                }
                if (finished && partialprice > 0) {
		  //                    printf ("Nearest %d are correct, now try complete graph\n",
		  //                             partialprice);
		  //                    fflush (stdout);
                    if (price_repair (&G, &finished, dat, &scount, &srk, 0)) {
		      //                        fprintf (stderr, "pricing failed\n");
                        return 1;
                    }
                }
		//		printf (" ... ready in %.2f sec !! \n", CCutil_zeit () - startzeit);
		//                fflush (stdout);
	    }
            CC_IFFREE (G.roots, nodeptr);
	}
	if (blo_filename != (char *) NULL) {
	    if (write_blossom_tree (&G, blo_filename)) {
	      //                fprintf (stderr, "write_blossom_tree failed\n");
		status = 1;
                goto CLEANUP;
            }
	}
        CC_IFFREE (srk.expands.node, int);
        CC_IFFREE (srk.shrinks.ary, shrink_ary_T); 
    } while (!finished);

    //    printf (" Adjust found Matching...\n");
    //    fflush (stdout);
    startzeit = CCutil_zeit ();
    adjust_match (&G);
    //    printf (" ... ready in %.2f sec !! \n", CCutil_zeit () - startzeit);
    //    fflush (stdout);

    *totalzeit = CCutil_zeit () - zero_zeit;
    //    printf ("Matching Time: %.2f Seconds\n", *totalzeit);
    //    fflush (stdout);

    if (dat) {
      //        printf ("Testing the solution...\n");
      //        fflush (stdout);
        startzeit = CCutil_zeit ();
        if (test_matching (&G, dat, *elen, just_fractional, &bad)) {
	  //            fprintf (stderr, "test matching failed\n");
	  status = 1;
	  goto CLEANUP;
        }
        if (bad) {
	  //            printf ("ERROR: A problem was detected in the matching\n");
	  status = 1;
	  goto CLEANUP;
        }
	//        printf ("Testing Time: %.2f sec\n", CCutil_zeit () - startzeit);
	//        fflush (stdout);
    }

    //    printf ("ZZ Edges:  %d (starting)   %d (total)\n", sedges, G.nedges);

    if (mat_filename !=  (char *) NULL) {
      *elist = (int*)malloc((3*ncount+1)*sizeof(int));// over allocated
      if (write_match (&G, dat, *elen, mat_filename,*elist)) {
	status = 1;
	//            fprintf (stderr, "write_match failed\n");
	goto CLEANUP;
      }
    }

CLEANUP:

    CC_IFFREE (G.nodelist, node);
    CC_IFFREE (G.edgelist, edge);
    CC_IFFREE (G.roots, nodeptr);
    CC_IFFREE (srk.expands.node, int);
    CC_IFFREE (srk.shrinks.ary, shrink_ary_T); 
    if (!dat) {
       CC_FREE (*elen, int);
    }

    return status;
}

#ifdef CC_PROTOTYPE_ANSI
static void print_node (graph *G, node *n)
#else
static void print_node (G, n)
graph *G;
node *n;
#endif
{
    edge *e;
    int ei;
    int c;
    node *nodelist = G->nodelist;
    edge *edgelist = G->edgelist;

    printf ("Node %d, Pi %d", (int) INODE(n), n->pi);
    if (n->label == PLUS) printf (" label +");
    if (n->label == MINUS) printf (" label -");
    if (n->label == NIX) printf (" label 0");
    if (n->status == MATCHED)
	printf (" MATCHED (%d,%d)\n",
            edgelist[n->matched_edge].nod1,
            edgelist[n->matched_edge].nod2);
    if (n->status == UNMATCHED) printf (" UNMATCHED\n");
    if (n->status == HALVES)
	printf (" HALVES (%i,%i)\n",
            edgelist[n->matched_edge].nod1, edgelist[n->matched_edge].nod2);
    fflush (stdout);
    if (n->label != NIX) {
	printf ("TreeRoot %d ", n->tree_root);
	if (n->parent)
	    printf ("TreeParent = %d ", n->parent);
	printf ("Children: ");
	for (c = n->child; c != -1; c = nodelist[c].sibling)
	    printf ("%d ", c);
	printf ("\n");
    }
    if (n->blossom_parent != -1) {
	printf ("BlossomNode %i, Parent %i, Next %i\n", (int) INODE(n),
            n->blossom_parent, n->blossom_next);
    }
    if (n->blossom_root != -1) {
	printf ("BlossomParent %i, Root %i\n", (int) INODE(n), n->blossom_root);
    }
    for (ei = n->edg_list; ei != -1; ei = e->ptrs[ei % 2]) {
        e = PEDGE(ei/2);
	printf ("| Edge (%i,%i)", e->nod1, e->nod2);
	printf ("| %4i is ", e->nod1);
	if (nodelist[e->nod1].label == PLUS) printf ("+");
	if (nodelist[e->nod1].label == MINUS) printf ("-");
	if (nodelist[e->nod1].label == NIX) printf ("0");
	printf ("| %4i is ", e->nod2);
	if (nodelist[e->nod2].label == PLUS) printf ("+");
	if (nodelist[e->nod2].label == MINUS) printf ("-");
	if (nodelist[e->nod2].label == NIX) printf ("0");
	printf ("| edg Slack %d, x=%d\n", e->slack, (int) e->x);
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void print_edges (graph *G)
#else
static void print_edges (G)
graph *G;
#endif
{
    int i;

    printf (" %i nodes, %i edges\n", G->nnodes, G->nedges);
    for (i = 0; i <= 3 * G->nnodes / 2 && i >= 0; i++) {
	if (G->nodelist[i].edg_list != -1)
	    print_node (G, PNODE(i));
    }
}

#ifdef CC_PROTOTYPE_ANSI
static int init (graph *G, srkstuff *srk)
#else
static int init (G, srk)
graph *G;
srkstuff *srk;
#endif
{
    int i, count;
    node *n;
    edge *e;
    int ei;
    int delta;
    node *nodelist = G->nodelist;
    int   ncount = G->nnodes;
    int   ecount = G->nedges;

    /* set all the pi s */
    for (i = 0; i < ncount; i++)
	nodelist[i].pi = INTEGER_MAX;
    for (i = ncount; i <= 3 * ncount / 2; i++)
	nodelist[i].pi = 0;

    for (i = 0, e = G->edgelist; i < ecount; i++, e++) {
	if (nodelist[e->nod1].pi > e->slack) {
	    nodelist[e->nod1].pi = e->slack;
	}
	if (nodelist[e->nod2].pi > e->slack) {
	    nodelist[e->nod2].pi = e->slack;
	}
    }

    for (i = 0; i < ncount; i++)
	nodelist[i].pi /= 2;

    /* calculate the slacks with the pi's and set rest to zero/nothing */

    for (i = 0, e = G->edgelist; i < ecount; i++, e++) {
	e->slack = e->slack - nodelist[e->nod1].pi - nodelist[e->nod2].pi;
	e->x = 0;
    }

    for (i = 0, n = nodelist; i <= 3 * ncount / 2; i++, n++) {
	n->child = -1;
	n->sibling = -1;
	n->parent = -1;
	n->label = NIX;
	n->parent_edge = -1;
	n->matched_edge = -1;
	n->status = UNMATCHED;
	n->blossom_root = -1;
	n->blossom_next = -1;
	n->blossom_next_edge = -1;
	n->blossom_parent = -1;
	n->tree_root = -1;
        n->hit = 0;
    }
#if 0
    /* Take all 0-slack edges directly, old version */
    count = 0;
    for (i = 0, e = G->edgelist; i < ecount; i++, e++) {
	if (e->slack == 0) {
	    if ((nodelist[e->nod1].status == UNMATCHED) &&
                (nodelist[e->nod2].status == UNMATCHED)) {
		e->x = 1;
		nodelist[e->nod1].matched_edge = i;
		nodelist[e->nod2].matched_edge = i;
		nodelist[e->nod1].status = MATCHED;
		nodelist[e->nod2].status = MATCHED;
		count += 2;
	    }
	}
    }
#else
    /* Take all 0-slack edges directly & make better pi, new version */
    count = 0;
    for (i = 0, n = nodelist; i < ncount; i++, n++) {
	delta = INTEGER_MAX;
	if (n->status == UNMATCHED) {
            for (ei = n->edg_list; ei != -1; ei = e->ptrs[ei % 2]) {
                e = PEDGE(ei/2); 
		if (e->slack <= delta) {
		    if (e->slack == 0) {
			if ((nodelist[e->nod1].status == UNMATCHED) && 
                            (nodelist[e->nod2].status == UNMATCHED)) {
			    e->x = 1;
			    nodelist[e->nod1].matched_edge = IEDGE(e);
			    nodelist[e->nod2].matched_edge = IEDGE(e);
			    nodelist[e->nod1].status = MATCHED;
			    nodelist[e->nod2].status = MATCHED;
			    count += 2;
			}
		    }
		    delta = e->slack;
		}
	    }
	    if (delta != 0) {
		n->pi += delta;
                for (ei = n->edg_list; ei != -1; ei = e->ptrs[ei % 2]) {
                    e = PEDGE(ei/2);
                    e->slack -= delta;
		}
	    }
	}
    }
#endif
    //    printf (" %i nodes ", count); fflush (stdout);

    G->unmatched_count = ncount - count;

    srk->shrinks_max = ncount / 10 + 10;  /* was just ncount */
    srk->shrinks.ary = CC_SAFE_MALLOC (srk->shrinks_max, shrink_ary_T);
    srk->expands_max = ncount / 10 + 10;
    srk->expands.node = CC_SAFE_MALLOC (srk->expands_max, int);

    if (!srk->shrinks.ary || !srk->expands.node) {
        fprintf (stderr, "out of memory in init\n");
        CC_IFFREE (srk->shrinks.ary, shrink_ary_T);
        CC_IFFREE (srk->expands.node, int);
        return 1;
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static void init_tree (graph *G, node *n)
#else
static void init_tree (G, n)
graph *G;
node *n;
#endif
{
#if PRINT_LEVEL
    printf ("  init_tree %i\n", (int) (n - PG->nodelist)); fflush (stdout);
#endif
    n->child = -1;
    n->sibling = -1;
    n->parent = -1;
    n->parent_edge = -1;
    n->label = PLUS;
}

#ifdef CC_PROTOTYPE_ANSI
static void clear_tree (graph *G, node *n)
#else
static void clear_tree (G, n)
graph *G;
node *n;
#endif
{
    node *c = n;
    node *stop = G->nodelist -1;

    while (1) {
	c->mark = 0;
	c->label = NIX;
	c->tree_root = -1;	/* ??? */

	/* go to next c */
	if (c->child!=-1) {
	    c=PNODE(c->child);
	}
	else {
	    while (PNODE(c->sibling)==stop) {
		if (c==n) return ; /* this if is for an n without childs */
		c=PNODE(c->parent);
		if (c==n) return ;
	    }
	    c=PNODE(c->sibling);
	}
    }
}

/* make_cycle_halves - edge from i to j, k is the "root" */
#ifdef CC_PROTOTYPE_ANSI
static void make_cycle_halves (graph *G, node *node_i, node *node_j,
                               node *node_k, edge *e)
#else
static void make_cycle_halves (G, node_i, node_j, node_k, e)
graph *G;
node *node_i, *node_j, *node_k;
edge *e;
#endif
{
    edge *edgelist = G->edgelist;
    node *parent;

#if PRINT_LEVEL
    printf ("    Make cycle halves: root %i ends %i and %i:",
	  (int) (node_k - PG->nodelist), (int) (node_i - PG->nodelist),
          (int) (node_j - PG->nodelist));
    fflush (stdout);
#endif

    /* set matched_edge for node_j */
    node_j->status = HALVES;
    node_j->matched_edge = e - edgelist;
    e->x = HALF;

    /* path from i to k : matched_edges are the parent_edges */
    for (; node_i != node_k; node_i = PNODE(node_i->parent)) {
        edgelist[node_i->parent_edge].x = HALF;
	node_i->matched_edge = node_i->parent_edge;
	node_i->status = HALVES;
    }

    /* path from j to k : matched_edges are the "child_edges" */
    for (; node_j != node_k; node_j = parent) {
        parent = PNODE(node_j->parent);
	edgelist[node_j->parent_edge].x = HALF;
	parent->matched_edge = node_j->parent_edge;
	parent->status = HALVES;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static int lift_edges (graph *G, node *newnode)
#else
static int lift_edges (G, newnode)
graph *G;
node *newnode;
#endif
{
    node *n, *node_k;
    node *nodelist = G->nodelist;
    int nn = INODE(newnode);
    edge *e;
    int ei, einext;

#if PRINT_LEVEL
    printf ("Lift edges %i\n", nn); fflush (stdout);
#endif

    n = node_k = PNODE(newnode->blossom_root);
    do {
        ei = n->edg_list;
        n->edg_list = -1;
        for (; ei != -1; ei = einext) {
            e = PEDGE(ei/2);
            einext = e->ptrs[ei % 2];
	    if ((nodelist[e->nod1].blossom_parent == nn) &&
                (nodelist[e->nod2].blossom_parent == nn)) {
                e->ptrs[ei % 2] = n->edg_list;
                n->edg_list = ei;
            } else {
		if (e->nod1 == INODE(n)) {    /* nod1 is in new blossom */
		    e->nod1 = nn;
		} else {                      /* nod2 is in new blossom */
		    e->nod2 = nn;
                }
                e->ptrs[ei % 2] = newnode->edg_list;
                newnode->edg_list = ei;
	    } 
	}
	n = PNODE(n->blossom_next);
    } while (n != node_k);
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static void shrink_tree (graph *G, node *newnode)
#else
static void shrink_tree (G, newnode)
graph *G;
node *newnode;
#endif
{
    node *n, *node_k, *cnode;
    int c, csibling, p;

#if PRINT_LEVEL
    printf ("   Shrink-Tree %i\n", (int) (newnode - PG->nodelist));
    fflush (stdout);
#endif

    n = node_k = PNODE(newnode->blossom_root);
    do {
	for (c = n->child; c != -1; c = csibling) {
            cnode = PNODE(c);
	    csibling = cnode->sibling;
	    if (cnode->blossom_parent != INODE(newnode)) {
		cnode->parent = INODE(newnode);
		cnode->sibling = newnode->child;
		newnode->child = c;
	    }
	}
	n = PNODE(n->blossom_next);
    } while (n != node_k);

    /* set other items for newnode */
    p = node_k->parent;

    newnode->sibling = -1;    /* Plus node, has no siblings */
    newnode->parent = p;
    newnode->parent_edge = node_k->parent_edge;
    newnode->matched_edge = node_k->matched_edge;
    newnode->label = PLUS;

    if (p != -1)		/* _p has just one child, so this is ok */
	G->nodelist[p].child = INODE(newnode);
}

/* shrink blossom - edge from i to j, k is the "root" */

#ifdef CC_PROTOTYPE_ANSI
static node *shrink_blossom (graph *G, node *node_i, node *node_j,
                             node *node_k, edge *e, stats *scount)
#else
static node *shrink_blossom (G, node_i, node_j, node_k, e, scount)
graph *G;
node *node_i, *node_j, *node_k;
edge *e;
stats *scount;
#endif
{
    node *newnode;
    node *parent;

#if PRINT_LEVEL
    printf ("    Shrink blossom: root %i ends %i and %i:\n",
       (int) (node_k - PG->nodelist), (int) (node_i - PG->nodelist),
       (int) (node_j - PG->nodelist));
    fflush (stdout);
#endif

    scount->shrink_count++;

    newnode = PNODE(G->unused);
    G->unused = newnode->mark;
    newnode->mark = 0;
    newnode->edg_list = -1;

    if (node_k->status == UNMATCHED) {
        G->roots[node_k->tree_root].surf = INODE(newnode);
    }

    /* set blossom_next,next_edge,parent for node_j */
    /* blossom_root has to stay the same */

    node_j->blossom_next = INODE(node_i);
    node_j->blossom_next_edge = IEDGE(e);
    node_j->blossom_parent = INODE(newnode);

    /* path from i to k : blossom_next_edges are the parent_edges */

    for (; node_i != node_k; node_i = PNODE(node_i->parent)) {
	node_i->blossom_next_edge = node_i->parent_edge;
	node_i->blossom_next = node_i->parent;
	node_i->blossom_parent = INODE(newnode);
    }

    /* path from j to k : blossom_next_edges are the "child_edges" */

    for (; node_j != node_k; node_j = parent) {
        parent = PNODE(node_j->parent);
	parent->blossom_next_edge = node_j->parent_edge;
	parent->blossom_next = INODE(node_j);
	parent->blossom_parent = INODE(newnode);
    }

    newnode->blossom_root = INODE(node_k);
    newnode->blossom_next = -1;
    newnode->blossom_next_edge = -1;
    newnode->blossom_parent = -1;

    newnode->mark = 0;
    newnode->pi = 0;
    newnode->status = node_k->status;
    newnode->tree_root = node_k->tree_root;

    shrink_tree (G, newnode);
    if (lift_edges (G, newnode)) {   
        fprintf (stderr, "lift_edges failed\n");
        return (node *) NULL;
    } 

    return newnode;
}

#ifdef CC_PROTOTYPE_ANSI
static void label_penultimate (graph *G, node *n, int label)
#else
static void label_penultimate (G, n, label)
graph *G;
node *n;
int label;
#endif
{
    /* all the leafs of the blossom_tree under n get the penultimate label */
    node *n2;

    if (n->blossom_root == -1) {
	n->penultimate = label;
	return;
    }

    n2 = n;
    while (1) {
	if (n2->blossom_root != -1) { 
	    n2 = PNODE(n2->blossom_root);
	} else {
	    n2->penultimate = label;
	    while (n2->blossom_next == 
                   PNODE(n2->blossom_parent)->blossom_root) {
		n2 = PNODE(n2->blossom_parent);
		if (n2 == n) return;
	    }
	    n2 = PNODE(n2->blossom_next);
	}
    }
}

#ifdef CC_PROTOTYPE_ANSI
static int lower_edges (graph *G, node *old)
#else
static int lower_edges (G, old)
graph *G;
node *old;
#endif
{
    edge *e;
    int ei, einext;
    node *x;

#if PRINT_LEVEL
    printf ("Lower edges %i !\n", (int) (old - PG->nodelist));
    fflush (stdout);
#endif

    for (ei = old->edg_list; ei != -1; ei = einext) {
        e = PEDGE(ei/2);
        einext = e->ptrs[ei % 2];
	if (e->nod1 == INODE(old)) {
	    x = PNODE(e->orig_nod1);
	    e->nod1 = x->penultimate;
	} else {
	    x = PNODE(e->orig_nod2);
	    e->nod2 = x->penultimate;
	}
        e->ptrs[ei % 2] = PNODE(x->penultimate)->edg_list;
        PNODE(x->penultimate)->edg_list = ei;
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static void fix_matching (graph *G, node *oldnode, node *x)
#else
static void fix_matching (G, oldnode, x)
graph *G;
node *oldnode, *x;
#endif
{
    node *n, *memo;
    node *nodelist = G->nodelist;
    edge *e;

#if PRINT_LEVEL
    printf ("    Fix Matching %i; x = %i\n",
                (int) (oldnode - PG->nodelist), (int) (x - PG->nodelist));
    fflush (stdout);
#endif

    if (x->blossom_next_edge == x->matched_edge) {
        n = x;
        memo = PNODE(oldnode->blossom_root);
    } else {
        n = PNODE(oldnode->blossom_root);
        memo = x;
    }

    for (; n != memo; n = PNODE(n->blossom_next)) {
        e = PEDGE(n->blossom_next_edge);
        e->x = 1 - e->x;
        if (e->x == 1) {
            nodelist[e->nod1].status = MATCHED;
	    nodelist[e->nod2].status = MATCHED;
	    nodelist[e->nod1].matched_edge = IEDGE(e);
	    nodelist[e->nod2].matched_edge = IEDGE(e);
        }
    }

    oldnode->blossom_root = INODE(x);
    x->matched_edge = oldnode->matched_edge;
    x->status = MATCHED;
}

#ifdef CC_PROTOTYPE_ANSI
static void fix_tree (graph *G, node *oldnode, node *x, node *y)
#else
static void fix_tree (G, oldnode, x, y)
graph *G;
node *oldnode, *x, *y;
#endif
{
    node *p, *n, *cnode;
    int c, label_help;

    p = PNODE(oldnode->parent);

#if PRINT_LEVEL
    printf ("    Fix Tree %i; x = %i; y = %i\n",
        (int) (oldnode - PG->nodelist), (int) (x - PG->nodelist),
        (int) (y - PG->nodelist));
    fflush (stdout);
#endif

    /* Restore child-sibling list for p */

    if (p->child == INODE(oldnode)) {
	y->sibling = oldnode->sibling;
	p->child = INODE(y);
    } else {
	for (c = p->child; c != -1; c = cnode->sibling) {
            cnode = PNODE(c);
	    if (cnode->sibling == INODE(oldnode)) {
		cnode->sibling = INODE(y);
		y->sibling = oldnode->sibling;
		break;
	    }
	}
        assert (c != -1);
    }

    y->parent = INODE(p);
    y->parent_edge = oldnode->parent_edge;
    G->nodelist[oldnode->child].parent = INODE(x);
    x->child = oldnode->child;

    label_help = MINUS;
    if (y->blossom_next_edge == y->matched_edge) {
        /* From y to x */
	for (n = y; n != x; n = PNODE(n->blossom_next)) {
	    n->child = n->blossom_next;
	    G->nodelist[n->blossom_next].parent = INODE(n);
	    G->nodelist[n->blossom_next].parent_edge = n->blossom_next_edge;
	    n->label = label_help;
	    if (label_help == MINUS) {
		label_help = PLUS;
	    } else {
		label_help = MINUS;
	    }
	}
	x->label = MINUS;	/* This is not set in for-loop */
    } else {
	for (n = x; n != y; n = PNODE(n->blossom_next)) {
            /* From x to y */
	    n->parent = n->blossom_next;
	    n->parent_edge = n->blossom_next_edge;
	    G->nodelist[n->blossom_next].child = INODE(n);
	    n->label = label_help;
	    if (label_help == MINUS) {
		label_help = PLUS;
	    } else {
		label_help = MINUS;
	    }
	}
	y->label = MINUS;	/* This is not set in for-loop */
    }
}

#ifdef CC_PROTOTYPE_ANSI
static int expand_blossom (graph *G, node *oldnode, stats *scount)
#else
static int expand_blossom (G, oldnode, scount)
graph *G;
node *oldnode;
stats *scount;
#endif
{
    node *memo, *x, *y, *n;
    int child, parent;

    scount->expand_count++;

#if PRINT_LEVEL
    printf ("    Expand blossom %i \n", (int) (oldnode - PG->nodelist));
    fflush (stdout);
#endif

    child = oldnode->child;
    parent = oldnode->parent;

    n = memo = PNODE(oldnode->blossom_root);
    do {
	label_penultimate (G, n, INODE(n));
	n = PNODE(n->blossom_next);
    } while (n != memo);

    if (G->edgelist[oldnode->matched_edge].nod1 == INODE(oldnode))
	x = PNODE(G->edgelist[oldnode->matched_edge].orig_nod1);
    else
	x = PNODE(G->edgelist[oldnode->matched_edge].orig_nod2);

    if (G->edgelist[oldnode->parent_edge].nod1 == INODE(oldnode))
	y = PNODE(G->edgelist[oldnode->parent_edge].orig_nod1);
    else
	y = PNODE(G->edgelist[oldnode->parent_edge].orig_nod2);

    if (lower_edges (G, oldnode)) {
        fprintf (stderr, "lower_edges failed\n");
        return 1;
    }
    fix_matching (G, oldnode, PNODE(x->penultimate));

    n = memo;
    do {
	/* Clear tree structure of nodes in oldnodes blossom */
	n->blossom_parent = -1;
	n->child = -1;
	n->parent = -1;
	n->sibling = -1;
	n->parent_edge = -1;
	n->label = NIX;

	n = PNODE(n->blossom_next);
        n->hit = n->hit | oldnode->hit;
    } while (n != memo);

    fix_tree (G, oldnode, PNODE(x->penultimate), PNODE(y->penultimate));

    /* update tree roots */

    for (child = G->nodelist[child].parent; child != parent;
                                            child = G->nodelist[child].parent) {
	G->nodelist[child].tree_root = G->nodelist[parent].tree_root;
    }

    /* clear oldnode */

    oldnode->edg_list = -1;
    oldnode->pi = 0;
    oldnode->status = UNMATCHED;
    oldnode->matched_edge = -1;
    oldnode->child = -1;
    oldnode->sibling = -1;
    oldnode->parent = -1;
    oldnode->parent_edge = -1;
    oldnode->label = NIX;
    oldnode->blossom_root = -1;
    oldnode->blossom_next = -1;
    oldnode->blossom_next_edge = -1;
    oldnode->blossom_parent = -1;
    oldnode->penultimate = -1;
    oldnode->tree_root = -1;
    oldnode->hit = 0;

    /* put oldnode on unused list */

    oldnode->mark = G->unused;
    G->unused = oldnode - G->nodelist;

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static node *common_parent (graph *G, node *p, node *q, int *size)
#else
static node *common_parent (G, p, q, size)
graph *G;
node *p, *q;
int *size;
#endif
{
    int count;
    node *n;
    node *stop = G->nodelist - 1;

#if PRINT_LEVEL
    printf ("     Common-parent from %i and %i is ",
          (int) (p - PG->nodelist), (int) (q - PG->nodelist));
    fflush (stdout);
#endif

    for (count = 0, n = p; n != stop; n = PNODE(n->parent)) {
	count++;
	n->mark = count;
    }

    for (count = 0; q != stop; q = PNODE(q->parent)) {
	if (q->mark) {
            *size = (count + q->mark);
	    for (n = p; n != stop; n = PNODE(n->parent)) 
		n->mark = 0;
	    return q;
	}
	count++;
    }
    for (n = p; n != stop; n = PNODE(n->parent))
	n->mark = 0;		

    *size = 0;
    return (node *) NULL;
}

#ifdef CC_PROTOTYPE_ANSI
static void flip_cycle (graph *G, node *node_i)
#else
static void flip_cycle (G, node_i)
graph *G;
node *node_i;
#endif
{
    int count = 0, ok = 1;
    node *node_j, *node_k;
    edge *e, *memo;

#if PRINT_LEVEL
    printf ("     Flip cycle with root %i: ", (int) (node_i - PG->nodelist));
    fflush (stdout);
#endif

    /* init start (node_j, node_k, e) */

    e = PEDGE(node_i->matched_edge);
    node_j = node_i;
    node_k = OTHEREND (e, node_i, G->nodelist);

    while (ok) {
	/* test if last edge */
	if (node_k == node_i)
	    ok = 0;

	e->x = (count % 2);
	memo = PEDGE(node_k->matched_edge);

	if (count % 2) {
	    node_j->matched_edge = node_k->matched_edge = IEDGE(e);
	    node_j->status = MATCHED;
	    node_k->status = MATCHED;
	}

	e = memo;
	node_j = node_k;
        node_k = OTHEREND (e, node_j, G->nodelist);
	count++;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void augment_path (graph *G, node *n, int fractional)
#else
static void augment_path (G, n, fractional)
graph *G;
node *n;
int fractional;
#endif
{
    edge *edgelist = G->edgelist;
    node *nodelist = G->nodelist;

#if PRINT_LEVEL
    printf ("      Augment path %i", (int) (n - PG->nodelist));
    fflush (stdout);
#endif

    if (n->parent != -1) {
	for (; n->parent_edge != -1; n = PNODE(n->parent)) {
	    edgelist[n->parent_edge].x = 1 - edgelist[n->parent_edge].x;
	    if (edgelist[n->parent_edge].x == 1) {
		nodelist[edgelist[n->parent_edge].nod1].matched_edge =
                             n->parent_edge;
		nodelist[edgelist[n->parent_edge].nod2].matched_edge =
                             n->parent_edge;
	    }
	}
    }
    n->status = MATCHED;  /* This will be corrected in HALVES case */
    if (!fractional) 
        G->roots[n->tree_root].status = MATCHED;
    clear_tree (G, n);   /* n is the root */
}

#ifdef CC_PROTOTYPE_ANSI
static int augment_blossom (graph *G, edge *e, int fractional, srkstuff *srk)
#else
static int augment_blossom (G, e, fractional, srk)
graph *G;
edge *e;
int fractional;
srkstuff *srk;
#endif
{
    node *node_i = PNODE(e->nod1);
    node *node_j = PNODE(e->nod2);
    node *node_k;
    int size;
    shrink_ary_T *ary = srk->shrinks.ary;

#if PRINT_LEVEL
    printf ("    Augment blossom with ends %i & %i \n", e->nod1, e->nod2);
    fflush (stdout);
#endif

    node_k = common_parent (G, node_i, node_j, &size);
    if (node_k == (node *) NULL) {    /* more then one tree */
	e->x = 1;
	node_i->matched_edge = e -G->edgelist;
	node_j->matched_edge = e -G->edgelist;
	G->unmatched_count -= 2;
	augment_path (G, node_i, fractional);
	augment_path (G, node_j, fractional);
	return 1;
    } else {
	if (fractional) {
	    make_cycle_halves (G, node_i, node_j, node_k, e);
	    augment_path (G, node_k, fractional);
            node_k->status = HALVES;
	    G->unmatched_count--;
	    return 1;
	} else {
	    if (srk->shrinks.length < srk->shrinks_max) {
		ary[srk->shrinks.length].node_i = node_i - G->nodelist;
		ary[srk->shrinks.length].node_j = node_j - G->nodelist;
		ary[srk->shrinks.length].node_k = node_k - G->nodelist;
		ary[srk->shrinks.length].edge = e - G->edgelist;
		ary[srk->shrinks.length].size = size;
		srk->shrinks.length++;
                if (srk->shrinks.length == srk->shrinks_max) {
		    printf ("   WARNING: shrinks.length==shrinks_max=%i\n",
                               srk->shrinks_max);
		    fflush (stdout);
                }
	    }
            return 0;
	}
    }
}

#ifdef CC_PROTOTYPE_ANSI
static int add_to_tree (graph *G, edge *e, node *node_i, node *node_j,
                        int fractional)
#else
static int add_to_tree (G, e, node_i, node_j, fractional)
graph *G;
edge *e;
node *node_i, *node_j;
int fractional;
#endif
{
    node *node_k;
    edge *f;

#if PRINT_LEVEL
    printf ("    Add (%i,%i)=(%i,%i) to tree \n", e->nod1,
       e->nod2, (int) (node_i - PG->nodelist), (int) (node_j - PG->nodelist));
    fflush (stdout);
#endif

    if (node_j->status == UNMATCHED) {
	e->x = 1;
	node_j->status = MATCHED;
	node_i->matched_edge = e - G->edgelist;
	node_j->matched_edge = e - G->edgelist;
	G->unmatched_count -= 2;
        if (!fractional) 
            G->roots[node_j->tree_root].status = MATCHED;
	augment_path (G, node_i, fractional);
	return 1;
    } else if (node_j->status == HALVES) {
	flip_cycle (G, node_j);
	e->x = 1;
	node_i->status = MATCHED;
	node_j->status = MATCHED;
	node_i->matched_edge = e - G->edgelist;
	node_j->matched_edge = e - G->edgelist;
	augment_path (G, node_i, fractional);
	G->unmatched_count--;
	return 1;
    } else {
	/* set node_j in tree */
	node_j->sibling = node_i->child;
	node_j->parent = INODE(node_i);
	node_j->tree_root = node_i->tree_root;
	node_j->parent_edge = IEDGE(e);
	node_j->label = MINUS;

	/* set child for node_i */
	node_i->child = INODE(node_j);

	/* set child for node_j */
	f = PEDGE(node_j->matched_edge);
        node_k = OTHEREND (f, node_j, G->nodelist);
	node_j->child = INODE(node_k);

	/* set node_k in tree */
	node_k->child = -1;
	node_k->sibling = -1;
	node_k->parent = INODE(node_j);
	node_k->parent_edge = IEDGE(f);
	node_k->label = PLUS;
	node_k->tree_root = node_j->tree_root;

	return 0;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static int checkout_node (graph *G, node *n, int fractional, srkstuff *srk)
#else
static int checkout_node (G, n, fractional, srk)
graph *G;
node *n;
int fractional;
srkstuff *srk;
#endif
{
    node *m;
    int augmented;
    edge *e;
    int ei;

#if PRINT_LEVEL
    printf ("   Checkout node %i ...\n", (int) (n - PG->nodelist));
    fflush (stdout);
#endif
 
    for (ei = n->edg_list; ei != -1; ei = e->ptrs[ei % 2]) {
        e = PEDGE(ei/2);
        if (e->slack == 0) {
            m = OTHEREND (e, n, G->nodelist);
	    if (m->label == PLUS) {
		return augment_blossom (G, e, fractional, srk);
	    }
	    if (m->label == NIX) {
		if ((augmented = add_to_tree (G, e, n, m, fractional)) != 0) {
		    return augmented;
		}
            }
	}
    }

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int grow_tree_no_shrink (graph *G, node *n, int fractional,
           srkstuff *srk)
#else
static int grow_tree_no_shrink (G, n, fractional, srk)
graph *G;
node *n;
int fractional;
srkstuff *srk;
#endif
{
    int augmented;
    expand_T *expands = &(srk->expands);
    int expands_max = srk->expands_max;
    node *c=n;
    node *stop = G->nodelist - 1;

#if PRINT_LEVEL
    printf ("   growtree no shrink %i\n", (int) (c - PG->nodelist));
    fflush (stdout);
#endif

    while (1) {
	if (c->label == PLUS) {
	    if ((augmented = checkout_node (G, c, fractional, srk)) > 0) {
		return augmented;
	    }
	} else {			/* MINUS node */
	    if (c->blossom_root != -1 && c->pi == 0) {
		if (expands->length < expands_max) {
		    expands->node[expands->length] = c - G->nodelist;
		    expands->length++;
		    if (expands->length == expands_max) {
			printf ("   WARNING: expands = expands_max = %i\n",
				expands_max);
			fflush (stdout);
		    }
		}
	    }
	}
	/* go to next c */
	if (c->child!=-1) {
	    c=PNODE(c->child);
	} else {
	    while (PNODE(c->sibling) == stop) {
		if (c == n) return 0; /* this if is for childless n */
		c = PNODE(c->parent);
		if (c == n) return 0;
	    }
	    c = PNODE(c->sibling);
	}
    }
}

#ifdef CC_PROTOTYPE_ANSI
static int grow_tree (graph *G, node *n, int fractional, stats *scount,
                      srkstuff *srk, int *found_aug)
#else
static int grow_tree (G, n, fractional, scount, srk, found_aug)
graph *G;
node *n;
int fractional;
stats *scount;
srkstuff *srk;
int *found_aug;
#endif
{
    int i, size;
    node *node_i, *node_j, *node_k, *newnode;
    edge *e;
    shrink_ary_T *ary = srk->shrinks.ary;
    expand_T *expands = &(srk->expands);
    int *shrinks_ = srk->shrinks_;
    shrink_T *shrinks = &(srk->shrinks);
    int old_shrinks_len;

    *found_aug = 0;

    do {
        FIND_SURFACE (n);
	shrinks->length = 0;
	expands->length = 0;

	if (grow_tree_no_shrink (G, n, fractional, srk)) {
            *found_aug = 1;
	    return 0;         
        }

        /* found no new match edge, so do shrinks */

        while (shrinks->length) {
            old_shrinks_len = shrinks->length;
            if (shrinks->length > 4) {   
                /* build buckets for all different sizes */
                for (i = 0; i < SHRINKS_SIZE; i++)
                    shrinks_[i] = -1;
                for (i = 0; i < shrinks->length; i++) {
                    size = ary[i].size;
                    if (size >= SHRINKS_SIZE)
                        size = SHRINKS_SIZE - 1;
                    if (shrinks_[size] == -1) {
                        shrinks_[size] = i;
                        ary[i].next = -1;
                    } else {
                        ary[i].next = shrinks_[size];
                        shrinks_[size] = i;
                    }
                }
                for (size = SHRINKS_SIZE - 1; size >= 3; size -= 2) {
                    for (i = shrinks_[size]; i != -1; i = ary[i].next) {
                        node_i = PNODE(ary[i].node_i);
                        node_j = PNODE(ary[i].node_j);
                        node_k = PNODE(ary[i].node_k);
                        e = PEDGE(ary[i].edge);
                        FIND_SURFACE (node_i);
                        FIND_SURFACE (node_j);
                        FIND_SURFACE (node_k);
                        if (node_i != node_j) {
                            newnode = shrink_blossom (G, node_i, node_j,
                                                      node_k, e, scount);
                            if ((checkout_node(G,newnode,fractional,srk)) >0) {
                                *found_aug = 1;
                                return 0;
                            }
                        }
                    }
                }
            } else {      /* just do all of the stupid shrinks */
                for (i = 0; i < shrinks->length; i++) {
                    node_i = PNODE(ary[i].node_i);
                    node_j = PNODE(ary[i].node_j);
                    node_k = PNODE(ary[i].node_k);
                    e = PEDGE(ary[i].edge);
                    FIND_SURFACE (node_i);
                    FIND_SURFACE (node_j);
                    FIND_SURFACE (node_k);
                    if (node_i != node_j) {
                        newnode = shrink_blossom (G, node_i, node_j,
                                                  node_k, e, scount);
                        if ((checkout_node (G, newnode, fractional, srk)) > 0) {
                            *found_aug = 1;
                            return 0;
                        }
                    }
                }
            }
            if (shrinks->length > old_shrinks_len) {
                size = shrinks->length - old_shrinks_len;
                for (i = 0; i < size; i++) {
                    ary[i].node_i = ary[i + old_shrinks_len].node_i;
                    ary[i].node_j = ary[i + old_shrinks_len].node_j;
                    ary[i].node_k = ary[i + old_shrinks_len].node_k;
                    ary[i].edge = ary[i + old_shrinks_len].edge;
                    ary[i].size = ary[i + old_shrinks_len].size;
                }
                shrinks->length = size;
            } else {
                shrinks->length = 0; 
            }
        }
	for (i = 0; i < expands->length; i++) {
	    /* blossom_root != -1 is necessary because expand
	     * of this node might have happened here before */
	    /* blossom_parent == -1 is necessary because
	     * this node might be shrunk already */
	    if (G->nodelist[expands->node[i]].blossom_root != -1 &&
                G->nodelist[expands->node[i]].blossom_parent == -1) {
		if (expand_blossom (G, G->nodelist+expands->node[i], scount)) {
                    fprintf (stderr, "expand_blossom failed\n");
                    return 1;
                }
	    }
	}
    } while (expands->length > 0);
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int apply_dual_change (graph *G, node *n, int delta)
#else
static int apply_dual_change (G, n, delta)
graph *G;
node *n;
int delta;
#endif
{
    int ei;
    edge *e;
    node *c=n;
    node *stop = G->nodelist - 1;

    if (delta == INTEGER_MAX) {
      //      	fprintf (stderr, "\ndelta=Infinity, node=%i\n", (int) (n-G->nodelist));
      //      	fprintf (stderr, "There seems to be no perfect matching\n");
      //	FAILED_NODE = (int)INODE(n);
      //      	print_node (G, n);
      return 1;
    }

    while (1) {
	if (c->label == PLUS) {
            c->hit = 1;
	    c->pi += delta;
	    for (ei = c->edg_list; ei != -1; ei = e->ptrs[ei % 2]) {
		e = PEDGE(ei/2);
		e->slack -= delta;
	    }
	} else if (c->label == MINUS) {
	    c->pi -= delta;
	    for (ei = c->edg_list; ei != -1; ei = e->ptrs[ei % 2]) {
		e = PEDGE(ei/2);
		e->slack += delta;
	    }
	}

	/* go to next c */

	if (c->child != -1) {
	    c = PNODE(c->child);
	} else {
	    while (PNODE(c->sibling) == stop) {
		if (c == n) return 0; /* this if is for childless n */
		c = PNODE(c->parent);
		if (c == n) return 0;
	    }
	    c = PNODE(c->sibling);
	}
    }
}

#ifdef CC_PROTOTYPE_ANSI
static int find_single_dual_change (graph *G, node *n)
#else
static int find_single_dual_change (G, n)
graph *G;
node *n;
#endif
{
    edge *e;
    int ei;
    int lab;
    int delta;
    node *c = n;
    node *stop = G->nodelist - 1;

#if PRINT_LEVEL
    printf (" %i", (int) (n - PG->nodelist));
    fflush (stdout);
#endif

    delta = INTEGER_MAX;

    while (1) {
	if (c->label == PLUS) {
	    for (ei = c->edg_list; ei != -1; ei = e->ptrs[ei % 2]) {
		e = PEDGE(ei/2);
		if (e->slack < 2 * delta) {
		    lab = OTHEREND (e, c, G->nodelist)->label;
		    if (lab == PLUS) {
			delta = e->slack / 2;
		    } else if (lab == NIX) {
			if (e->slack < delta) {
			    delta = e->slack;
			}
		    }
		}
	    }
	} else if (c->label == MINUS) {
	    if (c->blossom_root != -1 && c->pi < delta) {
		delta = c->pi;
	    }
	}

	/* go to next c */

	if (c->child != -1) {
	    c = PNODE(c->child);
	} else {
	    while (PNODE(c->sibling) == stop) {
		if (c == n) return delta ; /* this if is for childless n */
		c = PNODE(c->parent);
		if (c == n) return delta;
	    }
	    c = PNODE(c->sibling);
	}
    }
}

#ifdef CC_PROTOTYPE_ANSI
static int find_dual_change_forest (graph *G, node *n)
#else
static int find_dual_change_forest (G, n)
graph *G;
node *n;
#endif
{
    edge *e;
    int ei;
    int delta;
    nodeptr *roots = G->roots;
    node *c = n, *o;
    node *stop = G->nodelist - 1;

#if PRINT_LEVEL
    printf (" %i", (int) (c - PG->nodelist));
    fflush (stdout);
#endif

    delta = INTEGER_MAX;

    while (1) {
	if (c->label == PLUS) {
	    for (ei = c->edg_list; ei != -1; ei = e->ptrs[ei % 2]) {
		e = PEDGE(ei/2);
		o = OTHEREND (e, c, G->nodelist);
		switch (o->label) {
#ifdef GREEDY_DUAL_CHANGE
                case PLUS:
                    if (roots[c->tree_root].dad != roots[o->tree_root].dad ) {
                        /* two trees, not connected with vereinigung */
                        if (roots[o->tree_root].tree_processed) {
                            if (delta > e->slack -
                                        roots[roots[o->tree_root].dad].delta) {
                                delta = e->slack -
                                        roots[roots[o->tree_root].dad].delta;
                            }
                        } else {
                            if (e->slack < delta) {
                                delta = e->slack;
                            }
                        }
                    } else {
                        if (e->slack < 2 * delta) {
                            delta = e->slack / 2;
                        }
                    }
                    break;
                case NIX:
                    if (e->slack < delta) {
                        delta = e->slack;
                    }
                    break;
                case MINUS:
                    if (roots[c->tree_root].dad != roots[o->tree_root].dad) {
                        /* two trees, not connected with vereinigung */
                        if (roots[o->tree_root].tree_processed) { 
                            if (delta > e->slack +
                                        roots[roots[o->tree_root].dad].delta) {
                                delta = e->slack +
                                        roots[roots[o->tree_root].dad].delta;
                            }
                        } else {
                            if (e->slack < delta ) {
                                delta = e->slack;
                            }
                        }
                    }
                }
#else /* GREEDY_DUAL_CHANGE */
		case PLUS:
		    if (e->slack < 2 * delta) {
		        delta = e->slack / 2;
		    }
		    break;
		case NIX:
		    if (e->slack < delta) {
			delta = e->slack;
		    }
		    break;
		case MINUS:
		    if (roots[c->tree_root].dad != roots[o->tree_root].dad) { 
		        if (e->slack < delta ) {
			    delta = e->slack;
			}
		    }
		}
#endif /* GREEDY_DUAL_CHANGE */
	    }
	} else if (c->label == MINUS) {
	    if (c->blossom_root != -1 && c->pi <= delta) {
		delta = c->pi;
	    }
	}
	
	/* go to next c */

	if (c->child != -1) {
	    c = PNODE(c->child);
	} else {
	    while (PNODE(c->sibling) == stop) {
		if (c == n) return delta ; /* this is for childless n */
		c = PNODE(c->parent);
		if (c == n) return delta;
	    }
	    c = PNODE(c->sibling);
	}
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void vereinigung (graph *G, int x, int y)
#else
static void vereinigung (G, x, y)
graph *G;
int x, y;
#endif
{
    int xroot, yroot, dad;
    nodeptr *roots = G->roots;

#if PRINT_LEVEL
    printf (" vereinigung (%i,%i)", x, y); fflush (stdout);
#endif

    xroot = x;
    while (roots[xroot].dad >= 0)
	xroot = roots[xroot].dad;
    while (roots[x].dad >= 0) {
        dad = roots[x].dad;
        roots[x].dad = xroot;
        x = dad;
    }

    yroot = y;
    while (roots[yroot].dad >= 0)
	yroot = roots[yroot].dad;
    while (roots[y].dad >= 0) {
        dad = roots[y].dad;
        roots[y].dad = yroot;
        y = dad;
    }

    if (xroot != yroot) {
	if (roots[yroot].dad < roots[xroot].dad) {
            roots[yroot].dad += roots[xroot].dad; 
            roots[xroot].dad = yroot;
	} else {
	    roots[xroot].dad += roots[yroot].dad; 
	    roots[yroot].dad = xroot;
	}
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void set_vereinigung (graph *G, node *n)
#else
static void set_vereinigung (G, n)
graph *G;
node *n;
#endif
{
    edge *e;
    int ei;
    node *nod = G->nodelist;
    node *c = n;
    node *stop = G->nodelist - 1;

#if PRINT_LEVEL
    printf (" set_vereinigung (%i)", (int) (n - PG->nodelist));
    fflush (stdout);
#endif

    /* this is called only for PLUS nodes */

    while (1) {
	for (ei = c->edg_list; ei != -1; ei = e->ptrs[ei % 2]) {
	    e = PEDGE(ei/2);
	    if (nod[e->nod1].tree_root != nod[e->nod2].tree_root) {  
		if (e->slack == 0) {	
		    if (OTHEREND (e, c, nod)->label == MINUS) {
			vereinigung (G, nod[e->nod1].tree_root,
				        nod[e->nod2].tree_root);
		    }
		}
	    }
	}
	
	/* now check the chilren of c's children (these are PLUS nodes) */

	if (c->child != -1) {
	    c = PNODE(PNODE(c->child)->child);
	} else {
	    if (c == n) return; /* this if is for childless n */
	    c = PNODE(c->parent);
	    while (PNODE(c->sibling) == stop) {
		c = PNODE(c->parent);
		if (c == n) return;
		c = PNODE(c->parent);
	    }
	    c = PNODE(PNODE(c->sibling)->child);
	}
    }
}

#ifdef CC_PROTOTYPE_ANSI
static int find_parity_sum (graph *G, int n)
#else
static int find_parity_sum (G, n)
graph *G;
int n;
#endif
{
    node *v;
    int sum, ei;
    edge *e;

    ei = PNODE(n)->edg_list;
    e = PEDGE(ei/2);

    if (e->nod1 == n) {
        v = PNODE(e->orig_nod1); 
    } else {
        v = PNODE(e->orig_nod2);
    }

    sum = v->pi;
    while (v->blossom_parent != -1) {
        v = PNODE(v->blossom_parent);
        sum += v->pi;
    }

    return sum;
}

#ifdef CC_PROTOTYPE_ANSI
static int parity_correction (graph *G, stats *scount)
#else
static int parity_correction (G, scount)
graph *G;
stats *scount;
#endif
{
    nodeptr *np, *npprev = (nodeptr *) NULL;
    int hitme = 0;
    nodeptr *roots = G->roots;
    nodeptr *rstop = G->roots - 1;

#if PRINT_LEVEL
    printf ("   parity_correction ...\n"); 
    fflush (stdout);
#endif

    np = roots + G->unmatched;
    while (np->status != UNMATCHED)  
        np = roots + np->next;
    G->unmatched = np - roots;

    while (np != rstop) {
        if (np->status != UNMATCHED) {
            npprev->next = np->next;
        } else {
            if (np->sum % 2) {
                hitme = 1;
                scount->dualchange_count++;
                if (apply_dual_change (G, PNODE(np->surf), 1)) {
		  //                    fprintf (stderr, "apply_dual_change failed\n");
                    return -1;
                }
                np->sum += 1; 
            }
            npprev = np;
        }
        np = roots + np->next;
    }
    return hitme;
}

#ifdef CC_PROTOTYPE_ANSI
static int make_dual_change_forest (graph *G, stats *scount)
#else
static int make_dual_change_forest (G, scount)
graph *G;
stats *scount;
#endif
{
    nodeptr *np;
    int t;
    int delta;
    nodeptr *roots = G->roots;
    nodeptr *rstop = G->roots - 1;

#if PRINT_LEVEL
    printf ("\n   make_dual_change_forest ...\n");
    fflush (stdout);
#endif

    if (parity_correction (G, scount) == -1) {
        fprintf (stderr, "parity_correction failed\n");
        return -1;
    }

    for (np = roots + G->unmatched; np != rstop; np = roots + np->next) 
        np->dad = -1;     /*  Set dad for all trees to -1 */

    for (np = roots + G->unmatched; np != rstop; np = roots + np->next) 
        set_vereinigung (G, PNODE(np->surf));

    /* Set roots to point to theirselves */
    for (np = roots + G->unmatched; np != rstop; np = roots + np->next) {
        if (np->dad < 0) {
            np->dad = np - roots;
            np->delta = INTEGER_MAX; 
        }
    }

    /* Set others to point to root */
    for (np = roots + G->unmatched; np != rstop; np = roots + np->next) {
        t = np - roots;
        while (roots[t].dad != t)
            t = roots[t].dad;
        np->dad = t;
    }

#ifdef GREEDY_DUAL_CHANGE
    {
        int npnext;
        int glist = -1;

        /* order the unmatched nodes so that each union appears consecutively */

        for (np = roots + G->unmatched; np != rstop; np = roots + np->next) {
            np->tree_processed = 0;
            if (np->dad == np - roots) {
                np->gnext = glist;
                glist = np - roots;
            }
        }

        for (np = roots + G->unmatched; np != rstop; np = roots + np->next) {
            if (np->dad != np - roots) {
                np->gnext = roots[np->dad].gnext;
                roots[np->dad].gnext = np - roots;
            }
        }

        for (np = roots + G->unmatched; np != rstop; np = roots + npnext) {
            npnext = np->next;
            np->next = np->gnext;
        }
        G->unmatched = glist;
    }
#endif

    /* Set delta for all vereinigung trees */
    for (np = roots + G->unmatched; np != rstop; np = roots + np->next) {
	delta = find_dual_change_forest (G, PNODE(np->surf));
	if (delta < roots[np->dad].delta)
	    roots[np->dad].delta = delta;
#ifdef GREEDY_DUAL_CHANGE
        np->tree_processed = 1;
#endif
    } 

    /* Apply_dual_change for all vereinigung trees */
    for (np = roots + G->unmatched; np != rstop; np = roots + np->next) {
	delta = roots[np->dad].delta;
        scount->dualchange_count++;
        if (delta == 0) {
            scount->dualzero_count++;
        } else {
            if (apply_dual_change (G, PNODE(np->surf), delta)) {
	      //                fprintf (stderr, "apply_dual_change failed\n");
                return -1;
            }
        }
        np->sum += delta; 
    }

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int match_main_frac (graph *G, stats *scount, srkstuff *srk)
#else
static int match_main_frac (G, scount, srk)
graph *G;
stats *scount;
srkstuff *srk;
#endif
{
    node *n;
    int i, delta;
    int found_aug = 0;

    /* Just work with one tree   */

    for (i = 0, n = G->nodelist; i < G->nnodes; i++, n++) {
        if (n->status == UNMATCHED) {
	    init_tree (G, n);
            if (grow_tree (G, n, 1, scount, srk, &found_aug)) {
                fprintf (stderr, "grow_tree failed\n");
                return 1;
            }
            while (!found_aug) {
                scount->dualchange_count++;
                delta = find_single_dual_change (G, n);
                if (delta != 0) {
                    if (apply_dual_change (G, n, delta)) {
		      //                        fprintf (stderr, "apply_dual_change failed\n");
                        return 1;
                    }
                } else {
                    scount->dualzero_count++;
                }
                if (grow_tree (G, n, 1, scount, srk, &found_aug)) {
                    fprintf (stderr, "grow_tree failed\n");
                    return 1;
                }
	    }
#if PRINT_LEVEL
            printf ("."); fflush (stdout);
#endif
        }
    }
    //    printf (" %i Dual Changes, %i with delta=0 ",
    //             scount->dualchange_count, scount->dualzero_count);
    //    fflush (stdout);
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int match_main_more_in_forest (graph *G, stats *scount, srkstuff *srk)
#else
static int match_main_more_in_forest (G, scount, srk)
graph *G;
stats *scount;
srkstuff *srk;
#endif
{
    nodeptr *np;
    node *n;
    int i, ni, ninext;
    int grow_status_forest;
    int found_aug = 0;
    nodeptr *roots, *rstop;

    /* The unmatched surface nodes should be linked using the mark  */
    /* fields, with G->unmatched pointing to the start of the list. */
    /* G->umatched is assumed to be accurate.                       */

    if (G->unmatched_count == 0) 
	return 0;

    /* ********************************* */
    /* First init all forests            */
    /* ********************************* */

    G->roots = CC_SAFE_MALLOC (G->unmatched_count, nodeptr);
    if (!G->roots) {
      //        fprintf (stderr, "out of memory in match_main_more_in_forest\n");
        return 1;
    }
    roots = G->roots;
    rstop = G->roots - 1;

    for (i = 0, ni = G->unmatched; ni != -1; ni = ninext, i++) {
        n = PNODE(ni);
        ninext = n->mark;
        n->mark = 0;
        roots[i].status = UNMATCHED;
        roots[i].surf = ni;
        roots[i].sum = find_parity_sum (G, ni);
        roots[i].next = i+1;
        init_tree (G, n);
        n->tree_root = i;
    }
    roots[i - 1].next = -1;
    G->unmatched = 0;

    //    printf ("\nTry to grow the trees in the forest directly\n");
    //    fflush (stdout);

    /* ************************************ */
    /* Try to grow all forests directly     */
    /* ************************************ */

    for (np = roots + G->unmatched; np != rstop; np = roots + np->next) {
        n = PNODE(np->surf);
        if (np->status == UNMATCHED) {
            if (grow_tree (G, n, 0, scount, srk, &found_aug)) {
	      //                fprintf (stderr, "grow_tree failed\n");
                return 1;
            }
            if (found_aug) {	 
	      //                printf ("."); fflush (stdout);
                if (G->unmatched_count == 0) {
                    return 0;
                }
	    }
        }
    }

    /* *************************** */
    /* Work with tree-vereinigung  */
    /* *************************** */

    //    printf ("\nNow work on tree-vereinigung in a forest (%i points)\n",
    //                        G->unmatched_count / 2);
    //    fflush (stdout);

    /* first make sure that all trees have the correct parity */

    if (parity_correction (G, scount) == -1) {
      //        fprintf (stderr, "parity_correction failed\n");
        return 1;
    }

    while (G->unmatched_count > 0) {
        if (make_dual_change_forest (G, scount) == -1) {
	  //            fprintf (stderr, "make_dual_change_forest failed\n");
            return 1;
        }
        do {
	    grow_status_forest = 0;
            for (np = roots + G->unmatched; np != rstop; np = roots+np->next) {
		n = PNODE(np->surf);
                if (np->status == UNMATCHED) {
		    if (grow_tree (G, n, 0, scount, srk, &found_aug)) {
		      //                        fprintf (stderr, "grow_tree failed\n");
                        return 1;
                    }
		    if (found_aug) { 
		      //		        printf ("."); fflush (stdout);
		        if (G->unmatched_count == 0) {
                            goto DONE;
		        }
		        grow_status_forest = 1;
		    }
	        }
            }
	} while (grow_status_forest);
    }

DONE:

    G->unmatched = -1;
    CC_IFFREE (G->roots, nodeptr);

    //    printf ("\n %i Dual Changes, %i with delta=0 ",
    //	       scount->dualchange_count, scount->dualzero_count);
    //    printf ("| %i Expands ", scount->expand_count);
    //    printf ("| %i Shrinks ", scount->shrink_count);
    //    fflush (stdout);

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int match_main_forest (graph *G, stats *scount, srkstuff *srk)
#else
static int match_main_forest (G, scount, srk)
graph *G;
stats *scount;
srkstuff *srk;
#endif
{
    nodeptr *np;
    node *n;
    int i, ni, ninext;
    int grow_status_forest;
    int found_aug = 0;
    int delta, delta2;
    int do_parity = 1;
    nodeptr *roots, *rstop;

    //    printf ("match_main_forest (%d points)\n", G->unmatched_count / 2);
    //    fflush (stdout);

    if (G->unmatched_count == 0) {
	return 0;
    }

    /* ********************************* */
    /* First init all forests            */
    /* ********************************* */

    G->roots = CC_SAFE_MALLOC (G->unmatched_count, nodeptr);
    if (!G->roots) {
        fprintf (stderr, "out of memory in match_main_more_in_forest\n");
        return 1;
    }
    roots = G->roots;
    rstop = G->roots - 1;

    for (i = 0, ni = G->unmatched; ni != -1; ni = ninext, i++) {
        n = PNODE(ni);
        ninext = n->mark;
        n->mark = 0;
        roots[i].status = UNMATCHED;
        roots[i].surf = ni;
        roots[i].sum = find_parity_sum (G, ni);
        roots[i].next = i+1;
        init_tree (G, n);
        n->tree_root = i;
    }
    roots[i - 1].next = -1;
    G->unmatched = 0;

    /* ********************************* */
    /* Work with a forest                */
    /* ********************************* */

    while (G->unmatched_count > 0) {
        do {
	    grow_status_forest = 0;
            for (np = roots + G->unmatched; np != rstop; np = roots+np->next) {
		n = PNODE(np->surf);
                if (np->status == UNMATCHED) {
		    if (grow_tree (G, n, 0, scount, srk, &found_aug)) {
		      //                        fprintf (stderr, "grow_tree failed\n");
                        return 1;
                    }
		    if (found_aug) {
		        printf ("."); fflush (stdout);
		        if (G->unmatched_count == 0) {
                            goto DONE;
                        }
		        grow_status_forest = 1;
                    }
		}
	    }
	} while (grow_status_forest);

        if (G->unmatched_count > 0 && do_parity) {
            if (parity_correction (G, scount) == -1) {
	      //                fprintf (stderr, "parity_correction failed\n");
                return 1;
            }
            do_parity = 0;
        }
    
	if (G->unmatched_count > 0 && !do_parity) {
	    delta = INTEGER_MAX;
	    scount->dualchange_count++;
            for (np = roots + G->unmatched; np != rstop; np = roots+np->next) {
		n = PNODE(np->surf);
                if (np->status == UNMATCHED) {
		    delta2 = find_single_dual_change (G, n);
		    if (delta2 < delta) {
		        delta = delta2;
                    }
                }
	    } 

	    if (delta == 0) {
		scount->dualzero_count++;
            } else {
                for (np = roots+G->unmatched; np!=rstop; np = roots+np->next) {
		    n = PNODE(np->surf);
                    if (np->status == UNMATCHED) {
		        if (apply_dual_change (G, n, delta)) {
			  //                            fprintf (stderr, "apply_dual_change failed\n");
                            return 1;
                        }
                        np->sum += delta; 
                    }
		}
	    }
	}
    }

DONE:

    G->unmatched = -1;
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int match_main_tree (graph *G, stats *scount, srkstuff *srk)
#else
static int match_main_tree (G, scount, srk)
graph *G;
stats *scount;
srkstuff *srk;
#endif
{
    nodeptr *np;
    node *n;
    int i, ni, ninext;
    int found_aug = 0;
    int delta;
    nodeptr *roots, *rstop;

    //    printf ("match_main_tree (%d points)\n", G->unmatched_count / 2);
    //    fflush (stdout);

    if (G->unmatched_count == 0) {
	return 0;
    }

    /* ********************************* */
    /* First init all forests            */
    /* ********************************* */

    G->roots = CC_SAFE_MALLOC (G->unmatched_count, nodeptr);
    if (!G->roots) {
      //        fprintf (stderr, "out of memory in match_main_more_in_forest\n");
        return 1;
    }
    roots = G->roots;
    rstop = G->roots - 1;

    for (i = 0, ni = G->unmatched; ni != -1; ni = ninext, i++) {
        n = PNODE(ni);
        ninext = n->mark;
        n->mark = 0;
        roots[i].status = UNMATCHED;
        roots[i].surf = ni;
        roots[i].sum = find_parity_sum (G, ni);
        roots[i].next = i+1;
        /* init_tree (G, n); */
        n->tree_root = i;
    }
    roots[i - 1].next = -1;
    G->unmatched = 0;

    /* ********************************* */
    /* Work with a tree                  */
    /* ********************************* */

    while (G->unmatched_count > 0) {
        np = roots + G->unmatched; 
        while (np->status != UNMATCHED) {
            np = roots + np->next;
        }
        G->unmatched = np - roots;
        np = roots + G->unmatched; 
        n = PNODE(np->surf);
        init_tree (G, n);
        do {
            if (grow_tree (G, n, 0, scount, srk, &found_aug)) {
	      //                fprintf (stderr, "grow_tree failed\n");
                return 1;
            }
            if (found_aug) {
                printf ("."); fflush (stdout);
	        if (G->unmatched_count == 0) {
                    goto DONE;
                }
            } else {
                scount->dualchange_count++;
                n = PNODE(np->surf);
	        delta = find_single_dual_change (G, n);

	        if (delta == 0) {
	            scount->dualzero_count++;
                } else {
	            if (apply_dual_change (G, n, delta)) {
		      //                        fprintf (stderr, "apply_dual_change failed\n");
                        return 1;
                    }
                }
	    }
        } while (!found_aug);
    }

DONE:

    G->unmatched = -1;
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int match_main (graph *G, stats *scount, srkstuff *srk, int use_all)
#else
static int match_main (G, scount, srk, use_all)
graph *G;
stats *scount;
srkstuff *srk;
int use_all;
#endif
{
    double szeit;

    szeit = CCutil_zeit ();
    //    printf (" Need to find %i edges ...\n", G->unmatched_count / 2);
    //    fflush (stdout);

    if (!G->unmatched_count) 
        return 0;

    if (use_all == 2) {
        if (match_main_tree (G, scount, srk)) {
	  //            fprintf (stderr, "match_main_tree failed\n");
            return 1;
        }
    } else if (use_all == 1) {
        if (match_main_forest (G, scount, srk)) {
	  //            fprintf (stderr, "match_main_forest failed\n");
            return 1;
        }
    } else {
        if (match_main_more_in_forest (G, scount, srk)) {
	  //            fprintf (stderr, "match_main_more_in_forest failed\n");
            return 1;
        }
    }
    //    printf ("\n %i Dual Changes, %i with delta=0 \n",
    //               scount->dualchange_count, scount->dualzero_count);
    //    printf (" %i Expands \n", scount->expand_count);
    //    printf (" %i Shrinks \n", scount->shrink_count);
    //    printf (" Running Time in match_main: %.2f\n", CCutil_zeit () - szeit);
    //    fflush (stdout);

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static node *find_below (graph *G, node *n, int blossom)
#else
static node *find_below (G, n, blossom)
graph *G;
node *n;
int blossom;
#endif
{
    if (!n)
        return (node *) NULL;

    for (; n->blossom_parent != blossom; n = PNODE(n->blossom_parent)) {
        if (n->blossom_parent == -1)
            return (node *) NULL;
    }
    return n;
}

#ifdef CC_PROTOTYPE_ANSI
static void fix_match (graph *G, int blossom)
#else
static void fix_match (G, blossom)
graph *G;
int blossom;
#endif
{
    node *x, *n;
    node *b = blossom + G->nodelist;
  
#if PRINT_LEVEL
    printf ("   Fixing blossom %i ", blossom);
    fflush (stdout);
#endif

    x = find_below (G, PNODE(G->edgelist[b->matched_edge].orig_nod1),
               blossom);
    if (x == (node *) NULL) {
	x = find_below (G, PNODE(G->edgelist[b->matched_edge].orig_nod2),
               blossom);
    }
    /* x is now something like the match_edge->nod(1 or 2)->penultimate */
    fix_matching (G, b, x);
    b->mark = 1;

    n = PNODE(b->blossom_root);
    do {
	if (n->blossom_root != -1)          /* if n is a real blossom */
	    fix_match (G, INODE(n));        /* call fix match again */
	n = PNODE(n->blossom_next);
    } while (n != PNODE(b->blossom_root));
}

#ifdef CC_PROTOTYPE_ANSI
static void adjust_match (graph *G)
#else
static void adjust_match (G)
graph *G;
#endif
{
    node *n, *b;
    int i;
    int ncount = G->nnodes;
    node *nodelist = G->nodelist;

    for (i = 0; i < ncount; i++) {
	n = PNODE(i);
	if (n->blossom_parent != -1 && nodelist[n->blossom_parent].mark == 0) {
	    for (b = n; b->blossom_parent != -1 &&
               nodelist[b->blossom_parent].mark == 0;
               b = PNODE(b->blossom_parent));
	    fix_match (G, INODE(b));
	}
    }
}

#ifdef CARELESS_REPAIRS
#ifdef CC_PROTOTYPE_ANSI
static int bring_to_surface (graph *G, node *p, stats *scount, srkstuff *srk)
#else
static int bring_to_surface (G, p, scount, srk)
graph *G;
node *p;
stats *scount;
srkstuff *srk;
#endif
{
    node *psurf, *n, *memo, *x;
    edge *e;
    int ei;

    if (p->blossom_parent == -1) 
        return 0;

    psurf = p;
    while (psurf->blossom_parent != -1) {
        psurf = PNODE(psurf->blossom_parent);
    }

    while (p != psurf) {
        scount->expand_count++;

        /* Mark edge to be unmatched later */
        G->edgelist[psurf->matched_edge].mark = 1;

        for (ei = psurf->edg_list; ei != -1; ei = e->ptrs[ei % 2]) {
            e = PEDGE(ei/2);
            e->slack += psurf->pi;
        }

        n = memo = PNODE(psurf->blossom_root);
        do {
            label_penultimate (G, n, INODE(n));
            n = PNODE(n->blossom_next);
        } while (n != memo);

        if (G->edgelist[psurf->matched_edge].nod1 == (psurf - G->nodelist))
            x = PNODE(G->edgelist[psurf->matched_edge].orig_nod1);
        else
	    x = PNODE(G->edgelist[psurf->matched_edge].orig_nod2);

        if (lower_edges (G, psurf)) {
            fprintf (stderr, "lower_edges failed\n");
            return 1;
        }
        fix_matching (G, psurf, PNODE(x->penultimate));

        n = memo;
        do {
	    /* Clear tree structure of nodes in psurf's blossom */
            n->blossom_parent = -1;
            n->child = -1;
            n->parent = -1;
            n->sibling = -1;
            n->parent_edge = -1;
            n->label = NIX;
	    n = PNODE(n->blossom_next);
            n->hit = n->hit | psurf->hit;
        } while (n != memo);

        /* clear oldnode */

        psurf->edg_list = -1;
        psurf->pi = 0;
        psurf->status = UNMATCHED;
        psurf->matched_edge = -1;
        psurf->child = -1;
        psurf->sibling = -1;
        psurf->parent = -1;
        psurf->parent_edge = -1;
        psurf->label = NIX;
        psurf->blossom_root = -1;
        psurf->blossom_next = -1;
        psurf->blossom_next_edge = -1;
        psurf->blossom_parent = -1;
        psurf->penultimate = -1;
        psurf->tree_root = -1;
        psurf->hit = 0;
    
        /* add psurf to unused list */

        psurf->mark = G->unused;
        G->unused = psurf - G->nodelist;

        psurf = PNODE(p->penultimate);
    }

    return 0;
}
#endif  /* CARELESS_REPAIRS */

#ifdef BALL_DERIGS_REPAIRS
#ifdef CC_PROTOTYPE_ANSI
static int bring_to_surface (graph *G, node *p, stats *scount, srkstuff *srk)
#else
static int bring_to_surface (G, p, scount, srk)
graph *G;
node *p;
stats *scount;
srkstuff *srk;
#endif
{
    node *n, *newnode;
    node *stop = G->nodelist - 1;
    edge *e, *f;
    int sum, delta;
    int found_aug = 0;

    printf ("bring to surface (%d) ...\n", p - G->nodelist);
    fflush (stdout);

    if (p->blossom_parent == -1) {
        return 0;
    }

    /* Take newnode from unused list */

    newnode = PNODE(G->unused);
    G->unused = newnode->mark;
    newnode->mark = 0;

    /* Initialize newnode */ 

    sum = 0;
    for (n = p; n != stop; n = PNODE(n->blossom_parent))
        sum += n->pi;

    newnode->matched_edge = -1;
    newnode->status = UNMATCHED;
    newnode->pi = sum % 2;

    /* Add the edge (newnode, p) */

    if (G->nedges >= G->max_nedges) {
        fprintf (stderr, "number of edges exceeds max_nedges\n");
        return 1;
    }
    e = PEDGE(G->nedges);
    e->slack = 0;
    e->x = 0;
    e->orig_nod1 = e->nod1 = newnode - G->nodelist;
    e->orig_nod2 = p - G->nodelist;
    n = p;
    while (n->blossom_parent != -1)
        n = PNODE(n->blossom_parent);
    e->nod2 = INODE(n); 

    /* Attach the new edge to the edg_lists of newnode and n */

    e->ptrs[0] = n->edg_list;
    n->edg_list = 2*G->nedges;
    e->ptrs[1] = -1;
    newnode->edg_list = 2*G->nedges + 1;

    G->nedges++;

    init_tree (G, newnode);
    newnode->tree_root = INODE(newnode);

    if (grow_tree (G, newnode, 0, scount, srk, &found_aug)) {
        fprintf (stderr, "grow_tree failed\n");
        return 1;
    }
    if (found_aug) {
        fprintf (stderr, "found an augmentation in bring_to_surface\n");
        return 1;
    }

    while (p->blossom_parent != -1) {
        delta = find_single_dual_change (G, newnode);
        fflush (stdout);
        if (delta == 0) {
            printf ("O"); fflush (stdout);
        }
        if (apply_dual_change (G, newnode, delta)) {
	  //            fprintf (stderr, "apply_dual_change failed\n");
            return 1;
        }
        if (grow_tree (G, newnode, 0, scount, srk, &found_aug)) {
            fprintf (stderr, "grow_tree failed\n");
            return 1;
        }
        if (found_aug) {
            fprintf (stderr, "found an augmentation in bring_to_surface\n");
            return 1;
        }
    }

    clear_tree (G, newnode);

    /* reset newnode */

    newnode->edg_list = -1;
    newnode->pi = 0;
    newnode->status = UNMATCHED;
    newnode->matched_edge = -1;
    newnode->child = -1;
    newnode->sibling = -1;
    newnode->parent = -1;
    newnode->parent_edge = -1;
    newnode->label = NIX;
    newnode->blossom_root = -1;
    newnode->blossom_next = -1;
    newnode->blossom_next_edge = -1;
    newnode->blossom_parent = -1;
    newnode->penultimate = -1;
    newnode->tree_root = -1;
    newnode->hit = 0;

    /* Delete the added edge */

    f = PEDGE (p->edg_list/2);
    if (f == e) {
        p->edg_list = e->ptrs[p->edg_list % 2];
    } else {
        int ei, eiprev = p->edg_list;

        for (ei = f->ptrs[p->edg_list % 2]; ei != -1; ei = f->ptrs[ei % 2]) {
            f = PEDGE(ei/2);
            if (f == e) {
                G->edgelist[eiprev/2].ptrs[eiprev % 2] = f->ptrs[ei % 2];
                break;
            }
            eiprev = ei;
        }
        if (ei == -1) {
            fprintf (stderr, "Screw up in bring_to_surface\n");
            return 1;
        }
    }
    G->nedges--;

    /* Return newnode from unused list */

    newnode->mark = G->unused;
    G->unused = newnode - G->nodelist;

    return 0;
}
#endif  /* BALL_DERIGS_REPAIRS */

#ifdef CC_PROTOTYPE_ANSI
static int add_repair_edge (graph *G, int n1, int n2, int len,
                            stats *scount, srkstuff *srk)
#else
static int add_repair_edge (G, n1, n2, len, scount, srk)
graph *G;
int n1, n2, len;
stats *scount;
srkstuff *srk;
#endif
{
    edge *e, *f = (edge *) NULL;
    node *n1surf, *n2surf;
    int ei, eiprev = -1, sum2;

    n1surf = PNODE(n1);
    n2surf = PNODE(n2);
    sum2 = n2surf->pi;
    while (n2surf->blossom_parent != -1) {
        n2surf = PNODE(n2surf->blossom_parent);
        sum2 += n2surf->pi;
    }

    if (G->nedges >= G->max_nedges) {
        fprintf (stderr, "number of edges exceeds max_nedges\n");
        return 1;
    }
    e = PEDGE(G->nedges);
    e->slack = len - n1surf->pi - sum2;
    e->mark = 0;
    e->x = 0;
    e->orig_nod1 = n1;
    e->orig_nod2 = n2;
    e->nod1 = n1surf - G->nodelist;
    e->nod2 = n2surf - G->nodelist; 

    for (ei = n1surf->edg_list; ei != -1; ei = f->ptrs[ei % 2]) {
        f = PEDGE(ei/2);
        eiprev = ei;
    }
    f->ptrs[eiprev % 2] = 2*G->nedges;
    e->ptrs[0] = -1;

    for (ei = n2surf->edg_list; ei != -1; ei = f->ptrs[ei % 2]) {
        f = PEDGE(ei/2);
        eiprev = ei;
    }
    f->ptrs[eiprev % 2] = 2*G->nedges + 1;
    e->ptrs[1] = -1;
    
    G->nedges++;

    if (e->slack < 0) {
        n1surf->pi += e->slack;
        for (ei = n1surf->edg_list; ei != -1; ei = f->ptrs[ei % 2]) {
            f = PEDGE(ei/2);
            f->slack -= e->slack;
        }
    }

#ifdef BALL_DERIGS_REPAIRS
    if (n1surf->matched_edge != -1) {
        unmatch_edge (G, PEDGE(n1surf->matched_edge)); 
        if (match_main_more_in_forest (G, scount, srk)) {
        /* if (match_main_forest (G, scount, srk)) { */
            fprintf (stderr, "match_main_more_in_forest failed\n");
            return 1;
        }
    }
#endif
#ifdef CARELESS_REPAIRS
    if (n1surf->matched_edge != -1) {
        /* mark edges to be unmatched later */
        G->edgelist[n1surf->matched_edge].mark = 1;
    }
#endif

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static void unmatch_edge (graph *G, edge *e)
#else
static void unmatch_edge (G, e)
graph *G;
edge *e;
#endif
{
    G->nodelist[e->nod1].status = UNMATCHED;
    G->nodelist[e->nod2].status = UNMATCHED;
    e->x = 0;
    G->nodelist[e->nod1].matched_edge = -1;
    G->nodelist[e->nod2].matched_edge = -1;
    G->unmatched_count += 2;

    G->nodelist[e->nod1].mark = G->unmatched;
    G->nodelist[e->nod2].mark = e->nod1;
    G->unmatched = e->nod2;
}

#ifdef CC_PROTOTYPE_ANSI
static int run_repair (graph *G, int badcount, int *badlist, int *badlen,
                       stats *scount, srkstuff *srk)
#else
static int run_repair (G, badcount, badlist, badlen, scount, srk)
graph *G;
int badcount;
int *badlist;
int *badlen;
stats *scount;
srkstuff *srk;
#endif
{
    int i, sum1, sum2;
    int n1, n2;
    node *n;
    edge *e, *lastedge;

    for (i = 0; i < badcount; i++) {
#ifdef PRINT_REPAIRS
        printf ("Bad Edge [%d, %d]\n", badlist[2*i], badlist[2*i + 1]);
        fflush (stdout);
#endif
        sum1 = 0;
        n = PNODE(badlist[2*i]);
        while (n->blossom_parent != -1) {
            n = PNODE(n->blossom_parent);
            sum1 += n->pi;
        }
        sum2 = 0;
        n = PNODE(badlist[2*i + 1]);
        while (n->blossom_parent != -1) {
            n = PNODE(n->blossom_parent);
            sum2 += n->pi;
        }
        if (sum1 < sum2) {
            n1 = badlist[2*i];
            n2 = badlist[2*i + 1];
        } else {
            n1 = badlist[2*i + 1];
            n2 = badlist[2*i];
        }
        if (bring_to_surface (G, PNODE(n1), scount, srk)){
            fprintf (stderr, "bring_to_surface failed\n");
            return 1;
        }
        if (add_repair_edge (G, n1, n2, 2 * badlen[i], scount, srk)) {
            fprintf (stderr, "add_repair_edge failed\n");
            return 1;
        }
        printf ("+"); fflush (stdout);
    }
    printf ("\n");

    lastedge = PEDGE(G->nedges);
    for (e = G->edgelist; e != lastedge; e++) {
        if (e->mark) {
            e->mark = 0;
            if (e->x == 1) {
                unmatch_edge (G, e);
            }
        }
    }

    if (G->unmatched_count > 0) {
/*
        if (match_main_forest (G, scount, srk)) {
            fprintf (stderr, "match_main_forest failed\n");
            return 1;
        }
*/
        if (match_main_more_in_forest (G, scount, srk)) {
            fprintf (stderr, "match_main_more_in_forest failed\n");
            return 1;
        }
    }

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int add_edges (graph *G, CCdatagroup *dat, int badcount, int *badlist,
                      int *badlen)
#else
static int add_edges (G, dat, badcount, badlist, badlen)
graph *G;
CCdatagroup *dat;
int badcount;
int *badlist;
int *badlen;
#endif
{
    int i,j;
    int ncount = G->nnodes;
    int ecount = G->nedges;
    edge *e;
    edge *edgelist = G->edgelist;
    node *nodelist = G->nodelist;
    int maxbad = G->nnodes * MAX_BAD_PORTION;

    /* init unused */
    j = 3*ncount/2;
    for (i = ncount; i < j; i++) {
        nodelist[i].mark = i + 1;
    }
    nodelist[j].mark = -1;
    G->unused = ncount;

    /* Init edg_list */
    for (i = 0; i < 3*ncount/2; i++) {
        nodelist[i].edg_list = -1;
    }

    /* correct old edges */
    for (i = 0, e = edgelist; i < ecount; i++, e++) {
	e->nod1 = e->orig_nod1;
	e->nod2 = e->orig_nod2;
        e->slack = 2 * CCutil_dat_edgelen (e->nod1, e->nod2, dat); 
    }

    if (badcount <= maxbad) {
        for (i = 0; i < badcount; i++) {
            if (ecount + 1 < G->max_nedges) {
	        edgelist[ecount].orig_nod1 =
                                 edgelist[ecount].nod1 = badlist[2*i];
	        edgelist[ecount].orig_nod2 =
                                 edgelist[ecount].nod2 = badlist[2*i+1];
	        edgelist[ecount].slack = 2 * badlen[i];
	        ecount++;
	    } else {
	        fprintf(stderr, "Exceeded limit on the number of edges\n");
                G->nedges = ecount;
                return 1;
	    }
        }
    } else {
        printf ("Using only %.2f of the bad edges\n",
                      ((double) maxbad) / ((double) badcount));
        fflush (stdout);
        for (i = 0; i < badcount; i++) {
            if (CCutil_lprand () % badcount < maxbad) {
                if (ecount + 1 < G->max_nedges) {
	            edgelist[ecount].orig_nod1 =
                                     edgelist[ecount].nod1 = badlist[2*i];
	            edgelist[ecount].orig_nod2 =
                                     edgelist[ecount].nod2 = badlist[2*i+1];
	            edgelist[ecount].slack = 2 * badlen[i];
	            ecount++;
	        } else {
	            fprintf(stderr, "Exceeded limit on the number of edges\n");
                    G->nedges = ecount;
                    return 1;
                }
	    }
        }
    }

    printf(" Added %i edges ", ecount - G->nedges);
    fflush (stdout);

    G->nedges = ecount;

    /* build the edg_lists */

    for (i = 0, e = edgelist; i < ecount; i++, e++) {
        e->ptrs[0] = nodelist[e->nod1].edg_list;
        nodelist[e->nod1].edg_list = 2*i;
        e->ptrs[1] = nodelist[e->nod2].edg_list;
        nodelist[e->nod2].edg_list = 2*i + 1;
    }
    for (i = 0; i < ncount; i++) {
        G->nodelist[i].mark = 0;
    }

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int price_repair (graph *G, int *finished, CCdatagroup *dat, stats *scount,
                         srkstuff *srk, int partialprice) 
#else
static int price_repair (G, finished, dat, scount, srk, partialprice) 
graph *G;
int *finished;
CCdatagroup *dat;
stats *scount;
srkstuff *srk;
int partialprice;
#endif
{
    int badcount = 0;
    int *badlist = (int *) NULL;
    int *badlen = (int *) NULL;
    int i;
    CCtsp_edgegenerator eg;
    CCtsp_edgegenerator *myeg = (CCtsp_edgegenerator *) NULL;

    *finished = 0;

    if (partialprice > 0) {
        printf ("Price using the nearest %d neighbor graph\n", partialprice);
        fflush (stdout);
        if (CCtsp_init_edgegenerator (&eg, G->nnodes, dat, (CCtsp_genadj *) NULL,
                                partialprice)) {
            fprintf (stderr, "init_edgegenerator failed\n");
            return 1;
        }
        myeg = &eg;
    }
    
    if (pricing (G, dat, scount, srk, &badcount, &badlist, &badlen, myeg, 0)) {
        fprintf (stderr, "pricing failed\n");
        if (myeg)
            CCtsp_free_edgegenerator (myeg);
        return 1;
    }
 
    while (badcount > 0) {
        if (badcount > G->nnodes / SWITCH_LEVEL /* 10000 */) {
            if (myeg)
                CCtsp_free_edgegenerator (myeg);
    	    if (add_edges (G, dat, badcount, badlist, badlen)) {
                fprintf (stderr, "add_edges failed\n");
                CC_IFFREE (badlist, int);
                CC_IFFREE (badlen, int);
                return 1;
            } else {
                CC_IFFREE (badlist, int);
                CC_IFFREE (badlen, int);
                return 0;
            }
        } else {
            for (i = 0; i < 3 * G->nnodes / 2; i++)
                G->nodelist[i].hit = 0; 
            if (run_repair (G, badcount, badlist, badlen, scount, srk)) {
                fprintf (stderr, "run_repair failed\n");
                CC_IFFREE (badlist, int);
                CC_IFFREE (badlen, int);
                if (myeg)
                    CCtsp_free_edgegenerator (myeg);
                return 1;
            }
        } 
        CC_IFFREE (badlist, int);
        CC_IFFREE (badlen, int);

        if (pricing(G,dat,scount,srk, &badcount, &badlist, &badlen, myeg, 1)) {
            fprintf (stderr, "pricing failed\n");
            if (myeg)
                CCtsp_free_edgegenerator (myeg);
            return 1;
        }
    }

    *finished = 1;
    if (myeg) 
        CCtsp_free_edgegenerator (myeg);

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int pricing (graph *G, CCdatagroup *dat, stats *scount, srkstuff *srk, 
                    int *badcount, int **badlist, int **badlen, 
                    CCtsp_edgegenerator *eg, int usehit) 
#else
static int pricing (G, dat, scount, srk, badcount, badlist, badlen, eg, usehit) 
graph *G;
CCdatagroup *dat;
stats *scount;
srkstuff *srk;
int *badcount;
int **badlist, **badlen;
CCtsp_edgegenerator *eg;
int usehit;
#endif
{
    int i, k;
    double szeit, penalty;
    double *orig_pi = (double *) NULL;
    int *orig_parent = (int *) NULL;
    int rval = 0;
    int ncount = G->nnodes;
    node *nodelist = G->nodelist;
    char *hit = (char *) NULL;

    szeit = CCutil_zeit();
    printf ("Pricing ...\n");
    fflush (stdout);

    orig_pi = CC_SAFE_MALLOC (ncount*3/2+1, double);
    orig_parent = CC_SAFE_MALLOC (ncount*3/2+1, int);
    if (!orig_pi || !orig_parent) {
        fprintf (stderr, "out of memory in pricing\n");
        rval = 1; goto CLEANUP;
    }

    if (usehit) {
        hit = CC_SAFE_MALLOC (ncount*3/2 + 1, char);
        if (!hit) {
            fprintf (stderr, "out of memory in pricing\n");
            rval = 1; goto CLEANUP;
        }
    }

    for (i = 0; i < 3*ncount/2; i++) {
        k = nodelist[i].blossom_parent;
	orig_parent[i] = k;
	orig_pi[i] = ((double) nodelist[i].pi) / 2.0;
        if (hit) {
            hit[i] = nodelist[i].hit;
        }
    }

    if (matching_price (ncount, dat, orig_pi, orig_parent, badcount,
                        badlist, badlen, &penalty, eg, hit) ) {
	fprintf (stderr, "matching_price failed\n");
        rval = 1; goto CLEANUP;
    }

    printf("\n%i Edges are wrong in the extra graph, penalty=%.4f\n",
           *badcount, penalty);

    printf ("    Total time in pricing: %.2f seconds\n", CCutil_zeit () - szeit);
    fflush(stdout);

CLEANUP:

    CC_IFFREE (orig_pi, double);
    CC_IFFREE (orig_parent, int);
    CC_IFFREE (hit, char);

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static int test_matching (graph *G, CCdatagroup *dat, int *elen, int fractional,
                          int *bad) 
#else
static int test_matching (G, dat, elen, fractional, bad) 
graph *G;
CCdatagroup *dat;
int *elen;
int fractional;
int *bad;
#endif
{
    int i, c, len;
    double a = 0.0, b = 0.0;
    edge *e;
    int ncount = G->nnodes;
    node *nodelist = G->nodelist;

    *bad = 0;

    if (dat) {
        if (fractional) {
            for (i = 0; i < G->nedges; i++) {
                e = G->edgelist + i;
                if (e->x == 1) {
                    a += (double) CCutil_dat_edgelen (e->orig_nod1, e->orig_nod2, dat);
                    a += (double) CCutil_dat_edgelen (e->orig_nod1, e->orig_nod2, dat);
                } else if (e->x == HALF) {
                    a += (double) CCutil_dat_edgelen (e->orig_nod1, e->orig_nod2, dat);
                }
	    }
            for (i = 0; i < ncount; i++)
	        b += (double) nodelist[i].pi;
        } else {
	    for (i = 0; i < ncount; i++) {
                e = nodelist[i].matched_edge + G->edgelist;
                a += (double) CCutil_dat_edgelen (e->orig_nod1, e->orig_nod2, dat);
            }
	    for (i = 0; i <= 3*ncount/2; i++)
	        b += (double) nodelist[i].pi;
        }
    } else {
        if (fractional) {
            for (i = 0; i < ncount; i++) {
                a += (double) elen[nodelist[i].matched_edge];
	        b += (double) nodelist[i].pi;
	    }
        } else {
	    for (i = 0; i < ncount; i++) {
                a += (double) elen[nodelist[i].matched_edge];
            }
	    for (i = 0; i <= 3*ncount/2; i++)
	        b += (double) nodelist[i].pi;
        }
    }
    b /= 2.0;
    a /= 2.0;
    printf("     Matching Length: %.1f, Dual %.1f\n", a, b);
    fflush (stdout);

    if (a != b) {
        printf ("ERROR: the primal and dual values do not agree\n");
        fflush (stdout);
        *bad = 1;
        return 0;
    } 

    if (fractional) {
	for (i = 0, e = G->edgelist; i < G->nedges; i++, e++) {
            if (dat) {
                len = 2 * CCutil_dat_edgelen (e->orig_nod1, e->orig_nod2, dat);
            } else {
                len = 2 * elen[i];
            }
	    if ((c = len - nodelist[e->nod1].pi-nodelist[e->nod2].pi) < 0) {
		printf("ERROR: Edge %i %i has slack < 0\n", e->nod1, e->nod2);
                fflush (stdout);
                *bad = 1;
                return 0;
	    }
	    if (e->x != 0 && c > 0) {
		printf("ERROR: Edge %i %i has x != 0 and slack > 0\n",
                     e->nod1, e->nod2);
                fflush (stdout);
                *bad = 1;
                return 0;
	    }
	}
    } else {
        int *mlist = (int *) NULL;
        int *mlen = (int *) NULL;
        double *pi = (double *) NULL;
        int *parent = (int *) NULL;
        int csbad, k;
        int *badlist = (int *) NULL;
        int *badlen = (int *) NULL;
        int badcount = 0;
        double penalty;
        
        mlist = CC_SAFE_MALLOC (ncount, int);
        mlen = CC_SAFE_MALLOC (ncount/2, int);
        pi = CC_SAFE_MALLOC (ncount*3/2+1, double);
        parent = CC_SAFE_MALLOC (ncount*3/2+1, int);
        if (!mlist || !mlen || !pi || !parent) {
            fprintf (stderr, "out of memory in test_matching\n");
            CC_IFFREE (mlist, int);
            CC_IFFREE (mlen, int);
            CC_IFFREE (pi, double);
            CC_IFFREE (parent, int);
            return 1;
        }

        for (i = 0, e = G->edgelist, k = 0; i < G->nedges; i++, e++) {
            if (e->x == 1) {
                mlist[2*k] = e->orig_nod1;
                mlist[2*k + 1] = e->orig_nod2;
                if (dat) {
                    mlen[k] = CCutil_dat_edgelen (e->orig_nod1, e->orig_nod2, dat);
                } else {
                    mlen[k] = elen[i];
                }
                k++;
            }
        }
        for (i = 0; i < 3*ncount/2; i++) {
            parent[i] = nodelist[i].blossom_parent;
            pi[i] = ((double) nodelist[i].pi) / 2.0;
        }

        if (matching_check (ncount, pi, parent, mlist, mlen, &csbad)) {
            fprintf (stderr, "matching_check failed\n");
            CC_FREE (mlist, int);
            CC_FREE (mlen, int);
            CC_FREE (pi, double);
            CC_FREE (parent, int);
            return 1;
        }

        if (csbad) {
            printf ("matching_check found an error\n");
            fflush (stdout);
            *bad = 1;
            CC_FREE (mlist, int);
            CC_FREE (mlen, int);
            CC_FREE (pi, double);
            CC_FREE (parent, int);
            return 0;
        }

        if (matching_price (ncount, dat, pi, parent, &badcount,
               &badlist, &badlen, &penalty, (CCtsp_edgegenerator *) NULL,
               (char *) NULL)) {
	    fprintf (stderr, "matching_price failed\n");
            CC_FREE (mlist, int);
            CC_FREE (mlen, int);
            CC_FREE (pi, double);
            CC_FREE (parent, int);
            return 1;
        }

        if (badcount) {
            printf ("pricing on complete graph found %d bad edges\n", badcount);
            fflush (stdout);
            *bad = 1;
            CC_IFFREE (badlist, int);
            CC_IFFREE (badlen, int);
            CC_FREE (mlist, int);
            CC_FREE (mlen, int);
            CC_FREE (pi, double);
            CC_FREE (parent, int);
            return 0;
        }

        CC_FREE (mlist, int);
        CC_FREE (mlen, int);
        CC_FREE (pi, double);
        CC_FREE (parent, int);
    }

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static void dual_match_len (graph *G, int fractional, double *val) 
#else
static void dual_match_len (G, fractional, val) 
graph *G;
int fractional;
double *val;
#endif
{
    int i;
    double b = 0.0;
    int ncount = G->nnodes;
    node *nodelist = G->nodelist;

    if (fractional) {
	for (i = 0; i < ncount; i++) {
	    b += (double) nodelist[i].pi;
	}
    } else {
	for (i = 0; i <= 3*ncount/2; i++)
	    b += (double) nodelist[i].pi;
    }
    *val = b / 2.0;
}

#ifdef CC_PROTOTYPE_ANSI
static int make_match (graph *G) 
#else
static int make_match (G) 
graph *G;
#endif
{
    int i, i2, j, k, start, counter=0;
    int ncount = G->nnodes;
    edge *e;
    node *nodelist = G->nodelist;
    edge *edgelist = G->edgelist;

    for (i = 0; i < ncount; i++) {
	if (nodelist[i].status == MATCHED)
	    counter++;
	if (nodelist[i].status == HALVES) {
	    k = 1;
	    start = i;
	    i2 = i;
            j = OTHEREND_INT (PEDGE(nodelist[i2].matched_edge), i2);
	    do {
                e = PEDGE(nodelist[j].matched_edge);
		if (k % 2) {
		    nodelist[i2].status = MATCHED;
		    nodelist[j].status = MATCHED;
		    edgelist[nodelist[j].matched_edge].x = 0;
		    nodelist[j].matched_edge = nodelist[i2].matched_edge;
		    edgelist[nodelist[j].matched_edge].x = 1;
		}
		i2 = j;
                j = OTHEREND_INT (e, i2);
		k++;
	    } while (j!=start);
	    nodelist[i2].status = UNMATCHED;
	    edgelist[nodelist[i2].matched_edge].x = 0;
	    nodelist[i2].matched_edge = -1;
	    counter++;
	}
	nodelist[i].label = NIX;
	nodelist[i].child = -1;
	nodelist[i].sibling = -1;
	nodelist[i].parent = -1;
	nodelist[i].parent_edge = -1;
	nodelist[i].mark = 0;
	nodelist[i].tree_root = -1;
    }

    counter=0;
    for (i = 0; i < ncount; i++)
	if (nodelist[i].status == MATCHED)
	    counter++;
    //    printf(" %i nodes are matched now !\n",counter);

    /* build list of unmatched nodes */

    G->unmatched_count = 0;
    for (i = 0; i < ncount; i++) {
	if (nodelist[i].status == UNMATCHED) {
	    G->unmatched_count++;
	}
    }

    j = -1;
    for (i = 0; i < ncount; i++) {
	if (nodelist[i].status == UNMATCHED) {
            if (j != -1) 
                nodelist[j].mark = i;
            j = i;
	}
    }
    if (j != -1)
        nodelist[j].mark = -1;


    if (G->unmatched_count == 0) {
        G->unmatched = -1;
    } else {
        for (i = 0; nodelist[i].status != UNMATCHED; i++);
        G->unmatched = i;
    }
    //    printf(" unmatched_count = %i\n", G->unmatched_count);
    //    fflush (stdout);

    /* hit is used to identify the blossoms that receive a label +  during */
    /* the matching run; this will help the pricing code                   */

    for (i = 0; i < 3 * ncount / 2; i++)  
        nodelist[i].hit = 0;

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int build_graph (graph *G, int ncount, int ecount, int *elist, int *elen)
#else
static int build_graph (G, ncount, ecount, elist, elen)
graph *G;
int ncount, ecount;
int *elist, *elen;
#endif
{
    int i, j;
    edge *e;

    if (ncount % 2 != 0) {
        fprintf (stderr, "problem has an odd number of nodes\n");
        return 1;
    }

    G->nnodes = ncount;
    G->nodelist = CC_SAFE_MALLOC ((3*ncount/2+1), node);
    if (!G->nodelist) {
        fprintf (stderr, "out of memory in build_graph\n");
        return 1;
    }
    for (i = 0; i < 3*ncount/2 + 1; i++) {
        G->nodelist[i].blossom_parent = -1;
        G->nodelist[i].matched_edge = -1;
        G->nodelist[i].edg_list = -1;
    }

    /* init unused */

    j = 3*ncount/2;
    for (i = ncount; i < j; i++) {
        G->nodelist[i].mark = i + 1;
    }
    G->nodelist[j].mark = -1;
    G->unused = ncount;

    G->nedges = ecount;
    G->max_nedges = ecount + (1.5 * ncount);

    G->edgelist = CC_SAFE_MALLOC (G->max_nedges, edge);
    if (!G->edgelist) {
        fprintf (stderr, "out of memory in build_graph\n");
        CC_FREE (G->nodelist, node);
        return 1;
    }

    for (i = 0; i < ncount; i++) {
        G->nodelist[i].mark = 0;
    }

    for (i = 0, e = G->edgelist; i < ecount; i++, e++) {
	e->nod1 = elist[2*i];
	e->nod2 = elist[2*i+1];
	e->orig_nod1 = e->nod1;
	e->orig_nod2 = e->nod2;
	e->slack =  2 * elen[i];  /* to work with ints */
        e->mark = 0;
        e->ptrs[0] = G->nodelist[e->nod1].edg_list;
        G->nodelist[e->nod1].edg_list = 2*i;
        e->ptrs[1] = G->nodelist[e->nod2].edg_list;
        G->nodelist[e->nod2].edg_list = 2*i + 1;
    }
    for (; i < G->max_nedges; i++)
        G->edgelist[i].mark = 0;

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int write_match (graph *G, CCdatagroup *dat, int *elen, char* fname, int *outp) 
#else
  static int write_match (G, dat, elen, fname, outp) 
graph *G;
CCdatagroup *dat;
int *elen;
char *fname;
int *outp;
#endif
{
    int i, c, len = 0;
    edge *e;
    FILE* fp;
    int KOUNT=0;
    double szeit;

    szeit = CCutil_zeit();
    //    printf(" Writing %s ...", fname);
    //    fflush(stdout);

    //    if ((fp = fopen (fname, "w")) ==  (FILE *) NULL) {
    //	fprintf(stderr," Error: Can't open file %s\n",fname);
    //        return 1;
    //    }

    c = 0;
    for (i = 0; i < G->nnodes; i++) {
	if (i == G->edgelist[G->nodelist[i].matched_edge].orig_nod2 ||
                 G->edgelist[G->nodelist[i].matched_edge].x == HALF) {
	    c++;
        }
    }
    //    printf(" %i nodes, %i edges ", G->nnodes, c);
    //    fprintf (fp, "%i %i\n", G->nnodes, c);
    outp[0] = c;

    for (i = 0; i < G->nnodes; i++) {
        e = PEDGE(G->nodelist[i].matched_edge);
	if (i == e->orig_nod2 || e->x == HALF) {
            if (dat)
                len = CCutil_dat_edgelen (e->orig_nod1, e->orig_nod2, dat);
            else
                len = elen[e - G->edgelist];
	    outp[1+3*KOUNT] = G->edgelist[G->nodelist[i].matched_edge].orig_nod1;
	    outp[1+3*KOUNT+1] = G->edgelist[G->nodelist[i].matched_edge].orig_nod2;
	    outp[1+3*KOUNT+2] = len;
	    KOUNT++;
	    //	    fprintf (fp,"%i %i %i\n",
	    //                     G->edgelist[G->nodelist[i].matched_edge].orig_nod1,
	    //                     G->edgelist[G->nodelist[i].matched_edge].orig_nod2, len);
        }
    }
    //    fclose(fp);

    //    printf(" ... in %.2f sec !! \n", CCutil_zeit () - szeit);
    //    fflush(stdout);

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int write_blossom_tree (graph *G, char* blossom_tree_file) 
#else
static int write_blossom_tree (G, blossom_tree_file) 
graph *G;
char *blossom_tree_file;
#endif
{
    int i,j;
    FILE *fp;
    double szeit;
    double t;

    szeit = CCutil_zeit();
    printf(" Writing %s ...",blossom_tree_file);
    fflush(stdout);

    if ((fp = fopen (blossom_tree_file, "w")) ==  (FILE *) NULL) {
	fprintf(stderr," cannot open file %s\n",blossom_tree_file);
        return 1;
    }

    for (i = 0; i < 3*G->nnodes/2; i++) {
	j = G->nodelist[i].blossom_parent;
        t = ((double) G->nodelist[i].pi) / 2.0;
	fwrite (&j, sizeof(int), 1, fp);
	fwrite (&t, sizeof(double), 1, fp);
    }
    fclose(fp);

    printf(" ... in %.2f sec !! \n", CCutil_zeit () - szeit);
    fflush(stdout);

    return 0;
}
