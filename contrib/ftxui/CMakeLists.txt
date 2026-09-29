# Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file in the Gmsh root directory for license information.
# Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

# The screen, dom and component libraries of FTXUI as one: see README.gmsh.txt
file(GLOB_RECURSE FTXUI_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/ftxui/*.cpp)

add_library(ftxui STATIC ${FTXUI_SRC})
target_include_directories(ftxui
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_compile_features(ftxui PUBLIC cxx_std_17)
set_target_properties(ftxui PROPERTIES POSITION_INDEPENDENT_CODE ON)
find_package(Threads REQUIRED)
target_link_libraries(ftxui PUBLIC Threads::Threads)
