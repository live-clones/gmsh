// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <string.h>
#include <algorithm>
#include <atomic>
#include <cmath>
#include <cstdint>
#include <list>
#include <vector>
#include "GmshMessage.h"
#include "GmshDefines.h"
#include "MElement.h"
#include "MPolygon.h"
#include "MPolyhedron.h"
#include "onelab.h"
#include "Iso.h"
#include "MEdge.h"
#include "MFace.h"
#include "PView.h"
#include "PViewOptions.h"
#include "PViewData.h"
#include "PViewDataRemote.h"
#include "Numeric.h"
#include "VertexArray.h"
#include "SmoothData.h"
#include "Context.h"
#include "OwnerCache.h"
#include "ElementSpheres.h"
#include "FaceMatcher.h"
#include "OS.h"
#include "OpenFile.h"
#include "mathEvaluator.h"
#include "Options.h"
#include "StringUtils.h"
#include "fullMatrix.h"

static void saturate(int nb, double **val, double vmin, double vmax, int i0 = 0,
                     int i1 = 1, int i2 = 2, int i3 = 3, int i4 = 4, int i5 = 5,
                     int i6 = 6, int i7 = 7)
{
  int id[8] = {i0, i1, i2, i3, i4, i5, i6, i7};
  for(int i = 0; i < nb; i++) {
    if(val[id[i]][0] > vmax)
      val[id[i]][0] = vmax;
    else if(val[id[i]][0] < vmin)
      val[id[i]][0] = vmin;
  }
}

static double saturateVector(double *val, int numComp2, double *val2,
                             double min, double max)
{
  double v = ComputeScalarRep(numComp2, val2); // v >= 0
  if(v < min && v > 1e-15) {
    double f = min / v;
    for(int iComp = 0; iComp < numComp2; ++iComp) val2[iComp] *= f;
    val[0] *= f;
    val[1] *= f;
    val[2] *= f;
    return min;
  }
  if(v > max && v > 1e-15) {
    double f = max / v;
    for(int iComp = 0; iComp < numComp2; ++iComp) val2[iComp] *= f;
    val[0] *= f;
    val[1] *= f;
    val[2] *= f;
    return max;
  }
  return v;
}

static SVector3 normal3(double **xyz, int i0 = 0, int i1 = 1, int i2 = 2)
{
  SVector3 t1(xyz[i1][0] - xyz[i0][0], xyz[i1][1] - xyz[i0][1],
              xyz[i1][2] - xyz[i0][2]);
  SVector3 t2(xyz[i2][0] - xyz[i0][0], xyz[i2][1] - xyz[i0][1],
              xyz[i2][2] - xyz[i0][2]);
  SVector3 n = crossprod(t1, t2);
  n.normalize();
  return n;
}

// n rows of doubles, as the double ** the drawing routines take for the
// coordinates or the values at the nodes of an element; the memory is kept
// from one element to the next
class nodeRows {
private:
  std::vector<double> _data;
  std::vector<double *> _rows;

public:
  double **get(int n, int width)
  {
    if(_data.size() < (std::size_t)(n * width)) _data.resize(n * width);
    _rows.resize(n);
    for(int i = 0; i < n; i++) _rows[i] = &_data[i * width];
    return _rows.data();
  }
};

// what the drawing functions read the options from and write the primitives
// to; each thread gets its own, with its own copy of the options (which the
// functions modify) and its own arrays, merged in thread order afterwards
class drawTarget {
public:
  PView *view;
  PViewOptions *opt;
  VertexArray *va_points, *va_lines, *va_triangles, *va_vectors, *va_ellipses;
  smooth_normals *normals;
  // identifiers of the nodes of the element being drawn, or null when the data
  // has no topology and none could be recreated
  std::size_t *nodeIds;
  // the entity it belongs to
  int ent;
  // what is gathered: everything, or only what the clipping planes add (the
  // section they cut, or the cut elements drawn whole)
  enum { COLLECT_ALL, COLLECT_CAPS, COLLECT_CUT, COLLECT_KEPT };
  int collect;
  // the faces of the element being drawn that are on the skin, a bit each in
  // the order of its shape, when the skin was found ahead (-1 otherwise)
  int skinMask;
  const struct solidShape *skinShape;
  // bounding box of the elements that were drawn
  SBoundingBox3d bbox;
  drawTarget(PView *p)
    : view(p), opt(p->getOptions()), va_points(p->va_points),
      va_lines(p->va_lines), va_triangles(p->va_triangles),
      va_vectors(p->va_vectors), va_ellipses(p->va_ellipses),
      normals(p->normals), nodeIds(nullptr), ent(0), collect(COLLECT_ALL),
      skinMask(-1), skinShape(nullptr)
  {
  }
};

static SVector3 getPointNormal(drawTarget *p, double v)
{
  PViewOptions *opt = p->opt;
  SVector3 n(0., 0., 0.);
  if(opt->pointType > 0) {
    // when we draw spheres, we use the normalized value (between 0
    // and 1) stored in the first component of the normal to modulate
    // the radius
    double d = opt->tmpMax - opt->tmpMin;
    n[0] = (v - opt->tmpMin) / (d ? d : 1.);
  }
  return n;
}

static void getLineNormal(drawTarget *p, double x[2], double y[2], double z[2],
                          double *v, SVector3 n[2], bool computeNormal)
{
  PViewOptions *opt = p->opt;

  if(opt->lineType > 0) {
    if(v) {
      // when we draw tapered cylinders, we use the normalized values
      // (between 0 and 1) stored in the first component of the
      // normals to modulate the width
      double d = opt->tmpMax - opt->tmpMin;
      n[0][0] = (v[0] - opt->tmpMin) / (d ? d : 1.);
      n[1][0] = (v[1] - opt->tmpMin) / (d ? d : 1.);
    }
    else {
      // when we don't have values we use maximum width cylinders
      n[0][0] = n[1][0] = 1.;
    }
  }
  else if(computeNormal) {
    SBoundingBox3d bb = p->view->getData()->getBoundingBox();
    if(bb.min().z() == bb.max().z())
      n[0] = n[1] = SVector3(0., 0., 1.);
    else if(bb.min().y() == bb.max().y())
      n[0] = n[1] = SVector3(0., 1., 0.);
    else if(bb.min().x() == bb.max().x())
      n[0] = n[1] = SVector3(1., 0., 0.);
    else {
      // we don't have any info about the normal, just pick one
      SVector3 t(x[1] - x[0], y[1] - y[0], z[1] - z[0]);
      SVector3 ex(0., 0., 0.);
      if(t[0] == 0.)
        ex[0] = 1.;
      else if(t[1] == 0.)
        ex[1] = 1.;
      else
        ex[2] = 1.;
      n[0] = crossprod(t, ex);
      n[0].normalize();
      n[1] = n[0];
    }
  }
}

static bool getExternalValues(drawTarget *p, int index, int ient, int iele,
                              int numNodes, int numComp, double **val,
                              int &numComp2, double **val2)
{
  PViewOptions *opt = p->opt;

  // use self by default
  numComp2 = numComp;
  for(int i = 0; i < numNodes; i++)
    for(int j = 0; j < numComp; j++) val2[i][j] = val[i][j];
  opt->externalMin = opt->tmpMin;
  opt->externalMax = opt->tmpMax;

  if(index < 0 || index >= (int)PView::list.size()) return false;

  PView *p2 = PView::list[index];
  PViewData *data2 = p2->getData(true); // use adaptive data if available

  if(iele >= data2->getNumElements(opt->timeStep, ient)) return false;

  if(!data2->skipElement(opt->timeStep, ient, iele) &&
     data2->getNumNodes(opt->timeStep, ient, iele) == numNodes) {
    numComp2 = data2->getNumComponents(opt->timeStep, ient, iele);
    for(int i = 0; i < numNodes; i++)
      for(int j = 0; j < numComp2; j++)
        data2->getValue(opt->timeStep, ient, iele, i, j, val2[i][j]);
    opt->getRange(data2, opt->externalMin, opt->externalMax);
    return true;
  }
  return false;
}

static void applyGeneralRaise(drawTarget *p, int numNodes, int numComp,
                              double **vals, double **xyz)
{
  PViewOptions *opt = p->opt;
  if(!opt->genRaiseEvaluator) return;

  std::vector<double> values(14, 0.), res(3);
  for(int k = 0; k < numNodes; k++) {
    for(int i = 0; i < 3; i++) values[i] = xyz[k][i];
    for(int i = 0; i < std::min(numComp, 9); i++) values[3 + i] = vals[k][i];
    values[12] = p->opt->timeStep;
    values[13] = p->opt->currentTime;
    if(opt->genRaiseEvaluator->eval(values, res))
      for(int i = 0; i < 3; i++) xyz[k][i] += opt->genRaiseFactor * res[i];
  }
}

static void changeCoordinates(drawTarget *p, int ient, int iele, int numNodes,
                              int type, int numComp, double **xyz, double **val)
{
  PViewOptions *opt = p->opt;

  if(opt->explode != 1.) {
    double barycenter[3] = {0., 0., 0.};
    for(int i = 0; i < numNodes; i++)
      for(int j = 0; j < 3; j++) barycenter[j] += xyz[i][j];
    for(int j = 0; j < 3; j++) barycenter[j] /= (double)numNodes;
    for(int i = 0; i < numNodes; i++)
      for(int j = 0; j < 3; j++)
        xyz[i][j] = barycenter[j] + opt->explode * (xyz[i][j] - barycenter[j]);
  }

  if(opt->transform[0][0] != 1. || opt->transform[0][1] != 0. ||
     opt->transform[0][2] != 0. || opt->transform[1][0] != 0. ||
     opt->transform[1][1] != 1. || opt->transform[1][2] != 0. ||
     opt->transform[2][0] != 0. || opt->transform[2][1] != 0. ||
     opt->transform[2][2] != 1.) {
    for(int i = 0; i < numNodes; i++) {
      double old[3] = {xyz[i][0], xyz[i][1], xyz[i][2]};
      for(int j = 0; j < 3; j++) {
        xyz[i][j] = 0.;
        for(int k = 0; k < 3; k++) xyz[i][j] += opt->transform[j][k] * old[k];
      }
    }
  }

  if(opt->offset[0] || opt->offset[1] || opt->offset[2]) {
    for(int i = 0; i < numNodes; i++)
      for(int j = 0; j < 3; j++) xyz[i][j] += opt->offset[j];
  }

  if(opt->raise[0] || opt->raise[1] || opt->raise[2]) {
    for(int i = 0; i < numNodes; i++) {
      double v = ComputeScalarRep(numComp, val[i]);
      for(int j = 0; j < 3; j++) xyz[i][j] += opt->raise[j] * v;
    }
  }

  if(opt->normalRaise &&
     (type == TYPE_LIN || type == TYPE_TRI || type == TYPE_QUA)) {
    SVector3 n;
    if(type == TYPE_LIN) {
      // assumes lines in z=const plane, and raises in that plane
      double x[2] = {xyz[0][0], xyz[1][0]};
      double y[2] = {xyz[0][1], xyz[1][1]};
      double z[2] = {xyz[0][2], xyz[1][2]};
      SVector3 p(0, 0, 1.);
      SVector3 t(x[1] - x[0], y[1] - y[0], z[1] - z[0]);
      n = crossprod(t, p);
      n.normalize();
    }
    else
      n = normal3(xyz);
    for(int i = 0; i < numNodes; i++) {
      double v = ComputeScalarRep(numComp, val[i]);
      for(int j = 0; j < 3; j++) xyz[i][j] += n[j] * opt->normalRaise * v;
    }
  }

  if(numComp == 3 && opt->vectorType == PViewOptions::Displacement) {
    for(int i = 0; i < numNodes; i++) {
      for(int j = 0; j < 3; j++)
        xyz[i][j] += opt->displacementFactor * val[i][j];
    }
  }

  if(opt->useGenRaise) {
    int numComp2;
    static thread_local nodeRows rows;
    double **val2 = rows.get(numNodes, 9);
    getExternalValues(p, opt->viewIndexForGenRaise, ient, iele, numNodes,
                      numComp, val, numComp2, val2);
    applyGeneralRaise(p, numNodes, numComp2, val2, xyz);
  }
}

static double evalClipPlane(int clip, double x, double y, double z)
{
  return CTX::instance()->clipPlane[clip][0] * x +
         CTX::instance()->clipPlane[clip][1] * y +
         CTX::instance()->clipPlane[clip][2] * z +
         CTX::instance()->clipPlane[clip][3];
}

static double intersectClipPlane(int clip, int numNodes, double **xyz)
{
  double val = evalClipPlane(clip, xyz[0][0], xyz[0][1], xyz[0][2]);
  for(int i = 1; i < numNodes; i++) {
    if(val * evalClipPlane(clip, xyz[i][0], xyz[i][1], xyz[i][2]) <= 0)
      return 0.; // the element intersects the cut plane
  }
  return val;
}

// is this element kept by whole element mode? Only those entirely beyond a
// plane are dropped. Used for the glyphs drawn straight from the elements.
bool elementIsKept(PViewOptions *opt, int dim, int numNodes, double **xyz)
{
  CTX *ctx = CTX::instance();
  if(!ctx->clipWholeElements) return true;
  for(int clip = 0; clip < 6; clip++) {
    if(!(opt->clip & (1 << clip))) continue;
    // only the volume is clipped
    if(dim < 3 && ctx->clipOnlyVolume) continue;
    double d = intersectClipPlane(clip, numNodes, xyz);
    // only the cut volumes are drawn
    if(dim == 3 && ctx->clipOnlyDrawIntersectingVolume && d) return false;
    if(d < 0.) return false;
  }
  return true;
}

