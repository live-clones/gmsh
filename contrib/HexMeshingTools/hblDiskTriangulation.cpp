// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#include "hblDiskTriangulation.h"

#include <vector>
#include <map>
#include <unordered_map>

#include <sstream>
#include <iostream>
#include <fstream>

/* QuadMeshingTools includes */
#include "cppUtils.h"

/* HexMeshingTools includes */
#include "hblLogging.hpp"
#include "hblUtils.h"
#include "dataDiskTriangulations.hpp" // raw data in a std::string

/* Gmsh includes */
#include "robin_hood.h"

using std::vector;
using std::map;
using std::array;
using std::pair;

/* - Loops */
#define F(_VAR,_NB) for(size_t _VAR = 0; _VAR < (size_t) _NB; ++_VAR)
#define FC(_VAR,_NB,_COND) for(size_t _VAR = 0; _VAR < (size_t) _NB; ++_VAR) if (_COND)
#define RF(...) do {hbl::error(__VA_ARGS__); return false; } while(0)
#define RFC(_COND,...) do { if (_COND) {hbl::error(__VA_ARGS__); return false;} } while(0)

using namespace CppUtils;

namespace hbl {
  template <typename Key, typename T, typename Hash = robin_hood::hash<Key>,
         typename KeyEqual = std::equal_to<Key>, size_t MaxLoadFactor100 = 80>
         using unordered_map = robin_hood::detail::Table<true, MaxLoadFactor100, Key, T, Hash, KeyEqual>;

  template <typename Key, typename Hash = robin_hood::hash<Key>, typename KeyEqual = std::equal_to<Key>,
         size_t MaxLoadFactor100 = 80>
         using unordered_set = robin_hood::detail::Table<true, MaxLoadFactor100, Key, void, Hash, KeyEqual>;

  struct id2Hash {
    size_t operator()(const id2 &pr) const noexcept {
      size_t seed = 0;
      hash_combine(seed, robin_hood::hash_bytes(&(pr[0]), sizeof(id)));
      hash_combine(seed, robin_hood::hash_bytes(&(pr[1]), sizeof(id)));
      return seed;
    }
  };

  bool trgl_is_file(const char *fileName) {
    std::ifstream in(fileName);
    return in.good();
  }

  std::vector<std::string> split_string(const std::string& str, char delim) {
    std::vector<std::string> strings;
    size_t start;
    size_t end = 0;
    while ((start = str.find_first_not_of(delim, end)) != std::string::npos) {
      end = str.find(delim, start);
      strings.push_back(str.substr(start, end - start));
    }
    return strings;
  }

  vector<id> get_smallest_rotation(const vector<id>& vec) {
    vector<id> smallest = vec;
    vector<id> rot_l = vec;
    vector<id> rot_r = vec;
    std::reverse(rot_r.begin(),rot_r.end());
    F(i,vec.size()) {
      std::rotate(rot_l.begin(),rot_l.begin()+1,rot_l.end());
      if (rot_l < smallest) smallest = rot_l;
      std::rotate(rot_r.begin(),rot_r.begin()+1,rot_r.end());
      if (rot_r < smallest) smallest = rot_r;
    }
    return smallest;
  }

  bool get_smallest_rotation(const vector<id>& bdrVal, const vector<id>& bdrLoop, 
      vector<id>& smallestBdrVal, vector<id>& smallestBdrLoop) {
    smallestBdrVal = bdrVal;
    smallestBdrLoop = bdrLoop;
    vector<id> rot = bdrVal;
    vector<id> ids = bdrLoop;
    F(i,bdrVal.size()) {
      std::rotate(rot.begin(),rot.begin()+1,rot.end());
      std::rotate(ids.begin(),ids.begin()+1,ids.end());
      if (rot < smallestBdrVal) {
        smallestBdrVal = rot;
        smallestBdrLoop = ids;
      }
    }
    std::reverse(rot.begin(),rot.end());
    std::reverse(ids.begin(),ids.end());
    F(i,bdrVal.size()) {
      std::rotate(rot.begin(),rot.begin()+1,rot.end());
      std::rotate(ids.begin(),ids.begin()+1,ids.end());
      if (rot < smallestBdrVal) {
        smallestBdrVal = rot;
        smallestBdrLoop = ids;
      }
    }
    return true;
  }

