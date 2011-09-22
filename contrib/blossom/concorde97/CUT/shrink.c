/***************************************************************************/
/*                                                                         */
/*                             SHRINK ROUTINES                             */
/*                                                                         */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook (TSP Code)            */
/*  Date: July 19, 1996                                                    */
/*        October 21, 1996 (bico)                                          */
/*                                                                         */
/*  EXPORTED FUNCTIONS:                                                    */
/*                                                                         */
/*   void CCcut_SRK_init_graph (CC_SRKgraph *G)                            */
/*    INITIALIZES the fields of the CC_SRKgraph.                           */
/*                                                                         */
/*   void CCcut_SRK_free_graph (CC_SRKgraph *G)                            */
/*    FREES the SRKgraph.                                                  */
/*                                                                         */
/*   int CCcut_SRK_grab_edges (CC_SRKgraph *G, int *oncount, int *oecount, */
/*          int **olist, double **olen, CC_SRKexpinfo *expand)             */
/*          int **omembers)                                                */
/*    RETURNS the edges and member lists for the shrunk graph.             */
/*     -G is a pointer to a shrunk graph                                   */
/*     -oncount returns the number of nodes in the shrunk graph            */
/*     -oecount returns the number of edges in the shrunk graph            */
/*     -olist returns the edges in node node format                        */
/*     -olen returns the edge lengths                                      */
/*     -expand will be filled in with a memindex and members array;        */
/*      memindex returns pointers into the members array, the              */
/*      members of node i will be stored in from memindex[i] to            */
/*      memindex[i+1] - 1, so memindex is ncount + 1 long; members         */
/*      returns the nodes lists corresponding to each node in the          */
/*      shrunk graph. (expand can be NULL)                                 */
/*                                                                         */
/*   int CCcut_SRK_grab_nodes (CC_SRKgraph *G, SRKexpinfo *expand          */
/*    RETURNS the member lists for the shrunk graph (see above)            */
/*                                                                         */
/*  NOTE: Cyles of 1's will be shrunk into single nodes.                   */
/*                                                                         */
/***************************************************************************/

#include "machdefs.h"
#include "util.h"
#include "cut.h"

#define ADD_TO_PR_QUEUE(n) {                                             \
    if (!(n)->onqueue) {                                                 \
        (n)->qnext = (CC_SRKnode *) NULL;                                \
        if (qtail)                                                       \
            qtail->qnext = (n);                                          \
        else                                                             \
            qhead = (n);                                                 \
        qtail = (n);                                                     \
        (n)->onqueue = 1;                                                \
    }                                                                    \
}

#undef  PR_USE3   /* PR_USE3 and PR_USE4 cannot be defined in current code */
#undef  PR_USE4
#undef DEBUG_SHRINK
#define CC_SRK_ZERO_EPSILON (1e-10)

#ifdef CC_PROTOTYPE_ANSI

static void
#ifdef DEBUG_SHRINK
    printgraph (CC_SRKgraph *G),
#endif
    count_ones (CC_SRKgraph *G),
    merge_adj (CC_SRKgraph *G, CC_SRKnode *n, CC_SRKnode *m);

static int
    test_node (CC_SRKnode *n, double *minval, CC_SRKcallback *cb, int **cut,
        int *cutcount),
    expand_the_node (CC_SRKnode *n, int *cutcount, int **cut),
    expand_and_pass (CC_SRKnode *n, int (*doit_fn) (double, int, int *,
        void *), void *pass_param);

#else

static void
#ifdef DEBUG_SHRINK
    printgraph (),
#endif
    count_ones (),
    merge_adj ();

static int
    test_node (),
    expand_the_node (),
    expand_and_pass ();

#endif

#ifdef CC_PROTOTYPE_ANSI
int CCcut_SRK_subtour_shrink (CC_SRKgraph *G, double *minval, double epsilon,
        CC_SRKcallback *cb, int **cut, int *cutcount)
