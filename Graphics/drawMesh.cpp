// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <math.h>
#include <FL/gl.h>
#include "drawContext.h"
#include "GmshMessage.h"
#include "GmshDefines.h"
#include "GModel.h"
#include "MElement.h"
#include "Context.h"
#include "OS.h"
#include "gl2ps.h"
#include "VertexArray.h"
#include "SmoothData.h"
#include "PView.h"
#include "PViewData.h"

// General helper routines

static unsigned int getColorByEntity(GEntity *e)
{
  if(e->getSelection()){ // selection
    return CTX::instance()->color.geom.selection;
  }
  else if(e->useColor()){ // forced from a script
    return e->getColor();
  }
  else if(CTX::instance()->mesh.color_carousel == 1){ // by elementary entity
    return CTX::instance()->color.mesh.carousel[abs(e->tag() % 20)];
  }
  else if(CTX::instance()->mesh.color_carousel == 2){ // by physical entity
    int np = e->physicals.size();
    int p = np ? e->physicals[np - 1] : 0;
    return CTX::instance()->color.mesh.carousel[abs(p % 20)];
  }
  else{
    return CTX::instance()->color.fg;
  }
}

static unsigned int getColorByElement(MElement *ele)
{
  if(ele->getVisibility() > 1){ // selection
    return CTX::instance()->color.geom.selection;
  }
  else if(CTX::instance()->mesh.color_carousel == 0){ // by element type
    switch(ele->getNumEdges()){
    case 1: return CTX::instance()->color.mesh.line;
    case 3: return CTX::instance()->color.mesh.triangle;
    case 4: return CTX::instance()->color.mesh.quadrangle;
    case 6: return CTX::instance()->color.mesh.tetrahedron;
    case 12: return CTX::instance()->color.mesh.hexahedron;
    case 9: return CTX::instance()->color.mesh.prism;
    case 8: return CTX::instance()->color.mesh.pyramid;
    default: return CTX::instance()->color.mesh.vertex;
    }
  }
  else if(CTX::instance()->mesh.color_carousel == 3){ // by partition
    return CTX::instance()->color.mesh.carousel[abs(ele->getPartition() % 20)];
  }
  else{ 
    // by elementary or physical entity (this is not perfect (since
    // e.g. a triangle can have no vertices categorized on a surface),
    // but it's the best we can do "fast" since we don't store the
    // associated entity in the element
    for(int i = 0; i < ele->getNumVertices(); i++){
      GEntity *e = ele->getVertex(i)->onWhat();
      if(e && (e->dim() == ele->getDim()))
        return getColorByEntity(e);
    }
  }
  return CTX::instance()->color.fg;
}

static double evalClipPlane(int clip, double x, double y, double z)
{
  return CTX::instance()->clip_plane[clip][0] * x + 
    CTX::instance()->clip_plane[clip][1] * y + 
    CTX::instance()->clip_plane[clip][2] * z + 
    CTX::instance()->clip_plane[clip][3];
}

static double intersectClipPlane(int clip, MElement *ele)
{
  MVertex *v = ele->getVertex(0);
  double val = evalClipPlane(clip, v->x(), v->y(), v->z());
  for(int i = 1; i < ele->getNumVertices(); i++){
    v = ele->getVertex(i);
    if(val * evalClipPlane(clip, v->x(), v->y(), v->z()) <= 0)
      return 0.; // the element intersects the cut plane
  }
  return val;
}

static bool isElementVisible(MElement *ele)
{
  if(!ele->getVisibility()) return false;
  if(CTX::instance()->mesh.quality_sup) {
    double q;
    if(CTX::instance()->mesh.quality_type == 3)
      q = ele->distoShapeMeasure();
    else if(CTX::instance()->mesh.quality_type == 2)
      q = ele->rhoShapeMeasure();
    else if(CTX::instance()->mesh.quality_type == 1)
      q = ele->etaShapeMeasure();
    else
      q = ele->gammaShapeMeasure();
    if(q < CTX::instance()->mesh.quality_inf || 
       q > CTX::instance()->mesh.quality_sup) return false;
  }
  if(CTX::instance()->mesh.radius_sup) {
    double r = ele->maxEdge();
    if(r < CTX::instance()->mesh.radius_inf || 
       r > CTX::instance()->mesh.radius_sup) return false;
  }
  if(CTX::instance()->clip_whole_elements){
    bool hidden = false;
    for(int clip = 0; clip < 6; clip++){
      if(CTX::instance()->mesh.clip & (1 << clip)){
	if(ele->getDim() < 3 && CTX::instance()->clip_only_volume){
	}
	else{
	  double d = intersectClipPlane(clip, ele);
	  if(ele->getDim() == 3 && 
             CTX::instance()->clip_only_draw_intersecting_volume && d){
	    hidden = true;
	    break;
	  }
	  else if(d < 0){
	    hidden = true;
	    break;
	  }
	}
      }
    }
    if(hidden) return false;
  }
  return true;
}

