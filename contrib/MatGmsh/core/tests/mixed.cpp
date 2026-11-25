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

// This target links the complete mixed-zone filter without the unrelated
// legacy pipeline. Supply its stage timer locally; all geometry, gradient
// recovery, segmentation and peeling run through production code.
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
enum class Contact {
  InteriorSharedEdge, SharedVertex, RejectedSheet, TerminalSharedEdge,
  SteepInteriorSharedEdge, MixedInteriorSharedEdge
};

void require(bool condition, const std::string &message)
{
  if(!condition) throw std::runtime_error(message);
}

struct Fixture {
  matGmsh mesh;
  std::vector<int> rawColors;
  std::map<Point, int> nodeByPoint;
  std::vector<std::size_t> junctionZone, transitionZone, terminalZone, fixedSheet;
  double radiusGradient;

  int node(const Point &position)
  {
    const auto found = nodeByPoint.find(position);
    if(found != nodeByPoint.end()) return found->second;
    const int tag = static_cast<int>(nodeByPoint.size());
    nodeByPoint[position] = tag;
    mesh.vor.vertices.insert(mesh.vor.vertices.end(),
                             position.begin(), position.end());
    return tag;
  }

  void cell(const std::array<Point, 4> &points, int branch,
            int selectedColor, int supportPair,
            std::vector<std::size_t> *group = nullptr)
  {
    std::vector<int> vertices;
    Point center{};
    for(const Point &position : points) {
      vertices.push_back(node(position));
      for(int coordinate = 0; coordinate < 3; ++coordinate)
        center[coordinate] += position[coordinate] / points.size();
    }
    const int firstSeed = static_cast<int>(mesh.del.seeds.size() / 3);
    const double radius = 0.6 + radiusGradient * center[0];
    for(int sign : {-1, 1}) {
      mesh.del.seeds.insert(mesh.del.seeds.end(),
          {center[0], center[1], sign * radius});
      mesh.del.seedFaces.push_back(
          {2 * supportPair + (sign == 1 ? 2 : 1)});
    }
    if(group) group->push_back(mesh.vor.faces.size());
    mesh.vor.faces.emplace_back(matGmshEdge(firstSeed, firstSeed + 1), vertices);
    mesh.vor.faceColors.push_back(selectedColor);
    rawColors.push_back(branch);
  }

  Fixture(Contact contact, double gradient) : radiusGradient(gradient)
  {
    // The support patches share a smooth affine radius field. The full
    // gradient fit recovers the prescribed gradient, coherence = 1 and no
    // plateau. A slope of 0.28 lies above the local support-core limit 0.25
    // and below the interface limit 0.30; slope 0.4 is a removable wing.
    for(int x = 0; x < 4; ++x) {
      for(int y = 0; y < 3; ++y) {
        const double a = x, b = y;
        cell({Point{a,b,0}, Point{a+1,b,0},
              Point{a+1,b+1,0}, Point{a,b+1,0}},
             0, 0, x < 2 ? 0 : 1,
             x == 0 ? &junctionZone : x == 1 ? &transitionZone : &terminalZone);
      }
    }

    // A closed raw box gives the retained top sheet no raw free edges, so
    // this different branch is outside mixed-zone segmentation. Its other
    // faces are already rejected. Moving the box changes the shared edge to
    // a shared vertex without introducing any duplicate node coordinates.
    const int firstY = contact == Contact::SharedVertex ? -3 : 0;
    const int selected = contact == Contact::RejectedSheet ? -1 : 1;
    for(int y = firstY; y < firstY + 3; ++y) {
      const double b = y;
      cell({Point{-1,b,0}, Point{0,b,0},
            Point{0,b+1,0}, Point{-1,b+1,0}}, 1, selected, 0, &fixedSheet);
      cell({Point{-1,b,-1}, Point{0,b,-1},
            Point{0,b+1,-1}, Point{-1,b+1,-1}}, 2, -1, 0);
      for(int x : {-1, 0}) {
        const double a = x;
        cell({Point{a,b,0}, Point{a,b+1,0},
              Point{a,b+1,-1}, Point{a,b,-1}}, 2, -1, 0);
      }
    }
    for(int y : {firstY, firstY + 3}) {
      const double b = y;
      cell({Point{-1,b,0}, Point{0,b,0},
            Point{0,b,-1}, Point{-1,b,-1}}, 2, -1, 0);
    }

    // A genuine junction has no boundary in the raw complex. Rejected raw
    // neighbors cover the other exposed edges of its zone; after initial
    // selection those edges are free, which must not be confused with an
    // original terminal rim. Leave this collar absent in the terminal case.
    if(contact != Contact::TerminalSharedEdge) {
      for(int x = 0; x < 2; ++x) {
        for(int y : {0, 3}) {
          const double a = x, b = y;
          cell({Point{a,b,0}, Point{a+1,b,0},
                Point{a+1,b,-1}, Point{a,b,-1}}, 2, -1, 0);
        }
      }
      if(contact == Contact::SharedVertex) {
        for(int y = 0; y < 3; ++y) {
          const double b = y;
          cell({Point{0,b,0}, Point{0,b+1,0},
                Point{0,b+1,-1}, Point{0,b,-1}}, 2, -1, 0);
        }
      }
    }
  }
};

