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
/************************************************************************/

#include "concorde.h"
#include "match.h" 

#ifdef CC_PROTOTYPE_ANSI

static void
    usage (char *name);
static int
    parseargs (int ac, char **av);

#else

static void
    usage ();
static int
    parseargs ();

#endif

static int seed = 0;
static char *blossom_file = (char *) NULL;
static char *match_file = (char *) NULL;
static char *datfilename = (char *) NULL;
static char *edgefilename = (char *) NULL;
static char *edgegenfname = (char *) NULL;
static int no_frac = 0;
static int just_frac = 0;
static int use_all_trees = 0;
static int binary_in = 0;
static int tsplib_in = 0;
static int nnodes_want = 0;
static int partialprice = 0;
static int norm = CC_EUCLIDEAN;
static int no_price = 0;

#ifdef CC_PROTOTYPE_ANSI
int  main (int ac, char **av)
#else
int  main (ac, av)
int ac;
char **av;
#endif
{
    double zero_zeit = CCutil_zeit ();
    double matzeit = 0.0;
    double genzeit = 0.0;
    int ncount, ecount;
    int *elist = (int *) NULL;
    int *elen = (int *) NULL;
    long l;
    CCdatagroup dat, *mydat = (CCdatagroup *) NULL;

    seed = time (&l);
    if (parseargs (ac, av))
        return 0;
    CCutil_sprand (seed);

    if (edgefilename == (char *) NULL && datfilename == (char *) NULL &&
                                         nnodes_want == 0) {
        usage (av[0]);
        return 0;
    }
    ncount = nnodes_want;

    if (tsplib_in && datfilename != (char *) NULL) {
        if (CCutil_gettsplib (datfilename, &ncount, &dat)) {
            fprintf (stderr, "could not read the TSPLIB file\n");
            goto CLEANUP;
        }
        mydat = &dat;
        norm = dat.norm;
    } else if (datfilename != (char *) NULL || nnodes_want != 0) {
        if (CCutil_getdata (datfilename, binary_in, norm, &ncount, &dat)) {
            fprintf (stderr, "Could not create data set\n");
            goto CLEANUP;
        }
        mydat = &dat;
    } else {
        mydat = (CCdatagroup *) NULL;
    }

    if (mydat) {
        if (CCutil_init_dat_edgelen (mydat)) {
            fprintf (stderr, "init_dat_edgelen failed\n");
            goto CLEANUP;
        }
    }

    if (edgefilename) {
        if (CCutil_getedgelist_n (&ncount, edgefilename, &ecount, &elist, &elen)) {
            fprintf (stderr, "getedgelist_n failed\n");
            goto CLEANUP;
         }
    } else {
        CCedgegengroup plan;
        int i;

        if (edgegenfname) {
            if (CCedgegen_read (edgegenfname, &plan)) {
                fprintf (stderr, "CCedgegen_read failed\n");
                goto CLEANUP;
            }
        } else {
            CCedgegen_init_edgegengroup (&plan);
            if ((norm & CC_NORM_BITS) != CC_KD_NORM_TYPE) {
                plan.nearest = 5;
            } else {
                plan.quadnearest = 2;  
                plan.tour.nearest_count = 1; 
            }
        }
        genzeit = CCutil_zeit ();
        if (CCedgegen_edges (&plan, ncount, mydat, (double *) NULL, &ecount,
                     &elist)) {
            fprintf (stderr, "CCedgegen_edges failed\n");
            goto CLEANUP;
        }
        elen = CC_SAFE_MALLOC (ecount, int);
        if (!elen) {
            fprintf (stderr, "out of memory in main\n");
            CC_FREE (elist, int);
            goto CLEANUP;
        }
        for (i = 0; i < ecount; i++) {
            elen[i] = CCutil_dat_edgelen (elist[2*i], elist[2*i+1], mydat);
        }
        genzeit = CCutil_zeit () - genzeit;
    }

    if (mydat != (CCdatagroup *) NULL && no_price) {
        CCutil_freedatagroup (ncount, mydat);
        mydat = (CCdatagroup *) NULL;
    }

    printf ("ZZ nnodes: %d  seed: %d\n", ncount, seed); fflush (stdout);

    if (perfect_match (ncount, mydat, ecount, &elist, &elen,
                       blossom_file, match_file, just_frac, no_frac, 
                       use_all_trees, partialprice, &matzeit)) {
        fprintf (stderr, "perfect_match failed\n");
        goto CLEANUP;
    }

CLEANUP:

    if (mydat != (CCdatagroup *) NULL) {
        CCutil_freedatagroup (ncount, mydat);
    }

    printf ("\nZZ Running Time: %.2f seconds (Edgegen %.2f, Matching %.2f)\n",
                    genzeit + matzeit, genzeit, matzeit);
    printf ("ZZ Total Time: %.2f Seconds (includes IO and checking)\n",
                    CCutil_zeit () - zero_zeit);
    fflush (stdout);

   return 0;
}

