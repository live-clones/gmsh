============
gmsh-nox-dev
============

`Gmsh <https://gmsh.info>`_ is an automatic three-dimensional finite element
mesh generator with built-in pre- and post-processing facilities.

The aim of this package is to install the latest development snapshot of the
official Gmsh app and binary Software Development Kit (SDK) in a pythonic way on
Linux systems without X Windows. For Windows, macOS or graphics-enabled Linux
systems, use the ``dev`` version of the gmsh package instead; for the latest
stable release, use the official ``gmsh`` package.

To install ``gmsh`` (development, ``nox`` version)::

    $ pip install -i https://gmsh.info/python-packages-dev-nox --force-reinstall --no-cache-dir gmsh

This will download and install the latest development snapshot from
https://gmsh.info, bypassing the cache.

After installation you can either run the Gmsh app::

    $ gmsh

or use the Gmsh Python API::

    $ python -c "import gmsh; gmsh.initialize(); gmsh.fltk.run(); gmsh.finalize()"

(Note that the header files for using the C++ and C API are also installed, as
is the Julia module.)
