#include "MatPipeline.h"
#include "core/matGmsh.h"
#include "core/matPolygonFan.h"
#include "cadSurfacePatchAnalyzer.h"
#include "GModel.h"
#include "GFace.h"
#include "Context.h"
#include "MTriangle.h"
#include "MLine.h"
#include "GEdge.h"
#include "GmshMessage.h"
#include "DiscreteCADMeshBoolean.h"
#include "DiscreteCADWinding.h"
#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <stdexcept>
#include <unordered_map>

namespace {
using Clock = std::chrono::steady_clock;
double elapsed(Clock::time_point start)
{ return std::chrono::duration<double>(Clock::now() - start).count(); }

struct ContextGuard {
  GModel *previous;
  double algorithm = 1., randomFactor = 0.;
  ContextGuard(GModel *model) : previous(GModel::current())
  {
    GModel::setCurrent(model);
    // The native application initializes GmshGlobal, but not the public API
    // flag. Attach the extracted API-based helpers to that existing session.
    // GmshInitialize is idempotent; preserve the application's error policy.
    if(!gmsh::isInitialized()) {
      const int abortOnError = CTX::instance()->abortOnError;
      const int terminal = CTX::instance()->terminal;
      gmsh::initialize(0, nullptr, false);
      CTX::instance()->abortOnError = abortOnError;
      CTX::instance()->terminal = terminal;
    }
    gmsh::option::getNumber("Mesh.Algorithm3D", algorithm);
    gmsh::option::getNumber("Mesh.RandomFactor3D", randomFactor);
    gmsh::option::setNumber("Mesh.Algorithm3D", 10);
  }
  ~ContextGuard()
  {
    gmsh::option::setNumber("Mesh.Algorithm3D", algorithm);
    gmsh::option::setNumber("Mesh.RandomFactor3D", randomFactor);
    GModel::setCurrent(previous);
  }
};
}

// The bridge alone sees the extracted legacy storage. No GModel or MVertex
// ownership is transferred into that storage; all shared vertex IDs survive.
struct MatNativeAccess {
  static matgmsh_native::Mesh skin(const matGmsh &mat)
  {
    matgmsh_native::Mesh mesh;
    mesh.xyz = mat.del.seeds;
    mesh.triangles.assign(mat.del.triangles.begin(), mat.del.triangles.end());
    mesh.branch.assign(mesh.triangles.size() / 3, 0);
    for(std::size_t i = 0; i < mesh.branch.size(); ++i) mesh.parent.push_back(i);
    return mesh;
  }

  // Interior tetrahedra, their unmerged dual complex and its certificate.
  static matgmsh::tet::Report tetRaw(const matGmsh &mat, unsigned threads,
                                     matgmsh::tet::Dual &dual,
                                     std::vector<signed char> &skinSide)
  {
    const std::size_t sites = mat.del.seeds.size() / 3;
    const std::vector<int> skin(mat.del.triangles.begin(), mat.del.triangles.end());
    std::vector<int> tets(mat.del.tetrahedra.size());
    for(std::size_t i = 0; i < tets.size(); ++i) tets[i] = int(mat.del.tetrahedra[i]) - 1;
    const auto classification = matgmsh::tet::classify(mat.del.seeds, skin, tets, threads);
    dual = matgmsh::tet::buildDual(tets, classification.interior, sites);
    skinSide = matgmsh::tet::skinSides(skin, tets, classification);
    return matgmsh::tet::certify(skin, tets, classification, dual, sites);
  }

