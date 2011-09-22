/***************************************************************************/
/*                                                                         */
/*                  SOME ROUTINES FOR HANDLING CLIQUES                     */
/*                                                                         */
/*                              TSP CODE                                   */
/*                                                                         */
/*                                                                         */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook                       */
/*  Date: July 15, 1997                                                    */
/*                                                                         */
/*                                                                         */
/*  EXPORTED FUNCTIONS:                                                    */
/*                                                                         */
/*    void CCtsp_mark_clique (CCtsp_lpclique *c, int *marks, int marker)   */
/*     MARKS the nodes in clique c                                         */
/*      -marks an array of length at least ncount                          */
/*      -marker an int that is used to mark the clique entries in marks    */
/*                                                                         */
/*    void CCtsp_mark_clique_and_neighbors (CCtsp_lpgraph *g,              */
/*            CCtsp_lpclique *c, int *marks, int marker)                   */
/*     MARKS the clique and the neighbors of the clique                    */
/*                                                                         */
/*    void CCtsp_mark_clique_and_neighbors_double (CCtsp_lpgraph *g,       */
/*            CCtsp_lpclique *c, double *marks, double marker)             */
/*     MARKS the clique and the neighbors of the clique in a double array. */
/*                                                                         */
/*    void CCtsp_mark_cut (CCtsp_lpcut_in *c, int *marks, int marker)      */
/*     MARKS the nodes in the cut.                                         */
/*                                                                         */
/*    void CCtsp_mark_cut_and_neighbors (CCtsp_lpgraph *g,                 */
/*            CCtsp_lpcut_in *c, int *marks, int marker)                   */
/*     MARKS the nodes in the cut and their neighbors                      */
/*                                                                         */
/*    void CCtsp_is_clique_marked (CCtsp_lpclique *c, int *marks,          */
/*            int marker, int *yes_no)                                     */
/*     CHECKS if a node in the clique is marked with the value marker.     */
/*      -yesno returns the result (1 is yes and 0 is no)                   */
/*                                                                         */
/*    void CCtsp_clique_count (CCtsp_lpclique *c, int *count)              */
/*     COUNTS the number of nodes in the clique.                           */
/*                                                                         */
/*    int CCtsp_clique_to_array (CCtsp_lpclique *c, int **ar, int *count)  */
/*     EXPANDS a clique into an array of integers.                         */
/*                                                                         */
/*    int CCtsp_clique_delta (CCtsp_lpgraph *g, double *x,                 */
/*            CCtsp_lpclique *c, double *delta)                            */
/*     COMPUTES the sum of the x-edges in the coboundary of the clique,    */
/*      that is, x(delta(c)).                                              */
/*      -delta returns the sum                                             */
/*                                                                         */
/***************************************************************************/

#include "machdefs.h"
#include "util.h"
#include "tsp.h"


#ifdef CC_PROTOTYPE_ANSI
void CCtsp_mark_clique (CCtsp_lpclique *c, int *marks, int marker)
#else
void CCtsp_mark_clique (c, marks, marker)
CCtsp_lpclique *c;
int *marks;
int marker;
#endif
{
    int i, j;

    for (i = 0; i < c->segcount; i++) {
        for (j = c->nodes[i].lo; j <= c->nodes[i].hi; j++) {
            marks[j] = marker;
        }
    }
}

#ifdef CC_PROTOTYPE_ANSI
void CCtsp_mark_clique_and_neighbors (CCtsp_lpgraph *g, CCtsp_lpclique *c,
        int *marks, int marker)
#else
void CCtsp_mark_clique_and_neighbors (g, c, marks, marker)
CCtsp_lpgraph *g;
CCtsp_lpclique *c;
int *marks;
int marker;
#endif
{
    int i, j, k;

    for (i = 0; i < c->segcount; i++) {
        for (j = c->nodes[i].lo; j <= c->nodes[i].hi; j++) {
            marks[j] = marker;
            for (k = 0; k < g->nodes[j].deg; k++) {
                marks[g->nodes[j].adj[k].to] = marker;
            }
        }
    }
}

#ifdef CC_PROTOTYPE_ANSI
void CCtsp_mark_cut (CCtsp_lpcut_in *c, int *marks, int marker)
#else
void CCtsp_mark_cut (c, marks, marker)
CCtsp_lpcut_in *c;
int *marks;
int marker;
#endif
{
    int i;

    for (i = 0; i < c->cliquecount; i++) {
        CCtsp_mark_clique (&(c->cliques[i]), marks, marker);
    }
}

