// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "LBFGS.h"

#include "GmshConfig.h"
#include "GmshMessage.h"
#include "OS.h"

#include <algorithm>
#include <cmath>
#include <limits>
#include <stdexcept>

#if defined(HAVE_EIGEN)
#include <Eigen/Dense>
#endif

#if !defined(F77NAME)
#define F77NAME(x) (x##_)
#endif

#if defined(HAVE_BLAS)
extern "C" {
double F77NAME(ddot)(int *n, double *x, int *incx, double *y, int *incy);
void F77NAME(daxpy)(int *n, double *alpha, double *x, int *incx, double *y,
                    int *incy);
void F77NAME(dcopy)(int *n, double *x, int *incx, double *y, int *incy);
void F77NAME(dscal)(int *n, double *alpha, double *x, int *incx);
}
#endif

namespace LBFGS {
  namespace {
#if defined(HAVE_BLAS)
    static int blasSize(size_t n)
    {
      return (n > (size_t)std::numeric_limits<int>::max()) ?
               std::numeric_limits<int>::max() :
               (int)n;
    }
#elif defined(HAVE_EIGEN)
    typedef Eigen::Map<Eigen::VectorXd> EigenVec;
    typedef Eigen::Map<const Eigen::VectorXd> ConstEigenVec;
#endif

    static double dot(const std::vector<double> &a,
                      const std::vector<double> &b)
    {
#if defined(HAVE_BLAS)
      int n = blasSize(a.size()), inc = 1;
      return F77NAME(ddot)(&n, const_cast<double *>(a.data()), &inc,
                           const_cast<double *>(b.data()), &inc);
#elif defined(HAVE_EIGEN)
      return ConstEigenVec(a.data(), a.size())
        .dot(ConstEigenVec(b.data(), b.size()));
#else
      double val = 0.0;
      for(size_t i = 0; i < a.size(); ++i) val += a[i] * b[i];
      return val;
#endif
    }

    static double norm(const std::vector<double> &a)
    { return std::sqrt(dot(a, a)); }

    static double scaledNorm(const std::vector<double> &a,
                             const std::vector<double> &s, bool inverse = false)
    {
      if(s.empty()) return norm(a);
      double squaredNorm = 0.;
      for(size_t i = 0; i < a.size(); ++i) {
        double value = inverse ? a[i] / s[i] : a[i] * s[i];
        squaredNorm += value * value;
      }
      return std::sqrt(squaredNorm);
    }

    static void axpy(double a, const std::vector<double> &x,
                     std::vector<double> &y)
    {
#if defined(HAVE_BLAS)
      int n = blasSize(x.size()), inc = 1;
      F77NAME(daxpy)(&n, &a, const_cast<double *>(x.data()), &inc, y.data(),
                     &inc);
#elif defined(HAVE_EIGEN)
      EigenVec(y.data(), y.size()) += a * ConstEigenVec(x.data(), x.size());
#else
      for(size_t i = 0; i < x.size(); ++i) y[i] += a * x[i];
#endif
    }

    static void assignDifference(const std::vector<double> &a,
                                 const std::vector<double> &b,
                                 std::vector<double> &out)
    {
      out.resize(a.size());
#if defined(HAVE_BLAS)
      int n = blasSize(a.size()), inc = 1;
      double minusOne = -1.;
      F77NAME(dcopy)(&n, const_cast<double *>(a.data()), &inc, out.data(),
                     &inc);
      F77NAME(daxpy)(&n, &minusOne, const_cast<double *>(b.data()), &inc,
                     out.data(), &inc);
#elif defined(HAVE_EIGEN)
      EigenVec(out.data(), out.size()) =
        ConstEigenVec(a.data(), a.size()) - ConstEigenVec(b.data(), b.size());
#else
      for(size_t i = 0; i < a.size(); ++i) out[i] = a[i] - b[i];
#endif
    }

    static void assignStep(const std::vector<double> &x,
                           const std::vector<double> &direction, double step,
                           std::vector<double> &out)
    {
      out.resize(x.size());
#if defined(HAVE_BLAS)
      int n = blasSize(x.size()), inc = 1;
      F77NAME(dcopy)(&n, const_cast<double *>(x.data()), &inc, out.data(),
                     &inc);
      F77NAME(daxpy)(&n, &step, const_cast<double *>(direction.data()), &inc,
                     out.data(), &inc);
#elif defined(HAVE_EIGEN)
      EigenVec(out.data(), out.size()) =
        ConstEigenVec(x.data(), x.size()) +
        step * ConstEigenVec(direction.data(), direction.size());
#else
      for(size_t i = 0; i < x.size(); ++i) out[i] = x[i] + step * direction[i];
#endif
    }

    static void assignScaled(const std::vector<double> &x, double scale,
                             std::vector<double> &out)
    {
      out.resize(x.size());
#if defined(HAVE_BLAS)
      int n = blasSize(x.size()), inc = 1;
      F77NAME(dcopy)(&n, const_cast<double *>(x.data()), &inc, out.data(),
                     &inc);
      F77NAME(dscal)(&n, &scale, out.data(), &inc);
#elif defined(HAVE_EIGEN)
      EigenVec(out.data(), out.size()) =
        scale * ConstEigenVec(x.data(), x.size());
#else
      for(size_t i = 0; i < x.size(); ++i) out[i] = scale * x[i];
#endif
    }

