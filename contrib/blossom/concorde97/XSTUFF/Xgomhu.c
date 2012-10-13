/**************************************************************************/
/*                                                                        */
/* EXPORTED FUNCTIONS:                                                    */
/*                                                                        */
/*  Xcuttree_node                                                         */
/*      *Xgomory_hu (Xgraph *G);                                           */
/*                                                                        */
/*  void                                                                  */
/*      Xcuttree_free (Xcuttree_node *n);                                  */
/*                                                                        */
/**************************************************************************/

#include "machdefs.h"
#include "util.h"
#include "Xsubtour.h"

#ifdef CC_PROTOTYPE_ANSI

static void
    addtonodeset (Xnodeset *s, Xnode *n),
    delfromnodeset (Xnodeset *s, Xnode *n),
    delfromedgeset (Xedgeset *s, Xedge *e),
    freenodeset (Xnodeset *s),
    gh_work (Xgraph *G, Xcuttree_node *n, Xnodeset *nlist, Xnodeset *special),
    splitset (Xnodeset *s, Xnodeset *a, Xnodeset *b, int n),
    mergeset (Xnodeset *s, Xnodeset *a),
    shrinkdown (Xnodeset *a, Xnode *pseudo, Xedgeset *esave, int num),
    unshrink (Xnode *pseudo, Xedgeset *esave, int num),
    paint (Xgraph *G, Xnode *n, int v);

static int
    countdescendants (Xcuttree_node *n),
    myrandnum (int n);

#else

static void
    addtonodeset (),
    delfromnodeset (),
    delfromedgeset (),
    freenodeset (),
    gh_work (),
    splitset (),
    mergeset (),
    shrinkdown (),
    unshrink (),
    paint ();

static int
    countdescendants (),
    myrandnum ();

#endif

#ifdef  DEBUG
#ifdef CC_PROTOTYPE_ANSI
static void
    dumpcutcadj (Xgraph *G);
#else
static void
    dumpcutcadj ();
#endif
#endif

/*
 gomory_hu returns a pointer to the root of a rooted cut tree.  The tree is
   described by the parent, sibling, and child pointers.
 cutval is the weight on the cut (or, edge) between a node and its parent.
 ndescendants is the total number of nodes in the subtree rooted at that
   node, including itself.  This is the size of the cut between that node and
   its parent.
 special is the special node for this node of the tree.
 nlist is a nodeset containing all of the nodes of the graph grouped with the
   special node.  nlist contains special.
 pseudonode and next are work area.
 The calling routine should call cuttree_free(root) after it is done with the
   cuttree.

 gomory_hu constructs the min-cut tree for the nodes with mark = 1.
 pseudonodelist is the head of a linked list of the nodes in the graph
*/


#ifdef CC_PROTOTYPE_ANSI
Xcuttree_node *Xgomory_hu (Xgraph *G)
#else
Xcuttree_node *Xgomory_hu (G)
Xgraph *G;
#endif
{
    Xnodeset special;
    Xnodeset nlist;
    Xnode *p;
    Xcuttree_node *root;
    Xnodeptr *pp;

    /* see if there's anything to do */
    p = G->pseudonodelist->next;
    while (p && p->mark != 1)
        p = p->next;
    /* BICO: WAS  for (p = pseudonodelist->next; p && p->mark==1; p=p->next);*/
    /* WHATS THIS? IF ALL NODES ARE MARKED WE GIVE UP? */
    if (!p) {
        return 0;
    }
    /* initialize root */
    root = Xcuttree_nodealloc ();
    root->parent = (Xcuttree_node *) NULL;
    root->sibling = (Xcuttree_node *) NULL;
    root->child = (Xcuttree_node *) NULL;
    root->cutval = 0.0;
    root->pseudonode = (Xnode *) NULL;
    root->nlist.head = root->nlist.tail = (Xnodeptr *) NULL;

    /* set up nlist & special */
    special.head = special.tail = (Xnodeptr *) NULL;
    nlist.head = nlist.tail = (Xnodeptr *) NULL;

    for (p = G->pseudonodelist->next; p; p = p->next) {
        addtonodeset (&nlist, p);
        if (p->mark == 1)
            addtonodeset (&special, p);
    }

    if (!special.head) {
        fprintf (stderr, "Big Whoa, calling initial gh_work\n");
        exit (1);
    }
    gh_work (G, root, &nlist, &special);

    /* restore pseudonodelist */
    G->npseudonodes = 0;
    G->pseudonodelist->next = (Xnode *) NULL;
    G->pseudonodelist->prev = (Xnode *) NULL;
    for (pp = nlist.head; pp; pp = pp->next) {
        pp->this->next = G->pseudonodelist->next;
        if (G->pseudonodelist->next)
            G->pseudonodelist->next->prev = pp->this;
        G->pseudonodelist->next = pp->this;
        pp->this->prev = G->pseudonodelist;
        G->npseudonodes++;
    }

    freenodeset (&nlist);
    freenodeset (&special);

    countdescendants (root);

    root->cutval = XMAXWEIGHT;

    return root;
}

