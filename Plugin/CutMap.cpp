// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "CutMap.h"
#include "Context.h"

extern Context_T CTX;

StringXNumber CutMapOptions_Number[] = {
  {GMSH_FULLRC, "A", GMSH_CutMapPlugin::callbackA, 0.},
  {GMSH_FULLRC, "dTimeStep", NULL, -1.},
  {GMSH_FULLRC, "dView", NULL, -1.},
  {GMSH_FULLRC, "ExtractVolume", GMSH_CutMapPlugin::callbackVol, 0.},
  {GMSH_FULLRC, "RecurLevel", GMSH_CutMapPlugin::callbackRecur, 4},
  {GMSH_FULLRC, "TargetError", GMSH_CutMapPlugin::callbackTarget, 0},
  {GMSH_FULLRC, "iView", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterCutMapPlugin()
  {
    return new GMSH_CutMapPlugin();
  }
}

double GMSH_CutMapPlugin::callbackA(int num, int action, double value)
{
  double min = 0., max = 1.;
  if(action > 0){
    int iview = (int)CutMapOptions_Number[6].def;
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

double GMSH_CutMapPlugin::callbackVol(int num, int action, double value)
{
  switch(action){ // configure the input field
  case 1: return 1.;
  case 2: return -1.;
  case 3: return 1.;
  default: break;
  }
  return 0.;
}

double GMSH_CutMapPlugin::callbackRecur(int num, int action, double value)
{
  switch(action){ // configure the input field
  case 1: return 1.;
  case 2: return 0.;
  case 3: return 10.;
  default: break;
  }
  return 0.;
}

double GMSH_CutMapPlugin::callbackTarget(int num, int action, double value)
{
  switch(action){ // configure the input field
  case 1: return 0.01;
  case 2: return 0.;
  case 3: return 1.;
  default: break;
  }
  return 0.;
}

void GMSH_CutMapPlugin::getName(char *name) const
{
  strcpy(name, "Cut Map");
}

void GMSH_CutMapPlugin::getInfos(char *author, char *copyright,
                                 char *help_text) const
{
  strcpy(author, "C. Geuzaine, J.-F. Remacle");
  strcpy(copyright, "C. Geuzaine, J.-F. Remacle");
  strcpy(help_text,
         "Plugin(CutMap) extracts the isosurface of value\n"
         "`A' from the view `iView' and draws the\n"
         "`dTimeStep'-th value of the view `dView' on the\n"
         "isosurface. If `iView' < 0, the plugin is run\n"
         "on the current view. If `dTimeStep' < 0, the\n"
         "plugin uses, for each time step in `iView', the\n"
         "corresponding time step in `dView'. If `dView'\n"
         "< 0, the plugin uses `iView' as the value source.\n"
         "If `ExtractVolume' is nonzero, the plugin\n" 
         "extracts the isovolume with values greater (if\n"
         "`ExtractVolume' > 0) or smaller (if `ExtractVolume'\n"
         "< 0) than the isosurface `A'.\n"
         "\n"
         "Plugin(CutMap) creates as many views as there\n"
         "are time steps in `iView'.\n");
}

int GMSH_CutMapPlugin::getNbOptions() const
{
  return sizeof(CutMapOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_CutMapPlugin::getOption(int iopt)
{
  return &CutMapOptions_Number[iopt];
}

void GMSH_CutMapPlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "CutMap failed...");
}

double GMSH_CutMapPlugin::levelset(double x, double y, double z, double val) const
{
  // we must look into the map for Map(x,y,z) - A
  // this is the case when the map is the same as the view,
  // the result is the extraction of isovalue A
  return val - CutMapOptions_Number[0].def;
}

PView *GMSH_CutMapPlugin::execute(PView *v)
{
  int iView = (int)CutMapOptions_Number[6].def;
  _valueIndependent = 0;
  _valueView = (int)CutMapOptions_Number[2].def;
  _valueTimeStep = (int)CutMapOptions_Number[1].def;
  _extractVolume = (int)CutMapOptions_Number[3].def;
  _recurLevel = (int)CutMapOptions_Number[4].def;
  _targetError = CutMapOptions_Number[5].def;
  _orientation = GMSH_LevelsetPlugin::MAP;
  
  PView *v1 = getView(iView, v);
  if(!v1) return v;

  return GMSH_LevelsetPlugin::execute(v1);
}
