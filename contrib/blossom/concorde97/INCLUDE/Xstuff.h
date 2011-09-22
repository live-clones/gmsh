#ifndef __XSTUFF_H
#define __XSTUFF_H

#ifdef CC_PROTOTYPE_ANSI

int
    Xfastcuts (CCtsp_lpcut_in **cuts, int *cutcount, int ncount, int ecount,
               int *elist, double *x),
    Xslowcuts (CCtsp_lpcut_in **cuts, int *cutcount, int ncount, int ecount,
               int *elist, double *x),
    Xfastsubtours (CCtsp_lpcut_in **cuts, int *cutcount, int ncount, int ecount,
               int *elist, double *x),
    Xexactsubtours (CCtsp_lpcut_in **cuts, int *cutcount, int ncount, int ecount,
               int *elist, double *x),
    Xcliquetrees (CCtsp_lpcut_in **cuts, int *cutcount, int ncount, int ecount,
               int *elist, double *x),
    Xconsecutiveones (CCtsp_lpcut_in **cuts, int *cutcount, int ncount, int ecount,
                      int *elist, double *x, CCtsp_lpcuts *pool),
    Xnecklacecuts (CCtsp_lpcut_in **cuts, int *cutcount, int ncount, int ecount,
                      int *elist, double *x, CCtsp_lpcuts *pool);

#else

int
    Xfastcuts (),
    Xslowcuts (),
    Xfastsubtours (),
    Xexactsubtours (),
    Xcliquetrees (),
    Xconsecutiveones (),
    Xnecklacecuts ();

#endif

#endif  /* __XSTUFF_H */
