// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <sstream>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "GFace.h"
#include "GEdge.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MElementCut.h"
#include "VertexArray.h"
#include "fullMatrix.h"
#include "Numeric.h"
#include "GaussLegendre1D.h"
#include "Context.h"
#include "OS.h"
#include "discreteEdge.h"
#include "discreteFace.h"
#include "ExtrudeParams.h"

#if defined(HAVE_MESH)
#include "meshGFace.h"
#include "meshGFaceOptimize.h"
#include "BackgroundMeshTools.h"
#include "meshGFaceBipartiteLabelling.h"
#include "Field.h"
#endif

#if defined(HAVE_ALGLIB)
#include <stdafx.h>
#include <optimization.h>
#endif

#if defined(HAVE_QUADMESHINGTOOLS)
#include "cppUtils.h"
#include "qmtMeshUtils.h"
#include "qmtCrossField.h"
#endif

GFace::GFace(GModel *model, int tag)
  : GEntity(model, tag), r1(nullptr), r2(nullptr), va_geom_triangles(nullptr),
    compoundSurface(nullptr)
{
  meshStatistics.status = GFace::PENDING;
  meshStatistics.refineAllEdges = false;
  GFace::resetMeshAttributes();
}

GFace::~GFace()
{
  for(auto ge : l_edges) ge->delFace(this);

  if(va_geom_triangles) delete va_geom_triangles;

  GFace::deleteMesh();
}

int GFace::getMeshingAlgo() const
{
  if(meshAttributes.algorithm)
    return meshAttributes.algorithm;
  else
    return CTX::instance()->mesh.algo2d;
}

int GFace::getMeshSizeFromBoundary() const
{
  if(meshAttributes.meshSizeFromBoundary >= 0)
    return meshAttributes.meshSizeFromBoundary;
  else
    return CTX::instance()->mesh.lcExtendFromBoundary;
}

bool GFace::isOrphan()
{
  if(model()->getNumRegions())
    return regions().empty();
  return false;
}

int GFace::delEdge(GEdge *edge)
{
  const auto found = std::find(l_edges.begin(), l_edges.end(), edge);

  if(found != l_edges.end()) { l_edges.erase(found); }

  const auto pos = std::distance(l_edges.begin(), found);

  if(l_dirs.empty()) { return 0; }

  if(l_dirs.size() < static_cast<std::size_t>(pos)) {
    l_dirs.erase(std::prev(l_dirs.end()));
    return 0;
  }

  const auto orientation = l_dirs.at(pos);
  l_dirs.erase(std::next(begin(l_dirs), pos));
  return orientation;
}

void GFace::setBoundEdges(const std::vector<int> &tagEdges)
{
  std::vector<GEdge *> e;
  for(std::size_t i = 0; i < tagEdges.size(); i++) {
    GEdge *ge = model()->getEdgeByTag(tagEdges[i]);
    if(ge) {
      e.push_back(ge);
      ge->addFace(this);
    }
    else {
      Msg::Error("Unknown curve %d in surface %d", tagEdges[i], tag());
    }
  }
  GEdgeLoop el(e);
  el.getEdges(l_edges);
  el.getSigns(l_dirs);
}

void GFace::setBoundEdges(const std::vector<int> &tagEdges,
                          const std::vector<int> &signEdges)
{
  if(signEdges.size() != tagEdges.size()) {
    Msg::Error("Wrong number of curve signs in surface %d", tag());
    setBoundEdges(tagEdges);
  }
  for(std::vector<int>::size_type i = 0; i < tagEdges.size(); i++) {
    GEdge *ge = model()->getEdgeByTag(tagEdges[i]);
    if(ge) {
      if(std::find(l_edges.begin(), l_edges.end(), ge) == l_edges.end()) {
        l_edges.push_back(ge);
        l_dirs.push_back(signEdges[i]);
        ge->addFace(this);
      }
    }
    else {
      Msg::Error("Unknown curve %d in surface %d", tagEdges[i], tag());
    }
  }
}

void GFace::deleteMesh()
{
  for(std::size_t i = 0; i < mesh_vertices.size(); i++) delete mesh_vertices[i];
  mesh_vertices.clear();
  transfinite_vertices.clear();
  removeElements(true);
  correspondingVertices.clear();
  correspondingHighOrderVertices.clear();
  deleteVertexArrays();
  model()->destroyMeshCaches();
}

void GFace::deleteGeometryVertexArrays()
{
  if(!va_geom_triangles) return;
  delete va_geom_triangles;
  va_geom_triangles = nullptr;
}

std::size_t GFace::getNumMeshElements() const
{
  return triangles.size() + quadrangles.size() + polygons.size();
}

std::size_t GFace::getNumMeshElementsByType(const int familyType) const
{
  if(familyType == TYPE_TRI)
    return triangles.size();
  else if(familyType == TYPE_QUA)
    return quadrangles.size();
  else if(familyType == TYPE_POLYG)
    return polygons.size();

  return 0;
}

std::size_t GFace::getNumMeshParentElements()
{
  std::size_t n = 0;
  for(std::size_t i = 0; i < polygons.size(); i++)
    if(polygons[i]->ownsParent()) n++;
  return n;
}

void GFace::getNumMeshElements(unsigned *const c) const
{
  c[0] += triangles.size();
  c[1] += quadrangles.size();
  c[2] += polygons.size();
}

MElement *const *GFace::getStartElementType(int type) const
{
  switch(type) {
  case 0:
    if(triangles.empty()) return nullptr; // msvc would throw an exception
    return reinterpret_cast<MElement *const *>(&triangles[0]);
  case 1:
    if(quadrangles.empty()) return nullptr; // msvc would throw an exception
    return reinterpret_cast<MElement *const *>(&quadrangles[0]);
  case 2:
    if(polygons.empty()) return nullptr;
    return reinterpret_cast<MElement *const *>(&polygons[0]);
  }
  return nullptr;
}

MElement *GFace::getMeshElement(std::size_t index) const
{
  if(index < triangles.size())
    return triangles[index];
  else if(index < triangles.size() + quadrangles.size())
    return quadrangles[index - triangles.size()];
  else if(index < triangles.size() + quadrangles.size() + polygons.size())
    return polygons[index - triangles.size() - quadrangles.size()];
  return nullptr;
}

MElement *GFace::getMeshElementByType(const int familyType,
                                      const std::size_t index) const
{
  if(familyType == TYPE_TRI)
    return triangles[index];
  else if(familyType == TYPE_QUA)
    return quadrangles[index];
  else if(familyType == TYPE_POLYG)
    return polygons[index];

  return nullptr;
}

void GFace::resetMeshAttributes()
{
  meshAttributes.recombine = 0;
  meshAttributes.recombineAngle = 45.;
  meshAttributes.method = MESH_UNSTRUCTURED;
  meshAttributes.transfiniteArrangement = 0;
  meshAttributes.transfiniteSmoothing = -1;
  meshAttributes.extrude = nullptr;
  meshAttributes.reverseMesh = false;
  meshAttributes.meshSize = MAX_LC;
  meshAttributes.meshSizeFactor = 1.;
  meshAttributes.algorithm = 0;
  meshAttributes.meshSizeFromBoundary = -1;
  meshAttributes.transfinite3 = false;
}

SBoundingBox3d GFace::bounds(bool fast)
{
  SBoundingBox3d res;
  if(geomType() != DiscreteSurface && geomType() != BoundaryLayerSurface &&
     geomType() != PartitionSurface) {
    for(auto ge : l_edges) {
      res += ge->bounds(fast);
    }
  }
  else {
    for(std::size_t i = 0; i < getNumMeshElements(); i++)
      for(std::size_t j = 0; j < getMeshElement(i)->getNumVertices(); j++)
        res += getMeshElement(i)->getVertex(j)->point();
  }
  return res;
}

SOrientedBoundingBox GFace::getOBB()
{
  if(!_obb) {
    std::vector<SPoint3> vertices;
    if(getNumMeshVertices() > 0) {
      int N = getNumMeshVertices();
      for(int i = 0; i < N; i++) {
        MVertex *mv = getMeshVertex(i);
        vertices.push_back(mv->point());
      }
      std::vector<GEdge *> const &eds = edges();
      for(auto ed = eds.begin(); ed != eds.end(); ed++) {
        int N2 = (*ed)->getNumMeshVertices();
        for(int i = 0; i < N2; i++) {
          MVertex *mv = (*ed)->getMeshVertex(i);
          vertices.push_back(mv->point());
        }
        // Don't forget to add the first and last vertices...
        if((*ed)->getBeginVertex()) {
          SPoint3 pt1((*ed)->getBeginVertex()->x(),
                      (*ed)->getBeginVertex()->y(),
                      (*ed)->getBeginVertex()->z());
          vertices.push_back(pt1);
        }
        if((*ed)->getEndVertex()) {
          SPoint3 pt2((*ed)->getEndVertex()->x(), (*ed)->getEndVertex()->y(),
                      (*ed)->getEndVertex()->z());
          vertices.push_back(pt2);
        }
      }
    }
    else if(buildSTLTriangulation()) {
      vertices = stl_vertices_xyz;
    }
    else {
      // Fallback, if we can't make a STL triangulation of the surface, use its
      // edges..
      std::vector<GEdge *> const &b_edges = edges();
      int N = 10;
      for(auto b_edge = b_edges.begin(); b_edge != b_edges.end(); b_edge++) {
        Range<double> tr = (*b_edge)->parBounds(0);
        for(int j = 0; j < N; j++) {
          double t =
            tr.low() + (double)j / (double)(N - 1) * (tr.high() - tr.low());
          GPoint p = (*b_edge)->point(t);
          SPoint3 pt(p.x(), p.y(), p.z());
          vertices.push_back(pt);
        }
      }
    }
    _obb = SOrientedBoundingBox::buildOBB(vertices);
  }
  return SOrientedBoundingBox(_obb);
}

std::vector<GVertex *> GFace::getEmbeddedVertices(bool force) const
{
  if(!force && compound.size()) return std::vector<GVertex *>();
  return std::vector<GVertex *>(embedded_vertices.begin(),
                                embedded_vertices.end());
}

std::vector<GEdge *> GFace::getEmbeddedEdges(bool force) const
{
  if(!force && compound.size()) return std::vector<GEdge *>();
  return embedded_edges;
}

std::vector<MVertex *> GFace::getEmbeddedMeshVertices(bool force) const
{
  if(!force && compound.size()) return std::vector<MVertex *>();

  std::set<MVertex *> tmp;
  for(auto it = embedded_edges.begin(); it != embedded_edges.end(); it++) {
    tmp.insert((*it)->mesh_vertices.begin(), (*it)->mesh_vertices.end());
    if((*it)->getBeginVertex())
      tmp.insert((*it)->getBeginVertex()->mesh_vertices.begin(),
                 (*it)->getBeginVertex()->mesh_vertices.end());
    if((*it)->getEndVertex())
      tmp.insert((*it)->getEndVertex()->mesh_vertices.begin(),
                 (*it)->getEndVertex()->mesh_vertices.end());
  }
  for(auto it = embedded_vertices.begin(); it != embedded_vertices.end();
      it++) {
    tmp.insert((*it)->mesh_vertices.begin(), (*it)->mesh_vertices.end());
  }
  return std::vector<MVertex *>(tmp.begin(), tmp.end());
}

std::vector<GVertex *> GFace::vertices() const
{
  std::set<GVertex *, GEntityPtrLessThan> v;
  for(auto ge : l_edges) {
    GVertex *const v1 = ge->getBeginVertex();
    if(v1) v.insert(v1);

    GVertex *const v2 = ge->getEndVertex();
    if(v2) v.insert(v2);
  }
  return std::vector<GVertex *>(v.begin(), v.end());
}

void GFace::setVisibility(char val, bool recursive)
{
  GEntity::setVisibility(val);
  if(recursive) {
    for(auto e : l_edges) e->setVisibility(val, recursive);
    for(auto e : embedded_edges) e->setVisibility(val, recursive);
    for(auto v : embedded_vertices) v->setVisibility(val);
  }
}

