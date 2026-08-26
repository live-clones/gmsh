# 3CW Mach 0.7 RANS/SST SU2 test

This directory contains a native SU2 test case for the Gmsh boundary-layer
plugin.

The mesh generator creates a 2D 3CW mesh with:

- `Mesh.MeshSizeFromCurvature = 20`
- `Mesh.MeshSizeExtendFromBoundary = 0`
- boundary-layer thickness `40`
- first-layer size `0.3`
- ratio `1.5`
- P1 elements for the first CFD sanity check

It writes the SU2 mesh with these markers:

- `airfoil`: curves 1 to 7
- `farfield`: curves 8 to 11
- `fluid`: surface 16

Run:

```sh
python3 make_3cw_su2.py
```

If `SU2_CFD` is in `PATH`, the script also launches:

```sh
SU2_CFD config.cfg
```

If your SU2 install is not in the shell environment used by VS Code/Codex,
source your SU2 environment first or call the binary manually:

```sh
cd contrib/BoundaryLayers/su2/mach07_RANS
SU2_CFD config.cfg
```

The config is a conservative starting point:

- `SOLVER = RANS`
- `KIND_TURB_MODEL = SST`
- `MACH_NUMBER = 0.70`
- `FREESTREAM_PRESSURE = 101325 Pa`
- `FREESTREAM_TEMPERATURE = 300 K`
- `MARKER_HEATFLUX = ( airfoil, 0.0 )`
- `MARKER_FAR = ( farfield )`

Once the P1 case is stable, the same generation script can be extended to write
a P2 or split-P2 mesh and test what the installed SU2 version accepts.
