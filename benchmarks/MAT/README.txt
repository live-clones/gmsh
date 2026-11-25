MAT benchmark CAD inputs
========================

Doghouse.stp, Sample2.stp, Sample3.stp and Sample4.stp are unchanged copies
of the original MatGmsh tests/<case>/<case>.stp inputs used in the
19 November 2026 filtered-MAT and free-boundary extension experiments.

Four manufactured inputs from the 20 November 2026 complex-case audit
are also included, unchanged from the audited STEP files:

  SteppedFilletedBracket.step - thickness changes, fillets and pierced ribs
  FlangedPipeT.step           - a hollow pipe T with three flanges
  DoubleShellCage.step        - two shells with radial webs and an annulus
  TwistedDuct.step            - a twisted elliptical duct with two windows

Their source generator is MatGmsh/tests/complex_manufactured_mat_cases.py.

Open the STEP directly, or use its companion GEO file, for example:

  gmsh benchmarks/MAT/Doghouse.geo

The GEO files import the original solid using OpenCASCADE and set first-order
surface mesh sizes: 0.3 for Doghouse and Sample2/3/4, and 0.175 for the four
manufactured cases. These sizes halve the edge-size settings used by the
23 November 2026 native performance audit (0.6 and 0.35 respectively).
They do not run the MAT pipeline. An OpenCASCADE-enabled Gmsh build is required.

gmshMat preserves these GEO sizing bounds unless a positive --mesh-size is
supplied. When the input does not change Mesh.MeshSizeMin/Max, newly generated
skins default to h/10. Existing surface meshes are reused without remeshing.

cases.json records source paths, SHA-256 hashes and the historical MAT
parameters. current_surface_mesh_size records the current recommended size
in CAD units separately from the historical parameters. The thickness
parameters are 4 mm for Doghouse, Sample3 and
Sample4, and 4.5 mm for Sample2; these are calculation settings, not
independent measurements of maximum wall thickness.

For the manufactured cases the historical thickness parameter is 1.6 mm
for SteppedFilletedBracket and 1.2 mm for the other three. The manifest
also records the original CAD entity counts for import checks.

These files are source geometries, not validated reference midsurfaces.

Corpus of scored mid-surfaces
=============================

corpus/ holds 71 synthetic thin-walled parts whose exact mid-surface is
known, one directory per case:

  <case>.stp              the solid
  <case>_midsurface.brep  its exact mid-surface (the truth)
  <case>.json             metadata of the generator: thicknesses, role of
                          each CAD face, junction and free-edge fillets
  <case>_mid_ext.brep     face-pairing walls computed on 9 October 2026

They are unchanged copies from the MatGmsh corpus of 220 cases (generator:
contrib/MatGmsh/tools/evaluation/generate_corpus.py). The 71 are the cases
whose mid-surface is graded "perfect" (59) or "good" (12) with the chain of
this tree:

  1. gmshMat <case>.stp --thickness t --raw tet --filter collapse
  2. fuse.py filtered.msh <case>_mid_ext.brep t fusion.msh --gentle --part <case>.stp
  3. projected_quality.measure(case, run, 4000, "surface", True)

Step 1 is the MAT of contrib/MatGmsh: interior tetrahedra of the Delaunay
tetrahedrization of the skin nodes, their dual, and the collapse of the wings
and of the sheets thinner than 0.21 t. Step 2 completes it with the walls, as
they were computed in October; the walls are NOT recomputed here. Step 3 is
the evaluator: missing area and area off the truth in units of t^2, interior
coverage, largest distance in units of t, and the verdict

  perfect  coverage >= 0.999, off truth <= 0.1, largest distance <= 0.1 t
  good     coverage >= 0.99,  off truth <= 1,   largest distance <= 0.25 t
  review   otherwise

See contrib/MatGmsh/tools/README.txt for the origin of the scripts.

corpus.json records, for each case, the level and family, the thickness
given to gmshMat and to the fusion, the scores and the verdict, a summary of
the MAT (sites, tetrahedra, polygons, certificate) and the SHA-256 of the four
files. Its list "not_included" gives the scores of the 149 other cases.

Replaying the corpus:

  python3 benchmarks/MAT/run_corpus.py --output <new directory>
          [--case <name>]... [--threads n] [--build <build directory>]

runs the three steps on every case and prints the verdict obtained next to
the recorded one; the exit code is nonzero if a case fails or falls below
"good". It needs gmshMat and the shared Gmsh library in the build directory,
Python with NumPy and SciPy, and a C++ compiler with OpenCASCADE and
nlohmann/json for the tessellator of the evaluator (environment variables
CXX, MATGMSH_OCC_ROOT, MATGMSH_JSON_INCLUDE_DIR). The whole corpus takes
about one hour on one core (57 minutes on the machine of the measures: 35
for the MAT, 19 for the fusion, 3 for the evaluation), of which 34 minutes
for the five assemblies; the largest, assembly_036, needs 13 GB of memory.

