cmake_minimum_required(VERSION 3.5)

project(graphPartitioner)

option(MPI "Compile the parallel version" OFF)

file(GLOB FILES main.cpp
		io.cpp
		graph.cpp
		topology.cpp)

include_directories(include/gmsh)
include_directories(include/metis)

if(MPI)
	message("Parallel version")

	set(CMAKE_CXX_COMPILER "mpic++")
	set(CMAKE_C_COMPILER "mpicc")

	find_package (MPI)
	if (MPI_FOUND)
		include_directories(${MPI_INCLUDE_PATH})
	endif(MPI_FOUND)

	add_definitions(-DPARALLEL)

	file(GLOB FILESMPI main_mpi.cpp
			   topology_mpi.cpp)
else(MPI)
	message("Sequential version")
endif(MPI)

if(APPLE)
	message("OS X build")
	link_directories(lib/osx)
	set(EXECUTABLE_OUTPUT_PATH ../bin/osx)
else(APPLE)
	message("NIC4 build")
	link_directories(lib/nic4)
	set(EXECUTABLE_OUTPUT_PATH ../bin/nic4)
endif(APPLE)


if(MPI)
	add_executable(meshPartitioner_mpi ${FILES} ${FILESMPI})
	target_link_libraries(meshPartitioner_mpi Gmsh lapack blas parmetis metis)
else(MPI)
	add_executable(meshPartitioner ${FILES})
	target_link_libraries(meshPartitioner Gmsh lapack blas metis)
endif(MPI)
