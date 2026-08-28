// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Stephen Guzik
//

#include <stdio.h>
#include <string.h>
#include <FL/Fl_Value_Slider.H>
#include <FL/Fl_Menu_Window.H>
#include <FL/Fl_Select_Browser.H>
#include <FL/Fl_Toggle_Button.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Hold_Browser.H>
#include <FL/Fl_Input_Choice.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Text_Editor.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Preferences.H>
#include "FlGui.h"
#include "inputValue.h"
#include "paletteWindow.h"
#include "GmshDefines.h"
#include "OpenFile.h"
#include "CreateFile.h"
#include "Options.h"
#include "drawContext.h"
#include "GModel.h"
#include "Context.h"
#include "PView.h"

// What is left of this file: the two little windows the ONELAB range widgets
// of the FLTK module tree open, which is FLTK's own. The chooser of one
// option, the arrow editor and the two command choosers were the rest of it;
// they are described once in src/common/GuiPrompts.cpp now, and both
// interfaces build them.

int simpleTextDisplay(const char *title, const std::string &text)
{
  struct _display {
    Fl_Window *window;
    Fl_Text_Buffer *buff;
    Fl_Text_Display *disp;
  };
  static _display *display = nullptr;

  if(!display) {
    display = new _display;
    display->window =
      new paletteWindow(4 * BB + 2 * WB, 5 * BH + 2 * WB,
                        CTX::instance()->nonModalWindows ? true : false);
    display->buff = new Fl_Text_Buffer();
    display->disp = new Fl_Text_Display(WB, WB, 4 * BB, 5 * BH);
    display->disp->buffer(display->buff);
    display->disp->wrap_mode(Fl_Text_Display::WRAP_AT_BOUNDS, 0);
    display->window->end();
    display->window->resizable(display->disp);
  }
  display->window->label(title);
  display->buff->text(text.c_str());
  display->window->hotspot(display->window);
  display->window->show();

  while(display->window->shown()) {
    Fl::wait();
    for(;;) {
      Fl_Widget *o = Fl::readqueue();
      if(!o) break;
      if(o == display->window) {
        display->window->hide();
        return 0;
      }
    }
  }
  return 0;
}

int simpleTextEditor(const char *title, const std::string &help,
                     std::string &text)
{
  struct _editor {
    Fl_Window *window;
    Fl_Text_Buffer *buff;
    Fl_Text_Editor *edit;
    Fl_Button *apply, *cancel;
    Fl_Box *help;
    char *help_text;
  };
  static _editor *editor = nullptr;

  if(!editor) {
    editor = new _editor;
    editor->window =
      new paletteWindow(4 * BB + 2 * WB, 7 * BH + 3 * WB,
                        CTX::instance()->nonModalWindows ? true : false);
    editor->help_text = strdup(help.c_str());
    editor->help = new Fl_Box(WB, WB / 2, 4 * BB, BH, editor->help_text);
    editor->help->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
    editor->buff = new Fl_Text_Buffer();
    editor->edit = new Fl_Text_Editor(WB, WB + BH, 4 * BB, 5 * BH);
    editor->edit->buffer(editor->buff);
    editor->edit->wrap_mode(Fl_Text_Editor::WRAP_AT_BOUNDS, 0);
    editor->apply = new Fl_Return_Button
      (4 * BB + WB - BB, 2 * WB + 6 * BH, BB, BH, "Apply");
    editor->cancel = new Fl_Button
      (4 * BB - 2 * BB, 2 * WB + 6 * BH, BB, BH, "Cancel");
    Fl_Box *resize = new Fl_Box(WB, WB + BH, WB, WB);
    editor->window->end();
    editor->window->resizable(resize);
  }
  editor->window->label(title);
  editor->buff->text(text.c_str());
  editor->window->hotspot(editor->window);
  editor->window->show();

  while(editor->window->shown()) {
    Fl::wait();
    for(;;) {
      Fl_Widget *o = Fl::readqueue();
      if(!o) break;
      if(o == editor->apply) {
        char *t = editor->buff->text();
        text = t;
        free(t);
        editor->window->hide();
        return 1;
      }
      if(o == editor->window || o == editor->cancel) {
        editor->window->hide();
        return 0;
      }
    }
  }
  return 0;
}
