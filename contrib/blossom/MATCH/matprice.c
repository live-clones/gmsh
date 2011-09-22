/************************************************************************/
/*                                                                      */
/*         PRICING ROUTINE FOR WEIGHTED PERFECT MATCHING PROBLEMS       */
/*                                                                      */
/*  Written by:  D. Applegate, W. Cook, and A. Rohe                     */
/*  Date:  August 1, 1996                                               */
/*                                                                      */
/*                                                                      */
/* EXPORTED FUNCTION:                                                   */
/*   int matching_price (int ncount, CCdatagroup *dat,                  */
/*          double *orig_pi, int *orig_parent, int *badcount,           */
/*          int **badlist, int **badlen, double *penalty,               */
/*          edgegenerator *starteg, char *hit)                          */
/*     RETURNS the edges of negative reduced cost.                      */
/*         -ncount is the number of nodes in the graph                  */
/*         -dat is a pointer to the data used to generate edge lengths  */
/*         -orig_pi is an array giving the dual variables on the nodes  */
/*            and blossoms (the first ncount entries are the nodes)     */
/*         -orig_parent is an array giving the parents of the nodes and */
/*            and blossoms in the nesting structure created by the      */
/*            matching algorithm (the entry is -1 if there is no parent)*/
/*         -badcount will return the number of edges having negative    */
/*            reduced cost                                              */
/*         -badlist will return the negative edges in node node format  */
/*            (the space for badlist will be allocated by this routine) */
/*         -badlen will return the lengths of the negative edges        */
/*         -penalty will return the sum of the negative reduced costs   */
/*            cutcount)                                                 */
/*         -starteg is a pointer to an edgegenerator that has been      */
/*            initialized (this can be NULL, in which cas the pricing   */
/*            is over the complete graph)                               */
/*         -hit is array (of length 3*ncount/2) that marks the nodes    */
/*            that have been hit by a positive dual change during the   */
/*            course of the algorithm (it can be NULL)                  */
/*   int matching_check (int ncount, CCdatagroup *dat, int *matchlist,  */
/*          int *mlen, int *orig_parent, int *csbad)                    */
/*     CHECKS that the complementary slackness conditions hold.         */
/*         -variables are as above.                                     */
/*         -matchlist is an array of length ncount giving the edges     */
/*            in a perfect matching in end end format                   */
/*         -mlen is an array of lenght ncount/2 giving the lengths of   */
/*            the edges in the matching                                 */
/*         -csbad will return 1 if complementary slackness conditions   */
/*            are violated and 0 otherwise)                             */
/*                                                                      */
/*  NOTES:                                                              */
/*                                                                      */
/*    Returns 0 if it worked and 1 otherwise (for example, when one     */
/*    of the mallocs failed). The nodes in the graph should be named    */
/*    0 through #nodes - 1.                                             */
/*                                                                      */
/*    The arrays orig_pi and orig_parent are 3/2 ncount long (this      */
/*    is the maximum number of nodes + blossoms used in the blossom     */
/*    algorithms. Some of the entries will be wasted space. The real    */
/*    entries can be determined by following the parent pointers from   */
/*    the ncount nodes (the first ncount entries in the arrays).        */
/*                                                                      */
/*    If matchlist is not NULL, then the complementary slackness        */
/*    conditions will be checked for the matching and dual solution.    */
/*                                                                      */
/************************************************************************/

#include "concorde.h"
#include "match.h"

#define MAT_GEN_EPSILON  0.000001
#define MAT_GEN_INFINITY 1000000000000.0

typedef struct node {
    struct node       *parent;
    struct node       *child;
    struct node       *sibling;
    struct anc        *addset;
    struct anc        *evallist;
    double             pi;
    double             sum;
    int                prenum;
    int                mark;
    char               hit;
} node;

typedef struct anc {
    struct anc        *parent;
    struct anc        *next;
    struct node       *ancestor;
    struct node       *lca;
    int                rank;
} anc;

typedef struct tree {
    struct node       *nodelist;
    struct node       *root;
    int                ncount;
    int                realncount;
} tree;

typedef struct junk_param {
    struct tree       *T;
    struct node       *nodelist;
    CCdatagroup       *dat;
    int               *list;
    int               *len;
    int               *badlist;
    int               *badlen;
    int               *mark;
    double             penalty;
    int                nwant;
    int                ngot;  
    int                total;
    int                badcount;
    int                phase;
} junk_param;

#ifdef CC_PROTOTYPE_ANSI

static void
    number_tree (node *n, int *prenum, int depth, int *maxdepth),
    freetree (tree *T);
static char
    get_hit_work (node *n);
static int
    cs_matching (tree *T, int *mlist, int *mlen, int *bad),
    check_card (node *b, int *not_odd),
    match_kdtree_price (tree *T, CCdatagroup *dat, int *badcount,
       int **badlist, int **badlen, double *penalty),
    merge_edge_lists (int *totalcount, int **totallist, int **totallen,
       int ecount, int *elist, int *elen),
    buildtree (tree *T, int ncount, double *pi, int *parent, char *hit),
    junk_check (int n1, int n2, void *pass_param),
    ancestor_price (tree *T, int zero_rc, int ecount, int *elist,
       int *elen, int *badcount, int **badlist, int **badlen, double *penalty);
static double
    get_sum_work (node *n);
