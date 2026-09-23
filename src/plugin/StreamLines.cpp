// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <cmath>
#include "GmshConfig.h"
#include "StreamLines.h"
#include "OctreePost.h"
#include "Context.h"
#include "PViewOptions.h"

#if defined(HAVE_OPENGL)
#include "drawContext.h"
#endif

GMSH_StreamLinesPlugin::GMSH_StreamLinesPlugin()
  : GMSH_PointGridPlugin({{GMSH_FULLRC, "X0", nullptr, 0., ""},
                          {GMSH_FULLRC, "Y0", nullptr, 0., ""},
                          {GMSH_FULLRC, "Z0", nullptr, 0., ""},
                          {GMSH_FULLRC, "X1", nullptr, 1., ""},
                          {GMSH_FULLRC, "Y1", nullptr, 0., ""},
                          {GMSH_FULLRC, "Z1", nullptr, 0., ""},
                          {GMSH_FULLRC, "X2", nullptr, 0., ""},
                          {GMSH_FULLRC, "Y2", nullptr, 1., ""},
                          {GMSH_FULLRC, "Z2", nullptr, 0., ""},
                          {GMSH_FULLRC, "NumPointsU", nullptr, 10, ""},
                          {GMSH_FULLRC, "NumPointsV", nullptr, 1, ""},
                          {GMSH_FULLRC, "DT", nullptr, .1, ""},
                          {GMSH_FULLRC, "MaxIter", nullptr, 100, ""},
                          {GMSH_FULLRC, "TimeStep", nullptr, 0, ""},
                          {GMSH_FULLRC, "View", nullptr, -1., ""},
                          {GMSH_FULLRC, "OtherView", nullptr, -1., ""},
                          {GMSH_FULLRC, "Tolerance", nullptr, 0., ""},
                          {GMSH_FULLRC, "Direction", nullptr, 1., ""},
                          {GMSH_FULLRC, "MinSpeed", nullptr, 0., ""}})
{
}

std::string GMSH_StreamLinesPlugin::getHelp() const
{
  return "Plugin(StreamLines) computes stream lines "
         "from the `TimeStep'-th time step of a vector "
         "view `View' and optionally interpolates the "
         "scalar view `OtherView' on the resulting stream "
         "lines.\n\n"
         "The plugin takes as input a grid defined by the "
         "3 points (`X0',`Y0',`Z0') (origin), (`X1',`Y1',`Z1') "
         "(axis of U) and (`X2',`Y2',`Z2') (axis of V).\n\n"
         "The number of points along U and V that are to be "
         "transported is set with the options `NumPointsU' "
         "and `NumPointsV'. The equation\n\n"
         "dX(t)/dt = V(x,y,z)\n\n"
         "is then solved with the initial condition X(t=0) "
         "chosen as the grid and with V(x,y,z) interpolated "
         "on the vector view.\n\n"
         "The lines are computed over `MaxIter' steps of size `DT', "
         "forward if `Direction' = 1, backward if `Direction' = -1, or both "
         "ways from the seeds if `Direction' = 0 (with `OtherView' only). If "
         "`Tolerance' = 0, each step is a step of the classical fourth order "
         "Runge-Kutta scheme; otherwise it is made of the steps of an embedded "
         "Runge-Kutta 5(4) scheme (Dormand-Prince), whose sizes adapt to keep "
         "the estimated error of each below `Tolerance' times the size of the "
         "model. A line stops where it leaves the domain, or where the speed "
         "falls below `MinSpeed'.\n\n"
         "If `TimeStep' < 0, the plugin tries to compute "
         "streamlines of the unsteady flow (forward only), with the time step "
         "closest to the time of each step.\n\n"
         "If `View' < 0, the plugin is run on the current view.\n\n"
         "Plugin(StreamLines) creates one new list-based view. This "
         "view contains multi-step vector points if `OtherView' "
         "< 0, or single-step scalar lines if `OtherView' >= 0.";
}

