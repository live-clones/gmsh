// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <string.h>
#include "GmshConfig.h"
#include "CutSphere.h"
#include "Context.h"

#if defined(HAVE_OPENGL)
#include "drawContext.h"
#endif

GMSH_CutSpherePlugin::GMSH_CutSpherePlugin()
  : GMSH_LevelsetPlugin({{GMSH_FULLRC, "Xc", nullptr, 0., ""},
                         {GMSH_FULLRC, "Yc", nullptr, 0., ""},
                         {GMSH_FULLRC, "Zc", nullptr, 0., ""},
                         {GMSH_FULLRC, "R", nullptr, 0.25, ""},
                         {GMSH_FULLRC, "ExtractVolume", nullptr, 0., ""},
                         {GMSH_FULLRC, "RecurLevel", nullptr, 3, ""},
                         {GMSH_FULLRC, "TargetError", nullptr, 1e-3, ""},
                         {GMSH_FULLRC, "View", nullptr, -1., ""},
                         {GMSH_FULLRC, "Visible", nullptr, 1., ""}})
{
}

void GMSH_CutSpherePlugin::drawPreview(void *context)
{
#if defined(HAVE_OPENGL)
  bool fill = gmshPolygonFilled();
  gmshPolygonFill(false);
  gmshColor4ubv((GLubyte *)&CTX::instance()->color.fg);
  gmshLineWidth((float)CTX::instance()->lineWidth);
  drawContext *ctx = (drawContext *)context;
  ctx->drawSphere(option(3), option(0), option(1), option(2), 40, 40, 1);
  gmshPolygonFill(fill);
#endif
}

bool GMSH_CutSpherePlugin::optionCallback(int iopt, int num, int action,
                                          double &value)
{
  double lc = CTX::instance()->lc;
  switch(iopt) {
  case 0:
  case 1:
  case 2: return sliderOption(iopt, action, value, lc / 100., -2 * lc, 2 * lc);
  case 3: return sliderOption(iopt, action, value, lc / 100., 0., 2 * lc);
  case 4: return sliderOption(iopt, action, value, 1., -1., 1.);
  case 5: return sliderOption(iopt, action, value, 1, 0, 10);
  case 6: return sliderOption(iopt, action, value, 0.01, 0., 1.);
  default: return false;
  }
}

std::string GMSH_CutSpherePlugin::getHelp() const
{
  return "Plugin(CutSphere) cuts the view `View' with the "
         "sphere (X-`Xc')^2 + (Y-`Yc')^2 + (Z-`Zc')^2 = `R'^2.\n\n"
         "If `ExtractVolume' is nonzero, the plugin extracts "
         "the elements inside (if `ExtractVolume' < 0) or "
         "outside (if `ExtractVolume' > 0) the sphere.\n\n"
         "If `View' < 0, the plugin is run on the current view. "
         "If `Visible' = 1, the plugin only cuts visible entities.\n\n"
         "Plugin(CutSphere) creates one new list-based view.";
}

double GMSH_CutSpherePlugin::levelset(double x, double y, double z,
                                      double val) const
{
  double a = option(0);
  double b = option(1);
  double c = option(2);
  double r = option(3);
  return (x - a) * (x - a) + (y - b) * (y - b) + (z - c) * (z - c) - r * r;
}

PView *GMSH_CutSpherePlugin::execute(PView *v)
{
  int iView = (int)option(7);
  _ref[0] = option(0);
  _ref[1] = option(1);
  _ref[2] = option(2);
  _extractVolume = (int)option(4);
  _recurLevel = (int)option(5);
  _targetError = option(6);
  _visible = (int)option(8);

  _valueIndependent = 1;
  _valueView = -1;
  _valueTimeStep = -1;
  _orientation = GMSH_LevelsetPlugin::SPHERE;

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  return GMSH_LevelsetPlugin::execute(v1);
}
