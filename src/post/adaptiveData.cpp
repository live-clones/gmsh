// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <math.h>
#include <map>
#include <array>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include "adaptiveData.h"
#include "MElement.h"
#include "MPolygon.h"
#include "MPolyhedron.h"
#include "Plugin.h"
#include "OS.h"
#include "GmshDefines.h"
#include "ElementType.h"

std::vector<vectInt> globalVTKData::vtkGlobalConnectivity;
std::vector<int> globalVTKData::vtkGlobalCellType;
std::vector<PCoords> globalVTKData::vtkGlobalCoords;
std::vector<PValues> globalVTKData::vtkGlobalValues;

static void computeShapeFunctions(fullMatrix<double> *coeffs,
                                  fullMatrix<double> *eexps, double u, double v,
                                  double w, fullVector<double> *sf,
                                  fullVector<double> *tmp)
{
  for(int i = 0; i < eexps->size1(); i++) {
    (*tmp)(i) = pow(u, (*eexps)(i, 0));
    if(eexps->size2() > 1) (*tmp)(i) *= pow(v, (*eexps)(i, 1));
    if(eexps->size2() > 2) (*tmp)(i) *= pow(w, (*eexps)(i, 2));
  }
  coeffs->mult(*tmp, *sf);
}

/*! Bergot space is characterised by polynomials
  \f$ \mathcal B_{ijk} =
  \mathcal P_i \left(\frac{\xi }{1-\zeta}\right)
  \mathcal P_j \left(\frac{\eta}{1-\zeta}\right)
  \left(1-\zeta\right)^{max(i,j)}
  \mathcal P^{2 max(i,j),0}_k \left(2 \zeta -1\right)~|~i,j \leq p, k \leq p -
  max(i,j) \f$ and hence by the "monomials" \f$ \mu_{ijk} = \left(\frac{\xi
  }{1-\zeta}\right)^i \left(\frac{\eta}{1-\zeta}\right)^j
  \left(1-\zeta\right)^{max(i,j)} \zeta^k~|~i,j \leq p~,~k \leq p-max(i,j)
  \f$
*/
static void computeShapeFunctionsPyramid(fullMatrix<double> *coeffs,
                                         fullMatrix<double> *eexps, double u,
                                         double v, double w,
                                         fullVector<double> *sf,
                                         fullVector<double> *tmp)
{
  double oneMinW = (w == 1) ? 1e-12 : 1 - w;
  for(int l = 0; l < eexps->size1(); l++) {
    int i = (*eexps)(l, 0);
    int j = (*eexps)(l, 1);
    int k = (*eexps)(l, 2);
    int m = std::max(i, j);
    (*tmp)(l) = pow(u, i);
    (*tmp)(l) *= pow(v, j);
    (*tmp)(l) *= pow(w, k);
    (*tmp)(l) *= pow(oneMinW, m - i - j);
  }
  coeffs->mult(*tmp, *sf);
}

// The reference elements and their subdivision

static void pointSF(double u, double v, double w, fullVector<double> &sf)
{
  sf(0) = 1;
}

static void lineSF(double u, double v, double w, fullVector<double> &sf)
{
  sf(0) = (1 - u) / 2.;
  sf(1) = (1 + u) / 2.;
}

static void triangleSF(double u, double v, double w, fullVector<double> &sf)
{
  sf(0) = 1. - u - v;
  sf(1) = u;
  sf(2) = v;
}

static void quadrangleSF(double u, double v, double w, fullVector<double> &sf)
{
  sf(0) = 0.25 * (1. - u) * (1. - v);
  sf(1) = 0.25 * (1. + u) * (1. - v);
  sf(2) = 0.25 * (1. + u) * (1. + v);
  sf(3) = 0.25 * (1. - u) * (1. + v);
}

static void tetrahedronSF(double u, double v, double w, fullVector<double> &sf)
{
  sf(0) = 1. - u - v - w;
  sf(1) = u;
  sf(2) = v;
  sf(3) = w;
}

static void hexahedronSF(double u, double v, double w, fullVector<double> &sf)
{
  sf(0) = 0.125 * (1 - u) * (1 - v) * (1 - w);
  sf(1) = 0.125 * (1 + u) * (1 - v) * (1 - w);
  sf(2) = 0.125 * (1 + u) * (1 + v) * (1 - w);
  sf(3) = 0.125 * (1 - u) * (1 + v) * (1 - w);
  sf(4) = 0.125 * (1 - u) * (1 - v) * (1 + w);
  sf(5) = 0.125 * (1 + u) * (1 - v) * (1 + w);
  sf(6) = 0.125 * (1 + u) * (1 + v) * (1 + w);
  sf(7) = 0.125 * (1 - u) * (1 + v) * (1 + w);
}

static void prismSF(double u, double v, double w, fullVector<double> &sf)
{
  sf(0) = (1. - u - v) * (1 - w) / 2;
  sf(1) = u * (1 - w) / 2;
  sf(2) = v * (1 - w) / 2;
  sf(3) = (1. - u - v) * (1 + w) / 2;
  sf(4) = u * (1 + w) / 2;
  sf(5) = v * (1 + w) / 2;
}

static void pyramidSF(double u, double v, double w, fullVector<double> &sf)
{
  double ww = 0.25 / std::max(1e-14, 1. - w);
  sf(0) = (1 - u - w) * (1 - v - w) * ww;
  sf(1) = (1 + u - w) * (1 - v - w) * ww;
  sf(2) = (1 + u - w) * (1 + v - w) * ww;
  sf(3) = (1 - u - w) * (1 + v - w) * ww;
  sf(4) = w;
}

static adaptiveShape makeShape(int type)
{
  typedef std::vector<std::vector<int> > table;
  adaptiveShape s;
  s.type = type;
  s.diagonal[0] = s.diagonal[1] = -1;
  s.pyramid = false;
  std::vector<std::vector<double> > nodes;
  // the points of a subdivision other than the nodes (added after them)
  table more;

  switch(type) {
  case TYPE_PNT:
    s.numEdges = 0;
    nodes = {{0, 0, 0}};
    s.shapeFunctions = pointSF;
    break;
  case TYPE_LIN:
    // 0    2    1
    s.numEdges = 1;
    nodes = {{-1, 0, 0}, {1, 0, 0}};
    more = {{0, 1}};
    s.children = {{0, 2}, {2, 1}};
    s.weights = {1, 1};
    s.shapeFunctions = lineSF;
    break;
  case TYPE_TRI:
    // 2
    // 4    5
    // 0    3    1
    s.numEdges = 3;
    nodes = {{0, 0, 0}, {1, 0, 0}, {0, 1, 0}};
    more = {{0, 1}, {0, 2}, {1, 2}};
    s.children = {{0, 3, 4}, {1, 5, 3}, {2, 4, 5}, {3, 5, 4}};
    s.weights = {2, 2, 2, 1};
    s.shapeFunctions = triangleSF;
    break;
  case TYPE_QUA:
    // 3    6    2
    // 7    8    5
    // 0    4    1
    s.numEdges = 4;
    nodes = {{-1, -1, 0}, {1, -1, 0}, {1, 1, 0}, {-1, 1, 0}};
    more = {{0, 1}, {1, 2}, {2, 3}, {0, 3}, {0, 1, 2, 3}};
    s.children = {{0, 4, 8, 7}, {1, 5, 8, 4}, {2, 6, 8, 5}, {3, 7, 8, 6}};
    s.weights = {1, 1, 1, 1};
    s.diagonal[0] = 0;
    s.diagonal[1] = 2;
    s.shapeFunctions = quadrangleSF;
    break;
  case TYPE_TET:
    // four at the corners, four from the octahedron left in the middle
    s.numEdges = 6;
    nodes = {{0, 0, 0}, {1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    more = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}};
    s.children = {{0, 4, 5, 6}, {5, 7, 2, 9}, {4, 1, 7, 8}, {6, 8, 9, 3},
                  {7, 6, 8, 9}, {7, 5, 6, 9}, {6, 7, 8, 4}, {5, 7, 6, 4}};
    s.weights = {1, 1, 1, 1, 1, 1, 1, 1};
    s.faces = {{0, 2, 1}, {0, 1, 3}, {0, 3, 2}, {3, 1, 2}};
    s.shapeFunctions = tetrahedronSF;
    break;
  case TYPE_HEX:
    s.numEdges = 12;
    nodes = {{-1, -1, -1}, {1, -1, -1}, {1, 1, -1}, {-1, 1, -1},
             {-1, -1, 1},  {1, -1, 1},  {1, 1, 1},  {-1, 1, 1}};
    more = {{0, 1}, {1, 2}, {2, 3}, {0, 3}, {4, 5}, {5, 6}, {6, 7}, {4, 7}, // 8
            {0, 4}, {1, 5}, {2, 6}, {3, 7}, // 16: the vertical edges
            {0, 1, 4, 5}, {1, 2, 5, 6}, {2, 3, 6, 7}, {0, 3, 4, 7}, // 20
            {4, 5, 6, 7}, {0, 1, 2, 3}, // 24: top and bottom
            {0, 1, 2, 3, 4, 5, 6, 7}}; // 26: the centre
    s.children = {{0, 8, 25, 11, 16, 20, 26, 23},  {11, 3, 19, 23, 25, 10, 22, 26},
                  {16, 23, 15, 4, 20, 26, 24, 12}, {23, 19, 7, 15, 26, 22, 14, 24},
                  {20, 26, 24, 12, 17, 21, 13, 5}, {26, 22, 14, 24, 21, 18, 6, 13},
                  {8, 25, 26, 20, 1, 9, 21, 17},   {25, 10, 22, 26, 9, 2, 18, 21}};
    s.weights = {1, 1, 1, 1, 1, 1, 1, 1};
    s.diagonal[0] = 3;
    s.diagonal[1] = 5;
    s.faces = {{0, 3, 2, 1}, {0, 1, 5, 4}, {0, 4, 7, 3},
               {1, 2, 6, 5}, {2, 3, 7, 6}, {4, 5, 6, 7}};
    s.shapeFunctions = hexahedronSF;
    break;
  case TYPE_PRI:
    // the triangles are cut in four, below and above the middle; the
    // children on the inner triangles weigh half of the others, as in the
    // triangle
    s.numEdges = 9;
    nodes = {{0, 0, -1}, {1, 0, -1}, {0, 1, -1}, {0, 0, 1}, {1, 0, 1}, {0, 1, 1}};
    more = {{0, 3}, {1, 4}, {2, 5}, // 6: the vertical edges
            {0, 1}, {1, 2}, {2, 0}, // 9: the bottom
            {0, 1, 3, 4}, {1, 2, 4, 5}, {2, 0, 5, 3}, // 12: the middle
            {3, 4}, {4, 5}, {5, 3}}; // 15: the top
    s.children = {{0, 9, 11, 6, 12, 14},   {1, 10, 9, 7, 13, 12},
                  {2, 11, 10, 8, 14, 13},  {9, 10, 11, 12, 13, 14},
                  {6, 12, 14, 3, 15, 17},  {7, 13, 12, 4, 16, 15},
                  {8, 14, 13, 5, 17, 16},  {12, 13, 14, 15, 16, 17}};
    s.weights = {1, 1, 1, 0.5, 1, 1, 1, 0.5};
    s.sumOfWeights = 7;
    s.faces = {{0, 1, 4, 3}, {0, 3, 5, 2}, {1, 2, 5, 4}, {0, 2, 1}, {3, 4, 5}};
    s.shapeFunctions = prismSF;
    break;
  case TYPE_PYR:
    // Four pyramids on the base, one at the top, one upside down under it,
    // and four tetrahedra in the holes that are left: these are pyramids with
    // two nodes at the same place (the first and the fourth), and half the
    // volume of the others.
    s.numEdges = 8;
    nodes = {{-1, -1, 0}, {1, -1, 0}, {1, 1, 0}, {-1, 1, 0}, {0, 0, 1}};
    more = {{0, 1, 2, 3}, // 5: the centre of the base
            {0, 1}, {1, 2}, {2, 3}, {3, 0}, // 6: the base
            {0, 4}, {1, 4}, {2, 4}, {3, 4}}; // 10: the edges to the apex
    s.children = {{0, 6, 5, 9, 10},    {1, 7, 5, 6, 11},   {2, 8, 5, 7, 12},
                  {3, 9, 5, 8, 13},    {10, 11, 12, 13, 4}, {10, 13, 12, 11, 5},
                  {5, 11, 10, 5, 6},   {5, 12, 11, 5, 7},  {5, 13, 12, 5, 8},
                  {5, 10, 13, 5, 9}};
    s.weights = {1, 1, 1, 1, 1, 1, 0.5, 0.5, 0.5, 0.5};
    s.sumOfWeights = 8;
    s.faces = {{0, 3, 2, 1}, {0, 1, 4}, {3, 0, 4}, {1, 2, 4}, {2, 3, 4}};
    s.shapeFunctions = pyramidSF;
    s.pyramid = true;
    break;
  default: Msg::Error("No adaptive shape for element type %d", type); break;
  }

  s.numNodes = (int)nodes.size();
  s.numChildren = (int)s.children.size();
  for(int i = 0; i < s.numNodes; i++) {
    for(int k = 0; k < 3; k++) s.nodes[i][k] = nodes[i][k];
    s.points.push_back({i});
  }
  s.points.insert(s.points.end(), more.begin(), more.end());
  if(type != TYPE_PRI && type != TYPE_PYR) {
    s.sumOfWeights = 0;
    for(auto w : s.weights) s.sumOfWeights += w;
  }
  return s;
}

