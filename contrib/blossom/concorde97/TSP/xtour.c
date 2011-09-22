/***************************************************************************/
/*                                                                         */
/*              ROUTINES FOR CONSTRUCTING TOURS FROM x-VECTORS             */
/*                                                                         */
/*                               TSP CODE                                  */
/*                                                                         */
/*                                                                         */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook                       */
/*  Date: July 21, 1997                                                    */
/*                                                                         */
/*  EXPORTED FUNCTIONS:                                                    */
/*    int CCtsp_x_greedy_tour (CCdatagroup *dat, int ncount, int ecount,   */
/*            int *elist, double *x, int *cyc, double *val)                */
/*     FINDS a tour by adding in edges by nonincreasing x-value.           */
/*      -cyc should be an array of length at least ncount                  */
/*      -val returns the length of the tour                                */
/*                                                                         */
/*    int CCtsp_x_greedy_tour_lk (CCdatagroup *dat, int ncount, int ecount,*/
/*            int *elist, double *x, int *cyc, double *val)                */
/*     FINDS the x-greedy tour then calls a short LK.                      */
/*                                                                         */
/*  NOTES:                                                                 */
/*                                                                         */
/*                                                                         */
/***************************************************************************/

#include "machdefs.h"
#include "util.h"
#include "edgegen.h"
#include "linkern.h"
#include "tsp.h"

#ifdef CC_PROTOTYPE_ANSI

static void
    update_tail (int *tail, int a, int b);

#else

static void
    update_tail ();

#endif

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_x_greedy_tour_lk (CCdatagroup *dat, int ncount, int ecount,
        int *elist, double *x, int *cyc, double *val)
#else
int CCtsp_x_greedy_tour_lk (dat, ncount, ecount, elist, x, cyc, val)
CCdatagroup *dat;
int ncount, ecount;
int *elist;
double *x;
int *cyc;
double *val;
#endif
{
    int rval = 0;
    int *gcyc = (int *) NULL;
    int *tlist = (int *) NULL;
    int tcount;
    double gval;
    CCedgegengroup plan;

    *val = 1e30;
    if (!dat) {
        fprintf (stderr, "no dat in CCtsp_x_greedy_tour_lk\n");
        rval = 1; goto CLEANUP;
    }

    gcyc = CC_SAFE_MALLOC (ncount, int);
    if (!gcyc) {
        fprintf (stderr, "out of memory in CCtsp_x_greedy_tour_lk\n");
        rval = 1; goto CLEANUP;
    }

    rval = CCtsp_x_greedy_tour (dat, ncount, ecount, elist, x, gcyc,
                 &gval);
    if (rval) {
        fprintf (stderr, "CCtsp_x_greedy_tour failed\n"); goto CLEANUP;
    }

    CCedgegen_init_edgegengroup (&plan);
    plan.quadnearest = 2;

    rval = CCedgegen_edges (&plan, ncount, dat, (double *) NULL, &tcount,
                            &tlist);
    if (rval) {
        fprintf (stderr, "CCedgegen_edges failed\n"); goto CLEANUP;
    }

    rval = CClinkern_tour (ncount, dat, tcount, tlist, ncount,
             ncount > 1000 ? 500 : ncount/2, gcyc, cyc, val, 0, 0.0,
             0.0, (char *) NULL);
    if (rval) {
        fprintf (stderr, "CClinkern_tour failed\n"); goto CLEANUP;
    }

CLEANUP:

    CC_IFFREE (tlist, int);
    CC_IFFREE (gcyc, int);
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_x_greedy_tour (CCdatagroup *dat, int ncount, int ecount, int *elist,
        double *x, int *cyc, double *val)
#else
int CCtsp_x_greedy_tour (dat, ncount, ecount, elist, x, cyc, val)
CCdatagroup *dat;
int ncount, ecount;
int *elist;
double *x;
int *cyc;
double *val;
#endif
{
    int rval = 0;
    int tcount = 0;
    int i, a, b;
    double szeit = CCutil_zeit ();
    double len;
    int *perm    = (int *) NULL;
    int *tail    = (int *) NULL;
    int *tcyc    = (int *) NULL;
    char *degree = (char *) NULL;

    printf ("CCtsp_x_greedy_tour ...\n"); fflush (stdout);

    *val = 1e30;
    if (!dat) {
        fprintf (stderr, "no dat in CCtsp_x_greedy_tour\n");
        rval = 1; goto CLEANUP;
    }

    perm     = CC_SAFE_MALLOC (ecount, int);
    degree   = CC_SAFE_MALLOC (ncount, char);
    tail     = CC_SAFE_MALLOC (ncount, int);
    tcyc     = CC_SAFE_MALLOC (2 * ncount, int);
    if (!perm || !degree || !tail || !tcyc) {
        fprintf (stderr, "out of memory in CCtsp_x_greedy_tour\n");
        rval = 1; goto CLEANUP;
    }

    for (i = 0; i < ncount; i++) {
        degree[i] = 0;
        tail[i]   = -1;
    }
    for (i = 0; i < ecount; i++) {
        perm[i] = i;
    }

    CCutil_double_perm_quicksort (perm, x, ecount);
    len = 0;
    for (i = ecount - 1; i >= 0; i--) {
        a = elist[2*perm[i]];
        b = elist[(2*perm[i]) + 1];
        if (degree[a] != 2 && degree[b] != 2 && tail[a] != b) {
            /* add (a, b) to the tour */
            tcyc[tcount++] = a;
            tcyc[tcount++] = b;
            len += (double) CCutil_dat_edgelen (a, b, dat);
            degree[a]++;
            degree[b]++;
            update_tail (tail, a, b);
        }
    }

    printf ("%d edges in x-tour\n", tcount / 2); fflush (stdout);
    a = 0;
    b = 0;
    while (tcount < (2*ncount - 2)) {
        for (; degree[a] == 2; a++);
        for (b = a + 1; degree[b] == 2 || tail[a] == b; b++);
        tcyc[tcount++] = a;
        tcyc[tcount++] = b;
        degree[a]++;
        degree[b]++;
        update_tail (tail, a, b);
        len += (double) CCutil_dat_edgelen (a, b, dat);
    }

    if (tcount < 2*ncount) {
        for (a = 0; degree[a] != 1; a++);
        for (b = a + 1; degree[b] != 1; b++);
        tcyc[tcount++] = a;
        tcyc[tcount++] = b;
        len += (double) CCutil_dat_edgelen (a, b, dat);
    }

    printf ("tour length: %.2f (%.2f seconds)\n", len, CCutil_zeit () - szeit);
    fflush (stdout);
    *val = len;

    rval = CCutil_edge_to_cycle (ncount, tcyc, cyc);
    if (rval) {
        fprintf (stderr, "CCutil_edge_to_cycle failed\n");
        goto CLEANUP;
    }

CLEANUP:

    CC_IFFREE (perm, int);
    CC_IFFREE (tail, int);
    CC_IFFREE (tcyc, int);
    CC_IFFREE (degree, char);
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static void update_tail (int *tail, int a, int b)
#else
static void update_tail (tail, a, b)
int *tail;
int a, b;
#endif
{
    if (tail[a] == -1) {
        if (tail[b] == -1) {
            tail[a] = b;
            tail[b] = a;
        } else {
            tail[a] = tail[b];
            tail[tail[b]] = a;
        }
    } else if (tail[b] == -1) {
        tail[tail[a]] = b;
        tail[b] = tail[a];
    } else {
        tail[tail[a]] = tail[b];
        tail[tail[b]] = tail[a];
    }
}
