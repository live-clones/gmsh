// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#include "hblSolveAllHexLayer.h"

#include <unordered_map>
#include <queue>

/* QuadMeshingTools includes */
#include "cppUtils.h"
#include "arrayGeometry.h"
#include "geolog.h"

/* HexMeshingTools includes */
#include "hblLogging.hpp"
#include "hblTypes.hpp"
#include "hblUtils.h"
#include "hblBrepMesh.h"
#include "hblDiskTriangulation.h"
#include "hblGecode.h"

/* Gmsh includes */
#include "OS.h"
#include "StringUtils.h"
#include "GModel.h"
#include "gmsh.h"
#include "Options.h"
#include "Context.h"

/* - Useful macros */
#define F(_VAR,_NB) for(size_t _VAR = 0; _VAR < (size_t) _NB; ++_VAR)
#define FC(_VAR,_NB,_COND) for(size_t _VAR = 0; _VAR < (size_t) _NB; ++_VAR) if (_COND)
#define RF(...) do {hbl::error(__VA_ARGS__); return false; } while(0)
#define RFC(_COND,...) do { if (_COND) {hbl::error(__VA_ARGS__); return false;} } while(0)


using std::vector;
using std::map;
using std::unordered_map;
using std::array;
using std::pair;

namespace hbl {
  constexpr id EDGE_FIXED = 0;
  const double EPS0 = 1.e-15;

  using namespace CppUtils;

  void printHblStats(const HblStats& stats) {
    info("Gecode sub-problem details:");
    info("  subproblemVarIterTimeStoppedTfirstTlast : {}", stats.subproblemVarIterTimeStoppedTfirstTlast);
    info("Hexbl stats:");
    info("  inNbVertices                    : {}", stats.inNbVertices);
    info("  inNbFacets                      : {}", stats.inNbFacets);
    info("  outNbVertices                   : {}", stats.outNbVertices);
    info("  outNbHexes                      : {}", stats.outNbHexes);
    info("  timePreprocessing               : {}", stats.timePreprocessing);
    info("  timeIntegerProblem              : {}", stats.timeIntegerProblem);
    info("  timeMeshConstruction            : {}", stats.timeMeshConstruction);
    info("  timeGecode                      : {}", stats.timeGecode);
    info("  topoNbConflicts                 : {}", stats.topoNbConflicts);
    info("  topoNbIrregularConfigs          : {}", stats.topoNbIrregularConfigs);
    info("  topoNbSubProblems               : {}", stats.topoNbSubProblems);
    info("  topoNbSubProblemFailed          : {}", stats.topoNbSubProblemFailed);
    info("  topoNbSubProblemStopped         : {}", stats.topoNbSubProblemStopped);
    info("  energyExtrusion                 : {}", stats.energyExtrusion);
    info("  energyFinal                     : {}", stats.energyFinal);
    info("  qualityQuadMinMedAvgMaxInv      : {}", stats.qualityQuadMinMedAvgMaxInv);
    info("  qualityExtrusionMinMedAvgMaxInv : {}", stats.qualityExtrusionMinMedAvgMaxInv);
    info("  qualityFinalMinMedAvgMaxInv     : {}", stats.qualityFinalMinMedAvgMaxInv);
    info("  nbSelfIntersectionInitial       : {}", stats.nbSelfIntersectionInitial);
    info("  nbSelfIntersectionFixed         : {}", stats.nbSelfIntersectionFixed);
    info("  interiorTetMeshingInitial       : {}", stats.interiorTetMeshingInitial);
    info("  interiorTetMeshingFixed         : {}", stats.interiorTetMeshingFixed);
  }


#define _KEY(_VAR) ReplaceSubString("stats.","",#_VAR)
#define WRITE_INFO(_VAR) sformat(stream, "\"{}\": \"{}\",\n", _KEY(_VAR),_VAR);
#define WRITE_INFO_LAST(_VAR) sformat(stream, "\"{}\": \"{}\"\n", _KEY(_VAR),_VAR);
  void writeHblStats(const HblStats& stats, const std::string& path) {
    std::ofstream out(path);
    out << "{\n";

    std::ostringstream stream; 
    std::string model = GModel::current()->getName();
    WRITE_INFO(model);
    WRITE_INFO(stats.inNbVertices);
    WRITE_INFO(stats.inNbFacets);
    WRITE_INFO(stats.outNbVertices);
    WRITE_INFO(stats.outNbHexes);
    WRITE_INFO(stats.timePreprocessing);
    WRITE_INFO(stats.timeIntegerProblem);
    WRITE_INFO(stats.timeMeshConstruction);
    WRITE_INFO(stats.timeGecode);
    WRITE_INFO(stats.topoNbConflicts);
    WRITE_INFO(stats.topoNbIrregularConfigs);
    WRITE_INFO(stats.topoNbSubProblems);
    WRITE_INFO(stats.topoNbSubProblemFailed);
    WRITE_INFO(stats.topoNbSubProblemStopped);
    WRITE_INFO(stats.energyExtrusion);
    WRITE_INFO(stats.energyFinal);
    WRITE_INFO(stats.qualityQuadMinMedAvgMaxInv);
    WRITE_INFO(stats.qualityExtrusionMinMedAvgMaxInv);
    WRITE_INFO(stats.qualityFinalMinMedAvgMaxInv);

    WRITE_INFO(stats.extrusionOutNbHexes);
    WRITE_INFO(stats.extrusionOutNbVertices);
    WRITE_INFO(stats.extrusionTimePreprocessing);
    WRITE_INFO(stats.extrusionTimeIntegerProblem);
    WRITE_INFO(stats.extrusionTimeMeshConstruction);

    WRITE_INFO(stats.nbSelfIntersectionInitial);
    WRITE_INFO(stats.nbSelfIntersectionFixed);
    WRITE_INFO(stats.interiorTetMeshingInitial);
    WRITE_INFO(stats.interiorTetMeshingFixed);

    WRITE_INFO_LAST(stats.subproblemVarIterTimeStoppedTfirstTlast);

    out << stream.str();
    out << "}\n";
    out.close();
  }

