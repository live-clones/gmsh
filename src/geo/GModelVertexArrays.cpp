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

// Set when only the clipping planes moved: fillVertexArrays() then rebuilds
// only the entities that clipPlanesChanged() marked, instead of all of them.
static bool selectiveVertexArrayUpdate = false;

// Bounding boxes of the entities, which are only needed when the clipping
// planes move. bounds() is cheap for CAD entities but walks the mesh for
// discrete ones, so cache the result and only recompute it when the entity has
// been remeshed - which the number of elements detects well enough here.
static std::map<GEntity *, std::pair<std::size_t, SBoundingBox3d> > clipBounds;

static SBoundingBox3d &entityBounds(GEntity *e)
{
  std::size_t n = e->getNumMeshElements();
  auto it = clipBounds.find(e);
  if(it != clipBounds.end() && it->second.first == n) return it->second.second;
  clipBounds[e] = std::make_pair(n, e->bounds());
  return clipBounds[e].second;
}

// Where the entity sits with respect to the clipping planes: 1 if all of its
// elements are visible, 2 if they are all clipped away, 3 if a plane cuts
// through it. Only 3, or a change from one state to another, requires the
// vertex arrays to be rebuilt.
static char entityClipState(GEntity *e)
{
  // without clipWholeElements the planes are applied by OpenGL, and the arrays
  // only depend on them through the section they cut out of a 3D entity
  if(!CTX::instance()->clipWholeElements) {
    if(e->dim() < 3 || !CTX::instance()->meshClipCaps()) return 1;
  }
  int mask = CTX::instance()->mesh.clip;
  if(!mask) return 1;
  // in this mode only the elements that the plane cuts are drawn, so moving it
  // changes the arrays everywhere
  if(CTX::instance()->clipWholeElements &&
     CTX::instance()->clipOnlyDrawIntersectingVolume)
    return 3;
  if(!e->getNumMeshElements()) return 1;

  SBoundingBox3d &b = entityBounds(e);
  if(b.empty()) return 1;
  SPoint3 lo = b.min(), hi = b.max();
  bool cut = false;
  for(int c = 0; c < 6; c++) {
    if(!(mask & (1 << c))) continue;
    if(e->dim() < 3 && CTX::instance()->clipOnlyVolume) continue;
    double *p = CTX::instance()->clipPlane[c];
    // the extreme values of the plane equation over the box are reached at two
    // of its corners, picked componentwise by the sign of the coefficients
    double mn = p[3], mx = p[3];
    for(int k = 0; k < 3; k++) {
      double a = p[k], l = lo[k], h = hi[k];
      mn += (a > 0) ? a * l : a * h;
      mx += (a > 0) ? a * h : a * l;
    }
    if(mx < 0.) return 2; // entirely on the clipped side of this plane
    if(mn < 0.) cut = true;
  }
  return cut ? 3 : 1;
}

