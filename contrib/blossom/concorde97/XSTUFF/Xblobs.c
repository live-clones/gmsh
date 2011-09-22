/**************************************************************************/
/*                                                                        */
/* EXPORTED FUNCTIONS:                                                    */
/*                                                                        */
/*    void                                                                */
/*        Xpancakex (Xgraph *G, double *x),                               */
/*        Xfreepancake (void),                                            */
/*        Xshrinksmallblobs (Xgraph *G, int rnum, int biggest),           */
/*        Xtightblobs (Xgraph *G);                                        */
/*                                                                        */
/*    int                                                                 */
/*        Xblobsviolated (Xgraph *G, Xcplane **list );                    */
/*                                                                        */
/**************************************************************************/

#include "machdefs.h"
#include "util.h"
#include "Xsubtour.h"

typedef struct pannode {
    struct panedge **edgelist;
    struct panedge **goodedge;
    int degree;
    struct vaseknode *vptr;
} pannode;

typedef struct panedge {
    double panweight;
    pannode *ends[2];
    int elim;
    int tag;
    struct vaseknode *a[2];
    struct vaseknode *roof;
    struct vaseknode *top;
    struct panedge *next;
    double rc;
    double realrc;
} panedge;

typedef struct vaseknode {
    struct vaseknode *parent;
    struct vaseknode *child;
    struct vaseknode *sibling;
    struct vaseknode *anc;
    struct vaseknode *ptr;
    struct vaseknode *qtr;
    struct vaseknode *listpointer;
    int b;
    int d;
    int n;
    int tag;
    int fringe;
    double y;
    double w;
    double mult;
    struct panedge *tree;
    struct panedge *junk;
    struct triomino *adj;
    struct triomino *scan;
} vaseknode;

typedef struct triomino {
    panedge *edge;
    vaseknode *end;
    struct triomino *next;
} triomino;


static panedge **panedgespace, *panedgelist;
static pannode *pannodelist;


#define XPOSITIVE 1

#define VNODEALLOC(vrequest) {                                          \
        if (vnodestack == (vaseknode *) NULL) {                         \
                printf ("Ran out of vnode supply\n");                   \
                exit (1);                                               \
        }                                                               \
        vrequest = vnodestack;                                          \
        vnodestack = vnodestack->ptr;                                   \
    }

#define VNODEFREE(vreturn) {                                            \
        vreturn->ptr = vnodestack;                                      \
        vnodestack = vreturn;                                           \
    }

#define TRIALLOC(trequest) {                                            \
        trequest = tristack;                                            \
        tristack = tristack->next;                                      \
    }

#define TRIFREE(treturn) {                                              \
        treturn->next = tristack;                                       \
        tristack = treturn;                                             \
    }

#define XSHORT 1000
#define XFEW 1

#ifdef CC_PROTOTYPE_ANSI

static void
    panalloc (Xgraph *G),
    buildpanadjlist (Xgraph *G),
    pancakemain (Xgraph *G),
    initpancake (Xgraph *G),
    buildfirsttree (Xgraph *G),
    decompositiontree (Xgraph *G),
    initdecompositiontree (Xgraph *G),
    drop (panedge *e, vaseknode *x),
    throw (vaseknode *x, vaseknode *y, panedge *e),
    trickledown (int i),
    hookup (vaseknode *parent, vaseknode *child),
    distribute (void),
    initdistribute (void),
    split (vaseknode *a),
    bruteforce (panedge *e),
    update (panedge *e),
    dealwith (panedge *e, vaseknode **pa),
    attach (panedge *e),
    magicrc (void),
    labeler (Xgraph *G, vaseknode *p),
    shrinkblob (Xgraph *G, vaseknode *v);

static int
    ssblob (Xgraph *G, vaseknode *v, int rnum, int biggest, int *shrunk);

static double
    min2 (panedge **elist),
    findbound (void),
    blnode (Xgraph *G, Xcplane **list, vaseknode *v, int *hit),
    tblob (Xgraph *G, vaseknode *v, int *count);

static vaseknode
    *anc (vaseknode *v),
    *vsmall (Xgraph *G, vaseknode *p),
    *newcomp (vaseknode *v, double w);

#else

