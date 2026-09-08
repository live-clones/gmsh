// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// Bounded, geometry-independent candidates for experimental V2 searches.
#pragma once

#include "halfEdgeMesh.h"
#include "halfEdgeRewriteCatalog.h"
#include <algorithm>
#include <set>
#include <vector>

namespace QuadOptimizer { namespace PatchSearch {
  using Id = HalfEdgeMesh::Index;
  using Cell = std::vector<Id>;
  using Cells = std::vector<Cell>;

  inline Cell canonicalCell(Cell cell)
  {
    if(cell.empty()) return cell;
    std::rotate(cell.begin(), std::min_element(cell.begin(), cell.end()), cell.end());
    Cell reversed = cell;
    std::reverse(reversed.begin() + 1, reversed.end());
    return std::min(cell, reversed);
  }

  inline Cells canonicalCells(Cells cells)
  {
    for(Cell &cell : cells) cell = canonicalCell(std::move(cell));
    std::sort(cells.begin(), cells.end());
    return cells;
  }

  // C contains exactly rewritten cells, rather than unchanged context cells
  // that could dilute its quality or CAD score.
  inline bool changesEveryCell(const Cells &before, const Cells &after)
  {
    std::set<Cell> original;
    for(const Cell &cell : before) original.insert(canonicalCell(cell));
    for(const Cell &cell : after)
      if(original.count(canonicalCell(cell))) return false;
    return true;
  }

  inline std::vector<Cells> quadrangulations(const Cell &boundary,
                                            std::size_t limit)
  {
    std::vector<Cells> result;
    if(!limit || boundary.size() > 10 || boundary.size() % 2) return result;
    std::vector<std::size_t> polygon(boundary.size());
    for(std::size_t i = 0; i < polygon.size(); ++i) polygon[i] = i;
    // At most 55 raw fillings for the supported ten-corner disk. Only the
    // requested number are returned to geometry evaluation.
    for(const auto &filling : HalfEdgeRewrite::evenPolygonQuadrangulations(polygon)) {
      Cells cells;
      for(const auto &quad : filling)
        cells.push_back({boundary[quad[0]], boundary[quad[1]],
                         boundary[quad[2]], boundary[quad[3]]});
      result.push_back(std::move(cells));
      if(result.size() == limit) break;
    }
    return result;
  }

  inline bool buildMesh(const Cells &cells, HalfEdgeMesh::Mesh &mesh)
  {
    Id maximum = -1;
    for(const Cell &cell : cells)
      for(const Id vertex : cell) {
        if(vertex < 0 || vertex >= 32) return false;
        maximum = std::max(maximum, vertex);
      }
    for(Id vertex = 0; vertex <= maximum; ++vertex)
      mesh.addVertex({{0., 0., 0.}});
    for(const Cell &cell : cells)
      if(mesh.addFace(cell) == HalfEdgeMesh::invalid) return false;
    return mesh.manifold();
  }

  inline std::vector<Cells> minimalTriangleFillings(const Cell &boundary,
                                                   std::size_t limit)
  {
    if(boundary.size() % 2 == 0) return quadrangulations(boundary, limit);
    std::vector<Cells> result;
    if(!limit || boundary.size() < 5 || boundary.size() > 9) return result;
    // An odd boundary needs at least one triangle. Keep exactly one instead
    // of converting an even quad-only patch into triangles.
    for(std::size_t root = 0; root < boundary.size(); ++root) {
      Cell remainder;
      for(std::size_t i = 0; i < boundary.size(); ++i)
        if(i != (root + 1) % boundary.size()) remainder.push_back(boundary[i]);
      for(Cells filling : quadrangulations(remainder, limit - result.size())) {
        filling.push_back({boundary[root], boundary[(root + 1) % boundary.size()],
                           boundary[(root + 2) % boundary.size()]});
        result.push_back(std::move(filling));
        if(result.size() == limit) return result;
      }
    }
    return result;
  }

  struct ComposedResult {
    std::vector<Cells> candidates;
    std::size_t visited = 0;
  };

  // A QT relocation followed by a TT / TQT / TQQT reduction. The first
  // state is never installed. Its hard geometric guards are delegated to
  // the caller; final candidates still require the normal complete gate.
  template <class AcceptIntermediate>
  ComposedResult composeTriangleReduction(const Cells &before,
                                          std::size_t limit,
                                          AcceptIntermediate acceptIntermediate)
  {
    ComposedResult result;
    if(!limit || before.size() < 3 || before.size() > 5) return result;
    if(std::count_if(before.begin(), before.end(),
         [](const Cell &cell) { return cell.size() == 3; }) != 2) return result;
    HalfEdgeMesh::Mesh original;
    if(!buildMesh(before, original)) return result;
    HalfEdgeMesh::Cavity whole;
    if(!original.diskCavity(original.faces(), whole)) return result;
    std::set<Cells> unique;
    for(const auto &edge : original.edges()) {
      if(edge.faces.size() != 2) continue;
      const std::size_t first = original.faceCornerCount(edge.faces[0]);
      const std::size_t second = original.faceCornerCount(edge.faces[1]);
      if(!((first == 3 && second == 4) || (first == 4 && second == 3))) continue;
      HalfEdgeMesh::Cavity pair;
      if(!original.diskCavity(edge.faces, pair) || pair.boundaryVertices.size() != 5)
        continue;
      const Cell &b = pair.boundaryVertices;
      const Cells oldPair = {before[edge.faces[0]], before[edge.faces[1]]};
      for(std::size_t rotation = 0; rotation < 5; ++rotation) {
        const auto at = [&](std::size_t i) { return b[(rotation + i) % 5]; };
        const Cells relocated = {{at(0), at(1), at(2)},
                                 {at(2), at(3), at(4), at(0)}};
        if(canonicalCells(oldPair) == canonicalCells(relocated)) continue;
        if(result.visited == limit) return result;
        ++result.visited;
        if(!original.validReplacement(edge.faces, relocated) ||
           !acceptIntermediate(edge.faces, relocated)) continue;
        HalfEdgeMesh::Mesh trial = original;
        std::vector<Id> installed;
        if(!trial.replace(edge.faces, relocated, &installed)) continue;
        std::vector<Cell> pending(1, {installed[0]});
        while(!pending.empty()) {
          Cell path = std::move(pending.back());
          pending.pop_back();
          for(const Id neighbor : trial.neighbors(path.back())) {
            if(std::find(path.begin(), path.end(), neighbor) != path.end()) continue;
            if(trial.faceCornerCount(neighbor) == 4 && path.size() < 3) {
              Cell longer = path;
              longer.push_back(neighbor);
              pending.push_back(std::move(longer));
              continue;
            }
            if(trial.faceCornerCount(neighbor) != 3) continue;
            Cell terminal = path;
            terminal.push_back(neighbor);
            HalfEdgeMesh::Cavity disk;
            if(!trial.diskCavity(terminal, disk) || !disk.interiorVertices.empty())
              continue;
            for(const Cells &filling : quadrangulations(disk.boundaryVertices,
                                                         limit - result.visited)) {
              if(result.visited == limit) return result;
              ++result.visited;
              HalfEdgeMesh::Mesh final = trial;
              if(!final.replace(terminal, filling)) continue;
              Cells candidate;
              for(const Id cell : final.faces()) candidate.push_back(final.faceVertices(cell));
              if(!changesEveryCell(before, candidate)) continue;
              if(unique.insert(canonicalCells(candidate)).second)
                result.candidates.push_back(std::move(candidate));
            }
          }
        }
      }
    }
    return result;
  }
}} // namespace QuadOptimizer::PatchSearch
