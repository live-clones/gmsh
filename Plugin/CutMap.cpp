#include "CutMap.h"

double opt_cut_map_A(OPT_ARGS_NUM)
{
  return 0;
}

StringXNumber CutMapOptions_Number[] = {
  { GMSH_FULLRC, "A" , opt_cut_map_A , 1. },
  { GMSH_FULLRC, "iView" , opt_cut_map_A , 1. }
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterCutMapPlugin ()
  {
    return new GMSH_CutMapPlugin (1.5,1);
  }
}


GMSH_CutMapPlugin::GMSH_CutMapPlugin(double a, int I)
  :A(a),iView(I)
{
}

void GMSH_CutMapPlugin::getName(char *name) const
{
  strcpy(name,"Cut Map");
}

void GMSH_CutMapPlugin::getInfos(char *author, char *copyright, char *help_text) const
{
  strcpy(author,"J.-F. Remacle (remacle@scorec.rpi.edu)");
  strcpy(copyright,"DGR (www.multiphysics.com)");
  strcpy(help_text,"This Plugins cuts a view \n with a plane (x-xc)^2 + (y-yc)^2 + (z-zc)^2  = r^20\n");
}

int GMSH_CutMapPlugin::getNbOptions() const
{
  return 2;
}

StringXNumber *GMSH_CutMapPlugin:: GetOption (int iopt)
{
  return &CutMapOptions_Number[iopt];
}

void GMSH_CutMapPlugin::CatchErrorMessage (char *errorMessage) const
{
  strcpy(errorMessage,"CutMap Failed...");
}

double GMSH_CutMapPlugin :: levelset (double x, double y, double z, double val) const
{
  // we must look into the map for A - Map(x,y,z)
  // this is the case when the map is the same as the view,
  // the result is the extraction of isovalue A
  return A - val;
}







