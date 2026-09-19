Graphics tests
==============

Checks of what Gmsh draws (geometry, meshes, post-processing views) with both
drawing pipelines (General.Shaders = 0 and 1), meant to be run in CI on the
base and the head of a change and compared:

  cases.txt      the test cases: files to open, and steps (in the .geo
                 language) applied and drawn one after the other
  *.geo          the geometries and meshes of the cases: every kind of OCC,
                 built-in and discrete entity, meshes of every element type
  generate.py    writes the files that cannot be .geo scripts: patches of
                 every element type at orders 1, 2 (complete and incomplete)
                 and 3, with scalar, vector and tensor node, element and
                 element-node data, and the same as list-based views
  run.py         runs the cases (one process per case and pipeline), saves an
                 image after every step, times the drawing, and checks every
                 step against a fresh start with the same steps (what is kept
                 between frames must follow every change); writes summary.json
                 and report.html in the output directory
  pick.cpp       picks on a grid of the window, stepping behind what is found
                 (built by build_pick.py, as it uses the internals of the GUI;
                 run by run.py --pick)
  compare.py     compares two runs: images, picks and timings
  pngdiff.py     PNG reading and comparison, without any other module

Usage, from a build with the GUI and the shared library (make gmsh shared):

  python3 run.py [-o out] [-j jobs] [cases...]
  python3 build_pick.py ../../bin out && python3 run.py --pick -o out
  python3 compare.py reference_out new_out

run.py uses the Python API of ../../api (--api for another tree), which loads
the library of the build next to it. The timings are those Gmsh reports for
the draws of its window (debug messages of openglWindow::draw()): the first
draw, with what it builds, the frames redrawn after rotations, and the steps.
