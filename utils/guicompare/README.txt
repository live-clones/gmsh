Comparing the dialogs, four ways
================================

Every interface of this tree is built from one declaration now
(src/common/GuiDialogs.h). The question this answers is whether that
declaration still says what the windows it replaced said, and the only honest
way to ask it is to photograph them all and look.

  released   the Gmsh installed with pip, untouched upstream. This is the
             reference: it is what the conversion has to reproduce.
  fltk       the FLTK interface of this tree, built from the declaration.
             It should be indistinguishable from the released one.
  imgui      the Dear ImGui interface, built from the same declaration. It
             cannot be identical -- another toolkit draws differently -- but
             it must hold the same fields, in the same order and the same
             grouping, with the same labels.
  browser    the same declaration again, drawn as a page in a browser. It was
             written to find out what the contract still took for granted, and
             it is the strictest of the three conversions: it shares no widget,
             no toolkit and no process with the others. It needs chromium and
             a build in build-browser/; without either, the column is simply
             absent.

Running it
----------

  python3 -m venv .venv
  .venv/bin/pip install 'gmsh==4.15.2' python-xlib pillow
  utils/guicompare/run.sh

The version is pinned on purpose. That build is the reference every picture is
compared against, and every coordinate this bench clicks was measured on its
windows; a newer one would move them and quietly change what "the same" means.

The four builds photograph at the same time. Each holds an X server, a Gmsh
with its model, and for the page a browser besides, so on a machine with
little memory to spare GUICOMPARE_AT_ONCE says how many may run together.

The pictures land in utils/guicompare/out/figures, one sheet per dialog, the
versions side by side at their true size: a dialog that came out twice as tall
as the one it replaces has to look twice as tall.

utils/guicompare/out/bench.html is the lot in one page -- every dialog, every
interface, a box to filter by name and a control for how big to draw them. It
points at the shots where they lie rather than carrying them, so it is opened
from the disk, next to them.

That control is in screen pixels per picture pixel rather than in a zoom, and
on purpose: a screenshot looks like itself only while each of its pixels covers
a whole number of the screen's, and what a browser does when they do not is its
own business -- the same page came out right in one and broken in another. Said
this way there is nothing to interpolate. It opens at whatever makes a window
as big as it was on the server it was photographed on.

How it works, and why it is built this way
------------------------------------------

Everything happens on a private X server. XTEST, which is how the clicks are
sent, has no way of telling one display from another, so without it this would
be clicking on the session of whoever runs it. HOME is redirected for the same
reason: Gmsh remembers window positions and Dear ImGui remembers its layout,
and neither should be read from, or written to, a real home directory. FLTK 1.4
and GLFW both prefer Wayland when they can have it, and would then open on that
real session anyway, so both are told to use X11.

Each picture takes two processes. drive.py holds the interface open with the
right branches of the tree unfolded; shoot.py clicks the leaf and photographs
what appears. They cannot be one process: opening a leaf usually starts an
interactive selection, which never gives control back.

Unfolding is done through gmsh.fltk.openTreeItem(), which only unfolds
branches, so the leaf itself has to be clicked. The coordinates are in run.sh,
one set per interface; `shoot.py --probe` photographs the tree so they can be
read off it when they drift.

In FLTK a dialog is a window of its own and the X server hands it over by name.
In Dear ImGui it is a window inside the one window of the application, so there
is nothing to hand over: shoot.py writes a layout file beforehand that pins the
dialogs to a known place clear of the modules panel, then walks the rectangle
out from there.

The page in a browser is photographed differently again, and on purpose.
Nothing there is clicked at a measured coordinate: the page is driven the way
anything outside it would drive it, over the socket it answers on, and it says
back where it put each of its windows -- which is what is cut out of the one
browser window the X server holds. A tree leaf is opened by its place in the
tree, a tab by its name, a button by its label. That makes the browser column
the one that says whether the description carries enough to build a window
from, rather than whether a toolkit was clicked in the right place.

What the page cannot do yet, it does not pretend to: a sheet says "pas de
capture" in its column rather than showing something that is not there. The
colour map of a view is the one thing left in that state.

No screen needed
----------------

Everything happens on private X servers, so a machine with no display is where
this belongs -- nothing is lost, since the scene was already drawn by Mesa's
software rasteriser under Xvfb rather than by any GPU. What such a machine
needs is Xvfb, chromium for the page's column, and the virtualenv above.

One thing does not announce itself: the fonts. FLTK asks for "Helvetica", and
what fontconfig answers decides every width in every window and therefore
whether the measured clicks still land. Check it before wondering why a run
misses:

  fc-match Helvetica        # Nimbus Sans here, from the URW base35 fonts

The build matters as much. A tree configured without ENABLE_PLUGINS has no
plugin window, one without ENABLE_OCC loses half the elementary entities, and
the bench would report differences that come from the configuration rather
than from the interface. ENABLE_BUILD_DYNAMIC is required -- there has to be a
libgmsh to drive -- and FLTK, Dear ImGui and the page are best built together,
since which of them comes up is decided when it does.