  // Erosion thickness and collapse of the dual complex. The CAD enters through
  // the patch of each skin triangle and site, and the mesh segments of the
  // CAD curves (convex edges anchor the wings).
  static matgmsh::tet::Filtered collapse(const matGmsh &mat, GModel *model,
                                         const CadSurfacePatchAnalyzer::Result &patches,
                                         const matgmsh::tet::Dual &dual,
                                         const std::vector<signed char> &skinSide,
                                         double thickness, double threshold)
  {
    const std::size_t sites = mat.del.nodeTags.size();
    const std::vector<int> skin(mat.del.triangles.begin(), mat.del.triangles.end());
    std::vector<int> tets(mat.del.tetrahedra.size());
    for(std::size_t i = 0; i < tets.size(); ++i) tets[i] = int(mat.del.tetrahedra[i]) - 1;
    matgmsh::tet::FilterInput in;
    in.sites = &mat.del.seeds;
    in.vertices = &mat.vor.vertices;
    in.skin = &skin;
    in.tetrahedra = &tets;
    in.skinSide = skinSide;
    in.thickness = thickness;
    in.threshold = threshold;
    const auto patchOf = [&](int face) {
      const auto found = patches.patchByFaceTag.find(face);
      return found == patches.patchByFaceTag.end() ? -1 : found->second;
    };
    in.patchOffsets.push_back(0);
    for(std::size_t s = 0; s < sites; ++s) {
      std::set<int> around;
      for(int face : mat.del.seedFaces[s])
        if(patchOf(face) >= 0) around.insert(patchOf(face));
      in.patchValues.insert(in.patchValues.end(), around.begin(), around.end());
      in.patchOffsets.push_back(in.patchValues.size());
    }
    std::unordered_map<std::size_t, int> siteOf;
    for(std::size_t s = 0; s < sites; ++s) siteOf[mat.del.nodeTags[s]] = int(s);
    const auto site = [&](const MVertex *vertex) {
      const auto found = siteOf.find(vertex->getNum());
      return found == siteOf.end() ? -1 : found->second;
    };
    // CAD face of each skin triangle; -1 for a triangle found on two faces.
    std::map<std::array<int, 3>, int> faceOf;
    for(auto face = model->firstFace(); face != model->lastFace(); ++face)
      for(const MTriangle *triangle : (*face)->triangles) {
        std::array<int, 3> key = {{site(triangle->getVertex(0)), site(triangle->getVertex(1)),
                                   site(triangle->getVertex(2))}};
        std::sort(key.begin(), key.end());
        const auto inserted = faceOf.emplace(key, (*face)->tag());
        if(!inserted.second && inserted.first->second != (*face)->tag()) inserted.first->second = -1;
      }
    in.trianglePatch.reserve(skin.size() / 3);
    for(std::size_t t = 0; t < skin.size() / 3; ++t) {
      std::array<int, 3> key = {{skin[3 * t], skin[3 * t + 1], skin[3 * t + 2]}};
      std::sort(key.begin(), key.end());
      const auto found = faceOf.find(key);
      in.trianglePatch.push_back(found == faceOf.end() ? -1 : patchOf(found->second));
    }
    for(auto edge = model->firstEdge(); edge != model->lastEdge(); ++edge)
      for(const MLine *line : (*edge)->lines) {
        const int a = site(line->getVertex(0)), b = site(line->getVertex(1));
        if(a >= 0 && b >= 0 && a != b) in.curves.push_back({{a, b}});
      }
    return matgmsh::tet::filter(dual, in);
  }

  // The polygons of the unmerged dual become the Voronoi faces, the kept ones
  // (all if keep is null) coloured by sheet. Coincident circumcentres are
  // merged in this copy only: the dual complex itself is never modified.
  static void select(matGmsh &mat, const matgmsh::tet::Dual &dual,
                     const std::vector<unsigned char> *keep)
  {
    mat.vor.faces.clear();
    mat.vor.faces.reserve(dual.size());
    std::vector<char> selected(dual.size(), 1);
    for(std::size_t p = 0; p < dual.size(); ++p) {
      std::vector<int> cycle(dual.cycles.begin() + dual.offsets[p],
                             dual.cycles.begin() + dual.offsets[p + 1]);
      mat.vor.faces.emplace_back(matGmshEdge(dual.sitePair[p][0], dual.sitePair[p][1]), cycle);
      if(keep) selected[p] = (*keep)[p] != 0;
    }
    mat.colorSelectedVoronoiFaces(selected);
  }

