/**************************************************************************/
/*                                                                        */
/* EXPORTED FUNCTIONS:                                                    */
/*                                                                        */
/*  int                                                                   */
/*      Xolaf_combs (Xgraph *G, Xcplane *list, double *x),                */
/*      Xblobcuts (Xgraph *G, Xcplane **list, double *x);                 */
/*                                                                        */
/**************************************************************************/

#include "machdefs.h"
#include "Xsubtour.h"

#ifdef CC_PROTOTYPE_ANSI

static int
    run_olaf (Xgraph *G, Xcplane **list, double *x, int olaf_select, int count),
    dfs (Xgraph *G, Xnode *start);

#else

static int
    run_olaf (),
    dfs ();

#endif

#ifdef CC_PROTOTYPE_ANSI
int Xolaf_combs (Xgraph *G, Xcplane **list, double *x)
#else
int Xolaf_combs (G, list, x)
Xgraph *G;
Xcplane **list;
double *x;
#endif
{
    int cnt;

    cnt =  run_olaf (G, list, x, 3, 4);
    if (cnt >= XCUTNUM)
        return cnt;
    cnt += run_olaf (G, list, x, 1, 1);
    if (cnt >= XCUTNUM)
        return cnt;
    cnt += run_olaf (G, list, x, 2, 1);
    if (cnt >= XCUTNUM)
        return cnt;
    cnt += run_olaf (G, list, x, 4, 1);

    return cnt;
}


#ifdef CC_PROTOTYPE_ANSI
static int run_olaf (Xgraph *G, Xcplane **list, double *x, int olaf_select,
            int count)
#else
static int run_olaf (G, list, x, olaf_select, count)
Xgraph *G;
Xcplane **list;
double *x;
int olaf_select, count;
#endif
{
    int hit, cuts, round;

    Xloadx (G, x);
    hit = round = 0;
    Xbuildpseudonodelist (G, 0);
    while (round < count && hit < XCUTNUM && Xolaf (G, olaf_select)) {
        hit += (cuts = Xexactblossomcheck (G, list, 1, x));
        printf ("    [%d olaf(%d) combs]\n", cuts, olaf_select);
        fflush (stdout);
        round++;
    }
    Xdestroypseudonodelist (G);
    return hit;
}


#ifdef CC_PROTOTYPE_ANSI
int Xblobcuts (Xgraph *G, Xcplane **list, double *x)
#else
int Xblobcuts (G, list, x)
Xgraph *G;
Xcplane **list;
double *x;
#endif
{
    int i;

    if (dfs (G, &(G->nodelist[0])) != G->nnodes) {
        printf ("  cannot run blobcuts on disconnected graph\n");
        fflush (stdout);
        return 0;
    }
    Xpancakex (G, x);
    i = Xblobsviolated (G, list);
    Xfreepancake ();

    return i;
}

#ifdef CC_PROTOTYPE_ANSI
static int dfs (Xgraph *G, Xnode *start)
#else
static int dfs (G, start)
Xgraph *G;
Xnode *start;
#endif
{
    int i = 0;
    Xedgeptr *epp;
    Xedge *ep;
    Xnode *n, *n1;
    Xnodeptr *next, *queue = (Xnodeptr *) NULL;

    G->magicnum++;
    start->magiclabel = G->magicnum;
    Xadd_nodeptr (&queue, start);

    while (queue) {
        i++;
        n = queue->this;
        next = queue->next;
        Xnodeptrfree (queue);
        queue = next;
        for (epp = n->adj.head; epp; epp = epp->next) {
            ep = epp->this;
            n1 = ep->ends[0];
            if (n1 == n)
                n1 = ep->ends[1];
            if (n1->magiclabel != G->magicnum) {
                n1->magiclabel = G->magicnum;
                Xadd_nodeptr (&queue, n1);
            }
        }
    }
    return i;
}

