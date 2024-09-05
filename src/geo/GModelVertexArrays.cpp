// Gmsh - Copyright (C) 1997-2023 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <cmath>
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
#include "VertexArray.h"
#include "SmoothData.h"

static const double curvedRepTol = 1.e-5;

unsigned int getColorByEntity(GEntity *e)
{
  if(e->getSelection()) { // selection
    return CTX::instance()->color.geom.selection;
  }
  else if(e->useColor()) { // forced from a script
    return e->getColor();
  }
  else if(CTX::instance()->mesh.colorCarousel == 1) { // by elementary entity
    return CTX::instance()->color.mesh.carousel[abs(e->tag() % 20)];
  }
  else if(CTX::instance()->mesh.colorCarousel == 2) { // by physical entity
    int np = e->physicals.size();
    int p = np ? e->physicals[np - 1] : 0;
    return CTX::instance()->color.mesh.carousel[abs(p % 20)];
  }
  else {
    return CTX::instance()->color.fg;
  }
}

static unsigned int getColorByElement(MElement *ele)
{
  if(ele->getVisibility() > 1) { // selection
    return CTX::instance()->color.geom.selection;
  }
  else if(CTX::instance()->mesh.colorCarousel == 0) { // by element type
    switch(ele->getType()) {
    case TYPE_LIN: return CTX::instance()->color.mesh.line;
    case TYPE_TRI: return CTX::instance()->color.mesh.triangle;
    case TYPE_QUA: return CTX::instance()->color.mesh.quadrangle;
    case TYPE_TET: return CTX::instance()->color.mesh.tetrahedron;
    case TYPE_HEX: return CTX::instance()->color.mesh.hexahedron;
    case TYPE_PRI: return CTX::instance()->color.mesh.prism;
    case TYPE_PYR: return CTX::instance()->color.mesh.pyramid;
    case TYPE_TRIH: return CTX::instance()->color.mesh.trihedron;
    default: return CTX::instance()->color.mesh.node;
    }
  }
  else if(CTX::instance()->mesh.colorCarousel == 3) { // by partition
    return CTX::instance()
      ->color.mesh.carousel[std::abs(ele->getPartition() % 20)];
  }
  else {
    // by elementary or physical entity (this is not perfect (since
    // e.g. a triangle can have no vertices categorized on a surface),
    // but it's the best we can do "fast" since we don't store the
    // associated entity in the element
    for(std::size_t i = 0; i < ele->getNumVertices(); i++) {
      GEntity *e = ele->getVertex(i)->onWhat();
      if(e && (e->dim() == ele->getDim())) return getColorByEntity(e);
    }
  }
  return CTX::instance()->color.fg;
}

static double evalClipPlane(int clip, double x, double y, double z)
{
  return CTX::instance()->clipPlane[clip][0] * x +
         CTX::instance()->clipPlane[clip][1] * y +
         CTX::instance()->clipPlane[clip][2] * z +
         CTX::instance()->clipPlane[clip][3];
}

static double intersectClipPlane(int clip, MElement *ele)
{
  MVertex *v = ele->getVertex(0);
  double val = evalClipPlane(clip, v->x(), v->y(), v->z());
  for(std::size_t i = 1; i < ele->getNumVertices(); i++) {
    v = ele->getVertex(i);
    if(val * evalClipPlane(clip, v->x(), v->y(), v->z()) <= 0)
      return 0.; // the element intersects the cut plane
  }
  return val;
}