    static void scale(std::vector<double> &x, double scale)
    {
#if defined(HAVE_BLAS)
      int n = blasSize(x.size()), inc = 1;
      F77NAME(dscal)(&n, &scale, x.data(), &inc);
#elif defined(HAVE_EIGEN)
      EigenVec(x.data(), x.size()) *= scale;
#else
      for(size_t i = 0; i < x.size(); ++i) x[i] *= scale;
#endif
    }

    bool isFinite(const std::vector<double> &v)
    {
      return std::all_of(v.begin(), v.end(),
                         [](double value) { return std::isfinite(value); });
    }

    bool validTolerance(double value)
    { return std::isfinite(value) && value >= 0.; }

    void checkArguments(const std::vector<double> &x,
                        const FunctionGradient &fg, const Options &options)
    {
      if(!fg) throw std::invalid_argument("LBFGS: no function given");
      if(x.empty() || !isFinite(x))
        throw std::invalid_argument(
          "LBFGS: starting point is empty or not finite");
      if(options.memory < 1 || options.maxIterations < 0 ||
         options.maxLineSearchSteps < 1)
        throw std::invalid_argument("LBFGS: require memory >= 1, "
                                    "maxIterations >= 0 and "
                                    "maxLineSearchSteps >= 1");
      if(!validTolerance(options.gradientTolerance) ||
         !validTolerance(options.functionTolerance) ||
         !validTolerance(options.stepTolerance) ||
         !validTolerance(options.maxStepNorm))
        throw std::invalid_argument(
          "LBFGS: tolerances and maximum step must be finite and nonnegative");
      if(!options.scale.empty()) {
        if(options.scale.size() != x.size())
          throw std::invalid_argument("LBFGS: scale has the wrong size");
        for(double value : options.scale) {
          if(!std::isfinite(value) || value == 0.)
            throw std::invalid_argument(
              "LBFGS: scales must be finite and nonzero");
        }
      }
    }
  } // namespace

