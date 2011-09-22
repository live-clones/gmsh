/***************************************************************************/
/*                                                                         */
/*                  STORING AND SEARCHING THE CUTPOOL                      */
/*                                                                         */
/*                            TSP CODE                                     */
/*                                                                         */
/*                                                                         */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook                       */
/*  Date: March 19, 1997                                                   */
/*        May 27, 1997 (bico)                                              */
/*                                                                         */
/*  EXPORTED FUNCTIONS:                                                    */
/*    int CCtsp_init_cutpool (int ncount, char *poolfilename,              */
/*            CCtsp_lpcuts **pool)                                         */
/*      -ncount is the number of nodes in the problem                      */
/*      -poolfilename is a file containing an cutpool (it can be NULL)     */
/*      -CCtsp_lpcuts will return the pool                                 */
/*                                                                         */
/*    int CCtsp_search_cutpool_cliques (CCtsp_lpcuts *pool,                */
/*            CCtsp_lpclique **cliques, int *cliquecount, int ncount,      */
/*            int ecount, int *elist, double *x, double maxdelta,          */
/*            int maxcliques, double **cliquevals)                         */
/*     RETURNS an array of cliques having x(delta(C)) < maxdelta           */
/*      -pool points to a cutpool (or cuts of an lp)                       */
/*      -cliques will return the array of cliques                          */
/*      -cliquecount with return the length of the array                   */
/*      -ncount is the number of nodes in the problem                      */
/*      -ecount is the number of edges in elist                            */
/*      -elist is a list of edges in end end format                        */
/*      -x is an ecount-long array of weights                              */
/*      -maxdelta is a bound on x(delta(C))                                */
/*      -maxcliques is an upperbound on the number of cliques that should  */
/*       be returned                                                       */
/*      -cliquevals will return the values of x(delta(C)) for the cliques  */
/*       (this parameter can be NULL)                                      */
/*                                                                         */
/*    void CCtsp_free_cutpool (CCtsp_lpcuts **pool)                        */
/*     FREES the pool of cuts.                                             */
/*                                                                         */
/*    int CCtsp_write_cutpool (int ncount, char *poolfilename,             */
/*         CCtsp_lpcuts *pool)                                             */
/*     WRITES pool to poolfilename.                                        */
/*                                                                         */
/*    int CCtsp_branch_cutpool_cliques (CCtsp_lpcuts *pool,                */
/*            CCtsp_lpclique **cliques, int *cliquecount, int ncount,      */
/*            int ecount, int *elist, double *x, int nwant,                */
/*            double **cliquevals)                                         */
/*     RETURNS an array of cliques having x(delta(C)) as close to 3.0 as   */
/*      possible.                                                          */
/*      -the parmeters are like those used by search_cutpool_cliques,      */
/*       where nwant is the number of cliques we would like to have in     */
/*       the array.                                                        */
/*                                                                         */
/*    int CCtsp_price_cuts (CCtsp_lpcuts *pool, int ncount, int ecount,    */
/*            int *elist, double *x, double *cutval)                       */
/*     COMPUTES the slack on each cut in the pool                          */
/*      -ecount, elist, and x give an x-vector                             */
/*      -cutval returns the array of slack values (it should be passed in  */
/*       as an array of length at least pool->cutcount)                    */
/*                                                                         */
/*  NOTES:                                                                 */
/*      This version does not use the compressed set references.  Notes    */
/*  on the representation are given in "Chapter 4: The Linear              */
/*  Programming Problems".                                                 */
/*                                                                         */
/***************************************************************************/

#include "machdefs.h"
#include "util.h"
#include "macrorus.h"
#include "tsp.h"

#define ZERO_EPSILON 0.0000000001
#define POOL_MAXCUTS 500
#define POOL_MINVIOL 0.001

typedef struct pooledge {
    double x;
    int to;
} pooledge;

typedef struct poolnode {
    struct pooledge *adj;
    int mark;
    int deg;
} poolnode;

#ifdef CC_PROTOTYPE_ANSI

static int
    init_empty_cutpool (int ncount, CCtsp_lpcuts *pool),
    cut_eq (void *v_cut1, void *v_cut2, void *u_data),
    read_cutpool (int ncount, char *poolfilename, CCtsp_lpcuts *pool),
    register_lpcuts (CCtsp_lpcuts *pool),
    price_cliques (CCtsp_lpcuts *pool, int ncount, int ecount, int *elist,
            double *x, double *cval);

