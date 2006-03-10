# $Id: Makefile,v 1.6.2.1 2006-03-10 06:35:01 geuzaine Exp $
#
# Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
# USA.
# 
# Please report all bugs and problems to <gmsh@geuz.org>.

include ../../variables

LIB     = ../../lib/libGmshNetgen.a
INCLUDE = -I../../Common -Ilibsrc/include -Ilibsrc/interface
CFLAGS  = ${OPTIM} ${FLAGS} ${INCLUDE} -DNO_PARALLEL_THREADS -UWIN32

SRC = libsrc/opti/linopt.cpp \
	libsrc/opti/bfgs.cpp \
	libsrc/opti/linsearch.cpp \
	libsrc/meshing/global.cpp \
	libsrc/meshing/bisect.cpp \
	libsrc/meshing/meshtool.cpp \
	libsrc/meshing/refine.cpp \
	libsrc/meshing/ruler3.cpp \
	libsrc/meshing/improve3.cpp \
	libsrc/meshing/smoothing3.cpp \
	libsrc/meshing/adfront3.cpp \
	libsrc/meshing/tetrarls.cpp \
	libsrc/meshing/prism2rls.cpp \
	libsrc/meshing/pyramidrls.cpp \
	libsrc/meshing/pyramid2rls.cpp \
	libsrc/meshing/netrule3.cpp \
	libsrc/meshing/ruler2.cpp \
	libsrc/meshing/meshclass.cpp \
	libsrc/meshing/improve2.cpp \
	libsrc/meshing/smoothing2.cpp \
	libsrc/meshing/adfront2.cpp \
	libsrc/meshing/netrule2.cpp \
	libsrc/meshing/triarls.cpp \
	libsrc/meshing/geomsearch.cpp \
	libsrc/meshing/secondorder.cpp \
	libsrc/meshing/meshtype.cpp \
	libsrc/meshing/parser3.cpp \
	libsrc/meshing/meshing2.cpp \
	libsrc/meshing/quadrls.cpp \
	libsrc/meshing/specials.cpp \
	libsrc/meshing/parser2.cpp \
	libsrc/meshing/meshing3.cpp \
	libsrc/meshing/meshfunc.cpp \
	libsrc/meshing/localh.cpp \
	libsrc/meshing/improve2gen.cpp \
	libsrc/meshing/delaunay.cpp \
	libsrc/meshing/boundarylayer.cpp \
	libsrc/meshing/msghandler.cpp \
	libsrc/meshing/meshfunc2d.cpp \
	libsrc/meshing/topology.cpp \
	libsrc/meshing/clusters.cpp \
	libsrc/meshing/curvedelems.cpp \
	libsrc/meshing/curvedelems2.cpp \
	libsrc/meshing/hprefinement.cpp \
	libsrc/interface/nglib.cpp \
	libsrc/gprim/geomtest3d.cpp \
	libsrc/gprim/geom2d.cpp \
	libsrc/gprim/geom3d.cpp \
	libsrc/gprim/adtree.cpp \
	libsrc/gprim/transform3d.cpp \
	libsrc/gprim/geomfuncs.cpp \
	libsrc/linalg/polynomial.cpp \
	libsrc/linalg/densemat.cpp \
	libsrc/linalg/vector.cpp \
	libsrc/csg/algprim.cpp \
	libsrc/csg/brick.cpp \
	libsrc/csg/manifold.cpp \
	libsrc/csg/bspline2d.cpp \
	libsrc/csg/meshsurf.cpp \
	libsrc/csg/csgeom.cpp \
	libsrc/csg/polyhedra.cpp \
	libsrc/csg/curve2d.cpp \
	libsrc/csg/singularref.cpp \
	libsrc/csg/edgeflw.cpp \
	libsrc/csg/solid.cpp \
	libsrc/csg/explicitcurve2d.cpp \
	libsrc/csg/specpoin.cpp \
	libsrc/csg/gencyl.cpp \
	libsrc/csg/revolution.cpp \
	libsrc/csg/genmesh.cpp \
	libsrc/csg/spline3d.cpp \
	libsrc/csg/surface.cpp \
	libsrc/csg/identify.cpp \
	libsrc/csg/triapprox.cpp \
	libsrc/geom2d/geom2dmesh.cpp \
	libsrc/geom2d/spline2d.cpp \
	libsrc/geom2d/splinegeometry2.cpp \
	libsrc/geom2d/genmesh2d.cpp \
	libsrc/stlgeom/meshstlsurface.cpp \
	libsrc/stlgeom/stlline.cpp \
	libsrc/stlgeom/stltopology.cpp \
	libsrc/stlgeom/stltool.cpp \
	libsrc/stlgeom/stlgeom.cpp \
	libsrc/stlgeom/stlgeomchart.cpp \
	libsrc/stlgeom/stlgeommesh.cpp \
	libsrc/general/moveablemem.cpp \
	libsrc/general/ngexception.cpp \
	libsrc/general/table.cpp \
	libsrc/general/optmem.cpp \
	libsrc/general/spbita2d.cpp \
	libsrc/general/hashtabl.cpp \
	libsrc/general/sort.cpp \
	libsrc/general/flags.cpp \
	libsrc/general/seti.cpp \
	libsrc/general/bitarray.cpp \
	libsrc/general/array.cpp \
	libsrc/general/symbolta.cpp \
	libsrc/general/mystring.cpp \
	nglib_addon.cpp

OBJ = ${SRC:.cpp=.o}

.SUFFIXES: .o .cpp

${LIB}: ${OBJ} 
	${AR} ${LIB} ${OBJ} 
	${RANLIB} ${LIB}

.cpp.o:
	${CXX} ${CFLAGS} -c $< -o ${<:.cpp=.o}

