// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GmshConfig.h"
#if !defined(HAVE_NO_STDINT_H)
#include <stdint.h>
#elif defined(HAVE_NO_INTPTR_T)
typedef unsigned long intptr_t;
#endif
#include <vector>
#include <string.h>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Help_View.H>
#include "FlGui.h"
#include "drawContext.h"
#include "pluginWindow.h"
#include "paletteWindow.h"
#include "PView.h"
#include "PluginManager.h"
#include "Plugin.h"
#include "GModel.h"
#include "MVertex.h"
#include "Context.h"
#include "GeoStringInterface.h"
#include "StringUtils.h"

#define MAX_PLUGIN_OPTIONS 50
class PluginDialogBox{
 public:
  Fl_Group *group;
  Fl_Value_Input *value[MAX_PLUGIN_OPTIONS];
  Fl_Input *input[MAX_PLUGIN_OPTIONS];
};

void plugin_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->plugins->show((intptr_t)data);
}

static void plugin_input_value_cb(Fl_Widget *w, void *data)
{
  double (*f)(int, int, double) = (double (*)(int, int, double)) data;
  Fl_Value_Input *input = (Fl_Value_Input*) w;
  f(-1, 0, input->value());
}

static void plugin_input_cb(Fl_Widget *w, void *data)
{
  std::string (*f)(int, int, std::string) = (std::string (*)(int, int, std::string)) data;
  Fl_Input *input = (Fl_Input*) w;
  f(-1, 0, input->value());
}

