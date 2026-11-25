#pragma once
#include <array>
#include <chrono>
#include <cstddef>
#include <iosfwd>
#include <map>
#include <set>
#include <string>
#include <vector>
#include "matGmshEdge.h"
#include "matLargestConnectedComponent.h"

struct MatNativeAccess;
class matGmsh {
  friend struct MatNativeAccess;
public:
  matGmsh() = default;
  void computeVoronoi();
  void setVoronoiSurfaceMeshInput(const std::string &filename) { voronoiSurfaceMeshInput = filename; }
  void computeVoronoiWindingNumbersAtCircumcenters(int order = 2, float accuracyScale = 2.f, bool useDoublePrecision = false);
  void colorVoronoiFaces(double threshold);
  void rebuildFilteredTopology(bool preserveExistingBranches = true);
  void projectRegularBranchVerticesToLocalMidSurface(int iterations = 8, double relativeTolerance = 1.e-8, const std::map<int, std::set<int>> *patchesByCadFaceTag = nullptr, bool storeDiagnostics = true);
  void projectRegularBranchVerticesToLocalMidSurfacePasses(int passes, int iterations = 8, double relativeTolerance = 1.e-8, const std::map<int, std::set<int>> *patchesByCadFaceTag = nullptr, bool storeDiagnostics = true);
  matLargestConnectedComponent::Statistics rebuildConnectedComponentsPerColor(const std::vector<int> &unfilteredFaceColors, const std::map<int, int> &branchClasses);
  matLargestConnectedComponent::Statistics rebuildFinalSurfaceTopology(bool preserveNonOrientable = false);
  std::size_t discardClosedRetainedSurfaces();
  struct BranchClassificationPolicy {
    bool applyManualOverrides, restoreStrongMedialSheets, restoreEnclosedBranches, restoreWingClosureCaps;
    BranchClassificationPolicy(bool manual = false, bool strongSheets = false, bool enclosed = false, bool wingClosureCaps = true)
      : applyManualOverrides(manual), restoreStrongMedialSheets(strongSheets), restoreEnclosedBranches(enclosed), restoreWingClosureCaps(wingClosureCaps) {}
  };
  struct MixedBranchZoneSummary {
    int id = -1, rawBranch = -1, firstPatch = -1, secondPatch = -1, classification = 3;
    std::size_t faceCount = 0;
    double area = 0.;
  };
  void filterVoronoiBranchesByClassification(const std::string &classificationPosFile, const std::string &classificationCsvFile, std::ostream *report = nullptr, std::map<int, int> *effectiveClasses = nullptr, BranchClassificationPolicy policy = BranchClassificationPolicy(), std::map<int, int> *wingClosureCapMergeTargets = nullptr);
  std::size_t filterMixedBranchWings(const std::string &diagnosticFilename, const std::vector<int> &unfilteredFaceColors, const std::map<int, std::set<int>> &patchesByCadFaceTag, std::ostream *report = nullptr, std::vector<int> *zoneByFace = nullptr, std::set<int> *hybridBranches = nullptr, std::vector<MixedBranchZoneSummary> *zoneSummaries = nullptr);
  std::size_t reportSmallTerminalBranches(const std::vector<int> &unfilteredFaceColors, std::ostream &report) const;
  std::size_t filterSmallTerminalBranches(const std::vector<int> &unfilteredFaceColors, std::ostream *report = nullptr);
  std::map<int, int> restoreSewnClosureDisks(const std::vector<int> &unfilteredFaceColors, std::ostream *report = nullptr);
  void addTimingSample(const std::string &name, std::chrono::nanoseconds duration) const;
  std::vector<int> snapshotVoronoiFaceColors() const;
  void restoreVoronoiFaceColors(const std::vector<int> &faceColors);
private:
  std::size_t processMixedBranchSegmentation(const std::string &diagnosticFilename, const std::vector<int> &unfilteredFaceColors, const std::map<int, std::set<int>> &patchesByCadFaceTag, bool removeDetectedWings, double thetaHmaAngleDegrees, const std::string &thetaHmaTripleLineDiagnosticFilename, bool applyTripleLineCorridors, std::ostream *report, std::vector<int> *zoneByFace = nullptr, std::set<int> *hybridBranches = nullptr, const std::string &hybridTripleLineDiagnosticFilename = "", std::vector<MixedBranchZoneSummary> *zoneSummaries = nullptr);
  struct TimingEntry { std::chrono::nanoseconds total{0}; std::size_t calls = 0; };
  class ScopedTimer {
  public:
    ScopedTimer(const matGmsh &owner, const std::string &name);
    ~ScopedTimer();
  private:
    const matGmsh &owner;
    std::string name;
    std::chrono::steady_clock::time_point start;
  };
  bool voronoiVertexIsInterior(std::size_t vertex, double windingThreshold) const;
  std::size_t inspectSmallTerminalBranches(const std::vector<int> &unfilteredFaceColors, std::ostream &report, std::vector<std::size_t> *removableFaces) const;

  struct Delaunay {
    std::vector<size_t> nodeTags;
    std::vector<double> seeds;
    std::vector<std::pair<int, int> > onWhat;
    std::vector<std::vector<int>> seedFaces;
    std::vector<size_t> triangles;
    std::vector<size_t> tetrahedra;
    // Model nodes used by no skin triangle; they are not sites.
    std::vector<size_t> unreferencedNodeTags;
  };
  std::string voronoiSurfaceMeshInput;

  struct VoronoiFace {
    matGmshEdge edge;          // arête duale (i,j)
    std::vector<int> verts;    // indices des sommets Voronoi (= ids de tétras)
    VoronoiFace(matGmshEdge e, std::vector<int> &v) :
      edge(e), verts(v){}
  };

  struct Voronoi {
    std::vector<double> vertices; // xyz xyz ...
    std::vector<VoronoiFace> faces;
    std::vector<double> winding;
    bool windingAtCircumcenters = false;
    std::vector<int> faceColors;
  };

  Delaunay del;
  Voronoi vor;
  mutable std::map<std::string, TimingEntry> timings;
  std::set<matGmshEdge> preservedFilteredTopologyEdges;
  struct LocalMidSurfaceProjectionDiagnostic {
    std::array<double, 3> original = {0.0, 0.0, 0.0};
    std::array<double, 3> rawRequested = {0.0, 0.0, 0.0};
    std::array<double, 3> preSplineRequested = {0.0, 0.0, 0.0};
    std::array<double, 3> filteredRequested = {0.0, 0.0, 0.0};
    std::array<double, 3> accepted = {0.0, 0.0, 0.0};
    std::array<double, 3> midSurfaceNormal = {0.0, 0.0, 0.0};
    std::array<double, 3> repeatedSourceContactA = {0.0, 0.0, 0.0};
    std::array<double, 3> repeatedSourceContactB = {0.0, 0.0, 0.0};
    double acceptedFraction = 0.0;
    double meanSurfaceDistance = 0.0;
    bool projectionCandidate = false;
    bool surfaceClassifiedOpposites = false;
    bool simpleBoundary = false;
    bool tripleLine = false;
    bool repeatedCadSourcePair = false;
    bool tripleSplineTarget = false;
  };
  std::map<int, LocalMidSurfaceProjectionDiagnostic>
      localMidSurfaceProjectionDiagnostics;

  void createVoronoiSeeds();
  void computeVoronoiVertices();
  void orientSurfaceTriangles();
  void projectRegularBranchVerticesToLocalMidSurfaceImpl(int iterations, double relativeTolerance, const std::map<int, std::set<int>> *patchesByCadFaceTag, bool storeDiagnostics, void *sharedContext);
};
