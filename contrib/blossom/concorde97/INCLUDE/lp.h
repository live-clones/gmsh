#ifndef __LP_H
#define __LP_H

#define  CClp_METHOD_DUAL    1
#define  CClp_METHOD_BARRIER 2

#define  CClp_SUCCESS        0
#define  CClp_FAILURE        1
#define  CClp_UNBOUNDED      2
#define  CClp_INFEASIBLE     3
#define  CClp_UNKNOWN        4

typedef struct CClp {
    struct cpxenv *cplex_env;
    struct cpxlp  *cplex_lp;
    int            lp_allocated;
} CClp;

typedef struct CClpbasis {
    int       *rstat;
    int       *cstat;
    double    *dnorm;
} CClpbasis;

#ifdef CC_PROTOTYPE_ANSI

int
    CClp_init (CClp *lp),
    CClp_loadlp (CClp *lp, char *name, int ncols, int nrows, int objsense,
            double *obj, double *rhs, char *sense, int *matbeg, int *matcnt,
            int *matind, double *matval, double *lb, double *ub),
    CClp_opt (CClp *lp, int method),
    CClp_dualopt (CClp *lp),
    CClp_limited_dualopt (CClp *lp, int lim, int *status, double *upperbound),
    CClp_primalopt (CClp *lp),
    CClp_addrows (CClp *lp, int newrows, int newnz, double *rhs, char *sense,
            int *rmatbeg, int *rmatind, double *rmatval),
    CClp_addcols (CClp *lp, int newcols, int newnz, double *obj,
            int *cmatbeg, int *cmatind, double *cmatval, double *lb,
            double *ub),
    CClp_delete_row (CClp *lp, int i),
    CClp_delete_set_of_rows (CClp *lp, int *delstat),
    CClp_delete_column (CClp *lp, int i),
    CClp_delete_set_of_columns (CClp *lp, int *delstat),
    CClp_setbnd (CClp *lp, int col, char lower_or_upper, double bnd),
    CClp_get_basis_and_norms (CClp *lp, CClpbasis *b),
    CClp_load_basis_and_norms (CClp *lp, CClpbasis *b),
    CClp_basis (CClp *lp, int *cstat, int *rstat),
    CClp_loadbasis (CClp *lp, int *cstat, int *rstat),
    CClp_getbasis_and_norms (CClp *lp, int *cstat, int *rstat,
            double *dnorm),
    CClp_loadbasis_and_norms (CClp *lp, int *cstat, int *rstat,
                              double *dnorm),
    CClp_x (CClp *lp, double *x),
    CClp_rc (CClp *lp, double *rc),
    CClp_pi_range (CClp *lp, double *pi, int from, int to),
    CClp_objval (CClp *lp, double *obj),
    CClp_nonzeros (CClp *lp),
    CClp_status (CClp *lp, int *status),
    CClp_getweight (CClp *lp, int nrows, int *rmatbeg, int *rmatind,
            double *rmatval, double *weight),
    CClp_dump_lp (CClp *lp, char *fname),
    CClp_getgoodlist (CClp *lp, int *goodlist, int *goodlen_p,
            double *downpen, double *uppen),
    CClp_strongbranch (CClp *lp, int *candidatelist, int ncand,
            double *downpen, double *uppen, int iterations,
            double *upperbound),
    CClp_getfarkasmultipliers (CClp *lp, double *y);

void
    CClp_init_struct (CClp *lp),
    CClp_free (CClp *lp),
    CClp_init_basis (CClpbasis *b),
    CClp_free_basis (CClpbasis *b),
    CClp_pivotin (CClp *lp, int i);

#else

int
    CClp_init (),
    CClp_loadlp (),
    CClp_opt (),
    CClp_dualopt (),
    CClp_limited_dualopt (),
    CClp_primalopt (),
    CClp_addrows (),
    CClp_addcols (),
    CClp_delete_row (),
    CClp_delete_set_of_rows (),
    CClp_delete_column (),
    CClp_delete_set_of_columns (),
    CClp_setbnd (),
    CClp_get_basis_and_norms (),
    CClp_load_basis_and_norms (),
    CClp_basis (),
    CClp_loadbasis (),
    CClp_getbasis_and_norms (),
    CClp_loadbasis_and_norms (),
    CClp_x (),
    CClp_rc (),
    CClp_pi_range (),
    CClp_objval (),
    CClp_nonzeros (),
    CClp_status (),
    CClp_getweight (),
    CClp_dump_lp (),
    CClp_getgoodlist (),
    CClp_strongbranch (),
    CClp_getfarkasmultipliers ();

void
    CClp_init_struct (),
    CClp_free (),
    CClp_init_basis (),
    CClp_free_basis (),
    CClp_pivotin ();

#endif


#endif  /* __LP_H */
