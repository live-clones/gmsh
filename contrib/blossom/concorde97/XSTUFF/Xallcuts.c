/**************************************************************************/
/*                                                                        */
/* EXPORTED FUNCTION:                                                     */
/*        void  all_tightcuts ()                                          */
/*                                                                        */
/**************************************************************************/

#include "machdefs.h"
#include "util.h"
#include "Xsubtour.h"

#ifdef CC_PROTOTYPE_ANSI

static void
    magiclabel_nodes (Xnodeptr *S, int v),
    test_cut (Xnode *, Xedge *),
    found_tight_cut (Xnodeptr *),
    unbump_S (Xnodeptr *, Xedge *),
    buildpseudonodelist_pathshrink (int),
    collect_nodes (Xnode *);

static int
    next_min_cut (Xnodeptr *, Xnode *, Xnode *, Xedge *, Xnodeptr **);

static double
    cut_value (Xnodeptr *S);

static Xnode
    *next_node (Xnode *, Xnode *);

#else

static void
    magiclabel_nodes (),
    test_cut (),
    found_tight_cut (),
    unbump_S (),
    buildpseudonodelist_pathshrink (),
    collect_nodes ();

static int
    next_min_cut ();

static double
    cut_value ();

static Xnode
    *next_node ();

#endif


#define EPSILON (0.0005)

#define TWO      2.0
#define TWOPLUS  (2.0 + EPSILON)
#define TWOMINUS (2.0 - EPSILON)
#define ONEMINUS (1.0 - EPSILON/2)

static Xclique **cliquelist;
static int *ncliques;
static int quiet = 0;
static Xgraph *G;

