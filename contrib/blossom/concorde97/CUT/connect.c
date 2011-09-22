/***************************************************************************/
/*                                                                         */
/*                   Cuts from Connected Components                        */
/*                                                                         */
/*                              TSP CODE                                   */
/*                                                                         */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook                       */
/*  Date: February 17, 1997                                                */
/*                                                                         */
/*  EXPORTED FUNCTIONS:                                                    */
/*    int CCcut_connect_components (int ncount, int ecount, int *elist,    */
/*            double *x, int *ncomp, int **compscount, int **comps)        */
/*     RETURNS the connected components of the graph given by the edgeset  */
/*      -ncount is the number of nodes                                     */
/*      -ecount is the number of edges                                     */
/*      -elist is the edge list in node node format                        */
/*      -x is an vector of length ecount (it can be NULL); is it is not    */
/*       NULL, then the connected components will be for the graph         */
/*       consisting of the positive edges                                  */
/*      -ncomp will return the number of connected components              */
/*      -compscount will return the number of nodes in each of the         */
/*       components (it will be an ncomp long array)                       */
/*      -comps will return the nodes in the components (it will be an      */
/*       ncount array, with the first compscount[0] elements making up     */
/*       the first component, etc.)                                        */
/*                                                                         */
/*  NOTES:                                                                 */
/*                                                                         */
/***************************************************************************/

#include "machdefs.h"
#include "util.h"
#include "cut.h"

#define CONNECT_ZERO_EPSILON (1e-10)

typedef struct node {
    int *adj;
    int degree;
    int mark;
} node;

typedef struct graph {
    node *nodelist;
    int  *adjspace;
    int ncount;
    int ecount;
} graph;

#ifdef CC_PROTOTYPE_ANSI

static int
    build_graph (graph *G, int ncount, int ecount, int *elist,
                 double *x);

static void
    free_graph (graph *G),
    connect_search (graph *G, int n, int marker, int *dstack);

#else

static int
    build_graph ();

static void
    free_graph (),
    connect_search ();

#endif

#ifdef  CC_PROTOTYPE_ANSI
int CCcut_connect_components (int ncount, int ecount, int *elist, double *x,
        int *ncomp, int **compscount, int **comps)
#else
int CCcut_connect_components (ncount, ecount, elist, x, ncomp, compscount,
        comps)
