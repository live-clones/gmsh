// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_FLTK)

#include <cstdio>
#include <map>

#include <FL/Fl.H>
#if (FL_MAJOR_VERSION == 1) && (FL_MINOR_VERSION >= 4)
// OK
#elif (FL_MAJOR_VERSION == 1) && (FL_MINOR_VERSION == 3) && (FL_PATCH_VERSION >= 3)
// OK
#else
#error "Gmsh requires FLTK >= 1.3.3"
#endif
#include <FL/fl_ask.H>
#include <FL/Fl_Tooltip.H>
#include <FL/Fl_Window.H>

#include "Backend.h"
#include "uiSources.h"
#include "FlGui.h"
#include <mutex>
#include "graphicWindow.h"
#include "dialogFltk.h"
#include "onelabGroup.h"
#include "menuFltk.h"
#include "sceneViewFltk.h"
#include "fileDialogs.h"
#include "extraDialogs.h"
#if defined(HAVE_TOUCHBAR)
#include "touchBar.h"
#endif

// FLTK, as the interface asks for it. Nothing here says anything about Gmsh.

namespace {

  class backendFltk : public Ui::Backend {
  public:
    std::string name() override
    {
      char tmp[256];
      sprintf(tmp, "FLTK %d.%d.%d", FL_MAJOR_VERSION, FL_MINOR_VERSION,
              FL_PATCH_VERSION);
      return std::string(tmp);
    }

    void setSources(const Sources &sources) override
    {
      _sources = sources;
    }

    const Sources &sources() const { return _sources; }

    void setHost(const Host &host) override { _host = host; }
    const Host &host() const { return _host; }

    bool create(int argc, char **argv, bool quitShouldExit) override
    {
      if(!FlGui::available()) FlGui::instance(argc, argv, quitShouldExit,
                                              nullptr);
      return FlGui::available();
    }

    void destroy() override { FlGui::destroy(); }

    int runLoop() override
    {
#if defined(HAVE_TOUCHBAR)
      // the bar of buttons a MacBook offers over its keyboard
      updateTouchBar();
#endif
      return Fl::run();
    }

    void check(bool rateLimited) override { FlGui::check(rateLimited); }
    bool ready() override { return Fl::ready() ? true : false; }

    void wait(double seconds, bool force) override
    {
      if(seconds < 0.)
        FlGui::wait(force);
      else
        FlGui::wait(seconds, force);
    }

    void lock() override { FlGui::lock(); }
    void unlock() override { FlGui::unlock(); }
    int locked() override { return FlGui::locked(); }

    void postFromThread(const std::function<void()> &what) override
    {
      // Fl::awake() carries a pointer through to the loop; the work itself is
      // held here until the loop asks for it
      {
        std::lock_guard<std::mutex> lock(_mutex);
        _posted.push_back(what);
      }
      Fl::awake(_drain, this);
    }

    void post(const std::function<void()> &what) override { what(); }

    void copyText(const std::string &text) override
    {
      // both the selection buffer and the clipboard proper
      Fl::copy(text.c_str(), (int)text.size(), 0);
      Fl::copy(text.c_str(), (int)text.size(), 1);
    }

    void beep() override { fl_beep(); }

    // --- messages, the bar, and the questions that stop everything

    void addMessage(const std::string &text, int level) override
    {
      FlGui::instance()->addMessage((_colourPrefix(level) + text).c_str());
    }

    void messageLines(std::vector<std::string> &lines) override
    {
      if(FlGui::available()) FlGui::instance()->messageLines(lines);
    }

    void refreshBar() override
    {
      if(!FlGui::available()) return;
      for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++) {
        graphicWindow *g = FlGui::instance()->graph[i];
        g->getProgress()->redraw();
        // the buttons of the bar answer to options -- the one that picks with
        // the mouse says whether picking is on -- and are drawn from them
        g->refreshStatusButtons();
      }
    }

    // --- what the options that shape the main window push into it

    void setSceneSize(int width, int height) override
    {
      if(!FlGui::available() || FlGui::instance()->graph.empty()) return;
      if(width >= 0) FlGui::instance()->graph[0]->setGlWidth(width);
      if(height >= 0) FlGui::instance()->graph[0]->setGlHeight(height);
    }

    void setConsoleFontSize(int size) override
    {
      if(FlGui::available() && !FlGui::instance()->graph.empty())
        FlGui::instance()->graph[0]->setMessageFontSize(size);
    }

