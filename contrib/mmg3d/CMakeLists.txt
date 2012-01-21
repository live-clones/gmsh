# Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

set(SRC
./build/sources/mmg3d.c
./build/sources/inout.c
./build/sources/mmg3dlib.c
./build/sources/scalem.c
./build/sources/outqua.c
./build/sources/baryct.c
./build/sources/zaldy.c
./build/sources/typelt.c
./build/sources/swaptet.c
./build/sources/swapar.c
./build/sources/swap710.c
./build/sources/swap68.c
./build/sources/swap56.c
./build/sources/swap44.c
./build/sources/swap23.c
./build/sources/spledg.c
./build/sources/solmap.c
./build/sources/simu710.c
./build/sources/simu68.c
./build/sources/simu56.c
./build/sources/simu44.c
./build/sources/simu23.c
./build/sources/ratio.c
./build/sources/queue.c
./build/sources/quality.c
./build/sources/pattern.c
./build/sources/opttyp.c
./build/sources/opttet.c
./build/sources/optra4.c
./build/sources/optlentet.c
./build/sources/optlen.c
./build/sources/optlap.c
./build/sources/optcte.c
./build/sources/optcoq.c
./build/sources/optbdry.c
./build/sources/movevertex.c
./build/sources/mmg3d9.c
./build/sources/delaunay.c
./build/sources/hash.c
./build/sources/length.c
./build/sources/mmg3d4.c
./build/sources/mmg3d1.c
./build/sources/memory.c
./build/sources/matrix.c
./build/sources/locate.c
./build/sources/librnbg.c
./build/sources/heap.c
./build/sources/eigenv.c
./build/sources/cutelt.c
./build/sources/coquil.c
./build/sources/colpoi.c
./build/sources/chrono.c
./build/sources/chkmsh.c
./build/sources/cenrad.c
./build/sources/cendel.c
./build/sources/bucket.c
./build/sources/boulep.c
./build/sources/analarcutting.c
./build/sources/analar.c
)

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(contrib/mmg3d "${SRC};${HDR}")