static void
    panalloc (),
    buildpanadjlist (),
    pancakemain (),
    initpancake (),
    buildfirsttree (),
    decompositiontree (),
    initdecompositiontree (),
    drop (),
    throw (),
    trickledown (),
    hookup (),
    distribute (),
    initdistribute (),
    split (),
    bruteforce (),
    update (),
    dealwith (),
    attach (),
    magicrc (),
    labeler (),
    shrinkblob ();

static int
    ssblob ();

static double
    min2 (),
    findbound (),
    blnode (),
    tblob ();

static vaseknode
    *anc (),
    *vsmall (),
    *newcomp ();

#endif

#ifdef  DEBUG
#ifdef CC_PROTOTYPE_ANSI
static void
    dumpwork (void),
    dumpdecompositiontree (Xgraph *G),
    dumpvaseknodes (Xgraph *G, vaseknode *pv),
    printvaseknode (vaseknode *v);
#else
static void
    dumpdecompositiontree (),
    dumpwork (),
    dumpvaseknodes (),
    printvaseknode ();
#endif
#endif /* DEBUG */

#define XMAGICNODE 0

static int step = 0;
static vaseknode *root;
static vaseknode *vpannodes = (vaseknode *) NULL, *vnodehit;
static vaseknode *head, *tail;
static vaseknode *vnodestack = (vaseknode *) NULL;
static triomino *trisupply, *tristack;
static panedge *work;
static panedge **vheap;
static int vheapend = 0;
static int componentcount = 0;


#ifdef CC_PROTOTYPE_ANSI
void Xpancakex (Xgraph *G, double *x)
#else
void Xpancakex (G, x)
Xgraph *G;
double *x;
#endif
{
    double *dp;
    int i;
    panedge *pm;

    panalloc (G);
    Xloadx (G, x);

    for (i = G->nedges, pm = panedgelist, dp = x; i; i--, pm++)
        pm->panweight = -(*dp++);

    pancakemain (G);
}

#ifdef CC_PROTOTYPE_ANSI
static void panalloc (Xgraph *G)
#else
static void panalloc (G)
Xgraph *G;
#endif
{
    int i;
    Xedge *pe;
    panedge *pa;

    pannodelist = CC_SAFE_MALLOC (G->nnodes + 1000, pannode);
    panedgelist = CC_SAFE_MALLOC (G->nedges + 1000, panedge);
    if (!pannodelist || !panedgelist) {
        fprintf (stderr, "out of memory in panalloc\n");
        exit (1);
    }

    for (i = G->nedges, pa = panedgelist, pe = G->edgelist; i;
                                                       i--, pa++, pe++) {
        pa->ends[0] = pannodelist + (pe->ends[0] - G->nodelist);
        pa->ends[1] = pannodelist + (pe->ends[1] - G->nodelist);
    }

    buildpanadjlist (G);
}


#ifdef CC_PROTOTYPE_ANSI
static void buildpanadjlist (Xgraph *G)
#else
static void buildpanadjlist (G)
Xgraph *G;
#endif
{
    int i, *degrees, *pint;
    pannode *pv;
    panedge *pa, **edgespace;
    Xedge *pe;

    edgespace = CC_SAFE_MALLOC (G->nnodes + (G->nedges * 2) + 1000, panedge *);
    degrees = CC_SAFE_MALLOC (G->nnodes + 1000, int);
    if (!edgespace || !degrees) {
        fprintf (stderr, "out of memory in buildpadadjlist\n");
        exit (1);
    }
    panedgespace = edgespace;

    for (i = 0, pint = degrees; i < G->nnodes; i++)
        *pint++ = 0;

    for (i = 0, pe = G->edgelist; i < G->nedges; i++, pe++) {
        degrees[pe->ends[0] - G->nodelist]++;
        degrees[pe->ends[1] - G->nodelist]++;
    }

    for (i = 0, pint = degrees, pv = pannodelist; i < G->nnodes;
         i++, pint++, pv++) {
        if (*pint) {
            pv->edgelist = pv->goodedge = edgespace;
            edgespace += *pint + 1;
        } else
            pv->edgelist = pv->goodedge = (panedge **) NULL;
    }

    for (i = 0, pa = panedgelist; i < G->nedges; i++, pa++) {
        *(pa->ends[0]->goodedge++) = pa;
        *(pa->ends[1]->goodedge++) = pa;
    }

    for (i = 0, pv = pannodelist; i < G->nnodes; i++, pv++)
        *(pv->goodedge) = (panedge *) NULL;

    CC_FREE (degrees, int);
}

