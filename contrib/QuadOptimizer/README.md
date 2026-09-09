# Quad optimizer V2: repeated improvement rounds


PACK + OptimizeQuads is independent of the QuadQuasiStructured algorithm.
Gmsh generates the mesh in this order: PACK point placement, intrinsic
triangulation on discrete surfaces, Blossom recombination, then OptimizeQuads.
The shared background-field and pattern utilities remain reusable by both
algorithms.

## Code ownership and options

- `intrinsicTriangulation.cpp`: intrinsic connectivity, flips and optional
  long-edge splitting; called before Blossom, never as a final cleanup.
- `quadOptimizerIntegration.cpp`: PACK completion, native optimizer dispatch,
  option translation, temporary target-size settings and quality summaries.
- `quadFinalRepair.cpp`: quality-based and transactional terminal quad splitting.
- `smallCavityOptimizerV2.cpp`: V2 improvement rounds and final physical smoothing.

The core keeps small dispatch calls. `Generator.h` and `meshGFaceOptimize.h`
retain their original interfaces. Projection accelerators and the MSH4 embedded
entity fix remain general geometry services. QuadOptimizer reuses the shared
LBFGS solver without requiring the BoundaryLayers plugin.

`Mesh.Pack*` controls generation; `Mesh.OptimizeQuads*` controls optimization.
`Mesh.Quadqs*` remains reserved for QuadQuasiStructured. These development-branch
options have been renamed; the old names are not aliases:

| Previous suffix after `Mesh.` | Replacement |
| --- | --- |
| `QuadqsCleanupMethod` | `PackCleanupMethod` |
| `QuadqsTargetSize` | `PackTargetSize` |
| `QuadqsPacking3D` | `Pack3D` |
| `QuadqsPacking3DForceAllPoints` | `PackForceAllPoints` |
| `QuadqsIntrinsicEdgeLengthFactor` | `PackIntrinsicEdgeLengthFactor` |
| `QuadqsSmartLaplacian` | `OptimizeQuadsSmartLaplacian` |
| `QuadqsFinalSplitCadDistanceRatio` | `OptimizeQuadsFinalSplitCadDistanceRatio` |
| `QuadqsMinimumEdgeLength` | `OptimizeQuadsMinimumEdgeLength` |
| `QuadqsMaximumEdgeLength` | `OptimizeQuadsMaximumEdgeLength` |
| `QuadqsPillowLayers` | `OptimizeQuadsPillowLayers` |

`Mesh.OptimizeQuadsTargetSize` optionally overrides the target used by the
optimizer; zero inherits `Mesh.PackTargetSize`, then the active size field.
`Mesh.PackSizemapMethod = 3` and `Mesh.PackScalingOnTriangulation = 0.75`
configure the shared guiding-field implementation independently of Quadqs.
The default intrinsic split factor remains zero: no extra midpoint insertion.
For example, surface quads with target size 4:

```sh
gmsh geometry.step -2 -algo pack -setnumber Mesh.PackTargetSize 4 -o mesh.msh
```

There are no QuadOptimizer test targets or CTest registrations in the Gmsh
build. Existing standalone diagnostic fixtures remain available for explicit
manual use. Debug files and JSON reports require explicit opt-in.

## Improvement rounds

`OptimizeQuadsFast` uses the persistent half-edge V2 optimizer. PACK delegates
mesh generation to Gmsh. V2 then runs the following model-wide schedule:

1. Smooth all eligible nodes: by default up to three projected Smart Laplacian
   sweeps, followed by one physical 3D mean-plane Winslow sweep.
2. Apply geometrically admissible valence rewrites (QQTQQT, boundary TQQT,
   triangle/quad strips, true 3-3 diamonds), without requiring quality gain.
   Replacement interior points receive local coupled Winslow; QQTQQT has
   exactly two free points. Topology, orientation, size and CAD guards remain.
3. Apply QQ/QT swaps only with strict improvement of the quality objective.
4. Merge TT pairs only when the resulting quad meets the absolute quality
   requirements, preserves preferred quotas, size and CAD guards, and passes
   the same validity/selective diagonal-CAD predicate as final splitting.
