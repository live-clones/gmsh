
doit:
	gmsh levelsetTest.geo -3
	getdp levelsetTest -solve Proj -pos v -bin
	gmsh levelsetTest.geo levelsetTest1.pos levelsetTest.opt

#	gmsh levelsetTest.geo levelsetTest2.pos levelsetTest.opt
#	gmsh levelsetTest.geo levelsetTest3.pos levelsetTest.opt

clean:
	rm -f *.msh *.pre *.res *.pos
