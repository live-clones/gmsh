// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#include "qmt_linalg_solver.h"
#include "qmt_utils.hpp"
#include "qmt_types.hpp"

#include <string>
#include <sstream>
#include <iostream>
#include "gmsh.h"

#include "GmshConfig.h"

#if defined(HAVE_SOLVER)

#include "linearSystemGmm.h"
#include "linearSystemCSR.h"
#include "linearSystemFull.h"
#include "linearSystemPETSc.h"
#include "linearSystemMUMPS.h"

#endif

/* - Shortcuts for loops */
#define F(_VAR,_NB) for(size_t _VAR = 0; _VAR < (size_t) _NB; ++_VAR)
#define FC(_VAR,_NB,_COND) for(size_t _VAR = 0; _VAR < (size_t) _NB; ++_VAR) if (_COND)

namespace QMT_LA_Utils {
  using namespace QMT;
  using namespace QMT_Utils;
  /************************************/
  /* Formatting and Logging functions */
  template <typename... Args>
    void error(const char* format, const Args & ... args) {
      std::ostringstream stream;
      sformat(stream, format, args...);
      gmsh::logger::write("QMT | Solver | " + stream.str(), "error");
    }

  template <typename... Args>
    void warn(const char* format, const Args & ... args) {
      std::ostringstream stream;
      sformat(stream, format, args...);
      gmsh::logger::write("QMT | Solver | " + stream.str(), "warning");
    }

  template <typename... Args>
    void info(const char* format, const Args & ... args) {
      std::ostringstream stream;
      sformat(stream, format, args...);
      gmsh::logger::write("QMT | Solver | " + stream.str(), "info");
    }
  /************************************/
}



namespace QMT {
  using namespace QMT_Utils;
  using namespace QMT_LA_Utils;

#if defined(HAVE_SOLVER)
  bool solve_sparse_linear_system_impl(
      const std::vector<std::vector<size_t>>& columns,
      const std::vector<std::vector<double>>& values,
      const std::vector<double>& rhs,
      std::vector<double>& x) {
    size_t nb_rows = columns.size();
#if defined(HAVE_PETSC)
    linearSystemPETSc<double> *_lsys = new linearSystemPETSc<double>;
#elif defined(HAVE_MUMPS)
    linearSystemMUMPS<double> *_lsys = new linearSystemMUMPS<double>;
#elif defined(HAVE_GMM)
    linearSystemGmm<double> *_lsys = new linearSystemGmm<double>;
#else
    warn("using solver Full (very slow ?)");
    linearSystemFull<double> *_lsys = new linearSystemFull<double>;
#endif

    _lsys->allocate(nb_rows);
    F(i,columns.size()) {
      if (columns[i].size() != values[i].size()) {
        error("invalid row {}: columns[i].size(), values[i].size()", i, columns[i].size(), values[i].size());
        return false;
      }
      F(j,columns[i].size()) {
        _lsys->addToMatrix(i, columns[i][j], values[i][j]);
      }
    }
    F(i, rhs.size()) {
      _lsys->addToRightHandSide(i, rhs[i]);
    }

    int ok = _lsys->systemSolve();
    if (!ok) {
      error("systemSolve() failed");
      return false;
    }
    F(i,x.size()) {
      _lsys->getFromSolution(i, x[i]);
    }

    return true;
  }
#endif

  bool solve_sparse_linear_system(
      const std::vector<std::vector<size_t>>& columns,
      const std::vector<std::vector<double>>& values,
      const std::vector<double>& rhs,
      std::vector<double>& x) {
    if (columns.size() == 0 || columns.size() != values.size() || columns.size() != rhs.size() || columns.size() != x.size()) {
      error("wrong input size: columns.size() = {}, values.size() = {}, rhs.size() = {}, x.size() = {}",
          columns.size(),values.size(),rhs.size(),x.size());
      return false;
    }
#if defined(HAVE_SOLVER)
    return solve_sparse_linear_system_impl(columns, values, rhs, x);
#else
    error("SOLVER module required");
    return false;
#endif
  }

  struct LS_state {
#if defined(HAVE_PETSC)
    linearSystemPETSc<double> *sys = new linearSystemPETSc<double>;
#elif defined(HAVE_MUMPS)
    linearSystemMUMPS<double> *sys = new linearSystemMUMPS<double>;
#elif defined(HAVE_GMM)
    linearSystemCSRGmm<double> *sys = new linearSystemCSRGmm<double>;
#else
    linearSystemFull<double> *sys = new linearSystemFull<double>;
#endif
    size_t nb_rows = 0;
  };

  bool create_linear_system(size_t nb_rows, void** data) {
#if defined(HAVE_SOLVER)
    LS_state *state = new LS_state;
    state->sys->allocate(nb_rows);
    state->nb_rows = nb_rows;
    *data = state;
#if defined(HAVE_PETSC)
    info("using PETSc");
#elif defined(HAVE_MUMPS)
    info("using MUMPS (direct)");
#elif defined(HAVE_GMM)
    info("using Gmm (iterative)");
#else
    info("using Full");
#endif
    return true;
#else
    error("module SOLVER required");
    return false;
#endif
  }

  bool destroy_linear_system(void** data) {
    if (*data == NULL) return false;
    LS_state* state = (LS_state*) (*data);
    delete state;
    *data = NULL;
    return true;
  }

  bool add_sparse_coefficients(
      const std::vector<std::vector<size_t>>& columns,
      const std::vector<std::vector<double>>& values,
      void* data) {
    LS_state* state = (LS_state*) (data);
    F(i,columns.size()) {
      F(j,columns[i].size()) {
        state->sys->addToMatrix(i, columns[i][j], values[i][j]);
      }
    }
    return true;
  }

  bool set_rhs_values(
      const std::vector<double>& rhs,
      void* data) {
    LS_state* state = (LS_state*) (data);
    state->sys->zeroRightHandSide();
    F(i, rhs.size()) {
      state->sys->addToRightHandSide(i, rhs[i]);
    }
    return true;
  }

  bool solve(std::vector<double>& x, void* data) {
    LS_state* state = (LS_state*) (data);
    // // print matrix
    // F(i,state->nb_rows) F(j,state->nb_rows) {
    //   double coef = 0.;
    //   state->sys->getFromMatrix(i,j,coef);
    //   if (coef != 0.) {
    //     info("{} {} = {}", i, j, coef);
    //   }
    // }

    int ok = state->sys->systemSolve();
    if (!ok) {
      error("systemSolve() failed");
      return false;
    }
    F(i,x.size()) {
      state->sys->getFromSolution(i, x[i]);
    }
    return true;
  }

}
