// $Id: Mesh.cpp,v 1.169 2006-08-16 05:25:22 geuzaine Exp $
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
#include "MRep.h"
#include "OS.h"
#include "gl2ps.h"
#include "tc.h"

extern GModel *GMODEL;
extern Context_T CTX;

// General helper routines

static unsigned int getColor(GEntity *e, int forceColor, unsigned int color)
{
  if(forceColor) return color;
  
  if(e->getFlag() > 0){
    switch(e->dim()){
    case 0: return CTX.color.geom.point_sel;
    case 1: return CTX.color.geom.line_sel;
    case 2: return CTX.color.geom.surface_sel;
    default: return CTX.color.geom.volume_sel;
    }
  }
  else if(e->useColor())
    return e->getColor();
  else if(CTX.mesh.color_carousel == 1)
    return CTX.color.mesh.carousel[abs(e->tag() % 20)];
  else if(CTX.mesh.color_carousel == 2){
    int np = e->physicals.size();
    int p = np ? e->physicals[np - 1] : 0;
    return CTX.color.mesh.carousel[abs(p % 20)];
  }
  return color;
}

static double intersectCutPlane(MElement *ele, int *edges=0, int *faces=0)
{
  MVertex *v = ele->getVertex(0);
  double val = CTX.mesh.evalCutPlane(v->x(), v->y(), v->z());
  for(int i = 1; i < ele->getNumVertices(); i++){
    v = ele->getVertex(i);
    if(val * CTX.mesh.evalCutPlane(v->x(), v->y(), v->z()) <= 0){
      // the element intersects the cut plane
      if(CTX.mesh.cut_plane_as_surface){
	if(!*edges) *edges = CTX.mesh.surfaces_edges;
	if(!*faces) *faces = CTX.mesh.surfaces_faces;
      }
      return 1.;
    }
  }
  return val;
}

static int getLabelStep(int total)
{
  int step;
  if(CTX.mesh.label_frequency == 0.0) 
    step = total;
  else 
    step = (int)(100.0 / CTX.mesh.label_frequency);
  return (step > total) ? total : step;
}

template<class T>
static void drawLabels(GEntity *e, std::vector<T*> &elements, int labelStep,
		       int &labelNum, int forceColor, unsigned int color)
{
  unsigned col = getColor(e, forceColor, color);
  glColor4ubv((GLubyte *) & col);
  for(unsigned int i = 0; i < elements.size(); i++){
    MElement *ele = elements[i];
    labelNum++;
    if(labelNum % labelStep == 0) {
      SPoint3 pc = ele->barycenter();
      char str[256];
      if(CTX.mesh.label_type == 4)
	sprintf(str, "(%g,%g,%g)", pc.x(), pc.y(), pc.z());
      else if(CTX.mesh.label_type == 3)
	sprintf(str, "%d", ele->getPartition());
      else if(CTX.mesh.label_type == 2){
	int np = e->physicals.size();
	int p = np ? e->physicals[np - 1] : 0;
	sprintf(str, "%d", p);
      }
      else if(CTX.mesh.label_type == 1)
	sprintf(str, "%d", e->tag());
      else
	sprintf(str, "%d", ele->getNum());
      if(e->dim() == 1){
	double offset = 0.3 * (CTX.mesh.line_width + CTX.gl_fontsize) * CTX.pixel_equiv_x;
	glRasterPos3d(pc.x() + offset / CTX.s[0], 
		      pc.y() + offset / CTX.s[1], 
		      pc.z() + offset / CTX.s[2]);
      }
      else
	glRasterPos3d(pc.x(), pc.y(), pc.z());
      Draw_String(str);
    }
  }
}

template<class T>
static void drawNormals(std::vector<T*> &elements)
{
  glColor4ubv((GLubyte *) & CTX.color.mesh.normals);
  for(unsigned int i = 0; i < elements.size(); i++){
    SVector3 n = elements[i]->getFaceRep(0).normal();
    for(int j = 0; j < 3; j++)
      n[j] *= CTX.mesh.normals * CTX.pixel_equiv_x / CTX.s[j];
    SPoint3 pc = elements[i]->barycenter();
    Draw_Vector(CTX.vector_type, 0, CTX.arrow_rel_head_radius, 
		CTX.arrow_rel_stem_length, CTX.arrow_rel_stem_radius,
		pc.x(), pc.y(), pc.z(), n[0], n[1], n[2], CTX.mesh.light);
  }
}

