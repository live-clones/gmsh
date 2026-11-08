// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include "GmshDefines.h"
#include "GmshVersion.h"
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <functional>
#include <map>
#include <FL/Fl_Box.H>
#include <FL/fl_ask.H>
#include <FL/filename.H>
#include <FL/Fl_Tree.H>
#include <FL/Fl_Menu_Button.H>
#include "FlGui.h"
#include "Shortcuts.h"
#include "mainWindow.h"
#include "paletteWindow.h"
#include "graphicWindow.h"
#include "toolDock.h"
#include "gmshScheme.h"
#include "icons.h"
#include "optionWindow.h"
#include "gamepadWindow.h"
#include "statisticsWindow.h"
#include "contextWindow.h"
#include "visibilityWindow.h"
#include "highOrderToolsWindow.h"
#include "clippingWindow.h"
#include "manipWindow.h"
#include "fieldWindow.h"
#include "pluginWindow.h"
#include "helpWindow.h"
#include "windowPlacement.h"
#include "openglWindow.h"
#include "viewButton.h"
#include "editorWindow.h"
#include "onelabContextWindow.h"
#include "onelabGroup.h"
#include "messageBrowser.h"
#include "gmshLocalNetworkClient.h"
#include "fileDialogs.h"
#include "extraDialogs.h"
#include "partitionDialog.h"
#include "classificationEditor.h"
#include "GModel.h"
#include "PView.h"
#include "PViewData.h"
#include "PViewOptions.h"
#include "OpenFile.h"
#include "CreateFile.h"
#include "scriptStringInterface.h"
#include "CommandLine.h"
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

static void file_open_recent_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  if(modelBusy()) return;
  std::string str((const char *)data);
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
  if(FlGui::instance()->onelab->isBusy()) {
    Msg::Info("I'm busy! Ask me that later...");
    return;
  }
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

static void file_window_cb(Fl_Widget *w, void *data)
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

static void geometry_edit_cb(Fl_Widget *w, void *data)
{ editFile(GModel::current()->getFileName()); }