// does this element go in the array of whole element mode? The cut ones do,
// and everything the planes are not applied to (OpenGL would slice both).
static bool elementIsCut(PViewOptions *opt, int dim, int numNodes, double **xyz)
{
  CTX *ctx = CTX::instance();
  if(!elementIsKept(opt, dim, numNodes, xyz)) return false;
  if(dim < 3 && ctx->clipOnlyVolume) return true;
  for(int clip = 0; clip < 6; clip++) {
    if(!(opt->clip & (1 << clip))) continue;
    if(!intersectClipPlane(clip, numNodes, xyz)) return true;
  }
  return false;
}

// does this element go in the view's own arrays? OpenGL clips those, so
// nothing depends on the planes here, except in the mode drawing only the
// cut volumes, whose arrays are filled through the planes (see
// checkClipPlanesChanged()).
static bool isElementVisible(PViewOptions *opt, int dim, int numNodes,
                             double **xyz)
{
  CTX *ctx = CTX::instance();
  if(!ctx->clipWholeElements || !opt->clip) return true;
  if(ctx->clipOnlyDrawIntersectingVolume)
    return elementIsKept(opt, dim, numNodes, xyz);
  return true;
}

static void addOutlinePoint(drawTarget *p, double **xyz, unsigned int color,
                            bool pre, int i0 = 0)
{
  if(pre) return;
  SVector3 n = getPointNormal(p, 1.);
  p->va_points->add(&xyz[i0][0], &xyz[i0][1], &xyz[i0][2], &n, &color, nullptr,
                    true);
}

// the boundary faces of the 3D elements when View.DrawSkinOnly is set, found
// by inserting every face and cancelling it when seen a second time
static UniqueElementFilter *boundaryFaces = nullptr;
static bool markingBoundaryFaces = false;
static std::atomic<int> noNodeIdWarning(0);

// The key of a face of n nodes, from their sorted identifiers and the entity
// (so that the skin is taken entity by entity); false if the data has no
// topology. A quadrangle and a triangle never collide: the keys differ in
// length.
static bool faceKey(const std::size_t *nodeIds, int ent, const int *idx, int n,
                    std::uint64_t *k)
{
  if(!nodeIds) return false;
  for(int i = 0; i < n; i++) {
    if(!nodeIds[idx[i]]) return false;
    k[i] = nodeIds[idx[i]];
  }
  for(int i = 1; i < n; i++)
    for(int j = i; j > 0 && k[j] < k[j - 1]; j--) std::swap(k[j], k[j - 1]);
  k[n] = (std::uint64_t)ent;
  return true;
}

// Is this face of a 3D element on the skin of the field? In the pass that
// marks them it is inserted, and cancelled when the element on the other
// side inserts it too. The faces of the element itself are used, not those
// of the tetrahedra a hexahedron, a prism or a pyramid is split into: the
// diagonal that splits a shared quadrangle into two triangles need not be
// the one the neighbour chose, and the halves then cancel nothing and both
// sides of every such face are drawn.
static bool maskedSkinFace(drawTarget *p, const int *idx, int n);

static bool skinFace(drawTarget *p, const int *idx, int n)
{
  // the skin was found ahead (see findSkin())
  if(p->skinMask >= 0) return maskedSkinFace(p, idx, n);
  if(!boundaryFaces && !markingBoundaryFaces) return true;
  // no topology to use (see addElementRange()): all the faces are drawn
  if(!p->nodeIds) return !markingBoundaryFaces;
  std::uint64_t k[5];
  if(!faceKey(p->nodeIds, p->ent, idx, n, k)) {
    if(markingBoundaryFaces) return false;
    if(!noNodeIdWarning++)
      Msg::Warning("DrawSkinOnly needs node identifiers, which this data does "
                   "not have: drawing all the faces");
    return true; // nothing to tell the faces apart: draw them all
  }
  if(markingBoundaryFaces) {
    boundaryFaces->insertOrErase(k, n + 1);
    return false;
  }
  return boundaryFaces->contains(k, n + 1);
}

// are only the outlines of the faces on the skin drawn?
static bool skinOutlines(PViewOptions *opt)
{
  return opt->showElement && opt->drawSkinEdgesOnly;
}

// does this element draw its own faces, and only the ones on the skin?
static bool skinOnly(PViewOptions *opt)
{
  return opt->drawSkinOnly && opt->boundary <= 0 &&
         (opt->intervalsType == PViewOptions::Continuous ||
          opt->intervalsType == PViewOptions::Discrete);
}

// skip an element already added, identified by its nodes rather than by
// coordinates; clears `unique' when the check was done here
static bool topoDuplicate(VertexArray *va, const std::size_t *nodeIds,
                          bool &unique, const int *idx, int n,
                          const unsigned int *col)
{
  if(!unique || !nodeIds) return false;

  std::uint64_t k[8];
  for(int i = 0; i < n; i++) {
    if(!nodeIds[idx[i]]) return false; // no topology for this node
    k[2 * i] = nodeIds[idx[i]];
    k[2 * i + 1] = col[i];
  }
  // sort the (node, color) pairs by node; the color is part of the key
  for(int i = 1; i < n; i++)
    for(int j = i; j > 0 && k[2 * j] < k[2 * (j - 1)]; j--) {
      std::swap(k[2 * j], k[2 * (j - 1)]);
      std::swap(k[2 * j + 1], k[2 * (j - 1) + 1]);
    }

  unique = false;
  if(va->getUniqueFilter(false)->isDuplicate(k, 2 * n)) {
    va->addUniqueStats(n, 0);
    return true;
  }
  va->addUniqueStats(n, n);
  return false;
}

// With smoothed normals, the normal at a point is the average of those of
// the faces through it: gathered by the pass that only collects them (pre),
// read back by the one that draws.
static void smoothNormal(drawTarget *p, bool pre, double x, double y, double z,
                         SVector3 &n)
{
  if(!p->opt->smoothNormals) return;
  if(pre)
    p->normals->add(x, y, z, n[0], n[1], n[2]);
  else
    p->normals->get(x, y, z, n[0], n[1], n[2]);
}

// f(k, min, max) for each band of the scale, or f(k, iso) for each iso-value:
// the middle one only when the range is empty
template <class F>
static void forBands(PViewOptions *opt, double vmin, double vmax, F f)
{
  for(int k = 0; k < opt->nbIso; k++) {
    if(vmin == vmax) k = opt->nbIso / 2;
    f(k, opt->getScaleValue(k, opt->nbIso + 1, vmin, vmax),
      opt->getScaleValue(k + 1, opt->nbIso + 1, vmin, vmax));
    if(vmin == vmax) break;
  }
}

template <class F>
static void forIsos(PViewOptions *opt, double vmin, double vmax, F f)
{
  for(int k = 0; k < opt->nbIso; k++) {
    if(vmin == vmax) k = opt->nbIso / 2;
    f(k, opt->getScaleValue(k, opt->nbIso, vmin, vmax));
    if(vmin == vmax) break;
  }
}

// the triangles of a convex polygon of nb points, as a fan around its first,
// with the normal n and a colour per point of the polygon
static void addFan(drawTarget *p, bool pre, int nb, const double *x,
                   const double *y, const double *z, const SVector3 &nfac,
                   const unsigned int *col, bool unique)
{
  for(int j = 2; j < nb; j++) {
    const int t[3] = {0, j - 1, j};
    double x3[3], y3[3], z3[3];
    SVector3 n[3] = {nfac, nfac, nfac};
    unsigned int c3[3];
    for(int i = 0; i < 3; i++) {
      x3[i] = x[t[i]];
      y3[i] = y[t[i]];
      z3[i] = z[t[i]];
      c3[i] = col[t[i]];
      smoothNormal(p, pre, x3[i], y3[i], z3[i], n[i]);
    }
    if(!pre) p->va_triangles->add(x3, y3, z3, n, c3, nullptr, unique);
  }
}

static void addScalarPoint(drawTarget *p, double **xyz, double **val, bool pre,
                           int i0 = 0, bool unique = false)
{
  if(pre) return;

  PViewOptions *opt = p->opt;

  double vmin = opt->tmpMin, vmax = opt->tmpMax;
  if(opt->saturateValues) saturate(1, val, vmin, vmax, i0);

  if(val[i0][0] >= vmin && val[i0][0] <= vmax) {
    unsigned int col = opt->getColor(
      val[i0][0], vmin, vmax, false,
      (opt->intervalsType == PViewOptions::Discrete) ? opt->nbIso : -1);
    SVector3 n = getPointNormal(p, val[i0][0]);
    p->va_points->add(&xyz[i0][0], &xyz[i0][1], &xyz[i0][2], &n, &col, nullptr,
                      unique);
  }
}

static void addOutlineLine(drawTarget *p, double **xyz, unsigned int color,
                           bool pre, int i0 = 0, int i1 = 1)
{
  if(pre) return;

  const int in[2] = {i0, i1};
  unsigned int col[2];
  double x[2], y[2], z[2];
  for(int i = 0; i < 2; i++) {
    x[i] = xyz[in[i]][0];
    y[i] = xyz[in[i]][1];
    z[i] = xyz[in[i]][2];
    col[i] = color;
  }
  SVector3 n[2];
  getLineNormal(p, x, y, z, nullptr, n, true);
  p->va_lines->add(x, y, z, n, col, nullptr, true);
}

static void addScalarLine(drawTarget *p, double **xyz, double **val, bool pre,
                          int i0 = 0, int i1 = 1, bool unique = false)
{
  if(pre) return;

  PViewOptions *opt = p->opt;

  if(opt->boundary > 0) {
    opt->boundary--;
    addScalarPoint(p, xyz, val, pre, i0, true);
    addScalarPoint(p, xyz, val, pre, i1, true);
    opt->boundary++;
    return;
  }

  double vmin = opt->tmpMin, vmax = opt->tmpMax;
  if(opt->saturateValues) saturate(2, val, vmin, vmax, i0, i1);

  double x[2] = {xyz[i0][0], xyz[i1][0]};
  double y[2] = {xyz[i0][1], xyz[i1][1]};
  double z[2] = {xyz[i0][2], xyz[i1][2]};
  double v[2] = {val[i0][0], val[i1][0]};

  if(opt->intervalsType == PViewOptions::Continuous) {
    SVector3 n[2];
    getLineNormal(p, x, y, z, v, n, true);
    if(val[i0][0] >= vmin && val[i0][0] <= vmax && val[i1][0] >= vmin &&
       val[i1][0] <= vmax) {
      unsigned int col[2];
      for(int i = 0; i < 2; i++) col[i] = opt->getColor(v[i], vmin, vmax);
      const int ii[2] = {i0, i1};
      if(topoDuplicate(p->va_lines, p->nodeIds, unique, ii, 2, col)) return;
      p->va_lines->add(x, y, z, n, col, nullptr, unique);
    }
    else {
      double x2[2], y2[2], z2[2], v2[2];
      int nb = CutLine(x, y, z, v, vmin, vmax, x2, y2, z2, v2);
      if(nb == 2) {
        unsigned int col[2];
        for(int i = 0; i < 2; i++) col[i] = opt->getColor(v2[i], vmin, vmax);
        // the values of the cut segment, which its cylinder is sized by
        SVector3 n2[2];
        getLineNormal(p, x2, y2, z2, v2, n2, true);
        p->va_lines->add(x2, y2, z2, n2, col, nullptr, unique);
      }
    }
  }

  if(opt->intervalsType == PViewOptions::Discrete) {
    forBands(opt, vmin, vmax, [&](int k, double min, double max) {
      double x2[2], y2[2], z2[2], v2[2];
      int nb = CutLine(x, y, z, v, min, max, x2, y2, z2, v2);
      if(nb == 2) {
        unsigned int color = opt->getColor(k, opt->nbIso);
        unsigned int col[2] = {color, color};
        SVector3 n[2];
        getLineNormal(p, x2, y2, z2, v2, n, true);
        p->va_lines->add(x2, y2, z2, n, col, nullptr, unique);
      }
    });
  }

  if(opt->intervalsType == PViewOptions::Iso) {
    forIsos(opt, vmin, vmax, [&](int k, double iso) {
      double x2[1], y2[1], z2[1];
      int nb = IsoLine(x, y, z, v, iso, x2, y2, z2);
      if(nb == 1) {
        unsigned int color = opt->getColor(k, opt->nbIso);
        SVector3 n = getPointNormal(p, iso);
        p->va_points->add(x2, y2, z2, &n, &color, nullptr, unique);
      }
    });
  }
}

// an edge (a, b) of the outline of an element, lit with the normal of its
// face when there is one
static void addOutlineEdge(drawTarget *p, double **xyz, unsigned int color,
                           bool pre, int a, int b, const SVector3 *nfac)
{
  double x[2] = {xyz[a][0], xyz[b][0]};
  double y[2] = {xyz[a][1], xyz[b][1]};
  double z[2] = {xyz[a][2], xyz[b][2]};
  SVector3 n[2];
  if(nfac) {
    n[0] = n[1] = *nfac;
    for(int j = 0; j < 2; j++) smoothNormal(p, pre, x[j], y[j], z[j], n[j]);
  }
  unsigned int col[2] = {color, color};
  getLineNormal(p, x, y, z, nullptr, n, false);
  if(!pre) p->va_lines->add(x, y, z, n, col, nullptr, true);
}

