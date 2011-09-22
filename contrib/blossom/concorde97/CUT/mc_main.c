/************************************************************************/
/*                                                                      */
/*        Demo of Min-Cutw for Directed and Undirected Graphs           */
/*                                                                      */
/*  Written by:  Applegate, Bixby, Chvatal,  and Cook                   */
/*  Date: September, 1994 (Bonn)                                        */
/*        July 28, 1997 (bico)                                          */
/*                                                                      */
/************************************************************************/

#include "machdefs.h"
#include "util.h"
#include "cut.h"

#undef  USE_DIRECTED_GRAPH

static int source = -1, sink = -1;
static int showcut = 0;
static int violatedcuts = 0;
static int use_shrink = 1;
static int find_global = 0;
static int binary_in = 0;
static char *fname = (char *) NULL;

#ifdef CC_PROTOTYPE_ANSI

int
    main (int ac, char **av);

static void
    usage (char *f),
    display_cut (int *cut, int count);

static int
    parseargs (int ac, char **av),
    shrink_ones (int ncount, int ecount, int *elist, double *dlen,
        int *oncount, int *oecount, int **olist, double **olen,
        double *minval),
    display_all_cuts (double val, int cnt, int *cut, void *pass_param);

#else

int
    main ();

static void
    usage (),
    display_cut ();

static int
    parseargs (),
    shrink_ones (),
    display_all_cuts ();

#endif

#ifdef USE_DIRECTED_GRAPH
#ifdef CC_PROTOTYPE_ANSI
static int
    duplicate_edges (int ncount, int ecount, int *elist, double *ecap,
        int **tlist, double **tcap);
#else
    duplicate_edges ();
#endif
#endif