#ifdef  DEBUG
#ifdef CC_PROTOTYPE_ANSI
static void dumpcutcadj (Xgraph *G)
#else
static void dumpcutcadj (G)
Xgraph *G;
#endif
{
    Xnode *p;
    Xedgeptr *ep;

    printf ("CADJ IN GOMORY_HU:\n");
    for (p = G->pseudonodelist->next; p; p = p->next) {
        printf ("NODE %d: ", p - G->nodelist);
        if (p->mark)
            printf ("(S) ");
        for (ep = p->cadj.head; ep; ep = ep->next) {
            printf ("%d", OTHERCURRENTEND (ep->this, p) - G->nodelist);
            printf ("(%f) ", ep->this->x);
        }
        printf ("\n");
    }
}
#endif /* DEBUG */

#ifdef CC_PROTOTYPE_ANSI
static void addtonodeset (Xnodeset *s, Xnode *n)
#else
static void addtonodeset (s, n)
Xnodeset *s;
Xnode *n;
#endif
{
    Xnodeptr *nnew;

    nnew = Xnodeptralloc ();
    nnew->this = n;
    nnew->next = s->head;
    s->head = nnew;
    if (!s->tail)
        s->tail = nnew;
}

#ifdef CC_PROTOTYPE_ANSI
static void delfromnodeset (Xnodeset *s, Xnode *n)
#else
static void delfromnodeset (s, n)
Xnodeset *s;
Xnode *n;
#endif
{
    Xnodeptr *oldn, *n1;

    oldn = (Xnodeptr *) NULL;
    n1 = s->head;
    while (n1 && n1->this != n) {
        oldn = n1;
        n1 = n1->next;
    }
    if (!n1) {
        fprintf (stderr, "Node vanished from sight\n");
        exit (1);
    }
    if (!oldn) {                /* deleting head */
        s->head = n1->next;
        if (!s->head)
            s->tail = (Xnodeptr *) NULL;
    } else {
        oldn->next = n1->next;
        if (!oldn->next)
            s->tail = oldn;
    }
    Xnodeptrfree (n1);
}

#ifdef CC_PROTOTYPE_ANSI
static void delfromedgeset (Xedgeset *s, Xedge *e)
#else
static void delfromedgeset (s, e)
Xedgeset *s;
Xedge *e;
#endif
{
    Xedgeptr *olde, *e1;

    olde = (Xedgeptr *) NULL;
    e1 = s->head;
    while (e1 && e1->this != e) {
        olde = e1;
        e1 = e1->next;
    }
    if (!e1) {
        fprintf (stderr, "Edge vanished from sight\n");
        exit (1);
    }
    if (!olde) {                /* deleting head */
        s->head = e1->next;
        if (!s->head)
            s->tail = (Xedgeptr *) NULL;
    } else {
        olde->next = e1->next;
        if (!olde->next)
            s->tail = olde;
    }
    Xedgeptrfree (e1);
}

#ifdef CC_PROTOTYPE_ANSI
static void freenodeset (Xnodeset *s)
#else
static void freenodeset (s)
Xnodeset *s;
#endif
{
    Xnodeptr *p, *pnext;

    for (p = s->head; p; p = pnext) {
        pnext = p->next;
        Xnodeptrfree (p);
    }
}

