// Gmsh Boundary Layer Plugin - Copyright (C) 2025-2026 C. Geuzaine and J.-F.
// Remacle
//
// This program is free software: you can redistribute it and/or modify it under
// the terms of the GNU Affero General Public License as published by the Free
// Software Foundation, either version 3 of the License, or (at your option) any
// later version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more
// details.
//
// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include <vector>
#include <cmath>
#include <algorithm>
#include <array>
#include <map>
#include <set>
#include "GModel.h"
#include "GRegion.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MTetrahedron.h"
#include "MQuadrangle.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "meshGEdge.h"
#include "BoundaryLayer.h"
#include "Context.h"
#include "OS.h"

#include "highOrderBoundaryLayerUntangler.h"
#include "WinslowUntangler.h"

GMSH_BoundaryLayerPlugin::GMSH_BoundaryLayerPlugin()
  : GMSH_PostPlugin({{GMSH_FULLRC, "Thickness", nullptr, 1.e-2},
                     {GMSH_FULLRC, "Size", nullptr, 1.e-3},
                     {GMSH_FULLRC, "Ratio", nullptr, 1.2},
                     {GMSH_FULLRC, "SmoothingLayers", nullptr, 2.},
                     {GMSH_FULLRC, "NumExactLayers", nullptr, -2.},
                     {GMSH_FULLRC, "HighOrder", nullptr, 1.},
                     {GMSH_FULLRC, "HighOrderStrategy", nullptr, 2.},
                     {GMSH_FULLRC, "HighOrderPostSplitUntangle", nullptr, 0.}},
                    {{GMSH_FULLRC, "Volumes", nullptr, ""},
                     {GMSH_FULLRC, "Surfaces", nullptr, ""},
                     {GMSH_FULLRC, "Curves", nullptr, ""},
                     {GMSH_FULLRC, "Points", nullptr, ""}})
{
}

std::string GMSH_BoundaryLayerPlugin::getHelp() const
{
  return "Plugin(BoundaryLayer) inserts boundary layers in the current mesh, "
         "which must be of order 1: layers of quadrangles along curves in a "
         "2D mesh, or of prisms (hexahedra on quadrangles) along surfaces in "
         "a 3D mesh. The mesh is generated first, without layers; the plugin "
         "then moves the elements next to the walls to make room for "
         "them.\n\n"
         "`Volumes', `Surfaces' and `Curves' are comma-separated lists of "
         "tags. For a 3D mesh, `Volumes' gives the volumes that receive the "
         "layers and `Surfaces' the walls. For a 2D mesh, `Volumes' is "
         "empty, `Surfaces' gives the surfaces that receive the layers and "
         "`Curves' the walls. A wall on the boundary gets layers on one "
         "side; a wall between two of the volumes (or surfaces), or embedded "
         "in one of them, gets layers on both sides. Where a wall ends on "
         "another surface or curve the layers end on it as well, and its "
         "mesh is modified accordingly.\n\n"
         "`Size' is the height of the first layer, `Ratio' the ratio "
         "between the heights of two successive layers and `Thickness' the "
         "total thickness: there are as many layers as needed for their "
         "heights to add up to `Thickness'. These values are never exceeded, "
         "but the thickness is reduced where the layers do not fit: between "
         "two walls closer than about three times the thickness, and down "
         "to zero along the free edge of a wall with layers on both sides. "
         "Where the thickness is reduced, the first `NumExactLayers' layers "
         "keep their height as long as possible and the others are reduced "
         "first; a negative value -n stands for one n-th of the "
         "layers.\n\n"
         "`SmoothingLayers' is the number of rings of elements around the "
         "layers that are moved to make room for them: it should be "
         "increased when the layers are thick compared with the elements "
         "next to the walls.\n\n"
         "If `HighOrder' is larger than 1 the layers are curved to that "
         "order (experimental, order 2 only): they are split then curved if "
         "`HighOrderStrategy' is 1, curved then split if it is 2, and "
         "`HighOrderPostSplitUntangle' untangles the volume mesh once more "
         "after the split.\n\n"
         "`Points' is not used.";
}

static double triangleArea2D(std::array<double, 2> a, std::array<double, 2> b,
                             std::array<double, 2> c)
{
  return .5 * ((b[1] - a[1]) * (b[0] + a[0]) + (c[1] - b[1]) * (c[0] + b[0]) +
               (a[1] - c[1]) * (a[0] + c[0]));
}

inline std::array<double, 3> sub(const std::array<double, 3> &x,
                                 const std::array<double, 3> &y)
{ return {x[0] - y[0], x[1] - y[1], x[2] - y[2]}; }

inline double dot(const std::array<double, 3> &u,
                  const std::array<double, 3> &v)
{ return u[0] * v[0] + u[1] * v[1] + u[2] * v[2]; }

inline std::array<double, 3> cross(const std::array<double, 3> &u,
                                   const std::array<double, 3> &v)
{
  return {u[1] * v[2] - u[2] * v[1], u[2] * v[0] - u[0] * v[2],
          u[0] * v[1] - u[1] * v[0]};
}

inline double tetVolume(const std::array<double, 3> &a,
                        const std::array<double, 3> &b,
                        const std::array<double, 3> &c,
                        const std::array<double, 3> &d)
{ return dot(sub(a, d), cross(sub(b, d), sub(c, d))) / 6.0; }

// Parametric coordinates of a node on a surface. A node on a curve lying on
// the seam of a periodic surface has two sets of coordinates: return the one
// inside the parametric bounds of the surface, so that a surface that does not
// span the whole period gets a single-valued parametrization.
static bool reparamOnFace(MVertex *v, GFace *gf, SPoint2 &param)
{
  if(!reparamMeshVertexOnFace(v, gf, param, true, false)) return false;
  for(int i = 0; i < 2; i++) {
    if(!gf->periodic(i)) continue;
    double period = gf->period(i);
    if(period <= 0.) continue;
    Range<double> bounds = gf->parBounds(i);
    double tol = 1.e-6 * period;
    while(param[i] > bounds.high() + tol &&
          param[i] - period > bounds.low() - tol)
      param[i] -= period;
    while(param[i] < bounds.low() - tol &&
          param[i] + period < bounds.high() + tol)
      param[i] += period;
  }
  return true;
}

// Layer elements

// A layer element, described by its columns: column j goes from wall node j to
// the node spawned from it. Where no node could be spawned the layer is
// pinched: the column has no top and the element loses a node. In a surface
// (n = 2) a quad becomes a triangle; in a volume a prism (n = 3) becomes a
// pyramid or a tetrahedron, and a hexahedron (n = 4) a prism or a pyramid.
struct LayerColumns {
  std::size_t n = 0;
  MVertex *wall[4] = {nullptr, nullptr, nullptr, nullptr};
  MVertex *top[4] = {nullptr, nullptr, nullptr, nullptr};
  std::size_t numTops() const
  {
    std::size_t num = 0;
    for(std::size_t j = 0; j < n; j++)
      if(top[j]) num++;
    return num;
  }
};

// The columns of the pinched layer elements: those of the others follow from
// the order of their nodes
typedef std::map<MElement *, LayerColumns> PinchMap;

// A column of the layers, from a wall node to its spawned node. The cosine is
// the largest one between the column and the normals of the wall elements
// around it, so that the height of the column above the wall is its length
// times the cosine.
struct Column {
  MVertex *wall = nullptr;
  double cosine = 0.;
};

// Everything known about the layers while they are built
struct LayerData {
  // the layer elements, with the thickness requested when they were inserted,
  // then the height of their layer once the columns are split
  std::map<MElement *, double> elements;
  // those that lost nodes, and the wall nodes without any spawned node
  PinchMap pinched;
  std::set<MVertex *> pinchedNodes;
  // target thickness of each wall node
  std::map<MVertex *, double> wallThickness;
  // the columns, by the node at their top
  std::map<MVertex *, Column> columns;
  // nodes moved so far: the elements around them must be untangled
  std::set<MVertex *> moved;
  // shape of the elements before the inflation, which the elements outside
  // the layers try to keep: for those of the surfaces, in the parametric
  // plane (and mirrored if the mesh of the surface is negative there); for
  // those of the volumes, the position of their nodes
  std::map<MElement *, std::array<std::array<double, 2>, 4>> shapes2D;
  std::vector<std::array<double, 3>> positions; // of the nodes, by number

  bool has(MElement *e) const { return elements.find(e) != elements.end(); }
  double thicknessAt(MVertex *v, double defaultValue) const
  {
    auto it = wallThickness.find(v);
    return it != wallThickness.end() ? it->second : defaultValue;
  }
};

static bool getLayerColumns(MElement *e, const LayerData &data,
                            LayerColumns &lc)
{
  auto it = data.pinched.find(e);
  if(it != data.pinched.end()) {
    lc = it->second;
    return true;
  }
  switch(e->getTypeForMSH()) {
  case MSH_QUA_4:
    // nodes 0 and 1 are on the wall
    lc.n = 2;
    lc.wall[0] = e->getVertex(0);
    lc.wall[1] = e->getVertex(1);
    lc.top[0] = e->getVertex(3);
    lc.top[1] = e->getVertex(2);
    return true;
  case MSH_PRI_6:
  case MSH_HEX_8:
    lc.n = e->getNumVertices() / 2;
    for(std::size_t j = 0; j < lc.n; j++) {
      lc.wall[j] = e->getVertex(j);
      lc.top[j] = e->getVertex(j + lc.n);
    }
    return true;
  default: return false;
  }
}

// A hexahedron can only lose two neighbouring columns or three columns
static bool isSupported(const LayerColumns &lc)
{
  if(lc.n != 4) return true;
  std::size_t num = lc.numTops();
  if(num == 4 || num == 1 || num == 0) return true;
  if(num == 3) return false;
  for(std::size_t i = 0; i < 4; i++)
    if(!lc.top[i] && !lc.top[(i + 1) % 4]) return true;
  return false;
}

// Create the layer element with the given columns on a surface. The wall nodes
// are ordered so that the element is oriented as the others.
static MElement *addLayerElement(GFace *gf, const LayerColumns &lc)
{
  MVertex *const *w = lc.wall, *const *t = lc.top;
  if(t[0] && t[1]) {
    gf->quadrangles.push_back(new MQuadrangle(w[0], w[1], t[1], t[0]));
    return gf->quadrangles.back();
  }
  if(t[0] || t[1]) {
    gf->triangles.push_back(new MTriangle(w[0], w[1], t[0] ? t[0] : t[1]));
    return gf->triangles.back();
  }
  return nullptr;
}

// Same in a volume
static MElement *addLayerElement(GRegion *gr, const LayerColumns &lc)
{
  MVertex *const *w = lc.wall, *const *t = lc.top;
  const std::size_t num = lc.numTops();
  if(lc.n == 3) {
    if(num == 3) {
      gr->prisms.push_back(new MPrism(w[0], w[1], w[2], t[0], t[1], t[2]));
      return gr->prisms.back();
    }
    if(num == 2) {
      // the quad between the two columns, seen from the pinched node
      std::size_t m = !t[0] ? 0 : !t[1] ? 1 : 2;
      std::size_t p = (m + 1) % 3, q = (m + 2) % 3;
      gr->pyramids.push_back(new MPyramid(w[p], t[p], t[q], w[q], w[m]));
      return gr->pyramids.back();
    }
    if(num == 1) {
      gr->tetrahedra.push_back(new MTetrahedron(w[0], w[1], w[2],
                                                t[0] ? t[0] :
                                                t[1] ? t[1] :
                                                       t[2]));
      return gr->tetrahedra.back();
    }
  }
  else if(lc.n == 4) {
    if(num == 4) {
      gr->hexahedra.push_back(
        new MHexahedron(w[0], w[1], w[2], w[3], t[0], t[1], t[2], t[3]));
      return gr->hexahedra.back();
    }
    if(num == 2) {
      for(std::size_t i = 0; i < 4; i++) {
        if(t[i] || t[(i + 1) % 4]) continue;
        std::size_t j = (i + 1) % 4, k = (i + 2) % 4, l = (i + 3) % 4;
        gr->prisms.push_back(new MPrism(w[i], w[l], t[l], w[j], w[k], t[k]));
        return gr->prisms.back();
      }
    }
    if(num == 1) {
      MVertex *apex = t[0] ? t[0] : t[1] ? t[1] : t[2] ? t[2] : t[3];
      gr->pyramids.push_back(new MPyramid(w[0], w[1], w[2], w[3], apex));
      return gr->pyramids.back();
    }
  }
  return nullptr;
}

static void addLayerElement(GEntity *ge, const LayerColumns &lc,
                            double thickness, LayerData &data)
{
  MElement *e = (lc.n == 2) ? addLayerElement(static_cast<GFace *>(ge), lc) :
                              addLayerElement(static_cast<GRegion *>(ge), lc);
  if(!e) return;
  data.elements[e] = thickness;
  if(lc.numTops() < lc.n) data.pinched[e] = lc;
}

// Insertion of the layers
//
// The layers are inserted with zero thickness, by duplicating the nodes of the
// walls. A single rule is applied to each wall node v, in 2D and in 3D:
//
// - The elements of the domains around v are grouped in components: two
//   elements are in the same component if one can go from one to the other
//   around v without crossing the wall. A node inside a wall on the boundary
//   has one component, a node inside a wall with layers on both sides has two,
//   and a node on the rim of such a wall has one again, which contains both
//   sides.
// - Each component touching the wall gets one new node, the spawn of v, which
//   replaces v in all the elements of the component.
// - The spawn is classified on the entity the component leaves the wall along:
//   the curve whose line starts at v without being in the wall if there is
//   one, otherwise the surface (not a wall) with elements around v in the
//   component if there is one, otherwise the volume (in 2D: the curve,
//   otherwise the surface).
// - No node is spawned where that cannot work, and the layers are pinched
//   there, i.e. they have no thickness at v: on the free edge of a wall with
//   layers on both sides, where a single node would have to rise on both
//   sides, and where several curves or surfaces leave the wall in the same
//   component.
// - A layer element is created between each wall element and its copy on the
//   spawns, on each side of the wall that has elements; and on the surfaces
//   along which the layers leave the wall, a quad between each wall edge and
//   its copy.