const adaptiveShape &adaptiveShape::get(int type)
{
  static std::map<int, adaptiveShape> shapes;
  auto it = shapes.find(type);
  if(it == shapes.end()) it = shapes.insert({type, makeShape(type)}).first;
  return it->second;
}


adaptiveElements::adaptiveElements(
  int type, const std::vector<fullMatrix<double> *> &p)
  : _shape(adaptiveShape::get(type)), _coeffsVal(nullptr), _eexpsVal(nullptr),
    _interpolVal(nullptr), _coeffsGeom(nullptr), _eexpsGeom(nullptr),
    _interpolGeom(nullptr)
{
  if(p.size() >= 2) {
    _coeffsVal = p[0];
    _eexpsVal = p[1];
  }
  if(p.size() == 4) {
    _coeffsGeom = p[2];
    _eexpsGeom = p[3];
  }
}

adaptiveElements::~adaptiveElements()
{
  if(_interpolVal) delete _interpolVal;
  if(_interpolGeom) delete _interpolGeom;
}

// the vertex at this place of the reference element, new if need be (the
// elements of a set do not move)
adaptiveVertex *adaptiveElements::_vertex(double x, double y, double z)
{
  adaptiveVertex p;
  p.x = x;
  p.y = y;
  p.z = z;
  // it is on a face of the reference element if the first order shape
  // functions of the nodes that are not on that face vanish
  p.onFaces = 0;
  fullVector<double> sf(_shape.numNodes);
  _shape.shapeFunctions(x, y, z, sf);
  for(std::size_t f = 0; f < _shape.faces.size(); f++) {
    double off = 0.;
    for(int i = 0; i < _shape.numNodes; i++)
      if(std::find(_shape.faces[f].begin(), _shape.faces[f].end(), i) ==
         _shape.faces[f].end())
        off += fabs(sf(i));
    if(off < 1e-10) p.onFaces |= (unsigned char)(1 << f);
  }
  return (adaptiveVertex *)&(*allVertices.insert(p).first);
}

adaptiveElement *
adaptiveElements::_create(const std::vector<adaptiveVertex *> &nodes,
                          int maxLevel, int level)
{
  all.push_back(adaptiveElement());
  adaptiveElement *e = &all.back();
  e->shape = &_shape;
  e->visible = false;
  for(int i = 0; i < 8; i++) e->p[i] = (i < _shape.numNodes) ? nodes[i] : nullptr;
  for(int i = 0; i < 10; i++) e->e[i] = nullptr;
  for(std::size_t f = 0; f < 6; f++) {
    // a face lies on a face of the reference element if all its nodes do
    unsigned char on = (f < _shape.faces.size()) ? 0xff : 0;
    for(std::size_t k = 0; f < _shape.faces.size() && k < _shape.faces[f].size(); k++)
      on &= nodes[_shape.faces[f][k]]->onFaces;
    e->onFace[f] = -1;
    for(int b = 0; b < 6 && e->onFace[f] < 0; b++)
      if(on & (1 << b)) e->onFace[f] = b;
  }
  if(level >= maxLevel) return e;

  // the points of the subdivision, then the children on them
  std::vector<adaptiveVertex *> points;
  for(auto &of : _shape.points) {
    double x = 0., y = 0., z = 0.;
    for(int i : of) {
      x += nodes[i]->x;
      y += nodes[i]->y;
      z += nodes[i]->z;
    }
    points.push_back(_vertex(x / of.size(), y / of.size(), z / of.size()));
  }
  for(int i = 0; i < _shape.numChildren; i++) {
    std::vector<adaptiveVertex *> child;
    for(int k : _shape.children[i]) child.push_back(points[k]);
    e->e[i] = _create(child, maxLevel, level + 1);
  }
  return e;
}

void adaptiveElements::init(int level)
{
  // the tree has numChildren^level leaves, and the interpolation matrices a
  // row for each of its vertices
  const double maxLeaves = 262144.; // 8^6: level 6 for the volumes
  int maxLevel = 0;
  while(_shape.numChildren > 1 &&
        pow(_shape.numChildren, maxLevel + 1) <= maxLeaves)
    maxLevel++;
  if(level > maxLevel && _shape.numChildren) {
    Msg::Warning("Adaptive views: recursion level %d is too much for %s, "
                 "using %d", level,
                 ElementType::nameOfParentType(_shape.type, true).c_str(),
                 maxLevel);
    level = maxLevel;
  }

  all.clear();
  allVertices.clear();
  std::vector<adaptiveVertex *> nodes;
  for(int i = 0; i < _shape.numNodes; i++)
    nodes.push_back(
      _vertex(_shape.nodes[i][0], _shape.nodes[i][1], _shape.nodes[i][2]));
  _create(nodes, level, 0);
  int index = 0;
  for(auto &v : allVertices) ((adaptiveVertex *)&v)->index = index++;

  int numVals = _coeffsVal ? _coeffsVal->size1() : _shape.numNodes;
  int numNodes = _coeffsGeom ? _coeffsGeom->size1() : _shape.numNodes;

  if(_interpolVal) delete _interpolVal;
  _interpolVal = new fullMatrix<double>(allVertices.size(), numVals);

  if(_interpolGeom) delete _interpolGeom;
  _interpolGeom = new fullMatrix<double>(allVertices.size(), numNodes);

  fullVector<double> sfv(numVals), sfg(numNodes);
  auto evaluate = [&](fullMatrix<double> *coeffs, fullMatrix<double> *eexps,
                      const adaptiveVertex &v, fullVector<double> &sf) {
    if(!coeffs || !eexps)
      _shape.shapeFunctions(v.x, v.y, v.z, sf);
    else {
      fullVector<double> tmp(eexps->size1());
      if(_shape.pyramid)
        computeShapeFunctionsPyramid(coeffs, eexps, v.x, v.y, v.z, &sf, &tmp);
      else
        computeShapeFunctions(coeffs, eexps, v.x, v.y, v.z, &sf, &tmp);
    }
  };
  for(auto &v : allVertices) {
    evaluate(_coeffsVal, _eexpsVal, v, sfv);
    for(int j = 0; j < numVals; j++) (*_interpolVal)(v.index, j) = sfv(j);
    evaluate(_coeffsGeom, _eexpsGeom, v, sfg);
    for(int j = 0; j < numNodes; j++) (*_interpolGeom)(v.index, j) = sfg(j);
  }
}

// An element is kept if the mean of the field over it would not change by
// more than the threshold if it were subdivided once more, nor the means
// over its children if they were
void adaptiveElements::_error(adaptiveElement *e, double threshold)
{
  e->visible = true;
  if(!e->e[0]) return;

  bool grandChildren = (e->e[0]->e[0] != nullptr);
  double mean = e->meanOfChildren();

  bool refine = fabs(e->V() - mean) > threshold;
  if(!refine && _shape.diagonal[0] >= 0) {
    double onDiagonal =
      (e->p[_shape.diagonal[0]]->norm + e->p[_shape.diagonal[1]]->norm) / 2.;
    refine = fabs(onDiagonal - mean) > threshold;
  }
  for(int i = 0; i < _shape.numChildren && grandChildren && !refine; i++)
    refine = fabs(e->e[i]->V() - e->e[i]->meanOfChildren()) > threshold;

  if(refine) {
    e->visible = false;
    for(int i = 0; i < _shape.numChildren; i++) _error(e->e[i], threshold);
  }
}

