// $Id: Transform.cpp,v 1.8 2001-10-29 08:52:21 geuzaine Exp $

#include "Plugin.h"
#include "Transform.h"
#include "List.h"
#include "Views.h"
#include "Context.h"

extern Context_T CTX;

StringXNumber TransformOptions_Number[] = {
  { GMSH_FULLRC, "A11" , NULL , 1. },
  { GMSH_FULLRC, "A12" , NULL , 0. },
  { GMSH_FULLRC, "A13" , NULL , 0. },
  { GMSH_FULLRC, "A21" , NULL , 0. },
  { GMSH_FULLRC, "A22" , NULL , 1. },
  { GMSH_FULLRC, "A23" , NULL , 0. },
  { GMSH_FULLRC, "A31" , NULL , 0. },
  { GMSH_FULLRC, "A32" , NULL , 0. },
  { GMSH_FULLRC, "A33" , NULL , 1. },
  { GMSH_FULLRC, "iView" , NULL , -1. }
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterTransformPlugin ()
  {
    return new GMSH_TransformPlugin ();
  }
}


GMSH_TransformPlugin::GMSH_TransformPlugin()
{
}

void GMSH_TransformPlugin::getName(char *name) const
{
  strcpy(name,"Transform");
}

void GMSH_TransformPlugin::getInfos(char *author, char *copyright, char *help_text) const
{
  strcpy(author, "C. Geuzaine (geuz@geuz.org)");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text, 
	 "Transforms a view by the matrix [ [A11 A12 A13] [A21 A22 A23] [A31 A32 A33] ].\n"
	 "Script name: Plugin(Transform).");
}

int GMSH_TransformPlugin::getNbOptions() const
{
  return sizeof(TransformOptions_Number)/sizeof(StringXNumber);
}

StringXNumber *GMSH_TransformPlugin:: GetOption (int iopt)
{
  return &TransformOptions_Number[iopt];
}

void GMSH_TransformPlugin::CatchErrorMessage (char *errorMessage) const
{
  strcpy(errorMessage,"Transform failed...");
}

Post_View *GMSH_TransformPlugin::execute (Post_View *v)
{
  Post_View *vv;
  double mat[3][3];

  mat[0][0] = TransformOptions_Number[0].def;
  mat[0][1] = TransformOptions_Number[1].def;
  mat[0][2] = TransformOptions_Number[2].def;
  mat[1][0] = TransformOptions_Number[3].def;
  mat[1][1] = TransformOptions_Number[4].def;
  mat[1][2] = TransformOptions_Number[5].def;
  mat[2][0] = TransformOptions_Number[6].def;
  mat[2][1] = TransformOptions_Number[7].def;
  mat[2][2] = TransformOptions_Number[8].def;

  int iView = (int)TransformOptions_Number[9].def;

  if(v && iView < 0)
    vv = v;
  else{
    if(!v && iView < 0) iView = 0;
    if(!(vv = (Post_View*)List_Pointer_Test(CTX.post.list,iView))){
      Msg(WARNING,"View[%d] does not exist",iView);
      return 0;
    }
  }
  
  vv->transform(mat);
  return vv;
}

void GMSH_TransformPlugin::Run ()
{
  execute(0);
}

void GMSH_TransformPlugin::Save ()
{
}
