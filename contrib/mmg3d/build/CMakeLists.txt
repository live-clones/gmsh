cmake_minimum_required (VERSION 2.6)
project (MMG3D)     

IF(APPLE) 
   add_definitions(-static-libgcc -mmacosx-version-min=10.4 -arch ppc -arch i386)  

   # determine if the processor supports 64bit execution
   EXECUTE_PROCESS(
      COMMAND sysctl hw.cpu64bit_capable
      ERROR_QUIET
      OUTPUT_VARIABLE 64_CMD
      OUTPUT_STRIP_TRAILING_WHITESPACE
   )
   STRING(REGEX REPLACE "^hw.cpu64bit_capable: (.*)" "\\1" 64_BIT "${64_CMD}")
   #otherwise pbs with linkage SCOTCH
   SET(CMAKE_OSX_ARCHITECTURES ppc)   
   
   # display the results
   MESSAGE(STATUS "CMAKE_OSX_ARCHITECTURES: " ${CMAKE_OSX_ARCHITECTURES})
ENDIF(APPLE)  



# should we use SCOTCH
option (USE_SCOTCH 
        "Use SCOTCH TOOL for renumbering" ON) 

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "sources/mmg3dConfig.h.in"
  "sources/mmg3dConfig.h"
  )

# add SCOTCH library?
#
if (USE_SCOTCH)  
  #Inclusion de SCOTCH
  find_library(LIBS_SCOTCH scotch)
  find_library(LIBS_SCOTCHERR scotcherr)
  find_path(INCLUDE_SCOTCH scotch.h)
  # IF(LIBS_SCOTCH_FOUND)
  # 	MESSAGE(STATUS "Looking for SCOTCH - found")
  # ELSE(SCOTCH_FOUND)
  # 	MESSAGE(STATUS "Looking for SCOTCH - not found")
  # ENDIF(SCOTCH_FOUND)   
  include_directories(${INCLUDE_SCOTCH}) 
endif (USE_SCOTCH)   

#file sources
file(
	GLOB_RECURSE
	source_files
	sources/*
)

add_executable(mmg3d4.0 ${source_files})                                    

option (COMPIL_STATIC_LIBRARY 
        "Use tutorial provided math implementation" OFF) 
if (COMPIL_STATIC_LIBRARY)  
  add_library(mmg3dlib4.0 STATIC ${source_files})
  target_link_libraries(mmg3dlib4.0 ${M_LIB} ${LIBS_SCOTCH} ${LIBS_SCOTCHERR})
endif (COMPIL_STATIC_LIBRARY)   
option (COMPIL_SHARED_LIBRARY 
        "Use tutorial provided math implementation" OFF) 
if (COMPIL_SHARED_LIBRARY)  
  add_library(mmg3dlib4.0 SHARED ${source_files})
  target_link_libraries(mmg3dlib4.0 ${M_LIB} ${LIBS_SCOTCH} ${LIBS_SCOTCHERR})
endif (COMPIL_SHARED_LIBRARY)   

find_library(M_LIB m)
target_link_libraries(mmg3d4.0 ${M_LIB} ${LIBS_SCOTCH} ${LIBS_SCOTCHERR})    

#add testlib   
if (COMPIL_STATIC_LIBRARY) 
  #file sources
  file(
  	GLOB_RECURSE
  	source_testlib
  	libexamples/*
  )
  add_executable(testlib ${source_testlib}) 
  include_directories(sources/)                                    
  target_link_libraries(testlib mmg3dlib4.0)    
endif (COMPIL_STATIC_LIBRARY)   

if (COMPIL_SHARED_LIBRARY) 
  #file sources
  file(
  	GLOB_RECURSE
  	source_testlib
  	libexamples/*
  )
  add_executable(testlib ${source_testlib}) 
  include_directories(sources/)                                    
  target_link_libraries(testlib mmg3dlib4.0)    
endif (COMPIL_SHARED_LIBRARY)
