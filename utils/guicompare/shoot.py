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
import subprocess
import sys
import time

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


def shot(dialog, pane, branches, row, depth, geo=None, scene=(), added=False,
         press=None):
    """A shot. `geo` is a model to open first, `scene` clicks in the 3D view
    once the dialog is up -- which is how a picking dialog is shown doing
    anything at all, `press` clicks a button of the dialog itself -- which is
    how a folded half of one is opened. A press is given a point per interface,
    since the three do not put the button in the same place."""
    SHOTS.append(dict(name="%s-%s" % (dialog, pane), dialog=dialog,
                      branches=branches, row=row, depth=depth, geo=geo,
                      scene=list(scene), added=added, press=press or {}))


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

# the high order tools and the partitioner, which have no tabs
shot("highorder", "", [M], 12, 2)
shot("partition", "", [M], 14, 2)
# and the same dialog with its advanced half unfolded
shot("partition", "advanced", [M], 14, 2,
     press={"released": (368, 120), "fltk": (398, 104), "imgui": (407, 110)})

# and the ones the Tools menu raises
keyed("manipulator", ["ctrl", "shift", "m"])
keyed("options", ["ctrl", "shift", "n"])
# and the same window on another category, since picking one in the list on the
# left is what changes the tabs on the right
SHOTS.append(dict(name="options-mesh", dialog="options", branches=[],
                  keys=["ctrl", "shift", "n"],
                  press={"released": (45, 37), "fltk": (45, 40),
                         "imgui": (45, 67)}))
keyed("clipping", ["ctrl", "shift", "c"])
# The visibility window, on a model that has something to hide. Every one of
# its tabs is photographed, and where each tab is, is read off the picture --
# the released build has one more of them than the converted ones, so they are
# named per interface.
SHOTS.append(dict(name="visibility", dialog="visibility", branches=[],
                  keys=["ctrl", "shift", "v"], geo=_GEO3,
                  everyTab={"released": ["list", "tree", "numeric",
                                         "interactive", "per-window"],
                            "fltk": ["list", "numeric", "interactive",
                                     "per-window"],
                            "imgui": ["list", "numeric", "interactive",
                                      "per-window"]}))
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
    % (i, DIALOG_POS[0], DIALOG_POS[1]) for i in range(12))


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


KEYSYM = {"ctrl": 0xffe3, "shift": 0xffe1, "alt": 0xffe9}


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
             "imgui": (250, 110, 130, 300)}


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


