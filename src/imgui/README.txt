Dear ImGui / GLFW interface of Gmsh
===================================

This directory contains the Dear ImGui frontend, enabled with
"cmake -DENABLE_IMGUI=ON". It is mutually exclusive with the FLTK interface:
ENABLE_IMGUI=ON turns ENABLE_FLTK off.

The rest of Gmsh never talks to this directory directly: everything goes
through the toolkit-independent interface declared in src/common/Gui.h, which
is implemented here by Gui.cpp (and by src/fltk/GuiFltk.cpp for the FLTK
build).

How a frame is drawn
--------------------

appWindow::frame() runs, in this order:

  1. actions queued by widgets are run, outside of any Dear ImGui frame (see
     "Deferred actions" below);
  2. the events are polled and a new Dear ImGui frame is started;
  3. the dock space and the panels are built; the central node of the dock
     space is left empty ("pass-through"), and its rectangle becomes the
     rectangle of the 3D scene;
  4. the scene is rendered by scenePane::draw(), with glViewport()/glScissor()
     set to that rectangle, i.e. directly into the main frame buffer;
  5. the Dear ImGui draw lists are submitted on top.

There is deliberately no frame buffer object: the whole rendering path stays in
plain OpenGL 1.x + GLU, which is what the Gmsh drawing routines and the
imgui_impl_opengl2 backend both expect. It also means the picture of the scene
cannot be rendered larger than the window (see appWindow::beginCapture()).

Deferred actions
----------------

Dear ImGui frames are not re-entrant, so an action triggered by a widget cannot
run while the frame is being built: it would deadlock as soon as it opens a
blocking dialog (Msg::GetAnswer()) or starts an interactive selection, both of
which pump frames of their own. Widgets must therefore queue their work with
appWindow::postAction(), which runs it at the beginning of the next frame,
outside of NewFrame()/Render().

Pumping events from the mesher
------------------------------

Msg::Info() and friends call Gui::check() while a mesh is being generated, so
that the interface stays alive. appWindow::check() reproduces the semantics of
FlGui::check(): it returns immediately when called from a worker thread
(Msg::GetThreadNum() > 0) or while the GUI is locked, and it draws at most
General.GuiRefreshRate frames per second. frame() additionally guards against
re-entering itself.

Windowing system
----------------

