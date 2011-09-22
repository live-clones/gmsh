/**************************************************************************/
/*                                                                        */
/* EXPORTED FUNCTIONS:                                                    */
/*                                                                        */
/*    void                                                                */
/*        Xlocalshrink_a (),                                              */
/*        Xlocalshrink_b (),                                              */
/*        Xlocalshrink_c (),                                              */
/*        Xadd_tooth ();                                                  */
/*        Xmarktooth ();                                                  */
/*        Xmarktoothend ();                                               */
/*                                                                        */
/*    int                                                                 */
/*        Xlocalcombs (),                                                 */
/*        Xglobalcombs (),                                                */
/*        Xblockcombs (),                                                 */
/*        XTmark_components (),                                           */
/*        Xrepeat_1_shrink (),                                            */
/*        Xbasiccliques (),                                               */
/*        Xsearchbasiccliques (),                                         */
/*        Xbasicclique ();                                                */
/*                                                                        */
/*    Xedge                                                               */
/*        *Xcurrentedge (Xnode *n1, Xnode *n2);                           */
/*                                                                        */
/**************************************************************************/

#include "machdefs.h"
#include "util.h"
#include "Xsubtour.h"

#define BLOTOLERANCE .01


#ifdef CC_PROTOTYPE_ANSI

static void
    block_biconnect (Xgraph *G, Xnode *v, Xnode *u, int *lastnumber,
          Xnode ***top_pointer, Xblock **tblock, Xcutnode **tcut,
          int count_cut),
    dfs_Tmark (Xnode *start, int t),
    blockweight (Xgraph *G, Xblock *b),
    blockone (Xgraph *G, Xblock *b),
    buildcutnodes (Xgraph *G),
    buildallneighbors (void),
    buildneighbors (Xblock *b),
    freeblocklist (void),
    freecutnodelist (void),
    handlesearch (Xgraph *G, Xcplane **cplanelist, double *x,
          int *combcount, int *searchcount);

static int
    blockcombs_work (Xgraph *G, Xcplane **cplanelist, int pseudo,
          double *x),
    localcombs_work (Xgraph *G, Xcplane **cplanelist,
          Xnode *startnode, double *x, int pseudo),
    analyze_component (Xgraph *G, Xcplane **cplanelist, Xnode *n,
          int first, Xnode **nodestack, double *x),
    connectedhandles (Xgraph *G, Xcplane **cplanelist, double *x),
    processhandle (Xgraph *G, Xcplane **cplanelist, double *x),
    markblock (Xblock *b, Xcutnode *c, Xnodeptr **list),
    component_basicclique (Xgraph *G, Xcplane **list, Xnode *n, int first,
          Xnode **nodestack, double *x),
    combslack (Xgraph *G, Xblock *handle, Xblock *fixtooth, double *slack,
          Xnodeptrptr **teeth);

static double
    hoodweight (Xgraph *G, Xblock *b, Xnode *n);

static Xnode
    *globalshrink (Xgraph *G);

#else

static void
    block_biconnect (),
    dfs_Tmark (),
    blockweight (),
    blockone (),
    buildcutnodes (),
    buildallneighbors (),
    buildneighbors (),
    freeblocklist (),
    freecutnodelist (),
    handlesearch ();

static int
    blockcombs_work (),
    localcombs_work (),
    analyze_component (),
    connectedhandles (),
    processhandle (),
    markblock (),
    component_basicclique (),
    combslack ();

static double
    hoodweight ();

static Xnode
    *globalshrink ();

#endif

#define FMPMAX 25
#define SEARCHMAX 500           /* Was 5000 */
static int nblocks, ncutnodes;
static Xblock *blocklist;
static Xcutnode *cutnodelist;

#ifdef CC_PROTOTYPE_ANSI
int Xblockcombs (Xgraph *G, Xcplane **list, double *x)
#else
int Xblockcombs (G, list, x)
Xgraph *G;
Xcplane **list;
double *x;
#endif
{
    return blockcombs_work (G, list, 0, x);
}

#ifdef CC_PROTOTYPE_ANSI
int Xlocalcombs (Xgraph *G, Xcplane **list, double *x)
#else
int Xlocalcombs (G, list, x)
Xgraph *G;
Xcplane **list;
double *x;
#endif
{
    return localcombs_work (G, list, (Xnode *) NULL, x, 0);

}

#ifdef CC_PROTOTYPE_ANSI
static int localcombs_work (Xgraph *G, Xcplane **cplanelist,
            Xnode *startnode, double *x, int pseudo)
#else
static int localcombs_work (G, cplanelist, startnode, x, pseudo)
Xgraph *G;
Xcplane **cplanelist;
Xnode *startnode;
double *x;
int pseudo;
#endif
{
    int hit, component;
    Xnode *n;

    /* printf ("localcombs...\n"); fflush (stdout); */

    if (startnode)
        component = startnode->Tmark;
    else
        component = 0;
    if (x == (double *) NULL) {
        printf ("need x vector for Xlocalcombs\n");
        return 0;
    }
    if (!pseudo) {
        Xloadx (G, x);
        Xbuildpseudonodelist (G, 0);
    }
    Xlocalshrink_a (G, component);
    Xlocalshrink_b (G, component);
    Xlocalshrink_c (G, component);
    if (startnode == (Xnode *) NULL)
        hit = blockcombs_work (G, cplanelist, 1, x);
    else {
        n = G->pseudonodelist->next;
        while (n && n->Tmark != component)
            n = n->next;
        if (!n) {
            hit = 0;
            printf ("WHOOOPS, did not find the component\n");
        } else
            hit = analyze_component (G, cplanelist, n, 0, (Xnode **) NULL, x);
    }
    if (!pseudo)
        Xdestroypseudonodelist (G);

    return hit;
}

#ifdef CC_PROTOTYPE_ANSI
int Xglobalcombs (Xgraph *G, Xcplane **cplanelist, double *x)
#else
int Xglobalcombs (G, cplanelist, x)
Xgraph *G;
Xcplane **cplanelist;
double *x;
#endif
{
    int count = 0;
    Xnode *n, **nodestack;

    Xloadx (G, x);
    Xbuildpseudonodelist (G, 0);
    nodestack = CC_SAFE_MALLOC (G->npseudonodes, Xnode *);
    if (!nodestack) {
        fprintf (stderr, "out of memory on globalcombs\n");
        exit (1);
    }

    while ((n = globalshrink (G)) != (Xnode *) NULL) {
        /* printf ("N: %d ", n - G->nodelist); fflush (stdout); */
        XTmark_components (G);
        count += analyze_component (G, cplanelist, n, 0, nodestack, x);
        count += localcombs_work (G, cplanelist, n, x, 1);
        /* printf ("\n"); fflush (stdout); */
    }

/*
    printf ("%d globalcombs\n", count);
*/

    CC_FREE (nodestack, Xnode *);
    Xdestroypseudonodelist (G);

    return count;
}

