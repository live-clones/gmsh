// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The main window of the graphical interface (graphicWindow): its menu bar,
// the tiles of the scene, the tree of the modules (onelabGroup), the messages
// and the status bar. In this file, in order:
// - the callbacks of the menu bar (File, Window, Help), then the menu bar
//   itself (the actions of its items, whose menus are in Actions.cpp);
// - the callbacks of the status bar: the points of view, the query and the
//   measure (the modes that wait for clicks), the quick access menu, the
//   mouse selection, the models and the animation of the views;
// - the small widget classes of the window (its tile, menu bar, resizing,
//   progress bar), the table of the status bar buttons, the constructor, and
//   the methods that size and split the window, the menu and the messages.
// Elsewhere: the docking of the tool windows (toolDock.cpp), the items of the
// action registry and the operations on picked entities (actionMenus.cpp),
// the rows of the modules (onelabGroup.cpp).

#include "GmshConfig.h"
#include "GmshDefines.h"
#include "GmshVersion.h"
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sstream>
#include <string>
#include <algorithm>
#include <map>
#include <FL/Fl_Box.H>
#include <FL/fl_ask.H>
#include <FL/filename.H>
#include <FL/Fl_Menu_Button.H>
#include "FlGui.h"
#include "Shortcuts.h"
#include "mainWindow.h"
#include "paletteWindow.h"
#include "graphicWindow.h"
#include "sceneTool.h"
#include "toolDock.h"
#include "gmshScheme.h"
#include "icons.h"
#include "optionWindow.h"
#include "statisticsWindow.h"
#include "visibilityWindow.h"
#include "clippingWindow.h"
#include "manipWindow.h"
#include "pluginWindow.h"
#include "helpWindow.h"
#include "windowPlacement.h"
#include "openglWindow.h"
#include "editorWindow.h"
#include "onelabGroup.h"
#include "messageBrowser.h"
#include "gmshLocalNetworkClient.h"
#include "fileDialogs.h"
#include "extraDialogs.h"
#include "GModel.h"
#include "PView.h"
#include "PViewData.h"
#include "PViewOptions.h"
#include "OpenFile.h"
#include "CreateFile.h"
#include "Options.h"
#include "Context.h"
#include "StringUtils.h"
#include "OS.h"
#include "onelabUtils.h"
#include "selectionDriver.h"
#include "Actions.h"

#if defined(HAVE_MESH)
#include "gmshCrossFields.h"
#endif

#if defined(HAVE_3M)
#include "3M.h"
#endif

static void file_new_cb(Fl_Widget *w, void *data)
{
test:
  if(fileChooser(FILE_CHOOSER_CREATE, "New", "")) {
    std::string name = fileChooserGetName(1);
    std::vector<std::string> split = SplitFileName(name);
    if(split[2] != ".geo") {
      if(fl_choice("File '%s' does not have the '.geo' extension.\n\n"
                   "Do you want to continue as-is?",
                   "Continue as-is", "Use '.geo' extension", nullptr,
                   name.c_str()))
        name = split[0] + split[1] + ".geo";
    }
    if(!StatFile(name)) {
      if(fl_choice("File '%s' already exists.\n\nDo you want to delete it?",
                   "Cancel", "Delete", nullptr, name.c_str()))
        UnlinkFile(name);
      else
        goto test;
    }
    FILE *fp = Fopen(name.c_str(), "w");
    if(!fp) {
      Msg::Error("Unable to open file '%s'", name.c_str());
      return;
    }
    int factory = fl_choice("Which geometry kernel do you want to use?",
                            "Built-in", "OpenCASCADE", nullptr);
    time_t now;
    time(&now);
    fprintf(fp, "// Gmsh project created on %s", ctime(&now));
    if(factory) fprintf(fp, "SetFactory(\"OpenCASCADE\");\n");
    fclose(fp);
    OpenProject(name);
    drawContext::global()->draw();
  }
}

static const char *input_formats =
  "All Files\t*.*\n"
  "Geometry - Gmsh GEO\t*.geo\n"
#if defined(HAVE_ACIS)
  "Geometry - ACIS\t*.sat\n"
#endif
#if defined(HAVE_OCC)
  "Geometry - OpenCASCADE BRep\t*.brep\n"
  "Geometry - OpenCASCADE XAO\t*.xao\n"
#endif
#if defined(HAVE_PARASOLID)
  "Geometry - Parasolid XMT\t*.xmt_txt\n"
#endif
#if defined(HAVE_OCC) || defined(HAVE_PARASOLID_STEP)
  "Geometry - STEP\t*.{stp,step}\n"
#endif
#if defined(HAVE_OCC)
  "Geometry - IGES\t*.{igs,iges}\n"
#endif
  "Mesh - Gmsh MSH\t*.msh\n"
  "Mesh - Diffpack 3D\t*.diff\n"
  "Mesh - I-deas Universal\t*.unv\n"
#if defined(HAVE_MED)
  "Mesh - MED\t*.{med,mmed}\n"
#endif
  "Mesh - INRIA Medit\t*.mesh\n"
  "Mesh - Nastran Bulk Data File\t*.{bdf,nas}\n"
  "Mesh - GAMBIT Neutral File\t*.neu\n"
  "Mesh - Object File Format\t*.off\n"
  "Mesh - Wavefront File Format\t*.obj\n"
  "Mesh - Plot3D Structured Mesh\t*.p3d\n"
  "Mesh - STL Surface\t*.stl\n"
  "Mesh - VTK\t*.vtk\n"
  "Mesh - VTK XML Unstructured Grid\t*.{vtu,pvtu,pvd}\n"
  "Mesh - VRML Surface\t*.{wrl,vrml}\n"
  "Mesh - PLY2 Surface\t*.ply2\n"
  "Post-processing - Gmsh POS\t*.pos\n"
#if defined(HAVE_MED)
  "Post-processing - MED\t*.rmed\n"
#endif
  "Image - BMP\t*.bmp\n"
#if defined(HAVE_LIBJPEG)
  "Image - JPEG\t*.{jpg,jpeg}\n"
#endif
  "Image - PBM\t*.pbm\n"
  "Image - PGM\t*.pgm\n"
#if defined(HAVE_LIBPNG)
  "Image - PNG\t*.png\n"
#endif
  "Image - PNM\t*.pnm\n"
  "Image - PPM\t*.ppm\n";

static void file_open_merge_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  if(modelBusy()) return;
  std::string mode((char *)data);
  int n = PView::list.size();
  int f = fileChooser(FILE_CHOOSER_MULTI, (mode == "open") ? "Open" : "Merge",
                      input_formats);
  if(f) {
    for(int i = 1; i <= f; i++) {
      if(mode == "open")
        OpenProject(fileChooserGetName(i));
      else
        MergeFile(fileChooserGetName(i));
    }
    // the GUI may have been closed while the files were read
    if(!FlGui::available()) return;
    if(n != (int)PView::list.size())
      FlGui::instance()->openModule("Post-processing");
    if(CTX::instance()->launchSolverAtStartup >= 0)
      solver_cb(nullptr,
                (void *)(intptr_t)CTX::instance()->launchSolverAtStartup);
    else if(onelabUtils::haveSolverToRun())
      onelab_cb(nullptr, (void *)"check");
    drawContext::global()->draw();
  }
}

// the recent file of index data
static void file_open_recent_cb(Fl_Widget *w, void *data)
{
  std::size_t i = (intptr_t)data;
  if(i >= CTX::instance()->recentFiles.size()) return;
  if(modelBusy()) return;
  std::string str = CTX::instance()->recentFiles[i];
  int n = PView::list.size();
  OpenProject(str);
  // the GUI may have been closed while the file was read
  if(!FlGui::available()) return;
  drawContext::global()->draw();
  if(n != (int)PView::list.size())
    FlGui::instance()->openModule("Post-processing");
  if(CTX::instance()->launchSolverAtStartup >= 0)
    solver_cb(nullptr,
              (void *)(intptr_t)CTX::instance()->launchSolverAtStartup);
  else if(onelabUtils::haveSolverToRun())
    onelab_cb(nullptr, (void *)"check");
}

static void file_clear_cb(Fl_Widget *w, void *data)
{
  if(modelBusy()) return;
  if(solverBusy()) return;
  ClearProject();
  if(onelabUtils::haveSolverToRun())
    onelab_cb(nullptr, (void *)"reset"); // this will call OpenProject
  else
    OpenProject(GModel::current()->getFileName());
  drawContext::global()->draw();
}

static void file_remote_cb(Fl_Widget *w, void *data)
{
  onelab::localNetworkClient *c;
  auto it = onelab::server::instance()->findClient("GmshRemote");
  if(it == onelab::server::instance()->lastClient()) {
    c = new gmshLocalNetworkClient("GmshRemote", "");
    c->setSocketSwitch("-socket");
  }
  else
    c = (onelab::localNetworkClient *)(*it);
  GmshServer *server = c->getGmshServer();

  std::string str((const char *)data);

  if(str == "start") {
    if(server) {
      Msg::Error("Cannot start: remote Gmsh is already running");
      return;
    }
    c->setExecutable(connectionChooser());
    if(c->getExecutable().size()) c->run();
  }
  else {
    if(!server) {
      Msg::Error("Cannot %s: remote Gmsh not running", str.c_str());
      return;
    }
    if(str == "stop") {
      server->SendString(GmshSocket::GMSH_STOP, "Disconnect!");
    }
    else if(str == "merge") {
      const char *file = fl_input("Merge", "/tmp/data.pos");
      if(file) server->SendString(GmshSocket::GMSH_MERGE_FILE, file);
    }
    else if(str == "clear") {
      server->SendString(GmshSocket::GMSH_PARSE_STRING, "Delete All;");
      for(int i = PView::list.size() - 1; i >= 0; i--)
        if(PView::list[i]->getData()->isRemote()) delete PView::list[i];
      FlGui::instance()->updateViews(true);
      drawContext::global()->draw();
    }
    else if(str == "test") {
      server->SendString(GmshSocket::GMSH_SPEED_TEST, "Speed test");
    }
  }
}

void file_window_cb(Fl_Widget *w, void *data)
{
  std::string str((const char *)data);
  if(str == "new") {
    graphicWindow *g1 = FlGui::instance()->graph.back();
    graphicWindow *g2 = new graphicWindow(false, CTX::instance()->numTiles);
    FlGui::instance()->graph.push_back(g2);
    g2->getWindow()->resize(g1->getWindow()->x() + 10,
                            g1->getWindow()->y() + 10, g1->getWindow()->w(),
                            g1->getWindow()->h());
    g2->getWindow()->show();
  }
  else if(str == "split_h") {
    FlGui::instance()->splitCurrentOpenglWindow('h', 0.5);
  }
  else if(str == "split_v") {
    FlGui::instance()->splitCurrentOpenglWindow('v', 0.5);
  }
  else if(str == "split_u") {
    FlGui::instance()->splitCurrentOpenglWindow('u');
  }
  else if(str == "copy") {
    FlGui::instance()->copyCurrentOpenglWindowToClipboard();
  }
  drawContext::global()->draw();
  FlGui::instance()->setGraphicTitle(GModel::current()->getFileName());
}