template<class T>
static void drawTangents(std::vector<T*> &elements)
{
  glColor4ubv((GLubyte *) & CTX.color.mesh.tangents);
  for(unsigned int i = 0; i < elements.size(); i++){
    SVector3 t = elements[i]->getEdgeRep(0).tangent();
    for(int j = 0; j < 3; j++)
      t[j] *= CTX.mesh.tangents * CTX.pixel_equiv_x / CTX.s[j];
    SPoint3 pc = elements[i]->barycenter();
    Draw_Vector(CTX.vector_type, 0, CTX.arrow_rel_head_radius, 
		CTX.arrow_rel_stem_length, CTX.arrow_rel_stem_radius,
		pc.x(), pc.y(), pc.z(), t[0], t[1], t[2], CTX.mesh.light);
  }
}

static void drawVertices(GEntity *e)
{
  glColor4ubv((GLubyte *) & CTX.color.mesh.vertex);

  if(CTX.mesh.points) {
    if(CTX.mesh.point_type) {
      for(unsigned int i = 0; i < e->mesh_vertices.size(); i++){
	MVertex *v = e->mesh_vertices[i];
	Draw_Sphere(CTX.mesh.point_size, v->x(), v->y(), v->z(), CTX.mesh.light);
      }
    }
    else{
      glBegin(GL_POINTS);
      for(unsigned int i = 0; i < e->mesh_vertices.size(); i++){
	MVertex *v = e->mesh_vertices[i];
	glVertex3d(v->x(), v->y(), v->z());
      }
      glEnd();
    }
  }

  int np = e->physicals.size();
  int physical = np ? e->physicals[np - 1] : 0;
  const int labelStep = getLabelStep(e->mesh_vertices.size());
  int labelNum = 0;
  if(CTX.mesh.points_num) {
    for(unsigned int i = 0; i < e->mesh_vertices.size(); i++){
      MVertex *v = e->mesh_vertices[i];
      labelNum++;
      if(labelNum % labelStep == 0) {
	char str[256];
	if(CTX.mesh.label_type == 4)
	  sprintf(str, "(%g,%g,%g)", v->x(), v->y(), v->z());
	else if(CTX.mesh.label_type == 3)
	  sprintf(str, "NA");
	else if(CTX.mesh.label_type == 2)
	  sprintf(str, "%d", physical);
	else if(CTX.mesh.label_type == 1)
	  sprintf(str, "%d", e->tag());
	else
	  sprintf(str, "%d", v->getNum());
	double offset = 0.3 * (CTX.mesh.point_size + CTX.gl_fontsize) * CTX.pixel_equiv_x;
	glRasterPos3d(v->x() + offset / CTX.s[0],
		      v->y() + offset / CTX.s[1],
		      v->z() + offset / CTX.s[2]);
	Draw_String(str);
      }
    }
  }
}

template<class T>
static void drawBarycentricDual(std::vector<T*> &elements)
{
  glColor4ubv((GLubyte *) & CTX.color.fg);
  glEnable(GL_LINE_STIPPLE);
  glLineStipple(1, 0x0F0F);
  gl2psEnable(GL2PS_LINE_STIPPLE);
  glBegin(GL_LINES);
  for(unsigned int i = 0; i < elements.size(); i++){
    MElement *ele = elements[i];
    SPoint3 pc = ele->barycenter();
    if(ele->getDim() == 2){
      for(int j = 0; j < ele->getNumEdges(); j++){
	MEdge e = ele->getEdge(j);
	SPoint3 p = e.barycenter();
	glVertex3d(pc.x(), pc.y(), pc.z());
	glVertex3d(p.x(), p.y(), p.z());
      }
    }
    else if(ele->getDim() == 3){
      for(int j = 0; j < ele->getNumFaces(); j++){
	MFace f = ele->getFace(j);
	SPoint3 p = f.barycenter();
	glVertex3d(pc.x(), pc.y(), pc.z());
	glVertex3d(p.x(), p.y(), p.z());
	for(int k = 0; k < f.getNumVertices(); k++){
	  MEdge e(f.getVertex(k), (k == f.getNumVertices() - 1) ? 
		  f.getVertex(0) : f.getVertex(k + 1), ele);
	  SPoint3 pe = e.barycenter();
	  glVertex3d(p.x(), p.y(), p.z());
	  glVertex3d(pe.x(), pe.y(), pe.z());
	}
      }
    }
  }
  glEnd();
  glDisable(GL_LINE_STIPPLE);
  gl2psDisable(GL2PS_LINE_STIPPLE);
}

