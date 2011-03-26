// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
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
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Double_Window.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Preferences.H>
#include "FlGui.h"
#include "paletteWindow.h"
#include "GmshDefines.h"
#include "OpenFile.h"
#include "CreateFile.h"
#include "Options.h"
#include "drawContext.h"
#include "GModel.h"
#include "Context.h"

// Arrow editor

int arrowEditor(const char *title, double &a, double &b, double &c)
{
  struct _editor{
    Fl_Window *window;
    Fl_Value_Slider *sa, *sb, *sc;
    Fl_Button *apply, *cancel;
  };
  static _editor *editor = 0;

  if(!editor){
    editor = new _editor;
    editor->window = new paletteWindow
      (2 * BB + 3 * WB, 4 * BH + 3 * WB, CTX::instance()->nonModalWindows ? true : false);
    editor->sa = new Fl_Value_Slider(WB, WB, BB, BH, "Head radius");
    editor->sa->type(FL_HOR_SLIDER);
    editor->sa->align(FL_ALIGN_RIGHT);
    editor->sb = new Fl_Value_Slider(WB, WB + BH, BB, BH, "Stem length");
    editor->sb->type(FL_HOR_SLIDER);
    editor->sb->align(FL_ALIGN_RIGHT);
    editor->sc = new Fl_Value_Slider(WB, WB + 2 * BH, BB, BH, "Stem radius");
    editor->sc->type(FL_HOR_SLIDER);
    editor->sc->align(FL_ALIGN_RIGHT);
    editor->apply = new Fl_Return_Button(WB, 2 * WB + 3 * BH, BB, BH, "Apply");
    editor->cancel = new Fl_Button(2 * WB + BB, 2 * WB + 3 * BH, BB, BH, "Cancel");
    editor->window->end();
    editor->window->hotspot(editor->window);
  }
  
  editor->window->label(title);
  editor->sa->value(a);
  editor->sb->value(b);
  editor->sc->value(c);
  editor->window->show();

  while(editor->window->shown()){
    Fl::wait();
    for (;;) {
      Fl_Widget* o = Fl::readqueue();
      if (!o) break;
      if (o == editor->apply) {
        a = editor->sa->value();
        b = editor->sb->value();
        c = editor->sc->value();
        return 1;
      }
      if (o == editor->window || o == editor->cancel){
        editor->window->hide();
        return 0;
      }
    }
  }
  return 0;
}

// Perspective editor (aka z-clipping planes factor slider)

class Release_Slider : public Fl_Value_Slider {
  int handle(int event)
  {
    switch (event) {
    case FL_RELEASE: 
      if(window())
        window()->hide();
      return 1;
    default:
      return Fl_Value_Slider::handle(event);
    }
  };
public:
  Release_Slider(int x, int y, int w, int h, const char *l=0)
    : Fl_Value_Slider(x, y, w, h, l) {}
};

static void persp_change_factor(Fl_Widget* w, void* data)
{
  opt_general_clip_factor(0, GMSH_SET|GMSH_GUI, ((Fl_Value_Slider*)w)->value());
  drawContext::global()->draw();
}

int perspectiveEditor()
{
  struct _editor{
    Fl_Menu_Window *window;
    Release_Slider *sa;
  };
  static _editor *editor = 0;

  if(!editor){
    editor = new _editor;
    editor->window = new Fl_Menu_Window(200, 20);
    if(CTX::instance()->nonModalWindows) editor->window->set_non_modal();
    editor->sa = new Release_Slider(0, 0, 200, 20);
    editor->sa->type(FL_HOR_NICE_SLIDER);
    editor->sa->minimum(0.1);
    editor->sa->maximum(20);
    editor->sa->callback(persp_change_factor);
    editor->window->border(0);
    editor->window->end();
  }

  editor->window->hotspot(editor->window);
  editor->sa->value(CTX::instance()->clipFactor);

  if(editor->window->non_modal() && !editor->window->shown())
    editor->window->show(); // fix ordering
  editor->window->show();
  return 0;
}

// Mesh element size editor

static void mesh_size_factor(Fl_Widget* w, void* data)
{
  opt_mesh_lc_factor(0, GMSH_SET|GMSH_GUI, ((Fl_Value_Slider*)w)->value());
  drawContext::global()->draw();
}

