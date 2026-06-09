// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

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