  GEntity* getEntity(const BrepMesh& H, size_t v, const HexToBoundaryMeshMatching& h2q, const BrepMesh& Q) {
    if (v >= h2q.vertexParent.size()) {
      return nullptr;
    }
    int pDim = h2q.vertexParent[v].first;
    int pId = h2q.vertexParent[v].second;
    if (pDim == 0) { /* hex vertex is initial boundary mesh vertex */
      if (pId >= Q.vertices.size()) return nullptr;
      return Q.vertices[pId].entity;
    } else if (pDim == 1) { /* hex vertex is mid vertex of initial boundary edge */
      if (pId >= Q.edges.size()) return nullptr;
      return Q.edges[pId].entity;
    } else if (pDim == 2) { /* hex vertex is mid point of initial boundary quad or tri */
      if (pId >= Q.faces.size()) return nullptr;
      return Q.faces[pId].entity;
    } else if (pDim == 3) {
      if (pId >= Q.cells.size()) return nullptr;
      return Q.cells[pId].entity;
    }
    return nullptr;
  }

  bool is_valid_edge_valences(
      const vector<id>& n, 
      const vector<vector<id>>& polygons,
      const DiskTriangulations& dts,
      bool only_check_dts,
      vector<bool>& trglIsValid,
      bool early_stop) {
    trglIsValid.clear();
    trglIsValid.resize(polygons.size(),true);
    // vector<vector<id>> canonicals;
    map<vector<id>,vector<id>> canonicals_map;
    bool valid = true;
    vector<id> bdrVal;
    bdrVal.reserve(16);
    std::array<id,VAL_MAX+1> nb_each_val;
    F(i,polygons.size()) { /* Loop over constraints (polygons) */
      bdrVal.resize(polygons[i].size());
      const size_t NB = polygons[i].size();
      std::fill(nb_each_val.begin(),nb_each_val.end(),0);
      F(j,NB) {
        bdrVal[j] = n[polygons[i][j]];
        RFC(bdrVal[j] > VAL_MAX, "valence {} >= VAL_MAX", bdrVal[j]);
        nb_each_val[bdrVal[j]] += 1;
      }
      if (!only_check_dts) {
        F(j,NB) {
          if (bdrVal[j] == 0) {
            trglIsValid[i] = false;
            valid = false;
            if (early_stop) return false;
          }
          if (bdrVal[j] == 1 && NB >= 4 && bdrVal[(j+1)%NB] == 1) {
            /* cannot have consecutive val. 1 in polygon */
            trglIsValid[i] = false;
            valid = false;
            if (early_stop) return false;
          }
        }
        if (bdrVal[0] > 0 && nb_each_val[bdrVal[0]] == NB) {
          /* all polygon vertices have the same valence -> OK */
          if (bdrVal[0] == 1 && NB != 3) {
            trglIsValid[i] = false;
            valid = false;
            if (early_stop) return false;
            // RFC(bdrVal[0] == 1 && NB != 3, "all val. to 1 only possible for triangle !");
          }
          continue;
        }
        if (nb_each_val[2] == NB - 1) {
          /* if all vertices have val. 2 except one, there is no trangulation */
          trglIsValid[i] = false;
          valid = false;
          if (early_stop) return false;
        }
      }

      /* Remaining case, check in list of triangulations */
      vector<id> canonicalBdrLoop(bdrVal.size());
      vector<id> canonicalBdrVal(bdrVal.size());
      get_smallest_rotation(bdrVal, polygons[i], canonicalBdrVal, canonicalBdrLoop);
      // canonicals.push_back(canonicalBdrVal);
      canonicals_map[canonicalBdrVal].push_back(i);
    }

    // sort_unique(canonicals);
    // F(i,canonicals.size()) {
    id nb_simple_check = 0;
    for (const auto& kv: canonicals_map) {
      // const vector<id>& canonicalBdrVal = canonicals[i];
      const vector<id>& canonicalBdrVal = kv.first;

      size_t NB = 0;
      FC(j,canonicalBdrVal.size(),canonicalBdrVal[j] != 0) NB = j + 1;

      std::fill(nb_each_val.begin(),nb_each_val.end(),0);
      F(j,NB) {
        nb_each_val[canonicalBdrVal[j]] += 1;
      }

      if (NB > 6 && nb_each_val[1] == 0) {
        bool ok = true;
        /* For large polygons, we do not store all the solutions
         * but there are simple tests (to be confirmed 100%) */
        if (nb_each_val[2] == NB - 1) {
          ok = false;
        }
        if (bdrVal[0] > 0 && nb_each_val[bdrVal[0]] == NB) {
          ok = true;
        }
        if (!ok) {
          valid = false;
          for (auto i: kv.second) {
            trglIsValid[i] = false;
          }
          if (early_stop) return false;
        }
        if (ok) {
          nb_simple_check += 1;
          continue;
        }
      }


      bdrsign_t sign = signature_from_boundary(canonicalBdrVal);
      auto it = dts.nbv_sign_to_trgl[NB].find(sign);
      if (it == dts.nbv_sign_to_trgl[NB].end()) {
        valid = false;
        for (auto i: kv.second) {
          trglIsValid[i] = false;
        }
        if (early_stop) return false;
      } else {
        continue;
      }
    }
    // if (valid) trace("verification: the {} bdr. signatures (from {} polygons) have been found in the triangulation database", canonicals.size(), polygons.size());
    if (valid) debug("verification: the {} bdr. signatures (from {} polygons) have been found in the triangulation database", canonicals_map.size(), polygons.size());
    if (valid && nb_simple_check > 0) {
      warn("{} large bdr signatures have been assumed correct without checking in the database", nb_simple_check);
    }

    return valid;
  }