5. If the round changed topology, run another active nodal smoothing batch
   and repeat steps 2–5. If no topological operation was accepted, stop this loop
   immediately, regardless of whether nodal proposals could still improve it.
6. Run exactly four pure mean-plane 3D Winslow sweeps over all eligible nodes.
   These sweeps do not enqueue topology work or restart the alternating loop.
7. Split remaining invalid or selectively CAD-distant quads. This is the
   **last mutation**: no swap, merge or smoothing follows it.

Both nodal proposal methods require a strict increase of the minimum physical
corner sine over incident elements. They retain quality, size, orientation and
cumulative CAD-distance guards. Winslow supplies a candidate in the physical
mean plane, projected back to the supporting surface; an energy decrease alone
is insufficient. CAD boundary and embedded-curve nodes remain fixed.

Initial node eligibility covers the whole mesh. Subsequent in-round sweeps visit only
stars whose elements changed through a topology rewrite or a neighboring move.
Smart and Winslow maintain separate active sets, so rejection by one proposal
never suppresses the other. A successful move reactivates every free corner of
its incident cells, including opposite quad corners. Deterministic coloring is
cached until connectivity changes. `activeNodalSmoothing` defaults to true;
`--active-smoothing 0` in the standalone driver retains full sweeps for comparison.
`testActiveNodalSmoothing.py` checks identical coordinates and accepted moves
against that baseline, propagation, a stationary disconnected patch and fewer
node visits. It also checks that terminal Winslow covers all free nodes four
times and that productive final sweeps do not restart topology.

Topological queues are seeded once, then updated around changed connectivity
and moved nodes. Valence queues, QQ/QT swap edges and TT merge edges persist
independently across rounds. No global re-enqueue occurs at each phase.

Quad and split-triangle validity is physical 3D validity and CAD-normal alignment.
UV polygon convexity and UV triangle-area signs are not quality predicates.
Parametric coordinates still locate projections and surface normals internally.
The native quality audit uses the same physical validity rule.
`testPhysicalQuadValidity.py` preserves five fixed planar Sample4 quads whose UV
polygons are nonconvex, and checks that their native validity audit passes.

Native Fast optimization has no round limit. The standalone driver uses
`--max-passes -1` by default; a nonnegative value imposes an explicit cap.
The existing per-face cavity cap remains a safeguard. Logs distinguish `topology-idle`,
`iteration-budget` and `cavity-budget`; an exhausted cap is not convergence.
`--max-passes 0` skips the rounds, but retains initial smoothing, terminal
Winslow and final splitting. `--max-accepted 0` disables topology rewrites, not node smoothing or
final validity repair. The historical `reachedFixedPoint` result refers to the
pre-polish topology stopping condition, not a joint topology/nodal fixed point
of the delivered mesh. `terminalWinslowPasses` defaults to four; the standalone
switch `--terminal-winslow-passes 0` disables only this polish for isolated tests.

The C++ options `terminalMandatoryCleanup`, `qualitySwaps` and `finalPairCleanup`
enable the valence, swap and TT merge phases respectively. Their historical
names are retained for compatibility. The standalone switches are `--valence`,
`--swaps`, `--merge-tt` (0/1); old `--terminal-mandatory`/`--final-pairs` aliases
remain accepted. Legacy counters `acceptedTerminalMandatoryCavities`,
`finalQtSwaps` and `finalTtMerges` now cover those operations across all rounds.
There is no TT diagonal-flip phase.

Final splitting may expose new triangle patterns; they are intentionally not
revisited after the repair. `testLateMandatoryClosure.py` now checks the repeated
round ordering, the topology-only stopping condition, four terminal Winslow
sweeps, and the absence of mutations after
the final split, rather than the superseded post-split closure.

Before constructing the V2 topology, a fixed CAD pole of valence two may be
regularized by splitting one incident quad through that pole. This preserves
every existing edge, point and CAD classification, and avoids skipping a whole
face because two cells share both sides of a fixed pole. The staged face must
pass the full orientation/connectivity check; otherwise the splits roll back.
`initialValenceTwoQuadsSplit` counts these preparatory splits.
`testFixedCadValenceTwo.py` covers QQ/QT stars and rollback in the presence of
an unrelated bow-tie vertex.

