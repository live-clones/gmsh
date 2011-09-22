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
#include "tsp.h"
#include "Xstuff.h"

static int seed = 0;
static char *xfilename = (char *) NULL;


#ifdef CC_PROTOTYPE_ANSI

int
    main (int ac, char **av);

static void
    usage (char *f);

static int
    parseargs (int ac, char **av),
    getxvector (char *f, int *ncount, int *ecount, int **elist, double **x);

#else  /* CC_PROTOTYPE_ANSI */

int
    main ();

static void
    usage ();

static int
    parseargs (),
    getxvector ();

#endif /* CC_PROTOTYPE_ANSI */


#ifdef CC_PROTOTYPE_ANSI
int main (int ac, char **av)
#else
int main (ac, av)
int ac;
char **av;
#endif
{
    int ncount, ecount;
    int *elist = (int *) NULL;
    double *x = (double *) NULL;
    int cnt;
    CCtsp_lpcut_in *cuts = (CCtsp_lpcut_in *) NULL;
    int rval = 0;

    seed = (int) CCutil_real_zeit ();
    if (parseargs (ac, av))
        return 0;
    CCutil_sprand (seed);

    if (xfilename == (char *) NULL) {
        usage (av[0]);
        return 0;
    }

    if (getxvector (xfilename, &ncount, &ecount, &elist, &x)) {
        fprintf (stderr, "getxvector failed\n");
        rval = 1;
        goto CLEANUP;
    }

    if (Xfastcuts (&cuts, &cnt, ncount, ecount, elist, x)) {
        fprintf (stderr, "Xfastcuts failed\n");
        rval = 1;
        goto CLEANUP;
    }

    if (Xexactsubtours (&cuts, &cnt, ncount, ecount, elist, x)) {
        fprintf (stderr, "Xfastcuts failed\n");
        rval = 1;
        goto CLEANUP;
    }

CLEANUP:

    CC_IFFREE (elist, int);
    CC_IFFREE (x, double);

    if (CCutil_bigchunk_free_world ()) {
        fprintf (stderr, "ERROR: bigchunk_free_world failed\n");
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

    while ((c = CCutil_bix_getopt (ac, av, "s:x:")) != EOF)
        switch (c) {
        case 's':
            seed = atoi (CCutil_bix_optarg);
            break;
        case 'x':
            xfilename = CCutil_bix_optarg;
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
    fprintf (stderr, "   -s #  random seed\n");
    fprintf (stderr, "   -x f  x-vector file\n");
}

#ifdef CC_PROTOTYPE_ANSI
static int getxvector (char *f, int *ncount, int *ecount, int **elist,
                       double **x)
#else
static int getxvector (f, ncount, ecount, elist, x)
char *f;
int *ncount, *ecount;
int **elist;
double **x;
#endif
{
    FILE *in = fopen (f, "r");
    int i;

    *ncount = 0;
    *ecount = 0;
    *elist = (int *) NULL;
    *x = (double *) NULL;

    if (in == (FILE *) NULL) {
        perror (f);
        fprintf (stderr, "Unable to open %s for input\n", f);
        return 1;
    }

    fscanf (in, "%d %d\n", ncount, ecount);
    printf ("nnodes = %d, nedges = %d\n", *ncount, *ecount);
    fflush (stdout);

    *elist = CC_SAFE_MALLOC ((*ecount) * 2, int);
    if (!(*elist)) {
        fprintf (stderr, "Out of memory\n");
        fclose (in);
        return 1;
    }
    *x = CC_SAFE_MALLOC (*ecount, double);
    if (!(*x)) {
        fprintf (stderr, "Out of memory\n");
        CC_FREE (*elist, int);
        fclose (in);
        return 1;
    }

    for (i = 0; i < *ecount; i++) {
        fscanf (in, "%d %d %lf", &((*elist)[2 * i]), &((*elist)[(2 * i) + 1]),
                                 &((*x)[i]));
    }

    fclose (in);
    return 0;
}

/*  Dummies for now */

/*
#ifdef CC_PROTOTYPE_ANSI
int Xloadcplane_cut (Xgraph *G, Xcplane **list, int k)
#else
int Xloadcplane_cut (G, list, k)
Xgraph *G;
Xcplane **list;
int k;
#endif
{
    int i;

    printf ("Subtour: ");
    for (i = 0; i < G->nnodes; i++) {
        if (G->nodelist[i].magiclabel == k)
            printf ("%d ", i);
    }
    printf ("\n");
    fflush (stdout);

    return 1;
}
*/
