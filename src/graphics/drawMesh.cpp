// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <map>
#include <set>
#include <algorithm>
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
#include "MPolygon.h"
#include "MPolyhedron.h"
#include "Context.h"
#include "OwnerCache.h"
#include "glyphList.h"
#include "OS.h"
#include "gl2ps.h"
#include "VertexArray.h"
#include "SmoothData.h"
#include "PView.h"
#include "PViewData.h"

// from GModelVertexArrays
extern unsigned int getColorByEntity(GEntity *e, bool withSelection = true);
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

// f(elements) for each list of elements of an entity whose type is shown
// (none for a point entity)
template <class F> static void forShownElements(GEntity *e, F f)
{
  CTX *c = CTX::instance();
  if(e->dim() == 1) { f(static_cast<GEdge *>(e)->lines); }
  else if(e->dim() == 2) {
    GFace *g = static_cast<GFace *>(e);
    if(c->mesh.triangles) f(g->triangles);
    if(c->mesh.quadrangles) f(g->quadrangles);
    if(c->mesh.polygons) f(g->polygons);
  }
  else if(e->dim() == 3) {
    GRegion *g = static_cast<GRegion *>(e);
    if(c->mesh.tetrahedra) f(g->tetrahedra);
    if(c->mesh.hexahedra) f(g->hexahedra);
    if(c->mesh.prisms) f(g->prisms);
    if(c->mesh.pyramids) f(g->pyramids);
    if(c->mesh.trihedra) f(g->trihedra);
    if(c->mesh.polyhedra) f(g->polyhedra);
  }
}

// f(e) for each entity of a dimension of a model
template <class F> static void forMeshEntities(GModel *m, int dim, F f)
{
  switch(dim) {
  case 0:
    for(auto it = m->firstVertex(); it != m->lastVertex(); it++) f(*it);
    break;
  case 1:
    for(auto it = m->firstEdge(); it != m->lastEdge(); it++) f(*it);
    break;
  case 2:
    for(auto it = m->firstFace(); it != m->lastFace(); it++) f(*it);
    break;
  case 3:
    for(auto it = m->firstRegion(); it != m->lastRegion(); it++) f(*it);
    break;
  }
}

// how the edges of the elements of a dimension are lit, and whether they take
// the colour of the lines (when the faces are drawn) rather than their own
static bool edgesLit(int dim)
{
  CTX *c = CTX::instance();
  return c->mesh.light && (dim == 2 ? c->mesh.lightLines > 0 :
                           dim == 3 ? c->mesh.lightLines > 1 :
                                      false);
}

static int edgesForced(int dim)
{
  CTX *c = CTX::instance();
  return (dim == 2) ? c->mesh.surfaceFaces : (dim == 3) ? c->mesh.volumeFaces : 0;
}

// The node spheres of a mesh entity, collected once and kept: they depend on
// the mesh (every list is dropped when it changes, see drawMesh()), the
// options deciding their size and colour, and the pixel size. The labels are
// not collected.

// what a walk over the nodes of an entity is being asked to do
enum { NODES_COLLECT = 1, NODES_POINTS = 2, NODES_LABELS = 4 };

// What the arrays kept for the model being drawn cover (see mergedArrays),
// which its entities then do not draw again, but when selected (on top of
// it) or in a picking pass: the nodes as points, the edges and the faces of
// the elements of the dimension being drawn, their normals or tangents.
static struct {
  bool points, lines, triangles, normals, tangents;
} _merged = {false, false, false, false, false};

// the list an entity keeps its node spheres in, and whether it has to be
// filled
static bool getNodeGlyphs(drawContext *ctx, GEntity *e, glyphList *&g)
{
  glyphToken tok;
  tok.add(ctx->pixel_equiv_x / ctx->s[0]);
  tok.add(CTX::instance()->mesh.nodeSize);
  tok.add(CTX::instance()->mesh.nodeType);
  tok.add(CTX::instance()->mesh.colorCarousel);
  tok.add(CTX::instance()->mesh.volumeFaces);
  tok.add(CTX::instance()->mesh.surfaceFaces);
  tok.add(CTX::instance()->color.mesh.node);
  tok.add(CTX::instance()->color.mesh.nodeSup);
  tok.add(getColorByEntity(e));
  // which nodes the walk visits, not only how they are drawn
  tok.add(e->getVisibility());
  tok.add(e->getOnlySomeElementsVisible());
  tok.add((double)e->mesh_vertices.size());
  tok.add(CTX::instance()->mesh.qualityInf);
  tok.add(CTX::instance()->mesh.qualitySup);
  tok.add(CTX::instance()->mesh.radiusInf);
  tok.add(CTX::instance()->mesh.radiusSup);
  return !glyphCache::get(e, GLYPH_NODES, tok, g);
}

