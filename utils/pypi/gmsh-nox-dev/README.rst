============
gmsh-nox-dev
============

`Gmsh <https://gmsh.info>`_ is an automatic three-dimensional finite element
mesh generator with built-in pre- and post-processing facilities.

The aim of this package is to install the latest development snapshot of the
official Gmsh app and binary Software Development Kit (SDK) in a pythonic way on
Linux systems without X Windows. For Windows, macOS or graphics-enabled Linux
systems, use the ``gmsh-dev`` package instead; for the latest stable release,
use the ``gmsh`` package.

Installation should work under Linux, Windows and macOS for both Python 2
and 3. Before installation make sure that possibly conflicting ``gmsh``,
``gmsh-sdk`` or ``gmsh-sdk-git`` packages are uninstalled.

To install ``gmsh-nox-dev``::

    $ pip install -i https://gmsh.info/python-packages --force-reinstall --no-cache-dir gmsh-nox-dev

This will download and install the latest development snapshot from
https://gmsh.info, bypassing the cache.

After installation you can either run the Gmsh app::

    $ gmsh

or use the Gmsh Python API::

    $ python -c "import gmsh; gmsh.initialize(); gmsh.fltk.run(); gmsh.finalize()"

(Note that the header files for using the C++ and C API are also installed, as
is the Julia module.)
