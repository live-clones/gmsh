// Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <map>
#include <unordered_map>
#include <unordered_set>
#include "MPolyhedron.h"
#include "GmshMessage.h"

MPolyhedron::MPolyhedron(const std::vector<MVertex *> &vertices, int num,
                         int part)
  : MElement(num, part), _givenTetrahedra(false)
{
  std::unordered_set<MVertex *> set;
  for(auto v : vertices) {
    if(set.insert(v).second) _vertices.push_back(v);
  }
  _numBoundary = _vertices.size();
}

void MPolyhedron::setPolygons(const std::vector<MVertex *> &borderVertices,
                              const std::vector<int> &borderOffset)
{
  std::unordered_map<MVertex *, int> indices;
  for(std::size_t i = 0; i < _numBoundary; i++) indices[_vertices[i]] = (int)i;
  _polygons.resize(borderVertices.size());
  for(std::size_t i = 0; i < borderVertices.size(); i++) {
    auto it = indices.find(borderVertices[i]);
    if(it == indices.end()) {
      Msg::Error("Face node %zu is not a node of polyhedron %zu",
                 borderVertices[i]->getNum(), getNum());
      _polygons[i] = 0;
    }
    else
      _polygons[i] = it->second;
  }
  _polygonStarts = borderOffset;
  _computeEdges();
}

void MPolyhedron::setTetrahedra(const std::vector<MVertex *> &simplicesVertices)
{
  // drop the interior nodes of a previous sub-tetrahedralization
  _vertices.resize(_numBoundary);
  _tetrahedra.clear();
  _triangles.clear();
  _givenTetrahedra = !simplicesVertices.empty();
  if(!_givenTetrahedra) return;
  std::unordered_map<MVertex *, int> indices;
  for(std::size_t i = 0; i < _vertices.size(); i++)
    indices[_vertices[i]] = (int)i;
  _tetrahedra.resize(simplicesVertices.size());
  for(std::size_t i = 0; i < simplicesVertices.size(); i++) {
    auto it = indices.find(simplicesVertices[i]);
    if(it == indices.end()) {
      it = indices.insert({simplicesVertices[i], (int)_vertices.size()}).first;
      _vertices.push_back(simplicesVertices[i]);
    }
    _tetrahedra[i] = it->second;
  }
  // orient the tetrahedra positively
  for(std::size_t i = 0; i < _tetrahedra.size(); i += 4) {
    MTetrahedron t(_vertices[_tetrahedra[i]], _vertices[_tetrahedra[i + 1]],
                   _vertices[_tetrahedra[i + 2]], _vertices[_tetrahedra[i + 3]]);
    if(t.getVolume() < 0.) std::swap(_tetrahedra[i + 2], _tetrahedra[i + 3]);
  }
  _computeTriangles();
}

void MPolyhedron::_computeEdges()
{
  // each edge once, whatever the orientation of the faces, with a face that
  // holds it (for the normals of the edge representation)
  std::map<std::pair<int, int>, int> edges;
  for(int i = 0; i < getNumPolygons(); i++) {
    int N = _polygonStarts[i + 1] - _polygonStarts[i];
    for(int j = 0; j < N; j++) {
      int i0 = _polygons[_polygonStarts[i] + j];
      int i1 = _polygons[_polygonStarts[i] + (j + 1) % N];
      edges.insert({{std::min(i0, i1), std::max(i0, i1)}, i});
    }
  }
  _lines.clear();
  _lineFaces.clear();
  for(auto &e : edges) {
    _lines.push_back(e.first.first);
    _lines.push_back(e.first.second);
    _lineFaces.push_back(e.second);
  }
}

void MPolyhedron::_computeTriangles() const
{
  // the faces of the tetrahedra that belong to a single one
  auto hasher = [](const std::array<int, 3> &t) -> std::size_t {
    auto [a, b, c] = t;
    return (uint64_t)a << 42 | (uint64_t)b << 21 | (uint64_t)c;
  };
  std::unordered_map<std::array<int, 3>, int, decltype(hasher)> faces(0,
                                                                      hasher);
  for(std::size_t i = 0; i < _tetrahedra.size(); i += 4) {
    for(int j = 0; j < 4; j++) {
      std::array<int, 3> t = {_tetrahedra[i + MTetrahedron::faces_tetra(j, 0)],
                              _tetrahedra[i + MTetrahedron::faces_tetra(j, 1)],
                              _tetrahedra[i + MTetrahedron::faces_tetra(j, 2)]};
      std::sort(t.begin(), t.end());
      ++faces[t];
    }
  }
  _triangles.clear();
  for(std::size_t i = 0; i < _tetrahedra.size(); i += 4) {
    for(int j = 0; j < 4; j++) {
      int i0 = _tetrahedra[i + MTetrahedron::faces_tetra(j, 0)];
      int i1 = _tetrahedra[i + MTetrahedron::faces_tetra(j, 1)];
      int i2 = _tetrahedra[i + MTetrahedron::faces_tetra(j, 2)];
      std::array<int, 3> t = {i0, i1, i2};
      std::sort(t.begin(), t.end());
      int n = faces[t];
      if(n == 1) {
        _triangles.push_back(i0);
        _triangles.push_back(i1);
        _triangles.push_back(i2);
      }
      else if(n != 2) {
        Msg::Error("Face %zu %zu %zu has more than 2 adjacent tetrahedra in "
                   "polyhedron %zu",
                   _vertices[i0]->getNum(), _vertices[i1]->getNum(),
                   _vertices[i2]->getNum(), getNum());
      }
    }
  }
}