void GFace::setColor(unsigned int val, bool recursive)
{
  deleteGeometryVertexArrays();
  GEntity::setColor(val);
  if(recursive) {
    for(auto e : l_edges) e->setColor(val, recursive);
    for(auto e : embedded_edges) e->setColor(val, recursive);
    for(auto v : embedded_vertices) v->setColor(val);
  }
}

std::string GFace::getAdditionalInfoString(bool multline)
{
  std::ostringstream sstream;
  if(l_edges.size() > 20) {
    sstream << "Boundary curves: " << l_edges.front()->tag() << ", ...,"
            << l_edges.back()->tag();
    if(multline)
      sstream << "\n";
    else
      sstream << " ";
  }
  else if(l_edges.size()) {
    sstream << "Boundary curves: ";
    for(auto it = l_edges.begin(); it != l_edges.end(); ++it) {
      if(it != l_edges.begin()) sstream << ", ";
      sstream << (*it)->tag();
    }
    if(multline)
      sstream << "\n";
    else
      sstream << " ";
  }

  if(r1 || r2) {
    sstream << "On boundary of volumes: ";
    if(r1) {
      sstream << r1->tag();
      if(r2) sstream << ", ";
    }
    if(r2) sstream << r2->tag();
    if(multline)
      sstream << "\n";
    else
      sstream << " ";
  }

  if(embedded_edges.size()) {
    sstream << "Embedded curves: ";
    for(auto it = embedded_edges.begin(); it != embedded_edges.end(); ++it) {
      if(it != embedded_edges.begin()) sstream << ", ";
      sstream << (*it)->tag();
    }
    if(multline)
      sstream << "\n";
    else
      sstream << " ";
  }

  if(embedded_vertices.size()) {
    sstream << "Embedded points: ";
    for(auto it = embedded_vertices.begin(); it != embedded_vertices.end();
        ++it) {
      if(it != embedded_vertices.begin()) sstream << ", ";
      sstream << (*it)->tag();
    }
    if(multline)
      sstream << "\n";
    else
      sstream << " ";
  }

  if(meshAttributes.recombine || meshAttributes.method == MESH_TRANSFINITE ||
     (meshAttributes.extrude && meshAttributes.extrude->mesh.ExtrudeMesh) ||
     meshAttributes.reverseMesh ||
     (getMeshMaster() && getMeshMaster() != this)) {
    sstream << "Mesh attributes:";
    if(meshAttributes.recombine) sstream << " recombined";
    if(meshAttributes.method == MESH_TRANSFINITE) sstream << " transfinite";
    if(meshAttributes.extrude && meshAttributes.extrude->mesh.ExtrudeMesh)
      sstream << " extruded";
    if(meshAttributes.reverseMesh) sstream << " reverse";
    if(getMeshMaster() && getMeshMaster() != this)
      sstream << " periodic copy of surface " << getMeshMaster()->tag();
  }

  std::string str = sstream.str();
  if(str.size() && (str[str.size() - 1] == '\n' || str[str.size() - 1] == ' '))
    str.resize(str.size() - 1);
  return str;
}

void GFace::writeGEO(FILE *fp)
{
  if(geomType() == DiscreteSurface || geomType() == BoundaryLayerSurface) return;

  std::vector<GEdge *> const &edg = edges();
  std::vector<int> const &dir = orientations();
  if(edg.size() && dir.size() == edg.size()) {
    std::vector<int> num, ori;
    for(auto it = edg.begin(); it != edg.end(); it++)
      num.push_back((*it)->tag());
    for(auto it = dir.begin(); it != dir.end(); it++)
      ori.push_back((*it) > 0 ? 1 : -1);
    fprintf(fp, "Curve Loop(%d) = ", tag());
    for(std::size_t i = 0; i < num.size(); i++) {
      if(i)
        fprintf(fp, ", %d", num[i] * ori[i]);
      else
        fprintf(fp, "{%d", num[i] * ori[i]);
    }
    fprintf(fp, "};\n");
    if(geomType() == GEntity::Plane) {
      fprintf(fp, "Plane Surface(%d) = {%d};\n", tag(), tag());
    }
    else if(edg.size() == 3 || edg.size() == 4) {
      fprintf(fp, "Surface(%d) = {%d};\n", tag(), tag());
    }
    else {
      Msg::Warning("Skipping surface %d in export", tag());
    }
  }

  for(auto it = embedded_edges.begin(); it != embedded_edges.end(); it++)
    fprintf(fp, "Line {%d} In Surface {%d};\n", (*it)->tag(), tag());

  for(auto it = embedded_vertices.begin(); it != embedded_vertices.end(); it++)
    fprintf(fp, "Point {%d} In Surface {%d};\n", (*it)->tag(), tag());

  if(meshAttributes.method == MESH_TRANSFINITE) {
    fprintf(fp, "Transfinite Surface {%d}", tag());
    if(meshAttributes.corners.size()) {
      fprintf(fp, " = {");
      for(std::size_t i = 0; i < meshAttributes.corners.size(); i++) {
        if(i) fprintf(fp, ",");
        fprintf(fp, "%d", meshAttributes.corners[i]->tag());
      }
      fprintf(fp, "}");
    }
    fprintf(fp, ";\n");
  }

  if(meshAttributes.recombine) fprintf(fp, "Recombine Surface {%d};\n", tag());

  if(meshAttributes.reverseMesh) fprintf(fp, "Reverse Surface {%d};\n", tag());
}

void GFace::writePY(FILE *fp)
{
  // This is by no means complete - merely a placeholder for a future
  // implementation

  if(geomType() == DiscreteSurface || geomType() == BoundaryLayerSurface) return;

  const char *factory = getNativeType() == OpenCascadeModel ? "occ" : "geo";

  std::size_t numcl = 0;
  for(std::size_t i = 0; i < edgeLoops.size(); i++) {
    std::vector<GEdge *> edges;
    std::vector<int> signs;
    edgeLoops[i].getEdges(edges);
    edgeLoops[i].getSigns(signs);
    if(edges.size() && edges.size() == signs.size()) {
      fprintf(fp, "s%d_cl%lu = gmsh.model.%s.addCurveLoop([", tag(), ++numcl,
              factory);
      for(std::size_t j = 0; j < edges.size(); j++) {
        if(j) fprintf(fp, ", ");
        fprintf(fp, "%d", edges[j]->tag() * signs[j]);
      }
      fprintf(fp, "])\n");
    }
  }

  if(geomType() == GEntity::Plane || geomType() == GEntity::ParametricSurface) {
    fprintf(fp, "gmsh.model.%s.addPlaneSurface([", factory);
    for(std::size_t i = 0; i < numcl; i++) {
      if(i) fprintf(fp, ", ");
      fprintf(fp, "s%d_cl%lu", tag(), i + 1);
    }
    fprintf(fp, "], %d)\n", tag());
  }
  else {
    // TODO
    Msg::Warning("Skipping surface %d in export", tag());
  }
}

void GFace::computeMeanPlane()
{
  std::vector<SPoint3> pts;

  if(geomType() == Plane) {
    // Special case for planar CAD surfaces: we first try to compute the
    // parametrization in a way that is more robust with respect to
    // perturbations of the boundary. This is crucial for sensitivity analyses
    // and GFace::relocateMeshVertices(): after perturbation of the boundary, we
    // want a parametrization of the surface that is "close" to the original
    // one. If this fails, we fallback to the classical (SVD-based) algorithm.
    std::vector<GEdge *> const &edg = edges();
    for(auto e : edg) {
      if(!e->haveParametrization()) {
        pts.clear();
        break;
      }
      Range<double> b = e->parBounds(0);
      GPoint p1 = e->point(b.low() + 0.333 * (b.high() - b.low()));
      pts.push_back(SPoint3(p1.x(), p1.y(), p1.z()));
      GPoint p2 = e->point(b.low() + 0.666 * (b.high() - b.low()));
      pts.push_back(SPoint3(p2.x(), p2.y(), p2.z()));
    }
    bool ok = false;
    double res[4] = {0., 0., 0., 0.}, xm = 0., ym = 0., zm = 0.;
    if(pts.size() >= 3) {
      SVector3 d01(pts[0], pts[1]);
      for(std::size_t i = 2; i < pts.size(); i++) {
        SVector3 d0i(pts[0], pts[i]);
        SVector3 n = crossprod(d01, d0i);
        // if too small, the points are almost colinear; tolerance is relatively
        // high so that we don't accept points on plane surfaces defined by
        // lines that are not exactly co-planar
        if(norm(n) >
           sqrt(CTX::instance()->geom.tolerance) * CTX::instance()->lc) {
          res[0] = n.x();
          res[1] = n.y();
          res[2] = n.z();
          xm = pts[0].x();
          ym = pts[0].y();
          zm = pts[0].z();
          ok = true;
          break;
        }
      }
    }
    if(ok) {
      double ex[3], t1[3], t2[3];
      ex[0] = ex[1] = ex[2] = 0.0;
      if(res[0] == 0.)
        ex[0] = 1.0;
      else if(res[1] == 0.)
        ex[1] = 1.0;
      else
        ex[2] = 1.0;
      prodve(res, ex, t1);
      norme(t1);
      prodve(t1, res, t2);
      norme(t2);
      res[3] = (xm * res[0] + ym * res[1] + zm * res[2]);
      fillMeanPlane(res, t1, t2, meanPlane);
      return;
    }
  }

  std::vector<GVertex *> const &verts = vertices();
  for(auto itv = verts.begin(); itv != verts.end(); itv++) {
    const GVertex *v = *itv;
    pts.push_back(SPoint3(v->x(), v->y(), v->z()));
  }

  bool colinear = (pts.size() < 3);
  if(pts.size() > 2) {
    SVector3 d01(pts[0], pts[1]), d02(pts[0], pts[2]);
    if(norm(crossprod(d01, d02)) < 1e-12) colinear = true;
  }

  if(colinear) {
    Msg::Debug("Adding curve points (%d) to compute mean plane of surface %d",
               pts.size(), tag());
    std::vector<GEdge *> const &edg = edges();
    for(auto e : edg) {
      if(e->mesh_vertices.size() > 1) {
        for(std::size_t i = 0; i < e->mesh_vertices.size(); i++)
          pts.push_back(e->mesh_vertices[i]->point());
      }
      else if(!e->haveParametrization()) {
        if(e->getBeginVertex()) {
          GPoint p1 = e->getBeginVertex()->point();
          pts.push_back(SPoint3(p1.x(), p1.y(), p1.z()));
        }
      }
      else {
        Range<double> b = e->parBounds(0);
        GPoint p1 = e->point(b.low() + 0.333 * (b.high() - b.low()));
        pts.push_back(SPoint3(p1.x(), p1.y(), p1.z()));
        GPoint p2 = e->point(b.low() + 0.666 * (b.high() - b.low()));
        pts.push_back(SPoint3(p2.x(), p2.y(), p2.z()));
      }
    }
  }

  computeMeanPlane(pts);
}

void GFace::computeMeanPlane(const std::vector<MVertex *> &points)
{
  std::vector<SPoint3> pts;
  for(std::size_t i = 0; i < points.size(); i++)
    pts.push_back(SPoint3(points[i]->x(), points[i]->y(), points[i]->z()));
  computeMeanPlane(pts);
}