// the nodes of an entity, as spheres and labels; walk() visits them (all of
// them, or those of the visible elements) for one thing at a time, so that
// the spheres come out in the same order whether or not they were kept
template <class W>
static void drawNodes(drawContext *ctx, GEntity *e, W walk)
{
  int labels = CTX::instance()->mesh.nodeLabels ? NODES_LABELS : 0;
  if(CTX::instance()->mesh.nodes && CTX::instance()->mesh.nodeType) {
    glyphList *g;
    if(getNodeGlyphs(ctx, e, g)) walk(g, NODES_COLLECT);
    g->draw(ctx, CTX::instance()->mesh.light);
    if(labels) walk(nullptr, labels);
  }
  else {
    // the points of the whole model are drawn at once from an array kept
    // between frames (see mergedArrays); an entity only draws its own in a
    // picking pass, or when that array could not be used
    // (a selected entity draws its own on top, in the selection colour)
    bool points = CTX::instance()->mesh.nodes &&
                  (!_merged.points || ctx->inPickColorMode() ||
                   e->getSelection());
    int what = (points ? NODES_POINTS : 0) | labels;
    if(what) walk(nullptr, what);
  }
}

// the colour a node is drawn in, which is the one of its order or the one of
// the entity it belongs to
static unsigned int getColorByVertex(GEntity *e, MVertex *v,
                                     bool withSelection = true)
{
  if(CTX::instance()->mesh.colorCarousel == 0 ||
     CTX::instance()->mesh.volumeFaces ||
     CTX::instance()->mesh.surfaceFaces) { // by element type
    if(v->getPolynomialOrder() > 1)
      return CTX::instance()->color.mesh.nodeSup;
    return CTX::instance()->color.mesh.node;
  }
  return getColorByEntity(e, withSelection);
}

// the nodes of an entity: spheres are collected into the list (kept between
// frames) when it asks for it, labels are drawn either way
static void drawVerticesPerEntity(drawContext *ctx, GEntity *e, glyphList *g,
                                  int what)
{
  if(what & NODES_COLLECT) {
    g->reserve(GLYPH_SPHERE, e->mesh_vertices.size());
    for(std::size_t i = 0; i < e->mesh_vertices.size(); i++) {
      MVertex *v = e->mesh_vertices[i];
      if(!v->getVisibility()) continue;
      g->addSphere(ctx, CTX::instance()->mesh.nodeSize, v->x(), v->y(), v->z(),
                   getColorByVertex(e, v));
    }
  }
  if(what & NODES_POINTS) {
    gmshBegin(GL_POINTS);
    // the colour is only set when it changes: it is the same for all the
    // nodes of an entity but for those of high order elements
    unsigned int last = 0;
    bool first = true;
    for(std::size_t i = 0; i < e->mesh_vertices.size(); i++) {
      MVertex *v = e->mesh_vertices[i];
      if(!v->getVisibility()) continue;
      unsigned int col = getColorByVertex(e, v);
      if(first || col != last) {
        gmshColor4ubv((const void *)&col);
        last = col;
        first = false;
      }
      gmshVertex3d(v->x(), v->y(), v->z());
    }
    gmshEnd();
  }
  if(what & NODES_LABELS) {
    int labelStep = CTX::instance()->mesh.labelSampling;
    if(labelStep <= 0) labelStep = 1;
    for(std::size_t i = 0; i < e->mesh_vertices.size(); i++)
      if(i % labelStep == 0) drawVertexLabel(ctx, e, e->mesh_vertices[i]);
  }
}

template <class T>
static void drawVerticesPerElement(drawContext *ctx, GEntity *e,
                                   std::vector<T *> &elements, glyphList *g,
                                   int what)
{
  for(std::size_t i = 0; i < elements.size(); i++) {
    MElement *ele = elements[i];
    for(std::size_t j = 0; j < ele->getNumVertices(); j++) {
      MVertex *v = ele->getVertex(j);
      // FIXME isElementVisible() can be slow: we should also use a
      // vertex array for drawing vertices...
      if(isElementVisible(ele) && v->getVisibility()) {
        if(what & NODES_COLLECT)
          g->addSphere(ctx, CTX::instance()->mesh.nodeSize, v->x(), v->y(),
                       v->z(), getColorByVertex(e, v));
        if(what & NODES_POINTS) {
          unsigned int col = getColorByVertex(e, v);
          gmshColor4ubv((const void *)&col);
          gmshBegin(GL_POINTS);
          gmshVertex3d(v->x(), v->y(), v->z());
          gmshEnd();
        }
        if(what & NODES_LABELS)
          drawVertexLabel(ctx, v->onWhat() ? v->onWhat() : e, v);
      }
    }
  }
}

