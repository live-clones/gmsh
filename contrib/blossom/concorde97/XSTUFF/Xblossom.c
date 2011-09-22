/**************************************************************************/
/*                                                                        */
/* EXPORTED FUNCTIONS:                                                    */
/*                                                                        */
/*  int                                                                   */
/*      Xexactblossoms_run (Xgraph *G, Xcplane **list, double *x),        */
/*      Xexactblossomcheck (Xgraph *G, Xcplane **list, int pseudo,        */
/*            double *x),                                                 */
/*      Xolaf (Xgraph *G, int olaf_select);                               */
/*                                                                        */
/**************************************************************************/

#include "machdefs.h"
#include "util.h"
#include "Xsubtour.h"

#ifdef CC_PROTOTYPE_ANSI

static void
    buildcadj_from_pseudoedgelist (Xgraph *G),
    buildcadj_from_edgelist (Xgraph *G),
    buildpseudonodelist_from_scratch (Xgraph *G),
    removedegreezero (Xgraph *G),
    splitem (Xgraph *G, Xnode *n),
    splitedge (Xgraph *G, Xedge *e, Xnode *n),
    destroysplitgraph (Xgraph *G),
    freesplitcadj (Xgraph *G),
    freesplitedges (Xgraph *G),
    freesplitters (Xgraph *G),
    markcuttree_cut (Xcuttree_node *n, int v, int pseudo),
    marknode (Xnode *n, int v),
    dumpchildren (Xgraph *G, Xcuttree_node *n),
    dump_cuttree (Xcuttree_node *t, Xnode *n),
    T1 (Xgraph *G),
    T2 (Xgraph *G),
    T3 (Xgraph *G),
    T4 (Xgraph *G),
    T5 (Xgraph *G);

static int
    checkcuttree (Xgraph *G, Xcplane **cplanelist, Xcuttree_node *root,
          int pseudo, double *x),
    searchtree (Xgraph *G, Xcplane **cplanelist, Xcuttree_node *n,
          int pseudo, double *x, double *val_last, int *n_last),
    loadcuttree_blossom (Xgraph *G, Xcplane **cplanelist, int v),
    loadcuttree_comb (Xgraph *G, Xcplane **list, int v, double *x),
    cuttree_tooth (Xedge *e, int v),
    isita_fattooth (Xedge *e),
    oneend (Xedge *e, int v);

#else

static void
    buildcadj_from_pseudoedgelist (),
    buildcadj_from_edgelist (),
    buildpseudonodelist_from_scratch (),
    removedegreezero (),
    splitem (),
    splitedge (),
    destroysplitgraph (),
    freesplitcadj (),
    freesplitedges (),
    freesplitters (),
    markcuttree_cut (),
    marknode (),
    dumpchildren (),
    dump_cuttree (),
    T1 (),
    T2 (),
    T3 (),
    T4 (),
    T5 ();

static int
    checkcuttree (),
    searchtree (),
    loadcuttree_blossom (),
    loadcuttree_comb (),
    cuttree_tooth (),
    isita_fattooth (),
    oneend ();

#endif

#ifdef   DEBUG
#ifdef CC_PROTOTYPE_ANSI
static void
    dumpsplitgraph (Xgraph *G);
#else
static void
    dumpsplitgraph ();
#endif
#endif


#define ONEMINUS 0.999999
#define ZEROPLUS 0.000001

static int npseudoedges;

#ifdef CC_PROTOTYPE_ANSI
int Xexactblossoms_run (Xgraph *G, Xcplane **list, double *x)
#else
int Xexactblossoms_run (G, list, x)
Xgraph *G;
Xcplane **list;
double *x;
#endif
{
    return Xexactblossomcheck (G, list, 0, x);
}

