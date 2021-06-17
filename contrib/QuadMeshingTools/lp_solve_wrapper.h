// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#pragma once
#include <vector>

namespace lp_solve {

  const int LPS_LE = 1; /* <= */
  const int LPS_GE = 2; /* >= */
  const int LPS_EQ = 3; /* =  */

  class LpSolveSolver {
    public:
      LpSolveSolver(int nvars);
      ~LpSolveSolver();
      bool setBounds(int i, int boundMin, int boundMax);
      bool addConstraintRow(const std::vector<std::pair<int,double> >& column_value, int op, double rhs);
      bool setObjectiveFunction(const std::vector<std::pair<int,double> >& column_value, bool minimize = true);
      bool lpSolve(std::vector<double>& slt);

    private:
      void* state;

  };

}