#ifdef CC_PROTOTYPE_ANSI
static void pancakemain (Xgraph *G)
#else
static void pancakemain (G)
Xgraph *G;
#endif
{
    initpancake (G);
    buildfirsttree (G);
    findbound ();
    /* printf ("decompositiontree: %lf\n", findbound ()); */
}

#ifdef CC_PROTOTYPE_ANSI
static void initpancake (Xgraph *G)
#else
static void initpancake (G)
Xgraph *G;
#endif
{
    int i;
    pannode *pn;
    vaseknode *pv;
    triomino *pt;

    vpannodes = CC_SAFE_MALLOC ((2 * G->nnodes) - 1 + 1000, vaseknode);
    if (!vpannodes) {
        fprintf (stderr, "out of memory in initpancake\n");
        exit (1);
    }

    for (i = G->nnodes, pn = pannodelist, pv = vpannodes; i; i--, pn++, pv++) {
        pv->parent = (vaseknode *) NULL;
        pv->child = (vaseknode *) NULL;
        pv->sibling = (vaseknode *) NULL;
        pv->adj = (triomino *) NULL;
        pv->n = 0;
        pv->b = 1;
        pv->anc = pv;
        pv->junk = (panedge *) NULL;
        pv->w = XBIGNEG;
        pv->y = 0.0;
        pn->vptr = pv;
    }

    vnodestack = vpannodes + G->nnodes;
    for (i = G->nnodes - 2, pv = vnodestack; i; i--, pv++)
        pv->ptr = pv + 1;
    pv->ptr = (vaseknode *) NULL;

    trisupply = CC_SAFE_MALLOC (2 * G->nedges + 1000, triomino);
    if (!trisupply) {
        fprintf (stderr, "out of memory in initpancake\n");
        exit (1);
    }

    tristack = trisupply;
    for (i = 2 * G->nedges - 1, pt = tristack; i; i--, pt++)
        pt->next = pt + 1;

    VNODEALLOC (head);
}

#ifdef CC_PROTOTYPE_ANSI
void Xfreepancake (void)
#else
void Xfreepancake ()
#endif
{
    CC_FREE (vpannodes, vaseknode);
    CC_FREE (trisupply, triomino);
    CC_FREE (vheap, panedge *);
    CC_FREE (pannodelist, pannode);
    CC_FREE (panedgelist, panedge);
    CC_FREE (panedgespace, panedge *);
}

#ifdef CC_PROTOTYPE_ANSI
static void buildfirsttree (Xgraph *G)
#else
static void buildfirsttree (G)
Xgraph *G;
#endif
{
    vaseknode *p;
    double parw;
    vaseknode *q;

    decompositiontree (G);
    distribute ();


    head->ptr = tail = root;
    p = head;
    do {
        p = p->ptr;
        parw = p->w;
        for (q = p->child; q != (vaseknode *) NULL; q = q->sibling) {
            q->mult = parw - q->w;
            if (q->child != (vaseknode *) NULL) {
                tail->ptr = q;
                tail = q;
            }
        }
    } while (p != tail);
    root->mult = -root->w;

    magicrc ();
}

#ifdef CC_PROTOTYPE_ANSI
static void decompositiontree (Xgraph *G)
#else
static void decompositiontree (G)
Xgraph *G;
#endif
{
    panedge *e;
    int i;
    double w, ub;
    vaseknode *x, *y;

    initdecompositiontree (G);

    for (componentcount = G->nnodes - 2; componentcount;) {
        for (;;) {
            e = *vheap;
            *vheap = vheap[vheapend--];
            trickledown (0);
            x = anc (e->ends[0]->vptr);
            y = anc (e->ends[1]->vptr);
            if (x != y)
                break;
            drop (e, x);
        }

        w = e->panweight;
        throw (x, y, e);

        ub = w + 0.01;

        while (vheapend >= 0 && (e = *vheap)->panweight < ub) {
            *vheap = vheap[vheapend--];
            trickledown (0);
            x = anc (e->ends[0]->vptr);
            y = anc (e->ends[1]->vptr);
            if (x != y)
                throw (x, y, e);
            else
                drop (e, x);
        }

        for (; vnodehit != (vaseknode *) NULL; vnodehit = vnodehit->ptr)
            if (vnodehit->n)
                root = newcomp (vnodehit, w);
    }
    i = vheapend + 1;
    while (i)
        drop (vheap[--i], root);
}

