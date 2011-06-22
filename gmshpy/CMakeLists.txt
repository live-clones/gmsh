set (SWIG_MODULES
  gmshCommon
  gmshGeo
  gmshNumeric
  gmshPost
  gmshSolver
  gmshMesh
)

if(ENABLE_SWIG)
  find_package(SWIG)
  if(SWIG_FOUND)
    message(STATUS "Found SWIG version " ${SWIG_VERSION})
    string(SUBSTRING ${SWIG_VERSION} 0 1 SWIG_MAJOR_VERSION)
    if(SWIG_MAJOR_VERSION EQUAL 1)
      message("WARNING: Python bindings require SWIG >= 2: disabling Python")
    else(SWIG_MAJOR_VERSION EQUAL 1)
      include(${SWIG_USE_FILE})
      find_package(PythonLibs)
      include_directories(${PYTHON_INCLUDE_DIR})

      foreach(module ${SWIG_MODULES})
        set_source_files_properties(${module}.i PROPERTIES CPLUSPLUS ON)
        swig_add_module(${module} python ${module}.i)
        swig_link_libraries(${module} ${PYTHON_LIBRARIES} shared)
        SET(GMSH_PYTHON_MODULES_INCLUDE_CODE 
            "${GMSH_PYTHON_MODULES_INCLUDE_CODE}from ${module} import *\n")
      endforeach(module)

      configure_file(${CMAKE_CURRENT_SOURCE_DIR}/__init__.py.in 
                     ${CMAKE_CURRENT_BINARY_DIR}/__init__.py)

    endif(SWIG_MAJOR_VERSION EQUAL 1)
  endif(SWIG_FOUND)
endif(ENABLE_SWIG)
