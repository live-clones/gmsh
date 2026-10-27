// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#if !defined(HAVE_NO_STDINT_H)
#include <stdint.h>
#elif defined(HAVE_NO_INTPTR_T)
typedef unsigned long intptr_t;
#endif
#include <algorithm>
#include <vector>
#include <string.h>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Scroll.H>
#include <FL/fl_draw.H>
#include "FlGui.h"
#include "drawContext.h"
#include "pluginWindow.h"
#include "paletteWindow.h"
#include "hintInput.h"
#include "PView.h"
#include "PViewData.h"
#include "PViewOptions.h"
#include "PluginManager.h"
#include "Plugin.h"
#include "GModel.h"
#include "MVertex.h"
#include "Context.h"
#include "scriptStringInterface.h"
#include "StringUtils.h"
#include "OS.h"

#define MAX_PLUGIN_OPTIONS 50
class PluginDialogBox {
public:
  Fl_Group *group;
  Fl_Box *title, *about;
  Fl_Value_Input *value[MAX_PLUGIN_OPTIONS];
  Fl_Input *input[MAX_PLUGIN_OPTIONS];
};

void plugin_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->plugins->show((intptr_t)data);
}

// the field of an option changed: tell the plugin, which may preview it
static void plugin_input_value_cb(Fl_Widget *w, void *data)
{
  GMSH_Plugin *p = (GMSH_Plugin *)data;
  for(int i = 0; i < std::min(p->getNbOptions(), MAX_PLUGIN_OPTIONS); i++) {
    if(p->dialogBox->value[i] != w) continue;
    double v = p->dialogBox->value[i]->value();
    p->optionCallback(i, -1, 0, v);
  }
}

static void plugin_input_cb(Fl_Widget *w, void *data)
{
  GMSH_Plugin *p = (GMSH_Plugin *)data;
  for(int i = 0; i < std::min(p->getNbOptionsStr(), MAX_PLUGIN_OPTIONS); i++) {
    if(p->dialogBox->input[i] != w) continue;
    std::string v = p->dialogBox->input[i]->value();
    p->optionStrCallback(i, -1, 0, v);
  }
}

static void plugin_browser_cb(Fl_Widget *w, void *data)
{
  GMSH_Plugin *p = FlGui::instance()->plugins->selected();
  if(!p) return;

  // show the current values of the options (a script or the API may have
  // changed them), unless the plugin was already shown: its fields may have
  // been edited
  static GMSH_Plugin *shown = nullptr;
  if(p != shown) {
    GMSH_Plugin::preview = nullptr; // the preview of the previous plugin
    for(int i = 0; i < std::min(p->getNbOptionsStr(), MAX_PLUGIN_OPTIONS); i++)
      p->dialogBox->input[i]->value(p->getOptionStr(i)->def.c_str());
    for(int i = 0; i < std::min(p->getNbOptions(), MAX_PLUGIN_OPTIONS); i++)
      p->dialogBox->value[i]->value(p->getOption(i)->def);
    shown = p;
  }

  // get first first selected view
  int iView = -1;
  Fl_Multi_Browser *views = FlGui::instance()->plugins->views->browser;
  for(int i = 1; i <= views->size(); i++) {
    if(views->selected(i)) {
      iView = i - 1;
      break;
    }
  }

  // set the Fl_Value_Input callbacks and configure the input value
  // fields (we get step, min and max by calling the option function
  // with action==1, 2 and 3, respectively)
  int n = std::min(p->getNbOptions(), MAX_PLUGIN_OPTIONS);
  for(int i = 0; i < n; i++) {
    p->dialogBox->value[i]->callback(plugin_input_value_cb, (void *)p);
    double v = 0.;
    if(iView >= 0 && p->optionCallback(i, iView, 1, v)) {
      if(CTX::instance()->inputScrolling) p->dialogBox->value[i]->step(v, 1);
      p->optionCallback(i, iView, 2, v);
      p->dialogBox->value[i]->minimum(v);
      p->optionCallback(i, iView, 3, v);
      p->dialogBox->value[i]->maximum(v);
    }
  }

  // set the Fl_Input callbacks
  int m = std::min(p->getNbOptionsStr(), MAX_PLUGIN_OPTIONS);
  for(int i = 0; i < m; i++)
    p->dialogBox->input[i]->callback(plugin_input_cb, (void *)p);

  FlGui::instance()->plugins->updateCount();
  FlGui::instance()->plugins->layout();
}

