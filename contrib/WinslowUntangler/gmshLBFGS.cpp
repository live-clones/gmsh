// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "gmshLBFGS.h"

#include "GmshConfig.h"
#include "GmshMessage.h"
#include "OS.h"

#include <algorithm>
#include <cmath>
#include <limits>

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

namespace GmshLBFGS {
  namespace {
    static int blasSize(size_t n)
    {
      return (n > (size_t)std::numeric_limits<int>::max()) ?
               std::numeric_limits<int>::max() :
               (int)n;
    }

    static double dot(const std::vector<double> &a,
                      const std::vector<double> &b)
    {
#if defined(HAVE_BLAS)
      int n = blasSize(a.size()), inc = 1;
      return F77NAME(ddot)(&n, const_cast<double *>(a.data()), &inc,
                           const_cast<double *>(b.data()), &inc);
#else
      double val = 0.0;
      for(size_t i = 0; i < a.size(); ++i) val += a[i] * b[i];
      return val;
#endif
    }

    static double norm(const std::vector<double> &a)
    {
      return std::sqrt(dot(a, a));
    }

    static void axpy(double a, const std::vector<double> &x,
                     std::vector<double> &y)
    {
#if defined(HAVE_BLAS)
      int n = blasSize(x.size()), inc = 1;
      F77NAME(daxpy)(&n, &a, const_cast<double *>(x.data()), &inc, y.data(),
                     &inc);
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
#else
      for(size_t i = 0; i < x.size(); ++i) out[i] = scale * x[i];
#endif
    }

    static void scale(std::vector<double> &x, double scale)
    {
#if defined(HAVE_BLAS)
      int n = blasSize(x.size()), inc = 1;
      F77NAME(dscal)(&n, &scale, x.data(), &inc);
#else
      for(size_t i = 0; i < x.size(); ++i) x[i] *= scale;
#endif
    }

  } // namespace

  Result minimize(std::vector<double> &x, const FunctionGradient &fg,
                  const Options &options)
  {
    Result result;
    if(!fg || x.empty()) {
      result.terminationType = -1;
      return result;
    }

    const size_t n = x.size();
    const int memory = std::max(1, options.memory);
    (void)options.numThreads;

    std::vector<double> g(n), gNew(n), xNew(n), direction(n), q(n), s(n), y(n);
    std::vector<std::vector<double>> sList, yList;
    std::vector<double> rhoList, alpha;
    sList.reserve(memory);
    yList.reserve(memory);
    rhoList.reserve(memory);
    alpha.resize(memory);

    const double tTotal = TimeOfDay();
    double t = TimeOfDay();
    double f = fg(x, g);
    result.timeFunction += TimeOfDay() - t;
    result.functionEvaluations++;
    result.initialValue = f;

    for(int iter = 0; iter < options.maxIterations; ++iter) {
      result.iterations = iter;
      result.gradientNorm = norm(g);
      if(options.verbose) {
        Msg::Info("GmshLBFGS iter %d: f %.16g, |g| %.6g", iter, f,
                  result.gradientNorm);
      }
      if(result.gradientNorm <= options.gradientTolerance) {
        result.converged = true;
        result.terminationType = 4;
        if(options.verbose)
          Msg::Info("GmshLBFGS converged on gradient tolerance");
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
        const double yy = dot(yList.back(), yList.back());
        if(yy > 0.) gamma = ys / yy;
      }

      assignScaled(q, gamma, direction);
      for(int i = 0; i < hist; ++i) {
        const double beta = rhoList[i] * dot(yList[i], direction);
        axpy(alpha[i] - beta, sList[i], direction);
      }
      scale(direction, -1.);

      double descent = dot(g, direction);
      if(!(descent < 0.)) {
        assignScaled(g, -1., direction);
        descent = dot(g, direction);
        if(options.verbose)
          Msg::Info("GmshLBFGS iter %d: fallback to steepest descent", iter);
      }

      const double directionNorm = norm(direction);
      double step = options.initialStep;
      if(options.maxStepNorm > 0. && directionNorm > 0.)
        step = std::min(step, options.maxStepNorm / directionNorm);
      if(f > 0. && descent < 0.)
        step = std::min(step, 0.5 * f / (options.armijo * -descent));
      if(options.verbose) {
        Msg::Info("GmshLBFGS iter %d direction: g.d %.16g, |d| %.6g, "
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
        const double fNew = fg(xNew, gNew);
        result.timeFunction += TimeOfDay() - t;
        result.functionEvaluations++;

        if(options.verbose) {
          Msg::Info(
            "GmshLBFGS iter %d line %d: step %.6g, f %.16g, armijo %.16g", iter,
            ls, step, fNew, f + options.armijo * step * descent);
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
          result.timeUpdate += TimeOfDay() - t;

          if(options.verbose) {
            Msg::Info("GmshLBFGS iter %d accepted: step %.6g, f %.16g, "
                      "|g| %.6g, corrections %d",
                      iter, step, f, norm(g), (int)sList.size());
          }

          if(std::abs(fOld - f) <=
             options.functionTolerance * std::max(1., std::abs(f))) {
            result.converged = true;
            result.terminationType = 1;
            if(options.verbose)
              Msg::Info("GmshLBFGS converged on function tolerance");
          }
          if(step * norm(direction) <= options.stepTolerance) {
            result.converged = true;
            result.terminationType = 2;
            if(options.verbose)
              Msg::Info("GmshLBFGS converged on step tolerance");
          }
          break;
        }
        step *= options.backtrackingFactor;
      }

      if(!accepted) {
        result.terminationType = -2;
        if(options.verbose)
          Msg::Info("GmshLBFGS iter %d failed line search", iter);
        break;
      }
      if(result.converged) break;
    }

    result.finalValue = f;
    result.gradientNorm = norm(g);
    result.timeTotal = TimeOfDay() - tTotal;
    if(options.verbose) {
      Msg::Info("GmshLBFGS done: converged %d, term %d, iter %d, eval %d, f "
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

} // namespace GmshLBFGS
