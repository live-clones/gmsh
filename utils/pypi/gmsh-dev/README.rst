========
gmsh-dev
========

The aim of this package is to download and install the latest development
snapshot of the `Gmsh app and SDK <https://gmsh.info>`_ in a pythonic way,
i.e. via the ``pip`` command. For the latest stable release, use the ``gmsh``
package instead.

Installation should work under Linux, Windows and macOS for both Python 2 and 3.

Before installation make sure that possibly conflicting ``gmsh``, ``gmsh-sdk``
or ``gmsh-sdk-git`` are uninstalled::

    $ pip uninstall gmsh
    $ pip uninstall gmsh-sdk
    $ pip uninstall gmsh-sdk-git

then install ``gmsh-dev`` (don't use the cache and force the download of the
latest development snapshot)::

    $ pip install --force-reinstall --no-cache-dir gmsh-dev

and use::

    $ gmsh --help
    $ python -c "import gmsh; gmsh.initialize(['', '--help'])"
