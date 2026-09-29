// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef WIN32_COMMON_H
#define WIN32_COMMON_H

#if !defined(NOMINMAX)
#define NOMINMAX
#endif
#if !defined(WIN32_LEAN_AND_MEAN)
#define WIN32_LEAN_AND_MEAN
#endif
#if !defined(_WIN32_WINNT)
// Windows 10: SetThreadDpiAwarenessContext, GetDpiForWindow
#define _WIN32_WINNT 0x0A00
#endif

#include <windows.h>
#include <commctrl.h>

#include <functional>
#include <string>
#include <vector>

#include "Backend.h"
#include "Layout.h"
#include "Tree.h"

// What the files of the native Windows interface share: the descriptions it
// was handed, the menus, the controls of a field, the tree, the forms and the
// scene the main window holds. Plain Win32 and the common controls, nothing
// else; nothing here calls Gmsh but the scene.

const Ui::Backend::Sources &win32Sources();
const Ui::Backend::Host &win32Host();

// UTF-8, which Gmsh speaks, and UTF-16, which the W functions of Windows do
std::wstring win32Wide(const std::string &s);
std::string win32Utf8(const std::wstring &s);
std::string win32Text(HWND w);

// run once the message being handled is over: what it does may open a
// window, start a picking or make the control it came from again
void win32Later(const std::function<void()> &what);
// the message the main window gets for them, and what it does then
#define WM_GMSH_LATER (WM_APP + 1)
void win32RunLater();
// held anywhere: the scene, and a value dragged in a dialog, ask
bool win32ButtonDown();

// --- the keys as Ui::Shortcut says them, from a WM_KEYDOWN or WM_SYSKEYDOWN
bool win32UiKey(WPARAM vk, LPARAM lp, int &key, unsigned &mods);
// a key the window it went to does not take: the shortcuts of Sources::keys
bool win32MainKey(const MSG &m);

// --- menus: an entry runs its action with win32Later()

// the menu bar of the main window, made again when the description changed
void win32RefreshMenuBar(HWND window);
// what is checked and greyed, read as a menu opens (WM_INITMENUPOPUP)
void win32MenuOpens(HMENU menu);
// WM_COMMAND of an entry: true if it was one
bool win32MenuCommand(WORD id);
// at the pointer, or at x, y of the screen
void win32PopupMenu(const std::vector<Ui::MenuItem> &items, HWND owner,
                    int x = -1, int y = -1);

// --- the size of things: the font of the interface, and the metrics of
// Layout.h measured on the controls of Windows
HFONT win32Font(bool bold = false);
HFONT win32FixedFont();
double win32Em();
int win32Px(double em);
Ui::Metrics win32Metrics();
// the height of a line of controls, in pixels
int win32Row();
// the fonts or the DPI changed
void win32ForgetMetrics();

// --- the window class every holder of controls is: it hands what its
// controls tell (WM_COMMAND, WM_NOTIFY, WM_HSCROLL, WM_DRAWITEM,
// WM_CTLCOLOR...) to the binding of the control
const wchar_t *win32PanelClass();
// what the panel does with a message no control takes, if anything
typedef LRESULT (*win32PanelHook)(HWND, UINT, WPARAM, LPARAM, bool &taken);
void win32SetPanelHook(HWND panel, win32PanelHook hook);
HWND win32Panel(HWND parent, int x, int y, int w, int h, bool border = false);

// --- the controls of one field, children of `parent`, bound to the place
// its value lives; after runs once the user changed something
struct fieldWin32;
fieldWin32 *win32MakeField(HWND parent, const Ui::Field &field,
                           const std::function<void()> &after);
void win32DropField(fieldWin32 *f);
// where they go, in the pixels of the parent: the widget, its name (w == 0:
// none apart), the buttons after it
void win32PlaceField(fieldWin32 *f, const RECT &widget, const RECT &label,
                     const std::vector<RECT> &trailing, bool shown);
void win32RefreshField(fieldWin32 *f);
void win32RebindField(fieldWin32 *f, const Ui::Field &field);
HWND win32FieldWindow(fieldWin32 *f);
// the messages a panel hands over; true when it was the field's
bool win32FieldMessage(HWND panel, UINT msg, WPARAM wp, LPARAM lp,
                       LRESULT &result);

// --- a tree whose lines are fields (Tree.h), as a tree view: the modules,
// and a Hierarchy field, whose lines have boxes to check
class treeWin32;
treeWin32 *win32MakeTree(HWND parent, const Ui::Tree &tree, bool picks,
                         const std::function<void()> &after);
void win32DropTree(treeWin32 *t);
HWND win32TreeWindow(treeWin32 *t);
void win32SetTree(treeWin32 *t, const Ui::Tree &tree);
void win32RefreshTree(treeWin32 *t, bool rebuild);
void win32OpenTreeItem(treeWin32 *t, const std::string &path, bool open);
bool win32TreeItemOpen(treeWin32 *t, const std::string &path);
// the WM_NOTIFY of the tree view: true when it was
bool win32TreeNotify(treeWin32 *t, NMHDR *n, LRESULT &result);
// the field of the line picked is edited under the tree, in this panel
void win32SetTreeEditor(treeWin32 *t, HWND panel);

// --- the described forms, see dialogWin32.cpp
void win32ShowForm(const Ui::Form &form, bool show);
bool win32FormVisible(const Ui::Form &form);
std::string win32FormPane(const Ui::Form &form);
void win32SetFormPane(const Ui::Form &form, const std::string &pane);
void win32ReloadForm(const Ui::Form &form);
void win32DropForm(const Ui::Form &form);
void win32FormOptionChanged(const std::string &name);
void win32FormsClosingDown();
void win32SetMainWindow(HWND window);
HWND win32MainWindow();
// the windows of the forms, for the keys that move between their controls
bool win32FormDialogMessage(MSG &m);

// --- the scene, see SceneWin32.cpp: the panes of the main window
HWND win32SceneWindow(HWND parent);
void win32SceneRedraw();
void win32SceneSize(int &width, int &height);
void win32SceneNewWindow();
void win32SceneDestroy();
bool win32SceneDrawing();
// once a turn of the loop: the timers of the scene, the animation, the pad
void win32ScenePump();
// in seconds, below zero for nothing pending
double win32SceneNextTimer();

void win32RefreshBar();

#endif
