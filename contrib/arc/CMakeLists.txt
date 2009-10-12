
# pour boris!

add_executable(boris EXCLUDE_FROM_ALL contrib/arc/boris.cpp ${GMSH_SRC})
target_link_libraries(boris ${EXTERNAL_LIBRARIES} ${LAPACK_LIBRARIES})