// Routines for filling and drawing the vertex arrays

template<class T>
static void addElementsInArrays(GEntity *e, VertexArray *va, std::vector<T*> &elements)
{
  for(unsigned int i = 0; i < elements.size(); i++){
    MElement *ele = elements[i];
    int part = ele->getPartition();
    if(CTX.mesh.quality_sup) {
      double q;
      if(CTX.mesh.quality_type == 2)
	q = ele->rhoShapeMeasure();
      else if(CTX.mesh.quality_type == 1)
	q = ele->etaShapeMeasure();
      else
	q = ele->gammaShapeMeasure();
      if(q < CTX.mesh.quality_inf || q > CTX.mesh.quality_sup) continue;
    }
    if(CTX.mesh.radius_sup) {
      double r = ele->maxEdge();
      if(r < CTX.mesh.radius_inf || r > CTX.mesh.radius_sup) continue;
    }
    if(CTX.mesh.use_cut_plane && !CTX.mesh.cut_plane_only_volume){
      if(intersectCutPlane(ele) < 0) continue;
    }
    if(ele->getNumFacesRep()){
      for(int j = 0; j < ele->getNumFacesRep(); j++){
	MFace fr = ele->getFaceRep(j);
	SVector3 n = fr.normal();
	SPoint3 pc;
	if(CTX.mesh.explode != 1.) pc = ele->barycenter();
	for(int k = 0; k < fr.getNumVertices(); k++){
	  MVertex *v = fr.getVertex(k);
	  SPoint3 p(v->x(), v->y(), v->z());
	  if(CTX.mesh.explode != 1.){
	    for(int l = 0; l < 3; l++)
	      p[l] = pc[l] + CTX.mesh.explode * (p[l] - pc[l]);
	  }
	  if(CTX.mesh.smooth_normals)
	    e->model()->normals->get(p[0], p[1], p[2], n[0], n[1], n[2]);
	  va->add(p[0], p[1], p[2], n[0], n[1], n[2],
		  CTX.color.mesh.carousel[abs(part % 20)]);
	}
      }
    }
    else{
      for(int j = 0; j < ele->getNumEdgesRep(); j++){
	MEdge er = ele->getEdgeRep(j);
	SPoint3 pc;
	if(CTX.mesh.explode != 1.) pc = ele->barycenter();
	for(int k = 0; k < er.getNumVertices(); k++){
	  MVertex *v = er.getVertex(k);
	  SPoint3 p(v->x(), v->y(), v->z());
	  if(CTX.mesh.explode != 1.){
	    for(int l = 0; l < 3; l++)
	      p[l] = pc[l] + CTX.mesh.explode * (p[l] - pc[l]);
	  }
	  va->add(p[0], p[1], p[2], CTX.color.mesh.carousel[abs(part % 20)]);
	}
      }
    }
  }
}

static void drawArrays(VertexArray *va, GLint type, bool useNormalArray, 
		       bool useColorArray, bool usePolygonOffset,
		       unsigned int uniformColor, bool drawOutline=false)
{
  if(!va) return;

  glVertexPointer(3, GL_FLOAT, 0, va->vertices->array);
  glNormalPointer(GL_BYTE, 0, va->normals->array);
  glColorPointer(4, GL_UNSIGNED_BYTE, 0, va->colors->array);
  
  glEnableClientState(GL_VERTEX_ARRAY);
  if(useNormalArray){
    glEnable(GL_LIGHTING);
    glEnableClientState(GL_NORMAL_ARRAY);
  }
  else
    glDisableClientState(GL_NORMAL_ARRAY);
  if(useColorArray)
    glEnableClientState(GL_COLOR_ARRAY);
  else{
    glDisableClientState(GL_COLOR_ARRAY);
    glColor4ubv((GLubyte *) & uniformColor);
  }
  
  if(usePolygonOffset) 
    glEnable(GL_POLYGON_OFFSET_FILL);
  
  if(drawOutline) 
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  
  glDrawArrays(type, 0, va->n());
  
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glDisable(GL_POLYGON_OFFSET_FILL);
  glDisable(GL_LIGHTING);
  
  glDisableClientState(GL_VERTEX_ARRAY);
  glDisableClientState(GL_NORMAL_ARRAY);
  glDisableClientState(GL_COLOR_ARRAY);
}

