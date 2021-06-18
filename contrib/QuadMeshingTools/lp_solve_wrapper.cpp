// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#include "lp_solve_wrapper.h"

#include <string>
#include <sstream>
#include <iostream>
#include "gmsh.h"

#include "GmshConfig.h"
#include "GmshMessage.h"

//#if defined(HAVE_LP_SOLVE)
#include "lp_lib.h"
//#endif

namespace lp_solve {
//#if defined(HAVE_LP_SOLVE)
  LpSolveSolver::LpSolveSolver(int nvars) {
    lprec* lp = make_lp(0,nvars);
    if (lp == NULL) {
      Msg::Error("Unable to create new lp_solver");
      return;
    }
    set_add_rowmode(lp, TRUE);
    state = static_cast<void*>(lp);
  }

  LpSolveSolver::~LpSolveSolver() {
    if (state != NULL) {
      lprec* lp = static_cast<lprec*>(state);
      delete_lp(lp);
      state = NULL;
    }
  }

  bool LpSolveSolver::setBounds(int i, int boundMin, int boundMax) {
    lprec* lp = static_cast<lprec*>(state);
    if (lp == NULL) return false;
    unsigned char r = set_bounds(lp,i+1,boundMin,boundMax);
    return (r == TRUE);
  }

  bool LpSolveSolver::setInteger(int i) {
    lprec* lp = static_cast<lprec*>(state);
    if (lp == NULL) return false;
    unsigned char r = set_int(lp, i+1, TRUE);
    return (r == TRUE);
  }

  bool LpSolveSolver::setBasisUpperBound() {
    lprec* lp = static_cast<lprec*>(state);
    if (lp == NULL) return false;
    int nrows = get_Nrows(lp);
    std::vector<int> basis(1+nrows,0);
    for (size_t i = 0; i < basis.size(); ++i) basis[i] = i;
    unsigned char r = set_basis(lp, basis.data(), FALSE);
    return (r == TRUE);
  }

  bool LpSolveSolver::addConstraintRow(const std::vector<std::pair<int,double> >& column_value, int op, double rhs) {
    lprec* lp = static_cast<lprec*>(state);
    if (lp == NULL) return false;
    std::vector<int> colno(column_value.size());
    std::vector<double> sparserow(column_value.size());
    for (size_t i = 0; i < column_value.size(); ++i) {
      colno[i] = column_value[i].first + 1;
      sparserow[i] = column_value[i].second;
    }
    set_add_rowmode(lp, TRUE);
    unsigned char r = add_constraintex(lp,(int)colno.size(),sparserow.data(),colno.data(), op, rhs);
    return (r == TRUE);
  }

  bool LpSolveSolver::setObjectiveFunction(const std::vector<std::pair<int,double> >& column_value, bool minimize) {
    lprec* lp = static_cast<lprec*>(state);
    if (lp == NULL) return false;
    std::vector<int> colno(column_value.size());
    std::vector<double> sparserow(column_value.size());
    for (size_t i = 0; i < column_value.size(); ++i) {
      colno[i] = column_value[i].first + 1;
      sparserow[i] = column_value[i].second;
    }
    set_add_rowmode(lp, FALSE);
    unsigned char r = set_obj_fnex(lp,(int)colno.size(),sparserow.data(),colno.data());

    if (minimize) {
      set_minim(lp);
    } else {
      set_maxim(lp);
    }

    return (r == TRUE);
  }

  bool LpSolveSolver::lpSolve(std::vector<double>& slt) {
    lprec* lp = static_cast<lprec*>(state);
    if (lp == NULL) return false;

    write_LP(lp, stdout);
    set_verbose(lp, IMPORTANT);

    int ret = solve(lp);
    if (ret == OPTIMAL) {
      double mv = get_objective(lp);
      Msg::Info("lp_solve: solution found, energy = %f", mv);

      slt.resize(lp->columns,0.);
      get_variables(lp, slt.data());
      return true;
    } else if (ret == SUBOPTIMAL) {
      double mv = get_objective(lp);
      Msg::Warning("lp_solve: solution found but sub-optimal, energy = %f", mv);

      slt.resize(lp->columns,0.);
      get_variables(lp, slt.data());
      return true;
    } else {
      Msg::Warning("lp_solve: optimal solution not found");
    }
    return false;
  }

//#endif
}

