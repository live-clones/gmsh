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
#include "MElementCut.h"
#include "Context.h"
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

// The node spheres of a mesh entity, collected once and kept: they depend on
// the mesh (every list is dropped when it changes, see drawMesh()), the
// options deciding their size and colour, and the pixel size. The labels are
// not collected.

// what a walk over the nodes of an entity is being asked to do
enum { NODES_COLLECT = 1, NODES_POINTS = 2, NODES_LABELS = 4 };

// set while the nodes of the model being drawn come from its merged array,
// and its normals and tangents from its recorded ones
static bool _mergedPoints = false, _mergedNormals = false,
            _mergedTangents = false;

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
                  (!_mergedPoints || ctx->inPickColorMode() ||
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
  mergedArrays() : built(false), colorStamp(0), points(nullptr)
  {
    for(int i = 0; i < 4; i++) lines[i] = triangles[i] = nullptr;
  }
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

static std::map<GModel *, mergedArrays> _merged;
// set while a merged array covers the entities being drawn, per primitive
static bool _mergedLines = false, _mergedTriangles = false;

// below this many entities merging is not worth the duplicated memory
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
      col = getColorByEntity(e, false);
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

  bool normals = useNormalArray && va->hasNormals();
  if(normals) gmshLighting(true);
  gmshBindVertexArray(va, normals, true);

  if(va->getNumVerticesPerElement() > 2 && CTX::instance()->polygonOffset)
    glEnable(GL_POLYGON_OFFSET_FILL);

  drawVertexArray(va, type);

  glDisable(GL_POLYGON_OFFSET_FILL);
  gmshLighting(false);
  gmshUnbindArrays();
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
  CTX *c = CTX::instance();
  std::set<MVertex *> seen;
  if(e->dim() == 1) {
    GEdge *ge = static_cast<GEdge *>(e);
    collectNodes(e, ge->lines, seen, va);
  }
  else if(e->dim() == 2) {
    GFace *f = static_cast<GFace *>(e);
    if(c->mesh.triangles) collectNodes(e, f->triangles, seen, va);
    if(c->mesh.quadrangles) collectNodes(e, f->quadrangles, seen, va);
    collectNodes(e, f->polygons, seen, va);
  }
  else if(e->dim() == 3) {
    GRegion *r = static_cast<GRegion *>(e);
    if(c->mesh.tetrahedra) collectNodes(e, r->tetrahedra, seen, va);
    if(c->mesh.hexahedra) collectNodes(e, r->hexahedra, seen, va);
    if(c->mesh.prisms) collectNodes(e, r->prisms, seen, va);
    if(c->mesh.pyramids) collectNodes(e, r->pyramids, seen, va);
    if(c->mesh.trihedra) collectNodes(e, r->trihedra, seen, va);
    collectNodes(e, r->polyhedra, seen, va);
  }
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
                             (double)c->mesh.trihedra};
  // which entities are shown, which can change without the mesh being
  // flagged as changed
  tok.push_back((double)CTX::instance()->entityVisibilityStamp);
  tok.push_back((double)c->hideUnselected);
  if(ma.points && tok == ma.pointsToken) return;
  ma.clearPoints();
  ma.pointsToken = tok;
  ma.points = new VertexArray(1, (int)m->getNumMeshVertices());
  if(status >= 0)
    for(auto it = m->firstVertex(); it != m->lastVertex(); it++)
      collectNodes(*it, ma.points);
  if(status >= 1)
    for(auto it = m->firstEdge(); it != m->lastEdge(); it++)
      collectNodes(*it, ma.points);
  if(status >= 2)
    for(auto it = m->firstFace(); it != m->lastFace(); it++)
      collectNodes(*it, ma.points);
  if(status >= 3)
    for(auto it = m->firstRegion(); it != m->lastRegion(); it++)
      collectNodes(*it, ma.points);
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
  tok.add(CTX::instance()->entityVisibilityStamp);
  tok.add(c->hideUnselected);
  glyphList *g;
  if(!glyphCache::get(m, dim == 2 ? GLYPH_NORMALS : GLYPH_TANGENTS, tok, g)) {
    g->recordBegin();
    if(dim == 2) {
      for(auto it = m->firstFace(); it != m->lastFace(); it++) {
        GFace *f = *it;
        if(!f->getVisibility()) continue;
        if(c->mesh.triangles) drawNormals(ctx, f->triangles);
        if(c->mesh.quadrangles) drawNormals(ctx, f->quadrangles);
        drawNormals(ctx, f->polygons);
      }
    }
    else {
      for(auto it = m->firstEdge(); it != m->lastEdge(); it++)
        if((*it)->getVisibility()) drawTangents(ctx, (*it)->lines);
    }
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

  bool normals =
    !ctx->inPickColorMode() && useNormalArray && va->hasNormals();
  if(normals) gmshLighting(true);

  // in picking mode the colour set by setPickColor() is kept; otherwise the
  // colours come from the array unless forced, selected or by carousel
  bool colors = false;
  if(!ctx->inPickColorMode() && !forceColor && va->hasColors() &&
     (CTX::instance()->pickElements ||
      (!e->getSelection() && (CTX::instance()->mesh.colorCarousel == 0 ||
                              CTX::instance()->mesh.colorCarousel == 3))))
    colors = true;

  gmshBindVertexArray(va, normals, colors);

  if(!ctx->inPickColorMode() && !colors) {
    if(!forceColor) color = getColorByEntity(e);
    gmshColor4ubv((const void *)&color);
  }

  if(va->getNumVerticesPerElement() > 2 && CTX::instance()->polygonOffset)
    glEnable(GL_POLYGON_OFFSET_FILL);

  drawVertexArray(va, type);

  if(overlay) glDepthFunc(GL_LESS);
  glDisable(GL_POLYGON_OFFSET_FILL);
  gmshLighting(false);

  gmshUnbindArrays();
}

