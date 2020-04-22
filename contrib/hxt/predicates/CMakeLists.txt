cmake_minimum_required(VERSION 3.9)
project(hxt_predicates C)

if(TARGET hxt_predicates)
  # header guard for CMake. You need to include this directory first
  return()
endif()

set(HXT_PREDICATES_SRC
	"${CMAKE_CURRENT_SOURCE_DIR}/src/predicates.c"
	"${CMAKE_CURRENT_SOURCE_DIR}/include/predicates.h"
	)

# make an object library (no archive)
add_library(hxt_predicates OBJECT ${HXT_PREDICATES_SRC})

target_include_directories(hxt_predicates INTERFACE include)

# do not use extended double precision or arithmetic contraction in predicates.c
if(MSVC OR (CMAKE_C_COMPILER_ID STREQUAL "Intel" AND WIN32))
	target_compile_options(hxt_predicates PRIVATE "/fp:strict")
elseif(CMAKE_C_COMPILER_ID STREQUAL "Intel")
	target_compile_options(${target} ${keyword} "-fp-model" "strict")
elseif(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
	target_compile_options(hxt_predicates PRIVATE "-fno-unsafe-math-optimizations" "-ffp-contract=off")
else()
	message(WARNING
		"Unsupported compiler !
		 Make sure compiled functions from predicates.c
		 do NOT use extended double precision and follow IEEE754 standard.
		 It is crucial for the robustness of geometric predicates.")
endif()
