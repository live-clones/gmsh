// $Id: Smooth.cpp,v 1.6 2001-08-06 11:39:22 geuzaine Exp $

#include "Plugin.h"
#include "Smooth.h"
#include "List.h"
#include "Views.h"

StringXNumber SmoothOptions_Number[] = {
  { GMSH_FULLRC, "iView" , NULL , -1. }
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterSmoothPlugin ()
  {
    return new GMSH_SmoothPlugin();
  }
}


GMSH_SmoothPlugin::GMSH_SmoothPlugin()
{
}

void GMSH_SmoothPlugin::getName(char *name) const
{
  strcpy(name,"Smooth");
}

void GMSH_SmoothPlugin::getInfos(char *author, char *copyright, char *help_text) const
{
  strcpy(author, "C. Geuzaine (geuz@geuz.org)");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text, 
	 "Smoothes a discontinuous view by averaging all the values at each node.\n"
	 "Script name: Plugin(Smooth).");
}

int GMSH_SmoothPlugin::getNbOptions() const
{
  return sizeof(SmoothOptions_Number)/sizeof(StringXNumber);
}

StringXNumber *GMSH_SmoothPlugin:: GetOption (int iopt)
{
  return &SmoothOptions_Number[iopt];
}

void GMSH_SmoothPlugin::CatchErrorMessage (char *errorMessage) const
{
  strcpy(errorMessage,"Smooth failed...");
}

extern List_T *Post_ViewList;

Post_View *GMSH_SmoothPlugin::execute (Post_View *v)
{
  Post_View *vv;
  int iView = (int)SmoothOptions_Number[0].def;

  if(v && iView < 0)
    vv = v;
  else{
    if(!v && iView < 0) iView = 0;
    if(!(vv = (Post_View*)List_Pointer_Test(Post_ViewList,iView))){
      Msg(WARNING,"View[%d] does not exist",iView);
      return 0;
    }
  }

  vv->smooth();
  return vv;
}

void GMSH_SmoothPlugin::Run ()
{
  execute(0);
}

void GMSH_SmoothPlugin::Save ()
{
}