  bool diagnostic_invalid_edge_valences(
      const vector<id>& n, 
      const vector<vector<id>>& polygons,
      const DiskTriangulations& dts,
      const vector<bool>& trglIsValid) {

    map<vector<id>,vector<id>> canonicals_map;
    vector<id> bdrVal;
    bdrVal.reserve(16);
    FC(i,polygons.size(),!trglIsValid[i]) { 
      const size_t NB = polygons[i].size();
      bdrVal.resize(polygons[i].size());
      F(j,NB) {
        bdrVal[j] = n[polygons[i][j]];
      }

      vector<id> canonicalBdrLoop(bdrVal.size());
      vector<id> canonicalBdrVal(bdrVal.size());
      get_smallest_rotation(bdrVal, polygons[i], canonicalBdrVal, canonicalBdrLoop);
      canonicals_map[canonicalBdrVal].push_back(i);
    }

    for (const auto& kv: canonicals_map) {
      const vector<id>& canonicalBdrVal = kv.first;
      size_t NB = 0;
      FC(j,canonicalBdrVal.size(),canonicalBdrVal[j] != 0) NB = j + 1;
      bdrsign_t sign = signature_from_boundary(canonicalBdrVal);
      auto it = dts.nbv_sign_to_trgl[NB].find(sign);
      if (it == dts.nbv_sign_to_trgl[NB].end()) {
        error("- trgl not found, NB = {}, canonicalBdrVal = {}. From {} polygons: {}", NB, canonicalBdrVal, kv.second.size(),
            kv.second);
      } 
    }

    return true;
  }

  bool is_valid_edge_valences(
      const vector<id>& n, 
      const vector<vector<id>>& polygons,
      const DiskTriangulations& dts,
      bool only_check_dts = false,
      bool diagnostic_mode = false,
      bool early_stop = true) {
    vector<bool> trglIsValid(polygons.size(),true);
    bool ok = is_valid_edge_valences(n, polygons, dts, only_check_dts, trglIsValid, early_stop);
    if (!ok && diagnostic_mode) {
      error("edge valences NOT valid, diagnostic:");
      diagnostic_invalid_edge_valences(n, polygons, dts, trglIsValid);
      return false;
    }
    return ok;
  }

  bool compute_discrete_valence_ranges(
      const vector<double>& edgeValenceIdealReal,
      vector<id>& valIdeal,
      vector<id2>& valMinMax,
      const HblOptions& opt
      ) {
    RFC(edgeValenceIdealReal.size() == 0, "no edges ?");
    valIdeal.resize(edgeValenceIdealReal.size());
    valMinMax.resize(edgeValenceIdealReal.size());
    bool V2 = true; /* to avoid valence 1 or 3 on surfaces where dihedral
                       angles are noisy due to coarse resolution of quad
                       mesh */
    if (V2) {
      Msg::Warning("extend the valence two range for ideal valence");
    }

    size_t nb_val[5] = {0,0,0,0,0};
    if (opt.imposed_edge_valence.size() == 0) {
      F(e,edgeValenceIdealReal.size()) {
        double val = edgeValenceIdealReal[e];
        // TODOMX: range too small ?
        if (V2) {
          if (val < 0) {
            RF("edgeValenceIdealReal[{}] = {} ?!", e, val);
          } else if (val < 1.25) { /* use something else ? */
            valIdeal[e] = 1;
            valMinMax[e] = {1,2};
          } else if (val < 2.75) {
            valIdeal[e] = 2;
            valMinMax[e] = {2,3};
          } else if (val < 3.5) {
            valIdeal[e] = 3;
            valMinMax[e] = {2,4};
          } else if (val < 4.) {
            valIdeal[e] = 4;
            valMinMax[e] = {3,5};
          } else {
            RF("edgeValenceIdealReal[{}] = {} ?!", e, val);
          }
        } else {
          if (val < 0) {
            RF("edgeValenceIdealReal[{}] = {} ?!", e, val);
          } else if (val < 1.5) { /* use something else ? */
            valIdeal[e] = 1;
            valMinMax[e] = {1,2};
          } else if (val < 2.5) {
            valIdeal[e] = 2;
            valMinMax[e] = {2,3};
          } else if (val < 3.5) {
            valIdeal[e] = 3;
            valMinMax[e] = {2,4};
          } else if (val < 4.) {
            valIdeal[e] = 4;
            valMinMax[e] = {3,5};
          } else {
            RF("edgeValenceIdealReal[{}] = {} ?!", e, val);
          }
        }
        nb_val[valIdeal[e]] += 1;
      }
    } else {
      F(e,edgeValenceIdealReal.size()) {
        valIdeal[e] = id(edgeValenceIdealReal[e]);
        valMinMax[e] = {valIdeal[e],valIdeal[e]};
        if (valIdeal[e] <= 4) nb_val[valIdeal[e]] += 1;
      }
    }

    info("edge ideal discrete hex valences: {} with val. 1, {} with val. 2, {} with val. 3, {} with val. 4",
        nb_val[1],nb_val[2],nb_val[3],nb_val[4]);
    return true;
  }

