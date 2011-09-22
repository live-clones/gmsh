/**************************************************************************/
/*                                                                        */
/* EXPORTED FUNCTIONS:                                                    */
/*                                                                        */
/*  int                                                                   */
/*      Xcliquetree (Xgraph *G, Xcplane **list, double *x),               */
/*      Xcliquetree_work (Xgraph *G, Xcplane **list, int pseudo,          */
/*                        double *x, int type_of_grow)                    */
/*                                                                        */
/**************************************************************************/


#include "machdefs.h"
#include "Xsubtour.h"


#ifdef CC_PROTOTYPE_ANSI

static void
    split_T (Xgraph *G, Xnodeptr *T, Xnodeptr *U, Xnodeptr **u1,
          Xnodeptr **u2, Xnodeptr **u3, Xnodeptr **u4, Xnodeptr **u5),
    clique_dfs (Xgraph *G, Xnode *start, int z, int storenodes,
          Xnodeptr **list),
    unscan_remove (Xgraph *G, Xedgeptr **unscan, Xnodeptr *T),
    remove_from_nodeptr (Xnode *n, Xnodeptr **list),
    add_nodeptr_list (Xnodeptr **addto, Xnodeptr *takefrom),
    label_nodeptr_list (Xnodeptr *list, int z),
    pseudonodelist_to_nodelist (Xnodeptr *p, Xnodeptr **l);

static int
    clique_setup (Xgraph *G, int ct, Xnodeptr **u1, Xnodeptr **u2,
          Xnodeptr **u3, Xnodeptr **u4, Xnodeptr **u5, int type_of_grow),
    process_T (Xgraph *G, Xnodeptr **T, Xedge *e, Xnodeptr *U,
          Xnodeptr **u1, Xnodeptr **u2, int type_of_grow),
    grow (Xgraph *G, Xnodeptr **T, Xedge *e, Xnodeptr *U),
    grow2 (Xgraph *G, Xnodeptr **T, Xedge *e, Xnodeptr *U),
    grabcomponents (Xgraph *G, int z, Xnodeptr *T, Xnodeptr *U,
          Xnodeptr **u1, Xnodeptr **u2),
    improve (Xgraph *G, Xnodeptr **u1, Xnodeptr **u2, Xnodeptr **u3,
          Xnodeptr **u4, Xnodeptr **u5),
    grab_from_u5 (Xgraph *G, Xnodeptr *u1, Xnodeptr *u2, Xnodeptr *u3,
          Xnodeptr *u4, Xnodeptr *u5, Xnodeptr **pick, Xnode **v),
    grab_from_mate (Xgraph *G, Xnodeptr *mate, Xnodeptr *u3,
          Xnodeptr *u4, Xnodeptr *u5, Xnode **w),
    clique_violated (Xgraph *G, Xnodeptr *u1, Xnodeptr *u2,
           Xnodeptr *u3, Xnodeptr *u4, Xnodeptr *u5),
    clique_fringe (Xnode *n, int ct),
    check_special_cliquetree (Xgraph *G, Xnodeptr *u1, Xnodeptr *u2,
           Xnodeptr *u3, Xnodeptr *u4, Xnodeptr *u5, Xcplane **list, double *x),
    load_special_cliquetree (Xgraph *G, Xnodeptr *H1, Xnodeptr *H2,
           Xnodeptr *T, Xedgeptr *pteeth, Xcplane **list, double *x);

static double
    crossvalue (Xgraph *G, Xnodeptr *s1, Xnodeptr *s2, Xnodeptr *s3),
    single_crossvalue (Xgraph *G, Xnode *v, Xnodeptr *s1,
           Xnodeptr *s2, Xnodeptr *s3),
    clique_slack (Xgraph *G, Xnodeptr *s);

static Xnode
    *best_w (Xgraph *G, Xnodeptr *T, Xnodeptr *ui, Xnode *hitter);

#else

static void
    split_T (),
    clique_dfs (),
    unscan_remove (),
    remove_from_nodeptr (),
    add_nodeptr_list (),
    label_nodeptr_list (),
    pseudonodelist_to_nodelist ();

static int
    clique_setup (),
    process_T (),
    grow (),
    grow2 (),
    grabcomponents (),
    improve (),
    grab_from_u5 (),
    grab_from_mate (),
    clique_violated (),
    clique_fringe (),
    check_special_cliquetree (),
    load_special_cliquetree ();

static double
    crossvalue (),
    single_crossvalue (),
    clique_slack ();

static Xnode
    *best_w ();

#endif

#ifdef  DEBUG
#ifdef CC_PROTOTYPE_ANSI
static void
    nodeptr_print (Xgraph *G, Xnodeptr *s),
    dump_special_cliquetree (Xgraph *G, Xnodeptr *u1, Xnodeptr *u2,
          Xnodeptr *u3, Xnodeptr *u4, Xnodeptr *u5);