void GFace::computeMeanPlane(const std::vector<SPoint3> &points)
{
  if(points.empty()) return;

  // The concept of a mean plane computed in the sense of least
  // squares is fine for plane surfaces(!), but not really the best
  // one for non-plane surfaces. Indeed, imagine a quarter of a circle
  // extruded along a very small height: the mean plane will be in the
  // plane of the circle... Until we implement something better, there
  // is a test in this routine that checks the coherence of the
  // computation for non-plane surfaces and reverts to a basic mean
  // plane approximatation if the check fails.

  double xm = 0., ym = 0., zm = 0.;
  int ndata = points.size();
  int na = 3;
  for(int i = 0; i < ndata; i++) {
    xm += points[i].x();
    ym += points[i].y();
    zm += points[i].z();
  }
  xm /= (double)ndata;
  ym /= (double)ndata;
  zm /= (double)ndata;

  fullMatrix<double> U(ndata, na), V(na, na);
  fullVector<double> sigma(na);
  for(int i = 0; i < ndata; i++) {
    U(i, 0) = points[i].x() - xm;
    U(i, 1) = points[i].y() - ym;
    U(i, 2) = points[i].z() - zm;
  }
  U.svd(V, sigma);
  double res[4], svd[3];
  svd[0] = sigma(0);
  svd[1] = sigma(1);
  svd[2] = sigma(2);
  int min;
  if(std::abs(svd[0]) < std::abs(svd[1]) && std::abs(svd[0]) < std::abs(svd[2]))
    min = 0;
  else if(std::abs(svd[1]) < std::abs(svd[0]) &&
          std::abs(svd[1]) < std::abs(svd[2]))
    min = 1;
  else
    min = 2;
  res[0] = V(0, min);
  res[1] = V(1, min);
  res[2] = V(2, min);
  norme(res);

  double ex[3], t1[3], t2[3];

  // check coherence of results for non-plane surfaces
  if(geomType() != Plane && geomType() != DiscreteSurface &&
     geomType() != BoundaryLayerSurface) {
    double res2[3], c[3], sinc, angplan;
    double eps = 1.e-3;

    GPoint v1 = point(0.5, 0.5);
    GPoint v2 = point(0.5 + eps, 0.5);
    GPoint v3 = point(0.5, 0.5 + eps);
    t1[0] = v2.x() - v1.x();
    t1[1] = v2.y() - v1.y();
    t1[2] = v2.z() - v1.z();
    t2[0] = v3.x() - v1.x();
    t2[1] = v3.y() - v1.y();
    t2[2] = v3.z() - v1.z();
    norme(t1);
    norme(t2);
    // prodve(t1, t2, res2);
    // WARNING: the rest of the code assumes res = t2 x t1, not t1 x t2 (WTF?)
    prodve(t2, t1, res2);
    norme(res2);

    prodve(res, res2, c);
    double const cosc = prosca(res, res2);
    sinc = std::sqrt(c[0] * c[0] + c[1] * c[1] + c[2] * c[2]);
    angplan = myatan2(sinc, cosc);
    angplan = angle_02pi(angplan) * 180. / M_PI;
    if((angplan > 70 && angplan < 110) || (angplan > 260 && angplan < 280)) {
      Msg::Info("SVD failed (angle=%g): using rough algo...", angplan);
      res[0] = res2[0];
      res[1] = res2[1];
      res[2] = res2[2];
      goto end;
    }
  }

  ex[0] = ex[1] = ex[2] = 0.0;
  if(res[0] == 0.)
    ex[0] = 1.0;
  else if(res[1] == 0.)
    ex[1] = 1.0;
  else
    ex[2] = 1.0;

  prodve(res, ex, t1);
  norme(t1);
  prodve(t1, res, t2);
  norme(t2);

end:
  res[3] = (xm * res[0] + ym * res[1] + zm * res[2]);

  fillMeanPlane(res, t1, t2, meanPlane);

  Msg::Debug("Surface: %d", tag());
  Msg::Debug("SVD    : %g,%g,%g (min=%d)", svd[0], svd[1], svd[2], min);
  Msg::Debug("Plane  : (%g x + %g y + %g z = %g)", meanPlane.a, meanPlane.b,
             meanPlane.c, meanPlane.d);
  Msg::Debug("Normal : (%g , %g , %g )", meanPlane.a, meanPlane.b, meanPlane.c);
  Msg::Debug("t1     : (%g , %g , %g )", t1[0], t1[1], t1[2]);
  Msg::Debug("t2     : (%g , %g , %g )", t2[0], t2[1], t2[2]);
  Msg::Debug("pt     : (%g , %g , %g )", meanPlane.x, meanPlane.y, meanPlane.z);

  // check coherence for plane surfaces
  if(geomType() == Plane) {
    SBoundingBox3d bb = bounds();
    double lc = norm(SVector3(bb.max(), bb.min()));
    std::vector<GVertex *> const &verts = vertices();
    for(auto itv = verts.begin(); itv != verts.end(); itv++) {
      const GVertex *v = *itv;
      double const d = meanPlane.a * v->x() + meanPlane.b * v->y() +
                       meanPlane.c * v->z() - meanPlane.d;
      if(std::abs(d) > lc * 1.e-3) {
        Msg::Debug("Plane surface %d (%gx+%gy+%gz=%g) is not plane!", tag(),
                   meanPlane.a, meanPlane.b, meanPlane.c, meanPlane.d);
        Msg::Debug("Control point %d = (%g,%g,%g), val=%g", v->tag(), v->x(),
                   v->y(), v->z(), d);
        break;
      }
    }
  }
}

void GFace::getMeanPlaneData(double VX[3], double VY[3], double &x, double &y,
                             double &z) const
{
  VX[0] = meanPlane.plan[0][0];
  VX[1] = meanPlane.plan[0][1];
  VX[2] = meanPlane.plan[0][2];
  VY[0] = meanPlane.plan[1][0];
  VY[1] = meanPlane.plan[1][1];
  VY[2] = meanPlane.plan[1][2];
  x = meanPlane.x;
  y = meanPlane.y;
  z = meanPlane.z;
}

void GFace::getMeanPlaneData(double plan[3][3]) const
{
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++) plan[i][j] = meanPlane.plan[i][j];
}

void GFace::computeMeshSizeFieldAccuracy(double &avg, double &max_e,
                                         double &min_e, int &nE, int &GS)
{
#if defined(HAVE_MESH)
  std::set<MEdge, MEdgeLessThan> es;
  for(std::size_t i = 0; i < getNumMeshElements(); i++) {
    MElement *e = getMeshElement(i);
    for(int j = 0; j < e->getNumEdges(); j++) es.insert(e->getEdge(j));
  }

  avg = 0;
  min_e = 1.e22;
  max_e = 0;
  nE = es.size();
  GS = 0;
  double oneoversqr2 = 1. / sqrt(2.);
  double sqr2 = sqrt(2.);
  for(auto it = es.begin(); it != es.end(); ++it) {
    double u1, v1, u2, v2;
    MVertex *vert1 = it->getVertex(0);
    vert1->getParameter(0, u1);
    vert1->getParameter(1, v1);
    MVertex *vert2 = it->getVertex(1);
    vert2->getParameter(0, u2);
    vert2->getParameter(1, v2);
    double l1 = BGM_MeshSize(this, u1, v1, vert1->x(), vert1->y(), vert1->z());
    double l2 = BGM_MeshSize(this, u2, v2, vert2->x(), vert2->y(), vert2->z());
    double correctLC = 0.5 * (l1 + l2);
    double lone = it->length() / correctLC;
    if(lone > oneoversqr2 && lone < sqr2) GS++;
    avg += lone > 1 ? (1. / lone) - 1. : lone - 1.;
    max_e = std::max(max_e, lone);
    min_e = std::min(min_e, lone);
  }
#endif
}

double GFace::curvatureDiv(const SPoint2 &param) const
{
  if(geomType() == Plane || geomType() == BoundaryLayerSurface) return 0;

  // X=X(u,v) Y=Y(u,v) Z=Z(u,v)
  // curv = div n = dnx/dx + dny/dy + dnz/dz
  // dnx/dx = dnx/du du/dx + dnx/dv dv/dx

  const double eps = 1.e-5;

  Pair<SVector3, SVector3> der = firstDer(param);

  SVector3 du = der.first();
  SVector3 dv = der.second();
  SVector3 nml = crossprod(du, dv);

  double detJ = norm(nml);

  du.normalize();
  dv.normalize();

  SVector3 n1, n2, n3, n4;
  if(param.x() - eps < 0.0) {
    n1 = normal(SPoint2(param.x(), param.y()));
    n2 = normal(SPoint2(param.x() + eps, param.y()));
  }
  else {
    n1 = normal(SPoint2(param.x() - eps, param.y()));
    n2 = normal(SPoint2(param.x(), param.y()));
  }
  if(param.y() - eps < 0.0) {
    n3 = normal(SPoint2(param.x(), param.y()));
    n4 = normal(SPoint2(param.x(), param.y() + eps));
  }
  else {
    n3 = normal(SPoint2(param.x(), param.y() - eps));
    n4 = normal(SPoint2(param.x(), param.y()));
  }

  SVector3 dndu = 100000 * (n2 - n1);
  SVector3 dndv = 100000 * (n4 - n3);

  SVector3 dudu = SVector3();
  SVector3 dvdv = SVector3();
  SVector3 dudv = SVector3();
  secondDer(param, dudu, dvdv, dudv);

  double ddu = dot(dndu, du);
  double ddv = dot(dndv, dv);

  return (fabs(ddu) + fabs(ddv)) / detJ;
}

double GFace::curvatureMax(const SPoint2 &param) const
{
  if(geomType() == Plane || geomType() == BoundaryLayerSurface) return 0.;

  double eigVal[2], eigVec[8];
  getMetricEigenVectors(param, eigVal, eigVec);

  return fabs(eigVal[1]);
}

double GFace::curvatures(const SPoint2 &param, SVector3 &dirMax,
                         SVector3 &dirMin, double &curvMax,
                         double &curvMin) const
{
  Pair<SVector3, SVector3> D1 = firstDer(param);

  if(geomType() == Plane || geomType() == BoundaryLayerSurface) {
    dirMax = D1.first();
    dirMin = D1.second();
    curvMax = 0.;
    curvMin = 0.;
    return 0.;
  }

  if(geomType() == Sphere) {
    dirMax = D1.first();
    dirMin = D1.second();
    curvMax = curvatureDiv(param);
    curvMin = curvMax;
    return curvMax;
  }

  double eigVal[2], eigVec[8];
  getMetricEigenVectors(param, eigVal, eigVec);

  // curvatures and main directions
  curvMax = fabs(eigVal[1]);
  curvMin = fabs(eigVal[0]);
  dirMax = eigVec[1] * D1.first() + eigVec[3] * D1.second();
  dirMin = eigVec[0] * D1.first() + eigVec[2] * D1.second();

  return curvMax;
}

double GFace::getMetricEigenvalue(const SPoint2 &)
{
  Msg::Error("Metric eigenvalue is not implemented for this type of surface");
  return 0.;
}

// eigen values are absolute values and sorted from min to max of absolute
// values eigen vectors are the corresponding COLUMNS of eigVec
void GFace::getMetricEigenVectors(const SPoint2 &param, double eigVal[2],
                                  double eigVec[4]) const
{
  // first derivatives
  Pair<SVector3, SVector3> D1 = firstDer(param);
  SVector3 du = D1.first();
  SVector3 dv = D1.second();
  SVector3 nor = crossprod(du, dv);
  nor.normalize();

  // second derivatives
  SVector3 dudu = SVector3();
  SVector3 dvdv = SVector3();
  SVector3 dudv = SVector3();
  secondDer(param, dudu, dvdv, dudv);

  // first form
  double form1[2][2];
  form1[0][0] = normSq(du);
  form1[1][1] = normSq(dv);
  form1[0][1] = form1[1][0] = dot(du, dv);

  // second form
  double form2[2][2];
  form2[0][0] = dot(nor, dudu);
  form2[1][1] = dot(nor, dvdv);
  form2[0][1] = form2[1][0] = dot(nor, dudv);

  // inverse of first form
  double inv_form1[2][2];
  double denom = (form1[0][0] * form1[1][1] - form1[1][0] * form1[0][1]);
  if(denom) {
    double inv_det_form1 = 1. / denom;
    inv_form1[0][0] = inv_det_form1 * form1[1][1];
    inv_form1[1][1] = inv_det_form1 * form1[0][0];
    inv_form1[1][0] = inv_form1[0][1] = -1 * inv_det_form1 * form1[0][1];

    // N = (inverse of form1) X (form2)
    fullMatrix<double> N(2, 2);
    N(0, 0) = inv_form1[0][0] * form2[0][0] + inv_form1[0][1] * form2[1][0];
    N(0, 1) = inv_form1[0][0] * form2[0][1] + inv_form1[0][1] * form2[1][1];
    N(1, 0) = inv_form1[1][0] * form2[0][0] + inv_form1[1][1] * form2[1][0];
    N(1, 1) = inv_form1[1][0] * form2[0][1] + inv_form1[1][1] * form2[1][1];

    // eigen values and vectors of N
    fullMatrix<double> vl(2, 2), vr(2, 2);
    fullVector<double> dr(2), di(2);
    if(N.eig(dr, di, vl, vr, true)) {
      eigVal[0] = fabs(dr(0));
      eigVal[1] = fabs(dr(1));
      eigVec[0] = vr(0, 0);
      eigVec[2] = vr(1, 0);
      eigVec[1] = vr(0, 1);
      eigVec[3] = vr(1, 1);
      if(fabs(di(0)) > 1.e-12 || fabs(di(1)) > 1.e-12) {
        Msg::Warning("Imaginary eigenvalues in metric");
      }
      return;
    }
  }

  Msg::Warning("Could not compute metric eigenvectors");
  for(int i = 0; i < 2; i++) eigVal[i] = 0.;
  for(int i = 0; i < 4; i++) eigVec[i] = 0.;
}

