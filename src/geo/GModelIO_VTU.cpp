// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <array>
#include <cmath>
#include <map>
#include "GModel.h"
#include "OS.h"
#include "MElement.h"
#include "MPolygon.h"
#include "MPolyhedron.h"
#include "ElementType.h"
#include "BasisFactory.h"
#include "nodalBasis.h"
#include "VTKXML.h"
#include "GmshVersion.h"
#include "GmshConfig.h"

#if defined(HAVE_POST)
#include "PViewDataGModel.h"
#endif

// The nodes of the VTK Lagrange cells of order p, in the order VTK wants them,
// as integer coordinates in [0, p]: the corners, the inside of the edges, of
// the faces, of the volume. (Checked against vtkLagrange*::InterpolateFunctions
// of VTK 9.7 up to order 5.)

typedef std::array<int, 3> ijk;

static ijk combine(const std::vector<ijk> &v, const std::vector<int> &w, int p)
{
  ijk r = {0, 0, 0};
  for(std::size_t n = 0; n < v.size(); n++)
    for(int d = 0; d < 3; d++) r[d] += w[n] * v[n][d];
  for(int d = 0; d < 3; d++) r[d] /= p;
  return r;
}

static void edgeLattice(const ijk &a, const ijk &b, int p, std::vector<ijk> &out)
{
  for(int t = 1; t < p; t++)
    out.push_back({a[0] + (b[0] - a[0]) * t / p, a[1] + (b[1] - a[1]) * t / p,
                   a[2] + (b[2] - a[2]) * t / p});
}

static void edgesLattice(const std::vector<ijk> &v,
                         const std::vector<std::array<int, 2> > &edges, int p,
                         std::vector<ijk> &out)
{
  for(auto &e : edges) edgeLattice(v[e[0]], v[e[1]], p, out);
}

// the inside of a triangle is ordered as a triangle of order p - 3
static void triLattice(const std::vector<ijk> &v, int p, std::vector<ijk> &out)
{
  if(p == 0) {
    out.push_back(v[0]);
    return;
  }
  out.insert(out.end(), v.begin(), v.end());
  edgesLattice(v, {{0, 1}, {1, 2}, {2, 0}}, p, out);
  if(p < 3) return;
  std::vector<ijk> in = {combine(v, {p - 2, 1, 1}, p),
                         combine(v, {1, p - 2, 1}, p),
                         combine(v, {1, 1, p - 2}, p)};
  triLattice(in, p - 3, out);
}

static void tetLattice(const std::vector<ijk> &v, int p, std::vector<ijk> &out)
{
  if(p == 0) {
    out.push_back(v[0]);
    return;
  }
  out.insert(out.end(), v.begin(), v.end());
  edgesLattice(v, {{0, 1}, {1, 2}, {2, 0}, {0, 3}, {1, 3}, {2, 3}}, p, out);
  if(p < 3) return;
  static const int faces[4][3] = {{0, 1, 3}, {2, 3, 1}, {0, 3, 2}, {0, 2, 1}};
  for(int f = 0; f < 4; f++) {
    std::vector<ijk> in;
    for(int m = 0; m < 3; m++) {
      std::vector<int> w(4, 0);
      for(int q = 0; q < 3; q++) w[faces[f][q]] = (q == m) ? p - 2 : 1;
      in.push_back(combine(v, w, p));
    }
    triLattice(in, p - 3, out);
  }
  if(p < 4) return;
  std::vector<ijk> in;
  for(int m = 0; m < 4; m++) {
    std::vector<int> w(4, 1);
    w[m] = p - 3;
    in.push_back(combine(v, w, p));
  }
  tetLattice(in, p - 4, out);
}

