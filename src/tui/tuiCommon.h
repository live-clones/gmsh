// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef TUI_COMMON_H
#define TUI_COMMON_H

#include <functional>
#include <map>
#include <memory>
#include <string>
#include <vector>

#include <ftxui/component/event.hpp>
#include <ftxui/component/mouse.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/box.hpp>

#include "Backend.h"
#include "Tree.h"

// The terminal interface, drawn with FTXUI and drawn afresh: every frame asks
// the descriptions again and makes the elements from them, as the Dear ImGui
// interface does, and what can be clicked or focused says so while it is
// made. Laid out as the page lays its forms out -- FTXUI's boxes are flex
// boxes. Nothing here calls Gmsh.


const Ui::Backend::Sources &tuiSources();
const Ui::Backend::Host &tuiHost();

// run between two turns of the loop, never inside one: what it does may
// turn the loop again
void tuiLater(const std::function<void()> &what);
// something changed that the next frame must show
void tuiDirty();
// on the clipboard, through the terminal (OSC 52)
void tuiCopy(const std::string &text);

// --- what can be clicked or focused this frame

struct hotTui {
  std::shared_ptr<ftxui::Box> box;
  // for the focus, which lasts from one frame to the next; empty for what
  // takes no focus
  std::string id;
  // x, y relative to the box; true when taken
  std::function<bool(ftxui::Mouse &m, int x, int y)> mouse;
  // while focused
  std::function<bool(const ftxui::Event &e)> key;
};
// the element, remembered as something to click on
ftxui::Element tuiHot(ftxui::Element e, hotTui h);
bool tuiFocused(const std::string &id);
void tuiFocus(const std::string &id);

// --- a menu that drops at x, y of the terminal
void tuiPopupMenu(const std::vector<Ui::MenuItem> &items, int x, int y);
// a list of lines, one of which is picked
void tuiChoose(const std::vector<std::string> &labels, int current, int x, int y,
            const std::function<void(int)> &picked);

// a line to type, asked in a box of its own; false when given up
bool tuiAsk(const std::string &question, std::string &value);

// --- sizes: the descriptions speak in em, a terminal in cells
int tuiCells(double em);

// --- keys as Ui::Shortcut says them
bool tuiUiKey(const ftxui::Event &e, int &key, unsigned &mods);

// --- a line of text being edited: the one focused
struct editTui {
  std::string id, text;
  std::size_t cursor = 0;
  // what the text is written through when it is left: true for Return
  std::function<void(bool enter)> commit;
};
editTui &tuiEdit();
// the keys of a line of text; true when the event was one; enter tells
// Return
bool tuiEditKey(const ftxui::Event &e, bool &enter);

// --- how the picture of the scene is shown, see graphicsTui.cpp: in half
// blocks, or at the resolution of the terminal through the graphics
// protocol of kitty or sixel
enum class graphicsTui { Blocks, Kitty, Sixel };
graphicsTui tuiGraphics();
// the pixels of a cell, when the terminal says
bool tuiCellPixels(int &width, int &height);
// the bitmap the scene hands over, at cell x, y of the terminal, cols by
// rows cells
void tuiShowPicture(const unsigned char *bmp, int w, int h, int x, int y,
                 int cols, int rows);
void tuiClearPictures();
// kitty keeps the image of a placement taken away, to be placed again
// without sending it: false where it cannot be
void tuiHidePicture();
bool tuiPlaceAgain(int x, int y, int cols, int rows);

// --- fields, forms and trees, see fieldTui.cpp, treeTui.cpp and dialogTui.cpp

// the widget of a field, `width` cells wide (0: its own); after runs once
// the user changed something
ftxui::Element tuiFieldWidget(const Ui::Field &f, const std::string &id,
                              int width, const std::function<void()> &after);
ftxui::Element tuiButtonWidget(const Ui::Button &b, const std::string &id,
                               const std::function<void()> &after);

struct treeTui {
  std::map<std::string, bool> open;
  int scroll = 0;
  bool built = false;
};
ftxui::Element tuiTree(const Ui::Tree &t, treeTui &state, bool picks,
                      const std::string &id, int height,
                      const std::function<void()> &after);

struct dialogTui {
  std::string pane;
  int scroll = 0;
};
ftxui::Element tuiForm(const Ui::Form &f, dialogTui &state);


// how big the scene writes its text, see SceneTui.cpp: a pixel of the picture
// is a quarter of a character in half blocks, a pixel of the screen otherwise
void tuiSceneScale(float uiScale, int screenHeight);

#endif
