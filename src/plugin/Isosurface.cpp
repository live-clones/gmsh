// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "Isosurface.h"
#include "Context.h"

GMSH_IsosurfacePlugin::GMSH_IsosurfacePlugin()
  : GMSH_LevelsetPlugin({{GMSH_FULLRC, "Value", nullptr, 0., ""},
                         {GMSH_FULLRC, "ExtractVolume", nullptr, 0., ""},
                         {GMSH_FULLRC, "RecurLevel", nullptr, 3, ""},
                         {GMSH_FULLRC, "TargetError", nullptr, 1e-3, ""},
                         {GMSH_FULLRC, "View", nullptr, -1., ""},
                         {GMSH_FULLRC, "OtherTimeStep", nullptr, -1., ""},
                         {GMSH_FULLRC, "OtherView", nullptr, -1., ""},
                         {GMSH_FULLRC, "Visible", nullptr, 1., ""}})
{
}

bool GMSH_IsosurfacePlugin::optionCallback(int iopt, int num, int action,
                                           double &value)
{
  double step, min, max;
  switch(iopt) {
  case 0: { // between the extrema of the view
    min = 0.;
    max = 1.;
    int iview = (int)option(4);
    if(iview < 0) iview = num;
    if(iview >= 0 && iview < (int)PView::list.size()) {
      min = PView::list[iview]->getData()->getMin();
      max = PView::list[iview]->getData()->getMax();
    }
    step = (max - min) / 200.;
  } break;
  case 1: step = 1., min = -1., max = 1.; break;
  case 2: step = 1., min = 0., max = 10.; break;
  case 3: step = 0.01, min = 0., max = 1.; break;
  default: return false;
  }
  switch(action) {
  case 1: value = step; break;
  case 2: value = min; break;
  case 3: value = max; break;
  default: option(iopt) = value; break; // nothing to preview
  }
  return true;
}

std::string GMSH_IsosurfacePlugin::getHelp() const
{
  return "Plugin(Isosurface) extracts the isosurface of value "
         "`Value' from the view `View', and draws the "
         "`OtherTimeStep'-th step of the view `OtherView' on "
         "this isosurface.\n\n"
         "If `ExtractVolume' is nonzero, the plugin extracts the "
         "isovolume with values greater (if `ExtractVolume' > 0) "
         "or smaller (if `ExtractVolume' < 0) than the isosurface "
         "`Value'.\n\n"
         "If `OtherTimeStep' < 0, the plugin uses, for each time "
         "step in `View', the corresponding time step in `OtherView'. "
         "If `OtherView' < 0, the plugin uses `View' as the value "
         "source.\n\n"
         "If `View' < 0, the plugin is run on the current view. "
         "If `Visible' = 1, the plugin only cuts visible entities.\n\n"
         "Plugin(Isosurface) creates as many list-based views as there "
         "are time steps in `View'.";
}

double GMSH_IsosurfacePlugin::levelset(double x, double y, double z,
                                       double val) const
{
  // we must look into the map for Map(x,y,z) - Value
  // this is the case when the map is the same as the view,
  // the result is the extraction of isovalue Value
  return val - option(0);
}

PView *GMSH_IsosurfacePlugin::execute(PView *v)
{
  int iView = (int)option(4);
  _valueIndependent = 0;
  _extractVolume = (int)option(1);
  _recurLevel = (int)option(2);
  _targetError = option(3);
  _valueTimeStep = (int)option(5);
  _valueView = (int)option(6);
  _orientation = GMSH_LevelsetPlugin::MAP;
  _visible = (int)option(7);

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  return GMSH_LevelsetPlugin::execute(v1);
}
