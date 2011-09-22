/**************************************************************************/
/*                                                                        */
/* EXPORTED FUNCTIONS:                                                    */
/*                                                                        */
/*  int       Xnewkids ()                                                  */
/*                                                                        */
/*                                                                        */
/**************************************************************************/

#include "machdefs.h"
#include "util.h"
#include "Xsubtour.h"
#include "Xcutpool.h"
#include "Xpq.h"

Xgraph *G;

#ifdef CC_PROTOTYPE_ANSI
int Xsearch_cutpool_for_slack_cliques (Xgraph *H, double maxslack,
         int request, int *kcount, Xportableclique **klist, int ecount,
         int *elist, double *x);
#else
int Xsearch_cutpool_for_slack_cliques ();
#endif

#ifdef CC_PROTOTYPE_ANSI

static void
    free_portableclique (Xportableclique *q),
    build_weakcliques (double *),
    gethist (unsigned int *),
    sortcliquelist (void),
    mark_clique (Xclique *, int);

static int
    add_clique_to_PQtree (Xclique *c, PQ_node *elems),
    add_comblist_to_cutlist (Xclique *[4], Xcplane **),
    checkout_cliquelist (Xcplane **),
    find_intptr_list (Xintptr *, int),
    found_clique_contradiction (Xclique *, Xclique *, Xclique *, Xcplane **),
    found_comb_contradiction (Xclique *[4], Xcplane **),
    clique_comp (const void *, const void *);

static PQ_node
    *init_elems (PQ_node *elems),
    *clique_to_PQlist (Xclique *, PQ_node *);

static Xclique
    *add_cliques_to_PQtree (Xclique *, Xclique *, PQ_node *);

#else

static void
    free_portableclique (),
    build_weakcliques (),
    gethist (),
    sortcliquelist (),
    mark_clique ();

static int
    add_clique_to_PQtree (),
    add_comblist_to_cutlist (),
    checkout_cliquelist (),
    find_intptr_list (),
    found_clique_contradiction (),
    found_comb_contradiction (),
    clique_comp ();

static PQ_node
    *init_elems (),
    *clique_to_PQlist ();

static Xclique
    *add_cliques_to_PQtree ();

#endif

static int ncliques = 0;
static Xclique *cliquelist = (Xclique *) NULL;


#ifdef CC_PROTOTYPE_ANSI
int Xnewkids (Xgraph *Gin, double *x, Xcplane **list)
#else
int Xnewkids (Gin, x, list)
Xgraph *Gin;
double *x;
Xcplane **list;
#endif
{
    int ntight, nweak;
    int i, k;
    Xclique *c, *cnext;

    G = Gin;

    printf ("CALLED PQ CUTS ... (%d, %d)\n", G->nnodes, G->nedges);
    fflush (stdout);

    for (i = 0; i < G->nedges; i++) {
        G->edgelist[i].x = x[i];
    }

    cliquelist = (Xclique *) NULL;
    ncliques = 0;

    Xall_tightcuts (G, &cliquelist, &ncliques);
    ntight = ncliques;
    printf ("Found %d tight cliques\n", ntight);
    fflush (stdout);

    for (i = 0; i < G->nedges; i++) {
        G->edgelist[i].x = x[i];
    }
    build_weakcliques (x);
    nweak = ncliques - ntight;
    printf ("Found %d weak cliques\n", nweak);
    fflush (stdout);

    sortcliquelist ();
    printf ("Sorted cliques\n");

    k = checkout_cliquelist (list);
    printf ("Checked out cliques\n"); fflush (stdout);

    c = cliquelist;
    do {
        cnext = c->next;
        Xintptr_list_free (c->nodes);
        Xcliquefree (c);
        c = cnext;
    } while (c != cliquelist);

    return k;
}

