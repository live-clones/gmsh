$Id: README.txt,v 1.2 2001-02-23 19:51:11 geuzaine Exp $

For Windows versions of Gmsh only:
==================================

2) About opengl32.dll:

If a version of the OpenGL library opengl32.dll is already installed
on your system, you should remove the version shipped with
Gmsh. Failing to do so may result in incorrect behaviour of Gmsh (the
graphic window may stay "transparent", or Gmsh may even not run at
all).

1) About cygwin1.dll:

If you plan to use other programs than Gmsh which depend on the
cygwin1.dll library, please move the library from this directory to
the Windows system directory (usually C:\Windows\System\). Failing to
do so may result in incorrect behaviour of all applications sharing
the library.

3) About configuration files:

Gmsh saves session information and default options on disk. The
directory in which these files are saved is (in that order) $HOME (if
the HOME variable is defined, e.g. in your autoexec.bat file), $TEMP
(if TEMP is defined) or $TMP (if TMP is defined). If none of these
variables are defined, Gmsh will try to save/load its configuration
files from the current working directory.

