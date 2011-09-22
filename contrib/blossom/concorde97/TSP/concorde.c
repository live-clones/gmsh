/***************************************************************************/
/*                                                                         */
/*                  THE MAIN PROGRAM FOR CONCORDE                          */
/*                                                                         */
/*                           TSP CODE                                      */
/*                                                                         */
/*                                                                         */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook                       */
/*  Date: September 25, 1995                                               */
/*                                                                         */
/*  SEE short decsribtion in usage ().                                     */
/*                                                                         */
/*  Link with:                                                             */
/*    SEE conmake.grs                                                      */
/*                                                                         */
/***************************************************************************/

#include "machdefs.h"
#include "util.h"
#include "edgegen.h"
#include "tsp.h"
#include "linkern.h"
#include "bigguy.h"
#include "macrorus.h"

#define CC_LK_TRY  (1)    /* number of trials to generate initial tour */

static int norm = CC_EUCLIDEAN;
static char *datfname     = (char *) NULL;
static char *edgegenfname = (char *) NULL;
static char *probname     = (char *) NULL;
static char *probfname    = (char *) NULL;
static char *edgefname    = (char *) NULL;
static char *fullfname    = (char *) NULL;
static char *tourfname    = (char *) NULL;
static char *masterfname  = (char *) NULL;
static char *poolfname    = (char *) NULL;
static char *xfname       = (char *) NULL;
static int binary_in = 0;
static int tsplib_in = 0;
static int nnodes_want = 0;
static int seed = 0;
static int just_subtour = 0;
static int valid_edges = 0;
static double initial_ub = CCtsp_LP_MAXDOUBLE;
static int useconsecutiveones = 0;
static int usenecklace = 0;
static int usetighten  = 1;
static int dfs_branching = 0;
static int bfs_branching = 0;
static int usebranchcliques = 0;
static int standalone_branch = 0;


#ifdef CC_PROTOTYPE_ANSI

int
    main (int ac, char **av);

static void
    usage (char *f);

static int
    parseargs (int ac, char **av),
    find_good_tour (int ncount, CCdatagroup *dat, int *perm, double *ub,
            int trials),
    getedges (CCdatagroup *dat, CCedgegengroup *plan, int ncount, int *ecount,
            int **elist, int **elen);

#else

int
    main ();

static void
    usage ();

static int
    parseargs (),
    find_good_tour (),
    getedges ();

#endif


