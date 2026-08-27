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
gmsh.option.setNumber("General.FontSize", 12)
gmsh.option.setNumber("General.GraphicsWidth", plan["width"])
gmsh.option.setNumber("General.GraphicsHeight", plan["height"])
gmsh.fltk.initialize()
for branch in plan["close"]:
    gmsh.fltk.closeTreeItem(branch)
for branch in plan["open"]:
    gmsh.fltk.openTreeItem(branch)
gmsh.fltk.run()