    void setTreeWidth(int width) override
    {
      if(FlGui::available() && !FlGui::instance()->graph.empty())
        FlGui::instance()->graph[0]->setMenuWidth(width);
    }

    void detachTree(bool detached) override
    {
      if(!FlGui::available() || FlGui::instance()->graph.empty()) return;
      if(detached)
        FlGui::instance()->graph[0]->detachMenu();
      else
        FlGui::instance()->graph[0]->attachMenu();
    }

    void enableTooltips(bool on) override
    {
      if(on)
        Fl_Tooltip::enable();
      else
        Fl_Tooltip::disable();
    }

    int numWindows() override
    {
      return FlGui::available() ? (int)FlGui::instance()->graph.size() : 0;
    }

    void setWindowTitle(int which, const std::string &title) override
    {
      if(!FlGui::available()) return;
      if(which < 0 || which >= (int)FlGui::instance()->graph.size()) return;
      FlGui::instance()->graph[which]->setTitle(title);
    }

    bool inputDialog(const std::string &question, std::string &value,
                     const std::string &hint, bool readOnly) override
    {
      if(readOnly) {
        simpleTextDisplay(question.c_str(), value);
        return false;
      }
      // a question with a shape to its answer gets the little editor that says
      // the shape
      if(hint.size())
        return simpleTextEditor(question.c_str(), hint.c_str(), value);
      const char *ret = fl_input("%s", value.c_str(), question.c_str());
      if(!ret) return false;
      value = ret;
      return true;
    }

    int questionDialog(const std::string &question, const std::string &zero,
                       const std::string &one,
                       const std::string &two) override
    {
      return fl_choice("%s", zero.c_str(), one.c_str(),
                       two.empty() ? nullptr : two.c_str(), question.c_str());
    }

    bool fileDialog(int mode, const std::string &title,
                    const std::vector<FileFormat> &formats,
                    std::vector<std::string> &names,
                    int *chosenFormat) override
    {
      // this chooser offers them as filters, one per line, and says which of
      // them was in force when the name was given
      std::string filter;
      for(const auto &f : formats) {
        if(f.name.size()) filter += f.name + "\t";
        filter += f.pattern + "\n";
      }
      FILE_CHOOSER_TYPE how = mode == OpenSeveral ? FILE_CHOOSER_MULTI :
                              mode == Create      ? FILE_CHOOSER_CREATE :
                                                    FILE_CHOOSER_SINGLE;
      std::string from = names.empty() ? "" : names[0];
      int picked = fileChooser(how, title.c_str(), filter.c_str(),
                               from.c_str());
      if(!picked) return false;
      names.clear();
      for(int i = 1; i <= picked; i++)
        names.push_back(fileChooserGetName(i));
      if(chosenFormat) *chosenFormat = fileChooserGetFilter();
      return true;
    }

    void applyColorScheme(bool dark) override
    {
      _dark = dark;
      if(FlGui::available()) FlGui::instance()->applyColorScheme(false);
    }

    // --- the things that are described

    void showForm(const Ui::Form &form, bool show) override
    {
      dialogFltk *d = fltkDialog(form, false);
      if(!d) {
        // built here and now, on the pane that was asked for meanwhile
        std::string pane;
        auto it = _paneWanted.find(&form);
        if(it != _paneWanted.end()) {
          pane = it->second;
          _paneWanted.erase(it);
        }
        d = fltkDialog(form, true, pane);
      }
      if(!d) return;
      if(show)
        d->show();
      else
        d->hide();
    }

    bool formVisible(const Ui::Form &form) override
    {
      // only if it is already there: asking is not a reason to build it
      dialogFltk *d = fltkDialog(form, false);
      return d && d->shown();
    }

    std::string formPane(const Ui::Form &form) override
    {
      dialogFltk *d = fltkDialog(form, false);
      // a pane asked for before the window exists is kept for it
      if(!d) {
        auto it = _paneWanted.find(&form);
        return it == _paneWanted.end() ? "" : it->second;
      }
      return d->pane();
    }

    void setFormPane(const Ui::Form &form, const std::string &pane) override
    {
      dialogFltk *d = fltkDialog(form, false);
      if(d)
        d->setPane(pane);
      else
        _paneWanted[&form] = pane;
    }

    void reloadForm(const Ui::Form &form) override
    {
      dialogFltk *d = fltkDialog(form, false);
      if(d && d->shown()) d->refresh();
    }

