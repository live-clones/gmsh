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
#include "Context.h"
#include <sstream>
#include "StringUtils.h"
#include "VTKXML.h"
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
    s.diagonal[0] = 3;
    s.diagonal[1] = 5;
    s.faces = {{0, 3, 2, 1}, {0, 1, 5, 4}, {0, 4, 7, 3},
               {1, 2, 6, 5}, {2, 3, 7, 6}, {4, 5, 6, 7}};
    s.shapeFunctions = hexahedronSF;
    break;
  case TYPE_PRI:
    // the triangles are cut in four, below and above the middle
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
    s.faces = {{0, 1, 4, 3}, {0, 3, 5, 2}, {1, 2, 5, 4}, {0, 2, 1}, {3, 4, 5}};
    s.shapeFunctions = prismSF;
    break;
  case TYPE_PYR:
    // Four pyramids on the base, one at the top, one upside down under it,
    // and four tetrahedra in the holes that are left: these are pyramids with
    // two nodes at the same place (the first and the fourth).
    s.numEdges = 8;
    nodes = {{-1, -1, 0}, {1, -1, 0}, {1, 1, 0}, {-1, 1, 0}, {0, 0, 1}};
    more = {{0, 1, 2, 3}, // 5: the centre of the base
            {0, 1}, {1, 2}, {2, 3}, {3, 0}, // 6: the base
            {0, 4}, {1, 4}, {2, 4}, {3, 4}}; // 10: the edges to the apex
    s.children = {{0, 6, 5, 9, 10},    {1, 7, 5, 6, 11},   {2, 8, 5, 7, 12},
                  {3, 9, 5, 8, 13},    {10, 11, 12, 13, 4}, {10, 13, 12, 11, 5},
                  {5, 11, 10, 5, 6},   {5, 12, 11, 5, 7},  {5, 13, 12, 5, 8},
                  {5, 10, 13, 5, 9}};
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
  // a child and the node of it at each point
  s.where.assign(s.points.size(), {0, 0});
  for(int c = 0; c < s.numChildren; c++)
    for(std::size_t j = 0; j < s.children[c].size(); j++)
      s.where[s.children[c][j]] = {c, (int)j};
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
    _coeffsGeom(nullptr), _eexpsGeom(nullptr), _numVals(0), _numNodes(0)
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

adaptiveElements::~adaptiveElements() {}

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

  int numVals = _numVals = _coeffsVal ? _coeffsVal->size1() : _shape.numNodes;
  int numNodes = _numNodes =
    _coeffsGeom ? _coeffsGeom->size1() : _shape.numNodes;

  // the shape functions at the vertices of the tree, a row per vertex
  _interpolVal.assign(allVertices.size() * numVals, 0.);
  _interpolGeom.assign(allVertices.size() * numNodes, 0.);
  _leaves.clear();
  for(auto &e : all)
    if(!e.e[0]) _leaves.push_back(&e);

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
    for(int j = 0; j < numVals; j++)
      _interpolVal[v.index * numVals + j] = sfv(j);
    evaluate(_coeffsGeom, _eexpsGeom, v, sfg);
    for(int j = 0; j < numNodes; j++)
      _interpolGeom[v.index * numNodes + j] = sfg(j);
  }
}

// The field at a vertex of the tree, and its position, for the element being
// adapted: computed when first asked for, as an error estimate that is
// satisfied early leaves most of the tree alone
void adaptiveElements::_evaluate(adaptiveWork &w, const adaptiveVertex *p) const
{
  if(w.evaluated[p->index] == w.stamp) return;
  w.evaluated[p->index] = w.stamp;
  const double *row = &_interpolVal[p->index * _numVals];
  double *v = &w.values[p->index * w.numComp];
  for(int c = 0; c < w.numComp; c++) {
    const double *in = &w.inValues[c * _numVals];
    double sum = 0.;
    for(int j = 0; j < _numVals; j++) sum += row[j] * in[j];
    v[c] = sum;
  }
  // the error is estimated on the norm of vectors and tensors
  double norm = v[0];
  if(w.numComp > 1) {
    norm = 0.;
    for(int c = 0; c < w.numComp; c++) norm += v[c] * v[c];
    norm = sqrt(norm);
  }
  w.norm[p->index] = norm;
}

