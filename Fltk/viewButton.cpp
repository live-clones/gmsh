// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <FL/fl_ask.H>
#include "FlGui.h"
#include "drawContext.h"
#include "fileDialogs.h"
#include "optionWindow.h"
#include "pluginWindow.h"
#include "Context.h"
#include "GModel.h"
#include "PView.h"
#include "PViewData.h"
#include "PViewOptions.h"
#include "Options.h"
#include "OpenFile.h"
#include "Field.h"
#include "OS.h"
#include "onelabGroup.h"
#include "viewButton.h"

static void view_toggle_cb(Fl_Widget *w, void *data)
{
  int num = (intptr_t)data;
  viewButton *but = FlGui::instance()->onelab->getViewButton(num);
  if(but){
    opt_view_visible(num, GMSH_SET, but->value());
    drawContext::global()->draw();
  }
}

static void view_reload(int index)
{
  if(index >= 0 && index < (int)PView::list.size()){
    PView *p = PView::list[index];

    if(StatFile(p->getData()->getFileName())){
      Msg::Error("File '%s' does not exist", p->getData()->getFileName().c_str());
      return;
    }

    int n = PView::list.size();

    // FIXME: use fileIndex
    MergeFile(p->getData()->getFileName());

    if((int)PView::list.size() > n){ // we loaded a new view
      // delete old data and replace with new
      delete p->getData();
      p->setData(PView::list.back()->getData());
      PView::list.back()->setData(0);
      // delete new view
      delete PView::list.back();
      // in case the reloaded view has a different number of time steps
      if(p->getOptions()->timeStep > p->getData()->getNumTimeSteps() - 1)
        p->getOptions()->timeStep = 0;
      p->setChanged(true);
      FlGui::instance()->updateViews();
    }
  }
}

static void view_reload_cb(Fl_Widget *w, void *data)
{
  view_reload((intptr_t)data);
  drawContext::global()->draw();
}

static void view_reload_all_cb(Fl_Widget *w, void *data)
{
  for(unsigned int i = 0; i < PView::list.size(); i++)
    view_reload(i);
  drawContext::global()->draw();
}

static void view_reload_visible_cb(Fl_Widget *w, void *data)
{
  for(unsigned int i = 0; i < PView::list.size(); i++)
    if(opt_view_visible(i, GMSH_GET, 0))
      view_reload(i);
  drawContext::global()->draw();
}

static void view_remove_other_cb(Fl_Widget *w, void *data)
{
  if(PView::list.empty()) return;
  for(int i = PView::list.size() - 1; i >= 0; i--)
    if(i != (intptr_t)data) delete PView::list[i];
  FlGui::instance()->updateViews();
  drawContext::global()->draw();
}

static void view_remove_all_cb(Fl_Widget *w, void *data)
{
  if(PView::list.empty()) return;
  int mode = (intptr_t)data;
  if(mode == -1){ // remove all
    if(PView::list.empty()) return;
    while(PView::list.size()) delete PView::list[0];
  }
  else if(mode == -2){ // remove all visible
    for(int i = PView::list.size() - 1; i >= 0; i--)
      if(opt_view_visible(i, GMSH_GET, 0)) delete PView::list[i];
  }
  else if(mode == -3){ // remove all invisible
    for(int i = PView::list.size() - 1; i >= 0; i--)
      if(!opt_view_visible(i, GMSH_GET, 0)) delete PView::list[i];
  }
  else if(mode == -4){ // remove all empty
    for(int i = PView::list.size() - 1; i >= 0; i--)
      if(PView::list[i]->getData()->empty()) delete PView::list[i];
  }
  else if(mode >=0 && mode < (int)PView::list.size()){ // remove by name
    std::string name = PView::list[mode]->getData()->getName();
    for(int i = PView::list.size() - 1; i >= 0; i--)
      if(PView::list[i]->getData()->getName() == name) delete PView::list[i];
  }

  FlGui::instance()->updateViews();
  drawContext::global()->draw();
}

static void view_remove_cb(Fl_Widget *w, void *data)
{
  delete PView::list[(intptr_t)data];
  FlGui::instance()->updateViews();
  drawContext::global()->draw();
}

#if defined(HAVE_NATIVE_FILE_CHOOSER)
#  define TT "\t"
#  define NN "\n"
#else
#  define TT " ("
#  define NN ")\t"
#endif