Included cases by level (* = good, otherwise perfect):

  Level 1, single sheet (40 of 40):
    bend_135deg_r10, bend_135deg_r4, bend_45deg_r10, bend_45deg_r4,
    bend_90deg_r10, bend_90deg_r4, cone_panel, corrugated,
    cylinder_panel_R100_60deg, cylinder_panel_R30_90deg,
    cylinder_panel_R60_120deg, elbow_R40_r12, hat_r6, hem_gap0.4,
    hem_gap1.0, hem_gap2.0, joggle_h4, joggle_h8, omega_r6, pipe_R20,
    plate_120x30, plate_200x200, plate_60x40, plate_hole_r10, plate_hole_r4,
    plate_holes_3, saddle_k0.005, saddle_k0.01, sphere_cap_R50_40deg,
    sphere_cap_R80_25deg, strip_w12, strip_w20, strip_w8, tray_rb10_rc20,
    tray_rb6_rc10, tube_40x30_r6, tube_60x20_r8, u_channel_narrow,
    u_channel_r6, z_section_r6
  Level 2, junctions (7 of 28):
    pan_flange_r0, pan_flange_r3, pipe_flange_r0, pipe_flange_r3, post_r0*,
    t_junction_h20_r0*, x_junction_r0*
  Level 3, combinations and quirks (17 of 26):
    acute_corner_20deg, acute_corner_40deg, bead, collar, dimple, hat_holes*,
    ligament_edge_gap2*, ligament_edge_gap4, ligament_edge_gap8,
    ligament_holes_gap2*, ligament_holes_gap4, ligament_holes_gap8,
    plate_round_edges_r1.0*, plate_tab_w8, sliver_face, slotted_plate,
    split_faces
  Level 4, thickness varying from 2 to 6 (2 of 9):
    thickness_step_6_2, thickness_step_6_4
  Level 6, objects on a large base plate (5 of 100):
    assembly_030*, assembly_034*, assembly_036*, assembly_074*, assembly_087*

Cases left out, graded "review" with the same chain (no file here):

  Level 2 (21): bend_gusset_r2, channel_gusset_r0, channel_gusset_r2,
    corner_joint_r0, corner_joint_r3, inclined_rib_45deg_r2,
    inclined_rib_60deg_r2, partial_rib_r2, post_r2, ribbed_plate_2_r2,
    ribbed_plate_3_r2, t_junction_h20_r2, t_junction_h20_r5,
    t_junction_h40_r0, t_junction_h40_r2, t_junction_h40_r5, tapered_rib_r2,
    tray_rib_r0, tray_rib_r2, waffle_3_r2, x_junction_r3
  Level 3 (9): bend_round_edges_r1.0, bend_round_edges_r1.5, bracket,
    bracket_round_edges, channel_holes_gussets, cylinder_panel_ring_rib,
    plate_round_edges_r1.5, ribbed_plate_holes, tray_two_ribs_hole
  Level 4 (7): channel_t3_gusset_t6, flush_step_6_2, ribbed_plate_t2_to_6,
    t_junction_t2_6, t_junction_t4_2, t_junction_t6_3, thickness_step_4_2
  Level 5, small parts mixing many features (4): bracket_t3_hem,
    crossmember, pan_ribs_flange_holes, pipe_flange_bolts_gussets
  Level 6 (95): assembly_000 to assembly_099 except the five above
  Level 7, large curved trim panels (9): panel_001, panel_005, panel_009,
    panel_011, panel_012, panel_013, panel_014, panel_015, panel_019
  Level 8, look-alikes of an industrial part (4): doghouse_r0, doghouse_r1,
    trim_strip_000, trim_strip_001

What these verdicts do and do not say:

- They were measured on 25 November 2026 on Linux (GCC 14.3), on a skin mesh
  of size t/10. On 26 November run_corpus.py, which meshes the skin from the
  STEP file, returned the same scores to the last digit on the 71 cases on
  that machine, and the recorded verdict on the 8 cases tried on macOS arm64
  (bend_90deg_r4, plate_60x40, pipe_flange_r0, t_junction_h20_r0,
  x_junction_r0, hat_holes, ligament_edge_gap2, thickness_step_6_2).
- On another platform the skin mesh differs slightly. Six "good" cases sit
  just under the 0.25 t limit of the largest distance (t_junction_h20_r0 and
  the five assemblies, between 0.245 t and 0.25 t) and could tip to "review"
  there; the assemblies were not replayed on macOS.
- In the 71 cases the MAT certificate holds (the interior tetrahedra bound a
  closed manifold surface through every site, with the Euler characteristic
  of the skin). In six of them (hat_holes, ligament_edge_gap2,
  ligament_edge_gap4, ligament_holes_gap2, ligament_holes_gap4,
  plate_round_edges_r1.0) the collapse leaves edges without surface: there
  the filtered surface alone does not have the topology of the solid (it is
  in several pieces in all of them but ligament_edge_gap2), and the verdict
  is that of the surface completed by the walls.
- Of the 149 cases left out, 141 have a point of a free edge of the truth
  farther than 0.25 t from the result, 62 a point of a junction line, 123
  more than 1 t^2 of area off the truth and 56 a coverage below 0.99.
- Doghouse.stp and the other inputs of the first section have no truth and
  no verdict.
