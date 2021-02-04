// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#include "qmtDiskQuadrangulationRemeshing.h"

/* System includes */
// #include <vector>
// #include <array>
// #include <unordered_map>
// #include <cstdint>
// #include <math.h>
// #include <queue>
// #include <algorithm>

/* Gmsh includes */
#include "GmshMessage.h"
#include "OS.h"
#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "GModel.h"
#include "MVertex.h"
#include "MLine.h"
#include "MElement.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "BackgroundMesh.h"
#include "StringUtils.h"

/* QuadMeshingTools includes */
#include "cppUtils.h"
#include "qmtMeshUtils.h"
#include "qmtMeshGeometryOptimization.h"
#include "dataDiskQuadrangulations.hpp" // list of disk quadrangulations as a raw string literal

using namespace CppUtils;

namespace QMT {
  using id = uint32_t;
  using id4 = std::array<id,4>;

  struct vidHash {
    size_t operator()(const std::vector<id>& p) const noexcept {
      uint32_t hash = 0;
      for (size_t i = 0; i < p.size(); ++i) {
        hash += p[i];
        hash += hash << 10;
        hash ^= hash >> 6;
      }
      hash += hash << 3;
      hash ^= hash >> 11;
      hash += hash << 15;
      return hash;
    }
  };

  using std::vector;
  using std::unordered_map; /* robin_hood unordered_map much faster */
  using Quadrangulation = std::vector< std::array<id,4> >;

  vector<vector<Quadrangulation> > B_disk_quadrangulations;
  vector<unordered_map<vector<id>, vector<id>, vidHash > > B_BVL_ids;

  bool load_disk_quadrangulations_from_raw_data() {
    if (B_disk_quadrangulations.size() != 0) return false;

    Msg::Info("loading disk quadrangulations ...");
    B_disk_quadrangulations.reserve(20);
    B_BVL_ids.reserve(20);
    std::string data(disk_quadrangulations);
    vector<std::string> lines = SplitString(data,'\n');
    Quadrangulation qdrl;
    vector<std::string> numbers;
    vector<id> bdrValLoop;
    for (size_t i = 0; i < lines.size(); ++i) {
      numbers = SplitString(lines[i],' ');
      if (numbers.size() < 7) continue;
      size_t B = std::stoi(numbers[0]);
      size_t I = std::stoi(numbers[1]);
      size_t Q = std::stoi(numbers[2]);
      if (numbers.size() != 3 + 4 * Q) {
        Msg::Warning("load_disk_quadrangulations | wrong sizes: B=%li, I=%li, Q=%li and numbers.size = %li",
            B, I, Q, numbers.size());
        continue;
      }
      qdrl.resize(Q);
      for (size_t j = 0; j < Q; ++j) {
        for (size_t lv = 0; lv < 4; ++lv) {
          qdrl[j][lv] = std::stoi(numbers[3 + 4 * j + lv]);
        }
      }

      if (B >= B_disk_quadrangulations.size()) {
        B_disk_quadrangulations.resize(B+1);
        B_disk_quadrangulations[B].reserve(1000);
        B_BVL_ids.resize(B+1);
      }

      id qId = B_disk_quadrangulations[B].size();
      B_disk_quadrangulations[B].push_back(qdrl);

      /* Assumes:
       * - first B vertices are on the boundary 
       * - canonical valence ordering according to boundary valence loop 
       *   (should be compatible with the generator) */
      bdrValLoop.clear();
      bdrValLoop.resize(B,0);
      for (size_t j = 0; j < Q; ++j) for (size_t lv = 0; lv < 4; ++lv){
        id v = qdrl[j][lv];
        if (v < B) bdrValLoop[v] += 1;
      }
      B_BVL_ids[B][bdrValLoop].push_back(qId);
    }
    Msg::Info("%li disk quadrangulations loaded", lines.size());
    return true;
  }

