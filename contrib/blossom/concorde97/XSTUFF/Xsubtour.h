#ifndef __XSUBTOUR_H
#define __XSUBTOUR_H

#include "Xcutpool.h"

#define XFALSE 0
#define XEPSILON .0001
#define XCUTTOLERANCE .01
#define XBLOTOLERANCE .01
#define XCUTTWO (2.0-XCUTTOLERANCE)
#define XCUTNUM 150
#define XMAXWEIGHT 1e30
#define XBIGNEG -10000000000.0
#define SWAP(x,y,temp) (temp = x, x = y, y = temp)
#define OTHEREND(e,n) (e->ends[0] == n ? e->ends[1] : e->ends[0])
#define OTHERCURRENTEND(e,n) ((e)->cends[0] == (n) ? (e)->cends[1] : (e)->cends[0])

typedef struct Xedge {
    struct Xnode  *ends[2];
    struct Xnode  *cends[2];
    struct Xnode  *splitter;
    int           weight;
    double        x;
    double        rc;
    double        flow;
    int           stay;
    int           elim;
    int           weak;
    int           hold;
    int           fixed;
    int           magiclabel;
    struct Xedge  *next;
} Xedge;

typedef struct Xextraedge {
    int ends[2];
    int weight;
    int elim;
} Xextraedge;

typedef struct Xextralink {
    int ends[2];
    int weight;
    struct Xextralink *next;
} Xextralink;

typedef struct Xedgeptr {
    struct Xedge     *this;
    struct Xedgeptr  *next;
} Xedgeptr;

typedef struct Xedgeset {
    struct Xedgeptr *head;
    struct Xedgeptr *tail;
} Xedgeset;

typedef struct Xnodeset {
    struct Xnodeptr  *head;
    struct Xnodeptr  *tail;
} Xnodeset;

typedef struct Xnode {
    Xedgeset adj;
    Xedgeset cadj;
    Xnodeset base;
    int degree;
    int     magiclabel;
    int     stacklabel;
    int     pseudonumber;
    double  excess;
    int     flowlabel;
    Xedgeptr *current;
    int     active;
    struct  Xnode  *next, *prev;
    struct  Xnode  *snext;
    struct  Xnode  *tnext;  /* Only use locally */
    Xedge *pe;
    struct  Xclink *cuts;
    struct  Xblink *blossoms;
    int     mark;
    int     Tmark;
    int     rand1;
    int     rand2;
} Xnode;

typedef struct Xnodeptr {
    struct Xnode     *this;
    struct Xnodeptr  *next;
} Xnodeptr;

typedef struct Xnodeptrptr {
    struct Xnodeptr    *this;
    struct Xnodeptrptr *next;
} Xnodeptrptr;

typedef struct Xclink {
    int            cut;
    struct Xclink *next;
} Xclink;

typedef struct Xblink {
    int             cut;
    char            handle;
    int             tooth;
    struct Xblink   *next;
} Xblink;

typedef struct Xconstraint {
    int             sort;
    struct Xnodeptr *teeth;
    int             rhs;
} Xconstraint;

typedef struct Xcplane {
    unsigned long       val;
    struct Xnodeptr     *handle;
    struct Xnodeptrptr  *handles;
    struct Xnodeptrptr  *teeth;
    struct Xcplane      *next;
} Xcplane;

typedef struct Xiplane {
    struct Xintptr      *handle;
    struct Xintptrptr   *handles;
    struct Xintptrptr   *teeth;
    struct Xiplane      *next;
} Xiplane;

typedef struct Xcuttree_node {
    struct Xcuttree_node *parent;
    struct Xcuttree_node *sibling;
    struct Xcuttree_node *child;
    double cutval;
    int ndescendants;
    Xnode *special;
    Xnodeset nlist;
    Xnode *pseudonode;
    struct Xcuttree_node *next;
} Xcuttree_node;

typedef struct Xintptr {
    int              this;
    struct Xintptr   *next;
} Xintptr;

typedef struct Xintptrptr {
    Xintptr           *this;
    struct Xintptrptr *next;
} Xintptrptr;

typedef struct Xblock {
    Xnodeptr           *members;
    struct Xcutnodeptr *cutnodes;
    struct Xblockptr   *neighbors;
    Xedgeptr           *one;
    double             weight;
    double             x;
    int                mark;
} Xblock;