// the edges of a face of n corners
static void addOutlineFace(drawTarget *p, double **xyz, unsigned int color,
                           bool pre, const int *idx, int n)
{
  SVector3 nfac = normal3(xyz, idx[0], idx[1], idx[2]);
  for(int i = 0; i < n; i++)
    addOutlineEdge(p, xyz, color, pre, idx[i], idx[(i + 1) % n], &nfac);
}

static void addOutlineTriangle(drawTarget *p, double **xyz, unsigned int color,
                               bool pre, int i0 = 0, int i1 = 1, int i2 = 2)
{
  const int idx[3] = {i0, i1, i2};
  addOutlineFace(p, xyz, color, pre, idx, 3);
}

static void addScalarTriangle(drawTarget *p, double **xyz, double **val,
                              bool pre, int i0 = 0, int i1 = 1, int i2 = 2,
                              bool unique = false, bool skin = false)
{
  PViewOptions *opt = p->opt;

  // the pass marking the skin only draws the faces that may be on it
  if(skin || markingBoundaryFaces) {
    const int ii[3] = {i0, i1, i2};
    if(!skin || !skinFace(p, ii, 3)) return;
  }

  const int il[3][2] = {{i0, i1}, {i1, i2}, {i2, i0}};

  if(opt->boundary > 0) {
    opt->boundary--;
    for(int i = 0; i < 3; i++)
      addScalarLine(p, xyz, val, pre, il[i][0], il[i][1], true);
    opt->boundary++;
    return;
  }

  double vmin = opt->tmpMin, vmax = opt->tmpMax;
  if(opt->saturateValues) saturate(3, val, vmin, vmax, i0, i1, i2);

  double x[3] = {xyz[i0][0], xyz[i1][0], xyz[i2][0]};
  double y[3] = {xyz[i0][1], xyz[i1][1], xyz[i2][1]};
  double z[3] = {xyz[i0][2], xyz[i1][2], xyz[i2][2]};
  double v[3] = {val[i0][0], val[i1][0], val[i2][0]};

  SVector3 nfac = normal3(xyz, i0, i1, i2);

  if(opt->intervalsType == PViewOptions::Continuous) {
    if(val[i0][0] >= vmin && val[i0][0] <= vmax && val[i1][0] >= vmin &&
       val[i1][0] <= vmax && val[i2][0] >= vmin && val[i2][0] <= vmax) {
      SVector3 n[3] = {nfac, nfac, nfac};
      unsigned int col[3];
      for(int i = 0; i < 3; i++) {
        smoothNormal(p, pre, x[i], y[i], z[i], n[i]);
        col[i] = opt->getColor(v[i], vmin, vmax);
      }
      const int ii[3] = {i0, i1, i2};
      if(!pre &&
         topoDuplicate(p->va_triangles, p->nodeIds, unique, ii, 3, col))
        return;
      if(!pre) p->va_triangles->add(x, y, z, n, col, nullptr, unique);
    }
    else {
      double x2[10], y2[10], z2[10], v2[10];
      int nb = CutTriangle(x, y, z, v, vmin, vmax, x2, y2, z2, v2);
      unsigned int col[10];
      for(int i = 0; i < nb; i++) col[i] = opt->getColor(v2[i], vmin, vmax);
      addFan(p, pre, nb, x2, y2, z2, nfac, col, unique);
    }
  }

  if(opt->intervalsType == PViewOptions::Discrete) {
    forBands(opt, vmin, vmax, [&](int k, double min, double max) {
      double x2[10], y2[10], z2[10], v2[10];
      int nb = CutTriangle(x, y, z, v, min, max, x2, y2, z2, v2);
      unsigned int col[10];
      for(int i = 0; i < nb; i++) col[i] = opt->getColor(k, opt->nbIso);
      addFan(p, pre, nb, x2, y2, z2, nfac, col, unique);
    });
  }

  if(opt->intervalsType == PViewOptions::Iso) {
    forIsos(opt, vmin, vmax, [&](int k, double iso) {
      double x2[3], y2[3], z2[3];
      int nb = IsoTriangle(x, y, z, v, iso, x2, y2, z2);
      if(nb == 2) {
        unsigned int color = opt->getColor(k, opt->nbIso);
        unsigned int col[2] = {color, color};
        SVector3 n[2] = {nfac, nfac};
        for(int i = 0; i < 2; i++) smoothNormal(p, pre, x2[i], y2[i], z2[i], n[i]);
        double v[2] = {iso, iso};
        getLineNormal(p, x, y, z, v, n, false);
        if(!pre) p->va_lines->add(x2, y2, z2, n, col, nullptr, unique);
      }
    });
  }
}

static void addOutlineQuadrangle(drawTarget *p, double **xyz,
                                 unsigned int color, bool pre, int i0 = 0,
                                 int i1 = 1, int i2 = 2, int i3 = 3)
{
  const int idx[4] = {i0, i1, i2, i3};
  addOutlineFace(p, xyz, color, pre, idx, 4);
}

static void addScalarQuadrangle(drawTarget *p, double **xyz, double **val,
                                bool pre, int i0 = 0, int i1 = 1, int i2 = 2,
                                int i3 = 3, bool unique = false)
{
  PViewOptions *opt = p->opt;

  const int il[4][2] = {{i0, i1}, {i1, i2}, {i2, i3}, {i3, i0}};
  const int it[2][3] = {{i0, i1, i2}, {i0, i2, i3}};

  if(opt->boundary > 0) {
    opt->boundary--;
    for(int i = 0; i < 4; i++)
      addScalarLine(p, xyz, val, pre, il[i][0], il[i][1], true);
    opt->boundary++;
    return;
  }

  for(int i = 0; i < 2; i++)
    addScalarTriangle(p, xyz, val, pre, it[i][0], it[i][1], it[i][2], unique);
}

static void addOutlinePolygon(drawTarget *p, int ient, int iele, int numNodes,
                              double **xyz, unsigned int color, bool pre)
{
  PViewOptions *opt = p->opt;
  PViewData *data = p->view->getData();
  MPolygon *polygon =
    static_cast<MPolygon *>(data->getElement(opt->timeStep, ient, iele));
  int numEdges = polygon ? polygon->getNumEdgesRep(false) : numNodes;
  SVector3 nfac = polygon ? polygon->getNormal() : SVector3(0., 0., 1.);
  for(int i = 0; i < numEdges; i++) {
    std::array<int, 2> is = polygon ? polygon->getEdgeRepIndices(false, i) :
                                      std::array<int, 2>{i, (i + 1) % numNodes};
    addOutlineEdge(p, xyz, color, pre, is[0], is[1], &nfac);
  }
}

static void addScalarPolygon(drawTarget *p, int ient, int iele, int numNodes,
                             double **xyz, double **val, bool pre,
                             bool unique = false)
{
  PViewOptions *opt = p->opt;
  PViewData *data = p->view->getData();
  MPolygon *polygon =
    static_cast<MPolygon *>(data->getElement(opt->timeStep, ient, iele));

  if(opt->boundary > 0) {
    opt->boundary--;
    int numEdges = polygon ? polygon->getNumEdgesRep(false) : numNodes;
    for(int i = 0; i < numEdges; i++) {
      std::array<int, 2> is = polygon ?
                                polygon->getEdgeRepIndices(false, i) :
                                std::array<int, 2>{i, (i + 1) % numNodes};
      addScalarLine(p, xyz, val, pre, is[0], is[1], true);
    }
    opt->boundary++;
    return;
  }

  if(!polygon) { // list data: a fan
    for(int i = 1; i < numNodes - 1; i++)
      addScalarTriangle(p, xyz, val, pre, 0, i, i + 1, unique);
    return;
  }
  for(int i = 0; i < polygon->getNumTriangles(); i++) {
    std::array<int, 3> is = polygon->getTriangleIndices(i);
    addScalarTriangle(p, xyz, val, pre, is[0], is[1], is[2], unique);
  }
}

// How a 3D element is drawn: its faces, for its outline, its boundary and
// its skin (the quadrangles first), and the tetrahedra it is split into for
// the rest (and for the caps)
struct solidShape {
  int numQuads;
  const int (*quads)[4];
  int numTriangles;
  const int (*triangles)[3];
  int numTets;
  const int (*tets)[4];
};

static const int tetTriangles[4][3] = {
  {0, 2, 1}, {0, 1, 3}, {0, 3, 2}, {3, 1, 2}};
static const int tetTets[1][4] = {{0, 1, 2, 3}};
static const solidShape tetShape = {0, nullptr, 4, tetTriangles, 1, tetTets};

static const int hexQuads[6][4] = {{0, 3, 2, 1}, {0, 1, 5, 4}, {0, 4, 7, 3},
                                   {1, 2, 6, 5}, {2, 3, 7, 6}, {4, 5, 6, 7}};
static const int hexTets[6][4] = {{0, 1, 3, 7}, {0, 4, 1, 7}, {1, 4, 5, 7},
                                  {1, 2, 3, 7}, {1, 6, 2, 7}, {1, 5, 6, 7}};
static const solidShape hexShape = {6, hexQuads, 0, nullptr, 6, hexTets};

static const int priQuads[3][4] = {{0, 1, 4, 3}, {0, 3, 5, 2}, {1, 2, 5, 4}};
static const int priTriangles[2][3] = {{0, 2, 1}, {3, 4, 5}};
static const int priTets[3][4] = {{0, 1, 2, 4}, {0, 4, 2, 5}, {0, 3, 4, 5}};
static const solidShape priShape = {3, priQuads, 2, priTriangles, 3, priTets};

static const int pyrQuads[1][4] = {{0, 3, 2, 1}};
static const int pyrTriangles[4][3] = {
  {0, 1, 4}, {3, 0, 4}, {1, 2, 4}, {2, 3, 4}};
static const int pyrTets[2][4] = {{0, 1, 3, 4}, {1, 2, 3, 4}};
static const solidShape pyrShape = {1, pyrQuads, 4, pyrTriangles, 2, pyrTets};

static const solidShape *solidShapes[4] = {&tetShape, &hexShape, &priShape,
                                           &pyrShape};
static const int solidCorners[4] = {4, 8, 6, 5};

static int solidShapeIndex(int type)
{
  switch(type) {
  case TYPE_TET: return 0;
  case TYPE_HEX: return 1;
  case TYPE_PRI: return 2;
  case TYPE_PYR: return 3;
  }
  return -1;
}

// the nodes of face f of a shape (its quadrangles first, then its triangles)
static int solidFace(const solidShape &s, int f, const int *&idx)
{
  if(f < s.numQuads) {
    idx = s.quads[f];
    return 4;
  }
  idx = s.triangles[f - s.numQuads];
  return 3;
}

static bool maskedSkinFace(drawTarget *p, const int *idx, int n)
{
  const solidShape &s = *p->skinShape;
  unsigned int bits = 0;
  for(int k = 0; k < n; k++) bits |= 1u << idx[k];
  for(int f = 0; f < s.numQuads + s.numTriangles; f++) {
    const int *fi;
    if(solidFace(s, f, fi) != n) continue;
    unsigned int b = 0;
    for(int k = 0; k < n; k++) b |= 1u << fi[k];
    if(b == bits) return (p->skinMask >> f) & 1;
  }
  return true;
}

// The elements of the entities that are drawn, numbered in a single flat
// index space, so that a loop on them can be split evenly between threads
// whatever the size of each entity
struct flatElements {
  std::vector<int> ents;
  std::vector<std::size_t> start;
  std::size_t num;
  flatElements(PViewData *data, PViewOptions *opt) : num(0)
  {
    int numEnt = data->getNumEntities(opt->timeStep);
    for(int ent = 0; ent < numEnt; ent++) {
      if(data->skipEntity(opt->timeStep, ent)) continue;
      ents.push_back(ent);
      start.push_back(num);
      num += data->getNumElements(opt->timeStep, ent);
    }
    start.push_back(num);
  }
  // calls f(entity, element in it, flat index) on [first, last)
  template <class F> void forRange(std::size_t first, std::size_t last, F f) const
  {
    std::size_t e = 0;
    while(e + 1 < ents.size() && start[e + 1] <= first) e++;
    for(; e < ents.size() && start[e] < last; e++) {
      std::size_t i0 = first > start[e] ? first - start[e] : 0;
      std::size_t i1 = std::min(last, start[e + 1]) - start[e];
      for(std::size_t i = i0; i < i1; i++) f(ents[e], (int)i, start[e] + i);
    }
  }
};

// how many threads walk the elements of a view: options that touch shared
// state (smoothed normals, general raise, external view, Gauss points) are
// handled serially
static int numWalkThreads(PViewData *data, PViewOptions *opt, std::size_t num)
{
  int nthreads = CTX::instance()->numThreads;
  if(!nthreads) nthreads = Msg::GetMaxThreads();
  if(num < 10000) nthreads = 1;
  if(opt->smoothNormals || opt->useGenRaise || opt->externalViewIndex >= 0 ||
     data->useGaussPoints() || !data->isThreadSafe())
    nthreads = 1;
  return nthreads;
}

// The spheres around the elements of a view (see ElementSpheres.h), from their
// coordinates as the options change them. Built when the planes first need
// them, dropped when the view changes.
static OwnerCache<elementSpheres> _viewSpheres;