#ifdef CC_PROTOTYPE_ANSI
static void initdecompositiontree (Xgraph *G)
#else
static void initdecompositiontree (G)
Xgraph *G;
#endif
{
    int i;
    panedge *pe, **ph;
    pannode *pm;

    vnodehit = (vaseknode *) NULL;
    work = (panedge *) NULL;

    for (i = G->nedges, pe = panedgelist; i; i--, pe++)
        pe->tag = XFALSE;

    vheap = CC_SAFE_MALLOC (G->nedges + 1000, panedge *);
    if (!vheap) {
        fprintf (stderr, "out of memory in initdecompositiontree\n");
        exit (1);
    }

    pm = pannodelist + XMAGICNODE;
    for (i = G->nedges, pe = panedgelist, ph = vheap; i; i--, pe++)
        if (pe->ends[0] != pm && pe->ends[1] != pm)
            *(ph++) = pe;
        else
            pe->rc = pe->panweight;

    vheapend = (ph - vheap) - 1;
    for (i = vheapend / 2; i >= 0; i--)
        trickledown (i);
}

#ifdef CC_PROTOTYPE_ANSI
static void drop (panedge *e, vaseknode *x)
#else
static void drop (e, x)
panedge *e;
vaseknode *x;
#endif
{
    e->a[0] = e->ends[0]->vptr;
    e->a[1] = e->ends[1]->vptr;
    e->roof = x;
    e->rc = XPOSITIVE;
    e->next = work;
    work = e;
}

#ifdef  DEBUG
#ifdef CC_PROTOTYPE_ANSI
static void dumpwork (void)
#else
static void dumpwork ()
#endif
{
    panedge *pe;

    printf ("WORK: ");
    for (pe = work; pe != (panedge *) NULL; pe = pe->next)
        printf ("(%d, %d) -> ", pe->ends[0] - pannodelist,
                pe->ends[1] - pannodelist);
    printf ("NULL\n");
    fflush (stdout);
}
#endif /* DEBUG */


#ifdef  DEBUG
#ifdef CC_PROTOTYPE_ANSI
static void dumpdecompositiontree (Xgraph *G)
#else
static void dumpdecompositiontree (G)
Xgraph *G;
#endif
{
    int i;
    pannode *pn;

    printf ("Nodes of the decomposition tree:\n");
    for (i = 0, pn = pannodelist; i < G->nnodes; i++, pn++)
        if (pn != pannodelist + XMAGICNODE)
            dumpvaseknodes (G, pn->vptr);
    printf ("\n");
    fflush (stdout);
}
#endif /* DEBUG */

#ifdef  DEBUG
#ifdef CC_PROTOTYPE_ANSI
static void dumpvaseknodes (Xgraph *G, vaseknode *pv)
#else
static void dumpvaseknodes (G, pv)
Xgraph *G;
vaseknode *pv;
#endif
{
    /* dump vaseknodes whose smallest real pannode is v */

    vaseknode *p;

    for (p = pv->parent; p != (vaseknode *) NULL && vsmall (G, p) == pv;
                                                       p = p->parent) {
        printf ("Node %d: ", p - vpannodes);
        printvaseknode (p);
        printf ("\n");
    }
    fflush (stdout);
}
#endif /* DEBUG */

#ifdef CC_PROTOTYPE_ANSI
static vaseknode *vsmall (Xgraph *G, vaseknode *p)
#else
static vaseknode *vsmall (G, p)
Xgraph *G;
vaseknode *p;
#endif
{
    vaseknode *p1, *p2, *psmall = vpannodes + G->nnodes;

    if (p->child == (vaseknode *) NULL)
        return p;
    for (p1 = p->child; p1 != (vaseknode *) NULL; p1 = p1->sibling)
        if ((p2 = vsmall (G, p1)) < psmall)
            psmall = p2;
    return psmall;
}

