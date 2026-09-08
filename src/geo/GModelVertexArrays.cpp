// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <cmath>
#include <map>
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
#include "Iso.h"

// how many edges or faces of one element are hashed and prefetched together
// before being looked up; elements with more than this fall back on looking
// them up one at a time
enum { MAX_BATCHED_EDGES = 32, MAX_BATCHED_FACES = 8 };

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
  // Nothing about the clipping planes here on purpose: the arrays are built
  // once and OpenGL applies the planes, so that moving one costs nothing but a
  // redraw. What whole element mode used to leave out is drawn back from
  // va_clip_*, and what capping used to add is built there too.
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

// Drop the faces interior to a 3D mesh, i.e. those shared by two elements of
// the same entity, when the user asked for the skin only. They are gone, not
// merely hidden, whatever else is going on: clipping, exploding or drawing the
// mesh with transparency will show what is left, which is what the option is
// for. The one thing that is not a matter of taste is picking, which cannot
// reach an element that is not in the arrays.
static bool removeInteriorFaces()
{
  if(!CTX::instance()->mesh.drawSkinOnly) return false;
  if(CTX::instance()->pickElements) return false;
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
    // as when the edges are filtered: hash the faces of the element and ask
    // for their table entries before touching any of them
    MVertex *fv[4];
    int nf = ele->getNumFaces();
    std::uint64_t hash[MAX_BATCHED_FACES];
    for(int j0 = 0; j0 < nf; j0 += MAX_BATCHED_FACES) {
      int n = std::min(nf - j0, (int)MAX_BATCHED_FACES);
      for(int j = 0; j < n; j++) {
        int nc = ele->getFaceCorners(j0 + j, fv);
        if(!nc) { // no corner accessor: fall back on the sorted face
          MFace fa = ele->getFace(j0 + j);
          nc = (int)fa.getNumVertices();
          for(int i = 0; i < nc && i < 4; i++) fv[i] = fa.getVertex(i);
        }
        hash[j] =
          boundary->hashOf(0, fv[0], fv[1], fv[2], nc > 3 ? fv[3] : nullptr);
        boundary->prefetch(hash[j]);
      }
      for(int j = 0; j < n; j++) boundary->insertOrErase(hash[j]);
    }
  }
}

// Add the section a clipping plane cuts out of an element to the array. The
// section is moved by a fraction of the model size towards the side the plane
// keeps, so that the plane that produced it does not clip it away again; the
// other planes still do, which is what makes several planes work together
static void addCapInArray(VertexArray *va, MElement *ele, unsigned int *col)
{
  int nv = ele->getNumPrimaryVertices();
  int ne = ele->getNumEdges();
  if(nv < 4 || ne < 6 || ne > 12) return; // not a convex 3D element we can cut

  for(int c = 0; c < 6; c++) {
    if(!(CTX::instance()->mesh.clip & (1 << c))) continue;
    double *pl = CTX::instance()->clipPlane[c];
    int neg = 0, pos = 0;
    for(int i = 0; i < nv; i++) {
      MVertex *v = ele->getVertex(i);
      if(evalClipPlane(c, v->x(), v->y(), v->z()) < 0.)
        neg++;
      else
        pos++;
    }
    if(!neg || !pos) continue; // the plane does not cut this element

    double n[3] = {pl[0], pl[1], pl[2]};
    double len = sqrt(n[0] * n[0] + n[1] * n[1] + n[2] * n[2]);
    if(len < 1.e-15) continue;
    for(int i = 0; i < 3; i++) n[i] /= len;

    double xp[12], yp[12], zp[12];
    int nb = 0;
    for(int j = 0; j < ne && nb < 12; j++) {
      MEdge ed = ele->getEdge(j);
      MVertex *a = ed.getVertex(0), *b = ed.getVertex(1);
      double da = evalClipPlane(c, a->x(), a->y(), a->z());
      double db = evalClipPlane(c, b->x(), b->y(), b->z());
      if((da < 0. && db < 0.) || (da >= 0. && db >= 0.)) continue;
      double t = (da == db) ? 0. : da / (da - db);
      double x = a->x() + t * (b->x() - a->x());
      double y = a->y() + t * (b->y() - a->y());
      double z = a->z() + t * (b->z() - a->z());
      // a plane through a corner crosses every edge that meets there
      bool same = false;
      for(int k = 0; k < nb; k++)
        if(fabs(x - xp[k]) < 1.e-12 && fabs(y - yp[k]) < 1.e-12 &&
           fabs(z - zp[k]) < 1.e-12) {
          same = true;
          break;
        }
      if(same) continue;
      xp[nb] = x;
      yp[nb] = y;
      zp[nb] = z;
      nb++;
    }
    if(nb < 3) continue;

    OrderPolygonInPlane(nb, n, xp, yp, zp, nullptr);

    double eps = 1.e-5 * CTX::instance()->lc;
    for(int i = 0; i < nb; i++) {
      xp[i] += eps * n[0];
      yp[i] += eps * n[1];
      zp[i] += eps * n[2];
    }

    SVector3 nn[3] = {SVector3(n[0], n[1], n[2]), SVector3(n[0], n[1], n[2]),
                      SVector3(n[0], n[1], n[2])};
    for(int j = 2; j < nb; j++) {
      double x[3] = {xp[0], xp[j - 1], xp[j]};
      double y[3] = {yp[0], yp[j - 1], yp[j]};
      double z[3] = {zp[0], zp[j - 1], zp[j]};
      va->add(x, y, z, nn, col, ele, false);
    }
  }
}

