/***************************************************************************/
/*                                                                         */
/*                  CODE FOR TESTING KD-TREE ROUTINES                      */
/*                                                                         */
/*                             TSP CODE                                    */
/*                                                                         */
/*                                                                         */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook                       */
/*  Date: February 24, 1995  (cofeb24)                                     */
/*                                                                         */
/*  For a short describtion see usage ()                                   */
/*                                                                         */
/***************************************************************************/


#include "machdefs.h"
#include "util.h"
#include "kdtree.h"

static int norm = CC_EUCLIDEAN;
static int usenodeweights = 0;
static int random_weight_limit = 0;
static int seed = 0;
static int nnodes_want = 0;
static int nearnum = 0;
static int quadnearnum = 0;
static int find_nearest_tour = 0;
static int find_nearest_2match = 0;
static int find_greedy_tour = 0;
static int find_fa_tour = 0;
static int find_qboruvka_tour = 0;
static int find_boruvka_tour = 0;
static int find_twoopt_tour = 0;
static int find_3opt_tour = 0;
static int find_spanning_tree = 0;
static int run_two_and_a_half_opt = 0;
static int binary_in = 0;
static int tsplib_in = 0;

static char *nodefile = (char *) NULL;
static char *weightfile = (char *) NULL;
static char *cycle_for_twoopt = (char *) NULL;
static char *outfile = (char *) NULL;


#ifdef CC_PROTOTYPE_ANSI

int
    main (int ac, char **av);
static void
    usage (char *f);
static int
    parseargs (int ac, char **av);

#else

int
    main ();
static void
    usage ();
static int
    parseargs ();

#endif

