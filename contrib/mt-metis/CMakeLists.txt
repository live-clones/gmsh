# Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file in the Gmsh root directory for license information.
# Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

# mt-metis bundles its own copy of METIS 5.1 (with its symbols renamed), whose
# headers have the same names as those of contrib/metis: compile it as an
# object library with its own include directories, first in the search path
file(GLOB SRC src/*.c domlib/*.c metis/libmetis/*.c)
list(APPEND SRC
  metis/GKlib/error.c
  metis/GKlib/fs.c
  metis/GKlib/gk_util.c
  metis/GKlib/io.c
  metis/GKlib/mcore.c
  metis/GKlib/memory.c
  metis/GKlib/random.c
  metis/GKlib/string.c
  metis/GKlib/timers.c
)

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)

add_library(mtmetis OBJECT ${SRC} ${HDR})
set_target_properties(mtmetis PROPERTIES POSITION_INDEPENDENT_CODE ON
  C_STANDARD 99 C_EXTENSIONS ON C_VISIBILITY_PRESET hidden)
target_include_directories(mtmetis BEFORE PRIVATE include domlib
  metis/include metis/libmetis metis/GKlib src)
# 64-bit edges (see include/mtmetis.h) and METIS indices, as upstream's BIGEDGES
target_compile_definitions(mtmetis PRIVATE NDEBUG=1 NDEBUG2=1 IDXTYPEWIDTH=64)
# silence the warnings of the upstream code
if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
  target_compile_options(mtmetis PRIVATE -w)
endif()

set(GMSH_SRC ${GMSH_SRC};$<TARGET_OBJECTS:mtmetis> PARENT_SCOPE)
