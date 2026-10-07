// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// Comparison with reference values. The other tests check the properties of
// the bases, which hold for many different choices of basis functions; this
// one detects any change of the functions themselves (scaling, sign, order,
// orientation conventions), and of the information attached to their keys,
// which codes using the API may depend on. For each element, function space,
// order and a few orientations, each function is summarized by a fixed random
// combination of its values at fixed points.

#include <cmath>
#include <cstdio>
#include <fstream>
#include <map>
#include <sstream>
#include "gmsh.h"
#include "basisTest.h"

namespace bt {

  struct Fingerprint {
    std::vector<double> values; // one per function
    std::string info; // type and order of each function
  };

  static std::map<std::string, Fingerprint> fingerprints()
  {
    std::map<std::string, Fingerprint> fp;
    for(auto &e : elements()) {
      Random rp(7);
      std::vector<double> uvw = interiorPoints(e, 6, rp);
      std::vector<std::size_t> nodes(e.numVertices);
      for(int i = 0; i < e.numVertices; i++) nodes[i] = i + 1;
      std::size_t tag = singleElement(e, nodes);
      for(auto &s : spaces()) {
        if(!supported(s, e)) continue;
        for(int p = s.minOrder; p <= (e.dim <= 2 ? 4 : 3); p++) {
          for(int derivative = 0; derivative < 2; derivative++) {
            std::string fs = spaceType(s, p, derivative);
            int n = evaluate(e.type, uvw, fs, {0}).totalOrientations;
            std::set<int> o = {0, n / 2, n - 1};
            for(int i : o) {
              Table t = evaluate(e.type, uvw, fs, {i});
              std::ostringstream key;
              key << e.name << " " << fs << " " << i;
              Fingerprint &f = fp[key.str()];
              Random rw(11);
              std::vector<double> w(t.numPoints * t.numComponents);
              for(auto &x : w) x = rw.uniform(-1., 1.);
              for(int j = 0; j < t.numFunctions; j++) {
                double v = 0.;
                for(int q = 0; q < t.numPoints; q++)
                  for(int c = 0; c < t.numComponents; c++)
                    v += w[q * t.numComponents + c] * t(0, q, j, c);
                f.values.push_back(v);
              }
              if(derivative) continue;
              std::vector<int> tk;
              std::vector<std::size_t> ek;
              std::vector<double> coord;
              gmsh::model::mesh::getKeysForElement(tag, fs, tk, ek, coord,
                                                   false);
              gmsh::vectorpair info;
              gmsh::model::mesh::getKeysInformation(tk, ek, e.type, fs, info);
              std::ostringstream is;
              for(auto &ti : info) is << ti.first << ":" << ti.second << " ";
              f.info = is.str();
            }
          }
        }
      }
    }
    return fp;
  }

  void testReference(const std::string &file, bool write)
  {
    std::map<std::string, Fingerprint> fp = fingerprints();
    if(write) {
      std::ofstream out(file);
      out << "# Reference values of the hierarchical basis functions, written "
             "by\n# hierarchicalBasisTests reference reference.txt write\n";
      char buf[32];
      for(auto &kv : fp) {
        out << kv.first << " | " << kv.second.info << "|";
        for(double v : kv.second.values) {
          std::snprintf(buf, sizeof(buf), " %.13g", v);
          out << buf;
        }
        out << "\n";
      }
      std::printf("Wrote %d cases to %s\n", (int)fp.size(), file.c_str());
      return;
    }
    std::ifstream in(file);
    if(!check(in.good(), "cannot read %s", file.c_str())) return;
    std::map<std::string, Fingerprint> ref;
    std::string line;
    while(std::getline(in, line)) {
      if(line.empty() || line[0] == '#') continue;
      std::size_t a = line.find(" | "), b = line.find('|', a + 3);
      Fingerprint &f = ref[line.substr(0, a)];
      f.info = line.substr(a + 3, b - a - 3);
      std::istringstream vs(line.substr(b + 1));
      double v;
      while(vs >> v) f.values.push_back(v);
    }
    check(ref.size() == fp.size(), "%d reference cases, %d computed",
          (int)ref.size(), (int)fp.size());
    for(auto &kv : fp) {
      auto it = ref.find(kv.first);
      if(!check(it != ref.end(), "%s: no reference values", kv.first.c_str()))
        continue;
      const Fingerprint &r = it->second, &c = kv.second;
      check(r.info == c.info, "%s: key information differs", kv.first.c_str());
      if(!check(r.values.size() == c.values.size(),
                "%s: %d functions, %d in the reference", kv.first.c_str(),
                (int)c.values.size(), (int)r.values.size()))
        continue;
      double scale = 1., diff = 0.;
      for(double v : r.values) scale = std::max(scale, std::abs(v));
      for(std::size_t i = 0; i < r.values.size(); i++)
        diff = std::max(diff, std::abs(r.values[i] - c.values[i]));
      check(diff < 1e-10 * scale, "%s: values differ by %g (scale %g)",
            kv.first.c_str(), diff, scale);
    }
  }

} // namespace bt