template <class T> static void drawBarycentricDual(std::vector<T *> &elements)
{
  gmshColor4ubv((const void *)&CTX::instance()->color.fg);
  gmshLineStipple(1, 0x0F0F);
  gl2psEnable(GL2PS_LINE_STIPPLE);
  gmshBegin(GL_LINES);
  for(std::size_t i = 0; i < elements.size(); i++) {
    MElement *ele = elements[i];
    if(!isElementVisible(ele)) continue;
    SPoint3 pc = ele->barycenter();
    if(ele->getDim() == 2) {
      for(int j = 0; j < ele->getNumEdges(); j++) {
        MEdge e = ele->getEdge(j);
        SPoint3 p = e.barycenter();
        gmshVertex3d(pc.x(), pc.y(), pc.z());
        gmshVertex3d(p.x(), p.y(), p.z());
      }
    }
    else if(ele->getDim() == 3) {
      for(int j = 0; j < ele->getNumFaces(); j++) {
        MFace f = ele->getFace(j);
        SPoint3 p = f.barycenter();
        gmshVertex3d(pc.x(), pc.y(), pc.z());
        gmshVertex3d(p.x(), p.y(), p.z());
        for(std::size_t k = 0; k < f.getNumVertices(); k++) {
          MEdge e(f.getVertex(k), (k == f.getNumVertices() - 1) ?
                                    f.getVertex(0) :
                                    f.getVertex(k + 1));
          SPoint3 pe = e.barycenter();
          gmshVertex3d(p.x(), p.y(), p.z());
          gmshVertex3d(pe.x(), pe.y(), pe.z());
        }
      }
    }
  }
  gmshEnd();
  gmshLineStippleOff();
  gl2psDisable(GL2PS_LINE_STIPPLE);
}

template <class T> static void drawVoronoiDual(std::vector<T *> &elements)
{
  gmshColor4ubv((const void *)&CTX::instance()->color.fg);
  gmshLineStipple(1, 0x0F0F);
  gl2psEnable(GL2PS_LINE_STIPPLE);
  gmshBegin(GL_LINES);
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
        gmshVertex3d(pc.x(), pc.y(), pc.z());
        gmshVertex3d(p.x(), p.y(), p.z());
      }
    }
    else if(ele->getDim() == 3) {
      for(int j = 0; j < ele->getNumFaces(); j++) {
        MFace f = ele->getFace(j);
        SPoint3 p = f.barycenter();
        gmshVertex3d(pc.x(), pc.y(), pc.z());
        gmshVertex3d(p.x(), p.y(), p.z());
        for(std::size_t k = 0; k < f.getNumVertices(); k++) {
          MEdge e(f.getVertex(k), (k == f.getNumVertices() - 1) ?
                                    f.getVertex(0) :
                                    f.getVertex(k + 1));
          SPoint3 pe = e.barycenter();
          gmshVertex3d(p.x(), p.y(), p.z());
          gmshVertex3d(pe.x(), pe.y(), pe.z());
        }
      }
    }
  }
  gmshEnd();
  gmshLineStippleOff();
  gl2psDisable(GL2PS_LINE_STIPPLE);
}

// Routine for drawing the vertex arrays

// Merged vertex arrays: on a model with many entities the per-entity draw
// calls dominate the frame, so the arrays of all the entities of a dimension
// are concatenated and drawn in one call. The entities keep their own arrays
// for picking and for the selected ones, drawn again on top.
class mergedArrays {
public:
  VertexArray *lines[4], *triangles[4];
  bool built;
  // the colours are baked in: rebuild when they change
  int colorStamp;
  // The nodes of the whole model drawn as points, which no entity keeps an
  // array of: walking them at every frame cost more than drawing them (half a
  // second for 11 million), and an array per entity is no better when the
  // entities are many (80,000 draws of a point each). Built when they are
  // first shown, with what decides which nodes and which colours.
  VertexArray *points;
  std::vector<double> pointsToken;
  // the mesh status of the model (drawMeshStatus()), and what it was
  // computed for
  std::vector<int> statusKey;
  int status;
  mergedArrays() : built(false), colorStamp(0), points(nullptr), status(-1)
  {
    for(int i = 0; i < 4; i++) lines[i] = triangles[i] = nullptr;
  }
  mergedArrays(const mergedArrays &) = delete;
  ~mergedArrays() { clear(); }
  void clearPoints()
  {
    delete points;
    points = nullptr;
    pointsToken.clear();
  }
  void clear()
  {
    for(int i = 0; i < 4; i++) {
      delete lines[i];
      delete triangles[i];
      lines[i] = triangles[i] = nullptr;
    }
    clearPoints();
    built = false;
  }
};

