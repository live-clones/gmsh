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

Wings by their angle (--wing-branches, the box "Remove the wings by their
angle" of the tool window; off by default, not run on the corpus). Each
polygon of the raw MAT sees its two sites from its centroid under an angle:
90 degrees on the sheet that runs from a right-angled convex edge into the
material, 180 between two facing walls. A polygon under the angle given
(--wing-angle, 135 degrees by default) is a wing, removed like the convex
wings, whatever its erosion thickness and by the same collapses, in two cases:

  - it burns like the bisector of a wedge: its erosion thickness is at most
    one and a half times R (1 - cos(a/2)) / cos(a/2), the value on the
    bisector of a wedge where it is seen under the angle a, plus its own
    size. The strip of a mid-sheet along a junction is seen under a small
    angle too, but it burns late, from far away, and stays; near the ends of
    the junction it burns early, so the margins of the walls are left out:
    the sets of polygons under the angle, connected through the edges of two
    polygons, that touch polygons over the angle across such an edge and have
    less than a quarter of the length of their boundary free;
  - it belongs to a wing branch. A branch is a set of polygons connected
    through edges of exactly two polygons; it is a wing if it touches the
    free boundary of the raw MAT and nine tenths of its area is under the
    angle.

The mid-sheet of two facing walls is seen under 180 degrees and is kept even
when it has a free boundary (rounded edges). report.json records "branches",
"wing_branches", "wedge_polygons" (the first case) and "branch_wing_polygons"
(what the two cases add to the convex wings). Use it with --collapse-threshold
0 (the tool window does so when the box is ticked): the mid-sheets then end
where the wings were attached, whereas a positive threshold also removes
polygons of the mid-sheets along these lines and notches them.

Until 26 November 2026 a branch was a wing as soon as half of its area was
under the angle, and only whole branches were removed. A branch can hold a
wall and the wings that go on from it without a junction: on Sample3.stp the
web of the stiffener was removed with them, or the wings kept with it,
depending on the mesh size (VALIDATION.txt).

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

ENABLE_MATGMSH defaults to OFF. It needs nothing beyond Gmsh (HXT, the
discrete CAD modeler, Eigen): no Boost, libigl or CGAL. The exact fallback of
the circumcentres (core/matCircumcenter.cpp) works on integers of any size
(core/matExactInteger.h): the twelve coordinates times a common power of two
are integers, the cofactor formula is exact on them, and each coordinate is
the double nearest to a quotient (ties to even), found from an estimate
checked exactly against the midpoints. It gives the same doubles, bit for
bit, as the Boost rationals it replaces. The tetrahedron-based raw MAT only
computes the circumcentres of the interior tetrahedra (vertex_xyz of
--complex is NaN for the others); the legacy raw MAT computes them all. CAD input
and CAD projection require the corresponding Gmsh CAD backend, normally OCC.
The driver is built when a shared or static Gmsh library target is enabled.

Driver
------

  build/gmshMat benchmarks/MAT/Doghouse.geo --thickness 4 \
    --project --stage projected --output doghouse-mat

  build/gmshMat benchmarks/MAT/Doghouse.stp --thickness 4 \
    --source-mesh doghouse-mat/source.msh --project --stage extended \
    --extension-length 12 --extension-layers 12 --output doghouse-extended

--threads is the number of threads of the skin mesh and of the
classification of the tetrahedra (General.NumThreads); 0, the default, is
every core (or OMP_NUM_THREADS). The results do not depend on it.

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
  5. Extension    branch by branch or all at once (see below): the list of
                  the branches, Preview, Extend and Extend all
  6. Mesh         the extended MAT in a discrete model of its own, meshed by
                  Gmsh (see "Mesh of the mid-surface" below)

The Filter stage has, besides the threshold, the box "Remove the wings by
their angle" with its angle, and the box "Show the angle of the wings". Once
the medial axis is filtered, a change of the threshold, of the box or of the
angle filters it again at once (the raw MAT is kept) and shows the result.
"Show the angle of the wings" shows instead the raw MAT colored, in bands of
15 degrees, by the angle under which each polygon sees its two contacts, where
it burns like a wing or belongs to a wing branch (180 for the others): what is
below the angle given is what the box removes, except the margins of the walls
along the junctions.

A button first runs the earlier stages that are missing or out of date: with a
CAD model just opened, Filter meshes the skin, computes the raw MAT and
filters it. Each stage says what it gave on its line (details in its tooltip
and in the messages) and leaves a view, "MAT raw", "MAT filtered", "MAT
projected" or "MAT extended", colored by sheet. The boxes of the Show row show
and hide these views and the skin mesh; a stage that has just run is shown
alone, without the skin that would hide it, as soon as it has run: Extend all
pressed on a CAD model just opened shows the skin mesh, then the raw MAT, then
the filtered MAT, each while the next stage runs, then the extended MAT.

The raw MAT is kept between the stages: changing the threshold and pressing
Filter again does not compute the tetrahedrization again (Doghouse, thickness
4, mesh size 0.4: 2.2 s for Filter on a CAD model just opened, then 0.4 s for
each filter). It is computed again when asked for, and when the model, its
surface mesh or the method has changed. The skin mesh and the classification
of the tetrahedra run on every core, unless General.NumThreads asks for
another number of threads than its default, 1.

Extension branch by branch
--------------------------

A branch is the set of triangles of a MAT mesh with one sheet number. The
window lists the branches of the filtered MAT, largest first, with their area
and their flatness (the distance to the least-squares plane below which 95% of
the area lies; "flat" under a tenth of the thickness). A branch chosen in the
list is shown alone. It is extended in one of two ways (MatBranchPlane.cpp,
declared in MatPipeline.h):

In its plane (extendBranchInPlane), for a flat branch. A rectangle of the
plane around the whole skin is cut, by an exact co-refinement, by the
triangles of the skin and of the other branches that reach the plane; the
fragments that hold a triangle of the branch replace the branch, together with
the other branches lying in the same plane inside them (the two halves of a
flange under a web). The fragments are found with two triangles, then meshed
with a grid of a quarter of the thickness cut the same way. Preview shows the
fragments (0 on those kept) without changing anything.

A fragment goes on inside the walls the branch stands on, along them, between
their face and their mid-surface: beyond the two ends of a rib that stands on
a plate over a part of its length, for instance. To stop it where the branch
stops, the faces of the part are prolonged into the material. The section of
the skin by the plane is a set of closed lines; a face is a stretch of a line
that keeps its direction within 5 degrees, and a corner is where two faces
that follow each other make 40 to 135 degrees with the void inside the turn
(faces as short as the tolerance when they touch; faces of half the reach or
more when a fillet is between them). At a corner each of the two faces is
prolonged by a fence, a small strip across the plane that cuts the rectangle
like the skin does, when the three conditions hold:

  - it meets the sheet of another branch within the reach (the mid-surface of
    the wall it enters), and stops a tenth of the thickness after it;
  - less than a tenth of it runs on a sheet of the branch, or of a branch that
    goes with it: of the end face of a rib and of the face of the plate, the
    first one is prolonged, the second one would cut the rib from its foot;
  - no sheet of another branch runs along it within half the reach on the side
    of the other face: there the branch ends on a wall and has to reach its
    mid-surface.

Nothing is kept across another surface. The sheets of the other branches cut
the rectangle along the lines where they cross the plane; such a line can end
just short of the line or of the face of the skin it should end on, when the
branch it ended on has been replaced by its plane, which is not exactly where
its sheet was (the sheet of a wall, 0.07 short of the plane of the base in
Doghouse.stp). The fragment would then go around the end of the line: the foot
of a rib, inside the base, went on through the mid-surface of the wall to its
far face. The end of such a line is prolonged straight to the first line or
face of the skin within twice the tolerance, under the same condition on the
sheets of the branch (running along the border of a sheet does not count as
running on it). Prolonging these lines further, to anything within the reach,
was tried and is not done: next to a junction with fillets it cuts the plane
under the junction from the branch (see VALIDATION.txt).

What is still kept beyond is limited to what is within the reach of the
branch, as before. The message of the extension gives the number of corners,
of fences and of lines prolonged. tools/topology/branches_through.py reads the
file written by Save... and lists where a branch goes through another one. Limits: a step of the edge of the branch lower than half its
thickness, next to another wall, can lose a strip of that height; where the
sheet of the wall under the branch is not flat (junction with fillets, not
yet replaced by its plane), the branch stops on it and not on the mid-plane.

By a ribbon (branchRibbon, extendBranchByRibbon), for any branch. The ribbon
starts from the free boundary of the branch (the edges that no other triangle
shares, nor shared in the MAT before its branches were extended) and goes, for
the reach, in the direction tangent to the branch and normal to the boundary:
u along the boundary, v away from it. The map (u, v) -> x(u) + v d(u) folds
where the directions d turn towards each other faster than the boundary
advances (in a plane, with normal directions, where 1 - v k < 0, k being the
curvature of the boundary): there the directions are smoothed along the
boundary until nothing folds within the reach, and where no direction field
can avoid the fold (around a hole smaller than the reach) the ribbon is made
shorter. Preview shows the ribbon before it is cut, colored by v. Extend cuts
it by the skin, by the other branches and where it crosses itself, and adds to
the branch the pieces that have an edge on its boundary.

A row of the ribbon is the set of its points away from one vertex of the
boundary. Before the cut, a row that ends on the skin is shortened to a little
after the farthest of its end and of the ends of the rows beside it (beyond,
it is outside the part, or back in it further on). A row that does not end on
the skin (it meets nothing, or the sheet of another branch) is stopped where
it crosses the plane of the face of the skin that stops the nearest row that
does, if one is within its own length along the boundary: at the foot of a
wall that ends on a plate, the rows that start inside the plate would go on
inside it, along it. It is not stopped if it ends before on the sheet of
another branch, or less than half its length after on one that faces it (a
wall the branch ends on). The message gives the number of rows stopped.

Extend all, with the box "Extend all at once" ticked (the default), extends
every branch in one cut (extendAllBranches):

  1. each branch gets the surface that extends it, not cut by anything: the
     flat branches lying in one plane get the part of that plane within the
     reach of them, as a grid of a quarter of the thickness; another branch
     gets the ribbon along its free boundary (its rows stopped as above).
     View "MAT surfaces before the cut", colored by branch;
  2. these surfaces, the skin, the sheets of the branches that are not
     replaced (the branches that are not flat keep their sheet) and the faces
     of the part prolonged at its reentrant corners (those of a plane cut
     that plane only) are cut where they meet, all together, once;
  3. of each surface are kept the pieces attached to its branches (those that
     hold a triangle of them for a plane, those along the boundary for a
     ribbon) without crossing the skin, a sheet, or a kept piece of another
     surface. What the others keep is not known beforehand: the pieces are
     first found with every piece of the other surfaces taken as kept, then
     again with those that were kept, until nothing changes. With more cuts a
     surface keeps less, so the rounds 0, 2, 4... grow, the rounds 1, 3, 5...
     shrink, the first ones inside the second ones; when they end on two sets
     that give each other, the smaller one is taken (it never crosses a kept
     piece) and the message says so. View "MAT pieces after the cut", -1 on
     what is dropped.

The result does not depend on an order, a branch stops exactly on the surfaces
of the others, and the kept pieces share their vertices along the lines where
they meet (edges of three triangles: junctions again, where both branches are
extended; a branch that keeps its sheet is still not re-meshed).

A branch is also flat, here, when half of its area is within an eighth of the
tolerance of a plane (really flat: a curved sheet has little of its area that
close to any plane), the rest no further than half the reach from it and,
beyond the tolerance, within the reach of a junction of the MAT: a wall with
the cusps its sheet has along its junctions, where fillets put the junction
away from its mid-plane. Its plane is fitted on its flattest part, and it is
replaced whole, cusps included, by its plane: the other walls then stop on
that plane and not on the cusp.

With the box not ticked, Extend all does the flat branches in their plane,
largest first, then the others by ribbons, each one cut by the MAT as it is
then (the two ways one by one, repeated).

From the command line, gmshMat --extend-all does the same on the filtered MAT
(or on the projected one with --project), after the stages asked for:

  gmshMat part.step --thickness T --wing-branches --collapse-threshold 0 \
    --extend-all --output DIR

writes DIR/extended_all.msh, DIR/extended_all_classified.msh (the file of
Save...) and DIR/extended_all.json (surfaces, rounds, and for each surface
its areas, pieces, corners and fences). The tolerance is a tenth of the
thickness, the grid a quarter, the reach twice (or --extension-length), the
ribbons have --extension-layers rows. This is not --stage extended, the
earlier front-by-front extension.

In both cases it leaves as they are the branches of less than a hundredth of
the thickness squared: specks left by the filter, a few triangles that hang on
the rest by an edge and have no plane of their own (extended, each gives a
sheet in any direction through the others). They stay in the list and can be
extended one by one; all at once they do not cut either. The branches already
extended one by one stay as they are, and cut. The result is the view "MAT extended"; it is not made
conforming along the junctions, and the earlier front-by-front extension
(--stage extended of gmshMat) is no longer in the window. Undo takes back the
last extension (Extend, or the whole of Extend all; the last ten are kept) and
Reset all of them: the filtered MAT again. In the window the box "Remove the
wings by their angle" is ticked by default, with a threshold of 0; gmshMat and the
plugin keep the threshold of 0.21 without it, with which the corpus was
scored.

Save... writes the MAT as it is in the window (filtered, with the branches
extended so far) as an MSH 2.2 file (writeClassifiedMesh): one surface and one
physical group "branch <n>" per branch, and the edges in four physical groups
of lines, one curve per group and branch:

  junction                       edge of three triangles or more, or of two
                                 triangles of different branches
  boundary along another branch  edge of one triangle, with a triangle of
                                 another branch within half the usual edge
                                 length of the skin from its middle: where an
                                 extended branch stops on a sheet without
                                 sharing its vertices
  boundary on the skin           edge of one triangle, with a node of the
                                 skin within one and a half usual edge
                                 lengths from its middle
  boundary inside the part       the other edges of one triangle

After the extension the junctions of the filtered MAT are found in the second
group: the mesh is not conforming along them. With the MAT filtered, the file
also has the local thickness at its nodes ($NodeData "MAT local thickness",
see below).

Local thickness
---------------

At a node of a MAT mesh (raw, filtered) the radius of the ball of the MAT
centred there is its distance to the two sites of the Voronoi polygon it is
on (Mesh::radius). The local thickness at a point of a branch is twice the
radius at the nearest node of that branch in the filtered MAT (a kd-tree per
branch): on what extends a branch, the thickness where the branch ends
(localThickness). After an extension the window shows the view "MAT local
thickness" on the extended MAT (the box "Color by the local thickness"; not
ticked, the branches), and on the mesh of the mid-surface "MAT mid-surface
thickness"; Save..., extended_all.msh and extended_all_classified.msh of
gmshMat --extend-all, and midsurface_mesh.msh have it as $NodeData "MAT local
thickness". On Doghouse.stp (walls 3.5, ribs 1.35): 3.51 at the median node of
the mesh of the mid-surface, 1.32 at the fifth percentile, up to 4.1 to 4.25
along the junctions, where the ball of the MAT grows into the other wall.

