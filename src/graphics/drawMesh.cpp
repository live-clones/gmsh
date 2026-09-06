// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <map>
#include <cmath>
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
#include "MTrihedron.h"
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

template <class T>
static void drawElementLabels(drawContext *ctx, GEntity *e,
                              std::vector<T *> &elements, int forceColor = 0,
                              unsigned int color = 0)
{
  unsigned col = forceColor ? color : getColorByEntity(e);
  gmshColor4ubv((const void *)&col);

  int labelStep = CTX::instance()->mesh.labelSampling;
  if(labelStep <= 0) labelStep = 1;

  for(std::size_t i = 0; i < elements.size(); i++) {
    MElement *ele = elements[i];
    if(!isElementVisible(ele)) continue;
    if(i % labelStep == 0) {
      SPoint3 pc = ele->barycenter();
      char str[256];
      switch(CTX::instance()->mesh.labelType) {
      case 4:
        sprintf(str, "(%g,%g,%g)", pc.x(), pc.y(), pc.z());
        break;
      case 3:
        sprintf(str, "%d", ele->getPartition());
        break;
      case 2:
        {
          int np = e->physicals.size();
          int p = np ? e->physicals[np - 1] : 0;
          sprintf(str, "%d", p);
        }
        break;
      case 1:
        sprintf(str, "%d", e->tag());
        break;
      case 0:
      default:
        sprintf(str, "%zu", ele->getNum());
        break;
      }
      ctx->drawString(str, pc.x(), pc.y(), pc.z());
    }
  }
}

