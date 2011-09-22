/**************************************************************************/
/*                                                                        */
/* EXPORTED FUNCTIONS:                                                    */
/*                                                                        */
/*    int shrinkprocess ();                                               */
/*    void buildpseudonodelist ();                                        */
/*    void buildpseudonodenumbers ();                                     */
/*    void destroypseudonodelist ();                                      */
/*    void dumppseudograph ();                                            */
/*    void dumppseudograph_edgelist ()                                    */
/*    void simpleshrink ();                                               */
/*    void rebuildcadj ();                                                */
/*                                                                        */
/**************************************************************************/

#include "machdefs.h"
#include "Xsubtour.h"

#ifdef CC_PROTOTYPE_ANSI

static void
    markedge (Xgraph *G, Xedge *e),
    marknode (Xnode *n, int v),
    deletepseudonode (Xgraph *G, Xnode *),
    destroynode (Xnode *),
    mergebase (Xnode *, Xnode *),
    rebuildnodecadj (Xnode *);

static int
    mergeadj (Xgraph *G, Xcplane **, Xnode *, Xnode *, Xnode **, int);

#else

static void
    markedge (),
    marknode (),
    deletepseudonode (),
    destroynode (),
    mergebase (),
    rebuildnodecadj ();

static int
    mergeadj ();

#endif

#ifdef CC_PROTOTYPE_ANSI
void Xbuildpseudonodelist (Xgraph *G, int all)
#else
void Xbuildpseudonodelist (G, all)
Xgraph *G;
int all;
#endif
{
    int i;
    Xnode *n;
    Xedge *e;
    Xedgeptr *e1;
    static Xnode pseudodummy;

    G->pseudonodelist = &pseudodummy;
    pseudodummy.prev = (Xnode *) NULL;
    pseudodummy.next = G->nodelist;
    for (i = 0, n = G->nodelist; i < G->nnodes; i++, n++) {
        n->base.head = Xnodeptralloc ();
        n->base.tail = n->base.head;
        n->base.head->next = (Xnodeptr *) NULL;
        n->base.head->this = n;
        n->cadj.head = n->cadj.tail = (Xedgeptr *) NULL;
        n->prev = n - 1;
        n->next = n + 1;
    }
    G->nodelist->prev = G->pseudonodelist;
    G->nodelist[G->nnodes - 1].next = (Xnode *) NULL;

    for (i = G->nedges, e = G->edgelist; i; i--, e++)
        if (all || e->x > 0.00001) {    /* 0.0 */
            e->stay = 1;
            e->cends[0] = e->ends[0];
            e->cends[1] = e->ends[1];
            e1 = Xedgeptralloc ();
            e1->next = (e->cends[0])->cadj.head;
            e1->this = e;
            (e->cends[0])->cadj.head = e1;
            if ((e->cends[0])->cadj.tail == (Xedgeptr *) NULL)
                (e->cends[0])->cadj.tail = e1;
            e1 = Xedgeptralloc ();
            e1->next = (e->cends[1])->cadj.head;
            e1->this = e;
            (e->cends[1])->cadj.head = e1;
            if ((e->cends[1])->cadj.tail == (Xedgeptr *) NULL)
                (e->cends[1])->cadj.tail = e1;
        } else
            e->stay = 0;
    G->npseudonodes = G->nnodes;
}

#ifdef CC_PROTOTYPE_ANSI
void Xbuildpseudonodenumbers (Xgraph *G)
#else
void Xbuildpseudonodenumbers (G)
Xgraph *G;
#endif
{
    int i = 0;
    Xnode *n;

    for (n = G->pseudonodelist->next; n; n = n->next, i++)
        n->pseudonumber = i;
}

#ifdef CC_PROTOTYPE_ANSI
void Xdumppseudograph (Xgraph *G)
#else
void Xdumppseudograph (G)
Xgraph *G;
#endif
{
    Xnode *n;
    Xedge *e;
    Xedgeptr *ep;
    int i;

    printf ("PSEUDOGRAPH:\n");
    printf ("nnodes = %d  nodes: ", G->npseudonodes);
    for (i = 0, n = G->pseudonodelist->next; n; n = n->next, i++) {
        printf (" %d", (int) (n - G->nodelist));
        if (i % 10 == 9)
            printf ("\n");
    }
    if (i % 10)
        printf ("\n");
    for (n = G->pseudonodelist->next; n; n = n->next) {
        printf ("node %d: ", (int) (n - G->nodelist));
        for (ep = n->cadj.head; ep; ep = ep->next) {
            e = ep->this;
            if (e->stay)
                printf (" (%d, %d, %.2f)",
                        (int) (e->cends[0] - G->nodelist),
                        (int) (e->cends[1] - G->nodelist),
                        e->x);
        }
/*
        printf ("  base: ");
        for (np = n->base.head; np; np = np->next)
            printf ("%d ", (int) (np->this - G->nodelist));
*/
        printf ("\n");
    }
    fflush (stdout);
}