def start_driver(libdir, home, opened, geo=None):
    env = dict(os.environ)
    env["HOME"] = home
    # fltk 1.4 and GLFW both prefer Wayland when they can have it, and would
    # then open on the session of whoever runs this instead of on the private
    # server -- which is the whole point of the private server
    env.pop("WAYLAND_DISPLAY", None)
    env["FLTK_BACKEND"] = "x11"
    env["GMSH_GUI_PLATFORM"] = "x11"
    if libdir:
        env["GMSH_LIB_DIR"] = libdir
    env["GMSH_SHOT_PLAN"] = json.dumps(
        dict(close=CLOSE_ORDER, open=opened, width=WIDTH, height=HEIGHT,
             geo=geo))
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
def tab_boundaries(img, build):
    """The x of the middle of each tab of the strip along the top.

    Read off the picture rather than written down: a tab moves as soon as a
    label changes, and the option window has twenty-five of them.
    """
    im = img.convert("RGB")
    px = im.load()
    if build == "imgui":
        # a tab is drawn in one of two colours, selected or not, with the
        # window background showing between them
        y = 30
        selected, plain = (152, 186, 225), (198, 206, 215)
        runs, start = [], None
        for x in range(im.width):
            on = px[x, y] in (selected, plain)
            if on and start is None: start = x
            if not on and start is not None:
                if x - start >= 16: runs.append((start, x - 1))
                start = None
        return [(a + b) // 2 for a, b in runs]
    # FLTK draws a dark line between two tabs
    y = 8
    grey, line = (192, 192, 192), (83, 83, 83)
    cuts = [x for x in range(im.width) if px[x, y] == line]
    cuts = [x for x in cuts if x > 20]
    if not cuts: return []
    # the strip starts where its grey does, left of the first line
    left = cuts[0]
    while left > 0 and px[left - 1, y] == grey: left -= 1
    out, previous = [], left
    for x in cuts:
        if x - previous >= 16: out.append((previous + x) // 2)
        previous = x
    if not out and im.width - left >= 16:
        # a lone tab has no line beside it
        right = left
        while right + 1 < im.width and px[right + 1, y] == grey: right += 1
        out.append((left + min(right, left + 120)) // 2)
    return out


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
        found = tab_boundaries(picture, build)
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
            click(dpy, dx + x, dy + TAB_ROW[build])
            time.sleep(0.4)
            shot = _dialog_picture(dpy, "options", build, win, ww, wh)
            if shot is None:
                failures.append("options-%s-%s: nothing to photograph"
                                % (category, name))
                continue
            f = "%s-options-%s-%s.png" % (build, category.lower(), name.lower())
            shot.save(os.path.join(out, f))
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
        key = (spec["dialog"], spec.get("geo"), tuple(spec["branches"]),
               name if spec.get("scene") else "")
        if held and held[0] != key:
            stop_driver(held[1])
            held = None
        if not held:
            proc = start_driver(args.lib, args.home, spec["branches"],
                                spec.get("geo"))
            main_win = wait_for(dpy, lambda n: "Gmsh" in n)
            if not main_win:
                err = proc.stderr.read().decode(errors="replace")[-400:]
                failures.append("%s: no main window. %s" % (name, err))
                stop_driver(proc)
                continue
            held = (key, proc, main_win)
            time.sleep(1.0)
        _, win, wx, wy, ww, wh = held[2]

        if spec.get("keys"):
            # the pointer has to be over the window for the key to
            # reach it
            xtest.fake_input(dpy, X.MotionNotify, x=wx + 120,
                             y=wy + wh - 60)
            dpy.sync()
            time.sleep(0.3)
            press(dpy, spec["keys"])
            time.sleep(0.6)
            wiggle(dpy, wx + 120, wy + wh - 60)
            time.sleep(0.6)

            if spec.get("everyTab"):
                # one picture per tab, whichever interface this is
                names = spec["everyTab"].get(args.build, [])
                picture = _dialog_picture(dpy, spec["dialog"], args.build, win,
                                          ww, wh)
                found = tab_boundaries(picture, args.build) if picture else []
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
                    click(dpy, place[0] + x, place[1] + TAB_ROW[args.build])
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

            point = spec.get("press", {}).get(args.build)
            if point:
                if not press_inside(dpy, args.build, point,
                                    spec["dialog"], wx, wy):
                    failures.append("%s: no dialog to press in" % name)
                    continue
                time.sleep(0.5)
                wiggle(dpy, wx + 120, wy + wh - 60)
                time.sleep(0.5)

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
                box = imgui_box(after, DIALOG_POS)
                if not box:
                    failures.append("%s: no dialog at %s" % (name, DIALOG_POS))
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

        point = spec.get("press", {}).get(args.build)
        if point:
            if not press_inside(dpy, args.build, point, spec["dialog"],
                                wx, wy):
                failures.append("%s: no dialog to press in" % name)
                continue
            time.sleep(0.5)
            wiggle(dpy, wx + 120, wy + wh - 60)
            time.sleep(0.5)

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
                    choices=["released", "fltk", "imgui"])
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

    os.makedirs(args.out, exist_ok=True)
    os.makedirs(args.home, exist_ok=True)
    if args.build == "imgui":
        with open(os.path.join(args.home, ".gmsh-imgui.ini"), "w") as f:
            f.write(IMGUI_INI)
    failures = []

    with Xserver(args.display):
        dpy = display.Display()
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
        failures = photograph(dpy, args, specs)
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
            failures = photograph(dpy, args, again)

    for f in failures:
        print("FAIL " + f)
    return 1 if failures else 0


if __name__ == "__main__":
    sys.exit(main())
