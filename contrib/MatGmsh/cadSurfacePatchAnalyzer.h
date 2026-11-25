#pragma once

#include <map>
#include <set>
#include <string>
#include <vector>

class GEdge;
class GFace;
class GModel;

class CadSurfacePatchAnalyzer {
public:
  struct Options {
    int samplesPerEdge = 8;
    double minAbsNormalDot = 0.985;
    // Tangency used to assemble the mechanical support patches. This is kept
    // stricter than the legacy C1 threshold so a shallow crease does not
    // percolate through a large support patch.
    double supportPatchMinAbsNormalDot = 0.9995;
    // Relative jump allowed for the normal curvature in the surface direction
    // orthogonal to the common edge. This separates tangent fillets from planes.
    double maxRelativeTransverseCurvatureJump = 0.25;
    double curvatureNoiseFloor = 1.e-9;
    bool useCurvatureCompatibility = true;
  };

  struct Transition {
    int edgeTag = -1;
    int faceA = -1;
    int faceB = -1;
    int incidentFaceCount = 0;
    double minAbsNormalDot = 0.0;
    double maxRelativeTransverseCurvatureJump = 0.0;
    bool accepted = false;
  };

  struct Result {
    std::map<int, int> patchByFaceTag;
    // A support surface has one patch. An analytic fillet belongs to every
    // support patch that it connects, so this is intentionally an overlapping
    // cover rather than a partition.
    std::map<int, std::set<int>> patchesByFaceTag;
    std::vector<std::vector<int>> faceTagsByPatch;
    std::set<int> filletFaceTags;
    std::vector<std::vector<int>> filletFaceTagsByComponent;
    std::vector<Transition> transitions;
  };

  CadSurfacePatchAnalyzer();
  explicit CadSurfacePatchAnalyzer(Options options);

  Result analyze(GModel *model) const;
  Result analyzeCurrentModel() const;

private:
  Options options;

  double edgeNormalCompatibility(GEdge *edge, GFace *a, GFace *b) const;
};
