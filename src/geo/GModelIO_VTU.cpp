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
#include "MLine.h"
#include "MPoint.h"
#include "MTriangle.h"
#include "StringUtils.h"
#include "ElementType.h"
#include "BasisFactory.h"
#include "nodalBasis.h"
#include "VTKXML.h"
#include "GmshVersion.h"
#include "GmshConfig.h"

#if defined(HAVE_POST)
#include "PView.h"
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

const vtkXMLCell &getVTKXMLCell(int mshType, bool warn)
{
  static std::map<int, vtkXMLCell> cells;
  static std::map<int, bool> warned;
  auto it = cells.find(mshType);
  if(it == cells.end())
    it = cells.insert(std::make_pair(mshType, makeVTKCell(mshType))).first;
  const vtkXMLCell &c = it->second;
  if(warn && c.type && !warned[mshType] &&
     c.nodes.size() < (std::size_t)ElementType::getNumVertices(mshType)) {
    warned[mshType] = true;
    Msg::Warning("No VTK equivalent for %s of order %d: written as first "
                 "order cells",
                 ElementType::nameOfParentType(
                   ElementType::getParentType(mshType), true).c_str(),
                 ElementType::getOrder(mshType));
  }
  return c;
}

int getMSHTypeOfVTKXMLCell(int vtkType, int numNodes)
{
  static std::map<std::pair<int, int>, int> types;
  if(types.empty()) {
    for(int parent = TYPE_PNT; parent <= TYPE_HEX; parent++) {
      for(int order = 0; order <= 10; order++) {
        for(int serendip = 0; serendip < 2; serendip++) {
          if((order == 0) != (parent == TYPE_PNT)) continue;
          if(parent == TYPE_PYR && order > 2) continue; // no VTK equivalent
          if(parent == TYPE_PRI && order > 2) continue; // not in Gmsh
          if(parent == TYPE_HEX && order > 9) continue;
          if(serendip && (order != 2 || parent < TYPE_QUA)) continue;
          int t = ElementType::getType(parent, order, serendip);
          if(t <= 0) continue;
          const vtkXMLCell &c = getVTKXMLCell(t, false);
          int n = ElementType::getNumVertices(t);
          if(!c.type || (int)c.nodes.size() != n) continue;
          if(!types.count({c.type, n})) types[{c.type, n}] = t;
          // VTK can also write the cells of order 1 and 2 as Lagrange
          // cells, which order their nodes in the same way
          static const int lagrange[] = {0, 0, 68, 69, 70, 71, 0, 73, 72};
          int l = serendip ? 0 : lagrange[parent];
          if(l && !types.count({l, n})) types[{l, n}] = t;
        }
      }
    }
  }
  auto it = types.find({vtkType, numNodes});
  return it == types.end() ? 0 : it->second;
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

  // a .pvtu is made of a .vtu per partition; the copies of a node in several
  // of them are told by their number
  std::vector<std::string> split = SplitFileName(name);
  bool parallel = (split[2] == ".pvtu" || split[2] == ".PVTU");
  std::size_t numPieces = parallel ? std::max<std::size_t>(getNumPartitions(), 1) : 1;
  if(parallel && !getNumPartitions())
    Msg::Warning("The mesh is not partitioned: '%s' will have a single piece",
                 name.c_str());
  std::vector<std::string> pieces;
  std::string comment = getName() + ", created by Gmsh " + GMSH_VERSION;
  bool ok = true;

  for(std::size_t piece = 1; piece <= numPieces; piece++) {
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
      if(views.empty() ? (ge->physicals.empty() && !saveAll) :
                         (ge->dim() != dim))
        continue;
      for(std::size_t j = 0; j < ge->getNumMeshElements(); j++) {
        MElement *e = ge->getMeshElement(j);
        if(!hasVTUCell(e)) continue;
        if(parallel && getNumPartitions() &&
           e->getPartition() != (int)piece)
          continue;
#if defined(HAVE_POST)
        if(views.size() && !hasData(e, views, step)) continue;
#endif
        addVTUCell(e, discontinuous, grid, points);
        elements.push_back(e);
        grid.cellTags[0].data.push_back(
          ge->physicals.empty() ? 0 : ge->physicals[0]);
        // (the entity a piece of a partitioned mesh was cut from)
        GEntity *parent = ge->getParentEntity();
        bool cut = (parent && parent->dim() == ge->dim());
        grid.cellTags[1].data.push_back(cut ? parent->tag() : ge->tag());
        grid.cellTags[2].data.push_back(ge->dim());
        if(getNumPartitions())
          grid.cellTags[3].data.push_back(e->getPartition());
      }
    }

    grid.points.reserve(3 * points.size());
    for(auto &p : points) {
      grid.points.push_back(p.vertex->x() * scalingFactor);
      grid.points.push_back(p.vertex->y() * scalingFactor);
      grid.points.push_back(p.vertex->z() * scalingFactor);
      if(parallel && !discontinuous)
        grid.globalNodeIds.push_back(p.vertex->getNum());
    }

#if defined(HAVE_POST)
    for(auto view : views) addVTUData(view, step, points, elements, grid);
#endif

    if(!parallel) return grid.write(name, binary, comment) ? 1 : 0;

    pieces.push_back(split[1] + "_" + std::to_string(piece) + ".vtu");
    if(!grid.write(split[0] + pieces.back(), binary, comment)) ok = false;
    if(piece == numPieces && !grid.writeParallel(name, pieces, comment))
      ok = false;
  }
  return ok ? 1 : 0;
}