typedef struct Xblockptr {
    struct Xblockptr *next;
    struct Xblock    *this;
    double           hood_weight;
} Xblockptr;

typedef struct Xcutnode {
    Xnode           *name;
    Xblockptr       *blocks;
    int             mark;
} Xcutnode;

typedef struct Xcutnodeptr {
    struct Xcutnode  *this;
    struct Xcutnodeptr  *next;
} Xcutnodeptr;

typedef struct Xcombhash {
    unsigned long    val;
    struct Xcombhash *next;
} Xcombhash;

typedef struct Xclique {
    double slack;
    Xintptr *nodes;
    struct Xclique *next;
    struct Xclique *prev;
} Xclique;

typedef struct Xgraph {
    int      nnodes;
    Xnode    *nodelist;
    int      nedges;
    Xedge    *edgelist;
    Xnode    *pseudonodelist;
    Xedge    *pseudoedgelist;
    int      npseudonodes;
    int      magicnum;
    int      stacknum;
    int      magicedgenum;
} Xgraph;

#ifdef CC_PROTOTYPE_ANSI

/* adjacency.c */

void
    Xbuildpanadjlist (void),
    Xbuildmatadjlist (void);

/* allcuts.c */

void
    Xall_tightcuts (Xgraph *Gin, Xclique **cliquelistin, int *ncliquesin);

/* Xblock.c */

void
    Xlocalshrink_a (Xgraph *G, int component),
    Xlocalshrink_b (Xgraph *G, int component),
    Xlocalshrink_c (Xgraph *G, int component),
    Xadd_tooth (Xnode *t, Xnodeptr **list);

int
    Xblockcombs (Xgraph *G, Xcplane **cplanelist, double *x),
    Xlocalcombs (Xgraph *G, Xcplane **cplanelist, double *x),
    Xglobalcombs (Xgraph *G, Xcplane **cplanelist, double *x),
    XTmark_components (Xgraph *G),
    Xbasiccliques (Xgraph *G, Xcplane **list, double *x),
    Xsearchbasiccliques (Xgraph *G, Xcplane **list, int pseudo, double *x),
    Xbasicclique (Xgraph *G, Xcplane **list, double *x, Xblock *bigtooth),
    Xmarktooth (Xedge *e, Xnodeptr **list),
    Xmarktoothend (Xnode *n, Xnodeptr **list),
    Xrepeat_1_shrink (Xgraph *G, Xnode *n, Xedge *e);

Xedge
    *Xcurrentedge (Xnode *n1, Xnode *n2);


/* Xblocheck.c */

int
    Xexactblossoms_run (Xgraph *G, Xcplane **list, double *x),
    Xexactblossomcheck (Xgraph *G, Xcplane **list, int pseudo, double *x),
    Xolaf (Xgraph *G, int choice);


/* Xclique.c */

int
    Xcliquetree (Xgraph *G, Xcplane **list, double *x),
    Xcliquetree_work (Xgraph *G, Xcplane **list, int pseudo, double *x,
          int type_of_grow);


/* Xcuthash.c */

void
    Xinit_hash_values (Xgraph *G);

unsigned long
    Xcut_hash_value (Xnodeptr *h),
    Xcomb_hash_value (Xnodeptr *h, Xnodeptrptr *t),
    Xclique_hash_value (Xnodeptrptr *h, Xnodeptrptr *t);


/* Xblobs.c */

void
    Xpancakex (Xgraph *G, double *x),
    Xfreepancake (void),
    Xshrinksmallblobs (Xgraph *G, int rnum, int biggest),
    Xtightblobs (Xgraph *G);

int
    Xblobsviolated (Xgraph *G, Xcplane **list );


/* Xcclean.c */

void
    Xcleancomb (Xgraph *G, Xnodeptr **handle, Xnodeptrptr **teeth,
          int *nteeth, double *x);
int
    Xcheckcomb (Xgraph *G, Xnodeptr *handle, Xnodeptrptr *teeth),
    Xcliquefluff (Xgraph *G, Xnodeptrptr **handles, Xnodeptrptr **teeth),
    Xtemp_combfluff (Xgraph *G, Xnodeptr **handle, Xnodeptrptr **teeth),
    Xcombfluff (Xgraph *G, Xnodeptrptr **handles, Xnodeptrptr **teeth,
         int cliquetest),
    Xhistok (unsigned int *hist),
    Xtemp_combcheck (Xgraph *G, Xnodeptr *handle, Xnodeptrptr *teeth),
    Xcheckclique (Xgraph *G, Xnodeptrptr *handles, Xnodeptrptr *teeth);

