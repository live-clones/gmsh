// $Id: SphericalRaise.cpp,v 1.6 2003-03-21 00:52:46 geuzaine Exp $
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
#include "SphericalRaise.h"
#include "List.h"
#include "Views.h"
#include "Context.h"
#include "Numeric.h"

extern Context_T CTX;

StringXNumber SphericalRaiseOptions_Number[] = {
  {GMSH_FULLRC, "Xc", NULL, 0.},
  {GMSH_FULLRC, "Yc", NULL, 0.},
  {GMSH_FULLRC, "Zc", NULL, 0.},
  {GMSH_FULLRC, "Raise", NULL, 1.},
  {GMSH_FULLRC, "iView", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterSphericalRaisePlugin()
  {
    return new GMSH_SphericalRaisePlugin();
  }
}


GMSH_SphericalRaisePlugin::GMSH_SphericalRaisePlugin()
{
  ;
}

void GMSH_SphericalRaisePlugin::getName(char *name) const
{
  strcpy(name, "Spherical raise");
}

void GMSH_SphericalRaisePlugin::getInfos(char *author, char *copyright,
                                         char *help_text) const
{
  strcpy(author, "C. Geuzaine (geuz@geuz.org)");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
         "SphericalRaise transforms the coordinates\n"
         "of the elements in a view according to the\n"
         "elements' associated values. Instead of\n"
         "transforming the coordinates along the X,\n"
         "Y, Z axes (as in Options->Offset->Raise),\n"
         "the raise is applied along the radius of\n"
         "a sphere centered at (Xc, Yc, Zc).\n"
         "Script name: Plugin(SphericalRaise).");
}

int GMSH_SphericalRaisePlugin::getNbOptions() const
{
  return sizeof(SphericalRaiseOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_SphericalRaisePlugin::GetOption(int iopt)
{
  return &SphericalRaiseOptions_Number[iopt];
}

void GMSH_SphericalRaisePlugin::CatchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "SphericalRaise failed...");
}

static void sphericalRaiseList(Post_View * v, List_T * list, int nbelm,
                               int nbvert, double center[3], double raise)
{
  double *x, *y, *z, *val, d[3], coef;
  int nb, i, j;

  if(nbelm)
    v->Changed = 1;
  else
    return;

  // for each element
  //   for each node
  //      compute d=(x-Xc,y-Yc,z-Zc)
  //      norm d
  //      get nodal value val at xyz
  //      compute (x,y,z)_new = (x,y,z)_old + raise*val*(dx,dy,dz)

  nb = List_Nbr(list) / nbelm;
  for(i = 0; i < List_Nbr(list); i += nb) {
    x = (double *)List_Pointer_Fast(list, i);
    y = (double *)List_Pointer_Fast(list, i + nbvert);
    z = (double *)List_Pointer_Fast(list, i + 2 * nbvert);
    val = (double *)List_Pointer_Fast(list, i + 3 * nbvert);
    for(j = 0; j < nbvert; j++) {
      d[0] = x[j] - center[0];
      d[1] = y[j] - center[1];
      d[2] = z[j] - center[2];
      norme(d);
      coef = raise * val[j];
      x[j] += coef * d[0];
      y[j] += coef * d[1];
      z[j] += coef * d[2];
    }
  }
}

static void sphericalRaise(Post_View * v, double center[3], double raise)
{
  sphericalRaiseList(v, v->SP, v->NbSP, 1, center, raise);
  sphericalRaiseList(v, v->SL, v->NbSL, 2, center, raise);
  sphericalRaiseList(v, v->ST, v->NbST, 3, center, raise);
  sphericalRaiseList(v, v->SQ, v->NbSQ, 4, center, raise);
  sphericalRaiseList(v, v->SS, v->NbSS, 4, center, raise);
  sphericalRaiseList(v, v->SH, v->NbSH, 8, center, raise);
  sphericalRaiseList(v, v->SI, v->NbSI, 6, center, raise);
  sphericalRaiseList(v, v->SY, v->NbSY, 5, center, raise);
}

Post_View *GMSH_SphericalRaisePlugin::execute(Post_View * v)
{
  Post_View *vv;
  double center[3], raise;

  center[0] = SphericalRaiseOptions_Number[0].def;
  center[1] = SphericalRaiseOptions_Number[1].def;
  center[2] = SphericalRaiseOptions_Number[2].def;
  raise = SphericalRaiseOptions_Number[3].def;

  int iView = (int)SphericalRaiseOptions_Number[4].def;

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

  sphericalRaise(vv, center, raise);
  return vv;
}

void GMSH_SphericalRaisePlugin::Run()
{
  execute(0);
}

void GMSH_SphericalRaisePlugin::Save()
{
  ;
}