  bool DTriangulation::fill_struct_from_triangles() {
    vOnBdr.clear();
    vOnBdr.resize(nv,false);

    vValence.clear();
    vValence.resize(nv,0);
    std::unordered_map<id2,id,id2Hash> sedge_val;
    F(f,triangles.size()) F(le,3) {
      id v1 = triangles[f][le];
      id v2 = triangles[f][(le+1)%3];
      id2 sedge = sorted(v1,v2);
      sedge_val[sedge] += 1;
      vValence[v1] += 1;
    }

    edges.clear();
    edges.reserve(sedge_val.size());

    eOnBdr.clear();
    eOnBdr.reserve(sedge_val.size());

    for (const auto& kv : sedge_val) {
      edges.push_back(kv.first);
      if (kv.second == 1) {
        eOnBdr.push_back(true);
        vOnBdr[kv.first[0]] = true;
        vOnBdr[kv.first[1]] = true;
      } else if (kv.second == 2) {
        eOnBdr.push_back(false);
      } else {
        RF("load_triangulation | non manifold edge ?! triangles = {}, edge = {}, valence = {}", triangles, kv.first, kv.second);
      }
    }
    nb = 0;
    FC(v,nv,vOnBdr[v]) nb += 1;
    return true;
  }

  bool DTriangulation::load_triangulation(const std::vector<id>& tri_vertices) {
    RFC(tri_vertices.size() == 0 || tri_vertices.size() % 3 != 0, "load_triangulation | wrong input: {}", tri_vertices);
    triangles.resize(tri_vertices.size()/3);
    nv = 0;
    F(i,triangles.size()) F(j,3) {
      id v = tri_vertices[3*i+j];
      triangles[i][j] = v;
      nv = std::max(nv,v+1);
    }
    bool okf = fill_struct_from_triangles();
    RFC(!okf, "failed to build the DTriangulation");
    return true;
  }

  bool DTriangulation::transform_to_canonical_boundary_loop() {
    vector<id> old2new(nv,NO_ID);

    /* Get vertex boundary loop */
    vector<id2> bdrEdges;
    FC(le,edges.size(),eOnBdr[le]) {
      bdrEdges.push_back(edges[le]);
    }
    std::vector<id> overt;
    bool ok = getOrderedVerticesFromEdges(bdrEdges[0][0], bdrEdges, overt);
    RFC(!ok, "failed to get ordered vertices from edges");
    vector<id> bdr_val_loop(overt.size());
    F(i,bdr_val_loop.size()) {
      bdr_val_loop[i] = vValence[overt[i]];
    }

    /* Smallest 'boundary val' loop */
    vector<id> s_bdrVal(overt.size());
    vector<id> s_overt(overt.size());
    get_smallest_rotation(bdr_val_loop, overt, s_bdrVal, s_overt);

    /* Re-numbering map */
    id cv = 0;
    F(i,s_overt.size()) {
      old2new[s_overt[i]] = cv;
      cv += 1;
    }
    FC(i,nv,old2new[i] == NO_ID) {
      old2new[i] = cv;
      cv += 1;
    }

    /* Apply */
    F(f,triangles.size()) F(lv,3) triangles[f][lv] = old2new[triangles[f][lv]];

    bool okf = fill_struct_from_triangles();
    RFC(!okf, "failed to build the DTriangulation after transform_to_canonical_boundary_loop");

    return true;
  }

