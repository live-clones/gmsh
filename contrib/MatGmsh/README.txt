MatGmsh: native filtered medial-axis pipeline
============================================

This optional module extracts the active MatGmsh pipeline into Gmsh. It does
not import the old standalone application, quad meshing, surface fitting or
experimental alternative pipelines. The source provenance and hashes are in
core/SOURCE_PROVENANCE.txt and core/extraction-manifest.json.

Stages
------

1. A closed, surface-only first-order triangular skin supplies the sites. Gmsh's HXT
   Delaunay implementation builds the tetrahedra. By default the raw MAT is
   the dual of the interior tetrahedra and the filter is the collapse by
   erosion thickness: see "Tetrahedron-based raw MAT and collapse filter"
   below. In the legacy stage 1 (--raw legacy; RawMode 0 and FilterMode 0),
   the dual polygons are classified using discreteCADModeler's winding
   numbers, then the existing branch decision tree, mixed-wing and terminal
   filters. Shared MAT vertex identities and junction incidence are retained.

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

Tetrahedron-based raw MAT and collapse filter
---------------------------------------------

The default stage 1 since 26 November 2026: --raw tet --filter collapse
(driver), RawMode 1 and FilterMode 1 (plugin). The legacy stage 1 is selected
with --raw legacy (driver) or RawMode 0 and FilterMode 0 (plugin).

Sites. Only the nodes used by a skin triangle are sites (also true of the
legacy stage 1): nodes of construction curves or points are ignored.

Raw MAT. A Delaunay tetrahedron is interior if and only if its exact volume
is nonzero and the integer winding number of the skin at its barycentre is
odd (signed ray crossings with exact predicates, no tolerance). A barycentre
in contact with the skin, exactly or within the roundoff of its own
evaluation, makes the tetrahedron exterior; these cases are counted. A dual
face is kept if and only if every tetrahedron around its Delaunay edge is
interior. Coincident circumcentres are not merged in this complex; they are
merged, and triangles of zero area left out, in the output meshes only.

Certificate. The boundary of the union of the interior tetrahedra must be a
closed oriented manifold through every site, with the Euler characteristic of
the skin; every kept dual face must be a simple cycle; the dual complex must
have half the Euler characteristic of the skin. report.json records all the
counts under "tet", and "certified". A failed certificate does not stop the
calculation: it adds a warning, and the result must not be trusted.

Filter. The erosion thickness of a polygon is the time at which a fire lit on
the free boundary of the raw MAT reaches it, minus its radius; an edge shared
by k polygons lets the fire through once k - 1 of them have burned. A polygon
with a free edge is removed, together with that edge, if its erosion
thickness is below --collapse-threshold (default 0.21) times the thickness,
or if it belongs to a convex wing: polygons whose nearest common CAD curve is
a convex edge, connected to a free edge that touches that curve. These
elementary collapses keep the homotopy type of the raw MAT. report.json
records under "collapse" the wings, the removed and blocked polygons, the
topology of the kept surface, and "wire_edges": edges left without surface,
which mean that the kept surface alone has lost the topology of the solid.

Which thickness to give. A convex wing is recognized as such only when the two
contacts of its polygons lie on two patches of CAD faces that share a sharp
convex curve. The other wings (rounded edges, free-form faces, contacts on CAD
curves) are removed by the erosion rule alone, whose threshold is a fraction
of the thickness given: the wing of a right-angled edge of a wall of thickness
e has an erosion thickness of up to 0.207 e. The thickness must therefore be
that of the thickest wall, with some margin, or the wings of the thicker walls
stay; the price is that thinner walls lose a band of their own mid-surface
along their free edges (see VALIDATION.txt for the Doghouse). gmshMat, the
plugin and the tool window have no default thickness.

Whole wing branches (--wing-branches, the box "Remove whole wing branches" of
the tool window; off by default, not yet run on the corpus). A branch of the
raw MAT is a set of polygons connected through edges of exactly two polygons.
A branch that touches the free boundary of the raw MAT, and at least half of
whose area is made of polygons whose two sites are seen from the centroid
under less than 135 degrees, is a wing: all its polygons are removed like the
convex wings, whatever their erosion thickness, by the same collapses. The
mid-sheet of two facing walls is seen under 180 degrees and is kept even when
it has a free boundary (rounded edges). report.json records "branches",
"wing_branches" and "branch_wing_polygons". Use it with --collapse-threshold 0
(the tool window does so when the box is ticked): the mid-sheets then end
exactly on the lines where the wings were attached, whereas a positive
threshold also removes polygons of the mid-sheets along these lines and
notches them.

The convexity of a CAD edge needs the material side of the skin. It is taken,
shell by shell, from the interior tetrahedra, so closed cavities and
assemblies of several solids are handled.

--complex writes the dual complex to <output>/complex as NumPy arrays (one
.npy file per array, described by complex.json): sites, skin triangles,
tetrahedra, circumcentres, polygons as cycles of tetrahedron ids with their
site pair, CAD faces of each site and patch of each face; with the collapse
filter also centroid, radius, area, erosion thickness over thickness, and the
keep and wing flags of each polygon. All indices are zero-based.

--filter none stops at the raw MAT. The legacy filter needs the legacy raw
MAT and the collapse filter the tetrahedron-based one; the driver selects
both legacy modes when only one of --raw legacy and --filter legacy is given.
Projection and extension (stages 2 and 3) accept either filtered MAT; their
validation (VALIDATION.txt) was done on the legacy one.