Mesh of the mid-surface
-----------------------

Mesh, in the section 6 of the window, puts the MAT as it is (extended; Extend
all is run first if no branch is) in a discrete model of its own, "MAT
mid-surface" (buildMidSurfaceModel), made current, and meshes it
(meshMidSurfaceModel): the menus of Gmsh then act on it (mesh it again with
other options, save it). Pressed on a CAD model just opened, it shows the skin,
the raw MAT, the filtered MAT, the extended MAT, then the mesh. The box Mesh
of the Show row shows it (the model of the part is hidden when the skin is
not shown, the mesh options being those of all the models); a stage run
again, an extension, Undo or Reset delete it.

The model is made by the discrete CAD modeler from the triangles of the MAT,
each branch a piece (DiscreteCAD_Internals::addTriangulation, then
synchronize), without parametrization: no parameters are computed and no
analytic surface is recognized, the surfaces are their triangulations, which
the mesher works on. Its surfaces are the triangles of a branch connected
across edges of two triangles, its curves along the junctions and the
boundaries; a triple line that does not reach the boundary of a surface (a
rib on a wall) is a curve embedded in it, so that its mesh follows it. One
physical group of surfaces "branch <n>" per branch, and two of curves,
"junction" (between surfaces of different branches, embedded curves counted
with their surface) and "boundary". Before, the triangulation is repaired
where the cut of the extension leaves defects that the 1D mesh would follow:
the nodes at the same coordinates merged; the nodes joined by an edge
shorter than a hundredth of the thickness (a tenth of the square root of the
area of the specks) made one, the edges in order of length, the node on more
junction and boundary edges kept where it is unless that turns a triangle
over (then the other one), never a node farther than that length from where
it was, no triangle that is not flat turned over, no sheet pinched (an edge
with three triangles of one branch more around them; away from the
junctions and boundaries, two nodes with no other common neighbor than the
third nodes of their two triangles), the triangles left without area or
found twice left out; the slits closed (a hole of three
edges and zero area: the triangle along its long edge split at its third
node), the holes of less than a hundredth of the thickness squared filled;
after, the surfaces of less than that removed (folds and needles). Its
surfaces are meshed by the Frontal-Delaunay algorithm on their triangulation
(Mesh.Algorithm 12, set on each surface), with the size map of Gmsh: the size
of the section (the thickness if 0) is Mesh.MeshSizeMax for this mesh, the
smaller sizes the other options ask for apply, but the sizes of the 1D mesh
are not extended into the surfaces (Mesh.MeshSizeExtendFromBoundary 0 on each
surface): a short curve of the MAT is no size asked for, and one 1D element of
0.007 made a surface of size 3 refine its triangulation to 2.3 million nodes.

