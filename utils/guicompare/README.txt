Comparing the dialogs, three ways
=================================

The Dear ImGui interface and the rewritten FLTK one are both built from one
declaration now (src/common/GuiDialogs.h). The question this answers is whether
that declaration still says what the windows it replaced said, and the only
honest way to ask it is to photograph all three and look.

  released   the Gmsh installed with pip, untouched upstream. This is the
             reference: it is what the conversion has to reproduce.
  fltk       the FLTK interface of this tree, built from the declaration.
             It should be indistinguishable from the released one.
  imgui      the Dear ImGui interface, built from the same declaration. It
             cannot be identical -- another toolkit draws differently -- but
             it must hold the same fields, in the same order and the same
             grouping, with the same labels.

Running it
----------

  python3 -m venv .venv
  .venv/bin/pip install gmsh python-xlib pillow
  utils/guicompare/run.sh

The pictures land in utils/guicompare/out/figures, one sheet per dialog, the
three versions side by side at their true size: a dialog that came out twice as
tall as the one it replaces has to look twice as tall.

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