// the export menu's own formats, for those both the mesh and the views write
enum { EXPORT_MESH_X3D = -2, EXPORT_VIEW_X3D = -3, EXPORT_MESH_STAT = -4 };

// the options dialog of an export format, which then writes the file, or the
// file written directly
static int exportFile(const char *name, int format)
{
  switch(format) {
  case FORMAT_AUTO: {
    int guessed = GuessFileFormatFromFileName(name);
    if(guessed >= 0 && guessed != FORMAT_AUTO) return exportFile(name, guessed);
    CreateOutputFile(name, FORMAT_AUTO);
    return 1;
  }
  case FORMAT_OPT: return optionsFileDialog(name);
  case FORMAT_GEO: return geoFileDialog(name);
  case FORMAT_MSH: return mshFileDialog(name);
  case FORMAT_INP:
    return unvinpFileDialog(name, "Abaqus INP Options", FORMAT_INP);
  case FORMAT_UNV: return unvinpFileDialog(name, "UNV Options", FORMAT_UNV);
  case FORMAT_KEY:
    return keyRadFileDialog(name, "LSDYNA KEY Options", FORMAT_KEY);
  case FORMAT_RAD:
    return keyRadFileDialog(name, "RADIOSS Block Options", FORMAT_RAD);
  case FORMAT_MED: return medFileDialog(name);
  case FORMAT_BDF: return bdfFileDialog(name);
  case FORMAT_STL: return stlFileDialog(name);
  case FORMAT_VTU:
  case FORMAT_PVTU: return vtuFileDialog(name);
  case FORMAT_VTK:
    return genericMeshFileDialog(name, "VTK Options", format, true, false);
  case FORMAT_TOCHNOG:
    return genericMeshFileDialog(name, "Tochnog Options", format, true, false);
  case FORMAT_DIFF:
    return genericMeshFileDialog(name, "Diffpack Options", format, true, false);
  case FORMAT_MESH:
    return genericMeshFileDialog(name, "MESH Options", format, false, true);
  case FORMAT_IR3:
    return genericMeshFileDialog(name, "Iridium Options", format, false, true);
  case FORMAT_CELUM:
    return genericMeshFileDialog(name, "CELUM Options", format, false, false);
  case FORMAT_SU2:
    return genericMeshFileDialog(name, "SU2 Options", format, false, false);
  case FORMAT_OFF:
    return genericMeshFileDialog(name, "OFF Options", format, false, false);
  case FORMAT_OBJ:
    return genericMeshFileDialog(name, "OBJ Options", format, false, false);
  case FORMAT_MAIL:
    return genericMeshFileDialog(name, "MAIL Options", format, false, false);
  case FORMAT_MATLAB:
    return genericMeshFileDialog(name, "MATLAB Options", format, false, false);
  case FORMAT_P3D:
    return genericMeshFileDialog(name, "P3D Options", format, false, false);
  case FORMAT_VRML:
    return genericMeshFileDialog(name, "VRML Options", format, false, false);
  case FORMAT_PLY2:
    return genericMeshFileDialog(name, "PLY2 Options", format, false, false);
  case FORMAT_NEU:
    return genericMeshFileDialog(name, "NEU Options", format, false, false);
  case FORMAT_X3D:
    return exportFile(name,
                      PView::list.empty() ? EXPORT_MESH_X3D : EXPORT_VIEW_X3D);
  case EXPORT_MESH_X3D:
    return genericMeshFileDialog(name, "X3D Options", FORMAT_X3D, false, false);
  case EXPORT_VIEW_X3D: return x3dViewFileDialog(name, "X3D Options", 7);
  case EXPORT_MESH_STAT: return meshStatFileDialog(name);
  case FORMAT_POS: return posFileDialog(name);
  case FORMAT_RMED:
    return genericViewFileDialog(name, "MED Options", PView::MED);
  case FORMAT_TXT:
    return genericViewFileDialog(name, "TXT Options", PView::TXT);
  case FORMAT_EPS: return gl2psFileDialog(name, "EPS Options", format);
  case FORMAT_PDF: return gl2psFileDialog(name, "PDF Options", format);
  case FORMAT_PS: return gl2psFileDialog(name, "PS Options", format);
  case FORMAT_SVG: return gl2psFileDialog(name, "SVG Options", format);
  case FORMAT_TIKZ: return gl2psFileDialog(name, "TIKZ Options", format);
  case FORMAT_JPEG:
    return genericBitmapFileDialog(name, "JPEG Options", format);
  case FORMAT_PNG: return genericBitmapFileDialog(name, "PNG Options", format);
  case FORMAT_PPM: return genericBitmapFileDialog(name, "PPM Options", format);
  case FORMAT_YUV: return genericBitmapFileDialog(name, "YUV Options", format);
  case FORMAT_PGF: return pgfBitmapFileDialog(name, "PGF Options", format);
  case FORMAT_GIF: return gifFileDialog(name);
  case FORMAT_TEX: return latexFileDialog(name);
  case FORMAT_MPEG:
  case FORMAT_MP4: return mpegFileDialog(name, format);
  default: // CGNS, VIS, BREP, XAO, STEP, IGES, XMT and the others with no options
    CreateOutputFile(name, format);
    return 1;
  }
}

static void file_export_cb(Fl_Widget *w, void *data)
{
  static const struct {
    const char *pattern;
    int format;
  } formats[] = {
    {"Guess From Extension\t*.*", FORMAT_AUTO},
    {"Geometry - Gmsh Options\t*.opt", FORMAT_OPT},
    {"Geometry - Gmsh Unrolled GEO\t*.geo_unrolled", FORMAT_GEO},
    {"Geometry - Gmsh Visibility\t*.vis", FORMAT_VIS},
#if defined(HAVE_OCC)
    {"Geometry - OpenCASCADE BRep\t*.brep", FORMAT_BREP},
    {"Geometry - OpenCASCADE XAO\t*.xao", FORMAT_XAO},
#endif
#if defined(HAVE_PARASOLID)
    {"Geometry - Parasolid XMT\t*.xmt_txt", FORMAT_XMT},
#endif
#if defined(HAVE_OCC) || defined(HAVE_PARASOLID_STEP)
    {"Geometry - STEP\t*.step", FORMAT_STEP},
#endif
#if defined(HAVE_OCC)
    {"Geometry - IGES\t*.iges", FORMAT_IGES},
#endif
    {"Mesh - Gmsh MSH\t*.msh", FORMAT_MSH},
    {"Mesh - Abaqus INP\t*.inp", FORMAT_INP},
    {"Mesh - LSDYNA KEY\t*.key", FORMAT_KEY},
    {"Mesh - RADIOSS BLOCK\t*_0000.rad", FORMAT_RAD},
    {"Mesh - CELUM\t*.celum", FORMAT_CELUM},
#if defined(HAVE_LIBCGNS)
    {"Mesh - CGNS (Experimental)\t*.cgns", FORMAT_CGNS},
#endif
    {"Mesh - Diffpack 3D\t*.diff", FORMAT_DIFF},
    {"Mesh - I-deas Universal\t*.unv", FORMAT_UNV},
    {"Mesh - Iridum\t*.ir3", FORMAT_IR3},
#if defined(HAVE_MED)
    {"Mesh - MED\t*.med", FORMAT_MED},
#endif
    {"Mesh - INRIA Medit\t*.mesh", FORMAT_MESH},
    {"Mesh - CEA Triangulation\t*.mail", FORMAT_MAIL},
    {"Mesh - Matlab\t*.m", FORMAT_MATLAB},
    {"Mesh - Nastran Bulk Data File\t*.bdf", FORMAT_BDF},
    {"Mesh - Object File Format\t*.off", FORMAT_OFF},
    {"Mesh - Wavefront File Format\t*.obj", FORMAT_OBJ},
    {"Mesh - Plot3D Structured Mesh\t*.p3d", FORMAT_P3D},
    {"Mesh - STL Surface\t*.stl", FORMAT_STL},
    {"Mesh - VRML Surface\t*.wrl", FORMAT_VRML},
    {"Mesh - VTK\t*.vtk", FORMAT_VTK},
    {"Mesh - VTK XML Unstructured Grid\t*.vtu", FORMAT_VTU},
    {"Mesh - Tochnog\t*.dat", FORMAT_TOCHNOG},
    {"Mesh - PLY2 Surface\t*.ply2", FORMAT_PLY2},
    {"Mesh - SU2\t*.su2", FORMAT_SU2},
    {"Mesh - GAMBIT Neutral File\t*.neu", FORMAT_NEU},
    {"Mesh - X3D\t*.x3d", EXPORT_MESH_X3D},
    {"Post-processing - Gmsh POS\t*.pos", FORMAT_POS},
    {"Post-processing - X3D\t*.x3d", EXPORT_VIEW_X3D},
#if defined(HAVE_MED)
    {"Post-processing - MED\t*.rmed", FORMAT_RMED},
#endif
    {"Post-processing - Generic TXT\t*.txt", FORMAT_TXT},
    {"Post-processing - Mesh Statistics\t*.pos", EXPORT_MESH_STAT},
    {"Image - Encapsulated PostScript\t*.eps", FORMAT_EPS},
    {"Image - GIF\t*.gif", FORMAT_GIF},
#if defined(HAVE_LIBJPEG)
    {"Image - JPEG\t*.jpg", FORMAT_JPEG},
#endif
    {"Image - LaTeX\t*.tex", FORMAT_TEX},
    {"Image - PDF\t*.pdf", FORMAT_PDF},
#if defined(HAVE_LIBPNG)
    {"Image - PNG\t*.png", FORMAT_PNG},
    {"Image - PGF\t*.pgf", FORMAT_PGF},
#endif
    {"Image - PostScript\t*.ps", FORMAT_PS},
    {"Image - PPM\t*.ppm", FORMAT_PPM},
    {"Image - SVG\t*.svg", FORMAT_SVG},
    {"Image - TIKZ\t*.tikz", FORMAT_TIKZ},
    {"Image - YUV\t*.yuv", FORMAT_YUV},
#if defined(HAVE_MPEG_ENCODE)
    {"Movie - MPEG\t*.mpg", FORMAT_MPEG},
#endif
#if defined(HAVE_FFMPEG)
    {"Movie - MP4\t*.mp4", FORMAT_MP4},
#endif
  };
  int nbformats = sizeof(formats) / sizeof(formats[0]);
  static std::string pat;
  if(pat.empty()) {
    for(int i = 0; i < nbformats; i++)
      pat += std::string(i ? "\n" : "") + formats[i].pattern;
  }

test:
  if(fileChooser(FILE_CHOOSER_CREATE, "Export", pat.c_str())) {
    std::string name = fileChooserGetName(1);
    bool confirmOverwrite = CTX::instance()->confirmOverwrite;
#if defined(__APPLE__)
    // handled directly by the native macOS file chooser
    if(CTX::instance()->nativeFileChooser) confirmOverwrite = false;
#endif
    if(confirmOverwrite) {
      if(!StatFile(name))
        if(!fl_choice("File '%s' already exists.\n\nDo you want to replace it?",
                      "Cancel", "Replace", nullptr, name.c_str()))
          goto test;
    }
    int i = fileChooserGetFilter();
    // any additional automatic fltk filter guesses from the extension
    int format = (i >= 0 && i < nbformats) ? formats[i].format : FORMAT_AUTO;
    if(!exportFile(name.c_str(), format)) goto test;
  }
}

