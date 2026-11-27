#include "MatPipeline.h"
#include "core/matGmsh.h"
#include "core/matPolygonFan.h"
#include "core/matMessage.h"
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
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <cmath>
#include <iostream>
#include <limits>
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

namespace {
// One little-endian NumPy array (.npy, format 1.0) per file.
template <class T>
void writeArray(const std::filesystem::path &directory, const std::string &name,
                const char *type, const std::vector<T> &data, std::size_t columns = 0)
{
  const std::size_t rows = columns ? data.size() / columns : data.size();
  std::string header = std::string("{'descr': '") + type + "', 'fortran_order': False, 'shape': (" +
                       std::to_string(rows) + (columns ? ", " + std::to_string(columns) : ",") +
                       "), }";
  header.resize((10 + header.size() + 1 + 63) / 64 * 64 - 10 - 1, ' ');
  header += '\n';
  std::ofstream file(directory / (name + ".npy"), std::ios::binary);
  const unsigned char magic[10] = {0x93, 'N', 'U', 'M', 'P', 'Y', 1, 0,
                                   static_cast<unsigned char>(header.size() & 0xff),
                                   static_cast<unsigned char>(header.size() >> 8)};
  file.write(reinterpret_cast<const char *>(magic), 10);
  file.write(header.data(), header.size());
  file.write(reinterpret_cast<const char *>(data.data()), data.size() * sizeof(T));
  if(!file) throw std::runtime_error("Cannot write " + (directory / (name + ".npy")).string());
}
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

  // The vertices of the MAT, which a projection moves.
  static const std::vector<double> &vertices(const matGmsh &mat) { return mat.vor.vertices; }
  static void setVertices(matGmsh &mat, const std::vector<double> &xyz) { mat.vor.vertices = xyz; }

  // Interior tetrahedra, their circumcentres (the vertices of the dual: the
  // others are not needed, and most of the exact constructions are those of
  // exterior tetrahedra, flat ones on the faces of the part), their unmerged
  // dual complex and its certificate.
  static matgmsh::tet::Report tetRaw(matGmsh &mat, unsigned threads,
                                     matgmsh::tet::Dual &dual,
                                     std::vector<signed char> &skinSide)
  {
    const std::size_t sites = mat.del.seeds.size() / 3;
    const std::vector<int> skin(mat.del.triangles.begin(), mat.del.triangles.end());
    std::vector<int> tets(mat.del.tetrahedra.size());
    for(std::size_t i = 0; i < tets.size(); ++i) tets[i] = int(mat.del.tetrahedra[i]) - 1;
    const auto classification = matgmsh::tet::classify(mat.del.seeds, skin, tets, threads);
    mat.computeVoronoiVertices(&classification.interior);
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
                                         double thickness, double threshold,
                                         bool wingBranches, double branchAngle)
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
    in.wingBranches = wingBranches;
    in.branchAngle = branchAngle;
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

