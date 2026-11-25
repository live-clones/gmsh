#pragma once

#include <cstddef>
#include <stdexcept>
#include <utility>
#include <vector>

namespace matgmsh {
namespace skinSites {

// The MAT sites are the nodes of the closed triangulated skin. A model can
// also hold nodes that no skin triangle uses, for instance on construction
// curves left without a face. Used as Delaunay sites they lie strictly inside
// or outside the part, and each one adds a closed Voronoi cell that is no part
// of the medial axis.
//
// Keeps the sites used by at least one triangle. The compaction is stable: the
// retained sites keep their order and their coordinates bit for bit, nothing is
// welded or moved. The triangles are renumbered. `entity` may be empty when
// the sites carry no model entity. Returns the node tags of the removed sites.
inline std::vector<std::size_t>
restrictToTriangles(std::vector<double> &xyz, std::vector<std::size_t> &nodeTags,
                    std::vector<std::pair<int, int> > &entity,
                    std::vector<std::vector<int> > &faces,
                    std::vector<std::size_t> &triangles)
{
  const std::size_t n = nodeTags.size();
  if(xyz.size() != 3 * n || faces.size() != n ||
     (!entity.empty() && entity.size() != n) || triangles.size() % 3)
    throw std::runtime_error("MAT sites: inconsistent skin arrays");

  std::vector<unsigned char> used(n, 0);
  for(const std::size_t v : triangles) {
    if(v >= n)
      throw std::runtime_error("MAT sites: a skin triangle uses an unknown node");
    used[v] = 1;
  }

  std::vector<std::size_t> removed, newIndex(n, n);
  std::size_t kept = 0;
  for(std::size_t old = 0; old < n; ++old) {
    if(!used[old]) {
      removed.push_back(nodeTags[old]);
      continue;
    }
    newIndex[old] = kept;
    if(kept != old) {
      nodeTags[kept] = nodeTags[old];
      if(!entity.empty()) entity[kept] = entity[old];
      faces[kept] = std::move(faces[old]);
      for(int k = 0; k < 3; ++k) xyz[3 * kept + k] = xyz[3 * old + k];
    }
    ++kept;
  }
  if(removed.empty()) return removed;

  nodeTags.resize(kept);
  if(!entity.empty()) entity.resize(kept);
  faces.resize(kept);
  xyz.resize(3 * kept);
  for(std::size_t &v : triangles) v = newIndex[v];
  return removed;
}

} // namespace skinSites
} // namespace matgmsh