  bool computeQuadMeshValences(const vector<id4>& quads, vector<int>& valence) {
    valence.clear();
    valence.reserve(quads.size()*4);
    for (size_t f = 0; f < quads.size(); ++f) for (size_t lv = 0; lv < 4; ++lv) {
      size_t v = quads[f][lv];
      if (v >= valence.size()) valence.resize(v+1,0);
      valence[v] += 1;
    }
    return true;
  }

  double computeIrregularity(
      const vector<id4>& quads, 
      const vector<int>& valence,
      const std::vector<int>& bndIdealValence,
      const std::vector<std::pair<int,int> >& bndAllowedValenceRange) 
  {
    double irregularity = 0.;
    /* Boundary vertices */
    for (size_t bv = 0; bv < bndIdealValence.size(); ++bv) {
      if (valence[bv] < bndAllowedValenceRange[bv].first) return DBL_MAX;
      if (valence[bv] > bndAllowedValenceRange[bv].second) return DBL_MAX;
      if (bndIdealValence[bv] <= 1 && valence[bv] >= 2) { /* probably making a 6+ ... */
        irregularity += 1000;
      } else {
        irregularity += 10*std::pow(bndIdealValence[bv]-valence[bv],2);
      }
    }
    /* Interior vertices */
    for (size_t iv = bndIdealValence.size(); iv < valence.size(); ++iv) {
      irregularity += std::pow(4-valence[iv],2);
    }
    return irregularity;
  }


  bool computeBestMatchingConfiguration(
      const vector<id4>& quads, 
      const vector<int>& valence,
      const vector<int>& bndIdealValence,
      const vector<std::pair<int,int> >& bndAllowedValenceRange,
      int& rotation,
      double& irregularity)
  {
    double best = DBL_MAX;
    int rot = 0;
    vector<int> biv = bndIdealValence;
    vector<std::pair<int,int>>  bav = bndAllowedValenceRange;

    /* Initial config */
    {
      double irreg = computeIrregularity(quads, valence, biv, bav);
      if (irreg < best) {
        best = irreg;
        rotation = rot;
      }
    }

    /* Forward rotation */
    for (size_t r = 1; r < biv.size(); ++r) {
      rot += 1;
      std::rotate(biv.begin(),biv.begin()+1,biv.end());
      std::rotate(bav.begin(),bav.begin()+1,bav.end());
      double irreg = computeIrregularity(quads, valence, biv, bav);
      if (irreg < best) {
        best = irreg;
        rotation = rot;
      }
    }

    /* Try in reverse order */
    rot = 0;
    biv = bndIdealValence;
    bav = bndAllowedValenceRange;
    std::reverse(biv.begin(),biv.end());
    std::reverse(bav.begin(),bav.end());
    for (size_t r = 1; r < biv.size(); ++r) {
      rot -= 1;
      std::rotate(biv.begin(),biv.begin()+1,biv.end());
      std::rotate(bav.begin(),bav.begin()+1,bav.end());
      double irreg = computeIrregularity(quads, valence, biv, bav);
      if (irreg < best) {
        best = irreg;
        rotation = rot;
      }
    }

    irregularity = best;
    return (best != DBL_MAX);
  }

  double randomInRange(double vMin, double vMax) {
    double v = (double) rand() / RAND_MAX;
    return vMin + v * (vMax-vMin);
  }

