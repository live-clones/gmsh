set (SWIG_MODULES
  gmshCommon
  gmshGeo
  gmshNumeric
  gmshPost
  gmshSolver
  gmshMesh
)

# code backported from CMake git version, see CMake bug 4147
MACRO(SWIG_GET_WRAPPER_DEPENDENCIES swigFile genWrapper language DEST_VARIABLE)
  GET_FILENAME_COMPONENT(swig_getdeps_basename ${swigFile} NAME_WE)
  GET_FILENAME_COMPONENT(swig_getdeps_outdir ${genWrapper} PATH)
  GET_SOURCE_FILE_PROPERTY(swig_getdeps_extra_flags "${swigFile}" SWIG_FLAGS)
  IF("${swig_getdeps_extra_flags}" STREQUAL "NOTFOUND")
    SET(swig_getdeps_extra_flags "")
  ENDIF("${swig_getdeps_extra_flags}" STREQUAL "NOTFOUND")

  IF(NOT swig_getdeps_outdir)
    SET(swig_getdeps_outdir ${CMAKE_CURRENT_BINARY_DIR})
  ENDIF(NOT swig_getdeps_outdir)
  SET(swig_getdeps_depsfile
    ${swig_getdeps_outdir}/swig_${swig_getdeps_basename}_deps.txt)
  GET_DIRECTORY_PROPERTY(swig_getdeps_include_directories INCLUDE_DIRECTORIES)
  SET(swig_getdeps_include_dirs)
  FOREACH(it ${swig_getdeps_include_directories})
    SET(swig_getdeps_include_dirs ${swig_getdeps_include_dirs} "-I${it}")
  ENDFOREACH(it)
  EXECUTE_PROCESS(
    COMMAND ${SWIG_EXECUTABLE}
    -MM -MF ${swig_getdeps_depsfile} ${swig_getdeps_extra_flags}
    ${CMAKE_SWIG_FLAGS} -${language}
    -o ${genWrapper} ${swig_getdeps_include_dirs} ${swigFile}
    RESULT_VARIABLE swig_getdeps_result
    ERROR_VARIABLE swig_getdeps_error
    OUTPUT_STRIP_TRAILING_WHITESPACE)
  IF(NOT ${swig_getdeps_error} EQUAL 0)
    MESSAGE(SEND_ERROR "Command \"${SWIG_EXECUTABLE} -MM -MF ${swig_getdeps_depsfile} ${swig_getdeps_extra_flags} ${CMAKE_SWIG_FLAGS} -${language} -o ${genWrapper} ${swig_getdeps_include_dirs} ${swigFile}\" failed with output:\n${swig_getdeps_error}")
    SET(swig_getdeps_dependencies "")
  ELSE(NOT ${swig_getdeps_error} EQUAL 0)
    FILE(READ ${swig_getdeps_depsfile} ${DEST_VARIABLE})
    # Remove the first line
    STRING(REGEX REPLACE "^.+: +\\\\\n +" ""
      ${DEST_VARIABLE} "${${DEST_VARIABLE}}")
    # Clean the end of each line
    STRING(REGEX REPLACE " +(\\\\)?\n" "\n" ${DEST_VARIABLE}
      "${${DEST_VARIABLE}}")
    # Clean beginning of each line
    STRING(REGEX REPLACE "\n +" "\n"
      ${DEST_VARIABLE} "${${DEST_VARIABLE}}")
    # clean paths
    STRING(REGEX REPLACE "\\\\\\\\" "/" ${DEST_VARIABLE}
      "${${DEST_VARIABLE}}")
    STRING(REGEX REPLACE "\n" ";"
      ${DEST_VARIABLE} "${${DEST_VARIABLE}}")
  ENDIF(NOT ${swig_getdeps_error} EQUAL 0)
ENDMACRO(SWIG_GET_WRAPPER_DEPENDENCIES)

option(ENABLE_PYTHON_LIB_API "Export all C header files needed to build the python library" OFF)
if(ENABLE_PYTHON_LIB_API)
  set(GMSH_API ${GMSH_API} Geo/Curvature.h Mesh/Generator.h Mesh/highOrderTools.h Mesh/meshGFaceLloyd.h Numeric/DivideAndConquer.h Post/PViewFactory.h Solver/linearSystemPETSc.h Fltk/FlGui.h Solver/functionSpace.h Solver/STensor43.h Solver/sparsityPattern.h Solver/SElement.h Solver/groupOfElements.h PARENT_SCOPE)
endif(ENABLE_PYTHON_LIB_API)

if(HAVE_SWIG)
  include(${SWIG_USE_FILE})
  include_directories(${PYTHON_INCLUDE_DIR})

  foreach(module ${SWIG_MODULES})
    set_source_files_properties(${module}.i PROPERTIES CPLUSPLUS ON)

    # code backported from CMake git version, see CMake bug 4147
    SWIG_GET_WRAPPER_DEPENDENCIES(${CMAKE_CURRENT_SOURCE_DIR}/\${module}.i ${CMAKE_CURRENT_BINARY_DIR}/${module}PYTHON_wrap.cxx python swig_extra_dependencies)
    LIST(APPEND SWIG_MODULE_${module}_EXTRA_DEPS ${swig_extra_dependencies})

    swig_add_module(${module} python ${module}.i)
    swig_link_libraries(${module} ${PYTHON_LIBRARIES} shared)
    SET(GMSH_PYTHON_MODULES_INCLUDE_CODE 
        "${GMSH_PYTHON_MODULES_INCLUDE_CODE}from ${module} import *\n")
    list(APPEND GMSHPY_DEPENDS "_${module}")
  endforeach(module)
  add_custom_target("_gmshpy" DEPENDS ${GMSHPY_DEPENDS})

  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/__init__.py.in 
                 ${CMAKE_CURRENT_BINARY_DIR}/__init__.py)
endif(HAVE_SWIG)
