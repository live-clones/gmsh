========
gmsh-dev
========

`Gmsh <https://gmsh.info>`_ is an automatic three-dimensional finite element
mesh generator with built-in pre- and post-processing facilities.

The aim of this package is to install the latest development snapshot of the
official Gmsh app and binary Software Development Kit (SDK) in a pythonic way,
i.e. via the ``pip`` command. For the latest stable release, use the ``gmsh``
package instead.

Installation should work under Linux, Windows and macOS for both Python 2 and 3.
Before installation make sure that possibly conflicting ``gmsh``, ``gmsh-sdk``
or ``gmsh-sdk-git`` packages are uninstalled.

To install ``gmsh-dev``::

    $ pip install -i https://gmsh.info/pypi --force-reinstall --no-cache-dir gmsh-dev

This will download and install the latest development snapshot from
https://gmsh.info, bypassing the cache. On Linux systems without X windows, use
``gmsh-nox-dev`` instead of ``gmsh-dev``.

After installation you can either run the Gmsh app::

    $ gmsh

or use the Gmsh Python API::

    $ python -c "import gmsh; gmsh.initialize(); gmsh.fltk.run(); gmsh.finalize()"

(Note that the header files for using the C++ and C API are also installed, as
is the Julia module.)
