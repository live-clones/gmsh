# Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

set(SRC
  PView.cpp PViewIO.cpp
    PViewData.cpp PViewDataIO.cpp
      PViewDataList.cpp PViewDataListIO.cpp
      PViewDataGModel.cpp PViewDataGModelIO.cpp
    PViewOptions.cpp
  adaptiveData.cpp shapeFunctions.cpp
  OctreePost.cpp
  ColorTable.cpp
)

append_gmsh_src(Post "${SRC}")