static const elementSpheres *getSpheres(PView *p, const flatElements &flat)
{
  if(flat.num < 50000) return nullptr; // walking them all is fast enough
  elementSpheres *found = _viewSpheres.find(p);
  if(found && found->size() == flat.num) return found;
  double t1 = TimeOfDay();
  elementSpheres &sp = _viewSpheres[p];
  sp.assign(flat.num);
  PViewData *data = p->getData(true);
  int nthreads = numWalkThreads(data, p->getOptions(), flat.num);
#pragma omp parallel for schedule(static, 1) num_threads(nthreads)
  for(int t = 0; t < nthreads; t++) {
    PViewElement el;
    flat.forRange(flat.num * t / nthreads, flat.num * (t + 1) / nthreads,
                  [&](int ent, int ele, std::size_t i) {
                    if(!el.select(p, ent, ele)) return;
                    el.read(p, false);
                    sp.set(i, el.dim, el.numNodes,
                           [&](int j, int k) { return el.xyz[j][k]; });
                  });
  }
  Msg::Debug("Bounded the elements of View[%d] in %g s (%g MB)", p->getIndex(),
             TimeOfDay() - t1, sp.getMemoryInMB());
  return &sp;
}

// The skin found ahead of the drawing, from the nodes of the 3D elements
// alone: a byte per element, 0x80 if its faces were looked at, plus a bit for
// each of them seen once only (faces are told apart by their sorted nodes and
// the entity, so that the skin is taken entity by entity). The drawing then
// reads the elements that have a face on the skin and none of the others.
// (A face that an invalid mesh gives to three elements is drawn by the last
// of them, where matching faces while drawing had the first one draw it.)
static std::vector<std::uint8_t> skinMasks;
static const std::vector<std::uint8_t> *activeSkinMasks = nullptr;

// The skin of a view is kept from one filling of its arrays to the next, as
// long as what it depends on stays: the data, the mesh (the visibility of
// its elements included), and the options choosing the elements that are
// drawn. A change of range, of colours or of light then costs the drawing
// of the skin alone.
// The elements that have data can differ from one step to the next, so each
// step has its own, the last few being kept for a view that is animated.
struct keptSkin {
  std::vector<double> key;
  std::vector<std::uint8_t> masks;
};
static OwnerCache<std::list<keptSkin> > _viewSkin;
static const std::size_t maxKeptSkins = 16;

static std::vector<double> skinKey(PViewData *data, PViewOptions *opt,
                                   const flatElements &flat)
{
  CTX *ctx = CTX::instance();
  int step = opt->timeStep;
  std::vector<double> k;
  k.push_back((double)(std::uintptr_t)data);
  k.push_back(data->getStamp());
  k.push_back((double)flat.num);
  k.push_back((double)flat.ents.size());
  k.push_back(data->getNumTetrahedra(step));
  k.push_back(data->getNumHexahedra(step));
  k.push_back(data->getNumPrisms(step));
  k.push_back(data->getNumPyramids(step));
  for(int d = 0; d < 4; d++) k.push_back(ctx->mesh.stamp[d]);
  k.push_back(ctx->entityVisibilityStamp);
  k.push_back(opt->sampling);
  k.push_back(opt->drawTetrahedra);
  k.push_back(opt->drawHexahedra);
  k.push_back(opt->drawPrisms);
  k.push_back(opt->drawPyramids);
  k.push_back(opt->drawScalars);
  k.push_back(opt->drawVectors);
  k.push_back(opt->drawTensors);
  k.push_back(opt->vectorType == PViewOptions::Displacement);
  k.push_back(opt->forceNumComponents);
  k.push_back(skinOutlines(opt));
  k.push_back(step); // last: see where the key is used
  return k;
}

static bool findSkin(PView *p, const flatElements &flat, bool keptOnly,
                     const elementSpheres *spheres,
                     const std::vector<std::uint8_t> *original);

// the skin of the field, kept or found now (null if it cannot be)
static const std::vector<std::uint8_t> *getSkin(PView *p, PViewData *data,
                                                PViewOptions *opt,
                                                const flatElements &flat)
{
  double t1 = TimeOfDay();
  std::vector<double> key = skinKey(data, opt, flat);
  std::list<keptSkin> &kept = _viewSkin[p];
  // what was found for another state of the data or of the mesh is of no
  // use any more (the step is the last entry of the key)
  kept.remove_if([&](const keptSkin &k) {
    return k.key.size() != key.size() ||
           !std::equal(key.begin(), key.end() - 1, k.key.begin());
  });
  auto it = std::find_if(kept.begin(), kept.end(), [&](const keptSkin &k) {
    return k.key == key && k.masks.size() == flat.num;
  });
  if(it != kept.end()) {
    kept.splice(kept.begin(), kept, it); // most recently used first
    return &kept.front().masks;
  }
  if(!findSkin(p, flat, false, nullptr, nullptr)) return nullptr;
  kept.push_front(keptSkin());
  kept.front().key = key;
  kept.front().masks.swap(skinMasks);
  if(kept.size() > maxKeptSkins) kept.pop_back();
  Msg::Debug("Found the skin of View[%d] in %g s", p->getIndex(),
             TimeOfDay() - t1);
  return &kept.front().masks;
}

// keptOnly: the faces of the cut elements that are on the skin of what whole
// element mode keeps (the other elements are not drawn from the clip arrays).
// They are found from the cut elements alone. A face two of them share is
// interior. The element on the other side of any other face is not cut, so
// that it is wholly kept or wholly removed, and the face tells which: removed
// if its corners are all beyond one of the planes. And there is no element on
// the other side of a face of the skin of the field (original).
static bool findSkin(PView *p, const flatElements &flat, bool keptOnly,
                     const elementSpheres *spheres,
                     const std::vector<std::uint8_t> *original)
{
  PViewData *data = p->getData(true);
  PViewOptions *opt = p->getOptions();
  CTX *ctx = CTX::instance();
  int step = opt->timeStep;
  if(flat.num >= 0xffffffffu) return false;
  if(!(opt->explode == 1. && !opt->normalRaise && !opt->useGenRaise))
    return false; // no topology
  if(data->useGaussPoints() || opt->intervalsType == PViewOptions::Numeric ||
     opt->tmpMin > opt->tmpMax)
    return false;
  if(data->getNumPolyhedra(step)) return false; // drawn through tetrahedra
  if(keptOnly && !spheres) return false;
  // the view's own arrays are filled through the planes in that mode
  if(!keptOnly && ctx->clipWholeElements && opt->clip &&
     ctx->clipOnlyDrawIntersectingVolume)
    return false;

  if(keptOnly && (!original || original->size() != flat.num)) return false;
  activePlanes planes(opt->clip);

  double t0 = TimeOfDay();
  struct chunk {
    std::vector<std::uint32_t> elem, ids;
    std::vector<std::uint8_t> shape;
    std::vector<int> ent;
    // for each plane, the corners that are beyond it, a bit each (keptOnly)
    std::vector<std::uint8_t> beyond;
  };
  int nthreads = numWalkThreads(data, opt, flat.num);
  std::vector<chunk> chunks(nthreads);
  std::atomic<bool> bad(false);
  skinMasks.assign(flat.num, 0);

#pragma omp parallel for schedule(static, 1) num_threads(nthreads)
  for(int t = 0; t < nthreads; t++) {
    PViewElement el;
    chunk &c = chunks[t];
    flat.forRange(
      flat.num * t / nthreads, flat.num * (t + 1) / nthreads,
      [&](int ent, int ele, std::size_t i) {
        if(bad) return;
        if(keptOnly && (!spheres->drawn(i) || spheres->dim(i) != 3 ||
                        planes.gap(spheres->sphere(i)) > 0.))
          return;
        if(!el.select(p, ent, ele)) return;
        int sh = solidShapeIndex(el.type);
        if(sh < 0) return;
        int numComp = opt->forceNumComponents ? opt->forceNumComponents :
                                                el.numComp;
        // the elements whose faces are drawn: those of a scalar, or of a
        // vector shown as a displacement (what a tensor draws is left to
        // the drawing itself)
        if(numComp == 9 && opt->drawTensors) {
          bad = true;
          return;
        }
        // (all of them if the skin is wanted for the outlines)
        if(!(numComp == 1 && opt->drawScalars) &&
           !(numComp == 3 && opt->drawVectors &&
             opt->vectorType == PViewOptions::Displacement) &&
           !skinOutlines(opt))
          return;
        int nc = solidCorners[sh];
        if(el.numNodes < nc) return;
        if(keptOnly) {
          el.read(p, false);
          if(!elementIsCut(opt, el.dim, el.numNodes, el.xyz)) return;
          for(int clip = 0; clip < 6; clip++) {
            std::uint8_t b = 0;
            if(opt->clip & (1 << clip))
              for(int j = 0; j < nc; j++)
                if(evalClipPlane(clip, el.xyz[j][0], el.xyz[j][1],
                                 el.xyz[j][2]) < 0.)
                  b |= (std::uint8_t)(1 << j);
            c.beyond.push_back(b);
          }
        }
        for(int j = 0; j < nc; j++) {
          std::size_t id = data->getNodeId(step, ent, ele, j);
          if(!id || id >= 0xffffffffu) {
            bad = true;
            return;
          }
          c.ids.push_back((std::uint32_t)id);
        }
        c.elem.push_back((std::uint32_t)i);
        c.shape.push_back((std::uint8_t)sh);
        c.ent.push_back(ent);
        skinMasks[i] = 0x80;
      });
  }
  if(bad) {
    skinMasks.clear();
    return false;
  }
  Msg::Debug("Skin: nodes of the elements read in %g s", TimeOfDay() - t0);

  // each thread matches its share of the faces, in a table of its own
  std::vector<std::vector<std::pair<std::uint32_t, int> > > skin(nthreads);

#pragma omp parallel for schedule(static, 1) num_threads(nthreads)
  for(int t = 0; t < nthreads; t++) {
    FaceMatcher<std::uint32_t, std::uint32_t> matcher;
    for(auto &c : chunks) {
      const std::uint32_t *ids = c.ids.data();
      for(std::size_t e = 0; e < c.elem.size(); e++) {
        const solidShape &s = *solidShapes[c.shape[e]];
        int nf = s.numQuads + s.numTriangles; // 6 at most
        std::uint64_t hash[6];
        for(int f = 0; f < nf; f++) {
          const int *fi;
          int n = solidFace(s, f, fi);
          std::uint32_t k[4] = {ids[fi[0]], ids[fi[1]], ids[fi[2]],
                                n == 4 ? ids[fi[3]] : 0};
          hash[f] = (matcher.share(k, n, nthreads) == t) ?
                      matcher.hashOf(k, n, c.ent[e]) : 0;
        }
        for(int f = 0; f < nf; f++)
          if(hash[f]) matcher.add(hash[f], c.elem[e], f);
        ids += solidCorners[c.shape[e]];
      }
    }
    matcher.forEachLeft([&](std::uint32_t elem, int face) {
      skin[t].push_back({elem, face});
    });
  }
  for(auto &sk : skin) {
    for(auto &f : sk) {
      if(keptOnly && !(((*original)[f.first] >> f.second) & 1)) {
        // is the element on the other side removed?
        int t = 0;
        while(t + 1 < nthreads && flat.num * (t + 1) / nthreads <= f.first) t++;
        const chunk &c = chunks[t];
        std::size_t e =
          std::lower_bound(c.elem.begin(), c.elem.end(), f.first) -
          c.elem.begin();
        const int *fi;
        int n = solidFace(*solidShapes[c.shape[e]], f.second, fi);
        unsigned int corners = 0;
        for(int k = 0; k < n; k++) corners |= 1u << fi[k];
        bool removed = false;
        for(int clip = 0; clip < 6 && !removed; clip++)
          removed = (opt->clip & (1 << clip)) &&
                    (c.beyond[6 * e + clip] & corners) == corners;
        if(!removed) continue;
      }
      skinMasks[f.first] |= (std::uint8_t)(1 << f.second);
    }
  }
  return true;
}

static void addOutlineSolid(drawTarget *p, double **xyz, unsigned int color,
                            bool pre, const solidShape &s)
{
  // the faces on the skin alone, if asked and if it was found ahead
  int mask = (p->opt->drawSkinEdgesOnly && p->skinMask >= 0) ? p->skinMask : ~0;
  for(int i = 0; i < s.numQuads; i++)
    if(mask & (1 << i)) addOutlineFace(p, xyz, color, pre, s.quads[i], 4);
  for(int i = 0; i < s.numTriangles; i++)
    if(mask & (1 << (s.numQuads + i)))
      addOutlineFace(p, xyz, color, pre, s.triangles[i], 3);
}