template<class T>
static bool areAllElementsVisible(std::vector<T*> &elements)
{
  for(unsigned int i = 0; i < elements.size(); i++)
    if(!isElementVisible(elements[i])) return false;
  return true;
}

template<class T>
static bool areSomeElementsCurved(std::vector<T*> &elements)
{
  for(unsigned int i = 0; i < elements.size(); i++)
    if(elements[i]->getPolynomialOrder() > 1) return true;
  return false;
}

static int getLabelStep(int total)
{
  int step;
  if(CTX::instance()->mesh.label_frequency == 0.0) 
    step = total;
  else 
    step = (int)(100.0 / CTX::instance()->mesh.label_frequency);
  return (step > total) ? total : step;
}

template<class T>
static void drawElementLabels(drawContext *ctx, GEntity *e,
                              std::vector<T*> &elements, int forceColor=0,
                              unsigned int color=0)
{
  unsigned col = forceColor ? color : getColorByEntity(e);
  glColor4ubv((GLubyte *) & col);

  int labelStep = getLabelStep(elements.size());

  for(unsigned int i = 0; i < elements.size(); i++){
    MElement *ele = elements[i];
    if(!isElementVisible(ele)) continue;
    if(i % labelStep == 0) {
      SPoint3 pc = ele->barycenter();
      char str[256];
      if(CTX::instance()->mesh.label_type == 4)
        sprintf(str, "(%g,%g,%g)", pc.x(), pc.y(), pc.z());
      else if(CTX::instance()->mesh.label_type == 3)
        sprintf(str, "%d", ele->getPartition());
      else if(CTX::instance()->mesh.label_type == 2){
        int np = e->physicals.size();
        int p = np ? e->physicals[np - 1] : 0;
        sprintf(str, "%d", p);
      }
      else if(CTX::instance()->mesh.label_type == 1)
        sprintf(str, "%d", e->tag());
      else
        sprintf(str, "%d", ele->getNum());
      glRasterPos3d(pc.x(), pc.y(), pc.z());
      ctx->drawString(str);
    }
  }
}

template<class T>
static void drawNormals(drawContext *ctx, std::vector<T*> &elements)
{
  glColor4ubv((GLubyte *) & CTX::instance()->color.mesh.normals);
  for(unsigned int i = 0; i < elements.size(); i++){
    MElement *ele = elements[i];
    if(!isElementVisible(ele)) continue;
    SVector3 n = ele->getFace(0).normal();
    for(int j = 0; j < 3; j++)
      n[j] *= CTX::instance()->mesh.normals * ctx->pixel_equiv_x / ctx->s[j];
    SPoint3 pc = ele->barycenter();
    ctx->drawVector(CTX::instance()->vector_type, 0, pc.x(), pc.y(), pc.z(), 
                    n[0], n[1], n[2], CTX::instance()->mesh.light);
  }
}

template<class T>
static void drawTangents(drawContext *ctx, std::vector<T*> &elements)
{
  glColor4ubv((GLubyte *) & CTX::instance()->color.mesh.tangents);
  for(unsigned int i = 0; i < elements.size(); i++){
    MElement *ele = elements[i];
    if(!isElementVisible(ele)) continue;
    SVector3 t = ele->getEdge(0).tangent();
    for(int j = 0; j < 3; j++)
      t[j] *= CTX::instance()->mesh.tangents * ctx->pixel_equiv_x / ctx->s[j];
    SPoint3 pc = ele->barycenter();
    ctx->drawVector(CTX::instance()->vector_type, 0, pc.x(), pc.y(), pc.z(), 
                    t[0], t[1], t[2], CTX::instance()->mesh.light);
  }
}

static void drawVertexLabel(drawContext *ctx, GEntity *e, MVertex *v, 
                            int partition=-1)
{
  if(!v->getVisibility()) return;

  int np = e->physicals.size();
  int physical = np ? e->physicals[np - 1] : 0;
  char str[256];
  if(CTX::instance()->mesh.label_type == 4)
    sprintf(str, "(%.16g,%.16g,%.16g)", v->x(), v->y(), v->z());
  else if(CTX::instance()->mesh.label_type == 3){
    if(partition < 0)
      sprintf(str, "NA");
    else
      sprintf(str, "%d", partition);
  }
  else if(CTX::instance()->mesh.label_type == 2)
    sprintf(str, "%d", physical);
  else if(CTX::instance()->mesh.label_type == 1)
    sprintf(str, "%d", e->tag());
  else
    sprintf(str, "%d", v->getNum());

  if(v->getPolynomialOrder() > 1)
    glColor4ubv((GLubyte *) & CTX::instance()->color.mesh.vertex_sup);
  else
    glColor4ubv((GLubyte *) & CTX::instance()->color.mesh.vertex);   
  glRasterPos3d(v->x(), v->y(), v->z());
  ctx->drawString(str);
}