  bool select_triangulations(const BrepMesh& Q, 
      const HblOptions& opt,
      const vector<vector<id>>& polygons,
      const vector<id>& edge_valence,
      const std::vector<double>& vertexHexValIdeal,
      vector<const DTriangulation*>& trgls) {
    trgls.clear();
    RFC(Q.vertices.size() != polygons.size(), "number of bdr vertices {} should be equal to number of polygons {}", Q.vertices.size(), polygons.size());
    trgls.resize(Q.vertices.size(),NULL);

    F(i,polygons.size()) {
      vector<id> bdrVal(polygons[i].size());
      F(j,polygons[i].size()) bdrVal[j] = edge_valence[polygons[i][j]];

      vector<id> canonicalBdrLoop(bdrVal.size());
      vector<id> canonicalBdrVal(bdrVal.size());
      get_smallest_rotation(bdrVal, polygons[i], canonicalBdrVal, canonicalBdrLoop);
      bdrsign_t sign = signature_from_boundary(canonicalBdrVal);
      size_t nb = bdrVal.size();
      auto it = opt.dt->nbv_sign_to_trgl[nb].find(sign);
      if (it == opt.dt->nbv_sign_to_trgl[nb].end()) {
        warn("! triangulation not found for bdrVal = {}", bdrVal);
        return false;
      } else {
        if (it->second.size() > 0) {
          /* Takes the disk triangulation with the number of triangles closest 
           * to the ideal number of hexes */
          double diffMax = DBL_MAX;;
          for (auto& kv: it->second) {
            size_t ntri = kv->triangles.size();
            double diff = std::abs(double(ntri)-vertexHexValIdeal[i]);
            if (diff < diffMax) {
              diffMax = diff;
              trgls[i] = kv;
            }
          }
        } else {
          error("select_triangulations | size 0 ?");
          return false;
        }
      }
    }

    return true;
  }

  bool problem_decomposition(
      const HblOptions& opt,
      /* inputs */
      const BrepMesh& Q,
      const vector<double>& valIdealReal,
      const vector<id2>& valMinMax,
      const vector<id>& valIdeal,
      const vector<bool>& trglIsValid,
      id dist_threshold, /* distance in term of edge to edges, so around 3 in practice */
      /* outputs */
      vector<id>& edgeDomain,
      vector<id>& eDistToInvalid
      ) {
    info("problem decomposition with dist threshold set to {} ...", dist_threshold);
    RFC(Q.vertToEdges.size() != Q.vertices.size(), "problem decompoisition | vertToEdges required");

    edgeDomain.clear();
    edgeDomain.resize(Q.edges.size(),NO_ID);

    /* Edge to edges navigation */
    vector<vector<id>> e2e(Q.edges.size());
    F(e,Q.edges.size()) F(lv,2) {
      id v = Q.edges[e].vertices[lv];
      F(le,Q.vertToEdges[v].size()) {
        id e2 = Q.vertToEdges[v][le];
        if (e2 != e) {
          e2e[e].push_back(e2);
        }
      }
    }

    /* Grow Dijsktra-like arround invalid triangulations */
    /* - flag seed edges (eDistToInvalid set to 0) */
    eDistToInvalid.clear();
    eDistToInvalid.resize(Q.edges.size(),NO_ID);
    FC(v,Q.vertices.size(),!trglIsValid[v]) {
      F(le,Q.vertToEdges[v].size()) {
        id e = Q.vertToEdges[v][le];
        eDistToInvalid[e] = 0;
      }
    }
    /* - grow until eDistToInvalid = dist_threshold */
    id domain = 0;
    FC(eInit,Q.edges.size(), edgeDomain[eInit] == NO_ID && eDistToInvalid[eInit] == 0) {
      domain += 1;
      /* Init */
      std::priority_queue<std::pair<id,id>,  std::vector<std::pair<id,id> >,  std::greater<std::pair<id,id> > > qq; 
      eDistToInvalid[eInit] = 0;
      qq.push({0,eInit});
      /* Dijkstra-like */
      while (qq.size() > 0) {
        id e = qq.top().second;
        qq.pop();
        edgeDomain[e] = domain;
        /* Propagation to adjacent edges */
        F(le,e2e[e].size()) {
          id e2 = e2e[e][le];
          if (e2 == e) continue;
          if (eDistToInvalid[e2] == 0 && edgeDomain[e2] == NO_ID) { /* Reach another seed, merge */
            edgeDomain[e2] = domain;
            qq.push({eDistToInvalid[e2],e2});
          } else if (eDistToInvalid[e] + 1 < eDistToInvalid[e2]) {
            eDistToInvalid[e2] = eDistToInvalid[e] + 1;
            if (eDistToInvalid[e2] <= dist_threshold) {
              edgeDomain[e2] = domain;
              qq.push({eDistToInvalid[e2],e2});
            }
          }
        }
      }
    }
    FC(e,Q.edges.size(),edgeDomain[e] == NO_ID) edgeDomain[e] = EDGE_FIXED;

    /* - merge adjacent (sharing vertex) domains */
    {
      vector<id2> equalities;
      vector<id> adjDomains;
      F(v,Q.vertices.size()) {
        adjDomains.clear();
        F(le,Q.vertToEdges[v].size()) {
          id e = Q.vertToEdges[v][le];
          if (edgeDomain[e] != NO_ID && edgeDomain[e] != EDGE_FIXED) {
            adjDomains.push_back(edgeDomain[e]);
          }
        }
        sort_unique(adjDomains);
        if (adjDomains.size() > 1) {
          F(i,adjDomains.size()) FC(j,adjDomains.size(),j>i) {
            id2 eq = sorted(adjDomains[i],adjDomains[j]);
            equalities.push_back(eq);
          }
        }
      }
      sort_unique(equalities);
      id nbi = 0;
      vector<id> old2new;
      system_reduction_using_graph(domain+1, equalities, old2new, nbi);
      F(e,Q.edges.size()) {
        id d = edgeDomain[e];
        if (old2new[d] != NO_ID) {
          edgeDomain[e] = old2new[d];
        }
      }
      info("... {} initial domain found, {} after merge of adjacent ones", domain, nbi-1);
    }

    return true;
  }