#ifdef CC_PROTOTYPE_ANSI
static void build_weakcliques (double *x)
#else
static void build_weakcliques (x)
double *x;
#endif
{
    int ecount;
    int *elist = (int *) NULL;
    int etemp = G->nedges;
    int kcount;
    Xportableclique *klist = (Xportableclique *) NULL;
    Xclique *c;
    Xintptr *ip;
    int i, j, k;

    ecount = G->nedges;
    elist = CC_SAFE_MALLOC (2 * G->nedges, int);
    if (!elist) {
        fprintf (stderr, "out of memory in build_weakcliques\n");
        exit (1);
    }
    for (i = 0, k = 0; i < etemp; i++) {
        elist[k++] = G->edgelist[i].ends[0] - G->nodelist;
        elist[k++] = G->edgelist[i].ends[1] - G->nodelist;
    }
    if (Xsearch_cutpool_for_slack_cliques (G, 1.0, 1000000, &kcount, &klist,
                                           ecount, elist, x)) {
        fprintf (stderr, "Xsearch_cutpool failed\n");
        exit (1);
    }

    for (i = 0; i < kcount; i++) {
        ncliques++;
        c = Xcliquealloc ();
        c->slack = klist[i].cutval;
        c->nodes = (Xintptr *) NULL;
        for (j = 0; j < klist[i].size; j++) {
            ip = Xintptralloc ();
            ip->this = klist[i].nodes[j];
            ip->next = c->nodes;
            c->nodes = ip;
        }
        c->next = cliquelist;
        cliquelist = c;
        free_portableclique (&(klist[i]));
    }
    if (elist)
        CC_FREE (elist, int);
    if (klist)
        CC_FREE (klist, Xportableclique);
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
static int checkout_cliquelist (Xcplane **list)
#else
static int checkout_cliquelist (list)
Xcplane **list;
#endif
{
    PQ_node *elems;
    PQ_node *token_elem;
    PQ_node *save_root;
    Xclique *bot, *top, *botnext, *topnext;
    Xclique *save_bot;
    Xclique *chk;
    int isbot;
    int k = 0;
    int botcount;
    int topcount;

    elems = CC_SAFE_MALLOC (G->nnodes, PQ_node);
    if (!elems) {
        fprintf (stderr, "out of memory in checkout_cliquelist\n");
        exit (1);
    }

    token_elem = init_elems (elems);

    bot = cliquelist;
    top = cliquelist;
    /* [cliquelist,bot) is base, [top,cliquelist) is tested */
    /* [cliquelist,save_bot) is in save_root */

    save_root = XPQ_save_tree (token_elem);
    save_bot = bot;
    botcount = 0;
    topcount = 0;

    do {
        if (3 * bot->slack + top->prev->slack < 1.0) {
            /* putchar ('v'); fflush (stdout); */
            chk = bot;
            isbot = 1;
            botnext = bot->next;
            topnext = top;
        } else {
            /* putchar ('^'); fflush (stdout); */
            chk = top->prev;
            botnext = bot;
            topnext = top->prev;
            isbot = 0;
            if (botcount > 20 && topcount == 0) {
                XPQ_save_tree_free (save_root);
                save_root = XPQ_save_tree (token_elem);
                save_bot = bot;
                botcount = 0;
            }
        }
        if (!add_clique_to_PQtree (chk, elems)) {
            /* putchar ('!'); fflush (stdout); */
            XPQ_free_all (token_elem, 1);
            XPQ_restore_tree (save_root, 1);
            topcount = 0;
            if (save_bot != bot) {
                if (add_cliques_to_PQtree (save_bot, bot, elems)) {
                    fprintf (stderr, "add_clique error\n");
                    exit (1);
                }
                XPQ_save_tree_free (save_root);
                save_root = XPQ_save_tree (token_elem);
                save_bot = bot;
                botcount = 0;
            }
            if (!add_clique_to_PQtree (chk, elems)) {
                k += found_clique_contradiction (chk, cliquelist, bot, list);
                XPQ_free_all (token_elem, 1);
                XPQ_restore_tree (save_root, 1);

                if (isbot) {
                    chk->next->prev = chk->prev;
                    chk->prev->next = chk->next;
                    if (save_bot == chk) {
                        save_bot = bot->next;
                    }
                    Xintptr_list_free (chk->nodes);
                    Xcliquefree (chk);
                }
            } else {
                if (isbot) {
                    botcount++;
                } else {
                    topcount++;
                }
            }
        } else {
            if (isbot)
                botcount++;
            else
                topcount++;
        }
        top = topnext;
        bot = botnext;
    } while (bot != top);
    /* XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX */
    XPQ_free_all (token_elem, 1);
    XPQ_save_tree_free (save_root);
    /* XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX */
    CC_FREE (elems, PQ_node);

    return k;
}

#ifdef CC_PROTOTYPE_ANSI
static int clique_comp (const void *a, const void *b)
#else
static int clique_comp (a, b)
const void *a, *b;
#endif
{
    if ((*(Xclique * const *) a)->slack <
        (*(Xclique * const *) b)->slack) {
        return -1;
    } else if ((*(Xclique * const *) a)->slack >
               (*(Xclique * const *) b)->slack) {
        return 1;
    } else {
        return 0;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void sortcliquelist (void)
#else
static void sortcliquelist ()
#endif
{
    Xclique **svec;
    Xclique *p;
    int i;

    svec = CC_SAFE_MALLOC (ncliques, Xclique *);
    if (!svec) {
        fprintf (stderr, "out of memory in sortcliquelist\n");
        exit (1);
    }
    for (i = 0, p = cliquelist; p; p = p->next, i++) {
        svec[i] = p;
    }
    if (i != ncliques) {
        fprintf (stderr, "Found %d cliques, expected %d\n", i, ncliques);
    }
    qsort ((char *) svec, ncliques, sizeof (Xclique *), clique_comp);

    for (i = 0; i < ncliques; i++) {
        svec[i]->next = svec[i + 1];
        svec[i]->prev = svec[i - 1];
    }
    svec[0]->prev = svec[ncliques - 1];
    svec[ncliques - 1]->next = svec[0];
    cliquelist = svec[0];

    CC_FREE (svec, Xclique *);
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
static Xclique *add_cliques_to_PQtree (Xclique *c, Xclique *cend, PQ_node *elems)
#else
static Xclique *add_cliques_to_PQtree (c, cend, elems)
Xclique *c;
Xclique *cend;
PQ_node *elems;
#endif
{
    while (c != cend) {
        if (!add_clique_to_PQtree (c, elems)) {
            return c;
        }
        c = c->next;
    }
    return (Xclique *) NULL;
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

/* viol added to [base,bend) results in violation.  Convert to comb. */

#ifdef CC_PROTOTYPE_ANSI
static int found_clique_contradiction (Xclique *viol, Xclique *base, Xclique *bend, Xcplane **list)
#else
static int found_clique_contradiction (viol, base, bend, list)
Xclique *viol;
Xclique *base;
Xclique *bend;
Xcplane **list;
#endif
{
    Xclique *comblist[4];
    PQ_node *elems;
    PQ_node *token_elem;
    int i, j;
    Xclique *b = (Xclique *) NULL;

    comblist[0] = viol;
    elems = CC_SAFE_MALLOC (G->nnodes, PQ_node);
    if (!elems) {
        fprintf (stderr, "out of memory in found_clique_contradiction\n");
        exit (1);
    }

    for (i = 1;; i++) {
        token_elem = init_elems (elems);
        for (j = 0; j < i; j++) {
            if (!add_clique_to_PQtree (comblist[j], elems)) {
                if (j != i - 1) {
                    fprintf (stderr, "Whoa, unexpected violation\n");
                }
                XPQ_free_all (token_elem, 1);
                CC_FREE (elems, PQ_node);
                if (i == 4) {
                    return found_comb_contradiction (comblist, list);
                } else {
                    return 0;
                }
            }
        }
        if (i < 4) {
            b = add_cliques_to_PQtree (base, bend, elems);
        }
        XPQ_free_all (token_elem, 1);
        if (i >= 4 || !b) {
            CC_FREE (elems, PQ_node);
            return 0;
        }
        comblist[i] = b;
        bend = b;
    }
}

#define HANDLE 1
#define TOOTH1 2
#define TOOTH2 4
#define TOOTH3 8
#define NREGIONS 16

int flipseq[NREGIONS] = {0, TOOTH1, TOOTH2, TOOTH3, TOOTH1 | TOOTH2,
    TOOTH1 | TOOTH3, TOOTH2 | TOOTH3, TOOTH1 | TOOTH2 | TOOTH3,
    HANDLE | TOOTH1, HANDLE | TOOTH2, HANDLE | TOOTH3,
    HANDLE | TOOTH1 | TOOTH2, HANDLE | TOOTH1 | TOOTH3,
HANDLE | TOOTH2 | TOOTH3};

#ifdef CC_PROTOTYPE_ANSI
static int found_comb_contradiction (Xclique *comblist[4], Xcplane **list)

#else
static int found_comb_contradiction (comblist, list)
Xclique  *comblist[4];
Xcplane  **list;
#endif
{
    int i, i2;
    int flip;
    int handle;
    int hbit;
    unsigned int hist[NREGIONS];
    unsigned int hist2[NREGIONS];
    Xclique *tmp;
    int test;

    for (i = 0; i < G->nnodes; i++) {
        G->nodelist[i].Tmark = 0;
    }
    for (i = 0; i < 4; i++) {
        mark_clique (comblist[i], (1 << i));
    }
    gethist (hist);

    for (flip = 0; flip < NREGIONS; flip++) {
        for (handle = 0; handle < 4; handle++) {
            hbit = (1 << handle);
            for (i = 0; i < NREGIONS; i++) {
                i2 = i & ~(1 | hbit);
                if (i & 1)
                    i2 |= hbit;
                if (i & hbit)
                    i2 |= 1;
                i2 ^= flipseq[flip];
                hist2[i] = hist[i2];
            }
            if (Xhistok (hist2)) {
                SWAP (comblist[0], comblist[handle], tmp);
                test = add_comblist_to_cutlist (comblist, list);
                return test;
            }
        }
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static void mark_clique (Xclique *c, int m)
#else
static void mark_clique (c, m)
Xclique *c;
int m;
#endif
{
    Xintptr *p;

    for (p = c->nodes; p; p = p->next) {
        G->nodelist[p->this].Tmark |= m;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void gethist (unsigned int *hist)
#else
static void gethist (hist)
unsigned int *hist;
#endif
{
    int i;

    for (i = 0; i < NREGIONS; i++) {
        hist[i] = 0;
    }
    for (i = 0; i < G->nnodes; i++) {
        hist[G->nodelist[i].Tmark]++;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static int add_comblist_to_cutlist (Xclique *comblist[4], Xcplane **list)
#else
static int add_comblist_to_cutlist (comblist, list)
Xclique *comblist[4];
Xcplane **list;
#endif
{
    Xintptr *ip;
    Xnodeptr *np;
    Xnodeptrptr *npp;
    Xnodeptrptr *handles, *teeth;
    int i;
    int test;

    handles = Xnodeptrptralloc ();
    handles->next = (Xnodeptrptr *) NULL;
    handles->this = (Xnodeptr *) NULL;
    for (ip = comblist[0]->nodes; ip; ip = ip->next) {
        np = Xnodeptralloc ();
        np->this = &G->nodelist[ip->this];
        np->next = handles->this;
        handles->this = np;
    }
    teeth = (Xnodeptrptr *) NULL;
    for (i = 1; i < 4; i++) {
        npp = Xnodeptrptralloc ();
        npp->next = teeth;
        teeth = npp;
        npp->this = (Xnodeptr *) NULL;
        for (ip = comblist[i]->nodes; ip; ip = ip->next) {
            np = Xnodeptralloc ();
            np->this = &G->nodelist[ip->this];
            np->next = npp->this;
            npp->this = np;
        }
    }
    if (!Xcliquefluff (G, &handles, &teeth)) {
        printf ("DE FLUFFED TO 0\n");
        fflush (stdout);
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
static void free_portableclique (Xportableclique *q)
#else
static void free_portableclique (q)
Xportableclique *q;
#endif
{
    if (q->nodes)
        CC_FREE (q->nodes, int);
}
