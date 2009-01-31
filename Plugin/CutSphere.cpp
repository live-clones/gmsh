// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <string.h>
#include "GmshConfig.h"
#include "CutSphere.h"
#include "Context.h"

#if defined(HAVE_FLTK)
#include "drawContext.h"
#include "Draw.h"
#endif

StringXNumber CutSphereOptions_Number[] = {
  {GMSH_FULLRC, "Xc", GMSH_CutSpherePlugin::callbackX, 0.},
  {GMSH_FULLRC, "Yc", GMSH_CutSpherePlugin::callbackY, 0.},
  {GMSH_FULLRC, "Zc", GMSH_CutSpherePlugin::callbackZ, 0.},
  {GMSH_FULLRC, "R", GMSH_CutSpherePlugin::callbackR, 0.25},
  {GMSH_FULLRC, "ExtractVolume", GMSH_CutSpherePlugin::callbackVol, 0.},
  {GMSH_FULLRC, "RecurLevel", GMSH_CutSpherePlugin::callbackRecur, 4},
  {GMSH_FULLRC, "iView", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterCutSpherePlugin()
  {
    return new GMSH_CutSpherePlugin();
  }
}

void GMSH_CutSpherePlugin::draw(void *context)
{
#if defined(HAVE_FLTK)
  GLint mode[2];
  glGetIntegerv(GL_POLYGON_MODE, mode);
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glColor4ubv((GLubyte *) & CTX::instance()->color.fg);
  glLineWidth(CTX::instance()->lineWidth);
  drawContext *ctx = (drawContext*)context;
  ctx->drawSphere(CutSphereOptions_Number[3].def,
                  CutSphereOptions_Number[0].def,
                  CutSphereOptions_Number[1].def,
                  CutSphereOptions_Number[2].def, 40, 40, 1);
  glPolygonMode(GL_FRONT_AND_BACK, mode[1]);
#endif
}

double GMSH_CutSpherePlugin::callback(int num, int action, double value, double *opt,
                                      double step, double min, double max)
{
  switch(action){ // configure the input field
  case 1: return step;
  case 2: return min;
  case 3: return max;
  default: break;
  }
  *opt = value;
#if defined(HAVE_FLTK)
  DrawPlugin(draw);
#endif
  return 0.;
}

double GMSH_CutSpherePlugin::callbackX(int num, int action, double value)
{
  return callback(num, action, value, &CutSphereOptions_Number[0].def,
                  CTX::instance()->lc/100., -2*CTX::instance()->lc, 2*CTX::instance()->lc);
}

double GMSH_CutSpherePlugin::callbackY(int num, int action, double value)
{
  return callback(num, action, value, &CutSphereOptions_Number[1].def,
                  CTX::instance()->lc/100., -2*CTX::instance()->lc, 2*CTX::instance()->lc);
}

double GMSH_CutSpherePlugin::callbackZ(int num, int action, double value)
{
  return callback(num, action, value, &CutSphereOptions_Number[2].def,
                  CTX::instance()->lc/100., -2*CTX::instance()->lc, 2*CTX::instance()->lc);
}

double GMSH_CutSpherePlugin::callbackR(int num, int action, double value)
{
  return callback(num, action, value, &CutSphereOptions_Number[3].def,
                  CTX::instance()->lc/100., 0., 2*CTX::instance()->lc);
}

double GMSH_CutSpherePlugin::callbackVol(int num, int action, double value)
{
  return callback(num, action, value, &CutSphereOptions_Number[4].def,
                  1., -1., 1.);
}

double GMSH_CutSpherePlugin::callbackRecur(int num, int action, double value)
{
  return callback(num, action, value, &CutSphereOptions_Number[5].def,
                  1, 0, 10);
}

void GMSH_CutSpherePlugin::getName(char *name) const
{
  strcpy(name, "Cut Sphere");
}

void GMSH_CutSpherePlugin::getInfos(char *author, char *copyright,
                                    char *help_text) const
{
  strcpy(author, "C. Geuzaine, J.-F. Remacle");
  strcpy(copyright, "C. Geuzaine, J.-F. Remacle");
  strcpy(help_text,
         "Plugin(CutSphere) cuts the view `iView' with the\n"
         "sphere (X-`Xc')^2 + (Y-`Yc')^2 + (Z-`Zc')^2 = `R'^2.\n"
         "If `ExtractVolume' is nonzero, the plugin extracts\n"
         "the elements inside (if `ExtractVolume' < 0) or\n"
         "outside (if `ExtractVolume' > 0) the sphere. If\n"
         "`iView' < 0, the plugin is run on the current view.\n"
         "\n"
         "Plugin(CutSphere) creates one new view.\n");
}

int GMSH_CutSpherePlugin::getNbOptions() const
{
  return sizeof(CutSphereOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_CutSpherePlugin::getOption(int iopt)
{
  return &CutSphereOptions_Number[iopt];
}

void GMSH_CutSpherePlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "CutSphere failed...");
}

double GMSH_CutSpherePlugin::levelset(double x, double y, double z,
                                      double val) const
{
  double a = CutSphereOptions_Number[0].def;
  double b = CutSphereOptions_Number[1].def;
  double c = CutSphereOptions_Number[2].def;
  double r = CutSphereOptions_Number[3].def;
  return (x - a) * (x - a) + (y - b) * (y - b) + (z - c) * (z - c) - r * r;
}

PView *GMSH_CutSpherePlugin::execute(PView *v)
{
  int iView = (int)CutSphereOptions_Number[6].def;
  _ref[0] = CutSphereOptions_Number[0].def;
  _ref[1] = CutSphereOptions_Number[1].def;
  _ref[2] = CutSphereOptions_Number[2].def;
  _extractVolume = (int)CutSphereOptions_Number[4].def;
  _recurLevel = (int)CutSphereOptions_Number[5].def;

  _valueIndependent = 1;
  _valueView = -1;
  _valueTimeStep = -1;
  _orientation = GMSH_LevelsetPlugin::SPHERE;

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  return GMSH_LevelsetPlugin::execute(v1);
}
