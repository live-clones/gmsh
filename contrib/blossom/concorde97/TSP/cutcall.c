/***************************************************************************/
/*                                                                         */
/*                    Interface to the Cutters                             */
/*                                                                         */
/*                           TSP CODE                                      */
/*                                                                         */
/*                                                                         */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook                       */
/*  Date: February 17, 1997                                                */
/*                                                                         */
/*                                                                         */
/*  EXPORTED FUNCTIONS:                                                    */
/*    int CCtsp_connect_cuts (CCtsp_lpcut_in **cuts, int *cutcount,        */
/*            int ncount, int ecount, int *elist, double *x)               */
/*     FINDS violated subtour inequalities via connectivity.               */
/*      -cuts will return any new cuts found (they will be added to the    */
/*       head of the linked list)                                          */
/*      -cutcount will return the number of new cuts added                 */
/*      -ncount is the number of nodes                                     */
/*      -ecount is the number of edges                                     */
/*      -elist contains the LP edges in node node format                   */
/*      -x is an LP solution                                               */
/*                                                                         */
/*    int CCtsp_segment_cuts (CCtsp_lpcut_in **cuts, int *cutcount,        */
/*            int ncount, int ecount, int *elist, double *x)               */
/*     FINDS violated subtour inequalities via linsub.                     */
/*                                                                         */
/*    int CCtsp_exact_subtours (CCtsp_lpcut_in **cuts, int *cutcount,      */
/*            int ncount, int ecount, int *elist, double *x)               */
/*     FINDS violated subtour inequalities via a mincut algorithm.         */
/*                                                                         */
/*    int CCtsp_tighten_lp (CCtsp_lpcuts *cuts, CCtsp_tighten_info *stats, */
/*            CCtsp_lpcut_in **cutsout, int *cutcount, int ncount,         */
/*            int ecount,  int *elist, double *x, double testtol,          */
/*            int maxcuts)                                                 */
/*     CALLS tighten for each cut in the cuts.                             */
/*      -stats contains some running statistics of tighten                 */
/*      -cutsout returns the tightened cuts that are violated (they are    */
/*       added to the head of the linked list)                             */
/*      -cutcount is the number of cuts in cutsout                         */
/*      -testtol is a tolerance for calling tighten (call only when the    */
/*       cut has slack value within testtol)                               */
/*      -maxcuts is a bound on the number of cuts to be returned           */
/*                                                                         */
/*    void CCtsp_init_lpcut_in (CCtsp_lpcut_in *c)                         */
/*     INITIALIZE the fields of the CCtsp_lpcut_in structure               */
/*                                                                         */
/*    int CCtsp_segment_to_subtour (CCtsp_lpcut_in **cut, int a, int b)    */
/*     BUILDS a subtour CCtsp_lpcut_in from an the segment.                */
/*      -cut will return the subtour (it will be allocated).               */
/*                                                                         */
/*    int CCtsp_array_to_subtour (CCtsp_lpcut_in **cut, int *ar,           */
/*            int acount)                                                  */
/*     BUILDS a subtour CCtsp_lpcut_in from an array.                      */
/*      -cut will return the subtour (it will be allocated).               */
/*                                                                         */
/*    void CCtsp_init_lpclique (CCtsp_lpclique *c)                         */
/*     INITIALIZE the fields of the CCtsp_lpclique structure               */
/*                                                                         */
/*    int CCtsp_array_to_lpclique (int *ar, int acount,                    */
/*            CCtsp_lpclique *cliq)                                        */
/*     BUILDS an CCtsp_lpclique represented the nodes in an array.         */
/*      -ar is an array of node numbers                                    */
/*      -acount is the length of ar                                        */
/*      -cliq's segcount and nodes will be filled with the compressed      */
/*       version of the nodes in ar                                        */
/*                                                                         */
/*    int CCtsp_seglist_to_lpclique (int nseg, int *list,                  */
/*            CCtsp_lpclique *cliq)                                        */
/*     BUILDS the CCtsp_lpclique represented by a list of CCtsp_segments   */
/*     (it will sort the CCtsp_segments before it puts them into the       */
/*     CCtsp_segment structures)                                           */
/*      -list is an array of CCtsp_segments in lo-hi-lo-hi format          */
/*      -clig's segcount and nodes will be filled in (nodes will be        */
/*       allocated)                                                        */
/*                                                                         */
/*    int CCtsp_add_node_to_lpclique (CCtsp_lpclique *cin,                 */
/*            CCtsp_lpclique *cout, int n)                                 */
/*     ADDS node n to clique cin, and returns the new clique in cout       */
/*                                                                         */
/*    int CCtsp_delete_node_from_lpclique (CCtsp_lpclique *cin,      */
/*            CCtsp_lpclique *cout, int n)                                 */
/*     DELETES node n from clique cin, and returns the new clique in cout  */
/*                                                                         */
/*    void CCtsp_print_lpcut_in (CCtsp_lpcut_in *c)                  */
/*     PRINTS the CCtsp_lpcut_in                                           */
/*                                                                         */
/*    void CCtsp_print_lpclique (CCtsp_lpclique *c)                  */
/*     PRINTS the CCtsp_segments in the clique to stdout.                  */
/*                                                                         */
/*    int CCtsp_copy_lpcut_in (CCtsp_lpcut_in *c,                    */
/*            CCtsp_lpcut_in *new)                                         */
/*     COPIES an CCtsp_lpcut_in                                            */
/*      -c is a pointer to an CCtsp_lpcut_in                               */
/*      -new returns the copied CCtsp_lpcut                                */
/*                                                                         */
/*    int CCtsp_lpcut_to_lpcut_in (CCtsp_lpcuts *cuts,                     */
/*            CCtsp_lpcut *c, CCtsp_lpcut_in *new)                         */
/*     COPIES an CCtsp_lpcut to an CCtsp_lpcut_in                          */
/*      -cuts is a pointer to the structure holding the set of cuts        */
/*      -c is the cut to be copied                                         */
/*      -new returns the copied cut                                        */
/*                                                                         */
/*    void CCtsp_lpclique_compare (CCtsp_lpclique *a,                      */
/*            CCtsp_lpclique *b, int *diff)                                */
/*     COMPARES two CCtsp_lpcliques.                                       */
/*      -diff is set to 1 if they differ and 0 if they are the same        */
/*       Note: Assumes CCtsp_segments are ordered.                         */
/*                                                                         */
/*    int CCtsp_copy_lpclique (CCtsp_lpclique *c,                    */
/*            CCtsp_lpclique *new)                                         */
/*     COPIES an CCtsp_lpclique                                            */
/*      -c is a pointer to an CCtsp_lpclique                               */
/*      -new returns the copied clique                                     */
/*                                                                         */
/*    int CCtsp_file_cuts (char *cutfile, CCtsp_lpcut_in **cuts,           */
/*            int *cutcount, int ncount, int *tour)                        */
/*     READS a set of cuts from a file; the format of the cuts can be      */
/*      found by examining the code                                        */
/*      -cutfile is an asci file with a list of cuts                       */
/*      -cuts will return any new cuts found (they will be added to the    */
/*       head of the linked list)                                          */
/*      -cutcount with return the number of new cuts added                 */
/*      -ncount is the number of nodes                                     */
/*      -tour the permutation tour (used to map the incoming nodes)        */
/*                                                                         */
/*    int CCtsp_file_cuts_write (char *cutfile, CCtsp_lpcuts *cuts,        */
/*            int *tour)                                                   */
/*     WRITES a set of cuts in a text file that can be read by             */
/*      tsp_file_cuts                                                      */
/*      -cutfile is the name of the file to be written                     */
/*      -cuts is the set of cuts to be written                             */
/*      -tour is a permutation tour (used to map the outgoing nodes)       */
/*                                                                         */
/*    int CCtsp_test_pure_comb (int ncount, CCtsp_lpcut_in *c, int *yes_no,*/
/*           int *handle)                                                  */
/*     TEST if the cut is a comb (without flipped teeth or intersections)  */
/*      -ncount is the number of nodes in the TSP                          */
/*      -yes_no will be set to either 0 or 1, with 1 meaning yes           */
/*      -handle with return the index of the handle if the cut is a comb   */
/*       (handle can be NULL)                                              */
/*                                                                         */
/*    int CCtsp_test_pseudocomb (int ncount, CCtsp_lpcut_in *c, int handle,*/
/*           int *yes_no)                                                  */
/*     TEST if the cut is a pseudocomb.                                    */
/*      -handle gives the index of the handle of the pseudocomb            */
/*                                                                         */
/*    int CCtsp_test_teeth_disjoint (int ncount, CCtsp_lpcut_in *c,        */
/*       int handle, int *yes_no)                                          */
/*     TEST if the cliques other than handle are pairwise disjoint.        */
/*      -yes_no is 1 if disjoint and 0 otherwise.                          */
/*                                                                         */
/*    int CCtsp_find_pure_handle (int ncount, CCtsp_lpcut_in *c,           */
/*            int *handle)                                                 */
/*     FINDS a clique that is c's handle if c is a comb; the search        */
/*      assumes that the teeth are disjoint, so if the comb has            */
/*      extra intersections then a tooth may be returned.                  */
/*      -handle returns the potential handle (it will return -1 if no      */
/*       clique is a potential handle)                                     */
/*                                                                         */
/*  NOTES:                                                                 */
/*                                                                         */
/***************************************************************************/

