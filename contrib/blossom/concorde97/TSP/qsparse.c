/***************************************************************************/
/*                                                                         */
/*   Function to Reduce the Number of Nonzeros in a Cut by add/sub Stars   */
/*                                                                         */
/*                           TSP CODE                                      */
/*                                                                         */
/*                                                                         */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook                       */
/*  Date: October 7, 1995                                                  */
/*                                                                         */
/*                                                                         */
/*  EXPORTED FUNCTIONS:                                                    */
/*    int CCtsp_qsparsify (CCtsp_qsparsegroup **pqs, CCtsp_lpgraph *g,     */
/*            int *pnzlist, int scount, CCtsp_sparser **slist,             */
/*            int *savedcount)                                             */
/*        -pqs (if *pqs is NULL, then it will be initialized)              */
/*        -g (the graph)                                                   */
/*        -pnzlist (pointer to an int that is the start of a linked list   */
/*           of edges that is a superset of the nonzeros in the cut, it    */
/*           returns a pointer to a superset of the nonzeros in the        */
/*           sparsified cut. The links are via the coefnext field of       */
/*           CCtsp_lpedge, and the coef field gives the actual nonzero     */
/*           coefs.)                                                       */
/*        -scount (returns the number of CCtsp_sparsers in slist)          */
/*        -slist (rturns an array of CCtsp_sparsers)                       */
/*        -savedcount (returns the number of nonzeros that were saved)     */
/*      RETURNS 0 is it worked and 1 if it failed (probably due to running */
/*      out of memory). free_qsparsify will free the allocated memory (it  */
/*      is not freed after each call since the mallocs and initialization  */
/*      require too much time).                                            */
/*    void CCtsp_free_qsparsify (CCtsp_qsparsegroup **pqs)                 */
/*        -pqs (will free the queues and arrays in the struct pointed to   */
/*             by *pqs, and sets *pqs to NULL)                             */
/*                                                                         */
/*  NOTES:                                                                 */
/*      This functions uses priorty queues to line up the stars that would */
/*    decrease the number of nonzeros if they were added or subtracted     */
/*    there are separate add and subtract queues).                         */
/*                                                                         */
/***************************************************************************/

#include "machdefs.h"
#include "util.h"
#include "tsp.h"

#ifdef CC_PROTOTYPE_ANSI

static void
    queue_add (CCdheap *q, int v, int k),
    queue_delete (CCdheap *q, int v),
    queue_keychange (CCdheap *q, int v, int k),
    add_node(int v, CCtsp_qsparsegroup *qs, CCtsp_lpgraph *g, int *pnzlist),
    sub_node(int v, CCtsp_qsparsegroup *qs, CCtsp_lpgraph *g, int *pnzlist),
    update_queues (int v, CCtsp_qsparsegroup *qs, CCtsp_lpgraph *g);

static int
    init_qsparsify (CCtsp_qsparsegroup **pqs, int ncount),
    queue_max (CCdheap *);

#else

static void
    queue_add (),
    queue_delete (),
    queue_keychange (),
    add_node(),
    sub_node(),
    update_queues ();

static int
    init_qsparsify (),
    queue_max ();

#endif


