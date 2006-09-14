# $Id: Makefile,v 1.11 2006-09-14 15:23:30 remacle Exp $
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
tetrarls.o: libsrc/meshing/tetrarls.cpp
prism2rls.o: libsrc/meshing/prism2rls.cpp
pyramidrls.o: libsrc/meshing/pyramidrls.cpp
pyramid2rls.o: libsrc/meshing/pyramid2rls.cpp
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
triarls.o: libsrc/meshing/triarls.cpp
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
quadrls.o: libsrc/meshing/quadrls.cpp
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
vector.o: libsrc/linalg/vector.cpp
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