  Result minimize(std::vector<double> &x, const FunctionGradient &fg,
                  const Options &options)
  {
    checkArguments(x, fg, options);

    Result result;
    const size_t n = x.size();
    const int memory = (int)std::min<size_t>(options.memory, n);
    std::vector<double> variableScale(options.scale);
    for(double &value : variableScale) value = std::abs(value);
    const bool scalePreconditioner =
      options.scalePreconditioner && !variableScale.empty();

    // Evaluate f and g; a non-finite value at a trial point returns +inf,
    // which the line search rejects.
    auto evaluate = [&](const std::vector<double> &xe, std::vector<double> &ge,
                        bool initial) {
      double f = fg(xe, ge);
      if(ge.size() != xe.size())
        throw std::runtime_error("LBFGS: gradient has the wrong size");
      if(!std::isfinite(f) || !isFinite(ge)) {
        if(initial)
          throw std::runtime_error(
            "LBFGS: initial function or gradient is not finite");
        return std::numeric_limits<double>::infinity();
      }
      return f;
    };

    std::vector<double> g(n), gNew(n), xNew(n), direction(n), q(n), s(n), y(n);
    std::vector<std::vector<double>> sList, yList;
    std::vector<double> rhoList, alpha;
    sList.reserve(memory);
    yList.reserve(memory);
    rhoList.reserve(memory);
    alpha.resize(memory);

    const double tTotal = TimeOfDay();
    double t = TimeOfDay();
    double f = evaluate(x, g, true);
    result.timeFunction += TimeOfDay() - t;
    result.functionEvaluations++;
    result.initialValue = f;
    if(options.progress)
      options.progress(0, x, f, scaledNorm(g, variableScale), 0.);

    for(int iter = 0;
        options.maxIterations == 0 || iter < options.maxIterations; ++iter) {
      result.iterations = iter;
      result.gradientNorm = scaledNorm(g, variableScale);
      if(options.verbose) {
        Msg::Info("LBFGS iter %d: f %.16g, |g| %.6g", iter, f,
                  result.gradientNorm);
      }
      if(result.gradientNorm <= options.gradientTolerance) {
        result.converged = true;
        result.terminationType = 4;
        if(options.verbose) Msg::Info("LBFGS converged on gradient tolerance");
        break;
      }

      t = TimeOfDay();
      q = g;
      const int hist = (int)sList.size();
      for(int i = hist - 1; i >= 0; --i) {
        alpha[i] = rhoList[i] * dot(sList[i], q);
        axpy(-alpha[i], yList[i], q);
      }

      double gamma = 1.;
      if(hist > 0) {
        const double ys = dot(yList.back(), sList.back());
        double yy = dot(yList.back(), yList.back());
        if(scalePreconditioner) {
          double ynorm = scaledNorm(yList.back(), variableScale);
          yy = ynorm * ynorm;
        }
        if(yy > 0.) gamma = ys / yy;
      }

      assignScaled(q, gamma, direction);
      if(scalePreconditioner) {
        for(size_t i = 0; i < n; ++i) {
          direction[i] *= variableScale[i];
          direction[i] *= variableScale[i];
        }
      }
      for(int i = 0; i < hist; ++i) {
        const double beta = rhoList[i] * dot(yList[i], direction);
        axpy(alpha[i] - beta, sList[i], direction);
      }
      scale(direction, -1.);

      double descent = dot(g, direction);
      if(!(descent < 0.)) {
        assignScaled(g, -1., direction);
        if(scalePreconditioner) {
          for(size_t i = 0; i < n; ++i) {
            direction[i] *= variableScale[i];
            direction[i] *= variableScale[i];
          }
        }
        descent = dot(g, direction);
        if(options.verbose)
          Msg::Info("LBFGS iter %d: fallback to steepest descent", iter);
      }

      const double directionNorm = norm(direction);
      double step = options.initialStep;
      if(options.maxStepNorm > 0. && directionNorm > 0.)
        step = std::min(step, options.maxStepNorm / directionNorm);
      if(f > 0. && descent < 0.)
        step = std::min(step, 0.5 * f / (options.armijo * -descent));
      if(options.verbose) {
        Msg::Info("LBFGS iter %d direction: g.d %.16g, |d| %.6g, "
                  "initial step %.6g",
                  iter, descent, directionNorm, step);
      }
      result.timeDirection += TimeOfDay() - t;

      bool accepted = false;
      for(int ls = 0; ls < options.maxLineSearchSteps; ++ls) {
        t = TimeOfDay();
        assignStep(x, direction, step, xNew);
        result.timeLineSearch += TimeOfDay() - t;
        t = TimeOfDay();
        double fNew = evaluate(xNew, gNew, false);
        result.timeFunction += TimeOfDay() - t;
        result.functionEvaluations++;

        if(options.verbose) {
          Msg::Info("LBFGS iter %d line %d: step %.6g, f %.16g, armijo %.16g",
                    iter, ls, step, fNew, f + options.armijo * step * descent);
        }

        if(std::isfinite(fNew) && fNew <= f + options.armijo * step * descent) {
          t = TimeOfDay();
          assignDifference(xNew, x, s);
          assignDifference(gNew, g, y);
          const double ys = dot(y, s);
          if(ys > std::numeric_limits<double>::epsilon()) {
            if((int)sList.size() == memory) {
              sList.erase(sList.begin());
              yList.erase(yList.begin());
              rhoList.erase(rhoList.begin());
            }
            sList.push_back(s);
            yList.push_back(y);
            rhoList.push_back(1. / ys);
          }

          const double fOld = f;
          x.swap(xNew);
          g.swap(gNew);
          f = fNew;
          accepted = true;
          result.iterations = iter + 1;
          result.gradientNorm = scaledNorm(g, variableScale);
          result.timeUpdate += TimeOfDay() - t;

          if(options.verbose) {
            Msg::Info("LBFGS iter %d accepted: step %.6g, f %.16g, "
                      "|g| %.6g, corrections %d",
                      iter, step, f, result.gradientNorm, (int)sList.size());
          }
          if(options.progress)
            options.progress(iter + 1, x, f, result.gradientNorm, step);

          if(options.maxIterations > 0 &&
             result.iterations >= options.maxIterations)
            result.terminationType = 5;
          else if(result.gradientNorm <= options.gradientTolerance)
            result.terminationType = 4;
          else if(std::abs(fOld - f) <=
                  options.functionTolerance *
                    std::max({1., std::abs(fOld), std::abs(f)}))
            result.terminationType = 1;
          else if(scaledNorm(s, variableScale, true) <= options.stepTolerance)
            result.terminationType = 2;
          result.converged = result.terminationType == 1 ||
                             result.terminationType == 2 ||
                             result.terminationType == 4;
          break;
        }
        step *= options.backtrackingFactor;
      }

      if(!accepted) {
        result.terminationType = -2;
        if(options.verbose) Msg::Info("LBFGS iter %d failed line search", iter);
        break;
      }
      if(result.terminationType != 0) break;
    }

    if(!result.converged && result.terminationType == 0)
      result.terminationType = 5;

    result.finalValue = f;
    result.gradientNorm = scaledNorm(g, variableScale);
    result.timeTotal = TimeOfDay() - tTotal;
    if(options.verbose) {
      Msg::Info("LBFGS done: converged %d, term %d, iter %d, eval %d, f "
                "%.16g, |g| %.6g, total %g, function %g, direction %g, "
                "line-search %g, update %g",
                result.converged ? 1 : 0, result.terminationType,
                result.iterations, result.functionEvaluations,
                result.finalValue, result.gradientNorm, result.timeTotal,
                result.timeFunction, result.timeDirection,
                result.timeLineSearch, result.timeUpdate);
    }
    return result;
  }

} // namespace LBFGS
