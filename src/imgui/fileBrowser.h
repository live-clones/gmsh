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

// a file chooser on std::filesystem, the same on every platform; shown through
// appWindow::fileDialog(), which pumps frames until the user has chosen: from
// an action posted with postAction()

class fileBrowser {
public:
  enum Mode { Open, Save };
  // naming the formats is what tells an exported view which flavour of a shared
  // extension was wanted
  struct format {
    std::string name, pattern;
  };

private:
  struct entry {
    std::string name;
    bool isDir;
    entry(const std::string &n, bool d) : name(n), isDir(d) {}
  };

  Mode _mode;
  std::string _title;
  std::string _directory;
  // the directory as it is being typed
  char _where[1024];
  char _fileName[1024];
  char _filter[256];
  std::vector<format> _formats;
  int _chosen;
  std::vector<entry> _entries;
  int _selected;
  bool _active, _done, _accepted;
  bool _needRescan, _hidden;
  std::string _message;

  void _rescan();

public:
  fileBrowser();
  // a pattern is a space separated list of extensions ("*.geo *.msh"), empty
  // for all
  void begin(Mode mode, const std::string &title,
             const std::vector<format> &formats,
             const std::string &initialName);
  int chosen() const { return _formats.size() > 1 ? _chosen : -1; }
  bool active() const { return _active; }
  bool done() const { return _done; }
  bool accepted() const { return _accepted; }
  std::string result() const;
  void finish() { _active = false; }
  void draw();
};

#endif

#endif