  struct EdgeValenceProblemInput {
    /* Unknowns */
    std::vector<id> n_origin;
    std::vector<double> x_ideal;
    std::vector<id2> n_min_max;
    /* Constraints */
    std::vector<std::vector<id> > polygons;
    /* Branching info, select values with higher priority first */
    std::vector<id> n_priority;
  };

  bool extract_edge_valence_problems_from_decomposition(
      const BrepMesh& Q,
      const vector<id>& edgeDomain,
      const vector<id>& eDistToInvalid,
      const vector<double>& edgeValenceIdealReal,
      const vector<id>& edgeValenceIdeal,
      const vector<id2>& valMinMax,
      const vector<vector<id>>& polygons,
      vector<EdgeValenceProblemInput>& problems
      ) {
    problems.clear();
    id nbDomains = *std::max_element(edgeDomain.begin(),edgeDomain.end());
    problems.reserve(nbDomains);

    /* For each domain, do the redirection and fill the problem struct */
    vector<id> old2new(Q.edges.size());
    FC(domain,nbDomains+1,domain>0) {
      std::fill(old2new.begin(),old2new.end(),NO_ID);

      /* Extract the unknowns */
      EdgeValenceProblemInput prob;
      vector<std::pair<id,id> > dist_var;
      FC(e,Q.edges.size(),edgeDomain[e] == domain) {
        old2new[e] = prob.n_origin.size();
        prob.n_origin.push_back(e);
        prob.n_priority.push_back(eDistToInvalid[e]);
      }
      if (prob.n_origin.size() == 0) continue;

      /* Fill the problem variables */
      vector<id> trglIds;
      prob.x_ideal.resize(prob.n_origin.size());
      prob.n_min_max.resize(prob.n_origin.size());
      F(i,prob.n_origin.size()) {
        id e = prob.n_origin[i];
        prob.n_min_max[i] = valMinMax[e];
        prob.x_ideal[i] = edgeValenceIdealReal[e];
        F(lv,2) trglIds.push_back(Q.edges[e].vertices[lv]);
      }

      /* Extract the constraints (polygons) */
      sort_unique(trglIds);
      F(i,trglIds.size()) {
        id v = trglIds[i];
        const vector<id>& poly = polygons[v];
        vector<id> new_poly = poly;
        F(j,poly.size()) {
          id e = poly[j];
          id ne = old2new[e];
          if (ne == NO_ID) { 
            /* Create fixed edge variable (boundary condition for sub problems) */
            if (edgeDomain[e] != EDGE_FIXED) {
              error("domain {}, v={}, cannot extend to edge e={} because edgeDomain[e]={} !",
                  domain, v, e, edgeDomain[e]);
              return false;
            }
            id val = edgeValenceIdeal[e];
            old2new[e] = prob.n_origin.size();
            prob.n_origin.push_back(e);
            prob.x_ideal.push_back(double(val));
            prob.n_min_max.push_back({val,val});
            prob.n_priority.push_back(eDistToInvalid[e]);
            ne = old2new[e];
          }
          new_poly[j] = ne;
        }
        prob.polygons.push_back(new_poly);
      }

      problems.push_back(prob);
    }

    return true;
  }