The junctions are conforming where the extension makes them so
(extendAllBranches): a sheet that stays (not replaced by its plane) is cut
where the extended branches stop on it, its pieces in place of its triangles,
so that a rib shares its vertices with the wall it stops on; a sheet that
stays and ended on a branch now replaced by its plane (the walls of the
Doghouse on its base, 0.01 to 0.1 mm above that plane) is prolonged across
the plane by a strip from the edges of that junction, cut with the rest, its
part beyond the plane left out; and the slits of the result are closed
(closeSlits: a triangle kept whole next to one that was cut, a node of the
cut on their common edge on one side only).

A branch that is not flat is extended by a band from its free boundary that
does not fold (extendFront, MatPipeline.h): the boundary advanced as a front,
layer by layer, each layer the strip between the front and its smoothed
offset, triangulated by walking along both lines with every triangle tested
to be turned like the surface; the steps double from twice the edge length of
the boundary up to the reach over the number of layers; the notches of the
boundary are filled first, the points where the offset turns back are left
out, a loop that closes is filled, and a front ends where it comes closer to
another part of the boundary than to its own. It replaces, in Extend all at
once and in gmshMat --extend-all, the ribbon of one row per node of the
boundary (branchRibbon), whose rows crossed where the boundary of the MAT
zigzags; the rows are still computed, one layer, for where each one is
stopped. Preview and Extend, one branch at a time, still use the ribbon.

