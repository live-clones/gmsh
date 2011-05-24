// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <math.h>
#include "drawContext.h"
#include "GmshMessage.h"
#include "GmshDefines.h"
#include "GModel.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "MElementCut.h"
#include "Context.h"
#include "OS.h"
#include "gl2ps.h"
#include "VertexArray.h"
#include "SmoothData.h"
#include "PView.h"
#include "PViewData.h"

// from GModelVertexArrays
extern unsigned int getColorByEntity(GEntity *e);
extern bool isElementVisible(MElement *ele);

template<class T>
static void drawElementLabels(drawContext *ctx, GEntity *e,
                              std::vector<T*> &elements, int forceColor=0,
                              unsigned int color=0)
{
  unsigned col = forceColor ? color : getColorByEntity(e);
  glColor4ubv((GLubyte *) & col);

  int labelStep = CTX::instance()->mesh.labelSampling;
  if(labelStep <= 0) labelStep = 1;

  for(unsigned int i = 0; i < elements.size(); i++){
    MElement *ele = elements[i];
    if(!isElementVisible(ele)) continue;
    if(i % labelStep == 0) {
      SPoint3 pc = ele->barycenter();
      char str[256];
      if(CTX::instance()->mesh.labelType == 4)
        sprintf(str, "(%g,%g,%g)", pc.x(), pc.y(), pc.z());
      else if(CTX::instance()->mesh.labelType == 3)
        sprintf(str, "%d", ele->getPartition());
      else if(CTX::instance()->mesh.labelType == 2){
        int np = e->physicals.size();
        int p = np ? e->physicals[np - 1] : 0;
        sprintf(str, "%d", p);
      }
      else if(CTX::instance()->mesh.labelType == 1)
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
    ctx->drawVector(CTX::instance()->vectorType, 0, pc.x(), pc.y(), pc.z(), 
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
    ctx->drawVector(CTX::instance()->vectorType, 0, pc.x(), pc.y(), pc.z(), 
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
  if(CTX::instance()->mesh.labelType == 4)
    sprintf(str, "(%.16g,%.16g,%.16g)", v->x(), v->y(), v->z());
  else if(CTX::instance()->mesh.labelType == 3){
    if(partition < 0)
      sprintf(str, "NA");
    else
      sprintf(str, "%d", partition);
  }
  else if(CTX::instance()->mesh.labelType == 2)
    sprintf(str, "%d", physical);
  else if(CTX::instance()->mesh.labelType == 1)
    sprintf(str, "%d", e->tag());
  else
    sprintf(str, "%d", v->getNum());

  if(v->getPolynomialOrder() > 1)
    glColor4ubv((GLubyte *) & CTX::instance()->color.mesh.vertexSup);
  else
    glColor4ubv((GLubyte *) & CTX::instance()->color.mesh.vertex);   

  double offset = (0.5 * CTX::instance()->mesh.pointSize + 
                   0.1 * CTX::instance()->glFontSize) * ctx->pixel_equiv_x;
  glRasterPos3d(v->x() + offset / ctx->s[0],
                v->y() + offset / ctx->s[1],
                v->z() + offset / ctx->s[2]);
  ctx->drawString(str);
}

static void drawVerticesPerEntity(drawContext *ctx, GEntity *e)
{
  if(CTX::instance()->mesh.points) {
    if(CTX::instance()->mesh.pointType) {
      for(unsigned int i = 0; i < e->mesh_vertices.size(); i++){
        MVertex *v = e->mesh_vertices[i];
        if(!v->getVisibility()) continue;
        if(v->getPolynomialOrder() > 1)
          glColor4ubv((GLubyte *) & CTX::instance()->color.mesh.vertexSup);
        else
          glColor4ubv((GLubyte *) & CTX::instance()->color.mesh.vertex);     
        ctx->drawSphere(CTX::instance()->mesh.pointSize, v->x(), v->y(), v->z(), 
                        CTX::instance()->mesh.light);
      }
    }
    else{
      glBegin(GL_POINTS);
      for(unsigned int i = 0; i < e->mesh_vertices.size(); i++){
        MVertex *v = e->mesh_vertices[i];
        if(!v->getVisibility()) continue;
        if(v->getPolynomialOrder() > 1)
          glColor4ubv((GLubyte *) & CTX::instance()->color.mesh.vertexSup);
        else
          glColor4ubv((GLubyte *) & CTX::instance()->color.mesh.vertex);     
        glVertex3d(v->x(), v->y(), v->z());
      }
      glEnd();
    }
  }
  if(CTX::instance()->mesh.pointsNum) {
    int labelStep = CTX::instance()->mesh.labelSampling;
    if(labelStep <= 0) labelStep = 1;
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
      // FIXME isElementVisible() can be slow: we should also use a
      // vertex array for drawing vertices...
      if(isElementVisible(ele) && v->getVisibility()){
        if(CTX::instance()->mesh.points) {
          if(v->getPolynomialOrder() > 1)
            glColor4ubv((GLubyte *) & CTX::instance()->color.mesh.vertexSup);
          else
            glColor4ubv((GLubyte *) & CTX::instance()->color.mesh.vertex);   
          if(CTX::instance()->mesh.pointType)
            ctx->drawSphere(CTX::instance()->mesh.pointSize, v->x(), v->y(), v->z(),
                            CTX::instance()->mesh.light);
          else{
            glBegin(GL_POINTS);
            glVertex3d(v->x(), v->y(), v->z());
            glEnd();
          }
        }
        if(CTX::instance()->mesh.pointsNum)
          drawVertexLabel(ctx, v->onWhat() ? v->onWhat() : e, v);
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

// Routines for filling and drawing the vertex arrays

static void drawArrays(drawContext *ctx, GEntity *e, VertexArray *va, GLint type, 
                       bool useNormalArray, int forceColor=0, unsigned int color=0)
{
  if(!va || !va->getNumVertices()) return;

  // If we want to be enable picking of individual elements we need to
  // draw each one separately
  bool select = (ctx->render_mode == drawContext::GMSH_SELECT && 
                 CTX::instance()->pickElements && e->model() == GModel::current());
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
  else if(CTX::instance()->pickElements || 
          (!e->getSelection() && (CTX::instance()->mesh.colorCarousel == 0 || 
                                  CTX::instance()->mesh.colorCarousel == 3))){
    glColorPointer(4, GL_UNSIGNED_BYTE, 0, va->getColorArray());
    glEnableClientState(GL_COLOR_ARRAY);
  }
  else{
    glDisableClientState(GL_COLOR_ARRAY);
    color = getColorByEntity(e);
    glColor4ubv((GLubyte *) & color);
  }
  
  if(va->getNumVerticesPerElement() > 2 && CTX::instance()->polygonOffset)
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

    if(CTX::instance()->mesh.points || CTX::instance()->mesh.pointsNum)
      drawVerticesPerEntity(_ctx, v);

    if(select) {
      glPopName();
      glPopName();
    }
  }
};

// GEdge drawing routines

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

    if(CTX::instance()->mesh.linesNum)
      drawElementLabels(_ctx, e, e->lines);

    if(CTX::instance()->mesh.points || CTX::instance()->mesh.pointsNum){
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
               CTX::instance()->mesh.light && CTX::instance()->mesh.lightLines, 
               CTX::instance()->mesh.surfacesFaces, CTX::instance()->color.mesh.line);
    drawArrays(_ctx, f, f->va_triangles, GL_TRIANGLES, CTX::instance()->mesh.light);

    if(CTX::instance()->mesh.surfacesNum) {
      if(CTX::instance()->mesh.triangles)
        drawElementLabels(_ctx, f, f->triangles, CTX::instance()->mesh.surfacesFaces, 
                          CTX::instance()->color.mesh.line);
      if(CTX::instance()->mesh.quadrangles)
        drawElementLabels(_ctx, f, f->quadrangles, CTX::instance()->mesh.surfacesFaces, 
                          CTX::instance()->color.mesh.line);
      drawElementLabels(_ctx, f, f->polygons, CTX::instance()->mesh.surfacesFaces, 
                        CTX::instance()->color.mesh.line);
    }

    if(CTX::instance()->mesh.points || CTX::instance()->mesh.pointsNum){
      if(f->getAllElementsVisible())
        drawVerticesPerEntity(_ctx, f);
      else{
        if(CTX::instance()->mesh.triangles) 
          drawVerticesPerElement(_ctx, f, f->triangles);
        if(CTX::instance()->mesh.quadrangles) 
          drawVerticesPerElement(_ctx, f, f->quadrangles);
        drawVerticesPerElement(_ctx, f, f->polygons);
      }
    }

    if(CTX::instance()->mesh.normals) {
      if(CTX::instance()->mesh.triangles) drawNormals(_ctx, f->triangles);
      if(CTX::instance()->mesh.quadrangles) drawNormals(_ctx, f->quadrangles);
      drawNormals(_ctx, f->polygons);
    }

    if(CTX::instance()->mesh.dual) {
      if(CTX::instance()->mesh.triangles) drawBarycentricDual(f->triangles);
      if(CTX::instance()->mesh.quadrangles) drawBarycentricDual(f->quadrangles);
      drawBarycentricDual(f->polygons);
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
               CTX::instance()->mesh.lightLines, CTX::instance()->mesh.volumesFaces,
               CTX::instance()->color.mesh.line);
    drawArrays(_ctx, r, r->va_triangles, GL_TRIANGLES, CTX::instance()->mesh.light);
    
    if(CTX::instance()->mesh.volumesNum) {
      if(CTX::instance()->mesh.tetrahedra) 
        drawElementLabels(_ctx, r, r->tetrahedra, CTX::instance()->mesh.volumesFaces || 
                          CTX::instance()->mesh.surfacesFaces, 
                          CTX::instance()->color.mesh.line);
      if(CTX::instance()->mesh.hexahedra) 
        drawElementLabels(_ctx, r, r->hexahedra, CTX::instance()->mesh.volumesFaces || 
                          CTX::instance()->mesh.surfacesFaces, 
                          CTX::instance()->color.mesh.line);
      if(CTX::instance()->mesh.prisms) 
        drawElementLabels(_ctx, r, r->prisms, CTX::instance()->mesh.volumesFaces || 
                          CTX::instance()->mesh.surfacesFaces,
                          CTX::instance()->color.mesh.line);
      if(CTX::instance()->mesh.pyramids) 
        drawElementLabels(_ctx, r, r->pyramids, CTX::instance()->mesh.volumesFaces ||
                          CTX::instance()->mesh.surfacesFaces,
                          CTX::instance()->color.mesh.line);
      drawElementLabels(_ctx, r, r->polyhedra, CTX::instance()->mesh.volumesFaces ||
                        CTX::instance()->mesh.surfacesFaces,
                        CTX::instance()->color.mesh.line);
    }

    if(CTX::instance()->mesh.points || CTX::instance()->mesh.pointsNum){
      if(r->getAllElementsVisible())
        drawVerticesPerEntity(_ctx, r);
      else{
        if(CTX::instance()->mesh.tetrahedra) drawVerticesPerElement(_ctx, r, r->tetrahedra);
        if(CTX::instance()->mesh.hexahedra) drawVerticesPerElement(_ctx, r, r->hexahedra);
        if(CTX::instance()->mesh.prisms) drawVerticesPerElement(_ctx, r, r->prisms);
        if(CTX::instance()->mesh.pyramids) drawVerticesPerElement(_ctx, r, r->pyramids);
        drawVerticesPerElement(_ctx, r, r->polyhedra);
      }
    }

    if(CTX::instance()->mesh.dual) {
      if(CTX::instance()->mesh.tetrahedra) drawBarycentricDual(r->tetrahedra);
      if(CTX::instance()->mesh.hexahedra) drawBarycentricDual(r->hexahedra);
      if(CTX::instance()->mesh.prisms) drawBarycentricDual(r->prisms);
      if(CTX::instance()->mesh.pyramids) drawBarycentricDual(r->pyramids);
      drawBarycentricDual(r->polyhedra);
    }

    if(CTX::instance()->mesh.voronoi) {
      if(CTX::instance()->mesh.tetrahedra) drawVoronoiDual(r->tetrahedra);
    }

    if(select) {
      glPopName();
      glPopName();
    }
  }
};

static void beginFakeTransparency()
{
  return;
  CTX::instance()->color.mesh.triangle = CTX::instance()->packColor(255, 0, 0, 128);
  // simple additive blending "a la xpost":
  glBlendFunc(GL_SRC_ALPHA, GL_ONE); // glBlendEquation(GL_FUNC_ADD);
  // maximum intensity projection "a la volsuite":
  // glBlendFunc(GL_ONE, GL_ONE); // glBlendEquation(GL_MAX);
  glEnable(GL_BLEND);
  glDisable(GL_DEPTH_TEST);
}

static void endFakeTransparency()
{
  return;
  glDisable(GL_BLEND);
  glEnable(GL_DEPTH_TEST);
}

// Main drawing routine

void drawContext::drawMesh()
{
  if(!CTX::instance()->mesh.draw) return;

  // make sure to flag any model-dependent post-processing view as
  // changed if the underlying mesh has, before resetting the changed
  // flag
  if(CTX::instance()->mesh.changed){
    for(unsigned int i = 0; i < GModel::list.size(); i++)
      for(unsigned int j = 0; j < PView::list.size(); j++)
        if(PView::list[j]->getData()->hasModel(GModel::list[i]))
          PView::list[j]->setChanged(true);
  }
  
  glPointSize((float)CTX::instance()->mesh.pointSize);
  gl2psPointSize((float)(CTX::instance()->mesh.pointSize * 
                         CTX::instance()->print.epsPointSizeFactor));

  glLineWidth((float)CTX::instance()->mesh.lineWidth);
  gl2psLineWidth((float)(CTX::instance()->mesh.lineWidth *
                         CTX::instance()->print.epsLineWidthFactor));
  
  if(CTX::instance()->mesh.lightTwoSide)
    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
  else
    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
  
  if(!CTX::instance()->clipWholeElements){
    for(int i = 0; i < 6; i++)
      if(CTX::instance()->mesh.clip & (1 << i)) 
        glEnable((GLenum)(GL_CLIP_PLANE0 + i));
      else
        glDisable((GLenum)(GL_CLIP_PLANE0 + i));
  }

  for(unsigned int i = 0; i < GModel::list.size(); i++){
    GModel *m = GModel::list[i];
    m->fillVertexArrays();
    if(m->getVisibility() && isVisible(m)){
      int status = m->getMeshStatus();
      if(status >= 0)
        std::for_each(m->firstVertex(), m->lastVertex(), drawMeshGVertex(this));
      if(status >= 1)
        std::for_each(m->firstEdge(), m->lastEdge(), drawMeshGEdge(this));
      if(status >= 2){
        beginFakeTransparency();
        std::for_each(m->firstFace(), m->lastFace(), drawMeshGFace(this));
        endFakeTransparency();
      }
      if(status >= 3)
        std::for_each(m->firstRegion(), m->lastRegion(), drawMeshGRegion(this));
    }
  }
  
  CTX::instance()->mesh.changed = 0;

  for(int i = 0; i < 6; i++)
    glDisable((GLenum)(GL_CLIP_PLANE0 + i));
}