namespace {

  // A facet of an element: a face in 3D, an edge in 2D
  struct Facet {
    MVertex *v[4] = {nullptr, nullptr, nullptr, nullptr};
    std::size_t n = 0;
  };

  struct FacetKey {
    std::size_t n[4] = {0, 0, 0, 0};
    bool operator<(const FacetKey &o) const
    {
      for(int i = 0; i < 4; i++)
        if(n[i] != o.n[i]) return n[i] < o.n[i];
      return false;
    }
  };

  static FacetKey facetKey(MVertex *const *v, std::size_t n)
  {
    FacetKey k;
    for(std::size_t i = 0; i < n; i++) k.n[i] = v[i]->getNum();
    std::sort(k.n, k.n + n);
    return k;
  }

  static FacetKey facetKey(MElement *e)
  {
    MVertex *v[4];
    std::size_t n = std::min<std::size_t>(e->getNumPrimaryVertices(), 4);
    for(std::size_t i = 0; i < n; i++) v[i] = e->getVertex(i);
    return facetKey(v, n);
  }

  static void getFacets(MElement *e, int dim, std::vector<Facet> &facets)
  {
    facets.clear();
    if(dim == 3) {
      for(int k = 0; k < e->getNumFaces(); k++) {
        MFace f = e->getFace(k);
        Facet facet;
        facet.n = f.getNumVertices();
        for(std::size_t i = 0; i < facet.n; i++) facet.v[i] = f.getVertex(i);
        facets.push_back(facet);
      }
    }
    else {
      for(int k = 0; k < e->getNumEdges(); k++) {
        MEdge edge = e->getEdge(k);
        Facet facet;
        facet.n = 2;
        facet.v[0] = edge.getVertex(0);
        facet.v[1] = edge.getVertex(1);
        facets.push_back(facet);
      }
    }
  }

  static bool elementHasVertex(MElement *e, MVertex *v)
  {
    for(std::size_t i = 0; i < e->getNumVertices(); i++)
      if(e->getVertex(i) == v) return true;
    return false;
  }

  // An element of a domain with at least one node on the wall
  struct StarElement {
    MElement *e;
    GEntity *domain;
  };

  // The elements around wall node v that can be reached from one another
  // without crossing the wall
  struct Component {
    MVertex *v = nullptr;
    std::vector<int> elements;
    bool onWall = false; // an element has a facet on the wall
    bool pinched = false; // no node can be spawned
    MVertex *spawn = nullptr;
  };

  // The insertion of the layers along the walls (surfaces in 3D, curves in 2D)
  // of the domains (volumes in 3D, surfaces in 2D), in steps. Nothing is
  // changed in the mesh before the last step, apply().
  class LayerInsertion {
  public:
    LayerInsertion(GModel *m, int dim, const std::vector<GEntity *> &domains,
                   const std::set<GEntity *, GEntityPtrLessThan> &walls)
      : m(m), dim(dim), domains(domains), walls(walls)
    {
    }

    bool run(double thickness, LayerData &data,
             std::vector<GFace *> &sideSurfaces)
    {
      if(!collectWalls() || !collectStar()) return false;
      buildComponents();
      collectLinesAndSurfaceElements();
      spawnNodes();
      createLayerElements();
      createSideElements();
      if(!check(data)) return false;
      apply(thickness, data, sideSurfaces);
      return true;
    }

  private:
    struct NodeLine {
      GEdge *ge;
      MLine *line;
    };
    struct NodeFacet {
      GFace *gf;
      MElement *e;
    };
    struct NewVertex {
      GEntity *ge;
      MVertex *v;
      bool front;
    };
    struct LineEdit {
      GEdge *ge;
      bool begin;
      MVertex *v, *spawn;
    };
    struct NewElement {
      GEntity *ge;
      LayerColumns lc;
    };
    struct NodeEdit {
      MElement *e;
      int index;
      MVertex *spawn;
    };

    GModel *m;
    int dim;
    const std::vector<GEntity *> &domains;
    const std::set<GEntity *, GEntityPtrLessThan> &walls;

    // facets, elements, nodes and (in 3D) edges of the walls
    std::map<FacetKey, MElement *> wallFacets;
    std::vector<MElement *> wallElements;
    std::set<MVertex *, MVertexPtrLessThan> wallNodes;
    std::set<std::pair<std::size_t, std::size_t>> wallEdges;
    // elements of the domains around the wall nodes: those around each node,
    // and the (at most two) elements on each of their facets
    std::vector<StarElement> star;
    std::map<MVertex *, std::vector<int>> starOf;
    std::map<FacetKey, std::array<int, 2>> facetMap;
    std::vector<Facet> facets;
    // components of the star of each wall node, and the component of each
    // (node, element)
    std::vector<Component> components;
    std::map<std::pair<std::size_t, int>, int> componentOf;
    // the lines of the curves starting at a wall node without being in the
    // wall, and in 3D the elements of the other surfaces around it
    std::map<MVertex *, std::vector<NodeLine>> linesAt;
    std::map<MVertex *, std::vector<NodeFacet>> surfaceElementsAt;
    std::vector<NodeFacet> surfaceElements; // with at least one wall node
    // the changes to apply
    std::vector<NewVertex> newVertices;
    std::vector<LineEdit> lineEdits;
    std::vector<NewElement> newElements;
    std::vector<NodeEdit> nodeEdits;
    std::vector<NewElement> newSideElements;
    std::set<GFace *, GEntityPtrLessThan> sharedSurfaces;
    std::size_t numUnsupported = 0;

    static std::pair<std::size_t, std::size_t> edgeKey(MVertex *a, MVertex *b)
    {
      return std::make_pair(std::min(a->getNum(), b->getNum()),
                            std::max(a->getNum(), b->getNum()));
    }

    bool isWallNode(MVertex *v) const
    { return wallNodes.find(v) != wallNodes.end(); }

    int componentAt(MVertex *v, int element) const
    {
      auto it = componentOf.find(std::make_pair(v->getNum(), element));
      return it == componentOf.end() ? -1 : it->second;
    }

    MVertex *spawnAt(MVertex *v, int element) const
    {
      int c = componentAt(v, element);
      return c < 0 ? nullptr : components[c].spawn;
    }

    // the element of the domains a surface element is a facet of, or -1
    int elementOn(MElement *surfaceElement) const
    {
      auto it = facetMap.find(facetKey(surfaceElement));
      return it == facetMap.end() ? -1 : it->second[0];
    }

    bool collectWalls()
    {
      for(auto w : walls) {
        for(std::size_t i = 0; i < w->getNumMeshElements(); i++) {
          MElement *e = w->getMeshElement(i);
          if(e->getDim() != dim - 1) continue;
          if(e->getPolynomialOrder() != 1) {
            Msg::Error("Boundary layer: the mesh must be of order 1");
            return false;
          }
          if(!wallFacets.insert(std::make_pair(facetKey(e), e)).second)
            continue;
          wallElements.push_back(e);
          std::size_t n = e->getNumPrimaryVertices();
          for(std::size_t j = 0; j < n; j++) {
            wallNodes.insert(e->getVertex(j));
            if(dim == 3)
              wallEdges.insert(
                edgeKey(e->getVertex(j), e->getVertex((j + 1) % n)));
          }
        }
      }
      if(wallElements.empty()) {
        Msg::Warning("Boundary layer: no mesh on the %s to create layers on",
                     dim == 3 ? "surfaces" : "curves");
        return false;
      }
      return true;
    }

    // elements of the domains around the wall nodes, and their facets
    bool collectStar()
    {
      for(auto domain : domains) {
        for(std::size_t i = 0; i < domain->getNumMeshElements(); i++) {
          MElement *e = domain->getMeshElement(i);
          if(e->getDim() != dim) continue;
          bool inStar = false;
          for(std::size_t j = 0; j < e->getNumVertices(); j++) {
            if(!isWallNode(e->getVertex(j))) continue;
            if(!inStar) {
              if(e->getPolynomialOrder() != 1) {
                Msg::Error("Boundary layer: the mesh must be of order 1");
                return false;
              }
              star.push_back({e, domain});
              inStar = true;
            }
            starOf[e->getVertex(j)].push_back((int)star.size() - 1);
          }
          if(!inStar) continue;
          getFacets(e, dim, facets);
          for(const auto &facet : facets) {
            auto it = facetMap
                        .insert(std::make_pair(facetKey(facet.v, facet.n),
                                               std::array<int, 2>{-1, -1}))
                        .first;
            if(it->second[0] < 0)
              it->second[0] = (int)star.size() - 1;
            else if(it->second[1] < 0)
              it->second[1] = (int)star.size() - 1;
          }
        }
      }
      return true;
    }

    // components of the star of each wall node
    void buildComponents()
    {
      for(auto v : wallNodes) {
        auto its = starOf.find(v);
        if(its == starOf.end()) continue;
        const std::vector<int> &elements = its->second;
        const int n = (int)elements.size();
        std::map<int, int> local;
        for(int i = 0; i < n; i++) local[elements[i]] = i;
        std::vector<int> parent(n);
        for(int i = 0; i < n; i++) parent[i] = i;
        auto find = [&](int i) {
          while(parent[i] != i) i = parent[i] = parent[parent[i]];
          return i;
        };
        std::vector<bool> onWall(n, false);
        std::vector<std::pair<FacetKey, int>> wallHits;
        for(int i = 0; i < n; i++) {
          getFacets(star[elements[i]].e, dim, facets);
          for(const auto &facet : facets) {
            bool hasV = false;
            for(std::size_t k = 0; k < facet.n; k++)
              if(facet.v[k] == v) hasV = true;
            if(!hasV) continue;
            FacetKey key = facetKey(facet.v, facet.n);
            if(wallFacets.find(key) != wallFacets.end()) {
              onWall[i] = true;
              wallHits.push_back(std::make_pair(key, i));
              continue;
            }
            auto itf = facetMap.find(key);
            if(itf == facetMap.end()) continue;
            for(int other : itf->second) {
              if(other < 0 || other == elements[i]) continue;
              auto itl = local.find(other);
              if(itl != local.end()) parent[find(i)] = find(itl->second);
            }
          }
        }
        std::map<int, int> rootToComponent;
        for(int i = 0; i < n; i++) {
          int root = find(i);
          auto itr = rootToComponent.find(root);
          if(itr == rootToComponent.end()) {
            itr = rootToComponent
                    .insert(std::make_pair(root, (int)components.size()))
                    .first;
            components.push_back(Component());
            components.back().v = v;
          }
          Component &c = components[itr->second];
          c.elements.push_back(elements[i]);
          if(onWall[i]) c.onWall = true;
          componentOf[std::make_pair(v->getNum(), elements[i])] = itr->second;
        }
        // a wall element with both its sides in the same component: v is on the
        // free edge of a wall with layers on both sides
        std::map<std::pair<int, FacetKey>, int> sides;
        for(const auto &hit : wallHits) {
          int root = find(hit.second);
          if(++sides[std::make_pair(root, hit.first)] > 1)
            components[rootToComponent[root]].pinched = true;
        }
      }
    }

    void collectLinesAndSurfaceElements()
    {
      for(auto it = m->firstEdge(); it != m->lastEdge(); ++it) {
        GEdge *ge = *it;
        if(dim == 2 && walls.find(ge) != walls.end()) continue;
        for(auto line : ge->lines) {
          MVertex *a = line->getVertex(0), *b = line->getVertex(1);
          if(dim == 3 && wallEdges.find(edgeKey(a, b)) != wallEdges.end())
            continue;
          if(isWallNode(a)) linesAt[a].push_back({ge, line});
          if(isWallNode(b)) linesAt[b].push_back({ge, line});
        }
      }
      if(dim == 3) {
        for(auto it = m->firstFace(); it != m->lastFace(); ++it) {
          GFace *gf = *it;
          if(walls.find(gf) != walls.end()) continue;
          for(std::size_t i = 0; i < gf->getNumMeshElements(); i++) {
            MElement *e = gf->getMeshElement(i);
            if(e->getDim() != 2) continue;
            bool any = false;
            for(std::size_t j = 0; j < e->getNumPrimaryVertices(); j++) {
              if(!isWallNode(e->getVertex(j))) continue;
              surfaceElementsAt[e->getVertex(j)].push_back({gf, e});
              any = true;
            }
            if(any) surfaceElements.push_back({gf, e});
          }
        }
      }
    }

