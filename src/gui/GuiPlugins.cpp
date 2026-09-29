// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// a plugin carries its own options: the fields of the pane are made from what
// the picked one says it takes

#include "GmshConfig.h"

#include <string>
#include <vector>

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

#if defined(HAVE_PLUGINS)
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

  GMSH_Plugin *_current(const std::string &name)
  {
    for(const auto &p : _plugins())
      if(p.first == name) return p.second;
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

  // with the options as they were run: the View one names the view
  void _record(GMSH_PostPlugin *p, PView *view)
  {
    std::string fileName = view ? view->getData()->getFileName() :
                                  GModel::current()->getFileName();
    fileName += ".opt";
    FILE *fp = Fopen(fileName.c_str(), "a");
    if(!fp) { Msg::Error("Could not open file '%s'", fileName.c_str()); }
    else {
      fprintf(fp, "%s", p->serialize().c_str());
      fclose(fp);
    }
  }
#endif

} // namespace

#if defined(HAVE_PLUGINS)
// on every view picked, or once on nothing at all
void GuiPlugins::run()
{
  GMSH_Plugin *p = _current(plugin);
  if(!p) return;
  if(p->getType() == GMSH_Plugin::GMSH_POST_PLUGIN) {
    GMSH_PostPlugin *pp = (GMSH_PostPlugin *)p;
    bool none = true;
#if defined(HAVE_POST)
    for(std::size_t i = 0; i < views.size(); i++) {
      if(!views[i]) continue;
      none = false;
      try {
        if(i < PView::list.size()) {
          PView *view = PView::list[i];
          if(view->getData()->isRemote())
            pp->executeRemote(view);
          else {
            // run on the selected view, whatever the View option says
            StringXNumber *opt = pp->findOption("View");
            double old = opt ? opt->def : 0.;
            if(opt) opt->def = view->getIndex();
            pp->execute(view);
            if(record) _record(pp, view);
            if(opt) opt->def = old;
          }
        }
      } catch(const std::exception &e) {
        Msg::Error("Plugin(%s) failed: %s", pp->getName().c_str(), e.what());
      }
    }
#endif
    if(none) {
      try {
        pp->execute(nullptr);
        if(record) _record(pp, nullptr);
      } catch(const std::exception &e) {
        Msg::Error("Plugin(%s) failed: %s", pp->getName().c_str(), e.what());
      }
    }
  }
  else {
    try {
      p->run();
    } catch(const std::exception &e) {
      Msg::Error("Plugin(%s) failed: %s", p->getName().c_str(), e.what());
    }
  }
  Gui::instance().updateViews(true, true);
  GMSH_Plugin::preview = nullptr;
  drawContext::global()->draw();
}
#endif

using namespace Ui;
using namespace Declare;

Form GuiPlugins::build()
{
  Form f = {"plugins", "Plugins", Item()};
  f.leastRows = 8;
#if defined(HAVE_PLUGINS)
  std::vector<std::pair<std::string, GMSH_Plugin *> > all = _plugins();
  if(all.size() && plugin.empty()) plugin = all[0].first;
  views.resize(_numViews(), 0);
  GMSH_Plugin *chosen = _current(plugin);

  // the two lists take more room than a column of names
  Field which =
    chooseFrom(
      [](std::vector<std::string> &labels, std::vector<int> &values) {
        std::vector<std::pair<std::string, GMSH_Plugin *> > all = _plugins();
        for(std::size_t i = 0; i < all.size(); i++) {
          labels.push_back(all[i].first);
          values.push_back((int)i);
        }
      },
      [this](int i) {
        std::vector<std::pair<std::string, GMSH_Plugin *> > all = _plugins();
        return i >= 0 && i < (int)all.size() && all[i].first == plugin;
      },
      [this](int i, bool on) {
        std::vector<std::pair<std::string, GMSH_Plugin *> > all = _plugins();
        if(!on || i < 0 || i >= (int)all.size()) return;
        // the preview of the previous plugin
        if(all[i].first != plugin) GMSH_Plugin::preview = nullptr;
        plugin = all[i].first;
        rebuild();
      },
      false)
      .fills()
      .sized(12.5);
  Field viewList =
    chooseFrom(
      [](std::vector<std::string> &labels, std::vector<int> &values) {
        for(int i = 0; i < _numViews(); i++) {
          labels.push_back("View [" + std::to_string(i) + "]");
          values.push_back(i);
        }
        if(!_numViews()) labels.push_back("No Views");
      },
      [this](int i) {
        return i >= 0 && i < (int)views.size() && views[i] != 0;
      },
      [this](int i, bool on) {
        if(i >= 0 && i < (int)views.size()) views[i] = on ? 1 : 0;
      },
      true)
      .fills()
      .sized(5.5)
      .enabledWhen([]() { return _numViews() > 0; });

  // the words first, the numbers after
  std::vector<Item> options;
  if(chosen) {
    // an edit is told to the plugin too, which may preview it
    for(int i = 0; i < chosen->getNbOptionsStr(); i++) {
      StringXString *o = chosen->getOptionStr(i);
      if(!o) continue;
      options.push_back(
        text(
          o->str, [o]() { return o->def; },
          [chosen, o, i](const std::string &v) {
            o->def = v;
            std::string w = v;
            chosen->optionStrCallback(i, -1, 0, w);
          })
          .tip(o->help ? o->help : ""));
    }
    // the options that ask the view for their range ask the first view picked
    int view = -1;
    for(std::size_t i = 0; i < views.size() && view < 0; i++)
      if(views[i]) view = (int)i;
    for(int i = 0; i < chosen->getNbOptions(); i++) {
      StringXNumber *o = chosen->getOption(i);
      if(!o) continue;
      Field n = number(
                  o->str, [o]() { return o->def; },
                  [chosen, o, i](double v) {
                    o->def = v;
                    chosen->optionCallback(i, -1, 0, v);
                  })
                  .tip(o->help ? o->help : "");
      double step, min, max;
      if(view >= 0 && chosen->optionCallback(i, view, 1, step) &&
         chosen->optionCallback(i, view, 2, min) &&
         chosen->optionCallback(i, view, 3, max))
        n.within(min, max, step);
      options.push_back(n);
    }
  }
  Item running =
    hbox({check("Record", &record)
            .tip("Append scripting command to file options when plugin is run")
            .tight(),
          gap(), button("Run", [this]() { run(); }).byDefault()});

  std::string name = chosen ? chosen->getName() : "";
  std::string brief = chosen ? chosen->getShortHelp() : "";
  std::string help = chosen ? chosen->getHelp() : "";
  if(chosen) help += "\n\nAuthor(s): " + chosen->getAuthor();

  // what it does in the middle under its name, as wide as the room
  std::vector<Ui::Line> said = paragraphs(brief);
  for(auto &l : said) l.centred = true;
  f.content = hbox(
    {hbox({which, viewList}),
     vbox({heading(name), prose([said]() { return said; }),
           tabs({{"Options", vbox({vbox(options).scrolls(), running})},
                 {"Help", vbox({prose([help]() { return paragraphs(help); })})
                            .scrolls()}})})});
#endif
  return f;
}

void GuiPlugins::showForView(int view)
{
  if(view >= 0) {
    views.assign(_numViews(), 0);
    if(view < (int)views.size()) views[view] = 1;
  }
  show();
}
