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

Result mat(bool legacy)
{
  Options options;
  options.thickness = 1.;
  if(legacy) {
    options.raw = RawMode::Legacy;
    options.filter = FilterMode::Legacy;
  }
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
  // The default pipeline (tetrahedron-based raw MAT, collapse), then the
  // legacy one.
  const Result results[2] = {mat(false), mat(true)};
  for(const Result &result : results)
    check(result.skin.xyz.size() == 3 * referenced,
          "the nodes of the construction curve must not be sites");

  gmsh::model::mesh::clear({{1, curve}});
  gmsh::model::mesh::clear({{0, a}, {0, b}});
  std::size_t remaining = 0;
  countNodes(all, remaining);
  check(all == referenced && remaining == referenced,
        "only the nodes of the construction curve must have been removed");
  for(int legacy = 0; legacy < 2; ++legacy) {
    const Result &result = results[legacy];
    const Result reference = mat(legacy != 0);
    check(result.skin.xyz == reference.skin.xyz && result.skin.triangles == reference.skin.triangles,
          "both skins must be identical for the comparison to be meaningful");
    check(!result.raw.triangles.empty() && result.raw.xyz == reference.raw.xyz &&
            result.raw.triangles == reference.raw.triangles,
          "the raw MAT must not depend on the construction curve");
    check(!result.filtered.triangles.empty() && result.filtered.xyz == reference.filtered.xyz &&
            result.filtered.triangles == reference.filtered.triangles,
          "the filtered MAT must not depend on the construction curve");
  }
  check(results[0].tet.computed && results[0].tet.certified && results[0].collapse.computed &&
          !results[1].tet.computed, "the default raw MAT is the certified tetrahedron-based one");
}

bool same(const Mesh &a, const Mesh &b)
{
  return a.xyz == b.xyz && a.triangles == b.triangles && a.branch == b.branch && a.parent == b.parent;
}

// The stages run one at a time give what compute() gives; a filter run again
// gives the same MAT without a new raw MAT, and discards the later stages;
// the legacy filter, which changes the raw MAT in place, can be run again
// too; a surface mesh that is not the one of the raw MAT is refused.
void sessionRunsTheStagesOneAtATime()
{
  const auto plate = [](double size) {
    gmsh::clear();
    gmsh::model::add("plate");
    gmsh::model::occ::addBox(0, 0, 0, 10, 6, 1);
    gmsh::model::occ::synchronize();
    gmsh::option::setNumber("Mesh.MeshSizeMin", size);
    gmsh::option::setNumber("Mesh.MeshSizeMax", size);
    gmsh::model::mesh::generate(2);
  };
  plate(0.25);
  const Result reference = mat(false), legacyReference = mat(true);
  Options options;
  options.thickness = 1.;
  Session session;
  std::string error;
  check(!session.filter(currentModel(), options, error) && !error.empty(),
        "a filter without a raw MAT must be refused");
  check(session.raw(currentModel(), options, error), "raw stage failed: " + error);
  check(session.hasRaw() && !session.hasFiltered() && same(session.result().raw, reference.raw),
        "the raw MAT of the session must be that of compute()");
  check(session.filter(currentModel(), options, error), "filter stage failed: " + error);
  check(session.hasFiltered() && same(session.result().filtered, reference.filtered) &&
          session.result().warnings == reference.warnings,
        "the filtered MAT of the session must be that of compute()");

  Options wide = options;
  wide.collapseThreshold = 1.;
  check(session.filter(currentModel(), wide, error), "second filter failed: " + error);
  check(!session.result().filtered.triangles.empty() &&
          session.result().filtered.triangles.size() < reference.filtered.triangles.size(),
        "a larger threshold must remove more of the MAT");
  check(same(session.result().raw, reference.raw), "the raw MAT must be kept between the filters");
  check(session.extend(currentModel(), wide, error) && session.hasExtended() && session.hasProjected(),
        "extension stage failed: " + error);
  check(session.filter(currentModel(), options, error) && !session.hasProjected() &&
          !session.hasExtended() && session.result().extended.triangles.empty(),
        "a filter run again must discard the later stages");
  check(same(session.result().filtered, reference.filtered),
        "a filter run again with the first threshold must give the first MAT");

  Options legacy = options;
  legacy.raw = RawMode::Legacy;
  legacy.filter = FilterMode::Legacy;
  check(!session.filter(currentModel(), legacy, error), "the legacy filter needs the legacy raw MAT");
  check(session.raw(currentModel(), legacy, error) && session.filter(currentModel(), legacy, error),
        "legacy stages failed: " + error);
  check(same(session.result().filtered, legacyReference.filtered),
        "the legacy MAT of the session must be that of compute()");
  check(session.filter(currentModel(), legacy, error) &&
          same(session.result().filtered, legacyReference.filtered),
        "the legacy filter run again must give the same MAT");

  check(session.raw(currentModel(), options, error), "raw stage failed: " + error);
  plate(0.3);
  check(!session.filter(currentModel(), options, error) &&
          error.find("has changed") != std::string::npos && !session.hasFiltered(),
        "a filter on another surface mesh must be refused");
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
    sessionRunsTheStagesOneAtATime();
    gmsh::finalize();
    std::cout << "MatSkinSites: 5 tests passed\n";
    return 0;
  }
  catch(const std::exception &e) {
    std::cerr << "MatSkinSites test: " << e.what() << '\n';
    if(gmsh::isInitialized()) gmsh::finalize();
    return 1;
  }
}