  // With flat non-null, triangles of exactly zero area are counted there and
  // left out instead of making the mesh invalid.
  static matgmsh_native::Mesh mesh(const matGmsh &mat, std::size_t *flat = nullptr)
  {
    matgmsh_native::Mesh mesh;
    const auto skip = [&](int a, int b, int c) {
      if(!flat) return false;
      const double *p = &mesh.xyz[3 * a], *q = &mesh.xyz[3 * b], *r = &mesh.xyz[3 * c];
      double u[3], w[3], n2 = 0.;
      for(int k = 0; k < 3; ++k) { u[k] = q[k] - p[k]; w[k] = r[k] - p[k]; }
      for(int k = 0; k < 3; ++k) {
        const double n = u[(k+1)%3] * w[(k+2)%3] - u[(k+2)%3] * w[(k+1)%3];
        n2 += n * n;
      }
      if(std::isfinite(n2) && n2 != 0.) return false;
      ++*flat;
      return true;
    };
    std::map<int, int> index;
    auto vertex = [&](int old) {
      auto p = index.emplace(old, static_cast<int>(mesh.xyz.size() / 3));
      if(p.second) mesh.xyz.insert(mesh.xyz.end(),
        mat.vor.vertices.begin() + 3 * old, mat.vor.vertices.begin() + 3 * old + 3);
      return p.first->second;
    };
    for(std::size_t f = 0; f < mat.vor.faces.size(); ++f) {
      if(mat.vor.faceColors[f] < 0) continue;
      const auto &poly = mat.vor.faces[f].verts;
      if(poly.size() < 3) throw std::runtime_error("Retained MAT polygon has fewer than three vertices");
      std::vector<matgmsh::polygon_fan::Point> points;
      std::array<double, 3> center{{0., 0., 0.}};
      for(int v : poly) {
        if(v < 0) throw std::runtime_error("Unbounded polygon in retained MAT");
        points.push_back({{mat.vor.vertices[3*v], mat.vor.vertices[3*v+1], mat.vor.vertices[3*v+2]}});
        for(int k = 0; k < 3; ++k) center[k] += points.back()[k];
      }
      for(int k = 0; k < 3; ++k) center[k] *= 1. / poly.size();
      const auto selected = matgmsh::polygon_fan::selectCenter(points, center);
      if(selected.status != matgmsh::polygon_fan::Status::Unsupported) center = selected.center;
      std::vector<int> ids;
      for(int v : poly) ids.push_back(vertex(v));
      if(ids.size() == 3) {
        if(skip(ids[0], ids[1], ids[2])) continue;
        mesh.triangles.insert(mesh.triangles.end(), ids.begin(), ids.end());
        mesh.branch.push_back(mat.vor.faceColors[f]);
        mesh.parent.push_back(f);
        continue;
      }
      const int c = mesh.xyz.size() / 3;
      mesh.xyz.insert(mesh.xyz.end(), center.begin(), center.end());
      for(std::size_t i = 0; i < ids.size(); ++i) {
        if(skip(ids[i], ids[(i+1)%ids.size()], c)) continue;
        mesh.triangles.insert(mesh.triangles.end(), {ids[i], ids[(i+1)%ids.size()], c});
        mesh.branch.push_back(mat.vor.faceColors[f]);
        mesh.parent.push_back(f);
      }
    }
    return mesh;
  }

  static void filter(matGmsh &mat, const CadSurfacePatchAnalyzer::Result &patches,
                     bool legacyCleanup)
  {
    const auto rawColors = mat.snapshotVoronoiFaceColors();
    std::map<int, int> classes, closure;
    mat.filterVoronoiBranchesByClassification("", "", &std::cout, &classes,
      matGmsh::BranchClassificationPolicy(false, false, false, true), &closure);
    std::map<int, std::set<int>> disjoint;
    for(const auto &entry : patches.patchByFaceTag) disjoint[entry.first].insert(entry.second);
    mat.filterMixedBranchWings("", rawColors, disjoint, &std::cout);
    const auto sewn = mat.restoreSewnClosureDisks(rawColors, &std::cout);
    mat.filterSmallTerminalBranches(rawColors, &std::cout);
    for(const auto &entry : sewn) { closure[entry.first] = entry.second; classes[entry.first] = 1; }
    auto entities = rawColors;
    auto selected = mat.snapshotVoronoiFaceColors();
    for(std::size_t i = 0; i < entities.size(); ++i) {
      auto target = closure.find(rawColors[i]);
      if(target == closure.end()) continue;
      entities[i] = target->second;
      if(selected[i] >= 0) selected[i] = target->second;
    }
    mat.restoreVoronoiFaceColors(selected);
    if(legacyCleanup) {
      mat.rebuildConnectedComponentsPerColor(entities, classes);
      mat.rebuildFinalSurfaceTopology(true);
      if(mat.discardClosedRetainedSurfaces()) mat.rebuildFinalSurfaceTopology(true);
    }
    else {
      // Preserve all material components/closed sheets; no global largest-only
      // cleanup. This explicit policy is audited separately from legacy parity.
      mat.rebuildFilteredTopology(true);
    }
  }

