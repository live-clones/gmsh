/***************************************************************************/
/*                                                                         */
/*                  THE CONTROLLER FOR CUTTING PLANES                      */
/*                                                                         */
/*                             TSP CODE                                    */
/*                                                                         */
/*                                                                         */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook                       */
/*  Date: June 27, 1997                                                    */
/*                                                                         */
/*  EXPORTED FUNCTIONS:                                                    */
/*    int CCtsp_init_cutselect (CCtsp_lp *lp, CCtsp_cutselect *s)          */
/*     INITIALIZES the cut selctions                                       */
/*     Note: The lp should be solved before this call.                     */
/*                                                                         */
/*    int CCtsp_cutting_loop (CCtsp_lp *lp, CCtsp_cutselect *sel,          */
/*            int savelp)                                                  */
/*     CALLS the cutting plane and pricing routines.                       */
/*      -sel should be set with the desired cut selection.                 */
/*      -savelp should be set to a nonzero value to write the lps to after */
/*       rounds of cuts                                                    */
/*     Note: It returns a 2 if the lp becomes infeasible                   */
/*                                                                         */
/*    int CCtsp_subtour_loop (CCtsp_lp *lp)                                */
/*     CALLS the cutting and pricing to optimize over the subtour polytope.*/
/*                                                                         */
/*    int CCtsp_pricing_loop (CCtsp_lp *lp, double *bnd)                   */
/*     ADDS negative reduced costs edges to lp and returns the current     */
/*      lowerbound.                                                        */
/*      -bnd can be NULL                                                   */
/*     NOTE: The LP must have full_edges_valid.                            */
/*                                                                         */
/*    int CCtsp_call_x_heuristic (CCtsp_lp *lp, double *val, int *outcyc ) */
/*     CALLS the x-greedy LK heuristic with the current LP solution.       */
/*      -val returns the length of the tour.                               */
/*      -outcyc will return the tour in node-node-node format if the       */
/*       length of the tour is less than lp->upperbound; the array should  */
/*       at least of length ncount (it can be NULL)                        */
/*                                                                         */
/*    int CCtsp_bb_cutting (char *probname, int probnum, int ncount,       */
/*            CCdatagroup *dat, int *ptour, double initial_ub,             */
/*            CCtsp_lpcuts *pool, CCtsp_cutselect *sel, double *val,       */
/*            int *prune, int *foundtour, int *besttour)                   */
/*     CALLS the cutting loop after reading the lp; writes the result to   */
/*      the same prob file; using exact price to verify pruned runs        */
/*      -upbound should be passed in as the current bound; if a better     */
/*       tour is found then upbound will be updated                        */
/*      -val returns the lp bound; it is CCtsp_LP_MAXDOUBLE if infeasible  */
/*      -prune is set to 1 if bbnode can be pruned                         */
/*      -foundtour is set to 1 if a better tour is found.                  */
/*      -besttour (if not NULL) will return a better tour if one is found. */
/*                                                                         */
/*  NOTES:                                                                 */
/*                                                                         */
/*                                                                         */
/***************************************************************************/

#include "machdefs.h"
#include "util.h"
#include "tsp.h"
#include "Xstuff.h"
#include "bigguy.h"
#include "cut.h"


#ifdef CC_PROTOTYPE_ANSI

static int
    call_add_cuts (CCtsp_lp *lp, CCtsp_lpcut_in **cuts, int *cut_added,
        int *xcount, int **xlist, double **x, double *val, int tighten),
    lp_value (CCtsp_lp *lp, double *val),
    lp_x (CCtsp_lp *lp, int *xcount, int **xlist, double **x),
    full_edge_check (CCtsp_lp *lp, int *nadded),
    sparse_edge_check (CCtsp_lp *lp, CCtsp_edgegenerator *eg, int *nadded,
        double *bnd),
    bb_cutting_work (CCtsp_lp **lp, char *probname, int probnum,
        int ncount, CCdatagroup *dat, int *ptour, double upbound,
        CCtsp_lpcuts *pool, CCtsp_cutselect *sel, double *val);

#else

static int
    call_add_cuts (),
    lp_value (),
    lp_x (),
    full_edge_check (),
    sparse_edge_check (),
    bb_cutting_work ();

#endif


#ifdef CC_PROTOTYPE_ANSI
int CCtsp_init_cutselect (CCtsp_lp *lp, CCtsp_cutselect *s)
#else
int CCtsp_init_cutselect (lp, s)
CCtsp_lp *lp;
CCtsp_cutselect *s;
#endif
{
    double ub;
    int rval = 0;

    s->cutpool          = 1;
    s->connect          = 1;
    s->segments         = 1;
    s->exactsubtour     = 1;
    s->tighten_lp       = 1;
    s->decker_lp        = 0;
    s->teething_lp      = 1;
    s->tighten_pool     = 1;
    s->decker_pool      = 0;
    s->teething_pool    = 0;
    s->maxchunksize     = 0;
    s->Xfastcuts        = 1;
    s->Xexactsubtours   = 0;
    s->Xslowcuts        = 1;
    s->consecutiveones  = 0;
    s->necklace         = 0;
    s->usetighten       = 1;
    s->extra_connect    = 0;

    rval = CCtsp_get_lp_result (lp, (double *) NULL, &ub, (int *) NULL,
              (int **) NULL, (double **) NULL, (double **) NULL,
              (double **) NULL, (double **) NULL);
    if (rval) {
        fprintf (stderr, "CCtsp_get_lp_result failed\n"); goto CLEANUP;
    }

    s->nexttol  = CCtsp_CUTS_NEXT_TOL * ub;
    s->roundtol = CCtsp_CUTS_NEXT_ROUND * ub;

CLEANUP:

    return rval;
}