  /* WARNING: GFace is not modified, just the "floating" MVertex
   * and MQuadrangle are created, they must be inserted in the GFace
   * later is the pattern is kept.
   * The vertex positions are random ! Need geometric smoothing after */
  bool getDiskQuadrangulationRemeshing(
      GFace* gf,
      const std::vector<MVertex*>& bnd,
      int rotation,                                      /* rotation to apply to input */
      const std::vector<id4>& quads,                     /* pattern */
      std::vector<MVertex*> & newVertices,               /* new vertices inside the cavity */
      std::vector<MElement*> & newElements               /* new quads inside the cavity */
      ) {

    const double EPS_RANDOM = 1.e-16;

    std::vector<MVertex*> bndr = bnd;
    if (rotation > 0) {
      std::rotate(bndr.begin(),bndr.begin()+(size_t)rotation,bndr.end());
    } else if (rotation < 0) {
      std::reverse(bndr.begin(),bndr.end());
      std::rotate(bndr.begin(),bndr.begin()+(size_t) std::abs(rotation),bndr.end());
    }

    unordered_map<id,MVertex*> pv2mv;
    for (size_t f = 0; f < quads.size(); ++f) {
      std::array<MVertex*,4> vert;
      for (size_t lv = 0; lv < 4; ++lv) {
        size_t pv = quads[f][lv];
        if (pv < bndr.size()) {
          vert[lv] = bndr[pv];
        } else {
          auto it = pv2mv.find(pv);
          if (it == pv2mv.end()) {
            SVector3 p = bndr[0]->point();
            p.data()[0] += randomInRange(-EPS_RANDOM,EPS_RANDOM);
            p.data()[1] += randomInRange(-EPS_RANDOM,EPS_RANDOM);
            p.data()[2] += randomInRange(-EPS_RANDOM,EPS_RANDOM);
            double uv[2] = {0.,0.};
            uv[0] = randomInRange(-EPS_RANDOM,EPS_RANDOM);
            uv[1] = randomInRange(-EPS_RANDOM,EPS_RANDOM);
            MVertex *mv = new MFaceVertex(p.x(),p.y(),p.z(),gf,uv[0],uv[1]);
            pv2mv[pv] = mv;
            vert[lv] = mv;
            newVertices.push_back(mv);
          } else {
            vert[lv] = it->second;
          }
        }
      }
      if (rotation < 0) { /* revert quad to keep coherent orientation */
        std::reverse(vert.begin(),vert.end());
      }
      MQuadrangle *q = new MQuadrangle (vert[0],vert[1],vert[2],vert[3]);
      newElements.push_back(q);
    }

    /* Ensure coherent orientation between the new mesh and the boundary */
    {
      MVertex* a = bnd[0];
      MVertex* b = bnd[1];
      int reorient = 0;
      for (MElement* e: newElements) {
        for (size_t lv = 0; lv < 4; ++lv) {
          MVertex* v0 = e->getVertex(lv);
          MVertex* v1 = e->getVertex((lv+1)%4);
          if (v0 == a && v1 == b) {
            reorient = -1;
            break;
          } else if (v0 == b && v1 == a) {
            reorient = 1;
            break;
          }
        }
        if (reorient != 0) break;
      }
      if (reorient == 1) {
        for (MElement* e: newElements) {
          e->reverse();
        }
      } else if (reorient == 0) {
        Msg::Error("getDiskQuadrangulationRemeshing: bdr quad edge not found, weird");
        return false;
      }
    }

    // TODO: ensure coherent orientation before / after remeshing
    //       check quad bdr vs bnd in input

    return true;
  }
  
