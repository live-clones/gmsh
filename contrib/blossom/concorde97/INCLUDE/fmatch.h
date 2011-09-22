#ifndef __FMATCH_H
#define __FMATCH_H

#include "util.h"

#ifdef CC_PROTOTYPE_ANSI

int
    CCfmatch_fractional_2match (int ncount, int ecount, int *elist, int *elen,
        CCdatagroup *dat, double *val, int *thematching, int *thedual,
        int *thebasis, int wantbasic);

#else

int
    CCfmatch_fractional_2match ();

#endif

#endif  /* __FMATCH_H */
