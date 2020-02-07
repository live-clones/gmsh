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
    // info("solver: PETSc");
    linearSystemPETSc<double> *_lsys = new linearSystemPETSc<double>;
#elif defined(HAVE_GMM)
    // info("solver: Gmm (mumps ?)");
    linearSystemGmm<double> *_lsys = new linearSystemGmm<double>;
#else
    // info("solver: Full");
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


}