static void file_options_save_cb(Fl_Widget *w, void *data)
{
  std::string str((const char *)data), fileName;
  if(str == "file")
    fileName = GModel::current()->getFileName() + ".opt";
  else
    fileName = CTX::instance()->homeDir + CTX::instance()->optionsFileName;
  Msg::StatusBar(true, "Writing '%s'...", fileName.c_str());
  if(str == "file")
    PrintOptions(0, GMSH_FULLRC, 0, 0, fileName.c_str());
  else
    PrintOptions(0, GMSH_OPTIONSRC, 1, 1, fileName.c_str());
  Msg::StatusBar(true, "Done writing '%s'", fileName.c_str());
}

static void file_rename_cb(Fl_Widget *w, void *data)
{
test:
  if(fileChooser(FILE_CHOOSER_CREATE, "Rename", "")) {
    std::string name = fileChooserGetName(1);
    bool confirmOverwrite = CTX::instance()->confirmOverwrite;
#if defined(__APPLE__)
    // handled directly by the native macOS file chooser
    if(CTX::instance()->nativeFileChooser) confirmOverwrite = false;
#endif
    if(confirmOverwrite) {
      if(!StatFile(name))
        if(!fl_choice("File '%s' already exists.\n\nDo you want to replace it?",
                      "Cancel", "Replace", nullptr, name.c_str()))
          goto test;
    }
    rename(GModel::current()->getFileName().c_str(), name.c_str());
    GModel::current()->setFileName(name);
    GModel::current()->setName(SplitFileName(name)[1]);
    Msg::SetOnelabChanged(3);
    if(onelabUtils::haveSolverToRun()) onelab_cb(nullptr, (void *)"check");
    drawContext::global()->draw();
  }
}

static void file_delete_cb(Fl_Widget *w, void *data)
{
  if(fl_choice("Do you really want to delete file '%s'?", "Cancel", "Delete",
               nullptr, GModel::current()->getFileName().c_str())) {
    UnlinkFile(GModel::current()->getFileName());
    Msg::Info("Deleted `%s'", GModel::current()->getFileName().c_str());
    file_clear_cb(nullptr, nullptr);
  }
}

// not while an event is handled (the timer runs in the event loops of its
// callbacks too, e.g. of a computation), its widgets' code still running
static void destroyGui(void *)
{
  if(FlGui::handlingEvent())
    Fl::repeat_timeout(0.1, destroyGui);
  else
    FlGui::destroy();
}

void file_quit_cb(Fl_Widget *w, void *data)
{
  // save persistent info to disk
  if(CTX::instance()->sessionSave) {
    PrintOptions(
      0, GMSH_SESSIONRC, 0, 0,
      (CTX::instance()->homeDir + CTX::instance()->sessionFileName).c_str());
  }
  if(CTX::instance()->optionsSave == 1) {
    PrintOptions(
      0, GMSH_OPTIONSRC, 1, 0,
      (CTX::instance()->homeDir + CTX::instance()->optionsFileName).c_str());
  }
  else if(CTX::instance()->optionsSave == 2) {
    std::string fileName = GModel::current()->getFileName() + ".opt";
    PrintOptions(0, GMSH_FULLRC, 1, 0, fileName.c_str());
    // also save visibility info - same as with fltk::run("options")
    visibility_save(fileName);
  }

  if(FlGui::instance()->quitShouldExit()) { Msg::Exit(0); }
  else {
    // once the event that asked for it is over: the widget it came through (a
    // menu bar, a button) goes with the windows, while its code still runs
    Fl::add_timeout(0., destroyGui);
  }
}

void file_watch_cb(Fl_Widget *w, void *data)
{
  if(w) CTX::instance()->watchFilePattern = patternChooser();

  if(CTX::instance()->watchFilePattern.empty()) return;
  // the files are merged when no other operation is on the model (silently:
  // the animation asks at each step)
  if(CTX::instance()->lock) return;

  std::string pattern = FixRelativePath(GModel::current()->getFileName(),
                                        CTX::instance()->watchFilePattern);
  std::string directory = SplitFileName(pattern)[0];
  if(directory.empty()) directory = "./";

  dirent **files = nullptr;
  int num = fl_filename_list(directory.c_str(), &files, fl_numericsort);
  if(num <= 0) return;
  std::vector<std::string> matches;
  for(int i = 0; i < num; i++) {
    std::string name = directory + files[i]->d_name;
    if(fl_filename_match(name.c_str(), pattern.c_str()))
      matches.push_back(name);
    free((void *)files[i]);
  }
  if(files) free((void *)files);

  Msg::Info("%d match%s for pattern '%s'", (int)matches.size(),
            (matches.size() > 1) ? "es" : "", pattern.c_str());

  std::set<std::string> allFiles;
  for(std::size_t i = 0; i < GModel::list.size(); i++)
    allFiles.insert(GetFileNameWithoutPath(GModel::list[i]->getFileName()));
  for(std::size_t i = 0; i < PView::list.size(); i++)
    for(int j = 0; j < PView::list[i]->getData()->getNumTimeSteps(); j++)
      allFiles.insert(
        GetFileNameWithoutPath(PView::list[i]->getData()->getFileName(j)));

  for(std::size_t i = 0; i < matches.size(); i++)
    if(allFiles.find(GetFileNameWithoutPath(matches[i])) == allFiles.end())
      MergeFile(matches[i]);
  drawContext::global()->draw();
}

static void help_online_cb(Fl_Widget *w, void *data)
{
  if(std::string(GMSH_EXTRA_VERSION) == "")
    fl_open_uri("https://gmsh.info/doc/texinfo/gmsh.html");
  else
    fl_open_uri("https://gmsh.info/dev/doc/texinfo/gmsh.html");
}

static void help_basic_cb(Fl_Widget *w, void *data)
{
  centerWindow(FlGui::instance()->help->basic);
  FlGui::instance()->help->basic->show();
}

void help_about_cb(Fl_Widget *w, void *data)
{
  centerWindow(FlGui::instance()->help->about);
  FlGui::instance()->help->about->show();
}

void geometry_edit_cb(Fl_Widget *w, void *data)
{ editFile(GModel::current()->getFileName()); }

void onelab_reload_cb(Fl_Widget *w, void *data)
{
  if(modelBusy()) return;
  if(solverBusy()) return;

  std::string fileName = GModel::current()->getFileName();
  ClearProject();
  GModel::current()->setFileName(fileName);
  onelab_cb(nullptr, (void *)"reset"); // will call OpenProject
  drawContext::global()->draw();
}

void geometry_reload_cb(Fl_Widget *w, void *data)
{
  if(onelabUtils::haveSolverToRun()) {
    onelab_cb(nullptr, (void *)"check_always");
  }
  else {
    onelab_cb(nullptr, (void *)"reload");
    OpenProject(GModel::current()->getFileName());
  }
  drawContext::global()->draw();
}

void mesh_save_cb(Fl_Widget *w, void *data)
{
  std::string name = CTX::instance()->outputFileName;
  if(name.empty()) {
    if(CTX::instance()->mesh.fileFormat == FORMAT_AUTO)
      name = GetDefaultFileName(FORMAT_MSH);
    else
      name = GetDefaultFileName(CTX::instance()->mesh.fileFormat);
  }
  if(CTX::instance()->confirmOverwrite) {
    if(!StatFile(name))
      if(!fl_choice("File '%s' already exists.\n\nDo you want to replace it?",
                    "Cancel", "Replace", nullptr, name.c_str()))
        return;
  }
  CreateOutputFile(name, CTX::instance()->mesh.fileFormat);
}

// The actions of the menu bar, by the names the "Menu bar" menu of the
// registry gives them (see Actions.cpp), which are those of their shortcuts
static void help_current_options_cb(Fl_Widget *w, void *data);

static fltkAction call(Fl_Callback *f, void *data = nullptr)
{
  return {[f, data](int) { f(nullptr, data); }};
}

// whether a string is valid UTF-8, as a menu label must be
static bool check_utf8(const std::string &string)
{
  for(int i = 0, ix = string.length(); i < ix; i++) {
    int n;
    int c = (unsigned char)string[i];
    if(0x00 <= c && c <= 0x7f)
      n = 0; // 0bbbbbbb
    else if((c & 0xE0) == 0xC0)
      n = 1; // 110bbbbb
    else if(c == 0xed && i < (ix - 1) &&
            ((unsigned char)string[i + 1] & 0xa0) == 0xa0)
      return false; // U+d800 to U+dfff
    else if((c & 0xF0) == 0xE0)
      n = 2; // 1110bbbb
    else if((c & 0xF8) == 0xF0)
      n = 3; // 11110bbb
    // else if (($c & 0xFC) == 0xF8) n=4; // 111110bb //byte 5, unnecessary in 4
    // byte UTF-8 else if (($c & 0xFE) == 0xFC) n=5; // 1111110b //byte 6,
    // unnecessary in 4 byte UTF-8
    else
      return false;
    for(int j = 0; j < n && i < ix; j++) { // n bytes matching 10bbbbbb follow ?
      if((++i == ix) || (((unsigned char)string[i] & 0xC0) != 0x80))
        return false;
    }
  }
  return true;
}

// the submenu path of the recent files (see fillRecentHistoryMenu()); the
// second one, the file opened before the current one, has a shortcut
static void addRecentFiles(Fl_Menu_ *m, const std::string &path)
{
  // (add() makes a new submenu of a path that is one already)
  if(m->find_index(path.c_str()) < 0)
    m->add(path.c_str(), 0, nullptr, nullptr, FL_SUBMENU);
  const std::vector<std::string> &files = CTX::instance()->recentFiles;
  for(std::size_t i = 0; i < files.size(); i++) {
    if(!check_utf8(files[i])) {
      Msg::Info("Ignoring invalid General.RecentFile%d", (int)i);
      continue;
    }
    // (add() takes a label starting with '/' as it is; otherwise '/' would
    // make a submenu, and '\\' or a leading '_' would be read as well)
    std::string label;
    if(files[i][0] != '/') {
      for(char c : files[i]) {
        if(c == '/' || c == '\\' || (c == '_' && label.empty())) label += '\\';
        label += c;
      }
    }
    else
      label = files[i];
    m->add((path + "/" + label).c_str(),
           i == 1 ? fltkShortcut("file_recent") : 0, file_open_recent_cb,
           (void *)(intptr_t)i);
  }
}