static std::vector<ijk> vtkLattice(int parentType, int p)
{
  std::vector<ijk> out, v;
  switch(parentType) {
  case TYPE_LIN:
    v = {{0, 0, 0}, {p, 0, 0}};
    out = v;
    edgeLattice(v[0], v[1], p, out);
    break;
  case TYPE_TRI: triLattice({{0, 0, 0}, {p, 0, 0}, {0, p, 0}}, p, out); break;
  case TYPE_TET:
    tetLattice({{0, 0, 0}, {p, 0, 0}, {0, p, 0}, {0, 0, p}}, p, out);
    break;
  case TYPE_QUA:
    // the edges of tensor cells run along increasing coordinates, and their
    // faces and volume are ordered lexicographically
    v = {{0, 0, 0}, {p, 0, 0}, {p, p, 0}, {0, p, 0}};
    out = v;
    edgesLattice(v, {{0, 1}, {1, 2}, {3, 2}, {0, 3}}, p, out);
    for(int j = 1; j < p; j++)
      for(int i = 1; i < p; i++) out.push_back({i, j, 0});
    break;
  case TYPE_HEX:
    v = {{0, 0, 0}, {p, 0, 0}, {p, p, 0}, {0, p, 0},
         {0, 0, p}, {p, 0, p}, {p, p, p}, {0, p, p}};
    out = v;
    edgesLattice(v,
                 {{0, 1}, {1, 2}, {3, 2}, {0, 3}, {4, 5}, {5, 6}, {7, 6},
                  {4, 7}, {0, 4}, {1, 5}, {2, 6}, {3, 7}}, p, out);
    for(int x = 0; x <= p; x += p)
      for(int k = 1; k < p; k++)
        for(int j = 1; j < p; j++) out.push_back({x, j, k});
    for(int y = 0; y <= p; y += p)
      for(int k = 1; k < p; k++)
        for(int i = 1; i < p; i++) out.push_back({i, y, k});
    for(int z = 0; z <= p; z += p)
      for(int j = 1; j < p; j++)
        for(int i = 1; i < p; i++) out.push_back({i, j, z});
    for(int k = 1; k < p; k++)
      for(int j = 1; j < p; j++)
        for(int i = 1; i < p; i++) out.push_back({i, j, k});
    break;
  case TYPE_PRI: {
    // unlike in the triangle, the inside of the triangular faces and
    // sections is ordered lexicographically
    v = {{0, 0, 0}, {p, 0, 0}, {0, p, 0}, {0, 0, p}, {p, 0, p}, {0, p, p}};
    out = v;
    edgesLattice(v,
                 {{0, 1}, {1, 2}, {2, 0}, {3, 4}, {4, 5}, {5, 3}, {0, 3},
                  {1, 4}, {2, 5}}, p, out);
    auto inside = [&](int z) {
      for(int j = 1; j < p; j++)
        for(int i = 1; i < p - j; i++) out.push_back({i, j, z});
    };
    inside(0);
    inside(p);
    for(int f = 0; f < 3; f++) {
      std::vector<ijk> e;
      edgeLattice(v[f], v[(f + 1) % 3], p, e);
      for(int k = 1; k < p; k++)
        for(auto &n : e) out.push_back({n[0], n[1], k});
    }
    for(int k = 1; k < p; k++) inside(k);
  } break;
  }
  return out;
}

static vtkXMLCell makeVTKCell(int mshType)
{
  static const int linear[] = {0, 1, 3, 5, 9, 10, 14, 13, 12};
  static const int quadratic[] = {0, 0, 21, 22, 28, 24, 0, 32, 29};
  static const int serendipity[] = {0, 0, 0, 0, 23, 0, 27, 26, 25};
  static const int lagrange[] = {0, 0, 68, 69, 70, 71, 0, 73, 72};

  vtkXMLCell c;
  int parent = ElementType::getParentType(mshType);
  if(parent < TYPE_PNT || parent > TYPE_HEX) {
    c.type = 0;
    return c;
  }
  int p = ElementType::getOrder(mshType);
  bool serendip = (ElementType::getSerendipity(mshType) > 1);
  int numNodes = ElementType::getNumVertices(mshType);

  if(parent == TYPE_PYR && p == 2 && serendip) {
    c.type = serendipity[parent];
    c.nodes = {0, 1, 2, 3, 4, 5, 8, 10, 6, 7, 9, 11, 12};
    return c;
  }

  if(p <= 1)
    c.type = linear[parent];
  else if(p == 2)
    c.type = serendip ? serendipity[parent] : quadratic[parent];
  else
    c.type = serendip ? 0 : lagrange[parent];

  if(p > 1 && c.type && parent != TYPE_PYR) {
    // match the VTK nodes with the reference nodes of the element; a
    // serendipity cell has the corners and edges of the complete one
    std::vector<ijk> lattice = vtkLattice(parent, p);
    lattice.resize(numNodes);
    const nodalBasis *basis = BasisFactory::getNodalBasis(mshType);
    std::map<ijk, int> index;
    if(basis && basis->getReferenceNodes().size1() == numNodes) {
      const fullMatrix<double> &ref = basis->getReferenceNodes();
      for(int n = 0; n < numNodes; n++) {
        ijk r = {0, 0, 0};
        for(int d = 0; d < ref.size2() && d < 3; d++) {
          // simplices (and the triangle of prisms) live in [0, 1]
          bool unit = (parent == TYPE_TRI || parent == TYPE_TET ||
                       (parent == TYPE_PRI && d < 2));
          double u = unit ? ref(n, d) : 0.5 * (ref(n, d) + 1.);
          r[d] = (int)std::lround(u * p);
        }
        index[r] = n;
      }
    }
    for(auto &r : lattice) {
      auto it = index.find(r);
      if(it == index.end()) break;
      c.nodes.push_back(it->second);
    }
    if((int)c.nodes.size() != numNodes) c.type = 0;
  }

  if(p > 1 && (!c.type || parent == TYPE_PYR)) {
    c.type = linear[parent];
    c.nodes.clear();
  }
  if(c.nodes.empty()) {
    int n = ElementType::getNumVertices(ElementType::getPrimaryType(mshType));
    for(int i = 0; i < n; i++) c.nodes.push_back(i);
  }
  return c;
}