// add the section a clipping plane cuts out of a 3D element, colored with
// the field and moved slightly towards the kept side so that the plane does
// not clip it away (the other planes still do)
static void addScalarCap(drawTarget *p, double **xyz, double **val, int i0,
                         int i1, int i2, int i3)
{
  PViewOptions *opt = p->opt;
  // only the pass gathering the section wants it
  if(p->collect != drawTarget::COLLECT_CAPS) return;
  if(!opt->clip || !CTX::instance()->clipCapping) return;
  // no hole to fill in whole element mode
  if(CTX::instance()->clipWholeElements) return;
  // the section is only meaningful where the element is drawn as a solid
  if(opt->intervalsType != PViewOptions::Continuous &&
     opt->intervalsType != PViewOptions::Discrete)
    return;

  const int ii[4] = {i0, i1, i2, i3};
  double X[4], Y[4], Z[4], V[4];
  for(int i = 0; i < 4; i++) {
    X[i] = xyz[ii[i]][0];
    Y[i] = xyz[ii[i]][1];
    Z[i] = xyz[ii[i]][2];
    V[i] = val[ii[i]][0];
  }

  double cx[3][3], cv[3][9];
  double *cxyz[3] = {cx[0], cx[1], cx[2]};
  double *cval[3] = {cv[0], cv[1], cv[2]};

  for(int c = 0; c < 6; c++) {
    if(!(opt->clip & (1 << c))) continue;
    double *pl = CTX::instance()->clipPlane[c];
    double D[4];
    int neg = 0, pos = 0;
    for(int i = 0; i < 4; i++) {
      D[i] = pl[0] * X[i] + pl[1] * Y[i] + pl[2] * Z[i] + pl[3];
      if(D[i] < 0.)
        neg++;
      else
        pos++;
    }
    if(!neg || !pos) continue; // the plane does not cut this element

    double n[3] = {pl[0], pl[1], pl[2]};
    double len = sqrt(n[0] * n[0] + n[1] * n[1] + n[2] * n[2]);
    if(len < 1.e-15) continue;
    for(int i = 0; i < 3; i++) n[i] /= len;

    double xp[4], yp[4], zp[4], vp[4];
    int nb = CutSimplexByPlane(X, Y, Z, V, D, n, xp, yp, zp, vp);
    if(nb < 3) continue;

    // the corners are on the plane: move them just inside
    double eps = 1.e-5 * CTX::instance()->lc;
    for(int i = 0; i < nb; i++) {
      xp[i] += eps * n[0];
      yp[i] += eps * n[1];
      zp[i] += eps * n[2];
    }

    for(int j = 2; j < nb; j++) {
      const int t[3] = {0, j - 1, j};
      for(int i = 0; i < 3; i++) {
        cx[i][0] = xp[t[i]];
        cx[i][1] = yp[t[i]];
        cx[i][2] = zp[t[i]];
        cv[i][0] = vp[t[i]];
      }
      addScalarTriangle(p, cxyz, cval, false, 0, 1, 2, false, false);
    }
  }
}

static void addScalarTetrahedron(drawTarget *p, double **xyz, double **val,
                                 bool pre, int i0 = 0, int i1 = 1, int i2 = 2,
                                 int i3 = 3)
{
  PViewOptions *opt = p->opt;

  const int ii[4] = {i0, i1, i2, i3};

  if(!pre && opt->boundary <= 0) addScalarCap(p, xyz, val, i0, i1, i2, i3);
  // the pass gathering the section stops here
  if(p->collect == drawTarget::COLLECT_CAPS) return;

  if(opt->boundary > 0 || opt->intervalsType == PViewOptions::Continuous ||
     opt->intervalsType == PViewOptions::Discrete) {
    bool skin = (opt->boundary > 0) ? false : opt->drawSkinOnly;
    opt->boundary--;
    for(int i = 0; i < 4; i++) {
      const int *t = tetTriangles[i];
      addScalarTriangle(p, xyz, val, pre, ii[t[0]], ii[t[1]], ii[t[2]], true,
                        skin);
    }
    opt->boundary++;
    return;
  }

  double vmin = opt->tmpMin, vmax = opt->tmpMax;
  if(opt->saturateValues) saturate(4, val, vmin, vmax, i0, i1, i2, i3);

  double x[4] = {xyz[i0][0], xyz[i1][0], xyz[i2][0], xyz[i3][0]};
  double y[4] = {xyz[i0][1], xyz[i1][1], xyz[i2][1], xyz[i3][1]};
  double z[4] = {xyz[i0][2], xyz[i1][2], xyz[i2][2], xyz[i3][2]};
  double v[4] = {val[i0][0], val[i1][0], val[i2][0], val[i3][0]};

  if(opt->intervalsType == PViewOptions::Iso) {
    forIsos(opt, vmin, vmax, [&](int k, double iso) {
      double x2[6], y2[6], z2[6], nn[3];
      int nb = IsoSimplex(x, y, z, v, iso, x2, y2, z2, nn);
      unsigned int col[6];
      for(int i = 0; i < nb; i++) col[i] = opt->getColor(k, opt->nbIso);
      addFan(p, pre, nb, x2, y2, z2, SVector3(nn[0], nn[1], nn[2]), col,
             false);
    });
  }
}

// the elements a 3D element is made of, for the value of a scalar: its faces
// for its boundary or its skin, its tetrahedra otherwise
static void addScalarSolid(drawTarget *p, double **xyz, double **val, bool pre,
                           const solidShape &s)
{
  PViewOptions *opt = p->opt;

  if(opt->boundary > 0) {
    opt->boundary--;
    for(int i = 0; i < s.numQuads; i++)
      addScalarQuadrangle(p, xyz, val, pre, s.quads[i][0], s.quads[i][1],
                          s.quads[i][2], s.quads[i][3], true);
    for(int i = 0; i < s.numTriangles; i++)
      addScalarTriangle(p, xyz, val, pre, s.triangles[i][0],
                        s.triangles[i][1], s.triangles[i][2], true);
    opt->boundary++;
    return;
  }

  if(skinOnly(opt)) {
    // the caps still come from the tetrahedra it is split into
    if(!pre)
      for(int i = 0; i < s.numTets; i++)
        addScalarCap(p, xyz, val, s.tets[i][0], s.tets[i][1], s.tets[i][2],
                     s.tets[i][3]);
    if(p->collect == drawTarget::COLLECT_CAPS) return;
    for(int i = 0; i < s.numQuads; i++)
      if(skinFace(p, s.quads[i], 4))
        addScalarQuadrangle(p, xyz, val, pre, s.quads[i][0], s.quads[i][1],
                            s.quads[i][2], s.quads[i][3], true);
    for(int i = 0; i < s.numTriangles; i++)
      if(skinFace(p, s.triangles[i], 3))
        addScalarTriangle(p, xyz, val, pre, s.triangles[i][0],
                          s.triangles[i][1], s.triangles[i][2], true);
    return;
  }

  for(int i = 0; i < s.numTets; i++)
    addScalarTetrahedron(p, xyz, val, pre, s.tets[i][0], s.tets[i][1],
                         s.tets[i][2], s.tets[i][3]);
}

static void addOutlinePolyhedron(drawTarget *p, int ient, int iele,
                                 int numNodes, double **xyz, unsigned int color,
                                 bool pre)
{
  PViewOptions *opt = p->opt;
  PViewData *data = p->view->getData();
  MPolyhedron *polyhedron =
    static_cast<MPolyhedron *>(data->getElement(opt->timeStep, ient, iele));
  if(!polyhedron) return; // list data: the faces are unknown
  for(int i = 0; i < polyhedron->getNumEdgesRep(false); i++) {
    std::array<int, 2> is = polyhedron->getEdgeRepIndices(false, i);
    addOutlineEdge(p, xyz, color, pre, is[0], is[1], nullptr);
  }
}

static void addScalarPolyhedron(drawTarget *p, int ient, int iele,
                                int numNodes, double **xyz, double **val,
                                bool pre)
{
  PViewOptions *opt = p->opt;
  PViewData *data = p->view->getData();
  MPolyhedron *polyhedron =
    static_cast<MPolyhedron *>(data->getElement(opt->timeStep, ient, iele));
  if(!polyhedron) return; // list data: the faces are unknown

  if(opt->boundary > 0) {
    opt->boundary--;
    for(int i = 0; i < polyhedron->getNumFacesRep(false); i++) {
      std::array<int, 3> is = polyhedron->getFaceRepIndices(false, i);
      addScalarTriangle(p, xyz, val, pre, is[0], is[1], is[2], true);
    }
    opt->boundary++;
    return;
  }

  for(int i = 0; i < polyhedron->getNumTetrahedra(); i++) {
    std::array<int, 4> is = polyhedron->getTetrahedronIndices(i);
    addScalarTetrahedron(p, xyz, val, pre, is[0], is[1], is[2], is[3]);
  }
}

static void addOutlineElement(drawTarget *p, int ient, int iele, int numNodes,
                              int type, double **xyz, bool pre)
{
  PViewOptions *opt = p->opt;
  switch(type) {
  case TYPE_PNT: addOutlinePoint(p, xyz, opt->color.point, pre); break;
  case TYPE_LIN: addOutlineLine(p, xyz, opt->color.line, pre); break;
  case TYPE_TRI: addOutlineTriangle(p, xyz, opt->color.triangle, pre); break;
  case TYPE_QUA:
    addOutlineQuadrangle(p, xyz, opt->color.quadrangle, pre);
    break;
  case TYPE_POLYG:
    addOutlinePolygon(p, ient, iele, numNodes, xyz, opt->color.quadrangle, pre);
    break;
  case TYPE_TET:
    addOutlineSolid(p, xyz, opt->color.tetrahedron, pre, tetShape);
    break;
  case TYPE_HEX:
    addOutlineSolid(p, xyz, opt->color.hexahedron, pre, hexShape);
    break;
  case TYPE_PRI: addOutlineSolid(p, xyz, opt->color.prism, pre, priShape); break;
  case TYPE_PYR:
    addOutlineSolid(p, xyz, opt->color.pyramid, pre, pyrShape);
    break;
  case TYPE_TRIH:
    addOutlineQuadrangle(p, xyz, opt->color.pyramid, pre);
    break;
  case TYPE_POLYH:
    addOutlinePolyhedron(p, ient, iele, numNodes, xyz, opt->color.pyramid, pre);
    break;
  }
}

static void addScalarElement(drawTarget *p, int ient, int iele, int numNodes,
                             int type, double **xyz, double **val, bool pre)
{
  // a range given the other way round holds no value: nothing is drawn, in
  // every interval type (the bands and the iso values of a reversed range
  // would still cut the elements)
  if(p->opt->tmpMin > p->opt->tmpMax) return;
  switch(type) {
  case TYPE_PNT: addScalarPoint(p, xyz, val, pre); break;
  case TYPE_LIN: addScalarLine(p, xyz, val, pre); break;
  case TYPE_TRI: addScalarTriangle(p, xyz, val, pre); break;
  case TYPE_QUA: addScalarQuadrangle(p, xyz, val, pre); break;
  case TYPE_POLYG:
    addScalarPolygon(p, ient, iele, numNodes, xyz, val, pre);
    break;
  case TYPE_TET: addScalarTetrahedron(p, xyz, val, pre); break;
  case TYPE_HEX: addScalarSolid(p, xyz, val, pre, hexShape); break;
  case TYPE_PRI: addScalarSolid(p, xyz, val, pre, priShape); break;
  case TYPE_PYR: addScalarSolid(p, xyz, val, pre, pyrShape); break;
  case TYPE_TRIH: addScalarQuadrangle(p, xyz, val, pre); break;
  case TYPE_POLYH:
    addScalarPolyhedron(p, ient, iele, numNodes, xyz, val, pre);
    break;
  }
}

// an arrow from x along d, coloured by v (the norm, or the value of an
// external view)
static void addArrow(drawTarget *p, const double *x, const double *d,
                     double v, bool unique)
{
  PViewOptions *opt = p->opt;
  unsigned int color = opt->getColor(
    v, opt->externalMin, opt->externalMax, false,
    (opt->intervalsType == PViewOptions::Discrete) ? opt->nbIso : -1);
  unsigned int col[2] = {color, color};
  double dxyz[3][2];
  for(int j = 0; j < 3; j++) {
    dxyz[j][0] = x[j];
    dxyz[j][1] = d[j];
  }
  p->va_vectors->add(dxyz[0], dxyz[1], dxyz[2], nullptr, col, nullptr, unique);
}

static void addVectorElement(drawTarget *p, int ient, int iele, int numNodes,
                             int type, double **xyz, double **val, bool pre)
{
  // use adaptive data if available
  PViewData *data = p->view->getData(true);
  PViewOptions *opt = p->opt;
  // a range given the other way round holds no value: nothing is drawn
  if(opt->tmpMin > opt->tmpMax) return;

  int numComp2;
  static thread_local nodeRows rows;
  double **val2 = rows.get(numNodes, 9);
  getExternalValues(p, opt->externalViewIndex, ient, iele, numNodes, 3, val,
                    numComp2, val2);

  if(opt->vectorType == PViewOptions::Displacement) {
    for(int i = 0; i < numNodes; i++)
      val2[i][0] = ComputeScalarRep(numComp2, val2[i]);

    // add scalar element with correct min/max
    double min = opt->tmpMin, max = opt->tmpMax;
    opt->tmpMin = opt->externalMin;
    opt->tmpMax = opt->externalMax;
    addScalarElement(p, ient, iele, numNodes, type, xyz, val2, pre);
    opt->tmpMin = min;
    opt->tmpMax = max;

    // add point trajectories
    // FIXME: this should be optional
    if(!pre && numNodes == 1 && opt->timeStep > 0 && opt->lineWidth) {
      for(int ts = 0; ts < opt->timeStep; ts++) {
        if(!data->hasTimeStep(ts)) continue;
        int numComp = data->getNumComponents(ts, ient, iele);
        double xyz0[3], dxyz[3][2] = {{0., 0.}, {0., 0.}, {0., 0.}};
        data->getNode(ts, ient, iele, 0, xyz0[0], xyz0[1], xyz0[2]);
        for(int j = 0; j < 3; j++) {
          int comp = opt->forceNumComponents ? opt->componentMap[j] : j;
          if(comp >= 0 && comp < numComp) {
            data->getValue(ts, ient, iele, 0, comp, dxyz[j][0]);
            data->getValue(ts + 1, ient, iele, 0, comp, dxyz[j][1]);
          }
        }
        unsigned int col[2];
        double norm[2];
        for(int i = 0; i < 2; i++) {
          norm[i] = sqrt(dxyz[0][i] * dxyz[0][i] + dxyz[1][i] * dxyz[1][i] +
                         dxyz[2][i] * dxyz[2][i]);
          col[i] = opt->getColor(norm[i], opt->tmpMin, opt->tmpMax);
        }
        for(int j = 0; j < 3; j++) {
          dxyz[j][0] = xyz0[j] + dxyz[j][0] * opt->displacementFactor;
          dxyz[j][1] = xyz0[j] + dxyz[j][1] * opt->displacementFactor;
        }
        SVector3 n[2];
        getLineNormal(p, dxyz[0], dxyz[1], dxyz[2], norm, n, true);
        p->va_lines->add(dxyz[0], dxyz[1], dxyz[2], n, col, nullptr, false);
      }
    }
    return;
  }

  if(pre) return;

  if(opt->glyphLocation == PViewOptions::Vertex) {
    for(int i = 0; i < numNodes; i++) {
      double v2 = opt->saturateValues ?
                    saturateVector(val[i], numComp2, val2[i], opt->externalMin,
                                   opt->externalMax) :
                    ComputeScalarRep(numComp2, val2[i]);
      // once per node, not once per element around it (two dozen of them
      // for a node of a tetrahedral mesh): the same position with the same
      // value is the same arrow
      if(v2 >= opt->externalMin && v2 <= opt->externalMax)
        addArrow(p, xyz[i], val[i], v2, true);
    }
  }

  if(opt->glyphLocation == PViewOptions::COG) {
    // compute value by averaging the norm and averaging the directions (this
    // allows to preserve the min/max)
    SPoint3 pc(0., 0., 0.);
    double d[3] = {0., 0., 0.};
    double v2 = 0.;
    for(int i = 0; i < numNodes; i++) {
      pc += SPoint3(xyz[i][0], xyz[i][1], xyz[i][2]);
      v2 += opt->saturateValues ?
              saturateVector(val[i], numComp2, val2[i], opt->externalMin,
                             opt->externalMax) :
              ComputeScalarRep(numComp2, val2[i]);
      for(int j = 0; j < 3; j++) d[j] += val[i][j];
    }
    pc /= (double)numNodes;
    v2 /= (double)numNodes;
    norme(d);
    for(int i = 0; i < 3; i++) d[i] *= v2;

    // need tolerance since we compare computed results (the average)
    // instead of the raw data used to compute bounds
    if(v2 >= opt->externalMin * (1. - 1.e-15) &&
       v2 <= opt->externalMax * (1. + 1.e-15)) {
      double x[3] = {pc.x(), pc.y(), pc.z()};
      addArrow(p, x, d, v2, false);
    }
  }
}