#ifdef CC_PROTOTYPE_ANSI
void Xdumppseudograph_edgelist (Xgraph *G)
#else
void Xdumppseudograph_edgelist (G)
Xgraph *G;
#endif
{
    Xnode *n;
    Xedge *e;
    Xedgeptr *ep;
    int count;

    printf ("PSEUDOGRAPH EDGELIST:\n");
    Xbuildpseudonodenumbers (G);
    for (count = 0, n = G->pseudonodelist->next; n; n = n->next)
        for (ep = n->cadj.head; ep; ep = ep->next) {
            e = ep->this;
            if (e->stay)
                count++;
        }
    printf ("%d %d\n", G->npseudonodes, count / 2);
    G->magicedgenum++;
    for (n = G->pseudonodelist->next; n; n = n->next)
        for (ep = n->cadj.head; ep; ep = ep->next) {
            e = ep->this;
            if (e->stay && e->magiclabel != G->magicedgenum) {
                e->magiclabel = G->magicedgenum;
                printf ("%d %d %f\n",
                        e->cends[0]->pseudonumber,
                        e->cends[1]->pseudonumber,
                        e->x);
            }
        }

    fflush (stdout);
}

#ifdef CC_PROTOTYPE_ANSI
void Xdestroypseudonodelist (Xgraph *G)
#else
void Xdestroypseudonodelist (G)
Xgraph *G;
#endif
{
    Xnode *n;

    for (n = G->pseudonodelist->next; n; n = n->next) {
        destroynode (n);
    }
    G->npseudonodes = 0;
}

#ifdef CC_PROTOTYPE_ANSI
static void destroynode (Xnode *n)
#else
static void destroynode (n)
Xnode *n;
#endif
{
    Xedgeptr *e, *enext;
    Xnodeptr *np, *npnext;


    for (e = n->cadj.head; e; e = enext) {
        enext = e->next;
        Xedgeptrfree (e);
    }
    for (np = n->base.head; np; np = npnext) {
        npnext = np->next;
        Xnodeptrfree (np);
    }
}

#ifdef CC_PROTOTYPE_ANSI
int Xshrinkprocess (Xgraph *G, Xcplane **list)
#else
int Xshrinkprocess (G, list)
Xgraph *G;
Xcplane **list;
#endif
{
    Xnode *stack, headstack, *n1, *n2;
    int i, returnval = 0;
    Xedge *e;

    stack = &headstack;
    stack->snext = (Xnode *) NULL;

    for (i = G->nedges, e = G->edgelist; i; e++, i--) {
        if (G->npseudonodes <= 3)
            return returnval;
        if (!e->stay)
            continue;
        if (e->x < 1.0 - XEPSILON)
            continue;
        if (e->x > 1.0 + XEPSILON) {
            markedge (G, e);
            returnval += Xloadcplane_cut (G, list, G->magicnum);
        }
        n1 = e->cends[0];
        e->cends[1]->snext = stack;
        stack = e->cends[1];
        n1->stacklabel = ++(G->stacknum);
        do {
            if (G->npseudonodes <= 3)
                return returnval;
            n2 = stack;
            stack = stack->snext;

            mergebase (n1, n2);
            returnval += mergeadj (G, list, n1, n2, &stack, 1);
            deletepseudonode (G, n2);
        } while (stack != &headstack);
    }
    return returnval;
}

#ifdef CC_PROTOTYPE_ANSI
void Xsimpleshrink (Xgraph *G, Xnode *n1, Xnode *n2)
#else
void Xsimpleshrink (G, n1, n2)
Xgraph *G;
Xnode *n1, *n2;
#endif
{
    Xnode dummystack, *stack, *n3;
    Xedgeptr *e;

    stack = &dummystack;
    mergebase (n1, n2);
    mergeadj (G, (Xcplane **) NULL, n1, n2, &stack, 0);
          /* since repeat = 0, dont load */
    deletepseudonode (G, n2);
    for (e = n1->cadj.head; e; e = e->next)
        if (e->this->stay) {
            n3 = OTHERCURRENTEND (e->this, n1);
            rebuildnodecadj (n3);
        }
    rebuildnodecadj (n1);
}