## Options

- `Mesh.PackCleanupMethod = 1`: V2 cleanup (default).
- `Mesh.OptimizeQuadsSmartLaplacian = 2`: Smart Laplacian followed by one
  Winslow sweep per batch (default). `1` selects Smart Laplacian in the batches;
  `0` retains projected centroid/Winslow fallback. All modes finish with four
  global pure Winslow sweeps before splitting.
- `Mesh.Smoothing`: primary nodal sweep budget. PACK enforces a minimum of
  three sweeps for Smart Laplacian, five for the historical mode. The single
  Winslow sweep in mode `2` is additional and is attempted even when Smart
  Laplacian has no accepted moves. These batches run initially and after each productive topology round.
- `Mesh.RecombineMinimumQuality < 0`: experimental acceptance of all raw
  matched quad qualities, including non-positive eta. PACK/V2 also bypasses
  the pre-optimizer validity splitting passes in this mode. V2's own guards
  remain active. The final split tries to repair any invalid quads left by V2;
  quads with no valid diagonal are retained and reported.
  Non-negative values retain the existing recombination validity filter.
- `Mesh.OptimizeQuadsFinalSplitCadDistanceRatio = 0.2`: after all smoothing and
  mandatory rewrites, try to split physically invalid quads. A finite angle
  outside the absolute quality interval does not alone trigger a split:
  preserve geometrically valid pattern quads and report their quality violations.
  TT merges still require the resulting quad to meet the absolute specifications.
  For otherwise valid quads,
  split only if one diagonal exceeds this CAD distance/local-size ratio and
  the other diagonal is within tolerance and at least twice closer to CAD.
  Insert the **closer** diagonal. If its two triangles fail validity, retain
  the quad; never fall back to the distant diagonal for a CAD-only repair.
  This preserves quads whose two diagonal distances merely reflect curvature.
  For validity repair, compare both valid diagonals: minimize triangle
  absolute violations, then minimize the triangles' sampled maximum and
  area-weighted mean squared CAD distances; minimum triangle angle breaks ties.
  The comparison uses seven samples per triangle: centroid, edge midpoints,
  and the three barycentric permutations of (0.6, 0.2, 0.2). Planar projection
  roundoff is ignored. The default global CAD ledger quadrature is unchanged.
  Distances are sampled at 1/4, 1/2 and 3/4 of each straight diagonal using
  closest-point projection; they are estimates, not certified bounds.
  Replacement triangles must have positive area and consistent intrinsic and
  CAD orientation. No points are added or moved. No optimization follows this split.
  Rejected splits and projection failures are reported. Negative values
  disable only the CAD trigger. The standalone driver exposes
  `--final-split-cad-ratio` with the same semantics.
  Final repairs are independent of optimization budgets and shape quotas;
  remaining size/quality violations are reported by the final audit.
- `Mesh.PackIntrinsicEdgeLengthFactor = 0`: preserve the packed point cloud
  (default). Intrinsic edge splitting is opt-in: inserted midpoints have not
  passed the oriented-cube exclusion.

The Smart step uses the arithmetic mean of edge-connected neighbor positions,
projects it, and accepts only strict improvement of the minimum physical
corner sine over the incident cells. This adapts Freitag's 1997 Smart
Laplacian to mixed triangle/quad surfaces. It is not the paper's combined
optimization-based method. Winslow proposals use the same minimum-sine acceptance gate.

For a size-1 triangular, parametrized background mesh:

```sh
gmsh background_h1.msh -2 -algo pack -clmin 1 -clmax 1 \
  -setnumber Mesh.Pack3D 1 \
  -setnumber Mesh.PackCleanupMethod 1 \
  -setnumber Mesh.OptimizeQuadsSmartLaplacian 2 \
  -setnumber Mesh.Smoothing 3 \
  -setnumber Mesh.PackIntrinsicEdgeLengthFactor 0 \
  -setnumber Mesh.RecombineMinimumQuality 0 \
  -setnumber Mesh.AlgorithmSwitchOnFailure 0 \
  -setnumber Mesh.SaveAll 1 -setnumber Mesh.SaveParametric 1 \
  -nt 1 -o result.msh
```