bool adaptiveElements::adapt(double tol, int numComp,
                             std::vector<PCoords> &coords,
                             std::vector<PValues> &values, double range,
                             GMSH_PostPlugin *plug,
                             std::vector<unsigned char> *skin)
{
  int numVertices = allVertices.size();

  if(!numVertices) {
    Msg::Warning("No adapted vertices to interpolate");
    return false;
  }

  int numVals = _coeffsVal ? _coeffsVal->size1() : _shape.numNodes;

  if(numVals != (int)values.size()) {
    Msg::Warning("Wrong number of values in adaptation %d != %d", numVals,
                 (int)values.size());
    return false;
  }

  if(numComp != 1 && numComp != 3 && numComp != 9) {
    Msg::Error("Can only adapt scalar, vector or tensor data");
    return false;
  }

  // the field at all the vertices of the tree
  fullVector<double> val(numVals), res(numVertices);
  if(numComp == 1) {
    for(int i = 0; i < numVals; i++) val(i) = values[i].v[0];
    _interpolVal->mult(val, res);
  }

  fullMatrix<double> *resxyz = nullptr;
  if(numComp == 3 || numComp == 9) {
    fullMatrix<double> valxyz(numVals, numComp);
    resxyz = new fullMatrix<double>(numVertices, numComp);
    for(int i = 0; i < numVals; i++) {
      for(int k = 0; k < numComp; k++) { valxyz(i, k) = values[i].v[k]; }
    }
    _interpolVal->mult(valxyz, *resxyz);
  }

  int numNodes = _coeffsGeom ? _coeffsGeom->size1() : _shape.numNodes;
  if(numNodes != (int)coords.size()) {
    Msg::Error("Wrong number of nodes in adaptation %d != %d", numNodes,
               (int)coords.size());
    if(resxyz) delete resxyz;
    return false;
  }

  fullMatrix<double> xyz(numNodes, 3), XYZ(numVertices, 3);
  for(int i = 0; i < numNodes; i++) {
    xyz(i, 0) = coords[i].c[0];
    xyz(i, 1) = coords[i].c[1];
    xyz(i, 2) = coords[i].c[2];
  }
  _interpolGeom->mult(xyz, XYZ);

  for(auto &v : allVertices) {
    // ok because we know this will not change the set ordering
    adaptiveVertex *p = (adaptiveVertex *)&v;
    int i = p->index;
    p->val = p->norm = res(i);
    if(resxyz) {
      // the error is estimated on the norm of what is interpolated
      p->norm = 0.;
      for(int k = 0; k < numComp; k++)
        p->norm += (*resxyz)(i, k) * (*resxyz)(i, k);
      p->norm = sqrt(p->norm);
      p->val = (*resxyz)(i, 0);
      p->valy = (*resxyz)(i, 1);
      p->valz = (*resxyz)(i, 2);
      if(numComp == 9) {
        p->valyx = (*resxyz)(i, 3);
        p->valyy = (*resxyz)(i, 4);
        p->valyz = (*resxyz)(i, 5);
        p->valzx = (*resxyz)(i, 6);
        p->valzy = (*resxyz)(i, 7);
        p->valzz = (*resxyz)(i, 8);
      }
    }
    p->X = XYZ(i, 0);
    p->Y = XYZ(i, 1);
    p->Z = XYZ(i, 2);
  }

  if(resxyz) delete resxyz;

  for(auto &e : all) e.visible = false;

  if(!plug || tol != 0.) {
    // The target error is relative to the range of the view. A negative one,
    // or a view that is constant, keeps the smallest subdivision.
    double threshold = (tol < 0. || range <= 0.) ? -1. : tol * range;
    _error(&all.front(), threshold);
  }

  if(plug) plug->assignSpecificVisibility(&all.front());

  // a face of a refined element is on the skin if it lies on a face of the
  // element that is
  unsigned char onSkin = (skin && skin->size()) ? (*skin)[0] : 0;
  if(skin) skin->clear();

  coords.clear();
  values.clear();
  for(auto &e : all) {
    if(!e.visible) continue;
    if(skin) {
      unsigned char mask = 0;
      for(int f = 0; f < 6; f++)
        if(e.onFace[f] >= 0 && (onSkin & (1 << e.onFace[f])))
          mask |= (unsigned char)(1 << f);
      skin->push_back(mask);
    }
    adaptiveVertex *const *p = e.p;
    for(int i = 0; i < _shape.numNodes; i++) {
      coords.push_back(PCoords(p[i]->X, p[i]->Y, p[i]->Z));
      switch(numComp) {
      case 1: values.push_back(PValues(p[i]->val)); break;
      case 3:
        values.push_back(PValues(p[i]->val, p[i]->valy, p[i]->valz));
        break;
      case 9:
        values.push_back(PValues(p[i]->val, p[i]->valy, p[i]->valz,
                                 p[i]->valyx, p[i]->valyy, p[i]->valyz,
                                 p[i]->valzx, p[i]->valzy, p[i]->valzz));
        break;
      }
    }
  }

  return true;
}


bool adaptPolytope(int level, int numComp, MElement *e, int &numNodes,
                   std::vector<PCoords> &coords, std::vector<PValues> &values)
{
  int type = e->getType();

  std::vector<size_t> simplices;
  if(type == TYPE_POLYG) {
    MPolygon *polygon = static_cast<MPolygon *>(e);
    int numSimplices = polygon->getNumTriangles();
    for(int i = 0; i < numSimplices; ++i) {
      std::array<int, 3> is = polygon->getTriangleIndices(i);
      for(auto ii : is) simplices.push_back(ii);
    }
  }
  if(type == TYPE_POLYH) {
    MPolyhedron *polyhedron = static_cast<MPolyhedron *>(e);
    int numSimplices = polyhedron->getNumTetrahedra();
    for(int i = 0; i < numSimplices; ++i) {
      std::array<int, 4> is = polyhedron->getTetrahedronIndices(i);
      for(auto ii : is) simplices.push_back(ii);
    }
  }

  // Refinement
  auto hasher = [](const std::pair<std::size_t, std::size_t> p) -> size_t {
    uint64_t packed = ((uint64_t)p.first << 32) | (p.second & 0xFFFFFFFF);
    return std::hash<uint64_t>{}(packed);
  };
  for(int i = 0; i < level; ++i) {
    // create sub simplices
    if(type == TYPE_POLYG) {
      std::vector<size_t> newSimplices(4 * simplices.size());
      std::unordered_map<std::pair<std::size_t, std::size_t>, size_t,
                         decltype(hasher)>
        mids(0, hasher);
      for(std::size_t j = 0; j < simplices.size(); j += 3) {
        // create middles
        size_t *is = &simplices[j];
        size_t mid[3];
        for(int k = 0; k < 3; ++k) {
          size_t i0 = is[k], i1 = is[(k + 1) % 3];
          std::pair<size_t, size_t> edge = {std::min(i0, i1), std::max(i0, i1)};
          auto it = mids.find(edge);
          if(it == mids.end()) {
            it = mids.insert({edge, coords.size()}).first;
            double x = .5 * (coords[i0].c[0] + coords[i1].c[0]);
            double y = .5 * (coords[i0].c[1] + coords[i1].c[1]);
            double z = .5 * (coords[i0].c[2] + coords[i1].c[2]);
            coords.push_back(PCoords(x, y, z));
            values.push_back(PValues(numComp));
            for(int c = 0; c < numComp; c++)
              values.back().v[c] = .5 * (values[i0].v[c] + values[i1].v[c]);
          }
          mid[k] = it->second;
        }
        // create new simplices
        for(int k = 0; k < 3; ++k) {
          newSimplices[4 * j + 3 * k] = is[k];
          newSimplices[4 * j + 3 * k + 1] = mid[k];
          newSimplices[4 * j + 3 * k + 2] = mid[(k + 2) % 3];
        }
        newSimplices[4 * j + 9] = mid[0];
        newSimplices[4 * j + 10] = mid[1];
        newSimplices[4 * j + 11] = mid[2];
      }
      simplices = std::move(newSimplices);
    }
    else if(type == TYPE_POLYH) {
      std::vector<size_t> newSimplices(8 * simplices.size());
      std::unordered_map<std::pair<std::size_t, std::size_t>, size_t,
                         decltype(hasher)>
        mids(0, hasher);
      for(std::size_t j = 0; j < simplices.size(); j += 4) {
        // create middles
        size_t *is = &simplices[j];
        size_t mid[6];
        int count = 0;
        for(int k = 0; k < 4; ++k) {
          for(int l = k + 1; l < 4; ++l) {
            size_t i0 = is[k], i1 = is[l];
            std::pair<size_t, size_t> edge = {std::min(i0, i1),
                                              std::max(i0, i1)};
            auto it = mids.find(edge);
            if(it == mids.end()) {
              it = mids.insert({edge, coords.size()}).first;
              double x = .5 * (coords[i0].c[0] + coords[i1].c[0]);
              double y = .5 * (coords[i0].c[1] + coords[i1].c[1]);
              double z = .5 * (coords[i0].c[2] + coords[i1].c[2]);
              coords.push_back(PCoords(x, y, z));
              values.push_back(PValues(numComp));
              for(int c = 0; c < numComp; c++)
                values.back().v[c] = .5 * (values[i0].v[c] + values[i1].v[c]);
            }
            mid[count++] = it->second;
          }
        }
        // create new simplices
        newSimplices[8 * j + 0] = is[0];
        newSimplices[8 * j + 1] = mid[0];
        newSimplices[8 * j + 2] = mid[1];
        newSimplices[8 * j + 3] = mid[2];
        newSimplices[8 * j + 4] = is[1];
        newSimplices[8 * j + 5] = mid[0];
        newSimplices[8 * j + 6] = mid[3];
        newSimplices[8 * j + 7] = mid[4];
        newSimplices[8 * j + 8] = is[2];
        newSimplices[8 * j + 9] = mid[1];
        newSimplices[8 * j + 10] = mid[3];
        newSimplices[8 * j + 11] = mid[5];
        newSimplices[8 * j + 12] = is[3];
        newSimplices[8 * j + 13] = mid[2];
        newSimplices[8 * j + 14] = mid[4];
        newSimplices[8 * j + 15] = mid[5];
        newSimplices[8 * j + 16] = mid[0];
        newSimplices[8 * j + 17] = mid[1];
        newSimplices[8 * j + 18] = mid[2];
        newSimplices[8 * j + 19] = mid[3];
        newSimplices[8 * j + 20] = mid[0];
        newSimplices[8 * j + 21] = mid[2];
        newSimplices[8 * j + 22] = mid[3];
        newSimplices[8 * j + 23] = mid[4];
        newSimplices[8 * j + 24] = mid[1];
        newSimplices[8 * j + 25] = mid[2];
        newSimplices[8 * j + 26] = mid[3];
        newSimplices[8 * j + 27] = mid[5];
        newSimplices[8 * j + 28] = mid[2];
        newSimplices[8 * j + 29] = mid[3];
        newSimplices[8 * j + 30] = mid[4];
        newSimplices[8 * j + 31] = mid[5];
      }
      simplices = std::move(newSimplices);
    }
  }

  std::vector<PCoords> newCoords(simplices.size(), PCoords(0, 0, 0));
  std::vector<PValues> newValues(simplices.size(), PValues(numComp));
  for(std::size_t j = 0; j < simplices.size(); ++j) {
    newCoords[j] = coords[simplices[j]];
    newValues[j] = values[simplices[j]];
  }
  coords = std::move(newCoords);
  values = std::move(newValues);
  if(type == TYPE_POLYG) numNodes = 3;
  if(type == TYPE_POLYH) numNodes = 4;
  return true;
}

