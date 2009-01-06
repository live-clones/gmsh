// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Stephen Guzik
//

#include <FL/Fl_Value_Slider.H>
#include <FL/Fl_Menu_Window.H>
#include <FL/Fl_Select_Browser.H>
#include <FL/Fl_Toggle_Button.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Hold_Browser.H>
#include <FL/Fl_Box.H>
#include "GUI.h"
#include "paletteWindow.h"
#include "GmshDefines.h"
#include "OpenFile.h"
#include "CreateFile.h"
#include "Options.h"
#include "Draw.h"
#include "GModel.h"
#include "Context.h"

extern Context_T CTX;

// Arrow editor

int arrow_editor(const char *title, double &a, double &b, double &c)
{
  struct _editor{
    Fl_Window *window;
    Fl_Value_Slider *sa, *sb, *sc;
    Fl_Button *apply, *cancel;
  };
  static _editor *editor = NULL;

  if(!editor){
    editor = new _editor;
    editor->window = new paletteWindow
      (2 * BB + 3 * WB, 4 * BH + 3 * WB, CTX.non_modal_windows);
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

static void persp_change_factor(Fl_Widget* w, void* data)
{
  opt_general_clip_factor(0, GMSH_SET|GMSH_GUI, ((Fl_Slider*)w)->value());
  Draw();
}

class Release_Slider : public Fl_Slider {
  int handle(int event){ 
    switch (event) {
    case FL_RELEASE: 
      if(window())
        window()->hide();
      return 1;
    default:
      return Fl_Slider::handle(event);
    }
  };
public:
  Release_Slider(int x, int y, int w, int h, const char *l=0)
    : Fl_Slider(x, y, w, h, l) {}
};

int perspective_editor()
{
  struct _editor{
    Fl_Menu_Window *window;
    Release_Slider *sa;
  };
  static _editor *editor = NULL;

  if(!editor){
    editor = new _editor;
    editor->window = new Fl_Menu_Window(20, 100);
    if(CTX.non_modal_windows) editor->window->set_non_modal();
    editor->sa = new Release_Slider(0, 0, 20, 100);
    editor->sa->type(FL_VERT_NICE_SLIDER);
    editor->sa->minimum(12);
    editor->sa->maximum(0.75);
    editor->sa->callback(persp_change_factor);
    editor->window->border(0);
    editor->window->end();
  }

  editor->window->hotspot(editor->window);
  editor->sa->value(CTX.clip_factor);

  if(editor->window->non_modal() && !editor->window->shown())
    editor->window->show(); // fix ordering
  editor->window->show();
  return 0;
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
  CTX.mesh.changed = ENT_ALL;
  GUI::instance()->setGraphicTitle(GModel::current()->getFileName());
  GUI::instance()->resetVisibility();
  Draw();
}

int model_chooser()
{
  struct _menu{
    Fl_Menu_Window *window;
    Fl_Hold_Browser *browser;
    Fl_Check_Button *butt;
  };
  static _menu *menu = NULL;

  const int WW = 200;

  if(!menu){
    menu = new _menu;
    menu->window = new Fl_Menu_Window(WW, 6 * BH);
    if(CTX.non_modal_windows) menu->window->set_non_modal();
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
    sprintf(tmp, "Model %d <<%s>>", i, GModel::list[i]->getName().c_str());
    menu->browser->add(tmp);
    if(GModel::list[i] == GModel::current()) menu->browser->value(i + 1);
  }

  if(menu->window->non_modal() && !menu->window->shown())
    menu->window->show(); // fix ordering
  menu->window->show();
  return 0;
}
