// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <vector>
#include <algorithm>
#include "GmshConfig.h"
#include "MFace.h"
#include "Numeric.h"
#include "ElementType.h"
#include "nodalBasis.h"
#include "BasisFactory.h"

bool compare(const MVertex *const v0, const MVertex *const v1)
{
  return v0->getNum() < v1->getNum();
}

void sortVertices(const std::vector<MVertex *> &v, std::vector<char> &s)
{
  if(v.size() == 3) {
    s.resize(3);
    if(v[0]->getNum() < v[1]->getNum() && v[0]->getNum() < v[2]->getNum()) {
      s[0] = 0;
      s[1] = 1;
      s[2] = 2;
    }
    else if(v[1]->getNum() < v[0]->getNum() &&
            v[1]->getNum() < v[2]->getNum()) {
      s[0] = 1;
      s[1] = 0;
      s[2] = 2;
    }
    else {
      s[0] = 2;
      s[1] = 0;
      s[2] = 1;
    }

    if(v[s[2]]->getNum() < v[s[1]]->getNum()) {
      char temp = s[1];
      s[1] = s[2];
      s[2] = temp;
    }
    return;
  }

  std::vector<MVertex *> sorted = v;
  std::sort(sorted.begin(), sorted.end(), compare);
  s.reserve(sorted.size());
  for(std::size_t i = 0; i < sorted.size(); i++)
    s.push_back(
      std::distance(v.begin(), std::find(v.begin(), v.end(), sorted[i])));
}

MFace::MFace(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3)
{
  _v.reserve(v3 ? 4 : 3);
  _v.push_back(v0);
  _v.push_back(v1);
  _v.push_back(v2);
  if(v3) _v.push_back(v3);
  sortVertices(_v, _si);
}

MFace::MFace(const std::vector<MVertex *> &v)
{
  _v.reserve(v.size());
  for(std::size_t i = 0; i < v.size(); i++) _v.push_back(v[i]);
  sortVertices(_v, _si);
}
void MFace::getOrientationFlagForFace(std::vector<int> &faceOrientationFlag)
{ // Reference :  "Higher-Order Finite Element  Methods"; Pavel Solin, Karel
  // Segeth ,
  //                 Ivo Dolezel , Chapman and Hall/CRC; Edition : Har/Cdr
  //                 (2003)
  if(_v.size() == 3) { // triangular face
    if(_v[int(_si[0])]->getNum() == _v[0]->getNum()) {
      faceOrientationFlag[0] = 0;
      if(_v[int(_si[1])]->getNum() == _v[1]->getNum()) {
        faceOrientationFlag[1] = 1;
      }
      else {
        faceOrientationFlag[1] = -1;
      }
    }
    else {
      if(_v[1]->getNum() == _v[int(_si[0])]->getNum()) {
        faceOrientationFlag[0] = 1;
        if(_v[0]->getNum() == _v[int(_si[2])]->getNum()) {
          faceOrientationFlag[1] = 1;
        }
        else {
          faceOrientationFlag[1] = -1;
        }
      }
      else {
        faceOrientationFlag[0] = 2;
        if(_v[1]->getNum() == _v[int(_si[2])]->getNum()) {
          faceOrientationFlag[1] = 1;
        }
        else {
          faceOrientationFlag[1] = -1;
        }
      }
    }
  }
  else { // quadrilateral face
    int c = 0;
    for(int i = 0; i < 4; i++) {
      if(_v[int(_si[0])]->getNum() == unsigned(_v[i]->getNum())) { c = i; }
    }
    int indexopposedVertex = 0;
    switch(c) {
    case(0): indexopposedVertex = 3; break;
    case(1): indexopposedVertex = 2; break;
    case(2): indexopposedVertex = 1; break;
    case(3): indexopposedVertex = 0; break;
    }
    int numVertexOpposed = _v[indexopposedVertex]->getNum();

    int axis1A = _v[int(_si[0])]->getNum();
    int axis1B = 0;
    if(_v[int(_si[1])]->getNum() == unsigned(numVertexOpposed)) {
      axis1B = _v[int(_si[2])]->getNum();
    }
    else {
      axis1B = _v[int(_si[1])]->getNum();
    }
    if(unsigned(axis1A) == _v[0]->getNum()) {
      if(unsigned(axis1B) == _v[1]->getNum()) {
        faceOrientationFlag[0] = 1;
        faceOrientationFlag[1] = 1;
        faceOrientationFlag[2] = 1;
      }
      else {
        faceOrientationFlag[0] = 1;
        faceOrientationFlag[1] = 1;
        faceOrientationFlag[2] = -1;
      }
    }
    else {
      if(unsigned(axis1A) == _v[1]->getNum()) {
        if(unsigned(axis1B) == _v[0]->getNum()) {
          faceOrientationFlag[0] = -1;
          faceOrientationFlag[1] = 1;
          faceOrientationFlag[2] = 1;
        }
        else {
          faceOrientationFlag[0] = -1;
          faceOrientationFlag[1] = 1;
          faceOrientationFlag[2] = -1;
        }
      }
      else {
        if(unsigned(axis1A) == _v[2]->getNum()) {
          if(unsigned(axis1B) == _v[3]->getNum()) {
            faceOrientationFlag[0] = 1;
            faceOrientationFlag[1] = -1;
            faceOrientationFlag[2] = 1;
          }
          else {
            faceOrientationFlag[0] = 1;
            faceOrientationFlag[1] = -1;
            faceOrientationFlag[2] = -1;
          }
        }
        else {
          if(unsigned(axis1B) == _v[2]->getNum()) {
            faceOrientationFlag[0] = -1;
            faceOrientationFlag[1] = -1;
            faceOrientationFlag[2] = 1;
          }
          else {
            faceOrientationFlag[0] = -1;
            faceOrientationFlag[1] = -1;
            faceOrientationFlag[2] = -1;
          }
        }
      }
    }
  }
}
double MFace::approximateArea() const
{
  SPoint3 p0 = _v[0]->point(), p1 = _v[1]->point(), p2 = _v[2]->point();
  double a = triangle_area(p0, p1, p2);
  if(_v.size() == 3) return a;
  a += triangle_area(p0, p2, _v[3]->point());
  return a;
}

