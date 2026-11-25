// Extracted from MatGmsh for the native Gmsh MAT pipeline.
// See SOURCE_PROVENANCE.txt for the extraction boundary.
#include "matGmsh.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stdexcept>
#include <unordered_map>
#include <unordered_set>
#include <vector>
namespace {
struct MatGmshEdgeHash {
  std::size_t operator()(const matGmshEdge &edge) const noexcept
  {
    const std::uint64_t packed =
        (static_cast<std::uint64_t>(static_cast<std::uint32_t>(edge.a))
         << 32) |
        static_cast<std::uint32_t>(edge.b);
    return std::hash<std::uint64_t>{}(packed);
  }
};
}
matGmsh::ScopedTimer::ScopedTimer(const matGmsh &ownerIn,
                                  const std::string &nameIn)
    : owner(ownerIn), name(nameIn), start(std::chrono::steady_clock::now())
{
}

matGmsh::ScopedTimer::~ScopedTimer()
{
  owner.addTimingSample(
      name,
      std::chrono::duration_cast<std::chrono::nanoseconds>(
          std::chrono::steady_clock::now() - start));
}

void matGmsh::addTimingSample(const std::string &name,
                              std::chrono::nanoseconds duration) const
{
  auto &entry = timings[name];
  entry.total += duration;
  entry.calls += 1;
}

std::vector<int> matGmsh::snapshotVoronoiFaceColors() const
{
  return vor.faceColors;
}

void matGmsh::restoreVoronoiFaceColors(const std::vector<int> &faceColors)
{
  if(faceColors.size() != vor.faceColors.size()) {
    throw std::runtime_error(
        "Cannot restore Voronoi face colors with a different size");
  }
  vor.faceColors = faceColors;
}

