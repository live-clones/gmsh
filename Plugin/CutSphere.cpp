// $Id: CutSphere.cpp,v 1.9 2001-07-31 18:07:57 geuzaine Exp $

#include <string.h>
#include "CutSphere.h"
#include "List.h"

StringXNumber CutSphereOptions_Number[] = {
  { GMSH_FULLRC, "Xc" , NULL , 0. },
  { GMSH_FULLRC, "Yc" , NULL , 0. },
  { GMSH_FULLRC, "Zc" , NULL , 0. },
  { GMSH_FULLRC, "R" , NULL , 0.25 },
  { GMSH_FULLRC, "ViewNumber" , NULL , 1. }
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterCutSpherePlugin ()
  {
    return new GMSH_CutSpherePlugin (CutSphereOptions_Number[0].def,
				     CutSphereOptions_Number[1].def,
				     CutSphereOptions_Number[2].def,
				     CutSphereOptions_Number[3].def);
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
  strcpy(help_text,
	 "Cuts a 3D scalar view with the sphere\n"
	 "(X-Xc)^2 + (Y-Yc)^2 + (Z-Zc)^2  = R^2.\n"
	 "Script name: Plugin(CutSphere).");
}

int GMSH_CutSpherePlugin::getNbOptions() const
{
  return sizeof(CutSphereOptions_Number)/sizeof(StringXNumber);
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

extern List_T *Post_ViewList;

Post_View *GMSH_CutSpherePlugin::execute (Post_View *v)
{

  a = CutSphereOptions_Number[0].def;
  b = CutSphereOptions_Number[1].def;
  c = CutSphereOptions_Number[2].def;
  r = CutSphereOptions_Number[3].def;
  int iView = (int)CutSphereOptions_Number[4].def;

  if(v)
    return GMSH_LevelsetPlugin::execute(v);
  else{
    if(List_Nbr(Post_ViewList) < iView){
      Msg(WARNING,"Plugin CutSphere, view %d not loaded\n",iView);
      return 0;
    }
    return GMSH_LevelsetPlugin::execute((Post_View*)List_Pointer_Test(Post_ViewList,iView-1));
  }
}