// what is kept for each model
static OwnerCache<mergedArrays> _models;

// below this many entities merging is not worth the duplicated memory
static const std::size_t mergeThreshold = 200;

// the edges (lines) or the faces of the elements of a dimension of a model in
// one array, or null when there are too few entities for it to be worth it
static VertexArray *buildMerged(GModel *m, int dim, bool lines)
{
  std::size_t num = 0, n = 0;
  forMeshEntities(m, dim, [&](GEntity *e) {
    VertexArray *va = lines ? e->va_lines : e->va_triangles;
    if(va && va->getNumVertices()) {
      n += va->getNumVertices();
      num++;
    }
  });
  if(num < mergeThreshold || !n) return nullptr;

  // the total is known: size the merged array once, instead of letting it grow
  int npe = lines ? 2 : 3;
  VertexArray *out = new VertexArray(npe, (int)(n / npe) + 1);
  int force = lines ? edgesForced(dim) : 0;
  forMeshEntities(m, dim, [&](GEntity *e) {
    VertexArray *va = lines ? e->va_lines : e->va_triangles;
    if(!va || !va->getNumVertices()) return;
    // reproduce exactly the colour drawArrays() would have used
    unsigned int col = 0;
    const unsigned char *c = nullptr;
    if(force) {
      col = CTX::instance()->color.mesh.line;
      c = (const unsigned char *)&col;
    }
    else if(!(va->hasColors() &&
              (CTX::instance()->pickElements ||
               (CTX::instance()->mesh.colorCarousel == 0 ||
                CTX::instance()->mesh.colorCarousel == 3)))) {
      col = getColorByEntity(e, false);
      c = (const unsigned char *)&col;
    }
    out->merge(va, c);
  });
  out->clearElementPointers();
  return out;
}

// the flags for drawing an array of mesh elements: lit if asked, and its
// polygons behind the edges drawn over them
static int meshDrawFlags(VertexArray *va, bool light)
{
  return (light ? GMSH_DRAW_LIGHT : 0) |
         ((va && va->getNumVerticesPerElement() > 2 &&
           CTX::instance()->polygonOffset) ?
            GMSH_DRAW_OFFSET :
            0);
}

// draw one of the merged arrays: it always carries its own colours
static void drawMergedArray(VertexArray *va, GLenum type, bool useNormalArray)
{
  gmshDrawVertexArray(va, type,
                      meshDrawFlags(va, useNormalArray) | GMSH_DRAW_COLORS);
}

// the nodes of the elements of an entity that are visible, once each
template <class T>
static void collectNodes(GEntity *e, std::vector<T *> &elements,
                         std::set<MVertex *> &seen, VertexArray *va)
{
  for(std::size_t i = 0; i < elements.size(); i++) {
    MElement *ele = elements[i];
    if(!isElementVisible(ele)) continue;
    for(std::size_t j = 0; j < ele->getNumVertices(); j++) {
      MVertex *v = ele->getVertex(j);
      if(!v->getVisibility() || !seen.insert(v).second) continue;
      double x = v->x(), y = v->y(), z = v->z();
      unsigned int col = getColorByVertex(e, v, false);
      va->add(&x, &y, &z, nullptr, &col, nullptr, false);
    }
  }
}

// the nodes an entity shows: all of them, or those of its visible elements
static void collectNodes(GEntity *e, VertexArray *va)
{
  if(!e->getVisibility()) return;
  if(!e->getOnlySomeElementsVisible()) {
    for(std::size_t i = 0; i < e->mesh_vertices.size(); i++) {
      MVertex *v = e->mesh_vertices[i];
      if(!v->getVisibility()) continue;
      double x = v->x(), y = v->y(), z = v->z();
      unsigned int col = getColorByVertex(e, v, false);
      va->add(&x, &y, &z, nullptr, &col, nullptr, false);
    }
    return;
  }
  std::set<MVertex *> seen;
  forShownElements(e, [&](auto &elements) { collectNodes(e, elements, seen, va); });
}

