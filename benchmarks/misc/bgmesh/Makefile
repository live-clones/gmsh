
doit:
	gmsh proj.geo -3
	getdp proj -solve Proj -pos v -bin
	gmsh proj.geo -bgm proj.pos

clean:
	rm -f *.msh *.pre *.res *.pos
