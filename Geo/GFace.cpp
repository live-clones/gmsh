// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

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
#include "meshGFaceLloyd.h"
#include "Bindings.h"
#include "meshGFaceOptimize.h"

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
  meshAttributes.Method = MESH_UNSTRUCTURED;
  meshAttributes.transfiniteArrangement = 0;
  meshAttributes.transfiniteSmoothing = -1;
  meshAttributes.extrude = 0;
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

std::list<GVertex*> GFace::vertices() const
{
  std::list<GEdge*>::const_iterator it = l_edges.begin();
  std::list<GVertex*>ret;
  while (it != l_edges.end()){
    GVertex *v1 = (*it)->getBeginVertex();
    GVertex *v2 = (*it)->getEndVertex();
    if(v1 && std::find(ret.begin(), ret.end(), v1) == ret.end())
      ret.push_back(v1);
    if(v2 && std::find(ret.begin(), ret.end(), v2) == ret.end())
      ret.push_back(v2);
    ++it;
  }
  return ret;
}

void GFace::setVisibility(char val, bool recursive)
{
  GEntity::setVisibility(val);
  if(recursive){
    std::list<GEdge*>::iterator it = l_edges.begin();
    while (it != l_edges.end()){
      (*it)->setVisibility(val, recursive);

      ++it;
    }
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
      if(it != l_edges.begin()) sstream << ",";
      sstream << (*it)->tag();
    }
    sstream << "}";
  }
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
      fprintf(fp, "Ruled Surface(%d) = {%d};\n", tag(), tag());
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

  if(meshAttributes.Method == MESH_TRANSFINITE){
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
}

void GFace::computeMeanPlane()
{
  std::vector<SPoint3> pts;
  std::list<GVertex*> verts = vertices();
  std::list<GVertex*>::const_iterator itv = verts.begin();
  for(; itv != verts.end(); itv++){
    const GVertex *v = *itv;
    pts.push_back(SPoint3(v->x(), v->y(), v->z()));
  }

  if(pts.size() < 3){
    Msg::Info("Adding edge points to compute mean plane of face %d", tag());
    std::list<GEdge*> edg = edges();
    std::list<GEdge*>::const_iterator ite = edg.begin();
    for(; ite != edg.end(); ite++){
      const GEdge *e = *ite;
      Range<double> b = e->parBounds(0);
      GPoint p1 = e->point(b.low() + 0.333 * (b.high() - b.low()));
      pts.push_back(SPoint3(p1.x(), p1.y(), p1.z()));
      GPoint p2 = e->point(b.low() + 0.666 * (b.high() - b.low()));
      pts.push_back(SPoint3(p2.x(), p2.y(), p2.z()));
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

  for(int i = 0; i < 3; i++)
    meanPlane.plan[0][i] = t1[i];
  for(int i = 0; i < 3; i++)
    meanPlane.plan[1][i] = t2[i];
  for(int i = 0; i < 3; i++)
    meanPlane.plan[2][i] = res[i];

  meanPlane.a = res[0];
  meanPlane.b = res[1];
  meanPlane.c = res[2];
  meanPlane.d = res[3];

  meanPlane.x = meanPlane.y = meanPlane.z = 0.;
  if(fabs(meanPlane.a) >= fabs(meanPlane.b) &&
     fabs(meanPlane.a) >= fabs(meanPlane.c) ){
    meanPlane.x = meanPlane.d / meanPlane.a;
  }
  else if(fabs(meanPlane.b) >= fabs(meanPlane.a) &&
          fabs(meanPlane.b) >= fabs(meanPlane.c)){
    meanPlane.y = meanPlane.d / meanPlane.b;
  }
  else{
    meanPlane.z = meanPlane.d / meanPlane.c;
  }

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
        Msg::Error("Plane surface %d (%gx+%gy+%gz=%g) is not plane!",
                   tag(), meanPlane.a, meanPlane.b, meanPlane.c, meanPlane.d);
        Msg::Error("Control point %d = (%g,%g,%g), val=%g",
                   v->tag(), v->x(), v->y(), v->z(), d);
        break;
      }
    }
  }
}

