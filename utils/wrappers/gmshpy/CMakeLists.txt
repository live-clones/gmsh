# Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file in the Gmsh root directory for license information.
# Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

set(SWIG_MODULES
  gmshCommon
  gmshGeo
  gmshNumeric
  gmshPost
  gmshSolver
  gmshMesh
)
if (NOT GMSHPY_INSTALL_DIRECTORY)
  execute_process(COMMAND ${PYTHON_EXECUTABLE} -c "from distutils import sysconfig; print (sysconfig.get_python_lib(1,0,prefix='${CMAKE_INSTALL_PREFIX}'))" OUTPUT_VARIABLE PYTHON_MODULE_PATH OUTPUT_STRIP_TRAILING_WHITESPACE)
  set(GMSHPY_INSTALL_DIRECTORY ${PYTHON_MODULE_PATH}/gmshpy CACHE STRING "python wrappers installation directory")
endif (NOT GMSHPY_INSTALL_DIRECTORY)

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

include(${SWIG_USE_FILE})
include_directories(${PYTHON_INCLUDE_PATH})

option(ENABLE_GMSHPY_SOURCE_PACKAGE "Instead of generating the python bindings for the current python executable, generate a source package that can be used to generate the bindings without requiring the gmsh source code" OFF)
set(GMSH_PYTHON_MODULES_INCLUDE_CODE "")
foreach(module ${SWIG_MODULES})
  set_source_files_properties(${module}.i PROPERTIES CPLUSPLUS ON)
  # silent the warnings if DISABLE_SWIG_WARNING_FLAG has been set
  string(COMPARE EQUAL "${DISABLE_SWIG_WARNINGS_FLAG}" "" swig_warnings_enabled)
  if(NOT swig_warnings_enabled )
    message("The swig warnings are disabled!")
    set_source_files_properties(${module}.i PROPERTIES SWIG_FLAGS "${DISABLE_SWIG_WARNINGS_FLAG}")
  endif(NOT swig_warnings_enabled )

  # code backported from CMake git version, see CMake bug 4147
  swig_get_wrapper_dependencies(${CMAKE_CURRENT_SOURCE_DIR}/\${module}.i
    ${CMAKE_CURRENT_BINARY_DIR}/${module}PYTHON_wrap.cxx python swig_extra_dependencies)
  list(APPEND SWIG_MODULE_${module}_EXTRA_DEPS ${swig_extra_dependencies})
  swig_add_module(${module} python ${module}.i)
  swig_link_libraries(${module} ${PYTHON_LIBRARIES} shared)
  set(GMSH_PYTHON_MODULES_INCLUDE_CODE
      "${GMSH_PYTHON_MODULES_INCLUDE_CODE}from gmshpy.${module} import *\n")
  list(APPEND GMSHPY_DEPENDS "${module}PYTHON_wrap.cxx")

  if (NOT ENABLE_GMSHPY_SOURCE_PACKAGE)
    install(TARGETS ${SWIG_MODULE_${module}_REAL_NAME} DESTINATION ${GMSHPY_INSTALL_DIRECTORY})
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${module}.py DESTINATION ${GMSHPY_INSTALL_DIRECTORY})
  endif (NOT ENABLE_GMSHPY_SOURCE_PACKAGE)
  if(APPLE)
    set_target_properties("_${module}" PROPERTIES LINK_FLAGS "-undefined suppress -flat_namespace")
  endif(APPLE)
endforeach(module)

if (NOT ENABLE_GMSHPY_SOURCE_PACKAGE)
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
endif (NOT ENABLE_GMSHPY_SOURCE_PACKAGE)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/__init__.py.in ${CMAKE_CURRENT_BINARY_DIR}/__init__.py)
if (NOT ENABLE_GMSHPY_SOURCE_PACKAGE)
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/__init__.py DESTINATION ${GMSHPY_INSTALL_DIRECTORY})
endif (NOT ENABLE_GMSHPY_SOURCE_PACKAGE)

if(ENABLE_GMSHPY_SOURCE_PACKAGE)
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

endif(ENABLE_GMSHPY_SOURCE_PACKAGE)