const std::map<std::string, fltkAction> &menuBarActions()
{
  static const std::map<std::string, fltkAction> actions = {
    {"file_new", call(file_new_cb)},
    {"file_open", call(file_open_merge_cb, (void *)"open")},
    {"recent_files", {nullptr, nullptr, addRecentFiles}},
    {"file_recent", call(file_open_recent_cb, (void *)1)},
    {"file_merge", call(file_open_merge_cb, (void *)"merge")},
    {"watch", call(file_watch_cb)},
    {"file_clear", call(file_clear_cb)},
    {"file_rename", call(file_rename_cb)},
    {"file_delete", call(file_delete_cb)},
    {"remote_start", call(file_remote_cb, (void *)"start")},
    {"remote_merge", call(file_remote_cb, (void *)"merge")},
    {"remote_clear", call(file_remote_cb, (void *)"clear")},
    {"remote_stop", call(file_remote_cb, (void *)"stop")},
    {"options_save", call(file_options_save_cb, (void *)"file")},
    {"options_save_default", call(file_options_save_cb, (void *)"default")},
    {"file_export", call(file_export_cb)},
    {"quit", call(file_quit_cb)},
    {"options", call(options_cb)},
    {"plugins", call(plugin_cb, (void *)(-1))},
    {"visibility", call(visibility_cb)},
    {"clipping", call(clip_cb)},
    {"manipulator", call(manip_cb)},
#if defined(HAVE_3M)
    {"window_3m", call(window3M_cb)},
#endif
    {"statistics", call(statistics_cb)},
    {"console", call(show_hide_message_cb)},
    {"window_new", call(file_window_cb, (void *)"new")},
    {"window_copy", call(file_window_cb, (void *)"copy")},
    {"minimize", call(window_cb, (void *)"minimize")},
    {"window_zoom", call(window_cb, (void *)"zoom")},
    {"menu_show_hide", call(show_hide_menu_cb)},
    {"menu_attach_detach", call(attach_detach_menu_cb)},
    {"dock", call(dock_tool_cb)},
    {"dock_all", call(dock_tools_cb)},
    {"window_front", call(window_cb, (void *)"front")},
    {"help_online", call(help_online_cb)},
    {"help_keys", call(help_basic_cb)},
    {"help_options", call(help_current_options_cb)},
    {"options_restore_defaults", call(options_restore_defaults_cb)},
    {"help_about", call(help_about_cb)},
  };
  return actions;
}


static graphicWindow *getGraphicWindow(Fl_Widget *w)
{
  if(!w || !w->parent()) return FlGui::instance()->graph[0];
  for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++)
    if(FlGui::instance()->graph[i]->getWindow() == w->parent())
      return FlGui::instance()->graph[i];
  return FlGui::instance()->graph[0];
}

void status_xyz1p_cb(Fl_Widget *w, void *data)
{
  const char *str = (const char *)data;

  // the viewports of the window of the button; from a shortcut the current
  // one, or all those of its window to sync them (Ctrl)
  std::vector<openglWindow *> gls;
  openglWindow *current = FlGui::instance()->getCurrentOpenglWindow();
  bool sync = Fl::event_state(FL_CTRL) || Fl::event_state(FL_META);
  if(w)
    gls = getGraphicWindow(w)->gl;
  else if(sync) {
    for(graphicWindow *g : FlGui::instance()->graph)
      if(std::find(g->gl.begin(), g->gl.end(), current) != g->gl.end())
        gls = g->gl;
  }
  if(gls.empty()) gls.push_back(current);

  for(std::size_t i = 0; i < gls.size(); i++) {
    drawContext *ctx = gls[i]->getDrawContext();
    if(!strcmp(str, "r")) {
      // rotate +90 or -90 (shift) degress around axis perp to the
      // screen, or sync rotation with first window (Ctrl)
      double axis[3] = {0., 0., 1.};
      if(Fl::event_state(FL_CTRL) || Fl::event_state(FL_META)) {
        if(i != 0) {
          drawContext *ctx0 = gls[0]->getDrawContext();
          ctx->setQuaternion(ctx0->quaternion[0], ctx0->quaternion[1],
                             ctx0->quaternion[2], ctx0->quaternion[3]);
        }
      }
      else if(!Fl::event_state(FL_SHIFT)) {
        ctx->addQuaternionFromAxisAndAngle(axis, -90.);
        if(CTX::instance()->camera) ctx->camera.tiltHeadRight();
      }
      else {
        ctx->addQuaternionFromAxisAndAngle(axis, 90.);
        if(CTX::instance()->camera) ctx->camera.tiltHeadLeft();
      }
    }
    else if(!strcmp(str, "1:1")) {
      // if Shift is pressed, reset bounding box around visible entities
      if(Fl::event_state(FL_SHIFT)) SetBoundingBox(true);
      // fit the model in the window, or sync translation and scaling with the
      // first window (Ctrl)
      if(!CTX::instance()->camera &&
         (Fl::event_state(FL_CTRL) || Fl::event_state(FL_META))) {
        if(i != 0) {
          drawContext *ctx0 = gls[0]->getDrawContext();
          for(int j = 0; j < 3; j++) {
            ctx->t[j] = ctx0->t[j];
            ctx->s[j] = ctx0->s[j];
          }
        }
      }
      else
        ctx->standardView(str, false);
    }
    else {
      // an axis pointing out of the screen, or into it (Shift), the
      // isometric view, or no rotation, translation or scaling
      ctx->standardView(str, Fl::event_state(FL_SHIFT));
    }
  }
  drawContext::global()->draw();
  FlGui::instance()->manip->update();
}

static void model_switch_cb(Fl_Widget *w, void *data)
{
  int index = (intptr_t)data;
  GModel::current(index);
  SetBoundingBox();
  for(std::size_t i = 0; i < GModel::list.size(); i++)
    GModel::list[i]->setVisibility(0);
  GModel::current()->setVisibility(1);
  CTX::instance()->meshChanged();
  Msg::SetWindowTitle(GModel::current()->getFileName());
  FlGui::instance()->resetVisibility();
  drawContext::global()->draw();
}

// The two tools that take the clicks on the model, until asked to stop (their
// button again, or Escape), shared with the web page (see sceneTool):
// - in query mode, every click says what the model holds where it hit: the
//   entity, the mesh element and the node there, and the value of every
//   visible view. A click replaces what the queries before it left on the
//   picture, a Ctrl+click adds to it. (The first query of a large mesh or view
//   builds a search structure that the ones after it reuse.)
// - in measure mode, two clicks give the distance between the points they hit,
//   drawn on the picture and printed.
// Starting one stops the other.
bool queryMode() { return sceneTool::running("Query"); }

bool measureMode() { return sceneTool::running("Measure"); }

static void toggleTool(const std::string &name)
{
  if(!FlGui::available()) return;
  if(sceneTool::running(name)) {
    sceneTool::stop();
    return;
  }
  sceneTool::start(name == "Query" ? newQueryTool() : newMeasureTool(),
                   FlGui::instance()->getCurrentOpenglWindow());
}

void updateModeButtons()
{
  if(!FlGui::available()) return;
  // a query and a measurement in yellow, as what they leave on the picture by
  // default (see General.Color.Query)
  Fl_Color col = gmshIndicator(IndicatorYellow);
  for(graphicWindow *g : FlGui::instance()->graph) {
    g->getQueryButton()->color(queryMode() ? col : FL_BACKGROUND_COLOR);
    g->getQueryButton()->redraw();
    g->getMeasureButton()->color(measureMode() ? col : FL_BACKGROUND_COLOR);
    g->getMeasureButton()->redraw();
    g->getSelectionButton()->color(
      CTX::instance()->mouseSelection ? FL_BACKGROUND_COLOR :
                                        gmshIndicator(IndicatorRed));
    g->getSelectionButton()->redraw();
  }
}

void status_query_cb(Fl_Widget *w, void *data) { toggleTool("Query"); }

void status_measure_cb(Fl_Widget *w, void *data) { toggleTool("Measure"); }

// the menu of the models, to pick the current one
static void status_model_cb(Fl_Widget *w, void *data)
{
  std::vector<char *> tofree;
  std::vector<Fl_Menu_Item> menu;
  int selected = 0;
  for(std::size_t i = 0; i < GModel::list.size(); i++) {
    std::ostringstream sstream;
    sstream << "Model " << i;
    if(GModel::list[i]->getName().size())
      sstream << " - " << GModel::list[i]->getName();
    sstream << " ";
    char *str = strdup(sstream.str().c_str());
    Fl_Menu_Item menuItem = {str, 0, model_switch_cb, (void *)(intptr_t)i,
                             FL_MENU_RADIO};
    if(GModel::list[i] == GModel::current()) {
      selected = i;
      menuItem.flags |= FL_MENU_VALUE;
    }
    menu.push_back(menuItem);
    tofree.push_back(str);
  }
  Fl_Menu_Item it = {nullptr};
  menu.push_back(it);
  Fl_Menu_Item *m = (Fl_Menu_Item *)(&menu[0])->popup(
    Fl::event_x(), Fl::event_y(), nullptr, &menu[selected], gmshPopupStyle());
  if(m) m->do_callback(nullptr);
  for(std::size_t i = 0; i < tofree.size(); i++) free(tofree[i]);
  drawContext::global()->draw();
}

// the window of the current options and the workspace
static void help_current_options_cb(Fl_Widget *w, void *data)
{
  help_options_cb(nullptr, nullptr);
  centerWindow(FlGui::instance()->help->options);
  FlGui::instance()->help->options->show();
}

// the shortcuts of the main menu, whatever window has the focus: as
// Fl_Menu_::global(), but undone when the menu goes (FLTK's cannot be)
static Fl_Menu_ *globalMenu = nullptr;

static int globalMenuHandler(int e)
{
  if(e != FL_SHORTCUT || Fl::modal() || !globalMenu) return 0;
  Fl::first_window(globalMenu->window());
  return globalMenu->handle(e);
}

void quick_access_cb(Fl_Widget *w, void *data)
{
  // the menu (see Actions.cpp), opened on the item picked last
  static Fl_Menu_Button *menu = nullptr;
  static const void *last = nullptr;
  if(!menu) {
    Fl_Group::current(nullptr);
    menu = new Fl_Menu_Button(0, 0, 0, 0);
  }
  menu->clear();
  addMenuItems(menu, GetActionMenu("Quick access"), -1);
  // (the display of the mesh toggled, at first)
  const Fl_Menu_Item *initial = nullptr;
  for(int i = 0; i < menu->size(); i++) {
    const actionItem *item = (const actionItem *)menu->menu()[i].user_data();
    if(item && (last ? item == last : item->name == "mesh_toggle"))
      initial = &menu->menu()[i];
  }
  const Fl_Menu_Item *picked = menu->menu()->popup(
    Fl::event_x(), Fl::event_y(), nullptr, initial, gmshPopupStyle());
  if(picked && picked->callback()) {
    last = picked->user_data();
    // run once the event is over: an item may delete the pane double-clicked
    // (Unsplit), whose handle() is still running
    static Fl_Callback *cb;
    static void *data;
    cb = picked->callback();
    data = picked->user_data();
    Fl::add_timeout(0., [](void *) {
      cb(menu, data);
      drawContext::global()->draw();
    });
  }
  drawContext::global()->draw();
}

