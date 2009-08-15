This is a tool to convert a BRL CAD model to an OpenCASCADE brep
file. To compile this program you need BRL CAD and it's sources to be
installed. Set the paths BRL_SRC and BRL_LIB in the Makefile and type
make. On 32 bit systems the -D_OCC64 option must be removed.

To use the program type:

	g-brep test.g complex.r tst_corner1.s tst_com.s tst_acom.s

The first parameter is the BRL database, the subsequent parameters are
the models to be included in the brep file. Note that these models will
become single solids. All these solids will be connected to each other.

It is possible to skip the connecting algorithm when the "-c" option
is used. This is used to test the connecting algorithm in gmsh.

The result of the g-brep program is test.brep which can be read by gmsh,
if gmsh is compiled with OCC support.

This program has been tested with brlcad-7.14.6 and OpenCASCADE-6.3.0.

Mark van Doesburg.