int ncount;
int ecount;
int *elist;
double *x;
int *ncomp;
int **compscount;
int **comps;
#endif
{
    graph G;
    int i, k, rval;
    int *nmarks = (int *) NULL;
    int *dstack = (int *) NULL;

    G.nodelist = (node *) NULL;
    G.adjspace = (int *) NULL;

    *ncomp = 0;
    *comps = CC_SAFE_MALLOC (ncount, int);
    if (!(*comps)) {
        fprintf (stderr, "out of memory in CCcut_connect_components\n");
        rval = 1; goto CLEANUP;
    }

    rval = build_graph (&G, ncount, ecount, elist, x);
    if (rval) {
        fprintf (stderr, "build_graph failed\n");
        goto CLEANUP;
    }

    dstack = CC_SAFE_MALLOC (ncount, int);
    if (!dstack) {
        fprintf (stderr, "out of memory in CCcut_connect_components\n");
        CC_FREE (*comps, int);
        rval = 1; goto CLEANUP;
    }
    for (i = 0; i < ncount; i++) {
        if (!G.nodelist[i].mark) {
            (*ncomp)++;
            connect_search (&G, i, *ncomp, dstack);
        }
    }

    *compscount = CC_SAFE_MALLOC (*ncomp, int);
    nmarks = CC_SAFE_MALLOC (*ncomp, int);
    if (!(*compscount) || !nmarks) {
        fprintf (stderr, "out of memory in CCcut_connect_components\n");
        CC_FREE (*comps, int);
        CC_IFFREE (*compscount, int);
        CC_IFFREE (nmarks, int);
        rval = 1; goto CLEANUP;
    }
    for (i = 0; i < *ncomp; i++) {
        nmarks[i] = 0;
    }
    for (i = 0; i < ncount; i++) {
        nmarks[G.nodelist[i].mark - 1]++;
    }
    for (i = 0, k = 0; i < *ncomp; i++) {
        (*compscount)[i] = nmarks[i];
        nmarks[i] = k;
        k += (*compscount)[i];
    }
    for (i = 0; i < ncount; i++) {
        (*comps)[(nmarks[G.nodelist[i].mark - 1])++] = i;
    }

CLEANUP:

    free_graph (&G);
    CC_IFFREE (nmarks, int);
    CC_IFFREE (dstack, int);
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static int build_graph (graph *G, int ncount, int ecount, int *elist,
        double *x)
#else
static int build_graph (G, ncount, ecount, elist, x)
graph *G;
int ncount, ecount;
int *elist;
double *x;
#endif
{
    int rval = 0;
    int i;
    int *p;
    node *nodelist;

    G->nodelist = (node *) NULL;
    G->adjspace = (int *) NULL;
    G->ncount = ncount;
    if (x) {
        G->ecount = 0;
        for (i = 0; i < ecount; i++) {
            if (x[i] > CONNECT_ZERO_EPSILON)
                G->ecount++;
        }
    } else {
       G->ecount = ecount;
    }

    G->nodelist = CC_SAFE_MALLOC (G->ncount, node);
    G->adjspace = CC_SAFE_MALLOC (2*G->ecount, int);
    if (!G->nodelist || !G->adjspace) {
        fprintf (stderr, "out of memory in build_graph\n");
        rval = 1; goto CLEANUP;
    }
    nodelist = G->nodelist;

    for (i = 0; i < ncount; i++) {
        nodelist[i].degree = 0;
        nodelist[i].mark = 0;
    }

    if (x) {
        for (i = 0; i < ecount; i++) {
            if (x[i] > CONNECT_ZERO_EPSILON) {
                nodelist[elist[2*i]].degree++;
                nodelist[elist[2*i+1]].degree++;
            }
        }
    } else {
        for (i = 0; i < ecount; i++) {
            nodelist[elist[2*i]].degree++;
            nodelist[elist[2*i+1]].degree++;
        }
    }

    p = G->adjspace;
    for (i = 0; i < ncount; i++) {
        nodelist[i].adj = p;
        p += nodelist[i].degree;
        nodelist[i].degree = 0;
    }

    if (x) {
        for (i = 0; i < ecount; i++) {
            if (x[i] > CONNECT_ZERO_EPSILON) {
                nodelist[elist[2*i]].adj[nodelist[elist[2*i]].degree++]
                                                = elist[2*i+1];
                nodelist[elist[2*i+1]].adj[nodelist[elist[2*i+1]].degree++]
                                                = elist[2*i];
            }
        }
    } else {
        for (i = 0; i < ecount; i++) {
            nodelist[elist[2*i]].adj[nodelist[elist[2*i]].degree++]
                                            = elist[2*i+1];
            nodelist[elist[2*i+1]].adj[nodelist[elist[2*i+1]].degree++]
                                            = elist[2*i];
        }
    }

CLEANUP:

    if (rval) {
        CC_IFFREE (G->nodelist, node);
        CC_IFFREE (G->adjspace, int);
    }
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static void free_graph (graph *G)
#else
static void free_graph (G)
graph *G;
#endif
{
    CC_IFFREE (G->nodelist, node);
    CC_IFFREE (G->adjspace, int);
}

#ifdef CC_PROTOTYPE_ANSI
static void connect_search (graph *G, int n, int marker, int *dstack)
#else
static void connect_search (G, n, marker, dstack)
graph *G;
int n, marker;
int *dstack;
#endif
{
    int i, k, head = 0;
    node *nodelist = G->nodelist;

    nodelist[n].mark = marker;
    dstack[head++] = n;

    while (head > 0) {
        n = dstack[--head];
        for (i = 0; i < nodelist[n].degree; i++) {
            k = nodelist[n].adj[i];
            if (!nodelist[k].mark) {
                nodelist[k].mark = marker;
                dstack[head++] =  k;
            }
        }
    }
}