    // spawn the nodes
    void spawnNodes()
    {
      for(std::size_t ic = 0; ic < components.size(); ic++) {
        Component &c = components[ic];
        if(!c.onWall || c.pinched) continue;
        MVertex *v = c.v;

        // curves along which the component leaves the wall
        std::vector<NodeLine> lines;
        auto itl = linesAt.find(v);
        if(itl != linesAt.end()) {
          for(const auto &nl : itl->second) {
            MVertex *other = (nl.line->getVertex(0) == v) ?
                               nl.line->getVertex(1) :
                               nl.line->getVertex(0);
            for(int element : c.elements) {
              if(elementHasVertex(star[element].e, other)) {
                lines.push_back(nl);
                break;
              }
            }
          }
        }

        if(lines.size() > 1) {
          c.pinched = true;
          continue;
        }
        if(lines.size() == 1) {
          GEdge *ge = lines[0].ge;
          MLine *line = lines[0].line;
          bool begin = !ge->lines.empty() && line == ge->lines.front() &&
                       line->getVertex(0) == v;
          bool end = !ge->lines.empty() && line == ge->lines.back() &&
                     line->getVertex(1) == v;
          double param;
          if((!begin && !end) || !reparamMeshVertexOnEdge(v, ge, param)) {
            c.pinched = true;
            continue;
          }
          double lc = line->getLength();
          if(!ge->mesh_vertices.empty()) {
            MEdgeVertex *neighbour = dynamic_cast<MEdgeVertex *>(
              begin ? ge->mesh_vertices.front() : ge->mesh_vertices.back());
            if(neighbour) lc = neighbour->getLc();
          }
          c.spawn = new MEdgeVertex(v->x(), v->y(), v->z(), ge, param, 0, lc);
          newVertices.push_back({ge, c.spawn, begin});
          lineEdits.push_back({ge, begin, v, c.spawn});
          continue;
        }

        // surface along which the component leaves the wall
        GFace *gf = nullptr;
        bool severalSurfaces = false;
        if(dim == 3) {
          auto itf = surfaceElementsAt.find(v);
          if(itf != surfaceElementsAt.end()) {
            for(const auto &nf : itf->second) {
              auto ite = facetMap.find(facetKey(nf.e));
              if(ite == facetMap.end()) continue;
              bool inComponent = false;
              for(int element : ite->second)
                if(element >= 0 && componentAt(v, element) == (int)ic)
                  inComponent = true;
              if(!inComponent) continue;
              if(gf && gf != nf.gf) severalSurfaces = true;
              gf = nf.gf;
            }
          }
        }
        else
          gf = static_cast<GFace *>(star[c.elements[0]].domain);
        if(severalSurfaces) {
          c.pinched = true;
          continue;
        }
        if(gf) {
          SPoint2 param;
          if(!reparamOnFace(v, gf, param)) {
            c.pinched = true;
            continue;
          }
          c.spawn =
            new MFaceVertex(v->x(), v->y(), v->z(), gf, param.x(), param.y());
          newVertices.push_back({gf, c.spawn, false});
        }
        else {
          GEntity *domain = star[c.elements[0]].domain;
          c.spawn = new MVertex(v->x(), v->y(), v->z(), domain);
          newVertices.push_back({domain, c.spawn, false});
        }
      }
    }

    // the layer elements, between each wall element and its spawn on each
    // side
    void createLayerElements()
    {
      for(auto wallElement : wallElements) {
        auto itf = facetMap.find(facetKey(wallElement));
        if(itf == facetMap.end()) continue;
        for(int element : itf->second) {
          if(element < 0) continue;
          MElement *e = star[element].e;
          NewElement ne;
          ne.ge = star[element].domain;
          LayerColumns &lc = ne.lc;
          lc.n = wallElement->getNumPrimaryVertices();
          for(std::size_t j = 0; j < lc.n; j++) {
            lc.wall[j] = wallElement->getVertex(j);
            lc.top[j] = spawnAt(lc.wall[j], element);
          }
          if(!lc.numTops()) continue;
          bool reversed;
          if(dim == 3) {
            // the volume lies behind the wall element if the face of its
            // element has the same orientation
            int ithFace = 0, sign = 0, rot = 0;
            e->getFaceInfo(wallElement->getFace(0), ithFace, sign, rot);
            reversed = (sign > 0);
          }
          else {
            // the layer element is oriented as the element, which runs along
            // the wall line in the same direction
            reversed = true;
            for(int k = 0; k < e->getNumEdges(); k++) {
              MEdge edge = e->getEdge(k);
              if(edge.getVertex(0) == lc.wall[0] &&
                 edge.getVertex(1) == lc.wall[1])
                reversed = false;
            }
          }
          if(reversed) {
            const std::size_t i = (dim == 2) ? 0 : 1, j = lc.n - 1;
            std::swap(lc.wall[i], lc.wall[j]);
            std::swap(lc.top[i], lc.top[j]);
          }
          if(!isSupported(lc)) {
            numUnsupported++;
            continue;
          }
          newElements.push_back(ne);
        }
      }
    }

    // in 3D, the surfaces along which the layers leave the wall: their
    // elements move to the spawned nodes, and a layer element is created on
    // each wall edge
    void createSideElements()
    {
      std::set<GEntity *> domainSet(domains.begin(), domains.end());
      for(const auto &se : surfaceElements) {
        int element = elementOn(se.e);
        if(element < 0) continue;
        const std::size_t n = se.e->getNumPrimaryVertices();
        MVertex *spawns[4] = {nullptr, nullptr, nullptr, nullptr};
        bool any = false;
        for(std::size_t j = 0; j < n; j++) {
          MVertex *v = se.e->getVertex(j);
          if(!isWallNode(v)) continue;
          spawns[j] = spawnAt(v, element);
          if(!spawns[j]) continue;
          nodeEdits.push_back({se.e, (int)j, spawns[j]});
          any = true;
        }
        if(!any) continue;
        for(auto gr : se.gf->regions())
          if(domainSet.find(gr) == domainSet.end())
            sharedSurfaces.insert(se.gf);
        for(std::size_t j = 0; j < n; j++) {
          std::size_t k = (j + 1) % n;
          MVertex *a = se.e->getVertex(j), *b = se.e->getVertex(k);
          if(!spawns[j] && !spawns[k]) continue;
          if(wallEdges.find(edgeKey(a, b)) == wallEdges.end()) continue;
          NewElement ne;
          ne.ge = se.gf;
          ne.lc.n = 2;
          ne.lc.wall[0] = a;
          ne.lc.wall[1] = b;
          ne.lc.top[0] = spawns[j];
          ne.lc.top[1] = spawns[k];
          newSideElements.push_back(ne);
        }
      }
    }

    // give up if a layer element cannot be created, and find the wall nodes
    // without any spawned node
    bool check(LayerData &data)
    {
      if(numUnsupported) {
        Msg::Error(
          "Boundary layer: %zu hexahedra of the layers would be pinched "
          "in a way that leaves no valid element: mesh left unchanged",
          numUnsupported);
        for(auto &nv : newVertices) delete nv.v;
        return false;
      }
      // the wall nodes without any spawned node
      {
        std::map<MVertex *, bool, MVertexPtrLessThan> spawned;
        for(const auto &c : components) {
          if(!c.onWall) continue;
          if(c.spawn)
            spawned[c.v] = true;
          else if(spawned.find(c.v) == spawned.end())
            spawned[c.v] = false;
        }
        for(const auto &sp : spawned)
          if(!sp.second) data.pinchedNodes.insert(sp.first);
        if(!data.pinchedNodes.empty())
          Msg::Info("Boundary layer: layers pinched at %zu wall node(s)",
                    data.pinchedNodes.size());
      }
      for(auto gf : sharedSurfaces)
        Msg::Warning(
          "Boundary layer: the layers end on surface %d, shared with a "
          "volume without layers: the mesh will not be conforming "
          "across it",
          gf->tag());
      return true;
    }

    void apply(double thickness, LayerData &data,
               std::vector<GFace *> &sideSurfaces)
    {
      for(auto &nv : newVertices) {
        if(nv.front)
          nv.ge->mesh_vertices.insert(nv.ge->mesh_vertices.begin(), nv.v);
        else
          nv.ge->mesh_vertices.push_back(nv.v);
      }
      for(auto &c : components) {
        if(!c.spawn) continue;
        for(int element : c.elements) {
          MElement *e = star[element].e;
          for(std::size_t j = 0; j < e->getNumVertices(); j++)
            if(e->getVertex(j) == c.v) e->setVertex(j, c.spawn);
        }
      }
      for(auto &ne : nodeEdits) ne.e->setVertex(ne.index, ne.spawn);
      for(auto &le : lineEdits) {
        if(le.begin) {
          le.ge->lines.front()->setVertex(0, le.spawn);
          le.ge->lines.insert(le.ge->lines.begin(), new MLine(le.v, le.spawn));
        }
        else {
          le.ge->lines.back()->setVertex(1, le.spawn);
          le.ge->lines.push_back(new MLine(le.spawn, le.v));
        }
      }
      for(auto &ne : newElements)
        addLayerElement(ne.ge, ne.lc, thickness, data);
      for(auto &ne : newSideElements) {
        addLayerElement(ne.ge, ne.lc, thickness, data);
        GFace *gf = static_cast<GFace *>(ne.ge);
        if(std::find(sideSurfaces.begin(), sideSurfaces.end(), gf) ==
           sideSurfaces.end())
          sideSurfaces.push_back(gf);
      }
    }
  };

} // namespace

// Insert zero-thickness layers along the walls (surfaces in 3D, curves in 2D)
// in the domains (volumes in 3D, surfaces in 2D). Return in sideSurfaces the
// surfaces that received layer elements in 3D, in pinched the layer elements
// that lost a node and in pinchedNodes the wall nodes without any spawned
// node. Nothing is changed if the layers cannot be inserted.
static bool insertLayers(GModel *m, int dim,
                         const std::vector<GEntity *> &domains,
                         const std::set<GEntity *, GEntityPtrLessThan> &walls,
                         double thickness, LayerData &data,
                         std::vector<GFace *> &sideSurfaces)
{
  return LayerInsertion(m, dim, domains, walls)
    .run(thickness, data, sideSurfaces);
}

namespace {

  // The elements of a surface or of a volume to untangle, and the nodes that
  // stay in place. The elements are the layers and numRings rings of elements
  // around them, and around the nodes already moved on the boundary. The fixed
  // nodes are those of the other elements and those on the boundary (not
  // classified on an entity of dimension dim).
  template <class GEntityT>
  static void
  buildUntangleSets(GEntityT *ge, int dim, const LayerData &data,
                    std::size_t numRings,
                    std::set<MElement *, MElementPtrLessThan> &toProcess,
                    std::set<MVertex *, MVertexPtrLessThan> &fixed)
  {
    const std::size_t numElements = ge->getNumMeshElements();
    std::vector<MElement *> elements(numElements);
    std::size_t maxNum = 0;
    for(std::size_t i = 0; i < numElements; i++) {
      elements[i] = ge->getMeshElement(i);
      for(std::size_t j = 0; j < elements[i]->getNumVertices(); j++)
        maxNum = std::max(maxNum, elements[i]->getVertex(j)->getNum());
    }

    // flags by node number
    std::vector<char> touched(maxNum + 1, 0);
    for(auto e : elements) {
      bool inLayer = data.has(e);
      for(std::size_t j = 0; j < e->getNumVertices(); j++) {
        MVertex *v = e->getVertex(j);
        if(inLayer || data.moved.find(v) != data.moved.end())
          touched[v->getNum()] = 1;
      }
    }

    // a ring: the elements with a touched node, whose nodes are touched for
    // the next ring
    std::vector<char> processed(numElements, 0);
    for(std::size_t ring = 0; ring < numRings; ring++) {
      std::vector<std::size_t> newlyTouched;
      for(std::size_t i = 0; i < numElements; i++) {
        if(processed[i]) continue;
        MElement *e = elements[i];
        bool touches = false;
        for(std::size_t j = 0; j < e->getNumVertices() && !touches; j++)
          touches = touched[e->getVertex(j)->getNum()];
        if(!touches) continue;
        processed[i] = 1;
        for(std::size_t j = 0; j < e->getNumVertices(); j++)
          newlyTouched.push_back(e->getVertex(j)->getNum());
      }
      for(auto num : newlyTouched) touched[num] = 1;
    }

    std::vector<MElement *> processedElements;
    std::vector<MVertex *> fixedNodes;
    for(std::size_t i = 0; i < numElements; i++) {
      MElement *e = elements[i];
      if(processed[i]) processedElements.push_back(e);
      for(std::size_t j = 0; j < e->getNumVertices(); j++) {
        MVertex *v = e->getVertex(j);
        if(!processed[i] || v->onWhat()->dim() != dim) fixedNodes.push_back(v);
      }
    }
    // sorted, the sets are built in linear time
    std::sort(processedElements.begin(), processedElements.end(),
              MElementPtrLessThan());
    std::sort(fixedNodes.begin(), fixedNodes.end(), MVertexPtrLessThan());
    toProcess.insert(processedElements.begin(), processedElements.end());
    fixed.insert(fixedNodes.begin(), fixedNodes.end());
  }

  // The part of the mesh of a surface or of a volume that is untangled: the
  // layers and the rings of elements around them
  struct UntangleSet {
    std::set<MElement *, MElementPtrLessThan> elements;
    std::vector<MVertex *> nodes; // node i has index i
    std::vector<bool> locked;
  };

  template <class GEntityT>
  static void buildUntangleSet(GEntityT *ge, int dim, const LayerData &data,
                               std::size_t numRings, bool lockLayers,
                               UntangleSet &set)
  {
    std::set<MVertex *, MVertexPtrLessThan> fixed;
    buildUntangleSets(ge, dim, data, numRings, set.elements, fixed);

    std::set<MVertex *, MVertexPtrLessThan> nodes;
    for(auto e : set.elements)
      for(std::size_t j = 0; j < e->getNumVertices(); j++)
        nodes.insert(e->getVertex(j));
    for(auto v : nodes) {
      v->setIndex((int)set.nodes.size());
      set.nodes.push_back(v);
      set.locked.push_back(fixed.find(v) != fixed.end());
    }
    // second pass, once the columns have been cut back: the layers stay in
    // place and only the elements around them are untangled
    if(lockLayers) {
      for(auto e : set.elements) {
        if(!data.has(e)) continue;
        for(std::size_t j = 0; j < e->getNumVertices(); j++)
          set.locked[e->getVertex(j)->getIndex()] = true;
      }
    }
  }

} // namespace