#include "machdefs.h"
#include "macrorus.h"
#include "util.h"
#include "tsp.h"
#include "cut.h"

#define X_FLUFF (1e-10)
#undef  DUMP_BUILDCUT

typedef struct exactsub_param {
    int cutcount;
    CCtsp_lpcut_in *cuts;
} exactsub_param;

#ifdef CC_PROTOTYPE_ANSI

static int
    add_segment (double val, int a, int b, void *pass_param),
    add_exact (double val, int count, int *cutarray, void *pass_param),
    work_on_combs_in_lp (CCtsp_lpcuts *cuts, CCtsp_tighten_info *stats,
        CCtsp_lpcut_in **cutsout,
        int *cutcount, int ncount, int ecount, int *elist, double *x,
        double testtol, int maxcuts,
        int (*doit_fn) (CCtsp_lpgraph *, double *, CCtsp_lpcut_in *,
        CCtsp_lpcut_in **)),
    grab_nonzero_x (int ecount, int *elist, double *x, int *new_ecount,
        int **new_elist, double **new_x, double tol);

#else

static int
    add_segment (),
    add_exact (),
    work_on_combs_in_lp (),
    grab_nonzero_x ();

#endif


#ifdef CC_PROTOTYPE_ANSI
int CCtsp_connect_cuts (CCtsp_lpcut_in **cuts, int *cutcount, int ncount,
         int ecount, int *elist, double *x)
