// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The number of basis functions, components, orientations and keys, and how the
// functions are distributed over the vertices, edges, faces and interior of the
// element.

#include <map>
#include "gmsh.h"
#include "basisTest.h"

namespace bt {

  void testCounts()
  {
    Random r(1);
    for(auto &e : elements()) {
      int factorial = 1;
      for(int i = 2; i <= e.numVertices; i++) factorial *= i;
      std::vector<double> uvw = interiorPoints(e, 1, r);
      std::size_t tag = singleElement(e, permutation(e.numVertices, r));
      for(auto &s : spaces()) {
        if(!supported(s, e)) continue;
        for(int p = s.minOrder; p <= maxOrder(e); p++) {
          std::string fs = spaceType(s, p), dfs = spaceType(s, p, true);
          const char *n = e.name.c_str(), *f = fs.c_str();
          Table t = evaluate(e.type, uvw, fs, {0});
          Table d = evaluate(e.type, uvw, dfs, {0});
          int nf = t.numFunctions;
          check(t.numComponents == (s.kind == H1 ? 1 : 3),
                "%s %s: %d components", n, f, t.numComponents);
          check(d.numComponents == (s.kind == HDIV ? 1 : 3),
                "%s %s: %d components", n, dfs.c_str(), d.numComponents);
          check(d.numFunctions == nf, "%s %s: %d functions for %d values", n,
                dfs.c_str(), d.numFunctions, nf);
          check(t.totalOrientations == factorial &&
                  gmsh::model::mesh::getNumberOfOrientations(e.type, fs) ==
                    factorial,
                "%s %s: %d orientations", n, f, t.totalOrientations);
          check(gmsh::model::mesh::getNumberOfKeys(e.type, fs) == nf,
                "%s %s: %d keys for %d functions", n, f,
                gmsh::model::mesh::getNumberOfKeys(e.type, fs), nf);
          if(s.kind == H1)
            check(nf == (int)monomials(e, p).size(),
                  "%s %s: %d functions, expected %d", n, f, nf,
                  (int)monomials(e, p).size());
          if(s.kind == HCURL && e.dim == 1)
            check(nf == p + 1, "%s %s: %d functions", n, f, nf);

          // the keys of the element: one per function, all different, and
          // the same number of functions on all edges and on all faces of the
          // same type
          ElementKeys k = elementKeys(tag, fs);
          check((int)k.typeKeys.size() == nf, "%s %s: %d keys for %d functions",
                n, f, (int)k.typeKeys.size(), nf);
          std::set<std::pair<int, std::size_t>> unique;
          std::map<std::set<std::size_t>, int> perEntity;
          int numVertexFunctions = 0;
          for(std::size_t i = 0; i < k.typeKeys.size(); i++) {
            unique.insert({k.typeKeys[i], k.entityKeys[i]});
            perEntity[k.entityNodes[i]]++;
            if(k.functionType[i] == 0) numVertexFunctions++;
            check(k.functionType[i] != 0 || k.entityNodes[i].size() == 1,
                  "%s %s: vertex function on %d nodes", n, f,
                  (int)k.entityNodes[i].size());
          }
          check(unique.size() == k.typeKeys.size(), "%s %s: duplicate keys", n,
                f);
          check(numVertexFunctions == (s.kind == H1 ? e.numVertices : 0),
                "%s %s: %d vertex functions", n, f, numVertexFunctions);
          // entities with the same number of nodes (edges, triangular faces,
          // ...) carry the same number of functions
          std::map<std::size_t, std::set<int>> countsBySize;
          for(auto &pe : perEntity)
            if(pe.first.size() < (std::size_t)e.numVertices)
              countsBySize[pe.first.size()].insert(pe.second);
          for(auto &c : countsBySize)
            check(c.second.size() == 1,
                  "%s %s: entities with %d nodes carry different numbers of "
                  "functions",
                  n, f, (int)c.first);
        }
      }
    }
  }

} // namespace bt
