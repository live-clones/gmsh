// $Id: Transform.cpp,v 1.21 2003-11-29 01:38:55 geuzaine Exp $
//
// Copyright (C) 1997-2003 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to "gmsh@geuz.org".

#include "Plugin.h"
#include "Transform.h"
#include "List.h"
#include "Views.h"
#include "Context.h"

extern Context_T CTX;

StringXNumber TransformOptions_Number[] = {
  {GMSH_FULLRC, "A11", NULL, 1.},
  {GMSH_FULLRC, "A12", NULL, 0.},
  {GMSH_FULLRC, "A13", NULL, 0.},
  {GMSH_FULLRC, "A21", NULL, 0.},
  {GMSH_FULLRC, "A22", NULL, 1.},
  {GMSH_FULLRC, "A23", NULL, 0.},
  {GMSH_FULLRC, "A31", NULL, 0.},
  {GMSH_FULLRC, "A32", NULL, 0.},
  {GMSH_FULLRC, "A33", NULL, 1.},
  {GMSH_FULLRC, "iView", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterTransformPlugin()
  {
    return new GMSH_TransformPlugin();
  }
}


GMSH_TransformPlugin::GMSH_TransformPlugin()
{
  ;
}

void GMSH_TransformPlugin::getName(char *name) const
{
  strcpy(name, "Transform");
}

void GMSH_TransformPlugin::getInfos(char *author, char *copyright,
                                    char *help_text) const
{
  strcpy(author, "C. Geuzaine (geuz@geuz.org)");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
         "Plugin(Transform) transforms the coordinates of\n"
	 "the nodes of the view 'iView' by the matrix\n"
         "['A11' 'A12' 'A13']\n"
	 "['A21' 'A22' 'A23']\n"
	 "['A31' 'A32' 'A33'].\n"
	 "If 'iView' < 0, the plugin is run on the current\n"
	 "view.\n"
	 "\n"
	 "Plugin(Transform) is executed in-place.\n");
}

int GMSH_TransformPlugin::getNbOptions() const
{
  return sizeof(TransformOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_TransformPlugin::getOption(int iopt)
{
  return &TransformOptions_Number[iopt];
}

void GMSH_TransformPlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "Transform failed...");
}

Post_View *GMSH_TransformPlugin::execute(Post_View * v)
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
  else {
    if(!v && iView < 0)
      iView = 0;
    if(!(vv = (Post_View *) List_Pointer_Test(CTX.post.list, iView))) {
      Msg(WARNING, "View[%d] does not exist", iView);
      return 0;
    }
  }

  vv->transform(mat);

  return 0;
}

