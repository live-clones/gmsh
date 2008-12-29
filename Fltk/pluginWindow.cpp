// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <vector>
#include <FL/Fl_Box.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Scroll.H>
#include "GUI.h"
#include "Draw.h"
#include "pluginWindow.h"
#include "shortcutWindow.h"
#include "PView.h"
#include "PluginManager.h"
#include "Plugin.h"
#include "Context.h"

extern Context_T CTX;

void plugin_cb(Fl_Widget *w, void *data)
{
  GUI::instance()->plugins->show((int)(long)data);
}

static void plugin_input_value_cb(Fl_Widget *w, void *data)
{
  double (*f)(int, int, double) = (double (*)(int, int, double)) data;
  Fl_Value_Input *input = (Fl_Value_Input*) w;
  f(-1, 0, input->value());
}

static void plugin_input_cb(Fl_Widget *w, void *data)
{
  const char* (*f)(int, int, const char*) = (const char* (*)(int, int, const char*)) data;
  Fl_Input *input = (Fl_Input*) w;
  f(-1, 0, input->value());
}

static void plugin_browser_cb(Fl_Widget *w, void *data)
{
  // get selected plugin
  GMSH_Plugin *p = 0;
  for(int i = 1; i <= GUI::instance()->plugins->browser->size(); i++) {
    if(GUI::instance()->plugins->browser->selected(i)) {
      p = (GMSH_Plugin*)GUI::instance()->plugins->browser->data(i);
      break;
    }
  }
  if(!p) return;

  // get first first selected view
  int iView = -1;
  for(int i = 1; i <= GUI::instance()->plugins->view_browser->size(); i++) {
    if(GUI::instance()->plugins->view_browser->selected(i)) {
      iView = i - 1;
      break;
    }
  }

  // set the Fl_Value_Input callbacks and configure the input value
  // fields (we get step, min and max by calling the option function
  // with action==1, 2 and 3, respectively)
  int n = p->getNbOptions();
  if(n > MAX_PLUGIN_OPTIONS) n = MAX_PLUGIN_OPTIONS;
  for(int i = 0; i < n; i++) {
    StringXNumber *sxn = p->getOption(i);
    if(sxn->function){
      p->dialogBox->value[i]->callback(plugin_input_value_cb, (void*)sxn->function);
      if(iView >= 0){
        p->dialogBox->value[i]->step(sxn->function(iView, 1, 0.));
        p->dialogBox->value[i]->minimum(sxn->function(iView, 2, 0.));
        p->dialogBox->value[i]->maximum(sxn->function(iView, 3, 0.));
      }
    }
  }

  // set the Fl_Input callbacks
  int m = p->getNbOptionsStr();
  if(m > MAX_PLUGIN_OPTIONS) m = MAX_PLUGIN_OPTIONS;
  for(int i = 0; i < m; i++) {
    StringXString *sxs = p->getOptionStr(i);
    if(sxs->function){
      p->dialogBox->input[i]->callback(plugin_input_cb, (void*)sxs->function);
    }
  }

  // hide all plugin groups except the selected one
  for(int i = 1; i <= GUI::instance()->plugins->browser->size(); i++)
    ((GMSH_Plugin*)GUI::instance()->plugins->browser->data(i))->dialogBox->group->hide();
  p->dialogBox->group->show();
}

static void plugin_run_cb(Fl_Widget *w, void *data)
{
  // get selected plugin
  GMSH_Post_Plugin *p = 0;
  for(int i = 1; i <= GUI::instance()->plugins->browser->size(); i++) {
    if(GUI::instance()->plugins->browser->selected(i)) {
      p = (GMSH_Post_Plugin*)GUI::instance()->plugins->browser->data(i);
      break;
    }
  }
  if(!p) return;

  if(p->dialogBox) { // get the values from the GUI
    int m = p->getNbOptionsStr();
    int n = p->getNbOptions();
    if(m > MAX_PLUGIN_OPTIONS) m = MAX_PLUGIN_OPTIONS;
    if(n > MAX_PLUGIN_OPTIONS) n = MAX_PLUGIN_OPTIONS;
    for(int i = 0; i < m; i++) {
      StringXString *sxs = p->getOptionStr(i);
      sxs->def = p->dialogBox->input[i]->value();
    }
    for(int i = 0; i < n; i++) {
      StringXNumber *sxn = p->getOption(i);
      sxn->def = p->dialogBox->value[i]->value();
    }
  }

  // run on all selected views
  bool no_view_selected = true;
  for(int i = 1; i <= GUI::instance()->plugins->view_browser->size(); i++) {
    if(GUI::instance()->plugins->view_browser->selected(i)) {
      no_view_selected = false;
      try{
        if(i - 1 >= 0 && i - 1 < (int)PView::list.size())
          p->execute(PView::list[i - 1]);
        else
          p->execute(0);
      }
      catch(GMSH_Plugin * err) {
        char tmp[256];
        p->catchErrorMessage(tmp);
        Msg::Warning("%s", tmp);
      }
    }
  }
  if(no_view_selected){
    p->execute(0);
  }

  GUI::instance()->updateViews();
  CTX.post.plugin_draw_function = NULL;
  Draw();
}

static void plugin_cancel_cb(Fl_Widget *w, void *data)
{
  GUI::instance()->plugins->win->hide();
  CTX.post.plugin_draw_function = NULL;
  Draw();
}

