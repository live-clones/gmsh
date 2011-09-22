/***************************************************************************/
/*                                                                         */
/*               CODE FOR TESTING ITERATED LIN-KERNIGHAN                   */
/*                                                                         */
/*                             TSP CODE                                    */
/*                                                                         */
/*                                                                         */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook                       */
/*  Date: March 17, 1995                                                   */
/*                                                                         */
/*  For a short describtion see usage ()                                   */
/*                                                                         */
/***************************************************************************/

#include "machdefs.h"
#include "util.h"
#include "linkern.h"
#include "kdtree.h"
#include "edgegen.h"

#define BIGDOUBLE 1000000000.0
#define SWAP(x,y,temp) {(temp) = (x); (x) = (y); (y) = (temp);}

static int norm = CC_EUCLIDEAN;
static int seed = 0;
static int binary_in = 0;
static int tsplib_in = 0;
static int nnodes_want = 0;
static int usegreedy = 0;
static int useqboruvka = 0;
static int useboruvka = 0;
static int userandom = 0;
static int nearnum = 0;
static int quadtry = 2;
static int run_silently = 0;

static int in_repeater = 0;
static int number_runs = 0;
static int print_final = 0;
static double time_bound = -1.0;
static double length_bound = -1.0;

static char *nodefile = (char *) NULL;
static char *goodfname = (char *) NULL;
static char *cycfname = (char *) NULL;
static char *edgegenfname = (char *) NULL;
static char *edgecycfname = (char *) NULL;
static char *process_name = (char *) NULL;
static char *saveit_name = (char *) NULL;
static char edgecyclefilename[256];

#ifdef CC_PROTOTYPE_ANSI

int
    main (int, char **);
static int
    parseargs (int, char **);
static void
    setupnames (char *n1, char *n2, int ncount),
    randcycle (int ncount, int *cyc),
    usage (char *f);

#else

int
    main ();
static int
    parseargs ();
static void
    setupnames (),
    randcycle (),
    usage ();

#endif