#ifdef  DEBUG
#ifdef CC_PROTOTYPE_ANSI
static void printvaseknode (vaseknode *p)
#else
static void printvaseknode (p)
vaseknode *p;
#endif
{
    vaseknode *p1;
    panedge *pe;

    if (p->child != (vaseknode *) NULL) {
        for (p1 = p->child; p1 != (vaseknode *) NULL; p1 = p1->sibling)
            printf ("%d ", p1 - vpannodes);
    } else
        printf ("%d ", p - vpannodes);
    printf ("mult: %f ", p->mult);
    printf ("parent: %d ", p->parent - vpannodes);
    printf ("depth: %d ", p->d);
    printf ("b: %d ", p->b);
    printf ("junk: ");
    for (pe = p->junk; pe != (panedge *) NULL; pe = pe->next)
        printf ("(%d, %d) ", pe->ends[0] - pannodelist,
                pe->ends[1] - pannodelist);
    fflush (stdout);
}
#endif /* DEBUG */

#ifdef CC_PROTOTYPE_ANSI
static void throw (vaseknode *x, vaseknode *y, panedge *e)
#else
static void throw (x, y, e)
vaseknode *x, *y;
panedge *e;
#endif
{
    e->a[0] = x;
    e->a[1] = y;

    e->rc = 0.0;
    attach (e);

    if (!(x->n)) {
        x->n = 1;
        x->ptr = vnodehit;
        vnodehit = x;
    }
    if (!(y->n)) {
        y->n = 1;
        y->ptr = vnodehit;
        vnodehit = y;
    }
    e->next = work;
    work = e;
}

#ifdef CC_PROTOTYPE_ANSI
static vaseknode *anc (vaseknode *v)
#else
static vaseknode *anc (v)
vaseknode *v;
#endif
{
    vaseknode *hand, *va;

    hand = v;
    while (hand != hand->anc)
        hand = hand->anc;

    va = hand;
    for (hand = v; hand != va; hand = hand->anc)
        hand->anc = va;

    return va;
}

#ifdef CC_PROTOTYPE_ANSI
static void trickledown (int i)
#else
static void trickledown (i)
int i;
#endif
{
    panedge *memo;
    int k, minchild;

    memo = vheap[i];

    while ((k = (2 * i) + 2) <= vheapend) {
        minchild = (vheap[k - 1]->panweight <= vheap[k]->panweight ? k - 1 : k);

        if (memo->panweight > vheap[minchild]->panweight) {
            vheap[i] = vheap[minchild];
            i = minchild;
        } else {
            vheap[i] = memo;
            return;
        }
    }
    if (k - 1 == vheapend && memo->panweight > vheap[vheapend]->panweight) {
        vheap[i] = vheap[vheapend];
        i = vheapend;
    }
    vheap[i] = memo;
}

#ifdef CC_PROTOTYPE_ANSI
static vaseknode *newcomp (vaseknode *v, double w)
#else
static vaseknode *newcomp (v, w)
vaseknode *v;
double w;
#endif
{
    vaseknode *new, *stack;
    triomino *t;

    VNODEALLOC (new);
    new->parent = (vaseknode *) NULL;
    new->child = (vaseknode *) NULL;
    new->sibling = (vaseknode *) NULL;
    new->anc = new;
    new->n = 0;
    new->b = 0;
    new->w = w;
    new->adj = (triomino *) NULL;
    new->junk = (panedge *) NULL;
    new->tag = XFALSE;

    hookup (new, v);
    v->qtr = (vaseknode *) NULL;

    do {
        stack = v->qtr;
        for (t = v->adj; t != (triomino *) NULL; t = t->next) {
            t->edge->roof = new;
            v = t->end;
            if (v->n) {
                v->qtr = stack;
                stack = v;
                hookup (new, v);
                componentcount--;
            }
        }
    } while ((v = stack) != (vaseknode *) NULL);

    return new;
}

#ifdef CC_PROTOTYPE_ANSI
static void hookup (vaseknode *parent, vaseknode *child)
#else
static void hookup (parent, child)
vaseknode *parent, *child;
#endif
{
    child->n = 0;
    child->parent = parent;
    child->anc = parent;
    child->sibling = parent->child;
    parent->child = child;
}

