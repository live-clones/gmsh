========
gmsh-dev
========

`Gmsh <https://gmsh.info>`_ is an automatic three-dimensional finite element
mesh generator with built-in pre- and post-processing facilities.

The aim of this package is to download and install the latest development
snapshot of the Gmsh app and SDK in a pythonic way, i.e. via the ``pip``
command. For the latest stable release, use the ``gmsh`` package instead.

Installation should work under Linux, Windows and macOS for both Python 2 and 3.

Before installation make sure that possibly conflicting ``gmsh``, ``gmsh-sdk``
or ``gmsh-sdk-git`` are uninstalled::

    $ pip uninstall gmsh gmsh-sdk gmsh-sdk-git

Then install ``gmsh-dev`` by bypassing the cache and forcing the download of the
latest development snapshot::

    $ pip install --force-reinstall --no-cache-dir gmsh-dev

After installation you can either run the Gmsh app::

    $ gmsh

or use the Gmsh Python API::

    $ python -c "import gmsh; gmsh.initialize(); gmsh.fltk.run();"
