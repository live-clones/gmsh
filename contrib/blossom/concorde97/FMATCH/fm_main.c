/***************************************************************************/
/*                                                                         */
/*                TEST PROGRAM FOR FRACTIONAL MATCHINGS                    */
/*                                                                         */
/*                           TSP CODE                                      */
/*                                                                         */
/*                                                                         */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook                       */
/*  Date: February 24, 1995  (cofeb24)                                     */
/*                                                                         */
/*  SEE short decsribtion in usage ().                                     */
/*                                                                         */
/*  Link with:                                                             */
/*    SEE fmmake.grs                                                       */
/*                                                                         */
/***************************************************************************/

#include "machdefs.h"
#include "util.h"
#include "fmatch.h"
#include "kdtree.h"
#include "edgegen.h"

static int norm = CC_EUCLIDEAN;
static int wantbasic = 0;
static char *edgefilename = (char *) NULL;
static char *datfilename = (char *) NULL;
static char *edgegenfname = (char *) NULL;
static int dumpmatch = 0;
static int dumpdual = 0;
static int dumpbasis = 0;
static int binary_in = 0;
static int tsplib_in = 0;
static int nnodes_want = 0;
static int seed = 0;
static int usenn2match = 0;
static int quadtry = 2;


#ifdef CC_PROTOTYPE_ANSI

int
    main (int ac, char **av);

static void
    usage (char *f),
    dump_match (int *thematching),
    dump_dual (int *thedual, int ncount),
    dump_basis (int *thebasis, int ncount);

static int
    parseargs (int ac, char **av),
    getgraph (char *edgefile, CCdatagroup *dat, int *ncount, int *ecount,
                     int **elist, int **elen);

#else

int
    main ();

static void
    usage (),
    dump_match (),
    dump_dual (),
    dump_basis ();

static int
    parseargs (),
    getgraph ();

#endif


