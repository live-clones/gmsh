// $Id: Mesh.cpp,v 1.160 2006-08-13 18:11:17 geuzaine Exp $
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
#include "OS.h"
#include "gl2ps.h"

extern GModel *GMODEL;
extern Context_T CTX;

#include "tc.h"

void renumberFaceVertices(GFace *f, List_T *xyz)
{
  std::list<GEdge*> ee = f->edges();
  std::list<GVertex*> vv = f->vertices();

  int num = 0;

  for(std::list<GVertex*>::const_iterator it = vv.begin(); it != vv.end(); ++it){
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++){
      MVertex *v = (*it)->mesh_vertices[i]; v->setNum(num++); 
      float x = v->x(), y = v->y(), z = v->z();
      List_Add(xyz, &x); List_Add(xyz, &y); List_Add(xyz, &z);
    }
  }
  for(std::list<GEdge*>::const_iterator it = ee.begin(); it != ee.end(); ++it){
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++){
      MVertex *v = (*it)->mesh_vertices[i]; v->setNum(num++);
      float x = v->x(), y = v->y(), z = v->z();
      List_Add(xyz, &x); List_Add(xyz, &y); List_Add(xyz, &z);
    }
  }
  for(unsigned int i = 0; i < f->mesh_vertices.size(); i++){
    MVertex *v = f->mesh_vertices[i]; v->setNum(num++);
    float x = v->x(), y = v->y(), z = v->z();
    List_Add(xyz, &x); List_Add(xyz, &y); List_Add(xyz, &z);
  }
}

// define this to draw the vertex array by indexing elements
//#define ELEM

class drawMeshGFace
{
public :
  void operator () (GFace *f)
  {  
    if(!f->getVisibility())
      return;
    
    if(CTX.render_mode == GMSH_SELECT) {
      glPushName(2);
      glPushName(f->tag());
    }



#if 0
    static int first = 1;
    static List_T *xyz;
    static std::vector<List_T*> idx, idx2;

    if(first){
      first = 0;
      printf("stripe surface %d\n", f->tag());
      xyz = List_Create(f->mesh_vertices.size(), 1000, sizeof(float));
      renumberFaceVertices(f, xyz);

      /*
      for(int i = 0; i < List_Nbr(xyz)/3; i+=3){
	float x, y, z;
	List_Read(xyz, i, &x);
	List_Read(xyz, i+1, &y);
	List_Read(xyz, i+2, &z);
	printf("xyz = %f %f %f\n", x, y, z);
      }
      */
      ACTCData *tc = actcNew();
      actcParami(tc, ACTC_OUT_MIN_FAN_VERTS, INT_MAX); // generate only strips
      //actcParami(tc, ACTC_OUT_MAX_PRIM_VERTS, INT_MAX); // optimum 12?
      actcParami(tc, ACTC_OUT_MAX_PRIM_VERTS, 100); // optimum 12?
      actcBeginInput(tc);
      for(unsigned int i = 0; i < f->triangles.size(); i++){
	actcAddTriangle(tc, 
			f->triangles[i]->getVertex(0)->getNum(),
			f->triangles[i]->getVertex(1)->getNum(),
			f->triangles[i]->getVertex(2)->getNum());
      }
      actcEndInput(tc);
      actcBeginOutput(tc);
      int strip, prim;
      unsigned int v1, v2, v3;
      strip = 0;
      while((prim = actcStartNextPrim(tc, &v1, &v2)) != ACTC_DATABASE_EMPTY) {
	strip++;
#ifdef ELEM
	idx.push_back(List_Create(100, 100, sizeof(unsigned int)));
	List_Add(idx[strip - 1], &v1);
	List_Add(idx[strip - 1], &v2);
#else
	idx2.push_back(List_Create(100, 100, sizeof(float)));
	List_Add(idx2[strip - 1], List_Pointer_Fast(xyz, 3*v1));
	List_Add(idx2[strip - 1], List_Pointer_Fast(xyz, 3*v1+1));
	List_Add(idx2[strip - 1], List_Pointer_Fast(xyz, 3*v1+2));
	List_Add(idx2[strip - 1], List_Pointer_Fast(xyz, 3*v2));
	List_Add(idx2[strip - 1], List_Pointer_Fast(xyz, 3*v2+1));
	List_Add(idx2[strip - 1], List_Pointer_Fast(xyz, 3*v2+2));
#endif
	while(actcGetNextVert(tc, &v3) != ACTC_PRIM_COMPLETE){
#ifdef ELEM
	  List_Add(idx[strip - 1], &v3);
#else
	  List_Add(idx2[strip - 1], List_Pointer_Fast(xyz, 3*v3));
	  List_Add(idx2[strip - 1], List_Pointer_Fast(xyz, 3*v3+1));
	  List_Add(idx2[strip - 1], List_Pointer_Fast(xyz, 3*v3+2));
#endif
	}
      }
      actcEndOutput(tc);
      actcDelete(tc);
      printf("stripe end\n");

    }

    glEnableClientState(GL_VERTEX_ARRAY);
#ifdef ELEM
    glVertexPointer(3, GL_FLOAT, 0, xyz->array);
    for(unsigned int i = 0; i < idx.size(); i++){
      //printf("strip %d\n", i);
      int n = List_Nbr(idx[i]);
      glColor4ubv((GLubyte *)&CTX.color.mesh.carousel[i % 20]);
      glDrawElements(GL_TRIANGLE_STRIP, n, GL_UNSIGNED_INT, idx[i]->array);
    }
#else
    for(unsigned int i = 0; i < idx2.size(); i++){
      //printf("strip %d\n", i);
      int n = List_Nbr(idx2[i]);
      glVertexPointer(3, GL_FLOAT, 0, idx2[i]->array);
      glColor4ubv((GLubyte *)&CTX.color.mesh.carousel[i % 20]);
      glDrawArrays(GL_TRIANGLE_STRIP, 0, n / 3);
    }
#endif
    glDisableClientState(GL_VERTEX_ARRAY);


#endif

    unsigned int col;
    if(f->getFlag() > 0){
      col = CTX.color.geom.surface_sel;
    }
    else if(CTX.mesh.color_carousel == 1){
      col = CTX.color.mesh.carousel[abs(f->tag() % 20)];
    }
    else if(CTX.mesh.color_carousel == 2){
      int n = 1;
      int np = f->physicals.size();
      if(np) n = f->physicals[np - 1];
      col = CTX.color.mesh.carousel[abs(n % 20)];
    }
    else if(CTX.mesh.color_carousel == 3){
      // partition
    }
    else
      col = CTX.color.mesh.triangle;
    glColor4ubv((GLubyte *)&col);

    glBegin(GL_TRIANGLES);
    for(unsigned int i = 0; i < f->triangles.size(); i++){
      MTriangle *t = f->triangles[i];
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
  if(!CTX.mesh.draw) return;
  
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