  bool solve_edge_valences_with_decomposition(
      size_t N,
      const std::vector<std::vector<id>>& polygons,
      const std::vector<double>& edgeValenceIdealReal_in,
      const std::vector<id2>& valMinMax_in,
      std::vector<id>& val,
      id dist_threshold,
      const BrepMesh& Q,
      const vector<id>& valIdeal_in,
      const vector<bool>& trglIsValid_in,
      const HblOptions& opt,
      HblStats& stats
      ) {
    val.resize(Q.edges.size());

    /* Inputs of the topological problem */
    std::vector<double> edgeValenceIdealReal = edgeValenceIdealReal_in;
    std::vector<id2> valMinMax = valMinMax_in;
    vector<id> valIdeal = valIdeal_in;
    vector<id> valFound(valIdeal.size(),NO_ID);
    vector<bool> trglIsValid = trglIsValid_in;

    /* Try increasing dist_threshold (size of relaxation around conflicts) if required */
    bool ok = false;
    for (id dt = dist_threshold; dt < dist_threshold + 3; ++dt) {
      if (dt > dist_threshold) {
        warn("failed to solve the sub-problems with dist_threshold = {}, trying with dist_threshold = {} ...", dt-1, dt);

        // update triangulation conflicts
        is_valid_edge_valences(valIdeal, polygons, *opt.dt, false, trglIsValid, false);
      }
      std::fill(val.begin(),val.end(),NO_ID);
      vector<id> edgeDomain;
      vector<id> eDistToInvalid;
      bool okd = problem_decomposition(opt, Q, edgeValenceIdealReal, valMinMax, valIdeal, 
          trglIsValid, dt, edgeDomain, eDistToInvalid);
      RFC(!okd, "failed to build domain decomposition");
      FC(e,Q.edges.size(),edgeDomain[e] == EDGE_FIXED) val[e] = valIdeal[e];
      FC(e,Q.edges.size(),eDistToInvalid[e] == NO_ID) eDistToInvalid[e] = 1e6;

      if (false && opt.debug && opt.viz) {
        F(e,Q.edges.size()) {
          if (edgeDomain[e] > 0) {
            vec3 p1 = Q.vertices[Q.edges[e].vertices[0]].pt;
            vec3 p2 = Q.vertices[Q.edges[e].vertices[1]].pt;
            GeoLog::add({p1,p2},double(edgeDomain[e]),"domain_dcp");
          }
        }
        F(f,Q.faces.size()) {
          bool inside = false;
          FC(le,4,edgeDomain[Q.faces[f].edges[le]] != 0) inside = true;
          MElement* q = Q.faces[f].origin;
          if (inside) {
            q->setPartition(2);
          } else {
            q->setPartition(1);
          }
        } 
        id nc = 0;
        FC(v,Q.vertices.size(),!trglIsValid[v]) {
          GeoLog::add(Q.vertices[v].pt,0.,"conflict");
          nc += 1;
        }
        info("{} invalid initial disk triangulations", nc);

        GModel::current()->setNumPartitions(2);
        unsigned int colorCarousel = 3;
        opt_mesh_color_carousel(0, GMSH_SET | GMSH_GUI,  colorCarousel);
        unsigned int hexExtr = CTX::instance()->packColor(242, 242, 242, 1.);
        opt_mesh_color_1(0, GMSH_SET | GMSH_GUI, hexExtr);
        unsigned int hexCurve = CTX::instance()->packColor(255, 193, 0, 1.);
        opt_mesh_color_2(0, GMSH_SET | GMSH_GUI, hexCurve);

        Msg::Warning("testing sub problems");
        gmsh::initialize();


        GeoLog::flush();
        gmsh::fltk::run();
        abort();

        GeoLog::flush();
        // gmsh::fltk::run();
        // RF("testing");
      }


      vector<EdgeValenceProblemInput> problems;
      bool oke = extract_edge_valence_problems_from_decomposition(Q, edgeDomain, eDistToInvalid,
          edgeValenceIdealReal, 
          valIdeal, valMinMax, polygons, problems);
      RFC(!oke, "failed to extract sub problems for domain decomposition");

      ok = true;
      stats.timeGecode = 0.;
      stats.topoNbSubProblemStopped = 0;
      stats.topoNbSubProblemFailed = 0;
      stats.topoNbSubProblems = (int) problems.size();
      F(p,problems.size()) {
        info("- solving sub-problem {}/{} ({} variables) ...", p+1, problems.size(), problems[p].x_ideal.size());
        double tInit = Cpu();
        const EdgeValenceProblemInput& pb = problems[p];
        vector<id> slt(pb.n_origin.size(),0);
        if (pb.n_origin.size() != pb.n_priority.size()) {
          error("wrong sizes: n_origin.size() = {}, n_priority.size() = {}, n_min_max.size() = {}", pb.n_origin.size(), pb.n_priority.size(), pb.n_min_max.size());
          return false;
        }
        bool stopped = false;
        std::vector<double> iterTime;
        bool oks = solve_with_gecode(
            pb.n_origin.size(),
            pb.polygons,
            pb.x_ideal,
            pb.n_min_max,
            pb.n_priority,
            slt,
            stopped,
            iterTime,
            opt.gecodeTimeMaxInit,
            opt.gecodeTimeMaxImprove);
        if (stopped) {
          stats.topoNbSubProblemStopped += 1;
        }
        if (!oks) {
          warn("failed to solve sub-problem {}/{} (dist_threshold = {})", p+1, problems.size(), dist_threshold);
          stats.topoNbSubProblemFailed += 1;
          ok = false;
          // break; // do not break, to fix/update values on other sub-problems

          if (pb.x_ideal.size() > 500) {
            // Problem will be quite large next step, we make it easier by targeting valence 2 or more
            warn("update the problem {}/{} targets", p+1,problems.size());
            FC(i,pb.n_min_max.size(),pb.n_min_max[i][0] != pb.n_min_max[i][1]) {
              id e = pb.n_origin[i];
              if (edgeValenceIdealReal[e] < 2) {
                edgeValenceIdealReal[e] = 2.;
                valIdeal[e] = 2;
                if (valMinMax[e][0] < 2) valMinMax[e][0] = 2;
                if (valMinMax[e][1] < 3) valMinMax[e][1] = 3;
              }
            } 
          }
          continue;
        }

        double tFinal = Cpu();
        double tFirstSol = -1.;
        double tLastSol = -1.;
        if (iterTime.size() > 0) {
          tFirstSol = iterTime[0];
          tLastSol = iterTime.back();
        }
        double nUnknowns = 0.;
        FC(i,pb.n_min_max.size(),pb.n_min_max[i][0] != pb.n_min_max[i][1]) nUnknowns += 1.;
        stats.subproblemVarIterTimeStoppedTfirstTlast.push_back(
            {nUnknowns, double(iterTime.size()), tFinal-tInit, double(stopped), tFirstSol, tLastSol});
        stats.timeGecode += tFinal - tInit;

        const bool verify_sub_solution = false;
        if (opt.debug && verify_sub_solution) {
          vector<bool> trglIsValid(pb.polygons.size(),true);
          bool okev = is_valid_edge_valences(slt,
              pb.polygons, *opt.dt, true, trglIsValid, false);
          if (!okev) {
            error("sub-problem {}/{}, solution is not valid", p+1,problems.size());
            FC(v,pb.polygons.size(),!trglIsValid[v]) {
              vector<id> bdrVal(pb.polygons[v].size(),0);
              F(le,pb.polygons[v].size()) {
                id var = pb.polygons[v][le];
                bdrVal[le] = slt[var];
              }
              error("- trgl {} invalid: {}", v, bdrVal);
            }
          }
        }

        /* Put the local solution in the global solution */
        F(i,pb.n_origin.size()) {
          id e = pb.n_origin[i];
          val[e] = slt[i];

          /* Update values in case of call with larger subdomain size */
          valFound[e] = slt[i];
          valIdeal[e] = slt[i];
          edgeValenceIdealReal[e] = double(valIdeal[e]);

          if (slt[i] == 0) {
            error("sub-problem {}/{}, slt[{}] = {} (initial edge e={})", 
                p+1, problems.size(), i, slt[i], e);
            ok = false;
          }
        }

      } /* end of loop over problems */

      if (ok) {
        const bool verify_solution = true;
        if (opt.debug && verify_solution) {
          warn("debug mode, verify solution");
          vector<bool> trglIsValid(polygons.size(),true);
          bool okv = is_valid_edge_valences(val, polygons, *opt.dt, true, trglIsValid, false);
          if (!okv) {
            error("invalid solution");
            FC(v,Q.vertices.size(),!trglIsValid[v]) {
              vector<id> bdrVal(polygons[v].size(),0);
              vector<id> bdrEdgeDomain(polygons[v].size(),0);
              F(le,polygons[v].size()) {
                id e = polygons[v][le];
                bdrVal[le] = val[e];
                bdrEdgeDomain[le] = edgeDomain[e];
              }
              error("- trgl {} invalid. bdr val: {}, bdr edge domain: {}", v, bdrVal, bdrEdgeDomain);
            }
            warn("debug mode, done");
            return false;
          }
          warn("debug mode, done");
        }
      }

      if (ok) {
        break;
      }
    }

    if (!ok) {
      warn("! failed to solve edge valences with decomposition strategy !");
      return false;
    }


    return true;
  }