// The section the clipping planes cut out of the 3D elements. This is the one
// thing about the arrays that moving a plane changes, so it is built on its
// own and the rest is left exactly as it is: a plane can then be moved without
// the mesh being built again. Only the elements a plane actually cuts produce
// anything, so this is a slice through the model however big the model is.
// Does a plane cut through this element? Those are the ones whole element mode
// draws entire, and they are the only elements whose faces can lie between
// what is kept and what is removed: a fully visible element and a fully
// removed one cannot share a face, as its vertices would have to be on both
// sides at once.
static bool elementIsCut(MElement *ele)
{
  CTX *ctx = CTX::instance();
  for(int clip = 0; clip < 6; clip++) {
    if(!(ctx->mesh.clip & (1 << clip))) continue;
    if(ele->getDim() < 3 && ctx->clipOnlyVolume) continue;
    if(intersectClipPlane(clip, ele) == 0.) return true;
  }
  return false;
}

// Is this element kept by whole element mode? The elements a plane cuts are,
// and so are the ones entirely on the visible side; only those entirely beyond
// a plane are dropped. This is the test isElementVisible() used to make.
static bool elementIsKept(MElement *ele)
{
  CTX *ctx = CTX::instance();
  for(int clip = 0; clip < 6; clip++) {
    if(!(ctx->mesh.clip & (1 << clip))) continue;
    if(ele->getDim() < 3 && ctx->clipOnlyVolume) continue;
    double d = intersectClipPlane(clip, ele);
    if(ele->getDim() == 3 && ctx->clipOnlyDrawIntersectingVolume && d)
      return false;
    if(d < 0.) return false;
  }
  return true;
}

// The faces on the boundary of what whole element mode keeps. What is drawn is
// that boundary, so the faces between a kept element and a removed one count
// while those between two kept elements do not - which is why the boundary has
// to be worked out over the kept elements rather than over the whole mesh.
template <class T>
static void markKeptBoundaryFaces(std::vector<T *> &elements,
                                  UniqueElementFilter *bnd, int nthreads)
{
  std::vector<T *> kept;
  kept.reserve(elements.size());
  for(std::size_t i = 0; i < elements.size(); i++)
    if(isElementVisible(elements[i]) && elementIsKept(elements[i]))
      kept.push_back(elements[i]);
  markBoundaryFaces(kept, bnd, nthreads);
}

// The elements a plane cuts, gathered so that they can be drawn whole while
// OpenGL clips everything else.
template <class T>
static void gatherCutElements(std::vector<T *> &elements,
                              std::vector<T *> &cut)
{
  for(std::size_t i = 0; i < elements.size(); i++) {
    if(!isElementVisible(elements[i])) continue;
    // an element one plane cuts can still be entirely beyond another, and is
    // then not drawn at all: what is drawn whole here is not clipped again
    if(!elementIsKept(elements[i])) continue;
    if(!elementIsCut(elements[i])) continue;
    cut.push_back(elements[i]);
  }
}

