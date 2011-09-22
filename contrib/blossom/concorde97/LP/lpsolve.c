/***************************************************************************/
/*                                                                         */
/*              Interface Routines to an LP Solver                         */
/*                                                                         */
/*                                                                         */
/*                                                                         */
/*  NOTE: These are just dummy routines. To make use of the LP-based       */
/*   portion of concorde you will need to write an interface between these */
/*   routines and an LP solve. To use the CPLEX 4.1 library, the code in   */
/*   lpcplex.c can be used instead of this file.                           */
/*                                                                         */
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


#ifdef CC_PROTOTYPE_ANSI

static void
    lp_message (void);

#else

static void
    lp_message ();

#endif


#ifdef CC_PROTOTYPE_ANSI
static void lp_message (void)
#else
static void lp_message ()
#endif
{
    fprintf (stderr, "need to link an lp solver to use this function\n");
}

#ifdef CC_PROTOTYPE_ANSI
void CClp_init_struct (CClp *lp)
#else
void CClp_init_struct (lp)
CClp *lp;
#endif
{
    if (lp) lp_message ();
}

#ifdef CC_PROTOTYPE_ANSI
int CClp_init (CClp *lp)
#else
int CClp_init (lp)
CClp *lp;
#endif
{
    if (lp) {
        lp_message (); return 1;
    } else {
        return 0;
    }
}

