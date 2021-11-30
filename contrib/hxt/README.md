# Functions

Functions in `processing/src/hxt_meshValidation.h` are useful to verify that a mesh respects some hypothesis, e.g.
the mesh has no isolated vertices.

Functions in `processing/src/hxt_meshRepair.h` are useful to repair meshes with defects.

# Executables

`hxtClean` can be used to generate a copy of the input mesh without isolated and/or duplicated vertices.


# Todo

After vertex duplicated deletion, verify there are no edges with the same vertices

Functions to :

- detect non-manifold mesh
- measure element qualities
- validate element orientations
- validate mesh adjacencies

