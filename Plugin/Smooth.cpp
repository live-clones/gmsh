// $Id: Smooth.cpp,v 1.2 2001-08-06 09:44:22 geuzaine Exp $

#include "Plugin.h"
#include "Smooth.h"
#include "List.h"
#include "Views.h"

StringXNumber SmoothOptions_Number[] = {
  { GMSH_FULLRC, "iView" , NULL , 1. }
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterSmoothPlugin ()
  {
    return new GMSH_SmoothPlugin ((int)SmoothOptions_Number[0].def);
  }
}


GMSH_SmoothPlugin::GMSH_SmoothPlugin(int a)
  :iView(a)
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

  if(v)
    vv = v;
  else{
    if(List_Nbr(Post_ViewList) < iView){
      Msg(WARNING,"Plugin Smooth, view %d not loaded",iView);
      return 0;
    }
    vv = (Post_View*)List_Pointer_Test(Post_ViewList,iView-1);
  }

  Msg(INFO, "Executing Smooth on View num %d", vv->Num);
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
