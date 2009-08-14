project(qtgmsh)

cmake_minimum_required(VERSION 2.4.0)

find_package(Qt4 REQUIRED) # find and setup Qt4 for this project

set(QT_USE_QTOPENGL TRUE)
include(${QT_USE_FILE})

set(qtgmsh_SRCS
  glwidget.cpp
  main.cpp
  window.cpp
)
set(qtgmsh_MOC_HDRS
  glwidget.h
  window.h
)
qt4_wrap_cpp(qtgmsh_MOC_SRCS ${qtgmsh_MOC_HDRS})
add_executable(qtgmsh ${qtgmsh_SRCS} ${qtgmsh_MOC_SRCS})
include_directories(../include)
find_library(GMSH_LIBRARIES Gmsh ../lib)
target_link_libraries(qtgmsh ${QT_LIBRARIES} ${GMSH_LIBRARIES} -llapack -lblas)

#install(TARGETS qtproject DESTINATION bin)
# tell cmake to process CMakeLists.txt in that subdirectory
# add_subdirectory(src)
