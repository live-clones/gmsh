# pour boris:
## boris cela ne marche que si le fichier est dans SVN ...
#include(/home/boris/MyGmshProjects/CMakeLists.txt)
# tests pour eric et christophe:
list(APPEND EXTERNAL_INCLUDES contrib/arc)
add_executable(elastic EXCLUDE_FROM_ALL contrib/arc/mainElasticity.cpp ${GMSH_SRC})
target_link_libraries(elastic ${LINK_LIBRARIES})

