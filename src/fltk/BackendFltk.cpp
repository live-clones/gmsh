// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_FLTK)

#include <cstdio>

#include <FL/Fl.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Window.H>

#include "Backend.h"
#include "FlGui.h"
#include <mutex>
#include "drawContext.h"

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

    void setHost(const Host &host) override { _host = host; }

    bool create(int argc, char **argv, bool quitShouldExit) override
    {
      if(!FlGui::available()) FlGui::instance(argc, argv, quitShouldExit,
                                              nullptr);
      return FlGui::available();
    }

    void destroy() override { FlGui::destroy(); }

    int runLoop() override
    {
      // the scene is drawn once before the loop, which is what makes a window
      // that has just come up show something
      drawContext::global()->draw(false);
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
      // both of them: the selection buffer and the clipboard proper, as the
      // window this replaces does
      Fl::copy(text.c_str(), (int)text.size(), 0);
      Fl::copy(text.c_str(), (int)text.size(), 1);
    }

    void beep() override { fl_beep(); }

    bool supports(const std::string &what) override
    {
#if !defined(WIN32)
      // the proprietary extension has a window only in this interface
      if(what == "3m") return true;
#endif
      return true;
    }

  private:
    Host _host;
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

} // namespace

Ui::Backend *makeUiBackend() { return new backendFltk(); }

#endif
