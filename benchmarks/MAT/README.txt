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