#ifdef CC_PROTOTYPE_ANSI
int Xexactblossomcheck (Xgraph *G, Xcplane **cplanelist, int pseudo, double *x)
#else
int Xexactblossomcheck (G, cplanelist, pseudo, x)
Xgraph *G;
Xcplane **cplanelist;
int pseudo;
double *x;
#endif
{
    int i, j, npseudo_save = 0;
    Xnode *n, **pseudo_save = (Xnode **) NULL, **p;
    Xedge *e;
    static Xedge pseudoedgedummy;
    Xcuttree_node *root;

    if (!pseudo) {
        Xloadx (G, x);
        buildpseudonodelist_from_scratch (G);
        for (i = G->nedges, e = G->edgelist; i; i--, e++) {
            e->cends[0] = e->ends[0];
            e->cends[1] = e->ends[1];
            e->stay = 1;
        }
        buildcadj_from_edgelist (G);
    } else {
        pseudo_save = CC_SAFE_MALLOC (G->npseudonodes, Xnode *);
        if (!pseudo_save) {
            fprintf (stderr, "out of memory in Xexactblossomcheck\n");
            exit (1);
        }
        for (n = G->pseudonodelist->next, p = pseudo_save; n; n = n->next, p++)
            *p = n;
        npseudo_save = G->npseudonodes;
    }

    for (n = G->pseudonodelist->next; n; n = n->next) {
        n->pe = (Xedge *) NULL;
        n->mark = 0;
    }
    for (i = G->nedges, e = G->edgelist; i; i--, e++) {
        if (!e->stay) {
            continue;
        } else if (e->x > ONEMINUS) {
            e->splitter = G->nodelist;     /* just to kill the edge */
            e->cends[0]->mark = 1 - e->cends[0]->mark;
            e->cends[1]->mark = 1 - e->cends[1]->mark;
        } else if (e->x < ZEROPLUS) {
            e->splitter = G->nodelist;
        } else {
            e->splitter = (Xnode *) NULL;
        }
    }


    G->pseudoedgelist = &pseudoedgedummy;
    G->pseudoedgelist->next = (Xedge *) NULL;
    npseudoedges = 0;

    G->magicnum++;
    for (n = G->pseudonodelist->next; n; n = n->next)
        if (n->magiclabel != G->magicnum)
            splitem (G, n);

    freesplitcadj (G);
    buildcadj_from_pseudoedgelist (G);
    removedegreezero (G);

    root = Xgomory_hu (G);

    if (root) {
        j = checkcuttree (G, cplanelist, root, pseudo, x);
/*
        printf ("%d exact blossoms\n", j);
        fflush (stdout);
*/
        Xcuttree_free (root);
    } else
        j = 0;

    destroysplitgraph (G);
    if (pseudo) {
        G->npseudonodes = npseudo_save;
        n = G->pseudonodelist;
        for (i = npseudo_save, p = pseudo_save; i; i--, p++) {
            n->next = *p;
            n->next->prev = n;
            n = n->next;
        }
        n->next = (Xnode *) NULL;
        CC_FREE (pseudo_save, Xnode *);
        buildcadj_from_edgelist (G);
    }
    return j;
}

