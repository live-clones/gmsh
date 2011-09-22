/**************************************************************************/
/*                                                                        */
/*     OLD GRAPH STUFF - Routines for building the old style graphs to    */
/*                       run the separation routines from concorde.       */
/*                       The separation routines will not be threadsafe.  */
/*                                                                        */
/* EXPORTED FUNCTIONS:                                                    */
/*                                                                        */
/*    void                                                                */
/*        Xfreegraph (Xgraph *G)                                          */
/*                                                                        */
/**************************************************************************/

#include "machdefs.h"
#include "util.h"
#include "Xsubtour.h"

#ifdef CC_PROTOTYPE_ANSI
int Xbuildgraph (Xgraph *G, int ncount, int ecount, int *elist, int *elen)
#else
int Xbuildgraph (G, ncount, ecount, elist, elen)
Xgraph *G;
int ncount;
int ecount;
int *elist;
int *elen;
#endif
{
    Xedge *e;
    Xedgeptr *e1;
    int i, k, n1, n2;

    G->edgelist = (Xedge *) NULL;
    G->nodelist = (Xnode *) NULL;
    G->pseudonodelist = (Xnode *) NULL;
    G->pseudoedgelist = (Xedge *) NULL;
    G->npseudonodes = 0;
    G->magicnum = 0;
    G->stacknum = 0;
    G->magicedgenum = 0;

    G->nnodes = ncount;
    G->nedges = ecount;
    G->nodelist = CC_SAFE_MALLOC (ncount, Xnode);
    if (!G->nodelist)
        return 1;
    G->edgelist = CC_SAFE_MALLOC (ecount, Xedge);
    if (!G->edgelist) {
        CC_FREE (G->nodelist, Xnode);
        return 1;
    }

    for (i = 0; i < ncount; i++) {
        G->nodelist[i].adj.head = G->nodelist[i].adj.tail = (Xedgeptr *) NULL;
        G->nodelist[i].magiclabel = 0;
        G->nodelist[i].stacklabel = 0;
    }
    for (i = 0, e = G->edgelist, k = 0; i < ecount; i++, e++) {
        n1 = elist[k++];
        n2 = elist[k++];
        e->weight = elen[i];
        e->ends[0] = G->nodelist + n1;
        e->ends[1] = G->nodelist + n2;
        e->elim = 0;
        e->weak = 0;
        e->fixed = 0;
        e->hold = 0;            /* use 1 to hold original edges in weak
                                 * remove */
        e->x = 0.0;
        e->rc = 0.0;
        e->magiclabel = 0;
    }

    for (i = ecount, e = G->edgelist; i; i--, e++) {
        e1 = Xedgeptralloc ();
        e1->next = e->ends[0]->adj.head;
        e1->this = e;
        e->ends[0]->adj.head = e1;
        if (e->ends[0]->adj.tail == (Xedgeptr *) NULL)
            e->ends[0]->adj.tail = e1;
        e1 = Xedgeptralloc ();
        e1->next = e->ends[1]->adj.head;
        e1->this = e;
        e->ends[1]->adj.head = e1;
        if (e->ends[1]->adj.tail == (Xedgeptr *) NULL)
            e->ends[1]->adj.tail = e1;
    }
    Xinit_hash_values (G);
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
void Xfreegraph (Xgraph *G)
#else
void Xfreegraph (G)
Xgraph *G;
#endif
{
    int i;
    Xnode *n;
    Xedgeptr *e, *enext;

    if (G->nodelist) {
        for (i = G->nnodes, n = G->nodelist; i; i--, n++) {
            for (e = n->adj.head; e; e = enext) {
                enext = e->next;
                Xedgeptrfree (e);
            }
            n->adj.head = n->adj.tail = (Xedgeptr *) NULL;
        }
        CC_FREE (G->nodelist, Xnode);
    }
    if (G->edgelist)
        CC_FREE (G->edgelist, Xedge);
}

#ifdef CC_PROTOTYPE_ANSI
void Xloadx (Xgraph *G, double *x)
#else
void Xloadx (G, x)
Xgraph *G;
double *x;
#endif
{
    double *dp;
    Xedge *pe;
    int i;

    for (i = G->nedges, pe = G->edgelist, dp = x; i; i--)
        pe++->x = *dp++;

}