#ifdef CC_PROTOTYPE_ANSI
void Xlocalshrink_a (Xgraph *G, int component)
#else
void Xlocalshrink_a (G, component)
Xgraph *G;
int component;
#endif
{
    int i;
    Xedge *e;
    Xnode *u, *v;

    /* printf ("localshrink_a (%d)...\n", component); */
    if (!component) {
        for (e = G->edgelist, i = G->nedges; i; e++, i--)
            if (e->stay && e->x == 1.0) {
                u = e->cends[0];
                v = e->cends[1];
                Xrepeat_1_shrink (G, u, e);
                Xrepeat_1_shrink (G, v, e);
            }
    } else {
        for (e = G->edgelist, i = G->nedges; i; e++, i--)
            if (e->stay && e->x == 1.0 &&
                (e->cends[0]->Tmark == component ||
                 e->cends[1]->Tmark == component)) {
                Xrepeat_1_shrink (G, e->cends[0], e);
                Xrepeat_1_shrink (G, e->cends[1], e);
            }
    }
}

#ifdef CC_PROTOTYPE_ANSI
void Xlocalshrink_b (Xgraph *G, int component)
#else
void Xlocalshrink_b (G, component)
Xgraph *G;
int component;
#endif
{
    int i, hit;
    Xedge *e, *f, *g;
    Xedgeptr *ep;
    Xnode *u, *v, *w;

    for (e = G->edgelist, i = G->nedges; i; e++, i--) {
        if (e->stay && e->x == 1.0 && (!component ||
                                       (e->cends[0]->Tmark == component &&
                                        e->cends[1]->Tmark == component))) {
            u = e->cends[0];
            v = e->cends[1];
            hit = 0;
            for (ep = u->cadj.head; ep && !hit; ep = ep->next) {
                f = ep->this;
                w = OTHERCURRENTEND (f, u);
                if ((g = Xcurrentedge (v, w)) != (Xedge *) NULL)
                    if (f->x + g->x > 1.0 - XEPSILON) {
                        hit = 1;
                        Xsimpleshrink (G, u, v);
                    }
            }
        }
    }
}

#ifdef CC_PROTOTYPE_ANSI
void Xlocalshrink_c (Xgraph *G, int component)
#else
void Xlocalshrink_c (G, component)
Xgraph *G;
int component;
#endif
{
    int i, hit;
    Xedge *c, *d, *e, *f, *g, *h;
    Xedgeptr *ep, *tp;
    Xnode *u, *v, *w, *t;

    for (e = G->edgelist, i = G->nedges; i; e++, i--)
        if (e->stay && (!component || (e->cends[0]->Tmark == component
                        && e->cends[1]->Tmark == component))) {
            u = e->cends[0];
            v = e->cends[1];
            hit = 0;
            for (ep = u->cadj.head; ep && !hit; ep = ep->next) {
                f = ep->this;
                if (f == e)
                    continue;
                w = OTHERCURRENTEND (f, u);
                if (((g = Xcurrentedge (w, v)) != (Xedge *) NULL) &&
                    e->x + f->x + g->x > 2.0 - XEPSILON) {
                    for (tp = u->cadj.head; tp && !hit;
                         tp = tp->next) {
                        h = tp->this;
                        if (h == e || h == f || h == g)
                            continue;
                        t = OTHERCURRENTEND (h, u);
                        if (((c = Xcurrentedge (t, v)) != (Xedge *) NULL) &&
                            ((d = Xcurrentedge (t, w)) != (Xedge *) NULL) &&
                            h->x + c->x + d->x >
                            1.0 - XEPSILON) {
                            hit = 1;
                            Xsimpleshrink (G, u, v);
                            Xsimpleshrink (G, u, w);
                        }
                    }
                }
            }
        }
}

#ifdef CC_PROTOTYPE_ANSI
static Xnode *globalshrink (Xgraph *G)
#else
static Xnode *globalshrink (G)
Xgraph *G;
#endif
{
    Xedge *e, *f, *g, *h;
    Xedgeptr *ep, *ep2;
    Xnode *u, *v, *w, *x;
    int i;

    XTmark_components (G);
    for (e = G->edgelist, i = G->nedges; i; i--, e++)
        if (e->stay && e->x == 1.0 && (u = e->cends[0])->Tmark
            != (w = e->cends[1])->Tmark)
            for (ep = u->cadj.head; ep; ep = ep->next) {
                f = ep->this;
                if (f == e)
                    continue;
                v = OTHERCURRENTEND (f, u);
                for (ep2 = w->cadj.head; ep2; ep2 = ep2->next) {
                    g = ep2->this;
                    if (g == e)
                        continue;
                    x = OTHERCURRENTEND (g, w);
                    if (x != v &&
                        f->x + g->x > 1.0 - XEPSILON &&
                        (h = Xcurrentedge (v, x)) != (Xedge *) NULL &&
                        h->x == 1.0) {
                        Xsimpleshrink (G, u, w);
                        Xsimpleshrink (G, v, x);
                        /* printf ("SHRINK\n"); fflush (stdout); */
                        return u;
                    }
                }
            }
    return (Xnode *) NULL;
}

#ifdef CC_PROTOTYPE_ANSI
static int blockcombs_work (Xgraph *G, Xcplane **cplanelist, int pseudo,
            double *x)
#else
static int blockcombs_work (G, cplanelist, pseudo, x)
Xgraph *G;
Xcplane **cplanelist;
int pseudo;
double *x;
#endif
{
    Xnode *n, **nodestack, **top;
    int lastnumber = 1, oldlast, combcount = 0;

    /* printf ("blockcombs....\n"); fflush (stdout); */

    if (x == (double *) NULL) {
        printf ("Need x vector of Xblockcombs\n");
        return 0;
    }
    if (!pseudo) {
        Xloadx (G, x);
        Xbuildpseudonodelist (G, 0);
    }
    for (n = G->pseudonodelist->next; n; n = n->next) {
        n->active = 0;
        n->mark = G->npseudonodes;
    }

    nodestack = CC_SAFE_MALLOC (G->npseudonodes, Xnode *);
    if (!nodestack) {
        fprintf (stderr, "out of memory in blockcombs\n");
        exit (1);
    }
    for (n = G->pseudonodelist->next; n; n = n->next) {
        if (!n->active) {
            *nodestack = n;
            top = nodestack + 1;
            oldlast = lastnumber;
            block_biconnect (G, n, (Xnode *) NULL, &lastnumber, &top,
                             (Xblock **) NULL, (Xcutnode **) NULL, 0);
            if (lastnumber - oldlast >= 3)
                combcount += analyze_component (G, cplanelist,
                                                n, oldlast, nodestack, x);
        }
        if (combcount >= FMPMAX)
            break;
    }
    CC_FREE (nodestack, Xnode *);

    if (!pseudo)
        Xdestroypseudonodelist (G);
/*
    if (report)
        printf ("%d blockcombs\n", combcount);
*/

    return combcount;
}

