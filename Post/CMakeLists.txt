# Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

set(SRC
  PView.cpp PViewIO.cpp PViewVertexArrays.cpp
    PViewData.cpp PViewDataIO.cpp PViewX3D.cpp
      PViewDataList.cpp PViewDataListIO.cpp
      PViewDataGModel.cpp PViewDataGModelIO.cpp
    PViewOptions.cpp
    PViewFactory.cpp
    PViewAsSimpleFunction.cpp
  adaptiveData.cpp shapeFunctions.cpp
  OctreePost.cpp
  ColorTable.cpp
)

file(GLOB HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h) 
append_gmsh_src(Post "${SRC};${HDR}")
