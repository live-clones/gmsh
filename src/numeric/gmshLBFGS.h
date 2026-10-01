// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
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
  using Function = std::function<double(const std::vector<double> &x)>;

  Result minimize(std::vector<double> &x, const FunctionGradient &fg,
                  const Options &options = Options());
  Result minimize(std::vector<double> &x, const FunctionGradient &fg,
                  const Function &f, const Options &options = Options());

  // ALGLIB-style interface with standard containers. This uses the same
  // L-BFGS/Armijo solver as minimize(), not ALGLIB's line search.
  // Invalid arguments throw std::invalid_argument. Invalid initial values or
  // gradient sizes throw std::runtime_error; nonfinite trial values reject the
  // trial step. User exceptions propagate unchanged.
  using GradientCallback = std::function<void(
    const std::vector<double> &x, double &f, std::vector<double> &g, void *ptr)>;
  using ReportCallback =
    std::function<void(const std::vector<double> &x, double f, void *ptr)>;

  struct Report {
    int iterationscount = 0;
    int nfev = 0;
    // 0: not run; -2: line search failed; 1: function tolerance;
    // 2: step tolerance; 4: gradient tolerance; 5: iteration limit.
    int terminationtype = 0;
  };

  // Initialize and configure the state with the functions below.
  struct State {
    std::vector<double> x;
    Options options;
    Result result;
    bool xrep = false;
    std::vector<double> scale;
    bool scalePreconditioner = false;
  };

  // Copy the first n entries of x; require n > 0 and 1 <= m <= n.
  // Defaults: epsg = epsf = 0, epsx = 1e-6, unlimited iterations/step length.
  void create(int n, int m, const std::vector<double> &x, State &state);
  void create(int m, const std::vector<double> &x, State &state);

  // Stop on |g| <= epsg, |fOld-f| <= epsf*max(1, |fOld|, |f|), or
  // |xNew-xOld| <= epsx. maxits = 0 means unlimited iterations.
  // If all four parameters are zero, epsx is set to 1e-6.
  void setCond(State &state, double epsg, double epsf, double epsx, int maxits);
  // Enable reports at the initial point and after each accepted step.
  void setXRep(State &state, bool needxrep);
  // Limit the Euclidean step length; zero (the default) means no limit.
  void setStpMax(State &state, double stpmax);
  // Use |g[i]*scale[i]| and |dx[i]/scale[i]| in stopping criteria.
  // Scales must be finite and nonzero; their signs are ignored.
  void setScale(State &state, const std::vector<double> &scale);
  // Use diag(scale[i]^2) as the initial inverse Hessian approximation.
  void setPrecScale(State &state);
  // Keep settings and dimension, copy a new starting point and reset results.
  void restartFrom(State &state, const std::vector<double> &x);

  // The gradient vector is pre-sized. rep is called only when xrep is enabled.
  void optimize(State &state, const GradientCallback &grad,
                const ReportCallback &rep = ReportCallback(),
                void *ptr = nullptr);
  void results(const State &state, std::vector<double> &x, Report &rep);

} // namespace GmshLBFGS