// the list of a list-based view that holds the elements of a type
static void getList(PViewDataList *out, int type, int numComp, int *&nb,
                    std::vector<double> *&list)
{
  int k = (numComp == 1) ? 0 : (numComp == 3) ? 1 : 2;
  switch(type) {
  case TYPE_PNT: {
    int *n[3] = {&out->NbSP, &out->NbVP, &out->NbTP};
    std::vector<double> *l[3] = {&out->SP, &out->VP, &out->TP};
    nb = n[k]; list = l[k];
  } break;
  case TYPE_LIN: {
    int *n[3] = {&out->NbSL, &out->NbVL, &out->NbTL};
    std::vector<double> *l[3] = {&out->SL, &out->VL, &out->TL};
    nb = n[k]; list = l[k];
  } break;
  case TYPE_TRI: {
    int *n[3] = {&out->NbST, &out->NbVT, &out->NbTT};
    std::vector<double> *l[3] = {&out->ST, &out->VT, &out->TT};
    nb = n[k]; list = l[k];
  } break;
  case TYPE_QUA: {
    int *n[3] = {&out->NbSQ, &out->NbVQ, &out->NbTQ};
    std::vector<double> *l[3] = {&out->SQ, &out->VQ, &out->TQ};
    nb = n[k]; list = l[k];
  } break;
  case TYPE_TET: {
    int *n[3] = {&out->NbSS, &out->NbVS, &out->NbTS};
    std::vector<double> *l[3] = {&out->SS, &out->VS, &out->TS};
    nb = n[k]; list = l[k];
  } break;
  case TYPE_HEX: {
    int *n[3] = {&out->NbSH, &out->NbVH, &out->NbTH};
    std::vector<double> *l[3] = {&out->SH, &out->VH, &out->TH};
    nb = n[k]; list = l[k];
  } break;
  case TYPE_PRI: {
    int *n[3] = {&out->NbSI, &out->NbVI, &out->NbTI};
    std::vector<double> *l[3] = {&out->SI, &out->VI, &out->TI};
    nb = n[k]; list = l[k];
  } break;
  case TYPE_PYR: {
    int *n[3] = {&out->NbSY, &out->NbVY, &out->NbTY};
    std::vector<double> *l[3] = {&out->SY, &out->VY, &out->TY};
    nb = n[k]; list = l[k];
  } break;
  default: nb = nullptr; list = nullptr; break;
  }
}

void adaptiveElements::addInView(double tol, int step, PViewData *in,
                                 PViewDataList *out, GMSH_PostPlugin *plug,
                                 int level, int type,
                                 const std::vector<std::vector<unsigned char> > *inSkin,
                                 std::vector<unsigned char> *outSkin)
{
  int numComp = in->getNumComponents(0, 0, 0);
  if(numComp != 1 && numComp != 3 && numComp != 9) return;

  // polygons and polyhedra come after the triangles and the tetrahedra, in
  // the same list
  if(!type) type = _shape.type;
  int numEle = 0, *outNb = nullptr;
  std::vector<double> *outList = nullptr;
  bool clear = true;
  switch(type) {
  case TYPE_PNT: numEle = in->getNumPoints(); break;
  case TYPE_LIN: numEle = in->getNumLines(); break;
  case TYPE_TRI: numEle = in->getNumTriangles(); break;
  case TYPE_QUA: numEle = in->getNumQuadrangles(); break;
  case TYPE_TET: numEle = in->getNumTetrahedra(); break;
  case TYPE_HEX: numEle = in->getNumHexahedra(); break;
  case TYPE_PRI: numEle = in->getNumPrisms(); break;
  case TYPE_PYR: numEle = in->getNumPyramids(); break;
  case TYPE_POLYG:
    numEle = in->getNumPolygons();
    if(in->getNumTriangles()) clear = false;
    break;
  case TYPE_POLYH:
    numEle = in->getNumPolyhedra();
    if(in->getNumTetrahedra()) clear = false;
    break;
  }
  getList(out, _shape.type, numComp, outNb, outList);
  if(!numEle || !outList) return;

  if(clear) {
    outList->clear();
    *outNb = 0;
  }

  double range = in->getMax(step) - in->getMin(step);

  for(int ent = 0; ent < in->getNumEntities(step); ent++) {
    for(int ele = 0; ele < in->getNumElements(step, ent); ele++) {
      if(in->skipElement(step, ent, ele) || in->getType(step, ent, ele) != type)
        continue;
      int numNodes = in->getNumNodes(step, ent, ele);
      std::vector<PCoords> coords;
      for(int i = 0; i < numNodes; i++) {
        double x, y, z;
        in->getNode(step, ent, ele, i, x, y, z);
        coords.push_back(PCoords(x, y, z));
      }
      int numVal = in->getNumValues(step, ent, ele);
      std::vector<PValues> values;

      switch(numComp) {
      case 1:
        for(int i = 0; i < numVal; i++) {
          double val;
          in->getValue(step, ent, ele, i, val);
          values.push_back(PValues(val));
        }
        break;
      case 3: {
        for(int i = 0; i < numVal / 3; i++) {
          double vx, vy, vz;
          in->getValue(step, ent, ele, 3 * i + 0, vx);
          in->getValue(step, ent, ele, 3 * i + 1, vy);
          in->getValue(step, ent, ele, 3 * i + 2, vz);
          values.push_back(PValues(vx, vy, vz));
        }
        break;
      }
      case 9: {
        for(int i = 0; i < numVal / 9; i++) {
          double vxx, vxy, vxz, vyx, vyy, vyz, vzx, vzy, vzz;
          in->getValue(step, ent, ele, 9 * i + 0, vxx);
          in->getValue(step, ent, ele, 9 * i + 1, vxy);
          in->getValue(step, ent, ele, 9 * i + 2, vxz);
          in->getValue(step, ent, ele, 9 * i + 3, vyx);
          in->getValue(step, ent, ele, 9 * i + 4, vyy);
          in->getValue(step, ent, ele, 9 * i + 5, vyz);
          in->getValue(step, ent, ele, 9 * i + 6, vzx);
          in->getValue(step, ent, ele, 9 * i + 7, vzy);
          in->getValue(step, ent, ele, 9 * i + 8, vzz);
          values.push_back(
            PValues(vxx, vxy, vxz, vyx, vyy, vyz, vzx, vzy, vzz));
        }
        break;
      }
      }

      bool result = false;
      if(type == TYPE_POLYG || type == TYPE_POLYH) {
        result = adaptPolytope(level, numComp, in->getElement(step, ent, ele),
                               numNodes, coords, values);
      }
      else {
        std::vector<unsigned char> skin;
        if(inSkin && outSkin) skin.push_back((*inSkin)[ent][ele]);
        result = adapt(tol, numComp, coords, values, range, plug,
                       (inSkin && outSkin) ? &skin : nullptr);
        if(result && outSkin)
          outSkin->insert(outSkin->end(), skin.begin(), skin.end());
        // the refined elements are first order, whatever the order of the
        // element they come from
        numNodes = _shape.numNodes;
      }
      if(result && (double)*outNb + coords.size() / numNodes > 2147483647.) {
        Msg::Error("Too many elements in adaptive view: lower the recursion "
                   "level or raise the target error");
        return;
      }
      if(result) {
        *outNb += coords.size() / numNodes;
        for(std::size_t i = 0; i < coords.size() / numNodes; i++) {
          for(int k = 0; k < numNodes; ++k)
            outList->push_back(coords[numNodes * i + k].c[0]);
          for(int k = 0; k < numNodes; ++k)
            outList->push_back(coords[numNodes * i + k].c[1]);
          for(int k = 0; k < numNodes; ++k)
            outList->push_back(coords[numNodes * i + k].c[2]);
          for(int k = 0; k < numNodes; ++k)
            for(int l = 0; l < numComp; ++l)
              outList->push_back(values[numNodes * i + k].v[l]);
        }
      }
    }
  }
}

adaptiveData::adaptiveData(PViewData *data, bool outDataInit)
  : _step(-1), _level(-1), _tol(-1.), _inData(data), _points(nullptr),
    _lines(nullptr), _triangles(nullptr), _quadrangles(nullptr),
    _polygons(nullptr), _tetrahedra(nullptr), _hexahedra(nullptr),
    _prisms(nullptr), _pyramids(nullptr), _polyhedra(nullptr)
{
  if(outDataInit ==
     true) { // For visualization of the adapted view in GMSH GUI only
    _outData = new PViewDataList(true);
    _outData->setName(data->getName() + "_adapted");
  }
  else {
    _outData = nullptr; // For external used
  }
  // (a kind of element the view has no shape functions for is interpolated
  // at first order)
  auto make = [&](int type, int num) -> adaptiveElements * {
    if(!num) return nullptr;
    std::vector<fullMatrix<double> *> p;
    _inData->getInterpolationMatrices(type, p);
    return new adaptiveElements(type, p);
  };
  _points = make(TYPE_PNT, _inData->getNumPoints());
  _lines = make(TYPE_LIN, _inData->getNumLines());
  _triangles = make(TYPE_TRI, _inData->getNumTriangles());
  _quadrangles = make(TYPE_QUA, _inData->getNumQuadrangles());
  _tetrahedra = make(TYPE_TET, _inData->getNumTetrahedra());
  _prisms = make(TYPE_PRI, _inData->getNumPrisms());
  _hexahedra = make(TYPE_HEX, _inData->getNumHexahedra());
  _pyramids = make(TYPE_PYR, _inData->getNumPyramids());
  if(_inData->getNumPolygons())
    _polygons = new adaptiveElements(TYPE_TRI, {});
  if(_inData->getNumPolyhedra())
    _polyhedra = new adaptiveElements(TYPE_TET, {});
  upWriteVTK(true); // By default, write VTK data if called...
  upBuildStaticData(false); // ... and do not generated global static data
                            // structure (only useful for ParaView plugin).
}