void GFace::XYZtoUV(double X, double Y, double Z, double &U, double &V,
                    double relax, bool onSurface, bool convTestXYZ) const
{
  if(geomType() == BoundaryLayerSurface) return;

  const double Precision = onSurface ? 1.e-8 : 1.e-3;
  const int MaxIter = onSurface ? 25 : 10;
  const int NumInitGuess = 9;
  bool testXYZ =
    (convTestXYZ || CTX::instance()->mesh.NewtonConvergenceTestXYZ);

  double Unew = 0., Vnew = 0., err, err2;
  int iter;
  double mat[3][3], jac[3][3];
  double umin, umax, vmin, vmax;
  // don't use 0.9, 0.1 it fails with ruled surfaces
  double initu[NumInitGuess] = {0.5, 0.6, 0.4, 0.7, 0.3, 0.8, 0.2, 1.0, 0.0};
  double initv[NumInitGuess] = {0.5, 0.6, 0.4, 0.7, 0.3, 0.8, 0.2, 1.0, 0.0};

  Range<double> ru = parBounds(0);
  Range<double> rv = parBounds(1);
  umin = ru.low();
  umax = ru.high();
  vmin = rv.low();
  vmax = rv.high();

  const double tol =
    Precision * (std::pow(umax - umin, 2) + std::pow(vmax - vmin, 2));
  for(int i = 0; i < NumInitGuess; i++) {
    initu[i] = umin + initu[i] * (umax - umin);
    initv[i] = vmin + initv[i] * (vmax - vmin);
  }

  for(int i = 0; i < NumInitGuess; i++) {
    for(int j = 0; j < NumInitGuess; j++) {
      U = initu[i];
      V = initv[j];
      err = 1.0;
      iter = 1;

      GPoint P = point(U, V);
      err2 = std::sqrt(std::pow(X - P.x(), 2) + std::pow(Y - P.y(), 2) +
                       std::pow(Z - P.z(), 2));
      if(err2 < 1.e-8 * CTX::instance()->lc) return;

      while(err > tol && iter < MaxIter) {
        P = point(U, V);
        Pair<SVector3, SVector3> der = firstDer(SPoint2(U, V));
        mat[0][0] = der.left().x();
        mat[0][1] = der.left().y();
        mat[0][2] = der.left().z();
        mat[1][0] = der.right().x();
        mat[1][1] = der.right().y();
        mat[1][2] = der.right().z();
        mat[2][0] = 0.;
        mat[2][1] = 0.;
        mat[2][2] = 0.;
        invert_singular_matrix3x3(mat, jac);

        Unew = U + relax * (jac[0][0] * (X - P.x()) + jac[1][0] * (Y - P.y()) +
                            jac[2][0] * (Z - P.z()));
        Vnew = V + relax * (jac[0][1] * (X - P.x()) + jac[1][1] * (Y - P.y()) +
                            jac[2][1] * (Z - P.z()));

        // don't remove this test: it is important
        if((Unew > umax + tol || Unew < umin - tol) &&
           (Vnew > vmax + tol || Vnew < vmin - tol))
          break;

        err = std::pow(Unew - U, 2) + std::pow(Vnew - V, 2);
        err2 = std::sqrt(std::pow(X - P.x(), 2) + std::pow(Y - P.y(), 2) +
                         std::pow(Z - P.z(), 2));

        iter++;
        U = Unew;
        V = Vnew;
      }

      if(iter < MaxIter && err <= tol && Unew <= umax && Vnew <= vmax &&
         Unew >= umin && Vnew >= vmin) {
        if(onSurface && err2 > 1.e-4 * CTX::instance()->lc && !testXYZ) {
          Msg::Warning("Converged at iter. %d for initial guess (%d,%d) "
                       "with uv error = %g, but xyz error = %g in point "
                       "(%e, %e, %e) on surface %d",
                       iter, i, j, err, err2, X, Y, Z, tag());
        }
        if(onSurface && err2 > 1.e-4 * CTX::instance()->lc && testXYZ) {
          // not converged in XYZ coordinates: try again
        }
        else {
          return;
        }
      }
    }
  }

  if(!onSurface) return;

  if(relax < 1.e-3)
    Msg::Warning("Inverse surface mapping could not converge");
  else {
    Msg::Info("Point %g %g %g: Relaxation factor = %g", X, Y, Z, 0.75 * relax);
    XYZtoUV(X, Y, Z, U, V, 0.75 * relax, onSurface, convTestXYZ);
  }
}

SPoint2 GFace::parFromPoint(const SPoint3 &p, bool onSurface,
                            bool convTestXYZ) const
{
  if(geomType() == BoundaryLayerSurface) return SPoint2();

  double U = 0., V = 0.;
  XYZtoUV(p.x(), p.y(), p.z(), U, V, 1.0, onSurface, convTestXYZ);
  return SPoint2(U, V);
}

#if defined(HAVE_ALGLIB)

class data_wrapper {
private:
  const GFace *gf;
  SPoint3 point;

public:
  data_wrapper()
  {
    gf = nullptr;
    point = SPoint3();
  }
  ~data_wrapper() {}
  const GFace *get_face() { return gf; }
  void set_face(const GFace *face) { gf = face; }
  SPoint3 get_point() { return point; }
  void set_point(const SPoint3 &_point) { point = SPoint3(_point); }
};

// Callback function for ALGLIB
void bfgs_callback(const alglib::real_1d_array &x, double &func,
                   alglib::real_1d_array &grad, void *ptr)
{
  auto *w = static_cast<data_wrapper *>(ptr);
  SPoint3 p = w->get_point();
  const GFace *gf = w->get_face();

  // Value of the objective
  GPoint pnt = gf->point(x[0], x[1]);
  func = 0.5 * (p.x() - pnt.x()) * (p.x() - pnt.x()) +
         (p.y() - pnt.y()) * (p.y() - pnt.y()) +
         (p.z() - pnt.z()) * (p.z() - pnt.z());
  // printf("func : %f\n", func);

  // Value of the gradient
  Pair<SVector3, SVector3> der = gf->firstDer(SPoint2(x[0], x[1]));
  grad[0] = -(p.x() - pnt.x()) * der.left().x() -
            (p.y() - pnt.y()) * der.left().y() -
            (p.z() - pnt.z()) * der.left().z();
  grad[1] = -(p.x() - pnt.x()) * der.right().x() -
            (p.y() - pnt.y()) * der.right().y() -
            (p.z() - pnt.z()) * der.right().z();
  // printf("func %22.15E Gradients %22.15E %22.15E der %g %g %g\n", func,
  //         grad[0], grad[1],der.left().x(),der.left().y(),der.left().z());
}
#endif

GPoint GFace::closestPoint(const SPoint3 &queryPoint,
                           const double initialGuess[2]) const
{
  if(geomType() == BoundaryLayerSurface) return GPoint();

#if defined(HAVE_ALGLIB)
  // Test initial guess
  double min_u = initialGuess[0];
  double min_v = initialGuess[1];
  GPoint pnt = point(min_u, min_v);
  SPoint3 spnt(pnt.x(), pnt.y(), pnt.z());
  double min_dist = queryPoint.distance(spnt);

  // Try to find a better initial guess by sampling full parameter range
  const double nGuesses = 10.;
  const Range<double> uu = parBounds(0);
  const Range<double> vv = parBounds(1);
  const double ru = uu.high() - uu.low(), rv = vv.high() - vv.low();
  const double epsU = 1e-5 * ru, epsV = 1e-5 * rv;
  const double du = ru / nGuesses, dv = rv / nGuesses;
  for(double u = uu.low(); u <= uu.high() + epsU; u += du) {
    for(double v = vv.low(); v <= vv.high() + epsV; v += dv) {
      GPoint pnt = point(u, v);
      SPoint3 spnt(pnt.x(), pnt.y(), pnt.z());
      double dist = queryPoint.distance(spnt);
      if(dist < min_dist) {
        min_dist = dist;
        min_u = u;
        min_v = v;
      }
    }
  }

  try {
    // Set up optimisation problem
    alglib::ae_int_t dim = 2;
    alglib::ae_int_t corr = 2; // Num of corrections in the scheme in [3,7]
    alglib::minlbfgsstate state;
    alglib::real_1d_array x;
    const double initialCond[2] = {min_u, min_v};
    x.setcontent(dim, initialCond);
    minlbfgscreate(2, corr, x, state);

    // Set stopping criteria
    const double epsg = 1.e-12;
    const double epsf = 0.;
    const double epsx = 0.;
    const alglib::ae_int_t maxits = 500;
    minlbfgssetcond(state, epsg, epsf, epsx, maxits);

    // Solve problem
    data_wrapper w;
    w.set_point(queryPoint);
    w.set_face(this);
    minlbfgsoptimize(state, bfgs_callback, nullptr, &w);

    // Get results
    alglib::minlbfgsreport rep;
    minlbfgsresults(state, x, rep);
    GPoint pntF = point(x[0], x[1]);
    return pntF;
  } catch(...) {
    Msg::Warning("Closest point failed, computing from parametric coordinate");
    SPoint2 p = parFromPoint(queryPoint, false);
    return point(p);
  }

#else
  Msg::Error("Closest point not implemented for this type of surface");
  SPoint2 p = parFromPoint(queryPoint, false);
  return point(p);
#endif
}

bool GFace::containsParam(const SPoint2 &pt)
{
  if(geomType() == BoundaryLayerSurface) return false;

  Range<double> uu = parBounds(0);
  Range<double> vv = parBounds(1);
  if((pt.x() >= uu.low() && pt.x() <= uu.high()) &&
     (pt.y() >= vv.low() && pt.y() <= vv.high()))
    return true;
  else
    return false;
}

SVector3 GFace::normal(const SPoint2 &param) const
{
  if(geomType() == BoundaryLayerSurface) return SVector3();

  Pair<SVector3, SVector3> der = firstDer(param);
  SVector3 n = crossprod(der.first(), der.second());
  n.normalize();
  return n;
}

