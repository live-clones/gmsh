$Id: README.txt,v 1.1 2001-03-04 16:27:07 geuzaine Exp $

For Windows versions of Gmsh only:
==================================

1) About opengl32.dll:

If a version of the OpenGL library opengl32.dll is already installed
on your system, you should remove the version shipped with
Gmsh. Failing to do so may result in an incorrect behaviour of Gmsh
(the most common being the graphic window staying "transparent").

2) About cygwin1.dll:

If you plan to use other programs than Gmsh which depend on the
cygwin1.dll library (e.g. GetDP, http://www.geuz.org/getdp/), you
should keep only one version of the library on your system. For this
purpose, you should move the file cygwin1.dll from this directory to
the Windows system directory (usually C:\Windows\System\) and suppress
all other versions of cygwin1.dll. Failing to do so may result in
incorrect behaviour of applications sharing the library and running
simultaneously.

3) About configuration files:

Gmsh saves session information and default options on disk. The
directory in which these files are saved is (in that order) $HOME (if
the HOME variable is defined, e.g. in your autoexec.bat file), $TEMP
(if TEMP is defined) or $TMP (if TMP is defined). If none of these
variables are defined, Gmsh will try to save/load its configuration
files from the current working directory.

