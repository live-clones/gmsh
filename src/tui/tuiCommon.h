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

namespace Tui {

  const Ui::Backend::Sources &sources();
  const Ui::Backend::Host &host();

  // run between two turns of the loop, never inside one: what it does may
  // turn the loop again
  void later(const std::function<void()> &what);
  // something changed that the next frame must show
  void dirty();

  // --- what can be clicked or focused this frame

  struct Hot {
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
  ftxui::Element hot(ftxui::Element e, Hot h);
  bool focused(const std::string &id);
  void focus(const std::string &id);

  // --- a menu that drops at x, y of the terminal
  void popup(const std::vector<Ui::MenuItem> &items, int x, int y);
  // a list of lines, one of which is picked
  void choose(const std::vector<std::string> &labels, int current, int x, int y,
              const std::function<void(int)> &picked);

  // a line to type, asked in a box of its own; false when given up
  bool ask(const std::string &question, std::string &value);

  // --- sizes: the descriptions speak in em, a terminal in cells
  int cells(double em);

  // --- keys as Ui::Shortcut says them
  bool uiKey(const ftxui::Event &e, int &key, unsigned &mods);

  // --- a line of text being edited: the one focused
  struct Edit {
    std::string id, text;
    std::size_t cursor = 0;
    // what the text is written through when it is left: true for Return
    std::function<void(bool enter)> commit;
  };
  Edit &edit();
  // the keys of a line of text; true when the event was one; enter tells
  // Return
  bool editKey(const ftxui::Event &e, bool &enter);

  // --- fields, forms and trees, see formTui.cpp

  // the widget of a field, `width` cells wide (0: its own); after runs once
  // the user changed something
  ftxui::Element field(const Ui::Field &f, const std::string &id, int width,
                       const std::function<void()> &after);
  ftxui::Element button(const Ui::Button &b, const std::string &id,
                        const std::function<void()> &after);

  struct TreeState {
    std::map<std::string, bool> open;
    int scroll = 0;
    bool built = false;
  };
  ftxui::Element tree(const Ui::Tree &t, TreeState &state, bool picks,
                      const std::string &id, int height,
                      const std::function<void()> &after);

  struct FormState {
    std::string pane;
    int scroll = 0;
  };
  ftxui::Element form(const Ui::Form &f, FormState &state);

} // namespace Tui

#endif
