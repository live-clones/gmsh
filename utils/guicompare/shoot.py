#!/usr/bin/env python3
"""Photograph the Gmsh dialogs, one build at a time.

Three builds are compared: the released Gmsh installed with pip, which is what
the conversion has to reproduce, and the FLTK and Dear ImGui interfaces of this
tree. All three are driven the same way, so that what the pictures differ by is
the interface and not the way it was photographed.

Everything happens on a private X server. XTEST has no way of telling one
display from another, so the alternative would be clicking on the session of
whoever runs this. HOME is redirected for the same reason: Gmsh remembers
window positions and Dear ImGui remembers its layout, and neither should be
read from, or written to, a real home directory.

Each picture is taken by two processes. drive.py holds the interface open with
the right branches unfolded; this one clicks the leaf and photographs what
appears. They cannot be the same process: opening a leaf usually starts an
interactive selection, which never gives control back.

  probe:  shoot.py --build released --probe --shot elementary
          -> the tree with a cross where each click will land
  shoot:  shoot.py --build released --shot elementary-point
          -> the dialog itself; no --shot takes every tab of every dialog
"""

import argparse
import json
import os
import re
import shutil
import subprocess
import sys
import time
import urllib.request

from Xlib import display, X
from Xlib.ext import xtest
from PIL import Image

HERE = os.path.dirname(os.path.realpath(__file__))


def model(name):
    """One of the little models the dialogs are photographed against.

    Several of them show nothing at all without one: a picking dialog has an
    empty list, and the one that names physical groups offers none, so what
    the picture shows is the empty case and not the dialog.
    """
    return os.path.join(HERE, "models", name)

# --- what to photograph
#
# The branches are unfolded through the API, which only unfolds branches; the
# leaf that raises the dialog has to be clicked, and the coordinates are read
# off what --probe takes. They are per interface: the two trees hold the same
# 89 paths, but not at the same pixel.

# Every tab of every dialog, each reached the way one reaches it: through the
# leaf of the modules tree that raises it. That checks the wiring from the tree
# to the pane at the same time as the pane itself.
#
# A shot says which branches to unfold and which row to click. Rows are counted
# from the top of the unfolded tree, and turned into pixels below -- the rows
# are evenly spaced, so a row number is both shorter to write and easier to
# check than a coordinate.

G = "0Modules/Geometry"
E = G + "/Elementary entities"
P = G + "/Physical groups"
M = "0Modules/Mesh"

SHOTS = []

# Where a dialog that is opened from inside another one goes instead: the arrow
# editor is reached through a button of the option window, and stacked at the
# same place the two would be cut out as one -- the walk that finds the edges of
# a Dear ImGui window would run out of the top one into the one below it, which
# is the same colour.
STACKED_POS = (260, 460)
STACKED = {20}  # Dialog::Arrow


def shot(dialog, pane, branches, row, depth, geo=None, scene=(), added=False,
         press=None, pressName=None, paneName=None):
    """A shot. `geo` is a model to open first, `scene` clicks in the 3D view
    once the dialog is up -- which is how a picking dialog is shown doing
    anything at all, `press` clicks a button of the dialog itself -- which is
    how a folded half of one is opened. A press is given a point per interface,
    since the three do not put the button in the same place."""
    SHOTS.append(dict(name="%s-%s" % (dialog, pane), dialog=dialog,
                      branches=branches, row=row, depth=depth, geo=geo,
                      scene=list(scene), added=added, press=press or {},
                      pressName=pressName or [], paneName=paneName))


def keyed(dialog, keys, tabs=()):
    """A dialog the menu raises, reached by its accelerator.

    Clicking through a menu would mean one more set of coordinates per
    interface; the shortcut is the same in both and is worth testing anyway.
    `tabs` names the tabs to photograph and where to click each, as (name, x in
    the FLTK dialog, x in the Dear ImGui one) -- their widths differ, the
    toolkits do not draw the same.
    """
    if not tabs:
        SHOTS.append(dict(name="%s-" % dialog, dialog=dialog, branches=[],
                          keys=keys))
        return
    for name, xf, xi in tabs:
        SHOTS.append(dict(name="%s-%s" % (dialog, name), dialog=dialog,
                          branches=[], keys=keys, tab=(xf, xi)))


# where the row of tabs sits inside a dialog, per interface
TAB_ROW = {"released": 14, "fltk": 14, "imgui": 30}
# and where the strip is looked for: the row that tells one tab from the next,
# which in FLTK is above the labels rather than through them
TAB_SCAN = {"released": 8, "fltk": 8, "imgui": 30}


# the twelve shapes of the elementary dialog
for _i, _name in enumerate(["parameter", "point", "circle", "ellipse",
                            "rectangle", "disk", "sphere", "cylinder", "box",
                            "torus", "cone", "wedge"]):
    # rows under "Add", in the order the tree lists them
    _under_add = ["Parameter", "Point", "Line", "Spline", "Bezier", "B-Spline",
                  "Circle", "Circle arc", "Ellipse", "Ellipse arc",
                  "Rectangle", "Disk", "Plane surface", "Surface filling",
                  "Sphere", "Cylinder", "Box", "Torus", "Cone", "Wedge",
                  "Volume"]
    _label = {"parameter": "Parameter", "point": "Point", "circle": "Circle",
              "ellipse": "Ellipse", "rectangle": "Rectangle", "disk": "Disk",
              "sphere": "Sphere", "cylinder": "Cylinder", "box": "Box",
              "torus": "Torus", "cone": "Cone", "wedge": "Wedge"}[_name]
    # Modules, Geometry, Elementary entities, Set geometry kernel, Add, then
    # the children of Add
    shot("elementary", _name, [G, E, E + "/Add"],
         5 + _under_add.index(_label), 4)

# the curves whose points are picked rather than typed: they have no window at
# all in the released build, so only the two converted ones can be compared
_GEO = model("point.geo")
# a closed contour for the surfaces, a solid for the volume
_GEO2 = model("contour.geo")
_GEO3 = model("solid.geo")
for _pane, _label in [("line", "Line"), ("spline", "Spline"),
                      ("bezier", "Bezier"), ("bspline", "B-Spline"),
                      ("circlearc", "Circle arc"),
                      ("ellipsearc", "Ellipse arc")]:
    _under_add = ["Parameter", "Point", "Line", "Spline", "Bezier", "B-Spline",
                  "Circle", "Circle arc", "Ellipse", "Ellipse arc",
                  "Rectangle", "Disk", "Plane surface", "Surface filling",
                  "Sphere", "Cylinder", "Box", "Torus", "Cone", "Wedge",
                  "Volume"]
    shot("elementary", _pane, [G, E, E + "/Add"],
         5 + _under_add.index(_label), 4, geo=_GEO, scene=[0], added=True)

# and the surfaces and volumes, gathered from a boundary that is picked whole:
# one click on any curve of a closed contour takes the lot
for _pane, _label, _model in [("planesurface", "Plane surface", _GEO2),
                              ("surfacefilling", "Surface filling", _GEO2),
                              ("volume", "Volume", _GEO3)]:
    _under_add = ["Parameter", "Point", "Line", "Spline", "Bezier", "B-Spline",
                  "Circle", "Circle arc", "Ellipse", "Ellipse arc",
                  "Rectangle", "Disk", "Plane surface", "Surface filling",
                  "Sphere", "Cylinder", "Box", "Torus", "Cone", "Wedge",
                  "Volume"]
    shot("elementary", _pane, [G, E, E + "/Add"],
         5 + _under_add.index(_label), 4, geo=_model, scene=[0], added=True)

# the seven operations of the transform dialog
for _pane, _row in [("translate", 6), ("rotate", 7), ("scale", 8),
                    ("symmetry", 9), ("fillet", 12), ("delete", 14)]:
    shot("transform", _pane, [G, E, E + "/Transform"], _row, 4)
# boolean needs its own branch, which moves what follows it
shot("transform", "boolean", [G, E, E + "/Transform", E + "/Boolean"], 12, 4)

# the two panes of the physical dialog
shot("physical", "add", [G, P, P + "/Add"], 5, 4, geo=model("physical.geo"))
shot("physical", "remove", [G, P, P + "/Remove"], 6, 4,
     geo=model("physical.geo"))

# the three panes of the mesh dialog
shot("mesh", "size", [M, M + "/Define"], 4, 3)
shot("mesh", "transfinite-curve", [M, M + "/Define", M + "/Define/Transfinite"], 8, 4)
shot("mesh", "transfinite-surface", [M, M + "/Define", M + "/Define/Transfinite"], 9, 4)

# the high order tools, the partitioner and the reclassification, which have
# no tabs
shot("highorder", "", [M], 12, 2)
shot("classify", "", [M], 18, 2)
# and the same after "All", which detects the edges of a triangulation: what
# one may do next is no longer greyed out
shot("classify", "detected", [M], 18, 2, geo=model("facets.stl"),
     press={"released": (155, 41), "fltk": (146, 41), "imgui": (116, 57)},
     pressName=["All"])
shot("partition", "", [M], 14, 2)
# and the same dialog with its advanced half unfolded
shot("partition", "advanced", [M], 14, 2,
     press={"released": (368, 120), "fltk": (398, 104), "imgui": (352, 104)},
     pressName=["Advanced"])

