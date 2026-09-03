// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
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
#include "OS.h"
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
  // CTX::instance() is not inlined across translation units: look it up once,
  // as this is called for every element
  CTX *ctx = CTX::instance();
  if(ele->getVisibility() > 1) { // selection
    return ctx->color.geom.selection;
  }
  else if(ctx->mesh.colorCarousel == 0) { // by element type
    switch(ele->getType()) {
    case TYPE_LIN: return ctx->color.mesh.line;
    case TYPE_TRI: return ctx->color.mesh.triangle;
    case TYPE_QUA: return ctx->color.mesh.quadrangle;
    case TYPE_TET: return ctx->color.mesh.tetrahedron;
    case TYPE_HEX: return ctx->color.mesh.hexahedron;
    case TYPE_PRI: return ctx->color.mesh.prism;
    case TYPE_PYR: return ctx->color.mesh.pyramid;
    case TYPE_TRIH: return ctx->color.mesh.trihedron;
    default: return ctx->color.mesh.node;
    }
  }
  else if(ctx->mesh.colorCarousel == 3) { // by partition
    return ctx->color.mesh.carousel[std::abs(ele->getPartition() % 20)];
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
  // as in getColorByElement(), look the context up only once
  CTX *ctx = CTX::instance();
  if(ctx->mesh.qualitySup) {
    double q;
    if(ctx->mesh.qualityType == 3)
      q = ele->distoShapeMeasure();
    else if(ctx->mesh.qualityType == 2)
      q = ele->gammaShapeMeasure();
    else if(ctx->mesh.qualityType == 1)
      q = ele->minSIGEShapeMeasure();
    else
      q = ele->minSICNShapeMeasure();
    if(q < ctx->mesh.qualityInf || q > ctx->mesh.qualitySup) return false;
  }
  if(ctx->mesh.radiusSup) {
    double r = ele->maxEdge();
    if(r < ctx->mesh.radiusInf || r > ctx->mesh.radiusSup) return false;
  }
  if(ctx->clipWholeElements) {
    bool hidden = false;
    for(int clip = 0; clip < 6; clip++) {
      if(ctx->mesh.clip & (1 << clip)) {
        if(ele->getDim() < 3 && ctx->clipOnlyVolume) {}
        else {
          double d = intersectClipPlane(clip, ele);
          if(ele->getDim() == 3 && ctx->clipOnlyDrawIntersectingVolume && d) {
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

template <class T> static bool areOnlySomeElementsVisible(std::vector<T *> &elements)
{
  bool visible = false, hidden = false;
  for(std::size_t i = 0; i < elements.size(); i++) {
    bool v = isElementVisible(elements[i]);
    if(v) visible = true;
    else hidden = true;
    if(hidden && visible) return true;
  }
  return false;
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

// The faces interior to a 3D mesh are hidden by its skin, so there is no point
// in drawing them - not even with transparency, since they are exactly covered
// by the elements on either side. This only holds if the elements are not
// exploded, and if no clip plane cuts through them and opens up the interior.
static bool removeInteriorFaces()
{
  // make sure the mode has been read from the environment
  VertexArray::uniqueFilterEnabled();
  if(VertexArray::unique < 3 && !CTX::instance()->mesh.drawSkinOnly)
    return false;
  if(CTX::instance()->mesh.explode != 1.) return false;
  if(CTX::instance()->mesh.clip && !CTX::instance()->clipWholeElements)
    return false;
  return true;
}

// number of face representations per topological face, or 0 if they do not map
// onto each other
static int repPerFace(MElement *ele, bool curved)
{
  int numRep = ele->getNumFacesRep(curved), numFaces = ele->getNumFaces();
  if(numFaces <= 0 || numRep <= 0 || numRep % numFaces) return 0;
  return numRep / numFaces;
}

// First pass: a face shared by two visible elements is interior, and is hidden
// by the skin of the mesh. Insert each face and cancel it when it is seen a
// second time, so that the filter is left holding exactly the faces that bound
// the mesh - far fewer than the interior ones, so the table stays small and hot
// instead of growing to the total number of faces.
template <class T>
static void markBoundaryFaces(std::vector<T *> &elements,
                              UniqueElementFilter *boundary, int nthreads)
{
#pragma omp parallel for schedule(static) num_threads(nthreads)
  for(std::size_t i = 0; i < elements.size(); i++) {
    MElement *ele = elements[i];
    if(!isElementVisible(ele) || ele->getDim() < 3) continue;
    const bool curved =
      (ele->getPolynomialOrder() > 1) &&
      (ele->maxDistToStraight() > curvedRepTol * ele->getInnerRadius());
    if(!repPerFace(ele, curved)) continue;
    for(int j = 0; j < ele->getNumFaces(); j++) {
      MFace fa = ele->getFace(j);
      boundary->insertOrErase(
        0, fa.getVertex(0), fa.getVertex(1), fa.getVertex(2),
        fa.getNumVertices() > 3 ? fa.getVertex(3) : nullptr);
    }
  }
}

template <class T>
static void addElementsInArrays(GEntity *e, std::vector<T *> &elements,
                                bool edges, bool faces,
                                UniqueElementFilter *interior = nullptr)
{
  int nthreads = CTX::instance()->numThreads;
  if(!nthreads) nthreads = Msg::GetMaxThreads();
  if(elements.size() < 1000) nthreads = 1;

  // each thread fills its own vertex arrays, which are merged below: this
  // avoids the critical sections that used to serialize the whole loop
  std::vector<VertexArray *> vaLines(nthreads, nullptr);
  std::vector<VertexArray *> vaTriangles(nthreads, nullptr);
  if(nthreads == 1) {
    vaLines[0] = e->va_lines;
    vaTriangles[0] = e->va_triangles;
  }
  else {
    int n = (int)(elements.size() / nthreads) + 100;
    // the threads share the filter of the entity's own arrays, so that an
    // element is dropped whichever thread sees it first, and so that the filter
    // survives across the successive calls made for each element type
    UniqueElementFilter *fl =
      e->va_lines ? e->va_lines->getUniqueFilter(true) : nullptr;
    UniqueElementFilter *ft =
      e->va_triangles ? e->va_triangles->getUniqueFilter(true) : nullptr;
    for(int t = 0; t < nthreads; t++) {
      if(edges) {
        vaLines[t] = new VertexArray(2, 6 * n);
        vaLines[t]->setUniqueFilter(fl);
      }
      if(faces) {
        vaTriangles[t] = new VertexArray(3, 4 * n);
        vaTriangles[t]->setUniqueFilter(ft);
      }
    }
  }

  // static scheduling, merged in thread order, keeps the arrays in the same
  // order as in a serial run
  const double explode = CTX::instance()->mesh.explode;
  const bool smooth = CTX::instance()->mesh.smoothNormals;
  const bool pick = CTX::instance()->pickElements;
  // the filter is only worth it on edges, which are shared by many elements; it
  // finds nothing at all when the elements are exploded, since no two of them
  // then share any coordinate
  const bool filtering =
    VertexArray::uniqueFilterEnabled() && (explode == 1.) && !pick;
  // GMSH_UNIQUE_VA=2 also filters the faces, which are shared by at most two
  // elements and thus give a smaller reduction than the edges
  const bool filterF = (VertexArray::unique > 1);
  const bool uniqueEdges = (e->dim() > 1 && filtering);
  const bool uniqueFaces = (e->dim() > 2 && filtering && filterF);

  // when the elements have a topology, identify a duplicated edge by its two
  // vertices rather than by the coordinates of its corners: this is both
  // cheaper and exact, and it lets us skip getEdgeRep() altogether for the
  // edges that have already been drawn
  UniqueElementFilter *filter =
    (uniqueEdges && e->va_lines) ?
      e->va_lines->getUniqueFilter(nthreads > 1) : nullptr;
  UniqueElementFilter *filterFaces =
    (uniqueFaces && e->va_triangles) ?
      e->va_triangles->getUniqueFilter(nthreads > 1) : nullptr;
  // size the tables up front: growing them by successive doublings costs about
  // as much as the lookups themselves
  if(filter) filter->reserve(2 * elements.size());
  if(filterFaces) filterFaces->reserve(2 * elements.size());

  long int numIn = 0, numKept = 0;

#pragma omp parallel for schedule(static) num_threads(nthreads) \
  reduction(+ : numIn, numKept)
  for(std::size_t i = 0; i < elements.size(); i++) {
    MElement *ele = elements[i];

    if(!isElementVisible(ele) || ele->getDim() < 1) continue;

    VertexArray *vaLine = vaLines[Msg::GetThreadNum()];
    VertexArray *vaTriangle = vaTriangles[Msg::GetThreadNum()];

    unsigned int c = getColorByElement(ele);
    unsigned int col[4] = {c, c, c, c};

    const bool curved =
      (ele->getPolynomialOrder() > 1) &&
      (ele->maxDistToStraight() > curvedRepTol * ele->getInnerRadius());

    SPoint3 pc(0., 0., 0.);
    if(explode != 1.) pc = ele->barycenter();

    if(edges) {
      int numRep = ele->getNumEdgesRep(curved);
      // the representation of a curved edge is subdivided, and does not map one
      // to one onto the topological edges: fall back on the coordinates
      bool topo = (filter && numRep == ele->getNumEdges());
      bool unique = uniqueEdges && !topo;
      for(int j = 0; j < numRep; j++) {
        if(topo) {
          MEdge ed = ele->getEdge(j);
          numIn += 2;
          if(filter->isDuplicate(c, ed.getMinVertex(), ed.getMaxVertex()))
            continue;
          numKept += 2;
        }
        double x[2], y[2], z[2];
        SVector3 n[2];
        ele->getEdgeRep(curved, j, x, y, z, n);
        if(explode != 1.) {
          for(int k = 0; k < 2; k++) {
            x[k] = pc[0] + explode * (x[k] - pc[0]);
            y[k] = pc[1] + explode * (y[k] - pc[1]);
            z[k] = pc[2] + explode * (z[k] - pc[2]);
          }
        }
        if(e->dim() == 2 && smooth)
          for(int k = 0; k < 2; k++)
            e->model()->normals->get(x[k], y[k], z[k], n[k][0], n[k][1],
                                     n[k][2]);
        vaLine->add(x, y, z, n, col, ele, unique);
      }
    }

    if(faces) {
      int numRep = ele->getNumFacesRep(curved);
      bool topo = (filterFaces && numRep == ele->getNumFaces());
      bool unique = uniqueFaces && !topo;
      int perFace = interior ? repPerFace(ele, curved) : 0;
      for(int j = 0; j < numRep; j++) {
        if(perFace) {
          // only the faces that bound the mesh are drawn
          MFace fa = ele->getFace(j / perFace);
          if(!interior->contains(
               0, fa.getVertex(0), fa.getVertex(1), fa.getVertex(2),
               fa.getNumVertices() > 3 ? fa.getVertex(3) : nullptr))
            continue;
        }
        if(topo) {
          MFace fa = ele->getFace(j);
          numIn += 3;
          if(filterFaces->isDuplicate(
               c, fa.getVertex(0), fa.getVertex(1), fa.getVertex(2),
               fa.getNumVertices() > 3 ? fa.getVertex(3) : nullptr))
            continue;
          numKept += 3;
        }
        double x[3], y[3], z[3];
        SVector3 n[3];
        ele->getFaceRep(curved, j, x, y, z, n);
        if(explode != 1.) {
          for(int k = 0; k < 3; k++) {
            x[k] = pc[0] + explode * (x[k] - pc[0]);
            y[k] = pc[1] + explode * (y[k] - pc[1]);
            z[k] = pc[2] + explode * (z[k] - pc[2]);
          }
        }
        if(e->dim() == 2 && smooth)
          for(int k = 0; k < 3; k++)
            e->model()->normals->get(x[k], y[k], z[k], n[k][0], n[k][1],
                                     n[k][2]);
        vaTriangle->add(x, y, z, n, col, ele, unique);
      }
    }
  }

  VertexArray::statUniqueIn += numIn;
  VertexArray::statUniqueKept += numKept;

  if(nthreads == 1) return;

  for(int t = 0; t < nthreads; t++) {
    if(vaLines[t]) {
      e->va_lines->merge(vaLines[t]);
      delete vaLines[t];
    }
    if(vaTriangles[t]) {
      e->va_triangles->merge(vaTriangles[t]);
      delete vaTriangles[t];
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
    e->setOnlySomeElementsVisible(areOnlySomeElementsVisible(e->lines));

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
    f->setOnlySomeElementsVisible(areOnlySomeElementsVisible(f->triangles) ||
                                  areOnlySomeElementsVisible(f->quadrangles));

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
    r->setOnlySomeElementsVisible(areOnlySomeElementsVisible(r->tetrahedra) ||
                                  areOnlySomeElementsVisible(r->hexahedra) ||
                                  areOnlySomeElementsVisible(r->prisms) ||
                                  areOnlySomeElementsVisible(r->pyramids) ||
                                  areOnlySomeElementsVisible(r->trihedra));

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

      // locate the interior faces before filling the arrays: all the element
      // types have to be seen before any of them can be drawn
      UniqueElementFilter *interior = nullptr;
      if(fac && removeInteriorFaces()) {
        int nth = CTX::instance()->numThreads;
        if(!nth) nth = Msg::GetMaxThreads();
        double t1 = TimeOfDay();
        interior = new UniqueElementFilter(nth > 1);
        if(CTX::instance()->mesh.tetrahedra)
          markBoundaryFaces(r->tetrahedra, interior, nth);
        if(CTX::instance()->mesh.hexahedra)
          markBoundaryFaces(r->hexahedra, interior, nth);
        if(CTX::instance()->mesh.prisms)
          markBoundaryFaces(r->prisms, interior, nth);
        if(CTX::instance()->mesh.pyramids)
          markBoundaryFaces(r->pyramids, interior, nth);
        if(CTX::instance()->mesh.trihedra)
          markBoundaryFaces(r->trihedra, interior, nth);
        markBoundaryFaces(r->polyhedra, interior, nth);
        Msg::Info("Located the boundary faces of volume %d in %g s", r->tag(),
                  TimeOfDay() - t1);
      }

      if(CTX::instance()->mesh.tetrahedra)
        addElementsInArrays(r, r->tetrahedra, edg, fac, interior);
      if(CTX::instance()->mesh.hexahedra)
        addElementsInArrays(r, r->hexahedra, edg, fac, interior);
      if(CTX::instance()->mesh.prisms)
        addElementsInArrays(r, r->prisms, edg, fac, interior);
      if(CTX::instance()->mesh.pyramids)
        addElementsInArrays(r, r->pyramids, edg, fac, interior);
      if(CTX::instance()->mesh.trihedra)
        addElementsInArrays(r, r->trihedra, edg, fac, interior);
      addElementsInArrays(r, r->polyhedra, edg, fac, interior);
      delete interior;
      r->va_lines->finalize();
      r->va_triangles->finalize();
    }
  }
};

bool GModel::fillVertexArrays()
{
  if(!getVisibility() || !CTX::instance()->mesh.changed) return false;

  Msg::Debug("Mesh has changed: reinitializing vertex arrays");

  double tStart = TimeOfDay();
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

  Msg::Info("Vertex arrays built in %g s", TimeOfDay() - tStart);
  VertexArray::printStats();
  return true;
}
