// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The plugins, what each of them takes and what it is run on: the counterpart
// of src/fltk/pluginWindow.cpp, described once and built by both interfaces.
// A plugin carries its own options, so the fields of the pane are not written
// here at all -- they are made from whatever the plugin one has picked says it
// takes.

#include "GmshConfig.h"

#include <string>
#include <vector>

#include "GuiDialogs.h"
#include "GuiDeclare.h"
#include "GuiActions.h"
#include "Gui.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "Context.h"
#include "OS.h"
#include "StringUtils.h"
#include "drawContext.h"

#if defined(HAVE_PLUGINS)
#include "PluginManager.h"
#include "Plugin.h"
#endif

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewData.h"
#endif

namespace {

  // Which plugin the window is showing, which views it would run it on, and
  // whether it writes down what it does. The window this replaces kept all
  // three in its widgets.
  struct pluginState {
    std::string plugin;
    std::vector<char> views;
    bool record = false;
  };

  pluginState &_state()
  {
    static pluginState state;
    return state;
  }

#if defined(HAVE_PLUGINS)
  // the plugins one can run from here, in the order the manager keeps them
  std::vector<std::pair<std::string, GMSH_Plugin *> > _plugins()
  {
    std::vector<std::pair<std::string, GMSH_Plugin *> > out;
    for(auto it = PluginManager::instance()->begin();
        it != PluginManager::instance()->end(); ++it) {
      GMSH_Plugin *p = it->second;
      if(!p) continue;
      if(p->getType() == GMSH_Plugin::GMSH_POST_PLUGIN ||
         p->getType() == GMSH_Plugin::GMSH_MESH_PLUGIN)
        out.push_back(std::make_pair(it->first, p));
    }
    return out;
  }

  GMSH_Plugin *_current()
  {
    for(const auto &p : _plugins())
      if(p.first == _state().plugin) return p.second;
    std::vector<std::pair<std::string, GMSH_Plugin *> > all = _plugins();
    return all.size() ? all[0].second : nullptr;
  }

  int _numViews()
  {
#if defined(HAVE_POST)
    return (int)PView::list.size();
#else
    return 0;
#endif
  }

  // the first view it is to be run on, which is what the options that ask the
  // view for their range are asked about
  int _firstView()
  {
    for(std::size_t i = 0; i < _state().views.size(); i++)
      if(_state().views[i]) return (int)i;
    return -1;
  }