GLFW is built with both the native Wayland backend and the X11 one on Linux and
normally picks Wayland when a Wayland display is available. Set the
GMSH_GUI_PLATFORM environment variable to "wayland", "x11" or "any" to force the
choice; when the preferred backend cannot be initialized, Gmsh falls back to the
other one. Which one ended up being used is printed at startup ("Running
natively on Wayland" or "Running on X11"), because it changes how the desktop
shell treats the window: an X11 window under a Wayland session goes through
XWayland, and the window rules of the shell often apply differently there.

While probing the backends, a failure is expected and is only logged as a debug
message: Msg::Error() records the last error, which would make the public API
throw when the first backend tried is not available. The reason of the last such
failure is kept, so that a fallback to X11 inside a Wayland session can say why
it happened instead of being silent.

That fallback is the one failure mode worth knowing about, because nothing looks
broken when it happens. GLFW deliberately loads its Wayland client libraries
with dlopen(), so that a binary built with Wayland support still runs where they
are absent; the price is that a session which keeps them outside the search path
of the dynamic loader silently lands on XWayland. The dynamic loader resolves a
dlopen() through the RUNPATH of the caller, so the top-level CMakeLists.txt asks
pkg-config where they were found at build time and adds their directories to the
RUNPATH of the Gmsh targets, without linking them (they stay optional). On a
distribution that installs them in the default search path this is a no-op; on
NixOS or Guix it is what makes the native Wayland backend usable at all.

libdecor is on that list for a different reason: it draws the window frames on
the compositors that leave them to the client, which is most of them. Missing,
it costs no more than the plain coloured borders GLFW falls back to -- but with
no title bar to grab, so it is worth having.

Panels can be dragged out of the main window into windows of their own, the way
the palette windows of the FLTK interface are: that is Dear ImGui multi-viewport
support (ImGuiConfigFlags_ViewportsEnable), which needs the frame loop to call
UpdatePlatformWindows()/RenderPlatformWindowsDefault() and to put back the
OpenGL context the scene is drawn in, since each detached window has one of its
own. A panel dragged back over the main window merges into it again.

This does not work under Wayland, where panels stay inside the main window. The
protocol has no global window coordinates: a client can neither learn nor choose
where its windows are, and Dear ImGui drags a detached panel by moving its
window. The GLFW backend therefore turns multi-viewport support off on that
platform, and Dear ImGui clears the flag by itself when a backend cannot honour
it -- asking for it is always safe. _detachablePanels() reports what was
actually granted, and the interface says so once at startup.

Separate windows can be made to appear there, but not to be usable: doing so
means feeding Dear ImGui positions the platform never confirms, so the
coordinate space it lays windows out in stops matching the screen, and dragging
one -- to move it, or back onto a dock node -- no longer lands where it looks
like it should. Detaching a panel on Wayland is worth revisiting when the
platform, or GLFW, offers something better than a position the client has to
invent.

statusBar.cpp draws the bar along the bottom, the counterpart of the one the
FLTK interface builds out of Fl_Buttons: the current model, a menu of the
options one reaches for most often, the view orientation (Shift gives the
opposite direction, as in FLTK), the mouse selection toggle, the animation
controls -- greyed out until there is something to animate -- and then the last
message and the progress of whatever is running. Clicking the message shows or
hides the console, which is what the FLTK progress widget does on FL_PUSH.

Two things are worth knowing there. BeginViewportSideBar() lives in
imgui_internal.h, and the window it opens must carry ImGuiWindowFlags_MenuBar or
the BeginMenuBar() inside it simply returns false and the bar draws empty. And
the animation is stepped from the frame loop (_stepAnimation()) rather than from
the blocking loop the FLTK interface runs, since an immediate-mode frame is not
re-entrant and a frame is going by anyway.

The modules tree is not written here either. Like the menu bar, it is declared
once -- Menu::modules() -- and both interfaces walk it: modulesPanel.cpp draws
it as Dear ImGui tree nodes, and src/fltk/menuFltk.cpp flattens it into the
"0Modules/..." paths onelabGroup wants, which is what static_modules[] used to
be by hand.

A leaf either runs an action of GuiActions.h straight away, or shows the context
panel that holds its parameters and starts an interactive selection. Saying that
once needs a few more hooks in the facade, all of them things the description
cannot know: Gui::showElementaryContext(), showTransformContext(),
showMeshContext() and showPhysicalContext() to bring up the right pane, and
Gui::geometryParams() / elementaryParams() to read those panes back. The panels
of the tree that have no menu entry -- the mesh size fields, the high order
tools, the partitioner, the surface reclassification -- joined the Gui::Panel
enum.

Two things stop at the same place in both interfaces. The tree stops where the
ONELAB parameters begin: those are widgets, not entries, and each interface
builds them itself, below the declared part. And bringing a context panel
forward has to wait for the next frame -- the tree runs its action outside of
one, where SetWindowFocus() has nothing to act on -- so it goes through a
pending flag and SetNextWindowFocus().

Those selections live in src/common/GuiActionsGeo.cpp and are shared with the
FLTK interface -- geometryActOnSelection(), geometryAddCurve(),
geometryAddSurfaceVolume(), geometryBoolean(), geometryFillet(),
geometrySplitCurve(), meshDefineEmbedded(), meshDefineTransfinite(). Their
parameters are not passed by value but read through a callback, because the
panel they come from stays usable while the loop runs: the FLTK context windows
have always let one change a value between two applications without starting the
selection over, and reading the parameters again at each 'e' keeps that true in
both interfaces.

The four context dialogs are declared once as well, in src/common/GuiDialogs.h
and GuiDialogs.cpp, and built by both interfaces: contextPanels.cpp turns the
description into Dear ImGui windows, src/fltk/dialogFltk.cpp into the windows
contextWindow.cpp used to build by hand.

A dialog is a set of panes, a pane a list of labelled fields. The difference
with the menus is that the description *owns the values*: a field says where its
value lives -- a std::string, an int, a double, a bool in the shared store of
GuiActions.h -- and both interfaces bind their widget to that same variable. So
nothing has to be read back, which is exactly what the interactive actions want,
since they read their parameters again at every application. That is what
removed Gui::geometryParams() and the getter each action used to be handed.

Three things the model had to be able to say, because the FLTK windows say them:
a field can be greyed out by a predicate (the mesh extrusion fields only matter
when the action extrudes); a choice can be bound to an integer rather than to
its own text (the selection mode is an ENT_* constant); and a list can come from
the model rather than being fixed (the physical groups that already exist). The
elementary dialog also asks for its twelve tabs to be laid out on two rows,
which is why the FLTK window had two Fl_Tabs.

A field does not have to be bound to a variable of ours: it can edit a Gmsh
option, addressed the way the option file does. The interfaces never see the
difference, because they go through Field::getNumber()/setNumber() and friends
rather than at the pointer. That is what let the mesh partitioner be declared
with nothing of its own to store -- every one of its fields is an option -- and
it is what the option panel will need.

The description does carry a little layout, and it has to: the windows it
replaces are two or three columns wide in places -- the axis point beside the
axis direction, the element weights in two rows of three -- and stacking
everything in one column loses the grouping that says which fields belong
together. A field can therefore ask to share the line of the one before it, and
that is the whole of it: no coordinates, no widths. Each interface works out the
rest, the FLTK builder measuring the labels with fl_width() to size the window,
which is what the hand-written windows did with arithmetic.

Folding a pane away must not cost a rebuild on the FLTK side. Destroying the
window and making a new one makes it blink and come back wherever the remembered
position says, and deleting widgets from inside the callback of one of them is
how FLTK crashes. So every pane is built, folded or not, and refreshing only
moves what is left and resizes the window -- same window, same place.

A dialog is not resized by hand: it declares what it holds and takes exactly
the room that needs, but it keeps the width of its widest row and the height of
its tallest pane whatever is folded or whichever tab is up. A window that grows
sideways as one uses it is a window that will not sit still.

Everything that used to be a window of its own is described that way now -- the
options, the visibility, the plugins, the size fields, the three windows of the
Help menu, and the parameters a solver attaches to one entity -- so neither
interface builds a dialog by hand any more. The last two brought their own vocabulary:
what the panes are about, written above the row of tabs (Panel::header) and
named in bold (Field::heading); what stands on the line of a pane's button and
outside what scrolls above it (Pane::beside); and a button that drops things to
do rather than things to be (FieldKind::Menu), which is how one asks for a new
size field or for the view to draw one on.

What a dialog offers can change with what one picks in it: another plugin has
other options, a size field deleted is one line fewer. Dear ImGui builds the
description afresh every frame and follows by itself; the FLTK one compares the
shape of the description with the shape it was built for and builds again only
when they differ, keeping the window where the user put it. Anything a field
callback still needs after that must be a copy: building again is the end of the
list it was walking.

A dialog that is one long page rather than a form one fills -- the keyboard and
mouse reference -- scrolls: its panes are not tabbed, and FLTK puts them inside
an Fl_Scroll as tall as the panel says it is worth while Dear ImGui lets the
window itself scroll. A panel of a single pane is a box that scrolls instead, so
that a list filling it -- the listing of the current options -- stops above the
footer rather than pushing it out of the window.

The per-entity ONELAB window (src/common/GuiOnelab.cpp) holds no fields of its
own either: it makes one per parameter instantiated from the "ONELAB
Context/<Dim> Template/..." templates, for whichever entity was double-clicked.
Its fields are bound to a place in that list rather than to a name, so that
opening the window on a second entity made from the same template -- the same
fields, with the same labels -- shows the second entity without the FLTK window
having to be built again.

It brought two things the model could not say. A field can ask for its value to
be taken once one has finished typing it rather than at every letter
(Field::commitsWhenDone): a ONELAB parameter may have the solver run again when
it changes, and running it once per letter is not what anyone means. FLTK says
that by giving the input inside the widget FL_WHEN_RELEASE|FL_WHEN_ENTER_KEY,
Dear ImGui by holding what is being typed in a buffer of its own until the item
is deactivated -- read afresh at every frame, the value would write over the
keyboard between two letters. And a panel can say what to do when it is closed
(Panel::closed), which is how the window stops highlighting the entity it was
about; FLTK hears every way of hiding a window through FL_HIDE, so the builder
gives its dialogs a window that reports it, and takes care not to report the
window it destroys when it builds one again.

What a ONELAB parameter *does* when someone changes it moved with the window,
from the widget callbacks of the FLTK module tree into GuiOnelab.cpp: the Gmsh
option its "GmshOption" attribute names, the hiding, resetting and rewriting its
"ServerAction..." attributes ask of the server, and the check the solver wants
when Solver.AutoCheck is on. The tree calls the same code, so the two agree; the
Dear ImGui panel used to write the value back and quietly do none of the rest.

Two things of that window are deliberately not described. A ONELAB number is
drawn by the FLTK tree as an inputRange, which carries two small buttons -- the
loop level of a parametric sweep, and which graph to plot the parameter in --
and a string of kind "file" gets menu entries for choosing, editing and merging
the file. Both belong to the metamodel and solver workflow of the module tree,
which keeps its own widgets and still has them; the per-entity window shows the
value, the range and the choices, and no more.

FLTK reads "&" in a label as the mark of a keyboard shortcut in menus, buttons
and inputs -- and only there. A label that is text has to double it for those,
and must not for a box, a group, a tab or a line of a tree, which draw what they
are given.

GLFW is not like the other bundled libraries. They are compiled straight into
Gmsh, source by source; GLFW keeps its own CMakeLists and produces a target of
its own, which is what selects the platform backend for us. A target of this
build cannot travel: its name means nothing to another project, and a target
named in the interface of an installed library must itself be installed and
exported, which a vendored dependency is not -- install(EXPORT) refuses the
whole export set over it, so ENABLE_BUILD_DYNAMIC and ENABLE_IMGUI could not be
asked for together. It goes in GMSH_PRIVATE_LIBRARIES now and is linked PRIVATE:
baked into libgmsh, its symbols hidden by --exclude-libs, and mentioned to
nobody.

One more thing the build needs on a system that is not the one it was written
on: Gmsh takes only `fltk-config --includedir`, which since fltk 1.4 is not
enough, as its headers include those of the libraries it was itself built
against (`Fl.H` pulls in `<cairo.h>`). Every `-I` of `--cxxflags` is taken now.

A window must never be created while a group is open: FLTK makes it a child of
that group instead, and the window that was being built comes out empty. A
dialog is therefore built only when it is asked to show, never merely because
someone asked whether it is up, and it clears the current group while it
builds.

A dialog that shows something the running action keeps -- what has been picked
so far, say -- has to be told when it changes. The Dear ImGui one draws itself
afresh at every frame and needs nothing; the FLTK one holds its values in
widgets, so the action calls Gui::refreshDialog(). Forgetting it shows an empty
list next to a status bar that says otherwise.

utils/guicompare photographs the same dialog in the released Gmsh, in this
FLTK interface and in this Dear ImGui one, and puts the three side by side. It
goes through every tab, each reached through the leaf of the modules tree that
raises it, which checks the wiring from the tree to the pane at the same time.
Comparing the two interfaces of this tree against each other proves nothing:
they are built from one declaration, so they are wrong together. Only the
released build can contradict it, and it did -- twelve tabs stacked into two
sets both on screen at once, a line of instructions dropped, labels rewritten,
a window renamed, the one two-column pane flattened. None of that was visible
without it.

Anything declared has to be checked in *both* interfaces, and a geometry dump is
not enough: the FLTK check buttons came out with no visible label because the
builder gave every widget FL_ALIGN_RIGHT, and a check button draws its label
inside, next to the box. The widget rectangles were right; only the pixels were
wrong. src/fltk keeps its own grab of a dialog through fl_read_image() easy to
add back when a layout needs looking at.

Two other things the partitioner asked for: a panel whose panes follow one
another as titled sections rather than as tabs, for the windows that are one
long form, and buttons at the bottom of the panel rather than one per pane.

One trap the shared pane fell into, worth remembering when binding any state
both sides write to. The pane the description asks for must be forced *once*,
when it is asked for, and not at every frame: forcing it while also writing back
whichever tab is actually open makes the two fight, and the dialog visibly
alternates between two panes. The same applies to the FLTK window, where the tab
the user clicks has to be written back into the description, or the next refresh
puts the remembered pane back.

The values being shared has a pleasant side effect: Geometry.Snap0/1/2 is bound
straight to CTX::instance()->geom.snap, so the option and the field are the same
variable and opt_geometry_snap*() no longer has to push anything into a widget.

Hovering says what is under the pointer, as it does in FLTK: scenePane::_hover()
runs the same selection query on every move and puts the information string of
what it found -- plus what a double click would do -- into a tooltip, or into
the status bar when General.Tooltips is off. It also asks for the hand cursor,
Dear ImGui having no crosshair among the ones it knows. The tooltip is cleared
as soon as the pointer moves over a panel: nothing else would clear it, and it
would sit there over a window it has nothing to do with.

Placing an entity with the mouse works as it does in FLTK: picking a shape under
"Add" starts geometryAddPointBasedEntity(), which turns the "add point mode" of
the panes on. The pointer then drives the first three fields of the pane -- the
line it points along is unprojected, the point of that line closest to the
centre of gravity of the model is taken, and it is snapped to Geometry.Snap --
Shift holds the coordinates where they are, 'e' writes the entity and 'q'
leaves. The entity being built is previewed on top of the model through
drawContext::setDrawGeomTransientFunction(); the preview and the snapping both
live in GuiActionsGeo.cpp, so the two interfaces show the same thing.

The menu bar is not written here at all. It is declared once, in
src/common/GuiMenus.h and GuiMenus.cpp, and both interfaces build it from that
one description: menuBar.cpp walks it every frame, and src/fltk/menuFltk.cpp
flattens it into the Fl_Menu_Item[] that Fl_Menu_Bar wants, which is what
bar_table[] and sysbar_table[] used to be by hand.

What the description had to be able to say, for that to work:

 - A shortcut is a key plus modifiers, with "Command" meaning Control on X11 and
   Windows and the Command key on macOS -- the distinction the old pair of FLTK
   tables spelled out twice. The text next to the entry is computed from it, not
   stored: a stored label is exactly how a menu comes to promise Ctrl+H and do
   something else.
 - The mnemonic is a field of its own rather than an ampersand inside the label,
   because FLTK wants the ampersand and this interface has no mnemonics at all.
 - The separator is "after this entry", which is what FL_MENU_DIVIDER has always
   meant; walking it, this interface emits Separator() on the way out.
 - An entry that shows and hides a panel is a Toggle bound to Gui::panelVisible()
   and Gui::showPanel(). FLTK draws those with FL_MENU_TOGGLE, which it had
   never used: its "Message Console" entry toggled without saying so.
 - What an interface cannot honour is left out rather than greyed, through
   Gui::supportsWindowAction(): "Copy to Clipboard" needs an image clipboard,
   "Bring All to Front" needs more than one window, and "Attach/Detach Menu" has
   nothing to do here, where every panel is already dragged in and out of the
   dock space by hand. They all stay in the FLTK menu, which does have a use for
   them.
 - A divider on the last entry of a menu is trimmed when the description is
   built, since leaving one out is exactly what makes a line appear under
   nothing.

The description is rebuilt rather than mutated, so the recent files are simply
read while it is built; Gui::fillRecentHistoryMenu() only bumps a generation
counter, and both interfaces build again when they notice. That is also the
answer for anything else dynamic that ends up in a menu.

The accelerators are read from the same description in shortcuts.cpp: Dear ImGui
draws the menus but never acts on the shortcut it displays, so each one has to
be tested by hand -- from the description rather than from a second hand-written
list. Doing so turned up that they had never worked at all: the handler bailed
out on io.WantCaptureKeyboard, which with keyboard navigation enabled -- and it
is enabled -- is true as soon as any panel has the focus. The test is
io.WantTextInput, which is true only while a text field is being typed into.

"Tools > 3M", which belongs to the proprietary extension of contrib/3M, is
declared under HAVE_3M like the rest and only appears where there is a window
for it, which is the FLTK interface. The extension is not part of the
repository, so that path cannot be built here; it was checked by compiling the
two files with HAVE_3M forced and a stand-in header.

The entries of the "Window" menu that this interface keeps act on the GLFW
window that holds the dock space. "Minimize" and "Zoom" go straight to GLFW --
"Zoom" is the old macOS idiom, resizing the window to the work area of the
screen and back, which FLTK does by hand and GLFW does through the window
manager.

"Enter Full Screen" keeps nothing but the 3D view, as in FLTK, which shows a
graphic window of its own there and hides everything else: the dock space, the
two bars and the panels are simply not drawn, and the current view fills the
window. Nothing is saved and restored, because nothing is changed -- Ctrl+F
again brings the interface back exactly as it was, which is the one thing an
immediate-mode interface makes easy. The menu is out of reach while full screen,
so Ctrl+F is the way out, again as in FLTK.

"New Window" opens another graphic window, and that one is a real window: a GLFW
window sharing the OpenGL context of the main one -- so the textures, the font
atlas of the scene text included, are the same -- with no Dear ImGui inside it
at all, just the scene. That is what makes it work everywhere, Wayland included:
an application may open as many toplevel windows as it likes there, it simply
may not place them, which a window carrying nothing but a 3D view never needs to
do. Going through Dear ImGui's viewports instead would have inherited the
limitation described above and given a window that cannot leave the main one.

Its pane is in _panes like any other, so the API and the status bar count it,
but it is not in _paneRoot: it is not tiled, and Split/Unsplit leave it alone.
It is rendered after the main window has been swapped, with its own context made
current, and closed when GLFW says the user asked for it.

Its events come from GLFW callbacks rather than from Dear ImGui, which is why
scenePane::handleMouse() takes a paneInput instead of reading the Dear ImGui io:
the panes of the main window get that structure filled in from Dear ImGui, an
extra window from its own callbacks. The events it carries are one-shot -- a
click, a release, a wheel notch -- so they are cleared once the pane has seen
them, which is what Dear ImGui does for the main window anyway.

The window is identified with a Wayland app id and an X11 WM_CLASS of "gmsh".
GLFW leaves the app id empty and derives WM_CLASS from the window title
otherwise, and the title follows the project file, so the desktop would have
nothing stable to match the window against.

Fonts
-----

Dear ImGui embeds a single bitmap font, crisp at its native size but blurry as
soon as the display scale is not 1. src/imgui/fonts.cpp therefore looks for a
real TrueType font: GMSH_GUI_FONT if it is set, then the usual system paths,
then the directories that fontconfig lists in /etc/fonts (which is what finds
the fonts on the distributions that keep them out of the usual places). It falls
back on the embedded font when it finds nothing. The text drawn in the 3D scene
comes from the same atlas, so it benefits too.

Status
------

Implemented: the window and its event loop, the dock space, the 3D scene with
mouse navigation (rotate, pan, zoom, lasso zoom), entity selection, the string
rendering used by the 3D scene, the message console, the status bar and its
progress meter, the blocking input and question dialogs, the file chooser
(fileBrowser.cpp, on std::filesystem), the menu bar and the actions it triggers,
the keyboard shortcuts, the option editor
(optionsPanel.cpp) and the raster graphic output files (PNG, JPEG, PPM, GIF,
YUV).

The actions themselves live in src/common/GuiActions.cpp and are shared with the
FLTK interface: this directory only decides how they are presented.

The option editor has two layers. What an option looks like cannot be deduced
from the tables of DefaultOptions.h: they do not say which numbers are switches,
which ones are enumerations and what their values mean, which ones belong
together, or how to name them for a human ("General.FastRedraw" is really "draw
a simplified model while interacting"). The panels are therefore written by
hand, as they are in the FLTK option window, and only the mechanism is generic:
a row says which option it edits and how, the reading and the writing go through
NumberOption()/StringOption()/ColorOption(), and the tooltip is the help string
of the table, so that it cannot drift. Beware that the values of an enumeration
do not always start at 0 and do not always go up: General.VectorType starts at
1, and General.Orthographic is 1 for "Orthographic" and 0 for "Perspective",
hence the COMBOV() rows.

Whatever is not laid out by hand is still reachable: the "All" tab of each
category lists every one of its options, alphabetically and searchable. All
seven categories now have hand-written panels.

A script check is worth re-running after editing the tables: every name in an
optionRow must exist in DefaultOptions.h, in the table matching the kind of the
row. Two of the tooltips of the FLTK window are stale ("Solver.Timout",
"Geometry.OCCFixSewFaces") and copying them blindly would silently produce rows
that show nothing.

Scaling: the interface follows the scale factor of the display, read from
glfwGetWindowContentScale(), and applied to the Dear ImGui style, to the
interface font and to the text drawn in the 3D scene. It is refreshed at every
frame, so moving the window to another display works. Set GMSH_GUI_SCALE to
override it. General.FontSize keeps its usual meaning of a size in points and is
multiplied by that factor.

Also implemented: splitting the graphic window ('h', 'v' and 'u', with the
panes tiling the central node through a binary tree), the module tree with the
ONELAB parameters and the solver, the clipping, manipulator, statistics,
visibility, colour map, plugin, mesh size field and geometry panels, the
per-format export options, the keyboard and mouse reference, and the vector
output formats (PS, PDF, SVG, TeX, PGF).

Also implemented: the high order tools, the mesh partitioning, the surface
reclassification, the interactive inspection of
the mesh elements, the mesh constraints (size at points, transfinite, recombine,
compound) and the registration and start-up of the solvers.

The only thing left is copying the view to the clipboard, which the FLTK
interface only does on Windows anyway, and which GLFW cannot do: its clipboard
carries text, not images. Use "File > Save Model As" with a picture format
instead.

Grabbing the scene. glReadPixels() and gl2ps both expect the scene to sit at the
origin of the frame buffer, which it does not when it only occupies the central
node of the dock space. Gui::beginGraphicCapture() therefore redraws the panes
into the bottom-left corner at the requested size, and endGraphicCapture()
restores the on-screen layout; in the FLTK interface, where the graphic window
is a window of its own, both do nothing. Without a frame buffer object the
picture cannot be larger than the window, and Gmsh warns and clamps when asked
for more.

One consequence is worth knowing: with General.PrintCompositeWindows set and the
view split, a vector output (PS, PDF, SVG, TeX) contains all the panes here,
because they share one frame buffer, whereas the FLTK interface writes an almost
empty file, gl2ps being able to record only one window at a time.

Known limitations:

 * Dear ImGui ships a single embedded bitmap font, so the fifteen font names of
   General.GraphicsFont all resolve to it and small text in the 3D scene looks
   softer than with FLTK.
 * Under Wayland there is no server-side window positioning, so window
   positions cannot be restored (sizes can).
