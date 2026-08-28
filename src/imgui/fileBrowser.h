// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef FILE_BROWSER_H
#define FILE_BROWSER_H

#include "GmshConfig.h"

#if defined(HAVE_IMGUI)

#include <string>
#include <vector>

// A file chooser drawn with Dear ImGui on top of std::filesystem, so that Gmsh
// does not depend on the file dialog of a widget toolkit and behaves the same
// on all the platforms. It is used through appWindow::fileDialog(), which shows
// it and pumps frames until the user has chosen: like the other blocking
// dialogs, it can therefore only be called from an action posted with
// appWindow::postAction().

class fileBrowser {
public:
  // where the "Home" button goes; the caller says once, so that the browser
  // has nothing to ask anyone
  static void setHome(const std::string &directory);

public:
  enum Mode { Open, Save };

private:
  struct entry {
    std::string name;
    bool isDir;
    entry(const std::string &n, bool d) : name(n), isDir(d) {}
  };

  Mode _mode;
  std::string _title;
  std::string _directory;
  char _fileName[1024];
  char _filter[256];
  std::vector<entry> _entries;
  int _selected;
  bool _active, _done, _accepted;
  bool _needRescan;
  std::string _message;

  void _rescan();

public:
  fileBrowser();
  // start showing the browser; filter is a space-separated list of extensions
  // ("*.geo *.msh"), empty for all the files
  void begin(Mode mode, const std::string &title, const std::string &filter,
             const std::string &initialName);
  bool active() const { return _active; }
  bool done() const { return _done; }
  bool accepted() const { return _accepted; }
  std::string result() const;
  void finish() { _active = false; }
  // draw one frame of the browser
  void draw();
};

#endif

#endif