// Weights of the size of the elements in the untangling: the elements of the
// layers must reach their thickness, the others only keep their shape and are
// free to shrink
static const double layerSizeWeight = 10.;
static const double outsideSizeWeight = 0.01;
// The untangling stops when the elements are valid and the energy decreases by
// less than this fraction in an outer iteration: going further only polishes
// the shape of the elements, at several times the cost
static const double untangleTolerance = 1.e-3;

// With lockLayers the untangling only repairs the elements around layers that
// are already in place: shorter runs and a looser stopping test are enough
static void setUntangleOptions(WinslowUntangler::Options &options,
                               bool lockLayers)
{
  options.strictFailures = true;
  options.energyTolerance = untangleTolerance;
  if(lockLayers) {
    options.energyTolerance = 10. * untangleTolerance;
    options.maxInnerIterations = 100;
  }
}

// Target thickness of the layers
//
// Each wall node has a target thickness: the requested one, reduced where
// another part of the boundary faces the wall at a short distance, so that the
// layers fit in thin gaps. The untangling inflates the layers towards the
// target, the columns are then cut back where they exceed it, and split in
// layers of the requested first height and growth ratio as far as their final
// height allows.

// Fraction of a gap a layer may fill, when the boundary across the gap carries
// layers as well and when it does not
static const double gapFractionFacingWall = 1. / 3.;
static const double gapFractionFacingOther = 1. / 2.;
// Largest variation of the target thickness per unit length along the wall
static const double thicknessGradation = 0.3;
// Smallest target thickness, as a fraction of the requested one
static const double thicknessFloor = 0.02;

// A piece of the boundary of the meshed domain: a triangle in 3D or a segment
// in 2D
struct BoundaryPiece {
  SPoint3 p[3];
  int n; // number of points: 2 or 3
  SVector3 dir; // unit normal of the triangle, unit tangent of the segment
  bool wall; // on a boundary carrying layers
};

// A wall node seen from one of its wall elements
struct WallSample {
  MVertex *v;
  SVector3 normal; // unit normal of the wall element, towards the domain
  SVector3 surfaceNormal; // 2D: unit normal of the surface
};

struct WallData {
  std::vector<WallSample> samples;
  std::vector<BoundaryPiece> pieces;
  std::vector<std::pair<MVertex *, MVertex *>> edges; // of the wall elements
};

static SPoint3 closestPointOnSegment(const SPoint3 &a, const SPoint3 &b,
                                     const SPoint3 &p)
{
  SVector3 ab(a, b), ap(a, p);
  double l2 = dot(ab, ab);
  double t = (l2 > 0.) ? std::max(0., std::min(1., dot(ap, ab) / l2)) : 0.;
  return a + ab * t;
}

static SPoint3 closestPointOnTriangle(const SPoint3 &a, const SPoint3 &b,
                                      const SPoint3 &c, const SPoint3 &p)
{
  // Real-Time Collision Detection, C. Ericson, 5.1.5
  SVector3 ab(a, b), ac(a, c), ap(a, p);
  double d1 = dot(ab, ap), d2 = dot(ac, ap);
  if(d1 <= 0. && d2 <= 0.) return a;
  SVector3 bp(b, p);
  double d3 = dot(ab, bp), d4 = dot(ac, bp);
  if(d3 >= 0. && d4 <= d3) return b;
  double vc = d1 * d4 - d3 * d2;
  if(vc <= 0. && d1 >= 0. && d3 <= 0.) return a + ab * (d1 / (d1 - d3));
  SVector3 cp(c, p);
  double d5 = dot(ab, cp), d6 = dot(ac, cp);
  if(d6 >= 0. && d5 <= d6) return c;
  double vb = d5 * d2 - d1 * d6;
  if(vb <= 0. && d2 >= 0. && d6 <= 0.) return a + ac * (d2 / (d2 - d6));
  double va = d3 * d6 - d5 * d4;
  if(va <= 0. && (d4 - d3) >= 0. && (d5 - d6) >= 0.)
    return b + SVector3(b, c) * ((d4 - d3) / ((d4 - d3) + (d5 - d6)));
  double denom = 1. / (va + vb + vc);
  return a + ab * (vb * denom) + ac * (vc * denom);
}

// Reduce the target thickness of the wall nodes facing another part of the
// boundary. The gap seen from a wall node along the normal n of a wall element
// is the diameter |d|^2 / (d . n) of the sphere tangent to the wall at the node
// that touches the boundary at the point at d from the node. Only the pieces
// of the boundary roughly parallel to the wall element count: around a concave
// corner the layers of both walls share a column and do not collide.
static void limitThicknessToGaps(const WallData &wall, double maxThickness,
                                 std::map<MVertex *, double> &thickness)
{
  if(wall.samples.empty() || maxThickness <= 0.) return;
  // nothing farther than this can reduce the thickness
  const double R = maxThickness / gapFractionFacingWall;

  // the wall samples, in a grid of cells of size R
  struct Cell {
    long i, j, k;
    bool operator<(const Cell &o) const
    {
      if(i != o.i) return i < o.i;
      if(j != o.j) return j < o.j;
      return k < o.k;
    }
  };
  auto cellOf = [&](const SPoint3 &p) {
    return Cell{(long)std::floor(p.x() / R), (long)std::floor(p.y() / R),
                (long)std::floor(p.z() / R)};
  };
  std::map<Cell, std::vector<std::size_t>> grid;
  for(std::size_t i = 0; i < wall.samples.size(); i++)
    grid[cellOf(wall.samples[i].v->point())].push_back(i);

  auto visit = [&](const BoundaryPiece &piece,
                   const std::vector<std::size_t> &ids) {
    for(auto id : ids) {
      const WallSample &sample = wall.samples[id];
      SPoint3 p = sample.v->point();
      SPoint3 q =
        (piece.n == 3) ?
          closestPointOnTriangle(piece.p[0], piece.p[1], piece.p[2], p) :
          closestPointOnSegment(piece.p[0], piece.p[1], p);
      SVector3 d(p, q);
      double dist = d.norm();
      if(dist < 1.e-12 * R || dist > R) continue;
      double dn = dot(d, sample.normal);
      if(dn < 1.e-6 * dist) continue;
      SVector3 pieceNormal = piece.dir;
      if(piece.n == 2) {
        pieceNormal = crossprod(sample.surfaceNormal, piece.dir);
        double l = pieceNormal.norm();
        if(l <= 0.) continue;
        pieceNormal *= 1. / l;
      }
      if(std::abs(dot(pieceNormal, sample.normal)) < 0.5) continue;
      double gap = dist * dist / dn;
      double limit =
        gap * (piece.wall ? gapFractionFacingWall : gapFractionFacingOther);
      auto it = thickness.find(sample.v);
      if(it != thickness.end() && limit < it->second) it->second = limit;
    }
  };

  for(const auto &piece : wall.pieces) {
    SPoint3 lo = piece.p[0], hi = piece.p[0];
    for(int i = 1; i < piece.n; i++)
      for(int k = 0; k < 3; k++) {
        lo[k] = std::min(lo[k], piece.p[i][k]);
        hi[k] = std::max(hi[k], piece.p[i][k]);
      }
    for(int k = 0; k < 3; k++) {
      lo[k] -= R;
      hi[k] += R;
    }
    Cell c0 = cellOf(lo), c1 = cellOf(hi);
    double numCells = double(c1.i - c0.i + 1) * double(c1.j - c0.j + 1) *
                      double(c1.k - c0.k + 1);
    if(numCells > (double)grid.size()) {
      // a large piece: go through the cells holding samples instead
      for(const auto &cell : grid) {
        const Cell &c = cell.first;
        if(c.i < c0.i || c.i > c1.i || c.j < c0.j || c.j > c1.j || c.k < c0.k ||
           c.k > c1.k)
          continue;
        visit(piece, cell.second);
      }
    }
    else {
      for(long i = c0.i; i <= c1.i; i++)
        for(long j = c0.j; j <= c1.j; j++)
          for(long k = c0.k; k <= c1.k; k++) {
            auto it = grid.find(Cell{i, j, k});
            if(it != grid.end()) visit(piece, it->second);
          }
    }
  }
}

// Limit the variation of the target thickness along the wall
static void smoothThickness(const WallData &wall,
                            std::map<MVertex *, double> &thickness)
{
  for(int iter = 0; iter < 1000; iter++) {
    bool changed = false;
    for(const auto &edge : wall.edges) {
      auto it0 = thickness.find(edge.first);
      auto it1 = thickness.find(edge.second);
      if(it0 == thickness.end() || it1 == thickness.end()) continue;
      double l = thicknessGradation * edge.first->distance(edge.second);
      if(it0->second > it1->second + l * (1. + 1.e-12)) {
        it0->second = it1->second + l;
        changed = true;
      }
      else if(it1->second > it0->second + l * (1. + 1.e-12)) {
        it1->second = it0->second + l;
        changed = true;
      }
    }
    if(!changed) break;
  }
}

// True if the elements of the volume are positively oriented
static bool isPositive(GRegion *gr)
{
  double volume = 0.;
  for(auto t : gr->tetrahedra) {
    std::array<double, 3> p[4];
    for(int k = 0; k < 4; k++)
      p[k] = {t->getVertex(k)->x(), t->getVertex(k)->y(), t->getVertex(k)->z()};
    // tetVolume() has the sign of the untangler, opposite to the one of Gmsh
    volume -= tetVolume(p[0], p[1], p[2], p[3]);
  }
  return volume >= 0.;
}

// Unit normal of the wall face of a layer element of a volume, towards the
// inside of the volume
static bool wallNormal(const LayerColumns &lc, bool positive, SVector3 &normal)
{
  if(lc.n < 3) return false;
  SVector3 t1(lc.wall[0]->point(), lc.wall[1]->point());
  SVector3 t2(lc.wall[0]->point(), lc.wall[lc.n - 1]->point());
  normal = positive ? crossprod(t1, t2) : crossprod(t2, t1);
  double l = normal.norm();
  if(l <= 0.) return false;
  normal *= 1. / l;
  return true;
}

// Normal of the surface from its parametrization: unlike GFace::normal() it is
// defined on the boundary of the surface, where the wall nodes are, and its
// orientation does not change over the surface
static SVector3 parametricNormal(GFace *gf, const SPoint2 &param)
{
  std::pair<SVector3, SVector3> der = gf->firstDer(param);
  SVector3 n = crossprod(der.first, der.second);
  double l = n.norm();
  if(l <= 0.) return gf->normal(param);
  return n * (1. / l);
}

// +1 if the elements of the surface are oriented as its normal, -1 otherwise
static double meshOrientation(GFace *gf, const LayerData &data)
{
  for(std::size_t i = 0; i < gf->getNumMeshElements(); i++) {
    MElement *e = gf->getMeshElement(i);
    if(e->getDim() != 2 || data.elements.find(e) != data.elements.end())
      continue;
    SVector3 n =
      crossprod(SVector3(e->getVertex(0)->point(), e->getVertex(1)->point()),
                SVector3(e->getVertex(0)->point(), e->getVertex(2)->point()));
    SPoint2 param;
    if(n.norm() <= 0. || !reparamOnFace(e->getVertex(0), gf, param)) continue;
    return dot(n, parametricNormal(gf, param)) >= 0. ? 1. : -1.;
  }
  return 1.;
}

// Unit normal, in the surface and towards its inside, of the wall edge of a
// layer element of a surface
static bool wallNormal(GFace *gf, const LayerColumns &lc, double orientation,
                       SVector3 &normal, SVector3 &surfaceNormal)
{
  if(lc.n != 2) return false;
  SPoint2 param;
  if(!reparamOnFace(lc.wall[0], gf, param)) return false;
  surfaceNormal = parametricNormal(gf, param) * orientation;
  SVector3 t(lc.wall[0]->point(), lc.wall[1]->point());
  normal = crossprod(surfaceNormal, t);
  double l = normal.norm();
  if(l <= 0.) return false;
  normal *= 1. / l;
  return true;
}

static void addWallElements(GRegion *gr, const LayerData &data, WallData &wall)
{
  bool positive = isPositive(gr);
  for(std::size_t i = 0; i < gr->getNumMeshElements(); i++) {
    MElement *e = gr->getMeshElement(i);
    if(data.elements.find(e) == data.elements.end()) continue;
    LayerColumns lc;
    SVector3 normal;
    if(!getLayerColumns(e, data, lc) || !wallNormal(lc, positive, normal))
      continue;
    for(std::size_t j = 0; j < lc.n; j++) {
      wall.samples.push_back({lc.wall[j], normal, SVector3()});
      wall.edges.push_back(std::make_pair(lc.wall[j], lc.wall[(j + 1) % lc.n]));
    }
  }
}

static void addBoundaryPieces(GFace *gf, bool isWall, WallData &wall)
{
  for(std::size_t i = 0; i < gf->getNumMeshElements(); i++) {
    MElement *e = gf->getMeshElement(i);
    std::size_t n = e->getNumPrimaryVertices();
    if(e->getDim() != 2 || (n != 3 && n != 4)) continue;
    for(std::size_t k = 0; k + 2 < n; k++) {
      BoundaryPiece piece;
      piece.n = 3;
      piece.p[0] = e->getVertex(0)->point();
      piece.p[1] = e->getVertex(k + 1)->point();
      piece.p[2] = e->getVertex(k + 2)->point();
      piece.dir = crossprod(SVector3(piece.p[0], piece.p[1]),
                            SVector3(piece.p[0], piece.p[2]));
      double l = piece.dir.norm();
      if(l <= 0.) continue;
      piece.dir *= 1. / l;
      piece.wall = isWall;
      wall.pieces.push_back(piece);
    }
  }
}

