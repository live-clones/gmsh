#include "MatPipeline.h"
#include "matSkinSites.h"
#include "gmsh.h"
#include <cstring>
#include <iostream>
#include <set>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

using namespace matgmsh_native;
namespace {
void check(bool condition, const std::string &message)
{
  if(!condition) throw std::runtime_error(message);
}

// Sites 0, 3 and 5 are used by no triangle.
void stableCompaction()
{
  std::vector<double> xyz = {9, 9, 9, 0, 0, 0, 1, 0, 0, 8, 8, 8, 0, 1, 0, 7, 7, 7};
  std::vector<std::size_t> tags = {70, 60, 50, 40, 30, 20}, triangles = {1, 2, 4};
  std::vector<std::pair<int, int> > entity = {{2, 1}, {2, 2}, {2, 3},
                                              {1, 4}, {2, 5}, {1, 6}};
  std::vector<std::vector<int> > faces = {{1}, {2}, {3}, {4}, {5}, {6}};
  const auto removed =
    matgmsh::skinSites::restrictToTriangles(xyz, tags, entity, faces, triangles);
  check(removed == std::vector<std::size_t>({70, 40, 20}), "removed tags");
  check(tags == std::vector<std::size_t>({60, 50, 30}), "retained tags keep their order");
  check(triangles == std::vector<std::size_t>({0, 1, 2}), "triangles renumbered");
  check(xyz == std::vector<double>({0, 0, 0, 1, 0, 0, 0, 1, 0}), "coordinates");
  check(entity == std::vector<std::pair<int, int> >({{2, 2}, {2, 3}, {2, 5}}), "entities");
  check(faces == std::vector<std::vector<int> >({{2}, {3}, {5}}), "support faces");
}

// With every site referenced nothing changes, not even the sign of a zero.
void identityKeepsCoordinateBits()
{
  std::vector<double> xyz = {-0.0, 0, 0, 0.0, 0, 0, 1, 0, 0};
  const std::vector<double> copy = xyz;
  std::vector<std::size_t> tags = {2, 3, 1}, triangles = {0, 1, 2};
  std::vector<std::pair<int, int> > entity; // sites without a model entity
  std::vector<std::vector<int> > faces = {{1}, {2}, {3}};
  const auto removed =
    matgmsh::skinSites::restrictToTriangles(xyz, tags, entity, faces, triangles);
  check(removed.empty(), "no site removed");
  check(!std::memcmp(xyz.data(), copy.data(), xyz.size() * sizeof(double)),
        "coordinate bits preserved");
  check(tags == std::vector<std::size_t>({2, 3, 1}), "tags untouched");
}

void unknownTriangleNodeIsRejected()
{
  std::vector<double> xyz = {0, 0, 0, 1, 0, 0, 0, 1, 0};
  std::vector<std::size_t> tags = {1, 2, 3}, triangles = {0, 1, 8};
  std::vector<std::pair<int, int> > entity;
  std::vector<std::vector<int> > faces(3);
  bool rejected = false;
  try {
    matgmsh::skinSites::restrictToTriangles(xyz, tags, entity, faces, triangles);
  }
  catch(const std::runtime_error &) {
    rejected = true;
  }
  check(rejected, "a triangle on an unknown node must be rejected");
}

// Nodes of the current model, and those used by its triangles.
void countNodes(std::size_t &all, std::size_t &referenced)
{
  std::vector<std::size_t> nodeTags;
  std::vector<double> coordinates, parametric;
  gmsh::model::mesh::getNodes(nodeTags, coordinates, parametric);
  std::vector<int> types;
  std::vector<std::vector<std::size_t> > elementTags, elementNodes;
  gmsh::model::mesh::getElements(types, elementTags, elementNodes, 2);
  std::set<std::size_t> used;
  for(const auto &nodes : elementNodes) used.insert(nodes.begin(), nodes.end());
  all = nodeTags.size();
  referenced = used.size();
}

Result mat()
{
  Options options;
  options.thickness = 1.;
  Result result;
  std::string error;
  check(computeCurrent(options, result, error), "pipeline failed: " + error);
  return result;
}

// A plate with a construction curve inside the material that bounds no face:
// its 1D nodes belong to the model but to no skin triangle. The MAT is
// computed with them, then again on the very same skin once they are removed.
void constructionCurveDoesNotChangeTheMat()
{
  gmsh::clear();
  gmsh::model::add("plate_with_curve");
  gmsh::model::occ::addBox(0, 0, 0, 10, 6, 1);
  const int a = gmsh::model::occ::addPoint(2, 3, 0.5);
  const int b = gmsh::model::occ::addPoint(8, 3, 0.5);
  const int curve = gmsh::model::occ::addLine(a, b);
  gmsh::model::occ::synchronize();
  gmsh::option::setNumber("Mesh.MeshSizeMin", 0.25);
  gmsh::option::setNumber("Mesh.MeshSizeMax", 0.25);
  gmsh::model::mesh::generate(2);

  std::size_t all = 0, referenced = 0;
  countNodes(all, referenced);
  check(all > referenced, "the construction curve must carry nodes outside the skin");
  const Result result = mat();
  check(result.skin.xyz.size() == 3 * referenced,
        "the nodes of the construction curve must not be sites");

  gmsh::model::mesh::clear({{1, curve}});
  gmsh::model::mesh::clear({{0, a}, {0, b}});
  std::size_t remaining = 0;
  countNodes(all, remaining);
  check(all == referenced && remaining == referenced,
        "only the nodes of the construction curve must have been removed");
  const Result reference = mat();
  check(result.skin.xyz == reference.skin.xyz && result.skin.triangles == reference.skin.triangles,
        "both skins must be identical for the comparison to be meaningful");
  check(result.raw.xyz == reference.raw.xyz && result.raw.triangles == reference.raw.triangles,
        "the raw MAT must not depend on the construction curve");
  check(result.filtered.xyz == reference.filtered.xyz &&
          result.filtered.triangles == reference.filtered.triangles,
        "the filtered MAT must not depend on the construction curve");
}
} // namespace

int main()
{
  try {
    stableCompaction();
    identityKeepsCoordinateBits();
    unknownTriangleNodeIsRejected();
    gmsh::initialize();
    gmsh::option::setNumber("General.Terminal", 0);
    gmsh::option::setNumber("General.NumThreads", 1);
    constructionCurveDoesNotChangeTheMat();
    gmsh::finalize();
    std::cout << "MatSkinSites: 4 tests passed\n";
    return 0;
  }
  catch(const std::exception &e) {
    std::cerr << "MatSkinSites test: " << e.what() << '\n';
    if(gmsh::isInitialized()) gmsh::finalize();
    return 1;
  }
}
