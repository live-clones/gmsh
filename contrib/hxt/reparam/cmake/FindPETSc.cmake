# - Try to find PETSc
# Once done this will define
#
#  PETSC_INC     - the PETSc include directories
#  PETSC_LIBS    - Link these to use PETSc

macro(find_all_libraries VARNAME LISTNAME PATH SUFFIX)
  set(${VARNAME})
  list(LENGTH ${LISTNAME} NUM_LIST)
  foreach(LIB ${${LISTNAME}})
    if("${PATH}" STREQUAL "")
      find_library(FOUND_LIB ${LIB} PATH_SUFFIXES ${SUFFIX})
    else("${PATH}" STREQUAL "")
      find_library(FOUND_LIB ${LIB} PATHS ${PATH} NO_DEFAULT_PATH)
    endif("${PATH}" STREQUAL "")
    if(FOUND_LIB)
      list(APPEND ${VARNAME} ${FOUND_LIB})
    endif(FOUND_LIB)
    unset(FOUND_LIB CACHE)
  endforeach(LIB)
  list(LENGTH ${VARNAME} NUM_FOUND_LIBRARIES)
  if(NUM_FOUND_LIBRARIES LESS NUM_LIST)
    set(${VARNAME})
  endif(NUM_FOUND_LIBRARIES LESS NUM_LIST)
endmacro(find_all_libraries)


if(PETSC_DIR)
  set(ENV_PETSC_DIR ${PETSC_DIR})
else(PETSC_DIR)
  set(ENV_PETSC_DIR $ENV{PETSC_DIR})
endif(PETSC_DIR)
if(PETSC_ARCH)
  set(ENV_PETSC_ARCH ${PETSC_ARCH})
else(PETSC_ARCH)
  set(ENV_PETSC_ARCH $ENV{PETSC_ARCH})
endif(PETSC_ARCH)
set(PETSC_POSSIBLE_CONF_FILES 
    ${ENV_PETSC_DIR}/${ENV_PETSC_ARCH}/conf/petscvariables
    ${ENV_PETSC_DIR}/${ENV_PETSC_ARCH}/lib/petsc-conf/petscvariables
    ${ENV_PETSC_DIR}/${ENV_PETSC_ARCH}/lib/petsc/conf/petscvariables)
foreach(FILE ${PETSC_POSSIBLE_CONF_FILES})
  if(EXISTS ${FILE})
    # old-style PETSc installations (using PETSC_DIR and PETSC_ARCH)
    message(STATUS "Using PETSc dir: ${ENV_PETSC_DIR}")
    message(STATUS "Using PETSc arch: ${ENV_PETSC_ARCH}")
    # find includes by parsing the petscvariables file
    file(STRINGS ${FILE} PETSC_VARIABLES NEWLINE_CONSUME)
  endif(EXISTS ${FILE})
endforeach(FILE)
if(PETSC_VARIABLES)
  # try to find PETSC_CC_INCLUDES for PETSc >= 3.4
  string(REGEX MATCH "PETSC_CC_INCLUDES = [^\n\r]*" PETSC_PACKAGES_INCLUDES
         ${PETSC_VARIABLES})
  if(PETSC_PACKAGES_INCLUDES)
    string(REPLACE "PETSC_CC_INCLUDES = " "" PETSC_PACKAGES_INCLUDES
           ${PETSC_PACKAGES_INCLUDES})
  else(PETSC_PACKAGES_INCLUDES)
    # try to find PETSC_PACKAGES_INCLUDES in older versions
    list(APPEND PETSC_INC ${ENV_PETSC_DIR}/include)
    list(APPEND PETSC_INC ${ENV_PETSC_DIR}/${ENV_PETSC_ARCH}/include)
    string(REGEX MATCH "PACKAGES_INCLUDES = [^\n\r]*" PETSC_PACKAGES_INCLUDES
           ${PETSC_VARIABLES})
    string(REPLACE "PACKAGES_INCLUDES = " "" PETSC_PACKAGES_INCLUDES
           ${PETSC_PACKAGES_INCLUDES})
  endif(PETSC_PACKAGES_INCLUDES)
  if(PETSC_PACKAGES_INCLUDES)
    if(PETSC_PACKAGES_INCLUDES)
      string(REPLACE "-I" "" PETSC_PACKAGES_INCLUDES ${PETSC_PACKAGES_INCLUDES})
      string(REPLACE " " ";" PETSC_PACKAGES_INCLUDES ${PETSC_PACKAGES_INCLUDES})
      foreach(VAR ${PETSC_PACKAGES_INCLUDES})
        # seem to include unexisting directories (/usr/include/lib64)
  # check to avoid warnings
  if(EXISTS ${VAR})
    list(APPEND PETSC_INC ${VAR})
        endif(EXISTS ${VAR})
      endforeach(VAR)
    endif(PETSC_PACKAGES_INCLUDES)
  endif(PETSC_PACKAGES_INCLUDES)
  # find libraries (<= 3.0)
  set(PETSC_LIBS_REQUIRED petscksp petscdm petscmat petscvec petsc)
  find_all_libraries(PETSC_LIBS PETSC_LIBS_REQUIRED
                     ${ENV_PETSC_DIR}/${ENV_PETSC_ARCH}/lib "")
  # petsc 3.1 creates only one library (libpetsc)
  if(NOT PETSC_LIBS)
    find_library(PETSC_LIBS petsc PATHS ${ENV_PETSC_DIR}/${ENV_PETSC_ARCH}/lib
                 NO_DEFAULT_PATH)
  endif(NOT PETSC_LIBS)
  # find additional libraries to link with
  string(REGEX MATCH "PACKAGES_LIBS = [^\n\r]*" PLIBS ${PETSC_VARIABLES})
  if(PLIBS)
    string(REPLACE "PACKAGES_LIBS = " "" PLIBS ${PLIBS})
    string(STRIP ${PLIBS} PLIBS)
    list(APPEND PETSC_LIBS "${PLIBS}")
  endif(PLIBS)
  string(REGEX MATCH "PETSC_EXTERNAL_LIB_BASIC = [^\n\r]*" PLIBS_BASIC ${PETSC_VARIABLES})
  if(PLIBS_BASIC)
    string(REPLACE "PETSC_EXTERNAL_LIB_BASIC = " "" PLIBS_BASIC ${PLIBS_BASIC})
    string(STRIP ${PLIBS_BASIC} PLIBS_BASIC)
    separate_arguments(PLIBS_BASIC)
    list(APPEND PETSC_LIBS "${PLIBS_BASIC}")
  endif(PLIBS_BASIC)
  string(REGEX MATCH "PCC_LINKER_LIBS = [^\n\r]*" LLIBS ${PETSC_VARIABLES})
  if(LLIBS)
    string(REPLACE "PCC_LINKER_LIBS = " "" LLIBS ${LLIBS})
    string(STRIP ${LLIBS} LLIBS)
    list(APPEND PETSC_LIBS "${LLIBS}")
  endif(LLIBS)
else(PETSC_VARIABLES)
  # new-style PETSc installations (in standard system directories)
  find_library(PETSC_LIBS petsc)
  find_path(PETSC_INC "petsc.h" PATH_SUFFIXES include/petsc)
endif(PETSC_VARIABLES)


include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(PETSc DEFAULT_MSG PETSC_LIBS PETSC_INC)
mark_as_advanced(PETSC_LIBS PETSC_INC)

