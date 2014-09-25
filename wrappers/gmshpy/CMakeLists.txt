# Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to the public mailing list <gmsh@geuz.org>.

set(SWIG_MODULES
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
  set(GMSH_API ${GMSH_API} Geo/Curvature.h Mesh/Generator.h 
      Mesh/meshGFaceLloyd.h Numeric/DivideAndConquer.h Post/PViewFactory.h
      Solver/linearSystemPETSc.h Fltk/FlGui.h Solver/functionSpace.h
      Solver/STensor43.h Solver/sparsityPattern.h Solver/SElement.h
      Solver/groupOfElements.h PARENT_SCOPE)
endif(ENABLE_PYTHON_LIB_API)

include(${SWIG_USE_FILE})
include_directories(${PYTHON_INCLUDE_PATH})

set(GMSH_PYTHON_MODULES_INCLUDE_CODE "")
foreach(module ${SWIG_MODULES})
  set_source_files_properties(${module}.i PROPERTIES CPLUSPLUS ON)

  # code backported from CMake git version, see CMake bug 4147
  swig_get_wrapper_dependencies(${CMAKE_CURRENT_SOURCE_DIR}/\${module}.i 
    ${CMAKE_CURRENT_BINARY_DIR}/${module}PYTHON_wrap.cxx python swig_extra_dependencies)
  list(APPEND SWIG_MODULE_${module}_EXTRA_DEPS ${swig_extra_dependencies})
  swig_add_module(${module} python ${module}.i)
  swig_link_libraries(${module} ${PYTHON_LIBRARIES} shared)
  set(GMSH_PYTHON_MODULES_INCLUDE_CODE 
      "${GMSH_PYTHON_MODULES_INCLUDE_CODE}from gmshpy.${module} import *\n")
  list(APPEND GMSHPY_DEPENDS "${module}PYTHON_wrap.cxx")
  if(APPLE)
    set_target_properties("_${module}" PROPERTIES LINK_FLAGS "-undefined suppress -flat_namespace")
  endif(APPLE)
endforeach(module)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/__init__.py.in ${CMAKE_CURRENT_BINARY_DIR}/__init__.py.orig)
IF(HAVE_MPI)
  # this hack is only required for openmpi compiled with dynamic modules
  # unfortunately I do not know how to detect this situation => I always enable it
  set(GMSH_PYTHON_OPENMPI_HACK "import ctypes\n")
  FOREACH (lib ${MPI_C_LIBRARIES})
    IF (${lib} MATCHES ".*libmpi.*")
      set(GMSH_PYTHON_OPENMPI_HACK 
        "${GMSH_PYTHON_OPENMPI_HACK}ctypes.CDLL(\"${lib}\", mode = ctypes.RTLD_GLOBAL)\n")
    ENDIF (${lib} MATCHES ".*libmpi.*")
  ENDFOREACH (lib)
ENDIF(HAVE_MPI)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/__init__.py.in ${CMAKE_CURRENT_BINARY_DIR}/__init__.py)

string(REPLACE ";" "\", \"" GMSH_PYTHON_MODULES "${SWIG_MODULES}")
set(GMSH_PYTHON_MODULES "\"${GMSH_PYTHON_MODULES}\"")
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/setup.py.in ${CMAKE_CURRENT_BINARY_DIR}/setup.py)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/__init__.py.orig DESTINATION gmshpy/src RENAME __init__.py)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/setup.py DESTINATION gmshpy)
foreach(module ${SWIG_MODULES})
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${module}PYTHON_wrap.cxx DESTINATION gmshpy/src)
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${module}.py DESTINATION gmshpy/src)
  install(TARGETS _${module} DESTINATION gmshpy/src)
endforeach(module)

set (GMSH_PYTHON_EXTRA_INCLUDE 
  Numeric/BasisFactory.h
  Numeric/BergotBasis.h
  Mesh/CenterlineField.h
  Geo/Curvature.h
  Common/Options.h
  Mesh/directions3D.h
  Mesh/DivideAndConquer.h
  Mesh/Field.h
  Mesh/FieldPython.h
  Fltk/FlGui.h
  Solver/frameSolver.h
  Solver/functionSpace.h
  Solver/eigenSolver.h
  Mesh/Generator.h
  Geo/GeomMeshMatcher.h
  Geo/GFaceCompound.h
  Geo/gmshLevelset.h
  Numeric/jacobiPolynomials.h
  Numeric/legendrePolynomials.h
  Plugin/Plugin.h
  Solver/linearSystemPETSc.h
  Mesh/meshGFaceLloyd.h
  contrib/HighOrderMeshOptimizer/OptHomRun.h
  contrib/HighOrderMeshOptimizer/OptHomElastic.h
  contrib/MeshQualityOptimizer/MeshQualityOptimizer.h
  Post/PViewAsSimpleFunction.h
  Post/PViewDataList.h
  Post/PViewFactory.h
  Numeric/pyramidalBasis.h
  Solver/SElement.h
  Numeric/simpleFunctionPython.h
  Solver/STensor33.h
  Solver/STensor43.h
)

foreach (file ${GMSH_PYTHON_EXTRA_INCLUDE})
  install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/../../${file} DESTINATION gmshpy/extra_include)
endforeach(file)