const vtkXMLCell &getVTKXMLCell(int mshType)
{
  static std::map<int, vtkXMLCell> cells;
  auto it = cells.find(mshType);
  if(it == cells.end()) {
    vtkXMLCell c = makeVTKCell(mshType);
    if(c.type && ElementType::getOrder(mshType) > 1 &&
       c.nodes.size() < (std::size_t)ElementType::getNumVertices(mshType))
      Msg::Warning("No VTK equivalent for %s: written as first order cells",
                   ElementType::nameOfParentType(
                     ElementType::getParentType(mshType), true).c_str());
    it = cells.insert(std::make_pair(mshType, c)).first;
  }
  return it->second;
}

// The cells of an element, with a point per node of the mesh, or per node of
// each element if the grid is to carry discontinuous data

struct vtuPoint {
  MVertex *vertex;
  MElement *element;
  int node; // in the element
};

static void addVTUCell(MElement *e, bool discontinuous, vtkXMLGrid &grid,
                       std::vector<vtuPoint> &points)
{
  auto index = [&](int k) {
    MVertex *v = e->getVertex(k);
    if(discontinuous || v->getIndex() < 0) {
      points.push_back({v, e, k});
      v->setIndex(points.size());
    }
    return (std::int64_t)v->getIndex() - 1;
  };

  if(e->getType() == TYPE_POLYG) {
    int n = e->getNumEdges(); // the boundary nodes come first
    for(int k = 0; k < n; k++) grid.connectivity.push_back(index(k));
    grid.types.push_back(7);
    grid.faceOffsets.push_back(-1);
  }
  else if(e->getType() == TYPE_POLYH) {
    int n = e->getNumVertices() - e->getNumVolumeVertices();
    std::map<MVertex *, std::int64_t> local;
    for(int k = 0; k < n; k++) {
      grid.connectivity.push_back(index(k));
      local[e->getVertex(k)] = grid.connectivity.back();
    }
    grid.types.push_back(42);
    grid.faces.push_back(e->getNumFaces());
    std::vector<MVertex *> fv;
    for(int f = 0; f < e->getNumFaces(); f++) {
      e->getFaceVertices(f, fv);
      grid.faces.push_back(fv.size());
      for(auto v : fv) grid.faces.push_back(local[v]);
    }
    grid.faceOffsets.push_back(grid.faces.size());
  }
  else {
    const vtkXMLCell &c = getVTKXMLCell(e->getTypeForMSH());
    for(auto k : c.nodes) grid.connectivity.push_back(index(k));
    grid.types.push_back(c.type);
    grid.faceOffsets.push_back(-1);
  }
  grid.offsets.push_back(grid.connectivity.size());
}

static bool hasVTUCell(MElement *e)
{
  return e->getType() == TYPE_POLYG || e->getType() == TYPE_POLYH ||
         getVTKXMLCell(e->getTypeForMSH()).type;
}

#if defined(HAVE_POST)

// a view with a single step is static: it goes with every step of the others
static stepData<double> *getStep(PViewDataGModel *view, int step)
{
  if(view->getNumTimeSteps() == 1) step = 0;
  return view->hasTimeStep(step) ? view->getStepData(step) : nullptr;
}

static bool hasData(MElement *e, const std::vector<PViewDataGModel *> &views,
                    int step)
{
  for(auto view : views) {
    stepData<double> *s = getStep(view, step);
    if(!s) continue;
    if(view->getType() == PViewDataGModel::NodeData) {
      bool all = true;
      for(std::size_t k = 0; k < e->getNumPrimaryVertices() && all; k++)
        if(!s->getData(e->getVertex(k)->getNum())) all = false;
      if(all) return true;
    }
    else if(s->getData(e->getNum()))
      return true;
  }
  return false;
}

