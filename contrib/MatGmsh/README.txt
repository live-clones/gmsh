MatGmsh: native filtered medial-axis pipeline
============================================

This optional module extracts the active MatGmsh pipeline into Gmsh. It does
not import the old standalone application, quad meshing, surface fitting or
experimental alternative pipelines. The source provenance and hashes are in
core/SOURCE_PROVENANCE.txt and core/extraction-manifest.json.

Stages
------

1. A closed, surface-only first-order triangular skin supplies the sites. Gmsh's HXT
   Delaunay implementation builds the tetrahedra. Their dual polygons are
   classified using discreteCADModeler's winding numbers, then the existing
   branch decision tree, mixed-wing and terminal filters. Shared MAT vertex
   identities and junction incidence are retained.

2. Optional local projection uses the existing CAD-support method. It must
   preserve triangles, branch labels and polygon provenance. The proposal
   is checked for self-intersections using the discrete modeler's exact
   predicates, and for containment by co-refining it with the source skin
   and checking its descendants. A rejected or unavailable projection keeps the exact filtered
   input. This is a check on the final geometry, not a swept-motion check.

3. Free edges (global incidence one, excluding junction edges) initiate
   connected short collars with regularized boundary directions. Neighboring
   collars share tip vertices and are proposed together. Spatial queries select
   nearby deposited triangles and skin triangles for native open co-refinement.
   The whole proposed collar is intersected, not just its moving edge.

   A finite contact casts a shadow in the local propagation coordinates.
   Selective auxiliary cuts through contact endpoints split blocked and still
   active pieces; the auxiliary triangles never enter the result. Coplanar
   competing collars are divided by an affine equal-normal-advance cut. This is a
   declared growth policy, not a proof of a unique geometric midsurface.

   Original and previously deposited triangle area/provenance are checked;
   every fixed triangle must retain descendants. Accepted layers pass the
   exact self-intersection audit and an extension-specific containment audit
   using non-collapsing open co-refinement. This is containment within a
   numerical envelope, not strict exact containment of the exported doubles.
   A positive-area exterior descendant must have all three vertices within
   coordinate roundoff of ONE common skin triangle, whose neighborhood is
   convex. The radius is eight times the Euclidean norm of the coordinate
   ULPs. Exterior area is additionally capped per source triangle using its
   coordinate-perturbation area bound, independently of subdivision count.
   The existing stricter projection guard remains unchanged.
   Contact-status and root/seam classification separately retain the existing
   geometric tolerance, 1e-8 times max(thickness, skin bounding-box diagonal).
   This is not the containment-envelope tolerance and does not weld vertices.

   A rejected layer preserves preceding accepted layers. Self-intersecting
   collars are rejected locally and the layer is retried (at most four
   attempts); safe neighboring fronts may continue. Every initial free edge
   has a status; a propagation bound or an interior lateral boundary remains
   unresolved. A partial contact can retain useful partial growth even if no
   original edge has completely terminated. Without any real contact, the
   original input is retained exactly.

   This extension remains experimental. Direction extrapolation is unchanged;
   folds, unresolved side fronts and rounded intersection slivers can still
   stop propagation. Local co-refinement rebuilds its index each layer; there
   is not yet a persistent event queue or an incremental Boolean data structure.
   Partial results must not be mistaken for completed midsurfaces.

No independent reference midsurface or benchmark name enters these stages.
The thickness option is a user-supplied scale, not an estimated measurement:
it supplies the default surface mesh size (h/10) and extension bound (3 h).

Build from the Gmsh root
------------------------

  cmake -S . -B build-mat -DENABLE_MATGMSH=ON \
    -DENABLE_DISCRETECAD=ON -DENABLE_HXT=ON -DENABLE_EIGEN=ON \
    -DENABLE_BUILD_SHARED=ON -DENABLE_BUILD_DYNAMIC=ON -DENABLE_TESTS=ON
  cmake --build build-mat --target gmsh gmshMat -j 6

ENABLE_MATGMSH defaults to OFF. Boost headers are needed for the certified
circumcenter fallback. This module does not require libigl or CGAL. CAD input
and CAD projection require the corresponding Gmsh CAD backend, normally OCC.
The driver is built when a shared or static Gmsh library target is enabled.