int meshSizeEditor()
{
  struct _editor{
    Fl_Menu_Window *window;
    Release_Slider *sa;
  };
  static _editor *editor = 0;

  if(!editor){
    editor = new _editor;
    editor->window = new Fl_Menu_Window(200, 20);
    if(CTX::instance()->nonModalWindows) editor->window->set_non_modal();
    editor->sa = new Release_Slider(0, 0, 200, 20);
    editor->sa->type(FL_HOR_NICE_SLIDER);
    editor->sa->minimum(0.01);
    editor->sa->maximum(2.5);
    editor->sa->callback(mesh_size_factor);
    editor->window->border(0);
    editor->window->end();
  }

  editor->window->hotspot(editor->window);
  editor->sa->value(CTX::instance()->mesh.lcFactor);

  if(editor->window->non_modal() && !editor->window->shown())
    editor->window->show(); // fix ordering
  editor->window->show();
    return 0;

  return CTX::instance()->mesh.lcFactor;
}

// Model chooser

static void model_switch_cb(Fl_Widget* w, void *data)
{
  Fl_Select_Browser *b = (Fl_Select_Browser *)w;
  if(b->value()){
    GModel::current(b->value() - 1);
    SetBoundingBox();
    for(unsigned int i = 0; i < GModel::list.size(); i++)
      GModel::list[i]->setVisibility(0);
    GModel::current()->setVisibility(1);
  }
  if(w->window()) w->window()->hide();
  CTX::instance()->mesh.changed = ENT_ALL;
  FlGui::instance()->setGraphicTitle(GModel::current()->getFileName());
  FlGui::instance()->resetVisibility();
  drawContext::global()->draw();
}

int modelChooser()
{
  struct _menu{
    Fl_Menu_Window *window;
    Fl_Hold_Browser *browser;
    Fl_Check_Button *butt;
  };
  static _menu *menu = 0;

  const int WW = 200;

  if(!menu){
    menu = new _menu;
    menu->window = new Fl_Menu_Window(WW, 6 * BH);
    if(CTX::instance()->nonModalWindows) menu->window->set_non_modal();
    menu->window->border(0);
    Fl_Box *l = new Fl_Box(0, 0, WW, BH, "Select active model:");
    l->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
    menu->browser = new Fl_Hold_Browser(0, BH, WW, 5 * BH);
    menu->browser->callback(model_switch_cb);
    menu->browser->when(FL_WHEN_RELEASE_ALWAYS);
    menu->window->end();
  }

  menu->window->hotspot(menu->window);
  menu->browser->clear();
  for(unsigned int i = 0; i < GModel::list.size(); i++){
    char tmp[256];
    sprintf(tmp, "Model [%d] <<%s>>", i, GModel::list[i]->getName().c_str());
    menu->browser->add(tmp);
    if(GModel::list[i] == GModel::current()) menu->browser->value(i + 1);
  }

  if(menu->window->non_modal() && !menu->window->shown())
    menu->window->show(); // fix ordering
  menu->window->show();
  return 0;
}

// Connection and pattern choosers

class historyBrowser : public Fl_Hold_Browser {
  int handle(int event)
  { 
    switch (event) {
    case FL_SHORTCUT:
    case FL_KEYBOARD:
      if(Fl::test_shortcut(FL_Delete) || Fl::test_shortcut(FL_BackSpace)){
        int i = value();
        if(i){
          remove(i);
          if(i <= size()) select(i);
          else if(i > 1) select(i - 1);
        }
        return 1;
      }
      break;
    }
    return Fl_Hold_Browser::handle(event);
  };
 public:
  historyBrowser(int x, int y, int w, int h, const char *l=0)
    : Fl_Hold_Browser(x, y, w, h, l) {}
};

