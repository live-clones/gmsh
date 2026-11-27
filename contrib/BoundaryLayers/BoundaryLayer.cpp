// Gmsh Boundary Layer Plugin - Copyright (C) 2025-2026 C. Geuzaine and J.-F. Remacle
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
#include <stdexcept>
#include <sstream>
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
  return "Plugin(BoundaryLayer) performs magic.";
}

static double triangle_area_2d(std::array<double, 2> a, std::array<double, 2> b,
                               std::array<double, 2> c)
{
  return .5 * ((b[1] - a[1]) * (b[0] + a[0]) + (c[1] - b[1]) * (c[0] + b[0]) +
               (a[1] - c[1]) * (a[0] + c[0]));
}

inline std::array<double, 3> sub(const std::array<double, 3> &x,
                                 const std::array<double, 3> &y)
{
  return {x[0] - y[0], x[1] - y[1], x[2] - y[2]};
}

inline double dot(const std::array<double, 3> &u,
                  const std::array<double, 3> &v)
{
  return u[0] * v[0] + u[1] * v[1] + u[2] * v[2];
}

inline std::array<double, 3> cross(const std::array<double, 3> &u,
                                   const std::array<double, 3> &v)
{
  return {u[1] * v[2] - u[2] * v[1], u[2] * v[0] - u[0] * v[2],
          u[0] * v[1] - u[1] * v[0]};
}

inline double tet_volume(const std::array<double, 3> &a,
                         const std::array<double, 3> &b,
                         const std::array<double, 3> &c,
                         const std::array<double, 3> &d)
{
  return dot(sub(a, d), cross(sub(b, d), sub(c, d))) / 6.0;
}

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
    while(param[i] > bounds.high() + tol && param[i] - period > bounds.low() - tol)
      param[i] -= period;
    while(param[i] < bounds.low() - tol && param[i] + period < bounds.high() + tol)
      param[i] += period;
  }
  return true;
}

static void
classifyVertexOnFace(GFace *gf, MVertex *v)
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

static bool getLayerColumns(MElement *e, const PinchMap &pinched,
                            LayerColumns &lc)
{
  auto it = pinched.find(e);
  if(it != pinched.end()) {
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
      gr->tetrahedra.push_back(
        new MTetrahedron(w[0], w[1], w[2], t[0] ? t[0] : t[1] ? t[1] : t[2]));
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

static void addLayerElement(GEntity *ge, const LayerColumns &lc, double thickness,
                            std::map<MElement *, double> &layers,
                            PinchMap &pinched)
{
  MElement *e = (lc.n == 2) ? addLayerElement(static_cast<GFace *>(ge), lc) :
                              addLayerElement(static_cast<GRegion *>(ge), lc);
  if(!e) return;
  layers[e] = thickness;
  if(lc.numTops() < lc.n) pinched[e] = lc;
}

// Split a pinched triangle along its only column, given from the wall
// outwards: a fan of triangles around the pinched node
static void splitPinchedTriangle(GFace *gf, MElement *t,
                                 const std::vector<MVertex *> &column,
                                 std::map<MElement *, double> &layers,
                                 const std::vector<double> &widths)
{
  int k = 0;
  while(k < 3 && (t->getVertex(k) == column.front() ||
                  t->getVertex(k) == column.back()))
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
    layers[e] = s < widths.size() ? widths[s] : widths.back();
  }
}

static void
replaceFaces(GModel *gm,
             std::map<MEdge, std::vector<MVertex *>, MEdgeLessThan> &split,
             std::map<MElement *, double> &layers,
             const std::vector<double> &widths)
{
  for(GModel::fiter fit = gm->firstFace(); fit != gm->lastFace(); ++fit) {
    GFace *gf = (*fit);

    // pinched layer elements
    std::vector<MTriangle *> triangles = gf->triangles;
    for(auto t : triangles) {
      if(layers.find(t) == layers.end()) continue;
      for(int i = 0; i < 3; i++) {
        auto it = split.find(t->getEdge(i));
        if(it == split.end()) continue;
        splitPinchedTriangle(gf, t, it->second, layers, widths);
        break;
      }
    }

    std::vector<MQuadrangle *> newVec;
    for(auto q : gf->quadrangles) {
      bool found = false;
      auto itLayer = layers.find(q);
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
            for(int k = 0; k < 4; ++k) classifyVertexOnFace(gf, nq->getVertex(k));
            newVec.push_back(nq);
            if(itLayer != layers.end())
              layers[nq] = j < widths.size() ? widths[j] : itLayer->second;
          }
          found = true;
        }
      }
      if(found) {
        if(itLayer != layers.end()) layers.erase(itLayer);
        delete q;
      }
      else
        newVec.push_back(q);
    }
    gf->quadrangles = newVec;
  }
}

static void
replaceEdges(GModel *gm,
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
      //      printf("coucou %d
      //      %d\n",ge->tag(),l0->getVertex(0)->onWhat()->dim());
      std::vector<MLine *> old = ge->lines;
      ge->lines.clear();
      for(size_t j = 0; j < it0->second.size() - 1; j++)
        ge->lines.push_back(new MLine(it0->second[j], it0->second[j + 1]));
      for(size_t j = 1; j < old.size(); j++) ge->lines.push_back(old[j]);
      delete old.front();
    }
    if(it1 != split.end()) {
      //      	printf("poucou %d
      //      %d\n",ge->tag(),l1->getVertex(0)->onWhat()->dim());
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

// ---------------------------------------------------------------------------
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
// ---------------------------------------------------------------------------

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

} // namespace