void MPolyhedron::_ensureTetrahedra() const
{
  if(!_tetrahedra.empty() || !getNumPolygons()) return;

  // fan from the first vertex: each face is fanned into triangles from its
  // first vertex, and each triangle not holding the apex gives a tetrahedron,
  // oriented positively
  int apex = 0;
  MVertex *va = _vertices[apex];
  for(int i = 0; i < getNumPolygons(); i++) {
    int N = _polygonStarts[i + 1] - _polygonStarts[i];
    const int *f = &_polygons[_polygonStarts[i]];
    for(int j = 1; j < N - 1; j++) {
      int t[3] = {f[0], f[j], f[j + 1]};
      if(t[0] == apex || t[1] == apex || t[2] == apex) continue;
      MTetrahedron tet(va, _vertices[t[0]], _vertices[t[1]], _vertices[t[2]]);
      if(tet.getVolume() < 0.) std::swap(t[1], t[2]);
      _tetrahedra.push_back(apex);
      for(int k = 0; k < 3; k++) _tetrahedra.push_back(t[k]);
    }
  }
  _computeTriangles();
}

void MPolyhedron::getEdgeRep(bool curved, int num, double *x, double *y,
                             double *z, SVector3 *n)
{
  MEdge e = getEdge(num);
  SVector3 nf = getFace(_lineFaces[num]).normal();
  for(int i = 0; i < 2; i++) {
    x[i] = e.getVertex(i)->x();
    y[i] = e.getVertex(i)->y();
    z[i] = e.getVertex(i)->z();
    n[i] = nf;
  }
}

void MPolyhedron::getFaceRep(bool curved, int num, double *x, double *y,
                             double *z, SVector3 *n)
{
  std::array<int, 3> is = getFaceRepIndices(curved, num);
  _getFaceRep(_vertices[is[0]], _vertices[is[1]], _vertices[is[2]], x, y, z,
              n);
}

void MPolyhedron::reverse()
{
  for(int i = 0; i < getNumPolygons(); i++)
    std::reverse(_polygons.begin() + _polygonStarts[i],
                 _polygons.begin() + _polygonStarts[i + 1]);
  for(std::size_t i = 0; i < _tetrahedra.size(); i += 4)
    std::swap(_tetrahedra[i + 2], _tetrahedra[i + 3]);
  for(std::size_t i = 0; i < _triangles.size(); i += 3)
    std::swap(_triangles[i + 1], _triangles[i + 2]);
}

double MPolyhedron::getVolume()
{
  double v = 0.;
  for(int i = 0; i < getNumTetrahedra(); i++)
    v += getTetrahedron(i).getVolume();
  return v;
}

double MPolyhedron::getJacobian(double u, double v, double w,
                                double jac[3][3]) const
{
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++) jac[i][j] = (i == j) ? 1. : 0.;
  return 1.;
}

int MPolyhedron::_findTetrahedron(double x, double y, double z,
                                  double bary[4]) const
{
  int best = -1;
  double bestMin = -1e300;
  for(int i = 0; i < getNumTetrahedra(); i++) {
    std::array<int, 4> is = getTetrahedronIndices(i);
    MVertex *v0 = _vertices[is[0]];
    SVector3 a(_vertices[is[1]]->x() - v0->x(), _vertices[is[1]]->y() - v0->y(),
               _vertices[is[1]]->z() - v0->z());
    SVector3 b(_vertices[is[2]]->x() - v0->x(), _vertices[is[2]]->y() - v0->y(),
               _vertices[is[2]]->z() - v0->z());
    SVector3 c(_vertices[is[3]]->x() - v0->x(), _vertices[is[3]]->y() - v0->y(),
               _vertices[is[3]]->z() - v0->z());
    SVector3 p(x - v0->x(), y - v0->y(), z - v0->z());
    double det = dot(a, crossprod(b, c));
    if(det == 0.) continue;
    double b1 = dot(p, crossprod(b, c)) / det;
    double b2 = dot(a, crossprod(p, c)) / det;
    double b3 = dot(a, crossprod(b, p)) / det;
    double b0 = 1. - b1 - b2 - b3;
    double m = std::min(std::min(b0, b1), std::min(b2, b3));
    if(m > bestMin) {
      bestMin = m;
      best = i;
      bary[0] = b0;
      bary[1] = b1;
      bary[2] = b2;
      bary[3] = b3;
    }
  }
  return best;
}