bool GFace::buildRepresentationCross(bool force)
{
  if(cross[0].size()) {
    if(force) {
      cross[0].clear();
      cross[1].clear();
    }
    else
      return true;
  }

  if(!haveParametrization()) { // cannot do it, add a dummy point
    if(cross[0].empty()) {
      cross[0].push_back(std::vector<SPoint3>());
      cross[0][0].push_back(bounds().center());
    }
    return false;
  }

  Range<double> ubounds = parBounds(0);
  Range<double> vbounds = parBounds(1);
  bool tri = (geomType() == RuledSurface && getNativeType() == GmshModel &&
              edges().size() == 3 && !CTX::instance()->geom.oldRuledSurface);
  double tol = 1e-8;
  double ud = (ubounds.high() - ubounds.low()) - 2 * tol;
  double vd = (vbounds.high() - vbounds.low()) - 2 * tol;
  double u2 = 0.5 * (ubounds.high() + ubounds.low());
  double v2 = 0.5 * (vbounds.high() + vbounds.low());
  int N = 100;
  for(int dir = 0; dir < 2; dir++) {
    cross[dir].push_back(std::vector<SPoint3>());
    for(int i = 0; i < N; i++) {
      double t = (double)i / (double)(N - 1);
      SPoint2 uv;
      if(!dir) {
        if(tri)
          uv.setPosition(u2 + u2 * t, vbounds.low() + tol + v2 * t);
        else
          uv.setPosition(ubounds.low() + tol + ud * t, v2);
      }
      else {
        if(tri)
          uv.setPosition(u2 + u2 * t, v2 - v2 * t);
        else
          uv.setPosition(u2, vbounds.low() + tol + vd * t);
      }
      GPoint p = point(uv);
      SPoint3 pt(p.x(), p.y(), p.z());
      bool inside =
        (geomType() == Plane) ? containsPoint(pt) : containsParam(uv);
      if(inside) { cross[dir].back().push_back(pt); }
      else {
        if(cross[dir].back().size())
          cross[dir].push_back(std::vector<SPoint3>());
      }
    }
    while(!cross[dir].empty() && cross[dir].back().empty())
      cross[dir].pop_back();
  }


  // draw additional small diamonds for plane surfaces, to make it easier to
  // select overlapping surfaces placed such that their crosses fully overlap
  // (e.g. when creating a hole centered in the middle of a surface, something
  // that happens quite often in practice)
  if(geomType() == Plane) {
    if(cross[0].size() > 0 && cross[0][0].size() > 1 &&
       cross[1].size() > 0 && cross[1][0].size() > 1) {
      SVector3 v0(cross[0][0][0], cross[0][0][1]);
      SVector3 v1(cross[1][0][0], cross[1][0][1]);
      double l0 = v0.normalize();
      double l1 = v1.normalize();
      SPoint3 p[4] = {cross[0].front().front(),
                      cross[0].back().back(),
                      cross[1].front().front(),
                      cross[1].back().back()};
      SVector3 vt[4] = {v0, -v0, v1, -v1};
      SVector3 vp[4] = {v1, -v1, v0, -v0};
      double l[4] = {l0, l0, l1, l1};
      for(int s = 0; s < 4; s++) {
        SPoint3 p0 = p[s];
        SPoint3 p1 = p0 + l[s] * vt[s];
        SPoint3 p2 = p1 + l[s] * vt[s] + l[s] * vp[s];
        SPoint3 p3 = p1 + 2 * l[s] * vt[s];
        SPoint3 p4 = p1 + l[s] * vt[s] - l[s] * vp[s];
        if(containsPoint(p1) && containsPoint(p3)) {
          if(containsPoint(p2)) {
            std::vector<SPoint3> c1 = {p1, p2};
            std::vector<SPoint3> c2 = {p2, p3};
            cross[0].push_back(c1);
            cross[0].push_back(c2);
          }
          if(containsPoint(p4)) {
            std::vector<SPoint3> c1 = {p1, p4};
            std::vector<SPoint3> c2 = {p4, p3};
            cross[0].push_back(c1);
            cross[0].push_back(c2);
          }
        }
      }
    }
  }

  // if we couldn't determine a cross, add a single point (center of the
  // bounding box) so that we won't try again unless we force the recomputation,
  // but we will still have a point to draw e.g. the label
  if(cross[0].empty()) {
    cross[0].push_back(std::vector<SPoint3>());
    cross[0][0].push_back(bounds().center());
    return false;
  }
  return true;
}

bool GFace::buildSTLTriangulation(bool force)
{
  if(stl_triangles.size() && !force) return true;

  stl_vertices_uv.clear();
  stl_vertices_xyz.clear();
  stl_triangles.clear();

  if(triangles.size()) {
    // if a mesh exists, import it as the STL representation
    std::map<MVertex *, int, MVertexPtrLessThan> nodes;
    for(std::size_t i = 0; i < triangles.size(); i++) {
      for(int j = 0; j < 3; j++) {
        MVertex *v = triangles[i]->getVertex(j);
        if(!nodes.count(v)) {
          stl_vertices_xyz.push_back(SPoint3(v->x(), v->y(), v->z()));
          nodes[v] = stl_vertices_xyz.size() - 1;
        }
      }
    }
    for(std::size_t i = 0; i < triangles.size(); i++) {
      for(int j = 0; j < 3; j++) {
        stl_triangles.push_back(nodes[triangles[i]->getVertex(j)]);
      }
    }
    return true;
  }
  else if(geomType() == ParametricSurface) {
    // build a simple triangulation for surfaces which we know are not trimmed
    const int nu = 64, nv = 64;
    Range<double> ubounds = parBounds(0);
    Range<double> vbounds = parBounds(1);
    double umin = ubounds.low(), umax = ubounds.high();
    double vmin = vbounds.low(), vmax = vbounds.high();
    for(int i = 0; i < nu; i++) {
      for(int j = 0; j < nv; j++) {
        double u = umin + (double)i / (double)(nu - 1) * (umax - umin);
        double v = vmin + (double)j / (double)(nv - 1) * (vmax - vmin);
        stl_vertices_uv.push_back(SPoint2(u, v));
        GPoint gp = point(u, v);
        stl_vertices_xyz.push_back(SPoint3(gp.x(), gp.y(), gp.z()));
      }
    }
    for(int i = 0; i < nu - 1; i++) {
      for(int j = 0; j < nv - 1; j++) {
        stl_triangles.push_back(i * nv + j);
        stl_triangles.push_back((i + 1) * nv + j);
        stl_triangles.push_back((i + 1) * nv + j + 1);
        stl_triangles.push_back(i * nv + j);
        stl_triangles.push_back((i + 1) * nv + j + 1);
        stl_triangles.push_back(i * nv + j + 1);
      }
    }
    return true;
  }

  return false;
}

bool GFace::fillVertexArray(bool force)
{
  if(va_geom_triangles) {
    if(force)
      delete va_geom_triangles;
    else
      return true;
  }

  if(!buildSTLTriangulation(force)) return false;
  if(stl_triangles.empty()) return false;

  va_geom_triangles = new VertexArray(3, stl_triangles.size() / 3);
  unsigned int c =
    useColor() ? getColor() : CTX::instance()->color.geom.surface;
  unsigned int col[4] = {c, c, c, c};
  if(stl_vertices_xyz.size()) {
    for(std::size_t i = 0; i < stl_triangles.size(); i += 3) {
      SPoint3 &p1(stl_vertices_xyz[stl_triangles[i]]);
      SPoint3 &p2(stl_vertices_xyz[stl_triangles[i + 1]]);
      SPoint3 &p3(stl_vertices_xyz[stl_triangles[i + 2]]);
      double x[3] = {p1.x(), p2.x(), p3.x()};
      double y[3] = {p1.y(), p2.y(), p3.y()};
      double z[3] = {p1.z(), p2.z(), p3.z()};
      if(stl_vertices_xyz.size() == stl_normals.size()) {
        SVector3 n[3] = {stl_normals[stl_triangles[i]],
                         stl_normals[stl_triangles[i + 1]],
                         stl_normals[stl_triangles[i + 2]]};
        va_geom_triangles->add(x, y, z, n, col);
      }
      else {
        double nn[3];
        normal3points(x[0], y[0], z[0], x[1], y[1], z[1], x[2], y[2], z[2], nn);
        SVector3 n[3] = {SVector3(nn), SVector3(nn), SVector3(nn)};
        va_geom_triangles->add(x, y, z, n, col);
      }
    }
  }
  else if(stl_vertices_uv.size()) {
    for(std::size_t i = 0; i < stl_triangles.size(); i += 3) {
      SPoint2 &p1(stl_vertices_uv[stl_triangles[i]]);
      SPoint2 &p2(stl_vertices_uv[stl_triangles[i + 1]]);
      SPoint2 &p3(stl_vertices_uv[stl_triangles[i + 2]]);
      GPoint gp1 = point(p1);
      GPoint gp2 = point(p2);
      GPoint gp3 = point(p3);
      double x[3] = {gp1.x(), gp2.x(), gp3.x()};
      double y[3] = {gp1.y(), gp2.y(), gp3.y()};
      double z[3] = {gp1.z(), gp2.z(), gp3.z()};
      if(stl_vertices_uv.size() == stl_normals.size()) {
        SVector3 n[3] = {stl_normals[stl_triangles[i]],
                         stl_normals[stl_triangles[i + 1]],
                         stl_normals[stl_triangles[i + 2]]};
        va_geom_triangles->add(x, y, z, n, col);
      }
      else {
        SVector3 n[3] = {normal(p1), normal(p2), normal(p3)};
        va_geom_triangles->add(x, y, z, n, col);
      }
    }
  }
  va_geom_triangles->finalize();
  return true;
}

bool GFace::storeSTLAsMesh()
{
  // as the STL might be non-conforming, we make no effort to have a conformal
  // mesh - nodes will not be classified on boundaries, and not shared with
  // adjacent entities
  if(stl_vertices_xyz.size()) {
    for(std::size_t i = 0; i < stl_vertices_xyz.size(); i++) {
      SPoint3 &p(stl_vertices_xyz[i]);
      mesh_vertices.push_back(new MVertex(p.x(), p.y(), p.z(), this));
    }
  }
  else if(stl_vertices_uv.size()) {
    for(std::size_t i = 0; i < stl_vertices_uv.size(); i++) {
      SPoint2 &p(stl_vertices_uv[i]);
      GPoint gp = point(p);
      mesh_vertices.push_back(new MFaceVertex(gp.x(), gp.y(), gp.z(),
                                              this, p.x(), p.y()));
    }
  }
  else {
    return false;
  }
  for(std::size_t i = 0; i < stl_triangles.size(); i += 3) {
    triangles.push_back(new MTriangle(mesh_vertices[stl_triangles[i]],
                                      mesh_vertices[stl_triangles[i + 1]],
                                      mesh_vertices[stl_triangles[i + 2]]));
  }
  return true;
}

int GFace::genusGeom() const
{
  int nSeams = 0;
  std::set<GEdge *> single_seams;
  for(auto it = l_edges.begin(); it != l_edges.end(); ++it) {
    if((*it)->isSeam(this)) {
      nSeams++;
      auto it2 = single_seams.find(*it);
      if(it2 != single_seams.end())
        single_seams.erase(it2);
      else
        single_seams.insert(*it);
    }
  }
  return nSeams - single_seams.size();
}

bool GFace::fillPointCloud(double maxDist, std::vector<SPoint3> *points,
                           std::vector<SPoint2> *uvpoints,
                           std::vector<SVector3> *normals)
{
  if(!points) return false;

  if(buildSTLTriangulation()) {
    if(stl_vertices_xyz.size()) {
      for(std::size_t i = 0; i < stl_triangles.size(); i += 3) {
        SPoint3 &p0(stl_vertices_xyz[stl_triangles[i]]);
        SPoint3 &p1(stl_vertices_xyz[stl_triangles[i + 1]]);
        SPoint3 &p2(stl_vertices_xyz[stl_triangles[i + 2]]);
        double maxEdge =
          std::max(p0.distance(p1), std::max(p1.distance(p2), p2.distance(p0)));
        int N = std::max((int)(maxEdge / maxDist), 1);
        for(double u = 0.; u < 1.; u += 1. / N) {
          for(double v = 0.; v < 1 - u; v += 1. / N) {
            SPoint3 p = p0 * (1. - u - v) + p1 * u + p2 * v;
            points->push_back(p);
          }
        }
      }
    }
    else if(stl_vertices_uv.size()) {
      for(std::size_t i = 0; i < stl_triangles.size(); i += 3) {
        SPoint2 &p0(stl_vertices_uv[stl_triangles[i]]);
        SPoint2 &p1(stl_vertices_uv[stl_triangles[i + 1]]);
        SPoint2 &p2(stl_vertices_uv[stl_triangles[i + 2]]);
        GPoint gp0 = point(p0);
        GPoint gp1 = point(p1);
        GPoint gp2 = point(p2);
        double maxEdge = std::max(
          gp0.distance(gp1), std::max(gp1.distance(gp2), gp2.distance(gp0)));
        int N = std::max((int)(maxEdge / maxDist), 1);
        for(double u = 0.; u < 1.; u += 1. / N) {
          for(double v = 0.; v < 1 - u; v += 1. / N) {
            SPoint2 p = p0 * (1. - u - v) + p1 * u + p2 * v;
            GPoint gp(point(p));
            points->push_back(SPoint3(gp.x(), gp.y(), gp.z()));
            if(uvpoints) uvpoints->push_back(p);
            if(normals) normals->push_back(normal(p));
          }
        }
      }
    }
  }
  else {
    // uniform sampling of underlying parametric plane
    int N = std::max((int)(bounds().diag() / maxDist), 2);
    Range<double> b1 = parBounds(0);
    Range<double> b2 = parBounds(1);
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
        double u = (double)i / (N - 1);
        double v = (double)j / (N - 1);
        double t1 = b1.low() + u * (b1.high() - b1.low());
        double t2 = b2.low() + v * (b2.high() - b2.low());
        GPoint gp = point(t1, t2);
        points->push_back(SPoint3(gp.x(), gp.y(), gp.z()));
        if(uvpoints) uvpoints->push_back(SPoint2(t1, t2));
        if(normals) normals->push_back(normal(SPoint2(t1, t2)));
      }
    }
  }
  return true;
}