  // The dual complex for external tools: one .npy file per array.
  static void writeComplex(const matGmsh &mat, const CadSurfacePatchAnalyzer::Result &patches,
                           const matgmsh::tet::Dual &dual, const matgmsh::tet::Filtered *kept,
                           const matgmsh_native::Options &options, bool certified)
  {
    const std::filesystem::path directory(options.complexDirectory);
    std::filesystem::create_directories(directory);
    writeArray(directory, "site_xyz", "<f8", mat.del.seeds, 3);
    writeArray(directory, "site_node_tag", "<u8",
               std::vector<std::uint64_t>(mat.del.nodeTags.begin(), mat.del.nodeTags.end()));
    writeArray(directory, "skin_triangles", "<i4",
               std::vector<std::int32_t>(mat.del.triangles.begin(), mat.del.triangles.end()), 3);
    std::vector<std::int32_t> tets(mat.del.tetrahedra.size());
    for(std::size_t i = 0; i < tets.size(); ++i) tets[i] = std::int32_t(mat.del.tetrahedra[i]) - 1;
    writeArray(directory, "tetrahedra", "<i4", tets, 4);
    writeArray(directory, "vertex_xyz", "<f8", mat.vor.vertices, 3);
    std::vector<std::int64_t> offsets(1, 0);
    std::vector<std::int32_t> values;
    for(const auto &faces : mat.del.seedFaces) {
      values.insert(values.end(), faces.begin(), faces.end());
      offsets.push_back(std::int64_t(values.size()));
    }
    writeArray(directory, "site_faces_offsets", "<i8", offsets);
    writeArray(directory, "site_faces_values", "<i4", values);
    values.clear();
    for(const auto &entry : patches.patchByFaceTag) values.insert(values.end(), {entry.first, entry.second});
    writeArray(directory, "face_patch", "<i4", values, 2);
    values.clear();
    for(const auto &pair : dual.sitePair) values.insert(values.end(), {pair[0], pair[1]});
    writeArray(directory, "polygon_site_pair", "<i4", values, 2);
    writeArray(directory, "cycle_offsets", "<i8",
               std::vector<std::int64_t>(dual.offsets.begin(), dual.offsets.end()));
    writeArray(directory, "cycle_vertices", "<i4",
               std::vector<std::int32_t>(dual.cycles.begin(), dual.cycles.end()));
    if(kept) {
      writeArray(directory, "centroid", "<f8", kept->geometry.centroid, 3);
      writeArray(directory, "radius", "<f8", kept->geometry.radius);
      writeArray(directory, "area", "<f8", kept->geometry.area);
      writeArray(directory, "erosion_over_thickness", "<f8", kept->erosionOverThickness);
      writeArray(directory, "keep", "|u1", kept->keep);
      writeArray(directory, "wing", "|u1", kept->wing);
    }
    std::ofstream manifest(directory / "complex.json");
    manifest << "{\n\"format\":\"matgmsh-complex-1\",\n\"thickness\":" << options.thickness
             << ",\n\"collapse_threshold\":" << options.collapseThreshold
             << ",\n\"wing_branches\":" << (options.wingBranches ? "true" : "false")
             << ",\n\"wing_angle\":" << options.branchAngle
             << ",\n\"certified\":" << (certified ? "true" : "false")
             << ",\n\"filtered\":" << (kept ? "true" : "false")
             << ",\n\"sites\":" << mat.del.nodeTags.size()
             << ",\n\"tetrahedra\":" << mat.del.tetrahedra.size() / 4
             << ",\n\"polygons\":" << dual.size()
             << ",\n\"indices\":\"zero-based; a polygon is a cycle of tetrahedron ids, "
                "vertex_xyz holds one circumcentre per tetrahedron (NaN for the tetrahedra that "
                "are not interior: they are not computed); polygons are sorted by site "
                "pair\"\n}\n";
    if(!manifest) throw std::runtime_error("Cannot write the MAT complex manifest");
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
    // the vertices numbered in the order they are met, with the radius of
    // their ball: the distance to the first site of their polygon
    std::vector<int> index(mat.vor.vertices.size() / 3, -1);
    int site = -1;
    auto ball = [&](const double *x) {
      const std::size_t s = std::size_t(site);
      if(site < 0 || 3 * s + 2 >= mat.del.seeds.size())
        return std::numeric_limits<double>::quiet_NaN();
      const double *a = &mat.del.seeds[3 * s];
      return std::sqrt((x[0] - a[0]) * (x[0] - a[0]) + (x[1] - a[1]) * (x[1] - a[1]) +
                       (x[2] - a[2]) * (x[2] - a[2]));
    };
    auto vertex = [&](int old) {
      if(std::size_t(old) >= index.size())
        throw std::runtime_error("A MAT polygon has an unknown vertex");
      if(index[old] < 0) {
        index[old] = static_cast<int>(mesh.xyz.size() / 3);
        mesh.xyz.insert(mesh.xyz.end(),
          mat.vor.vertices.begin() + 3 * old, mat.vor.vertices.begin() + 3 * old + 3);
        mesh.radius.push_back(ball(&mat.vor.vertices[3 * old]));
      }
      return index[old];
    };
    for(std::size_t f = 0; f < mat.vor.faces.size(); ++f) {
      if(mat.vor.faceColors[f] < 0) continue;
      const auto &poly = mat.vor.faces[f].verts;
      site = mat.vor.faces[f].edge.a;
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
      mesh.radius.push_back(ball(center.data()));
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
    matInfo report; // each line of the reports of the filter is a message
    mat.filterVoronoiBranchesByClassification("", "", &report, &classes,
      matGmsh::BranchClassificationPolicy(false, false, false, true), &closure);
    std::map<int, std::set<int>> disjoint;
    for(const auto &entry : patches.patchByFaceTag) disjoint[entry.first].insert(entry.second);
    mat.filterMixedBranchWings("", rawColors, disjoint, &report);
    const auto sewn = mat.restoreSewnClosureDisks(rawColors, &report);
    mat.filterSmallTerminalBranches(rawColors, &report);
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

GModel *currentModel() { return GModel::current(); }

namespace {
bool validOptions(const Options &options)
{
  return std::isfinite(options.thickness) && options.thickness > 0. &&
         std::isfinite(options.extensionLength) && options.extensionLength >= 0. &&
         options.extensionLayers >= 1 && std::isfinite(options.windingThreshold) &&
         options.windingThreshold > 0. && options.windingThreshold < 1. &&
         std::isfinite(options.collapseThreshold) && options.collapseThreshold >= 0. &&
         std::isfinite(options.branchAngle) && options.branchAngle > 0. &&
         options.branchAngle <= 180.;
}
const char *const invalidOptions = "Invalid MAT thickness, winding threshold, wing angle or extension settings";
const char *const meshChanged = "The surface mesh of the model has changed since the raw MAT was computed";

// What the stages after the raw MAT read again from the model: the nodes of
// the triangles of its faces, by tag and position.
std::uint64_t skinStamp(GModel *model)
{
  std::uint64_t h = 1469598103934665603ull;
  const auto mix = [&h](const void *data, std::size_t size) {
    const unsigned char *bytes = static_cast<const unsigned char *>(data);
    for(std::size_t i = 0; i < size; ++i) { h ^= bytes[i]; h *= 1099511628211ull; }
  };
  for(auto face = model->firstFace(); face != model->lastFace(); ++face) {
    const int tag = (*face)->tag();
    mix(&tag, sizeof(tag));
    for(const auto *triangle : (*face)->triangles)
      for(int i = 0; i < 3; ++i) {
        const MVertex *vertex = triangle->getVertex(i);
        const std::size_t number = vertex->getNum();
        const double xyz[3] = {vertex->x(), vertex->y(), vertex->z()};
        mix(&number, sizeof(number));
        mix(xyz, sizeof(xyz));
      }
  }
  return h;
}
}

struct Session::Data {
  std::unique_ptr<matGmsh> mat;
  matgmsh::tet::Dual dual;
  std::vector<signed char> skinSide;
  CadSurfacePatchAnalyzer::Result patches;
  // the vertices of the MAT before a projection moved them
  std::vector<double> vertices;
  bool haveSurfaceParametrization = true, patchesReady = false;
  // moved: a projection changed the vertices; consumed: the legacy filter
  // changed the raw MAT in place; reselected: a filter chose among the
  // polygons of the tetrahedron-based raw MAT
  bool tetRaw = true, moved = false, consumed = false, reselected = false;
  bool raw = false, filtered = false, projected = false, extended = false;
  std::uint64_t stamp = 0;
  std::size_t flatRaw = 0;
  std::vector<std::string> rawWarnings, filterWarnings, extensionWarnings;
  Result result;
  void setWarnings()
  {
    result.warnings = rawWarnings;
    result.warnings.insert(result.warnings.end(), filterWarnings.begin(), filterWarnings.end());
    result.warnings.insert(result.warnings.end(), extensionWarnings.begin(), extensionWarnings.end());
  }
  void dropProjection()
  {
    result.projected = Mesh{};
    result.projectionStatus = "disabled";
    result.projectionMessage.clear();
    result.projectionSeconds = 0.;
    projected = false;
  }
  void dropExtension()
  {
    result.extended = Mesh{};
    result.extension = ExtensionReport{};
    result.extensionSeconds = 0.;
    extensionWarnings.clear();
    extended = false;
  }
};

Session::Session() : data_(new Data) {}
Session::~Session() = default;
bool Session::hasRaw() const { return data_->raw; }
bool Session::hasFiltered() const { return data_->filtered; }
bool Session::hasProjected() const { return data_->projected; }
bool Session::hasExtended() const { return data_->extended; }
const Result &Session::result() const { return data_->result; }

Result Session::take()
{
  Result result = std::move(data_->result);
  data_.reset(new Data);
  return result;
}

bool Session::raw(GModel *source, const Options &options, std::string &error)
{
  error.clear();
  data_.reset(new Data); // everything is computed again
  Data &d = *data_;
  Result &result = d.result;
  if(!source) { error = "No source GModel"; return false; }
  if(!validOptions(options)) { error = invalidOptions; return false; }
  try {
    ContextGuard guard(source);
    for(auto face = source->firstFace(); face != source->lastFace(); ++face) {
      if((*face)->triangles.empty() || !(*face)->quadrangles.empty())
        throw std::runtime_error("MAT needs a complete first-order triangular skin; face " +
                                 std::to_string((*face)->tag()) + " is unmeshed or contains quadrangles");
      for(const auto *triangle : (*face)->triangles)
        if(triangle->getNumVertices() != 3)
          throw std::runtime_error("MAT needs first-order triangles; face " +
                                   std::to_string((*face)->tag()) + " contains higher-order triangles");
      d.haveSurfaceParametrization = d.haveSurfaceParametrization && (*face)->haveParametrization();
    }
    std::vector<int> types;
    std::vector<std::vector<std::size_t>> elementTags, nodeTags;
    gmsh::model::mesh::getElements(types, elementTags, nodeTags, 3);
    if(!types.empty()) throw std::runtime_error("Use a surface-only input mesh, without volume nodes");
    d.tetRaw = options.raw == RawMode::Tet;
    // a filter that cannot follow is refused before the raw MAT is computed
    if(options.filter == FilterMode::Collapse && !d.tetRaw)
      throw std::runtime_error("The collapse filter needs the tetrahedron-based raw MAT (--raw tet, RawMode 1); for the legacy pipeline select the legacy filter as well (--filter legacy, FilterMode 0)");
    if(options.filter == FilterMode::Legacy && d.tetRaw)
      throw std::runtime_error("The legacy filter needs the legacy raw MAT (--raw legacy, RawMode 0)");
    auto start = Clock::now();
    d.mat.reset(new matGmsh);
    matGmsh &mat = *d.mat;
    if(d.tetRaw) {
      // General.NumThreads threads, every core if it is 0 (as for the mesh)
      double configured = 1.;
      gmsh::option::getNumber("General.NumThreads", configured);
      const unsigned threads = std::isfinite(configured) && configured >= 1. ?
        static_cast<unsigned>(std::min(configured, 256.)) :
        static_cast<unsigned>(std::max(1, std::min(Msg::GetMaxThreads(), 256)));
      mat.computeVoronoi(false, false);
      result.tet = MatNativeAccess::tetRaw(mat, threads, d.dual, d.skinSide);
      if(!result.tet.certified)
        d.rawWarnings.push_back("The certificate of the interior tetrahedra failed: the raw MAT may not have the topology of the solid. See \"tet\" in the report.");
      MatNativeAccess::select(mat, d.dual, nullptr);
      result.skin = MatNativeAccess::skin(mat);
      result.raw = MatNativeAccess::mesh(mat, &d.flatRaw);
    }
    else {
      mat.computeVoronoi();
      mat.computeVoronoiWindingNumbersAtCircumcenters();
      mat.colorVoronoiFaces(options.windingThreshold);
      result.skin = MatNativeAccess::skin(mat);
      result.raw = MatNativeAccess::mesh(mat);
    }
    result.rawSeconds = elapsed(start);
    d.vertices = MatNativeAccess::vertices(mat);
    d.stamp = skinStamp(source);
    d.raw = true;
    d.setWarnings();
    return true;
  }
  catch(const std::exception &e) { error = e.what(); }
  catch(const std::string &e) { error = e; }
  catch(...) { error = "Unknown error in native MAT pipeline"; }
  data_.reset(new Data);
  return false;
}

bool Session::filter(GModel *source, const Options &options, std::string &error)
{
  error.clear();
  if(!source) { error = "No source GModel"; return false; }
  if(!validOptions(options)) { error = invalidOptions; return false; }
  if(!data_->raw) { error = "The raw MAT has not been computed"; return false; }
  if(options.filter == FilterMode::Collapse && !data_->tetRaw) { error = "The collapse filter needs the tetrahedron-based raw MAT (--raw tet, RawMode 1); for the legacy pipeline select the legacy filter as well (--filter legacy, FilterMode 0)"; return false; }
  if(options.filter == FilterMode::Legacy && data_->tetRaw) { error = "The legacy filter needs the legacy raw MAT (--raw legacy, RawMode 0)"; return false; }
  if(data_->consumed) {
    Options again = options;
    again.raw = RawMode::Legacy;
    if(!raw(source, again, error)) return false;
  }
  Data &d = *data_;
  Result &result = d.result;
  result.filtered = Mesh{};
  result.filteredTopology = Topology{};
  result.collapse = matgmsh::tet::CollapseReport{};
  result.wingCandidate.clear();
  result.contactAngle.clear();
  result.filterSeconds = 0.;
  d.filterWarnings.clear();
  d.filtered = false;
  d.dropProjection();
  d.dropExtension();
  d.setWarnings();
  try {
    ContextGuard guard(source);
    if(skinStamp(source) != d.stamp) throw std::runtime_error(meshChanged);
    matGmsh &mat = *d.mat;
    if(d.moved) {
      MatNativeAccess::setVertices(mat, d.vertices);
      d.moved = false;
    }
    auto start = Clock::now();
    if(!d.patchesReady) {
      if(d.haveSurfaceParametrization) {
        d.patches = CadSurfacePatchAnalyzer().analyzeCurrentModel();
      }
      else {
        // A loaded surface mesh can preserve entity tags without carrying CAD
        // parametrizations. Keep those entities as distinct support patches;
        // inverse CAD evaluation cannot establish tangency between them.
        int patch = 0;
        for(auto face = source->firstFace(); face != source->lastFace(); ++face, ++patch) {
          const int tag = (*face)->tag();
          d.patches.patchByFaceTag[tag] = patch;
          d.patches.patchesByFaceTag[tag].insert(patch);
          d.patches.faceTagsByPatch.push_back({tag});
        }
      }
      d.patchesReady = true;
    }
    if(!d.haveSurfaceParametrization)
      d.filterWarnings.push_back("Surface parametrization is unavailable: each source face is a separate support patch; normal-based filtering may retain additional MAT material.");
    std::size_t flat = d.flatRaw;
    matgmsh::tet::Filtered kept;
    if(options.filter == FilterMode::Legacy) {
      d.consumed = true;
      MatNativeAccess::filter(mat, d.patches, options.legacyCleanup);
      result.filtered = MatNativeAccess::mesh(mat);
    }
    else if(options.filter == FilterMode::Collapse) {
      kept = MatNativeAccess::collapse(mat, source, d.patches, d.dual, d.skinSide, options.thickness,
                                       options.collapseThreshold, options.wingBranches,
                                       options.branchAngle);
      result.collapse = kept.report;
      result.wingCandidate = kept.wingCandidate;
      result.contactAngle = kept.contactAngle;
      if(!kept.report.materialSide)
        d.filterWarnings.push_back("The material side of the skin is not known on every shell: there, convex edges are not identified and no wing is removed as such; only the erosion thickness filters the MAT.");
      if(kept.report.wireEdges)
        d.filterWarnings.push_back(std::to_string(kept.report.wireEdges) + " edges of the collapsed MAT carry no surface: the retained surface alone does not have the topology of the solid.");
      MatNativeAccess::select(mat, d.dual, &kept.keep);
      d.reselected = true;
      result.filtered = MatNativeAccess::mesh(mat, &flat);
    }
    else {
      if(d.reselected) {
        MatNativeAccess::select(mat, d.dual, nullptr);
        d.reselected = false;
      }
      result.filtered = result.raw;
    }
    if(d.tetRaw && !options.complexDirectory.empty())
      MatNativeAccess::writeComplex(mat, d.patches, d.dual,
                                    options.filter == FilterMode::Collapse ? &kept : nullptr,
                                    options, result.tet.certified);
    if(flat)
      d.filterWarnings.push_back(std::to_string(flat) + " triangles of zero area were left out of the MAT meshes.");
    d.setWarnings();
    if(!validateMesh(result.filtered, error)) return false;
    result.filteredTopology = topology(result.filtered);
    result.filterSeconds = elapsed(start);
    if(options.legacyCleanup && options.filter == FilterMode::Legacy)
      d.filterWarnings.push_back("Legacy cleanup keeps the largest component and removes closed branch surfaces; use explicit keep-components policy to disable it.");
    d.vertices = MatNativeAccess::vertices(mat);
    d.filtered = true;
    d.setWarnings();
    return true;
  }
  catch(const std::exception &e) { error = e.what(); }
  catch(const std::string &e) { error = e; }
  catch(...) { error = "Unknown error in native MAT pipeline"; }
  return false;
}

bool Session::project(GModel *source, const Options &options, std::string &error)
{
  error.clear();
  Data &d = *data_;
  Result &result = d.result;
  if(!source) { error = "No source GModel"; return false; }
  if(!d.filtered) { error = "The filtered MAT has not been computed"; return false; }
  d.dropProjection();
  d.dropExtension();
  d.setWarnings();
  try {
    ContextGuard guard(source);
    auto start = Clock::now();
    result.projected = result.filtered;
    if(options.project && !d.haveSurfaceParametrization) {
      result.projectionStatus = "unchanged";
      result.projectionMessage = "Projection skipped because source surface parametrization is unavailable; the filtered MAT is retained exactly.";
    }
    else if(options.project) {
      if(skinStamp(source) != d.stamp) throw std::runtime_error(meshChanged);
      matGmsh &mat = *d.mat;
      if(d.moved) MatNativeAccess::setVertices(mat, d.vertices);
      d.moved = true; // a projection that is refused puts them back itself
      Mesh proposal;
      std::string why;
      if(MatNativeAccess::project(mat, d.patches, result.skin, proposal, why) &&
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
    d.projected = true;
    return true;
  }
  catch(const std::exception &e) { error = e.what(); }
  catch(const std::string &e) { error = e; }
  catch(...) { error = "Unknown error in native MAT pipeline"; }
  d.dropProjection();
  return false;
}

bool Session::extend(GModel *source, const Options &options, std::string &error)
{
  error.clear();
  Data &d = *data_;
  Result &result = d.result;
  if(!source) { error = "No source GModel"; return false; }
  if(!validOptions(options)) { error = invalidOptions; return false; }
  if(!d.filtered) { error = "The filtered MAT has not been computed"; return false; }
  d.dropExtension();
  if(!d.projected) {
    d.dropProjection();
    result.projected = result.filtered;
    d.projected = true;
  }
  try {
    ContextGuard guard(source);
    auto start = Clock::now();
    std::string why;
    if(!matgmsh_native::extend(result.projected, result.skin, options, result.extended, result.extension, why)) {
      result.extended = result.projected;
      result.extension.complete = false;
      result.extension.message = why;
      d.extensionWarnings.push_back("Extension failed; the prior MAT is retained: " + why);
    }
    result.extensionSeconds = elapsed(start);
    d.extended = true;
    d.setWarnings();
    return true;
  }
  catch(const std::exception &e) { error = e.what(); }
  catch(const std::string &e) { error = e; }
  catch(...) { error = "Unknown error in native MAT pipeline"; }
  d.dropExtension();
  d.setWarnings();
  return false;
}

bool compute(GModel *source, const Options &options, Result &result, std::string &error)
{
  Session session;
  bool ok = session.raw(source, options, error) && session.filter(source, options, error);
  if(ok && options.stopAfter != Stage::Filtered) ok = session.project(source, options, error);
  if(ok && options.stopAfter == Stage::Extended) ok = session.extend(source, options, error);
  result = session.take();
  return ok;
}
} // namespace matgmsh_native