clean:
	rm -f *.o libsrc/*/*.o

depend:
	(sed '/^# DO NOT DELETE THIS LINE/q' Makefile && \
	${CXX} -MM ${CFLAGS} ${SRC} \
	) >Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	rm -f Makefile.new

# DO NOT DELETE THIS LINE
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
linopt.o: libsrc/opti/linopt.cpp libsrc/include/mystdlib.h \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/opti/opti.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
bfgs.o: libsrc/opti/bfgs.cpp libsrc/include/mystdlib.h \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/opti/opti.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
linsearch.o: libsrc/opti/linsearch.cpp libsrc/include/mystdlib.h \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/opti/opti.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
global.o: libsrc/meshing/global.cpp libsrc/include/mystdlib.h \
  libsrc/meshing/meshing.hpp libsrc/include/myadt.hpp \
  libsrc/include/../general/myadt.hpp libsrc/include/mydefs.hpp \
  libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp libsrc/meshing/msghandler.hpp \
  libsrc/meshing/meshtype.hpp libsrc/meshing/localh.hpp \
  libsrc/meshing/meshclass.hpp libsrc/meshing/global.hpp \
  libsrc/meshing/meshtool.hpp libsrc/meshing/ruler2.hpp \
  libsrc/meshing/adfront2.hpp libsrc/meshing/meshing2.hpp \
  libsrc/meshing/improve2.hpp libsrc/meshing/geomsearch.hpp \
  libsrc/meshing/adfront3.hpp libsrc/meshing/ruler3.hpp \
  libsrc/meshing/meshing3.hpp libsrc/meshing/improve3.hpp \
  libsrc/meshing/findip.hpp libsrc/meshing/topology.hpp \
  libsrc/meshing/curvedelems.hpp libsrc/meshing/bisect.hpp \
  libsrc/meshing/clusters.hpp libsrc/meshing/meshfunc.hpp \
  libsrc/meshing/hprefinement.hpp libsrc/meshing/boundarylayer.hpp \
  libsrc/meshing/specials.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
bisect.o: libsrc/meshing/bisect.cpp libsrc/include/mystdlib.h \
  libsrc/meshing/meshing.hpp libsrc/include/myadt.hpp \
  libsrc/include/../general/myadt.hpp libsrc/include/mydefs.hpp \
  libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp libsrc/meshing/msghandler.hpp \
  libsrc/meshing/meshtype.hpp libsrc/meshing/localh.hpp \
  libsrc/meshing/meshclass.hpp libsrc/meshing/global.hpp \
  libsrc/meshing/meshtool.hpp libsrc/meshing/ruler2.hpp \
  libsrc/meshing/adfront2.hpp libsrc/meshing/meshing2.hpp \
  libsrc/meshing/improve2.hpp libsrc/meshing/geomsearch.hpp \
  libsrc/meshing/adfront3.hpp libsrc/meshing/ruler3.hpp \
  libsrc/meshing/meshing3.hpp libsrc/meshing/improve3.hpp \
  libsrc/meshing/findip.hpp libsrc/meshing/topology.hpp \
  libsrc/meshing/curvedelems.hpp libsrc/meshing/bisect.hpp \
  libsrc/meshing/clusters.hpp libsrc/meshing/meshfunc.hpp \
  libsrc/meshing/hprefinement.hpp libsrc/meshing/boundarylayer.hpp \
  libsrc/meshing/specials.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
meshtool.o: libsrc/meshing/meshtool.cpp libsrc/include/mystdlib.h \
  libsrc/meshing/meshing.hpp libsrc/include/myadt.hpp \
  libsrc/include/../general/myadt.hpp libsrc/include/mydefs.hpp \
  libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp libsrc/meshing/msghandler.hpp \
  libsrc/meshing/meshtype.hpp libsrc/meshing/localh.hpp \
  libsrc/meshing/meshclass.hpp libsrc/meshing/global.hpp \
  libsrc/meshing/meshtool.hpp libsrc/meshing/ruler2.hpp \
  libsrc/meshing/adfront2.hpp libsrc/meshing/meshing2.hpp \
  libsrc/meshing/improve2.hpp libsrc/meshing/geomsearch.hpp \
  libsrc/meshing/adfront3.hpp libsrc/meshing/ruler3.hpp \
  libsrc/meshing/meshing3.hpp libsrc/meshing/improve3.hpp \
  libsrc/meshing/findip.hpp libsrc/meshing/topology.hpp \
  libsrc/meshing/curvedelems.hpp libsrc/meshing/bisect.hpp \
  libsrc/meshing/clusters.hpp libsrc/meshing/meshfunc.hpp \
  libsrc/meshing/hprefinement.hpp libsrc/meshing/boundarylayer.hpp \
  libsrc/meshing/specials.hpp libsrc/include/csg.hpp \
  libsrc/include/../csg/csg.hpp libsrc/include/../gprim/gprim.hpp \
  libsrc/include/meshing.hpp libsrc/include/../meshing/meshing.hpp \
  libsrc/include/../csg/surface.hpp libsrc/include/../csg/solid.hpp \
  libsrc/include/../csg/identify.hpp \
  libsrc/include/../csg/singularref.hpp libsrc/include/../csg/csgeom.hpp \
  libsrc/include/../csg/triapprox.hpp libsrc/include/../csg/algprim.hpp \
  libsrc/include/../csg/brick.hpp libsrc/include/../csg/spline3d.hpp \
  libsrc/include/../csg/manifold.hpp libsrc/include/../csg/curve2d.hpp \
  libsrc/include/../csg/explicitcurve2d.hpp \
  libsrc/include/../csg/gencyl.hpp libsrc/include/../csg/polyhedra.hpp \
  libsrc/include/../csg/extrusion.hpp \
  libsrc/include/../csg/revolution.hpp libsrc/include/../csg/specpoin.hpp \
  libsrc/include/../csg/edgeflw.hpp libsrc/include/../csg/meshsurf.hpp \
  libsrc/include/geometry2d.hpp libsrc/include/../geom2d/geometry2d.hpp \
  libsrc/include/../gprim/gprim.hpp libsrc/include/../geom2d/spline2d.hpp \
  libsrc/include/../geom2d/splinegeometry2.hpp \
  libsrc/include/../geom2d/geom2dmesh.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
refine.o: libsrc/meshing/refine.cpp libsrc/include/mystdlib.h \
  libsrc/meshing/meshing.hpp libsrc/include/myadt.hpp \
  libsrc/include/../general/myadt.hpp libsrc/include/mydefs.hpp \
  libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp libsrc/meshing/msghandler.hpp \
  libsrc/meshing/meshtype.hpp libsrc/meshing/localh.hpp \
  libsrc/meshing/meshclass.hpp libsrc/meshing/global.hpp \
  libsrc/meshing/meshtool.hpp libsrc/meshing/ruler2.hpp \
  libsrc/meshing/adfront2.hpp libsrc/meshing/meshing2.hpp \
  libsrc/meshing/improve2.hpp libsrc/meshing/geomsearch.hpp \
  libsrc/meshing/adfront3.hpp libsrc/meshing/ruler3.hpp \
  libsrc/meshing/meshing3.hpp libsrc/meshing/improve3.hpp \
  libsrc/meshing/findip.hpp libsrc/meshing/topology.hpp \
  libsrc/meshing/curvedelems.hpp libsrc/meshing/bisect.hpp \
  libsrc/meshing/clusters.hpp libsrc/meshing/meshfunc.hpp \
  libsrc/meshing/hprefinement.hpp libsrc/meshing/boundarylayer.hpp \
  libsrc/meshing/specials.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
ruler3.o: libsrc/meshing/ruler3.cpp libsrc/include/mystdlib.h \
  libsrc/meshing/meshing.hpp libsrc/include/myadt.hpp \
  libsrc/include/../general/myadt.hpp libsrc/include/mydefs.hpp \
  libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp libsrc/meshing/msghandler.hpp \
  libsrc/meshing/meshtype.hpp libsrc/meshing/localh.hpp \
  libsrc/meshing/meshclass.hpp libsrc/meshing/global.hpp \
  libsrc/meshing/meshtool.hpp libsrc/meshing/ruler2.hpp \
  libsrc/meshing/adfront2.hpp libsrc/meshing/meshing2.hpp \
  libsrc/meshing/improve2.hpp libsrc/meshing/geomsearch.hpp \
  libsrc/meshing/adfront3.hpp libsrc/meshing/ruler3.hpp \
  libsrc/meshing/meshing3.hpp libsrc/meshing/improve3.hpp \
  libsrc/meshing/findip.hpp libsrc/meshing/topology.hpp \
  libsrc/meshing/curvedelems.hpp libsrc/meshing/bisect.hpp \
  libsrc/meshing/clusters.hpp libsrc/meshing/meshfunc.hpp \
  libsrc/meshing/hprefinement.hpp libsrc/meshing/boundarylayer.hpp \
  libsrc/meshing/specials.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
improve3.o: libsrc/meshing/improve3.cpp libsrc/include/mystdlib.h \
  libsrc/meshing/meshing.hpp libsrc/include/myadt.hpp \
  libsrc/include/../general/myadt.hpp libsrc/include/mydefs.hpp \
  libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp libsrc/meshing/msghandler.hpp \
  libsrc/meshing/meshtype.hpp libsrc/meshing/localh.hpp \
  libsrc/meshing/meshclass.hpp libsrc/meshing/global.hpp \
  libsrc/meshing/meshtool.hpp libsrc/meshing/ruler2.hpp \
  libsrc/meshing/adfront2.hpp libsrc/meshing/meshing2.hpp \
  libsrc/meshing/improve2.hpp libsrc/meshing/geomsearch.hpp \
  libsrc/meshing/adfront3.hpp libsrc/meshing/ruler3.hpp \
  libsrc/meshing/meshing3.hpp libsrc/meshing/improve3.hpp \
  libsrc/meshing/findip.hpp libsrc/meshing/topology.hpp \
  libsrc/meshing/curvedelems.hpp libsrc/meshing/bisect.hpp \
  libsrc/meshing/clusters.hpp libsrc/meshing/meshfunc.hpp \
  libsrc/meshing/hprefinement.hpp libsrc/meshing/boundarylayer.hpp \
  libsrc/meshing/specials.hpp libsrc/include/../opti/opti.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
smoothing3.o: libsrc/meshing/smoothing3.cpp libsrc/include/mystdlib.h \
  libsrc/meshing/meshing.hpp libsrc/include/myadt.hpp \
  libsrc/include/../general/myadt.hpp libsrc/include/mydefs.hpp \
  libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp libsrc/meshing/msghandler.hpp \
  libsrc/meshing/meshtype.hpp libsrc/meshing/localh.hpp \
  libsrc/meshing/meshclass.hpp libsrc/meshing/global.hpp \
  libsrc/meshing/meshtool.hpp libsrc/meshing/ruler2.hpp \
  libsrc/meshing/adfront2.hpp libsrc/meshing/meshing2.hpp \
  libsrc/meshing/improve2.hpp libsrc/meshing/geomsearch.hpp \
  libsrc/meshing/adfront3.hpp libsrc/meshing/ruler3.hpp \
  libsrc/meshing/meshing3.hpp libsrc/meshing/improve3.hpp \
  libsrc/meshing/findip.hpp libsrc/meshing/topology.hpp \
  libsrc/meshing/curvedelems.hpp libsrc/meshing/bisect.hpp \
  libsrc/meshing/clusters.hpp libsrc/meshing/meshfunc.hpp \
  libsrc/meshing/hprefinement.hpp libsrc/meshing/boundarylayer.hpp \
  libsrc/meshing/specials.hpp libsrc/include/../opti/opti.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
adfront3.o: libsrc/meshing/adfront3.cpp libsrc/include/mystdlib.h \
  libsrc/meshing/meshing.hpp libsrc/include/myadt.hpp \
  libsrc/include/../general/myadt.hpp libsrc/include/mydefs.hpp \
  libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp libsrc/meshing/msghandler.hpp \
  libsrc/meshing/meshtype.hpp libsrc/meshing/localh.hpp \
  libsrc/meshing/meshclass.hpp libsrc/meshing/global.hpp \
  libsrc/meshing/meshtool.hpp libsrc/meshing/ruler2.hpp \
  libsrc/meshing/adfront2.hpp libsrc/meshing/meshing2.hpp \
  libsrc/meshing/improve2.hpp libsrc/meshing/geomsearch.hpp \
  libsrc/meshing/adfront3.hpp libsrc/meshing/ruler3.hpp \
  libsrc/meshing/meshing3.hpp libsrc/meshing/improve3.hpp \
  libsrc/meshing/findip.hpp libsrc/meshing/topology.hpp \
  libsrc/meshing/curvedelems.hpp libsrc/meshing/bisect.hpp \
  libsrc/meshing/clusters.hpp libsrc/meshing/meshfunc.hpp \
  libsrc/meshing/hprefinement.hpp libsrc/meshing/boundarylayer.hpp \
  libsrc/meshing/specials.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
tetrarls.o: libsrc/meshing/tetrarls.cpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
prism2rls.o: libsrc/meshing/prism2rls.cpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
pyramidrls.o: libsrc/meshing/pyramidrls.cpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
pyramid2rls.o: libsrc/meshing/pyramid2rls.cpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
netrule3.o: libsrc/meshing/netrule3.cpp libsrc/include/mystdlib.h \
  libsrc/meshing/meshing.hpp libsrc/include/myadt.hpp \
  libsrc/include/../general/myadt.hpp libsrc/include/mydefs.hpp \
  libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp libsrc/meshing/msghandler.hpp \
  libsrc/meshing/meshtype.hpp libsrc/meshing/localh.hpp \
  libsrc/meshing/meshclass.hpp libsrc/meshing/global.hpp \
  libsrc/meshing/meshtool.hpp libsrc/meshing/ruler2.hpp \
  libsrc/meshing/adfront2.hpp libsrc/meshing/meshing2.hpp \
  libsrc/meshing/improve2.hpp libsrc/meshing/geomsearch.hpp \
  libsrc/meshing/adfront3.hpp libsrc/meshing/ruler3.hpp \
  libsrc/meshing/meshing3.hpp libsrc/meshing/improve3.hpp \
  libsrc/meshing/findip.hpp libsrc/meshing/topology.hpp \
  libsrc/meshing/curvedelems.hpp libsrc/meshing/bisect.hpp \
  libsrc/meshing/clusters.hpp libsrc/meshing/meshfunc.hpp \
  libsrc/meshing/hprefinement.hpp libsrc/meshing/boundarylayer.hpp \
  libsrc/meshing/specials.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
ruler2.o: libsrc/meshing/ruler2.cpp libsrc/include/mystdlib.h \
  libsrc/meshing/meshing.hpp libsrc/include/myadt.hpp \
  libsrc/include/../general/myadt.hpp libsrc/include/mydefs.hpp \
  libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp libsrc/meshing/msghandler.hpp \
  libsrc/meshing/meshtype.hpp libsrc/meshing/localh.hpp \
  libsrc/meshing/meshclass.hpp libsrc/meshing/global.hpp \
  libsrc/meshing/meshtool.hpp libsrc/meshing/ruler2.hpp \
  libsrc/meshing/adfront2.hpp libsrc/meshing/meshing2.hpp \
  libsrc/meshing/improve2.hpp libsrc/meshing/geomsearch.hpp \
  libsrc/meshing/adfront3.hpp libsrc/meshing/ruler3.hpp \
  libsrc/meshing/meshing3.hpp libsrc/meshing/improve3.hpp \
  libsrc/meshing/findip.hpp libsrc/meshing/topology.hpp \
  libsrc/meshing/curvedelems.hpp libsrc/meshing/bisect.hpp \
  libsrc/meshing/clusters.hpp libsrc/meshing/meshfunc.hpp \
  libsrc/meshing/hprefinement.hpp libsrc/meshing/boundarylayer.hpp \
  libsrc/meshing/specials.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
meshclass.o: libsrc/meshing/meshclass.cpp libsrc/include/mystdlib.h \
  libsrc/meshing/meshing.hpp libsrc/include/myadt.hpp \
  libsrc/include/../general/myadt.hpp libsrc/include/mydefs.hpp \
  libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp libsrc/meshing/msghandler.hpp \
  libsrc/meshing/meshtype.hpp libsrc/meshing/localh.hpp \
  libsrc/meshing/meshclass.hpp libsrc/meshing/global.hpp \
  libsrc/meshing/meshtool.hpp libsrc/meshing/ruler2.hpp \
  libsrc/meshing/adfront2.hpp libsrc/meshing/meshing2.hpp \
  libsrc/meshing/improve2.hpp libsrc/meshing/geomsearch.hpp \
  libsrc/meshing/adfront3.hpp libsrc/meshing/ruler3.hpp \
  libsrc/meshing/meshing3.hpp libsrc/meshing/improve3.hpp \
  libsrc/meshing/findip.hpp libsrc/meshing/topology.hpp \
  libsrc/meshing/curvedelems.hpp libsrc/meshing/bisect.hpp \
  libsrc/meshing/clusters.hpp libsrc/meshing/meshfunc.hpp \
  libsrc/meshing/hprefinement.hpp libsrc/meshing/boundarylayer.hpp \
  libsrc/meshing/specials.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
improve2.o: libsrc/meshing/improve2.cpp libsrc/include/mystdlib.h \
  libsrc/meshing/meshing.hpp libsrc/include/myadt.hpp \
  libsrc/include/../general/myadt.hpp libsrc/include/mydefs.hpp \
  libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp libsrc/meshing/msghandler.hpp \
  libsrc/meshing/meshtype.hpp libsrc/meshing/localh.hpp \
  libsrc/meshing/meshclass.hpp libsrc/meshing/global.hpp \
  libsrc/meshing/meshtool.hpp libsrc/meshing/ruler2.hpp \
  libsrc/meshing/adfront2.hpp libsrc/meshing/meshing2.hpp \
  libsrc/meshing/improve2.hpp libsrc/meshing/geomsearch.hpp \
  libsrc/meshing/adfront3.hpp libsrc/meshing/ruler3.hpp \
  libsrc/meshing/meshing3.hpp libsrc/meshing/improve3.hpp \
  libsrc/meshing/findip.hpp libsrc/meshing/topology.hpp \
  libsrc/meshing/curvedelems.hpp libsrc/meshing/bisect.hpp \
  libsrc/meshing/clusters.hpp libsrc/meshing/meshfunc.hpp \
  libsrc/meshing/hprefinement.hpp libsrc/meshing/boundarylayer.hpp \
  libsrc/meshing/specials.hpp libsrc/include/../opti/opti.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
smoothing2.o: libsrc/meshing/smoothing2.cpp libsrc/include/mystdlib.h \
  libsrc/meshing/meshing.hpp libsrc/include/myadt.hpp \
  libsrc/include/../general/myadt.hpp libsrc/include/mydefs.hpp \
  libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp libsrc/meshing/msghandler.hpp \
  libsrc/meshing/meshtype.hpp libsrc/meshing/localh.hpp \
  libsrc/meshing/meshclass.hpp libsrc/meshing/global.hpp \
  libsrc/meshing/meshtool.hpp libsrc/meshing/ruler2.hpp \
  libsrc/meshing/adfront2.hpp libsrc/meshing/meshing2.hpp \
  libsrc/meshing/improve2.hpp libsrc/meshing/geomsearch.hpp \
  libsrc/meshing/adfront3.hpp libsrc/meshing/ruler3.hpp \
  libsrc/meshing/meshing3.hpp libsrc/meshing/improve3.hpp \
  libsrc/meshing/findip.hpp libsrc/meshing/topology.hpp \
  libsrc/meshing/curvedelems.hpp libsrc/meshing/bisect.hpp \
  libsrc/meshing/clusters.hpp libsrc/meshing/meshfunc.hpp \
  libsrc/meshing/hprefinement.hpp libsrc/meshing/boundarylayer.hpp \
  libsrc/meshing/specials.hpp libsrc/include/../opti/opti.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
adfront2.o: libsrc/meshing/adfront2.cpp libsrc/include/mystdlib.h \
  libsrc/meshing/meshing.hpp libsrc/include/myadt.hpp \
  libsrc/include/../general/myadt.hpp libsrc/include/mydefs.hpp \
  libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp libsrc/meshing/msghandler.hpp \
  libsrc/meshing/meshtype.hpp libsrc/meshing/localh.hpp \
  libsrc/meshing/meshclass.hpp libsrc/meshing/global.hpp \
  libsrc/meshing/meshtool.hpp libsrc/meshing/ruler2.hpp \
  libsrc/meshing/adfront2.hpp libsrc/meshing/meshing2.hpp \
  libsrc/meshing/improve2.hpp libsrc/meshing/geomsearch.hpp \
  libsrc/meshing/adfront3.hpp libsrc/meshing/ruler3.hpp \
  libsrc/meshing/meshing3.hpp libsrc/meshing/improve3.hpp \
  libsrc/meshing/findip.hpp libsrc/meshing/topology.hpp \
  libsrc/meshing/curvedelems.hpp libsrc/meshing/bisect.hpp \
  libsrc/meshing/clusters.hpp libsrc/meshing/meshfunc.hpp \
  libsrc/meshing/hprefinement.hpp libsrc/meshing/boundarylayer.hpp \
  libsrc/meshing/specials.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
netrule2.o: libsrc/meshing/netrule2.cpp libsrc/include/mystdlib.h \
  libsrc/meshing/meshing.hpp libsrc/include/myadt.hpp \
  libsrc/include/../general/myadt.hpp libsrc/include/mydefs.hpp \
  libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp libsrc/meshing/msghandler.hpp \
  libsrc/meshing/meshtype.hpp libsrc/meshing/localh.hpp \
  libsrc/meshing/meshclass.hpp libsrc/meshing/global.hpp \
  libsrc/meshing/meshtool.hpp libsrc/meshing/ruler2.hpp \
  libsrc/meshing/adfront2.hpp libsrc/meshing/meshing2.hpp \
  libsrc/meshing/improve2.hpp libsrc/meshing/geomsearch.hpp \
  libsrc/meshing/adfront3.hpp libsrc/meshing/ruler3.hpp \
  libsrc/meshing/meshing3.hpp libsrc/meshing/improve3.hpp \
  libsrc/meshing/findip.hpp libsrc/meshing/topology.hpp \
  libsrc/meshing/curvedelems.hpp libsrc/meshing/bisect.hpp \
  libsrc/meshing/clusters.hpp libsrc/meshing/meshfunc.hpp \
  libsrc/meshing/hprefinement.hpp libsrc/meshing/boundarylayer.hpp \
  libsrc/meshing/specials.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
triarls.o: libsrc/meshing/triarls.cpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
geomsearch.o: libsrc/meshing/geomsearch.cpp libsrc/include/mystdlib.h \
  libsrc/meshing/meshing.hpp libsrc/include/myadt.hpp \
  libsrc/include/../general/myadt.hpp libsrc/include/mydefs.hpp \
  libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp libsrc/meshing/msghandler.hpp \
  libsrc/meshing/meshtype.hpp libsrc/meshing/localh.hpp \
  libsrc/meshing/meshclass.hpp libsrc/meshing/global.hpp \
  libsrc/meshing/meshtool.hpp libsrc/meshing/ruler2.hpp \
  libsrc/meshing/adfront2.hpp libsrc/meshing/meshing2.hpp \
  libsrc/meshing/improve2.hpp libsrc/meshing/geomsearch.hpp \
  libsrc/meshing/adfront3.hpp libsrc/meshing/ruler3.hpp \
  libsrc/meshing/meshing3.hpp libsrc/meshing/improve3.hpp \
  libsrc/meshing/findip.hpp libsrc/meshing/topology.hpp \
  libsrc/meshing/curvedelems.hpp libsrc/meshing/bisect.hpp \
  libsrc/meshing/clusters.hpp libsrc/meshing/meshfunc.hpp \
  libsrc/meshing/hprefinement.hpp libsrc/meshing/boundarylayer.hpp \
  libsrc/meshing/specials.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
secondorder.o: libsrc/meshing/secondorder.cpp libsrc/include/mystdlib.h \
  libsrc/meshing/meshing.hpp libsrc/include/myadt.hpp \
  libsrc/include/../general/myadt.hpp libsrc/include/mydefs.hpp \
  libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp libsrc/meshing/msghandler.hpp \
  libsrc/meshing/meshtype.hpp libsrc/meshing/localh.hpp \
  libsrc/meshing/meshclass.hpp libsrc/meshing/global.hpp \
  libsrc/meshing/meshtool.hpp libsrc/meshing/ruler2.hpp \
  libsrc/meshing/adfront2.hpp libsrc/meshing/meshing2.hpp \
  libsrc/meshing/improve2.hpp libsrc/meshing/geomsearch.hpp \
  libsrc/meshing/adfront3.hpp libsrc/meshing/ruler3.hpp \
  libsrc/meshing/meshing3.hpp libsrc/meshing/improve3.hpp \
  libsrc/meshing/findip.hpp libsrc/meshing/topology.hpp \
  libsrc/meshing/curvedelems.hpp libsrc/meshing/bisect.hpp \
  libsrc/meshing/clusters.hpp libsrc/meshing/meshfunc.hpp \
  libsrc/meshing/hprefinement.hpp libsrc/meshing/boundarylayer.hpp \
  libsrc/meshing/specials.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
meshtype.o: libsrc/meshing/meshtype.cpp libsrc/include/mystdlib.h \
  libsrc/meshing/meshing.hpp libsrc/include/myadt.hpp \
  libsrc/include/../general/myadt.hpp libsrc/include/mydefs.hpp \
  libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp libsrc/meshing/msghandler.hpp \
  libsrc/meshing/meshtype.hpp libsrc/meshing/localh.hpp \
  libsrc/meshing/meshclass.hpp libsrc/meshing/global.hpp \
  libsrc/meshing/meshtool.hpp libsrc/meshing/ruler2.hpp \
  libsrc/meshing/adfront2.hpp libsrc/meshing/meshing2.hpp \
  libsrc/meshing/improve2.hpp libsrc/meshing/geomsearch.hpp \
  libsrc/meshing/adfront3.hpp libsrc/meshing/ruler3.hpp \
  libsrc/meshing/meshing3.hpp libsrc/meshing/improve3.hpp \
  libsrc/meshing/findip.hpp libsrc/meshing/topology.hpp \
  libsrc/meshing/curvedelems.hpp libsrc/meshing/bisect.hpp \
  libsrc/meshing/clusters.hpp libsrc/meshing/meshfunc.hpp \
  libsrc/meshing/hprefinement.hpp libsrc/meshing/boundarylayer.hpp \
  libsrc/meshing/specials.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
parser3.o: libsrc/meshing/parser3.cpp libsrc/include/mystdlib.h \
  libsrc/meshing/meshing.hpp libsrc/include/myadt.hpp \
  libsrc/include/../general/myadt.hpp libsrc/include/mydefs.hpp \
  libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp libsrc/meshing/msghandler.hpp \
  libsrc/meshing/meshtype.hpp libsrc/meshing/localh.hpp \
  libsrc/meshing/meshclass.hpp libsrc/meshing/global.hpp \
  libsrc/meshing/meshtool.hpp libsrc/meshing/ruler2.hpp \
  libsrc/meshing/adfront2.hpp libsrc/meshing/meshing2.hpp \
  libsrc/meshing/improve2.hpp libsrc/meshing/geomsearch.hpp \
  libsrc/meshing/adfront3.hpp libsrc/meshing/ruler3.hpp \
  libsrc/meshing/meshing3.hpp libsrc/meshing/improve3.hpp \
  libsrc/meshing/findip.hpp libsrc/meshing/topology.hpp \
  libsrc/meshing/curvedelems.hpp libsrc/meshing/bisect.hpp \
  libsrc/meshing/clusters.hpp libsrc/meshing/meshfunc.hpp \
  libsrc/meshing/hprefinement.hpp libsrc/meshing/boundarylayer.hpp \
  libsrc/meshing/specials.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
meshing2.o: libsrc/meshing/meshing2.cpp libsrc/include/mystdlib.h \
  libsrc/meshing/meshing.hpp libsrc/include/myadt.hpp \
  libsrc/include/../general/myadt.hpp libsrc/include/mydefs.hpp \
  libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp libsrc/meshing/msghandler.hpp \
  libsrc/meshing/meshtype.hpp libsrc/meshing/localh.hpp \
  libsrc/meshing/meshclass.hpp libsrc/meshing/global.hpp \
  libsrc/meshing/meshtool.hpp libsrc/meshing/ruler2.hpp \
  libsrc/meshing/adfront2.hpp libsrc/meshing/meshing2.hpp \
  libsrc/meshing/improve2.hpp libsrc/meshing/geomsearch.hpp \
  libsrc/meshing/adfront3.hpp libsrc/meshing/ruler3.hpp \
  libsrc/meshing/meshing3.hpp libsrc/meshing/improve3.hpp \
  libsrc/meshing/findip.hpp libsrc/meshing/topology.hpp \
  libsrc/meshing/curvedelems.hpp libsrc/meshing/bisect.hpp \
  libsrc/meshing/clusters.hpp libsrc/meshing/meshfunc.hpp \
  libsrc/meshing/hprefinement.hpp libsrc/meshing/boundarylayer.hpp \
  libsrc/meshing/specials.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
quadrls.o: libsrc/meshing/quadrls.cpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
specials.o: libsrc/meshing/specials.cpp libsrc/include/mystdlib.h \
  libsrc/meshing/meshing.hpp libsrc/include/myadt.hpp \
  libsrc/include/../general/myadt.hpp libsrc/include/mydefs.hpp \
  libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp libsrc/meshing/msghandler.hpp \
  libsrc/meshing/meshtype.hpp libsrc/meshing/localh.hpp \
  libsrc/meshing/meshclass.hpp libsrc/meshing/global.hpp \
  libsrc/meshing/meshtool.hpp libsrc/meshing/ruler2.hpp \
  libsrc/meshing/adfront2.hpp libsrc/meshing/meshing2.hpp \
  libsrc/meshing/improve2.hpp libsrc/meshing/geomsearch.hpp \
  libsrc/meshing/adfront3.hpp libsrc/meshing/ruler3.hpp \
  libsrc/meshing/meshing3.hpp libsrc/meshing/improve3.hpp \
  libsrc/meshing/findip.hpp libsrc/meshing/topology.hpp \
  libsrc/meshing/curvedelems.hpp libsrc/meshing/bisect.hpp \
  libsrc/meshing/clusters.hpp libsrc/meshing/meshfunc.hpp \
  libsrc/meshing/hprefinement.hpp libsrc/meshing/boundarylayer.hpp \
  libsrc/meshing/specials.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
parser2.o: libsrc/meshing/parser2.cpp libsrc/include/mystdlib.h \
  libsrc/meshing/meshing.hpp libsrc/include/myadt.hpp \
  libsrc/include/../general/myadt.hpp libsrc/include/mydefs.hpp \
  libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp libsrc/meshing/msghandler.hpp \
  libsrc/meshing/meshtype.hpp libsrc/meshing/localh.hpp \
  libsrc/meshing/meshclass.hpp libsrc/meshing/global.hpp \
  libsrc/meshing/meshtool.hpp libsrc/meshing/ruler2.hpp \
  libsrc/meshing/adfront2.hpp libsrc/meshing/meshing2.hpp \
  libsrc/meshing/improve2.hpp libsrc/meshing/geomsearch.hpp \
  libsrc/meshing/adfront3.hpp libsrc/meshing/ruler3.hpp \
  libsrc/meshing/meshing3.hpp libsrc/meshing/improve3.hpp \
  libsrc/meshing/findip.hpp libsrc/meshing/topology.hpp \
  libsrc/meshing/curvedelems.hpp libsrc/meshing/bisect.hpp \
  libsrc/meshing/clusters.hpp libsrc/meshing/meshfunc.hpp \
  libsrc/meshing/hprefinement.hpp libsrc/meshing/boundarylayer.hpp \
  libsrc/meshing/specials.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
meshing3.o: libsrc/meshing/meshing3.cpp libsrc/include/mystdlib.h \
  libsrc/meshing/meshing.hpp libsrc/include/myadt.hpp \
  libsrc/include/../general/myadt.hpp libsrc/include/mydefs.hpp \
  libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp libsrc/meshing/msghandler.hpp \
  libsrc/meshing/meshtype.hpp libsrc/meshing/localh.hpp \
  libsrc/meshing/meshclass.hpp libsrc/meshing/global.hpp \
  libsrc/meshing/meshtool.hpp libsrc/meshing/ruler2.hpp \
  libsrc/meshing/adfront2.hpp libsrc/meshing/meshing2.hpp \
  libsrc/meshing/improve2.hpp libsrc/meshing/geomsearch.hpp \
  libsrc/meshing/adfront3.hpp libsrc/meshing/ruler3.hpp \
  libsrc/meshing/meshing3.hpp libsrc/meshing/improve3.hpp \
  libsrc/meshing/findip.hpp libsrc/meshing/topology.hpp \
  libsrc/meshing/curvedelems.hpp libsrc/meshing/bisect.hpp \
  libsrc/meshing/clusters.hpp libsrc/meshing/meshfunc.hpp \
  libsrc/meshing/hprefinement.hpp libsrc/meshing/boundarylayer.hpp \
  libsrc/meshing/specials.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
meshfunc.o: libsrc/meshing/meshfunc.cpp libsrc/include/mystdlib.h \
  libsrc/meshing/meshing.hpp libsrc/include/myadt.hpp \
  libsrc/include/../general/myadt.hpp libsrc/include/mydefs.hpp \
  libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp libsrc/meshing/msghandler.hpp \
  libsrc/meshing/meshtype.hpp libsrc/meshing/localh.hpp \
  libsrc/meshing/meshclass.hpp libsrc/meshing/global.hpp \
  libsrc/meshing/meshtool.hpp libsrc/meshing/ruler2.hpp \
  libsrc/meshing/adfront2.hpp libsrc/meshing/meshing2.hpp \
  libsrc/meshing/improve2.hpp libsrc/meshing/geomsearch.hpp \
  libsrc/meshing/adfront3.hpp libsrc/meshing/ruler3.hpp \
  libsrc/meshing/meshing3.hpp libsrc/meshing/improve3.hpp \
  libsrc/meshing/findip.hpp libsrc/meshing/topology.hpp \
  libsrc/meshing/curvedelems.hpp libsrc/meshing/bisect.hpp \
  libsrc/meshing/clusters.hpp libsrc/meshing/meshfunc.hpp \
  libsrc/meshing/hprefinement.hpp libsrc/meshing/boundarylayer.hpp \
  libsrc/meshing/specials.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
localh.o: libsrc/meshing/localh.cpp libsrc/include/mystdlib.h \
  libsrc/meshing/meshing.hpp libsrc/include/myadt.hpp \
  libsrc/include/../general/myadt.hpp libsrc/include/mydefs.hpp \
  libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp libsrc/meshing/msghandler.hpp \
  libsrc/meshing/meshtype.hpp libsrc/meshing/localh.hpp \
  libsrc/meshing/meshclass.hpp libsrc/meshing/global.hpp \
  libsrc/meshing/meshtool.hpp libsrc/meshing/ruler2.hpp \
  libsrc/meshing/adfront2.hpp libsrc/meshing/meshing2.hpp \
  libsrc/meshing/improve2.hpp libsrc/meshing/geomsearch.hpp \
  libsrc/meshing/adfront3.hpp libsrc/meshing/ruler3.hpp \
  libsrc/meshing/meshing3.hpp libsrc/meshing/improve3.hpp \
  libsrc/meshing/findip.hpp libsrc/meshing/topology.hpp \
  libsrc/meshing/curvedelems.hpp libsrc/meshing/bisect.hpp \
  libsrc/meshing/clusters.hpp libsrc/meshing/meshfunc.hpp \
  libsrc/meshing/hprefinement.hpp libsrc/meshing/boundarylayer.hpp \
  libsrc/meshing/specials.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
improve2gen.o: libsrc/meshing/improve2gen.cpp libsrc/include/mystdlib.h \
  libsrc/meshing/meshing.hpp libsrc/include/myadt.hpp \
  libsrc/include/../general/myadt.hpp libsrc/include/mydefs.hpp \
  libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp libsrc/meshing/msghandler.hpp \
  libsrc/meshing/meshtype.hpp libsrc/meshing/localh.hpp \
  libsrc/meshing/meshclass.hpp libsrc/meshing/global.hpp \
  libsrc/meshing/meshtool.hpp libsrc/meshing/ruler2.hpp \
  libsrc/meshing/adfront2.hpp libsrc/meshing/meshing2.hpp \
  libsrc/meshing/improve2.hpp libsrc/meshing/geomsearch.hpp \
  libsrc/meshing/adfront3.hpp libsrc/meshing/ruler3.hpp \
  libsrc/meshing/meshing3.hpp libsrc/meshing/improve3.hpp \
  libsrc/meshing/findip.hpp libsrc/meshing/topology.hpp \
  libsrc/meshing/curvedelems.hpp libsrc/meshing/bisect.hpp \
  libsrc/meshing/clusters.hpp libsrc/meshing/meshfunc.hpp \
  libsrc/meshing/hprefinement.hpp libsrc/meshing/boundarylayer.hpp \
  libsrc/meshing/specials.hpp libsrc/include/../opti/opti.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
delaunay.o: libsrc/meshing/delaunay.cpp libsrc/include/mystdlib.h \
  libsrc/meshing/meshing.hpp libsrc/include/myadt.hpp \
  libsrc/include/../general/myadt.hpp libsrc/include/mydefs.hpp \
  libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp libsrc/meshing/msghandler.hpp \
  libsrc/meshing/meshtype.hpp libsrc/meshing/localh.hpp \
  libsrc/meshing/meshclass.hpp libsrc/meshing/global.hpp \
  libsrc/meshing/meshtool.hpp libsrc/meshing/ruler2.hpp \
  libsrc/meshing/adfront2.hpp libsrc/meshing/meshing2.hpp \
  libsrc/meshing/improve2.hpp libsrc/meshing/geomsearch.hpp \
  libsrc/meshing/adfront3.hpp libsrc/meshing/ruler3.hpp \
  libsrc/meshing/meshing3.hpp libsrc/meshing/improve3.hpp \
  libsrc/meshing/findip.hpp libsrc/meshing/topology.hpp \
  libsrc/meshing/curvedelems.hpp libsrc/meshing/bisect.hpp \
  libsrc/meshing/clusters.hpp libsrc/meshing/meshfunc.hpp \
  libsrc/meshing/hprefinement.hpp libsrc/meshing/boundarylayer.hpp \
  libsrc/meshing/specials.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
boundarylayer.o: libsrc/meshing/boundarylayer.cpp \
  libsrc/include/mystdlib.h libsrc/meshing/meshing.hpp \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp libsrc/meshing/msghandler.hpp \
  libsrc/meshing/meshtype.hpp libsrc/meshing/localh.hpp \
  libsrc/meshing/meshclass.hpp libsrc/meshing/global.hpp \
  libsrc/meshing/meshtool.hpp libsrc/meshing/ruler2.hpp \
  libsrc/meshing/adfront2.hpp libsrc/meshing/meshing2.hpp \
  libsrc/meshing/improve2.hpp libsrc/meshing/geomsearch.hpp \
  libsrc/meshing/adfront3.hpp libsrc/meshing/ruler3.hpp \
  libsrc/meshing/meshing3.hpp libsrc/meshing/improve3.hpp \
  libsrc/meshing/findip.hpp libsrc/meshing/topology.hpp \
  libsrc/meshing/curvedelems.hpp libsrc/meshing/bisect.hpp \
  libsrc/meshing/clusters.hpp libsrc/meshing/meshfunc.hpp \
  libsrc/meshing/hprefinement.hpp libsrc/meshing/boundarylayer.hpp \
  libsrc/meshing/specials.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
msghandler.o: libsrc/meshing/msghandler.cpp libsrc/include/meshing.hpp \
  libsrc/include/../meshing/meshing.hpp libsrc/include/myadt.hpp \
  libsrc/include/../general/myadt.hpp libsrc/include/mystdlib.h \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp \
  libsrc/include/../meshing/msghandler.hpp \
  libsrc/include/../meshing/meshtype.hpp \
  libsrc/include/../meshing/localh.hpp \
  libsrc/include/../meshing/meshclass.hpp \
  libsrc/include/../meshing/global.hpp \
  libsrc/include/../meshing/meshtool.hpp \
  libsrc/include/../meshing/ruler2.hpp \
  libsrc/include/../meshing/adfront2.hpp \
  libsrc/include/../meshing/meshing2.hpp \
  libsrc/include/../meshing/improve2.hpp \
  libsrc/include/../meshing/geomsearch.hpp \
  libsrc/include/../meshing/adfront3.hpp \
  libsrc/include/../meshing/ruler3.hpp \
  libsrc/include/../meshing/meshing3.hpp \
  libsrc/include/../meshing/improve3.hpp \
  libsrc/include/../meshing/findip.hpp \
  libsrc/include/../meshing/topology.hpp \
  libsrc/include/../meshing/curvedelems.hpp \
  libsrc/include/../meshing/bisect.hpp \
  libsrc/include/../meshing/clusters.hpp \
  libsrc/include/../meshing/meshfunc.hpp \
  libsrc/include/../meshing/hprefinement.hpp \
  libsrc/include/../meshing/boundarylayer.hpp \
  libsrc/include/../meshing/specials.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
meshfunc2d.o: libsrc/meshing/meshfunc2d.cpp libsrc/include/mystdlib.h \
  libsrc/meshing/meshing.hpp libsrc/include/myadt.hpp \
  libsrc/include/../general/myadt.hpp libsrc/include/mydefs.hpp \
  libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp libsrc/meshing/msghandler.hpp \
  libsrc/meshing/meshtype.hpp libsrc/meshing/localh.hpp \
  libsrc/meshing/meshclass.hpp libsrc/meshing/global.hpp \
  libsrc/meshing/meshtool.hpp libsrc/meshing/ruler2.hpp \
  libsrc/meshing/adfront2.hpp libsrc/meshing/meshing2.hpp \
  libsrc/meshing/improve2.hpp libsrc/meshing/geomsearch.hpp \
  libsrc/meshing/adfront3.hpp libsrc/meshing/ruler3.hpp \
  libsrc/meshing/meshing3.hpp libsrc/meshing/improve3.hpp \
  libsrc/meshing/findip.hpp libsrc/meshing/topology.hpp \
  libsrc/meshing/curvedelems.hpp libsrc/meshing/bisect.hpp \
  libsrc/meshing/clusters.hpp libsrc/meshing/meshfunc.hpp \
  libsrc/meshing/hprefinement.hpp libsrc/meshing/boundarylayer.hpp \
  libsrc/meshing/specials.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
topology.o: libsrc/meshing/topology.cpp libsrc/include/mystdlib.h \
  libsrc/meshing/meshing.hpp libsrc/include/myadt.hpp \
  libsrc/include/../general/myadt.hpp libsrc/include/mydefs.hpp \
  libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp libsrc/meshing/msghandler.hpp \
  libsrc/meshing/meshtype.hpp libsrc/meshing/localh.hpp \
  libsrc/meshing/meshclass.hpp libsrc/meshing/global.hpp \
  libsrc/meshing/meshtool.hpp libsrc/meshing/ruler2.hpp \
  libsrc/meshing/adfront2.hpp libsrc/meshing/meshing2.hpp \
  libsrc/meshing/improve2.hpp libsrc/meshing/geomsearch.hpp \
  libsrc/meshing/adfront3.hpp libsrc/meshing/ruler3.hpp \
  libsrc/meshing/meshing3.hpp libsrc/meshing/improve3.hpp \
  libsrc/meshing/findip.hpp libsrc/meshing/topology.hpp \
  libsrc/meshing/curvedelems.hpp libsrc/meshing/bisect.hpp \
  libsrc/meshing/clusters.hpp libsrc/meshing/meshfunc.hpp \
  libsrc/meshing/hprefinement.hpp libsrc/meshing/boundarylayer.hpp \
  libsrc/meshing/specials.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
clusters.o: libsrc/meshing/clusters.cpp libsrc/include/mystdlib.h \
  libsrc/meshing/meshing.hpp libsrc/include/myadt.hpp \
  libsrc/include/../general/myadt.hpp libsrc/include/mydefs.hpp \
  libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp libsrc/meshing/msghandler.hpp \
  libsrc/meshing/meshtype.hpp libsrc/meshing/localh.hpp \
  libsrc/meshing/meshclass.hpp libsrc/meshing/global.hpp \
  libsrc/meshing/meshtool.hpp libsrc/meshing/ruler2.hpp \
  libsrc/meshing/adfront2.hpp libsrc/meshing/meshing2.hpp \
  libsrc/meshing/improve2.hpp libsrc/meshing/geomsearch.hpp \
  libsrc/meshing/adfront3.hpp libsrc/meshing/ruler3.hpp \
  libsrc/meshing/meshing3.hpp libsrc/meshing/improve3.hpp \
  libsrc/meshing/findip.hpp libsrc/meshing/topology.hpp \
  libsrc/meshing/curvedelems.hpp libsrc/meshing/bisect.hpp \
  libsrc/meshing/clusters.hpp libsrc/meshing/meshfunc.hpp \
  libsrc/meshing/hprefinement.hpp libsrc/meshing/boundarylayer.hpp \
  libsrc/meshing/specials.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
curvedelems.o: libsrc/meshing/curvedelems.cpp libsrc/include/mystdlib.h \
  libsrc/meshing/meshing.hpp libsrc/include/myadt.hpp \
  libsrc/include/../general/myadt.hpp libsrc/include/mydefs.hpp \
  libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp libsrc/meshing/msghandler.hpp \
  libsrc/meshing/meshtype.hpp libsrc/meshing/localh.hpp \
  libsrc/meshing/meshclass.hpp libsrc/meshing/global.hpp \
  libsrc/meshing/meshtool.hpp libsrc/meshing/ruler2.hpp \
  libsrc/meshing/adfront2.hpp libsrc/meshing/meshing2.hpp \
  libsrc/meshing/improve2.hpp libsrc/meshing/geomsearch.hpp \
  libsrc/meshing/adfront3.hpp libsrc/meshing/ruler3.hpp \
  libsrc/meshing/meshing3.hpp libsrc/meshing/improve3.hpp \
  libsrc/meshing/findip.hpp libsrc/meshing/topology.hpp \
  libsrc/meshing/curvedelems.hpp libsrc/meshing/bisect.hpp \
  libsrc/meshing/clusters.hpp libsrc/meshing/meshfunc.hpp \
  libsrc/meshing/hprefinement.hpp libsrc/meshing/boundarylayer.hpp \
  libsrc/meshing/specials.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
curvedelems2.o: libsrc/meshing/curvedelems2.cpp libsrc/include/mystdlib.h \
  libsrc/meshing/meshing.hpp libsrc/include/myadt.hpp \
  libsrc/include/../general/myadt.hpp libsrc/include/mydefs.hpp \
  libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp libsrc/meshing/msghandler.hpp \
  libsrc/meshing/meshtype.hpp libsrc/meshing/localh.hpp \
  libsrc/meshing/meshclass.hpp libsrc/meshing/global.hpp \
  libsrc/meshing/meshtool.hpp libsrc/meshing/ruler2.hpp \
  libsrc/meshing/adfront2.hpp libsrc/meshing/meshing2.hpp \
  libsrc/meshing/improve2.hpp libsrc/meshing/geomsearch.hpp \
  libsrc/meshing/adfront3.hpp libsrc/meshing/ruler3.hpp \
  libsrc/meshing/meshing3.hpp libsrc/meshing/improve3.hpp \
  libsrc/meshing/findip.hpp libsrc/meshing/topology.hpp \
  libsrc/meshing/curvedelems.hpp libsrc/meshing/bisect.hpp \
  libsrc/meshing/clusters.hpp libsrc/meshing/meshfunc.hpp \
  libsrc/meshing/hprefinement.hpp libsrc/meshing/boundarylayer.hpp \
  libsrc/meshing/specials.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
hprefinement.o: libsrc/meshing/hprefinement.cpp libsrc/include/mystdlib.h \
  libsrc/meshing/meshing.hpp libsrc/include/myadt.hpp \
  libsrc/include/../general/myadt.hpp libsrc/include/mydefs.hpp \
  libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp libsrc/meshing/msghandler.hpp \
  libsrc/meshing/meshtype.hpp libsrc/meshing/localh.hpp \
  libsrc/meshing/meshclass.hpp libsrc/meshing/global.hpp \
  libsrc/meshing/meshtool.hpp libsrc/meshing/ruler2.hpp \
  libsrc/meshing/adfront2.hpp libsrc/meshing/meshing2.hpp \
  libsrc/meshing/improve2.hpp libsrc/meshing/geomsearch.hpp \
  libsrc/meshing/adfront3.hpp libsrc/meshing/ruler3.hpp \
  libsrc/meshing/meshing3.hpp libsrc/meshing/improve3.hpp \
  libsrc/meshing/findip.hpp libsrc/meshing/topology.hpp \
  libsrc/meshing/curvedelems.hpp libsrc/meshing/bisect.hpp \
  libsrc/meshing/clusters.hpp libsrc/meshing/meshfunc.hpp \
  libsrc/meshing/hprefinement.hpp libsrc/meshing/boundarylayer.hpp \
  libsrc/meshing/specials.hpp libsrc/meshing/hpref_trig.hpp \
  libsrc/meshing/hpref_quad.hpp libsrc/meshing/hpref_tet.hpp \
  libsrc/meshing/hpref_prism.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
nglib.o: libsrc/interface/nglib.cpp libsrc/include/mystdlib.h \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/csg.hpp \
  libsrc/include/../csg/csg.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/meshing.hpp \
  libsrc/include/../meshing/meshing.hpp libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp \
  libsrc/include/../meshing/msghandler.hpp \
  libsrc/include/../meshing/meshtype.hpp \
  libsrc/include/../meshing/localh.hpp \
  libsrc/include/../meshing/meshclass.hpp \
  libsrc/include/../meshing/global.hpp \
  libsrc/include/../meshing/meshtool.hpp \
  libsrc/include/../meshing/ruler2.hpp \
  libsrc/include/../meshing/adfront2.hpp \
  libsrc/include/../meshing/meshing2.hpp \
  libsrc/include/../meshing/improve2.hpp \
  libsrc/include/../meshing/geomsearch.hpp \
  libsrc/include/../meshing/adfront3.hpp \
  libsrc/include/../meshing/ruler3.hpp \
  libsrc/include/../meshing/meshing3.hpp \
  libsrc/include/../meshing/improve3.hpp \
  libsrc/include/../meshing/findip.hpp \
  libsrc/include/../meshing/topology.hpp \
  libsrc/include/../meshing/curvedelems.hpp \
  libsrc/include/../meshing/bisect.hpp \
  libsrc/include/../meshing/clusters.hpp \
  libsrc/include/../meshing/meshfunc.hpp \
  libsrc/include/../meshing/hprefinement.hpp \
  libsrc/include/../meshing/boundarylayer.hpp \
  libsrc/include/../meshing/specials.hpp \
  libsrc/include/../csg/surface.hpp libsrc/include/../csg/solid.hpp \
  libsrc/include/../csg/identify.hpp \
  libsrc/include/../csg/singularref.hpp libsrc/include/../csg/csgeom.hpp \
  libsrc/include/../csg/triapprox.hpp libsrc/include/../csg/algprim.hpp \
  libsrc/include/../csg/brick.hpp libsrc/include/../csg/spline3d.hpp \
  libsrc/include/../csg/manifold.hpp libsrc/include/../csg/curve2d.hpp \
  libsrc/include/../csg/explicitcurve2d.hpp \
  libsrc/include/../csg/gencyl.hpp libsrc/include/../csg/polyhedra.hpp \
  libsrc/include/../csg/extrusion.hpp \
  libsrc/include/../csg/revolution.hpp libsrc/include/../csg/specpoin.hpp \
  libsrc/include/../csg/edgeflw.hpp libsrc/include/../csg/meshsurf.hpp \
  libsrc/include/stlgeom.hpp libsrc/include/../stlgeom/stlgeom.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../stlgeom/stltopology.hpp \
  libsrc/include/../stlgeom/stltool.hpp \
  libsrc/include/../stlgeom/stlline.hpp \
  libsrc/include/../stlgeom/meshstlsurface.hpp \
  libsrc/include/geometry2d.hpp libsrc/include/../geom2d/geometry2d.hpp \
  libsrc/include/../gprim/gprim.hpp libsrc/include/../geom2d/spline2d.hpp \
  libsrc/include/../geom2d/splinegeometry2.hpp \
  libsrc/include/../geom2d/geom2dmesh.hpp libsrc/interface/nglib.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
geomtest3d.o: libsrc/gprim/geomtest3d.cpp libsrc/include/mystdlib.h \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
geom2d.o: libsrc/gprim/geom2d.cpp libsrc/include/mystdlib.h \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
geom3d.o: libsrc/gprim/geom3d.cpp libsrc/include/mystdlib.h \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
adtree.o: libsrc/gprim/adtree.cpp libsrc/include/mystdlib.h \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
transform3d.o: libsrc/gprim/transform3d.cpp libsrc/include/mystdlib.h \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
geomfuncs.o: libsrc/gprim/geomfuncs.cpp libsrc/include/mystdlib.h \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
polynomial.o: libsrc/linalg/polynomial.cpp libsrc/include/mystdlib.h \
  libsrc/include/linalg.hpp libsrc/include/../linalg/linalg.hpp \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp \
  libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
densemat.o: libsrc/linalg/densemat.cpp libsrc/include/mystdlib.h \
  libsrc/include/linalg.hpp libsrc/include/../linalg/linalg.hpp \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp \
  libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
vector.o: libsrc/linalg/vector.cpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
algprim.o: libsrc/csg/algprim.cpp libsrc/include/mystdlib.h \
  libsrc/include/linalg.hpp libsrc/include/../linalg/linalg.hpp \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp \
  libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/csg.hpp \
  libsrc/include/../csg/csg.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/meshing.hpp \
  libsrc/include/../meshing/meshing.hpp libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp \
  libsrc/include/../meshing/msghandler.hpp \
  libsrc/include/../meshing/meshtype.hpp \
  libsrc/include/../meshing/localh.hpp \
  libsrc/include/../meshing/meshclass.hpp \
  libsrc/include/../meshing/global.hpp \
  libsrc/include/../meshing/meshtool.hpp \
  libsrc/include/../meshing/ruler2.hpp \
  libsrc/include/../meshing/adfront2.hpp \
  libsrc/include/../meshing/meshing2.hpp \
  libsrc/include/../meshing/improve2.hpp \
  libsrc/include/../meshing/geomsearch.hpp \
  libsrc/include/../meshing/adfront3.hpp \
  libsrc/include/../meshing/ruler3.hpp \
  libsrc/include/../meshing/meshing3.hpp \
  libsrc/include/../meshing/improve3.hpp \
  libsrc/include/../meshing/findip.hpp \
  libsrc/include/../meshing/topology.hpp \
  libsrc/include/../meshing/curvedelems.hpp \
  libsrc/include/../meshing/bisect.hpp \
  libsrc/include/../meshing/clusters.hpp \
  libsrc/include/../meshing/meshfunc.hpp \
  libsrc/include/../meshing/hprefinement.hpp \
  libsrc/include/../meshing/boundarylayer.hpp \
  libsrc/include/../meshing/specials.hpp \
  libsrc/include/../csg/surface.hpp libsrc/include/../csg/solid.hpp \
  libsrc/include/../csg/identify.hpp \
  libsrc/include/../csg/singularref.hpp libsrc/include/../csg/csgeom.hpp \
  libsrc/include/../csg/triapprox.hpp libsrc/include/../csg/algprim.hpp \
  libsrc/include/../csg/brick.hpp libsrc/include/../csg/spline3d.hpp \
  libsrc/include/../csg/manifold.hpp libsrc/include/../csg/curve2d.hpp \
  libsrc/include/../csg/explicitcurve2d.hpp \
  libsrc/include/../csg/gencyl.hpp libsrc/include/../csg/polyhedra.hpp \
  libsrc/include/../csg/extrusion.hpp \
  libsrc/include/../csg/revolution.hpp libsrc/include/../csg/specpoin.hpp \
  libsrc/include/../csg/edgeflw.hpp libsrc/include/../csg/meshsurf.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
brick.o: libsrc/csg/brick.cpp libsrc/include/mystdlib.h \
  libsrc/include/linalg.hpp libsrc/include/../linalg/linalg.hpp \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp \
  libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/csg.hpp \
  libsrc/include/../csg/csg.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/meshing.hpp \
  libsrc/include/../meshing/meshing.hpp libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp \
  libsrc/include/../meshing/msghandler.hpp \
  libsrc/include/../meshing/meshtype.hpp \
  libsrc/include/../meshing/localh.hpp \
  libsrc/include/../meshing/meshclass.hpp \
  libsrc/include/../meshing/global.hpp \
  libsrc/include/../meshing/meshtool.hpp \
  libsrc/include/../meshing/ruler2.hpp \
  libsrc/include/../meshing/adfront2.hpp \
  libsrc/include/../meshing/meshing2.hpp \
  libsrc/include/../meshing/improve2.hpp \
  libsrc/include/../meshing/geomsearch.hpp \
  libsrc/include/../meshing/adfront3.hpp \
  libsrc/include/../meshing/ruler3.hpp \
  libsrc/include/../meshing/meshing3.hpp \
  libsrc/include/../meshing/improve3.hpp \
  libsrc/include/../meshing/findip.hpp \
  libsrc/include/../meshing/topology.hpp \
  libsrc/include/../meshing/curvedelems.hpp \
  libsrc/include/../meshing/bisect.hpp \
  libsrc/include/../meshing/clusters.hpp \
  libsrc/include/../meshing/meshfunc.hpp \
  libsrc/include/../meshing/hprefinement.hpp \
  libsrc/include/../meshing/boundarylayer.hpp \
  libsrc/include/../meshing/specials.hpp \
  libsrc/include/../csg/surface.hpp libsrc/include/../csg/solid.hpp \
  libsrc/include/../csg/identify.hpp \
  libsrc/include/../csg/singularref.hpp libsrc/include/../csg/csgeom.hpp \
  libsrc/include/../csg/triapprox.hpp libsrc/include/../csg/algprim.hpp \
  libsrc/include/../csg/brick.hpp libsrc/include/../csg/spline3d.hpp \
  libsrc/include/../csg/manifold.hpp libsrc/include/../csg/curve2d.hpp \
  libsrc/include/../csg/explicitcurve2d.hpp \
  libsrc/include/../csg/gencyl.hpp libsrc/include/../csg/polyhedra.hpp \
  libsrc/include/../csg/extrusion.hpp \
  libsrc/include/../csg/revolution.hpp libsrc/include/../csg/specpoin.hpp \
  libsrc/include/../csg/edgeflw.hpp libsrc/include/../csg/meshsurf.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
manifold.o: libsrc/csg/manifold.cpp libsrc/include/csg.hpp \
  libsrc/include/../csg/csg.hpp libsrc/include/myadt.hpp \
  libsrc/include/../general/myadt.hpp libsrc/include/mystdlib.h \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/meshing.hpp \
  libsrc/include/../meshing/meshing.hpp libsrc/include/../gprim/gprim.hpp \
  libsrc/include/linalg.hpp libsrc/include/../linalg/linalg.hpp \
  libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp \
  libsrc/include/../meshing/msghandler.hpp \
  libsrc/include/../meshing/meshtype.hpp \
  libsrc/include/../meshing/localh.hpp \
  libsrc/include/../meshing/meshclass.hpp \
  libsrc/include/../meshing/global.hpp \
  libsrc/include/../meshing/meshtool.hpp \
  libsrc/include/../meshing/ruler2.hpp \
  libsrc/include/../meshing/adfront2.hpp \
  libsrc/include/../meshing/meshing2.hpp \
  libsrc/include/../meshing/improve2.hpp \
  libsrc/include/../meshing/geomsearch.hpp \
  libsrc/include/../meshing/adfront3.hpp \
  libsrc/include/../meshing/ruler3.hpp \
  libsrc/include/../meshing/meshing3.hpp \
  libsrc/include/../meshing/improve3.hpp \
  libsrc/include/../meshing/findip.hpp \
  libsrc/include/../meshing/topology.hpp \
  libsrc/include/../meshing/curvedelems.hpp \
  libsrc/include/../meshing/bisect.hpp \
  libsrc/include/../meshing/clusters.hpp \
  libsrc/include/../meshing/meshfunc.hpp \
  libsrc/include/../meshing/hprefinement.hpp \
  libsrc/include/../meshing/boundarylayer.hpp \
  libsrc/include/../meshing/specials.hpp \
  libsrc/include/../csg/surface.hpp libsrc/include/../csg/solid.hpp \
  libsrc/include/../csg/identify.hpp \
  libsrc/include/../csg/singularref.hpp libsrc/include/../csg/csgeom.hpp \
  libsrc/include/../csg/triapprox.hpp libsrc/include/../csg/algprim.hpp \
  libsrc/include/../csg/brick.hpp libsrc/include/../csg/spline3d.hpp \
  libsrc/include/../csg/manifold.hpp libsrc/include/../csg/curve2d.hpp \
  libsrc/include/../csg/explicitcurve2d.hpp \
  libsrc/include/../csg/gencyl.hpp libsrc/include/../csg/polyhedra.hpp \
  libsrc/include/../csg/extrusion.hpp \
  libsrc/include/../csg/revolution.hpp libsrc/include/../csg/specpoin.hpp \
  libsrc/include/../csg/edgeflw.hpp libsrc/include/../csg/meshsurf.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
bspline2d.o: libsrc/csg/bspline2d.cpp libsrc/include/mystdlib.h \
  libsrc/include/csg.hpp libsrc/include/../csg/csg.hpp \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/meshing.hpp \
  libsrc/include/../meshing/meshing.hpp libsrc/include/../gprim/gprim.hpp \
  libsrc/include/linalg.hpp libsrc/include/../linalg/linalg.hpp \
  libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp \
  libsrc/include/../meshing/msghandler.hpp \
  libsrc/include/../meshing/meshtype.hpp \
  libsrc/include/../meshing/localh.hpp \
  libsrc/include/../meshing/meshclass.hpp \
  libsrc/include/../meshing/global.hpp \
  libsrc/include/../meshing/meshtool.hpp \
  libsrc/include/../meshing/ruler2.hpp \
  libsrc/include/../meshing/adfront2.hpp \
  libsrc/include/../meshing/meshing2.hpp \
  libsrc/include/../meshing/improve2.hpp \
  libsrc/include/../meshing/geomsearch.hpp \
  libsrc/include/../meshing/adfront3.hpp \
  libsrc/include/../meshing/ruler3.hpp \
  libsrc/include/../meshing/meshing3.hpp \
  libsrc/include/../meshing/improve3.hpp \
  libsrc/include/../meshing/findip.hpp \
  libsrc/include/../meshing/topology.hpp \
  libsrc/include/../meshing/curvedelems.hpp \
  libsrc/include/../meshing/bisect.hpp \
  libsrc/include/../meshing/clusters.hpp \
  libsrc/include/../meshing/meshfunc.hpp \
  libsrc/include/../meshing/hprefinement.hpp \
  libsrc/include/../meshing/boundarylayer.hpp \
  libsrc/include/../meshing/specials.hpp \
  libsrc/include/../csg/surface.hpp libsrc/include/../csg/solid.hpp \
  libsrc/include/../csg/identify.hpp \
  libsrc/include/../csg/singularref.hpp libsrc/include/../csg/csgeom.hpp \
  libsrc/include/../csg/triapprox.hpp libsrc/include/../csg/algprim.hpp \
  libsrc/include/../csg/brick.hpp libsrc/include/../csg/spline3d.hpp \
  libsrc/include/../csg/manifold.hpp libsrc/include/../csg/curve2d.hpp \
  libsrc/include/../csg/explicitcurve2d.hpp \
  libsrc/include/../csg/gencyl.hpp libsrc/include/../csg/polyhedra.hpp \
  libsrc/include/../csg/extrusion.hpp \
  libsrc/include/../csg/revolution.hpp libsrc/include/../csg/specpoin.hpp \
  libsrc/include/../csg/edgeflw.hpp libsrc/include/../csg/meshsurf.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
meshsurf.o: libsrc/csg/meshsurf.cpp libsrc/include/mystdlib.h \
  libsrc/include/csg.hpp libsrc/include/../csg/csg.hpp \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/meshing.hpp \
  libsrc/include/../meshing/meshing.hpp libsrc/include/../gprim/gprim.hpp \
  libsrc/include/linalg.hpp libsrc/include/../linalg/linalg.hpp \
  libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp \
  libsrc/include/../meshing/msghandler.hpp \
  libsrc/include/../meshing/meshtype.hpp \
  libsrc/include/../meshing/localh.hpp \
  libsrc/include/../meshing/meshclass.hpp \
  libsrc/include/../meshing/global.hpp \
  libsrc/include/../meshing/meshtool.hpp \
  libsrc/include/../meshing/ruler2.hpp \
  libsrc/include/../meshing/adfront2.hpp \
  libsrc/include/../meshing/meshing2.hpp \
  libsrc/include/../meshing/improve2.hpp \
  libsrc/include/../meshing/geomsearch.hpp \
  libsrc/include/../meshing/adfront3.hpp \
  libsrc/include/../meshing/ruler3.hpp \
  libsrc/include/../meshing/meshing3.hpp \
  libsrc/include/../meshing/improve3.hpp \
  libsrc/include/../meshing/findip.hpp \
  libsrc/include/../meshing/topology.hpp \
  libsrc/include/../meshing/curvedelems.hpp \
  libsrc/include/../meshing/bisect.hpp \
  libsrc/include/../meshing/clusters.hpp \
  libsrc/include/../meshing/meshfunc.hpp \
  libsrc/include/../meshing/hprefinement.hpp \
  libsrc/include/../meshing/boundarylayer.hpp \
  libsrc/include/../meshing/specials.hpp \
  libsrc/include/../csg/surface.hpp libsrc/include/../csg/solid.hpp \
  libsrc/include/../csg/identify.hpp \
  libsrc/include/../csg/singularref.hpp libsrc/include/../csg/csgeom.hpp \
  libsrc/include/../csg/triapprox.hpp libsrc/include/../csg/algprim.hpp \
  libsrc/include/../csg/brick.hpp libsrc/include/../csg/spline3d.hpp \
  libsrc/include/../csg/manifold.hpp libsrc/include/../csg/curve2d.hpp \
  libsrc/include/../csg/explicitcurve2d.hpp \
  libsrc/include/../csg/gencyl.hpp libsrc/include/../csg/polyhedra.hpp \
  libsrc/include/../csg/extrusion.hpp \
  libsrc/include/../csg/revolution.hpp libsrc/include/../csg/specpoin.hpp \
  libsrc/include/../csg/edgeflw.hpp libsrc/include/../csg/meshsurf.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
csgeom.o: libsrc/csg/csgeom.cpp libsrc/include/mystdlib.h \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/csg.hpp \
  libsrc/include/../csg/csg.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/meshing.hpp \
  libsrc/include/../meshing/meshing.hpp libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp \
  libsrc/include/../meshing/msghandler.hpp \
  libsrc/include/../meshing/meshtype.hpp \
  libsrc/include/../meshing/localh.hpp \
  libsrc/include/../meshing/meshclass.hpp \
  libsrc/include/../meshing/global.hpp \
  libsrc/include/../meshing/meshtool.hpp \
  libsrc/include/../meshing/ruler2.hpp \
  libsrc/include/../meshing/adfront2.hpp \
  libsrc/include/../meshing/meshing2.hpp \
  libsrc/include/../meshing/improve2.hpp \
  libsrc/include/../meshing/geomsearch.hpp \
  libsrc/include/../meshing/adfront3.hpp \
  libsrc/include/../meshing/ruler3.hpp \
  libsrc/include/../meshing/meshing3.hpp \
  libsrc/include/../meshing/improve3.hpp \
  libsrc/include/../meshing/findip.hpp \
  libsrc/include/../meshing/topology.hpp \
  libsrc/include/../meshing/curvedelems.hpp \
  libsrc/include/../meshing/bisect.hpp \
  libsrc/include/../meshing/clusters.hpp \
  libsrc/include/../meshing/meshfunc.hpp \
  libsrc/include/../meshing/hprefinement.hpp \
  libsrc/include/../meshing/boundarylayer.hpp \
  libsrc/include/../meshing/specials.hpp \
  libsrc/include/../csg/surface.hpp libsrc/include/../csg/solid.hpp \
  libsrc/include/../csg/identify.hpp \
  libsrc/include/../csg/singularref.hpp libsrc/include/../csg/csgeom.hpp \
  libsrc/include/../csg/triapprox.hpp libsrc/include/../csg/algprim.hpp \
  libsrc/include/../csg/brick.hpp libsrc/include/../csg/spline3d.hpp \
  libsrc/include/../csg/manifold.hpp libsrc/include/../csg/curve2d.hpp \
  libsrc/include/../csg/explicitcurve2d.hpp \
  libsrc/include/../csg/gencyl.hpp libsrc/include/../csg/polyhedra.hpp \
  libsrc/include/../csg/extrusion.hpp \
  libsrc/include/../csg/revolution.hpp libsrc/include/../csg/specpoin.hpp \
  libsrc/include/../csg/edgeflw.hpp libsrc/include/../csg/meshsurf.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
polyhedra.o: libsrc/csg/polyhedra.cpp libsrc/include/mystdlib.h \
  libsrc/include/linalg.hpp libsrc/include/../linalg/linalg.hpp \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp \
  libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/csg.hpp \
  libsrc/include/../csg/csg.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/meshing.hpp \
  libsrc/include/../meshing/meshing.hpp libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp \
  libsrc/include/../meshing/msghandler.hpp \
  libsrc/include/../meshing/meshtype.hpp \
  libsrc/include/../meshing/localh.hpp \
  libsrc/include/../meshing/meshclass.hpp \
  libsrc/include/../meshing/global.hpp \
  libsrc/include/../meshing/meshtool.hpp \
  libsrc/include/../meshing/ruler2.hpp \
  libsrc/include/../meshing/adfront2.hpp \
  libsrc/include/../meshing/meshing2.hpp \
  libsrc/include/../meshing/improve2.hpp \
  libsrc/include/../meshing/geomsearch.hpp \
  libsrc/include/../meshing/adfront3.hpp \
  libsrc/include/../meshing/ruler3.hpp \
  libsrc/include/../meshing/meshing3.hpp \
  libsrc/include/../meshing/improve3.hpp \
  libsrc/include/../meshing/findip.hpp \
  libsrc/include/../meshing/topology.hpp \
  libsrc/include/../meshing/curvedelems.hpp \
  libsrc/include/../meshing/bisect.hpp \
  libsrc/include/../meshing/clusters.hpp \
  libsrc/include/../meshing/meshfunc.hpp \
  libsrc/include/../meshing/hprefinement.hpp \
  libsrc/include/../meshing/boundarylayer.hpp \
  libsrc/include/../meshing/specials.hpp \
  libsrc/include/../csg/surface.hpp libsrc/include/../csg/solid.hpp \
  libsrc/include/../csg/identify.hpp \
  libsrc/include/../csg/singularref.hpp libsrc/include/../csg/csgeom.hpp \
  libsrc/include/../csg/triapprox.hpp libsrc/include/../csg/algprim.hpp \
  libsrc/include/../csg/brick.hpp libsrc/include/../csg/spline3d.hpp \
  libsrc/include/../csg/manifold.hpp libsrc/include/../csg/curve2d.hpp \
  libsrc/include/../csg/explicitcurve2d.hpp \
  libsrc/include/../csg/gencyl.hpp libsrc/include/../csg/polyhedra.hpp \
  libsrc/include/../csg/extrusion.hpp \
  libsrc/include/../csg/revolution.hpp libsrc/include/../csg/specpoin.hpp \
  libsrc/include/../csg/edgeflw.hpp libsrc/include/../csg/meshsurf.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
curve2d.o: libsrc/csg/curve2d.cpp libsrc/include/mystdlib.h \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/csg.hpp \
  libsrc/include/../csg/csg.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/meshing.hpp \
  libsrc/include/../meshing/meshing.hpp libsrc/include/../gprim/gprim.hpp \
  libsrc/include/linalg.hpp libsrc/include/../linalg/linalg.hpp \
  libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp \
  libsrc/include/../meshing/msghandler.hpp \
  libsrc/include/../meshing/meshtype.hpp \
  libsrc/include/../meshing/localh.hpp \
  libsrc/include/../meshing/meshclass.hpp \
  libsrc/include/../meshing/global.hpp \
  libsrc/include/../meshing/meshtool.hpp \
  libsrc/include/../meshing/ruler2.hpp \
  libsrc/include/../meshing/adfront2.hpp \
  libsrc/include/../meshing/meshing2.hpp \
  libsrc/include/../meshing/improve2.hpp \
  libsrc/include/../meshing/geomsearch.hpp \
  libsrc/include/../meshing/adfront3.hpp \
  libsrc/include/../meshing/ruler3.hpp \
  libsrc/include/../meshing/meshing3.hpp \
  libsrc/include/../meshing/improve3.hpp \
  libsrc/include/../meshing/findip.hpp \
  libsrc/include/../meshing/topology.hpp \
  libsrc/include/../meshing/curvedelems.hpp \
  libsrc/include/../meshing/bisect.hpp \
  libsrc/include/../meshing/clusters.hpp \
  libsrc/include/../meshing/meshfunc.hpp \
  libsrc/include/../meshing/hprefinement.hpp \
  libsrc/include/../meshing/boundarylayer.hpp \
  libsrc/include/../meshing/specials.hpp \
  libsrc/include/../csg/surface.hpp libsrc/include/../csg/solid.hpp \
  libsrc/include/../csg/identify.hpp \
  libsrc/include/../csg/singularref.hpp libsrc/include/../csg/csgeom.hpp \
  libsrc/include/../csg/triapprox.hpp libsrc/include/../csg/algprim.hpp \
  libsrc/include/../csg/brick.hpp libsrc/include/../csg/spline3d.hpp \
  libsrc/include/../csg/manifold.hpp libsrc/include/../csg/curve2d.hpp \
  libsrc/include/../csg/explicitcurve2d.hpp \
  libsrc/include/../csg/gencyl.hpp libsrc/include/../csg/polyhedra.hpp \
  libsrc/include/../csg/extrusion.hpp \
  libsrc/include/../csg/revolution.hpp libsrc/include/../csg/specpoin.hpp \
  libsrc/include/../csg/edgeflw.hpp libsrc/include/../csg/meshsurf.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
singularref.o: libsrc/csg/singularref.cpp libsrc/include/mystdlib.h \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/csg.hpp \
  libsrc/include/../csg/csg.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/meshing.hpp \
  libsrc/include/../meshing/meshing.hpp libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp \
  libsrc/include/../meshing/msghandler.hpp \
  libsrc/include/../meshing/meshtype.hpp \
  libsrc/include/../meshing/localh.hpp \
  libsrc/include/../meshing/meshclass.hpp \
  libsrc/include/../meshing/global.hpp \
  libsrc/include/../meshing/meshtool.hpp \
  libsrc/include/../meshing/ruler2.hpp \
  libsrc/include/../meshing/adfront2.hpp \
  libsrc/include/../meshing/meshing2.hpp \
  libsrc/include/../meshing/improve2.hpp \
  libsrc/include/../meshing/geomsearch.hpp \
  libsrc/include/../meshing/adfront3.hpp \
  libsrc/include/../meshing/ruler3.hpp \
  libsrc/include/../meshing/meshing3.hpp \
  libsrc/include/../meshing/improve3.hpp \
  libsrc/include/../meshing/findip.hpp \
  libsrc/include/../meshing/topology.hpp \
  libsrc/include/../meshing/curvedelems.hpp \
  libsrc/include/../meshing/bisect.hpp \
  libsrc/include/../meshing/clusters.hpp \
  libsrc/include/../meshing/meshfunc.hpp \
  libsrc/include/../meshing/hprefinement.hpp \
  libsrc/include/../meshing/boundarylayer.hpp \
  libsrc/include/../meshing/specials.hpp \
  libsrc/include/../csg/surface.hpp libsrc/include/../csg/solid.hpp \
  libsrc/include/../csg/identify.hpp \
  libsrc/include/../csg/singularref.hpp libsrc/include/../csg/csgeom.hpp \
  libsrc/include/../csg/triapprox.hpp libsrc/include/../csg/algprim.hpp \
  libsrc/include/../csg/brick.hpp libsrc/include/../csg/spline3d.hpp \
  libsrc/include/../csg/manifold.hpp libsrc/include/../csg/curve2d.hpp \
  libsrc/include/../csg/explicitcurve2d.hpp \
  libsrc/include/../csg/gencyl.hpp libsrc/include/../csg/polyhedra.hpp \
  libsrc/include/../csg/extrusion.hpp \
  libsrc/include/../csg/revolution.hpp libsrc/include/../csg/specpoin.hpp \
  libsrc/include/../csg/edgeflw.hpp libsrc/include/../csg/meshsurf.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
edgeflw.o: libsrc/csg/edgeflw.cpp libsrc/include/mystdlib.h \
  libsrc/include/meshing.hpp libsrc/include/../meshing/meshing.hpp \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp \
  libsrc/include/../meshing/msghandler.hpp \
  libsrc/include/../meshing/meshtype.hpp \
  libsrc/include/../meshing/localh.hpp \
  libsrc/include/../meshing/meshclass.hpp \
  libsrc/include/../meshing/global.hpp \
  libsrc/include/../meshing/meshtool.hpp \
  libsrc/include/../meshing/ruler2.hpp \
  libsrc/include/../meshing/adfront2.hpp \
  libsrc/include/../meshing/meshing2.hpp \
  libsrc/include/../meshing/improve2.hpp \
  libsrc/include/../meshing/geomsearch.hpp \
  libsrc/include/../meshing/adfront3.hpp \
  libsrc/include/../meshing/ruler3.hpp \
  libsrc/include/../meshing/meshing3.hpp \
  libsrc/include/../meshing/improve3.hpp \
  libsrc/include/../meshing/findip.hpp \
  libsrc/include/../meshing/topology.hpp \
  libsrc/include/../meshing/curvedelems.hpp \
  libsrc/include/../meshing/bisect.hpp \
  libsrc/include/../meshing/clusters.hpp \
  libsrc/include/../meshing/meshfunc.hpp \
  libsrc/include/../meshing/hprefinement.hpp \
  libsrc/include/../meshing/boundarylayer.hpp \
  libsrc/include/../meshing/specials.hpp libsrc/include/csg.hpp \
  libsrc/include/../csg/csg.hpp libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../csg/surface.hpp libsrc/include/../csg/solid.hpp \
  libsrc/include/../csg/identify.hpp \
  libsrc/include/../csg/singularref.hpp libsrc/include/../csg/csgeom.hpp \
  libsrc/include/../csg/triapprox.hpp libsrc/include/../csg/algprim.hpp \
  libsrc/include/../csg/brick.hpp libsrc/include/../csg/spline3d.hpp \
  libsrc/include/../csg/manifold.hpp libsrc/include/../csg/curve2d.hpp \
  libsrc/include/../csg/explicitcurve2d.hpp \
  libsrc/include/../csg/gencyl.hpp libsrc/include/../csg/polyhedra.hpp \
  libsrc/include/../csg/extrusion.hpp \
  libsrc/include/../csg/revolution.hpp libsrc/include/../csg/specpoin.hpp \
  libsrc/include/../csg/edgeflw.hpp libsrc/include/../csg/meshsurf.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
solid.o: libsrc/csg/solid.cpp libsrc/include/mystdlib.h \
  libsrc/include/linalg.hpp libsrc/include/../linalg/linalg.hpp \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp \
  libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/csg.hpp \
  libsrc/include/../csg/csg.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/meshing.hpp \
  libsrc/include/../meshing/meshing.hpp libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp \
  libsrc/include/../meshing/msghandler.hpp \
  libsrc/include/../meshing/meshtype.hpp \
  libsrc/include/../meshing/localh.hpp \
  libsrc/include/../meshing/meshclass.hpp \
  libsrc/include/../meshing/global.hpp \
  libsrc/include/../meshing/meshtool.hpp \
  libsrc/include/../meshing/ruler2.hpp \
  libsrc/include/../meshing/adfront2.hpp \
  libsrc/include/../meshing/meshing2.hpp \
  libsrc/include/../meshing/improve2.hpp \
  libsrc/include/../meshing/geomsearch.hpp \
  libsrc/include/../meshing/adfront3.hpp \
  libsrc/include/../meshing/ruler3.hpp \
  libsrc/include/../meshing/meshing3.hpp \
  libsrc/include/../meshing/improve3.hpp \
  libsrc/include/../meshing/findip.hpp \
  libsrc/include/../meshing/topology.hpp \
  libsrc/include/../meshing/curvedelems.hpp \
  libsrc/include/../meshing/bisect.hpp \
  libsrc/include/../meshing/clusters.hpp \
  libsrc/include/../meshing/meshfunc.hpp \
  libsrc/include/../meshing/hprefinement.hpp \
  libsrc/include/../meshing/boundarylayer.hpp \
  libsrc/include/../meshing/specials.hpp \
  libsrc/include/../csg/surface.hpp libsrc/include/../csg/solid.hpp \
  libsrc/include/../csg/identify.hpp \
  libsrc/include/../csg/singularref.hpp libsrc/include/../csg/csgeom.hpp \
  libsrc/include/../csg/triapprox.hpp libsrc/include/../csg/algprim.hpp \
  libsrc/include/../csg/brick.hpp libsrc/include/../csg/spline3d.hpp \
  libsrc/include/../csg/manifold.hpp libsrc/include/../csg/curve2d.hpp \
  libsrc/include/../csg/explicitcurve2d.hpp \
  libsrc/include/../csg/gencyl.hpp libsrc/include/../csg/polyhedra.hpp \
  libsrc/include/../csg/extrusion.hpp \
  libsrc/include/../csg/revolution.hpp libsrc/include/../csg/specpoin.hpp \
  libsrc/include/../csg/edgeflw.hpp libsrc/include/../csg/meshsurf.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
explicitcurve2d.o: libsrc/csg/explicitcurve2d.cpp \
  libsrc/include/mystdlib.h libsrc/include/csg.hpp \
  libsrc/include/../csg/csg.hpp libsrc/include/myadt.hpp \
  libsrc/include/../general/myadt.hpp libsrc/include/mydefs.hpp \
  libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/meshing.hpp \
  libsrc/include/../meshing/meshing.hpp libsrc/include/../gprim/gprim.hpp \
  libsrc/include/linalg.hpp libsrc/include/../linalg/linalg.hpp \
  libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp \
  libsrc/include/../meshing/msghandler.hpp \
  libsrc/include/../meshing/meshtype.hpp \
  libsrc/include/../meshing/localh.hpp \
  libsrc/include/../meshing/meshclass.hpp \
  libsrc/include/../meshing/global.hpp \
  libsrc/include/../meshing/meshtool.hpp \
  libsrc/include/../meshing/ruler2.hpp \
  libsrc/include/../meshing/adfront2.hpp \
  libsrc/include/../meshing/meshing2.hpp \
  libsrc/include/../meshing/improve2.hpp \
  libsrc/include/../meshing/geomsearch.hpp \
  libsrc/include/../meshing/adfront3.hpp \
  libsrc/include/../meshing/ruler3.hpp \
  libsrc/include/../meshing/meshing3.hpp \
  libsrc/include/../meshing/improve3.hpp \
  libsrc/include/../meshing/findip.hpp \
  libsrc/include/../meshing/topology.hpp \
  libsrc/include/../meshing/curvedelems.hpp \
  libsrc/include/../meshing/bisect.hpp \
  libsrc/include/../meshing/clusters.hpp \
  libsrc/include/../meshing/meshfunc.hpp \
  libsrc/include/../meshing/hprefinement.hpp \
  libsrc/include/../meshing/boundarylayer.hpp \
  libsrc/include/../meshing/specials.hpp \
  libsrc/include/../csg/surface.hpp libsrc/include/../csg/solid.hpp \
  libsrc/include/../csg/identify.hpp \
  libsrc/include/../csg/singularref.hpp libsrc/include/../csg/csgeom.hpp \
  libsrc/include/../csg/triapprox.hpp libsrc/include/../csg/algprim.hpp \
  libsrc/include/../csg/brick.hpp libsrc/include/../csg/spline3d.hpp \
  libsrc/include/../csg/manifold.hpp libsrc/include/../csg/curve2d.hpp \
  libsrc/include/../csg/explicitcurve2d.hpp \
  libsrc/include/../csg/gencyl.hpp libsrc/include/../csg/polyhedra.hpp \
  libsrc/include/../csg/extrusion.hpp \
  libsrc/include/../csg/revolution.hpp libsrc/include/../csg/specpoin.hpp \
  libsrc/include/../csg/edgeflw.hpp libsrc/include/../csg/meshsurf.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
specpoin.o: libsrc/csg/specpoin.cpp libsrc/include/mystdlib.h \
  libsrc/include/meshing.hpp libsrc/include/../meshing/meshing.hpp \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp \
  libsrc/include/../meshing/msghandler.hpp \
  libsrc/include/../meshing/meshtype.hpp \
  libsrc/include/../meshing/localh.hpp \
  libsrc/include/../meshing/meshclass.hpp \
  libsrc/include/../meshing/global.hpp \
  libsrc/include/../meshing/meshtool.hpp \
  libsrc/include/../meshing/ruler2.hpp \
  libsrc/include/../meshing/adfront2.hpp \
  libsrc/include/../meshing/meshing2.hpp \
  libsrc/include/../meshing/improve2.hpp \
  libsrc/include/../meshing/geomsearch.hpp \
  libsrc/include/../meshing/adfront3.hpp \
  libsrc/include/../meshing/ruler3.hpp \
  libsrc/include/../meshing/meshing3.hpp \
  libsrc/include/../meshing/improve3.hpp \
  libsrc/include/../meshing/findip.hpp \
  libsrc/include/../meshing/topology.hpp \
  libsrc/include/../meshing/curvedelems.hpp \
  libsrc/include/../meshing/bisect.hpp \
  libsrc/include/../meshing/clusters.hpp \
  libsrc/include/../meshing/meshfunc.hpp \
  libsrc/include/../meshing/hprefinement.hpp \
  libsrc/include/../meshing/boundarylayer.hpp \
  libsrc/include/../meshing/specials.hpp libsrc/include/csg.hpp \
  libsrc/include/../csg/csg.hpp libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../csg/surface.hpp libsrc/include/../csg/solid.hpp \
  libsrc/include/../csg/identify.hpp \
  libsrc/include/../csg/singularref.hpp libsrc/include/../csg/csgeom.hpp \
  libsrc/include/../csg/triapprox.hpp libsrc/include/../csg/algprim.hpp \
  libsrc/include/../csg/brick.hpp libsrc/include/../csg/spline3d.hpp \
  libsrc/include/../csg/manifold.hpp libsrc/include/../csg/curve2d.hpp \
  libsrc/include/../csg/explicitcurve2d.hpp \
  libsrc/include/../csg/gencyl.hpp libsrc/include/../csg/polyhedra.hpp \
  libsrc/include/../csg/extrusion.hpp \
  libsrc/include/../csg/revolution.hpp libsrc/include/../csg/specpoin.hpp \
  libsrc/include/../csg/edgeflw.hpp libsrc/include/../csg/meshsurf.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
gencyl.o: libsrc/csg/gencyl.cpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/myadt.hpp \
  libsrc/include/../general/myadt.hpp libsrc/include/mystdlib.h \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp \
  libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/csg.hpp \
  libsrc/include/../csg/csg.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/meshing.hpp \
  libsrc/include/../meshing/meshing.hpp libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp \
  libsrc/include/../meshing/msghandler.hpp \
  libsrc/include/../meshing/meshtype.hpp \
  libsrc/include/../meshing/localh.hpp \
  libsrc/include/../meshing/meshclass.hpp \
  libsrc/include/../meshing/global.hpp \
  libsrc/include/../meshing/meshtool.hpp \
  libsrc/include/../meshing/ruler2.hpp \
  libsrc/include/../meshing/adfront2.hpp \
  libsrc/include/../meshing/meshing2.hpp \
  libsrc/include/../meshing/improve2.hpp \
  libsrc/include/../meshing/geomsearch.hpp \
  libsrc/include/../meshing/adfront3.hpp \
  libsrc/include/../meshing/ruler3.hpp \
  libsrc/include/../meshing/meshing3.hpp \
  libsrc/include/../meshing/improve3.hpp \
  libsrc/include/../meshing/findip.hpp \
  libsrc/include/../meshing/topology.hpp \
  libsrc/include/../meshing/curvedelems.hpp \
  libsrc/include/../meshing/bisect.hpp \
  libsrc/include/../meshing/clusters.hpp \
  libsrc/include/../meshing/meshfunc.hpp \
  libsrc/include/../meshing/hprefinement.hpp \
  libsrc/include/../meshing/boundarylayer.hpp \
  libsrc/include/../meshing/specials.hpp \
  libsrc/include/../csg/surface.hpp libsrc/include/../csg/solid.hpp \
  libsrc/include/../csg/identify.hpp \
  libsrc/include/../csg/singularref.hpp libsrc/include/../csg/csgeom.hpp \
  libsrc/include/../csg/triapprox.hpp libsrc/include/../csg/algprim.hpp \
  libsrc/include/../csg/brick.hpp libsrc/include/../csg/spline3d.hpp \
  libsrc/include/../csg/manifold.hpp libsrc/include/../csg/curve2d.hpp \
  libsrc/include/../csg/explicitcurve2d.hpp \
  libsrc/include/../csg/gencyl.hpp libsrc/include/../csg/polyhedra.hpp \
  libsrc/include/../csg/extrusion.hpp \
  libsrc/include/../csg/revolution.hpp libsrc/include/../csg/specpoin.hpp \
  libsrc/include/../csg/edgeflw.hpp libsrc/include/../csg/meshsurf.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
revolution.o: libsrc/csg/revolution.cpp libsrc/include/mystdlib.h \
  libsrc/include/linalg.hpp libsrc/include/../linalg/linalg.hpp \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp \
  libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/csg.hpp \
  libsrc/include/../csg/csg.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/meshing.hpp \
  libsrc/include/../meshing/meshing.hpp libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp \
  libsrc/include/../meshing/msghandler.hpp \
  libsrc/include/../meshing/meshtype.hpp \
  libsrc/include/../meshing/localh.hpp \
  libsrc/include/../meshing/meshclass.hpp \
  libsrc/include/../meshing/global.hpp \
  libsrc/include/../meshing/meshtool.hpp \
  libsrc/include/../meshing/ruler2.hpp \
  libsrc/include/../meshing/adfront2.hpp \
  libsrc/include/../meshing/meshing2.hpp \
  libsrc/include/../meshing/improve2.hpp \
  libsrc/include/../meshing/geomsearch.hpp \
  libsrc/include/../meshing/adfront3.hpp \
  libsrc/include/../meshing/ruler3.hpp \
  libsrc/include/../meshing/meshing3.hpp \
  libsrc/include/../meshing/improve3.hpp \
  libsrc/include/../meshing/findip.hpp \
  libsrc/include/../meshing/topology.hpp \
  libsrc/include/../meshing/curvedelems.hpp \
  libsrc/include/../meshing/bisect.hpp \
  libsrc/include/../meshing/clusters.hpp \
  libsrc/include/../meshing/meshfunc.hpp \
  libsrc/include/../meshing/hprefinement.hpp \
  libsrc/include/../meshing/boundarylayer.hpp \
  libsrc/include/../meshing/specials.hpp \
  libsrc/include/../csg/surface.hpp libsrc/include/../csg/solid.hpp \
  libsrc/include/../csg/identify.hpp \
  libsrc/include/../csg/singularref.hpp libsrc/include/../csg/csgeom.hpp \
  libsrc/include/../csg/triapprox.hpp libsrc/include/../csg/algprim.hpp \
  libsrc/include/../csg/brick.hpp libsrc/include/../csg/spline3d.hpp \
  libsrc/include/../csg/manifold.hpp libsrc/include/../csg/curve2d.hpp \
  libsrc/include/../csg/explicitcurve2d.hpp \
  libsrc/include/../csg/gencyl.hpp libsrc/include/../csg/polyhedra.hpp \
  libsrc/include/../csg/extrusion.hpp \
  libsrc/include/../csg/revolution.hpp libsrc/include/../csg/specpoin.hpp \
  libsrc/include/../csg/edgeflw.hpp libsrc/include/../csg/meshsurf.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
genmesh.o: libsrc/csg/genmesh.cpp libsrc/include/mystdlib.h \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/csg.hpp \
  libsrc/include/../csg/csg.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/meshing.hpp \
  libsrc/include/../meshing/meshing.hpp libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp \
  libsrc/include/../meshing/msghandler.hpp \
  libsrc/include/../meshing/meshtype.hpp \
  libsrc/include/../meshing/localh.hpp \
  libsrc/include/../meshing/meshclass.hpp \
  libsrc/include/../meshing/global.hpp \
  libsrc/include/../meshing/meshtool.hpp \
  libsrc/include/../meshing/ruler2.hpp \
  libsrc/include/../meshing/adfront2.hpp \
  libsrc/include/../meshing/meshing2.hpp \
  libsrc/include/../meshing/improve2.hpp \
  libsrc/include/../meshing/geomsearch.hpp \
  libsrc/include/../meshing/adfront3.hpp \
  libsrc/include/../meshing/ruler3.hpp \
  libsrc/include/../meshing/meshing3.hpp \
  libsrc/include/../meshing/improve3.hpp \
  libsrc/include/../meshing/findip.hpp \
  libsrc/include/../meshing/topology.hpp \
  libsrc/include/../meshing/curvedelems.hpp \
  libsrc/include/../meshing/bisect.hpp \
  libsrc/include/../meshing/clusters.hpp \
  libsrc/include/../meshing/meshfunc.hpp \
  libsrc/include/../meshing/hprefinement.hpp \
  libsrc/include/../meshing/boundarylayer.hpp \
  libsrc/include/../meshing/specials.hpp \
  libsrc/include/../csg/surface.hpp libsrc/include/../csg/solid.hpp \
  libsrc/include/../csg/identify.hpp \
  libsrc/include/../csg/singularref.hpp libsrc/include/../csg/csgeom.hpp \
  libsrc/include/../csg/triapprox.hpp libsrc/include/../csg/algprim.hpp \
  libsrc/include/../csg/brick.hpp libsrc/include/../csg/spline3d.hpp \
  libsrc/include/../csg/manifold.hpp libsrc/include/../csg/curve2d.hpp \
  libsrc/include/../csg/explicitcurve2d.hpp \
  libsrc/include/../csg/gencyl.hpp libsrc/include/../csg/polyhedra.hpp \
  libsrc/include/../csg/extrusion.hpp \
  libsrc/include/../csg/revolution.hpp libsrc/include/../csg/specpoin.hpp \
  libsrc/include/../csg/edgeflw.hpp libsrc/include/../csg/meshsurf.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
spline3d.o: libsrc/csg/spline3d.cpp libsrc/include/mystdlib.h \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/csg.hpp \
  libsrc/include/../csg/csg.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/meshing.hpp \
  libsrc/include/../meshing/meshing.hpp libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp \
  libsrc/include/../meshing/msghandler.hpp \
  libsrc/include/../meshing/meshtype.hpp \
  libsrc/include/../meshing/localh.hpp \
  libsrc/include/../meshing/meshclass.hpp \
  libsrc/include/../meshing/global.hpp \
  libsrc/include/../meshing/meshtool.hpp \
  libsrc/include/../meshing/ruler2.hpp \
  libsrc/include/../meshing/adfront2.hpp \
  libsrc/include/../meshing/meshing2.hpp \
  libsrc/include/../meshing/improve2.hpp \
  libsrc/include/../meshing/geomsearch.hpp \
  libsrc/include/../meshing/adfront3.hpp \
  libsrc/include/../meshing/ruler3.hpp \
  libsrc/include/../meshing/meshing3.hpp \
  libsrc/include/../meshing/improve3.hpp \
  libsrc/include/../meshing/findip.hpp \
  libsrc/include/../meshing/topology.hpp \
  libsrc/include/../meshing/curvedelems.hpp \
  libsrc/include/../meshing/bisect.hpp \
  libsrc/include/../meshing/clusters.hpp \
  libsrc/include/../meshing/meshfunc.hpp \
  libsrc/include/../meshing/hprefinement.hpp \
  libsrc/include/../meshing/boundarylayer.hpp \
  libsrc/include/../meshing/specials.hpp \
  libsrc/include/../csg/surface.hpp libsrc/include/../csg/solid.hpp \
  libsrc/include/../csg/identify.hpp \
  libsrc/include/../csg/singularref.hpp libsrc/include/../csg/csgeom.hpp \
  libsrc/include/../csg/triapprox.hpp libsrc/include/../csg/algprim.hpp \
  libsrc/include/../csg/brick.hpp libsrc/include/../csg/spline3d.hpp \
  libsrc/include/../csg/manifold.hpp libsrc/include/../csg/curve2d.hpp \
  libsrc/include/../csg/explicitcurve2d.hpp \
  libsrc/include/../csg/gencyl.hpp libsrc/include/../csg/polyhedra.hpp \
  libsrc/include/../csg/extrusion.hpp \
  libsrc/include/../csg/revolution.hpp libsrc/include/../csg/specpoin.hpp \
  libsrc/include/../csg/edgeflw.hpp libsrc/include/../csg/meshsurf.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
surface.o: libsrc/csg/surface.cpp libsrc/include/mystdlib.h \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/csg.hpp \
  libsrc/include/../csg/csg.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/meshing.hpp \
  libsrc/include/../meshing/meshing.hpp libsrc/include/../gprim/gprim.hpp \
  libsrc/include/linalg.hpp libsrc/include/../linalg/linalg.hpp \
  libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp \
  libsrc/include/../meshing/msghandler.hpp \
  libsrc/include/../meshing/meshtype.hpp \
  libsrc/include/../meshing/localh.hpp \
  libsrc/include/../meshing/meshclass.hpp \
  libsrc/include/../meshing/global.hpp \
  libsrc/include/../meshing/meshtool.hpp \
  libsrc/include/../meshing/ruler2.hpp \
  libsrc/include/../meshing/adfront2.hpp \
  libsrc/include/../meshing/meshing2.hpp \
  libsrc/include/../meshing/improve2.hpp \
  libsrc/include/../meshing/geomsearch.hpp \
  libsrc/include/../meshing/adfront3.hpp \
  libsrc/include/../meshing/ruler3.hpp \
  libsrc/include/../meshing/meshing3.hpp \
  libsrc/include/../meshing/improve3.hpp \
  libsrc/include/../meshing/findip.hpp \
  libsrc/include/../meshing/topology.hpp \
  libsrc/include/../meshing/curvedelems.hpp \
  libsrc/include/../meshing/bisect.hpp \
  libsrc/include/../meshing/clusters.hpp \
  libsrc/include/../meshing/meshfunc.hpp \
  libsrc/include/../meshing/hprefinement.hpp \
  libsrc/include/../meshing/boundarylayer.hpp \
  libsrc/include/../meshing/specials.hpp \
  libsrc/include/../csg/surface.hpp libsrc/include/../csg/solid.hpp \
  libsrc/include/../csg/identify.hpp \
  libsrc/include/../csg/singularref.hpp libsrc/include/../csg/csgeom.hpp \
  libsrc/include/../csg/triapprox.hpp libsrc/include/../csg/algprim.hpp \
  libsrc/include/../csg/brick.hpp libsrc/include/../csg/spline3d.hpp \
  libsrc/include/../csg/manifold.hpp libsrc/include/../csg/curve2d.hpp \
  libsrc/include/../csg/explicitcurve2d.hpp \
  libsrc/include/../csg/gencyl.hpp libsrc/include/../csg/polyhedra.hpp \
  libsrc/include/../csg/extrusion.hpp \
  libsrc/include/../csg/revolution.hpp libsrc/include/../csg/specpoin.hpp \
  libsrc/include/../csg/edgeflw.hpp libsrc/include/../csg/meshsurf.hpp \
  libsrc/include/../linalg/linalg.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
identify.o: libsrc/csg/identify.cpp libsrc/include/mystdlib.h \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/csg.hpp \
  libsrc/include/../csg/csg.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/meshing.hpp \
  libsrc/include/../meshing/meshing.hpp libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp \
  libsrc/include/../meshing/msghandler.hpp \
  libsrc/include/../meshing/meshtype.hpp \
  libsrc/include/../meshing/localh.hpp \
  libsrc/include/../meshing/meshclass.hpp \
  libsrc/include/../meshing/global.hpp \
  libsrc/include/../meshing/meshtool.hpp \
  libsrc/include/../meshing/ruler2.hpp \
  libsrc/include/../meshing/adfront2.hpp \
  libsrc/include/../meshing/meshing2.hpp \
  libsrc/include/../meshing/improve2.hpp \
  libsrc/include/../meshing/geomsearch.hpp \
  libsrc/include/../meshing/adfront3.hpp \
  libsrc/include/../meshing/ruler3.hpp \
  libsrc/include/../meshing/meshing3.hpp \
  libsrc/include/../meshing/improve3.hpp \
  libsrc/include/../meshing/findip.hpp \
  libsrc/include/../meshing/topology.hpp \
  libsrc/include/../meshing/curvedelems.hpp \
  libsrc/include/../meshing/bisect.hpp \
  libsrc/include/../meshing/clusters.hpp \
  libsrc/include/../meshing/meshfunc.hpp \
  libsrc/include/../meshing/hprefinement.hpp \
  libsrc/include/../meshing/boundarylayer.hpp \
  libsrc/include/../meshing/specials.hpp \
  libsrc/include/../csg/surface.hpp libsrc/include/../csg/solid.hpp \
  libsrc/include/../csg/identify.hpp \
  libsrc/include/../csg/singularref.hpp libsrc/include/../csg/csgeom.hpp \
  libsrc/include/../csg/triapprox.hpp libsrc/include/../csg/algprim.hpp \
  libsrc/include/../csg/brick.hpp libsrc/include/../csg/spline3d.hpp \
  libsrc/include/../csg/manifold.hpp libsrc/include/../csg/curve2d.hpp \
  libsrc/include/../csg/explicitcurve2d.hpp \
  libsrc/include/../csg/gencyl.hpp libsrc/include/../csg/polyhedra.hpp \
  libsrc/include/../csg/extrusion.hpp \
  libsrc/include/../csg/revolution.hpp libsrc/include/../csg/specpoin.hpp \
  libsrc/include/../csg/edgeflw.hpp libsrc/include/../csg/meshsurf.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
triapprox.o: libsrc/csg/triapprox.cpp libsrc/include/mystdlib.h \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/csg.hpp \
  libsrc/include/../csg/csg.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/meshing.hpp \
  libsrc/include/../meshing/meshing.hpp libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp \
  libsrc/include/../meshing/msghandler.hpp \
  libsrc/include/../meshing/meshtype.hpp \
  libsrc/include/../meshing/localh.hpp \
  libsrc/include/../meshing/meshclass.hpp \
  libsrc/include/../meshing/global.hpp \
  libsrc/include/../meshing/meshtool.hpp \
  libsrc/include/../meshing/ruler2.hpp \
  libsrc/include/../meshing/adfront2.hpp \
  libsrc/include/../meshing/meshing2.hpp \
  libsrc/include/../meshing/improve2.hpp \
  libsrc/include/../meshing/geomsearch.hpp \
  libsrc/include/../meshing/adfront3.hpp \
  libsrc/include/../meshing/ruler3.hpp \
  libsrc/include/../meshing/meshing3.hpp \
  libsrc/include/../meshing/improve3.hpp \
  libsrc/include/../meshing/findip.hpp \
  libsrc/include/../meshing/topology.hpp \
  libsrc/include/../meshing/curvedelems.hpp \
  libsrc/include/../meshing/bisect.hpp \
  libsrc/include/../meshing/clusters.hpp \
  libsrc/include/../meshing/meshfunc.hpp \
  libsrc/include/../meshing/hprefinement.hpp \
  libsrc/include/../meshing/boundarylayer.hpp \
  libsrc/include/../meshing/specials.hpp \
  libsrc/include/../csg/surface.hpp libsrc/include/../csg/solid.hpp \
  libsrc/include/../csg/identify.hpp \
  libsrc/include/../csg/singularref.hpp libsrc/include/../csg/csgeom.hpp \
  libsrc/include/../csg/triapprox.hpp libsrc/include/../csg/algprim.hpp \
  libsrc/include/../csg/brick.hpp libsrc/include/../csg/spline3d.hpp \
  libsrc/include/../csg/manifold.hpp libsrc/include/../csg/curve2d.hpp \
  libsrc/include/../csg/explicitcurve2d.hpp \
  libsrc/include/../csg/gencyl.hpp libsrc/include/../csg/polyhedra.hpp \
  libsrc/include/../csg/extrusion.hpp \
  libsrc/include/../csg/revolution.hpp libsrc/include/../csg/specpoin.hpp \
  libsrc/include/../csg/edgeflw.hpp libsrc/include/../csg/meshsurf.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
geom2dmesh.o: libsrc/geom2d/geom2dmesh.cpp libsrc/include/mystdlib.h \
  libsrc/include/csg.hpp libsrc/include/../csg/csg.hpp \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/meshing.hpp \
  libsrc/include/../meshing/meshing.hpp libsrc/include/../gprim/gprim.hpp \
  libsrc/include/linalg.hpp libsrc/include/../linalg/linalg.hpp \
  libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp \
  libsrc/include/../meshing/msghandler.hpp \
  libsrc/include/../meshing/meshtype.hpp \
  libsrc/include/../meshing/localh.hpp \
  libsrc/include/../meshing/meshclass.hpp \
  libsrc/include/../meshing/global.hpp \
  libsrc/include/../meshing/meshtool.hpp \
  libsrc/include/../meshing/ruler2.hpp \
  libsrc/include/../meshing/adfront2.hpp \
  libsrc/include/../meshing/meshing2.hpp \
  libsrc/include/../meshing/improve2.hpp \
  libsrc/include/../meshing/geomsearch.hpp \
  libsrc/include/../meshing/adfront3.hpp \
  libsrc/include/../meshing/ruler3.hpp \
  libsrc/include/../meshing/meshing3.hpp \
  libsrc/include/../meshing/improve3.hpp \
  libsrc/include/../meshing/findip.hpp \
  libsrc/include/../meshing/topology.hpp \
  libsrc/include/../meshing/curvedelems.hpp \
  libsrc/include/../meshing/bisect.hpp \
  libsrc/include/../meshing/clusters.hpp \
  libsrc/include/../meshing/meshfunc.hpp \
  libsrc/include/../meshing/hprefinement.hpp \
  libsrc/include/../meshing/boundarylayer.hpp \
  libsrc/include/../meshing/specials.hpp \
  libsrc/include/../csg/surface.hpp libsrc/include/../csg/solid.hpp \
  libsrc/include/../csg/identify.hpp \
  libsrc/include/../csg/singularref.hpp libsrc/include/../csg/csgeom.hpp \
  libsrc/include/../csg/triapprox.hpp libsrc/include/../csg/algprim.hpp \
  libsrc/include/../csg/brick.hpp libsrc/include/../csg/spline3d.hpp \
  libsrc/include/../csg/manifold.hpp libsrc/include/../csg/curve2d.hpp \
  libsrc/include/../csg/explicitcurve2d.hpp \
  libsrc/include/../csg/gencyl.hpp libsrc/include/../csg/polyhedra.hpp \
  libsrc/include/../csg/extrusion.hpp \
  libsrc/include/../csg/revolution.hpp libsrc/include/../csg/specpoin.hpp \
  libsrc/include/../csg/edgeflw.hpp libsrc/include/../csg/meshsurf.hpp \
  libsrc/include/geometry2d.hpp libsrc/include/../geom2d/geometry2d.hpp \
  libsrc/include/../gprim/gprim.hpp libsrc/include/../geom2d/spline2d.hpp \
  libsrc/include/../geom2d/splinegeometry2.hpp \
  libsrc/include/../geom2d/geom2dmesh.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
spline2d.o: libsrc/geom2d/spline2d.cpp libsrc/include/mystdlib.h \
  libsrc/include/csg.hpp libsrc/include/../csg/csg.hpp \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/meshing.hpp \
  libsrc/include/../meshing/meshing.hpp libsrc/include/../gprim/gprim.hpp \
  libsrc/include/linalg.hpp libsrc/include/../linalg/linalg.hpp \
  libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp \
  libsrc/include/../meshing/msghandler.hpp \
  libsrc/include/../meshing/meshtype.hpp \
  libsrc/include/../meshing/localh.hpp \
  libsrc/include/../meshing/meshclass.hpp \
  libsrc/include/../meshing/global.hpp \
  libsrc/include/../meshing/meshtool.hpp \
  libsrc/include/../meshing/ruler2.hpp \
  libsrc/include/../meshing/adfront2.hpp \
  libsrc/include/../meshing/meshing2.hpp \
  libsrc/include/../meshing/improve2.hpp \
  libsrc/include/../meshing/geomsearch.hpp \
  libsrc/include/../meshing/adfront3.hpp \
  libsrc/include/../meshing/ruler3.hpp \
  libsrc/include/../meshing/meshing3.hpp \
  libsrc/include/../meshing/improve3.hpp \
  libsrc/include/../meshing/findip.hpp \
  libsrc/include/../meshing/topology.hpp \
  libsrc/include/../meshing/curvedelems.hpp \
  libsrc/include/../meshing/bisect.hpp \
  libsrc/include/../meshing/clusters.hpp \
  libsrc/include/../meshing/meshfunc.hpp \
  libsrc/include/../meshing/hprefinement.hpp \
  libsrc/include/../meshing/boundarylayer.hpp \
  libsrc/include/../meshing/specials.hpp \
  libsrc/include/../csg/surface.hpp libsrc/include/../csg/solid.hpp \
  libsrc/include/../csg/identify.hpp \
  libsrc/include/../csg/singularref.hpp libsrc/include/../csg/csgeom.hpp \
  libsrc/include/../csg/triapprox.hpp libsrc/include/../csg/algprim.hpp \
  libsrc/include/../csg/brick.hpp libsrc/include/../csg/spline3d.hpp \
  libsrc/include/../csg/manifold.hpp libsrc/include/../csg/curve2d.hpp \
  libsrc/include/../csg/explicitcurve2d.hpp \
  libsrc/include/../csg/gencyl.hpp libsrc/include/../csg/polyhedra.hpp \
  libsrc/include/../csg/extrusion.hpp \
  libsrc/include/../csg/revolution.hpp libsrc/include/../csg/specpoin.hpp \
  libsrc/include/../csg/edgeflw.hpp libsrc/include/../csg/meshsurf.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/geom2d/spline2d.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
splinegeometry2.o: libsrc/geom2d/splinegeometry2.cpp \
  libsrc/include/mystdlib.h libsrc/include/csg.hpp \
  libsrc/include/../csg/csg.hpp libsrc/include/myadt.hpp \
  libsrc/include/../general/myadt.hpp libsrc/include/mydefs.hpp \
  libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/meshing.hpp \
  libsrc/include/../meshing/meshing.hpp libsrc/include/../gprim/gprim.hpp \
  libsrc/include/linalg.hpp libsrc/include/../linalg/linalg.hpp \
  libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp \
  libsrc/include/../meshing/msghandler.hpp \
  libsrc/include/../meshing/meshtype.hpp \
  libsrc/include/../meshing/localh.hpp \
  libsrc/include/../meshing/meshclass.hpp \
  libsrc/include/../meshing/global.hpp \
  libsrc/include/../meshing/meshtool.hpp \
  libsrc/include/../meshing/ruler2.hpp \
  libsrc/include/../meshing/adfront2.hpp \
  libsrc/include/../meshing/meshing2.hpp \
  libsrc/include/../meshing/improve2.hpp \
  libsrc/include/../meshing/geomsearch.hpp \
  libsrc/include/../meshing/adfront3.hpp \
  libsrc/include/../meshing/ruler3.hpp \
  libsrc/include/../meshing/meshing3.hpp \
  libsrc/include/../meshing/improve3.hpp \
  libsrc/include/../meshing/findip.hpp \
  libsrc/include/../meshing/topology.hpp \
  libsrc/include/../meshing/curvedelems.hpp \
  libsrc/include/../meshing/bisect.hpp \
  libsrc/include/../meshing/clusters.hpp \
  libsrc/include/../meshing/meshfunc.hpp \
  libsrc/include/../meshing/hprefinement.hpp \
  libsrc/include/../meshing/boundarylayer.hpp \
  libsrc/include/../meshing/specials.hpp \
  libsrc/include/../csg/surface.hpp libsrc/include/../csg/solid.hpp \
  libsrc/include/../csg/identify.hpp \
  libsrc/include/../csg/singularref.hpp libsrc/include/../csg/csgeom.hpp \
  libsrc/include/../csg/triapprox.hpp libsrc/include/../csg/algprim.hpp \
  libsrc/include/../csg/brick.hpp libsrc/include/../csg/spline3d.hpp \
  libsrc/include/../csg/manifold.hpp libsrc/include/../csg/curve2d.hpp \
  libsrc/include/../csg/explicitcurve2d.hpp \
  libsrc/include/../csg/gencyl.hpp libsrc/include/../csg/polyhedra.hpp \
  libsrc/include/../csg/extrusion.hpp \
  libsrc/include/../csg/revolution.hpp libsrc/include/../csg/specpoin.hpp \
  libsrc/include/../csg/edgeflw.hpp libsrc/include/../csg/meshsurf.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/geom2d/spline2d.hpp \
  libsrc/geom2d/splinegeometry2.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
genmesh2d.o: libsrc/geom2d/genmesh2d.cpp libsrc/include/mystdlib.h \
  libsrc/include/csg.hpp libsrc/include/../csg/csg.hpp \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/meshing.hpp \
  libsrc/include/../meshing/meshing.hpp libsrc/include/../gprim/gprim.hpp \
  libsrc/include/linalg.hpp libsrc/include/../linalg/linalg.hpp \
  libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp \
  libsrc/include/../meshing/msghandler.hpp \
  libsrc/include/../meshing/meshtype.hpp \
  libsrc/include/../meshing/localh.hpp \
  libsrc/include/../meshing/meshclass.hpp \
  libsrc/include/../meshing/global.hpp \
  libsrc/include/../meshing/meshtool.hpp \
  libsrc/include/../meshing/ruler2.hpp \
  libsrc/include/../meshing/adfront2.hpp \
  libsrc/include/../meshing/meshing2.hpp \
  libsrc/include/../meshing/improve2.hpp \
  libsrc/include/../meshing/geomsearch.hpp \
  libsrc/include/../meshing/adfront3.hpp \
  libsrc/include/../meshing/ruler3.hpp \
  libsrc/include/../meshing/meshing3.hpp \
  libsrc/include/../meshing/improve3.hpp \
  libsrc/include/../meshing/findip.hpp \
  libsrc/include/../meshing/topology.hpp \
  libsrc/include/../meshing/curvedelems.hpp \
  libsrc/include/../meshing/bisect.hpp \
  libsrc/include/../meshing/clusters.hpp \
  libsrc/include/../meshing/meshfunc.hpp \
  libsrc/include/../meshing/hprefinement.hpp \
  libsrc/include/../meshing/boundarylayer.hpp \
  libsrc/include/../meshing/specials.hpp \
  libsrc/include/../csg/surface.hpp libsrc/include/../csg/solid.hpp \
  libsrc/include/../csg/identify.hpp \
  libsrc/include/../csg/singularref.hpp libsrc/include/../csg/csgeom.hpp \
  libsrc/include/../csg/triapprox.hpp libsrc/include/../csg/algprim.hpp \
  libsrc/include/../csg/brick.hpp libsrc/include/../csg/spline3d.hpp \
  libsrc/include/../csg/manifold.hpp libsrc/include/../csg/curve2d.hpp \
  libsrc/include/../csg/explicitcurve2d.hpp \
  libsrc/include/../csg/gencyl.hpp libsrc/include/../csg/polyhedra.hpp \
  libsrc/include/../csg/extrusion.hpp \
  libsrc/include/../csg/revolution.hpp libsrc/include/../csg/specpoin.hpp \
  libsrc/include/../csg/edgeflw.hpp libsrc/include/../csg/meshsurf.hpp \
  libsrc/include/geometry2d.hpp libsrc/include/../geom2d/geometry2d.hpp \
  libsrc/include/../gprim/gprim.hpp libsrc/include/../geom2d/spline2d.hpp \
  libsrc/include/../geom2d/splinegeometry2.hpp \
  libsrc/include/../geom2d/geom2dmesh.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
meshstlsurface.o: libsrc/stlgeom/meshstlsurface.cpp \
  libsrc/include/mystdlib.h libsrc/include/myadt.hpp \
  libsrc/include/../general/myadt.hpp libsrc/include/mydefs.hpp \
  libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/meshing.hpp \
  libsrc/include/../meshing/meshing.hpp libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp \
  libsrc/include/../meshing/msghandler.hpp \
  libsrc/include/../meshing/meshtype.hpp \
  libsrc/include/../meshing/localh.hpp \
  libsrc/include/../meshing/meshclass.hpp \
  libsrc/include/../meshing/global.hpp \
  libsrc/include/../meshing/meshtool.hpp \
  libsrc/include/../meshing/ruler2.hpp \
  libsrc/include/../meshing/adfront2.hpp \
  libsrc/include/../meshing/meshing2.hpp \
  libsrc/include/../meshing/improve2.hpp \
  libsrc/include/../meshing/geomsearch.hpp \
  libsrc/include/../meshing/adfront3.hpp \
  libsrc/include/../meshing/ruler3.hpp \
  libsrc/include/../meshing/meshing3.hpp \
  libsrc/include/../meshing/improve3.hpp \
  libsrc/include/../meshing/findip.hpp \
  libsrc/include/../meshing/topology.hpp \
  libsrc/include/../meshing/curvedelems.hpp \
  libsrc/include/../meshing/bisect.hpp \
  libsrc/include/../meshing/clusters.hpp \
  libsrc/include/../meshing/meshfunc.hpp \
  libsrc/include/../meshing/hprefinement.hpp \
  libsrc/include/../meshing/boundarylayer.hpp \
  libsrc/include/../meshing/specials.hpp libsrc/stlgeom/stlgeom.hpp \
  libsrc/include/../gprim/gprim.hpp libsrc/stlgeom/stltopology.hpp \
  libsrc/stlgeom/stltool.hpp libsrc/stlgeom/stlline.hpp \
  libsrc/stlgeom/meshstlsurface.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
stlline.o: libsrc/stlgeom/stlline.cpp libsrc/include/mystdlib.h \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/meshing.hpp \
  libsrc/include/../meshing/meshing.hpp libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp \
  libsrc/include/../meshing/msghandler.hpp \
  libsrc/include/../meshing/meshtype.hpp \
  libsrc/include/../meshing/localh.hpp \
  libsrc/include/../meshing/meshclass.hpp \
  libsrc/include/../meshing/global.hpp \
  libsrc/include/../meshing/meshtool.hpp \
  libsrc/include/../meshing/ruler2.hpp \
  libsrc/include/../meshing/adfront2.hpp \
  libsrc/include/../meshing/meshing2.hpp \
  libsrc/include/../meshing/improve2.hpp \
  libsrc/include/../meshing/geomsearch.hpp \
  libsrc/include/../meshing/adfront3.hpp \
  libsrc/include/../meshing/ruler3.hpp \
  libsrc/include/../meshing/meshing3.hpp \
  libsrc/include/../meshing/improve3.hpp \
  libsrc/include/../meshing/findip.hpp \
  libsrc/include/../meshing/topology.hpp \
  libsrc/include/../meshing/curvedelems.hpp \
  libsrc/include/../meshing/bisect.hpp \
  libsrc/include/../meshing/clusters.hpp \
  libsrc/include/../meshing/meshfunc.hpp \
  libsrc/include/../meshing/hprefinement.hpp \
  libsrc/include/../meshing/boundarylayer.hpp \
  libsrc/include/../meshing/specials.hpp libsrc/stlgeom/stlgeom.hpp \
  libsrc/include/../gprim/gprim.hpp libsrc/stlgeom/stltopology.hpp \
  libsrc/stlgeom/stltool.hpp libsrc/stlgeom/stlline.hpp \
  libsrc/stlgeom/meshstlsurface.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
stltopology.o: libsrc/stlgeom/stltopology.cpp libsrc/include/mystdlib.h \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/meshing.hpp \
  libsrc/include/../meshing/meshing.hpp libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp \
  libsrc/include/../meshing/msghandler.hpp \
  libsrc/include/../meshing/meshtype.hpp \
  libsrc/include/../meshing/localh.hpp \
  libsrc/include/../meshing/meshclass.hpp \
  libsrc/include/../meshing/global.hpp \
  libsrc/include/../meshing/meshtool.hpp \
  libsrc/include/../meshing/ruler2.hpp \
  libsrc/include/../meshing/adfront2.hpp \
  libsrc/include/../meshing/meshing2.hpp \
  libsrc/include/../meshing/improve2.hpp \
  libsrc/include/../meshing/geomsearch.hpp \
  libsrc/include/../meshing/adfront3.hpp \
  libsrc/include/../meshing/ruler3.hpp \
  libsrc/include/../meshing/meshing3.hpp \
  libsrc/include/../meshing/improve3.hpp \
  libsrc/include/../meshing/findip.hpp \
  libsrc/include/../meshing/topology.hpp \
  libsrc/include/../meshing/curvedelems.hpp \
  libsrc/include/../meshing/bisect.hpp \
  libsrc/include/../meshing/clusters.hpp \
  libsrc/include/../meshing/meshfunc.hpp \
  libsrc/include/../meshing/hprefinement.hpp \
  libsrc/include/../meshing/boundarylayer.hpp \
  libsrc/include/../meshing/specials.hpp libsrc/stlgeom/stlgeom.hpp \
  libsrc/include/../gprim/gprim.hpp libsrc/stlgeom/stltopology.hpp \
  libsrc/stlgeom/stltool.hpp libsrc/stlgeom/stlline.hpp \
  libsrc/stlgeom/meshstlsurface.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
stltool.o: libsrc/stlgeom/stltool.cpp libsrc/include/mystdlib.h \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/meshing.hpp \
  libsrc/include/../meshing/meshing.hpp libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp \
  libsrc/include/../meshing/msghandler.hpp \
  libsrc/include/../meshing/meshtype.hpp \
  libsrc/include/../meshing/localh.hpp \
  libsrc/include/../meshing/meshclass.hpp \
  libsrc/include/../meshing/global.hpp \
  libsrc/include/../meshing/meshtool.hpp \
  libsrc/include/../meshing/ruler2.hpp \
  libsrc/include/../meshing/adfront2.hpp \
  libsrc/include/../meshing/meshing2.hpp \
  libsrc/include/../meshing/improve2.hpp \
  libsrc/include/../meshing/geomsearch.hpp \
  libsrc/include/../meshing/adfront3.hpp \
  libsrc/include/../meshing/ruler3.hpp \
  libsrc/include/../meshing/meshing3.hpp \
  libsrc/include/../meshing/improve3.hpp \
  libsrc/include/../meshing/findip.hpp \
  libsrc/include/../meshing/topology.hpp \
  libsrc/include/../meshing/curvedelems.hpp \
  libsrc/include/../meshing/bisect.hpp \
  libsrc/include/../meshing/clusters.hpp \
  libsrc/include/../meshing/meshfunc.hpp \
  libsrc/include/../meshing/hprefinement.hpp \
  libsrc/include/../meshing/boundarylayer.hpp \
  libsrc/include/../meshing/specials.hpp libsrc/stlgeom/stlgeom.hpp \
  libsrc/include/../gprim/gprim.hpp libsrc/stlgeom/stltopology.hpp \
  libsrc/stlgeom/stltool.hpp libsrc/stlgeom/stlline.hpp \
  libsrc/stlgeom/meshstlsurface.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
stlgeom.o: libsrc/stlgeom/stlgeom.cpp libsrc/include/mystdlib.h \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/meshing.hpp \
  libsrc/include/../meshing/meshing.hpp libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp \
  libsrc/include/../meshing/msghandler.hpp \
  libsrc/include/../meshing/meshtype.hpp \
  libsrc/include/../meshing/localh.hpp \
  libsrc/include/../meshing/meshclass.hpp \
  libsrc/include/../meshing/global.hpp \
  libsrc/include/../meshing/meshtool.hpp \
  libsrc/include/../meshing/ruler2.hpp \
  libsrc/include/../meshing/adfront2.hpp \
  libsrc/include/../meshing/meshing2.hpp \
  libsrc/include/../meshing/improve2.hpp \
  libsrc/include/../meshing/geomsearch.hpp \
  libsrc/include/../meshing/adfront3.hpp \
  libsrc/include/../meshing/ruler3.hpp \
  libsrc/include/../meshing/meshing3.hpp \
  libsrc/include/../meshing/improve3.hpp \
  libsrc/include/../meshing/findip.hpp \
  libsrc/include/../meshing/topology.hpp \
  libsrc/include/../meshing/curvedelems.hpp \
  libsrc/include/../meshing/bisect.hpp \
  libsrc/include/../meshing/clusters.hpp \
  libsrc/include/../meshing/meshfunc.hpp \
  libsrc/include/../meshing/hprefinement.hpp \
  libsrc/include/../meshing/boundarylayer.hpp \
  libsrc/include/../meshing/specials.hpp libsrc/stlgeom/stlgeom.hpp \
  libsrc/include/../gprim/gprim.hpp libsrc/stlgeom/stltopology.hpp \
  libsrc/stlgeom/stltool.hpp libsrc/stlgeom/stlline.hpp \
  libsrc/stlgeom/meshstlsurface.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
stlgeomchart.o: libsrc/stlgeom/stlgeomchart.cpp libsrc/include/mystdlib.h \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/meshing.hpp \
  libsrc/include/../meshing/meshing.hpp libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp \
  libsrc/include/../meshing/msghandler.hpp \
  libsrc/include/../meshing/meshtype.hpp \
  libsrc/include/../meshing/localh.hpp \
  libsrc/include/../meshing/meshclass.hpp \
  libsrc/include/../meshing/global.hpp \
  libsrc/include/../meshing/meshtool.hpp \
  libsrc/include/../meshing/ruler2.hpp \
  libsrc/include/../meshing/adfront2.hpp \
  libsrc/include/../meshing/meshing2.hpp \
  libsrc/include/../meshing/improve2.hpp \
  libsrc/include/../meshing/geomsearch.hpp \
  libsrc/include/../meshing/adfront3.hpp \
  libsrc/include/../meshing/ruler3.hpp \
  libsrc/include/../meshing/meshing3.hpp \
  libsrc/include/../meshing/improve3.hpp \
  libsrc/include/../meshing/findip.hpp \
  libsrc/include/../meshing/topology.hpp \
  libsrc/include/../meshing/curvedelems.hpp \
  libsrc/include/../meshing/bisect.hpp \
  libsrc/include/../meshing/clusters.hpp \
  libsrc/include/../meshing/meshfunc.hpp \
  libsrc/include/../meshing/hprefinement.hpp \
  libsrc/include/../meshing/boundarylayer.hpp \
  libsrc/include/../meshing/specials.hpp libsrc/stlgeom/stlgeom.hpp \
  libsrc/include/../gprim/gprim.hpp libsrc/stlgeom/stltopology.hpp \
  libsrc/stlgeom/stltool.hpp libsrc/stlgeom/stlline.hpp \
  libsrc/stlgeom/meshstlsurface.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
stlgeommesh.o: libsrc/stlgeom/stlgeommesh.cpp libsrc/include/mystdlib.h \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/meshing.hpp \
  libsrc/include/../meshing/meshing.hpp libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp \
  libsrc/include/../meshing/msghandler.hpp \
  libsrc/include/../meshing/meshtype.hpp \
  libsrc/include/../meshing/localh.hpp \
  libsrc/include/../meshing/meshclass.hpp \
  libsrc/include/../meshing/global.hpp \
  libsrc/include/../meshing/meshtool.hpp \
  libsrc/include/../meshing/ruler2.hpp \
  libsrc/include/../meshing/adfront2.hpp \
  libsrc/include/../meshing/meshing2.hpp \
  libsrc/include/../meshing/improve2.hpp \
  libsrc/include/../meshing/geomsearch.hpp \
  libsrc/include/../meshing/adfront3.hpp \
  libsrc/include/../meshing/ruler3.hpp \
  libsrc/include/../meshing/meshing3.hpp \
  libsrc/include/../meshing/improve3.hpp \
  libsrc/include/../meshing/findip.hpp \
  libsrc/include/../meshing/topology.hpp \
  libsrc/include/../meshing/curvedelems.hpp \
  libsrc/include/../meshing/bisect.hpp \
  libsrc/include/../meshing/clusters.hpp \
  libsrc/include/../meshing/meshfunc.hpp \
  libsrc/include/../meshing/hprefinement.hpp \
  libsrc/include/../meshing/boundarylayer.hpp \
  libsrc/include/../meshing/specials.hpp libsrc/stlgeom/stlgeom.hpp \
  libsrc/include/../gprim/gprim.hpp libsrc/stlgeom/stltopology.hpp \
  libsrc/stlgeom/stltool.hpp libsrc/stlgeom/stlline.hpp \
  libsrc/stlgeom/meshstlsurface.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
moveablemem.o: libsrc/general/moveablemem.cpp libsrc/include/myadt.hpp \
  libsrc/include/../general/myadt.hpp libsrc/include/mystdlib.h \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
ngexception.o: libsrc/general/ngexception.cpp libsrc/include/myadt.hpp \
  libsrc/include/../general/myadt.hpp libsrc/include/mystdlib.h \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
table.o: libsrc/general/table.cpp libsrc/include/mystdlib.h \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
optmem.o: libsrc/general/optmem.cpp libsrc/include/mystdlib.h \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
spbita2d.o: libsrc/general/spbita2d.cpp libsrc/include/mystdlib.h \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
hashtabl.o: libsrc/general/hashtabl.cpp libsrc/include/mystdlib.h \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
sort.o: libsrc/general/sort.cpp libsrc/include/mystdlib.h \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
flags.o: libsrc/general/flags.cpp libsrc/include/mystdlib.h \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
seti.o: libsrc/general/seti.cpp libsrc/include/mystdlib.h \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
bitarray.o: libsrc/general/bitarray.cpp libsrc/include/mystdlib.h \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
array.o: libsrc/general/array.cpp libsrc/include/mystdlib.h \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
symbolta.o: libsrc/general/symbolta.cpp libsrc/include/mystdlib.h \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
mystring.o: libsrc/general/mystring.cpp libsrc/include/mystdlib.h \
  libsrc/include/myadt.hpp libsrc/include/../general/myadt.hpp \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/contrib/Netgen//"
nglib_addon.o: nglib_addon.cpp libsrc/include/meshing.hpp \
  libsrc/include/../meshing/meshing.hpp libsrc/include/myadt.hpp \
  libsrc/include/../general/myadt.hpp libsrc/include/mystdlib.h \
  libsrc/include/mydefs.hpp libsrc/include/../general/ngexception.hpp \
  libsrc/include/../general/parthreads.hpp \
  libsrc/include/../general/moveablemem.hpp \
  libsrc/include/../general/dynamicmem.hpp \
  libsrc/include/../general/template.hpp \
  libsrc/include/../general/array.hpp libsrc/include/../general/table.hpp \
  libsrc/include/../general/hashtabl.hpp \
  libsrc/include/../general/symbolta.hpp \
  libsrc/include/../general/bitarray.hpp \
  libsrc/include/../general/flags.hpp \
  libsrc/include/../general/spbita2d.hpp \
  libsrc/include/../general/seti.hpp libsrc/include/../general/optmem.hpp \
  libsrc/include/../general/autoptr.hpp \
  libsrc/include/../general/sort.hpp libsrc/include/../general/stack.hpp \
  libsrc/include/../general/mystring.hpp libsrc/include/gprim.hpp \
  libsrc/include/../gprim/gprim.hpp \
  libsrc/include/../gprim/geomobjects.hpp \
  libsrc/include/../gprim/geomops.hpp \
  libsrc/include/../gprim/geomfuncs.hpp \
  libsrc/include/../gprim/geom2d.hpp libsrc/include/../gprim/geom3d.hpp \
  libsrc/include/../gprim/geomtest3d.hpp \
  libsrc/include/../gprim/transform3d.hpp \
  libsrc/include/../gprim/adtree.hpp libsrc/include/linalg.hpp \
  libsrc/include/../linalg/linalg.hpp libsrc/include/../linalg/vector.hpp \
  libsrc/include/../linalg/densemat.hpp \
  libsrc/include/../linalg/polynomial.hpp libsrc/include/opti.hpp \
  libsrc/include/../opti/opti.hpp \
  libsrc/include/../meshing/msghandler.hpp \
  libsrc/include/../meshing/meshtype.hpp \
  libsrc/include/../meshing/localh.hpp \
  libsrc/include/../meshing/meshclass.hpp \
  libsrc/include/../meshing/global.hpp \
  libsrc/include/../meshing/meshtool.hpp \
  libsrc/include/../meshing/ruler2.hpp \
  libsrc/include/../meshing/adfront2.hpp \
  libsrc/include/../meshing/meshing2.hpp \
  libsrc/include/../meshing/improve2.hpp \
  libsrc/include/../meshing/geomsearch.hpp \
  libsrc/include/../meshing/adfront3.hpp \
  libsrc/include/../meshing/ruler3.hpp \
  libsrc/include/../meshing/meshing3.hpp \
  libsrc/include/../meshing/improve3.hpp \
  libsrc/include/../meshing/findip.hpp \
  libsrc/include/../meshing/topology.hpp \
  libsrc/include/../meshing/curvedelems.hpp \
  libsrc/include/../meshing/bisect.hpp \
  libsrc/include/../meshing/clusters.hpp \
  libsrc/include/../meshing/meshfunc.hpp \
  libsrc/include/../meshing/hprefinement.hpp \
  libsrc/include/../meshing/boundarylayer.hpp \
  libsrc/include/../meshing/specials.hpp libsrc/interface/nglib.h \
  ../../Common/Message.h
