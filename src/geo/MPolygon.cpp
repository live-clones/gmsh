// Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <unordered_map>
#include "MPolygon.h"
#include "GmshMessage.h"

MPolygon::MPolygon(const std::vector<MVertex *> &vertices, int num, int part)
  : MElement(num, part), _vertices(vertices),
    _numBoundary((int)vertices.size()), _givenTriangles(false)
{
}

SVector3 MPolygon::getNormal() const
{
  SVector3 n(0., 0., 0.);
  for(int i = 0; i < _numBoundary; i++) {
    MVertex *a = _vertices[i], *b = _vertices[(i + 1) % _numBoundary];
    n[0] += (a->y() - b->y()) * (a->z() + b->z());
    n[1] += (a->z() - b->z()) * (a->x() + b->x());
    n[2] += (a->x() - b->x()) * (a->y() + b->y());
  }
  if(n.norm() > 0.) n.normalize();
  return n;
}

void MPolygon::setTriangles(const std::vector<MVertex *> &simplices)
{
  _triangles.clear();
  _vertices.resize(_numBoundary);
  _givenTriangles = !simplices.empty();
  if(!_givenTriangles) return;
  std::unordered_map<MVertex *, int> indices;
  for(std::size_t i = 0; i < _vertices.size(); i++)
    indices[_vertices[i]] = (int)i;
  _triangles.resize(simplices.size());
  for(std::size_t i = 0; i < simplices.size(); i++) {
    auto it = indices.find(simplices[i]);
    if(it == indices.end()) {
      it = indices.insert({simplices[i], (int)_vertices.size()}).first;
      _vertices.push_back(simplices[i]);
    }
    _triangles[i] = it->second;
  }
  // orient the triangles like the polygon
  SVector3 normal = getNormal();
  for(std::size_t i = 0; i < _triangles.size(); i += 3) {
    MVertex *v0 = _vertices[_triangles[i]], *v1 = _vertices[_triangles[i + 1]],
            *v2 = _vertices[_triangles[i + 2]];
    SVector3 n = crossprod(
      SVector3(v1->x() - v0->x(), v1->y() - v0->y(), v1->z() - v0->z()),
      SVector3(v2->x() - v0->x(), v2->y() - v0->y(), v2->z() - v0->z()));
    if(dot(n, normal) < 0.) std::swap(_triangles[i + 1], _triangles[i + 2]);
  }
}

void MPolygon::_ensureTriangles() const
{
  if(!_triangles.empty() || _numBoundary < 3) return;

  // ear clipping in the plane of the polygon
  SVector3 normal = getNormal();
  SVector3 e1 = (fabs(normal[0]) < 0.9) ?
                  crossprod(normal, SVector3(1., 0., 0.)) :
                  crossprod(normal, SVector3(0., 1., 0.));
  e1.normalize();
  SVector3 e2 = crossprod(normal, e1);
  int N = _numBoundary;
  std::vector<double> x(N), y(N);
  double scale = 0.;
  for(int i = 0; i < N; i++) {
    SVector3 p(_vertices[i]->x(), _vertices[i]->y(), _vertices[i]->z());
    x[i] = dot(p, e1);
    y[i] = dot(p, e2);
  }
  for(int i = 0; i < N; i++) {
    int j = (i + 1) % N;
    scale = std::max(scale, fabs(x[j] - x[i]) + fabs(y[j] - y[i]));
  }
  double eps = 1e-10 * scale * scale;
  auto cross = [&](int a, int b, int c) {
    return (x[b] - x[a]) * (y[c] - y[a]) - (y[b] - y[a]) * (x[c] - x[a]);
  };
  auto inside = [&](int p, int a, int b, int c) {
    return cross(a, b, p) >= -eps && cross(b, c, p) >= -eps &&
           cross(c, a, p) >= -eps;
  };

  std::vector<int> ring(N);
  for(int i = 0; i < N; i++) ring[i] = i;
  while(ring.size() > 3) {
    int n = (int)ring.size(), ear = -1, flat = -1;
    for(int i = 0; i < n && ear < 0; i++) {
      int a = ring[(i + n - 1) % n], b = ring[i], c = ring[(i + 1) % n];
      double cr = cross(a, b, c);
      if(fabs(cr) <= eps) {
        // a node on a straight part of the boundary (e.g. a hanging node): not
        // an ear, but it can be dropped without changing the region
        if(flat < 0) flat = i;
        continue;
      }
      if(cr < 0.) continue; // reflex
      bool ok = true;
      for(int j = 0; j < n && ok; j++) {
        int p = ring[j];
        if(p != a && p != b && p != c && inside(p, a, b, c)) ok = false;
      }
      if(ok) ear = i;
    }
    if(ear >= 0) {
      int n = (int)ring.size();
      _triangles.push_back(ring[(ear + n - 1) % n]);
      _triangles.push_back(ring[ear]);
      _triangles.push_back(ring[(ear + 1) % n]);
      ring.erase(ring.begin() + ear);
    }
    else if(flat >= 0) {
      ring.erase(ring.begin() + flat);
    }
    else {
      Msg::Warning("Could not triangulate polygon %zu: using a fan", getNum());
      _triangles.clear();
      for(int i = 1; i < N - 1; i++) {
        _triangles.push_back(0);
        _triangles.push_back(i);
        _triangles.push_back(i + 1);
      }
      return;
    }
  }
  if(ring.size() == 3) {
    _triangles.push_back(ring[0]);
    _triangles.push_back(ring[1]);
    _triangles.push_back(ring[2]);
  }
}