// Insert zero-thickness layers along the walls (surfaces in 3D, curves in 2D)
// in the domains (volumes in 3D, surfaces in 2D). Return in sideSurfaces the
// surfaces that received layer elements in 3D, in pinched the layer elements
// that lost a node and in pinchedNodes the wall nodes without any spawned
// node. Nothing is changed if the layers cannot be inserted.
static bool insertLayers(GModel *m, int dim, const std::vector<GEntity *> &domains,
                         const std::set<GEntity *> &walls, double thickness,
                         std::map<MElement *, double> &layers,
                         std::vector<GFace *> &sideSurfaces, PinchMap &pinched,
                         std::set<MVertex *> &pinchedNodes)
{
  // facets, nodes and (in 3D) edges of the walls
  std::map<FacetKey, MElement *> wallFacets;
  std::vector<MElement *> wallElements;
  std::set<MVertex *, MVertexPtrLessThan> wallNodes;
  std::set<std::pair<std::size_t, std::size_t>> wallEdges;
  auto edgeKey = [](MVertex *a, MVertex *b) {
    return std::make_pair(std::min(a->getNum(), b->getNum()),
                          std::max(a->getNum(), b->getNum()));
  };
  for(auto w : walls) {
    for(std::size_t i = 0; i < w->getNumMeshElements(); i++) {
      MElement *e = w->getMeshElement(i);
      if(e->getDim() != dim - 1) continue;
      if(e->getPolynomialOrder() != 1) {
        Msg::Error("Boundary layer: the mesh must be of order 1");
        return false;
      }
      if(!wallFacets.insert(std::make_pair(facetKey(e), e)).second) continue;
      wallElements.push_back(e);
      std::size_t n = e->getNumPrimaryVertices();
      for(std::size_t j = 0; j < n; j++) {
        wallNodes.insert(e->getVertex(j));
        if(dim == 3)
          wallEdges.insert(edgeKey(e->getVertex(j), e->getVertex((j + 1) % n)));
      }
    }
  }
  if(wallElements.empty()) {
    Msg::Warning("Boundary layer: no mesh on the %s to create layers on",
                 dim == 3 ? "surfaces" : "curves");
    return false;
  }
  auto isWallNode = [&](MVertex *v) {
    return wallNodes.find(v) != wallNodes.end();
  };

  // elements of the domains around the wall nodes, and their facets
  std::vector<StarElement> star;
  std::map<MVertex *, std::vector<int>> starOf;
  std::map<FacetKey, std::array<int, 2>> facetMap;
  std::vector<Facet> facets;
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

  // components of the star of each wall node
  std::vector<Component> components;
  std::map<std::pair<std::size_t, int>, int> componentOf;
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
  auto componentAt = [&](MVertex *v, int element) {
    auto it = componentOf.find(std::make_pair(v->getNum(), element));
    return it == componentOf.end() ? -1 : it->second;
  };
  auto spawnAt = [&](MVertex *v, int element) -> MVertex * {
    int c = componentAt(v, element);
    return c < 0 ? nullptr : components[c].spawn;
  };

  // the lines of the curves starting at a wall node without being in the wall,
  // and in 3D the elements of the other surfaces around it
  struct NodeLine {
    GEdge *ge;
    MLine *line;
  };
  struct NodeFacet {
    GFace *gf;
    MElement *e;
  };
  std::map<MVertex *, std::vector<NodeLine>> linesAt;
  std::map<MVertex *, std::vector<NodeFacet>> surfaceElementsAt;
  for(auto it = m->firstEdge(); it != m->lastEdge(); ++it) {
    GEdge *ge = *it;
    if(dim == 2 && walls.find(ge) != walls.end()) continue;
    for(auto line : ge->lines) {
      MVertex *a = line->getVertex(0), *b = line->getVertex(1);
      if(dim == 3 && wallEdges.find(edgeKey(a, b)) != wallEdges.end()) continue;
      if(isWallNode(a)) linesAt[a].push_back({ge, line});
      if(isWallNode(b)) linesAt[b].push_back({ge, line});
    }
  }
  std::vector<NodeFacet> surfaceElements; // with at least one wall node
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
  // the element of the domains a surface element is a facet of, or -1
  auto elementOn = [&](MElement *surfaceElement) {
    auto it = facetMap.find(facetKey(surfaceElement));
    return it == facetMap.end() ? -1 : it->second[0];
  };

  // spawn the nodes: nothing is changed in the mesh until all are known
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
  std::vector<NewVertex> newVertices;
  std::vector<LineEdit> lineEdits;
  std::size_t numUnsupported = 0;

  for(std::size_t ic = 0; ic < components.size(); ic++) {
    Component &c = components[ic];
    if(!c.onWall || c.pinched) continue;
    MVertex *v = c.v;

    // curves along which the component leaves the wall
    std::vector<NodeLine> lines;
    auto itl = linesAt.find(v);
    if(itl != linesAt.end()) {
      for(const auto &nl : itl->second) {
        MVertex *other = (nl.line->getVertex(0) == v) ? nl.line->getVertex(1) :
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

  // the layer elements, between each wall element and its spawn on each side
  struct NewElement {
    GEntity *ge;
    LayerColumns lc;
  };
  std::vector<NewElement> newElements;
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
        // the volume lies behind the wall element if the face of its element
        // has the same orientation
        int ithFace = 0, sign = 0, rot = 0;
        e->getFaceInfo(wallElement->getFace(0), ithFace, sign, rot);
        reversed = (sign > 0);
      }
      else {
        // the layer element is oriented as the element, which runs along the
        // wall line in the same direction
        reversed = true;
        for(int k = 0; k < e->getNumEdges(); k++) {
          MEdge edge = e->getEdge(k);
          if(edge.getVertex(0) == lc.wall[0] && edge.getVertex(1) == lc.wall[1])
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

  // in 3D, the surfaces along which the layers leave the wall: their elements
  // move to the spawned nodes, and a quad is created on each wall edge
  struct NodeEdit {
    MElement *e;
    int index;
    MVertex *spawn;
  };
  std::vector<NodeEdit> nodeEdits;
  std::vector<NewElement> newSideElements;
  std::set<GEntity *> domainSet(domains.begin(), domains.end());
  std::set<GFace *> sharedSurfaces;
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
      if(domainSet.find(gr) == domainSet.end()) sharedSurfaces.insert(se.gf);
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

  if(numUnsupported) {
    Msg::Error("Boundary layer: %zu hexahedra of the layers would be pinched "
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
      if(!sp.second) pinchedNodes.insert(sp.first);
    if(!pinchedNodes.empty())
      Msg::Info("Boundary layer: layers pinched at %zu wall node(s)",
                pinchedNodes.size());
  }
  for(auto gf : sharedSurfaces)
    Msg::Warning("Boundary layer: the layers end on surface %d, shared with a "
                 "volume without layers: the mesh will not be conforming "
                 "across it",
                 gf->tag());

  // apply the changes
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
    addLayerElement(ne.ge, ne.lc, thickness, layers, pinched);
  for(auto &ne : newSideElements) {
    addLayerElement(ne.ge, ne.lc, thickness, layers, pinched);
    GFace *gf = static_cast<GFace *>(ne.ge);
    if(std::find(sideSurfaces.begin(), sideSurfaces.end(), gf) ==
       sideSurfaces.end())
      sideSurfaces.push_back(gf);
  }
  return true;
}

namespace {

  inline bool
  elementTouchesVertexSet(MElement *e,
                          std::set<MVertex *, MVertexPtrLessThan> &touched)
  {
    for(size_t j = 0; j < e->getNumVertices(); ++j)
      if(touched.find(e->getVertex(j)) != touched.end()) return true;
    return false;
  }

  template <class GEntityT>
  static void
  buildUntangleSets(GEntityT *ge,
                    int targetDim, // 2 for faces, 3 for regions
                    const std::map<MElement *, double> &layers,
                    size_t nRings, // how many adjacency expansions
                    // nodes already moved on lower-dimensional entities
                    const std::set<MVertex *> &moved,
                    std::set<MElement *, MElementPtrLessThan> &toProcess,
                    std::set<MVertex *, MVertexPtrLessThan> &fixed)
  {
    std::set<MVertex *, MVertexPtrLessThan> touched;

    // 1) seed touched with vertices of BL elements, and with the nodes that
    // were moved on the boundary: the elements around them must follow
    for(std::size_t i = 0; i < ge->getNumMeshElements(); ++i) {
      MElement *e = ge->getMeshElement(i);
      bool inLayer = (layers.find(e) != layers.end());
      for(size_t j = 0; j < e->getNumVertices(); ++j) {
        MVertex *v = e->getVertex(j);
        if(inLayer || moved.find(v) != moved.end()) touched.insert(v);
      }
    }

    // 2) expand neighborhood by nRings
    for(size_t ring = 0; ring < nRings; ++ring) {
      std::set<MVertex *, MVertexPtrLessThan> newlyTouched;

      for(std::size_t i = 0; i < ge->getNumMeshElements(); ++i) {
        MElement *e = ge->getMeshElement(i);
        if(!elementTouchesVertexSet(e, touched)) continue;

        toProcess.insert(e);
        for(size_t j = 0; j < e->getNumVertices(); ++j)
          newlyTouched.insert(e->getVertex(j));
      }

      touched.insert(newlyTouched.begin(), newlyTouched.end());
    }

    // 3) build fixed = vertices of elements not processed + vertices not
    // classified on targetDim
    for(std::size_t i = 0; i < ge->getNumMeshElements(); ++i) {
      MElement *e = ge->getMeshElement(i);

      if(toProcess.find(e) == toProcess.end()) {
        for(size_t j = 0; j < e->getNumVertices(); ++j)
          fixed.insert(e->getVertex(j));
      }

      for(size_t j = 0; j < e->getNumVertices(); ++j) {
        MVertex *v = e->getVertex(j);
        if(v->onWhat()->dim() != targetDim) fixed.insert(v);
      }
    }
  }

} // namespace

// Weights of the size of the elements in the untangling: the elements of the
// layers must reach their thickness, the others only keep their shape and are
// free to shrink
static const double layerSizeWeight = 10.;
static const double outsideSizeWeight = 0.01;

// ---------------------------------------------------------------------------
// Target thickness of the layers
//
// Each wall node has a target thickness: the requested one, reduced where
// another part of the boundary faces the wall at a short distance, so that the
// layers fit in thin gaps. The untangling inflates the layers towards the
// target, the columns are then cut back where they exceed it, and split in
// layers of the requested first height and growth ratio as far as their final
// height allows.
// ---------------------------------------------------------------------------

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
static void
limitThicknessToGaps(const WallData &wall, double maxThickness,
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

  auto visit = [&](const BoundaryPiece &piece, const std::vector<std::size_t> &ids) {
    for(auto id : ids) {
      const WallSample &sample = wall.samples[id];
      SPoint3 p = sample.v->point();
      SPoint3 q = (piece.n == 3) ?
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
      double limit = gap * (piece.wall ? gapFractionFacingWall :
                                         gapFractionFacingOther);
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
        if(c.i < c0.i || c.i > c1.i || c.j < c0.j || c.j > c1.j ||
           c.k < c0.k || c.k > c1.k)
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
    // tet_volume() has the sign of the untangler, opposite to the one of Gmsh
    volume -= tet_volume(p[0], p[1], p[2], p[3]);
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
static double meshOrientation(GFace *gf,
                              const std::map<MElement *, double> &layers)
{
  for(std::size_t i = 0; i < gf->getNumMeshElements(); i++) {
    MElement *e = gf->getMeshElement(i);
    if(e->getDim() != 2 || layers.find(e) != layers.end()) continue;
    SVector3 n = crossprod(
      SVector3(e->getVertex(0)->point(), e->getVertex(1)->point()),
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

static void addWallElements(GRegion *gr,
                            const std::map<MElement *, double> &layers,
                            const PinchMap &pinched, WallData &wall)
{
  bool positive = isPositive(gr);
  for(std::size_t i = 0; i < gr->getNumMeshElements(); i++) {
    MElement *e = gr->getMeshElement(i);
    if(layers.find(e) == layers.end()) continue;
    LayerColumns lc;
    SVector3 normal;
    if(!getLayerColumns(e, pinched, lc) || !wallNormal(lc, positive, normal))
      continue;
    for(std::size_t j = 0; j < lc.n; j++) {
      wall.samples.push_back({lc.wall[j], normal, SVector3()});
      wall.edges.push_back(
        std::make_pair(lc.wall[j], lc.wall[(j + 1) % lc.n]));
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

static void addWallElements(GFace *gf,
                            const std::map<MElement *, double> &layers,
                            const PinchMap &pinched, WallData &wall)
{
  double orientation = meshOrientation(gf, layers);
  for(std::size_t i = 0; i < gf->getNumMeshElements(); i++) {
    MElement *e = gf->getMeshElement(i);
    if(layers.find(e) == layers.end()) continue;
    LayerColumns lc;
    SVector3 normal, surfaceNormal;
    if(!getLayerColumns(e, pinched, lc) ||
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
                                 const std::set<MVertex *> &pinchedNodes,
                                 std::map<MVertex *, double> &wallThickness)
{
  for(const auto &sample : wall.samples) wallThickness[sample.v] = thickness;
  double maxThickness = 0.;
  for(const auto &t : wallThickness)
    maxThickness = std::max(maxThickness, t.second);

  limitThicknessToGaps(wall, maxThickness, wallThickness);
  for(auto &t : wallThickness)
    t.second = std::max(t.second, thicknessFloor * thickness);
  // no thickness where the layers are pinched: the smoothing tapers the
  // layers towards those nodes
  for(auto v : pinchedNodes) {
    auto it = wallThickness.find(v);
    if(it != wallThickness.end()) it->second = 0.;
  }
  smoothThickness(wall, wallThickness);

  std::size_t numReduced = 0;
  double minThickness = maxThickness;
  for(const auto &t : wallThickness) {
    if(t.second <= 0.) continue;
    if(t.second < thickness * (1. - 1.e-9)) numReduced++;
    minThickness = std::min(minThickness, t.second);
  }
  if(numReduced)
    Msg::Info("Boundary layer: thickness reduced on %zu of %zu wall nodes, in "
              "gaps or towards pinched nodes (smallest: %g)",
              numReduced, wallThickness.size(), minThickness);
}

static double thicknessAt(const std::map<MVertex *, double> &wallThickness,
                          MVertex *v, double defaultValue)
{
  auto it = wallThickness.find(v);
  return it != wallThickness.end() ? it->second : defaultValue;
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

// A column of the layers, from a wall node to its spawned node. The cosine is
// the largest one between the column and the normals of the wall elements
// around it, so that the height of the column above the wall is its length
// times the cosine.
struct Column {
  MVertex *wall = nullptr;
  double cosine = 0.;
};

static void addColumn(std::map<MVertex *, Column> &columns, MVertex *wallNode,
                      MVertex *top, const SVector3 &normal)
{
  SVector3 d(wallNode->point(), top->point());
  double l = d.norm();
  double c = (l > 0.) ? std::abs(dot(d, normal)) / l : 1.;
  Column &column = columns[top];
  column.wall = wallNode;
  column.cosine = std::max(column.cosine, c);
}

// Cut back the columns classified on the entity that are higher than the
// target thickness of their wall node. Return the number of columns cut.
static std::size_t
clampColumns(GEntity *ge, std::map<MVertex *, Column> &columns,
             const std::map<MVertex *, double> &wallThickness,
             std::set<MVertex *> &moved)
{
  std::size_t numClamped = 0;
  for(auto &c : columns) {
    MVertex *top = c.first;
    if(top->onWhat() != ge) continue;
    auto it = wallThickness.find(c.second.wall);
    if(it == wallThickness.end()) continue;
    double l = top->distance(c.second.wall);
    double maxLength = it->second / std::max(c.second.cosine, 0.1);
    if(l > maxLength * (1. + 1.e-6)) {
      moveOnColumn(c.second.wall, top, maxLength / l);
      moved.insert(top);
      numClamped++;
    }
  }
  return numClamped;
}

static void collectColumns(GRegion *gr,
                           const std::map<MElement *, double> &layers,
                           const PinchMap &pinched,
                           std::map<MVertex *, Column> &columns)
{
  bool positive = isPositive(gr);
  for(std::size_t i = 0; i < gr->getNumMeshElements(); i++) {
    MElement *e = gr->getMeshElement(i);
    if(layers.find(e) == layers.end()) continue;
    LayerColumns lc;
    SVector3 normal;
    if(!getLayerColumns(e, pinched, lc) || !wallNormal(lc, positive, normal))
      continue;
    for(std::size_t j = 0; j < lc.n; j++)
      if(lc.top[j]) addColumn(columns, lc.wall[j], lc.top[j], normal);
  }
}

static void collectColumns(GFace *gf,
                           const std::map<MElement *, double> &layers,
                           const PinchMap &pinched,
                           std::map<MVertex *, Column> &columns)
{
  double orientation = meshOrientation(gf, layers);
  for(std::size_t i = 0; i < gf->getNumMeshElements(); i++) {
    MElement *e = gf->getMeshElement(i);
    if(layers.find(e) == layers.end()) continue;
    LayerColumns lc;
    SVector3 normal, surfaceNormal;
    if(!getLayerColumns(e, pinched, lc) ||
       !wallNormal(gf, lc, orientation, normal, surfaceNormal))
      continue;
    for(int j = 0; j < 2; j++)
      if(lc.top[j]) addColumn(columns, lc.wall[j], lc.top[j], normal);
  }
}

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

static bool expandBL(
  GFace *gf,
  std::map<MElement *, std::array<std::array<double, 2>, 4>> &perfectShapes,
  std::map<MElement *, double> &layers, std::vector<GFace *> &inSurfaces,
  size_t nRings, std::set<MVertex *> &moved,
  const std::map<MVertex *, double> &wallThickness, const PinchMap &pinched,
  bool lockLayers = false)
{
  //  printf("layer size %zu\n",layers.size());
  //  std::vector<double> areas;

  std::set<MElement *, MElementPtrLessThan> toProcess;
  std::set<MVertex *, MVertexPtrLessThan> fixed;
  buildUntangleSets(gf, /*targetDim=*/2, layers, nRings, moved, toProcess, fixed);

  // nodes, and orientation of the elements in the parametric plane
  std::vector<std::array<double, 2>> points;
  std::vector<std::array<uint32_t, 3>> triangles;
  std::vector<bool> locked;
  std::set<MVertex *, MVertexPtrLessThan> verts;

  for(auto e : toProcess) {
    for(size_t j = 0; j < e->getNumVertices(); j++)
      verts.insert(e->getVertex(j));
  }

  int index = 0;
  for(auto v : verts) {
    v->setIndex(index++);
    if(fixed.find(v) == fixed.end())
      locked.push_back(false);
    else
      locked.push_back(true);

    SPoint2 param;
    reparamOnFace(v, gf, param);
    points.push_back({param.x(), param.y()});
  }
  // second pass, once the columns have been cut back: the layers stay in
  // place and only the elements around them are untangled
  if(lockLayers) {
    for(auto e : toProcess) {
      if(layers.find(e) == layers.end()) continue;
      for(size_t j = 0; j < e->getNumVertices(); j++)
        locked[e->getVertex(j)->getIndex()] = true;
    }
  }
  // int tricount = 0;
  double area = 0.0;
  for(auto e : toProcess) {
    uint32_t a = (uint32_t)e->getVertex(0)->getIndex();
    uint32_t b = (uint32_t)e->getVertex(1)->getIndex();
    uint32_t c = (uint32_t)e->getVertex(2)->getIndex();
    std::array<double, 2> pa = points[a];
    std::array<double, 2> pb = points[b];
    std::array<double, 2> pc = points[c];
    area += triangle_area_2d(pa, pb, pc);
    if(e->getNumVertices() == 4) {
      uint32_t d = (uint32_t)e->getVertex(3)->getIndex();
      std::array<double, 2> pd = points[d];
      area += triangle_area_2d(pa, pc, pd);
    }
  }

  // Ideal position, in the parametric plane, of the two wall nodes of a layer
  // element and of the nodes at the top of their columns
  auto layerCorners = [&](MVertex *w0, MVertex *w1, double thickness0,
                          double thickness1,
                          std::array<double, 2> &perfectEdge0,
                          std::array<double, 2> &perfectEdge1,
                          std::array<double, 2> &perfectLayer1,
                          std::array<double, 2> &perfectLayer0) {
    double dx = distance(w0, w1);
    perfectEdge0 = {0., 0.};
    perfectEdge1 = {dx, 0.};
    perfectLayer1 = {dx, thickness1};
    perfectLayer0 = {0., thickness0};

    if(gf->geomType() != GEntity::Plane) {
      SPoint2 paramEdge0, paramEdge1;
      bool haveParamEdge0 =
        reparamOnFace(w0, gf, paramEdge0);
      bool haveParamEdge1 =
        reparamOnFace(w1, gf, paramEdge1);
      if(haveParamEdge0 && haveParamEdge1) {
        SPoint3 pointEdge0 = w0->point();
        SPoint3 pointEdge1 = w1->point();
        SVector3 edgeDirection(pointEdge0, pointEdge1);
        double edgeLength = edgeDirection.norm();
        if(edgeLength > 0.) {
          edgeDirection.normalize();
          SVector3 normalAtEdge0 = gf->normal(paramEdge0);
          SVector3 normalAtEdge1 = gf->normal(paramEdge1);
          SVector3 layerDirection0 =
            crossprod(normalAtEdge0, edgeDirection);
          SVector3 layerDirection1 =
            crossprod(normalAtEdge1, edgeDirection);
          if(layerDirection0.norm() > 0. && layerDirection1.norm() > 0.) {
            layerDirection0.normalize();
            layerDirection1.normalize();
            // the layer lies on the side of the wall that gives the quad
            // the orientation of the other elements in the parametric
            // plane, whatever the orientation of the normal
            for(double side : {1., -1.}) {
              SPoint3 queryLayer0 =
                pointEdge0 + layerDirection0 * (side * thickness0);
              SPoint3 queryLayer1 =
                pointEdge1 + layerDirection1 * (side * thickness1);
              double guess0[2] = {paramEdge0.x(), paramEdge0.y()};
              double guess1[2] = {paramEdge1.x(), paramEdge1.y()};
              GPoint closestLayer0 = gf->closestPoint(queryLayer0, guess0);
              GPoint closestLayer1 = gf->closestPoint(queryLayer1, guess1);
              perfectEdge0 = {paramEdge0.x(), paramEdge0.y()};
              perfectEdge1 = {paramEdge1.x(), paramEdge1.y()};
              perfectLayer1 = {closestLayer1.u(), closestLayer1.v()};
              perfectLayer0 = {closestLayer0.u(), closestLayer0.v()};
              if(triangle_area_2d(perfectEdge0, perfectEdge1,
                                  perfectLayer1) * area > 0.)
                break;
            }
          }
        }
      }
    }
  };

  std::vector<std::array<std::array<double, 2>, 3>> sh;
  for(auto e : toProcess) {
    //    printf("%zu %zu\n",i,gf->getNumMeshElements());
    //    MElement *e = gf->getMeshElement(i);

    std::array<std::array<double, 2>, 4> vs;

    auto it = layers.find(e);

    if(e->getNumVertices() == 3) {
      if(it != layers.end()) {
        // pinched layer element: the quad it would have been, without the
        // node missing at the top of one of its columns
        LayerColumns lc;
        if(!getLayerColumns(e, pinched, lc) || lc.n != 2) {
          Msg::Error("Boundary layer: unknown layer triangle %zu", e->getNum());
          return false;
        }
        std::array<double, 2> edge0, edge1, layer1, layer0;
        layerCorners(lc.wall[0], lc.wall[1],
                     thicknessAt(wallThickness, lc.wall[0], it->second),
                     thicknessAt(wallThickness, lc.wall[1], it->second), edge0,
                     edge1, layer1, layer0);
        for(int k = 0; k < 3; k++) {
          MVertex *v = e->getVertex(k);
          vs[k] = (v == lc.wall[0]) ? edge0 :
                  (v == lc.wall[1]) ? edge1 :
                  (v == lc.top[0])  ? layer0 :
                                      layer1;
        }
        // ideal shapes are positive: mirror the triangle as its nodes are
        // when the surface is negative in the parametric plane
        double a = triangle_area_2d(vs[0], vs[1], vs[2]);
        if((area > 0) ? (a < 0) : (a > 0))
          for(int k = 0; k < 3; k++) vs[k][0] = -vs[k][0];
        if(area <= 0) std::swap(vs[0], vs[1]);
      }
      else {
        auto it2 = perfectShapes.find(e);
        if(it2 != perfectShapes.end())
          vs = it2->second;
        else
          Msg::Error("Argh");
      }
      sh.push_back({vs[0], vs[1], vs[2]});
    }
    else {
      if(it != layers.end()) {
        double thickness = it->second;
        // assume here zero size quads have been generated such as nodes 0 and 1
        // are along the curve ... nodes 1 and 2 are at the same position, same
        // for 0 and 3
        std::array<double, 2> perfectEdge0;
        std::array<double, 2> perfectEdge1;
        std::array<double, 2> perfectLayer1;
        std::array<double, 2> perfectLayer0;
        const double thickness0 =
          thicknessAt(wallThickness, e->getVertex(0), thickness);
        const double thickness1 =
          thicknessAt(wallThickness, e->getVertex(1), thickness);
        layerCorners(e->getVertex(0), e->getVertex(1), thickness0, thickness1,
                     perfectEdge0, perfectEdge1, perfectLayer1, perfectLayer0);

        int numBoundaryVertices = 0;
        int freeVertex = -1;
        std::array<std::array<double, 2>, 4> boundaryParam;
        bool haveBoundaryParam[4] = {false, false, false, false};
        for(int j = 0; j < 4; j++) {
          if(e->getVertex(j)->onWhat()->dim() < 2) {
            SPoint2 param;
            if(reparamOnFace(e->getVertex(j), gf, param)) {
              boundaryParam[j] = {param.x(), param.y()};
              haveBoundaryParam[j] = true;
              numBoundaryVertices++;
            }
          }
          else
            freeVertex = j;
        }
        bool haveBoundaryParallelogram = false;
        if(numBoundaryVertices == 3 && freeVertex >= 0) {
          for(int j = 0; j < 4; j++) {
            if(haveBoundaryParam[j]) {
              if(j == 0)
                perfectEdge0 = boundaryParam[j];
              else if(j == 1)
                perfectEdge1 = boundaryParam[j];
              else if(j == 2)
                perfectLayer1 = boundaryParam[j];
              else if(j == 3)
                perfectLayer0 = boundaryParam[j];
            }
          }
          if(freeVertex == 0)
            perfectEdge0 = {
              perfectEdge1[0] + perfectLayer0[0] - perfectLayer1[0],
              perfectEdge1[1] + perfectLayer0[1] - perfectLayer1[1]};
          else if(freeVertex == 1)
            perfectEdge1 = {
              perfectEdge0[0] + perfectLayer1[0] - perfectLayer0[0],
              perfectEdge0[1] + perfectLayer1[1] - perfectLayer0[1]};
          else if(freeVertex == 2)
            perfectLayer1 = {
              perfectEdge1[0] + perfectLayer0[0] - perfectEdge0[0],
              perfectEdge1[1] + perfectLayer0[1] - perfectEdge0[1]};
          else
            perfectLayer0 = {
              perfectEdge0[0] + perfectLayer1[0] - perfectEdge1[0],
              perfectEdge0[1] + perfectLayer1[1] - perfectEdge1[1]};
          haveBoundaryParallelogram = true;
        }

        // ideal shapes are positive: mirror the quad as the nodes of the
        // elements are when the surface is negative in the parametric plane
        if(triangle_area_2d(perfectEdge0, perfectEdge1, perfectLayer1) < 0.) {
          std::swap(perfectEdge0, perfectEdge1);
          std::swap(perfectLayer0, perfectLayer1);
        }

        sh.push_back({perfectEdge0, perfectEdge1, perfectLayer1});
        sh.push_back({perfectLayer1, perfectLayer0, perfectEdge0});
        sh.push_back({perfectEdge0, perfectEdge1, perfectLayer0});
        sh.push_back({perfectEdge1, perfectLayer1, perfectLayer0});
        //	printf(" %g %g %g %g %g %g\n",dx,thickness, triangle_area_2d(p0, p1,
        // p2), triangle_area_2d(p2, p3, p0), 	       triangle_area_2d(p0, p1,
        // p3),triangle_area_2d(p1, p2, p3));
      }
      else {
        auto it2 = perfectShapes.find(e);
        if(it2 != perfectShapes.end())
          vs = it2->second;
        else
          Msg::Error("Argh -- perfect shapes cannot be found ...");
        sh.push_back({vs[0], vs[1], vs[2]});
        sh.push_back({vs[2], vs[3], vs[0]});
        sh.push_back({vs[0], vs[1], vs[3]});
        sh.push_back({vs[1], vs[2], vs[3]});
      }
    }
  }

  for(auto e : toProcess) {
    uint32_t a = (uint32_t)e->getVertex(0)->getIndex();
    uint32_t b = (uint32_t)e->getVertex(1)->getIndex();
    uint32_t c = (uint32_t)e->getVertex(2)->getIndex();
    if(e->getNumVertices() == 3) {
      if(area > 0)
        triangles.push_back({a, b, c});
      else
        triangles.push_back({b, a, c});
    }
    else {
      uint32_t d = (uint32_t)e->getVertex(3)->getIndex();
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
    }
  }
  printf("face %d: %zu vertices, %zu triangles\n", gf->tag(), points.size(),
         triangles.size());
  WinslowUntangler::Options options;
  options.strictFailures = true;
  options.numThreads = CTX::instance()->numThreadsFor(triangles.size(), 5000);
  std::vector<double> sizeWeight;
  for(auto e : toProcess) {
    double w = (layers.find(e) != layers.end()) ? layerSizeWeight :
                                                  outsideSizeWeight;
    sizeWeight.insert(sizeWeight.end(), e->getNumVertices() == 3 ? 1 : 4, w);
  }
  options.elementLambda = &sizeWeight;
  bool ok =
    WinslowUntangler::untangle2D(points, locked, triangles, sh, options);
  if(!ok)
    Msg::Warning("Boundary layer: untangling of surface %d did not converge",
                 gf->tag());

  for(auto v : verts) {
    int i = v->getIndex();
    if(!locked[i]) {
      GPoint gp = gf->point(points[i][0], points[i][1]);
      moved.insert(v);
      v->x() = gp.x();
      v->y() = gp.y();
      v->z() = gp.z();
      v->setParameter(0, gp.u());
      v->setParameter(1, gp.v());
    }
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

static bool expandBL3D(
  GRegion *gr,
  std::map<MElement *, std::array<std::array<double, 3>, 8>> &perfectShapes3D,
  std::map<MElement *, double> &layers, size_t nRings,
  const std::set<MVertex *> &moved,
  const std::map<MVertex *, double> &wallThickness, const PinchMap &pinched,
  bool lockLayers = false)
{
  std::set<MElement *, MElementPtrLessThan> toProcess;
  std::set<MVertex *, MVertexPtrLessThan> fixed;
  buildUntangleSets(gr, /*targetDim=*/3, layers, nRings, moved, toProcess, fixed);

  std::vector<std::array<double, 3>> points;
  std::vector<bool> locked;
  std::set<MVertex *, MVertexPtrLessThan> verts;

  for(auto e : toProcess) {
    for(size_t j = 0; j < e->getNumVertices(); j++)
      verts.insert(e->getVertex(j));
  }

  int index = 0;
  for(auto v : verts) {
    v->setIndex(index++);
    locked.push_back(fixed.find(v) != fixed.end());
    points.push_back({v->x(), v->y(), v->z()});
  }

  // second pass, once the columns have been cut back: the layers stay in
  // place and only the elements around them are untangled
  if(lockLayers) {
    for(auto e : toProcess) {
      if(layers.find(e) == layers.end()) continue;
      for(size_t j = 0; j < e->getNumVertices(); j++)
        locked[e->getVertex(j)->getIndex()] = true;
    }
  }

  // orientation of the elements of the volume: the layer elements are flat,
  // and were created with the orientation of the other elements
  double volume = 0.0;
  for(auto e : toProcess) {
    int type = e->getTypeForMSH();
    if(type != MSH_TET_4 && type != MSH_PRI_6 && type != MSH_HEX_8 &&
       type != MSH_PYR_5)
      continue;
    const int *t = (type == MSH_TET_4) ? tetSubTets[0] :
                   (type == MSH_PRI_6) ? prismSubTets[0] :
                   (type == MSH_HEX_8) ? hexSubTets[0] :
                                         pyramidSubTets[0];
    // tet_volume() has the sign of the untangler, opposite to the one of Gmsh
    volume -= tet_volume(points[e->getVertex(t[0])->getIndex()],
                         points[e->getVertex(t[1])->getIndex()],
                         points[e->getVertex(t[2])->getIndex()],
                         points[e->getVertex(t[3])->getIndex()]);
  }
  const bool positive = (volume > 0);

  // The ideal shape of each element and its nodes are split with the same
  // sub-tetrahedra. The untangler wants left-handed tetrahedra, i.e. negative
  // ones for Gmsh, hence the swap of the first two nodes of each of them when
  // the elements are positive.
  std::vector<std::array<std::array<double, 3>, 4>> sh;
  std::vector<std::array<uint32_t, 4>> tets;
  std::vector<double> sizeWeight;
  for(auto e : toProcess) {
    int type = e->getTypeForMSH();
    const int (*sub)[4] = nullptr;
    int numSub = 0;
    if(type == MSH_TET_4) { sub = tetSubTets; numSub = 1; }
    else if(type == MSH_PRI_6) { sub = prismSubTets; numSub = 6; }
    else if(type == MSH_HEX_8) { sub = hexSubTets; numSub = 6; }
    else if(type == MSH_PYR_5) { sub = pyramidSubTets; numSub = 4; }
    else
      continue;

    std::array<std::array<double, 3>, 8> vs = {};
    auto it = layers.find(e);
    LayerColumns lc;
    if(it != layers.end() && getLayerColumns(e, pinched, lc) && lc.n >= 3) {
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
            const double t = thicknessAt(wallThickness, w, it->second);
            vs[k] = {w->x() + normal.x() * t, w->y() + normal.y() * t,
                     w->z() + normal.z() * t};
          }
        }
      }
    }
    else {
      auto it2 = perfectShapes3D.find(e);
      if(it2 == perfectShapes3D.end()) {
        Msg::Error("Boundary layer: no ideal shape for element %zu",
                   e->getNum());
        return false;
      }
      vs = it2->second;
    }

    for(int j = 0; j < numSub; j++) {
      int k[4] = {sub[j][0], sub[j][1], sub[j][2], sub[j][3]};
      if(positive) std::swap(k[0], k[1]);
      sh.push_back({vs[k[0]], vs[k[1]], vs[k[2]], vs[k[3]]});
      sizeWeight.push_back(it != layers.end() ? layerSizeWeight :
                                                outsideSizeWeight);
      tets.push_back({(uint32_t)e->getVertex(k[0])->getIndex(),
                      (uint32_t)e->getVertex(k[1])->getIndex(),
                      (uint32_t)e->getVertex(k[2])->getIndex(),
                      (uint32_t)e->getVertex(k[3])->getIndex()});
    }
  }

  double tUntangle = TimeOfDay();
  WinslowUntangler::Options options;
  options.strictFailures = true;
  options.laplacianPresmoothing = !lockLayers;
  options.numThreads = CTX::instance()->numThreadsFor(tets.size(), 5000);
  options.elementLambda = &sizeWeight;
  bool ok = WinslowUntangler::untangle3D(points, locked, tets, sh, options);
  if(!ok)
    Msg::Warning("Boundary layer: untangling of volume %d did not converge",
                 gr->tag());
  Msg::Info("Boundary layer 3D untangling done in %g s",
            TimeOfDay() - tUntangle);

  for(auto v : verts) {
    int i = v->getIndex();
    if(!locked[i]) {
      v->x() = points[i][0];
      v->y() = points[i][1];
      v->z() = points[i][2];
    }
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
    int type = e->getTypeForMSH();
    const int (*sub)[4] = nullptr;
    int numSub = 0;
    if(type == MSH_TET_4) { sub = tetSubTets; numSub = 1; }
    else if(type == MSH_PRI_6) { sub = prismSubTets; numSub = 6; }
    else if(type == MSH_HEX_8) { sub = hexSubTets; numSub = 6; }
    else if(type == MSH_PYR_5) { sub = pyramidSubTets; numSub = 4; }
    else
      continue;
    bool pos = true, neg = true;
    for(int j = 0; j < numSub; j++) {
      std::array<double, 3> p[4];
      for(int k = 0; k < 4; k++) {
        MVertex *v = e->getVertex(sub[j][k]);
        p[k] = {v->x(), v->y(), v->z()};
      }
      double vol = -tet_volume(p[0], p[1], p[2], p[3]);
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

// Split the column going from a wall node to its spawned node in layers
static std::vector<MVertex *>
splitedge(MEdge me,
          std::map<MEdge, std::vector<MVertex *>, MEdgeLessThan> &split,
          const LayerLaw &law, const std::map<MVertex *, Column> &columns)
{
  auto it = split.find(me);
  if(it != split.end()) return it->second;

  // height of the column above the wall
  double height = me.length();
  auto itc = columns.find(me.getVertex(1));
  if(itc != columns.end()) height *= itc->second.cosine;
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
void splitounette3D(std::vector<GRegion *> &r,
                    std::map<MElement *, double> &layers, PinchMap &pinched,
                    const LayerLaw &law,
                    const std::map<MVertex *, Column> &columns)
{
  std::map<MEdge, std::vector<MVertex *>, MEdgeLessThan> split;
  const std::vector<double> &widths = law.widths;
  const std::size_t numLayers = widths.size();

  for(auto gr : r) {
    std::vector<MElement *> elements;
    for(size_t i = 0; i < gr->getNumMeshElements(); ++i)
      if(layers.find(gr->getMeshElement(i)) != layers.end())
        elements.push_back(gr->getMeshElement(i));

    std::set<MElement *> replaced;
    for(auto e : elements) {
      LayerColumns lc;
      if(!getLayerColumns(e, pinched, lc) || lc.n < 3) continue;
      // the nodes of each column, from the wall outwards; a pinched column
      // stays on its wall node
      std::vector<MVertex *> column[4];
      for(std::size_t j = 0; j < lc.n; j++) {
        if(lc.top[j])
          column[j] =
            splitedge(MEdge(lc.wall[j], lc.top[j]), split, law, columns);
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
        addLayerElement(gr, slab, widths[s], layers, pinched);
      }
      replaced.insert(e);
      layers.erase(e);
      pinched.erase(e);
    }

    auto isReplaced = [&](MElement *e) {
      return replaced.find(e) != replaced.end();
    };
    gr->tetrahedra.erase(std::remove_if(gr->tetrahedra.begin(),
                                        gr->tetrahedra.end(), isReplaced),
                         gr->tetrahedra.end());
    gr->pyramids.erase(
      std::remove_if(gr->pyramids.begin(), gr->pyramids.end(), isReplaced),
      gr->pyramids.end());
    gr->prisms.erase(
      std::remove_if(gr->prisms.begin(), gr->prisms.end(), isReplaced),
      gr->prisms.end());
    gr->hexahedra.erase(std::remove_if(gr->hexahedra.begin(),
                                       gr->hexahedra.end(), isReplaced),
                        gr->hexahedra.end());
    for(auto e : replaced) delete e;
  }

  replaceEdges(r[0]->model(), split);
  replaceFaces(r[0]->model(), split, layers, widths);
}

void splitounette(std::vector<GFace *> &f, std::map<MElement *, double> &layers,
                  const PinchMap &pinched, const LayerLaw &law,
                  const std::map<MVertex *, Column> &columns)
{
  std::map<MEdge, std::vector<MVertex *>, MEdgeLessThan> split;
  const std::vector<double> &widths = law.widths;

  for(auto gf : f) {
    std::vector<MElement *> temp;
    for(size_t i = 0; i < gf->getNumMeshElements(); i++)
      temp.push_back(gf->getMeshElement(i));

    for(size_t i = 0; i < temp.size(); i++) {
      if(layers.find(temp[i]) != layers.end()) {
        if(temp[i]->getNumEdges() == 3) {
          // pinched layer element: split along its only column
          LayerColumns lc;
          if(!getLayerColumns(temp[i], pinched, lc) || lc.n != 2) continue;
          int j = lc.top[0] ? 0 : 1;
          std::vector<MVertex *> column =
            splitedge(MEdge(lc.wall[j], lc.top[j]), split, law, columns);
          splitPinchedTriangle(gf, temp[i], column, layers, widths);
        }
        else if(temp[i]->getNumEdges() == 4) {
          MEdge m03 = MEdge(temp[i]->getVertex(0), temp[i]->getVertex(3));
          MEdge m12 = MEdge(temp[i]->getVertex(1), temp[i]->getVertex(2));
          std::vector<MVertex *> p03 =
            splitedge(m03, split, law, columns);
          std::vector<MVertex *> p12 =
            splitedge(m12, split, law, columns);
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
              layers[temp[i]] = widths[j];
            }
            else {
              MQuadrangle *q = new MQuadrangle(v0, v1, v2, v3);
              gf->quadrangles.push_back(q);
              layers[q] = widths[j];
            }
          }
        }
      }
    }
  }
  if(!f.empty()) replaceEdges(f[0]->model(), split);
}

void computePerfectShapes(
  std::vector<GFace *> &f,
  std::map<MElement *, std::array<std::array<double, 2>, 4>> &perfectShapes)
{
  // printf("COMPUTE PERFECT SHAPES for %lu\n", f.size());
  for(auto gf : f) {
    //      std::map<MVertex*,SPoint2> ivp;
    double area = 0.0;
    for(size_t i = 0; i < gf->getNumMeshElements(); i++) {
      std::vector<SPoint2> pts;
      for(size_t j = 0; j < gf->getMeshElement(i)->getNumVertices(); j++) {
        SPoint2 param;
        reparamOnFace(gf->getMeshElement(i)->getVertex(j), gf, param);
        pts.push_back(param);
      }
      if(pts.size() == 3) {
        std::array<double, 2> vs0 = {pts[0].x(), pts[0].y()};
        std::array<double, 2> vs1 = {pts[1].x(), pts[1].y()};
        std::array<double, 2> vs2 = {pts[2].x(), pts[2].y()};
        area += triangle_area_2d(vs0, vs1, vs2);
      }
      else if(pts.size() == 4) {
        std::array<double, 2> vs0 = {pts[0].x(), pts[0].y()};
        std::array<double, 2> vs1 = {pts[1].x(), pts[1].y()};
        std::array<double, 2> vs2 = {pts[2].x(), pts[2].y()};
        std::array<double, 2> vs3 = {pts[3].x(), pts[3].y()};
        area += triangle_area_2d(vs0, vs1, vs2);
        area += triangle_area_2d(vs0, vs2, vs3);
      }
    }

    printf("area (%d) = %g\n", gf->tag(), area);

    for(size_t i = 0; i < gf->getNumMeshElements(); i++) {
      std::vector<SPoint2> pts;
      for(size_t j = 0; j < gf->getMeshElement(i)->getNumVertices(); j++) {
        SPoint2 param;
        reparamOnFace(gf->getMeshElement(i)->getVertex(j), gf, param);
        pts.push_back(param);
      }
      std::array<double, 2> vs0 = {pts[0].x(), pts[0].y()};
      std::array<double, 2> vs1 = {pts[1].x(), pts[1].y()};
      std::array<double, 2> vs2 = {pts[2].x(), pts[2].y()};
      if(pts.size() == 3) {
        if(area > 0)
          perfectShapes[gf->getMeshElement(i)] = {vs0, vs1, vs2, vs2};
        else
          perfectShapes[gf->getMeshElement(i)] = {vs1, vs0, vs2, vs2};
      }
      else {
        std::array<double, 2> vs3 = {pts[3].x(), pts[3].y()};
        if(area > 0)
          perfectShapes[gf->getMeshElement(i)] = {vs0, vs1, vs2, vs3};
        else
          perfectShapes[gf->getMeshElement(i)] = {vs1, vs0, vs3, vs2};
      }
    }
  }
}

// The ideal shape of the elements outside the layers is their initial shape
void computePerfectShapes(
  std::vector<GRegion *> &r,
  std::map<MElement *, std::array<std::array<double, 3>, 8>> &perfectShapes)
{
  for(auto gr : r) {
    for(size_t i = 0; i < gr->getNumMeshElements(); i++) {
      MElement *e = gr->getMeshElement(i);
      if(e->getNumVertices() > 8) continue;
      std::array<std::array<double, 3>, 8> vs = {};
      for(size_t j = 0; j < e->getNumVertices(); j++) {
        MVertex *v = e->getVertex(j);
        vs[j] = {v->x(), v->y(), v->z()};
      }
      perfectShapes[e] = vs;
    }
  }
}

PView *GMSH_BoundaryLayerPlugin::execute(PView *v)
{
  GModel *m = GModel::current();

  // the tags of the points, curves, surfaces and volumes
  std::vector<std::vector<int>> entities(4);
  for(int dim = 0; dim < 4; dim++)
    if(!optionIntList(3 - dim, entities[dim])) return v;

  std::vector<GVertex *> vv;
  for(auto v : entities[0]) {
    GVertex *gv = m->getVertexByTag(v);
    if(gv) vv.push_back(gv);
  }
  std::vector<GEdge *> e;
  for(auto c : entities[1]) {
    GEdge *ge = m->getEdgeByTag(c);
    if(ge) e.push_back(ge);
  }
  std::vector<GFace *> f;
  for(auto s : entities[2]) {
    GFace *gf = m->getFaceByTag(s);
    if(gf) f.push_back(gf);
  }
  std::vector<GRegion *> r;
  for(auto e : entities[3]) {
    GRegion *gr = m->getRegionByTag(e);
    if(gr) r.push_back(gr);
  }

  double thickness = option(0);
  double size = option(1);
  double ratio = option(2);
  int numLayers = (int)option(3);
  double numExactLayers = option(4);
  int highOrder = (int)option(5);
  int highOrderStrategy = (int)option(6);
  int highOrderPostSplitUntangle = (int)option(7);
  if(numLayers < 1) {
    Msg::Warning("Hey ! at least one smoothing layer dude ...");
    numLayers = 1;
  }
  if(highOrder < 1) highOrder = 1;
  if(highOrderStrategy < 0) highOrderStrategy = 0;

  std::map<MElement *, double> layers;

  //  printf("perfectshapes = %zu\n",perfectShapes.size());

  double ww = 0.0;
  std::vector<double> ws;
  double hwall = size;
  // as many layers as needed to reach the thickness: the last ones are
  // reduced in each column to end exactly on it
  if(size <= 0. || thickness <= 0. || ratio < 1.) {
    Msg::Error("Boundary layer: Size and Thickness must be positive and Ratio "
               "at least 1");
    return v;
  }
  while(1) {
    ws.push_back(hwall);
    ww += hwall;
    if(ww >= thickness * (1. - 1.e-12) || ws.size() >= 1000) break;
    hwall *= ratio;
  }
  LayerLaw law;
  law.widths = ws;
  law.ratio = ratio;
  law.numExact = (numExactLayers > 0) ? (int)numExactLayers :
                 (numExactLayers < 0) ? (int)(ws.size() / (-numExactLayers)) :
                                        0;

  //  printf("ww = %12.5E\n",ww);
  //  double h = 0.;
  //  for (auto wid  : ws){
  //    h += wid;
  //    printf("h = %g y = %g\n",wid,h);
  //  }

  std::vector<GFace *> toExpand;

  PinchMap pinched;
  std::set<MVertex *> pinchedNodes;
  bool inserted;
  if(r.empty()) {
    std::vector<GEntity *> domains(f.begin(), f.end());
    std::set<GEntity *> walls(e.begin(), e.end());
    inserted = insertLayers(m, 2, domains, walls, thickness, layers, toExpand,
                            pinched, pinchedNodes);
  }
  else {
    std::vector<GEntity *> domains(r.begin(), r.end());
    std::set<GEntity *> walls(f.begin(), f.end());
    inserted = insertLayers(m, 3, domains, walls, thickness, layers, toExpand,
                            pinched, pinchedNodes);
  }
  if(!inserted) return v;
  if(highOrder > 1 && !pinched.empty()) {
    Msg::Error("Boundary layer: high-order layers are not available with "
               "pinched layers: keeping order 1");
    highOrder = 1;
  }

  std::map<MElement *, std::array<std::array<double, 2>, 4>> perfectShapes;
  std::map<MElement *, std::array<std::array<double, 3>, 8>> perfectShapes3D;
  if(r.empty()) { computePerfectShapes(f, perfectShapes); }
  else {
    computePerfectShapes(r, perfectShapes3D);
    computePerfectShapes(toExpand, perfectShapes);
  }

  // target thickness of each wall node
  WallData wall;
  if(r.empty()) {
    std::set<GEdge *> wallCurves(e.begin(), e.end());
    std::set<GEdge *> curves;
    for(auto gf : f) {
      addWallElements(gf, layers, pinched, wall);
      for(auto ge : gf->edges()) curves.insert(ge);
      for(auto ge : gf->embeddedEdges()) curves.insert(ge);
    }
    for(auto ge : curves)
      addBoundaryPieces(ge, wallCurves.find(ge) != wallCurves.end(), wall);
  }
  else {
    std::set<GFace *> wallSurfaces(f.begin(), f.end());
    std::set<GFace *> surfaces;
    for(auto gr : r) {
      addWallElements(gr, layers, pinched, wall);
      for(auto gf : gr->faces()) surfaces.insert(gf);
      for(auto gf : gr->embeddedFaces()) surfaces.insert(gf);
    }
    for(auto gf : surfaces)
      addBoundaryPieces(gf, wallSurfaces.find(gf) != wallSurfaces.end(), wall);
  }
  std::map<MVertex *, double> wallThickness;
  computeWallThickness(wall, thickness, pinchedNodes, wallThickness);

  // the nodes moved on the curves, then on the surfaces: the elements of the
  // surfaces and of the volumes around them are untangled as well
  std::set<MVertex *> moved;
  for(GModel::eiter eit = m->firstEdge(); eit != m->lastEdge(); ++eit) {
    GEdge *ge = *eit;
    // the layers at both ends of a curve take at most a third of it each
    double width[2] = {0., 0.};
    GVertex *gv[2] = {ge->getBeginVertex(), ge->getEndVertex()};
    double maxWidth = ge->length() / 3.;
    for(int i = 0; i < 2; i++) {
      if(!gv[i] || gv[i]->mesh_vertices.empty()) continue;
      width[i] =
        std::min(thicknessAt(wallThickness, gv[i]->mesh_vertices[0], 0.),
                 maxWidth);
    }
    std::vector<SPoint3> before;
    for(auto mv : ge->mesh_vertices) before.push_back(mv->point());
    meshGEdgeInsertBoundaryLayer(ge, width[0], width[1]);
    for(std::size_t i = 0; i < before.size(); i++)
      if(before[i].distance(ge->mesh_vertices[i]->point()) > 0.)
        moved.insert(ge->mesh_vertices[i]);
  }

  // inflate the layers on the surfaces then in the volumes, and cut back the
  // columns that exceed their target
  std::map<MVertex *, Column> columns;
  std::size_t numClamped = 0;
  std::vector<GFace *> &surfacesToExpand = r.empty() ? f : toExpand;
  for(auto gf : surfacesToExpand) {
    expandBL(gf, perfectShapes, layers, surfacesToExpand, numLayers, moved,
             wallThickness, pinched);
    collectColumns(gf, layers, pinched, columns);
    std::size_t n = clampColumns(gf, columns, wallThickness, moved);
    if(n)
      expandBL(gf, perfectShapes, layers, surfacesToExpand, numLayers, moved,
               wallThickness, pinched, true);
    numClamped += n;
  }
  for(auto gr : r) {
    expandBL3D(gr, perfectShapes3D, layers, numLayers, moved, wallThickness,
               pinched);
    collectColumns(gr, layers, pinched, columns);
    std::size_t n = clampColumns(gr, columns, wallThickness, moved);
    if(n)
      expandBL3D(gr, perfectShapes3D, layers, numLayers, moved, wallThickness,
                 pinched, true);
    numClamped += n;
  }
  if(numClamped)
    Msg::Info("Boundary layer: %zu of %zu columns cut back to their target "
              "thickness",
              numClamped, columns.size());

  if(r.empty()) {
    if(highOrder <= 1 || highOrderStrategy == 1) {
      if(ws.size() > 1) {
        if(highOrder > 1)
          Msg::Info("Boundary layer high-order mode: splitting %zu low-order "
                    "layers before P%d untangling",
                    ws.size(), highOrder);
        splitounette(f, layers, pinched, law, columns);
      }
    }
    else if(ws.size() > 1) {
      Msg::Info("Boundary layer high-order mode: delaying layer splitting to "
                "high-order strategy %d",
                highOrderStrategy);
    }
  }
  else if(ws.size() > 1) {
    if(highOrder <= 1 || highOrderStrategy == 1) {
      if(highOrder > 1)
        Msg::Info("Boundary layer high-order mode: splitting %zu low-order "
                  "volume layers before P%d untangling",
                  ws.size(), highOrder);
      // the side quads are split along with the volume elements, on nodes
      // already in place: the adjacent surfaces need no further untangling
      splitounette3D(r, layers, pinched, law, columns);
    }
    else {
      Msg::Info("Boundary layer high-order mode: delaying volume layer "
                "splitting to high-order strategy %d",
                highOrderStrategy);
    }
  }

  for(auto gr : r) {
    std::size_t numInvalid = countInvalidElements(gr);
    if(numInvalid)
      Msg::Error("Boundary layer: %zu flat or inverted elements in volume %d",
                 numInvalid, gr->tag());
  }

  if(highOrder > 1) {
    std::set<MElement *, MElementPtrLessThan> toProcess;
    std::set<MVertex *, MVertexPtrLessThan> fixed;
    if(r.empty()) {
      for(auto gf : f)
        buildUntangleSets(gf, /*targetDim=*/2, layers, numLayers, moved,
                          toProcess, fixed);
    }
    else {
      for(auto gf : toExpand)
        buildUntangleSets(gf, /*targetDim=*/2, layers, numLayers, moved,
                          toProcess, fixed);
      for(auto gr : r)
        buildUntangleSets(gr, /*targetDim=*/3, layers, numLayers, moved,
                          toProcess, fixed);
    }
    untangleHighOrderBoundaryLayerPN(m, toProcess, fixed, highOrder, &layers,
                                     &ws, highOrderStrategy,
                                     highOrderPostSplitUntangle != 0);
  }

  //  for (auto gf : f)
  //    expandL(gf, perfectShapes, layers, f);

  CTX::instance()->meshChanged();

  return v;
}