#ifdef CC_PROTOTYPE_ANSI
int main (int ac, char **av)
#else
int main (ac, av)
int ac;
char **av;
#endif
{
    int rval = 0;
    double val;
    double szeit;
    int i, cutcount;
    int ncount, ecount;
    int *elist = (int *) NULL;
    int *cut   = (int *) NULL;
    int **mycut = (int **) NULL;
    double *ecap = (double *) NULL;

    if (parseargs (ac, av)) goto CLEANUP;

    if (find_global && violatedcuts) {
        fprintf (stderr, "use at most one of -p and -c arguments\n");
        goto CLEANUP;
    }

#ifdef USE_DIRECTED
    if (find_global || violatedcuts) {
        fprintf (stderr, "not set up for global cut in directed graphs\n");
        goto CLEANUP;
    }
#endif


    rval = CCutil_getedges_double (&ncount, fname, &ecount, &elist, &ecap,
                                   binary_in);
    if (rval) {
        fprintf (stderr, "getedges_double failed\n"); goto CLEANUP;
    }

    if (showcut) {
        mycut = &cut;
    } else {
        mycut = (int **) NULL;
    }

    if (find_global) {
        szeit = CCutil_zeit ();
        rval = CCcut_mincut (ncount, ecount, elist, ecap, &val, mycut,
                            &cutcount);
        if (rval) {
            fprintf (stderr, "CCcut_mincut failed\n"); goto CLEANUP;
        }
        printf ("Minimum Cut Value: %f (%.2f seconds)\n", val, CCutil_zeit () - szeit);
        fflush (stdout);
        if (showcut) display_cut (cut, cutcount);
        goto CLEANUP;
    } else if (violatedcuts) {
        szeit = CCutil_zeit ();
        rval = CCcut_violated_cuts (ncount, ecount, elist, ecap,
                2.0 - CC_MINCUT_ONE_EPSILON, display_all_cuts, (void *) NULL);
        if (rval) {
            fprintf (stderr, "CCcut_violated_cuts failed\n");
            goto CLEANUP;
        }
        printf ("Running time: %.2f seconds\n", CCutil_zeit () - szeit);
        goto CLEANUP;
    }

    szeit = CCutil_zeit ();
    if (use_shrink) {
        int tncount, tecount;
        int *telist = (int *) NULL;
        double *tecap = (double *) NULL;
        double minval = CC_MINCUT_BIGDOUBLE;
        double sszeit = CCutil_zeit ();

        rval = shrink_ones (ncount, ecount, elist, ecap, &tncount, &tecount,
                            &telist, &tecap, &minval);
        if (rval) {
            fprintf (stderr, "shrink_ones failed\n"); goto CLEANUP;
        }
        printf ("Shrunk graph has %d nodes and %d edges\n", tncount, tecount);
        if (minval != CC_MINCUT_BIGDOUBLE) {
            printf ("Shrinking found cut of value %f\n", minval);
        }
        fflush (stdout);
        printf ("Time for shrinking: %.2f seconds\n", CCutil_zeit () - sszeit);
        fflush (stdout);
        CC_IFFREE(elist, int);
        CC_IFFREE(ecap, double);
        ncount = tncount;
        ecount = tecount;
        elist = telist;
        ecap = tecap;
    }

#ifdef USE_DIRECTED_GRAPH
    {
        int tncount, tecount;
        int *telist = (int *) NULL;
        double *tecap = (double *) NULL;

        rval = duplicate_edges (ncount, ecount, elist, ecap, &telist, &tecap);
        if (rval) {
            fprintf (stderr, "duplicated_edges failed\n"); goto CLEANUP;
        }
        CC_IFFREE(elist, int);
        CC_IFFREE(ecap, double);
        ecount *= 2;
        elist = telist;
        ecap = tecap;
    }
#endif


    if (source == -1)
        source = 0;

    if (sink != -1) {
        if (source < 0 || sink < 0 || source >= ncount ||
            sink >= ncount || source == sink) {
            printf ("Bad source sink pair\n");
            fflush (stdout);
            goto CLEANUP;
        }

        szeit = CCutil_zeit ();
        rval = CCcut_mincut_st (ncount, ecount, elist, ecap, source, sink,
                            &val, mycut, &cutcount);
        if (rval) {
           fprintf (stderr, "mincut_st failed\n"); goto CLEANUP;
        }
        printf ("Cut value: %f\n", val);
        printf ("Running Time: %.2f (seconds)\n", CCutil_zeit () - szeit);
        fflush (stdout);

        if (showcut) display_cut (cut, cutcount);
    } else {
        double minval = CC_MINCUT_BIGDOUBLE;
        double fzeit = CCutil_zeit ();

        printf ("compute all cuts from source node %d\n", source);
        fflush (stdout);
        for (i = 0; i < ncount; i++) {
            if (i != source) {
                rval = CCcut_mincut_st (ncount, ecount, elist, ecap, source, i,
                                        &val, (int **) NULL, (int *) NULL);
                if (rval) {
                    fprintf (stderr, "mincut_digraph failed\n"); goto CLEANUP;
                }
                if (val < minval)
                    minval = val;
                printf ("."); fflush (stdout);
                if (i % 75 == 0)
                    printf ("%d\n", i);
            }
        }
        printf ("\nMinimum Cut Value: %f\n", minval);
        printf ("Running Time: %.2f (seconds)\n", CCutil_zeit () - fzeit);
        fflush (stdout);
    }

    printf ("Total Running Time: %.2f (seconds)\n", CCutil_zeit () - szeit);
    fflush (stdout);

CLEANUP:

    CC_IFFREE (elist, int);
    CC_IFFREE (ecap, double);
    CC_IFFREE (cut, int);
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

    while ((c = CCutil_bix_getopt (ac, av, "bcCps:St:")) != EOF)
        switch (c) {
        case 'b':
            binary_in = 1;
            break;
        case 'c':
            violatedcuts = 1;
            break;
        case 'C':
            showcut++;
            break;
        case 'p':
            find_global = 1;
            break;
        case 's':
            source = atoi (CCutil_bix_optarg);
            break;
        case 'S':
            use_shrink = 0;
            break;
        case 't':
            sink = atoi (CCutil_bix_optarg);
            break;
        case '?':
        default:
            usage (av[0]);
            return 1;
        }
    if (CCutil_bix_optind >= ac) {
        usage (av[0]);
        return 1;
    }

    fname = av[CCutil_bix_optind++];
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static void usage (char *f)
#else
static void usage (f)
char *f;
#endif
{
    fprintf (stderr, "usage: %s [- below -] edge_file\n", f);
    fprintf (stderr, "    b:   binary input file\n");
    fprintf (stderr, "    c:   display all cuts < 2.0\n");
    fprintf (stderr, "    p:   use Padberg-Rinaldi style shrinking\n");
    fprintf (stderr, "    s #: source\n");
    fprintf (stderr, "    t #: sink\n");
    fprintf (stderr, "    S:   do not use the TSP shrink routines\n");
    fprintf (stderr, "    C:   display the min cut\n");
}

#ifdef CC_PROTOTYPE_ANSI
static void display_cut (int *cut, int count)
#else
static void display_cut (cut, count)
int *cut;
int count;
#endif
{
    int i;

    printf ("MIN CUT:\n");
    for (i = 0; i < count; i++) {
        printf ("%3d ", cut[i]);
        if (i % 10 == 9)
            printf ("\n");
    }
    if (i % 10) printf ("\n");
    fflush (stdout);
}

#ifdef USE_DIRECTED_GRAPH
#ifdef CC_PROTOTYPE_ANSI
static int duplicate_edges (int ncount, int ecount, int *elist, double *ecap,
        int **tlist, double **tcap)
#else
static int duplicate_edges (ncount, ecount, elist, ecap, tlist, tcap)
int ncount, ecount;
int *elist;
double *ecap;
int **tlist;
double **tcap;
#endif
{
    int i;

    *tlist = (int *) NULL;
    *tcap = (double *) NULL;


    /* Convert the graph to a digraph */

    *tlist = CC_SAFE_MALLOC (4 * ecount, int);
    *tcap  = CC_SAFE_MALLOC (2 * ecount, double);
    if (!*tlist || !*tcap) {
        fprintf (stderr, "Out of memory in duplicate_edges\n");
        CC_IFFREE (*tlist, int);
        CC_IFFREE (*tcap, double);
        return 1;
    }

    for (i = 0; i < ecount; i++) {
        (*tlist)[4 * i] = (*tlist)[4 * i + 3] = elist[2 * i];
        (*tlist)[4 * i + 1] = (*tlist)[4 * i + 2] = elist[2 * i + 1];
        (*tcap)[2 * i] = (*tcap)[2 * i + 1] = ecap[i];
    }

    return 0;
}
#endif


#ifdef CC_PROTOTYPE_ANSI
static int shrink_ones (int ncount, int ecount, int *elist, double *dlen,
        int *oncount, int *oecount, int **olist, double **olen, double *minval)
#else
static int shrink_ones (ncount, ecount, elist, dlen, oncount, oecount, olist,
        olen, minval)
int ncount, ecount;
int *elist;
double *dlen;
int *oncount, *oecount;
int **olist;
double **olen;
double *minval;
#endif
{
    int rval = 0;
    CC_SRKgraph G;

    CCcut_SRK_init_graph (&G);
    rval = CCcut_SRK_buildgraph (&G, ncount, ecount, elist, dlen);
    if (rval) {
        fprintf (stderr, "buildgraph failed in shrink_ones\n"); goto CLEANUP;
    }
    CCcut_SRK_subtour_shrink (&G, minval, CC_MINCUT_ONE_EPSILON,
                        (CC_SRKcallback *) NULL, (int **) NULL, (int *) NULL);

    rval = CCcut_SRK_grab_edges (&G, oncount, oecount, olist, olen,
                          (CC_SRKexpinfo *) NULL);
    if (rval) {
        fprintf (stderr, "grab edges failed in shrink_ones\n"); goto CLEANUP;
    }


CLEANUP:

    CCcut_SRK_free_graph (&G);
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static int display_all_cuts (double val, int cnt, int *cut, void *pass_param)
#else
static int display_all_cuts (val, cnt, cut, pass_param)
double val;
int cnt;
int *cut;
void *pass_param;
#endif
{
    if (pass_param) {
        fprintf (stderr, "don't know about pass_param in display_all_cuts\n");
        return 1;
    }

    if (cut && cnt) {
        printf ("Found cut of value %f\n", val); fflush (stdout);
    }
    return 0;
}
