# RAE2822 RANS boundary-layer mesh

This directory contains a small reproducible RAE2822 test based on
`benchmarks/bl/RAE2822.geo`.

The Python script strips the meshing/plugin commands from the `.geo`, remeshes
the surface, applies the `BoundaryLayer` plugin, adds SU2 physical markers and
writes `rae2822_bl.su2`.

Current tags:

- fluid surface: `16`
- airfoil curves: `1,2`
- farfield curves: `3,4,5,6`
- farfield circle: center `(0.5, 0)`, radius `20`

Current baseline parameters:

- `Thickness = 0.01`
- `Size = 0.001`
- `Ratio = 1.2`
- `SmoothingLayers = 5`
- `HighOrder = 1`
- farfield mesh size: `1.5`
- near-wall triangle size: `0.003` with a smooth transition up to distance `0.75`
- wake refinement: aligned with the AoA, sampled from `x = 0.98` to `x = 10`,
  size `0.03`, half-width `0.18`
- trailing-edge point size: `0.002`

Run:

```sh
python3 make_rae2822_su2.py
```

The mesh generation is OK. The current SU2 RANS run diverges immediately on this
sharp trailing-edge geometry: even the coarse baseline has a very large dual
sub-volume ratio at the cusp. The next robust CFD variant should either split the
airfoil curves and stop the boundary layer before the trailing edge, or use a
small trailing-edge cap/finite thickness so the boundary-layer columns do not end
at a double point.