From the command line, gmshMat ... --extend-all --mesh-midsurface s does the
same (s the size, the thickness if 0) and writes DIR/midsurface_mesh.msh (MSH
4.1: the mesh, the physical groups and the local thickness; the surfaces have
no parametrization to write, so the file is the mesh only: the model is meshed
again in the session), DIR/midsurface_mesh.json and DIR/midsurface_mesh.dat
(PERMAS, see below).

Doghouse.stp: one surface per branch (8), 46 curves of which 18 to 23 at
junctions (the triple lines of the six ribs on the curved wall, embedded in
it, and on the base); thickness 4: 1034 triangles, the model built in 1.6 s
and meshed in 0.6 s; thickness 3: 1685 triangles, 2.9 s and 1.2 s. The mesh is
one piece: the ribs share 9 to 12 nodes with the curved wall and 3 with the
base; the walls and the base, 0.01 to 0.1 mm apart, share none.

PERMAS export (.dat)
--------------------

MatPermas.{h,cpp} write a shell mesh as the PERMAS input of an industrial
pipeline, as write_mesh_dat of thicknesses.py does, in the layout of its
manual meshes (the same columns): the corner
nodes of the elements ($COOR, their Gmsh numbers), the quadrangles (QUAD4)
then the triangles (TRIA3) by element set, each element with its Gmsh number
before its nodes, then $GEODAT SHELL with the thickness of each set, $ELPROP
if a material is given, $END SYSTEM, $EXIT COMPONENT and $FIN. The thickness
of an element is the mean of the thickness at its corners (the MAT local
thickness), rounded up to a multiple of the step (Mesh.PermasThicknessStep,
0.1 by default as range_size in thicknesses.py): the set thick_1.300 holds
the elements of thickness in ]1.2, 1.3] and has the thickness 1.3. A
multiple of the step up to 1e-6 relative stays in its set (the 1.1 of a
float, 1.100000024, is not rounded up to 1.2). One set per thickness, the
triangles and quadrangles together (thicknesses.py made one per element
type). What thicknesses.py did not write and PERMAS needs: the number of
each element (without it the first node is read as the number), $END
STRUCTURE and the end keywords.

With MatGmsh, .dat is this format in Gmsh (File > Export, gmsh::write, gmsh
-o, -format dat); Tochnog stays available by choosing "Mesh - Tochnog" in
the list of formats. The thickness is that of a view of node or element data
on the model: the first one whose name holds "thickness", or else the first
one; without one every element has the thickness 1, with a warning. The
Midsurfacer makes "MAT mid-surface thickness" such a view (node data on the
model "MAT mid-surface"), and midsurface_mesh.msh holds "MAT local
thickness" as $NodeData, so that

  gmsh midsurface_mesh.msh -save -o part.dat -setnumber Mesh.PermasThicknessStep 0.1

writes the same file as gmshMat ... --mesh-midsurface s, which writes
DIR/midsurface_mesh.dat (--dat-step, 0.1 by default; --dat-material NAME
adds the $ELPROP lines, the material being defined in another file). A .dat
whose first keyword is $ENTER, $STRUCTURE or $SYSTEM is read as PERMAS
(readPermasFile): a discrete surface and a physical surface per element set,
and a view of element data "PERMAS thickness" from $GEODAT SHELL; the other
.dat files are read as before (ACTRAN, SAMCEF, BDF).

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
    MatPermasTest MatTetInteriorTest MatCollapseTest -j 6
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
