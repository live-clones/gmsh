#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <gmsh.h>
#define private public
#include "matGmsh.h"
#undef private

// Link the production filter directly, without the rest of the legacy pipeline.
matGmsh::ScopedTimer::ScopedTimer(const matGmsh &ownerIn,
                                const std::string &nameIn)
    : owner(ownerIn), name(nameIn), start(std::chrono::steady_clock::now())
{
}

matGmsh::ScopedTimer::~ScopedTimer()
{
  auto &entry = owner.timings[name];
  entry.total += std::chrono::duration_cast<std::chrono::nanoseconds>(
      std::chrono::steady_clock::now() - start);
  ++entry.calls;
}

namespace {
using Point = std::array<double, 3>;

void require(bool condition, const std::string &message)
{
  if(!condition) throw std::runtime_error(message);
}

Point add(Point a, const Point &b, double factor = 1.)
{
  for(int d = 0; d < 3; ++d) a[d] += factor * b[d];
  return a;
}

Point cross(const Point &a, const Point &b)
{
  return {a[1] * b[2] - a[2] * b[1],
          a[2] * b[0] - a[0] * b[2],
          a[0] * b[1] - a[1] * b[0]};
}

Point unit(Point point)
{
  double length = 0.;
  for(double x : point) length += x * x;
  length = std::sqrt(length);
  require(length > 0., "Fixture has a zero normal");
  for(double &x : point) x /= length;
  return point;
}

enum class Supports { Opposed, Weak, AlternativeOpposed };

struct Fixture {
  matGmsh mesh;
  std::vector<int> rawColors;
  std::size_t candidate = 0;
  double scale;

  explicit Fixture(double scaleIn = 1.) : scale(scaleIn)
  {
    gmsh::clear();
    gmsh::model::add("Terminal branch filter regression");
  }

  int vertex(const Point &point)
  {
    const int tag = static_cast<int>(mesh.vor.vertices.size() / 3);
    for(double x : point) mesh.vor.vertices.push_back(scale * x);
    return tag;
  }

  Point point(int vertex) const
  {
    return {mesh.vor.vertices[3 * vertex],
            mesh.vor.vertices[3 * vertex + 1],
            mesh.vor.vertices[3 * vertex + 2]};
  }

  // Each seed lives on a real OCC curve shared by its supporting planes.
  // This makes every alternative normal available through native pcurves.
  // getParametrization here only prepares the source mesh fixture; production
  // receives the resulting stored curve parameter through getNode.
  int seed(const Point &position, const std::vector<Point> &normals)
  {
    const int seedIndex = static_cast<int>(mesh.del.seeds.size() / 3);
    mesh.del.seeds.insert(mesh.del.seeds.end(), position.begin(), position.end());
    // A curve must lie in every supporting plane. Use their intersection
    // for alternatives, or any tangent perpendicular to a single normal.
    const Point axis = std::abs(normals.front()[1]) < .9 ? Point{0.,1.,0.} : Point{1.,0.,0.};
    const Point tangent = normals.size() > 1 ?
        unit(cross(normals[0], normals[1])) : unit(cross(normals.front(), axis));
    const Point first = add(position, tangent, -2. * scale);
    const Point last = add(position, tangent, 2. * scale);
    const int firstTag = gmsh::model::occ::addPoint(first[0], first[1], first[2]);
    const int lastTag = gmsh::model::occ::addPoint(last[0], last[1], last[2]);
    const int curve = gmsh::model::occ::addLine(firstTag, lastTag);
    std::vector<int> surfaces;
    for(const Point &normal : normals) {
      const Point across = unit(cross(normal, tangent));
      const Point third = add(last, across, 4. * scale);
      const Point fourth = add(first, across, 4. * scale);
      const int thirdTag = gmsh::model::occ::addPoint(third[0], third[1], third[2]);
      const int fourthTag = gmsh::model::occ::addPoint(fourth[0], fourth[1], fourth[2]);
      const int secondEdge = gmsh::model::occ::addLine(lastTag, thirdTag);
      const int thirdEdge = gmsh::model::occ::addLine(thirdTag, fourthTag);
      const int fourthEdge = gmsh::model::occ::addLine(fourthTag, firstTag);
      const int loop = gmsh::model::occ::addCurveLoop({curve, secondEdge, thirdEdge, fourthEdge});
      surfaces.push_back(gmsh::model::occ::addPlaneSurface({loop}));
    }
    gmsh::model::occ::synchronize();
    const std::size_t node = 1001 + static_cast<std::size_t>(seedIndex);
    const std::vector<double> xyz(position.begin(), position.end());
    std::vector<double> parameter;
    gmsh::model::getParametrization(1, curve, xyz, parameter);
    require(parameter.size() == 1, "Source seed lacks its curve parameter");
    gmsh::model::mesh::addNodes(1, curve, {node}, xyz, parameter);
    mesh.del.nodeTags.push_back(node);
    mesh.del.onWhat.emplace_back(1, curve);
    mesh.del.seedFaces.push_back(surfaces);

    // Verify the native fixture itself supplies every intended normal.
    for(std::size_t i = 0; i < surfaces.size(); ++i) {
      std::vector<double> uv, value;
      gmsh::model::reparametrizeOnSurface(1, curve, parameter, surfaces[i], uv, 1);
      gmsh::model::getNormal(surfaces[i], uv, value);
      require(value.size() == 3, "Fixture support normal is unavailable");
      double dot = 0.;
      for(int d = 0; d < 3; ++d) dot += value[d] * normals[i][d];
      require(dot > .999999, "Fixture OCC support orientation is wrong");
    }
    return seedIndex;
  }

