// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <cmath>
#include <map>
#include "GModelVertexArrays.h"
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
#include "ElementSpheres.h"
#include "FaceMatcher.h"
#include "VertexArray.h"
#include "OS.h"
#include "SmoothData.h"
#include "Iso.h"
#include <set>

// how many edges of an element are hashed and prefetched together before
// being looked up (more fall back on one at a time)
enum { MAX_BATCHED_EDGES = 32 };

static const double curvedRepTol = 1.e-5;

// The colour of a selected entity: the cursor merely resting on one is not
// the same as having chosen it, so what is hovered is drawn in the highlight
// colour instead (Geometry.Color.HighlightTwo, which nothing else uses).
unsigned int getSelectionColor(GEntity *e)
{
  return (e && e->getSelection() == GEntity::SelectHover) ?
           CTX::instance()->color.geom.highlight[2] :
           CTX::instance()->color.geom.selection;
}

// (what is merged across entities and kept takes the colour an entity has
// unselected: a selected one is drawn again on top, and the selection
// changes without anything being rebuilt)
unsigned int getColorByEntity(GEntity *e, bool withSelection)
{
  if(withSelection && e->getSelection()) { // selection
    return getSelectionColor(e);
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
      if(e && (e->dim() == ele->getDim())) return getColorByEntity(e, true);
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
  // nothing about the clipping planes here: OpenGL applies them, and what
  // they add is built into va_clip_*
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

// drop the faces interior to a 3D mesh (shared by two elements of the same
// entity) when only the skin is asked for; they are then not in the arrays
// at all, so they cannot be picked either
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

static int numFillThreads(std::size_t numElements)
{
  int nthreads = CTX::instance()->numThreads;
  if(!nthreads) nthreads = Msg::GetMaxThreads();
  if(numElements < 1000) nthreads = 1;
  return nthreads;
}

static bool isCurved(MElement *ele)
{
  return (ele->getPolynomialOrder() > 1) &&
         (ele->maxDistToStraight() > curvedRepTol * ele->getInnerRadius());
}

// The skin of a set of 3D elements: their faces that no other element of the
// set shares, in the order of the elements, and apart the elements whose
// faces cannot be told from what draws them, which are drawn whole.
struct meshSkin {
  std::vector<std::pair<MElement *, int> > faces;
  std::vector<MElement *> whole;
};

static void findSkin(const std::vector<MElement *> &elements, meshSkin &skin)
{
  skin.faces.clear();
  skin.whole.clear();
  std::size_t num = elements.size();
  if(num >= 0xffffffffu) { // (they are numbered on 32 bits below)
    skin.whole = elements;
    return;
  }
  int nthreads = numFillThreads(num);

  // (what decides it is not cheap for curved elements: once, not per thread)
  std::vector<std::uint8_t> mapped(num);
#pragma omp parallel for schedule(static) num_threads(nthreads)
  for(std::size_t i = 0; i < num; i++)
    mapped[i] = repPerFace(elements[i], isCurved(elements[i])) ? 1 : 0;
  for(std::size_t i = 0; i < num; i++)
    if(!mapped[i]) skin.whole.push_back(elements[i]);

  // each thread matches its share of the faces, in a table of its own
  typedef std::pair<std::size_t, int> face;
  std::vector<std::vector<face> > left(nthreads);
#pragma omp parallel for schedule(static, 1) num_threads(nthreads)
  for(int t = 0; t < nthreads; t++) {
    FaceMatcher<std::uintptr_t, std::uint32_t> matcher;
    for(std::size_t i = 0; i < num; i++) {
      if(!mapped[i]) continue;
      MElement *ele = elements[i];
      // (the faces of an element are hashed together, then added)
      int nf = ele->getNumFaces();
      std::uint64_t hash[8];
      for(int j0 = 0; j0 < nf; j0 += 8) {
        int n = std::min(nf - j0, 8);
        for(int j = 0; j < n; j++) {
          MVertex *fv[4];
          int nc = ele->getFaceCorners(j0 + j, fv);
          if(!nc) { // no corner accessor: fall back on the face
            MFace fa = ele->getFace(j0 + j);
            nc = std::min((int)fa.getNumVertices(), 4);
            for(int k = 0; k < nc; k++) fv[k] = fa.getVertex(k);
          }
          hash[j] = 0;
          if(nc < 3) continue;
          std::uintptr_t k[4] = {(std::uintptr_t)fv[0], (std::uintptr_t)fv[1],
                                 (std::uintptr_t)fv[2],
                                 nc > 3 ? (std::uintptr_t)fv[3] : 0};
          if(matcher.share(k, nc, nthreads) == t)
            hash[j] = matcher.hashOf(k, nc, 0);
        }
        for(int j = 0; j < n; j++)
          if(hash[j]) matcher.add(hash[j], (std::uint32_t)i, j0 + j);
      }
    }
    matcher.forEachLeft(
      [&](std::uint32_t i, int j) { left[t].push_back(face(i, j)); });
  }

  std::vector<face> all;
  for(auto &l : left) all.insert(all.end(), l.begin(), l.end());
  std::sort(all.begin(), all.end());
  skin.faces.reserve(all.size());
  for(auto &f : all)
    skin.faces.push_back(std::make_pair(elements[f.first], f.second));
}

// add the section a clipping plane cuts out of an element, moved slightly
// towards the kept side so that the plane does not clip it away (the other
// planes still do)
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

// does a plane cut through this element? Those are the elements whole
// element mode draws whole, and the only ones whose faces can lie between
// what is kept and what is removed.
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

// is this element kept by whole element mode? Only those entirely beyond a
// plane are dropped.
bool elementIsKept(MElement *ele)
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

// the elements a plane cuts, to be drawn whole while OpenGL clips the rest
template <class T>
static void gatherCutElements(std::vector<T *> &elements,
                              std::vector<T *> &cut)
{
  for(std::size_t i = 0; i < elements.size(); i++) {
    if(!isElementVisible(elements[i])) continue;
    // an element cut by one plane can be entirely beyond another
    if(!elementIsKept(elements[i])) continue;
    if(!elementIsCut(elements[i])) continue;
    cut.push_back(elements[i]);
  }
}

// vaL and vaT are where the lines and triangles go: the entity's own arrays,
// or the ones holding what the clipping planes add
template <class T>
static void addElementsInArrays(GEntity *e, VertexArray *vaL, VertexArray *vaT,
                                std::vector<T *> &elements, bool edges,
                                bool faces)
{
  int nthreads = numFillThreads(elements.size());

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
    // the threads share the entity's filter, which also survives across the
    // calls made for each element type
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
  // the filter is only worth it on edges, and finds nothing when the elements
  // are exploded
  const bool filtering =
    CTX::instance()->mesh.drawUniqueEdges && (explode == 1.) && !pick;
  const bool uniqueEdges = (e->dim() > 1 && filtering);

  // with a topology, identify a duplicated edge by its two vertices rather
  // than by coordinates: cheaper, exact, and getEdgeRep() can be skipped
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

    const bool curved = isCurved(ele);

    SPoint3 pc(0., 0., 0.);
    if(explode != 1.) pc = ele->barycenter();

    if(edges) {
      int numRep = ele->getNumEdgesRep(curved);
      // the representation of a curved edge is subdivided, and does not map one
      // to one onto the topological edges: fall back on the coordinates
      bool topo = (filter && numRep == ele->getNumEdges() &&
                   numRep <= MAX_BATCHED_EDGES);
      bool unique = uniqueEdges && !topo;
      // hash the edges and prefetch their table entries before looking up,
      // so that the cache misses overlap
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
      for(int j = 0; j < numRep; j++) {
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

// the faces of a skin, each drawn by what represents it in its element
static void addSkinInArray(VertexArray *va, const meshSkin &skin)
{
  const double explode = CTX::instance()->mesh.explode;
  MElement *last = nullptr;
  bool curved = false;
  int perFace = 0;
  unsigned int col[4];
  SPoint3 pc(0., 0., 0.);
  for(auto &f : skin.faces) {
    MElement *ele = f.first;
    if(ele != last) {
      last = ele;
      curved = isCurved(ele);
      perFace = repPerFace(ele, curved);
      col[0] = col[1] = col[2] = col[3] = getColorByElement(ele);
      if(explode != 1.) pc = ele->barycenter();
    }
    for(int j = f.second * perFace; j < (f.second + 1) * perFace; j++) {
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
      va->add(x, y, z, n, col, ele, false);
    }
  }
}

// What is kept for a volume from one filling of its arrays to the next, as
// long as its mesh stays (CTX::meshChanged(), not the options that change the
// way it is drawn) along with the options choosing the elements: its skin,
// and the spheres around its elements, built when the planes first need them.
static std::vector<double> regionKey(GRegion *r)
{
  CTX *ctx = CTX::instance();
  std::vector<double> k = {
    (double)ctx->meshContentStamp,  (double)ctx->entityVisibilityStamp,
    (double)ctx->mesh.tetrahedra,   (double)ctx->mesh.hexahedra,
    (double)ctx->mesh.prisms,       (double)ctx->mesh.pyramids,
    (double)ctx->mesh.trihedra,     (double)ctx->mesh.polyhedra,
    ctx->mesh.qualitySup,           ctx->mesh.qualityInf,
    (double)ctx->mesh.qualityType,  ctx->mesh.radiusSup,
    ctx->mesh.radiusInf,            (double)r->getNumMeshElements()};
  return k;
}

struct keptSkin {
  std::vector<double> key;
  meshSkin skin;
};
static OwnerCache<keptSkin> _regionSkin;

struct keptSpheres {
  std::vector<double> key;
  elementSpheres spheres;
};
static OwnerCache<keptSpheres> _regionSpheres;

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

// The element lists of a surface or a volume, each passed to f when its own
// option shows it, always in the same order: what goes into an array in
// which order decides what is drawn over what, and what a pick returns.
template <class F> static void forShownFaceElements(GFace *f, F fun)
{
  CTX *c = CTX::instance();
  if(c->mesh.triangles) fun(f->triangles);
  if(c->mesh.quadrangles) fun(f->quadrangles);
  if(c->mesh.polygons) fun(f->polygons);
}

template <class F> static void forShownRegionElements(GRegion *r, F fun)
{
  CTX *c = CTX::instance();
  if(c->mesh.tetrahedra) fun(r->tetrahedra);
  if(c->mesh.hexahedra) fun(r->hexahedra);
  if(c->mesh.prisms) fun(r->prisms);
  if(c->mesh.pyramids) fun(r->pyramids);
  if(c->mesh.trihedra) fun(r->trihedra);
  if(c->mesh.polyhedra) fun(r->polyhedra);
}

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
                                  areOnlySomeElementsVisible(f->quadrangles) ||
                                  areOnlySomeElementsVisible(f->polygons));

    bool edg = CTX::instance()->mesh.surfaceEdges;
    bool fac = CTX::instance()->mesh.surfaceFaces;
    if(edg || fac) {
      _curved = (areSomeElementsCurved(f->triangles) ||
                 areSomeElementsCurved(f->quadrangles));
      f->va_lines = new VertexArray(2, edg ? _estimateNumLines(f) : 100);
      f->va_triangles =
        new VertexArray(3, fac ? _estimateNumTriangles(f) : 100);
      forShownFaceElements(f, [&](auto &els) {
        addElementsInArrays(f, f->va_lines, f->va_triangles, els, edg, fac);
      });
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
    // the cut elements form a surface: about the 2/3 power of the elements
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
                                  areOnlySomeElementsVisible(r->trihedra) ||
                                  areOnlySomeElementsVisible(r->polyhedra));

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

      if(fac && removeInteriorFaces()) {
        // the skin, found from all the element types before any is drawn
        keptSkin &kept = _regionSkin[r];
        std::vector<double> key = regionKey(r);
        if(kept.key != key) {
          double t1 = TimeOfDay();
          std::vector<MElement *> shown;
          forShownRegionElements(r, [&](auto &els) {
            for(auto e : els)
              if(isElementVisible(e) && e->getDim() == 3) shown.push_back(e);
          });
          findSkin(shown, kept.skin);
          kept.key = key;
          Msg::Debug("Found the skin of volume %d in %g s", r->tag(),
                     TimeOfDay() - t1);
        }
        if(edg)
          forShownRegionElements(r, [&](auto &els) {
            addElementsInArrays(r, r->va_lines, r->va_triangles, els, true,
                                false);
          });
        addSkinInArray(r->va_triangles, kept.skin);
        addElementsInArrays(r, r->va_lines, r->va_triangles, kept.skin.whole,
                            false, true);
      }
      else
        forShownRegionElements(r, [&](auto &els) {
          addElementsInArrays(r, r->va_lines, r->va_triangles, els, edg, fac);
        });
      r->va_lines->finalize();
      r->va_triangles->finalize();
    }
  }
};

// what each model's clip arrays were last built for: only what changes them
// without marking the mesh as changed (the planes and the clipping options);
// everything else changes the mesh (CTX::meshChanged()), and drawMesh()
// then invalidates them
static OwnerCache<std::vector<double> > _clipToken;

static std::vector<double> clipToken()
{
  CTX *ctx = CTX::instance();
  std::vector<double> t;
  t.push_back(ctx->mesh.clip);
  ctx->addClipToKey(t);
  return t;
}

void GModel::invalidateClipVertexArrays() { _clipToken.erase(this); }

// The elements of one entity that a plane cuts, drawn whole into its clip
// arrays
template <class T>
static void addCutElements(GEntity *e, std::vector<T *> &elements, bool edges,
                           bool faces)
{
  std::vector<T *> cut;
  gatherCutElements(elements, cut);
  if(cut.empty()) return;
  addElementsInArrays(e, e->va_clip_lines, e->va_clip_triangles, cut, edges,
                      faces);
}

// The spheres around the elements of a volume, numbered as
// forShownRegionElements() goes through them (none around the elements that
// are not drawn), if there are enough of them to be worth their memory
static const elementSpheres *getSpheres(GRegion *r)
{
  std::size_t num = 0;
  forShownRegionElements(r, [&](auto &els) { num += els.size(); });
  if(num < 50000) return nullptr;
  keptSpheres &kept = _regionSpheres[r];
  std::vector<double> key = regionKey(r);
  if(kept.key == key && kept.spheres.size() == num) return &kept.spheres;
  double t1 = TimeOfDay();
  kept.key = key;
  kept.spheres.assign(num);
  std::size_t first = 0;
  forShownRegionElements(r, [&](auto &els) {
    int nthreads = numFillThreads(els.size());
#pragma omp parallel for schedule(static) num_threads(nthreads)
    for(std::size_t i = 0; i < els.size(); i++) {
      MElement *ele = els[i];
      if(ele->getDim() != 3 || !isElementVisible(ele)) continue;
      kept.spheres.set(first + i, 3, (int)ele->getNumVertices(),
                       [&](int j, int k) {
                         MVertex *v = ele->getVertex(j);
                         return k == 0 ? v->x() : k == 1 ? v->y() : v->z();
                       });
    }
    first += els.size();
  });
  Msg::Debug("Bounded the elements of volume %d in %g s (%g MB)", r->tag(),
             TimeOfDay() - t1, kept.spheres.getMemoryInMB());
  return &kept.spheres;
}

// the elements of a volume that are drawn and within a distance of a plane
static void gatherCloseElements(GRegion *r, const elementSpheres *spheres,
                                const activePlanes &planes, double distance,
                                std::vector<MElement *> &close,
                                double *maxRadius = nullptr)
{
  std::size_t first = 0;
  forShownRegionElements(r, [&](auto &els) {
    for(std::size_t i = 0; i < els.size(); i++) {
      if(spheres) {
        if(!spheres->drawn(first + i) ||
           planes.gap(spheres->sphere(first + i)) > distance)
          continue;
        if(maxRadius)
          *maxRadius = std::max(*maxRadius, spheres->radius(first + i));
      }
      else if(els[i]->getDim() != 3 || !isElementVisible(els[i]))
        continue;
      close.push_back(els[i]);
    }
    first += els.size();
  });
}

// What the planes add to a volume: the section they cut, or the elements
// they cut drawn whole. Only the elements close enough to a plane are looked
// at, when there are spheres to tell.
static void fillCutRegion(GRegion *r, bool caps, int est)
{
  CTX *ctx = CTX::instance();
  const elementSpheres *spheres = getSpheres(r);
  activePlanes planes(ctx->mesh.clip);

  // the elements a plane may cut
  std::vector<MElement *> close;
  double maxRadius = 0.;
  gatherCloseElements(r, spheres, planes, 0., close, &maxRadius);

  if(caps) {
    r->va_clip_triangles = new VertexArray(3, est);
    for(auto ele : close) {
      unsigned int c = getColorByElement(ele);
      unsigned int col[4] = {c, c, c, c};
      addCapInArray(r->va_clip_triangles, ele, col);
    }
    r->va_clip_triangles->finalize();
    return;
  }

  // whole element mode: the cut elements, drawn whole
  bool edg = ctx->mesh.volumeEdges, fac = ctx->mesh.volumeFaces;
  if(!edg && !fac) return;
  r->va_clip_lines = new VertexArray(2, edg ? 6 * est : 100);
  r->va_clip_triangles = new VertexArray(3, fac ? 4 * est : 100);
  std::vector<MElement *> cut;
  gatherCutElements(close, cut);
  if(fac && removeInteriorFaces()) {
    // only the boundary of what is kept is drawn (a face between two kept
    // elements is interior, one facing a removed element is not): the faces
    // of the cut elements in the skin of the kept elements around them
    // (one that touches a cut element is within twice its radius of a plane)
    std::vector<MElement *> near, around;
    gatherCloseElements(r, spheres, planes, 2. * maxRadius, near);
    for(auto e : near)
      if(elementIsKept(e)) around.push_back(e);
    meshSkin skin, ofCut;
    findSkin(around, skin);
    std::set<MElement *> isCut(cut.begin(), cut.end());
    for(auto &f : skin.faces)
      if(isCut.count(f.first)) ofCut.faces.push_back(f);
    for(auto e : skin.whole)
      if(isCut.count(e)) ofCut.whole.push_back(e);
    if(edg)
      addElementsInArrays(r, r->va_clip_lines, r->va_clip_triangles, cut, true,
                          false);
    addSkinInArray(r->va_clip_triangles, ofCut);
    addElementsInArrays(r, r->va_clip_lines, r->va_clip_triangles, ofCut.whole,
                        false, true);
  }
  else
    addElementsInArrays(r, r->va_clip_lines, r->va_clip_triangles, cut, edg,
                        fac);
  r->va_clip_lines->finalize();
  r->va_clip_triangles->finalize();
}

// What the planes cut out of a curve or a surface. There is no interior to
// hide here, so the elements go in as they are.
static void fillCutEntity(GEntity *e, bool edges, bool faces, int est)
{
  e->va_clip_lines = new VertexArray(2, edges ? 6 * est : 100);
  e->va_clip_triangles = new VertexArray(3, faces ? 4 * est : 100);
  if(e->dim() == 1) {
    addCutElements(e, ((GEdge *)e)->lines, edges, false);
  }
  else if(e->dim() == 2) {
    GFace *f = (GFace *)e;
    forShownFaceElements(
      f, [&](auto &els) { addCutElements(e, els, edges, faces); });
  }
  e->va_clip_lines->finalize();
  e->va_clip_triangles->finalize();
}

bool GModel::fillClipVertexArrays()
{
  std::vector<double> tok = clipToken();
  std::vector<double> *found = _clipToken.find(this);
  if(found && *found == tok) return false;
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
    // the cut elements form a surface: about the 2/3 power of the elements
    std::size_t ne = r->getNumMeshElements();
    int est = (int)(2. * pow((double)ne, 2. / 3.)) + 100;

    fillCutRegion(r, caps, est);
    if(r->va_clip_lines) n += r->va_clip_lines->getNumVertices();
    if(r->va_clip_triangles) n += r->va_clip_triangles->getNumVertices();
  }

  // curves and surfaces get their cut elements back too, unless only the
  // volume is clipped (they are then drawn whole with the planes off)
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
  // the dimensions whose mesh changed since the arrays were filled; a model
  // hidden meanwhile is brought up to date when it is shown again
  CTX *ctx = CTX::instance();
  if(!getVisibility()) return false;
  // hidden entities get no arrays: showing one again (the API does not flag
  // the mesh as the visibility window does) needs them filled
  bool visibility = (ctx->entityVisibilityStamp != visibilityStampBuilt);
  visibilityStampBuilt = ctx->entityVisibilityStamp;
  bool changed[4];
  bool any = false;
  for(int d = 0; d < 4; d++) {
    changed[d] = visibility || (ctx->mesh.stamp[d] != meshStampBuilt[d]);
    if(changed[d]) any = true;
    meshStampBuilt[d] = ctx->mesh.stamp[d];
  }
  if(!any) return false;

  Msg::Debug("Mesh has changed: reinitializing vertex arrays");

  double tStart = TimeOfDay();
  int status = getMeshStatus();

  if(status >= 1 && changed[1])
    std::for_each(firstEdge(), lastEdge(), initMeshGEdge());

  if(status >= 2 && changed[2]) {
    if(normals) delete normals;
    normals = new smooth_normals(CTX::instance()->mesh.angleSmoothNormals);
    if(CTX::instance()->mesh.smoothNormals)
      std::for_each(firstFace(), lastFace(), initSmoothNormalsGFace());
    std::for_each(firstFace(), lastFace(), initMeshGFace());
  }

  if(status >= 3 && changed[3])
    std::for_each(firstRegion(), lastRegion(), initMeshGRegion());

  Msg::Debug("Vertex arrays built in %g s", TimeOfDay() - tStart);
  VertexArray::printStats();
  return true;
}
