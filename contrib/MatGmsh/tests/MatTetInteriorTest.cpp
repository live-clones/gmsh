#include "MatPipeline.h"
#include "MatTetInterior.h"
#include "gmsh.h"
#include <functional>
#include <iostream>
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

// Unit cube, outward triangles.
const std::vector<double> cubeXyz = {0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0,
                                     0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1};
const std::vector<int> cubeSkin = {0, 2, 1, 0, 3, 2, 4, 5, 6, 4, 6, 7, 0, 1, 5, 0, 5, 4,
                                   1, 2, 6, 1, 6, 5, 2, 3, 7, 2, 7, 6, 3, 0, 4, 3, 4, 7};

void surfaceCertificates()
{
  tet::Surface s = tet::certifySurface(cubeSkin, 8);
  check(s.closedManifold && s.oriented && s.euler == 2 && s.components == 1 && !s.missingSites,
        "the cube is a closed oriented sphere");
  check(s.vertices == 8 && s.edges == 18 && s.faces == 12, "cube counts");

  std::vector<int> flipped = cubeSkin;
  std::swap(flipped[0], flipped[1]);
  s = tet::certifySurface(flipped, 8);
  check(s.closedManifold && !s.oriented && s.badOrientations == 3, "a flipped triangle is seen");

  const std::vector<int> open(cubeSkin.begin() + 3, cubeSkin.end());
  s = tet::certifySurface(open, 8);
  check(!s.closedManifold && s.badEdges == 3 && s.badVertices == 3, "a missing triangle is seen");

  // Two tetrahedra touching at site 0: every edge is fine, the vertex is not.
  const std::vector<int> pinched = {0, 2, 1, 0, 1, 3, 0, 3, 2, 1, 2, 3,
                                    0, 5, 4, 0, 4, 6, 0, 6, 5, 4, 5, 6};
  s = tet::certifySurface(pinched, 8);
  check(!s.badEdges && s.badVertices == 1 && !s.closedManifold && s.missingSites == 1,
        "a pinched vertex is seen");
}

void barycentreClassification()
{
  // Sites 8 and 9 are off the skin: they only build exterior tetrahedra.
  std::vector<double> xyz = cubeXyz;
  xyz.insert(xyz.end(), {2, .5, .5, 3, .5, .5});
  const std::vector<int> pattern = {
    0, 1, 3, 4, // corner of the cube: interior
    1, 2, 3, 6, // interior
    1, 2, 8, 9, // outside
    0, 1, 2, 3, // flat
    1, 2, 4, 8, // barycentre (1, .375, .375) exactly on the face x = 1
  };
  std::vector<int> tets; // repeated, so that several threads share the work
  for(int copy = 0; copy < 200; ++copy) tets.insert(tets.end(), pattern.begin(), pattern.end());
  for(unsigned threads : {1u, 3u}) {
    const tet::Classification c = tet::classify(xyz, cubeSkin, tets, threads);
    for(std::size_t t = 0; t < c.interior.size(); ++t)
      check(c.interior[t] == (t % 5 < 2) && c.status[t] == c.status[t % 5] &&
              c.winding[t] == c.winding[t % 5], "interior flags");
    check(c.winding[0] != 0 && c.winding[0] == c.winding[1] && c.winding[2] == 0, "winding");
    check(c.status[0] == tet::Resolved && c.status[2] == tet::Resolved &&
            c.status[3] == tet::ZeroVolume && c.status[4] == tet::ExactContact,
          "query status");
    check(c.volumeSign[3] == 0 && c.volumeSign[0] != 0, "volume signs");
  }
  std::vector<int> open(cubeSkin.begin() + 3, cubeSkin.end());
  bool refused = false;
  try {
    tet::classify(xyz, open, tets);
  }
  catch(const std::runtime_error &) {
    refused = true;
  }
  check(refused, "an open skin must be refused");
}

void dualOfOneEdge()
{
  // Four tetrahedra around the edge (0, 1); every other edge is on the hull.
  const std::vector<int> tets = {0, 1, 2, 3, 0, 1, 5, 2, 0, 1, 4, 5, 0, 1, 3, 4};
  tet::Dual dual = tet::buildDual(tets, {1, 1, 1, 1}, 6);
  check(dual.size() == 1 && dual.sitePair[0] == std::array<int, 2>({0, 1}), "one polygon");
  // From tetrahedron 0, entered through site 2 and left through site 3.
  check(dual.cycles == std::vector<int>({0, 3, 2, 1}), "cycle order");
  check(dual.hullEdges == 12 && dual.invalidLinks == 0, "hull edges");
  const tet::ComplexTopology t = tet::topology(dual);
  check(t.vertices == 4 && t.edges == 4 && t.faces == 1 && t.euler == 1 && t.freeEdges == 4 &&
          t.components == 1, "topology of one polygon");

  dual = tet::buildDual(tets, {1, 1, 0, 1}, 6);
  check(dual.size() == 0 && dual.invalidLinks == 0, "an exterior tetrahedron removes the polygon");
}