static void addWallElements(GFace *gf, const LayerData &data, WallData &wall)
{
  double orientation = meshOrientation(gf, data);
  for(std::size_t i = 0; i < gf->getNumMeshElements(); i++) {
    MElement *e = gf->getMeshElement(i);
    if(data.elements.find(e) == data.elements.end()) continue;
    LayerColumns lc;
    SVector3 normal, surfaceNormal;
    if(!getLayerColumns(e, data, lc) ||
       !wallNormal(gf, lc, orientation, normal, surfaceNormal))
      continue;
    for(int j = 0; j < 2; j++)
      wall.samples.push_back({lc.wall[j], normal, surfaceNormal});
    wall.edges.push_back(std::make_pair(lc.wall[0], lc.wall[1]));
  }
}

static void addBoundaryPieces(GEdge *ge, bool isWall, WallData &wall)
{
  for(auto l : ge->lines) {
    BoundaryPiece piece;
    piece.n = 2;
    piece.p[0] = l->getVertex(0)->point();
    piece.p[1] = l->getVertex(1)->point();
    piece.dir = SVector3(piece.p[0], piece.p[1]);
    double len = piece.dir.norm();
    if(len <= 0.) continue;
    piece.dir *= 1. / len;
    piece.wall = isWall;
    wall.pieces.push_back(piece);
  }
}

// The target thickness of each wall node. The requested thickness is uniform
// for now: a thickness depending on the position, e.g. proportional to the
// size of the wall elements, only has to be set here.
static void computeWallThickness(const WallData &wall, double thickness,
                                 LayerData &data)
{
  for(const auto &sample : wall.samples)
    data.wallThickness[sample.v] = thickness;
  double maxThickness = 0.;
  for(const auto &t : data.wallThickness)
    maxThickness = std::max(maxThickness, t.second);

  limitThicknessToGaps(wall, maxThickness, data.wallThickness);
  for(auto &t : data.wallThickness)
    t.second = std::max(t.second, thicknessFloor * thickness);
  // no thickness where the layers are pinched: the smoothing tapers the
  // layers towards those nodes
  for(auto v : data.pinchedNodes) {
    auto it = data.wallThickness.find(v);
    if(it != data.wallThickness.end()) it->second = 0.;
  }
  smoothThickness(wall, data.wallThickness);

  std::size_t numReduced = 0;
  double minThickness = maxThickness;
  for(const auto &t : data.wallThickness) {
    if(t.second <= 0.) continue;
    if(t.second < thickness * (1. - 1.e-9)) numReduced++;
    minThickness = std::min(minThickness, t.second);
  }
  if(numReduced)
    Msg::Info("Boundary layer: thickness reduced on %zu of %zu wall nodes, in "
              "gaps or towards pinched nodes (smallest: %g)",
              numReduced, data.wallThickness.size(), minThickness);
}

// Move node top at the given fraction of the column going from the wall node
// to it, staying on the entity it is classified on
static void moveOnColumn(MVertex *wallNode, MVertex *top, double fraction)
{
  GEntity *ge = top->onWhat();
  if(ge->dim() == 2) {
    GFace *gf = static_cast<GFace *>(ge);
    SPoint2 p0, p1;
    if(reparamOnFace(wallNode, gf, p0) && reparamOnFace(top, gf, p1)) {
      SPoint2 p = p0 + (p1 - p0) * fraction;
      GPoint gp = gf->point(p.x(), p.y());
      top->setXYZ(gp.x(), gp.y(), gp.z());
      top->setParameter(0, p.x());
      top->setParameter(1, p.y());
    }
  }
  else if(ge->dim() == 1) {
    GEdge *gc = static_cast<GEdge *>(ge);
    double p0, p1;
    if(reparamMeshVertexOnEdge(wallNode, gc, p0) &&
       reparamMeshVertexOnEdge(top, gc, p1)) {
      double p = p0 + fraction * (p1 - p0);
      GPoint gp = gc->point(p);
      top->setXYZ(gp.x(), gp.y(), gp.z());
      top->setParameter(0, p);
    }
  }
  else {
    SPoint3 p0 = wallNode->point(), p1 = top->point();
    SPoint3 p = p0 + SVector3(p0, p1) * fraction;
    top->setXYZ(p.x(), p.y(), p.z());
  }
}

static void addColumn(LayerData &data, MVertex *wallNode, MVertex *top,
                      const SVector3 &normal)
{
  SVector3 d(wallNode->point(), top->point());
  double l = d.norm();
  double c = (l > 0.) ? std::abs(dot(d, normal)) / l : 1.;
  Column &column = data.columns[top];
  column.wall = wallNode;
  column.cosine = std::max(column.cosine, c);
}

// Cut back the columns classified on the entity that are higher than the
// target thickness of their wall node. Return the number of columns cut.
static std::size_t clampColumns(GEntity *ge, LayerData &data)
{
  std::size_t numClamped = 0;
  for(auto &c : data.columns) {
    MVertex *top = c.first;
    if(top->onWhat() != ge) continue;
    auto it = data.wallThickness.find(c.second.wall);
    if(it == data.wallThickness.end()) continue;
    double l = top->distance(c.second.wall);
    double maxLength = it->second / std::max(c.second.cosine, 0.1);
    if(l > maxLength * (1. + 1.e-6)) {
      moveOnColumn(c.second.wall, top, maxLength / l);
      data.moved.insert(top);
      numClamped++;
    }
  }
  return numClamped;
}

static void collectColumns(GRegion *gr, LayerData &data)
{
  bool positive = isPositive(gr);
  for(std::size_t i = 0; i < gr->getNumMeshElements(); i++) {
    MElement *e = gr->getMeshElement(i);
    if(data.elements.find(e) == data.elements.end()) continue;
    LayerColumns lc;
    SVector3 normal;
    if(!getLayerColumns(e, data, lc) || !wallNormal(lc, positive, normal))
      continue;
    for(std::size_t j = 0; j < lc.n; j++)
      if(lc.top[j]) addColumn(data, lc.wall[j], lc.top[j], normal);
  }
}

static void collectColumns(GFace *gf, LayerData &data)
{
  double orientation = meshOrientation(gf, data);
  for(std::size_t i = 0; i < gf->getNumMeshElements(); i++) {
    MElement *e = gf->getMeshElement(i);
    if(data.elements.find(e) == data.elements.end()) continue;
    LayerColumns lc;
    SVector3 normal, surfaceNormal;
    if(!getLayerColumns(e, data, lc) ||
       !wallNormal(gf, lc, orientation, normal, surfaceNormal))
      continue;
    for(int j = 0; j < 2; j++)
      if(lc.top[j]) addColumn(data, lc.wall[j], lc.top[j], normal);
  }
}

// Inflation of the layers
//
// The layers and the rings of elements around them are untangled: the ideal
// shape of a layer element has the target thickness of its wall nodes, the
// ideal shape of the other elements is their initial one. The nodes on the
// boundary of the surface or of the volume do not move: curves are done
// first, then surfaces, then volumes.

// Ideal position, in the parametric plane of the surface, of the two wall
// nodes of a layer element and of the nodes at the top of their columns. For a
// plane surface a local frame is used, with the wall edge along the first
// axis.
struct LayerCorners {
  std::array<double, 2> wall[2], top[2];
};

static LayerCorners idealLayerCorners(GFace *gf, double area, MVertex *w0,
                                      MVertex *w1, double thickness0,
                                      double thickness1)
{
  LayerCorners c;
  double dx = distance(w0, w1);
  c.wall[0] = {0., 0.};
  c.wall[1] = {dx, 0.};
  c.top[1] = {dx, thickness1};
  c.top[0] = {0., thickness0};
  if(gf->geomType() == GEntity::Plane) return c;

  SPoint2 param0, param1;
  if(!reparamOnFace(w0, gf, param0) || !reparamOnFace(w1, gf, param1)) return c;
  SPoint3 point0 = w0->point();
  SPoint3 point1 = w1->point();
  SVector3 edgeDirection(point0, point1);
  if(edgeDirection.norm() <= 0.) return c;
  edgeDirection.normalize();
  SVector3 layerDirection0 = crossprod(gf->normal(param0), edgeDirection);
  SVector3 layerDirection1 = crossprod(gf->normal(param1), edgeDirection);
  if(layerDirection0.norm() <= 0. || layerDirection1.norm() <= 0.) return c;
  layerDirection0.normalize();
  layerDirection1.normalize();
  // the layer lies on the side of the wall that gives the element the
  // orientation of the other elements in the parametric plane, whatever the
  // orientation of the normal
  for(double side : {1., -1.}) {
    SPoint3 query0 = point0 + layerDirection0 * (side * thickness0);
    SPoint3 query1 = point1 + layerDirection1 * (side * thickness1);
    double guess0[2] = {param0.x(), param0.y()};
    double guess1[2] = {param1.x(), param1.y()};
    GPoint closest0 = gf->closestPoint(query0, guess0);
    GPoint closest1 = gf->closestPoint(query1, guess1);
    c.wall[0] = {param0.x(), param0.y()};
    c.wall[1] = {param1.x(), param1.y()};
    c.top[1] = {closest1.u(), closest1.v()};
    c.top[0] = {closest0.u(), closest0.v()};
    if(triangleArea2D(c.wall[0], c.wall[1], c.top[1]) * area > 0.) break;
  }
  return c;
}

// When three nodes of a layer quad are on the boundary of the surface, its
// ideal shape is the parallelogram they define
static void useBoundaryParallelogram(GFace *gf, MElement *e, LayerCorners &c)
{
  // the nodes of the quad, in order
  std::array<double, 2> *corner[4] = {&c.wall[0], &c.wall[1], &c.top[1],
                                      &c.top[0]};
  std::array<double, 2> boundaryParam[4];
  int numBoundaryVertices = 0, freeVertex = -1;
  for(int j = 0; j < 4; j++) {
    if(e->getVertex(j)->onWhat()->dim() < 2) {
      SPoint2 param;
      if(reparamOnFace(e->getVertex(j), gf, param)) {
        boundaryParam[j] = {param.x(), param.y()};
        numBoundaryVertices++;
      }
    }
    else
      freeVertex = j;
  }
  if(numBoundaryVertices != 3 || freeVertex < 0) return;
  for(int j = 0; j < 4; j++)
    if(j != freeVertex) *corner[j] = boundaryParam[j];
  // the free corner closes the parallelogram: next + previous - opposite
  const std::array<double, 2> &next = *corner[(freeVertex + 1) % 4];
  const std::array<double, 2> &opposite = *corner[(freeVertex + 2) % 4];
  const std::array<double, 2> &previous = *corner[(freeVertex + 3) % 4];
  *corner[freeVertex] = {next[0] + previous[0] - opposite[0],
                         next[1] + previous[1] - opposite[1]};
}

// Ideal shape of a layer element of a surface, positively oriented: mirrored,
// as the nodes of the elements are, when the mesh of the surface is negative
// in the parametric plane
static bool idealLayerShape(GFace *gf, MElement *e, const LayerData &data,
                            double area, double thickness,
                            std::array<std::array<double, 2>, 4> &vs)
{
  LayerColumns lc;
  if(!getLayerColumns(e, data, lc) || lc.n != 2) {
    Msg::Error("Boundary layer: unknown layer element %zu", e->getNum());
    return false;
  }
  LayerCorners c = idealLayerCorners(gf, area, lc.wall[0], lc.wall[1],
                                     data.thicknessAt(lc.wall[0], thickness),
                                     data.thicknessAt(lc.wall[1], thickness));
  if(e->getNumVertices() == 4) {
    useBoundaryParallelogram(gf, e, c);
    vs = {c.wall[0], c.wall[1], c.top[1], c.top[0]};
    if(triangleArea2D(vs[0], vs[1], vs[2]) < 0.) {
      std::swap(vs[0], vs[1]);
      std::swap(vs[2], vs[3]);
    }
  }
  else {
    // pinched: the quad it would have been, without the node missing at the
    // top of one of its columns
    for(int k = 0; k < 3; k++) {
      MVertex *v = e->getVertex(k);
      vs[k] = (v == lc.wall[0]) ? c.wall[0] :
              (v == lc.wall[1]) ? c.wall[1] :
              (v == lc.top[0])  ? c.top[0] :
                                  c.top[1];
    }
    double a = triangleArea2D(vs[0], vs[1], vs[2]);
    if((area > 0) ? (a < 0) : (a > 0))
      for(int k = 0; k < 3; k++) vs[k][0] = -vs[k][0];
    if(area <= 0) std::swap(vs[0], vs[1]);
  }
  return true;
}

// Start the inflation of the layers from columns that have their target
// thickness: each node spawned in the volume (or on the surface) is moved
// along the mean normal of the wall elements around its wall node, further
// where these normals diverge so that the layer has its thickness above each
// of them. The elements around may end up tangled: the untangling takes care
// of them, from a much better start than layers without thickness.
struct ColumnTop {
  MVertex *wall = nullptr;
  SVector3 normal; // sum of the normals of the wall elements
  int numNormals = 0;

  // where the top of the column goes
  bool target(const LayerData &data, SPoint3 &p) const
  {
    double length = normal.norm();
    if(length <= 0.) return false;
    // norm of the mean normal: 1 on a smooth wall, the cosine of the angle
    // between the column and the walls on a concave edge
    double spread = std::max(length / numNormals, 0.3);
    double thickness = data.thicknessAt(wall, 0.);
    p = wall->point() + normal * (thickness / spread / length);
    return true;
  }
};

