cmake_minimum_required(VERSION 3.8.2)

project(qtgmsh)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Make this a GUI application on Windows
if(WIN32)
  set(CMAKE_WIN32_EXECUTABLE ON)
endif()

find_library(GMSH_LIB gmsh)
if(NOT GMSH_LIB)
  message(FATAL_ERROR "Could not find the Gmsh library")
endif()

find_path(GMSH_INC gmsh/GmshGlobal.h)
if(NOT GMSH_INC)
  message(FATAL_ERROR "Could not find the private Gmsh API")
endif()

include_directories(${GMSH_INC})

# Find OpenGL
find_package(OpenGL REQUIRED)

# Find Qt
# On macOS with homebrew, need to set Qt5_DIR=/usr/local/opt/qt5/lib/cmake/Qt5
find_package(Qt5 REQUIRED COMPONENTS Widgets OpenGL)

# Add qtgmsh executable
add_executable(qtgmsh Main.cpp QGui.cpp GLWidget.cpp graphicWindow.cpp)
target_link_libraries(qtgmsh Qt5::Widgets Qt5::OpenGL ${GMSH_LIB} ${OPENGL_LIBRARIES})
