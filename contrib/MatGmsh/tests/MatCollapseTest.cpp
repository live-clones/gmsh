#include "MatPipeline.h"
#include "MatCollapse.h"
#include "gmsh.h"
#include <cmath>
#include <functional>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>

using namespace matgmsh_native;
namespace tet = matgmsh::tet;
namespace {
void check(bool condition, const std::string &message)
{
  if(!condition) throw std::runtime_error(message);
}

tet::Dual complex(const std::vector<std::vector<int> > &polygons)
{
  tet::Dual dual;
  dual.offsets.push_back(0);
  for(const auto &polygon : polygons) {
    dual.sitePair.push_back({{0, 1}});
    dual.cycles.insert(dual.cycles.end(), polygon.begin(), polygon.end());
    dual.offsets.push_back(dual.cycles.size());
  }
  return dual;
}

// Three by three unit squares in the plane z = 0, sites at (1.5, 1.5, +-0.5).
void burnTimeOfAnInnerPolygon()
{
  std::vector<double> vertices;
  for(int j = 0; j < 4; ++j)
    for(int i = 0; i < 4; ++i) vertices.insert(vertices.end(), {double(i), double(j), 0.});
  std::vector<std::vector<int> > squares;
  for(int j = 0; j < 3; ++j)
    for(int i = 0; i < 3; ++i)
      squares.push_back({4 * j + i, 4 * j + i + 1, 4 * j + i + 5, 4 * j + i + 4});
  const tet::Dual dual = complex(squares);
  const std::vector<double> sites = {1.5, 1.5, .5, 1.5, 1.5, -.5};
  const tet::Adjacency graph = tet::adjacency(dual);
  check(graph.edges() == 24, "24 edges");
  const tet::Geometry g = tet::geometry(dual, vertices, sites);
  check(std::abs(g.area[4] - 1.) < 1e-14 && std::abs(g.centroid[12] - 1.5) < 1e-14 &&
          std::abs(g.radius[4] - .5) < 1e-14 && g.zeroArea == 0, "geometry of the centre square");
  const std::vector<double> times = tet::burnTimes(dual, graph, g);
  for(int p = 0; p < 9; ++p)
    if(p != 4) check(times[p] == g.radius[p], "a boundary polygon starts at its radius");
  // Reached from an edge neighbour, at distance 1 with radius sqrt(1.25).
  check(std::abs(times[4] - (std::sqrt(1.25) + 1.)) < 1e-14, "burn time of the centre square");
}

void elementaryCollapses()
{
  // Three pages around the edge (0, 1).
  const tet::Dual book = complex({{0, 1, 2, 3}, {0, 1, 4, 5}, {0, 1, 6, 7}});
  const tet::Adjacency graph = tet::adjacency(book);
  const double nan = std::numeric_limits<double>::quiet_NaN();
  tet::Collapse c = tet::collapse(book, graph, {.1, 1., 1.}, {0, 0, 0}, .21);
  check(c.keep == std::vector<unsigned char>({0, 1, 1}) && c.removed == 1 && !c.wireEdges &&
          !c.blocked, "the thin page goes, its dangling edges are pruned");
  check(tet::topology(book, &c.keep).junctionEdges == 0, "no junction is left");
  c = tet::collapse(book, graph, {5., 1., 1.}, {1, 0, 0}, .21);
  check(c.keep == std::vector<unsigned char>({0, 1, 1}), "a wing goes whatever its thickness");
  c = tet::collapse(book, graph, {nan, 1., 1.}, {1, 0, 0}, .21);
  check(c.keep == std::vector<unsigned char>({1, 1, 1}) && !c.eligible, "NaN is never eligible");
  c = tet::collapse(book, graph, {.1, .1, .1}, {0, 0, 0}, .21);
  check(c.removed == 3 && !c.wireEdges, "a book of thin pages collapses to a point");

  // A closed surface has no free edge: nothing can start.
  const tet::Dual sphere = complex({{0, 1, 2}, {0, 1, 3}, {0, 2, 3}, {1, 2, 3}});
  c = tet::collapse(sphere, tet::adjacency(sphere), {.1, .1, .1, .1}, {0, 0, 0, 0}, .21);
  check(c.removed == 0 && c.blocked == 4, "a closed surface is blocked");

  // Two thick squares joined by a thin one: the bridge leaves a wire.
  const tet::Dual bridge = complex({{0, 1, 2, 3}, {2, 4, 5, 6}, {4, 7, 8, 9}});
  c = tet::collapse(bridge, tet::adjacency(bridge), {1., .1, 1.}, {0, 0, 0}, .21);
  check(c.keep == std::vector<unsigned char>({1, 0, 1}), "the bridge polygon goes");
  check(c.wireEdges > 0, "the two squares stay connected by edges without surface");
}

void convexEdgesOfACube()
{
  const std::vector<double> xyz = {0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0,
                                   0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1};
  std::vector<int> skin = {0, 2, 1, 0, 3, 2, 4, 5, 6, 4, 6, 7, 0, 1, 5, 0, 5, 4,
                           1, 2, 6, 1, 6, 5, 2, 3, 7, 2, 7, 6, 3, 0, 4, 3, 4, 7};
  const std::vector<int> patch = {0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
  const std::vector<std::array<int, 2> > curves = {{{1, 0}}, {{1, 2}}, {{2, 3}}, {{3, 0}},
                                                   {{4, 5}}, {{5, 6}}, {{6, 7}}, {{7, 4}},
                                                   {{0, 4}}, {{1, 5}}, {{2, 6}}, {{3, 7}},
                                                   {{0, 2}}, {{0, 6}}};
  for(int pass = 0; pass < 2; ++pass) {
    const tet::SkinSegments s = tet::skinSegments(xyz, skin, patch, curves);
    check(s.materialSide && s.segments.size() == 14, "one closed shell");
    for(const tet::Segment &segment : s.segments) {
      if(segment.a == 0 && segment.b == 6)
        check(segment.sign == 2 && segment.patchA == -1, "a chord is no skin edge");
      else if(segment.a == 0 && segment.b == 2)
        check(segment.sign == 0 && segment.patchA == segment.patchB, "a diagonal is flat");
      else
        check(segment.sign == 1 && segment.patchA != segment.patchB, "a cube edge is convex");
    }
    // Inward triangles: the material side is found from the signed volume.
    for(std::size_t t = 0; t < skin.size(); t += 3) std::swap(skin[t + 1], skin[t + 2]);
  }
}

Result run(const std::function<void()> &build)
{
  gmsh::clear();
  gmsh::model::add("case");
  build();
  gmsh::model::occ::synchronize();
  gmsh::option::setNumber("Mesh.MeshSizeMin", .2);
  gmsh::option::setNumber("Mesh.MeshSizeMax", .2);
  gmsh::model::mesh::generate(2);
  Options options;
  options.thickness = 1.;
  options.raw = RawMode::Tet;
  options.filter = FilterMode::Collapse;
  Result result;
  std::string error;
  check(computeCurrent(options, result, error), "pipeline failed: " + error);
  check(result.tet.certified && result.collapse.computed, "certificate");
  // Elementary collapses keep the homotopy type.
  check(result.collapse.surface.euler == result.tet.dual.euler &&
          result.collapse.surface.components == result.tet.dual.components &&
          !result.collapse.wireEdges,
        "homotopy type of the dual: Euler " + std::to_string(result.tet.dual.euler) + " -> " +
          std::to_string(result.collapse.surface.euler) + ", components " +
          std::to_string(result.tet.dual.components) + " -> " +
          std::to_string(result.collapse.surface.components) + ", wire edges " +
          std::to_string(result.collapse.wireEdges) + ", removed " +
          std::to_string(result.collapse.removed) + " of " + std::to_string(result.tet.polygons) +
          ", wings " + std::to_string(result.collapse.wingPolygons) + ", zero area " +
          std::to_string(result.collapse.zeroAreaPolygons) + ", unreached " +
          std::to_string(result.collapse.unreachedPolygons));
  check(result.filteredTopology.euler == result.collapse.surface.euler &&
          result.filteredTopology.components == 1, "topology of the filtered mesh");
  return result;
}

double area(const Mesh &m)
{
  double total = 0.;
  for(std::size_t f = 0; f < m.triangles.size(); f += 3) {
    const double *a = &m.xyz[3 * m.triangles[f]], *b = &m.xyz[3 * m.triangles[f + 1]],
                 *c = &m.xyz[3 * m.triangles[f + 2]];
    double u[3], w[3], n2 = 0.;
    for(int k = 0; k < 3; ++k) { u[k] = b[k] - a[k]; w[k] = c[k] - a[k]; }
    for(int k = 0; k < 3; ++k) {
      const double n = u[(k + 1) % 3] * w[(k + 2) % 3] - u[(k + 2) % 3] * w[(k + 1) % 3];
      n2 += n * n;
    }
    total += .5 * std::sqrt(n2);
  }
  return total;
}

void fuse(int a, int b)
{
  gmsh::vectorpair out;
  std::vector<gmsh::vectorpair> map;
  gmsh::model::occ::fuse({{3, a}}, {{3, b}}, out, map);
}

void solids()
{
  // Plate: the wings of the twelve edges burn, the mid-plane stays.
  Result r = run([] { gmsh::model::occ::addBox(0, 0, 0, 10, 6, 1); });
  check(r.collapse.materialSide && r.collapse.convexSegments == r.collapse.curveSegments &&
          r.collapse.wingPolygons > 0 && !r.collapse.wingsBlocked, "plate: wings");
  check(r.filteredTopology.euler == 1 && r.filteredTopology.junctionEdges == 0, "plate: one sheet");
  for(std::size_t v = 0; v < r.filtered.xyz.size(); v += 3)
    // Circumcentres of sites on both faces: within h^2 / t of the mid-plane.
    check(std::abs(r.filtered.xyz[v + 2] - .5) < .06, "plate: the sheet is the mid-plane");
  const double sheet = area(r.filtered);
  check(sheet > 40. && sheet < 50., "plate: mid-plane without its wings, area " +
                                      std::to_string(sheet));

  // T junction: three sheets around one triple line.
  r = run([] {
    fuse(gmsh::model::occ::addBox(0, 0, 0, 10, 6, 1), gmsh::model::occ::addBox(4.5, 0, 0, 1, 6, 5));
  });
  check(r.collapse.convexSegments < r.collapse.curveSegments, "T: concave edges are seen");
  check(r.filteredTopology.euler == 1 && r.filteredTopology.junctionEdges > 0, "T: junction");

  // Closed cavity: the edges of the inner shell are concave, whatever the
  // orientation of its triangles.
  r = run([] {
    const int a = gmsh::model::occ::addBox(0, 0, 0, 6, 6, 6);
    const int b = gmsh::model::occ::addBox(1, 1, 1, 4, 4, 4);
    gmsh::vectorpair out;
    std::vector<gmsh::vectorpair> map;
    gmsh::model::occ::cut({{3, a}}, {{3, b}}, out, map);
  });
  check(r.collapse.materialSide && r.collapse.wingPolygons > 0 && !r.collapse.wingsBlocked &&
          r.collapse.convexSegments < r.collapse.curveSegments &&
          2 * r.collapse.convexSegments > r.collapse.curveSegments,
        "hollow box: convex outer edges, concave inner edges");
  check(r.filteredTopology.euler == 2, "hollow box: the MAT is a sphere");
}
} // namespace

int main()
{
  try {
    gmsh::initialize();
    gmsh::option::setNumber("General.Terminal", 0);
    gmsh::option::setNumber("General.NumThreads", 2);
    burnTimeOfAnInnerPolygon();
    elementaryCollapses();
    convexEdgesOfACube();
    solids();
    gmsh::finalize();
    std::cout << "MatCollapse: 4 tests passed\n";
    return 0;
  }
  catch(const std::exception &e) {
    std::cerr << "MatCollapse test: " << e.what() << '\n';
    if(gmsh::isInitialized()) gmsh::finalize();
    return 1;
  }
}
