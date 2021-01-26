# Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

set(SRC
  PView.cpp PViewIO.cpp PViewIO_CGNS.cpp PViewVertexArrays.cpp
    PViewData.cpp PViewDataIO.cpp PViewX3D.cpp
      PViewDataList.cpp PViewDataListIO.cpp
      PViewDataGModel.cpp PViewDataGModelIO.cpp PViewDataGModelIO_CGNS.cpp
    PViewOptions.cpp
    PViewFactory.cpp
    PViewAsSimpleFunction.cpp
  adaptiveData.cpp shapeFunctions.cpp
  OctreePost.cpp
  ColorTable.cpp
)

file(GLOB HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h) 
append_gmsh_src(Post "${SRC};${HDR}")