bool isElementVisible(MElement *ele)
{
  if(!ele->getVisibility()) return false;
  if(CTX::instance()->mesh.qualitySup) {
    double q;
    if(CTX::instance()->mesh.qualityType == 3)
      q = ele->distoShapeMeasure();
    else if(CTX::instance()->mesh.qualityType == 2)
      q = ele->gammaShapeMeasure();
    else if(CTX::instance()->mesh.qualityType == 1)
      q = ele->minSIGEShapeMeasure();
    else
      q = ele->minSICNShapeMeasure();
    if(q < CTX::instance()->mesh.qualityInf ||
       q > CTX::instance()->mesh.qualitySup)
      return false;
  }
  if(CTX::instance()->mesh.radiusSup) {
    double r = ele->maxEdge();
    if(r < CTX::instance()->mesh.radiusInf ||
       r > CTX::instance()->mesh.radiusSup)
      return false;
  }
  if(CTX::instance()->clipWholeElements) {
    bool hidden = false;
    for(int clip = 0; clip < 6; clip++) {
      if(CTX::instance()->mesh.clip & (1 << clip)) {
        if(ele->getDim() < 3 && CTX::instance()->clipOnlyVolume) {}
        else {
          double d = intersectClipPlane(clip, ele);
          if(ele->getDim() == 3 &&
             CTX::instance()->clipOnlyDrawIntersectingVolume && d) {
            hidden = true;
            break;
          }
          else if(d < 0) {
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

template <class T> static bool areAllElementsVisible(std::vector<T *> &elements)
{
  for(std::size_t i = 0; i < elements.size(); i++)
    if(!isElementVisible(elements[i])) return false;
  return true;
}

template <class T> static bool areSomeElementsCurved(std::vector<T *> &elements)
{
  for(std::size_t i = 0; i < elements.size(); i++)
    if(elements[i]->getPolynomialOrder() > 1) return true;
  return false;
}

template <class T>
static void addSmoothNormals(GEntity *e, std::vector<T *> &elements)
{
  for(std::size_t i = 0; i < elements.size(); i++) {
    MElement *ele = elements[i];
    const bool curved =
      (ele->getPolynomialOrder() > 1) &&
      (ele->maxDistToStraight() > curvedRepTol * ele->getInnerRadius());
    SPoint3 pc(0., 0., 0.);
    if(CTX::instance()->mesh.explode != 1.) pc = ele->barycenter();
    for(int j = 0; j < ele->getNumFacesRep(curved); j++) {
      double x[3], y[3], z[3];
      SVector3 n[3];
      ele->getFaceRep(curved, j, x, y, z, n);
      for(int k = 0; k < 3; k++) {
        if(CTX::instance()->mesh.explode != 1.) {
          x[k] = pc[0] + CTX::instance()->mesh.explode * (x[k] - pc[0]);
          y[k] = pc[1] + CTX::instance()->mesh.explode * (y[k] - pc[1]);
          z[k] = pc[2] + CTX::instance()->mesh.explode * (z[k] - pc[2]);
        }
        e->model()->normals->add(x[k], y[k], z[k], n[k][0], n[k][1], n[k][2]);
      }
    }
  }
}

template <class T>
static void addElementsInArrays(GEntity *e, std::vector<T *> &elements,
                                bool edges, bool faces)
{
  int nthreads = CTX::instance()->numThreads;
  if(!nthreads) nthreads = Msg::GetMaxThreads();
#pragma omp parallel for schedule(dynamic) num_threads(nthreads)
  for(std::size_t i = 0; i < elements.size(); i++) {
    MElement *ele = elements[i];

    if(!isElementVisible(ele) || ele->getDim() < 1) continue;

    unsigned int c = getColorByElement(ele);
    unsigned int col[4] = {c, c, c, c};

    const bool curved =
      (ele->getPolynomialOrder() > 1) &&
      (ele->maxDistToStraight() > curvedRepTol * ele->getInnerRadius());

    SPoint3 pc(0., 0., 0.);
    if(CTX::instance()->mesh.explode != 1.) pc = ele->barycenter();

    if(edges) {
      bool unique = e->dim() > 1 && !CTX::instance()->pickElements;
      for(int j = 0; j < ele->getNumEdgesRep(curved); j++) {
        double x[2], y[2], z[2];
        SVector3 n[2];
        ele->getEdgeRep(curved, j, x, y, z, n);
        if(CTX::instance()->mesh.explode != 1.) {
          for(int k = 0; k < 2; k++) {
            x[k] = pc[0] + CTX::instance()->mesh.explode * (x[k] - pc[0]);
            y[k] = pc[1] + CTX::instance()->mesh.explode * (y[k] - pc[1]);
            z[k] = pc[2] + CTX::instance()->mesh.explode * (z[k] - pc[2]);
          }
        }
        if(e->dim() == 2 && CTX::instance()->mesh.smoothNormals)
          for(int k = 0; k < 2; k++)
            e->model()->normals->get(x[k], y[k], z[k], n[k][0], n[k][1],
                                     n[k][2]);
#pragma omp critical
        {
          e->va_lines->add(x, y, z, n, col, ele, unique);
        }
      }
    }

    if(faces) {
      bool unique = e->dim() > 2 && !CTX::instance()->pickElements;
      bool skin = e->dim() > 2 && CTX::instance()->mesh.drawSkinOnly;
      for(int j = 0; j < ele->getNumFacesRep(curved); j++) {
        double x[3], y[3], z[3];
        SVector3 n[3];
        ele->getFaceRep(curved, j, x, y, z, n);
        if(CTX::instance()->mesh.explode != 1.) {
          for(int k = 0; k < 3; k++) {
            x[k] = pc[0] + CTX::instance()->mesh.explode * (x[k] - pc[0]);
            y[k] = pc[1] + CTX::instance()->mesh.explode * (y[k] - pc[1]);
            z[k] = pc[2] + CTX::instance()->mesh.explode * (z[k] - pc[2]);
          }
        }
        if(e->dim() == 2 && CTX::instance()->mesh.smoothNormals)
          for(int k = 0; k < 3; k++)
            e->model()->normals->get(x[k], y[k], z[k], n[k][0], n[k][1],
                                     n[k][2]);
#pragma omp critical
        {
          e->va_triangles->add(x, y, z, n, col, ele, unique, skin);
        }
      }
    }
  }
}

class initMeshGEdge {
private:
  int _estimateNumLines(GEdge *e)
  {
    int num = 0;
    if(CTX::instance()->mesh.lines) {
      num += e->lines.size();
      if(areSomeElementsCurved(e->lines)) num *= 2;
    }
    return num + 100;
  }

public:
  void operator()(GEdge *e)
  {
    e->deleteVertexArrays();
    if(!e->getVisibility()) return;
    e->setAllElementsVisible(areAllElementsVisible(e->lines));

    if(CTX::instance()->mesh.lines) {
      e->va_lines = new VertexArray(2, _estimateNumLines(e));
      addElementsInArrays(e, e->lines, CTX::instance()->mesh.lines, false);
      e->va_lines->finalize();
    }
  }
};

class initSmoothNormalsGFace {
public:
  void operator()(GFace *f)
  {
    addSmoothNormals(f, f->triangles);
    addSmoothNormals(f, f->quadrangles);
    addSmoothNormals(f, f->polygons);
  }
};

class initMeshGFace {
private:
  bool _curved;
  int _estimateNumLines(GFace *f)
  {
    int num = 0;
    if(CTX::instance()->mesh.surfaceEdges) {
      num += (3 * f->triangles.size() + 4 * f->quadrangles.size() +
              4 * f->polygons.size()) /
             2;
      if(CTX::instance()->mesh.explode != 1.) num *= 2;
      if(_curved) num *= 2;
    }
    return num + 100;
  }
  int _estimateNumTriangles(GFace *f)
  {
    int num = 0;
    if(CTX::instance()->mesh.surfaceFaces) {
      num += (f->triangles.size() + 2 * f->quadrangles.size() +
              2 * f->polygons.size());
      if(_curved) num *= 4;
    }
    return num + 100;
  }

public:
  void operator()(GFace *f)
  {
    f->deleteVertexArrays();
    if(!f->getVisibility()) return;
    f->setAllElementsVisible(areAllElementsVisible(f->triangles) &&
                             areAllElementsVisible(f->quadrangles));

    bool edg = CTX::instance()->mesh.surfaceEdges;
    bool fac = CTX::instance()->mesh.surfaceFaces;
    if(edg || fac) {
      _curved = (areSomeElementsCurved(f->triangles) ||
                 areSomeElementsCurved(f->quadrangles));
      f->va_lines = new VertexArray(2, edg ? _estimateNumLines(f) : 100);
      f->va_triangles =
        new VertexArray(3, fac ? _estimateNumTriangles(f) : 100);
      if(CTX::instance()->mesh.triangles)
        addElementsInArrays(f, f->triangles, edg, fac);
      if(CTX::instance()->mesh.quadrangles)
        addElementsInArrays(f, f->quadrangles, edg, fac);
      addElementsInArrays(f, f->polygons, edg, fac);
      f->va_lines->finalize();
      f->va_triangles->finalize();
    }
  }
};

class initMeshGRegion {
private:
  bool _curved;
  int _estimateIfClipped(int num)
  {
    if(CTX::instance()->clipWholeElements) {
      for(int clip = 0; clip < 6; clip++) {
        if(CTX::instance()->mesh.clip & (1 << clip)) {
          if(CTX::instance()->clipOnlyDrawIntersectingVolume) {
            // let be more aggressive than num^{2/3}
            return (int)sqrt((double)num);
          }
          else {
            // why not :-)
            return num / 4;
          }
        }
      }
    }
    return num;
  }
  int _estimateNumLines(GRegion *r)
  {
    int num = 0;
    if(CTX::instance()->mesh.volumeEdges) {
      // suppose edge shared by 4 elements on averge (pessmistic)
      int numLP = 0;
      for(std::size_t i = 0; i < r->polyhedra.size(); i++)
        numLP += 2 * r->polyhedra[i]->getNumEdges();
      num += (12 * r->tetrahedra.size() + 24 * r->hexahedra.size() +
              18 * r->prisms.size() + 16 * r->pyramids.size() +
              10 * r->trihedra.size() + numLP) /
             4;
      num = _estimateIfClipped(num);
      if(CTX::instance()->mesh.explode != 1.) num *= 4;
      if(_curved) num *= 2;
    }
    return num + 100;
  }
  int _estimateNumTriangles(GRegion *r)
  {
    int num = 0;
    if(CTX::instance()->mesh.volumeFaces) {
      int numFP = 0;
      for(std::size_t i = 0; i < r->polyhedra.size(); i++)
        numFP += r->polyhedra[i]->getNumFaces();
      num += (4 * r->tetrahedra.size() + 12 * r->hexahedra.size() +
              8 * r->prisms.size() + 6 * r->pyramids.size() +
              4 * r->trihedra.size() + numFP) /
             2;
      num = _estimateIfClipped(num);
      if(CTX::instance()->mesh.explode != 1.) num *= 2;
      if(_curved) num *= 4;
    }
    return num + 100;
  }

public:
  void operator()(GRegion *r)
  {
    r->deleteVertexArrays();
    if(!r->getVisibility()) return;
    r->setAllElementsVisible(areAllElementsVisible(r->tetrahedra) &&
                             areAllElementsVisible(r->hexahedra) &&
                             areAllElementsVisible(r->prisms) &&
                             areAllElementsVisible(r->pyramids) &&
                             areAllElementsVisible(r->trihedra));

    bool edg = CTX::instance()->mesh.volumeEdges;
    bool fac = CTX::instance()->mesh.volumeFaces;
    if(edg || fac) {
      _curved = (areSomeElementsCurved(r->tetrahedra) ||
                 areSomeElementsCurved(r->hexahedra) ||
                 areSomeElementsCurved(r->prisms) ||
                 areSomeElementsCurved(r->pyramids) ||
                 areSomeElementsCurved(r->trihedra));
      r->va_lines = new VertexArray(2, edg ? _estimateNumLines(r) : 100);
      r->va_triangles =
        new VertexArray(3, fac ? _estimateNumTriangles(r) : 100);
      if(CTX::instance()->mesh.tetrahedra)
        addElementsInArrays(r, r->tetrahedra, edg, fac);
      if(CTX::instance()->mesh.hexahedra)
        addElementsInArrays(r, r->hexahedra, edg, fac);
      if(CTX::instance()->mesh.prisms)
        addElementsInArrays(r, r->prisms, edg, fac);
      if(CTX::instance()->mesh.pyramids)
        addElementsInArrays(r, r->pyramids, edg, fac);
      if(CTX::instance()->mesh.trihedra)
        addElementsInArrays(r, r->trihedra, edg, fac);
      addElementsInArrays(r, r->polyhedra, edg, fac);
      r->va_lines->finalize();
      r->va_triangles->finalize();
    }
  }
};

bool GModel::fillVertexArrays()
{
  if(!getVisibility() || !CTX::instance()->mesh.changed) return false;

  Msg::Debug("Mesh has changed: reinitializing vertex arrays");

  int status = getMeshStatus();

  if(status >= 1 && CTX::instance()->mesh.changed & ENT_CURVE)
    std::for_each(firstEdge(), lastEdge(), initMeshGEdge());

  if(status >= 2 && CTX::instance()->mesh.changed & ENT_SURFACE) {
    if(normals) delete normals;
    normals = new smooth_normals(CTX::instance()->mesh.angleSmoothNormals);
    if(CTX::instance()->mesh.smoothNormals)
      std::for_each(firstFace(), lastFace(), initSmoothNormalsGFace());
    std::for_each(firstFace(), lastFace(), initMeshGFace());
  }

  if(status >= 3 && CTX::instance()->mesh.changed & ENT_VOLUME)
    std::for_each(firstRegion(), lastRegion(), initMeshGRegion());
  return true;
}