class historyChooser{
 private:
  std::string _prefix, _label, _commandLabel, _defaultCommand, _okLabel;
 public:
  Fl_Double_Window *window;
  Fl_Input *input;
  historyBrowser *browser;
  Fl_Return_Button *ok;
  Fl_Button *cancel;
 public:
  historyChooser(const std::string &prefix, const std::string &label,
                 const std::string &commandLabel, const std::string &defaultCommand,
                 const std::string &okLabel)
    : _prefix(prefix), _label(label), _commandLabel(commandLabel), 
      _defaultCommand(defaultCommand), _okLabel(okLabel)
  {
    int h = 4 * WB + 10 * BH, w = 3 * BB + 2 * WB;
    window = new Fl_Double_Window(w, h);
    window->set_modal();
    window->label(_label.c_str());
    Fl_Box *b1 = new Fl_Box(WB, WB, w, BH, _commandLabel.c_str());
    b1->align(FL_ALIGN_INSIDE|FL_ALIGN_LEFT);
    input = new Fl_Input(WB, WB + BH, w - 2 * WB, BH);
    Fl_Box *b2 = new Fl_Box(WB, 2 * WB + 2 * BH, w, BH, "History:");
    b2->align(FL_ALIGN_INSIDE|FL_ALIGN_LEFT);
    browser = new historyBrowser
      (WB, 2 * WB + 3 * BH, w - 2 * WB, h - 4 * BH - 4 * WB);
    cancel = new Fl_Button
      (w - 2 * WB - 2 * BB, h - WB - BH, BB, BH, "Cancel");
    ok = new Fl_Return_Button
      (w - WB - BB, h - WB - BH, BB, BH, _okLabel.c_str());
    Fl_Box *b3 = new Fl_Box(WB, h - WB - BB, WB, WB);
    b3->hide();
    window->resizable(b3);
  }
  void save(Fl_Preferences &prefs)
  {
    for(int i = 0; i < 100; i++){
      char name[256];
      sprintf(name, "%s%02d", _prefix.c_str(), i);
      if(i < browser->size())
        prefs.set(name, browser->text(i + 1));
      else if(prefs.entryExists(name)) 
        prefs.deleteEntry(name);
    }
    prefs.set((_prefix + "PositionX").c_str(), window->x());
    prefs.set((_prefix + "PositionY").c_str(), window->y());
    prefs.set((_prefix + "Width").c_str(), window->w());
    prefs.set((_prefix + "Height").c_str(), window->h());
  }
  std::string run()
  {
    Fl_Preferences prefs(Fl_Preferences::USER, "fltk.org", "gmsh");
    int x = 100, y = 100, h = 4 * WB + 10 * BH, w = 3 * BB + 2 * WB;
    prefs.get((_prefix + "PositionX").c_str(), x, x);
    prefs.get((_prefix + "PositionY").c_str(), y, y);
    prefs.get((_prefix + "Width").c_str(), w, w);
    prefs.get((_prefix + "Height").c_str(), h, h);
    window->resize(x, y, w, h);
    int old = browser->value();
    browser->clear();
    for (int i = 0; i < 100; i++) {
      char name[256], value[1024];
      sprintf(name, "%s%02d", _prefix.c_str(), i);
      if(prefs.entryExists(name)){
        prefs.get(name, value, "", sizeof(value));
        browser->add(value);
      }
    }
    int n = browser->size();
    if(n){
      if(old > 0 && old <= n)
        input->value(browser->text(old));
      else
        input->value(browser->text(1));
    }
    else
      input->value(_defaultCommand.c_str());
    window->show();
    while(window->shown()){
      Fl::wait();
      for (;;) {
        Fl_Widget* o = Fl::readqueue();
        if (!o) break;
        if (o == ok) {
          if(strlen(input->value())){
            // insert choosen value at the top of the history
            for(int i = 0; i < browser->size(); i++){
              if(!strcmp(input->value(), browser->text(i + 1))){
                browser->remove(i + 1);
                break;
              }
            }
            browser->insert(1, input->value());
          }
          save(prefs);
          window->hide();
          return input->value();
        }
        if (o == window || o == cancel){
          save(prefs);
          window->hide();
          return "";
        }
      }
    }
    return "";
  }
};

static historyChooser *_connectionChooser = 0;
static void connection_select_cb(Fl_Widget* w, void *data)
{
  int i = _connectionChooser->browser->value();
  if(i) _connectionChooser->input->value(_connectionChooser->browser->text(i));
}

std::string connectionChooser()
{
  if(!_connectionChooser){
    _connectionChooser = new historyChooser
      ("connection", "Remote Start", "Command:", "./gmsh ../tutorial/view3.pos",
       "Run");
    _connectionChooser->browser->callback(connection_select_cb);
  }
  return _connectionChooser->run();
}

static historyChooser *_patternChooser = 0;
static void pattern_select_cb(Fl_Widget* w, void *data)
{
  int i = _patternChooser->browser->value();
  if(i) _patternChooser->input->value(_patternChooser->browser->text(i));
}

std::string patternChooser()
{
  if(!_patternChooser){
    _patternChooser = new historyChooser
      ("pattern", "Watch Pattern", "Pattern:", "output/*.msh", "Watch");
    _patternChooser->browser->callback(pattern_select_cb);
  }
  return _patternChooser->run();
}