static void addTriangle(drawTarget *p, PViewOptions *opt, double *x0,
                        double *x1, double *x2, SPoint3 &xx, double val)
{
  unsigned int color = opt->getColor(
    val, opt->tmpMin, opt->tmpMax, false,
    (opt->intervalsType == PViewOptions::Discrete) ? opt->nbIso : -1);

  SVector3 a(x1[0] - x0[0], x1[1] - x0[1], x1[2] - x0[2]);
  SVector3 b(x2[0] - x0[0], x2[1] - x0[1], x2[2] - x0[2]);
  SVector3 c(xx.x() - x0[0], xx.y() - x0[1], xx.z() - x0[2]);
  SVector3 N = crossprod(a, b);
  unsigned int col[3] = {color, color, color};
  N.normalize();
  // unique: the box of a node comes once per element around it otherwise
  if(dot(c, N) > 0) {
    double XX[3] = {x0[0], x1[0], x2[0]};
    double YY[3] = {x0[1], x1[1], x2[1]};
    double ZZ[3] = {x0[2], x1[2], x2[2]};
    SVector3 NN[3] = {N, N, N};
    p->va_triangles->add(XX, YY, ZZ, NN, col, nullptr, true);
  }
  else {
    double XX[3] = {x1[0], x0[0], x2[0]};
    double YY[3] = {x1[1], x0[1], x2[1]};
    double ZZ[3] = {x1[2], x0[2], x2[2]};
    SVector3 NN[3] = {-N, -N, -N};
    p->va_triangles->add(XX, YY, ZZ, NN, col, nullptr, true);
  }
}

// Whether a view draws faces, which only the skin of its volumes is kept of:
// a view of vectors drawn as arrows, or of tensors drawn as glyphs, has
// none, and the pass locating the skin would walk its elements - computing
// every eigenvector twice for tensors - for nothing. A view that cannot say
// what it holds is assumed to.
static bool viewDrawsFaces(PView *p)
{
  PViewData *data = p->getData(true);
  PViewOptions *opt = p->getOptions();
  if(opt->forceNumComponents) return true;
  int ns = data->getNumScalars(), nv = data->getNumVectors();
  int nt = data->getNumTensors();
  if(ns || (!nv && !nt)) return true;
  if(nv && opt->vectorType == PViewOptions::Displacement) return true;
  if(nt && (opt->tensorType == PViewOptions::VonMises ||
            opt->tensorType == PViewOptions::MinEigenValue ||
            opt->tensorType == PViewOptions::MaxEigenValue))
    return true;
  return false;
}

// the eigenvalues and eigenvectors (columns of rightV) of a tensor: by
// Jacobi rotations when it is symmetric, by LAPACK otherwise (a general
// solver, with allocations, for each node of each element: ten seconds for
// a million tetrahedra)
static void tensorEig(fullMatrix<double> &tensor, fullVector<double> &S,
                      fullVector<double> &imS, fullMatrix<double> &leftV,
                      fullMatrix<double> &rightV, bool sortRealPart,
                      bool valuesOnly = false)
{
  double a[9], w[3], v[3][3];
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++) a[3 * i + j] = tensor(i, j);
  if(valuesOnly && eigenvaluesSymmetric3x3(a, w)) {
    for(int j = 0; j < 3; j++) {
      S(j) = w[j];
      imS(j) = 0.;
    }
    return;
  }
  if(eigenSymmetric3x3(a, w, v)) {
    // Unsorted, the axes go by decreasing magnitude: an ellipse is drawn
    // from the first two, which for a plane tensor are then the ones in its
    // plane, as LAPACK happened to give them (its order is otherwise
    // arbitrary).
    int o[3] = {0, 1, 2};
    if(!sortRealPart)
      std::stable_sort(o, o + 3, [&w](int i, int j) {
        return std::abs(w[i]) > std::abs(w[j]);
      });
    for(int j = 0; j < 3; j++) {
      S(j) = w[o[j]];
      imS(j) = 0.;
      for(int k = 0; k < 3; k++) rightV(k, j) = v[k][o[j]];
    }
    return;
  }
  tensor.eig(S, imS, leftV, rightV, sortRealPart);
}

// the tensor at a node, as a matrix
static void loadTensor(fullMatrix<double> &tensor, const double *v)
{
  for(int j = 0; j < 3; j++)
    for(int k = 0; k < 3; k++) tensor(j, k) = v[k + j * 3];
}

// the box drawn for the frame of a node: its corners, as signs of the three
// axes, and its triangles, facing out
static const int frameCorners[8][3] = {{1, 1, 1},   {-1, 1, 1}, {-1, -1, 1},
                                       {1, -1, 1},  {1, 1, -1}, {-1, 1, -1},
                                       {-1, -1, -1}, {1, -1, -1}};
static const int frameTriangles[12][3] = {
  {0, 1, 2}, {2, 3, 0}, {4, 7, 6}, {6, 5, 4}, {0, 3, 7}, {7, 4, 0},
  {1, 5, 6}, {6, 2, 1}, {0, 4, 5}, {5, 1, 0}, {3, 2, 6}, {6, 7, 3}};

