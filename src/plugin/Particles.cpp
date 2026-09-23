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
#include "glyphList.h"
#endif

GMSH_ParticlesPlugin::GMSH_ParticlesPlugin()
  : GMSH_PostPlugin({{GMSH_FULLRC, "X0", nullptr, 0., ""},
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

void GMSH_ParticlesPlugin::drawPreview(void *context)
{
#if defined(HAVE_OPENGL)
  gmshColor4ubv((GLubyte *)&CTX::instance()->color.fg);
  drawContext *ctx = (drawContext *)context;
  double p[3];
  glyphList g;
  unsigned int col = glyphCurrentColor();
  g.reserve(GLYPH_SPHERE, getNbU() * getNbV());
  for(int i = 0; i < getNbU(); ++i) {
    for(int j = 0; j < getNbV(); ++j) {
      getPoint(i, j, p);
      g.addSphere(ctx, CTX::instance()->pointSize, p[0], p[1], p[2], col);
    }
  }
  g.draw(ctx, 1);
#endif
}

bool GMSH_ParticlesPlugin::optionCallback(int iopt, int num, int action,
                                          double &value)
{
  double lc = CTX::instance()->lc;
  if(iopt < 9) // coordinates of the 3 points
    return sliderOption(iopt, action, value, lc / 100., -2 * lc, 2 * lc);
  if(iopt == 9 || iopt == 10)
    return sliderOption(iopt, action, value, 1, 1, 100);
  return false;
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

int GMSH_ParticlesPlugin::getNbU() { return (int)option(9); }

int GMSH_ParticlesPlugin::getNbV() { return (int)option(10); }

void GMSH_ParticlesPlugin::getPoint(int iU, int iV, double *X)
{
  double u = getNbU() > 1 ? (double)iU / (double)(getNbU() - 1.) : 0.;
  double v = getNbV() > 1 ? (double)iV / (double)(getNbV() - 1.) : 0.;
  X[0] = option(0) + u * (option(3) - option(0)) + v * (option(6) - option(0));
  X[1] = option(1) + u * (option(4) - option(1)) + v * (option(7) - option(1));
  X[2] = option(2) + u * (option(5) - option(2)) + v * (option(8) - option(2));
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

  for(int i = 0; i < getNbU(); ++i) {
    for(int j = 0; j < getNbV(); ++j) {
      double XINIT[3], X0[3], X1[3];
      getPoint(i, j, XINIT);
      getPoint(i, j, X0);
      getPoint(i, j, X1);
      data2->NbVP++;
      data2->VP.push_back(XINIT[0]);
      data2->VP.push_back(XINIT[1]);
      data2->VP.push_back(XINIT[2]);
      for(int iter = 0; iter < maxIter; iter++) {
        double F[3], X[3];
        o1.searchVector(X1[0], X1[1], X1[2], F, timeStep);
        for(int k = 0; k < 3; k++)
          X[k] = (c2 * X1[k] + c3 * X0[k] + c4 * F[k]) / c1;
        data2->VP.push_back(X[0] - XINIT[0]);
        data2->VP.push_back(X[1] - XINIT[1]);
        data2->VP.push_back(X[2] - XINIT[2]);
        for(int k = 0; k < 3; k++) {
          X0[k] = X1[k];
          X1[k] = X[k];
        }
      }
    }
  }

  v2->getOptions()->vectorType = PViewOptions::Displacement;

  data2->setName(data1->getName() + "_Particles");
  data2->setFileName(data1->getName() + "_Particles.pos");
  data2->finalize();

  return v2;
}
