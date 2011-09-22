/***************************************************************************/
/*                                                                         */
/*              Interface Routines to The CPLEX LP Solver                  */
/*                                                                         */
/*  NOTE: Use this code in place of lpsolve.c to access the Cplex 4.1      */
/*   library. You will also need to link the cplex library via the         */
/*   makefile.                                                             */
/*                                                                         */
/*                             TSP CODE                                    */
/*                                                                         */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook                       */
/*  Date: April 17, 1997                                                   */
/*        June 19, 1997 (bico, REB)                                        */
/*                                                                         */
/*                                                                         */
/*  EXPORTED FUNCTIONS:                                                    */
/*                                                                         */
/*    void CClp_init_struct (CClp *lp)                                     */
/*      INITIALIZES the fields of the LP structure to NULL.                */
/*                                                                         */
/*    int CClp_init (CClp *lp)                                             */
/*      INITIALIZES the LP.                                                */
/*                                                                         */
/*   void CClp_free (CClp *lp)                                             */
/*      FREES the LP (but not pointer to the LP).                          */
/*                                                                         */
/*   int CClp_loadlp (CClp *lp, char *name, int ncols, int nrows,          */
/*            int objsense, double *obj, double *rhs, char *sense,         */
/*            int *matbeg, int *matcnt,                                    */
/*            int *matind, double *matval,                                 */
/*            double *lb, double *ub)                                      */
/*      LOADS the data into the LP. The memory is used by the LP solver,   */
/*       and thus should not be freed until after a call to CClp_free.     */
/*        -name attaches a name to the LP (it can be used by the LP solver */
/*         in io routines)                                                 */
/*        -ncols and nrows give the number of columns and rows in the LP   */
/*        -objsense should be -1 for minimize and 1 for maximize           */
/*        -obj and rhs are arrays giving the objective function and rhs    */
/*        -sense is an array specifying 'L', 'E', or 'G' for each of the   */
/*         rows                                                            */
/*        -matbeg, matcnt, matind, and matval give the coefficients of     */
/*         the contraint matrix in column by column order. matbeg gives    */
/*         gives the index of the start of each column; matcnt gives the   */
/*         number of coefficients in each column; matind gives the indices */
/*         of the rows where the coefficients are located in the contraint */
/*         matrix (so for column j, the indices are given in matcnt[j]     */
/*         locations starting at matind[matbeg[j]]; and matval gives the   */
/*         actual coefficients (organized like matind).                    */
/*        -lb and ub are arrays giving the upper and lower bounds of       */
/*         the variables.                                                  */
/*                                                                         */
/*   int CClp_opt (CClp *lp, int method)                                   */
/*      CALLS designated LP solution method.                               */
/*                                                                         */
/*   int CClp_dualopt (CClp *lp)                                           */
/*      CALLS the dual simplex method.                                     */
/*                                                                         */
/*   int CClp_limited_dualopt (CClp *lp, int lim, double *upperbound,      */
/*           int *status)                                                  */
/*      CALLS the dual simplex method with a limit on the number of pivots.*/
/*        -upperbound it is used to cutoff the dual simplex method (when   */
/*         the objective value reaches upperbound); it can be NULL         */
/*        -status returns the status of the optimization (it can be NULL)  */
/*                                                                         */
/*   void CClp_pivotin (CClp *lp, int i)                                   */
/*      Puts slack/artificial on row i into the resident basis             */
/*      If there is no resident basis, the call fails                      */
/*                                                                         */
/*   int CClp_primalopt (CClp *lp)                                         */
/*      CALLS the primal simplex method.                                   */
/*                                                                         */
/*   int CClp_addrows (CClp *lp, int newrows, int newnz, double *rhs,      */
/*            char *sense, int *rmatbeg, int *rmatind, double *rmatval)    */
/*      ADDS the rows to the LP.                                           */
/*        -newrows is the number of rows to be added                       */
/*        -newnz is the number of nonzero coefficients in the new rows     */
/*        -rhs is an array of the rhs values for the new rows              */
/*        -sense is 'L', 'E', or 'G' for each of the new rows              */
/*        -rmatbeg, rmatind, and rmatval give the coefficients of the      */
/*         new rows in sparse format. The arrays can be freed after the    */
/*         call.                                                           */
/*                                                                         */
/*   int CClp_addcols (CClp *lp, int newcols, int newnz, double *obj,      */
/*            int *cmatbeg, int *cmatind, double *cmatval,                 */
/*            double *lb, double *ub)                                      */
/*      ADDS the columns to the LP.                                        */
/*                                                                         */
/*   int CClp_delete_row (CClp *lp, int i)                                 */
/*      DELETES row i of the LP.                                           */
/*                                                                         */
/*   int CClp_delete_set_of_rows (CClp *lp, int *delstat)                  */
/*      DELETES the rows corresponding to 1 entries in delstat.            */
/*        -delstat is a 0/1 array having an entry for each row             */
/*                                                                         */
/*   int CClp_delete_column (CClp *lp, int i)                              */
/*      DELETES column i from the LP.                                      */
/*                                                                         */
/*   int CClp_delete_set_of_columns (CClp *lp, int *delstat)               */
/*      DELETES the columns corresponding to the 1 entries in delstat.     */
/*        -delstat is a 0/1 array having an entry for each column          */
/*                                                                         */
/*   int CClp_setbnd (CClp *lp, int col, char lower_or_upper, double bnd)  */
/*      SETS the bound on the variable index by col.                       */
/*        -lower_or_upper should be either 'L' or 'U'                      */
/*                                                                         */
/*   void CClp_init_basis (CClpbasis *b)                                   */
/*      INITIALIZES the fields of the basis structure.                     */
/*                                                                         */
/*   void CClp_free_basis (CClpbasis *b)                                   */
/*      FREEs the basis structure.                                         */
/*                                                                         */
/*   int CClp_get_basis_and_norms (CClp *lp, CClpbasis *b)                 */
/*      RETURNS the current basis and dual norms.                          */
/*      Note: The arrays are allocated by this function are should be      */
/*       freed by a call to CC_lp_free_basis ().                           */
/*                                                                         */
/*   int CClp_load_basis_and_norms (CClp *lp, CClpbasis *b)                */
/*      LOADS the basis and norm int the LP.                               */
/*      Note: If the norms field is not set, then just the basis is loaded.*/
/*                                                                         */
/*   int CClp_basis (CClp *lp, int *cstat, int *rstat)                     */
/*      RETURNS the current basis. cstat or rstat can by NULL.             */
/*        -cstat should be an array of length at least ncols               */
/*        -rstat should be an array of length at least nrows               */
/*                                                                         */
/*   int CClp_loadbasis (CClp *lp, int *cstat, int *rstat)                 */
/*      LOADS the basis into the LP.                                       */
/*                                                                         */
/*   int CClp_getbasis_and_norms (CClp *lp, int *cstat, int *rstat,        */
/*          double *dnorm)                                                 */
/*      RETURNS the current basis and dual norms - these items should be   */
/*       used as a pair, in calls to CClp_loadbasis_and_norms.             */
/*        -dnorms should be an array of length at least nrows              */
/*                                                                         */
/*   int CClp_loadbasis_and_norms (CClp *lp,int *cstat, int *rstat,        */
/*          double *dnorm)                                                 */
/*      LOADS the basis and dual norms into the LP. (This pair should      */
/*       have been obtained by a call to CClp_getbasis_and_norms.          */
/*                                                                         */
/*   int CClp_x (CClp *lp, double *x)                                      */
/*      RETURNS the current LP solution.                                   */
/*        -x should be an array of length at least ncols                   */
/*                                                                         */
/*   int CClp_rc (CClp *lp, double *rc)                                    */
/*      RETURNS the current reduced costs.                                 */
/*        -rc should be an array of length at least ncols                  */
/*                                                                         */
/*   int CClp_pi_range (CClp *lp, double *pi, int from, int to)            */
/*      RETURNS the dual values on the constraints indexed [from, to].     */
/*        -pi should be an array of length at least (to-from+1)            */
/*                                                                         */
/*   int CClp_objval (CClp *lp, double *obj)                               */
/*      RETURNS the objective value of the lp.                             */
/*                                                                         */
/*   int CClp_nonzeros (CClp *lp)                                          */
/*      RETURNS the number of nonzeros in the LP.                          */
/*                                                                         */
/*   int CClp_status (CClp *lp, int *status)                               */
/*      CHECKS whether the current lp is infeasible or whether an optimal  */
/*       solution has been found. It returns an error if the LP has not    */
/*       not been optimized.                                               */
/*        -lp is the lp                                                    */
/*        -status returns 0 if the lp has an optimal solution and 1 if it  */
/*         is infeasible.                                                  */
/*                                                                         */
/*   int CClp_getweight (CClp *lp, int nrows, int *rmatbeg, int *rmatind,  */
/*          double *rmatval, double *weight)                               */
/*      COMPUTES the duals of the steepest edge norms for the n rows       */
/*       specified in rmatbeg, rmatind, and rmatval.                       */
/*        -weight returns the array of weights; the array should be at     */
/*         least nrows long                                                */
/*                                                                         */
/*   int CClp_dump_lp (CClp *lp, char *fname)                              */
/*      WRITES the LP to file fname.                                       */
/*                                                                         */
/*   int CClp_getgoodlist (CClp *lp, int *goodlist, int *ngood,            */
/*          double *downpen, double *uppen)                                */
/*      RETURNS an array of the column indices corresponding to variables  */
/*       that move in both the up and down directions. This is a useful    */
/*       list of candidates for strong branching.                          */
/*        -goodlist, downpen and uppen should be arrays of length at       */
/*         least ncols.                                                    */
/*                                                                         */
/*   int CClp_strongbranch (CClp *lp, int *candidatelist, int ncand,       */
/*          double *downpen, double *uppen, int iterations,                */
/*          double *upperbound)                                            */
/*      RETURNS estimates of the lp values obtained by setting each of the */
/*        ncand variables listed in candidatelist to 0 and 1. The estimates*/
/*        are obtained by performing iterations pivots of dual simplex     */
/*        method. If upperbound is not NULL, then it is used to cutoff the */
/*        dual simplex method.                                             */
/*         -downpen and uppen should be arrays of length at least ncand    */
/*                                                                         */
/*    int CClp_getfarkasmultipliers (CClp *lp, double *y)                  */
/*      RETURNS the multipliers for a Farkas' proof after dualopt returns  */
/*       with an unbound lp.                                               */
/*        -y should point to an array at least as long as the number of    */
/*         rows                                                            */
/*      The y[] computed will satisfy the following:                       */
/*                                                                         */
/*         y_i <= 0  for <= constraints                                    */
/*         y_i >= 0  for >= constraints                                    */
/*                                                                         */
/*         y'b - sum (y'A_j * u_j: y'A_j > 0)                              */
/*             - sum (y'A_j * l_j: y'A_j < 0) > 0                          */
/*                                                                         */
/*      where b is the rhs vector, u_j is the upper bound on variable x_j, */
/*      l_j the lower bound, and A_j the constraint matrix column for x_j. */
/*                                                                         */
/*                                                                         */
/*  NOTES:                                                                 */
/*                                                                         */
/*                                                                         */
/***************************************************************************/