// GVertex drawing routines

// does this pass draw this entity? A mixed mesh draws its opaque entities in
// the opaque pass and the others in the transparent one
static bool passWants(drawContext *ctx, GEntity *e)
{
  if(ctx->transparencyPass == TRANSPARENCY_ALL) return true;
  return (ctx->transparencyPass == TRANSPARENCY_TRANSPARENT) ==
         gmshMeshEntityIsTransparent(e);
}

class drawMeshGVertex {
private:
  drawContext *_ctx;

public:
  drawMeshGVertex(drawContext *ctx) : _ctx(ctx) {}
  void operator()(GVertex *v)
  {
    if(!v->getVisibility() || !passWants(_ctx, v)) return;

    bool select = (_ctx->render_mode == drawContext::GMSH_SELECT &&
                   v->model() == GModel::current());
    if(select) {
      _ctx->setPickColor(0, v->tag());
    }

    gmshLightTwoSide(false);

    drawNodes(_ctx, v, [this, v](glyphList *g, int what) {
      drawVerticesPerEntity(_ctx, v, g, what);
    });

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
    if(!e->getVisibility() || !passWants(_ctx, e)) return;

    bool select = (_ctx->render_mode == drawContext::GMSH_SELECT &&
                   e->model() == GModel::current());
    if(select) {
      _ctx->setPickColor(1, e->tag());
    }

    gmshLightTwoSide(false);

    if(CTX::instance()->mesh.lines)
      drawArrays(_ctx, e, e->va_lines, GL_LINES, false);

    if(CTX::instance()->mesh.lineLabels) drawElementLabels(_ctx, e, e->lines);

    drawNodes(_ctx, e, [this, e](glyphList *g, int what) {
      if(!e->getOnlySomeElementsVisible())
        drawVerticesPerEntity(_ctx, e, g, what);
      else
        drawVerticesPerElement(_ctx, e, e->lines, g, what);
    });

    if(CTX::instance()->mesh.tangents && !_mergedTangents)
      drawTangents(_ctx, e->lines);

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
    if(!f->getVisibility() || !passWants(_ctx, f)) return;

    bool select = (_ctx->render_mode == drawContext::GMSH_SELECT &&
                   f->model() == GModel::current());
    if(select) {
      _ctx->setPickColor(2, f->tag());
    }

    gmshLightTwoSide(false);

    drawArrays(_ctx, f, f->va_lines, GL_LINES,
               CTX::instance()->mesh.light && CTX::instance()->mesh.lightLines,
               CTX::instance()->mesh.surfaceFaces,
               CTX::instance()->color.mesh.line);

    if(CTX::instance()->mesh.lightTwoSide)
      gmshLightTwoSide(true);

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

    drawNodes(_ctx, f, [this, f](glyphList *g, int what) {
      if(!f->getOnlySomeElementsVisible()) {
        drawVerticesPerEntity(_ctx, f, g, what);
      }
      else {
        if(CTX::instance()->mesh.triangles)
          drawVerticesPerElement(_ctx, f, f->triangles, g, what);
        if(CTX::instance()->mesh.quadrangles)
          drawVerticesPerElement(_ctx, f, f->quadrangles, g, what);
        drawVerticesPerElement(_ctx, f, f->polygons, g, what);
      }
    });

    if(CTX::instance()->mesh.normals && !_mergedNormals) {
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
    if(!r->getVisibility() || !passWants(_ctx, r)) return;

    bool select = (_ctx->render_mode == drawContext::GMSH_SELECT &&
                   r->model() == GModel::current());
    if(select) {
      _ctx->setPickColor(3, r->tag());
    }

    gmshLightTwoSide(false);

    drawArrays(
      _ctx, r, r->va_lines, GL_LINES,
      CTX::instance()->mesh.light && (CTX::instance()->mesh.lightLines > 1),
      CTX::instance()->mesh.volumeFaces, CTX::instance()->color.mesh.line);

    if(CTX::instance()->mesh.lightTwoSide)
      gmshLightTwoSide(true);

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

    drawNodes(_ctx, r, [this, r](glyphList *g, int what) {
      if(!r->getOnlySomeElementsVisible()) {
        drawVerticesPerEntity(_ctx, r, g, what);
      }
      else {
        if(CTX::instance()->mesh.tetrahedra)
          drawVerticesPerElement(_ctx, r, r->tetrahedra, g, what);
        if(CTX::instance()->mesh.hexahedra)
          drawVerticesPerElement(_ctx, r, r->hexahedra, g, what);
        if(CTX::instance()->mesh.prisms)
          drawVerticesPerElement(_ctx, r, r->prisms, g, what);
        if(CTX::instance()->mesh.pyramids)
          drawVerticesPerElement(_ctx, r, r->pyramids, g, what);
        if(CTX::instance()->mesh.trihedra)
          drawVerticesPerElement(_ctx, r, r->trihedra, g, what);
        drawVerticesPerElement(_ctx, r, r->polyhedra, g, what);
      }
    });

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

// turn the clipping planes of the mesh on or off (the cut elements of whole
// element mode are drawn with them off)
static void setMeshClipPlanes(bool on)
{
  for(int i = 0; i < 6; i++)
    gmshClipPlaneOn(i, on && (CTX::instance()->mesh.clip & (1 << i)));
}

// Draw what the clipping planes add for these entities: the cut elements.
// With the shader pipeline they are clipped to what the planes cut off, so
// that they sit next to the clipped rest without overlapping it (a
// transparent mesh would show the overlap); the fixed function pipeline
// draws them whole with the planes off, as does either when nothing else is
// drawn (whole = true) or the planes are already off.
template <class IT>
static void drawClipArrays(drawContext *ctx, IT first, IT last, int dim,
                           bool whole = false)
{
  if(!CTX::instance()->clipWholeElements) return;
  bool any = false;
  for(IT it = first; it != last; it++)
    if((*it)->va_clip_lines || (*it)->va_clip_triangles) any = true;
  if(!any) return;
  bool planesOn = false;
  for(int i = 0; i < 6; i++)
    if(gmshClipPlaneEnabled(i)) planesOn = true;
  bool outside = gmshUseShaders() && planesOn && !whole;
  if(outside)
    gmshClipOutside(true);
  else
    setMeshClipPlanes(false);
  for(IT it = first; it != last; it++) {
    GEntity *e = *it;
    if(!e->getVisibility() || !passWants(ctx, e)) continue;
    if(!e->va_clip_lines && !e->va_clip_triangles) continue;
    if(ctx->render_mode == drawContext::GMSH_SELECT)
      ctx->setPickColor(dim, e->tag());
    // lit and coloured as the entities draw their own lines
    CTX *c = CTX::instance();
    bool lit = c->mesh.light && (dim == 1 ? false :
                                 dim == 2 ? c->mesh.lightLines > 0 :
                                            c->mesh.lightLines > 1);
    int force = (dim == 1) ? 0 : (dim == 2) ? c->mesh.surfaceFaces :
                                             c->mesh.volumeFaces;
    drawArrays(ctx, e, e->va_clip_lines, GL_LINES, lit, force,
               c->color.mesh.line);
    drawArrays(ctx, e, e->va_clip_triangles, GL_TRIANGLES,
               CTX::instance()->mesh.light);
    if(ctx->render_mode == drawContext::GMSH_SELECT) ctx->unsetPickColor();
  }
  if(outside)
    gmshClipOutside(false);
  else
    setMeshClipPlanes(true);
}

static bool needPerEntityPass(drawContext *ctx, int dim, bool mergedLines,
                              bool mergedTriangles)
{
  if(ctx->render_mode != drawContext::GMSH_RENDER) return true;
  if(GEntity::numSelected) return true;
  CTX *c = CTX::instance();
  if((c->mesh.nodes && !_mergedPoints) || c->mesh.nodeLabels) return true;
  switch(dim) {
  case 0: return false;
  case 1:
    return (c->mesh.lines && !mergedLines) || c->mesh.lineLabels ||
           (c->mesh.tangents && !_mergedTangents);
  case 2:
    return (c->mesh.surfaceEdges && !mergedLines) ||
           (c->mesh.surfaceFaces && !mergedTriangles) || c->mesh.surfaceLabels ||
           (c->mesh.normals && !_mergedNormals) || c->mesh.dual ||
           c->mesh.voronoi;
  case 3:
    return (c->mesh.volumeEdges && !mergedLines) ||
           (c->mesh.volumeFaces && !mergedTriangles) ||
           c->mesh.volumeLabels || c->mesh.dual || c->mesh.voronoi;
  default: return true;
  }
}

int drawMeshStatus(GModel *m)
{
  struct entry {
    std::vector<int> key;
    int status;
  };
  static std::map<GModel *, entry> cache;
  CTX *c = CTX::instance();
  c->stampChanges();
  std::vector<int> key = {c->mesh.stamp[0], c->mesh.stamp[1], c->mesh.stamp[2],
                          c->mesh.stamp[3], c->geom.stamp[0], c->geom.stamp[1],
                          c->geom.stamp[2], c->geom.stamp[3],
                          c->entityVisibilityStamp, c->mesh.meshOnlyVisible};
  auto it = cache.find(m);
  if(it != cache.end() && it->second.key == key) return it->second.status;
  int status = m->getMeshStatus();
  cache[m] = {key, status};
  return status;
}

// Main drawing routine

void drawContext::drawMesh()
{
  // before anything else, whatever this pass draws (see CTX::stampChanges())
  CTX::instance()->stampChanges();

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

  // the merged arrays of a model that is gone go with it
  for(auto it = _merged.begin(); it != _merged.end();) {
    if(std::find(GModel::list.begin(), GModel::list.end(), it->first) ==
       GModel::list.end()) {
      it->second.clear();
      it = _merged.erase(it);
    }
    else
      it++;
  }

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
    if(m->getVisibility() && isVisible(m)) {
      int status = drawMeshStatus(m);

      // concatenate the arrays of the dimensions that hold many entities, and
      // draw each of them in a single call; the entities then only draw their
      // labels and, if they are selected, themselves on top
      mergedArrays &ma = _merged[m];
      if(changed || ma.colorStamp != CTX::instance()->entityColorsStamp) ma.clear();
      if(!ma.built && !inPickColorMode()) {
        ma.built = true;
        ma.colorStamp = CTX::instance()->entityColorsStamp;
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
      // a mixed mesh, some entities transparent and the others not, is drawn
      // entity by entity: the merged arrays hold them all
      bool mixed = transparencyPass != TRANSPARENCY_ALL &&
                   !gmshMeshColorsAreTransparent();
      bool merge = !inPickColorMode() && !mixed;
      CTX *c = CTX::instance();
      // only the volume is clipped: curves and surfaces are drawn whole
      bool volumeOnly = c->clipWholeElements && c->clipOnlyVolume;
      if(volumeOnly) setMeshClipPlanes(false);

      // the nodes drawn as points, all at once - unless the planes only
      // apply to some of them, which the single draw cannot tell apart
      _mergedPoints = merge && c->mesh.nodes && !c->mesh.nodeType &&
                      !(c->mesh.clip && c->clipWholeElements);

      if(status >= 0 && needPerEntityPass(this, 0, false, false))
        std::for_each(m->firstVertex(), m->lastVertex(),
                      drawMeshGVertex(this));
      // The merged draws set the two-sided lighting themselves, as the
      // per-entity draws do: it was left to whatever the previous pass had
      // set, and once an entity was selected or hovered the pass over the
      // curves, which turns it off, ran before the merged faces, which
      // then lit their back faces no more and went dark.
      if(status >= 1) {
        if(merge) {
          gmshLightTwoSide(false);
          drawMergedArray(this, ma.lines[1], GL_LINES, false);
        }
        _mergedLines = (merge && ma.lines[1]);
        _mergedTangents = (merge && c->mesh.tangents);
        if(_mergedTangents) drawMergedVectors(this, m, 1);
        if(needPerEntityPass(this, 1, _mergedLines, false))
          std::for_each(m->firstEdge(), m->lastEdge(), drawMeshGEdge(this));
        _mergedLines = _mergedTangents = false;
        drawClipArrays(this, m->firstEdge(), m->lastEdge(), 1);
      }
      if(status >= 2) {
        if(merge) {
          gmshLightTwoSide(false);
          drawMergedArray(this, ma.lines[2], GL_LINES,
                          CTX::instance()->mesh.light &&
                            CTX::instance()->mesh.lightLines);
          gmshLightTwoSide(CTX::instance()->mesh.lightTwoSide);
          drawMergedArray(this, ma.triangles[2], GL_TRIANGLES,
                          CTX::instance()->mesh.light);
        }
        _mergedLines = (merge && ma.lines[2]);
        _mergedTriangles = (merge && ma.triangles[2]);
        _mergedNormals = (merge && c->mesh.normals);
        if(_mergedNormals) drawMergedVectors(this, m, 2);
        if(needPerEntityPass(this, 2, _mergedLines, _mergedTriangles))
          std::for_each(m->firstFace(), m->lastFace(), drawMeshGFace(this));
        _mergedLines = _mergedTriangles = _mergedNormals = false;
        drawClipArrays(this, m->firstFace(), m->lastFace(), 2);
      }
      if(volumeOnly) setMeshClipPlanes(true);
      // only the cut elements are drawn, which is what the clip arrays hold
      bool cutOnly = c->clipWholeElements && c->clipOnlyDrawIntersectingVolume &&
                     c->mesh.clip;
      if(status >= 3) {
        if(merge && !cutOnly) {
          gmshLightTwoSide(false);
          drawMergedArray(this, ma.lines[3], GL_LINES,
                          CTX::instance()->mesh.light &&
                            (CTX::instance()->mesh.lightLines > 1));
          gmshLightTwoSide(CTX::instance()->mesh.lightTwoSide);
          drawMergedArray(this, ma.triangles[3], GL_TRIANGLES,
                          CTX::instance()->mesh.light);
        }
        // what the clipping planes add is not merged, so it is drawn here,
        // before the flags that say the volumes are (drawArrays() would take
        // these arrays for merged ones and skip them):
        // the section in capping mode (clipped like everything else), the
        // cut elements in whole element mode (whole, with the planes off)
        if(CTX::instance()->clipWholeElements) {
          drawClipArrays(this, m->firstRegion(), m->lastRegion(), 3, cutOnly);
        }
        else {
          for(auto it = m->firstRegion(); it != m->lastRegion(); it++) {
            GRegion *r = *it;
            if(!r->va_clip_triangles || !r->getVisibility() ||
               !passWants(this, r))
              continue;
            if(render_mode == GMSH_SELECT) setPickColor(3, r->tag());
            drawArrays(this, r, r->va_clip_triangles, GL_TRIANGLES,
                       CTX::instance()->mesh.light);
            if(render_mode == GMSH_SELECT) unsetPickColor();
          }
        }
        _mergedLines = (merge && !cutOnly && ma.lines[3]);
        _mergedTriangles = (merge && !cutOnly && ma.triangles[3]);
        if(!cutOnly && needPerEntityPass(this, 3, _mergedLines, _mergedTriangles))
          std::for_each(m->firstRegion(), m->lastRegion(),
                        drawMeshGRegion(this));
        _mergedLines = _mergedTriangles = false;
      }
      // after the edges and the faces, as the entities drew their nodes: a
      // node is then covered by the lines that meet at it, as it always was
      if(_mergedPoints) {
        fillMergedPoints(m, ma, status);
        gmshLightTwoSide(false);
        if(volumeOnly || cutOnly) setMeshClipPlanes(true);
        drawMergedArray(this, ma.points, GL_POINTS, false);
      }
      _mergedPoints = false;
    }
  }

  for(int i = 0; i < 6; i++) gmshClipPlaneOn(i, false);
}