// the points of a model, (re)built when what they depend on has changed;
// the mesh itself and the visibilities go through Mesh.Changed, which drops
// the merged arrays altogether
static void fillMergedPoints(GModel *m, mergedArrays &ma, int status)
{
  CTX *c = CTX::instance();
  std::vector<double> tok = {(double)status,
                             (double)c->mesh.colorCarousel,
                             (double)c->mesh.volumeFaces,
                             (double)c->mesh.surfaceFaces,
                             (double)c->color.mesh.node,
                             (double)c->color.mesh.nodeSup,
                             (double)CTX::instance()->entityColorsStamp,
                             c->mesh.qualityInf,
                             c->mesh.qualitySup,
                             c->mesh.radiusInf,
                             c->mesh.radiusSup,
                             (double)c->mesh.triangles,
                             (double)c->mesh.quadrangles,
                             (double)c->mesh.tetrahedra,
                             (double)c->mesh.hexahedra,
                             (double)c->mesh.prisms,
                             (double)c->mesh.pyramids,
                             (double)c->mesh.trihedra,
                             (double)c->mesh.polygons,
                             (double)c->mesh.polyhedra};
  // which entities are shown, which can change without the mesh being
  // flagged as changed
  tok.push_back((double)CTX::instance()->entityVisibilityStamp);
  tok.push_back((double)c->hideUnselected);
  if(ma.points && tok == ma.pointsToken) return;
  ma.clearPoints();
  ma.pointsToken = tok;
  ma.points = new VertexArray(1, (int)m->getNumMeshVertices());
  for(int dim = 0; dim <= status; dim++)
    forMeshEntities(m, dim, [&](GEntity *e) { collectNodes(e, ma.points); });
  ma.points->finalize();
  Msg::Debug("%d mesh nodes in the merged array of points",
             ma.points->getNumVertices());
}

// The normals of the surfaces (dim 2) or the tangents of the curves (dim 1)
// of a model, recorded once into a list of the model and drawn as a whole:
// drawn a 3D arrow at a time at every frame, the normals of a large mesh
// took half a second. The mesh changing drops the list (drawMesh()).
static void drawMergedVectors(drawContext *ctx, GModel *m, int dim)
{
  CTX *c = CTX::instance();
  glyphToken tok;
  tok.add(ctx->pixel_equiv_x / ctx->s[0]);
  tok.add(ctx->pixel_equiv_x / ctx->s[1]);
  tok.add(ctx->pixel_equiv_x / ctx->s[2]);
  tok.add(dim == 2 ? c->mesh.normals : c->mesh.tangents);
  tok.add(dim == 2 ? c->color.mesh.normals : c->color.mesh.tangents);
  tok.add(c->mesh.light);
  tok.add(c->vectorType);
  tok.add(c->arrowRelHeadRadius);
  tok.add(c->arrowRelStemLength);
  tok.add(c->arrowRelStemRadius);
  tok.add(c->mesh.qualityInf);
  tok.add(c->mesh.qualitySup);
  tok.add(c->mesh.radiusInf);
  tok.add(c->mesh.radiusSup);
  tok.add(c->mesh.triangles);
  tok.add(c->mesh.quadrangles);
  tok.add(c->mesh.polygons);
  tok.add(CTX::instance()->entityVisibilityStamp);
  tok.add(c->hideUnselected);
  glyphList *g;
  if(!glyphCache::get(m, dim == 2 ? GLYPH_NORMALS : GLYPH_TANGENTS, tok, g)) {
    g->recordBegin();
    forMeshEntities(m, dim, [&](GEntity *e) {
      if(!e->getVisibility()) return;
      forShownElements(e, [&](auto &elements) {
        if(dim == 2)
          drawNormals(ctx, elements);
        else
          drawTangents(ctx, elements);
      });
    });
    g->recordEnd();
  }
  g->draw(ctx, c->mesh.light);
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
        gmshBegin(type);
        for(int j = 0; j < va->getNumVerticesPerElement(); j++)
          gmshVertex3fv(va->getVertexArray(3 * (i + j)));
        gmshEnd();
      }
      return;
    }
  }

  // already covered by the merged draw, unless it is selected and has to be
  // drawn again on top of it (what the clipping planes add is never merged)
  bool merged = (va == e->va_lines && _merged.lines) ||
                (va == e->va_triangles && _merged.triangles);
  bool overlay = false;
  if(merged && !ctx->inPickColorMode()) {
    if(!e->getSelection()) return;
    // the entity is already in the merged draw, in its unselected colour: draw
    // it again on top, which needs the depth test to accept equal depths
    overlay = true;
    glDepthFunc(GL_LEQUAL);
  }

  // in picking mode the colour set by setPickColor() is kept; otherwise the
  // colours come from the array unless forced, selected or by carousel
  bool colors = !forceColor && va->hasColors() &&
                (CTX::instance()->pickElements ||
                 (!e->getSelection() &&
                  (CTX::instance()->mesh.colorCarousel == 0 ||
                   CTX::instance()->mesh.colorCarousel == 3)));
  if(!ctx->inPickColorMode() && !colors) {
    if(!forceColor) color = getColorByEntity(e);
    gmshColor4ubv((const void *)&color);
  }
  gmshDrawVertexArray(va, type,
                      meshDrawFlags(va, useNormalArray) |
                        (colors ? GMSH_DRAW_COLORS : 0));
  if(overlay) glDepthFunc(GL_LESS);
}