#ifdef CC_PROTOTYPE_ANSI
int main (int ac, char **av)
#else
int main (ac, av)
int ac;
char **av;
#endif
{
    double szeit;
    char dummyname[256];
    int i, ncount;
    CCdatagroup dat;
    CCdatagroup *mydat = (CCdatagroup *) NULL;
    CCtsp_lp *lp = (CCtsp_lp *) NULL;
    CCbigguy bound;
    CCtsp_cutselect sel;
    CCtsp_lpcuts *pool = (CCtsp_lpcuts *) NULL;
    int *ptour = (int *) NULL;
    int ecount = 0;
    int *elist = (int *) NULL;
    int *elen = (int *) NULL;
    int excount = 0;
    int *exlist = (int *) NULL;
    int *exlen = (int *) NULL;
    int *besttour = (int *) NULL;
    int probnum = -1;
    int rval = 0;

    for (i=0; i<ac; i++) {
        printf ("%s", av[i]);
        if (i < ac-1) printf (" ");
    }
    printf ("\n");
    fflush (stdout);

    szeit = CCutil_zeit ();
    seed = (int) CCutil_real_zeit ();
    if (parseargs (ac, av))
        return 0;
    CCutil_sprand (seed);
    printf ("Using random seed %d\n", seed); fflush (stdout);

    if (datfname == (char *) NULL && nnodes_want == 0 && probnum == -1 &&
       probfname == (char *) NULL && edgefname == (char *) NULL &&
       masterfname == (char *) NULL) {
        usage (av[0]);
        return 0;
    }
    ncount = nnodes_want;


    /****** Get the ncount and the data set ******/

    if (masterfname != (char *) NULL) {
        if (CCutil_getmaster (masterfname, &ncount, &dat, &ptour)) {
            fprintf (stderr, "getmaster failed\n");
            return 1;
        }
        if (dat.norm != 0) {
            mydat = &dat;
        } else  {
            mydat = (CCdatagroup *) NULL;
        }
    } else {
        if (tsplib_in && datfname != (char *) NULL) {
            if (CCutil_gettsplib (datfname, &ncount, &dat)) {
                fprintf (stderr, "could not read the TSPLIB file\n");
                rval = 1;
                goto CLEANUP;
            }
            norm = dat.norm;
            mydat = &dat;
        } else if (datfname != (char *) NULL || edgefname == (char *) NULL) {
            if (CCutil_getdata (datfname, binary_in, norm, &ncount, &dat)) {
                fprintf (stderr, "Could not create data set\n");
                rval = 1;
                goto CLEANUP;
            }
            mydat = &dat;
        } else {
            /* Look at edge file to get ncount */

            if (CCutil_getedgelist_n (&ncount, edgefname, &ecount, &elist,
                                      &elen)) {
                fprintf  (stderr, "Could not read edge set\n");
                rval = 1;
                goto CLEANUP;
            }
            printf ("Number of nodes: %d\n", ncount);
            fflush (stdout);

            CC_IFFREE (elist, int);
            CC_IFFREE (elen, int);
            ecount = 0;
            mydat = (CCdatagroup *) NULL;
        }
    }

    if (ncount < 10) {
        fprintf (stderr, "Less than 10 nodes.  Who cares.\n");
        rval = 1;
        goto CLEANUP;
    }
    if (mydat) {
        if (CCutil_init_dat_edgelen (mydat)) {
            fprintf (stderr, "CCutil_init_dat_edgelen failed\n");
            rval = 1;
            goto CLEANUP;
        }
    }


    /***** Get the permutation tour and permute the data  *****/

    if (!ptour) {
        ptour = CC_SAFE_MALLOC (ncount, int);
        if (!ptour) {
            fprintf (stderr, "out of memory in main\n");
            rval = 1;
            goto CLEANUP;
        }

        if (tourfname) {
            rval = CCutil_getcycle (ncount, tourfname, ptour);
            if (rval) {
                fprintf (stderr, "getcycle failed\n");
                goto CLEANUP;
            }
        } else if (mydat) {
            double bnd;
            if (just_subtour) {
                rval = find_good_tour (ncount, mydat, ptour, &bnd, -1);
            } else if (initial_ub == CCtsp_LP_MAXDOUBLE) {
                rval = find_good_tour (ncount, mydat, ptour, &bnd, CC_LK_TRY);
            } else {
                printf ("Initial bnd %f given - use short tour run\n",
                      initial_ub);
                fflush (stdout);
                rval = find_good_tour (ncount, mydat, ptour, &bnd, 0);
            }
            if (rval) {
                fprintf (stderr, "find_good_tour failed\n");
                goto CLEANUP;
            }
        } else {
            fprintf (stderr, "no way to generate the permutation tour\n");
            rval = 1;
            goto CLEANUP;
        }

        if (mydat) {
            rval = CCutil_datagroup_perm (ncount, mydat, ptour);
            if (rval) goto CLEANUP;
        }
    }
    if (mydat) {
        double bnd;

        bnd = CCutil_dat_edgelen (ncount - 1, 0, mydat);
        for (i = 1; i < ncount; i++) {
            bnd += CCutil_dat_edgelen (i-1, i, mydat);
        }
        if (bnd < initial_ub) {
            printf ("Set initial upperbound to %.2f (from tour)\n", bnd);
            fflush (stdout);
            initial_ub = bnd;
        }
    }


    /***** Get the initial edge set *****/

    if (!probfname) {
        if (edgefname) {
            int *invperm = (int *) NULL;

            rval = CCutil_getedgelist (ncount, edgefname, &ecount, &elist,
                                      &elen);
            if (rval) {
                fprintf (stderr, "getedgelist failed\n");
                goto CLEANUP;
            }
            printf ("Initial edgeset: %d edges (%d nodes)\n", ecount, ncount);
            printf ("Rearrange the edges to match the tour order\n");
            fflush (stdout);

            invperm = CC_SAFE_MALLOC (ncount, int);
            if (!invperm) {
                rval = 1;
                goto CLEANUP;
            }
            for (i = 0; i < ncount; i++)
                invperm[ptour[i]] = i;
            for (i = 0; i < 2*ecount; i++)
                elist[i] = invperm[elist[i]];
            CC_FREE (invperm, int);
        } else if (mydat) {
            CCedgegengroup plan;

            if (edgegenfname) {
                rval = CCedgegen_read (edgegenfname, &plan);
                if (rval) {
                    fprintf (stderr, "CCedgegen_read failed\n");
                    return 1;
                }
            } else {
                CCedgegen_init_edgegengroup (&plan);
                if (just_subtour) {
                    plan.tour.greedy = 1;
                    plan.f2match_nearest.number = 4;
                } else {
                    plan.linkern.count = 10;
                    plan.linkern.quadnearest = 2;
                    plan.linkern.greedy_start = 0;
                    plan.linkern.nkicks = (ncount / 100) + 1;
                }
            }

            rval = getedges (mydat, &plan, ncount, &ecount, &elist, &elen);
            if (rval) {
                fprintf (stderr, "getgraph failed\n");
                goto CLEANUP;
            }
        }
    }

    /***** Get the problem name *****/

    if (probname == (char *) NULL) {
        char *p, *q;
        char buf[1024];

        probname = dummyname;

        if (datfname || masterfname) {
            if (datfname)
                sprintf (buf, "%s", datfname);
            else
                sprintf (buf, "%s", masterfname);
            p = CCutil_strrchr (buf, '/');
            if (!p)
                p = buf;
            else
                p++;
            q = CCutil_strrchr (p, '.');
            if (q)
                *q = '\0';
            sprintf (probname, "%s",  p);
        } else {
            sprintf (probname, "%s", "noname");
        }
    }


    /***** Write the master file *****/

    if (!masterfname) {
        char buf[1024];

        sprintf (buf, "%s.mas", probname);
        rval = CCutil_writemaster (buf, ncount, mydat, ptour);
        if (rval) {
            fprintf (stderr, "writemaster failed\n");
            goto CLEANUP;
        }
    }

    /***** Get full edges *****/

    if (fullfname) {
        int *invperm = (int *) NULL;

        rval = CCutil_getedgelist (ncount, fullfname, &excount, &exlist,
                                   &exlen);
        if (rval) {
            fprintf (stderr, "getedgelist failed\n");
            goto CLEANUP;
        }

        invperm = CC_SAFE_MALLOC (ncount, int);
        if (!invperm) {
            fprintf (stderr, "out of memory in main\n");
            rval = 1;
            goto CLEANUP;
        }
        for (i = 0; i < ncount; i++)
            invperm[ptour[i]] = i;
        for (i = 0; i < 2*excount; i++)
            exlist[i] = invperm[exlist[i]];
        CC_FREE (invperm, int);
    } else {
        excount = 0;
    }

    /***** Get the initial cutpool *****/

    rval = CCtsp_init_cutpool (ncount, poolfname, &pool);
    if  (rval) {
        fprintf (stderr, "CCtsp_init_cutpool failed\n");
        goto CLEANUP;
    }

    /***** Initialize besttour to represent the permutation tour  ****/

    besttour = CC_SAFE_MALLOC (ncount, int);
    if (!besttour) {
        fprintf (stderr, "out of memory in allocating best tour\n");
        rval = 1; goto CLEANUP;
    }
    for (i = 0; i < ncount; i++) {
        besttour[i] = i;
    }

    /***** Get the initial LP *****/

    rval = CCtsp_init_lp (&lp, probname, probnum, probfname, ncount, mydat,
                    ecount, elist, elen, excount, exlist, exlen, valid_edges,
                    ptour, initial_ub, pool);
    if (rval == 2) {
        printf ("CCtsp_init_lp reports an infeasible LP\n");
        rval = CCtsp_exact_price (lp, &bound, 1);
        if (rval) {
            fprintf (stderr, "CCtsp_exact_price failed\n");
            goto CLEANUP;
        }
        if (CCbigguy_cmp (bound, CCbigguy_ZERO) < 0) {
            printf ("Problem shown to be infeasible\n");
            fflush (stdout);
            lp->infeasible = 1;
            lp->exact_lowerbound = CCbigguy_MAXBIGGUY;
            goto DONE;
        } else {
            fprintf (stderr, "exact pricing did not verify an infeasible LP\n");
            rval = 1;
            goto CLEANUP;
        }
    } else if (rval) {
        fprintf (stderr, "CCtsp_init_lp failed\n"); goto CLEANUP;
    }

    ecount = 0;
    CC_IFFREE (elist, int);
    CC_IFFREE (elen, int);
    excount = 0;
    CC_IFFREE (exlist, int);
    CC_IFFREE (exlen, int);

    if (lp->full_edges_valid) {
        if (CCtsp_inspect_full_edges (lp)) {
            fprintf (stderr, "full edge set does not contain all LP edges\n");
            rval = 1; goto CLEANUP;
        }
    }

    if (xfname) {
        rval = CCtsp_dump_x (lp, xfname);
        if (rval) {
            fprintf (stderr, "CCtsp_dump_x failed\n");
            goto CLEANUP;
        }
    }

    if (standalone_branch) {
        rval = CCtsp_do_interactive_branch (lp);
        if (rval) {
            fprintf (stderr, "CCtsp_do_interactive_branch failed\n");
            goto CLEANUP;
        } else {
            printf ("completed interative branch\n");
            printf ("Total Running Time: %.2f (seconds)\n",
                               CCutil_zeit () - szeit);
            goto CLEANUP;
        }
    }

    rval = CCtsp_init_cutselect (lp, &sel);
    if (rval) {
        fprintf (stderr, "CCtsp_init_cutselect failed\n");
        goto CLEANUP;
    }
    if (useconsecutiveones) sel.consecutiveones = 1;
    if (usenecklace)        sel.necklace = 1;
    sel.usetighten = usetighten;

    if (just_subtour) {
        rval = CCtsp_subtour_loop (lp);
        if (rval) {
            fprintf (stderr, "CCtsp_subtour_loop failed\n");
            goto CLEANUP;
        }
        printf ("Bound: %f\n", lp->lowerbound); fflush (stdout);
        goto DONE;
    } else {
        rval = CCtsp_cutting_loop (lp, &sel, 1);
        if (rval == 2) {
            printf ("CCtsp_cutting_loop reports an infeasible LP\n");
            rval = CCtsp_exact_price (lp, &bound, 1);
            if (rval) {
                fprintf (stderr, "CCtsp_exact_price failed\n");
                goto CLEANUP;
            }
            if (CCbigguy_cmp (bound, CCbigguy_ZERO) < 0) {
                printf ("Problem shown to be infeasible\n");
                fflush (stdout);
                lp->infeasible = 1;
                lp->exact_lowerbound = CCbigguy_MAXBIGGUY;
                goto DONE;
            } else {
                fprintf (stderr, "pricing did not verify an infeasible LP\n");
                rval = 1; goto CLEANUP;
            }
        } else if (rval) {
            fprintf (stderr, "cutting_loop failed\n");
            goto CLEANUP;
        }
    }

    if (mydat) {
        double tourval;
        rval = CCtsp_call_x_heuristic (lp, &tourval, besttour);
        if (rval) {
            fprintf (stderr, "CCtsp_call_x_heuristic failed\n");
            goto CLEANUP;
        }
        if (tourval < lp->upperbound) {
            printf ("New upperbound from x-heuristic: %.2f\n", tourval);
            lp->upperbound = tourval;
            rval = CCtsp_dumptour (ncount, mydat, ptour, probname, besttour);
            if (rval) {
                fprintf (stderr, "CCtsp_dumptour failed\n"); goto CLEANUP;
            }
        }
    }

    printf ("Final lower bound %f, upper bound %f\n", lp->lowerbound,
                                                      lp->upperbound);
    fflush (stdout);

    if (lp->graph.ncount < 100000) {
        CCbigguy bupper;
        rval = CCtsp_exact_price (lp, &bound, 0);
        if (rval) {
            fprintf (stderr, "CCtsp_exact_price failed\n");
            goto CLEANUP;
        }
        lp->exact_lowerbound = bound;
        printf ("Exact lower bound: %.6f\n", CCbigguy_bigguytod (bound));
        printf ("DIFF: %f\n", lp->lowerbound - CCbigguy_bigguytod (bound));
        fflush (stdout);

        bupper = CCbigguy_dtobigguy (lp->upperbound);
        CCbigguy_sub (&bupper, CCbigguy_ONE);

        if (CCbigguy_cmp (lp->exact_lowerbound, bupper) > 0) {
            printf ("Optimal Solution: %.2f\n", lp->upperbound);
            if (dfs_branching || bfs_branching) {
                printf ("Number of bbnodes: %d\n", 0);
            }
            fflush (stdout);
            goto DONE;
        }

        rval = CCtsp_eliminate_variables (lp);
        if (rval) {
            fprintf (stderr, "CCtsp_eliminate_variables failed\n");
            goto CLEANUP;
        }
    } else {
        printf ("During testing, do not exact price large problems\n");
        fflush (stdout);
        goto DONE;
    }

    if (dfs_branching) {
        double upbound = lp->upperbound;
        int bbcount = 0;

        rval = CCtsp_easy_dfs_brancher (lp, &sel, 0, &upbound, &bbcount,
                                        usebranchcliques, besttour);
        if (rval) {
            fprintf (stderr, "CCtsp_easy_dfs_brancher failed\n");
            goto CLEANUP;
        }
        printf ("Optimal Solution: %.2f\n", upbound);
        printf ("Number of bbnodes: %d\n", bbcount);
        fflush (stdout);
        rval = CCtsp_dumptour (ncount, mydat, ptour, probname, besttour);
        if (rval) {
            fprintf (stderr, "CCtsp_dumptour failed\n"); goto CLEANUP;
        }
    } else if (bfs_branching) {
        double upbound  = lp->upperbound;
        double lowbound = lp->lowerbound;
        int id          = lp->id;
        int bbcount = 0;

        rval = CCtsp_write_probfile_id (lp);
        if (rval) {
            fprintf (stderr, "CCtsp_write_probfile_id failed\n");
            goto CLEANUP;
        }
        CCtsp_free_tsp_lp_struct (&lp);

        rval = CCtsp_bfs_brancher (probname, id, lowbound, &sel, &upbound,
                                   &bbcount, usebranchcliques, mydat, ptour,
                                   pool, ncount, besttour);
        if (rval) {
            fprintf (stderr, "CCtsp_bfs_brancher failed\n"); goto CLEANUP;
        }

        printf ("Optimal Solution: %.2f\n", upbound);
        printf ("Number of bbnodes: %d\n", bbcount);
        fflush (stdout);
        rval = CCtsp_dumptour (ncount, mydat, ptour, probname, besttour);
        if (rval) {
            fprintf (stderr, "CCtsp_dumptour failed\n"); goto CLEANUP;
        }
    }

DONE:

    printf ("Total Running Time: %.2f (seconds)\n", CCutil_zeit () - szeit);
    fflush (stdout);

    if (!dfs_branching && !bfs_branching) {
        CCtsp_print_tighten_info (&lp->tighten_stats);
        CClp_nonzeros (&lp->lp);

        rval = CCtsp_write_probfile_sav (lp);
        if (rval) {
            fprintf (stderr, "CCtsp_write_probfile_sav failed\n");
            goto CLEANUP;
        }
    }

    if (pool && pool->cutcount) {
        char buf[1024];
        printf ("Final Pool: %d cuts\n", pool->cutcount);
        fflush (stdout);

        sprintf (buf, "%s.pul", probname);
        rval = CCtsp_write_cutpool (ncount, buf, pool);
        if (rval) {
            fprintf (stderr, "CCtsp_write_cutpool failed\n");
            goto CLEANUP;
        }
    }
    rval = 0;

CLEANUP:

    CCtsp_free_tsp_lp_struct (&lp);

    if (pool) {
        CCtsp_free_cutpool (&pool);
    }

    CC_IFFREE (elist, int);
    CC_IFFREE (elen, int);
    CC_IFFREE (exlist, int);
    CC_IFFREE (exlen, int);
    CC_IFFREE (ptour, int);
    CC_IFFREE (besttour, int);
    if (mydat)
        CCutil_freedatagroup (ncount, mydat);
    if (CCutil_bigchunk_free_world ()) {
        fprintf (stderr, "ERROR: CCutil_bigchunk_free_world failed\n");
        return 1;
    }

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static int find_good_tour (int ncount, CCdatagroup *dat, int *perm, double *ub,
                           int trials)
#else
static int find_good_tour (ncount, dat, perm, ub, trials)
int ncount;
CCdatagroup *dat;
int *perm;
double *ub;
int trials;
#endif
{
    int rval = 0;
    CCedgegengroup plan;
    int ecount;
    int *elist = (int *) NULL;
    int tcount;
    int *tlist = (int *) NULL;
    int *bestcyc = (int *) NULL;
    int *cyc     = (int *) NULL;
    int *tmp;
    double val, bestval, szeit;
    int kicks;
    int i;

    szeit = CCutil_zeit ();
    bestval = CCtsp_LP_MAXDOUBLE;

    if (trials == -1) {
        kicks = (ncount > 400 ? 100 : ncount/4);
    } else {
        kicks = (ncount > 1000 ? 500 : ncount/2);
    }

    printf ("Finding a good tour for compression: %d\n", trials);
    fflush (stdout);

    cyc     = CC_SAFE_MALLOC (ncount, int);
    bestcyc = CC_SAFE_MALLOC (ncount, int);
    if (!cyc || !bestcyc) {
        fprintf (stderr, "out of memory in find_good_tour\n");
        rval = 1; goto CLEANUP;
    }

    CCedgegen_init_edgegengroup (&plan);
    plan.quadnearest = 2;
    rval = CCedgegen_edges (&plan, ncount, dat, (double *) NULL, &ecount,
                            &elist);
    if (rval) {
        fprintf (stderr, "CCedgegen_edges failed\n"); goto CLEANUP;
    }
    plan.quadnearest = 0;


    plan.tour.greedy = 1;
    rval = CCedgegen_edges (&plan, ncount, dat, (double *) NULL, &tcount,
                            &tlist);
    if (rval) {
        fprintf (stderr, "CCedgegen_edges failed\n"); goto CLEANUP;
    }

    if (tcount != ncount) {
        fprintf (stderr, "wrong edgeset from edgegen\n");
        rval = 1; goto CLEANUP;
    }

    rval = CCutil_edge_to_cycle (ncount, tlist, cyc);
    if (rval) {
        fprintf (stderr, "CCutil_edge_to_cycle failed\n");
        rval = 1; goto CLEANUP;
    }
    CC_FREE (tlist, int);

    rval = CClinkern_tour (ncount, dat, ecount, elist, ncount, kicks,
                    cyc, bestcyc, &bestval, 0, 0.0, 0.0, (char *) NULL);
    if (rval) {
        fprintf (stderr, "CClinkern_tour failed\n"); goto CLEANUP;
    }

    for (i = 0; i < trials; i++) {
        rval = CClinkern_tour (ncount, dat, ecount, elist, ncount, kicks,
                        (int *) NULL, cyc, &val, 0, 0.0, 0.0, (char *) NULL);
        if (rval) {
            fprintf (stderr, "CClinkern_tour failed\n"); goto CLEANUP;
        }
        if (val < bestval) {
            CC_SWAP (cyc, bestcyc, tmp);
            bestval = val;
        }
    }

    if (trials > 0) {
        rval = CClinkern_tour (ncount, dat, ecount, elist, ncount, 2 * kicks,
                        bestcyc, perm, ub, 0, 0.0, 0.0, (char *) NULL);
        if (rval) {
            fprintf (stderr, "CClinkern_tour failed\n"); goto CLEANUP;
        }
    } else {
        for (i = 0; i < ncount; i++) {
            perm[i] = bestcyc[i];
        }
    }

    printf ("Time to find compression tour: %.2f (seconds)\n", CCutil_zeit () - szeit);
    fflush (stdout);

CLEANUP:

    CC_IFFREE (cyc, int);
    CC_IFFREE (bestcyc, int);
    CC_IFFREE (elist, int);
    CC_IFFREE (tlist, int);
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static int getedges (CCdatagroup *dat, CCedgegengroup *plan, int ncount,
                     int *ecount, int **elist, int **elen)
#else
static int getedges (dat, plan, ncount, ecount, elist, elen)
CCdatagroup *dat;
CCedgegengroup *plan;
int ncount, *ecount, **elist, **elen;
#endif
{
    int i;

    *elist = (int *) NULL;
    *elen = (int *) NULL;

    if (dat == (CCdatagroup *) NULL || plan == (CCedgegengroup *) NULL) {
        fprintf (stderr, "getedges needs CCdatagroup and CCedgegenplan\n");
        return 1;
    }

    if (CCedgegen_edges (plan, ncount, dat, (double *) NULL, ecount, elist)) {
        fprintf (stderr, "CCedgegen_edges failed\n");
        return 1;
    }
    *elen = CC_SAFE_MALLOC(*ecount, int);
    if (!(*elen)) {
        CC_FREE (*elist, int);
        return 1;
    }
    for (i = 0; i < *ecount; i++) {
        (*elen)[i] =
             CCutil_dat_edgelen ((*elist)[2*i], (*elist)[(2*i) + 1], dat);
    }

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int parseargs (int ac, char **av)
#else
static int parseargs (ac, av)
int ac;
char **av;
#endif
{
    int c;

    while ((c = CCutil_bix_getopt (ac, av, "bBcdD:e:E:fk:lM:n:N:P:s:STt:u:vUX:Y0123456789")) != EOF)
        switch (c) {
        case 'b':
            binary_in = 1;
            break;
        case 'B':
            bfs_branching = 1;
            break;
        case 'c':
            useconsecutiveones = 1;
            break;
        case 'd':
            dfs_branching = 1;
            break;
        case 'D':
            edgegenfname = CCutil_bix_optarg;
            break;
        case 'e':
            edgefname = CCutil_bix_optarg;
            break;
        case 'E':
            fullfname = CCutil_bix_optarg;
            break;
        case 'f':
            usetighten = 0;
            break;
        case 'k':
            nnodes_want = atoi (CCutil_bix_optarg);
            break;
        case 'l':
            usenecklace = 1;
            break;
        case 'n':
            probname = CCutil_bix_optarg;
            break;
        case 'M':
            masterfname = CCutil_bix_optarg;
            break;
        case 'N':
            probfname = CCutil_bix_optarg;
            break;
        case 'P':
            poolfname = CCutil_bix_optarg;
            break;
        case 's':
            seed = atoi (CCutil_bix_optarg);
            break;
        case 'S':
            just_subtour = 1;
            break;
        case 'T':
            tsplib_in = 1;
            break;
        case 't':
            tourfname =  CCutil_bix_optarg;
            break;
        case 'u':
            initial_ub = atof (CCutil_bix_optarg);
            break;
        case 'v':
            valid_edges = 1;
            break;
        case 'U':
            usebranchcliques = 1;
            break;
        case 'X':
            xfname = CCutil_bix_optarg;
            break;
        case 'Y':
            standalone_branch = 1;
            break;
        case '0':
            norm = CC_MAXNORM;
            break;
        case '1':
            norm = CC_EUCLIDEAN_CEIL;
            break;
        case '2':
            norm = CC_EUCLIDEAN;
            break;
        case '3':
            norm = CC_EUCLIDEAN_3D;
            break;
        case '4':
            norm = CC_IBM;
            break;
        case '5':
            norm = CC_ATT;
            break;
        case '6':
            norm = CC_GEOGRAPHIC;
            break;
        case '7':
            norm = CC_MATRIXNORM;
            break;
        case '8':
            norm = CC_DSJRANDNORM;
            break;
        case '9':
            norm = CC_CRYSTAL;
            break;
        case CC_BIX_GETOPT_UNKNOWN:
        case '?':
        default:
            usage (av[0]);
            return 1;
        }
    if (CCutil_bix_optind < ac) {
        datfname = av[CCutil_bix_optind++];
    }

    if (CCutil_bix_optind != ac) {
        usage (av[0]);
        return 1;
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static void usage (char *f)
#else
static void usage (f)
char *f;
#endif
{
    fprintf (stderr, "Usage: %s [-see below-] [dat_file]\n", f);
    fprintf (stderr, "   -b    datfile in integer binary format\n");
    fprintf (stderr, "   -B    run best-bound branching\n");
    fprintf (stderr, "   -c    use consecutive ones cuts\n");
    fprintf (stderr, "   -d    dfs search\n");
    fprintf (stderr, "   -D f  edgegen file for initial edge set\n");
    fprintf (stderr, "   -e f  initial edge file\n");
    fprintf (stderr, "   -E f  full edge file\n");
    fprintf (stderr, "   -f    don't call tighten for each cut\n");
    fprintf (stderr, "   -k #  number of nodes for random problem\n");
    fprintf (stderr, "   -l    use necklace cuts\n");
    fprintf (stderr, "   -M f  master file\n");
    fprintf (stderr, "   -n s  problem name (just a name, not a file name)\n");
    fprintf (stderr, "   -N f  prob file\n");
    fprintf (stderr, "   -P f  cutpool file\n");
    fprintf (stderr, "   -s #  random seed\n");
    fprintf (stderr, "   -S    just solve the subtour polytope\n");
    fprintf (stderr, "   -T    the dat file is a TSPLIB file\n");
    fprintf (stderr, "   -t f  tour file (in node node node format)\n");
    fprintf (stderr, "   -u v  initial upperbound\n");
    fprintf (stderr, "   -U    permit branching on subtour inequalities\n");
    fprintf (stderr, "   -v    full list valid (must contain initial list)\n");
    fprintf (stderr, "   -(0 1 2 3) price out using (MAX JOHNSON L2 3D)  norm\n");
    fprintf (stderr, "   -(4 5 6 7 8 9) IBM ATT GEO MATRIX DSJRAND CRYSTAL norm\n");
}
