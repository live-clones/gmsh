// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "Isosurface.h"
#include "Context.h"

StringXNumber IsosurfaceOptions_Number[] = {
  {GMSH_FULLRC, "Value", GMSH_IsosurfacePlugin::callbackValue, 0.},
  {GMSH_FULLRC, "ExtractVolume", GMSH_IsosurfacePlugin::callbackVol, 0.},
  {GMSH_FULLRC, "RecurLevel", GMSH_IsosurfacePlugin::callbackRecur, 4},
  {GMSH_FULLRC, "TargetError", GMSH_IsosurfacePlugin::callbackTarget, 0},
  {GMSH_FULLRC, "View", NULL, -1.},
  {GMSH_FULLRC, "OtherTimeStep", NULL, -1.},
  {GMSH_FULLRC, "OtherView", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterIsosurfacePlugin()
  {
    return new GMSH_IsosurfacePlugin();
  }
}

double GMSH_IsosurfacePlugin::callbackValue(int num, int action, double value)
{
  double min = 0., max = 1.;
  if(action > 0){
    int iview = (int)IsosurfaceOptions_Number[4].def;
    if(iview < 0) iview = num;
    if(iview >= 0 && iview < (int)PView::list.size()){
      min = PView::list[iview]->getData()->getMin();
      max = PView::list[iview]->getData()->getMax();
    }
  }
  switch(action){ // configure the input field
  case 1: return (min - max) / 200.;
  case 2: return min;
  case 3: return max;
  default: break;
  }
  return 0.;
}

double GMSH_IsosurfacePlugin::callbackVol(int num, int action, double value)
{
  switch(action){ // configure the input field
  case 1: return 1.;
  case 2: return -1.;
  case 3: return 1.;
  default: break;
  }
  return 0.;
}

double GMSH_IsosurfacePlugin::callbackRecur(int num, int action, double value)
{
  switch(action){ // configure the input field
  case 1: return 1.;
  case 2: return 0.;
  case 3: return 10.;
  default: break;
  }
  return 0.;
}

double GMSH_IsosurfacePlugin::callbackTarget(int num, int action, double value)
{
  switch(action){ // configure the input field
  case 1: return 0.01;
  case 2: return 0.;
  case 3: return 1.;
  default: break;
  }
  return 0.;
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
    "If `View' < 0, the plugin is run on the current view.\n\n"
    "Plugin(Isosurface) creates as many views as there are "
    "time steps in `View'.";
}

int GMSH_IsosurfacePlugin::getNbOptions() const
{
  return sizeof(IsosurfaceOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_IsosurfacePlugin::getOption(int iopt)
{
  return &IsosurfaceOptions_Number[iopt];
}

double GMSH_IsosurfacePlugin::levelset(double x, double y, double z, double val) const
{
  // we must look into the map for Map(x,y,z) - Value
  // this is the case when the map is the same as the view,
  // the result is the extraction of isovalue Value
  return val - IsosurfaceOptions_Number[0].def;
}

PView *GMSH_IsosurfacePlugin::execute(PView *v)
{
  int iView = (int)IsosurfaceOptions_Number[4].def;
  _valueIndependent = 0;
  _extractVolume = (int)IsosurfaceOptions_Number[1].def;
  _recurLevel = (int)IsosurfaceOptions_Number[2].def;
  _targetError = IsosurfaceOptions_Number[3].def;
  _valueTimeStep = (int)IsosurfaceOptions_Number[5].def;
  _valueView = (int)IsosurfaceOptions_Number[6].def;
  _orientation = GMSH_LevelsetPlugin::MAP;
  
  PView *v1 = getView(iView, v);
  if(!v1) return v;

  return GMSH_LevelsetPlugin::execute(v1);
}
