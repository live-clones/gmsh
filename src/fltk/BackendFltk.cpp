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
#include "graphicWindow.h"
#include "openglWindow.h"
#include "fileDialogs.h"
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
      for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++)
        FlGui::instance()->graph[i]->getProgress()->redraw();
    }

    void sceneMessage(const std::string &first,
                      const std::string &second) override
    {
      if(!FlGui::available()) return;
      openglWindow *gl = FlGui::instance()->getCurrentOpenglWindow();
      if(!gl) return;
      if(first.size()) gl->screenMessage[0] = first;
      if(second.size()) gl->screenMessage[1] = second;
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

    bool inputDialog(const std::string &question, std::string &value) override
    {
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
                    const std::string &filter,
                    std::string &fileName) override
    {
      if(!fileChooser(mode ? FILE_CHOOSER_CREATE : FILE_CHOOSER_SINGLE,
                      title.c_str(), filter.c_str(), fileName.c_str()))
        return false;
      fileName = fileChooserGetName(1);
      return true;
    }

    bool formatOptionsDialog(int format, const std::string &fileName) override
    {
      // this interface asks for them inside its export chooser, which offers
      // the formats as filters; there is nothing more to ask here
      return true;
    }

    void applyColorScheme(bool dark) override
    {
      _dark = dark;
      if(FlGui::available()) FlGui::instance()->applyColorScheme(false);
    }

    bool supports(const std::string &what) override
    {
#if !defined(WIN32)
      // the proprietary extension has a window only in this interface
      if(what == "3m") return true;
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

    Host _host;
    bool _dark = false;
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
