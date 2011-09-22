#include "machdefs.h"
#include "util.h"
#include "tsp.h"

#undef  USE_INLINES
#undef  TIGHTEN_NOTIEADD
#undef  NOTIGHTEN

#define EPS (1e-6)

typedef struct tighten_node {
    struct tighten_node *next;              /* to maintain atomlist */
    struct tighten_node *prev;
    struct tighten_node **atomlist;         /* alpha(v) */
    struct qu_elem *moves;                  /* size ncliques */
    struct tighten_node *next_initialized;  /* to maintain initialized_nodes */
} tighten_node;

typedef struct qu_elem {
    double delta;
    tighten_node *v;                        /* node to move */
    int i;                                  /* clique to adjust */
    int chi;                                /* 0==outside, last del tied */
                                            /* 1==inside, 2 otherwise */
    int queue_handle;
} qu_elem;

typedef union atomfind {
    union atomfind *child[2];
    tighten_node *nodelist;                 /* A(I) in writeup */
    union atomfind *next;                   /* for freelist */
} atomfind;

typedef struct tighten_graph {
    CCtsp_lpgraph *g;
    struct tighten_node *nodes;
    double *x;
    int ncliques;
    int nhandles;
    int rhs;

    atomfind *atomtree;
    tighten_node *initialized_nodes;       /* Vstar in writeup */
    CCpriority queue;
} tighten_graph;

#define NODE_IN_SINGLETON(v) ((v)->atomlist && (*((v)->atomlist))       \
                              && (!(*((v)->atomlist))->next))

#ifdef CC_PROTOTYPE_ANSI

static void
    add_to_atom (tighten_node *v),
    delete_from_atom (tighten_node *v),
    cleanup_atomfinder (atomfind *tree, int depth),
    cleanup_graph (tighten_graph *tg);

static int
    update_queue (CCpriority *q, qu_elem *qe),
    initialize_graph (CCtsp_lpgraph *g, double *x, tighten_graph *tg),
    initialize_lpcut_in (tighten_graph *tg, CCtsp_lpcut_in *c),
    initialize_lpcut (tighten_graph *tg, CCtsp_lpclique *cliques,
        CCtsp_lpcut *c),
    initialize_node (tighten_graph *tg, tighten_node *v, int add_atom),
    process_qu_elem (tighten_graph *tg, qu_elem *q),
    process_qu_elem_atom (tighten_graph *tg, tighten_node *v),
    process_qu_elem_delta (tighten_graph *tg, qu_elem *q),
    collect_new_cut (tighten_graph *tg, CCtsp_lpcut_in *cout),
    tighten_cut (tighten_graph *tg, CCtsp_tighten_info *stats,
        double *pimprove);

static tighten_node
  **find_atomlist (tighten_graph *tg, tighten_node *v, int add);

#ifndef USE_INLINES
static double
    qu_elem_key (qu_elem *q);
static int
    qu_elem_is_active (qu_elem *q);
#endif

#else /* CC_PROTOTYPE_ANSI */

static void
    add_to_atom (),
    delete_from_atom (),
    cleanup_atomfinder (),
    cleanup_graph ();

static int
    update_queue (),
    initialize_graph (),
    initialize_lpcut_in (),
    initialize_lpcut (),
    initialize_node (),
    process_qu_elem (),
    process_qu_elem_atom (),
    process_qu_elem_delta (),
    collect_new_cut (),
    tighten_cut ();

static tighten_node
  **find_atomlist ();

#ifndef USE_INLINES
static double
    qu_elem_key ();
static int
    qu_elem_is_active ();
#endif

#endif /* CC_PROTOTYPE_ANSI */

CC_PTR_ALLOC_ROUTINE (atomfind, atomfind_alloc, chunklist, atomfind_freelist)
CC_PTR_FREE_ROUTINE (atomfind, atomfind_free, atomfind_freelist)
CC_PTR_FREE_WORLD_ROUTINE (atomfind, atomfind_freeworld, chunklist,
        atomfind_freelist)
CC_PTR_LEAKS_ROUTINE (atomfind, atomfind_leaks, chunklist, atomfind_freelist,
        child[1], atomfind *)

#ifdef USE_INLINES

#define qu_elem_key(q) (((q)->delta > EPS) ? (-(3.0 + (q)->delta))        \
                                         : (-((q)->chi + (q)->delta)))