template <class T>
static void drawNormals(drawContext *ctx, std::vector<T *> &elements)
{
  gmshColor4ubv((const void *)&CTX::instance()->color.mesh.normals);
  for(std::size_t i = 0; i < elements.size(); i++) {
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

template <class T>
static void drawTangents(drawContext *ctx, std::vector<T *> &elements)
{
  gmshColor4ubv((const void *)&CTX::instance()->color.mesh.tangents);
  for(std::size_t i = 0; i < elements.size(); i++) {
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
                            int partition = -1)
{
  if(!v->getVisibility()) return;

  int np = e->physicals.size();
  int physical = np ? e->physicals[np - 1] : 0;
  char str[256];
  if(CTX::instance()->mesh.labelType == 4) {
    strcpy(str, "(");
    char tmp[256];
    sprintf(tmp, CTX::instance()->numberFormat.c_str(), v->x());
    strcat(str, tmp);
    strcat(str, ",");
    sprintf(tmp, CTX::instance()->numberFormat.c_str(), v->y());
    strcat(str, tmp);
    strcat(str, ",");
    sprintf(tmp, CTX::instance()->numberFormat.c_str(), v->z());
    strcat(str, tmp);
    strcat(str, ")");
  }
  else if(CTX::instance()->mesh.labelType == 3) {
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
    sprintf(str, "%zu", v->getNum());

  if(CTX::instance()->mesh.colorCarousel == 0 ||
     CTX::instance()->mesh.volumeFaces ||
     CTX::instance()->mesh.surfaceFaces) { // by element type
    if(v->getPolynomialOrder() > 1)
      gmshColor4ubv((const void *)&CTX::instance()->color.mesh.nodeSup);
    else
      gmshColor4ubv((const void *)&CTX::instance()->color.mesh.node);
  }
  else {
    unsigned int col = getColorByEntity(e);
    gmshColor4ubv((const void *)&col);
  }
  double offset = (0.5 * CTX::instance()->mesh.nodeSize +
                   0.1 * CTX::instance()->glFontSize) *
                  ctx->pixel_equiv_x;
  ctx->drawString(str, v->x() + offset / ctx->s[0], v->y() + offset / ctx->s[1],
                  v->z() + offset / ctx->s[2]);
}

static void drawVerticesPerEntity(drawContext *ctx, GEntity *e)
{
  if(CTX::instance()->mesh.nodes) {
    if(CTX::instance()->mesh.nodeType) {
      for(std::size_t i = 0; i < e->mesh_vertices.size(); i++) {
        MVertex *v = e->mesh_vertices[i];
        if(!v->getVisibility()) continue;
        if(CTX::instance()->mesh.colorCarousel == 0 ||
           CTX::instance()->mesh.volumeFaces ||
           CTX::instance()->mesh.surfaceFaces) { // by element type
          if(v->getPolynomialOrder() > 1)
            gmshColor4ubv((const void *)&CTX::instance()->color.mesh.nodeSup);
          else
            gmshColor4ubv((const void *)&CTX::instance()->color.mesh.node);
        }
        else {
          unsigned int col = getColorByEntity(e);
          gmshColor4ubv((const void *)&col);
        }
        ctx->drawSphere(CTX::instance()->mesh.nodeSize, v->x(), v->y(), v->z(),
                        CTX::instance()->mesh.light);
      }
    }
    else {
      glBegin(GL_POINTS);
      for(std::size_t i = 0; i < e->mesh_vertices.size(); i++) {
        MVertex *v = e->mesh_vertices[i];
        if(!v->getVisibility()) continue;
        if(CTX::instance()->mesh.colorCarousel == 0 ||
           CTX::instance()->mesh.volumeFaces ||
           CTX::instance()->mesh.surfaceFaces) { // by element type
          if(v->getPolynomialOrder() > 1)
            gmshColor4ubv((const void *)&CTX::instance()->color.mesh.nodeSup);
          else
            gmshColor4ubv((const void *)&CTX::instance()->color.mesh.node);
        }
        else {
          unsigned int col = getColorByEntity(e);
          gmshColor4ubv((const void *)&col);
        }
        glVertex3d(v->x(), v->y(), v->z());
      }
      glEnd();
    }
  }
  if(CTX::instance()->mesh.nodeLabels) {
    int labelStep = CTX::instance()->mesh.labelSampling;
    if(labelStep <= 0) labelStep = 1;
    for(std::size_t i = 0; i < e->mesh_vertices.size(); i++)
      if(i % labelStep == 0) drawVertexLabel(ctx, e, e->mesh_vertices[i]);
  }
}

template <class T>
static void drawVerticesPerElement(drawContext *ctx, GEntity *e,
                                   std::vector<T *> &elements)
{
  for(std::size_t i = 0; i < elements.size(); i++) {
    MElement *ele = elements[i];
    for(std::size_t j = 0; j < ele->getNumVertices(); j++) {
      MVertex *v = ele->getVertex(j);
      // FIXME isElementVisible() can be slow: we should also use a
      // vertex array for drawing vertices...
      if(isElementVisible(ele) && v->getVisibility()) {
        if(CTX::instance()->mesh.nodes) {
          if(CTX::instance()->mesh.colorCarousel == 0 ||
             CTX::instance()->mesh.volumeFaces ||
             CTX::instance()->mesh.surfaceFaces) { // by element type
            if(v->getPolynomialOrder() > 1)
              gmshColor4ubv((const void *)&CTX::instance()->color.mesh.nodeSup);
            else
              gmshColor4ubv((const void *)&CTX::instance()->color.mesh.node);
          }
          else {
            unsigned int col = getColorByEntity(e);
            gmshColor4ubv((const void *)&col);
          }
          if(CTX::instance()->mesh.nodeType)
            ctx->drawSphere(CTX::instance()->mesh.nodeSize, v->x(), v->y(),
                            v->z(), CTX::instance()->mesh.light);
          else {
            glBegin(GL_POINTS);
            glVertex3d(v->x(), v->y(), v->z());
            glEnd();
          }
        }
        if(CTX::instance()->mesh.nodeLabels)
          drawVertexLabel(ctx, v->onWhat() ? v->onWhat() : e, v);
      }
    }
  }
}

template <class T> static void drawBarycentricDual(std::vector<T *> &elements)
{
  gmshColor4ubv((const void *)&CTX::instance()->color.fg);
  glEnable(GL_LINE_STIPPLE);
  glLineStipple(1, 0x0F0F);
  gl2psEnable(GL2PS_LINE_STIPPLE);
  glBegin(GL_LINES);
  for(std::size_t i = 0; i < elements.size(); i++) {
    MElement *ele = elements[i];
    if(!isElementVisible(ele)) continue;
    SPoint3 pc = ele->barycenter();
    if(ele->getDim() == 2) {
      for(int j = 0; j < ele->getNumEdges(); j++) {
        MEdge e = ele->getEdge(j);
        SPoint3 p = e.barycenter();
        glVertex3d(pc.x(), pc.y(), pc.z());
        glVertex3d(p.x(), p.y(), p.z());
      }
    }
    else if(ele->getDim() == 3) {
      for(int j = 0; j < ele->getNumFaces(); j++) {
        MFace f = ele->getFace(j);
        SPoint3 p = f.barycenter();
        glVertex3d(pc.x(), pc.y(), pc.z());
        glVertex3d(p.x(), p.y(), p.z());
        for(std::size_t k = 0; k < f.getNumVertices(); k++) {
          MEdge e(f.getVertex(k), (k == f.getNumVertices() - 1) ?
                                    f.getVertex(0) :
                                    f.getVertex(k + 1));
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

template <class T> static void drawVoronoiDual(std::vector<T *> &elements)
{
  gmshColor4ubv((const void *)&CTX::instance()->color.fg);
  glEnable(GL_LINE_STIPPLE);
  glLineStipple(1, 0x0F0F);
  gl2psEnable(GL2PS_LINE_STIPPLE);
  glBegin(GL_LINES);
  for(std::size_t i = 0; i < elements.size(); i++) {
    T *ele = elements[i];
    if(!isElementVisible(ele)) continue;
    SPoint3 pc = ele->circumcenter();
    if(ele->getDim() == 2) {
      for(int j = 0; j < ele->getNumEdges(); j++) {
        MEdge e = ele->getEdge(j);
        SVector3 p2p1(e.getVertex(1)->x() - e.getVertex(0)->x(),
                      e.getVertex(1)->y() - e.getVertex(0)->y(),
                      e.getVertex(1)->z() - e.getVertex(0)->z());
        SVector3 pcp1(pc.x() - e.getVertex(0)->x(),
                      pc.y() - e.getVertex(0)->y(),
                      pc.z() - e.getVertex(0)->z());
        double alpha = dot(pcp1, p2p1) / dot(p2p1, p2p1);
        SPoint3 p(
          (1 - alpha) * e.getVertex(0)->x() + alpha * e.getVertex(1)->x(),
          (1 - alpha) * e.getVertex(0)->y() + alpha * e.getVertex(1)->y(),
          (1 - alpha) * e.getVertex(0)->z() + alpha * e.getVertex(1)->z());
        glVertex3d(pc.x(), pc.y(), pc.z());
        glVertex3d(p.x(), p.y(), p.z());
      }
    }
    else if(ele->getDim() == 3) {
      for(int j = 0; j < ele->getNumFaces(); j++) {
        MFace f = ele->getFace(j);
        SPoint3 p = f.barycenter();
        glVertex3d(pc.x(), pc.y(), pc.z());
        glVertex3d(p.x(), p.y(), p.z());
        for(std::size_t k = 0; k < f.getNumVertices(); k++) {
          MEdge e(f.getVertex(k), (k == f.getNumVertices() - 1) ?
                                    f.getVertex(0) :
                                    f.getVertex(k + 1));
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

// Routine for drawing the vertex arrays

// Merged vertex arrays. On a model made of many entities the per-entity draw
// calls dominate the frame: an assembly of 38000 entities spends about 8 of its
// 13 ms in them, while a model of the same size held in a few entities spends
// none. Concatenate the arrays of all the entities of a dimension into a single
// one and draw that in one call. The entities keep their own arrays, which are
// still used for picking and for the entities that are selected: those are
// drawn again on top of the merged draw, so that selecting something does not
// require the merged arrays to be rebuilt.
class mergedArrays {
public:
  VertexArray *lines[4], *triangles[4];
  bool built;
  mergedArrays() : built(false)
  {
    for(int i = 0; i < 4; i++) lines[i] = triangles[i] = nullptr;
  }
  void clear()
  {
    for(int i = 0; i < 4; i++) {
      delete lines[i];
      delete triangles[i];
      lines[i] = triangles[i] = nullptr;
    }
    built = false;
  }
};

static std::map<GModel *, mergedArrays> _merged;
// set while a merged array covers the entities being drawn, per primitive
static bool _mergedLines = false, _mergedTriangles = false;

// below this many entities the per-entity draw calls cost nothing, and merging
// would only duplicate the arrays in memory
static const std::size_t mergeThreshold = 200;

template <class IT>
static VertexArray *buildMerged(IT first, IT last, bool lines, bool forceColor,
                                unsigned int flatColor)
{
  std::size_t num = 0, n = 0;
  for(IT it = first; it != last; it++) {
    VertexArray *va = lines ? (*it)->va_lines : (*it)->va_triangles;
    if(va && va->getNumVertices()) { n += va->getNumVertices(); num++; }
  }
  if(num < mergeThreshold || !n) return nullptr;

  // the total is known: size the merged array once, instead of letting it grow
  int npe = lines ? 2 : 3;
  VertexArray *out = new VertexArray(npe, (int)(n / npe) + 1);
  for(IT it = first; it != last; it++) {
    GEntity *e = *it;
    VertexArray *va = lines ? e->va_lines : e->va_triangles;
    if(!va || !va->getNumVertices()) continue;
    // reproduce exactly the colour drawArrays() would have used
    unsigned int col = 0;
    const unsigned char *c = nullptr;
    if(forceColor) {
      col = flatColor;
      c = (const unsigned char *)&col;
    }
    else if(!(va->hasColors() &&
              (CTX::instance()->pickElements ||
               (CTX::instance()->mesh.colorCarousel == 0 ||
                CTX::instance()->mesh.colorCarousel == 3)))) {
      col = getColorByEntity(e);
      c = (const unsigned char *)&col;
    }
    out->merge(va, c);
  }
  out->clearElementPointers();
  return out;
}

// draw one of the merged arrays: it always carries its own colours
static void drawMergedArray(drawContext *ctx, VertexArray *va, GLenum type,
                            bool useNormalArray)
{
  if(!va || !va->getNumVertices()) return;

  glVertexPointer(3, GL_FLOAT, 0, vaVertexPointer(va));
  glEnableClientState(GL_VERTEX_ARRAY);
  if(useNormalArray && va->hasNormals()) {
    glEnable(GL_LIGHTING);
    glNormalPointer(NORMAL_GLTYPE, 0, vaNormalPointer(va));
    glEnableClientState(GL_NORMAL_ARRAY);
  }
  else
    glDisableClientState(GL_NORMAL_ARRAY);
  glColorPointer(4, GL_UNSIGNED_BYTE, 0, vaColorPointer(va));
  glEnableClientState(GL_COLOR_ARRAY);

  if(va->getNumVerticesPerElement() > 2 && CTX::instance()->polygonOffset)
    glEnable(GL_POLYGON_OFFSET_FILL);

  drawVertexArray(va, type);

  glDisable(GL_POLYGON_OFFSET_FILL);
  glDisable(GL_LIGHTING);
  glDisableClientState(GL_VERTEX_ARRAY);
  glDisableClientState(GL_NORMAL_ARRAY);
  glDisableClientState(GL_COLOR_ARRAY);
}

static void drawArrays(drawContext *ctx, GEntity *e, VertexArray *va,
                       GLint type, bool useNormalArray, int forceColor = 0,
                       unsigned int color = 0)
{
  if(!va || !va->getNumVertices()) return;

  // If we want to be enable picking of individual elements we need to
  // draw each one separately
  bool select =
    (ctx->render_mode == drawContext::GMSH_SELECT &&
     CTX::instance()->pickElements && e->model() == GModel::current());
  if(select) {
    if(va->getNumElementPointers() == va->getNumVertices()) {
      for(int i = 0; i < va->getNumVertices();
          i += va->getNumVerticesPerElement()) {
        ctx->setPickColor(e->dim(), e->tag(),
                          va->getNumVerticesPerElement(), i);
        glBegin(type);
        for(int j = 0; j < va->getNumVerticesPerElement(); j++)
          glVertex3fv(va->getVertexArray(3 * (i + j)));
        glEnd();
      }
      return;
    }
  }

  // already covered by the merged draw, unless it is selected and has to be
  // drawn again on top of it
  bool merged = (va->getNumVerticesPerElement() == 2) ? _mergedLines :
                                                        _mergedTriangles;
  bool overlay = false;
  if(merged && !ctx->inPickColorMode()) {
    if(!e->getSelection()) return;
    // the entity is already in the merged draw, in its unselected colour: draw
    // it again on top, which needs the depth test to accept equal depths
    overlay = true;
    glDepthFunc(GL_LEQUAL);
  }

  glVertexPointer(3, GL_FLOAT, 0, vaVertexPointer(va));
  glEnableClientState(GL_VERTEX_ARRAY);

  if(!ctx->inPickColorMode() && useNormalArray && va->hasNormals()) {
    glEnable(GL_LIGHTING);
    glNormalPointer(NORMAL_GLTYPE, 0, vaNormalPointer(va));
    glEnableClientState(GL_NORMAL_ARRAY);
  }
  else
    glDisableClientState(GL_NORMAL_ARRAY);

  if(ctx->inPickColorMode()) {
    // the colour set by setPickColor() encodes the entity: keep it
    glDisableClientState(GL_COLOR_ARRAY);
  }
  else if(forceColor) {
    glDisableClientState(GL_COLOR_ARRAY);
    gmshColor4ubv((const void *)&color);
  }
  else if(va->hasColors() &&
          (CTX::instance()->pickElements ||
           (!e->getSelection() && (CTX::instance()->mesh.colorCarousel == 0 ||
                                   CTX::instance()->mesh.colorCarousel == 3)))) {
    glColorPointer(4, GL_UNSIGNED_BYTE, 0, vaColorPointer(va));
    glEnableClientState(GL_COLOR_ARRAY);
  }
  else {
    glDisableClientState(GL_COLOR_ARRAY);
    color = getColorByEntity(e);
    gmshColor4ubv((const void *)&color);
  }

  if(va->getNumVerticesPerElement() > 2 && CTX::instance()->polygonOffset)
    glEnable(GL_POLYGON_OFFSET_FILL);

  drawVertexArray(va, type);

  if(overlay) glDepthFunc(GL_LESS);
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
  drawMeshGVertex(drawContext *ctx) : _ctx(ctx) {}
  void operator()(GVertex *v)
  {
    if(!v->getVisibility()) return;

    bool select = (_ctx->render_mode == drawContext::GMSH_SELECT &&
                   v->model() == GModel::current());
    if(select) {
      _ctx->setPickColor(0, v->tag());
    }

    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);

    if(CTX::instance()->mesh.nodes || CTX::instance()->mesh.nodeLabels)
      drawVerticesPerEntity(_ctx, v);

    if(select) {
    }
  }
};

// GEdge drawing routines

class drawMeshGEdge {
private:
  drawContext *_ctx;

public:
  drawMeshGEdge(drawContext *ctx) : _ctx(ctx) {}
  void operator()(GEdge *e)
  {
    if(!e->getVisibility()) {
      return;
    }

    bool select = (_ctx->render_mode == drawContext::GMSH_SELECT &&
                   e->model() == GModel::current());
    if(select) {
      _ctx->setPickColor(1, e->tag());
    }

    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);

    if(CTX::instance()->mesh.lines)
      drawArrays(_ctx, e, e->va_lines, GL_LINES, false);

    if(CTX::instance()->mesh.lineLabels) drawElementLabels(_ctx, e, e->lines);

    if(CTX::instance()->mesh.nodes || CTX::instance()->mesh.nodeLabels) {
      if(!e->getOnlySomeElementsVisible())
        drawVerticesPerEntity(_ctx, e);
      else
        drawVerticesPerElement(_ctx, e, e->lines);
    }

    if(CTX::instance()->mesh.tangents) drawTangents(_ctx, e->lines);

    if(select) {
    }
  }
};

// GFace drawing routines

class drawMeshGFace {
private:
  drawContext *_ctx;

public:
  drawMeshGFace(drawContext *ctx) : _ctx(ctx) {}
  void operator()(GFace *f)
  {
    if(!f->getVisibility()) {
      return;
    }

    bool select = (_ctx->render_mode == drawContext::GMSH_SELECT &&
                   f->model() == GModel::current());
    if(select) {
      _ctx->setPickColor(2, f->tag());
    }

    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);

    drawArrays(_ctx, f, f->va_lines, GL_LINES,
               CTX::instance()->mesh.light && CTX::instance()->mesh.lightLines,
               CTX::instance()->mesh.surfaceFaces,
               CTX::instance()->color.mesh.line);

    if(CTX::instance()->mesh.lightTwoSide)
      glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);

    drawArrays(_ctx, f, f->va_triangles, GL_TRIANGLES,
               CTX::instance()->mesh.light);

    if(CTX::instance()->mesh.surfaceLabels) {
      if(CTX::instance()->mesh.triangles)
        drawElementLabels(_ctx, f, f->triangles,
                          CTX::instance()->mesh.surfaceFaces,
                          CTX::instance()->color.mesh.line);
      if(CTX::instance()->mesh.quadrangles)
        drawElementLabels(_ctx, f, f->quadrangles,
                          CTX::instance()->mesh.surfaceFaces,
                          CTX::instance()->color.mesh.line);
      drawElementLabels(_ctx, f, f->polygons,
                        CTX::instance()->mesh.surfaceFaces,
                        CTX::instance()->color.mesh.line);
    }

    if(CTX::instance()->mesh.nodes || CTX::instance()->mesh.nodeLabels) {
      if(!f->getOnlySomeElementsVisible()) {
        drawVerticesPerEntity(_ctx, f);
      }
      else {
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
    }
  }
};

// GRegion drawing routines

class drawMeshGRegion {
private:
  drawContext *_ctx;

public:
  drawMeshGRegion(drawContext *ctx) : _ctx(ctx) {}
  void operator()(GRegion *r)
  {
    if(!r->getVisibility()) return;

    bool select = (_ctx->render_mode == drawContext::GMSH_SELECT &&
                   r->model() == GModel::current());
    if(select) {
      _ctx->setPickColor(3, r->tag());
    }

    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);

    drawArrays(
      _ctx, r, r->va_lines, GL_LINES,
      CTX::instance()->mesh.light && (CTX::instance()->mesh.lightLines > 1),
      CTX::instance()->mesh.volumeFaces, CTX::instance()->color.mesh.line);

    if(CTX::instance()->mesh.lightTwoSide)
      glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);

    drawArrays(_ctx, r, r->va_triangles, GL_TRIANGLES,
               CTX::instance()->mesh.light);

    if(CTX::instance()->mesh.volumeLabels) {
      if(CTX::instance()->mesh.tetrahedra)
        drawElementLabels(_ctx, r, r->tetrahedra,
                          CTX::instance()->mesh.volumeFaces ||
                            CTX::instance()->mesh.surfaceFaces,
                          CTX::instance()->color.mesh.line);
      if(CTX::instance()->mesh.hexahedra)
        drawElementLabels(_ctx, r, r->hexahedra,
                          CTX::instance()->mesh.volumeFaces ||
                            CTX::instance()->mesh.surfaceFaces,
                          CTX::instance()->color.mesh.line);
      if(CTX::instance()->mesh.prisms)
        drawElementLabels(_ctx, r, r->prisms,
                          CTX::instance()->mesh.volumeFaces ||
                            CTX::instance()->mesh.surfaceFaces,
                          CTX::instance()->color.mesh.line);
      if(CTX::instance()->mesh.pyramids)
        drawElementLabels(_ctx, r, r->pyramids,
                          CTX::instance()->mesh.volumeFaces ||
                            CTX::instance()->mesh.surfaceFaces,
                          CTX::instance()->color.mesh.line);
      if(CTX::instance()->mesh.trihedra)
        drawElementLabels(_ctx, r, r->trihedra,
                          CTX::instance()->mesh.volumeFaces ||
                            CTX::instance()->mesh.surfaceFaces,
                          CTX::instance()->color.mesh.line);
      drawElementLabels(_ctx, r, r->polyhedra,
                        CTX::instance()->mesh.volumeFaces ||
                          CTX::instance()->mesh.surfaceFaces,
                        CTX::instance()->color.mesh.line);
    }

    if(CTX::instance()->mesh.nodes || CTX::instance()->mesh.nodeLabels) {
      if(!r->getOnlySomeElementsVisible()) {
        drawVerticesPerEntity(_ctx, r);
      }
      else {
        if(CTX::instance()->mesh.tetrahedra)
          drawVerticesPerElement(_ctx, r, r->tetrahedra);
        if(CTX::instance()->mesh.hexahedra)
          drawVerticesPerElement(_ctx, r, r->hexahedra);
        if(CTX::instance()->mesh.prisms)
          drawVerticesPerElement(_ctx, r, r->prisms);
        if(CTX::instance()->mesh.pyramids)
          drawVerticesPerElement(_ctx, r, r->pyramids);
        if(CTX::instance()->mesh.trihedra)
          drawVerticesPerElement(_ctx, r, r->trihedra);
        drawVerticesPerElement(_ctx, r, r->polyhedra);
      }
    }

    if(CTX::instance()->mesh.dual) {
      if(CTX::instance()->mesh.tetrahedra) drawBarycentricDual(r->tetrahedra);
      if(CTX::instance()->mesh.hexahedra) drawBarycentricDual(r->hexahedra);
      if(CTX::instance()->mesh.prisms) drawBarycentricDual(r->prisms);
      if(CTX::instance()->mesh.pyramids) drawBarycentricDual(r->pyramids);
      if(CTX::instance()->mesh.trihedra) drawBarycentricDual(r->trihedra);
      drawBarycentricDual(r->polyhedra);
    }

    if(CTX::instance()->mesh.voronoi) {
      if(CTX::instance()->mesh.tetrahedra) drawVoronoiDual(r->tetrahedra);
    }

    if(select) {
    }
  }
};

static void beginFakeTransparency()
{
  return;
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

// The merged arrays drawn just before the per-entity loops already cover the
// wireframe and the filled faces of every unselected entity, so those loops
// have something left to do only when a per-entity feature is on (nodes,
// labels, normals, tangents, dual, voronoi), when an entity is selected and
// wants its highlight painted on top of the merge, or when the pass is a
// picking one, which needs a colour per entity. Otherwise the loop is one
// virtual call and a few cold cache lines per entity for no pixels at all --
// which, on a mesh split into a few hundred thousand partition entities, is
// most of the frame. Decide once, not inside every functor.
static bool needPerEntityPass(drawContext *ctx, int dim, bool mergedLines,
                              bool mergedTriangles)
{
  if(ctx->render_mode != drawContext::GMSH_RENDER) return true;
  if(GEntity::numSelected) return true;
  CTX *c = CTX::instance();
  if(c->mesh.nodes || c->mesh.nodeLabels) return true;
  switch(dim) {
  case 0: return false;
  case 1:
    return (c->mesh.lines && !mergedLines) || c->mesh.lineLabels ||
           c->mesh.tangents;
  case 2:
    return (c->mesh.surfaceEdges && !mergedLines) ||
           (c->mesh.surfaceFaces && !mergedTriangles) || c->mesh.surfaceLabels ||
           c->mesh.normals || c->mesh.dual || c->mesh.voronoi;
  case 3:
    return (c->mesh.volumeEdges && !mergedLines) ||
           ((c->mesh.volumeFaces || c->meshClipCaps()) && !mergedTriangles) ||
           c->mesh.volumeLabels || c->mesh.dual || c->mesh.voronoi;
  default: return true;
  }
}

// Main drawing routine

void drawContext::drawMesh()
{
  if(!CTX::instance()->mesh.draw) return;

  // make sure to flag any model-dependent post-processing view as
  // changed if the underlying mesh has, before resetting the changed
  // flag
  if(CTX::instance()->mesh.changed) {
    for(std::size_t i = 0; i < GModel::list.size(); i++)
      for(std::size_t j = 0; j < PView::list.size(); j++)
        if(PView::list[j]->getData()->hasModel(GModel::list[i]))
          PView::list[j]->setChanged(true);
  }

  glPointSize((float)CTX::instance()->mesh.nodeSize);
  gl2psPointSize((float)(CTX::instance()->mesh.nodeSize *
                         CTX::instance()->print.epsPointSizeFactor));

  glLineWidth((float)CTX::instance()->mesh.lineWidth);
  gl2psLineWidth((float)(CTX::instance()->mesh.lineWidth *
                         CTX::instance()->print.epsLineWidthFactor));

  if(!CTX::instance()->clipWholeElements) {
    for(int i = 0; i < 6; i++)
      if(CTX::instance()->mesh.clip & (1 << i))
        glEnable((GLenum)(GL_CLIP_PLANE0 + i));
      else
        glDisable((GLenum)(GL_CLIP_PLANE0 + i));
  }

  for(std::size_t i = 0; i < GModel::list.size(); i++) {
    GModel *m = GModel::list[i];
    bool changed = m->fillVertexArrays();
    if(changed) Msg::Debug("mesh vertex arrays have changed");
#if defined(__APPLE__)
    // FIXME: resetting texture pile fixes bug with recent macOS versions
    if(changed) global()->resetFontTextures();
#endif
    if(m->getVisibility() && isVisible(m)) {
      int status = m->getMeshStatus();

      // concatenate the arrays of the dimensions that hold many entities, and
      // draw each of them in a single call; the entities then only draw their
      // labels and, if they are selected, themselves on top
      mergedArrays &ma = _merged[m];
      if(changed) ma.clear();
      if(!ma.built && !inPickColorMode()) {
        ma.built = true;
        if(status >= 1)
          ma.lines[1] =
            buildMerged(m->firstEdge(), m->lastEdge(), true, false, 0);
        if(status >= 2) {
          ma.lines[2] = buildMerged(m->firstFace(), m->lastFace(), true,
                                    CTX::instance()->mesh.surfaceFaces,
                                    CTX::instance()->color.mesh.line);
          ma.triangles[2] =
            buildMerged(m->firstFace(), m->lastFace(), false, false, 0);
        }
        if(status >= 3) {
          ma.lines[3] = buildMerged(m->firstRegion(), m->lastRegion(), true,
                                    CTX::instance()->mesh.volumeFaces,
                                    CTX::instance()->color.mesh.line);
          ma.triangles[3] =
            buildMerged(m->firstRegion(), m->lastRegion(), false, false, 0);
        }
      }
      bool merge = !inPickColorMode();

      if(status >= 0 && needPerEntityPass(this, 0, false, false))
        std::for_each(m->firstVertex(), m->lastVertex(),
                      drawMeshGVertex(this));
      if(status >= 1) {
        if(merge) drawMergedArray(this, ma.lines[1], GL_LINES, false);
        _mergedLines = (merge && ma.lines[1]);
        if(needPerEntityPass(this, 1, _mergedLines, false))
          std::for_each(m->firstEdge(), m->lastEdge(), drawMeshGEdge(this));
        _mergedLines = false;
      }
      if(status >= 2) {
        beginFakeTransparency();
        if(merge) {
          drawMergedArray(this, ma.lines[2], GL_LINES,
                          CTX::instance()->mesh.light &&
                            CTX::instance()->mesh.lightLines);
          drawMergedArray(this, ma.triangles[2], GL_TRIANGLES,
                          CTX::instance()->mesh.light);
        }
        _mergedLines = (merge && ma.lines[2]);
        _mergedTriangles = (merge && ma.triangles[2]);
        if(needPerEntityPass(this, 2, _mergedLines, _mergedTriangles))
          std::for_each(m->firstFace(), m->lastFace(), drawMeshGFace(this));
        _mergedLines = _mergedTriangles = false;
        endFakeTransparency();
      }
      if(status >= 3) {
        if(merge) {
          drawMergedArray(this, ma.lines[3], GL_LINES,
                          CTX::instance()->mesh.light &&
                            (CTX::instance()->mesh.lightLines > 1));
          drawMergedArray(this, ma.triangles[3], GL_TRIANGLES,
                          CTX::instance()->mesh.light);
        }
        _mergedLines = (merge && ma.lines[3]);
        _mergedTriangles = (merge && ma.triangles[3]);
        if(needPerEntityPass(this, 3, _mergedLines, _mergedTriangles))
          std::for_each(m->firstRegion(), m->lastRegion(),
                        drawMeshGRegion(this));
        _mergedLines = _mergedTriangles = false;
      }
    }
  }

  CTX::instance()->mesh.changed = 0;

  for(int i = 0; i < 6; i++) glDisable((GLenum)(GL_CLIP_PLANE0 + i));
}
