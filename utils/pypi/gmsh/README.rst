====
gmsh
====

The aim of this package is to download and install the `Gmsh app and SDK
<https://gmsh.info>`_ in a pythonic way, i.e. via the ``pip`` command.

Installation should work under Linux, Windows and macOS for both Python 2 and 3.

Before installation make sure that possibly conflicting ``gmsh-dev``,
``gmsh-sdk`` or ``gmsh-sdk-git`` are uninstalled::

    $ pip uninstall gmsh-dev
    $ pip uninstall gmsh-sdk
    $ pip uninstall gmsh-sdk-git

then install (or upgrade) ``gmsh``::

    $ pip install --upgrade gmsh

and use::

    $ gmsh --help
    $ python -c "import gmsh; gmsh.initialize(['', '--help'])"