#ifdef CC_PROTOTYPE_ANSI
void CClp_free (CClp *lp)
#else
void CClp_free (lp)
CClp *lp;
#endif
{
    if (lp) lp_message ();
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
    if (lp || name || ncols || nrows || objsense || obj || rhs || sense
           || matbeg || matcnt || matind || matval || lb || ub) {
        lp_message (); return 1;
    } else {
        return 0;
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CClp_opt (CClp *lp, int method)
#else
int CClp_opt (lp, method)
CClp *lp;
int method;
#endif
{
    if (lp || method) {
        lp_message (); return 1;
    } else {
        return 0;
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CClp_dualopt (CClp *lp)
#else
int CClp_dualopt (lp)
CClp *lp;
#endif
{
    if (lp) {
        lp_message (); return 1;
    } else {
        return 0;
    }
}

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
    if (lp || iterationlim || status || objupperlim) {
        lp_message (); return 1;
    } else {
        return 0;
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CClp_primalopt (CClp *lp)
#else
int CClp_primalopt (lp)
CClp *lp;
#endif
{
    if (lp) {
        lp_message (); return 1;
    } else {
        return 0;
    }
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
    if (lp || newrows || newnz || rhs || sense || rmatbeg || rmatind
           || rmatval) {
        lp_message (); return 1;
    } else {
        return 0;
    }
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
    if (lp || newcols || newnz || obj || cmatbeg || cmatind || cmatval
           || lb || ub) {
        lp_message (); return 1;
    } else {
        return 0;
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CClp_delete_row (CClp *lp, int i)
#else
int CClp_delete_row (lp, i)
CClp *lp;
int i;
#endif
{
    if (lp || i) {
        lp_message (); return 1;
    } else {
        return 0;
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CClp_delete_set_of_rows (CClp *lp, int *delstat)
#else
int CClp_delete_set_of_rows (lp, delstat)
CClp *lp;
int *delstat;
#endif
{
    if (lp || delstat) {
        lp_message (); return 1;
    } else {
        return 0;
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CClp_delete_column (CClp *lp, int i)
#else
int CClp_delete_column (lp, i)
CClp *lp;
int i;
#endif
{
    if (lp || i) {
        lp_message (); return 1;
    } else {
        return 0;
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CClp_delete_set_of_columns (CClp *lp, int *delstat)
#else
int CClp_delete_set_of_columns (lp, delstat)
CClp *lp;
int *delstat;
#endif
{
    if (lp || delstat) {
        lp_message (); return 1;
    } else {
        return 0;
    }
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
    if (lp || col || lower_or_upper || bnd) {
        lp_message (); return 1;
    } else {
        return 0;
    }
}

#ifdef CC_PROTOTYPE_ANSI
void CClp_init_basis (CClpbasis *b)
#else
void CClp_init_basis (b)
CClpbasis *b;
#endif
{
    if (b) lp_message ();
}

#ifdef CC_PROTOTYPE_ANSI
void CClp_free_basis (CClpbasis *b)
#else
void CClp_free_basis (b)
CClpbasis *b;
#endif
{
    if (b) lp_message ();
}

#ifdef CC_PROTOTYPE_ANSI
int CClp_get_basis_and_norms (CClp *lp, CClpbasis *b)
#else
int CClp_get_basis_and_norms (lp, b)
CClp *lp;
CClpbasis *b;
#endif
{
    if (lp || b) {
        lp_message (); return 1;
    } else {
        return 0;
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CClp_load_basis_and_norms (CClp *lp, CClpbasis *b)
#else
int CClp_load_basis_and_norms (lp, b)
CClp *lp;
CClpbasis *b;
#endif
{
    if (lp || b) {
        lp_message (); return 1;
    } else {
        return 0;
    }
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
    if (lp || cstat || rstat) {
        lp_message (); return 1;
    } else {
        return 0;
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CClp_loadbasis (CClp *lp, int *cstat, int *rstat)
#else
int CClp_loadbasis (lp, cstat, rstat)
CClp *lp;
int *cstat, *rstat;
#endif
{
    if (lp || cstat || rstat) {
        lp_message (); return 1;
    } else {
        return 0;
    }
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
    if (lp || cstat || rstat || dnorm) {
        lp_message (); return 1;
    } else {
        return 0;
    }
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
    if (lp || cstat || rstat || dnorm) {
        lp_message (); return 1;
    } else {
        return 0;
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CClp_x (CClp *lp, double *x)
#else
int CClp_x (lp, x)
CClp *lp;
double *x;
#endif
{
    if (lp || x) {
        lp_message (); return 1;
    } else {
        return 0;
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CClp_rc (CClp *lp, double *rc)
#else
int CClp_rc (lp, rc)
CClp *lp;
double *rc;
#endif
{
    if (lp || rc) {
        lp_message (); return 1;
    } else {
        return 0;
    }
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
    if (lp || pi || from || to) {
        lp_message (); return 1;
    } else {
        return 0;
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CClp_objval (CClp *lp, double *obj)
#else
int CClp_objval (lp, obj)
CClp *lp;
double *obj;
#endif
{
    if (lp || obj) {
        lp_message (); return 1;
    } else {
        return 0;
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CClp_nonzeros (CClp *lp)
#else
int CClp_nonzeros (lp)
CClp *lp;
#endif
{
    if (lp) {
        lp_message (); return 1;
    } else {
        return 0;
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CClp_status (CClp *lp, int *status)
#else
int CClp_status (lp, status)
CClp *lp;
int *status;
#endif
{
    if (lp || status) {
        lp_message (); return 1;
    } else {
        return 0;
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
    if (lp || nrows || rmatbeg || rmatind || rmatval || weight) {
        lp_message (); return 1;
    } else {
        return 0;
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CClp_dump_lp (CClp *lp, char *fname)
#else
int CClp_dump_lp (lp, fname)
CClp *lp;
char *fname;
#endif
{
    if (lp || fname ) {
        lp_message (); return 1;
    } else {
        return 0;
    }
}

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
    if (lp || goodlist || goodlen_p || downpen || uppen) {
        lp_message (); return 1;
    } else {
        return 0;
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CClp_strongbranch (CClp *lp, int *candidatelist, int ncand,
        double *downpen, double *uppen, int iterations, double *upperbound)
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
    if (lp || candidatelist || ncand || downpen || uppen || iterations
           || upperbound) {
        lp_message (); return 1;
    } else {
        return 0;
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CClp_getfarkasmultipliers (CClp *lp, double *y)
#else
int CClp_getfarkasmultipliers (lp, y)
CClp *lp;
double *y;
#endif
{
    if (lp || y) {
        lp_message (); return 1;
    } else {
        return 0;
    }
}

#ifdef CC_PROTOTYPE_ANSI
void CClp_pivotin (CClp *lp, int i)
#else
void CClp_pivotin (lp, i)
CClp *lp;
int i;
#endif
{
    if (lp || i) lp_message ();
}
