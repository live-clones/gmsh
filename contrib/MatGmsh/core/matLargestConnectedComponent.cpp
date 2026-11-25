#include "matLargestConnectedComponent.h"

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <iterator>
#include <map>
#include <queue>
#include <stdexcept>
#include <utility>

namespace matLargestConnectedComponent {
namespace {

using Point = std::array<double, 3>;

Point point(const std::vector<double> &vertices, int vertex)
{
  return {vertices[3 * vertex], vertices[3 * vertex + 1],
          vertices[3 * vertex + 2]};
}

Point subtract(const Point &a, const Point &b)
{
  return {a[0] - b[0], a[1] - b[1], a[2] - b[2]};
}

Point cross(const Point &a, const Point &b)
{
  return {a[1] * b[2] - a[2] * b[1],
          a[2] * b[0] - a[0] * b[2],
          a[0] * b[1] - a[1] * b[0]};
}

double norm(const Point &a)
{
  return std::sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
}

double polygonArea(const std::vector<int> &face,
                   const std::vector<double> &vertices)
{
  const std::size_t vertexCount = vertices.size() / 3;
  std::vector<int> valid;
  valid.reserve(face.size());
  for(int vertex : face) {
    if(vertex < 0 || static_cast<std::size_t>(vertex) >= vertexCount)
      continue;
    if(valid.empty() || valid.back() != vertex) valid.push_back(vertex);
  }
  if(valid.size() > 1 && valid.front() == valid.back()) valid.pop_back();
  if(valid.size() < 3) return 0.0;

  Point center{0.0, 0.0, 0.0};
  for(int vertex : valid) {
    const Point p = point(vertices, vertex);
    center[0] += p[0];
    center[1] += p[1];
    center[2] += p[2];
  }
  const double inverse = 1.0 / static_cast<double>(valid.size());
  center[0] *= inverse;
  center[1] *= inverse;
  center[2] *= inverse;

  double area = 0.0;
  for(std::size_t local = 0; local < valid.size(); ++local) {
    const Point a = subtract(point(vertices, valid[local]), center);
    const Point b = subtract(
        point(vertices, valid[(local + 1) % valid.size()]), center);
    area += 0.5 * norm(cross(a, b));
  }
  return area;
}

Point polygonNormal(const std::vector<int> &face,
                    const std::vector<double> &vertices)
{
  const std::size_t vertexCount = vertices.size() / 3;
  std::vector<int> valid;
  valid.reserve(face.size());
  for(int vertex : face) {
    if(vertex < 0 || static_cast<std::size_t>(vertex) >= vertexCount)
      continue;
    if(valid.empty() || valid.back() != vertex) valid.push_back(vertex);
  }
  if(valid.size() > 1 && valid.front() == valid.back()) valid.pop_back();
  Point normal{0.0, 0.0, 0.0};
  if(valid.size() < 3) return normal;
  for(std::size_t local = 0; local < valid.size(); ++local) {
    const Point a = point(vertices, valid[local]);
    const Point b = point(vertices, valid[(local + 1) % valid.size()]);
    normal[0] += (a[1] - b[1]) * (a[2] + b[2]);
    normal[1] += (a[2] - b[2]) * (a[0] + b[0]);
    normal[2] += (a[0] - b[0]) * (a[1] + b[1]);
  }
  const double length = norm(normal);
  if(length > 0.0) {
    normal[0] /= length;
    normal[1] /= length;
    normal[2] /= length;
  }
  return normal;
}

double dot(const Point &a, const Point &b)
{
  return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

struct Component {
  std::vector<std::size_t> faces;
  double area = 0.0;
  std::size_t seed = 0;
};

// Each root is a connected component of signed face adjacencies, not a color:
// disconnected pieces and protected seams may choose independent orientations.
// Union by rank, without path compression, permits a whole proposed color
// merge to be rolled back if any of its interfaces closes an inconsistent cycle.
class FaceOrientation {
  struct Change {
    std::size_t child, parent;
    bool increasedRank;
  };
  std::vector<std::size_t> parent_;
  std::vector<unsigned char> rank_, parity_;
  std::vector<Change> changes_;

  std::pair<std::size_t, unsigned char> find(std::size_t face) const
  {
    unsigned char parity = 0;
    while(parent_[face] != face) {
      parity ^= parity_[face];
      face = parent_[face];
    }
    return {face, parity};
  }

public:
  explicit FaceOrientation(std::size_t count)
    : parent_(count), rank_(count, 0), parity_(count, 0)
  {
    for(std::size_t face = 0; face < count; ++face) parent_[face] = face;
  }

  bool join(std::size_t first, std::size_t second, unsigned char oppositeFlip,
            bool reversible = false)
  {
    auto a = find(first), b = find(second);
    const unsigned char parity = a.second ^ b.second ^ oppositeFlip;
    if(a.first == b.first) return parity == 0;
    if(rank_[a.first] < rank_[b.first]) std::swap(a, b);
    const bool increasedRank = rank_[a.first] == rank_[b.first];
    if(reversible) changes_.push_back({b.first, a.first, increasedRank});
    parent_[b.first] = a.first;
    parity_[b.first] = parity;
    if(increasedRank) ++rank_[a.first];
    return true;
  }

  void commit() { changes_.clear(); }

  std::size_t representative(std::size_t face) const { return find(face).first; }

  void rollback()
  {
    for(auto change = changes_.rbegin(); change != changes_.rend(); ++change) {
      parent_[change->child] = change->child;
      parity_[change->child] = 0;
      if(change->increasedRank) --rank_[change->parent];
    }
    changes_.clear();
  }
};

// Cache the full cell-complex Euler characteristic, but only keep its rim and
// face-component representatives. Candidate unions never rescan their faces.
struct SurfaceTopology {
  std::int64_t euler = 0;
  bool regularCells = true;
  bool preserveOpenGenusZero = false;
  std::map<matGmshEdge, std::size_t> boundary; // edge -> incident face
  std::set<std::size_t> components;
};

bool isOpenGenusZero(const SurfaceTopology &topology,
                    const FaceOrientation &orientation)
{
  if(!topology.regularCells || topology.boundary.empty()) return false;
  std::map<int, std::array<int, 2>> neighbors;
  std::set<std::size_t> componentsWithBoundary;
  const auto addNeighbor = [&](int vertex, int neighbor) {
    auto entry = neighbors.emplace(vertex, std::array<int, 2>{-1, -1});
    auto &adjacent = entry.first->second;
    if(adjacent[0] < 0) adjacent[0] = neighbor;
    else if(adjacent[1] < 0) adjacent[1] = neighbor;
    else return false;
    return true;
  };
  for(const auto &edge : topology.boundary) {
    if(!addNeighbor(edge.first.a, edge.first.b) ||
       !addNeighbor(edge.first.b, edge.first.a)) return false;
    componentsWithBoundary.insert(orientation.representative(edge.second));
  }
  for(const auto &vertex : neighbors)
    if(vertex.second[1] < 0) return false;

  std::int64_t boundaryCycles = 0;
  std::set<int> visited;
  for(const auto &vertex : neighbors) {
    if(visited.count(vertex.first)) continue;
    ++boundaryCycles;
    int previous = -1, current = vertex.first;
    do {
      if(!visited.insert(current).second) return false;
      const auto &adjacent = neighbors.at(current);
      const int next = adjacent[0] == previous ? adjacent[1] : adjacent[0];
      previous = current;
      current = next;
    } while(current != vertex.first);
  }
  std::set<std::size_t> components;
  for(std::size_t face : topology.components)
    components.insert(orientation.representative(face));
  // A disconnected color may include a sphere beside a disk. A global Euler
  // equality alone would accept it, so every face component needs a rim.
  if(components != componentsWithBoundary) return false;

  // With regular polygon cells, at most two uses per edge, orientability and
  // degree-two rim vertices, a vertex link consists of cycles and at most one
  // path. Splitting disconnected links adds D >= 0 vertices without changing
  // edge-connected components C or boundary cycles b. Its Euler characteristic
  // is chi + D = 2*C - 2*genus - b, where chi belongs to the original complex.
  // Equality with 2*C - b therefore certifies both
  // genus zero and connected vertex links; negative chi alone is not a veto.
  return topology.euler ==
      2 * static_cast<std::int64_t>(components.size()) - boundaryCycles;
}

} // namespace

MeshStatistics retainLargestMesh(
    const std::vector<std::vector<int>> &faces,
    const std::vector<double> &vertices,
    std::vector<int> &colors)
{
  if(vertices.size() % 3 != 0)
    throw std::invalid_argument("Invalid MAT vertex coordinate array");
  if(faces.size() != colors.size())
    throw std::invalid_argument("Incompatible MAT face and color arrays");

  std::map<matGmshEdge, std::vector<std::size_t>> facesByEdge;
  for(std::size_t face = 0; face < faces.size(); ++face) {
    if(colors[face] < 0) continue;
    std::set<matGmshEdge> uniqueEdges;
    for(std::size_t local = 0; local < faces[face].size(); ++local) {
      const int first = faces[face][local];
      const int second = faces[face][(local + 1) % faces[face].size()];
      if(first < 0 || second < 0 || first == second) continue;
      uniqueEdges.insert(matGmshEdge(first, second));
    }
    for(const matGmshEdge &edge : uniqueEdges)
      facesByEdge[edge].push_back(face);
  }

  std::vector<std::vector<std::size_t>> adjacency(faces.size());
  for(const auto &entry : facesByEdge) {
    const std::vector<std::size_t> &incident = entry.second;
    if(incident.size() < 2) continue;
    for(std::size_t local = 1; local < incident.size(); ++local) {
      adjacency[incident[0]].push_back(incident[local]);
      adjacency[incident[local]].push_back(incident[0]);
    }
  }

  std::vector<Component> components;
  std::vector<char> visited(faces.size(), 0);
  std::queue<std::size_t> pending;
  for(std::size_t seed = 0; seed < faces.size(); ++seed) {
    if(colors[seed] < 0 || visited[seed]) continue;
    Component component;
    component.seed = seed;
    visited[seed] = 1;
    pending.push(seed);
    while(!pending.empty()) {
      const std::size_t face = pending.front();
      pending.pop();
      component.faces.push_back(face);
      component.area += polygonArea(faces[face], vertices);
      for(std::size_t neighbor : adjacency[face]) {
        if(!visited[neighbor] && colors[neighbor] >= 0) {
          visited[neighbor] = 1;
          pending.push(neighbor);
        }
      }
    }
    components.push_back(std::move(component));
  }

  MeshStatistics statistics;
  statistics.connectedComponentCount = components.size();
  if(components.size() <= 1) return statistics;
  const auto largest = std::max_element(
      components.begin(), components.end(),
      [](const Component &first, const Component &second) {
        if(first.area != second.area) return first.area < second.area;
        if(first.faces.size() != second.faces.size())
          return first.faces.size() < second.faces.size();
        return first.seed > second.seed;
      });
  for(auto component = components.begin(); component != components.end();
      ++component) {
    if(component == largest) continue;
    ++statistics.removedComponentCount;
    statistics.removedFaceCount += component->faces.size();
    statistics.removedArea += component->area;
    for(std::size_t face : component->faces) colors[face] = -1;
  }
  return statistics;
}

Statistics splitDisconnectedColors(
    const std::vector<std::vector<int>> &faces,
    const std::vector<double> &vertices,
    const std::set<matGmshEdge> &protectedEdges,
    std::vector<int> &colors)
{
  if(vertices.size() % 3 != 0)
    throw std::invalid_argument("Invalid MAT vertex coordinate array");
  if(faces.size() != colors.size())
    throw std::invalid_argument("Incompatible MAT face and color arrays");

  Statistics statistics;
  std::map<matGmshEdge, std::vector<std::size_t>> facesByEdge;
  for(std::size_t face = 0; face < faces.size(); ++face) {
    if(colors[face] < 0) continue;
    std::set<matGmshEdge> uniqueEdges;
    for(std::size_t local = 0; local < faces[face].size(); ++local) {
      const int first = faces[face][local];
      const int second = faces[face][(local + 1) % faces[face].size()];
      if(first < 0 || second < 0 || first == second) continue;
      uniqueEdges.insert(matGmshEdge(first, second));
    }
    for(const matGmshEdge &edge : uniqueEdges)
      facesByEdge[edge].push_back(face);
  }

  std::vector<std::vector<std::size_t>> adjacency(faces.size());
  for(const auto &entry : facesByEdge) {
    const std::vector<std::size_t> &incident = entry.second;
    if(protectedEdges.count(entry.first) != 0) {
      ++statistics.preservedBarrierEdgeCount;
      continue;
    }
    if(incident.size() == 1) {
      ++statistics.finalBoundaryEdgeCount;
      continue;
    }
    if(incident.size() != 2) {
      ++statistics.finalTripleOrNonManifoldEdgeCount;
      // A T-junction can contain two faces of one continuing surface and one
      // face of another surface that terminates on it. The total MAT edge is
      // non-manifold, but the two same-color uses still form a regular edge
      // inside their host surface. Cross that host pair unless this edge was
      // explicitly protected above; the terminating surface will later use
      // the same edge as an embedded curve on the host.
      std::map<int, std::vector<std::size_t>> incidentByColor;
      for(std::size_t face : incident)
        if(colors[face] >= 0) incidentByColor[colors[face]].push_back(face);
      if(incidentByColor.size() > 1)
        ++statistics.finalInterfaceEdgeCount;
      for(const auto &colorFaces : incidentByColor) {
        if(colorFaces.second.size() != 2) continue;
        adjacency[colorFaces.second[0]].push_back(colorFaces.second[1]);
        adjacency[colorFaces.second[1]].push_back(colorFaces.second[0]);
      }
      continue;
    }
    if(colors[incident[0]] != colors[incident[1]]) {
      ++statistics.finalInterfaceEdgeCount;
      continue;
    }
    adjacency[incident[0]].push_back(incident[1]);
    adjacency[incident[1]].push_back(incident[0]);
  }

  std::map<int, std::vector<Component>> componentsByColor;
  std::vector<char> visited(faces.size(), 0);
  std::queue<std::size_t> pending;
  for(std::size_t seed = 0; seed < faces.size(); ++seed) {
    if(colors[seed] < 0 || visited[seed]) continue;
    const int color = colors[seed];
    Component component;
    component.seed = seed;
    visited[seed] = 1;
    pending.push(seed);
    while(!pending.empty()) {
      const std::size_t face = pending.front();
      pending.pop();
      component.faces.push_back(face);
      component.area += polygonArea(faces[face], vertices);
      for(std::size_t neighbor : adjacency[face]) {
        if(!visited[neighbor] && colors[neighbor] == color) {
          visited[neighbor] = 1;
          pending.push(neighbor);
        }
      }
    }
    componentsByColor[color].push_back(std::move(component));
  }

  statistics.retainedColorCount = componentsByColor.size();
  int nextColor = -1;
  for(int color : colors) nextColor = std::max(nextColor, color);
  for(auto &entry : componentsByColor) {
    statistics.sourceColorByColor[entry.first] = entry.first;
    std::vector<Component> &components = entry.second;
    statistics.connectedComponentCount += components.size();
    if(components.size() <= 1) continue;
    ++statistics.splitColorCount;

    const auto largest = std::max_element(
        components.begin(), components.end(),
        [](const Component &first, const Component &second) {
          if(first.area != second.area) return first.area < second.area;
          if(first.faces.size() != second.faces.size())
            return first.faces.size() < second.faces.size();
          return first.seed > second.seed;
        });
    for(auto component = components.begin(); component != components.end();
        ++component) {
      if(component == largest) continue;
      const int newColor = ++nextColor;
      statistics.sourceColorByColor[newColor] = entry.first;
      ++statistics.addedComponentCount;
      statistics.recoloredFaceCount += component->faces.size();
      for(std::size_t face : component->faces) colors[face] = newColor;
    }
  }
  return statistics;
}

Statistics rebuildFinalSurfaceComponents(
    const std::vector<std::vector<int>> &faces,
    const std::vector<double> &vertices,
    std::vector<int> &colors,
    std::vector<unsigned char> *reversedFaces,
    const std::set<matGmshEdge> &protectedEdges,
    bool preserveNonOrientable)
{
  if(vertices.size() % 3 != 0)
    throw std::invalid_argument("Invalid MAT vertex coordinate array");
  if(faces.size() != colors.size())
    throw std::invalid_argument("Incompatible MAT face and color arrays");

  const std::vector<int> provisionalColors = colors;
  if(reversedFaces) reversedFaces->assign(faces.size(), 0);
  Statistics statistics;
  std::set<int> retainedColors;
  struct EdgeUse {
    std::size_t face = 0;
    int direction = 0;
  };
  std::map<matGmshEdge, std::vector<EdgeUse>> usesByEdge;
  std::map<int, SurfaceTopology> topologyByRoot;
  // Most vertices belong to one color. Keep sets only at shared vertices,
  // including point-only contacts that are absent from the seam edge map.
  std::vector<int> firstVertexColor(vertices.size() / 3, -1);
  std::map<int, std::set<int>> sharedVertexColors;
  for(std::size_t face = 0; face < faces.size(); ++face) {
    if(colors[face] < 0) continue;
    retainedColors.insert(colors[face]);
    SurfaceTopology &topology = topologyByRoot[colors[face]];
    ++topology.euler; // one polygon cell
    std::vector<int> faceVertices;
    faceVertices.reserve(faces[face].size());
    for(int vertex : faces[face]) {
      if(vertex < 0 || static_cast<std::size_t>(vertex) >= firstVertexColor.size()) {
        topology.regularCells = false;
        continue;
      }
      if(std::find(faceVertices.begin(), faceVertices.end(), vertex) != faceVertices.end())
        topology.regularCells = false;
      else
        faceVertices.push_back(vertex);
      const int first = firstVertexColor[vertex];
      if(first < 0) {
        firstVertexColor[vertex] = colors[face];
        ++topology.euler;
      }
      else if(first != colors[face]) {
        auto &owners = sharedVertexColors[vertex];
        owners.insert(first);
        if(owners.insert(colors[face]).second) ++topology.euler;
      }
    }
    if(faceVertices.size() < 3) topology.regularCells = false;
    std::map<matGmshEdge, int> uniqueEdges;
    for(std::size_t local = 0; local < faces[face].size(); ++local) {
      const int first = faces[face][local];
      const int second = faces[face][(local + 1) % faces[face].size()];
      if(first < 0 || second < 0 || first == second ||
         static_cast<std::size_t>(first) >= firstVertexColor.size() ||
         static_cast<std::size_t>(second) >= firstVertexColor.size()) continue;
      const matGmshEdge edge(first, second);
      uniqueEdges.emplace(edge, first == edge.a ? 1 : -1);
    }
    for(const auto &edge : uniqueEdges)
      usesByEdge[edge.first].push_back({face, edge.second});
  }
  std::map<std::pair<int, int>, std::vector<int>> sharedVerticesByColors;
  for(const auto &vertex : sharedVertexColors) {
    for(auto first = vertex.second.begin(); first != vertex.second.end(); ++first)
      for(auto second = std::next(first); second != vertex.second.end(); ++second)
        sharedVerticesByColors[{*first, *second}].push_back(vertex.first);
  }
  // Release preprocessing storage before building the face-adjacency graph.
  std::vector<int>().swap(firstVertexColor);
  sharedVertexColors.clear();
  statistics.retainedColorCount = retainedColors.size();

  std::vector<Point> faceNormals(faces.size(), Point{0.0, 0.0, 0.0});
  std::map<int, double> areaByColor;
  for(std::size_t face = 0; face < faces.size(); ++face) {
    if(provisionalColors[face] < 0) continue;
    faceNormals[face] = polygonNormal(faces[face], vertices);
    areaByColor[provisionalColors[face]] +=
        polygonArea(faces[face], vertices);
  }

  // Colors that coexist on one genuine junction may never be collapsed into
  // one final surface, even transitively through regular seams elsewhere.
  std::set<std::pair<int, int>> incompatibleColors;
  struct MergeCandidate {
    int first = -1;
    int second = -1;
    double interfaceLength = 0.0;
    double alignedInterfaceLength = 0.0;
  };
  struct OrientationConstraint {
    std::size_t first, second;
    unsigned char oppositeFlip;
  };
  std::map<std::pair<int, int>, MergeCandidate> candidateByColors;
  std::map<std::pair<int, int>, std::vector<OrientationConstraint>>
      interfacesByColors;
  FaceOrientation faceOrientation(faces.size());
  std::set<int> nonOrientableColors;
  const auto joinInitial = [&](const EdgeUse &first, const EdgeUse &second) {
    if(!faceOrientation.join(first.face, second.face,
                             first.direction == second.direction)) {
      ++statistics.orientationConflictEdgeCount;
      nonOrientableColors.insert(provisionalColors[first.face]);
    }
  };
  for(const auto &entry : usesByEdge) {
    const std::vector<EdgeUse> &incident = entry.second;
    std::map<int, std::vector<EdgeUse>> incidentByColor;
    const auto recordColorEdge = [&](std::size_t face, std::size_t count) {
      SurfaceTopology &topology = topologyByRoot.at(provisionalColors[face]);
      --topology.euler; // one edge in this color's cell complex
      if(count == 1)
        topology.boundary.emplace(entry.first, face);
      else if(count > 2)
        topology.regularCells = false;
      // A protected ordinary seam is a traversal cut without duplicated
      // vertices. Do not certify its uncut Euler counts as that cut surface.
      else if(incident.size() == 2 && protectedEdges.count(entry.first))
        topology.regularCells = false;
    };
    if(incident.size() == 1) recordColorEdge(incident[0].face, 1);
    else if(incident.size() == 2) {
      if(provisionalColors[incident[0].face] == provisionalColors[incident[1].face])
        recordColorEdge(incident[0].face, 2);
      else {
        recordColorEdge(incident[0].face, 1);
        recordColorEdge(incident[1].face, 1);
      }
    }
    else {
      for(const EdgeUse &use : incident)
        incidentByColor[provisionalColors[use.face]].push_back(use);
      for(const auto &colorFaces : incidentByColor)
        recordColorEdge(colorFaces.second.front().face, colorFaces.second.size());
    }
    if(incident.size() > 2 || protectedEdges.count(entry.first)) {
      std::set<int> edgeColors;
      for(const EdgeUse &use : incident)
        if(provisionalColors[use.face] >= 0)
          edgeColors.insert(provisionalColors[use.face]);
      for(auto first = edgeColors.begin(); first != edgeColors.end(); ++first) {
        for(auto second = std::next(first); second != edgeColors.end();
            ++second)
          incompatibleColors.insert({*first, *second});
      }
      // Match the final traversal: an unambiguous same-color host continues
      // through a T-junction. Distinct junction colors can never be merged,
      // so these host constraints remain unchanged by every admissible union.
      if(incident.size() > 2) {
        for(const auto &colorFaces : incidentByColor)
          if(colorFaces.second.size() == 2)
            joinInitial(colorFaces.second[0], colorFaces.second[1]);
      }
      continue;
    }
    if(incident.size() != 2) continue;
    int firstColor = provisionalColors[incident[0].face];
    int secondColor = provisionalColors[incident[1].face];
    if(firstColor < 0 || secondColor < 0) continue;
    if(firstColor == secondColor) {
      joinInitial(incident[0], incident[1]);
      continue;
    }
    if(firstColor > secondColor) std::swap(firstColor, secondColor);
    const Point a = point(vertices, entry.first.a);
    const Point b = point(vertices, entry.first.b);
    const double edgeLength = norm(subtract(b, a));
    const double alignment = std::abs(dot(
        faceNormals[incident[0].face], faceNormals[incident[1].face]));
    MergeCandidate &candidate =
        candidateByColors[{firstColor, secondColor}];
    candidate.first = firstColor;
    candidate.second = secondColor;
    candidate.interfaceLength += edgeLength;
    candidate.alignedInterfaceLength += edgeLength * alignment;
    interfacesByColors[{firstColor, secondColor}].push_back(
        {incident[0].face, incident[1].face,
         static_cast<unsigned char>(incident[0].direction == incident[1].direction)});
  }
  if(statistics.orientationConflictEdgeCount != 0 && !preserveNonOrientable)
    throw std::runtime_error(
        "Final filtered MAT contains a non-orientable surface component (" +
        std::to_string(statistics.orientationConflictEdgeCount) +
        " conflicting adjacency edges before surface merging)");

  for(std::size_t face = 0; face < faces.size(); ++face)
    if(provisionalColors[face] >= 0)
      topologyByRoot.at(provisionalColors[face]).components.insert(
          faceOrientation.representative(face));
  // Protect topology already certified on the input patches. Some legacy
  // inputs have touching boundary loops handled by later parameterization;
  // this guard does not change their existing junction/orientation policy or
  // claim to validate those complexes. The scope is inherited through unions.
  for(auto &entry : topologyByRoot)
    entry.second.preserveOpenGenusZero = !nonOrientableColors.count(entry.first) &&
        isOpenGenusZero(entry.second, faceOrientation);

  std::vector<MergeCandidate> candidates;
  candidates.reserve(candidateByColors.size());
  for(const auto &candidate : candidateByColors)
    candidates.push_back(candidate.second);
  auto meanAlignment = [](const MergeCandidate &candidate) {
    return candidate.interfaceLength > 0.0 ?
        candidate.alignedInterfaceLength / candidate.interfaceLength : 0.0;
  };
  auto relativeInterface = [&](const MergeCandidate &candidate) {
    const double smallerArea = std::min(
        areaByColor[candidate.first], areaByColor[candidate.second]);
    return smallerArea > 0.0 ?
        candidate.interfaceLength / std::sqrt(smallerArea) : 0.0;
  };
  std::sort(candidates.begin(), candidates.end(),
            [&](const MergeCandidate &first,
                const MergeCandidate &second) {
    const double firstAlignment = meanAlignment(first);
    const double secondAlignment = meanAlignment(second);
    if(firstAlignment != secondAlignment)
      return firstAlignment > secondAlignment;
    const double firstRelative = relativeInterface(first);
    const double secondRelative = relativeInterface(second);
    if(firstRelative != secondRelative) return firstRelative > secondRelative;
    if(first.interfaceLength != second.interfaceLength)
      return first.interfaceLength > second.interfaceLength;
    return std::pair<int, int>{first.first, first.second} <
           std::pair<int, int>{second.first, second.second};
  });
  statistics.candidateSurfaceMergeCount = candidates.size();

  std::map<int, int> parent;
  std::map<int, std::set<int>> members;
  for(int color : retainedColors) {
    parent[color] = color;
    members[color].insert(color);
  }
  auto findRoot = [&](int color) {
    int root = color;
    while(parent.at(root) != root) root = parent.at(root);
    while(parent.at(color) != color) {
      const int next = parent.at(color);
      parent[color] = root;
      color = next;
    }
    return root;
  };
  auto componentsAreCompatible = [&](int firstRoot, int secondRoot) {
    for(int first : members.at(firstRoot)) {
      for(int second : members.at(secondRoot)) {
        const std::pair<int, int> pair =
            first < second ? std::make_pair(first, second) :
                             std::make_pair(second, first);
        if(incompatibleColors.count(pair) != 0) return false;
      }
    }
    return true;
  };
  auto orientationsAreCompatible = [&](int firstRoot, int secondRoot) {
    // An accepted color union internalizes EVERY regular interface between
    // its two groups, including seams not belonging to this candidate pair.
    // Test them together; a late contradiction must undo the earlier joins.
    for(int first : members.at(firstRoot)) {
      for(int second : members.at(secondRoot)) {
        const auto interface = interfacesByColors.find(std::minmax(first, second));
        if(interface == interfacesByColors.end()) continue;
        for(const OrientationConstraint &constraint : interface->second) {
          if(!faceOrientation.join(constraint.first, constraint.second,
                                   constraint.oppositeFlip, true)) {
            faceOrientation.rollback();
            return false;
          }
        }
      }
    }
    return true;
  };
  const auto unionTopology = [&](int firstRoot, int secondRoot) {
    SurfaceTopology result = topologyByRoot.at(firstRoot);
    const SurfaceTopology &second = topologyByRoot.at(secondRoot);
    result.regularCells = result.regularCells && second.regularCells;
    result.preserveOpenGenusZero =
        result.preserveOpenGenusZero && second.preserveOpenGenusZero;
    result.euler += second.euler;
    result.components.insert(second.components.begin(), second.components.end());
    for(const auto &edge : second.boundary) {
      const auto inserted = result.boundary.insert(edge);
      if(!inserted.second) {
        result.boundary.erase(inserted.first);
        ++result.euler; // E(A union B) = E(A) + E(B) - E(A intersection B)
      }
    }
    std::set<int> sharedVertices;
    for(int firstColor : members.at(firstRoot)) {
      for(int secondColor : members.at(secondRoot)) {
        const auto found = sharedVerticesByColors.find(
            std::minmax(firstColor, secondColor));
        if(found != sharedVerticesByColors.end())
          sharedVertices.insert(found->second.begin(), found->second.end());
      }
    }
    // Deduplicate across all source-color pairs: a four-way contact contributes
    // one common vertex, even when it occurs in several pair lists.
    result.euler -= static_cast<std::int64_t>(sharedVertices.size());
    return result;
  };
  for(const MergeCandidate &candidate : candidates) {
    int firstRoot = findRoot(candidate.first);
    int secondRoot = findRoot(candidate.second);
    if(firstRoot == secondRoot) continue;
    // Do not propagate an input orientation defect through an otherwise
    // admissible union. These colors remain separate in review exports.
    if(nonOrientableColors.count(firstRoot) ||
       nonOrientableColors.count(secondRoot)) {
      ++statistics.blockedSurfaceMergeCount;
      ++statistics.orientationBlockedSurfaceMergeCount;
      continue;
    }
    if(!componentsAreCompatible(firstRoot, secondRoot)) {
      ++statistics.blockedSurfaceMergeCount;
      continue;
    }
    if(!orientationsAreCompatible(firstRoot, secondRoot)) {
      ++statistics.blockedSurfaceMergeCount;
      ++statistics.orientationBlockedSurfaceMergeCount;
      continue;
    }
    SurfaceTopology mergedTopology = unionTopology(firstRoot, secondRoot);
    if(mergedTopology.preserveOpenGenusZero &&
       !isOpenGenusZero(mergedTopology, faceOrientation)) {
      faceOrientation.rollback();
      ++statistics.blockedSurfaceMergeCount;
      ++statistics.topologyBlockedSurfaceMergeCount;
      continue;
    }
    faceOrientation.commit();
    std::set<std::size_t> mergedComponents;
    for(std::size_t face : mergedTopology.components)
      mergedComponents.insert(faceOrientation.representative(face));
    mergedTopology.components = std::move(mergedComponents);
    if(members[firstRoot].size() < members[secondRoot].size())
      std::swap(firstRoot, secondRoot);
    parent[secondRoot] = firstRoot;
    members[firstRoot].insert(members[secondRoot].begin(),
                              members[secondRoot].end());
    members.erase(secondRoot);
    topologyByRoot[firstRoot] = std::move(mergedTopology);
    topologyByRoot.erase(secondRoot);
    ++statistics.acceptedSurfaceMergeCount;
  }

  struct Neighbor {
    std::size_t face = 0;
    // One polygon must be reversed iff both polygons currently traverse the
    // shared edge in the same direction.
    unsigned char oppositeFlip = 0;
  };
  std::vector<std::vector<Neighbor>> adjacency(faces.size());
  auto connect = [&](const EdgeUse &first, const EdgeUse &second) {
    const unsigned char oppositeFlip = first.direction == second.direction;
    adjacency[first.face].push_back({second.face, oppositeFlip});
    adjacency[second.face].push_back({first.face, oppositeFlip});
  };
  for(const auto &entry : usesByEdge) {
    const std::vector<EdgeUse> &incident = entry.second;
    if(incident.size() == 1) {
      ++statistics.finalBoundaryEdgeCount;
      continue;
    }
    if(incident.size() == 2) {
      if(protectedEdges.count(entry.first)) {
        ++statistics.preservedBarrierEdgeCount;
        ++statistics.finalInterfaceEdgeCount;
        continue;
      }
      if(findRoot(provisionalColors[incident[0].face]) ==
         findRoot(provisionalColors[incident[1].face]))
        connect(incident[0], incident[1]);
      else
        ++statistics.finalInterfaceEdgeCount;
      continue;
    }

    ++statistics.finalTripleOrNonManifoldEdgeCount;
    std::map<int, std::vector<EdgeUse>> incidentByColor;
    for(const EdgeUse &use : incident)
      if(provisionalColors[use.face] >= 0)
        incidentByColor[findRoot(provisionalColors[use.face])].push_back(use);
    if(incidentByColor.size() > 1) ++statistics.finalInterfaceEdgeCount;
    for(const auto &colorFaces : incidentByColor) {
      // More than two uses from one provisional component are already an
      // ambiguous non-manifold junction; they are not evidence that the
      // surrounding sheets should be rejected.  Keep the edge as a BFS
      // barrier so that the final connected-component pass gives the sheets
      // independent surface tags.  Exactly two uses remain the unambiguous
      // continuing host of a T-junction.
      if(colorFaces.second.size() != 2) continue;
      connect(colorFaces.second[0], colorFaces.second[1]);
    }
  }

  // A junction barrier alone does not separate sheets that reconnect through
  // regular edges elsewhere. Detect exactly those inherited ambiguities. The
  // orientation DSU has the same connectivity as the adjacency graph above.
  // For each offending edge, its incident polygons must belong to separate
  // charts. Grow charts along the most continuous regular adjacencies, carrying
  // these constraints through every union so no alternate path can undo a cut.
  // This only repartitions affected components: no polygon or vertex is removed.
  std::map<std::size_t, std::map<std::size_t, std::size_t>> chartConstraints;
  std::set<std::size_t> affectedComponents;
  std::size_t constraint = 0;
  for(const auto &entry : usesByEdge) {
    if(entry.second.size() <= 2) continue;
    std::map<std::size_t, std::vector<std::size_t>> incidentByComponent;
    for(const auto &use : entry.second)
      incidentByComponent[faceOrientation.representative(use.face)].push_back(use.face);
    for(const auto &component : incidentByComponent) {
      if(component.second.size() <= 2) continue;
      affectedComponents.insert(component.first);
      for(std::size_t face : component.second)
        chartConstraints[face][constraint] = face;
      ++constraint;
    }
  }
  statistics.reconnectedJunctionCount = constraint;
  if(!affectedComponents.empty()) {
    std::vector<std::size_t> chartParent(faces.size());
    std::vector<std::size_t> chartSize(faces.size(), 1);
    for(std::size_t face = 0; face < faces.size(); ++face) chartParent[face] = face;
    auto chartRoot = [&](std::size_t face) {
      std::size_t root = face;
      while(chartParent[root] != root) root = chartParent[root];
      while(chartParent[face] != face) {
        const std::size_t next = chartParent[face];
        chartParent[face] = root;
        face = next;
      }
      return root;
    };
    struct ChartSeam {
      std::size_t first, second;
      double alignment;
    };
    std::vector<ChartSeam> seams;
    for(std::size_t face = 0; face < faces.size(); ++face) {
      if(colors[face] < 0 ||
         !affectedComponents.count(faceOrientation.representative(face))) continue;
      for(const auto &neighbor : adjacency[face])
        if(face < neighbor.face)
          seams.push_back({face, neighbor.face,
              std::abs(dot(faceNormals[face], faceNormals[neighbor.face]))});
    }
    std::sort(seams.begin(), seams.end(), [](const ChartSeam &a, const ChartSeam &b) {
      if(a.alignment != b.alignment) return a.alignment > b.alignment;
      return std::make_pair(a.first, a.second) < std::make_pair(b.first, b.second);
    });
    for(const auto &seam : seams) {
      std::size_t first = chartRoot(seam.first), second = chartRoot(seam.second);
      if(first == second) continue;
      const auto firstConstraints = chartConstraints.find(first);
      const auto secondConstraints = chartConstraints.find(second);
      bool compatible = true;
      if(firstConstraints != chartConstraints.end() &&
         secondConstraints != chartConstraints.end()) {
        const auto *small = &firstConstraints->second;
        const auto *large = &secondConstraints->second;
        if(small->size() > large->size()) std::swap(small, large);
        for(const auto &mark : *small) {
          const auto other = large->find(mark.first);
          if(other != large->end() && other->second != mark.second) {
            compatible = false;
            break;
          }
        }
      }
      if(!compatible) continue;
      if(chartSize[first] < chartSize[second]) std::swap(first, second);
      chartParent[second] = first;
      chartSize[first] += chartSize[second];
      const auto inherited = chartConstraints.find(second);
      if(inherited != chartConstraints.end()) {
        auto &destination = chartConstraints[first];
        destination.insert(inherited->second.begin(), inherited->second.end());
        chartConstraints.erase(inherited);
      }
    }
    for(const auto &seam : seams)
      if(chartRoot(seam.first) != chartRoot(seam.second))
        ++statistics.junctionChartCutCount;
    for(std::size_t face = 0; face < faces.size(); ++face) {
      if(colors[face] < 0 ||
         !affectedComponents.count(faceOrientation.representative(face))) continue;
      auto &neighbors = adjacency[face];
      neighbors.erase(std::remove_if(neighbors.begin(), neighbors.end(),
          [&](const Neighbor &neighbor) {
            return chartRoot(face) != chartRoot(neighbor.face);
          }), neighbors.end());
    }
  }

  struct FinalComponent {
    std::vector<std::size_t> faces;
    std::map<int, double> areaBySourceColor;
    double area = 0.0;
    int preferredColor = -1;
    bool orientationConflict = false;
  };
  // Count conflicts in the final traversal, without counting the initial
  // orientation diagnostic a second time in review mode.
  statistics.orientationConflictEdgeCount = 0;
  std::vector<FinalComponent> components;
  std::vector<signed char> orientation(faces.size(), -1);
  std::queue<std::size_t> pending;
  for(std::size_t seed = 0; seed < faces.size(); ++seed) {
    if(colors[seed] < 0 || orientation[seed] >= 0) continue;
    FinalComponent component;
    orientation[seed] = 0;
    pending.push(seed);
    while(!pending.empty()) {
      const std::size_t face = pending.front();
      pending.pop();
      component.faces.push_back(face);
      const double area = polygonArea(faces[face], vertices);
      component.area += area;
      component.areaBySourceColor[provisionalColors[face]] += area;
      for(const Neighbor &neighbor : adjacency[face]) {
        if(colors[neighbor.face] < 0) continue;
        const signed char required =
            orientation[face] ^ neighbor.oppositeFlip;
        if(orientation[neighbor.face] < 0) {
          orientation[neighbor.face] = required;
          pending.push(neighbor.face);
        }
        else if(orientation[neighbor.face] != required &&
                face < neighbor.face) {
          ++statistics.orientationConflictEdgeCount;
          component.orientationConflict = true;
        }
      }
    }
    for(const auto &source : component.areaBySourceColor) {
      if(component.preferredColor < 0 ||
         source.second >
             component.areaBySourceColor.at(component.preferredColor) ||
         (source.second ==
              component.areaBySourceColor.at(component.preferredColor) &&
          source.first < component.preferredColor))
        component.preferredColor = source.first;
    }
    components.push_back(std::move(component));
  }
  if(statistics.orientationConflictEdgeCount != 0 && !preserveNonOrientable) {
    throw std::runtime_error(
        "Final filtered MAT contains a non-orientable surface component (" +
        std::to_string(statistics.orientationConflictEdgeCount) +
        " conflicting adjacency edges)");
  }
  statistics.connectedComponentCount = components.size();

  // Each connected component has two equivalent global orientations. Keep
  // the one that reverses the smaller area, which preserves the dominant
  // inherited orientation while making the whole rebuilt surface coherent.
  for(const FinalComponent &component : components) {
    // A non-orientable component has no consistent global orientation. Keep
    // its inherited polygon orders instead of applying arbitrary BFS flips.
    if(component.orientationConflict) continue;
    double areaByOrientation[2] = {0.0, 0.0};
    for(std::size_t face : component.faces)
      areaByOrientation[orientation[face]] += polygonArea(faces[face], vertices);
    const unsigned char complement =
        areaByOrientation[1] > areaByOrientation[0] ? 1 : 0;
    for(std::size_t face : component.faces) {
      const unsigned char reverse = orientation[face] ^ complement;
      if(!reverse) continue;
      ++statistics.reorientedFaceCount;
      if(reversedFaces) (*reversedFaces)[face] = 1;
    }
  }

  std::vector<std::size_t> order(components.size());
  for(std::size_t index = 0; index < order.size(); ++index) order[index] = index;
  std::sort(order.begin(), order.end(), [&](std::size_t first,
                                            std::size_t second) {
    if(components[first].area != components[second].area)
      return components[first].area > components[second].area;
    return components[first].faces.front() < components[second].faces.front();
  });
  int nextColor = -1;
  for(int color : provisionalColors) nextColor = std::max(nextColor, color);
  std::set<int> usedColors;
  std::map<int, std::set<std::size_t>> componentsBySourceColor;
  for(std::size_t component = 0; component < components.size(); ++component)
    for(const auto &source : components[component].areaBySourceColor)
      componentsBySourceColor[source.first].insert(component);
  for(const auto &source : componentsBySourceColor)
    if(source.second.size() > 1) ++statistics.splitColorCount;

  for(std::size_t index : order) {
    FinalComponent &component = components[index];
    int outputColor = component.preferredColor;
    if(outputColor < 0 || !usedColors.insert(outputColor).second) {
      outputColor = ++nextColor;
      usedColors.insert(outputColor);
      ++statistics.addedComponentCount;
    }
    statistics.sourceColorByColor[outputColor] = component.preferredColor;
    for(std::size_t face : component.faces) {
      if(colors[face] != outputColor) ++statistics.recoloredFaceCount;
      colors[face] = outputColor;
    }
  }
  return statistics;
}

} // namespace matLargestConnectedComponent
