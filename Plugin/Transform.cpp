// $Id: Transform.cpp,v 1.2 2001-08-06 09:44:22 geuzaine Exp $

#include "Plugin.h"
#include "Transform.h"
#include "List.h"
#include "Views.h"

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
  { GMSH_FULLRC, "iView" , NULL , 1. }
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterTransformPlugin ()
  {
    return new GMSH_TransformPlugin (TransformOptions_Number[0].def,
				     TransformOptions_Number[1].def,
				     TransformOptions_Number[2].def,
				     TransformOptions_Number[3].def,
				     TransformOptions_Number[4].def,
				     TransformOptions_Number[5].def,
				     TransformOptions_Number[6].def,
				     TransformOptions_Number[7].def,
				     TransformOptions_Number[8].def,
				     (int)TransformOptions_Number[9].def);
  }
}


GMSH_TransformPlugin::GMSH_TransformPlugin(double d11, double d12, double d13,
					   double d21, double d22, double d23,
					   double d31, double d32, double d33,
					   int i)
{
  mat[0][0] = d11; mat[0][1] = d12; mat[0][2] = d13;
  mat[1][0] = d21; mat[1][1] = d22; mat[1][2] = d23;
  mat[2][0] = d31; mat[2][1] = d32; mat[2][2] = d33;
  iView = i;
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

extern List_T *Post_ViewList;

Post_View *GMSH_TransformPlugin::execute (Post_View *v)
{
  Post_View *vv;

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

  if(v)
    vv = v;
  else{
    if(List_Nbr(Post_ViewList) < iView){
      Msg(WARNING,"Plugin CutTransform, view %d not loaded",iView);
      return 0;
    }
    vv = (Post_View*)List_Pointer_Test(Post_ViewList,iView-1);
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
