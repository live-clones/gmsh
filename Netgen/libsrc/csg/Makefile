#
# Makefile for geometric library
#
src =  csgparser.cpp algprim.cpp curve2d.cpp brick.cpp  \
	solid.cpp spline3d.cpp surface.cpp bspline2d.cpp \
	explicitcurve2d.cpp gencyl.cpp csgeom.cpp polyhedra.cpp extrusion.cpp revolution.cpp  \
	manifold.cpp curve2d.cpp triapprox.cpp identify.cpp \
	singularref.cpp  \
	edgeflw.cpp specpoin.cpp meshsurf.cpp genmesh.cpp 
#
#  lex.yy.cpp geometry.cpp
# 
lib = csg
libpath = libsrc/csg
#
#
include ../makefile.inc
#
# geometry.cpp : geometry.yy 
#	bison -d -o geometry.c geometry.yy
#	mv -f geometry.c geometry.cpp
#
# lex.yy.cpp : geometry.yy geometry.ll
#	flex  -+ -d -I geometry.ll
#	mv lex.yy.cc lex.yy.cpp