#define LOOP_FULL (25)      /* to force a full price after 25 inner loops */
#define CC_NO_NEAREST (20)  /* the initial sparse graph for pricing       */

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_cutting_loop (CCtsp_lp *lp, CCtsp_cutselect *sel, int savelp)
#else
int CCtsp_cutting_loop (lp, sel, savelp)
CCtsp_lp *lp;
CCtsp_cutselect *sel;
int savelp;
#endif
{
    int xcount, cutcount, cutcount_connect, cut_added, edge_added;
    int *xlist = (int *) NULL;
    int outside = 0;
    double newval, oldval, ub;
    double *x = (double *) NULL;
    CCtsp_lpcut_in *cuts = (CCtsp_lpcut_in *) NULL;
    CCtsp_edgegenerator eginside;
    int rval = 0;
    int loopcount = 0;
    double szeit = CCutil_zeit ();

    eginside.ncount = 0;
    if (lp->fulladj) {
        rval = CCtsp_init_edgegenerator (&eginside, lp->graph.ncount, lp->dat,
                                   lp->fulladj, 0);
        if (rval) {
            fprintf (stderr, "CCtsp_init_edgegenerator (sparse) failed\n");
            rval = 1; goto CLEANUP;
        }
    } else if (lp->dat) {
        rval = CCtsp_init_edgegenerator (&eginside, lp->graph.ncount, lp->dat,
                                   (CCtsp_genadj *) NULL, CC_NO_NEAREST);
        if (rval) {
            fprintf (stderr, "CCtsp_init_edgegenerator (sparse) failed\n");
            rval = 1; goto CLEANUP;
        }
    }

    rval = CCtsp_get_lp_result (lp, (double *) NULL, &ub, (int *) NULL,
              (int **) NULL, (double **) NULL, (double **) NULL,
              (double **) NULL, (double **) NULL);
    if (rval) {
        fprintf (stderr, "CCtsp_get_lp_result failed\n");
        rval = 1; goto CLEANUP;
    }

    do {
        loopcount = 0;
        cutcount_connect = 0;
        do {
            cut_added = 0;
            rval = lp_value (lp, &oldval);
            if (rval) {rval = 1; goto CLEANUP;}

            newval = oldval;

            rval = lp_x (lp, &xcount, &xlist, &x);
            if (rval) {rval = 1; goto CLEANUP;}

            if (sel->cutpool) {
                rval = CCtsp_search_cutpool (lp->pool, &cuts, &cutcount,
                           lp->graph.ncount, xcount, xlist, x);
                if (rval) {
                    fprintf (stderr, "CCtsp_search_cutpool failed\n");
                    rval = 1; goto CLEANUP;
                }
                if (cutcount)  {
                    printf ("Found %d cutpool cuts\n", cutcount);
                    fflush (stdout);
                    rval = call_add_cuts (lp, &cuts, &cut_added, &xcount,
                               &xlist, &x, &newval, sel->usetighten);
                    if (rval) {
                        fprintf (stderr, "call_add_cuts failed\n");
                        goto CLEANUP;
                    }
                }
            }

            if (sel->connect) {
                rval = CCtsp_connect_cuts (&cuts, &cutcount, lp->graph.ncount,
                                           xcount, xlist, x);
                if (rval) {
                    fprintf (stderr, "CCtsp_connect_cuts failed\n");
                    rval = 1; goto CLEANUP;
                }
                if (cutcount) {
                    printf ("Found %d connect cuts\n", cutcount);
                    fflush (stdout);
                    rval = call_add_cuts (lp, &cuts, &cut_added, &xcount,
                               &xlist, &x, &newval, sel->usetighten);
                    if (rval) {
                        fprintf (stderr, "call_add_cuts failed\n");
                        goto CLEANUP;
                    }
                }
            }

            if (sel->segments) {
                rval = CCtsp_segment_cuts (&cuts, &cutcount, lp->graph.ncount,
                               xcount, xlist, x);
                if (rval) {
                    fprintf (stderr,  "CCtsp_segment_cuts failed\n");
                    rval = 1; goto CLEANUP;
                }
                if (cutcount) {
                    printf ("Found %d segment cuts\n", cutcount);
                    fflush (stdout);
                    rval = call_add_cuts (lp, &cuts, &cut_added, &xcount,
                               &xlist, &x, &newval, sel->usetighten);
                    if (rval) {
                        fprintf (stderr, "call_add_cuts failed\n");
                        goto CLEANUP;
                    }
                }
            }

            if (sel->Xfastcuts) {
                rval = Xfastcuts (&cuts, &cutcount, lp->graph.ncount, xcount,
                                  xlist, x);
                if (rval) {
                    fprintf (stderr, "Xfastcuts failed\n");
                    rval = 1; goto CLEANUP;
                }
                if (cutcount) {
                    printf ("Found %d Xfastcuts\n", cutcount);
                    fflush (stdout);
                    rval = call_add_cuts (lp, &cuts, &cut_added, &xcount,
                               &xlist, &x, &newval, sel->usetighten);
                    if (rval) {
                        fprintf (stderr, "call_add_cuts failed\n");
                        goto CLEANUP;
                    }
                }
            }

            if (sel->exactsubtour) {
                rval = CCtsp_exact_subtours (&cuts, &cutcount, lp->graph.ncount,
                                           xcount, xlist, x);
                if (rval) {
                    fprintf (stderr, "CCtsp_exact_subtours failed\n");
                    rval = 1; goto CLEANUP;
                }
                if (cutcount) {
                    printf ("Found %d exact subtours\n", cutcount);
                    fflush (stdout);
                    rval = call_add_cuts (lp, &cuts, &cut_added, &xcount,
                               &xlist, &x, &newval, sel->usetighten);
                    if (rval) {
                        fprintf (stderr, "call_add_cuts failed\n");
                        goto CLEANUP;
                    }
                }
            }

            if (sel->tighten_lp) {
                rval = CCtsp_tighten_lp (&lp->cuts, &lp->tighten_stats, &cuts,
                        &cutcount, lp->graph.ncount, xcount, xlist, x,
                        1.0, 500);
                if (rval) {
                    fprintf (stderr, "CCtsp_tighten_lp failed\n");
                    rval = 1; goto CLEANUP;
                }
                if (cutcount) {
                    printf ("Found %d tighten_lp cuts\n", cutcount);
                    fflush (stdout);
                    rval = call_add_cuts (lp, &cuts, &cut_added, &xcount,
                               &xlist, &x, &newval, sel->usetighten);
                    if (rval) {
                        fprintf (stderr, "call_add_cuts failed\n");
                        goto CLEANUP;
                    }
                }
            }

            if (sel->teething_lp) {
                rval = CCtsp_teething_lp (&lp->cuts, &lp->tighten_stats,
                        &cuts, &cutcount, lp->graph.ncount, xcount, xlist, x,
                        10.0, 500);
                if (rval) {
                    fprintf (stderr, "CCtsp_teething_lp failed\n");
                    rval = 1; goto CLEANUP;
                }
                if (cutcount) {
                    printf ("Found %d teethed combs\n", cutcount);
                    fflush (stdout);
                    rval = call_add_cuts (lp, &cuts, &cut_added, &xcount,
                               &xlist, &x, &newval, sel->usetighten);
                    if (rval) {
                        fprintf (stderr, "call_add_cuts failed\n");
                        goto CLEANUP;
                    }
                }
            }

            if (sel->Xexactsubtours) {
                rval = Xexactsubtours (&cuts, &cutcount, lp->graph.ncount,
                                  xcount, xlist, x);
                if (rval) {
                    fprintf (stderr, "Xexactsubtours failed\n");
                    rval = 1; goto CLEANUP;
                }
                if (cutcount) {
                    printf ("Found %d Xexactsubtours\n", cutcount);
                    fflush (stdout);
                    rval = call_add_cuts (lp, &cuts, &cut_added, &xcount,
                               &xlist, &x, &newval, sel->usetighten);
                    if (rval) {
                        fprintf (stderr, "call_add_cuts failed\n");
                        goto CLEANUP;
                    }
                }
            }

            if (sel->Xslowcuts && newval < oldval + sel->nexttol) {
                rval = Xslowcuts (&cuts, &cutcount, lp->graph.ncount,
                                  xcount, xlist, x);
                if (rval) {
                    fprintf (stderr, "Xslowcuts failed\n");
                    rval = 1; goto CLEANUP;
                }
                if (cutcount) {
                    printf ("Found %d Xslowcuts\n", cutcount); fflush (stdout);
                    rval = call_add_cuts (lp, &cuts, &cut_added, &xcount,
                               &xlist, &x, &newval, sel->usetighten);
                    if (rval) {
                        fprintf (stderr, "call_add_cuts failed\n");
                        goto CLEANUP;
                    }
                }
            }

            if (sel->tighten_pool && newval < oldval + sel->nexttol) {
                rval = CCtsp_tighten_lp (lp->pool, &lp->tighten_stats, &cuts,
                         &cutcount, lp->graph.ncount, xcount, xlist, x, 0.1,
                         1000);
                if (rval) {
                    fprintf (stderr, "CCtsp_tighten_lp failed\n");
                    rval = 1; goto CLEANUP;
                }
                if (cutcount) {
                    printf ("Found %d tighten pool cuts\n", cutcount);
                    fflush (stdout);
                    rval = call_add_cuts (lp, &cuts, &cut_added, &xcount,
                               &xlist, &x, &newval, sel->usetighten);
                    if (rval) {
                        fprintf (stderr, "call_add_cuts failed\n");
                        goto CLEANUP;
                    }
                }
            }

            if (sel->teething_pool && newval < oldval + sel->nexttol) {
                rval = CCtsp_teething_lp (lp->pool, &lp->tighten_stats,
                         &cuts, &cutcount, lp->graph.ncount, xcount, xlist, x,
                         0.5, 1000);
                if (rval) {
                    fprintf (stderr, "CCtsp_teething_lp failed\n");
                    rval = 1; goto CLEANUP;
                }
                if (cutcount) {
                    printf ("Found %d pool teething combs\n", cutcount);
                    fflush (stdout);
                    rval = call_add_cuts (lp, &cuts, &cut_added, &xcount,
                               &xlist, &x, &newval, sel->usetighten);
                    if (rval) {
                        fprintf (stderr, "call_add_cuts failed\n");
                        goto CLEANUP;
                    }
                }
            }

            if (sel->consecutiveones && newval < oldval + sel->nexttol) {
                rval = Xconsecutiveones (&cuts, &cutcount, lp->graph.ncount,
                                  xcount, xlist, x, lp->pool);
                if (rval) {
                    fprintf (stderr, "Xconsecutiveones failed\n");
                    rval = 1; goto CLEANUP;
                }
                if (cutcount) {
                    printf ("Found %d Xconsecutiveones cuts\n", cutcount);
                    fflush (stdout);
                    rval = call_add_cuts (lp, &cuts, &cut_added, &xcount,
                               &xlist, &x, &newval, sel->usetighten);
                    if (rval) {
                        fprintf (stderr, "call_add_cuts failed\n");
                        goto CLEANUP;
                    }
                }
            }
            if (sel->necklace && newval < oldval + sel->nexttol) {
                rval = Xnecklacecuts (&cuts, &cutcount, lp->graph.ncount,
                                  xcount, xlist, x, lp->pool);
                if (rval) {
                    fprintf (stderr, "Xnecklacecuts failed\n");
                    rval = 1; goto CLEANUP;
                }
                if (cutcount) {
                    printf ("Found %d Xnecklace cuts\n", cutcount);
                    fflush (stdout);
                    rval = call_add_cuts (lp, &cuts, &cut_added, &xcount,
                               &xlist, &x, &newval, sel->usetighten);
                    if (rval) {
                        fprintf (stderr, "call_add_cuts failed\n");
                        goto CLEANUP;
                    }
                }
            }

            CC_FREE (xlist, int);
            CC_FREE (x, double);

            rval = sparse_edge_check (lp, &eginside, &edge_added,
                                      (double *) NULL);
            if (rval) {
                fprintf (stderr, "sparse_edge_check failed\n");
                rval = 1; goto CLEANUP;
            }
            if (savelp) {
                rval = CCtsp_write_probfile_sav (lp);
                if (rval) {
                    fprintf (stderr, "CCtsp_write_probfile_sav failed\n");
                    rval = 1; goto CLEANUP;
                }
            }
            if (lp->pool) {
                char buf[1024];
                printf ("Write Pool: %d cuts\n", lp->pool->cutcount);
                fflush (stdout);
                sprintf (buf, "%s.pul", lp->name);
                rval = CCtsp_write_cutpool (lp->graph.ncount, buf, lp->pool);
                if (rval) {
                    fprintf (stderr, "CCtsp_write_cutpool failed\n");
                    rval = 1; goto CLEANUP;
                }
            }
            if (lp->lowerbound >= lp->upperbound - 0.9) {
                printf ("Stop cutting, lp bound is within 0.9 of upperbound\n");
                fflush (stdout);
                goto CLEANUP;
            }
            loopcount++;
        } while ((newval > oldval + sel->roundtol || edge_added)
                  && loopcount < LOOP_FULL);

        rval = full_edge_check (lp, &edge_added);
        if (rval) {
            fprintf (stderr, "full_edge_check failed\n");
            rval = 1; goto CLEANUP;
        }
        if (savelp) {
            rval = CCtsp_write_probfile_sav (lp);
            if (rval) {
                fprintf (stderr, "CCtsp_write_probfile_sav failed\n");
                rval = 1; goto CLEANUP;
            }
        }

        if (sel->extra_connect && (!edge_added || loopcount != LOOP_FULL)) {
            printf ("Check connectivity before exiting cutting_loop\n");
            fflush (stdout);

            rval = lp_x (lp, &xcount, &xlist, &x);
            if (rval) {rval = 1; goto CLEANUP;}

            rval = CCtsp_connect_cuts (&cuts, &cutcount_connect, 
                                       lp->graph.ncount,
                                       xcount, xlist, x);
            if (rval) {
                fprintf (stderr, "CCtsp_connect_cuts failed\n");
                rval = 1; goto CLEANUP;
            }
            if (cutcount_connect) {
                printf ("Found %d connect cuts\n", cutcount);
                fflush (stdout);
                rval = call_add_cuts (lp, &cuts, &cut_added, &xcount,
                           &xlist, &x, &newval, sel->usetighten);
                if (rval) {
                    fprintf (stderr, "call_add_cuts failed\n");
                    goto CLEANUP;
                }
            }
            CC_FREE (xlist, int);
            CC_FREE (x, double);
        }
        outside++;
    } while (edge_added || loopcount == LOOP_FULL || cutcount_connect);

CLEANUP:

    if (rval == 2) {
        printf ("LP is infeasible in cutting_loop\n");
        fflush (stdout);
    } else if (rval) {
        fprintf (stderr, "failure in cutting_loop\n");
    }
    printf ("Time in cutting routine: %.2f\n", CCutil_zeit () - szeit);
    printf ("Number of outside rounds: %d\n", outside);
    fflush (stdout);

    if (eginside.ncount)
        CCtsp_free_edgegenerator (&eginside);
    CC_IFFREE (xlist, int);
    CC_IFFREE (x, double);

    return rval;
}

