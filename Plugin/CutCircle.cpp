// $Id: CutCircle.cpp,v 1.1 2004-06-15 16:17:58 remacle Exp $
//
// Copyright (C) 1997-2004 C. Geuzaine, J.-F. Remacle
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
// Please report all bugs and problems to <gmsh@geuz.org>.

#include "CutCircle.h"
#include "List.h"
#include "Context.h"
#include <math.h>

extern Context_T CTX;

StringXNumber CutCircleOptions_Number[] = {
  {GMSH_FULLRC, "Xc", NULL, 0.},
  {GMSH_FULLRC, "Yc", NULL, 0.},
  {GMSH_FULLRC, "Zc", NULL, 0.},
  {GMSH_FULLRC, "R", NULL,  1},
  {GMSH_FULLRC, "nbPoints", NULL,  360},
  {GMSH_FULLRC, "iView", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterCutCirclePlugin()
  {
    return new GMSH_CutCirclePlugin();
  }
}


GMSH_CutCirclePlugin::GMSH_CutCirclePlugin()
{
  ;
}

void GMSH_CutCirclePlugin::getName(char *name) const
{
  strcpy(name, "Cut circle");
}

void GMSH_CutCirclePlugin::getInfos(char *author, char *copyright,
                                   char *help_text) const
{
  strcpy(author, "J.-F. Remacle (remacle@gce.ucl.ac.be)");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
         "Plugin(CutCircle) cuts the view `iView' with\n"
	 "the circle centered at Xc,Yc,Zc and of Radius R If\n"
	 "`iView' < 0, the plugin is run on the current\n"
	 "view.\n"
	 "\n"
	 "Plugin(CutCircle) creates one new view.\n");
}

int GMSH_CutCirclePlugin::getNbOptions() const
{
  return sizeof(CutCircleOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_CutCirclePlugin::getOption(int iopt)
{
  return &CutCircleOptions_Number[iopt];
}

void GMSH_CutCirclePlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "CutCircle failed...");
}

void GMSH_CutCirclePlugin::getPoint(const double &u, double &x, double &y, double &z) const
{
  const double Xc =CutCircleOptions_Number[0].def;
  const double Yc =CutCircleOptions_Number[1].def;
  const double Zc =CutCircleOptions_Number[2].def;
  const double R  =CutCircleOptions_Number[3].def;

  const double theta = u * 2 * 3.1415926;
  x = Xc + R * cos (theta);
  y = Yc + R * sin (theta);
  z = 0.0;
}

int GMSH_CutCirclePlugin::getNbPoints() const
{
  return (int)CutCircleOptions_Number[4].def;
}

Post_View *GMSH_CutCirclePlugin::execute(Post_View * v)
{
  int iView = (int)CutCircleOptions_Number[5].def;

  if(iView < 0)
    iView = v ? v->Index : 0;

  if(!List_Pointer_Test(CTX.post.list, iView)) {
    Msg(GERROR, "View[%d] does not exist", iView);
    return v;
  }

  Post_View *v1 = (Post_View*)List_Pointer(CTX.post.list, iView);

  return GMSH_CutCurvePlugin:: GenerateView(v1);
}
