This directory contains the Gmsh tutorial.

The `.geo' files are written in Gmsh's built-in scripting language. You can open
them directly with the Gmsh app: in the graphical user interface (GUI), just go
to `File->Open', select e.g. the first tutorial (`t1.geo') and choose "Open"; on
the command line, run "gmsh t1.geo" (which will launch the GUI) or "gmsh t1.geo
-2" (to perform 2D meshing in batch mode).

 * Binary versions of the Gmsh app for Windows, Linux and macOS can be
   downloaded from http://gmsh.info. Several Linux distributions also ship the
   Gmsh app. See the top-level `README.txt' file in the Gmsh source code for
   instructions on how to compile the app from source.

The `c++', `c', `python' and `julia' subdirectories contain C++, C, Python and
Julia versions of (some of these) tutorials, written using the Gmsh Application
Programming Interface (API): you will need the Gmsh dynamic library and the
associated header files (for C++ and C) or modules (for Python and Julia) to run
them. Each subdirectory contains additional information on how to run the
tutorials for each supported language, as well as a extended tutorials (starting
with `x') introducing features available through the API but not available in
`.geo' files.

 * A binary Software Development Kit (SDK) for Windows, Linux and macOS, that
   contains the dynamic Gmsh library and the associated header and module files,
   can be downloaded from http://gmsh.info. Several Linux distributions also
   ship the Gmsh SDK. See the top-level `README.txt' in the Gmsh source code for
   instructions on how to compile the dynamic Gmsh library from source.
