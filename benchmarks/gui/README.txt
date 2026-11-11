Tests of the FLTK graphical user interface (src/fltk) and of the action
registry it shares with the web page (src/common/Actions.cpp). They open
windows, so they are built and run only when asked:

  cmake -DENABLE_GUI_TESTS=1 -DENABLE_BUILD_DYNAMIC=1 ..
  make gui_registry gui_menus gui_onelab gui_keys
  ctest -L gui --output-on-failure

Each is a program linked to the Gmsh library, run from the build directory
(77 means skipped, when there is no display):

- registry.cpp: every item of the registry resolves (the items of a name agree
  on what they do, every key names an item, every operation is known, every
  icon has strokes), and which items the FLTK interface does not have.
- menus.cpp: the menu bar and the status bar of the FLTK interface are built
  from the registry: every item has its entry or button, with its shortcut.
- onelab.cpp: the ONELAB loop of the FLTK interface on a script, checked
  then computed (meshed), the interface idle again after each.
- keys.cpp: Escape, e, u and q and the mouse selection in every selection
  workflow (query, measure, operations on picked entities, point placing,
  rotation centre, visibility, reclassification, the API's selection), with
  synthetic clicks and keys.

The random user (fuzz.cpp, built as gui_fuzz; ctest skips it, as it needs a
model) opens a model and acts on the interface at random every 50 ms, each
action logged with the seed so that a run can be repeated:

  gui_fuzz model.geo [seconds] [seed]

fuzz.sh runs it on models and seeds, one run at a time in a scratch copy of
each model's files, kills a run stuck for twice its time, and keeps the logs
(and on macOS the crash report of a run that died) in an output directory:

  benchmarks/gui/fuzz.sh bin 60 1,2,3 /tmp/fuzz tutorials/t1.geo tutorials/t5.geo

The windows open on screen while it runs: do not use the computer meanwhile.