static void add_scripting(GMSH_PostPlugin *p, PView *view)
{
  if(!FlGui::instance()->plugins->record->value()) return;

  std::string fileName;
  int oldIndex = -1;
  if(view) {
    for(int i = 0; i < p->getNbOptions(); i++) {
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
  FILE *fp = Fopen(fileName.c_str(), "a");
  if(!fp) { Msg::Error("Could not open file '%s'", fileName.c_str()); }
  else {
    fprintf(fp, "%s", p->serialize().c_str());
    fclose(fp);
  }

  if(view && oldIndex != -1) {
    for(int i = 0; i < p->getNbOptions(); i++) {
      if(std::string(p->getOption(i)->str) == "View") {
        p->getOption(i)->def = oldIndex;
      }
    }
  }
}

static void plugin_run_cb(Fl_Widget *w, void *data)
{
  GMSH_Plugin *p = FlGui::instance()->plugins->selected();
  if(!p) return;

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

  if(p->getType() == GMSH_Plugin::GMSH_POST_PLUGIN) {
    GMSH_PostPlugin *pp = (GMSH_PostPlugin *)p;
    // run on all selected views
    bool no_view_selected = true;
    Fl_Multi_Browser *views = FlGui::instance()->plugins->views->browser;
    for(int i = 1; i <= views->size(); i++) {
      if(views->selected(i)) {
        no_view_selected = false;
        try {
          if(i - 1 >= 0 && i - 1 < (int)PView::list.size()) {
            PView *view = PView::list[i - 1];
            if(view->getData()->isRemote())
              pp->executeRemote(view);
            else {
              // run on the selected view, whatever the View option says
              StringXNumber *opt = nullptr;
              for(int j = 0; j < pp->getNbOptions(); j++)
                if(std::string(pp->getOption(j)->str) == "View")
                  opt = pp->getOption(j);
              double old = opt ? opt->def : 0.;
              if(opt) opt->def = view->getIndex();
              pp->execute(view);
              add_scripting(pp, view);
              if(opt) opt->def = old;
            }
          }
          else {
            pp->execute(nullptr);
            add_scripting(pp, nullptr);
          }
        } catch(const std::exception &e) {
          Msg::Error("Plugin(%s) failed: %s", pp->getName().c_str(), e.what());
        }
      }
    }
    if(no_view_selected) {
      pp->execute(nullptr);
      add_scripting(pp, nullptr);
    }
  }
  else {
    p->run();
  }

  FlGui::instance()->updateViews(true, true);
  GMSH_Plugin::preview = nullptr;
  drawContext::global()->draw();
}

static void plugin_search_cb(Fl_Widget *w, void *data)
{ FlGui::instance()->plugins->filter(); }

static void plugin_help_cb(Fl_Widget *w, void *data)
{ FlGui::instance()->plugins->toggleHelp(); }

static void plugin_views_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->plugins->views->selectViews((const char *)data);
  plugin_browser_cb(nullptr, nullptr);
}

static void plugin_resized_cb(void *data)
{ FlGui::instance()->plugins->layout(); }

// the height of the label of a box wrapped on lines w wide, as FLTK draws a
// label inside its box, plus a border below
static int wrappedHeight(Fl_Box *b, int w)
{
  fl_font(b->labelfont(), b->labelsize());
  int tw = w - 6, th = 0;
  fl_measure(b->label(), tw, th, 0);
  return th + WB;
}

void pluginWindow::_createDialogBox(GMSH_Plugin *p)
{
  // placed by _placeDialogBox()
  PluginDialogBox *d = p->dialogBox = new PluginDialogBox;
  d->group = new Fl_Group(0, 0, 10 * BH, 10 * BH);

  d->title = new Fl_Box(0, 0, IW, BH, strdup(p->getName().c_str()));
  d->title->labelfont(FL_BOLD);
  d->title->labelsize(FL_NORMAL_SIZE + 3);
  d->title->align(FL_ALIGN_INSIDE | FL_ALIGN_LEFT);
  d->about = new Fl_Box(0, 0, IW, BH, strdup(p->getShortHelp().c_str()));
  d->about->align(FL_ALIGN_WRAP | FL_ALIGN_TOP | FL_ALIGN_LEFT |
                  FL_ALIGN_INSIDE);

  int m = std::min(p->getNbOptionsStr(), MAX_PLUGIN_OPTIONS);
  int n = std::min(p->getNbOptions(), MAX_PLUGIN_OPTIONS);
  for(int i = 0; i < m; i++) {
    StringXString *sxs = p->getOptionStr(i);
    d->input[i] = new Fl_Input(0, 0, IW, BH, sxs->str);
    d->input[i]->align(FL_ALIGN_RIGHT);
    d->input[i]->value(sxs->def.c_str());
  }
  for(int i = 0; i < n; i++) {
    StringXNumber *sxn = p->getOption(i);
    d->value[i] = new Fl_Value_Input(0, 0, IW, BH, sxn->str);
    d->value[i]->align(FL_ALIGN_RIGHT);
    d->value[i]->value(sxn->def);
  }

  d->group->end();
}

int pluginWindow::_placeDialogBox(GMSH_Plugin *p, int x, int y, int w)
{
  PluginDialogBox *d = p->dialogBox;
  int bh = _rowHeight, yy = y;
  d->title->resize(x, yy, w, bh);
  yy += bh;
  // the short help on as many lines as it takes
  int ah = wrappedHeight(d->about, w);
  d->about->resize(x, yy, w, ah);
  yy += ah + WB;
  int m = std::min(p->getNbOptionsStr(), MAX_PLUGIN_OPTIONS);
  int n = std::min(p->getNbOptions(), MAX_PLUGIN_OPTIONS);
  for(int i = 0; i < m; i++, yy += bh)
    d->input[i]->resize(x + WB, yy, _fieldWidth, bh);
  for(int i = 0; i < n; i++, yy += bh)
    d->value[i]->resize(x + WB, yy, _fieldWidth, bh);
  // its children are placed: only the box of the group changes
  d->group->Fl_Widget::resize(x, y, w, yy - y);
  return yy + WB;
}

void pluginWindow::_fillScroll(GMSH_Plugin *p)
{
  // only the plugin chosen is in the scroll, which moves all its children at
  // each step
  if(p == _shown) return;
  if(_shown) scroll->remove(_shown->dialogBox->group);
  if(p) {
    scroll->insert(*p->dialogBox->group, 0);
    // a label, where '@' would start a symbol
    std::string str = p->getHelp() + "\n\nAuthor(s): " + p->getAuthor();
    ReplaceSubStringInPlace("@", "@@", str);
    help->copy_label(str.c_str());
  }
  _shown = p;
}

pluginWindow::pluginWindow(int deltaFontSize)
{
  FL_NORMAL_SIZE -= deltaFontSize;

  _rowHeight = BH;
  _fieldWidth = IW;
  _helpOpen = false;
  _shown = nullptr;

  // as narrow as the option window, and tall enough for the list of plugins,
  // a few options and the views
  int width0 = TW;
  int height0 = 22 * BH;
  int width = std::max(CTX::instance()->pluginSize[0], width0);
  int height = std::max(CTX::instance()->pluginSize[1], height0);

  win = new paletteWindow(width, height,
                          CTX::instance()->nonModalWindows ? true : false,
                          "Plugins", CTX::instance()->pluginOffset);
  win->box(GMSH_WINDOW_BOX);

  search = searchBox(
    WB, WB, width - 2 * WB, BH, "Search plugins",
    "Show only the plugins whose name or description match the regular\n"
    "expression, whatever the case",
    plugin_search_cb);

  // the name of each plugin, then what it does
  browser = new Fl_Hold_Browser(WB, 2 * WB + BH, width - 2 * WB, 7 * BH);
  browser->callback(plugin_browser_cb);
  browser->has_scrollbar(Fl_Browser_::VERTICAL);
  fl_font(browser->textfont(), browser->textsize());
  int nameWidth = 0;
  for(auto it = PluginManager::instance()->begin();
      it != PluginManager::instance()->end(); ++it)
    nameWidth =
      std::max(nameWidth, (int)fl_width(it->second->getName().c_str()));
  _cols[0] = nameWidth + 3 * WB;
  _cols[1] = 0;
  browser->column_widths(_cols);
  _listHeight = 7 * (fl_height() + 2) + 4;

  scroll = new Fl_Scroll(0, 0, width, height);
  scroll->type(Fl_Scroll::VERTICAL);
  for(auto it = PluginManager::instance()->begin();
      it != PluginManager::instance()->end(); ++it) {
    GMSH_Plugin *p = it->second;
    if(p->getType() == GMSH_Plugin::GMSH_POST_PLUGIN ||
       p->getType() == GMSH_Plugin::GMSH_MESH_PLUGIN) {
      std::string line = p->getName() + "\t@C8" + p->getShortHelp();
      browser->add(line.c_str(), p);
      _createDialogBox(p);
      // put in the scroll when chosen
      scroll->remove(p->dialogBox->group);
    }
  }
  browser->select(1);
  helpHeader = new Fl_Button(0, 0, IW, BH);
  helpHeader->box(FL_FLAT_BOX);
  helpHeader->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
  helpHeader->labelfont(FL_BOLD);
  helpHeader->clear_visible_focus();
  helpHeader->callback(plugin_help_cb);
  // in full, in the flow of the options
  help = new Fl_Box(0, 0, IW, BH);
  help->align(FL_ALIGN_WRAP | FL_ALIGN_TOP | FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
  help->hide();
  scroll->end();

  views = new targetList(WB, 0, width - 2 * WB, BH, {"All", "Visible", "None"},
                         plugin_views_cb);
  views->browser->callback(plugin_browser_cb);

  record = new Fl_Check_Button(WB, height - BH - WB, BB, BH, "Record");
  record->type(FL_TOGGLE_BUTTON);
  record->tooltip(
    "Append scripting command to file options when plugin is run");
  run = new Fl_Return_Button(width - BB - WB, height - BH - WB, BB, BH, "Run");
  run->callback(plugin_run_cb);

  win->resizable(scroll);
  ((paletteWindow *)win)->sizeRange(width0, 16 * BH); // height: layout()
  win->end();
  ((paletteWindow *)win)->whenResized(plugin_resized_cb, nullptr);
  updateCount();
  layout();

  FL_NORMAL_SIZE += deltaFontSize;
}

GMSH_Plugin *pluginWindow::selected() const
{
  int i = browser->value();
  return i ? (GMSH_Plugin *)browser->data(i) : nullptr;
}

void pluginWindow::filter()
{
  _filter.set(search);
  for(int i = 1; i <= browser->size(); i++) {
    GMSH_Plugin *p = (GMSH_Plugin *)browser->data(i);
    if(_filter.matches(p->getName() + " " + p->getShortHelp()))
      browser->show(i);
    else
      browser->hide(i);
  }
  // the plugin chosen hidden: the first match instead, or none
  int v = browser->value();
  if(!v || browser->visible(v)) return;
  browser->deselect();
  for(int i = 1; i <= browser->size(); i++)
    if(browser->visible(i)) {
      browser->value(i);
      break;
    }
  if(browser->value())
    browser->do_callback();
  else
    layout();
}

void pluginWindow::toggleHelp()
{
  _helpOpen = !_helpOpen;
  layout();
  // the help opened is shown, from its header down
  if(_helpOpen) {
    int most = std::max(0, help->y() + help->h() - scroll->y() - scroll->h());
    scroll->scroll_to(0, std::min(helpHeader->y() - scroll->y(), most));
  }
}

void pluginWindow::updateCount()
{
  int n = views->selectedCount();
  std::string str =
    n ? "Runs on " + std::to_string(n) + (n > 1 ? " views" : " view") :
        "Runs without a view";
  views->count->copy_label(str.c_str());
}

void pluginWindow::layout()
{
  int bh = _rowHeight, ww = win->w(), wh = win->h();
  GMSH_Plugin *p = selected();
  bool post =
    p && p->getType() == GMSH_Plugin::GMSH_POST_PLUGIN && PView::list.size();

  // the list of plugins (7 lines, down to 3 in a short window), the views of
  // a post-processing plugin (down to 2 lines), the plugin chosen with three
  // rows at least, Record and Run
  int top = 2 * WB + bh, bottom = wh - bh - 2 * WB;
  int line = (_listHeight - 4) / 7, lh = _listHeight;
  int vh = post ? views->heightFor(PView::list.size()) : 0;
  int least = top + 3 * line + 4 + WB + 3 * bh + (wh - bottom) +
              (post ? views->heightFor(2) + WB : 0);
  if(((paletteWindow *)win)->leastHeight(least)) return;
  int excess = lh + WB + 3 * bh + (post ? vh + WB : 0) - (bottom - top);
  if(excess > 0) {
    int d = std::min(excess, lh - (3 * line + 4));
    lh -= d;
    excess -= d;
  }
  if(excess > 0 && post) vh = std::max(views->heightFor(2), vh - excess);

  search->parent()->resize(WB, WB, ww - 2 * WB, bh);
  int y = top;
  browser->resize(WB, y, ww - 2 * WB, lh);
  y += lh + WB;

  // the views of a post-processing plugin under the plugins, what it runs on
  // before how; Record and Run at the bottom
  if(post) {
    views->resize(WB, y, ww - 2 * WB, vh);
    views->show();
    y += vh + WB;
  }
  else
    views->hide();
  int yb = wh - bh - WB;
  record->resize(WB, yb, record->w(), bh);
  run->resize(ww - run->w() - WB, yb, run->w(), bh);

  // the plugin chosen, scrolling between the two, kept where it was scrolled
  // to (e.g. when views are chosen)
  int ypos = (p == _shown) ? scroll->yposition() : 0;
  scroll->scroll_to(0, 0);
  scroll->resize(0, y, ww - WB, std::max(0, bottom - y));
  _fillScroll(p);
  int w = ww - 2 * WB - Fl::scrollbar_size();
  if(p) y = _placeDialogBox(p, WB, y, w);
  helpHeader->copy_label(_helpOpen ? "@-22> Help" : "@-2> Help");
  helpHeader->resize(WB, y, w, bh);
  if(p)
    helpHeader->show();
  else
    helpHeader->hide();
  if(p && _helpOpen) {
    help->resize(WB, y + bh, w, wrappedHeight(help, w));
    help->show();
  }
  else {
    // out of the way too: FLTK 1.3 scrolls over hidden children
    help->hide();
    help->resize(WB, y, w, 0);
  }
  int end = help->visible() ? help->y() + help->h() : y + bh;
  scroll->scroll_to(
    0, std::min(ypos, std::max(0, end - scroll->y() - scroll->h())));

  win->init_sizes();
  win->redraw();
}

void pluginWindow::show(int viewIndex)
{
  resetViewBrowser();
  if(viewIndex >= 0 && viewIndex < (int)PView::list.size()) {
    views->browser->deselect();
    views->browser->select(viewIndex + 1);
    plugin_browser_cb(nullptr, nullptr);
  }
  win->show();
}

void pluginWindow::resetViewBrowser()
{
  // keep what was selected
  Fl_Multi_Browser *b = views->browser;
  std::vector<int> state;
  for(int i = 0; i < b->size(); i++) state.push_back(b->selected(i + 1));
  b->clear();
  for(std::size_t i = 0; i < PView::list.size(); i++) {
    b->add(targetList::viewName(i).c_str());
    if(i < state.size() && state[i]) b->select(i + 1);
  }
  plugin_browser_cb(nullptr, nullptr);
}