template <class T>
static void addCapsInArray(GEntity *e, std::vector<T *> &elements)
{
  for(std::size_t i = 0; i < elements.size(); i++) {
    MElement *ele = elements[i];
    if(ele->getDim() != 3 || !isElementVisible(ele)) continue;
    unsigned int c = getColorByElement(ele);
    unsigned int col[4] = {c, c, c, c};
    addCapInArray(e->va_clip_triangles, ele, col);
  }
}

// vaL and vaT are where the lines and the triangles go: the entity's own
// arrays, or the ones held apart for what the clipping planes add.
template <class T>
static void addElementsInArrays(GEntity *e, VertexArray *vaL, VertexArray *vaT,
                                std::vector<T *> &elements, bool edges,
                                bool faces,
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
    vaLines[0] = vaL;
    vaTriangles[0] = vaT;
  }
  else {
    int n = (int)(elements.size() / nthreads) + 100;
    // the threads share the filter of the entity's own arrays, so that an
    // element is dropped whichever thread sees it first, and so that the filter
    // survives across the successive calls made for each element type
    UniqueElementFilter *fl = vaL ? vaL->getUniqueFilter(true) : nullptr;
    UniqueElementFilter *ft = vaT ? vaT->getUniqueFilter(true) : nullptr;
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
    CTX::instance()->mesh.drawUniqueEdges && (explode == 1.) && !pick;
  const bool uniqueEdges = (e->dim() > 1 && filtering);

  // when the elements have a topology, identify a duplicated edge by its two
  // vertices rather than by the coordinates of its corners: this is both
  // cheaper and exact, and it lets us skip getEdgeRep() altogether for the
  // edges that have already been drawn
  UniqueElementFilter *filter =
    (uniqueEdges && vaL) ? vaL->getUniqueFilter(nthreads > 1) : nullptr;
  // size the tables up front: growing them by successive doublings costs about
  // as much as the lookups themselves
  if(filter) filter->reserve(2 * elements.size());

  long int numIn = 0, numKept = 0;

#pragma omp parallel for schedule(static) num_threads(nthreads) \
  reduction(+ : numIn, numKept)
  for(std::size_t i = 0; i < elements.size(); i++) {
    MElement *ele = elements[i];

    if(!isElementVisible(ele) || ele->getDim() < 1) continue;

    const int tnum = (nthreads == 1) ? 0 : Msg::GetThreadNum();
    VertexArray *vaLine = vaLines[tnum];
    VertexArray *vaTriangle = vaTriangles[tnum];

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
      bool topo = (filter && numRep == ele->getNumEdges() &&
                   numRep <= MAX_BATCHED_EDGES);
      bool unique = uniqueEdges && !topo;
      // hash the edges of the element and ask for their table entries before
      // looking any of them up: the lookups are spread over a table far larger
      // than the caches, and would otherwise stall one after the other
      std::uint64_t hash[MAX_BATCHED_EDGES];
      if(topo) {
        for(int j = 0; j < numRep; j++) {
          MEdge ed = ele->getEdge(j);
          hash[j] = filter->hashOf(c, ed.getMinVertex(), ed.getMaxVertex());
          filter->prefetch(hash[j]);
        }
      }
      for(int j = 0; j < numRep; j++) {
        if(topo) {
          numIn += 2;
          if(filter->isDuplicate(hash[j])) continue;
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
      int perFace = interior ? repPerFace(ele, curved) : 0;
      // hash the faces of the element and ask for their table entries before
      // looking any of them up
      std::uint64_t interiorHash[MAX_BATCHED_FACES];
      int nf = perFace ? ele->getNumFaces() : 0;
      bool batched = (nf > 0 && nf <= MAX_BATCHED_FACES);
      for(int j = 0; batched && j < nf; j++) {
        MVertex *fv[4];
        int nc = ele->getFaceCorners(j, fv);
        if(!nc) {
          MFace fa = ele->getFace(j);
          nc = (int)fa.getNumVertices();
          for(int i = 0; i < nc && i < 4; i++) fv[i] = fa.getVertex(i);
        }
        interiorHash[j] =
          interior->hashOf(0, fv[0], fv[1], fv[2], nc > 3 ? fv[3] : nullptr);
        interior->prefetch(interiorHash[j]);
      }
      for(int j = 0; j < numRep; j++) {
        // only the faces that bound the mesh are drawn
        if(perFace) {
          bool bnd;
          if(batched)
            bnd = interior->contains(interiorHash[j / perFace]);
          else {
            MVertex *fv[4];
            int nc = ele->getFaceCorners(j / perFace, fv);
            if(!nc) {
              MFace fa = ele->getFace(j / perFace);
              nc = (int)fa.getNumVertices();
              for(int i = 0; i < nc && i < 4; i++) fv[i] = fa.getVertex(i);
            }
            bnd = interior->contains(0, fv[0], fv[1], fv[2],
                                     nc > 3 ? fv[3] : nullptr);
          }
          if(!bnd) continue;
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
        vaTriangle->add(x, y, z, n, col, ele, false);
      }
    }
  }

  VertexArray::statUniqueIn += numIn;
  VertexArray::statUniqueKept += numKept;

  if(nthreads == 1) return;

  for(int t = 0; t < nthreads; t++) {
    if(vaLines[t]) {
      vaL->merge(vaLines[t]);
      delete vaLines[t];
    }
    if(vaTriangles[t]) {
      vaT->merge(vaTriangles[t]);
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
      addElementsInArrays(e, e->va_lines, e->va_triangles, e->lines, CTX::instance()->mesh.lines, false);
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
        addElementsInArrays(f, f->va_lines, f->va_triangles, f->triangles, edg, fac);
      if(CTX::instance()->mesh.quadrangles)
        addElementsInArrays(f, f->va_lines, f->va_triangles, f->quadrangles, edg, fac);
      addElementsInArrays(f, f->va_lines, f->va_triangles, f->polygons, edg, fac);
      f->va_lines->finalize();
      f->va_triangles->finalize();
    }
  }
};

class initMeshGRegion {
private:
  bool _curved;
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
      if(CTX::instance()->mesh.explode != 1.) num *= 2;
      if(_curved) num *= 4;
    }
    return num + 100;
  }

public:
  int _estimateNumCaps(GRegion *r)
  {
    // the elements a plane cuts form a surface through the volume: there are
    // about as many of them as the 2/3 power of the number of elements
    std::size_t n = r->getNumMeshElements();
    return (int)(2. * pow((double)n, 2. / 3.)) + 100;
  }

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
        Msg::Debug("Located the boundary faces of volume %d in %g s", r->tag(),
                   TimeOfDay() - t1);
      }

      if(CTX::instance()->mesh.tetrahedra)
        addElementsInArrays(r, r->va_lines, r->va_triangles, r->tetrahedra, edg, fac, interior);
      if(CTX::instance()->mesh.hexahedra)
        addElementsInArrays(r, r->va_lines, r->va_triangles, r->hexahedra, edg, fac, interior);
      if(CTX::instance()->mesh.prisms)
        addElementsInArrays(r, r->va_lines, r->va_triangles, r->prisms, edg, fac, interior);
      if(CTX::instance()->mesh.pyramids)
        addElementsInArrays(r, r->va_lines, r->va_triangles, r->pyramids, edg, fac, interior);
      if(CTX::instance()->mesh.trihedra)
        addElementsInArrays(r, r->va_lines, r->va_triangles, r->trihedra, edg, fac, interior);
      addElementsInArrays(r, r->va_lines, r->va_triangles, r->polyhedra, edg, fac, interior);
      delete interior;
      r->va_lines->finalize();
      r->va_triangles->finalize();
    }
  }
};

