// $Id: CutSphere.cpp,v 1.5 2001-07-30 13:22:21 geuzaine Exp $

#include <string.h>
#include "CutSphere.h"

StringXNumber CutSphereOptions_Number[] = {
  { GMSH_FULLRC, "Xc" , NULL , 1. },
  { GMSH_FULLRC, "Yc" , NULL , 1. },
  { GMSH_FULLRC, "Zc" , NULL , 1. },
  { GMSH_FULLRC, "R" , NULL , 1. }
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterCutSpherePlugin ()
  {
    return new GMSH_CutSpherePlugin (0.0,0.0,0.0,.25);
  }
}


GMSH_CutSpherePlugin::GMSH_CutSpherePlugin(double A, double B, double C, double D)
  :a(A),b(B),c(C),r(D)
{
}

void GMSH_CutSpherePlugin::getName(char *name) const
{
  strcpy(name,"Cut Sphere");
}

void GMSH_CutSpherePlugin::getInfos(char *author, char *copyright, char *help_text) const
{
  strcpy(author,"J.-F. Remacle (remacle@scorec.rpi.edu)");
  strcpy(copyright,"DGR (www.multiphysics.com)");
  strcpy(help_text,"This Plugins cuts a view \n with a plane (x-xc)^2 + (y-yc)^2 + (z-zc)^2  = r^20\n");
}

int GMSH_CutSpherePlugin::getNbOptions() const
{
  return 4;
}

StringXNumber* GMSH_CutSpherePlugin:: GetOption (int iopt)
{
  return &CutSphereOptions_Number[iopt];
}

void GMSH_CutSpherePlugin::CatchErrorMessage (char *errorMessage) const
{
  strcpy(errorMessage,"CutSphere Failed...");
}

double GMSH_CutSpherePlugin :: levelset (double x, double y, double z, double val) const
{
  return (x-a)*(x-a) + (y-b)*(y-b) + (z-c)*(z-c) - r*r;
}







