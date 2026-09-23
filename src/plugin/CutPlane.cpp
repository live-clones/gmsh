// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include "CutPlane.h"
#include "Context.h"

#if defined(HAVE_OPENGL)
#include "drawContext.h"
#endif

GMSH_CutPlanePlugin::GMSH_CutPlanePlugin()
  : GMSH_LevelsetPlugin({{GMSH_FULLRC, "A", nullptr, 1., ""},
                         {GMSH_FULLRC, "B", nullptr, 0., ""},
                         {GMSH_FULLRC, "C", nullptr, 0., ""},
                         {GMSH_FULLRC, "D", nullptr, -0.01, ""},
                         {GMSH_FULLRC, "ExtractVolume", nullptr, 0, ""},
                         {GMSH_FULLRC, "RecurLevel", nullptr, 3, ""},
                         {GMSH_FULLRC, "TargetError", nullptr, 1e-3, ""},
                         {GMSH_FULLRC, "View", nullptr, -1., ""},
                         {GMSH_FULLRC, "Visible", nullptr, 1., ""}})
{
}

void GMSH_CutPlanePlugin::drawPreview(void *context)
{
#if defined(HAVE_OPENGL)
  int num = (int)option(7);
  drawContext *ctx = (drawContext *)context;
  if(num < 0) num = _iview;
  if(num >= 0 && num < (int)PView::list.size()) {
    gmshColor4ubv((GLubyte *)&CTX::instance()->color.fg);
    gmshLineWidth((float)CTX::instance()->lineWidth);
    SBoundingBox3d bb = PView::list[num]->getData()->getBoundingBox();
    ctx->drawPlaneInBoundingBox(bb.min().x(), bb.min().y(), bb.min().z(),
                                bb.max().x(), bb.max().y(), bb.max().z(),
                                option(0), option(1), option(2), option(3));
  }
#endif
}

bool GMSH_CutPlanePlugin::optionCallback(int iopt, int num, int action,
                                         double &value)
{
  if(action > 0) _iview = num;
  double lc = CTX::instance()->lc;
  switch(iopt) {
  case 0:
  case 1:
  case 2: return sliderOption(iopt, action, value, 0.01, -1, 1);
  case 3: return sliderOption(iopt, action, value, lc / 200., -lc, lc);
  case 4: return sliderOption(iopt, action, value, 1., -1, 1);
  case 5: return sliderOption(iopt, action, value, 1, 0, 10);
  case 6: return sliderOption(iopt, action, value, 0.01, 0., 1.);
  default: return false;
  }
}

std::string GMSH_CutPlanePlugin::getHelp() const
{
  return "Plugin(CutPlane) cuts the view `View' with "
         "the plane `A'*X + `B'*Y + `C'*Z + `D' = 0.\n\n"
         "If `ExtractVolume' is nonzero, the plugin extracts "
         "the elements on one side of the plane (depending "
         "on the sign of `ExtractVolume').\n\n"
         "If `View' < 0, the plugin is run on the current view. "
         "If `Visible' = 1, the plugin only cuts visible entities.\n\n"
         "Plugin(CutPlane) creates one new list-based view.";
}

double GMSH_CutPlanePlugin::levelset(double x, double y, double z,
                                     double val) const
{ return option(0) * x + option(1) * y + option(2) * z + option(3); }

PView *GMSH_CutPlanePlugin::execute(PView *v)
{
  int iView = (int)option(7);
  _ref[0] = option(0);
  _ref[1] = option(1);
  _ref[2] = option(2);
  _valueIndependent = 1;
  _valueView = -1;
  _valueTimeStep = -1;
  _orientation = GMSH_LevelsetPlugin::PLANE;
  _extractVolume = (int)option(4);
  _recurLevel = (int)option(5);
  _targetError = option(6);
  _visible = (int)option(8);

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  return GMSH_LevelsetPlugin::execute(v1);
}
