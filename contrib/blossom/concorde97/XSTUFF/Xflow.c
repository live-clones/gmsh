/**************************************************************************/
/*                                                                        */
/* EXPORTED FUNCTION:                                                     */
/*                                                                        */
/*    double flow ();                                                     */
/*                                                                        */
/**************************************************************************/

#include "machdefs.h"
#include "Xsubtour.h"

#ifdef CC_PROTOTYPE_ANSI

static void
    relabel (Xnode *),
    setlabels (Xgraph *G, Xnode *, Xnode *),
    backwards_bfs (Xnode *, int),
    addtoq (Xnodeset *, Xnode *),
    dfs2 (Xgraph *G, Xnode *start),
    marknode (Xnode *n, int v);

static int
    subtourcuts (Xgraph *G, Xcplane **list),
    connectcuts (Xgraph *G, Xcplane **list),
    dfs (Xgraph *G, Xnode *start);

static Xnode
    *push (Xnode *, Xedge *),
    *popfromq (Xnodeset *);

#else

static void
    relabel (),
    setlabels (),
    backwards_bfs (),
    addtoq (),
    dfs2 (),
    marknode ();

static int
    subtourcuts (),
    connectcuts (),
    dfs ();

static Xnode
    *push (),
    *popfromq ();

#endif

#define INFINITY (1<<30)

#ifdef CC_PROTOTYPE_ANSI
double Xflow (Xgraph *G, Xnode *s, Xnode *t, double bound)
#else
double Xflow (G, s, t, bound)
Xgraph *G;
Xnode *s, *t;
double bound;
#endif
{
    Xnodeset q;
    Xnode *n, *n1;
    Xedge *e;
    int savelabel;
    Xedgeptr *ep;
    int count, round;

    q.head = q.tail = (Xnodeptr *) NULL;
    for (n = G->pseudonodelist->next; n; n = n->next) {
        n->excess = 0.0;
        n->active = 0;
        n->current = n->cadj.head;
        n->flowlabel = 0;
        for (ep = n->cadj.head; ep; ep = ep->next)
            ep->this->flow = 0.0;
    }
    setlabels (G, s, t);
    t->active = 1;              /* a lie, which keeps t off the active queue */
    for (ep = s->cadj.head; ep; ep = ep->next) {
        e = ep->this;
        if (!e->stay)
            continue;
        if (e->cends[0] == s) {
            e->flow = e->x;
            if (e->x > 0.0) {
                e->cends[1]->excess += e->x;
                addtoq (&q, e->cends[1]);
            }
        } else {
            e->flow = -e->x;
            if (e->x > 0.0) {
                e->cends[0]->excess += e->x;
                addtoq (&q, e->cends[0]);
            }
        }
    }
    count = 0;
    round = G->npseudonodes / 2;
    while (q.head && t->excess < bound) {
        if (count == round) {
            setlabels (G, s, t);
            count = 0;
        } else
            count++;
        n = popfromq (&q);
        n->active = 0;
        savelabel = n->flowlabel;
        do {
            ep = n->current;
            if ((n1 = push (n, ep->this)) != (Xnode *) NULL)
                addtoq (&q, n1);
            else {
                n->current = ep->next;
                if (!n->current) {
                    n->current = n->cadj.head;
                    relabel (n);
                }
            }
        } while (n->excess > 0.0 && n->flowlabel == savelabel);
        if (n->excess > 0.0 && n->flowlabel < G->npseudonodes)
            addtoq (&q, n);
    }

    while (q.head) {
        popfromq (&q);
    }

    return t->excess;
}

#ifdef CC_PROTOTYPE_ANSI
static void relabel (Xnode *n)
#else
static void relabel (n)
Xnode *n;
#endif
{
    int m = INFINITY;
    Xedgeptr *ep;
    Xedge *e;
    int t;

    for (ep = n->cadj.head; ep; ep = ep->next) {
        e = ep->this;
        if (n == e->cends[0]) {
            if (e->x - e->flow > 0.0 && (t = e->cends[1]->flowlabel) < m)
                m = t;
        } else {
            if (e->x + e->flow > 0.0 && (t = e->cends[0]->flowlabel) < m)
                m = t;
        }
    }
    n->flowlabel = m + 1;
}

