# Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

set(gen libsrc/general)
set(lin libsrc/linalg)
set(gpr libsrc/gprim)
set(mes libsrc/meshing)
set(opt libsrc/opti)

set(SRC
  nglib_gmsh.cpp
  ${gen}/array.cpp ${gen}/bitarray.cpp ${gen}/hashtabl.cpp 
    ${gen}/symbolta.cpp ${gen}/table.cpp ${gen}/flags.cpp
    ${gen}/spbita2d.cpp ${gen}/seti.cpp ${gen}/optmem.cpp ${gen}/sort.cpp 
    ${gen}/mystring.cpp ${gen}/parthreads.cpp
    ${gen}/dynamicmem.cpp ${gen}/ngexception.cpp ${gen}/profiler.cpp
  ${lin}/densemat.cpp ${lin}/polynomial.cpp ${lin}/bfgs.cpp
    ${lin}/linopt.cpp ${lin}/linsearch.cpp
  ${gpr}/geom2d.cpp ${gpr}/geom3d.cpp ${gpr}/geomtest3d.cpp ${gpr}/adtree.cpp 
    ${gpr}/transform3d.cpp ${gpr}/geomfuncs.cpp
  ${mes}/meshclass.cpp ${mes}/adfront2.cpp ${mes}/adfront3.cpp 
    ${mes}/geomsearch.cpp ${mes}/global.cpp ${mes}/meshtool.cpp
    ${mes}/netrule2.cpp ${mes}/netrule3.cpp ${mes}/parser2.cpp 
    ${mes}/parser3.cpp ${mes}/ruler2.cpp ${mes}/ruler3.cpp
    ${mes}/meshtype.cpp ${mes}/improve2.cpp ${mes}/smoothing2.5.cpp
    ${mes}/smoothing2.cpp ${mes}/improve3.cpp ${mes}/smoothing3.cpp
    ${mes}/improve2gen.cpp ${mes}/meshing2.cpp ${mes}/meshing3.cpp
    ${mes}/localh.cpp ${mes}/delaunay.cpp ${mes}/topology.cpp 
    ${mes}/clusters.cpp ${mes}/tetrarls.cpp ${mes}/triarls.cpp 
    ${mes}/quadrls.cpp ${mes}/meshfunc.cpp ${mes}/meshfunc2d.cpp
    ${mes}/refine.cpp ${mes}/bisect.cpp ${mes}/boundarylayer.cpp 
    ${mes}/specials.cpp ${mes}/msghandler.cpp ${mes}/pyramidrls.cpp
    ${mes}/pyramid2rls.cpp ${mes}/prism2rls.cpp ${mes}/curvedelems.cpp
    ${mes}/validate.cpp ${mes}/basegeom.cpp
)

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(contrib/Netgen "${SRC};${HDR}")