// GVertex drawing routines

class drawMeshGVertex {
 public:
  void operator () (GVertex *v)
  {  
    if(!v->getVisibility())
      return;
    
    if(CTX.render_mode == GMSH_SELECT) {
      glPushName(0);
      glPushName(v->tag());
    }

    if(CTX.mesh.points || CTX.mesh.points_num)
      drawVertices(v);

    if(CTX.render_mode == GMSH_SELECT) {
      glPopName();
      glPopName();
    }
  }
};

// GEdge drawing routines

class initMeshGEdge {
 public :
  void operator () (GEdge *e)
  {
    if(!e->getVisibility())
      return;

    if(!e->meshRep)
      e->meshRep = new MRepEdge(e);

    if(CTX.mesh.lines){
      if(e->meshRep->va_lines) delete e->meshRep->va_lines;
      e->meshRep->va_lines = new VertexArray(2, e->lines.size());
      addElementsInArrays(e, e->meshRep->va_lines, e->lines);
    }
  }
};

class drawMeshGEdge {
 public:
  void operator () (GEdge *e)
  {  
    if(!e->getVisibility())
      return;
    
    if(CTX.render_mode == GMSH_SELECT) {
      glPushName(1);
      glPushName(e->tag());
    }

    MRep *m = e->meshRep;

    if(CTX.mesh.lines)
      drawArrays(m->va_lines, GL_LINES, false, CTX.mesh.color_carousel == 3, 
		 false,  getColor(e, false, CTX.color.mesh.line));

    if(CTX.mesh.lines_num) {
      const int labelStep = getLabelStep(e->lines.size());
      int labelNum = 0;
      drawLabels(e, e->lines, labelStep, labelNum, false, CTX.color.mesh.line);
    }

    if(CTX.mesh.points || CTX.mesh.points_num)
      drawVertices(e);

    if(CTX.mesh.tangents)
      drawTangents(e->lines);

    if(CTX.render_mode == GMSH_SELECT) {
      glPopName();
      glPopName();
    }
  }
};

// GFace drawing routines

class initSmoothNormalsGFace {
 private:
  template<class T>
  void _addSmoothNormals(GFace *f, std::vector<T*> &elements)
  {
    for(unsigned int i = 0; i < elements.size(); i++){
      MElement *ele = elements[i];
      for(int j = 0; j < ele->getNumFacesRep(); j++){
	MFace fr = ele->getFaceRep(j);
	SVector3 n = fr.normal();
	SPoint3 pc;
	if(CTX.mesh.explode != 1.) pc = ele->barycenter();
	for(int k = 0; k < fr.getNumVertices(); k++){
	  MVertex *v = fr.getVertex(k);
	  SPoint3 p(v->x(), v->y(), v->z());
	  if(CTX.mesh.explode != 1.){
	    for(int l = 0; l < 3; l++)
	      p[l] = pc[l] + CTX.mesh.explode * (p[l] - pc[l]);
	  }
	  f->model()->normals->add(p[0], p[1], p[2], n[0], n[1], n[2]);
	}
      }
    }
  }
 public :
  void operator () (GFace *f)
  {
    _addSmoothNormals(f, f->triangles);
    _addSmoothNormals(f, f->quadrangles);
  }
};

