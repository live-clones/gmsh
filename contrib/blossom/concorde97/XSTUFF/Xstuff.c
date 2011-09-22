/***************************************************************************/
/*                                                                         */
/*           Interface to a subset of the old subtour routines             */
/*                                                                         */
/*                                                                         */
/*   WARNING: These routines are messy ports of old cut, they use many     */
/*   static variables, may not clean up their memory, and are known to     */
/*   have bugs. These routines will not be included in future versions     */
/*   of concorde.                                                          */
/*                                                                         */
/*                           TSP CODE                                      */
/*                                                                         */
/*                                                                         */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook                       */
/*  Date: Novemeber 6, 1995                                                */
/*                                                                         */
/*  Exported Functions:                                                    */
/*                                                                         */
/*    int                                                                  */
/*       Xfastcuts (CCtsp_lpcut_in **cuts, int *cutcount, int ncount,      */
/*                  int ecount, int *elist, double *x),                    */
/*       Xslowcuts (CCtsp_lpcut_in **cuts, int *cutcount, int ncount,      */
/*                  int ecount, int *elist, double *x),                    */
/*       Xfastsubtours (CCtsp_lpcut_in **cuts, int *cutcount, int ncount,  */
/*                  int ecount, int *elist, double *x),                    */
/*       Xexactsubtours (CCtsp_lpcut_in **cuts, int *cutcount, int ncount, */
/*                  int ecount, int *elist, double *x),                    */
/*       Xcliquetrees (CCtsp_lpcut_in **cuts, int *cutcount, int ncount,   */
/*                  int ecount, int *elist, double *x),                    */
/*       Xconsecutiveones (CCtsp_lpcut_in **cuts, int *cutcount,           */
/*                  int ncount, int ecount, int *elist, double *x,         */
/*                  CCtsp_lpcuts *pool)                                    */
/*       Xnecklacecuts (CCtsp_lpcut_in **cuts, int *cutcount, int ncount,  */
/*                   int ecount, int *elist, double *x, CCtsp_lpcuts *pool)*/
/*         -cuts should point to a NULL terminated cutlist. The new cuts   */
/*          will be added to the front of this list.                       */
/*         -cutcount will return the number of new cuts found.             */
/*                                                                         */
/*  Link with:                                                             */
/*    SEE conmake.grs                                                      */
/*                                                                         */
/***************************************************************************/

#include "machdefs.h"
#include "util.h"
#include "tsp.h"
#include "Xsubtour.h"
#include "Xstuff.h"

#ifdef CC_PROTOTYPE_ANSI

static int
    munch_the_list (CCtsp_lpcut_in **cuts, int *cutcount, Xgraph *G,
        Xcplane *list),
    send_the_cut (CCtsp_lpcut_in **cuts, Xgraph *G, Xcplane *c),
    cplane_to_lpcut_in (Xgraph *G, Xcplane *c, CCtsp_lpcut_in *lc),
    nodeptr_to_lpclique (Xgraph *G, Xnodeptr *npclique, CCtsp_lpclique *cliq);

#else

static int
    munch_the_list (),
    send_the_cut (),
    cplane_to_lpcut_in (),
    nodeptr_to_lpclique ();

#endif

static CCtsp_lpcuts *xpool = (CCtsp_lpcuts *) NULL;

#ifdef CC_PROTOTYPE_ANSI
int Xfastcuts (CCtsp_lpcut_in **cuts, int *cutcount, int ncount, int ecount,
               int *elist, double *x)