// does this pass draw this entity? A mixed mesh draws its opaque entities in
// the opaque pass and the others in the transparent one
static bool passWants(drawContext *ctx, GEntity *e)
{
  if(ctx->transparencyPass == TRANSPARENCY_ALL) return true;
  return (ctx->transparencyPass == TRANSPARENCY_TRANSPARENT) ==
         gmshMeshEntityIsTransparent(e);
}

// what an entity draws of its mesh: its edges and faces (unless merged), the
// labels of its elements, its nodes, its normals or tangents (unless
// recorded for the whole model), the duals
static void drawMeshEntity(drawContext *ctx, GEntity *e)
{
  if(!e->getVisibility() || !passWants(ctx, e)) return;
  CTX *c = CTX::instance();
  int dim = e->dim();

  if(ctx->render_mode == drawContext::GMSH_SELECT &&
     e->model() == GModel::current())
    ctx->setPickColor(dim, e->tag());

  gmshLightTwoSide(false);

  if(dim > 1 || (dim == 1 && c->mesh.lines))
    drawArrays(ctx, e, e->va_lines, GL_LINES, edgesLit(dim), edgesForced(dim),
               c->color.mesh.line);
  if(dim > 1) {
    if(c->mesh.lightTwoSide) gmshLightTwoSide(true);
    drawArrays(ctx, e, e->va_triangles, GL_TRIANGLES, c->mesh.light);
  }

  bool labels = (dim == 1) ? c->mesh.lineLabels :
                (dim == 2) ? c->mesh.surfaceLabels :
                (dim == 3) ? c->mesh.volumeLabels :
                             false;
  if(labels) {
    int force = (dim == 2) ? c->mesh.surfaceFaces :
                (dim == 3) ? (c->mesh.volumeFaces || c->mesh.surfaceFaces) :
                             0;
    forShownElements(e, [&](auto &elements) {
      drawElementLabels(ctx, e, elements, force, c->color.mesh.line);
    });
  }

  drawNodes(ctx, e, [&](glyphList *g, int what) {
    if(dim == 0 || !e->getOnlySomeElementsVisible())
      drawVerticesPerEntity(ctx, e, g, what);
    else
      forShownElements(e, [&](auto &elements) {
        drawVerticesPerElement(ctx, e, elements, g, what);
      });
  });

  if(dim == 1 && c->mesh.tangents && !_merged.tangents)
    drawTangents(ctx, static_cast<GEdge *>(e)->lines);
  if(dim == 2 && c->mesh.normals && !_merged.normals)
    forShownElements(e, [&](auto &elements) { drawNormals(ctx, elements); });

  if(dim > 1 && c->mesh.dual)
    forShownElements(e, [&](auto &elements) { drawBarycentricDual(elements); });
  if(dim == 2 && c->mesh.voronoi && !c->mesh.dual && c->mesh.triangles)
    drawVoronoiDual(static_cast<GFace *>(e)->triangles);
  if(dim == 3 && c->mesh.voronoi && c->mesh.tetrahedra)
    drawVoronoiDual(static_cast<GRegion *>(e)->tetrahedra);
}

// turn the clipping planes of the mesh on or off (the cut elements of whole
// element mode are drawn with them off)
static void setMeshClipPlanes(bool on)
{
  for(int i = 0; i < 6; i++)
    gmshClipPlaneOn(i, on && (CTX::instance()->mesh.clip & (1 << i)));
}

// Draw what the clipping planes add for the entities of a dimension: the
// section of the volumes in capping mode, clipped like everything else, or
// the cut elements in whole element mode. With the shader pipeline these are
// clipped to what the planes cut off, so that they sit next to the clipped
// rest without overlapping it (a transparent mesh would show the overlap);
// the fixed function pipeline draws them whole with the planes off, as does
// either when nothing else is drawn (whole = true) or the planes are already
// off.
static void drawClipArrays(drawContext *ctx, GModel *m, int dim,
                           bool whole = false)
{
  bool any = false;
  forMeshEntities(m, dim, [&](GEntity *e) {
    if(e->va_clip_lines || e->va_clip_triangles) any = true;
  });
  if(!any) return;
  CTX *c = CTX::instance();
  // the section (only volumes have one) is clipped as the rest
  bool section = !c->clipWholeElements;
  bool planesOn = false;
  for(int i = 0; i < 6; i++)
    if(gmshClipPlaneEnabled(i)) planesOn = true;
  bool outside = gmshUseShaders() && planesOn && !whole;
  if(!section) {
    if(outside)
      gmshClipOutside(true);
    else
      setMeshClipPlanes(false);
  }
  forMeshEntities(m, dim, [&](GEntity *e) {
    if(!e->getVisibility() || !passWants(ctx, e)) return;
    if(!e->va_clip_lines && !e->va_clip_triangles) return;
    if(ctx->render_mode == drawContext::GMSH_SELECT)
      ctx->setPickColor(dim, e->tag());
    // lit and coloured as the entities draw their own lines
    drawArrays(ctx, e, e->va_clip_lines, GL_LINES, edgesLit(dim),
               edgesForced(dim), c->color.mesh.line);
    drawArrays(ctx, e, e->va_clip_triangles, GL_TRIANGLES, c->mesh.light);
    if(ctx->render_mode == drawContext::GMSH_SELECT) ctx->unsetPickColor();
  });
  if(!section) {
    if(outside)
      gmshClipOutside(false);
    else
      setMeshClipPlanes(true);
  }
}