#ifdef CC_PROTOTYPE_ANSI
int main (int ac, char **av)
#else
int main (ac, av)
int ac;
char **av;
#endif
{
    double v, szeit;
    int ncount, ecount;
    int *elist = (int *) NULL, *elen = (int *) NULL;
    int *thematching = (int *) NULL, *thedual = (int *) NULL;
    int *thebasis = (int *) NULL;
    CCdatagroup dat, *mydat = (CCdatagroup *) NULL;
    int rval = 0;

    seed = (int) CCutil_real_zeit ();
    if (parseargs (ac, av))
        return 0;
    CCutil_sprand (seed);

    if (edgefilename == (char *) NULL && datfilename == (char *) NULL &&
                                         nnodes_want == 0) {
        usage (av[0]);
        return 0;
    }
    ncount = nnodes_want;

    szeit = CCutil_zeit ();
    if (tsplib_in && datfilename != (char *) NULL) {
        if (CCutil_gettsplib (datfilename, &ncount, &dat)) {
            fprintf (stderr, "could not read the TSPLIB file\n");
            rval = 1;
            goto CLEANUP;
        }
        norm = dat.norm;
        mydat = &dat;
    } else if (edgefilename == (char *) NULL || datfilename != (char *) NULL) {
        if (CCutil_getdata (datfilename, binary_in, norm, &ncount, &dat)) {
            fprintf (stderr, "Could not create data set\n");
            rval = 1;
            goto CLEANUP;
        }
        mydat = &dat;
    } else {
        mydat = (CCdatagroup *) NULL;
    }

    if (mydat) {
        if (CCutil_init_dat_edgelen (&dat)) {
            fprintf (stderr, "CCutil_init_dat_edgelen failed\n");
            rval = 1;
            goto CLEANUP;
        }
    }

    if (getgraph (edgefilename, &dat, &ncount, &ecount, &elist, &elen)) {
        fprintf (stderr, "getgraph failed\n");
        rval = 1;
        goto CLEANUP;
    }
    printf ("Initial edgeset: %d edges (%d nodes)\n", ecount, ncount);
    printf ("Time to generate graph: %.2f (seconds)\n", CCutil_zeit () - szeit);
    fflush (stdout);

    if (dumpmatch) {
        thematching = CC_SAFE_MALLOC((6 * ncount) + 1, int);
        if (!thematching)
            goto CLEANUP;
    }
    if (dumpdual) {
        thedual = CC_SAFE_MALLOC(ncount, int);
        if (!thedual)
            goto CLEANUP;
    }
    if (dumpbasis) {
        thebasis = CC_SAFE_MALLOC(2 * ncount, int);
        if (!thebasis)
            goto CLEANUP;
    }


    szeit = CCutil_zeit ();
    if (CCfmatch_fractional_2match (ncount, ecount, elist, elen, mydat,
          &v, thematching, thedual, thebasis, wantbasic)) {
        fprintf (stderr, "Fractional matching routine failed\n");
        printf ("Running Time: %.2f (seconds)\n", CCutil_zeit () - szeit);
        goto CLEANUP;
    }

    printf ("Total Running Time: %.2f (seconds)\n", CCutil_zeit () - szeit);
    printf ("Final matching weight: %.1f\n", v);
    fflush (stdout);

    if (dumpmatch)
        dump_match (thematching);
    if (dumpdual)
        dump_dual (thedual, ncount);
    if (dumpbasis)
        dump_basis (thebasis, ncount);


CLEANUP:

    CC_IFFREE (thematching, int);
    CC_IFFREE (thedual, int);
    CC_IFFREE (thebasis, int);
    CC_IFFREE (elist, int);
    CC_IFFREE (elen, int);

    if (mydat != (CCdatagroup *) NULL) {
        CCutil_freedatagroup (ncount, mydat);
    }
    if (CCutil_bigchunk_free_world ()) {
        fprintf (stderr, "ERROR: CCutil_bigchunk_free_world failed\n");
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

    while ((c = CCutil_bix_getopt (ac, av, "BbD:e:k:mn:q:s:Txyz0123456789")) != EOF)
        switch (c) {
        case 'B':
            wantbasic = 1;
            break;
        case 'b':
            binary_in = 1;
            break;
        case 'D':
            edgegenfname = CCutil_bix_optarg;
            break;
        case 'e':
            edgefilename = CCutil_bix_optarg;
            break;
        case 'k':
            nnodes_want = atoi (CCutil_bix_optarg);
            break;
        case 'm':
            usenn2match = 1;
             break;
        case 'n':
            datfilename = CCutil_bix_optarg;
            break;
        case 'q':
            quadtry = atoi (CCutil_bix_optarg);
            break;
        case 's':
            seed = atoi (CCutil_bix_optarg);
            break;
        case 'T':
            tsplib_in = 1;
            break;
        case 'x':
            dumpmatch = 1;
            break;
        case 'y':
            dumpdual = 1;
            break;
        case 'z':
            dumpbasis = 1;
            wantbasic = 1;
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
static void usage (char *f)
#else
static void usage (f)
char *f;
#endif
{
    fprintf (stderr, "Usage: %s [-see below-]\n", f);
    fprintf (stderr, "   -B    find basic optimal solution\n");
    fprintf (stderr, "   -b    datfile in integer binary format\n");
    fprintf (stderr, "   -D f  edgegen file for initial edge set\n");
    fprintf (stderr, "   -e f  edge file - initial edge set\n");
    fprintf (stderr, "   -k #  number of nodes for random problem\n");
    fprintf (stderr, "   -m    NN 2-matching as initial edge set\n");
    fprintf (stderr, "   -n f  dat file - for fmatch on complete graph\n");
    fprintf (stderr, "   -q #  quad-nearest # as initial edge set (default 2)\n");
    fprintf (stderr, "   -s #  random seed\n");
    fprintf (stderr, "   -T    the dat file is a TSPLIB file\n");
    fprintf (stderr, "   -x    dump matching to match.out\n");
    fprintf (stderr, "   -y    dump dual solution to dual.out\n");
    fprintf (stderr, "   -z    dump basic edges to basis.out\n");
    fprintf (stderr, "   -0    price out using MAX norm\n");
    fprintf (stderr, "   -1    price out using JOHNSON norm\n");
    fprintf (stderr, "   -2    price out using EUCLIDEAN norm (default)\n");
    fprintf (stderr, "   -3    price out using Rounded Euclidean 3D norm\n");
    fprintf (stderr, "   -(4 5 6 7 8 9) IBM ATT GEO MATRIX DSJRAND CRYSTAL norm\n");
}

#define QUAD_TRY 2

#ifdef CC_PROTOTYPE_ANSI
static int getgraph (char *edgefile, CCdatagroup *dat, int *ncount, int *ecount,
                     int **elist, int **elen)
#else
static int getgraph (edgefile, dat, ncount, ecount, elist, elen)
char *edgefile;
CCdatagroup *dat;
int *ncount, *ecount, **elist, **elen;
#endif
{
    FILE *in;
    int i, k;


    *elist = (int *) NULL;
    *elen = (int *) NULL;

    if (edgefile != (char *) NULL) {
        if ((in = fopen (edgefile, "r")) == (FILE *) NULL) {
            perror (edgefile);
            fprintf (stderr, "Unable to open %s for input\n", edgefile);
            return 1;
        }

        k = CCutil_readint (in);
        if (*ncount != 0 && k != *ncount) {
            fprintf (stderr, "Edge file does not match dat file\n");
            fclose (in);
            return 1;
        }
        *ncount = k;
        *ecount = CCutil_readint (in);

        *elist = CC_SAFE_MALLOC(2 * (*ecount), int);
        if (!(*elist)) {
            fclose (in);
            return 1;
        }
        *elen = CC_SAFE_MALLOC(*ecount, int);
        if (!(*elen)) {
            fclose (in);
            CC_FREE (*elist, int);
            return 1;
        }

        for (i = 0, k = 0; i < *ecount; i++) {
            (*elist)[k++] = CCutil_readint (in);
            (*elist)[k++] = CCutil_readint (in);
            (*elen)[i] = CCutil_readint (in);
        }
        fclose (in);
    } else if (edgegenfname) {
        CCedgegengroup plan;
        if (CCedgegen_read (edgegenfname, &plan)) {
            fprintf (stderr, "CCedgegen_read failed\n");
            return 1;
        }
        if (CCedgegen_edges (&plan, *ncount, dat, (double *) NULL, ecount,
                             elist)) {
            fprintf (stderr, "CCedgegen_edges failed\n");
            return 1;
        }
        *elen = CC_SAFE_MALLOC(*ecount, int);
        if (!(*elen)) {
            CC_FREE (*elist, int);
            return 1;
        }
        for (i = 0; i < *ecount; i++) {
            (*elen)[i] = CCutil_dat_edgelen ((*elist)[2*i], (*elist)[(2*i) + 1], dat);
        }
    } else {
        if (usenn2match) {
            double val;
            *ecount = *ncount;
            *elist = CC_SAFE_MALLOC(2 * (*ecount), int);
            if (!(*elist))
                return 1;
            if ((dat->norm & CC_NORM_BITS) == CC_KD_NORM_TYPE) {
                printf ("Using nearest neighbor 2-matching graph\n");
                fflush (stdout);
                if (CCkdtree_nearest_neighbor_2match ((CCkdtree *) NULL,
                        *ncount, CCutil_lprand () % (*ncount), dat,
                        *elist, &val)) {
                    fprintf (stderr, "nearest 2-matching code failed\n");
                    CC_FREE (*elist, int);
                    return 1;
                }
            } else {
                int *cyc = (int *) NULL;
                printf ("Not setup for nearest 2-match with x or junk norms\n");
                printf ("Using nearest neighbour tour graph\n");
                fflush (stdout);
                cyc = CC_SAFE_MALLOC (*ncount, int);
                if (!cyc) {
                    CC_FREE (*elist, int);
                    return 1;
                }
                if ((dat->norm & CC_NORM_BITS) == CC_X_NORM_TYPE) {
                    if (CCedgegen_x_nearest_neighbor_tour (*ncount,
                            CCutil_lprand () % (*ncount), dat, cyc, &val)) {
                        CC_FREE (*elist, int);
                        CC_FREE (cyc, int);
                        return 1;
                    }
                } else {
                    if (CCedgegen_junk_nearest_neighbor_tour (*ncount,
                            CCutil_lprand () % (*ncount), dat, cyc, &val)) {
                        CC_FREE (*elist, int);
                        CC_FREE (cyc, int);
                        return 1;
                    }
                }
                for (i = 0; i < *ncount - 1; i++) {
                    (*elist)[2 * i] = cyc[i];
                    (*elist)[(2 * i) + 1] = cyc[i + 1];
                }
                (*elist)[2 * i] = cyc[i];
                (*elist)[(2 * i) + 1] = cyc[0];
                CC_FREE (cyc, int);
            }
        } else {
            if ((dat->norm & CC_NORM_BITS) == CC_KD_NORM_TYPE) {
                printf ("Using quadrant nearest %d graph\n", quadtry);
                fflush (stdout);
                if (CCkdtree_quadrant_k_nearest ((CCkdtree *) NULL, *ncount,
                       quadtry, dat, (double *) NULL, 1, ecount, elist)) {
                    fprintf (stderr, "CCkdtree-quad nearest code failed\n");
                    CC_FREE (*elist, int);
                    return 1;
                }
            } else if ((dat->norm & CC_NORM_BITS) == CC_X_NORM_TYPE) {
                printf ("Using quadrant nearest %d graph\n", quadtry);
                fflush (stdout);
                if (CCedgegen_x_quadrant_k_nearest (*ncount, quadtry, dat,
                       (double *) NULL, 1, ecount, elist)) {
                    fprintf (stderr, "CCedgegen_x-quad nearest code failed\n");
                    CC_FREE (*elist, int);
                    return 1;
                }
            } else {
                printf ("No junk quad nearest, using %d nearest graph\n",
                         4 * quadtry);
                fflush (stdout);
                if (CCedgegen_junk_k_nearest (*ncount, 4 * quadtry, dat,
                       (double *) NULL, 1, ecount, elist)) {
                    fprintf (stderr, "CCedgegen_junk-nearest code failed\n");
                    CC_FREE (*elist, int);
                    return 1;
                }
            }
        }

        *elen = CC_SAFE_MALLOC(*ecount, int);
        if (!(*elen)) {
            CC_FREE (*elist, int);
            return 1;
        }
        for (i = 0; i < *ecount; i++) {
            (*elen)[i] = CCutil_dat_edgelen ((*elist)[2*i], (*elist)[(2*i) + 1], dat);
        }
    }

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static void dump_match (int *thematching)
#else
static void dump_match (thematching)
int *thematching;
#endif
{
    FILE *out = fopen ("match.out", "w");
    int k;

    if (out == (FILE *) NULL) {
        perror ("match.out");
        fprintf (stderr, "Unable to open match.out for output\n");
        return;
    }

    k = 0;
    while (thematching[k] != -1) {
        fprintf (out, "%d %d %d\n", thematching[k], thematching[k + 1],
                       thematching[k + 2]);
        k += 3;
    }
}
#ifdef CC_PROTOTYPE_ANSI
static void dump_dual (int *thedual, int ncount)
#else
static void dump_dual (thedual, ncount)
int *thedual;
int ncount;
#endif
{
    FILE *out = fopen ("dual.out", "w");
    int k;

    if (out == (FILE *) NULL) {
        perror ("dual.out");
        fprintf (stderr, "Unable to open dual.out for output\n");
        return;
    }

    for (k = 0; k < ncount; k++)
        fprintf (out, "%d\n", thedual[k]);
}


#ifdef CC_PROTOTYPE_ANSI
static void dump_basis (int *thebasis, int ncount)
#else
static void dump_basis (thebasis, ncount)
int *thebasis;
int ncount;
#endif
{
    FILE *out = fopen ("basis.out", "w");
    int k;

    if (out == (FILE *) NULL) {
        perror ("basis.out");
        fprintf (stderr, "Unable to open basis.out for output\n");
        return;
    }

    for (k = 0; k < ncount; k++)
        fprintf (out, "%d %d\n", thebasis[2 * k], thebasis[(2 * k) + 1]);
}