static void plugin_browser_cb(Fl_Widget *w, void *data)
{
  // get selected plugin
  GMSH_Plugin *p = 0;
  for(int i = 1; i <= FlGui::instance()->plugins->browser->size(); i++) {
    if(FlGui::instance()->plugins->browser->selected(i)) {
      p = (GMSH_Plugin*)FlGui::instance()->plugins->browser->data(i);
      break;
    }
  }
  if(!p) return;

  // get first first selected view
  int iView = -1;
  for(int i = 1; i <= FlGui::instance()->plugins->view_browser->size(); i++) {
    if(FlGui::instance()->plugins->view_browser->selected(i)) {
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
  for(int i = 1; i <= FlGui::instance()->plugins->browser->size(); i++)
    ((GMSH_Plugin*)FlGui::instance()->plugins->browser->data(i))->dialogBox->group->hide();
  p->dialogBox->group->show();
}

static void add_scripting(GMSH_PostPlugin *p, PView *view)
{
  if(!FlGui::instance()->plugins->record->value()) return;

  std::string fileName;
  int oldIndex = -1;
  if(view){
    for(int i = 0; i < p->getNbOptions(); i++){
      if(std::string(p->getOption(i)->str) == "View") {
        oldIndex = (int)(p->getOption(i)->def);
        p->getOption(i)->def = view->getIndex();
      }
    }
    fileName = view->getData()->getFileName();
  }
  else
    fileName = GModel::current()->getFileName();

  fileName += ".opt";
  FILE *fp = fopen(fileName.c_str(), "a");
  if(!fp){
    Msg::Error("Could not open file '%s'", fileName.c_str());
  }
  else{
    fprintf(fp, "%s", p->serialize().c_str());
    fclose(fp);
  }

  if(view && oldIndex != -1){
    for(int i = 0; i < p->getNbOptions(); i++){
      if(std::string(p->getOption(i)->str) == "View"){
        p->getOption(i)->def = oldIndex;
      }
    }
  }
}

static void plugin_run_cb(Fl_Widget *w, void *data)
{
  GMSH_PostPlugin *p = (GMSH_PostPlugin*)data;

  // get the values from the GUI
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

  // run on all selected views
  bool no_view_selected = true;
  for(int i = 1; i <= FlGui::instance()->plugins->view_browser->size(); i++) {
    if(FlGui::instance()->plugins->view_browser->selected(i)) {
      no_view_selected = false;
      try{
        if(i - 1 >= 0 && i - 1 < (int)PView::list.size()){
          PView *view = PView::list[i - 1];
          if(view->getData()->isRemote())
            p->executeRemote(view);
          else{
            p->execute(view);
            add_scripting(p, view);
          }
        }
        else{
          p->execute(0);
          add_scripting(p, 0);
        }
      }
      catch(GMSH_Plugin * err) {
        char tmp[256];
        p->catchErrorMessage(tmp);
        Msg::Warning("%s", tmp);
      }
    }
  }
  if(no_view_selected) p->execute(0);

  FlGui::instance()->updateViews();
  GMSH_Plugin::draw = 0;
  drawContext::global()->draw();
}

static void plugin_create_new_view_cb(Fl_Widget *w, void *data)
{
  if(GModel::current()->getMeshStatus() < 1){
    Msg::Error("No mesh available to create the view: please mesh your model!");
    return;
  }
  std::map<int, std::vector<double> > d;
  std::vector<GEntity*> entities;
  GModel::current()->getEntities(entities);
  for(unsigned int i = 0; i < entities.size(); i++){
    for(unsigned int j = 0; j < entities[i]->mesh_vertices.size(); j++){
      MVertex *v = entities[i]->mesh_vertices[j];
      d[v->getNum()].push_back(0.);
    }
  }
  PView *view = new PView("New view", "NodeData", GModel::current(), d);
  view->setChanged(true);
  FlGui::instance()->updateViews();
  drawContext::global()->draw();
}

void pluginWindow::_createDialogBox(GMSH_Plugin *p, int x, int y,
                                    int width, int height)
{
  p->dialogBox = new PluginDialogBox;
  p->dialogBox->group = new Fl_Group(x, y, width, height);

  Fl_Box *title = new Fl_Box(x, y, width, BH, strdup(p->getName().c_str()));
  title->labelfont(FL_BOLD);
  title->labelsize(FL_NORMAL_SIZE + 3);
  title->align(FL_ALIGN_INSIDE);

  Fl_Box *help = new Fl_Box
    (x, y + BH, width, BH + WB, strdup(p->getShortHelp().c_str()));
  help->align(FL_ALIGN_WRAP | FL_ALIGN_CLIP | FL_ALIGN_TOP | FL_ALIGN_INSIDE);

  int top = 2 * BH + WB;

  {
    Fl_Tabs *o = new Fl_Tabs(x, y + top, width, height - top);
    {
      Fl_Group *g = new Fl_Group
        (x, y + top + BH, width, height - top - BH, "Options");

      Fl_Scroll *s = new Fl_Scroll
        (x + WB, y + top + BH + WB, width - 2 * WB, height - top - 2 * BH - 3 * WB);

      int m = p->getNbOptionsStr();
      if(m > MAX_PLUGIN_OPTIONS) m = MAX_PLUGIN_OPTIONS;

      int n = p->getNbOptions();
      if(n > MAX_PLUGIN_OPTIONS) n = MAX_PLUGIN_OPTIONS;

      int k = 0;
      for(int i = 0; i < m; i++) {
        StringXString *sxs = p->getOptionStr(i);
        p->dialogBox->input[i] = new Fl_Input
          (x + WB, y + top + (k + 1) * BH + WB, IW, BH, sxs->str);
        p->dialogBox->input[i]->align(FL_ALIGN_RIGHT);
        p->dialogBox->input[i]->value(sxs->def.c_str());
        k++;
      }
      for(int i = 0; i < n; i++) {
        StringXNumber *sxn = p->getOption(i);
        p->dialogBox->value[i] = new Fl_Value_Input
          (x + WB, y + top + (k + 1) * BH + WB, IW, BH, sxn->str);
        p->dialogBox->value[i]->align(FL_ALIGN_RIGHT);
        p->dialogBox->value[i]->value(sxn->def);
        k++;
      }

      s->end();

      Fl_Return_Button *run = new Fl_Return_Button
        (x + width - BB - WB, y + height - BH - WB, BB, BH, "Run");
      run->callback(plugin_run_cb, (void*)p);

      g->resizable(new Fl_Box(x + 2 * WB, y + top + 2 * BH, 1, 1));
      g->end();
      o->resizable(g);
    }
    {
      Fl_Group *g = new Fl_Group
        (x, y + top + BH, width, height - top - BH, "Help");

      Fl_Help_View *o = new Fl_Help_View
        (x + WB, y + top + BH + WB, width - 2 * WB, height - top - 2 * BH - 3 * WB);
      std::string help = p->getHelp();
      ConvertToHTML(help);
      help += std::string("<p><em>Author(s): ") + p->getAuthor() + "</em>";
      o->value(help.c_str());
      o->textfont(FL_HELVETICA);
      o->textsize(FL_NORMAL_SIZE);

      g->resizable(new Fl_Box(x + 2 * WB, y + top + 2 * BH, 1, 1));
      g->end();
    }
    o->end();
  }

  p->dialogBox->group->end();
  p->dialogBox->group->hide();
}

pluginWindow::pluginWindow(int deltaFontSize)
{
  FL_NORMAL_SIZE -= deltaFontSize;

  int width0 = 34 * FL_NORMAL_SIZE + WB;
  int height0 = 12 * BH + 4 * WB;
  int L1 = 10 * FL_NORMAL_SIZE, L2 = 6 * FL_NORMAL_SIZE;

  int width = (CTX::instance()->pluginSize[0] < width0) ? width0 : 
    CTX::instance()->pluginSize[0];
  int height = (CTX::instance()->pluginSize[1] < height0) ? height0 : 
    CTX::instance()->pluginSize[1];

  win = new paletteWindow
    (width, height, CTX::instance()->nonModalWindows ? true : false, "Plugins");
  win->box(GMSH_WINDOW_BOX);

  browser = new Fl_Hold_Browser(WB, WB, L1, height - 2 * WB);
  browser->callback(plugin_browser_cb);

  view_browser = new Fl_Multi_Browser(WB + L1, WB, L2, height - 2 * WB - BH);
  view_browser->has_scrollbar(Fl_Browser_::VERTICAL);
  view_browser->callback(plugin_browser_cb);

  Fl_Button *b = new Fl_Button(WB + L1, height - WB - BH, L2, BH, "New view");
  b->callback(plugin_create_new_view_cb);
  b->tooltip("Create new post-processing dataset based on current mesh");

  for(std::map<std::string, GMSH_Plugin*>::iterator it = PluginManager::
        instance()->begin(); it != PluginManager::instance()->end(); ++it) {
    GMSH_Plugin *p = it->second;
    if(p->getType() == GMSH_Plugin::GMSH_POST_PLUGIN) {
      browser->add(p->getName().c_str(), p);
      _createDialogBox(p, 2 * WB + L1 + L2, WB, width - L1 - L2 - 3 * WB, 
                       height - 2 * WB);
      // select first plugin by default
      if(it == PluginManager::instance()->begin()){
        browser->select(1);
        p->dialogBox->group->show();
      }
    }
  }

  record = new Fl_Check_Button
    (L1 + L2 + 3 * WB, height - BH - 2 * WB, BB, BH, "Record");
  record->type(FL_TOGGLE_BUTTON);
  record->tooltip("Append scripting command to file options when plugin is run");
  
  win->resizable(new Fl_Box(L1 + L2 + 2 * BH, height - 4 * BH, 10, 10));
  win->size_range(width0, height0);

  win->position(CTX::instance()->pluginPosition[0], CTX::instance()->pluginPosition[1]);
  win->end();

  FL_NORMAL_SIZE += deltaFontSize;
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