adaptiveData::~adaptiveData()
{
  if(_points) delete _points;
  if(_lines) delete _lines;
  if(_triangles) delete _triangles;
  if(_quadrangles) delete _quadrangles;
  if(_polygons) delete _polygons;
  if(_tetrahedra) delete _tetrahedra;
  if(_prisms) delete _prisms;
  if(_hexahedra) delete _hexahedra;
  if(_pyramids) delete _pyramids;
  if(_outData) delete _outData;
  if(_polyhedra) delete _polyhedra;
}

// The faces of the volumes of the view that no other volume shares, a bit
// each, for each entity and element. Not for the views with polyhedra, whose
// refined elements are matched by the coordinates of their nodes, nor for
// those without node identifiers.
bool adaptiveData::_findSkin(int step,
                             std::vector<std::vector<unsigned char> > &skin)
{
  skin.clear();
  if(_polygons || _polyhedra) return false;
  if(!_tetrahedra && !_hexahedra && !_prisms && !_pyramids) return false;
  struct where {
    int ent, ele, face, count;
  };
  std::map<std::array<std::size_t, 4>, where> faces;
  skin.resize(_inData->getNumEntities(step));
  for(int ent = 0; ent < _inData->getNumEntities(step); ent++) {
    skin[ent].resize(_inData->getNumElements(step, ent), 0);
    for(int ele = 0; ele < _inData->getNumElements(step, ent); ele++) {
      if(_inData->skipElement(step, ent, ele)) continue;
      int type = _inData->getType(step, ent, ele);
      if(type != TYPE_TET && type != TYPE_HEX && type != TYPE_PRI &&
         type != TYPE_PYR)
        continue;
      const adaptiveShape &shape = adaptiveShape::get(type);
      for(std::size_t f = 0; f < shape.faces.size(); f++) {
        std::array<std::size_t, 4> key = {0, 0, 0, 0};
        for(std::size_t k = 0; k < shape.faces[f].size(); k++) {
          key[k] = _inData->getNodeId(step, ent, ele, shape.faces[f][k]);
          if(!key[k]) return false;
        }
        std::sort(key.begin(), key.end());
        auto it = faces.find(key);
        if(it == faces.end())
          faces[key] = {ent, ele, (int)f, 1};
        else
          it->second.count++;
      }
    }
  }
  for(auto &f : faces)
    if(f.second.count == 1)
      skin[f.second.ent][f.second.ele] |= (unsigned char)(1 << f.second.face);
  return true;
}

void adaptiveData::changeResolution(int step, int level, double tol,
                                    GMSH_PostPlugin *plug)
{
  if(_level != level) {
    if(_points) _points->init(level);
    if(_lines) _lines->init(level);
    if(_triangles) _triangles->init(level);
    if(_quadrangles) _quadrangles->init(level);
    if(_tetrahedra) _tetrahedra->init(level);
    if(_prisms) _prisms->init(level);
    if(_hexahedra) _hexahedra->init(level);
    if(_pyramids) _pyramids->init(level);
  }
  if(plug || _step != step || _level != level || _tol != tol) {
    _outData->setDirty(true);
    // which faces of the elements are on the skin of the view, so that the
    // refined elements can tell the faces they have on it
    std::vector<std::vector<unsigned char> > inSkin;
    std::map<int, std::vector<unsigned char> > outSkin;
    bool skin = _findSkin(step, inSkin);
    auto add = [&](adaptiveElements *e, int type) {
      if(!e) return;
      e->addInView(tol, step, _inData, _outData, plug, level, type,
                   skin ? &inSkin : nullptr, skin ? &outSkin[type] : nullptr);
    };
    add(_points, TYPE_PNT);
    add(_lines, TYPE_LIN);
    add(_triangles, TYPE_TRI);
    add(_quadrangles, TYPE_QUA);
    add(_polygons, TYPE_POLYG);
    add(_tetrahedra, TYPE_TET);
    add(_prisms, TYPE_PRI);
    add(_hexahedra, TYPE_HEX);
    add(_pyramids, TYPE_PYR);
    add(_polyhedra, TYPE_POLYH);
    _outData->finalize();
    if(skin) {
      // in the order of the lists
      std::vector<unsigned char> all;
      for(int type : {TYPE_PNT, TYPE_LIN, TYPE_TRI, TYPE_QUA, TYPE_TET,
                      TYPE_HEX, TYPE_PRI, TYPE_PYR})
        all.insert(all.end(), outSkin[type].begin(), outSkin[type].end());
      _outData->setSkinMasks(all);
    }
  }
  _step = step;
  _level = level;
  _tol = tol;

}

bool VTKData::isLittleEndian()
{
  int num = 1;
  if(*(char *)&num == 1)
    return true; // Little Endian
  else
    return false; // Big Endian
}

void VTKData::SwapArrayByteOrder(void *array, int nbytes, int nItems)
{
  // This swaps the byte order for the array of nItems each of size nbytes
  int i, j;
  unsigned char *ucDst = (unsigned char *)array;

  for(i = 0; i < nItems; i++) {
    for(j = 0; j < (nbytes / 2); j++)
      std::swap(ucDst[j], ucDst[(nbytes - 1) - j]);
    ucDst += nbytes;
  }
}

void VTKData::writeVTKElmData()
{
  // This routine writes vtu files (ascii or binary) from a elemental data base
  // of nodes coordinates, cell connectivity, type and offset, and point data
  // (either scalar or vector field)

  // Format choice
  if(vtkFormat == "vtu") {
    if(vtkCountTotElmLev0 <= numPartMinElm * minElmPerPart) {
      if((vtkCountTotElmLev0 - 1) % minElmPerPart == 0) { // new filename
        vtkCountFile = (vtkCountTotElmLev0 - 1) / minElmPerPart;
        initVTKFile();
      }
    }
    else {
      if((vtkCountTotElmLev0 - 1 - numPartMinElm * minElmPerPart) %
           maxElmPerPart ==
         0) {
        // new filename
        vtkCountFile = numPartMinElm + (vtkCountTotElmLev0 - 1 -
                                        numPartMinElm * minElmPerPart) /
                                         maxElmPerPart;
        initVTKFile();
      }
    }

    if(vtkIsBinary == true) { // Use appended format for raw binary

      // Write raw binary data to separate files first.  Text headers will be
      // added later, as wall as raw data size (needs to know the size before)

      int counter;
      uint64_t *i64array;
      uint8_t *i8array;
      double *darray;

      // Node value
      counter = 0;
      darray = new double[vtkNumComp * vtkLocalValues.size()];
      for(auto it = vtkLocalValues.begin(); it != vtkLocalValues.end(); ++it) {
        for(int i = 0; i < vtkNumComp; i++) { darray[counter + i] = it->v[i]; }
        counter += vtkNumComp;
        vtkCountTotVal += vtkNumComp;
      }
      assert(counter == vtkNumComp * (int)vtkLocalValues.size());
      fwrite(darray, sizeof(double), vtkNumComp * vtkLocalValues.size(),
             vtkFileNodVal);
      delete[] darray;

      // Points
      int sizeArray = (int)vtkLocalCoords.size();
      darray = new double[3 * sizeArray];
      counter = 0;
      for(auto it = vtkLocalCoords.begin(); it != vtkLocalCoords.end(); ++it) {
        for(int i = 0; i < 3; i++) { darray[counter + i] = (*it).c[i]; }
        counter += 3;
        vtkCountCoord += 3;
      }
      fwrite(darray, sizeof(double), 3 * sizeArray, vtkFileCoord);
      delete[] darray;

      // Cells

      // First count the number of integers that described the cell data in
      // vtkConnectivity See
      // http://www.vtk.org/wp-content/uploads/2015/04/file-formats.pdf (page 4)
      int cellSizeData = 0;
      for(auto it = vtkLocalConnectivity.begin();
          it != vtkLocalConnectivity.end(); ++it) {
        // Contrary to vtk format, no +1 required for the number of nodes in the
        // element
        cellSizeData += (int)it->size();
      }

      // Connectivity (and build offset at the same time)
      counter = 0;
      int cellcounter = 0;
      i64array = new uint64_t[cellSizeData];
      uint64_t *cellOffset = new uint64_t[vtkLocalConnectivity.size()];
      for(auto it = vtkLocalConnectivity.begin();
          it != vtkLocalConnectivity.end(); ++it) {
        for(auto jt = it->begin(); jt != it->end(); ++jt) {
          i64array[counter] = *jt;
          counter++;
          vtkCountTotNodConnect++;
        }
        cellOffset[cellcounter] = vtkCountTotNodConnect; // build the offset
        cellcounter++;
      }
      fwrite(i64array, sizeof(uint64_t), cellSizeData, vtkFileConnect);
      delete[] i64array;

      // Cell offset
      fwrite(cellOffset, sizeof(uint64_t), vtkLocalConnectivity.size(),
             vtkFileCellOffset);
      delete[] cellOffset;

      // Cell type
      counter = 0;
      i8array = new uint8_t[vtkLocalConnectivity.size()];
      for(auto it = vtkLocalCellType.begin(); it != vtkLocalCellType.end();
          it++) {
        i8array[counter] = *it;
        counter++;
      }
      fwrite(i8array, sizeof(uint8_t), vtkLocalConnectivity.size(),
             vtkFileCellType);
      delete[] i8array;
    }
    else { // ascii

      // Node values
      for(auto it = vtkLocalValues.begin(); it != vtkLocalValues.end(); ++it) {
        for(int i = 0; i < vtkNumComp; i++) {
          fprintf(vtkFileNodVal, "%23.16e ", (*it).v[i]);
          vtkCountTotVal++;
          if(vtkCountTotVal % 6 == 0) fprintf(vtkFileNodVal, "\n");
        }
      }

      for(auto it = vtkLocalCoords.begin(); it != vtkLocalCoords.end(); it++) {
        fprintf(vtkFileCoord, "%23.16e %23.16e %23.16e ", (*it).c[0],
                (*it).c[1], (*it).c[2]);
        vtkCountCoord += 3;
        if(vtkCountCoord % 6 == 0) fprintf(vtkFileCoord, "\n");
      }

      // Cells
      // Connectivity
      int *cellOffset = new int[vtkLocalConnectivity.size()];
      int cellcounter = 0;
      for(auto it = vtkLocalConnectivity.begin();
          it != vtkLocalConnectivity.end(); ++it) {
        for(auto jt = it->begin(); jt != it->end(); ++jt) {
          fprintf(vtkFileConnect, "%d ", *jt);
          vtkCountTotNodConnect++;
          if(vtkCountTotNodConnect % 6 == 0) fprintf(vtkFileConnect, "\n");
        }
        cellOffset[cellcounter] = vtkCountTotNodConnect; // build the offset
        cellcounter++;
      }

      // Cell offset
      for(uint64_t i = 0; i < vtkLocalConnectivity.size(); i++) {
        fprintf(vtkFileCellOffset, "%d ", cellOffset[i]);
        vtkCountCellOffset++;
        if(vtkCountCellOffset % 6 == 0) fprintf(vtkFileCellOffset, "\n");
      }
      delete[] cellOffset;

      // Cell type
      for(auto it = vtkLocalCellType.begin(); it != vtkLocalCellType.end();
          it++) {
        fprintf(vtkFileCellType, "%d ", *it);
        vtkCountCellType++;
        if(vtkCountCellType % 6 == 0) fprintf(vtkFileCellType, "\n");
      }

    } // if ascii

    // finalize and close current vtu file
    if(vtkCountTotElmLev0 <= numPartMinElm * minElmPerPart) {
      if(vtkCountTotElmLev0 % minElmPerPart == 0) { finalizeVTKFile(); }
    }
    else {
      if((vtkCountTotElmLev0 - numPartMinElm * minElmPerPart) % maxElmPerPart ==
         0) {
        finalizeVTKFile();
      }
    }

  } // vtu format
  else
    Msg::Error("Unknown format");
}