void mouse_selection_cb(Fl_Widget *w, void *data)
{
  if(CTX::instance()->mouseSelection) {
    opt_general_mouse_selection(0, GMSH_SET | GMSH_GUI, 0);
    for(openglWindow *gl : FlGui::instance()->openglWindows())
      gl->cursor(FL_CURSOR_DEFAULT, FL_BLACK, FL_WHITE);
  }
  else
    opt_general_mouse_selection(0, GMSH_SET | GMSH_GUI, 1);
}

void status_play_manual(int time, int incr, bool redraw)
{
  // avoid firing this routine recursively (can happen e.g when
  // keeping the finger down on the arrow key: if the system generates
  // too many events, we can overflow the stack--that happened on my
  // powerbook with the new, optimzed FLTK event handler)
  static bool busy = false;
  if(busy) return;
  busy = true;

  // if we watch some files this is a good time to check for new data
  file_watch_cb(nullptr, nullptr);

  PView::animate(time, incr);
  if(redraw) drawContext::global()->draw();
  busy = false;
}

// the animation: a step every PostProcessing.AnimationDelay seconds, from a
// timer, the events being processed by the event loop between the steps;
// playing until paused (a pause handled while a step runs cannot remove the
// timer, which re-arms itself)
static bool animPlaying = false;

static void animate_cb(void *)
{
  if(!FlGui::available() || !animPlaying) return;
  // no step during another operation (the timer runs in its event loops too),
  // e.g. an export of the animation, which steps the views itself, as the
  // animation paused when it ran its own loop
  if(!CTX::instance()->lock && !FlGui::handlingEvent())
    status_play_manual(!CTX::instance()->post.animCycle,
                       CTX::instance()->post.animStep);
  // not again if a pause then a play during the step started another timer
  if(animPlaying && !Fl::has_timeout(animate_cb))
    Fl::repeat_timeout(CTX::instance()->post.animDelay, animate_cb);
}

static void status_play_cb(Fl_Widget *w, void *data)
{
  getGraphicWindow(w)->setAnimButtons(0);
  if(animPlaying) return;
  animPlaying = true;
  Fl::add_timeout(CTX::instance()->post.animDelay, animate_cb);
}

static void status_pause_cb(Fl_Widget *w, void *data)
{
  animPlaying = false;
  Fl::remove_timeout(animate_cb);
  getGraphicWindow(w)->setAnimButtons(1);
}

static void status_rewind_cb(Fl_Widget *w, void *data)
{
  if(!CTX::instance()->post.animCycle) {
    for(std::size_t i = 0; i < PView::list.size(); i++) {
      int step = PView::list[i]->getData()->getFirstNonEmptyTimeStep();
      opt_view_timestep(i, GMSH_SET | GMSH_GUI, step);
    }
  }
  else
    PView::animate(false, 0);
  drawContext::global()->draw();
}

static void status_stepbackward_cb(Fl_Widget *w, void *data)
{
  status_play_manual(!CTX::instance()->post.animCycle,
                     -CTX::instance()->post.animStep);
}

static void status_stepforward_cb(Fl_Widget *w, void *data)
{
  status_play_manual(!CTX::instance()->post.animCycle,
                     CTX::instance()->post.animStep);
}

static void remove_graphic_window_cb(Fl_Widget *w, void *data)
{
  std::vector<graphicWindow *> graph2;
  graphicWindow *deleteMe = nullptr;
  for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++) {
    if(FlGui::instance()->graph[i]->getWindow() == w)
      deleteMe = FlGui::instance()->graph[i];
    else
      graph2.push_back(FlGui::instance()->graph[i]);
  }
  if(deleteMe) {
    openglWindow::setLastHandled(nullptr);
    FlGui::instance()->graph = graph2;
    delete deleteMe;
  }
}

void show_hide_message_cb(Fl_Widget *w, void *data)
{
  graphicWindow *g =
    getGraphicWindow(FlGui::instance()->getCurrentOpenglWindow()->parent());
  g->showHideMessages();
  FlGui::check();
}

void show_hide_menu_cb(Fl_Widget *w, void *data)
{
  graphicWindow *g =
    getGraphicWindow(FlGui::instance()->getCurrentOpenglWindow()->parent());
  g->showHideMenu();
  FlGui::check();
}

void dock_tool_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->toggleCurrentTool();
  FlGui::check();
}

void dock_tools_cb(Fl_Widget *w, void *data)
{
  // docks every tool when any is open on the desktop, undocks every one
  // when all the open ones are docked; with none open, the list is flipped
  bool open = false, floating = false;
  for(paletteWindow *p : FlGui::instance()->toolWindows()) {
    if(!p->isOpen()) continue;
    open = true;
    if(p->floating()) floating = true;
  }
  bool dock = open ? floating : !CTX::instance()->floatingTools.empty();
  FlGui::instance()->dockTools(dock);
  FlGui::check();
}

static void dock_divider_cb(Fl_Widget *w, void *data)
{
  graphicWindow *g = (graphicWindow *)data;
  g->setDockWidth(g->getWindow()->w() - Fl::event_x() - WB / 2);
}

void attach_detach_menu_cb(Fl_Widget *w, void *data)
{
  graphicWindow *g =
    getGraphicWindow(FlGui::instance()->getCurrentOpenglWindow()->parent());
  g->attachDetachMenu();
  FlGui::check();
}

static void message_menu_autoscroll_cb(Fl_Widget *w, void *data)
{
  graphicWindow *g = (graphicWindow *)data;
  g->setAutoScroll(!g->getAutoScroll());
}

static void message_menu_clear_cb(Fl_Widget *w, void *data)
{
  graphicWindow *g = (graphicWindow *)data;
  g->clearMessages();
}

static void message_menu_save_cb(Fl_Widget *w, void *data)
{
  graphicWindow *g = (graphicWindow *)data;
  if(fileChooser(FILE_CHOOSER_CREATE, "Save Messages", ""))
    g->saveMessages(fileChooserGetName(1).c_str());
}

static void message_browser_cb(Fl_Widget *w, void *data)
{
  graphicWindow *g = (graphicWindow *)data;
  g->copySelectedMessagesToClipboard();
}

static void message_menu_search_cb(Fl_Widget *w, void *data)
{
  graphicWindow *g = (graphicWindow *)data;
  g->getMessageBrowser()->rebuild(g->getMessages());
}

static void message_menu_copy_cb(Fl_Widget *w, void *data)
{
  graphicWindow *g = (graphicWindow *)data;
  g->copySelectedMessagesToClipboard();
}

// the tiles of the main window, which also call their callback when pressed,
// as Fl_Tile does only when an edge moves and when it is released
class mainTile : public Fl_Tile {
public:
  mainTile(int x, int y, int w, int h) : Fl_Tile(x, y, w, h) {}
  int handle(int event)
  {
    if(event == FL_PUSH) do_callback(FL_REASON_SELECTED);
    return Fl_Tile::handle(event);
  }
};

static void tile_cb(Fl_Widget *w, void *data)
{
  if(Fl::callback_reason() == FL_REASON_SELECTED) {
    getGraphicWindow(w)->tilePushed();
    return;
  }
  if(Fl::event() == FL_RELEASE) {
    getGraphicWindow(w)->tileReleased();
    // rebuild the tree when we release the mouse after resizing
    FlGui::instance()->rebuildTree();
  }
}

// the least sizes of the menu and the messages in the tiles: their edges
// could not be grabbed again at the border of the tile, where the graphics,
// subwindows, take the events; the menu as wide as its Check, Run and gear
// buttons (see onelabGroup)
static int minMenuWidth() { return 3 * (BB / 2 + 4) + 4 * WB; }
static int minMessageHeight() { return 2 * BH; }

// The menu bar of the window, when it is not the system's: the title under
// the pointer is highlighted, as the bars of the desktops do (FLTK draws the
// titles without a box of their own, so the bar draws them itself, laid out
// as Fl_Menu_Bar lays them out)
class hoverMenuBar : public Fl_Menu_Bar {
  int _hot; // the title under the pointer, or -1
  int _titleAt(int px)
  {
    int X = x() + 6, i = 0;
    for(const Fl_Menu_Item *m = menu()->first(); m->text; m = m->next(), i++) {
      int W = m->measure(0, this) + 16;
      if(px >= X && px < X + W) return i;
      X += W;
    }
    return -1;
  }

public:
  hoverMenuBar(int x, int y, int w, int h) : Fl_Menu_Bar(x, y, w, h), _hot(-1)
  {
  }
  int handle(int event)
  {
    if(menu() && (event == FL_ENTER || event == FL_MOVE || event == FL_LEAVE)) {
      int hot = (event == FL_LEAVE) ? -1 : _titleAt(Fl::event_x());
      if(hot != _hot) {
        _hot = hot;
        redraw();
      }
    }
    // a click opens a menu, which runs in a loop of its own where the bar
    // sees no move: no highlight while it is open, nor after, until the
    // pointer moves over the bar again
    if(event == FL_PUSH && _hot >= 0) {
      _hot = -1;
      redraw();
    }
    int ret = Fl_Menu_Bar::handle(event);
    if(event == FL_PUSH && _hot >= 0) {
      _hot = -1;
      redraw();
    }
    return ret;
  }
  void draw()
  {
    // the open title and the items of its menu in a neutral grey (see
    // gmshMenuHighlight())
    if(gmshScheme()) selection_color(gmshMenuHighlight());
    draw_box();
    if(!menu() || !menu()->text) return;
    int X = x() + 6, i = 0;
    for(const Fl_Menu_Item *m = menu()->first(); m->text; m = m->next(), i++) {
      int tw = m->measure(0, this), W = tw + 16;
      if(i == _hot) {
        // the text, drawn 3 pixels into its slot, with the same margin on
        // both sides
        fl_color(hoverHighlight(color()));
        fl_rectf(X - 2, y() + 1, tw + 10, h() - 2);
      }
      m->draw(X, y(), W, h(), this);
      X += W;
    }
  }
};

// This dummy box class permits to define a box widget that will not eat the
// FL_ENTER/FL_LEAVE events (the box widget in fltk > 1.1 does that, so that
// gl->handle() was not called when the mouse moved)
class dummyBox : public Fl_Box {
private:
  int handle(int) { return 0; } // always!
public:
  dummyBox(int x, int y, int w, int h, const char *l = nullptr)
    : Fl_Box(x, y, w, h, l)
  {
  }
};

// A graphic window other than the main one: closed by the key that closes a
// window, and Escape left to the scene and the global shortcuts, as in the
// main window (a tool window would close on it)
class secondaryGraphicWindow : public gmshWindow {
public:
  secondaryGraphicWindow(int w, int h)
    : gmshWindow(w, h, false, nullptr, nullptr)
  {
  }
  virtual int handle(int event)
  {
    if((event == FL_SHORTCUT || event == FL_KEYBOARD) && _closeKey()) {
      do_callback();
      return 1;
    }
    return Fl_Double_Window::handle(event);
  }
  virtual void show() { _showOnDesktop(); }
};

