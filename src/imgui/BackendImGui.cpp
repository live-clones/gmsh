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
#include "appWindow.h"
#include "toolkit.h"

// Dear ImGui and GLFW, as the interface asks for them. Nothing here says
// anything about Gmsh.

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

    void setHost(const Host &host) override
    {
      _host = host;
      // where what the toolkit says goes, and what quitting means
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
      // an immediate mode frame is not re-entrant: anything that opens a
      // window of its own waits for the one being drawn to be over
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
      // GLFW has no bell; the terminal one is what there is
      fputc('\a', stderr);
      fflush(stderr);
    }

    bool supports(const std::string &what) override
    {
      // Nothing to bring to the front, since the panels are not windows of
      // their own; no image clipboard in GLFW; nothing to attach or detach,
      // since every panel is already dragged in and out of the dock space by
      // hand; and the proprietary extension has no window here.
      if(what == "front" || what == "copy" || what == "attach_detach" ||
         what == "3m")
        return false;
      return true;
    }

    // what the frame loop drains when it comes round
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
    Host _host;
    std::mutex _mutex;
    std::vector<std::function<void()> > _posted;
  };

  backendImGui *_the = nullptr;

} // namespace

// the frame loop asks for what came in from another thread
void drainPostedFromThread()
{
  if(_the) _the->drain();
}

Ui::Backend *makeUiBackend()
{
  if(!_the) _the = new backendImGui();
  return _the;
}

#endif
