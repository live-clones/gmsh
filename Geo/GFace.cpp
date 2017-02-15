// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

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
#include "discreteFace.h"

#if defined(HAVE_MESH)
#include "meshGFace.h"
#include "meshGFaceOptimize.h"
#include "meshGFaceLloyd.h"
#include "BackgroundMeshTools.h"
#endif

#if defined(HAVE_BFGS)
#include "stdafx.h"
#include "optimization.h"
#endif

#define SQU(a)      ((a)*(a))

GFace::GFace(GModel *model, int tag)
  : GEntity(model, tag), r1(0), r2(0), compound(0), va_geom_triangles(0)
{
  meshStatistics.status = GFace::PENDING;
  resetMeshAttributes();
}

GFace::~GFace()
{
  std::list<GEdge*>::iterator it = l_edges.begin();
  while (it != l_edges.end()){
    (*it)->delFace(this);
    ++it;
  }

  if(va_geom_triangles)
    delete va_geom_triangles;

  deleteMesh();
}

int GFace::getCurvatureControlParameter() const
{
  std::map<int,int>::iterator it =
    CTX::instance()->mesh.curvature_control_per_face.find(tag());
  return it == CTX::instance()->mesh.curvature_control_per_face.end() ?
    CTX::instance()->mesh.minCircPoints : it->second ;
}

void GFace::setCurvatureControlParameter(int n)
{
  CTX::instance()->mesh.curvature_control_per_face[tag()] = n;
}

int GFace::getMeshingAlgo() const
{
  std::map<int,int>::iterator it = CTX::instance()->mesh.algo2d_per_face.find(tag());
  return it == CTX::instance()->mesh.algo2d_per_face.end() ?
    CTX::instance()->mesh.algo2d : it->second ;
}

void GFace::setMeshingAlgo(int algo)
{
  CTX::instance()->mesh.algo2d_per_face[tag()] = algo;
}

void GFace::delFreeEdge(GEdge *e)
{
  // delete the edge from the edge list and the orientation list
  std::list<GEdge*>::iterator ite = l_edges.begin();
  std::list<int>::iterator itd = l_dirs.begin();
  while(ite != l_edges.end()){
    if(e == *ite){
      Msg::Debug("Erasing edge %d from edge list in face %d", e->tag(), tag());
      l_edges.erase(ite);
      if(itd != l_dirs.end()) l_dirs.erase(itd);
      break;
    }
    ite++;
    if(itd != l_dirs.end()) itd++;
  }

  // delete the edge from the edge loops
  for(std::list<GEdgeLoop>::iterator it = edgeLoops.begin();
      it != edgeLoops.end(); it++){
    for(GEdgeLoop::iter it2 = it->begin(); it2 != it->end(); it2++){
      if(e == it2->ge){
        Msg::Debug("Erasing edge %d from edge loop in face %d", e->tag(), tag());
        it->erase(it2);
        break;
      }
    }
  }
}

void GFace::replaceEdge(GEdge *e1, GEdge *e2)
{
  std::list<GEdge*>::iterator ite = l_edges.begin();
  std::list<GEdge*> newlist;
  newlist.clear();
  while(ite != l_edges.end()){
    if(e1 == *ite){
      newlist.push_back(e2);
    }
    else{
      newlist.push_back((*ite));
    }
    ite++;
  }
  l_edges = newlist;
}

void GFace::deleteMesh()
{
  for(unsigned int i = 0; i < mesh_vertices.size(); i++) delete mesh_vertices[i];
  mesh_vertices.clear();
  transfinite_vertices.clear();
  for(unsigned int i = 0; i < triangles.size(); i++) delete triangles[i];
  triangles.clear();
  for(unsigned int i = 0; i < quadrangles.size(); i++) delete quadrangles[i];
  quadrangles.clear();
  for(unsigned int i = 0; i < polygons.size(); i++) delete polygons[i];
  polygons.clear();
  deleteVertexArrays();
  model()->destroyMeshCaches();
}

unsigned int GFace::getNumMeshElements()
{
  return triangles.size() + quadrangles.size() + polygons.size();
}

unsigned int GFace::getNumMeshParentElements()
{
  unsigned int n = 0;
  for(unsigned int i = 0; i < polygons.size(); i++)
    if(polygons[i]->ownsParent())
      n++;
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
    if(triangles.empty()) return 0; // msvc would throw an exception
    return reinterpret_cast<MElement *const *>(&triangles[0]);
  case 1:
    if(quadrangles.empty()) return 0; // msvc would throw an exception
    return reinterpret_cast<MElement *const *>(&quadrangles[0]);
  case 2:
    if(polygons.empty()) return 0;
    return reinterpret_cast<MElement *const *>(&polygons[0]);
  }
  return 0;
}

MElement *GFace::getMeshElement(unsigned int index)
{
  if(index < triangles.size())
    return triangles[index];
  else if(index < triangles.size() + quadrangles.size())
    return quadrangles[index - triangles.size()];
  else if(index < triangles.size() + quadrangles.size() + polygons.size())
    return polygons[index - triangles.size() - quadrangles.size()];
  return 0;
}

void GFace::resetMeshAttributes()
{
  meshAttributes.recombine = 0;
  meshAttributes.recombineAngle = 45.;
  meshAttributes.method = MESH_UNSTRUCTURED;
  meshAttributes.transfiniteArrangement = 0;
  meshAttributes.transfiniteSmoothing = -1;
  meshAttributes.extrude = 0;
  meshAttributes.reverseMesh = false;
  meshAttributes.meshSize = MAX_LC;
}

SBoundingBox3d GFace::bounds() const
{
  SBoundingBox3d res;
  if(geomType() != DiscreteSurface){
    std::list<GEdge*>::const_iterator it = l_edges.begin();
    for(; it != l_edges.end(); it++)
      res += (*it)->bounds();
  }
  else{
    for(unsigned int i = 0; i < mesh_vertices.size(); i++)
      res += mesh_vertices[i]->point();
  }
  return res;
}

