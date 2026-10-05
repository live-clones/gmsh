// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// Constraints of the pdel3d mesh: locating the surface triangles and the
// curve lines among the facets and edges of the tets, flagging them, and
// coloring the tets by volume

#include <algorithm>
#include <map>
#include <set>
#include "pdel3d.h"
#include "GmshMessage.h"
#include "Context.h"

namespace pdel3d {

  namespace {

    inline void sort3(vIdx &a, vIdx &b, vIdx &c)
    {
      if(a > b) std::swap(a, b);
      if(b > c) std::swap(b, c);
      if(a > b) std::swap(a, b);
    }

    inline std::uint64_t hash3(vIdx a, vIdx b, vIdx c)
    {
      std::uint64_t h = a * 0x9e3779b97f4a7c15ull;
      h ^= (h >> 29) + b * 0xbf58476d1ce4e5b9ull;
      h ^= (h >> 31) + c * 0x94d049bb133111ebull;
      return h ^ (h >> 33);
    }

    // open addressing table of the (sorted) triangles
    struct TriangleTable {
      std::size_t mask;
      std::vector<std::uint32_t> slot; // triangle index + 1, 0 when empty
      const std::vector<vIdx> &tri; // sorted nodes

      TriangleTable(const std::vector<vIdx> &sortedTri) : tri(sortedTri)
      {
        const std::size_t n = tri.size() / 3;
        std::size_t size = 16;
        while(size < 2 * n) size <<= 1;
        mask = size - 1;
        slot.assign(size, 0);
        for(std::size_t i = 0; i < n; i++) {
          std::size_t h =
            hash3(tri[3 * i], tri[3 * i + 1], tri[3 * i + 2]) & mask;
          while(slot[h]) h = (h + 1) & mask;
          slot[h] = (std::uint32_t)(i + 1);
        }
      }
      // index of the triangle (a, b, c) sorted, or -1
      std::int64_t find(vIdx a, vIdx b, vIdx c) const
      {
        std::size_t h = hash3(a, b, c) & mask;
        while(slot[h]) {
          const std::size_t i = slot[h] - 1;
          if(tri[3 * i] == a && tri[3 * i + 1] == b && tri[3 * i + 2] == c)
            return (std::int64_t)i;
          h = (h + 1) & mask;
        }
        return -1;
      }
    };

  } // namespace

  std::size_t triangleToTetMap(const Mesh &m, const std::vector<vIdx> &triNode,
                               std::vector<tRef> &tri2tet)
  {
    const std::size_t ntri = triNode.size() / 3;
    tri2tet.assign(ntri, NO_ADJ);
    if(!ntri) return 0;
    std::vector<vIdx> sorted(triNode);
    for(std::size_t i = 0; i < ntri; i++)
      sort3(sorted[3 * i], sorted[3 * i + 1], sorted[3 * i + 2]);
    TriangleTable table(sorted);
    // every interior facet is seen from its two tets: only the one with the
    // smaller index writes, so that the entries are written once
    const int nthreads = CTX::instance()->numThreadsFor(m.ntet, 1 << 16);
#pragma omp parallel for schedule(static) num_threads(nthreads)
    for(std::size_t t = 0; t < m.ntet; t++) {
      if(m.isDeleted((tIdx)t) || m.isGhost((tIdx)t)) continue;
      const vIdx *n = &m.node[4 * t];
      for(unsigned f = 0; f < 4; f++) {
        const tRef r = m.neigh[4 * t + f];
        if(r != NO_ADJ && (r >> 2) < t && !m.isGhost(r >> 2)) continue;
        vIdx a = n[facetNode0(f)], b = n[facetNode1(f)], c = n[facetNode2(f)];
        sort3(a, b, c);
        const std::int64_t i = table.find(a, b, c);
        if(i >= 0) tri2tet[i] = (tRef)(4 * t + f);
      }
    }
    std::size_t missing = 0;
    for(auto r : tri2tet)
      if(r == NO_ADJ) missing++;
    return missing;
  }