`-2` meshes surfaces; `Pack3D` selects physical 3D surface packing.
The standalone `quadV2StrategyMain.cpp` driver can also resume an existing
mesh with `--max-accepted 0 --smoothing-passes 0 --final-winslow-passes 1`.
`buildQuadV2Strategy.py` builds that driver using an existing Gmsh build.

`testTerminalMandatory.py --runner PATH --output DIRECTORY` checks the
valence two-point QQTQQT solve, fixed boundary, disable switch, cavity budget
and size guard. `testTerminalPairs.py` isolates quality swaps and acceptable TT
merges, including their idle reruns. `testFinalQuadSplit.py` checks diagonal
selection on planar/spherical fixtures and preservation of fixed nodes.

## Frozen reference, 2026-09-08

Doghouse h=1: 4,671 nodes, 4,533 quads, 46 triangles. Reapplying one Winslow
sweep to the saved Smart mesh reproduces the validated experiment exactly:
3,919 moved nodes, absolute warping failures 18 to 16, absolute skewing
failures 39 to 30. Connectivity, fixed nodes and 104 embedded segments are
preserved; intrinsic and GFace orientation audits pass.

The integrated native run from the triangular background takes 0.846 s in V2
and 3.486 s total (one measurement, one thread, excluding background
preparation and independent audits). It retains the cumulative acceptance
budget across both smoothing phases instead of resetting it on mesh reload,
so its coordinates can differ slightly from the two-process experiment.
It finishes with 15 absolute warping failures and 30 skewing failures.
These are reference results, not a guarantee that all specifications pass.

`quadSmartWinslowFinal` exercises initial smoothing, ordered rounds to idle,
last-only splitting and the explicit nodal modes. Numerical tests
cover Smart corner sines, Winslow normalization and 3D rigid transformations.

Fixed CAD valence-two preparation checks physical separation across both
shared segments before any cut, so overlapping T/Q or Q/Q input is rejected
without mutation while legitimate QQ/QT poles remain repairable.

## STEP campaign, one report

`runCadQuadCampaign.py --gmsh /path/to/gmsh --inputs /path/to/STEPs
--output /path/to/new-common-directory --jobs 10 --commit GIT_SHA`
processes all `A*.stp`/`A*.step` surfaces directly in 3D at h=4. A separate
triangular meshing process must succeed before PACK can start; its h=4 mesh is
reused as the background while the original STEP CAD remains loaded. Boundary
recovery warnings and all meshing errors abort that case immediately. There is
no alternate algorithm, CAD healing, size reduction or retry of invalid cases.
Ten independent one-thread Gmsh processes can run concurrently. Temporary
triangular meshes are deleted. The single `rapport_A_h4.md` is updated as cases
finish and contains timings, all preferred/absolute criterion counts, physical
validity, edge lengths and sampled CAD-distance diagnostics. A completed mesh
is not necessarily specification-compliant. Native logs and the input/binary
manifest remain in the same output directory; no per-case quality reports or
geometry files are committed.

## Optional diagnostic files

Optimization drivers save only the requested mesh by default.
`gmshQuadV2Strategy --report path.json` explicitly enables its JSON report
and the report-only closest-CAD audits. `gmshQuadOptimizer` accepts
`input.msh face-tag|all output.msh` without a quality POS path; supplying
that optional path retains the existing quality export behavior.
`buildQuadV2Strategy.py --manifest path.json` requests a build manifest.

`Mesh.SaveDebugFiles = 1` enables optional PACK/QuadQuasiStructured
point views, background-field exports, intermediate debug meshes and the
statistics JSON. It defaults to zero; high verbosity alone does not enable
these exports. `Solver.SaveDatabaseJSON = 1` requests the additional JSON
copy of a saved ONELAB database. The normal ONELAB database save policy
remains controlled by `Solver.AutoSaveDatabase`.
