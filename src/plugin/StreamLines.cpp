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
                          {GMSH_FULLRC, "OtherView", nullptr, -1., ""}})
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
         "The time stepping scheme is a RK44 with step size "
         "`DT' and `MaxIter' maximum number of iterations.\n\n"
         "If `TimeStep' < 0, the plugin tries to compute "
         "streamlines of the unsteady flow.\n\n"
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

  const double b1 = 1. / 3., b2 = 2. / 3., b3 = 1. / 3., b4 = 1. / 6.;
  const double a1 = 0.5, a2 = 0.5, a3 = 1., a4 = 1.;

  // the lines of each seed, computed in parallel and then written in the
  // order of the seeds
  struct Line {
    std::vector<double> VP, SL;
    int nVP = 0, nSL = 0;
  };
  int nbV = getNbV(), numSeeds = getNbU() * nbV;
  std::vector<Line> lines(numSeeds);
  auto trace = [&](int seed, Line &line) {
    double XINIT[3], X[3], DX[3] = {0., 0., 0.}, X1[3], X2[3], X3[3], X4[3];
    std::vector<double> val2(data2 ? data2->getNumTimeSteps() : 0);
    getPoint(seed / nbV, seed % nbV, XINIT);
    getPoint(seed / nbV, seed % nbV, X);

    if(data2) { o2->searchScalar(X[0], X[1], X[2], val2.data(), -1); }
    else {
      line.nVP++;
      line.VP.insert(line.VP.end(), X, X + 3);
    }

    int currentTimeStep = 0;
    bool outside = false; // the line has left the domain

    for(int iter = 0; iter < maxIter; iter++) {
      if(outside) { // the point stays where it left the domain
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

      // dX/dt = V
      // X1 = X + a1 * DT * V(X)
      // X2 = X + a2 * DT * V(X1)
      // X3 = X + a3 * DT * V(X2)
      // X4 = X + a4 * DT * V(X3)
      // X = X + b1 X1 + b2 X2 + b3 X3 + b4 x4
      // stop where a stage falls outside of the domain (its velocity would
      // be taken as 0)
      double val[3];
      if(!o1.searchVector(X[0], X[1], X[2], val, currentTimeStep))
        outside = true;
      for(int k = 0; k < 3; k++) X1[k] = X[k] + DT * val[k] * a1;
      if(!outside &&
         !o1.searchVector(X1[0], X1[1], X1[2], val, currentTimeStep))
        outside = true;
      for(int k = 0; k < 3; k++) X2[k] = X[k] + DT * val[k] * a2;
      if(!outside &&
         !o1.searchVector(X2[0], X2[1], X2[2], val, currentTimeStep))
        outside = true;
      for(int k = 0; k < 3; k++) X3[k] = X[k] + DT * val[k] * a3;
      if(!outside &&
         !o1.searchVector(X3[0], X3[1], X3[2], val, currentTimeStep))
        outside = true;
      for(int k = 0; k < 3; k++) X4[k] = X[k] + DT * val[k] * a4;
      if(outside) {
        iter--; // redo this iteration as a point that no longer moves
        continue;
      }

      for(int k = 0; k < 3; k++)
        X[k] += (b1 * (X1[k] - X[k]) + b2 * (X2[k] - X[k]) +
                 b3 * (X3[k] - X[k]) + b4 * (X4[k] - X[k]));
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
  for(int seed = 0; seed < numSeeds; seed++) trace(seed, lines[seed]);
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
