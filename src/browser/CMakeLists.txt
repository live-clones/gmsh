# Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file in the Gmsh root directory for license information.
# Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

set(SRC
  BackendBrowser.cpp
  httpServer.cpp
)

file(GLOB HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(src/browser "${SRC};${HDR}")

# The page is a file of its own, handed to the compiler as an array of bytes in
# browserPage.h: as a string literal it would be more than MSVC takes (16380
# bytes a piece, 65535 in all). CMake runs again when the page changes.
set(PAGE ${CMAKE_CURRENT_SOURCE_DIR}/page.html)
set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS ${PAGE})
file(READ ${PAGE} BYTES HEX)
# 32 bytes to a line
string(REGEX REPLACE
  "(................................................................)" "\\1\n"
  BYTES "${BYTES}")
string(REGEX REPLACE "([0-9a-f][0-9a-f])" "0x\\1," BYTES "${BYTES}")
file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/browserPage.h.new
  "// made from src/browser/page.html by src/browser/CMakeLists.txt\n"
  "static const unsigned char browserPage[] = {\n${BYTES}};\n")
# copied only when it changed: what includes it is not built again for nothing
configure_file(${CMAKE_CURRENT_BINARY_DIR}/browserPage.h.new
               ${CMAKE_CURRENT_BINARY_DIR}/browserPage.h COPYONLY)