Driver
------

  build-mat/gmshMat benchmarks/MAT/Doghouse.geo --thickness 4 \
    --project --stage projected --output doghouse-mat

  build-mat/gmshMat benchmarks/MAT/Doghouse.stp --thickness 4 \
    --source-mesh doghouse-mat/source.msh --project --stage extended \
    --extension-length 12 --extension-layers 12 --output doghouse-extended

For newly generated skins, a positive --mesh-size overrides the input sizing.
Otherwise the driver preserves Mesh.MeshSizeMin/Max when opening the input
changes either bound; without such settings, both bounds default to h/10.
Generated skins use first-order triangles. The benchmark GEO files set the
current denser sizes: 0.3 for Doghouse and Sample2/3/4, and 0.175 for the four
manufactured cases. Opening the STEP directly uses h/10 unless --mesh-size
is supplied. Existing surface meshes, including --source-mesh checkpoints,
are reused without remeshing regardless of these sizing options.

The output directory must not already exist. Exit codes: 0 for a successful
requested stage, 2 for a partial extension with saved checkpoints, 1 for an
error. Stage defaults to filtered; projection defaults to disabled. Each
available MAT stage is saved as an ASCII MSH2 file. The source mesh is saved
as binary MSH4 with all faces, even if physical groups cover only part of the
skin. Triangle physical/elementary
tags encode branch+1, and the MAT parent ElementData records the original
Voronoi polygon (-1 denotes an extension triangle). report.json includes
timings, topology, projection status and the extension front ledger.

For controlled old/new comparisons, both runs must reload the same cached
source.msh: even an ASCII coordinate round trip can change a nearly
cospherical Delaunay triangulation. --source-mesh is merged with the CAD to
retain support queries. A standalone .msh has no implicit CAD geometry:
without parametrized faces, identity support patches are used and optional
CAD projection is skipped with an explicit message.

The default legacy cleanup intentionally retains the historical largest
component and closed-sheet removal policy for comparison. --keep-components
selects a different policy retaining disconnected components and closed
sheets. This is not yet a certification of all multi-solid configurations.

Gmsh plugin
-----------

Mesh the current model's surfaces, then run Plugin(MatGmsh). Thickness,
Project, Stage (0 filtered, 1 projected, 2 extended), ExtensionLength,
ExtensionLayers, ShowStages and LegacyCleanup are numeric options.
OutputPrefix sets optional checkpoint file output (empty disables it).
The plugin creates branch-colored views for each stage and initially shows
the last stage. The source CAD and surface mesh are retained. For example:

  Mesh 2;
  Plugin(MatGmsh).Thickness = 4;
  Plugin(MatGmsh).Project = 1;
  Plugin(MatGmsh).Stage = 1;
  Plugin(MatGmsh).OutputPrefix = "doghouse";
  Plugin(MatGmsh).Run;

Validation
----------

  cmake --build build-mat --target MatProjectionTest MatExtensionTest \
    MatClassifierTest MatMixedFilterTest MatTerminalFilterTest \
    MatCircumcenterTest MatIntersectionTest -j 6
  ctest --test-dir build-mat -R '^mat_native_' --output-on-failure
  python3 contrib/MatGmsh/tests/check_native_outputs.py doghouse-mat \
    --stage projected --project
  python3 contrib/MatGmsh/tests/check_app_plugin_smoke.py \
    --gmsh build-mat/gmsh --output native-plugin-smoke

The Python checker uses only the standard library. It verifies topology,
coordinates, provenance and stage contracts; it does not establish medial
accuracy or absence of self-intersections. The C++ fixtures cover classifier
decisions, mixed and terminal branch filtering, certified circumcenters,
projection helpers and extension contacts. The eight source CAD cases live
in benchmarks/MAT. Full-case tests should additionally audit intersections
and compare geometric coverage with frozen results.

The application smoke test launches the actual Gmsh executable on a temporary
plate script, without importing its Python API. It checks that the plugin
creates its stage files and report, that binary source-mesh checkpoints before
and after the plugin are byte-identical, and that the log contains no Error
diagnostic even when the process exits with code zero. Its output directory
must be new; omit --output to retain artifacts in a new temporary directory.