static void view_save_cb(Fl_Widget *w, void *data)
{
  static const char *formats =
    "Gmsh Parsed" TT "*.pos" NN
    "Gmsh Mesh-based" TT "*.pos" NN
    "Gmsh Legacy ASCII" TT "*.pos" NN
    "Gmsh Legacy Binary" TT "*.pos" NN
    "MED" TT "*.rmed" NN
    "STL Surface" TT "*.stl" NN
    "Generic TXT" TT "*.txt" NN;

  PView *view = PView::list[(intptr_t)data];
 test:
  if(fileChooser(FILE_CHOOSER_CREATE, "Save As", formats,
                 view->getData()->getFileName().c_str())){
    std::string name = fileChooserGetName(1);
    if(CTX::instance()->confirmOverwrite) {
      if(!StatFile(name))
        if(!fl_choice("File '%s' already exists.\n\nDo you want to replace it?",
                      "Cancel", "Replace", 0, name.c_str()))
          goto test;
    }
    int format = 0;
    switch(fileChooserGetFilter()){
    case 0: format = 2; break;
    case 1: format = 5; break;
    case 2: format = 0; break;
    case 3: format = 1; break;
    case 4: format = 6; break;
    case 5: format = 3; break;
    case 6: format = 4; break;
    }
    view->write(name, format);
  }
}

#undef TT
#undef NN

static void view_alias_cb(Fl_Widget *w, void *data)
{
  new PView(PView::list[(intptr_t)data], false);
  FlGui::instance()->updateViews();
  drawContext::global()->draw();
}

static void view_alias_with_options_cb(Fl_Widget *w, void *data)
{
  new PView(PView::list[(intptr_t)data], true);
  FlGui::instance()->updateViews();
  drawContext::global()->draw();
}

static void view_combine_space_all_cb(Fl_Widget *w, void *data)
{
  PView::combine(false, 1, CTX::instance()->post.combineRemoveOrig);
  FlGui::instance()->updateViews();
  drawContext::global()->draw();
}

static void view_combine_space_visible_cb(Fl_Widget *w, void *data)
{
  PView::combine(false, 0, CTX::instance()->post.combineRemoveOrig);
  FlGui::instance()->updateViews();
  drawContext::global()->draw();
}

static void view_combine_space_by_name_cb(Fl_Widget *w, void *data)
{
  PView::combine(false, 2, CTX::instance()->post.combineRemoveOrig);
  FlGui::instance()->updateViews();
  drawContext::global()->draw();
}

static void view_combine_time_all_cb(Fl_Widget *w, void *data)
{
  PView::combine(true, 1, CTX::instance()->post.combineRemoveOrig);
  FlGui::instance()->updateViews();
  drawContext::global()->draw();
}

static void view_combine_time_visible_cb(Fl_Widget *w, void *data)
{
  PView::combine(true, 0, CTX::instance()->post.combineRemoveOrig);
  FlGui::instance()->updateViews();
  drawContext::global()->draw();
}

static void view_combine_time_by_name_cb(Fl_Widget *w, void *data)
{
  PView::combine(true, 2, CTX::instance()->post.combineRemoveOrig);
  FlGui::instance()->updateViews();
  drawContext::global()->draw();
}

static void view_all_visible_cb(Fl_Widget *w, void *data)
{
  int mode = (intptr_t)data;
  std::string name;
  if(mode >= 0) name = PView::list[mode]->getData()->getName();
  for(unsigned int i = 0; i < PView::list.size(); i++)
    opt_view_visible(i, GMSH_SET | GMSH_GUI,
                     (mode == -1) ? 1 :
                     (mode == -2) ? 0 :
                     (mode == -3) ? !opt_view_visible(i, GMSH_GET, 0) :
                     (name == PView::list[i]->getData()->getName()) ? 1 :
                     0);
  drawContext::global()->draw();
}

static void view_applybgmesh_cb(Fl_Widget *w, void *data)
{
  int index =  (intptr_t)data;
  if(index >= 0 && index < (int)PView::list.size())
    GModel::current()->getFields()->setBackgroundMesh(index);
}

