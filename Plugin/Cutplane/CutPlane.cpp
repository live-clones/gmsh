#include "CutPlane.h"
//#include "Views.h"
/*
  Plugin Entry : GMSH_RegisterPlugin
 */

GMSH_Plugin *GMSH_RegisterPlugin ()
{
  return new GMSH_CutPlanePlugin (1.0,0.0,0.0,0.0);
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
  strcpy(help_text,"This Plugins cuts a view with a plane a x + b y + c z + d = 0");
}

int GMSH_CutPlanePlugin::getNbOptions() const
{
  return 4;
}

void GMSH_CutPlanePlugin:: GetOption (int iopt, char *optionName, void *optionValue) const
{
  // geuz, t'es le specialiste des options, regarde comment
  // on pourrait faire Plugin.CutPlane.a = 1.0;
}

void GMSH_CutPlanePlugin::CatchErrorMessage (char *errorMessage) const
{
  strcpy(errorMessage,"CutPlane Failed...");
}

Post_View *GMSH_CutPlanePlugin::execute (Post_View *)
{
  throw this;
}

void GMSH_CutPlanePlugin::SetOption (char *optionName, void *optionValue)
{
}


