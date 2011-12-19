
This directory contains Joachim Sch\"oberl's NETGEN mesh generator:

The libsrc and nglib directories are unmodified copies taken from 

  svn co https://netgen-mesher.svn.sourceforge.net/svnroot/netgen-mesher

(SVN rev. 469), with the following exceptions:

* dllexport/dllimport directives have been removed from nglib/nglib.h
* nglib_gmsh.cpp file replaces the original nglib/nglib.cpp file

See the LICENSE file for license information.