static void drawVerticesPerEntity(drawContext *ctx, GEntity *e)
{
  if(CTX::instance()->mesh.points) {
    if(CTX::instance()->mesh.point_type) {
      for(unsigned int i = 0; i < e->mesh_vertices.size(); i++){
        MVertex *v = e->mesh_vertices[i];
        if(!v->getVisibility()) continue;
        if(v->getPolynomialOrder() > 1)
          glColor4ubv((GLubyte *) & CTX::instance()->color.mesh.vertex_sup);
        else
          glColor4ubv((GLubyte *) & CTX::instance()->color.mesh.vertex);     
        ctx->drawSphere(CTX::instance()->mesh.point_size, v->x(), v->y(), v->z(), 
                        CTX::instance()->mesh.light);
      }
    }
    else{
      glBegin(GL_POINTS);
      for(unsigned int i = 0; i < e->mesh_vertices.size(); i++){
        MVertex *v = e->mesh_vertices[i];
        if(!v->getVisibility()) continue;
        if(v->getPolynomialOrder() > 1)
          glColor4ubv((GLubyte *) & CTX::instance()->color.mesh.vertex_sup);
        else
          glColor4ubv((GLubyte *) & CTX::instance()->color.mesh.vertex);     
        glVertex3d(v->x(), v->y(), v->z());
      }
      glEnd();
    }
  }
  if(CTX::instance()->mesh.points_num) {
    int labelStep = getLabelStep(e->mesh_vertices.size());
    for(unsigned int i = 0; i < e->mesh_vertices.size(); i++)
      if(i % labelStep == 0) drawVertexLabel(ctx, e, e->mesh_vertices[i]);
  }
}

template<class T>
static void drawVerticesPerElement(drawContext *ctx, GEntity *e, 
                                   std::vector<T*> &elements)
{
  for(unsigned int i = 0; i < elements.size(); i++){
    MElement *ele = elements[i];
    for(int j = 0; j < ele->getNumVertices(); j++){
      MVertex *v = ele->getVertex(j);
      if(isElementVisible(ele) && v->getVisibility()){
        if(CTX::instance()->mesh.points) {
          if(v->getPolynomialOrder() > 1)
            glColor4ubv((GLubyte *) & CTX::instance()->color.mesh.vertex_sup);
          else
            glColor4ubv((GLubyte *) & CTX::instance()->color.mesh.vertex);   
          if(CTX::instance()->mesh.point_type)
            ctx->drawSphere(CTX::instance()->mesh.point_size, v->x(), v->y(), v->z(),
                            CTX::instance()->mesh.light);
          else{
            glBegin(GL_POINTS);
            glVertex3d(v->x(), v->y(), v->z());
            glEnd();
          }
        }
        if(CTX::instance()->mesh.points_num)
          drawVertexLabel(ctx, e, v);
      }
    }
  }
}