# and the ones the Tools menu raises
keyed("manipulator", ["ctrl", "shift", "m"])
keyed("options", ["ctrl", "shift", "n"])
# and the same window on another category, since picking one in the list on the
# left is what changes the tabs on the right
SHOTS.append(dict(name="options-mesh", dialog="options", branches=[],
                  keys=["ctrl", "shift", "n"], pressName=["Mesh"],
                  press={"released": (45, 37), "fltk": (45, 40),
                         "imgui": (45, 67)}))
keyed("clipping", ["ctrl", "shift", "c"])
# the plugins, on a model with a view to run them on
SHOTS.append(dict(name="plugins", dialog="plugins", branches=[],
                  keys=["ctrl", "shift", "u"], geo=model("view.pos"),
                  everyTab={"released": ["options", "help"],
                            "fltk": ["options", "help"],
                            "imgui": ["options", "help"]},
                  # measured on a picture of the open window: FLTK 1.4 draws
                  # this strip beside two list boxes whose borders read as tab
                  # separators, so it is the one dialog whose tabs are written
                  # down rather than found
                  tabsAt={"fltk": [(261, 94), (306, 94)]}))
# The visibility window, on a model that has something to hide. Every one of
# its tabs is photographed, and where each tab is, is read off the picture --
# the released build has one more of them than the converted ones, so they are
# named per interface.
SHOTS.append(dict(name="visibility", dialog="visibility", branches=[],
                  keys=["ctrl", "shift", "v"], geo=_GEO3,
                  everyTab={"released": ["list", "tree", "numeric",
                                         "interactive", "per-window"],
                            "fltk": ["list", "tree", "numeric",
                                     "interactive", "per-window"],
                            "imgui": ["list", "tree", "numeric",
                                      "interactive", "per-window"]}))
# The size fields, on a model that already has one. As it opens, the window
# says to pick a field or make one; the field is picked by clicking the first
# line of its list, which is not in the same place in the three interfaces.
_FIELD = model("field.geo")
shot("fields", "", [M, M + "/Define"], 5, 3, geo=_FIELD)
shot("fields", "box", [M, M + "/Define"], 5, 3, geo=_FIELD,
     press={"released": (60, 40), "fltk": (60, 45), "imgui": (60, 58)},
     pressName=["list:0"])
# and the same, on its help
shot("fields", "help", [M, M + "/Define"], 5, 3, geo=_FIELD,
     press={"released": [(60, 40), (207, 47)],
            "fltk": [(60, 45), (233, 42)],
            "imgui": [(60, 58), (234, 51)]},
     pressName=["list:0"], paneName="help")

# the three windows of the Help menu; About has no accelerator, so it is
# reached through the menu itself
keyed("shortcuts", ["ctrl", "h"])
keyed("listing", ["ctrl", "shift", "h"])
# and the same listing with a line picked: the converted windows then offer
# what that option is worth, where one can change it
SHOTS.append(dict(name="listing-picked", dialog="listing", branches=[],
                  keys=["ctrl", "shift", "h"], pressName=["list:0"],
                  press={"released": (100, 40), "fltk": (100, 40),
                         "imgui": (100, 58)}))
# About has no accelerator: it is reached through the Help menu, whose entries
# are not in the same place in the three interfaces -- the converted menu
# writes a check mark beside the entries that show a window, which makes its
# rows taller. Measured on a picture of the open menu, as everything else here.
SHOTS.append(dict(name="about-", dialog="about", branches=[],
                  menuPath=["Help", "About Gmsh"],
                  menu={"released": [(162, 12), (179, 101)],
                        "fltk": [(162, 12), (180, 109)],
                        "imgui": [(154, 9), (172, 111)]}))

# The parameters a solver attaches to one entity, which a double click on that
# entity raises. It is opened through the API rather than by clicking in the
# view: all three builds have gmsh.fltk.showContextWindow(), and a double click
# that has to land on the right surface would be one more thing to measure.
SHOTS.append(dict(name="parameters-", dialog="parameters", branches=[],
                  geo=model("onelab.geo"), context=[2, 1]))

# The quick access menu of the status bar, which both interfaces now build
# from one description. A menu that has popped up is not a window the X server
# will name, so the picture is of the whole window it opened over.
SHOTS.append(dict(name="quickaccess-", dialog="quickaccess", branches=[],
                  geo=model("view.pos"), whole=True,
                  # the second button of the bar, which is what the page calls
                  # it: a menu lives in the page, so it is pressed there
                  barButton=1,
                  menu={"released": [(22, 735)], "fltk": [(22, 735)],
                        "imgui": [(41, 987)]}))

# The tree down the left side, with what a solver has published under its
# commands. Nothing else photographs those: the parameters of onelab.geo are
# "ONELAB Context/" templates, which belong to the per-entity window and are
# kept out of the tree on purpose, so a change to how a parameter is drawn
# could pass unseen. The picture is of the whole window, the tree being a part
# of it rather than a window the X server would name.
SHOTS.append(dict(name="tree-", dialog="tree", branches=[],
                  geo=model("parameters.geo"), whole=True))

# The file choosers, which nothing photographed: they are what every entry of
# the File menu opens, and what says which format an exported view is written
# in. A chooser is a window of its own in one interface and a panel inside the
# one window in the other, so the picture is of the whole window; it is left
# open, which is why each of these keeps an interface to itself.
SHOTS.append(dict(name="open-", dialog="open", branches=[], whole=True,
                  menu={"released": [(18, 11), (50, 49)],
                        "fltk": [(18, 11), (50, 51)],
                        "imgui": [(14, 9), (50, 48)]}))
# the one that offers the formats by name, which is what the export of a view
# is asked and what one of the two interfaces could not answer
SHOTS.append(dict(name="export-", dialog="export", branches=[], whole=True,
                  geo=model("view.pos"),
                  menu={"released": [(18, 11), (50, 236)],
                        "fltk": [(18, 11), (50, 260)],
                        "imgui": [(14, 9), (50, 244)]}))

# The three little windows that ask for one thing. The pattern of the files to
# watch is reached through the File menu, and the arrow editor through the
# button the option window carries on its General/Aspect tab -- neither has an
# accelerator, and both are where they have always been.
SHOTS.append(dict(name="watch-", dialog="watch", branches=[],
                  menuPath=["File", "Watch Pattern..."],
                  menu={"released": [(18, 11), (50, 100)],
                        "fltk": [(18, 11), (50, 107)],
                        "imgui": [(14, 9), (50, 96)]}))
SHOTS.append(dict(name="arrow-", dialog="arrow", branches=[],
                  keys=["ctrl", "shift", "n"], pressIn="options",
                  at=STACKED_POS, paneName="aspect",
                  pressName=["Edit arrow"],
                  press={"released": [(270, 14), (360, 220)],
                         "fltk": [(287, 14), (360, 220)],
                         "imgui": [(287, 32), (345, 211)]}))

keyed("statistics", ["ctrl", "i"],
      tabs=[("geometry", 55, 40), ("mesh", 112, 100), ("post", 187, 165)])

# What a row number is worth, per interface: where the first row is and how
# far apart two of them are. The FLTK tree starts with its "Modules" root; the
# Dear ImGui one starts at "Geometry", so its rows are counted from one further
# in. Measured off a --probe picture, and worth measuring again whenever the
# font changes: a pitch that is a pixel out is half a row out by the twentieth,
# and a click that lands between two rows opens nothing -- or, worse, leaves
# the dialog of the shot before it up, and that is what gets photographed.
GEOMETRY = {"released": (35, 17.0, 0), "fltk": (34, 17.0, 0),
            "imgui": (51.5, 16.0, 1)}
INDENT = {"released": {2: 75, 3: 95, 4: 100},
          "fltk": {2: 75, 3: 95, 4: 100},
          "imgui": {2: 50, 3: 85, 4: 90}}


def where(build, row, depth):
    top, pitch, skip = GEOMETRY[build]
    return INDENT[build][depth], int(round(top + pitch * (row - skip)))


TITLES = {
    "elementary": "^Elementary Entity Context$",
    "physical": "^Physical .* Context$",
    "transform": "^Elementary Operation Context$",
    "mesh": "^Mesh Context$",
    "partition": "^Partition$",
    "highorder": "^High-order tools$",
    "manipulator": "^Manipulator$",
    "statistics": "^Statistics$",
    "clipping": "^Clipping$",
    "options": "^Options",
    "visibility": "^Visibility$",
    "plugins": "^Plugins$",
    "fields": "^Size fields$",
    "classify": "^Reclassify 2D$",
    "shortcuts": "^Keyboard and Mouse Usage$",
    "listing": "^Current Options and Workspace$",
    "about": "^About Gmsh$",
    "parameters": "^Parameters$",
    "watch": "^Watch Pattern$",
    "arrow": "^Arrow Editor$",
    "factor": "^Factor$",
}

# every branch any shot unfolds, deepest first: closing a parent would hide the
# children before they are closed
ALL_BRANCHES = []
for _s in SHOTS:
    for _b in _s["branches"]:
        if _b not in ALL_BRANCHES:
            ALL_BRANCHES.append(_b)
CLOSE_ORDER = sorted(ALL_BRANCHES, key=len, reverse=True)

WIDTH, HEIGHT = 900, 700

