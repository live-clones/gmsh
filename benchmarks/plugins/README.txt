
Plugin tests
============

One or more cases per plugin of src/plugin, each a .geo file that merges the
shared inputs of data/ (or builds a small model of its own), sets the options
of the plugin and runs it:

  *.geo      the cases (files starting with _ are not cases)
  data/      small meshes of a square (triangles, quadrangles) and of a cube
             (tetrahedra, hexahedra) with physical groups, and the same four
             views on each as model data (.msh) and list data (.pos): scalar
             and vector node data (3 steps), tensor node data, element data
  data.py    writes data/ (the files are committed: run it only to change them)
  run.py     runs the cases, one process and one directory per case, and
             checks what each leaves behind against ref.json: the mesh (nodes,
             elements of each type, physical groups), each view (count, sum,
             sum of absolute values, min and max of what each kind of list or
             each step of model data holds) and the files written
  ref.json   the reference summaries

Usage, from a build with the shared library (make gmsh shared):

  python3 run.py [-o out] [--api ../../api] [-j jobs] [cases...]
  python3 run.py --update [cases...]

A case fails if it crashes, logs an error or differs from its reference. After
a change that is meant to change results, check the differences, then update
the reference of the cases concerned with --update.

Traps of the .geo language met writing cases: `For i In {a : b}' only takes a
range (loop over the indices of a list instead), plugin options keep their
values from one run to the next, and the views of a merged file are appended
after the existing ones (PostProcessing.NbViews gives their number).
