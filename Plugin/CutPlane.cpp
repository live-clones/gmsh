#include "CutPlane.h"

/*
  Plugin Entry : GMSH_RegisterPlugin
 */

// that's the bad part of the story ...

double opt_cut_plane_A(OPT_ARGS_NUM)
{
}

StringXNumber CutPlaneOptions_Number[] = {
  { GMSH_FULLRC, "A" , opt_cut_plane_A , 1. },
  { GMSH_FULLRC, "B" , opt_cut_plane_A , 1. },
  { GMSH_FULLRC, "C" , opt_cut_plane_A , 1. },
  { GMSH_FULLRC, "D" , opt_cut_plane_A , 1. }
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterCutPlanePlugin ()
  {
    return new GMSH_CutPlanePlugin (1.0,0.0,0.0,0.01);
  }
}


GMSH_CutPlanePlugin::GMSH_CutPlanePlugin(double A, double B, double C, double D)
  :a(A),b(B),c(C),d(D)
{
}

void GMSH_CutPlanePlugin::getName(char *name) const
{
  strcpy(name,"Cut Plane");
}

void GMSH_CutPlanePlugin::getInfos(char *author, char *copyright, char *help_text) const
{
  strcpy(author,"J.-F. Remacle (remacle@scorec.rpi.edu)");
  strcpy(copyright,"DGR (www.multiphysics.com)");
  strcpy(help_text,"This Plugins cuts a view \n with a plane a x + b y + c z + d = 0\n");
}

int GMSH_CutPlanePlugin::getNbOptions() const
{
  return 4;
}

void GMSH_CutPlanePlugin:: GetOption (int iopt, StringXNumber *option) const
{
  *option = CutPlaneOptions_Number[iopt];
}

void GMSH_CutPlanePlugin::CatchErrorMessage (char *errorMessage) const
{
  strcpy(errorMessage,"CutPlane Failed...");
}

double GMSH_CutPlanePlugin :: levelset (double x, double y, double z) const
{
  return a * x + b * y + c * z + d;
}