#else
int CCcut_SRK_subtour_shrink (G, minval, epsilon, cb, cut, cutcount)
CC_SRKgraph *G;
double *minval;
double epsilon;
CC_SRKcallback *cb;
int **cut;
int *cutcount;
#endif
{
    int rval = 0;
    int k, cnt = 0;
    CC_SRKnode *n;

    for (n = G->head; n; n = n->next) {
        cnt++;
    }

    /* In the tsp, paths of 1's can be shrunk via a call to the function  */
    /* CCcut_SRK_identify_paths.                                          */

    /* Could call a version of CCcut_SRK_identify_ones */

    printf ("Identify PR edges ....\n");
    fflush (stdout);
    rval = CCcut_SRK_identify_pr_edges (G, minval, &k, (CC_SRKnode *) NULL,
                   epsilon, cb, cut, cutcount);
    if (rval) {
        fprintf (stderr, "SRK_identify_pr_edges failed\n"); goto CLEANUP;
    }

    cnt -= k;
    printf ("Graph shrunk to %d nodes\n", cnt);
    fflush (stdout);

CLEANUP:

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static void count_ones (CC_SRKgraph *G)
#else
static void count_ones (G)
CC_SRKgraph *G;
#endif
{
    int k;
    CC_SRKnode *n;
    CC_SRKedge *e;

    for (n = G->head; n; n = n->next) {
        for (k = 0, e = n->adj; e; e = e->next) {
            if (e->weight == 1.0)
                k++;
        }
        n->onecnt = k;
    }
}

#ifdef CC_PROTOTYPE_ANSI
void CCcut_SRK_identify_paths (CC_SRKgraph *G, int *newcount, int onecnt_okay)
#else
void CCcut_SRK_identify_paths (G, newcount, onecnt_okay)
CC_SRKgraph *G;
int onecnt_okay;
int *newcount;
#endif
{
    CC_SRKnode *n, *m, *last;
    CC_SRKedge *e, *f;
    int dropcnt = 0;
    double dropweight = 0.0;
    int k;

    printf ("Identify paths ...\n");
    fflush (stdout);

    if (!onecnt_okay)
        count_ones (G);
    for (n = G->head; n; n = n->next) {
        if (n->onecnt == 1) {
            e = n->adj;
            while (e->weight != 1.0)
                e = e->next;
            last = n;
            m = e->end;
            while (m->onecnt != 1) {
                m->parent = n;
                m->members = n->members;
                n->members = m;
                e = m->adj;
                while (e->weight != 1.0 || e->end == last)
                    e = e->next;
                last = m;
                m = e->end;
            }
            m->parent = n;
            m->members = n->members;
            n->members = m;
            m->onecnt = 3;
        }
    }

    for (n = G->head; n->parent != n; n = n->next);
    G->head = n;
    G->head->prev = (CC_SRKnode *) NULL;
    for (n = G->head->next; n; n = n->next) {
        if (n->parent != n) {
            n->prev->next = n->next;
            if (n->next)
               n->next->prev = n->prev;
        }
    }
    for (k = 0, n = G->head; n; n = n->next) {
        k++;
        if (n->members) {
            for (e = n->members->adj; e; e = e->next) {
                e->other->end = n;
            }
            for (m = n->members->members; m; m = m->members) {
                for (e = m->adj; e; e = e->next) {
                    if (e->weight == 1.0) {
                        e->other->end = n;
                    } else {
                        /* drop fluff edge */
                        dropcnt++;
                        dropweight += e->weight;
                        f = e->other;
                        if (f->prev) {
                            f->prev->next = f->next;
                        } else {
                            e->end->adj = f->next;
                        }
                        if (f->next) {
                            f->next->prev = f->prev;
                        }
                    }
                }
            }
            n->weight = n->weight + n->members->weight;
            merge_adj (G, n, n->members);
        }
    }

    if (dropcnt > 0) {
        printf ("dropped %d edges of total weight %f\n", dropcnt, dropweight);
        fflush (stdout);
    }

    *newcount = k;
}

#ifdef CC_PROTOTYPE_ANSI
int CCcut_SRK_defluff (CC_SRKgraph *G)
#else
int CCcut_SRK_defluff (G)
CC_SRKgraph *G;
#endif
{
    CC_SRKnode *n;
    CC_SRKedge *e, *enext;
    int k;
    int ndel = 0;
    double delweight = 0.0;

    for (n = G->head; n; n = n->next) {
        for (k = 0, e = n->adj; e; e = e->next) {
            if (e->weight >= 1.0 - CC_SRK_ZERO_EPSILON) {
                e->weight = 1.0;
                k++;
            }
        }
        n->onecnt = k;
    }

    for (n = G->head; n; n = n->next) {
        for (e = n->adj, n->adj = (CC_SRKedge *) NULL; e; e = enext) {
            enext = e->next;
            if (e->weight == 1.0 ||
                (n->onecnt < 2 && e->end->onecnt < 2
                 && e->weight > CC_SRK_ZERO_EPSILON)) {
                if (n->adj) n->adj->prev = e;
                e->next = n->adj;
                n->adj = e;
                e->prev = (CC_SRKedge *) NULL;
            } else {
                delweight += e->weight;
                ndel++;
            }
        }
    }

    if (ndel & 1) {
        fprintf (stderr, "Whoa, deleted %d (odd) endpoints in SRK_defluff\n",
                 ndel);
        return -1;
    }
    printf ("SRK_defluff deleted %d endpoints (weight %.6f)\n", ndel,
            delweight);
    fflush (stdout);
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
void CCcut_SRK_identify_paths_to_edges (CC_SRKgraph *G, int *newcount,
        int onecnt_okay)
#else
void CCcut_SRK_identify_paths_to_edges (G, newcount, onecnt_okay)
CC_SRKgraph *G;
int *newcount;
int onecnt_okay;
#endif
{
    CC_SRKnode *n, *p, *m, *last;
    CC_SRKedge *e;
    int k;

    printf ("Identify paths to edges ...\n");
    fflush (stdout);

    /* NOTE: We should add in code to drop fluff edges */

    if (!onecnt_okay)
        count_ones (G);
    for (n = G->head; n; n = n->next) {
        if (n->onecnt == 1) {
            e = n->adj;
            while (e->weight != 1.0)
                e = e->next;
            m = e->end;
            if (m->onecnt != 1) {
                e = m->adj;
                while (e->weight != 1.0 || e->end == n)
                    e = e->next;
                last = m;
                p = e->end;
                while (p->onecnt != 1) {
                    p->parent = m;
                    p->members = m->members;
                    m->members = p;
                    e = p->adj;
                    while (e->weight != 1.0 || e->end == last)
                         e = e->next;
                    last = p;
                    p = e->end;
                }
                p->parent = m;
                p->members = m->members;
                m->members = p;
                p->onecnt = 3;
            }
        }
    }


    for (n = G->head; n->parent != n; n = n->next);
    G->head = n;
    G->head->prev = (CC_SRKnode *) NULL;
    for (n = G->head->next; n; n = n->next) {
        if (n->parent != n) {
            n->prev->next = n->next;
            if (n->next)
               n->next->prev = n->prev;
        }
    }
    for (k = 0, n = G->head; n; n = n->next) {
        k++;
        if (n->members) {
            for (m = n->members; m; m = m->members) {
                for (e = m->adj; e; e = e->next)
                    e->other->end = n;
            }
            merge_adj (G, n, n->members);
        }
    }
    *newcount = k;
}

#ifdef CC_PROTOTYPE_ANSI
void CCcut_SRK_identify_ones (CC_SRKgraph *G, int *count, double epsilon)
#else
void CCcut_SRK_identify_ones (G, count, epsilon)
CC_SRKgraph *G;
int *count;
double epsilon;
#endif
{
    CC_SRKnode *n;
    CC_SRKedge *e;
    double tol = 1.0 - epsilon;

    printf ("Identify ones ....\n");
    fflush (stdout);

    *count = 0;

    for (n = G->head; n; n = n->next) {
        do {
            for (e = n->adj; e; e = e->next) {
                if (e->weight >= tol) {
                    CCcut_SRK_identify_nodes (G, n, e->end);
                    (*count)++;
                    break;
                }
            }
        } while (e);
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CCcut_SRK_identify_pr_edges (CC_SRKgraph *G, double *minval, int *count,
        CC_SRKnode *qstart, double epsilon, CC_SRKcallback *cb, int **cut,
        int *cutcount)
#else
int CCcut_SRK_identify_pr_edges (G, minval, count, qstart, epsilon, cb, cut,
        cutcount)
CC_SRKgraph *G;
double *minval;
int *count;
CC_SRKnode *qstart;
double epsilon;
CC_SRKcallback *cb;
int **cut;
int *cutcount;
#endif
{
    int rval = 0;
    CC_SRKnode *n;
    CC_SRKedge *e, *f, *h;
    double tol, tol1, tol2;
    CC_SRKnode *qhead, *qtail;

    /* Trivial PR Test: If w(uv) >= c(u)/2, then we can shrink edge uv.   */

    /* First PR Test: If we have a triangle uv, uw, vw with               */
    /* w(uv) + w(vw) >= c(v)/2 and w(uw) + w(vw) >= c(w)/2, then we can   */
    /* shrink edge vw.                                                    */

    /* Second PR Test: Compute a lower bound on any cut that separates    */
    /* the ends of an edge by summing the minimum values of the edges to  */
    /* common neighbors of the ends. If the bound is >= "2", then we can  */
    /* shrink the edge.                                                   */

    /* Third PR Test: Edge uv with common neighbors xy. If                */
    /* w(ux) + w(uy) + w(uv) >= "1" and w(vx) + w(vy) + w(uv) >= "1" and  */
    /* at least one of w(uy) + w(uv) and w(vx) + w(uv) is >= "1" and      */
    /* at least one of w(ux) + w(uv) and w(vy) + w(uv) is >= "1" then we  */
    /* can shrink the edge uv.                                            */

    *count = 0;

    if (cut && !cutcount) {
        fprintf (stderr, "cut defined, but not cutcount\n");
        rval = 1; goto CLEANUP;
    }

    if (qstart) {
        qhead = qstart;
        for (n = qstart; n->next; n = n->next)
            n->onqueue = 1;
        qtail = n;
        qtail->onqueue = 1;
    } else {
        for (n = G->head; n->next; n = n->next) {
            n->qnext = n->next;
            n->onqueue = 1;
        }
        qhead = G->head;
        qtail = n;
        qtail->onqueue = 1;
        qtail->qnext = (CC_SRKnode *) NULL;
    }

    while (qhead) {
        n = qhead;
        qhead = qhead->qnext;
        if (!qhead)
            qtail = (CC_SRKnode *) NULL;
        if (n->parent != n)
            continue;
        n->onqueue = 0;
        tol = n->weight/2.0 - epsilon;

        for (e = n->adj; e && e->weight < tol; e = e->next);
        if (e) {
            rval = test_node (n, minval, cb, cut, cutcount);
            if (rval) { fprintf (stderr, "test_node failed\n"); goto CLEANUP; }
            rval = test_node (e->end, minval, cb, cut, cutcount);
            if (rval) { fprintf (stderr, "test_node failed\n"); goto CLEANUP; }
            CCcut_SRK_identify_nodes (G, n, e->end);
            (*count)++;
            ADD_TO_PR_QUEUE(n);
            for (h = n->adj; h; h = h->next) {
                ADD_TO_PR_QUEUE(h->end);
            }
        } else {
            for (e = n->adj; e; e = e->next)
                e->end->prweight = e->weight;
            for (e = n->adj; e; e = e->next) {
                tol1 = (n->weight/2.0) - e->weight - epsilon;
                tol2 = (e->end->weight/2.0) - e->weight - epsilon;
                for (f = e->end->adj; f; f = f->next) {
                    if (f->weight >= tol2 && f->end->prweight >= tol1) {
                        rval = test_node (n, minval, cb, cut, cutcount);
                        if (rval) {
                            fprintf (stderr, "test_node failed\n");
                            goto CLEANUP;
                        }
                        rval = test_node (e->end, minval, cb, cut, cutcount);
                        if (rval) {
                            fprintf (stderr, "test_node failed\n");
                            goto CLEANUP;
                        }
                        CCcut_SRK_identify_nodes (G, n, e->end);
                        (*count)++;
                        ADD_TO_PR_QUEUE(n);
                        for (h = n->adj; h; h = h->next) {
                            ADD_TO_PR_QUEUE(h->end);
                        }
                        goto GET_OUT;
                    }
                }
            }

#ifdef PR_USE3
    -Must modify to use node current min cut value.
            for (e = n->adj; e; e = e->next) {
                tol = e->weight;
                for (f = e->end->adj; f; f = f->next) {
                    if (f->end->prweight >= f->weight)
                        tol += f->weight;
                    else if (f->end->prweight > -2.0)
                        tol += f->end->prweight;
                }
                if (tol >= 1.0 + onetol) {
                    printf ("X"); fflush (stdout);
                    CCcut_SRK_identify_nodes (G, n, e->end);
                    (*count)++;
                    ADD_TO_PR_QUEUE(n);
                    for (h = n->adj; h; h = h->next) {
                        ADD_TO_PR_QUEUE(h->end);
                    }
                    goto GET_OUT;
                }
            }
#endif

#ifdef PR_USE4
    -Must modify to use node weights.
            for (e = n->adj; e; e = e->next) {
                tol = onetol - e->weight;
                for (f = e->end->adj; f; f = f->next) {
                    if (f->end->prweight > -2.0) {
                        for (h = f->next; h; h = h->next) {
                            if (h->end->prweight > -2.0) {
                                if (f->weight + h->weight >= tol
                       && f->end->prweight + h->end->prweight >= tol
                       && (f->weight >= tol || h->end->prweight >= tol)
                       && (h->weight >= tol || f->end->prweight >= tol)) {
                                    CCcut_SRK_identify_nodes (G, n, e->end);
                                    (*count)++;
                                        ADD_TO_PR_QUEUE(n);
                                    for (h = n->adj; h; h = h->next) {
                                        ADD_TO_PR_QUEUE(h->end);
                                    }
                                    goto GET_OUT;
                                }
                            }
                        }
                    }
                }
            }
#endif

GET_OUT:
            for (e = n->adj; e; e = e->next)
                e->end->prweight = -2.0;
        }
    }

CLEANUP:

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static int test_node (CC_SRKnode *n, double *minval, CC_SRKcallback *cb,
        int **cut, int *cutcount)
#else
static int test_node (n, minval, cb, cut, cutcount)
CC_SRKnode *n;
double *minval;
CC_SRKcallback *cb;
int **cut;
int *cutcount;
#endif
{
    int rval = 0;

    if (n->weight < *minval) {
        *minval = n->weight;
        /* printf ("New minimum: %f\n", *minval); */
        if (cut) {
            CC_IFFREE (*cut, int);
            rval = expand_the_node (n, cutcount, cut);
            if (rval) {
                fprintf (stderr, "expand_the_node failed\n"); goto CLEANUP;
            }
        }
    }
    if (cb) {
        if (n->weight <= cb->cutoff) {
            rval = expand_and_pass (n, cb->doit_fn, cb->pass_param);
            if (rval) {
                fprintf (stderr,"expand_and_pass failed\n"); goto CLEANUP;
            }
        }
    }

CLEANUP:

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static int expand_and_pass (CC_SRKnode *n, int (*doit_fn) (double, int, int *,
        void *), void *pass_param)
#else
static int expand_and_pass (n, doit_fn, pass_param)
CC_SRKnode *n;
int (*doit_fn) ();
void *pass_param;
#endif
{
    int rval = 0;
    int cutcount;
    int *cut = (int *) NULL;

    if (!doit_fn) goto CLEANUP;

    rval = expand_the_node (n, &cutcount, &cut);
    if (rval) {
        fprintf (stderr, "expand_the_node failed\n"); fflush (stdout);
    }

    rval = doit_fn (n->weight, cutcount, cut, pass_param);
    if (rval) {
        fprintf (stderr, "doit_fn failed\n"); goto CLEANUP;
    }

CLEANUP:

    CC_IFFREE (cut, int);
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static int expand_the_node (CC_SRKnode *n, int *cutcount, int **cut)
#else
static int expand_the_node (n, cutcount, cut)
CC_SRKnode *n;
int *cutcount;
int **cut;
#endif
{
    int rval = 0;
    int cnt;
    int *tcut = (int *) NULL;
    CC_SRKnode *v;

    *cutcount = 0;
    *cut = (int *) NULL;

    cnt = 1;
    for (v = n->members; v; v = v->members) {
        cnt++;
    }
    tcut = CC_SAFE_MALLOC (cnt, int);
    if (!tcut) {
        fprintf (stderr, "out of memory in expand_the_node\n");
        rval = 1; goto CLEANUP;
    }

    tcut[0] = n->num;
    cnt = 1;
    for (v = n->members; v; v = v->members) {
        tcut[cnt++] = v->num;
    }

    *cutcount = cnt;
    *cut = tcut;

CLEANUP:

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
void CCcut_SRK_identify_one_triangles (CC_SRKgraph *G, int *count,
        CC_SRKnode *qstart, double epsilon)
#else
void CCcut_SRK_identify_one_triangles (G, count, qstart, epsilon)
CC_SRKgraph *G;
int *count;
CC_SRKnode *qstart;
double epsilon;
#endif
{
    CC_SRKnode *n;
    CC_SRKedge *e, *f, *h;
    CC_SRKnode *qhead, *qtail;
    double tol = 1.0 - epsilon;

    printf ("Identify one edges in tight triangles ....\n");
    fflush (stdout);

    /* Identify any edge of weight one that is contained in a triangle of */
    /* weight two.   */

    *count = 0;
    if (qstart) {
        qhead = qstart;
        for (n = qstart; n->next; n = n->next)
            n->onqueue = 1;
        qtail = n;
        qtail->onqueue = 1;
    } else {
        for (n = G->head; n->next; n = n->next) {
            n->qnext = n->next;
            n->onqueue = 1;
        }
        qhead = G->head;
        qtail = n;
        qtail->onqueue = 1;
        qtail->qnext = (CC_SRKnode *) NULL;
    }

    while (qhead) {
        n = qhead;
        qhead = qhead->qnext;
        if (!qhead)
            qtail = (CC_SRKnode *) NULL;
        if (n->parent != n)
            continue;
        n->onqueue = 0;

        for (e = n->adj; e && e->weight < tol; e = e->next);
        if (e) {
            for (f = n->adj; f; f = f->next)
                f->end->prweight = f->weight;
            for (f = e->end->adj; f; f = f->next) {
                if (f->weight + f->end->prweight >= tol ||
                   (f->weight >= tol && f->end != n)) {
                    CCcut_SRK_identify_nodes (G, n, e->end);
                    (*count)++;
                    ADD_TO_PR_QUEUE(n);
                    for (h = n->adj; h; h = h->next) {
                        ADD_TO_PR_QUEUE(h->end);
                    }
                    goto GET_OUT;
                }
            }
GET_OUT:
            for (e = n->adj; e; e = e->next)
                e->end->prweight = -2.0;
        }
    }
}

#ifdef CC_PROTOTYPE_ANSI
void CCcut_SRK_identify_nodes (CC_SRKgraph *G, CC_SRKnode *n, CC_SRKnode *m)
#else
void CCcut_SRK_identify_nodes (G, n, m)
CC_SRKgraph *G;
CC_SRKnode *n, *m;
#endif
{
    CC_SRKedge *e;

    m->parent = n;
    n->weight += m->weight;

    if (!n->members) {
        n->members = m;
    } else if (!m->members) {
        m->members = n->members;
        n->members = m;
    } else {
        CC_SRKnode *t;
        for (t = n->members; t->members; t = t->members);
        t->members = m;
    }

    for (e = m->adj; e; e = e->next) {
        e->other->end = n;
    }

    merge_adj (G, n, m);

    if (m->prev)
        m->prev->next = m->next;
    else
        G->head = m->next;
    if (m->next)
        m->next->prev = m->prev;
}

#ifdef CC_PROTOTYPE_ANSI
static void merge_adj (CC_SRKgraph *G, CC_SRKnode *n, CC_SRKnode *m)
#else
static void merge_adj (G, n, m)
CC_SRKgraph *G;
CC_SRKnode *n, *m;
#endif
{
    CC_SRKedge *e, *f, *last, *work;
    CC_SRKedge **hit = G->hit;

    /* String together the two lists */

    if (n->adj) {
        for (last = n->adj; last->next; last = last->next);
        last->next = m->adj;
        if (m->adj)
            m->adj->prev = last;
        work = n->adj;
    } else {
        work = m->adj;
    }

    /* Remove any edges that become loops */

    while (work && work->end == n) {
        n->weight -= work->weight;
        work = work->next;
    }

    if (work) {
        work->prev = (CC_SRKedge *) NULL;
        for (e = work->next; e; e = e->next) {
            if (e->end == n) {
                n->weight -= e->weight;
                e->prev->next = e->next;
                if (e->next)
                    e->next->prev = e->prev;
            }
        }
    } else {
        n->adj = (CC_SRKedge *) NULL;
        return;
    }

    /* Remove the duplicate edges in the work list */

    hit[work->end->num] = work;
    for (e = work->next; e; e = e->next) {
        if (hit[e->end->num]) {
            /* A duplicate edge */

            hit[e->end->num]->weight += e->weight;
            hit[e->end->num]->other->weight = hit[e->end->num]->weight;
            e->prev->next = e->next;
            if (e->next)
                e->next->prev = e->prev;

            /* Fix the adj of the other end of the duplicate */

            f = e->other;
            if (f->prev) {
                f->prev->next = f->next;
            } else {
                e->end->adj = f->next;
            }
            if (f->next) {
                f->next->prev = f->prev;
            }
        } else {
            hit[e->end->num] = e;
        }
    }

    for (e = work; e; e = e->next)
        hit[e->end->num] = (CC_SRKedge *) NULL;
    n->adj = work;
}

#ifdef CC_PROTOTYPE_ANSI
int CCcut_SRK_buildgraph (CC_SRKgraph *G, int ncount, int ecount, int *elist,
        double *dlen)
#else
int CCcut_SRK_buildgraph (G, ncount, ecount, elist, dlen)
CC_SRKgraph *G;
int ncount, ecount;
int *elist;
double *dlen;
#endif
{
    int i;
    int *degree = (int *) NULL;
    int newecount = 0;
    CC_SRKnode *nodespace, *n, *n1, *n2;
    CC_SRKedge *e, *adj1, *adj2;
    CC_SRKedge **hit;

    G->nodespace = CC_SAFE_MALLOC (ncount, CC_SRKnode);
    G->hit = CC_SAFE_MALLOC (ncount, CC_SRKedge *);
    if (!G->nodespace || !G->hit) {
        fprintf (stderr, "out of memory in SRK_buildgraph\n");
        CC_IFFREE (G->nodespace, CC_SRKnode);
        CC_IFFREE (G->hit, CC_SRKedge *);
        return 1;
    }
    nodespace = G->nodespace;
    hit = G->hit;
    G->head = nodespace;
    G->original_ncount = ncount;
    G->original_ecount = ecount;

    degree = CC_SAFE_MALLOC (ncount, int);
    if (!degree) {
        fprintf (stderr, "out of memory in SRK_buildgraph\n");
        CC_IFFREE (G->nodespace, CC_SRKnode);
        CC_IFFREE (G->hit, CC_SRKedge *);
        return 1;
    }

    for (i = 0, n = nodespace; i < ncount; i++, n++) {
        n->prev = n - 1;
        n->next = n + 1;
        n->num = i;
        n->members = (CC_SRKnode *) NULL;
        n->parent = n;
        n->prweight = -2.0;
        n->weight = 0.0;
        hit[i] = (CC_SRKedge *) NULL;
        degree[i] = 0;
        n->onecnt = 0;
    }
    nodespace[0].prev = (CC_SRKnode *) NULL;
    nodespace[ncount - 1].next = (CC_SRKnode *) NULL;

    for (i = 0; i < ecount; i++) {
        if (dlen[i] > CC_SRK_ZERO_EPSILON) {
            newecount++;
            degree[elist[2*i]]++;
            degree[elist[2*i+1]]++;
        }
    }
    G->edgespace = CC_SAFE_MALLOC (2*newecount, CC_SRKedge);
    if (!G->edgespace) {
        fprintf (stderr, "out of memory in SRK_buildgraph\n");
        CC_IFFREE (G->nodespace, CC_SRKnode);
        CC_IFFREE (G->hit, CC_SRKedge *);
        return 1;
    }

    for (e = G->edgespace, i = 0; i < ncount; i++) {
        nodespace[i].adj = e;
        e += degree[i];
    }
    for (i = 0; i < ecount; i++) {
        if (dlen[i] > CC_SRK_ZERO_EPSILON) {
            n1 = nodespace + elist[2 * i];
            n2 = nodespace + elist[2 * i + 1];
            adj1 = n1->adj;
            adj2 = n2->adj;
            adj1->end = n2;
            adj1->weight = dlen[i];
            adj1->next = adj1 + 1;
            adj1->prev = adj1 - 1;
            adj1->other = adj2;
            adj2->end = n1;
            adj2->weight = dlen[i];
            adj2->next = adj2 + 1;
            adj2->prev = adj2 - 1;
            adj2->other = adj1;
            n1->adj++;
            n2->adj++;
            if (dlen[i] == 1.0) {
                n1->onecnt++;
                n2->onecnt++;
            }
        }
    }
    for (e = G->edgespace, i = 0; i < ncount; i++) {
        if (degree[i]) {
            (nodespace[i].adj - 1)->next = (CC_SRKedge *) NULL;
            nodespace[i].adj = e;
            nodespace[i].adj->prev = (CC_SRKedge *) NULL;
            e += degree[i];
        } else {
            nodespace[i].adj = (CC_SRKedge *) NULL;
        }
    }

    for (i = 0, n = nodespace; i < ncount; i++, n++) {
        for (e = n->adj; e; e = e->next) {
            n->weight += e->weight;
        }
    }

    CC_IFFREE(degree, int);
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCcut_SRK_grab_edges (CC_SRKgraph *G, int *oncount, int *oecount,
        int **olist, double **olen, CC_SRKexpinfo *expand)
#else
int CCcut_SRK_grab_edges (G, oncount, oecount, olist, olen, expand)
CC_SRKgraph *G;
int *oncount, *oecount;
int **olist;
double **olen;
CC_SRKexpinfo *expand;
#endif
{
    int rval = 0;
    int k, num;
    int ncount = 0, ecount = 0;
    CC_SRKnode *n;
    CC_SRKedge *e;

    *oncount = 0;
    *oecount = 0;
    *olist = (int *) NULL;
    *olen = (double *) NULL;
    if (expand) {
        CCcut_SRK_init_expinfo (expand);
    }

    for (n = G->head; n; n = n->next) {
        n->newnum = ncount;
        for (e = n->adj; e; e = e->next)
            ecount++;
        ncount++;
    }

    if (ecount % 2) {
        fprintf (stderr, "Error in grab_edges\n");
        rval = 1; goto CLEANUP;
    } else {
        ecount /= 2;
    }

    if (ecount == 0) {
        rval = 0; goto CLEANUP;
    }

    *olist = CC_SAFE_MALLOC (ecount * 2, int);
    *olen  = CC_SAFE_MALLOC (ecount, double);
    if (!(*olist) || !(*olen)) {
        fprintf (stderr, "out of memory in grab_edges\n");
        rval = 1; goto CLEANUP;
    }

    k = 0;
    for (n = G->head; n; n = n->next) {
        num = n->newnum;
        for (e = n->adj; e; e = e->next) {
            if (num < e->end->newnum) {
                (*olist)[2 * k] = num;
                (*olist)[2 * k + 1] = e->end->newnum;
                (*olen)[k++] = e->weight;
            }
        }
    }
    if (k != ecount) {
        fprintf (stderr, "Error in grab_edges\n");
        rval = 1; goto CLEANUP;
    }

    *oncount = ncount;
    *oecount = ecount;

    if (expand) {
        rval = CCcut_SRK_grab_nodes (G, expand);
        if (rval) {
            fprintf (stderr, "SRK_grab_nodes failed\n"); goto CLEANUP;
        }
    }

CLEANUP:

    if (rval) {
        CC_IFFREE (*olist, int);
        CC_IFFREE (*olen, double);
        if (expand) {
            CCcut_SRK_free_expinfo (expand);
        }
    }

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CCcut_SRK_grab_nodes (CC_SRKgraph *G, CC_SRKexpinfo *expand)
#else
int CCcut_SRK_grab_nodes (G, expand)
CC_SRKgraph *G;
CC_SRKexpinfo *expand;
#endif
{
    int rval = 0;
    int i;
    CC_SRKnode *n, *m;
    int total  = 0;
    int ncount = 0;

    if (!expand) {
        fprintf (stderr, "SRK_grab_nodes called without an expand struct\n");
        rval = 1; goto CLEANUP;
    }

    for (n = G->head; n; n = n->next) {
        ncount++;
    }

    CCcut_SRK_init_expinfo (expand);
    expand->members  = CC_SAFE_MALLOC (G->original_ncount, int);
    expand->memindex = CC_SAFE_MALLOC (ncount + 1, int);
    if (!(expand->members) || !(expand->memindex)) {
        fprintf (stderr, "out of memory in grab_nodes\n");
        rval = 1; goto CLEANUP;
    }
    for (n = G->head, i = 0; n; n = n->next, i++) {
        expand->memindex[i] = total;
        expand->members[total++] = n->num;
        for (m = n->members; m; m = m->members)
            expand->members[total++] = m->num;
    }
    expand->memindex[i] = total;

CLEANUP:

    if (rval) CCcut_SRK_free_expinfo (expand);
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
void CCcut_SRK_init_graph (CC_SRKgraph *G)
#else
void CCcut_SRK_init_graph (G)
CC_SRKgraph *G;
#endif
{
    if (G) {
        G->nodespace = (CC_SRKnode *) NULL;
        G->edgespace = (CC_SRKedge *) NULL;
        G->head      = (CC_SRKnode *) NULL;
        G->hit       = (CC_SRKedge **) NULL;
        G->original_ncount = 0;
        G->original_ecount = 0;
    }
}

#ifdef CC_PROTOTYPE_ANSI
void CCcut_SRK_free_graph (CC_SRKgraph *G)
#else
void CCcut_SRK_free_graph (G)
CC_SRKgraph *G;
#endif
{
    if (G) {
        CC_IFFREE (G->nodespace, CC_SRKnode);
        CC_IFFREE (G->edgespace, CC_SRKedge);
        CC_IFFREE (G->hit, CC_SRKedge *);
    }
}

#ifdef CC_PROTOTYPE_ANSI
void CCcut_SRK_init_callback (CC_SRKcallback *cb)
#else
void CCcut_SRK_init_callback (cb)
CC_SRKcallback *cb;
#endif
{
    if (cb) {
        cb->cutoff     = 0.0;
        cb->pass_param = (void *) NULL;
#ifdef CC_PROTOTYPE_ANSI
        cb->doit_fn    = (int (*) (double, int, int *, void *)) NULL;
#else
        cb->doit_fn    = (int (*) ()) NULL;
#endif
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CCcut_SRK_trivial (int ncount, CC_SRKexpinfo *expand)
#else
int CCcut_SRK_trivial (ncount, expand)
int ncount;
CC_SRKexpinfo *expand;
#endif
{
    int i;

    expand->memindex = CC_SAFE_MALLOC (ncount+1, int);
    if (!expand->memindex) {
        fprintf (stderr, "Out of memory in SRK_trivial\n");
        return -1;
    }
    expand->members = CC_SAFE_MALLOC (ncount, int);
    if (!expand->members) {
        fprintf (stderr, "Out of memory in SRK_trivial\n");
        CC_FREE (expand->memindex, int);
        return -1;
    }
    for (i=0; i<ncount; i++) {
        expand->members[i] = i;
        expand->memindex[i] = i;
    }
    expand->memindex[ncount] = ncount;
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
void CCcut_SRK_init_expinfo (CC_SRKexpinfo *expand)
#else
void CCcut_SRK_init_expinfo (expand)
CC_SRKexpinfo *expand;
#endif
{
    expand->memindex = (int *) NULL;
    expand->members = (int *) NULL;
}

#ifdef CC_PROTOTYPE_ANSI
void CCcut_SRK_free_expinfo (CC_SRKexpinfo *expand)
#else
void CCcut_SRK_free_expinfo (expand)
CC_SRKexpinfo *expand;
#endif
{
    CC_IFFREE (expand->memindex, int);
    CC_IFFREE (expand->members, int);
}

#ifdef CC_PROTOTYPE_ANSI
int CCcut_SRK_expand (CC_SRKexpinfo *expand, int *arr, int size, int **pnewarr,
        int *pnewsize)
#else
int CCcut_SRK_expand (expand, arr, size, pnewarr, pnewsize)
CC_SRKexpinfo *expand;
int *arr;
int size;
int **pnewarr;
int *pnewsize;
#endif
{
    int newsize = 0;
    int *newarr = (int *) NULL;
    int i, j, jend;

    *pnewsize = 0;
    *pnewarr = (int *) NULL;
    for (i=0; i<size; i++) {
        newsize += expand->memindex[arr[i]+1] - expand->memindex[arr[i]];
    }
    newarr = CC_SAFE_MALLOC (newsize, int);
    if (!newarr) {
        fprintf (stderr, "Out of memory in SRK_expand\n");
        return -1;
    }
    newsize = 0;
    for (i=0; i<size; i++) {
        for (j=expand->memindex[arr[i]], jend = expand->memindex[arr[i]+1];
             j < jend; j++) {
            newarr[newsize++] = expand->members[j];
        }
    }
    *pnewarr = newarr;
    *pnewsize = newsize;
    return 0;
}

#ifdef DEBUG_SHRINK
#ifdef CC_PROTOTYPE_ANSI
static void printgraph (CC_SRKgraph *G)
#else
static void printgraph (G)
CC_SRKgraph *G;
#endif
{
    CC_SRKnode *n;
    CC_SRKedge *e;

    for (n = G->head; n; n = n->next) {
        printf ("Node %d: ", n->num);
        fflush (stdout);
        for (e = n->adj; e; e = e->next) {
            printf ("%d [%.2f] ", e->end->num, e->weight);
            fflush (stdout);
            if (e->other->end != n || e->other->weight != e->weight) {
                printf ("(Whoops) ");
                fflush (stdout);
            }
        }
        printf ("\n");
    }
}
#endif
