/***************************************************************************/
/*                                                                         */
/*             GLOBAL MIN-CUT USING PADBERG-RINALDI SHRINKING              */
/*                                                                         */
/*                                TSP CODE                                 */
/*                                                                         */
/*                                                                         */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook                       */
/*  Date: July 24, 1997                                                    */
/*                                                                         */
/*  EXPORTED FUNCTIONS:                                                    */
/*                                                                         */
/*    int CCcut_mincut (int ncount, int ecount, int *elist, double *dlen,  */
/*           double *cutval, int **cut, int *cutcount)                     */
/*     COMPUTES the global minimum cut in an undirected graph.             */
/*      -ncount is the number of nodes in the graph.                       */
/*      -ecount is the number of edges in the graph.                       */
/*      -elist is the list of edges in end0 end1 format                    */
/*      -dlen is a list of the edge capacities                             */
/*      -cutval returns the capacity of the mincut (it can be NULL).       */
/*      -cut will return the indices of the nodes in the minimum cut;      */
/*       this variable can be passed in as NULL, otherwise it will be      */
/*       an allocated to an array of the appropriate length.               */
/*      -cutcount will return the number of nodes in the minimum cut if    */
/*       cut is not NULL (if cut is NULL, then cutcount can be NULL).      */
/*    NOTE: This function assumes graph is connected. Paths of 1's are     */
/*     are shrunk - this is valid for the tsp, but not in general.         */
/*                                                                         */
/*   int CCcut_violated_cuts (int ncount, int ecount, int *elist,          */
/*           double *dlen, double cutoff, int (*doit_fn) (double, int,     */
/*           int *, void *), void *pass_param)                             */
/*    COMPUTES the global minimum cut, but calls the doit_fn function for  */
/*     cut the algorithm encounters that has capacity at most cutoff.      */
/*     -doit_fn (if not NULL) will be called for each cut having capacity  */
/*       less than or equal to the cutoff value; the arguments will be the */
/*       value of the cut, the number of nodes in the cut, the array of    */
/*       the members of the cut, and pass_param.                           */
/*     -pass_param will be passed to doit_fn; it can be NULL or it can be  */
/*       used to pass information to the doit_fn function.                 */
/*    NOTE: This function assumes graph is connected.                      */
/*                                                                         */
/*  NOTES:                                                                 */
/*                                                                         */
/*    This code works with undirected graphs. The shrinking routines       */
/*    assume that we are working with the TSP and not interested in cuts   */
/*    of weight 2.0 or more.                                               */
/*                                                                         */
/***************************************************************************/

#include "machdefs.h"
#include "util.h"
#include "cut.h"

#ifdef CC_PROTOTYPE_ANSI

static int
    mincut_work (int ncount, int ecount, int *elist, double *dlen,
        double *cutval, int **cut, int *cutcount, double cutoff,
        int (*doit_fn) (double, int, int *, void *), void *pass_param),
    flip_the_cut (int ncount, int **cut, int *cutcount);

#else

static int
    mincut_work (),
    flip_the_cut ();

#endif

#ifdef CC_PROTOTYPE_ANSI
int CCcut_mincut (int ncount, int ecount, int *elist, double *dlen,
        double *cutval, int **cut, int *cutcount)
