/***************************************************************************/
/***************************************************************************/
/*                                                                         */
/*                      PROTOTYPES FOR FILES IN CUT                        */
/*                                                                         */
/***************************************************************************/
/***************************************************************************/


#ifndef  __CUT_H
#define  __CUT_H


#define CC_MINCUT_BIGDOUBLE   (100000000000.0)
#define CC_MINCUT_ONE_EPSILON (0.000001)


#ifdef CC_PROTOTYPE_ANSI

int
    CCcut_mincut (int ncount, int ecount, int *elist, double *dlen,
            double *valval, int **cut, int *cutcount),
    CCcut_violated_cuts (int ncount, int ecount, int *elist, double *dlen,
            double cutoff, int (*doit_fn) (double, int, int *, void *),
            void *pass_param),
    CCcut_mincut_st (int ncount, int ecount, int *elist, double *ecap,
            int s, int t, double *value, int **cut, int *cutcount),
    CCcut_linsub (int ncount, int ecount, int *elist, double *x, double cutoff,
        int (*doit_fn) (double, int, int, void *), void *pass_param),
    CCcut_connect_components (int ncount, int ecount, int *elist, double *x,
        int *ncomp, int **compscount, int **comps);

#else

int
    CCcut_mincut (),
    CCcut_violated_cuts (),
    CCcut_mincut_st (),
    CCcut_linsub (),
    CCcut_connect_components ();

#endif



/***************************************************************************/
/*                                                                         */
/*                             shrink.c                                    */
/*                                                                         */
/***************************************************************************/

typedef struct CC_SRKnode {
    struct CC_SRKedge *adj;
    struct CC_SRKnode *next;
    struct CC_SRKnode *prev;
    struct CC_SRKnode *members;
    struct CC_SRKnode *parent;
    struct CC_SRKnode *qnext;
    double             prweight;
    double             weight;
    int                num;
    int                newnum;
    int                onecnt;
    int                onqueue;
} CC_SRKnode;

typedef struct CC_SRKedge {
    struct CC_SRKnode *end;
    struct CC_SRKedge *other;
    struct CC_SRKedge *next;
    struct CC_SRKedge *prev;
    double             weight;
} CC_SRKedge;

typedef struct CC_SRKgraph {
    struct CC_SRKnode  *nodespace;
    struct CC_SRKedge  *edgespace;
    struct CC_SRKnode  *head;
    struct CC_SRKedge **hit;
    int                 original_ncount;
    int                 original_ecount;
} CC_SRKgraph;

typedef struct CC_SRKexpinfo {
    int *members;
    int *memindex;
} CC_SRKexpinfo;

typedef struct CC_SRKcallback {
    double  cutoff;
    void   *pass_param;
#ifdef CC_PROTOTYPE_ANSI
    int   (*doit_fn) (double, int, int *, void *);
#else
    int   (*doit_fn) ();
#endif
} CC_SRKcallback;

#ifdef CC_PROTOTYPE_ANSI

void
    CCcut_SRK_identify_paths (CC_SRKgraph *G, int *newcount, int onecnt_okay),
    CCcut_SRK_identify_paths_to_edges (CC_SRKgraph *G, int *newcount,
        int onecnt_okay),
    CCcut_SRK_identify_ones (CC_SRKgraph *G, int *count, double epsilon),
    CCcut_SRK_identify_one_triangles (CC_SRKgraph *G, int *count,
        CC_SRKnode *qstart, double epsilon),
    CCcut_SRK_identify_nodes (CC_SRKgraph *G, CC_SRKnode *n, CC_SRKnode *m),
    CCcut_SRK_init_graph (CC_SRKgraph *G),
    CCcut_SRK_free_graph (CC_SRKgraph *G),
    CCcut_SRK_init_expinfo (CC_SRKexpinfo *expand),
    CCcut_SRK_free_expinfo (CC_SRKexpinfo *expand),
    CCcut_SRK_init_callback (CC_SRKcallback *cb);

int
    CCcut_SRK_buildgraph (CC_SRKgraph *G, int ncount, int ecount, int *elist,
        double *dlen),
    CCcut_SRK_subtour_shrink (CC_SRKgraph *G, double *minval, double epsilon,
        CC_SRKcallback *cb, int **cut, int *cutcount),
    CCcut_SRK_identify_pr_edges (CC_SRKgraph *G, double *minval, int *count,
        CC_SRKnode *qstart, double epsilon, CC_SRKcallback *cb, int **cut,
        int *cutcount),
    CCcut_SRK_defluff (CC_SRKgraph *G),
    CCcut_SRK_grab_edges (CC_SRKgraph *G, int *oncount, int *oecount,
        int **olist, double **olen, CC_SRKexpinfo *expand),
    CCcut_SRK_grab_nodes (CC_SRKgraph *G, CC_SRKexpinfo *expand),
    CCcut_SRK_trivial (int ncount, CC_SRKexpinfo *expand),
    CCcut_SRK_expand (CC_SRKexpinfo *expand, int *arr, int size, int **pnewarr,
        int *pnewsize);

#else

void
    CCcut_SRK_identify_paths (),
    CCcut_SRK_identify_paths_to_edges (),
    CCcut_SRK_identify_ones (),
    CCcut_SRK_identify_one_triangles (),
    CCcut_SRK_identify_nodes (),
    CCcut_SRK_init_graph (),
    CCcut_SRK_free_graph (),
    CCcut_SRK_init_expinfo (),
    CCcut_SRK_free_expinfo (),
    CCcut_SRK_init_callback ();

int
    CCcut_SRK_buildgraph (),
    CCcut_SRK_subtour_shrink (),
    CCcut_SRK_identify_pr_edges (),
    CCcut_SRK_defluff (),
    CCcut_SRK_grab_edges (),
    CCcut_SRK_grab_nodes (),
    CCcut_SRK_trivial (),
    CCcut_SRK_expand ();

#endif

#endif  /* __CUT_H */
