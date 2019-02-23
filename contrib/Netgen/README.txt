
This directory contains Joachim Sch\"oberl's NETGEN mesh generator:

The libsrc and nglib directories are unmodified copies taken from 
"svn co https://netgen-mesher.svn.sourceforge.net/svnroot/netgen-mesher"
(svn revision 469), with the following exceptions:

* removed dllexport/dllimport #defines from
     nglib/nglib.h
     libsrc/interface/nginterface.h
     libsrc/interface/mydefs.hpp
* removed #include <config.h> from 
     libsrc/includes/mystdlib.h

The nglib_gmsh.cpp file in this directory reimplements the parts of
nglib/nglib.cpp that Gmsh relies on.

See the LICENSE file for license information.