bool MPolyhedron::isInside(double u, double v, double w) const
{
  double bary[4];
  int i = _findTetrahedron(u, v, w, bary);
  if(i < 0) return false;
  double tol = getTolerance();
  for(int k = 0; k < 4; k++)
    if(bary[k] < -tol) return false;
  return true;
}

void MPolyhedron::getIntegrationPoints(int pOrder, int *npts, IntPt **pts)
{
  int n = getNGQTetPts(pOrder);
  IntPt *p = getGQTetPts(pOrder);
  _intpt.clear();
  for(int i = 0; i < getNumTetrahedra(); i++) {
    MTetrahedron t = getTetrahedron(i);
    for(int j = 0; j < n; j++) {
      IntPt ip;
      t.pnt(p[j].pt[0], p[j].pt[1], p[j].pt[2], ip.pt);
      ip.weight = p[j].weight * t.getJacobianDeterminant(p[j].pt[0],
                                                         p[j].pt[1],
                                                         p[j].pt[2]);
      _intpt.push_back(ip);
    }
  }
  *npts = (int)_intpt.size();
  *pts = _intpt.empty() ? nullptr : &_intpt[0];
}

void MPolyhedron::getShapeFunctions(double u, double v, double w, double s[],
                                    int order) const
{
  for(std::size_t i = 0; i < _vertices.size(); i++) s[i] = 0.;
  double bary[4];
  int i = _findTetrahedron(u, v, w, bary);
  if(i < 0) return;
  std::array<int, 4> is = getTetrahedronIndices(i);
  for(int k = 0; k < 4; k++) s[is[k]] = bary[k];
}

void MPolyhedron::getGradShapeFunctions(double u, double v, double w,
                                        double s[][3], int order) const
{
  for(std::size_t i = 0; i < _vertices.size(); i++)
    s[i][0] = s[i][1] = s[i][2] = 0.;
  double bary[4];
  int i = _findTetrahedron(u, v, w, bary);
  if(i < 0) return;
  // grad lambda_k = (opposite face normal, inwards) / (3 volume)
  std::array<int, 4> is = getTetrahedronIndices(i);
  SVector3 p[4];
  for(int k = 0; k < 4; k++)
    p[k] = SVector3(_vertices[is[k]]->x(), _vertices[is[k]]->y(),
                    _vertices[is[k]]->z());
  double det = dot(p[1] - p[0], crossprod(p[2] - p[0], p[3] - p[0]));
  if(det == 0.) return;
  for(int k = 0; k < 4; k++) {
    int a = (k + 1) % 4, b = (k + 2) % 4, c = (k + 3) % 4;
    SVector3 g = crossprod(p[b] - p[a], p[c] - p[a]) * (1. / det);
    if(k % 2) g = -g; // orientation of the opposite face alternates
    for(int d = 0; d < 3; d++) s[is[k]][d] = g[d];
  }
}

void MPolyhedron::getHessShapeFunctions(double u, double v, double w,
                                        double s[][3][3], int order) const
{
  for(std::size_t i = 0; i < _vertices.size(); i++)
    for(int j = 0; j < 3; j++)
      for(int k = 0; k < 3; k++) s[i][j][k] = 0.;
}

void MPolyhedron::scaledJacRange(double &jmin, double &jmax,
                                 GEntity *ge) const
{
  jmin = 1e300;
  jmax = -1e300;
  for(int i = 0; i < getNumTetrahedra(); i++) {
    double a, b;
    getTetrahedron(i).scaledJacRange(a, b, ge);
    jmin = std::min(jmin, a);
    jmax = std::max(jmax, b);
  }
  if(jmin > jmax) jmin = jmax = 0.;
}

void MPolyhedron::idealJacRange(double &jmin, double &jmax, GEntity *ge)
{
  jmin = 1e300;
  jmax = -1e300;
  for(int i = 0; i < getNumTetrahedra(); i++) {
    double a, b;
    getTetrahedron(i).idealJacRange(a, b, ge);
    jmin = std::min(jmin, a);
    jmax = std::max(jmax, b);
  }
  if(jmin > jmax) jmin = jmax = 0.;
}

void MPolyhedron::signedInvCondNumRange(double &iCNMin, double &iCNMax,
                                        GEntity *ge)
{
  iCNMin = 1e300;
  iCNMax = -1e300;
  for(int i = 0; i < getNumTetrahedra(); i++) {
    double a, b;
    getTetrahedron(i).signedInvCondNumRange(a, b, ge);
    iCNMin = std::min(iCNMin, a);
    iCNMax = std::max(iCNMax, b);
  }
  if(iCNMin > iCNMax) iCNMin = iCNMax = 0.;
}

void MPolyhedron::signedInvGradErrorRange(double &minSIGE, double &maxSIGE)
{
  minSIGE = 1e300;
  maxSIGE = -1e300;
  for(int i = 0; i < getNumTetrahedra(); i++) {
    double a, b;
    getTetrahedron(i).signedInvGradErrorRange(a, b);
    minSIGE = std::min(minSIGE, a);
    maxSIGE = std::max(maxSIGE, b);
  }
  if(minSIGE > maxSIGE) minSIGE = maxSIGE = 0.;
}