Result run(const std::function<void()> &build, double size)
{
  gmsh::clear();
  gmsh::model::add("case");
  build();
  gmsh::model::occ::synchronize();
  gmsh::option::setNumber("Mesh.MeshSizeMin", size);
  gmsh::option::setNumber("Mesh.MeshSizeMax", size);
  gmsh::model::mesh::generate(2);
  Options options;
  options.thickness = 1.;
  options.raw = RawMode::Tet;
  options.filter = FilterMode::None;
  Result result;
  std::string error;
  check(computeCurrent(options, result, error), "pipeline failed: " + error);
  return result;
}

void expectCertified(const Result &r, long long skinEuler, std::size_t components,
                     bool convex, const std::string &name)
{
  const auto &t = r.tet;
  const auto surface = [](const tet::Surface &x) {
    return "euler " + std::to_string(x.euler) + ", components " + std::to_string(x.components) +
           ", bad edges " + std::to_string(x.badEdges) + ", bad vertices " +
           std::to_string(x.badVertices) + ", bad orientations " +
           std::to_string(x.badOrientations) + ", missing sites " + std::to_string(x.missingSites);
  };
  check(t.computed && t.certified,
        name + ": certificate; skin: " + surface(t.skin) + "; boundary: " + surface(t.boundary) +
          "; dual euler " + std::to_string(t.dual.euler) + ", invalid links " +
          std::to_string(t.invalidLinks) + ", interior " + std::to_string(t.interior) + " of " +
          std::to_string(t.tetrahedra) + ", contacts " + std::to_string(t.exactContact) + "+" +
          std::to_string(t.numericalContact) + ", flat " + std::to_string(t.zeroVolume));
  check(t.skin.euler == skinEuler && t.boundary.euler == skinEuler && 2 * t.dual.euler == skinEuler,
        name + ": Euler characteristics");
  check(t.skin.components == components && t.boundary.components == components,
        name + ": skin components");
  check(t.dual.components == 1, name + ": one MAT component");
  check(t.interior > 0 && (t.interior + t.zeroVolume == t.tetrahedra) == convex,
        name + ": interior and exterior tetrahedra");
  check(!t.invalidLinks && !t.boundary.missingSites && !t.unresolved, name + ": counts");
  check(!r.raw.triangles.empty() && r.filtered.triangles == r.raw.triangles, name + ": raw mesh");
}

void solids()
{
  // Plate: the MAT of a ball is contractible.
  expectCertified(run([] { gmsh::model::occ::addBox(0, 0, 0, 10, 6, 1); }, .25), 2, 1, true, "plate");
  // L profile: the Delaunay tetrahedra of the notch are exterior.
  expectCertified(run([] {
    const int a = gmsh::model::occ::addBox(0, 0, 0, 8, 6, 1);
    const int b = gmsh::model::occ::addBox(0, 0, 0, 1, 6, 5);
    gmsh::vectorpair out;
    std::vector<gmsh::vectorpair> map;
    gmsh::model::occ::fuse({{3, a}}, {{3, b}}, out, map);
  }, .25), 2, 1, false, "bracket");
  // Through hole: genus one.
  expectCertified(run([] {
    const int a = gmsh::model::occ::addBox(0, 0, 0, 10, 8, 1);
    const int b = gmsh::model::occ::addCylinder(5, 4, -1, 0, 0, 3, 2);
    gmsh::vectorpair out;
    std::vector<gmsh::vectorpair> map;
    gmsh::model::occ::cut({{3, a}}, {{3, b}}, out, map);
  }, .25), 0, 1, false, "holed plate");
  // Closed cavity: two skin components, the MAT is a sphere.
  expectCertified(run([] {
    const int a = gmsh::model::occ::addBox(0, 0, 0, 6, 6, 6);
    const int b = gmsh::model::occ::addBox(1, 1, 1, 4, 4, 4);
    gmsh::vectorpair out;
    std::vector<gmsh::vectorpair> map;
    gmsh::model::occ::cut({{3, a}}, {{3, b}}, out, map);
  }, .25), 4, 2, false, "hollow box");
}
} // namespace

int main()
{
  try {
    gmsh::initialize();
    gmsh::option::setNumber("General.Terminal", 0);
    gmsh::option::setNumber("General.NumThreads", 2);
    surfaceCertificates();
    barycentreClassification();
    dualOfOneEdge();
    solids();
    gmsh::finalize();
    std::cout << "MatTetInterior: 4 tests passed\n";
    return 0;
  }
  catch(const std::exception &e) {
    std::cerr << "MatTetInterior test: " << e.what() << '\n';
    if(gmsh::isInitialized()) gmsh::finalize();
    return 1;
  }
}