#ifdef CC_PROTOTYPE_ANSI
static void block_biconnect (Xgraph *G, Xnode *v, Xnode *u, int *lastnumber,
        Xnode ***top_pointer, Xblock **tblock, Xcutnode **tcut, int count_cut)
#else
static void block_biconnect (G, v, u, lastnumber, top_pointer, tblock, tcut,
        count_cut)
Xgraph *G;
Xnode *v, *u;
int *lastnumber;
Xnode ***top_pointer;
Xblock **tblock;
Xcutnode **tcut;
int count_cut;
#endif
{
    Xedge *e;
    Xedgeptr *ep;
    Xnode *w, **top = *top_pointer;
    Xnodeptr *np;

    v->mark = v->active = (*lastnumber)++;
    for (ep = v->cadj.head; ep; ep = ep->next) {
        e = ep->this;
        if (e->x > 1.0 - XEPSILON)
            continue;
        w = OTHERCURRENTEND (e, v);
        if (!w->active) {
            *top = w;
            top++;
            block_biconnect (G, w, v, lastnumber, &top, tblock, tcut,
                             count_cut);
            if (w->mark < v->mark)
                v->mark = w->mark;
            if (w->mark >= v->active) {
                if (count_cut)
                    nblocks++;
                if (count_cut && v->magiclabel != G->magicnum) {
                    if (v->magiclabel == G->magicnum - 1)
                        v->magiclabel--;
                    else {
                        ncutnodes++;
                        v->magiclabel = G->magicnum;
                        if (tcut != (Xcutnode **) NULL) {
                            (*tcut)->name = v;
                            (*tcut)++;
                        }
                    }
                }
                if (tblock) {
                    np = Xnodeptralloc ();
                    np->this = v;
                    np->next = (Xnodeptr *) NULL;
                    (*tblock)->members = np;
                }
                while (*(top - 1) != v) {
                    if (tblock) {
                        np = Xnodeptralloc ();
                        np->this = *(top - 1);
                        np->next = (*tblock)->members;
                        (*tblock)->members = np;
                    }
                    top--;
                }
                if (tblock)
                    (*tblock)++;
            }
        } else if (w->active < v->mark && w != u) {
            if (w->mark < v->mark)
                v->mark = w->mark;
        }
    }
    *top_pointer = top;
}

#ifdef CC_PROTOTYPE_ANSI
int XTmark_components (Xgraph *G)
#else
int XTmark_components (G)
Xgraph *G;
#endif
{
    int ccount = 1;
    Xnode *n;

    for (n = G->pseudonodelist->next; n; n = n->next)
        n->Tmark = 0;

    for (n = G->pseudonodelist->next; n; n = n->next) {
        if (!n->Tmark) {
            dfs_Tmark (n, ccount);
            ccount++;
        }
    }
    /* printf ("NUMBER OF COMPONENTS: %d\n", ccount - 1); */
    return ccount;
}

#ifdef CC_PROTOTYPE_ANSI
static void dfs_Tmark (Xnode *start, int t)
#else
static void dfs_Tmark (start, t)
Xnode *start;
int t;
#endif
{
    Xedgeptr *ep;
    Xnode *n, *v;
    Xnodeptr *next, *queue = (Xnodeptr *) NULL;

    start->Tmark = t;
    Xadd_nodeptr (&queue, start);

    while (queue) {
        n = queue->this;
        next = queue->next;
        Xnodeptrfree (queue);
        queue = next;
        for (ep = n->cadj.head; ep; ep = ep->next) {
            if (ep->this->x > 1.0 - XEPSILON)
                continue;
            if (!(v = OTHERCURRENTEND (ep->this, n))->Tmark) {
                v->Tmark = t;
                Xadd_nodeptr (&queue, v);
            }
        }
    }
}


#ifdef CC_PROTOTYPE_ANSI
static int analyze_component (Xgraph *G, Xcplane **cplanelist, Xnode *n,
            int first, Xnode **nodestack, double *x)
#else
static int analyze_component (G, cplanelist, n, first, nodestack, x)
Xgraph *G;
Xcplane **cplanelist;
Xnode *n;
int first;
Xnode **nodestack;
double *x;
#endif
{
    int i, fake, combcount = 0, newstack = 0;
    Xnode *v, **top;
    Xblock *topblock, *b;
    Xcutnode *topcutnode;

    /*
    printf ("analyze_component (blocks: %d  cuts: %d)...\n",
             nblocks, ncutnodes);
    fflush (stdout);
    */

    if (!nodestack) {
        nodestack = CC_SAFE_MALLOC (G->npseudonodes, Xnode *);
        if (!nodestack) {
            fprintf (stderr, "out of memory in analyze_component\n");
            exit (1);
        }
        newstack = 1;
    }
    *nodestack = n;
    top = nodestack + 1;
    if (first) {
        for (v = G->pseudonodelist->next; v; v = v->next)
            if (v->active >= first)
                v->active = 0;
    } else {
        for (v = G->pseudonodelist->next; v; v = v->next) {
            v->active = 0;
            v->mark = G->npseudonodes;
        }
        first = 1;
    }

    nblocks = ncutnodes = 0;
    G->magicnum += 2;
    n->magiclabel = G->magicnum - 1;
    fake = first;
    block_biconnect (G, n, (Xnode *) NULL, &fake, &top, (Xblock **) NULL,
                        (Xcutnode **) NULL, 1);

    if (nblocks > 0) {
        blocklist = CC_SAFE_MALLOC (nblocks, Xblock);
        if (!blocklist) {
            fprintf (stderr, "out of memory in analyze_component\n");
            exit (1);
        }
    } else
        blocklist = (Xblock *) NULL;

    if (ncutnodes) {
        cutnodelist = CC_SAFE_MALLOC (ncutnodes, Xcutnode);
        if (!cutnodelist) {
            fprintf (stderr, "out of memory in analyze_component\n");
            exit (1);
        }
    } else
        cutnodelist = (Xcutnode *) NULL;

    for (i = 0; i < nblocks; i++) {
        blocklist[i].members = (Xnodeptr *) NULL;
        blocklist[i].neighbors = (Xblockptr *) NULL;
        blocklist[i].one = (Xedgeptr *) NULL;
        blocklist[i].cutnodes = (Xcutnodeptr *) NULL;
    }

    for (i = 0; i < ncutnodes; i++)
        cutnodelist[i].blocks = (Xblockptr *) NULL;

    topblock = blocklist;
    topcutnode = cutnodelist;

    for (v = G->pseudonodelist->next; v; v = v->next)
        if (v->active >= first)
            v->active = 0;

    *nodestack = n;
    top = nodestack + 1;
    nblocks = ncutnodes = 0;
    G->magicnum += 2;
    n->magiclabel = G->magicnum - 1;
    fake = first;
    block_biconnect (G, n, (Xnode *) NULL, &fake, &top, &topblock,
                           &topcutnode, 1);
    for (i = nblocks, b = blocklist; i; i--, b++) {
        blockweight (G, b);
        blockone (G, b);
    }
    buildcutnodes (G);
    buildallneighbors ();
    combcount += connectedhandles (G, cplanelist, x);

    /*
    printf ("ALL CUTNODES: ");
    fflush (stdout);
    for (i = ncutnodes, topcutnode = cutnodelist; i; i--, topcutnode++)
        printf ("%d ", topcutnode->name - G->nodelist);
    printf ("\n");
    printf ("BLOCKS:\n");
    for (i = 0, topblock = blocklist; i < nblocks; i++, topblock++) {
        printf ("%d: ", i);
        fflush (stdout);
        for (np = topblock->members; np; np = np->next)
            printf (" %d", np->this - nodelist);
        printf ("\nWeight: %lf\n", topblock->weight);
        printf ("ONE: ");
        fflush (stdout);
        for (ep = topblock->one; ep; ep = ep->next) {
            printf ("(%d, %d) ", ep->this->cends[0] - G->nodelist,
                                 ep->this->cends[1] - G->nodelist);
            fflush (stdout);
        }
        printf ("\n");
        printf ("CUTNODES: ");
        fflush (stdout);
        for (cp = topblock->cutnodes; cp; cp = cp->next)
            printf (" %d", cp->this->name - G->nodelist);
        printf ("\n");
    }
    printf ("done\n");
    fflush (stdout);
    */

    freeblocklist ();
    freecutnodelist ();
    if (newstack)
        CC_FREE (nodestack, Xnode *);
    return combcount;
}