#else
int Xfastcuts (cuts, cutcount, ncount, ecount, elist, x)
CCtsp_lpcut_in **cuts;
int *cutcount;
int ncount;
int ecount;
int *elist;
double *x;
#endif
{
    double szeit = CCutil_zeit ();
    double tzeit;
    Xcplane *list = (Xcplane *) NULL;
    int i, cnt;
    int *elen = (int *) NULL;
    Xgraph G;
    int rval = 0;

    *cutcount = 0;

    G.nodelist = (Xnode *) NULL;
    G.edgelist = (Xedge *) NULL;

    elen = CC_SAFE_MALLOC (ecount, int);
    if (!elen) {
        rval = 1;
        goto CLEANUP;
    }

    for (i = 0; i < ecount; i++)
        elen[i] = 0;

    if (Xbuildgraph (&G, ncount, ecount, elist, elen)) {
        fprintf (stderr, "Xbuildgraph failed\n");
        rval = 1;
        goto CLEANUP;
    }

    printf ("Xfastcuts:\n"); fflush (stdout);

    tzeit = CCutil_zeit ();
    cnt = Xrunconnectcuts (&G, &list, x);
    printf ("  %d connect cuts  in %.2f seconds\n", cnt,
            CCutil_zeit () - tzeit);
    fflush (stdout);

    tzeit = CCutil_zeit ();
    cnt = Xheavy_edge_cuts (&G, &list, x);
    printf ("  %d heavy-edge cuts in %.2f seconds\n", cnt,
            CCutil_zeit () - tzeit);
    fflush (stdout);

    tzeit = CCutil_zeit ();
    cnt = Xblobcuts (&G, &list, x);
    printf ("  %d blob cuts in %.2f seconds\n", cnt, CCutil_zeit () - tzeit);
    fflush (stdout);

    tzeit = CCutil_zeit ();
    cnt = Xblockcombs (&G, &list, x);
    printf ("  %d block combs in %.2f seconds\n", cnt, CCutil_zeit () - tzeit);
    fflush (stdout);

    tzeit = CCutil_zeit ();
    cnt = Xlocalcombs (&G, &list, x);
    printf ("  %d local combs in %.2f seconds\n", cnt, CCutil_zeit () - tzeit);
    fflush (stdout);

    tzeit = CCutil_zeit ();
    cnt = Xglobalcombs (&G, &list, x);
    printf ("  %d global combs in %.2f seconds\n", cnt,
            CCutil_zeit () - tzeit);
    fflush (stdout);

    {
        Xcplane *c, *cnext;
        int ksub = 0, kcomb = 0, kctree = 0, k = 0;

        for (c = list; c; c = c->next) {
            k++;
            if (c->handle) {
                if (!c->teeth)
                    ksub++;
                else
                    kcomb++;
            } else {
                if (!c->teeth)
                    ksub++;
                else {
                    if (!c->handles->next)
                        kcomb++;
                    else
                        kctree++;
                }
            }
        }

        printf ("\n%d CUTS (%d subtours, %d combs, %d cliquetrees)\n",
                 k, ksub, kcomb, kctree);
        for (c = list; c; c = cnext) {
            cnext = c->next;
            if (send_the_cut (cuts, &G, c)) {
                fprintf (stderr, "send_the_cut failed\n");
                rval = 1;
                goto CLEANUP;
            }
            Xfreecplanestruct (c);
            (*cutcount)++;
        }
    }


    printf ("Total Running Time: %.2f (seconds)\n", CCutil_zeit () - szeit);
    fflush (stdout);

CLEANUP:

    Xfreegraph (&G);
    CC_IFFREE (elen, int);

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int Xslowcuts (CCtsp_lpcut_in **cuts, int *cutcount, int ncount, int ecount,
       int *elist, double *x)
#else
int Xslowcuts (cuts, cutcount, ncount, ecount, elist, x)
CCtsp_lpcut_in **cuts;
int *cutcount;
int ncount;
int ecount;
int *elist;
double *x;
#endif
{
    double szeit = CCutil_zeit ();
    double tzeit;
    Xcplane *list = (Xcplane *) NULL;
    int i, cnt;
    int *elen = (int *) NULL;
    Xgraph G;
    int rval = 0;

    *cutcount = 0;

    G.nodelist = (Xnode *) NULL;
    G.edgelist = (Xedge *) NULL;

    elen = CC_SAFE_MALLOC (ecount, int);
    if (!elen) {
        rval = 1;
        goto CLEANUP;
    }

    for (i = 0; i < ecount; i++)
        elen[i] = 0;

    if (Xbuildgraph (&G, ncount, ecount, elist, elen)) {
        fprintf (stderr, "Xbuildgraph failed\n");
        rval = 1;
        goto CLEANUP;
    }

    printf ("Xslowcuts:\n"); fflush (stdout);

    tzeit = CCutil_zeit ();
    cnt = Xexactblossoms_run (&G, &list, x);
    printf ("  %d exact blossoms in %.2f seconds\n", cnt,
          CCutil_zeit () - tzeit);
    fflush (stdout);

    tzeit = CCutil_zeit ();
    cnt = Xolaf_combs (&G, &list, x);
    printf ("  %d olaf combs in %.2f seconds\n", cnt, CCutil_zeit () - tzeit);
    fflush (stdout);

    {
        Xcplane *c, *cnext;
        int ksub = 0, kcomb = 0, kctree = 0, k = 0;

        for (c = list; c; c = c->next) {
            k++;
            if (c->handle) {
                if (!c->teeth)
                    ksub++;
                else
                    kcomb++;
            } else {
                if (!c->teeth)
                    ksub++;
                else {
                    if (!c->handles->next)
                        kcomb++;
                    else
                        kctree++;
                }
            }
        }

        printf ("\n%d CUTS (%d subtours, %d combs, %d cliquetrees)\n",
                 k, ksub, kcomb, kctree);
        for (c = list; c; c = cnext) {
            cnext = c->next;
            if (send_the_cut (cuts, &G, c)) {
                fprintf (stderr, "send_the_cut failed\n");
                rval = 1;
                goto CLEANUP;
            }
            Xfreecplanestruct (c);
            (*cutcount)++;
        }
    }

    printf ("Total Running Time: %.2f (seconds)\n", CCutil_zeit () - szeit);
    fflush (stdout);

CLEANUP:

    Xfreegraph (&G);
    CC_IFFREE (elen, int);

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int Xfastsubtours (CCtsp_lpcut_in **cuts, int *cutcount, int ncount,
        int ecount, int *elist, double *x)
#else
int Xfastsubtours (cuts, cutcount, ncount, ecount, elist, x)
CCtsp_lpcut_in **cuts;
int *cutcount;
int ncount;
int ecount;
int *elist;
double *x;
#endif
{
    double tzeit;
    Xcplane *list = (Xcplane *) NULL;
    int i, cnt, rval = 0;
    int *elen = (int *) NULL;
    Xgraph G;

    *cutcount = 0;

    G.nodelist = (Xnode *) NULL;
    G.edgelist = (Xedge *) NULL;

    elen = CC_SAFE_MALLOC (ecount, int);
    if (!elen) {
        rval = 1;
        goto CLEANUP;
    }
    for (i = 0; i < ecount; i++)
        elen[i] = 0;

    if (Xbuildgraph (&G, ncount, ecount, elist, elen)) {
        fprintf (stderr, "Xbuildgraph failed\n");
        rval = 1;
        goto CLEANUP;
    }

    printf ("Xfastsubtours:\n"); fflush (stdout);

    tzeit = CCutil_zeit ();
    cnt = Xrunconnectcuts (&G, &list, x);
    printf ("  %d connect cuts  in %.2f seconds\n", cnt,
            CCutil_zeit () - tzeit);
    fflush (stdout);

    tzeit = CCutil_zeit ();
    cnt = Xheavy_edge_cuts (&G, &list, x);
    printf ("  %d heavy-edge cuts in %.2f seconds\n", cnt,
            CCutil_zeit () - tzeit);
    fflush (stdout);

    tzeit = CCutil_zeit ();
    cnt = Xblobcuts (&G, &list, x);
    printf ("  %d blob cuts in %.2f seconds\n", cnt,
            CCutil_zeit () - tzeit);
    fflush (stdout);


    if (munch_the_list (cuts, cutcount, &G, list)) {
        fprintf (stderr, "munch_the_list failed\n");
        return 1;
    }

CLEANUP:

    Xfreegraph (&G);
    CC_IFFREE (elen, int);

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int Xexactsubtours (CCtsp_lpcut_in **cuts, int *cutcount, int ncount,
        int ecount, int *elist, double *x)
#else
int Xexactsubtours (cuts, cutcount, ncount, ecount, elist, x)
CCtsp_lpcut_in **cuts;
int *cutcount;
int ncount;
int ecount;
int *elist;
double *x;
#endif
{
    double tzeit;
    Xcplane *list = (Xcplane *) NULL;
    int i, rval = 0;
    int *elen = (int *) NULL;
    Xgraph G;

    *cutcount = 0;

    G.nodelist = (Xnode *) NULL;
    G.edgelist = (Xedge *) NULL;

    elen = CC_SAFE_MALLOC (ecount, int);
    if (!elen) {
        rval = 1;
        goto CLEANUP;
    }
    for (i = 0; i < ecount; i++)
        elen[i] = 0;

    if (Xbuildgraph (&G, ncount, ecount, elist, elen)) {
        fprintf (stderr, "Xbuildgraph failed\n");
        rval = 1;
        goto CLEANUP;
    }

    printf ("Xexactcutcheck:\n"); fflush (stdout);
    tzeit = CCutil_zeit ();
    i = Xexactcutcheck (&G, &list, x);
    printf ("  %d exact cuts in %.2f seconds\n", i, CCutil_zeit () - tzeit);
    fflush (stdout);

    if (munch_the_list (cuts, cutcount, &G, list)) {
        fprintf (stderr, "munch_the_list failed\n");
        return 1;
    }

CLEANUP:

    Xfreegraph (&G);
    CC_IFFREE (elen, int);

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int Xconsecutiveones (CCtsp_lpcut_in **cuts, int *cutcount, int ncount,
        int ecount, int *elist, double *x, CCtsp_lpcuts *pool)
#else
int Xconsecutiveones (cuts, cutcount, ncount, ecount, elist, x, pool)
CCtsp_lpcut_in **cuts;
int *cutcount;
int ncount;
int ecount;
int *elist;
double *x;
CCtsp_lpcuts *pool;
#endif
{
    double tzeit;
    Xcplane *list = (Xcplane *) NULL;
    int i, rval = 0;
    int *elen = (int *) NULL;
    Xgraph G;

    xpool = pool;

    *cutcount = 0;

    G.nodelist = (Xnode *) NULL;
    G.edgelist = (Xedge *) NULL;

    elen = CC_SAFE_MALLOC (ecount, int);
    if (!elen) {
        rval = 1;
        goto CLEANUP;
    }
    for (i = 0; i < ecount; i++)
        elen[i] = 0;

    if (Xbuildgraph (&G, ncount, ecount, elist, elen)) {
        fprintf (stderr, "Xbuildgraph failed\n");
        rval = 1;
        goto CLEANUP;
    }

    printf ("Xconsecutiveones:\n"); fflush (stdout);
    tzeit = CCutil_zeit ();
    i = Xnewkids (&G, x, &list);
    printf ("  %d consecutive ones cuts in %.2f seconds\n", i,
            CCutil_zeit () - tzeit);
    fflush (stdout);

    if (munch_the_list (cuts, cutcount, &G, list)) {
        fprintf (stderr, "munch_the_list failed\n");
        return 1;
    }

CLEANUP:

    Xfreegraph (&G);
    CC_IFFREE (elen, int);

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int Xnecklacecuts (CCtsp_lpcut_in **cuts, int *cutcount, int ncount, int ecount,
        int *elist, double *x, CCtsp_lpcuts *pool)
#else
int Xnecklacecuts (cuts, cutcount, ncount, ecount, elist, x, pool)
CCtsp_lpcut_in **cuts;
int *cutcount;
int ncount;
int ecount;
int *elist;
double *x;
CCtsp_lpcuts *pool;
#endif
{
    double tzeit;
    Xcplane *list = (Xcplane *) NULL;
    int i, rval = 0;
    int *elen = (int *) NULL;
    Xgraph G;

    xpool = pool;

    *cutcount = 0;

    G.nodelist = (Xnode *) NULL;
    G.edgelist = (Xedge *) NULL;

    elen = CC_SAFE_MALLOC (ecount, int);
    if (!elen) {
        rval = 1;
        goto CLEANUP;
    }
    for (i = 0; i < ecount; i++)
        elen[i] = 0;

    if (Xbuildgraph (&G, ncount, ecount, elist, elen)) {
        fprintf (stderr, "Xbuildgraph failed\n");
        rval = 1;
        goto CLEANUP;
    }

    printf ("Xnecklaces:\n"); fflush (stdout);
    tzeit = CCutil_zeit ();
    i = Xnecklaces (&G, &list, x);
    printf ("  %d necklace cuts in %.2f seconds\n", i, CCutil_zeit () - tzeit);
    fflush (stdout);

    if (munch_the_list (cuts, cutcount, &G, list)) {
        fprintf (stderr, "munch_the_list failed\n");
        return 1;
    }

CLEANUP:

    Xfreegraph (&G);
    CC_IFFREE (elen, int);

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int Xcliquetrees (CCtsp_lpcut_in **cuts, int *cutcount, int ncount, int ecount,
        int *elist, double *x)
#else
int Xcliquetrees (cuts, cutcount, ncount, ecount, elist, x)
CCtsp_lpcut_in **cuts;
int *cutcount;
int ncount;
int ecount;
int *elist;
double *x;
#endif
{
    double tzeit, szeit = CCutil_zeit ();
    Xcplane *list = (Xcplane *) NULL;
    int i, rval = 0;
    int *elen = (int *) NULL;
    Xgraph G;

    *cutcount = 0;

    G.nodelist = (Xnode *) NULL;
    G.edgelist = (Xedge *) NULL;

    elen = CC_SAFE_MALLOC (ecount, int);
    if (!elen) {
        rval = 1;
        goto CLEANUP;
    }
    for (i = 0; i < ecount; i++)
        elen[i] = 0;

    if (Xbuildgraph (&G, ncount, ecount, elist, elen)) {
        fprintf (stderr, "Xbuildgraph failed\n");
        rval = 1;
        goto CLEANUP;
    }

    printf ("Xcliquetrees:\n"); fflush (stdout);
    tzeit = CCutil_zeit ();
    i = Xcliquetree (&G, &list, x);
    printf ("  %d cliquetrees in %.2f seconds\n", i, CCutil_zeit () - tzeit);
    fflush (stdout);

    tzeit = CCutil_zeit ();
    i = Xbasiccliques (&G, &list, x);
    printf ("  %d basic cliquetrees in %.2f seconds\n", i,
            CCutil_zeit () - tzeit);
    fflush (stdout);

    if (munch_the_list (cuts, cutcount, &G, list)) {
        fprintf (stderr, "munch_the_list failed\n");
        return 1;
    }

    printf ("Total Running Time: %.2f (seconds)\n", CCutil_zeit () - szeit);
    fflush (stdout);

CLEANUP:

    Xfreegraph (&G);
    CC_IFFREE (elen, int);

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static int munch_the_list (CCtsp_lpcut_in **cuts, int *cutcount, Xgraph *G,
        Xcplane *list)
#else
static int munch_the_list (cuts, cutcount, G, list)
CCtsp_lpcut_in **cuts;
int *cutcount;
Xgraph *G;
Xcplane *list;
#endif
{
    Xcplane *c, *cnext;

    for (c = list; c; c = cnext) {
        cnext = c->next;
        if (send_the_cut (cuts, G, c)) {
            fprintf (stderr, "send_the_cut failed\n");
            return 1;
        }
        Xfreecplanestruct (c);
        (*cutcount)++;
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int send_the_cut (CCtsp_lpcut_in **cuts, Xgraph *G, Xcplane *c)
#else
static int send_the_cut (cuts, G, c)
CCtsp_lpcut_in **cuts;
Xgraph *G;
Xcplane *c;
#endif
{
    CCtsp_lpcut_in *lc;

    lc = CC_SAFE_MALLOC (1, CCtsp_lpcut_in);
    if (!lc) {
        fprintf (stderr, "out of memory in send_the_cut\n");
        return 1;
    }

    if (cplane_to_lpcut_in (G, c, lc)) {
        fprintf (stderr,  "cplane_to_lpcut_in failed\n");
        CC_FREE (lc, CCtsp_lpcut_in);
        return 1;
    }

    lc->next = *cuts;
    *cuts = lc;

#ifdef XSTUFF_DEBUG
    CCtsp_print_lpcut_in (lc);
#endif

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int cplane_to_lpcut_in (Xgraph *G, Xcplane *c, CCtsp_lpcut_in *lc)
#else
static int cplane_to_lpcut_in (G, c, lc)
Xgraph *G;
Xcplane *c;
CCtsp_lpcut_in *lc;
#endif
{
    Xnodeptrptr *npp;
    int hcnt = 0, ccnt = 0;

    lc->handlecount = 0;
    lc->cliquecount = 0;
    lc->cliques = (CCtsp_lpclique *) NULL;

    if (c->handle) {
        ccnt++;
        if (c->teeth)
            hcnt++;
    } else {
        for (npp = c->handles; npp; npp = npp->next) {
            hcnt++;
            ccnt++;
        }
    }
    for (npp = c->teeth; npp; npp = npp->next)
        ccnt++;

    lc->cliques = CC_SAFE_MALLOC (ccnt, CCtsp_lpclique);
    if (!lc->cliques) {
        fprintf (stderr, "out of memory in cplane_to_lpcut_in\n");
        return 1;
    }

    ccnt = 0;
    if (c->handle) {
        if (nodeptr_to_lpclique (G, c->handle, &(lc->cliques[ccnt++]))) {
            fprintf (stderr, "nodeptr_to_lpclique failed\n");
            CC_FREE (lc->cliques, CCtsp_lpclique);
            return 1;
        }
    } else {
        for (npp = c->handles; npp; npp = npp->next) {
            if (nodeptr_to_lpclique (G, npp->this, &(lc->cliques[ccnt++]))) {
                fprintf (stderr, "nodeptr_to_lpclique failed\n");
                CC_FREE (lc->cliques, CCtsp_lpclique);
                return 1;
            }
        }
    }
    for (npp = c->teeth; npp; npp = npp->next) {
        if (nodeptr_to_lpclique (G, npp->this, &(lc->cliques[ccnt++]))) {
            fprintf (stderr, "nodeptr_to_lpclique failed\n");
            CC_FREE (lc->cliques, CCtsp_lpclique);
            return 1;
        }
    }
    lc->handlecount = hcnt;
    lc->cliquecount = ccnt;
    lc->rhs         = CCtsp_CUTRHS(lc);
    lc->sense       = 'G';
    lc->branch      = 0;

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int nodeptr_to_lpclique (Xgraph *G, Xnodeptr *npcliq,
         CCtsp_lpclique *cliq)
#else
static int nodeptr_to_lpclique (G, npcliq, cliq)
Xgraph *G;
Xnodeptr *npcliq;
CCtsp_lpclique *cliq;
#endif
{
    int i, k = 0;
    Xnodeptr *np;
    int *ac = (int *) NULL;
    int nseg;

    cliq->segcount = 0;
    cliq->nodes = (CCtsp_segment *) NULL;

    for (np = npcliq; np; np = np->next)
        k++;

    if (!k) {
        fprintf (stderr, "empty clique in nodeptr_to_lpclique\n");
        return 1;
    }

    ac = CC_SAFE_MALLOC (k, int);
    if (!ac) {
        fprintf (stderr, "out of memory in nodeptr_to_lpclique\n");
        return 1;
    }

    for (i = 0, np = npcliq; np; np = np->next, i++) {
        ac[i] = np->this - G->nodelist;
    }

    CCutil_int_array_quicksort (ac, k);

    nseg = 0;
    i = 0;
    while (i < k) {
        while (i < (k - 1) && ac[i + 1] == (ac[i] + 1))
            i++;
        i++;
        nseg++;
    }

    cliq->nodes = CC_SAFE_MALLOC (nseg, CCtsp_segment);
    if (!cliq->nodes) {
        fprintf (stderr, "out of memory in in nodeptr_to_lpclique\n");
        CC_FREE (ac, int);
        return 1;
    }
    cliq->segcount = nseg;

    nseg = 0;
    i = 0;
    while (i < k) {
        cliq->nodes[nseg].lo = ac[i];
        while (i < (k - 1) && ac[i + 1] == (ac[i] + 1))
            i++;
        cliq->nodes[nseg].hi = ac[i++];
        nseg++;
    }

    CC_FREE (ac, int);
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int Xsearch_cutpool_for_slack_cliques (Xgraph *G, double maxslack,
         int request, int *kcount, Xportableclique **klist, int ecount,
         int *elist, double *x)
#else
int Xsearch_cutpool_for_slack_cliques (G, maxslack, request, kcount, klist,
         ecount, elist, x)
Xgraph *G;
double maxslack;
int request;
int *kcount;
Xportableclique **klist;
int ecount;
int *elist;
double *x;
#endif
{
    int i, j, isize, k, p;
    CCtsp_lpclique *c;
    CCtsp_lpclique *cliquelist = (CCtsp_lpclique *) NULL;
    double   *cliquevals = (double *) NULL;
    int      cliquecount = 0;
    double maxdelta = maxslack * 2.0 + 2.0;
    int maxcliques = request;
    int rval = 0;

    *kcount = 0;
    *klist = (Xportableclique *) NULL;

    printf ("Checking Xpoolcliques...\n"); fflush (stdout);

    rval = CCtsp_search_cutpool_cliques (xpool, &cliquelist, &cliquecount,
                       G->nnodes, ecount, elist, x, maxdelta, maxcliques,
                       &cliquevals);

    printf ("Back from CCtsp_search_cutpool_cliques\n"); fflush (stdout);
    if (rval) {
        fprintf (stderr, "CCtsp_search_cutpool_cliques failed\n");
        goto CLEANUP;
    }

    if (!cliquecount) {
        printf ("Found no nearly tight cliques\n"); fflush (stdout);
        goto CLEANUP;
    }

    *klist = CC_SAFE_MALLOC (cliquecount, Xportableclique);
    if (!(*klist)) {
        fprintf (stderr, "out of memory in Xsearch_cutpool\n");
        rval = 1; goto CLEANUP;
    }

    for (i = 0; i < cliquecount; i++) {
        c = &(cliquelist[i]);
        isize = 0;
        for (k = 0; k < c->segcount; k++) {
            isize += (c->nodes[k].hi - c->nodes[k].lo + 1);
        }
        (*klist)[i].size = isize;
        (*klist)[i].nodes = CC_SAFE_MALLOC (isize, int);
        if (!(*klist)[i].nodes) {
            fprintf (stderr, "out of memory in Xsearch_cutpool A\n");
            CC_FREE (*klist, Xportableclique);
            rval = 1; goto CLEANUP;
        }
        p = 0;
        for (k = 0; k < c->segcount; k++) {
            for (j = c->nodes[k].lo; j <= c->nodes[k].hi; j++) {
                (*klist)[i].nodes[p++] = j;
            }
        }
        (*klist)[i].cutval = ((2.0 *((double) isize)) - cliquevals[i])/2.0;
        (*klist)[i].cutval = (double) isize - 1.0 - (*klist)[i].cutval;
    }
    *kcount = cliquecount;

CLEANUP:

    for (i = 0; i < cliquecount; i++) {
        CC_IFFREE (cliquelist[i].nodes, CCtsp_segment);
    }
    CC_IFFREE (cliquelist, CCtsp_lpclique);
    CC_IFFREE (cliquevals, double);
    return rval;
}