static void placeColumnTops(GRegion *gr, const LayerData &data)
{
  std::map<MVertex *, ColumnTop, MVertexPtrLessThan> tops;
  bool positive = isPositive(gr);
  for(std::size_t i = 0; i < gr->getNumMeshElements(); i++) {
    MElement *e = gr->getMeshElement(i);
    if(!data.has(e)) continue;
    LayerColumns lc;
    SVector3 normal;
    if(!getLayerColumns(e, data, lc) || !wallNormal(lc, positive, normal))
      continue;
    for(std::size_t j = 0; j < lc.n; j++) {
      if(!lc.top[j] || lc.top[j]->onWhat() != gr) continue;
      ColumnTop &top = tops[lc.top[j]];
      top.wall = lc.wall[j];
      top.normal += normal;
      top.numNormals++;
    }
  }
  for(auto &t : tops) {
    SPoint3 p;
    if(t.second.target(data, p)) t.first->setXYZ(p.x(), p.y(), p.z());
  }
}

// On a surface the target is projected on it
static void placeColumnTops(GFace *gf, const LayerData &data)
{
  std::map<MVertex *, ColumnTop, MVertexPtrLessThan> tops;
  double orientation = meshOrientation(gf, data);
  for(std::size_t i = 0; i < gf->getNumMeshElements(); i++) {
    MElement *e = gf->getMeshElement(i);
    if(!data.has(e)) continue;
    LayerColumns lc;
    SVector3 normal, surfaceNormal;
    if(!getLayerColumns(e, data, lc) ||
       !wallNormal(gf, lc, orientation, normal, surfaceNormal))
      continue;
    for(std::size_t j = 0; j < lc.n; j++) {
      if(!lc.top[j] || lc.top[j]->onWhat() != gf) continue;
      ColumnTop &top = tops[lc.top[j]];
      top.wall = lc.wall[j];
      top.normal += normal;
      top.numNormals++;
    }
  }
  for(auto &t : tops) {
    SPoint3 p;
    SPoint2 param;
    if(!t.second.target(data, p) || !reparamOnFace(t.second.wall, gf, param))
      continue;
    double guess[2] = {param.x(), param.y()};
    GPoint gp = gf->closestPoint(p, guess);
    if(!gp.succeeded()) continue;
    t.first->setXYZ(gp.x(), gp.y(), gp.z());
    t.first->setParameter(0, gp.u());
    t.first->setParameter(1, gp.v());
  }
}

// Inflate the layers of a surface, in its parametric plane. With lockLayers
// the layers stay in place and only the elements around them are untangled.
static bool inflateLayers(GFace *gf, LayerData &data, std::size_t numRings,
                          bool lockLayers = false)
{
  if(!lockLayers) placeColumnTops(gf, data);
  UntangleSet set;
  buildUntangleSet(gf, 2, data, numRings, lockLayers, set);

  std::vector<std::array<double, 2>> points;
  for(auto v : set.nodes) {
    SPoint2 param;
    reparamOnFace(v, gf, param);
    points.push_back({param.x(), param.y()});
  }

  // orientation of the elements in the parametric plane
  double area = 0.0;
  for(auto e : set.elements) {
    const std::array<double, 2> &pa = points[e->getVertex(0)->getIndex()];
    const std::array<double, 2> &pb = points[e->getVertex(1)->getIndex()];
    const std::array<double, 2> &pc = points[e->getVertex(2)->getIndex()];
    area += triangleArea2D(pa, pb, pc);
    if(e->getNumVertices() == 4)
      area += triangleArea2D(pa, pc, points[e->getVertex(3)->getIndex()]);
  }

  // The ideal shape of each element and its nodes are split in the same
  // triangles (a double covering for quads), positive for the untangler: the
  // first two nodes are swapped when the mesh is negative.
  std::vector<std::array<std::array<double, 2>, 3>> ideal;
  std::vector<std::array<uint32_t, 3>> triangles;
  std::vector<double> sizeWeight;
  for(auto e : set.elements) {
    std::array<std::array<double, 2>, 4> vs;
    auto it = data.elements.find(e);
    if(it != data.elements.end()) {
      if(!idealLayerShape(gf, e, data, area, it->second, vs)) return false;
    }
    else {
      auto it2 = data.shapes2D.find(e);
      if(it2 == data.shapes2D.end()) {
        Msg::Error("Boundary layer: no initial shape for element %zu",
                   e->getNum());
        return false;
      }
      vs = it2->second;
    }
    const uint32_t a = (uint32_t)e->getVertex(0)->getIndex();
    const uint32_t b = (uint32_t)e->getVertex(1)->getIndex();
    const uint32_t c = (uint32_t)e->getVertex(2)->getIndex();
    const double weight =
      (it != data.elements.end()) ? layerSizeWeight : outsideSizeWeight;
    if(e->getNumVertices() == 3) {
      ideal.push_back({vs[0], vs[1], vs[2]});
      if(area > 0)
        triangles.push_back({a, b, c});
      else
        triangles.push_back({b, a, c});
      sizeWeight.push_back(weight);
    }
    else {
      const uint32_t d = (uint32_t)e->getVertex(3)->getIndex();
      ideal.push_back({vs[0], vs[1], vs[2]});
      ideal.push_back({vs[2], vs[3], vs[0]});
      ideal.push_back({vs[0], vs[1], vs[3]});
      ideal.push_back({vs[1], vs[2], vs[3]});
      if(area > 0) {
        triangles.push_back({a, b, c});
        triangles.push_back({c, d, a});
        triangles.push_back({a, b, d});
        triangles.push_back({b, c, d});
      }
      else {
        triangles.push_back({b, a, d});
        triangles.push_back({d, c, b});
        triangles.push_back({b, a, c});
        triangles.push_back({a, d, c});
      }
      sizeWeight.insert(sizeWeight.end(), 4, weight);
    }
  }

  WinslowUntangler::Options options;
  setUntangleOptions(options, lockLayers);
  options.numThreads = CTX::instance()->numThreadsFor(triangles.size(), 5000);
  options.elementLambda = &sizeWeight;
  bool ok =
    WinslowUntangler::untangle2D(points, set.locked, triangles, ideal, options);
  if(!ok)
    Msg::Warning("Boundary layer: untangling of surface %d did not converge",
                 gf->tag());

  for(std::size_t i = 0; i < set.nodes.size(); i++) {
    if(set.locked[i]) continue;
    MVertex *v = set.nodes[i];
    GPoint gp = gf->point(points[i][0], points[i][1]);
    data.moved.insert(v);
    v->x() = gp.x();
    v->y() = gp.y();
    v->z() = gp.z();
    v->setParameter(0, gp.u());
    v->setParameter(1, gp.v());
  }
  return ok;
}

// Sub-tetrahedra measuring each type of element, positively oriented when the
// element is (a double covering for prisms)
static const int tetSubTets[1][4] = {{0, 1, 2, 3}};
static const int prismSubTets[6][4] = {{0, 1, 2, 3}, {0, 1, 2, 4},
                                       {0, 1, 2, 5}, {4, 3, 5, 0},
                                       {4, 3, 5, 1}, {4, 3, 5, 2}};
static const int hexSubTets[6][4] = {{0, 1, 2, 6}, {0, 2, 3, 6}, {0, 3, 7, 6},
                                     {0, 7, 4, 6}, {0, 4, 5, 6}, {0, 5, 1, 6}};
static const int pyramidSubTets[4][4] = {
  {0, 1, 2, 4}, {0, 2, 3, 4}, {0, 1, 3, 4}, {1, 2, 3, 4}};

// The sub-tetrahedra of an element, and their number (0 if the type of the
// element is not handled)
static int getSubTets(MElement *e, const int (*&sub)[4])
{
  switch(e->getTypeForMSH()) {
  case MSH_TET_4: sub = tetSubTets; return 1;
  case MSH_PRI_6: sub = prismSubTets; return 6;
  case MSH_HEX_8: sub = hexSubTets; return 6;
  case MSH_PYR_5: sub = pyramidSubTets; return 4;
  default: sub = nullptr; return 0;
  }
}

// Inflate the layers of a volume. With lockLayers the layers stay in place and
// only the elements around them are untangled.
static bool inflateLayers(GRegion *gr, LayerData &data, std::size_t numRings,
                          bool lockLayers = false)
{
  if(!lockLayers) placeColumnTops(gr, data);
  UntangleSet set;
  buildUntangleSet(gr, 3, data, numRings, lockLayers, set);

  std::vector<std::array<double, 3>> points;
  for(auto v : set.nodes) points.push_back({v->x(), v->y(), v->z()});

  // orientation of the elements of the volume: the layer elements are flat,
  // and were created with the orientation of the other elements
  double volume = 0.0;
  for(auto e : set.elements) {
    const int (*sub)[4];
    if(!getSubTets(e, sub)) continue;
    // tetVolume() has the sign of the untangler, opposite to the one of Gmsh
    volume -= tetVolume(points[e->getVertex(sub[0][0])->getIndex()],
                        points[e->getVertex(sub[0][1])->getIndex()],
                        points[e->getVertex(sub[0][2])->getIndex()],
                        points[e->getVertex(sub[0][3])->getIndex()]);
  }
  const bool positive = (volume > 0);

  // The ideal shape of each element and its nodes are split with the same
  // sub-tetrahedra. The untangler wants left-handed tetrahedra, i.e. negative
  // ones for Gmsh, hence the swap of the first two nodes of each of them when
  // the elements are positive.
  std::vector<std::array<std::array<double, 3>, 4>> ideal;
  std::vector<std::array<uint32_t, 4>> tets;
  std::vector<double> sizeWeight;
  for(auto e : set.elements) {
    const int (*sub)[4];
    const int numSub = getSubTets(e, sub);
    if(!numSub) continue;

    std::array<std::array<double, 3>, 8> vs = {};
    auto it = data.elements.find(e);
    LayerColumns lc;
    if(it != data.elements.end() && getLayerColumns(e, data, lc) && lc.n >= 3) {
      // the wall face of the element, each node extruded along the normal of
      // the face by its thickness, towards the inside of the volume; a
      // pinched element is the same without the nodes it lost
      SVector3 normal;
      if(!wallNormal(lc, positive, normal)) {
        Msg::Error("Boundary layer: flat wall face on element %zu",
                   e->getNum());
        return false;
      }
      for(std::size_t k = 0; k < e->getNumVertices(); k++) {
        MVertex *v = e->getVertex(k);
        for(std::size_t j = 0; j < lc.n; j++) {
          MVertex *w = lc.wall[j];
          if(v == w)
            vs[k] = {w->x(), w->y(), w->z()};
          else if(v == lc.top[j]) {
            const double t = data.thicknessAt(w, it->second);
            vs[k] = {w->x() + normal.x() * t, w->y() + normal.y() * t,
                     w->z() + normal.z() * t};
          }
        }
      }
    }
    else {
      for(std::size_t k = 0; k < e->getNumVertices(); k++) {
        const std::size_t num = e->getVertex(k)->getNum();
        if(num >= data.positions.size()) {
          Msg::Error("Boundary layer: no initial position for node %zu", num);
          return false;
        }
        vs[k] = data.positions[num];
      }
    }

    for(int j = 0; j < numSub; j++) {
      int k[4] = {sub[j][0], sub[j][1], sub[j][2], sub[j][3]};
      if(positive) std::swap(k[0], k[1]);
      ideal.push_back({vs[k[0]], vs[k[1]], vs[k[2]], vs[k[3]]});
      tets.push_back({(uint32_t)e->getVertex(k[0])->getIndex(),
                      (uint32_t)e->getVertex(k[1])->getIndex(),
                      (uint32_t)e->getVertex(k[2])->getIndex(),
                      (uint32_t)e->getVertex(k[3])->getIndex()});
      sizeWeight.push_back(it != data.elements.end() ? layerSizeWeight :
                                                       outsideSizeWeight);
    }
  }

  double tUntangle = TimeOfDay();
  WinslowUntangler::Options options;
  setUntangleOptions(options, lockLayers);
  options.numThreads = CTX::instance()->numThreadsFor(tets.size(), 5000);
  options.elementLambda = &sizeWeight;
  bool ok =
    WinslowUntangler::untangle3D(points, set.locked, tets, ideal, options);
  if(!ok)
    Msg::Warning("Boundary layer: untangling of volume %d did not converge",
                 gr->tag());
  Msg::Info("Boundary layer: volume %d untangled in %g s", gr->tag(),
            TimeOfDay() - tUntangle);

  for(std::size_t i = 0; i < set.nodes.size(); i++) {
    if(set.locked[i]) continue;
    set.nodes[i]->setXYZ(points[i][0], points[i][1], points[i][2]);
  }
  return ok;
}

// Number of elements of the volume that are flat or inverted with respect to
// the others
static std::size_t countInvalidElements(GRegion *gr)
{
  std::size_t numPositive = 0, numNegative = 0, numFlat = 0;
  for(std::size_t i = 0; i < gr->getNumMeshElements(); i++) {
    MElement *e = gr->getMeshElement(i);
    const int (*sub)[4];
    const int numSub = getSubTets(e, sub);
    if(!numSub) continue;
    bool pos = true, neg = true;
    for(int j = 0; j < numSub; j++) {
      std::array<double, 3> p[4];
      for(int k = 0; k < 4; k++) {
        MVertex *v = e->getVertex(sub[j][k]);
        p[k] = {v->x(), v->y(), v->z()};
      }
      double vol = -tetVolume(p[0], p[1], p[2], p[3]);
      if(vol <= 0.) pos = false;
      if(vol >= 0.) neg = false;
    }
    if(pos)
      numPositive++;
    else if(neg)
      numNegative++;
    else
      numFlat++;
  }
  return numFlat + std::min(numPositive, numNegative);
}