class initMeshGFace {
 public :
  void operator () (GFace *f)
  {
    if(!f->getVisibility())
      return;

    if(!f->meshRep)
      f->meshRep = new MRepFace(f);

    //bool useEdges = true;
    bool useEdges = false;

    if(CTX.mesh.explode != 1. || CTX.mesh.quality_sup || CTX.mesh.radius_sup || 
       CTX.mesh.use_cut_plane)
      useEdges = false;

    for(unsigned int i = 0; i < f->triangles.size(); i++){
      if(!f->triangles[i]->getVisibility()){ useEdges = false; break; }
    }
    for(unsigned int i = 0; i < f->quadrangles.size(); i++){
      if(!f->quadrangles[i]->getVisibility()){ useEdges = false; break; }
    }
    
    if(useEdges) f->meshRep->generateEdges();

    // TODO: further optimizations are possible when useEdges is true:
    //
    // 1) store the unique vertices in the vertex array and
    //    glDrawElements() instead of glDrawArrays().
    // 2) we can use tc to stripe the triangles to create strips

    if(useEdges && CTX.mesh.surfaces_edges){
      if(f->meshRep->va_lines) delete f->meshRep->va_lines;
      f->meshRep->va_lines = new VertexArray(2, f->meshRep->edges.size());
      std::set<MEdge>::const_iterator it = f->meshRep->edges.begin();
      for(; it != f->meshRep->edges.end(); ++it){
	for(int i = 0; i < 2; i++){
	  MVertex *v = it->getVertex(i);
	  MElement *ele = it->getElement();
	  SVector3 n = ele->getFace(0).normal();
	  int part = ele->getPartition();
	  if(CTX.mesh.smooth_normals)
	    f->model()->normals->get(v->x(), v->y(), v->z(), n[0], n[1], n[2]);
	  f->meshRep->va_lines->add(v->x(), v->y(), v->z(), n[0], n[1], n[2],
				    CTX.color.mesh.carousel[abs(part % 20)]);
	}
      }
    }

    if((!useEdges && CTX.mesh.surfaces_edges) || CTX.mesh.surfaces_faces){
      if(f->meshRep->va_triangles) delete f->meshRep->va_triangles;
      f->meshRep->va_triangles = new VertexArray(3, f->triangles.size());
      addElementsInArrays(f, f->meshRep->va_triangles, f->triangles);

      if(f->meshRep->va_quads) delete f->meshRep->va_quads;
      f->meshRep->va_quads = new VertexArray(4, f->quadrangles.size());
      addElementsInArrays(f, f->meshRep->va_quads, f->quadrangles);
    }
  }
};

class drawMeshGFace {
 public:
  void operator () (GFace *f)
  {  
    if(!f->getVisibility())
      return;
    
    if(CTX.render_mode == GMSH_SELECT) {
      glPushName(2);
      glPushName(f->tag());
    }

    MRep *m = f->meshRep;

    if(CTX.mesh.surfaces_edges){
      if(m->va_lines && m->va_lines->n()){
	drawArrays(m->va_lines, GL_LINES, CTX.mesh.light && CTX.mesh.light_lines, 
		   CTX.mesh.color_carousel == 3, false, 
		   getColor(f, CTX.mesh.surfaces_faces, CTX.color.mesh.line));
      }
      else{
	drawArrays(m->va_triangles, GL_TRIANGLES, CTX.mesh.light && CTX.mesh.light_lines,
		   CTX.mesh.color_carousel == 3, false, 
		   getColor(f, CTX.mesh.surfaces_faces, CTX.color.mesh.line), true);
	drawArrays(m->va_quads, GL_QUADS, CTX.mesh.light && CTX.mesh.light_lines, 
		   CTX.mesh.color_carousel == 3, false, 
		   getColor(f, CTX.mesh.surfaces_faces, CTX.color.mesh.line), true);
      }
    }
    
    if(CTX.mesh.surfaces_faces){
      drawArrays(m->va_triangles, GL_TRIANGLES, CTX.mesh.light, 
		 CTX.mesh.color_carousel == 3, CTX.polygon_offset, 
		 getColor(f, 0, CTX.color.mesh.triangle));
      drawArrays(m->va_quads, GL_QUADS, CTX.mesh.light, 
		 CTX.mesh.color_carousel == 3, CTX.polygon_offset, 
		 getColor(f, 0, CTX.color.mesh.quadrangle));
    }

    if(CTX.mesh.surfaces_num) {
      const int labelStep = getLabelStep(f->triangles.size() + f->quadrangles.size());
      int labelNum = 0;
      drawLabels(f, f->triangles, labelStep, labelNum,
		 CTX.mesh.surfaces_faces, CTX.color.mesh.line);
      drawLabels(f, f->quadrangles, labelStep, labelNum,
		 CTX.mesh.surfaces_faces, CTX.color.mesh.line);
    }

    if(CTX.mesh.points || CTX.mesh.points_num)
      drawVertices(f);

    if(CTX.mesh.normals) {
      drawNormals(f->triangles);
      drawNormals(f->quadrangles);
    }

    if(CTX.mesh.dual) {
      drawBarycentricDual(f->triangles);
      drawBarycentricDual(f->quadrangles);
    }

    if(CTX.render_mode == GMSH_SELECT) {
      glPopName();
      glPopName();
    }
  }
};