  std::size_t face(std::vector<int> vertices, int branch,
                   Supports supports = Supports::Opposed,
                   bool acuteOpening = false, bool selected = true,
                   double acuteOffset = 1.5)
  {
    Point center{};
    for(int vertex : vertices)
      center = add(center, point(vertex), 1. / vertices.size());
    const Point first = point(vertices[0]);
    const Point normal = unit(cross(add(point(vertices[1]), first, -1.),
                                   add(point(vertices[2]), first, -1.)));
    Point supportNormal = normal;
    if(supports != Supports::Opposed) {
      const Point tangent = unit(add(point(vertices[1]), first, -1.));
      for(int d = 0; d < 3; ++d)
        supportNormal[d] = .45 * normal[d] + std::sqrt(1. - .45 * .45) * tangent[d];
    }
    Point midpoint = center;
    if(acuteOpening) {
      const Point inPlane = unit(cross(normal,
          unit(add(point(vertices[1]), first, -1.))));
      // Move the seed midpoint within the polygon plane independently of
      // the CAD support normals, including asymmetric terminal fixtures.
      midpoint = add(midpoint, inPlane, acuteOffset * scale);
    }
    std::vector<int> seeds;
    for(int sign : {-1, 1}) {
      const Point location = add(midpoint, normal, sign * .5 * scale);
      std::vector<Point> normals{add(Point{}, supportNormal, sign)};
      if(supports == Supports::AlternativeOpposed)
        normals.push_back(add(Point{}, normal, sign));
      seeds.push_back(seed(location, normals));
    }
    const std::size_t index = mesh.vor.faces.size();
    mesh.vor.faces.emplace_back(matGmshEdge(seeds[0], seeds[1]), vertices);
    rawColors.push_back(branch);
    mesh.vor.faceColors.push_back(selected ? branch : -1);
    return index;
  }

  void terminal(Supports supports, bool acuteOpening = true,
                double acuteOffset = 1.5)
  {
    vertex({-.25,0.,0.}); // 0: base endpoint
    vertex({ .25,0.,0.}); // 1: base endpoint
    vertex({0., .8,0.});  // 2: free tip
    vertex({0.,0.,-2.});  // 3: first host
    vertex({0.,0., 2.});  // 4: second host
    face({1,0,3}, 10);
    face({0,1,4}, 20);
    candidate = face({0,1,2}, 30, supports, acuteOpening, true, acuteOffset);
  }
};

struct Snapshot {
  decltype(matGmsh::vor) vor;
  decltype(matGmsh::del) del;
  std::vector<int> rawColors;

  explicit Snapshot(const Fixture &fixture)
      : vor(fixture.mesh.vor), del(fixture.mesh.del), rawColors(fixture.rawColors) {}