/* Xcutload.c */

void
    Xcliquetree_slack_rhs_flow (Xgraph *G, Xnodeptrptr *handles,
             Xnodeptrptr *teeth, double *x, double *slack, double *rhs),
    Xfreecplanelist (Xcplane **list);

int
    Xcutchecksout (Xgraph *G, int x),
    Xtemp_doblossom (Xgraph *G, Xcplane **cplanelist, Xnodeptr *handle,
                     Xedgeptr *teeth),
    Xviolated_clique_flow (Xgraph *G, Xnodeptrptr *handles, Xnodeptrptr *teeth,
                           double *x),
    Xloadcplane (Xcplane **list, Xnodeptr *h, Xnodeptrptr *H,
                 Xnodeptrptr *t, int countcheck),
    Xloadcplane_cut (Xgraph *G, Xcplane **list, int num);


/* Xcuts.c */

int
    Xolaf_combs (Xgraph *G, Xcplane **list, double *x),
    Xblobcuts (Xgraph *G, Xcplane **list, double *x);

int
    Xreallyfaststuff (Xcplane **, double *, double *),
    Xfaststuff (Xcplane **, double *, double *),
    Xmediumstuff (Xcplane **, double *, double *),
    Xslowstuff (Xcplane **, double *, double *),
    Xreallyslowstuff (Xcplane **, double *, double *),
    Xall_run_olaf (Xcplane **, double *),
    Xheuristiccutcheck (Xcplane **, double *);

/* Xcututil.c */

void
    Xfreecplanestruct (Xcplane *c),
    Xfreeiplanestruct (Xiplane *c),
    Xcplane_to_iplane (Xgraph *G, Xcplane *c, Xiplane **ipl),
    Xiplane_to_cplane (Xgraph *G, Xiplane *c, Xcplane **cpl),
    Xportablecut_to_cplane (Xgraph *G, Xportablecut *p, Xcplane **cpl),
    Xportablecut_to_handles_and_teeth (Xgraph *G, Xportablecut *p,
          Xnodeptrptr **handles, Xnodeptrptr **teeth),
    Xportablecut_to_iplane (Xportablecut *p, Xiplane **ipl),
    Xiplane_to_portablecut (Xiplane *c, Xportablecut *p),
    Xfreeteeth (Xnodeptrptr *teeth),
    Xprintchvatalcomb (Xgraph *G, Xnodeptr *h, Xnodeptrptr *t),
    Xprintcliquetree (Xgraph *G, Xnodeptrptr *h, Xnodeptrptr *t),
    Xdumpchvatalcomb (FILE *out, Xintptr *h, Xintptrptr *t),
    Xdumpcliquetree (FILE *out, Xintptrptr *h, Xintptrptr *t);

int
    Xslackclique (Xgraph *G, Xnodeptrptr *handles, Xnodeptrptr *teeth,
                  double *slack),
    Xinduced_edges_flow (Xgraph *G, Xnodeptr *set);


/* Xflow.c */

double
    Xflow (Xgraph *G, Xnode *, Xnode *, double);

int
    Xmincut (Xgraph *G, Xnode *, Xnode *, double, double *, int *),
    Xexactcutcheck (Xgraph *G, Xcplane **list, double *x),
    Xrunconnectcuts (Xgraph *G, Xcplane **, double *);


/* Xgomhu.c */

Xcuttree_node
    *Xgomory_hu (Xgraph *G);

void
    Xcuttree_free (Xcuttree_node *n);

/* necklace.c */

int
    Xnecklaces (Xgraph *Gin, Xcplane **, double *);

/* newkids.c */

int
    Xnewkids (Xgraph *Gin, double *x, Xcplane **list);

/* Xourallo.c */

