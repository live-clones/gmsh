Tests of the graphical user interface (src/fltk) and of the action registry it
shares with the web page (src/common/Actions.cpp). They open windows, so they
are built and run only when asked:

  cmake -DENABLE_GUI_TESTS=1 -DENABLE_BUILD_DYNAMIC=1 ..
  make gui_registry gui_menus gui_keys
  ctest -L gui --output-on-failure

Each is a program linked to the Gmsh library, run from the build directory
(77 means skipped, when there is no display):

- registry.cpp: every item of the registry resolves (the items of a name agree
  on what they do, every key names an item, every operation is known, every
  icon has strokes), and which items the FLTK interface does not have.
- menus.cpp: the menu bar and the status bar of the FLTK interface are built
  from the registry: every item has its entry or button, with its shortcut.
- keys.cpp: Escape, e, u and q and the mouse selection in every selection
  workflow (query, measure, operations on picked entities, point placing,
  rotation centre, visibility, reclassification, the API's selection), with
  synthetic clicks and keys.
