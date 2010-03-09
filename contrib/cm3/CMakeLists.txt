# pour boris:
## boris cela ne marche que si le fichier est dans SVN ...
#include(/home/boris/MyGmshProjects/CMakeLists.txt)
# tests pour eric et christophe:
list(APPEND EXTERNAL_INCLUDES contrib/cm3)
add_executable(dgsolver EXCLUDE_FROM_ALL contrib/cm3/mainDG.cpp contrib/cm3/DgC0PlateSolver.cpp contrib/cm3/MInterfaceElement.cpp contrib/cm3/GModelWithInterface.cpp contrib/cm3/C0DgPlateTerms.h ${GMSH_SRC})
target_link_libraries(dgsolver ${LINK_LIBRARIES})