PView *GMSH_StreamLinesPlugin::execute(PView *v)
{
  double DT = option(11);
  int maxIter = (int)option(12);
  int timeStep = (int)option(13);
  int iView = (int)option(14);
  int otherView = (int)option(15);

  PView *v1 = getView(iView, v);
  if(!v1) return v;
  PViewData *data1 = getPossiblyAdaptiveData(v1);

  PView *v2 = (otherView < 0) ? nullptr : getView(otherView, v);
  PViewData *data2 = v2 ? getPossiblyAdaptiveData(v2) : nullptr;

  // sanity checks
  if(timeStep > data1->getNumTimeSteps() - 1) {
    Msg::Error("Invalid time step (%d) in View[%d]", timeStep, v1->getIndex());
    return v;
  }

  OctreePost o1(v1);
  OctreePost *o2 = data2 ? new OctreePost(v2) : nullptr;

  PView *v3 = new PView();
  PViewDataList *data3 = getDataList(v3);

  double tol = option(16) * CTX::instance()->lc;
  int direction = (int)option(17);
  double minSpeed = option(18);
  if(direction < -1 || direction > 1) {
    Msg::Error("Direction should be 1, -1 or 0");
    return v;
  }
  if(direction != 1 && timeStep < 0) {
    Msg::Error("Streamlines of an unsteady flow can only be computed forward");
    return v;
  }
  if(direction == 0 && !data2) {
    Msg::Warning("Streamlines both ways need OtherView: computing them "
                 "forward");
    direction = 1;
  }

  // the velocity at a point, false outside of the domain or below MinSpeed
  auto velocity = [&](const double *X, int step, OctreePost::Cache &cache,
                      double *V) {
    if(!o1.searchVector(X[0], X[1], X[2], V, step, cache)) return false;
    return !(minSpeed > 0 &&
             std::sqrt(V[0] * V[0] + V[1] * V[1] + V[2] * V[2]) < minSpeed);
  };

  // move X over a step h (dX/dt = V), with the classical Runge-Kutta scheme:
  //   X1 = X + a1 h V(X), X2 = X + a2 h V(X1), X3 = X + a3 h V(X2),
  //   X4 = X + a4 h V(X3), X = X + b1 (X1 - X) + ... + b4 (X4 - X)
  // false if it fails (outside or too slow)
  auto rk4 = [&](double *X, double h, int step, OctreePost::Cache &cache) {
    const double a[4] = {0.5, 0.5, 1., 1.};
    const double b[4] = {1. / 3., 2. / 3., 1. / 3., 1. / 6.};
    double Xs[4][3], val[3];
    const double *from = X;
    for(int s = 0; s < 4; s++) {
      if(!velocity(from, step, cache, val)) return false;
      for(int k = 0; k < 3; k++) Xs[s][k] = X[k] + h * val[k] * a[s];
      from = Xs[s];
    }
    for(int k = 0; k < 3; k++)
      X[k] += (b[0] * (Xs[0][k] - X[k]) + b[1] * (Xs[1][k] - X[k]) +
               b[2] * (Xs[2][k] - X[k]) + b[3] * (Xs[3][k] - X[k]));
    return true;
  };

  // move X over a step h with steps of the Dormand-Prince 5(4) scheme, whose
  // sizes (starting from hs, updated) keep the error estimate below tol; a
  // step with a stage outside of the domain is made smaller, to end the line
  // close to the boundary; false if it stops before the end, X being where
  // it stopped
  auto rk45 = [&](double *X, double h, int step, OctreePost::Cache &cache,
                  double &hs) {
    static const double c[7][6] = {
      {0, 0, 0, 0, 0, 0},
      {1. / 5, 0, 0, 0, 0, 0},
      {3. / 40, 9. / 40, 0, 0, 0, 0},
      {44. / 45, -56. / 15, 32. / 9, 0, 0, 0},
      {19372. / 6561, -25360. / 2187, 64448. / 6561, -212. / 729, 0, 0},
      {9017. / 3168, -355. / 33, 46732. / 5247, 49. / 176, -5103. / 18656, 0},
      {35. / 384, 0, 500. / 1113, 125. / 192, -2187. / 6784, 11. / 84}};
    // fifth minus fourth order weights
    static const double e[7] = {
      71. / 57600,      0.,        -71. / 16695, 71. / 1920,
      -17253. / 339200, 22. / 525, -1. / 40};
    double done = 0., span = std::abs(h), sign = (h < 0) ? -1. : 1.;
    while(done < span) {
      double hh = std::min(hs, span - done), k[7][3], Y[3];
      bool inside = true;
      for(int s = 0; s < 7 && inside; s++) {
        for(int d = 0; d < 3; d++) {
          Y[d] = X[d];
          for(int j = 0; j < s; j++) Y[d] += sign * hh * c[s][j] * k[j][d];
        }
        inside = velocity(Y, step, cache, k[s]);
      }
      if(!inside) {
        if(hh < 1.e-6 * span) return false; // at the boundary, or stagnant
        hs = hh / 4.;
        continue;
      }
      // Y is the fifth order solution (the last stage is evaluated there)
      double err = 0.;
      for(int d = 0; d < 3; d++) {
        double ed = 0.;
        for(int s = 0; s < 7; s++) ed += e[s] * k[s][d];
        err = std::max(err, std::abs(hh * ed));
      }
      double f = (err > 0.) ? 0.9 * std::pow(tol / err, 0.2) : 5.;
      if(err <= tol) {
        for(int d = 0; d < 3; d++) X[d] = Y[d];
        done += hh;
        hs = hh * std::min(5., std::max(0.2, f));
      }
      else {
        hs = hh * std::max(0.2, f);
        if(hs < 1.e-9 * span) return false;
      }
    }
    return true;
  };

  // the lines of each seed, computed in parallel and then written in the
  // order of the seeds
  struct Line {
    std::vector<double> VP, SL;
    int nVP = 0, nSL = 0;
  };
  int nbV = getNbV(), numSeeds = getNbU() * nbV;
  std::vector<Line> lines(numSeeds);
  auto trace = [&](int seed, int dir, Line &line) {
    double XINIT[3], X[3], DX[3] = {0., 0., 0.};
    std::vector<double> val2(data2 ? data2->getNumTimeSteps() : 0);
    getPoint(seed / nbV, seed % nbV, XINIT);
    getPoint(seed / nbV, seed % nbV, X);
    OctreePost::Cache cache;
    double hs = std::abs(DT);

    if(data2) { o2->searchScalar(X[0], X[1], X[2], val2.data(), -1); }
    else {
      line.nVP++;
      line.VP.insert(line.VP.end(), X, X + 3);
    }

    int currentTimeStep = 0;
    bool outside = false; // the line has stopped

    for(int iter = 0; iter < maxIter; iter++) {
      if(outside) { // the point stays where the line stopped
        if(data2) break;
        line.VP.insert(line.VP.end(), DX, DX + 3);
        continue;
      }
      double XPREV[3] = {X[0], X[1], X[2]};

      if(timeStep < 0) {
        double T0 = data1->getTime(0);
        double currentT = T0 + DT * iter;
        for(; currentTimeStep < data1->getNumTimeSteps() - 1 &&
              currentT > 0.5 * (data1->getTime(currentTimeStep) +
                                data1->getTime(currentTimeStep + 1));
            currentTimeStep++);
      }
      else {
        currentTimeStep = timeStep;
      }

      bool ok = (tol > 0.) ? rk45(X, dir * DT, currentTimeStep, cache, hs) :
                             rk4(X, dir * DT, currentTimeStep, cache);
      if(!ok) {
        outside = true;
        // the part of the step made before stopping (adaptive steps) ends the
        // line; without any, redo this iteration as a point that no longer
        // moves
        if(X[0] == XPREV[0] && X[1] == XPREV[1] && X[2] == XPREV[2]) {
          iter--;
          continue;
        }
      }
      for(int k = 0; k < 3; k++) DX[k] = X[k] - XINIT[k];

      if(data2) {
        line.nSL++;
        double xyz[6] = {XPREV[0], X[0], XPREV[1], X[1], XPREV[2], X[2]};
        line.SL.insert(line.SL.end(), xyz, xyz + 6);
        line.SL.insert(line.SL.end(), val2.begin(), val2.end());
        o2->searchScalar(X[0], X[1], X[2], val2.data(), -1);
        line.SL.insert(line.SL.end(), val2.begin(), val2.end());
      }
      else {
        line.VP.insert(line.VP.end(), DX, DX + 3);
      }
    }
  };
  o1.prepareThreads();
  if(o2) o2->prepareThreads();
  int nthreads =
    CTX::instance()->numThreadsFor((std::size_t)numSeeds * maxIter, 10000);
#pragma omp parallel for num_threads(nthreads) schedule(dynamic, 1)
  for(int seed = 0; seed < numSeeds; seed++) {
    if(direction == 0) { // backward, then forward
      trace(seed, -1, lines[seed]);
      trace(seed, 1, lines[seed]);
    }
    else
      trace(seed, direction, lines[seed]);
  }
  for(auto &line : lines) {
    data3->NbVP += line.nVP;
    data3->VP.insert(data3->VP.end(), line.VP.begin(), line.VP.end());
    data3->NbSL += line.nSL;
    data3->SL.insert(data3->SL.end(), line.SL.begin(), line.SL.end());
  }

  // the steps of the other view on the lines, or the displacements at the end
  // of each iteration in an unsteady field
  if(data2) {
    for(int k = 0; k < data2->getNumTimeSteps(); k++)
      data3->Time.push_back(data2->getTime(k));
  }
  else if(timeStep < 0) {
    for(int iter = 0; iter < maxIter; iter++)
      data3->Time.push_back(data1->getTime(0) + DT * (iter + 1));
  }

  if(data2) { delete o2; }
  else {
    v3->getOptions()->vectorType = PViewOptions::Displacement;
  }

  data3->setName(data1->getName() + "_StreamLines");
  data3->setFileName(data1->getName() + "_StreamLines.pos");
  data3->finalize();

  return v3;
}
