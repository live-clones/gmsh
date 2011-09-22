#ifndef  __MATPRICE_H
#define  __MATPRICE_H

#ifdef CC_PROTOTYPE_ANSI

int
   matching_price (int ncount, CCdatagroup *dat, double *orig_pi,
                   int *orig_parent, int *badcount, int **badlist,
                   int **badlen, double *penalty, CCtsp_edgegenerator *starteg,
                   char *hit),
   matching_check (int ncount, double *orig_pi, int *orig_parent,
                   int *matchlist, int *mlen, int *csbad);

#else

int
    matching_price (),
    matching_check ();

#endif

#endif  /* __MATPRICE_H */
