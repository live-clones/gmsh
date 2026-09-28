// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_IMGUI)

#include <mutex>
#include <vector>

#include "imgui.h"
#include <GLFW/glfw3.h>

#include "Backend.h"
#include "uiSources.h"
#include "appWindow.h"
#include "toolkit.h"
#include "messageConsole.h"
#include "sceneView.h"


namespace {

  class backendImGui : public Ui::Backend {
  public:
    std::string name() override
    {
      std::string s = "Dear ImGui ";
      s += IMGUI_VERSION;
      s += ", GLFW ";
      s += glfwGetVersionString();
      return s;
    }

    void setSources(const Sources &sources) override
    {
      _sources = sources;
    }

    const Sources &sources() const { return _sources; }

    void setHost(const Host &host) override
    {
      _host = host;
      Toolkit::reportTo([host](int level, const std::string &text) {
        if(level == Toolkit::Error && host.error) host.error(text);
      });
      if(host.quitting) Toolkit::quitWith(host.quitting);
    }

    bool create(int argc, char **argv, bool quitShouldExit) override
    {
      if(appWindow::available()) return true;
      appWindow::instance(argc, argv, quitShouldExit);
      return appWindow::available();
    }

    void destroy() override { appWindow::destroy(); }

    int runLoop() override
    {
      return appWindow::available() ? appWindow::instance()->runLoop() : 0;
    }

    void check(bool rateLimited) override
    {
      if(appWindow::available()) appWindow::instance()->check(rateLimited);
    }

    bool ready() override
    {
      return appWindow::available() && appWindow::instance()->ready();
    }

    void wait(double seconds, bool force) override
    {
      if(!appWindow::available()) return;
      if(seconds < 0.)
        appWindow::instance()->wait(force);
      else
        appWindow::instance()->wait(seconds, force);
    }

    void lock() override { appWindow::lock(); }
    void unlock() override { appWindow::unlock(); }
    int locked() override { return appWindow::locked(); }

    void postFromThread(const std::function<void()> &what) override
    {
      {
        std::lock_guard<std::mutex> lock(_mutex);
        _posted.push_back(what);
      }
      appWindow::wake();
    }

    void post(const std::function<void()> &what) override
    {
      // a frame is not re-entrant: what opens a window waits for it to be over
      appWindow *a = appWindow::instance();
      if(a && a->inFrame())
        a->postAction(what);
      else
        what();
    }

    void copyText(const std::string &text) override
    {
      ImGui::SetClipboardText(text.c_str());
    }

    void beep() override
    {
      fputc('\a', stderr);
      fflush(stderr);
    }

    // --- messages, the bar, and the questions that stop everything

    void addMessage(const std::string &text, int level) override
    {
      if(appWindow::available())
        appWindow::instance()->addMessage(text, level);
    }

    void messageLines(std::vector<std::string> &lines) override
    {
      if(appWindow::available() && appWindow::instance()->console())
        appWindow::instance()->console()->lines(lines);
    }

    void refreshBar() override
    {
      // the bar is drawn at every frame: only a frame to ask for
      if(appWindow::available()) appWindow::instance()->requestFrame();
    }
    void optionChanged(const std::string &) override
    {
      if(appWindow::available()) appWindow::instance()->requestRedraw();
    }

    int numWindows() override { return appWindow::available() ? 1 : 0; }

    void setWindowTitle(int which, const std::string &title) override
    {
      if(appWindow::available())
        appWindow::instance()->setGraphicTitle(title);
    }

    bool inputDialog(const std::string &question, std::string &value,
                     const std::string &hint, bool readOnly) override
    {
      if(!appWindow::available()) return false;
      std::string ask = question;
      if(hint.size()) ask += "\n" + hint;
      if(readOnly) {
        appWindow::instance()->inputDialog(ask + "\n\n" + value, value);
        return false;
      }
      return appWindow::instance()->inputDialog(ask, value);
    }

    int questionDialog(const std::string &question, const std::string &zero,
                       const std::string &one,
                       const std::string &two) override
    {
      if(!appWindow::available()) return 0;
      return appWindow::instance()->questionDialog(question, zero, one, two);
    }

    bool fileDialog(int mode, const std::string &title,
                    const std::vector<FileFormat> &formats,
                    std::vector<std::string> &names,
                    int *chosenFormat) override
    {
      if(!appWindow::available()) return false;
      std::string fileName = names.empty() ? "" : names[0];
      std::vector<fileBrowser::format> say;
      for(const auto &f : formats) {
        fileBrowser::format one;
        one.name = f.name;
        one.pattern = f.pattern;
        say.push_back(one);
      }
      if(!appWindow::instance()->fileDialog(mode == Create ? 1 : 0, title, say,
                                            fileName, chosenFormat))
        return false;
      names.assign(1, fileName);
      return true;
    }