  int patchOptimizeGeometryWithExteriorStorage(
      int method,
      GFaceMeshPatch& patch, 
      const GeomOptimOptions& opt,
      GeomOptimStats& stats,
      std::unordered_map<MVertex*,SPoint2>& newUVs,
      std::unordered_map<MVertex*,SPoint3>& newPositions) {

    /* Save old positions */
    std::unordered_map<MVertex*,SPoint2> oldUVs;
    std::unordered_map<MVertex*,SPoint3> oldPositions;
    for (MVertex* v: patch.intVertices) {
      if (dynamic_cast<GFace*>(v->onWhat()) != nullptr) {
        double uv[2];
        v->getParameter(0,uv[0]);
        v->getParameter(1,uv[1]);
        oldUVs[v] = SPoint2(uv[0],uv[1]);
      }
      oldPositions[v] = v->point();
    }

    if (method == 0) {
      int st = patchOptimizeGeometryGlobal(patch, stats);
      if (st != 0) return st;
    } else if (method == 1) {
      int st = patchOptimizeGeometryWithKernel(patch, opt, stats);
      if (st != 0) return st;
    } else if (method == 2) {
      int st = patchOptimizeGeometryGlobal(patch, stats);
      if (st != 0) return st;
      st = patchOptimizeGeometryWithKernel(patch, opt, stats);
      if (st != 0) return st;
    }

    /* Save new positions and restore old ones */
    for (MVertex* v: patch.intVertices) {
      if (dynamic_cast<GFace*>(v->onWhat()) != nullptr) {
        double uv[2];
        v->getParameter(0,uv[0]);
        v->getParameter(1,uv[1]);
        newUVs[v] = SPoint2(uv[0],uv[1]);
        SPoint2 oldUV = oldUVs[v];
        v->setParameter(oldUV[0],oldUV[1]);
      }
      newPositions[v] = v->point();
      SPoint3 oldPt = oldPositions[v];
      v->setXYZ(oldPt.x(),oldPt.y(),oldPt.z());
    }

    return 0;
  }

}

using namespace QMT;

int initDiskQuadrangulations() {
  bool ok = load_disk_quadrangulations_from_raw_data();
  if (!ok) return -1;
  return 0;
}

