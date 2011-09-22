/***************************************************************************/
/*                                                                         */
/*               CODE FOR TESTING EDGE GENERATION ROUTINES                 */
/*                                                                         */
/*                             TSP CODE                                    */
/*                                                                         */
/*                                                                         */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook                       */
/*  Date: February 25, 1995                                                */
/*                                                                         */
/*  For a short describtion see usage ()                                   */
/*                                                                         */
/*  Link with:                                                             */
/*   edg_main.o xnear.o                                                    */
/*   edgelen.o  allocrus.o urandom.o safe_io.o zeit.o bgetopt.o            */
/*   edg2cyc.o  fastread.o getdata.o                                       */
/*                                                                         */
/*                                                                         */
/***************************************************************************/

#include "machdefs.h"
#include "util.h"
#include "edgegen.h"

static int norm = CC_EUCLIDEAN;
static int seed = 0;
static int nnodes_want = 0;
static int nearnum = 0;
static int quadnearnum = 0;
static int f2match_nearnum = 0;
static int usenodeweights = 0;
static int random_weight_limit = 0;
static int random_tour_count = 0;
static int nearest_tour_count = 0;
static int linkern_tour_count = 0;
static int linkern_kicks = 100;
static int use_greedy_in_linkern = 0;
static int use_random_in_linkern = 0;
static int linkern_nearnum = 0;
static int linkern_quadnum = 0;
static int twoopt_tour_count = 0;
static int twoopt5_tour_count = 0;
static int threeopt_tour_count = 0;
static int nearest_twomatch_count = 0;
static int find_greedy_tour = 0;
static int find_fractional_2match = 0;
static int find_spanning_tree = 0;
static int find_delaunay_edges = 0;
static int find_mlinkern_edges = 0;
static int binary_in = 0;
static int tsplib_in = 0;

static char *nodefile = (char *) NULL;
static char *weightfile = (char *) NULL;
static char *outfile = (char *) NULL;
static char *describefile = (char *) NULL;


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
    double szeit;
    double *wcoord = (double *) NULL;
    int ncount;
    int rval = 0;
    int ecount = 0;
    int *elist = (int *) NULL;
    CCdatagroup dat;
    CCedgegengroup plan;


    dat.x = (double *) NULL;
    dat.y = (double *) NULL;
    dat.z = (double *) NULL;
    dat.adj = (int **) NULL;

    seed = (int) CCutil_real_zeit();
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

    if (CCutil_init_dat_edgelen (&dat)) {
        fprintf (stderr, "CCutil_init_dat_edgelen failed\n");
        rval = 1;
        goto CLEANUP;
    }

    if (usenodeweights) {
        if (CCutil_getnodeweights (weightfile, ncount, random_weight_limit, &wcoord)) {
            fprintf (stderr, "could not read the nodeweight file\n");
            rval = 1;
            goto CLEANUP;
        }
    }

    if (describefile) {
        if (CCedgegen_read (describefile, &plan)) {
            fprintf (stderr, "CCedgegen_read failed\n");
            rval = 1;
            goto CLEANUP;
        }
    } else {
        CCedgegen_init_edgegengroup (&plan);

        plan.nearest = nearnum;
        plan.quadnearest = quadnearnum;
        plan.delaunay = find_delaunay_edges;
        plan.mlinkern = find_mlinkern_edges;
        plan.tour.random_count = random_tour_count;
        plan.tour.nearest_count = nearest_tour_count;
        plan.tour.greedy = find_greedy_tour;
        plan.want_tree = find_spanning_tree;
        plan.tour.twoopt_count = twoopt_tour_count;
        plan.tour.twoopt5_count = twoopt5_tour_count;
        plan.tour.threeopt_count = threeopt_tour_count;
        if (linkern_tour_count) {
            plan.linkern.count = linkern_tour_count;
            if (!linkern_quadnum && !linkern_nearnum) {
                linkern_quadnum = 3;
            } else {
                plan.linkern.quadnearest = linkern_quadnum;
                plan.linkern.nearest = linkern_nearnum;
            }
            if (!use_greedy_in_linkern && !use_random_in_linkern) {
                plan.linkern.nearest_start = 1;
            } else {
                plan.linkern.greedy_start = use_greedy_in_linkern;
                plan.linkern.random_start = use_random_in_linkern;
            }
            plan.linkern.nkicks = linkern_kicks;
        }
        plan.nearest_twomatch_count = nearest_twomatch_count;
        plan.f2match.wantit = find_fractional_2match;
        if (f2match_nearnum) {
            plan.f2match_nearest.number = f2match_nearnum;
            plan.f2match_nearest.basic = 0;
            plan.f2match_nearest.priced = 1;
        }
    }

    szeit = CCutil_zeit ();

    if (CCedgegen_edges (&plan, ncount, &dat, wcoord, &ecount, &elist)) {
        fprintf (stderr, "CCedgegen_edges failed\n");
        rval = 1;
        goto CLEANUP;
    }

    printf ("Edgegen running time: %.2f (seconds)\n", CCutil_zeit () - szeit);
    fflush (stdout);

    if (outfile && ecount) {
        if (CCutil_writeedges (ncount, outfile, ecount, elist, &dat)) {
            fprintf (stderr, "Could not write the edge set\n");
            rval = 1;
            goto CLEANUP;
        }
    }