#ifdef CC_PROTOTYPE_ANSI
static void blockweight (Xgraph *G, Xblock *b)
#else
static void blockweight (G, b)
Xgraph *G;
Xblock *b;
#endif
{
    int count = 0;
    double inside = 0.0;
    Xnode *n;
    Xedge *e;
    Xnodeptr *np;
    Xedgeptr *ep;

    G->magicnum++;
    for (np = b->members; np; np = np->next) {
        np->this->magiclabel = G->magicnum;
        count++;
    }

    for (np = b->members; np; np = np->next) {
        n = np->this;
        for (ep = n->cadj.head; ep; ep = ep->next) {
            e = ep->this;
            if (OTHERCURRENTEND (e, n)->magiclabel == G->magicnum)
                inside += e->x;
        }
    }
    inside /= 2.0;
    b->x = inside;
    b->weight = inside + 2.0 - count;
}

#ifdef CC_PROTOTYPE_ANSI
static void blockone (Xgraph *G, Xblock *b)
#else
static void blockone (G, b)
Xgraph *G;
Xblock *b;
#endif
{
    Xnode *n;
    Xedge *e;
    Xnodeptr *np;
    Xedgeptr *ep, *tp;

    G->magicnum++;
    for (np = b->members; np; np = np->next)
        np->this->magiclabel = G->magicnum;

    for (np = b->members; np; np = np->next) {
        n = np->this;
        for (ep = n->cadj.head; ep; ep = ep->next) {
            e = ep->this;
            if (e->x == 1.0 && OTHERCURRENTEND (e, n)->magiclabel
                != G->magicnum) {
                tp = Xedgeptralloc ();
                tp->this = e;
                tp->next = b->one;
                b->one = tp;
            }
        }
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void buildcutnodes (Xgraph *G)
#else
static void buildcutnodes (G)
Xgraph *G;
#endif
{
    Xcutnode *c;
    Xnode *nc;
    Xnodeptr *np;
    Xcutnodeptr *cp;
    Xblock *b;
    Xblockptr *bp;
    int i, j, hit;

    for (i = ncutnodes, c = cutnodelist; i; i--, c++) {
        nc = c->name;
        for (j = nblocks, b = blocklist; j; j--, b++) {
            hit = 0;
            for (np = b->members; np && !hit; np = np->next)
                if (np->this == nc) {
                    cp = Xcutnodeptralloc ();
                    cp->this = c;
                    cp->next = b->cutnodes;
                    b->cutnodes = cp;

                    bp = Xblockptralloc ();
                    bp->this = b;
                    bp->next = c->blocks;
                    c->blocks = bp;
                    bp->hood_weight = hoodweight (G, b, nc);
                    hit++;
                }
        }
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void buildallneighbors (void)
#else
static void buildallneighbors ()
#endif
{
    int i;
    Xblock *b;

    for (i = nblocks, b = blocklist; i; i--, b++)
        buildneighbors (b);
}

#ifdef CC_PROTOTYPE_ANSI
static void buildneighbors (Xblock *b)
#else
static void buildneighbors (b)
Xblock *b;
#endif
{
    int i;
    Xblock *d;
    Xblockptr *bp;
    Xcutnodeptr *cp;

    for (i = nblocks, d = blocklist; i; i--, d++)
        d->mark = 0;

    for (cp = b->cutnodes; cp; cp = cp->next)
        for (bp = cp->this->blocks; bp; bp = bp->next)
            if (bp->this != b)
                bp->this->mark = 1;

    for (i = nblocks, d = blocklist; i; i--, d++)
        if (d->mark) {
            bp = Xblockptralloc ();
            bp->this = d;
            bp->next = b->neighbors;
            b->neighbors = bp;
        }
}

#ifdef CC_PROTOTYPE_ANSI
static double hoodweight (Xgraph *G, Xblock *b, Xnode *n)
#else
static double hoodweight (G, b, n)
Xgraph *G;
Xblock *b;
Xnode *n;
#endif
{
    Xnode *m;
    Xnodeptr *np;
    Xedgeptr *ep, *tp;
    Xedge *e;
    double inside = 0.0;
    int count = 1;

    G->magicnum++;
    for (np = b->members; np; np = np->next)
        np->this->magiclabel = G->magicnum;
    for (ep = n->cadj.head; ep; ep = ep->next)
        OTHERCURRENTEND (ep->this, n)->magiclabel++;
    n->magiclabel++;
    G->magicnum++;
    for (ep = n->cadj.head; ep; ep = ep->next) {
        m = OTHERCURRENTEND (ep->this, n);
        if (m->magiclabel == G->magicnum) {
            count++;
            inside += ep->this->x;
            for (tp = m->cadj.head; tp; tp = tp->next) {
                e = tp->this;
                if (OTHERCURRENTEND (e, m)->magiclabel == G->magicnum)
                    inside += e->x;
            }
        }
    }
    inside /= 2.0;

    return inside + 2.0 - count;
}

#ifdef CC_PROTOTYPE_ANSI
static void freeblocklist (void)
#else
static void freeblocklist ()
#endif
{
    Xblock *b;
    Xnodeptr *np, *next;
    Xblockptr *bp, *bext;
    Xcutnodeptr *cp, *cext;
    Xedgeptr *ep, *eext;
    int i;

    for (b = blocklist, i = nblocks; i; i--, b++) {
        for (np = b->members; np; np = next) {
            next = np->next;
            Xnodeptrfree (np);
        }
        for (bp = b->neighbors; bp; bp = bext) {
            bext = bp->next;
            Xblockptrfree (bp);
        }
        for (cp = b->cutnodes; cp; cp = cext) {
            cext = cp->next;
            Xcutnodeptrfree (cp);
        }
        for (ep = b->one; ep; ep = eext) {
            eext = ep->next;
            Xedgeptrfree (ep);
        }
    }
    if (blocklist) {
        CC_FREE (blocklist, Xblock);
    }
}


#ifdef CC_PROTOTYPE_ANSI
static void freecutnodelist (void)
#else
static void freecutnodelist ()
#endif
{
    Xcutnode *c;
    Xblockptr *bp, *next;
    int i;

    if (ncutnodes) {
        for (c = cutnodelist, i = ncutnodes; i; i--, c++)
            for (bp = c->blocks; bp; bp = next) {
                next = bp->next;
                Xblockptrfree (bp);
            }
        CC_FREE (cutnodelist, Xcutnode);
    }
}

#ifdef CC_PROTOTYPE_ANSI
static int connectedhandles (Xgraph *G, Xcplane **cplanelist, double *x)
#else
static int connectedhandles (G, cplanelist, x)
Xgraph *G;
Xcplane **cplanelist;
double *x;
#endif
{
    int i, combcount = 0, searchcount = 0;
    Xblock *b;

    for (i = nblocks, b = blocklist; i; i--, b++)
        b->mark = 0;

    for (i = nblocks, b = blocklist; i; i--, b++) {
        b->mark = 1;
        if (processhandle (G, cplanelist, x))
            combcount++;
        if (combcount >= FMPMAX)
            return combcount;

        b->mark = 0;
    }

    handlesearch (G, cplanelist, x, &combcount, &searchcount);

    /* printf ("(%d)  ", searchcount); fflush (stdout); */

    return combcount;
}

#ifdef CC_PROTOTYPE_ANSI
static void handlesearch (Xgraph *G, Xcplane **cplanelist, double *x,
             int *combcount, int *searchcount)
#else
static void handlesearch (G, cplanelist, x, combcount, searchcount)
Xgraph *G;
Xcplane **cplanelist;
double *x;
int *combcount, *searchcount;
#endif
{
    int i, k;
    Xblock *b, *winner = (Xblock *) NULL, *runnerup = (Xblock *) NULL;
    Xblockptr *bp;

    for (i = nblocks, b = blocklist; i && !winner; i--, b++) {
        if (!b->mark) {
            for (k = 0, bp = b->neighbors; bp && k < 2; bp = bp->next)
                if (!bp->this->mark)
                    k++;
            if (k == 1) {
                winner = b;
                for (bp = b->neighbors; bp; bp = bp->next)
                    if (!bp->this->mark) {
                        runnerup = bp->this;
                        break;
                    }
                winner->mark = 1;
                runnerup->mark = 1;
            }
        }
    }
    if (!winner)
        return;
    (*searchcount)++;
    if (processhandle (G, cplanelist, x))
        (*combcount)++;
    if (*combcount >= FMPMAX || *searchcount >= SEARCHMAX)
        return;

    winner->mark = -1;
    runnerup->mark = 0;
    handlesearch (G, cplanelist, x, combcount, searchcount);
}

#ifdef CC_PROTOTYPE_ANSI
static int processhandle (Xgraph *G, Xcplane **cplanelist, double *x)
#else
static int processhandle (G, cplanelist, x)
Xgraph *G;
Xcplane **cplanelist;
double *x;
#endif
{
    int i, nteeth = 0, handlecount = 0, midtake = 0, test;
    double total = 0.0, midval = 2.0, mid = 0, handleweight = 0.0, max;
    Xcutnode *c;
    Xnode *n;
    Xnodeptr *np, *nnp;
    Xcutnodeptr *cp;
    Xblock *b, *d, *bestblock = (Xblock *) NULL;
    Xblockptr *bp;
    Xedgeptr *ep;
    Xedge *e;
    int gotmid, besttype = 0, hit;
    Xnodeptr *handle, *tooth;
    Xnodeptrptr *teeth, *ntp;
    int countcheck = 0;

    /*
    printf ("PH: ");
    for (i = nblocks, b = blocklist; i; i--, b++)
        if (b->mark == 1)
            printf ("%d ", b - blocklist);
    printf ("\n");
    */
    G->magicnum++;
    for (n = G->pseudonodelist->next; n; n = n->next)
        n->stacklabel = 0;
    for (i = ncutnodes, c = cutnodelist; i; i--, c++)
        c->mark = 0;
    for (i = nblocks, b = blocklist; i; i--, b++) {
        if (b->mark == 1) {
            for (np = b->members; np; np = np->next)
                np->this->stacklabel = 1;
            for (cp = b->cutnodes; cp; cp = cp->next)
                cp->this->mark = 1;
        }
    }
    for (i = nblocks, b = blocklist; i; i--, b++) {
        if (b->mark == 1) {
            for (ep = b->one; ep; ep = ep->next) {
                e = ep->this;
                if ((e->cends[0]->stacklabel !=
                     e->cends[1]->stacklabel) &&
                    (e->cends[0]->magiclabel != G->magicnum ||
                     e->cends[1]->magiclabel != G->magicnum)) {
                    e->cends[0]->magiclabel = G->magicnum;
                    e->cends[1]->magiclabel = G->magicnum;
                    nteeth++;
                    total += 1.0;
                    midtake = 1;
                    mid = 1.0;
                    midval = 0.5;
                }
            }
        }
    }

    for (i = G->nedges, e = G->edgelist; i; i--, e++) {
        if (e->stay && e->cends[0]->stacklabel &&
            e->cends[1]->stacklabel)
            handleweight += e->x;
    }

    for (n = G->pseudonodelist->next; n; n = n->next) {
        if (n->stacklabel)
            handlecount++;
    }

    for (i = ncutnodes, c = cutnodelist; i; i--, c++) {
        if (c->mark && c->name->magiclabel != G->magicnum) {
            hit = 0;
            max = 0.0;
            for (bp = c->blocks; bp; bp = bp->next) {
                d = bp->this;
                if (d->mark != 1) {
                    hit = 1;
                    if (d->weight > max)
                        max = d->weight;
                    if (bp->hood_weight > max)
                        max = bp->hood_weight;
                }
            }
            if (max >= 0.5) {
                nteeth++;
                total += max;
                if (midval > max - 0.5) {
                    midval = max - 0.5;
                    mid = max;
                    midtake = 1;
                }
            } else if (hit && midval > 0.5 - max) {
                midval = 0.5 - max;
                mid = max;
                midtake = 0;
            }
        }
    }
    if (nteeth < 2) {
        return 0;
    }
    if (nteeth % 2 == 0) {
        gotmid = 0;
        if (!midtake) {
            total += mid;
            nteeth++;
        } else {
            total -= mid;
            nteeth--;
        }
    } else
        gotmid = 1;


    total += handleweight + 2.0 - handlecount;
    if (nteeth < 3 || total <= 1.5 + (0.5 * nteeth) + BLOTOLERANCE)
        return 0;

    G->magicnum++;
    for (i = nblocks, b = blocklist; i; i--, b++)
        if (b->mark == 1)
            for (np = b->members; np; np = np->next)
                for (nnp = np->this->base.head; nnp;
                     nnp = nnp->next)
                    nnp->this->magiclabel = G->magicnum;

    handle = (Xnodeptr *) NULL;
    for (i = G->nnodes, n = G->nodelist; i; i--, n++)
        if (n->magiclabel == G->magicnum) {
            np = Xnodeptralloc ();
            np->this = n;
            np->next = handle;
            handle = np;
        }
    nteeth = 0;
    teeth = (Xnodeptrptr *) NULL;

    G->magicnum++;
    for (i = nblocks, b = blocklist; i; i--, b++)
        if (b->mark == 1)
            for (ep = b->one; ep; ep = ep->next) {
                e = ep->this;
                if ((e->cends[0]->stacklabel !=
                     e->cends[1]->stacklabel) &&
                    (e->cends[0]->magiclabel != G->magicnum ||
                     e->cends[1]->magiclabel != G->magicnum)) {
                    e->cends[0]->magiclabel = G->magicnum;
                    e->cends[1]->magiclabel = G->magicnum;
                    if (!gotmid && mid == 1.0)
                        gotmid = 1;
                    else {
                        nteeth++;
                        tooth = (Xnodeptr *) NULL;
                        Xmarktooth (ep->this, &tooth);
                        Xadd_nodeptrptr (&teeth, tooth);
                    }
                }
            }

    for (i = ncutnodes, c = cutnodelist; i; i--, c++)
        if (c->mark && c->name->magiclabel != G->magicnum) {
            max = 0.0;
            hit = 0;
            for (bp = c->blocks; bp; bp = bp->next) {
                d = bp->this;
                if (d->mark != 1) {
                    hit = 1;
                    if (d->weight > max) {
                        bestblock = d;
                        besttype = 0;
                        max = d->weight;
                    }
                    if (bp->hood_weight > max) {
                        bestblock = d;
                        besttype = 1;
                        max = bp->hood_weight;
                    }
                }
            }
            if (max >= 0.5) {
                if (!gotmid && max == mid)
                    gotmid = 1;
                else {
                    nteeth++;
                    tooth = (Xnodeptr *) NULL;
                    if (besttype)
                        markblock (bestblock, c,
                                        &tooth);
                    else
                        markblock (bestblock, (Xcutnode *) NULL,
                                        &tooth);
                    Xadd_nodeptrptr (&teeth, tooth);
                }
            } else if (hit && !gotmid && max == mid) {
                gotmid = 1;
                nteeth++;
                tooth = (Xnodeptr *) NULL;
                if (besttype)
                    markblock (bestblock, c,
                                    &tooth);
                else
                    markblock (bestblock, (Xcutnode *) NULL,
                                    &tooth);
                Xadd_nodeptrptr (&teeth, tooth);
            }
        }
    Xcleancomb (G, &handle, &teeth, &nteeth, x);
    if (!Xtemp_combfluff (G, &handle, &teeth))
        return 0;
    test = Xtemp_combcheck (G, handle, teeth) &&
           Xloadcplane (cplanelist, handle, (Xnodeptrptr *) NULL, teeth,
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
static int markblock (Xblock *b, Xcutnode *c, Xnodeptr **list)
#else
static int markblock (b, c, list)
Xblock *b;
Xcutnode *c;
Xnodeptr **list;
#endif
{
    Xnode *n, *m;
    Xnodeptr *np, *nnp;
    Xedgeptr *ep;
    int count = 0, hit;

    *list = (Xnodeptr *) NULL;
    if (c == (Xcutnode *) NULL)
        for (np = b->members; np; np = np->next) {
            n = np->this;
            for (nnp = n->base.head; nnp; nnp = nnp->next) {
                Xadd_tooth (nnp->this, list);
                count++;
            }
        }
    else
        for (np = b->members; np; np = np->next) {
            n = np->this;
            if (n == c->name)
                hit = 1;
            else
                hit = 0;
            for (ep = c->name->cadj.head; ep && !hit; ep = ep->next) {
                m = OTHERCURRENTEND (ep->this, c->name);
                if (m == n)
                    hit = 1;
            }
            if (hit) {
                for (nnp = n->base.head; nnp; nnp = nnp->next) {
                    Xadd_tooth (nnp->this, list);
                    count++;
                }
            }
        }
    return count;
}

#ifdef CC_PROTOTYPE_ANSI
Xedge *Xcurrentedge (Xnode *n1, Xnode *n2)
#else
Xedge *Xcurrentedge (n1, n2)
Xnode *n1, *n2;
#endif
{
    Xedgeptr *ep;

    for (ep = n1->cadj.head; ep; ep = ep->next)
        if (OTHERCURRENTEND (ep->this, n1) == n2)
            return ep->this;

    return (Xedge *) NULL;
}


#ifdef CC_PROTOTYPE_ANSI
void Xadd_tooth (Xnode *t, Xnodeptr **list)
#else
void Xadd_tooth (t, list)
Xnode *t;
Xnodeptr **list;
#endif
{
    Xnodeptr *np;

    np = Xnodeptralloc ();
    np->this = t;
    np->next = *list;
    *list = np;
}

#ifdef CC_PROTOTYPE_ANSI
int Xmarktooth (Xedge *e, Xnodeptr **list)
#else
int Xmarktooth (e, list)
Xedge *e;
Xnodeptr **list;
#endif
{
    int count;

    *list = (Xnodeptr *) NULL;
    count = Xmarktoothend (e->cends[0], list) +
        Xmarktoothend (e->cends[1], list);

    return count;
}

#ifdef CC_PROTOTYPE_ANSI
int Xmarktoothend (Xnode *n, Xnodeptr **list)
#else
int Xmarktoothend (n, list)
Xnode *n;
Xnodeptr **list;
#endif
{
    Xnodeptr *np;
    int count = 0;

    for (np = n->base.head; np; np = np->next) {
        count++;
        Xadd_tooth (np->this, list);
    }

    return count;
}

#ifdef CC_PROTOTYPE_ANSI
int Xrepeat_1_shrink (Xgraph *G, Xnode *n, Xedge *e)
#else
int Xrepeat_1_shrink (G, n, e)
Xgraph *G;
Xnode *n;
Xedge *e;
#endif
{
    int hit, count = 0;
    Xedgeptr *ep;
    Xedge *f;

    do {
        for (ep = n->cadj.head, hit = 0; ep && !hit; ep = ep->next) {
            f = ep->this;
            if (f->x == 1.0 && f != e) {
                Xsimpleshrink (G, n, OTHERCURRENTEND (f, n));
                hit = 1;
                count++;
            }
        }
    } while (hit);

    return count;
}



/*********************** New Clique Tree Stuff *********************/

#ifdef CC_PROTOTYPE_ANSI
int Xbasiccliques (Xgraph *G, Xcplane **list, double *x)
#else
int Xbasiccliques (G, list, x)
Xgraph *G;
Xcplane **list;
double *x;
#endif
{
    return Xsearchbasiccliques (G, list, 0, x);
}

#ifdef CC_PROTOTYPE_ANSI
int Xsearchbasiccliques (Xgraph *G, Xcplane **list, int pseudo, double *x)
#else
int Xsearchbasiccliques (G, list, pseudo, x)
Xgraph *G;
Xcplane **list;
int pseudo;
double *x;
#endif
{
    int lastnumber = 1, oldlast, cliquecount = 0;
    Xnode *n, **nodestack, **top;

/*
    printf ("searchbasiccliques ...\n");
    fflush (stdout);
*/

    if (x == (double *) NULL) {
        printf ("need x vector of Xsearchbasiccliques\n");
        return 0;
    }
    if (!pseudo) {
        Xloadx (G, x);
        Xbuildpseudonodelist (G, 0);
    }
    for (n = G->pseudonodelist->next; n; n = n->next) {
        n->active = 0;
        n->mark = G->npseudonodes;
    }

    nodestack = CC_SAFE_MALLOC (G->npseudonodes, Xnode *);
    if (!nodestack) {
        fprintf (stderr, "out of memory in Xsearchbasiccliques\n");
        exit (1);
    }
    for (n = G->pseudonodelist->next; n; n = n->next) {
        if (!n->active) {
            *nodestack = n;
            top = nodestack + 1;
            oldlast = lastnumber;
            block_biconnect (G, n, (Xnode *) NULL, &lastnumber, &top,
                                   (Xblock **) NULL, (Xcutnode **) NULL, 0);
            if (lastnumber - oldlast >= 3)
                cliquecount += component_basicclique (G, list,
                                                  n, oldlast, nodestack, x);
        }
        if (cliquecount >= FMPMAX)
            break;
    }
    CC_FREE (nodestack, Xnode *);

    if (!pseudo)
        Xdestroypseudonodelist (G);

    /* printf ("%d potential new cliquetrees\n", cliquecount); */

    return cliquecount;
}

#ifdef CC_PROTOTYPE_ANSI
static int component_basicclique (Xgraph *G, Xcplane **list, Xnode *n,
            int first, Xnode **nodestack, double *x)
#else
static int component_basicclique (G, list, n, first, nodestack, x)
Xgraph *G;
Xcplane **list;
Xnode *n;
int first;
Xnode **nodestack;
double *x;
#endif
{
    int i, fake, cliquecount = 0, newstack = 0;
    Xnode *v, **top;
    Xblock *topblock, *b;
    Xcutnode *topcutnode;

    if (!nodestack) {
        nodestack = CC_SAFE_MALLOC (G->npseudonodes, Xnode *);
        if (!nodestack) {
            fprintf (stderr, "out of memory in component_basicclique\n");
            exit (1);
        }
        newstack = 1;
    }
    *nodestack = n;
    top = nodestack + 1;
    if (first) {
        for (v = G->pseudonodelist->next; v; v = v->next)
            if (v->active >= first)
                v->active = 0;
    } else {
        for (v = G->pseudonodelist->next; v; v = v->next) {
            v->active = 0;
            v->mark = G->npseudonodes;
        }
        first = 1;
    }

    nblocks = ncutnodes = 0;
    G->magicnum += 2;
    n->magiclabel = G->magicnum - 1;
    fake = first;
    block_biconnect (G, n, (Xnode *) NULL, &fake, &top, (Xblock **) NULL,
                           (Xcutnode **) NULL, 1);

    if (nblocks > 0) {
        blocklist = CC_SAFE_MALLOC (nblocks, Xblock);
        if (!blocklist) {
            fprintf (stderr, "out of memory in component_basicclique\n");
            exit (1);
        }
    } else
        blocklist = (Xblock *) NULL;

    if (ncutnodes > 0) {
        cutnodelist = CC_SAFE_MALLOC (ncutnodes, Xcutnode);
        if (!cutnodelist) {
            fprintf (stderr, "out of memory in component_basicclique\n");
            exit (1);
        }
    } else
        cutnodelist = (Xcutnode *) NULL;

    for (i = 0; i < nblocks; i++) {
        blocklist[i].members = (Xnodeptr *) NULL;
        blocklist[i].neighbors = (Xblockptr *) NULL;
        blocklist[i].one = (Xedgeptr *) NULL;
        blocklist[i].cutnodes = (Xcutnodeptr *) NULL;
    }

    for (i = 0; i < ncutnodes; i++)
        cutnodelist[i].blocks = (Xblockptr *) NULL;

    topblock = blocklist;
    topcutnode = cutnodelist;

    for (v = G->pseudonodelist->next; v; v = v->next)
        if (v->active >= first)
            v->active = 0;

    *nodestack = n;
    top = nodestack + 1;
    nblocks = ncutnodes = 0;
    G->magicnum += 2;
    n->magiclabel = G->magicnum - 1;
    fake = first;
    block_biconnect (G, n, (Xnode *) NULL, &fake, &top, &topblock,
                     &topcutnode, 1);
    for (i = nblocks, b = blocklist; i; i--, b++) {
        blockweight (G, b);
        blockone (G, b);
    }
    buildcutnodes (G);
    buildallneighbors ();

    for (i = nblocks, b = blocklist; i; i--, b++)
        cliquecount += Xbasicclique (G, list, x, b);


    freeblocklist ();
    freecutnodelist ();
    if (newstack)
        CC_FREE (nodestack, Xnode *);
    return cliquecount;
}

#ifdef CC_PROTOTYPE_ANSI
int Xbasicclique (Xgraph *G, Xcplane **list, double *x, Xblock *bigtooth)
#else
int Xbasicclique (G, list, x, bigtooth)
Xgraph *G;
Xcplane **list;
double *x;
Xblock *bigtooth;
#endif
{
    Xblockptr *bp, *bnext, *combs;
    Xblock *b, *minb = (Xblock *) NULL;
    Xcutnode *c;
    Xcutnodeptr *cp;
    double min, t, slack, toothslack;
    int count, goodcount, nhandles;
    Xnodeptr *np, *tooth, *handle;
    Xnodeptrptr *teeth, *handles;
    int test;

    /* printf ("basiclique (%d)\n", bigtooth - blocklist); fflush (stdout); */

    toothslack = -(bigtooth->weight) + 1.0;

    if (toothslack <= 0.001)
        return 0;
    for (count = 0, np = bigtooth->members; np; np = np->next)
        count++;
    if (count < 3)
        return 0;


    combs = (Xblockptr *) NULL;
    for (cp = bigtooth->cutnodes; cp; cp = cp->next) {
        c = cp->this;
        min = 100.0;
        minb = (Xblock *) NULL;
        for (bp = c->blocks; bp; bp = bp->next) {
            b = bp->this;
            if (b == bigtooth)
                continue;
            if (combslack (G, b, bigtooth, &t, (Xnodeptrptr **) NULL))
                if (t < min) {
                    min = t;
                    minb = b;
                }
        }
        if (minb) {
            bp = Xblockptralloc ();
            bp->this = minb;
            bp->hood_weight = min;
            bp->next = combs;
            combs = bp;
        }
    }
    goodcount = 0;
    for (count = 0, bp = combs; bp; bp = bp->next) {
        if (bp->hood_weight >= toothslack)
            bp->this->mark = 0;
        else {
            bp->this->mark = 1;
            goodcount++;
        }
        count++;
    }

    if (count <= 1) {
        for (bp = combs; bp; bp = bnext) {
            bnext = bp->next;
            Xblockptrfree (bp);
        }
        return 0;
    } else if (goodcount == 1) {
        min = 100.0;
        for (bp = combs; bp; bp = bp->next)
            if (!bp->this->mark && bp->hood_weight < min) {
                min = bp->hood_weight;
                minb = bp->this;
            }
        minb->mark = 1;
    } else if (goodcount == 0) {
        min = 100.0;
        for (bp = combs; bp; bp = bp->next)
            if (!bp->this->mark && bp->hood_weight < min) {
                min = bp->hood_weight;
                minb = bp->this;
            }
        minb->mark = 1;
        min = 100.0;
        for (bp = combs; bp; bp = bp->next)
            if (!bp->this->mark && bp->hood_weight < min) {
                min = bp->hood_weight;
                minb = bp->this;
            }
        minb->mark = 1;
    }
    for (slack = 0.0, nhandles = 0, bp = combs; bp; bp = bp->next)
        if (bp->this->mark) {
            nhandles++;
            slack += bp->hood_weight;
        }
    slack -= ((nhandles - 1) * toothslack);

/*
    printf ("NEW CLIQUE SLACK: %f\n", slack);
    fflush (stdout);
*/

    if (slack >= -BLOTOLERANCE) {
        for (bp = combs; bp; bp = bnext) {
            bnext = bp->next;
            Xblockptrfree (bp);
        }
        return 0;
    }
    teeth = (Xnodeptrptr *) NULL;
    handles = (Xnodeptrptr *) NULL;
    markblock (bigtooth, (Xcutnode *) NULL, &tooth);
    Xadd_nodeptrptr (&teeth, tooth);

    for (bp = combs; bp; bp = bp->next)
        if (bp->this->mark) {
            markblock (bp->this, (Xcutnode *) NULL, &handle);
            Xadd_nodeptrptr (&handles, handle);
            combslack (G, bp->this, bigtooth, &t, &teeth);
        }
    for (bp = combs; bp; bp = bnext) {
        bnext = bp->next;
        Xblockptrfree (bp);
    }
    if (!Xcliquefluff (G, &handles, &teeth)) {
        printf ("DE FLUFFED TO 0\n");
        fflush (stdout);
        return 0;
    }
    if (!Xviolated_clique_flow (G, handles, teeth, x)) {
        printf ("BANG!\n");
        fflush (stdout);
        Xfreeteeth (handles);
        Xfreeteeth (teeth);
        return 0;
    } else {
        test = Xloadcplane (list, (Xnodeptr *) NULL, handles, teeth, 0);
        if (!test) {
            Xfreeteeth (handles);
            Xfreeteeth (teeth);
        }
        return test;
    }

}

#ifdef CC_PROTOTYPE_ANSI
static int combslack (Xgraph *G, Xblock *handle, Xblock *fixtooth,
            double *slack, Xnodeptrptr **teeth)
#else
static int combslack (G, handle, fixtooth, slack, teeth)
Xgraph *G;
Xblock *handle, *fixtooth;
double *slack;
Xnodeptrptr **teeth;
#endif
{
    int nteeth, hood = 0;
    double max, total;
    Xedge *e;
    Xedgeptr *ep;
    Xnode *n;
    Xnodeptr *np;
    Xcutnode *c;
    Xcutnodeptr *cp;
    Xblock *b, *maxb = (Xblock *) NULL;
    Xblockptr *bp;
    Xnodeptr *tooth;

    /*
    printf ("combslack (%d, %d) ... \n", handle - blocklist,
                                         fixtooth - * blocklist);
    fflush (stdout);
    */

    nteeth = 1;
    total = fixtooth->weight + handle->weight;

    for (n = G->pseudonodelist->next; n; n = n->next)
        n->stacklabel = 0;
    for (np = fixtooth->members; np; np = np->next)
        np->this->stacklabel = 1;
    for (bp = fixtooth->neighbors; bp; bp = bp->next)
        for (np = bp->this->members; np; np = np->next)
            np->this->stacklabel = 1;

    G->magicnum++;
    for (ep = handle->one; ep; ep = ep->next) {
        e = ep->this;
        if (e->cends[0]->stacklabel != e->cends[1]->stacklabel) {
            e->cends[0]->magiclabel = G->magicnum;
            e->cends[1]->magiclabel = G->magicnum;
            nteeth++;
            total += 1.0;
            if (teeth) {
                Xmarktooth (e, &tooth);
                Xadd_nodeptrptr (teeth, tooth);
            }
        }
    }
    for (np = fixtooth->members; np; np = np->next)
        np->this->magiclabel = G->magicnum;

    for (cp = handle->cutnodes; cp; cp = cp->next) {
        c = cp->this;
        if (c->name->magiclabel != G->magicnum) {
            max = 0.0;
            for (bp = c->blocks; bp; bp = bp->next) {
                b = bp->this;
                if (b != handle) {
                    if (b->weight > max) {
                        hood = 0;
                        maxb = b;
                        max = b->weight;
                    }
                    if (bp->hood_weight > max) {
                        hood = 1;
                        maxb = b;
                        max = bp->hood_weight;
                    }
                }
            }
            if (max >= 0.5) {
                nteeth++;
                total += max;
                if (teeth) {
                    if (hood)
                        markblock (maxb, c, &tooth);
                    else
                        markblock (maxb, (Xcutnode *) NULL, &tooth);
                    Xadd_nodeptrptr (teeth, tooth);
                }
            }
        }
    }

    if (!(nteeth % 2))
        return 0;
    else {
        *slack = 1.5 + (0.5 * nteeth) - total;
        return 1;
    }
}