#ifdef CC_PROTOTYPE_ANSI
static void markedge (Xgraph *G, Xedge *e)
#else
static void markedge (G, e)
Xgraph *G;
Xedge *e;
#endif
{
    G->magicnum++;
    marknode (e->cends[0], G->magicnum);
    marknode (e->cends[1], G->magicnum);
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
static void mergebase (Xnode *n1, Xnode *n2)
#else
static void mergebase (n1, n2)
Xnode *n1, *n2;
#endif
{
    n1->base.tail->next = n2->base.head;
    n1->base.tail = n2->base.tail;
}

#ifdef CC_PROTOTYPE_ANSI
static int mergeadj (Xgraph *G, Xcplane **list, Xnode *n1, Xnode *n2,
                     Xnode **pstack, int repeat)
#else
static int mergeadj (G, list, n1, n2, pstack, repeat)
Xgraph *G;
Xcplane **list;
Xnode *n1, *n2, **pstack;
int repeat;
#endif
{
    Xedgeptr *e, *memo;
    Xnode *stack, *n3;
    int returnval = 0;

    stack = *pstack;

    for (e = n2->cadj.head; e != (Xedgeptr *) NULL; e = e->next) {
        if (!e->this->stay)
            continue;
        if (OTHERCURRENTEND (e->this, n2) == n1)
            e->this->stay = 0;
        else
            (OTHERCURRENTEND (e->this, n2))->pe = (Xedge *) NULL;
    }

    for (e = n1->cadj.head; e != (Xedgeptr *) NULL; e = e->next)
        if (e->this->stay)
            (OTHERCURRENTEND (e->this, n1))->pe = e->this;

    for (e = n2->cadj.head; e != (Xedgeptr *) NULL;) {
        if (!e->this->stay) {
            memo = e;
            e = e->next;
            Xedgeptrfree (memo);
        } else if ((n3 = (OTHERCURRENTEND (e->this, n2)))->pe
                      != (Xedge *) NULL) {
            n3->pe->x += e->this->x;
            n3->pe->rc += e->this->rc;
            e->this->stay = 0;
            memo = e;
            e = e->next;
            Xedgeptrfree (memo);
            if (n3->pe->x > 1.0 + XEPSILON && repeat) {
                markedge (G, n3->pe);
                returnval += Xloadcplane_cut (G, list, G->magicnum);
                if (n3->stacklabel != G->stacknum) {
                    n3->snext = stack;
                    stack = n3;
                    n3->stacklabel = G->stacknum;
                }
            }
            if (n3->pe->x > 1.0 - XEPSILON &&
                n3->stacklabel != G->stacknum && repeat) {
                n3->snext = stack;
                stack = n3;
            }
        } else {
            n1->cadj.tail->next = e;
            n1->cadj.tail = e;
            if (e->this->cends[0] == n2)
                e->this->cends[0] = n1;
            else
                e->this->cends[1] = n1;
            e = e->next;
        }
    }
    n1->cadj.tail->next = (Xedgeptr *) NULL;
    return returnval;
}

#ifdef CC_PROTOTYPE_ANSI
static void deletepseudonode (Xgraph *G, Xnode *n2)
#else
static void deletepseudonode (G, n2)
Xgraph *G;
Xnode *n2;
#endif
{
    n2->prev->next = n2->next;
    if (n2->next != (Xnode *) NULL)
        n2->next->prev = n2->prev;
    G->npseudonodes--;
}

#ifdef CC_PROTOTYPE_ANSI
void Xrebuildcadj (Xgraph *G)
#else
void Xrebuildcadj (G)
Xgraph *G;
#endif
{
    Xnode *n;

    for (n = G->pseudonodelist->next; n; n = n->next)
        rebuildnodecadj (n);
}

#ifdef CC_PROTOTYPE_ANSI
static void rebuildnodecadj (Xnode *n)
#else
static void rebuildnodecadj (n)
Xnode *n;
#endif
{
    Xedgeptr *e, *olde, *memo;

    olde = n->cadj.head;
    while (olde && !olde->this->stay) {
        memo = olde;
        olde = olde->next;
        Xedgeptrfree (memo);
    }
    n->cadj.head = olde;
    if (!olde)
        return;

    e = olde->next;
    while (e) {
        if (!e->this->stay) {
            olde->next = e->next;
            memo = e;
            e = e->next;
            Xedgeptrfree (memo);
        } else {
            olde = e;
            e = e->next;
        }
    }
    n->cadj.tail = olde;
}

#ifdef CC_PROTOTYPE_ANSI
int Xheavy_edge_cuts (Xgraph *G, Xcplane **list, double *x)
#else
int Xheavy_edge_cuts (G, list, x)
Xgraph *G;
Xcplane **list;
double *x;
#endif
{
    int cnt;

    Xloadx (G, x);
    Xbuildpseudonodelist (G, 0);
    cnt = Xshrinkprocess (G, list);
    Xdestroypseudonodelist (G);
    return cnt;
}