Build from the Gmsh root
------------------------

  cmake -S . -B build -DENABLE_MATGMSH=ON \
    -DENABLE_DISCRETECAD=ON -DENABLE_HXT=ON -DENABLE_EIGEN=ON \
    -DENABLE_BUILD_SHARED=ON -DENABLE_BUILD_DYNAMIC=ON -DENABLE_TESTS=ON
  cmake --build build --target gmsh gmshMat -j 6

ENABLE_MATGMSH defaults to OFF. Boost headers are needed for the certified
circumcenter fallback. This module does not require libigl or CGAL. CAD input
and CAD projection require the corresponding Gmsh CAD backend, normally OCC.
The driver is built when a shared or static Gmsh library target is enabled.

Driver
------

  build/gmshMat benchmarks/MAT/Doghouse.geo --thickness 4 \
    --project --stage projected --output doghouse-mat

  build/gmshMat benchmarks/MAT/Doghouse.stp --thickness 4 \
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

Every message of the module goes through Gmsh's message system (Msg::Info,
Msg::Warning and Msg::Error in the library and the plugin, the API logger in
gmshMat), so General.Verbosity, General.Terminal and the message console
apply; nothing is written directly to standard output. The diagnostic lines
with many fields are composed with the stream of core/matMessage.h, which
sends each line to Msg::Info. Only the usage text of gmshMat, printed before
Gmsh is initialized, goes to standard error.

For controlled old/new comparisons, both runs must reload the same cached
source.msh: even an ASCII coordinate round trip can change a nearly
cospherical Delaunay triangulation. --source-mesh is merged with the CAD to
retain support queries. A standalone .msh has no implicit CAD geometry:
without parametrized faces, identity support patches are used and optional
CAD projection is skipped with an explicit message.

With the legacy filter, the default cleanup intentionally retains the
historical largest component and closed-sheet removal policy for comparison.
--keep-components selects a different policy retaining disconnected
components and closed sheets. This is not yet a certification of all
multi-solid configurations. The collapse filter has no such cleanup.

Gmsh plugin
-----------

Mesh the current model's surfaces, then run Plugin(MatGmsh). Thickness,
Project, Stage (0 filtered, 1 projected, 2 extended), ExtensionLength,
ExtensionLayers, ShowStages, LegacyCleanup, RawMode (1 tetrahedra, the
default; 0 legacy), FilterMode (1 collapse, the default; 0 legacy; 2 none)
and CollapseThreshold are numeric options.
OutputPrefix sets optional checkpoint file output (empty disables it).
The plugin creates branch-colored views for each stage and initially shows
the last stage. The source CAD and surface mesh are retained. For example:

  Mesh 2;
  Plugin(MatGmsh).Thickness = 4;
  Plugin(MatGmsh).Project = 1;
  Plugin(MatGmsh).Stage = 1;
  Plugin(MatGmsh).OutputPrefix = "doghouse";
  Plugin(MatGmsh).Run;

Midsurfacer tool window
-----------------------

In the graphical interface, Tools > Midsurfacer opens a tool window
(src/fltk/midsurfacerWindow.cpp) that docks in the main window like the other
tools. It runs the pipeline one stage at a time, on the current model:

  Thickness       of the thickest wall, common to all the stages; it has
                  no default
  1. Skin         Mesh: first-order surface mesh of the given size (0 for a
                  tenth of the thickness); the next stages use the surface
                  mesh of the model, whoever made it
  2. Medial axis  Compute: the raw MAT; method Tetrahedra (the default, with
                  its certificate) or Legacy
  3. Filter       Filter: collapse with the given threshold (or the legacy
                  filter, with the legacy method)
  4. Projection   Project: optional; a projection that fails its checks
                  changes nothing
  5. Extension    Extend: of the projected MAT if there is one, of the
                  filtered one otherwise

A button first runs the earlier stages that are missing or out of date: with a
CAD model just opened, Filter meshes the skin, computes the raw MAT and
filters it. Each stage says what it gave on its line (details in its tooltip
and in the messages) and leaves a view, "MAT raw", "MAT filtered", "MAT
projected" or "MAT extended", colored by sheet. The boxes of the Show row show
and hide these views and the skin mesh; a stage that has just run is shown
alone, without the skin that would hide it.

The raw MAT is kept between the stages: changing the threshold and pressing
Filter again does not compute the tetrahedrization again (Doghouse, thickness
4, mesh size 0.4, one thread: 6.1 s for the raw MAT, then 0.8 s for each
filter). It is computed again when asked for, and when the model, its surface
mesh or the method has changed.

Stage by stage in C++
---------------------

matgmsh_native::Session (MatPipeline.h) is what the window drives: raw(),
filter(), project() and extend() on a model, each needing the ones before it;
a stage run again discards the results of the later ones, and filter() and
project() refuse a model whose surface mesh is not the one given to raw().
compute() runs these stages in a row and gives the same meshes and report as
before (byte-identical files on the cases checked, see VALIDATION.txt). The
legacy filter changes the raw MAT in place, so the session computes the legacy
raw MAT again when that filter is run a second time.

Validation
----------

  cmake --build build --target MatProjectionTest MatExtensionTest \
    MatClassifierTest MatMixedFilterTest MatTerminalFilterTest \
    MatCircumcenterTest MatIntersectionTest MatSkinSitesTest \
    MatTetInteriorTest MatCollapseTest -j 6
  ctest --test-dir build -R '^mat_native_' --output-on-failure
  python3 contrib/MatGmsh/tests/check_native_outputs.py doghouse-mat \
    --stage projected --project
  python3 contrib/MatGmsh/tests/check_app_plugin_smoke.py \
    --gmsh build/gmsh --output native-plugin-smoke

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
