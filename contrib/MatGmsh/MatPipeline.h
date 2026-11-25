// Native filtered MAT pipeline. Source geometry and all mesh indices are kept
// separate from GModel entity tags; junction vertices have one global identity.
#ifndef GMSH_MAT_PIPELINE_H
#define GMSH_MAT_PIPELINE_H

#include <cstddef>
#include <string>
#include <vector>
#include "gmsh.h"
#include "core/MatCollapse.h"

class GModel;

namespace matgmsh_native {

struct Mesh {
  std::vector<double> xyz;
  std::vector<int> triangles;
  std::vector<int> branch; // one branch per triangle
  std::vector<int> parent; // original polygon/triangle, -1 for new material
};

enum class Stage { Filtered, Projected, Extended };

// Raw MAT. Legacy: dual faces whose circumcentres have a winding number above
// the threshold, coincident circumcentres merged. Tet: dual faces of the
// Delaunay edges surrounded by interior tetrahedra only (integer winding at
// the barycentre), with a certificate of the boundary of their union.
enum class RawMode { Legacy, Tet };
// Legacy: branch classification by CAD patches. Collapse: erosion thickness
// and homotopy-preserving collapse (needs RawMode::Tet). None: the raw MAT.
enum class FilterMode { Legacy, Collapse, None };

struct Options {
  double thickness = 1.;
  double windingThreshold = .5;
  RawMode raw = RawMode::Legacy;
  FilterMode filter = FilterMode::Legacy;
  // FilterMode::Collapse: polygons with an erosion thickness below this
  // fraction of the thickness are removed.
  double collapseThreshold = .21;
  bool project = false;
  bool legacyCleanup = true;
  Stage stopAfter = Stage::Filtered;
  double extensionLength = 0.; // zero means 3 * thickness
  int extensionLayers = 12;
};

struct Topology {
  std::size_t vertices = 0, triangles = 0, components = 0;
  std::size_t freeEdges = 0, junctionEdges = 0;
  long long euler = 0;
};

struct FrontStatus {
  int a = -1, b = -1, branch = -1;
  std::string status; // already_on_skin, reached_skin, reached_sheet, unresolved
  std::string reason;
};

struct ExtensionReport {
  std::vector<FrontStatus> fronts;
  std::size_t addedTriangles = 0;
  bool complete = false;
  std::string message;
};

struct Result {
  Mesh skin, raw, filtered, projected, extended;
  Topology filteredTopology;
  matgmsh::tet::Report tet;              // RawMode::Tet only
  matgmsh::tet::CollapseReport collapse; // FilterMode::Collapse only
  std::string projectionStatus = "disabled";
  std::string projectionMessage;
  ExtensionReport extension;
  double rawSeconds = 0., filterSeconds = 0., projectionSeconds = 0.;
  double extensionSeconds = 0.;
  std::vector<std::string> warnings;
};

// Consume the current model's existing first-order surface mesh. The caller
// retains ownership of the CAD and chooses its mesh sizing separately.
GMSH_API bool compute(GModel *source, const Options &options, Result &result,
             std::string &error);
GMSH_API bool computeCurrent(const Options &options, Result &result,
                            std::string &error);

GMSH_API Topology topology(const Mesh &mesh);
GMSH_API bool validateMesh(const Mesh &mesh, std::string &error);
// Exact final-configuration intersection check, including coplanar overlaps;
// shared indexed vertices/edges at sheet junctions are valid. No swept check.
GMSH_API bool validateNoSelfIntersections(const Mesh &mesh, std::string &error);
// Co-refine against the closed skin and verify every original triangle remains
// inside, with its area preserved. The input mesh is never changed.
GMSH_API bool validateContainedInSkin(const Mesh &mesh, const Mesh &skin,
                                    std::string &error);
GMSH_API bool writeMesh(const Mesh &mesh, const std::string &filename,
               std::string &error);
GMSH_API bool writeReport(const Result &result, const Options &options,
                 const std::string &filename, std::string &error);

// Optional stages propose changes to a copy. On failure their input remains
// usable. A partial extension is reported explicitly for every original front.
GMSH_API bool extend(const Mesh &input, const Mesh &skin, const Options &options,
            Mesh &output, ExtensionReport &report, std::string &error);

} // namespace matgmsh_native
#endif
