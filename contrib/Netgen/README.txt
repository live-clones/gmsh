
This directory contains Joachim Sch\"oberl's NETGEN mesh generator:

The libsrc and nglib directories are unmodified copies taken from 
"svn co https://netgen-mesher.svn.sourceforge.net/svnroot/netgen-mesher"
(svn revision 469), with the following exceptions:

* dllexport/dllimport directives have been removed from 
     nglib/nglib.h
     libsrc/interface/nginterface.h
     libsrc/interface/mydefs.hpp
* removed #include <config.h> from libsrc/includes/mystdlib.h
* nglib_gmsh.cpp reimplements parts of nglib/nglib.cpp

See the LICENSE file for license information.