// Reads a .vtu file, or the series of files of a .pvd: the mesh from the
// first step, and the data arrays of each step as steps of model-based views

int GModel::readVTU(const std::string &name)
{
  std::vector<std::vector<std::string> > files(1, {name});
  std::vector<double> times(1, 0.);
  std::vector<std::string> split = SplitFileName(name);
  if(split[2] == ".pvd" || split[2] == ".PVD") {
    if(!readPVD(name, files, times)) {
      Msg::Error("No data set in '%s'", name.c_str());
      return 0;
    }
    for(auto &f : files)
      for(auto &n : f)
        if(n.size() && n[0] != '/' && n.find(':') == std::string::npos)
          n = split[0] + n;
  }

  // the mesh of each part, kept to put the data of the next steps on as long
  // as it does not change: a step with another mesh has it in a model of its
  // own (hidden, as the models of the meshes merged with views)
  struct part {
    GModel *model = nullptr;
    std::vector<double> points;
    std::vector<std::int64_t> connectivity, offsets;
    std::vector<std::uint8_t> types;
    std::vector<MVertex *> vertices;
    std::vector<bool> copy; // of a point met before (in another piece)
    std::vector<std::pair<std::size_t, MElement *> > elements;
#if defined(HAVE_POST)
    std::map<std::string, PViewDataGModel *> views;
#endif
  };
  std::vector<part> parts;

  // the mesh of a grid in the model, current while it is made so that its
  // nodes and elements are numbered in it (the current model is then put
  // back: saved as a pointer, since a model added at the end of the list is
  // the current one if none was set)
  GModel *current = GModel::current();
  auto build = [&](GModel *model, const vtkXMLGrid &grid, part &p) -> bool {
    std::size_t numPoints = grid.points.size() / 3;
    std::size_t numCells = grid.types.size();
    GModel::setCurrent(model);
    p.model = model;
    p.points = grid.points;
    p.connectivity = grid.connectivity;
    p.offsets = grid.offsets;
    p.types = grid.types;
    p.vertices.clear();
    p.copy.clear();
    p.elements.clear();
    Msg::Info("%zu points, %zu cells", numPoints, numCells);

    auto array = [&](const std::string &n) -> const std::vector<double> * {
      for(auto &a : grid.cellData)
        if(a.name == n && a.numComp == 1 && a.data.size() == numCells)
          return &a.data;
      return nullptr;
    };
    const std::vector<double> *geometrical = array("gmsh:geometrical");
    const std::vector<double> *physical = array("gmsh:physical");
    if(!physical) physical = array("CellEntityIds"); // legacy .vtk

    // the points with the same global number, in the pieces of a
    // partitioned grid, are one node
    const std::vector<double> *ids = nullptr;
    for(auto &a : grid.pointData)
      if(a.name == "GlobalNodeIds" && a.numComp == 1 &&
         a.data.size() == numPoints)
        ids = &a.data;
    std::map<std::size_t, MVertex *> numbered;
    std::vector<MVertex *> unique;
    p.vertices.resize(numPoints);
    p.copy.resize(numPoints, false);
    for(std::size_t i = 0; i < numPoints; i++) {
      std::size_t num = (ids && (*ids)[i] > 0) ? (std::size_t)(*ids)[i] : 0;
      MVertex *&known = numbered[num];
      if(num && known) {
        p.vertices[i] = known;
        p.copy[i] = true;
        continue;
      }
      p.vertices[i] = new MVertex(grid.points[3 * i], grid.points[3 * i + 1],
                                  grid.points[3 * i + 2], nullptr, num);
      unique.push_back(p.vertices[i]);
      if(num) known = p.vertices[i];
    }

    std::map<int, std::vector<MElement *> > elements[16];
    std::map<int, std::map<int, std::string> > physicals[4];
    MElementFactory factory;
    std::map<int, int> unknown;

    for(std::size_t c = 0; c < numCells; c++) {
      std::int64_t start = c ? grid.offsets[c - 1] : 0;
      std::int64_t n = grid.offsets[c] - start;
      std::vector<MVertex *> v(n);
      bool ok = (n > 0);
      for(std::int64_t k = 0; k < n && ok; k++) {
        std::int64_t i = grid.connectivity[start + k];
        if(i < 0 || i >= (std::int64_t)numPoints)
          ok = false;
        else
          v[k] = p.vertices[i];
      }
      if(!ok) {
        Msg::Error("Wrong node index in cell %zu", c);
        GModel::setCurrent(current);
        return false;
      }
      int type = grid.types[c];
      std::vector<MElement *> created;
      switch(type) {
      case 2: // poly-vertex
        for(auto w : v) created.push_back(new MPoint(w));
        break;
      case 4: // poly-line
        for(std::int64_t k = 0; k + 1 < n; k++)
          created.push_back(new MLine(v[k], v[k + 1]));
        break;
      case 6: // triangle strip
        for(std::int64_t k = 0; k + 2 < n; k++)
          created.push_back((k % 2) ? new MTriangle(v[k + 1], v[k], v[k + 2]) :
                                      new MTriangle(v[k], v[k + 1], v[k + 2]));
        break;
      case 7: created.push_back(new MPolygon(v)); break;
      case 42: {
        MPolyhedron *ph = new MPolyhedron(v);
        std::vector<MVertex *> fv;
        std::vector<int> fo(1, 0);
        if(c < grid.faceOffsets.size() && grid.faceOffsets[c] > 0) {
          // the faces end at the offset: find where they start
          std::int64_t end = grid.faceOffsets[c], i = 0;
          for(std::size_t b = c; b-- > 0;)
            if(grid.faceOffsets[b] > 0) {
              i = grid.faceOffsets[b];
              break;
            }
          if(end <= (std::int64_t)grid.faces.size() && i < end) {
            std::int64_t numFaces = grid.faces[i++];
            for(std::int64_t f = 0; f < numFaces && i < end; f++) {
              std::int64_t m = grid.faces[i++];
              for(std::int64_t k = 0; k < m && i < end; k++, i++)
                if(grid.faces[i] >= 0 &&
                   grid.faces[i] < (std::int64_t)numPoints)
                  fv.push_back(p.vertices[grid.faces[i]]);
              fo.push_back(fv.size());
            }
          }
        }
        ph->setPolygons(fv, fo);
        created.push_back(ph);
      } break;
      default: {
        if(type == 8 && n == 4) { // pixel
          std::swap(v[2], v[3]);
          type = 9;
        }
        else if(type == 11 && n == 8) { // voxel
          std::swap(v[2], v[3]);
          std::swap(v[6], v[7]);
          type = 12;
        }
        int mshType = getMSHTypeOfVTKXMLCell(type, n);
        if(!mshType) {
          unknown[type]++;
          break;
        }
        const vtkXMLCell &cell = getVTKXMLCell(mshType);
        std::vector<MVertex *> w(n);
        for(std::int64_t k = 0; k < n; k++) w[cell.nodes[k]] = v[k];
        MElement *e = factory.create(mshType, w);
        if(e) created.push_back(e);
      } break;
      }
      for(auto e : created) {
        int tag = geometrical ? (int)(*geometrical)[c] : 1;
        elements[e->getType() % 16][tag].push_back(e);
        if(physical && (*physical)[c] > 0)
          physicals[e->getDim()][tag][(int)(*physical)[c]] = "";
        p.elements.push_back({c, e});
      }
    }
    for(auto &u : unknown)
      Msg::Warning("%d cells of VTK type %d ignored", u.second, u.first);

    for(int i = 0; i < 16; i++) model->_storeElementsInEntities(elements[i]);
    model->_associateEntityWithMeshVertices();
    // (the points no cell uses are deleted)
    std::vector<bool> unused(numPoints);
    for(std::size_t i = 0; i < numPoints; i++)
      unused[i] = !p.vertices[i]->onWhat();
    model->_storeVerticesInEntities(unique);
    for(std::size_t i = 0; i < numPoints; i++)
      if(unused[i]) p.vertices[i] = nullptr;
    for(int i = 0; i < 4; i++)
      model->_storePhysicalTagsInEntities(i, physicals[i]);
    GModel::setCurrent(current);
    return true;
  };

  for(std::size_t step = 0; step < files.size(); step++) {
    for(std::size_t ip = 0; ip < files[step].size(); ip++) {
      vtkXMLGrid grid;
      if(!grid.read(files[step][ip])) return 0;
      std::size_t numPoints = grid.points.size() / 3;
      std::size_t numCells = grid.types.size();

      if(ip >= parts.size()) {
        parts.resize(ip + 1);
        if(!build(this, grid, parts[ip])) return 0;
      }
      else {
        part &p = parts[ip];
        if(grid.points != p.points || grid.connectivity != p.connectivity ||
           grid.offsets != p.offsets || grid.types != p.types) {
          Msg::Info("New mesh in '%s'", files[step][ip].c_str());
          std::vector<int> visible;
          for(auto m : GModel::list) visible.push_back(m->getVisibility());
          GModel *m = new GModel();
          m->setFileName(files[step][ip]);
          m->setName(SplitFileName(files[step][ip])[1]);
          bool ok = build(m, grid, p);
          for(std::size_t i = 0; i < visible.size(); i++)
            GModel::list[i]->setVisibility(visible[i]);
          m->setVisibility(0);
          if(!ok) return 0;
        }
      }
      part &p = parts[ip];

#if defined(HAVE_POST)
      auto addData = [&](const vtkXMLGrid::realArray &a, bool onPoints) {
        if(!a.name.compare(0, 5, "gmsh:") || a.name == "CellEntityIds" ||
           a.name == "GlobalNodeIds")
          return;
        std::size_t n = onPoints ? numPoints : numCells;
        if(a.data.size() != n * a.numComp) return;
        // Gmsh fields have 1, 3 or 9 components
        int numComp = (a.numComp == 1) ? 1 : (a.numComp <= 3) ? 3 : 9;
        std::vector<std::size_t> tags;
        std::vector<double> data;
        auto add = [&](std::size_t tag, std::size_t i) {
          if(std::isnan(a.data[i * a.numComp])) return;
          tags.push_back(tag);
          for(int c = 0; c < numComp; c++)
            data.push_back(c < a.numComp ? a.data[i * a.numComp + c] : 0.);
        };
        if(onPoints) {
          for(std::size_t i = 0; i < numPoints; i++)
            if(p.vertices[i] && !p.copy[i]) add(p.vertices[i]->getNum(), i);
        }
        else {
          for(auto &e : p.elements) add(e.second->getNum(), e.first);
        }
        if(tags.empty()) return;
        std::string key = (onPoints ? "p:" : "c:") + a.name;
        PViewDataGModel *&d = p.views[key];
        bool first = !d;
        if(first) {
          d = new PViewDataGModel(onPoints ? PViewDataGModel::NodeData :
                                             PViewDataGModel::ElementData);
          d->setName(a.name);
          d->setFileName(name);
        }
        d->addData(p.model, tags, data, step, times[step], 0, numComp);
        if(first) new PView(d);
      };
      for(auto &a : grid.pointData) addData(a, true);
      for(auto &a : grid.cellData) addData(a, false);
#endif
    }
  }

#if defined(HAVE_POST)
  for(auto &p : parts)
    for(auto &v : p.views) v.second->finalize();
#endif
  return 1;
}