  bool solveAllHexBoundaryLayerProblem(
      const HblInput& input,
      const HblOptions& opt,
      HblOutput& output) {
    info("====== edge valence solver ======");
    double t0 = Cpu();
    output.trgls.clear();
    output.hexValence.clear();
    RFC(opt.dt == NULL, "disk triangulations not found in opt");
    bool found = false;

    const BrepMesh& Q = input.Q;

    /* Extract boundary of dual disk triangulations */
    vector<vector<id> > dualPolygons(Q.vertices.size());
    F(i,Q.vertices.size()) {
      bool okbl = extract_dual_polygon(Q, i, dualPolygons[i]);
      RFC(!okbl, "failed to get boundary loop for face {}", i);
    }
    FC(i,dualPolygons.size(),dualPolygons[i].size() <= 2)  {
      Msg::Error("Input quad mesh: wrong number quads around vertex: %li", dualPolygons[i].size());
      return false;
    }

    /* Set the domain of each integer variable based on ideal value */
    vector<id> valIdeal(Q.edges.size(),0);
    vector<id2> valRange(Q.edges.size(),{id(opt.val_min),id(opt.val_max)});
    bool oki = compute_discrete_valence_ranges(input.edgeHexValIdeal, valIdeal, valRange, opt);
    RFC(!oki, "failed to build discrete edge ideal hex valence");

    /* Check if ideal valence is already a solution
     * the quad vertex where the hex configurations are not valid flagged
     * with trglIsValid */
    vector<id> val = valIdeal;
    vector<bool> trglIsValid;
    if (opt.imposed_edge_valence.size() == 0 && opt.imposed_valence > 0) {
      warn("impose hex-valence {} on all quad edges", opt.imposed_valence);
      std::fill(val.begin(),val.end(),id(opt.imposed_valence));
    } 
    bool ok = is_valid_edge_valences(val, dualPolygons, *opt.dt, false, trglIsValid, false);
    if (ok) {
      found = true;
      info("ideal valence IS a solution ! no need to use valence solver");
      bool force_gecode = false;
      if (force_gecode) {
        found = false;
        warn("(temporary) forcing the use of the gecode solver");
      }
    } else {
      info("ideal valence is not a solution, need to use valence solver");
      if (opt.imposed_edge_valence.size() > 0) {
        error("imposed edge valence (from file) is NOT a solution ! continue but weird");
      }
    }
    FC(k,trglIsValid.size(),!trglIsValid[k]) output.stats.topoNbConflicts += 1;


    /* Valence solver based on gecode */
    if (!found) {
      id dist_threshold = 2;
      double t0 = Cpu();
      bool gfound = solve_edge_valences_with_decomposition(Q.edges.size(),
          dualPolygons, input.edgeHexValIdeal, valRange,
          val, dist_threshold, Q,
          valIdeal, trglIsValid, opt, output.stats);

      if (gfound) {
        double t1 = Cpu();
        double nrj = 0.;
        FC(e,Q.edges.size(),valIdeal[e] != val[e]) nrj += std::pow(input.edgeHexValIdeal[e]-val[e],2);
        info("integer problem solved in {} seconds, energy: {}", t1-t0, nrj);
        bool ok = is_valid_edge_valences(val, dualPolygons, *opt.dt, false, false);
        if (!ok) {
          error("solution from gecode not valid !");
          is_valid_edge_valences(val, dualPolygons, *opt.dt, true, true);
          if (opt.viz && opt.debug) { /* Show solution n_i */
            F(e,Q.edges.size()) {
              vec3 p1 = Q.vertices[Q.edges[e].vertices[0]].pt;
              vec3 p2 = Q.vertices[Q.edges[e].vertices[1]].pt;
              GeoLog::add({p1,p2},double(val[e]),"!n_i");
              GeoLog::add({p1,p2},double(e),"!e_i");
            }
            vector<bool> trglIsValid(dualPolygons.size(),true);
            is_valid_edge_valences(val, dualPolygons, 
                *opt.dt, true, trglIsValid, false);
            FC(v,Q.vertices.size(),!trglIsValid[v]) {
              vector<id> bdrVal(dualPolygons[v].size(),0);
              vector<id> bdrEdgeDomain(dualPolygons[v].size(),0);
              F(le,dualPolygons[v].size()) {
                id e = dualPolygons[v][le];
                bdrVal[le] = val[e];
              }
              error("- trgl {} invalid: {}", v, bdrVal);
              GeoLog::add({Q.vertices[v].pt},0.,"!no_disk_trgl");
            }
            GeoLog::flush();
          }
          return false;
        } else {
          info("gecode-based valence solver found a solution !");
          found = true;
          vector<id> nb_val(6,0);
          F(i,val.size()) nb_val[std::min(val[i],id(5))] += 1;
          info("edge hex valences: {} with val. 1, {} with val. 2, {} with val. 3, {} with val. 4, {} with more",
              nb_val[1],nb_val[2],nb_val[3],nb_val[4], nb_val[5]);
        }
      } else {
        warn("gecode-based valence solver DID NOT FOUND a solution !");
        warn("fallback to pure extrusion");
        F(e,Q.edges.size()) { val[e] = 2; }
        found = true;
      }
    }
    if (!found) return false;

    if (opt.viz) { /* Show solution n_i */
      int tag = -1;
      F(e,Q.edges.size()) {
        vec3 p1 = Q.vertices[Q.edges[e].vertices[0]].pt;
        vec3 p2 = Q.vertices[Q.edges[e].vertices[1]].pt;
        GeoLog::add({p1,p2},double(val[e]),"n_i");
      }
      GeoLog::flush();
    }

    if (Q.edges.size() < 1000) {
      debug("solution edge hex val: {}", val);
    }


    /* Energy computation */
    output.stats.energyExtrusion = 0.;
    output.stats.energyFinal = 0.;
    F(e,Q.edges.size()) {
      if (valIdeal[e] != 2) {
        output.stats.energyExtrusion += std::pow(input.edgeHexValIdeal[e]-2.,2);
      }
      if (val[e] != valIdeal[e]) {
        output.stats.energyFinal += std::pow(input.edgeHexValIdeal[e]-double(val[e]),2);
      }
    }
    if (output.stats.energyFinal > output.stats.energyExtrusion) {
      warn("energy of the found topology {} superior to pure extrusion {}, fall back to extrusion solution", 
          output.stats.energyFinal, output.stats.energyExtrusion);
      F(e,Q.edges.size()) {
        val[e] = 2;
      }
      output.stats.energyFinal = output.stats.energyExtrusion;
    }


    /* For each dual polygon, select a triangulation given the boundary degrees and an
     * ideal number of triangles (the vertex hex valence in the primal) */
    output.trgls.resize(Q.vertices.size(),NULL);
    bool oks = select_triangulations(Q, opt, dualPolygons, val, input.vertexHexValIdeal, output.trgls);
    if (!oks) {
      warn("failed to assign disk triangulations from given boundary and valence");
      warn("fallback to pure extrusion and try again");
      F(e,Q.edges.size()) {
        val[e] = 2;
      }
      oks = select_triangulations(Q, opt, dualPolygons, val, input.vertexHexValIdeal, output.trgls);
    }
    if (!oks) {
      error("failed to assign disk triangulations");
      return false;
    }
    info("{} triangulations assigned", output.trgls.size());

    output.hexValence.resize(val.size(),0);
    F(i,val.size()) output.hexValence[i] = (int) val[i];

    output.configIsIdeal.resize(Q.vertices.size(),true);
    F(j,Q.vertices.size()) {
      F(k,dualPolygons[j].size()) {
        id e = dualPolygons[j][k];
        if (val[e] != valIdeal[e]) {
          output.configIsIdeal[j] = false;
          output.stats.topoNbIrregularConfigs += 1;
          break;
        }
      }
    }


    output.stats.timeIntegerProblem = Cpu() - t0;

    return true;
  }

}

