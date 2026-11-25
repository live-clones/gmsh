#pragma once

#include "matGmshEdge.h"

#include <cstddef>
#include <map>
#include <set>
#include <vector>

namespace matLargestConnectedComponent {

struct Statistics {
  std::size_t retainedColorCount = 0;
  std::size_t connectedComponentCount = 0;
  std::size_t splitColorCount = 0;
  std::size_t addedComponentCount = 0;
  std::size_t recoloredFaceCount = 0;
  std::size_t finalBoundaryEdgeCount = 0;
  std::size_t finalTripleOrNonManifoldEdgeCount = 0;
  std::size_t finalInterfaceEdgeCount = 0;
  std::size_t preservedBarrierEdgeCount = 0;
  std::size_t reorientedFaceCount = 0;
  std::size_t orientationConflictEdgeCount = 0;
  std::size_t candidateSurfaceMergeCount = 0;
  std::size_t acceptedSurfaceMergeCount = 0;
  std::size_t blockedSurfaceMergeCount = 0;
  std::size_t orientationBlockedSurfaceMergeCount = 0;
  std::size_t topologyBlockedSurfaceMergeCount = 0;
  std::size_t reconnectedJunctionCount = 0;
  std::size_t junctionChartCutCount = 0;
  std::map<int, int> sourceColorByColor;
};

struct MeshStatistics {
  std::size_t connectedComponentCount = 0;
  std::size_t removedComponentCount = 0;
  std::size_t removedFaceCount = 0;
  double removedArea = 0.0;
};

// Finds connected components of the complete retained MAT, crossing surface
// and triple-line interfaces whenever faces share an edge. If several
// disconnected MAT meshes exist, only the largest-area mesh is retained.
MeshStatistics retainLargestMesh(
    const std::vector<std::vector<int>> &faces,
    const std::vector<double> &vertices,
    std::vector<int> &colors);

// Rebuild the connected components of every retained color on the final MAT.
// A face-to-face traversal is allowed across an unprotected regular pair
// carrying the same color. This includes the two host uses at a T-junction,
// where another surface terminates on an embedded curve. Final MAT rims,
// protected final triple lines and protected inherited triple lines remain
// barriers.
// If a color owns several disconnected meshes, the largest-area component
// keeps the original color and every other component receives a new color.
// No face is removed by this branch-level operation.
Statistics splitDisconnectedColors(
    const std::vector<std::vector<int>> &faces,
    const std::vector<double> &vertices,
    const std::set<matGmshEdge> &protectedEdges,
    std::vector<int> &colors);

// Rebuild the surface partition of the already filtered MAT from its final
// topology. Every regular valence-two seam between provisional colors is a
// merge candidate. Two colors that coexist at a triple/non-manifold edge are
// strictly incompatible, preventing a transitive merge from creating a
// non-manifold surface. Compatible candidates are processed by decreasing
// normal continuity and relative interface length; there is no face-count or
// geometric threshold. A union is also rejected if its newly internal seams
// would form a non-orientable surface. For groups made entirely of input patches
// certified as open genus-zero manifolds, unions cannot create handles, close
// components, or leave non-manifold vertices. The certificate counts components,
// vertices, edges and boundary cycles: genus-zero surfaces with any number of
// holes remain admissible, even with negative Euler characteristic. Failed
// unions keep their interfaces; existing patches and all polygons are preserved.
// Preexisting uncertified patches (e.g. touching boundary loops) retain the old
// junction/orientation merge policy; this guard does not validate their topology.
// At a T-junction, two uses carrying the same
// provisional color are paired as the continuing host surface while the other
// surface terminates on an embedded curve. Existing colors are used only to
// choose stable output tags for the new connected components. The signed
// face-adjacency graph is solved at the same time: reversedFaces marks
// polygons whose order must be reversed to give every rebuilt surface a
// consistent orientation. Protected feature edges prevent direct and transitive
// color merges. If more than two sheets of one component meet at an edge and
// reconnect elsewhere, constrained chart unions cut the alternate paths,
// preferring normal continuity and retaining every polygon and shared vertex.
// Unaffected components keep their original partition. Protected feature edges
// remain traversal barriers. A non-orientable component is rejected instead of
// being silently emitted. In explicit review mode, preexisting non-orientable
// colors cannot merge with other colors; conflicted components retain their
// polygon order and are counted in orientationConflictEdgeCount.
Statistics rebuildFinalSurfaceComponents(
    const std::vector<std::vector<int>> &faces,
    const std::vector<double> &vertices,
    std::vector<int> &colors,
    std::vector<unsigned char> *reversedFaces = nullptr,
    const std::set<matGmshEdge> &protectedEdges = {},
    bool preserveNonOrientable = false);

} // namespace matLargestConnectedComponent