    void rebuildForm(const Ui::Form &form) override
    {
      dialogFltk *d = fltkDialog(form, false);
      if(d && d->shown()) d->reshape();
    }

    void dropForm(const Ui::Form &form) override
    {
      fltkDropDialog(form);
      _paneWanted.erase(&form);
    }

    void showConsole(bool show) override
    {
      if(!FlGui::available()) return;
      graphicWindow *g = FlGui::instance()->graph[0];
      if(show)
        g->showMessages();
      else
        g->hideMessages();
      FlGui::check();
    }

    bool consoleVisible() override
    {
      if(!FlGui::available()) return false;
      return FlGui::instance()->graph[0]->getMessageHeight() >= FL_NORMAL_SIZE;
    }

    void refreshTree(bool rebuild) override
    {
      if(FlGui::available()) FlGui::instance()->rebuildTree(rebuild);
    }

    void openTreeItem(const std::string &name, bool open) override
    {
      if(!FlGui::available() || !FlGui::instance()->onelab) return;
      if(open)
        FlGui::instance()->onelab->openTreeItem(name);
      else
        FlGui::instance()->onelab->closeTreeItem(name);
    }

    bool treeItemOpen(const std::string &name) override
    {
      return FlGui::available() && FlGui::instance()->onelab &&
             FlGui::instance()->onelab->isTreeItemOpen(name);
    }

    void showTree() override
    {
      if(FlGui::available() && FlGui::instance()->onelab)
        FlGui::instance()->onelab->show();
    }

    void refreshMenus() override
    {
      if(FlGui::available())
        FlGui::instance()->graph[0]->fillRecentHistoryMenu();
    }

    Ui::Backend::Layout windowLayout() override
    {
      return FlGui::available() ? FlGui::instance()->windowLayout() :
                                  Ui::Backend::Layout();
    }

    void setSolverButtonMode(const std::string &button0,
                             const std::string &button1) override
    {
      if(FlGui::available() && FlGui::instance()->onelab)
        FlGui::instance()->onelab->rebuildFooter();
    }

    void drawTooltip(const std::string &text) override
    {
      if(!FlGui::available()) return;
      if(sceneViewFltk *w = FlGui::instance()->getCurrentOpenglWindow())
        w->drawTooltip(text);
    }

    void windowAction(const std::string &what) override
    {
      if(!fltkWindowAction(what) && _host.error)
        _host.error("Unknown window action '" + what + "'");
    }

    bool supports(const std::string &what) override
    {
#if !defined(WIN32)
      // this interface only copies the view to the clipboard on Windows
      if(what == "copy") return false;
#endif
      return true;
    }

  private:
    // colour codes understood by Fl_Browser; a dark scheme wants lighter ones
    std::string _colourPrefix(int level) const
    {
      switch(level) {
      case Direct: return _dark ? "@B136@." : "@C4@.";
      case Error: return _dark ? "@B72@." : "@C1@.";
      case Warning: return _dark ? "@B152@." : "@C5@.";
      default: return "";
      }
    }

    Sources _sources;
    Host _host;
    bool _dark = false;
    // the pane asked for on a dialog whose window has not been built yet
    std::map<const Ui::Form *, std::string> _paneWanted;
    std::mutex _mutex;
    std::vector<std::function<void()> > _posted;

    static void _drain(void *data)
    {
      backendFltk *self = (backendFltk *)data;
      std::vector<std::function<void()> > work;
      {
        std::lock_guard<std::mutex> lock(self->_mutex);
        work.swap(self->_posted);
      }
      for(auto &w : work) w();
    }
  };

  backendFltk *_the = nullptr;

} // namespace

// what the interface was given, for the files that build from it
const Ui::Backend::Sources &fltkSources()
{
  // answered before the interface was given anything: the settings come out
  // at their defaults
  static Ui::Backend::Sources none = []() {
    Ui::Backend::Sources empty;
    empty.settings = []() { return Ui::Backend::Settings(); };
    return empty;
  }();
  return _the ? _the->sources() : none;
}

// and what it may call back
const Ui::Backend::Host &fltkHost()
{
  static const Ui::Backend::Host none;
  return _the ? _the->host() : none;
}

// the one this file offers, made once: every interface that was compiled
// in is there at once, and the choice is a word one types
namespace {
  struct offeringFltk {
    offeringFltk()
    {
      Ui::offer("fltk", []() -> Ui::Backend * {
        if(!_the) _the = new backendFltk();
        return _the;
      });
    }
  };
  offeringFltk _offeringFltk;
}


#endif