#ifdef CC_PROTOTYPE_ANSI
static void buildcadj_from_pseudoedgelist (Xgraph *G)
#else
static void buildcadj_from_pseudoedgelist (G)
Xgraph *G;
#endif
{
    Xedge *e;
    Xedgeptr *ep;

    for (e = G->pseudoedgelist->next; e; e = e->next) {
        ep = Xedgeptralloc ();
        ep->next = (e->cends[0])->cadj.head;
        ep->this = e;
        (e->cends[0])->cadj.head = ep;
        if ((e->cends[0])->cadj.tail == (Xedgeptr *) NULL)
            (e->cends[0])->cadj.tail = ep;
        ep = Xedgeptralloc ();
        ep->next = (e->cends[1])->cadj.head;
        ep->this = e;
        (e->cends[1])->cadj.head = ep;
        if ((e->cends[1])->cadj.tail == (Xedgeptr *) NULL)
            (e->cends[1])->cadj.tail = ep;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void buildcadj_from_edgelist (Xgraph *G)
#else
static void buildcadj_from_edgelist (G)
Xgraph *G;
#endif
{
    Xedge *e;
    Xedgeptr *ep;
    int i;

    for (i = G->nedges, e = G->edgelist; i; i--, e++) {
        if (!e->stay)
            continue;
        ep = Xedgeptralloc ();
        ep->next = (e->cends[0])->cadj.head;
        ep->this = e;
        (e->cends[0])->cadj.head = ep;
        if ((e->cends[0])->cadj.tail == (Xedgeptr *) NULL)
            (e->cends[0])->cadj.tail = ep;
        ep = Xedgeptralloc ();
        ep->next = (e->cends[1])->cadj.head;
        ep->this = e;
        (e->cends[1])->cadj.head = ep;
        if ((e->cends[1])->cadj.tail == (Xedgeptr *) NULL)
            (e->cends[1])->cadj.tail = ep;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void buildpseudonodelist_from_scratch (Xgraph *G)
#else
static void buildpseudonodelist_from_scratch (G)
Xgraph *G;
#endif
{
    static Xnode pseudonodedummy;
    int i;
    Xnode *n;

    G->pseudonodelist = &pseudonodedummy;
    pseudonodedummy.prev = (Xnode *) NULL;
    pseudonodedummy.next = G->nodelist;
    for (i = 0, n = G->nodelist; i < G->nnodes; i++, n++) {
        n->cadj.head = n->cadj.tail = (Xedgeptr *) NULL;
        n->prev = n - 1;
        n->next = n + 1;
    }
    G->nodelist->prev = G->pseudonodelist;
    G->nodelist[G->nnodes - 1].next = (Xnode *) NULL;
    G->npseudonodes = G->nnodes;
}

#ifdef CC_PROTOTYPE_ANSI
static void removedegreezero (Xgraph *G)
#else
static void removedegreezero (G)
Xgraph *G;
#endif
{
    Xnode *n, *next;

    for (n = G->pseudonodelist->next; n; n = next)
        if (n->cadj.head == (Xedgeptr *) NULL) {
            if ((next = n->next) != (Xnode *) NULL) {
                n->next->prev = n->prev;
                n->prev->next = n->next;
            } else
                n->prev->next = (Xnode *) NULL;
            G->npseudonodes--;
        } else
            next = n->next;
}

#ifdef CC_PROTOTYPE_ANSI
static void splitem (Xgraph *G, Xnode *n)
#else
static void splitem (G, n)
Xgraph *G;
Xnode *n;
#endif
{
    Xedgeptr *ep;
    Xedge *e, *last;
    Xnode *child;

    n->magiclabel = G->magicnum;
    for (ep = n->cadj.head; ep; ep = ep->next) {
        e = ep->this;
        if (!e->splitter) {
            child = OTHERCURRENTEND (e, n);
            if (child->magiclabel != G->magicnum)
                splitem (G, child);
        }
    }
    for (ep = n->cadj.head, last = (Xedge *) NULL; ep; ep = ep->next) {
        e = ep->this;
        if (!e->splitter) {
            if (last)
                splitedge (G, last, n);
            last = e;
        }
    }

    if (last) {
        if (n->mark)
            splitedge (G, last, n);
        else
            splitedge (G, last, OTHERCURRENTEND (last, n));
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void splitedge (Xgraph *G, Xedge *e, Xnode *n)
#else
static void splitedge (G, e, n)
Xgraph *G;
Xedge *e;
Xnode *n;
#endif
{
    Xnode *n1;
    Xedge *e1;

    n->mark = 1 - n->mark;

    n1 = Xnodealloc ();
    n1->magiclabel = 0;
    n1->stacklabel = 0;
    e->splitter = n1;
    n1->pe = e;
    n1->snext = n;              /* points to the end which is marked odd */
    n1->mark = 1;
    n1->cadj.head = n1->cadj.tail = (Xedgeptr *) NULL;

    n1->base.head = Xnodeptralloc ();
    n1->base.tail = n1->base.head;
    n1->base.head->next = (Xnodeptr *) NULL;
    n1->base.head->this = n1;

    n1->next = G->pseudonodelist->next;
    n1->prev = G->pseudonodelist;
    G->pseudonodelist->next->prev = n1;
    G->pseudonodelist->next = n1;
    G->npseudonodes++;


    e1 = Xedgealloc ();
    e1->cends[0] = n;
    e1->cends[1] = n1;
    e1->stay = 1;
    e1->x = 1.0 - e->x;
    e1->next = G->pseudoedgelist->next;
    G->pseudoedgelist->next = e1;
    npseudoedges++;


    e1 = Xedgealloc ();
    e1->cends[0] = OTHERCURRENTEND (e, n);
    e1->cends[1] = n1;
    e1->stay = 1;
    e1->x = e->x;
    e1->next = G->pseudoedgelist->next;
    G->pseudoedgelist->next = e1;
    npseudoedges++;
}

#ifdef CC_PROTOTYPE_ANSI
static void destroysplitgraph (Xgraph *G)
#else
static void destroysplitgraph (G)
Xgraph *G;
#endif
{
    freesplitcadj (G);
    freesplitedges (G);
    freesplitters (G);
}

#ifdef CC_PROTOTYPE_ANSI
static void freesplitcadj (Xgraph *G)
#else
static void freesplitcadj (G)
Xgraph *G;
#endif
{
    Xnode *n;
    Xedgeptr *e, *enext;

    for (n = G->pseudonodelist->next; n; n = n->next) {
        for (e = n->cadj.head; e; e = enext) {
            enext = e->next;
            Xedgeptrfree (e);
        }
        n->cadj.head = n->cadj.tail = (Xedgeptr *) NULL;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void freesplitedges (Xgraph *G)
#else
static void freesplitedges (G)
Xgraph *G;
#endif
{
    Xedge *e, *enext;

    for (e = G->pseudoedgelist->next; e; e = enext) {
        enext = e->next;
        Xedgefree (e);
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void freesplitters (Xgraph *G)
#else
static void freesplitters (G)
Xgraph *G;
#endif
{
    Xnode *n, *nnext, *prev;
    Xnodeptr *np, *npnext;

    for (n = G->pseudonodelist->next, prev = G->pseudonodelist; n; n = nnext) {
        nnext = n->next;
        if (n->pe) {
            prev->next = nnext;
            if (nnext)
                nnext->prev = prev;
            for (np = n->base.head; np; np = npnext) {
                npnext = np->next;
                Xnodeptrfree (np);
            }
            Xnodefree (n);
        } else
            prev = n;
    }
}


#ifdef  DEBUG
#ifdef CC_PROTOTYPE_ANSI
static void dumpsplitgraph (Xgraph *G)
#else
static void dumpsplitgraph (G)
Xgraph *G;
#endif
{
    Xnode *n;
    Xedge *e;
    int i;

    printf ("NODES: %d\n", G->npseudonodes);
    for (n = G->pseudonodelist->next; n; n = n->next) {
        printf ("NODE %d  mark = %d", n - G->nodelist, n->mark);
        if (n->pe)
            printf (" from %d\n", n->pe - G->edgelist);
        else
            printf ("\n");
    }

    printf ("EDGES: %d\n", npseudoedges);
    for (i = 0, e = G->pseudoedgelist->next; e; e = e->next, i++) {
        printf ("(%d %d %f) ", e->cends[0] - G->nodelist,
                e->cends[1] - G->nodelist,
                e->x);
        if (i % 10 == 9)
            printf ("\n");
    }
    if (i % 10)
        printf ("\n");
    fflush (stdout);
}
#endif /* DEBUG */



/***********************************************************************/


#ifdef CC_PROTOTYPE_ANSI
static int checkcuttree (Xgraph *G, Xcplane **cplanelist, Xcuttree_node *root,
            int pseudo, double *x)
#else
static int checkcuttree (G, cplanelist, root, pseudo, x)
Xgraph *G;
Xcplane **cplanelist;
Xcuttree_node *root;
int pseudo;
double *x;
#endif
{
    int nviolated;
    int n_last = 0;
    double val_last = 1.0;

    if (x == (double *) NULL) {
        printf ("need x vector in checkcuttree\n");
        fflush (stdout);
        return 0;
    }

    nviolated = searchtree (G, cplanelist, root, pseudo, x, &val_last, &n_last);
    return nviolated;
}


#ifdef CC_PROTOTYPE_ANSI
static int searchtree (Xgraph *G, Xcplane **cplanelist, Xcuttree_node *n,
            int pseudo, double *x, double *val_last, int *n_last)
#else
static int searchtree (G, cplanelist, n, pseudo, x, val_last, n_last)
Xgraph *G;
Xcplane **cplanelist;
Xcuttree_node *n;
int pseudo;
double *x;
double *val_last;               /* these guys are a hack to try to stop
                                 * repeats */
int *n_last;
#endif
{
    Xcuttree_node *c;
    int i = 0;

    if (n->ndescendants % 2 == 1  &&  n->ndescendants > 1  ) {
        if (n->cutval < 1.0 - XBLOTOLERANCE) {
            G->magicnum++;
            markcuttree_cut (n, G->magicnum, pseudo);
            if (pseudo) {
                i += loadcuttree_comb (G, cplanelist, G->magicnum, x);
            } else
                i += loadcuttree_blossom (G, cplanelist, G->magicnum);
        }
    }
    for (c = n->child; c; c = c->sibling)
        i += searchtree (G, cplanelist, c, pseudo, x, val_last, n_last);

    return i;
}


#ifdef CC_PROTOTYPE_ANSI
static void markcuttree_cut (Xcuttree_node *n, int v, int pseudo)
#else
static void markcuttree_cut (n, v, pseudo)
Xcuttree_node *n;
int v, pseudo;
#endif
{
    Xcuttree_node *c;
    Xnodeptr *np;

    for (np = n->nlist.head; np; np = np->next)
        if (pseudo) {
            marknode (np->this, v);
        } else
            np->this->magiclabel = v;

    for (c = n->child; c; c = c->sibling)
        markcuttree_cut (c, v, pseudo);
}

#ifdef CC_PROTOTYPE_ANSI
static int loadcuttree_blossom (Xgraph *G, Xcplane **cplanelist, int v)
#else
static int loadcuttree_blossom (G, cplanelist, v)
Xgraph *G;
Xcplane **cplanelist;
int v;
#endif
{
    int i, test;
    Xedge *e;
    Xnode *n;
    Xnodeptr *handle, *np;
    Xedgeptr *teeth, *ep;

    teeth = (Xedgeptr *) NULL;
    for (i = G->nedges, e = G->edgelist; i; i--, e++)
        if (oneend (e, v) && cuttree_tooth (e, v)) {
            ep = Xedgeptralloc ();
            ep->this = e;
            ep->next = teeth;
            teeth = ep;
        }
    handle = (Xnodeptr *) NULL;
    for (i = G->nnodes, n = G->nodelist; i; i--, n++)
        if (n->magiclabel == v) {
            np = Xnodeptralloc ();
            np->this = n;
            np->next = handle;
            handle = np;
        }
    test = Xtemp_doblossom (G, cplanelist, handle, teeth);
    Xedgeptr_list_free (teeth);
    return test;
}

#ifdef CC_PROTOTYPE_ANSI
static int loadcuttree_comb (Xgraph *G, Xcplane **cplanelist, int v, double *x)
#else
static int loadcuttree_comb (G, cplanelist, v, x)
Xgraph *G;
Xcplane **cplanelist;
int v;
double *x;
#endif
{
    int i, nteeth, test, hit = 0, countcheck = 1;
    Xnode *n;
    Xedge *e;
    Xnodeptr *np, *handle;
    Xnodeptrptr *teeth, *ntp;


    for (i = G->nedges, e = G->edgelist; i; i--, e++) {
        if (e->stay && oneend (e, v) &&
            cuttree_tooth (e, v) && isita_fattooth (e)) {
            hit = 1;
            break;
        }
    }
    if (!hit)
        return 0;

    handle = (Xnodeptr *) NULL;
    for (i = G->nnodes, n = G->nodelist; i; i--, n++)
        if (n->magiclabel == v) {
            np = Xnodeptralloc ();
            np->this = n;
            np->next = handle;
            handle = np;
        }
    teeth = (Xnodeptrptr *) NULL;
    for (nteeth = 0, i = G->nedges, e = G->edgelist; i; i--, e++) {
        if (!e->stay)
            continue;
        if (oneend (e, v) && cuttree_tooth (e, v)) {
            nteeth++;
            ntp = Xnodeptrptralloc ();
            ntp->this = (Xnodeptr *) NULL;
            ntp->next = teeth;
            teeth = ntp;
            Xmarktooth (e, &(ntp->this));
        }
    }

    Xcleancomb (G, &handle, &teeth, &nteeth, x);
    if (!Xtemp_combfluff (G, &handle, &teeth))
        return 0;
    test = Xloadcplane (cplanelist, handle, (Xnodeptrptr *) NULL, teeth,
                        countcheck);
    if (!test) {
        Xnodeptr_list_free (handle);
        for (ntp = teeth; ntp; ntp = ntp->next)
            Xnodeptr_list_free (ntp->this);
        Xnodeptrptr_list_free (teeth);
    }
    return test;
}

#ifdef CC_PROTOTYPE_ANSI
static int cuttree_tooth (Xedge *e, int v)
#else
static int cuttree_tooth (e, v)
Xedge *e;
int v;
#endif
{
    if (e->x > ONEMINUS)
        return 1;
    if (e->x < ZEROPLUS)
        return 0;

    if (e->splitter->magiclabel == v) {
        if (e->splitter->snext->magiclabel == v)
            return 0;
        else
            return 1;
    } else {
        if (e->splitter->snext->magiclabel == v)
            return 1;
        else
            return 0;
    }

    /* David: is this the same as return (e->splitter->magiclabel == v) ^
     * (e->splitter->snext->magiclabel == v)   */
}

#ifdef CC_PROTOTYPE_ANSI
static int isita_fattooth (Xedge *e)
#else
static int isita_fattooth (e)
Xedge *e;
#endif
{
    return (e->cends[0]->base.head->next ||
            e->cends[1]->base.head->next);
}

#ifdef CC_PROTOTYPE_ANSI
static int oneend (Xedge *e, int v)
#else
static int oneend (e, v)
Xedge *e;
int v;
#endif
{
    if ((e->ends[0]->magiclabel == v && e->ends[1]->magiclabel != v) ||
        (e->ends[0]->magiclabel != v && e->ends[1]->magiclabel == v))
        return 1;
    else
        return 0;
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
static void dumpchildren (Xgraph *G, Xcuttree_node *n)
#else
static void dumpchildren (G, n)
Xgraph *G;
Xcuttree_node *n;
#endif
{
    Xcuttree_node *c;
    Xnodeptr *cp;

    for (cp = n->nlist.head; cp; cp = cp->next) {
        printf ("%d ", (int) (cp->this - G->nodelist));
        if (cp->this->pe)
            printf ("splits  %d = (%d %d) ",
                        (int) (cp->this->pe - G->edgelist),
                        (int) (cp->this->pe->ends[0] - G->nodelist),
                        (int) (cp->this->pe->ends[1] - G->nodelist));
    }
    printf ("Special: %d\n", (int) (n->special - G->nodelist));
    for (c = n->child; c; c = c->sibling)
        dumpchildren (G, c);
    fflush (stdout);
}

#ifdef CC_PROTOTYPE_ANSI
static void dump_cuttree (Xcuttree_node *t, Xnode *n)
#else
static void dump_cuttree (t, n)
Xcuttree_node *t;
Xnode *n;
#endif
{
    Xcuttree_node *p;
    Xnodeptr *pn;

    printf ("(%f, %d, %d, <", t->cutval, t->ndescendants,
                   (int) (t->special - n));
    for (pn = t->nlist.head; pn; pn = pn->next)
        printf ("%d ", (int) (pn->this - n));
    printf ("> )\n");
    for (p = t->child; p; p = p->sibling)
        dump_cuttree (p, n);
    printf ("*");
    fflush (stdout);
}

/**********************************************************************/

#ifdef CC_PROTOTYPE_ANSI
int Xolaf (Xgraph *G, int olaf_select)
#else
int Xolaf (G, olaf_select)
Xgraph *G;
int olaf_select;
#endif
{
    Xnode *n;
    int oldpseudonodes = G->npseudonodes;

    for (n = G->pseudonodelist->next; n; n = n->next)
        n->Tmark = 0;

    switch (olaf_select) {
    case 1:
        T1 (G);
        T2 (G);
        T3 (G);
        break;
    case 2:
        T1 (G);
        T4 (G);
        T3 (G);
        break;
    case 3:
        T1 (G);
        T5 (G);
        T3 (G);
        break;
    case 4:
        T1 (G);
        T4 (G);
        T5 (G);
        break;
    default:
        printf ("Hey pal, don't call olaf with %d\n", olaf_select);
        break;
    }
    return oldpseudonodes - G->npseudonodes;
}

#ifdef CC_PROTOTYPE_ANSI
static void T1 (Xgraph *G)
#else
static void T1 (G)
Xgraph *G;
#endif
{
    int i;
    Xedge *e;
    Xnode *u, *v;

    for (e = G->edgelist, i = G->nedges; i; e++, i--) {
        if (e->stay && e->x == 1.0) {
            u = e->cends[0];
            v = e->cends[1];
            if (Xrepeat_1_shrink (G, u, e) + Xrepeat_1_shrink (G, v, e)) {
                u->Tmark = 1;
                v->Tmark = 1;
            }
        }
    }
}


#ifdef CC_PROTOTYPE_ANSI
static void T2 (Xgraph *G)
#else
static void T2 (G)
Xgraph *G;
#endif
{
    int i;
    Xedge *e, *f, *g;
    Xedgeptr *ep;
    Xnode *u, *v, *w;

    for (e = G->edgelist, i = G->nedges; i; e++, i--) {
        if (e->stay && e->x == 1.0 && !(u = e->cends[0])->Tmark
            && !(v = e->cends[1])->Tmark) {
            for (ep = u->cadj.head; ep && !u->Tmark; ep = ep->next) {
                f = ep->this;
                w = OTHERCURRENTEND (f, u);
                if (!w->Tmark && (g = Xcurrentedge (v, w)) != (Xedge *) NULL)
                    if (f->x + g->x > 1.0 - XEPSILON) {
                        Xsimpleshrink (G, u, v);
                        u->Tmark = 1;
                        w->Tmark = 1;
                    }
            }
        }
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void T3 (Xgraph *G)
#else
static void T3 (G)
Xgraph *G;
#endif
{
    int i;
    Xedge *c, *d, *e, *f, *g, *h;
    Xedgeptr *ep, *ep2;
    Xnode *u, *v, *w, *x;

    for (e = G->edgelist, i = G->nedges; i; e++, i--) {
        /* e->x == 1 remove */
        if (e->stay && !(u = e->cends[0])->Tmark
            && !(w = e->cends[1])->Tmark) {
            for (ep = u->cadj.head; ep && !u->Tmark; ep = ep->next) {
                f = ep->this;
                v = OTHERCURRENTEND (f, u);
                if (!v->Tmark) {
                    for (ep2 = w->cadj.head; ep2 &&
                         !w->Tmark; ep2 = ep2->next) {
                        g = ep2->this;
                        x = OTHERCURRENTEND (g, w);
                        if (!x->Tmark &&
                            x != v &&
                            (h = Xcurrentedge (v, x)) != (Xedge *) NULL &&
                            (d = Xcurrentedge (u, x)) != (Xedge *) NULL &&
                            (c = Xcurrentedge (w, v)) != (Xedge *) NULL &&
                            c->x + d->x + e->x + f->x + g->x + h->x >=
                                                           3.0 - XEPSILON) {
                            Xsimpleshrink (G, u, w);
                            Xsimpleshrink (G, u, v);
                            Xsimpleshrink (G, u, x);
                            u->Tmark = 1;
                            w->Tmark = 1;
                            v->Tmark = 1;
                            x->Tmark = 1;
                        }
                    }
                }
            }
        }
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void T4 (Xgraph *G)
#else
static void T4 (G)
Xgraph *G;
#endif
{
    int i;
    Xedge *e, *f, *g, *h;
    Xedgeptr *ep, *ep2;
    Xnode *u, *v, *w, *x;

    for (e = G->edgelist, i = G->nedges; i; e++, i--) {
        if (e->stay && e->x == 1.0 && !(u = e->cends[0])->Tmark
            && !(w = e->cends[1])->Tmark) {
            for (ep = u->cadj.head; ep && !u->Tmark; ep = ep->next) {
                f = ep->this;
                v = OTHERCURRENTEND (f, u);
                if (!v->Tmark) {
                    for (ep2 = w->cadj.head; ep2 &&
                         !w->Tmark; ep2 = ep2->next) {
                        g = ep2->this;
                        x = OTHERCURRENTEND (g, w);
                        if (!x->Tmark &&
                            x != v &&
                            f->x + g->x == 1.0 &&
                            (h = Xcurrentedge (v, x)) != (Xedge *) NULL &&
                            h->x == 1.0) {
                            Xsimpleshrink (G, u, w);
                            Xsimpleshrink (G, v, x);
                            u->Tmark = 1;
                            w->Tmark = 1;
                            v->Tmark = 1;
                            x->Tmark = 1;
                        }
                    }
                }
            }
        }
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void T5 (Xgraph *G)
#else
static void T5 (G)
Xgraph *G;
#endif
{
    int i;
    Xedge *e, *f, *g;
    Xedgeptr *ep;
    Xnode *u, *v, *w;

    for (e = G->edgelist, i = G->nedges; i; e++, i--) {
        if (e->stay && e->x == 1.0 && !(u = e->cends[0])->Tmark
            && !(v = e->cends[1])->Tmark) {
            for (ep = u->cadj.head; ep && !u->Tmark; ep = ep->next) {
                f = ep->this;
                w = OTHERCURRENTEND (f, u);
                if (!w->Tmark && (g = Xcurrentedge (v, w)) != (Xedge *) NULL)
                    if (f->x + g->x <= 0.5 + XEPSILON) {
                        Xsimpleshrink (G, u, v);
                        u->Tmark = 1;
                        w->Tmark = 1;
                    }
            }
        }
    }
}
