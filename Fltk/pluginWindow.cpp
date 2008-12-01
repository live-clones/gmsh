// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <vector>
#include <FL/Fl_Box.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Scroll.H>
#include "GUI.h"
#include "pluginWindow.h"
#include "shortcutWindow.h"
#include "PView.h"
#include "PluginManager.h"
#include "Plugin.h"
#include "Callbacks.h"
#include "Context.h"

extern Context_T CTX;

pluginWindow::pluginWindow(int fontsize) : _fontsize(fontsize)
{
  int width0 = 34 * _fontsize + WB;
  int height0 = 13 * BH + 5 * WB;

  int width = (CTX.plugin_size[0] < width0) ? width0 : CTX.plugin_size[0];
  int height = (CTX.plugin_size[1] < height0) ? height0 : CTX.plugin_size[1];

  win = new dialogWindow(width, height, CTX.non_modal_windows, "Plugins");
  win->box(GMSH_WINDOW_BOX);

  {
    Fl_Button *o = new Fl_Button
      (width - BB - WB, height - BH - WB, BB, BH, "Cancel");
    o->callback(view_plugin_cancel_cb);
  }
  {
    run = new Fl_Return_Button
      (width - 2 * BB - 2 * WB, height - BH - WB, BB, BH, "Run");
    run->callback(view_plugin_run_cb);
  }
  
  int L1 = (int)(0.3 * width), L2 = (int)(0.6 * L1);
  browser = new Fl_Hold_Browser(WB, WB, L1, height - 3 * WB - BH);
  browser->callback(view_plugin_browser_cb);

  view_browser = new Fl_Multi_Browser(WB + L1, WB, L2, height - 3 * WB - BH);
  view_browser->has_scrollbar(Fl_Browser_::VERTICAL);
  view_browser->callback(view_plugin_browser_cb);

  for(GMSH_PluginManager::iter it = GMSH_PluginManager::instance()->begin();
      it != GMSH_PluginManager::instance()->end(); ++it) {
    GMSH_Plugin *p = (*it).second;
    if(p->getType() == GMSH_Plugin::GMSH_POST_PLUGIN) {
      char name[256];
      p->getName(name);
      browser->add(name, p);
      createDialogBox(p, 2 * WB + L1 + L2, WB, width - L1 - L2 - 3 * WB, 
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
    view_plugin_browser_cb(NULL, NULL);
  }
  win->show();
}

void pluginWindow::createDialogBox(GMSH_Plugin *p, int x, int y, int width, int height)
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

  view_plugin_browser_cb(NULL, NULL);
}
