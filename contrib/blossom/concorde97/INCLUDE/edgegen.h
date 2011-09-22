/***************************************************************************/
/***************************************************************************/
/*                                                                         */
/*                      PROTOTYPES FOR FILES IN EDGEGEN                    */
/*                                                                         */
/***************************************************************************/
/***************************************************************************/

#ifndef __EDGEGEN_H
#define __EDGEGEN_H

#include "util.h"


/***************************************************************************/
/*                                                                         */
/*                             edgegen.c                                   */
/*                                                                         */
/***************************************************************************/

typedef struct CCedgegengroup {
    struct {
        int count;
        int quadnearest;
        int nearest;
        int nearest_start;
        int greedy_start;
        int random_start;
        int nkicks;
    } linkern;

    struct {
        int twoopt_count;
        int twoopt5_count;
        int threeopt_count;
        int greedy;
        int nearest_count;
        int random_count;
    } tour;

    struct {
        int wantit;
        int basic;
        int priced;
    } f2match;

    struct {
        int number;
        int basic;
        int priced;
    } f2match_nearest;

    int    nearest;
    int    quadnearest;
    int    want_tree;
    int    nearest_twomatch_count;
    int    delaunay;
    int    mlinkern;
} CCedgegengroup;


#ifdef CC_PROTOTYPE_ANSI

int
    CCedgegen_read (char *egname, CCedgegengroup *plan),
    CCedgegen_edges (CCedgegengroup *plan, int ncount, CCdatagroup *dat,
        double *wcoord, int *ecount, int **elist);
void
    CCedgegen_init_edgegengroup (CCedgegengroup *plan);

#else

int
    CCedgegen_read (),
    CCedgegen_edges ();
void
    CCedgegen_init_edgegengroup ();

#endif



/***************************************************************************/
/*                                                                         */
/*                             xnear.c                                     */
/*                                                                         */
/***************************************************************************/

typedef struct CCxnear {
    struct CCdatagroup  dat;
    double             *w;
    int                *nodenames;
    int                *invnames;
} CCxnear;


#ifdef CC_PROTOTYPE_ANSI

int
    CCedgegen_x_k_nearest (int ncount, int num, CCdatagroup *dat,
        double *wcoord, int wantlist, int *ecount, int **elist),
    CCedgegen_x_quadrant_k_nearest (int ncount, int num, CCdatagroup *dat,
        double *wcoord, int wantlist, int *ecount, int **elist),
    CCedgegen_x_node_k_nearest (CCxnear *xn, int n, int nearnum, int ncount,
        int *list),
    CCedgegen_x_node_quadrant_k_nearest (CCxnear *xn, int n, int nearnum,
        int ncount, int *list),
    CCedgegen_x_node_nearest (CCxnear *xn, int ncount, int ni, char *marks),
    CCedgegen_x_nearest_neighbor_tour (int ncount, int start, CCdatagroup *dat,
        int *outcycle, double *val),
    CCedgegen_junk_k_nearest (int ncount, int num, CCdatagroup *dat,
        double *wcoord, int wantlist, int *ecount, int **elist),
    CCedgegen_junk_node_k_nearest (CCdatagroup *dat, double *wcoord, int n,
        int nearnum, int ncount, int *list),
    CCedgegen_junk_node_nearest (CCdatagroup *dat, double *wcoord, int ncount,
        int n, char *marks),
    CCedgegen_junk_nearest_neighbor_tour (int ncount, int start,
        CCdatagroup *dat, int *outcycle, double *val),
    CCedgegen_xnear_build (int ncount, CCdatagroup *dat, double *wcoord,
        CCxnear *xn);

void
    CCedgegen_xnear_free (int ncount, CCxnear *xn);

#else

int
    CCedgegen_x_k_nearest (),
    CCedgegen_x_quadrant_k_nearest (),
    CCedgegen_x_node_k_nearest (),
    CCedgegen_x_node_quadrant_k_nearest (),
    CCedgegen_x_node_nearest (),
    CCedgegen_x_nearest_neighbor_tour (),
    CCedgegen_junk_k_nearest (),
    CCedgegen_junk_node_k_nearest (),
    CCedgegen_junk_node_nearest (),
    CCedgegen_junk_nearest_neighbor_tour (),
    CCedgegen_xnear_build ();
void
    CCedgegen_xnear_free ();

#endif

#endif  /* __EDGEGEN_H */
