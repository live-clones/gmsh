========
gmsh-dev
========

The aim of this package is to download and install the latest development 
snapshot of the `Gmsh app and SDK <http://gmsh.info>`_ in a pythonic way, 
i.e. via the ``pip`` command. For the latest stable release, use the ``gmsh``
package instead.

Installation should work under Linux, Windows and macOS for both Python 2 and 3.

Before installation make sure that possibly conflicting ``gmsh``, ``gmsh-sdk``
or ``gmsh-sdk-git`` are uninstalled::

    $ pip uninstall gmsh
    $ pip uninstall gmsh-sdk
    $ pip uninstall gmsh-sdk-git

then install (or upgrade) ``gmsh-dev``::

    $ pip install --upgrade gmsh-dev

and use::

    $ gmsh --help
    $ python -c "import gmsh; gmsh.initialize(['', '--help'])"
