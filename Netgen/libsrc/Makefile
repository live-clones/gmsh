#
#
appl = NETGEN
.default all:
#
#	
all:
	@ (cd linalg; $(MAKE) -f Makefile) 
	@ (cd general; $(MAKE) -f Makefile)  
	@ (cd gprim; $(MAKE) -f Makefile)
	@ (cd csg; $(MAKE) -f Makefile)  
	@ (cd geom2d; $(MAKE) -f Makefile)
	@ (cd stlgeom; $(MAKE) -f Makefile)
	@ (cd occ; $(MAKE) -f Makefile)
	@ (cd meshing; $(MAKE) -f Makefile)
	@ (cd opti; $(MAKE) -f Makefile)
	@ (cd visualization; $(MAKE) -f Makefile)
	@ (cd interface; $(MAKE) -f Makefile)
#
#	@ (cd step; $(MAKE) -f Makefile)
#	@ (cd stepgeom; $(MAKE) -f Makefile)
#	@ (cd graphics; $(MAKE) -f Makefile)

tar:
	tar cvf ../../libsrc.tar Makefile
	tar rf ../../libsrc.tar linalg/Makefile linalg/*.hh linalg/*.cc
	tar rf ../../libsrc.tar general/Makefile general/*.hh general/*.cc
	tar rf ../../libsrc.tar gprim/Makefile gprim/*.hh gprim/*.cc
	tar rf ../../libsrc.tar csg/Makefile csg/*.hh csg/*.cc
	tar rf ../../libsrc.tar stlgeom/Makefile stlgeom/*.hh stlgeom/*.cc
	tar rf ../../libsrc.tar occ/Makefile occ/*.h* occ/*.c*
	tar rf ../../libsrc.tar meshing/Makefile meshing/*.hh meshing/*.cc meshing/*.h
	tar rf ../../libsrc.tar opti/Makefile opti/*.hh opti/*.cc
	tar rf ../../libsrc.tar step/Makefile step/*.h step/*.cc
	tar rf ../../libsrc.tar stepgeom/Makefile stepgeom/*.hh stepgeom/*.cc
	tar tf ../../libsrc.tar include/*.h include/*.hh
	gzip -9 ../../libsrc.tar