  void requireOriginalGeometry(const Fixture &fixture) const
  {
    const auto &mesh = fixture.mesh;
    require(vor.vertices == mesh.vor.vertices &&
            del.seeds == mesh.del.seeds && del.nodeTags == mesh.del.nodeTags &&
            del.onWhat == mesh.del.onWhat && del.seedFaces == mesh.del.seedFaces &&
            rawColors == fixture.rawColors,
            "Terminal filtering changed original geometry or CAD supports");
    require(vor.faces.size() == mesh.vor.faces.size(),
            "Terminal filtering changed the polygon array");
    for(std::size_t i = 0; i < vor.faces.size(); ++i)
      require(vor.faces[i].verts == mesh.vor.faces[i].verts &&
              vor.faces[i].edge.a == mesh.vor.faces[i].edge.a &&
              vor.faces[i].edge.b == mesh.vor.faces[i].edge.b,
              "Terminal filtering changed polygon connectivity or generating seeds");
  }
};

void checkPreserved(Fixture &fixture, const std::string &reason)
{
  const Snapshot before(fixture);
  std::ostringstream report;
  fixture.mesh.reportSmallTerminalBranches(fixture.rawColors, report);
  require(fixture.mesh.vor.faceColors == before.vor.faceColors,
          "Read-only terminal diagnostic changed the selection");
  const auto removed = fixture.mesh.filterSmallTerminalBranches(fixture.rawColors, &report);
  require(removed == 0 && fixture.mesh.vor.faceColors == before.vor.faceColors,
          reason + "\n" + report.str());
  before.requireOriginalGeometry(fixture);
}

void checkOpposedAndAlternativeSupports()
{
  {
    Fixture fixture(.01);
    fixture.terminal(Supports::Opposed);
    checkPreserved(fixture, "A genuinely supported tiny terminal T was removed");
  }
  {
    Fixture fixture;
    fixture.terminal(Supports::AlternativeOpposed);
    checkPreserved(fixture, "An available opposed CAD alternative was ignored");
  }
  {
    Fixture fixture;
    fixture.terminal(Supports::Weak, false);
    checkPreserved(fixture, "Weak normal agreement alone removed a wide-opening sheet");
  }
  {
    Fixture fixture;
    fixture.terminal(Supports::Opposed, true, 1.);
    checkPreserved(fixture, "A genuine opposed CAD support pair was discarded on an asymmetric terminal triangle");
  }
}

void checkUnknownSupports()
{
  {
    Fixture fixture;
    fixture.terminal(Supports::Weak);
    fixture.mesh.del.nodeTags.clear();
    checkPreserved(fixture, "Missing source-node metadata authorized deletion");
  }
  {
    Fixture fixture;
    fixture.terminal(Supports::Weak);
    const int seed = fixture.mesh.vor.faces[fixture.candidate].edge.a;
    fixture.mesh.del.seedFaces[seed].push_back(999999);
    checkPreserved(fixture, "An unavailable CAD alternative was treated as weak support");
  }
  {
    Fixture fixture;
    fixture.terminal(Supports::Weak);
    const int seed = fixture.mesh.vor.faces[fixture.candidate].edge.a;
    fixture.mesh.del.seeds[3 * seed] += .01;
    checkPreserved(fixture, "Stale source-node parameters authorized deletion");
  }
  {
    Fixture fixture;
    fixture.terminal(Supports::Weak);
    const int hostSeed = fixture.mesh.vor.faces.front().edge.a;
    fixture.mesh.del.nodeTags[hostSeed] = 9999999;
    checkPreserved(fixture, "An unknown host support authorized deletion of its terminal neighbor");
  }
  {
    Fixture fixture;
    fixture.terminal(Supports::Weak);
    const auto seeds = fixture.mesh.vor.faces[fixture.candidate].edge;
    fixture.mesh.del.seedFaces[seeds.b] = fixture.mesh.del.seedFaces[seeds.a];
    checkPreserved(fixture, "A generating pair on the same CAD surface authorized deletion");
  }
}

void checkTopologyProtections()
{
  {
    Fixture fixture;
    fixture.terminal(Supports::Weak);
    const int a = fixture.vertex({1.,.8,0.});
    const int b = fixture.vertex({0.,.8,1.});
    fixture.face({2,a,b}, 40);
    checkPreserved(fixture, "A secondary retained contact at the tip was ignored");
  }
  {
    Fixture fixture;
    fixture.vertex({-.25,0.,0.});
    fixture.vertex({.25,0.,0.});
    fixture.vertex({0.,.8,0.});
    fixture.vertex({0.,-1.,0.});
    fixture.vertex({1.,1.,0.});
    fixture.vertex({-1.,1.,0.});
    fixture.face({1,0,3}, 10);
    fixture.face({2,1,4}, 20);
    fixture.face({0,2,5}, 40);
    fixture.candidate = fixture.face({0,1,2}, 30, Supports::Weak, true);
    checkPreserved(fixture, "An original sewn triangular closure cap was removed");
  }
  {
    Fixture fixture;
    fixture.terminal(Supports::Opposed);
    const int a = fixture.vertex({1.,1.,0.});
    fixture.face({2,1,a}, 40, Supports::Opposed, false, false);
    checkPreserved(fixture, "A supported connector was removed after prior filtering exposed its boundary");
  }
}

void checkCertifiedWeakSpur()
{
  Fixture fixture;
  fixture.terminal(Supports::Weak);
  // Real spur boundaries are exposed by prior classification. The rejected
  // raw collar must stay rejected while the weak terminal candidate is removed.
  const int collar = fixture.vertex({1.,1.,0.});
  fixture.face({2,1,collar}, 40, Supports::Opposed, false, false);
  const Snapshot before(fixture);
  std::ostringstream report;
  require(fixture.mesh.filterSmallTerminalBranches(fixture.rawColors, &report) == 1,
          "The acute, weakly supported terminal spur survived\n" + report.str());
  for(std::size_t face = 0; face < before.vor.faceColors.size(); ++face)
    require(fixture.mesh.vor.faceColors[face] ==
                (face == fixture.candidate ? -1 : before.vor.faceColors[face]),
            "Terminal filtering changed a host or removed the wrong polygon");
  before.requireOriginalGeometry(fixture);
  const auto once = fixture.mesh.vor.faceColors;
  require(fixture.mesh.filterSmallTerminalBranches(fixture.rawColors, &report) == 0 &&
          fixture.mesh.vor.faceColors == once,
          "Terminal filtering changed its result on a second pass");
}

void checkTwoPolygonSpur()
{
  Fixture fixture;
  fixture.terminal(Supports::Weak);
  const int outer = fixture.vertex({-.6,.6,0.});
  const std::size_t second = fixture.face({0,2,outer}, 30, Supports::Weak, true);
  const Snapshot before(fixture);
  std::ostringstream report;
  require(fixture.mesh.filterSmallTerminalBranches(fixture.rawColors, &report) == 2,
          "The weak two-polygon terminal disk was not removed as a whole\n" + report.str());
  for(std::size_t face = 0; face < before.vor.faceColors.size(); ++face)
    require(fixture.mesh.vor.faceColors[face] ==
                (face == fixture.candidate || face == second ? -1 : before.vor.faceColors[face]),
            "The two-polygon certificate changed a host or left a partial disk");
  before.requireOriginalGeometry(fixture);
  const auto once = fixture.mesh.vor.faceColors;
  require(fixture.mesh.filterSmallTerminalBranches(fixture.rawColors, &report) == 0 &&
          fixture.mesh.vor.faceColors == once,
          "The two-polygon removal was not idempotent");
}

void checkSecondaryEdgeAttachment(bool hostsAlreadyConnected)
{
  Fixture fixture;
  fixture.vertex({-.25,0.,0.}); // 0,1: base shared by two hosts
  fixture.vertex({ .25,0.,0.});
  fixture.vertex({ .25,.8,0.}); // 2,3: a separate edge attachment
  fixture.vertex({-.25,.8,0.});
  fixture.vertex({0.,0.,-2.});  // 4: first base host
  fixture.vertex({0.,0., 2.});  // 5: second base host
  fixture.vertex({0.,.8,2.});   // 6: the secondary host
  fixture.face({1,0,4}, 10);
  fixture.face({0,1,5}, 20);
  fixture.face({3,2,6}, 40);
  fixture.candidate = fixture.face({0,1,2,3}, 30, Supports::Weak, true);

  if(hostsAlreadyConnected) {
    // This path leaves the candidate plane and joins existing host edges
    // 1--5 and 2--6. It neither shares the candidate's free edges 1--2/3--0
    // nor relies on any candidate polygon to connect the two attachments.
    const int outsideA = fixture.vertex({2.,-1.,1.});
    const int outsideB = fixture.vertex({2., 2.,1.});
    fixture.face({1,5,outsideA}, 50);
    fixture.face({5,outsideA,outsideB}, 60);
    fixture.face({outsideA,outsideB,6}, 70);
    fixture.face({outsideB,6,2}, 80);
  }

  if(!hostsAlreadyConnected) {
    checkPreserved(fixture,
        "A weak disk providing the only connection between its host sheets was removed");
    return;
  }

  const Snapshot before(fixture);
  std::ostringstream report;
  require(fixture.mesh.filterSmallTerminalBranches(fixture.rawColors, &report) == 1,
          "The secondary edge attachment hid a redundant weak spur\n" + report.str());
  for(std::size_t face = 0; face < before.vor.faceColors.size(); ++face)
    require(fixture.mesh.vor.faceColors[face] ==
                (face == fixture.candidate ? -1 : before.vor.faceColors[face]),
            "Secondary-attachment filtering changed a host or its alternate path");
  before.requireOriginalGeometry(fixture);
  const auto once = fixture.mesh.vor.faceColors;
  require(fixture.mesh.filterSmallTerminalBranches(fixture.rawColors, &report) == 0 &&
          fixture.mesh.vor.faceColors == once,
          "Secondary-attachment filtering was not idempotent");
}
} // namespace

int main()
{
  bool initialized = false;
  try {
    gmsh::initialize();
    initialized = true;
    gmsh::option::setNumber("General.Terminal", 0);
    checkOpposedAndAlternativeSupports();
    checkUnknownSupports();
    checkTopologyProtections();
    checkCertifiedWeakSpur();
    checkTwoPolygonSpur();
    checkSecondaryEdgeAttachment(true);
    checkSecondaryEdgeAttachment(false);
    gmsh::finalize();
    std::cout << "Terminal branch filtering: PASS\n";
    return 0;
  }
  catch(const std::exception &error) {
    if(initialized) gmsh::finalize();
    std::cerr << error.what() << '\n';
    return 1;
  }
}