#if defined(HAVE_MESH)

#if defined(HAVE_QUADMESHINGTOOLS)

int buildBackgroundField(
  GModel *gm, const std::vector<MTriangle *> &global_triangles,
  const std::vector<std::array<double, 9> > &global_triangle_directions,
  const std::unordered_map<MVertex *, double> &global_size_map,
  const std::vector<std::array<double, 5> > &global_singularity_list,
  const std::string &viewName);
int fillSizemapFromScalarBackgroundField(
  GModel *gm, const std::vector<MTriangle *> &triangles,
  std::unordered_map<MVertex *, double> &sizeMap);

#endif

static int meshCompoundMakeQuads(GFace *gf)
{
  if(gf->meshAttributes.algorithm != ALGO_2D_PACK_PRLGRMS &&
     gf->meshAttributes.algorithm != ALGO_2D_QUAD_QUASI_STRUCT)
    return 0;

  // recombineIntoQuads(gf, false, 2, true, .01);

  meshGFaceQuadrangulateBipartiteLabelling(gf->tag());
  return 0;
}

static int meshCompoundComputeCrossFieldWithHeatEquation(GFace *gf)
{
  if(gf->meshAttributes.algorithm != ALGO_2D_PACK_PRLGRMS &&
     gf->meshAttributes.algorithm != ALGO_2D_QUAD_QUASI_STRUCT)
    return 0;

#if defined(HAVE_QUADMESHINGTOOLS)

  std::vector<std::array<double, 3> > triEdgeTheta;
  std::vector<MLine *> lines;
  std::vector<GEdge *> edges = gf->edges();
  for(auto ge : edges)
    lines.insert(lines.end(), ge->lines.begin(), ge->lines.end());

  int scf =
    computeCrossFieldWithHeatEquation(4, gf->triangles, lines, triEdgeTheta);

  if(scf != 0) {
    Msg::Warning("- Face %i: failed to compute cross field", gf->tag());
    return scf;
  }

  std::vector<std::array<double, 9> > triangleDirections;
  int sc = convertToPerTriangleCrossFieldDirections(
    4, gf->triangles, triEdgeTheta, triangleDirections);
  if(sc != 0) {
    Msg::Warning(
      "- Face %i: failed to resample cross field at triangle corners",
      gf->tag());
  }

  std::unordered_map<MVertex *, double> sizeMap;

  int sts =
    fillSizemapFromScalarBackgroundField(gf->model(), gf->triangles, sizeMap);
  if(sts != 0) {
    Msg::Warning("- Face %i: failed to fill size map from background field",
                 gf->tag());
  }

  std::vector<std::array<double, 5> > singularityList;

  FieldManager *fields = gf->model()->getFields();
  fields->setBackgroundFieldId(0);

  int TEMP = CTX::instance()->mesh.algo2d;
  CTX::instance()->mesh.algo2d = ALGO_2D_PACK_PRLGRMS;

  int sbf = buildBackgroundField(gf->model(), gf->triangles, triangleDirections,
                                 sizeMap, singularityList, "guiding_field");

  CTX::instance()->mesh.algo2d = TEMP;

  if(sbf != 0) {
    Msg::Warning("failed to build background guiding field");
    return -1;
  }

  return 0;
#else
  return -1;
#endif
}

static void meshCompound(GFace *gf, bool verbose)
{
  discreteFace *df = dynamic_cast<discreteFace*>
    (gf->model()->getFaceByTag(gf->tag() + 100000));
  if(df) {
    df->deleteMesh();
  }
  else{
    df = new discreteFace(gf->model(), gf->tag() + 100000);
    gf->model()->add(df);
  }

  // reclassify the elements on the original surfaces? (This is nice but it will
  // perturb algorithms that depend on the parametrization after the mesh is
  // done)
  bool magic = (CTX::instance()->mesh.compoundClassify == 1);

  if(CTX::instance()->geom.copyMeshingMethod) {
    df->meshAttributes.method = gf->meshAttributes.method;
    df->meshAttributes.transfiniteArrangement =
      gf->meshAttributes.transfiniteArrangement;
    df->meshAttributes.transfiniteSmoothing =
      gf->meshAttributes.transfiniteSmoothing;
    df->meshAttributes.algorithm = gf->meshAttributes.algorithm;
  }

  std::vector<GFace *> triangles_tag;

  std::set<GEdge *, GEntityPtrLessThan> bnd, emb1;
  std::set<GVertex *, GEntityPtrLessThan> emb0;
  std::set<int> phys;
  for(std::size_t i = 0; i < gf->compound.size(); i++) {
    auto *c = (GFace *)gf->compound[i];
    df->triangles.insert(df->triangles.end(), c->triangles.begin(),
                         c->triangles.end());
    df->quadrangles.insert(df->quadrangles.end(), c->quadrangles.begin(),
                           c->quadrangles.end());
    df->mesh_vertices.insert(df->mesh_vertices.end(), c->mesh_vertices.begin(),
                             c->mesh_vertices.end());
    for(std::size_t j = 0; j < c->triangles.size(); j++)
      triangles_tag.push_back(c);
    std::vector<GEdge *> edges = c->edges();
    for(std::size_t j = 0; j < edges.size(); j++) {
      if(bnd.find(edges[j]) == bnd.end())
        bnd.insert(edges[j]);
      else
        bnd.erase(edges[j]);
    }
    // force retrieval of embedded entities
    std::vector<GVertex *> embv = c->getEmbeddedVertices(true);
    emb0.insert(embv.begin(), embv.end());
    std::vector<GEdge *> embe = c->getEmbeddedEdges(true);
    emb1.insert(embe.begin(), embe.end());

    if(magic) {
      c->triangles.clear();
      c->quadrangles.clear();
      c->mesh_vertices.clear();
    }
    c->compoundSurface = df;
    if(!magic) {
      phys.insert(c->physicals.begin(), c->physicals.end());
      c->physicals.clear();
    }
  }

  std::set<GEdge *, GEntityPtrLessThan> bndc;
  for(auto it = bnd.begin(); it != bnd.end(); it++) {
    GEdge *e = *it;
    if(e->compoundCurve)
      bndc.insert(e->compoundCurve);
    else
      bndc.insert(e);
  }
  std::vector<GEdge *> ed(bndc.begin(), bndc.end());
  df->set(ed);

  for(auto it = emb1.begin(); it != emb1.end(); it++) df->addEmbeddedEdge(*it);

  for(auto it = emb0.begin(); it != emb0.end(); it++)
    df->addEmbeddedVertex(*it);

  FieldManager *fields = gf->model()->getFields();
  int BGTAG = fields->getBackgroundField();
  Field *backgroundField = fields->get(BGTAG);

  if(df->createGeometry()) {
    Msg::Error("Could not create geometry of discrete surface %d (check "
               "orientation of input triangulations)",
               df->tag());
  }
  else {
    int scf = meshCompoundComputeCrossFieldWithHeatEquation(df);
    if(scf != 0) { return; }
  }

  if(!magic) {
    df->triangles.clear();
    df->quadrangles.clear();
    df->mesh_vertices.clear();
  }
  df->mesh(verbose);

  meshCompoundMakeQuads(df);

  if(fields->getBackgroundField() > 0 &&
     fields->getBackgroundField() != BGTAG) {
    fields->deleteField(fields->getBackgroundField());
    fields->setBackgroundField(backgroundField);
  }

  if(!magic) {
    df->physicals.clear();
    df->physicals.insert(df->physicals.end(), phys.begin(), phys.end());
    return;
  }

  for(std::size_t i = 0; i < df->mesh_vertices.size(); i++) {
    double u, v;
    df->mesh_vertices[i]->getParameter(0, u);
    df->mesh_vertices[i]->getParameter(1, v);
    double U, V;
    // search triangle in original mesh used to compute the parametrization
    int position = df->trianglePosition(u, v, U, V);
    if(position >= 0 && position < (int)triangles_tag.size()) {
      triangles_tag[position]->mesh_vertices.push_back(df->mesh_vertices[i]);
      df->mesh_vertices[i]->setEntity(triangles_tag[position]);
    }
    else {
      gf->mesh_vertices.push_back(df->mesh_vertices[i]);
      gf->mesh_vertices[i]->setEntity(gf);
    }
  }

  for(std::size_t i = 0; i < df->triangles.size(); i++) {
    MTriangle *t = df->triangles[i];
    bool found = false;
    for(int i = 0; i < 3; i++) {
      if(t->getVertex(i)->onWhat()->dim() == 2) {
        ((GFace *)t->getVertex(i)->onWhat())->triangles.push_back(t);
        found = true;
        break;
      }
    }
    if(!found) {
      gf->triangles.push_back(t); // FIXME could be better!
    }
  }

  for(std::size_t i = 0; i < df->quadrangles.size(); i++) {
    MQuadrangle *q = df->quadrangles[i];
    bool found = false;
    for(int i = 0; i < 4; i++) {
      if(q->getVertex(i)->onWhat()->dim() == 2) {
        ((GFace *)q->getVertex(i)->onWhat())->quadrangles.push_back(q);
        found = true;
        break;
      }
    }
    if(!found) {
      gf->quadrangles.push_back(q); // FIXME could be better!
    }
  }

  df->triangles.clear();
  df->quadrangles.clear();
  df->mesh_vertices.clear();
}
#endif

void GFace::mesh(bool verbose)
{
  if(CTX::instance()->debugSurface > 0 &&
     tag() != CTX::instance()->debugSurface) {
    meshStatistics.status = GFace::DONE;
    return;
  }

#if defined(HAVE_MESH)
  if(compound.size())
    meshAttributes.meshSizeFactor = CTX::instance()->mesh.compoundLcFactor;

  meshGFace mesher;
  mesher(this, verbose);

  if(compound.size()) { // Some faces are meshed together
    meshAttributes.meshSizeFactor = 1;

    orientMeshGFace orient;
    orient(this);
    if(compound[0] == this) { // I'm the one that makes the compound job
      bool ok = true;
      for(std::size_t i = 0; i < compound.size(); i++) {
        auto *gf = (GFace *)compound[i];
        ok &= (gf->meshStatistics.status == GFace::DONE);
      }
      if(!ok) { meshStatistics.status = GFace::PENDING; }
      else {
        meshCompound(this, verbose);
        meshStatistics.status = GFace::DONE;
        return;
      }
    }
  }
#endif
}

void GFace::moveToValidRange(SPoint2 &pt) const
{
  for(int i = 0; i < 2; i++) {
    if(periodic(i)) {
      Range<double> range = parBounds(i);
      double tol = 1e-6 * (range.high() - range.low());
      if(pt[i] < range.low() - tol) pt[i] += period(i);
      if(pt[i] > range.high() + tol) pt[i] -= period(i);
      if(pt[i] < range.low()) pt[i] = range.low();
      if(pt[i] > range.high()) pt[i] = range.high();
    }
  }
}

void GFace::relocateMeshVertices()
{
  for(std::size_t i = 0; i < mesh_vertices.size(); i++) {
    MVertex *v = mesh_vertices[i];
    double u0 = 0., u1 = 0.;
    if(v->getParameter(0, u0) && v->getParameter(1, u1)) {
      GPoint p = point(u0, u1);
      v->x() = p.x();
      v->y() = p.y();
      v->z() = p.z();
    }
  }
}