void GModel::clipPlanesChanged()
{
  int changed = 0;
  std::vector<GEntity *> ents;
  ents.insert(ents.end(), firstEdge(), lastEdge());
  ents.insert(ents.end(), firstFace(), lastFace());
  ents.insert(ents.end(), firstRegion(), lastRegion());

  for(auto e : ents) {
    char state = entityClipState(e);
    // an entity that a plane cuts always changes; one that is entirely on one
    // side only changes when it moved from one side to the other
    if(state == 3 || state != e->getVertexArraysClipState()) {
      e->setVertexArraysDirty(true);
      e->setVertexArraysClipState(state);
      changed |= (e->dim() == 1) ? ENT_CURVE :
                 (e->dim() == 2) ? ENT_SURFACE : ENT_VOLUME;
    }
  }

  if(Msg::GetVerbosity() >= 99) {
    int dirty = 0;
    for(auto e : ents)
      if(e->getVertexArraysDirty()) dirty++;
    Msg::Debug("Clipping planes moved: %d of %d entities to rebuild", dirty,
               (int)ents.size());
  }

  if(changed) {
    CTX::instance()->mesh.changed |= changed;
    selectiveVertexArrayUpdate = true;
  }
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

template <class T>
static void addElementsInArrays(GEntity *e, std::vector<T *> &elements,
                                bool edges, bool faces, bool caps,
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
      if(faces || caps) {
        vaTriangles[t] = new VertexArray(3, faces ? 4 * n : n / 4);
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
    (uniqueEdges && e->va_lines) ?
      e->va_lines->getUniqueFilter(nthreads > 1) : nullptr;
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

    if(caps && ele->getDim() == 3) addCapInArray(vaTriangle, ele, col);

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
    if(!e->getVertexArraysDirty()) return;
    e->setVertexArraysDirty(false);
    e->deleteVertexArrays();
    if(!e->getVisibility()) return;
    e->setOnlySomeElementsVisible(areOnlySomeElementsVisible(e->lines));

    if(CTX::instance()->mesh.lines) {
      e->va_lines = new VertexArray(2, _estimateNumLines(e));
      addElementsInArrays(e, e->lines, CTX::instance()->mesh.lines, false,
                          false);
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
    if(!f->getVertexArraysDirty()) return;
    f->setVertexArraysDirty(false);
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
        addElementsInArrays(f, f->triangles, edg, fac, false);
      if(CTX::instance()->mesh.quadrangles)
        addElementsInArrays(f, f->quadrangles, edg, fac, false);
      addElementsInArrays(f, f->polygons, edg, fac, false);
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
  int _estimateNumCaps(GRegion *r)
  {
    // the elements a plane cuts form a surface through the volume: there are
    // about as many of them as the 2/3 power of the number of elements
    std::size_t n = r->getNumMeshElements();
    return (int)(2. * pow((double)n, 2. / 3.)) + 100;
  }

  void operator()(GRegion *r)
  {
    if(!r->getVertexArraysDirty()) return;
    r->setVertexArraysDirty(false);
    r->deleteVertexArrays();
    if(!r->getVisibility()) return;
    r->setOnlySomeElementsVisible(areOnlySomeElementsVisible(r->tetrahedra) ||
                                  areOnlySomeElementsVisible(r->hexahedra) ||
                                  areOnlySomeElementsVisible(r->prisms) ||
                                  areOnlySomeElementsVisible(r->pyramids) ||
                                  areOnlySomeElementsVisible(r->trihedra));

    bool edg = CTX::instance()->mesh.volumeEdges;
    bool fac = CTX::instance()->mesh.volumeFaces;
    bool cap = CTX::instance()->meshClipCaps();
    if(edg || fac || cap) {
      _curved = (areSomeElementsCurved(r->tetrahedra) ||
                 areSomeElementsCurved(r->hexahedra) ||
                 areSomeElementsCurved(r->prisms) ||
                 areSomeElementsCurved(r->pyramids) ||
                 areSomeElementsCurved(r->trihedra));
      r->va_lines = new VertexArray(2, edg ? _estimateNumLines(r) : 100);
      r->va_triangles = new VertexArray(
        3, fac ? _estimateNumTriangles(r) : (cap ? _estimateNumCaps(r) : 100));

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
        addElementsInArrays(r, r->tetrahedra, edg, fac, cap, interior);
      if(CTX::instance()->mesh.hexahedra)
        addElementsInArrays(r, r->hexahedra, edg, fac, cap, interior);
      if(CTX::instance()->mesh.prisms)
        addElementsInArrays(r, r->prisms, edg, fac, cap, interior);
      if(CTX::instance()->mesh.pyramids)
        addElementsInArrays(r, r->pyramids, edg, fac, cap, interior);
      if(CTX::instance()->mesh.trihedra)
        addElementsInArrays(r, r->trihedra, edg, fac, cap, interior);
      addElementsInArrays(r, r->polyhedra, edg, fac, cap, interior);
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

  if(!selectiveVertexArrayUpdate) {
    // anything other than a clipping plane can change every entity
    for(auto it = firstEdge(); it != lastEdge(); it++)
      (*it)->setVertexArraysDirty(true);
    for(auto it = firstFace(); it != lastFace(); it++)
      (*it)->setVertexArraysDirty(true);
    for(auto it = firstRegion(); it != lastRegion(); it++)
      (*it)->setVertexArraysDirty(true);
  }
  selectiveVertexArrayUpdate = false;

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