  bool load_disk_triangulations(DiskTriangulations& data) {
    debug("loading disk triangulations from raw data ...");

    std::stringstream input(dataDiskTriangulationList);
    std::string nb_trgl_str;
    std::getline(input, nb_trgl_str, '\n');
    size_t nbTriangulations = std::stoi(nb_trgl_str);
    info("loading {} triangulations from disk ...", nbTriangulations);
    id nbmax = 0;
    F(i,nbTriangulations) {
      std::string str_line;
      std::getline(input, str_line, '\n');
      std::vector<std::string> str_vertices = split_string(str_line, ' ');
      RFC(str_vertices.size() % 3 != 0, "load_disk_triangulations | trgl {}: vertices are not a multiple of 3", i);
      std::vector<id> tri_vertices(str_vertices.size());
      F(j,tri_vertices.size()) tri_vertices[j] = std::stoi(str_vertices[j]);
      std::unique_ptr<DTriangulation> uptr(new DTriangulation);
      bool okl = uptr->load_triangulation(tri_vertices);
      RFC(!okl,"failed to load triangulation with vertices: {}", tri_vertices);
      bool okc = uptr->transform_to_canonical_boundary_loop();
      RFC(!okc,"failed to transform to canonical representation");
      data.trgls.push_back(std::move(uptr));
      nbmax = std::max(nbmax,data.trgls.back()->nb);
    }

    /* Build trivial triangulations (central vertices) for large disks */
    id nbmaxT = NBMAX;
    for (size_t n = nbmax; n < nbmaxT; ++n) {
      /* Triangulation with n boundary vertices -> n triangles */
      std::vector<id> tri_vertices;
      for (size_t i = 0; i < n; ++i) {
        tri_vertices.push_back(i);
        tri_vertices.push_back((i+1)%n);
        tri_vertices.push_back(n);
      }
      std::unique_ptr<DTriangulation> uptr(new DTriangulation);
      bool okl = uptr->load_triangulation(tri_vertices);
      RFC(!okl,"failed to load triangulation with vertices: {}", tri_vertices);
      bool okc = uptr->transform_to_canonical_boundary_loop();
      RFC(!okc,"failed to transform to canonical representation");
      data.trgls.push_back(std::move(uptr));
    }
    nbmax = nbmaxT;

    /* Create the hash mapping */
    info("computing signatures and redirections ...");
    data.nbv_sign_to_trgl.clear();
    data.nbv_sign_to_trgl.resize(nbmax+1);

    F(i,data.trgls.size()) {
      const DTriangulation& dt = *(data.trgls[i]);
      RFC((size_t) dt.nb >= data.nbv_sign_to_trgl.size(), "error nbv");
      vector<id2> bdrEdges;
      FC(le,dt.edges.size(),dt.eOnBdr[le]) {
        bdrEdges.push_back(dt.edges[le]);
      }
      vector<id> bdr_val_loop(dt.nb);
      FC(j,dt.nv,dt.vOnBdr[j]) bdr_val_loop[j] = dt.vValence[j];
      bdrsign_t bsign = signature_from_boundary(bdr_val_loop);
      data.nbv_sign_to_trgl[dt.nb][bsign].push_back(data.trgls[i].get());
    }

    return true;
  }

  bool compute_triangulation_boundary_valence_loop(
      const std::vector<id2>& bdrEdges,
      const std::vector<id>& vValence,
      std::vector<id>& bdr_val_loop) {
    std::vector<id> overt;
    bool ok = getOrderedVerticesFromEdges(bdrEdges[0][0], bdrEdges, overt);
    RFC(!ok, "failed to get ordered vertices from edges");
    bdr_val_loop.clear();
    bdr_val_loop.resize(overt.size());
    F(i,bdr_val_loop.size()) {
      bdr_val_loop[i] = vValence[overt[i]];
    }
    return true;
  }

  bdrsign_t signature_from_boundary(const std::vector<id>& bdr_val_loop) {
    bdrsign_t sign;
    if (bdr_val_loop.size() >= sign.size()) {
      error("too much vertices in boundary: {}/{}", bdr_val_loop.size(), sign.size());
    }
    std::fill(sign.begin(),sign.end(),0);
    F(i,bdr_val_loop.size()) sign[i] = (unsigned char) bdr_val_loop[i];
    return sign;
  }

  bool show_legal_configurations(const DiskTriangulations& dts, id nbv) {
    info("nbv = {}:",nbv);
    for (const auto& kv: dts.nbv_sign_to_trgl[nbv]) {
      const bdrsign_t& sig = kv.first;
      vector<id> vals;
      bool ok = true;
      FC(i,sig.size(),sig[i] > 0) {
        if (sig[i] >= 4) ok = false;
        vals.push_back(sig[i]);
      }
      if (ok) {
        info("  {}", vals);
      }
    }

    return true;
  }
}