void makeCadSupports(double gradient)
{
  // Adjacent CAD patches separate the zones while their supporting planes
  // retain the same exact affine radius on both sides of x = 2.
  for(int pair = 0; pair < 2; ++pair) {
    const double xmin = pair == 0 ? -1.0 : 2.0;
    const double xmax = pair == 0 ? 2.0 : 6.0;
    for(int sign : {-1, 1}) {
      std::vector<int> points, lines;
      for(const auto &xy : std::array<std::array<double, 2>, 4>{
               {{xmin,-4}, {xmax,-4}, {xmax,4}, {xmin,4}}}) {
        points.push_back(gmsh::model::occ::addPoint(
            xy[0], xy[1], sign * (0.6 + gradient * xy[0])));
      }
      for(int i = 0; i < 4; ++i)
        lines.push_back(gmsh::model::occ::addLine(points[i], points[(i+1)%4]));
      const int loop = gmsh::model::occ::addCurveLoop(lines);
      gmsh::model::occ::addPlaneSurface({loop}, 2 * pair + (sign == 1 ? 2 : 1));
    }
  }
  gmsh::model::occ::synchronize();
}

void check(Contact contact)
{
  const double gradient = contact == Contact::SteepInteriorSharedEdge ? 0.4 : 0.28;
  gmsh::clear();
  gmsh::model::add("Mixed branch interface regression");
  makeCadSupports(gradient);
  Fixture fixture(contact, gradient);
  auto &mesh = fixture.mesh;
  if(contact == Contact::MixedInteriorSharedEdge) {
    // Expose the outer rim of the neighboring sheet so that it, too, enters
    // mixed-zone analysis. The common junction geometry is unchanged.
    for(std::size_t face = 0; face < fixture.rawColors.size(); ++face) {
      if(fixture.rawColors[face] != 2) continue;
      const auto &vertices = mesh.vor.faces[face].verts;
      if(std::all_of(vertices.begin(), vertices.end(), [&](int v) {
           return mesh.vor.vertices[3 * v] == -1.0;
         }))
        fixture.rawColors[face] = -1;
    }
  }
  const auto originalCoordinates = mesh.vor.vertices;
  const auto originalSeeds = mesh.del.seeds;
  const auto originalFaces = mesh.vor.faces;
  const auto originalColors = mesh.vor.faceColors;
  std::map<std::pair<int, int>, int> rawIncidence;
  for(const auto &face : originalFaces)
    for(std::size_t i = 0; i < face.verts.size(); ++i)
      ++rawIncidence[std::minmax(face.verts[i],
                                face.verts[(i+1)%face.verts.size()])];
  std::size_t rawFreeEdges = 0;
  for(std::size_t face : fixture.junctionZone) {
    const auto &vertices = originalFaces[face].verts;
    for(std::size_t i = 0; i < vertices.size(); ++i)
      rawFreeEdges += rawIncidence.at(
          std::minmax(vertices[i], vertices[(i+1)%vertices.size()])) == 1;
  }
  require((rawFreeEdges != 0) == (contact == Contact::TerminalSharedEdge),
          "Fixture did not distinguish a raw terminal rim from a selected boundary");
  std::ostringstream report;
  std::vector<int> zoneByFace;
  std::vector<matGmsh::MixedBranchZoneSummary> summaries;
  const std::size_t removed = mesh.filterMixedBranchWings(
      "", fixture.rawColors, {}, &report, &zoneByFace, nullptr, &summaries);
  const bool protectJunction = contact == Contact::InteriorSharedEdge ||
                               contact == Contact::MixedInteriorSharedEdge;
  require(removed == (protectJunction ? 9 : 12),
          "Unexpected number of removed mixed-zone faces:\n" + report.str());
  require(summaries.size() >= 2 &&
          zoneByFace[fixture.junctionZone.front()] > 0 &&
          zoneByFace[fixture.terminalZone.front()] > 0 &&
          zoneByFace[fixture.junctionZone.front()] !=
              zoneByFace[fixture.terminalZone.front()],
          "Fixture did not produce two distinct CAD support zones");
  // With the raw collar present, the existing local-radius ridge criterion
  // splits the first CAD support patch into two three-cell zones. Only its
  // first column actually touches the fixed sheet.
  if(contact == Contact::InteriorSharedEdge)
    require(summaries.size() == 3 &&
            zoneByFace[fixture.junctionZone.front()] !=
                zoneByFace[fixture.transitionZone.front()],
            "Fixture did not isolate the fixed-sheet interface zone");
  for(std::size_t face : fixture.junctionZone)
    require(mesh.vor.faceColors[face] == (protectJunction ? 0 : -1),
            "Shared-edge junction protection has the wrong extent");
  for(std::size_t face : fixture.terminalZone)
    require(mesh.vor.faceColors[face] == -1,
            "Interface protection propagated into the terminal neighbor");
  for(std::size_t face : fixture.transitionZone)
    require(mesh.vor.faceColors[face] == -1,
            "Interface protection propagated within the same CAD support patch");
  for(std::size_t face : fixture.fixedSheet) {
    require(contact == Contact::MixedInteriorSharedEdge ? zoneByFace[face] > 0 :
                zoneByFace[face] == -1,
            "The neighboring sheet has the wrong mixed-analysis membership");
    require(mesh.vor.faceColors[face] == originalColors[face],
            "The filter modified the fixed or already rejected sheet");
  }
  for(std::size_t face = 0; face < originalColors.size(); ++face) {
    if(originalColors[face] < 0)
      require(mesh.vor.faceColors[face] == -1,
              "Interface guard restored an already rejected raw face");
    require(mesh.vor.faces[face].verts == originalFaces[face].verts &&
            mesh.vor.faces[face].edge.a == originalFaces[face].edge.a &&
            mesh.vor.faces[face].edge.b == originalFaces[face].edge.b,
            "Classification changed original MAT connectivity or supports");
  }
  require(mesh.vor.vertices == originalCoordinates &&
          mesh.del.seeds == originalSeeds,
          "Classification moved MAT vertices or CAD seeds");
}

} // namespace

int main()
{
  bool initialized = false;
  try {
    gmsh::initialize();
    initialized = true;
    gmsh::option::setNumber("General.Terminal", 0);
    check(Contact::InteriorSharedEdge);
    check(Contact::MixedInteriorSharedEdge);
    check(Contact::SharedVertex);
    check(Contact::RejectedSheet);
    check(Contact::TerminalSharedEdge);
    check(Contact::SteepInteriorSharedEdge);
    gmsh::finalize();
    std::cout << "Mixed-branch fixed-sheet interface: PASS\n";
    return 0;
  }
  catch(const std::exception &error) {
    if(initialized) gmsh::finalize();
    std::cerr << error.what() << '\n';
    return 1;
  }
}