#ifdef TIGHTEN_NOTIEADD
#define qu_elem_is_active(q) ((!NODE_IN_SINGLETON((q)->v))                \
                            && ((q)->delta > EPS                          \
                                || ((q)->delta >= 0.0 && (q)->chi == 1)))
#else
#define qu_elem_is_active(q) ((!NODE_IN_SINGLETON((q)->v))                \
                            && ((q)->delta > EPS                          \
                                || ((q)->delta >= 0.0 && (q)->chi > 0)))
#endif

#else /* USE_INLINES */

#ifdef CC_PROTOTYPE_ANSI
static double qu_elem_key (qu_elem *q)
#else
static double qu_elem_key (q)
qu_elem *q;
#endif
{
    double key;

    if (q->delta > EPS) {
        key = 3.0 + q->delta;
    } else {
        key = q->chi + q->delta;
    }
    return -key;
}

#ifdef CC_PROTOTYPE_ANSI
static int qu_elem_is_active (qu_elem *q)
#else
static int qu_elem_is_active (q)
qu_elem *q;
#endif
{
#ifdef TIGHTEN_NOTIEADD
    return ((!NODE_IN_SINGLETON(q->v))
            && ((q->delta > EPS)
                || ((q)->delta >= 0.0 && (q)->chi == 1)));
#else
    return ((!NODE_IN_SINGLETON(q->v))
            && ((q->delta > EPS)
                || ((q)->delta >= 0.0 && (q)->chi > 0)));
#endif
}

#endif