viewButton::viewButton(int x, int y, int w, int h, int num)
  : Fl_Group(x,y,w,h)
{
  int popw = 4 * FL_NORMAL_SIZE + 3;

  PView *view = PView::list[num];
  PViewData *data = view->getData();
  PViewOptions *opt = view->getOptions();

  _toggle = new Fl_Light_Button(x, y, w - popw, h);
  _toggle->callback(view_toggle_cb, (void *)num);
  _toggle->align(FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
  _toggle->value(opt->visible);
  _toggle->copy_label(data->getName().c_str());
  strcpy(_tooltip, data->getFileName().c_str());
  _toggle->tooltip(_tooltip);
  sprintf(_arrow, "[%d]@#-1>", num);
  _butt = new Fl_Button(x + w - popw, y, popw, h, _arrow);
  _butt->align(FL_ALIGN_RIGHT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
  _butt->tooltip("Show view option menu (Shift+w)");

  _popup = new Fl_Menu_Button(x + w - popw, y, popw, h);
  _popup->type(Fl_Menu_Button::POPUP123);
  _popup->add("Reload/View", 'r',
              (Fl_Callback *) view_reload_cb, (void *)num, 0);
  _popup->add("Reload/Visible Views", 0,
              (Fl_Callback *) view_reload_visible_cb, (void *)num, 0);
  _popup->add("Reload/All Views", 0,
              (Fl_Callback *) view_reload_all_cb, (void *)num, 0);
  _popup->add("Remove/View", FL_Delete,
              (Fl_Callback *) view_remove_cb, (void *)num, 0);
  _popup->add("Remove/Other Views", 0,
              (Fl_Callback *) view_remove_other_cb, (void *)num, 0);
  _popup->add("Remove/Visible Views", 0,
              (Fl_Callback *) view_remove_all_cb, (void *)-2, 0);
  _popup->add("Remove/Invisible Views", 0,
              (Fl_Callback *) view_remove_all_cb, (void *)-3, 0);
  _popup->add("Remove/Empty Views", 0,
              (Fl_Callback *) view_remove_all_cb, (void *)-4, 0);
  _popup->add("Remove/All Views", 0,
              (Fl_Callback *) view_remove_all_cb, (void *)-1, 0);
  _popup->add("Remove/By Name", 0,
              (Fl_Callback *) view_remove_all_cb, (void *)num, 0);
  _popup->add("Alias/View without Options", 0,
              (Fl_Callback *) view_alias_cb, (void *)num, 0);
  _popup->add("Alias/View with Options", 0,
              (Fl_Callback *) view_alias_with_options_cb, (void *)num, 0);
  _popup->add("Combine Elements/From Visible Views", 0,
              (Fl_Callback *) view_combine_space_visible_cb, (void *)num, 0);
  _popup->add("Combine Elements/From All Views", 0,
              (Fl_Callback *) view_combine_space_all_cb, (void *)num, 0);
  _popup->add("Combine Elements/By View Name", 0,
              (Fl_Callback *) view_combine_space_by_name_cb, (void *)num, 0);
  _popup->add("Combine Time Steps/From Visible Views", 0,
              (Fl_Callback *) view_combine_time_visible_cb, (void *)num, 0);
  _popup->add("Combine Time Steps/From All Views", 0,
              (Fl_Callback *) view_combine_time_all_cb, (void *)num, 0);
  _popup->add("Combine Time Steps/By View Name", 0,
              (Fl_Callback *) view_combine_time_by_name_cb, (void *)num, 0);
  _popup->add("Set Visibility/All On", 0,
              (Fl_Callback *) view_all_visible_cb, (void *)-1, 0);
  _popup->add("Set Visibility/All Off", 0,
              (Fl_Callback *) view_all_visible_cb, (void *)-2, 0);
  _popup->add("Set Visibility/Invert", 0,
              (Fl_Callback *) view_all_visible_cb, (void *)-3, 0);
  _popup->add("Set Visibility/By name", 0,
              (Fl_Callback *) view_all_visible_cb, (void *)num, 0);
  _popup->add("Apply As Background Mesh", 0,
              (Fl_Callback *) view_applybgmesh_cb, (void *)num, 0);
  _popup->add("Save As...", 0,
              (Fl_Callback *) view_save_cb, (void *)num, FL_MENU_DIVIDER);
  _popup->add("Options", 'o',
              (Fl_Callback *) view_options_cb, (void *)num, 0);
  _popup->add("Plugins", 'p',
              (Fl_Callback *) plugin_cb, (void *)num, 0);

  end(); // close the group
  resizable(_toggle);
}
