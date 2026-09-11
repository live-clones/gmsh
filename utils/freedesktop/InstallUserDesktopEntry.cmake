# Install the desktop entry for the current user only, pointing at a binary that
# is not installed -- typically one sitting in a build tree.
#
# Without an entry the desktop cannot tell which application a Gmsh window
# belongs to, and the window rules that key on that (tiling extensions, "always
# on this workspace", ...) skip the window. See the comments in
# src/imgui/appWindow.cpp and src/fltk/FlGui.cpp for the matching side.
#
# Invoked by the "desktop-entry" target with ENTRY and EXECUTABLE set. Deleting
# the written file undoes everything this does.

if(NOT DEFINED ENTRY OR NOT DEFINED EXECUTABLE)
  message(FATAL_ERROR "ENTRY and EXECUTABLE must be set")
endif()

if(DEFINED ENV{XDG_DATA_HOME} AND NOT "$ENV{XDG_DATA_HOME}" STREQUAL "")
  set(DATA_HOME "$ENV{XDG_DATA_HOME}")
else()
  set(DATA_HOME "$ENV{HOME}/.local/share")
endif()
set(DEST "${DATA_HOME}/applications")

get_filename_component(NAME "${ENTRY}" NAME)
file(READ "${ENTRY}" CONTENT)

# point the launcher at the binary we were given, and keep the entry out of the
# application list: it exists to identify windows, not to be started from a menu
string(REGEX REPLACE "\nExec=[^\n]*" "\nExec=${EXECUTABLE} %f" CONTENT "${CONTENT}")
string(REGEX REPLACE "\nName=[^\n]*" "\nName=Gmsh (${EXECUTABLE})" CONTENT "${CONTENT}")
if(NOT CONTENT MATCHES "\nNoDisplay=")
  string(APPEND CONTENT "NoDisplay=true\n")
endif()

file(MAKE_DIRECTORY "${DEST}")
file(WRITE "${DEST}/${NAME}" "${CONTENT}")
message(STATUS "Wrote ${DEST}/${NAME}")
message(STATUS "Gmsh windows will be recognized by the desktop; delete that "
               "file to undo")
