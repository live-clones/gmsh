# Install script for directory: /home/hillewaert/srcs/gmsh_git

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "RelWithDebInfo")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/gmsh" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/gmsh")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/gmsh"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE OPTIONAL FILES "/home/hillewaert/srcs/gmsh_git/test/gmsh")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/gmsh" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/gmsh")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/gmsh"
         OLD_RPATH "/usr/lib64/mpi/gcc/openmpi/lib64:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/gmsh")
    endif()
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE FILES "/home/hillewaert/srcs/gmsh_git/contrib/onelab/python/onelab.py")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/gmsh" TYPE FILE RENAME "README.txt" FILES "/home/hillewaert/srcs/gmsh_git/doc/WELCOME.txt")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/gmsh" TYPE FILE FILES "/home/hillewaert/srcs/gmsh_git/LICENSE.txt")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/gmsh" TYPE FILE FILES "/home/hillewaert/srcs/gmsh_git/CREDITS.txt")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/gmsh" TYPE FILE FILES "/home/hillewaert/srcs/gmsh_git/CHANGELOG.txt")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/gmsh/tutorial" TYPE FILE FILES
    "/home/hillewaert/srcs/gmsh_git/tutorial/bgmesh.pos"
    "/home/hillewaert/srcs/gmsh_git/tutorial/image.png"
    "/home/hillewaert/srcs/gmsh_git/tutorial/t1.geo"
    "/home/hillewaert/srcs/gmsh_git/tutorial/t10.geo"
    "/home/hillewaert/srcs/gmsh_git/tutorial/t11.geo"
    "/home/hillewaert/srcs/gmsh_git/tutorial/t12.geo"
    "/home/hillewaert/srcs/gmsh_git/tutorial/t13.geo"
    "/home/hillewaert/srcs/gmsh_git/tutorial/t13_data.msh"
    "/home/hillewaert/srcs/gmsh_git/tutorial/t14.geo"
    "/home/hillewaert/srcs/gmsh_git/tutorial/t15.geo"
    "/home/hillewaert/srcs/gmsh_git/tutorial/t16.geo"
    "/home/hillewaert/srcs/gmsh_git/tutorial/t17.geo"
    "/home/hillewaert/srcs/gmsh_git/tutorial/t17.pos"
    "/home/hillewaert/srcs/gmsh_git/tutorial/t2.geo"
    "/home/hillewaert/srcs/gmsh_git/tutorial/t3.geo"
    "/home/hillewaert/srcs/gmsh_git/tutorial/t4.geo"
    "/home/hillewaert/srcs/gmsh_git/tutorial/t5.geo"
    "/home/hillewaert/srcs/gmsh_git/tutorial/t6.geo"
    "/home/hillewaert/srcs/gmsh_git/tutorial/t7.geo"
    "/home/hillewaert/srcs/gmsh_git/tutorial/t8.geo"
    "/home/hillewaert/srcs/gmsh_git/tutorial/t9.geo"
    "/home/hillewaert/srcs/gmsh_git/tutorial/view1.pos"
    "/home/hillewaert/srcs/gmsh_git/tutorial/view2.pos"
    "/home/hillewaert/srcs/gmsh_git/tutorial/view3.pos"
    "/home/hillewaert/srcs/gmsh_git/tutorial/view4.pos"
    "/home/hillewaert/srcs/gmsh_git/tutorial/view5.msh"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/gmsh/demos/boolean" TYPE FILE FILES
    "/home/hillewaert/srcs/gmsh_git/demos/boolean/baffles.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/boolean/boolean.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/boolean/component8.step"
    "/home/hillewaert/srcs/gmsh_git/demos/boolean/compsolid.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/boolean/compsolid2.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/boolean/extrude.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/boolean/extrude2.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/boolean/fillet.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/boolean/fillet2.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/boolean/fillet3.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/boolean/fragment_numbering.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/boolean/import.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/boolean/import2.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/boolean/intersect_line_volume.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/boolean/neuron.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/boolean/periodic.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/boolean/pipe.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/boolean/primitives.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/boolean/revolve.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/boolean/revolve2.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/boolean/simple.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/boolean/simple2.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/boolean/simple3.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/boolean/simple4.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/boolean/simple5.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/boolean/simple6.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/boolean/simple7.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/boolean/spline.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/boolean/thicksolid.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/boolean/thrusections.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/boolean/transfinite.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/boolean/transform.geo"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/gmsh/demos/post_processing" TYPE FILE FILES
    "/home/hillewaert/srcs/gmsh_git/demos/post_processing/anim.script"
    "/home/hillewaert/srcs/gmsh_git/demos/post_processing/encode.script"
    "/home/hillewaert/srcs/gmsh_git/demos/post_processing/isosurf.script"
    "/home/hillewaert/srcs/gmsh_git/demos/post_processing/lowmem-anim.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/post_processing/multislice.script"
    "/home/hillewaert/srcs/gmsh_git/demos/post_processing/plot2d.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/post_processing/primitives.pos"
    "/home/hillewaert/srcs/gmsh_git/demos/post_processing/rotate.script"
    "/home/hillewaert/srcs/gmsh_git/demos/post_processing/title.script"
    "/home/hillewaert/srcs/gmsh_git/demos/post_processing/view_groups.geo"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/gmsh/demos/simple_geo" TYPE FILE FILES
    "/home/hillewaert/srcs/gmsh_git/demos/simple_geo/antenna.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/simple_geo/antenna.i1"
    "/home/hillewaert/srcs/gmsh_git/demos/simple_geo/component8.step"
    "/home/hillewaert/srcs/gmsh_git/demos/simple_geo/component8_in_a_box.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/simple_geo/cone.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/simple_geo/cube.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/simple_geo/fields.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/simple_geo/filter.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/simple_geo/hex.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/simple_geo/homology.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/simple_geo/indheat.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/simple_geo/machine.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/simple_geo/machine.i1"
    "/home/hillewaert/srcs/gmsh_git/demos/simple_geo/machine.i2"
    "/home/hillewaert/srcs/gmsh_git/demos/simple_geo/piece-extr-rec.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/simple_geo/piece-extr.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/simple_geo/piece.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/simple_geo/pripyrtet.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/simple_geo/sphere-discrete.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/simple_geo/sphere-surf.stl"
    "/home/hillewaert/srcs/gmsh_git/demos/simple_geo/sphere.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/simple_geo/splines.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/simple_geo/square_regular.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/simple_geo/tower.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/simple_geo/tower.i1"
    "/home/hillewaert/srcs/gmsh_git/demos/simple_geo/tower.i2"
    "/home/hillewaert/srcs/gmsh_git/demos/simple_geo/tower.i3"
    "/home/hillewaert/srcs/gmsh_git/demos/simple_geo/tower.i4"
    "/home/hillewaert/srcs/gmsh_git/demos/simple_geo/tower.i5"
    "/home/hillewaert/srcs/gmsh_git/demos/simple_geo/transfinite.geo"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/gmsh/demos/struct" TYPE FILE FILES
    "/home/hillewaert/srcs/gmsh_git/demos/struct/Exists_GetForced.geo"
    "/home/hillewaert/srcs/gmsh_git/demos/struct/struct.geo"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/man/man1" TYPE FILE FILES "/home/hillewaert/srcs/gmsh_git/doc/gmsh.1")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/gmsh" TYPE FILE OPTIONAL FILES "/home/hillewaert/srcs/gmsh_git/doc/texinfo/gmsh.html")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/gmsh" TYPE FILE OPTIONAL FILES "/home/hillewaert/srcs/gmsh_git/doc/texinfo/gmsh.pdf")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/hillewaert/srcs/gmsh_git/test/Common/cmake_install.cmake")
  include("/home/hillewaert/srcs/gmsh_git/test/Numeric/cmake_install.cmake")
  include("/home/hillewaert/srcs/gmsh_git/test/Geo/cmake_install.cmake")
  include("/home/hillewaert/srcs/gmsh_git/test/Mesh/cmake_install.cmake")
  include("/home/hillewaert/srcs/gmsh_git/test/Solver/cmake_install.cmake")
  include("/home/hillewaert/srcs/gmsh_git/test/Post/cmake_install.cmake")
  include("/home/hillewaert/srcs/gmsh_git/test/Plugin/cmake_install.cmake")
  include("/home/hillewaert/srcs/gmsh_git/test/Parser/cmake_install.cmake")
  include("/home/hillewaert/srcs/gmsh_git/test/Fltk/cmake_install.cmake")
  include("/home/hillewaert/srcs/gmsh_git/test/contrib/onelab/cmake_install.cmake")
  include("/home/hillewaert/srcs/gmsh_git/test/contrib/mpeg_encode/cmake_install.cmake")
  include("/home/hillewaert/srcs/gmsh_git/test/Graphics/cmake_install.cmake")
  include("/home/hillewaert/srcs/gmsh_git/test/contrib/ANN/cmake_install.cmake")
  include("/home/hillewaert/srcs/gmsh_git/test/contrib/lbfgs/cmake_install.cmake")
  include("/home/hillewaert/srcs/gmsh_git/test/contrib/DiscreteIntegration/cmake_install.cmake")
  include("/home/hillewaert/srcs/gmsh_git/test/contrib/HighOrderMeshOptimizer/cmake_install.cmake")
  include("/home/hillewaert/srcs/gmsh_git/test/contrib/MeshOptimizer/cmake_install.cmake")
  include("/home/hillewaert/srcs/gmsh_git/test/contrib/MeshQualityOptimizer/cmake_install.cmake")
  include("/home/hillewaert/srcs/gmsh_git/test/contrib/kbipack/cmake_install.cmake")
  include("/home/hillewaert/srcs/gmsh_git/test/contrib/MathEx/cmake_install.cmake")
  include("/home/hillewaert/srcs/gmsh_git/test/contrib/Metis/cmake_install.cmake")
  include("/home/hillewaert/srcs/gmsh_git/test/contrib/Chaco/cmake_install.cmake")
  include("/home/hillewaert/srcs/gmsh_git/test/contrib/voro++/cmake_install.cmake")
  include("/home/hillewaert/srcs/gmsh_git/test/contrib/blossom/cmake_install.cmake")
  include("/home/hillewaert/srcs/gmsh_git/test/contrib/Netgen/cmake_install.cmake")
  include("/home/hillewaert/srcs/gmsh_git/test/contrib/bamg/cmake_install.cmake")
  include("/home/hillewaert/srcs/gmsh_git/test/contrib/mmg3d/cmake_install.cmake")
  include("/home/hillewaert/srcs/gmsh_git/test/contrib/Tetgen1.5/cmake_install.cmake")
  include("/home/hillewaert/srcs/gmsh_git/test/contrib/taucs/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/hillewaert/srcs/gmsh_git/test/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
