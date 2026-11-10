# Hex-dominant meshes

Two examples of the hex-dominant flow (`-hybrid`), whose `.geo` files set its
options:

| File | Geometry | Default size `h` | Hexahedra |
| --- | --- | ---: | ---: |
| `crankshaft.geo` | `../step/SampleCrankshaft4A.stp` | 2.75 | about 93,000 |
| `piquage.geo` | `piquage.brep` (pipe junction) | 0.003 | about 115,000 |

`gmsh piquage.geo -3` gives the same mesh as
`gmsh piquage.brep -3 -hybrid -clmin 0.003 -clmax 0.003`, and likewise for the
crankshaft. The size is uniform. From the repository root:

```sh
build/gmsh benchmarks/hexdom/piquage.geo -3 -o /tmp/piquage.msh
build/gmsh benchmarks/hexdom/piquage.geo -3 -setnumber h 0.0015 -o /tmp/piquage.msh
build/gmsh /tmp/piquage.msh -option benchmarks/hexdom/hexdom_view.opt
```

The second run gives about a million hexahedra. The flow:

1. PACK meshes the surfaces with quads (`Mesh.Algorithm = 9`, `Mesh.RecombineAll = 1`).
2. The flat filler places points along the frames in the volume, and they are tetrahedralized (`Mesh.Algorithm3D = 9`).
3. The tetrahedra are combined into hexahedra (`Mesh.Recombine3DAll = 1`) and prisms (`Mesh.Recombine3DPrisms = 1`).
4. The pairs of tetrahedra forming a pyramid on an unmatched quad become pyramids (`Mesh.Recombine3DPyramids = 1`).
5. The vertices are smoothed (`Mesh.Smoothing = 3`).
6. Trihedra close the unmatched quads that remain.

At the end, the run reports the number and quality of each element type and the time of each stage.

`hexdom_view.opt` colors the volume elements by type: green hexahedra, blue
prisms, yellow pyramids, red tetrahedra and purple trihedra. Each `.geo` clips
whole elements through the middle of its geometry.

Both `.geo` files are run by the automatic tests (`ctest`). Each takes a few
seconds.