// What each model's clip arrays were last built for. Rebuilding them when none
// of this has changed would be work at every frame for nothing; keyed by
// model, as several of them can be drawn one after the other in the same
// frame.
//
// Only what changes the arrays without marking the mesh as changed is in here:
// the planes and the clipping options that leave the mesh arrays alone. The
// capping option, what is drawn (edges, faces, each kind of element) and the
// visibility all set mesh.changed, and drawMesh() invalidates the arrays
// whenever it rebuilds the mesh ones.
static std::map<GModel *, std::vector<double> > _clipToken;

static std::vector<double> clipToken()
{
  CTX *ctx = CTX::instance();
  std::vector<double> t;
  t.push_back(ctx->mesh.clip);
  t.push_back(ctx->clipWholeElements);
  t.push_back(ctx->clipOnlyVolume);
  t.push_back(ctx->clipOnlyDrawIntersectingVolume);
  for(int i = 0; i < 6; i++)
    for(int j = 0; j < 4; j++) t.push_back(ctx->clipPlane[i][j]);
  return t;
}

void GModel::invalidateClipVertexArrays() { _clipToken.erase(this); }

// The elements of one entity that a plane cuts, drawn whole into its clip
// arrays. bnd, when given, is the boundary of what is kept, so that only the
// faces facing the removed side come out.
template <class T>
static void addCutElements(GEntity *e, std::vector<T *> &elements, bool edges,
                           bool faces, UniqueElementFilter *bnd)
{
  std::vector<T *> cut;
  gatherCutElements(elements, cut);
  if(cut.empty()) return;
  addElementsInArrays(e, e->va_clip_lines, e->va_clip_triangles, cut, edges,
                      faces, bnd);
}