  void linesInTriangles(const std::vector<vIdx> &triNode,
                        const std::vector<vIdx> &lineNode,
                        std::vector<std::uint8_t> &inTriangle)
  {
    const std::size_t nl = lineNode.size() / 2;
    inTriangle.assign(nl, 0);
    if(!nl || triNode.empty()) return;
    std::vector<std::uint64_t> edges;
    edges.reserve(triNode.size());
    for(std::size_t i = 0; i < triNode.size() / 3; i++) {
      for(int j = 0; j < 3; j++) {
        vIdx a = triNode[3 * i + j], b = triNode[3 * i + (j + 1) % 3];
        if(a > b) std::swap(a, b);
        edges.push_back(((std::uint64_t)a << 32) | b);
      }
    }
    std::sort(edges.begin(), edges.end());
    for(std::size_t i = 0; i < nl; i++) {
      vIdx a = lineNode[2 * i], b = lineNode[2 * i + 1];
      if(a > b) std::swap(a, b);
      inTriangle[i] = std::binary_search(edges.begin(), edges.end(),
                                         ((std::uint64_t)a << 32) | b) ?
                        1 :
                        0;
    }
  }

  std::size_t lineToTetMap(const Mesh &m, const std::vector<vIdx> &lineNode,
                           const std::vector<std::uint8_t> &skip,
                           std::vector<std::uint64_t> &line2tet)
  {
    const std::size_t nl = lineNode.size() / 2;
    line2tet.assign(nl, NO_ADJ);
    std::size_t todo = 0;
    for(std::size_t i = 0; i < nl; i++)
      if(!skip[i]) todo++;
    if(!todo) return 0;
    // one tet per vertex, then a search of the star of the first node
    std::vector<tIdx> tetOf(m.numVertices(), NO_TET);
    for(std::size_t t = 0; t < m.ntet; t++) {
      if(m.isDeleted((tIdx)t) || m.isGhost((tIdx)t)) continue;
      for(int k = 0; k < 4; k++) tetOf[m.node[4 * t + k]] = (tIdx)t;
    }
    std::size_t missing = 0;
    std::vector<tIdx> star;
    for(std::size_t i = 0; i < nl; i++) {
      if(skip[i]) continue;
      const vIdx a = lineNode[2 * i], b = lineNode[2 * i + 1];
      if(a == b) continue; // degenerate line
      if(tetOf[a] == NO_TET) {
        missing++;
        continue;
      }
      star.clear();
      star.push_back(tetOf[a]);
      bool found = false;
      for(std::size_t s = 0; s < star.size() && !found; s++) {
        const tIdx t = star[s];
        const vIdx *n = &m.node[4 * t];
        int ia = -1, ib = -1;
        for(int k = 0; k < 4; k++) {
          if(n[k] == a) ia = k;
          if(n[k] == b) ib = k;
        }
        if(ib >= 0) {
          line2tet[i] = 6 * (std::uint64_t)t + (5 - edgeFromFacets(ia, ib));
          found = true;
          break;
        }
        // the neighbors through the facets containing a
        for(unsigned f = 0; f < 4; f++) {
          if((int)f == ia) continue;
          const tIdx nb = m.neigh[4 * t + f] >> 2;
          if(m.isGhost(nb)) continue;
          if(std::find(star.begin(), star.end(), nb) == star.end())
            star.push_back(nb);
        }
      }
      if(!found) missing++;
    }
    return missing;
  }

  void constrainFacets(Mesh &m, const std::vector<tRef> &tri2tet)
  {
    for(auto r : tri2tet) {
      if(r == NO_ADJ) continue;
      m.flag[r >> 2] |= F_FACET0 << (r & 3);
      const tRef s = m.neigh[r];
      if(s != NO_ADJ) m.flag[s >> 2] |= F_FACET0 << (s & 3);
    }
  }

  void constrainEdges(Mesh &m, const std::vector<std::uint64_t> &line2tet)
  {
    for(auto e : line2tet) {
      if(e == NO_ADJ) continue;
      const tIdx t0 = (tIdx)(e / 6);
      unsigned inF, outF;
      edgeFacets((int)(e % 6), inF, outF);
      tIdx cur = t0;
      // turn around the edge
      do {
        m.flag[cur] |= 1 << edgeFromFacets(inF, outF);
        const vIdx newV = m.node[4 * cur + inF];
        const tRef r = m.neigh[4 * cur + outF];
        cur = r >> 2;
        inF = r & 3;
        const vIdx *nodes = &m.node[4 * cur];
        for(outF = 0; outF < 3; outF++)
          if(nodes[outF] == newV) break;
      } while(cur != t0);
    }
  }

