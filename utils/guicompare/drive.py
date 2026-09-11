#!/usr/bin/env python3
"""Hold a Gmsh interface open with a few tree branches unfolded.

Started by shoot.py, one per picture. It does nothing but run: opening a leaf
of the tree usually starts an interactive selection, which never gives control
back, so the clicking and the photographing are done from the outside.
"""

import json
import os
import shutil
import sys

libdir = os.environ.get("GMSH_LIB_DIR")
if libdir:
    sys.path.insert(0, libdir)

import gmsh  # noqa: E402

plan = json.loads(os.environ["GMSH_SHOT_PLAN"])

gmsh.initialize(["gmsh"], run=False)
if plan.get("geo"):
    # on a copy: adding an entity through the interface writes it back to the
    # file the model came from, and the fixture would grow at every run
    copy = os.path.join(os.environ["HOME"], os.path.basename(plan["geo"]))
    shutil.copyfile(plan["geo"], copy)
    gmsh.merge(copy)
# The same font in the three, or nothing can be compared: FLTK 1.3 works out
# 12 points where 1.4 works out 13, and every width of a window follows from
# it -- IW, the width of an input, is ten times the font size.
#
# It is also the only way of drawing these windows larger that the three
# builds share: FLTK 1.3, which the released one is built on, has no screen
# scaling at all. But every coordinate shoot.py clicks is measured at twelve
# points, so raising it means measuring them all again -- see the head of
# shoot.py.
gmsh.option.setNumber("General.FontSize",
                      int(os.environ.get("GUICOMPARE_FONT", 12)))
gmsh.option.setNumber("General.GraphicsWidth", plan["width"])
gmsh.option.setNumber("General.GraphicsHeight", plan["height"])
gmsh.fltk.initialize()
for branch in plan["close"]:
    gmsh.fltk.closeTreeItem(branch)
for branch in plan["open"]:
    gmsh.fltk.openTreeItem(branch)
# The per-entity ONELAB window is raised by double-clicking the entity in the
# 3D view. It is opened here instead, through the API the three builds share:
# a double click that has to land on the right surface is one more thing to
# measure, and what is being photographed is the window, not the picking.
if plan.get("context"):
    gmsh.fltk.showContextWindow(*plan["context"])
gmsh.fltk.run()