matLargestConnectedComponent::Statistics
matGmsh::rebuildConnectedComponentsPerColor(
    const std::vector<int> &unfilteredFaceColors,
    const std::map<int, int> &branchClasses)
{
  ScopedTimer timer(*this, "rebuildConnectedComponentsPerColor");
  if(unfilteredFaceColors.size() != vor.faces.size() ||
     vor.faceColors.size() != vor.faces.size()) {
    throw std::runtime_error(
        "Cannot rebuild retained MAT components with incompatible colors");
  }

  auto branchClass = [&](int branch) {
    const auto classification = branchClasses.find(branch);
    return classification == branchClasses.end() ? 3 :
                                                   classification->second;
  };

  std::vector<std::vector<int>> faces;
  faces.reserve(vor.faces.size());
  std::map<matGmshEdge, std::set<int>> rawBranchesByEdge;
  for(std::size_t face = 0; face < vor.faces.size(); ++face) {
    std::vector<int> vertices;
    vertices.reserve(vor.faces[face].verts.size());
    for(int vertex : vor.faces[face].verts)
      if(vertex >= 0) vertices.push_back(vertex);
    faces.push_back(vertices);

    if(unfilteredFaceColors[face] < 0 || vertices.size() < 2) continue;
    std::set<matGmshEdge> uniqueEdges;
    for(std::size_t local = 0; local < vertices.size(); ++local) {
      const int first = vertices[local];
      const int second = vertices[(local + 1) % vertices.size()];
      if(first >= 0 && second >= 0 && first != second)
        uniqueEdges.insert(matGmshEdge(first, second));
    }
    for(const matGmshEdge &edge : uniqueEdges) {
      rawBranchesByEdge[edge].insert(unfilteredFaceColors[face]);
    }
  }

  // First discard disconnected MAT islands globally. Surface and triple-line
  // interfaces are crossed here: they belong to one MAT mesh even though they
  // will delimit separate surface branches in the second BFS below.
  const matLargestConnectedComponent::MeshStatistics meshStatistics =
      matLargestConnectedComponent::retainLargestMesh(
          faces, vor.vertices, vor.faceColors);

  std::map<matGmshEdge, std::set<int>> retainedBranchesByEdge;
  for(std::size_t face = 0; face < faces.size(); ++face) {
    if(vor.faceColors[face] < 0 || unfilteredFaceColors[face] < 0) continue;
    std::set<matGmshEdge> uniqueEdges;
    for(std::size_t local = 0; local < faces[face].size(); ++local) {
      const int first = faces[face][local];
      const int second = faces[face][(local + 1) % faces[face].size()];
      if(first >= 0 && second >= 0 && first != second)
        uniqueEdges.insert(matGmshEdge(first, second));
    }
    for(const matGmshEdge &edge : uniqueEdges)
      retainedBranchesByEdge[edge].insert(unfilteredFaceColors[face]);
  }

  std::set<matGmshEdge> protectedEdges;
  std::size_t finalTripleEdges = 0;
  std::size_t acceptedPlusTwoWingedEdges = 0;
  for(const auto &entry : rawBranchesByEdge) {
    const auto retained = retainedBranchesByEdge.find(entry.first);
    const std::set<int> empty;
    const std::set<int> &retainedBranches =
        retained == retainedBranchesByEdge.end() ? empty : retained->second;
    if(retainedBranches.size() >= 3) {
      protectedEdges.insert(entry.first);
      ++finalTripleEdges;
      continue;
    }

    // A raw triple with one locally retained accepted sheet and two locally
    // removed non-spurious sheets is the accepted+2-winged line requested by
    // the v2 post-filter. Preserve it even if two polygons of the accepted
    // sheet happen to make its final edge valence equal to two.
    if(entry.second.size() != 3 || retainedBranches.size() != 1) continue;
    const int retainedBranch = *retainedBranches.begin();
    if(branchClass(retainedBranch) != 1) continue;
    bool twoWinged = true;
    int removedBranches = 0;
    for(int branch : entry.second) {
      if(retainedBranches.count(branch) != 0) continue;
      ++removedBranches;
      if(branchClass(branch) == 3) twoWinged = false;
    }
    if(twoWinged && removedBranches == 2) {
      protectedEdges.insert(entry.first);
      ++acceptedPlusTwoWingedEdges;
    }
  }

  matLargestConnectedComponent::Statistics statistics =
      matLargestConnectedComponent::splitDisconnectedColors(
          faces, vor.vertices, protectedEdges, vor.faceColors);
  // Splitting branch colors does not remove faces, but apply the global audit
  // once more to keep this method's final-state invariant explicit.
  const matLargestConnectedComponent::MeshStatistics finalMeshStatistics =
      matLargestConnectedComponent::retainLargestMesh(
          faces, vor.vertices, vor.faceColors);
  std::cout << "Post-filter MAT connected components: colors="
            << statistics.retainedColorCount
            << " initialGlobalMeshes="
            << meshStatistics.connectedComponentCount
            << " removedInitialGlobalMeshes="
            << meshStatistics.removedComponentCount
            << " removedInitialGlobalFaces="
            << meshStatistics.removedFaceCount
            << " components=" << statistics.connectedComponentCount
            << " splitColors=" << statistics.splitColorCount
            << " addedComponents=" << statistics.addedComponentCount
            << " recoloredFaces=" << statistics.recoloredFaceCount
            << " finalGlobalMeshes="
            << finalMeshStatistics.connectedComponentCount
            << " removedFinalGlobalMeshes="
            << finalMeshStatistics.removedComponentCount
            << " removedFinalGlobalFaces="
            << finalMeshStatistics.removedFaceCount
            << " removedFinalGlobalArea="
            << finalMeshStatistics.removedArea
            << " finalTripleBarriers=" << finalTripleEdges
            << " acceptedPlusTwoWingedBarriers="
            << acceptedPlusTwoWingedEdges
            << " finalBoundaryEdges="
            << statistics.finalBoundaryEdgeCount << '\n';
  return statistics;
}