#else
static void
    nodeptr_print (),
    dump_special_cliquetree ();
#endif
#endif

#define ONEMINUS 0.999999

#ifdef CC_PROTOTYPE_ANSI
int Xcliquetree (Xgraph *G, Xcplane **list, double *x)
#else
int Xcliquetree (G, list, x)
Xgraph *G;
Xcplane **list;
double *x;
#endif
{
    int hit = 0;

    hit += Xcliquetree_work (G, list, 0, x, 0);
    if (hit < XCUTNUM)
        hit += Xcliquetree_work (G, list, 0, x, 1);

    return hit;
}

#ifdef CC_PROTOTYPE_ANSI
int Xcliquetree_work (Xgraph *G, Xcplane **list, int pseudo, double *x,
     int type_of_grow)
#else
int Xcliquetree_work (G, list, pseudo, x, type_of_grow)
Xgraph *G;
Xcplane **list;
int pseudo;
double *x;
int type_of_grow;
#endif
{
    int ncomponents, ct, hit, roll, realcount = 0;
    Xnodeptr *u1, *u2, *u3, *u4, *u5;

    if (!pseudo) {
        Xloadx (G, x);
        Xbuildpseudonodelist (G, 0);
    }
    ncomponents = XTmark_components (G);
    for (ct = 1; ct <= ncomponents; ct++) {
        u1 = u2 = u3 = u4 = u5 = (Xnodeptr *) NULL;
        if (!clique_setup (G, ct, &u1, &u2, &u3, &u4, &u5, type_of_grow))
            continue;
        hit = 0;
        do {
            roll = improve (G, &u1, &u2, &u3, &u4, &u5);
            if (clique_violated (G, u1, u2, u3, u4, u5))
                hit = 1;
        } while (!hit && roll);
        if (hit) {
            realcount +=
                check_special_cliquetree (G, u1, u2, u3, u4, u5, list, x);
        }
        Xnodeptr_list_free (u1);
        Xnodeptr_list_free (u2);
        Xnodeptr_list_free (u3);
        Xnodeptr_list_free (u4);
        Xnodeptr_list_free (u5);
    }

    if (!pseudo) {
        Xdestroypseudonodelist (G);
        /* printf ("%d clique trees\n", realcount); */
    }

    return realcount;
}

#ifdef CC_PROTOTYPE_ANSI
static int clique_setup (Xgraph *G, int ct, Xnodeptr **u1, Xnodeptr **u2,
            Xnodeptr **u3, Xnodeptr **u4, Xnodeptr **u5, int type_of_grow)