#ifdef CC_PROTOTYPE_ANSI
void Xcuttree_free (Xcuttree_node *n)
#else
void Xcuttree_free (n)
Xcuttree_node *n;
#endif
{
    Xcuttree_node *p, *pnext;

    for (p = n->child; p; p = pnext) {
        pnext = p->sibling;
        Xcuttree_free (p);
    }
    freenodeset (&n->nlist);
    Xcuttree_nodefree (n);
}

#ifdef CC_PROTOTYPE_ANSI
static int countdescendants (Xcuttree_node *n)
#else
static int countdescendants (n)
Xcuttree_node *n;
#endif
{
    Xcuttree_node *p;
    int i;

    i = 1;
    for (p = n->child; p; p = p->sibling)
        i += countdescendants (p);
    n->ndescendants = i;
    return i;
}

/* gh_work(n) expands the Xcuttree_node n. */

#ifdef CC_PROTOTYPE_ANSI
static void gh_work (Xgraph *G, Xcuttree_node *n, Xnodeset *nlist,
             Xnodeset *special)
#else
static void gh_work (G, n, nlist, special)
Xgraph *G;
Xcuttree_node *n;
Xnodeset *nlist, *special;
#endif
{
    Xnodeset a_nlist, b_nlist;
    Xnodeset a_special, b_special;
    Xcuttree_node *a_cut, *b_cut;
    Xcuttree_node *cp, *nextcp;
    Xnodeptr *p;
    double fv;
    Xedgeset esave;
    Xcuttree_node *newcut;
    Xnode newnode;
    Xnode *anode = (Xnode *) NULL;
    Xnode *bnode = (Xnode *) NULL;
    int i;
    Xnode *v;

    /* termination cases for the recursion */
    if (!special->head) {
        fprintf (stderr, "Whoa, gh_work called with a null special list\n");
        exit (1);
    }
    if (!special->head->next) {
        ++(G->magicnum);
        if (n->parent)
            n->parent->pseudonode->magiclabel = G->magicnum;
        for (cp = n->child; cp; cp = cp->sibling)
            cp->pseudonode->magiclabel = G->magicnum;
        n->special = special->head->this;
        n->nlist.head = n->nlist.tail = (Xnodeptr *) NULL;
        for (p = nlist->head; p; p = p->next)
            if (p->this->magiclabel != G->magicnum)
                addtonodeset (&n->nlist, p->this);
        return;
    }
    /* find the split */

    /* set up G->pseudonodelist so flow is happy */
    G->npseudonodes = 0;
    G->pseudonodelist->next = (Xnode *) NULL;
    for (p = nlist->head; p; p = p->next) {
        p->this->next = G->pseudonodelist->next;
        G->pseudonodelist->next = p->this;
        G->npseudonodes++;
    }

    for (p = special->head, i = 0; p; p = p->next) {
        i++;
        if (myrandnum (i) == 0)
            anode = p->this;
    }

    for (p = special->head, i = 0; p; p = p->next) {
        if (p->this != anode) {
            i++;
            if (myrandnum (i) == 0)
                bnode = p->this;
        }
    }

    fv = Xflow (G, anode, bnode, 1.0e10);

    paint (G, bnode, ++(G->magicnum));

    /* make the two new cuttree_nodes */

    /* divide them up */
    splitset (nlist, &a_nlist, &b_nlist, G->magicnum);
    splitset (special, &a_special, &b_special, G->magicnum);

    if (!a_special.head) {
        fprintf (stderr, "Yipes! a_special is null\n");
        if (!b_special.head)
            fprintf (stderr, "And so is b_special\n");
        exit (1);
    } else if (!b_special.head) {
        fprintf (stderr, "Yipes! b_special is null\n");
        printf ("SPECIAL: ");
        for (p = a_special.head; p; p = p->next)
            printf ("%d ", (int) (p->this - G->nodelist));
        printf ("\n");
        printf ("anode = %d  bnode = %d\n", (int) (anode - G->nodelist),
                (int) (bnode - G->nodelist));
        printf ("flow value = %f\n", fv);
        printf ("npseudonodes = %d\n", G->npseudonodes);
        Xdumppseudograph (G);
        fv = Xflow (G, anode, bnode, 10.0);
        printf ("new flow value = %f\n", fv);
        fflush (stdout);
        paint (G, bnode, ++(G->magicnum));
        printf ("MIN CUT: ");
        fflush (stdout);
        for (v = G->pseudonodelist->next; v; v = v->next)
            if (v->magiclabel == G->magicnum) {
                printf ("%d ", (int) (v - G->nodelist));
                fflush (stdout);
            }
        printf ("\n");
        Xdumppseudograph_edgelist (G);
        exit (1);
    }
    newcut = Xcuttree_nodealloc ();
    newcut->parent = n;
    newcut->sibling = (Xcuttree_node *) NULL;
    newcut->child = (Xcuttree_node *) NULL;
    newcut->cutval = fv;
    newcut->nlist.head = newcut->nlist.tail = (Xnodeptr *) NULL;

    if (n->parent && n->parent->pseudonode->magiclabel == G->magicnum) {
        a_cut = n;
        b_cut = newcut;
    } else {
        a_cut = newcut;
        b_cut = n;
    }

    /* divide the children up between the two sides */
    for (cp = n->child, n->child = (Xcuttree_node *) NULL,
                   newcut->child = (Xcuttree_node *) NULL; cp; cp = nextcp) {
        nextcp = cp->sibling;
        if (cp->pseudonode->magiclabel == G->magicnum) {
            cp->sibling = a_cut->child;
            a_cut->child = cp;
        } else {
            cp->sibling = b_cut->child;
            b_cut->child = cp;
        }
    }
    newcut->sibling = n->child;
    n->child = newcut;

    newnode.magiclabel = 0;
    newnode.stacklabel = 0;
    shrinkdown (&a_nlist, &newnode, &esave, G->magicnum);

    a_cut->pseudonode = (Xnode *) NULL;
    b_cut->pseudonode = &newnode;

    addtonodeset (&a_nlist, &newnode);

    gh_work (G, a_cut, &a_nlist, &a_special);

    delfromnodeset (&a_nlist, &newnode);

    ++(G->magicnum);
    for (p = b_nlist.head; p; p = p->next)
        p->this->magiclabel = G->magicnum;

    unshrink (&newnode, &esave, G->magicnum);

    shrinkdown (&b_nlist, &newnode, &esave, G->magicnum);

    a_cut->pseudonode = &newnode;
    b_cut->pseudonode = (Xnode *) NULL;

    addtonodeset (&b_nlist, &newnode);

    gh_work (G, b_cut, &b_nlist, &b_special);

    delfromnodeset (&b_nlist, &newnode);

    ++(G->magicnum);
    for (p = a_nlist.head; p; p = p->next)
        p->this->magiclabel = G->magicnum;

    unshrink (&newnode, &esave, G->magicnum);

    nlist->head = a_nlist.head;
    nlist->tail = a_nlist.tail;
    mergeset (nlist, &b_nlist);

    special->head = a_special.head;
    special->tail = a_special.tail;
    mergeset (special, &b_special);

    return;
}