void computeMeanPlane(const std::vector<SPoint3> &points, mean_plane &meanPlane)
{
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

  for(int i = 0; i < 3; i++)
    meanPlane.plan[0][i] = t1[i];
  for(int i = 0; i < 3; i++)
    meanPlane.plan[1][i] = t2[i];
  for(int i = 0; i < 3; i++)
    meanPlane.plan[2][i] = res[i];

  meanPlane.a = res[0];
  meanPlane.b = res[1];
  meanPlane.c = res[2];
  meanPlane.d = res[3];

  meanPlane.x = meanPlane.y = meanPlane.z = 0.;
  if(fabs(meanPlane.a) >= fabs(meanPlane.b) &&
     fabs(meanPlane.a) >= fabs(meanPlane.c) ){
    meanPlane.x = meanPlane.d / meanPlane.a;
  }
  else if(fabs(meanPlane.b) >= fabs(meanPlane.a) &&
          fabs(meanPlane.b) >= fabs(meanPlane.c)){
    meanPlane.y = meanPlane.d / meanPlane.b;
  }
  else{
    meanPlane.z = meanPlane.d / meanPlane.c;
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
  const int NumInitGuess = 11;

  double Unew = 0., Vnew = 0., err, err2;
  int iter;
  double mat[3][3], jac[3][3];
  double umin, umax, vmin, vmax;
  double initu[NumInitGuess] = {0.487, 0.6, 0.4, 0.7, 0.3, 0.8, 0.2, 1., 0., 0., 1.};
  double initv[NumInitGuess] = {0.487, 0.6, 0.4, 0.7, 0.3, 0.8, 0.2, 0., 1., 0., 1.};

  Range<double> ru = parBounds(0);
  Range<double> rv = parBounds(1);
  umin = ru.low();
  umax = ru.high();
  vmin = rv.low();
  vmax = rv.high();

  for(int i = 0; i < NumInitGuess; i++){
    for(int j = 0; j < NumInitGuess; j++){

      U = initu[i];
      V = initv[j];
      err = 1.0;
      iter = 1;

      GPoint P = point(U, V);
      err2 = sqrt(SQU(X - P.x()) + SQU(Y - P.y()) + SQU(Z - P.z()));
      if (err2 < 1.e-8 * CTX::instance()->lc) return;

      while(err > Precision && iter < MaxIter) {
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

        //if(Unew > umax || Vnew > vmax || Unew < umin || Vnew < vmin) break;

        err = SQU(Unew - U) + SQU(Vnew - V);
        err2 = sqrt(SQU(X - P.x()) + SQU(Y - P.y()) + SQU(Z - P.z()));
        iter++;
        U = Unew;
        V = Vnew;
      }

      if(iter < MaxIter && err <= Precision &&
         Unew <= umax && Vnew <= vmax &&
         Unew >= umin && Vnew >= vmin){
        if (onSurface && err2 > 1.e-4 * CTX::instance()->lc)
          Msg::Warning("Converged for i=%d j=%d (err=%g iter=%d) BUT "
                       "xyz error = %g in point (%e,%e,%e) on surface %d",
                       i, j, err, iter, err2, X, Y, Z, tag());
        return;
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

GPoint GFace::closestPoint(const SPoint3 &queryPoint, const double initialGuess[2]) const
{
  Msg::Error("Closest point not implemented for this type of surface");
  return GPoint(0, 0, 0);
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
    else
      return true;
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

int GFace::poincareMesh()
{
  std::set<MEdge, Less_Edge> es;
  std::set<MVertex*> vs;
  for(unsigned int i = 0; i < getNumMeshElements(); i++){
    MElement *e = getMeshElement(i);
    for(int j = 0; j < e->getNumVertices(); j++) vs.insert(e->getVertex(j));
    for(int j = 0; j < e->getNumEdges(); j++) es.insert(e->getEdge(j));
  }
  return vs.size() - es.size() + getNumMeshElements();
}

int GFace::genusGeom()
{
  int nSeams = 0;
  std::set<GEdge*> single_seams;
  for (std::list<GEdge*>::iterator it = l_edges.begin();
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

bool GFace::fillPointCloud(double maxDist, std::vector<SPoint3> *points,
                           std::vector<SVector3> *normals)
{
  if(!buildSTLTriangulation()){
    Msg::Error("No STL triangulation available to fill point cloud");
    return false;
  }

  if(!points) return false;

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
        if(normals) normals->push_back(normal(p));
      }
    }
  }
  return true;
}

void GFace::lloyd(int nbiter, int infn)
{
#if defined(HAVE_MESH)
  lloydAlgorithm algo(nbiter, infn);
  algo(this);
#endif
}

void GFace::replaceEdges (std::list<GEdge*> &new_edges)
{
  replaceEdgesInternal (new_edges);
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


void GFace::addLayersOfQuads(int nLayers, GVertex *gv, double hmin, double ratio){
  
  SVector3 ez (0,0,1);
  std::list<GEdgeLoop>::iterator it = edgeLoops.begin();
  FILE *f = fopen ("coucou.pos","w");
  fprintf(f,"View \"\"{\n");
  for (; it != edgeLoops.end(); ++it){
    bool found = false;
    // look if this edge loop has the GVertex as an endpoint
    for (GEdgeLoop::iter it2 = it->begin(); it2 != it->end(); ++it2){
      if (it2->ge->getBeginVertex() == gv || it2->ge->getEndVertex() == gv)
	found = true;
    }
    // we found an edge loop with the GVertex that was specified
    if (found){
      // first build a list of edges in the parametric space
      std::vector<std::pair<MVertex*,SPoint2> > contour;
      for (GEdgeLoop::iter it2 = it->begin(); it2 != it->end(); ++it2){
	GEdge *ge = it2->ge;
	SPoint2 p[2];
	if (it2->_sign == 1){
	  for (int i=0;i<ge->lines.size();i++){
	    reparamMeshEdgeOnFace ( ge->lines[i]->getVertex(0), ge->lines[i]->getVertex(1),this,p[0],p[1]);	  	  
	    contour.push_back(std::make_pair(ge->lines[i]->getVertex(0),p[0]));
	  }
	}
	else {
	  for (int i=ge->lines.size()-1;i>=0;i--){
	    reparamMeshEdgeOnFace ( ge->lines[i]->getVertex(0), ge->lines[i]->getVertex(1),this,p[0],p[1]);	  	  
	    contour.push_back(std::make_pair(ge->lines[i]->getVertex(1),p[1]));
	  }
	}
      }      
      double hlayer = hmin;
      for (int j=0;j<nLayers;j++){
	for (int i=0;i<contour.size();i++){
	  SPoint2 p0 = contour[(i+0) % contour.size()].second;
	  SPoint2 p1 = contour[(i+1) % contour.size()].second;
	  SPoint2 p2 = contour[(i+2) % contour.size()].second;
	  SVector3 p0p1 (p1.x()-p0.x(),p1.y()-p0.y(),0.0);
	  SVector3 p1p2 (p2.x()-p1.x(),p2.y()-p1.y(),0.0);
	  SVector3 n01 = crossprod(ez,p0p1);
	  SVector3 n12 = crossprod(ez,p1p2);
	  SVector3 n = (n01+n12)*-0.5;
	  n.normalize();
	  double u = p1.x() + n.x() * hmin;
	  double v = p1.y() + n.y() * hmin;
	  GPoint gp = point(SPoint2(u,v));
	  _additional_vertices.push_back(new MFaceVertex(gp.x(),gp.y(),gp.z(),this,u,v));
	  fprintf(f,"SP(%g, %g, 0){1};\n",gp.x(),gp.y());
	}
	hlayer *= ratio;
	hmin += hlayer;
      }
      fprintf(f,"};\n");
      fclose(f);
    }
  }  
}


#include "Bindings.h"

void GFace::registerBindings(binding *b)
{
  classBinding *cb = b->addClass<GFace>("GFace");
  cb->setParentClass<GEntity>();
  cb->setDescription("A GFace is a geometrical 2D entity");
  methodBinding *mb;
  mb = cb->addMethod("lloyd", &GFace::lloyd);
  mb->setDescription("do N iteration of Lloyd's algorithm using or not the infinite norm");
  mb->setArgNames("N","infiniteNorm",NULL);
  mb = cb->addMethod("addTriangle", &GFace::addTriangle);
  mb->setDescription("insert a triangle mesh element");
  mb->setArgNames("triangle", NULL);
  mb = cb->addMethod("addQuadrangle", &GFace::addQuadrangle);
  mb->setDescription("insert a quadrangle mesh element");
  mb->setArgNames("quadrangle", NULL);
  mb = cb->addMethod("edges", &GFace::edges);
  mb->setDescription("return the list of edges bounding this surface");
  mb = cb->addMethod("addLayersOfQuads", &GFace::addLayersOfQuads);
  mb->setDescription("insert layers of quads");
  mb->setArgNames("nLayers","startingVertex", "hmin", "ratio", NULL);
/*  mb = cb->addMethod("addPolygon", &GFace::addPolygon);
  mb->setDescription("insert a polygon mesh element");
  mb->setArgNames("polygon", NULL);*/
}