void pluginWindow::_createDialogBox(GMSH_Plugin *p, int x, int y,
                                    int width, int height)
{
  p->dialogBox = new PluginDialogBox;
  p->dialogBox->group = new Fl_Group(x, y, width, height);

  {
    Fl_Tabs *o = new Fl_Tabs(x, y, width, height);
    {
      Fl_Group *g = new Fl_Group
        (x, y + BH, width, height - BH, "Options");
      Fl_Scroll *s = new Fl_Scroll
        (x + WB, y + WB + BH, width - 2 * WB, height - BH - 2 * WB);

      int m = p->getNbOptionsStr();
      if(m > MAX_PLUGIN_OPTIONS) m = MAX_PLUGIN_OPTIONS;

      int n = p->getNbOptions();
      if(n > MAX_PLUGIN_OPTIONS) n = MAX_PLUGIN_OPTIONS;

      int k = 0;
      for(int i = 0; i < m; i++) {
        StringXString *sxs = p->getOptionStr(i);
        p->dialogBox->input[i] = new Fl_Input
          (x + WB, y + WB + (k + 1) * BH, IW, BH, sxs->str);
        p->dialogBox->input[i]->align(FL_ALIGN_RIGHT);
        p->dialogBox->input[i]->value(sxs->def);
        k++;
      }
      for(int i = 0; i < n; i++) {
        StringXNumber *sxn = p->getOption(i);
        p->dialogBox->value[i] = new Fl_Value_Input
          (x + WB, y + WB + (k + 1) * BH, IW, BH, sxn->str);
        p->dialogBox->value[i]->align(FL_ALIGN_RIGHT);
        p->dialogBox->value[i]->value(sxn->def);
        k++;
      }

      s->end();
      g->end();
      o->resizable(g); // to avoid ugly resizing of tab labels
    }
    {
      Fl_Group *g = new Fl_Group(x, y + BH, width, height - BH, "About");

      Fl_Browser *o = new Fl_Browser
        (x + WB, y + WB + BH, width - 2 * WB, height - 2 * WB - BH);

      char name[1024], copyright[256], author[256], help[4096];
      p->getName(name);
      p->getInfos(author, copyright, help);

      o->add(" ");
      add_multiline_in_browser(o, "@c@b@.", name, false);
      o->add(" ");
      add_multiline_in_browser(o, "", help, false);
      o->add(" ");
      add_multiline_in_browser(o, "Author: ", author, false);
      add_multiline_in_browser(o, "Copyright (C) ", copyright, false);
      o->add(" ");

      g->end();
    }
    o->end();
  }

  p->dialogBox->group->end();
  p->dialogBox->group->hide();
}

pluginWindow::pluginWindow()
{
  int width0 = 34 * FL_NORMAL_SIZE + WB;
  int height0 = 13 * BH + 5 * WB;

  int width = (CTX.plugin_size[0] < width0) ? width0 : CTX.plugin_size[0];
  int height = (CTX.plugin_size[1] < height0) ? height0 : CTX.plugin_size[1];

  win = new dialogWindow(width, height, CTX.non_modal_windows, "Plugins");
  win->box(GMSH_WINDOW_BOX);

  {
    Fl_Button *o = new Fl_Button
      (width - BB - WB, height - BH - WB, BB, BH, "Cancel");
    o->callback(plugin_cancel_cb);
  }
  {
    run = new Fl_Return_Button
      (width - 2 * BB - 2 * WB, height - BH - WB, BB, BH, "Run");
    run->callback(plugin_run_cb);
  }
  
  int L1 = (int)(0.3 * width), L2 = (int)(0.6 * L1);
  browser = new Fl_Hold_Browser(WB, WB, L1, height - 3 * WB - BH);
  browser->callback(plugin_browser_cb);

  view_browser = new Fl_Multi_Browser(WB + L1, WB, L2, height - 3 * WB - BH);
  view_browser->has_scrollbar(Fl_Browser_::VERTICAL);
  view_browser->callback(plugin_browser_cb);

  for(GMSH_PluginManager::iter it = GMSH_PluginManager::instance()->begin();
      it != GMSH_PluginManager::instance()->end(); ++it) {
    GMSH_Plugin *p = (*it).second;
    if(p->getType() == GMSH_Plugin::GMSH_POST_PLUGIN) {
      char name[256];
      p->getName(name);
      browser->add(name, p);
      _createDialogBox(p, 2 * WB + L1 + L2, WB, width - L1 - L2 - 3 * WB, 
                       height - 3 * WB - BH);
      // select first plugin by default
      if(it == GMSH_PluginManager::instance()->begin()){
        browser->select(1);
        p->dialogBox->group->show();
      }
    }
  }
  
  Fl_Box *resize_box = new Fl_Box(3*WB + L1+L2, WB, WB, height - 3 * WB - BH);
  win->resizable(resize_box);
  win->size_range(width0, height0);

  win->position(CTX.plugin_position[0], CTX.plugin_position[1]);
  win->end();
}

void pluginWindow::show(int viewIndex)
{
  resetViewBrowser();
  if(viewIndex >= 0 && viewIndex < (int)PView::list.size()){
    view_browser->deselect();
    view_browser->select(viewIndex + 1);
    plugin_browser_cb(NULL, NULL);
  }
  win->show();
}

void pluginWindow::resetViewBrowser()
{
  // save selected state
  std::vector<int> state;
  for(int i = 0; i < view_browser->size(); i++){
    if(view_browser->selected(i + 1))
      state.push_back(1);
    else
      state.push_back(0);
  }

  char str[128];
  view_browser->clear();

  if(PView::list.size()){
    view_browser->activate();
    for(unsigned int i = 0; i < PView::list.size(); i++) {
      sprintf(str, "View [%d]", i);
      view_browser->add(str);
    }
    for(int i = 0; i < view_browser->size(); i++){
      if(i < (int)state.size() && state[i])
        view_browser->select(i + 1);
    }
  }
  else{
    view_browser->add("No Views");
    view_browser->deactivate();
  }

  plugin_browser_cb(NULL, NULL);
}