#ifdef CC_PROTOTYPE_ANSI
static Xnode *push (Xnode *n, Xedge *e)
#else
static Xnode *push (n, e)
Xnode *n;
Xedge *e;
#endif
{
    Xnode *n1;
    double rf;

    if (e->cends[0] == n) {
        n1 = e->cends[1];
        rf = e->x - e->flow;
        if (n->flowlabel == n1->flowlabel + 1 && rf > 0.0) {
            if (n->excess < rf)
                rf = n->excess;
            n->excess -= rf;
            e->flow += rf;
            n1->excess += rf;
            return n1;
        } else
            return 0;
    } else {
        n1 = e->cends[0];
        rf = e->x + e->flow;
        if (n->flowlabel == n1->flowlabel + 1 && rf > 0.0) {
            if (n->excess < rf)
                rf = n->excess;
            n->excess -= rf;
            e->flow -= rf;
            n1->excess += rf;
            return n1;
        } else
            return 0;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void setlabels (Xgraph *G, Xnode *s, Xnode *t)
#else
static void setlabels (G, s, t)
Xgraph *G;
Xnode *s, *t;
#endif
{
    G->magicnum++;
    t->flowlabel = 0;
    backwards_bfs (t, G->magicnum);
    s->flowlabel = G->npseudonodes;

    if (s->magiclabel == G->magicnum)
        return;
    else
        backwards_bfs (s, G->magicnum);
}

#ifdef CC_PROTOTYPE_ANSI
static void backwards_bfs (Xnode *s, int K)
#else
static void backwards_bfs (s, K)
Xnode *s;
int K;
#endif
{
    Xnode *this, *next, *tail;
    Xedge *e;
    Xedgeptr *ep;
    int dist;

    s->magiclabel = K;
    next = s;
    s->tnext = (Xnode *) NULL;
    do {
        for (this = next, next = (Xnode *) NULL; this; this = this->tnext) {
            dist = this->flowlabel + 1;
            for (ep = this->cadj.head; ep; ep = ep->next) {
                e = ep->this;
                if (this == e->cends[0]) {
                    tail = e->cends[1];
                    if (tail->magiclabel != K &&
                        e->x + e->flow > 0.0) {
                        tail->flowlabel = dist;
                        tail->tnext = next;
                        next = tail;
                        tail->magiclabel = K;
                    }
                } else {
                    tail = e->cends[0];
                    if (tail->magiclabel != K &&
                        e->x - e->flow > 0.0) {
                        tail->flowlabel = dist;
                        tail->tnext = next;
                        next = tail;
                        tail->magiclabel = K;
                    }
                }
            }
        }
    } while (next);
}

#ifdef CC_PROTOTYPE_ANSI
static void addtoq (Xnodeset *q, Xnode *n)
#else
static void addtoq (q, n)
Xnodeset *q;
Xnode *n;
#endif
{
    Xnodeptr *newn;

    if (!n->active) {
        newn = Xnodeptralloc ();
        newn->next = (Xnodeptr *) NULL;
        newn->this = n;
        if (q->tail) {
            q->tail->next = newn;
        } else {
            q->head = newn;
        }
        q->tail = newn;
        n->active = 1;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static Xnode *popfromq (Xnodeset *q)
#else
static Xnode *popfromq (q)
Xnodeset *q;
#endif
{
    Xnodeptr *newn = q->head;
    Xnode *n = newn->this;

    q->head = newn->next;
    if (!q->head)
        q->tail = (Xnodeptr *) NULL;
    Xnodeptrfree (newn);
    return n;
}

#ifdef CC_PROTOTYPE_ANSI
static int subtourcuts (Xgraph *G, Xcplane **list)
#else
static int subtourcuts (G, list)
Xgraph *G;
Xcplane **list;
#endif
{
    Xnode *n, *nnext;
    int returnval = 0;

    for (n = G->pseudonodelist->next->next; n; n = nnext) {
        /* printf ("o"); fflush (stdout); */

        nnext = n->next;
        if (Xflow (G, G->pseudonodelist->next, n, XCUTTWO) < XCUTTWO) {
            G->magicnum++;
            dfs2 (G, n);
            returnval += Xloadcplane_cut (G, list, G->magicnum);
            /* printf ("i"); fflush (stdout); */
            Xsimpleshrink (G, G->pseudonodelist->next, n);
        }
    }
    /* printf ("\n"); */
    return returnval;
}

#ifdef CC_PROTOTYPE_ANSI
static void dfs2 (Xgraph *G, Xnode *start)
#else
static void dfs2 (G, start)
Xgraph *G;
Xnode *start;
#endif
{
    Xedgeptr *epp;
    Xedge *ep;
    Xnodeptr *next, *queue = (Xnodeptr *) NULL;
    Xnode *n;

    marknode (start, G->magicnum);
    Xadd_nodeptr (&queue, start);

    while (queue) {
        n = queue->this;
        next = queue->next;
        Xnodeptrfree (queue);
        queue = next;
        for (epp = n->cadj.head; epp; epp = epp->next) {
            ep = epp->this;
            if (ep->cends[0] == n) {
                if (ep->x + ep->flow > 0.0 &&
                    ep->cends[1]->magiclabel != G->magicnum) {
                    marknode (ep->cends[1], G->magicnum);
                    Xadd_nodeptr (&queue, ep->cends[1]);
                }
            } else {
                if (ep->x - ep->flow > 0.0 &&
                    ep->cends[0]->magiclabel != G->magicnum) {
                    marknode (ep->cends[0], G->magicnum);
                    Xadd_nodeptr (&queue, ep->cends[0]);
                }
            }
        }
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void marknode (Xnode *n, int v)
#else
static void marknode (n, v)
Xnode *n;
int v;
#endif
{
    Xnodeptr *np;

    n->magiclabel = v;
    for (np = n->base.head; np; np = np->next) {
        np->this->magiclabel = v;
    }
}

#ifdef CC_PROTOTYPE_ANSI
int Xexactcutcheck (Xgraph *G, Xcplane **list, double *x)
#else
int Xexactcutcheck (G, list, x)
Xgraph *G;
Xcplane **list;
double *x;
#endif
{
    int i, hit;

    Xloadx (G, x);
    Xbuildpseudonodelist (G, 0);
    i = Xshrinkprocess (G, list);
/*
    printf ("%d heavy-edge cut(s), np = %d\n", i, G->npseudonodes);
    fflush (stdout);
*/
    if (i >= XCUTNUM) {
        Xdestroypseudonodelist (G);
        return i;
    }
    hit = i;
    Xrebuildcadj (G);

    i = subtourcuts (G, list);
    /* printf ("%d flow cut(s)\n", i); fflush (stdout); */
    Xdestroypseudonodelist (G);

    return hit + i;
}

#ifdef CC_PROTOTYPE_ANSI
int Xmincut (Xgraph *G, Xnode *s, Xnode *t, double bound, double *value,
            int *label)
#else
int Xmincut (G, s, t, bound, value, label)
Xgraph *G;
Xnode *s, *t;
double bound, *value;
int *label;
#endif
{
    /* Uses the x field as capacities. If min cut from s to t has */
    /* value < bound it returns 1 and marks nodes in cut with     */
    /* magiclabel equal to label.  value get the capacity of cut. */

    *value = Xflow (G, s, t, bound);
    if (*value >= bound)
        return 0;
    else {
        G->magicnum++;
        dfs2 (G, t);
        *label = G->magicnum;
        return 1;
    }
}

#ifdef CC_PROTOTYPE_ANSI
int Xrunconnectcuts (Xgraph *G, Xcplane **list, double *x)
#else
int Xrunconnectcuts (G, list, x)
Xgraph *G;
Xcplane **list;
double *x;
#endif
{
    int i;

    Xloadx (G, x);
    Xbuildpseudonodelist (G, 0);
    i = connectcuts (G, list);
    Xdestroypseudonodelist (G);

    fflush (stdout);
    return i;
}

#ifdef CC_PROTOTYPE_ANSI
static int connectcuts (Xgraph *G, Xcplane **list)
#else
static int connectcuts (G, list)
Xgraph *G;
Xcplane **list;
#endif
{
    int val, ccount = 0, count, track = 1;
    Xnode *n;

    val = ++(G->magicnum);
    if ((count = dfs (G, G->pseudonodelist->next)) < G->npseudonodes) {
        ccount += Xloadcplane_cut (G, list, G->magicnum);
        n = G->pseudonodelist->next;
        do {
            track++;
            n = n->next;
            while (n->magiclabel >= val)
                n = n->next;
            G->magicnum++;
            count += dfs (G, n);
        } while (count < G->npseudonodes);

        if (track > 2) {
            for (val++; val <= G->magicnum; val++) {
                ccount += Xloadcplane_cut (G, list, val);
            }
            return ccount;
        } else {
            return ccount;
        }
    }
    return 0;
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

    marknode (start, G->magicnum);
    Xadd_nodeptr (&queue, start);

    while (queue) {
        i++;
        n = queue->this;
        next = queue->next;
        Xnodeptrfree (queue);
        queue = next;
        for (epp = n->cadj.head; epp; epp = epp->next) {
            ep = epp->this;
            if (ep->stay) {
                n1 = ep->cends[0];
                if (n1 == n)
                    n1 = ep->cends[1];
                if (n1->magiclabel != G->magicnum) {
                    marknode (n1, G->magicnum);
                    Xadd_nodeptr (&queue, n1);
                }
            }
        }
    }
    return i;
}

