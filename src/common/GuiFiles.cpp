// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// What the File menu does, once, for whichever interface is up. It lived in
// src/imgui/menuBar.cpp, which meant the Dear ImGui layer knew how to open a
// project, guess an output format and write a .geo header -- the wrong way
// round: a toolkit is asked to show a chooser, it is not asked to know what a
// Gmsh file is.
//
// Everything here goes through two things the interface owns and nothing else:
// Gui::fileDialog(), which shows the chooser, and Msg::GetAnswer(), which asks
// the question.

#include "GmshConfig.h"

#include <cstdio>
#include <ctime>
#include <string>
#include <vector>

#include "GuiActions.h"
#include "GuiDialogs.h"
#include "Gui.h"
#include "GmshMessage.h"
#include "GmshDefines.h"
#include "Context.h"
#include "GModel.h"
#include "OpenFile.h"
#include "CreateFile.h"
#include "Options.h"
#include "OS.h"
#include "StringUtils.h"
#include "drawContext.h"

#if defined(HAVE_POST)
#include "PView.h"
#endif

namespace {

  // "File 'x' already exists. Do you want to replace it?", asked only when the
  // options say to ask and the file is really there
  bool _mayOverwrite(const std::string &name)
  {
    if(!CTX::instance()->confirmOverwrite) return true;
    if(StatFile(name)) return true; // it is not there
    std::string q = "File '" + name + "' already exists.\n\nDo you want to "
                    "replace it?";
    return Msg::GetAnswer(q.c_str(), 0, "Cancel", "Replace") != 0;
  }

} // namespace

void fileOpen(bool merge)
{
  std::string name;
  if(!Gui::fileDialog(0, merge ? "Merge file" : "Open file", "", name)) return;
#if defined(HAVE_POST)
  std::size_t views = PView::list.size();
#endif
  if(merge)
    MergeFile(name);
  else
    OpenProject(name);
#if defined(HAVE_POST)
  // a file that brought views along has something to show, so show it
  if(PView::list.size() != views) Gui::openModule("Post-processing");
#endif
  drawContext::global()->draw();
}

void fileOpenRecent(int index)
{
  if(index < 0 || index >= (int)CTX::instance()->recentFiles.size()) return;
  std::string name = CTX::instance()->recentFiles[index];
  if(name.empty()) return;
  OpenProject(name);
  drawContext::global()->draw();
}

void fileNew()
{
  std::string name;
  if(!Gui::fileDialog(1, "New geometry file", "*.geo", name)) return;
  std::vector<std::string> split = SplitFileName(name);
  if(split[2] != ".geo") {
    std::string q = "File '" + name + "' does not have the '.geo' extension."
                    "\n\nDo you want to continue as-is?";
    if(Msg::GetAnswer(q.c_str(), 0, "Continue as-is", "Use '.geo' extension"))
      name = split[0] + split[1] + ".geo";
  }
  if(!StatFile(name)) {
    std::string q = "File '" + name + "' already exists.\n\nDo you want to "
                    "delete it?";
    if(Msg::GetAnswer(q.c_str(), 0, "Cancel", "Delete"))
      UnlinkFile(name);
    else
      return;
  }
  FILE *fp = Fopen(name.c_str(), "w");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return;
  }
  int factory = Msg::GetAnswer("Which geometry kernel do you want to use?", 0,
                               "Built-in", "OpenCASCADE");
  time_t now;
  time(&now);
  fprintf(fp, "// Gmsh project created on %s", ctime(&now));
  if(factory) fprintf(fp, "SetFactory(\"OpenCASCADE\");\n");
  fclose(fp);
  OpenProject(name);
  drawContext::global()->draw();
}

void fileRename()
{
  std::string name = GModel::current()->getFileName();
  if(!Gui::fileDialog(1, "Rename model file", "", name)) return;
  if(!_mayOverwrite(name)) return;
  rename(GModel::current()->getFileName().c_str(), name.c_str());
  GModel::current()->setFileName(name);
  GModel::current()->setName(SplitFileName(name)[1]);
  Msg::SetOnelabChanged(3);
  drawContext::global()->draw();
}

void fileExport()
{
  std::string name = GModel::current()->getFileName();
  if(!Gui::fileDialog(1, "Export", "", name)) return;
  if(!_mayOverwrite(name)) return;
  double version = 0.;
  int format = GetFileFormatFromExtension(SplitFileName(name)[2], &version);
  if(format < 0) {
    Msg::Error("Unknown output file format for '%s'", name.c_str());
    return;
  }
  if(version > 0.)
    NumberOption(GMSH_SET, "Mesh", 0, "MshFileVersion", version, false);
  // what that format takes, which the interface asks for in a window of its own
  if(!Gui::exportOptionsDialog(format, name)) return;
  CreateOutputFile(name, format);
}

#if defined(HAVE_ONELAB)

void fileRemote(const std::string &what)
{
  if(what == "start") {
    // described once, with the commands given before it
    Dialog::showRemoteCommand();
    return;
  }
  std::string arg;
  if(what == "merge") {
    arg = "/tmp/data.pos";
    if(!Gui::inputDialog("File the remote Gmsh should merge:", arg)) return;
  }
  remoteAction(what, arg);
}

#else

void fileRemote(const std::string &what) {}

#endif
