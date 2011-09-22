/**************************************************************************/
/*                                                                        */
/* EXPORTED FUNCTION:                                                     */
/*        int necklaces(Xcplane **, double *)                              */
/*                                                                        */
/**************************************************************************/

#include "machdefs.h"
#include "util.h"
#include "Xsubtour.h"
#include "Xpq.h"
#include "Xnecklac.h"

#ifdef CC_PROTOTYPE_ANSI

static void
    cliquelist_free (Xclique *),
    necklace_build_neckedges (double *),
    necklace_build_necklaces (PQ_node *),
    necklace_build_neckadj (void),
    necklace_destroy_neckadj (void),
    label_necklaces (PQ_node *),
    label_necklaces_work (PQ_node *),
    label_necklace (PQ_node *),
    label_edges (PQ_node *, PQ_node *, int),
    lift_ends (PQ_node *, PQ_node *),
    lift_edges (PQ_node *, PQ_node *),
    dump_necklaces (void),
    dump_necklace_work (PQ_node *),
    free_equation (Xeqn *),
    compute_toroots (PQ_node *),
    free_toroots (PQ_node *),
    eqn_addto (Xeqn *, Xeqn *),
    dump_intptr_list (Xintptr *),
    collect_neck_tooth_leaf (PQ_node *, int, int, Xnodeptr **),
    collect_neck_tooth_work (PQ_node *, int, int, Xnodeptr **, PQ_node *),
    binsys_init (bin_system *, int),
    binsys_elim (bin_system *, Xeqn *),
    binsys_random_solution (bin_system *),
    binsys_eval_pivot (bin_system *, Xeqn *),
    binsys_pop_sparse (bin_system *),
    binsys_free_system (bin_system *),
    ds_makeset (PQ_node *);

static int
    necklace_cuts (double *, Xcplane **, PQ_node *),
    neckedge_compare (const void *, const void *),
    count_necklaces (PQ_node *),
    find_node_label (PQ_node *),
    necklace_crunch_cuts (PQ_node *, Xcplane **),
    necklace_add_edge_to_sys (Xneckedge *, bin_system *),
    necklace_try_solutions (bin_system *, PQ_node *, Xcplane **, Xintptrptr **),
    find_label (Xintptr *, int),
    intptr_list_size (Xintptr *),
    intptrlist_equal (Xintptr *, Xintptr *),
    find_solution (Xintptr *, Xintptrptr *),
    necklace_checkout_solution (Xintptr *, PQ_node *, Xcplane **),
    count_labeled_children (PQ_node *),
    check_realization (PQ_node *, int, PQ_node **, PQ_node **),
    collect_necklace_label (PQ_node *),
    binsys_add_dense (bin_system *, Xeqn *),
    binsys_add_sparse (bin_system *, Xeqn *),
    binsys_force_zero (bin_system *, int);

static PQ_node
    *init_elems (PQ_node *elems),
    *necklace_build_cuttree (double *),
    *necklace_build_spantree (void),
    *ds_find (PQ_node *),
    *ds_link (PQ_node *, PQ_node *);

static Xeqn
    *necklace_edge_to_eqn (Xneckedge *);

static Xintptr
    *intptr_add (Xintptr *, Xintptr *),
    *intptr_add_destruc (Xintptr *, Xintptr *),
    *intptr_addto (Xintptr *, Xintptr *),
    *intptr_copy (Xintptr *),
    *binsys_random_minimal_solution (bin_system *),
    *binsys_list_solution (bin_system *);

static Xnodeptr
    *collect_necklace_tooth (PQ_node *, PQ_node *, PQ_node *, PQ_node *),
    *collect_necklace_handle (void);

static int
     add_clique_to_PQtree (Xclique *c, PQ_node *elems);
static PQ_node
     *clique_to_PQlist (Xclique *c, PQ_node *elems);
static int
     find_intptr_list (Xintptr *p, int n);

#else

static void
    cliquelist_free (),
    necklace_build_neckedges (),
    necklace_build_necklaces (),
    necklace_build_neckadj (),
    necklace_destroy_neckadj (),
    label_necklaces (),
    label_necklaces_work (),
    label_necklace (),
    label_edges (),
    lift_ends (),
    lift_edges (),
    dump_necklaces (),
    dump_necklace_work (),
    free_equation (),
    compute_toroots (),
    free_toroots (),
    eqn_addto (),
    dump_intptr_list (),
    collect_neck_tooth_leaf (),
    collect_neck_tooth_work (),
    binsys_init (),
    binsys_elim (),
    binsys_random_solution (),
    binsys_eval_pivot (),
    binsys_pop_sparse (),
    binsys_free_system (),
    ds_makeset ();

static int
    necklace_cuts (),
    neckedge_compare (),
    count_necklaces (),
    find_node_label (),
    necklace_crunch_cuts (),
    necklace_add_edge_to_sys (),
    necklace_try_solutions (),
    find_label (),
    intptr_list_size (),
    intptrlist_equal (),
    find_solution (),
    necklace_checkout_solution (),
    count_labeled_children (),
    check_realization (),
    collect_necklace_label (),
    binsys_add_dense (),
    binsys_add_sparse (),
    binsys_force_zero ();

static PQ_node
    *init_elems (),
    *necklace_build_cuttree (),
    *necklace_build_spantree (),
    *ds_find (),
    *ds_link ();

static Xeqn
    *necklace_edge_to_eqn ();

static Xintptr
    *intptr_add (),
    *intptr_add_destruc (),
    *intptr_addto (),
    *intptr_copy (),
    *binsys_random_minimal_solution (),
    *binsys_list_solution ();

static Xnodeptr
    *collect_necklace_tooth (),
    *collect_necklace_handle ();

static int
     add_clique_to_PQtree ();
static PQ_node
     *clique_to_PQlist ();
static int
     find_intptr_list ();


#endif

#define NECK_ENUM_CUTOFF 5
#define NECK_ENUM_NTRIES 50
#define NECK_NEXTTRY(x) (((x)*2)/3)

static int verbose = 0;
static int nnecklaces;
static PQ_node **necklist;
static Xneckedge *neckedgelist;
static int nneckedges;
static PQ_node *necknodelist;
static int magicneckedgenum = 0;
static Xgraph *G;

static Xclique *cliquelist = (Xclique *) NULL;
static int ncliques = 0;