  static bool project(matGmsh &mat, const CadSurfacePatchAnalyzer::Result &patches,
                      const matgmsh_native::Mesh &skinMesh,
                      matgmsh_native::Mesh &proposal, std::string &error)
  {
    const auto coordinates = mat.vor.vertices;
    const auto labels = mat.vor.faceColors;
    const auto original = mesh(mat);
    try {
      mat.projectRegularBranchVerticesToLocalMidSurfacePasses(2, 8, 1.e-8,
                                                            &patches.patchesByFaceTag, false);
      if(mat.vor.faceColors != labels) throw std::runtime_error("Projection changed retained branches");
      proposal = mesh(mat);
      if(!matgmsh_native::validateMesh(proposal, error)) throw std::runtime_error(error);
      if(proposal.triangles != original.triangles || proposal.branch != original.branch ||
         proposal.parent != original.parent)
        throw std::runtime_error("Projection changed incidence");
      if(!matgmsh_native::validateNoSelfIntersections(proposal, error))
        throw std::runtime_error("Projection rejected: " + error);
      if(!matgmsh_native::validateContainedInSkin(proposal, skinMesh, error))
        throw std::runtime_error("Projection rejected: " + error);
      return true;
    }
    catch(const std::exception &e) { error = e.what(); }
    catch(...) { error = "Projection raised an unknown error"; }
    mat.vor.vertices = coordinates;
    mat.vor.faceColors = labels;
    return false;
  }
};