#ifdef CC_PROTOTYPE_ANSI
void  Xall_tightcuts (Xgraph *Gin, Xclique **cliquelistin, int *ncliquesin)
#else
void  Xall_tightcuts (Gin, cliquelistin, ncliquesin)
Xgraph *Gin;
Xclique **cliquelistin;
int *ncliquesin;
#endif
{
    Xnode *s;
    Xedgeptr *ep;
    Xedge *e;
    int i;
    Xclique *c;
    Xintptr *p;

    G = Gin;
    cliquelist = cliquelistin;
    ncliques = ncliquesin;

    buildpseudonodelist_pathshrink (1);

    for (i = 0; i < G->nedges; i++) {
        if (G->edgelist[i].x > ONEMINUS) {
            c = Xcliquealloc ();
            p = Xintptralloc ();
            p->this = G->edgelist[i].ends[0] - G->nodelist;
            p->next = (Xintptr *) NULL;
            c->nodes = p;
            p = Xintptralloc ();
            p->this = G->edgelist[i].ends[1] - G->nodelist;
            p->next = c->nodes;
            c->nodes = p;
            c->slack = 1.0 - G->edgelist[i].x;
            c->next = *cliquelist;
            *cliquelist = c;
            (*ncliques)++;
        }
    }

    for (s = G->pseudonodelist->next; s; s = s->next) {
        for (ep = s->cadj.head; ep; ep = ep->next) {
            e = ep->this;
            if (s == e->cends[0]) {
                test_cut (s, e);
                e->x += 2.5;    /* So we won't hit these again */
            }
        }
    }

    for (s = G->pseudonodelist->next; s; s = s->next) {
        Xedgeptr_list_free (s->cadj.head);
        s->cadj.head = (Xedgeptr *) NULL;
        s->cadj.tail = (Xedgeptr *) NULL;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void  test_cut (Xnode *s, Xedge *st)
#else
static void  test_cut (s, st)
Xnode *s;
Xedge *st;
#endif
{
    Xnodeptr *S, *smallest;
    Xnode *t;

    /* Find all cuts containing edge st (and chose the side missing s) */

    t = OTHERCURRENTEND (st, s);
    smallest = (Xnodeptr *) NULL;
    Xadd_nodeptr (&smallest, t);

    /* printf ("Cuts containing (%d, %d)\n", s - G->nodelist, t - G->nodelist); */
    do {
        S = smallest;
        if (next_min_cut (S, s, t, st, &smallest)) {
            found_tight_cut (smallest);
            if (!quiet && (cut_value (smallest) < TWOMINUS ||
                           cut_value (smallest) > TWOPLUS)) {
                fprintf (stderr, "PROBLEM WITH CUT VALUE %f\n",
                         cut_value (smallest));
                fflush (stderr);
            }
        }
        Xnodeptr_list_free (S);
    } while (smallest);
}

#ifdef CC_PROTOTYPE_ANSI
static void  found_tight_cut (Xnodeptr *smallest)
#else
static void  found_tight_cut (smallest)
Xnodeptr *smallest;
#endif
{
    int count;
    Xnodeptr *np, *np2;
    int match;
    int i;
    Xclique *c;
    Xintptr *p;

    for (i = 0; i < G->nnodes; i++) {
        G->nodelist[i].mark = 0;
    }

    for (count = 0, np = smallest; np; np = np->next) {
        for (np2 = np->this->base.head; np2; np2 = np2->next) {
            count++;
            np2->this->mark = 1;
        }
    }

    if (count != (G->nnodes - 1) && count != 1) {
        if (count > G->nnodes / 2)
            match = 0;
        else
            match = 1;
        c = Xcliquealloc ();
        c->nodes = (Xintptr *) NULL;
        for (i = 0; i < G->nnodes; i++) {
            if (G->nodelist[i].mark == match) {
                p = Xintptralloc ();
                p->this = i;
                p->next = c->nodes;
                c->nodes = p;
            }
        }
        c->slack = 0.0;
        c->next = *cliquelist;
        *cliquelist = c;
        (*ncliques)++;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static int  next_min_cut (Xnodeptr *S, Xnode *s, Xnode *t, Xedge *st, Xnodeptr **smallest)
#else
static int next_min_cut (S, s, t, st, smallest)
Xnodeptr *S;
Xnode *s, *t;
Xedge *st;
Xnodeptr **smallest;
#endif
{
    Xnodeptr *np, *nlist;
    Xnode *n;
    Xedgeptr *ep, *delta;
    Xedge *e;
    int least_count, count, label;
    double val;

    *smallest = (Xnodeptr *) NULL;

    G->magicnum++;
    for (np = S; np; np = np->next) {
        if (np->this == s) {
            printf ("%d in S\n", (int) (s - G->nodelist));
            return 0;
        }
        np->this->magiclabel = G->magicnum;
    }
    delta = (Xedgeptr *) NULL;
    for (np = S; np; np = np->next) {
        n = np->this;
        for (ep = n->cadj.head; ep; ep = ep->next) {
            if ((e = ep->this) == st)
                continue;
            if ((OTHERCURRENTEND (e, n))->magiclabel == G->magicnum) {
                if (e->x < 4.0)
                    e->x += 4.0;
            } else
                Xadd_edgeptr (&delta, e);
        }
    }

    if (Xflow (G, s, t, TWOPLUS) >= TWOPLUS) {
        unbump_S (S, st);
        Xedgeptr_list_free (delta);
        return 0;
    }
    least_count = G->nnodes + 1;
    for (ep = delta; ep; ep = ep->next) {
        e = ep->this;
        e->x += 4.0;
        if (Xmincut (G, s, t, TWOPLUS, &val, &label)) {
            count = 0;
            nlist = (Xnodeptr *) NULL;
            for (n = G->pseudonodelist->next; n; n = n->next)
                if (n->magiclabel == label) {
                    count++;
                    Xadd_nodeptr (&nlist, n);
                }
            if (count < least_count) {
                least_count = count;
                if (*smallest)
                    Xnodeptr_list_free (*smallest);
                *smallest = nlist;
            } else
                Xnodeptr_list_free (nlist);
        }
        e->x -= 4.0;
    }

    unbump_S (S, st);
    Xedgeptr_list_free (delta);

    return (*smallest != (Xnodeptr *) NULL);
}

#ifdef CC_PROTOTYPE_ANSI
static void  unbump_S (Xnodeptr *S, Xedge *st)
#else
static void  unbump_S (S, st)
Xnodeptr *S;
Xedge *st;
#endif
{
    Xnodeptr *np;
    Xnode *n;
    Xedgeptr *ep;
    Xedge *e;

    magiclabel_nodes (S, ++G->magicnum);
    for (np = S; np; np = np->next) {
        n = np->this;
        for (ep = n->cadj.head; ep; ep = ep->next) {
            if ((e = ep->this) == st)
                continue;
            if ((OTHERCURRENTEND (e, n))->magiclabel == G->magicnum) {
                if (e->x >= 4.0)
                    e->x -= 4.0;
            }
        }
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void  buildpseudonodelist_pathshrink (int all)
#else
static void  buildpseudonodelist_pathshrink (all)
int all;
#endif
{
    /* modified 2/10 to compress paths of ones */
    int i;
    Xnode *n;
    Xedge *e;
    Xedgeptr *e1;
    static Xnode pseudodummy;
    Xnode *nprev;
    Xnode *n2;

    for (i = 0; i < G->nnodes; i++) {
        G->nodelist[i].Tmark = 0;
        G->nodelist[i].tnext = (Xnode *) NULL;
    }

    for (i = 0; i < G->nedges; i++) {
        if (G->edgelist[i].x > ONEMINUS) {
            G->edgelist[i].ends[0]->Tmark++;
            G->edgelist[i].ends[1]->Tmark++;
        }
    }

    G->pseudonodelist = &pseudodummy;
    pseudodummy.prev = (Xnode *) NULL;
    pseudodummy.next = (Xnode *) NULL;
    nprev = G->pseudonodelist;
    for (i = 0, n = G->nodelist; i < G->nnodes; i++, n++) {
        n->base.head = Xnodeptralloc ();
        n->base.tail = n->base.head;
        n->base.head->next = (Xnodeptr *) NULL;
        n->base.head->this = n;
        if (n->Tmark == 1) {
            collect_nodes (n);
        }
        n->cadj.head = n->cadj.tail = (Xedgeptr *) NULL;
        if (n->Tmark != 2) {
            n->prev = nprev;
            nprev->next = n;
            nprev = n;
            n->tnext = n;
        }
    }
    for (i=0; i<G->nnodes; i++) {
        if (G->nodelist[i].tnext == (Xnode *) NULL) {
            printf ("ALLCUTS GRAPH CONTAINS CYCLE\n");
            n = next_node (&G->nodelist[i], (Xnode *) NULL);
            n2 = next_node (&G->nodelist[i], n); /* this trusts that next_node is consistent between calls */
            G->nodelist[i].Tmark = 1;
            n2->Tmark = 1;
            collect_nodes (&G->nodelist[i]);
            G->nodelist[i].prev = nprev;
            nprev->next = &G->nodelist[i];
            nprev = &G->nodelist[i];
            G->nodelist[i].tnext = &G->nodelist[i];
        }
    }
    nprev->next = (Xnode *) NULL;

    for (i = G->nedges, e = G->edgelist; i; i--, e++) {
        if ((all || e->x > 0.0) && e->ends[0]->tnext != e->ends[1]->tnext) {
            e->stay = 1;
            e->cends[0] = e->ends[0]->tnext;
            e->cends[1] = e->ends[1]->tnext;
            e1 = Xedgeptralloc ();
            e1->next = (e->cends[0])->cadj.head;
            e1->this = e;
            (e->cends[0])->cadj.head = e1;
            if ((e->cends[0])->cadj.tail == (Xedgeptr *) NULL) {
                (e->cends[0])->cadj.tail = e1;
            }
            e1 = Xedgeptralloc ();
            e1->next = (e->cends[1])->cadj.head;
            e1->this = e;
            (e->cends[1])->cadj.head = e1;
            if ((e->cends[1])->cadj.tail == (Xedgeptr *) NULL) {
                (e->cends[1])->cadj.tail = e1;
            }
        } else {
            e->stay = 0;
        }
    }
    G->npseudonodes = G->nnodes;
}

#ifdef CC_PROTOTYPE_ANSI
static Xnode  *next_node (Xnode *n, Xnode *nold)
#else
static Xnode  *next_node (n, nold)
Xnode *n;
Xnode *nold;
#endif
{
    Xedgeptr *ep;

    for (ep = n->adj.head; ep; ep = ep->next) {
        if (ep->this->x > ONEMINUS) {
            if (ep->this->ends[0] != n && ep->this->ends[0] != nold) {
                return ep->this->ends[0];
            } else if (ep->this->ends[1] != n && ep->this->ends[1] != nold) {
                return ep->this->ends[1];
            }
        }
    }
    return (Xnode *) NULL;
}

#ifdef CC_PROTOTYPE_ANSI
static void  collect_nodes (Xnode *n)
#else
static void  collect_nodes (n)
Xnode *n;
#endif
{
    Xnode *nold;
    Xnode *nnew;
    Xnode *ncur;
    Xnodeptr *np;

    ncur = n;
    nold = (Xnode *) NULL;

    while ((nnew = next_node (ncur, nold)) && nnew->Tmark == 2) {
        nold = ncur;
        ncur = nnew;
        ncur->tnext = n;
        np = Xnodeptralloc ();
        np->this = ncur;
        np->next = (Xnodeptr *) NULL;
        if (!n->base.tail) {
            n->base.tail = n->base.head = np;
        } else {
            n->base.tail->next = np;
            n->base.tail = np;
        }
    }
    if (!nnew) {
        fprintf (stderr, "Path vanished\n");
        exit (1);
    }
    nnew->Tmark = 0;
}

#ifdef CC_PROTOTYPE_ANSI
static double cut_value (Xnodeptr *S)
#else
static double cut_value (S)
Xnodeptr *S;
#endif
{
    double val = 0.0;
    Xnodeptr *np;
    Xnode *n;
    Xedgeptr *ep;
    Xedge *e;

    magiclabel_nodes (S, ++(G->magicnum));
    for (np = S; np; np = np->next) {
        n = np->this;
        for (ep = n->cadj.head; ep; ep = ep->next) {
            e = ep->this;
            if (OTHERCURRENTEND (e, n)->magiclabel != G->magicnum)
                val += e->x;
        }
    }
    return val;
}

#ifdef CC_PROTOTYPE_ANSI
static void magiclabel_nodes (Xnodeptr *S, int v)
#else
static void magiclabel_nodes (S, v)
Xnodeptr *S;
int v;
#endif
{
    Xnodeptr *np;

    for (np = S; np; np = np->next)
        np->this->magiclabel = v;
}