  // what the window writes down when it is asked to, as that window does
  void _record(GMSH_PostPlugin *p, PView *view)
  {
    if(!_state().record) return;
    std::string fileName;
    int was = -1;
    if(view) {
      for(int i = 0; i < p->getNbOptions(); i++)
        if(std::string(p->getOption(i)->str) == "View") {
          was = (int)(p->getOption(i)->def);
          p->getOption(i)->def = view->getIndex();
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
    if(view && was != -1)
      for(int i = 0; i < p->getNbOptions(); i++)
        if(std::string(p->getOption(i)->str) == "View")
          p->getOption(i)->def = was;
  }

  // run it: on every view that is picked, or once on nothing at all
  void _run()
  {
    GMSH_Plugin *p = _current();
    if(!p) return;
    if(p->getType() == GMSH_Plugin::GMSH_POST_PLUGIN) {
      GMSH_PostPlugin *pp = (GMSH_PostPlugin *)p;
      bool none = true;
#if defined(HAVE_POST)
      for(std::size_t i = 0; i < _state().views.size(); i++) {
        if(!_state().views[i]) continue;
        none = false;
        try {
          if(i < PView::list.size()) {
            PView *view = PView::list[i];
            if(view->getData()->isRemote())
              pp->executeRemote(view);
            else {
              pp->execute(view);
              _record(pp, view);
            }
          }
        } catch(...) {
          char tmp[256];
          pp->catchErrorMessage(tmp);
          Msg::Warning("%s", tmp);
        }
      }
#endif
      if(none) {
        try {
          pp->execute(nullptr);
          _record(pp, nullptr);
        } catch(...) {
          char tmp[256];
          pp->catchErrorMessage(tmp);
          Msg::Warning("%s", tmp);
        }
      }
    }
    else {
      try {
        p->run();
      } catch(...) {
        Msg::Error("Plugin '%s' failed", p->getName().c_str());
      }
    }
    Gui::updateViews(true, true);
    GMSH_Plugin::draw = nullptr;
    drawContext::global()->draw();
  }
#endif

} // namespace

namespace Dialog {

  void showPluginsForView(int view)
  {
    if(view >= 0) {
      _state().views.assign(_numViews(), 0);
      if(view < (int)_state().views.size()) _state().views[view] = 1;
    }
    show(Plugins, -1);
  }

  Form plugins()
  {
    Form p;
    p.title = "Plugins";
    p.tabbed = true;
    // the two lists beside the panes take more room than a column of names
    p.sideEm = 19.;
    // the name of the plugin and what it does take three lines over the panes,
    // and the window this reproduces is not taller for them
    p.leastRows = 8;

#if defined(HAVE_PLUGINS)
    std::vector<std::pair<std::string, GMSH_Plugin *> > all = _plugins();
    if(all.size() && _state().plugin.empty()) _state().plugin = all[0].first;
    _state().views.resize(_numViews(), 0);

    // --- which plugin, and which views it is to be run on
    {
      Field which = chooseFrom(
        [](std::vector<std::string> &labels, std::vector<int> &values) {
          std::vector<std::pair<std::string, GMSH_Plugin *> > all = _plugins();
          for(std::size_t i = 0; i < all.size(); i++) {
            labels.push_back(all[i].first);
            values.push_back((int)i);
          }
        },
        [](int i) {
          std::vector<std::pair<std::string, GMSH_Plugin *> > all = _plugins();
          return i >= 0 && i < (int)all.size() &&
                 all[i].first == _state().plugin;
        },
        [](int i, bool on) {
          std::vector<std::pair<std::string, GMSH_Plugin *> > all = _plugins();
          if(on && i >= 0 && i < (int)all.size())
            _state().plugin = all[i].first;
        },
        false);
      which.rows = 0;
      which.widthEm = 12.5;
      p.side.push_back(which);

      Field views = chooseFrom(
        [](std::vector<std::string> &labels, std::vector<int> &values) {
          for(int i = 0; i < _numViews(); i++) {
            labels.push_back("View [" + std::to_string(i) + "]");
            values.push_back(i);
          }
          if(!_numViews()) labels.push_back("No Views");
        },
        [](int i) {
          return i >= 0 && i < (int)_state().views.size() &&
                 _state().views[i] != 0;
        },
        [](int i, bool on) {
          if(i >= 0 && i < (int)_state().views.size())
            _state().views[i] = on ? 1 : 0;
        },
        true);
      views.rows = 0;
      views.widthEm = 5.5;
      views.sameRow = true;
      views.enabled = []() { return _numViews() > 0; };
      p.side.push_back(views);
    }

    // --- what it is, over the panes: the window this replaces writes the name
    // of the plugin, and what it does, over the row of tabs rather than inside
    // one of them
    {
      GMSH_Plugin *plugin = _current();
      std::string name = plugin ? plugin->getName() : "";
      p.header.push_back(names([name]() { return name; }));
      std::string brief = plugin ? plugin->getShortHelp() : "";
      Field about = says([brief]() { return brief; });
      about.wraps = true;
      about.rows = 2;
      p.header.push_back(about);
    }

    // --- what the plugin one has picked takes
    {
      Pane options;
      options.label = "Options";
      GMSH_Plugin *plugin = _current();
      if(plugin) {
        // its own options, as it says it takes them: the words first, the
        // numbers after, as that window has them
        for(int i = 0; i < plugin->getNbOptionsStr(); i++) {
          StringXString *o = plugin->getOptionStr(i);
          if(!o) continue;
          Field f = text(o->str, &o->def);
          if(o->help) f.tooltip = o->help;
          options.fields.push_back(f);
        }
        int view = _firstView();
        for(int i = 0; i < plugin->getNbOptions(); i++) {
          StringXNumber *o = plugin->getOption(i);
          if(!o) continue;
          Field f = number(o->str, &o->def);
          if(o->help) f.tooltip = o->help;
          // an option that asks the view it is run on what it may be
          if(o->function && view >= 0) {
            f.step = o->function(view, 1, 0.);
            f.minimum = o->function(view, 2, 0.);
            f.maximum = o->function(view, 3, 0.);
          }
          options.fields.push_back(f);
        }
      }
      options.scrolling = true;
      // and whether what it does is written down, on the line of Run, as the
      // window this replaces has it
      Field record = check("Record", &_state().record);
      record.tooltip =
        "Append scripting command to file options when plugin is run";
      record.packed = true;
      options.beside.push_back(record);
      options.buttonLabel = "Run";
      options.button = _run;
      p.panes.push_back(options);
    }

    // --- and what it is for
    {
      Pane help;
      help.label = "Help";
      GMSH_Plugin *plugin = _current();
      std::string text = plugin ? plugin->getHelp() : "";
      if(plugin) text += "\n\nAuthor(s): " + plugin->getAuthor();
      Field says_ = says([text]() { return text; });
      says_.wraps = true;
      says_.rows = 10;
      help.fields.push_back(says_);
      help.scrolling = true;
      p.panes.push_back(help);
    }

#endif
    return p;
  }

} // namespace Dialog