#ifdef CC_PROTOTYPE_ANSI
static void distribute (void)
#else
static void distribute ()
#endif
{
    vaseknode *active;
    panedge *e, *f;

    initdistribute ();
    active = (vaseknode *) NULL;
    root->n = 0;

    for (e = work, work = (panedge *) NULL; e != (panedge *) NULL; e = f) {
        f = e->next;
        e->top = root;
        dealwith (e, &active);
    }

    while (work) {
        for (; active != (vaseknode *) NULL; active = active->ptr)
            if (active->n < XFEW)
                active->n = -1;
            else {
                active->n = 0;
                split (active);
            }
        for (e = work, work = (panedge *) NULL; e != (panedge *) NULL;
                                                                    e = f) {
            f = e->next;
            if (e->top->n >= 0) {
                update (e);
                dealwith (e, &active);
            } else
                bruteforce (e);
        }
        step = step / 2;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void initdistribute (void)
#else
static void initdistribute ()
#endif
{
    vaseknode *stack, *finger, *x;
    int maxd, twice, d;

    maxd = 0;

    root->d = 0;
    root->ptr = (vaseknode *) NULL;

    for (finger = root; finger != (vaseknode *) NULL; finger = stack) {
        stack = finger->ptr;
        finger->anc = root;
        if ((x = finger->child) != (vaseknode *) NULL) {
            d = finger->d + 1;
            do {
                x->d = d;
                x->ptr = stack;
                stack = x;
                x = x->sibling;
            } while (x != (vaseknode *) NULL);
            if (d > maxd)
                maxd = d;
        }
    }
    step = 1;
    twice = 2;
    while (twice < maxd) {
        step = twice;
        twice = step + step;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void split (vaseknode *a)
#else
static void split (a)
vaseknode *a;
#endif
{
    int mid, bot;
    vaseknode *stack, *hand, *foot, *memo, *x;

    mid = step + a->d;
    bot = step + mid;

    a->qtr = (vaseknode *) NULL;
    for (hand = a; hand != (vaseknode *) NULL; hand = stack) {
        stack = hand->qtr;
        if (hand->d == mid) {
            memo = hand->qtr;
            hand->qtr = (vaseknode *) NULL;
            for (foot = hand; foot != (vaseknode *) NULL; foot = stack) {
                stack = foot->qtr;
                foot->anc = hand;
                if (foot->d != bot) {
                    for (x = foot->child; x != (vaseknode *) NULL;
                         x = x->sibling) {
                        x->qtr = stack;
                        stack = x;
                    }
                }
            }
            hand->qtr = memo;
        } else
            for (x = hand->child; x != (vaseknode *) NULL; x = x->sibling) {
                x->qtr = stack;
                stack = x;
            }
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void bruteforce (panedge *e)
#else
static void bruteforce (e)
panedge *e;
#endif
{
    vaseknode *x, *y, *nx, *ny;
    int dx, dy;

    x = e->a[0];
    y = e->a[1];

    if (x == y) {
        printf ("Tough luck Pal 1.\n");
        exit (1);
    }
    dx = x->d;
    dy = y->d;

    while (dx > dy) {
        x = x->parent;
        dx--;
    }
    if (x == y) {
        printf ("Tough luck Pal 2.\n");
        exit (1);
    }
    while (dy > dx) {
        y = y->parent;
        dy--;
    }
    if (x == y) {
        printf ("Tough luck Pal 3.\n");
        exit (1);
    }
    nx = x->parent;
    ny = y->parent;
    while (nx != ny) {
        x = nx;
        y = ny;
        nx = x->parent;
        ny = y->parent;
    }

    e->a[0] = x;
    e->a[1] = y;

    e->roof = nx;
    /* if (e->rc > 0.0) { e->next = nx->junk; nx->junk = e; } else { e->tag =
     * XFALSE; attach (e); } */
    e->next = nx->junk;
    nx->junk = e;
}

#ifdef CC_PROTOTYPE_ANSI
static void update (panedge *e)
#else
static void update (e)
panedge *e;
#endif
{
    vaseknode *x, *y, *v;

    x = e->a[0]->anc;
    y = e->a[1]->anc;
    v = e->top;

    if (x == v) {
        if (y != v)
            e->a[1] = y;
    } else if (y == v)
        e->a[0] = x;
    else if (x != y) {
        e->a[0] = x;
        e->a[1] = y;
    } else {
        e->top = x;
        if (x->d > e->roof->d)
            e->roof = x;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void dealwith (panedge *e, vaseknode **pa)
#else
static void dealwith (e, pa)
panedge *e;
vaseknode **pa;
#endif
{
    if ((e->roof->d) - (e->a[0]->d) < XSHORT &&
        (e->roof->d) - (e->a[1]->d) < XSHORT)
        bruteforce (e);
    else {
        e->next = work;
        work = e;
        if (!e->top->n) {
            e->top->ptr = *pa;
            *pa = e->top;
        }
        (e->top->n)++;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void attach (panedge *e)
#else
static void attach (e)
panedge *e;
#endif
{
    triomino *cell;

    TRIALLOC (cell);
    cell->edge = e;
    cell->end = e->a[1];
    cell->next = e->a[0]->adj;
    e->a[0]->adj = cell;

    TRIALLOC (cell);
    cell->edge = e;
    cell->end = e->a[0];
    cell->next = e->a[1]->adj;
    e->a[1]->adj = cell;
}

#ifdef CC_PROTOTYPE_ANSI
static void magicrc (void)
#else
static void magicrc ()
#endif
{
    double a;
    panedge **pee, *pe;

    a = min2 ((pannodelist + XMAGICNODE)->edgelist);

    for (pee = (pannodelist + XMAGICNODE)->edgelist;
                (pe = *pee) != (panedge *) NULL; pee++)
        pe->rc -= a;

    (pannodelist + XMAGICNODE)->vptr->y += a;
}

#ifdef CC_PROTOTYPE_ANSI
static double min2 (panedge **elist)
#else
static double min2 (elist)
panedge **elist;
#endif
{
    double minweight, minweight2, td;
    panedge *e;

    if (elist == (panedge **) NULL || elist[0] == (panedge *) NULL ||
                                      elist[1] == (panedge *) NULL) {
        fprintf (stderr, "Vertex has degree < two\n");
        exit (1);
    }
    minweight = elist[0]->rc;
    minweight2 = elist[1]->rc;
    if (minweight > minweight2) {
        SWAP (minweight, minweight2, td);
    }
    for (elist += 2; (e = *elist) != (panedge *) NULL; elist++) {
        if (e->rc < minweight2) {
            minweight2 = e->rc;
            if (minweight > minweight2) {
                SWAP (minweight, minweight2, td);
            }
        }
    }
    return minweight2;
}

#ifdef CC_PROTOTYPE_ANSI
static double findbound (void)
#else
static double findbound ()
#endif
{
    vaseknode *p, *q, *stack;
    triomino *tri;
    panedge **pee, *pe;
    double tree_bound = 0.0;
    double star_bound = 0.0;
    double edge_bound = 0.0;

    root->ptr = (vaseknode *) NULL;
    root->n = 1;
    root->b = 0;


    for (p = stack = root; p; p = stack) {
        if (p->n) {
            p->n = 0;
            q = p->child;
            if (q)
                for (; q; q = q->sibling) {
                    q->ptr = stack;
                    stack = q;
                    q->n = 1;
                    q->b = 0;
                }
            else {
                stack = p->ptr;
                (p->parent->b)++;
                star_bound += p->y;
            }
            for (tri = p->adj; tri; tri = tri->next)
                edge_bound += tri->edge->rc;
        } else {
            stack = p->ptr;
            if (stack)
                (p->parent->b) += p->b;
            tree_bound -= (p->mult) * ((p->b) - 1);
        }
    }
    star_bound *= 2.0;
    edge_bound /= 2.0;

    for (pee = ((pannodelist + XMAGICNODE)->edgelist);
                 (pe = *pee) != (panedge *) NULL; pee++)
        if (pe->rc < 0.0)
            edge_bound += pe->rc;
    star_bound += (pannodelist + XMAGICNODE)->vptr->y * 2;

    return tree_bound + star_bound + edge_bound;
}

#ifdef CC_PROTOTYPE_ANSI
int Xblobsviolated (Xgraph *G, Xcplane **list)
#else
int Xblobsviolated (G, list)
Xgraph *G;
Xcplane **list;
#endif
{
    int hit = 0;

    blnode (G, list, root, &hit);
    return hit;
}

#ifdef CC_PROTOTYPE_ANSI
static double blnode (Xgraph *G, Xcplane **list, vaseknode *v, int *hit)
#else
static double blnode (G, list, v, hit)
Xgraph *G;
Xcplane **list;
vaseknode *v;
int *hit;
#endif
{
    double w = 0.0;
    double t;
    panedge *e;
    vaseknode *c;

    if (!v->child)
        return 0.0;
    else {
        for (e = v->junk; e; e = e->next)
            w += (G->edgelist + (e - panedgelist))->x;
        for (c = v->child; c; c = c->sibling)
            w += blnode (G, list, c, hit);
        t = v->b;
        if (w > t - 1.0 + XCUTTOLERANCE) {
            G->magicnum++;
            labeler (G, v);
            if (Xcutchecksout (G, G->magicnum)) {
                Xloadcplane_cut (G, list, G->magicnum);
                (*hit)++;
            } else {
                printf ("BAD BLOB");
                fflush (stdout);
            }
        }
        return w;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void labeler (Xgraph *G, vaseknode *p)
#else
static void labeler (G, p)
Xgraph *G;
vaseknode *p;
#endif
{
    vaseknode *c;

    if (!p->child)
        (G->nodelist + (p - vpannodes))->magiclabel = G->magicnum;
    else
        for (c = p->child; c; c = c->sibling)
            labeler (G, c);
}

#ifdef CC_PROTOTYPE_ANSI
void Xshrinksmallblobs (Xgraph *G, int rnum, int biggest)
#else
void Xshrinksmallblobs (G, rnum, biggest)
Xgraph *G;
int rnum;
int biggest;
#endif
{
    int shrunk = 0;

    ssblob (G, root, rnum, biggest, &shrunk);
}

#ifdef CC_PROTOTYPE_ANSI
static int ssblob (Xgraph *G, vaseknode *v, int rnum, int biggest, int *shrunk)
#else
static int ssblob (G, v, rnum, biggest, shrunk)
Xgraph *G;
vaseknode *v;
int rnum;
int biggest;
int *shrunk;
#endif
{
    int count = 0;
    vaseknode *c;
    static int s = 0;

    if (v->b < 3)
        return 0;
    else {
        for (c = v->child; c; c = c->sibling)
            count += ssblob (G, c, rnum, biggest, shrunk);
        if (count)
            return count;
        else {
            if (v->tag) {
                if (v->b <= biggest &&
                    (!rnum || (++s) % 2)) {
                    shrinkblob (G, v);
                    (*shrunk)++;
                }
                return 1;
            } else
                return 0;
        }
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void shrinkblob (Xgraph *G, vaseknode *v)
#else
static void shrinkblob (G, v)
Xgraph *G;
vaseknode *v;
#endif
{
    Xnode *first, *pn;

    G->magicnum++;
    labeler (G, v);
    first = G->pseudonodelist->next;
    while (first->magiclabel != G->magicnum)
        first = first->next;
    for (pn = first->next; pn; pn = pn->next)
        if (pn->magiclabel == G->magicnum)
            Xsimpleshrink (G, first, pn);
}

#ifdef CC_PROTOTYPE_ANSI
void Xtightblobs (Xgraph *G)
#else
void Xtightblobs (G)
Xgraph *G;
#endif
{
    int count = 0;

    tblob (G, root, &count);
    printf ("Number tight blobs: %d\n", count);
}

#ifdef CC_PROTOTYPE_ANSI
static double tblob (Xgraph *G, vaseknode *v, int *count)
#else
static double tblob (G, v, count)
Xgraph *G;
vaseknode *v;
int *count;
#endif
{
    double w = 0.0;
    double t;
    panedge *e;
    vaseknode *c;

    if (v->b < 3)
        return 0.0;
    else {
        for (e = v->junk; e; e = e->next)
            w += (G->edgelist + (e - panedgelist))->x;
        for (c = v->child; c; c = c->sibling)
            w += tblob (G, c, count);
        t = v->b;
        if (w > t - 1.0 - XEPSILON) {
            v->tag = 1;
            (*count)++;
        } else
            v->tag = 0;
        return w;
    }
}

