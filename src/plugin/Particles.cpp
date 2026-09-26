// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <cmath>
#include "GmshConfig.h"
#include "Particles.h"
#include "OctreePost.h"
#include "Context.h"
#include "PViewOptions.h"

#if defined(HAVE_OPENGL)
#include "drawContext.h"
#endif

GMSH_ParticlesPlugin::GMSH_ParticlesPlugin()
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
                          {GMSH_FULLRC, "A2", nullptr, 1., ""},
                          {GMSH_FULLRC, "A1", nullptr, 0., ""},
                          {GMSH_FULLRC, "A0", nullptr, 0., ""},
                          {GMSH_FULLRC, "DT", nullptr, .1, ""},
                          {GMSH_FULLRC, "MaxIter", nullptr, 100, ""},
                          {GMSH_FULLRC, "TimeStep", nullptr, 0, ""},
                          {GMSH_FULLRC, "View", nullptr, -1., ""}})
{
}

std::string GMSH_ParticlesPlugin::getHelp() const
{
  return "Plugin(Particles) computes the trajectory "
         "of particules in the force field given by the "
         "`TimeStep'-th time step of a vector view "
         "`View'.\n\n"
         "The plugin takes as input a grid defined by the "
         "3 points (`X0',`Y0',`Z0') (origin), (`X1',`Y1',`Z1') "
         "(axis of U) and (`X2',`Y2',`Z2') (axis of V).\n\n"
         "The number of particles along U and V that are to "
         "be transported is set with the options `NumPointsU' "
         "and `NumPointsV'. The equation\n\n"
         "A2 * d^2X(t)/dt^2 + A1 * dX(t)/dt + A0 * X(t) = F\n\n"
         "is then solved with the initial conditions X(t=0) "
         "chosen as the grid, dX/dt(t=0)=0, and with F "
         "interpolated from the vector view.\n\n"
         "Time stepping is done using a Newmark scheme with "
         "step size `DT' and `MaxIter' maximum number of "
         "iterations.\n\n"
         "If `View' < 0, the plugin is run on the current view.\n\n"
         "Plugin(Particles) creates one new list-based view containing "
         "multi-step vector points.";
}

PView *GMSH_ParticlesPlugin::execute(PView *v)
{
  double A2 = option(11);
  double A1 = option(12);
  double A0 = option(13);
  double DT = option(14);
  int maxIter = (int)option(15);
  int timeStep = (int)option(16);
  int iView = (int)option(17);

  PView *v1 = getView(iView, v);
  if(!v1) return v;
  PViewData *data1 = getPossiblyAdaptiveData(v1);

  // sanity checks
  if(timeStep < 0 || timeStep > data1->getNumTimeSteps() - 1) {
    Msg::Warning("Invalid time step (%d) in View[%d]: using 0", timeStep,
                 v1->getIndex());
    timeStep = 0;
  }

  OctreePost o1(v1);

  PView *v2 = new PView();
  PViewDataList *data2 = getDataList(v2);

  // solve 'A2 d^2x/dt^2 + A1 dx/dt + A0 x = F' using a Newmark scheme:
  //
  // (A2 + gamma DT A1 + beta DT^2 A0) x^{n+1} =
  //   (2 A2 - (1 - 2 gamma) DT A1 - (0.5 + gamma - 2 beta) DT^2 A0) x^n +
  //   (-A2 - (gamma - 1) DT A1 - (0.5 - gamma + beta) DT^2 A0) x^{n-1} +
  //   DT^2 (beta b^{n+1} + (0.5 + gamma - 2 beta) b^n + (0.5 - gamma + beta)
  //   b^{n-1})
  //
  // coefs for constant acceleration (unconditinonally stable)
  const double gamma = 0.5, beta = 0.25;
  double c1 = (A2 + gamma * DT * A1 + beta * DT * DT * A0);
  double c2 = (2 * A2 - (1 - 2 * gamma) * DT * A1 -
               (0.5 + gamma - 2 * beta) * DT * DT * A0);
  double c3 =
    (-A2 - (gamma - 1) * DT * A1 - (0.5 - gamma + beta) * DT * DT * A0);
  double c4 =
    DT * DT * (beta + (0.5 + gamma - 2 * beta) + (0.5 - gamma + beta));

  // the trajectory of each seed, computed in parallel and then written in
  // the order of the seeds
  int nbV = getNbV(), numSeeds = getNbU() * nbV;
  std::vector<std::vector<double>> trajectories(numSeeds);
  o1.prepareThreads();
  int nthreads =
    CTX::instance()->numThreadsFor((std::size_t)numSeeds * maxIter, 10000);
#pragma omp parallel for num_threads(nthreads) schedule(dynamic, 1)
  for(int seed = 0; seed < numSeeds; seed++) {
    std::vector<double> &t = trajectories[seed];
    double XINIT[3], X0[3], X1[3];
    getPoint(seed / nbV, seed % nbV, XINIT);
    getPoint(seed / nbV, seed % nbV, X0);
    getPoint(seed / nbV, seed % nbV, X1);
    t.insert(t.end(), XINIT, XINIT + 3);
    for(int iter = 0; iter < maxIter; iter++) {
      double F[3], X[3];
      o1.searchVector(X1[0], X1[1], X1[2], F, timeStep);
      for(int k = 0; k < 3; k++)
        X[k] = (c2 * X1[k] + c3 * X0[k] + c4 * F[k]) / c1;
      for(int k = 0; k < 3; k++) t.push_back(X[k] - XINIT[k]);
      for(int k = 0; k < 3; k++) {
        X0[k] = X1[k];
        X1[k] = X[k];
      }
    }
  }
  for(auto &t : trajectories) data2->appendList(3, TYPE_PNT, 1, t);

  v2->getOptions()->vectorType = PViewOptions::Displacement;

  data2->setName(data1->getName() + "_Particles");
  data2->setFileName(data1->getName() + "_Particles.pos");
  data2->finalize();

  return v2;
}
