# Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file in the Gmsh root directory for license information.
# Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

# mt-metis calls the METIS of contrib/metis (or the system METIS) for the
# initial partitioning of the coarsest graph
file(GLOB SRC src/*.c domlib/*.c)

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)

add_library(mtmetis OBJECT ${SRC} ${HDR})
set_target_properties(mtmetis PROPERTIES POSITION_INDEPENDENT_CODE ON
  C_STANDARD 99 C_EXTENSIONS ON C_VISIBILITY_PRESET hidden)
# the METIS headers used by Gmsh first (another metis.h, with another idx_t,
# may be in a directory of EXTERNAL_INCLUDES)
target_include_directories(mtmetis BEFORE PRIVATE include domlib src
  ${METIS_INCLUDE_DIRS} ${PROJECT_BINARY_DIR}/src/common)
target_compile_definitions(mtmetis PRIVATE NDEBUG=1 NDEBUG2=1)
# silence the warnings of the upstream code
if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
  target_compile_options(mtmetis PRIVATE -w)
endif()

set(GMSH_SRC ${GMSH_SRC};$<TARGET_OBJECTS:mtmetis> PARENT_SCOPE)
