// Extracted from MatGmsh for the native Gmsh MAT pipeline.
// See SOURCE_PROVENANCE.txt for the extraction boundary.
#include "matGmsh.h"

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <limits>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <unordered_map>

#include <Eigen/Geometry>
#include <gmsh.h>

namespace {
using Point = Eigen::Vector3d;
using Edge = matGmshEdge;
struct EdgeHash {
  std::size_t operator()(const Edge &edge) const
  {
    return (static_cast<std::size_t>(static_cast<unsigned int>(edge.a)) << 32) ^
           static_cast<unsigned int>(edge.b);
  }
};

// A simple closed cycle or open chain, with no extra component or branch.
bool simpleChain(const std::vector<Edge> &edges, bool closed)
{
  if(edges.empty()) return false;
  std::map<int, std::vector<int>> graph;
  for(const Edge &edge : edges) {
    graph[edge.a].push_back(edge.b);
    graph[edge.b].push_back(edge.a);
  }
  std::size_t endpoints = 0;
  for(const auto &entry : graph) {
    if(entry.second.size() == 1) ++endpoints;
    else if(entry.second.size() != 2) return false;
  }
  if(endpoints != (closed ? 0 : 2)) return false;
  std::set<int> visited;
  std::vector<int> pending{graph.begin()->first};
  while(!pending.empty()) {
    const int vertex = pending.back();
    pending.pop_back();
    if(!visited.insert(vertex).second) continue;
    for(int next : graph.at(vertex)) pending.push_back(next);
  }
  return visited.size() == graph.size();
}

// Disjoint open chains only: a full sewn rim, a cycle and a branched contact
// are deliberately excluded. The complementary free rim is checked too.
bool openChainForest(const std::vector<Edge> &edges,
                     std::vector<std::vector<Edge>> &chains)
{
  chains.clear();
  if(edges.empty()) return false;
  std::map<int, std::vector<Edge>> incident;
  std::set<Edge> remaining;
  for(const Edge &edge : edges) {
    if(edge.a == edge.b || !remaining.insert(edge).second) return false;
    incident[edge.a].push_back(edge);
    incident[edge.b].push_back(edge);
  }
  for(const auto &entry : incident)
    if(entry.second.size() > 2) return false;
  while(!remaining.empty()) {
    std::vector<Edge> chain;
    std::set<int> visited;
    std::vector<int> pending{remaining.begin()->a};
    std::size_t endpoints = 0;
    while(!pending.empty()) {
      const int vertex = pending.back();
      pending.pop_back();
      if(!visited.insert(vertex).second) continue;
      if(incident.at(vertex).size() == 1) ++endpoints;
      for(const Edge &edge : incident.at(vertex)) {
        if(remaining.erase(edge) != 0) chain.push_back(edge);
        pending.push_back(edge.a == vertex ? edge.b : edge.a);
      }
    }
    if(endpoints != 2) { chains.clear(); return false; }
    chains.push_back(std::move(chain));
  }
  return true;
}

template <class Container>
void list(std::ostream &out, const Container &values)
{
  out << '[';
  bool first = true;
  for(const auto &value : values) {
    if(!first) out << ',';
    out << value;
    first = false;
  }
  out << ']';
}
}

std::size_t matGmsh::reportSmallTerminalBranches(
    const std::vector<int> &rawColors, std::ostream &report) const
{
  return inspectSmallTerminalBranches(rawColors, report, nullptr);
}

std::size_t matGmsh::filterSmallTerminalBranches(
    const std::vector<int> &rawColors, std::ostream *report)
{
  std::ostringstream quiet;
  std::ostream &out = report ? *report : quiet;
  std::vector<std::size_t> removable;
  inspectSmallTerminalBranches(rawColors, out, &removable);
  std::set<int> removedBranches;
  for(std::size_t face : removable) {
    vor.faceColors[face] = -1;
    removedBranches.insert(rawColors[face]);
  }
  out << "Terminal branch filter: removedBranches=" << removedBranches.size()
      << " removedFaces=" << removable.size() << " rawBranches=";
  list(out, removedBranches);
  out << '\n';
  return removable.size();
}