#ifdef CC_PROTOTYPE_ANSI
int  Xnecklaces (Xgraph *Gin, Xcplane **list, double *x)
#else
int  Xnecklaces (Gin, list, x)
Xgraph *Gin;
Xcplane **list;
double *x;
#endif
{
    double szeit;
    PQ_node *pqroot;
    int k;

    G = Gin;

    szeit = CCutil_zeit ();

    printf ("CALLED NECKLACE ... (%d, %d)\n", G->nnodes, G->nedges);
    fflush (stdout);

    pqroot = necklace_build_cuttree (x);

    if (!pqroot) {
        return 0;
    }

    k = necklace_cuts (x, list, pqroot);

/*
    for (c = *list; c; c = c->next)
        if (c->handles)
            printcliquetree (c->handles, c->teeth);
        else
            printchvatalcomb (c->handle, c->teeth);
*/


    XPQ_free_all (pqroot, 1);
    CC_FREE (necknodelist, PQ_node);

    printf ("Time in Necklace: %2f\n", CCutil_zeit () - szeit);
    fflush (stdout);

    return k;
}

#ifdef CC_PROTOTYPE_ANSI
static int  necklace_cuts (double *x, Xcplane **list, PQ_node *pqroot)
#else
static int  necklace_cuts (x, list, pqroot)
double *x;
Xcplane **list;
PQ_node *pqroot;
#endif
{
    PQ_node *spanroot;
    int k;

    necklace_build_neckedges (x);

    necklace_build_necklaces (pqroot);

    necklace_build_neckadj ();

    spanroot = necklace_build_spantree ();

    if (!spanroot) {
        necklace_destroy_neckadj ();
        CC_FREE (necklist, PQ_node *);
        CC_FREE (neckedgelist, Xneckedge);
        return 0;
    }

    spanroot->toroot = (Xintptr *) NULL;
    compute_toroots (spanroot);

    k = necklace_crunch_cuts (pqroot, list);

    free_toroots (spanroot);
    necklace_destroy_neckadj ();
    CC_FREE (necklist, PQ_node *);
    CC_FREE (neckedgelist, Xneckedge);

    return k;
}

#ifdef CC_PROTOTYPE_ANSI
static PQ_node *necklace_build_cuttree (double *x)
#else
static PQ_node *necklace_build_cuttree (x)
double *x;
#endif
{
    int i;
    Xclique *cnext;
    PQ_node *token_elem;
    double szeit;

    for (i=0; i<G->nedges; i++) {
        G->edgelist[i].x = x[i];
    }
    cliquelist = (Xclique *) NULL;
    ncliques = 0;
    szeit = CCutil_zeit ();
    Xall_tightcuts (G, &cliquelist, &ncliques);
    printf ("Found %d tight cliques in %.2f seconds\n", ncliques,
                      CCutil_zeit () - szeit);

    necknodelist = CC_SAFE_MALLOC (G->nnodes, PQ_node);
    if (!necknodelist) {
        fprintf (stderr, "out of memory in necklace\n");
        exit (1);
    }

    token_elem = init_elems (necknodelist);

    while (cliquelist) {
        cnext = cliquelist->next;
        if (!add_clique_to_PQtree (cliquelist, necknodelist)) {
            XPQ_free_all (token_elem, 1);
            CC_FREE (necknodelist, PQ_node);
            cliquelist_free (cliquelist);
            printf ("ZZZ Necklace bailout\n");
            fflush (stdout);
            return (PQ_node *) NULL;
        }
        Xintptr_list_free (cliquelist->nodes);
        Xcliquefree (cliquelist);
        cliquelist = cnext;
    }
    return XPQ_find_root (token_elem);
}

