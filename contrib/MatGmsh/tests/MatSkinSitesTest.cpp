#include "MatPipeline.h"
#include "matSkinSites.h"
#include "gmsh.h"
#include <cmath>
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

double areaOf(const Mesh &mesh)
{
  double area = 0.;
  for(std::size_t t = 0; t < mesh.triangles.size() / 3; ++t) {
    const double *a = &mesh.xyz[3 * mesh.triangles[3 * t]], *b = &mesh.xyz[3 * mesh.triangles[3 * t + 1]],
                 *c = &mesh.xyz[3 * mesh.triangles[3 * t + 2]];
    const double u[3] = {b[0] - a[0], b[1] - a[1], b[2] - a[2]}, v[3] = {c[0] - a[0], c[1] - a[1], c[2] - a[2]};
    const double n[3] = {u[1] * v[2] - u[2] * v[1], u[2] * v[0] - u[0] * v[2], u[0] * v[1] - u[1] * v[0]};
    area += .5 * std::sqrt(n[0] * n[0] + n[1] * n[1] + n[2] * n[2]);
  }
  return area;
}

// The filtered MAT of a plate of 10 by 6 stops half a thickness short of its
// edges. Extended in its plane, cut by the skin, it is the whole mid-plane,
// of area 60; a ribbon along its boundary, cut by the skin, gives the same
// area.
void plateIsExtendedToItsEdges()
{
  gmsh::clear();
  gmsh::model::add("plate");
  gmsh::model::occ::addBox(0, 0, 0, 10, 6, 1);
  gmsh::model::occ::synchronize();
  gmsh::option::setNumber("Mesh.MeshSizeMin", 0.25);
  gmsh::option::setNumber("Mesh.MeshSizeMax", 0.25);
  gmsh::model::mesh::generate(2);
  Options options;
  options.thickness = 1.;
  options.wingBranches = true;
  options.collapseThreshold = 0.;
  Result result;
  std::string error;
  check(computeCurrent(options, result, error), "pipeline failed: " + error);
  const std::vector<BranchPlane> planes = branchPlanes(result.filtered);
  check(planes.size() == 1 && planes[0].deviation < 1.e-6 && std::abs(planes[0].area - 45.) < 2.,
        "the filtered MAT of a plate is one flat branch, half a thickness short of the edges");
  PlaneExtension inPlane;
  check(extendBranchInPlane(result.filtered, result.skin, planes[0], .1, .25, 2., inPlane, error),
        "extension in the plane failed: " + error);
  check(!inPlane.reachesFrame && inPlane.keptFragments == 1 && std::abs(inPlane.addedArea - 60.) < 1.e-6 &&
          std::abs(areaOf(inPlane.result) - 60.) < 1.e-6,
        "the plate extended in its plane must be its whole mid-plane");
  Ribbon ribbon;
  check(branchRibbon(result.filtered, planes[0].branch, 2., 4, ribbon, error), "ribbon failed: " + error);
  check(ribbon.loops == 1 && ribbon.freeEdges == ribbon.boundaryEdges && ribbon.freeEdges > 0,
        "the boundary of the MAT of a plate is one free loop");
  PlaneExtension byRibbon;
  check(extendBranchByRibbon(result.filtered, result.skin, planes[0].branch, ribbon, byRibbon, error),
        "extension by a ribbon failed: " + error);
  check(std::abs(areaOf(byRibbon.result) - 60.) < .3,
        "the plate extended by a ribbon must reach its edges");
}
// A rib that stands on a plate over a part of its length: in the plane of
// the rib, the fragment around it goes on inside the plate, between its face
// and its mid-surface, beyond the two ends of the rib. The end faces of the
// rib are prolonged into the plate: the rib stops at its ends.
void ribStopsAtItsEnds()
{
  gmsh::clear();
  gmsh::model::add("rib");
  const int plate = gmsh::model::occ::addBox(0, 0, 0, 20, 12, 1);
  const int rib = gmsh::model::occ::addBox(6, 5.5, 1, 8, 1, 4);
  gmsh::vectorpair fused;
  std::vector<gmsh::vectorpair> map;
  gmsh::model::occ::fuse({{3, plate}}, {{3, rib}}, fused, map);
  gmsh::model::occ::synchronize();
  gmsh::option::setNumber("Mesh.MeshSizeMin", 0.2);
  gmsh::option::setNumber("Mesh.MeshSizeMax", 0.2);
  gmsh::model::mesh::generate(2);
  Options options;
  options.thickness = 1.;
  options.wingBranches = true;
  options.collapseThreshold = 0.;
  Result result;
  std::string error;
  check(computeCurrent(options, result, error), "pipeline failed: " + error);
  Mesh work = result.filtered;
  // the plate first, then the rib: the flat branch whose plane is across y
  for(int pass = 0; pass < 2; ++pass) {
    const BranchPlane *found = nullptr;
    const std::vector<BranchPlane> planes = branchPlanes(work);
    for(const BranchPlane &candidate : planes) {
      if(candidate.deviation > .1) continue;
      const double length = std::sqrt(candidate.normal[0] * candidate.normal[0] +
                                      candidate.normal[1] * candidate.normal[1] +
                                      candidate.normal[2] * candidate.normal[2]);
      if(std::abs(candidate.normal[pass == 0 ? 2 : 1]) > .99 * length && (!found || candidate.area > found->area))
        found = &candidate;
    }
    check(found != nullptr, pass == 0 ? "the plate must be a flat branch" : "the rib must be a flat branch");
    PlaneExtension extension;
    check(extendBranchInPlane(work, result.skin, *found, .1, .25, 2., extension, error),
          "extension in the plane failed: " + error);
    check(!extension.reachesFrame, "the skin must close the fragment");
    if(pass == 0)
      check(std::abs(extension.addedArea - 240.) < 1.e-6, "the plate must be its whole mid-plane");
    else {
      // 8 long, from the mid-surface of the plate to the top of the rib
      check(extension.fences >= 2, "the two end faces of the rib must be prolonged into the plate");
      check(std::abs(extension.addedArea - 36.) < .05,
            "the rib must stop at its ends: area " + std::to_string(extension.addedArea) + " for 36");
    }
    work = extension.result;
  }
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
    plateIsExtendedToItsEdges();
    ribStopsAtItsEnds();
    gmsh::finalize();
    std::cout << "MatSkinSites: 7 tests passed\n";
    return 0;
  }
  catch(const std::exception &e) {
    std::cerr << "MatSkinSites test: " << e.what() << '\n';
    if(gmsh::isInitialized()) gmsh::finalize();
    return 1;
  }
}