matLargestConnectedComponent::Statistics
matGmsh::rebuildFinalSurfaceTopology(bool preserveNonOrientable)
{
  ScopedTimer timer(*this, "rebuildFinalSurfaceTopology");
  std::vector<std::vector<int>> faces;
  faces.reserve(vor.faces.size());
  for(const VoronoiFace &face : vor.faces) {
    std::vector<int> vertices;
    vertices.reserve(face.verts.size());
    for(int vertex : face.verts)
      if(vertex >= 0) vertices.push_back(vertex);
    faces.push_back(std::move(vertices));
  }
  std::vector<unsigned char> reversedFaces;
  matLargestConnectedComponent::Statistics statistics =
      matLargestConnectedComponent::rebuildFinalSurfaceComponents(
          faces, vor.vertices, vor.faceColors, &reversedFaces,
          preservedFilteredTopologyEdges, preserveNonOrientable);
  for(std::size_t face = 0; face < reversedFaces.size(); ++face)
    if(reversedFaces[face])
      std::reverse(vor.faces[face].verts.begin(), vor.faces[face].verts.end());
  std::cout << "Final filtered MAT surface topology: inputColors="
            << statistics.retainedColorCount
            << " surfaces=" << statistics.connectedComponentCount
            << " mergedOrRecoloredFaces=" << statistics.recoloredFaceCount
            << " splitSourceColors=" << statistics.splitColorCount
            << " addedComponents=" << statistics.addedComponentCount
            << " boundaryEdges=" << statistics.finalBoundaryEdgeCount
            << " junctionEdges="
            << statistics.finalTripleOrNonManifoldEdgeCount
            << " reorientedFaces=" << statistics.reorientedFaceCount
            << " orientationConflicts="
            << statistics.orientationConflictEdgeCount
            << " preservedFeatureEdges=" << statistics.preservedBarrierEdgeCount
            << " mergeCandidates="
            << statistics.candidateSurfaceMergeCount
            << " acceptedMerges="
            << statistics.acceptedSurfaceMergeCount
            << " blockedMerges="
            << statistics.blockedSurfaceMergeCount
            << " orientationBlockedMerges="
            << statistics.orientationBlockedSurfaceMergeCount
            << " topologyBlockedMerges="
            << statistics.topologyBlockedSurfaceMergeCount
            << " reconnectedJunctions=" << statistics.reconnectedJunctionCount
            << " junctionChartCuts=" << statistics.junctionChartCutCount << '\n';
  return statistics;
}

