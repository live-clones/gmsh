# $Id: Makefile,v 1.39 2008-06-05 13:58:45 geuzaine Exp $
#
# Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
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

LIB = ../../lib/libGmshNetgen${LIBEXT}

INC = ${DASH}I../../Common ${DASH}Ilibsrc/include ${DASH}Ilibsrc/interface

CFLAGS = ${OPTIM} ${FLAGS} ${INC} ${SYSINCLUDE}\
         ${DASH}DNO_PARALLEL_THREADS ${DASH}UWIN32

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

OBJ = ${SRC:.cpp=${OBJEXT}}

.SUFFIXES: ${OBJEXT} .cpp

${LIB}: ${OBJ} 
	${AR} ${ARFLAGS}${LIB} ${OBJ} 
	${RANLIB} ${LIB}

cpobj: ${OBJ} 
	cp -f ${OBJ} ../../lib/

.cpp${OBJEXT}:
	${CXX} ${CFLAGS} ${DASH}c $< ${DASH}o ${<:.cpp=${OBJEXT}}
	if [ -r ${notdir ${<:.cpp=${OBJEXT}}} ]; then\
           mv -f ${notdir ${<:.cpp=${OBJEXT}}} ${<:.cpp=${OBJEXT}};\
        fi

# don't apply ugly hack above for files in this directory
nglib_addon${OBJEXT}:
	${CXX} ${CFLAGS} ${DASH}c nglib_addon.cpp

clean:
	rm -f *.o *.obj libsrc/*/*.o libsrc/*/*.obj

depend:
	(sed '/^# DO NOT DELETE THIS LINE/q' Makefile && \
	${CXX} -MM ${CFLAGS} ${SRC} \
	) >Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	rm -f Makefile.new

# DO NOT DELETE THIS LINE