#ifdef CC_PROTOTYPE_ANSI
static void cliquelist_free (Xclique *c)
#else
static void cliquelist_free (c)
Xclique *c;
#endif
{
    Xclique *cnext;

    while (c) {
        cnext = c->next;
        Xintptr_list_free (c->nodes);
        Xcliquefree (c);
        c = cnext;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static int neckedge_compare (const void *a, const void *b)
#else
static int neckedge_compare (a, b)
const void *a;
const void *b;
#endif
{
    if (((const Xneckedge *) a)->x < ((const Xneckedge *) b)->x) {
        return 1;
    } else if (((const Xneckedge *) a)->x > ((const Xneckedge *) b)->x) {
        return -1;
    } else {
        return 0;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void necklace_build_neckedges (double *x)
#else
static void necklace_build_neckedges (x)
double *x;
#endif
{
    int i;

    for (i=0; i<G->nnodes; i++) {
        necknodelist[i].adj = (Xneckedgeptr *) NULL;
        necknodelist[i].magiclabel = 0;
    }

    neckedgelist = CC_SAFE_MALLOC (G->nedges, Xneckedge);
    if (!neckedgelist) {
        fprintf (stderr, "out of memory in necklace\n");
        exit (1);
    }
    for (i=0, nneckedges = 0; i<G->nedges; i++) {
        if (x[i] > 0.0) {
            neckedgelist[nneckedges].x = x[i];
            neckedgelist[nneckedges].ends[0] = necknodelist + (G->edgelist[i].ends[0] - G->nodelist);
            neckedgelist[nneckedges].ends[1] = necknodelist + (G->edgelist[i].ends[1] - G->nodelist);
            neckedgelist[nneckedges].magiclabel = 0;
            nneckedges++;
        }
    }
    qsort ((char *) neckedgelist, nneckedges, sizeof (Xneckedge), neckedge_compare);
}

#ifdef CC_PROTOTYPE_ANSI
static void necklace_build_necklaces (PQ_node *pqroot)
#else
static void necklace_build_necklaces (pqroot)
PQ_node *pqroot;
#endif
{
    int neckspace;

    neckspace = count_necklaces (pqroot);

    necklist = CC_SAFE_MALLOC (neckspace, PQ_node *);
    if (!necklist) {
        fprintf (stderr, "out of memory in necklace\n");
        exit (1);
    }
    nnecklaces = 0;

    label_necklaces (pqroot);

    if (nnecklaces != neckspace) {
        fprintf (stderr, "ZZZ NECKLACE COUNTS WRONG (%d != %d)\n",neckspace, nnecklaces);
    }

    printf ("%d necklaces found, ",nnecklaces);
    fflush (stdout);

    if (verbose) {
        printf ("Necklaces:\n");
        dump_necklaces ();
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void necklace_build_neckadj (void)
#else
static void necklace_build_neckadj ()
#endif
{
    int i;

    for (i=0; i<nneckedges; i++) {
        Xadd_neckedgeptr (&neckedgelist[i].ends[0]->adj, &neckedgelist[i]);
        Xadd_neckedgeptr (&neckedgelist[i].ends[1]->adj, &neckedgelist[i]);
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void necklace_destroy_neckadj (void)
#else
static void necklace_destroy_neckadj ()
#endif
{
    int i;

    for (i=0; i<G->nnodes; i++) {
        Xneckedgeptr_list_free (necknodelist[i].adj);
        necknodelist[i].adj = (Xneckedgeptr *) NULL;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static int count_necklaces (PQ_node *x)
#else
static int count_necklaces (x)
PQ_node *x;
#endif
{
    int cnt = 0;
    PQ_node *z, *zprev, *znext;
    int childcount = 0;

    PQ_set_FOREACH (x->children_set, z, children_elem, zprev, znext) {
        cnt += count_necklaces (z);
        childcount++;
    }
    if (x->type == Q_NODE || (x->type == P_NODE && childcount == 2)) {
        cnt++;
    }
    return cnt;
}

#ifdef CC_PROTOTYPE_ANSI
static void label_necklaces (PQ_node *pqroot)
#else
static void label_necklaces (pqroot)
PQ_node *pqroot;
#endif
{
    int i;

    for (i=0; i<nneckedges; i++) {
        neckedgelist[i].cends[0] = neckedgelist[i].ends[0];
        neckedgelist[i].cends[1] = neckedgelist[i].ends[1];
        neckedgelist[i].necklabel = -1;
    }

    necklace_build_neckadj ();

    label_necklaces_work (pqroot);
/* label_necklaces_work destroys neckadj except for pqroot and magicnode */
    Xneckedgeptr_list_free (pqroot->adj);
    pqroot->adj = (Xneckedgeptr *) NULL;
    Xneckedgeptr_list_free (necknodelist[MAGICNODE].adj);
    necknodelist[MAGICNODE].adj = (Xneckedgeptr *) NULL;

    assert (nnecklaces < G->nnodes);
}

#ifdef CC_PROTOTYPE_ANSI
static void label_necklaces_work (PQ_node *n)
#else
static void label_necklaces_work (n)
PQ_node *n;
#endif
{
    PQ_node *z;
    PQ_node *zprev;
    PQ_node *znext;
    int cnt;

    cnt = 0;
    PQ_set_FOREACH (n->children_set, z, children_elem, zprev, znext) {
        cnt++;
        label_necklaces_work (z);
    }
    n->children_set.size = cnt;

    label_necklace (n);
}

#ifdef CC_PROTOTYPE_ANSI
static void label_necklace (PQ_node *n)
#else
static void label_necklace (n)
PQ_node *n;
#endif
{
    PQ_node *a, *b, *c;

    if (n->type == Q_NODE || (n->type == P_NODE && PQ_set_SIZE (n->children_set) == 2)) {
        a = PQ_set_LEFT_ELEM (n->children_set);
        assert (a);
        b = a->children_elem.ptr1;
        if (!b) {
            b = a->children_elem.ptr2;
        }
        assert (b);

        necklist[nnecklaces] = n;
        label_edges (a, b, nnecklaces);
        nnecklaces++;
    }

    if (n->type != LEAF_NODE) {
        PQ_set_FOREACH (n->children_set, a, children_elem, b, c) {
            lift_ends (a, n);
        }

        n->adj = (Xneckedgeptr *) NULL;
        PQ_set_FOREACH (n->children_set, a, children_elem, b, c) {
            lift_edges (a, n);
        }
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void label_edges (PQ_node *a, PQ_node *b, int n)
#else
static void label_edges (a, b, n)
PQ_node *a;
PQ_node *b;
int n;
#endif
{
    Xneckedgeptr *p;

    for (p = a->adj; p; p = p->next) {
        assert (p->this->cends[0] == a || p->this->cends[1] == a);
        if (p->this->cends[0] == b || p->this->cends[1] == b) {
            p->this->necklabel = n;
        }
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void lift_ends (PQ_node *a, PQ_node *n)
#else
static void lift_ends (a, n)
PQ_node *a;
PQ_node *n;
#endif
{
    Xneckedgeptr *p;

    for (p = a->adj; p; p = p->next) {
        if (p->this->cends[0] == a) {
            p->this->cends[0] = n;
        } else {
            assert (p->this->cends[1] == a);
            p->this->cends[1] = n;
        }
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void lift_edges (PQ_node *a, PQ_node *n)
#else
static void lift_edges (a, n)
PQ_node *a;
PQ_node *n;
#endif
{
    Xneckedgeptr *p, *pnext;

    for (p = a->adj; p; p = pnext) {
        pnext = p->next;
        if (p->this->cends[0] != n || p->this->cends[1] != n) {
            assert (p->this->cends[0] == n || p->this->cends[1] == n);
            p->next = n->adj;
            n->adj = p;
        } else {
            Xneckedgeptrfree (p);
        }
    }
    a->adj = (Xneckedgeptr *) NULL;
}

#ifdef CC_PROTOTYPE_ANSI
static void dump_necklaces (void)
#else
static void dump_necklaces ()
#endif
{
    int i;
    PQ_node *z, *znext, *zprev;
    int j;

    for (i=0; i<nnecklaces; i++) {
        printf ("%d:",i);
        PQ_set_FOREACH (necklist[i]->children_set, z, children_elem, zprev, znext) {
            if (z->type == Q_NODE || (z->type == P_NODE && PQ_set_SIZE (z->children_set) == 2)) {
                j = find_node_label (z);
                printf (" %d",j);
            } else if (z->type == LEAF_NODE) {
                printf (" n%d",z->number);
            } else {
                printf (" (");
                dump_necklace_work (z);
                printf (")");
            }
        }
        printf ("\n");
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void dump_necklace_work (PQ_node *x)
#else
static void dump_necklace_work (x)
PQ_node *x;
#endif
{
    PQ_node *z, *zprev, *znext;
    if (x->type == Q_NODE || (x->type == P_NODE && PQ_set_SIZE (x->children_set) == 2)) {
        printf ("%d ",find_node_label (x));
    } else if (x->type == LEAF_NODE) {
        printf ("n%d ",x->number);
    } else {
        PQ_set_FOREACH (x->children_set, z, children_elem, zprev, znext) {
            dump_necklace_work (z);
        }
    }
}

#ifdef CC_PROTOTYPE_ANSI
static int find_node_label (PQ_node *z)
#else
static int find_node_label (z)
PQ_node *z;
#endif
{
    int i;

    for (i=0; i<nnecklaces; i++) {
        if (necklist[i] == z) {
            return i;
        }
    }
    return -1;
}

#ifdef CC_PROTOTYPE_ANSI
static PQ_node *necklace_build_spantree (void)
#else
static PQ_node *necklace_build_spantree ()
#endif
{
    int i;
    int k;
    PQ_node *front, *back, *new;
    Xneckedge *e;
    Xneckedgeptr *it;
    PQ_node *root;
    int cnt;

    for (i=0; i<G->nnodes; i++) {
        ds_makeset (&necknodelist[i]);
    }
    for (i=0; i<nneckedges; i++) {
        neckedgelist[i].inspanning = 0;
    }

    for (i=0, k=G->nnodes-1; k && i < nneckedges; i++) {
        if (ds_find (neckedgelist[i].ends[0]) != ds_find (neckedgelist[i].ends[1])) {
            ds_link (ds_find (neckedgelist[i].ends[0]), ds_find (neckedgelist[i].ends[1]));
            neckedgelist[i].inspanning = 1;
            k--;
        }
    }
    if (k) {
        return (PQ_node *) NULL;
    }

    /* this is a bit clumsy; first we build the spanning tree, then we do
       a breadth-first search through it to root it */

    G->magicnum++;
    root = &necknodelist[0];
    cnt = 0;

    front = root;
    front->magiclabel = G->magicnum;
    cnt++;
    front->entered = (Xneckedge *) NULL;
    front->next = (PQ_node *) NULL;
    back = front;

    while (front) {
        for (it = front->adj; it; it = it->next) {
            e = it->this;
            if (e->inspanning) {
                new = (e->ends[0] == front) ? e->ends[1] : e->ends[0];
                if (new->magiclabel != G->magicnum) {
                    new->magiclabel = G->magicnum;
                    cnt++;
                    new->entered = e;
                    back->next = new;
                    back = new;
                    back->next = (PQ_node *) NULL;
                }
            }
        }
        front = front->next;
    }
    if (cnt < G->nnodes) {
        printf ("ZZZ !!!!LOST THE SPANNING TREE!!!!\n");
        fflush (stdout);
        return (PQ_node *) NULL;
    }
    return root;
}

#ifdef CC_PROTOTYPE_ANSI
static int necklace_crunch_cuts (PQ_node *pqroot, Xcplane **list)
#else
static int necklace_crunch_cuts (pqroot, list)
PQ_node *pqroot;
Xcplane **list;
#endif
{
    bin_system necksys;
    Xeqn *oneseqn;
    int i;
    Xintptr *tmp;
    int tried;
    Xintptrptr *found;
    int k;
    int trynext;
    int v;

    binsys_init (&necksys, nnecklaces);

    for (i=0; i<nneckedges; i++) {
        neckedgelist[i].insystem = neckedgelist[i].inspanning;
    }

    oneseqn = Xeqnalloc ();
    oneseqn->lhs = (Xintptr *) NULL;
    for (i = nnecklaces-1; i>=0; i--) {
        tmp = Xintptralloc ();
        tmp->this = i;
        tmp->next = oneseqn->lhs;
        oneseqn->lhs = tmp;
    }
    oneseqn->rhs = 1;

    if (binsys_add_dense (&necksys, oneseqn) != 1) {
        fprintf (stderr, "ZZZ ODDNESS CONSTRAINT FAILED\n");
    }
    printf ("1"); fflush (stdout);

    found = (Xintptrptr *) NULL;
    k = 0;
    trynext = NECK_NEXTTRY (nnecklaces);

    tried = 0;
    for (i=0; i<nneckedges && necksys.nfreevars > NECK_ENUM_CUTOFF; i++) {
        if (!neckedgelist[i].inspanning) {
            v = necklace_add_edge_to_sys (&neckedgelist[i], &necksys);
            if (v == 1) {
                neckedgelist[i].insystem = 1;
                printf ("+"); fflush (stdout);
                tried = 0;
                if (necksys.nfreevars <= trynext) {
                    printf (" (%.2f:%d)",neckedgelist[i].x,necksys.nfreevars);
                    fflush (stdout);
                    k += necklace_try_solutions (&necksys, pqroot, list, &found);
                    printf ("\n"); fflush (stdout);
                    tried = 1;
                    trynext = NECK_NEXTTRY (trynext);
                }
            } else if (v == 0) {
                neckedgelist[i].insystem = 1;
                printf ("."); fflush (stdout);
            } else {
                printf ("-"); fflush (stdout);
            }
        }
    }
    if (!tried) {
        printf (" (%.2f:%d)",neckedgelist[i-1].x,necksys.nfreevars);
        fflush (stdout);
        k += necklace_try_solutions (&necksys, pqroot, list, &found);
        printf ("\n"); fflush (stdout);
    }

    Xintptrptr_list_freeall (found);
    binsys_free_system (&necksys);
    return k;
}

#ifdef CC_PROTOTYPE_ANSI
static Xeqn *necklace_edge_to_eqn (Xneckedge *e)
#else
static Xeqn *necklace_edge_to_eqn (e)
Xneckedge *e;
#endif
{
    Xeqn *neweqn;
    Xintptr *tmp;

    neweqn = Xeqnalloc ();
    neweqn->lhs = intptr_add (e->ends[0]->toroot, e->ends[1]->toroot);
    if (e->necklabel != -1) {
        tmp = Xintptralloc ();
        tmp->this = e->necklabel;
        tmp->next = (Xintptr *) NULL;
        neweqn->lhs = intptr_add_destruc (neweqn->lhs, tmp);
    }
    neweqn->rhs = 0;
    return neweqn;
}

#ifdef CC_PROTOTYPE_ANSI
static int necklace_add_edge_to_sys (Xneckedge *e, bin_system *s)
#else
static int necklace_add_edge_to_sys (e, s)
Xneckedge *e;
bin_system *s;
#endif
{
    Xeqn *neweqn;

    neweqn = necklace_edge_to_eqn (e);
    return binsys_add_sparse (s, neweqn);
}

#ifdef CC_PROTOTYPE_ANSI
static int necklace_try_solutions (bin_system *necksys, PQ_node *pqroot, Xcplane **list, Xintptrptr **found)
#else
static int necklace_try_solutions (necksys, pqroot, list, found)
bin_system *necksys;
PQ_node *pqroot;
Xcplane **list;
Xintptrptr **found;
#endif
{
    int i;
    int k = 0;
    Xintptr *sollst;
    Xintptrptr *new;

    for (i=0; i<NECK_ENUM_NTRIES; i++) {
        sollst = binsys_random_minimal_solution (necksys);
        if (intptr_list_size (sollst) >= 3 &&
            !find_solution (sollst, *found)) {
            new = Xintptrptralloc ();
            new->this = sollst;
            new->next = *found;
            *found = new;
            k += necklace_checkout_solution (sollst, pqroot, list);
        } else {
            Xintptr_list_free (sollst);
        }
    }
    return k;
}

#ifdef CC_PROTOTYPE_ANSI
static void free_equation (Xeqn *sys)
#else
static void free_equation (sys)
Xeqn *sys;
#endif
{
    Xintptr_list_free (sys->lhs);
    Xeqnfree (sys);
}

#ifdef CC_PROTOTYPE_ANSI
static void compute_toroots (PQ_node *n)
#else
static void compute_toroots (n)
PQ_node *n;
#endif
{
    Xneckedgeptr *ep;
    Xneckedge *e;
    PQ_node *m;
    Xintptr tmp;

    for (ep = n->adj; ep; ep=ep->next) {
        if (ep->this->inspanning) {
            e = ep->this;
            m = (e->ends[0] == n) ? e->ends[1] : e->ends[0];
            if (m->entered == e) {
                if (e->necklabel != -1) {
                    tmp.this = e->necklabel;
                    tmp.next = (Xintptr *) NULL;
                    m->toroot = intptr_add (n->toroot, &tmp);
                } else {
                    m->toroot = intptr_copy (n->toroot);
                }
                compute_toroots (m);
            }
        }
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void free_toroots (PQ_node *n)
#else
static void free_toroots (n)
PQ_node *n;
#endif
{
    Xneckedgeptr *ep;
    Xneckedge *e;
    PQ_node *m;

    for (ep = n->adj; ep; ep=ep->next) {
        if (ep->this->inspanning) {
            e = ep->this;
            m = (e->ends[0] == n) ? e->ends[1] : e->ends[0];
            if (m->entered == e) {
                free_toroots (m);
            }
        }
    }
    Xintptr_list_free (n->toroot);
    n->toroot = (Xintptr *) NULL;
}

#ifdef CC_PROTOTYPE_ANSI
static Xintptr *intptr_add (Xintptr *a, Xintptr *b)
#else
static Xintptr *intptr_add (a, b)
Xintptr *a;
Xintptr *b;
#endif
{
    Xintptr *sum;
    Xintptr **sumend;

    sum = (Xintptr *) NULL;
    sumend = &sum;

    while (a && b) {
        if (a->this == b->this) {
            a = a->next;
            b = b->next;
        } else if (a->this < b->this) {
            *sumend = Xintptralloc ();
            (*sumend)->this = a->this;
            sumend = & (*sumend)->next;
            a = a->next;
        } else {
            assert (a->this > b->this);
            *sumend = Xintptralloc ();
            (*sumend)->this = b->this;
            sumend = & (*sumend)->next;
            b = b->next;
        }
    }
    if (a) {
        *sumend = intptr_copy (a);
    } else if (b) {
        *sumend = intptr_copy (b);
    } else {
        *sumend = (Xintptr *) NULL;
    }
    return sum;
}

#ifdef CC_PROTOTYPE_ANSI
static Xintptr *intptr_add_destruc (Xintptr *a, Xintptr *b)
#else
static Xintptr *intptr_add_destruc (a, b)
Xintptr *a;
Xintptr *b;
#endif
{
    Xintptr *sum;
    Xintptr **sumend;
    Xintptr *tnext;

    sum = (Xintptr *) NULL;
    sumend = &sum;

    while (a && b) {
        if (a->this == b->this) {
            tnext = a->next;
            Xintptrfree (a);
            a = tnext;
            tnext = b->next;
            Xintptrfree (b);
            b = tnext;
        } else if (a->this < b->this) {
            *sumend = a;
            sumend = &a->next;
            a = a->next;
        } else {
            assert (a->this > b->this);
            *sumend = b;
            sumend = &b->next;
            b = b->next;
        }
    }
    if (a) {
        *sumend = a;
    } else if (b) {
        *sumend = b;
    } else {
        *sumend = (Xintptr *) NULL;
    }
    return sum;
}

/* destroys a, but leaves b alone */
#ifdef CC_PROTOTYPE_ANSI
static Xintptr *intptr_addto (Xintptr *a, Xintptr *b)
#else
static Xintptr *intptr_addto (a, b)
Xintptr *a;
Xintptr *b;
#endif
{
    Xintptr *sum;
    Xintptr **sumend;
    Xintptr *tnext;

    sum = (Xintptr *) NULL;
    sumend = &sum;

    while (a && b) {
        if (a->this == b->this) {
            tnext = a->next;
            Xintptrfree (a);
            a = tnext;
            b = b->next;
        } else if (a->this < b->this) {
            *sumend = a;
            sumend = &a->next;
            a = a->next;
        } else {
            assert (a->this > b->this);
            *sumend = Xintptralloc ();
            (*sumend)->this = b->this;
            sumend = & (*sumend)->next;
            b = b->next;
        }
    }
    if (a) {
        *sumend = a;
    } else if (b) {
        *sumend = intptr_copy (b);
    } else {
        *sumend = (Xintptr *) NULL;
    }
    return sum;
}

#ifdef CC_PROTOTYPE_ANSI
static Xintptr *intptr_copy (Xintptr *a)
#else
static Xintptr *intptr_copy (a)
Xintptr *a;
#endif
{
    Xintptr *sum;
    Xintptr **sumend;

    sum = (Xintptr *) NULL;
    sumend = &sum;

    while (a) {
        *sumend = Xintptralloc ();
         (*sumend)->this = a->this;
        sumend = & (*sumend)->next;
        a = a->next;
    }
    *sumend = (Xintptr *) NULL;
    return sum;
}

#ifdef CC_PROTOTYPE_ANSI
static void eqn_addto (Xeqn *a, Xeqn *b)
#else
static void eqn_addto (a, b)
Xeqn *a;
Xeqn *b;
#endif
{
    a->lhs = intptr_addto (a->lhs, b->lhs);
    a->rhs ^= b->rhs;
}

#ifdef CC_PROTOTYPE_ANSI
static void dump_intptr_list (Xintptr *p)
#else
static void dump_intptr_list (p)
Xintptr *p;
#endif
{
    if (p) {
        printf ("%d",p->this);
        p = p->next;
    }
    while (p) {
        printf (" %d",p->this);
        p = p->next;
    }
    fflush (stdout);
}

#ifdef CC_PROTOTYPE_ANSI
static int find_label (Xintptr *e, int label)
#else
static int find_label (e, label)
Xintptr *e;
int label;
#endif
{
    while (e) {
        if (e->this == label) return 1;
        if (e->this > label) return 0;
        e = e->next;
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int intptr_list_size (Xintptr *p)
#else
static int intptr_list_size (p)
Xintptr *p;
#endif
{
    int i;

    for (i=0; p; p = p->next) {
        i++;
    }
    return i;
}

#ifdef CC_PROTOTYPE_ANSI
static int intptrlist_equal (Xintptr *a, Xintptr *b)
#else
static int intptrlist_equal (a, b)
Xintptr *a;
Xintptr *b;
#endif
{
    while (a && b) {
        if (a->this != b->this) {
            return 0;
        }
        a = a->next;
        b = b->next;
    }
    return (a == b);
}

#ifdef CC_PROTOTYPE_ANSI
static int find_solution (Xintptr *sollst, Xintptrptr *found)
#else
static int find_solution (sollst, found)
Xintptr *sollst;
Xintptrptr *found;
#endif
{
    while (found) {
        if (intptrlist_equal (sollst, found->this)) {
            return 1;
        }
        found = found->next;
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int necklace_checkout_solution (Xintptr *sollst, PQ_node *pqroot, Xcplane **list)
#else
static int necklace_checkout_solution (sollst, pqroot, list)
Xintptr *sollst;
PQ_node *pqroot;
Xcplane **list;
#endif
{
    int cnt;
    Xintptr *p;
    PQ_node *lefthalf, *righthalf;
    Xnodeptrptr *teeth;
    Xnodeptrptr *handles;
    Xnodeptrptr *npp;
    int test;

    if (verbose) {
        printf ("New minimal solution: ");
        dump_intptr_list (sollst);
        printf ("\n");
        fflush (stdout);
    } else {
        printf (".");
        fflush (stdout);
    }

    G->magicnum++;
    for (p = sollst, cnt = 0; p; p = p->next) {
        cnt++;
        necklist[p->this]->magiclabel = G->magicnum;
    }

    if (count_labeled_children (pqroot) != cnt) {
        fprintf (stderr, "Lost some labels\n");
        exit (1);
    }

    for (p = sollst; p; p = p->next) {
        if (!check_realization (necklist[p->this], cnt, &lefthalf, &righthalf)) {
            if (verbose) {
                printf ("Unrealizable!!\n");
            }
            return 0;
        }
    }
    if (verbose) {
        printf ("Realizable\n");
    } else {
        printf ("+");
        fflush (stdout);
    }

    magicneckedgenum++;

    teeth = (Xnodeptrptr *) NULL;
    for (p = sollst; p; p = p->next) {
        if (!check_realization (necklist[p->this], cnt, &lefthalf, &righthalf)) {
            fprintf (stderr, "ZZZ Whoops, necklace broke\n");
            exit (1);
        }
        npp = Xnodeptrptralloc ();
        npp->this = collect_necklace_tooth (lefthalf, righthalf, necklist[p->this], pqroot);
        npp->next = teeth;
        teeth = npp;
    }
    handles = Xnodeptrptralloc ();
    handles->next = (Xnodeptrptr *) NULL;
    handles->this = collect_necklace_handle ();

    if (!Xcliquefluff (G, &handles, &teeth)) {
        printf ("ZZZ NECKLACE DE FLUFFED TO 0\n");
        fflush (stdout);
        return 0;
    }

    test = Xloadcplane (list, (Xnodeptr *) NULL, handles, teeth, 0);
    if (!test) {
        Xfreeteeth (handles);
        Xfreeteeth (teeth);
        printf ("-");
        fflush (stdout);
    } else {
        printf ("YES ");
        fflush (stdout);
    }

    return test;
}

#ifdef CC_PROTOTYPE_ANSI
static int count_labeled_children (PQ_node *x)
#else
static int count_labeled_children (x)
PQ_node *x;
#endif
{
    int cnt = 0;
    PQ_node *z, *zprev, *znext;

    PQ_set_FOREACH (x->children_set, z, children_elem, zprev, znext) {
        cnt += count_labeled_children (z);
    }
    if (x->magiclabel == G->magicnum) {
        cnt++;
    }
    x->labeled_children_count = cnt;
    return cnt;
}

#ifdef CC_PROTOTYPE_ANSI
static int check_realization (PQ_node *x, int fullcnt, PQ_node **lefthalf, PQ_node **righthalf)
#else
static int check_realization (x, fullcnt, lefthalf, righthalf)
PQ_node *x;
int fullcnt;
PQ_node **lefthalf;
PQ_node **righthalf;
#endif
{
    PQ_node *z, *zprev, *znext;

    PQ_set_FOREACH (x->children_set, z, children_elem, zprev, znext) {
        if (zprev && z->labeled_children_count == 0 && zprev->labeled_children_count == 0) {
            *lefthalf = zprev;
            *righthalf = z;
            return 1;
        }
    }
    if (x->labeled_children_count == fullcnt) {
        if (PQ_set_RIGHT_ELEM (x->children_set)->labeled_children_count == 0) {
            *lefthalf = PQ_set_RIGHT_ELEM (x->children_set);
            *righthalf = (PQ_node *) NULL;
            return 1;
        }
        if (PQ_set_LEFT_ELEM  (x->children_set)->labeled_children_count == 0) {
            *lefthalf = PQ_set_LEFT_ELEM (x->children_set);
            *righthalf = (PQ_node *) NULL;
            return 1;
        }
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static Xnodeptr *collect_necklace_tooth (PQ_node *lefthalf, PQ_node *righthalf, PQ_node *x, PQ_node *pqroot)
#else
static Xnodeptr *collect_necklace_tooth (lefthalf, righthalf, x, pqroot)
PQ_node *lefthalf;
PQ_node *righthalf;
PQ_node *x;
PQ_node *pqroot;
#endif
{
    Xnodeptr *tooth;

    tooth = (Xnodeptr *) NULL;

    if (!lefthalf) {
        lefthalf = righthalf;
        righthalf = (PQ_node *) NULL;
    }
    G->magicnum++;
    collect_neck_tooth_work (lefthalf, 0, G->magicnum, &tooth, (PQ_node *) NULL);
    if (righthalf) {
        collect_neck_tooth_work (righthalf, 1, G->magicnum, &tooth, (PQ_node *) NULL);
    } else {
        collect_neck_tooth_work (pqroot, 1, G->magicnum, &tooth, x);
        collect_neck_tooth_leaf (&necknodelist[MAGICNODE], 1, G->magicnum, &tooth);
    }
    return tooth;
}

#ifdef CC_PROTOTYPE_ANSI
static void collect_neck_tooth_leaf (PQ_node *x, int mode, int label, Xnodeptr **list)
#else
static void collect_neck_tooth_leaf (x, mode, label, list)
PQ_node *x;
int mode;
int label;
Xnodeptr **list;
#endif
{
    Xnodeptr *np;
    Xneckedgeptr *ep;
    PQ_node *y;

    np = Xnodeptralloc ();
    np->this = G->nodelist + x->number;
    np->next = *list;
    *list = np;
    if (mode == 0) {
        x->magiclabel = label;
    } else {
        for (ep = x->adj; ep; ep = ep->next) {
            y = ep->this->ends[0];
            if (y == x) y = ep->this->ends[1];
            if (y->magiclabel == label) {
                ep->this->magiclabel = magicneckedgenum;
            }
        }
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void collect_neck_tooth_work (PQ_node *x, int mode, int label, Xnodeptr **list, PQ_node *avoid)
#else
static void collect_neck_tooth_work (x, mode, label, list, avoid)
PQ_node *x;
int mode;
int label;
Xnodeptr **list;
PQ_node *avoid;
#endif
{
    PQ_node *z, *zprev, *znext;

    if (x == avoid) return;
    if (x->type == LEAF_NODE) {
        collect_neck_tooth_leaf (x, mode, label, list);
    } else {
        PQ_set_FOREACH (x->children_set, z, children_elem, zprev, znext) {
            collect_neck_tooth_work (z, mode, label, list, avoid);
        }
    }
}

#ifdef CC_PROTOTYPE_ANSI
static Xnodeptr *collect_necklace_handle (void)
#else
static Xnodeptr *collect_necklace_handle ()
#endif
{
    Xnodeptr *handle;
    int cnt;
    Xnodeptr *np;
    int i;

    G->magicnum++;
    cnt = collect_necklace_label (necknodelist);
    handle = (Xnodeptr *) NULL;
    if (cnt*2 < G->nnodes) {
        for (i=0; i<G->nnodes; i++) {
            if (necknodelist[i].magiclabel == G->magicnum) {
                np = Xnodeptralloc ();
                np->this = &(G->nodelist[i]);
                np->next = handle;
                handle = np;
            }
        }
    } else {
        for (i=0; i<G->nnodes; i++) {
            if (necknodelist[i].magiclabel != G->magicnum) {
                np = Xnodeptralloc ();
                np->this = &(G->nodelist[i]);
                np->next = handle;
                handle = np;
            }
        }
    }
    return handle;
}

#ifdef CC_PROTOTYPE_ANSI
static int collect_necklace_label (PQ_node *x)
#else
static int collect_necklace_label (x)
PQ_node *x;
#endif
{
    int cnt;
    Xneckedgeptr *ep;
    PQ_node *y;

    x->magiclabel = G->magicnum;
    cnt = 1;

    for (ep = x->adj; ep; ep = ep->next) {
        if (ep->this->magiclabel != magicneckedgenum && ep->this->insystem) {
            y = ep->this->ends[0];
            if (y == x) y = ep->this->ends[1];
            if (y->magiclabel != G->magicnum) {
                cnt += collect_necklace_label (y);
            }
        }
    }
    return cnt;
}

#ifdef CC_PROTOTYPE_ANSI
static void binsys_init (bin_system *s, int nvars)
#else
static void binsys_init (s, nvars)
bin_system *s;
int nvars;
#endif
{
    int i;

    s->vars = CC_SAFE_MALLOC (nvars, bin_var);
    if (!s->vars) {
        fprintf (stderr, "out of memory in necklace\n");
        exit (1);
    }

    for (i=0; i<nnecklaces; i++) {
        s->vars[i].elim = (Xeqn *) NULL;
        s->vars[i].value = VALUE_UNKNOWN;
        s->vars[i].fixed = 0;
    }

    s->sparselist = (Xeqn *) NULL;
    s->denseeqn = (Xeqn *) NULL;
    s->nvars = nvars;
    s->nfreevars = nvars;
}

#ifdef CC_PROTOTYPE_ANSI
static int binsys_add_dense (bin_system *s, Xeqn *e)
#else
static int binsys_add_dense (s, e)
bin_system *s;
Xeqn *e;
#endif
{
    assert (s->denseeqn == (Xeqn *) NULL);
    binsys_elim (s, e);
    if (e->lhs == (Xintptr *) NULL) {
        if (e->rhs == 0) {
            Xeqnfree (e);
            return 0;
        } else {
            Xeqnfree (e);
            return -1;
        }
    }
    s->denseeqn = e;
    e->next = (Xeqn *) NULL;
    s->nfreevars--;
    return 1;
}

#ifdef CC_PROTOTYPE_ANSI
static int binsys_add_sparse (bin_system *s, Xeqn *e)
#else
static int binsys_add_sparse (s, e)
bin_system *s;
Xeqn *e;
#endif
{
    binsys_elim (s, e);

    if (!e->lhs) {
        if (e->rhs == 0) {
            free_equation (e);
            return 0;
        } else {
            free_equation (e);
            return -1;
        }
    }
    if (s->denseeqn && intptrlist_equal (e->lhs, s->denseeqn->lhs)) {
        if (e->rhs == s->denseeqn->rhs) {
            free_equation (e);
            return 0;
        } else {
            free_equation (e);
            return -1;
        }
    }
    e->pivot = e->lhs->this;
    s->vars[e->pivot].elim = e;
    if (s->denseeqn && find_label (s->denseeqn->lhs, e->pivot)) {
        eqn_addto (s->denseeqn, e);
        assert (s->denseeqn->lhs);
        e->hitdense = 1;
    } else {
        e->hitdense = 0;
    }
    e->next = s->sparselist;
    s->sparselist = e;
    s->nfreevars--;

    return 1;
}

#ifdef CC_PROTOTYPE_ANSI
static void binsys_elim (bin_system *s, Xeqn *e)
#else
static void binsys_elim (s, e)
bin_system *s;
Xeqn *e;
#endif
{
    Xintptr **p;
    Xintptr *q;
    Xeqn *f;

    p = &e->lhs;
    while ((q = *p) != (Xintptr *) NULL) {
        if ((f = s->vars[q->this].elim) != (Xeqn *) NULL) {
            if (f->lhs && f->lhs->this == q->this) {
                eqn_addto (e, f);
            } else {
                eqn_addto (e, f);
                p = &e->lhs;
            }
        } else {
            p = & (*p)->next;
        }
    }
}

#ifdef CC_PROTOTYPE_ANSI
static Xintptr *binsys_random_minimal_solution (bin_system *s)
#else
static Xintptr *binsys_random_minimal_solution (s)
bin_system *s;
#endif
{
    Xintptr *sollst;
    int nadded;
    int i;

    for (i=0; i<s->nvars; i++) {
        s->vars[i].fixed = 0;
    }

    nadded = 0;
    while (s->nfreevars) {
        binsys_random_solution (s);
        for (i=0; i<s->nvars; i++) {
            if (s->vars[i].value == 0 && !s->vars[i].fixed) {
                s->vars[i].fixed = 1;
                if (binsys_force_zero (s, i) == 1) {
                    nadded++;
                }
            }
        }
    }
    binsys_random_solution (s);
    sollst = binsys_list_solution (s);
    for (i=0; i<nadded; i++) {
        binsys_pop_sparse (s);
    }
    return sollst;
}

#ifdef CC_PROTOTYPE_ANSI
static void binsys_random_solution (bin_system *s)
#else
static void binsys_random_solution (s)
bin_system *s;
#endif
{
    Xeqn *e;
    int i;

    for (i=0; i<s->nvars; i++) {
        if (s->vars[i].elim) {
            s->vars[i].value = VALUE_UNKNOWN;
        } else {
            s->vars[i].value = (CCutil_lprand () & 1);
        }
    }
    if (s->denseeqn && s->denseeqn->lhs) {
        s->denseeqn->pivot = s->denseeqn->lhs->this;
        binsys_eval_pivot (s, s->denseeqn);
    }
    for (e = s->sparselist; e; e = e->next) {
        binsys_eval_pivot (s, e);
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void binsys_eval_pivot (bin_system *s, Xeqn *e)
#else
static void binsys_eval_pivot (s, e)
bin_system *s;
Xeqn *e;
#endif
{
    int val;
    Xintptr *p;

    val = e->rhs;
    for (p = e->lhs; p; p = p->next) {
        if (p->this != e->pivot) {
            assert (s->vars[p->this].value != VALUE_UNKNOWN);
            val ^= s->vars[p->this].value;
        }
    }
    s->vars[e->pivot].value = val;
}

#ifdef CC_PROTOTYPE_ANSI
static int binsys_force_zero (bin_system *s, int v)
#else
static int binsys_force_zero (s, v)
bin_system *s;
int v;
#endif
{
    Xeqn *e = Xeqnalloc ();
    Xintptr *p;

    e->rhs = 0;
    p = Xintptralloc ();
    p->this = v;
    p->next = (Xintptr *) NULL;
    e->lhs = p;

    return binsys_add_sparse (s, e);
}

#ifdef CC_PROTOTYPE_ANSI
static void binsys_pop_sparse (bin_system *s)
#else
static void binsys_pop_sparse (s)
bin_system *s;
#endif
{
    Xeqn *e;

    e = s->sparselist;
    s->sparselist = e->next;
    s->vars[e->pivot].elim = (Xeqn *) NULL;
    if (e->hitdense && s->denseeqn) {
        eqn_addto (s->denseeqn, e);
    }
    s->nfreevars++;
    free_equation (e);
}

#ifdef CC_PROTOTYPE_ANSI
static Xintptr *binsys_list_solution (bin_system *s)
#else
static Xintptr *binsys_list_solution (s)
bin_system *s;
#endif
{
    Xintptr *lst;
    Xintptr **lstend;
    Xintptr *new;
    int i;

    lst = (Xintptr *) NULL;
    lstend = &lst;
    for (i=0; i<s->nvars; i++) {
        if (s->vars[i].value == 1) {
            new = Xintptralloc ();
            new->this = i;
            *lstend = new;
            lstend = &new->next;
        }
    }
    *lstend = (Xintptr *) NULL;
    return lst;
}

#ifdef CC_PROTOTYPE_ANSI
static void binsys_free_system (bin_system *s)
#else
static void binsys_free_system (s)
bin_system *s;
#endif
{
    Xeqn *e, *enext;

    CC_FREE (s->vars, bin_var);

    for (e = s->sparselist; e; e = enext) {
        enext = e->next;
        free_equation (e);
    }
    if (s->denseeqn) {
        free_equation (s->denseeqn);
    }

    s->vars = (bin_var *) NULL;
    s->sparselist = (Xeqn *) NULL;
    s->denseeqn = (Xeqn *) NULL;
    s->nvars = 0;
    s->nfreevars = 0;
}

/* disjoint sets ala Tarjan (from Data Structures and Network Algorithms
   by Robert Tarjan) */

#ifdef CC_PROTOTYPE_ANSI
static void ds_makeset (PQ_node *v)
#else
static void ds_makeset (v)
PQ_node *v;
#endif
{
    v->setinfo.parent = v;
    v->setinfo.rank = 0;
}

#ifdef CC_PROTOTYPE_ANSI
static PQ_node *ds_find (PQ_node *v)
#else
static PQ_node *ds_find (v)
PQ_node *v;
#endif
{
    PQ_node *p = v->setinfo.parent;

    return v == p ? v : (v->setinfo.parent = ds_find (p));
}

#ifdef CC_PROTOTYPE_ANSI
static PQ_node *ds_link (PQ_node *x, PQ_node *y)
#else
static PQ_node *ds_link (x, y)
PQ_node *x;
PQ_node *y;
#endif
{
    PQ_node *t;
    if (x->setinfo.rank > y->setinfo.rank) {
        SWAP (x,y,t);
    } else if (x->setinfo.rank == y->setinfo.rank) {
        y->setinfo.rank++;
    }
    x->setinfo.parent = y;
    return y;
}

#ifdef CC_PROTOTYPE_ANSI
static PQ_node *init_elems (PQ_node *elems)
#else
static PQ_node *init_elems (elems)
PQ_node *elems;
#endif
{
    int i;
    PQ_node *token;

    for (i = 0, token = (PQ_node *) NULL; i < G->nnodes; i++) {
        if (i != MAGICNODE) {
            elems[i].next = token;
            token = &elems[i];
        }
        elems[i].number = i;
    }

    XPQ_init_tree (token);
    return token;
}

#ifdef CC_PROTOTYPE_ANSI
static int add_clique_to_PQtree (Xclique *c, PQ_node *elems)
#else
static int add_clique_to_PQtree (c, elems)
Xclique *c;
PQ_node *elems;
#endif
{
    PQ_node *cut;

    cut = clique_to_PQlist (c, elems);
    return (XPQ_process (cut) != (PQ_node *) NULL);
}

#ifdef CC_PROTOTYPE_ANSI
static PQ_node *clique_to_PQlist (Xclique *c, PQ_node *elems)
#else
static PQ_node *clique_to_PQlist (c, elems)
Xclique *c;
PQ_node *elems;
#endif
{
    Xintptr *p;
    PQ_node *cut;
    int n;

    if (find_intptr_list (c->nodes, MAGICNODE)) {
        G->magicnum++;
        for (p = c->nodes; p; p = p->next) {
            G->nodelist[p->this].magiclabel = G->magicnum;
        }
        for (n = 1, cut = (PQ_node *) NULL; n < G->nnodes; n++) {
            if (G->nodelist[n].magiclabel != G->magicnum) {
                elems[n].next = cut;
                cut = &elems[n];
            }
        }
    } else {
        for (cut = (PQ_node *) NULL, p = c->nodes; p; p = p->next) {
            n = p->this;
            elems[n].next = cut;
            cut = &elems[n];
        }
    }
    return cut;
}



#ifdef CC_PROTOTYPE_ANSI
static int find_intptr_list (Xintptr *p, int n)
#else
static int find_intptr_list (p, n)
Xintptr *p;
int n;
#endif
{
    while (p) {
        if (p->this == n)
            return 1;
        p = p->next;
    }
    return 0;
}