SOrientedBoundingBox GFace::getOBB()
{
  if (!_obb) {
    std::vector<SPoint3> vertices;
    if(getNumMeshVertices() > 0) {
      int N = getNumMeshVertices();
      for (int i = 0; i < N; i++) {
        MVertex* mv = getMeshVertex(i);
        vertices.push_back(mv->point());
      }
      std::list<GEdge*> eds = edges();
      for(std::list<GEdge*>::iterator ed = eds.begin(); ed != eds.end(); ed++) {
        int N2 = (*ed)->getNumMeshVertices();
        for (int i = 0; i < N2; i++) {
          MVertex* mv = (*ed)->getMeshVertex(i);
          vertices.push_back(mv->point());
        }
        // Don't forget to add the first and last vertices...
        SPoint3 pt1((*ed)->getBeginVertex()->x(),
                    (*ed)->getBeginVertex()->y(),
                    (*ed)->getBeginVertex()->z());
        SPoint3 pt2((*ed)->getEndVertex()->x(),
                    (*ed)->getEndVertex()->y(),
                    (*ed)->getEndVertex()->z());
        vertices.push_back(pt1);
        vertices.push_back(pt2);
      }
    }
    else if(buildSTLTriangulation()) {
      for (unsigned int i = 0; i < stl_vertices.size(); i++){
        GPoint p = point(stl_vertices[i]);
        vertices.push_back(SPoint3(p.x(), p.y(), p.z()));
      }
    }
    else {
      // Fallback, if we can't make a STL triangulation of the
      // surface, use its edges..
      std::list<GEdge*> b_edges = edges();
      int N = 10;
      for (std::list<GEdge*>::iterator b_edge = b_edges.begin();
           b_edge != b_edges.end(); b_edge++) {
        Range<double> tr = (*b_edge)->parBounds(0);
        for (int j = 0; j < N; j++) {
          double t = tr.low() + (double)j / (double)(N - 1) * (tr.high() - tr.low());
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

surface_params GFace::getSurfaceParams() const
{
  surface_params p;
  p.radius = p.radius2 = p.height = p.cx = p.cy = p.cz = 0.;
  Msg::Error("Empty surface parameters for this type of surface");
  return p;
}

std::vector<MVertex*> GFace::getEmbeddedMeshVertices() const
{
  std::set<MVertex*> tmp;
  for(std::list<GEdge *>::const_iterator it = embedded_edges.begin();
      it != embedded_edges.end(); it++){
    tmp.insert((*it)->mesh_vertices.begin(), (*it)->mesh_vertices.end());
    tmp.insert((*it)->getBeginVertex()->mesh_vertices.begin(),
               (*it)->getBeginVertex()->mesh_vertices.end());
    tmp.insert((*it)->getEndVertex()->mesh_vertices.begin(),
               (*it)->getEndVertex()->mesh_vertices.end());
  }
  for(std::list<GVertex *>::const_iterator it = embedded_vertices.begin();
      it != embedded_vertices.end(); it++){
    tmp.insert((*it)->mesh_vertices.begin(), (*it)->mesh_vertices.end());
  }
  std::vector<MVertex*> res;
  res.insert(res.end(), tmp.begin(), tmp.end());
  return res;
}

std::list<GVertex*> GFace::vertices() const
{
  std::set<GVertex*> v;
  for(std::list<GEdge*>::const_iterator it = l_edges.begin();
      it != l_edges.end(); ++it){
    GVertex *v1 = (*it)->getBeginVertex();
    if(v1) v.insert(v1);
    GVertex *v2 = (*it)->getEndVertex();
    if(v2) v.insert(v2);
  }
  std::list<GVertex*> res;
  res.insert(res.begin(), v.begin(), v.end());
  return res;
}

void GFace::setVisibility(char val, bool recursive)
{
  GEntity::setVisibility(val);
  if(recursive){
    for (std::list<GEdge*>::iterator it = l_edges.begin(); it != l_edges.end(); ++it)
      (*it)->setVisibility(val, recursive);
  }
}

std::string GFace::getAdditionalInfoString()
{
  std::ostringstream sstream;
  if(l_edges.size() > 20){
    sstream << "{" << l_edges.front()->tag() << ",...," << l_edges.back()->tag() << "}";
  }
  else if(l_edges.size()){
    sstream << "{";
    for(std::list<GEdge*>::iterator it = l_edges.begin(); it != l_edges.end(); ++it){
      if(it != l_edges.begin()) sstream << " ";
      sstream << (*it)->tag();
    }
    sstream << "}";
  }

  if(meshAttributes.recombine)
    sstream << " recombined";
  if(meshAttributes.method == MESH_TRANSFINITE)
    sstream << " transfinite";
  if(meshAttributes.extrude)
    sstream << " extruded";
  if(meshAttributes.reverseMesh)
    sstream << " reverse";

  return sstream.str();
}

void GFace::writeGEO(FILE *fp)
{
  if(geomType() == DiscreteSurface) return;

  std::list<GEdge*> edg = edges();
  std::list<int> dir = orientations();
  if(edg.size() && dir.size() == edg.size()){
    std::vector<int> num, ori;
    for(std::list<GEdge*>::iterator it = edg.begin(); it != edg.end(); it++)
      num.push_back((*it)->tag());
    for(std::list<int>::iterator it = dir.begin(); it != dir.end(); it++)
      ori.push_back((*it) > 0 ? 1 : -1);
    fprintf(fp, "Line Loop(%d) = ", tag());
    for(unsigned int i = 0; i < num.size(); i++){
      if(i)
        fprintf(fp, ", %d", num[i] * ori[i]);
      else
        fprintf(fp, "{%d", num[i] * ori[i]);
    }
    fprintf(fp, "};\n");
    if(geomType() == GEntity::Plane){
      fprintf(fp, "Plane Surface(%d) = {%d};\n", tag(), tag());
    }
    else if(edg.size() == 3 || edg.size() == 4){
      fprintf(fp, "Surface(%d) = {%d};\n", tag(), tag());
    }
    else{
      Msg::Error("Skipping surface %d in export", tag());
    }
  }

  for(std::list<GEdge*>::iterator it = embedded_edges.begin();
      it != embedded_edges.end(); it++)
    fprintf(fp, "Line {%d} In Surface {%d};\n", (*it)->tag(), tag());

  for(std::list<GVertex*>::iterator it = embedded_vertices.begin();
      it != embedded_vertices.end(); it++)
    fprintf(fp, "Point {%d} In Surface {%d};\n", (*it)->tag(), tag());

  if(meshAttributes.method == MESH_TRANSFINITE){
    fprintf(fp, "Transfinite Surface {%d}", tag());
    if(meshAttributes.corners.size()){
      fprintf(fp, " = {");
      for(unsigned int i = 0; i < meshAttributes.corners.size(); i++){
        if(i) fprintf(fp, ",");
        fprintf(fp, "%d", meshAttributes.corners[i]->tag());
      }
      fprintf(fp, "}");
    }
    fprintf(fp, ";\n");
  }

  if(meshAttributes.recombine)
    fprintf(fp, "Recombine Surface {%d};\n", tag());

  if(meshAttributes.reverseMesh)
    fprintf(fp, "Reverse Surface {%d};\n", tag());
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
    std::list<GEdge*> edg = edges();
    for(std::list<GEdge*>::const_iterator ite = edg.begin(); ite != edg.end(); ite++){
      const GEdge *e = *ite;
      if(e->geomType() == GEntity::DiscreteCurve ||
         e->geomType() == GEntity::BoundaryLayerCurve){
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
    if(pts.size() >= 3){
      SVector3 d01(pts[0], pts[1]);
      for(unsigned int i = 2; i < pts.size(); i++){
        SVector3 d0i(pts[0], pts[i]);
        SVector3 n = crossprod(d01, d0i);
        if(norm(n) > 1e-12){
          res[0] = n.x(); res[1] = n.y(); res[2] = n.z();
          xm = pts[0].x(); ym = pts[0].y(); zm = pts[0].z();
          ok = true;
          break;
        }
      }
    }
    if(ok){
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

  std::list<GVertex*> verts = vertices();
  std::list<GVertex*>::const_iterator itv = verts.begin();
  for(; itv != verts.end(); itv++){
    const GVertex *v = *itv;
    pts.push_back(SPoint3(v->x(), v->y(), v->z()));
  }

  bool colinear = (pts.size() < 3);
  if(pts.size() > 2){
    SVector3 d01(pts[0], pts[1]), d02(pts[0], pts[2]);
    if(norm(crossprod(d01, d02)) < 1e-12) colinear = true;
  }

  if(colinear){
    Msg::Debug("Adding edge points (%d) to compute mean plane of face %d", pts.size(), tag());
    std::list<GEdge*> edg = edges();
    for(std::list<GEdge*>::const_iterator ite = edg.begin(); ite != edg.end(); ite++){
      const GEdge *e = *ite;
      if(e->mesh_vertices.size() > 1){
        for(unsigned int i = 0; i < e->mesh_vertices.size(); i++)
          pts.push_back(e->mesh_vertices[i]->point());
      }
      else{
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

void GFace::computeMeanPlane(const std::vector<MVertex*> &points)
{
  std::vector<SPoint3> pts;
  for(unsigned int i = 0; i < points.size(); i++)
    pts.push_back(SPoint3(points[i]->x(), points[i]->y(), points[i]->z()));
  computeMeanPlane(pts);
}

void GFace::computeMeanPlane(const std::vector<SPoint3> &points)
{
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
  if(fabs(svd[0]) < fabs(svd[1]) && fabs(svd[0]) < fabs(svd[2]))
    min = 0;
  else if(fabs(svd[1]) < fabs(svd[0]) && fabs(svd[1]) < fabs(svd[2]))
    min = 1;
  else
    min = 2;
  res[0] = V(0, min);
  res[1] = V(1, min);
  res[2] = V(2, min);
  norme(res);

  double ex[3], t1[3], t2[3];

  // check coherence of results for non-plane surfaces
  if(geomType() != Plane && geomType() != DiscreteSurface) {
    double res2[3], c[3], cosc, sinc, angplan;
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
    // Warning: the rest of the code assumes res = t2 x t1, not t1 x t2 (WTF?)
    prodve(t2, t1, res2);
    norme(res2);
    prodve(res, res2, c);
    prosca(res, res2, &cosc);
    sinc = sqrt(c[0] * c[0] + c[1] * c[1] + c[2] * c[2]);
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
  Msg::Debug("Plane  : (%g x + %g y + %g z = %g)",
             meanPlane.a, meanPlane.b, meanPlane.c, meanPlane.d);
  Msg::Debug("Normal : (%g , %g , %g )",
             meanPlane.a, meanPlane.b, meanPlane.c);
  Msg::Debug("t1     : (%g , %g , %g )", t1[0], t1[1], t1[2]);
  Msg::Debug("t2     : (%g , %g , %g )", t2[0], t2[1], t2[2]);
  Msg::Debug("pt     : (%g , %g , %g )",
             meanPlane.x, meanPlane.y, meanPlane.z);

  //check coherence for plane surfaces
  if(geomType() == Plane) {
    SBoundingBox3d bb = bounds();
    double lc = norm(SVector3(bb.max(), bb.min()));
    std::list<GVertex*> verts = vertices();
    std::list<GVertex*>::const_iterator itv = verts.begin();
    for(; itv != verts.end(); itv++){
      const GVertex *v = *itv;
      double d = meanPlane.a * v->x() + meanPlane.b * v->y() +
        meanPlane.c * v->z() - meanPlane.d;
      if(fabs(d) > lc * 1.e-3) {
        Msg::Debug("Plane surface %d (%gx+%gy+%gz=%g) is not plane!",
                   tag(), meanPlane.a, meanPlane.b, meanPlane.c, meanPlane.d);
        Msg::Debug("Control point %d = (%g,%g,%g), val=%g",
                   v->tag(), v->x(), v->y(), v->z(), d);
        break;
      }
    }
  }
}

void GFace::getMeanPlaneData(double VX[3], double VY[3],
                             double &x, double &y, double &z) const
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
    for(int j = 0; j < 3; j++)
      plan[i][j] = meanPlane.plan[i][j];
}

void GFace::computeMeshSizeFieldAccuracy(double &avg,double &max_e, double &min_e,
					 int &nE, int &GS)
{
#if defined(HAVE_MESH)
  std::set<MEdge, Less_Edge> es;
  for(unsigned int i = 0; i < getNumMeshElements(); i++){
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
  for (std::set<MEdge, Less_Edge>::const_iterator it = es.begin();
       it != es.end();++it){
    double u1,v1,u2,v2;
    MVertex *vert1 =  it->getVertex(0);
    vert1->getParameter(0, u1);
    vert1->getParameter(1, v1);
    MVertex *vert2 =  it->getVertex(1);
    vert2->getParameter(0, u2);
    vert2->getParameter(1, v2);
    double l1 = BGM_MeshSize(this, u1, v1, vert1->x(), vert1->y(), vert1->z());
    double l2 = BGM_MeshSize(this, u2, v2, vert2->x(), vert2->y(), vert2->z());
    double correctLC = 0.5*(l1+l2);
    double lone = it->length()/correctLC;
    if (lone > oneoversqr2 && lone < sqr2) GS++;
    avg += lone >1 ? (1. / lone) - 1. : lone - 1.;
    max_e = std::max(max_e, lone);
    min_e = std::min(min_e, lone);
  }
#endif
}

double GFace::curvatureDiv(const SPoint2 &param) const
{

  if (geomType() == Plane) return 0;

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
    n1 = normal(SPoint2(param.x(),       param.y()));
    n2 = normal(SPoint2(param.x() + eps, param.y()));
  }
  else {
    n1 = normal(SPoint2(param.x() - eps, param.y()));
    n2 = normal(SPoint2(param.x(),       param.y()));
  }
  if(param.y() - eps < 0.0) {
    n3 = normal(SPoint2(param.x(), param.y()      ));
    n4 = normal(SPoint2(param.x(), param.y() + eps));
  }
  else {
    n3 = normal(SPoint2(param.x(), param.y() - eps));
    n4 = normal(SPoint2(param.x(), param.y()      ));
  }

  SVector3 dndu = 100000 * (n2 - n1);
  SVector3 dndv = 100000 * (n4 - n3);

  SVector3 dudu = SVector3();
  SVector3 dvdv = SVector3();
  SVector3 dudv = SVector3();
  secondDer(param, &dudu, &dvdv, &dudv);

  double ddu = dot(dndu, du);
  double ddv = dot(dndv, dv);

  return (fabs(ddu) + fabs(ddv)) / detJ;
}

double GFace::curvatureMax(const SPoint2 &param) const
{
  if (geomType() == Plane) return 0.;

  double eigVal[2], eigVec[8];
  getMetricEigenVectors(param, eigVal, eigVec);

  return fabs(eigVal[1]);
}

double GFace::curvatures(const SPoint2 &param, SVector3 *dirMax, SVector3 *dirMin,
                         double *curvMax, double *curvMin) const
{
  Pair<SVector3, SVector3> D1 = firstDer(param);

  if(geomType() == Plane){
    *dirMax = D1.first();
    *dirMin = D1.second();
    *curvMax = 0.;
    *curvMin = 0.;
    return 0.;
  }

  if(geomType() == Sphere){
    *dirMax = D1.first();
    *dirMin = D1.second();
    *curvMax = curvatureDiv(param);
    *curvMin = *curvMax;
    return *curvMax;
  }

  double eigVal[2], eigVec[8];
  getMetricEigenVectors(param, eigVal, eigVec);

  // curvatures and main directions
  *curvMax = fabs(eigVal[1]);
  *curvMin = fabs(eigVal[0]);
  *dirMax = eigVec[1] * D1.first() + eigVec[3] * D1.second();
  *dirMin = eigVec[0] * D1.first() + eigVec[2] * D1.second();

  return *curvMax;
}

double GFace::getMetricEigenvalue(const SPoint2 &)
{
  Msg::Error("Metric eigenvalue is not implemented for this type of surface");
  return 0.;
}

// eigen values are absolute values and sorted from min to max of absolute values
// eigen vectors are the corresponding COLUMNS of eigVec
void GFace::getMetricEigenVectors(const SPoint2 &param,
                                  double eigVal[2], double eigVec[4]) const
{

  // first derivatives
  Pair<SVector3,SVector3> D1 = firstDer(param);
  SVector3 du = D1.first();
  SVector3 dv = D1.second();
  SVector3 nor = crossprod(du, dv); nor.normalize();

  // second derivatives
  SVector3 dudu = SVector3();
  SVector3 dvdv = SVector3();
  SVector3 dudv = SVector3();
  secondDer(param, &dudu, &dvdv, &dudv);

  // first form
  double form1[2][2];
  form1[0][0] = normSq(du);
  form1[1][1] = normSq(dv);
  form1[0][1] = form1[1][0] = dot(du,dv);

  // second form
  double form2[2][2];
  form2[0][0] = dot(nor,dudu);
  form2[1][1] = dot(nor,dvdv);
  form2[0][1] = form2[1][0] = dot(nor,dudv);

  // inverse of first form
  double inv_form1[2][2];
  double inv_det_form1 = 1. / (form1[0][0] * form1[1][1] - form1[1][0] * form1[0][1]);
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
  if(N.eig(dr, di, vl, vr, true)){
    eigVal[0] = fabs(dr(0));
    eigVal[1] = fabs(dr(1));
    eigVec[0] = vr(0, 0);
    eigVec[2] = vr(1, 0);
    eigVec[1] = vr(0, 1);
    eigVec[3] = vr(1, 1);
  }
  else{
    Msg::Error("Problem in eigen vectors computation");
    Msg::Error(" N = [ %f %f ]", N(0, 0), N(0, 1));
    Msg::Error("     [ %f %f ]", N(1, 0), N(1, 1));
    for(int i = 0; i < 2; i++) eigVal[i] = 0.;
    for(int i = 0; i < 4; i++) eigVec[i] = 0.;
  }
  if (fabs(di(0)) > 1.e-12 || fabs(di(1)) > 1.e-12) {
    Msg::Error("Found imaginary eigenvalues");
  }
}

void GFace::XYZtoUV(double X, double Y, double Z, double &U, double &V,
                    double relax, bool onSurface) const
{
  const double Precision = onSurface ? 1.e-8 : 1.e-3;
  const int MaxIter = onSurface ? 25 : 10;
  const int NumInitGuess = 9;

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

  const double tol = Precision * (SQU(umax - umin) + SQU(vmax-vmin));
  for(int i = 0; i < NumInitGuess; i++) {
    initu[i] = umin + initu[i] * (umax - umin);
    initv[i] = vmin + initv[i] * (vmax - vmin);
  }

  for(int i = 0; i < NumInitGuess; i++){
    for(int j = 0; j < NumInitGuess; j++){

      U = initu[i];
      V = initv[j];
      err = 1.0;
      iter = 1;

      GPoint P = point(U, V);
      err2 = sqrt(SQU(X - P.x()) + SQU(Y - P.y()) + SQU(Z - P.z()));
      if (err2 < 1.e-8 * CTX::instance()->lc) return;

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

        Unew = U + relax *
          (jac[0][0] * (X - P.x()) + jac[1][0] * (Y - P.y()) +
           jac[2][0] * (Z - P.z()));
        Vnew = V + relax *
          (jac[0][1] * (X - P.x()) + jac[1][1] * (Y - P.y()) +
           jac[2][1] * (Z - P.z()));

        // don't remove this test: it is important
        if((Unew > umax+tol || Unew < umin-tol) &&
           (Vnew > vmax+tol || Vnew < vmin-tol)) break;

        err = SQU(Unew - U) + SQU(Vnew - V);
        err2 = sqrt(SQU(X - P.x()) + SQU(Y - P.y()) + SQU(Z - P.z()));

        iter++;
        U = Unew;
        V = Vnew;
      }

      if(iter < MaxIter && err <= tol &&
         Unew <= umax && Vnew <= vmax &&
         Unew >= umin && Vnew >= vmin){

        if (onSurface && err2 > 1.e-4 * CTX::instance()->lc &&
            !CTX::instance()->mesh.NewtonConvergenceTestXYZ){
          Msg::Warning("Converged for i=%d j=%d (err=%g iter=%d) BUT "
                       "xyz error = %g in point (%e,%e,%e) on surface %d",
                       i, j, err, iter, err2, X, Y, Z, tag());
        }

        if(onSurface && err2 > 1.e-4 * CTX::instance()->lc &&
           CTX::instance()->mesh.NewtonConvergenceTestXYZ){
          // not converged in XYZ coordinates
        }
        else{
          return;
        }

      }
    }
  }

  if(!onSurface) return;

  if(relax < 1.e-6)
    Msg::Error("Could not converge: surface mesh will be wrong");
  else {
    Msg::Info("point %g %g %g : Relaxation factor = %g", X, Y, Z, 0.75 * relax);
    XYZtoUV(X, Y, Z, U, V, 0.75 * relax);
  }
}

SPoint2 GFace::parFromPoint(const SPoint3 &p, bool onSurface) const
{
  double U = 0., V = 0.;
  XYZtoUV(p.x(), p.y(), p.z(), U, V, 1.0, onSurface);
  return SPoint2(U, V);
}

#if defined(HAVE_BFGS)

class data_wrapper{
 private:
  const GFace* gf;
  SPoint3 point;
 public:
  data_wrapper() { gf = NULL; point = SPoint3(); }
  ~data_wrapper() {}
  const GFace* get_face() { return gf; }
  void set_face(const GFace* face) { gf = face; }
  SPoint3 get_point() { return point; }
  void set_point(SPoint3 _point) { point = SPoint3(_point); }
};

// Callback function for BFGS
void bfgs_callback(const alglib::real_1d_array& x, double& func,
                   alglib::real_1d_array& grad, void* ptr)
{
  data_wrapper* w = static_cast<data_wrapper*>(ptr);
  SPoint3 p = w->get_point();
  const GFace* gf = w->get_face();

  // Value of the objective
  GPoint pnt = gf->point(x[0], x[1]);
  func = 0.5 *
    ( p.x() - pnt.x() ) * ( p.x() - pnt.x() ) +
    ( p.y() - pnt.y() ) * ( p.y() - pnt.y() ) +
    ( p.z() - pnt.z() ) * ( p.z() - pnt.z() ) ;
  //printf("func : %f\n", func);

  // Value of the gradient
  Pair<SVector3, SVector3> der = gf->firstDer(SPoint2(x[0], x[1]));
  grad[0] = -(p.x() - pnt.x()) * der.left().x()  - (p.y() - pnt.y()) * der.left().y()
    - (p.z() - pnt.z()) * der.left().z();
  grad[1] = -(p.x() - pnt.x()) * der.right().x() - (p.y() - pnt.y()) * der.right().y()
    - (p.z() - pnt.z()) * der.right().z();
  //  printf("func %22.15E Gradients %22.15E %22.15E der %g %g %g\n",
  //         func, grad[0], grad[1],der.left().x(),der.left().y(),der.left().z());
}
#endif

GPoint GFace::closestPoint(const SPoint3 &queryPoint, const double initialGuess[2]) const
{
#if defined(HAVE_BFGS)
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
  const double ru = uu.high()-uu.low(), rv = vv.high()-vv.low();
  const double epsU = 1e-5*ru, epsV = 1e-5*rv;
  const double du = ru/nGuesses, dv = rv/nGuesses;
  for(double u = uu.low(); u <= uu.high() + epsU; u += du) {
    for(double v = vv.low(); v <= vv.high() + epsV; v += dv) {
      GPoint pnt = point(u, v);
      SPoint3 spnt(pnt.x(), pnt.y(), pnt.z());
      double dist = queryPoint.distance(spnt);
      if (dist < min_dist) {
        min_dist = dist;
        min_u = u;
        min_v = v;
      }
    }
  }

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
  minlbfgsoptimize(state, bfgs_callback, NULL, &w);

  // Get results
  alglib::minlbfgsreport rep;
  minlbfgsresults(state, x, rep);
  GPoint pntF = point(x[0], x[1]);
  return pntF;

#else
  Msg::Error("Closest point not implemented for this type of surface");
  SPoint2 p = parFromPoint(queryPoint, false);
  return point(p);
#endif
}

bool GFace::containsParam(const SPoint2 &pt) const
{
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
  Pair<SVector3,SVector3> der = firstDer(param);
  SVector3 n = crossprod(der.first(), der.second());
  n.normalize();
  return n;
}

bool GFace::buildRepresentationCross(bool force)
{
  if(cross.size()){
    if(force)
      cross.clear();
    else
      return true;
  }

  if(geomType() != Plane){
    cross.clear();
    cross.push_back(SPoint3(0., 0., 0.));
    return false;
  }

  std::list<GEdge*> ed = edges();
  SBoundingBox3d bb;
  for(std::list<GEdge*>::iterator it = ed.begin(); it != ed.end(); it++){
    GEdge *ge = *it;
    if(ge->geomType() == GEntity::DiscreteCurve ||
       ge->geomType() == GEntity::BoundaryLayerCurve){
      cross.clear();
      cross.push_back(SPoint3(0., 0., 0.));
      return false;
    }
    else{
      Range<double> t_bounds = ge->parBounds(0);
      GPoint p[3] = {ge->point(t_bounds.low()),
                     ge->point(0.5 * (t_bounds.low() + t_bounds.high())),
                     ge->point(t_bounds.high())};
      for(int i = 0; i < 3; i++){
        SPoint2 uv = parFromPoint(SPoint3(p[i].x(), p[i].y(), p[i].z()));
        bb += SPoint3(uv.x(), uv.y(), 0.);
      }
    }
  }
  bb *= 1.1;
  GPoint v0 = point(bb.min().x(), bb.min().y());
  GPoint v1 = point(bb.max().x(), bb.min().y());
  GPoint v2 = point(bb.max().x(), bb.max().y());
  GPoint v3 = point(bb.min().x(), bb.max().y());
  const int N = 100;
  for(int dir = 0; dir < 2; dir++) {
    int end_line = 0;
    SPoint3 pt, pt_last_inside;
    for(int i = 0; i < N; i++) {
      double t = (double)i / (double)(N - 1);
      double x, y, z;
      if(!dir){
        x = 0.5 * (t * (v0.x() + v1.x()) + (1. - t) * (v2.x() + v3.x()));
        y = 0.5 * (t * (v0.y() + v1.y()) + (1. - t) * (v2.y() + v3.y()));
        z = 0.5 * (t * (v0.z() + v1.z()) + (1. - t) * (v2.z() + v3.z()));
      }
      else{
        x = 0.5 * (t * (v0.x() + v3.x()) + (1. - t) * (v2.x() + v1.x()));
        y = 0.5 * (t * (v0.y() + v3.y()) + (1. - t) * (v2.y() + v1.y()));
        z = 0.5 * (t * (v0.z() + v3.z()) + (1. - t) * (v2.z() + v1.z()));
      }
      pt.setPosition(x, y, z);
      if(containsPoint(pt)){
        pt_last_inside.setPosition(x, y, z);
        if(!end_line) { cross.push_back(pt); end_line = 1; }
      }
      else {
        if(end_line) { cross.push_back(pt_last_inside); end_line = 0; }
      }
    }
    if(end_line) cross.push_back(pt_last_inside);
  }
  // if we couldn't determine a cross, add a dummy point so that we
  // won't try again unless we force the recomputation
  if(!cross.size()){
    cross.push_back(SPoint3(0., 0., 0.));
    return false;
  }
  return true;
}

bool GFace::buildSTLTriangulation(bool force)
{
  if(stl_triangles.size()){
    if(force){
      stl_vertices.clear();
      stl_triangles.clear();
    }
    else{
      return true;
    }
  }
  // Build a simple triangulation for surfaces which we know are not
  // trimmed
  if(geomType() == ParametricSurface || geomType() == ProjectionFace){
    const int nu = 64, nv = 64;
    Range<double> ubounds = parBounds(0);
    Range<double> vbounds = parBounds(1);
    double umin = ubounds.low(), umax = ubounds.high();
    double vmin = vbounds.low(), vmax = vbounds.high();
    for(int i = 0; i < nu; i++){
      for(int j = 0; j < nv; j++){
        double u = umin + (double)i / (double)(nu - 1) * (umax - umin);
        double v = vmin + (double)j / (double)(nv - 1) * (vmax - vmin);
        stl_vertices.push_back(SPoint2(u, v));
      }
    }
    for(int i = 0; i < nu - 1; i++){
      for(int j = 0; j < nv - 1; j++){
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

  // build STL for general surfaces here

  return false;
}

bool GFace::fillVertexArray(bool force)
{
  if(va_geom_triangles){
    if(force)
      delete va_geom_triangles;
    else
      return true;
  }

  if(!buildSTLTriangulation(force)) return false;
  if(stl_triangles.empty()) return false;

  va_geom_triangles = new VertexArray(3, stl_triangles.size() / 3);
  unsigned int c = CTX::instance()->color.geom.surface;
  unsigned int col[4] = {c, c, c, c};
  for (unsigned int i = 0; i < stl_triangles.size(); i += 3){
    SPoint2 &p1(stl_vertices[stl_triangles[i]]);
    SPoint2 &p2(stl_vertices[stl_triangles[i + 1]]);
    SPoint2 &p3(stl_vertices[stl_triangles[i + 2]]);
    GPoint gp1 = point(p1);
    GPoint gp2 = point(p2);
    GPoint gp3 = point(p3);
    double x[3] = {gp1.x(), gp2.x(), gp3.x()};
    double y[3] = {gp1.y(), gp2.y(), gp3.y()};
    double z[3] = {gp1.z(), gp2.z(), gp3.z()};
    SVector3 n[3] = {normal(p1), normal(p2), normal(p3)};
    va_geom_triangles->add(x, y, z, n, col);
  }
  va_geom_triangles->finalize();
  return true;
}

// by default we assume that straight lines are geodesics
SPoint2 GFace::geodesic(const SPoint2 &pt1, const SPoint2 &pt2, double t)
{
  if(CTX::instance()->mesh.secondOrderExperimental && geomType() != GEntity::Plane ){
    // FIXME: this is buggy -- remove the CTX option once we do it in
    // a robust manner
    GPoint gp1 = point(pt1.x(), pt1.y());
    GPoint gp2 = point(pt2.x(), pt2.y());
    SPoint2 guess = pt1 + (pt2 - pt1) * t;
    GPoint gp = closestPoint(SPoint3(gp1.x() + t * (gp2.x() - gp1.x()),
                                     gp1.y() + t * (gp2.y() - gp1.y()),
                                     gp1.z() + t * (gp2.z() - gp1.z())),
                             (double*)guess);
    if (gp.g())
      return SPoint2(gp.u(), gp.v());
    else
      return pt1 + (pt2 - pt1) * t;
  }
  else{
    return pt1 + (pt2 - pt1) * t;
  }
}


// length of a curve drawn on a surface
// S = (X(u,v), Y(u,v), Z(u,v) );
// u = u(t) , v = v(t)
// C = C ( u(t), v(t) )
// dC/dt = dC/du du/dt + dC/dv dv/dt
double GFace::length(const SPoint2 &pt1, const SPoint2 &pt2, int nbQuadPoints)
{
  double *t = 0, *w = 0;
  double L = 0.0;
  gmshGaussLegendre1D(nbQuadPoints, &t, &w);
  for (int i = 0; i < nbQuadPoints; i++){
    const double ti = 0.5 * (1. + t[i]);
    SPoint2 pi = geodesic(pt1, pt2, ti);
    Pair<SVector3, SVector3> der2 = firstDer(pi);
    SVector3 der = der2.left() * (pt2.x() - pt1.x()) + der2.right() * (pt2.y() - pt1.y());
    const double d = norm(der);
    L += d * w[i] ;
  }
  return L;
}

int GFace::genusGeom() const
{
  int nSeams = 0;
  std::set<GEdge*> single_seams;
  for (std::list<GEdge*>::const_iterator it = l_edges.begin();
       it!=l_edges.end();++it){
    if ((*it)->isSeam(this)){
      nSeams++;
      std::set<GEdge*>::iterator it2 = single_seams.find(*it);
      if (it2 != single_seams.end()) single_seams.erase(it2);
      else single_seams.insert(*it);
    }
  }
  return nSeams - single_seams.size();
}

bool GFace::fillPointCloud(double maxDist,
			   std::vector<SPoint3> *points,
			   std::vector<SPoint2> *uvpoints,
                           std::vector<SVector3> *normals)
{
  if(!points) return false;

  if (buildSTLTriangulation()){
    for(unsigned int i = 0; i < stl_triangles.size(); i += 3){
      SPoint2 &p0(stl_vertices[stl_triangles[i]]);
      SPoint2 &p1(stl_vertices[stl_triangles[i + 1]]);
      SPoint2 &p2(stl_vertices[stl_triangles[i + 2]]);

      GPoint gp0 = point(p0);
      GPoint gp1 = point(p1);
      GPoint gp2 = point(p2);
      double maxEdge = std::max(gp0.distance(gp1),
				std::max(gp1.distance(gp2), gp2.distance(gp0)));
      int N = (int)(maxEdge / maxDist);
      for(double u = 0.; u < 1.; u += 1. / N){
	for(double v = 0.; v < 1 - u; v += 1. / N){
	  SPoint2 p = p0 * (1. - u - v) + p1 * u + p2 * v;
	  GPoint gp(point(p));
	  points->push_back(SPoint3(gp.x(), gp.y(), gp.z()));
	  if(uvpoints) uvpoints->push_back(p);
	  if(normals) normals->push_back(normal(p));
	}
      }
    }
  }
  else {
    int N = 1000;//(int)(maxDX / maxDist);
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
static void meshCompound (GFace* gf, bool verbose) {

  discreteFace *df = new discreteFace (gf->model(), gf->tag() + 100000);

  std::set<int> ec;
  for (unsigned int i=0;i<gf->_compound.size();i++){
    GFace *c = (GFace*)gf->_compound[i];
    std::list<GEdge*> edges = c->edges();
    for (std::list<GEdge*> :: iterator it = edges.begin() ; it != edges.end(); ++it){
      std::set<int>::iterator found = ec.find((*it)->tag());
      if (found == ec.end())ec.insert((*it)->tag());
      else ec.erase(found);
    }
    df->triangles.insert(df->triangles.end(), c->triangles.begin(),c->triangles.end());
    df->mesh_vertices.insert(df->mesh_vertices.end(), c->mesh_vertices.begin(),c->mesh_vertices.end());
    for (unsigned int j=0;j<c->triangles.size();j++)df->_CAD.push_back(c);
    c->triangles.clear();
    c->mesh_vertices.clear();
  }
  std::vector<int> cedges;
  cedges.insert(cedges.begin(), ec.begin(), ec.end());
  df->setBoundEdges(gf->model(), cedges);
  df->createGeometry();
  df->mesh(verbose);
  delete df;
}
#endif

void GFace::mesh(bool verbose)
{
#if defined(HAVE_MESH)
  meshGFace mesher;
  mesher(this, verbose);
  if (!_compound.empty()){ // Some faces are meshed together
    if (_compound[0] == this){ //  I'm the one that makes the compound job
      bool ok = true;
      for (unsigned int i=0;i<_compound.size();i++){
	GFace *gf = (GFace*)_compound[i];
	ok &= (gf->meshStatistics.status == GFace::DONE);
      }
      if (!ok)meshStatistics.status = GFace::PENDING;
      else {
	meshCompound(this, verbose);
	return;
      }
    }
  }
#endif
}

void GFace::lloyd(int nbiter, int infn)
{
#if defined(HAVE_MESH) && defined(HAVE_BFGS)
  smoothing s = smoothing(nbiter,infn);
  s.optimize_face(this);
  //lloydAlgorithm algo(nbiter, infn);
  //algo(this);
#endif
}

void GFace::replaceEdges(std::list<GEdge*> &new_edges)
{
  replaceEdgesInternal(new_edges);
  std::list<GEdge*>::iterator it  = l_edges.begin();
  std::list<GEdge*>::iterator it2 = new_edges.begin();
  std::list<int>::iterator it3 = l_dirs.begin();
  std::list<int> newdirs;
  for ( ; it != l_edges.end(); ++it, ++it2, ++it3){
    (*it)->delFace(this);
    (*it2)->addFace(this);
    if ((*it2)->getBeginVertex() == (*it)->getBeginVertex())
      newdirs.push_back(*it3);
    else
      newdirs.push_back(-(*it3));
  }
  l_edges = new_edges;
  l_dirs = newdirs;
}

void GFace::moveToValidRange(SPoint2 &pt) const
{
  //  printf("coucou %8d %12.5E %12.5E %d %d\n",
  //	 tag(),pt.x(),pt.y(),
  //	 periodic(0),periodic(1));
  for(int i=0; i < 2; i++){
    if(periodic(i)){
      Range<double> range = parBounds(i);
      double tol = 1e-6*(range.high()-range.low());
      if(pt[i] < range.low()-tol)
	pt[i] += period(i);
      if(pt[i] > range.high()+tol)
	pt[i] -= period(i);
      if(pt[i] < range.low())
	pt[i] = range.low();
      if(pt[i] > range.high())
	pt[i] = range.high();
    }
  }
}

void GFace::relocateMeshVertices()
{
  for(unsigned int i = 0; i < mesh_vertices.size(); i++){
    MVertex *v = mesh_vertices[i];
    double u0 = 0., u1 = 0.;
    if(v->getParameter(0, u0) && v->getParameter(1, u1)){
      GPoint p = point(u0, u1);
      v->x() = p.x();
      v->y() = p.y();
      v->z() = p.z();
    }
  }
}

void GFace::setMeshMaster(GFace* master, const std::vector<double>& tfo)
{
  std::list<GEdge*>::iterator eIter;
  std::list<GVertex*>::iterator vIter;

  Msg::Info("Setting mesh master using transformation ");

  // list all vertices and construct vertex to edge correspondence for local edge

  std::set<GVertex*> l_vertices;
  std::map<std::pair<GVertex*,GVertex*>,GEdge* > l_vtxToEdge;

  for (eIter=l_edges.begin();eIter!=l_edges.end();++eIter) {
    GVertex* v0 = (*eIter)->getBeginVertex();
    GVertex* v1 = (*eIter)->getEndVertex();
    l_vertices.insert(v0);
    l_vertices.insert(v1);
    l_vtxToEdge[std::make_pair(v0,v1)] = (*eIter);
  }

  for (eIter=embedded_edges.begin();eIter!=embedded_edges.end();++eIter) {
    GVertex* v0 = (*eIter)->getBeginVertex();
    GVertex* v1 = (*eIter)->getEndVertex();
    l_vertices.insert(v0);
    l_vertices.insert(v1);
    l_vtxToEdge[std::make_pair(v0,v1)] = (*eIter);
  }

  l_vertices.insert(embedded_vertices.begin(),embedded_vertices.end());

  // list all vertices and vertex to edge correspondence for remote edge

  std::list<GEdge*> m_edges = master->edges();
  std::set<GVertex*> m_vertices;
  std::map<std::pair<GVertex*,GVertex*>,GEdge* > m_vtxToEdge;
  for (eIter=m_edges.begin();eIter!=m_edges.end();++eIter) {
    GVertex* v0 = (*eIter)->getBeginVertex();
    GVertex* v1 = (*eIter)->getEndVertex();
    m_vertices.insert(v0);
    m_vertices.insert(v1);
    m_vtxToEdge[std::make_pair(v0,v1)] = (*eIter);
  }

  std::list<GEdge*> m_embedded_edges = master->embeddedEdges();

  for (eIter=m_embedded_edges.begin();eIter!=m_embedded_edges.end();eIter++) {
    GVertex* v0 = (*eIter)->getBeginVertex();
    GVertex* v1 = (*eIter)->getEndVertex();
    m_vertices.insert(v0);
    m_vertices.insert(v1);
    m_vtxToEdge[std::make_pair(v0,v1)] = (*eIter);
  }

  std::list<GVertex*> m_embedded_vertices = master->embeddedVertices();
  m_vertices.insert(m_embedded_vertices.begin(),m_embedded_vertices.end());

  // check topological correspondence

  if (l_vertices.size() != m_vertices.size()) {
    Msg::Error("Periodic connection specified between topologically "
               "incompatible surfaces %d and %d (that have %d vs %d model vertices)",
               master->tag(),tag(),l_vertices.size(),m_vertices.size());
    return;
  }

  if (l_vtxToEdge.size() != m_vtxToEdge.size()) {
    Msg::Error("Periodic connection specified between topologically "
               "incompatible surfaces %d and %d (that have %d vs %d model edges)",
               master->tag(),tag(),l_vtxToEdge.size(),m_vtxToEdge.size());
    return;
  }

  // compute corresponding vertices

  std::map<GVertex*,GVertex*> gVertexCounterparts;

  std::set<GVertex*>::iterator mvIter;
  for (mvIter=m_vertices.begin();mvIter!=m_vertices.end();++mvIter) {

    GVertex* m_vertex = *mvIter;

    SPoint3 xyzOri((*mvIter)->x(),(*mvIter)->y(),(*mvIter)->z());
    SPoint3 xyzTfo(0,0,0);

    int idx = 0;
    for (int i=0;i<3;i++) {
      for (int j=0;j<3;j++) xyzTfo[i] += xyzOri[j] * tfo[idx++];
      xyzTfo[i] += tfo[idx++];
    }

    GVertex* l_vertex = NULL;

    std::set<GVertex*>::iterator lvIter = l_vertices.begin();
    for (;lvIter!=l_vertices.end();++lvIter) {

      SPoint3 xyz((*lvIter)->x(),(*lvIter)->y(),(*lvIter)->z());
      SVector3 dist = xyz - xyzTfo;

      if (dist.norm() < CTX::instance()->geom.tolerance * CTX::instance()->lc) {
        l_vertex = *lvIter;
        break;
      }
    }

    if (l_vertex==NULL) {
      Msg::Error("Was not able to find corresponding node %d "
                 "for periodic connection of surface %d to %d "
                 "using the specified transformation",
                 m_vertex->tag(),master->tag(),tag());
      return;
    }
    gVertexCounterparts[l_vertex] = m_vertex;
  }

  if (gVertexCounterparts.size() != m_vertices.size()) {
    Msg::Error("Could not find all node correspondances "
               "for the periodic connection from surface %d to %d",
               master->tag(),tag());
    return;
  }

  // construct edge correspondence and update the edge masters

  std::map<GEdge*,std::pair<GEdge*,int> > gEdgeCounterparts;

  std::map<std::pair<GVertex*,GVertex*>,GEdge*>::iterator lv2eIter;
  for (lv2eIter=l_vtxToEdge.begin();lv2eIter!=l_vtxToEdge.end();lv2eIter++) {

    std::pair<GVertex*,GVertex*> lPair = lv2eIter->first;
    GEdge* localEdge = lv2eIter->second;

    std::pair<GVertex*,GVertex*> mPair(gVertexCounterparts[lPair.first],
                                       gVertexCounterparts[lPair.second]);
		int sign = 1;
    std::map<std::pair<GVertex*,GVertex*>,GEdge*>::iterator mv2eIter = m_vtxToEdge.find(mPair);
    if (mv2eIter == m_vtxToEdge.end()) {
      sign *= -1;
      std::pair<GVertex*,GVertex*> backward(mPair.second,mPair.first);
      mv2eIter = m_vtxToEdge.find(backward);
    }

    if (mv2eIter == m_vtxToEdge.end()) {
      Msg::Error("Could not find periodic copy of edge %d-%d "
                 "(corresponding to vertices %d %d) in face %d",
                 lPair.first->tag(),lPair.second->tag(),
                 mPair.first->tag(),mPair.second->tag(),
                 master->tag());
      return;
    }
    GEdge* masterEdge = mv2eIter->second;

    if (masterEdge->meshMaster() != localEdge) {
      localEdge->setMeshMaster(masterEdge,tfo);
      Msg::Info("Setting edge master %d - %d",
                localEdge->tag(),
                masterEdge->tag());
    }
    gEdgeCounterparts[localEdge] = std::make_pair(masterEdge,sign);
  }
  // complete the information at the edge level

  edgeCounterparts   = gEdgeCounterparts;
  vertexCounterparts = gVertexCounterparts;
  GEntity::setMeshMaster(master,tfo);
}

inline double myAngle(const SVector3 &a, const SVector3 &b, const SVector3 &d)
{
  double cosTheta = dot(a, b);
  double sinTheta = dot(crossprod(a, b), d);
  return atan2(sinTheta, cosTheta);
}

struct myPlane {
  SPoint3 p;
  SVector3 n;
  double a;
  // nx x + ny y + nz z + a = 0
  myPlane(SPoint3 _p, SVector3 _n) : p(_p),n(_n)
  {
    n.normalize();
    a = -(n.x()*p.x()+n.y()*p.y()+n.z()*p.z());
  }
  double eval (double x, double y, double z)
  {
    return n.x() * x + n.y() * y + n.z() * z + a;
  }
};
struct myLine {
  SPoint3 p;
  SVector3 t;
  myLine() : p(0,0,0) , t (0,0,1) {}
  myLine(myPlane &p1, myPlane &p2)
  {
    t = crossprod(p1.n, p2.n);
    if (t.norm() == 0.0){
      Msg::Error("parallel planes do not intersect");
    }
    else
      t.normalize();
    // find a point, assume z = 0
    double a[2][2] = {{p1.n.x(), p1.n.y()}, {p2.n.x(), p2.n.y()}};
    double b[2] = {-p1.a, -p2.a}, x[2];
    if (!sys2x2(a, b, x)){
      // assume x = 0
      double az[2][2] = {{p1.n.y(), p1.n.z()}, {p2.n.y(), p2.n.z()}};
      double bz[2] = {-p1.a, -p2.a};
      if (!sys2x2(az, bz, x)){
	// assume y = 0
	double ay[2][2] = {{p1.n.x(), p1.n.z()}, {p2.n.x(), p2.n.z()}};
	double by[2] = {-p1.a, -p2.a};
	if (!sys2x2(ay,by,x)){
	  Msg::Error("parallel planes do not intersect");
	}
	else {
	  p = SPoint3(x[0], 0., x[1]);
	}
      }
      else{
	p = SPoint3(0., x[0], x[1]);
      }
    }
    else{
      p = SPoint3(x[0], x[1], 0.);
    }
  }
  SPoint3 orthogonalProjection (SPoint3 &a)
  {
    // (x - a) * t = 0 -->
    // x = p + u t --> (p + ut - a) * t = 0 --> u = (a-p) * t
    const double u = dot(a - p, t);
    return SPoint3(p.x() + t.x() * u,p.y() + t.y() * u,p.z() + t.z() * u);
  }
};

void GFace::setMeshMaster(GFace* master,const std::map<int,int>& edgeCopies)
{
  std::map<GVertex*,GVertex*> vs2vt;

  for (std::list<GEdge*>::iterator it=l_edges.begin();it!=l_edges.end();++it){

    // slave edge
    GEdge* le = *it;

    int sign = 1;
    std::map<int,int>::const_iterator adnksd = edgeCopies.find(le->tag());
    int source_e;
    if (adnksd != edgeCopies.end()) source_e = adnksd->second;
    else{
      sign = -1;
      adnksd = edgeCopies.find(-(*it)->tag());
      if(adnksd != edgeCopies.end()) source_e = adnksd->second;
      else{
        Msg::Error("Could not find edge counterpart %d in slave surface %d",
                   (*it)->tag(), master->tag());
        return;
      }
    }

    // master edge
    GEdge *me = master->model()->getEdgeByTag(abs(source_e));

    if (source_e * sign > 0){
      vs2vt[me->getBeginVertex()] = le->getBeginVertex();
      vs2vt[me->getEndVertex()]   = le->getEndVertex();
    }
    else {
      vs2vt[me->getBeginVertex()] = le->getEndVertex();
      vs2vt[me->getEndVertex()]   = le->getBeginVertex();
    }
  }

  // --- find out the transformation

  bool translation = true;
  SVector3 DX;

  int count = 0;
  for (std::map<GVertex*, GVertex*>::iterator it = vs2vt.begin();
       it != vs2vt.end() ; ++it){
    GVertex *vs = it->first;
    GVertex *vt = it->second;
    if (count == 0)
      DX = SVector3(vt->x()-vs->x(),vt->y()-vs->y(),vt->z()-vs->z());
    else {
      SVector3 DX2(vt->x()-vs->x(),vt->y()-vs->y(),vt->z()-vs->z());
      SVector3 DDX(DX2 - DX);
      if (DDX.norm() > DX.norm() * 1.e-5) translation = false;
    }
    count ++;
  }

  std::vector<double> tfo(16);

  if (translation) {
    Msg::Info("Periodic mesh translation found between %d and %d: dx = (%g,%g,%g)",
              tag(),master->tag(),DX.x(), DX.y(), DX.z());

    for (size_t i=0;i<16;i++) tfo[i] = 0;
    for (size_t i=0;i<4;i++)  tfo[i*4+i] = 1;
    tfo[3]  = DX.x();
    tfo[7]  = DX.y();
    tfo[11] = DX.z();
  }

  else {

    bool rotation = false;
    myLine LINE;
    double ANGLE=0;

    count = 0;
    rotation = true;
    std::vector<SPoint3> mps, mpt;
    for (std::map<GVertex*, GVertex*>::iterator it = vs2vt.begin();
         it != vs2vt.end() ; ++it){
      GVertex *vs = it->first;
      GVertex *vt = it->second;
      mps.push_back(SPoint3(vs->x(), vs->y(), vs->z()));
      mpt.push_back(SPoint3(vt->x(), vt->y(), vt->z()));
    }
    mean_plane mean_source, mean_target;
    computeMeanPlaneSimple(mps, mean_source);
    computeMeanPlaneSimple(mpt, mean_target);

    myPlane PLANE_SOURCE(SPoint3(mean_source.x,mean_source.y,mean_source.z),
                         SVector3(mean_source.a,mean_source.b,mean_source.c));
    myPlane PLANE_TARGET(SPoint3(mean_target.x,mean_target.y,mean_target.z),
                         SVector3(mean_target.a,mean_target.b,mean_target.c));

    LINE = myLine(PLANE_SOURCE, PLANE_TARGET);

    // LINE is the axis of rotation
    // let us compute the angle of rotation
    count = 0;
    for (std::map<GVertex*, GVertex*>::iterator it = vs2vt.begin();
         it != vs2vt.end(); ++it){
      GVertex *vs = it->first;
      GVertex *vt = it->second;
      // project both points on the axis: that should be the same point !
      SPoint3 ps = SPoint3(vs->x(), vs->y(), vs->z());
      SPoint3 pt = SPoint3(vt->x(), vt->y(), vt->z());
      SPoint3 p_ps = LINE.orthogonalProjection(ps);
      SPoint3 p_pt = LINE.orthogonalProjection(pt);
      SVector3 dist1 = ps - pt;
      SVector3 dist2 = p_ps - p_pt;
      if (dist1.norm() > CTX::instance()->geom.tolerance){
        if (dist2.norm() > 1.e-8 * dist1.norm()){
          rotation = false;
        }
        SVector3 t1 = ps - p_ps;
        SVector3 t2 = pt - p_pt;
        if (t1.norm() > 1.e-8 * dist1.norm()){
          if (count == 0)
            ANGLE = myAngle(t1, t2, LINE.t);
          else {
            double ANGLE2 = myAngle(t1, t2, LINE.t);
            if (fabs (ANGLE2 - ANGLE) > 1.e-8){
              rotation = false;
            }
          }
          count++;
        }
      }
    }

    if (rotation){
      Msg::Info("Periodic mesh rotation found: axis (%g,%g,%g) point (%g %g %g) angle %g",
                LINE.t.x(), LINE.t.y(), LINE.t.z(), LINE.p.x(), LINE.p.y(), LINE.p.z(),
                ANGLE * 180 / M_PI);

      double ux = LINE.t.x();
      double uy = LINE.t.y();
      double uz = LINE.t.z();

      tfo[0*4+0] = cos (ANGLE) + ux*ux*(1.-cos(ANGLE));
      tfo[0*4+1] = ux*uy*(1.-cos(ANGLE)) - uz * sin(ANGLE);
      tfo[0*4+2] = ux*uz*(1.-cos(ANGLE)) + uy * sin(ANGLE);

      tfo[1*4+0] = ux*uy*(1.-cos(ANGLE)) + uz * sin(ANGLE);
      tfo[1*4+1] = cos (ANGLE) + uy*uy*(1.-cos(ANGLE));
      tfo[1*4+2] = uy*uz*(1.-cos(ANGLE)) - ux * sin(ANGLE);

      tfo[2*4+0] = ux*uz*(1.-cos(ANGLE)) - uy * sin(ANGLE);
      tfo[2*4+1] = uy*uz*(1.-cos(ANGLE)) + ux * sin(ANGLE);
      tfo[2*4+2] = cos (ANGLE) + uz*uz*(1.-cos(ANGLE));

      double origin[3] = {LINE.p.x(),LINE.p.y(),LINE.p.z()};

      for (int i=0;i<3;i++) tfo[i*4+3] =  origin[i];
      for (int i=0;i<3;i++) for (int j=0;j<3;j++) tfo[i*4+3] -= tfo[i*4+j] * origin[j];
      for (int i=0;i<3;i++) tfo[12+i] = 0;
      tfo[15] = 1;

    }
    else {
      Msg::Error("Only rotations or translations can currently be computed "
                 "automatically for periodic faces: face %d not meshed",
                 tag());
      return;
    }
  }

  // --- now check and encode the transformation
  // --- including for edges and vertices

  setMeshMaster(master, tfo);
}
