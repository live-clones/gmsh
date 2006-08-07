// $Id: Mesh.cpp,v 1.156 2006-08-07 22:02:30 geuzaine Exp $
//
// Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
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

#include "Gmsh.h"
#include "GmshUI.h"
#include "GModel.h"
#include "Draw.h"
#include "Context.h"
#include "VertexArray.h"
#include "gl2ps.h"

extern GModel *GMODEL;
extern Context_T CTX;

class drawMeshGFace 
{
public :
  void operator () (GFace *s)
  {  
    if(!(s->drawAttributes.Visible & VIS_MESH))
      return;
    
    if(CTX.render_mode == GMSH_SELECT) {
      glPushName(2);
      glPushName(s->tag());
    }

    glBegin(GL_TRIANGLES);
    for(unsigned int i = 0; i < s->triangles.size(); i++){
      MTriangle *t = s->triangles[i];
      for(int j = 0; j < 3; j++){
	MVertex *v = t->getVertex(j);
	glVertex3d(v->x(), v->y(), v->z());
      }
    }
    glEnd();

    if(CTX.render_mode == GMSH_SELECT) {
      glPopName();
      glPopName();
    }
  }
};

void Draw_Mesh()
{
  if(!GMODEL || !CTX.mesh.draw) return;
  
  glPointSize(CTX.mesh.point_size);
  gl2psPointSize(CTX.mesh.point_size * CTX.print.eps_point_size_factor);

  glLineWidth(CTX.mesh.line_width);
  gl2psLineWidth(CTX.mesh.line_width * CTX.print.eps_line_width_factor);
  
  if(CTX.mesh.light_two_side)
    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
  else
    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
  
  for(int i = 0; i < 6; i++)
    if(CTX.clip[i] & 2) 
      glEnable((GLenum)(GL_CLIP_PLANE0 + i));
    else
      glDisable((GLenum)(GL_CLIP_PLANE0 + i));
  
  /*
  if(CTX.mesh.changed){
    if(GMODEL->normals) delete GMODEL->normals;
    GMODEL->normals = new smooth_normals(CTX.mesh.angle_smooth_normals);
  }
  */
  
  if(CTX.mesh.surfaces_faces || CTX.mesh.surfaces_edges)
    std::for_each(GMODEL->firstFace(), GMODEL->lastFace(), drawMeshGFace());

  CTX.mesh.changed = 0;
  
  for(int i = 0; i < 6; i++)
    glDisable((GLenum)(GL_CLIP_PLANE0 + i));
}

// this routine is only used to display the interactive construction
// of the 2D aniso mesh
void draw_triangle_overlay(double r, double g, double b,
			   double *v1, double *v2, double *v3)
{
  SetOpenglContext();
  InitProjection();
  InitPosition();
  glDisable(GL_DEPTH_TEST);
  glDrawBuffer(GL_FRONT);
  glColor3f(r, g, b);
  glBegin(GL_LINE_LOOP);
  glVertex3dv(v1);
  glVertex3dv(v2);
  glVertex3dv(v3);
  glEnd();
  glFlush();
  glDrawBuffer(GL_BACK);
  glEnable(GL_DEPTH_TEST);
}