std::size_t matGmsh::inspectSmallTerminalBranches(
    const std::vector<int> &rawColors, std::ostream &report,
    std::vector<std::size_t> *removableFaces) const
{
  if(rawColors.size() != vor.faces.size() ||
     vor.faceColors.size() != vor.faces.size())
    throw std::invalid_argument("Terminal branch diagnostics require complete colors");

  struct Branch {
    std::size_t rawCount = 0, selectedCount = 0;
    std::vector<std::size_t> selected;
    Point minimum = Point::Constant(std::numeric_limits<double>::infinity());
    Point maximum = Point::Constant(-std::numeric_limits<double>::infinity());
  };
  std::map<int, Branch> branches;
  for(std::size_t face = 0; face < vor.faces.size(); ++face) {
    if(rawColors[face] < 0) continue;
    Branch &branch = branches[rawColors[face]];
    ++branch.rawCount;
    if(vor.faceColors[face] < 0) continue;
    ++branch.selectedCount;
    if(branch.selectedCount <= 2) branch.selected.push_back(face);
  }
  for(auto it = branches.begin(); it != branches.end();) {
    if(it->second.selectedCount == 0 || it->second.selectedCount > 2)
      it = branches.erase(it);
    else ++it;
  }

  const std::size_t vertexCount = vor.vertices.size() / 3;
  const auto validVertex = [&](int vertex) {
    return vertex >= 0 && static_cast<std::size_t>(vertex) < vertexCount;
  };
  const auto point = [&](int vertex) -> Point {
    return {vor.vertices[3 * vertex], vor.vertices[3 * vertex + 1],
            vor.vertices[3 * vertex + 2]};
  };
  struct EdgeUse {
    std::size_t rawCount = 0;
    std::vector<std::size_t> selected;
  };
  std::unordered_map<Edge, EdgeUse, EdgeHash> edgeUses;
  std::unordered_map<int, std::size_t> selectedVertexUses;
  for(const auto &branch : branches)
    for(std::size_t face : branch.second.selected) {
      const auto &vertices = vor.faces[face].verts;
      for(std::size_t i = 0; i < vertices.size(); ++i) {
        const int a = vertices[i], b = vertices[(i + 1) % vertices.size()];
        if(!validVertex(a) || !validVertex(b)) continue;
        edgeUses.emplace(Edge(a, b), EdgeUse{});
        selectedVertexUses.emplace(a, 0);
      }
    }
  // Index only edges/vertices touched by the small candidates. The complete
  // Voronoi complex can contain millions of polygons and needs no new graph.
  for(std::size_t face = 0; face < vor.faces.size(); ++face) {
    if(rawColors[face] < 0) continue;
    const auto &vertices = vor.faces[face].verts;
    const auto branch = branches.find(rawColors[face]);
    for(std::size_t i = 0; i < vertices.size(); ++i) {
      const int a = vertices[i], b = vertices[(i + 1) % vertices.size()];
      if(!validVertex(a) || !validVertex(b)) continue;
      if(branch != branches.end()) {
        branch->second.minimum = branch->second.minimum.cwiseMin(point(a));
        branch->second.maximum = branch->second.maximum.cwiseMax(point(a));
      }
      if(vor.faceColors[face] >= 0) {
        const auto vertex = selectedVertexUses.find(a);
        if(vertex != selectedVertexUses.end()) ++vertex->second;
      }
      const auto edge = edgeUses.find(Edge(a, b));
      if(edge == edgeUses.end()) continue;
      ++edge->second.rawCount;
      if(vor.faceColors[face] >= 0) edge->second.selected.push_back(face);
    }
  }

  const auto seedPoint = [&](int seed) -> Point {
    return {del.seeds[3 * seed], del.seeds[3 * seed + 1],
            del.seeds[3 * seed + 2]};
  };
  const auto validSeed = [&](int seed) {
    return seed >= 0 && static_cast<std::size_t>(seed) < del.seeds.size() / 3;
  };
  struct Normal { bool available = false; Point value = Point::Zero(); };
  std::map<std::pair<int, int>, Normal> normals;
  const auto normalAtSeed = [&](int seed, int faceTag) -> Normal {
    const auto key = std::make_pair(seed, faceTag);
    const auto found = normals.find(key);
    if(found != normals.end()) return found->second;
    Normal result;
    if(validSeed(seed) && static_cast<std::size_t>(seed) < del.nodeTags.size()) {
      try {
        std::vector<double> xyz, parameter, uv, values;
        int dimension = -1, tag = -1;
        gmsh::model::mesh::getNode(del.nodeTags[seed], xyz, parameter,
                                   dimension, tag);
        // Stored node parameters are valid only for the actual source seed.
        if(xyz.size() == 3 &&
           (Point(xyz[0], xyz[1], xyz[2]) - seedPoint(seed)).norm() <=
               1.e-10 * std::max(1.0, seedPoint(seed).norm())) {
          if(dimension == 2 && tag == faceTag && parameter.size() == 2)
            uv = parameter;
          else if(dimension == 1 && parameter.size() == 1 && std::isfinite(parameter[0]))
            gmsh::model::reparametrizeOnSurface(1, tag, parameter, faceTag, uv, 1);
          if(uv.size() == 2 && std::isfinite(uv[0]) && std::isfinite(uv[1])) {
            gmsh::model::getNormal(faceTag, uv, values);
            if(values.size() == 3) {
              result.value = Point(values[0], values[1], values[2]);
              result.available = result.value.allFinite() &&
                                 result.value.norm() > 1.e-30;
              if(result.available) result.value.normalize();
            }
          }
        }
      }
      catch(...) { /* Missing support is diagnostic uncertainty, never rejection. */ }
    }
    normals.emplace(key, result);
    return result;
  };

  struct Support {
    bool geometryAvailable = false;
    bool sameCadPair = false;
    std::size_t requested = 0, reliable = 0;
    double best = -1.0;
    double centerOpeningAngle = 180.0;
    double maximumOpeningAngle = 180.0;
    double maximumOpeningAwayFromRoot = 180.0;
  };
  const auto reportSupport = [&](std::size_t face, const char *kind,
                                  const std::set<int> &rootVertices,
                                  const std::set<int> &freeVertices) -> Support {
    Support result;
    std::ostringstream replay;
    replay << std::setprecision(17);
    const auto &polygon = vor.faces[face];
    const int a = polygon.edge.a, b = polygon.edge.b;
    report << "  terminalSupport kind=" << kind << " rawFace=" << face
           << " rawBranch=" << rawColors[face] << " seeds=(" << a << ',' << b << ')';
    if(!validSeed(a) || !validSeed(b) ||
       !seedPoint(a).allFinite() || !seedPoint(b).allFinite()) {
      report << " available=0\n"; return result;
    }
    const Point seedA = seedPoint(a), seedB = seedPoint(b);
    replay << "  terminalSeeds kind=" << kind << " rawFace=" << face
           << " a=(" << seedA.x() << ',' << seedA.y() << ',' << seedA.z() << ')'
           << " b=(" << seedB.x() << ',' << seedB.y() << ',' << seedB.z() << ')'
           << " nodeTags=("
           << (static_cast<std::size_t>(a) < del.nodeTags.size() ? del.nodeTags[a] : 0)
           << ','
           << (static_cast<std::size_t>(b) < del.nodeTags.size() ? del.nodeTags[b] : 0)
           << ")\n";
    Point center = Point::Zero();
    std::size_t count = 0;
    for(int vertex : polygon.verts)
      if(validVertex(vertex)) { center += point(vertex); ++count; }
    if(count == 0) { report << " available=0\n"; return result; }
    center /= static_cast<double>(count);
    const Point connector = seedPoint(b) - seedPoint(a);
    const double distance = connector.norm();
    const double radius = .5 * ((center - seedPoint(a)).norm() +
                                (center - seedPoint(b)).norm());
    const double angle = radius > 1.e-30 ?
        2.0 * std::asin(std::clamp(distance / (2.0 * radius), 0.0, 1.0)) *
            180.0 / std::acos(-1.0) : 0.0;
    result.geometryAvailable = std::isfinite(distance) && std::isfinite(radius) &&
                               distance > 1.e-30 && radius > 1.e-30 &&
                               center.allFinite() && std::isfinite(angle);
    result.centerOpeningAngle = angle;
    result.maximumOpeningAngle = angle;
    result.maximumOpeningAwayFromRoot = angle;
    replay << "  terminalCenter kind=" << kind << " rawFace=" << face
           << " xyz=(" << center.x() << ',' << center.y() << ',' << center.z() << ')'
           << " openingAngle=" << angle << '\n';
    for(int vertex : polygon.verts) {
      if(!validVertex(vertex) || !point(vertex).allFinite()) {
        result.geometryAvailable = false;
        continue;
      }
      const double vertexRadius = .5 * ((point(vertex) - seedPoint(a)).norm() +
                                         (point(vertex) - seedPoint(b)).norm());
      if(!(vertexRadius > 1.e-30) || !std::isfinite(vertexRadius)) {
        result.geometryAvailable = false;
        continue;
      }
      const double vertexAngle =
          2.0 * std::asin(std::clamp(distance / (2.0 * vertexRadius), 0.0, 1.0)) *
              180.0 / std::acos(-1.0);
      result.maximumOpeningAngle = std::max(result.maximumOpeningAngle, vertexAngle);
      if(!rootVertices.count(vertex))
        result.maximumOpeningAwayFromRoot =
            std::max(result.maximumOpeningAwayFromRoot, vertexAngle);
      const Point xyz = point(vertex);
      replay << "  terminalVertex kind=" << kind << " rawFace=" << face
             << " vertex=" << vertex
             << " xyz=(" << xyz.x() << ',' << xyz.y() << ',' << xyz.z() << ')'
             << " openingAngle=" << vertexAngle
             << " isRoot=" << rootVertices.count(vertex)
             << " isFreeRim=" << freeVertices.count(vertex) << '\n';
    }
    report << " seedDistance=" << distance << " radius=" << radius
           << " openingAngle=" << angle
           << " maximumOpeningAngle=" << result.maximumOpeningAngle
           << " maximumOpeningAwayFromRoot=" << result.maximumOpeningAwayFromRoot;
    if(static_cast<std::size_t>(a) >= del.seedFaces.size() ||
       static_cast<std::size_t>(b) >= del.seedFaces.size()) {
      report << " supportAvailable=0\n" << replay.str();
      return result;
    }
    report << " cadA="; list(report, del.seedFaces[a]);
    report << " cadB="; list(report, del.seedFaces[b]);
    if(static_cast<std::size_t>(a) < del.onWhat.size() &&
       static_cast<std::size_t>(b) < del.onWhat.size())
      report << " seedEntities=(" << del.onWhat[a].first << ',' << del.onWhat[a].second
             << ";" << del.onWhat[b].first << ',' << del.onWhat[b].second << ')';
    std::size_t requested = 0, reliable = 0;
    double best = -1.0, parallelism = -1.0, incidence = -1.0, signedDot = 0.0;
    std::pair<int, int> bestPair{-1, -1};
    for(int cadA : del.seedFaces[a]) for(int cadB : del.seedFaces[b]) {
      if(cadA == cadB) {
        result.sameCadPair = true;
        replay << "  terminalPair kind=" << kind << " rawFace=" << face
               << " cadA=" << cadA << " cadB=" << cadB
               << " evaluated=0 reason=sameCad\n";
        continue;
      }
      if(distance <= 1.e-30) continue;
      ++requested;
      const Normal na = normalAtSeed(a, cadA), nb = normalAtSeed(b, cadB);
      replay << "  terminalPair kind=" << kind << " rawFace=" << face
             << " cadA=" << cadA << " cadB=" << cadB
             << " knownA=" << na.available << " knownB=" << nb.available
             << " normalA=(" << na.value.x() << ',' << na.value.y() << ',' << na.value.z() << ')'
             << " normalB=(" << nb.value.x() << ',' << nb.value.y() << ',' << nb.value.z() << ')';
      if(!na.available || !nb.available) {
        replay << " evaluated=0 reason=unknownNormal\n";
        continue;
      }
      ++reliable;
      const double alignment = std::abs(na.value.dot(nb.value));
      const double axial = std::min(std::abs(na.value.dot(connector / distance)),
                                    std::abs(nb.value.dot(connector / distance)));
      const double compatibility = std::min(alignment, axial);
      replay << " evaluated=1 compatibility=" << compatibility << '\n';
      if(compatibility > best) {
        best = compatibility; parallelism = alignment; incidence = axial;
        signedDot = na.value.dot(nb.value); bestPair = {cadA, cadB};
      }
    }
    report << " supportPairs=" << requested << " reliableSupportPairs=" << reliable
           << " sameCadPair=" << result.sameCadPair
           << " bestPair=(" << bestPair.first << ',' << bestPair.second << ')'
           << " compatibility=" << best << " normalAbsDot=" << parallelism
           << " normalSignedDot=" << signedDot << " incidence=" << incidence << '\n'
           << replay.str();
    result.requested = requested;
    result.reliable = reliable;
    result.best = best;
    return result;
  };

  const auto oldPrecision = report.precision();
  report << std::setprecision(12);
  // Same 50-degree support tolerance as mixed-zone junction protection.
  // Both this geometric evidence and the terminal topology are mandatory.
  const double minimumHostCompatibility = std::cos(50.0 * std::acos(-1.0) / 180.0);
  struct Proposal {
    int branch;
    std::vector<std::size_t> faces;
    std::set<std::size_t> rootFaces;
    std::size_t rootChainCount;
  };
  std::vector<Proposal> proposals;
  std::size_t componentCount = 0, terminalCount = 0;
  for(const auto &entry : branches) {
    std::vector<std::vector<std::size_t>> components;
    const auto &selected = entry.second.selected;
    bool joined = false;
    if(selected.size() == 2) {
      for(const auto &edge : edgeUses) {
        const auto &uses = edge.second.selected;
        if(uses.size() == 2 &&
           ((uses[0] == selected[0] && uses[1] == selected[1]) ||
            (uses[0] == selected[1] && uses[1] == selected[0]))) {
          joined = true;
          break;
        }
      }
    }
    if(joined) components.push_back(selected);
    else for(std::size_t face : selected) components.push_back({face});
    for(const auto &component : components) {
      ++componentCount;
      std::map<Edge, std::size_t> patchEdges;
      std::map<int, std::size_t> patchVertexUses;
      std::map<int, std::vector<Edge>> links;
      bool valid = true;
      Point minimum = Point::Constant(std::numeric_limits<double>::infinity());
      Point maximum = Point::Constant(-std::numeric_limits<double>::infinity());
      Point center = Point::Zero();
      double area = 0.0;
      for(std::size_t face : component) {
        const auto &vertices = vor.faces[face].verts;
        std::set<int> unique(vertices.begin(), vertices.end());
        if(vertices.size() < 3 || unique.size() != vertices.size()) { valid = false; break; }
        Point polygonCenter = Point::Zero();
        for(int vertex : vertices) {
          if(!validVertex(vertex) || !point(vertex).allFinite()) { valid = false; break; }
          polygonCenter += point(vertex);
          minimum = minimum.cwiseMin(point(vertex));
          maximum = maximum.cwiseMax(point(vertex));
          ++patchVertexUses[vertex];
        }
        if(!valid) break;
        polygonCenter /= static_cast<double>(vertices.size());
        for(std::size_t i = 0; i < vertices.size(); ++i) {
          const int a = vertices[i], b = vertices[(i + 1) % vertices.size()];
          ++patchEdges[Edge(a, b)];
          links[a].emplace_back(vertices[(i + vertices.size() - 1) % vertices.size()], b);
          const double triangleArea = .5 * (point(a) - polygonCenter).cross(point(b) - polygonCenter).norm();
          area += triangleArea;
          center += triangleArea * (polygonCenter + point(a) + point(b)) / 3.0;
        }
      }
      if(!valid || !(area > 0.0) || !std::isfinite(area)) {
        report << "Small retained branch diagnostic: rawBranch=" << entry.first
               << " component=" << componentCount << " invalidPolygon=1 selectionChanged=0\n";
        continue;
      }
      if(area > 0.0) center /= area;
      std::vector<Edge> rim, root, free;
      std::set<int> rimVertices, rootVertices, neighbors;
      std::set<std::size_t> rootFaces;
      std::set<Edge> joinedRootEdges;
      bool regularInterior = true, redundantRoot = true, validRootValences = true;
      std::size_t inheritedFree = 0;
      for(const auto &edge : patchEdges) {
        const EdgeUse &uses = edgeUses.at(edge.first);
        std::vector<std::size_t> outside;
        for(std::size_t face : uses.selected)
          if(std::find(component.begin(), component.end(), face) == component.end()) outside.push_back(face);
        if(edge.second == 2) {
          if(!outside.empty()) regularInterior = false;
          continue;
        }
        if(edge.second != 1) { regularInterior = false; continue; }
        rim.push_back(edge.first);
        rimVertices.insert(edge.first.a); rimVertices.insert(edge.first.b);
        if(outside.empty()) {
          free.push_back(edge.first);
          if(uses.rawCount == 1) ++inheritedFree;
        }
        else {
          root.push_back(edge.first);
          rootVertices.insert(edge.first.a); rootVertices.insert(edge.first.b);
          const bool joined = outside.size() == 2 &&
                              rawColors[outside[0]] != rawColors[outside[1]];
          if(joined) joinedRootEdges.insert(edge.first);
          else redundantRoot = false;
          if(outside.size() > 2 || (outside.size() == 2 && !joined))
            validRootValences = false;
          for(std::size_t face : outside) {
            rootFaces.insert(face); neighbors.insert(rawColors[face]);
          }
        }
      }
      bool manifoldLinks = true, extraVertexContacts = false;
      for(const auto &vertex : patchVertexUses) {
        if(!simpleChain(links.at(vertex.first), rimVertices.count(vertex.first) == 0)) manifoldLinks = false;
        if(selectedVertexUses.at(vertex.first) > vertex.second && !rootVertices.count(vertex.first))
          extraVertexContacts = true;
      }
      const long long euler = static_cast<long long>(patchVertexUses.size()) -
          static_cast<long long>(patchEdges.size()) + static_cast<long long>(component.size());
      const bool disk = valid && regularInterior && manifoldLinks && euler == 1 && simpleChain(rim, true);
      std::vector<std::vector<Edge>> rootChains, freeChains;
      const bool rootsAreForest = openChainForest(root, rootChains);
      const bool freeIsForest = openChainForest(free, freeChains);
      const bool hasJoinedBase = rootsAreForest && std::any_of(rootChains.begin(), rootChains.end(),
          [&](const std::vector<Edge> &chain) {
            return std::all_of(chain.begin(), chain.end(),
                [&](const Edge &edge) { return joinedRootEdges.count(edge) != 0; });
          });
      const bool terminal = disk && rootsAreForest && freeIsForest &&
                            rootChains.size() == freeChains.size() && !extraVertexContacts;
      const bool topologyEligible = terminal && validRootValences && hasJoinedBase;
      if(terminal) ++terminalCount;
      report << "Small retained branch diagnostic: rawBranch=" << entry.first
             << " component=" << componentCount << " rawFaces=" << entry.second.rawCount
             << " selectedBranchFaces=" << selected.size() << " faces=" << component.size()
             << " faceIds="; list(report, component);
      report << " disk=" << disk << " terminal=" << terminal
             << " redundantRoot=" << (terminal && redundantRoot)
             << " hasJoinedBase=" << hasJoinedBase
             << " validRootValences=" << validRootValences
             << " rootChains=" << rootChains.size()
             << " extraVertexContacts=" << extraVertexContacts << " euler=" << euler
             << " rootEdges=" << root.size() << " freeEdges=" << free.size()
             << " inheritedFreeEdges=" << inheritedFree
             << " area=" << area << " diameter=" << (maximum - minimum).norm()
             << " rawDiameter=" << (entry.second.maximum - entry.second.minimum).norm()
             << " center=(" << center.x() << ',' << center.y() << ',' << center.z() << ')'
             << " neighbors="; list(report, neighbors); report << '\n';
      bool allWeakKnown = true, allCentersAcute = true, supportedHost = !rootFaces.empty();
      std::set<int> freeVertices;
      for(const Edge &edge : free) {
        freeVertices.insert(edge.a);
        freeVertices.insert(edge.b);
      }
      for(std::size_t face : component) {
        const Support support = reportSupport(face, "candidate", rootVertices, freeVertices);
        allWeakKnown = allWeakKnown && support.geometryAvailable &&
            !support.sameCadPair && support.requested > 0 &&
            support.reliable == support.requested && support.best >= 0.0 &&
            support.best < minimumHostCompatibility;
        // The contact angle describes the polygon center, as in the branch
        // classifier. A large angle at a shared circumcenter is not evidence
        // of an opposed CAD support; retain vertex extrema for diagnostics.
        allCentersAcute = allCentersAcute && support.geometryAvailable &&
                          support.centerOpeningAngle < 90.0;
      }
      for(std::size_t face : rootFaces) {
        const Support support = reportSupport(face, "root", rootVertices, freeVertices);
        supportedHost = supportedHost && support.geometryAvailable &&
            support.reliable > 0 && support.best >= minimumHostCompatibility;
      }
      const bool proposed = topologyEligible && allWeakKnown &&
                            allCentersAcute && supportedHost;
      report << "  terminalDecision rawBranch=" << entry.first
             << " topologyEligible=" << topologyEligible
             << " allWeakKnown=" << allWeakKnown << " allCentersAcute=" << allCentersAcute
             << " supportedHost=" << supportedHost << " proposed=" << proposed << '\n';
      if(proposed) proposals.push_back({entry.first, component, rootFaces, rootChains.size()});
    }
  }
  // Every certificate used the same retained snapshot. A proposed patch
  // cannot also supply the host whose continued presence justifies another.
  std::set<std::size_t> proposedFaces;
  for(const Proposal &proposal : proposals)
    proposedFaces.insert(proposal.faces.begin(), proposal.faces.end());

  // Multiple intervals or more than two host faces require a connectivity
  // proof without ANY proposed patch. Even along one chain, the incident
  // host pair can change at a vertex. Use adjacency through whole edges;
  // only a single chain carried by the same two host faces is immediate.
  const bool needsHostConnectivity = std::any_of(proposals.begin(), proposals.end(),
      [](const Proposal &proposal) {
        return proposal.rootChainCount > 1 || proposal.rootFaces.size() > 2;
      });
  const std::size_t absent = std::numeric_limits<std::size_t>::max();
  std::vector<std::size_t> parent;
  std::vector<unsigned char> rank;
  const auto findRoot = [&](std::size_t face) {
    std::size_t root = face;
    while(parent[root] != root) root = parent[root];
    while(parent[face] != face) {
      const std::size_t next = parent[face];
      parent[face] = root;
      face = next;
    }
    return root;
  };
  std::size_t connectivityFaces = 0, connectivityEdges = 0;
  if(needsHostConnectivity) {
    parent.assign(vor.faces.size(), absent);
    rank.assign(vor.faces.size(), 0);
    std::vector<unsigned char> excluded(vor.faces.size(), 0);
    for(std::size_t face : proposedFaces) excluded[face] = 1;
    std::unordered_map<Edge, std::size_t, EdgeHash> firstFaceByEdge;
    const std::size_t selectedCount = std::count_if(vor.faceColors.begin(), vor.faceColors.end(),
        [](int color) { return color >= 0; });
    firstFaceByEdge.reserve(3 * selectedCount);
    for(std::size_t face = 0; face < vor.faces.size(); ++face) {
      if(vor.faceColors[face] < 0 || excluded[face]) continue;
      const auto &vertices = vor.faces[face].verts;
      if(vertices.size() < 3 ||
         !std::all_of(vertices.begin(), vertices.end(), validVertex)) continue;
      parent[face] = face;
      ++connectivityFaces;
      for(std::size_t local = 0; local < vertices.size(); ++local) {
        const Edge edge(vertices[local], vertices[(local + 1) % vertices.size()]);
        if(edge.a == edge.b) continue;
        const auto inserted = firstFaceByEdge.emplace(edge, face);
        if(inserted.second) continue;
        std::size_t a = findRoot(face), b = findRoot(inserted.first->second);
        if(a == b) continue;
        if(rank[a] < rank[b]) std::swap(a, b);
        parent[b] = a;
        if(rank[a] == rank[b]) ++rank[a];
      }
    }
    connectivityEdges = firstFaceByEdge.size();
  }
  if(removableFaces) removableFaces->clear();
  std::size_t conflictingCandidates = 0, disconnectedHosts = 0;
  for(const Proposal &proposal : proposals) {
    const bool conflict = std::any_of(proposal.rootFaces.begin(), proposal.rootFaces.end(),
        [&](std::size_t face) { return proposedFaces.count(face) != 0; });
    if(conflict) ++conflictingCandidates;
    bool hostsConnected = true;
    if(proposal.rootChainCount > 1 || proposal.rootFaces.size() > 2) {
      std::size_t commonRoot = absent;
      for(std::size_t face : proposal.rootFaces) {
        if(parent[face] == absent) { hostsConnected = false; break; }
        const std::size_t root = findRoot(face);
        if(commonRoot == absent) commonRoot = root;
        else if(root != commonRoot) { hostsConnected = false; break; }
      }
    }
    if(!hostsConnected) ++disconnectedHosts;
    const bool removable = !conflict && hostsConnected;
    report << "  terminalCertificate rawBranch=" << proposal.branch
           << " rootChains=" << proposal.rootChainCount
           << " hostConflict=" << conflict << " hostsConnected=" << hostsConnected
           << " removable=" << removable << '\n';
    if(removable && removableFaces)
      removableFaces->insert(removableFaces->end(), proposal.faces.begin(), proposal.faces.end());
  }
  report << "Small retained branch diagnostics: branches=" << branches.size()
         << " components=" << componentCount << " terminalDisks=" << terminalCount
         << " proposed=" << proposals.size() << " hostConflicts=" << conflictingCandidates
         << " disconnectedHosts=" << disconnectedHosts
         << " connectivityFaces=" << connectivityFaces
         << " connectivityEdges=" << connectivityEdges
         << " selectionChanged=0\n";
  report.precision(oldPrecision);
  return terminalCount;
}