CLEANUP:

    CCutil_freedatagroup (ncount, &dat);
    CC_IFFREE (wcoord, double);
    CC_IFFREE (elist, int);

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

    while ((c = CCutil_bix_getopt (ac, av, "A:bB:C:dD:f:FGk:L:s:m:M:n:N:o:q:R:STuU:vw:W:x:y:0123456789?"))
            != EOF)
        switch (c) {
        case 'A':
            twoopt_tour_count = atoi (CCutil_bix_optarg);
            break;
        case 'b':
            binary_in = 1;
            break;
        case 'B':
            twoopt5_tour_count = atoi (CCutil_bix_optarg);
            break;
        case 'C':
            threeopt_tour_count = atoi (CCutil_bix_optarg);
            break;
        case 'd':
            find_delaunay_edges = 1;
            break;
        case 'D':
            describefile = CCutil_bix_optarg;
            break;
        case 'f':
            f2match_nearnum = atoi (CCutil_bix_optarg);
            break;
        case 'F':
            find_fractional_2match = 1;
            break;
        case 'G':
            find_greedy_tour = 1;
            break;
        case 'k':
            nnodes_want = atoi (CCutil_bix_optarg);
            break;
        case 'L':
            linkern_tour_count = atoi (CCutil_bix_optarg);
            break;
        case 'm':
            find_mlinkern_edges = atoi (CCutil_bix_optarg);
            break;
        case 'M':
            nearest_twomatch_count = atoi (CCutil_bix_optarg);
            break;
        case 'n':
            nearnum = atoi (CCutil_bix_optarg);
            break;
        case 'N':
            nearest_tour_count = atoi (CCutil_bix_optarg);
            break;
        case 'o':
            outfile = CCutil_bix_optarg;
            break;
        case 'q':
            quadnearnum = atoi (CCutil_bix_optarg);
            break;
        case 'R':
            linkern_kicks = atoi (CCutil_bix_optarg);
            break;
        case 's':
            seed = atoi (CCutil_bix_optarg);
            break;
        case 'S':
            find_spanning_tree = 1;
            break;
        case 'T':
            tsplib_in = 1;
            break;
        case 'u':
            use_greedy_in_linkern = 1;
            use_random_in_linkern = 0;
            break;
        case 'U':
            random_tour_count = atoi (CCutil_bix_optarg);
            break;
        case 'v':
            use_random_in_linkern = 1;
            use_greedy_in_linkern = 0;
            break;
        case 'w':
            usenodeweights = 1;
            weightfile = CCutil_bix_optarg;
            break;
        case 'W':
            usenodeweights = 1;
            random_weight_limit = atoi (CCutil_bix_optarg);
            break;
        case 'x':
            linkern_quadnum = atoi (CCutil_bix_optarg);
            break;
        case 'y':
            linkern_nearnum = atoi (CCutil_bix_optarg);
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
    fprintf (stderr, "Usage: %s [- see below -] [dat file]\n", f);
    fprintf (stderr, "   -b    dat file in binary-ints\n");
    fprintf (stderr, "   -w f  node weight file\n");
    fprintf (stderr, "   -W #  use random node weights, from 0 to # - 1\n");
    fprintf (stderr, "   -k #  number of nodes for random problem\n");
    fprintf (stderr, "   -s #  random seed\n");
    fprintf (stderr, "   -D f  description file\n");
    fprintf (stderr, "   -n #  find # nearest graph\n");
    fprintf (stderr, "   -q #  find quadrant # nearest graph\n");
    fprintf (stderr, "   -d    find Delaunay triangulation\n");
    fprintf (stderr, "   -f #  find # nearest using f2match reduced costs\n");
    fprintf (stderr, "   -U #  find # random tours\n");
    fprintf (stderr, "   -N #  find # nearest neighbor tours\n");
    fprintf (stderr, "   -G    find greedy tour\n");
    fprintf (stderr, "   -(A B C) #  find # (2opt, 2.5opt, 3opt) tours\n");
    fprintf (stderr, "   -L #  find # linkern tours\n");
    fprintf (stderr, "   -m #  find # linkern matchings\n");
    fprintf (stderr, "   -R #  use # kicks in linkern (default: 100)\n");
    fprintf (stderr, "   -u    use greedy starting tour for linkern\n");
    fprintf (stderr, "   -v    use random starting tours for linkern\n");
    fprintf (stderr, "   -x #  use # quadnearest in linkern\n");
    fprintf (stderr, "   -y #  use # nearest in linkern (can use x & y)\n");
    fprintf (stderr, "   -M #  find # nearest neighbor 2-matchings\n");
    fprintf (stderr, "   -S    find min spanning tree\n");
    fprintf (stderr, "   -F    find fractional twomatch (not priced)\n");
    fprintf (stderr, "   -o f  write the cycle or edge set to f\n");
    fprintf (stderr, "   -T    the dat file is a TSPLIB file\n");
    fprintf (stderr, "   -0    Max norm for edge lengths\n");
    fprintf (stderr, "   -1    Ceiling Euclidean norm - from DSJ\n");
    fprintf (stderr, "   -2    Rounded Euclidean norm (default)\n");
    fprintf (stderr, "   -3    Rounded Euclidean 3D norm\n");
    fprintf (stderr, "   -(4 5 6 7 8 9) IBM ATT GEO MATRIX DSJRAND CRYSTAL norm\n");
}
