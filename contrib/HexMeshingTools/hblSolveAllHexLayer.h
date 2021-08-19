// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#pragma once

#include <vector>
#include <array>

#include "hblBrepMesh.h"

namespace hbl {

  class DTriangulation;
  class DiskTriangulations;

  struct HblOptions {
    DiskTriangulations* dt = NULL;

    int val_min = 1;
    int val_max = 5;
    int imposed_valence = 0; /* 0: no imposed val, -1: random ideal valences */
    std::vector<int> imposed_edge_valence;

    int valence_free_width = 3;
    double extrusion_factor = 1.;
    bool noCADproj = false;
    bool debug = true;
    bool viz = false;
    bool discreteModel = false;


    double gecodeTimeMaxInit = 100e3;
    double gecodeTimeMaxImprove = 30e3;
  };

  struct HblStats {
    int inNbFacets = 0;
    int inNbVertices = 0;
    int outNbHexes = 0;
    int outNbTets = 0;
    int outNbVertices = 0;
    double timePreprocessing = 0.;
    double timeIntegerProblem = 0.;
    double timeMeshConstruction = 0.;
    double timeGecode = 0.;
    int topoNbConflicts = 0;
    int topoNbIrregularConfigs = 0;
    int topoNbSubProblems = 0;
    int topoNbSubProblemStopped = 0;
    int topoNbSubProblemFailed = 0;
    double energyFinal = 0.;
    std::array<double,5> qualityInputMinMedAvgMaxInv = {0.,0.,0.,0.,0.};
    std::array<double,5> qualityQuadMinMedAvgMaxInv = {0.,0.,0.,0.,0.};
    std::array<double,5> qualityHexMinMedAvgMaxInv = {0.,0.,0.,0.,0.};
    std::array<double,5> qualityTetMinMedAvgMaxInv = {0.,0.,0.,0.,0.};

    double energyExtrusion = 0.;
    int extrusionOutNbHexes = 0;
    int extrusionOutNbVertices = 0;
    double extrusionTimePreprocessing = 0.;
    double extrusionTimeIntegerProblem = 0.;
    double extrusionTimeMeshConstruction = 0.;
    std::array<double,5> qualityExtrusionMinMedAvgMaxInv = {0.,0.,0.,0.,0.};

    std::vector<std::array<double,6> > subproblemVarIterTimeStoppedTfirstTlast;

    int interiorTetMesh = 0;
    int interiorTetMeshTopoFallback = 0;
  };

  void printHblStats(const HblStats& stats);
  void writeHblStats(const HblStats& stats, const std::string& path);

  constexpr std::pair<int,int> NO_PARENT = {4,-1};

  struct HexToBoundaryMeshMatching {
    std::vector<std::pair<int,int> > vertexParent;
    std::vector<std::pair<int,int> > edgeParent;
    std::vector<std::pair<int,int> > faceParent;
  };


  struct HblInput {
    BrepMesh Q;
    std::vector<double> edgeDihedralAngle;
    std::vector<double> vertexSolidAngle;
    std::vector<std::array<double,3> > vertexNormals;

    /* Topological preferences (from geometry by default) */
    std::vector<double> edgeHexValIdeal;
    std::vector<double> vertexHexValIdeal;
  };

  struct HblOutput {
    std::vector<int> hexValence;
    std::vector<const DTriangulation*> trgls;

    HexToBoundaryMeshMatching h2q;
    BrepMesh H;

    std::vector<id8> hexahedra; /* final hexa, with coherent ordering */
    std::vector<id4> tetrahedra; /* final hexa, with coherent ordering */

    std::vector<bool> configIsIdeal; /* for each initial boundary vertex in Q */

    std::vector<id> QvertTangled;

    HblStats stats;
  };

  GEntity* getEntity(const BrepMesh& H, size_t v, const HexToBoundaryMeshMatching& h2q, const BrepMesh& Q);

  bool solveAllHexBoundaryLayerProblem(
      const HblInput& input,
      const HblOptions& opt,
      HblOutput& output);
}