static anc
   *ancest_work (node *p),
   *find_anc (anc *x),
   *union_anc (anc *x, anc *y);

#else

static void
    number_tree (),
    freetree ();
static char
    get_hit_work (node *n);
static int
    cs_matching (),
    check_card (),
    match_kdtree_price (),
    merge_edge_lists (),
    buildtree (),
    junk_check (),
    ancestor_price ();
static double
    get_sum_work ();
static anc
   *ancest_work (),
   *find_anc (),
   *union_anc ();

#endif


#ifdef DEBUG_MATPRICE
#ifdef CC_PROTOTYPE_ANSI

static void
    price_list (tree *T, int ecount, int *elist, int *elen, int *nbad);
static double
    price_it (tree *T, int n1, int n2, int len);
static node
   *easy_lca (node *n1, node *n2);

#else

static void
    price_list ();
static double
    price_it ();
static node
   *easy_lca ();

#endif
#endif


#ifdef CC_PROTOTYPE_ANSI
int matching_price (int ncount, CCdatagroup *dat, double *orig_pi,
                    int *orig_parent, int *badcount, int **badlist,
                    int **badlen, double *penalty, CCtsp_edgegenerator *starteg,
                    char *hit)
#else
int matching_price (ncount, dat, orig_pi, orig_parent,
                    badcount, badlist, badlen, penalty, starteg, hit)
int ncount;
CCdatagroup *dat;
double *orig_pi;
int *orig_parent;
int *badcount;
int **badlen, **badlist;
double *penalty;
CCtsp_edgegenerator *starteg;
char *hit;
#endif
{
    tree T;
    CCtsp_edgegenerator eg;
    CCtsp_edgegenerator *myeg = (CCtsp_edgegenerator *) NULL;
    double *sums = (double *) NULL;
    int i;
    int ngot, finished;
    int *plist = (int *) NULL;
    int *plen = (int *) NULL;
    int nwant;
    int rval = 0;
    int rcount;
    int *rlist = (int *) NULL;
    int *rlen = (int *) NULL;
    double rpenalty = 0.0;
    int tcount = 0;
    int *tlist = (int *) NULL;
    int *tlen = (int *) NULL;
    int totalpot = 0;


    //    printf ("matching_price ....\n");fflush (stdout);
    *badcount = 0;
    *badlist = (int *) NULL;
    *badlen = (int *) NULL;
    *penalty = 0.0;

    if (buildtree (&T, ncount, orig_pi, orig_parent, hit)) {
      //        fprintf (stderr, "buildtree failed\n");
        return 1;
    }

    if ((dat->norm & CC_NORM_BITS) == CC_KD_NORM_TYPE && !starteg) {
      //        printf ("Use kd-tree pricing ....\n");
        fflush (stdout);

        if (match_kdtree_price (&T, dat, badcount, badlist, badlen, penalty)) {
	  //            fprintf (stderr, "match_kdtree_price failed\n");
            rval = 1;
            goto CLEANUP;
        }
    } else {
      //        printf ("Use general pricing ...\n");
        fflush (stdout);

        if (!starteg) {
            if (CCtsp_init_edgegenerator (&eg, ncount, dat, (CCtsp_genadj *) NULL,
                                CCtsp_PRICE_COMPLETE_GRAPH)) {
	      //                fprintf (stderr, "CCtsp_init_edgegenerator failed\n");
                freetree (&T);
                return 1;
            }
            myeg = &eg;
        } else {
            myeg = starteg;
        }

        sums = CC_SAFE_MALLOC (ncount, double);
        if (!sums) {
	  //            fprintf (stderr, "out of memory in matching_price\n");
            rval = 1;
            CCtsp_free_edgegenerator (&eg);
            goto CLEANUP;
        }
    
        for (i = 0; i < ncount; i++) {
            sums[i] = T.nodelist[i].sum;
        }

        if (CCtsp_reset_edgegenerator (myeg, sums)) {
	  //            fprintf (stderr, "CCtsp_reset_edgegenerator failed\n");
            rval = 1;
            if (!starteg)
                CCtsp_free_edgegenerator (&eg);
            goto CLEANUP;
        }

        nwant = 3 * ncount;

        plist = CC_SAFE_MALLOC (nwant * 2, int);
        plen = CC_SAFE_MALLOC (nwant, int);
        if (!plist || !plen) {
	  //            fprintf (stderr, "out of memory in matching_price\n");
            rval = 1;
            if (!starteg)
                CCtsp_free_edgegenerator (&eg);
            goto CLEANUP;
        }

        do {
            ngot = 0;
            finished = 0;
            if (CCtsp_generate_edges (myeg, nwant, &ngot, plist, plen, &finished)) {
	      //                fprintf (stderr, "generate_edges failed\n");
                rval = 1;
                if (!starteg)
                    CCtsp_free_edgegenerator (&eg);
                CC_IFFREE (tlist, int);
                CC_IFFREE (tlen, int);
                goto CLEANUP;
            }
        
	    //            printf ("Found %d potential edges\n", ngot);
	    //            printf ("Finished = %d\n", finished);
            fflush (stdout);
            totalpot += ngot;

            if (ancestor_price (&T, 0, ngot, plist, plen, &rcount, &rlist,
                                &rlen, &rpenalty)) {
	      //                fprintf (stderr, "ancestor_price failed\n");
                rval = 1;
                CC_IFFREE (tlist, int);
                CC_IFFREE (tlen, int);
                if (!starteg)
                    CCtsp_free_edgegenerator (&eg);
                goto CLEANUP;
            }
       
            if (rcount) {
                *badcount += rcount;
                *penalty += rpenalty;

                if (merge_edge_lists (&tcount, &tlist, &tlen,
                                       rcount,  rlist,  rlen)) {
		  //                    fprintf (stderr, "merge_edge_lists failed\n");
                    rval = 1;
                    CC_IFFREE (tlist, int);
                    CC_IFFREE (tlen, int);
                    if (!starteg)
                        CCtsp_free_edgegenerator (&eg);
                    goto CLEANUP;
                }

                CC_IFFREE (rlist, int);
                CC_IFFREE (rlen, int);
            }
        } while (!finished);

	//        printf ("Total potential edges: %d\n", totalpot);
        fflush (stdout);

        if (badcount) {
            *badlist = tlist;
            *badlen = tlen;
        }

        if (!starteg)
            CCtsp_free_edgegenerator (&eg);
    }

CLEANUP:

    CC_IFFREE (plist, int);
    CC_IFFREE (plen, int);
    CC_IFFREE (rlist, int);
    CC_IFFREE (rlen, int);
    CC_IFFREE (sums, double);
    freetree (&T);

    return rval;
}