void adaptiveElements::_locate(adaptiveWork &w, const adaptiveVertex *p) const
{
  if(w.located[p->index] == w.stamp) return;
  w.located[p->index] = w.stamp;
  const double *row = &_interpolGeom[p->index * _numNodes];
  for(int k = 0; k < 3; k++) {
    const double *in = &w.inXYZ[k * _numNodes];
    double sum = 0.;
    for(int j = 0; j < _numNodes; j++) sum += row[j] * in[j];
    w.xyz[3 * p->index + k] = sum;
  }
}

// What is drawn of the field in an element is its first order interpolation
// between the nodes. At a point the next subdivision adds, the mean of some
// of the nodes, this is the mean of their values: the error of an element is
// the largest difference with the field itself at these points. (Quadrangles
// and hexahedra are drawn cut along a diagonal, which makes another value at
// their centre.)
double adaptiveElements::_errorOf(adaptiveWork &w,
                                  const adaptiveElement *e) const
{
  auto field = [&](const adaptiveVertex *p) {
    _evaluate(w, p);
    return w.norm[p->index];
  };
  double error = 0.;
  for(std::size_t k = _shape.numNodes; k < _shape.points.size(); k++) {
    double drawn = 0.;
    for(int i : _shape.points[k]) drawn += field(e->p[i]);
    drawn /= _shape.points[k].size();
    const adaptiveVertex *p = e->e[_shape.where[k][0]]->p[_shape.where[k][1]];
    error = std::max(error, fabs(field(p) - drawn));
    if(k + 1 == _shape.points.size() && _shape.diagonal[0] >= 0) {
      drawn = 0.5 * (field(e->p[_shape.diagonal[0]]) +
                     field(e->p[_shape.diagonal[1]]));
      error = std::max(error, fabs(field(p) - drawn));
    }
  }
  return error;
}

// An element is kept if its error is below the threshold, and the errors of
// its children too: a field can happen to be right at the few points looked
// at and wrong in between. The elements kept are added to w.visible.
void adaptiveElements::_error(adaptiveWork &w, const adaptiveElement *e,
                              double threshold) const
{
  if(!e->e[0]) {
    w.visible.push_back(e);
    return;
  }

  bool refine = _errorOf(w, e) > threshold;
  bool grandChildren = (e->e[0]->e[0] != nullptr);
  for(int i = 0; i < _shape.numChildren && grandChildren && !refine; i++)
    refine = _errorOf(w, e->e[i]) > threshold;

  if(refine)
    for(int i = 0; i < _shape.numChildren; i++) _error(w, e->e[i], threshold);
  else
    w.visible.push_back(e);
}

// the elements a plugin keeps: it looks at the tree itself, which is given
// the field everywhere (one element at a time: not for several threads)
void adaptiveElements::_askPlugin(adaptiveWork &w, GMSH_PostPlugin *plug)
{
  for(auto &e : all) e.visible = false;
  for(const adaptiveElement *e : w.visible)
    ((adaptiveElement *)e)->visible = true;
  for(auto &v : allVertices) {
    adaptiveVertex *p = (adaptiveVertex *)&v;
    _evaluate(w, p);
    _locate(w, p);
    p->X = w.xyz[3 * p->index];
    p->Y = w.xyz[3 * p->index + 1];
    p->Z = w.xyz[3 * p->index + 2];
    p->val = w.values[p->index * w.numComp];
  }
  plug->assignSpecificVisibility(&all.front());
  w.visible.clear();
  for(auto &e : all)
    if(e.visible) w.visible.push_back(&e);
}