int remeshLocalWithDiskQuadrangulation(
    GFace* gf,
    const std::vector<MElement*>& elements,
    const std::vector<MVertex*>& intVertices,
    const std::vector<MVertex*>& bdrVertices,
    const std::vector<int>& bndIdealValence,
    const std::vector<std::pair<int,int> >& bndAllowedValenceRange,
    const std::vector<MElement*>& neighborsForGeometry,
    double minSICNafer,
    bool invertNormalsForQuality,
    GFaceMeshDiff& diff) {
  if (QMT::B_disk_quadrangulations.size() == 0) {
    Msg::Error("Missing disk quadrangulation database, call initDiskQuadrangulations() before");
    return -1;
  }


  /* Get disk quadrangulations with the same boundary size */
  const vector<vector<id4> >* small_patterns = NULL;
  if (bdrVertices.size() < B_disk_quadrangulations.size() && B_disk_quadrangulations[bdrVertices.size()].size() > 0) {
    small_patterns = &(B_disk_quadrangulations[bdrVertices.size()]);
  } else {
    // TODO: a simple remeshing by using parallel quads ?
    Msg::Error("disk quadrangulation remeshing: no pattern for input boundary loop size (%li bdr vertices)", 
        bdrVertices.size());
    return -1;
  }
  const vector<vector<id4> >& qmeshes = *small_patterns;


  /* For each disk quadrangulation, compute vertex valence and
   * check matching with input patch, considering all rotations.
   * Store the compatible matchings with their irregularity score. */
  vector<int> valence;
  std::vector<std::pair<double,std::pair<size_t,int> > > irregularity_pattern_rotation;
  for (size_t i = 0; i < qmeshes.size(); ++i) {
    const vector<id4>& quads = qmeshes[i];
    computeQuadMeshValences(quads, valence);
    double irregularity = DBL_MAX;
    int rotation = 0;
    bool found = computeBestMatchingConfiguration(quads, valence, bndIdealValence, bndAllowedValenceRange, rotation, irregularity);
    if (found) {
      irregularity_pattern_rotation.push_back({irregularity,{i,rotation}});
    }
  }
  if (irregularity_pattern_rotation.size() == 0) {
    Msg::Debug("disk quadrangulation remeshing: no pattern matching input allowed valence range (%li bdr vertices)",
        bdrVertices.size());
    return -1; /* no pattern matching allowed valence range */
  }
  std::sort(irregularity_pattern_rotation.begin(),irregularity_pattern_rotation.end());

  /* Keep the best pattern for which it is possible to find a 
   * untangled and sufficient quality geometry */
  size_t N = 5; /* maximum number of pattern tested */
  if (irregularity_pattern_rotation.size() < N) N = irregularity_pattern_rotation.size();

  bool geometryOk = false;
  for (size_t i = 0; i < N; ++i) {
    size_t no = irregularity_pattern_rotation[i].second.first;
    int rotation = irregularity_pattern_rotation[i].second.second;
    const vector<id4>& quads = qmeshes[no];

    /* New GFace mesh patch */
    GFaceMeshPatch patch;
    patch.gf = gf;
    patch.bdrVertices = bdrVertices;

    bool ok = getDiskQuadrangulationRemeshing(gf, patch.bdrVertices,
        rotation, quads, patch.intVertices, patch.elements);
    if (!ok) {
      Msg::Debug("disk quandrangulation remeshing: failed to remesh small cavity");
      continue;
    }
    Msg::Debug("disk quadrangulation remeshing: try %li/%li, dq=[%li,%i], %li bdr, %i->%i int vertices, %i->%i quads",
        i, N, no, rotation, patch.bdrVertices.size(), intVertices.size(), patch.intVertices.size(), elements.size(), patch.elements.size());

    /* Try to only move the interior vertices (in general, it is not enough) */
    if (patch.intVertices.size() > 0) {
      /* Pure UV smoothing in CAD domain */
      GeomOptimStats stats;
      int s0 = patchOptimizeGeometryGlobal(patch, stats);

      /* Kernel smoothing */
      GeomOptimOptions opt;
      opt.invertCADNormals = invertNormalsForQuality;
      int s1 = patchOptimizeGeometryWithKernel(patch, opt, stats);
      if (stats.sicnAvgAfter > minSICNafer) {
        geometryOk = true;
        diff.after = patch; /* set the diff output ! */
        break;
      }
    } else {
      double sicnMin = -1.;
      double sicnAvg = -1.;
      computeSICN(patch.elements, sicnMin, sicnAvg);
      if (sicnMin > minSICNafer) {
        geometryOk = true;
        diff.after = patch; /* set the diff output ! */
        break;
      }
    }

    /* Try to move the interior and bdr vertices (which are not on CAD curve/corner) */
    {
      std::vector<MElement*> largerElements = patch.elements;
      append(largerElements, neighborsForGeometry);
      GFaceMeshPatch largerPatch;
      bool okp = patchFromElements(gf, largerElements, largerPatch);
      if (!okp || largerPatch.intVertices.size() == 0) continue;

      Msg::Debug("try smoothing the extended cavity (%li -> %li free vertices)", 
          patch.intVertices.size(), largerPatch.intVertices.size());

      GeomOptimOptions opt;
      opt.invertCADNormals = invertNormalsForQuality;
      GeomOptimStats stats;

      std::unordered_map<MVertex*,SPoint2> newUVs;
      std::unordered_map<MVertex*,SPoint3> newPositions;
      int globalUVThenLocalKernel = 2;
      int s0 = patchOptimizeGeometryWithExteriorStorage(globalUVThenLocalKernel, largerPatch, opt, stats, newUVs, newPositions);

      if (s0 == 0 && stats.sicnAvgAfter > minSICNafer) {
        geometryOk = true;
        /* Apply the new UV and positions (will the change the bdr of the initial patch) */
        for (auto& kv: newUVs) {
          kv.first->setParameter(0,kv.second.x());
          kv.first->setParameter(1,kv.second.y());
        }
        for (auto& kv: newPositions) {
          kv.first->setXYZ(kv.second.x(),kv.second.y(),kv.second.z());
        }
        diff.after = patch; 
        break;
      }
    }
  }

  if (!geometryOk) {
    Msg::Debug("disk quadrangulation remeshing: failed to find valid geometry (%li bdr vertices)",
        bdrVertices.size());
    return -1;
  }

  /* set the diff input */
  diff.gf = gf;
  diff.before.gf = gf;
  diff.before.elements = elements;
  diff.before.intVertices = intVertices;
  diff.before.bdrVertices = bdrVertices;

  return 0;
}


