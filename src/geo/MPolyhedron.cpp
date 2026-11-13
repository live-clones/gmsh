// Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include <climits>
#include <set>
#include "MPolyhedron.h"
#include "GmshMessage.h"

// A polyhedron has a few tens of nodes: they are looked up in a sorted copy,
// which is much cheaper to build than a hash table
namespace {
  struct NodeIndex {
    std::vector<std::pair<MVertex *, int>> sorted;
    void build(const std::vector<MVertex *> &v, int n)
    {
      sorted.resize(n);
      for(int i = 0; i < n; i++) sorted[i] = {v[i], i};
      std::sort(sorted.begin(), sorted.end());
    }
    int find(MVertex *v) const
    {
      auto it = std::lower_bound(sorted.begin(), sorted.end(),
                                 std::make_pair(v, INT_MIN));
      return (it != sorted.end() && it->first == v) ? it->second : -1;
    }
  };

  double signedVolume(const MVertex *a, const MVertex *b, const MVertex *c,
                      const MVertex *d)
  {
    double u[3] = {b->x() - a->x(), b->y() - a->y(), b->z() - a->z()};
    double v[3] = {c->x() - a->x(), c->y() - a->y(), c->z() - a->z()};
    double w[3] = {d->x() - a->x(), d->y() - a->y(), d->z() - a->z()};
    return u[0] * (v[1] * w[2] - v[2] * w[1]) -
           u[1] * (v[0] * w[2] - v[2] * w[0]) +
           u[2] * (v[0] * w[1] - v[1] * w[0]);
  }
} // namespace

MPolyhedron::MPolyhedron(const std::vector<MVertex *> &vertices, int num,
                         int part)
  : MElement(num, part), _numFaces(0), _tetOffset(0), _givenTetrahedra(false)
{
  // each node once, in the order of its first occurrence
  NodeIndex index;
  index.build(vertices, (int)vertices.size());
  std::vector<char> first(vertices.size(), 0);
  for(std::size_t i = 0; i < index.sorted.size(); i++)
    if(!i || index.sorted[i].first != index.sorted[i - 1].first)
      first[index.sorted[i].second] = 1;
  for(std::size_t i = 0; i < vertices.size(); i++)
    if(first[i]) _vertices.push_back(vertices[i]);
  _numBoundary = (int)_vertices.size();
}

void MPolyhedron::setPolygons(const std::vector<MVertex *> &borderVertices,
                              const std::vector<int> &borderOffset)
{
  NodeIndex index;
  index.build(_vertices, _numBoundary);
  _numFaces = borderOffset.empty() ? 0 : (int)borderOffset.size() - 1;
  _data.clear();
  _data.reserve(_numFaces + 1 + borderVertices.size());
  for(int i = 0; i <= _numFaces; i++) _data.push_back(borderOffset[i]);
  for(std::size_t i = 0; i < borderVertices.size(); i++) {
    int j = index.find(borderVertices[i]);
    if(j < 0) {
      Msg::Error("Face node %zu is not a node of polyhedron %zu",
                 borderVertices[i]->getNum(), getNum());
      j = 0;
    }
    _data.push_back(j);
  }
  _tetOffset = (int)_data.size();
  _edges.clear();
  _repTriangles.clear();
}

void MPolyhedron::setTetrahedra(const std::vector<MVertex *> &simplicesVertices)
{
  // drop the interior nodes of a previous sub-tetrahedralization
  _vertices.resize(_numBoundary);
  _repTriangles.clear();
  _data.resize(_tetOffset);
  _givenTetrahedra = !simplicesVertices.empty();
  if(!_givenTetrahedra) return;
  // the face nodes, and the interior nodes appended as they come (they are
  // few)
  NodeIndex index;
  index.build(_vertices, _numBoundary);
  _data.reserve(_data.size() + simplicesVertices.size());
  for(std::size_t i = 0; i < simplicesVertices.size(); i++) {
    MVertex *v = simplicesVertices[i];
    int j = index.find(v);
    if(j < 0) {
      auto it = std::find(_vertices.begin() + _numBoundary, _vertices.end(), v);
      j = (int)(it - _vertices.begin());
      if(it == _vertices.end()) _vertices.push_back(v);
    }
    _data.push_back(j);
  }
  // orient the tetrahedra positively
  for(std::size_t i = _tetOffset; i + 3 < _data.size(); i += 4) {
    if(signedVolume(_vertices[_data[i]], _vertices[_data[i + 1]],
                    _vertices[_data[i + 2]], _vertices[_data[i + 3]]) < 0.)
      std::swap(_data[i + 2], _data[i + 3]);
  }
}