void VTKData::initVTKFile()
{
  // Temporary files
  vtkFileCoord = fopen("vtkCoords.vtu", "wb");
  vtkFileConnect = fopen("vtkConnectivity.vtu", "wb");
  vtkFileCellOffset = fopen("vtkCellOffset.vtu", "wb");
  vtkFileCellType = fopen("vtkCellType.vtu", "wb");
  vtkFileNodVal = fopen("vtkNodeValue.vtu", "wb");

  if(vtkCountFile == 0) {
    // write the pvtu file and create the corresponding directory for vtu files

    if(vtkUseDefaultName == 1) {
      vtkDirName = vtkFieldName + "_step" + ToString<int>(vtkStep) + "_level" +
                   ToString<int>(vtkLevel) + "_tol" + ToString<double>(vtkTol) +
                   "_npart" + ToString<int>(vtkNpart);
    }
    else {
      // Remove existing extension here to avoid duplicate
      std::size_t found = vtkFileName.find_last_of('.');
      // remove extension
      if(found != std::string::npos) vtkFileName = vtkFileName.substr(0, found);
      vtkDirName = vtkFileName;
    }

    CreateSingleDir(vtkDirName);

    vtkFileName =
      vtkDirName + ".p" + vtkFormat; // add pvtu extension to file name
    vtkFile = fopen(vtkFileName.c_str(), "w");

    bool littleEndian = isLittleEndian(); // Determine endianess
    if(littleEndian == true)
      fprintf(vtkFile, "<VTKFile type=\"PUnstructuredGrid\" version=\"1.0\" "
                       "byte_order=\"LittleEndian\">\n");
    else
      fprintf(vtkFile, "<VTKFile type=\"PUnstructuredGrid\" version=\"1.0\" "
                       "byte_order=\"BigEndian\">\n");

    fprintf(vtkFile, "<PUnstructuredGrid GhostLevel=\"0\">\n");
    fprintf(vtkFile, "<PPoints>\n");
    fprintf(vtkFile, "<DataArray type=\"Float64\" Name=\"Points\" "
                     "NumberOfComponents=\"3\"/>\n");
    fprintf(vtkFile, "</PPoints>\n");

    fprintf(vtkFile, "<PCells>\n");
    fprintf(vtkFile, "<PDataArray type=\"Int64\" Name=\"connectivity\" "
                     "NumberOfComponents=\"1\"/>\n");
    fprintf(vtkFile, "<PDataArray type=\"Int64\" Name=\"offsets\" "
                     "NumberOfComponents=\"1\"/>\n");
    fprintf(
      vtkFile,
      "<PDataArray type=\"UInt8\" Name=\"types\" NumberOfComponents=\"1\"/>\n");
    fprintf(vtkFile, "</PCells>\n");

    fprintf(vtkFile, "<PPointData>\n");
    fprintf(
      vtkFile,
      "<PDataArray type=\"Float64\" Name=\"%s\" NumberOfComponents=\"%d\"/>\n",
      vtkFieldName.c_str(), vtkNumComp);
    fprintf(vtkFile, "</PPointData>\n");

    fprintf(vtkFile, "<PCellData>\n");
    fprintf(vtkFile, "</PCellData>\n");

    for(int i = 0; i < vtkNpart; i++)
      fprintf(vtkFile, "<Piece Source=\"%s/data%d.vtu\"/>\n",
              vtkDirName.c_str(), i);
    fprintf(vtkFile, "</PUnstructuredGrid>\n");
    fprintf(vtkFile, "</VTKFile>\n");
    fclose(vtkFile);
  }
}