#ifdef CC_PROTOTYPE_ANSI
static int init_qsparsify (CCtsp_qsparsegroup **pqs, int ncount)
#else
static int init_qsparsify (pqs, ncount)
CCtsp_qsparsegroup **pqs;
int ncount;
#endif
{
    int i;
    CCtsp_qsparsegroup *qs;

    (*pqs) = CC_SAFE_MALLOC (1, CCtsp_qsparsegroup);
    if (!(*pqs))
        return 1;

    qs = *pqs;
    qs->add_queue = (CCdheap *) NULL;
    qs->sub_queue = (CCdheap *) NULL;
    qs->count_m1 = (int *) NULL;
    qs->count_non0 = (int *) NULL;
    qs->count_1 = (int *) NULL;
    qs->on_add_queue = (int *) NULL;
    qs->on_sub_queue = (int *) NULL;
    qs->mults = (int *) NULL;

    qs->add_queue = CC_SAFE_MALLOC (1, CCdheap);
    qs->sub_queue = CC_SAFE_MALLOC (1, CCdheap);
    if (!qs->add_queue || !qs->sub_queue) {
        CCtsp_free_qsparsify (pqs);
        return 1;
    }
    if (CCutil_dheap_init (qs->add_queue, ncount)) {
        CCtsp_free_qsparsify (pqs);
        return 1;
    }
    if (CCutil_dheap_init (qs->sub_queue, ncount)) {
        CCtsp_free_qsparsify (pqs);
        return 1;
    }

    qs->count_m1 = CC_SAFE_MALLOC (ncount, int);
    qs->count_non0 = CC_SAFE_MALLOC (ncount, int);
    qs->count_1 = CC_SAFE_MALLOC (ncount, int);
    qs->on_add_queue = CC_SAFE_MALLOC (ncount, int);
    qs->on_sub_queue = CC_SAFE_MALLOC (ncount, int);
    qs->mults = CC_SAFE_MALLOC (ncount, int);
    if (!qs->count_m1 || !qs->count_non0 || !qs->count_1 ||
        !qs->on_add_queue || !qs->on_sub_queue || !qs->mults) {
        CCtsp_free_qsparsify (pqs);
        return 1;
    }

    for (i = 0; i < ncount; i++) {
        qs->count_m1[i] = 0;
        qs->count_non0[i] = 0;
        qs->count_1[i] = 0;
        qs->on_add_queue[i] = 0;
        qs->on_sub_queue[i] = 0;
        qs->mults[i] = 0;
    }

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
void CCtsp_free_qsparsify (CCtsp_qsparsegroup **pqs)
#else
void CCtsp_free_qsparsify (pqs)
CCtsp_qsparsegroup **pqs;
#endif
{
    if (*pqs != (CCtsp_qsparsegroup *) NULL) {
        if ((*pqs)->add_queue) {
            CCutil_dheap_free ((*pqs)->add_queue);
            CC_FREE ((*pqs)->add_queue, CCdheap);
        }
        if ((*pqs)->sub_queue) {
            CCutil_dheap_free ((*pqs)->sub_queue);
            CC_FREE ((*pqs)->sub_queue, CCdheap);
        }
        CC_IFFREE ((*pqs)->count_m1, int);
        CC_IFFREE ((*pqs)->count_non0, int);
        CC_IFFREE ((*pqs)->count_1, int);
        CC_IFFREE ((*pqs)->on_add_queue, int);
        CC_IFFREE ((*pqs)->on_sub_queue, int);
        CC_IFFREE ((*pqs)->mults, int);
        CC_FREE (*pqs, CCtsp_qsparsegroup);
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_qsparsify (CCtsp_qsparsegroup **pqs, CCtsp_lpgraph *g, int *pnzlist,
        int *scount, CCtsp_sparser **slist, int *savedcount)
#else
int CCtsp_qsparsify (pqs, g, pnzlist, scount, slist,  savedcount)
CCtsp_qsparsegroup **pqs;
CCtsp_lpgraph *g;
int *pnzlist;
int *scount;
CCtsp_sparser **slist;
int *savedcount;
#endif
{
    int i, k, e, t;
    int v, w;
    CCtsp_qsparsegroup *qs;
    int *count_non0, *count_1, *count_m1;
    CCtsp_lpedge *edges = g->edges;
    CCtsp_lpnode *nodes = g->nodes;

    *scount = 0;
    *slist = (CCtsp_sparser *) NULL;
    *savedcount = 0;
    if (*pnzlist == -1)
        return 0;

    if (*pqs == (CCtsp_qsparsegroup *) NULL) {
        if (init_qsparsify(pqs, g->ncount))
            return 1;
    }

    qs = *pqs;
    count_non0 = qs->count_non0;
    count_1 = qs->count_1;
    count_m1 = qs->count_m1;

    for (e = *pnzlist; e != -1; e = g->edges[e].coefnext) {
        if (edges[e].coef) {
            count_non0[edges[e].ends[0]]++;
            count_non0[edges[e].ends[1]]++;
            if (edges[e].coef == 1) {
                count_1[edges[e].ends[0]]++;
                count_1[edges[e].ends[1]]++;
            } else if (edges[e].coef == -1) {
                count_m1[edges[e].ends[0]]++;
                count_m1[edges[e].ends[1]]++;
            }
        }
    }

    g->nodemarker++;
    for (e = *pnzlist; e != -1; e = edges[e].coefnext) {
        if (edges[e].coef) {
            if (nodes[edges[e].ends[0]].mark != g->nodemarker) {
                update_queues(edges[e].ends[0], qs, g);
                nodes[edges[e].ends[0]].mark = g->nodemarker;
            }
            if (nodes[edges[e].ends[1]].mark != g->nodemarker) {
                update_queues(edges[e].ends[1], qs, g);
                nodes[edges[e].ends[1]].mark = g->nodemarker;
            }
        }
    }

    k = 0;
    for (;;) {
        v = queue_max (qs->add_queue);
        w = queue_max (qs->sub_queue);
        if (v == -1 && w == -1) break;
        if (w == -1 || (v != -1 &&
            count_m1[v] - (nodes[v].deg - count_non0[v]) >
                     count_1[w] - (nodes[w].deg - count_non0[w]))) {
            k += (count_m1[v] - (nodes[v].deg - count_non0[v]));
            queue_delete (qs->add_queue, v);
            qs->on_add_queue[v] = 0;
            (qs->mults[v])++;
            add_node (v, qs, g, pnzlist);
        } else {
            k += (count_1[w] - (nodes[w].deg - count_non0[w]));
            queue_delete (qs->sub_queue, w);
            qs->on_sub_queue[w] = 0;
            (qs->mults[w])--;
            sub_node (w, qs, g, pnzlist);
        }
    }


    g->nodemarker++;
    for (e = *pnzlist; e != -1; e = edges[e].coefnext) {
        if (qs->mults[edges[e].ends[0]] &&
                nodes[edges[e].ends[0]].mark != g->nodemarker) {
            (*scount)++;
            nodes[edges[e].ends[0]].mark = g->nodemarker;
        }
        if (qs->mults[edges[e].ends[1]] &&
                nodes[edges[e].ends[1]].mark != g->nodemarker) {
            (*scount)++;
            nodes[edges[e].ends[1]].mark = g->nodemarker;
        }
    }
    if (*scount) {
        *slist = CC_SAFE_MALLOC (*scount, CCtsp_sparser);
        if (!(*slist)) {
            CCtsp_free_qsparsify (pqs);
            *scount = 0;
            *savedcount = 0;
            return 1;
        }
        i = 0;
        for (e = *pnzlist; e != -1; e = edges[e].coefnext) {
            if (qs->mults[edges[e].ends[0]]) {
                (*slist)[i].node = (unsigned int) edges[e].ends[0];
                t = qs->mults[edges[e].ends[0]];
                if (t > 0)
                    (*slist)[i++].mult = (unsigned int) (128 + (t % 128));
                else
                    (*slist)[i++].mult = (unsigned int) (128 - ((-t) % 128));
                qs->mults[edges[e].ends[0]] = 0;
            }
            if (qs->mults[edges[e].ends[1]]) {
                (*slist)[i].node = (unsigned int) edges[e].ends[1];
                t = qs->mults[edges[e].ends[1]];
                if (t > 0)
                    (*slist)[i++].mult = (unsigned int) (128 + (t % 128));
                else
                    (*slist)[i++].mult = (unsigned int) (128 - ((-t) % 128));
                qs->mults[edges[e].ends[1]] = 0;
            }
        }
    }


    for (e = *pnzlist; e != -1; e = g->edges[e].coefnext) {
        qs->count_m1[edges[e].ends[0]] = 0;
        qs->count_non0[edges[e].ends[0]] = 0;
        qs->count_1[edges[e].ends[0]] = 0;
        qs->count_m1[edges[e].ends[1]] = 0;
        qs->count_non0[edges[e].ends[1]] = 0;
        qs->count_1[edges[e].ends[1]] = 0;
    }

    *savedcount = k;

/*
    printf ("sscount = %d  savedcount = %d\n", *scount, *savedcount);
    fflush (stdout);
*/

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static void queue_add (CCdheap *q, int v, int k)
#else
static void queue_add (q, v, k)
CCdheap *q;
int v;
int k;
#endif
{
    /* adds v to q with key k */
    q->key[v] = -k;  /* since dheap code works with min, not max */
    CCutil_dheap_insert (q, v);
}

#ifdef CC_PROTOTYPE_ANSI
static void queue_delete (CCdheap *q, int v)
#else
static void queue_delete (q, v)
CCdheap *q;
int v;
#endif
{
    /* deletes v from q */
    CCutil_dheap_delete (q, v);
}

#ifdef CC_PROTOTYPE_ANSI
static void queue_keychange (CCdheap *q, int v, int k)
#else
static void queue_keychange (q, v, k)
CCdheap *q;
int v;
int k;
#endif
{
    /* changes v's key to k on q */
    CCutil_dheap_changekey (q, v, (double) -k);
}

#ifdef CC_PROTOTYPE_ANSI
static int queue_max (CCdheap *q)
#else
static int queue_max (q)
CCdheap *q;
#endif
{
    /* returns the node on q with the largest key */
    return CCutil_dheap_findmin (q);
}

#ifdef CC_PROTOTYPE_ANSI
static void add_node (int v, CCtsp_qsparsegroup *qs, CCtsp_lpgraph *g,
        int *pnzlist)
#else
static void add_node (v, qs, g, pnzlist)
int v;
CCtsp_qsparsegroup *qs;
CCtsp_lpgraph *g;
int *pnzlist;
#endif
{
    int j, w;
    CCtsp_lpnode *lv = &(g->nodes[v]);
    CCtsp_lpedge *e;

    for (j = lv->deg - 1; j >= 0; j--) {
        e = &(g->edges[lv->adj[j].edge]);
        w = lv->adj[j].to;
        if (e->coef == 0) {
            if (e->coefnext == -2) {
                e->coefnext = *pnzlist;
                *pnzlist = lv->adj[j].edge;
            }
            qs->count_non0[v]++;
            qs->count_1[v]++;
            qs->count_non0[w]++;
            qs->count_1[w]++;
            update_queues (w, qs, g);
        } else if (e->coef == 1) {
            qs->count_1[v]--;
            qs->count_1[w]--;
            update_queues (w, qs, g);
        } else if (e->coef == -1) {
            qs->count_m1[v]--;
            qs->count_non0[v]--;
            qs->count_m1[w]--;
            qs->count_non0[w]--;
            update_queues (w, qs, g);
        } else if (e->coef == -2) {
            qs->count_m1[v]++;
            qs->count_m1[w]++;
            update_queues (w, qs, g);
        }
        e->coef++;
    }
    update_queues (v, qs, g);
}

#ifdef CC_PROTOTYPE_ANSI
static void sub_node (int v, CCtsp_qsparsegroup *qs, CCtsp_lpgraph *g,
        int *pnzlist)
#else
static void sub_node (v, qs, g, pnzlist)
int v;
CCtsp_qsparsegroup *qs;
CCtsp_lpgraph *g;
int *pnzlist;
#endif
{
    int j, w;
    CCtsp_lpnode *lv = &(g->nodes[v]);
    CCtsp_lpedge *e;

    for (j = lv->deg - 1; j >= 0; j--) {
        e = &(g->edges[lv->adj[j].edge]);
        w = lv->adj[j].to;
        if (e->coef == 0) {
            if (e->coefnext == -2) {
                e->coefnext = *pnzlist;
                *pnzlist = lv->adj[j].edge;
            }
            qs->count_non0[v]++;
            qs->count_m1[v]++;
            qs->count_non0[w]++;
            qs->count_m1[w]++;
            update_queues (w, qs, g);
        } else if (e->coef == -1) {
            qs->count_m1[v]--;
            qs->count_m1[w]--;
            update_queues (w, qs, g);
        } else if (e->coef == 1) {
            qs->count_1[v]--;
            qs->count_non0[v]--;
            qs->count_1[w]--;
            qs->count_non0[w]--;
            update_queues (w, qs, g);
        } else if (e->coef == 2) {
            qs->count_1[v]++;
            qs->count_1[w]++;
            update_queues (w, qs, g);
        }
        e->coef--;
    }
    update_queues (v, qs, g);
}

/* update_queues (v, qs, g) should be called whenever some of the counts for
   v have changed */

#ifdef CC_PROTOTYPE_ANSI
static void update_queues (int v, CCtsp_qsparsegroup *qs, CCtsp_lpgraph *g)
#else
static void update_queues (v, qs, g)
int v;
CCtsp_qsparsegroup *qs;
CCtsp_lpgraph *g;
#endif
{
    if (qs->count_m1[v] - (g->nodes[v].deg - qs->count_non0[v]) > 0) {
        if (qs->on_add_queue[v]) {
            queue_keychange (qs->add_queue, v,
                  qs->count_m1[v] - (g->nodes[v].deg - qs->count_non0[v]));
        } else {
            queue_add (qs->add_queue, v,
                  qs->count_m1[v] - (g->nodes[v].deg - qs->count_non0[v]));
            qs->on_add_queue[v] = 1;
        }
    } else {
        if (qs->on_add_queue[v]) {
            queue_delete (qs->add_queue, v);
            qs->on_add_queue[v] = 0;
        }
    }

    if (qs->count_1[v] - (g->nodes[v].deg - qs->count_non0[v]) > 0) {
        if (qs->on_sub_queue[v]) {
            queue_keychange (qs->sub_queue, v,
                  qs->count_1[v] - (g->nodes[v].deg - qs->count_non0[v]));
        } else {
            queue_add (qs->sub_queue, v,
                  qs->count_1[v] - (g->nodes[v].deg - qs->count_non0[v]));
            qs->on_sub_queue[v] = 1;
        }
    } else {
        if (qs->on_sub_queue[v]) {
            queue_delete (qs->sub_queue, v);
            qs->on_sub_queue[v] = 0;
        }
    }
}