#ifdef CC_PROTOTYPE_ANSI
void CCtsp_mark_cut_and_neighbors (CCtsp_lpgraph *g, CCtsp_lpcut_in *c,
        int *marks, int marker)
#else
void CCtsp_mark_cut_and_neighbors (g, c, marks, marker)
CCtsp_lpgraph *g;
CCtsp_lpcut_in *c;
int *marks;
int marker;
#endif
{
    int i;

    for (i = 0; i < c->cliquecount; i++) {
        CCtsp_mark_clique_and_neighbors (g, &(c->cliques[i]), marks, marker);
    }
}

#ifdef CC_PROTOTYPE_ANSI
void CCtsp_mark_clique_and_neighbors_double (CCtsp_lpgraph *g,
        CCtsp_lpclique *c, double *marks, double marker)
#else
void CCtsp_mark_clique_and_neighbors_double (g, c, marks, marker)
CCtsp_lpgraph *g;
CCtsp_lpclique *c;
double *marks;
double marker;
#endif
{
    int i, j, k;

    for (i = 0; i < c->segcount; i++) {
        for (j = c->nodes[i].lo; j <= c->nodes[i].hi; j++) {
            marks[j] = marker;
            for (k = 0; k < g->nodes[j].deg; k++) {
                marks[g->nodes[j].adj[k].to] = marker;
            }
        }
    }
}

#ifdef CC_PROTOTYPE_ANSI
void CCtsp_is_clique_marked (CCtsp_lpclique *c, int *marks, int marker,
        int *yes_no)
#else
void CCtsp_is_clique_marked (c, marks, marker, yes_no)
CCtsp_lpclique *c;
int *marks;
int marker;
int *yes_no;
#endif
{
    int i, j;

    for (i = 0; i < c->segcount; i++) {
        for (j = c->nodes[i].lo; j <= c->nodes[i].hi; j++) {
            if (marks[j] == marker) {
                *yes_no = 1;
                return;
            }
        }
    }
    *yes_no = 0;
}

#ifdef CC_PROTOTYPE_ANSI
void CCtsp_clique_count (CCtsp_lpclique *c, int *count)
#else
void CCtsp_clique_count (c, count)
CCtsp_lpclique *c;
int *count;
#endif
{
    int i;
    CCtsp_segment *nodes = c->nodes;

    *count = 0;
    for (i = 0; i < c->segcount; i++) {
        (*count) += (nodes[i].hi - nodes[i].lo + 1);
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_clique_to_array (CCtsp_lpclique *c, int **ar, int *count)
#else
int CCtsp_clique_to_array (c, ar, count)
CCtsp_lpclique *c;
int **ar;
int *count;
#endif
{
    int rval = 0;
    int i, j;
    int k = 0;

    *ar = (int *) NULL;

    CCtsp_clique_count (c, count);
    if (count) {
        *ar = CC_SAFE_MALLOC (*count, int);
        if (!(*ar)) {
            fprintf (stderr, "out of memory in CCtsp_clique_to_array\n");
            rval = 1; goto CLEANUP;
        }
        for (i = 0; i < c->segcount; i++) {
            for (j = c->nodes[i].lo; j <= c->nodes[i].hi; j++) {
                (*ar)[k++] = j;
            }
        }
    }

CLEANUP:

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_clique_delta (CCtsp_lpgraph *g, double *x, CCtsp_lpclique *c,
        double *delta)
#else
int CCtsp_clique_delta (g, x, c, delta)
CCtsp_lpgraph *g;
double *x;
CCtsp_lpclique *c;
double *delta;
#endif
{
    int rval = 0;
    int i, j, k;
    int *marks = (int *) NULL;
    CCtsp_lpnode *n;

    *delta = 0.0;

    marks = CC_SAFE_MALLOC (g->ncount, int);
    if (!marks) {
        fprintf (stderr, "out of memory in CCtsp_clique_delta\n");
        rval = 1; goto CLEANUP;
    }

    CCtsp_mark_clique_and_neighbors (g, c, marks, 0);
    CCtsp_mark_clique (c, marks, 1);

    for (i = 0; i < c->segcount; i++) {
        for (j = c->nodes[i].lo; j <= c->nodes[i].hi; j++) {
            n = &g->nodes[j];
            for (k = 0; k < n->deg; k++) {
                if (!marks[n->adj[k].to]) {
                    (*delta) += x[n->adj[k].edge];
                }
            }
        }
    }

CLEANUP:

    CC_IFFREE (marks, int);
    return rval;
}