// is a pass over the entities of a dimension needed, for what the merged
// arrays do not cover?
static bool needPerEntityPass(drawContext *ctx, int dim)
{
  if(ctx->render_mode != drawContext::GMSH_RENDER) return true;
  if(GEntity::numSelected) return true;
  CTX *c = CTX::instance();
  if((c->mesh.nodes && !_merged.points) || c->mesh.nodeLabels) return true;
  switch(dim) {
  case 0: return false;
  case 1:
    return (c->mesh.lines && !_merged.lines) || c->mesh.lineLabels ||
           (c->mesh.tangents && !_merged.tangents);
  case 2:
    return (c->mesh.surfaceEdges && !_merged.lines) ||
           (c->mesh.surfaceFaces && !_merged.triangles) ||
           c->mesh.surfaceLabels || (c->mesh.normals && !_merged.normals) ||
           c->mesh.dual || c->mesh.voronoi;
  case 3:
    return (c->mesh.volumeEdges && !_merged.lines) ||
           (c->mesh.volumeFaces && !_merged.triangles) ||
           c->mesh.volumeLabels || c->mesh.dual || c->mesh.voronoi;
  default: return true;
  }
}

int drawMeshStatus(GModel *m)
{
  CTX *c = CTX::instance();
  std::vector<int> key = {c->mesh.stamp[0], c->mesh.stamp[1], c->mesh.stamp[2],
                          c->mesh.stamp[3], c->geom.stamp[0], c->geom.stamp[1],
                          c->geom.stamp[2], c->geom.stamp[3],
                          c->entityVisibilityStamp, c->mesh.meshOnlyVisible};
  mergedArrays &ma = _models[m];
  if(ma.statusKey != key) {
    ma.status = m->getMeshStatus();
    ma.statusKey = key;
  }
  return ma.status;
}

// The elements of a dimension of a model: the merged arrays of their edges
// and faces in one call each (none when only the cut volumes are drawn), what
// the clipping planes add, and the entities for what the merged arrays do not
// cover. The volumes draw what the planes add first, the others last.
static void drawDimension(drawContext *ctx, GModel *m, mergedArrays &ma,
                          int dim, bool merge, bool cutOnly = false)
{
  CTX *c = CTX::instance();
  merge = merge && !cutOnly;
  VertexArray *lines = ma.lines[dim], *triangles = ma.triangles[dim];
  // The merged draws set the two-sided lighting themselves, as the
  // per-entity draws do: it was left to whatever the previous pass had set,
  // and once an entity was selected or hovered the pass over the curves,
  // which turns it off, ran before the merged faces, which then lit their
  // back faces no more and went dark.
  if(merge) {
    gmshLightTwoSide(false);
    drawMergedArray(lines, GL_LINES, edgesLit(dim));
    if(dim > 1) {
      gmshLightTwoSide(c->mesh.lightTwoSide);
      drawMergedArray(triangles, GL_TRIANGLES, c->mesh.light);
    }
  }
  _merged.lines = merge && lines;
  _merged.triangles = merge && triangles;
  _merged.tangents = merge && dim == 1 && c->mesh.tangents;
  _merged.normals = merge && dim == 2 && c->mesh.normals;
  if(_merged.tangents || _merged.normals) drawMergedVectors(ctx, m, dim);
  if(dim == 3) drawClipArrays(ctx, m, dim, cutOnly);
  if(!cutOnly && needPerEntityPass(ctx, dim))
    forMeshEntities(m, dim, [&](GEntity *e) { drawMeshEntity(ctx, e); });
  if(dim < 3) drawClipArrays(ctx, m, dim);
  _merged.lines = _merged.triangles = _merged.tangents = _merged.normals = false;
}

// Main drawing routine

