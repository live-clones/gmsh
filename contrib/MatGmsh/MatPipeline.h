// Native filtered MAT pipeline. Source geometry and all mesh indices are kept
// separate from GModel entity tags; junction vertices have one global identity.
#ifndef GMSH_MAT_PIPELINE_H
#define GMSH_MAT_PIPELINE_H

#include <cstddef>
#include <memory>
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

// Raw MAT. Tet (default): dual faces of the Delaunay edges surrounded by
// interior tetrahedra only (integer winding at the barycentre), with a
// certificate of the boundary of their union. Legacy: dual faces whose
// circumcentres have a winding number above the threshold, coincident
// circumcentres merged.
enum class RawMode { Legacy, Tet };
// Collapse (default): erosion thickness and homotopy-preserving collapse
// (needs RawMode::Tet). Legacy: branch classification by CAD patches (needs
// RawMode::Legacy). None: the raw MAT.
enum class FilterMode { Legacy, Collapse, None };

struct Options {
  double thickness = 1.;
  double windingThreshold = .5;
  RawMode raw = RawMode::Tet;
  FilterMode filter = FilterMode::Collapse;
  // FilterMode::Collapse: polygons with an erosion thickness below this
  // fraction of the thickness are removed.
  double collapseThreshold = .21;
  // FilterMode::Collapse: the branches of the raw MAT that touch its free
  // boundary and are wings (see matgmsh::tet::branchWings) are removed whole,
  // whatever their erosion thickness.
  bool wingBranches = false;
  // RawMode::Tet: if nonempty, the dual complex and its attributes are written
  // to this directory as NumPy arrays (see README.txt).
  std::string complexDirectory;
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
// The current model, for the callers that only see the API.
GMSH_API GModel *currentModel();

// The pipeline one stage at a time, for interactive use. The raw MAT is kept
// between the calls: the filter can be run again with another threshold, and
// the projection and the extension run or run again, without a new Delaunay
// tetrahedrization. compute() is these stages in a row.
//
// Each stage needs the ones before it, and running a stage again discards
// the results of the later ones. filter() and project() refuse a model whose
// surface mesh is not the one given to raw().
class GMSH_API Session {
public:
  Session();
  ~Session();
  Session(const Session &) = delete;
  Session &operator=(const Session &) = delete;
  // Raw MAT of the first-order triangular surface mesh of the model
  // (options: thickness, raw, windingThreshold).
  bool raw(GModel *source, const Options &options, std::string &error);
  // Filtered MAT (options: thickness, filter, collapseThreshold,
  // legacyCleanup, complexDirectory). The legacy filter changes the raw MAT
  // in place: running it again computes the raw MAT again.
  bool filter(GModel *source, const Options &options, std::string &error);
  // Projection of the filtered MAT if options.project is set; a projection
  // that is refused keeps the filtered MAT, and says why in the result.
  bool project(GModel *source, const Options &options, std::string &error);
  // Extension of the projected MAT (of the filtered one if project() was not
  // called) to the skin (options: thickness, extensionLength,
  // extensionLayers). A failed extension keeps its input and is reported in
  // the result.
  bool extend(GModel *source, const Options &options, std::string &error);
  bool hasRaw() const;
  bool hasFiltered() const;
  bool hasProjected() const;
  bool hasExtended() const;
  // The meshes and reports of the stages available.
  const Result &result() const;
  // The same, moved out of the session, which is left empty.
  Result take();

private:
  struct Data;
  std::unique_ptr<Data> data_;
};

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
