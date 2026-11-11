// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// What the File and Help menus of the FLTK graphical user interface do (see
// fileActions.h): the project made, opened, merged into, cleared, the remote
// Gmsh, the project exported, its options saved, renamed, deleted and quit,
// the files watched, the help windows, and the script and the mesh of the
// modules. The table of fltkActions.cpp names them.

#include "GmshConfig.h"
#include "GmshDefines.h"
#include "GmshVersion.h"
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <set>
#include <string>
#include <vector>
#include <FL/Fl.H>
#include <FL/fl_ask.H>
#include <FL/filename.H>
#include <FL/Fl_Menu_.H>
#include <FL/Fl_Check_Button.H>
#include "FlGui.h"
#include "drawContext.h"
#include "fileActions.h"
#include "helpWindow.h"
#include "editorWindow.h"
#include "visibilityWindow.h"
#include "onelabActions.h"
#include "fileDialogs.h"
#include "extraDialogs.h"
#include "windowPlacement.h"
#include "gmshLocalNetworkClient.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "PView.h"
#include "PViewData.h"
#include "OpenFile.h"
#include "CreateFile.h"
#include "Options.h"
#include "Context.h"
#include "StringUtils.h"
#include "OS.h"
#include "onelabUtils.h"

void fileNew()
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

// a project opened, or files merged into it, chosen in a dialog
static void openOrMerge(bool merge)
{
  if(modelBusy()) return;
  int n = PView::list.size();
  int f =
    fileChooser(FILE_CHOOSER_MULTI, merge ? "Merge" : "Open", input_formats);
  if(f) {
    for(int i = 1; i <= f; i++) {
      if(merge)
        MergeFile(fileChooserGetName(i));
      else
        OpenProject(fileChooserGetName(i));
    }
    // the GUI may have been closed while the files were read
    if(!FlGui::available()) return;
    if(n != (int)PView::list.size())
      FlGui::instance()->openModule("Post-processing");
    if(CTX::instance()->launchSolverAtStartup >= 0)
      selectSolver(CTX::instance()->launchSolverAtStartup);
    else if(onelabUtils::haveSolverToRun())
      onelabCheck();
    drawContext::global()->draw();
  }
}

void fileOpen() { openOrMerge(false); }

void fileMerge() { openOrMerge(true); }

void fileOpenRecent(int i)
{
  if(i < 0 || i >= (int)CTX::instance()->recentFiles.size()) return;
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
    selectSolver(CTX::instance()->launchSolverAtStartup);
  else if(onelabUtils::haveSolverToRun())
    onelabCheck();
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

static void open_recent_cb(Fl_Widget *w, void *data)
{ fileOpenRecent((intptr_t)data); }

// (see fillRecentHistoryMenu(); the second one, the file opened before the
// current one, has a shortcut)
void addRecentFiles(Fl_Menu_ *m, const std::string &path)
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
           i == 1 ? fltkShortcut("file_open_previous") : 0, open_recent_cb,
           (void *)(intptr_t)i);
  }
}

void fileClear()
{
  if(modelBusy()) return;
  if(solverBusy()) return;
  ClearProject();
  if(onelabUtils::haveSolverToRun())
    onelabReset(); // this will call OpenProject
  else
    OpenProject(GModel::current()->getFileName());
  drawContext::global()->draw();
}

// the GmshRemote client of the ONELAB server, made if there is none
static onelab::localNetworkClient *remoteClient()
{
  auto it = onelab::server::instance()->findClient("GmshRemote");
  if(it != onelab::server::instance()->lastClient())
    return (onelab::localNetworkClient *)(*it);
  gmshLocalNetworkClient *c = new gmshLocalNetworkClient("GmshRemote", "");
  c->setSocketSwitch("-socket");
  return c;
}

// the server of the remote Gmsh, or null, with an error saying what could
// not be done
static GmshServer *remoteServer(const char *what)
{
  GmshServer *server = remoteClient()->getGmshServer();
  if(!server) Msg::Error("Cannot %s: remote Gmsh not running", what);
  return server;
}

void remoteStart()
{
  onelab::localNetworkClient *c = remoteClient();
  if(c->getGmshServer()) {
    Msg::Error("Cannot start: remote Gmsh is already running");
    return;
  }
  c->setExecutable(connectionChooser());
  if(c->getExecutable().size()) c->run();
}