void MPolyhedron::_ensureEdges() const
{
  if(!_edges.empty() || !_numFaces) return;
  // each edge once, whatever the orientation of the faces, in the order of
  // their nodes
  std::vector<std::pair<int, int>> edges;
  const int *f = _faceIndices();
  edges.reserve(_data[_numFaces]);
  for(int i = 0; i < _numFaces; i++) {
    int N = _data[i + 1] - _data[i];
    for(int j = 0; j < N; j++) {
      int i0 = f[_data[i] + j], i1 = f[_data[i] + (j + 1) % N];
      edges.push_back({std::min(i0, i1), std::max(i0, i1)});
    }
  }
  std::sort(edges.begin(), edges.end());
  edges.erase(std::unique(edges.begin(), edges.end()), edges.end());
  _edges.reserve(2 * edges.size());
  for(auto &e : edges) {
    _edges.push_back(e.first);
    _edges.push_back(e.second);
  }
}

void MPolyhedron::_ensureTetrahedra() const
{
  if((int)_data.size() > _tetOffset || !_numFaces) return;

  // fan from the first vertex: each face not holding the apex is fanned into
  // triangles from its first vertex, and each triangle gives a tetrahedron,
  // oriented positively (a face holding the apex would only give flat
  // tetrahedra, from its triangles that do not hold it)
  int apex = 0;
  MVertex *va = _vertices[apex];
  std::vector<int> tets; // appended to _data at the end: the face pointers
                         // would be invalidated by a reallocation
  const int *f = _faceIndices();
  for(int i = 0; i < _numFaces; i++) {
    int N = _data[i + 1] - _data[i];
    const int *fi = &f[_data[i]];
    if(std::find(fi, fi + N, apex) != fi + N) continue;
    for(int j = 1; j < N - 1; j++) {
      int t[3] = {fi[0], fi[j], fi[j + 1]};
      if(signedVolume(va, _vertices[t[0]], _vertices[t[1]], _vertices[t[2]]) <
         0.)
        std::swap(t[1], t[2]);
      tets.push_back(apex);
      for(int k = 0; k < 3; k++) tets.push_back(t[k]);
    }
  }
  _data.insert(_data.end(), tets.begin(), tets.end());
}

void MPolyhedron::_ensureRepTriangles() const
{
  if(!_repTriangles.empty() || !_givenTetrahedra) return;
  // the faces of the (positively oriented) tetrahedra, oriented outwards,
  // sorted by their nodes: those met once are on the boundary
  std::vector<std::pair<std::array<int, 3>, std::array<int, 3>>> faces;
  for(std::size_t i = _tetOffset; i + 3 < _data.size(); i += 4) {
    int a = _data[i], b = _data[i + 1], c = _data[i + 2], d = _data[i + 3];
    std::array<int, 3> fs[4] = {{a, c, b}, {a, b, d}, {a, d, c}, {b, c, d}};
    for(auto &f : fs) {
      std::array<int, 3> k = f;
      std::sort(k.begin(), k.end());
      faces.push_back({k, f});
    }
  }
  std::sort(faces.begin(), faces.end(),
            [](const std::pair<std::array<int, 3>, std::array<int, 3>> &x,
               const std::pair<std::array<int, 3>, std::array<int, 3>> &y) {
              return x.first < y.first;
            });
  for(std::size_t i = 0; i < faces.size();) {
    std::size_t j = i + 1;
    while(j < faces.size() && faces[j].first == faces[i].first) j++;
    if(j == i + 1)
      _repTriangles.insert(_repTriangles.end(), faces[i].second.begin(),
                           faces[i].second.end());
    i = j;
  }
}

int MPolyhedron::getNumFacesRep(bool curved)
{
  if(_givenTetrahedra) {
    _ensureRepTriangles();
    return (int)_repTriangles.size() / 3;
  }
  int n = 0;
  for(int i = 0; i < _numFaces; i++) n += _data[i + 1] - _data[i] - 2;
  return n;
}

std::array<int, 3> MPolyhedron::getFaceRepIndices(bool curved, int num) const
{
  if(_givenTetrahedra) {
    _ensureRepTriangles();
    const int *t = &_repTriangles[3 * num];
    return {t[0], t[1], t[2]};
  }
  // the num-th triangle of the fans of the faces
  const int *f = _faceIndices();
  for(int i = 0; i < _numFaces; i++) {
    int n = _data[i + 1] - _data[i] - 2;
    if(num < n) {
      const int *fi = &f[_data[i]];
      return {fi[0], fi[num + 1], fi[num + 2]};
    }
    num -= n;
  }
  return {0, 0, 0};
}