Xblink *Xblinkalloc (void);
Xblockptr *Xblockptralloc (void);
Xclink *Xclinkalloc (void);
Xclique *Xcliquealloc (void);
Xcombhash *Xcombhashalloc (void);
Xcplane *Xcplanealloc (void);
Xcutnodeptr *Xcutnodeptralloc (void);
Xcuttree_node *Xcuttree_nodealloc (void);
Xedge *Xedgealloc (void);
Xedgeptr *Xedgeptralloc (void);
Xintptr *Xintptralloc (void);
Xintptrptr *Xintptrptralloc (void);
void Xadd_intptrptr (Xintptrptr **, Xintptr *);
Xiplane *Xiplanealloc (void);
Xnode *Xnodealloc (void);
Xnodeptr *Xnodeptralloc (void);
Xnodeptrptr *Xnodeptrptralloc (void);
void Xadd_edgeptr (Xedgeptr **, Xedge *);
void Xadd_extralink (Xextralink **, int, int, int);
void Xadd_nodeptr (Xnodeptr **, Xnode *);
void Xadd_nodeptrptr (Xnodeptrptr **, Xnodeptr *);
void Xblinkfree (Xblink *);
void Xblockptrfree (Xblockptr *);
void Xclinkfree (Xclink *);
void Xcliquefree (Xclique *);
void Xcombhashfree (Xcombhash *);
void Xcplane_list_free (Xcplane *);
void Xcplanefree (Xcplane *);
void Xcutnodeptrfree (Xcutnodeptr *);
void Xcuttree_nodefree (Xcuttree_node *);
void Xedgefree (Xedge *);
void Xedge_list_free (Xedge *);
void Xedgeptr_list_free (Xedgeptr *);
void Xedgeptrfree (Xedgeptr *);
void Xextralink_list_free (Xextralink *);
void Xinitialize_ouralloc (void);
void Xintptr_list_free (Xintptr *);
void Xintptrfree (Xintptr *);
void Xintptrptr_list_free (Xintptrptr *);
void Xintptrptr_list_freeall(Xintptrptr *);
void Xintptrptrfree (Xintptrptr *);
void Xiplane_list_free (Xiplane *);
void Xiplanefree (Xiplane *);
void Xnodefree (Xnode *);
void Xnodeptr_list_free (Xnodeptr *);
void Xnodeptrfree (Xnodeptr *);
void Xnodeptrptr_list_free (Xnodeptrptr *);
void Xnodeptrptrfree (Xnodeptrptr *);
void Xunion_nodeptr (Xgraph *G, Xnodeptr *, Xnodeptr *, Xnodeptr **);


/* Xshrink.c */

void
    Xbuildpseudonodelist (Xgraph *G, int all),
    Xbuildpseudonodenumbers (Xgraph *G),
    Xdestroypseudonodelist (Xgraph *G),
    Xdumppseudograph (Xgraph *G),
    Xdumppseudograph_edgelist (Xgraph *G),
    Xsimpleshrink (Xgraph *G, Xnode *, Xnode *),
    Xrebuildcadj (Xgraph *G);

int
    Xshrinkprocess (Xgraph *G, Xcplane **),
    Xheavy_edge_cuts (Xgraph *G, Xcplane **list, double *x);


/* Xgraph.c */

void
    Xfreegraph (Xgraph *G),
    Xloadx (Xgraph *G, double *x);

int
    Xbuildgraph (Xgraph *G, int ncount, int ecount, int *elist, int *elen);

/* Xstuff.c */

int
    Xsearch_cutpool_for_slack_cliques (Xgraph *G, double maxslack,
         int request, int *kcount, Xportableclique **klist, int ecount,
         int *elist, double *x);

#else

/* adjacency.c */

void
    Xbuildpanadjlist (),
    Xbuildmatadjlist ();

/* allcuts.c */

void
    Xall_tightcuts ();

/* Xblock.c */

void
    Xlocalshrink_a (),
    Xlocalshrink_b (),
    Xlocalshrink_c (),
    Xadd_tooth ();

int
    Xblockcombs (),
    Xlocalcombs (),
    Xglobalcombs (),
    XTmark_components (),
    Xbasiccliques (),
    Xsearchbasiccliques (),
    Xbasicclique (),
    Xmarktooth (),
    Xmarktoothend (),
    Xrepeat_1_shrink ();

Xedge
    *Xcurrentedge ();


/* Xblocheck.c */

int
    Xexactblossoms_run (),
    Xexactblossomcheck (),
    Xolaf ();


/* Xclique.c */

int
    Xcliquetree (),
    Xcliquetree_work ();


/* Xcuthash.c */

void
    Xinit_hash_values ();

unsigned long
    Xcut_hash_value (),
    Xcomb_hash_value (),
    Xclique_hash_value ();


/* Xblobs.c */

void
    Xpancakex (),
    Xfreepancake (),
    Xshrinksmallblobs (),
    Xtightblobs ();