static void addTensorElement(drawTarget *p, int iEnt, int iEle, int numNodes,
                             int type, double **xyz, double **val, bool pre)
{
  PViewOptions *opt = p->opt;
  // a range given the other way round holds no value: nothing is drawn
  if(opt->tmpMin > opt->tmpMax) return;
  // kept from one element to the next (and one set per thread, as elements
  // are added in parallel): allocations for each element otherwise
  static thread_local fullMatrix<double> tensor(3, 3), leftV(3, 3),
    rightV(3, 3);
  static thread_local fullVector<double> S(3), imS(3);
  static thread_local nodeRows rows[3];

  if(opt->tensorType == PViewOptions::VonMises) {
    for(int i = 0; i < numNodes; i++) val[i][0] = ComputeVonMises(val[i]);
    addScalarElement(p, iEnt, iEle, numNodes, type, xyz, val, pre);
  }
  else if(opt->tensorType == PViewOptions::FrameVectors) {
    if(opt->glyphLocation == PViewOptions::Vertex) {
      // six vectors: each axis, both ways
      double **vval = rows[0].get(numNodes, 3);
      for(int i = 0; i < 3; i++) {
        for(int d = 0; d < 2; d++) {
          for(int j = 0; j < numNodes; j++)
            for(int k = 0; k < 3; k++)
              vval[j][k] = (2 * d - 1) * val[j][3 * i + k];
          addVectorElement(p, iEnt, iEle, numNodes, type, xyz, vval, pre);
        }
      }
    }
  }
  else if(opt->tensorType == PViewOptions::Frame) {
    // glyphs: nothing for the passes gathering normals or the skin
    if(pre) return;
    if(opt->glyphLocation == PViewOptions::Vertex) {
      for(int i = 0; i < numNodes; i++) {
        double nrm = sqrt(val[i][0] * val[i][0] + val[i][1] * val[i][1] +
                          val[i][2] * val[i][2]);
        if(!nrm) continue;
        if((nrm < opt->tmpMin || nrm > opt->tmpMax) && !opt->saturateValues)
          continue;
        // the axes, scaled
        double d[3][3];
        for(int a = 0; a < 3; a++)
          for(int j = 0; j < 3; j++)
            d[a][j] = opt->displacementFactor * val[i][j + a * 3] / nrm;
        double c[8][3];
        for(int k = 0; k < 8; k++)
          for(int j = 0; j < 3; j++)
            c[k][j] = xyz[i][j] + frameCorners[k][0] * d[0][j] +
                      frameCorners[k][1] * d[1][j] +
                      frameCorners[k][2] * d[2][j];
        SPoint3 xx(xyz[i][0], xyz[i][1], xyz[i][2]);
        for(int t = 0; t < 12; t++)
          addTriangle(p, opt, c[frameTriangles[t][0]], c[frameTriangles[t][1]],
                      c[frameTriangles[t][2]], xx, nrm);
      }
    }
  }
  else if(opt->tensorType == PViewOptions::Ellipse ||
          opt->tensorType == PViewOptions::Ellipsoid) {
    // glyphs: added once, by the pass filling the arrays, and not also by
    // those gathering normals or the skin (va_ellipses keeps duplicates)
    if(pre) return;
    // the center and the three axes (the eigenvectors scaled by the
    // eigenvalues), at each node or averaged over the element
    double vval[3][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    bool vertex = (opt->glyphLocation == PViewOptions::Vertex);
    if(!vertex && opt->glyphLocation != PViewOptions::COG) return;
    for(int i = 0; i < numNodes; i++) {
      loadTensor(tensor, val[i]);
      tensorEig(tensor, S, imS, leftV, rightV, false);
      for(int k = 0; k < 3; k++) {
        if(vertex) {
          vval[k][0] = xyz[i][k];
          for(int j = 0; j < 3; j++) vval[k][j + 1] = rightV(k, j) * S(j);
        }
        else {
          vval[k][0] += xyz[i][k] / numNodes;
          for(int j = 0; j < 3; j++)
            vval[k][j + 1] += rightV(k, j) * S(j) / numNodes;
        }
      }
      if(!vertex) continue;
      // coloured by the determinant at a node
      double det = S(0) * S(1) * S(2);
      unsigned int color = opt->getColor(
        det, opt->tmpMin, opt->tmpMax, false,
        (opt->intervalsType == PViewOptions::Discrete) ? opt->nbIso : -1);
      unsigned int col[4] = {color, color, color, color};
      p->va_ellipses->add(vval[0], vval[1], vval[2], nullptr, col, nullptr,
                          false);
    }
    if(!vertex) {
      // coloured by the largest of the averaged axes, which are the
      // eigenvalues of the averaged tensor: the value of the last node read
      // depended on the order its nodes came in
      double lmax = 0.;
      for(int j = 0; j < 3; j++) {
        double l = 0.;
        for(int k = 0; k < 3; k++) l += vval[k][j + 1] * vval[k][j + 1];
        lmax = std::max(lmax, sqrt(l));
      }
      unsigned int color = opt->getColor(
        lmax, opt->tmpMin, opt->tmpMax, false,
        (opt->intervalsType == PViewOptions::Discrete) ? opt->nbIso : -1);
      unsigned int col[4] = {color, color, color, color};
      p->va_ellipses->add(vval[0], vval[1], vval[2], nullptr, col, nullptr,
                          false);
    }
  }
  else {
    bool eigenVectors = (opt->tensorType == PViewOptions::EigenVectors);
    double **vval[3];
    if(eigenVectors)
      for(int k = 0; k < 3; k++) vval[k] = rows[k].get(numNodes, 3);
    for(int i = 0; i < numNodes; i++) {
      loadTensor(tensor, val[i]);
      tensorEig(tensor, S, imS, leftV, rightV, !eigenVectors, !eigenVectors);
      if(opt->tensorType == PViewOptions::MinEigenValue)
        val[i][0] = S(0);
      else if(opt->tensorType == PViewOptions::MaxEigenValue)
        val[i][0] = S(2);
      else if(eigenVectors) {
        for(int k = 0; k < 3; k++)
          for(int j = 0; j < 3; j++) vval[k][i][j] = rightV(j, k) * S(k);
      }
    }
    if(eigenVectors)
      for(int k = 0; k < 3; k++)
        addVectorElement(p, iEnt, iEle, numNodes, type, xyz, vval[k], pre);
    else
      addScalarElement(p, iEnt, iEle, numNodes, type, xyz, val, pre);
  }
}

// the same, for an element read outside the filling of the arrays
static void changeCoordinates(PView *p, int ient, int iele, int numNodes,
                              int type, int numComp, double **xyz, double **val)
{
  drawTarget t(p);
  changeCoordinates(&t, ient, iele, numNodes, type, numComp, xyz, val);
}

bool PViewElement::select(PView *p, int ient, int iele)
{
  // only written when an element cannot be drawn, to warn about it once
  static std::atomic<int> numNodesError(0), numCompError(0);
  PViewData *data = p->getData(true);
  PViewOptions *opt = p->getOptions();
  int step = opt->timeStep;
  if(data->skipElement(step, ient, iele, true, opt->sampling)) return false;
  type = data->getType(step, ient, iele);
  if(opt->skipElement(type)) return false;
  ent = ient;
  ele = iele;
  dim = data->getDimension(step, ient, iele);
  numComp = data->getNumComponents(step, ient, iele);
  numNodes = data->getNumNodes(step, ient, iele);
  // (polytopes have as many nodes as they need)
  if(numNodes > PVIEW_NMAX && type != TYPE_POLYG && type != TYPE_POLYH) {
    if(numNodesError != numNodes) {
      numNodesError = numNodes;
      Msg::Warning("Fields with %d nodes per element cannot be displayed: "
                   "either force the field type or select 'Adapt "
                   "visualization grid' if the field is high-order",
                   numNodes);
    }
    return false;
  }
  if((numComp > 9 && !opt->forceNumComponents) ||
     opt->forceNumComponents > 9) {
    if(numCompError != numComp) {
      numCompError = numComp;
      Msg::Warning("Fields with %d components cannot be displayed: "
                   "either force the field type or select 'Adapt "
                   "visualization grid' if the field is high-order",
                   numComp);
    }
    return false;
  }
  return true;
}

void PViewElement::read(PView *p, bool ids)
{
  PViewData *data = p->getData(true);
  PViewOptions *opt = p->getOptions();
  int step = opt->timeStep;
  if(_xyz.size() < 3 * (std::size_t)numNodes) {
    _xyz.resize(3 * numNodes);
    _val.resize(9 * numNodes);
  }
  _xyzRows.resize(numNodes);
  _valRows.resize(numNodes);
  for(int j = 0; j < numNodes; j++) {
    _xyzRows[j] = &_xyz[3 * j];
    _valRows[j] = &_val[9 * j];
  }
  xyz = _xyzRows.data();
  val = _valRows.data();
  if(ids) nodeIds.resize(numNodes);
  for(int j = 0; j < numNodes; j++) {
    data->getNode(step, ent, ele, j, xyz[j][0], xyz[j][1], xyz[j][2]);
    if(ids) nodeIds[j] = data->getNodeId(step, ent, ele, j);
    if(opt->forceNumComponents) {
      for(int k = 0; k < opt->forceNumComponents; k++) {
        int comp = opt->componentMap[k];
        if(comp >= 0 && comp < numComp)
          data->getValue(step, ent, ele, j, comp, val[j][k]);
        else
          val[j][k] = 0.;
      }
    }
    else
      for(int k = 0; k < numComp; k++)
        data->getValue(step, ent, ele, j, k, val[j][k]);
  }
  if(opt->forceNumComponents) numComp = opt->forceNumComponents;
  changeCoordinates(p, ent, ele, numNodes, type, numComp, xyz, val);
}

// an element drawn as the field its values are: scalar, vector or tensor
static void addFieldElement(drawTarget *p, int ient, int iele, int numNodes,
                            int type, int numComp, double **xyz, double **val,
                            bool pre)
{
  PViewOptions *opt = p->opt;
  if(numComp == 1 && opt->drawScalars)
    addScalarElement(p, ient, iele, numNodes, type, xyz, val, pre);
  else if(numComp == 3 && opt->drawVectors)
    addVectorElement(p, ient, iele, numNodes, type, xyz, val, pre);
  else if(numComp == 9 && opt->drawTensors)
    addTensorElement(p, ient, iele, numNodes, type, xyz, val, pre);
}

// fill the arrays of one target with the elements numbered [first, last) in the
// flat index space built by addElementsInArrays below
static void addElementRange(drawTarget *p, PViewData *data,
                            bool preprocessNormalsOnly,
                            const std::vector<int> &ents,
                            const std::vector<std::size_t> &start,
                            std::size_t first, std::size_t last,
                            const elementSpheres *spheres)
{
  PViewOptions *opt = p->opt;
  PViewElement el;
  const std::vector<std::uint8_t> *masks = activeSkinMasks;
  const bool facesOnSkin = skinOnly(opt);
  activePlanes planes(opt->clip);
  bool onlyVolume = CTX::instance()->clipOnlyVolume;
  // what the planes add is looked for among the elements they may cut
  bool nearPlanes = spheres && planes.num() &&
                    (p->collect == drawTarget::COLLECT_CAPS ||
                     p->collect == drawTarget::COLLECT_CUT);
  // elements are told apart by their nodes (shared edges drawn once, the
  // skin) unless their coordinates are changed element by element: exploded
  // or raised along their normal, they no longer meet at their nodes
  bool topology = opt->explode == 1. && !opt->normalRaise && !opt->useGenRaise;

  // the entity the range starts in
  std::size_t e = 0;
  while(e + 1 < ents.size() && start[e + 1] <= first) e++;
  for(; e < ents.size() && start[e] < last; e++) {
    int ent = ents[e];
    p->ent = ent;
    int i0 = (int)(first > start[e] ? first - start[e] : 0);
    int i1 = (int)std::min(last, start[e + 1]) - (int)start[e];
    for(int i = i0; i < i1; i++) {
      std::size_t flat = start[e] + i;
      if(nearPlanes) {
        if(!spheres->drawn(flat)) continue;
        const float *sp = spheres->sphere(flat);
        int d = spheres->dim(flat);
        if(p->collect == drawTarget::COLLECT_CAPS) {
          if(d < 3 || planes.gap(sp) > 0.) continue;
        }
        else if(!(d < 3 && onlyVolume) && planes.gap(sp) > 0.)
          continue;
      }
      p->skinMask = -1;
      if(masks) {
        std::uint8_t m = (*masks)[flat];
        // inside the field: nothing to draw, unless all the faces or all
        // the outlines are
        if(m == 0x80 && facesOnSkin && (!opt->showElement || skinOutlines(opt)))
          continue;
        if(m & 0x80) p->skinMask = m & 0x3f;
      }
      if(!el.select(p->view, ent, i)) continue;
      if(p->skinMask >= 0) {
        int sh = solidShapeIndex(el.type);
        if(sh < 0)
          p->skinMask = -1;
        else
          p->skinShape = solidShapes[sh];
      }
      el.read(p->view, true);
      p->nodeIds = topology ? el.nodeIds.data() : nullptr;
      int type = el.type, dim = el.dim, numNodes = el.numNodes;
      int numComp = el.numComp;
      double **xyz = el.xyz, **val = el.val;
      // the cut pass wants the cut elements only, the ordinary fill the rest
      if(p->collect == drawTarget::COLLECT_CUT) {
        if(!elementIsCut(opt, dim, numNodes, xyz)) continue;
      }
      else if(p->collect == drawTarget::COLLECT_KEPT) {
        if(!elementIsKept(opt, dim, numNodes, xyz)) continue;
      }
      else if(!isElementVisible(opt, dim, numNodes, xyz))
        continue;
      // the caps pass wants 3D elements only, and no outlines
      if(p->collect == drawTarget::COLLECT_CAPS && dim < 3) continue;

      for(int j = 0; j < numNodes; j++)
        p->bbox += SPoint3(xyz[j][0], xyz[j][1], xyz[j][2]);

      // an element drawn whole is outlined whole
      if(opt->showElement && !data->useGaussPoints() &&
         (p->collect == drawTarget::COLLECT_ALL ||
          p->collect == drawTarget::COLLECT_CUT))
        addOutlineElement(p, ent, i, numNodes, type, xyz,
                          preprocessNormalsOnly);

      if(opt->intervalsType != PViewOptions::Numeric) {
        if(data->useGaussPoints()) {
          // a point at each Gauss point, with a copy of its values (a tensor
          // field changes them)
          for(int j = 0; j < numNodes; j++) {
            double x2[3] = {xyz[j][0], xyz[j][1], xyz[j][2]}, v2[9];
            for(int k = 0; k < numComp; k++) v2[k] = val[j][k];
            double *px = x2, *pv = v2;
            addFieldElement(p, ent, i, 1, TYPE_PNT, numComp, &px, &pv,
                            preprocessNormalsOnly);
          }
        }
        else
          addFieldElement(p, ent, i, numNodes, type, numComp, xyz, val,
                          preprocessNormalsOnly);
      }
    }
  }
  p->nodeIds = nullptr;
  p->skinMask = -1;
}

// what each view's clip arrays were last built for: only what changes them
// without marking the view as changed (the planes and the clipping options;
// capping marks the mesh, which only reaches model-based views); everything
// else marks the view as changed, and drawPost() then invalidates them
static OwnerCache<std::vector<double> > _viewClipToken;

static std::vector<double> viewClipToken(PView *p)
{
  CTX *ctx = CTX::instance();
  PViewOptions *opt = p->getOptions();
  std::vector<double> t;
  t.push_back(opt->clip);
  ctx->addClipToKey(t);
  return t;
}

void PView::invalidateClipVertexArrays() { _viewClipToken.erase(this); }

// walk the elements and draw them into vertex arrays: the view's own, or
// for the passes building what the clipping planes add, a subset of the
// elements into the two arrays given (everything else those passes produce
// is thrown away)
static void addElementsInArrays(PView *p, bool preprocessNormalsOnly,
                                int collect = drawTarget::COLLECT_ALL,
                                VertexArray *vaL = nullptr,
                                VertexArray *vaT = nullptr,
                                smooth_normals *normals = nullptr,
                                const elementSpheres *spheres = nullptr)
{
  // use adaptive data if available
  PViewData *data = p->getData(true);
  PViewOptions *opt = p->getOptions();
  bool own = (collect == drawTarget::COLLECT_ALL);

  if(own) opt->tmpBBox.reset();

  flatElements flat(data, opt);
  const std::vector<int> &ents = flat.ents;
  const std::vector<std::size_t> &start = flat.start;
  std::size_t num = flat.num;
  if(!num) return;

  int nthreads = numWalkThreads(data, opt, num);

  if(nthreads == 1) {
    drawTarget t(p);
    VertexArray points(1, 100), vectors(2, 100), ellipses(4, 100);
    if(!own) {
      t.collect = collect;
      t.va_lines = vaL;
      t.va_triangles = vaT;
      t.va_points = &points;
      t.va_vectors = &vectors;
      t.va_ellipses = &ellipses;
      if(normals) t.normals = normals;
    }
    addElementRange(&t, data, preprocessNormalsOnly, ents, start, 0, num,
                    spheres);
    if(own && !t.bbox.empty()) opt->tmpBBox += t.bbox;
    return;
  }

  // each thread fills its own arrays with its own copy of the options,
  // merged in thread order below
  std::vector<drawTarget *> targets(nthreads, nullptr);
  std::vector<PViewOptions *> opts(nthreads, nullptr);
  int n = (int)(num / nthreads) + 100;
  for(int t = 0; t < nthreads; t++) {
    drawTarget *d = new drawTarget(p);
    opts[t] = new PViewOptions(*opt);
    // the copy must not delete the shared general raise evaluator
    opts[t]->genRaiseEvaluator = nullptr;
    d->opt = opts[t];
    d->collect = collect;
    if(normals) d->normals = normals;
    // the threads share the filters of the arrays being filled, so that an
    // element is dropped whichever thread sees it first
    d->va_points = new VertexArray(1, n / 4);
    d->va_lines = new VertexArray(2, n / 4);
    d->va_lines->setUniqueFilter((own ? p->va_lines : vaL)->getUniqueFilter(true));
    d->va_triangles = new VertexArray(3, 4 * n);
    d->va_triangles->setUniqueFilter(
      (own ? p->va_triangles : vaT)->getUniqueFilter(true));
    d->va_vectors = new VertexArray(2, n / 4);
    if(own)
      d->va_vectors->setUniqueFilter(p->va_vectors->getUniqueFilter(true));
    d->va_ellipses = new VertexArray(4, n / 4);
    targets[t] = d;
  }
  if(boundaryFaces) boundaryFaces->setThreaded();

#pragma omp parallel for schedule(static, 1) num_threads(nthreads)
  for(int t = 0; t < nthreads; t++)
    addElementRange(targets[t], data, preprocessNormalsOnly, ents, start,
                    num * t / nthreads, num * (t + 1) / nthreads, spheres);

  for(int t = 0; t < nthreads; t++) {
    if(own) {
      p->va_points->merge(targets[t]->va_points);
      p->va_lines->merge(targets[t]->va_lines);
      p->va_triangles->merge(targets[t]->va_triangles);
      p->va_vectors->merge(targets[t]->va_vectors);
      p->va_ellipses->merge(targets[t]->va_ellipses);
      // adding an empty box would stretch the bounding box to infinity
      if(!targets[t]->bbox.empty()) opt->tmpBBox += targets[t]->bbox;
    }
    else {
      vaL->merge(targets[t]->va_lines);
      vaT->merge(targets[t]->va_triangles);
    }
    delete targets[t]->va_points;
    delete targets[t]->va_lines;
    delete targets[t]->va_triangles;
    delete targets[t]->va_vectors;
    delete targets[t]->va_ellipses;
    delete targets[t];
    delete opts[t];
  }
}
class initPView {
private:
  // we try to estimate how many primitives will end up in the vertex
  // arrays, since reallocating the arrays takes a huge amount of time
  // on Windows/Cygwin
  std::size_t _estimateIfClipped(PView *p, std::size_t num)
  {
    if(CTX::instance()->clipWholeElements &&
       CTX::instance()->clipOnlyDrawIntersectingVolume) {
      PViewOptions *opt = p->getOptions();
      for(int clip = 0; clip < 6; clip++) {
        if(opt->clip & (1 << clip)) return (std::size_t)sqrt((double)num);
      }
    }
    return num;
  }
  // How much to reserve for an array: what the data holds of that kind, what
  // the planes are likely to leave of it when they are applied here, and room
  // to spare. Only a starting size: an array grows if it has to.
  // (on 64 bits: six triangles for each of 400 million tetrahedra do not fit
  // in an int)
  std::size_t _estimate(PView *p, std::size_t count, bool clipped,
                        std::size_t spare)
  {
    return (clipped ? _estimateIfClipped(p, count) : count) + spare;
  }
  std::size_t _estimateNumPoints(PView *p)
  {
    return _estimate(p, p->getData(true)->getNumPoints(p->getOptions()->timeStep),
                     false, 10000);
  }
  std::size_t _estimateNumLines(PView *p)
  {
    return _estimate(p, p->getData(true)->getNumLines(p->getOptions()->timeStep),
                     false, 10000);
  }
  std::size_t _estimateNumTriangles(PView *p)
  {
    PViewData *data = p->getData(true);
    PViewOptions *opt = p->getOptions();
    std::size_t tris = data->getNumTriangles(opt->timeStep);
    std::size_t quads = data->getNumQuadrangles(opt->timeStep);
    std::size_t polygs = data->getNumPolygons(opt->timeStep);
    std::size_t tets = data->getNumTetrahedra(opt->timeStep);
    std::size_t prisms = data->getNumPrisms(opt->timeStep);
    std::size_t pyrs = data->getNumPyramids(opt->timeStep);
    std::size_t trihs = data->getNumTrihedra(opt->timeStep);
    std::size_t hexas = data->getNumHexahedra(opt->timeStep);
    std::size_t polyhs = data->getNumPolyhedra(opt->timeStep);
    std::size_t heuristic = 0;
    // the faces on the skin alone: about the 2/3 power of the 3D elements
    if(skinOnly(opt)) {
      double solids = (double)(tets + prisms + pyrs + hexas + polyhs);
      heuristic = tris + 2 * quads + 3 * polygs +
                  (std::size_t)(12. * pow(solids, 2. / 3.));
      return _estimate(p, heuristic, true, 10000);
    }
    if(opt->intervalsType == PViewOptions::Iso)
      heuristic = (tets + prisms + pyrs + hexas + polyhs) / 10;
    else if(opt->intervalsType == PViewOptions::Continuous)
      heuristic = (tris + 2 * quads + 3 * polygs + 6 * tets + 8 * prisms +
                   6 * pyrs + 2 * trihs + 12 * hexas + 10 * polyhs);
    else if(opt->intervalsType == PViewOptions::Discrete)
      heuristic = (tris + 2 * quads + 3 * polygs + 6 * tets + 8 * prisms +
                   6 * pyrs + 2 * trihs + 12 * hexas + 10 * polyhs) *
                  2;
    return _estimate(p, heuristic, true, 10000);
  }
  std::size_t _estimateNumVectors(PView *p)
  {
    return _estimate(p, p->getData(true)->getNumVectors(p->getOptions()->timeStep),
                     true, 1000);
  }
  std::size_t _estimateNumEllipses(PView *p)
  {
    return _estimate(p, p->getData(true)->getNumTensors(p->getOptions()->timeStep),
                     true, 1000);
  }

public:
  bool operator()(PView *p)
  {
    // use adaptive data if available
    PViewData *data = p->getData(true);
    PViewOptions *opt = p->getOptions();

    if(data->getDirty() || !data->getNumTimeSteps() || !p->getChanged())
      return false;
    if(!opt->visible || opt->type != PViewOptions::Plot3D) return false;

    p->deleteVertexArrays();

    if(data->isRemote()) {
      // FIXME: need to rewrite option code and add nice serialization
      std::string fileName =
        CTX::instance()->homeDir + CTX::instance()->tmpFileName;
      PrintOptions(0, GMSH_FULLRC, 0, 0, fileName.c_str());
      std::string options = ConvertFileToString(fileName);
      data->fillRemoteVertexArrays(options);
      return false;
    }

    if(opt->useGenRaise) opt->createGeneralRaise();

    // (not perfect for multi-step adaptive views, which do not know the
    // range of the other steps)
    opt->getRange(data, opt->tmpMin, opt->tmpMax);

    p->va_points = new VertexArray(1, _estimateNumPoints(p));
    p->va_lines = new VertexArray(2, _estimateNumLines(p));
    p->va_triangles = new VertexArray(3, _estimateNumTriangles(p));
    p->va_vectors = new VertexArray(2, _estimateNumVectors(p));
    p->va_ellipses = new VertexArray(4, _estimateNumEllipses(p));

    if(p->normals) delete p->normals;

    p->normals = new smooth_normals(opt->angleSmoothNormals);

    // the spheres around the elements are those of the view as it was
    _viewSpheres.erase(p);

    bool skinFound = false;
    if((skinOnly(opt) && viewDrawsFaces(p)) || skinOutlines(opt)) {
      // the skin from the nodes of the elements alone, if it can be
      const std::vector<std::uint8_t> *masks =
        getSkin(p, data, opt, flatElements(data, opt));
      if(masks) {
        skinFound = true;
        activeSkinMasks = masks;
      }
    }

    if(!skinFound && opt->drawSkinOnly && viewDrawsFaces(p)) {
      // first pass: locate the faces that bound the mesh
      double t1 = TimeOfDay();
      delete boundaryFaces;
      boundaryFaces = new UniqueElementFilter(false);
      markingBoundaryFaces = true;
      addElementsInArrays(p, true);
      markingBoundaryFaces = false;
      // that pass may have fed the smooth normals: start over
      delete p->normals;
      p->normals = new smooth_normals(opt->angleSmoothNormals);
      Msg::Debug("Located the boundary faces of View[%d] in %g s",
                 p->getIndex(), TimeOfDay() - t1);
    }

    if(opt->smoothNormals) addElementsInArrays(p, true);
    addElementsInArrays(p, false);

    delete boundaryFaces;
    boundaryFaces = nullptr;
    activeSkinMasks = nullptr;
    std::vector<std::uint8_t>().swap(skinMasks);

    p->va_points->finalize();
    p->va_lines->finalize();
    p->va_triangles->finalize();
    p->va_vectors->finalize();
    p->va_ellipses->finalize();

    Msg::Debug(
      "%d vertices in vertex arrays (%g MB)",
      p->va_points->getNumVertices() + p->va_lines->getNumVertices() +
        p->va_triangles->getNumVertices() + p->va_vectors->getNumVertices() +
        p->va_ellipses->getNumVertices(),
      p->va_points->getMemoryInMB() + p->va_lines->getMemoryInMB() +
        p->va_triangles->getMemoryInMB() + p->va_vectors->getMemoryInMB() +
        p->va_ellipses->getMemoryInMB());

    VertexArray::printStats();

    p->setChanged(false);
    return true;
  }
};

bool PView::fillClipVertexArrays()
{
  PViewOptions *o = getOptions();
  // a view that is not drawn builds nothing: what it holds is dropped, and
  // built again when it is shown (every plane moved walked every view)
  if(!o->visible || o->type != PViewOptions::Plot3D) {
    if(_viewClipToken.find(this)) {
      deleteClipVertexArrays();
      _viewClipToken.erase(this);
    }
    return false;
  }

  std::vector<double> tok = viewClipToken(this);
  std::vector<double> *found = _viewClipToken.find(this);
  if(found && *found == tok) return false;
  _viewClipToken[this] = tok;

  deleteClipVertexArrays();
  PViewOptions *opt = getOptions();
  CTX *ctx = CTX::instance();
  bool caps = opt->clip && ctx->clipCapping && !ctx->clipWholeElements;
  // the mode drawing only the cut volumes has nothing to hold apart
  bool whole = opt->clip && ctx->clipWholeElements &&
               !ctx->clipOnlyDrawIntersectingVolume;
  if(!caps && !whole) return true;

  PViewData *data = getData(true);
  if(!data || data->getDirty() || !data->getNumTimeSteps()) return true;

  double t1 = TimeOfDay();
  va_clip_lines = new VertexArray(2, 100);
  va_clip_triangles = new VertexArray(3, 1000);

  // the elements the planes may cut, without reading the others
  flatElements flat(data, opt);
  const elementSpheres *spheres = getSpheres(this, flat);

  bool skinFound = false;
  if(whole && ((skinOnly(opt) && viewDrawsFaces(this)) || skinOutlines(opt))) {
    skinFound = findSkin(this, flat, true, spheres,
                         spheres ? getSkin(this, data, opt, flat) : nullptr);
    if(skinFound) activeSkinMasks = &skinMasks;
  }

  if(whole && opt->drawSkinOnly && !skinFound) {
    // the skin of what whole element mode keeps, which differs from the
    // skin of the whole field
    delete boundaryFaces;
    boundaryFaces = new UniqueElementFilter(false);
    markingBoundaryFaces = true;
    // this pass feeds the smoothed normals, which are built already
    smooth_normals scratch(opt->angleSmoothNormals);
    addElementsInArrays(this, true, drawTarget::COLLECT_KEPT, va_clip_lines,
                        va_clip_triangles, &scratch);
    markingBoundaryFaces = false;
  }
  // the same walk as for the view's own arrays, into the clip arrays
  addElementsInArrays(this, false,
                      whole ? drawTarget::COLLECT_CUT :
                              drawTarget::COLLECT_CAPS,
                      va_clip_lines, va_clip_triangles, nullptr, spheres);
  delete boundaryFaces;
  boundaryFaces = nullptr;
  activeSkinMasks = nullptr;
  std::vector<std::uint8_t>().swap(skinMasks);

  va_clip_lines->finalize();
  va_clip_triangles->finalize();
  if(va_clip_lines->getNumVertices() || va_clip_triangles->getNumVertices())
    Msg::Debug("View[%d] %s: %d lines, %d triangles in %g s", getIndex(),
               whole ? "cut elements" : "section",
               va_clip_lines->getNumVertices(),
               va_clip_triangles->getNumVertices(), TimeOfDay() - t1);
  return true;
}

// The arrays of a view are built by walking its elements once (twice for
// smoothed normals, and once more to find the skin), each element turned into
// points, lines and triangles coloured from the colour table, or into
// vectors and ellipses for the glyphs, according to the options of the view.
// They are only built again when setChanged() says the view has changed.
bool PView::fillVertexArrays()
{
  initPView init;
  return init(this);
}

void PView::fillVertexArray(onelab::localNetworkClient *remote, int length,
                            const char *bytes, int swap)
{
  std::string name;
  int tag, type, numSteps;
  double min, max, time, xmin, ymin, zmin, xmax, ymax, zmax;
  if(!VertexArray::decodeHeader(length, bytes, swap, name, tag, type, min, max,
                                numSteps, time, xmin, ymin, zmin, xmax, ymax,
                                zmax))
    return;

  Msg::Debug("Filling vertex array (type %d) in view tag %d", type, tag);

  SBoundingBox3d bbox(xmin, ymin, zmin, xmax, ymax, zmax);

  PView *p = PView::getViewByTag(tag);
  if(!p) {
    Msg::Info("View tag %d does not exist: creating new view", tag);
    PViewData *data =
      new PViewDataRemote(remote, min, max, numSteps, time, bbox);
    data->setName(name + " (remote)");
    p = new PView(data, tag);
    SetBoundingBox();
  }
  else {
    PViewDataRemote *data = dynamic_cast<PViewDataRemote *>(p->getData());
    if(data) {
      data->setMin(min);
      data->setMax(max);
      data->setTime(time);
      data->setBoundingBox(bbox);
    }
  }
  // not perfect (does not take transformations into account)
  p->getOptions()->tmpBBox = bbox;

  // the glyphs of this view were expanded from the arrays being replaced
  OwnerCacheBase::release(p);

  switch(type) {
  case 1:
    if(p->va_points) delete p->va_points;
    p->va_points = new VertexArray(1, 100);
    p->va_points->fromChar(length, bytes, swap);
    break;
  case 2:
    if(p->va_lines) delete p->va_lines;
    p->va_lines = new VertexArray(2, 100);
    p->va_lines->fromChar(length, bytes, swap);
    break;
  case 3:
    if(p->va_triangles) delete p->va_triangles;
    p->va_triangles = new VertexArray(3, 100);
    p->va_triangles->fromChar(length, bytes, swap);
    break;
  case 4:
    if(p->va_vectors) delete p->va_vectors;
    p->va_vectors = new VertexArray(2, 100);
    p->va_vectors->fromChar(length, bytes, swap);
    break;
  case 5:
    if(p->va_ellipses) delete p->va_ellipses;
    p->va_ellipses = new VertexArray(4, 100);
    p->va_ellipses->fromChar(length, bytes, swap);
    break;
  default: Msg::Error("Cannot fill vertex array of type %d", type); return;
  }

  p->setChanged(false);
  p->getData()->setDirty(false);
}
