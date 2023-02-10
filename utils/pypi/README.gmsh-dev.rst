==================
gmsh (development)
==================

`Gmsh <https://gmsh.info>`_ is an automatic three-dimensional finite element
mesh generator with built-in pre- and post-processing facilities.

The aim of this package is to install the latest development snapshot of the
official Gmsh app and binary Software Development Kit (SDK) in a pythonic way,
i.e. via the ``pip`` command. Installation should work under Linux, Windows and
macOS for both Python 2 and 3. For the latest stable release, use
``python-packages`` instead of ``python-packages-dev``, or use the official pypi
``gmsh`` package.


To install ``gmsh`` (developement version)::

    $ pip install -i https://gmsh.info/python-packages-dev --force-reinstall --no-cache-dir gmsh

This will download and install the latest development snapshot from
https://gmsh.info, bypassing the cache. On Linux systems without X windows, you
can use ``python-packages-dev-nox`` instead of ``python-packages-dev``.

After installation you can either run the Gmsh app::

    $ gmsh

or use the Gmsh Python API::

    $ python -c "import gmsh; gmsh.initialize(); gmsh.fltk.run(); gmsh.finalize()"

(Note that the header files for using the C++ and C API are also installed, as
is the Julia module.)
