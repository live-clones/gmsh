
This directory contains a (very) slightly modified version of Joachim
Sch\"oberl's NETGEN mesh generator:

- only (part of the) the libsrc directory was kept from the original
  distribution

- some of the makefiles were changed

- parts of interface/nglib.cpp were #ifdef'd to remove the dependency
  towards netgen's CAD engine

All the changes are marked with "MODIFIED FOR GMSH" in the source code

See COPYING.LIB for license information

**************************************************************

From NETGEN's documentation:

What is NETGEN
==============

NETGEN is an automatic mesh generation tool for two and three
dimensions. Netgen is open source under the conditions of the LGPL.
It comes as stand alone programme with graphical user interface, or as
C++ library to be linked into an other application.  Netgen is
available for Unix/Linux and Windows 98/NT.  Netgen generates
triangular or quadrilateral meshes in 2D, and tetrahedral meshes in
3D. The input for 2D is described by spline curves, and the input for
3D problems is either defined by constructive solid geometries (CSG)
or by the standard STL file format.  NETGEN contains modules for mesh
optimization and hierarchical mesh refinement. Curved elements are
supported of arbitrary order.

The history of NETGEN
=====================

The NETGEN project was started 1994 in the master's programme of
Joachim Sch\"oberl, under supervision of Prof. Ulrich Langer, at the
Department of Computational Mathematics and Optimization, University
Linz, Austria.  Its further development was supported by the Austrian
science Fund ``Fonds zur F\"orderung der wissenschaftlichen
Forschung'' (http://www.fwf.ac.at) under projects P 10643-TEC and SFB
1306.  The current home of Netgen is the Start project ``hp-FEM''
(http://www.hpfem.jku.at) granted by the FWF.

Special thanks go to
- Robert Gaisbauer: High order curved elements
- Hannes Gerstmayr: Meshing of STL geometry

How to receive NETGEN
=====================

NETGEN is available from the WEB at http://www.hpfem.jku.at/netgen
You find there source code releases for Linux/Unix/Windows, as well
as compiled versions for Windows. You can use CVS access to receive
the most up to date version.

**************************************************************

From NETGEN's README.install file:

Latest information is available from:
http://www.sfb013.uni-linz.ac.at/~joachim/netgen

People might have asked similar questions on
https://www.sfb013.uni-linz.ac.at/mailman/listinfo/netgen
(please note the s in https)