#else
int CCtsp_connect_cuts (cuts, cutcount, ncount, ecount, elist, x)
CCtsp_lpcut_in **cuts;
int *cutcount;
int ncount, ecount;
int *elist;
double *x;
#endif
{
    int rval;
    int i, k, ncomp;
    CCtsp_lpcut_in *c     = (CCtsp_lpcut_in *) NULL;
    int *comps      = (int *) NULL;
    int *compscount = (int *) NULL;

    *cutcount = 0;
    rval = CCcut_connect_components (ncount, ecount, elist, x, &ncomp,
                                   &compscount, &comps);
    if (rval) {
        fprintf (stderr, "CCcut_connect_components failed\n"); goto CLEANUP;
    }

    for (i = 0, k = 0; i < ncomp - 1; k += compscount[i], i++) {
        rval = CCtsp_array_to_subtour (&c, comps + k, compscount[i]);
        if (rval) {
            fprintf (stderr, "CCtsp_array_to_subtour failed\n");
            rval = 1; goto CLEANUP;
        }
        c->next = *cuts;
        *cuts = c;
        (*cutcount)++;
    }

CLEANUP:

    CC_IFFREE (comps, int);
    CC_IFFREE (compscount, int);

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_segment_cuts (CCtsp_lpcut_in **cuts, int *cutcount, int ncount,
        int ecount, int *elist, double *x)
#else
int CCtsp_segment_cuts (cuts, cutcount, ncount, ecount, elist, x)
CCtsp_lpcut_in **cuts;
int *cutcount;
int ncount, ecount;
int *elist;
double *x;
#endif
{
    int rval = 0;
    exactsub_param p;
    double szeit = CCutil_zeit ();

    *cutcount = 0;

    p.cutcount = 0;
    p.cuts = *cuts;

    rval = CCcut_linsub (ncount, ecount, elist, x, 2.0 - 0.0001,
                         add_segment, (void *) &p);
    if (rval) {
        fprintf (stderr, "CCcut_linsub failed\n"); goto CLEANUP;
    }

    *cutcount = p.cutcount;
    *cuts = p.cuts;

    printf ("DONE (found %d segment cuts in %.2f seconds)\n", *cutcount,
                                                 CCutil_zeit () - szeit);
    fflush (stdout);

CLEANUP:

    return rval;
}


#ifdef CC_PROTOTYPE_ANSI
int CCtsp_exact_subtours (CCtsp_lpcut_in **cuts, int *cutcount, int ncount,
        int ecount, int *elist, double *x)
#else
int CCtsp_exact_subtours (cuts, cutcount, ncount, ecount, elist, x)
CCtsp_lpcut_in **cuts;
int *cutcount;
int ncount, ecount;
int *elist;
double *x;
#endif
{
    int rval = 0;
    exactsub_param p;
    double szeit = CCutil_zeit ();


    printf ("exact_subtours ... \n"); fflush (stdout);
    *cutcount = 0;
    rval = CCtsp_connect_cuts (cuts, cutcount, ncount, ecount, elist, x);
    if (rval) {
        fprintf (stderr, "CCtsp_connect_cuts failed\n"); goto CLEANUP;
    }

    if (*cutcount > 0) {
        fprintf (stderr, "found connect cuts, do not call exact cut routine\n");
        rval = 0; goto CLEANUP;
    }

    p.cutcount = 0;
    p.cuts = *cuts;

    rval = CCcut_violated_cuts (ncount, ecount, elist, x, 2.0 - 0.0001,
                       add_exact, (void *) &p);
    if (rval) {
        fprintf (stderr, "CCcut_violated_cuts failed\n"); goto CLEANUP;
    }

    *cutcount = p.cutcount;
    *cuts = p.cuts;

    printf ("DONE (found %d cuts in %.2f seconds)\n", *cutcount,
                                                   CCutil_zeit () - szeit);
    fflush (stdout);

#if 0
  - this is just to check the values of the exact cuts
    if (*cutcount) {
        CCtsp_lpgraph lg;
        CCtsp_lpcut_in *c;
        double t;

        CCtsp_init_lpgraph_struct (&lg);

        rval = CCtsp_build_lpgraph (&lg, ncount, ecount, elist, (int *) NULL);
        if (rval) {
            fprintf (stderr, "CCtsp_build_lpgraph failed\n"); goto CLEANUP;
        }
        rval = CCtsp_build_lpadj (&lg, 0, ecount);
        if (rval) {
            CCtsp_free_lpgraph (&lg);
            fprintf (stderr, "CCtsp_build_lpadj failed\n"); goto CLEANUP;
        }
        for (c = p.cuts; c; c = c->next) {
            t = CCtsp_cutprice (&lg, c, x);
            printf ("[%f] ", 2.0 + t); fflush (stdout);
        }
        printf ("\n"); fflush (stdout);
        CCtsp_free_lpgraph (&lg);
    }
#endif

CLEANUP:

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static int add_segment (double val, int a, int b, void *pass_param)
#else
static int add_segment (val, a, b, pass_param)
double val;
int a, b;
void *pass_param;
#endif
{
    int rval = 0;
    exactsub_param *p = (exactsub_param *) pass_param;
    CCtsp_lpcut_in *c = (CCtsp_lpcut_in *) NULL;

    if (val > 2.0) {
        printf ("Warning: Cut of value %f in add_segment\n", val);
        fflush (stdout);
        goto CLEANUP;
    }

    rval = CCtsp_segment_to_subtour (&c, a, b);
    if (rval) {
        fprintf (stderr, "CCtsp_array_to_subtour failed\n");
        rval = 1; goto CLEANUP;
    }
    c->next = p->cuts;
    p->cuts = c;
    p->cutcount++;

CLEANUP:

    return rval;
}
#ifdef CC_PROTOTYPE_ANSI
static int add_exact (double val, int count, int *cutarray, void *pass_param)
#else
static int add_exact (val, count, cutarray, pass_param)
double val;
int count;
int *cutarray;
void *pass_param;
#endif
{
    int rval = 0;
    exactsub_param *p = (exactsub_param *) pass_param;
    CCtsp_lpcut_in *c = (CCtsp_lpcut_in *) NULL;

    if (val > 2.0) {
        printf ("Warning: Cut of value %f in add_exact\n", val);
        fflush (stdout);
        goto CLEANUP;
    }

    rval = CCtsp_array_to_subtour (&c, cutarray, count);
    if (rval) {
        fprintf (stderr, "CCtsp_array_to_subtour failed\n");
        rval = 1; goto CLEANUP;
    }
    c->next = p->cuts;
    p->cuts = c;
    p->cutcount++;

CLEANUP:

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_tighten_lp (CCtsp_lpcuts *cuts, CCtsp_tighten_info *stats,
        CCtsp_lpcut_in **cutsout, int *cutcount, int ncount, int ecount,
        int *elist, double *x, double testtol, int maxcuts)
#else
int CCtsp_tighten_lp (cuts, stats, cutsout, cutcount, ncount, ecount, elist, x,
        testtol, maxcuts)
CCtsp_lpcuts *cuts;
CCtsp_tighten_info *stats;
CCtsp_lpcut_in **cutsout;
int *cutcount;
int ncount, ecount;
int *elist;
double *x;
double testtol;
int maxcuts;
#endif
{
    CCtsp_lpcut_in new, old;
    CCtsp_lpcut_in *c;
    int i;
    int rval = 0;
    double improve;
    CCtsp_lpgraph lg;
    double *newx = (double *) NULL;
    int *newelist = (int *) NULL;
    int newecount;
    CCtsp_lpcut_in **clist = (CCtsp_lpcut_in **) NULL;
    double *vlist = (double *) NULL;
    double maxviol = 0.0;
    int clistsize = 0, vlistsize = 0;
    int count = 0;
    int *perm = (int *) NULL;
    double szeit = CCutil_zeit ();
    double *cutval = (double *) NULL;

    *cutcount = 0;
    if (!cuts || !cuts->cutcount) return 0;


    rval = grab_nonzero_x (ecount, elist, x, &newecount, &newelist, &newx,
                           X_FLUFF);
    if (rval) {
        fprintf (stderr, "grab_nonzero_x failed\n"); goto CLEANUP;
    }

    cutval = CC_SAFE_MALLOC (cuts->cutcount, double);
    if (!cutval) {
        fprintf (stderr, "out of memory in CCtsp_tighten_lp\n");
        rval = 1; goto CLEANUP;
    }
    rval = CCtsp_price_cuts (cuts, ncount, newecount, newelist, newx, cutval);
    if (rval) {
        fprintf (stderr, "CCtsp_price_cuts failed\n"); goto CLEANUP;
    }

    CCtsp_init_lpgraph_struct (&lg);

    rval = CCtsp_build_lpgraph (&lg, ncount, newecount, newelist, (int *) NULL);
    if (rval) {
        fprintf (stderr, "CCtsp_build_lpgraph failed\n"); goto CLEANUP;
    }
    CC_FREE (newelist, int);
    rval = CCtsp_build_lpadj (&lg, 0, newecount);
    if (rval) {
        fprintf (stderr, "CCtsp_build_lpadj failed\n"); goto CLEANUP;
    }

    for (i = 0; i < cuts->cutcount; i++) {
        if (cutval[i] < testtol && !cuts->cuts[i].branch) {
            rval = CCtsp_lpcut_to_lpcut_in (cuts, &(cuts->cuts[i]), &old);
            if (rval) {
                fprintf (stderr, "CCtsp_lpcut_to_lpcut_in failed\n");
                goto CLEANUP;
            }
            rval = CCtsp_tighten_lpcut_in (&lg, &old, newx, &new, stats,
                                           &improve);
            if (rval) {
                fprintf (stderr, "CCtsp_tighten_lpcut failed\n");
                goto CLEANUP;
            }
            CCtsp_free_lpcut_in (&old);

            if (improve - cutval[i] > CCtsp_MIN_VIOL) {
                c = CC_SAFE_MALLOC (1, CCtsp_lpcut_in);
                if (!c) {
                    fprintf (stderr, "out of memory in CCtsp_tighten_lp\n");
                    rval = 1; goto CLEANUP;
                }
                *c = new;
                if (count >= clistsize) {
                    rval = CCutil_reallocrus_scale ((void **) &clist,
                                    &clistsize,
                                    count + 1, 1.3, sizeof (CCtsp_lpcut_in *));
                    if (rval) {
                        fprintf (stderr, "CCutil_reallocrus_scale failed\n");
                        rval = 1; goto CLEANUP;
                    }
                }
                if (count >= vlistsize) {
                    rval = CCutil_reallocrus_scale ((void **) &vlist,
                                    &vlistsize,
                                    count + 1, 1.3, sizeof (double));
                    if (rval) {
                        fprintf (stderr, "CCutil_reallocrus_scale failed\n");
                        rval = 1; goto CLEANUP;
                    }
                }
                clist[count] = c;
                vlist[count] = cutval[i] - improve;
                count++;
            } else {
                CCtsp_free_lpcut_in (&new);
            }
        }
    }

    if (count) {
        perm = CC_SAFE_MALLOC (count, int);
        if (!perm) {
            fprintf (stderr, "out of memory in CCtsp_tighten_lp\n");
            rval = 1; goto CLEANUP;
        }
        for (i = 0; i < count; i++) {
            perm[i] = i;
        }
        if (count > maxcuts) {
            CCutil_rselect (perm, 0, count - 1, maxcuts, vlist);
            for (i = maxcuts; i < count; i++) {
                CCtsp_free_lpcut_in (clist[perm[i]]);
            }
            count = maxcuts;
        }
        for (i = 0; i < count; i++) {
            if (vlist[perm[i]] < maxviol)
                maxviol = vlist[perm[i]];
            clist[perm[i]]->next = *cutsout;
            *cutsout = clist[perm[i]];
        }
    }

    *cutcount = count;
    printf ("%d tighten cuts, %.5f max violation (%.2f seconds)\n",
                  count, -maxviol, CCutil_zeit () - szeit);
    fflush (stdout);

CLEANUP:

    CC_IFFREE (newelist, int);
    CC_IFFREE (newx, double);
    CC_IFFREE (clist, CCtsp_lpcut_in *);
    CC_IFFREE (vlist, double);
    CC_IFFREE (perm, int);
    CC_IFFREE (cutval, double);
    CCtsp_free_lpgraph (&lg);
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_teething_lp (CCtsp_lpcuts *cuts, CCtsp_tighten_info *stats,
        CCtsp_lpcut_in **cutsout, int *cutcount, int ncount, int ecount,
        int *elist, double *x, double testtol, int maxcuts)
#else
int CCtsp_teething_lp (cuts, stats, cutsout, cutcount, ncount, ecount,
        elist, x, testtol, maxcuts)
CCtsp_lpcuts *cuts;
CCtsp_tighten_info *stats;
CCtsp_lpcut_in **cutsout;
int *cutcount;
int ncount, ecount;
int *elist;
double *x;
double testtol;
int maxcuts;
#endif
{
    int rval = 0;

    rval = work_on_combs_in_lp (cuts, stats, cutsout, cutcount, ncount, ecount,
                                elist, x, testtol, maxcuts,
                                CCtsp_teething);
    if (rval) {
        fprintf (stderr, "work_on_combs_in_lp failed\n");
        goto CLEANUP;
    }

CLEANUP:

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static int work_on_combs_in_lp (CCtsp_lpcuts *cuts, CCtsp_tighten_info *stats,
        CCtsp_lpcut_in **cutsout, int *cutcount, int ncount, int ecount,
        int *elist, double *x, double testtol, int maxcuts,
        int (*doit_fn) (CCtsp_lpgraph *, double *, CCtsp_lpcut_in *,
        CCtsp_lpcut_in **))
#else
static int work_on_combs_in_lp (cuts, stats, cutsout, cutcount, ncount, ecount,
        elist, x, testtol, maxcuts, doit_fn)
CCtsp_lpcuts *cuts;
CCtsp_tighten_info *stats;
CCtsp_lpcut_in **cutsout;
int *cutcount;
int ncount, ecount;
int *elist;
double *x;
double testtol;
int maxcuts;
int (*doit_fn) ();
#endif
{
    CCtsp_lpcut_in new, old;
    CCtsp_lpcut_in *c  = (CCtsp_lpcut_in *) NULL;
    CCtsp_lpcut_in *dd = (CCtsp_lpcut_in *) NULL;
    int i, test;
    int rval = 0;
    double improve, newslack;
    CCtsp_lpgraph lg;
    double *newx = (double *) NULL;
    int *newelist = (int *) NULL;
    int newecount;
    CCtsp_lpcut_in **clist = (CCtsp_lpcut_in **) NULL;
    double *vlist = (double *) NULL;
    double maxviol = 0.0;
    int clistsize = 0, vlistsize = 0;
    int count = 0;
    int *perm = (int *) NULL;
    double *cutval = (double *) NULL;
    double szeit = CCutil_zeit ();

    *cutcount = 0;
    if (!cuts || !cuts->cutcount) return 0;

    rval = grab_nonzero_x (ecount, elist, x, &newecount, &newelist, &newx,
                           X_FLUFF);
    if (rval) {
        fprintf (stderr, "grab_nonzero_x failed\n"); goto CLEANUP;
    }

    cutval = CC_SAFE_MALLOC (cuts->cutcount, double);
    if (!cutval) {
        fprintf (stderr, "out of memory in CCtsp_tighten_lp\n");
        rval = 1; goto CLEANUP;
    }
    rval = CCtsp_price_cuts (cuts, ncount, newecount, newelist, newx, cutval);
    if (rval) {
        fprintf (stderr, "CCtsp_price_cuts failed\n"); goto CLEANUP;
    }

    CCtsp_init_lpgraph_struct (&lg);
    rval = CCtsp_build_lpgraph (&lg, ncount, newecount, newelist, (int *) NULL);
    if (rval) {
        fprintf (stderr, "CCtsp_build_lpgraph failed\n"); goto CLEANUP;
    }
    CC_FREE (newelist, int);
    rval = CCtsp_build_lpadj (&lg, 0, newecount);
    if (rval) {
        fprintf (stderr, "CCtsp_build_lpadj failed\n"); goto CLEANUP;
    }

    for (i = 0; i < cuts->cutcount; i++) {
        if (cuts->cuts[i].branch || cuts->cuts[i].cliquecount % 2 ||
            cuts->cuts[i].cliquecount < 4 || cutval[i] >= testtol) {
            continue;
        }
        rval = CCtsp_lpcut_to_lpcut_in (cuts, &(cuts->cuts[i]), &old);
        if (rval) {
            fprintf (stderr, "CCtsp_lpcut_to_lpcut_in failed\n"); goto CLEANUP;
        }
        rval = CCtsp_test_pure_comb (ncount, &old, &test, (int *) NULL);
        if (rval) {
            fprintf (stderr, "CCtsp_test_pure_comb failed\n");
            CCtsp_free_lpcut_in (&old);
            goto CLEANUP;
        }
        if (test == 1) {
            rval = doit_fn (&lg, newx, &old, &dd);
            if (rval) {
                fprintf (stderr, "doit_fn failed\n"); goto CLEANUP;
            }
            CCtsp_free_lpcut_in (&old);
            if (dd) {
                rval = CCtsp_tighten_lpcut_in (&lg, dd, newx, &new,
                                               stats, &improve);
                if (rval) {
                    fprintf (stderr, "CCtsp_tighten_lpcut failed\n");
                    goto CLEANUP;
                }
                CCtsp_free_lpcut_in (dd);
                CC_FREE (dd, CCtsp_lpcut_in);

                newslack = CCtsp_cutprice (&lg, &new, newx);
                if (-newslack > CCtsp_MIN_VIOL) {
                    c = CC_SAFE_MALLOC (1, CCtsp_lpcut_in);
                    if (!c) {
                        fprintf (stderr,
                           "out of memory in work_on_combs_in_lp\n");
                        CCtsp_free_lpcut_in (&new);
                        rval = 1; goto CLEANUP;
                    }
                    *c = new;
                    if (count >= clistsize) {
                        rval = CCutil_reallocrus_scale ((void **) &clist,
                                &clistsize, count + 1, 1.3,
                                sizeof (CCtsp_lpcut_in *));
                        if (rval) {
                            fprintf (stderr,
                                  "CCutil_reallocrus_scale failed\n");
                            rval = 1; goto CLEANUP;
                        }
                    }
                    if (count >= vlistsize) {
                        rval = CCutil_reallocrus_scale ((void **) &vlist,
                                 &vlistsize, count + 1, 1.3,
                                 sizeof (double));
                        if (rval) {
                            fprintf (stderr,
                                  "CCutil_reallocrus_scale failed\n");
                            rval = 1; goto CLEANUP;
                        }
                    }
                    clist[count] = c;
                    vlist[count] = newslack;
                    count++;
                } else {
                    CCtsp_free_lpcut_in (&new);
                }
            }
        } else {
            CCtsp_free_lpcut_in (&old);
        }
    }

    if (count) {
        perm = CC_SAFE_MALLOC (count, int);
        if (!perm) {
            fprintf (stderr, "out of memory in work_on_combs_in_lp\n");
            rval = 1; goto CLEANUP;
        }
        for (i = 0; i < count; i++) {
            perm[i] = i;
        }
        if (count > maxcuts) {
            CCutil_rselect (perm, 0, count - 1, maxcuts, vlist);
            for (i = maxcuts; i < count; i++) {
                CCtsp_free_lpcut_in (clist[perm[i]]);
            }
            count = maxcuts;
        }
        for (i = 0; i < count; i++) {
            if (vlist[perm[i]] < maxviol)
                maxviol = vlist[perm[i]];
            clist[perm[i]]->next = *cutsout;
            *cutsout = clist[perm[i]];
        }
    }

    *cutcount = count;
    printf ("%d cuts, %.5f max violation (%.2f seconds)\n", count, -maxviol,
                         CCutil_zeit () - szeit);
    fflush (stdout);

CLEANUP:

    CC_IFFREE (newelist, int);
    CC_IFFREE (newx, double);
    CC_IFFREE (clist, CCtsp_lpcut_in *);
    CC_IFFREE (vlist, double);
    CC_IFFREE (perm, int);
    CC_IFFREE (cutval, double);
    CCtsp_free_lpgraph (&lg);
    if (dd) {
        CCtsp_free_lpcut_in (dd);
    }
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
void CCtsp_init_lpcut_in (CCtsp_lpcut_in *c)
#else
void CCtsp_init_lpcut_in (c)
CCtsp_lpcut_in *c;
#endif
{
    if (c) {
        c->handlecount = 0;
        c->cliquecount = 0;
        c->rhs         = 0;
        c->sense       = 'X';
        c->branch      = 0;
        c->cliques     = (CCtsp_lpclique *) NULL;
        c->next        = (CCtsp_lpcut_in *) NULL;
        c->prev        = (CCtsp_lpcut_in *) NULL;
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_copy_lpcut_in (CCtsp_lpcut_in *c, CCtsp_lpcut_in *new)
#else
int CCtsp_copy_lpcut_in (c, new)
CCtsp_lpcut_in *c;
CCtsp_lpcut_in *new;
#endif
{
    int rval = 0;
    int i;

    CCtsp_init_lpcut_in (new);

    new->handlecount = c->handlecount;
    new->cliquecount = c->cliquecount;
    new->rhs         = c->rhs;
    new->sense       = c->sense;

    if (c->cliquecount) {
        new->cliques = CC_SAFE_MALLOC (c->cliquecount, CCtsp_lpclique);
        if (!new->cliques) {
            fprintf (stderr, "out of memory in CCtsp_copy_lpcut_in\n");
            rval = 1; goto CLEANUP;
        }
        for (i = 0; i < c->cliquecount; i++) {
            rval = CCtsp_copy_lpclique (&c->cliques[i], &new->cliques[i]);
            if (rval) {
                fprintf (stderr, "CCtsp_copy_lpclique failed\n");
                goto CLEANUP;
            }
        }
    }

CLEANUP:

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_segment_to_subtour (CCtsp_lpcut_in **cut, int a, int b)
#else
int CCtsp_segment_to_subtour (cut, a, b)
CCtsp_lpcut_in **cut;
int a, b;
#endif
{
    int rval = 0;
    int list[2];
    int t;
    CCtsp_lpcut_in *c = (CCtsp_lpcut_in *) NULL;

    *cut = (CCtsp_lpcut_in *) NULL;
    if (a > b) CC_SWAP (a, b, t);

    c = CC_SAFE_MALLOC (1, CCtsp_lpcut_in);
    if (!c) {
        fprintf (stderr, "out of memory in CCtsp_segment_to_subtour\n");
        rval = 1; goto CLEANUP;
    }
    CCtsp_init_lpcut_in (c);

    c->cliquecount = 1;
    c->handlecount = 0;
    c->cliques = CC_SAFE_MALLOC (1, CCtsp_lpclique);
    if (!c->cliques) {
        fprintf (stderr, "out of memory in CCtsp_segment_to_subtour\n");
        rval = 1; goto CLEANUP;
    }

    list[0] = a;
    list[1] = b;
    rval = CCtsp_seglist_to_lpclique (1, list, &(c->cliques[0]));
    if (rval) {
        goto CLEANUP;
    }
    c->rhs = CCtsp_CUTRHS(c);
    c->sense = 'G';
    c->branch = 0;

    *cut = c;

CLEANUP:

    if (rval) {
        if (c) {
            CCtsp_free_lpcut_in (c);
            CC_FREE (c, CCtsp_lpcut_in);
        }
    }
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_array_to_subtour (CCtsp_lpcut_in **cut, int *ar, int acount)
#else
int CCtsp_array_to_subtour (cut, ar, acount)
CCtsp_lpcut_in **cut;
int *ar;
int acount;
#endif
{
    int rval = 0;
    CCtsp_lpcut_in *c = (CCtsp_lpcut_in *) NULL;

    *cut = (CCtsp_lpcut_in *) NULL;

    c = CC_SAFE_MALLOC (1, CCtsp_lpcut_in);
    if (!c) {
        fprintf (stderr, "out of memory in CCtsp_array_to_subtour\n");
        rval = 1; goto CLEANUP;
    }
    CCtsp_init_lpcut_in (c);

    c->cliquecount = 1;
    c->handlecount = 0;
    c->cliques = CC_SAFE_MALLOC (1, CCtsp_lpclique);
    if (!c->cliques) {
        fprintf (stderr, "out of memory in CCtsp_array_to_subtour\n");
        rval = 1; goto CLEANUP;
    }

    rval = CCtsp_array_to_lpclique (ar, acount, &(c->cliques[0]));
    if (rval) {
        goto CLEANUP;
    }
    c->rhs = CCtsp_CUTRHS(c);
    c->sense = 'G';
    c->branch = 0;

    *cut = c;

CLEANUP:

    if (rval) {
        if (c) {
            CCtsp_free_lpcut_in (c);
            CC_FREE (c, CCtsp_lpcut_in);
        }
    }
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
void CCtsp_init_lpclique (CCtsp_lpclique *c)
#else
void CCtsp_init_lpclique (c)
CCtsp_lpclique *c;
#endif
{
    if (c) {
        c->segcount = 0;
        c->nodes = (CCtsp_segment *) NULL;
        c->hashnext = 0;
        c->refcount = 0;
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_array_to_lpclique (int *ar, int acount, CCtsp_lpclique *cliq)
#else
int CCtsp_array_to_lpclique (ar, acount, cliq)
int *ar;
int acount;
CCtsp_lpclique *cliq;
#endif
{
    int i, nseg;

    /* Function will alter the order on the array */

    CCutil_int_array_quicksort (ar, acount);
    nseg = 0;
    i = 0;
    while (i < acount) {
        while (i < (acount - 1) && ar[i + 1] == (ar[i] + 1))
            i++;
        i++;
        nseg++;
    }

    cliq->nodes = CC_SAFE_MALLOC (nseg, CCtsp_segment);
    if (!cliq->nodes) {
        fprintf (stderr, "out of memory in CCtsp_array_to_lpclique\n");
        return 1;
    }
    cliq->segcount = nseg;

    nseg = 0;
    i = 0;
    while (i < acount) {
        cliq->nodes[nseg].lo = ar[i];
        while (i < (acount - 1) && ar[i + 1] == (ar[i] + 1))
            i++;
        cliq->nodes[nseg].hi = ar[i++];
        nseg++;
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_seglist_to_lpclique (int nseg, int *list, CCtsp_lpclique *cliq)
#else
int CCtsp_seglist_to_lpclique (nseg, list, cliq)
int nseg;
int *list;
CCtsp_lpclique *cliq;
#endif
{
    int i;
    int *perm = (int *) NULL;
    int *len  = (int *) NULL;
    int rval = 0;

    perm = CC_SAFE_MALLOC (nseg, int);
    len  = CC_SAFE_MALLOC (nseg, int);
    if (!perm || !len) {
        fprintf (stderr, "out of memory in CCtsp_seglist_to_lpclique\n");
        rval = 1; goto CLEANUP;
    }
    for (i = 0; i < nseg; i++) {
        perm[i] = i;
        len[i] = list[2*i];
    }
    CCutil_int_perm_quicksort (perm, len, nseg);

    cliq->nodes = CC_SAFE_MALLOC (nseg, CCtsp_segment);
    if (!cliq->nodes) {
        fprintf (stderr, "out of memory in CCtsp_seglist_to_lpclique\n");
        rval = 1; goto CLEANUP;
    }
    cliq->segcount = nseg;

    for (i = 0; i < nseg; i++) {
        cliq->nodes[i].lo = list[2*perm[i]];
        cliq->nodes[i].hi = list[2*perm[i]+1];
    }

    nseg = 0;

CLEANUP:

    CC_IFFREE (perm, int);
    CC_IFFREE (len, int);

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_add_node_to_lpclique (CCtsp_lpclique *cin, CCtsp_lpclique *cout,
        int n)
#else
int CCtsp_add_node_to_lpclique (cin, cout, n)
CCtsp_lpclique *cin;
CCtsp_lpclique *cout;
int n;
#endif
{
    int count = 0;
    int rval  = 0;
    int *ar   = (int *) NULL;
    int i, j;

    CCtsp_init_lpclique (cout);

    for (i = 0; i < cin->segcount; i++) {
        count += (cin->nodes[i].hi - cin->nodes[i].lo + 1);
        if (cin->nodes[i].lo <= n && n <= cin->nodes[i].hi) {
            fprintf (stderr, "node already in clique\n");
            rval = 1; goto CLEANUP;
        }
    }

    ar = CC_SAFE_MALLOC (count + 1, int);
    if (!ar) {
        fprintf (stderr, "out of memory in CCtsp_add_node_to_lpclique\n");
        rval = 1; goto CLEANUP;
    }

    count = 0;
    for (i = 0; i < cin->segcount; i++) {
        for (j = cin->nodes[i].lo; j <= cin->nodes[i].hi; j++) {
            ar[count++] = j;
        }
    }
    ar[count++] = n;
    rval = CCtsp_array_to_lpclique (ar, count, cout);
    if (rval) {
        fprintf (stderr, "CCtsp_array_to_lpclique failed\n"); goto CLEANUP;
    }

CLEANUP:

    CC_IFFREE (ar, int);
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_delete_node_from_lpclique (CCtsp_lpclique *cin,
        CCtsp_lpclique *cout, int n)
#else
int CCtsp_delete_node_from_lpclique (cin, cout, n)
CCtsp_lpclique *cin;
CCtsp_lpclique *cout;
int n;
#endif
{
    int count = 0;
    int rval  = 0;
    int *ar   = (int *) NULL;
    int i, j, hit = 0;

    CCtsp_init_lpclique (cout);

    for (i = 0; i < cin->segcount; i++) {
        count += (cin->nodes[i].hi - cin->nodes[i].lo + 1);
        if (cin->nodes[i].lo <= n && n <= cin->nodes[i].hi) {
            hit++;
        }
    }
    if (!hit) {
        fprintf (stderr, "node is not in clique\n");
        rval = 1; goto CLEANUP;
    }

    ar = CC_SAFE_MALLOC (count, int);
    if (!ar) {
        fprintf (stderr, "out of memory in CCtsp_delete_node_from_lpclique\n");
        rval = 1; goto CLEANUP;
    }

    count = 0;
    for (i = 0; i < cin->segcount; i++) {
        for (j = cin->nodes[i].lo; j <= cin->nodes[i].hi; j++) {
            if (j != n) {
                ar[count++] = j;
            }
        }
    }
    rval = CCtsp_array_to_lpclique (ar, count, cout);
    if (rval) {
        fprintf (stderr, "CCtsp_array_to_lpclique failed\n"); goto CLEANUP;
    }

CLEANUP:

    CC_IFFREE (ar, int);
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
void CCtsp_print_lpcut_in (CCtsp_lpcut_in *c)
#else
void CCtsp_print_lpcut_in (c)
CCtsp_lpcut_in *c;
#endif
{
    int i;

    if (c->cliquecount == 1) {
        printf ("Subtour\n");
        printf ("      ");
        CCtsp_print_lpclique (&(c->cliques[0]));
    } else {
        if (c->handlecount == 1) {
            printf ("Comb\n");
            printf ("  Handle\n");
        } else {
            printf ("Clique Tree or Wild Thing\n");
            printf ("  Handles:\n");
        }
        for (i = 0; i < c->handlecount; i++) {
            printf ("      ");
            CCtsp_print_lpclique (&(c->cliques[i]));
        }
        if (c->cliquecount > c->handlecount) {
            printf ("  Teeth\n");
            for (; i < c->cliquecount; i++) {
                printf ("      ");
                CCtsp_print_lpclique (&(c->cliques[i]));
            }
        }
    }
    printf ("\n"); fflush (stdout);
}

#ifdef CC_PROTOTYPE_ANSI
void CCtsp_print_lpclique (CCtsp_lpclique *c)
#else
void CCtsp_print_lpclique (c)
CCtsp_lpclique *c;
#endif
{
    int i;

    if (c->segcount == 0) {
        printf ("Empty Clique\n"); fflush (stdout);
    } else {
        for (i = 0; i < c->segcount; i++) {
            printf ("%d->%d ", c->nodes[i].lo, c->nodes[i].hi);
        }
        printf ("\n"); fflush (stdout);
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_lpcut_to_lpcut_in (CCtsp_lpcuts *cuts, CCtsp_lpcut *c,
        CCtsp_lpcut_in *new)
#else
int CCtsp_lpcut_to_lpcut_in (cuts, c, new)
CCtsp_lpcuts *cuts;
CCtsp_lpcut *c;
CCtsp_lpcut_in *new;
#endif
{
    int i, k;
    CCtsp_lpclique *cl;
    int rval = 0;

    new->handlecount = c->handlecount;
    new->cliquecount = c->cliquecount;
    new->rhs = c->rhs;
    new->sense = c->sense;
    new->branch = c->branch;
    new->next =  (CCtsp_lpcut_in *) NULL;
    new->prev = (CCtsp_lpcut_in *) NULL;

    new->cliques = CC_SAFE_MALLOC (c->cliquecount, CCtsp_lpclique);
    if (!new->cliques) {
        fprintf (stderr, "out of memory in CCtsp_lpcut_to_lpcut_in\n");
        return 1;
    }

    for (i = 0; i < c->cliquecount; i++) {
        cl = &(cuts->cliques[c->cliques[i]]);
        rval = CCtsp_copy_lpclique (cl, &new->cliques[i]);
        if (rval) {
            fprintf (stderr, "CCtsp_copy_lpclique failed\n");
            for (k = 0; k < i; k++) {
                CC_FREE (new->cliques[k].nodes, CCtsp_segment);
            }
            CC_FREE (new->cliques, CCtsp_lpclique);
            return 1;
        }
    }

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_copy_lpclique (CCtsp_lpclique *c, CCtsp_lpclique *new)
#else
int CCtsp_copy_lpclique (c, new)
CCtsp_lpclique *c;
CCtsp_lpclique *new;
#endif
{
    int k;
    CCtsp_segment *s = (CCtsp_segment *) NULL;

    CCtsp_init_lpclique (new);
    if (c->segcount) {
        s = CC_SAFE_MALLOC (c->segcount, CCtsp_segment);
        if (!s) {
            fprintf (stderr, "out of memory in copy_lpclique\n");
            return 1;
        }
        for (k = 0; k < c->segcount; k++) {
            s[k].lo = c->nodes[k].lo;
            s[k].hi = c->nodes[k].hi;
        }
    }
    new->segcount = c->segcount;
    new->nodes = s;
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
void CCtsp_lpclique_compare (CCtsp_lpclique *a, CCtsp_lpclique *b, int *diff)
#else
void CCtsp_lpclique_compare (a, b, diff)
CCtsp_lpclique *a, *b;
int *diff;
#endif
{
    int i;

    if (a->segcount != b->segcount) {
        *diff = 1; return;
    } else {
        for (i = 0; i < a->segcount; i++) {
            if (a->nodes[i].lo != b->nodes[i].lo) {
                *diff = 1; return;
            }
            if (a->nodes[i].hi != b->nodes[i].hi) {
                *diff = 1; return;
            }
        }
    }
    *diff = 0; return;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_file_cuts (char *cutfile, CCtsp_lpcut_in **cuts, int *cutcount,
        int ncount, int *tour)
#else
int CCtsp_file_cuts (cutfile, cuts, cutcount, ncount, tour)
char *cutfile;
CCtsp_lpcut_in **cuts;
int *cutcount;
int ncount;
int *tour;
#endif
{
    FILE *in = (FILE *) NULL;
    int *inv = (int *) NULL;
    CCtsp_lpcut_in *c;
    int i, j, k;
    int ncliques, nhandles, size;
    int *icliq = (int *) NULL;
    int rval = 0;

    *cutcount = 0;

    in = fopen (cutfile, "r");
    if  (in == (FILE *) NULL) {
        fprintf (stderr, "unable to open %s for reading\n", cutfile);
        return 0;
    }

    inv = CC_SAFE_MALLOC (ncount, int);
    if (!inv) {
        fprintf (stderr, "out of memory in CCtsp_file_cuts\n");
        rval = 1; goto CLEANUP;
    }
    for (i = 0; i < ncount; i++) {
        inv[tour[i]] = i;
    }

    while (fscanf (in, "%d", &ncliques) != EOF) {
        c = CC_SAFE_MALLOC (1, CCtsp_lpcut_in);
        if (!c) {
            fprintf (stderr, "out of memory in CCtsp_file_cuts\n");
            rval = 1; goto CLEANUP;
        }
        c->cliquecount = ncliques;
        c->cliques = CC_SAFE_MALLOC (ncliques, CCtsp_lpclique);
        if (!c->cliques) {
            fprintf (stderr, "out of memory in CCtsp_file_cuts\n");
            rval = 1; goto CLEANUP;
        }
        fscanf (in, "%d", &nhandles);
        c->handlecount = nhandles;
        for (i = 0; i < ncliques; i++) {
            fscanf (in, "%d", &size);
            icliq = CC_SAFE_MALLOC (size, int);
            if (!icliq) {
                fprintf (stderr, "out of memory in CCtsp_file_cuts\n");
                rval = 1; goto CLEANUP;
            }
            for (j = 0; j < size; j++) {
                fscanf (in, "%d", &k);
                icliq[j] = inv[k];
            }
            rval = CCtsp_array_to_lpclique (icliq, size, &(c->cliques[i]));
            if (rval) {
                fprintf (stderr, "CCtsp_array_to_lpclique failed\n");
                goto CLEANUP;
            }
            CC_FREE (icliq, int);
        }
        fscanf (in, "%d", &(c->rhs));
        c->sense = 'G';
        c->branch = 0;
        c->next = *cuts;
        *cuts = c;
        (*cutcount)++;
    }

CLEANUP:

    CC_IFFREE (inv, int);
    fclose (in);
    return  rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_file_cuts_write (char *cutfile, CCtsp_lpcuts *cuts, int *tour)
#else
int CCtsp_file_cuts_write (cutfile, cuts, tour)
char *cutfile;
CCtsp_lpcuts *cuts;
int *tour;
#endif
{
    FILE *out = (FILE *) NULL;
    int i, j, k, p;
    int cutcount = cuts->cutcount;
    CCtsp_lpcut *c;
    CCtsp_lpclique *cl;
    int isize;

    out = fopen (cutfile, "w");
    if  (out == (FILE *) NULL) {
        fprintf (stderr, "unable to open %s for writing\n", cutfile);
        return 1;
    }

    for (i = 0; i < cutcount; i++) {
        c = &cuts->cuts[i];
        if (!c->branch) {
            fprintf (out, "%d %d\n", c->cliquecount, c->handlecount);
            for (j = 0; j < c->cliquecount; j++) {
                cl = &cuts->cliques[c->cliques[j]];
                for (k = 0, isize = 0; k < cl->segcount; k++) {
                    isize += (cl->nodes[k].hi - cl->nodes[k].lo + 1);
                }
                fprintf (out, "%d  ", isize);
                for (k = 0; k < cl->segcount; k++) {
                    for (p = cl->nodes[k].lo; p <= cl->nodes[k].hi; p++) {
                        fprintf (out, "%d ", tour[p]);
                    }
                }
                fprintf (out, "\n");
            }
            fprintf (out, "%d\n", c->rhs);
        }
    }

    fclose (out);
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_buildcut_begin (cutinfo *cuts, int init_cliquecount)
#else
int CCtsp_buildcut_begin (cuts, init_cliquecount)
cutinfo *cuts;
int init_cliquecount;
#endif
{
    cuts->current = CC_SAFE_MALLOC (1, CCtsp_lpcut_in);
    if (!cuts->current) return -1;
    cuts->current->cliquecount = 0;
    cuts->current->handlecount = 0;
    cuts->current->rhs = 0;
    cuts->current->sense = 'G';
    cuts->current->branch = 0;
    cuts->current->cliques = CC_SAFE_MALLOC (init_cliquecount, CCtsp_lpclique);
    if (!cuts->current->cliques) {
        CC_FREE (cuts->current, CCtsp_lpcut_in);
        return -1;
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_buildcut_addclique (cutinfo *cuts, int *arr, int size, int handle)
#else
int CCtsp_buildcut_addclique (cuts, arr, size, handle)
cutinfo *cuts;
int *arr;
int size;
int handle;
#endif
{
    int i;
    int *newarr = (int *) NULL;
    int newsize;
    int rval;
    CCtsp_lpcut_in *c = cuts->current;

    if (!c) {
        fprintf (stderr, "Trying to add to nonexistent clique\n");
        return -1;
    }

    rval = CCcut_SRK_expand (&cuts->expand, arr, size, &newarr, &newsize);
    if (rval) {
        fprintf (stderr, "CCcut_SRK_expand failed\n");
        CCtsp_buildcut_abort (cuts);
        return rval;
    }

    rval = CCutil_reallocrus_count ((void **) &(c->cliques), c->cliquecount+1,
                             sizeof (c->cliques[0]));
    if (rval) {
        fprintf (stderr, "couldn't realloc cliques\n");
        CC_IFFREE (newarr, int);
        CCtsp_buildcut_abort (cuts);
        return rval;
    }

    if (handle) {
        for (i=c->cliquecount; i>c->handlecount; i--) {
            c->cliques[i] = c->cliques[i-1];
        }
        i = c->handlecount;
        c->handlecount++;
    } else {
        i = c->cliquecount;
    }

    rval = CCtsp_array_to_lpclique (newarr, newsize, &(c->cliques[i]));
    if (rval) {
        fprintf (stderr, "CCtsp_array_to_lpclique failed\n");
        CC_IFFREE (newarr, int);
        CCtsp_buildcut_abort (cuts);
        return rval;
    }
    c->cliquecount++;
    CC_IFFREE (newarr, int);
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
void CCtsp_buildcut_abort (cutinfo *cuts)
#else
void CCtsp_buildcut_abort (cuts)
cutinfo *cuts;
#endif
{
    int i;
    CCtsp_lpcut_in *c = cuts->current;

    if (c) {
        for (i=0; i<c->cliquecount; i++) {
            CC_FREE (c->cliques[i].nodes, CCtsp_segment);
        }
        CC_FREE (c->cliques, CCtsp_lpclique);
        CC_FREE (cuts->current, CCtsp_lpcut_in);
    }
}

#ifdef CC_PROTOTYPE_ANSI
void CCtsp_buildcut_finish (cutinfo *cuts, int rhs)
#else
void CCtsp_buildcut_finish (cuts, rhs)
cutinfo *cuts;
int rhs;
#endif
{
    CCtsp_lpcut_in *c = cuts->current;

#ifdef DUMP_BUILDCUT
    {
        int i, j, k;
        printf ("new buildcut (%d %d):", c->cliquecount, c->handlecount);
        for (i=0; i<c->cliquecount; i++) {
            printf (" (");
            for (j=0; j<c->cliques[i].segcount; j++) {
                for (k=c->cliques[i].nodes[j].lo; k<=c->cliques[i].nodes[j].hi;
                     k++) {
                    printf ("%d ",k);
                }
            }
            printf (")");
        }
        printf (" >= %d\n", rhs);
        fflush (stdout);
    }
#endif

    c->rhs = rhs;
    c->next = *cuts->clist;
    (*cuts->clist) = c;
    cuts->current = (CCtsp_lpcut_in *) NULL;
    (*cuts->cutcount)++;
}

#ifdef CC_PROTOTYPE_ANSI
static int grab_nonzero_x (int ecount, int *elist, double *x,
        int *new_ecount, int **new_elist, double **new_x, double tol)
#else
static int grab_nonzero_x (ecount, elist, x, new_ecount, new_elist, new_x, tol)
int ecount;
int *elist;
double *x;
int *new_ecount;
int **new_elist;
double **new_x;
double tol;
#endif
{
    int i;
    int count;

    *new_ecount = 0;
    *new_elist = (int *) NULL;
    *new_x = (double *) NULL;

    for (i = 0, count = 0; i < ecount; i++) {
        if (x[i] > tol) {
            count++;
        }
    }

    *new_elist = CC_SAFE_MALLOC (2*count, int);
    *new_x = CC_SAFE_MALLOC (count, double);
    if (!(*new_elist) || !(*new_x)) {
        fprintf (stderr, "out of memory in grab_nonzero_x\n");
        CC_IFFREE (*new_elist, int);
        CC_IFFREE (*new_x, double);
        return 1;
    }

    for (i = 0, count = 0; i < ecount; i++) {
        if (x[i] > tol) {
            (*new_elist)[2*count] = elist[2*i];
            (*new_elist)[2*count+1] = elist[2*i+1];
            (*new_x)[count] = x[i];
            count++;
        }
    }
    *new_ecount = count;
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_test_pure_comb (int ncount, CCtsp_lpcut_in *c, int *yes_no,
        int *handle)
#else
int CCtsp_test_pure_comb (ncount, c, yes_no, handle)
int ncount;
CCtsp_lpcut_in *c;
int *yes_no;
int *handle;
#endif
{
    int rval = 0;
    int i, marked, ihandle;
    int *marks = (int *) NULL;

    *yes_no = 0;
    if (handle) *handle = -1;

    if (c->cliquecount < 4 || c->cliquecount % 2 ||
        c->sense != 'G') {
        goto CLEANUP;
    }

    rval = CCtsp_find_pure_handle (ncount, c, &ihandle);
    if (rval) {
        fprintf (stderr, "CCtsp_find_pure_handle failed\n");
        goto CLEANUP;
    }
    if (ihandle == -1) goto CLEANUP;

    marks = CC_SAFE_MALLOC (ncount, int);
    if (!marks) {
        fprintf (stderr, "out of memory in CCtsp_test_pure_comb\n");
        rval = 1; goto CLEANUP;
    }
    CCtsp_mark_cut (c, marks, 0);

    CCtsp_mark_clique (&c->cliques[ihandle], marks, 1);
    for (i = 0; i < c->cliquecount; i++) {
        if (i != ihandle) {
            CCtsp_is_clique_marked (&c->cliques[i], marks, 1, &marked);
            if (!marked) goto CLEANUP;
            CCtsp_is_clique_marked (&c->cliques[i], marks, 0, &marked);
            if (!marked) goto CLEANUP;
        }
    }
    CCtsp_mark_clique (&c->cliques[ihandle], marks, 0);

    for (i = 0; i < c->cliquecount; i++) {
        if (i != ihandle) {
            CCtsp_is_clique_marked (&c->cliques[i], marks, 1, &marked);
            if (marked) goto CLEANUP;
            CCtsp_mark_clique (&c->cliques[i], marks, 1);
        }
    }

    *yes_no = 1;
    if (handle) *handle = ihandle;

CLEANUP:

    CC_IFFREE (marks, int);
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_test_pseudocomb (int ncount, CCtsp_lpcut_in *c, int handle,
        int *yes_no)
#else
int CCtsp_test_pseudocomb (ncount, c, handle, yes_no)
int ncount;
CCtsp_lpcut_in *c;
int handle;
int *yes_no;
#endif
{
    int rval = 0;
    int i, k, marked;
    int *ends = (int *) NULL;
    int *marks = (int *) NULL;

    *yes_no = 0;
    if (c->cliquecount <= 1 || c->cliquecount % 2 || c->sense != 'G') {
        printf ("bad cliquecount or sense in pseudocomb\n"); fflush (stdout);
        goto CLEANUP;
    }

    marks = CC_SAFE_MALLOC (ncount, int);
    if (!marks) {
        fprintf (stderr, "out of memory in CCtsp_test_pseudocomb\n");
        rval = 1; goto CLEANUP;
    }
    CCtsp_mark_cut (c, marks, 0);

    /* Teeth intersect H and are not contained in H */

    CCtsp_mark_clique (&c->cliques[handle], marks, 1);
    for (i = 0; i < c->cliquecount; i++) {
        if (i != handle) {
            CCtsp_is_clique_marked (&c->cliques[i], marks, 1, &marked);
            if (!marked) goto CLEANUP;
            CCtsp_is_clique_marked (&c->cliques[i], marks, 0, &marked);
            if (!marked) goto CLEANUP;
        }
    }
    CCtsp_mark_clique (&c->cliques[0], marks, 0);

    /* Big teeth are pairwise disjoint */

    for (i = 0; i < c->cliquecount; i++) {
        if (i != handle) {
            CCtsp_clique_count (&c->cliques[i], &k);
            if (k >= 3) {
                CCtsp_is_clique_marked (&c->cliques[i], marks, 1, &marked);
                if (marked) goto CLEANUP;
                CCtsp_mark_clique (&c->cliques[i], marks, 1);
            }
        }
    }
    for (i = 1; i < c->cliquecount; i++) {
        CCtsp_mark_clique (&c->cliques[i], marks, 0);
    }

    /* No small tooth is contained in a big tooth */

    for (i = 0; i < c->cliquecount; i++) {
        if (i != handle) {
            CCtsp_clique_count (&c->cliques[i], &k);
            if (k >= 3) {
                CCtsp_mark_clique (&c->cliques[i], marks, i + 1);
            }
        }
    }
    for (i = 0; i < c->cliquecount; i++) {
        if (i != handle) {
            CCtsp_clique_count (&c->cliques[i], &k);
            if (k < 3) {
                rval = CCtsp_clique_to_array (&c->cliques[i], &ends, &k);
                if (rval) {
                    fprintf (stderr, "CCtsp_clique_to_array failed\n");
                    goto CLEANUP;
                }
                if (ends[0] != 0 && ends[0] == ends[1]) goto CLEANUP;
                CC_IFFREE (ends, int);
            }
        }
    }


    *yes_no = 1;


CLEANUP:

    CC_IFFREE (marks, int);
    CC_IFFREE (ends, int);
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_test_teeth_disjoint (int ncount, CCtsp_lpcut_in *c, int handle,
       int *yes_no)
#else
int CCtsp_test_teeth_disjoint (ncount, c, handle, yes_no)
int ncount;
CCtsp_lpcut_in *c;
int handle;
int *yes_no;
#endif
{
    int rval = 0;
    int i, marked;
    int *marks = (int *) NULL;

    *yes_no = 0;

    marks = CC_SAFE_MALLOC (ncount, int);
    if (!marks) {
        fprintf (stderr, "out of memory in CCtsp_teeth_disjoint\n");
        rval = 1; goto CLEANUP;
    }
    CCtsp_mark_cut (c, marks, 0);

    for (i = 0; i < c->cliquecount; i++) {
        if (i != handle) {
            CCtsp_is_clique_marked (&c->cliques[i], marks, 1, &marked);
            if (marked) goto CLEANUP;
            CCtsp_mark_clique (&c->cliques[i], marks, 1);
        }
    }

    *yes_no = 1;

CLEANUP:

    CC_IFFREE (marks, int);
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_find_pure_handle (int ncount, CCtsp_lpcut_in *c, int *handle)
#else
int CCtsp_find_pure_handle (ncount, c, handle)
int ncount;
CCtsp_lpcut_in *c;
int *handle;
#endif
{
    int rval = 0;
    int *marks = (int *) NULL;
    int i, test;

    *handle = -1;
    if (c->cliquecount % 2 || c->cliquecount < 4) goto CLEANUP;

    marks = CC_SAFE_MALLOC (ncount, int);
    if (!marks) {
        fprintf (stderr, "out of memory in CCtsp_pure_find_handle\n");
        rval = 1; goto CLEANUP;
    }
    CCtsp_mark_cut (c, marks, 0);

    CCtsp_mark_clique (&c->cliques[0], marks, 1);
    CCtsp_is_clique_marked (&c->cliques[1], marks, 1, &test);
    if (test) {
        CCtsp_is_clique_marked (&c->cliques[2], marks, 1, &test);
        if (test) {
            *handle = 0; goto CLEANUP;
        } else {
            *handle = 1; goto CLEANUP;
        }
    } else {
        for (i = 2; i < c->cliquecount; i++) {
            CCtsp_is_clique_marked (&c->cliques[i], marks, 1, &test);
            if (test) {
                *handle = i;
                goto CLEANUP;
            }
        }
    }

CLEANUP:

    CC_IFFREE (marks, int);
    return rval;
}