// What the planes cut out of a curve or a surface. There is no interior to
// hide here, so the elements go in as they are.
static void fillCutEntity(GEntity *e, bool edges, bool faces, int est)
{
  e->va_clip_lines = new VertexArray(2, edges ? 6 * est : 100);
  e->va_clip_triangles = new VertexArray(3, faces ? 4 * est : 100);
  if(e->dim() == 1) {
    addCutElements(e, ((GEdge *)e)->lines, edges, false, nullptr);
  }
  else if(e->dim() == 2) {
    GFace *f = (GFace *)e;
    if(CTX::instance()->mesh.triangles)
      addCutElements(e, f->triangles, edges, faces, nullptr);
    if(CTX::instance()->mesh.quadrangles)
      addCutElements(e, f->quadrangles, edges, faces, nullptr);
    addCutElements(e, f->polygons, edges, faces, nullptr);
  }
  e->va_clip_lines->finalize();
  e->va_clip_triangles->finalize();
}

bool GModel::fillClipVertexArrays()
{
  std::vector<double> tok = clipToken();
  auto found = _clipToken.find(this);
  if(found != _clipToken.end() && found->second == tok) return false;
  _clipToken[this] = tok;

  CTX *ctx = CTX::instance();
  // The caps are worth computing only where the mesh is drawn as a surface,
  // and only when the planes are applied by OpenGL: in whole element mode the
  // elements a plane cuts are removed entire and there is no hole to fill.
  bool caps = ctx->clipCapping && !ctx->clipWholeElements && ctx->mesh.clip &&
              (ctx->mesh.volumeFaces || ctx->mesh.surfaceFaces);
  bool whole = ctx->clipWholeElements && ctx->mesh.clip;
  double t1 = TimeOfDay();
  std::size_t n = 0;
  for(auto it = firstEdge(); it != lastEdge(); it++)
    (*it)->deleteClipVertexArrays();
  for(auto it = firstFace(); it != lastFace(); it++)
    (*it)->deleteClipVertexArrays();
  for(auto it = firstRegion(); it != lastRegion(); it++) {
    GRegion *r = *it;
    r->deleteClipVertexArrays();
    if(!r->getVisibility() || (!caps && !whole)) continue;
    // A plane cuts a surface through the volume: there are about as many
    // elements on it as the 2/3 power of the ones in the volume, however many
    // that is. This is what makes holding it apart worth doing.
    std::size_t ne = r->getNumMeshElements();
    int est = (int)(2. * pow((double)ne, 2. / 3.)) + 100;

    if(caps) {
      r->va_clip_triangles = new VertexArray(3, est);
      if(ctx->mesh.tetrahedra) addCapsInArray(r, r->tetrahedra);
      if(ctx->mesh.hexahedra) addCapsInArray(r, r->hexahedra);
      if(ctx->mesh.prisms) addCapsInArray(r, r->prisms);
      if(ctx->mesh.pyramids) addCapsInArray(r, r->pyramids);
      if(ctx->mesh.trihedra) addCapsInArray(r, r->trihedra);
      addCapsInArray(r, r->polyhedra);
      r->va_clip_triangles->finalize();
    }
    else {
      // whole element mode: the elements a plane cuts, drawn entire while
      // OpenGL clips the rest
      bool edg = ctx->mesh.volumeEdges, fac = ctx->mesh.volumeFaces;
      if(!edg && !fac) continue;
      r->va_clip_lines = new VertexArray(2, edg ? 6 * est : 100);
      r->va_clip_triangles = new VertexArray(3, fac ? 4 * est : 100);
      VertexArray *vl = r->va_clip_lines, *vt = r->va_clip_triangles;

      // what is drawn is the boundary of what is kept, so that a face between
      // two kept elements stays hidden and one facing the removed side does not
      UniqueElementFilter *bnd = nullptr;
      int nth = ctx->numThreads;
      if(!nth) nth = Msg::GetMaxThreads();
      if(fac && removeInteriorFaces()) {
        bnd = new UniqueElementFilter(nth > 1);
        if(ctx->mesh.tetrahedra) markKeptBoundaryFaces(r->tetrahedra, bnd, nth);
        if(ctx->mesh.hexahedra) markKeptBoundaryFaces(r->hexahedra, bnd, nth);
        if(ctx->mesh.prisms) markKeptBoundaryFaces(r->prisms, bnd, nth);
        if(ctx->mesh.pyramids) markKeptBoundaryFaces(r->pyramids, bnd, nth);
        if(ctx->mesh.trihedra) markKeptBoundaryFaces(r->trihedra, bnd, nth);
        markKeptBoundaryFaces(r->polyhedra, bnd, nth);
      }
      if(ctx->mesh.tetrahedra) {
        std::vector<MTetrahedron *> cut;
        gatherCutElements(r->tetrahedra, cut);
        addElementsInArrays(r, vl, vt, cut, edg, fac, bnd);
      }
      if(ctx->mesh.hexahedra) {
        std::vector<MHexahedron *> cut;
        gatherCutElements(r->hexahedra, cut);
        addElementsInArrays(r, vl, vt, cut, edg, fac, bnd);
      }
      if(ctx->mesh.prisms) {
        std::vector<MPrism *> cut;
        gatherCutElements(r->prisms, cut);
        addElementsInArrays(r, vl, vt, cut, edg, fac, bnd);
      }
      if(ctx->mesh.pyramids) {
        std::vector<MPyramid *> cut;
        gatherCutElements(r->pyramids, cut);
        addElementsInArrays(r, vl, vt, cut, edg, fac, bnd);
      }
      if(ctx->mesh.trihedra) {
        std::vector<MTrihedron *> cut;
        gatherCutElements(r->trihedra, cut);
        addElementsInArrays(r, vl, vt, cut, edg, fac, bnd);
      }
      std::vector<MPolyhedron *> cutp;
      gatherCutElements(r->polyhedra, cutp);
      addElementsInArrays(r, vl, vt, cutp, edg, fac, bnd);
      delete bnd;
      r->va_clip_lines->finalize();
      r->va_clip_triangles->finalize();
      n += r->va_clip_lines->getNumVertices();
    }
    if(r->va_clip_triangles) n += r->va_clip_triangles->getNumVertices();
  }

  // Curves and surfaces are cut by OpenGL like everything else, so whole
  // element mode has to give their cut elements back too - otherwise the skin
  // ends flat at the plane instead of following the elements. Not when only
  // the volume is meant to be clipped: they are then left alone entirely, and
  // drawn with the planes off.
  if(whole && !ctx->clipOnlyVolume) {
    if(ctx->mesh.lines) {
      for(auto it = firstEdge(); it != lastEdge(); it++) {
        GEdge *e = *it;
        if(!e->getVisibility() || e->lines.empty()) continue;
        fillCutEntity(e, true, false,
                      (int)(2. * pow((double)e->lines.size(), 2. / 3.)) + 100);
        n += e->va_clip_lines->getNumVertices();
      }
    }
    bool edg = ctx->mesh.surfaceEdges, fac = ctx->mesh.surfaceFaces;
    if(edg || fac) {
      for(auto it = firstFace(); it != lastFace(); it++) {
        GFace *f = *it;
        if(!f->getVisibility() || !f->getNumMeshElements()) continue;
        std::size_t ne = f->getNumMeshElements();
        fillCutEntity(f, edg, fac,
                      (int)(2. * pow((double)ne, 2. / 3.)) + 100);
        n += f->va_clip_lines->getNumVertices() +
             f->va_clip_triangles->getNumVertices();
      }
    }
  }

  if(n)
    Msg::Debug("What the clipping planes add: %lu vertices in %g s",
               (unsigned long)n, TimeOfDay() - t1);
  return true;
}

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

  Msg::Debug("Vertex arrays built in %g s", TimeOfDay() - tStart);
  VertexArray::printStats();
  return true;
}
