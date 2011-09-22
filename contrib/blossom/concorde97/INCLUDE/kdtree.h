#ifndef __KDTREE_H
#define __KDTREE_H

#include "util.h"

typedef struct CCkdnode {
    double           cutval;
    struct CCkdnode *loson;
    struct CCkdnode *hison;
    struct CCkdnode *father;
    struct CCkdnode *next;
    struct CCkdbnds *bnds;
    int              lopt;
    int              hipt;
    char             bucket;
    char             empty;
    char             cutdim;
} CCkdnode;

typedef struct CCkdtree {
    CCkdnode  *root;
    CCkdnode **bucketptr;
    int       *perm;
} CCkdtree;

typedef struct CCkdbnds {
    double           x[2];
    double           y[2];
    struct CCkdbnds *next;
} CCkdbnds;

#ifdef CC_PROTOTYPE_ANSI

void
    CCkdtree_free (CCkdtree *kt),
    CCkdtree_delete (CCkdtree *kt, int k),
    CCkdtree_delete_all (CCkdtree *kt, int ncount),
    CCkdtree_undelete (CCkdtree *kt, int k),
    CCkdtree_undelete_all (CCkdtree *kt, int ncount);
int
    CCkdtree_build (CCkdtree *kt, int ncount, CCdatagroup *dat, double *wcoord),
    CCkdtree_k_nearest (CCkdtree *kt, int ncount, int k, CCdatagroup *dat,
            double *wcoord, int wantlist, int *ocount, int **olist),
    CCkdtree_quadrant_k_nearest (CCkdtree *kt, int ncount, int k,
            CCdatagroup *dat, double *wcoord, int wantlist, int *ocount,
            int **olist),
    CCkdtree_node_k_nearest (CCkdtree *kt, int ncount, int n, int k,
            CCdatagroup *dat, double *wcoord, int *list),
    CCkdtree_node_quadrant_k_nearest (CCkdtree *kt, int ncount, int n, int k,
            CCdatagroup *dat, double *wcoord, int *list),
    CCkdtree_node_nearest (CCkdtree *kt, int n, CCdatagroup *dat,
            double *wcoord),
    CCkdtree_fixed_radius_nearest (CCkdtree *kt, CCdatagroup *dat,
            double *wcoord, int n, double rad,
            int (*doit_fn) (int, int, void *), void *pass_param),
    CCkdtree_nearest_neighbor_tour (CCkdtree *kt, int ncount, int start,
            CCdatagroup *dat, int *outcycle, double *val),
    CCkdtree_nearest_neighbor_2match (CCkdtree *kt, int ncount, int start,
            CCdatagroup *dat, int *outmatch, double *val),
    CCkdtree_prim_spanningtree (CCkdtree *kt, int ncount, CCdatagroup *dat,
            double *wcoord, int *outtree, double *val),
    CCkdtree_greedy_tour (CCkdtree *kt, int ncount, CCdatagroup *dat,
            int *outcycle, double *val),
    CCkdtree_far_add_tour (CCkdtree *kt, int ncount, int start,
            CCdatagroup *dat, int *outcycle, double *val),
    CCkdtree_qboruvka_tour (CCkdtree *kt, int ncount, CCdatagroup *dat,
            int *outcycle, double *val),
    CCkdtree_boruvka_tour (CCkdtree *kt, int ncount, CCdatagroup *dat,
            int *outcycle, double *val),
    CCkdtree_twoopt_tour (CCkdtree *kt, int ncount, CCdatagroup *dat,
            int *incycle, int *outcycle, double *val,
            int in_run_two_and_a_half_opt, int run_silently),
    CCkdtree_3opt_tour (CCkdtree *kt, int ncount, CCdatagroup *dat,
            int *incycle, int *outcycle, double *val, int run_silently);

#else

void
    CCkdtree_free (),
    CCkdtree_delete (),
    CCkdtree_delete_all (),
    CCkdtree_undelete (),
    CCkdtree_undelete_all ();
int
    CCkdtree_build (),
    CCkdtree_k_nearest (),
    CCkdtree_quadrant_k_nearest (),
    CCkdtree_node_k_nearest (),
    CCkdtree_node_quadrant_k_nearest (),
    CCkdtree_node_nearest (),
    CCkdtree_fixed_radius_nearest (),
    CCkdtree_nearest_neighbor_tour (),
    CCkdtree_nearest_neighbor_2match (),
    CCkdtree_prim_spanningtree (),
    CCkdtree_greedy_tour (),
    CCkdtree_far_add_tour (),
    CCkdtree_qboruvka_tour (),
    CCkdtree_boruvka_tour (),
    CCkdtree_twoopt_tour (),
    CCkdtree_3opt_tour ();
#endif

#endif  /* __KDTREE_H */