#ifdef CC_PROTOTYPE_ANSI
static void splitset (Xnodeset *s, Xnodeset *a, Xnodeset *b, int n)
#else
static void splitset (s, a, b, n)
Xnodeset *s, *a, *b;
int n;
#endif
{
    Xnodeptr *p;
    Xnodeptr *pnext;

    a->head = a->tail = (Xnodeptr *) NULL;
    b->head = b->tail = (Xnodeptr *) NULL;
    for (p = s->head; p; p = pnext) {
        pnext = p->next;
        if (p->this->magiclabel == n) {
            p->next = a->head;
            a->head = p;
            if (!a->tail)
                a->tail = p;
        } else {
            p->next = b->head;
            b->head = p;
            if (!b->tail)
                b->tail = p;
        }
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void mergeset (Xnodeset *s, Xnodeset *a)
#else
static void mergeset (s, a)
Xnodeset *s, *a;
#endif
{
    Xnodeptr *p;
    Xnodeptr *pnext;

    for (p = a->head; p; p = pnext) {
        pnext = p->next;
        p->next = s->head;
        s->head = p;
        if (!s->tail)
            s->tail = p;
    }
}

/* shrink everything with G->magicnum != num to pseudo. a is a list of
 * everything with G->magicnum == num. */

#ifdef CC_PROTOTYPE_ANSI
static void shrinkdown (Xnodeset *a, Xnode *pseudo, Xedgeset *esave, int num)
#else
static void shrinkdown (a, pseudo, esave, num)
Xnodeset *a;
Xnode *pseudo;
Xedgeset *esave;
int num;
#endif
{
    Xedgeset enew;
    Xnodeptr *p;
    Xedgeptr *e, *enext;
    Xnode *x;
    double cumx;

    pseudo->cadj.head = pseudo->cadj.tail = (Xedgeptr *) NULL;
    esave->head = esave->tail = (Xedgeptr *) NULL;
    for (p = a->head; p; p = p->next) {
        cumx = 0.0;
        enew.head = enew.tail = (Xedgeptr *) NULL;
        for (e = p->this->cadj.head; e; e = enext) {
            enext = e->next;
            x = OTHERCURRENTEND (e->this, p->this);
            if (x->magiclabel != num) {
                cumx += e->this->x;
                e->next = esave->head;
                esave->head = e;
                if (!esave->tail)
                    esave->tail = e;
            } else {
                e->next = enew.head;
                enew.head = e;
                if (!enew.tail)
                    enew.tail = e;
            }
        }
        if (cumx > 0.0) {
            e = Xedgeptralloc ();
            e->this = Xedgealloc ();
            e->next = enew.head;
            enew.head = e;
            if (!enew.tail)
                enew.tail = e;
            e->this->cends[0] = p->this;
            e->this->cends[1] = pseudo;
            e->this->x = cumx;
            e->this->stay = 1;
            e = Xedgeptralloc ();
            e->this = enew.head->this;
            e->next = pseudo->cadj.head;
            pseudo->cadj.head = e;
            if (!pseudo->cadj.tail)
                pseudo->cadj.tail = e;
        }
        p->this->cadj.head = enew.head;
        p->this->cadj.tail = enew.tail;
    }
}

/* unshrink pseudo.  everything inside pseudo has been marked with num */

#ifdef CC_PROTOTYPE_ANSI
static void unshrink (Xnode *pseudo, Xedgeset *esave, int num)
#else
static void unshrink (pseudo, esave, num)
Xnode *pseudo;
Xedgeset *esave;
int num;
#endif
{
    Xedgeptr *e, *enext;
    Xnode *x;

    /* take out the new edges we added */
    for (e = pseudo->cadj.head; e; e = enext) {
        enext = e->next;
        x = OTHERCURRENTEND (e->this, pseudo);
        delfromedgeset (&x->cadj, e->this);
        Xedgefree (e->this);
        Xedgeptrfree (e);
    }

    /* put back the edges we deleted */
    for (e = esave->head; e; e = enext) {
        enext = e->next;
        x = e->this->cends[0];
        if (x->magiclabel == num)
            x = e->this->cends[1];
        e->next = x->cadj.head;
        x->cadj.head = e;
        if (!x->cadj.tail)
            x->cadj.tail = e;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void paint (Xgraph *G, Xnode *n, int v)
#else
static void paint (G, n, v)
Xgraph *G;
Xnode *n;
int v;
#endif
{
    Xedgeptr *epp;
    Xedge *ep;

    n->magiclabel = v;
    for (epp = n->cadj.head; epp; epp = epp->next) {
        ep = epp->this;
        if (ep->cends[0] == n) {
            if (ep->x + ep->flow > 0.0 &&
                    ep->cends[1]->magiclabel != G->magicnum)
                paint (G, ep->cends[1], v);
        } else {
            if (ep->x - ep->flow > 0.0 &&
                    ep->cends[0]->magiclabel != G->magicnum)
                paint (G, ep->cends[0], v);
        }
    }
}

/*
#define RAND_M 1771875
#define RAND_A 2416
#define RAND_C 374441

#ifdef CC_PROTOTYPE_ANSI
int myrandnum (int n)
#else
int myrandnum (n)
int n;
#endif
{
    static unsigned int seed = 473;

    seed = (seed * RAND_A + RAND_C) % RAND_M;
    return (n * seed) / RAND_M;
}
*/

#ifdef CC_PROTOTYPE_ANSI
static int myrandnum (int n)
#else
static int myrandnum (n)
int n;
#endif
{
    return (CCutil_lprand () % n);
}