int adaptiveElements::adapt(adaptiveWork &w, double tol, int numComp,
                            const double *xyz, const double *values,
                            double range, GMSH_PostPlugin *plug,
                            unsigned char onSkin, std::vector<double> &out,
                            std::vector<unsigned char> *outSkin)
{
  std::size_t numVertices = allVertices.size();
  if(!numVertices) {
    Msg::Warning("No adapted vertices to interpolate");
    return 0;
  }
  if(numComp != 1 && numComp != 3 && numComp != 9) {
    Msg::Error("Can only adapt scalar, vector or tensor data");
    return 0;
  }

  // nothing is known of the field for this element yet
  if(w.evaluated.size() != numVertices || w.numComp != numComp) {
    w.stamp = 0;
    w.numComp = numComp;
    w.evaluated.assign(numVertices, 0);
    w.located.assign(numVertices, 0);
    w.values.resize(numVertices * numComp);
    w.norm.resize(numVertices);
    w.xyz.resize(numVertices * 3);
  }
  w.stamp++;
  w.inXYZ = xyz;
  w.inValues = values;
  w.visible.clear();

  // The target error is relative to the range of the view. A negative one, or
  // a view that is constant, keeps the smallest subdivision.
  double threshold = (tol < 0. || range <= 0.) ? -1. : tol * range;
  if(threshold < 0. && !plug)
    w.visible.assign(_leaves.begin(), _leaves.end());
  else if(!plug || tol != 0.)
    _error(w, &all.front(), threshold);
  if(plug) _askPlugin(w, plug);

  // the elements that are kept, as the lists of a view hold them: the x, y
  // and z of the nodes, then their values
  int numNodes = _shape.numNodes;
  for(const adaptiveElement *e : w.visible) {
    for(int i = 0; i < numNodes; i++) {
      _evaluate(w, e->p[i]);
      _locate(w, e->p[i]);
    }
    for(int k = 0; k < 3; k++)
      for(int i = 0; i < numNodes; i++)
        out.push_back(w.xyz[3 * e->p[i]->index + k]);
    for(int i = 0; i < numNodes; i++)
      for(int c = 0; c < numComp; c++)
        out.push_back(w.values[e->p[i]->index * numComp + c]);
    if(outSkin) {
      // a face is on the skin if it lies on a face of the element that is
      unsigned char mask = 0;
      for(int f = 0; f < 6; f++)
        if(e->onFace[f] >= 0 && (onSkin & (1 << e->onFace[f])))
          mask |= (unsigned char)(1 << f);
      outSkin->push_back(mask);
    }
  }
  return (int)w.visible.size();
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

// the element of a view as adapt() takes it: the x, then the y, then the z of
// its nodes, and its values a component after the other
static void readElement(PViewData *in, int step, int ent, int ele, int numComp,
                        std::vector<double> &xyz, std::vector<double> &values)
{
  int numNodes = in->getNumNodes(step, ent, ele);
  xyz.resize(3 * numNodes);
  for(int i = 0; i < numNodes; i++)
    in->getNode(step, ent, ele, i, xyz[i], xyz[numNodes + i],
                xyz[2 * numNodes + i]);
  int numVals = in->getNumValues(step, ent, ele) / numComp;
  values.resize(numVals * numComp);
  for(int i = 0; i < numVals; i++)
    for(int c = 0; c < numComp; c++)
      in->getValue(step, ent, ele, numComp * i + c, values[c * numVals + i]);
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
  bool polytopes = (type == TYPE_POLYG || type == TYPE_POLYH);
  int *outNb = nullptr;
  std::vector<double> *outList = nullptr;
  getList(out, _shape.type, numComp, outNb, outList);
  if(!outList) return;
  bool clear = !polytopes || !((type == TYPE_POLYG) ? in->getNumTriangles() :
                                                      in->getNumTetrahedra());
  if(clear) {
    outList->clear();
    *outNb = 0;
  }

  std::vector<std::pair<int, int> > elements;
  for(int ent = 0; ent < in->getNumEntities(step); ent++)
    for(int ele = 0; ele < in->getNumElements(step, ent); ele++)
      if(!in->skipElement(step, ent, ele) &&
         in->getType(step, ent, ele) == type)
        elements.push_back({ent, ele});
  if(elements.empty()) return;

  double range = in->getMax() - in->getMin(); // (of all the steps)

  // The elements are cut in chunks, which the threads take as they are free,
  // each with a workspace of its own (the tree is only read), into a list of
  // its own: put together in their order, the chunks give what a single
  // thread would. The work of an element varies a lot with the refinement:
  // chunks many times more than the threads keep them all busy. A plugin
  // changes the tree, and some views cannot be read by several threads.
  int nthreads = CTX::instance()->numThreadsFor(elements.size(), 16);
  if(plug || polytopes || !in->isThreadSafe()) nthreads = 1;
  std::size_t numChunks =
    (nthreads == 1) ? 1 : std::min<std::size_t>(elements.size(), 32 * nthreads);
  std::vector<std::vector<double> > lists(numChunks);
  std::vector<std::vector<unsigned char> > skins(numChunks);
  std::vector<std::size_t> num(numChunks, 0);
  bool skin = (inSkin && outSkin && !polytopes);

  // All the last elements of the tree are kept if the target error is
  // negative: how much each chunk adds is known, which saves growing the
  // lists (a level or two down, the refined view is what takes the memory).
  auto first = [&](std::size_t c) { return elements.size() * c / numChunks; };
  std::size_t each = 0;
  if(tol < 0. && !plug && !polytopes)
    each = _leaves.size() * _shape.numNodes * (3 + numComp);

#pragma omp parallel num_threads(nthreads)
  {
    adaptiveWork work;
    std::vector<double> xyz, values;
#pragma omp for schedule(dynamic, 1)
    for(std::size_t c = 0; c < numChunks; c++) {
      if(each) lists[c].reserve((first(c + 1) - first(c)) * each);
      for(std::size_t i = first(c); i < first(c + 1); i++) {
        int ent = elements[i].first, ele = elements[i].second;
        if(polytopes) {
          num[c] += _addPolytope(level, step, in, ent, ele, numComp, lists[c]);
          continue;
        }
        readElement(in, step, ent, ele, numComp, xyz, values);
        if((int)xyz.size() != 3 * _numNodes ||
           (int)values.size() != numComp * _numVals) {
          Msg::Warning("Wrong number of nodes or values in adaptation");
          continue;
        }
        num[c] += adapt(work, tol, numComp, &xyz[0], &values[0], range, plug,
                        skin ? (*inSkin)[ent][ele] : 0, lists[c],
                        skin ? &skins[c] : nullptr);
      }
    }
  }

  double total = *outNb;
  for(std::size_t c = 0; c < numChunks; c++) total += num[c];
  if(total > 2147483647.) {
    Msg::Error("Too many elements in adaptive view: lower the recursion level "
               "or raise the target error");
    return;
  }
  // the chunks one after the other, copied by the threads
  std::vector<std::size_t> at(numChunks + 1, outList->size());
  for(std::size_t c = 0; c < numChunks; c++) {
    at[c + 1] = at[c] + lists[c].size();
    *outNb += (int)num[c];
    if(skin) outSkin->insert(outSkin->end(), skins[c].begin(), skins[c].end());
  }
  if(numChunks == 1 && outList->empty())
    outList->swap(lists[0]);
  else {
    outList->resize(at[numChunks]);
#pragma omp parallel for schedule(dynamic, 1) num_threads(nthreads)
    for(std::size_t c = 0; c < numChunks; c++) {
      std::copy(lists[c].begin(), lists[c].end(), outList->begin() + at[c]);
      std::vector<double>().swap(lists[c]);
    }
  }
  // (the elements of a view without skin still have their place in it)
  if(outSkin && !skin) outSkin->resize(outSkin->size() + (std::size_t)total, 0);
}

// a polygon or a polyhedron, refined through its triangles or tetrahedra:
// added to the list, as adapt() adds the elements it keeps
int adaptiveElements::_addPolytope(int level, int step, PViewData *in, int ent,
                                   int ele, int numComp,
                                   std::vector<double> &list)
{
  int numNodes = in->getNumNodes(step, ent, ele);
  std::vector<PCoords> coords;
  for(int i = 0; i < numNodes; i++) {
    double x, y, z;
    in->getNode(step, ent, ele, i, x, y, z);
    coords.push_back(PCoords(x, y, z));
  }
  std::vector<PValues> values;
  for(int i = 0; i < in->getNumValues(step, ent, ele) / numComp; i++) {
    values.push_back(PValues(numComp));
    for(int c = 0; c < numComp; c++)
      in->getValue(step, ent, ele, numComp * i + c, values.back().v[c]);
  }
  if(!adaptPolytope(level, numComp, in->getElement(step, ent, ele), numNodes,
                    coords, values))
    return 0;
  for(std::size_t i = 0; i < coords.size() / numNodes; i++) {
    for(int k = 0; k < 3; k++)
      for(int n = 0; n < numNodes; n++)
        list.push_back(coords[numNodes * i + n].c[k]);
    for(int n = 0; n < numNodes; n++)
      for(int c = 0; c < numComp; c++)
        list.push_back(values[numNodes * i + n].v[c]);
  }
  return (int)(coords.size() / numNodes);
}


adaptiveData::adaptiveData(PViewData *data, bool outDataInit)
  : _step(-1), _level(-1), _tol(-1.), _inData(data), _points(nullptr),
    _lines(nullptr), _triangles(nullptr), _quadrangles(nullptr),
    _tetrahedra(nullptr), _hexahedra(nullptr), _prisms(nullptr),
    _pyramids(nullptr), _polygons(nullptr), _polyhedra(nullptr)
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

// The export of adapted views to VTK files, and the VTK data structure built
// for ParaView's GmshReader plugin (globalVTKData). The view is refined an
// element at a time, and written a piece (a .vtu file) at a time, so that the
// memory that is needed is the one of a piece: with enough pieces, views of
// any size can be refined to any level.

class adaptiveVTKWriter {
private:
  std::string _path, _name; // of the files, without extension
  bool _binary;
  std::size_t _numPieces, _numElements, _element;
  vtkXMLGrid _grid;
  std::vector<std::string> _pieces;
  bool _ok;
  std::size_t _pieceOf(std::size_t element) const
  {
    return (_numElements && _numPieces) ? element * _numPieces / _numElements : 0;
  }
  void _flush()
  {
    if(_grid.types.empty()) return;
    std::string name = _name + ".vtu";
    if(_numPieces)
      name = _name + "_" + std::to_string(_pieces.size() + 1) + ".vtu";
    if(!_grid.write(_path + name, _binary, "Created by Gmsh")) _ok = false;
    _pieces.push_back(name);
    _grid.points.clear();
    _grid.connectivity.clear();
    _grid.offsets.clear();
    _grid.types.clear();
    _grid.pointData[0].data.clear();
  }

public:
  // the file name without its extension; the elements of the view are shared
  // between the pieces (0: a single .vtu file and no .pvtu)
  adaptiveVTKWriter(const std::string &path, const std::string &name,
                    bool binary, int numPieces,
                    std::size_t numElements, const std::string &fieldName,
                    int numComp)
    : _path(path), _name(name), _binary(binary),
      _numPieces(std::max(numPieces, 0)),
      _numElements(numElements), _element(0), _ok(true)
  {
    vtkXMLGrid::realArray a;
    a.name = fieldName;
    a.numComp = numComp;
    _grid.pointData.push_back(a);
  }
  std::size_t numPoints() const { return _grid.points.size() / 3; }
  void addPoint(const PCoords &x, const PValues &v)
  {
    for(int k = 0; k < 3; k++) _grid.points.push_back(x.c[k]);
    for(int k = 0; k < v.sizev; k++) _grid.pointData[0].data.push_back(v.v[k]);
  }
  void addCell(int vtkType, const std::vector<int> &pointsInPiece)
  {
    for(int n : pointsInPiece) _grid.connectivity.push_back(n);
    _grid.offsets.push_back(_grid.connectivity.size());
    _grid.types.push_back((std::uint8_t)vtkType);
  }
  // an element of the view has been refined
  void endElement()
  {
    _element++;
    if(_pieceOf(_element) != _pieceOf(_element - 1)) _flush();
  }
  bool finish()
  {
    _flush();
    if(_pieces.empty()) {
      Msg::Warning("No element to write in '%s%s'", _path.c_str(),
                   _name.c_str());
      return false;
    }
    if(_numPieces &&
       !_grid.writeParallel(_path + _name + ".pvtu", _pieces,
                            "Created by Gmsh"))
      _ok = false;
    return _ok;
  }
};

// the VTK cell of the (first order) refined elements
static int vtkCellType(int type)
{
  switch(type) {
  case TYPE_TRI: return 5;
  case TYPE_QUA: return 9;
  case TYPE_TET: return 10;
  case TYPE_HEX: return 12;
  case TYPE_PRI: return 13;
  case TYPE_PYR: return 14;
  default: return 0;
  }
}

void adaptiveElements::buildMapping(const adaptiveWork &w, nodMap &myNodMap,
                                    double tol, int &numNodInsert)
{
  // Either this is not a uniform refinement and the mapping has to be rebuilt
  // for each element, or this is the first time
  if(!(tol > 0.0 || myNodMap.getSize() == 0)) return;
  myNodMap.cleanMapping();

  // the vertices of the elements that are kept, by their index in the tree
  for(const adaptiveElement *leaf : w.visible)
    for(int i = 0; i < _shape.numNodes; i++)
      myNodMap.mapping.push_back(leaf->p[i]->index);
  if(myNodMap.mapping.size() == 0)
    Msg::Error("Node mapping in buildMapping has zero size");

  // numbered from 0 without holes
  std::map<int, int> renumbered;
  for(int n : myNodMap.mapping) renumbered[n] = 0;
  numNodInsert = 0;
  for(auto &r : renumbered) r.second = numNodInsert++;
  for(auto &n : myNodMap.mapping) n = renumbered[n];
}

// Refine the elements of this kind: into the writer if there is one, and into
// globalVTKData if asked to. The points are shared between the refined
// elements of an element of the view, but not further; numPoints counts the
// ones made so far, which number those of globalVTKData.
void adaptiveElements::addInViewForVTK(int step, double tol, PViewData *in,
                                       adaptiveVTKWriter *writer,
                                       bool buildStaticData, int &numPoints)
{
  int numComp = in->getNumComponents(0, 0, 0);
  if(numComp != 1 && numComp != 3 && numComp != 9) return;

  int numNodInsert = 0, numNodes = _shape.numNodes;
  nodMap myNodMap;
  adaptiveWork work;
  std::vector<double> xyz, values, list;
  double range = in->getMax() - in->getMin(); // (of all the steps)

  for(int ent = 0; ent < in->getNumEntities(step); ent++) {
    for(int ele = 0; ele < in->getNumElements(step, ent); ele++) {
      if(in->skipElement(step, ent, ele) ||
         in->getNumEdges(step, ent, ele) != _shape.numEdges)
        continue;
      readElement(in, step, ent, ele, numComp, xyz, values);
      if((int)xyz.size() != 3 * _numNodes ||
         (int)values.size() != numComp * _numVals)
        continue;
      list.clear();
      int num = adapt(work, tol, numComp, &xyz[0], &values[0], range, nullptr,
                      0, list, nullptr);
      if(!num) continue;

      // the points of the refined elements, numbered in the element
      buildMapping(work, myNodMap, tol, numNodInsert);
      std::vector<PCoords> points(numNodInsert, PCoords(0., 0., 0.));
      std::vector<PValues> pointValues(numNodInsert, PValues(numComp));
      int stride = numNodes * (3 + numComp);
      for(int i = 0; i < num; i++) {
        const double *e = &list[i * stride];
        for(int k = 0; k < numNodes; k++) {
          int n = myNodMap.mapping[numNodes * i + k];
          points[n] = PCoords(e[k], e[numNodes + k], e[2 * numNodes + k]);
          for(int c = 0; c < numComp; c++)
            pointValues[n].v[c] = e[3 * numNodes + numComp * k + c];
        }
      }

      int firstInPiece = writer ? (int)writer->numPoints() : 0;
      for(int i = 0; i < num; i++) {
        vectInt inPiece, inAll;
        for(int k = 0; k < numNodes; k++) {
          int n = myNodMap.mapping[numNodes * i + k];
          inPiece.push_back(firstInPiece + n);
          inAll.push_back(numPoints + n);
        }
        if(writer) writer->addCell(vtkCellType(_shape.type), inPiece);
        if(buildStaticData) {
          globalVTKData::vtkGlobalConnectivity.push_back(inAll);
          globalVTKData::vtkGlobalCellType.push_back(vtkCellType(_shape.type));
        }
      }
      for(int i = 0; i < numNodInsert; i++) {
        if(writer) writer->addPoint(points[i], pointValues[i]);
        if(buildStaticData) {
          globalVTKData::vtkGlobalCoords.push_back(points[i]);
          globalVTKData::vtkGlobalValues.push_back(pointValues[i]);
        }
      }
      numPoints += numNodInsert;
      if(writer) writer->endElement();
    }
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

  // the files: name.pvtu and name_1.vtu, name_2.vtu, ..., with the name given
  // or made from the view and the parameters
  adaptiveVTKWriter *writer = nullptr;
  if(writeVTK) {
    std::vector<std::string> split = SplitFileName(guiFileName);
    std::string name = split[1];
    if(useDefaultName) {
      std::string view = _inData->getName();
      for(auto &c : view)
        if(!isalnum((unsigned char)c) && c != '-' && c != '.') c = '_';
      std::ostringstream os;
      os << view << "_step" << step << "_level" << level << "_tol" << tol
         << "_npart" << npart;
      name = os.str();
    }
    // (npart <= 0: as many pieces as it takes for a piece to stay under two
    // million cells if every element is refined down to the level)
    std::size_t numElements = countTotElmLev0(step, _inData);
    if(npart <= 0) npart = (int)(numElements * pow(8., level) / 2.e6) + 1;
    bool single = (npart == 1 && split[2] != ".pvtu");
    writer = new adaptiveVTKWriter(split[0], name, isBinary,
                                   single ? 0 : npart,
                                   numElements,
                                   _inData->getName(),
                                   _inData->getNumComponents(0, 0, 0));
  }

  // Views of 2D and 3D elements only supported for VTK. _points and _lines are
  // currently ignored.
  int numPoints = 0;
  for(auto e : {_triangles, _quadrangles, _tetrahedra, _prisms, _hexahedra,
                _pyramids}) {
    if(!e) continue;
    e->init(level);
    e->addInViewForVTK(step, tol, _inData, writer, buildStaticData, numPoints);
  }
  // (the trees no longer are the ones of the adapted view, if there is one)
  _level = -1;

  if(writer) {
    if(writer->finish()) Msg::StatusBar(true, "Done writing VTK data");
    delete writer;
  }
}