#else
static int clique_setup (G, ct, u1, u2, u3, u4, u5, type_of_grow)
Xgraph *G;
int ct;
Xnodeptr **u1, **u2, **u3, **u4, **u5;
int type_of_grow;
#endif
{
    Xnodeptr *np, *tp, *U = (Xnodeptr *) NULL, *T;
    Xnode *n;
    Xedgeptr *ep, *unscan = (Xedgeptr *) NULL;
    Xedge *e;
    int i, k;

    for (n = G->pseudonodelist->next; n; n = n->next) {
        n->mark = 0;
        if (n->Tmark == ct || clique_fringe (n, ct)) {
            tp = Xnodeptralloc ();
            tp->this = n;
            tp->next = U;
            U = tp;
        }
    }
    G->magicnum++;
    for (k = 0, np = U; np; np = np->next) {
        np->this->magiclabel = G->magicnum;
        k++;
    }
    if (k < 7) {
        Xnodeptr_list_free (U);
        return 0;
    }
    for (k = 0, np = U; np; np = np->next) {
        n = np->this;
        for (ep = n->cadj.head; ep; ep = ep->next) {
            e = ep->this;
            if (e->x > ONEMINUS &&
                OTHERCURRENTEND (e, n)->magiclabel != G->magicnum) {
                n->mark = 1;
                k++;
            }
        }
    }

    if (k < 4) {
        Xnodeptr_list_free (U);
        return 0;
    }
    if (k % 2) {
        Xnodeptr_list_free (U);
        return 0;
    }
    for (i = G->nedges, e = G->edgelist; i; i--, e++)
        if (e->stay && e->cends[0]->magiclabel == G->magicnum &&
            e->cends[1]->magiclabel == G->magicnum &&
            e->cends[0]->mark == 0 &&
            e->cends[1]->mark == 0) {
            ep = Xedgeptralloc ();
            ep->this = e;
            ep->next = unscan;
            unscan = ep;
        }
    while (unscan) {
        e = unscan->this;
        ep = unscan;
        unscan = unscan->next;
        Xedgeptrfree (ep);
        if (process_T (G, &T, e, U, u1, u2, type_of_grow)) {
            split_T (G, T, U, u1, u2, u3, u4, u5);
            Xnodeptr_list_free (U);
            Xnodeptr_list_free (T);
            Xedgeptr_list_free (unscan);
            return 1;
        } else {
            unscan_remove (G, &unscan, T);
            Xnodeptr_list_free (T);
        }
    }
    Xnodeptr_list_free (U);
    Xedgeptr_list_free (unscan);
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static void split_T (Xgraph *G, Xnodeptr *T, Xnodeptr *U, Xnodeptr **u1,
             Xnodeptr **u2, Xnodeptr **u3, Xnodeptr **u4, Xnodeptr **u5)
#else
static void split_T (G, T, U, u1, u2, u3, u4, u5)
Xgraph *G;
Xnodeptr *T, *U, **u1, **u2, **u3, **u4, **u5;
#endif
{
    Xnodeptr *np, *tp, *next;
    Xnode *n, *w1, *w2;

    G->magicnum++;
    for (np = T; np; np = np->next)
        np->this->magiclabel = G->magicnum;

    for (np = *u1, *u1 = (Xnodeptr *) NULL; np; np = next) {
        next = np->next;
        if (np->this->magiclabel == G->magicnum)
            Xnodeptrfree (np);
        else {
            np->next = *u1;
            *u1 = np;
        }
    }
    for (np = *u2, *u2 = (Xnodeptr *) NULL; np; np = next) {
        next = np->next;
        if (np->this->magiclabel == G->magicnum)
            Xnodeptrfree (np);
        else {
            np->next = *u2;
            *u2 = np;
        }
    }

    w1 = best_w (G, T, *u1, (Xnode *) NULL);
    np = Xnodeptralloc ();
    np->this = w1;
    np->next = (Xnodeptr *) NULL;
    *u3 = np;

    w2 = best_w (G, T, *u2, w1);
    np = Xnodeptralloc ();
    np->this = w2;
    np->next = (Xnodeptr *) NULL;
    *u4 = np;

    G->magicnum++;
    for (np = *u1; np; np = np->next)
        np->this->magiclabel = G->magicnum;
    for (np = *u2; np; np = np->next)
        np->this->magiclabel = G->magicnum;
    for (np = *u3; np; np = np->next)
        np->this->magiclabel = G->magicnum;
    for (np = *u4; np; np = np->next)
        np->this->magiclabel = G->magicnum;

    *u5 = (Xnodeptr *) NULL;
    for (np = U; np; np = np->next) {
        n = np->this;
        if (n->magiclabel != G->magicnum) {
            tp = Xnodeptralloc ();
            tp->this = n;
            tp->next = *u5;
            *u5 = tp;
        }
    }
}

#ifdef CC_PROTOTYPE_ANSI
static Xnode *best_w (Xgraph *G, Xnodeptr *T, Xnodeptr *ui, Xnode *hitter)
#else
static Xnode *best_w (G, T, ui, hitter)
Xgraph *G;
Xnodeptr *T, *ui;
Xnode *hitter;
#endif
{
    Xnodeptr *np;
    Xnode *n, *w = (Xnode *) NULL;
    Xedgeptr *ep;
    Xedge *e;
    double adj, bestadj = -1.0;

    G->magicnum++;
    for (np = ui; np; np = np->next)
        np->this->magiclabel = G->magicnum;

    for (np = T; np; np = np->next) {
        n = np->this;
        if (n == hitter)
            continue;
        adj = 0.0;
        for (ep = n->cadj.head; ep; ep = ep->next) {
            e = ep->this;
            if (OTHERCURRENTEND (e, n)->magiclabel ==
                G->magicnum)
                adj += e->x;
        }
        if (adj > bestadj) {
            bestadj = adj;
            w = n;
        }
    }
    return w;
}

#ifdef CC_PROTOTYPE_ANSI
static int process_T (Xgraph *G, Xnodeptr **T, Xedge *e, Xnodeptr *U,
            Xnodeptr **u1, Xnodeptr **u2, int type_of_grow)
#else
static int process_T (G, T, e, U, u1, u2, type_of_grow)
Xgraph *G;
Xnodeptr **T;
Xedge *e;
Xnodeptr *U, **u1, **u2;
int type_of_grow;
#endif
{
    Xnodeptr *np;
    Xnode *n;
    Xedgeptr *ep;
    Xedge *f;
    int iU;

    if (!type_of_grow) {
        if (grow (G, T, e, U) < 3)
            return 0;
    } else {
        if (grow2 (G, T, e, U) < 3)
            return 0;
    }

    iU = ++(G->magicnum);
    for (np = U; np; np = np->next)
        np->this->magiclabel = G->magicnum;
    G->magicnum++;
    for (np = *T; np; np = np->next)
        np->this->magiclabel = G->magicnum;

    G->magicedgenum++;
    for (np = U; np; np = np->next) {
        n = np->this;
        if (n->magiclabel == G->magicnum)
            continue;
        for (ep = n->cadj.head; ep; ep = ep->next) {
            f = ep->this;
            if ((OTHERCURRENTEND (f, n))->magiclabel >= iU)
                f->magiclabel = G->magicedgenum;
        }
    }
    if (grabcomponents (G, G->magicedgenum, *T, U, u1, u2))
        return 1;

    iU = ++(G->magicnum);
    for (np = U; np; np = np->next)
        np->this->magiclabel = G->magicnum;
    G->magicnum++;
    for (np = *T; np; np = np->next)
        np->this->magiclabel = G->magicnum;

    G->magicedgenum++;
    for (np = U; np; np = np->next) {
        n = np->this;
        if (n->magiclabel == G->magicnum)
            continue;
        for (ep = n->cadj.head; ep; ep = ep->next) {
            f = ep->this;
            if ((OTHERCURRENTEND (f, n))->magiclabel == iU)
                f->magiclabel = G->magicedgenum;
        }
    }

    if (grabcomponents (G, G->magicedgenum, *T, U, u1, u2))
        return 1;
    else
        return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int grow (Xgraph *G, Xnodeptr **T, Xedge *e, Xnodeptr *U)
#else
static int grow (G, T, e, U)
Xgraph *G;
Xnodeptr **T;
Xedge *e;
Xnodeptr *U;
#endif
{
    Xnodeptr *np, *tp;
    Xnode *n;
    Xedgeptr *ep;
    Xedge *f;
    int count, adcount, hit;
    double adval;

    np = Xnodeptralloc ();
    tp = Xnodeptralloc ();
    np->this = e->cends[0];
    tp->this = e->cends[1];
    np->next = (Xnodeptr *) NULL;
    tp->next = np;
    *T = tp;
    count = 2;

    G->magicnum++;
    e->cends[0]->magiclabel = G->magicnum;
    e->cends[1]->magiclabel = G->magicnum;

    do {
        hit = 0;
        for (np = U; np; np = np->next) {
            n = np->this;
            if (n->magiclabel != G->magicnum && n->mark == 0) {
                adcount = 0;
                adval = 0.0;
                for (ep = n->cadj.head; ep; ep = ep->next) {
                    f = ep->this;
                    if (OTHERCURRENTEND (f, n)->magiclabel
                        == G->magicnum) {
                        adcount++;
                        adval += f->x;
                    }
                }
                if (adcount >= 2 && adval >= 1.0) {
                    tp = Xnodeptralloc ();
                    tp->this = n;
                    tp->next = *T;
                    *T = tp;
                    n->magiclabel = G->magicnum;
                    hit++;
                }
            }
        }
        count += hit;
    } while (hit);

    return count;
}

#ifdef CC_PROTOTYPE_ANSI
static int grow2 (Xgraph *G, Xnodeptr **T, Xedge *e, Xnodeptr *U)
#else
static int grow2 (G, T, e, U)
Xgraph *G;
Xnodeptr **T;
Xedge *e;
Xnodeptr *U;
#endif
{
    Xnodeptr *np, *tp;
    Xnode *n;
    Xedgeptr *ep;
    Xedge *f;
    int count, hit;
    double adval, slack;

    np = Xnodeptralloc ();
    tp = Xnodeptralloc ();
    np->this = e->cends[0];
    tp->this = e->cends[1];
    np->next = (Xnodeptr *) NULL;
    tp->next = np;
    *T = tp;
    count = 2;

    G->magicnum++;
    e->cends[0]->magiclabel = G->magicnum;
    e->cends[1]->magiclabel = G->magicnum;
    slack = 1.0 - e->x;

    do {
        hit = 0;
        for (np = U; np; np = np->next) {
            n = np->this;
            if (n->magiclabel != G->magicnum && n->mark == 0) {
                adval = 0.0;
                for (ep = n->cadj.head; ep; ep = ep->next) {
                    f = ep->this;
                    if (OTHERCURRENTEND (f, n)->magiclabel
                        == G->magicnum) {
                        adval += f->x;
                    }
                }
                if (slack + (1.0 - adval) < 0.5) {
                    tp = Xnodeptralloc ();
                    tp->this = n;
                    tp->next = *T;
                    *T = tp;
                    n->magiclabel = G->magicnum;
                    hit++;
                    slack += (1.0 - adval);
                }
            }
        }
        count += hit;
    } while (hit);

    return count;
}

#ifdef CC_PROTOTYPE_ANSI
static int grabcomponents (Xgraph *G, int z, Xnodeptr *T, Xnodeptr *U,
            Xnodeptr **u1, Xnodeptr **u2)
#else
static int grabcomponents (G, z, T, U, u1, u2)
Xgraph *G;
int z;
Xnodeptr *T, *U, **u1, **u2;
#endif
{
    Xnodeptr *np, *tp, *all = (Xnodeptr *) NULL;
    Xnode *n;
    Xedgeptr *ep;
    int componentcount, k;

    G->magicnum++;
    label_nodeptr_list (T, G->magicnum);

    for (np = U; np; np = np->next) {
        n = np->this;
        if (n->magiclabel != G->magicnum)
            Xadd_nodeptr (&all, n);
        else
            for (ep = n->cadj.head; ep; ep = ep->next)
                if (ep->this->magiclabel == z) {
                    Xadd_nodeptr (&all, n);
                    break;
                }
    }
    if (!all) {
        printf ("Eak in grabcomponents\n");
        return 0;
    }
    G->magicnum++;
    componentcount = 0;
    for (np = all; componentcount <= 2 && np; np = np->next)
        if (np->this->magiclabel != G->magicnum) {
            clique_dfs (G, np->this, z, 0, (Xnodeptr **) NULL);
            componentcount++;
        }
    if (componentcount != 2) {
        Xnodeptr_list_free (all);
        return 0;
    } else {
        G->magicnum++;
        *u1 = (Xnodeptr *) NULL;
        clique_dfs (G, all->this, z, 1, u1);
        for (k = 0, tp = *u1; tp; tp = tp->next) {
            if (tp->this->mark)
                k++;
        }
        if (k < 2 || k % 2 != 0) {
            Xnodeptr_list_free (all);
            Xnodeptr_list_free (*u1);
            *u1 = (Xnodeptr *) NULL;
            return 0;
        }
        np = all->next;
        while (np->this->magiclabel == G->magicnum)
            np = np->next;
        *u2 = (Xnodeptr *) NULL;
        clique_dfs (G, np->this, z, 1, u2);
        for (k = 0, tp = *u2; tp; tp = tp->next)
            if (tp->this->mark)
                k++;
        if (k < 2 || k % 2 != 0) {
            Xnodeptr_list_free (all);
            Xnodeptr_list_free (*u1);
            Xnodeptr_list_free (*u2);
            *u1 = *u2 = (Xnodeptr *) NULL;
            return 0;
        } else {
            Xnodeptr_list_free (all);
            return 1;
        }
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void clique_dfs (Xgraph *G, Xnode *start, int z, int storenodes,
             Xnodeptr **list)
#else
static void clique_dfs (G, start, z, storenodes, list)
Xgraph *G;
Xnode *start;
int z, storenodes;
Xnodeptr **list;
#endif
{
    Xedgeptr *ep;
    Xnodeptr *np;
    Xnode *n, *v;
    Xnodeptr *next, *queue = (Xnodeptr *) NULL;

    start->magiclabel = G->magicnum;
    Xadd_nodeptr (&queue, start);

    while (queue) {
        n = queue->this;
        next = queue->next;
        Xnodeptrfree (queue);
        queue = next;
        if (storenodes) {
            np = Xnodeptralloc ();
            np->this = n;
            np->next = *list;
            *list = np;
        }
        for (ep = n->cadj.head; ep; ep = ep->next) {
            if (ep->this->magiclabel == z) {
                v = OTHERCURRENTEND (ep->this, n);
                if (v->magiclabel != G->magicnum) {
                    v->magiclabel = G->magicnum;
                    Xadd_nodeptr (&queue, v);
                }
            }
        }
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void unscan_remove (Xgraph *G, Xedgeptr **unscan, Xnodeptr *T)
#else
static void unscan_remove (G, unscan, T)
Xgraph *G;
Xedgeptr **unscan;
Xnodeptr *T;
#endif
{
    Xnodeptr *np;
    Xedgeptr *ep, *next;

    G->magicnum++;
    for (np = T; np; np = np->next)
        np->this->magiclabel = G->magicnum;

    for (ep = *unscan, *unscan = (Xedgeptr *) NULL; ep; ep = next) {
        next = ep->next;
        if (ep->this->cends[0]->magiclabel == G->magicnum &&
            ep->this->cends[1]->magiclabel == G->magicnum)
            Xedgeptrfree (ep);
        else {
            ep->next = *unscan;
            *unscan = ep;
        }
    }
}

#ifdef CC_PROTOTYPE_ANSI
static int improve (Xgraph *G, Xnodeptr **u1, Xnodeptr **u2, Xnodeptr **u3,
            Xnodeptr **u4, Xnodeptr **u5)
#else
static int improve (G, u1, u2, u3, u4, u5)
Xgraph *G;
Xnodeptr **u1, **u2, **u3, **u4, **u5;
#endif
{
    int win, gotone = 0;
    Xnodeptr *pick;
    Xnode *v, *w;

    while ((*u5)->next != (Xnodeptr *) NULL) {
        win = grab_from_u5 (G, *u1, *u2, *u3, *u4, *u5, &pick, &v);
        if (!win)
            return gotone;
        gotone = 1;
        if (pick == *u1) {
            remove_from_nodeptr (v, u5);
            Xadd_nodeptr (u3, v);
            while ((*u3)->next != (Xnodeptr *) NULL &&
                   grab_from_mate (G, *u3, *u3, *u4, *u5, &w)) {
                remove_from_nodeptr (w, u3);
                Xadd_nodeptr (u1, w);
            }
        } else {
            remove_from_nodeptr (v, u5);
            Xadd_nodeptr (u4, v);
            while ((*u4)->next != (Xnodeptr *) NULL &&
                   grab_from_mate (G, *u4, *u3, *u4, *u5, &w)) {
                remove_from_nodeptr (w, u4);
                Xadd_nodeptr (u2, w);
            }
        }
    }
    return gotone;
}

#ifdef CC_PROTOTYPE_ANSI
static int grab_from_u5 (Xgraph *G, Xnodeptr *u1, Xnodeptr *u2, Xnodeptr *u3,
            Xnodeptr *u4, Xnodeptr *u5, Xnodeptr **pick, Xnode **v)
#else
static int grab_from_u5 (G, u1, u2, u3, u4, u5, pick, v)
Xgraph *G;
Xnodeptr *u1, *u2, *u3, *u4, *u5, **pick;
Xnode **v;
#endif
{
    Xnodeptr *np;
    Xnode *n;
    double t, best = -1.0;

    for (np = u5; np; np = np->next) {
        n = np->this;
        t = single_crossvalue (G, n, u1, u3, (Xnodeptr *) NULL);
        if (t > best) {
            best = t;
            *pick = u1;
            *v = n;
        }
        t = single_crossvalue (G, n, u2, u4, (Xnodeptr *) NULL);
        if (t > best) {
            best = t;
            *pick = u2;
            *v = n;
        }
    }

    return (best >= 1.0);
}

#ifdef CC_PROTOTYPE_ANSI
static int grab_from_mate (Xgraph *G, Xnodeptr *mate, Xnodeptr *u3,
            Xnodeptr *u4, Xnodeptr *u5, Xnode **w)
#else
static int grab_from_mate (G, mate, u3, u4, u5, w)
Xgraph *G;
Xnodeptr *mate, *u3, *u4, *u5;
Xnode **w;
#endif
{
    Xnodeptr *np;

    for (np = mate; np; np = np->next)
        if (single_crossvalue (G, np->this, u3, u4, u5) <= 1.0) {
            *w = np->this;
            return 1;
        }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int clique_violated (Xgraph *G, Xnodeptr *u1, Xnodeptr *u2,
            Xnodeptr *u3, Xnodeptr *u4, Xnodeptr *u5)
#else
static int clique_violated (G, u1, u2, u3, u4, u5)
Xgraph *G;
Xnodeptr *u1, *u2, *u3, *u4, *u5;
#endif
{
    double y;

    y = crossvalue (G, u1, (Xnodeptr *) NULL, u2) + crossvalue (G, u1, u2, u5) +
        crossvalue (G, u1, (Xnodeptr *) NULL, u4) +
        crossvalue (G, u2, (Xnodeptr *) NULL, u3) +
        clique_slack (G, u3) + clique_slack (G, u4);
    /* printf ("CLIQUE VALUE: %f\n", y); fflush (stdout); */
    return (y < 1.0 - XEPSILON);
}

#ifdef CC_PROTOTYPE_ANSI
static double crossvalue (Xgraph *G, Xnodeptr *s1, Xnodeptr *s2, Xnodeptr *s3)
#else
static double crossvalue (G, s1, s2, s3)
Xgraph *G;
Xnodeptr *s1, *s2, *s3;
#endif
{
    double val = 0.0;
    Xnodeptr *np;
    Xnode *n;
    Xedgeptr *ep;
    Xedge *e;

    G->magicnum++;
    for (np = s1; np; np = np->next)
        np->this->magiclabel = G->magicnum;
    if (s2)
        for (np = s2; np; np = np->next)
            np->this->magiclabel = G->magicnum;
    for (np = s3; np; np = np->next) {
        n = np->this;
        for (ep = n->cadj.head; ep; ep = ep->next) {
            e = ep->this;
            if (OTHERCURRENTEND (e, n)->magiclabel == G->magicnum)
                val += e->x;
        }
    }
    return val;
}

#ifdef CC_PROTOTYPE_ANSI
static double single_crossvalue (Xgraph *G, Xnode *v, Xnodeptr *s1,
               Xnodeptr *s2, Xnodeptr *s3)
#else
static double single_crossvalue (G, v, s1, s2, s3)
Xgraph *G;
Xnode *v;
Xnodeptr *s1, *s2, *s3;
#endif
{
    double val = 0.0;
    Xnodeptr *np;
    Xedgeptr *ep;
    Xedge *e;

    G->magicnum++;
    for (np = s1; np; np = np->next)
        np->this->magiclabel = G->magicnum;
    for (np = s2; np; np = np->next)
        np->this->magiclabel = G->magicnum;
    for (np = s3; np; np = np->next)
        np->this->magiclabel = G->magicnum;
    for (ep = v->cadj.head; ep; ep = ep->next) {
        e = ep->this;
        if (OTHERCURRENTEND (e, v)->magiclabel == G->magicnum)
            val += e->x;
    }
    return val;
}

#ifdef CC_PROTOTYPE_ANSI
static double clique_slack (Xgraph *G, Xnodeptr *s)
#else
static double clique_slack (G, s)
Xgraph *G;
Xnodeptr *s;
#endif
{
    double val = 0.0, c = 0.0;
    Xnodeptr *np;
    Xedgeptr *ep;
    Xedge *e;

    G->magicnum++;
    for (np = s; np; np = np->next) {
        np->this->magiclabel = G->magicnum;
        c += 1.0;
    }
    for (np = s; np; np = np->next)
        for (ep = np->this->cadj.head; ep; ep = ep->next) {
            e = ep->this;
            if (e->cends[0]->magiclabel == G->magicnum &&
                e->cends[1]->magiclabel == G->magicnum)
                val += e->x;
        }
    val *= 0.5;
    return c - 1.0 - val;
}

#ifdef CC_PROTOTYPE_ANSI
static int clique_fringe (Xnode *n, int ct)
#else
static int clique_fringe (n, ct)
Xnode *n;
int ct;
#endif
{
    Xedgeptr *ep;
    Xedge *e;

    for (ep = n->cadj.head; ep; ep = ep->next) {
        e = ep->this;
        if (e->x <= ONEMINUS ||
            OTHERCURRENTEND (e, n)->Tmark != ct)
            return 0;
    }
    return 1;
}

#ifdef CC_PROTOTYPE_ANSI
static void remove_from_nodeptr (Xnode *n, Xnodeptr **list)
#else
static void remove_from_nodeptr (n, list)
Xnode *n;
Xnodeptr **list;
#endif
{
    Xnodeptr *np, *next;

    for (np = *list, *list = (Xnodeptr *) NULL; np; np = next) {
        next = np->next;
        if (np->this == n)
            Xnodeptrfree (np);
        else {
            np->next = *list;
            *list = np;
        }
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void add_nodeptr_list (Xnodeptr **addto, Xnodeptr *takefrom)
#else
static void add_nodeptr_list (addto, takefrom)
Xnodeptr **addto, *takefrom;
#endif
{
    Xnodeptr *np, *tp;

    for (np = takefrom; np; np = np->next) {
        tp = Xnodeptralloc ();
        tp->this = np->this;
        tp->next = *addto;
        *addto = tp;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void label_nodeptr_list (Xnodeptr *list, int z)
#else
static void label_nodeptr_list (list, z)
Xnodeptr *list;
int z;
#endif
{
    Xnodeptr *np;

    for (np = list; np; np = np->next)
        np->this->magiclabel = z;
}

#ifdef CC_PROTOTYPE_ANSI
static int check_special_cliquetree (Xgraph *G, Xnodeptr *u1, Xnodeptr *u2,
            Xnodeptr *u3, Xnodeptr *u4, Xnodeptr *u5, Xcplane **list, double *x)
#else
static int check_special_cliquetree (G, u1, u2, u3, u4, u5, list, x)
Xgraph *G;
Xnodeptr *u1, *u2, *u3, *u4, *u5;
Xcplane **list;
double *x;
#endif
{
    Xnodeptr *H1 = (Xnodeptr *) NULL, *H2 = (Xnodeptr *) NULL,
             *T = (Xnodeptr *) NULL, *np;
    Xedgeptr *ep, *et, *pteeth = (Xedgeptr *) NULL;
    int nteeth = 0, test;
    Xnode *n;
    Xedge *e;

    add_nodeptr_list (&H1, u1);
    add_nodeptr_list (&H1, u3);

    add_nodeptr_list (&H2, u2);
    add_nodeptr_list (&H2, u4);

    add_nodeptr_list (&T, u3);
    add_nodeptr_list (&T, u4);
    add_nodeptr_list (&T, u5);
    nteeth++;

    G->magicnum++;
    label_nodeptr_list (u1, G->magicnum);
    label_nodeptr_list (u2, G->magicnum);
    label_nodeptr_list (u3, G->magicnum);
    label_nodeptr_list (u4, G->magicnum);
    label_nodeptr_list (u5, G->magicnum);

    for (np = u1; np; np = np->next) {
        n = np->this;
        if (n->mark)
            for (ep = n->cadj.head; ep; ep = ep->next) {
                e = ep->this;
                if (e->x > ONEMINUS &&
                    OTHERCURRENTEND (e, n)->magiclabel != G->magicnum) {
                    et = Xedgeptralloc ();
                    et->this = e;
                    et->next = pteeth;
                    pteeth = et;
                    nteeth++;
                }
            }
    }
    for (np = u2; np; np = np->next) {
        n = np->this;
        if (n->mark)
            for (ep = n->cadj.head; ep; ep = ep->next) {
                e = ep->this;
                if (e->x > ONEMINUS &&
                    OTHERCURRENTEND (e, n)->magiclabel != G->magicnum) {
                    et = Xedgeptralloc ();
                    et->this = e;
                    et->next = pteeth;
                    pteeth = et;
                    nteeth++;
                }
            }
    }
    if (nteeth % 2 == 0) {
        printf ("Even number of teeth in a clique-tree\n");
        Xnodeptr_list_free (H1);
        Xnodeptr_list_free (H2);
        Xnodeptr_list_free (T);
        Xedgeptr_list_free (pteeth);
        return 0;
    } else {
        test = load_special_cliquetree (G, H1, H2, T, pteeth, list, x);
        Xnodeptr_list_free (H1);
        Xnodeptr_list_free (H2);
        Xnodeptr_list_free (T);
        Xedgeptr_list_free (pteeth);
        return test;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static int load_special_cliquetree (Xgraph *G, Xnodeptr *H1, Xnodeptr *H2,
            Xnodeptr *T, Xedgeptr *pteeth, Xcplane **list, double *x)
#else
static int load_special_cliquetree (G, H1, H2, T, pteeth, list, x)
Xgraph *G;
Xnodeptr *H1, *H2, *T;
Xedgeptr *pteeth;
Xcplane **list;
double *x;
#endif
{
    int test;
    Xnodeptr *tooth, *tH1, *tH2, *tT;
    Xnodeptrptr *handles, *teeth;
    Xedgeptr *ep;

    pseudonodelist_to_nodelist (H1, &tH1);
    pseudonodelist_to_nodelist (H2, &tH2);
    pseudonodelist_to_nodelist (T, &tT);

    handles = (Xnodeptrptr *) NULL;
    Xadd_nodeptrptr (&handles, tH1);
    Xadd_nodeptrptr (&handles, tH2);

    teeth = (Xnodeptrptr *) NULL;
    Xadd_nodeptrptr (&teeth, tT);
    for (ep = pteeth; ep; ep = ep->next) {
        tooth = (Xnodeptr *) NULL;
        Xmarktooth (ep->this, &(tooth));
        Xadd_nodeptrptr (&teeth, tooth);
    }

    if (!Xcliquefluff (G, &handles, &teeth)) {
        return 0;
    }
    if (!Xviolated_clique_flow (G, handles, teeth, x)) {
        /* printf ("BANG!\n"); */
        Xfreeteeth (handles);
        Xfreeteeth (teeth);
        return 0;
    }
    test = Xloadcplane (list, (Xnodeptr *) NULL, handles, teeth, 0);
    if (!test) {
        Xfreeteeth (handles);
        Xfreeteeth (teeth);
    }
    return test;
}

#ifdef CC_PROTOTYPE_ANSI
static void pseudonodelist_to_nodelist (Xnodeptr *p, Xnodeptr **l)
#else
static void pseudonodelist_to_nodelist (p, l)
Xnodeptr *p, **l;
#endif
{
    Xnodeptr *mp, *np;

    (*l) = (Xnodeptr *) NULL;
    for (np = p; np; np = np->next)
        for (mp = np->this->base.head; mp; mp = mp->next)
            Xadd_nodeptr (l, mp->this);
}

#ifdef  DEBUG
#ifdef CC_PROTOTYPE_ANSI
static void dump_special_cliquetree (Xgraph *G, Xnodeptr *u1, Xnodeptr *u2,
             Xnodeptr *u3, Xnodeptr *u4, Xnodeptr *u5)
#else
static void dump_special_cliquetree (G, u1, u2, u3, u4, u5)
Xgraph *G;
Xnodeptr *u1, *u2, *u3, *u4, *u5;
#endif
{
    printf ("U1: ");
    nodeptr_print (u1);
    printf ("U2: ");
    nodeptr_print (u2);
    printf ("U3: ");
    nodeptr_print (u3);
    printf ("U4: ");
    nodeptr_print (u4);
    printf ("U5: ");
    nodeptr_print (u5);
}
#endif /* DEBUG */

#ifdef  DEBUG
#ifdef CC_PROTOTYPE_ANSI
static void nodeptr_print (Xgraph *G, Xnodeptr *s)
#else
static void nodeptr_print (G, s)
Xgraph *G;
Xnodeptr *s;
#endif
{
    Xnodeptr *np;

    for (np = s; np; np = np->next)
        printf ("%3d%c ", np->this - G->nodelist, np->this->mark ? '*' : ' ');
    printf ("\n");
}
#endif /* DEBUG */

