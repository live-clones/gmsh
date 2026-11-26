#include "MatPipeline.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <map>
#include <numeric>
#include <set>
#include <sstream>

namespace matgmsh_native {
namespace {
using Edge = std::pair<int, int>;
Edge edge(int a, int b) { return std::minmax(a, b); }
std::string quote(const std::string &s)
{
  std::ostringstream out; out << '"';
  for(unsigned char c : s) {
    if(c == '"' || c == '\\') out << '\\' << c;
    else if(c == '\n') out << "\\n";
    else if(c == '\r') out << "\\r";
    else if(c == '\t') out << "\\t";
    else if(c < 32) out << "\\u" << std::hex << std::setw(4) << std::setfill('0') << int(c) << std::dec;
    else out << c;
  }
  return out.str() + '"';
}
void writeSurface(std::ostream &out, const matgmsh::tet::Surface &s)
{
  out << "{\"vertices\":" << s.vertices << ",\"edges\":" << s.edges << ",\"faces\":" << s.faces
      << ",\"components\":" << s.components << ",\"euler\":" << s.euler
      << ",\"closed_manifold\":" << (s.closedManifold ? "true" : "false")
      << ",\"oriented\":" << (s.oriented ? "true" : "false")
      << ",\"bad_edges\":" << s.badEdges << ",\"bad_vertices\":" << s.badVertices
      << ",\"bad_orientations\":" << s.badOrientations
      << ",\"missing_sites\":" << s.missingSites << '}';
}
void writeComplex(std::ostream &out, const matgmsh::tet::ComplexTopology &t)
{
  out << "{\"vertices\":" << t.vertices << ",\"edges\":" << t.edges << ",\"faces\":" << t.faces
      << ",\"components\":" << t.components << ",\"free_edges\":" << t.freeEdges
      << ",\"junction_edges\":" << t.junctionEdges << ",\"euler\":" << t.euler << '}';
}
void writeTopology(std::ostream &out, const Topology &t)
{
  out << "{\"vertices\":" << t.vertices << ",\"triangles\":" << t.triangles
      << ",\"components\":" << t.components << ",\"free_edges\":" << t.freeEdges
      << ",\"junction_edges\":" << t.junctionEdges << ",\"euler\":" << t.euler << '}';
}
}

bool validateMesh(const Mesh &m, std::string &error)
{
  error.clear();
  if(m.xyz.empty() || m.triangles.empty() || m.xyz.size()%3 || m.triangles.size()%3 ||
     m.branch.size() != m.triangles.size()/3 || m.parent.size() != m.branch.size()) {
    error = "Empty or inconsistent MAT mesh arrays"; return false;
  }
  for(double x : m.xyz) if(!std::isfinite(x)) { error = "Nonfinite mesh coordinate"; return false; }
  for(std::size_t f = 0; f < m.branch.size(); ++f) {
    int v[3];
    for(int k = 0; k < 3; ++k) {
      v[k] = m.triangles[3*f+k];
      if(v[k] < 0 || std::size_t(v[k]) >= m.xyz.size()/3) {
        error = "Triangle references an unknown vertex"; return false;
      }
    }
    const double *a = &m.xyz[3*v[0]], *b = &m.xyz[3*v[1]], *c = &m.xyz[3*v[2]];
    double u[3], w[3], n[3];
    for(int k = 0; k < 3; ++k) { u[k] = b[k]-a[k]; w[k] = c[k]-a[k]; }
    for(int k = 0; k < 3; ++k) n[k] = u[(k+1)%3]*w[(k+2)%3]-u[(k+2)%3]*w[(k+1)%3];
    const double n2 = n[0]*n[0]+n[1]*n[1]+n[2]*n[2];
    if(!std::isfinite(n2) || n2 == 0.) {
      error = "Degenerate triangle " + std::to_string(f); return false;
    }
  }
  return true;
}

Topology topology(const Mesh &m)
{
  Topology r; r.triangles = m.triangles.size()/3;
  std::map<Edge, int> uses;
  std::vector<int> parent(m.xyz.size()/3);
  std::iota(parent.begin(), parent.end(), 0);
  auto find = [&](int v) { while(parent[v] != v) { parent[v] = parent[parent[v]]; v = parent[v]; } return v; };
  std::set<int> used;
  for(std::size_t f = 0; f < r.triangles; ++f) {
    for(int k = 0; k < 3; ++k) {
      const int a = m.triangles[3*f+k], b = m.triangles[3*f+(k+1)%3];
      ++uses[edge(a,b)]; used.insert(a);
      parent[find(b)] = find(a);
    }
  }
  std::set<int> components;
  for(int v : used) components.insert(find(v));
  for(const auto &e : uses) { r.freeEdges += e.second == 1; r.junctionEdges += e.second > 2; }
  r.vertices = used.size(); r.components = components.size();
  r.euler = static_cast<long long>(r.vertices) - static_cast<long long>(uses.size()) +
            static_cast<long long>(r.triangles);
  return r;
}

bool writeMesh(const Mesh &m, const std::string &filename, std::string &error)
{
  if(!validateMesh(m, error)) return false;
  std::ofstream f(filename);
  if(!f) { error = "Cannot open " + filename; return false; }
  f << std::setprecision(17) << "$MeshFormat\n2.2 0 8\n$EndMeshFormat\n$Nodes\n" << m.xyz.size()/3 << '\n';
  for(std::size_t v = 0; v < m.xyz.size()/3; ++v)
    f << v+1 << ' ' << m.xyz[3*v] << ' ' << m.xyz[3*v+1] << ' ' << m.xyz[3*v+2] << '\n';
  f << "$EndNodes\n$Elements\n" << m.triangles.size()/3 << '\n';
  for(std::size_t t = 0; t < m.triangles.size()/3; ++t)
    f << t+1 << " 2 2 " << m.branch[t]+1 << ' ' << m.branch[t]+1 << ' '
      << m.triangles[3*t]+1 << ' ' << m.triangles[3*t+1]+1 << ' ' << m.triangles[3*t+2]+1 << '\n';
  f << "$EndElements\n$ElementData\n1\n\"MAT parent\"\n1\n0\n3\n0\n1\n" << m.parent.size() << '\n';
  for(std::size_t t = 0; t < m.parent.size(); ++t) f << t+1 << ' ' << m.parent[t] << '\n';
  f << "$EndElementData\n";
  if(!f) { error = "Failed to write " + filename; return false; }
  return true;
}

bool writeReport(const Result &r, const Options &o, const std::string &filename,
                 std::string &error)
{
  std::ofstream f(filename);
  if(!f) { error = "Cannot open " + filename; return false; }
  f << std::setprecision(17) << "{\n\"scope\":\"Native extraction of the filtered MAT pipeline; no independent reference geometry is used\",\n"
    << "\"thickness\":" << o.thickness << ",\n\"legacy_cleanup\":" << (o.legacyCleanup ? "true" : "false")
    << ",\n\"raw_seconds\":" << r.rawSeconds << ",\n\"filter_seconds\":" << r.filterSeconds
    << ",\n\"projection_seconds\":" << r.projectionSeconds << ",\n\"extension_seconds\":" << r.extensionSeconds
    << ",\n\"projection_status\":" << quote(r.projectionStatus)
    << ",\n\"projection_message\":" << quote(r.projectionMessage) << ",\n\"stages\":{";
  bool first = true;
  for(const auto &item : std::vector<std::pair<std::string, const Mesh *>>{
      {"raw",&r.raw},{"filtered",&r.filtered},{"projected",&r.projected},{"extended",&r.extended}}) {
    if(item.second->triangles.empty()) continue;
    if(!first) f << ','; first = false;
    f << quote(item.first) << ':'; writeTopology(f, topology(*item.second));
  }
  f << "},\n\"raw_mode\":" << (o.raw == RawMode::Tet ? "\"tet\"" : "\"legacy\"")
    << ",\n\"filter_mode\":" << (o.filter == FilterMode::Collapse ? "\"collapse\"" :
                                  o.filter == FilterMode::None ? "\"none\"" : "\"legacy\"");
  if(r.tet.computed) {
    const auto &t = r.tet;
    f << ",\n\"tet\":{\"certified\":" << (t.certified ? "true" : "false")
      << ",\"sites\":" << t.sites << ",\"tetrahedra\":" << t.tetrahedra
      << ",\"interior\":" << t.interior << ",\"zero_volume\":" << t.zeroVolume
      << ",\"exact_contact\":" << t.exactContact
      << ",\"numerical_contact\":" << t.numericalContact << ",\"unresolved\":" << t.unresolved
      << ",\"polygons\":" << t.polygons << ",\"hull_edges\":" << t.hullEdges
      << ",\"invalid_links\":" << t.invalidLinks
      << ",\"boundary_faces_over_valence_two\":" << t.boundaryFacesOverValenceTwo
      << ",\n\"skin\":";
    writeSurface(f, t.skin);
    f << ",\n\"boundary\":";
    writeSurface(f, t.boundary);
    f << ",\n\"dual\":";
    writeComplex(f, t.dual);
    f << '}';
  }
  if(r.collapse.computed) {
    const auto &c = r.collapse;
    f << ",\n\"collapse\":{\"threshold\":" << c.threshold << ",\"thickness\":" << c.thickness
      << ",\"material_side_known\":" << (c.materialSide ? "true" : "false")
      << ",\"curve_segments\":" << c.curveSegments << ",\"convex_segments\":" << c.convexSegments
      << ",\"zero_area_polygons\":" << c.zeroAreaPolygons
      << ",\"unreached_polygons\":" << c.unreachedPolygons
      << ",\"convex_polygons\":" << c.convexPolygons
      << ",\"wing_components\":" << c.wingComponents
      << ",\"anchored_wing_components\":" << c.anchoredWingComponents
      << ",\"wing_polygons\":" << c.wingPolygons << ",\"eligible\":" << c.eligible
      << ",\"removed\":" << c.removed << ",\"blocked\":" << c.blocked
      << ",\"wings_blocked\":" << c.wingsBlocked << ",\"wire_edges\":" << c.wireEdges
      << ",\"branches\":" << c.branches << ",\"wing_branches\":" << c.wingBranches
      << ",\"branch_wing_polygons\":" << c.branchWingPolygons
      << ",\n\"surface\":";
    writeComplex(f, c.surface);
    f << '}';
  }
  f << ",\n\"extension\":{\"complete\":" << (r.extension.complete ? "true" : "false")
    << ",\"message\":" << quote(r.extension.message)
    << ",\"added_triangles\":" << r.extension.addedTriangles << ",\"fronts\":[";
  first = true;
  for(const auto &x : r.extension.fronts) {
    if(!first) f << ','; first = false;
    f << "{\"a\":" << x.a << ",\"b\":" << x.b << ",\"branch\":" << x.branch
      << ",\"status\":" << quote(x.status) << ",\"reason\":" << quote(x.reason) << '}';
  }
  f << "]},\n\"warnings\":["; first = true;
  for(const auto &x : r.warnings) { if(!first) f << ','; first = false; f << quote(x); }
  f << "]\n}\n";
  if(!f) { error = "Failed to write " + filename; return false; }
  return true;
}
} // namespace matgmsh_native