#include "machdefs.h"
#include "util.h"
#include "macrorus.h"
#include "lp.h"
#include <cplex.h>

#undef CC_CPLEX_DISPLAY

#ifdef CC_PROTOTYPE_ANSI
void CClp_init_struct (CClp *lp)
#else
void CClp_init_struct (lp)
CClp *lp;
#endif
{
    lp->cplex_env    = (CPXENVptr) NULL;
    lp->cplex_lp     =  (CPXLPptr) NULL;
    lp->lp_allocated = 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CClp_init (CClp *lp)
#else
int CClp_init (lp)
CClp *lp;
#endif
{
    int rval = 0;

    CClp_init_struct (lp);

    lp->cplex_env = CPXopenCPLEXdevelop (&rval);
    if (rval) {
        fprintf (stderr, "cplex open failed\n"); goto CLEANUP;
    }

#ifdef CC_CPLEX_DISPLAY
    /* the documentation doesn't say what the return value means */
    rval = CPXsetintparam (lp->cplex_env, CPX_PARAM_SCRIND, 1);
    if (rval) {
        fprintf (stderr, "cplex set SCR_IND failed\n"); goto CLEANUP;
    }

    rval = CPXsetintparam (lp->cplex_env, CPX_PARAM_SIMDISPLAY, 1);
    if (rval) {
        fprintf (stderr, "cplex setitfoind failed\n"); goto CLEANUP;
    }
#endif

    rval = CPXsetintparam (lp->cplex_env, CPX_PARAM_ADVIND, 1);
    if (rval) {
        fprintf (stderr, "cplex setadvind failed\n"); goto CLEANUP;
    }
    rval = CPXsetintparam (lp->cplex_env, CPX_PARAM_DPRIIND,
                           CPX_DPRIIND_STEEP);
    if (rval) {
        fprintf (stderr, "cplex setdpriind failed\n"); goto CLEANUP;
    }
    rval = CPXsetintparam (lp->cplex_env, CPX_PARAM_PPRIIND,
                           CPX_PPRIIND_STEEP);
    if (rval) {
        fprintf (stderr, "cplex setppriind failed\n"); goto CLEANUP;
    }

CLEANUP:

    if (rval) {
        CClp_free (lp);
    } else {
        lp->lp_allocated = 1;
    }

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
void CClp_free (CClp *lp)
#else
void CClp_free (lp)
CClp *lp;
#endif
{
    if (lp->cplex_env) {
        if (lp->cplex_lp) {
            CPXfreeprob (lp->cplex_env, &lp->cplex_lp);
        }
        CPXcloseCPLEX (&lp->cplex_env);
    }
    lp->lp_allocated = 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CClp_loadlp (CClp *lp, char *name, int ncols, int nrows,
                 int objsense, double *obj, double *rhs, char *sense,
                 int *matbeg, int *matcnt,
                 int *matind, double *matval,
                 double *lb, double *ub)

#else
int CClp_loadlp (lp, name, ncols, nrows, objsense, obj, rhs, sense, matbeg,
                 matcnt, matind, matval, lb, ub)
CClp *lp;
char *name;
int ncols, nrows;
int objsense;
double *obj, *rhs;
char *sense;
int *matbeg, *matcnt, *matind;
double *matval, *lb, *ub;
#endif
{
    int  rval = 0;

    lp->cplex_lp = CPXcreateprob (lp->cplex_env, &rval, name);
    if (!lp->cplex_lp || rval) {
       fprintf (stderr, "CPXcreateprob failed\n"); return 1;
    }

    rval = CPXcopylp (lp->cplex_env, lp->cplex_lp, ncols, nrows,
                      objsense, obj, rhs, sense, matbeg, matcnt,
                      matind, matval, lb, ub, (double *) NULL);
    if (rval) {
       fprintf (stderr, "CPXcopylp failed\n");  return 1;
    }

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CClp_opt (CClp *lp, int method)
#else
int CClp_opt (lp, method)
CClp *lp;
int method;
#endif
{
    int  rval = 0;

    switch (method) {
        case CClp_METHOD_DUAL:
            rval = CClp_dualopt (lp);
            break;
            /* The purpose of this function is to support calls to other
               LP algorithms, such CPXbaropt.  However, the current
               version of concorde (14 August 1997) does not use this
               feature */
        default: 
            rval = 1;
            fprintf (stderr, "Nonexistent method in CClp_opt\n");
            break;
    }
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CClp_dualopt (CClp *lp)
#else
int CClp_dualopt (lp)
CClp *lp;
#endif
{
    int rval;
    int solstat;
#ifdef  CC_CPLEX_WRITE_DUAL
    static int  probcnt = 0;
    char probname[100];

    sprintf (probname, "%s.dual%d.sav", lp->lpspace.probname, probcnt);
    probcnt++;
    printf ("Writing %s\n", probname);
    CPXsavwrite (lp->cplex_env, lp->cplex_lp, probname);
#endif

    rval = CPXdualopt (lp->cplex_env, lp->cplex_lp);
    if (rval) {
        if (rval == CPXERR_PRESLV_INForUNBD) {
            int old;
            printf ("Cplex presolved failed, switch to simplex\n");
            fflush (stdout);
            if (CPXgetintparam (lp->cplex_env, CPX_PARAM_PREIND, &old)) {
                fprintf (stderr, "CPXsetintparam failed\n");
                return 1;
            }
            if (CPXsetintparam (lp->cplex_env, CPX_PARAM_PREIND, CPX_OFF)) {
                fprintf (stderr, "CPXsetintparam failed\n");
                return 1;
            }
            rval = CPXdualopt (lp->cplex_env, lp->cplex_lp);
            if (rval) {
                fprintf (stderr, "Cplex failed\n");
                return 1;
            }
            if (CPXsetintparam (lp->cplex_env, CPX_PARAM_PREIND, old)) {
                fprintf (stderr, "CPXsetintparam failed\n");
                return 1;
            }
        } else {
            fprintf (stderr, "Cplex failed\n");
            return 1;
        }
    }
    solstat = CPXgetstat (lp->cplex_env, lp->cplex_lp);
    if (solstat == CPX_UNBOUNDED) {
        printf ("Infeasible in cplex_dualopt\n");
        return 2;
    } else if (solstat != CPX_OPTIMAL && solstat != CPX_OPTIMAL_INFEAS) {
        fprintf (stderr, "Cplex optimization status %d\n", solstat);
        if (solstat == CPX_IT_LIM_FEAS) {
            int itlim;
            rval = CPXgetintparam (lp->cplex_env, CPX_PARAM_ITLIM, &itlim);
            if (!rval) {
                printf ("cplex interation limit: %d\n", itlim);
                fflush (stdout);
            }
            return 1;
        }
    }
    return 0;
}

#define CC_MAX_REFACTORFREQ  150

#ifdef CC_PROTOTYPE_ANSI
int CClp_limited_dualopt (CClp *lp, int iterationlim, int *status,
                          double *objupperlim)
#else
int CClp_limited_dualopt (lp, iterationlim, status, objupperlim)
CClp *lp;
int iterationlim;
int *status;
double *objupperlim;
#endif
{
    int rval = 0;
    int sval = 0;
    int solstat;

    int got_iterationlim = 0;
    int got_presolveind  = 0;
    int got_objupperlim  = 0;
    int got_refactorfreq = 0;

    int    old_iterationlim;
    int    old_presolveind;
    double old_objupperlim;
    int    old_refactorfreq;

    rval = CPXgetintparam (lp->cplex_env, CPX_PARAM_ITLIM, &old_iterationlim);
    if (rval) {
        fprintf (stderr, "CPXgetintparam failed\n"); goto CLEANUP;
    }
    got_iterationlim = 1;

    rval = CPXgetdblparam (lp->cplex_env, CPX_PARAM_OBJULIM, &old_objupperlim);
    if (rval) {
        fprintf (stderr, "CPXgetdblparam failed\n"); goto CLEANUP;
    }
    got_objupperlim = 1;

    rval = CPXgetintparam (lp->cplex_env, CPX_PARAM_PREIND, &old_presolveind);
    if (rval) {
        fprintf (stderr, "CPXgetintparam failed\n"); goto CLEANUP;
    }
    got_presolveind = 1;

    rval = CPXgetintparam (lp->cplex_env, CPX_PARAM_REINV, &old_refactorfreq);
    if (rval) {
        fprintf (stderr, "CPXgetintparam failed\n"); goto CLEANUP;
    }
    got_refactorfreq = 1;

    rval = CPXsetintparam (lp->cplex_env, CPX_PARAM_ITLIM, iterationlim);
    if (rval) {
        fprintf (stderr, "CPXsetintparam failed\n"); goto CLEANUP;
    }

    if ( iterationlim < CC_MAX_REFACTORFREQ ) {
        rval = CPXsetintparam (lp->cplex_env, CPX_PARAM_REINV, iterationlim+1);
        if (rval) {
            fprintf (stderr, "CPXsetintparam failed\n"); goto CLEANUP;
        }
    }

    if (objupperlim) {
        rval = CPXsetdblparam (lp->cplex_env, CPX_PARAM_OBJULIM, *objupperlim);
        if (rval) {
            fprintf (stderr, "CPXsetdblparam failed\n"); goto CLEANUP;
        }
    }

    rval = CPXdualopt (lp->cplex_env, lp->cplex_lp);
    if (rval) {
        if (rval == CPXERR_PRESLV_INForUNBD) {
            printf ("Cplex presolve failed, force simplex\n");
            fflush (stdout);

            if (CPXsetintparam (lp->cplex_env, CPX_PARAM_PREIND, CPX_OFF)) {
                fprintf (stderr, "CPXsetintparam failed\n"); goto CLEANUP;
            }
            rval = CPXdualopt (lp->cplex_env, lp->cplex_lp);
            if (rval) {
                fprintf (stderr, "Cplex failed\n"); goto CLEANUP;
            }
        } else {
            fprintf (stderr, "Cplex failed\n"); goto CLEANUP;
        }
    }
    solstat = CPXgetstat (lp->cplex_env, lp->cplex_lp);
    if (solstat==CPX_IT_LIM_INFEAS) {
        rval = CPXsetdblparam (lp->cplex_env, CPX_PARAM_OBJULIM, -1.0E75);
        if (rval) {
            fprintf (stderr, "CPXsetdblparam failed\n"); goto CLEANUP;
        }
        /* We could be even more aggressive here and make the iteration
           limit infinite, but that approach seems contrary to the
           intent of this function.  Hence, the repeat test for
           CPX_IT_LIM_INFEAS below -- REB, 1 July 97 */
        rval = CPXdualopt (lp->cplex_env, lp->cplex_lp);
        if (rval) {
            fprintf (stderr, "Cplex failed\n"); goto CLEANUP;
        }
    }

    if (solstat == CPX_UNBOUNDED) {
        printf ("Infeasible in cplex_dualopt\n"); fflush (stdout);
        if (status) *status = CClp_INFEASIBLE;
    } else if (solstat == CPX_IT_LIM_INFEAS) {
        printf ("LP infeasible after the limited number of iterations\n");
        fflush (stdout);
        if (status) *status = CClp_UNKNOWN;
    } else if (solstat != CPX_OPTIMAL && solstat != CPX_OPTIMAL_INFEAS &&
               solstat != CPX_IT_LIM_FEAS && solstat != CPX_OBJ_LIM) {
        fprintf (stderr, "Cplex optimization status %d\n", solstat);
        if (status) *status = CClp_FAILURE;
    } else {
        if (status) *status = CClp_SUCCESS;
    }

CLEANUP:

    if (got_iterationlim == 1) {
        sval = CPXsetintparam (lp->cplex_env, CPX_PARAM_ITLIM,
                               old_iterationlim);
        if (sval) {
            fprintf (stderr, "CPXsetintparam failed\n");
            rval = 1;
        }
    }

    if (got_objupperlim == 1) {
        sval = CPXsetdblparam (lp->cplex_env, CPX_PARAM_OBJULIM,
                               old_objupperlim);
        if (sval) {
            fprintf (stderr, "CPXsetdblparam failed\n");
            rval = 1;
        }
    }

    if (got_presolveind == 1) {
        sval = CPXsetintparam (lp->cplex_env, CPX_PARAM_PREIND,
                               old_presolveind);
        if (sval) {
            fprintf (stderr, "CPXsetintparam failed\n");
            rval = 1;
        }
    }

    if (got_refactorfreq == 1) {
        sval = CPXsetintparam (lp->cplex_env, CPX_PARAM_REINV,
                               old_refactorfreq);
        if (sval) {
            fprintf (stderr, "CPXsetintparam failed\n");
            rval = 1;
        }
    }

    if (rval && status) {
        *status = CClp_FAILURE;
    }

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CClp_primalopt (CClp *lp)
#else
int CClp_primalopt (lp)
CClp *lp;
#endif
{
    int rval;
    int solstat;
#ifdef  CC_CPLEX_WRITE_PRIMAL
    static int  probcnt = 0;
    char probname[100];

    sprintf (probname, "%s.prim%d.sav", lp->lpspace.probname, probcnt);
    probcnt++;
    printf ("Writing %s\n", probname);
    CPXsavwrite (lp->cplex_env, lp->cplex_lp, probname);
#endif

    rval = CPXprimopt (lp->cplex_env, lp->cplex_lp);
    if (rval) {
        fprintf (stderr, "Cplex optimize failed\n");
        return 1;
    }
    solstat = CPXgetstat (lp->cplex_env, lp->cplex_lp);
    if (solstat == CPX_INFEASIBLE) {
        printf ("Infeasible.\n");
        return 2;
    } else if (solstat != CPX_OPTIMAL && solstat != CPX_OPTIMAL_INFEAS) {
        fprintf (stderr, "Cplex optimization status %d\n", solstat);
        return 1;
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CClp_addrows (CClp *lp, int newrows, int newnz, double *rhs, char *sense,
                  int *rmatbeg, int *rmatind, double *rmatval)
#else
int CClp_addrows (lp, newrows, newnz, rhs, sense, rmatbeg, rmatind, rmatval)
CClp *lp;
int newrows, newnz;
double *rhs;
char *sense;
int *rmatbeg, *rmatind;
double *rmatval;
#endif
{
    int rval = 0;

    rval = CPXaddrows (lp->cplex_env, lp->cplex_lp, 0, newrows, newnz,
                       rhs, sense, rmatbeg, rmatind, rmatval,
                       (char **) NULL, (char **) NULL);
    if (rval) fprintf (stderr, "CPXaddrows failed\n");
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CClp_addcols (CClp *lp, int newcols, int newnz, double *obj,
                  int *cmatbeg, int *cmatind, double *cmatval,
                  double *lb, double *ub)
#else
int CClp_addcols (lp, newcols, newnz, obj, cmatbeg, cmatind, cmatval, lb, ub)
CClp *lp;
int newcols, newnz;
double *obj;
int *cmatbeg, *cmatind;
double *cmatval;
double *lb, *ub;
#endif
{
    int rval = 0;

    rval = CPXaddcols (lp->cplex_env, lp->cplex_lp, newcols, newnz, obj,
                   cmatbeg, cmatind, cmatval, lb, ub, (char **) NULL);
    if (rval) fprintf (stderr, "CPXaddcols failed\n");
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CClp_delete_row (CClp *lp, int i)
#else
int CClp_delete_row (lp, i)
CClp *lp;
int i;
#endif
{
    int rval = 0;

    rval = CPXdelrows (lp->cplex_env, lp->cplex_lp, i, i);
    if (rval) fprintf (stderr, "CPXdelrows failed\n");
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CClp_delete_set_of_rows (CClp *lp, int *delstat)
#else
int CClp_delete_set_of_rows (lp, delstat)
CClp *lp;
int *delstat;
#endif
{
    int rval = 0;

    rval = CPXdelsetrows (lp->cplex_env, lp->cplex_lp, delstat);
    if (rval) fprintf (stderr, "CPXdelsetrows failed\n");
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CClp_delete_column (CClp *lp, int i)
#else
int CClp_delete_column (lp, i)
CClp *lp;
int i;
#endif
{
    int rval = 0;

    rval = CPXdelcols (lp->cplex_env, lp->cplex_lp, i, i);
    if (rval) fprintf (stderr, "CPXdelcols failed\n");
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CClp_delete_set_of_columns (CClp *lp, int *delstat)
#else
int CClp_delete_set_of_columns (lp, delstat)
CClp *lp;
int *delstat;
#endif
{
    int rval = 0;

    rval = CPXdelsetcols (lp->cplex_env, lp->cplex_lp, delstat);
    if (rval) fprintf (stderr, "CPXdelsetcols failed\n");
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CClp_setbnd (CClp *lp, int col, char lower_or_upper, double bnd)
#else
int CClp_setbnd (lp, col, lower_or_upper, bnd)
CClp *lp;
int col;
char lower_or_upper;
double bnd;
#endif
{
    int cindex[1];
    double bd[1];
    char lu[1];
    int rval;

    cindex[0] = col;
    lu[0] = lower_or_upper;
    bd[0] = bnd;

    rval = CPXchgbds (lp->cplex_env, lp->cplex_lp, 1, cindex, lu, bd);
    if (rval) {
        fprintf (stderr, "Couldn't set bnd on variable %d in cplex\n", col);
        return rval;
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
void CClp_init_basis (CClpbasis *b)
#else
void CClp_init_basis (b)
CClpbasis *b;
#endif
{
    if (b) {
        b->cstat = (int *) NULL;
        b->rstat = (int *) NULL;
        b->dnorm = (double *) NULL;
    }
}

#ifdef CC_PROTOTYPE_ANSI
void CClp_free_basis (CClpbasis *b)
#else
void CClp_free_basis (b)
CClpbasis *b;
#endif
{
    if (b) {
        CC_IFFREE (b->cstat, int);
        CC_IFFREE (b->rstat, int);
        CC_IFFREE (b->dnorm, double);
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CClp_get_basis_and_norms (CClp *lp, CClpbasis *b)
#else
int CClp_get_basis_and_norms (lp, b)
CClp *lp;
CClpbasis *b;
#endif
{
    int rval = 0;
    int ncols, nrows;

    CClp_init_basis (b);

    ncols = CPXgetnumcols (lp->cplex_env, lp->cplex_lp);
    if (ncols == 0) {
        fprintf (stderr, "No columns in LP\n");
        rval = 1; goto CLEANUP;
    }
    nrows = CPXgetnumrows (lp->cplex_env, lp->cplex_lp);
    if (nrows == 0) {
        fprintf (stderr ,"No rows in LP\n");
        rval = 1; goto CLEANUP;
    }

    b->cstat = CC_SAFE_MALLOC (ncols, int);
    b->rstat = CC_SAFE_MALLOC (nrows, int);
    b->dnorm = CC_SAFE_MALLOC (nrows, double);
    if (!b->cstat || !b->rstat || !b->dnorm) {
        fprintf (stderr, "out of memory in CClp_get_basis_and_norms\n");
        rval = 1; goto CLEANUP;
    }

    rval = CPXgetbasednorms (lp->cplex_env, lp->cplex_lp, b->cstat, b->rstat,
                             b->dnorm);
    if (rval) {
        fprintf (stderr, "CPXgetbasednorms failed\n"); goto CLEANUP;
    }

    return 0;

CLEANUP:

    CClp_free_basis (b);
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CClp_load_basis_and_norms (CClp *lp, CClpbasis *b)
#else
int CClp_load_basis_and_norms (lp, b)
CClp *lp;
CClpbasis *b;
#endif
{
    int rval = 0;

    if (b->cstat && b->rstat && b->dnorm) {
        rval = CPXcopybasednorms (lp->cplex_env, lp->cplex_lp, b->cstat,
                                  b->rstat, b->dnorm);
        if (rval) {
            fprintf (stderr, "CPXcopybasednorms failed\n"); goto CLEANUP;
        }
    } else if (b->cstat && b->rstat) {
        rval = CPXloadbase (lp->cplex_env, lp->cplex_lp, b->cstat, b->rstat);
        if (rval) {
            fprintf (stderr, "CPXloadbase failed\n"); goto CLEANUP;
        }
    } else {
        printf ("WARNING: No basis or norms in call to load_basis_and_norms\n");
        fflush (stdout);
    }

CLEANUP:

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CClp_basis (CClp *lp, int *cstat, int *rstat)
#else
int CClp_basis (lp, cstat, rstat)
CClp *lp;
int *cstat;
int *rstat;
#endif
{
    int rval;

    rval = CPXgetbase (lp->cplex_env, lp->cplex_lp, cstat, rstat);
    if (rval) {
        fprintf (stderr, "CPXgetbase failed\n");
        return rval;
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CClp_loadbasis (CClp *lp, int *cstat, int *rstat)
#else
int CClp_loadbasis (lp, cstat, rstat)
CClp *lp;
int *cstat, *rstat;
#endif
{
    int rval;

    rval = CPXloadbase (lp->cplex_env, lp->cplex_lp, cstat, rstat);
    if (rval) {
        fprintf (stderr, "CPXloadbase failed\n");
        return rval;
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CClp_getbasis_and_norms (CClp *lp, int *cstat, int *rstat, double *dnorm)
#else
int CClp_getbasis_and_norms (lp, cstat, rstat, dnorm)
CClp *lp;
int *cstat, *rstat;
double *dnorm;
#endif
{
    int rval;

    rval = CPXgetbasednorms (lp->cplex_env, lp->cplex_lp, cstat, rstat,
                             dnorm);
    if (rval) {
        fprintf (stderr, "CPXgetbasednorms failed\n");
        return rval;
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CClp_loadbasis_and_norms (CClp *lp, int *cstat, int *rstat,
                                 double *dnorm)
#else
int CClp_loadbasis_and_norms (lp, cstat, rstat, dnorm)
CClp *lp;
int *cstat, *rstat;
double *dnorm;
#endif
{
    int rval;

    rval = CPXcopybasednorms (lp->cplex_env, lp->cplex_lp, cstat, rstat,
                              dnorm);
    if (rval) {
        fprintf (stderr, "CPXcopybasednorms failed\n");
        return rval;
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CClp_x (CClp *lp, double *x)
#else
int CClp_x (lp, x)
CClp *lp;
double *x;
#endif
{
    int rval = 0;
    int ncols;

    ncols = CPXgetnumcols (lp->cplex_env, lp->cplex_lp);
    if (ncols == 0) {
        fprintf (stderr, "No columns in LP\n");
        return 1;
    }
    rval = CPXgetx (lp->cplex_env, lp->cplex_lp, x, 0, ncols - 1);
    if (rval) {
        fprintf (stderr, "CPXgetx failed\n");
        return rval;
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CClp_rc (CClp *lp, double *rc)
#else
int CClp_rc (lp, rc)
CClp *lp;
double *rc;
#endif
{
    int rval = 0;
    int ncols;

    ncols = CPXgetnumcols (lp->cplex_env, lp->cplex_lp);
    if (ncols == 0) {
        fprintf (stderr, "No columns in LP\n"); return 1;
    }
    rval = CPXgetdj (lp->cplex_env, lp->cplex_lp, rc, 0, ncols - 1);
    if (rval) {
        fprintf (stderr, "CPXgetdj failed\n"); return rval;
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CClp_pi_range (CClp *lp, double *pi, int from, int to)
#else
int CClp_pi_range (lp, pi, from, to)
CClp *lp;
double *pi;
int from, to;
#endif
{
    int rval = 0;

    rval = CPXgetpi (lp->cplex_env, lp->cplex_lp, pi, from, to);
    if (rval) {
        fprintf (stderr, "CPXgetpi failed\n"); return rval;
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CClp_objval (CClp *lp, double *obj)
#else
int CClp_objval (lp, obj)
CClp *lp;
double *obj;
#endif
{
    int rval;

    rval = CPXgetobjval (lp->cplex_env, lp->cplex_lp, obj);
    if (rval) {
        fprintf (stderr, "CPXgetobjval failed\n");
        return rval;
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CClp_nonzeros (CClp *lp)
#else
int CClp_nonzeros (lp)
CClp *lp;
#endif
{
    int k;

    k = CPXgetnumnz (lp->cplex_env, lp->cplex_lp);
    printf ("NONZEROS = %d\n", k); fflush (stdout);
    return k;
}

#ifdef CC_PROTOTYPE_ANSI
int CClp_status (CClp *lp, int *status)
#else
int CClp_status (lp, status)
CClp *lp;
int *status;
#endif
{
    int solmethod, solstat;

    solmethod = CPXgetmethod (lp->cplex_env, lp->cplex_lp);
    if (solmethod == CPXALG_PRIMAL || solmethod == CPXALG_DUAL) {
        solstat = CPXgetstat (lp->cplex_env, lp->cplex_lp);
        if (solstat == CPX_OPTIMAL || solstat == CPX_OPTIMAL_INFEAS) {
            *status = 0;
            return 0;
        } else if (solstat == CPX_UNBOUNDED && solmethod == CPXALG_DUAL) {
            *status = 1;
            return 0;
        } else {
            fprintf (stderr, "lp in an unknown state: %d %d\n",
                           solmethod, solstat);
            *status = -1;
            return 1;
        }
    } else {
        fprintf (stderr, "lp not solved by usual methods: %d\n", solmethod);
        *status = -2;
        return 1;
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CClp_getweight (CClp *lp, int nrows, int *rmatbeg, int *rmatind,
                    double *rmatval, double *weight)
#else
int CClp_getweight (lp, nrows, rmatbeg, rmatind, rmatval, weight)
CClp *lp;
int nrows;
int *rmatbeg;
int *rmatind;
double *rmatval;
double *weight;
#endif
{
    int rval = 0;

    rval = CPXgetweight (lp->cplex_env, lp->cplex_lp, nrows,
                         rmatbeg, rmatind, rmatval, weight, CPX_DPRIIND_STEEP);
    if (rval) {
        fprintf (stderr, "CPXgetweight failed\n");
    }
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CClp_dump_lp (CClp *lp, char *fname)
#else
int CClp_dump_lp (lp, fname)
CClp *lp;
char *fname;
#endif
{
    int rval = 0;

    rval = CPXlpwrite (lp->cplex_env, lp->cplex_lp, fname);
    if (rval) {
        fprintf (stderr, "CPXlpwrite failed\n");
    }
    return rval;
}

#define OURCPLEXZERO    (1.0E-10)
#define OURCPLEX_INTTOL (0.0001)

#ifdef CC_PROTOTYPE_ANSI
int CClp_getgoodlist (CClp *lp, int *goodlist, int *goodlen_p,
                      double *downpen, double *uppen)
#else
int CClp_getgoodlist (lp, goodlist, goodlen_p, downpen, uppen)
CClp *lp;
int *goodlist;
int *goodlen_p;
double *downpen;
double *uppen;
#endif
{
    int  rval = 0;
    int  ncols, i, k;
    int  *cstat = (int *) NULL;
    double *x = (double *) NULL;

    /* Call CPXdualopt and verify optimality */

    if ( CPXdualopt (lp->cplex_env, lp->cplex_lp) ) {
        fprintf (stderr, "CPXdualopt failed\n");
        rval = 1; goto CLEANUP;
    }

    ncols = CPXgetnumcols (lp->cplex_env, lp->cplex_lp);
    if ( ncols == 0 ) {
        fprintf (stderr, "No columns in LP\n");
        rval = 1; goto CLEANUP;
    }

    x = CC_SAFE_MALLOC (ncols, double);
    if (x == (double *) NULL) {
        fprintf (stderr, "out of memory in branch_getgoodlist\n");
        rval = 1; goto CLEANUP;
    }
    if (CPXgetx (lp->cplex_env, lp->cplex_lp, x, 0, ncols-1)) {
        fprintf (stderr, "CPXgetx failed\n");
        rval = 1; goto CLEANUP;
    }

    cstat = CC_SAFE_MALLOC (ncols, int);
    if ( cstat == (int *) NULL ) {
        fprintf (stderr, "Out of memory\n");
        rval = 1; goto CLEANUP;
    }

    /* Get basis */

    if ( CPXgetbase (lp->cplex_env, lp->cplex_lp, cstat, (int *) NULL) ) {
        fprintf (stderr, "CPXgetbase failed\n");
        rval = 1; goto CLEANUP;
    }

    /* Make initial goodlist and goodlen */

    *goodlen_p = 0;
    for (i = 0; i < ncols; i++) {
       if ( cstat[i] == 1 ) {
          goodlist[(*goodlen_p)++] = i;
       }
    }

    /* Call CPXmdleave */

    if ( CPXmdleave (lp->cplex_env, lp->cplex_lp, goodlist, *goodlen_p,
                     downpen, uppen)) {
       fprintf (stderr, "CPXmdleave failed\n");
       rval = 1; goto CLEANUP;
    }

    /* Keep only the nondegenerate ones */

    k = *goodlen_p;
    *goodlen_p = 0;
    for (i = 0; i < k; i++) {
       if ( CC_OURABS (downpen[i]) > OURCPLEXZERO   &&
            CC_OURABS (uppen[i])   > OURCPLEXZERO   &&
            x[goodlist[i]] >= OURCPLEX_INTTOL    &&
            x[goodlist[i]] <= 1 - OURCPLEX_INTTOL  ) {
          goodlist[*goodlen_p]  = goodlist[i];
          downpen[*goodlen_p] = x[goodlist[i]] * downpen[i];
          uppen[*goodlen_p]   = (1.0 - x[goodlist[i]]) * uppen[i];
          (*goodlen_p)++;
       }
    }

CLEANUP:

    CC_IFFREE (cstat, int);
    CC_IFFREE (x, double);
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CClp_strongbranch (CClp *lp, int *candidatelist, int ncand,
                       double *downpen, double *uppen, int iterations,
                       double *upperbound)
#else
int CClp_strongbranch (lp, candidatelist, ncand, downpen, uppen, iterations,
                       upperbound)
CClp *lp;
int *candidatelist;
int ncand;
double *downpen;
double *uppen;
int iterations;
double *upperbound;
#endif
{
    double oldupperbound;
    int rval = 0;
    int sval = 0;

    if (upperbound) {
        rval = CPXgetdblparam (lp->cplex_env, CPX_PARAM_OBJULIM,
                               &oldupperbound);
        if (rval) {
            fprintf (stderr, "CPXgetdblparam failed\n"); return rval;
        }
        rval = CPXsetdblparam (lp->cplex_env, CPX_PARAM_OBJULIM,
                               *upperbound);
        if (rval) {
            fprintf (stderr, "CPXsetdblparam failed\n"); return rval;
        }
    }

    rval = CPXstrongbranch (lp->cplex_env, lp->cplex_lp, candidatelist,
                            ncand, downpen, uppen, iterations);
    if (rval) {
        fprintf (stderr, "CPXstrongbranch failed\n");
        if (upperbound) {
            sval = CPXsetdblparam (lp->cplex_env, CPX_PARAM_OBJULIM,
                                   oldupperbound);
            if (sval) {
                fprintf (stderr,
                         "CPXsetdblparam failed with return code %d\n",
                         sval);
            }
        }
        return rval;
    }

    if (upperbound) {
        rval = CPXsetdblparam (lp->cplex_env, CPX_PARAM_OBJULIM,
                               oldupperbound);
        if (rval) {
            fprintf (stderr, "CPXsetdblparam failed\n"); return rval;
        }
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CClp_getfarkasmultipliers (CClp *lp, double *y)
#else
int CClp_getfarkasmultipliers (lp, y)
CClp *lp;
double *y;
#endif
{
    int  rval = 0;

    int  i = 0, nrows, idiv, jdiv;
    double  val, lb, ub;
    int  *bhead =  (int *) NULL;
    char  *sense = (char *) NULL;

    if ( lp->cplex_env == (struct cpxenv *) NULL ||
         lp->cplex_lp  == (struct cpxlp *)  NULL) {
        rval = 1;  fprintf (stderr, "env object or lp object is NULL\n");
        goto CLEANUP;
    }

    if ( CPXgetmethod (lp->cplex_env, lp->cplex_lp) != CPXALG_DUAL  ||
         CPXgetstat (lp->cplex_env, lp->cplex_lp )  != CPX_UNBOUNDED  ) {
        rval = 1;  fprintf (stderr, "Incorrect solution type\n");
        goto CLEANUP;
    }

    if ( CPXgetijdiv (lp->cplex_env, lp->cplex_lp, &idiv, &jdiv) ) {
        rval = 1;  fprintf (stderr, "CPXgetijdiv failed\n");
        goto CLEANUP;
    }

    if ( (jdiv == -1  &&  idiv == -1) ||
         (jdiv != -1  &&  idiv != -1)   ) {
        rval = 1;  fprintf (stderr, "CPLEX returned illegal indices\n");
        goto CLEANUP;
    }

    nrows = CPXgetnumrows (lp->cplex_env, lp->cplex_lp);
    if ( nrows == 0 ) {
        rval = 1;  fprintf (stderr, "lp->cplex_lp has no rows\n");
        goto CLEANUP;
    }

    bhead = CC_SAFE_MALLOC (nrows, int);
    sense = CC_SAFE_MALLOC (nrows, char);
    if ( bhead == (int *) NULL ||
         sense == (char *) NULL   ) {
        rval = -1;  fprintf (stderr, "Out of memory\n");
        goto CLEANUP;
    }

    if ( CPXgetbhead (lp->cplex_env, lp->cplex_lp, bhead, NULL) ) {
        rval = 1;  fprintf (stderr, "CPXgetbhead failed\n");
        goto CLEANUP;
    }

    if ( CPXgetsense (lp->cplex_env, lp->cplex_lp, sense, 0, nrows-1) ) {
        rval = 1;  fprintf (stderr, "CPXgetsense failed\n");
        goto CLEANUP;
    }

    if ( jdiv >= 0 ) {
        for (i = 0; i < nrows; i++) {
            if ( bhead[i] == jdiv )  break;
        }
        if ( i == nrows ) {
            rval = 1;  fprintf (stderr, "Basis index not found\n");
            goto CLEANUP;
        }
        if ( CPXgetx (lp->cplex_env, lp->cplex_lp, &val, jdiv, jdiv) ) {
            rval = 1;  fprintf (stderr, "CPXgetx failed\n");
            goto CLEANUP;
        }
        if ( CPXgetlb (lp->cplex_env, lp->cplex_lp, &lb, jdiv, jdiv) ) {
            rval = 1;  fprintf (stderr, "CPXgetlb failed\n");
            goto CLEANUP;
        }
        if ( CPXgetub (lp->cplex_env, lp->cplex_lp, &ub, jdiv, jdiv) ) {
            rval = 1;  fprintf (stderr, "CPXgetub failed\n");
            goto CLEANUP;
        }
    } else {
        for (i = 0; i < nrows; i++) {
            if ( bhead[i] ==  -idiv-1 )  break;
        }
        if ( i == nrows ) {
            rval = 1;  fprintf (stderr, "Basis index not found\n");
            goto CLEANUP;
        }
        if ( CPXgetslack (lp->cplex_env, lp->cplex_lp, &val, idiv, idiv) ) {
            rval = 1;  fprintf (stderr, "CPXgetslack failed\n");
            goto CLEANUP;
        }
        lb = 0.0;
        if ( sense[idiv] == 'E' )  ub = 0.0;
        else                       ub = INFBOUND;
        if ( sense[idiv] == 'G' )  val *= -1.0;
    }

    if ( CPXbinvrow (lp->cplex_env, lp->cplex_lp, i, y) ) {
        rval = 1;  fprintf (stderr, "CPXbinvrow failed\n");
        goto CLEANUP;
    }

    if ( val < lb ) {
        for (i = 0; i < nrows; i++)  y[i] *= -1.0;
    }

    for (i = 0; i < nrows; i++) {
        if ( sense[i] == 'L'  &&  y[i] > 0.0 )  y[i] = 0.0;
        if ( sense[i] == 'G'  &&  y[i] < 0.0 )  y[i] = 0.0;
    }

CLEANUP:

    CC_IFFREE (bhead, int);
    CC_IFFREE (sense, char);

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
void CClp_pivotin (CClp *lp, int i)
#else
void CClp_pivotin (lp, i)
CClp *lp;
int i;
#endif
{
    int locali = i;

    if ( CPXpivotin (lp->cplex_env, lp->cplex_lp, &locali, 1) ) {
        fprintf (stderr, "CPXpivotin failed, continuing anyway\n");
    }
}

