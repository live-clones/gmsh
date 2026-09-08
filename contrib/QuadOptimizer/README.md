# Quad optimizer V2: Smart Laplacian and final Winslow

`OptimizeQuadsFast` uses the persistent half-edge V2 optimizer. PACK delegates
mesh generation to Gmsh, completes the topology operations, then smooths all
eligible face nodes with projected Smart Laplacian and one final pure Winslow
sweep. Winslow solves in a physical 3D mean plane and projects the candidate
back to its supporting surface. CAD boundary and embedded-curve nodes remain
fixed. Every accepted movement retains the quality, size, orientation and
cumulative CAD-distance guards.

## Options

- `Mesh.QuadqsCleanupMethod = 1`: V2 cleanup (default).
- `Mesh.QuadqsSmartLaplacian = 2`: Smart Laplacian followed by one final
  Winslow sweep (default). `1` selects pure Smart Laplacian; `0` retains the
  projected-centroid/Winslow-fallback mode.
- `Mesh.Smoothing`: primary nodal sweep budget. PACK enforces a minimum of
  three sweeps for Smart Laplacian, five for the historical mode. The single
  final Winslow sweep in mode `2` is additional and runs even when Smart
  Laplacian has no accepted moves. It does not restart topology operations.
- `Mesh.QuadqsIntrinsicEdgeLengthFactor = 0`: preserve the packed point cloud
  (default). Intrinsic edge splitting is opt-in: inserted midpoints have not
  passed the oriented-cube exclusion.

The Smart step uses the arithmetic mean of edge-connected neighbor positions,
projects it, and accepts only strict improvement of the minimum physical
corner sine over the incident cells. This adapts Freitag's 1997 Smart
Laplacian to mixed triangle/quad surfaces. It is not the paper's combined
optimization-based method; the terminal Winslow sweep has its own objective.

For a size-1 triangular, parametrized background mesh:

```sh
gmsh background_h1.msh -2 -algo pack -clmin 1 -clmax 1 \
  -setnumber Mesh.QuadqsPacking3D 1 \
  -setnumber Mesh.QuadqsCleanupMethod 1 \
  -setnumber Mesh.QuadqsSmartLaplacian 2 \
  -setnumber Mesh.Smoothing 3 \
  -setnumber Mesh.QuadqsIntrinsicEdgeLengthFactor 0 \
  -setnumber Mesh.RecombineMinimumQuality 0 \
  -setnumber Mesh.AlgorithmSwitchOnFailure 0 \
  -setnumber Mesh.SaveAll 1 -setnumber Mesh.SaveParametric 1 \
  -nt 1 -o result.msh
```

`-2` meshes surfaces; `QuadqsPacking3D` selects physical 3D surface packing.
The standalone `quadV2StrategyMain.cpp` driver can also resume an existing
mesh with `--max-accepted 0 --smoothing-passes 0 --final-winslow-passes 1`.
`buildQuadV2Strategy.py` builds that driver using an existing Gmsh build.

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

`quadSmartWinslowFinal` exercises the default phase ordering, a productive
terminal Winslow move, and the explicit historical modes. Numerical tests
cover Smart corner sines, Winslow normalization and 3D rigid transformations.

The full 35-test quad subset currently has six pre-existing failures, also
reproduced with the pre-Smart executable: `optimizeQuadsFastTriangleTriangleSwap`,
`optimizeQuadsFastFinalAbsoluteBadQuadSplit`,
`optimizeQuadsFastDiscreteFoldGuard`, `optimizeQuadsFastPreflightConcaveSplit`,
`quadPackTerminalConcaveSplit`, and `quadPackTerminalTriangleRecombine`.
They concern historical trace/terminal repair expectations; the last two
request disabled cleanup while expecting its terminal operations. They are
kept visible rather than reported as passing. In particular, V2 is not a
general repairer for invalid imported meshes or fixed bad quadrangles.