// The main graphic window has a special resize behaviour forcing the message
// tile to always keep its height
class mainWindowSpecialResize : public mainWindow {
public:
  mainWindowSpecialResize(int w, int h, bool nonModal, const char *l = nullptr)
    : mainWindow(w, h, nonModal, l)
  {
  }
  virtual void resize(int X, int Y, int W, int H)
  {
    bool special = (FlGui::available() && shown() &&
                    this == FlGui::instance()->graph[0]->getWindow());
    int mh = 0;
    if(special) mh = FlGui::instance()->graph[0]->getMessageHeight();
    // not Fl_Window::resize(): Fl_Double_Window::resize() drops the offscreen
    // buffer when the window grows (on Windows the parts out of the old buffer
    // stay black otherwise)
    mainWindow::resize(X, Y, W, H);
    const int minimum_non_message_height = 100;
    if(special && mh < h() - minimum_non_message_height)
      FlGui::instance()->graph[0]->setMessageHeight(mh);
  }
};

// the message of the status bar, a progress bar while something runs; a click
// on it shows or hides the message console, and it is tinted under the
// pointer like the other controls of the bar (the theme does not take a
// progress bar for one)
class mainWindowProgress : public Fl_Progress {
public:
  mainWindowProgress(int x, int y, int w, int h, const char *l = nullptr)
    : Fl_Progress(x, y, w, h, l)
  { tooltip("Show or hide the message console"); }
  void draw()
  {
    Fl_Color c = color();
    color(hoverHighlight(this, c));
    Fl_Progress::draw();
    color(c);
  }
  int handle(int event)
  {
    switch(event) {
    case FL_ENTER:
    case FL_LEAVE: redraw(); return 1;
    case FL_PUSH:
      if(FlGui::available()) {
        for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++)
          FlGui::instance()->graph[i]->showHideMessages();
      }
      return 1;
    }
    return Fl_Progress::handle(event);
  }
};

// The buttons of the status bar, in their order (see statusButtonId): the
// label (text, for a button without icon), its icon (see icons.h), the
// callback and its data, the tooltip and the shortcut action whose keys it shows, the space
// before, and whether the button is wide
struct statusButton {
  const char *label, *icon;
  Fl_Callback *callback;
  const char *data, *tooltip, *shortcut;
  int gap;
  bool wide;
};

static const statusButton *statusButtons()
{
  static const statusButton buttons[StatusButtons] = {
    {nullptr, "sidebar", show_hide_menu_cb, nullptr,
     "Show or hide the menu", "menu_show_hide", 0, false},
    {nullptr, "models", status_model_cb, nullptr,
     "Set current (active) model", nullptr, 0, false},
    {nullptr, "quick", quick_access_cb, nullptr,
     "Open quick access menu (also available by double-clicking in the "
     "graphic window)",
     nullptr, 0, false},
    {"X", nullptr, status_xyz1p_cb, "x", "Set +X or -X (Shift) view", "view_x",
     0, false},
    {"Y", nullptr, status_xyz1p_cb, "y", "Set +Y or -Y (Shift) view", "view_y",
     0, false},
    {"Z", nullptr, status_xyz1p_cb, "z", "Set +Z or -Z (Shift) view", "view_z",
     0, false},
    {nullptr, "cube", status_xyz1p_cb, "3d",
     "Set isometric 3D view, Z up, or from the opposite side (Shift)",
     "view_3d", 0, false},
    {nullptr, "rotate", status_xyz1p_cb, "r",
     "Rotate +90 or -90 (Shift) degrees, or sync rotations (Ctrl)", nullptr, 0,
     false},
    {"1:1", nullptr, status_xyz1p_cb, "1:1",
     "Fit the model in the window, sync scale between viewports (Ctrl), or "
     "reset bounding box around visible entities (Shift)",
     "view_1_1", 0, true},
    {"S", nullptr, mouse_selection_cb, nullptr, "Toggle mouse selection ON/OFF",
     "mouse_selection", 0, false},
    {nullptr, "query", status_query_cb, nullptr,
     "Query the model where you click (Escape to stop)", nullptr, 0, false},
    {nullptr, "measure", status_measure_cb, nullptr,
     "Measure the distance between two points you click (Escape to stop)",
     nullptr, 0, false},
    {nullptr, "rewind", status_rewind_cb, nullptr, "Rewind animation", nullptr,
     4, false},
    {nullptr, "back", status_stepbackward_cb, nullptr, "Step backward",
     "time_step_prev", 0, false},
    {nullptr, "play", status_play_cb, nullptr, "Play/pause animation", nullptr,
     0, false},
    {nullptr, "forward", status_stepforward_cb, nullptr, "Step forward",
     "time_step_next", 0, false},
  };
  return buttons;
}

// the tooltip of a button, with the keys of its shortcut
static std::string statusTooltip(const statusButton &b)
{
  std::string tip = b.tooltip;
  if(!b.shortcut) return tip;
  std::string keys;
  // (without "with any modifier", a detail of how the key is matched)
  for(const Shortcut &s : GetShortcutsOf(b.shortcut))
    keys += (keys.empty() ? "" : ", ") +
            Shortcut(s.key, s.mods & ~AnyModifiers).label();
  return keys.empty() ? tip : tip + " (" + keys + ")";
}