// Split of the columns in layers

// The layers of a column: the requested heights when the column is as high as
// their sum, and otherwise
// - the first numExact layers at their requested height, and the others
//   growing from there with a smaller ratio, as long as that ratio is not
//   below 1;
// - below that, each layer at its requested height or at a common height
//   limit, whichever is smaller: the number of exact layers decreases with the
//   height of the column, and the layers end up uniform.
// The layers depend continuously on the height of the column, so that they
// stay smooth along the wall, and no layer is ever higher than requested.
struct LayerLaw {
  std::vector<double> widths; // requested heights
  double ratio = 1.;
  int numExact = 0;

  // heights of the layers of a column of the given height, cumulated and
  // divided by the height
  std::vector<double> fractions(double height) const
  {
    const int N = (int)widths.size();
    std::vector<double> h(widths);
    double total = 0.;
    for(double w : widths) total += w;
    if(height < total) {
      int n = std::max(0, std::min(numExact, N - 1));
      double exact = 0.;
      for(int k = 0; k < n; k++) exact += widths[k];
      double base = n ? widths[n - 1] : widths[0] / ratio;
      double rest = height - exact;
      int m = N - n;
      auto tail = [&](double r) {
        double sum = 0., w = base;
        for(int k = 0; k < m; k++) {
          w *= r;
          sum += w;
        }
        return sum;
      };
      if(rest >= m * base && ratio > 1.) {
        double lo = 1., hi = ratio;
        for(int iter = 0; iter < 100; iter++) {
          double mid = 0.5 * (lo + hi);
          if(tail(mid) > rest)
            hi = mid;
          else
            lo = mid;
        }
        double r = 0.5 * (lo + hi), w = base;
        for(int k = n; k < N; k++) {
          w *= r;
          h[k] = w;
        }
      }
      else {
        double below = 0.;
        for(int k = 0; k < N; k++) {
          double limit = (height - below) / (N - k);
          if(limit <= widths[k]) {
            for(int j = k; j < N; j++) h[j] = limit;
            break;
          }
          below += widths[k];
        }
      }
    }
    double sum = 0.;
    for(double w : h) sum += w;
    std::vector<double> t(N);
    double c = 0.;
    for(int k = 0; k < N; k++) {
      c += h[k];
      t[k] = (sum > 0.) ? c / sum : double(k + 1) / N;
    }
    t[N - 1] = 1.;
    return t;
  }
};

// Classify on the surface a node created in the volume
static void classifyVertexOnFace(GFace *gf, MVertex *v)
{
  if(!gf || !v || !v->onWhat() || v->onWhat()->dim() <= 2) return;

  SPoint3 p = v->point();
  SPoint2 param = gf->parFromPoint(p);
  double guess[2] = {param.x(), param.y()};
  GPoint gp = gf->closestPoint(p, guess);
  v->x() = gp.x();
  v->y() = gp.y();
  v->z() = gp.z();
  v->setParameter(0, gp.u());
  v->setParameter(1, gp.v());
  v->setEntity(gf);
  gf->mesh_vertices.push_back(v);
}

// Split a pinched triangle along its only column, given from the wall
// outwards: a fan of triangles around the pinched node
static void splitPinchedTriangle(GFace *gf, MElement *t,
                                 const std::vector<MVertex *> &column,
                                 LayerData &data,
                                 const std::vector<double> &widths)
{
  int k = 0;
  while(k < 3 &&
        (t->getVertex(k) == column.front() || t->getVertex(k) == column.back()))
    k++;
  if(k == 3) return;
  MVertex *apex = t->getVertex(k);
  bool outwards = (t->getVertex((k + 1) % 3) == column.front());
  for(std::size_t s = 0; s + 1 < column.size(); s++) {
    MVertex *a = outwards ? column[s] : column[s + 1];
    MVertex *b = outwards ? column[s + 1] : column[s];
    MElement *e = t;
    if(s == 0) {
      t->setVertex(0, apex);
      t->setVertex(1, a);
      t->setVertex(2, b);
    }
    else {
      gf->triangles.push_back(new MTriangle(apex, a, b));
      e = gf->triangles.back();
    }
    data.elements[e] = s < widths.size() ? widths[s] : widths.back();
  }
}

static void
splitSideElements(GModel *gm,
                  std::map<MEdge, std::vector<MVertex *>, MEdgeLessThan> &split,
                  LayerData &data, const std::vector<double> &widths)
{
  for(GModel::fiter fit = gm->firstFace(); fit != gm->lastFace(); ++fit) {
    GFace *gf = (*fit);

    // pinched layer elements
    std::vector<MTriangle *> triangles = gf->triangles;
    for(auto t : triangles) {
      if(data.elements.find(t) == data.elements.end()) continue;
      for(int i = 0; i < 3; i++) {
        auto it = split.find(t->getEdge(i));
        if(it == split.end()) continue;
        splitPinchedTriangle(gf, t, it->second, data, widths);
        break;
      }
    }

    std::vector<MQuadrangle *> newVec;
    for(auto q : gf->quadrangles) {
      bool found = false;
      auto itLayer = data.elements.find(q);
      // edges i and i + 2 are opposite: i = 2 and 3 would split the quad again,
      // reversed
      for(size_t i = 0; i < 2 && !found; i++) {
        MEdge ei = q->getEdge(i);
        MEdge ei2 = q->getEdge((i + 2) % 4);
        auto it0 = split.find(ei);
        auto it1 = split.find(ei2);
        if(it0 != split.end() && it1 != split.end()) {
          // both columns are stored from the wall outwards: keep the
          // orientation of the quad, with nodes 0 and 1 along the wall as in
          // the quads created by the boundary layer
          const std::vector<MVertex *> &c0 =
            (it0->second.front() == q->getVertex(i)) ? it1->second :
                                                       it0->second;
          const std::vector<MVertex *> &c1 =
            (it0->second.front() == q->getVertex(i)) ? it0->second :
                                                       it1->second;
          for(size_t j = 0; j < c0.size() - 1; j++) {
            MQuadrangle *nq =
              new MQuadrangle(c0[j], c1[j], c1[j + 1], c0[j + 1]);
            for(int k = 0; k < 4; ++k)
              classifyVertexOnFace(gf, nq->getVertex(k));
            newVec.push_back(nq);
            if(itLayer != data.elements.end())
              data.elements[nq] =
                j < widths.size() ? widths[j] : itLayer->second;
          }
          found = true;
        }
      }
      if(found) {
        if(itLayer != data.elements.end()) data.elements.erase(itLayer);
        delete q;
      }
      else
        newVec.push_back(q);
    }
    gf->quadrangles = newVec;
  }
}

static void
splitSideLines(GModel *gm,
               std::map<MEdge, std::vector<MVertex *>, MEdgeLessThan> &split)
{
  for(GModel::eiter eit = gm->firstEdge(); eit != gm->lastEdge(); ++eit) {
    GEdge *ge = (*eit);
    if(ge->lines.empty()) continue;
    MLine *l0 = ge->lines.front();
    MLine *l1 = ge->lines.back();
    MEdge m0 = MEdge(l0->getVertex(0), l0->getVertex(1));
    MEdge m1 = MEdge(l1->getVertex(0), l1->getVertex(1));
    auto it0 = split.find(m0);
    auto it1 = split.find(m1);

    if(it0 != split.end()) {
      std::vector<MLine *> old = ge->lines;
      ge->lines.clear();
      for(size_t j = 0; j < it0->second.size() - 1; j++)
        ge->lines.push_back(new MLine(it0->second[j], it0->second[j + 1]));
      for(size_t j = 1; j < old.size(); j++) ge->lines.push_back(old[j]);
      delete old.front();
    }
    if(it1 != split.end()) {
      // the last line goes from the spawned node to the model point: the
      // split nodes are stored from the model point outwards
      size_t s = it1->second.size();
      ge->lines.back()->setVertex(1, it1->second[s - 2]);
      for(size_t j = 2; j < s; j++)
        ge->lines.push_back(
          new MLine(it1->second[s - j], it1->second[s - j - 1]));
    }
  }
}

// Split the column going from a wall node to its spawned node in layers
static std::vector<MVertex *>
splitColumn(MEdge me,
            std::map<MEdge, std::vector<MVertex *>, MEdgeLessThan> &split,
            const LayerLaw &law, const LayerData &data)
{
  auto it = split.find(me);
  if(it != split.end()) return it->second;

  // height of the column above the wall
  double height = me.length();
  auto itc = data.columns.find(me.getVertex(1));
  if(itc != data.columns.end()) height *= itc->second.cosine;
  std::vector<double> t = law.fractions(height);

  std::vector<MVertex *> vs;
  vs.push_back(me.getVertex(0));
  if(me.getVertex(1)->onWhat()->dim() == 3) {
    GRegion *gr = static_cast<GRegion *>(me.getVertex(1)->onWhat());
    SPoint3 p0 = me.getVertex(0)->point();
    SPoint3 p1 = me.getVertex(1)->point();
    for(size_t i = 0; i < t.size() - 1; i++) {
      SPoint3 p = p0 + (p1 - p0) * t[i];
      vs.push_back(new MVertex(p.x(), p.y(), p.z(), gr));
      gr->mesh_vertices.push_back(vs.back());
    }
  }
  else if(me.getVertex(1)->onWhat()->dim() == 2) {
    SPoint2 p0, p1;
    GFace *gf = static_cast<GFace *>(me.getVertex(1)->onWhat());
    reparamOnFace(me.getVertex(0), gf, p0);
    reparamOnFace(me.getVertex(1), gf, p1);
    for(size_t i = 0; i < t.size() - 1; i++) {
      SPoint2 p = p0 + (p1 - p0) * t[i];
      GPoint gp = gf->point(p.x(), p.y());
      vs.push_back(new MFaceVertex(gp.x(), gp.y(), gp.z(), gf, p.x(), p.y()));
      gf->mesh_vertices.push_back(vs.back());
    }
  }
  else if(me.getVertex(1)->onWhat()->dim() == 1) {
    double p0, p1;
    GEdge *ge = static_cast<GEdge *>(me.getVertex(1)->onWhat());
    reparamMeshVertexOnEdge(me.getVertex(0), ge, p0);
    reparamMeshVertexOnEdge(me.getVertex(1), ge, p1);
    for(size_t i = 0; i < t.size() - 1; i++) {
      double p = p0 + t[i] * (p1 - p0);
      GPoint gp = ge->point(p);
      vs.push_back(new MEdgeVertex(gp.x(), gp.y(), gp.z(), ge, p));
      ge->mesh_vertices.push_back(vs.back());
    }
  }
  vs.push_back(me.getVertex(1));
  split[me] = vs;
  return vs;
}

// Split the layer elements of the volumes in layers along their columns
static void splitLayers(std::vector<GRegion *> &r, LayerData &data,
                        const LayerLaw &law)
{
  std::map<MEdge, std::vector<MVertex *>, MEdgeLessThan> split;
  const std::vector<double> &widths = law.widths;
  const std::size_t numLayers = widths.size();

  for(auto gr : r) {
    std::vector<MElement *> elements;
    for(size_t i = 0; i < gr->getNumMeshElements(); ++i)
      if(data.elements.find(gr->getMeshElement(i)) != data.elements.end())
        elements.push_back(gr->getMeshElement(i));

    std::set<MElement *> replaced;
    for(auto e : elements) {
      LayerColumns lc;
      if(!getLayerColumns(e, data, lc) || lc.n < 3) continue;
      // the nodes of each column, from the wall outwards; a pinched column
      // stays on its wall node
      std::vector<MVertex *> column[4];
      for(std::size_t j = 0; j < lc.n; j++) {
        if(lc.top[j])
          column[j] =
            splitColumn(MEdge(lc.wall[j], lc.top[j]), split, law, data);
        else
          column[j].assign(numLayers + 1, lc.wall[j]);
      }
      for(std::size_t s = 0; s < numLayers; s++) {
        LayerColumns slab;
        slab.n = lc.n;
        for(std::size_t j = 0; j < lc.n; j++) {
          slab.wall[j] = column[j][s];
          slab.top[j] = lc.top[j] ? column[j][s + 1] : nullptr;
        }
        addLayerElement(gr, slab, widths[s], data);
      }
      replaced.insert(e);
      data.elements.erase(e);
      data.pinched.erase(e);
    }

    auto isReplaced = [&](MElement *e) {
      return replaced.find(e) != replaced.end();
    };
    gr->tetrahedra.erase(
      std::remove_if(gr->tetrahedra.begin(), gr->tetrahedra.end(), isReplaced),
      gr->tetrahedra.end());
    gr->pyramids.erase(
      std::remove_if(gr->pyramids.begin(), gr->pyramids.end(), isReplaced),
      gr->pyramids.end());
    gr->prisms.erase(
      std::remove_if(gr->prisms.begin(), gr->prisms.end(), isReplaced),
      gr->prisms.end());
    gr->hexahedra.erase(
      std::remove_if(gr->hexahedra.begin(), gr->hexahedra.end(), isReplaced),
      gr->hexahedra.end());
    for(auto e : replaced) delete e;
  }

  splitSideLines(r[0]->model(), split);
  splitSideElements(r[0]->model(), split, data, widths);
}