void GFace::setMeshMaster(GFace *master, const std::vector<double> &tfo)
{
  Msg::Info("Setting mesh master using transformation");

  // points and curves
  std::set<GVertex *> l_vertices;
  std::multimap<std::pair<GVertex *, GVertex *>, GEdge *> l_vtxToEdge;
  for(auto eIter = l_edges.begin(); eIter != l_edges.end(); ++eIter) {
    GVertex *v0 = (*eIter)->getBeginVertex();
    GVertex *v1 = (*eIter)->getEndVertex();
    if(v0 && v1) {
      l_vertices.insert(v0);
      l_vertices.insert(v1);
      l_vtxToEdge.insert(std::make_pair(std::make_pair(v0, v1), *eIter));
    }
  }
  for(auto eIter = embedded_edges.begin(); eIter != embedded_edges.end();
      ++eIter) {
    GVertex *v0 = (*eIter)->getBeginVertex();
    GVertex *v1 = (*eIter)->getEndVertex();
    if(v0 && v1) {
      l_vertices.insert(v0);
      l_vertices.insert(v1);
      l_vtxToEdge.insert(std::make_pair(std::make_pair(v0, v1), *eIter));
    }
  }
  l_vertices.insert(embedded_vertices.begin(), embedded_vertices.end());

  // master points and curves
  std::vector<GEdge *> const &m_edges = master->edges();
  std::set<GVertex *> m_vertices;
  std::multimap<std::pair<GVertex *, GVertex *>, GEdge *> m_vtxToEdge;
  for(auto eIter = m_edges.begin(); eIter != m_edges.end(); ++eIter) {
    GVertex *v0 = (*eIter)->getBeginVertex();
    GVertex *v1 = (*eIter)->getEndVertex();
    if(v0 && v1) {
      m_vertices.insert(v0);
      m_vertices.insert(v1);
      m_vtxToEdge.insert(std::make_pair(std::make_pair(v0, v1), *eIter));
    }
  }
  std::vector<GEdge *> const &m_embedded_edges = master->embeddedEdges();
  for(auto eIter = m_embedded_edges.begin(); eIter != m_embedded_edges.end();
      eIter++) {
    GVertex *v0 = (*eIter)->getBeginVertex();
    GVertex *v1 = (*eIter)->getEndVertex();
    if(v0 && v1) {
      m_vertices.insert(v0);
      m_vertices.insert(v1);
      m_vtxToEdge.insert(std::make_pair(std::make_pair(v0, v1), *eIter));
    }
  }
  std::set<GVertex *, GEntityPtrLessThan> m_embedded_vertices =
    master->embeddedVertices();
  m_vertices.insert(m_embedded_vertices.begin(), m_embedded_vertices.end());

  // check topological correspondence
  if(l_vertices.size() != m_vertices.size()) {
    Msg::Error(
      "Different number of points (%d vs %d) for periodic correspondence "
      "between surfaces %d and %d",
      l_vertices.size(), m_vertices.size(), master->tag(), tag());
    return;
  }
  if(l_vtxToEdge.size() != m_vtxToEdge.size()) {
    Msg::Error(
      "Different number of curves (%d vs %d) for periodic correspondence "
      "between surfaces %d and %d",
      l_vtxToEdge.size(), m_vtxToEdge.size(), master->tag(), tag());
    return;
  }

  // compute corresponding vertices
  std::map<GVertex *, GVertex *> gVertexCounterparts;
  for(auto mvIter = m_vertices.begin(); mvIter != m_vertices.end(); ++mvIter) {
    GVertex *m_vertex = *mvIter;

    SPoint3 xyzTfo((*mvIter)->x(), (*mvIter)->y(), (*mvIter)->z());
    xyzTfo.transform(tfo);

    GVertex *l_vertex = nullptr;

    double dist_min = 1.e22;
    for(auto lvIter = l_vertices.begin(); lvIter != l_vertices.end();
        ++lvIter) {
      SPoint3 xyz((*lvIter)->x(), (*lvIter)->y(), (*lvIter)->z());
      SVector3 dist = xyz - xyzTfo;
      dist_min = std::min(dist_min, dist.norm());
      if(dist.norm() < CTX::instance()->geom.tolerance * CTX::instance()->lc) {
        l_vertex = *lvIter;
        break;
      }
    }

    if(l_vertex == nullptr) {
      Msg::Error("No corresponding point %d for periodic connection of surface "
                 "%d to %d (min. distance = %g, tolerance = %g)",
                 m_vertex->tag(), master->tag(), tag(), dist_min,
                 CTX::instance()->geom.tolerance * CTX::instance()->lc);
      return;
    }
    gVertexCounterparts[l_vertex] = m_vertex;
  }

  if(gVertexCounterparts.size() != m_vertices.size()) {
    Msg::Error("Could not find all point correspondences for the periodic "
               "connection from surface %d to %d",
               master->tag(), tag());
    return;
  }

  // construct edge correspondence and update the edge masters
  std::map<GEdge *, std::pair<GEdge *, int> > gEdgeCounterparts;

  for(auto lv2eIter = l_vtxToEdge.begin(); lv2eIter != l_vtxToEdge.end();
      lv2eIter++) {
    std::pair<GVertex *, GVertex *> lPair = lv2eIter->first;
    GEdge *localEdge = lv2eIter->second;

    std::pair<GVertex *, GVertex *> forward(gVertexCounterparts[lPair.first],
                                            gVertexCounterparts[lPair.second]);
    int numf = m_vtxToEdge.count(forward);
    std::pair<GVertex *, GVertex *> backward(forward.second, forward.first);
    int numb = m_vtxToEdge.count(backward);
    int sign = 0;
    GEdge *masterEdge = nullptr;

    // unique matches
    if(!masterEdge && numf == 1 &&
       (numb == 0 || forward.first == forward.second)) {
      masterEdge = m_vtxToEdge.find(forward)->second;
      sign = 1;
    }
    if(!masterEdge && numb == 1 &&
       (numf == 0 || forward.first == forward.second)) {
      masterEdge = m_vtxToEdge.find(backward)->second;
      sign = -1;
    }

    // if there are multiple matches (when several curves have the same
    // begin/end points), we must compare the geometry: mid-points (general) or
    // transformed bounding boxes as a fallback (ok for translations or
    // rotations by n*pi/2)
    SBoundingBox3d localbb = localEdge->bounds(true);
    double tol = localbb.diag() * 1e-3;
    Range<double> localr = localEdge->parBounds(0);
    GPoint localp = localEdge->point(0.5 * (localr.low() + localr.high()));
    if(!masterEdge && numf) {
      auto ret = m_vtxToEdge.equal_range(forward);
      for(auto it = ret.first; it != ret.second; it++) {
        GEdge *ge = it->second;
        Range<double> masterr = ge->parBounds(0);
        GPoint masterp = ge->point(0.5 * (masterr.low() + masterr.high()));
        if(localp.succeeded() && masterp.succeeded()) {
          SPoint3 p1(localp.x(), localp.y(), localp.z());
          SPoint3 p2(masterp.x(), masterp.y(), masterp.z());
          p2.transform(tfo);
          if(p1.distance(p2) < tol) {
            masterEdge = ge;
            sign = 1;
            break;
          }
        }
        SBoundingBox3d masterbb = ge->bounds(true);
        masterbb.transform(tfo);
        if(masterbb.min().distance(localbb.min()) < tol &&
           masterbb.max().distance(localbb.max()) < tol) {
          masterEdge = ge;
          sign = 1;
          break;
        }
      }
    }
    if(!masterEdge && numb) {
      auto ret = m_vtxToEdge.equal_range(backward);
      for(auto it = ret.first; it != ret.second; it++) {
        GEdge *ge = it->second;
        Range<double> masterr = ge->parBounds(0);
        GPoint masterp = ge->point(0.5 * (masterr.low() + masterr.high()));
        if(localp.succeeded() && masterp.succeeded()) {
          SPoint3 p1(localp.x(), localp.y(), localp.z());
          SPoint3 p2(masterp.x(), masterp.y(), masterp.z());
          p2.transform(tfo);
          if(p1.distance(p2) < tol) {
            masterEdge = ge;
            sign = -1;
            break;
          }
        }
        SBoundingBox3d masterbb = ge->bounds(true);
        masterbb.transform(tfo);
        if(masterbb.min().distance(localbb.min()) < tol &&
           masterbb.max().distance(localbb.max()) < tol) {
          masterEdge = ge;
          sign = -1;
          break;
        }
      }
    }

    if(!masterEdge) {
      Msg::Error("Could not find counterpart of curve %d with end points %d %d "
                 "(corresponding to curve with end points %d %d) in surface %d",
                 localEdge->tag(), lPair.first->tag(), lPair.second->tag(),
                 forward.first->tag(), forward.second->tag(), master->tag());
      return;
    }

    if(masterEdge->getMeshMaster() != localEdge) {
      localEdge->setMeshMaster(masterEdge, tfo);
      Msg::Info("Setting curve master %d - %d", localEdge->tag(),
                masterEdge->tag());
    }
    gEdgeCounterparts[localEdge] = std::make_pair(masterEdge, sign);
  }

  // complete the information at the edge level
  edgeCounterparts = gEdgeCounterparts;
  vertexCounterparts = gVertexCounterparts;
  GEntity::setMeshMaster(master, tfo);
}

inline double myAngle(const SVector3 &a, const SVector3 &b, const SVector3 &d)
{
  double const cosTheta = dot(a, b);
  double const sinTheta = dot(crossprod(a, b), d);
  return std::atan2(sinTheta, cosTheta);
}

struct myPlane {
  SPoint3 p;
  SVector3 n;
  double a;
  // nx x + ny y + nz z + a = 0
  myPlane(const SPoint3 &_p, const SVector3 &_n) : p(_p), n(_n)
  {
    n.normalize();
    a = -(n.x() * p.x() + n.y() * p.y() + n.z() * p.z());
  }
  double eval(double x, double y, double z)
  {
    return n.x() * x + n.y() * y + n.z() * z + a;
  }
};

struct myLine {
  SPoint3 p;
  SVector3 t;
  myLine() : p(0, 0, 0), t(0, 0, 1) {}
  myLine(myPlane &p1, myPlane &p2)
  {
    t = crossprod(p1.n, p2.n);
    if(t.norm() == 0.0) { Msg::Error("parallel planes do not intersect"); }
    else
      t.normalize();
    // find a point, assume z = 0
    double a[2][2] = {{p1.n.x(), p1.n.y()}, {p2.n.x(), p2.n.y()}};
    double b[2] = {-p1.a, -p2.a}, x[2];
    if(!sys2x2(a, b, x)) {
      // assume x = 0
      double az[2][2] = {{p1.n.y(), p1.n.z()}, {p2.n.y(), p2.n.z()}};
      double bz[2] = {-p1.a, -p2.a};
      if(!sys2x2(az, bz, x)) {
        // assume y = 0
        double ay[2][2] = {{p1.n.x(), p1.n.z()}, {p2.n.x(), p2.n.z()}};
        double by[2] = {-p1.a, -p2.a};
        if(!sys2x2(ay, by, x)) {
          Msg::Error("parallel planes do not intersect");
        }
        else {
          p = SPoint3(x[0], 0., x[1]);
        }
      }
      else {
        p = SPoint3(0., x[0], x[1]);
      }
    }
    else {
      p = SPoint3(x[0], x[1], 0.);
    }
  }
  SPoint3 orthogonalProjection(SPoint3 &a)
  {
    // (x - a) * t = 0 -->
    // x = p + u t --> (p + ut - a) * t = 0 --> u = (a-p) * t
    const double u = dot(a - p, t);
    return SPoint3(p.x() + t.x() * u, p.y() + t.y() * u, p.z() + t.z() * u);
  }
};

