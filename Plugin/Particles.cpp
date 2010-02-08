// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <math.h>
#include "GmshConfig.h"
#include "Particles.h"
#include "OctreePost.h"
#include "Context.h"
#include "PViewOptions.h"

#if defined(HAVE_OPENGL)
#include "drawContext.h"
#endif

StringXNumber ParticlesOptions_Number[] = {
  {GMSH_FULLRC, "X0", GMSH_ParticlesPlugin::callbackX0, 0.},
  {GMSH_FULLRC, "Y0", GMSH_ParticlesPlugin::callbackY0, 0.},
  {GMSH_FULLRC, "Z0", GMSH_ParticlesPlugin::callbackZ0, 0.},
  {GMSH_FULLRC, "X1", GMSH_ParticlesPlugin::callbackX1, 1.},
  {GMSH_FULLRC, "Y1", GMSH_ParticlesPlugin::callbackY1, 0.},
  {GMSH_FULLRC, "Z1", GMSH_ParticlesPlugin::callbackZ1, 0.},
  {GMSH_FULLRC, "X2", GMSH_ParticlesPlugin::callbackX2, 0.},
  {GMSH_FULLRC, "Y2", GMSH_ParticlesPlugin::callbackY2, 1.},
  {GMSH_FULLRC, "Z2", GMSH_ParticlesPlugin::callbackZ2, 0.},
  {GMSH_FULLRC, "NumPointsU", GMSH_ParticlesPlugin::callbackU, 10},
  {GMSH_FULLRC, "NumPointsV", GMSH_ParticlesPlugin::callbackV, 1},
  {GMSH_FULLRC, "A2", NULL, 1. },
  {GMSH_FULLRC, "A1", NULL, 0. },
  {GMSH_FULLRC, "A0", NULL, 0. },
  {GMSH_FULLRC, "DT", NULL, .1},
  {GMSH_FULLRC, "MaxIter", NULL, 100},
  {GMSH_FULLRC, "TimeStep", NULL, 0},
  {GMSH_FULLRC, "View", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterParticlesPlugin()
  {
    return new GMSH_ParticlesPlugin();
  }
}

void GMSH_ParticlesPlugin::draw(void *context)
{
#if defined(HAVE_OPENGL)
  glColor4ubv((GLubyte *) & CTX::instance()->color.fg);
  drawContext *ctx = (drawContext*)context;
  double p[3];
  for(int i = 0; i < getNbU(); ++i){
    for(int j = 0; j < getNbV(); ++j){
      getPoint(i, j, p);
      ctx->drawSphere(CTX::instance()->pointSize, p[0], p[1], p[2], 1);
    }
  }
#endif
}

double GMSH_ParticlesPlugin::callback(int num, int action, double value, double *opt,
                                        double step, double min, double max)
{
  switch(action){ // configure the input field
  case 1: return step;
  case 2: return min;
  case 3: return max;
  default: break;
  }
  *opt = value;
  GMSH_Plugin::setDrawFunction(draw);
  return 0.;
}

double GMSH_ParticlesPlugin::callbackX0(int num, int action, double value)
{
  return callback(num, action, value, &ParticlesOptions_Number[0].def,
                  CTX::instance()->lc / 100., 
                  -2 * CTX::instance()->lc, 2 * CTX::instance()->lc);
}

double GMSH_ParticlesPlugin::callbackY0(int num, int action, double value)
{
  return callback(num, action, value, &ParticlesOptions_Number[1].def,
                  CTX::instance()->lc / 100., 
                  -2 * CTX::instance()->lc, 2 * CTX::instance()->lc);
}

double GMSH_ParticlesPlugin::callbackZ0(int num, int action, double value)
{
  return callback(num, action, value, &ParticlesOptions_Number[2].def,
                  CTX::instance()->lc / 100., 
                  -2 * CTX::instance()->lc, 2 * CTX::instance()->lc);
}

double GMSH_ParticlesPlugin::callbackX1(int num, int action, double value)
{
  return callback(num, action, value, &ParticlesOptions_Number[3].def,
                  CTX::instance()->lc / 100., 
                  -2 * CTX::instance()->lc, 2 * CTX::instance()->lc);
}

double GMSH_ParticlesPlugin::callbackY1(int num, int action, double value)
{
  return callback(num, action, value, &ParticlesOptions_Number[4].def,
                  CTX::instance()->lc / 100., 
                  -2 * CTX::instance()->lc, 2 * CTX::instance()->lc);
}

double GMSH_ParticlesPlugin::callbackZ1(int num, int action, double value)
{
  return callback(num, action, value, &ParticlesOptions_Number[5].def,
                  CTX::instance()->lc / 100., -2*CTX::instance()->lc, 2*CTX::instance()->lc);
}

double GMSH_ParticlesPlugin::callbackX2(int num, int action, double value)
{
  return callback(num, action, value, &ParticlesOptions_Number[6].def,
                  CTX::instance()->lc / 100., -2*CTX::instance()->lc, 2*CTX::instance()->lc);
}

double GMSH_ParticlesPlugin::callbackY2(int num, int action, double value)
{
  return callback(num, action, value, &ParticlesOptions_Number[7].def,
                  CTX::instance()->lc / 100., 
                  -2 * CTX::instance()->lc, 2 * CTX::instance()->lc);
}

double GMSH_ParticlesPlugin::callbackZ2(int num, int action, double value)
{
  return callback(num, action, value, &ParticlesOptions_Number[8].def,
                  CTX::instance()->lc / 100., 
                  -2 * CTX::instance()->lc, 2 * CTX::instance()->lc);
}

double GMSH_ParticlesPlugin::callbackU(int num, int action, double value)
{
  return callback(num, action, value, &ParticlesOptions_Number[9].def,
                  1, 1, 100);
}

double GMSH_ParticlesPlugin::callbackV(int num, int action, double value)
{
  return callback(num, action, value, &ParticlesOptions_Number[10].def,
                  1, 1, 100);
}

std::string GMSH_ParticlesPlugin::getHelp() const
{
  return 
    "Plugin(Particles) computes the trajectory\n"
    "of particules in the force field given by the\n"
    "`TimeStep'-th time step of a vector view\n"
    "`View'. The plugin takes as input a grid defined\n"
    "by the 3 points (`X0',`Y0',`Z0') (origin),\n"
    "(`X1',`Y1',`Z1') (axis of U) and (`X2',`Y2',`Z2')\n"
    "(axis of V). The number of particles along U and V\n"
    "that are to be transported is set with the\n"
    "options `NumPointsU' and `NumPointsV'. The equation\n"
    "A2*d^2X(t)/dt^2+A1*dX(t)/dt+A0*X(t)=F is then\n"
    "solved with the initial conditions X(t=0) chosen\n"
    "as the grid, dX/dt(t=0)=0, and with F\n"
    "interpolated from the vector view. Time stepping\n"
    "is done using a Newmark scheme with step size `DT'\n"
    "and `MaxIter' maximum number of iterations. If\n"
    "`View' < 0 the plugin is run on the current view.\n"
    "\n"
    "Plugin(Particles) creates one new view containing\n"
    "multi-step vector points.\n";
}

int GMSH_ParticlesPlugin::getNbOptions() const
{
  return sizeof(ParticlesOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_ParticlesPlugin::getOption(int iopt)
{
  return &ParticlesOptions_Number[iopt];
}

int GMSH_ParticlesPlugin::getNbU()
{
  return (int)ParticlesOptions_Number[9].def;
}

int GMSH_ParticlesPlugin::getNbV()
{
  return (int)ParticlesOptions_Number[10].def;
}

void GMSH_ParticlesPlugin::getPoint(int iU, int iV, double *X)
{
  double u = getNbU() > 1 ? (double)iU / (double)(getNbU() - 1.) : 0.;
  double v = getNbV() > 1 ? (double)iV / (double)(getNbV() - 1.) : 0.;
  X[0] = ParticlesOptions_Number[0].def + 
    u  * (ParticlesOptions_Number[3].def - ParticlesOptions_Number[0].def) +
    v  * (ParticlesOptions_Number[6].def - ParticlesOptions_Number[0].def);
  X[1] = ParticlesOptions_Number[1].def + 
    u  * (ParticlesOptions_Number[4].def - ParticlesOptions_Number[1].def) +
    v  * (ParticlesOptions_Number[7].def - ParticlesOptions_Number[1].def);
  X[2] = ParticlesOptions_Number[2].def + 
    u  * (ParticlesOptions_Number[5].def - ParticlesOptions_Number[2].def) +
    v  * (ParticlesOptions_Number[8].def - ParticlesOptions_Number[2].def);
}

PView *GMSH_ParticlesPlugin::execute(PView *v)
{
  double A2 = ParticlesOptions_Number[11].def;
  double A1 = ParticlesOptions_Number[12].def;
  double A0 = ParticlesOptions_Number[13].def;
  double DT = ParticlesOptions_Number[14].def;
  int maxIter = (int)ParticlesOptions_Number[15].def;
  int timeStep = (int)ParticlesOptions_Number[16].def;
  int iView = (int)ParticlesOptions_Number[17].def;

  PView *v1 = getView(iView, v);
  if(!v1) return v;
  PViewData *data1 = v1->getData();

  // sanity checks
  if(timeStep > data1->getNumTimeSteps() - 1){
    Msg::Error("Invalid time step (%d) in view[%d]: using 0", v1->getIndex());
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
  //   DT^2 (beta b^{n+1} + (0.5 + gamma - 2 beta) b^n + (0.5 - gamma + beta) b^{n-1})
  //
  // coefs for constant acceleration (unconditinonally stable)
  const double gamma = 0.5, beta = 0.25; 
  double c1 = (A2 + gamma * DT * A1 + beta * DT * DT * A0);
  double c2 = (2 * A2 - (1 - 2 * gamma) * DT * A1 - (0.5 + gamma - 2 * beta) * DT * DT * A0);
  double c3 = (-A2 - (gamma - 1) * DT * A1 - (0.5 - gamma + beta) * DT * DT * A0);
  double c4 = DT * DT * (beta + (0.5 + gamma - 2 * beta) + (0.5 - gamma + beta));

  for(int i = 0; i < getNbU(); ++i){
    for(int j = 0; j < getNbV(); ++j){
      double XINIT[3], X0[3], X1[3];
      getPoint(i, j, XINIT);
      getPoint(i, j, X0);
      getPoint(i, j, X1);
      data2->NbVP++;
      data2->VP.push_back(XINIT[0]);
      data2->VP.push_back(XINIT[1]);
      data2->VP.push_back(XINIT[2]);
      for(int iter = 0; iter < maxIter; iter++){
        double F[3], X[3];
        o1.searchVector(X1[0], X1[1], X1[2], F, timeStep);
        for(int k = 0; k < 3; k++)
          X[k] = (c2 * X1[k] + c3 * X0[k] + c4 * F[k]) / c1;
        data2->VP.push_back(X[0] - XINIT[0]);
        data2->VP.push_back(X[1] - XINIT[1]);
        data2->VP.push_back(X[2] - XINIT[2]);
        for(int k = 0; k < 3; k++){
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