void remoteMerge()
{
  GmshServer *server = remoteServer("merge");
  if(!server) return;
  const char *file = fl_input("Merge", "/tmp/data.pos");
  if(file) server->SendString(GmshSocket::GMSH_MERGE_FILE, file);
}

void remoteClear()
{
  GmshServer *server = remoteServer("clear");
  if(!server) return;
  server->SendString(GmshSocket::GMSH_PARSE_STRING, "Delete All;");
  for(int i = PView::list.size() - 1; i >= 0; i--)
    if(PView::list[i]->getData()->isRemote()) delete PView::list[i];
  FlGui::instance()->updateViews(true);
  drawContext::global()->draw();
}

void remoteStop()
{
  GmshServer *server = remoteServer("stop");
  if(server) server->SendString(GmshSocket::GMSH_STOP, "Disconnect!");
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
  default: // CGNS, VIS, BREP, XAO, STEP, IGES, XMT and the others with no
           // options
    CreateOutputFile(name, format);
    return 1;
  }
}

void fileExport()
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

// the options written to a file, as said
static void saveOptions(const std::string &fileName, int level, int diff,
                        int help)
{
  Msg::StatusBar(true, "Writing '%s'...", fileName.c_str());
  PrintOptions(0, level, diff, help, fileName.c_str());
  Msg::StatusBar(true, "Done writing '%s'", fileName.c_str());
}

void saveModelOptions()
{ saveOptions(GModel::current()->getFileName() + ".opt", GMSH_FULLRC, 0, 0); }

void saveDefaultOptions()
{
  saveOptions(CTX::instance()->homeDir + CTX::instance()->optionsFileName,
              GMSH_OPTIONSRC, 1, 1);
}

void fileRename()
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
    if(onelabUtils::haveSolverToRun()) onelabCheck();
    drawContext::global()->draw();
  }
}

void fileDelete()
{
  if(fl_choice("Do you really want to delete file '%s'?", "Cancel", "Delete",
               nullptr, GModel::current()->getFileName().c_str())) {
    UnlinkFile(GModel::current()->getFileName());
    Msg::Info("Deleted `%s'", GModel::current()->getFileName().c_str());
    fileClear();
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

void fileQuit()
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
    // also save the visibility, as FlGui::run() does with its option file
    visibility_save(fileName);
  }

  if(FlGui::instance()->quitShouldExit()) { Msg::Exit(0); }
  else {
    // once the event that asked for it is over: the widget it came through (a
    // menu bar, a button) goes with the windows, while its code still runs
    Fl::add_timeout(0., destroyGui);
  }
}

void fileWatch()
{
  CTX::instance()->watchFilePattern = patternChooser();
  mergeWatchedFiles();
}

void mergeWatchedFiles()
{
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

void helpOnline()
{
  if(std::string(GMSH_EXTRA_VERSION) == "")
    fl_open_uri("https://gmsh.info/doc/texinfo/gmsh.html");
  else
    fl_open_uri("https://gmsh.info/dev/doc/texinfo/gmsh.html");
}

void helpKeys()
{
  centerWindow(FlGui::instance()->help->basic);
  FlGui::instance()->help->basic->show();
}

void helpAbout()
{
  centerWindow(FlGui::instance()->help->about);
  FlGui::instance()->help->about->show();
}

// the window of the current options and the workspace
void helpCurrentOptions()
{
  help_options_cb(nullptr, nullptr);
  centerWindow(FlGui::instance()->help->options);
  FlGui::instance()->help->options->show();
}

void editScript() { editFile(GModel::current()->getFileName()); }

void reloadProject()
{
  if(modelBusy()) return;
  if(solverBusy()) return;

  std::string fileName = GModel::current()->getFileName();
  ClearProject();
  GModel::current()->setFileName(fileName);
  onelabReset(); // will call OpenProject
  drawContext::global()->draw();
}

void reloadScript()
{
  if(onelabUtils::haveSolverToRun()) {
    onelabCheck(true);
  }
  else {
    onelabReload();
    OpenProject(GModel::current()->getFileName());
  }
  drawContext::global()->draw();
}

void saveMesh()
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
