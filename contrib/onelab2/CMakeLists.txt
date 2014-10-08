set(SRC
  NetworkUtils.cpp
  OnelabAttributes.cpp
  OnelabProtocol.cpp
  OnelabLocalNetworkClient.cpp
  OnelabServer.cpp
  OnelabNetworkClient.cpp)

file(GLOB HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(contrib/onelab2 "${SRC};${HDR}")

# build only the server
if(HAVE_UDT)
	find_package(Threads REQUIRED)
	find_path(UDT_INCLUDE_DIR udt.h PATH_SUFFIXES include udt)
	find_library(UDT_LIBRARY udt)
	if(UDT_INCLUDE_DIR AND UDT_LIBRARY AND Threads_FOUND)
		list(APPEND EXTERNAL_INCLUDES ${UDT_INCLUDE_DIR})
		list(APPEND EXTERNAL_LIBRARIES ${CMAKE_THREAD_LIBS_INIT})
		list(APPEND EXTERNAL_LIBRARIES ${UDT_LIBRARY})
	else(UDT_INCLUDE_DIR AND UDT_LIBRARY AND Threads_FOUND)
		message(FATAL_ERROR "Unable to find UDT library")
	endif(UDT_INCLUDE_DIR AND UDT_LIBRARY AND Threads_FOUND)
endif(HAVE_UDT)

include_directories(${CMAKE_SOURCE_DIR}/Common/) # for onelab.h
include_directories(${CMAKE_BINARY_DIR}/Common/) # for GmshConfig.h
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/)
include_directories(${EXTERNAL_INCLUDES}) # for UDT
add_executable (onelabserver Onelab.cpp OnelabServer.cpp OnelabNetworkClient.cpp OnelabLocalNetworkClient.cpp NetworkUtils.cpp OnelabProtocol.cpp OnelabAttributes.cpp) 
target_link_libraries(onelabserver ${EXTERNAL_LIBRARIES})