template<class T>
static void drawBarycentricDual(std::vector<T*> &elements)
{
  glColor4ubv((GLubyte *) & CTX::instance()->color.fg);
  glEnable(GL_LINE_STIPPLE);
  glLineStipple(1, 0x0F0F);
  gl2psEnable(GL2PS_LINE_STIPPLE);
  glBegin(GL_LINES);
  for(unsigned int i = 0; i < elements.size(); i++){
    MElement *ele = elements[i];
    if(!isElementVisible(ele)) continue;
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
                  f.getVertex(0) : f.getVertex(k + 1));
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

template<class T>
static void drawVoronoiDual(std::vector<T*> &elements)
{
  glColor4ubv((GLubyte *) & CTX::instance()->color.fg);
  glEnable(GL_LINE_STIPPLE);
  glLineStipple(1, 0x0F0F);
  gl2psEnable(GL2PS_LINE_STIPPLE);
  glBegin(GL_LINES);
  for(unsigned int i = 0; i < elements.size(); i++){
    T *ele = elements[i];
    if(!isElementVisible(ele)) continue;
    SPoint3 pc = ele->circumcenter();
    if(ele->getDim() == 2){
      for(int j = 0; j < ele->getNumEdges(); j++){
        MEdge e = ele->getEdge(j);
	SVector3 p2p1(e.getVertex(1)->x() - e.getVertex(0)->x(),
		      e.getVertex(1)->y() - e.getVertex(0)->y(),
		      e.getVertex(1)->z() - e.getVertex(0)->z());
	SVector3 pcp1(pc.x() - e.getVertex(0)->x(),
		      pc.y() - e.getVertex(0)->y(),
		      pc.z() - e.getVertex(0)->z());
	double alpha = dot(pcp1,p2p1) / dot(p2p1,p2p1);
        SPoint3 p((1 - alpha)*e.getVertex(0)->x() + alpha * e.getVertex(1)->x(), 
		  (1 - alpha)*e.getVertex(0)->y() + alpha * e.getVertex(1)->y(),
		  (1 - alpha)*e.getVertex(0)->z() + alpha * e.getVertex(1)->z());
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
                  f.getVertex(0) : f.getVertex(k + 1));
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

// Routine to fill the smooth normal container

template<class T>
static void addSmoothNormals(GEntity *e, std::vector<T*> &elements)
{
  for(unsigned int i = 0; i < elements.size(); i++){
    MElement *ele = elements[i];
    SPoint3 pc(0., 0., 0.);
    if(CTX::instance()->mesh.explode != 1.) pc = ele->barycenter();
    for(int j = 0; j < ele->getNumFacesRep(); j++){
      double x[3], y[3], z[3];
      SVector3 n[3];
      ele->getFaceRep(j, x, y, z, n);
      for(int k = 0; k < 3; k++){
        if(CTX::instance()->mesh.explode != 1.){
          x[k] = pc[0] + CTX::instance()->mesh.explode * (x[k] - pc[0]);
          y[k] = pc[1] + CTX::instance()->mesh.explode * (y[k] - pc[1]);
          z[k] = pc[2] + CTX::instance()->mesh.explode * (z[k] - pc[2]);
        }
        e->model()->normals->add(x[k], y[k], z[k], n[k][0], n[k][1], n[k][2]);
      }
    }
  }
}

// Routines for filling and drawing the vertex arrays

template<class T>
static void addElementsInArrays(GEntity *e, std::vector<T*> &elements,
                                bool edges, bool faces)
{
  for(unsigned int i = 0; i < elements.size(); i++){
    MElement *ele = elements[i];

    if(!isElementVisible(ele) || ele->getDim() < 1) continue;
    
    unsigned int c = getColorByElement(ele);
    unsigned int col[4] = {c, c, c, c};

    SPoint3 pc(0., 0., 0.);
    if(CTX::instance()->mesh.explode != 1.) pc = ele->barycenter();

    if(edges){
      bool unique = e->dim() > 1 && !CTX::instance()->pick_elements;
      for(int j = 0; j < ele->getNumEdgesRep(); j++){
        double x[2], y[2], z[2];
        SVector3 n[2];
        ele->getEdgeRep(j, x, y, z, n);
        if(CTX::instance()->mesh.explode != 1.){
          for(int k = 0; k < 2; k++){
            x[k] = pc[0] + CTX::instance()->mesh.explode * (x[k] - pc[0]);
            y[k] = pc[1] + CTX::instance()->mesh.explode * (y[k] - pc[1]);
            z[k] = pc[2] + CTX::instance()->mesh.explode * (z[k] - pc[2]);
          }
        }
        if(e->dim() == 2 && CTX::instance()->mesh.smooth_normals)
          for(int k = 0; k < 2; k++)
            e->model()->normals->get(x[k], y[k], z[k], n[k][0], n[k][1], n[k][2]);
        e->va_lines->add(x, y, z, n, col, ele, unique);
      }
    }

    if(faces){
      bool unique = e->dim() > 2 && !CTX::instance()->pick_elements;
      bool skin = e->dim() > 2 && CTX::instance()->mesh.draw_skin_only;
      for(int j = 0; j < ele->getNumFacesRep(); j++){
        double x[3], y[3], z[3];
        SVector3 n[3];
        ele->getFaceRep(j, x, y, z, n);
        if(CTX::instance()->mesh.explode != 1.){
          for(int k = 0; k < 3; k++){
            x[k] = pc[0] + CTX::instance()->mesh.explode * (x[k] - pc[0]);
            y[k] = pc[1] + CTX::instance()->mesh.explode * (y[k] - pc[1]);
            z[k] = pc[2] + CTX::instance()->mesh.explode * (z[k] - pc[2]);
          }
        }
        if(e->dim() == 2 && CTX::instance()->mesh.smooth_normals)
          for(int k = 0; k < 3; k++)
            e->model()->normals->get(x[k], y[k], z[k], n[k][0], n[k][1], n[k][2]);
        e->va_triangles->add(x, y, z, n, col, ele, unique, skin);
      }
    }
  }
}

static void drawArrays(drawContext *ctx, GEntity *e, VertexArray *va, GLint type, 
                       bool useNormalArray, int forceColor=0, unsigned int color=0)
{
  if(!va || !va->getNumVertices()) return;

  // If we want to be enable picking of individual elements we need to
  // draw each one separately
  bool select = (ctx->render_mode == drawContext::GMSH_SELECT && 
                 CTX::instance()->pick_elements && e->model() == GModel::current());
  if(select) {
    if(va->getNumElementPointers() == va->getNumVertices()){
      for(int i = 0; i < va->getNumVertices(); i += va->getNumVerticesPerElement()){
        glPushName(va->getNumVerticesPerElement());
        glPushName(i);
        glBegin(type);
        for(int j = 0; j < va->getNumVerticesPerElement(); j++)
          glVertex3fv(va->getVertexArray(3 * (i + j)));
        glEnd();
        glPopName();
        glPopName();
      }
      return;
    }
  }

  glVertexPointer(3, GL_FLOAT, 0, va->getVertexArray());
  glEnableClientState(GL_VERTEX_ARRAY);

  if(useNormalArray){
    glEnable(GL_LIGHTING);
    glNormalPointer(GL_BYTE, 0, va->getNormalArray());
    glEnableClientState(GL_NORMAL_ARRAY);
  }
  else
    glDisableClientState(GL_NORMAL_ARRAY);

  if(forceColor){
    glDisableClientState(GL_COLOR_ARRAY);
    glColor4ubv((GLubyte *) & color);
  }
  else if(CTX::instance()->pick_elements || 
          (!e->getSelection() && (CTX::instance()->mesh.color_carousel == 0 || 
                                  CTX::instance()->mesh.color_carousel == 3))){
    glColorPointer(4, GL_UNSIGNED_BYTE, 0, va->getColorArray());
    glEnableClientState(GL_COLOR_ARRAY);
  }
  else{
    glDisableClientState(GL_COLOR_ARRAY);
    color = getColorByEntity(e);
    glColor4ubv((GLubyte *) & color);
  }
  
  if(va->getNumVerticesPerElement() > 2 && CTX::instance()->polygon_offset)
    glEnable(GL_POLYGON_OFFSET_FILL);
  
  glDrawArrays(type, 0, va->getNumVertices());
  
  glDisable(GL_POLYGON_OFFSET_FILL);
  glDisable(GL_LIGHTING);
  
  glDisableClientState(GL_VERTEX_ARRAY);
  glDisableClientState(GL_NORMAL_ARRAY);
  glDisableClientState(GL_COLOR_ARRAY);
}

// GVertex drawing routines

class drawMeshGVertex {
 private:
  drawContext *_ctx;
 public:
  drawMeshGVertex(drawContext *ctx) : _ctx(ctx){}
  void operator () (GVertex *v)
  {  
    if(!v->getVisibility()) return;
    
    bool select = (_ctx->render_mode == drawContext::GMSH_SELECT && 
                   v->model() == GModel::current());
    if(select) {
      glPushName(0);
      glPushName(v->tag());
    }

    if(CTX::instance()->mesh.points || CTX::instance()->mesh.points_num)
      drawVerticesPerEntity(_ctx, v);

    if(select) {
      glPopName();
      glPopName();
    }
  }
};

// GEdge drawing routines

class initMeshGEdge {
 private:
  int _estimateNumLines(GEdge *e)
  {
    int num = 0;
    if(CTX::instance()->mesh.lines){
      num += e->lines.size();
      if(areSomeElementsCurved(e->lines)) num *= 2;
    }
    return num + 100;
  }
 public:
  void operator () (GEdge *e)
  {
    if(!e->getVisibility()) return;

    e->deleteVertexArrays();
    e->setAllElementsVisible(CTX::instance()->mesh.lines &&
                             areAllElementsVisible(e->lines));

    if(CTX::instance()->mesh.lines){
      e->va_lines = new VertexArray(2, _estimateNumLines(e));
      addElementsInArrays(e, e->lines, CTX::instance()->mesh.lines, false);
      e->va_lines->finalize();
    }
  }
};

class drawMeshGEdge {
 private:
  drawContext *_ctx;
 public:
  drawMeshGEdge(drawContext *ctx) : _ctx(ctx){}
  void operator () (GEdge *e)
  {  
    if(!e->getVisibility()) return;

    bool select = (_ctx->render_mode == drawContext::GMSH_SELECT && 
                   e->model() == GModel::current());    
    if(select) {
      glPushName(1);
      glPushName(e->tag());
    }

    if(CTX::instance()->mesh.lines)
      drawArrays(_ctx, e, e->va_lines, GL_LINES, false);

    if(CTX::instance()->mesh.lines_num)
      drawElementLabels(_ctx, e, e->lines);

    if(CTX::instance()->mesh.points || CTX::instance()->mesh.points_num){
      if(e->getAllElementsVisible())
        drawVerticesPerEntity(_ctx, e);
      else
        drawVerticesPerElement(_ctx, e, e->lines);
    }

    if(CTX::instance()->mesh.tangents)
      drawTangents(_ctx, e->lines);

    if(select) {
      glPopName();
      glPopName();
    }
  }
};

// GFace drawing routines

class initSmoothNormalsGFace {
 public:
  void operator () (GFace *f)
  {
    addSmoothNormals(f, f->triangles);
    addSmoothNormals(f, f->quadrangles);
  }
};

class initMeshGFace {
 private:
  bool _curved;
  int _estimateNumLines(GFace *f)
  {
    int num = 0;
    if(CTX::instance()->mesh.surfaces_edges){
      num += (3 * f->triangles.size() + 4 * f->quadrangles.size()) / 2;
      if(CTX::instance()->mesh.explode != 1.) num *= 2;
      if(_curved) num *= 2;
    }
    return num + 100;
  }
  int _estimateNumTriangles(GFace *f)
  {
    int num = 0;
    if(CTX::instance()->mesh.surfaces_faces){
      num += (f->triangles.size() + 2 * f->quadrangles.size());
      if(_curved) num *= 4;
    }
    return num + 100;
  }
 public:
  void operator () (GFace *f)
  {
    if(!f->getVisibility()) return;

    f->deleteVertexArrays();
    f->setAllElementsVisible
      (CTX::instance()->mesh.triangles && areAllElementsVisible(f->triangles) && 
       CTX::instance()->mesh.quadrangles && areAllElementsVisible(f->quadrangles));

    bool edg = CTX::instance()->mesh.surfaces_edges;
    bool fac = CTX::instance()->mesh.surfaces_faces;
    if(edg || fac){
      _curved = (areSomeElementsCurved(f->triangles) ||
                 areSomeElementsCurved(f->quadrangles));
      f->va_lines = new VertexArray(2, _estimateNumLines(f));
      f->va_triangles = new VertexArray(3, _estimateNumTriangles(f));
      if(CTX::instance()->mesh.triangles) addElementsInArrays(f, f->triangles, edg, fac);
      if(CTX::instance()->mesh.quadrangles) addElementsInArrays(f, f->quadrangles, edg, fac);
      f->va_lines->finalize();
      f->va_triangles->finalize();
    }
  }
};

class drawMeshGFace {
 private:
  drawContext *_ctx;
 public:
  drawMeshGFace(drawContext *ctx) : _ctx(ctx){}
  void operator () (GFace *f)
  {  
    if(!f->getVisibility()) return;

    bool select = (_ctx->render_mode == drawContext::GMSH_SELECT &&
                   f->model() == GModel::current());
    if(select) {
      glPushName(2);
      glPushName(f->tag());
    }

    drawArrays(_ctx, f, f->va_lines, GL_LINES, 
               CTX::instance()->mesh.light && CTX::instance()->mesh.light_lines, 
               CTX::instance()->mesh.surfaces_faces, CTX::instance()->color.mesh.line);
    drawArrays(_ctx, f, f->va_triangles, GL_TRIANGLES, CTX::instance()->mesh.light);

    if(CTX::instance()->mesh.surfaces_num) {
      if(CTX::instance()->mesh.triangles)
        drawElementLabels(_ctx, f, f->triangles, CTX::instance()->mesh.surfaces_faces, 
                          CTX::instance()->color.mesh.line);
      if(CTX::instance()->mesh.quadrangles)
        drawElementLabels(_ctx, f, f->quadrangles, CTX::instance()->mesh.surfaces_faces, 
                          CTX::instance()->color.mesh.line);
    }

    if(CTX::instance()->mesh.points || CTX::instance()->mesh.points_num){
      if(f->getAllElementsVisible())
        drawVerticesPerEntity(_ctx, f);
      else{
        if(CTX::instance()->mesh.triangles) 
          drawVerticesPerElement(_ctx, f, f->triangles);
        if(CTX::instance()->mesh.quadrangles) 
          drawVerticesPerElement(_ctx, f, f->quadrangles);
      }
    }

    if(CTX::instance()->mesh.normals) {
      if(CTX::instance()->mesh.triangles) drawNormals(_ctx, f->triangles);
      if(CTX::instance()->mesh.quadrangles) drawNormals(_ctx, f->quadrangles);
    }

    if(CTX::instance()->mesh.dual) {
      if(CTX::instance()->mesh.triangles) drawBarycentricDual(f->triangles);
      if(CTX::instance()->mesh.quadrangles) drawBarycentricDual(f->quadrangles);
    }
    else if(CTX::instance()->mesh.voronoi) {
      if(CTX::instance()->mesh.triangles) drawVoronoiDual(f->triangles);
    }

    if(select) {
      glPopName();
      glPopName();
    }
  }
};

// GRegion drawing routines

class initMeshGRegion {
 private:
  bool _curved;
  int _estimateIfClipped(int num)
  {
    if(CTX::instance()->clip_whole_elements && 
       CTX::instance()->clip_only_draw_intersecting_volume){
      for(int clip = 0; clip < 6; clip++){
	if(CTX::instance()->mesh.clip & (1 << clip))
	  return (int)sqrt((double)num);
      }
    }
    return num;
  }
  int _estimateNumLines(GRegion *r)
  {
    int num = 0;
    if(CTX::instance()->mesh.volumes_edges){
      // suppose edge shared by 4 elements on averge (pessmistic)
      num += (12 * r->tetrahedra.size() + 24 * r->hexahedra.size() +
              18 * r->prisms.size() + 16 * r->pyramids.size()) / 4;
      num = _estimateIfClipped(num);
      if(CTX::instance()->mesh.explode != 1.) num *= 4;
      if(_curved) num *= 2;
    }
    return num + 100;
  }
  int _estimateNumTriangles(GRegion *r)
  {
    int num = 0;
    if(CTX::instance()->mesh.volumes_faces){
      num += (4 * r->tetrahedra.size() + 12 * r->hexahedra.size() +
              8 * r->prisms.size() + 6 * r->pyramids.size()) / 2;
      num = _estimateIfClipped(num);
      if(CTX::instance()->mesh.explode != 1.) num *= 2;
      if(_curved) num *= 4;
    }
    return num + 100;
  }
 public:
  void operator () (GRegion *r)
  {  
    if(!r->getVisibility()) return;

    r->deleteVertexArrays();
    r->setAllElementsVisible
      (CTX::instance()->mesh.tetrahedra && areAllElementsVisible(r->tetrahedra) &&
       CTX::instance()->mesh.hexahedra && areAllElementsVisible(r->hexahedra) &&
       CTX::instance()->mesh.prisms && areAllElementsVisible(r->prisms) &&
       CTX::instance()->mesh.pyramids && areAllElementsVisible(r->pyramids));

    bool edg = CTX::instance()->mesh.volumes_edges;
    bool fac = CTX::instance()->mesh.volumes_faces;
    if(edg || fac){
      _curved = (areSomeElementsCurved(r->tetrahedra) || 
                 areSomeElementsCurved(r->hexahedra) ||
                 areSomeElementsCurved(r->prisms) ||
                 areSomeElementsCurved(r->pyramids));
      r->va_lines = new VertexArray(2, _estimateNumLines(r));
      r->va_triangles = new VertexArray(3, _estimateNumTriangles(r));
      if(CTX::instance()->mesh.tetrahedra) addElementsInArrays(r, r->tetrahedra, edg, fac);
      if(CTX::instance()->mesh.hexahedra) addElementsInArrays(r, r->hexahedra, edg, fac);
      if(CTX::instance()->mesh.prisms) addElementsInArrays(r, r->prisms, edg, fac);
      if(CTX::instance()->mesh.pyramids) addElementsInArrays(r, r->pyramids, edg, fac);
      r->va_lines->finalize();
      r->va_triangles->finalize();
    }
  }
};

class drawMeshGRegion {
 private:
  drawContext *_ctx;
 public:
  drawMeshGRegion(drawContext *ctx) : _ctx(ctx){}
  void operator () (GRegion *r)
  {  
    if(!r->getVisibility()) return;

    bool select = (_ctx->render_mode == drawContext::GMSH_SELECT && 
                   r->model() == GModel::current());
    if(select) {
      glPushName(3);
      glPushName(r->tag());
    }

    drawArrays(_ctx, r, r->va_lines, GL_LINES, CTX::instance()->mesh.light && 
               CTX::instance()->mesh.light_lines, CTX::instance()->mesh.volumes_faces,
               CTX::instance()->color.mesh.line);
    drawArrays(_ctx, r, r->va_triangles, GL_TRIANGLES, CTX::instance()->mesh.light);
    
    if(CTX::instance()->mesh.volumes_num) {
      if(CTX::instance()->mesh.tetrahedra) 
        drawElementLabels(_ctx, r, r->tetrahedra, CTX::instance()->mesh.volumes_faces || 
                          CTX::instance()->mesh.surfaces_faces, 
                          CTX::instance()->color.mesh.line);
      if(CTX::instance()->mesh.hexahedra) 
        drawElementLabels(_ctx, r, r->hexahedra, CTX::instance()->mesh.volumes_faces || 
                          CTX::instance()->mesh.surfaces_faces, 
                          CTX::instance()->color.mesh.line);
      if(CTX::instance()->mesh.prisms) 
        drawElementLabels(_ctx, r, r->prisms, CTX::instance()->mesh.volumes_faces || 
                          CTX::instance()->mesh.surfaces_faces,
                          CTX::instance()->color.mesh.line);
      if(CTX::instance()->mesh.pyramids) 
        drawElementLabels(_ctx, r, r->pyramids, CTX::instance()->mesh.volumes_faces ||
                          CTX::instance()->mesh.surfaces_faces,
                          CTX::instance()->color.mesh.line);
    }

    if(CTX::instance()->mesh.points || CTX::instance()->mesh.points_num){
      if(r->getAllElementsVisible())
        drawVerticesPerEntity(_ctx, r);
      else{
        if(CTX::instance()->mesh.tetrahedra) drawVerticesPerElement(_ctx, r, r->tetrahedra);
        if(CTX::instance()->mesh.hexahedra) drawVerticesPerElement(_ctx, r, r->hexahedra);
        if(CTX::instance()->mesh.prisms) drawVerticesPerElement(_ctx, r, r->prisms);
        if(CTX::instance()->mesh.pyramids) drawVerticesPerElement(_ctx, r, r->pyramids);
      }
    }

    if(CTX::instance()->mesh.dual) {
      if(CTX::instance()->mesh.tetrahedra) drawBarycentricDual(r->tetrahedra);
      if(CTX::instance()->mesh.hexahedra) drawBarycentricDual(r->hexahedra);
      if(CTX::instance()->mesh.prisms) drawBarycentricDual(r->prisms);
      if(CTX::instance()->mesh.pyramids) drawBarycentricDual(r->pyramids);
    }

    if(select) {
      glPopName();
      glPopName();
    }
  }
};


// Main drawing routine

void drawContext::drawMesh()
{
  if(!CTX::instance()->mesh.draw) return;

  // make sure to flag any model-dependent post-processing view as
  // changed if the underlying mesh has, before resetting the changed
  // flag
  for(unsigned int i = 0; i < GModel::list.size(); i++){
    GModel *m = GModel::list[i];
    for(unsigned int j = 0; j < PView::list.size(); j++)
      if(PView::list[j]->getData()->hasModel(m) && CTX::instance()->mesh.changed)
        PView::list[j]->setChanged(true);
  }

  glPointSize(CTX::instance()->mesh.point_size);
  gl2psPointSize(CTX::instance()->mesh.point_size * 
                 CTX::instance()->print.eps_point_size_factor);

  glLineWidth(CTX::instance()->mesh.line_width);
  gl2psLineWidth(CTX::instance()->mesh.line_width *
                 CTX::instance()->print.eps_line_width_factor);
  
  if(CTX::instance()->mesh.light_two_side)
    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
  else
    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
  
  if(!CTX::instance()->clip_whole_elements){
    for(int i = 0; i < 6; i++)
      if(CTX::instance()->mesh.clip & (1 << i)) 
	glEnable((GLenum)(GL_CLIP_PLANE0 + i));
      else
	glDisable((GLenum)(GL_CLIP_PLANE0 + i));
  }

  static bool busy = false;
  if(!busy){
    busy = true;

    for(unsigned int i = 0; i < GModel::list.size(); i++){
      GModel *m = GModel::list[i];
      if(m->getVisibility()){
        int status = m->getMeshStatus();
        if(CTX::instance()->mesh.changed) {
          Msg::Debug("Mesh has changed: reinitializing drawing data",
                     CTX::instance()->mesh.changed);
          if(status >= 1 && CTX::instance()->mesh.changed & ENT_LINE)
            std::for_each(m->firstEdge(), m->lastEdge(), initMeshGEdge());
          if(status >= 2 && CTX::instance()->mesh.changed & ENT_SURFACE){
            if(m->normals) delete m->normals;
            m->normals = new smooth_normals(CTX::instance()->mesh.angle_smooth_normals);
            if(CTX::instance()->mesh.smooth_normals)
              std::for_each(m->firstFace(), m->lastFace(), initSmoothNormalsGFace());
            std::for_each(m->firstFace(), m->lastFace(), initMeshGFace());
          }
          if(status >= 3 && CTX::instance()->mesh.changed & ENT_VOLUME)
            std::for_each(m->firstRegion(), m->lastRegion(), initMeshGRegion());
        }
        if(isVisible(m)){
          if(status >= 0)
            std::for_each(m->firstVertex(), m->lastVertex(), drawMeshGVertex(this));
          if(status >= 1)
            std::for_each(m->firstEdge(), m->lastEdge(), drawMeshGEdge(this));
          if(status >= 2)
            std::for_each(m->firstFace(), m->lastFace(), drawMeshGFace(this));
          if(status >= 3)
            std::for_each(m->firstRegion(), m->lastRegion(), drawMeshGRegion(this));
        }
      }
    }

    CTX::instance()->mesh.changed = 0;
    busy = false;
  }

  for(int i = 0; i < 6; i++)
    glDisable((GLenum)(GL_CLIP_PLANE0 + i));
}