std::size_t matGmsh::discardClosedRetainedSurfaces()
{
  struct ColoredEdge {
    int color = -1;
    matGmshEdge edge{0, 0};

    bool operator==(const ColoredEdge &other) const
    {
      return color == other.color && edge == other.edge;
    }
  };
  struct ColoredEdgeHash {
    std::size_t operator()(const ColoredEdge &value) const noexcept
    {
      std::size_t hash = std::hash<int>{}(value.color);
      hash ^= MatGmshEdgeHash{}(value.edge) + 0x9e3779b97f4a7c15ULL +
              (hash << 6) + (hash >> 2);
      return hash;
    }
  };

  std::unordered_map<ColoredEdge, unsigned char, ColoredEdgeHash> edgeUses;
  edgeUses.reserve(2 * vor.faces.size());
  std::unordered_map<int, std::size_t> faceCount;
  std::unordered_map<int, std::size_t> triangleCount;
  for(std::size_t faceIndex = 0; faceIndex < vor.faces.size(); ++faceIndex) {
    if(faceIndex >= vor.faceColors.size()) break;
    const int color = vor.faceColors[faceIndex];
    if(color < 0) continue;
    std::vector<int> vertices;
    for(const int vertex : vor.faces[faceIndex].verts)
      if(vertex >= 0) vertices.push_back(vertex);
    if(vertices.size() < 3) continue;
    ++faceCount[color];
    triangleCount[color] += vertices.size() - 2;
    for(std::size_t local = 0; local < vertices.size(); ++local) {
      const int first = vertices[local];
      const int second = vertices[(local + 1) % vertices.size()];
      if(first == second) continue;
      unsigned char &count =
          edgeUses[ColoredEdge{color, matGmshEdge(first, second)}];
      if(count < std::numeric_limits<unsigned char>::max()) ++count;
    }
  }

  std::unordered_set<int> colorsWithBoundary;
  for(const auto &edge : edgeUses)
    if(edge.second == 1) colorsWithBoundary.insert(edge.first.color);

  std::unordered_set<int> closedColors;
  std::size_t discardedFaces = 0;
  std::size_t discardedTriangles = 0;
  for(const auto &surface : faceCount) {
    if(colorsWithBoundary.count(surface.first) != 0) continue;
    closedColors.insert(surface.first);
    discardedFaces += surface.second;
    discardedTriangles += triangleCount[surface.first];
  }
  if(closedColors.empty()) return 0;

  for(std::size_t faceIndex = 0; faceIndex < vor.faceColors.size();
      ++faceIndex)
    if(closedColors.count(vor.faceColors[faceIndex]) != 0)
      vor.faceColors[faceIndex] = -1;

  std::cout << "Discarded closed retained MAT surfaces: surfaces="
            << closedColors.size() << " faces=" << discardedFaces
            << " triangles=" << discardedTriangles << " colors=";
  bool first = true;
  for(const int color : closedColors) {
    if(!first) std::cout << ',';
    first = false;
    std::cout << color;
  }
  std::cout << '\n';
  return closedColors.size();
}
void matGmsh::rebuildFilteredTopology(bool preserveExistingBranches)
{
  ScopedTimer timer(*this, "rebuildFilteredTopology");
  preservedFilteredTopologyEdges.clear();
  const std::vector<int> existingColors = vor.faceColors;

  // A retained polygonal Voronoi face is one MAT cell. Its polygon edges are
  // the edges of the triangulated MAT as well: the fan edges introduced by
  // createTriangulatedModel() always have valence two and are irrelevant here.
  std::map<matGmshEdge, std::vector<int>> edgeToFaces;
  for(std::size_t f = 0; f < vor.faces.size(); ++f) {
    if(f >= vor.faceColors.size() || vor.faceColors[f] < 0) {
      continue;
    }
    const std::vector<int> &vertices = vor.faces[f].verts;
    for(std::size_t i = 0; i < vertices.size(); ++i) {
      const int a = vertices[i];
      const int b = vertices[(i + 1) % vertices.size()];
      if(a >= 0 && b >= 0 && a != b) {
        edgeToFaces[matGmshEdge(a, b)].push_back(static_cast<int>(f));
      }
    }
  }


  // In CAD-patch mode, turn every interface between two propagated support
  // colors into an explicit topology edge. From this point on the ordinary
  // topology BFS can be used unchanged: crossing to another color is
  // geometrically impossible because the common edge is now a barrier.
  if(preserveExistingBranches) {
    for(const auto &entry : edgeToFaces) {
      if(entry.second.size() != 2) continue;
      const int faceA = entry.second[0];
      const int faceB = entry.second[1];
      if(existingColors[faceA] >= 0 && existingColors[faceB] >= 0 &&
         existingColors[faceA] != existingColors[faceB]) {
        preservedFilteredTopologyEdges.insert(entry.first);
      }
    }
  }

  // Cross only regular (valence-two) edges. Edges of valence one or greater
  // than two are topology curves and delimit the new surface branches.
  std::vector<int> rebuiltColors(vor.faces.size(), -1);
  int nextBranch = 0;
  std::queue<int> pending;
  for(std::size_t seed = 0; seed < vor.faces.size(); ++seed) {
    if(vor.faceColors[seed] < 0 || rebuiltColors[seed] >= 0) {
      continue;
    }
    rebuiltColors[seed] = nextBranch;
    pending.push(static_cast<int>(seed));
    while(!pending.empty()) {
      const int faceIndex = pending.front();
      pending.pop();
      const std::vector<int> &vertices = vor.faces[faceIndex].verts;
      for(std::size_t i = 0; i < vertices.size(); ++i) {
        const int a = vertices[i];
        const int b = vertices[(i + 1) % vertices.size()];
        if(a < 0 || b < 0 || a == b) {
          continue;
        }
        const auto edgeIt = edgeToFaces.find(matGmshEdge(a, b));
        if(edgeIt == edgeToFaces.end() || edgeIt->second.size() != 2 ||
           preservedFilteredTopologyEdges.count(matGmshEdge(a, b)) != 0) {
          continue;
        }
        for(int neighbor : edgeIt->second) {
          if(rebuiltColors[neighbor] < 0) {
            rebuiltColors[neighbor] = nextBranch;
            pending.push(neighbor);
          }
        }
      }
    }
    ++nextBranch;
  }


  vor.faceColors = std::move(rebuiltColors);
}