void onelab_reload_cb(Fl_Widget *w, void *data)
{
  if(modelBusy()) return;
  if(FlGui::instance()->onelab->isBusy()) {
    Msg::Info("I'm busy! Ask me that later...");
    return;
  }

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

// The value of a field of the operations on selected entities (see
// selectionDriver), by its name, from the context windows
static std::string dialogValue(const std::string &operation,
                               const std::string &name)
{
  FlGui *g = FlGui::instance();
  if(name == "Name") return g->physicalContext->selectedName;
  if(name == "Tag") return std::to_string(g->physicalContext->selectedTag);
  Fl_Widget *w =
    g->transformContext->field(name, operation == "Extrude rotate");
  return fieldValue(w ? w : g->meshContext->field(name));
}

// After a physical group is added or removed: the clients are told, and the
// ONELAB parameters of the group are shown if it has any, which stops the
// selection (so that outside codes can process events through the API); or
// the dialog is shown again, with the new group. False if the selection stops
static bool physicalGroupChanged(const selectionDriver &d)
{
  const std::string &op = d.operation();
  std::string what = op.substr(op.rfind(' ') + 1);
  bool remove = (op[0] == 'R');
  onelab_cb(nullptr, (void *)"check");
  if(!FlGui::available()) return false;
  std::vector<std::string> param;
  onelab::server::instance()->getParameterNames(
    param, "ONELAB Context/" + what + " Template");
  const std::vector<std::pair<int, int> > &picked = d.done()[0];
  if(picked.size() && param.size() && !remove) {
    FlGui::instance()->getCurrentOpenglWindow()->quitSelection = 1;
    GModel::current()->setSelection(0);
    FlGui::instance()->onelabContext->show(picked[0].first, picked[0].second);
    return false;
  }
  FlGui::instance()->physicalContext->show(what, remove);
  return true;
}

// An operation on selected entities (see selectionDriver): the clicks and the
// keys are waited for until it is over
static void runSelection(const std::string &operation)
{
  selectionDriver d(operation, [operation](const std::string &name) {
    return dialogValue(operation, name);
  });
  while(d.active()) {
    if(!FlGui::available()) return;
    Msg::StatusGl("%s", d.status().c_str());
    char ib = FlGui::instance()->selectEntity(d.type());
    if(!FlGui::available()) return;
    FlGui *g = FlGui::instance();
    if(d.step(ib, g->selectedVertices, g->selectedEdges, g->selectedFaces,
              g->selectedRegions, g->selectedElements)) {
      g->resetVisibility();
      if(operation.find("Physical ") != std::string::npos &&
         !physicalGroupChanged(d))
        break;
    }
    drawContext::global()->draw();
  }
  if(FlGui::available()) Msg::StatusGl("");
}

static void add_new_point_based_entity(const std::string &what, int pane)
{
  opt_general_axes(0, GMSH_SET | GMSH_GUI, 3);
  opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  drawContext::global()->draw();

  FlGui::instance()->elementaryContext->show(pane);

  while(1) {
    if(!FlGui::available()) return;

    for(openglWindow *gl : FlGui::instance()->openglWindows())
      gl->addPointMode = 1;
    std::string name = what;
    std::transform(name.begin(), name.end(), name.begin(), ::tolower);
    Msg::StatusGl(
      "Move mouse and/or enter coordinates\n"
      "[Press 'Shift' to hold position, 'e' to add %s or 'q' to abort]",
      name.c_str());
    char ib = FlGui::instance()->selectEntity(ENT_NONE);
    if(!FlGui::available()) return;
    if(ib == 'e') {
      FlGui::instance()->elementaryContext->addShape(pane);
      FlGui::instance()->resetVisibility();
      drawContext::global()->draw();
    }
    if(ib == 'q') {
      for(openglWindow *gl : FlGui::instance()->openglWindows())
        gl->addPointMode = 0;
      break;
    }
  }

  drawContext::setDrawGeomTransientFunction(nullptr);
  if(!FlGui::available()) return;
  FlGui::instance()->elementaryContext->hide();

  // at the end, not during creation to avoid having things jumping around
  SetBoundingBox();
  Msg::StatusGl("");
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

// after an operation on the mesh, which processes events: the GUI may have
// been closed meanwhile
static void afterMeshOperation()
{
  if(!FlGui::available()) return;
  // (before the drawing, which processes events)
  FlGui::instance()->updateStatistics();
  drawContext::global()->draw();
}

// clang-format off

// The static menus (we cannot use the 'g', 'm' 's' and 'p' mnemonics since they
// are already defined as global shortcuts)
// no label carries a mnemonic (an "&" letter): the titles of the menus would
// take Alt+f, t, w and h from the shortcuts of the table (see Shortcuts.h)
// before they are seen, and the macOS system menu bar wants none
static Fl_Menu_Item bar_table[] = {
  {"File", 0, nullptr, nullptr, FL_SUBMENU},
    {"New...",     fltkShortcut("file_new"), (Fl_Callback *)file_new_cb, nullptr},
    {"Open...",    fltkShortcut("file_open"), (Fl_Callback *)file_open_merge_cb, (void*)"open"},
    {"Open Recent", 0, nullptr, nullptr, FL_SUBMENU},
      {"", 0, (Fl_Callback *)file_open_recent_cb, nullptr},
      {"", fltkShortcut("file_recent"), (Fl_Callback *)file_open_recent_cb, nullptr},
      {"", 0, (Fl_Callback *)file_open_recent_cb, nullptr},
      {"", 0, (Fl_Callback *)file_open_recent_cb, nullptr},
      {"", 0, (Fl_Callback *)file_open_recent_cb, nullptr},
      {"", 0, (Fl_Callback *)file_open_recent_cb, nullptr},
      {"", 0, (Fl_Callback *)file_open_recent_cb, nullptr},
      {"", 0, (Fl_Callback *)file_open_recent_cb, nullptr},
      {"", 0, (Fl_Callback *)file_open_recent_cb, nullptr},
      {"", 0, (Fl_Callback *)file_open_recent_cb, nullptr},
      {nullptr},
    {"Merge...",   fltkShortcut("file_merge"), (Fl_Callback *)file_open_merge_cb, (void*)"merge"},
    {"Watch Pattern...",    0, (Fl_Callback *)file_watch_cb, nullptr, FL_MENU_DIVIDER},
    {"Clear",      0, (Fl_Callback *)file_clear_cb, nullptr},
    {"Rename...",  fltkShortcut("file_rename"), (Fl_Callback *)file_rename_cb, nullptr},
    {"Delete",      0, (Fl_Callback *)file_delete_cb, nullptr, FL_MENU_DIVIDER},
    {"Remote", 0, nullptr, nullptr, FL_MENU_DIVIDER | FL_SUBMENU},
      {"Start...",  0, (Fl_Callback *)file_remote_cb, (void*)"start"},
      {"Merge...",  0, (Fl_Callback *)file_remote_cb, (void*)"merge"},
      {"Clear",     0, (Fl_Callback *)file_remote_cb, (void*)"clear"},
      {"Stop",      0, (Fl_Callback *)file_remote_cb, (void*)"stop"},
      {nullptr},
    {"Save Mesh",  fltkShortcut("mesh_save"), (Fl_Callback *)mesh_save_cb, nullptr},
    {"Save Model Options", fltkShortcut("options_save"), (Fl_Callback *)file_options_save_cb, (void*)"file"},
    {"Save Options As Default", fltkShortcut("options_save_default"), (Fl_Callback *)file_options_save_cb, (void*)"default", FL_MENU_DIVIDER},
    {"Export...",  fltkShortcut("file_export"), (Fl_Callback *)file_export_cb, nullptr, FL_MENU_DIVIDER},
    {"Quit",       fltkShortcut("quit"), (Fl_Callback *)file_quit_cb, nullptr},
    {nullptr},
  {"Tools", 0, nullptr, nullptr, FL_SUBMENU},
    {"Options",         fltkShortcut("options"), (Fl_Callback *)options_cb, nullptr},
    {"Plugins",         fltkShortcut("plugins"), (Fl_Callback *)plugin_cb, (void*)(-1)},
    {"Visibility",      fltkShortcut("visibility"), (Fl_Callback *)visibility_cb, nullptr},
    {"Clipping",        fltkShortcut("clipping"), (Fl_Callback *)clip_cb, nullptr},
    {"Manipulator",     fltkShortcut("manipulator"), (Fl_Callback *)manip_cb, nullptr, FL_MENU_DIVIDER},
#if defined(HAVE_3M)
    {"3M",              0, (Fl_Callback *)window3M_cb, 0, FL_MENU_DIVIDER},
#endif
    {"Statistics",      fltkShortcut("statistics"), (Fl_Callback *)statistics_cb, nullptr},
    {"Message Console", fltkShortcut("console"), (Fl_Callback *)show_hide_message_cb, nullptr},
    {nullptr},
  {"Window", 0, nullptr, nullptr, FL_SUBMENU},
    {"New Window", 0, (Fl_Callback *)file_window_cb, (void*)"new", FL_MENU_DIVIDER},
#if defined(WIN32)
    {"Copy to Clipboard",  fltkShortcut("window_copy"), (Fl_Callback *)file_window_cb, (void*)"copy", FL_MENU_DIVIDER},
#endif
    {"Split Horizontally", 0, (Fl_Callback *)file_window_cb, (void*)"split_h"},
    {"Split Vertically",   0, (Fl_Callback *)file_window_cb, (void*)"split_v"},
    {"Unsplit",            0, (Fl_Callback *)file_window_cb, (void*)"split_u", FL_MENU_DIVIDER},
    {"Minimize",           fltkShortcut("minimize"), (Fl_Callback *)window_cb, (void*)"minimize"},
    {"Zoom",               0, (Fl_Callback *)window_cb, (void*)"zoom"},
    {"Enter Full Screen",  fltkShortcut("fullscreen"), (Fl_Callback *)window_cb, (void*)"fullscreen", FL_MENU_DIVIDER},
    {"Show/Hide Menu",     fltkShortcut("menu_show_hide"), (Fl_Callback *)show_hide_menu_cb, nullptr},
    {"Attach/Detach Menu", 0, (Fl_Callback *)attach_detach_menu_cb, nullptr},
    {"Dock/Undock Tool Window", fltkShortcut("dock"), (Fl_Callback *)dock_tool_cb, nullptr},
    {"Dock/Undock All Tool Windows", fltkShortcut("dock_all"), (Fl_Callback *)dock_tools_cb, nullptr, FL_MENU_DIVIDER},
    {"Bring All to Front", 0, (Fl_Callback *)window_cb, (void*)"front"},
    {nullptr},
  {"Help", 0, nullptr, nullptr, FL_SUBMENU},
    {"Online Documentation", 0, (Fl_Callback *)help_online_cb, nullptr, FL_MENU_DIVIDER},
    {"Keyboard and Mouse Usage",  fltkShortcut("help_keys"), (Fl_Callback *)help_basic_cb, nullptr, FL_MENU_DIVIDER},
    {"Current Options and Workspace", fltkShortcut("help_options"), (Fl_Callback *)status_options_cb, (void*)"?", 0},
    {"Restore all Options to Default Settings", 0, (Fl_Callback *)options_restore_defaults_cb, nullptr, FL_MENU_DIVIDER},
    {"About Gmsh",           0, (Fl_Callback *)help_about_cb, nullptr},
    {nullptr},
  {nullptr}
};

#if defined(__APPLE__)

// the items of the macOS system menu bar: those of the window bar without
// Quit and About, which the application menu has, nor the shortcut of the
// keyboard help, as Cmd+H hides the application
static Fl_Menu_Item *systemBarTable()
{
  static std::vector<Fl_Menu_Item> table;
  if(table.empty()) {
    int n = sizeof(bar_table) / sizeof(bar_table[0]);
    for(int i = 0; i < n; i++) {
      Fl_Menu_Item it = bar_table[i];
      if(it.callback_ == (Fl_Callback *)file_quit_cb ||
         it.callback_ == (Fl_Callback *)help_about_cb) {
        // the last of its menu: the divider above it goes too
        if(it.text && !bar_table[i + 1].text && table.size())
          table.back().flags &= ~FL_MENU_DIVIDER;
        continue;
      }
      if(it.callback_ == (Fl_Callback *)help_basic_cb)
        it.shortcut_ = fltkShortcut("help_keys", true);
      table.push_back(it);
    }
  }
  return &table[0];
}

#endif

// clang-format on

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

  std::vector<openglWindow *> gls;
  if(w)
    gls = getGraphicWindow(w)->gl;
  else
    gls.push_back(FlGui::instance()->getCurrentOpenglWindow());

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

// the index of the first visible view, or -1
static int firstVisibleView()
{
  for(std::size_t i = 0; i < PView::list.size(); i++)
    if(opt_view_visible(i, GMSH_GET, 0)) return i;
  return -1;
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

// Query and measure both wait for a click: starting one stops the other,
// which is only over once its loop has returned, so the one taking over is
// started from the event loop rather than from here.
static int _pendingMode = 0; // 1: query, 2: measure

static void _startPendingMode(void *)
{
  int what = _pendingMode;
  _pendingMode = 0;
  if(what == 1) status_query_cb(nullptr, nullptr);
  else if(what == 2) status_measure_cb(nullptr, nullptr);
}

// Query mode: every click says what the model holds where it hit - the
// entity, the mesh element and the node there, and the value of every visible
// view. A click replaces what the queries before it left on the picture, a
// Ctrl+click adds to it. It stays on until it is asked to stop (the button
// again or 'q'), as the first query of a large mesh or view builds a search
// structure that the ones after it reuse.
static bool _queryMode = false;

bool queryMode() { return _queryMode; }

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

void status_query_cb(Fl_Widget *w, void *data)
{
  if(!FlGui::available()) return;

  if(_queryMode) { // asked to stop while a query is waiting for a click
    for(openglWindow *gl : FlGui::instance()->openglWindows())
      gl->quitSelection = 1;
    return;
  }
  if(measureMode()) { // stop the measurement, and take over when it is over
    _pendingMode = 1;
    status_measure_cb(nullptr, nullptr);
    return;
  }

  _queryMode = true;
  updateModeButtons();
  int old = CTX::instance()->pickElements;
  CTX::instance()->pickElements = 1;
  // a query is a pick: it needs the mouse selection the "S" button switches
  if(!CTX::instance()->mouseSelection)
    opt_general_mouse_selection(0, GMSH_SET | GMSH_GUI, 1);

  while(1) {
    if(!FlGui::available()) break;
    Msg::StatusGl("Click to query the model, Ctrl+click to add a query\n"
                  "[Press 'q' to abort]");
    char ib = FlGui::instance()->selectEntity(ENT_ALL);
    if(!FlGui::available()) break;
    if(ib == 'q') break;
    if(ib != 'l') continue;

    openglWindow *gl = FlGui::instance()->getCurrentOpenglWindow();
    if(!gl) break;
    FlGui *g = FlGui::instance();
    if(!gl->queryClick(g->selectedVertices, g->selectedEdges, g->selectedFaces,
                       g->selectedRegions, g->selectedElements,
                       g->selectedViews))
      continue;
    drawContext::global()->draw();
  }

  CTX::instance()->pickElements = old;
  _queryMode = false;
  updateModeButtons();
  if(FlGui::available()) {
    GModel::current()->setSelection(0);
    for(openglWindow *gl : FlGui::instance()->openglWindows()) {
      gl->getDrawContext()->clearMarks();
      gl->pinTooltip("");
    }
    drawContext::global()->draw();
    Msg::StatusGl("");
  }
  if(_pendingMode) Fl::add_timeout(0., _startPendingMode);
}

// Measure mode: two clicks on the model, and the distance between the points
// they hit is drawn on the picture and printed. It stays on until it is asked
// to stop (the button again, Escape, or 'q'), so that distances can be taken
// one after the other.
static bool _measureMode = false;

bool measureMode() { return _measureMode; }

void status_measure_cb(Fl_Widget *w, void *data)
{
  if(!FlGui::available()) return;

  if(_measureMode) { // asked to stop while a measurement waits for a click
    for(openglWindow *gl : FlGui::instance()->openglWindows())
      gl->quitSelection = 1;
    return;
  }
  if(queryMode()) { // stop the query, and take over when it is over
    _pendingMode = 2;
    status_query_cb(nullptr, nullptr);
    return;
  }

  _measureMode = true;
  updateModeButtons();
  // a measurement is a pick: it needs the mouse selection the "S" button
  // switches, but not the mesh elements, only where the click hits
  if(!CTX::instance()->mouseSelection)
    opt_general_mouse_selection(0, GMSH_SET | GMSH_GUI, 1);

  while(1) {
    if(!FlGui::available()) break;
    openglWindow *current = FlGui::instance()->getCurrentOpenglWindow();
    Msg::StatusGl(current && current->measuring() ?
                    "Click the second point\n[Press 'q' to abort]" :
                    "Click the first point\n[Press 'q' to abort]");
    char ib = FlGui::instance()->selectEntity(ENT_ALL);
    if(!FlGui::available()) break;
    if(ib == 'q') break;
    if(ib != 'l') continue;

    openglWindow *gl = FlGui::instance()->getCurrentOpenglWindow();
    if(!gl) break;
    if(!gl->measureClick()) continue;
    drawContext::global()->draw();
  }

  _measureMode = false;
  updateModeButtons();
  if(FlGui::available()) {
    GModel::current()->setSelection(0);
    for(openglWindow *gl : FlGui::instance()->openglWindows()) {
      gl->getDrawContext()->clearMarks();
      gl->pinTooltip("");
    }
    drawContext::global()->draw();
    Msg::StatusGl("");
  }
  if(_pendingMode) Fl::add_timeout(0., _startPendingMode);
}

void status_options_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string what((const char *)data);

  if(what == "model") { // model selection
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
  else if(what == "menu") { // show or hide the menu
    show_hide_menu_cb(nullptr, nullptr);
  }
  else if(what == "?") { // display options
    help_options_cb(nullptr, nullptr);
    centerWindow(FlGui::instance()->help->options);
    FlGui::instance()->help->options->show();
  }
  else if(what == "p") { // toggle projection mode
    opt_general_orthographic(0, GMSH_SET | GMSH_GUI,
                             !opt_general_orthographic(0, GMSH_GET, 0));
    drawContext::global()->draw();
  }
  else if(what == "quick_access") { // quick access menu
    // (see Actions.cpp), opened on the item picked last
    static Fl_Menu_Button *menu = nullptr;
    static const void *last = nullptr;
    if(!menu) {
      Fl_Group::current(nullptr);
      menu = new Fl_Menu_Button(0, 0, 0, 0);
    }
    menu->clear();
    addActionItems(menu, GetActionMenu("Quick access"), -1);
    // (the display of the mesh toggled, at first)
    const Fl_Menu_Item *initial = nullptr;
    for(int i = 0; i < menu->size(); i++) {
      const actionItem *item = (const actionItem *)menu->menu()[i].user_data();
      if(item && (last ? item == last : item->what == "Toggle mesh display"))
        initial = &menu->menu()[i];
    }
    const Fl_Menu_Item *picked = menu->menu()->popup(
      Fl::event_x(), Fl::event_y(), nullptr, initial, gmshPopupStyle());
    if(picked && picked->callback()) {
      last = picked->user_data();
      picked->do_callback(menu, picked->user_data());
    }
    drawContext::global()->draw();
  }
  else if(what == "S") { // mouse selection
    if(CTX::instance()->mouseSelection) {
      opt_general_mouse_selection(0, GMSH_SET | GMSH_GUI, 0);
      for(openglWindow *gl : FlGui::instance()->openglWindows())
        gl->cursor(FL_CURSOR_DEFAULT, FL_BLACK, FL_WHITE);
    }
    else
      opt_general_mouse_selection(0, GMSH_SET | GMSH_GUI, 1);
  }
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

// the main window docking the tool windows, which reach it through the hooks of
// paletteWindow
static graphicWindow *theDocking = nullptr;
static void dock_hook(paletteWindow *w) { theDocking->dockTool(w); }
static bool close_tool_hook(Fl_Window *w)
{
  // Cmd-W in the main window closes the tool shown in the dock, if any
  return theDocking->getWindow() == w && theDocking->closeDockedTool();
}
static void resized_hook(paletteWindow *w) { theDocking->toolResized(w); }
static void hidden_hook(paletteWindow *w) { theDocking->toolHidden(w); }
static void moved_hook(paletteWindow *w) { theDocking->toolMoved(w); }
static void drag_hook(paletteWindow *w) { theDocking->dragToDock(w); }
static int drop_hook(int event) { return theDocking->toolDrop(event); }
static void torn_out_hook(paletteWindow *w, int x, int y)
{ theDocking->toolTornOut(w, x, y); }

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

graphicWindow::graphicWindow(bool main, int numTiles, bool detachedMenu)
  : _autoScrollMessages(true), _pushX(0), _pushY(0), _pushMenuWidth(0),
    _pushMessageHeight(0)
{
  int mh = main ? BH : 0; // menu bar height
#if defined(__APPLE__)
  if(CTX::instance()->systemMenuBar) mh = 0;
#endif
  // the status bar and its buttons: as tall as the menu bar and wider under
  // the gmsh theme, for its icons
  int sh = gmshScheme() ? BH : 2 * FL_NORMAL_SIZE - 3;
  int sw = gmshScheme() ? 1.7 * FL_NORMAL_SIZE : FL_NORMAL_SIZE + 2;
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
    _win = new paletteWindow(width, height, false);
    _win->callback(remove_graphic_window_cb);
  }

#if defined(__APPLE__)
  _sysbar = nullptr;
#endif
  _bar = nullptr;
  if(main) {
#if defined(__APPLE__)
    if(CTX::instance()->systemMenuBar) {
      _sysbar = new Fl_Sys_Menu_Bar(1, 1, 1, 1);
      _sysbar->menu(systemBarTable());
      _sysbar->global();
      fillRecentHistoryMenu();
    }
    else {
#endif
      _bar = new hoverMenuBar(0, 0, width, BH);
      _bar->menu(bar_table);
      _bar->global();
      fillRecentHistoryMenu();
#if defined(__APPLE__)
    }
#endif
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

  _butt[14] =
    new Fl_Button(x, mh + glheight + mheight + 2, sw, sht, "@-1gmsh_sidebar");
  _butt[14]->callback(status_options_cb, (void *)"menu");
  static std::string menuTip = "Show or hide the menu (" +
                               GetShortcutsOf("menu_show_hide")[0].label() +
                               ")";
  _butt[14]->tooltip(menuTip.c_str());
  x += sw;
  _butt[5] =
    new Fl_Button(x, mh + glheight + mheight + 2, sw, sht, "@-1gmsh_models");
  _butt[5]->callback(status_options_cb, (void *)"model");
  _butt[5]->tooltip("Set current (active) model");
  x += sw;
  _butt[8] = new Fl_Button(x, mh + glheight + mheight + 2, sw, sht, "O");
  _butt[8]->callback(status_options_cb, (void *)"quick_access");
  _butt[8]->tooltip("Open quick access menu (also available by double-clicking "
                    "in the graphic window)");
  x += sw;
  _butt[0] = new Fl_Button(x, mh + glheight + mheight + 2, sw, sht, "X");
  _butt[0]->callback(status_xyz1p_cb, (void *)"x");
  _butt[0]->tooltip("Set +X or -X (Shift) view (Alt+x or Alt+Shift+x)");
  x += sw;
  _butt[1] = new Fl_Button(x, mh + glheight + mheight + 2, sw, sht, "Y");
  _butt[1]->callback(status_xyz1p_cb, (void *)"y");
  _butt[1]->tooltip("Set +Y or -Y (Shift) view (Alt+y or Alt+Shift+y)");
  x += sw;
  _butt[2] = new Fl_Button(x, mh + glheight + mheight + 2, sw, sht, "Z");
  _butt[2]->callback(status_xyz1p_cb, (void *)"z");
  _butt[2]->tooltip("Set +Z or -Z (Shift) view (Alt+z or Alt+Shift+z)");
  x += sw;
  _butt[15] =
    new Fl_Button(x, mh + glheight + mheight + 2, sw, sht, "@-1gmsh_cube");
  _butt[15]->callback(status_xyz1p_cb, (void *)"3d");
  _butt[15]->tooltip("Set isometric 3D view, Z up, or from the opposite side "
                     "(Shift) (Alt+3 or Alt+Shift+3)");
  x += sw;
  _butt[4] =
    new Fl_Button(x, mh + glheight + mheight + 2, sw, sht, "@-1gmsh_rotate");
  _butt[4]->callback(status_xyz1p_cb, (void *)"r");
  _butt[4]->tooltip(
    "Rotate +90 or -90 (Shift) degrees, or sync rotations (Ctrl)");
  x += sw;
  _butt[3] = new Fl_Button(x, mh + glheight + mheight + 2, 2 * FL_NORMAL_SIZE,
                           sht, "1:1");
  _butt[3]->callback(status_xyz1p_cb, (void *)"1:1");
  _butt[3]->tooltip("Fit the model in the window, sync scale between viewports "
                    "(Ctrl), or reset bounding box around visible entities "
                    "(Shift) (Alt+1, Alt+Ctrl+1, Alt+Shift+1)");
  x += 1.75 * FL_NORMAL_SIZE;
  _butt[9] = new Fl_Button(x, mh + glheight + mheight + 2, sw, sht, "S");
  _butt[9]->callback(status_options_cb, (void *)"S");
  _butt[9]->tooltip("Toggle mouse selection ON/OFF (Escape)");
  x += sw;
  _butt[12] =
    new Fl_Button(x, mh + glheight + mheight + 2, sw, sht, "@-1gmsh_query");
  _butt[12]->callback(status_query_cb);
  _butt[12]->tooltip("Query the model where you click ('q' to stop)");
  x += sw;
  _butt[13] =
    new Fl_Button(x, mh + glheight + mheight + 2, sw, sht, "@-1gmsh_measure");
  _butt[13]->callback(status_measure_cb);
  _butt[13]->tooltip("Measure the distance between two points you click "
                     "('q' to stop)");
  x += sw;
  x += 4;
  _butt[6] =
    new Fl_Button(x, mh + glheight + mheight + 2, sw, sht, "@-1gmsh_rewind");
  _butt[6]->callback(status_rewind_cb);
  _butt[6]->tooltip("Rewind animation");
  _butt[6]->deactivate();
  x += sw;
  _butt[10] =
    new Fl_Button(x, mh + glheight + mheight + 2, sw, sht, "@-1gmsh_back");
  _butt[10]->callback(status_stepbackward_cb);
  _butt[10]->tooltip("Step backward (Left arrow)");
  _butt[10]->deactivate();
  x += sw;
  _butt[7] =
    new Fl_Button(x, mh + glheight + mheight + 2, sw, sht, "@-1gmsh_play");
  _butt[7]->callback(status_play_cb);
  _butt[7]->tooltip("Play/pause animation");
  _butt[7]->deactivate();
  x += sw;
  _butt[11] =
    new Fl_Button(x, mh + glheight + mheight + 2, sw, sht, "@-1gmsh_forward");
  _butt[11]->callback(status_stepforward_cb);
  _butt[11]->tooltip("Step forward (Right arrow)");
  _butt[11]->deactivate();
  x += sw;

  for(int i = 0; i < 16; i++) {
    _butt[i]->box(FL_FLAT_BOX);
    _butt[i]->selection_color(FL_BACKGROUND2_COLOR);
    _butt[i]->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
  }
  if(gmshScheme()) {
    // the icons in place of the symbols
    gmshIcon(_butt[14], "sidebar", _iconSize);
    gmshIcon(_butt[5], "models", _iconSize);
    gmshIcon(_butt[8], "quick", _iconSize);
    gmshIcon(_butt[15], "cube", _iconSize);
    gmshIcon(_butt[4], "rotate", _iconSize);
    gmshIcon(_butt[12], "query", _iconSize);
    gmshIcon(_butt[13], "measure", _iconSize);
    gmshIcon(_butt[6], "rewind", _iconSize);
    gmshIcon(_butt[10], "back", _iconSize);
    gmshIcon(_butt[7], "play", _iconSize);
    gmshIcon(_butt[11], "forward", _iconSize);
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

static void dropped_cb(void *data);

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
  openglWindow::setLastHandled(nullptr);
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
  if(mode) {
    _butt[7]->callback(status_play_cb);
    if(gmshScheme())
      gmshIcon(_butt[7], "play", _iconSize);
    else
      _butt[7]->label("@-1gmsh_play");
  }
  else {
    _butt[7]->callback(status_pause_cb);
    if(gmshScheme())
      gmshIcon(_butt[7], "pause", _iconSize);
    else
      _butt[7]->label("@-1gmsh_pause");
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
  if(play) {
    _butt[6]->activate();
    _butt[7]->activate();
    _butt[10]->activate();
    _butt[11]->activate();
  }
  else {
    _butt[6]->deactivate();
    _butt[7]->deactivate();
    _butt[10]->deactivate();
    _butt[11]->deactivate();
  }
}

bool graphicWindow::runMenuShortcut()
{
  // the entry of the menu bar whose shortcut is the event, run as a click on
  // it would; the system menu bar of macOS does not always take its own
  Fl_Menu_Item *table = bar_table;
  Fl_Widget *w = _bar;
#if defined(__APPLE__)
  if(_sysbar) {
    table = systemBarTable();
    w = _sysbar;
  }
#endif
  const Fl_Menu_Item *m = table->test_shortcut();
  if(!m || !m->callback()) return false;
  const_cast<Fl_Menu_Item *>(m)->do_callback(w);
  return true;
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

bool graphicWindow::isDockShown() { return _dock && _dock->visible(); }

// the least width of the tool windows, in the frame of the dock tabs
static int leastDockWidth() { return TW + Fl::box_dw(FL_THIN_UP_BOX); }

int graphicWindow::getDockWidth()
{ return std::max(CTX::instance()->dockWidth, leastDockWidth()); }

int graphicWindow::_leastTileWidth()
{
  // the tree, and some room for the graphics
  int tw = (_onelab && !_menuwin) ? _onelab->w() : 0;
  return std::max(_minWidth, tw + BB);
}

int graphicWindow::_fitDockWidth(int w)
{
  w = std::min(w, _win->w() - WB - _leastTileWidth());
  return std::max(w, leastDockWidth());
}

void graphicWindow::setDockWidth(int w)
{
  if(!isDockShown()) return;
  w = _fitDockWidth(w);
  CTX::instance()->dockWidth = w;
  _layoutDock(w);
}

void graphicWindow::setDocking(bool docking)
{
  if(!_dock) return;
  if(docking) {
    theDocking = this;
    paletteWindow::dockHook = dock_hook;
    mainWindow::closeToolHook = close_tool_hook;
    paletteWindow::resizedHook = resized_hook;
    paletteWindow::hiddenHook = hidden_hook;
    paletteWindow::movedHook = moved_hook;
    paletteWindow::dragHook = drag_hook;
    mainWindow::dropHook = drop_hook;
    toolDock::tornOutHook = torn_out_hook;
    // the tool windows open on the desktop join the dock, in the order they
    // were shown (the list of FLTK starts with the newest)
    std::vector<paletteWindow *> open;
    for(Fl_Window *w = Fl::first_window(); w; w = Fl::next_window(w)) {
      paletteWindow *p = dynamic_cast<paletteWindow *>(w);
      if(p && p->dockable() && !p->parent()) open.push_back(p);
    }
    std::reverse(open.begin(), open.end());
    for(auto p : open) p->show();
  }
  else {
    paletteWindow::dockHook = nullptr;
    _dock->undockAll();
    paletteWindow::hiddenHook = nullptr;
    paletteWindow::movedHook = nullptr;
    paletteWindow::dragHook = nullptr;
    mainWindow::dropHook = nullptr;
    toolDock::tornOutHook = nullptr;
    paletteWindow::dragged = nullptr;
    theDocking = nullptr;
    mainWindow::closeToolHook = nullptr;
    paletteWindow::resizedHook = nullptr;
    _layoutDock(0);
  }
}

void graphicWindow::toolTornOut(paletteWindow *w, int x, int y)
{
  if(_dock->empty()) _layoutDock(0);
  // the title bar under the pointer, which held the tab or the title
  placeWindowAt(w, x - w->w() / 2, y + BH / 2);
  w->show();
  FlGui::instance()->storeFloatingTools();
}

bool graphicWindow::_overDock(paletteWindow *w)
{
  // Wayland hides where the windows are on the screen: there a tool is docked
  // by dragging a tab or its background, not its title bar (see toolDrop())
  if(!screenPositionsKnown()) return false;
  // the middle of the title bar of the tool over the dock, or over where the
  // dock would be while none is docked: the right of the tiles
  int th = w->decorated_h() - w->h();
  int cx = w->x() + w->w() / 2, cy = w->y() - th / 2;
  int X = _win->x() + _win->w() - getDockWidth(), W = getDockWidth();
  if(isDockShown()) {
    X = _win->x() + _dock->x();
    W = _dock->w();
  }
  int Y = _win->y() + _tile->y(), H = _tile->h();
  return cx >= X && cx < X + W && cy >= Y && cy < Y + H;
}

void graphicWindow::toolMoved(paletteWindow *w)
{
  if(!w->shown() || !_win->shown()) return;
  if(_overDock(w)) {
    if(_dropping != w) {
      _dropping = w;
      _dropTarget(true);
      // docked when the button is released: the system is asked for it
      Fl::add_timeout(0.05, _drop_cb, this);
    }
  }
  else if(_dropping == w) {
    Fl::remove_timeout(_drop_cb, this);
    _dropping = nullptr;
    _dropTarget(false);
  }
}

void graphicWindow::_dropTarget(bool on)
{
  // the dock as the target of a drop, shown empty while none is docked
  if(on && !isDockShown()) _layoutDock(_fitDockWidth(getDockWidth()));
  _dropHint(on);
  if(!on && _dock->empty()) _layoutDock(0);
}

void graphicWindow::_dropHint(bool on)
{
  _dock->dropHint(on);
  if(on == _divider->highlight) return;
  _divider->highlight = on;
  _divider->redraw();
}

void graphicWindow::_drop_cb(void *data)
{
  graphicWindow *g = (graphicWindow *)data;
  paletteWindow *w = g->_dropping;
  if(!w) return;
  // Shift held keeps the tool out of the dock, to leave it over the dock
  // (Alt would tile the window on macOS): no hint while it is
  bool shift = shiftKeyDown();
  g->_dropHint(!shift);
  int down = mouseButtonDown();
  if(down == 1) {
    Fl::repeat_timeout(0.05, _drop_cb, data);
    return;
  }
  g->_dropping = nullptr;
  g->_dropTarget(false);
  // kept out when Shift is held, or where the system cannot say
  if(shift || down == -1) return;
  w->floating(false);
  w->show(); // docks it
  FlGui::instance()->storeFloatingTools();
}

void graphicWindow::dragToDock(paletteWindow *w)
{
  // an FLTK drag and drop of the label of the tool, which the system shows
  // along the pointer; the drop lands in toolDrop()
  const char *label = w->label() ? w->label() : "";
  paletteWindow::dragged = w;
  Fl::copy(label, strlen(label), 0);
  Fl::dnd();
}

static void dropped_cb(void *data)
{
  paletteWindow *w = (paletteWindow *)data;
  w->floating(false);
  w->show(); // docks it
  FlGui::instance()->storeFloatingTools();
}

int graphicWindow::toolDrop(int event)
{
  paletteWindow *w = paletteWindow::dragged;
  switch(event) {
  case FL_DND_ENTER:
  case FL_DND_DRAG: {
    // over the dock, or where it would be while none is docked: the right of
    // the tiles
    int X = isDockShown() ? _dock->x() : _win->w() - getDockWidth();
    bool over = Fl::event_x() >= X && Fl::event_y() >= _tile->y() &&
                Fl::event_y() < _tile->y() + _tile->h();
    _dropTarget(over);
    // the release and the text dropped go to the widget below the mouse
    if(over) Fl::belowmouse(_win);
    return over;
  }
  case FL_DND_LEAVE: _dropTarget(false); return 1;
  case FL_DND_RELEASE: return _dock->dropHint();
  case FL_PASTE:
    paletteWindow::dragged = nullptr;
    _dropTarget(false);
    // ours, by its text; docked once the drag is over
    if(w->label() && Fl::event_text() && !strcmp(Fl::event_text(), w->label()))
      Fl::add_timeout(0., dropped_cb, w);
    return 1;
  }
  return 0;
}

void graphicWindow::toolResized(paletteWindow *w) { _dock->resized(w); }

paletteWindow *graphicWindow::currentDockedTool()
{ return isDockShown() ? _dock->current() : nullptr; }

bool graphicWindow::closeDockedTool()
{ return isDockShown() && _dock->closeCurrent(); }

void graphicWindow::dockTool(paletteWindow *w)
{
  if(!isDockShown()) {
    // the window widened if the graphics would get narrower than their least,
    // within the screen
    int need = _leastTileWidth() + getDockWidth() + WB;
    if(_win->w() < need) {
      int sx, sy, sw, sh;
      windowWorkArea(_win, sx, sy, sw, sh);
      _win->size(std::min(need, sw), _win->h());
    }
    _layoutDock(_fitDockWidth(getDockWidth()));
  }
  _dock->dock(w);
}

void graphicWindow::toolHidden(paletteWindow *w)
{
  _dock->hidden(w);
  if(_dock->empty()) _layoutDock(0);
}

void graphicWindow::_layoutDock(int width)
{
  // the tiles take what the dock leaves
  int ww = _win->w(), y = _tile->y(), h = _tile->h();
  int dw = width ? width + WB : 0;
  _tile->resize(0, y, ww - dw, h);
  if(width) {
    _divider->resize(ww - dw, y, WB, h);
    _divider->show();
    _dock->resize(ww - width, y, width, h);
    _dock->show();
  }
  else {
    _divider->hide();
    _dock->hide();
  }
  // the dock keeps its width when the window is resized, and the window keeps
  // room for it
  _win->size_range((width ? _leastTileWidth() : _minWidth) + dw, _minHeight);
  _resbox->resize(_minWidth, _resbox->y(), std::max(1, ww - dw - _minWidth),
                  _resbox->h());
  _win->init_sizes();
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

void graphicWindow::fillRecentHistoryMenu()
{
#if defined(__APPLE__)
  if(CTX::instance()->systemMenuBar && !_sysbar) return;
#endif

  Fl_Menu_Item *table = bar_table;
#if defined(__APPLE__)
  if(CTX::instance()->systemMenuBar) table = systemBarTable();
#endif

  static std::string recent[10];
  for(int i = 0; i < 10; i++) {
    recent[i].clear();
    if(i < (int)CTX::instance()->recentFiles.size()) {
      if(check_utf8(CTX::instance()->recentFiles[i]))
        recent[i] = CTX::instance()->recentFiles[i];
      else
        Msg::Info("Ignoring invalid General.RecentFile%d", i);
    }
    table[4 + i].text = recent[i].c_str();
    table[4 + i].user_data_ = (void *)recent[i].c_str();
  }

#if defined(__APPLE__)
  if(CTX::instance()->systemMenuBar) _sysbar->menu(table);
#endif
}

// The actions of the registry (see Actions.h) as this interface does them

// an operation, with the context window that holds its fields, if it has one
static void runOperation(const std::string &op)
{
  FlGui *g = FlGui::instance();
  // the mesh parts picked deleted or reversed: not during another operation
  // on the model (nor the picking mode changed then)
  if(op.find(" mesh ") != std::string::npos) {
    if(modelBusy()) return;
    runSelection(op);
    afterMeshOperation();
    return;
  }
  // the pane of the transform context window, and whether it extrudes
  static const std::map<std::string, std::pair<int, bool>> transforms = {
    {"Translate", {0, false}},
    {"Rotate", {1, false}},
    {"Scale", {2, false}},
    {"Symmetry", {3, false}},
    {"Fillet", {5, false}},
    {"Delete", {6, false}},
    {"Extrude translate", {0, true}},
    {"Extrude rotate", {1, true}},
    {"Pipe", {-1, true}}};
  // the pane of the mesh context window
  static const std::map<std::string, int> meshPanes = {
    {"Size at points", 0},
    {"Transfinite Curve", 1},
    {"Transfinite Surface", 2}};
  auto t = transforms.find(op);
  auto m = meshPanes.find(op);
  std::function<void()> hide = [] {};
  if(op.find("Physical ") != std::string::npos) {
    g->physicalContext->show(op.substr(op.rfind(' ') + 1), op[0] == 'R');
    hide = [] { FlGui::instance()->physicalContext->hide(); };
  }
  else if(t != transforms.end() || op.compare(0, 7, "Boolean") == 0) {
    if(t != transforms.end())
      g->transformContext->show(t->second.first, t->second.second,
                                op != "Fillet");
    else
      g->transformContext->show(4);
    hide = [] { FlGui::instance()->transformContext->hide(); };
  }
  else if(m != meshPanes.end()) {
    g->meshContext->show(m->second);
    hide = [] { FlGui::instance()->meshContext->hide(); };
  }
  runSelection(op);
  if(FlGui::available()) hide();
}

// a shape: placed with the mouse, or from the values of its fields
static void addShape(const std::string &shape)
{
  if(shape == "Parameter") {
    FlGui::instance()->elementaryContext->show(0);
    return;
  }
  // (by pane of the elementary context window)
  for(int pane = 1; pane < 12; pane++)
    if(shape == scriptShapes()[pane].name)
      add_new_point_based_entity(shape, pane);
}

// the actions of the table this interface does: what it does (view: the
// index of the view of a menu of a view), its check mark, and whether it has
// it now (always if not said)
struct fltkAction {
  std::function<void(int view)> run;
  std::function<int()> check;
  std::function<bool()> available;
};

static const std::map<std::string, fltkAction> &fltkActions()
{
  static const std::map<std::string, fltkAction> actions = {
    // the modules
    {"Reload script", {[](int) { geometry_reload_cb(nullptr, nullptr); }}},
    {"Edit script", {[](int) { geometry_edit_cb(nullptr, nullptr); }}},
#if defined(HAVE_MESH)
    {"Reclassify surfaces", {[](int) { mesh_classify_cb(nullptr, nullptr); }}},
    {"Save mesh", {[](int) { mesh_save_cb(nullptr, nullptr); }}},
    {"Size fields", {[](int) { field_cb(nullptr, nullptr); }}},
    {"High-order tools", {[](int) { highordertools_cb(nullptr, nullptr); }}},
#if defined(HAVE_METIS)
    {"Partition mesh", {[](int) { partition_dialog(); }}},
#endif
#endif
    // the quick access menu
    {"Select rotation center", {[](int) {
       opt_general_rotation_center_cg(0, GMSH_SET | GMSH_GUI, 0);
       general_options_ok_cb(nullptr, (void *)"rotation_center");
       general_options_rotation_center_select_cb(nullptr, nullptr);
     }}},
    {"Query",
     {[](int) { status_query_cb(nullptr, nullptr); },
      [] { return (int)queryMode(); }}},
    {"Measure",
     {[](int) { status_measure_cb(nullptr, nullptr); },
      [] { return (int)measureMode(); }}},
    {"Full screen",
     {[](int) { window_cb(nullptr, (void *)"fullscreen"); },
      [] { return (int)FlGui::instance()->fullscreen->shown(); }}},
    {"Split window horizontally",
     {[](int) { file_window_cb(nullptr, (void *)"split_h"); }}},
    {"Split window vertically",
     {[](int) { file_window_cb(nullptr, (void *)"split_v"); }}},
    {"Unsplit window",
     {[](int) { file_window_cb(nullptr, (void *)"split_u"); }}},
    {"General options", {[](int) { general_options_cb(nullptr, nullptr); }}},
    {"Geometry options", {[](int) { geometry_options_cb(nullptr, nullptr); }}},
    {"Mesh options", {[](int) { mesh_options_cb(nullptr, nullptr); }}},
    {"All view options", {[](int) { view_options_cb(nullptr, (void *)-1); }}},
    // the menu of a view
    {"View options",
     {[](int view) { view_options_cb(nullptr, (void *)(intptr_t)view); }}},
    {"View plugins",
     {[](int view) { plugin_cb(nullptr, (void *)(intptr_t)view); }}},
    {"Export view",
     {[](int view) { view_save_cb(nullptr, (void *)(intptr_t)view); }}},
  };
  return actions;
}

bool canRunItem(const actionItem &item)
{
  if(!IsActionAvailable(item)) return false;
  if(item.kind != ActionRun || !IsDoneByInterface(item)) return true;
  auto it = fltkActions().find(item.what);
  return it != fltkActions().end() &&
         (!it->second.available || it->second.available());
}

// the value an item asks for, with a slider
static void askFor(const actionItem &item)
{
  double min, max, step, value;
  GetActionAsk(item.ask, min, max, step, value);
  std::string::size_type dot = item.ask.option.find('.');
  std::string category = item.ask.option.substr(0, dot);
  int index = (category == "View") ? firstVisibleView() : 0;
  if(index < 0) return;
  drawContext::global()->draw();
  double v = numberOrStringOptionChooser(category, index,
                                         item.ask.option.substr(dot + 1), true,
                                         item.label, true, min, max, step);
  SetActionOption(item.ask.option, v);
}

void runItem(const actionItem &item, int view)
{
  if(IsDoneByInterface(item)) {
    if(item.kind == ActionOperation)
      runOperation(item.what);
    else if(item.kind == ActionShape)
      addShape(item.what);
    else {
      auto it = fltkActions().find(item.what);
      if(it != fltkActions().end()) it->second.run(view);
    }
  }
  else {
    openglWindow *gl = FlGui::instance()->getCurrentOpenglWindow();
    int ret = RunAction(item, view, gl ? gl->getDrawContext() : nullptr);
    // the interface may have been closed meanwhile
    if(!FlGui::available()) return;
    if(ret & ActionViewsChanged) FlGui::instance()->updateViews(true);
    if(ret & ActionModelChanged) FlGui::instance()->resetVisibility();
    // (before the drawing, which processes events)
    FlGui::instance()->updateStatistics();
  }
  if(!FlGui::available()) return;
  if(!item.ask.option.empty()) askFor(item);
  drawContext::global()->draw();
}

void runAction(const std::string &name)
{ runItem(actionItem{"", ActionRun, name, {}, "", "", {}}); }

static void item_cb(Fl_Widget *w, void *data)
{
  // (the menu of a view keeps its index)
  int view = w ? (int)(intptr_t)w->user_data() : -1;
  runItem(*(const actionItem *)data, view);
}

// whether a menu has an item this interface has now
static bool anyItem(const actionItem &menu)
{
  for(const actionItem &item : menu.items)
    if(item.kind == ActionMenu ? anyItem(item) : canRunItem(item)) return true;
  return false;
}

// the items of menu added to an FLTK menu under prefix (the path of a
// submenu), a group set apart by a divider; the index of the last one added
// at the level of prefix, or -1
static int addItems(Fl_Menu_ *m, const actionItem &menu,
                    const std::string &prefix)
{
  int last = -1;
  for(const actionItem &item : menu.items) {
    if(item.kind == ActionMenu) {
      if(!anyItem(item)) continue;
      if(item.label.empty()) { // a group
        if(last >= 0) m->mode(last, m->mode(last) | FL_MENU_DIVIDER);
        int l = addItems(m, item, prefix);
        if(l >= 0) last = l;
      }
      else { // a submenu
        addItems(m, item, prefix + item.label + "/");
        last = m->find_index((prefix + item.label).c_str());
      }
      continue;
    }
    if(!canRunItem(item)) continue;
    int check = GetActionCheck(item);
    if(IsDoneByInterface(item) && item.kind == ActionRun) {
      auto it = fltkActions().find(item.what);
      check = it->second.check ? it->second.check() : -1;
    }
    int flags = 0;
    if(check >= 0)
      flags = (item.what.find('=') == std::string::npos ? FL_MENU_TOGGLE :
                                                          FL_MENU_RADIO) |
              (check ? FL_MENU_VALUE : 0);
    last = m->add((prefix + item.label).c_str(),
                  item.key.empty() ? 0 : fltkShortcut(item.key.c_str()),
                  item_cb, (void *)&item, flags);
  }
  return last;
}

void addActionItems(Fl_Menu_ *m, const actionItem &menu, int view)
{
  m->user_data((void *)(intptr_t)view);
  addItems(m, menu, "");
}

static void item_button_cb(Fl_Widget *w, void *data)
{ runItem(*(const actionItem *)data, -1); }

// the buttons of a module (see Actions.cpp) as rows of the tree, a menu as a
// row that pops it up, its submenus as submenus
void onelabGroup::_addModuleButtons(const std::string &module)
{
  for(const actionItem &row : GetActionMenu(module).items) {
    for(const actionItem &b : row.items) {
      std::string path = "0Modules/" + module + "/" + b.label;
      if(b.kind != ActionMenu) {
        if(canRunItem(b)) _addMenu(path, item_button_cb, (void *)&b, b.help);
        continue;
      }
      if(!anyItem(b)) continue;
      Fl_Tree_Item *n = _tree->add(path.c_str());
      if(!n) {
        Msg::Debug("Could not add item '%s' in tree", path.c_str());
        continue;
      }
      _addRow(n, [&](int ww, int hh) {
        // (its label where a button has it, 3 pixels in)
        Fl_Menu_Button *but = new Fl_Menu_Button(4, 1, ww - 3, hh);
        but->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
        but->box(FL_FLAT_BOX);
        but->color(_tree->color());
        but->selection_color(_tree->color());
        but->copy_label(b.label.c_str());
        but->copy_tooltip(b.help.c_str());
        addActionItems(but, b, -1);
      });
    }
  }
}

void onelabGroup::_addGmshMenus()
{
  _tree->sortorder(FL_TREE_SORT_NONE);

  _addModuleButtons("Geometry");
#if defined(HAVE_MESH)
  _addModuleButtons("Mesh");
#endif

  // add dynamic solver module items
  for(int i = 0; i < NUM_SOLVERS; i++) {
    std::string name = opt_solver_name(i, GMSH_GET, "");
    if(name.size()) _addSolverMenu(i);
  }

  // add dynamic post-processing module items
  for(std::size_t i = 0; i < PView::list.size(); i++) _addViewMenu(i);

  _tree->sortorder(FL_TREE_SORT_ASCENDING);

  if(_firstBuild) {
    _firstBuild = false;
    Fl_Tree_Item *n0 = _tree->find_item("0Modules");
    for(Fl_Tree_Item *n = n0; n; n = n->next()) {
      if(!n->is_root() && n->has_children() && n->depth() > 1) n->close();
    }
  }
}

std::set<std::string> onelabGroup::_getClosedGmshMenus()
{
  std::set<std::string> closed;
  Fl_Tree_Item *n0 = _tree->find_item("0Modules");
  for(Fl_Tree_Item *n = n0; n; n = n->next()) {
    if(!n->is_root() && n->has_children() && n->is_close()) {
      char path[1024];
      _tree->item_pathname(path, sizeof(path), n);
      closed.insert(path);
    }
  }
  return closed;
}