static void addVTUData(PViewDataGModel *view, int step,
                       const std::vector<vtuPoint> &points,
                       const std::vector<MElement *> &elements,
                       vtkXMLGrid &grid)
{
  stepData<double> *s = getStep(view, step);
  if(!s) return;
  int numComp = s->getNumComponents();
  const double nan = std::nan("");
  vtkXMLGrid::realArray a;
  a.name = grid.uniqueName(view->getName());
  a.numComp = numComp;

  switch(view->getType()) {
  case PViewDataGModel::NodeData:
    a.data.reserve(numComp * points.size());
    for(auto &p : points) {
      double *d = s->getData(p.vertex->getNum());
      for(int c = 0; c < numComp; c++) a.data.push_back(d ? d[c] : nan);
    }
    grid.pointData.push_back(a);
    break;
  case PViewDataGModel::ElementNodeData:
    a.data.reserve(numComp * points.size());
    for(auto &p : points) {
      double *d = s->getData(p.element->getNum());
      if(d && p.node >= s->getMult(p.element->getNum())) d = nullptr;
      for(int c = 0; c < numComp; c++)
        a.data.push_back(d ? d[numComp * p.node + c] : nan);
    }
    grid.pointData.push_back(a);
    break;
  case PViewDataGModel::ElementData:
    a.data.reserve(numComp * elements.size());
    for(auto e : elements) {
      double *d = s->getData(e->getNum());
      for(int c = 0; c < numComp; c++) a.data.push_back(d ? d[c] : nan);
    }
    grid.cellData.push_back(a);
    break;
  default:
    Msg::Warning("View '%s' not exported: only node, element and element-node "
                 "data can be", view->getName().c_str());
    break;
  }
}

#endif

// With views, the cells are the elements of highest dimension that have data

int GModel::writeVTU(const std::string &name, bool binary, bool saveAll,
                     double scalingFactor,
                     const std::vector<PViewDataGModel *> &views, int step)
{
  if(noPhysicalGroups()) saveAll = true;

  std::vector<GEntity *> entities;
  getEntities(entities);

  bool discontinuous = false;
  int dim = -1;
#if defined(HAVE_POST)
  for(auto view : views) {
    if(getStep(view, step) &&
       view->getType() == PViewDataGModel::ElementNodeData)
      discontinuous = true;
  }
  if(views.size()) {
    for(auto ge : entities) {
      if(ge->dim() <= dim) continue;
      for(std::size_t j = 0; j < ge->getNumMeshElements(); j++) {
        if(hasData(ge->getMeshElement(j), views, step)) {
          dim = ge->dim();
          break;
        }
      }
    }
  }
#endif

  vtkXMLGrid grid;
  std::vector<vtuPoint> points;
  std::vector<MElement *> elements;
  grid.cellTags.resize(getNumPartitions() ? 4 : 3);
  grid.cellTags[0].name = "gmsh:physical"; // the two names meshio uses
  grid.cellTags[1].name = "gmsh:geometrical";
  grid.cellTags[2].name = "gmsh:dim"; // entity tags are per dimension
  if(getNumPartitions()) grid.cellTags[3].name = "gmsh:partition";

  for(auto ge : entities)
    for(auto v : ge->mesh_vertices) v->setIndex(-1);

  for(auto ge : entities) {
    if(views.empty() ? (ge->physicals.empty() && !saveAll) : (ge->dim() != dim))
      continue;
    for(std::size_t j = 0; j < ge->getNumMeshElements(); j++) {
      MElement *e = ge->getMeshElement(j);
      if(!hasVTUCell(e)) continue;
#if defined(HAVE_POST)
      if(views.size() && !hasData(e, views, step)) continue;
#endif
      addVTUCell(e, discontinuous, grid, points);
      elements.push_back(e);
      grid.cellTags[0].data.push_back(
        ge->physicals.empty() ? 0 : ge->physicals[0]);
      grid.cellTags[1].data.push_back(ge->tag());
      grid.cellTags[2].data.push_back(ge->dim());
      if(getNumPartitions()) grid.cellTags[3].data.push_back(e->getPartition());
    }
  }

  grid.points.reserve(3 * points.size());
  for(auto &p : points) {
    grid.points.push_back(p.vertex->x() * scalingFactor);
    grid.points.push_back(p.vertex->y() * scalingFactor);
    grid.points.push_back(p.vertex->z() * scalingFactor);
  }

#if defined(HAVE_POST)
  for(auto view : views) addVTUData(view, step, points, elements, grid);
#endif

  return grid.write(name, binary,
                    getName() + ", created by Gmsh " + GMSH_VERSION) ? 1 : 0;
}