#else
int CCcut_mincut (ncount, ecount, elist, dlen, cutval, cut, cutcount)
int ncount, ecount;
int *elist;
double *dlen;
double *cutval;
int **cut, *cutcount;
#endif
{
    int rval = 0;

    rval = mincut_work (ncount, ecount, elist, dlen, cutval, cut, cutcount,
                        0.0, NULL, (void *) NULL);
    if (rval) {
        fprintf (stderr, "mincut_work failed\n"); goto CLEANUP;
    }

CLEANUP:

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CCcut_violated_cuts (int ncount, int ecount, int *elist, double *dlen,
        double cutoff, int (*doit_fn) (double, int, int *, void *),
        void *pass_param)
#else
int CCcut_violated_cuts (ncount, ecount, elist, dlen, cutoff, doit_fn,
        pass_param)
int ncount, ecount;
int *elist;
double *dlen;
double cutoff;
int (*doit_fn) ();
void *pass_param;
#endif
{
    int rval = 0;

    rval = mincut_work (ncount, ecount, elist, dlen, (double *) NULL,
                  (int **) NULL, (int *) NULL, cutoff, doit_fn, pass_param);
    if (rval) {
        fprintf (stderr, "mincut_work failed\n"); goto CLEANUP;
    }

CLEANUP:

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static int mincut_work (int ncount, int ecount, int *elist, double *dlen,
        double *cutval, int **cut, int *cutcount, double cutoff,
        int (*doit_fn) (double, int, int *, void *), void *pass_param)
#else
static int mincut_work (ncount, ecount, elist, dlen, cutval, cut,
        cutcount, cutoff, doit_fn, pass_param)
int ncount, ecount;
int *elist;
double *dlen;
double *cutval;
int **cut, *cutcount;
double cutoff;
int (*doit_fn) ();
void *pass_param;
#endif
{
    int rval = 0;
    CC_SRKgraph G;
    CC_SRKexpinfo E;
    int i, sncount, secount;
    int *slist = (int *) NULL;
    double *slen = (double *) NULL;
    double minval = CC_MINCUT_BIGDOUBLE;
    double val;
    CC_SRKnode *squeue = (CC_SRKnode *) NULL;
    CC_SRKedge *f;
    int *tcut = (int *) NULL;
    int **mytcut = (int **) NULL;
    int tcount = 0;
    CC_SRKcallback *cb = (CC_SRKcallback *) NULL;

    CCcut_SRK_init_graph (&G);
    CCcut_SRK_init_expinfo (&E);
    if (cut) {
        *cut = (int *) NULL;
        if (cutcount) {
            *cutcount = 0;
        } else {
            fprintf (stderr, "cut specified, but not cutcount\n");
            rval = 1; goto CLEANUP;
        }
    }
    if (cut || doit_fn) {
        mytcut = &tcut;
    } else {
        mytcut = (int **) NULL;
    }
    if (cutval) {
        *cutval = CC_MINCUT_BIGDOUBLE;
    }
    if (doit_fn) {
        cb = CC_SAFE_MALLOC (1, CC_SRKcallback);
        if (!cb) {
            fprintf (stderr, "out of memory in mincut_work\n");
            rval = 1; goto CLEANUP;
        }
        cb->cutoff     = cutoff;
        cb->pass_param = pass_param;
        cb->doit_fn    = doit_fn;
    }

    rval = CCcut_SRK_buildgraph (&G, ncount, ecount, elist, dlen);
    if (rval) {
        fprintf (stderr, "buildgraph failed in shrink_ones\n"); goto CLEANUP;
    }
    rval = CCcut_SRK_subtour_shrink (&G, &minval, CC_MINCUT_ONE_EPSILON,
                               cb, cut, cutcount);
    if (rval) {
        fprintf (stderr, "CCcut_SRK_subtour_shrink failed\n"); goto CLEANUP;
    }

    if (CCcut_SRK_grab_edges (&G, &sncount, &secount, &slist, &slen,
                       (CC_SRKexpinfo *) NULL)) {
        fprintf (stderr, "grab edges failed in shrink_ones\n");
        rval = 1; goto CLEANUP;
    }

    while (sncount > 1) {
        if ( G.head->adj       == (CC_SRKedge *) NULL ||
             G.head->next->adj == (CC_SRKedge *) NULL) {
            fprintf (stderr, "Disconnected graph\n");
            rval = 1; goto CLEANUP;
        }
        rval = CCcut_mincut_st (sncount, secount, slist, slen, 0, 1,
                                &val, mytcut, &tcount);
        if (rval) {
            fprintf (stderr, "CCcut_mincut_st failed\n");
            goto CLEANUP;
        }
        if (val < minval) {
            minval = val;
            if (cut) {
                CC_IFFREE (*cut, int);
                rval = CCcut_SRK_grab_nodes (&G, &E);
                if (rval) {
                    fprintf (stderr, "CCcut_SRK_grab_nodes failed\n");
                    goto CLEANUP;
                }
                CCcut_SRK_expand (&E, tcut, tcount, cut, cutcount);
                CCcut_SRK_free_expinfo (&E);
            }
        }
        if (val < cutoff && doit_fn) {
            int *fcut = (int *) NULL;
            int fcutcount = 0;

            rval = CCcut_SRK_grab_nodes (&G, &E);
            if (rval) {
                fprintf (stderr, "CCcut_SRK_grab_nodes failed\n");
                goto CLEANUP;
            }
            CCcut_SRK_expand (&E, tcut, tcount, &fcut, &fcutcount);
            CCcut_SRK_free_expinfo (&E);
            rval = doit_fn (val, fcutcount, fcut, pass_param);
            if (rval) {
                fprintf (stderr, "doit_fn failed\n");
                CC_IFFREE (fcut, int);
                goto CLEANUP;
            }
            CC_IFFREE (fcut, int);
        }

        if (cut || doit_fn) {
            CC_IFFREE (tcut, int);
        }

        CCcut_SRK_identify_nodes (&G, G.head, G.head->next);

        squeue = (CC_SRKnode *) NULL;
        for (f = G.head->adj; f; f = f->next) {
            f->end->qnext = squeue;
            squeue = f->end;
        }
        G.head->qnext = squeue;
        squeue = G.head;

        CCcut_SRK_identify_pr_edges (&G, &minval, &i, squeue,
                     CC_MINCUT_ONE_EPSILON, cb, cut, cutcount);

        /* if (i) { printf ("[%d]", i); fflush (stdout); } */

        CC_IFFREE (slist, int);
        CC_IFFREE (slen, double);
        rval = CCcut_SRK_grab_edges (&G, &sncount, &secount, &slist, &slen,
                            (CC_SRKexpinfo *) NULL);
        if (rval) {
            fprintf (stderr, "grab edges failed in shrink_ones\n");
            goto CLEANUP;
        }
    }

    if (cutval) {
        *cutval = minval;
    }

    if (cut) {
        if (*cutcount > ncount/2) {
            rval = flip_the_cut (ncount, cut, cutcount);
            if (rval) {
                fprintf (stderr, "flip_the_cut failed\n"); goto CLEANUP;
            }
        }
    }

CLEANUP:

    if (rval) {
        if (cut) {
            CC_IFFREE (*cut, int);
        }
    }
    CC_IFFREE (slist, int);
    CC_IFFREE (slen, double);
    CC_IFFREE (tcut, int);
    CCcut_SRK_free_graph (&G);
    CCcut_SRK_free_expinfo (&E);
    CC_IFFREE (cb, CC_SRKcallback);

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static int flip_the_cut (int ncount, int **cut, int *cutcount)
#else
static int flip_the_cut (ncount, cut, cutcount)
int ncount;
int **cut;
int *cutcount;
#endif
{
    int rval = 0;
    int i;
    char *marks = (char *) NULL;
    int *newcut = (int *) NULL;
    int newcutcount = 0;

    if (*cutcount == ncount) {
        fprintf (stderr, "cut is the entire graph\n");
        rval = 1; goto CLEANUP;
    }

    marks = CC_SAFE_MALLOC (ncount, char);
    if (!marks) {
        fprintf (stderr, "out of memory in flip_the_cut\n");
        rval = 1; goto CLEANUP;
    }
    for (i = 0; i < ncount; i++) {
        marks[i] = 0;
    }
    for (i = 0; i < *cutcount; i++) {
        marks[(*cut)[i]] = 1;
    }

    newcut = CC_SAFE_MALLOC (ncount - *cutcount, int);
    if (!newcut) {
        fprintf (stderr, "out of memory in flip_the_cut\n");
        rval = 1; goto CLEANUP;
    }
    for (i = 0; i < ncount; i++) {
        if (!marks[i]) {
            newcut[newcutcount++] = i;
        }
    }

    CC_IFFREE (*cut, int);
    *cut = newcut;
    *cutcount = newcutcount;

CLEANUP:

    if (rval) {
        CC_IFFREE (newcut, int);
    }
    CC_IFFREE (marks, char);

    return rval;
}
