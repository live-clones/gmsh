// $Id: CutCurve.cpp,v 1.1 2004-06-15 16:17:58 remacle Exp $
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

#include "OctreePost.h"
#include "CutCurve.h"
#include "List.h"
#include "Context.h"
#include "Views.h"
#include "Message.h"

extern Context_T CTX;


GMSH_CutCurvePlugin::GMSH_CutCurvePlugin()
{
  ;
}

Post_View * GMSH_CutCurvePlugin::GenerateView(Post_View * v) const 
{
  Post_View * View = BeginView(1);

  double *VALUES = new double [9*v->NbTimeStep];
  OctreePost o(v);

  for(int i = 0; i < getNbPoints(); ++i){
    const double xi = (double)(i)/(double)(getNbPoints()-1);
    double x,y,z;
    getPoint (xi,x,y,z);
    if(v->NbSS || v->NbSH || v->NbST || v->NbSQ){
      List_Add(View->SP, &x);
      List_Add(View->SP, &y);
      List_Add(View->SP, &z);
      View->NbSP++;
      o.searchScalar(x, y, z, VALUES);
      for(int k = 0; k < v->NbTimeStep; ++k){
	List_Add(View->SP, &VALUES[k]);	      
      }
    }
  }
  char name[1024], filename[1024];
  sprintf(name, "%s_CutCurve", v->Name);
  sprintf(filename, "%s_CutCurve.pos", v->Name);
  EndView(View, v->NbTimeStep, filename, name);
  delete [] VALUES;
  return View;
}

