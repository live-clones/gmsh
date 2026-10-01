// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#pragma once

#include <functional>
#include <vector>

// Limited-memory BFGS minimization with a backtracking Armijo line search.

namespace LBFGS {

  struct Options {
    // Number of corrections kept, clamped to the number of variables.
    int memory = 15;
    // Stop after maxIterations accepted steps; 0 means unlimited.
    int maxIterations = 300;
    // Stop on |g| <= gradientTolerance, on
    // |fOld - f| <= functionTolerance * max(1, |fOld|, |f|), or on
    // |xNew - xOld| <= stepTolerance; zero disables a test.
    double gradientTolerance = 1.e-4;
    double functionTolerance = 1.e-12;
    double stepTolerance = 1.e-12;
    // Limit the Euclidean length of a step; 0 means no limit.
    double maxStepNorm = 1.;
    double initialStep = 1.;
    double armijo = 1.e-4;
    double backtrackingFactor = 0.5;
    int maxLineSearchSteps = 20;
    // If not empty, use |g[i] * scale[i]| and |dx[i] / scale[i]| in the
    // stopping tests; scales must be finite and nonzero, signs are ignored.
    std::vector<double> scale;
    // Use diag(scale[i]^2) as the initial inverse Hessian approximation.
    bool scalePreconditioner = false;
    int verbose = 0;
    // Called at the starting point (iteration 0, step 0) and after each
    // accepted step.
    std::function<void(int iter, const std::vector<double> &x, double f,
                       double gradNorm, double step)>
      progress;
  };

  struct Result {
    bool converged = false;
    int iterations = 0;
    int functionEvaluations = 0;
    double initialValue = 0.;
    double finalValue = 0.;
    double gradientNorm = 0.;
    // 1: function tolerance; 2: step tolerance; 4: gradient tolerance;
    // 5: iteration limit; -2: line search failed.
    int terminationType = 0;
    double timeTotal = 0.;
    double timeFunction = 0.;
    double timeDirection = 0.;
    double timeLineSearch = 0.;
    double timeUpdate = 0.;
  };

  // Return f(x) and fill the pre-sized gradient g.
  using FunctionGradient =
    std::function<double(const std::vector<double> &x, std::vector<double> &g)>;

  // Minimize from x, which is overwritten with the solution. Invalid options or
  // starting point throw std::invalid_argument; a non-finite initial value or a
  // gradient of the wrong size throws std::runtime_error. Non-finite values at
  // trial points reject the step. Exceptions from fg propagate unchanged.
  Result minimize(std::vector<double> &x, const FunctionGradient &fg,
                  const Options &options = Options());

} // namespace LBFGS