int
    Xblobsviolated ();


/* Xcclean.c */

void
    Xcleancomb ();
int
    Xcheckcomb (),
    Xcliquefluff (),
    Xtemp_combfluff (),
    Xcombfluff (),
    Xhistok (),
    Xtemp_combcheck (),
    Xcheckclique ();

/* Xcutload.c */

void
    Xcliquetree_slack_rhs_flow (),
    Xfreecplanelist ();

int
    Xcutchecksout (),
    Xtemp_doblossom (),
    Xviolated_clique_flow (),
    Xloadcplane (),
    Xloadcplane_cut ();


/* Xcuts.c */

int
    Xolaf_combs (),
    Xblobcuts ();

int
    Xreallyfaststuff (),
    Xfaststuff (),
    Xmediumstuff (),
    Xslowstuff (),
    Xreallyslowstuff (),
    Xall_run_olaf (),
    Xheuristiccutcheck ();

/* Xcututil.c */

void
    Xfreecplanestruct (),
    Xfreeiplanestruct (),
    Xcplane_to_iplane (),
    Xiplane_to_cplane (),
    Xportablecut_to_cplane (),
    Xportablecut_to_handles_and_teeth (),
    Xportablecut_to_iplane (),
    Xiplane_to_portablecut (),
    Xfreeteeth (),
    Xprintchvatalcomb (),
    Xprintcliquetree (),
    Xdumpchvatalcomb (),
    Xdumpcliquetree ();

int
    Xslackclique (),
    Xinduced_edges_flow ();


/* Xflow.c */

double
    Xflow ();

int
    Xmincut (),
    Xexactcutcheck (),
    Xrunconnectcuts ();


/* Xgomhu.c */

Xcuttree_node
    *Xgomory_hu ();

void
    Xcuttree_free ();

/* necklace.c */

int
    Xnecklaces ();

/* newkids.c */

int
    Xnewkids ();

/* Xourallo.c */

Xblink *Xblinkalloc ();
Xblockptr *Xblockptralloc ();
Xclink *Xclinkalloc ();
Xclique *Xcliquealloc ();
Xcombhash *Xcombhashalloc ();
Xcplane *Xcplanealloc ();
Xcutnodeptr *Xcutnodeptralloc ();
Xcuttree_node *Xcuttree_nodealloc ();
Xedge *Xedgealloc ();
Xedgeptr *Xedgeptralloc ();
Xintptr *Xintptralloc ();
Xintptrptr *Xintptrptralloc ();
void Xadd_intptrptr ();
Xiplane *Xiplanealloc ();
Xnode *Xnodealloc ();
Xnodeptr *Xnodeptralloc ();
Xnodeptrptr *Xnodeptrptralloc ();
void Xadd_edgeptr ();
void Xadd_extralink ();
void Xadd_nodeptr ();
void Xadd_nodeptrptr ();
void Xblinkfree ();
void Xblockptrfree ();
void Xclinkfree ();
void Xcliquefree ();
void Xcombhashfree ();
void Xcplane_list_free ();
void Xcplanefree ();
void Xcutnodeptrfree ();
void Xcuttree_nodefree ();
void Xedgefree ();
void Xedge_list_free ();
void Xedgeptr_list_free ();
void Xedgeptrfree ();
void Xextralink_list_free ();
void Xinitialize_ouralloc ();
void Xintptr_list_free ();
void Xintptrfree ();
void Xintptrptr_list_free ();
void Xintptrptr_list_freeall();
void Xintptrptrfree ();
void Xiplane_list_free ();
void Xiplanefree ();
void Xnodefree ();
void Xnodeptr_list_free ();
void Xnodeptrfree ();
void Xnodeptrptr_list_free ();
void Xnodeptrptrfree ();
void Xunion_nodeptr ();


/* Xshrink.c */

void
    Xbuildpseudonodelist (),
    Xbuildpseudonodenumbers (),
    Xdestroypseudonodelist (),
    Xdumppseudograph (),
    Xdumppseudograph_edgelist (),
    Xsimpleshrink (),
    Xrebuildcadj ();

int
    Xshrinkprocess (),
    Xheavy_edge_cuts ();


/* Xgraph.c */

void
    Xfreegraph (),
    Xloadx ();

int
    Xbuildgraph ();

/* Xstuff.c */

int
    Xsearch_cutpool_for_slack_cliques ();

#endif
#endif /* __XSUBTOUR_H */

