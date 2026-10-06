// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.

#pragma once

#include <algorithm>
#include <array>
#include <cstdint>
#include <unordered_map>
#include <vector>

namespace QuadOpt {

  // Oriented triangle/quad complex on integer vertex ids. The only stored
  // connectivity is the map from directed edge (a,b) to the cell that owns it:
  // the twin of (a,b) is (b,a), and "next" is the following corner of the cell.
  // Vertex stars are kept for cavity queries. Cells are never renumbered.
  struct HalfEdgeMesh {
    struct Cell {
      int n = 0;
      std::array<int, 4> v = {{-1, -1, -1, -1}};
      bool alive = false;
    };
    std::vector<Cell> cells;
    std::vector<std::vector<int> > star;
    std::unordered_map<std::uint64_t, int> owner;

    static std::uint64_t key(int a, int b)
    {
      return (std::uint64_t(std::uint32_t(a)) << 32) | std::uint32_t(b);
    }
    int addVertex()
    {
      star.emplace_back();
      return int(star.size()) - 1;
    }
    int next(const Cell &c, int i) const { return c.v[(i + 1) % c.n]; }
    int prev(const Cell &c, int i) const { return c.v[(i + c.n - 1) % c.n]; }

    // Cell owning the directed edge (a,b), or -1.
    int cellAt(int a, int b) const
    {
      auto it = owner.find(key(a, b));
      return it == owner.end() ? -1 : it->second;
    }
    // Cell across edge i of cell c, or -1 on the boundary.
    int across(int c, int i) const
    {
      return cellAt(next(cells[c], i), cells[c].v[i]);
    }

    // Returns the new cell id, or -1 if a directed edge is already owned.
    int add(const Cell &cell)
    {
      for(int i = 0; i < cell.n; ++i)
        if(owner.count(key(cell.v[i], cell.v[(i + 1) % cell.n]))) return -1;
      const int id = int(cells.size());
      cells.push_back(cell);
      cells.back().alive = true;
      for(int i = 0; i < cell.n; ++i) {
        owner[key(cell.v[i], cell.v[(i + 1) % cell.n])] = id;
        star[cell.v[i]].push_back(id);
      }
      return id;
    }
    void remove(int id)
    {
      Cell &c = cells[id];
      for(int i = 0; i < c.n; ++i) {
        owner.erase(key(c.v[i], c.v[(i + 1) % c.n]));
        auto &s = star[c.v[i]];
        s.erase(std::find(s.begin(), s.end(), id));
      }
      c.alive = false;
    }

    // Oriented boundary of a set of cells as one simple closed vertex loop
    // (the cells keep the domain on their left). False if it is not a disk.
    bool loop(const std::vector<int> &set, std::vector<int> &poly) const
    {
      auto inSet = [&](int c) {
        return c >= 0 && std::find(set.begin(), set.end(), c) != set.end();
      };
      std::unordered_map<int, int> nextOf;
      for(int id : set)
        for(int i = 0; i < cells[id].n; ++i) {
          const int a = cells[id].v[i], b = next(cells[id], i);
          if(inSet(cellAt(b, a))) continue;
          if(!nextOf.emplace(a, b).second) return false;
        }
      if(nextOf.empty()) return false;
      poly.clear();
      const int first = nextOf.begin()->first;
      for(int a = first;;) {
        poly.push_back(a);
        auto it = nextOf.find(a);
        if(it == nextOf.end()) return false;
        a = it->second;
        if(a == first) break;
        if(poly.size() > nextOf.size()) return false;
      }
      return poly.size() == nextOf.size();
    }

    // Replace cells by new ones. Rolls back and returns false if the new
    // cells clash with existing edges (duplicate edge or non-manifold result).
    bool replace(const std::vector<int> &old, const std::vector<Cell> &fresh,
                 std::vector<int> &ids)
    {
      std::vector<Cell> saved;
      for(int id : old) saved.push_back(cells[id]);
      for(int id : old) remove(id);
      ids.clear();
      for(const Cell &c : fresh) {
        const int id = add(c);
        if(id < 0) {
          for(int k : ids) remove(k);
          for(const Cell &s : saved) add(s);
          ids.clear();
          return false;
        }
        ids.push_back(id);
      }
      return true;
    }

    bool isBoundaryVertex(int v) const
    {
      for(int id : star[v]) {
        const Cell &c = cells[id];
        for(int i = 0; i < c.n; ++i)
          if(c.v[i] == v && (cellAt(next(c, i), v) < 0 || cellAt(v, prev(c, i)) < 0))
            return true;
      }
      return star[v].empty();
    }
  };

} // namespace QuadOpt