static void splitLayers(std::vector<GFace *> &f, LayerData &data,
                        const LayerLaw &law)
{
  std::map<MEdge, std::vector<MVertex *>, MEdgeLessThan> split;
  const std::vector<double> &widths = law.widths;

  for(auto gf : f) {
    std::vector<MElement *> temp;
    for(size_t i = 0; i < gf->getNumMeshElements(); i++)
      temp.push_back(gf->getMeshElement(i));

    for(size_t i = 0; i < temp.size(); i++) {
      if(data.elements.find(temp[i]) != data.elements.end()) {
        if(temp[i]->getNumEdges() == 3) {
          // pinched layer element: split along its only column
          LayerColumns lc;
          if(!getLayerColumns(temp[i], data, lc) || lc.n != 2) continue;
          int j = lc.top[0] ? 0 : 1;
          std::vector<MVertex *> column =
            splitColumn(MEdge(lc.wall[j], lc.top[j]), split, law, data);
          splitPinchedTriangle(gf, temp[i], column, data, widths);
        }
        else if(temp[i]->getNumEdges() == 4) {
          MEdge m03 = MEdge(temp[i]->getVertex(0), temp[i]->getVertex(3));
          MEdge m12 = MEdge(temp[i]->getVertex(1), temp[i]->getVertex(2));
          std::vector<MVertex *> p03 = splitColumn(m03, split, law, data);
          std::vector<MVertex *> p12 = splitColumn(m12, split, law, data);
          for(size_t j = 0; j < p03.size() - 1; j++) {
            MVertex *v0 = p03[j];
            MVertex *v1 = p12[j];
            MVertex *v2 = p12[j + 1];
            MVertex *v3 = p03[j + 1];
            if(j == 0) {
              temp[i]->setVertex(0, v0);
              temp[i]->setVertex(1, v1);
              temp[i]->setVertex(2, v2);
              temp[i]->setVertex(3, v3);
              data.elements[temp[i]] = widths[j];
            }
            else {
              MQuadrangle *q = new MQuadrangle(v0, v1, v2, v3);
              gf->quadrangles.push_back(q);
              data.elements[q] = widths[j];
            }
          }
        }
      }
    }
  }
  if(!f.empty()) splitSideLines(f[0]->model(), split);
}

// Driver

// Store the shape of the elements of the surfaces in their parametric plane
static void storeInitialShapes(const std::vector<GFace *> &surfaces,
                               LayerData &data)
{
  for(auto gf : surfaces) {
    const std::size_t numElements = gf->getNumMeshElements();
    std::vector<std::array<std::array<double, 2>, 4>> shapes(numElements);
    double area = 0.0;
    for(std::size_t i = 0; i < numElements; i++) {
      MElement *e = gf->getMeshElement(i);
      const std::size_t n = std::min<std::size_t>(e->getNumVertices(), 4);
      std::array<std::array<double, 2>, 4> &vs = shapes[i];
      for(std::size_t j = 0; j < n; j++) {
        SPoint2 param;
        reparamOnFace(e->getVertex(j), gf, param);
        vs[j] = {param.x(), param.y()};
      }
      if(n == 3) {
        vs[3] = vs[2];
        area += triangleArea2D(vs[0], vs[1], vs[2]);
      }
      else if(n == 4) {
        area += triangleArea2D(vs[0], vs[1], vs[2]);
        area += triangleArea2D(vs[0], vs[2], vs[3]);
      }
    }
    // mirrored if the mesh of the surface is negative in the parametric plane
    for(std::size_t i = 0; i < numElements; i++) {
      MElement *e = gf->getMeshElement(i);
      std::array<std::array<double, 2>, 4> &vs = shapes[i];
      if(area <= 0) {
        std::swap(vs[0], vs[1]);
        if(e->getNumVertices() != 3) std::swap(vs[2], vs[3]);
      }
      data.shapes2D[e] = vs;
    }
  }
}

// Store the position of the nodes of the volumes
static void storeInitialShapes(const std::vector<GRegion *> &volumes,
                               LayerData &data)
{
  for(auto gr : volumes) {
    for(size_t i = 0; i < gr->getNumMeshElements(); i++) {
      MElement *e = gr->getMeshElement(i);
      for(size_t j = 0; j < e->getNumVertices(); j++) {
        MVertex *v = e->getVertex(j);
        if(v->getNum() >= data.positions.size())
          data.positions.resize(v->getNum() + 1);
        data.positions[v->getNum()] = {v->x(), v->y(), v->z()};
      }
    }
  }
}

// As many layers as needed to reach the thickness: the last ones are reduced
// in each column to end exactly on it
static LayerLaw layerLaw(double size, double ratio, double thickness,
                         double numExactLayers)
{
  LayerLaw law;
  law.ratio = ratio;
  double height = size, total = 0.;
  while(1) {
    law.widths.push_back(height);
    total += height;
    if(total >= thickness * (1. - 1.e-12) || law.widths.size() >= 1000) break;
    height *= ratio;
  }
  law.numExact =
    (numExactLayers > 0) ? (int)numExactLayers :
    (numExactLayers < 0) ? (int)(law.widths.size() / (-numExactLayers)) :
                           0;
  return law;
}

// The target thickness of the wall nodes of a 2D mesh
static void computeWallThickness(const std::vector<GFace *> &surfaces,
                                 const std::vector<GEdge *> &wallCurves,
                                 double thickness, LayerData &data)
{
  WallData wall;
  std::set<GEdge *> walls(wallCurves.begin(), wallCurves.end());
  std::set<GEdge *, GEntityPtrLessThan> curves;
  for(auto gf : surfaces) {
    addWallElements(gf, data, wall);
    for(auto ge : gf->edges()) curves.insert(ge);
    for(auto ge : gf->embeddedEdges()) curves.insert(ge);
  }
  for(auto ge : curves)
    addBoundaryPieces(ge, walls.find(ge) != walls.end(), wall);
  computeWallThickness(wall, thickness, data);
}

// The target thickness of the wall nodes of a 3D mesh
static void computeWallThickness(const std::vector<GRegion *> &volumes,
                                 const std::vector<GFace *> &wallSurfaces,
                                 double thickness, LayerData &data)
{
  WallData wall;
  std::set<GFace *> walls(wallSurfaces.begin(), wallSurfaces.end());
  std::set<GFace *, GEntityPtrLessThan> surfaces;
  for(auto gr : volumes) {
    addWallElements(gr, data, wall);
    for(auto gf : gr->faces()) surfaces.insert(gf);
    for(auto gf : gr->embeddedFaces()) surfaces.insert(gf);
  }
  for(auto gf : surfaces)
    addBoundaryPieces(gf, walls.find(gf) != walls.end(), wall);
  computeWallThickness(wall, thickness, data);
}

// Move the nodes spawned on the curves at their target thickness from the
// wall, and redistribute the other nodes of these curves
static void inflateLayersOnCurves(GModel *m, LayerData &data)
{
  for(GModel::eiter eit = m->firstEdge(); eit != m->lastEdge(); ++eit) {
    GEdge *ge = *eit;
    // the layers at both ends of a curve take at most a third of it each
    double width[2] = {0., 0.};
    GVertex *gv[2] = {ge->getBeginVertex(), ge->getEndVertex()};
    double maxWidth = ge->length() / 3.;
    for(int i = 0; i < 2; i++) {
      if(!gv[i] || gv[i]->mesh_vertices.empty()) continue;
      width[i] =
        std::min(data.thicknessAt(gv[i]->mesh_vertices[0], 0.), maxWidth);
    }
    std::vector<SPoint3> before;
    for(auto mv : ge->mesh_vertices) before.push_back(mv->point());
    meshGEdgeInsertBoundaryLayer(ge, width[0], width[1]);
    for(std::size_t i = 0; i < before.size(); i++)
      if(before[i].distance(ge->mesh_vertices[i]->point()) > 0.)
        data.moved.insert(ge->mesh_vertices[i]);
  }
}

// Inflate the layers of a surface or of a volume, then cut back the columns
// that exceed their target and untangle again around them. Return the number
// of columns cut.
template <class GEntityT>
static std::size_t inflateAndCutBack(GEntityT *ge, LayerData &data,
                                     std::size_t numRings)
{
  inflateLayers(ge, data, numRings);
  collectColumns(ge, data);
  std::size_t numCut = clampColumns(ge, data);
  if(numCut) inflateLayers(ge, data, numRings, true);
  return numCut;
}

PView *GMSH_BoundaryLayerPlugin::execute(PView *v)
{
  GModel *m = GModel::current();

  // the volumes, surfaces, curves and points
  std::vector<int> tags[4];
  for(int i = 0; i < 4; i++)
    if(!optionIntList(i, tags[i])) return v;
  std::vector<GRegion *> volumes;
  for(auto tag : tags[0]) {
    GRegion *gr = m->getRegionByTag(tag);
    if(gr)
      volumes.push_back(gr);
    else
      Msg::Warning("Boundary layer: unknown volume %d", tag);
  }
  std::vector<GFace *> surfaces;
  for(auto tag : tags[1]) {
    GFace *gf = m->getFaceByTag(tag);
    if(gf)
      surfaces.push_back(gf);
    else
      Msg::Warning("Boundary layer: unknown surface %d", tag);
  }
  std::vector<GEdge *> curves;
  for(auto tag : tags[2]) {
    GEdge *ge = m->getEdgeByTag(tag);
    if(ge)
      curves.push_back(ge);
    else
      Msg::Warning("Boundary layer: unknown curve %d", tag);
  }
  if(!tags[3].empty()) Msg::Warning("Boundary layer: Points is not used yet");
  const bool is3D = !volumes.empty();
  if(is3D && !curves.empty())
    Msg::Warning("Boundary layer: Curves is not used in 3D");

  const double thickness = option(0);
  const double size = option(1);
  const double ratio = option(2);
  int numRings = (int)option(3);
  const double numExactLayers = option(4);
  int highOrder = std::max(1, (int)option(5));
  const int highOrderStrategy = std::max(0, (int)option(6));
  const bool highOrderPostSplitUntangle = ((int)option(7) != 0);
  if(numRings < 1) {
    Msg::Warning("Boundary layer: SmoothingLayers must be at least 1");
    numRings = 1;
  }
  if(size <= 0. || thickness <= 0. || ratio < 1.) {
    Msg::Error("Boundary layer: Size and Thickness must be positive and Ratio "
               "at least 1");
    return v;
  }
  const LayerLaw law = layerLaw(size, ratio, thickness, numExactLayers);

  // insert the layers, with zero thickness; sets of entities are ordered by
  // tag, not by address, so that the result does not change from one run to
  // the next
  double t0 = TimeOfDay();
  auto timing = [&t0](const char *what) {
    double t = TimeOfDay();
    Msg::Debug("Boundary layer: %s in %g s", what, t - t0);
    t0 = t;
  };
  LayerData data;
  std::vector<GFace *> sideSurfaces;
  std::vector<GEntity *> domains;
  std::set<GEntity *, GEntityPtrLessThan> walls;
  if(is3D) {
    domains.assign(volumes.begin(), volumes.end());
    walls.insert(surfaces.begin(), surfaces.end());
  }
  else {
    domains.assign(surfaces.begin(), surfaces.end());
    walls.insert(curves.begin(), curves.end());
  }
  if(!insertLayers(m, is3D ? 3 : 2, domains, walls, thickness, data,
                   sideSurfaces))
    return v;
  if(highOrder > 1 && !data.pinched.empty()) {
    Msg::Error("Boundary layer: high-order layers are not available with "
               "pinched layers: keeping order 1");
    highOrder = 1;
  }
  timing("layers inserted");

  // the surfaces whose layers are inflated in their parametric plane
  const std::vector<GFace *> &inflatedSurfaces = is3D ? sideSurfaces : surfaces;
  if(is3D) storeInitialShapes(volumes, data);
  storeInitialShapes(inflatedSurfaces, data);

  if(is3D)
    computeWallThickness(volumes, surfaces, thickness, data);
  else
    computeWallThickness(surfaces, curves, thickness, data);
  timing("target thickness computed");

  // inflate the layers: on the curves, then on the surfaces, then in the
  // volumes
  inflateLayersOnCurves(m, data);
  std::size_t numCut = 0;
  for(auto gf : inflatedSurfaces)
    numCut += inflateAndCutBack(gf, data, numRings);
  timing("layers inflated on curves and surfaces");
  for(auto gr : volumes) numCut += inflateAndCutBack(gr, data, numRings);
  if(is3D) timing("layers inflated in volumes");
  if(numCut)
    Msg::Info("Boundary layer: %zu of %zu columns cut back to their target "
              "thickness",
              numCut, data.columns.size());

  // split the columns in layers. In 3D the elements of the side surfaces are
  // split along with those of the volumes, on nodes already in place.
  if(law.widths.size() > 1) {
    if(highOrder > 1 && highOrderStrategy != 1)
      Msg::Info("Boundary layer: layers will be split by high-order strategy "
                "%d",
                highOrderStrategy);
    else if(is3D)
      splitLayers(volumes, data, law);
    else
      splitLayers(surfaces, data, law);
  }

  timing("columns split");

  for(auto gr : volumes) {
    std::size_t numInvalid = countInvalidElements(gr);
    if(numInvalid)
      Msg::Error("Boundary layer: %zu flat or inverted elements in volume %d",
                 numInvalid, gr->tag());
  }

  if(highOrder > 1) {
    std::set<MElement *, MElementPtrLessThan> toProcess;
    std::set<MVertex *, MVertexPtrLessThan> fixed;
    for(auto gf : inflatedSurfaces)
      buildUntangleSets(gf, 2, data, numRings, toProcess, fixed);
    for(auto gr : volumes)
      buildUntangleSets(gr, 3, data, numRings, toProcess, fixed);
    untangleHighOrderBoundaryLayerPN(
      m, toProcess, fixed, highOrder, &data.elements, &law.widths,
      highOrderStrategy, highOrderPostSplitUntangle);
  }

  CTX::instance()->meshChanged();

  return v;
}