void MPolygon::getEdgeRep(bool curved, int num, double *x, double *y,
                          double *z, SVector3 *n)
{
  MEdge e = getEdge(num);
  SVector3 normal = getNormal();
  for(int i = 0; i < 2; i++) {
    x[i] = e.getVertex(i)->x();
    y[i] = e.getVertex(i)->y();
    z[i] = e.getVertex(i)->z();
    n[i] = normal;
  }
}

void MPolygon::getFaceRep(bool curved, int num, double *x, double *y,
                          double *z, SVector3 *n)
{
  std::array<int, 3> is = getTriangleIndices(num);
  _getFaceRep(_vertices[is[0]], _vertices[is[1]], _vertices[is[2]], x, y, z,
              n);
}

void MPolygon::reverse()
{
  std::reverse(_vertices.begin(), _vertices.begin() + _numBoundary);
  // the boundary indices changed: i -> numBoundary - 1 - i
  for(auto &t : _triangles)
    if(t < _numBoundary) t = _numBoundary - 1 - t;
  for(std::size_t i = 0; i < _triangles.size(); i += 3)
    std::swap(_triangles[i + 1], _triangles[i + 2]);
}

double MPolygon::getVolume()
{
  double v = 0.;
  for(int i = 0; i < getNumTriangles(); i++) v += getTriangle(i).getVolume();
  return v;
}

double MPolygon::getJacobian(double u, double v, double w,
                             double jac[3][3]) const
{
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++) jac[i][j] = (i == j) ? 1. : 0.;
  return 1.;
}

int MPolygon::_findTriangle(double x, double y, double z, double bary[3],
                            double &dist) const
{
  int best = -1;
  double bestMin = -1e300;
  for(int i = 0; i < getNumTriangles(); i++) {
    std::array<int, 3> is = getTriangleIndices(i);
    MVertex *v0 = _vertices[is[0]], *v1 = _vertices[is[1]],
            *v2 = _vertices[is[2]];
    SVector3 a(v1->x() - v0->x(), v1->y() - v0->y(), v1->z() - v0->z());
    SVector3 b(v2->x() - v0->x(), v2->y() - v0->y(), v2->z() - v0->z());
    SVector3 p(x - v0->x(), y - v0->y(), z - v0->z());
    double aa = dot(a, a), ab = dot(a, b), bb = dot(b, b), pa = dot(p, a),
           pb = dot(p, b);
    double den = aa * bb - ab * ab;
    if(den <= 0.) continue;
    double b1 = (bb * pa - ab * pb) / den, b2 = (aa * pb - ab * pa) / den;
    double b0 = 1. - b1 - b2;
    double m = std::min(b0, std::min(b1, b2));
    if(m > bestMin) {
      bestMin = m;
      best = i;
      bary[0] = b0;
      bary[1] = b1;
      bary[2] = b2;
      SVector3 nn = crossprod(a, b);
      dist = (nn.norm() > 0.) ? fabs(dot(p, nn)) / nn.norm() : 0.;
    }
  }
  return best;
}

bool MPolygon::isInside(double u, double v, double w) const
{
  double bary[3], dist;
  int i = _findTriangle(u, v, w, bary, dist);
  if(i < 0) return false;
  double tol = getTolerance();
  if(bary[0] < -tol || bary[1] < -tol || bary[2] < -tol) return false;
  // out of the plane: compare with the size of the triangle
  MTriangle t = getTriangle(i);
  return dist <= tol * t.maxEdge();
}