    void applyColorScheme(bool dark) override
    {
      if(appWindow::available()) appWindow::instance()->applyStyle();
    }

    // --- the things that are described: drawn at every frame, so what is here is what to show, and a request for a frame

    void showForm(const Ui::Form &form, bool show) override
    {
      if(!appWindow::available()) return;
      if(show)
        appWindow::instance()->showDialog(form);
      else
        appWindow::instance()->hideDialog(form);
    }

    bool formVisible(const Ui::Form &form) override
    {
      return appWindow::available() &&
             appWindow::instance()->dialogVisible(form);
    }

    std::string formPane(const Ui::Form &form) override
    {
      return appWindow::available() ?
               appWindow::instance()->dialogPane(form) : "";
    }

    void setFormPane(const Ui::Form &form, const std::string &pane) override
    {
      if(appWindow::available())
        appWindow::instance()->setDialogPane(form, pane);
    }

    void dropForm(const Ui::Form &form) override
    {
      if(appWindow::available()) appWindow::instance()->dropDialog(form);
    }

    void showConsole(bool show) override
    {
      if(appWindow::available()) appWindow::instance()->showConsole(show);
    }

    bool consoleVisible() override
    {
      return appWindow::available() &&
             appWindow::instance()->consoleVisible();
    }

    void refreshTree(bool rebuild) override
    {
      if(appWindow::available()) appWindow::instance()->requestFrame();
    }

    void openTreeItem(const std::string &name, bool open) override
    {
      if(!appWindow::available()) return;
      if(open)
        appWindow::instance()->openTreeItem(name);
      else
        appWindow::instance()->closeTreeItem(name);
    }

    bool treeItemOpen(const std::string &name) override
    {
      return appWindow::available() &&
             appWindow::instance()->treeItemOpen(name);
    }

    void showTree() override
    {
      if(appWindow::available()) appWindow::instance()->showModulesPanel();
    }

    void refreshMenus() override
    {
      if(appWindow::available()) appWindow::instance()->requestFrame();
    }

    void setSolverButtonMode(const std::string &button0,
                             const std::string &button1) override
    {
      if(appWindow::available())
        appWindow::instance()->setSolverButtonMode(button0, button1);
    }

    void windowAction(const std::string &what) override
    {
      if(!appWindow::available()) return;
      appWindow *a = appWindow::instance();
      if(what == "new")
        a->newGraphicWindow();
      else if(what == "split_h")
        a->splitCurrentPane('h', 0.5);
      else if(what == "split_v")
        a->splitCurrentPane('v', 0.5);
      else if(what == "split_u")
        a->splitCurrentPane('u', 0.);
      else
        a->windowAction(what);
    }

    bool supports(const std::string &what) override
    {
      // the panels are not windows of their own; no image clipboard in GLFW;
      // every panel is already dragged in and out by hand
      if(what == "front" || what == "copy" || what == "attach_detach" ||
         what == "3m")
        return false;
      return true;
    }

    void dropped(const std::vector<std::string> &paths)
    {
      if(_host.filesDropped) _host.filesDropped(paths);
    }

    void drain()
    {
      std::vector<std::function<void()> > work;
      {
        std::lock_guard<std::mutex> lock(_mutex);
        work.swap(_posted);
      }
      for(auto &w : work) w();
    }

  private:
    Sources _sources;
    Host _host;
    std::mutex _mutex;
    std::vector<std::function<void()> > _posted;
  };

  backendImGui *_the = nullptr;

} // namespace

void drainPostedFromThread()
{
  if(_the) _the->drain();
}

void imguiDropped(const std::vector<std::string> &paths)
{
  if(_the) _the->dropped(paths);
}

const Ui::Backend::Sources &imguiSources()
{
  // before the interface was given anything, the settings are their defaults
  static Ui::Backend::Sources none = []() {
    Ui::Backend::Sources empty;
    empty.settings = []() { return Ui::Backend::Settings(); };
    return empty;
  }();
  return _the ? _the->sources() : none;
}

// made once
namespace {
  struct offeringImGui {
    offeringImGui()
    {
      Ui::offer("imgui", []() -> Ui::Backend * {
        if(!_the) _the = new backendImGui();
        return _the;
      });
    }
  };
  offeringImGui _offeringImGui;
}


#endif
