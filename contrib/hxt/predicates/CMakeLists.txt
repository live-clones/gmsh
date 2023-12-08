cmake_minimum_required(VERSION 3.9)
project(hxt_predicates C)

# include guard for CMake:
# if you plan to include multiple directory that depend on this one,
# you need to include this directory first
if(TARGET hxt_predicates)
  return()
endif()


#################################################################################
# Options (other than inherited ones)
#################################################################################
option(HXT_PREDICATES_OBJECT_ONLY "Do not create hxt_predicates library" ON)


#################################################################################
# Library definition
#################################################################################
set(HXT_PREDICATES_SRC
    "${CMAKE_CURRENT_SOURCE_DIR}/src/predicates.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/predicates.h")

if(HXT_PREDICATES_OBJECT_ONLY)
	# make an object library (no archive)
	add_library(hxt_predicates OBJECT ${HXT_PREDICATES_SRC})
else()
	add_library(hxt_predicates ${HXT_PREDICATES_SRC})
endif()

target_include_directories(hxt_predicates INTERFACE include)
target_link_libraries(hxt_predicates m) # link with the math library


#################################################################################
# Compilation flags to ensure robustness
#################################################################################
if(MSVC OR (CMAKE_C_COMPILER_ID STREQUAL "Intel" AND WIN32))
	target_compile_options(hxt_predicates PRIVATE "/fp:strict")
elseif(CMAKE_C_COMPILER_ID STREQUAL "Intel")
	target_compile_options(hxt_predicates PRIVATE "-fp-model=strict")
elseif(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
	target_compile_options(hxt_predicates
	                       PRIVATE
	                       "-fno-unsafe-math-optimizations" "-ffp-contract=off")
else()
	message(WARNING
	        "Unsupported compiler !
	         Make sure compiled functions from predicates.c
	         do NOT use extended double precision and follow IEEE754 standard.
	         It is crucial for the robustness of geometric predicates.")
endif()