void MPolygon::getIntegrationPoints(int pOrder, int *npts, IntPt **pts)
{
  // the points are consumed right away by the caller (as those of the simplex
  // rules, which are static tables): no need to keep them per element
  static thread_local std::vector<IntPt> intpt;
  int n = getNGQTPts(pOrder);
  IntPt *p = getGQTPts(pOrder);
  intpt.clear();
  for(int i = 0; i < getNumTriangles(); i++) {
    MTriangle t = getTriangle(i);
    for(int j = 0; j < n; j++) {
      IntPt ip;
      t.pnt(p[j].pt[0], p[j].pt[1], p[j].pt[2], ip.pt);
      ip.weight = p[j].weight * t.getJacobianDeterminant(p[j].pt[0],
                                                         p[j].pt[1], 0.);
      intpt.push_back(ip);
    }
  }
  *npts = (int)intpt.size();
  *pts = intpt.empty() ? nullptr : &intpt[0];
}

void MPolygon::getShapeFunctions(double u, double v, double w, double s[],
                                 int order) const
{
  for(std::size_t i = 0; i < _vertices.size(); i++) s[i] = 0.;
  double bary[3], dist;
  int i = _findTriangle(u, v, w, bary, dist);
  if(i < 0) return;
  std::array<int, 3> is = getTriangleIndices(i);
  for(int k = 0; k < 3; k++) s[is[k]] = bary[k];
}

void MPolygon::getGradShapeFunctions(double u, double v, double w,
                                     double s[][3], int order) const
{
  for(std::size_t i = 0; i < _vertices.size(); i++)
    s[i][0] = s[i][1] = s[i][2] = 0.;
  double bary[3], dist;
  int i = _findTriangle(u, v, w, bary, dist);
  if(i < 0) return;
  // gradient of the barycentric coordinates in the plane of the triangle
  std::array<int, 3> is = getTriangleIndices(i);
  SVector3 p[3];
  for(int k = 0; k < 3; k++)
    p[k] = SVector3(_vertices[is[k]]->x(), _vertices[is[k]]->y(),
                    _vertices[is[k]]->z());
  SVector3 n = crossprod(p[1] - p[0], p[2] - p[0]);
  double n2 = dot(n, n);
  if(n2 <= 0.) return;
  for(int k = 0; k < 3; k++) {
    // grad lambda_k = n x (p_{k+2} - p_{k+1}) / |n|^2
    SVector3 g = crossprod(n, p[(k + 2) % 3] - p[(k + 1) % 3]) * (1. / n2);
    for(int d = 0; d < 3; d++) s[is[k]][d] = g[d];
  }
}

void MPolygon::getHessShapeFunctions(double u, double v, double w,
                                     double s[][3][3], int order) const
{
  for(std::size_t i = 0; i < _vertices.size(); i++)
    for(int j = 0; j < 3; j++)
      for(int k = 0; k < 3; k++) s[i][j][k] = 0.;
}

void MPolygon::scaledJacRange(double &jmin, double &jmax, GEntity *ge) const
{
  jmin = 1e300;
  jmax = -1e300;
  for(int i = 0; i < getNumTriangles(); i++) {
    double a, b;
    getTriangle(i).scaledJacRange(a, b, ge);
    jmin = std::min(jmin, a);
    jmax = std::max(jmax, b);
  }
  if(jmin > jmax) jmin = jmax = 0.;
}

void MPolygon::idealJacRange(double &jmin, double &jmax, GEntity *ge)
{
  jmin = 1e300;
  jmax = -1e300;
  for(int i = 0; i < getNumTriangles(); i++) {
    double a, b;
    getTriangle(i).idealJacRange(a, b, ge);
    jmin = std::min(jmin, a);
    jmax = std::max(jmax, b);
  }
  if(jmin > jmax) jmin = jmax = 0.;
}

void MPolygon::signedInvCondNumRange(double &iCNMin, double &iCNMax,
                                     GEntity *ge)
{
  iCNMin = 1e300;
  iCNMax = -1e300;
  for(int i = 0; i < getNumTriangles(); i++) {
    double a, b;
    getTriangle(i).signedInvCondNumRange(a, b, ge);
    iCNMin = std::min(iCNMin, a);
    iCNMax = std::max(iCNMax, b);
  }
  if(iCNMin > iCNMax) iCNMin = iCNMax = 0.;
}

void MPolygon::signedInvGradErrorRange(double &minSIGE, double &maxSIGE)
{
  minSIGE = 1e300;
  maxSIGE = -1e300;
  for(int i = 0; i < getNumTriangles(); i++) {
    double a, b;
    getTriangle(i).signedInvGradErrorRange(a, b);
    minSIGE = std::min(minSIGE, a);
    maxSIGE = std::max(maxSIGE, b);
  }
  if(minSIGE > maxSIGE) minSIGE = maxSIGE = 0.;
}