void drawContext::drawMesh()
{
  // nothing of the mesh is opaque when the colours of the options are
  // transparent; otherwise the entities are sorted out one by one
  if(transparencyPass == TRANSPARENCY_OPAQUE && gmshMeshColorsAreTransparent())
    return;
  if(transparencyPass == TRANSPARENCY_TRANSPARENT && !gmshMeshIsTransparent())
    return;
  if(!CTX::instance()->mesh.draw) return;

  // make sure to flag any model-dependent post-processing view as changed if
  // the underlying mesh has
  static int seen[4] = {0, 0, 0, 0};
  bool meshChanged = false;
  for(int d = 0; d < 4; d++) {
    if(seen[d] != CTX::instance()->mesh.stamp[d]) meshChanged = true;
    seen[d] = CTX::instance()->mesh.stamp[d];
  }
  if(meshChanged) {
    for(std::size_t i = 0; i < GModel::list.size(); i++)
      for(std::size_t j = 0; j < PView::list.size(); j++)
        if(PView::list[j]->getData()->hasModel(GModel::list[i]))
          PView::list[j]->setChanged(true);
    // the glyphs depend on the mesh: drop them all, the views' included
    glyphCache::clearAll();
  }

  gmshPointSize((float)CTX::instance()->mesh.nodeSize);
  gl2psPointSize((float)(CTX::instance()->mesh.nodeSize *
                         CTX::instance()->print.epsPointSizeFactor));

  gmshLineWidth((float)CTX::instance()->mesh.lineWidth);
  gl2psLineWidth((float)(CTX::instance()->mesh.lineWidth *
                         CTX::instance()->print.epsLineWidthFactor));

  // OpenGL applies the planes in both modes; whole element mode gets its cut
  // elements back from va_clip_*, drawn with the planes off
  setMeshClipPlanes(true);

  for(std::size_t i = 0; i < GModel::list.size(); i++) {
    GModel *m = GModel::list[i];
    bool changed = m->fillVertexArrays();
    if(changed) Msg::Debug("mesh vertex arrays have changed");
    // what the planes add is built on its own: moving a plane costs only this
    if(changed) m->invalidateClipVertexArrays();
    m->fillClipVertexArrays();
#if defined(__APPLE__)
    // FIXME: resetting texture pile fixes bug with recent macOS versions
    if(changed) global()->resetFontTextures();
#endif
    if(!m->getVisibility() || !isVisible(m)) continue;
    int status = drawMeshStatus(m);
    CTX *c = CTX::instance();

    // concatenate the arrays of the dimensions that hold many entities, and
    // draw each of them in a single call; the entities then only draw their
    // labels and, if they are selected, themselves on top
    mergedArrays &ma = _models[m];
    if(changed || ma.colorStamp != c->entityColorsStamp) ma.clear();
    if(!ma.built && !inPickColorMode()) {
      ma.built = true;
      ma.colorStamp = c->entityColorsStamp;
      for(int dim = 1; dim <= std::min(status, 3); dim++) {
        ma.lines[dim] = buildMerged(m, dim, true);
        if(dim > 1) ma.triangles[dim] = buildMerged(m, dim, false);
      }
    }
    // a mixed mesh, some entities transparent and the others not, is drawn
    // entity by entity: the merged arrays hold them all
    bool mixed = transparencyPass != TRANSPARENCY_ALL &&
                 !gmshMeshColorsAreTransparent();
    bool merge = !inPickColorMode() && !mixed;
    // only the volume is clipped: curves and surfaces are drawn whole
    bool volumeOnly = c->clipWholeElements && c->clipOnlyVolume;
    // only the cut elements are drawn, which is what the clip arrays hold
    bool cutOnly =
      c->clipWholeElements && c->clipOnlyDrawIntersectingVolume && c->mesh.clip;

    // the nodes drawn as points, all at once - unless the planes only apply
    // to some of them, which the single draw cannot tell apart
    _merged.points = merge && c->mesh.nodes && !c->mesh.nodeType &&
                     !(c->mesh.clip && c->clipWholeElements);

    if(volumeOnly) setMeshClipPlanes(false);
    if(status >= 0 && needPerEntityPass(this, 0))
      forMeshEntities(m, 0, [&](GEntity *e) { drawMeshEntity(this, e); });
    if(status >= 1) drawDimension(this, m, ma, 1, merge);
    if(status >= 2) drawDimension(this, m, ma, 2, merge);
    if(volumeOnly) setMeshClipPlanes(true);
    if(status >= 3) drawDimension(this, m, ma, 3, merge, cutOnly);

    // after the edges and the faces, as the entities drew their nodes: a
    // node is then covered by the lines that meet at it, as it always was
    if(_merged.points) {
      fillMergedPoints(m, ma, status);
      gmshLightTwoSide(false);
      if(volumeOnly || cutOnly) setMeshClipPlanes(true);
      drawMergedArray(ma.points, GL_POINTS, false);
    }
    _merged.points = false;
  }

  for(int i = 0; i < 6; i++) gmshClipPlaneOn(i, false);
}