#ifdef CC_PROTOTYPE_ANSI
static void add_to_atom (tighten_node *v)
#else
static void add_to_atom (v)
tighten_node *v;
#endif
{
    if (v->atomlist) {
        v->next = *(v->atomlist);
        if (v->next) v->next->prev = v;
        v->prev = (tighten_node *) NULL;
        *(v->atomlist) = v;
    } else {
        v->next = (tighten_node *) NULL;
        v->prev = (tighten_node *) NULL;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void delete_from_atom (tighten_node *v)
#else
static void delete_from_atom (v)
tighten_node *v;
#endif
{
    if (v->next) v->next->prev = v->prev;
    if (v->prev) v->prev->next = v->next;
    else if (v->atomlist) *(v->atomlist) = v->next;
}

#ifdef CC_PROTOTYPE_ANSI
static int update_queue (CCpriority *q, qu_elem *qe)
#else
static int update_queue (q, qe)
CCpriority *q;
qu_elem *qe;
#endif
{
    double newkey;
    int handle;

    if (qu_elem_is_active (qe)) {
        newkey = qu_elem_key (qe);
        if (qe->queue_handle >= 0) {
            CCutil_priority_changekey (q, qe->queue_handle, newkey);
        } else {
            handle = CCutil_priority_insert (q, (void *) qe, newkey);
            if (handle < 0) {
                return handle;
            }
            qe->queue_handle = handle;
        }
    } else {
        if (qe->queue_handle >= 0) {
            CCutil_priority_delete (q, qe->queue_handle);
            qe->queue_handle = -1;
        }
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static tighten_node **find_atomlist (tighten_graph *tg, tighten_node *v,
        int add)
#else
static tighten_node **find_atomlist (tg, v, add)
tighten_graph *tg;
tighten_node *v;
int add;
#endif
{
    atomfind *f = tg->atomtree;
    atomfind **pf = &(tg->atomtree);
    int i;
    int dir;

    for (i=0; i<tg->ncliques; i++) {
        if (!f) {
            if (add) {
                (*pf) = f = atomfind_alloc();
                if (!f) return (tighten_node **) NULL;
                f->child[0] = (atomfind *) NULL;
                f->child[1] = (atomfind *) NULL;
            } else {
                return (tighten_node **) NULL;
            }
        }

        dir = v->moves[i].chi & 1;
        pf = &(f->child[dir]);
        f = f->child[dir];
    }
    if (!f) {
        if (add) {
            (*pf) = f = atomfind_alloc();
            if (!f) return (tighten_node **) NULL;
            f->nodelist = (tighten_node *) NULL;
        } else {
            return (tighten_node **) NULL;
        }
    }

    return &(f->nodelist);
}

#ifdef CC_PROTOTYPE_ANSI
static void cleanup_atomfinder (atomfind *tree, int depth)
#else
static void cleanup_atomfinder (tree, depth)
atomfind *tree;
int depth;
#endif
{
    if (depth > 0) {
        if (tree->child[0]) {
            cleanup_atomfinder (tree->child[0], depth-1);
        }
        if (tree->child[1]) {
            cleanup_atomfinder (tree->child[1], depth-1);
        }
    }
    atomfind_free (tree);
}

#ifdef CC_PROTOTYPE_ANSI
static int initialize_graph (CCtsp_lpgraph *g, double *x, tighten_graph *tg)
#else
static int initialize_graph (g, x, tg)
CCtsp_lpgraph *g;
double *x;
tighten_graph *tg;
#endif
{
    int rval;

    tg->g = g;
    tg->x = x;

    tg->nodes = (tighten_node *) CC_SAFE_MALLOC (g->ncount, tighten_node);
    if (!tg->nodes) return -1;

    rval = CCutil_priority_init (&tg->queue, 1000);
    if (rval) {
        CC_FREE (tg->nodes, tighten_node);
        return rval;
    }

    tg->initialized_nodes = (tighten_node *) NULL;
    tg->atomtree = (atomfind *) NULL;
    tg->ncliques = 0;
    g->nodemarker++;

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int initialize_lpcut_in (tighten_graph *tg, CCtsp_lpcut_in *c)
#else
static int initialize_lpcut_in (tg, c)
tighten_graph *tg;
CCtsp_lpcut_in *c;
#endif
{
    int i,j,k,l,m;
    CCtsp_lpgraph *g = tg->g;
    CCtsp_lpclique *cl;
    tighten_node *v;
    int rval;

    tg->ncliques = c->cliquecount;
    tg->nhandles = c->handlecount;
    tg->rhs = c->rhs;
    for (i=0; i<tg->ncliques; i++) {
        cl = &(c->cliques[i]);
        for (j=0; j<cl->segcount; j++) {
            for (k=cl->nodes[j].lo; k<=cl->nodes[j].hi; k++) {
                if (g->nodes[k].mark < g->nodemarker) {
                    rval = initialize_node (tg, &(tg->nodes[k]), 0);
                    if (rval) return rval;
                }
                tg->nodes[k].moves[i].chi = 1;
                for (l=0; l<g->nodes[k].deg; l++) {
                    m = g->nodes[k].adj[l].to;
                    if (g->nodes[m].mark < g->nodemarker) {
                        rval = initialize_node (tg, &(tg->nodes[m]), 0);
                        if (rval) return rval;
                    }
                }
            }
        }
    }

    for (v = tg->initialized_nodes; v; v = v->next_initialized) {
        v->atomlist = find_atomlist (tg, v, 1);
        if (!v->atomlist) {
            return -1;
        }
        add_to_atom (v);
    }

    for (v = tg->initialized_nodes; v; v = v->next_initialized) {
        k = v - tg->nodes;
        for (l=0; l<g->nodes[k].deg; l++) {
            m = g->nodes[k].adj[l].to;
            if (g->nodes[m].mark == g->nodemarker) {
                for (i=0; i<tg->ncliques; i++) {
                    if (v->moves[i].chi != tg->nodes[m].moves[i].chi) {
                        v->moves[i].delta += tg->x[g->nodes[k].adj[l].edge];
                    }
                }
            }
        }
        for (i=0; i<tg->ncliques; i++) {
            rval = update_queue (&tg->queue, &v->moves[i]);
            if (rval) return rval;
        }
    }

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int initialize_lpcut (tighten_graph *tg, CCtsp_lpclique *cliques,
        CCtsp_lpcut *c)
#else
static int initialize_lpcut (tg, cliques, c)
tighten_graph *tg;
CCtsp_lpclique *cliques;
CCtsp_lpcut *c;
#endif
{
    int i,j,k,l,m;
    CCtsp_lpgraph *g = tg->g;
    CCtsp_lpclique *cl;
    tighten_node *v;
    int rval;

    tg->ncliques = c->cliquecount;
    tg->nhandles = c->handlecount;
    tg->rhs = c->rhs;
    for (i=0; i<tg->ncliques; i++) {
        cl = &cliques[c->cliques[i]];
        for (j=0; j<cl->segcount; j++) {
            for (k=cl->nodes[j].lo; k<=cl->nodes[j].hi; k++) {
                if (g->nodes[k].mark < g->nodemarker) {
                    rval = initialize_node (tg, &(tg->nodes[k]), 0);
                    if (rval) return rval;
                }
                tg->nodes[k].moves[i].chi = 1;
                for (l=0; l<g->nodes[k].deg; l++) {
                    m = g->nodes[k].adj[l].to;
                    if (g->nodes[m].mark < g->nodemarker) {
                        rval = initialize_node (tg, &(tg->nodes[m]), 0);
                        if (rval) return rval;
                    }
                }
            }
        }
    }

    for (v = tg->initialized_nodes; v; v = v->next_initialized) {
        v->atomlist = find_atomlist (tg, v, 1);
        if (!v->atomlist) {
            return -1;
        }
        add_to_atom (v);
    }

    for (v = tg->initialized_nodes; v; v = v->next_initialized) {
        k = v - tg->nodes;
        for (l=0; l<g->nodes[k].deg; l++) {
            m = g->nodes[k].adj[l].to;
            if (g->nodes[m].mark == g->nodemarker) {
                for (i=0; i<tg->ncliques; i++) {
                    if (v->moves[i].chi != tg->nodes[m].moves[i].chi) {
                        v->moves[i].delta += tg->x[g->nodes[k].adj[l].edge];
                    }
                }
            }
        }
        for (i=0; i<tg->ncliques; i++) {
            rval = update_queue (&tg->queue, &v->moves[i]);
            if (rval) return rval;
        }
    }

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int initialize_node (tighten_graph *tg, tighten_node *v, int add_atom)
#else
static int initialize_node (tg, v, add_atom)
tighten_graph *tg;
tighten_node *v;
int add_atom;
#endif
{
    int i;

    v->moves = CC_SAFE_MALLOC (tg->ncliques, qu_elem);
    if (!v->moves) return -1;

    for (i=0; i<tg->ncliques; i++) {
        v->moves[i].v = v;
        v->moves[i].i = i;
        v->moves[i].delta = -1.0;
        v->moves[i].chi = 2;
        v->moves[i].queue_handle = -1;
    }
    if (add_atom) {
        v->atomlist = find_atomlist (tg, v, 0);
        if (v->atomlist) {
            add_to_atom (v);
        }
    } else {
        v->atomlist = (tighten_node **) NULL;
    }

    v->next_initialized = tg->initialized_nodes;
    tg->initialized_nodes = v;

    tg->g->nodes[v - tg->nodes].mark = tg->g->nodemarker;

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int process_qu_elem (tighten_graph *tg, qu_elem *q)
#else
static int process_qu_elem (tg, q)
tighten_graph *tg;
qu_elem *q;
#endif
{
    int rval;

    if (q->chi == 1) {
        if (q->delta <= EPS) {
            q->chi = 0;
        } else {
            q->chi = 2;
        }
    } else {
        q->chi = 1;
    }
    rval = process_qu_elem_atom (tg, q->v);
    if (rval) return rval;
    rval = process_qu_elem_delta (tg, q);
    if (rval) return rval;
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int process_qu_elem_atom (tighten_graph *tg, tighten_node *v)
#else
static int process_qu_elem_atom (tg, v)
tighten_graph *tg;
tighten_node *v;
#endif
{
    tighten_node *w;
    int j;
    int rval;

    if (v->atomlist) {
        delete_from_atom (v);

        if (NODE_IN_SINGLETON(v)) {
            w = *(v->atomlist);
            for (j=0; j<tg->ncliques; j++) {
                rval = update_queue (&tg->queue, &w->moves[j]);
                if (rval) return rval;
            }
        }
    }

    /* chi was updated before the call */
    v->atomlist = find_atomlist (tg, v, 0);

    if (v->atomlist) {
        w = *(v->atomlist);

        add_to_atom (v);

        if (w->next == (tighten_node *) NULL) {
            /* v->atomlist was the singleton w */
            for (j=0; j<tg->ncliques; j++) {
                rval = update_queue (&tg->queue, &w->moves[j]);
                if (rval) return rval;
            }
        }
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int process_qu_elem_delta (tighten_graph *tg, qu_elem *q)
#else
static int process_qu_elem_delta (tg, q)
tighten_graph *tg;
qu_elem *q;
#endif
{
    tighten_node *v = q->v;
    int i = q->i;
    tighten_node *w;
    int j;
    CCtsp_lpgraph *g = tg->g;
    int nv = v - tg->nodes;
    int nw;
    int e;
    int rval;

    v->moves[i].delta = -v->moves[i].delta;
    rval = update_queue (&tg->queue, &v->moves[i]);
    if (rval) return rval;

    for (j=0; j<g->nodes[nv].deg; j++) {
        nw = g->nodes[nv].adj[j].to;
        e = g->nodes[nv].adj[j].edge;
        w = &tg->nodes[nw];
        if (g->nodes[nw].mark < g->nodemarker) {
            rval = initialize_node (tg, w, 1);
            if (rval) return rval;
        }

        if ((v->moves[i].chi & 1) == (w->moves[i].chi & 1)) {
            w->moves[i].delta -= tg->x[e];
        } else {
            w->moves[i].delta += tg->x[e];
        }
        rval = update_queue (&tg->queue, &w->moves[i]);
        if (rval) return rval;
    }

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static void cleanup_graph (tighten_graph *tg)
#else
static void cleanup_graph (tg)
tighten_graph *tg;
#endif
{
    tighten_node *v, *vnext;

    for (v = tg->initialized_nodes; v; v = vnext) {
        vnext = v->next_initialized;
        CC_FREE (v->moves, qu_elem);
    }
    cleanup_atomfinder (tg->atomtree, tg->ncliques);

#if 0
    {
        int total, onlist, leak;
        if ((leak = atomfind_leaks(&total, &onlist))) {
            fprintf (stderr, "TIGHTEN leaked %d atomfind's (total %d onlist %d)\n",
                     leak, total, onlist);
        }
    }
#endif

    atomfind_freeworld();

    CCutil_priority_free (&tg->queue);

    CC_FREE (tg->nodes, tighten_node);
}

#ifdef CC_PROTOTYPE_ANSI
static int collect_lpclique (tighten_graph *tg, int cnum, CCtsp_lpclique *c)
#else
static int collect_lpclique (tg, cnum, c)
tighten_graph *tg;
int cnum;
CCtsp_lpclique *c;
#endif
{
    tighten_node *v;
    int cnt;
    int *arr;
    int rval;

    cnt = 0;
    for (v = tg->initialized_nodes; v; v = v->next_initialized) {
        if (v->moves[cnum].chi == 1) cnt++;
    }
    arr = CC_SAFE_MALLOC (cnt, int);
    if (!arr) return -1;

    cnt = 0;
    for (v = tg->initialized_nodes; v; v = v->next_initialized) {
        if (v->moves[cnum].chi == 1) {
            arr[cnt++] = v - tg->nodes;
        }
    }

    rval = CCtsp_array_to_lpclique (arr, cnt, c);
    CC_FREE (arr, int);
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static int collect_new_cut (tighten_graph *tg, CCtsp_lpcut_in *cout)
#else
static int collect_new_cut (tg, cout)
tighten_graph *tg;
CCtsp_lpcut_in *cout;
#endif
{
    int i, j;
    int rval;

    cout->handlecount = tg->nhandles;
    cout->cliquecount = tg->ncliques;
    cout->rhs = tg->rhs;
    cout->cliques = CC_SAFE_MALLOC (tg->ncliques, CCtsp_lpclique);
    if (!cout->cliques) {
        return -1;
    }

    for (i=0; i<tg->ncliques; i++) {
        rval = collect_lpclique (tg, i, &(cout->cliques[i]));
        if (rval) {
            for (j=0; j<i; j++) {
                CC_FREE (cout->cliques[i].nodes, CCtsp_segment);
            }
            CC_FREE (cout->cliques, CCtsp_lpclique);
            return rval;
        }
    }

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int tighten_cut (tighten_graph *tg, CCtsp_tighten_info *stats,
        double *pimprove)
#else
static int tighten_cut (tg, stats, pimprove)
tighten_graph *tg;
CCtsp_tighten_info *stats;
double *pimprove;
#endif
{
    qu_elem *q;
    int rval;
    double improve = 0.0;

    while ((q = (qu_elem *) CCutil_priority_deletemin (&tg->queue,
                                                       (double *) NULL))) {
        if (q->v->moves[q->i].chi == 1) {
            stats->ndel++;
            stats->del_delta += q->delta;
            if (q->delta <= EPS) stats->ndel_tied++;
        } else {
            stats->nadd++;
            stats->add_delta += q->delta;
            if (q->delta <= EPS) stats->nadd_tied++;
        }
        improve += q->delta;
        q->queue_handle = -1;
        rval = process_qu_elem (tg, q);
        if (rval) return rval;
    }
    if (pimprove) *pimprove = improve;
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_tighten_lpcut_in (CCtsp_lpgraph *g, CCtsp_lpcut_in *c, double *x,
        CCtsp_lpcut_in *cout, CCtsp_tighten_info *stats, double *pimprove)
#else
int CCtsp_tighten_lpcut_in (g, c, x, cout, stats, pimprove)
CCtsp_lpgraph *g;
CCtsp_lpcut_in *c;
double *x;
CCtsp_lpcut_in *cout;
CCtsp_tighten_info *stats;
double *pimprove;
#endif
{
    tighten_graph tg;
    int rval = 0;
    double szeit = CCutil_zeit ();

    if (c->branch != 0) {
        fprintf (stderr, "try to tighten a branch cut\n"); return 1;
    }
    if (c->sense != 'G') {
        fprintf (stderr, "try to tighten a <= cut\n"); return 1;
    }

    rval = initialize_graph (g, x, &tg);
    if (rval) return rval;

    rval = initialize_lpcut_in (&tg, c);
    if (rval) goto CLEANUP;

#ifndef NOTIGHTEN
    rval = tighten_cut (&tg, stats, pimprove);
    if (rval) goto CLEANUP;
#endif

    rval = collect_new_cut (&tg, cout);
    if (rval) goto CLEANUP;

    cout->branch = c->branch;
    cout->sense  = c->sense;

CLEANUP:

    stats->ncall++;
    if (rval) stats->nfail++;
    stats->time += CCutil_zeit () - szeit;
    cleanup_graph (&tg);
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_tighten_lpcut (CCtsp_lpgraph *g, CCtsp_lpclique *cliques,
        CCtsp_lpcut *c, double *x, CCtsp_lpcut_in *cout,
        CCtsp_tighten_info *stats, double *pimprove)
#else
int CCtsp_tighten_lpcut (g, cliques, c, x, cout, stats, pimprove)
CCtsp_lpgraph *g;
CCtsp_lpclique *cliques;
CCtsp_lpcut *c;
double *x;
CCtsp_lpcut_in *cout;
CCtsp_tighten_info *stats;
double *pimprove;
#endif
{
    tighten_graph tg;
    int rval = 0;
    double szeit = CCutil_zeit ();

    if (c->branch != 0) {
        fprintf (stderr, "try to tighten a branch cut\n"); return 1;
    }
    if (c->sense != 'G') {
        fprintf (stderr, "try to tighten a <= cut\n"); return 1;
    }

    rval = initialize_graph (g, x, &tg);
    if (rval) return rval;

    rval = initialize_lpcut (&tg, cliques, c);
    if (rval) goto CLEANUP;

    rval = tighten_cut (&tg, stats, pimprove);
    if (rval) goto CLEANUP;

    rval = collect_new_cut (&tg, cout);
    if (rval) goto CLEANUP;

    cout->branch = c->branch;
    cout->sense  = c->sense;

CLEANUP:

    stats->ncall++;
    if (rval) stats->nfail++;
    stats->time += CCutil_zeit () - szeit;
    cleanup_graph (&tg);
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
void CCtsp_init_tighten_info (CCtsp_tighten_info *stats)
#else
void CCtsp_init_tighten_info (stats)
CCtsp_tighten_info *stats;
#endif
{
    stats->ncall = 0;
    stats->nfail = 0;
    stats->nadd = 0;
    stats->nadd_tied = 0;
    stats->ndel = 0;
    stats->ndel_tied = 0;
    stats->add_delta = 0.0;
    stats->del_delta = 0.0;
    stats->time = 0.0;
}

#ifdef CC_PROTOTYPE_ANSI
void CCtsp_print_tighten_info (CCtsp_tighten_info *stats)
#else
void CCtsp_print_tighten_info (stats)
CCtsp_tighten_info *stats;
#endif
{
    printf ("TIGHTEN STATS: %d calls (%d failed), %.2f improvement, %.2f seconds\n",
            stats->ncall, stats->nfail, stats->add_delta + stats->del_delta,
            stats->time);
    printf ("               %d adds, %d tied, %.2f improvement\n",
            stats->nadd, stats->nadd_tied, stats->add_delta);
    printf ("               %d dels, %d tied, %.2f improvement\n",
            stats->ndel, stats->ndel_tied, stats->del_delta);
    fflush (stdout);
}