SVector3 MFace::normal() const
{
  double n[3];
  normal3points(_v[0]->x(), _v[0]->y(), _v[0]->z(), _v[1]->x(), _v[1]->y(),
                _v[1]->z(), _v[2]->x(), _v[2]->y(), _v[2]->z(), n);
  return SVector3(n[0], n[1], n[2]);
}

bool MFace::computeCorrespondence(const MFace &other, int &rotation,
                                  bool &swap) const
{
  rotation = 0;
  swap = false;

  if(*this == other) {
    for(std::size_t i = 0; i < getNumVertices(); i++) {
      if(_v[0] == other.getVertex(i)) {
        rotation = i;
        break;
      }
    }
    if(_v[1] == other.getVertex((rotation + 1) % getNumVertices()))
      swap = false;
    else
      swap = true;
    return true;
  }
  return false;
}

MFaceN::MFaceN(int type, int order, const std::vector<MVertex *> &v)
  : _type(type), _order(order)
{
  _v.resize(v.size());
  for(std::size_t i = 0; i < v.size(); i++) _v[i] = v[i];
}

MEdgeN MFaceN::getHighOrderEdge(int num, int sign) const
{
  int nCorner = getNumCorners();
  std::vector<MVertex *> vertices(static_cast<std::size_t>(_order) + 1);
  if(sign == 1) {
    vertices[0] = _v[num];
    vertices[1] = _v[(num + 1) % nCorner];
  }
  else {
    vertices[0] = _v[(num + 1) % nCorner];
    vertices[1] = _v[num];
  }
  int start = nCorner + num * (_order - 1);
  int end = nCorner + (num + 1) * (_order - 1);
  int k = 1;
  if(sign == 1) {
    for(int i = start; i < end; ++i) vertices[++k] = _v[i];
  }
  else {
    for(int i = end - 1; i >= start; --i) vertices[++k] = _v[i];
  }
  return MEdgeN(vertices);
}

MFace MFaceN::getFace() const
{
  if(_type == TYPE_TRI)
    return MFace(_v[0], _v[1], _v[2]);
  else
    return MFace(_v[0], _v[1], _v[2], _v[3]);
}

SPoint3 MFaceN::pnt(double u, double v) const
{
  int tag = ElementType::getType(_type, _order);
  const nodalBasis *fs = BasisFactory::getNodalBasis(tag);

  double f[100];
  fs->f(u, v, 0, f);

  double x = 0, y = 0, z = 0;
  for(int j = 0; j < fs->getNumShapeFunctions(); j++) {
    x += f[j] * _v[j]->x();
    y += f[j] * _v[j]->y();
    z += f[j] * _v[j]->z();
  }
  return SPoint3(x, y, z);
}