void VTKData::finalizeVTKFile()
{
  // This routine writes vtu files (ascii or binary) from a complete data base
  // of nodes coordinates, cell connectivity, type and offset, and point data
  // (either scalar or vector field)

  // Close first temporary files.  Todo: Avoid multiple open/close actions and
  // keep the file open to write all information
  fclose(vtkFileCoord);
  fclose(vtkFileConnect);
  fclose(vtkFileCellOffset);
  fclose(vtkFileCellType);
  fclose(vtkFileNodVal);

  bool littleEndian = isLittleEndian(); // Determine endianess

  // Open final file
  std::string filename;
  filename = vtkDirName + "/data" + ToString(vtkCountFile) + "." + vtkFormat;

  Msg::StatusBar(true,
                 "Writing VTK data in %s: fieldname = %s - numElm = %d - "
                 "numNod = %d nodes\n",
                 filename.c_str(), vtkFieldName.c_str(), vtkCountTotElm,
                 vtkCountTotNod);

  assert(vtkCountTotNod == vtkCountCoord / 3);

  // Now concatenate headers with data files
  if(vtkFormat == "vtu") { // Format choice

    if(vtkIsBinary == true) { // Binary or ascii

      vtkFile = fopen(filename.c_str(), "wb");
      if(vtkFile == nullptr) {
        printf("Could not open file %s\n", filename.c_str());
        return;
      }

      uint64_t byteoffset = 0;

      // Headers first

      if(littleEndian == true)
        fprintf(vtkFile, "<VTKFile type=\"UnstructuredGrid\" version=\"1.0\" "
                         "byte_order=\"LittleEndian\" "
                         "header_type=\"UInt64\">\n");
      else
        fprintf(vtkFile, "<VTKFile type=\"PUnstructuredGrid\" version=\"1.0\" "
                         "byte_order=\"BigEndian\" header_type=\"UInt64\">\n");
      fprintf(vtkFile, "<UnstructuredGrid>\n");
      fprintf(vtkFile, "<Piece NumberOfPoints=\"%d\" NumberOfCells=\"%d\">\n",
              vtkCountTotNod, vtkCountTotElm);

      // Node value
      fprintf(vtkFile, "<PointData>\n");
      fprintf(vtkFile,
              "<DataArray type=\"Float64\" Name=\"%s\" "
              "NumberOfComponents=\"%d\" format=\"appended\" offset=\"%" PRIu64
              "\"/>\n",
              vtkFieldName.c_str(), vtkNumComp, byteoffset);
      fprintf(vtkFile, "</PointData>\n");
      byteoffset = byteoffset + (vtkCountTotNod * vtkNumComp + 1) *
                                  sizeof(double); // +1 for datasize in bytes

      // Cell values (none here but may change)
      fprintf(vtkFile, "<CellData>\n");
      fprintf(vtkFile,
              "</CellData>\n"); // no offset here because empty cell data

      // Nodes
      fprintf(vtkFile, "<Points>\n");
      fprintf(vtkFile,
              "<DataArray type=\"Float64\" Name=\"Points\" "
              "NumberOfComponents=\"3\" format=\"appended\" offset=\"%" PRIu64
              "\"/>\n",
              byteoffset);
      fprintf(vtkFile, "</Points>\n");
      byteoffset = byteoffset + (vtkCountCoord + 1) *
                                  sizeof(double); // +1 for datasize in bytes

      // Cells
      fprintf(vtkFile, "<Cells>\n");
      fprintf(vtkFile,
              "<DataArray type=\"Int64\" Name=\"connectivity\" "
              "format=\"appended\" offset=\"%" PRIu64 "\"/>\n",
              byteoffset);
      byteoffset = byteoffset + (vtkCountTotNodConnect + 1) * sizeof(uint64_t);
      fprintf(vtkFile,
              "<DataArray type=\"Int64\" Name=\"offsets\" format=\"appended\" "
              "offset=\"%" PRIu64 "\"/>\n",
              byteoffset);
      byteoffset = byteoffset + (vtkCountTotElm + 1) * sizeof(uint64_t);
      fprintf(vtkFile,
              "<DataArray type=\"UInt8\" Name=\"types\" format=\"appended\" "
              "offset=\"%" PRIu64 "\"/>\n",
              byteoffset);
      byteoffset = byteoffset + (vtkCountTotElm + 1) * sizeof(uint8_t);
      fprintf(vtkFile, "</Cells>\n");

      fprintf(vtkFile, "</Piece>\n");
      fprintf(vtkFile, "</UnstructuredGrid>\n");

      fprintf(vtkFile, "<AppendedData encoding=\"raw\">\n");
      fprintf(vtkFile, "_");

      uint64_t datasize;

      // Node values
      datasize = vtkNumComp * vtkCountTotNod * sizeof(double);
      fwrite(&datasize, sizeof(uint64_t), 1, vtkFile);
      fclose(vtkFile);

      std::ifstream if_vtkNodeValue("vtkNodeValue.vtu", std::ios_base::binary);
      std::ofstream of_vtkfile(filename.c_str(),
                               std::ios_base::binary | std::ios_base::app);
      of_vtkfile << if_vtkNodeValue.rdbuf();
      if_vtkNodeValue.close();
      of_vtkfile.close();

      // Points
      vtkFile = fopen(filename.c_str(), "ab");
      datasize = vtkCountTotNod * 3 * sizeof(double);
      fwrite(&datasize, sizeof(uint64_t), 1, vtkFile);
      fclose(vtkFile);

      std::ifstream if_vtkCoords("vtkCoords.vtu", std::ios_base::binary);
      of_vtkfile.open(filename.c_str(),
                      std::ios_base::binary | std::ios_base::app);
      of_vtkfile << if_vtkCoords.rdbuf();
      if_vtkCoords.close();
      of_vtkfile.close();

      // Cells
      // Connectivity
      vtkFile = fopen(filename.c_str(), "ab");
      datasize = vtkCountTotNodConnect * sizeof(uint64_t);
      fwrite(&datasize, sizeof(uint64_t), 1, vtkFile);
      fclose(vtkFile);

      std::ifstream if_vtkConnectivity("vtkConnectivity.vtu",
                                       std::ios_base::binary);
      of_vtkfile.open(filename.c_str(),
                      std::ios_base::binary | std::ios_base::app);
      of_vtkfile << if_vtkConnectivity.rdbuf();
      if_vtkConnectivity.close();
      of_vtkfile.close();

      // Cell offset
      vtkFile = fopen(filename.c_str(), "ab");
      datasize = vtkCountTotElm * sizeof(uint64_t);
      fwrite(&datasize, sizeof(uint64_t), 1, vtkFile);
      fclose(vtkFile);

      std::ifstream if_vtkCellOffset("vtkCellOffset.vtu",
                                     std::ios_base::binary);
      of_vtkfile.open(filename.c_str(),
                      std::ios_base::binary | std::ios_base::app);
      of_vtkfile << if_vtkCellOffset.rdbuf();
      if_vtkCellOffset.close();
      of_vtkfile.close();

      // Cell type
      vtkFile = fopen(filename.c_str(), "ab");
      datasize = vtkCountTotElm * sizeof(uint8_t);
      fwrite(&datasize, sizeof(uint64_t), 1, vtkFile);
      fclose(vtkFile);

      std::ifstream if_vtkCellType("vtkCellType.vtu", std::ios_base::binary);
      of_vtkfile.open(filename.c_str(),
                      std::ios_base::binary | std::ios_base::app);
      of_vtkfile << if_vtkCellType.rdbuf();
      if_vtkCellType.close();
      of_vtkfile.close();

      vtkFile = fopen(filename.c_str(), "ab");
      fprintf(vtkFile, "\n");
      fprintf(vtkFile, "</AppendedData>\n");
      fprintf(vtkFile, "</VTKFile>\n"); // for both binary and ascii
      fclose(vtkFile);
    }
    else { // ascii

      vtkFile = fopen(filename.c_str(), "w");
      if(vtkFile == nullptr) {
        printf("Could not open file %s\n", filename.c_str());
        return;
      }

      if(littleEndian == true)
        fprintf(vtkFile, "<VTKFile type=\"UnstructuredGrid\" version=\"1.0\" "
                         "byte_order=\"LittleEndian\" "
                         "header_type=\"UInt64\">\n");
      else
        fprintf(vtkFile, "<VTKFile type=\"PUnstructuredGrid\" version=\"1.0\" "
                         "byte_order=\"BigEndian\" header_type=\"UInt64\">\n");
      fprintf(vtkFile, "<UnstructuredGrid>\n");
      fprintf(vtkFile, "<Piece NumberOfPoints=\"%d\" NumberOfCells=\"%d\">\n",
              vtkCountTotNod, vtkCountTotElm);

      // Node values
      fprintf(vtkFile, "<PointData>\n");
      fprintf(vtkFile,
              "<DataArray type=\"Float64\" Name=\"%s\" "
              "NumberOfComponents=\"%d\" format=\"ascii\">\n",
              vtkFieldName.c_str(), vtkNumComp);
      fclose(vtkFile); // close file for binary concatenation

      std::ifstream if_vtkNodeValue("vtkNodeValue.vtu", std::ios_base::binary);
      std::ofstream of_vtkfile(filename.c_str(),
                               std::ios_base::binary | std::ios_base::app);
      of_vtkfile << if_vtkNodeValue.rdbuf();
      if_vtkNodeValue.close();
      of_vtkfile.close();

      vtkFile = fopen(filename.c_str(), "a");
      fprintf(vtkFile, "</DataArray>\n");
      fprintf(vtkFile, "</PointData>\n");

      // Cell values
      fprintf(vtkFile, "<CellData>\n");
      fprintf(vtkFile, "</CellData>\n");

      // Nodes
      fprintf(vtkFile, "<Points>\n");
      fprintf(vtkFile, "<DataArray type=\"Float64\" Name=\"Points\" "
                       "NumberOfComponents=\"3\" format=\"ascii\">\n");
      fclose(vtkFile); // close file for binary concatenation

      of_vtkfile.open(filename.c_str(),
                      std::ios_base::binary | std::ios_base::app);
      std::ifstream if_vtkCoords("vtkCoords.vtu", std::ios_base::binary);
      of_vtkfile << if_vtkCoords.rdbuf();
      if_vtkCoords.close();
      of_vtkfile.close();

      vtkFile = fopen(filename.c_str(), "a");
      fprintf(vtkFile, "</DataArray>\n");
      fprintf(vtkFile, "</Points>\n");

      // Cells
      fprintf(vtkFile, "<Cells>\n");
      fprintf(
        vtkFile,
        "<DataArray type=\"Int64\" Name=\"connectivity\" format=\"ascii\">\n");
      fclose(vtkFile); // close file for binary concatenation

      // Connectivity
      of_vtkfile.open(filename.c_str(),
                      std::ios_base::binary | std::ios_base::app);
      std::ifstream if_vtkConnectivity("vtkConnectivity.vtu",
                                       std::ios_base::binary);
      of_vtkfile << if_vtkConnectivity.rdbuf();
      if_vtkConnectivity.close();
      of_vtkfile.close();

      vtkFile = fopen(filename.c_str(), "a");
      fprintf(vtkFile, "</DataArray>\n");

      // Cell offset
      fprintf(vtkFile,
              "<DataArray type=\"Int64\" Name=\"offsets\" format=\"ascii\">\n");
      fclose(vtkFile); // close file for binary concatenation

      of_vtkfile.open(filename.c_str(),
                      std::ios_base::binary | std::ios_base::app);
      std::ifstream if_vtkCellOffset("vtkCellOffset.vtu",
                                     std::ios_base::binary);
      of_vtkfile << if_vtkCellOffset.rdbuf();
      if_vtkCellOffset.close();
      of_vtkfile.close();

      vtkFile = fopen(filename.c_str(), "a");
      fprintf(vtkFile, "</DataArray>\n");

      // Cell type
      fprintf(vtkFile,
              "<DataArray type=\"UInt8\" Name=\"types\" format=\"ascii\">\n");
      fclose(vtkFile); // close file for binary concatenation

      of_vtkfile.open(filename.c_str(),
                      std::ios_base::binary | std::ios_base::app);
      std::ifstream if_vtkCellType("vtkCellType.vtu", std::ios_base::binary);
      of_vtkfile << if_vtkCellType.rdbuf();
      if_vtkCellType.close();
      of_vtkfile.close();

      vtkFile = fopen(filename.c_str(), "a");
      fprintf(vtkFile, "</DataArray>\n");
      fprintf(vtkFile, "</Cells>\n");

      fprintf(vtkFile, "</Piece>\n");
      fprintf(vtkFile, "</UnstructuredGrid>\n");

      fprintf(vtkFile, "</VTKFile>\n"); // for both binary and ascii
      fclose(vtkFile);
    } // if binary/ascii

    // Remove temporary files now
    if(remove("vtkCoords.vtu") != 0)
      printf("ERROR: Could not remove vtkCoords.vtu\n");
    if(remove("vtkConnectivity.vtu") != 0)
      printf("ERROR: Could not remove vtkConnectivity.vtu\n");
    if(remove("vtkCellOffset.vtu") != 0)
      printf("ERROR: Could not remove vtkCellOffset.vtu\n");
    if(remove("vtkCellType.vtu") != 0)
      printf("ERROR: Could not remove vtkCellType.vtu\n");
    if(remove("vtkNodeValue.vtu") != 0)
      printf("ERROR: Could not remove vtkNodeValue.vtu\n");

    // Reset counters for next file
    vtkCountTotNod = 0;
    vtkCountTotElm = 0;
    vtkCountCoord = 0;
    vtkCountTotNodConnect = 0;
    vtkCountTotVal = 0;
    vtkCountCellOffset = 0;
    vtkCountCellType = 0;
  }

  else
    Msg::Error("File format unknown: %s", vtkFormat.c_str());
}

int VTKData::getPVCellType(int numEdges)
{
  int cellType; // Convention for cell types in ParaView
  switch(numEdges) {
  case 0:
    printf(
      "WARNING: Trying to write a node to the ParaView data base and file\n");
    cellType = -1;
    break;
  case 1:
    printf(
      "WARNING: Trying to write a node to the ParaView data base and file\n");
    cellType = -2;
    break;
  case 3:
    cellType = 5; // 2D VTK triangle
    break;
  case 4:
    cellType = 9; // 2D VTK quadrangle
    break;
  case 6:
    cellType = 10; // 3D VTK tetrahedron
    break;
  case 9:
    cellType = 13; // 3D VTK prism/wedge
    break;
  case 8:
    cellType = 14; // 3D VTK pyramid
    break;
  case 12:
    cellType = 12; // 3D VTK hexahedron
    break;
  default:
    printf("ERROR: No cell type was detected\n");
    cellType = -1;
    break;
  }

  return cellType;
}