#define CC_NO_NEAREST_SUBTOUR 50
#define CC_SUBTOUR_ROUNDS     5

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_subtour_loop (CCtsp_lp *lp)
#else
int CCtsp_subtour_loop (lp)
CCtsp_lp *lp;
#endif
{
    int rval = 0;
    int xcount, cutcount, cut_added, edge_added;
    int outside = 0;
    int inside = 0;
    int tighten = 0;
    double newval;
    int *xlist = (int *) NULL;
    double *x = (double *) NULL;
    CCtsp_lpcut_in *cuts = (CCtsp_lpcut_in *) NULL;
    CCtsp_edgegenerator eginside;
    double szeit = CCutil_zeit ();
    double connect_zeit = 0.0;
    double linsub_zeit  = 0.0;
    double exact_zeit   = 0.0;
    double tzeit;

    eginside.ncount = 0;
    if (lp->fulladj) {
        rval = CCtsp_init_edgegenerator (&eginside, lp->graph.ncount, lp->dat,
                             lp->fulladj, 0);
        if (rval) {
            fprintf (stderr, "CCtsp_init_edgegenerator (sparse) failed\n");
            rval = 1; goto CLEANUP;
        }
    } else if (lp->dat) {
        rval = CCtsp_init_edgegenerator (&eginside, lp->graph.ncount, lp->dat,
                             (CCtsp_genadj *) NULL, CC_NO_NEAREST_SUBTOUR);
        if (rval) {
            fprintf (stderr, "CCtsp_init_edgegenerator (sparse) failed\n");
            rval = 1; goto CLEANUP;
        }
    }

    rval = CCtsp_get_lp_result (lp, (double *) NULL, (double *) NULL,
              (int *) NULL, (int **) NULL, (double **) NULL, (double **) NULL,
              (double **) NULL, (double **) NULL);
    if (rval) {
        fprintf (stderr, "CCtsp_get_lp_result failed\n");
        rval = 1; goto CLEANUP;
    }

    do {
        do {
            cut_added = 0;

            rval = lp_x (lp, &xcount, &xlist, &x);
            if (rval) {rval = 1; goto CLEANUP;}


            /**** Connect Cuts ****/


            tzeit = CCutil_zeit ();
            rval = CCtsp_connect_cuts (&cuts, &cutcount, lp->graph.ncount,
                                       xcount, xlist, x);
            connect_zeit += (CCutil_zeit () - tzeit);
            if (rval) {
                fprintf (stderr, "CCtsp_connect_cuts failed\n");
                rval = 1; goto CLEANUP;
            }
            if (cutcount) {
                printf ("Found %d connect cuts\n", cutcount);
                fflush (stdout);
                rval = call_add_cuts (lp, &cuts, &cut_added, &xcount,
                           &xlist, &x, &newval, tighten);
                if (rval) {
                    fprintf (stderr, "call_add_cuts failed\n"); goto CLEANUP;
                }
            }


            /**** Linear Cuts ****/


            tzeit = CCutil_zeit ();
            rval = CCtsp_segment_cuts (&cuts, &cutcount, lp->graph.ncount,
                           xcount, xlist, x);
            if (rval) {
                fprintf (stderr,  "CCtsp_segment_cuts failed\n");
                rval = 1; goto CLEANUP;
            }
            linsub_zeit += (CCutil_zeit () - tzeit);
            if (rval) {
                fprintf (stderr,  "CCtsp_segment_cuts failed\n");
                rval = 1; goto CLEANUP;
            }
            if (cutcount) {
                printf ("Found %d segment cuts\n", cutcount);
                fflush (stdout);
                rval = call_add_cuts (lp, &cuts, &cut_added, &xcount,
                           &xlist, &x, &newval, tighten);
                if (rval) {
                    fprintf (stderr, "call_add_cuts failed\n"); goto CLEANUP;
                }
            }


            /**** Exact Cuts ****/


            tzeit = CCutil_zeit ();
            rval = CCtsp_exact_subtours (&cuts, &cutcount, lp->graph.ncount,
                                         xcount, xlist, x);
            exact_zeit += (CCutil_zeit () - tzeit);
            if (rval) {
                fprintf (stderr, "CCtsp_exact_subtours failed\n");
                rval = 1; goto CLEANUP;
            }
            if (cutcount) {
                printf ("Found %d exact subtours\n", cutcount);
                fflush (stdout);
                rval = call_add_cuts (lp, &cuts, &cut_added, &xcount,
                           &xlist, &x, &newval, tighten);
                if (rval) {
                    fprintf (stderr, "call_add_cuts failed\n"); goto CLEANUP;
                }
            }

#if 0
  - this is just to check that the code is finding all cuts

            /**** Old Exact Cuts ****/


            if (!cut_added) {
                rval = Xexactsubtours (&cuts, &cutcount, lp->graph.ncount,
                                       xcount, xlist, x);
                if (rval) {
                    fprintf (stderr, "Xexactsubtours failed\n");
                    rval = 1; goto CLEANUP;
                }
                if (cutcount) {
                    printf ("Found %d Xexactsubtours\n", cutcount);
                    fflush (stdout);

                    rval = CCtsp_dump_x (lp, "should.x");
                    if (rval) {
                        fprintf (stderr, "CCtsp_dump_x failed\n");
                        goto CLEANUP;
                    }

                    rval = call_add_cuts (lp, &cuts, &cut_added, &xcount,
                               &xlist, &x, &newval, tighten);
                    if (rval) {
                        fprintf (stderr, "call_add_cuts failed\n");
                        goto CLEANUP;
                    }
                    fprintf (stderr, "SHOULD NOT FIND XEXACTSUBTOURS\n");
                    rval = 1; goto CLEANUP;
                }
            }
#endif

            CC_FREE (xlist, int);
            CC_FREE (x, double);

            if (!cut_added || (inside % CC_SUBTOUR_ROUNDS) == 0) {
                rval = sparse_edge_check (lp, &eginside, &edge_added,
                                          (double *) NULL);
                if (rval) {
                    fprintf (stderr, "sparse_edge_check failed\n");
                    rval = 1; goto CLEANUP;
                }
            }
            inside++;
        } while (edge_added || cut_added);

        rval = full_edge_check (lp, &edge_added);
        if (rval) {
            fprintf (stderr, "full_edge_check failed\n");
            rval = 1; goto CLEANUP;
        }
        outside++;

    } while (edge_added);

CLEANUP:

    if (rval == 2) {
        printf ("LP is infeasible in subtour_loop\n");
        fflush (stdout);
    } else if (rval) {
        fprintf (stderr, "failure in subtour_loop\n");
    }
    printf ("Time in cutting routine: %.2f\n", CCutil_zeit () - szeit);
    printf ("   Connect cuts: %.2f\n", connect_zeit);
    printf ("   Linear cuts:  %.2f\n", linsub_zeit);
    printf ("   Exact cuts:   %.2f\n", exact_zeit);


    printf ("Number of outside rounds: %d (%d inside)\n", outside, inside);
    fflush (stdout);

    if (eginside.ncount)
        CCtsp_free_edgegenerator (&eginside);
    CC_IFFREE (xlist, int);
    CC_IFFREE (x, double);

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static int call_add_cuts (CCtsp_lp *lp, CCtsp_lpcut_in **cuts, int *cut_added,
        int *xcount, int **xlist, double **x, double *val, int tighten)
#else
static int call_add_cuts (lp, cuts, cut_added, xcount, xlist, x, val, tighten)
CCtsp_lp *lp;
CCtsp_lpcut_in **cuts;
int *cut_added;
int *xcount;
int **xlist;
double **x;
double *val;
int tighten;
#endif
{
    int rval = 0;

    CC_IFFREE (*xlist, int);
    CC_IFFREE (*x, double);

    CCtsp_add_cuts_to_queue (lp, cuts);
    rval = CCtsp_process_cuts (lp, cut_added, tighten);
    if (rval) {
        fprintf (stderr, "process_cuts failed\n"); goto CLEANUP;
    }
    printf ("Added %d cuts (Total %d)\n", *cut_added, lp->cuts.cutcount);
    fflush (stdout);

    rval = lp_value (lp, val);
    if (rval) {
        fprintf (stderr, "lp_value failed\n"); rval = 1; goto CLEANUP;
    }
    printf ("LP Value: %f\n", *val); fflush (stdout);

    rval = lp_x (lp, xcount, xlist, x);
    if (rval) {
        fprintf (stderr, "lp_x failed\n"); rval = 1; goto CLEANUP;
    }

CLEANUP:

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static int lp_value (CCtsp_lp *lp, double *val)
#else
static int lp_value (lp, val)
CCtsp_lp *lp;
double *val;
#endif
{
    int rval;

    rval = CCtsp_get_lp_result (lp, val, (double *) NULL, (int *) NULL,
                 (int **) NULL, (double **) NULL, (double **) NULL,
                 (double **) NULL, (double **) NULL);
    if (rval) fprintf (stderr, "CCtsp_get_lp_result failed\n");
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static int lp_x (CCtsp_lp *lp, int *xcount, int **xlist, double **x)
#else
static int lp_x (lp, xcount, xlist, x)
CCtsp_lp *lp;
int *xcount;
int **xlist;
double **x;
#endif
{
    int rval;

    rval = CCtsp_get_lp_result (lp, (double *) NULL, (double *) NULL, xcount,
                     xlist, x, (double **) NULL, (double **) NULL,
                     (double **) NULL);
    if (rval) fprintf (stderr, "CCtsp_get_lp_result failed\n");
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_pricing_loop (CCtsp_lp *lp, double *bnd)
#else
int CCtsp_pricing_loop (lp, bnd)
CCtsp_lp *lp;
double *bnd;
#endif
{
    CCtsp_edgegenerator eg;
    int nadded;
    int rval = 0;

    eg.ncount = 0;
    if (!lp->full_edges_valid) {
        fprintf (stderr, "CCtsp_pricing_loop called without valid edges\n");
        rval = 1; goto CLEANUP;
    }


    rval = CCtsp_init_edgegenerator (&eg, lp->graph.ncount, lp->dat,
                                     lp->fulladj, 0);
    if (rval) {
        fprintf (stderr, "CCtsp_init_edgegenerator failed\n"); goto CLEANUP;
    }
    rval = sparse_edge_check (lp, &eg, &nadded, bnd);
    if (rval) {
        fprintf (stderr, "sparse_edge_check failed\n"); goto CLEANUP;
    }

CLEANUP:

    if (eg.ncount) {
        CCtsp_free_edgegenerator (&eg);
    }
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static int full_edge_check (CCtsp_lp *lp, int *nadded)
#else
static int full_edge_check (lp, nadded)
CCtsp_lp *lp;
int *nadded;
#endif
{
    int rval;
    CCtsp_edgegenerator eg;
    double val, penalty;

    if (lp->dat && (!lp->full_edges_valid)) {
        rval = CCtsp_init_edgegenerator (&eg, lp->graph.ncount, lp->dat,
                       (CCtsp_genadj *) NULL, CCtsp_PRICE_COMPLETE_GRAPH);
        if (rval) {
            fprintf (stderr, "CCtsp_init_edgegenerator failed\n"); return rval;
        }

        rval = CCtsp_addbad_variables (lp, &eg, &penalty, nadded,
                  CCtsp_PRICE_RCTHRESH, CCtsp_PRICE_MAXPENALTY, 0, (int *) NULL);
        if (rval) {
            fprintf (stderr, "CCtsp_addbad_variables failed\n");
            CCtsp_free_edgegenerator (&eg);
            return rval;
        }
        CCtsp_free_edgegenerator (&eg);
        printf ("%d edges added, penalty %f\n", *nadded, penalty);
        fflush (stdout);

        rval = lp_value (lp, &val);
        if (rval) return rval;

        if (val + penalty > lp->lowerbound) {
            printf ("New lower bound: %f\n", val+ penalty);
            fflush (stdout);
            lp->lowerbound = val + penalty;
        }
    } else {
        *nadded = 0;
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int sparse_edge_check (CCtsp_lp *lp, CCtsp_edgegenerator *eg,
        int *nadded, double *bnd)
#else
static int sparse_edge_check (lp, eg, nadded, bnd)
CCtsp_lp *lp;
CCtsp_edgegenerator *eg;
int *nadded;
double *bnd;
#endif
{
    double val, penalty;
    int rval;

    if (bnd) *bnd = -CCtsp_LP_MAXDOUBLE;

    if (eg->ncount > 0) {
        rval = CCtsp_addbad_variables (lp, eg, &penalty, nadded,
                CCtsp_PRICE_RCTHRESH, CCtsp_PRICE_MAXPENALTY, 0, (int *) NULL);
        if (rval) {
            fprintf (stderr, "CCtsp_addbad_variables failed\n"); return rval;
        }

        rval = lp_value (lp, &val);
        if (rval) { fprintf (stderr, "lp_value failed\n"); return rval; }

        printf ("(SPARSE) %d edges added, penalty %f, val %f\n",
                  *nadded, penalty, val);
        fflush (stdout);

        if (lp->full_edges_valid) {
            if (val + penalty > lp->lowerbound) {
                printf ("New lower bound: %f\n", val + penalty);
                fflush (stdout);
                lp->lowerbound = val + penalty;
            }
            if (bnd) *bnd = val + penalty;
        }
    } else {
        *nadded = 0;
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_bb_cutting (char *probname, int probnum, int ncount, CCdatagroup *dat,
        int *ptour, double *upbound, CCtsp_lpcuts *pool, CCtsp_cutselect *sel,
        double *val, int *prune, int *foundtour, int *besttour)
#else
int CCtsp_bb_cutting (probname, probnum, ncount, dat, ptour, upbound, pool,
        sel, val, prune, foundtour, besttour)
char *probname;
int probnum;
int ncount;
CCdatagroup *dat;
int *ptour;
double *upbound;
CCtsp_lpcuts *pool;
CCtsp_cutselect *sel;
double *val;
int *prune;
int *foundtour;
int *besttour;
#endif
{
    int rval = 0;
    CCtsp_lp *lp = (CCtsp_lp *) NULL;
    double cval, tourval;
    int test;

    *val = 0.0;
    *prune = 0;
    *foundtour = 0;

    rval = bb_cutting_work (&lp, probname, probnum, ncount, dat, ptour,
                            *upbound, pool, sel, &cval);
    if (rval) {
        fprintf (stderr, "bb_cutting_work failed\n"); fflush (stdout);
    }

    if (cval == CCtsp_LP_MAXDOUBLE) {
        rval = CCtsp_verify_infeasible_lp (lp, &test);
        if (rval) {
            fprintf (stderr, "CCtsp_verify_infeasible_lp failed\n");
            goto CLEANUP;
        }
        if (test) {
            printf ("verified infeasible LP\n"); fflush (stdout);
            *val = CCtsp_LP_MAXDOUBLE;
            *prune = 1;
            /* for proof mode, write the lp file here */
            rval = 0;
        } else {
            fprintf (stderr, "did not verify an infeasible LP\n");
            rval = 1; goto CLEANUP;
        }
    } else {
        rval = CCtsp_pricing_loop (lp, val);
        if (rval) {
            fprintf (stderr, "CCtsp_pricing_loop failed\n");
            rval = 1; goto CLEANUP;
        }
        lp->lowerbound = *val;
        if (lp->upperbound < *upbound) *upbound = lp->upperbound;

        if (lp->lowerbound < lp->upperbound - 0.9) {
            rval = CCtsp_call_x_heuristic (lp, &tourval, besttour);
            if (rval) {
                fprintf (stderr, "CCtsp_call_x_heuristic failed\n");
                goto CLEANUP;
            }
            if (tourval < lp->upperbound) {
                printf ("New upperbound from x-heuristic: %.2f\n", tourval);
                lp->upperbound = tourval;
                *upbound = tourval;
                *foundtour = 1;
            }
        }

        if (lp->lowerbound >= lp->upperbound - 0.9) {
            rval = CCtsp_verify_lp_prune (lp, &test);
            if (rval) {
                fprintf (stderr, "CCtsp_verify_lp_prune failed\n");
                goto CLEANUP;
            }
            if (test) {
                printf ("verified that LP can be pruned\n"); fflush (stdout);
                *prune = 1;
                /* for proof mode, write the lp file here */
            } else {
                fprintf (stderr, "exact pricing could not prune the search\n");
                rval = 1; goto CLEANUP;
            }
        } else {
            rval = CCtsp_write_probfile_id (lp);
            if (rval) {
                fprintf (stderr, "CCtsp_write_probfile_id failed\n");
                goto CLEANUP;
            }
        }
    }

CLEANUP:

    if (lp) CCtsp_free_tsp_lp_struct (&lp);
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_call_x_heuristic (CCtsp_lp *lp, double *val, int *outcyc)
#else
int CCtsp_call_x_heuristic (lp, val, outcyc)
CCtsp_lp *lp;
double *val;
int *outcyc;
#endif
{
    int rval = 0;
    int *cyc   = (int *) NULL;
    int *xlist = (int *) NULL;
    double *x   = (double *) NULL;
    int ncount = lp->graph.ncount;
    int xcount, i;

    *val = CCtsp_LP_MAXDOUBLE;

    if (!lp->dat) goto CLEANUP;

    cyc = CC_SAFE_MALLOC (ncount, int);
    if (!cyc) {
        fprintf (stderr, "out of memory for cycle\n");
        rval = 1; goto CLEANUP;
    }
    rval = CCtsp_get_lp_result (lp, (double *) NULL, (double *) NULL,
         &xcount, &xlist, &x, (double **) NULL, (double **) NULL,
         (double **) NULL);
    if (rval) {
        fprintf (stderr, "CCtsp_get_lp_result failed\n");
        goto CLEANUP;
    }

    rval = CCtsp_x_greedy_tour_lk (lp->dat, ncount, xcount, xlist, x,
                   cyc, val);
    if (rval) {
        fprintf (stderr, "CCtsp_x_greedy_tour_lk failed\n"); goto CLEANUP;
    }
    printf ("x-heuristic lk  gives: %.2f\n", *val);
    if (*val < lp->upperbound) {
        if (outcyc) {
            for (i = 0; i < ncount; i++) {
                outcyc[i] = cyc[i];
            }
        }
    }

CLEANUP:

    CC_IFFREE (cyc, int);
    CC_IFFREE (xlist, int);
    CC_IFFREE (x, double);
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static int bb_cutting_work (CCtsp_lp **lp, char *probname, int probnum,
        int ncount, CCdatagroup *dat, int *ptour, double initial_ub,
        CCtsp_lpcuts *pool, CCtsp_cutselect *sel, double *val)
#else
static int bb_cutting_work (lp, probname, probnum, ncount, dat, ptour,
        initial_ub, pool, sel, val)
CCtsp_lp **lp;
char *probname;
int probnum;
int ncount;
CCdatagroup *dat;
int *ptour;
double initial_ub;
CCtsp_lpcuts *pool;
CCtsp_cutselect *sel;
double *val;
#endif
{
    int rval = 0;

    *lp = (CCtsp_lp *) NULL;
    *val = 0.0;

    rval = CCtsp_bb_init_lp (lp, probname, probnum, ncount, dat, ptour,
               initial_ub, pool);
    if (rval == 2) {
        printf ("LP is reported to be infeasible\n"); fflush (stdout);
        *val = CCtsp_LP_MAXDOUBLE;
        rval = 0; goto CLEANUP;
    } else if (rval) {
        fprintf (stderr, "CCtsp_init_lp failed\n"); goto CLEANUP;
    }

    if ((*lp)->lowerbound >= (*lp)->upperbound - 0.9) {
        printf ("Do not cut, the lp is within 1.0 of the upperbound\n");
        fflush (stdout);
        *val = (*lp)->lowerbound;
        goto CLEANUP;
    } else {
        rval = CCtsp_cutting_loop (*lp, sel, 0);
        if (rval == 2) {
            printf ("Cut LP is reported to be infeasible\n"); fflush (stdout);
        } else if (rval) {
            fprintf (stderr, "CCtsp_cutting_loop failed\n"); goto CLEANUP;
        } else {
            *val = (*lp)->lowerbound;
        }
    }

CLEANUP:

    return rval;
}