void MPolyhedron::getEdgeRep(bool curved, int num, double *x, double *y,
                             double *z, SVector3 *n)
{
  std::array<int, 2> is = getEdgeIndices(num);
  // the normal of a face holding the edge
  SVector3 nf(0., 0., 1.);
  const int *f = _faceIndices();
  for(int i = 0; i < _numFaces; i++) {
    int N = _data[i + 1] - _data[i];
    bool has0 = false, has1 = false;
    for(int j = 0; j < N; j++) {
      if(f[_data[i] + j] == is[0]) has0 = true;
      if(f[_data[i] + j] == is[1]) has1 = true;
    }
    if(has0 && has1) {
      nf = getFace(i).normal();
      break;
    }
  }
  for(int i = 0; i < 2; i++) {
    x[i] = _vertices[is[i]]->x();
    y[i] = _vertices[is[i]]->y();
    z[i] = _vertices[is[i]]->z();
    n[i] = nf;
  }
}

void MPolyhedron::getFaceRep(bool curved, int num, double *x, double *y,
                             double *z, SVector3 *n)
{
  std::array<int, 3> is = getFaceRepIndices(curved, num);
  _getFaceRep(_vertices[is[0]], _vertices[is[1]], _vertices[is[2]], x, y, z, n);
}

void MPolyhedron::reverse()
{
  for(int i = 0; i < _numFaces; i++)
    std::reverse(_data.begin() + _numFaces + 1 + _data[i],
                 _data.begin() + _numFaces + 1 + _data[i + 1]);
  for(std::size_t i = _tetOffset; i + 3 < _data.size(); i += 4)
    std::swap(_data[i + 2], _data[i + 3]);
  _repTriangles.clear();
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

bool MPolyhedron::isInside(double u, double v, double w, double tol) const
{
  double bary[4];
  int i = _findTetrahedron(u, v, w, bary);
  if(i < 0) return false;
  for(int k = 0; k < 4; k++)
    if(bary[k] < -tol) return false;
  return true;
}

double MPolyhedron::integrate(double val[], int pOrder, int stride, int order)
{
  double sum = 0.;
  for(int i = 0; i < getNumTetrahedra(); i++) {
    std::array<int, 4> t = getTetrahedronIndices(i);
    MVertex *v[4] = {_vertices[t[0]], _vertices[t[1]], _vertices[t[2]],
                     _vertices[t[3]]};
    double a[3] = {v[1]->x() - v[0]->x(), v[1]->y() - v[0]->y(),
                   v[1]->z() - v[0]->z()};
    double b[3] = {v[2]->x() - v[0]->x(), v[2]->y() - v[0]->y(),
                   v[2]->z() - v[0]->z()};
    double c[3] = {v[3]->x() - v[0]->x(), v[3]->y() - v[0]->y(),
                   v[3]->z() - v[0]->z()};
    double vol = std::abs(a[0] * (b[1] * c[2] - b[2] * c[1]) -
                          a[1] * (b[0] * c[2] - b[2] * c[0]) +
                          a[2] * (b[0] * c[1] - b[1] * c[0])) /
                 6.;
    sum += vol *
           (val[stride * t[0]] + val[stride * t[1]] + val[stride * t[2]] +
            val[stride * t[3]]) /
           4.;
  }
  return sum;
}

void MPolyhedron::getIntegrationPoints(int pOrder, int *npts, IntPt **pts)
{
  // consumed right away by the caller: a shared buffer is enough
  static thread_local std::vector<IntPt> intpt;
  int n = getNGQTetPts(pOrder);
  IntPt *p = getGQTetPts(pOrder);
  intpt.clear();
  for(int i = 0; i < getNumTetrahedra(); i++) {
    MTetrahedron t = getTetrahedron(i);
    for(int j = 0; j < n; j++) {
      IntPt ip;
      t.pnt(p[j].pt[0], p[j].pt[1], p[j].pt[2], ip.pt);
      ip.weight = p[j].weight *
                  t.getJacobianDeterminant(p[j].pt[0], p[j].pt[1], p[j].pt[2]);
      intpt.push_back(ip);
    }
  }
  *npts = (int)intpt.size();
  *pts = intpt.empty() ? nullptr : &intpt[0];
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

void MPolyhedron::scaledJacRange(double &jmin, double &jmax, GEntity *ge) const
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
