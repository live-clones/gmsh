====
gmsh
====

`Gmsh <https://gmsh.info>`_ is an automatic three-dimensional finite element
mesh generator with built-in pre- and post-processing facilities.

The aim of this package is to download and install the Gmsh app and SDK in a
pythonic way, i.e. via the ``pip`` command.

Installation should work under Linux, Windows and macOS for both Python 2 and 3.

Before installation make sure that possibly conflicting ``gmsh-dev``,
``gmsh-sdk`` or ``gmsh-sdk-git`` are uninstalled::

    $ pip uninstall gmsh-dev gmsh-sdk gmsh-sdk-git

Then install (or upgrade) ``gmsh``::

    $ pip install --upgrade gmsh

After installation you can either run the Gmsh app::

    $ gmsh

or use the Gmsh Python API::

    $ python -c "import gmsh; gmsh.initialize(); gmsh.fltk.run();"