# Where the Dear ImGui dialogs are made to open: clear of the modules panel, so
# that the picture holds the dialog and nothing else. Dear ImGui keys its saved
# layout on what follows "###", so the visible part of the name does not matter
# -- which is just as well, since the physical dialog renames itself.
DIALOG_POS = (260, 60)
# Only where they are: a size would override the one the dialog asks for, and
# what a dialog is worth is part of what is being compared.
IMGUI_INI = "".join(
    "[Window][shot###gmshDialog%d]\nPos=%d,%d\nCollapsed=0\n\n"
    # one line per dialog there is, and a few to spare: a dialog with no entry
    # of its own is put wherever Dear ImGui likes, and the picture is then
    # taken of whatever happens to be at the place this expects
    % ((i,) + (STACKED_POS if i in STACKED else DIALOG_POS))
    for i in range(24))


def dialog_title(dialog):
    return TITLES[dialog]


# --- the private X server

class Xserver:
    def __init__(self, number, size="1400x1000x24"):
        self.number, self.size, self.proc = number, size, None

    def __enter__(self):
        self.proc = subprocess.Popen(
            ["Xvfb", ":%d" % self.number, "-screen", "0", self.size,
             "-nolisten", "tcp", "-noreset"],
            stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        os.environ["DISPLAY"] = ":%d" % self.number
        os.environ.pop("WAYLAND_DISPLAY", None)
        for _ in range(100):
            time.sleep(0.1)
            try:
                display.Display().close()
                return self
            except Exception:
                continue
        raise RuntimeError("the private X server never came up")

    def __exit__(self, *exc):
        if self.proc:
            self.proc.terminate()
            self.proc.wait()


# --- looking at what is on that server

def named_windows(dpy):
    """Every window that has a name, with where it really is on the screen."""
    out = []
    root = dpy.screen().root

    def walk(win, depth=0):
        try:
            name = win.get_wm_name()
            geom = win.get_geometry()
            tree = win.query_tree()
        except Exception:
            return
        if name:
            x, y, w = 0, 0, win
            try:
                while w.id != root.id:
                    g = w.get_geometry()
                    x, y = x + g.x, y + g.y
                    w = w.query_tree().parent
            except Exception:
                pass
            out.append((name, win, x, y, geom.width, geom.height))
        if depth < 3:
            for child in tree.children:
                walk(child, depth + 1)

    walk(root)
    return out


def wait_for(dpy, predicate, seconds=25.0):
    end = time.time() + seconds
    while time.time() < end:
        for entry in named_windows(dpy):
            if predicate(entry[0]):
                return entry
        time.sleep(0.25)
    return None


def grab(dpy, win, w, h):
    raw = win.get_image(0, 0, w, h, X.ZPixmap, 0xffffffff).data
    if isinstance(raw, str):
        raw = raw.encode("latin-1")
    return Image.frombytes("RGB", (w, h), bytes(raw), "raw", "BGRX")


def imgui_box(img, pos, slack=6):
    """The rectangle of the Dear ImGui window that opens at `pos`.

    Diffing two pictures does not find it: the dialog opens over a scene that
    the same click also changes, and over the tree that the clicks before it
    unfolded. But its position is known -- it was written into the layout file
    -- so the rectangle can simply be walked out from there, along the title
    bar and then down the padding on its left, both of which are flat colour
    against the gradient of the scene.
    """
    px, py = pos
    if px + 4 >= img.width or py + 4 >= img.height:
        return None
    title = img.getpixel((px + 4, py + 3))
    x1 = px
    for x in range(px, img.width):
        if img.getpixel((x, py + 3)) == title:
            x1 = x
        elif x - x1 > slack:
            break
    inside = img.getpixel((px + 3, py + 26))
    y1 = py
    for y in range(py, img.height):
        if img.getpixel((px + 3, y)) in (title, inside):
            y1 = y
        elif y - y1 > slack:
            break
    if x1 - px < 40 or y1 - py < 20:
        return None
    return (px, py, x1 + 1, y1 + 1)


def mark(img, x, y, r=5):
    """Draw a cross where the click will land, for --probe to be checkable."""
    from PIL import ImageDraw
    d = ImageDraw.Draw(img)
    d.line((x - r, y, x + r, y), fill=(255, 0, 0))
    d.line((x, y - r, x, y + r), fill=(255, 0, 0))


def wiggle(dpy, x, y, times=4):
    """Move the pointer a little, to make sure a frame gets drawn.

    The Dear ImGui interface waits on glfwWaitEvents() while an interactive
    selection is running, so with nobody touching the machine it simply stops
    redrawing and the picture is whatever was on screen before. A few moves
    over the modules panel wake it up without touching any value -- moving over
    the scene would, since placing a point follows the pointer.
    """
    for i in range(times):
        xtest.fake_input(dpy, X.MotionNotify, x=x + (i % 2), y=y)
        dpy.sync()
        time.sleep(0.2)


KEYSYM = {"ctrl": 0xffe3, "shift": 0xffe1, "alt": 0xffe9,
          "left": 0xff51, "up": 0xff52, "right": 0xff53, "down": 0xff54}


def press(dpy, keys):
    """Type a chord: the modifiers down, the key, then everything up."""
    codes = [dpy.keysym_to_keycode(KEYSYM[k] if k in KEYSYM else ord(k))
             for k in keys]
    for c in codes:
        xtest.fake_input(dpy, X.KeyPress, c)
        dpy.sync()
        time.sleep(0.05)
    for c in reversed(codes):
        xtest.fake_input(dpy, X.KeyRelease, c)
        dpy.sync()
        time.sleep(0.05)


def click(dpy, x, y):
    xtest.fake_input(dpy, X.MotionNotify, x=x, y=y)
    dpy.sync()
    time.sleep(0.1)
    xtest.fake_input(dpy, X.ButtonPress, X.Button1)
    dpy.sync()
    time.sleep(0.1)
    xtest.fake_input(dpy, X.ButtonRelease, X.Button1)
    dpy.sync()
    time.sleep(0.1)


# --- one picture, one pair of processes

# The part of the window the model is drawn in, per interface: left of it is
# the modules panel, above it the menu bar, below it the status bar.
# The margins keep out the two things Gmsh draws in black inside the graphic
# area itself: the status message across the top, and the axis triad in the
# bottom right corner. Either would be more conspicuous than the model.
SCENE_BOX = {"released": (210, 95, 130, 110), "fltk": (210, 95, 130, 110),
             "imgui": (250, 110, 130, 300),
             # the page hands over a picture of the scene and nothing else, so
             # there is nothing to keep away from but its own edge
             "browser": (10, 10, 10, 10)}


def find_target(picture, build, avoid=None):
    """Where to click to pick something: the most conspicuous thing drawn.

    Gmsh draws points black and curves blue, both against a pale gradient, so
    the pixel with the least red and green in it is on the geometry. Hunting
    for it beats hard-coding a coordinate, which would depend on the model, on
    the interface and on the size of the window.

    `avoid` is a rectangle to keep away from: in the Dear ImGui interface the
    dialog floats over the scene, and its black text is far more conspicuous
    than any blue curve behind it.
    """
    left, top, right, bottom = SCENE_BOX[build]
    px = picture.load()
    best = None
    for y in range(top, picture.height - bottom, 2):
        for x in range(left, picture.width - right, 2):
            if avoid and avoid[0] <= x <= avoid[2] and avoid[1] <= y <= avoid[3]:
                continue
            r, g, b = px[x, y]
            if best is None or r + g < best[0]: best = (r + g, x, y)
    return (best[1], best[2]) if best else None


# which interface the driver is to put up, set once from --build
BUILD = ""


def start_driver(libdir, home, opened, geo=None, context=None):
    env = dict(os.environ)
    env["HOME"] = home
    # fltk 1.4 and GLFW both prefer Wayland when they can have it, and would
    # then open on the session of whoever runs this instead of on the private
    # server -- which is the whole point of the private server
    env.pop("WAYLAND_DISPLAY", None)
    env["FLTK_BACKEND"] = "x11"
    env["GMSH_GUI_PLATFORM"] = "x11"
    # which interface, for a build that holds more than one; a build that
    # holds only this one pays it no mind
    if BUILD:
        env["GMSH_GUI"] = BUILD
    if libdir:
        env["GMSH_LIB_DIR"] = libdir
    env["GMSH_SHOT_PLAN"] = json.dumps(
        dict(close=CLOSE_ORDER, open=opened, width=WIDTH, height=HEIGHT,
             geo=geo, context=context))
    return subprocess.Popen([sys.executable, os.path.join(HERE, "drive.py")],
                            env=env, stdout=subprocess.DEVNULL,
                            stderr=subprocess.PIPE)


def stop_driver(proc):
    proc.terminate()
    try:
        proc.wait(timeout=10)
    except subprocess.TimeoutExpired:
        proc.kill()
        proc.wait()


def grab_window(dpy, win, x, y):
    """Photograph a whole window off the screen itself.

    A window of its own that Dear ImGui gives a dialog is an OpenGL drawable
    whose front buffer the X server will not hand back; what the screen shows
    of it, it will.
    """
    try:
        g = win.get_geometry()
        root = dpy.screen().root
        # a rectangle that runs off the screen is refused, and a window wider
        # than the screen is worth seeing anyway, cut off or not
        w = min(g.width, dpy.screen().width_in_pixels - x)
        h = min(g.height, dpy.screen().height_in_pixels - y)
        raw = root.get_image(x, y, w, h, X.ZPixmap, 0xffffffff).data
        if isinstance(raw, str):
            raw = raw.encode("latin-1")
        return Image.frombytes("RGB", (w, h), bytes(raw), "raw", "BGRX")
    except Exception:
        return None


def detached(dpy, dialog, main):
    """The window of its own Dear ImGui gives a dialog too large to fit inside
    the application window, if there is one."""
    want = re.compile(dialog_title(dialog))
    for name, w, x, y, dw, dh in named_windows(dpy):
        if main is not None and w.id == main.id:
            continue
        if not want.search(name):
            continue
        # only one that can be photographed: a window still being mapped, or
        # the frame a window manager wraps it in, cannot
        try:
            if w.get_attributes().map_state != X.IsViewable:
                continue
        except Exception:
            continue
        return (name, w, x, y, dw, dh)
    return None


# where the tabs of a dialog sit, read off the picture rather than written
# down: a tab moves as soon as a label changes, and there are 25 of them here
def _tabs_at(im, px, build, y):
    """Where each tab of the strip drawn at that height starts and ends, if
    there is a strip there at all."""
    if build == "imgui":
        # a tab is drawn in one of two colours, selected or not, with the
        # window background showing between them
        selected, plain = (152, 186, 225), (198, 206, 215)
        runs, start = [], None
        for x in range(im.width):
            on = px[x, y] in (selected, plain)
            if on and start is None: start = x
            if not on and start is not None:
                if x - start >= 16: runs.append((start, x - 1))
                start = None
        return runs
    # FLTK draws a dark line between two tabs
    grey, line = (192, 192, 192), (83, 83, 83)
    cuts = [x for x in range(im.width) if px[x, y] == line]
    cuts = [x for x in cuts if x > 20]
    if not cuts: return []
    # the strip starts where its grey does, left of the first line
    left = cuts[0]
    while left > 0 and px[left - 1, y] == grey: left -= 1
    out, previous = [], left
    for x in cuts:
        if x - previous >= 16: out.append((previous, x))
        previous = x
    if not out and im.width - left >= 16:
        # a lone tab has no line beside it
        right = left
        while right + 1 < im.width and px[right + 1, y] == grey: right += 1
        out.append((left, min(right, left + 120)))
    return out


def tab_boundaries(img, build, want=0):
    """The middle of each tab of the strip, and how high up the strip is.

    Read off the picture rather than written down: a tab moves as soon as a
    label changes, the option window has twenty-five of them, and a dialog
    that says what its panes are about above them -- the plugins, the size
    fields -- has its strip further down than one that does not. `want` is how
    many tabs the caller is expecting, which is what tells a strip from a row
    of something else that happens to be striped.
    """
    im = img.convert("RGB")
    px = im.load()
    # what the caller wants is where to click, which is a few pixels under the
    # row that tells one tab from the next
    below = TAB_ROW[build] - TAB_SCAN[build]
    first = TAB_SCAN[build]
    # Where the strip usually is, and further down for a dialog that says what
    # its panes are about above them -- the plugins, the size fields.
    #
    # Counting is not enough to tell a strip from something else that happens
    # to be striped: the tops of two list boxes are two dark lines and look
    # like two tabs. A strip is also made of wide pieces that follow one
    # another, so the row whose pieces cover the most, none of them narrow,
    # is the one. The usual row wins a tie, which is what keeps a dialog with
    # a single tab -- the Solver options -- where it has always been.
    rows = [first] + [y for y in range(4, min(im.height, 160), 2) if y != first]
    best, most = None, None
    for y in rows:
        runs = _tabs_at(im, px, build, y)
        if not runs: continue
        if want and len(runs) != want: continue
        if min(b - a for a, b in runs) < 20: continue
        span = sum(b - a for a, b in runs)
        if most is None or span > most:
            most, best = span, (runs, y)
    if best is None:
        runs = _tabs_at(im, px, build, first)
        return [(a + b) // 2 for a, b in runs], first + below
    return [(a + b) // 2 for a, b in best[0]], best[1] + below


# The categories of the option window, and the tabs each of them has, as the
# window this reproduces has them. Only the names are written here: where a tab
# is, is read off the picture.
OPTION_TABS = [
    ("General", ["General", "Advanced", "Axes", "Aspect", "Color", "Camera"]),
    ("Geometry", ["General", "Visibility", "Transfo", "Aspect", "Color"]),
    ("Mesh", ["General", "Advanced", "Visibility", "Aspect", "Color"]),
    ("Solver", ["General"]),
    ("Post", ["General"]),
    # the last category exists only when a view is loaded, which is why the
    # sweep opens one; there is a line per view, and one view is enough
    ("View", ["General", "Axes", "Visibility", "Transfo", "Aspect", "Color",
              "Map"]),
]

# Where the rows of the list of categories are, per interface: the first one
# and the step from one to the next. Measured off a picture, like the rows of
# the modules tree -- FLTK 1.4 gives a browser taller rows than 1.3, so the
# same numbers cannot serve both, and clicking a row and a half off lands on
# the wrong category without saying so.
CATEGORY_ROWS = {"released": (10, 13.7), "fltk": (10, 15.3),
                 "imgui": (33, 17)}


def _points(spec, build):
    """Where a shot clicks inside the dialog before it is taken: one place, or
    several in the order they are to be clicked -- the size-field window wants
    a field picked before its help means anything."""
    point = spec.get("press", {}).get(build)
    if not point:
        return []
    return point if isinstance(point[0], (list, tuple)) else [point]


def press_inside(dpy, build, point, dialog, wx, wy):
    """Click a point of the dialog itself. In Dear ImGui the dialog sits at a
    known place inside the one window; in FLTK it is a window of its own and
    the X server says where it is."""
    if build == "imgui":
        apart = detached(dpy, dialog, None)
        if apart:
            click(dpy, apart[2] + point[0], apart[3] + point[1])
            return True
        click(dpy, wx + DIALOG_POS[0] + point[0], wy + DIALOG_POS[1] + point[1])
        return True
    found = wait_for(dpy, lambda n: re.search(dialog_title(dialog), n),
                     seconds=8)
    if not found:
        return False
    click(dpy, found[2] + point[0], found[3] + point[1])
    return True



# The keys of the colour map editor, and what pressing them is supposed to do.
# Photographing the tab shows what the map looks like at rest, which says
# nothing about whether the keys still work -- and this interface once
# advertised eight of them in its help without having any. So the map is
# photographed a second time, after being pressed on: swapped, rotated twice,
# bent three times and brightened twice. What each key does is not checked
# here; that the three builds end up with the same picture is.
COLORMAP_KEYS = [["i"], ["ctrl", "left"], ["ctrl", "left"], ["up"], ["up"],
                 ["up"], ["b"], ["b"]]


def _colormap_keys(dpy, build, win, ww, wh, dx, dy, dw, dh):
    """Press them, on the map that is showing, and photograph what is left."""
    # the middle of the pane, which is the map itself: FLTK gives its widget
    # the keyboard when the pointer enters it, so the pointer has to be there
    x, y = dx + dw // 2, dy + dh // 2
    xtest.fake_input(dpy, X.MotionNotify, x=x, y=y)
    dpy.sync()
    time.sleep(0.3)
    for chord in COLORMAP_KEYS:
        press(dpy, chord)
        time.sleep(0.15)
    time.sleep(0.5)
    wiggle(dpy, x, y)
    time.sleep(0.3)
    return _dialog_picture(dpy, "options", build, win, ww, wh)

def sweep_options(dpy, build, out, win, wx, wy, ww, wh, only=None):
    """Photograph every tab of every category of the option window.

    One picture per tab is more than one can look at, but not more than one can
    compare: what this is for is telling whether the two interfaces still show
    the same thing as the window they reproduce.
    """
    failures = []
    first, step = CATEGORY_ROWS[build]
    for k, (category, tabs) in enumerate(OPTION_TABS):
        if only and not only.startswith(category.lower()):
            continue
        where = _dialog_geometry(dpy, "options", build, win, wx, wy)
        if not where:
            failures.append("options: no window to sweep")
            return failures
        dx, dy, dw, dh = where
        click(dpy, dx + 45, dy + int(round(first + k * step)))
        time.sleep(0.6)
        picture = _dialog_picture(dpy, "options", build, win, ww, wh)
        if picture is None:
            failures.append("options-%s: nothing to photograph" % category)
            continue
        found, tabRow = tab_boundaries(picture, build, len(tabs))
        if len(found) != len(tabs):
            print("NOTE %s %s: %d tabs seen, %d expected"
                  % (build, category, len(found), len(tabs)))
            picture.save(os.path.join(
                out, "%s-options-%s-STRIP.png" % (build, category.lower())))
        for i, x in enumerate(found):
            name = tabs[i] if i < len(tabs) else "tab%d" % (i + 1)
            # a category on its own means every tab of it
            if only and "-" in only and \
               only != "%s-%s" % (category.lower(), name.lower()):
                continue
            where = _dialog_geometry(dpy, "options", build, win, wx, wy)
            if not where: break
            dx, dy = where[0], where[1]
            click(dpy, dx + x, dy + tabRow)
            time.sleep(0.4)
            shot = _dialog_picture(dpy, "options", build, win, ww, wh)
            if shot is None:
                failures.append("options-%s-%s: nothing to photograph"
                                % (category, name))
                continue
            f = "%s-options-%s-%s.png" % (build, category.lower(), name.lower())
            shot.save(os.path.join(out, f))
            print("SHOT %s  %dx%d" % (f, shot.width, shot.height))
            if name == "Map":
                # a dialog that is a window of Dear ImGui rather than one of
                # its own has no size to give, and _dialog_geometry says zero;
                # the picture that has just been taken is that size
                dw = where[2] or shot.width
                dh = where[3] or shot.height
                second = _colormap_keys(dpy, build, win, ww, wh, dx, dy,
                                        dw, dh)
                if second is None:
                    failures.append("options-view-map-keys: nothing to "
                                    "photograph")
                    continue
                f = "%s-options-view-map-keys.png" % build
                second.save(os.path.join(out, f))
                print("SHOT %s  %dx%d" % (f, second.width, second.height))
    return failures


def browser_sweep(dpy, args, port, win, only=None):
    """Every tab of every category of the option window, over the socket.

    The page is not clicked at a measured row: the category is picked by its
    name in the list the window puts down its side, and the tab by its name.
    That is the whole difference between this and the one above.
    """
    failures = []
    for category, tabs in OPTION_TABS:
        if only and not only.startswith(category.lower()):
            continue
        browser_quiet(port)
        state = browser_state(port) or {}
        item = browser_menu(state, browser_shortcut(["ctrl", "shift", "n"]))
        if not item:
            failures.append("options: no way to open the window")
            return failures
        browser_ask(port, "/do", which(item), timeout=3)
        time.sleep(0.6)
        form = browser_form(browser_state(port) or {}, "options")
        # the categories are named as the window names them, which is not
        # always how the bench calls them
        said = {"post": "Post-pro", "view": "View ["}
        want = said.get(category.lower(), category)
        if not browser_press(port, form, want):
            lists = [f for f in form.get("side", []) if f.get("kind") == "list"]
            at = None
            for f in lists:
                for i, label in enumerate(f.get("items", [])):
                    if label.startswith(want): at = (f, i)
            if not at:
                failures.append("options-%s: no such category" % category)
                continue
            browser_ask(port, "/choose", which(at[0]) + "&i=%d&v=1" % at[1],
                        timeout=3)
        time.sleep(0.8)
        form = browser_form(browser_state(port) or {}, "options")
        if form is None:
            failures.append("options-%s: the window went away" % category)
            continue
        for name in tabs:
            if only and "-" in only and \
               only != "%s-%s" % (category.lower(), name.lower()):
                continue
            if not browser_pane(port, form, name.lower()):
                failures.append("options-%s-%s: no such tab" % (category, name))
                continue
            time.sleep(0.5)
            rect = browser_rect(port, form["id"])
            shot = browser_cut(dpy, win, rect) if rect else None
            if shot is None:
                failures.append("options-%s-%s: nothing to photograph"
                                % (category, name))
                continue
            f = "%s-options-%s-%s.png" % (args.build, category.lower(),
                                          name.lower())
            shot.save(os.path.join(args.out, f))
            print("SHOT %s  %dx%d" % (f, shot.width, shot.height))
    return failures


def _dialog_geometry(dpy, dialog, build, win, wx, wy):
    """Where the dialog is on the screen, whichever kind of window it is."""
    if build == "imgui":
        apart = detached(dpy, dialog, win)
        if apart:
            return (apart[2], apart[3], apart[4], apart[5])
        return (wx + DIALOG_POS[0], wy + DIALOG_POS[1], 0, 0)
    found = wait_for(dpy, lambda n: re.search(dialog_title(dialog), n),
                     seconds=4)
    if not found:
        return None
    return (found[2], found[3], found[4], found[5])


def _dialog_picture(dpy, dialog, build, win, ww, wh):
    if build == "imgui":
        apart = detached(dpy, dialog, win)
        if apart:
            return grab_window(dpy, apart[1], apart[2], apart[3])
        after = grab(dpy, win, ww, wh)
        box = imgui_box(after, DIALOG_POS)
        return after.crop(box) if box else None
    found = wait_for(dpy, lambda n: re.search(dialog_title(dialog), n),
                     seconds=4)
    if not found:
        return None
    return grab(dpy, found[1], found[4], found[5])


# --- the interface that is a page in a browser
#
# There are no windows to find here. What the X server holds is one browser
# window, and every dialog is inside the page; so nothing below is clicked at a
# measured coordinate. The page is driven the way anything outside it would
# drive it -- over the socket it answers on -- and it says back where it put
# each window, which is what is cut out of the picture.
#
# What the page cannot do yet it does not pretend to: there is no file chooser
# and no popped-up menu, so those shots come out blank and the sheet says so.

BROWSER_PORT = 8130
# The word every request has to carry, so that no page anyone visits can drive
# a Gmsh listening on this machine. Gmsh makes one up when nothing says which;
# here it is said, so that both sides of the bench know it.
BROWSER_TOKEN = "guicompare"


def keyed_url(path):
    return "http://127.0.0.1:%d%s%sk=%s" % (
        BROWSER_PORT, path, "&" if "?" in path else "?", BROWSER_TOKEN)
# the browser window, which holds the tree, the scene and the dialogs at once,
# so it is larger than the 900x700 the other interfaces are photographed at
PAGE = (1500, 1000)


def browser_ask(port, path, body=None, timeout=6):
    """Ask the page's server something. A tool that picks does not answer
    until something has been picked, so a request that times out is not a
    failure -- it is the interface waiting, as it would for a click."""
    url = "http://127.0.0.1:%d%s%sk=%s" % (port, path, "&" if "?" in path
                                           else "?", BROWSER_TOKEN)
    data = (body + "&k=" + BROWSER_TOKEN).encode() if body is not None else None
    try:
        with urllib.request.urlopen(url, data, timeout=timeout) as r:
            return r.read().decode("utf-8", "replace")
    except Exception:
        return ""


def which(item):
    """A number the page was given, with what it stood for. Gmsh refuses one
    that no longer stands for the same thing rather than doing it to whatever
    has taken its place."""
    return "id=%d&h=%d" % (item["id"], item["h"])


def browser_state(port):
    said = browser_ask(port, "/state", "")
    try:
        return json.loads(said)
    except Exception:
        return None


def browser_wait(port, seconds=40):
    end = time.time() + seconds
    while time.time() < end:
        if browser_state(port):
            return True
        time.sleep(0.3)
    return False


def browser_where(port):
    """Where the page says it has put things, as name -> (x, y, w, h)."""
    out = {}
    for part in browser_ask(port, "/where").split("&"):
        if "=" not in part:
            continue
        name, said = part.split("=", 1)
        try:
            x, y, w, h = (int(v) for v in said.split(","))
        except ValueError:
            continue
        out[name] = (x, y, w, h)
    return out


def start_browser(home, port):
    profile = os.path.join(home, "chrome")
    env = dict(os.environ)
    env.pop("WAYLAND_DISPLAY", None)
    return subprocess.Popen(
        [BROWSER, "--ozone-platform=x11",
         "--app=" + keyed_url("/"),
         "--user-data-dir=" + profile,
         "--no-first-run", "--no-default-browser-check",
         "--disable-session-crashed-bubble", "--disable-background-networking",
         "--disable-component-update", "--disable-sync", "--disable-gpu",
         "--window-position=0,0", "--window-size=%d,%d" % PAGE],
        env=env, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)


BROWSER = (shutil.which("chromium") or shutil.which("chromium-browser") or
           shutil.which("google-chrome-stable") or shutil.which("google-chrome"))


def browser_window(dpy, seconds=30):
    """The one window the browser has, which is the whole page."""
    end = time.time() + seconds
    while time.time() < end:
        for win in dpy.screen().root.query_tree().children:
            try:
                g = win.get_geometry()
            except Exception:
                continue
            if g.width == PAGE[0] and g.height == PAGE[1]:
                return win
        time.sleep(0.3)
    return None


def browser_quiet(port):
    """Put the page back as it was: every window closed and no tool running.

    Waited for rather than asked once: a tool that is still starting has not
    reached the point where 'q' means anything to it, and the next shot would
    then open its dialog into whatever was left over.
    """
    for _ in range(8):
        state = browser_state(port) or {}
        forms = state.get("forms", [])
        if not forms:
            return True
        # "j", not "k": "k" is the word that says a request may be asked
        browser_ask(port, "/key", "j=q", timeout=3)
        for form in forms:
            browser_ask(port, "/close", "form=%d" % form["id"], timeout=3)
        time.sleep(0.3)
    return False


def browser_menu(state, want):
    """A menu entry, by the keys it says or by the labels leading to it."""
    def walk(items, path):
        for item in items:
            here = path + [item.get("label", "")]
            yield here, item
            for child in item.get("children") or []:
                yield from walk([child], here)
    for path, item in walk(state.get("menus", []), []):
        if "id" not in item:
            continue
        if isinstance(want, str):
            if item.get("key", "") == want:
                return item
        elif [p.lower() for p in path[-len(want):]] == \
             [w.lower() for w in want]:
            return item
    return None


def browser_shortcut(keys):
    """The keys a shot presses, written the way a menu says them."""
    said = {"ctrl": "Ctrl", "shift": "Shift", "alt": "Alt"}
    return "+".join(said.get(k, k.upper()) for k in keys)


def browser_pane(port, form, want):
    """Pick the pane whose label the shot names, by name and not by pixel."""
    def like(label):
        flat = label.lower().replace(" ", "-")
        return flat == want or flat.startswith(want) or want.startswith(flat)
    for i, tab in enumerate(form.get("tabs", [])):
        if like(tab.get("label", "")):
            browser_ask(port, "/pane", "form=%d&i=%d" % (form["id"], i),
                        timeout=3)
            return True
    return False


def browser_press(port, form, want):
    """Press a button, or turn on a check, by the name the description gives
    it. What the other interfaces do by clicking a measured point."""
    def every(pane):
        yield from pane.get("fields", [])
        for section in pane.get("sections", []):
            yield from section.get("fields", [])
        yield from pane.get("beside", [])
    fields = list(form.get("header", [])) + list(form.get("footer", [])) + \
             list(form.get("side", []))
    for pane in form.get("panes", []):
        fields += list(every(pane))
    for f in fields:
        if f.get("label") != want:
            continue
        if f.get("kind") == "action":
            browser_ask(port, "/do", which(f), timeout=3)
        else:
            browser_ask(port, "/set", which(f) + "&v=1", timeout=3)
        return True
    # or a line of a list. "list:2" is the third line of the first list there
    # is, which is what a shot means by clicking a row of a browser: the names
    # in it come from the model and are not worth writing down.
    lists = [f for f in fields if f.get("kind") == "list"]
    if want.startswith("list:") and lists:
        at = int(want[5:])
        if at < len(lists[0].get("items", [])):
            browser_ask(port, "/choose", which(lists[0]) + "&i=%d&v=1" % at,
                        timeout=3)
            return True
        return False
    for f in lists:
        for i, item in enumerate(f.get("items", [])):
            if item == want:
                browser_ask(port, "/choose", which(f) + "&i=%d&v=1" % i,
                            timeout=3)
                return True
    return False


def browser_form(state, dialog):
    want = re.compile(dialog_title(dialog))
    for form in state.get("forms", []):
        if want.search(form.get("title", "")):
            return form
    return None


def browser_rect(port, form, seconds=3.0):
    """Where the page has put that window, waited for rather than assumed:
    Gmsh tells the page what to show and the page says back where it put it,
    so there are two hops between opening a window and being able to cut it
    out of a picture."""
    want = "form%d" % form
    end = time.time() + seconds
    while time.time() < end:
        rect = browser_where(port).get(want)
        if rect and rect[2] > 4 and rect[3] > 4:
            return rect
        time.sleep(0.1)
    return None


def browser_cut(dpy, win, rect):
    picture = grab_window(dpy, dpy.screen().root, 0, 0)
    if picture is None:
        return None
    x, y, w, h = rect
    x, y = max(0, x), max(0, y)
    w = min(w, picture.width - x)
    h = min(h, picture.height - y)
    if w < 4 or h < 4:
        return None
    return picture.crop((x, y, x + w, y + h))


def photograph_browser(dpy, args, specs):
    """Take every shot of the list against the page in a browser."""
    if not BROWSER:
        return ["no browser installed to photograph the page with"]
    failures = []

    def missing(why):
        print("MISS " + why)
        failures.append(why)

    port = BROWSER_PORT
    chrome = None
    held = None
    try:
        for spec in specs:
            name = spec["name"]
            key = (spec["dialog"], spec.get("geo"), tuple(spec["branches"]),
                   name if spec.get("scene") or spec.get("keys")
                   or spec.get("menu") or spec.get("context") else "")
            reused = True
            if held and held[0] != key:
                stop_driver(held[1])
                held = None
            if not held:
                # the driver inherits the environment, which is how it is told
                # which port to answer on
                old = os.environ.get("GMSH_BROWSER_PORT")
                os.environ["GMSH_BROWSER_PORT"] = str(port)
                os.environ["GMSH_BROWSER_TOKEN"] = BROWSER_TOKEN
                proc = start_driver(args.lib, args.home, spec["branches"],
                                    spec.get("geo"), spec.get("context"))
                if old is None:
                    os.environ.pop("GMSH_BROWSER_PORT")
                else:
                    os.environ["GMSH_BROWSER_PORT"] = old
                if not browser_wait(port):
                    err = proc.stderr.read().decode(errors="replace")[-400:]
                    missing("%s: the page never answered. %s"
                                    % (name, err))
                    stop_driver(proc)
                    continue
                if chrome is None:
                    chrome = start_browser(args.home, port)
                reused = False
                held = (key, proc, browser_window(dpy))
                if held[2] is None:
                    missing("%s: no browser window" % name)
                    stop_driver(proc)
                    held = None
                    continue
                time.sleep(1.5)
            win = held[2]
            # Only what the shot before left behind: a window that was up
            # before anything was clicked is what this shot came for -- the
            # per-entity ONELAB window is opened by the driver itself.
            if reused:
                browser_quiet(port)
                time.sleep(0.4)

            # what opens the dialog: an entry of the menu bar, a line of the
            # tree, or nothing at all when it is already up
            if spec.get("context"):
                pass
            elif spec.get("keys"):
                state = browser_state(port) or {}
                item = browser_menu(state, browser_shortcut(spec["keys"]))
                if not item:
                    missing("%s: no menu entry for %s"
                                    % (name, browser_shortcut(spec["keys"])))
                    continue
                browser_ask(port, "/do", which(item), timeout=3)
            elif spec.get("menuPath"):
                state = browser_state(port) or {}
                item = browser_menu(state, spec["menuPath"])
                if not item:
                    missing("%s: no menu entry %s"
                                    % (name, spec["menuPath"]))
                    continue
                browser_ask(port, "/do", which(item), timeout=3)
            elif spec.get("barButton") is not None:
                # A menu dropped by a button of the status bar. The page says
                # where it put that button, and it is pressed the way anyone
                # would press it -- a menu lives in the page and cannot be
                # opened over the socket.
                at = browser_where(port).get("bar%d" % spec["barButton"])
                if not at:
                    missing("%s: the page never said where its buttons are"
                            % name)
                    continue
                click(dpy, at[0] + at[2] // 2, at[1] + at[3] // 2)
                time.sleep(0.8)
            elif spec.get("menu"):
                print("NOTE browser %s: the page has no menu to pop up" % name)
                continue
            elif spec.get("whole"):
                pass
            else:
                state = browser_state(port) or {}
                tree = state.get("tree", [])
                row = spec["row"]
                if row >= len(tree) or "id" not in tree[row]:
                    missing("%s: no tree line %d of %d"
                                    % (name, row, len(tree)))
                    continue
                browser_ask(port, "/do", which(tree[row]), timeout=3)
            time.sleep(0.8)

            if spec.get("whole"):
                out = "%s-%s.png" % (args.build, name)
                picture = browser_cut(dpy, win, (0, 0) + PAGE)
                if picture is None:
                    missing("%s: nothing to photograph" % name)
                    continue
                picture.save(os.path.join(args.out, out))
                print("SHOT %s  %dx%d" % (out, picture.width, picture.height))
                continue

            # The window that is acted on is not always the one the shot is
            # of: the arrow editor is opened by a button of the option window.
            acting = spec.get("pressIn", spec["dialog"])
            state = browser_state(port) or {}
            form = browser_form(state, acting)
            if form is None:
                missing("%s: no window titled %r; up: %s"
                                % (name, dialog_title(acting),
                                   [f["title"] for f in state.get("forms", [])]))
                continue

            # what to pick in the scene, now that the dialog is up
            for _ in spec.get("scene", []):
                shot = browser_scene(port, args.home)
                target = find_target(shot, "browser") if shot else None
                if not target:
                    missing("%s: nothing drawn to pick" % name)
                    break
                where = browser_where(port).get("scene")
                if not where:
                    missing("%s: the page never said where the scene is"
                                    % name)
                    break
                print("PICK %s at %d,%d" % (name, target[0], target[1]))
                for what in (1, 2):
                    browser_ask(port, "/pointer",
                                "x=%d&y=%d&b=0&w=%d&d=0&s=0&c=0&a=0"
                                % (target[0], target[1], what), timeout=3)
                time.sleep(0.6)

            if spec.get("paneName"):
                if not browser_pane(port, form, spec["paneName"]):
                    missing("%s: no tab called %r"
                            % (name, spec["paneName"]))
                    continue
                time.sleep(0.6)
                form = browser_form(browser_state(port) or {}, acting)
                if form is None:
                    missing("%s: the window went away with its tab" % name)
                    continue
            missed = False
            for want in spec.get("pressName", []):
                if not browser_press(port, form, want):
                    missing("%s: no field called %r to press"
                                    % (name, want))
                    missed = True
                    break
                time.sleep(0.8)
                form = browser_form(browser_state(port) or {}, acting)
                if form is None:
                    missing("%s: the window went away when %r was "
                                    "pressed" % (name, want))
                    missed = True
                    break
            if missed:
                continue
            if spec.get("press") and not spec.get("pressName"):
                print("NOTE browser %s: what to press is given as a point in "
                      "each interface, and the page has no such point" % name)
                continue
            # and now the window the shot is really of
            if acting != spec["dialog"]:
                state = browser_state(port) or {}
                form = browser_form(state, spec["dialog"])
                if form is None:
                    missing("%s: no window titled %r; up: %s"
                            % (name, dialog_title(spec["dialog"]),
                               [f["title"] for f in state.get("forms", [])]))
                    continue

            names = []
            if spec.get("everyTab"):
                names = (spec["everyTab"].get("browser")
                         or spec["everyTab"].get("fltk", []))
            elif spec.get("tab"):
                names = [name.split("-")[-1]]
            if names:
                for want in names:
                    if not browser_pane(port, form, want):
                        missing("%s: no tab like %r in %s"
                                        % (name, want, form.get("tabs")))
                        continue
                    time.sleep(0.6)
                    out = ("%s-%s.png" % (args.build, name)
                           if spec.get("tab")
                           else "%s-%s-%s.png" % (args.build, name, want))
                    rect = browser_rect(port, form["id"])
                    picture = browser_cut(dpy, win, rect) if rect else None
                    if picture is None:
                        missing("%s: the page never said where %s is"
                                        % (name, out))
                        continue
                    picture.save(os.path.join(args.out, out))
                    print("SHOT %s  %dx%d" % (out, picture.width,
                                              picture.height))
                continue

            out = "%s-%s.png" % (args.build, name)
            rect = browser_rect(port, form["id"])
            picture = browser_cut(dpy, win, rect) if rect else None
            if picture is None:
                missing("%s: the page never said where its window is"
                                % name)
                continue
            picture.save(os.path.join(args.out, out))
            print("SHOT %s  %dx%d" % (out, picture.width, picture.height))
    finally:
        if held:
            stop_driver(held[1])
        if chrome:
            chrome.terminate()
            try:
                chrome.wait(timeout=10)
            except subprocess.TimeoutExpired:
                chrome.kill()
    return failures


def browser_scene(port, home):
    """The 3D view as the page has it, to look for something to pick in."""
    said = None
    # "force": a picture only comes back when the scene has changed since the
    # last one, and what this wants is the picture, not the news
    try:
        with urllib.request.urlopen(keyed_url("/scene?force"), timeout=20) as r:
            said = r.read()
    except Exception:
        return None
    if not said:
        return None
    path = os.path.join(home, "scene.bmp")
    with open(path, "wb") as f:
        f.write(said)
    try:
        return Image.open(path).convert("RGB")
    except Exception:
        return None


def photograph(dpy, args, specs):
    """Take every shot of the list, in an X server that is already up.

    Returns what it could not take. A shot misses now and then -- a window that
    is a moment late, a click that lands as the tree is still drawing -- and
    the caller gives those another go rather than leaving a hole in the sheet.
    """
    failures = []
    # One interface for as many shots as it can take. Starting Gmsh is
    # most of what a shot costs, and shots that want the same model, the
    # same unfolded branches and the same dialog want the same interface:
    # the twelve shapes of the elementary dialog are twelve panes of one
    # window. A shot that clicks in the scene keeps one to itself -- what
    # it picks is added to the model, and the next shot would not find the
    # model it asked for.
    held = None  # what is up: its key, its process, where its window is
    for spec in specs:
        name = spec["name"]
        # a pane the conversion added: the released build has no window for
        # it, so there is nothing to photograph there
        if spec.get("added") and args.build == "released":
            continue
        # A shot that types the accelerator of a window keeps an interface to
        # itself. The menu entry is a toggle -- it says with a check mark
        # whether the window is up -- so typing the chord a second time in the
        # same interface would close the window the shot came to photograph.
        key = (spec["dialog"], spec.get("geo"), tuple(spec["branches"]),
               name if spec.get("scene") or spec.get("keys")
               or spec.get("menu") or spec.get("context") else "")
        if held and held[0] != key:
            stop_driver(held[1])
            held = None
        if not held:
            proc = start_driver(args.lib, args.home, spec["branches"],
                                spec.get("geo"), spec.get("context"))
            main_win = wait_for(dpy, lambda n: "Gmsh" in n)
            if not main_win:
                err = proc.stderr.read().decode(errors="replace")[-400:]
                failures.append("%s: no main window. %s" % (name, err))
                stop_driver(proc)
                continue
            held = (key, proc, main_win)
            time.sleep(1.0)
        _, win, wx, wy, ww, wh = held[2]

        # a shot of the whole window needs nothing opened first, but takes its
        # picture the same way
        if spec.get("keys") or spec.get("menu") or spec.get("context") or \
           spec.get("whole"):
            # the pointer has to be over the window for the key to
            # reach it
            xtest.fake_input(dpy, X.MotionNotify, x=wx + 120,
                             y=wy + wh - 60)
            dpy.sync()
            time.sleep(0.3)
            if spec.get("context") or (spec.get("whole") and
                                       not spec.get("menu")):
                # nothing to open: it is already there
                pass
            elif spec.get("keys"):
                press(dpy, spec["keys"])
            else:
                # through the menu bar: one click to open the menu, one on the
                # entry, both given for this interface
                for mx, my in spec["menu"].get(args.build, []):
                    click(dpy, wx + mx, wy + my)
                    time.sleep(0.5)
            time.sleep(0.6)
            wiggle(dpy, wx + 120, wy + wh - 60)
            time.sleep(0.6)

            if spec.get("everyTab"):
                # one picture per tab, whichever interface this is
                names = spec["everyTab"].get(args.build, [])
                # Where the tabs are is read off the picture, which is what
                # keeps this working as labels change. One dialog defeats it:
                # FLTK 1.4 draws the strip of the plugins window right of two
                # list boxes whose borders look exactly like tab separators.
                # For that one the places are measured and written down, the
                # way the menu entries are.
                said = spec.get("tabsAt", {}).get(args.build)
                picture = _dialog_picture(dpy, spec["dialog"], args.build, win,
                                          ww, wh)
                if said:
                    found, tabRow = [x for x, _ in said], said[0][1]
                else:
                    found, tabRow = (tab_boundaries(picture, args.build,
                                                    len(names))
                                     if picture else ([], TAB_ROW[args.build]))
                    if len(found) != len(names):
                        print("NOTE %s %s: %d tabs seen, %d expected"
                              % (args.build, name, len(found), len(names)))
                for i, x in enumerate(found):
                    if i >= len(names): break
                    # not "where": that is the function which says where a row
                    # of the tree is, and assigning it here would shadow it
                    place = _dialog_geometry(dpy, spec["dialog"], args.build,
                                             win, wx, wy)
                    if not place: break
                    click(dpy, place[0] + x, place[1] + tabRow)
                    time.sleep(0.4)
                    shot = _dialog_picture(dpy, spec["dialog"], args.build, win,
                                           ww, wh)
                    if shot is None:
                        failures.append("%s-%s: nothing to photograph"
                                        % (name, names[i]))
                        continue
                    out = "%s-%s-%s.png" % (args.build, name, names[i])
                    shot.save(os.path.join(args.out, out))
                    print("SHOT %s  %dx%d" % (out, shot.width, shot.height))
                continue

            if spec.get("tab"):
                # the dialog is up: pick the tab this shot is about
                tx = spec["tab"][1 if args.build == "imgui" else 0]
                ty = TAB_ROW[args.build]
                if args.build == "imgui":
                    click(dpy, wx + DIALOG_POS[0] + tx,
                          wy + DIALOG_POS[1] + ty)
                else:
                    found = wait_for(
                        dpy,
                        lambda n: re.search(dialog_title(spec["dialog"]), n),
                        seconds=8)
                    if not found:
                        failures.append("%s: no dialog to pick a tab in"
                                        % name)
                        continue
                    click(dpy, found[2] + tx, found[3] + ty)
                time.sleep(0.5)
                wiggle(dpy, wx + 120, wy + wh - 60)
                time.sleep(0.5)

            missed = False
            for point in _points(spec, args.build):
                # the button to press may be in another window than the one
                # the shot is of: the arrow editor is opened from the option
                # window
                if not press_inside(dpy, args.build, point,
                                    spec.get("pressIn", spec["dialog"]),
                                    wx, wy):
                    failures.append("%s: no dialog to press in" % name)
                    missed = True
                    break
                time.sleep(0.5)
                wiggle(dpy, wx + 120, wy + wh - 60)
                time.sleep(0.5)
            if missed: continue

            if spec.get("whole"):
                # A menu that has popped up is not a window anyone can ask the
                # server for by name, and what it is worth comparing against
                # is the window it opened over anyway.
                out = "%s-%s.png" % (args.build, name)
                picture = grab_window(dpy, dpy.screen().root, wx, wy)
                if picture:
                    picture = picture.crop((0, 0, ww, wh))
                    picture.save(os.path.join(args.out, out))
                    print("SHOT %s  %dx%d" % (out, picture.width,
                                              picture.height))
                else:
                    failures.append("%s: nothing to photograph" % name)
                continue

            if args.build == "imgui":
                # Dear ImGui gives a window of its own to a dialog that
                # does not fit inside the application window, and the X
                # server then hands it over by name, as in FLTK
                out = "%s-%s.png" % (args.build, name)
                apart = detached(dpy, spec["dialog"], win)
                if apart:
                    picture = grab_window(dpy, apart[1], apart[2], apart[3])
                    if picture:
                        picture.save(os.path.join(args.out, out))
                        print("SHOT %s  %dx%d" % (out, picture.width,
                                                  picture.height))
                        continue
                after = grab(dpy, win, ww, wh)
                at = spec.get("at", DIALOG_POS)
                box = imgui_box(after, at)
                if not box:
                    failures.append("%s: no dialog at %s" % (name, at))
                    after.save(os.path.join(
                        args.out, "%s-%s-MISS.png" % (args.build, name)))
                    continue
                after.crop(box).save(os.path.join(args.out, out))
                print("SHOT %s  %dx%d" % (out, box[2] - box[0],
                                          box[3] - box[1]))
                continue
            want = re.compile(dialog_title(spec["dialog"]))
            found = wait_for(dpy, lambda n: want.search(n), seconds=8)
            out = "%s-%s.png" % (args.build, name)
            if not found:
                failures.append("%s: nothing titled %r" % (name, want.pattern))
                grab(dpy, win, ww, wh).save(os.path.join(
                    args.out, "%s-%s-MISS.png" % (args.build, name)))
                continue
            _, dwin, _, _, dw, dh = found
            grab(dpy, dwin, dw, dh).save(os.path.join(args.out, out))
            print("SHOT %s  %dx%d" % (out, dw, dh))
            continue

        cx, cy = where(args.build, spec["row"], spec["depth"])
        if args.probe:
            out = "%s-probe-%s.png" % (args.build, name)
            picture = grab(dpy, win, ww, wh)
            mark(picture, cx, cy)
            picture.save(os.path.join(args.out, out))
            print("PROBE %s  click at %d,%d" % (out, cx, cy))
            continue

        click(dpy, wx + cx, wy + cy)
        time.sleep(0.6)
        wiggle(dpy, wx + 120, wy + wh - 60)
        time.sleep(0.6)

        # and what to pick in the view, now that the dialog is up
        for _ in spec.get("scene", []):
            picture = grab(dpy, win, ww, wh)
            if args.build == "imgui":
                # it floats over the scene inside the one window
                avoid = imgui_box(picture, DIALOG_POS)
            else:
                # a window of its own, but it still hides part of the
                # scene, and what it hides comes back black
                avoid = None
                over = wait_for(
                    dpy,
                    lambda n: re.search(dialog_title(spec["dialog"]), n),
                    seconds=2)
                if over:
                    _, _, dx, dy, dw, dh = over
                    avoid = (dx - wx, dy - wy, dx - wx + dw,
                             dy - wy + dh)
            target = find_target(picture, args.build, avoid)
            if not target:
                failures.append("%s: nothing drawn to pick" % name)
                break
            print("PICK %s at %d,%d" % (name, target[0], target[1]))
            click(dpy, wx + target[0], wy + target[1])
            time.sleep(0.5)
            wiggle(dpy, wx + 120, wy + wh - 60)
            time.sleep(0.5)

        missed = False
        for point in _points(spec, args.build):
            if not press_inside(dpy, args.build, point,
                                spec.get("pressIn", spec["dialog"]), wx, wy):
                failures.append("%s: no dialog to press in" % name)
                missed = True
                break
            time.sleep(0.5)
            wiggle(dpy, wx + 120, wy + wh - 60)
            time.sleep(0.5)
        if missed: continue

        out = "%s-%s.png" % (args.build, name)
        if args.build == "imgui":
            apart = detached(dpy, spec["dialog"], win)
            if apart:
                picture = grab_window(dpy, apart[1], apart[2], apart[3])
                if picture:
                    picture.save(os.path.join(args.out, out))
                    print("SHOT %s  %dx%d" % (out, picture.width,
                                              picture.height))
                    continue
            # Here a dialog is a window of Dear ImGui inside the one
            # window of the application, so there is nothing for the X
            # server to hand over. Its position is known -- it was
            # written into the layout file -- so the rectangle is
            # walked out from there.
            after = grab(dpy, win, ww, wh)
            box = imgui_box(after, DIALOG_POS)
            if not box:
                failures.append("%s: no dialog at %s" % (name, DIALOG_POS))
                after.save(os.path.join(args.out,
                                        "%s-%s-MISS.png" % (args.build, name)))
                continue
            after.crop(box).save(os.path.join(args.out, out))
            print("SHOT %s  %dx%d" % (out, box[2] - box[0], box[3] - box[1]))
            continue

        want = re.compile(dialog_title(spec["dialog"]))
        found = wait_for(dpy, lambda n: want.search(n), seconds=8)
        if not found:
            failures.append(
                "%s: nothing titled %r; on screen: %s"
                % (name, want.pattern,
                   sorted(set(e[0] for e in named_windows(dpy)))))
            grab(dpy, win, ww, wh).save(
                os.path.join(args.out, "%s-%s-MISS.png" % (args.build, name)))
            continue
        _, dwin, _, _, dw, dh = found
        grab(dpy, dwin, dw, dh).save(os.path.join(args.out, out))
        print("SHOT %s  %dx%d" % (out, dw, dh))
    if held:
        stop_driver(held[1])
    return failures


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--lib", help="directory holding gmsh.py and libgmsh")
    ap.add_argument("--out", required=True)
    ap.add_argument("--build", required=True,
                    choices=["released", "fltk", "imgui", "browser"])
    ap.add_argument("--home", required=True, help="a HOME of its own")
    ap.add_argument("--display", type=int, default=99)
    ap.add_argument("--probe", action="store_true",
                    help="photograph the tree instead, to read the "
                         "coordinates of the leaves off it")
    ap.add_argument("--sweep-options", action="store_true",
                    help="photograph every tab of every category of the "
                         "option window, in one go")
    ap.add_argument("--only", default=None,
                    help="with --sweep-options, the one tab to photograph, "
                         "as <category>-<tab>: iterating on a single page is "
                         "a great deal quicker than sweeping all of them")
    ap.add_argument("--shot", action="append", default=[],
                    help="a shot or a dialog by name; all of them by default")
    args = ap.parse_args()

    global BUILD
    BUILD = "" if args.build == "released" else args.build
    os.makedirs(args.out, exist_ok=True)
    os.makedirs(args.home, exist_ok=True)
    if args.build == "imgui":
        with open(os.path.join(args.home, ".gmsh-imgui.ini"), "w") as f:
            f.write(IMGUI_INI)
    failures = []

    # the browser window holds the tree, the scene and the dialogs at once,
    # so it wants a larger screen than the 900x700 the others are shot at
    with Xserver(args.display,
                 "1600x1100x24" if args.build == "browser"
                 else "1400x1000x24"):
        dpy = display.Display()
        if args.sweep_options and args.build == "browser":
            port = BROWSER_PORT
            os.environ["GMSH_BROWSER_PORT"] = str(port)
            os.environ["GMSH_BROWSER_TOKEN"] = BROWSER_TOKEN
            proc = start_driver(args.lib, args.home, [], model("view.pos"))
            chrome = None
            try:
                if not browser_wait(port):
                    print("FAIL sweep: the page never answered")
                    return 1
                chrome = start_browser(args.home, port)
                win = browser_window(dpy)
                if win is None:
                    print("FAIL sweep: no browser window")
                    return 1
                time.sleep(1.5)
                for f in browser_sweep(dpy, args, port, win, args.only):
                    print("FAIL " + f)
            finally:
                stop_driver(proc)
                if chrome:
                    chrome.terminate()
                    try: chrome.wait(timeout=10)
                    except subprocess.TimeoutExpired: chrome.kill()
            return 0
        if args.sweep_options:
            # the View category is a view: without one the list stops at
            # Post-processing
            wants_view = not args.only or args.only.startswith("view")
            proc = start_driver(args.lib, args.home, [],
                                model("view.pos") if wants_view else None)
            try:
                main_win = wait_for(dpy, lambda n: "Gmsh" in n)
                if not main_win:
                    print("FAIL sweep: no main window")
                    return 1
                _, win, wx, wy, ww, wh = main_win
                time.sleep(1.0)
                xtest.fake_input(dpy, X.MotionNotify, x=wx + 120,
                                 y=wy + wh - 60)
                dpy.sync()
                time.sleep(0.3)
                press(dpy, ["ctrl", "shift", "n"])
                time.sleep(1.0)
                for f in sweep_options(dpy, args.build, args.out, win, wx, wy,
                                       ww, wh, args.only):
                    print("FAIL " + f)
            finally:
                stop_driver(proc)
            return 0

        wanted = args.shot or [s["name"] for s in SHOTS]
        specs = [s for s in SHOTS
                 if s["name"] in wanted or s["dialog"] in wanted]
        take = photograph_browser if args.build == "browser" else photograph
        failures = take(dpy, args, specs)
        # A shot that missed is taken again, once, on its own interface: they
        # miss one at a time and never twice for the same reason.
        if failures and not args.probe:
            missed = set(f.split(":")[0] for f in failures)
            print("RETRY " + " ".join(sorted(missed)))
            # what the first try left behind: a picture of what was on screen
            # instead of the dialog, which is only of use while it is the
            # latest word on that shot
            for name in missed:
                miss = os.path.join(args.out,
                                    "%s-%s-MISS.png" % (args.build, name))
                if os.path.exists(miss):
                    os.remove(miss)
            again = [s for s in specs if s["name"] in missed]
            failures = take(dpy, args, again)

    for f in failures:
        print("FAIL " + f)
    return 1 if failures else 0


if __name__ == "__main__":
    sys.exit(main())