namespace matgmsh_native {
bool validateNoSelfIntersections(const Mesh &mesh, std::string &error)
{
  if(!validateMesh(mesh, error)) return false;
  std::vector<std::array<int, 2> > pairs;
  if(!meshSelfIntersections(mesh.xyz, mesh.triangles, pairs, error, true)) return false;
  if(pairs.empty()) return true;
  error = "self-intersection between triangles " + std::to_string(pairs[0][0]) +
          " and " + std::to_string(pairs[0][1]);
  return false;
}

bool validateContainedInSkin(const Mesh &mesh, const Mesh &skin, std::string &error)
{
  if(!validateMesh(mesh, error) || !validateMesh(skin, error)) return false;
  const auto skinTopology = topology(skin);
  if(skinTopology.freeEdges || skinTopology.junctionEdges) {
    error = "projection containment requires a closed manifold skin";
    return false;
  }
  // Testing only the original centers or vertices misses triangles crossing
  // concave walls or cavities. Native co-refinement partitions every triangle
  // at the skin before classifying its descendants; the proposal is unchanged.
  Mesh cut;
  std::vector<int> birth;
  if(!meshBoolean(3, mesh.xyz, mesh.triangles, skin.xyz, skin.triangles,
                  cut.xyz, cut.triangles, birth, error)) {
    error = "skin containment co-refinement failed: " + error;
    return false;
  }
  std::vector<std::array<double, 3> > coordinates;
  std::vector<std::array<int, 3> > triangles;
  for(std::size_t v = 0; v < skin.xyz.size(); v += 3)
    coordinates.push_back({{skin.xyz[v], skin.xyz[v + 1], skin.xyz[v + 2]}});
  for(std::size_t f = 0; f < skin.triangles.size(); f += 3)
    triangles.push_back({{skin.triangles[f], skin.triangles[f + 1], skin.triangles[f + 2]}});
  DiscreteCADWinding winding(coordinates, triangles);
  auto triangleArea = [](const Mesh &m, std::size_t f) {
    const double *a = &m.xyz[3 * m.triangles[3 * f]];
    const double *b = &m.xyz[3 * m.triangles[3 * f + 1]];
    const double *c = &m.xyz[3 * m.triangles[3 * f + 2]];
    double u[3], v[3], n[3];
    for(int k = 0; k < 3; ++k) { u[k] = b[k] - a[k]; v[k] = c[k] - a[k]; }
    for(int k = 0; k < 3; ++k)
      n[k] = u[(k + 1) % 3] * v[(k + 2) % 3] - u[(k + 2) % 3] * v[(k + 1) % 3];
    return .5 * std::sqrt(n[0]*n[0] + n[1]*n[1] + n[2]*n[2]);
  };
  std::vector<double> covered(mesh.triangles.size() / 3, 0.);
  for(std::size_t f = 0; f < birth.size(); ++f) {
    if(birth[f] < 0 || std::size_t(birth[f]) >= covered.size()) continue;
    std::array<double, 3> center{{0., 0., 0.}};
    for(int k = 0; k < 3; ++k)
      for(int d = 0; d < 3; ++d) center[d] += cut.xyz[3 * cut.triangles[3 * f + k] + d] / 3.;
    double w = std::abs(winding(center.data()));
    if(!std::isfinite(w) || w <= .5 + 1.e-5)
      w = std::abs(winding.exact(center.data()));
    if(!std::isfinite(w) || w <= .5 + 1.e-9) {
      error = "triangle " + std::to_string(birth[f]) + " has a part outside the source skin";
      return false;
    }
    covered[birth[f]] += triangleArea(cut, f);
  }
  for(std::size_t f = 0; f < covered.size(); ++f) {
    const double original = triangleArea(mesh, f);
    if(!std::isfinite(covered[f]) || std::abs(covered[f] - original) > 1.e-8 * original + 1.e-24) {
      error = "skin containment failed to preserve triangle " + std::to_string(f);
      return false;
    }
  }
  return true;
}

bool computeCurrent(const Options &options, Result &result, std::string &error)
{ return compute(GModel::current(), options, result, error); }

bool compute(GModel *source, const Options &options, Result &result, std::string &error)
{
  error.clear(); result = Result{};
  if(!source) { error = "No source GModel"; return false; }
  if(!std::isfinite(options.thickness) || options.thickness <= 0. ||
     !std::isfinite(options.extensionLength) || options.extensionLength < 0. ||
     options.extensionLayers < 1 || !std::isfinite(options.windingThreshold) ||
     options.windingThreshold <= 0. || options.windingThreshold >= 1. ||
     !std::isfinite(options.collapseThreshold) || options.collapseThreshold < 0.) {
    error = "Invalid MAT thickness, winding threshold or extension settings"; return false;
  }
  try {
    ContextGuard guard(source);
    bool haveSurfaceParametrization = true;
    for(auto face = source->firstFace(); face != source->lastFace(); ++face) {
      if((*face)->triangles.empty() || !(*face)->quadrangles.empty())
        throw std::runtime_error("MAT needs a complete first-order triangular skin; face " +
                                 std::to_string((*face)->tag()) + " is unmeshed or contains quadrangles");
      for(const auto *triangle : (*face)->triangles)
        if(triangle->getNumVertices() != 3)
          throw std::runtime_error("MAT needs first-order triangles; face " +
                                   std::to_string((*face)->tag()) + " contains higher-order triangles");
      haveSurfaceParametrization = haveSurfaceParametrization && (*face)->haveParametrization();
    }
    std::vector<int> types;
    std::vector<std::vector<std::size_t>> elementTags, nodeTags;
    gmsh::model::mesh::getElements(types, elementTags, nodeTags, 3);
    if(!types.empty()) throw std::runtime_error("Use a surface-only input mesh, without volume nodes");
    const bool tetRaw = options.raw == RawMode::Tet;
    if(options.filter == FilterMode::Collapse && !tetRaw)
      throw std::runtime_error("The collapse filter needs the tetrahedron-based raw MAT");
    if(options.filter == FilterMode::Legacy && tetRaw)
      throw std::runtime_error("The legacy filter needs the legacy raw MAT");
    auto start = Clock::now();
    matGmsh mat;
    matgmsh::tet::Dual dual;
    std::vector<signed char> skinSide;
    std::size_t flat = 0;
    if(tetRaw) {
      double configured = 1.;
      gmsh::option::getNumber("General.NumThreads", configured);
      const unsigned threads = std::isfinite(configured) && configured >= 1. ?
        static_cast<unsigned>(std::min(configured, 256.)) : 1u;
      mat.computeVoronoi(false);
      result.tet = MatNativeAccess::tetRaw(mat, threads, dual, skinSide);
      if(!result.tet.certified)
        result.warnings.push_back("The certificate of the interior tetrahedra failed: the raw MAT may not have the topology of the solid. See \"tet\" in the report.");
      MatNativeAccess::select(mat, dual, nullptr);
      result.skin = MatNativeAccess::skin(mat);
      result.raw = MatNativeAccess::mesh(mat, &flat);
    }
    else {
      mat.computeVoronoi();
      mat.computeVoronoiWindingNumbersAtCircumcenters();
      mat.colorVoronoiFaces(options.windingThreshold);
      result.skin = MatNativeAccess::skin(mat);
      result.raw = MatNativeAccess::mesh(mat);
    }
    result.rawSeconds = elapsed(start);
    start = Clock::now();
    CadSurfacePatchAnalyzer::Result patches;
    if(haveSurfaceParametrization) {
      patches = CadSurfacePatchAnalyzer().analyzeCurrentModel();
    }
    else {
      // A loaded surface mesh can preserve entity tags without carrying CAD
      // parametrizations. Keep those entities as distinct support patches;
      // inverse CAD evaluation cannot establish tangency between them.
      int patch = 0;
      for(auto face = source->firstFace(); face != source->lastFace(); ++face, ++patch) {
        const int tag = (*face)->tag();
        patches.patchByFaceTag[tag] = patch;
        patches.patchesByFaceTag[tag].insert(patch);
        patches.faceTagsByPatch.push_back({tag});
      }
      result.warnings.push_back("Surface parametrization is unavailable: each source face is a separate support patch; normal-based filtering may retain additional MAT material.");
    }
    if(options.filter == FilterMode::Legacy) {
      MatNativeAccess::filter(mat, patches, options.legacyCleanup);
      result.filtered = MatNativeAccess::mesh(mat);
    }
    else if(options.filter == FilterMode::Collapse) {
      const auto kept = MatNativeAccess::collapse(mat, source, patches, dual, skinSide,
                                                  options.thickness, options.collapseThreshold);
      result.collapse = kept.report;
      if(!kept.report.materialSide)
        result.warnings.push_back("The material side of the skin is not known on every shell: there, convex edges are not identified and no wing is removed as such; only the erosion thickness filters the MAT.");
      if(kept.report.wireEdges)
        result.warnings.push_back(std::to_string(kept.report.wireEdges) + " edges of the collapsed MAT carry no surface: the retained surface alone does not have the topology of the solid.");
      MatNativeAccess::select(mat, dual, &kept.keep);
      result.filtered = MatNativeAccess::mesh(mat, &flat);
    }
    else
      result.filtered = result.raw;
    if(flat)
      result.warnings.push_back(std::to_string(flat) + " triangles of zero area were left out of the MAT meshes.");
    if(!validateMesh(result.filtered, error)) return false;
    result.filteredTopology = topology(result.filtered);
    result.filterSeconds = elapsed(start);
    if(options.legacyCleanup && options.filter == FilterMode::Legacy)
      result.warnings.push_back("Legacy cleanup keeps the largest component and removes closed branch surfaces; use explicit keep-components policy to disable it.");
    if(options.stopAfter == Stage::Filtered) return true;
    start = Clock::now();
    result.projected = result.filtered;
    if(options.project && !haveSurfaceParametrization) {
      result.projectionStatus = "unchanged";
      result.projectionMessage = "Projection skipped because source surface parametrization is unavailable; the filtered MAT is retained exactly.";
    }
    else if(options.project) {
      Mesh proposal;
      std::string why;
      if(MatNativeAccess::project(mat, patches, result.skin, proposal, why) &&
         proposal.triangles == result.filtered.triangles &&
         proposal.branch == result.filtered.branch && proposal.parent == result.filtered.parent) {
        result.projectionStatus = proposal.xyz == result.filtered.xyz ? "unchanged" : "applied";
        result.projected = std::move(proposal);
        result.projectionMessage = "Local orientation/stretch, final self-intersection and full skin-containment guards passed; shared topology retained. Swept motion is not checked.";
      }
      else {
        result.projectionStatus = "unchanged";
        result.projectionMessage = why.empty() ? "Projection changed incidence; original MAT retained" : why;
      }
    }
    result.projectionSeconds = elapsed(start);
    if(options.stopAfter == Stage::Projected) return true;
    start = Clock::now();
    std::string why;
    if(!extend(result.projected, result.skin, options, result.extended, result.extension, why)) {
      result.extended = result.projected;
      result.extension.complete = false;
      result.extension.message = why;
      result.warnings.push_back("Extension failed; the prior MAT is retained: " + why);
    }
    result.extensionSeconds = elapsed(start);
    return true;
  }
  catch(const std::exception &e) { error = e.what(); }
  catch(const std::string &e) { error = e; }
  catch(...) { error = "Unknown error in native MAT pipeline"; }
  return false;
}
} // namespace matgmsh_native
