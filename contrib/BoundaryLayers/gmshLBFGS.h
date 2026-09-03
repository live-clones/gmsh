// Gmsh Boundary Layer Plugin - Copyright (C) 2026 C. Geuzaine and J.-F. Remacle
//
// This program is free software: you can redistribute it and/or modify it under
// the terms of the GNU Affero General Public License as published by the Free
// Software Foundation, either version 3 of the License, or (at your option) any
// later version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more
// details.
//
// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <functional>
#include <vector>

namespace GmshLBFGS {

  struct Options {
    int maxIterations = 300;
    int memory = 15;
    double gradientTolerance = 1.e-4;
    double functionTolerance = 1.e-12;
    double stepTolerance = 1.e-12;
    double initialStep = 1.;
    double maxStepNorm = 1.;
    double armijo = 1.e-4;
    double backtrackingFactor = 0.5;
    int maxLineSearchSteps = 20;
    int verbose = 0;
    int numThreads = 1;
    std::function<void(int iter, double f, double gradNorm, double step)>
      iterationCallback;
  };

  struct Result {
    bool converged = false;
    int iterations = 0;
    int functionEvaluations = 0;
    double initialValue = 0.;
    double finalValue = 0.;
    double gradientNorm = 0.;
    double timeTotal = 0.;
    double timeFunction = 0.;
    double timeDirection = 0.;
    double timeLineSearch = 0.;
    double timeUpdate = 0.;
    int terminationType = 0;
  };

  using FunctionGradient =
    std::function<double(const std::vector<double> &x, std::vector<double> &g)>;

  Result minimize(std::vector<double> &x, const FunctionGradient &fg,
                  const Options &options = Options());

} // namespace GmshLBFGS