graphicWindow::graphicWindow(bool main, int numTiles, bool detachedMenu)
  : _autoScrollMessages(true), _pushX(0), _pushY(0), _pushMenuWidth(0),
    _pushMessageHeight(0)
{
  int mh = main ? BH : 0; // menu bar height
#if defined(__APPLE__)
  if(CTX::instance()->systemMenuBar) mh = 0;
#endif
  // the status bar and its buttons: as tall as the menu bar, and wide enough
  // for their icons
  int sh = BH;
  int sw = 1.7 * FL_NORMAL_SIZE;
  _iconSize = FL_NORMAL_SIZE + 1; // the icons on the scale of the letters

  // the usable area of the screen that will show the window
  int screenX, screenY, screenW, screenH;
  Fl::screen_work_area(screenX, screenY, screenW, screenH,
                       Fl::screen_num(CTX::instance()->glPosition[0],
                                      CTX::instance()->glPosition[1]));

  int mheight = main ? 2 * BH /* nonzero! */ : 0;
  int glheight = CTX::instance()->glSize[1] - mheight;
  // make sure glheight is positive
  if(glheight <= 0) {
    CTX::instance()->glSize[1] = 600;
    glheight = CTX::instance()->glSize[1] - mheight;
  }
  int height = mh + glheight + mheight + sh;
  // make sure height < screen height
  if(height > screenH) {
    height = screenH;
    glheight = height - mh - mheight - sh;
    CTX::instance()->glSize[1] = glheight + mheight;
  }

  int twidth = (main && !detachedMenu) ? 14 * (FL_NORMAL_SIZE + 2) : 0;
  int glwidth = CTX::instance()->glSize[0] - twidth;
  // make sure glwidth is positive
  if(glwidth <= 0) {
    CTX::instance()->glSize[0] = 600;
    glwidth = CTX::instance()->glSize[0] - twidth;
  }
  int width = glwidth + twidth;
  // make sure width < screen width
  if(width > screenW) {
    width = screenW;
    glwidth = width - twidth;
    CTX::instance()->glSize[0] = glwidth + twidth;
  }

  // the graphic window should be a "normal" window (neither modal nor
  // non-modal)
  if(main) {
    _win = new mainWindowSpecialResize(width, height, false);
    _win->callback(file_quit_cb);
  }
  else {
    _win = new secondaryGraphicWindow(width, height);
    _win->callback(remove_graphic_window_cb);
  }

#if defined(__APPLE__)
  _sysbar = nullptr;
#endif
  _bar = nullptr;
  if(main) {
#if defined(__APPLE__)
    if(CTX::instance()->systemMenuBar)
      _sysbar = new Fl_Sys_Menu_Bar(1, 1, 1, 1);
    else
#endif
      _bar = new hoverMenuBar(0, 0, width, BH);
    Fl_Menu_ *m = _menuBar();
    addMenuItems(m, GetActionMenu("Menu bar"), -1, false);
#if defined(__APPLE__)
    if(_sysbar) {
      // Quit and About are in the application menu, and Cmd+H hides the
      // application: the keyboard help has another shortcut
      for(const char *path : {"File/Quit", "Help/About Gmsh"}) {
        int i = m->find_index(path);
        if(i < 1) continue;
        m->remove(i);
        // (the last of its menu: no divider above it then)
        m->mode(i - 1, m->mode(i - 1) & ~FL_MENU_DIVIDER);
      }
      int i = m->find_index("Help/Keyboard and Mouse Usage");
      if(i >= 0) m->shortcut(i, fltkShortcut("help_keys", true));
    }
#endif
    Fl::remove_handler(globalMenuHandler);
    Fl::add_handler(globalMenuHandler);
    globalMenu = m;
    fillRecentHistoryMenu();
  }

  // a dummy resizable box that won't eat events, created before the tile so
  // that FLTK does not find it first when it looks for the widget under the
  // mouse (which would turn every move over the graphic windows into a leave
  // and an enter, and no move at all); its place is set below, once the
  // status bar says where the resizing part of the window starts
  dummyBox *resbox = new dummyBox(0, mh, width, glheight);
  _win->resizable(resbox);
  _resbox = resbox;

  // tiled windows (tree menu, opengl, messages)
  _tile = new mainTile(0, mh, glwidth + twidth, glheight + mheight);

  int w2 = glwidth / 2, h2 = glheight / 2;
  if(numTiles == 2) {
    gl.push_back(new openglWindow(twidth, mh, w2, glheight));
    gl.back()->end();
    gl.push_back(new openglWindow(twidth + w2, mh, glwidth - w2, glheight));
    gl.back()->end();
  }
  else if(numTiles == 3) {
    gl.push_back(new openglWindow(twidth, mh, w2, glheight));
    gl.back()->end();
    gl.push_back(new openglWindow(twidth + w2, mh, glwidth - w2, h2));
    gl.back()->end();
    gl.push_back(
      new openglWindow(twidth + w2, mh + h2, glwidth - w2, glheight - h2));
    gl.back()->end();
  }
  else if(numTiles == 4) {
    gl.push_back(new openglWindow(twidth, mh, w2, h2));
    gl.back()->end();
    gl.push_back(new openglWindow(twidth + w2, mh, glwidth - w2, h2));
    gl.back()->end();
    gl.push_back(new openglWindow(twidth, mh + h2, w2, glheight - h2));
    gl.back()->end();
    gl.push_back(
      new openglWindow(twidth + w2, mh + h2, glwidth - w2, glheight - h2));
    gl.back()->end();
  }
  else {
    gl.push_back(new openglWindow(twidth, mh, glwidth, glheight));
    gl.back()->end();
  }

  int mode = openglWindowMode();
  for(std::size_t i = 0; i < gl.size(); i++) gl[i]->mode(mode);

  if(main) {
    _browser = new messageBrowser(twidth, mh + glheight, glwidth, mheight);
    int s = CTX::instance()->msgFontSize;
    _browser->textsize(s <= 0 ? FL_NORMAL_SIZE - 2 : s);
    _browser->callback(message_browser_cb, this);
    _browser->search_callback(message_menu_search_cb, this);
    _browser->autoscroll_callback(message_menu_autoscroll_cb, this);
    _browser->copy_callback(message_menu_copy_cb, this);
    _browser->save_callback(message_menu_save_cb, this);
    _browser->clear_callback(message_menu_clear_cb, this);
  }
  else {
    _browser = nullptr;
  }

  if(main && !detachedMenu) {
    _onelab = new onelabGroup(0, mh, twidth, height - mh - sh);
  }
  else {
    _onelab = nullptr;
  }

  // the edges are dragged within the resizable box: the tree and the messages
  // keep their least size, and are hidden when released well past it (see
  // tileReleased())
  {
    int minw = _onelab ? minMenuWidth() : 0;
    int minh = _browser ? minMessageHeight() : 0;
    dummyBox *drag =
      new dummyBox(minw, mh, _tile->w() - minw, _tile->h() - minh);
    _tile->insert(*drag, 0);
    _tile->resizable(drag);
  }
  _tile->callback(tile_cb);
  _tile->end();

  // the dock of the tool windows, shown while one is docked
  _dropping = nullptr;
  if(main) {
    _divider = new dockDivider(0, mh, 0, glheight + mheight);
    _divider->callback(dock_divider_cb, this);
    _divider->hide();
    _dock = new toolDock(0, mh, 0, glheight + mheight, BH);
    _dock->hide();
  }
  else {
    _divider = nullptr;
    _dock = nullptr;
  }

  // resize the tiles to match the prescribed sizes
  _tile->position(0, mh + glheight, 0, mh + CTX::instance()->glSize[1]);

  // the menu at least at its least width; a width of 0 means that the menu is
  // hidden: built at its least width, hidden at the end
  int minw = minMenuWidth();
  int mw = CTX::instance()->menuSize[0];
  bool hiddenMenu = (mw <= 0);
  if(mw < minw) mw = minw;
  if(!hiddenMenu) CTX::instance()->menuSize[0] = mw;
  _menuWidth = mw;
  _tile->position(twidth, 0, mw, 0);

  // bottom button bar
  _bottom = new Fl_Box(0, mh + glheight + mheight, width, sh);
  _bottom->box(GMSH_SIMPLE_TOP_BOX);

  int x = 2;
  int sht = sh - 4; // leave a 2 pixel border at the bottom
  for(int i = 0; i < StatusButtons; i++) {
    const statusButton &b = statusButtons()[i];
    x += b.gap;
    int bw = b.wide ? 2 * FL_NORMAL_SIZE : sw;
    _butt[i] = new Fl_Button(x, mh + glheight + mheight + 2, bw, sht, b.label);
    _butt[i]->callback(b.callback, (void *)b.data);
    _butt[i]->copy_tooltip(statusTooltip(b).c_str());
    _butt[i]->box(FL_FLAT_BOX);
    _butt[i]->selection_color(FL_BACKGROUND2_COLOR);
    _butt[i]->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
    if(b.icon) gmshIcon(_butt[i], b.icon, _iconSize);
    // (the animation buttons wait for views with time steps)
    if(i >= StatusRewind) _butt[i]->deactivate();
    x += b.wide ? (int)(1.75 * FL_NORMAL_SIZE) : sw;
  }
  x += 4;

  // the least width of the window is what the status bar buttons take, and
  // the part of the window that resizes starts after them, so that they stay
  // in place
  _minWidth = x;
  _minHeight = 100;
  _win->size_range(_minWidth, _minHeight);
  resbox->resize(_minWidth, mh, std::max(1, width - _minWidth), glheight);

  _label =
    new mainWindowProgress(x, mh + glheight + mheight + 2, width - x - 2, sht);
  _label->box(FL_FLAT_BOX);
  _label->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
  if(CTX::instance()->guiDark)
    _label->color(FL_BACKGROUND_COLOR, FL_LIGHT3);
  else
    _label->color(FL_BACKGROUND_COLOR, FL_DARK2);
  // a saved width below the least one
  if(_win->w() < _minWidth) _win->size(_minWidth, _win->h());

  if(main) {
    // the other windows are placed relative to the main graphic window
    setReferenceWindow(_win);
    placeWindowAt(_win, CTX::instance()->glPosition[0],
                  CTX::instance()->glPosition[1]);
  }
  else {
    _win->position(CTX::instance()->glPosition[0],
                   CTX::instance()->glPosition[1]);
  }
  _win->end();

  if(main && detachedMenu) {
    _menuwin = new mainWindow(std::max(CTX::instance()->menuSize[0], minw),
                              CTX::instance()->menuSize[1],
                              CTX::instance()->nonModalWindows ? true : false,
                              "Gmsh", CTX::instance()->menuOffset);
    _menuwin->callback(file_quit_cb);
    _menuwin->box(GMSH_WINDOW_BOX);
    _onelab = new onelabGroup(0, 0, _menuwin->w(), _menuwin->h());
    _menuwin->resizable(_onelab);
    _menuwin->size_range(_onelab->getMinWindowWidth(),
                         _onelab->getMinWindowHeight());
    _menuwin->end();
  }
  else {
    _menuwin = nullptr;
  }

  if(main) setDocking(true);
  if(main && hiddenMenu) {
    hideMenu();
    _menuWidth = 0; // shown again at its default width (see showMenu())
  }
}

// a tool dropped on the dock, docked at the next event (see toolDock.cpp)
void dropped_cb(void *data);

graphicWindow::~graphicWindow()
{
  // the main window: a tool dropped on its dock, docked at the next event,
  // and the animation go with it, and the docked tool windows are not its to
  // delete
  if(_dock) {
    Fl::remove_timeout(dropped_cb);
    animPlaying = false;
    Fl::remove_timeout(animate_cb);
    Fl::remove_timeout(_drop_cb, this);
    _dock->undockAll(false);
    setDocking(false);
  }
  // (as on unsplit, see split())
  for(openglWindow *w : gl)
    if(sceneTool::scene() == w) sceneTool::stop();
  openglWindow::setLastHandled(nullptr);
  if(globalMenu && globalMenu == _menuBar()) {
    Fl::remove_handler(globalMenuHandler);
    globalMenu = nullptr;
  }
  _tile->clear();
  _win->clear();
  Fl::delete_widget(_win);
  if(_menuwin) {
    _menuwin->clear();
    Fl::delete_widget(_menuwin);
  }
}

void graphicWindow::setTitle(const std::string &str)
{
  _win->copy_label(str.c_str());
}

void graphicWindow::detachMenu()
{
  if(_menuwin || !_onelab || !_browser) return;
  if(_browser->h() == 0) setMessageHeight(1);
  int w = _onelab->w();
  _tile->remove(_onelab);
  _browser->resize(0, _browser->y(), _browser->w() + w, _browser->h());
  for(std::size_t i = 0; i < gl.size(); i++) {
    if(gl[i]->x() == w) {
      gl[i]->resize(0, gl[i]->y(), gl[i]->w() + w, gl[i]->h());
    }
  }
  _tile->redraw();

  _menuwin =
    new mainWindow(std::max(_onelab->w(), _onelab->getMinWindowWidth()),
                   CTX::instance()->menuSize[1],
                   CTX::instance()->nonModalWindows ? true : false, "Gmsh",
                   CTX::instance()->menuOffset);
  _menuwin->callback(file_quit_cb);
  _menuwin->box(GMSH_WINDOW_BOX);
  _onelab->box(FL_FLAT_BOX);
  _menuwin->add(_onelab);
  _onelab->resize(0, 0, _menuwin->w(), _menuwin->h());
  _menuwin->resizable(_onelab);
  _menuwin->size_range(_onelab->getMinWindowWidth(),
                       _onelab->getMinWindowHeight());
  _menuwin->end();
  _menuwin->show();

  _onelab->rebuildTree();
}

void graphicWindow::attachMenu()
{
  if(!_menuwin || !_onelab || !_browser) return;
  CTX::instance()->menuSize[1] = _menuwin->h();
  storeWindowOffset(_menuwin, CTX::instance()->menuOffset);
  _menuwin->remove(_onelab);
  _menuwin->hide();
  delete _menuwin;
  _menuwin = nullptr;
  if(_browser->h() == 0) setMessageHeight(1);
  int w = _onelab->w();
  if(_browser->w() - w < 0) w = _browser->w() / 2;
  _browser->resize(w, _browser->y(), _browser->w() - w, _browser->h());
  for(std::size_t i = 0; i < gl.size(); i++) {
    if(gl[i]->x() == 0) {
      gl[i]->resize(w, gl[i]->y(), gl[i]->w() - w, gl[i]->h());
    }
  }
  _onelab->box(GMSH_SIMPLE_RIGHT_BOX);
  _tile->add(_onelab);
  _onelab->resize(_tile->x(), _tile->y(), w, _tile->h());
  _tile->redraw();

  _onelab->rebuildTree();
}

void graphicWindow::attachDetachMenu()
{
  if(_menuwin)
    attachMenu();
  else
    detachMenu();
}

void graphicWindow::showMenu()
{
  if(_menuwin || !_onelab || !_win->shown()) return;
  if(_onelab->w() < FL_NORMAL_SIZE) {
    // the width set, or the one the menu had when it was hidden
    int width = CTX::instance()->menuSize[0];
    if(width < FL_NORMAL_SIZE) width = _menuWidth;
    if(width < FL_NORMAL_SIZE) width = _onelab->getMinWindowWidth();
    int maxw = _tile->w(); // without the dock
    if(width > maxw) width = maxw / 2;
    setMenuWidth(width);
    CTX::instance()->menuSize[0] = width;
    // necessary until resizing of 0-sized groups works
    _onelab->rebuildTree();
  }
}

void graphicWindow::hideMenu()
{
  if(_menuwin || !_onelab) return;
  // hidden, the menu has no width (saved as such); the width it had is kept
  // to show it again
  if(_onelab->w() > 0) _menuWidth = _onelab->w();
  CTX::instance()->menuSize[0] = 0;
  setMenuWidth(0);
}

void graphicWindow::tilePushed()
{
  _pushX = Fl::event_x();
  _pushY = Fl::event_y();
  _pushMenuWidth = getMenuWidth();
  _pushMessageHeight = getMessageHeight();
}