SVector3 MFaceN::tangent(double u, double v, int num) const
{
  if(num != 0 && num != 1) num = 0;

  int tag = ElementType::getType(_type, _order);
  const nodalBasis *fs = BasisFactory::getNodalBasis(tag);

  double sf[100][3];
  fs->df(u, v, 0, sf);

  double dx = 0, dy = 0, dz = 0;
  for(int j = 0; j < fs->getNumShapeFunctions(); j++) {
    dx += sf[j][num] * _v[j]->x();
    dy += sf[j][num] * _v[j]->y();
    dz += sf[j][num] * _v[j]->z();
  }
  return SVector3(dx, dy, dz).unit();
}

SVector3 MFaceN::normal(double u, double v) const
{
  int tag = ElementType::getType(_type, _order);
  const nodalBasis *fs = BasisFactory::getNodalBasis(tag);

  double sf[100][3];
  fs->df(u, v, 0, sf);

  double dx[2] = {0, 0}, dy[2] = {0, 0}, dz[2] = {0, 0};
  for(int j = 0; j < fs->getNumShapeFunctions(); j++) {
    for(int k = 0; k < 1; ++k) {
      dx[k] += sf[j][k] * _v[j]->x();
      dy[k] += sf[j][k] * _v[j]->y();
      dz[k] += sf[j][k] * _v[j]->z();
    }
  }

  SVector3 t0 = SVector3(dx[0], dy[0], dz[0]);
  SVector3 t1 = SVector3(dx[1], dy[1], dz[1]);

  return crossprod(t0, t1).unit();
}

void MFaceN::frame(double u, double v, SVector3 &t0, SVector3 &t1,
                   SVector3 &n) const
{
  int tag = ElementType::getType(_type, _order);
  const nodalBasis *fs = BasisFactory::getNodalBasis(tag);

  double sf[100][3];
  fs->df(u, v, 0, sf);

  double dx[2] = {0, 0}, dy[2] = {0, 0}, dz[2] = {0, 0};
  for(int j = 0; j < fs->getNumShapeFunctions(); j++) {
    for(int k = 0; k < 2; ++k) {
      dx[k] += sf[j][k] * _v[j]->x();
      dy[k] += sf[j][k] * _v[j]->y();
      dz[k] += sf[j][k] * _v[j]->z();
    }
  }

  t0 = SVector3(dx[0], dy[0], dz[0]).unit();
  t1 = SVector3(dx[1], dy[1], dz[1]).unit();
  n = crossprod(t0, t1);
}

void MFaceN::frame(double u, double v, SPoint3 &p, SVector3 &t0, SVector3 &t1,
                   SVector3 &n) const
{
  int tag = ElementType::getType(_type, _order);
  const nodalBasis *fs = BasisFactory::getNodalBasis(tag);

  double f[100];
  double sf[100][3];
  fs->f(u, v, 0, f);
  fs->df(u, v, 0, sf);

  double x = 0, y = 0, z = 0;
  double dx[2] = {0, 0}, dy[2] = {0, 0}, dz[2] = {0, 0};
  for(int j = 0; j < fs->getNumShapeFunctions(); j++) {
    x += f[j] * _v[j]->x();
    y += f[j] * _v[j]->y();
    z += f[j] * _v[j]->z();
    for(int k = 0; k < 2; ++k) {
      dx[k] += sf[j][k] * _v[j]->x();
      dy[k] += sf[j][k] * _v[j]->y();
      dz[k] += sf[j][k] * _v[j]->z();
    }
  }

  p = SPoint3(x, y, z);
  t0 = SVector3(dx[0], dy[0], dz[0]).unit();
  t1 = SVector3(dx[1], dy[1], dz[1]).unit();
  n = crossprod(t0, t1);
}

void MFaceN::repositionInnerVertices(const fullMatrix<double> *placement) const
{
  int nCorner = getNumCorners();
  int start = nCorner + (_order - 1) * nCorner;
  for(int i = start; i < (int)_v.size(); ++i) {
    MVertex *v = _v[i];
    v->x() = 0;
    v->y() = 0;
    v->z() = 0;
    for(int j = 0; j < placement->size2(); ++j) {
      const double coeff = (*placement)(i - start, j);
      v->x() += coeff * _v[j]->x();
      v->y() += coeff * _v[j]->y();
      v->z() += coeff * _v[j]->z();
    }
  }
}