#ifdef  CC_PROTOTYPE_ANSI
static int parseargs (int ac, char **av)
#else
static int parseargs (ac, av)
int ac;
char **av;
#endif
{
    int c;

    while ((c = CCutil_bix_getopt (ac, av, "bB:dD:e:fjk:lp:Ps:tTx:w:0123456789")) != EOF)
        switch (c) {
        case 'b':
            binary_in = 1;
            break;
        case 'B':
            blossom_file = CCutil_bix_optarg;
            break;
        case 'd':
            use_all_trees = 2;
            break;
        case 'D':
            edgegenfname = CCutil_bix_optarg;
            break;
        case 'e':
            edgefilename = CCutil_bix_optarg;
            break;
        case 'f':
            just_frac = 1;
            break;
        case 'j':
            no_frac = 1;
            break;
        case 'k':
            nnodes_want = atoi (CCutil_bix_optarg);
            break;
        case 'p':
            partialprice = atoi (CCutil_bix_optarg);
            break;
        case 'P':
            no_price = 1;
            break;
        case 's':
            seed = atoi (CCutil_bix_optarg);
            break;
        case 't':
            use_all_trees = 1;
            break;
        case 'T':
            tsplib_in = 1;
            break;
        case 'w':
            match_file = CCutil_bix_optarg;
            break;
        case 'x':
            datfilename = CCutil_bix_optarg;
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

    if (CCutil_bix_optind != ac) {
        usage (av[0]);
        return 1;
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static void usage (char *name)
#else
static void usage (name)
char *name;
#endif
{
    fprintf (stderr, "Usage: %s [-see below-]\n", name);
    fprintf (stderr, "   -b    datfile in integer binary format\n");
    fprintf (stderr, "   -B f  blossom-tree-file (for writing)\n");
    fprintf (stderr, "   -d    grow a single tree\n");
    fprintf (stderr, "   -D f  edgegen description file (initial edges)\n");
    fprintf (stderr, "   -e f  edge_file\n");
    fprintf (stderr, "   -f    just fractional\n");
    fprintf (stderr, "   -j    no fractional jumpstart\n");
    fprintf (stderr, "   -k #  number of nodes for random problem\n");
    fprintf (stderr, "   -p #  number of neighbors in partial pricing\n");
    fprintf (stderr, "   -P    do not do pricing (just solve initial set)\n");
    fprintf (stderr, "   -s #  random seed\n");
    fprintf (stderr, "   -t    make same dual change to all trees\n");
    fprintf (stderr, "   -T    the dat file is a TSPLIB file\n");
    fprintf (stderr, "   -w f  match_file (for writing)\n");
    fprintf (stderr, "   -x f  datfile for pricing\n");
    fprintf (stderr, "   -0    Max norm for edge lengths\n");
    fprintf (stderr, "   -1    Ceiling Euclidean norm - from DSJ\n");
    fprintf (stderr, "   -2    Rounded Euclidean norm (default)\n");
    fprintf (stderr, "   -3    Rounded Euclidean 3D norm\n");
    fprintf (stderr, "   -(4 5 6 7 8 9) IBM ATT GEO MATRIX DSJRAND CRYSTAL norm\n");
}
