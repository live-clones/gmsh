// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The hierarchy of the bases, through their keys, as needed for p-adaptivity:
// each function of order p is a function of order p+1, with the same key, the
// same values and the same information (type and order); and the functions of
// order p whose order information is at most q are exactly the functions of
// order q; and the functions of the range of orders "q:p" are those of order p
// whose order information is at least q. Checked on a single element with
// several numberings of its nodes, i.e. in several orientations.

#include <algorithm>
#include <cmath>
#include <map>
#include "gmsh.h"
#include "basisTest.h"

namespace bt {

  void testHierarchy()
  {
    Random r(6);
    for(auto &e : elements()) {
      if(e.dim == 0) continue;
      std::vector<double> uvw = interiorPoints(e, 5, r);
      for(int numbering = 0; numbering < 3; numbering++) {
        std::vector<std::size_t> nodes = permutation(e.numVertices, r);
        if(!numbering) std::sort(nodes.begin(), nodes.end());
        std::size_t tag = singleElement(e, nodes);
        for(auto &s : spaces()) {
          if(!supported(s, e)) continue;
          std::vector<KeyedFunctions> all;
          for(int p = s.minOrder; p <= maxOrder(e); p++)
            all.push_back(keyedFunctions(tag, e, uvw, spaceType(s, p)));
          for(std::size_t i = 0; i + 1 < all.size(); i++) {
            int p = s.minOrder + i;
            std::string fs = spaceType(s, p);
            const char *n = e.name.c_str(), *f = fs.c_str();
            for(auto &kv : all[i]) {
              auto it = all[i + 1].find(kv.first);
              if(!check(it != all[i + 1].end(),
                        "%s %s: key (%d, %zu) not a key of order %d", n, f,
                        kv.first.first, kv.first.second, p + 1))
                continue;
              const KeyedFunction &a = kv.second, &b = it->second;
              double diff = 0., scale = 1.;
              for(std::size_t j = 0; j < a.values.size(); j++) {
                diff = std::max(diff, std::abs(a.values[j] - b.values[j]));
                scale = std::max(scale, std::abs(a.values[j]));
              }
              check(diff < 1e-12 * scale && a.type == b.type &&
                      a.order == b.order,
                    "%s %s: function of key (%d, %zu) differs at order %d "
                    "(values by %g, type %d/%d, order %d/%d)",
                    n, f, kv.first.first, kv.first.second, p + 1, diff, a.type,
                    b.type, a.order, b.order);
            }
            // the range of orders q:p
            for(int q = s.minOrder; q <= p; q++) {
              std::string fr =
                s.name + std::to_string(q) + ":" + std::to_string(p);
              KeyedFunctions range = keyedFunctions(tag, e, uvw, fr);
              int n = 0;
              bool same = true;
              for(auto &kv : all[i]) {
                if(kv.second.order < q) continue;
                n++;
                auto it = range.find(kv.first);
                if(it == range.end() || it->second.values != kv.second.values)
                  same = false;
              }
              check(same && n == (int)range.size(),
                    "%s %s: %d functions, not the %d functions of order >= %d "
                    "of order %d",
                    e.name.c_str(), fr.c_str(), (int)range.size(), n, q, p);
            }
            // the functions of order <= q among those of the last order
            const KeyedFunctions &last = all.back();
            int nq = 0;
            for(auto &kv : last)
              if(kv.second.order <= p) nq++;
            bool same = (nq == (int)all[i].size());
            for(auto &kv : all[i])
              if(!last.count(kv.first) || last.at(kv.first).order > p)
                same = false;
            check(same,
                  "%s %s: the functions of order <= %d of order %d are not "
                  "the functions of order %d (%d for %d)",
                  n, f, p, s.minOrder + (int)all.size() - 1, p, nq,
                  (int)all[i].size());
          }
        }
      }
    }
  }

} // namespace bt