  bool colorVolumes(Mesh &m, const std::vector<tRef> &tri2tet,
                    const std::vector<std::uint32_t> &triColor,
                    const std::vector<std::vector<std::uint32_t>> &volumes)
  {
    // flood fill bounded by the constrained facets
    if(m.color.size() < m.tetCapacity()) m.color.resize(m.tetCapacity());
    std::fill(m.color.begin(), m.color.begin() + m.ntet, 0);
    std::vector<tIdx> stack;
    std::uint32_t color = 1, colorOut = 0;
    for(std::size_t first = 0; first < m.ntet; first++) {
      if(m.isDeleted((tIdx)first) || m.color[first]) continue;
      stack.clear();
      stack.push_back((tIdx)first);
      m.color[first] = color;
      for(std::size_t i = 0; i < stack.size(); i++) {
        const tIdx t = stack[i];
        if(m.isGhost(t)) colorOut = color;
        for(unsigned f = 0; f < 4; f++) {
          const tRef r = m.neigh[4 * t + f];
          if(r == NO_ADJ || (m.flag[t] & (F_FACET0 << f))) continue;
          const tIdx nb = r >> 2;
          if(!m.color[nb]) {
            m.color[nb] = color;
            stack.push_back(nb);
          }
        }
      }
      color++;
    }
    const std::uint32_t numComponents = color - 1;
    Msg::Debug("%u connected components of tets bounded by constrained facets",
               numComponents);
    // the surface colors seen by each component
    std::vector<std::set<std::uint32_t>> surfaces(numComponents + 1);
    for(std::size_t i = 0; i < tri2tet.size(); i++) {
      const tRef r = tri2tet[i];
      if(r == NO_ADJ) continue;
      surfaces[m.color[r >> 2]].insert(triColor[i]);
      const tRef s = m.neigh[r];
      if(s != NO_ADJ) surfaces[m.color[s >> 2]].insert(triColor[i]);
    }
    // match the components to the volumes
    std::map<std::set<std::uint32_t>, std::uint32_t> volumeOfSurfaces;
    for(std::size_t i = 0; i < volumes.size(); i++) {
      std::set<std::uint32_t> s(volumes[i].begin(), volumes[i].end());
      if(volumeOfSurfaces.count(s)) {
        Msg::Error("Volumes %lu and %u are bounded by the same surfaces", i,
                   volumeOfSurfaces[s]);
        return false;
      }
      volumeOfSurfaces[s] = (std::uint32_t)i;
    }
    std::vector<std::uint32_t> map(numComponents + 1, Mesh::COLOR_OUT);
    std::vector<bool> found(volumes.size(), false);
    std::uint32_t next = (std::uint32_t)volumes.size();
    for(std::uint32_t c = 1; c <= numComponents; c++) {
      if(c == colorOut) continue;
      auto it = volumeOfSurfaces.find(surfaces[c]);
      if(it != volumeOfSurfaces.end() && !found[it->second]) {
        map[c] = it->second;
        found[it->second] = true;
      }
      else
        map[c] = next++;
    }
    for(std::size_t t = 0; t < m.ntet; t++)
      if(!m.isDeleted((tIdx)t)) m.color[t] = map[m.color[t]];
    bool ok = true;
    for(std::size_t i = 0; i < volumes.size(); i++) {
      if(!found[i]) {
        Msg::Error("Volume %lu was not found in the tetrahedralization (its "
                   "bounding surfaces "
                   "do not enclose a single connected component)",
                   i);
        ok = false;
      }
    }
    if(next > volumes.size())
      Msg::Info("%u enclosed volume(s) not in the model will not be refined",
                next - (std::uint32_t)volumes.size());
    return ok;
  }

} // namespace pdel3d