// an edge of the tiles released: a menu or messages dragged well past their
// least size, towards the border of the tile, are hidden as their toggles
// hide them, and the toggles show them again at the size they had before the
// drag
void graphicWindow::tileReleased()
{
  int mx = Fl::event_x(), my = Fl::event_y();
  const int grab = 5; // the grab area of Fl_Tile, and a pixel
  int minw = minMenuWidth(), minh = minMessageHeight();
  // a menu or messages shown when pressed (else Fl_Tile may take a press at
  // the border for their edge)
  if(_onelab && !_menuwin && _pushMenuWidth >= FL_NORMAL_SIZE &&
     _onelab->w() <= minw &&
     std::abs(_pushX - (_onelab->x() + _pushMenuWidth)) <= grab &&
     mx < _onelab->x() + minw / 2) {
    hideMenu();
    _menuWidth = (_pushMenuWidth > minw) ? _pushMenuWidth : 0;
  }
  if(_browser && _pushMessageHeight >= FL_NORMAL_SIZE &&
     _browser->h() <= minh) {
    int bottom = _browser->y() + _browser->h();
    if(std::abs(_pushY - (bottom - _pushMessageHeight)) <= grab &&
       my > bottom - minh / 2) {
      hideMessages();
      CTX::instance()->msgSize =
        (_pushMessageHeight > minh) ? _pushMessageHeight : 0;
    }
  }
}

void graphicWindow::showHideMenu()
{
  if(_menuwin || !_onelab) return;
  if(_onelab->w() < FL_NORMAL_SIZE)
    showMenu();
  else
    hideMenu();
}

int graphicWindow::getMenuWidth()
{
  if(!_onelab) return 0;
  return _onelab->w();
}

int graphicWindow::getMenuHeight()
{
  if(!_menuwin) return 0;
  return _menuwin->h();
}

bool graphicWindow::split(openglWindow *g, char how, double ratio)
{
  if(_tile->find(g) == _tile->children()) return false; // not found

  if(how == 'u') {
    // after many tries I cannot figure out how to do this cleanly, so let's be
    // brutal :-)
    int mode = g->mode();
    // the tool on one of the panes ends while they are all there (its end
    // may draw them, or say so in the current one)
    for(openglWindow *w : gl)
      if(sceneTool::scene() == w) sceneTool::stop();
    openglWindow::setLastHandled(nullptr);
    // hidden first, all of them whole: hiding moves the focus, which may
    // commit an edited value whose callback draws every pane
    for(std::size_t i = 0; i < gl.size(); i++) gl[i]->hide();
    for(std::size_t i = 0; i < gl.size(); i++) {
      _tile->remove(gl[i]);
      delete gl[i];
    }
    gl.clear();
    openglWindow *g2 = new openglWindow(
      _tile->x() + (_onelab && !_menuwin ? _onelab->w() : 0), _tile->y(),
      _tile->w() - (_onelab && !_menuwin ? _onelab->w() : 0),
      _tile->h() - (_browser ? _browser->h() : 0));
    g2->end();
    g2->mode(mode);
    gl.push_back(g2);
    _tile->add(g2);
    g2->show();
    openglWindow::setLastHandled(g2);
  }
  else {
    double fact = (ratio <= 0.) ? 0.01 : (ratio >= 1.) ? 0.99 : ratio;
    // make sure browser is not zero-size when adding children
    if(_browser && _browser->h() == 0) setMessageHeight(1);
    int x1 = g->x();
    int y1 = g->y();
    int w1 = (how == 'h') ? (int)(g->w() * fact) : g->w();
    int h1 = (how == 'h') ? g->h() : (int)(g->h() * fact);

    int x2 = (how == 'h') ? (g->x() + w1) : g->x();
    int y2 = (how == 'h') ? g->y() : (g->y() + h1);
    int w2 = (how == 'h') ? (g->w() - w1) : g->w();
    int h2 = (how == 'h') ? g->h() : (g->h() - h1);

    g->resize(x1, y1, w1, h1);
    openglWindow *g2 = new openglWindow(x2, y2, w2, h2);
    g2->end();
    g2->mode(g->mode());
    gl.push_back(g2);
    _tile->add(g2);
    g2->show();
    openglWindow::setLastHandled(g2);
  }
  return true;
}

void graphicWindow::setAnimButtons(int mode)
{
  Fl_Button *b = _butt[StatusPlay];
  if(mode) {
    b->callback(status_play_cb);
    gmshIcon(b, "play", _iconSize);
  }
  else {
    b->callback(status_pause_cb);
    gmshIcon(b, "pause", _iconSize);
  }
}

void graphicWindow::checkAnimButtons()
{
  bool play = false;
  if(CTX::instance()->post.animCycle) { play = true; }
  else {
    for(std::size_t i = 0; i < PView::list.size(); i++) {
      if(PView::list[i]->getData()->getNumTimeSteps() > 1) {
        play = true;
        break;
      }
    }
  }
  for(int i = StatusRewind; i <= StatusForward; i++) {
    if(play)
      _butt[i]->activate();
    else
      _butt[i]->deactivate();
  }
}

void graphicWindow::setMenuWidth(int w)
{
  if(!_onelab) return;
  if(_menuwin) {
    _menuwin->size(std::max(w, _onelab->getMinWindowWidth()), _menuwin->h());
    _menuwin->redraw();
    return;
  }
  if(!_browser) return;
  double dw = w - _onelab->w();
  if(!dw) return;
  for(std::size_t i = 0; i < gl.size(); i++) {
    if(gl[i]->x() == _onelab->x() + _onelab->w()) {
      gl[i]->resize(gl[i]->x() + dw, gl[i]->y(), gl[i]->w() - dw, gl[i]->h());
    }
  }
  _browser->resize(_browser->x() + dw, _browser->y(), _browser->w() - dw,
                   _browser->h());
  _onelab->resize(_onelab->x(), _onelab->y(), _onelab->w() + dw, _onelab->h());
  _tile->redraw();
}

int graphicWindow::getGlHeight()
{
  int h = _win->h() - _bottom->h(); // yes, ignore message browser
  if(_bar) h -= _bar->h();
  return h;
}

// the width of the window, the dock taking its room from the graphics, as the
// tree does, so that the size saved at exit does not depend on the tools open
int graphicWindow::getGlWidth() { return _win->w(); }

void graphicWindow::setGlWidth(int w)
{
  if(w == _win->w()) return;
  _win->size(std::max(w, _minWidth), _win->h());
  _win->redraw();
}

void graphicWindow::setGlHeight(int h)
{
  int hh = h + _bottom->h();
  if(_bar) hh += _bar->h();
  if(hh == _win->h()) return;
  _win->size(_win->w(), std::max(hh, _minHeight));
  _win->redraw();
}

void graphicWindow::setMessageHeight(int h)
{
  if(!_browser) return;
  int dh = h - _browser->h();
  if(!dh) return;
  for(std::size_t i = 0; i < gl.size(); i++) {
    if(gl[i]->y() + gl[i]->h() == _browser->y()) {
      gl[i]->resize(gl[i]->x(), gl[i]->y(), gl[i]->w(), gl[i]->h() - dh);
    }
  }
  _browser->resize(_browser->x(), _browser->y() - dh, _browser->w(),
                   _browser->h() + dh);
  _tile->redraw();
}

void graphicWindow::showMessages()
{
  if(!_browser || !_win->shown()) return;
  Msg::ResetErrorCounter();
  if(_browser->h() < FL_NORMAL_SIZE) {
    int height = CTX::instance()->msgSize;
    if(height < FL_NORMAL_SIZE) height = 10 * FL_NORMAL_SIZE;
    int maxh = _win->h() - _bottom->h();
    if(height > maxh) height = maxh / 2;
    setMessageHeight(height);
  }
  if(_autoScrollMessages) _browser->scrollToEnd();
}

void graphicWindow::hideMessages()
{
  if(!_browser) return;
  CTX::instance()->msgSize = _browser->h();
  setMessageHeight(0);
}

void graphicWindow::showHideMessages()
{
  if(!_browser) return;
  if(_browser->h() < FL_NORMAL_SIZE)
    showMessages();
  else
    hideMessages();
}

int graphicWindow::getMessageHeight()
{
  if(!_browser) return 0;
  return _browser->h();
}

// on the GUI's thread only: the other threads' lines are queued for it by
// FlGui::addMessage()
void graphicWindow::addMessage(const char *msg)
{
  if(!_browser) return;
  // the console keeps the last 50000 messages: beyond, the oldest tenth goes
  const std::size_t maxMessages = 50000;
  if(_messages.size() >= maxMessages) {
    _messages.erase(_messages.begin(), _messages.begin() + maxMessages / 10);
    _browser->removeFirst(maxMessages / 10);
  }
  _messages.push_back(msg);
  _browser->add(msg);
  if(_autoScrollMessages && _win->shown() && _browser->h() >= FL_NORMAL_SIZE)
    _browser->scrollToEnd();
}

void graphicWindow::clearMessages()
{
  _messages.clear();
  if(!_browser) return;
  _browser->clear();
}

// a line of the console without its colour: the codes FLTK reads at its start,
// up to "@." (e.g. "@C1@." or, in dark mode, "@B152@.")
static const char *withoutFormat(const char *c)
{
  if(c[0] != '@') return c;
  const char *end = strstr(c, "@.");
  return end ? end + 2 : c;
}

void graphicWindow::saveMessages(const char *filename)
{
  if(!_browser) return;

  FILE *fp = Fopen(filename, "w");

  if(!fp) {
    Msg::Error("Unable to open file '%s'", filename);
    return;
  }

  Msg::StatusBar(true, "Writing '%s'...", filename);
  for(int i = 1; i <= _browser->size(); i++) {
    fprintf(fp, "%s\n", withoutFormat(_browser->text(i)));
  }
  Msg::StatusBar(true, "Done writing '%s'", filename);
  fclose(fp);
}

void graphicWindow::copySelectedMessagesToClipboard()
{
  if(!_browser) return;

  // the lines selected, or all of them
  bool any = false;
  for(int i = 1; i <= _browser->size(); i++)
    if(_browser->selected(i)) any = true;
  std::string buff;
  for(int i = 1; i <= _browser->size(); i++) {
    if(!any || _browser->selected(i)) {
      buff += std::string(withoutFormat(_browser->text(i))) + "\n";
    }
  }
  // bof bof bof
  Fl::copy(buff.c_str(), buff.size(), 0);
  Fl::copy(buff.c_str(), buff.size(), 1);
}

void graphicWindow::setMessageFontSize(int size)
{
  if(!_browser) return;
  _browser->textsize(size <= 0 ? FL_NORMAL_SIZE - 2 : size);
  _browser->redraw();
}

void graphicWindow::fillRecentHistoryMenu()
{
  Fl_Menu_ *m = _menuBar();
  if(!m) return;
  int i = m->find_index("File/Open Recent");
  if(i >= 0) {
    m->clear_submenu(i);
    addRecentFiles(m, "File/Open Recent");
  }
#if defined(__APPLE__)
  // the system menu bar is made from the items only when asked: its add(),
  // mode()... are not virtual, and those of Fl_Menu_ are the ones called here
  // and when the menu is built
  if(_sysbar) _sysbar->update();
#endif
}