#ifdef CC_PROTOTYPE_ANSI
int main (int ac, char **av)
#else
int main (ac, av)
int ac;
char **av;
#endif
{
    double val, szeit;
    CCkdtree kt;
    CCdatagroup dat;
    double *wcoord = (double *) NULL;
    int ncount;
    int *ttour = (int *) NULL, *tour2 = (int *) NULL;
    int rval = 0;
    int ecount;
    int *elist = (int *) NULL;

    seed = (int) CCutil_real_zeit ();
    if (parseargs (ac, av))
        return 1;
    CCutil_sprand (seed);

    if ((!nnodes_want && !nodefile) || (tsplib_in && !nodefile)) {
        usage (av[0]);
        return 1;
    }

    if (tsplib_in) {
        if (CCutil_gettsplib (nodefile, &ncount, &dat)) {
            fprintf (stderr, "could not read the TSPLIB file\n");
            rval = 1;
            goto CLEANUP;
        }
        norm = dat.norm;
    } else {
        ncount = nnodes_want;
        if (CCutil_getdata (nodefile, binary_in, norm, &ncount, &dat)) {
            rval = 1;
            goto CLEANUP;
        }
    }
    if ((norm & CC_NORM_BITS) != CC_KD_NORM_TYPE) {
        fprintf (stderr, "Cannot run CCkdtree with norm %d\n", norm);
        rval = 1;
        goto CLEANUP;
    }

    if (CCutil_init_dat_edgelen (&dat)) {
        fprintf (stderr, "init_dat_edgelen failed\n");
        rval = 1;
        goto CLEANUP;
    }

    if (usenodeweights) {
        if (CCutil_getnodeweights (weightfile, ncount, random_weight_limit,
                                   &wcoord)) {
            fprintf (stderr, "could not read the nodeweight file\n");
            rval = 1;
            goto CLEANUP;
        }
    }

    if (find_nearest_tour || find_greedy_tour || find_twoopt_tour ||
        find_fa_tour || find_qboruvka_tour || find_boruvka_tour ||
        find_3opt_tour) {
        ttour = CC_SAFE_MALLOC (ncount, int);
        if (!ttour) {
            rval = 1;
            goto CLEANUP;
        }
    }
    if (find_twoopt_tour || find_3opt_tour) {
        tour2 = CC_SAFE_MALLOC (ncount, int);
        if (!tour2) {
            rval = 1;
            goto CLEANUP;
        }
    }

    if (cycle_for_twoopt) {
        if (CCutil_getcycle (ncount, cycle_for_twoopt, ttour)) {
            fprintf (stderr, "Getcycle failed\n");
            rval = 1;
            goto CLEANUP;
        }
    } else if (find_nearest_tour) {
        szeit = CCutil_zeit ();
        if (CCkdtree_nearest_neighbor_tour ((CCkdtree *) NULL, ncount,
                  CCutil_lprand () % ncount, &dat, ttour, &val)) {
            fprintf (stderr, "Nearest neighbor failed\n");
            rval = 1;
            goto CLEANUP;
        }
        printf ("NN tour: %.2f (%.2f seconds)\n", val, CCutil_zeit () - szeit);
        fflush (stdout);
    } else if (find_fa_tour) {
        szeit = CCutil_zeit ();
        if (CCkdtree_far_add_tour ((CCkdtree *) NULL, ncount,
                  CCutil_lprand () % ncount, &dat, ttour, &val)) {
            fprintf (stderr, "Farthest Addition Tour failed\n");
            rval = 1;
            goto CLEANUP;
        }
        printf ("FA tour: %.2f (%.2f seconds)\n", val, CCutil_zeit () - szeit);
        fflush (stdout);
        {
            char *marks;
            int i;

            marks = CC_SAFE_MALLOC (ncount, char);
            if (!marks) {
                rval = 1;
                goto CLEANUP;
            }
            for (i = 0; i < ncount; i++)
                marks[i] = 0;
            for (i = 0; i < ncount; i++) {
                if (ttour[i] < 0 || ttour[i] >= ncount) {
                    fprintf (stderr, "MADE NODE IN FA TOUR: %d\n", ttour[i]);
                    rval = 1;
                    goto CLEANUP;
                }
                if (marks[ttour[i]]) {
                    fprintf (stderr, "REPEAT NODE IN FA-TOUR: %d\n", ttour[i]);
                    fprintf (stderr, "BAD INDEX: %d\n", i);
                    rval = 1;
                    goto CLEANUP;
                } else {
                    marks[ttour[i]] = 1;
                }
            }
            CC_FREE (marks, char);
        }
    } else if (find_boruvka_tour) {
        szeit = CCutil_zeit ();
        if (CCkdtree_boruvka_tour ((CCkdtree *) NULL, ncount, &dat, ttour,
                                    &val)) {
            fprintf (stderr, "Boruvka tour failed\n");
            rval = 1;
            goto CLEANUP;
        }
        printf ("Boruvka tour: %.2f (%.2f seconds)\n",
                         val, CCutil_zeit () - szeit);
        fflush (stdout);
    } else if (find_qboruvka_tour) {
        szeit = CCutil_zeit ();
        if (CCkdtree_qboruvka_tour ((CCkdtree *) NULL, ncount, &dat, ttour,
                                     &val)) {
            fprintf (stderr, "Quick-Boruvka tour failed\n");
            rval = 1;
            goto CLEANUP;
        }
        printf ("Quick-Boruvka tour: %.2f (%.2f seconds)\n",
                         val, CCutil_zeit () - szeit);
        fflush (stdout);
    } else if (find_greedy_tour) {
        szeit = CCutil_zeit ();
        if (CCkdtree_greedy_tour ((CCkdtree *) NULL, ncount, &dat, ttour,
                                   &val)) {
            fprintf (stderr, "Greedy tour failed\n");
            rval = 1;
            goto CLEANUP;
        }
        printf ("Greedy tour: %.2f (%.2f seconds)\n",
                         val, CCutil_zeit () - szeit);
        fflush (stdout);
    }

    if (find_twoopt_tour) {
        szeit = CCutil_zeit ();
        if (CCkdtree_twoopt_tour ((CCkdtree *) NULL, ncount, &dat, ttour,
                                tour2, &val, run_two_and_a_half_opt, 0)) {
            fprintf (stderr, "Two-opt failed\n");
            rval = 1;
            goto CLEANUP;
        }
        printf ("2-opt tour: %.2f (%.2f seconds))\n",
                         val, CCutil_zeit () - szeit);
        fflush (stdout);
    } else if (find_3opt_tour) {
        szeit = CCutil_zeit ();
        if (CCkdtree_3opt_tour ((CCkdtree *) NULL, ncount, &dat, ttour, tour2,
                                 &val, 0)) {
            fprintf (stderr, "3-opt failed\n");
            rval = 1;
            goto CLEANUP;
        }
        printf ("3-opt tour: %.2f (%.2f seconds))\n",
                         val, CCutil_zeit () - szeit);
        fflush (stdout);
        {
            char *marks;
            int i;

            marks = CC_SAFE_MALLOC (ncount, char);
            if (!marks) {
                rval = 1;
                goto CLEANUP;
            }
            for (i = 0; i < ncount; i++)
                marks[i] = 0;
            for (i = 0; i < ncount; i++) {
                if (tour2[i] < 0 || tour2[i] >= ncount) {
                    fprintf (stderr, "MADE NODE IN TOUR2: %d\n", tour2[i]);
                    rval = 1;
                    goto CLEANUP;
                }
                if (marks[tour2[i]]) {
                    fprintf (stderr, "REPEATED NODE IN TOUR2: %d\n",
                             tour2[i]);
                    rval = 1;
                    goto CLEANUP;
                } else {
                    marks[tour2[i]] = 1;
                }
            }
            CC_FREE (marks, char);
        }
    }

    if (find_spanning_tree) {
        if (outfile) {
            ecount = ncount - 1;
            elist = CC_SAFE_MALLOC (2 * ecount, int);
            if (!elist) {
                rval = 1;
                goto CLEANUP;
            }
        }
        szeit = CCutil_zeit ();
        if (CCkdtree_prim_spanningtree ((CCkdtree *) NULL, ncount, &dat, wcoord,
                                         elist, &val)) {
            fprintf (stderr, "Prim_spanningtree failed\n");
            rval = 1;
            goto CLEANUP;
        }
        printf ("Min spanning tree: %.2f (%.2f seconds)\n", val,
                 CCutil_zeit () - szeit);
        fflush (stdout);
    } else if (nearnum) {
        int wantlist = (outfile ? 1 : 0);
        szeit = CCutil_zeit ();
        if (CCkdtree_k_nearest ((CCkdtree *) NULL, ncount, nearnum, &dat,
                                 wcoord, wantlist, &ecount, &elist)) {
            fprintf (stderr, "k-nearest failed\n");
            rval = 1;
            goto CLEANUP;
        }
        printf ("Nearest %d: %.2f (seconds)\n",
                         nearnum, CCutil_zeit () - szeit);
        fflush (stdout);
    } else if (quadnearnum) {
        int wantlist = (outfile ? 1 : 0);
        szeit = CCutil_zeit ();
        if (CCkdtree_quadrant_k_nearest ((CCkdtree *) NULL, ncount, quadnearnum,
              &dat, wcoord, wantlist, &ecount, &elist)) {
            fprintf (stderr, "k-nearest failed\n");
            rval = 1;
            goto CLEANUP;
        }
        printf ("Quadrant-Nearest %d: %.2f (seconds)\n", quadnearnum,
                 CCutil_zeit () - szeit);
        fflush (stdout);
    } else if (find_nearest_2match) {
        if (outfile) {
            ecount = ncount;
            elist = CC_SAFE_MALLOC (2 * ecount, int);
            if (!elist) {
                rval = 1;
                goto CLEANUP;
            }
        }
        szeit = CCutil_zeit ();
        if (CCkdtree_nearest_neighbor_2match ((CCkdtree *) NULL, ncount,
               CCutil_lprand () % ncount, &dat, elist, &val)) {
            fprintf (stderr, "Nearest neighbor 2-matching failed\n");
            rval = 1;
            goto CLEANUP;
        }
        printf ("Nearest 2-matching: %.2f (%.2f seconds)\n", val,
                 CCutil_zeit () - szeit);
        fflush (stdout);
    } else if (!find_nearest_tour && !find_greedy_tour && !find_twoopt_tour &&
               !find_qboruvka_tour && !find_boruvka_tour && !find_fa_tour &&
               !find_3opt_tour) {
        szeit = CCutil_zeit ();
        if (CCkdtree_build (&kt, ncount, &dat, wcoord)) {
            fprintf (stderr, "CCkdtree_build failed\n");
            rval = 1;
            goto CLEANUP;
        }
        printf ("Built CCkdtree: %.2f (seconds)\n", CCutil_zeit () - szeit);
        fflush (stdout);
        CCkdtree_free (&kt);
    }

    if (outfile) {
        if (find_twoopt_tour || find_3opt_tour) {
            if (CCutil_writecycle (ncount, outfile, tour2)) {
                fprintf (stderr, "Could not write tour\n");
                rval = 1;
                goto CLEANUP;
            }
        } else if (find_nearest_tour || find_greedy_tour || find_fa_tour ||
                   find_qboruvka_tour || find_boruvka_tour) {
            if (CCutil_writecycle (ncount, outfile, ttour)) {
                fprintf (stderr, "Could not write tour\n");
                rval = 1;
                goto CLEANUP;
            }
        } else if (find_spanning_tree ||  find_nearest_2match || nearnum ||
                                                             quadnearnum) {
            if (CCutil_writeedges (ncount, outfile, ecount, elist, &dat)) {
                fprintf (stderr, "Could not write the edge set\n");
                rval = 1;
                goto CLEANUP;
            }
        }
    }


CLEANUP:

    CCutil_freedatagroup (ncount, &dat);
    if (wcoord)
        CC_FREE (wcoord, double);
    if (ttour)
        CC_FREE (ttour, int);
    if (tour2)
        CC_FREE (tour2, int);
    if (elist)
        CC_FREE (elist, int);
    if (CCutil_bigchunk_free_world ()) {
        fprintf (stderr, "ERROR: CCutil_bigcunk free world failed\n");
        return 1;
    }
    return rval;
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

    while ((c = CCutil_bix_getopt (ac, av, "bfghjk:mn:o:pq:s:tTvw:W:x:Xz:Z012?")) != EOF)
        switch (c) {
        case 'b':
            binary_in = 1;
            break;
        case 'f':
            find_fa_tour = 1;
            break;
        case 'j':
            find_qboruvka_tour = 1;
            break;
        case 'w':
            usenodeweights = 1;
            weightfile = CCutil_bix_optarg;
            break;
        case 'W':
            usenodeweights = 1;
            random_weight_limit = atoi (CCutil_bix_optarg);
            break;
        case 'k':
            nnodes_want = atoi (CCutil_bix_optarg);
            break;
        case 's':
            seed = atoi (CCutil_bix_optarg);
            break;
        case 'n':
            nearnum = atoi (CCutil_bix_optarg);
            break;
        case 'm':
            find_nearest_2match++;
            break;
        case 'q':
            quadnearnum = atoi (CCutil_bix_optarg);
            break;
        case 't':
            find_nearest_tour++;
            break;
        case 'g':
            find_greedy_tour++;
            break;
        case 'v':
            find_boruvka_tour++;
            break;
        case 'Z':
            find_twoopt_tour++;
            find_greedy_tour++;
            break;
        case 'z':
            cycle_for_twoopt = CCutil_bix_optarg;
            find_twoopt_tour++;
            break;
        case 'X':
            find_3opt_tour++;
            find_greedy_tour++;
            break;
        case 'x':
            cycle_for_twoopt = CCutil_bix_optarg;
            find_3opt_tour++;
            break;
        case 'h':
            run_two_and_a_half_opt++;
            break;
        case 'o':
            outfile = CCutil_bix_optarg;
            break;
        case 'p':
            find_spanning_tree++;
            break;
        case 'T':
            tsplib_in = 1;
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
        case CC_BIX_GETOPT_UNKNOWN:
        case '?':
        default:
            usage (av[0]);
            return 1;
        }
    if (CCutil_bix_optind < ac)
        nodefile = av[CCutil_bix_optind++];

    if (CCutil_bix_optind > ac) {
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
    fprintf (stderr, "Usage: %s [- see below -] [node_file]\n", f);
    fprintf (stderr, "          -b:   dat file in binary-ints\n");
    fprintf (stderr, "          -w f  use node weights from file\n");
    fprintf (stderr, "          -W #  use random node weights (0, #)\n");
    fprintf (stderr, "          -k #  number of nodes for random problem\n");
    fprintf (stderr, "          -s #  random seed\n");
    fprintf (stderr, "          -n #  find # nearest graph\n");
    fprintf (stderr, "          -q #  find quadrant # nearest graph\n");
    fprintf (stderr, "          -t    nearest neighbor tour\n");
    fprintf (stderr, "          -g    greedy tour\n");
    fprintf (stderr, "          -j    quick-boruvka tour\n");
    fprintf (stderr, "          -v    boruvka tour\n");
    fprintf (stderr, "          -f    farthest addition tour\n");
    fprintf (stderr, "          -z f  two_opt the given cycle\n");
    fprintf (stderr, "          -Z    run two_opt (default: on greedy)\n");
    fprintf (stderr, "          -x f  3_opt the given cycle\n");
    fprintf (stderr, "          -X    run 3_opt (default: on greedy)\n");
    fprintf (stderr, "          -h    use limited 3-swaps in two_opt\n");
    fprintf (stderr, "          -m    nearest neighbor 2-matcing\n");
    fprintf (stderr, "          -p    min spanning tree (prim)\n");
    fprintf (stderr, "          -o f  write the cycle or edge set to f\n");
    fprintf (stderr, "          -T    node file is a TSPLIB file\n");
    fprintf (stderr, "          -0    Max norm for edge lengths\n");
    fprintf (stderr, "          -1    Euclidean Ceiling norm\n");
    fprintf (stderr, "          -2    Rounded Euclidean norm (default)\n");
}