void adaptiveElements::buildMapping(nodMap &myNodMap, double tol,
                                    int &numNodInsert)
{
  if(tol > 0.0 || myNodMap.getSize() == 0) {
    // Either this is not a uniform refinement and we need to rebuild the whole
    // mapping for each canonical element, or this is the first time we try to
    // build the mapping

    myNodMap
      .cleanMapping(); // Required if tol > 0 (local error based adaptation)

    // the vertices of the elements that are kept, by their index in the
    // canonical refined element
    for(auto &leaf : all) {
      if(!leaf.visible) continue;
      for(int i = 0; i < _shape.numNodes; i++)
        myNodMap.mapping.push_back(leaf.p[i]->index);
    }

    if(myNodMap.mapping.size() == 0) {
      Msg::Error("Node mapping in buildMapping has zero size");
    }

    // Count number of unique nodes from the mapping
    // Use an ordered set for efficiency
    // This set is also used in case of partiel refinement
    std::set<int> uniqueNod;
    for(auto it = myNodMap.mapping.begin(); it != myNodMap.mapping.end();
        it++) {
      uniqueNod.insert(*it);
    }
    numNodInsert = (int)uniqueNod.size();

    // Renumber the elm in the mapping in case of partial refinement (when vis
    // tolerance > 0) so that we have a continuous numbering starting from 0
    // with no missing node id in the connectivity This require a new local and
    // temporary mapping, based on uniqueNod already generated above
    if(tol > 0.0) {
      std::map<int, int> renumbered;
      for(int n : uniqueNod) renumbered[n] = (int)renumbered.size();
      for(auto &n : myNodMap.mapping) n = renumbered[n];
    }
  }
}

void adaptiveElements::addInViewForVTK(int step, PViewData *in,
                                          VTKData &myVTKData, bool writeVTK,
                                          bool buildStaticData)
{
  int numComp = in->getNumComponents(0, 0, 0);
  if(numComp != 1 && numComp != 3 && numComp != 9) return;

  int numEle = 0;
  switch(_shape.numEdges) {
  case 0: numEle = in->getNumPoints(); break;
  case 1: numEle = in->getNumLines(); break;
  case 3: numEle = in->getNumTriangles(); break;
  case 4: numEle = in->getNumQuadrangles(); break;
  case 6: numEle = in->getNumTetrahedra(); break;
  case 9: numEle = in->getNumPrisms(); break;
  case 8: numEle = in->getNumPyramids(); break;
  case 12: numEle = in->getNumHexahedra(); break;
  }
  if(!numEle) return;

  // New variables for high order visualiztion through vtk files
  int numNodInsert = 0;
  nodMap myNodMap;

  double range = in->getMax(step) - in->getMin(step);

  for(int ent = 0; ent < in->getNumEntities(step); ent++) {
    for(int ele = 0; ele < in->getNumElements(step, ent); ele++) {
      if(in->skipElement(step, ent, ele) ||
         in->getNumEdges(step, ent, ele) != _shape.numEdges)
        continue;
      int numNodes = in->getNumNodes(step, ent, ele);
      std::vector<PCoords> coords;
      for(int i = 0; i < numNodes; i++) {
        double x, y, z;
        in->getNode(step, ent, ele, i, x, y, z);
        coords.push_back(PCoords(x, y, z));
      }
      int numVal = in->getNumValues(step, ent, ele);
      std::vector<PValues> values;

      switch(numComp) {
      case 1:
        for(int i = 0; i < numVal; i++) {
          double val;
          in->getValue(step, ent, ele, i, val);
          values.push_back(PValues(val));
        }
        break;
      case 3:
        for(int i = 0; i < numVal / 3; i++) {
          double vx, vy, vz;
          in->getValue(step, ent, ele, 3 * i, vx);
          in->getValue(step, ent, ele, 3 * i + 1, vy);
          in->getValue(step, ent, ele, 3 * i + 2, vz);
          values.push_back(PValues(vx, vy, vz));
        }
        break;
      case 9:
        for(int i = 0; i < numVal / 9; i++) {
          double vxx, vxy, vxz, vyx, vyy, vyz, vzx, vzy, vzz;
          in->getValue(step, ent, ele, 9 * i + 0, vxx);
          in->getValue(step, ent, ele, 9 * i + 1, vxy);
          in->getValue(step, ent, ele, 9 * i + 2, vxz);
          in->getValue(step, ent, ele, 9 * i + 3, vyx);
          in->getValue(step, ent, ele, 9 * i + 4, vyy);
          in->getValue(step, ent, ele, 9 * i + 5, vyz);
          in->getValue(step, ent, ele, 9 * i + 6, vzx);
          in->getValue(step, ent, ele, 9 * i + 7, vzy);
          in->getValue(step, ent, ele, 9 * i + 8, vzz);
          values.push_back(
            PValues(vxx, vxy, vxz, vyx, vyy, vyz, vzx, vzy, vzz));
        }
        break;
      }

      adapt(myVTKData.vtkTol, numComp, coords, values, range);

      // Inside initial element, after adapt() has been called

      // Build the mapping of the canonical element,
      // or recycle existing one in case  of uniform refinement
      buildMapping(myNodMap, myVTKData.vtkTol, numNodInsert);

      // Pre-allocate some space for the local coordinates and connectivity
      // in order to write to any component of the vector later through vec[i]

      myVTKData.vtkLocalCoords.resize(numNodInsert, PCoords(0.0, 0.0, 0.0));
      myVTKData.vtkLocalValues.resize(numNodInsert, PValues(numComp));

      for(std::size_t i = 0; i < coords.size() / _shape.numNodes; i++) {
        // Loop over
        //  - all refined elements if refinement level > 0
        //  - single initial element when refinement box is checked for the
        //  first time (ref level =0)

        // local connectivity for the considered sub triangle
        vectInt vtkElmConnectivity;

        for(int k = 0; k < _shape.numNodes; ++k) {
          // Connectivity of the considered sub-element
          int countTotNodloc = _shape.numNodes * i + k; // Nodes are duplicate here
          int vtkNodeId =
            myVTKData.vtkCountTotNod + myNodMap.mapping[countTotNodloc];
          vtkElmConnectivity.push_back(vtkNodeId);

          // Coordinates of the nodes of the considered sub-element
          double px, py, pz;
          px = coords[_shape.numNodes * i + k].c[0];
          py = coords[_shape.numNodes * i + k].c[1];
          pz = coords[_shape.numNodes * i + k].c[2];
          PCoords tmpCoords = PCoords(px, py, pz);
          myVTKData.vtkLocalCoords[myNodMap.mapping[countTotNodloc]] =
            tmpCoords;

          // Value associated with each nodes of the sub-element
          myVTKData.vtkLocalValues[myNodMap.mapping[countTotNodloc]] =
            values[_shape.numNodes * i + k];
        }

        // Add elm connectivity to vector
        myVTKData.vtkLocalConnectivity.push_back(vtkElmConnectivity);

        // Increment global elm number
        myVTKData.incrementTotElm(1);

        // Save element type
        myVTKData.vtkLocalCellType.push_back(
          myVTKData.getPVCellType(_shape.numEdges));

        // Global variables
        if(buildStaticData == true) {
          globalVTKData::vtkGlobalConnectivity.push_back(vtkElmConnectivity);
          globalVTKData::vtkGlobalCellType.push_back(
            myVTKData.getPVCellType(_shape.numEdges));
        }

        // Clear existing structure (safer)
        vtkElmConnectivity.clear();
      }

      // Increment global node and elm-lev0 number
      myVTKData.incrementTotNod(numNodInsert);
      myVTKData.incrementTotElmLev0(1);

      // Write the VTK data structure of the consider element to vtu file

      if(writeVTK == true) { myVTKData.writeVTKElmData(); }

      if(buildStaticData == true) {
        for(int i = 0; i < numNodInsert; i++) {
          globalVTKData::vtkGlobalCoords.push_back(myVTKData.vtkLocalCoords[i]);
        }

        for(int i = 0; i < numNodInsert; i++) {
          globalVTKData::vtkGlobalValues.push_back(myVTKData.vtkLocalValues[i]);
        }
      }

      myVTKData.clearLocalData();

    } // loop over mesh element
  }
}

int adaptiveElements::countElmLev0(int step, PViewData *in)
{
  int sum = 0;
  for(int ent = 0; ent < in->getNumEntities(step); ent++) {
    for(int ele = 0; ele < in->getNumElements(step, ent); ele++) {
      if(in->skipElement(step, ent, ele) ||
         in->getNumEdges(step, ent, ele) != _shape.numEdges)
        continue;
      else
        sum++;
    }
  }
  return sum;
}

int adaptiveData::countTotElmLev0(int step, PViewData *in)
{
  int sumElm = 0;

  if(_triangles) sumElm += _triangles->countElmLev0(step, in);
  if(_quadrangles) sumElm += _quadrangles->countElmLev0(step, in);
  if(_tetrahedra) sumElm += _tetrahedra->countElmLev0(step, in);
  if(_prisms) sumElm += _prisms->countElmLev0(step, in);
  if(_hexahedra) sumElm += _hexahedra->countElmLev0(step, in);
  if(_pyramids) sumElm += _pyramids->countElmLev0(step, in);

  return sumElm;
}

void adaptiveData::changeResolutionForVTK(int step, int level, double tol,
                                          int npart, bool isBinary,
                                          const std::string &guiFileName,
                                          int useDefaultName)
{
  // clean global VTK data structure before (re)generating it
  if(buildStaticData == true) globalVTKData::clearGlobalData();

  VTKData myVTKData(_inData->getName(), _inData->getNumComponents(0, 0, 0),
                    step, level, tol, guiFileName, useDefaultName, npart,
                    isBinary);
  myVTKData.vtkTotNumElmLev0 = countTotElmLev0(step, _inData);
  myVTKData.setFileDistribution();

  // Views of 2D and 3D elements only supported for VTK. _points and _lines are
  // currently ignored.
  if(_triangles) _triangles->init(myVTKData.vtkLevel);
  if(_quadrangles) _quadrangles->init(myVTKData.vtkLevel);
  if(_tetrahedra) _tetrahedra->init(myVTKData.vtkLevel);
  if(_prisms) _prisms->init(myVTKData.vtkLevel);
  if(_hexahedra) _hexahedra->init(myVTKData.vtkLevel);
  if(_pyramids) _pyramids->init(myVTKData.vtkLevel);

  if(_triangles)
    _triangles->addInViewForVTK(step, _inData, myVTKData, writeVTK,
                                buildStaticData);
  if(_quadrangles)
    _quadrangles->addInViewForVTK(step, _inData, myVTKData, writeVTK,
                                  buildStaticData);
  if(_tetrahedra)
    _tetrahedra->addInViewForVTK(step, _inData, myVTKData, writeVTK,
                                 buildStaticData);
  if(_prisms)
    _prisms->addInViewForVTK(step, _inData, myVTKData, writeVTK,
                             buildStaticData);
  if(_hexahedra)
    _hexahedra->addInViewForVTK(step, _inData, myVTKData, writeVTK,
                                buildStaticData);
  if(_pyramids)
    _pyramids->addInViewForVTK(step, _inData, myVTKData, writeVTK,
                               buildStaticData);

  Msg::StatusBar(true, "Done writing VTK data");
}