static unsigned int
    cut_hash (void *v_cut, void *u_data);

static void
    sort_cliques (CCtsp_lpcut *c);

static double
    price_clique (poolnode *nlist, CCtsp_lpclique *c, int marker);

#else

static int
    init_empty_cutpool (),
    cut_eq (),
    read_cutpool (),
    register_lpcuts (),
    price_cliques ();

static unsigned int
    cut_hash ();

static void
    sort_cliques ();

static double
    price_clique ();

#endif


#ifdef CC_PROTOTYPE_ANSI
int CCtsp_init_cutpool (int ncount, char *poolfilename, CCtsp_lpcuts **pool)
#else
int CCtsp_init_cutpool (ncount, poolfilename, pool)
int ncount;
char *poolfilename;
CCtsp_lpcuts **pool;
#endif
{
    int rval = 0;
    CCtsp_lpcuts *p = (CCtsp_lpcuts *) NULL;

    p = CC_SAFE_MALLOC (1, CCtsp_lpcuts);
    if (!p) {
        fprintf (stderr, "out of memory in CCtsp_init_cutpool\n");
        return 1;
    }
    *pool = p;

    p->cutcount = 0;
    p->cuts = (CCtsp_lpcut *) NULL;
    p->cutspace = 0;
    p->cliqueend = 0;
    p->cliques = (CCtsp_lpclique *) NULL;
    p->cliquespace = 0;
    p->cliquehash = (int *) NULL;
    p->cuthash = (CCgenhash *) NULL;

    rval = init_empty_cutpool (ncount, p);
    if (rval) {
        fprintf (stderr, "init_empty_cutpool failed\n"); goto CLEANUP;
    }

    if (poolfilename) {
        rval = read_cutpool (ncount, poolfilename, p);
        if (rval) {
            fprintf (stderr, "read_cutpool failed\n"); goto CLEANUP;
        }
    }

CLEANUP:

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
void CCtsp_free_cutpool (CCtsp_lpcuts **pool)
#else
void CCtsp_free_cutpool (pool)
CCtsp_lpcuts **pool;
#endif
{
    int i;

    if (*pool) {
        if ((*pool)->cuts) {
            for (i = 0; i < (*pool)->cutcount; i++) {
                CC_IFFREE ((*pool)->cuts[i].cliques, int);
            }
            CC_FREE ((*pool)->cuts, CCtsp_lpcut);
        }
        if ((*pool)->cliques) {
            for (i=0; i < (*pool)->cliqueend; i++) {
                CC_IFFREE ((*pool)->cliques[i].nodes, CCtsp_segment);
            }
            CC_FREE ((*pool)->cliques, CCtsp_lpclique);
        }

        CCtsp_free_cliquehash (*pool);

        if ((*pool)->cuthash) {
            CCutil_genhash_free ((*pool)->cuthash, NULL);
            CC_FREE ((*pool)->cuthash, CCgenhash);
        }
        CC_FREE (*pool, CCtsp_lpcuts);
    }
}

#ifdef CC_PROTOTYPE_ANSI
static int init_empty_cutpool (int ncount, CCtsp_lpcuts *pool)
#else
static int init_empty_cutpool (ncount, pool)
int ncount;
CCtsp_lpcuts *pool;
#endif
{
    int rval = 0;

    rval = CCtsp_init_cliquehash (pool, 10 * ncount);
    if (rval) {
        fprintf (stderr, "CCtsp_init_cliqhash failed\n");
        return rval;
    }

    pool->cuthash = CC_SAFE_MALLOC (1, CCgenhash);
    if (pool->cuthash == (CCgenhash *) NULL) {
        fprintf (stderr, "Out of memory in init_empty_cutpool\n");
        return -1;
    }

    rval = CCutil_genhash_init (pool->cuthash, 10 * ncount, cut_eq,
                         cut_hash, (void *) pool, 1.0, 0.6);
    if (rval) {
        fprintf (stderr, "CCgenhash_init failed\n");
        return rval;
    }

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int cut_eq (void *v_cut1, void *v_cut2, void *u_data)
#else
static int cut_eq (v_cut1, v_cut2, u_data)
void *v_cut1;
void *v_cut2;
void *u_data;
#endif
{
    CCtsp_lpcuts *pool = (CCtsp_lpcuts *) u_data;
    CCtsp_lpcut *cut1 = pool->cuts + (long) v_cut1;
    CCtsp_lpcut *cut2 = pool->cuts + (long) v_cut2;
    int i;

    if (cut1->cliquecount != cut2->cliquecount) return 1;
    if (cut1->rhs != cut2->rhs) return 1;
    if (cut1->sense != cut2->sense) return 1;
    for (i=0; i<cut1->cliquecount; i++) {
        if (cut1->cliques[i] != cut2->cliques[i]) return 1;
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static unsigned int cut_hash (void *v_cut, void *u_data)
#else
static unsigned int cut_hash (v_cut, u_data)
void *v_cut;
void *u_data;
#endif
{
    CCtsp_lpcuts *pool = (CCtsp_lpcuts *) u_data;
    CCtsp_lpcut *cut = pool->cuts + (long) v_cut;
    unsigned int x = ((unsigned int) cut->rhs) * 257 +
                     ((unsigned int) cut->sense);
    int i;

    for (i=0; i<cut->cliquecount; i++) {
        x = x * 4099 + cut->cliques[i];
    }
    return x;
}

#ifdef CC_PROTOTYPE_ANSI
static int read_cutpool (int ncount, char *poolfilename, CCtsp_lpcuts *pool)
#else
static int read_cutpool (ncount, poolfilename, pool)
int ncount;
char *poolfilename;
CCtsp_lpcuts *pool;
#endif
{
    CC_SFILE *in;
    int n;
    int rval = 0;

    if (!poolfilename) {
        fprintf (stderr, "pool file name is not set\n");
        return 1;
    }

    in = CCutil_sopen (poolfilename, "r");
    if (!in) {
        fprintf (stderr, "sopen failed\n");
        return 1;
    }
    if (CCutil_sread_int (in, (unsigned int *) &n)) {
        fprintf (stderr, "CCutil_sread_int failed\n");
        CCutil_sclose (in);
        return 1;
    }
    if (n != ncount) {
        fprintf (stderr, "cutpool %s does not have the correct ncount\n",
                            poolfilename);
        CCutil_sclose (in);
        return 1;
    }

    rval = CCtsp_prob_getcuts ((CCtsp_PROB_FILE *) NULL, in, pool);
    if (rval < 0) {
        fprintf (stderr, "CCtsp_prob_getcuts failed\n");
        CCutil_sclose (in);
        return rval;
    }

    rval = register_lpcuts (pool);
    if (rval) {
        fprintf (stderr, "register_lpcuts failed\n");
        CCutil_sclose (in);
        return rval;
    }

    CCutil_sclose (in);
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_write_cutpool (int ncount, char *poolfilename, CCtsp_lpcuts *pool)
#else
int CCtsp_write_cutpool (ncount, poolfilename, pool)
int ncount;
char *poolfilename;
CCtsp_lpcuts *pool;
#endif
{
    CC_SFILE *out;
    int rval = 0;

    if (!poolfilename) {
        fprintf (stderr, "pool file name not set\n");
        return 1;
    }

    out = CCutil_sopen (poolfilename, "w");
    if (!out) {
        fprintf (stderr, "sopen failed\n");
        return 1;
    }
    if (CCutil_swrite_int (out, (unsigned int) ncount)) {
        fprintf (stderr, "CCutil_swrite_int failed\n");
        CCutil_sclose (out);
        return 1;
    }

    rval = CCtsp_prob_putcuts ((CCtsp_PROB_FILE *) NULL, out, pool);
    if (rval) {
        fprintf (stderr, "CCtsp_prob_putcuts failed\n");
        CCutil_sclose (out);
        return 1;
    }

    CCutil_sclose (out);
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_search_cutpool (CCtsp_lpcuts *pool, CCtsp_lpcut_in **cuts,
        int *cutcount, int ncount, int ecount, int *elist, double *x)
#else
int CCtsp_search_cutpool (pool, cuts, cutcount, ncount, ecount, elist, x)
CCtsp_lpcuts *pool;
CCtsp_lpcut_in **cuts;
int *cutcount;
int ncount, ecount;
int *elist;
double *x;
#endif
{
    int rval = 0;
    double *cval = (double *) NULL;
    int *ind = (int *) NULL;
    int i;
    CCtsp_lpcut_in *newc;
    double maxviol;

    *cutcount = 0;
    *cuts = (CCtsp_lpcut_in *) NULL;

    if (pool->cutcount == 0) return 0;

    cval = CC_SAFE_MALLOC (pool->cutcount, double);
    if (!cval) {
        fprintf (stderr, "out of memory in CCtsp_search_cutpool\n");
        rval = 1; goto CLEANUP;
    }
    rval = CCtsp_price_cuts (pool, ncount, ecount, elist, x, cval);
    if (rval) {
        fprintf (stderr, "CCtsp_price_cuts failed\n");
        goto CLEANUP;
    }

    ind = CC_SAFE_MALLOC (pool->cutcount, int);
    if (!ind) {
        fprintf (stderr, "out of memory in CCtsp_search_cutpool\n");
        rval = 1; goto CLEANUP;
    }

    for (i = 0; i < pool->cutcount; i++) {
        ind[i] = i;
    }

    CCutil_rselect (ind, 0, pool->cutcount - 1, POOL_MAXCUTS, cval);

    maxviol = 0.0;
    for (i = 0; i < pool->cutcount && i < POOL_MAXCUTS; i++) {
        if (cval[ind[i]] < maxviol) maxviol = cval[ind[i]];
        if (cval[ind[i]] < -POOL_MINVIOL) {
            newc = CC_SAFE_MALLOC (1, CCtsp_lpcut_in);
            if (!newc) {
                fprintf (stderr, "out of memory in CCtsp_search_cutpool\n");
                goto CLEANUP;
            }
            rval = CCtsp_lpcut_to_lpcut_in (pool, &pool->cuts[ind[i]], newc);
            if (rval) {
                fprintf (stderr, "CCtsp_lpcut_to_lpcut_in failed\n");
                CC_FREE (newc, CCtsp_lpcut_in);
                goto CLEANUP;
            }
            newc->next = *cuts;
            *cuts = newc;
            (*cutcount)++;
        }
    }
    printf ("%d pool cuts found, max violation %.3f\n", *cutcount, -maxviol);
    rval = 0;

CLEANUP:

    CC_IFFREE (cval, double);
    CC_IFFREE (ind, int);
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_search_cutpool_cliques (CCtsp_lpcuts *pool, CCtsp_lpclique **cliques,
        int *cliquecount, int ncount, int ecount, int *elist, double *x,
        double maxdelta, int maxcliques, double **cliquevals)
#else
int CCtsp_search_cutpool_cliques (pool, cliques, cliquecount, ncount, ecount,
        elist, x, maxdelta, maxcliques, cliquevals)
CCtsp_lpcuts *pool;
CCtsp_lpclique **cliques;
int *cliquecount;
int ncount, ecount;
int *elist;
double *x;
double maxdelta;
int maxcliques;
double **cliquevals;
#endif
{
    int rval = 0;
    double *cval = (double *) NULL;
    int *ind = (int *) NULL;
    double upperdelta, lowerdelta;
    int i, k;
    int ccount = 0;

    *cliquecount = 0;
    *cliques = (CCtsp_lpclique *) NULL;
    if (cliquevals) {
        *cliquevals = (double *) NULL;
    }

    if (pool->cutcount == 0) return 0;

    cval = CC_SAFE_MALLOC (pool->cliqueend, double);
    if (!cval) {
        fprintf (stderr, "out of memory in CCtsp_search_cutpool_cliques\n");
        rval = 1; goto CLEANUP;
    }

    rval = price_cliques (pool, ncount, ecount, elist, x, cval);
    if (rval) {
        fprintf (stderr, "price_cliques failed\n");
        goto CLEANUP;
    }

    ind = CC_SAFE_MALLOC (pool->cliqueend, int);
    if (!ind) {
        fprintf (stderr, "out of memory in CCtsp_search_cutpool_cliques\n");
        rval = 1; goto CLEANUP;
    }
    for (i = 0; i < pool->cliqueend; i++) {
        ind[i] = i;
    }

    CCutil_rselect (ind, 0, pool->cliqueend - 1, maxcliques, cval);

    upperdelta = -1.0;
    lowerdelta = maxdelta;
    for (i = 0; i < pool->cliqueend && i < maxcliques; i++) {
        if (cval[ind[i]] < maxdelta) {
            ccount++;
            if (cval[ind[i]] < lowerdelta) lowerdelta = cval[ind[i]];
            if (cval[ind[i]] > upperdelta) upperdelta = cval[ind[i]];
        }
    }

    if (ccount == 0) {
        printf ("Found no nearly tight cliques\n"); fflush (stdout);
        goto CLEANUP;
    }

    *cliques = CC_SAFE_MALLOC (ccount, CCtsp_lpclique);
    if (!(*cliques)) {
        fprintf (stderr, "out of memory in CCtsp_search_cutpool_cliques\n");
        rval = 1; goto CLEANUP;
    }
    if (cliquevals) {
        *cliquevals = CC_SAFE_MALLOC (ccount, double);
        if (!(*cliquevals)) {
            fprintf (stderr, "out of memory in CCtsp_search_cutpool_cliques\n");
            CC_FREE (*cliques, CCtsp_lpclique);
            rval = 1; goto CLEANUP;
        }
    }

    ccount = 0;
    for (i = 0; i < pool->cliqueend && i < maxcliques; i++) {
        if (cval[ind[i]] < maxdelta) {
            rval = CCtsp_copy_lpclique (&(pool->cliques[ind[i]]),
                                        &((*cliques)[ccount]));
            if (rval) {
                fprintf (stderr, "CCtsp_copy_lpclique failed\n");
                for (k = 0; k < ccount; k++) {
                    CC_FREE ((*cliques)[k].nodes, CCtsp_segment);
                }
                CC_FREE (*cliques, CCtsp_lpclique);
                if (cliquevals) {
                    CC_FREE (*cliquevals, double);
                }
                goto CLEANUP;
            }
            if (cliquevals) {
                (*cliquevals)[ccount] = cval[ind[i]];
            }
            ccount++;
        }
    }
    *cliquecount = ccount;

    printf ("%d nearly tight cliques found, range (%.3f, %.3f)\n",
              *cliquecount, lowerdelta, upperdelta);
    fflush (stdout);

CLEANUP:

    CC_IFFREE (cval, double);
    CC_IFFREE (ind, int);
    return rval;
}

#define BRANCH_CLIQUE_GOAL 3.00
#define BRANCH_CLIQUE_TOL  0.99

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_branch_cutpool_cliques (CCtsp_lpcuts *pool, CCtsp_lpclique **cliques,
        int *cliquecount, int ncount, int ecount, int *elist, double *x,
        int nwant, double **cliquevals)
#else
int CCtsp_branch_cutpool_cliques (pool, cliques, cliquecount, ncount, ecount,
        elist, x, nwant, cliquevals)
CCtsp_lpcuts *pool;
CCtsp_lpclique **cliques;
int *cliquecount;
int ncount, ecount;
int *elist;
double *x;
int nwant;
double **cliquevals;
#endif
{
    int rval = 0;
    double *cval = (double *) NULL;
    double upperdelta, lowerdelta;
    double t;
    int i, k;
    int ccount = 0;
    int *blist =   (int *) NULL;
    double *bval = (double *) NULL;

    printf ("branch_cutpool_cliques ...\n"); fflush (stdout);

    *cliquecount = 0;
    *cliques = (CCtsp_lpclique *) NULL;
    if (cliquevals) {
        *cliquevals = (double *) NULL;
    }

    if (pool->cutcount == 0 || nwant <= 0) return 0;

    blist = CC_SAFE_MALLOC (nwant + 1, int);
    bval  = CC_SAFE_MALLOC (nwant + 1, double);
    cval = CC_SAFE_MALLOC (pool->cliqueend, double);
    if (!blist || !bval || !cval) {
        fprintf (stderr, "out of memory in CCtsp_search_cutpool_cliques\n");
        rval = 1; goto CLEANUP;
    }

    rval = price_cliques (pool, ncount, ecount, elist, x, cval);
    if (rval) {
        fprintf (stderr, "price_cliques failed\n");
        goto CLEANUP;
    }

    for (i = 0; i < nwant; i++) {
        blist[i] = -1;
        bval[i]  = CCtsp_LP_MAXDOUBLE;
    }
    blist[nwant] = -1;
    bval[i]      = -1.0;

    for (i = 0; i < pool->cliqueend; i++) {
        t = CC_OURABS (BRANCH_CLIQUE_GOAL - cval[i]);
        if (t < bval[0] && t < BRANCH_CLIQUE_TOL) {
            for (k = 0; t < bval[k+1]; k++) {
                blist[k] = blist[k+1];
                bval[k]  =  bval[k+1];
            }
            blist[k] = i;
            bval[k]  = t;
        }
    }

    upperdelta = -1.0;
    lowerdelta = CCtsp_LP_MAXDOUBLE;
    for (i = 0; i < nwant; i++) {
        if (blist[i] != -1) {
            if (upperdelta < cval[blist[i]]) {
                upperdelta = cval[blist[i]];
            }
            if (lowerdelta > cval[blist[i]]) {
                lowerdelta = cval[blist[i]];
            }
            ccount++;
        }
    }

    if (ccount == 0) {
        printf ("Found no nearly tight cliques\n"); fflush (stdout);
        goto CLEANUP;
    }

    *cliques = CC_SAFE_MALLOC (ccount, CCtsp_lpclique);
    if (!(*cliques)) {
        fprintf (stderr, "out of memory in CCtsp_search_cutpool_cliques\n");
        rval = 1; goto CLEANUP;
    }
    if (cliquevals) {
        *cliquevals = CC_SAFE_MALLOC (ccount, double);
        if (!(*cliquevals)) {
            fprintf (stderr, "out of memory in CCtsp_search_cutpool_cliques\n");
            CC_FREE (*cliques, CCtsp_lpclique);
            rval = 1; goto CLEANUP;
        }
    }

    ccount = 0;
    for (i = nwant - 1; i >= 0; i--) {
        if (blist[i] != -1) {
            rval = CCtsp_copy_lpclique (&(pool->cliques[blist[i]]),
                                      &((*cliques)[ccount]));
            if (rval) {
                fprintf (stderr, "CCtsp_copy_lpclique failed\n");
                for (k = 0; k < ccount; k++) {
                    CC_FREE ((*cliques)[k].nodes, CCtsp_segment);
                }
                CC_FREE (*cliques, CCtsp_lpclique);
                if (cliquevals) {
                    CC_FREE (*cliquevals, double);
                }
                goto CLEANUP;
            }
            if (cliquevals) {
                (*cliquevals)[ccount] = cval[blist[i]];
            }
            ccount++;
        }
    }
    *cliquecount = ccount;

    printf ("%d candidate branching cliques, range (%.3f, %.3f)\n",
              *cliquecount, lowerdelta, upperdelta);
    fflush (stdout);


CLEANUP:

    CC_IFFREE (blist, int);
    CC_IFFREE (bval, double);
    CC_IFFREE (cval, double);
    return rval;
}


#ifdef CC_PROTOTYPE_ANSI
int CCtsp_add_to_cutpool (CCtsp_lpcuts *pool, CCtsp_lpcuts *cuts,
        CCtsp_lpcut *c)
#else
int CCtsp_add_to_cutpool (pool, cuts, c)
CCtsp_lpcuts *pool;
CCtsp_lpcuts *cuts;
CCtsp_lpcut *c;
#endif
{
    int rval = 0;
    CCtsp_lpcut_in cin;
    int k;

    if (!c || c->cliquecount <= 1)
        return 0;

    cin.cliquecount = 0;
    cin.cliques = (CCtsp_lpclique *) NULL;


    rval = CCtsp_lpcut_to_lpcut_in (cuts, c, &cin);
    if (rval) {
        fprintf (stderr, "CCtsp_lpcut_to_lpcut_in failed\n");
        goto CLEANUP;
    }

    rval = CCtsp_add_to_cutpool_lpcut_in (pool, &cin);
    if (rval) {
        fprintf (stderr, "CCtsp_add_to_cutpool_lpcut_in failed\n");
        goto CLEANUP;
    }

CLEANUP:

    for (k = 0; k < cin.cliquecount; k++) {
        CC_IFFREE (cin.cliques[k].nodes, CCtsp_segment);
    }
    CC_IFFREE (cin.cliques, CCtsp_lpclique);

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_add_to_cutpool_lpcut_in (CCtsp_lpcuts *pool, CCtsp_lpcut_in *cut)
#else
int CCtsp_add_to_cutpool_lpcut_in (pool, cut)
CCtsp_lpcuts *pool;
CCtsp_lpcut_in *cut;
#endif
{
    int rval = 0;
    CCtsp_lpcut new;
    int cutloc;
    unsigned int hval;

    if (!pool)
        return 0;

    new.rhs      = cut->rhs;
    new.branch   = cut->branch;
    new.sense    = cut->sense;
    new.modcount = 0;
    new.mods = (CCtsp_sparser *) NULL;
    new.handlecount = 0;
    new.cliquecount = 0;
    new.cliques = (int *) NULL;
    new.age = 0;

    rval = CCtsp_register_cliques (pool, cut, &new);
    if (rval) {
        fprintf (stderr, "register_cliques failed\n");
        return rval;
    }

    sort_cliques (&new);

    cutloc = CCtsp_add_cut_to_cutlist (pool, &new);
    if (cutloc < 0) {
        fprintf (stderr, "CCtsp_add_cut_to_cutlist failed\n");
        CCtsp_unregister_cliques (pool, &new);
        return cutloc;
    }

    hval = CCutil_genhash_hash (pool->cuthash, (void *) ((long) cutloc));
    if (CCutil_genhash_lookup_h (pool->cuthash, hval,
                                 (void *) ((long) cutloc))) {
        /* cut was already in pool */
        CCtsp_delete_cut_from_cutlist (pool, cutloc);
        return 0;
    }

    rval = CCutil_genhash_insert_h (pool->cuthash, hval, (void *) ((long) cutloc),
            (void *) ((long) 1));
    if (rval) {
        fprintf (stderr, "CCgenhash_insert_h failed\n");
        CCtsp_delete_cut_from_cutlist (pool, cutloc);
        return rval;
    }

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static void sort_cliques (CCtsp_lpcut *c)
#else
static void sort_cliques (c)
CCtsp_lpcut *c;
#endif
{
    CCutil_int_array_quicksort (c->cliques, c->handlecount);
    CCutil_int_array_quicksort (c->cliques + c->handlecount,
                               c->cliquecount - c->handlecount);
}

#ifdef CC_PROTOTYPE_ANSI
static int register_lpcuts (CCtsp_lpcuts *pool)
#else
static int register_lpcuts (pool)
CCtsp_lpcuts *pool;
#endif
{
    int i;
    unsigned int hval;
    int rval = 0;
    int ndup = 0;

    for (i=0; i<pool->cutcount; i++) {
        sort_cliques (&pool->cuts[i]);
        hval = CCutil_genhash_hash (pool->cuthash, (void *) ((long) i));
        if (CCutil_genhash_lookup_h (pool->cuthash, hval,
                                     (void *) ((long) i))) {
            ndup++;
        } else {
            rval = CCutil_genhash_insert_h (pool->cuthash, hval,
                                            (void *) ((long) i),
                                            (void *) ((long) 1));
            if (rval) {
                fprintf (stderr, "CCgenhash_insert_h failed\n");
                return rval;
            }
        }
    }
    if (ndup) {
        printf ("%d duplicates detected in pool\n", ndup);
        fflush (stdout);
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_display_cutpool (CCtsp_lpcuts *pool)
#else
int CCtsp_display_cutpool (pool)
CCtsp_lpcuts *pool;
#endif
{
    int i, k;
    CCtsp_lpcut_in c;

    for (i = 0; i < pool->cutcount; i++) {
        if (CCtsp_lpcut_to_lpcut_in (pool, &(pool->cuts[i]), &c)) {
            fprintf (stderr, "CCtsp_lpcut_to_lpcut_in failed\n");
            return 1;
        }
        CCtsp_print_lpcut_in (&c);
        for (k = 0; k < c.cliquecount; k++) {
            CC_IFFREE (c.cliques[k].nodes, CCtsp_segment);
        }
    }

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_price_cuts (CCtsp_lpcuts *pool, int ncount, int ecount, int *elist,
        double *x, double *cutval)
#else
int CCtsp_price_cuts (pool, ncount, ecount, elist, x, cutval)
CCtsp_lpcuts *pool;
int ncount;
int ecount;
int *elist;
double *x;
double *cutval;
#endif
{
    double *cval = (double *) NULL;
    int cutcount = pool->cutcount;
    int i, j;
    CCtsp_lpcut *c;
    int rval = 0;

    cval = CC_SAFE_MALLOC (pool->cliqueend, double);
    if (!cval) {
        fprintf (stderr, "out of memory in CCtsp_price_cuts\n");
        return 1;
    }

    rval = price_cliques (pool, ncount, ecount, elist, x, cval);
    if (rval) {
        fprintf (stderr, "price_cliques failed\n");
        return rval;
    }

    for (i = 0, c = pool->cuts; i < cutcount; i++, c++) {
        cutval[i] = (double) -(c->rhs);
        for (j  = 0; j < c->cliquecount; j++)  {
            cutval[i] += cval[c->cliques[j]];
        }
    }

    CC_FREE (cval, double);
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int price_cliques (CCtsp_lpcuts *pool, int ncount, int ecount,
        int *elist, double *x, double *cval)
#else
static int price_cliques (pool, ncount, ecount, elist, x, cval)
CCtsp_lpcuts *pool;
int ncount;
int ecount;
int *elist;
double *x;
double *cval;
#endif
{
    poolnode *nlist = (poolnode *) NULL;
    pooledge *espace = (pooledge *) NULL;
    pooledge *p;
    char *marks = (char *) NULL;
    int marker = 0;
    int i, j, a, b, count;
    int cend = pool->cliqueend;
    int rval = 0;

    nlist = CC_SAFE_MALLOC (ncount, poolnode);
    if (!nlist) {
        fprintf (stderr, "out of memory in price_cliques\n");
        rval = 1; goto CLEANUP;
    }

    for (i = 0; i < ncount; i++) {
        nlist[i].mark = 0;
        nlist[i].deg = 0;
    }

    count = 0;
    for (i = 0; i < ecount; i++) {
        if (x[i] >= ZERO_EPSILON) {
            nlist[elist[2*i]].deg++;
            nlist[elist[2*i+1]].deg++;
            count++;
        }
    }
    espace = CC_SAFE_MALLOC (2*count, pooledge);
    if (!espace) {
        fprintf (stderr, "out of memory in price_cliques\n");
        rval = 1; goto CLEANUP;
    }

    p = espace;
    for (i = 0; i < ncount; i++) {
        nlist[i].adj = p;
        p += nlist[i].deg;
        nlist[i].deg = 0;
    }
    for (i = 0; i < ecount; i++) {
        if (x[i] >= ZERO_EPSILON) {
            a = elist[2*i];
            b = elist[2*i+1];
            nlist[a].adj[nlist[a].deg].x = x[i];
            nlist[a].adj[nlist[a].deg++].to = b;
            nlist[b].adj[nlist[b].deg].x = x[i];
            nlist[b].adj[nlist[b].deg++].to = a;
        }
    }

    marks = CC_SAFE_MALLOC (cend, char);
    if (!marks) {
        fprintf (stderr, "out of memory in price_cliques\n");
        rval = 1; goto CLEANUP;
    }

    for (i = 0; i < cend; i++) {
        marks[i] = 0;
    }
    for (i = 0; i < pool->cutcount; i++) {
        for (j = 0; j < pool->cuts[i].cliquecount; j++) {
            marks[pool->cuts[i].cliques[j]] = 1;
        }
    }

    for (i = 0; i < cend; i++) {
        if (marks[i]) {
            marker++;
            cval[i] = price_clique (nlist, &(pool->cliques[i]), marker);
        } else {
            cval[i] = 0.0;
        }
    }

CLEANUP:

    CC_IFFREE (nlist, poolnode);
    CC_IFFREE (espace, pooledge);
    CC_IFFREE (marks, char);
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static double price_clique (poolnode *nlist, CCtsp_lpclique *c, int marker)
#else
static double price_clique (nlist, c, marker)
poolnode *nlist;
CCtsp_lpclique *c;
int marker;
#endif
{
    double val = 0.0;
    poolnode *n;
    int i, j, k;

    for (i = 0; i < c->segcount; i++) {
        for (j = c->nodes[i].lo; j <= c->nodes[i].hi; j++) {
            nlist[j].mark = marker;
        }
    }
    for (i = 0; i < c->segcount; i++) {
        for (j = c->nodes[i].lo; j <= c->nodes[i].hi; j++) {
            n = &(nlist[j]);
            for (k = 0; k < n->deg; k++) {
                if (nlist[n->adj[k].to].mark != marker) {
                    val += n->adj[k].x;
                }
            }
        }
    }
    return val;
}