#ifdef CC_PROTOTYPE_ANSI
int main (int ac, char **av)
#else
int main (ac, av)
int ac;
char **av;
#endif
{
    int k, ncount;
    double val, best;
    double startzeit;
    int tempcount, *templist;
    int *incycle = (int *) NULL, *outcycle = (int *) NULL;
    CCdatagroup dat;
    int rval = 0;

    seed = (int) CCutil_real_zeit ();
    if (parseargs (ac, av))
        return 1;
    CCutil_sprand (seed);

    printf ("Chained Lin-Kernighan with seed %d\n", seed);
    fflush (stdout);

    if ((!nnodes_want && !nodefile) || (tsplib_in && !nodefile)) {
        usage (av[0]);
        return 1;
    }

    startzeit = CCutil_zeit ();
    setupnames (nodefile, process_name, nnodes_want);

    dat.x = (double *) NULL;
    dat.y = (double *) NULL;
    dat.z = (double *) NULL;
    dat.adj = (int **) NULL;

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

    if (CCutil_init_dat_edgelen (&dat)) {
        fprintf (stderr, "CCutil_init_dat_edgelen failed\n");
        rval = 1;
        goto CLEANUP;
    }

    incycle = CC_SAFE_MALLOC (ncount, int);
    if (!incycle) {
        rval = 1;
        goto CLEANUP;
    }
    if (cycfname) {
        if (CCutil_getcycle (ncount, cycfname, incycle)) {
            fprintf (stderr, "CCutil_getcycle failed\n");
            rval = 1;
            goto CLEANUP;
        }
    } else if (edgecycfname) {
        if (CCutil_getcycle_edgelist (ncount, edgecycfname, incycle)) {
            fprintf (stderr, "CCutil_getcycle_edgelist failed\n");
            rval = 1;
            goto CLEANUP;
        }
    }

    if (goodfname) {
        int *templen = (int *) NULL;
        if (CCutil_getedgelist (ncount, goodfname, &tempcount, &templist,
                                &templen)) {
            rval = 1;
            goto CLEANUP;
        }
        if (templen)
            CC_FREE (templen, int);
        printf ("Read good-edge file: %d edges\n", tempcount);
        fflush (stdout);
    } else if (edgegenfname) {
        CCedgegengroup plan;
        if (CCedgegen_read (edgegenfname, &plan)) {
            fprintf (stderr, "CCedgegen_read failed\n");
            rval = 1;
            goto CLEANUP;
        }
        if (CCedgegen_edges (&plan, ncount, &dat, (double *) NULL, &tempcount,
                             &templist)) {
            fprintf (stderr, "CCedgegen_edges failed\n");
            rval = 1;
            goto CLEANUP;
        }
    }

    if ((norm & CC_NORM_BITS) == CC_KD_NORM_TYPE) {
        CCkdtree localkt;
        double kzeit = CCutil_zeit ();

        if ((!goodfname && !edgegenfname) || (!cycfname && !edgecycfname)) {
            if (CCkdtree_build (&localkt, ncount, &dat, (double *) NULL)) {
                fprintf (stderr, "CCkdtree_build failed\n");
                rval = 1;
                goto CLEANUP;
            }
            printf ("Time to build kdtree: %.2f\n", CCutil_zeit () - kzeit);
            fflush (stdout);

            if (!goodfname && !edgegenfname) {
                kzeit = CCutil_zeit ();
                if (nearnum) {
                    if (CCkdtree_k_nearest (&localkt, ncount, nearnum, &dat,
                               (double *) NULL, 1, &tempcount, &templist)) {
                        fprintf (stderr, "CCkdtree_k_nearest failed\n");
                        rval = 1;
                        goto CLEANUP;
                    }
                    if (!run_silently) {
                        printf ("Time to find %d-nearest: %.2f\n", nearnum,
                                                     CCutil_zeit () - kzeit);
                        fflush (stdout);
                    }
                } else {
                    if (CCkdtree_quadrant_k_nearest (&localkt, ncount, quadtry,
                           &dat, (double *) NULL, 1, &tempcount, &templist)) {
                        fprintf (stderr, "CCkdtree-quad nearest code failed\n");
                        rval = 1;
                        goto CLEANUP;
                    }
                    if (!run_silently) {
                        printf ("Time to find quad %d-nearest: %.2f\n", quadtry,
                                                     CCutil_zeit () - kzeit);
                        fflush (stdout);
                    }
                }
            }
            if (!cycfname && !edgecycfname) {
                kzeit = CCutil_zeit ();
                if (usegreedy) {
                    if (CCkdtree_greedy_tour (&localkt, ncount,
                              &dat, incycle, &val)) {
                        fprintf (stderr, "CCkdtree greedy-tour failed\n");
                        rval = 1;
                        goto CLEANUP;
                    }
                } else if (useqboruvka) {
                    if (CCkdtree_qboruvka_tour (&localkt, ncount,
                              &dat, incycle, &val)) {
                        fprintf (stderr, "CCkdtree qboruvak-tour failed\n");
                        rval = 1;
                        goto CLEANUP;
                    }
                } else if (useboruvka) {
                    if (CCkdtree_boruvka_tour (&localkt, ncount,
                              &dat, incycle, &val)) {
                        fprintf (stderr, "CCkdtree boruvka-tour failed\n");
                        rval = 1;
                        goto CLEANUP;
                    }
                } else if (userandom) {
                    randcycle (ncount, incycle);
                } else {
                    if (CCkdtree_nearest_neighbor_tour (&localkt, ncount,
                           CCutil_lprand () % ncount, &dat, incycle, &val)) {
                        fprintf (stderr, "CCkdtree NN-tour failed\n");
                        rval = 1;
                        goto CLEANUP;
                    }
                }
                if (!run_silently) {
                    printf ("Time to grow tour: %.2f\n", CCutil_zeit() - kzeit);
                    fflush (stdout);
                }
            }
            CCkdtree_free (&localkt);
        }
    } else if ((norm & CC_NORM_BITS) == CC_X_NORM_TYPE) {
        double xzeit = CCutil_zeit ();
        if (!goodfname && !edgegenfname) {
            if (nearnum) {
                if (CCedgegen_x_k_nearest (ncount, nearnum, &dat,
                            (double *) NULL, 1, &tempcount, &templist)) {
                    fprintf (stderr, "CCedgegen_x_k_nearest failed\n");
                    rval = 1;
                    goto CLEANUP;
                }
                if (!run_silently) {
                    printf ("Time to find %d-nearest: %.2f\n", nearnum,
                                                 CCutil_zeit () - xzeit);
                    fflush (stdout);
                }
            } else {
                if (CCedgegen_x_quadrant_k_nearest (ncount, quadtry, &dat,
                                 (double *) NULL, 1, &tempcount, &templist)) {
                    fprintf (stderr, "x-quad nearest code failed\n");
                    rval = 1;
                    goto CLEANUP;
                }
                if (!run_silently) {
                    printf ("Time to find quad %d-nearest: %.2f\n", quadtry,
                                                 CCutil_zeit () - xzeit);
                    fflush (stdout);
                }
            }
        }
        if (!cycfname && !edgecycfname) {
            xzeit = CCutil_zeit ();
            if (userandom) {
                randcycle (ncount, incycle);
            } else {
                if (CCedgegen_x_nearest_neighbor_tour (ncount,
                         CCutil_lprand () % ncount, &dat, incycle, &val)) {
                    fprintf (stderr, "x_nearest_neighbor_tour failed\n");
                    rval = 1;
                    goto CLEANUP;
                }
            }
            if (!run_silently) {
                printf ("Time to grow tour: %.2f\n", CCutil_zeit () - xzeit);
                fflush (stdout);
            }
        }
    } else {
        double jzeit = CCutil_zeit ();
        if (!goodfname && !edgegenfname) {
            if (!nearnum)
                nearnum = 4 * quadtry;
            if (CCedgegen_junk_k_nearest (ncount, nearnum, &dat,
                      (double *) NULL, 1, &tempcount, &templist)) {
                fprintf (stderr, "CCedgegen_junk_k_nearest failed\n");
                rval = 1;
                goto CLEANUP;
            }
            if (!run_silently) {
                printf ("Time to find %d nearest: %.2f\n",
                         nearnum, CCutil_zeit () - jzeit);
                fflush (stdout);
            }
        }
        if (!cycfname && !edgecycfname) {
            if (userandom) {
                randcycle (ncount, incycle);
            } else {
                if (CCedgegen_junk_nearest_neighbor_tour (ncount,
                         CCutil_lprand () % ncount, &dat, incycle, &val)) {
                    fprintf (stderr, "junk_nearest_neighbor_tour failed\n");
                    rval = 1;
                    goto CLEANUP;
                }
            }
            if (!run_silently) {
                printf ("Time to grow tour: %.2f\n", CCutil_zeit () - jzeit);
                fflush (stdout);
            }
        }
    }

    outcycle = CC_SAFE_MALLOC (ncount, int);
    if (!outcycle) {
        rval = 1;
        goto CLEANUP;
    }

    if (number_runs) {
        k = 0;
        best = BIGDOUBLE;
        do {
            printf ("\nStarting Run %d\n", k);
            if (CClinkern_tour (ncount, &dat, tempcount, templist, 100000000,
                   in_repeater, incycle, outcycle, &val, run_silently,
                   time_bound, length_bound, (char *) NULL)) {
                fprintf (stderr, "CClinkern_tour failed\n");
                rval = 1;
                goto CLEANUP;
            }
            if (val < best) {
                best = val;
                if (print_final) {
                    if (CCutil_writecycle_edgelist (ncount, edgecyclefilename,
                            outcycle, &dat)) {
                        fprintf (stderr, "could not write the cycle\n");
                        rval = 1;
                        goto CLEANUP;
                    }
                }
            }
        } while (++k < number_runs);
        printf ("Overall Best Cycle: %.0f\n", val);
        fflush (stdout);
    } else {
        double lkzeit = CCutil_zeit ();
        int attempt = 1;
        do {
            if (CClinkern_tour (ncount, &dat, tempcount, templist, 10000000,
               in_repeater, incycle, outcycle, &val,
               run_silently, time_bound, length_bound, saveit_name)) {
                fprintf (stderr, "CClinkern_tour failed\n");
                rval = 1;
                goto CLEANUP;
            }
            if (length_bound != -1 && val > length_bound) {
                printf ("Cycle of value %.0f  -  did not reach %.0f\n",
                    val, length_bound);
                printf ("Try again. Number of attempts: %d\n", ++attempt);
            }
        } while (length_bound != -1 && val > length_bound);
        if (print_final) {
            if (CCutil_writecycle_edgelist (ncount, edgecyclefilename,
                        outcycle, &dat)) {
                fprintf (stderr, "could not write the cycle\n");
                rval = 1;
                goto CLEANUP;
            }
        }
        if (run_silently)
            printf ("Lin-Kernighan Running Time: %.2f\n", CCutil_zeit()-lkzeit);
        printf ("Final Cycle: %.0f\n", val);
        fflush (stdout);
    }
    printf ("Total Running Time: %.2f\n", CCutil_zeit () - startzeit);
    fflush (stdout);

CLEANUP:

#ifndef BIG_PROBLEM
    if (templist)
        CC_FREE (templist, int);
#endif
    if (incycle)
        CC_FREE (incycle, int);
    if (outcycle)
        CC_FREE (outcycle, int);
    CCutil_freedatagroup (ncount, &dat);

    if (CCutil_bigchunk_free_world ()) {
        fprintf (stderr, "ERROR: CCuitl_bigcunk free world failed\n");
        return 1;
    }

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static void setupnames (char *n1, char *n2, int ncount)
#else
static void setupnames (n1, n2, ncount)
char *n1;
char *n2;
int ncount;
#endif
{
    if (n2) {
        sprintf (edgecyclefilename, "ecycle.out.%s", n2);
    } else if (n1) {
        char *p = CCutil_strrchr (n1, '/');
        if (!p)
            p = n1;
        else
            p++;
        sprintf (edgecyclefilename, "ecycle.out.%s", p);
    } else {
        sprintf (edgecyclefilename, "ecycle.out.%d", ncount);
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void randcycle (int ncount, int *cyc)
#else
static void randcycle (ncount, cyc)
int ncount;
int *cyc;
#endif
{
    int i, k, temp;

    for (i = 0; i < ncount; i++)
        cyc[i] = i;

    for (i = ncount; i > 1; i--) {
        k = CCutil_lprand () % i;
        SWAP (cyc[i - 1], cyc[k], temp);
    }
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

    while ((c = CCutil_bix_getopt (ac, av, "a:bD:g:h:jk:ln:pq:Qr:R:s:S:t:Tuvy:Y:0123456789")) != EOF)
        switch (c) {
        case 'a':
            nearnum = atoi (CCutil_bix_optarg);
            break;
        case 'b':
            binary_in = 1;
            break;
        case 'D':
            edgegenfname = CCutil_bix_optarg;
            break;
        case 'g':
            goodfname = CCutil_bix_optarg;
            break;
        case 'h':
            length_bound = atof (CCutil_bix_optarg);
            break;
        case 'j':
            useqboruvka++;
            break;
        case 'k':
            nnodes_want = atoi (CCutil_bix_optarg);
            break;
        case 'l':
            userandom++;
            break;
        case 'n':
            process_name = CCutil_bix_optarg;
            break;
        case 'p':
            print_final++;
            break;
        case 'q':
            quadtry = atoi (CCutil_bix_optarg);
            break;
        case 'Q':
            run_silently++;
            break;
        case 'r':
            number_runs = atoi (CCutil_bix_optarg);
            break;
        case 'R':
            in_repeater = atoi (CCutil_bix_optarg);
            break;
        case 's':
            seed = atoi (CCutil_bix_optarg);
            break;
        case 'S':
            saveit_name = CCutil_bix_optarg;
            break;
        case 't':
            time_bound = atof (CCutil_bix_optarg);
            break;
        case 'T':
            tsplib_in = 1;
            break;
        case 'u':
            usegreedy++;
            break;
        case 'v':
            useboruvka++;
            break;
        case 'y':
            cycfname = CCutil_bix_optarg;
            break;
        case 'Y':
            edgecycfname = CCutil_bix_optarg;
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
            break;
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
    fprintf (stderr, "usage: %s [- see below -] [dat_file]\n", f);
    fprintf (stderr, "   -b    dat file in binary ints\n");
    fprintf (stderr, "   -k #  number of nodes for random problem\n");
    fprintf (stderr, "   -s #  random number seed\n");
    fprintf (stderr, "   -n s  process name (used for naming output file)\n");
    fprintf (stderr, "   -p    dump final cycle\n");
    fprintf (stderr, "   -S s  save tour in S after every 10000 kicks\n");
    fprintf (stderr, "   -a #  use #-nearest as good edge set\n");
    fprintf (stderr, "   -D f  edgegen description file\n");
    fprintf (stderr, "   -g f  good edge file\n");
    fprintf (stderr, "   -q #  use quad #-nearest as edge set (default 3)\n");
    fprintf (stderr, "   -r #  number of runs\n");
    fprintf (stderr, "   -R #  number of kicks in iterated Lin-Kernighan\n");
    fprintf (stderr, "   -y f  starting cycle\n");
    fprintf (stderr, "   -Y f  starting cycle (as an edgelist)\n");
    fprintf (stderr, "   -u    greedy starting cycle (for kd-norms)\n");
    fprintf (stderr, "   -j    quick-boruvka starting cycle (for kd-norms)\n");
    fprintf (stderr, "   -v    boruvka starting cycle (for kd-norms)\n");
    fprintf (stderr, "   -l    random starting cycle\n");
    fprintf (stderr, "   -T    the dat file is a TSPLIB file\n");
    fprintf (stderr, "   -t d  running time bound in seconds\n");
    fprintf (stderr, "   -h d  tour length bound (stop when we hit d)\n");
    fprintf (stderr, "   -Q    run silently\n");
    fprintf (stderr, "   -0    Max norm for edge lengths\n");
    fprintf (stderr, "   -1    Ceiling Euclidean norm - from DSJ\n");
    fprintf (stderr, "   -2    Rounded Euclidean norm (default)\n");
    fprintf (stderr, "   -3    Rounded Euclidean 3D norm\n");
    fprintf (stderr, "   -(4 5 6 7 8 9) IBM ATT GEO MATRIX DSJRAND CRYSTAL norm\n");
}