void GFace::setMeshMaster(GFace *master, const std::map<int, int> &edgeCopies)
{
  std::map<GVertex *, GVertex *> vs2vt;

  for(auto it = l_edges.begin(); it != l_edges.end(); ++it) {
    // slave edge
    GEdge *le = *it;

    int sign = 1;
    auto adnksd = edgeCopies.find(le->tag());
    int source_e;
    if(adnksd != edgeCopies.end())
      source_e = adnksd->second;
    else {
      sign = -1;
      adnksd = edgeCopies.find(-(*it)->tag());
      if(adnksd != edgeCopies.end())
        source_e = adnksd->second;
      else {
        Msg::Error("Could not find curve counterpart %d in slave surface %d",
                   (*it)->tag(), master->tag());
        return;
      }
    }

    // master edge
    GEdge *me = master->model()->getEdgeByTag(abs(source_e));

    if(le->getBeginVertex() && le->getEndVertex() && me->getBeginVertex() &&
       me->getEndVertex()) {
      if(source_e * sign > 0) {
        vs2vt[me->getBeginVertex()] = le->getBeginVertex();
        vs2vt[me->getEndVertex()] = le->getEndVertex();
      }
      else {
        vs2vt[me->getBeginVertex()] = le->getEndVertex();
        vs2vt[me->getEndVertex()] = le->getBeginVertex();
      }
    }
  }

  // --- find out the transformation

  bool translation = true;
  SVector3 DX;

  int count = 0;
  for(auto it = vs2vt.begin(); it != vs2vt.end(); ++it) {
    GVertex *vs = it->first;
    GVertex *vt = it->second;
    if(count == 0)
      DX = SVector3(vt->x() - vs->x(), vt->y() - vs->y(), vt->z() - vs->z());
    else {
      SVector3 DX2(vt->x() - vs->x(), vt->y() - vs->y(), vt->z() - vs->z());
      SVector3 DDX(DX2 - DX);
      if(DDX.norm() > DX.norm() * 1.e-5) translation = false;
    }
    count++;
  }

  std::vector<double> tfo(16);

  if(translation) {
    Msg::Info(
      "Periodic mesh translation found between %d and %d: dx = (%g,%g,%g)",
      tag(), master->tag(), DX.x(), DX.y(), DX.z());

    for(size_t i = 0; i < 16; i++) tfo[i] = 0;
    for(size_t i = 0; i < 4; i++) tfo[i * 4 + i] = 1;
    tfo[3] = DX.x();
    tfo[7] = DX.y();
    tfo[11] = DX.z();
  }

  else {
    bool rotation = false;
    myLine LINE;
    double ANGLE = 0;

    count = 0;
    rotation = true;
    std::vector<SPoint3> mps, mpt;
    for(auto it = vs2vt.begin(); it != vs2vt.end(); ++it) {
      GVertex *vs = it->first;
      GVertex *vt = it->second;
      mps.push_back(SPoint3(vs->x(), vs->y(), vs->z()));
      mpt.push_back(SPoint3(vt->x(), vt->y(), vt->z()));
    }
    mean_plane mean_source, mean_target;
    computeMeanPlaneSimple(mps, mean_source);
    computeMeanPlaneSimple(mpt, mean_target);

    myPlane PLANE_SOURCE(SPoint3(mean_source.x, mean_source.y, mean_source.z),
                         SVector3(mean_source.a, mean_source.b, mean_source.c));
    myPlane PLANE_TARGET(SPoint3(mean_target.x, mean_target.y, mean_target.z),
                         SVector3(mean_target.a, mean_target.b, mean_target.c));

    LINE = myLine(PLANE_SOURCE, PLANE_TARGET);

    // LINE is the axis of rotation
    // let us compute the angle of rotation
    count = 0;
    for(auto it = vs2vt.begin(); it != vs2vt.end(); ++it) {
      GVertex *vs = it->first;
      GVertex *vt = it->second;
      // project both points on the axis: that should be the same point !
      SPoint3 ps = SPoint3(vs->x(), vs->y(), vs->z());
      SPoint3 pt = SPoint3(vt->x(), vt->y(), vt->z());
      SPoint3 p_ps = LINE.orthogonalProjection(ps);
      SPoint3 p_pt = LINE.orthogonalProjection(pt);
      SVector3 dist1 = ps - pt;
      SVector3 dist2 = p_ps - p_pt;
      if(dist1.norm() > CTX::instance()->geom.tolerance) {
        if(dist2.norm() > 1.e-8 * dist1.norm()) { rotation = false; }
        SVector3 t1 = ps - p_ps;
        SVector3 t2 = pt - p_pt;
        if(t1.norm() > 1.e-8 * dist1.norm()) {
          if(count == 0)
            ANGLE = myAngle(t1, t2, LINE.t);
          else {
            double ANGLE2 = myAngle(t1, t2, LINE.t);
            if(fabs(ANGLE2 - ANGLE) > 1.e-8) { rotation = false; }
          }
          count++;
        }
      }
    }

    if(rotation) {
      Msg::Info("Periodic mesh rotation found: axis (%g,%g,%g) point (%g %g "
                "%g) angle %g",
                LINE.t.x(), LINE.t.y(), LINE.t.z(), LINE.p.x(), LINE.p.y(),
                LINE.p.z(), ANGLE * 180 / M_PI);

      double ux = LINE.t.x();
      double uy = LINE.t.y();
      double uz = LINE.t.z();

      tfo[0 * 4 + 0] = cos(ANGLE) + ux * ux * (1. - cos(ANGLE));
      tfo[0 * 4 + 1] = ux * uy * (1. - cos(ANGLE)) - uz * sin(ANGLE);
      tfo[0 * 4 + 2] = ux * uz * (1. - cos(ANGLE)) + uy * sin(ANGLE);

      tfo[1 * 4 + 0] = ux * uy * (1. - cos(ANGLE)) + uz * sin(ANGLE);
      tfo[1 * 4 + 1] = cos(ANGLE) + uy * uy * (1. - cos(ANGLE));
      tfo[1 * 4 + 2] = uy * uz * (1. - cos(ANGLE)) - ux * sin(ANGLE);

      tfo[2 * 4 + 0] = ux * uz * (1. - cos(ANGLE)) - uy * sin(ANGLE);
      tfo[2 * 4 + 1] = uy * uz * (1. - cos(ANGLE)) + ux * sin(ANGLE);
      tfo[2 * 4 + 2] = cos(ANGLE) + uz * uz * (1. - cos(ANGLE));

      double origin[3] = {LINE.p.x(), LINE.p.y(), LINE.p.z()};

      for(int i = 0; i < 3; i++) tfo[i * 4 + 3] = origin[i];
      for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++) tfo[i * 4 + 3] -= tfo[i * 4 + j] * origin[j];
      for(int i = 0; i < 3; i++) tfo[12 + i] = 0;
      tfo[15] = 1;
    }
    else {
      Msg::Error("Only rotations or translations can currently be computed "
                 "automatically for periodic surfaces: surface %d not meshed",
                 tag());
      return;
    }
  }

  // --- now check and encode the transformation
  // --- including for edges and vertices

  setMeshMaster(master, tfo);
}

void GFace::addElement(MElement *e)
{
  switch(e->getType()) {
  case TYPE_TRI: addTriangle(reinterpret_cast<MTriangle *>(e)); break;
  case TYPE_QUA: addQuadrangle(reinterpret_cast<MQuadrangle *>(e)); break;
  case TYPE_POLYG: addPolygon(reinterpret_cast<MPolygon *>(e)); break;
  default:
    Msg::Error("Trying to add unsupported element in surface %d", tag());
  }
}

void GFace::removeElement(MElement *e, bool del)
{
  switch(e->getType()) {
  case TYPE_TRI: {
    auto it = std::find(triangles.begin(), triangles.end(),
                        reinterpret_cast<MTriangle *>(e));
    if(it != triangles.end()) {
      triangles.erase(it);
      if(del) delete e;
    }
  } break;
  case TYPE_QUA: {
    auto it = std::find(quadrangles.begin(), quadrangles.end(),
                        reinterpret_cast<MQuadrangle *>(e));
    if(it != quadrangles.end()) {
      quadrangles.erase(it);
      if(del) delete e;
    }
  } break;
  case TYPE_POLYG: {
    auto it = std::find(polygons.begin(), polygons.end(),
                        reinterpret_cast<MPolygon *>(e));
    if(it != polygons.end()) {
      polygons.erase(it);
      if(del) delete e;
    }
  } break;
  default:
    Msg::Error("Trying to remove unsupported element in surface %d", tag());
  }
}

void GFace::removeElements(bool del)
{
  if(del) {
    for(auto e : triangles) delete e;
    for(auto e : quadrangles) delete e;
    for(auto e : polygons) delete e;
  }
  triangles.clear();
  quadrangles.clear();
  polygons.clear();
}

bool GFace::reorder(const int elementType,
                    const std::vector<std::size_t> &ordering)
{
  if(triangles.size() != 0) {
    if(triangles.front()->getTypeForMSH() == elementType) {
      if(ordering.size() != triangles.size()) return false;

      for(auto it = ordering.begin(); it != ordering.end(); ++it) {
        if(*it >= triangles.size()) return false;
      }

      std::vector<MTriangle *> newTrianglesOrder(triangles.size());
      for(std::size_t i = 0; i < ordering.size(); i++) {
        newTrianglesOrder[i] = triangles[ordering[i]];
      }
      triangles = std::move(newTrianglesOrder);
      return true;
    }
  }

  if(quadrangles.size() != 0) {
    if(quadrangles.front()->getTypeForMSH() == elementType) {
      if(ordering.size() != quadrangles.size()) return false;

      for(auto it = ordering.begin(); it != ordering.end(); ++it) {
        if(*it >= quadrangles.size()) return false;
      }

      std::vector<MQuadrangle *> newQuadranglesOrder(quadrangles.size());
      for(std::size_t i = 0; i < ordering.size(); i++) {
        newQuadranglesOrder[i] = quadrangles[ordering[i]];
      }
      quadrangles = std::move(newQuadranglesOrder);
      return true;
    }
  }

  if(polygons.size() != 0) {
    if(polygons.front()->getTypeForMSH() == elementType) {
      if(ordering.size() != polygons.size()) return false;

      for(auto it = ordering.begin(); it != ordering.end(); ++it) {
        if(*it >= polygons.size()) return false;
      }

      std::vector<MPolygon *> newPolygonsOrder(polygons.size());
      for(std::size_t i = 0; i < ordering.size(); i++) {
        newPolygonsOrder[i] = polygons[ordering[i]];
      }
      polygons = std::move(newPolygonsOrder);
      return true;
    }
  }

  return false;
}

void GFace::alignElementsWithMaster()
{
  GEntity *master = getMeshMaster();

  if(master != this) {
    std::set<MFace, MFaceLessThan> srcFaces;

    for(std::size_t i = 0; i < master->getNumMeshElements(); i++) {
      MElement *face = master->getMeshElement(i);
      std::vector<MVertex *> vtcs;
      vtcs.reserve(face->getNumVertices());
      for(std::size_t j = 0; j < face->getNumVertices(); j++) {
        vtcs.push_back(face->getVertex(j));
      }
      srcFaces.insert(MFace(vtcs));
    }

    for(std::size_t i = 0; i < getNumMeshElements(); i++) {
      MElement *face = getMeshElement(i);
      std::vector<MVertex *> vtcs;
      for(std::size_t j = 0; j < face->getNumVertices(); j++) {
        MVertex *tv = face->getVertex(j);
        auto cIter = correspondingVertices.find(tv);
        if(cIter != correspondingVertices.end()) vtcs.push_back(cIter->second);
      }

      MFace mf(vtcs);

      auto sIter = srcFaces.find(mf);

      if(sIter == srcFaces.end()) continue;

      MFace of = *sIter;

      int orientation;
      bool swap;
      mf.computeCorrespondence(of, orientation, swap);

      switch(face->getNumVertices()) {
      case 3: {
        auto *tri = dynamic_cast<MTriangle *>(face);
        if(tri) tri->reorient(orientation, swap);
        break;
      }
      case 4: {
        auto *qua = dynamic_cast<MQuadrangle *>(face);
        if(qua) qua->reorient(orientation, swap);
        break;
      }
      }
    }
  }
}

bool GFace::isFullyDiscrete()
{
  if(geomType() != GEntity::DiscreteSurface) return false;
  auto *df = dynamic_cast<discreteFace *>(this);
  if(df && df->haveParametrization()) return false;
  std::vector<GEdge *> e = edges();
  for(std::size_t i = 0; i < e.size(); i++) {
    if(e[i]->geomType() != GEntity::DiscreteCurve) return false;
    auto *de = dynamic_cast<discreteEdge *>(e[i]);
    if(de && de->haveParametrization()) return false;
  }
  return true;
}
