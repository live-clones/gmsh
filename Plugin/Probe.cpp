// $Id: Probe.cpp,v 1.4 2004-12-28 17:24:25 geuzaine Exp $
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

#include "Probe.h"
#include "List.h"
#include "Context.h"

#if defined(HAVE_FLTK)
#include "GmshUI.h"
#include "Draw.h"
#endif

#include "OctreePost.h"

extern Context_T CTX;

int GMSH_ProbePlugin::iview = 0;

StringXNumber ProbeOptions_Number[] = {
  {GMSH_FULLRC, "X", GMSH_ProbePlugin::callbackX, 0.},
  {GMSH_FULLRC, "Y", GMSH_ProbePlugin::callbackY, 0.},
  {GMSH_FULLRC, "Z", GMSH_ProbePlugin::callbackZ, 0.},
  {GMSH_FULLRC, "iView", NULL, -1.},
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterProbePlugin()
  {
    return new GMSH_ProbePlugin();
  }
}

GMSH_ProbePlugin::GMSH_ProbePlugin()
{
  ;
}

void GMSH_ProbePlugin::draw()
{
#if defined(HAVE_FLTK)
  int num = (int)ProbeOptions_Number[3].def;
  if(num < 0) num = iview;
  Post_View **vv = (Post_View **)List_Pointer_Test(CTX.post.list, num);
  if(!vv) return;
  Post_View *v = *vv;
  double x = ProbeOptions_Number[0].def;
  double y = ProbeOptions_Number[1].def;
  double z = ProbeOptions_Number[2].def;
  glColor4ubv((GLubyte *) & CTX.color.fg);
  glLineWidth(CTX.line_width);
  gl2psLineWidth(CTX.line_width * CTX.print.eps_line_width_factor);
  if(x >= v->BBox[0] && x <= v->BBox[1] &&
     y >= v->BBox[2] && y <= v->BBox[3] &&
     z >= v->BBox[4] && z <= v->BBox[5]){
    // we're inside the bounding box: draw a large cross
    glBegin(GL_LINES);
    glVertex3d(v->BBox[0],y,z); glVertex3d(v->BBox[1],y,z);
    glVertex3d(x,v->BBox[2],z); glVertex3d(x,v->BBox[3],z);
    glVertex3d(x,y,v->BBox[4]); glVertex3d(x,y,v->BBox[5]);
    glEnd();
  }
  else{
    // draw a small marker
    double d = 10 * CTX.pixel_equiv_x / CTX.s[0];
    glBegin(GL_LINES);
    glVertex3d(x-d,y,z); glVertex3d(x+d,y,z);
    glVertex3d(x,y-d,z); glVertex3d(x,y+d,z);
    glVertex3d(x,y,z-d); glVertex3d(x,y,z+d);
    glEnd();
  }
#endif
}

double GMSH_ProbePlugin::callback(int num, int action, double value, double *opt)
{
  if(action > 0) iview = num;
  switch(action){ // configure the input field
  case 1: return CTX.lc/200.;
  case 2: return -CTX.lc;
  case 3: return CTX.lc;
  default: break;
  }
  *opt = value;
#if defined(HAVE_FLTK)
  DrawPlugin(draw);
#endif
  return 0.;
}

double GMSH_ProbePlugin::callbackX(int num, int action, double value)
{
  return callback(num, action, value, &ProbeOptions_Number[0].def);
}

double GMSH_ProbePlugin::callbackY(int num, int action, double value)
{
  return callback(num, action, value, &ProbeOptions_Number[1].def);
}

double GMSH_ProbePlugin::callbackZ(int num, int action, double value)
{
  return callback(num, action, value, &ProbeOptions_Number[2].def);
}

void GMSH_ProbePlugin::getName(char *name) const
{
  strcpy(name, "Probe");
}

void GMSH_ProbePlugin::getInfos(char *author, char *copyright,
                                   char *help_text) const
{
  strcpy(author, "C. Geuzaine (geuzaine@acm.caltech.edu)");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
         "Plugin(Probe) gets the value of the simplectic view\n"
	 "`iView' at the point (`X',`Y',`Z'). If `iView' < 0,\n"
	 "the plugin is run on the current view.\n"
	 "\n"
	 "Plugin(Probe) creates one new view.\n");
}

int GMSH_ProbePlugin::getNbOptions() const
{
  return sizeof(ProbeOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_ProbePlugin::getOption(int iopt)
{
  return &ProbeOptions_Number[iopt];
}

void GMSH_ProbePlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "Probe failed...");
}

Post_View *GMSH_ProbePlugin::execute(Post_View * v)
{
  double x = ProbeOptions_Number[0].def;
  double y = ProbeOptions_Number[1].def;
  double z = ProbeOptions_Number[2].def;
  int iView = (int)ProbeOptions_Number[3].def;
  
  if(iView < 0)
    iView = v ? v->Index : 0;
  
  if(!List_Pointer_Test(CTX.post.list, iView)) {
    Msg(GERROR, "View[%d] does not exist", iView);
    return v;
  }
  
  Post_View *v1 = *(Post_View **)List_Pointer(CTX.post.list, iView);
  Post_View *v2 = BeginView(1);

  double *val = new double[9*v1->NbTimeStep];
  OctreePost o(v1);

  if(o.searchScalar(x, y, z, val)){
    List_Add(v2->SP, &x);
    List_Add(v2->SP, &y);
    List_Add(v2->SP, &z);
    for(int i = 0; i < v1->NbTimeStep; i++)
      List_Add(v2->SP, &val[i]);
    v2->NbSP++;
  }

  double sizeElem;
  if(o.searchVector(x, y, z, val, &sizeElem)){
    List_Add(v2->VP, &x);
    List_Add(v2->VP, &y);
    List_Add(v2->VP, &z);
    for(int i = 0; i < v1->NbTimeStep; i++){
      List_Add(v2->VP, &val[3*i]);
      List_Add(v2->VP, &val[3*i+1]);
      List_Add(v2->VP, &val[3*i+2]);
    }
    v2->NbVP++;
  }

  // FIXME: do the tensor stuff

  delete [] val;
  
  // copy time data
  for(int i = 0; i < List_Nbr(v1->Time); i++)
    List_Add(v2->Time, List_Pointer(v1->Time, i));
  // finalize
  char name[1024], filename[1024];
  sprintf(name, "%s_Probe", v1->Name);
  sprintf(filename, "%s_Probe.pos", v1->Name);
  EndView(v2, 1, filename, name);
  return v2;
}