#ifdef CC_PROTOTYPE_ANSI
int matching_check (int ncount, double *orig_pi, int *orig_parent,
                    int *matchlist, int *mlen, int *csbad)
#else
int matching_check (ncount, orig_pi, orig_parent, matchlist, mlen, csbad)
int ncount;
double *orig_pi;
int *orig_parent;
int *matchlist;
int *mlen;
int *csbad;
#endif
{
    tree T;
    double szeit = CCutil_zeit ();

    *csbad = 0;
    if (buildtree (&T, ncount, orig_pi, orig_parent, (char *) NULL)) {
        fprintf (stderr, "buildtree failed\n");
        return 1;
    }

    printf ("Check complementary slackness conditions ....\n");
    fflush (stdout);
    if (cs_matching (&T, matchlist, mlen, csbad)) {
        fprintf (stderr, "cs_matching failed\n");
        freetree (&T);
        return 1;
    }
    if (*csbad) {
        printf ("\nWARNING: complementary slackness NOT satisfied\n\n");
        fflush (stdout);
    } else {
        printf ("Complementary slackness satisfied (%.2f seconds)\n\n", 
                CCutil_zeit () - szeit);
        fflush (stdout);
    }

    freetree (&T);
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int cs_matching (tree *T, int *mlist, int *mlen, int *bad)
#else
static int cs_matching (T, mlist, mlen, bad)
tree *T;
int *mlist, *mlen;
int *bad;
#endif
{
    int ncount = T->realncount;
    node *nodelist = T->nodelist;
    int i, k, not_odd = 0;
    int bcount = 0;
    int *blist = (int *) NULL;
    int *blen = (int *) NULL;
    char *mark = (char *) NULL;
    double t, penalty = 0.0;
    node *b, *n, *n1, *n2;
    int local_magic = 0;

    *bad = 0;

    mark = CC_SAFE_MALLOC (ncount, char);
    if (!mark) {
        fprintf (stderr, "out of memory in cs_matching\n");
        return 1;
    }
    for (i = 0; i < ncount; i++)
        mark[i] = 0;
    for (i = 0; i < ncount; i++) {
        if (mark[mlist[i]]) {
            printf ("node %d meets two edges in matching\n", mlist[i]);
            fflush (stdout);
            *bad = 1;
            goto CLEANUP;
        } else {
            mark[mlist[i]] = 1;
        }
    }
    printf ("All nodes meet exactly one matching edge\n");
    fflush (stdout);

    t = 0.0;
    for (i = 0; i < ncount/2; i++) {
        t += (double) mlen[i];
    }
    printf ("Length of matching: %.2f\n", t);
    fflush (stdout);

    if (ancestor_price (T, 1, ncount / 2, mlist, mlen, &bcount, &blist,
                        &blen,  &penalty)) {
        fprintf (stderr, "ancestor_price failed\n");
        return 1;
    }
    CC_IFFREE (blist, int);
    CC_IFFREE (blen, int);

    if (bcount > 0) {
        printf ("%d matching edges at nonzero reduced cost (%f sum)\n",
                   bcount, penalty);
        fflush (stdout);
        *bad = 1;
        goto CLEANUP;
    } else {
        printf ("All matching edges have zero reduced cost\n");
        fflush (stdout);
    }

    for (b = T->root->child; b; b = b->sibling) 
        check_card (b, &not_odd);
    if (not_odd) {
        printf ("%d blossoms do not have odd cardinality\n", not_odd);
        fflush (stdout);
        *bad = 1;
        goto CLEANUP;
    } else {
        printf ("All blossoms have odd cardinality\n");
        fflush (stdout);
    }

    for (i = 0; i < T->ncount; i++) {
        nodelist[i].mark = 0;
        nodelist[i].prenum = 0;
    }
    for (i = 0; i < ncount/2; i++) {
        n1 = nodelist + mlist[2*i];
        n2 = nodelist + mlist[2*i+1];
        local_magic++;

        n = n1;
        do {
            n->mark = local_magic;
            n = n->parent;
        } while (n);

        do {
            n2->prenum++;
            n2 = n2->parent;
        } while (n2->mark != local_magic);

        do {
            n1->prenum++;
            n1 = n1->parent;
        } while (n1 != n2);
    }
    for (i = 0; i < T->ncount; i++) 
        nodelist[i].mark = 0;

    k = 0;
    for (i = T->realncount; i < T->ncount; i++) {
        if (nodelist[i].prenum != 1 && nodelist + i != T->root)
            k++;
    }
    if (k) {
        printf ("%d blossoms do not contain exactly one matching edge\n", k);
        fflush (stdout);
        *bad = 1;
        goto CLEANUP;
    } else {
        printf ("All blossoms meet exactly one matching edge\n");
        fflush (stdout);
    }



CLEANUP:

    CC_IFFREE (mark, char);
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int check_card (node *b, int *not_odd)
#else
static int check_card (b, not_odd)
node *b;
int *not_odd;
#endif
{
    if (b->child) {
        int card = 0;
        node *c;
   
        for (c = b->child; c; c = c->sibling) {
            card += check_card (c, not_odd);
        }
        if (card % 2 == 0) 
            (*not_odd)++;
        return card;
    } else {
        return 1;
    }
}


#define PULLIT     20

#ifdef CC_PROTOTYPE_ANSI
static int match_kdtree_price (tree *T, CCdatagroup *dat, int *badcount,
            int **badlist, int **badlen, double *penalty)
#else
static int match_kdtree_price (T, dat, badcount, badlist, badlen, penalty)
tree *T;
CCdatagroup *dat;
int *badcount;
int **badlist, **badlen;
double *penalty;
#endif
{
    double smax = - MAT_GEN_INFINITY;
    int i, j;
    node *nodelist = T->nodelist;
    int ncount = T->realncount;
    double *wcoord = (double *) NULL;
    double szeit = CCutil_zeit ();
    double dist;
    CCkdtree kt;
    junk_param p;
    int *list = (int *) NULL;
    int *len = (int *) NULL;
    int *perm = (int *) NULL;
    int newtop, newbottom;
    int rval = 0;

    {
        double mins = nodelist[0].sum;
        double maxs = nodelist[0].sum;
        double *sum = (double *) NULL;

        sum = CC_SAFE_MALLOC (ncount, double);
        perm = CC_SAFE_MALLOC (ncount, int);
        if (!sum || !perm) {
            fprintf (stderr, "out of memory in match_kdtree_price\n");
            CC_IFFREE (sum, double);
            rval = 1;
            goto CLEANUP;
        }
        for (i = 0; i < ncount; i++) {
            sum[i] = nodelist[i].sum;
            perm[i] = i;
        }

        for (i = 0; i < ncount; i++) {
            if (sum[i] > maxs)
                maxs = sum[i];
            if (sum[i] < mins)
                mins = sum[i];
        }
        printf ("Spread: (%f, %f)\n", mins, maxs);
        fflush (stdout);

        CCutil_double_perm_quicksort (perm, sum, ncount);

        newtop = ncount - ncount/PULLIT;
        newbottom = ncount/PULLIT;

        printf ("Remove %d nodes to get spead of (%f, %f)\n",
          2 * (ncount / PULLIT), sum[perm[newbottom]], sum[perm[newtop - 1]]);
        fflush (stdout);

        CC_IFFREE (sum, double);
    }

    *badcount = 0;
    *badlist = (int *) NULL;
    *badlen = (int *) NULL;
    *penalty = 0.0;

    p.T = T;
    p.dat = dat;
    p.nodelist = nodelist;
    p.nwant = 3 * ncount;
    p.ngot = 0;
    p.total = 0;
    p.penalty = 0.0;

    list = CC_SAFE_MALLOC (2 * p.nwant, int);
    len = CC_SAFE_MALLOC (p.nwant, int);
    p.mark = CC_SAFE_MALLOC (ncount, int);

    if (!list || !len || !p.mark) {
        fprintf (stderr, "out of memory in match_kdtree_price\n");
        rval = 1;
        goto CLEANUP;
    }

    p.list = list;
    p.len = len;
    p.badcount = 0;
    p.badlist = (int *) NULL;
    p.badlen = (int *) NULL;

    for (i = 0; i < ncount; i++)
        p.mark[i] = 0;

    wcoord = CC_SAFE_MALLOC (ncount, double);
    if (!wcoord) {
        fprintf (stderr, "out of memory in match_kdtree_price\n");
        rval = 1;
        goto CLEANUP;
    }

    for (i = 0; i < ncount; i++)
        wcoord[i] = 0.0;
    for (j = newbottom; j < newtop; j++) {
        i = perm[j];
        if (nodelist[i].sum > smax)
            smax = nodelist[i].sum; 
    }
    for (j = newbottom; j < newtop; j++) {
        i = perm[j];
        wcoord[i] = smax - nodelist[i].sum;
    }

    dist = 2 * smax - MAT_GEN_EPSILON; 

    printf ("Build the kdtree ...\n"); fflush (stdout);

    if (CCkdtree_build (&kt, ncount, dat, wcoord)) {
        fprintf (stderr, "CCkdtree_build failed\n");
        rval = 1;
        goto CLEANUP;
    }

    p.phase = 0;
    for (i = 0; i < newbottom; i++)
        CCkdtree_delete (&kt, perm[i]);
    for (i = ncount - 1; i >= newtop; i--)
        CCkdtree_delete (&kt, perm[i]);
    for (j = newbottom; j < newtop; j++) {
        i = perm[j];
        if (nodelist[i].hit) {
            if (CCkdtree_fixed_radius_nearest (&kt, dat, wcoord, i, dist, 
                             junk_check, (void *) (&p))) {
                fprintf (stderr, "CCkdtree_fixed_radius_nearest failed\n");
                CCkdtree_free (&kt);
                CC_IFFREE (p.badlist, int);
                CC_IFFREE (p.badlen, int);
                rval = 1;
                goto CLEANUP;
            }
        }
        if (j % 100000 == 99999) {
            printf ("Processed %d nodes\n", j + 1);
            fflush (stdout);
        }
    }
    CCkdtree_free (&kt);

    printf ("Processing the deleted nodes ....\n");
    fflush (stdout);

    smax = - MAT_GEN_INFINITY;
    for (i = 0; i < ncount; i++) {
        if (nodelist[i].sum > smax)
            smax = nodelist[i].sum; 
    }
    for (i = 0; i < ncount; i++) {
        wcoord[i] = smax - nodelist[i].sum;
    }

    dist = 2 * smax - MAT_GEN_EPSILON; 

    if (CCkdtree_build (&kt, ncount, dat, wcoord)) {
        fprintf (stderr, "CCkdtree_build failed\n");
        rval = 1;
        goto CLEANUP;
    }

    for (i = 0; i < newbottom; i++)
        p.mark[perm[i]] = 1;
    p.phase = 1;

    for (j = 0;  j < newbottom; j++) {
        i = perm[j];
        if (CCkdtree_fixed_radius_nearest (&kt, dat, wcoord, i, dist, 
                         junk_check, (void *) (&p))) {
            fprintf (stderr, "CCkdtree_fixed_radius_nearest failed\n");
            CCkdtree_free (&kt);
            CC_IFFREE (p.badlist, int);
            CC_IFFREE (p.badlen, int);
            rval = 1;
            goto CLEANUP;
        }
        if (j % 1000 == 999) {
            printf ("+");
            fflush (stdout);
        }
    }

    printf ("\nNow the top nodes ....\n");
    fflush (stdout);

    for (i = ncount - 1; i >= newtop; i--)
        p.mark[perm[i]] = 2;
    p.phase = 2;

    for (j = ncount - 1; j >= newtop; j--) {
        i = perm[j];
        if (CCkdtree_fixed_radius_nearest (&kt, dat, wcoord, i, dist, 
                         junk_check, (void *) (&p))) {
            fprintf (stderr, "CCkdtree_fixed_radius_nearest failed\n");
            CCkdtree_free (&kt);
            CC_IFFREE (p.badlist, int);
            CC_IFFREE (p.badlen, int);
            rval = 1;
            goto CLEANUP;
        }
        if (j % 1000 == 999) {
            printf ("-");
            fflush (stdout);
        }
    }
    CCkdtree_free (&kt);
    printf ("\n");
    fflush (stdout);

    if (p.ngot) {
        int *rlist = (int *) NULL;
        int *rlen = (int *) NULL;
        int rcount = 0;
        double rpenalty = 0.0;

        if (ancestor_price (p.T, 0, p.ngot, p.list, p.len, &rcount, &rlist,
                                &rlen, &rpenalty)) {
            fprintf (stderr, "ancestor_price failed\n");
            rval = 1;
            goto CLEANUP;
        }

        if (rcount) {
            p.penalty += rpenalty;
            if (merge_edge_lists (&(p.badcount), &(p.badlist), &(p.badlen),
                                       rcount, rlist, rlen)) {
                fprintf (stderr, "merge_edge_lists failed\n");
                CC_IFFREE (rlist, int);
                CC_IFFREE (rlen, int);
                CC_IFFREE (p.badlist, int);
                CC_IFFREE (p.badlen, int);
                rval = 1;
                goto CLEANUP;
            }
            CC_IFFREE (rlist, int);
            CC_IFFREE (rlen, int);
        }
    }

    printf ("Kdtree price time: %.2f seconds\n", CCutil_zeit () - szeit);
    printf ("Total number of potential edges: %d\n", p.total);
    fflush (stdout);

    *badcount = p.badcount;
    *badlist = p.badlist;
    *badlen = p.badlen;
    *penalty = p.penalty;

CLEANUP:

    CC_IFFREE (wcoord, double);
    CC_IFFREE (list, int);
    CC_IFFREE (len, int);
    CC_IFFREE (p.mark, int);
    CC_IFFREE (perm, int);

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static int junk_check (int n1, int n2, void *pass_param)
#else
static int junk_check (n1, n2, pass_param)
int n1, n2;
void *pass_param;
#endif
{
    junk_param *p = (junk_param *) pass_param;
    double t;
    int l;

    if ((!p->nodelist[n2].hit) ||
        (p->phase == 0 && n1 < n2) ||
        (p->phase == 1 && (n1 < n2 || !p->mark[n2])) ||
        (p->phase == 2 && (!p->mark[n2] || (p->mark[n2] == 2 && n1 < n2)))) { 
        l = CCutil_dat_edgelen (n1, n2, p->dat);
        t = ((double) l) - p->nodelist[n1].sum - p->nodelist[n2].sum;
        if (t > -MAT_GEN_EPSILON) {
            printf ("What the hey: %f\n", t);
            fflush (stdout);
        }
        p->total++;
        p->len[p->ngot] = l;
        p->list[2 * p->ngot] = n1;
        p->list[2 * p->ngot + 1] = n2;
        p->ngot++;

        if (p->ngot == p->nwant) {
            int *rlist = (int *) NULL;
            int *rlen = (int *) NULL;
            int rcount = 0;
            double rpenalty = 0.0;

            if (ancestor_price (p->T, 0, p->ngot, p->list, p->len,
                      &rcount, &rlist, &rlen, &rpenalty)) {
                fprintf (stderr, "ancestor_price failed\n");
                return 1;
            }

            if (rcount) {
                p->penalty += rpenalty;
                if (merge_edge_lists (&(p->badcount), &(p->badlist),
                             &(p->badlen), rcount,  rlist,  rlen)) {
                    fprintf (stderr, "merge_edge_lists failed\n");
                    CC_IFFREE (rlist, int);
                    CC_IFFREE (rlen, int);
                    return 1;
                }
                CC_IFFREE (rlist, int);
                CC_IFFREE (rlen, int);
            }
            p->ngot = 0;
        }
    }
    
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int merge_edge_lists (int *totalcount, int **totallist, int **totallen,
            int ecount, int *elist, int *elen)
#else
static int merge_edge_lists (totalcount, totallist, totallen, ecount, elist,
            elen)
int *totalcount;
int **totallist, **totallen;
int ecount;
int *elist, *elen;
#endif
{
    int *nlist = (int *) NULL;
    int *nlen = (int *) NULL;
    int ncount = *totalcount + ecount;
    int i, k;

    if (!ecount)
        return 0;

    nlist = CC_SAFE_MALLOC (2 * ncount, int);
    nlen = CC_SAFE_MALLOC (ncount, int);
    if (!nlist || !nlen) {
        fprintf (stderr, "out of memory in merge_edge_lists\n");
        CC_IFFREE (nlist, int);
        CC_IFFREE (nlen, int);
        return 1;
    }

    for (i = 0; i < *totalcount; i++) {
        nlist[2 * i] = (*totallist)[2 * i];
        nlist[2 * i + 1] = (*totallist)[2 * i + 1];
        nlen[i] = (*totallen)[i];
    }
    for (k = 0; k < ecount; k++, i++) {
        nlist[2 * i] = elist[2 * k];
        nlist[2 * i + 1] = elist[2 * k + 1];
        nlen[i] = elen[k];
    }

    if (*totalcount) {
        CC_IFFREE (*totallist, int);
        CC_IFFREE (*totallen, int);
    }

    *totalcount = ncount;
    *totallist = nlist;
    *totallen = nlen;

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int buildtree (tree *T, int ncount, double *pi, int *parent, char *hit)
#else
static int buildtree (T, ncount, pi, parent, hit)
tree *T;
int ncount;
double *pi;
int *parent;
char *hit;
#endif
{
    int bcount = 3 * ncount/2;
    int *mark = (int *) NULL;
    int *invnames = (int *) NULL;
    int i, j, k;
    int count = 0;
    node *nodelist;
    
    T->ncount = 0;
    T->realncount = 0;
    T->nodelist = (node *) NULL;

    mark = CC_SAFE_MALLOC (bcount, int);
    if (!mark) {
        fprintf (stderr, "out of memory in buildtree\n");
        return 1;
    }

    for (i = 0; i < bcount; i++)
        mark[i] = 0;

    for (i = 0; i < ncount; i++) {
        j = i;
        while (j != -1 && mark[j] == 0) {
            mark[j] = 1;
            j = parent[j];
        }
    }
    for (i = 0; i < bcount; i++)
        if (mark[i])
            count++;

    printf ("%d tree nodes\n", count);
    fflush (stdout);


    T->nodelist = CC_SAFE_MALLOC (count + 1, node);
    if (!T->nodelist) {
        fprintf (stderr, "out of memory in buildtree\n");
        CC_IFFREE (mark, int);
        return 1;
    }
    T->ncount = count;
    T->realncount = ncount;
    T->root = T->nodelist + count;
    T->root->parent = (node *) NULL;
    T->root->child = (node *) NULL;
    T->root->sibling = (node *) NULL;
    T->root->pi = 0.0;
    T->root->hit = 0;
    nodelist = T->nodelist;

    invnames = CC_SAFE_MALLOC (bcount, int);
    if (!invnames) {
        fprintf (stderr, "out of memory in buildtree\n");
        CC_IFFREE (mark, int);
        freetree (T);
        return 1;
    }

    for (k = 0, i = 0; i < bcount; i++)
        if (mark[i]) 
            invnames[i] = k++;

    for (k = 0, i = 0; i < bcount; i++) {
        if (mark[i]) {
            if (parent[i] == -1) {
                nodelist[k].parent = T->root;
            } else {
                nodelist[k].parent = nodelist + invnames[parent[i]];
            }
            nodelist[k].child = (node *) NULL;
            nodelist[k].sibling = (node *) NULL;
            nodelist[k].pi = pi[i];
            if (hit) {
                nodelist[k].hit = hit[i];
            } else {
                nodelist[k].hit = 1;
            }
            k++;
        }
    }

    for (i = 0; i < count; i++) {
        if (nodelist[i].parent->child == (node *) NULL) {
            nodelist[i].parent->child = nodelist + i;
        } else {
            nodelist[i].sibling = nodelist[i].parent->child->sibling;
            nodelist[i].parent->child->sibling = nodelist + i;
        }
    }

    T->root->sum = 0.0;
    for (i = 0; i <= count; i++)
        nodelist[i].mark = 0;
    for (i = 0; i < ncount; i++)
        get_sum_work (nodelist + i);
    for (i = 0; i <= count; i++)
        nodelist[i].mark = 0;
    if (hit) {
        int hcount = 0;
        for (i = 0; i < ncount; i++) {
            get_hit_work (nodelist + i);
            if (nodelist[i].hit)
                hcount++;
        }
        printf ("%d nodes must be checked\n", hcount);
        for (i = 0; i <= count; i++)
            nodelist[i].mark = 0;
    } else {
        for (i = 0; i < ncount; i++)
            nodelist[i].hit = 1;
    }

    {
        double minsum =  1000000000000.0;
        double maxsum = -1000000000000.0;
        for (i = 0; i < count; i++) {
            if (nodelist[i].sum < minsum)
                minsum = nodelist[i].sum;
            if (nodelist[i].sum > maxsum)
                maxsum = nodelist[i].sum;
        }
        printf ("Range of sums: %f  to %f\n", minsum, maxsum);
        fflush (stdout);
    }

    
 
    CC_IFFREE (invnames, int);
    CC_IFFREE (mark, int);

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static double get_sum_work (node *n)
#else
static double get_sum_work (n)
node *n;
#endif
{
    if (!n)
        return 0.0;

    if (n->mark)
        return n->sum;
    else {
        n->mark = 1;
        n->sum = n->pi + get_sum_work (n->parent);
        return n->sum;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static char get_hit_work (node *n)
#else
static char get_hit_work (n)
node *n;
#endif
{
    if (!n)
        return 0;

    if (n->mark || n->hit)
        return n->hit;
    else {
        n->mark = 1;
        n->hit = get_hit_work (n->parent);
        return n->hit;
    }
}


#ifdef DEBUG_MATPRICE
#ifdef CC_PROTOTYPE_ANSI
static void price_list (tree *T, int ecount, int *elist, int *elen, int *nbad)
#else
static void price_list (T, ecount, elist, elen, nbad)
tree *T;
int ecount;
int *elist, *elen;
int *nbad;
#endif
{
    int i;
    double t;
    FILE *out = fopen ("dump.edges", "w");
    double szeit = CCutil_zeit ();

    if (!out) {
        fprintf (stderr, "couldn't open dump.edges\n");
        exit (1);
    }

    *nbad = 0;

    for (i = 0; i < ecount; i++) {
        if (i % 10000 == 0) {
            printf ("T[%d](%.0f sec)  ", i / 10000, CCutil_zeit () - szeit);
            fflush (stdout);
        }
        t = price_it (T, elist[2 * i], elist[2 * i + 1], elen[i]);
        if (t < -MAT_GEN_EPSILON) {
            (*nbad)++;
            fprintf (out, "%d %d %d\n", elist[2 * i], elist[2 * i + 1],
                                        elen[i]);
        }
    }
    printf ("Found %d bad edges [%.2f seconds]\n", *nbad, CCutil_zeit () - szeit);
    fflush (stdout);
    fclose (out);
}

#ifdef CC_PROTOTYPE_ANSI
static double price_it (tree *T, int n1, int n2, int len)
#else
static double price_it (T, n1, n2, len)
int n1, n2, len;
tree *T;
#endif
{
    node *lca;
    node *m1 = T->nodelist + n1;
    node *m2 = T->nodelist + n2;

    lca = easy_lca (m1, m2);
    return ((double) len) - m1->sum - m2->sum + (2 * lca->sum);
}

#ifdef CC_PROTOTYPE_ANSI
static node *easy_lca (node *n1, node *n2)
#else
static node *easy_lca (n1, n2)
#endif
{
    node *n, *a;
    for (n = n1; n; n = n->parent)
        n->mark = 1;
    for (n = n2; n; n = n->parent)
        if (n->mark) {
            a = n;
            break;
        }
    for (n = n1; n; n = n->parent)
        n->mark = 0;

    return a;
}
#endif

#ifdef CC_PROTOTYPE_ANSI
static void freetree (tree *T)
#else
static void freetree (T)
tree *T;
#endif
{
    CC_IFFREE (T->nodelist, node);
    T->ncount = 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int ancestor_price (tree *T, int zero_rc, int ecount, int *elist,
        int *elen, int *badcount, int **badlist, int **badlen, double *penalty)
#else
static int ancestor_price (T, zero_rc, ecount, elist, elen, badcount, badlist,
        badlen, penalty)
tree *T;
int zero_rc;
int ecount;
int *elist, *elen;
int *badcount;
int **badlist, **badlen;
double *penalty;
#endif
{
    int prenum = 0;
    int i, nbad;
    anc *anclist = (anc *) NULL;
    anc *p;
    node *n1, *n2, *t;
    node *nodelist = T->nodelist;
    int maxdepth = 0;
    double szeit = CCutil_zeit ();
    double w;

    printf ("ancstor_price(%d) ....\n", ecount);
    fflush (stdout);

    *badcount = 0;
    *badlist = (int *) NULL;
    *badlen = (int *) NULL;
    *penalty = 0.0;

    number_tree (T->root, &prenum, 0, &maxdepth);
/*
    printf ("Maximum Depth of Tree: %d\n", maxdepth);
    fflush (stdout); 
*/
    if (prenum != T->ncount + 1) {
        printf ("Yipes in ancest_init\n");
        fflush (stdout);
    }

    anclist = CC_SAFE_MALLOC (ecount, anc);
    if (!anclist) {
        fprintf (stderr, "out of memory in ancestor_price\n");
        return 1;
    }

    for (i = 0; i < ecount; i++) {
        n1 = nodelist + elist[2 * i];
        n2 = nodelist + elist[2 * i + 1]; 

        if (n1->prenum > n2->prenum) {
            CC_SWAP(n1, n2, t);
        }

        p = anclist + i;

        p->next = n2->evallist;
        n2->evallist = p;
        if (n1->addset) {
            p->ancestor = (node *) NULL;
	    n1->addset->rank = 1;
	    p->rank = 0;
	    p->parent = n1->addset; 
        } else {
	    p->ancestor = n1;
	    p->rank = 0;
	    n1->addset = p;
	    p->parent = p;
        }
    }
    ancest_work (T->root);

    *penalty = 0.0;
    nbad = 0;
 
    if (zero_rc) {
        for (i = 0; i < ecount; i++) {
            n1 = nodelist + elist[2 * i];
            n2 = nodelist + elist[2 * i + 1]; 

            w = ((double) elen[i]) - n1->sum - n2->sum +
                                            (2 * anclist[i].lca->sum);
            if (w != 0.0) {
                printf ("edge (%d,%d) with rc %f\n",
                                 elist[2 * i], elist[2*i+1], w);
                fflush (stdout);
                (*penalty) += w;
                nbad++;
                anclist[i].rank = 1;
            } else {
                anclist[i].rank = 0;
            }
        }
    } else {
        for (i = 0; i < ecount; i++) {
            n1 = nodelist + elist[2 * i];
            n2 = nodelist + elist[2 * i + 1]; 

            w = ((double) elen[i]) - n1->sum - n2->sum +
                                            (2 * anclist[i].lca->sum);
            if (w < -MAT_GEN_EPSILON) {
                (*penalty) += w;
                nbad++;
                anclist[i].rank = 1;
            } else {
                anclist[i].rank = 0;
            }
        }
    }

    printf ("Number of bad edges: %d  (penalty = %f)\n", nbad, *penalty);
    fflush (stdout);

    if (nbad > 0) {
        *badlist = CC_SAFE_MALLOC (2 * nbad, int);
        *badlen = CC_SAFE_MALLOC (nbad, int);
        if (!(*badlist) || !(*badlen)) {
            fprintf (stderr, "out of memory in ancestor_price\n");
            CC_IFFREE (*badlist, int);
            CC_IFFREE (*badlen, int);
            CC_IFFREE (anclist, anc);
            return 0;
        }
        nbad = 0;
        for (i = 0; i < ecount; i++) {
            if (anclist[i].rank) {
                (*badlist)[2 * nbad] = elist[2 * i];
                (*badlist)[2 * nbad + 1] = elist[2 * i + 1];
                (*badlen)[nbad] = elen[i];
                nbad++;
            }
        }
        *badcount = nbad;
    }
           
    printf ("Ancestor Time: %.2f seconds\n", CCutil_zeit () - szeit);
    fflush (stdout);

    CC_IFFREE (anclist, anc);
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static anc *ancest_work (node *p)
#else
static anc *ancest_work (p)
node *p;
#endif
{
    node *q;
    anc *a;

    for (q = p->child; q; q = q->sibling) {
	a = ancest_work (q);
	if (a) {
	    if (p->addset) {
		p->addset = union_anc (a, p->addset);
	    } else {
		p->addset = a;
	    }
	    p->addset->ancestor = p;
	}
    }

    for (a = p->evallist; a; a = a->next) {
	a->lca = find_anc(a)->ancestor;
    }

    return p->addset;
}

#ifdef CC_PROTOTYPE_ANSI
static void number_tree (node *n, int *prenum, int depth, int *maxdepth)
#else
static void number_tree (n, prenum, depth, maxdepth)
node *n;
int *prenum;
int depth;
int *maxdepth;
#endif
{
    if (depth > *maxdepth)
        *maxdepth = depth;
    n->prenum = (*prenum)++;
    n->addset = (anc *) NULL;
    n->evallist = (anc *) NULL;
    for (n = n->child; n; n = n->sibling) {
	number_tree (n, prenum, depth + 1, maxdepth);
    }
}

#ifdef CC_PROTOTYPE_ANSI
static anc *find_anc (anc *x)
#else
static anc *find_anc (x)
anc *x;
#endif
{
    anc *p = x->parent;
    return (x == p) ? x : (x->parent = find_anc (p));
}

#ifdef CC_PROTOTYPE_ANSI
static anc *union_anc (anc *x, anc *y)
#else
static anc *union_anc (x, y)
anc *x;
anc *y;
#endif
{
    anc *t;

    if (x->rank > y->rank) {
	CC_SWAP (x, y, t);
    } else if (x->rank == y->rank) {
	y->rank++;
    }
    x->parent = y;
    return y;
}