// GRegion drawing routines

class initMeshGRegion {
 public :
  void operator () (GRegion *r)
  {  
    if(!r->meshRep) 
      r->meshRep = new MRepRegion(r);
    if(CTX.mesh.volumes_edges)
      r->meshRep->generateEdges();
  }
};

class drawMeshGRegion {
 public :
  void operator () (GRegion *r)
  {  
    if(!r->getVisibility())
      return;

    if(CTX.render_mode == GMSH_SELECT) {
      glPushName(3);
      glPushName(r->tag());
    }

    if(CTX.mesh.volumes_edges){
      glColor4ubv((GLubyte *) & CTX.color.mesh.hexahedron);
      glBegin(GL_LINES);
      for(std::set<MEdge>::const_iterator it = r->meshRep->edges.begin(); 
	  it != r->meshRep->edges.end(); ++it){
	MVertex *v0 = it->getVertex(0), *v1 = it->getVertex(1);
	glVertex3d(v0->x(), v0->y(), v0->z());
	glVertex3d(v1->x(), v1->y(), v1->z());
      }
      glEnd();
    }

    if(CTX.mesh.volumes_num) {
      const int labelStep = getLabelStep(r->tetrahedra.size() + r->hexahedra.size() + 
					 r->prisms.size() + r->pyramids.size());
      int labelNum = 0;
      drawLabels(r, r->tetrahedra, labelStep, labelNum,
		 CTX.mesh.volumes_faces || CTX.mesh.surfaces_faces, CTX.color.mesh.line);
      drawLabels(r, r->hexahedra, labelStep, labelNum,
		 CTX.mesh.volumes_faces || CTX.mesh.surfaces_faces, CTX.color.mesh.line);
      drawLabels(r, r->prisms, labelStep, labelNum,
		 CTX.mesh.volumes_faces || CTX.mesh.surfaces_faces, CTX.color.mesh.line);
      drawLabels(r, r->pyramids, labelStep, labelNum,
		 CTX.mesh.volumes_faces || CTX.mesh.surfaces_faces, CTX.color.mesh.line);
    }

    if(CTX.mesh.points || CTX.mesh.points_num)
      drawVertices(r);

    if(CTX.mesh.dual) {
      drawBarycentricDual(r->tetrahedra);
      drawBarycentricDual(r->hexahedra);
      drawBarycentricDual(r->prisms);
      drawBarycentricDual(r->pyramids);
    }

    if(CTX.render_mode == GMSH_SELECT) {
      glPopName();
      glPopName();
    }
  }
};


// Main drawing routine

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
  
  if(!CTX.threads_lock){
    CTX.threads_lock = 1; 
    int status = GMODEL->getMeshStatus();
    if(CTX.mesh.changed) {
      if(status >= 1)
	std::for_each(GMODEL->firstEdge(), GMODEL->lastEdge(), initMeshGEdge());
      if(status >= 2){
	if(GMODEL->normals) 
	  delete GMODEL->normals;
	GMODEL->normals = new smooth_normals(CTX.mesh.angle_smooth_normals);
	if(CTX.mesh.smooth_normals)
	  std::for_each(GMODEL->firstFace(), GMODEL->lastFace(), initSmoothNormalsGFace());
	std::for_each(GMODEL->firstFace(), GMODEL->lastFace(), initMeshGFace());
      }
      if(status >= 3)
	std::for_each(GMODEL->firstRegion(), GMODEL->lastRegion(), initMeshGRegion());
    }
    if(status >= 0)
      std::for_each(GMODEL->firstVertex(), GMODEL->lastVertex(), drawMeshGVertex());
    if(status >= 1)
      std::for_each(GMODEL->firstEdge(), GMODEL->lastEdge(), drawMeshGEdge());
    if(status >= 2)
      std::for_each(GMODEL->firstFace(), GMODEL->lastFace(), drawMeshGFace());
    if(status >= 3)
      std::for_each(GMODEL->firstRegion(), GMODEL->lastRegion(), drawMeshGRegion());
    CTX.mesh.changed = 0;
    CTX.threads_lock = 0;
  }

  for(int i = 0; i < 6; i++)
    glDisable((GLenum)(GL_CLIP_PLANE0 + i));
}
