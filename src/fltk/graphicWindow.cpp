// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include "GmshDefines.h"
#include "GmshVersion.h"
#if !defined(HAVE_NO_STDINT_H)
#include <stdint.h>
#elif defined(HAVE_NO_INTPTR_T)
typedef unsigned long intptr_t;
#endif
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <FL/Fl_Box.H>
#include <FL/fl_ask.H>
#include <FL/filename.H>
#include <FL/Fl_Tree.H>
#include "FlGui.h"
#include "mainWindow.h"
#include "paletteWindow.h"
#include "graphicWindow.h"
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
#include "openglWindow.h"
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
#include "findLinks.h"
#include "scriptStringInterface.h"
#include "CommandLine.h"
#include "Options.h"
#include "Context.h"
#include "StringUtils.h"
#include "OS.h"
#include "onelabUtils.h"

#if defined(HAVE_MESH)
#include "gmshCrossFields.h"
#endif

#if defined(HAVE_3M)
#include "3M.h"
#endif

#if defined(HAVE_TOUCHBAR)
#include "touchBar.h"
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
  "Mesh - Plot3D Structured Mesh\t*.p3d\n"
  "Mesh - STL Surface\t*.stl\n"
  "Mesh - VTK\t*.vtk\n"
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
  std::string str((const char *)data);
  int n = PView::list.size();
  OpenProject(str);
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
  if(CTX::instance()->lock || FlGui::instance()->onelab->isBusy()) {
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
      FlGui::instance()->updateViews(true, true);
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

static int _save_msh(const char *name) { return mshFileDialog(name); }
static int _save_mesh_stat(const char *name)
{
  return meshStatFileDialog(name);
}
static int _save_options(const char *name) { return optionsFileDialog(name); }
static int _save_geo(const char *name) { return geoFileDialog(name); }
static int _save_brep(const char *name)
{
  CreateOutputFile(name, FORMAT_BREP);
  return 1;
}
static int _save_xao(const char *name)
{
  CreateOutputFile(name, FORMAT_XAO);
  return 1;
}
static int _save_step(const char *name)
{
  CreateOutputFile(name, FORMAT_STEP);
  return 1;
}
static int _save_iges(const char *name)
{
  CreateOutputFile(name, FORMAT_IGES);
  return 1;
}
static int _save_xmt(const char *name)
{
  CreateOutputFile(name, FORMAT_XMT);
  return 1;
}
static int _save_cgns(const char *name) { return cgnsFileDialog(name); }
static int _save_unv(const char *name)
{
  return unvinpFileDialog(name, "UNV Options", FORMAT_UNV);
}
static int _save_vtk(const char *name)
{
  return genericMeshFileDialog(name, "VTK Options", FORMAT_VTK, true, false);
}
static int _save_tochnog(const char *name)
{
  return genericMeshFileDialog(name, "Tochnog Options", FORMAT_TOCHNOG, true,
                               false);
}
static int _save_diff(const char *name)
{
  return genericMeshFileDialog(name, "Diffpack Options", FORMAT_DIFF, true,
                               false);
}
static int _save_inp(const char *name)
{
  return unvinpFileDialog(name, "Abaqus INP Options", FORMAT_INP);
}
static int _save_key(const char *name)
{
  return keyFileDialog(name, "LSDYNA KEY Options", FORMAT_KEY);
}
static int _save_rad(const char *name)
{
  return radFileDialog(name, "RADIOSS Block Options", FORMAT_RAD);
}
static int _save_celum(const char *name)
{
  return genericMeshFileDialog(name, "CELUM Options", FORMAT_CELUM, false,
                               false);
}
static int _save_su2(const char *name)
{
  return genericMeshFileDialog(name, "SU2 Options", FORMAT_SU2, false, false);
}
static int _save_med(const char *name)
{
  return genericMeshFileDialog(name, "MED Options", FORMAT_MED, false, false);
}
static int _save_mesh(const char *name)
{
  return genericMeshFileDialog(name, "MESH Options", FORMAT_MESH, false, true);
}
static int _save_off(const char *name)
{
  return genericMeshFileDialog(name, "OFF Options", FORMAT_OFF, false, false);
}
static int _save_mail(const char *name)
{
  return genericMeshFileDialog(name, "MAIL Options", FORMAT_MAIL, false, false);
}
static int _save_matlab(const char *name)
{
  return genericMeshFileDialog(name, "MATLAB Options", FORMAT_MATLAB, false,
                               false);
}
static int _save_bdf(const char *name) { return bdfFileDialog(name); }
static int _save_p3d(const char *name)
{
  return genericMeshFileDialog(name, "P3D Options", FORMAT_P3D, false, false);
}
static int _save_ir3(const char *name)
{
  return genericMeshFileDialog(name, "Iridium Options", FORMAT_IR3, false,
                               true);
}
static int _save_stl(const char *name) { return stlFileDialog(name); }
static int _save_vrml(const char *name)
{
  return genericMeshFileDialog(name, "VRML Options", FORMAT_VRML, false, false);
}
static int _save_ply2(const char *name)
{
  return genericMeshFileDialog(name, "PLY2 Options", FORMAT_PLY2, false, false);
}
static int _save_neu(const char *name)
{
  return genericMeshFileDialog(name, "NEU Options", FORMAT_NEU, false, false);
}
static int _save_eps(const char *name)
{
  return gl2psFileDialog(name, "EPS Options", FORMAT_EPS);
}
static int _save_gif(const char *name) { return gifFileDialog(name); }
static int _save_jpeg(const char *name)
{
  return genericBitmapFileDialog(name, "JPEG Options", FORMAT_JPEG);
}
static int _save_mpeg(const char *name) { return mpegFileDialog(name); }
static int _save_tex(const char *name) { return latexFileDialog(name); }
static int _save_pdf(const char *name)
{
  return gl2psFileDialog(name, "PDF Options", FORMAT_PDF);
}
static int _save_png(const char *name)
{
  return genericBitmapFileDialog(name, "PNG Options", FORMAT_PNG);
}
static int _save_pgf(const char *name)
{
  return pgfBitmapFileDialog(name, "PGF Options", FORMAT_PGF);
}
static int _save_ps(const char *name)
{
  return gl2psFileDialog(name, "PS Options", FORMAT_PS);
}
static int _save_ppm(const char *name)
{
  return genericBitmapFileDialog(name, "PPM Options", FORMAT_PPM);
}
static int _save_svg(const char *name)
{
  return gl2psFileDialog(name, "SVG Options", FORMAT_SVG);
}
static int _save_tikz(const char *name)
{
  return gl2psFileDialog(name, "TIKZ Options", FORMAT_TIKZ);
}
static int _save_yuv(const char *name)
{
  return genericBitmapFileDialog(name, "YUV Options", FORMAT_YUV);
}
static int _save_view_pos(const char *name) { return posFileDialog(name); }
static int _save_view_adapt_pvtu(const char *name)
{
  return pvtuAdaptFileDialog(name);
}
static int _save_view_med(const char *name)
{
  return genericViewFileDialog(name, "MED Options", 6);
}
static int _save_view_txt(const char *name)
{
  return genericViewFileDialog(name, "TXT Options", 4);
}
static int _save_mesh_x3d(const char *name)
{
  return genericMeshFileDialog(name, "X3D Options", FORMAT_X3D, false, false);
}
static int _save_view_x3d(const char *name)
{
  return x3dViewFileDialog(name, "X3D Options", 7);
}
static int _save_x3d(const char *name)
{
  if(PView::list.empty())
    return _save_mesh_x3d(name);
  else
    return _save_view_x3d(name);
}

static int _save_auto(const char *name)
{
  switch(GuessFileFormatFromFileName(name)) {
  case FORMAT_MSH: return _save_msh(name);
  case FORMAT_POS: return _save_view_pos(name);
  case FORMAT_X3D: return _save_x3d(name);
  case FORMAT_PVTU: return _save_view_adapt_pvtu(name);
  case FORMAT_TXT: return _save_view_txt(name);
  case FORMAT_OPT: return _save_options(name);
  case FORMAT_GEO: return _save_geo(name);
  case FORMAT_BREP: return _save_brep(name);
  case FORMAT_XAO: return _save_xao(name);
  case FORMAT_STEP: return _save_step(name);
  case FORMAT_IGES: return _save_iges(name);
  case FORMAT_CGNS: return _save_cgns(name);
  case FORMAT_UNV: return _save_unv(name);
  case FORMAT_VTK: return _save_vtk(name);
  case FORMAT_TOCHNOG: return _save_tochnog(name);
  case FORMAT_MED: return _save_med(name);
  case FORMAT_RMED: return _save_view_med(name);
  case FORMAT_MESH: return _save_mesh(name);
  case FORMAT_OFF: return _save_off(name);
  case FORMAT_MAIL: return _save_mail(name);
  case FORMAT_MATLAB: return _save_matlab(name);
  case FORMAT_BDF: return _save_bdf(name);
  case FORMAT_DIFF: return _save_diff(name);
  case FORMAT_INP: return _save_inp(name);
  case FORMAT_KEY: return _save_key(name);
  case FORMAT_RAD: return _save_rad(name);
  case FORMAT_CELUM: return _save_celum(name);
  case FORMAT_SU2: return _save_su2(name);
  case FORMAT_P3D: return _save_p3d(name);
  case FORMAT_IR3: return _save_ir3(name);
  case FORMAT_STL: return _save_stl(name);
  case FORMAT_VRML: return _save_vrml(name);
  case FORMAT_PLY2: return _save_ply2(name);
  case FORMAT_NEU: return _save_neu(name);
  case FORMAT_EPS: return _save_eps(name);
  case FORMAT_GIF: return _save_gif(name);
  case FORMAT_JPEG: return _save_jpeg(name);
  case FORMAT_MPEG: return _save_mpeg(name);
  case FORMAT_TEX: return _save_tex(name);
  case FORMAT_PDF: return _save_pdf(name);
  case FORMAT_PNG: return _save_png(name);
  case FORMAT_PGF: return _save_pgf(name);
  case FORMAT_PS: return _save_ps(name);
  case FORMAT_PPM: return _save_ppm(name);
  case FORMAT_SVG: return _save_svg(name);
  case FORMAT_TIKZ: return _save_tikz(name);
  case FORMAT_YUV: return _save_yuv(name);
  case FORMAT_XMT: return _save_xmt(name);
  default: CreateOutputFile(name, FORMAT_AUTO); return 1;
  }
}

typedef struct {
  const char *pat;
  int (*func)(const char *name);
} patXfunc;

static void file_export_cb(Fl_Widget *w, void *data)
{
  static patXfunc formats[] = {
    {"Guess From Extension\t*.*", _save_auto},
    {"Geometry - Gmsh Options\t*.opt", _save_options},
    {"Geometry - Gmsh Unrolled GEO\t*.geo_unrolled", _save_geo},
#if defined(HAVE_OCC)
    {"Geometry - OpenCASCADE BRep\t*.brep", _save_brep},
    {"Geometry - OpenCASCADE XAO\t*.xao", _save_xao},
#endif
#if defined(HAVE_PARASOLID)
    {"Geometry - Parasolid XMT\t*.xmt_txt", _save_xmt},
#endif
#if defined(HAVE_OCC) || defined(HAVE_PARASOLID_STEP)
    {"Geometry - STEP\t*.step", _save_step},
#endif
#if defined(HAVE_OCC)
    {"Geometry - IGES\t*.iges", _save_iges},
#endif
    {"Mesh - Gmsh MSH\t*.msh", _save_msh},
    {"Mesh - Abaqus INP\t*.inp", _save_inp},
    {"Mesh - LSDYNA KEY\t*.key", _save_key},
    {"Mesh - RADIOSS BLOCK\t*_0000.rad", _save_rad},
    {"Mesh - CELUM\t*.celum", _save_celum},
#if defined(HAVE_LIBCGNS)
    {"Mesh - CGNS (Experimental)\t*.cgns", _save_cgns},
#endif
    {"Mesh - Diffpack 3D\t*.diff", _save_diff},
    {"Mesh - I-deas Universal\t*.unv", _save_unv},
    {"Mesh - Iridum\t*.ir3", _save_ir3},
#if defined(HAVE_MED)
    {"Mesh - MED\t*.med", _save_med},
#endif
    {"Mesh - INRIA Medit\t*.mesh", _save_mesh},
    {"Mesh - CEA Triangulation\t*.mail", _save_mail},
    {"Mesh - Matlab\t*.m", _save_matlab},
    {"Mesh - Nastran Bulk Data File\t*.bdf", _save_bdf},
    {"Mesh - Object File Format\t*.off", _save_off},
    {"Mesh - Plot3D Structured Mesh\t*.p3d", _save_p3d},
    {"Mesh - STL Surface\t*.stl", _save_stl},
    {"Mesh - VRML Surface\t*.wrl", _save_vrml},
    {"Mesh - VTK\t*.vtk", _save_vtk},
    {"Mesh - Tochnog\t*.dat", _save_tochnog},
    {"Mesh - PLY2 Surface\t*.ply2", _save_ply2},
    {"Mesh - SU2\t*.su2", _save_su2},
    {"Mesh - GAMBIT Neutral File\t*.neu", _save_neu},
    {"Mesh - X3D\t*.x3d", _save_mesh_x3d},
    {"Post-processing - Gmsh POS\t*.pos", _save_view_pos},
    {"Post-processing - X3D\t*.x3d", _save_view_x3d},
#if defined(HAVE_MED)
    {"Post-processing - MED\t*.rmed", _save_view_med},
#endif
    {"Post-processing - Generic TXT\t*.txt", _save_view_txt},
    {"Post-processing - Mesh Statistics\t*.pos", _save_mesh_stat},
    {"Post-processing - Adapted data\t*.pvtu", _save_view_adapt_pvtu},
    {"Image - Encapsulated PostScript\t*.eps", _save_eps},
    {"Image - GIF\t*.gif", _save_gif},
#if defined(HAVE_LIBJPEG)
    {"Image - JPEG\t*.jpg", _save_jpeg},
#endif
    {"Image - LaTeX\t*.tex", _save_tex},
    {"Image - PDF\t*.pdf", _save_pdf},
#if defined(HAVE_LIBPNG)
    {"Image - PNG\t*.png", _save_png},
    {"Image - PGF\t*.pgf", _save_pgf},
#endif
    {"Image - PostScript\t*.ps", _save_ps},
    {"Image - PPM\t*.ppm", _save_ppm},
    {"Image - SVG\t*.svg", _save_svg},
    {"Image - TIKZ\t*.tikz", _save_tikz},
    {"Image - YUV\t*.yuv", _save_yuv},
#if defined(HAVE_MPEG_ENCODE)
    {"Movie - MPEG\t*.mpg", _save_mpeg},
#endif
  };
  int nbformats = sizeof(formats) / sizeof(formats[0]);
  static char *pat = nullptr;
  if(!pat) {
    pat = new char[nbformats * 256];
    strcpy(pat, formats[0].pat);
    for(int i = 1; i < nbformats; i++) {
      strcat(pat, "\n");
      strcat(pat, formats[i].pat);
    }
  }

test:
  if(fileChooser(FILE_CHOOSER_CREATE, "Export", pat)) {
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
    if(i >= 0 && i < nbformats) {
      if(!formats[i].func(name.c_str())) goto test;
    }
    else { // handle any additional automatic fltk filter
      if(!_save_auto(name.c_str())) goto test;
    }
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

void file_quit_cb(Fl_Widget *w, void *data)
{
  // save persistent info to disk
  if(CTX::instance()->sessionSave)
    PrintOptions(
      0, GMSH_SESSIONRC, 0, 0,
      (CTX::instance()->homeDir + CTX::instance()->sessionFileName).c_str());
  if(CTX::instance()->optionsSave == 1)
    PrintOptions(
      0, GMSH_OPTIONSRC, 1, 0,
      (CTX::instance()->homeDir + CTX::instance()->optionsFileName).c_str());
  else if(CTX::instance()->optionsSave == 2) {
    std::string fileName = GModel::current()->getFileName() + ".opt";
    PrintOptions(0, GMSH_FULLRC, 1, 0, fileName.c_str());
  }

  if(FlGui::instance()->quitShouldExit()) { Msg::Exit(0); }
  else { FlGui::destroy(); }
}

void file_watch_cb(Fl_Widget *w, void *data)
{
  if(w) CTX::instance()->watchFilePattern = patternChooser();

  if(CTX::instance()->watchFilePattern.empty()) return;

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
  FlGui::instance()->help->basic->show();
}

void help_about_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->help->about->show();
}

static void geometry_edit_cb(Fl_Widget *w, void *data)
{
  std::string prog = FixWindowsPath(CTX::instance()->editor);
  std::string file = FixWindowsPath(GModel::current()->getFileName());
  SystemCall(ReplaceSubString("%s", file, prog));
}

void onelab_reload_cb(Fl_Widget *w, void *data)
{
  if(CTX::instance()->lock || FlGui::instance()->onelab->isBusy()) {
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
  else
    OpenProject(GModel::current()->getFileName());
  drawContext::global()->draw();
}

void geometry_remove_last_command_cb(Fl_Widget *w, void *data)
{
  scriptRemoveLastCommand(GModel::current()->getFileName());
  drawContext::global()->draw();
}

static void add_new_point_based_entity(const std::string &what, int pane)
{
  opt_general_axes(0, GMSH_SET | GMSH_GUI, 3);
  opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  drawContext::global()->draw();

  FlGui::instance()->elementaryContext->show(pane);

  while(1) {
    if(!FlGui::available()) return;

    for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++)
      for(std::size_t j = 0; j < FlGui::instance()->graph[i]->gl.size(); j++)
        FlGui::instance()->graph[i]->gl[j]->addPointMode = 1;
    std::string name = what;
    std::transform(name.begin(), name.end(), name.begin(), ::tolower);
    Msg::StatusGl(
      "Move mouse and/or enter coordinates\n"
      "[Press 'Shift' to hold position, 'e' to add %s or 'q' to abort]",
      name.c_str());
    char ib = FlGui::instance()->selectEntity(ENT_NONE);
    if(!FlGui::available()) return;
    if(ib == 'e') {
      switch(pane) {
      case 1:
        scriptAddPoint(GModel::current()->getFileName(),
                       FlGui::instance()->elementaryContext->input[4]->value(),
                       FlGui::instance()->elementaryContext->input[5]->value(),
                       FlGui::instance()->elementaryContext->input[6]->value(),
                       FlGui::instance()->elementaryContext->input[7]->value());
        break;
      case 2:
        scriptAddCircle(
          GModel::current()->getFileName(),
          FlGui::instance()->elementaryContext->input[8]->value(),
          FlGui::instance()->elementaryContext->input[9]->value(),
          FlGui::instance()->elementaryContext->input[10]->value(),
          FlGui::instance()->elementaryContext->input[11]->value(),
          FlGui::instance()->elementaryContext->input[12]->value(),
          FlGui::instance()->elementaryContext->input[13]->value());
        break;
      case 3:
        scriptAddEllipse(
          GModel::current()->getFileName(),
          FlGui::instance()->elementaryContext->input[14]->value(),
          FlGui::instance()->elementaryContext->input[15]->value(),
          FlGui::instance()->elementaryContext->input[16]->value(),
          FlGui::instance()->elementaryContext->input[17]->value(),
          FlGui::instance()->elementaryContext->input[18]->value(),
          FlGui::instance()->elementaryContext->input[19]->value(),
          FlGui::instance()->elementaryContext->input[20]->value());
        break;
      case 4:
        scriptAddDisk(GModel::current()->getFileName(),
                      FlGui::instance()->elementaryContext->input[21]->value(),
                      FlGui::instance()->elementaryContext->input[22]->value(),
                      FlGui::instance()->elementaryContext->input[23]->value(),
                      FlGui::instance()->elementaryContext->input[24]->value(),
                      FlGui::instance()->elementaryContext->input[25]->value());
        break;
      case 5:
        scriptAddRectangle(
          GModel::current()->getFileName(),
          FlGui::instance()->elementaryContext->input[26]->value(),
          FlGui::instance()->elementaryContext->input[27]->value(),
          FlGui::instance()->elementaryContext->input[28]->value(),
          FlGui::instance()->elementaryContext->input[29]->value(),
          FlGui::instance()->elementaryContext->input[30]->value(),
          FlGui::instance()->elementaryContext->input[31]->value());
        break;
      case 6:
        scriptAddSphere(
          GModel::current()->getFileName(),
          FlGui::instance()->elementaryContext->input[32]->value(),
          FlGui::instance()->elementaryContext->input[33]->value(),
          FlGui::instance()->elementaryContext->input[34]->value(),
          FlGui::instance()->elementaryContext->input[35]->value(),
          FlGui::instance()->elementaryContext->input[36]->value(),
          FlGui::instance()->elementaryContext->input[37]->value(),
          FlGui::instance()->elementaryContext->input[38]->value());
        break;
      case 7:
        scriptAddCylinder(
          GModel::current()->getFileName(),
          FlGui::instance()->elementaryContext->input[39]->value(),
          FlGui::instance()->elementaryContext->input[40]->value(),
          FlGui::instance()->elementaryContext->input[41]->value(),
          FlGui::instance()->elementaryContext->input[42]->value(),
          FlGui::instance()->elementaryContext->input[43]->value(),
          FlGui::instance()->elementaryContext->input[44]->value(),
          FlGui::instance()->elementaryContext->input[45]->value(),
          FlGui::instance()->elementaryContext->input[46]->value());
        break;
      case 8:
        scriptAddBox(GModel::current()->getFileName(),
                     FlGui::instance()->elementaryContext->input[47]->value(),
                     FlGui::instance()->elementaryContext->input[48]->value(),
                     FlGui::instance()->elementaryContext->input[49]->value(),
                     FlGui::instance()->elementaryContext->input[50]->value(),
                     FlGui::instance()->elementaryContext->input[51]->value(),
                     FlGui::instance()->elementaryContext->input[52]->value());
        break;
      case 9:
        scriptAddTorus(
          GModel::current()->getFileName(),
          FlGui::instance()->elementaryContext->input[53]->value(),
          FlGui::instance()->elementaryContext->input[54]->value(),
          FlGui::instance()->elementaryContext->input[55]->value(),
          FlGui::instance()->elementaryContext->input[56]->value(),
          FlGui::instance()->elementaryContext->input[57]->value(),
          FlGui::instance()->elementaryContext->input[58]->value());
        break;
      case 10:
        scriptAddCone(GModel::current()->getFileName(),
                      FlGui::instance()->elementaryContext->input[59]->value(),
                      FlGui::instance()->elementaryContext->input[60]->value(),
                      FlGui::instance()->elementaryContext->input[61]->value(),
                      FlGui::instance()->elementaryContext->input[62]->value(),
                      FlGui::instance()->elementaryContext->input[63]->value(),
                      FlGui::instance()->elementaryContext->input[64]->value(),
                      FlGui::instance()->elementaryContext->input[65]->value(),
                      FlGui::instance()->elementaryContext->input[66]->value(),
                      FlGui::instance()->elementaryContext->input[67]->value());
        break;
      case 11:
        scriptAddWedge(
          GModel::current()->getFileName(),
          FlGui::instance()->elementaryContext->input[68]->value(),
          FlGui::instance()->elementaryContext->input[69]->value(),
          FlGui::instance()->elementaryContext->input[70]->value(),
          FlGui::instance()->elementaryContext->input[71]->value(),
          FlGui::instance()->elementaryContext->input[72]->value(),
          FlGui::instance()->elementaryContext->input[73]->value(),
          FlGui::instance()->elementaryContext->input[74]->value());
        break;
      }
      FlGui::instance()->resetVisibility();
      drawContext::global()->draw();
    }
    if(ib == 'q') {
      for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++)
        for(std::size_t j = 0; j < FlGui::instance()->graph[i]->gl.size(); j++)
          FlGui::instance()->graph[i]->gl[j]->addPointMode = 0;
      break;
    }
  }

  FlGui::instance()->elementaryContext->hide();
  drawContext::setDrawGeomTransientFunction(nullptr);

  // at the end, not during creation to avoid having things jumping around
  SetBoundingBox();
  Msg::StatusGl("");
}

static void add_new_multiline(const std::string &type)
{
  opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  opt_geometry_curves(0, GMSH_SET | GMSH_GUI, 1);
  drawContext::global()->draw();

  std::vector<int> p;
  while(1) {
    if(!FlGui::available()) return;

    if(p.empty())
      Msg::StatusGl("Select control points\n"
                    "[Press 'e' to end selection or 'q' to abort]");
    else
      Msg::StatusGl("Select control points\n"
                    "[Press 'e' to end selection, 'u' to undo last selection "
                    "or 'q' to abort]");
    char ib = FlGui::instance()->selectEntity(ENT_POINT);
    if(!FlGui::available()) return;
    if(ib == 'l') {
      for(std::size_t i = 0; i < FlGui::instance()->selectedVertices.size();
          i++) {
        FlGui::instance()->selectedVertices[i]->setSelection(1);
        p.push_back(FlGui::instance()->selectedVertices[i]->tag());
      }
      drawContext::global()->draw();
    }
    if(ib == 'r') {
      Msg::Warning(
        "Entity de-selection not supported yet during multi-line creation");
    }
    if(ib == 'e') {
      if(p.size() >= 2)
        scriptAddCurve(type, p, GModel::current()->getFileName());
      FlGui::instance()->resetVisibility();
      GModel::current()->setSelection(0);
      drawContext::global()->draw();
      p.clear();
    }
    if(ib == 'u') {
      if(p.size()) {
        GVertex *gv = GModel::current()->getVertexByTag(p.back());
        if(gv) gv->setSelection(0);
        drawContext::global()->draw();
        p.pop_back();
      }
    }
    if(ib == 'q') {
      GModel::current()->setSelection(0);
      drawContext::global()->draw();
      break;
    }
  }

  Msg::StatusGl("");
}

static void add_new_line()
{
  opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  opt_geometry_curves(0, GMSH_SET | GMSH_GUI, 1);
  drawContext::global()->draw();

  std::vector<int> p;
  while(1) {
    if(!FlGui::available()) return;

    if(p.empty())
      Msg::StatusGl("Select start point\n"
                    "[Press 'q' to abort]");
    if(p.size() == 1)
      Msg::StatusGl("Select end point\n"
                    "[Press 'u' to undo last selection or 'q' to abort]");
    char ib = FlGui::instance()->selectEntity(ENT_POINT);
    if(!FlGui::available()) return;
    if(ib == 'l') {
      FlGui::instance()->selectedVertices[0]->setSelection(1);
      drawContext::global()->draw();
      p.push_back(FlGui::instance()->selectedVertices[0]->tag());
    }
    if(ib == 'r') {
      Msg::Warning(
        "Entity de-selection not supported yet during curve creation");
    }
    if(ib == 'u') {
      if(p.size()) {
        GVertex *gv = GModel::current()->getVertexByTag(p.back());
        if(gv) gv->setSelection(0);
        drawContext::global()->draw();
        p.pop_back();
      }
    }
    if(ib == 'q') {
      GModel::current()->setSelection(0);
      drawContext::global()->draw();
      break;
    }
    if(p.size() == 2) {
      scriptAddCurve("Line", p, GModel::current()->getFileName());
      FlGui::instance()->resetVisibility();
      GModel::current()->setSelection(0);
      drawContext::global()->draw();
      p.clear();
    }
  }

  Msg::StatusGl("");
}

static void add_new_circle_arc()
{
  opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  opt_geometry_curves(0, GMSH_SET | GMSH_GUI, 1);
  drawContext::global()->draw();

  std::vector<int> p;
  while(1) {
    if(!FlGui::available()) return;

    if(p.empty())
      Msg::StatusGl("Select start point\n"
                    "[Press 'q' to abort]");
    if(p.size() == 1)
      Msg::StatusGl("Select center point\n"
                    "[Press 'u' to undo last selection or 'q' to abort]");
    if(p.size() == 2)
      Msg::StatusGl("Select end point\n"
                    "[Press 'u' to undo last selection or 'q' to abort]");
    char ib = FlGui::instance()->selectEntity(ENT_POINT);
    if(!FlGui::available()) return;
    if(ib == 'l') {
      FlGui::instance()->selectedVertices[0]->setSelection(1);
      drawContext::global()->draw();
      p.push_back(FlGui::instance()->selectedVertices[0]->tag());
    }
    if(ib == 'r') {
      Msg::Warning(
        "Entity de-selection not supported yet during circle creation");
    }
    if(ib == 'u') {
      if(p.size()) {
        GVertex *gv = GModel::current()->getVertexByTag(p.back());
        if(gv) gv->setSelection(0);
        drawContext::global()->draw();
        p.pop_back();
      }
    }
    if(ib == 'q') {
      GModel::current()->setSelection(0);
      drawContext::global()->draw();
      break;
    }
    if(p.size() == 3) {
      // begin, center, end
      scriptAddCircleArc(p[0], p[1], p[2], GModel::current()->getFileName());
      FlGui::instance()->resetVisibility();
      GModel::current()->setSelection(0);
      drawContext::global()->draw();
      p.clear();
    }
  }

  Msg::StatusGl("");
}

static void add_new_ellipse_arc()
{
  opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  opt_geometry_curves(0, GMSH_SET | GMSH_GUI, 1);
  drawContext::global()->draw();

  std::vector<int> p;
  while(1) {
    if(!FlGui::available()) return;

    if(p.empty())
      Msg::StatusGl("Select start point\n"
                    "[Press 'q' to abort]");
    if(p.size() == 1)
      Msg::StatusGl("Select center point\n"
                    "[Press 'u' to undo last selection or 'q' to abort]");
    if(p.size() == 2)
      Msg::StatusGl("Select major axis point\n"
                    "[Press 'u' to undo last selection or 'q' to abort]");
    if(p.size() == 3)
      Msg::StatusGl("Select end point\n"
                    "[Press 'u' to undo last selection or 'q' to abort]");
    char ib = FlGui::instance()->selectEntity(ENT_POINT);
    if(!FlGui::available()) return;
    if(ib == 'l') {
      FlGui::instance()->selectedVertices[0]->setSelection(1);
      drawContext::global()->draw();
      p.push_back(FlGui::instance()->selectedVertices[0]->tag());
    }
    if(ib == 'r') {
      Msg::Warning(
        "Entity de-selection not supported yet during ellipse creation");
    }
    if(ib == 'u') {
      if(p.size()) {
        GVertex *gv = GModel::current()->getVertexByTag(p.back());
        if(gv) gv->setSelection(0);
        drawContext::global()->draw();
        p.pop_back();
      }
    }
    if(ib == 'q') {
      GModel::current()->setSelection(0);
      drawContext::global()->draw();
      break;
    }
    if(p.size() == 4) {
      scriptAddEllipseArc(p[0], p[1], p[2], p[3],
                          GModel::current()->getFileName());
      FlGui::instance()->resetVisibility();
      GModel::current()->setSelection(0);
      drawContext::global()->draw();
      p.clear();
    }
  }

  Msg::StatusGl("");
}

static int selectContour(int type, int num, List_T *List)
{
  int k = 0;

  switch(type) {
  case ENT_CURVE:
    k = allEdgesLinked(num, List);
    for(int i = 0; i < List_Nbr(List); i++) {
      int ip;
      List_Read(List, i, &ip);
      GEdge *ge = GModel::current()->getEdgeByTag(abs(ip));
      if(ge) ge->setSelection(1);
    }
    break;
  case ENT_SURFACE:
    k = allFacesLinked(num, List);
    for(int i = 0; i < List_Nbr(List); i++) {
      int ip;
      List_Read(List, i, &ip);
      GFace *gf = GModel::current()->getFaceByTag(abs(ip));
      if(gf) gf->setSelection(1);
    }
    break;
  }

  drawContext::global()->draw();
  return k;
}

static void add_new_surface_volume(int mode)
{
  List_T *List1 = List_Create(10, 10, sizeof(int));
  List_T *List2 = List_Create(10, 10, sizeof(int));
  int type;
  if(mode == 2) {
    type = ENT_SURFACE;
    opt_geometry_surfaces(0, GMSH_SET | GMSH_GUI, 1);
    opt_geometry_volumes(0, GMSH_SET | GMSH_GUI, 1);
  }
  else {
    type = ENT_CURVE;
    opt_geometry_curves(0, GMSH_SET | GMSH_GUI, 1);
    opt_geometry_surfaces(0, GMSH_SET | GMSH_GUI, 1);
  }
  drawContext::global()->draw();

  while(1) {
    if(!FlGui::available()) return;

    List_Reset(List1);
    List_Reset(List2);

    while(1) {
      if(!FlGui::available()) return;

      if(type == ENT_CURVE) {
        if(!List_Nbr(List1))
          Msg::StatusGl("Select surface boundary\n"
                        "[Press 'q' to abort]");
        else
          Msg::StatusGl("Select surface boundary\n"
                        "[Press 'u' to undo last selection or 'q' to abort]");
      }
      else {
        if(!List_Nbr(List1))
          Msg::StatusGl("Select volume boundary\n"
                        "[Press 'q' to abort]");
        else
          Msg::StatusGl("Select volume boundary\n"
                        "[Press 'u' to undo last selection or 'q' to abort]");
      }

      char ib = FlGui::instance()->selectEntity(type);
      if(!FlGui::available()) return;
      if(ib == 'q') {
        GModel::current()->setSelection(0);
        drawContext::global()->draw();
        goto stopall;
      }
      if(ib == 'u') {
        if(List_Nbr(List1) > 0) {
          int num;
          List_Read(List1, List_Nbr(List1) - 1, &num);
          if(type == ENT_CURVE) {
            GEdge *ge = GModel::current()->getEdgeByTag(abs(num));
            if(ge) ge->setSelection(0);
          }
          else {
            GFace *gf = GModel::current()->getFaceByTag(abs(num));
            if(gf) gf->setSelection(0);
          }
          List_Pop(List1);
          drawContext::global()->draw();
        }
      }
      if(ib == 'r') {
        Msg::Warning("Entity de-selection not supported yet during "
                     "surface/volume creation");
      }
      if(ib == 'l') {
        int num = (type == ENT_CURVE) ?
                    FlGui::instance()->selectedEdges[0]->tag() :
                    FlGui::instance()->selectedFaces[0]->tag();
        if(selectContour(type, num, List1)) {
          if(type == ENT_CURVE)
            scriptAddCurveLoop(List1, GModel::current()->getFileName(), &num);
          else
            scriptAddSurfaceLoop(List1, GModel::current()->getFileName(), &num);
          List_Reset(List1);
          List_Add(List2, &num);
          while(1) {
            if(!FlGui::available()) return;

            if(!List_Nbr(List1))
              Msg::StatusGl("Select hole boundaries (if none, press 'e')\n"
                            "[Press 'e' to end selection or 'q' to abort]");
            else
              Msg::StatusGl(
                "Select hole boundaries\n"
                "[Press 'e' to end selection, 'u' to undo last selection "
                "or 'q' to abort]");
            ib = FlGui::instance()->selectEntity(type);
            if(!FlGui::available()) return;
            if(ib == 'q') {
              GModel::current()->setSelection(0);
              drawContext::global()->draw();
              goto stopall;
            }
            if(ib == 'e') {
              GModel::current()->setSelection(0);
              drawContext::global()->draw();
              List_Reset(List1);
              break;
            }
            if(ib == 'u') {
              if(List_Nbr(List1) > 0) {
                int num;
                List_Read(List1, List_Nbr(List1) - 1, &num);
                if(type == ENT_CURVE) {
                  GEdge *ge = GModel::current()->getEdgeByTag(abs(num));
                  if(ge) ge->setSelection(0);
                }
                else {
                  GFace *gf = GModel::current()->getFaceByTag(abs(num));
                  if(gf) gf->setSelection(0);
                }
                List_Pop(List1);
                drawContext::global()->draw();
              }
            }
            if(ib == 'l') {
              int size = (type == ENT_CURVE) ?
                           FlGui::instance()->selectedEdges.size() :
                           FlGui::instance()->selectedFaces.size();
              for(int i = 0; i < size; i++) {
                int num = (type == ENT_CURVE) ?
                            FlGui::instance()->selectedEdges[i]->tag() :
                            FlGui::instance()->selectedFaces[i]->tag();
                if(selectContour(type, num, List1)) {
                  if(type == ENT_CURVE)
                    scriptAddCurveLoop(List1, GModel::current()->getFileName(),
                                       &num);
                  else
                    scriptAddSurfaceLoop(
                      List1, GModel::current()->getFileName(), &num);
                  List_Reset(List1);
                  List_Add(List2, &num);
                }
              }
            }
            if(ib == 'r') {
              Msg::Warning("Entity de-selection not supported yet during "
                           "surface/volume creation");
            }
          }
          List_Unique(List2, fcmp_absint);
          if(List_Nbr(List2)) {
            switch(mode) {
            case 0:
              scriptAddSurface("Plane Surface", List2,
                               GModel::current()->getFileName());
              break;
            case 1:
              scriptAddSurface("Surface", List2,
                               GModel::current()->getFileName());
              break;
            case 2:
              scriptAddVolume(List2, GModel::current()->getFileName());
              break;
            }
            FlGui::instance()->resetVisibility();
            GModel::current()->setSelection(0);
            drawContext::global()->draw();
            break;
          }
        } // if selectContour
      }
    }
  }

stopall:
  List_Delete(List1);
  List_Delete(List2);

  Msg::StatusGl("");
}

static void geometry_elementary_set_factory_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string str((const char *)data);
  scriptSetFactory(str, GModel::current()->getFileName());
  if(FlGui::available())
    Msg::StatusBar(false, "Setting %s factory", str.c_str());
}

static void geometry_elementary_add_new_cb(Fl_Widget *w, void *data)
{
  if(!data) return;

  std::string str((const char *)data);
  if(str == "Parameter")
    FlGui::instance()->elementaryContext->show(0);
  else if(str == "Point")
    add_new_point_based_entity(str, 1);
  else if(str == "Line")
    add_new_line();
  else if(str == "Spline")
    add_new_multiline(str);
  else if(str == "BSpline")
    add_new_multiline(str);
  else if(str == "Bezier")
    add_new_multiline(str);
  else if(str == "Circle arc")
    add_new_circle_arc();
  else if(str == "Circle")
    add_new_point_based_entity(str, 2);
  else if(str == "Ellipse arc")
    add_new_ellipse_arc();
  else if(str == "Ellipse")
    add_new_point_based_entity(str, 3);
  else if(str == "Disk")
    add_new_point_based_entity(str, 4);
  else if(str == "Rectangle")
    add_new_point_based_entity(str, 5);
  else if(str == "Sphere")
    add_new_point_based_entity(str, 6);
  else if(str == "Cylinder")
    add_new_point_based_entity(str, 7);
  else if(str == "Box")
    add_new_point_based_entity(str, 8);
  else if(str == "Torus")
    add_new_point_based_entity(str, 9);
  else if(str == "Cone")
    add_new_point_based_entity(str, 10);
  else if(str == "Wedge")
    add_new_point_based_entity(str, 11);
  else if(str == "Plane Surface")
    add_new_surface_volume(0);
  else if(str == "Surface")
    add_new_surface_volume(1);
  else if(str == "Volume")
    add_new_surface_volume(2);
  else
    Msg::Error("Unknown entity to create: %s", str.c_str());
}

static void action_point_line_surface_volume(int action,
                                             const std::string &onwhat = "")
{
  drawContext::global()->draw();

  std::string what(onwhat);
  if(what == "Point")
    opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  else if(what == "Curve")
    opt_geometry_curves(0, GMSH_SET | GMSH_GUI, 1);
  else if(what == "Surface")
    opt_geometry_surfaces(0, GMSH_SET | GMSH_GUI, 1);
  else if(what == "Volume")
    opt_geometry_volumes(0, GMSH_SET | GMSH_GUI, 1);

  std::vector<std::pair<int, int> > dimTags, dimTagsSaved;
  while(1) {
    if(!FlGui::available()) return;

    std::string str;
    int type;
    if(what == "Point") {
      str = "points";
      type = ENT_POINT;
    }
    else if(what == "Curve") {
      str = "curves";
      type = ENT_CURVE;
    }
    else if(what == "Surface") {
      str = "surfaces";
      type = ENT_SURFACE;
    }
    else if(what == "Volume") {
      str = "volumes";
      type = ENT_VOLUME;
    }
    else {
      switch(FlGui::instance()->transformContext->choice->value()) {
      case 1:
        str = "points";
        type = ENT_POINT;
        break;
      case 2:
        str = "curves";
        type = ENT_CURVE;
        break;
      case 3:
        str = "surfaces";
        type = ENT_SURFACE;
        break;
      case 4:
        str = "volumes";
        type = ENT_VOLUME;
        break;
      default:
        str = "entities";
        type = ENT_ALL;
        break;
      }
    }

    if(dimTags.empty())
      Msg::StatusGl("Select %s\n"
                    "[Press 'e' to end selection or 'q' to abort]",
                    str.c_str());
    else
      Msg::StatusGl("Select %s\n"
                    "[Press 'e' to end selection, 'u' to undo last selection "
                    "or 'q' to abort]",
                    str.c_str());

    char ib = FlGui::instance()->selectEntity(type);
    if(!FlGui::available()) return;
    if(ib == 'l') {
      for(std::size_t i = 0; i < FlGui::instance()->selectedVertices.size();
          i++) {
        FlGui::instance()->selectedVertices[i]->setSelection(1);
        std::pair<int, int> t(0, FlGui::instance()->selectedVertices[i]->tag());
        if(std::find(dimTags.begin(), dimTags.end(), t) == dimTags.end())
          dimTags.push_back(t);
      }
      for(std::size_t i = 0; i < FlGui::instance()->selectedEdges.size(); i++) {
        FlGui::instance()->selectedEdges[i]->setSelection(1);
        std::pair<int, int> t(1, FlGui::instance()->selectedEdges[i]->tag());
        if(std::find(dimTags.begin(), dimTags.end(), t) == dimTags.end())
          dimTags.push_back(t);
      }
      for(std::size_t i = 0; i < FlGui::instance()->selectedFaces.size(); i++) {
        FlGui::instance()->selectedFaces[i]->setSelection(1);
        std::pair<int, int> t(2, FlGui::instance()->selectedFaces[i]->tag());
        if(std::find(dimTags.begin(), dimTags.end(), t) == dimTags.end())
          dimTags.push_back(t);
      }
      for(std::size_t i = 0; i < FlGui::instance()->selectedRegions.size();
          i++) {
        FlGui::instance()->selectedRegions[i]->setSelection(1);
        std::pair<int, int> t(3, FlGui::instance()->selectedRegions[i]->tag());
        if(std::find(dimTags.begin(), dimTags.end(), t) == dimTags.end())
          dimTags.push_back(t);
      }
      drawContext::global()->draw();
    }
    if(ib == 'r') {
      for(std::size_t i = 0; i < FlGui::instance()->selectedVertices.size();
          i++) {
        std::pair<int, int> t(0, FlGui::instance()->selectedVertices[i]->tag());
        auto it = std::find(dimTags.begin(), dimTags.end(), t);
        if(it != dimTags.end()) {
          dimTags.erase(it);
          GEntity *ge = GModel::current()->getEntityByTag(t.first, t.second);
          if(ge) ge->setSelection(0);
        }
      }
      for(std::size_t i = 0; i < FlGui::instance()->selectedEdges.size(); i++) {
        std::pair<int, int> t(1, FlGui::instance()->selectedEdges[i]->tag());
        auto it = std::find(dimTags.begin(), dimTags.end(), t);
        if(it != dimTags.end()) {
          dimTags.erase(it);
          GEntity *ge = GModel::current()->getEntityByTag(t.first, t.second);
          if(ge) ge->setSelection(0);
        }
      }
      for(std::size_t i = 0; i < FlGui::instance()->selectedFaces.size(); i++) {
        std::pair<int, int> t(2, FlGui::instance()->selectedFaces[i]->tag());
        auto it = std::find(dimTags.begin(), dimTags.end(), t);
        if(it != dimTags.end()) {
          dimTags.erase(it);
          GEntity *ge = GModel::current()->getEntityByTag(t.first, t.second);
          if(ge) ge->setSelection(0);
        }
      }
      for(std::size_t i = 0; i < FlGui::instance()->selectedRegions.size();
          i++) {
        std::pair<int, int> t(3, FlGui::instance()->selectedRegions[i]->tag());
        auto it = std::find(dimTags.begin(), dimTags.end(), t);
        if(it != dimTags.end()) {
          dimTags.erase(it);
          GEntity *ge = GModel::current()->getEntityByTag(t.first, t.second);
          if(ge) ge->setSelection(0);
        }
      }
      drawContext::global()->draw();
    }
    if(ib == 'u') {
      if(dimTags.size()) {
        std::pair<int, int> t = dimTags.back();
        GEntity *ge = GModel::current()->getEntityByTag(t.first, t.second);
        if(ge) ge->setSelection(0);
        dimTags.pop_back();
        drawContext::global()->draw();
      }
    }
    if(ib == 'i') { Msg::Error("Inverting selection!"); }
    if(ib == 'e') {
      if(dimTags.size()) {
        switch(action) {
        case 0:
          scriptTranslate(
            GModel::current()->getFileName(), dimTags,
            FlGui::instance()->transformContext->input[0]->value(),
            FlGui::instance()->transformContext->input[1]->value(),
            FlGui::instance()->transformContext->input[2]->value(),
            FlGui::instance()->transformContext->butt[0]->value());
          break;
        case 1:
          scriptRotate(GModel::current()->getFileName(), dimTags,
                       FlGui::instance()->transformContext->input[6]->value(),
                       FlGui::instance()->transformContext->input[7]->value(),
                       FlGui::instance()->transformContext->input[8]->value(),
                       FlGui::instance()->transformContext->input[3]->value(),
                       FlGui::instance()->transformContext->input[4]->value(),
                       FlGui::instance()->transformContext->input[5]->value(),
                       FlGui::instance()->transformContext->input[9]->value(),
                       FlGui::instance()->transformContext->butt[1]->value());
          break;
        case 2:
          scriptDilate(GModel::current()->getFileName(), dimTags,
                       FlGui::instance()->transformContext->input[10]->value(),
                       FlGui::instance()->transformContext->input[11]->value(),
                       FlGui::instance()->transformContext->input[12]->value(),
                       FlGui::instance()->transformContext->input[13]->value(),
                       FlGui::instance()->transformContext->input[14]->value(),
                       FlGui::instance()->transformContext->input[15]->value(),
                       FlGui::instance()->transformContext->butt[2]->value());
          break;
        case 3:
          scriptMirror(GModel::current()->getFileName(), dimTags,
                       FlGui::instance()->transformContext->input[16]->value(),
                       FlGui::instance()->transformContext->input[17]->value(),
                       FlGui::instance()->transformContext->input[18]->value(),
                       FlGui::instance()->transformContext->input[19]->value(),
                       FlGui::instance()->transformContext->butt[3]->value());
          break;
        case 4:
          scriptExtrude(GModel::current()->getFileName(), dimTags,
                        FlGui::instance()->transformContext->input[0]->value(),
                        FlGui::instance()->transformContext->input[1]->value(),
                        FlGui::instance()->transformContext->input[2]->value(),
                        FlGui::instance()->transformContext->butt[7]->value(),
                        FlGui::instance()->transformContext->input[21]->value(),
                        FlGui::instance()->transformContext->butt[8]->value());
          break;
        case 5:
          scriptProtude(GModel::current()->getFileName(), dimTags,
                        FlGui::instance()->transformContext->input[6]->value(),
                        FlGui::instance()->transformContext->input[7]->value(),
                        FlGui::instance()->transformContext->input[8]->value(),
                        FlGui::instance()->transformContext->input[3]->value(),
                        FlGui::instance()->transformContext->input[4]->value(),
                        FlGui::instance()->transformContext->input[5]->value(),
                        FlGui::instance()->transformContext->input[9]->value(),
                        FlGui::instance()->transformContext->butt[9]->value(),
                        FlGui::instance()->transformContext->input[22]->value(),
                        FlGui::instance()->transformContext->butt[10]->value());
          break;
        case 6:
          scriptDeleteEntities(
            GModel::current()->getFileName(), dimTags,
            FlGui::instance()->transformContext->butt[6]->value());
          break;
        case 7:
        case 11: {
          std::vector<int> tags;
          int dim = 0;
          for(std::size_t i = 0; i < dimTags.size(); i++) {
            if((dimTags[i].first == 0 && what == "Point") ||
               (dimTags[i].first == 1 && what == "Curve") ||
               (dimTags[i].first == 2 && what == "Surface") ||
               (dimTags[i].first == 3 && what == "Volume")) {
              dim = dimTags[i].first;
              tags.push_back(dimTags[i].second);
            }
          }
          scriptAddRemovePhysicalGroup(
            GModel::current()->getFileName(), what, tags,
            FlGui::instance()->physicalContext->selectedName,
            FlGui::instance()->physicalContext->selectedTag,
            FlGui::instance()->physicalContext->append,
            FlGui::instance()->physicalContext->mode);
          if(!FlGui::available()) return;

          // ask clients to update using the new physical definition
          onelab_cb(nullptr, (void *)"check");

          // if onelab context parameters are defined for the physical group,
          // show the parameter definition window and abort the physical group
          // creation loop (otherwise events cannot be processed by outside
          // codes through the api, as we are stuck in the while(1) for the
          // physical creation mode)
          std::vector<std::string> param;
          onelab::server::instance()->getParameterNames(
            param, "ONELAB Context/" + what + " Template");
          if(tags.size() && param.size() && action == 7) {
            FlGui::instance()->getCurrentOpenglWindow()->quitSelection = 1;
            FlGui::instance()->getCurrentOpenglWindow()->selectionMode = false;
            GModel::current()->setSelection(0);
            FlGui::instance()->onelabContext->show(dim, tags[0]);
            ib = 'z';
          }
          else {
            FlGui::instance()->physicalContext->show(what, action == 7 ? false :
                                                                         true);
          }
        } break;
        case 8: {
          std::vector<int> tags;
          for(std::size_t i = 0; i < dimTags.size(); i++) {
            if(dimTags[i].first == 0 && what == "Point")
              tags.push_back(dimTags[i].second);
          }
          if(tags.size())
            scriptSetMeshSize(
              GModel::current()->getFileName(), tags,
              FlGui::instance()->meshContext->input[0]->value());
        } break;
        case 9: {
          std::vector<int> tags;
          for(std::size_t i = 0; i < dimTags.size(); i++) {
            if(dimTags[i].first == 2 && what == "Surface")
              tags.push_back(dimTags[i].second);
          }
          scriptRecombineSurface(GModel::current()->getFileName(), tags);
        } break;
        case 10: {
          std::vector<int> tags;
          for(std::size_t i = 0; i < dimTags.size(); i++) {
            if((dimTags[i].first == 1 && what == "Curve") ||
               (dimTags[i].first == 2 && what == "Surface") ||
               (dimTags[i].first == 3 && what == "Volume"))
              tags.push_back(dimTags[i].second);
          }
          scriptSetCompound(GModel::current()->getFileName(), what, tags);
        } break;
        case 12:
          if(dimTagsSaved.empty()) {
            dimTagsSaved = dimTags;
            dimTags.clear();
            what = "Curve";
            continue;
          }
          else {
            std::vector<int> l;
            for(std::size_t i = 0; i < dimTags.size(); i++) {
              if(dimTags[i].first == 1) l.push_back(dimTags[i].second);
            }
            scriptAddPipe(GModel::current()->getFileName(), dimTagsSaved, l);
            dimTagsSaved.clear();
          }
          break;
        default: Msg::Error("Unknown action on selected entities"); break;
        }
        dimTags.clear();
        FlGui::instance()->resetVisibility();
        if(ib == 'z') break; // done: onelab context now shown
        GModel::current()->setSelection(0);
        if(action <= 6 || action >= 12) SetBoundingBox();
        drawContext::global()->draw();
      }
    }
    if(ib == 'q') {
      GModel::current()->setSelection(0);
      drawContext::global()->draw();
      break;
    }
  }

  Msg::StatusGl("");
}

static void geometry_elementary_translate_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->transformContext->show(0);
  action_point_line_surface_volume(0);
  if(!FlGui::available()) return;
  FlGui::instance()->transformContext->hide();
}

static void geometry_elementary_rotate_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->transformContext->show(1);
  action_point_line_surface_volume(1);
  if(!FlGui::available()) return;
  FlGui::instance()->transformContext->hide();
}

static void geometry_elementary_scale_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->transformContext->show(2);
  action_point_line_surface_volume(2);
  if(!FlGui::available()) return;
  FlGui::instance()->transformContext->hide();
}

static void geometry_elementary_symmetry_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->transformContext->show(3);
  action_point_line_surface_volume(3);
  if(!FlGui::available()) return;
  FlGui::instance()->transformContext->hide();
}

static void geometry_elementary_extrude_translate_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->transformContext->show(0, true);
  action_point_line_surface_volume(4);
  if(!FlGui::available()) return;
  FlGui::instance()->transformContext->hide();
}

static void geometry_elementary_extrude_rotate_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->transformContext->show(1, true);
  action_point_line_surface_volume(5);
  if(!FlGui::available()) return;
  FlGui::instance()->transformContext->hide();
}

static void geometry_elementary_pipe_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->transformContext->show(-1, true);
  action_point_line_surface_volume(12);
  if(!FlGui::available()) return;
  FlGui::instance()->transformContext->hide();
}

static void geometry_elementary_delete_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->transformContext->show(6);
  action_point_line_surface_volume(6);
  if(!FlGui::available()) return;
  FlGui::instance()->transformContext->hide();
}

static void geometry_elementary_boolean_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  FlGui::instance()->transformContext->show(4);

  std::string mode((const char *)data);
  bool selectObject = true;
  std::vector<std::pair<int, int> > object, tool;

  while(1) {
    if(!FlGui::available()) return;

    if(object.empty())
      Msg::StatusGl("Select object\n"
                    "[Press 'e' to end selection or 'q' to abort]");
    else if(selectObject)
      Msg::StatusGl(
        "Select object\n"
        "[Press 'e' to end selection, 'u' to undo last selection or "
        "'q' to abort]");
    else if(tool.empty())
      Msg::StatusGl("Select tool\n"
                    "[Press 'e' to end selection or 'q' to abort]");
    else
      Msg::StatusGl(
        "Select tool\n"
        "[Press 'e' to end selection, 'u' to undo last selection or "
        "'q' to abort]");

    int type = ENT_ALL;
    switch(FlGui::instance()->transformContext->choice->value()) {
    case 1: type = ENT_POINT; break;
    case 2: type = ENT_CURVE; break;
    case 3: type = ENT_SURFACE; break;
    case 4: type = ENT_VOLUME; break;
    }

    char ib = FlGui::instance()->selectEntity(type);
    if(!FlGui::available()) return;
    if(ib == 'l') {
      for(std::size_t i = 0; i < FlGui::instance()->selectedVertices.size(); i++) {
        if(FlGui::instance()->selectedVertices[i]->getSelection() != 1) {
          FlGui::instance()->selectedVertices[i]->setSelection(1);
          std::pair<int, int> t(0, FlGui::instance()->selectedVertices[i]->tag());
          if(selectObject)
            object.push_back(t);
          else
            tool.push_back(t);
        }
      }
      for(std::size_t i = 0; i < FlGui::instance()->selectedEdges.size(); i++) {
        if(FlGui::instance()->selectedEdges[i]->getSelection() != 1) {
          FlGui::instance()->selectedEdges[i]->setSelection(1);
          std::pair<int, int> t(1, FlGui::instance()->selectedEdges[i]->tag());
          if(selectObject)
            object.push_back(t);
          else
            tool.push_back(t);
        }
      }
      for(std::size_t i = 0; i < FlGui::instance()->selectedFaces.size(); i++) {
        if(FlGui::instance()->selectedFaces[i]->getSelection() != 1) {
          FlGui::instance()->selectedFaces[i]->setSelection(1);
          std::pair<int, int> t(2, FlGui::instance()->selectedFaces[i]->tag());
          if(selectObject)
            object.push_back(t);
          else
            tool.push_back(t);
        }
      }
      for(std::size_t i = 0; i < FlGui::instance()->selectedRegions.size();
          i++) {
        if(FlGui::instance()->selectedRegions[i]->getSelection() != 1) {
          FlGui::instance()->selectedRegions[i]->setSelection(1);
          std::pair<int, int> t(3,
                                FlGui::instance()->selectedRegions[i]->tag());
          if(selectObject)
            object.push_back(t);
          else
            tool.push_back(t);
        }
      }
    }
    if(ib == 'r') {
      Msg::Warning(
        "Entity de-selection not supported yet during boolean operation");
    }
    if(ib == 'u') {
      if(selectObject && object.size()) {
        std::pair<int, int> t = object.back();
        GEntity *ge = GModel::current()->getEntityByTag(t.first, t.second);
        if(ge) ge->setSelection(0);
        object.pop_back();
      }
      else if(tool.size()) {
        std::pair<int, int> t = tool.back();
        GEntity *ge = GModel::current()->getEntityByTag(t.first, t.second);
        if(ge) ge->setSelection(0);
        tool.pop_back();
      }
    }
    if(ib == 'e') {
      if(selectObject) {
        if(object.empty())
          Msg::Error("At least one object must be selected");
        else
          selectObject = false;
      }
      else if(tool.empty() && mode != "BooleanFragments") {
        Msg::Error("At least one tool must be selected");
      }
      else {
        scriptBoolean(GModel::current()->getFileName(), mode, object, tool,
                      FlGui::instance()->transformContext->butt[4]->value(),
                      tool.size() ?
                        FlGui::instance()->transformContext->butt[5]->value() :
                        0);
        GModel::current()->setSelection(0);
        selectObject = true;
        object.clear();
        tool.clear();
      }
    }
    if(ib == 'q') {
      GModel::current()->setSelection(0);
      break;
    }
  }

  FlGui::instance()->transformContext->hide();
  drawContext::global()->draw();
  Msg::StatusGl("");
}

static void geometry_elementary_fillet_cb(Fl_Widget *w, void *data)
{
  opt_geometry_volumes(0, GMSH_SET | GMSH_GUI, 1);
  opt_geometry_curves(0, GMSH_SET | GMSH_GUI, 1);

  FlGui::instance()->transformContext->show(5, false, false);

  bool selectRegions = true;
  std::vector<int> regions, edges;

  while(1) {
    if(!FlGui::available()) return;

    if(regions.empty())
      Msg::StatusGl("Select volume\n"
                    "[Press 'e' to end selection or 'q' to abort]");
    else if(selectRegions)
      Msg::StatusGl(
        "Select volume\n"
        "[Press 'e' to end selection, 'u' to undo last selection or "
        "'q' to abort]");
    else if(edges.empty())
      Msg::StatusGl("Select curve\n"
                    "[Press 'e' to end selection or 'q' to abort]");
    else
      Msg::StatusGl(
        "Select curve\n"
        "[Press 'e' to end selection, 'u' to undo last selection or "
        "'q' to abort]");

    char ib =
      FlGui::instance()->selectEntity(selectRegions ? ENT_VOLUME : ENT_CURVE);
    if(!FlGui::available()) return;
    if(ib == 'l') {
      for(std::size_t i = 0; i < FlGui::instance()->selectedEdges.size(); i++) {
        if(FlGui::instance()->selectedEdges[i]->getSelection() != 1) {
          FlGui::instance()->selectedEdges[i]->setSelection(1);
          edges.push_back(FlGui::instance()->selectedEdges[i]->tag());
        }
      }
      for(std::size_t i = 0; i < FlGui::instance()->selectedRegions.size();
          i++) {
        if(FlGui::instance()->selectedRegions[i]->getSelection() != 1) {
          FlGui::instance()->selectedRegions[i]->setSelection(1);
          regions.push_back(FlGui::instance()->selectedRegions[i]->tag());
        }
      }
    }
    if(ib == 'r') {
      Msg::Warning(
        "Entity de-selection not supported yet during boolean operation");
    }
    if(ib == 'u') {
      if(selectRegions && regions.size()) {
        GRegion *ge = GModel::current()->getRegionByTag(regions.back());
        if(ge) ge->setSelection(0);
        regions.pop_back();
      }
      else if(edges.size()) {
        GEdge *ge = GModel::current()->getEdgeByTag(edges.back());
        if(ge) ge->setSelection(0);
        edges.pop_back();
      }
    }
    if(ib == 'e') {
      if(selectRegions) {
        if(regions.empty())
          Msg::Error("At least one volume must be selected");
        else
          selectRegions = false;
      }
      else if(edges.empty()) {
        Msg::Error("At least one curve must be selected");
      }
      else {
        scriptFillet(GModel::current()->getFileName(), regions, edges,
                     FlGui::instance()->transformContext->input[20]->value());
        GModel::current()->setSelection(0);
        selectRegions = true;
        regions.clear();
        edges.clear();
      }
    }
    if(ib == 'q') {
      GModel::current()->setSelection(0);
      break;
    }
  }

  FlGui::instance()->transformContext->hide();
  drawContext::global()->draw();
  Msg::StatusGl("");
}

static void geometry_elementary_split_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  opt_geometry_curves(0, GMSH_SET | GMSH_GUI, 1);
  drawContext::global()->draw();
  Msg::StatusGl("Select curve to split\n"
                "[Press 'q' to abort]");
  GEdge *edge_to_split = nullptr;
  while(1) {
    if(!FlGui::available()) return;

    char ib = FlGui::instance()->selectEntity(ENT_CURVE);
    if(!FlGui::available()) return;
    if(ib == 'q') { break; }
    if(!FlGui::instance()->selectedEdges.empty()) {
      edge_to_split = FlGui::instance()->selectedEdges[0];
      edge_to_split->setSelection(1);
      break;
    }
  }
  Msg::StatusGl("");
  if(FlGui::instance()->selectedEdges.empty()) return;
  List_T *List1 = List_Create(5, 5, sizeof(int));
  Msg::StatusGl("Select break points\n"
                "[Press 'e' to end selection or 'q' to abort]");
  opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  drawContext::global()->draw();
  while(1) {
    if(!FlGui::available()) return;

    char ib = FlGui::instance()->selectEntity(ENT_POINT);
    if(!FlGui::available()) return;
    if(ib == 'q') { break; }
    if(ib == 'e' && edge_to_split) {
      scriptSplitCurve(edge_to_split->tag(), List1,
                       GModel::current()->getFileName());
      break;
    }
    for(std::size_t i = 0; i < FlGui::instance()->selectedVertices.size();
        i++) {
      int tag = FlGui::instance()->selectedVertices[i]->tag();
      int index = List_ISearchSeq(List1, &tag, fcmp_int);
      if(index < 0) List_Add(List1, &tag);
      FlGui::instance()->selectedVertices[i]->setSelection(1);
    }
  }
  Msg::StatusGl("");
  FlGui::instance()->resetVisibility();
  GModel::current()->setSelection(0);
  drawContext::global()->draw();
}

static void geometry_elementary_coherence_cb(Fl_Widget *w, void *data)
{
  scriptCoherence(GModel::current()->getFileName());
}

static void geometry_physical_add_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string what((const char *)data);
  FlGui::instance()->physicalContext->show(what, false);
  action_point_line_surface_volume(7, what);
  if(!FlGui::available()) return;
  FlGui::instance()->physicalContext->hide();
}

static void geometry_physical_remove_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string what((const char *)data);
  FlGui::instance()->physicalContext->show(what, true);
  action_point_line_surface_volume(11, what);
  if(FlGui::available()) FlGui::instance()->physicalContext->hide();
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

void mesh_1d_cb(Fl_Widget *w, void *data)
{
  GModel::current()->mesh(1);
  drawContext::global()->draw();
  FlGui::instance()->updateStatistics();
}

void mesh_2d_cb(Fl_Widget *w, void *data)
{
  GModel::current()->mesh(2);
  drawContext::global()->draw();
  FlGui::instance()->updateStatistics();
}

void mesh_3d_cb(Fl_Widget *w, void *data)
{
  GModel::current()->mesh(3);
  drawContext::global()->draw();
  FlGui::instance()->updateStatistics();
}

#if defined(HAVE_MESH)

static void mesh_modify_parts(Fl_Widget *w, void *data,
                              const std::string &action)
{
  const char *str = (const char *)data;
  int what;

  if(!strcmp(str, "elements")) {
    CTX::instance()->pickElements = 1;
    what = ENT_ALL;
  }
  else if(!strcmp(str, "curves")) {
    CTX::instance()->pickElements = 0;
    what = ENT_CURVE;
  }
  else if(!strcmp(str, "surfaces")) {
    CTX::instance()->pickElements = 0;
    what = ENT_SURFACE;
  }
  else if(!strcmp(str, "volumes")) {
    CTX::instance()->pickElements = 0;
    what = ENT_VOLUME;
  }
  else
    return;

  std::vector<MElement *> ele;
  std::vector<GEntity *> ent;

  while(1) {
    if(!FlGui::available()) return;

    CTX::instance()->mesh.changed = ENT_ALL;
    drawContext::global()->draw();

    if(ele.size() || ent.size())
      Msg::StatusGl(
        "Select %s\n"
        "[Press 'e' to end selection, 'u' to undo last selection or "
        "'q' to abort]",
        str);
    else
      Msg::StatusGl("Select %s\n"
                    "[Press 'e' to end selection or 'q' to abort]",
                    str);

    char ib = FlGui::instance()->selectEntity(what);
    if(!FlGui::available()) return;
    if(ib == 'l') {
      if(CTX::instance()->pickElements) {
        for(std::size_t i = 0; i < FlGui::instance()->selectedElements.size();
            i++) {
          if(FlGui::instance()->selectedElements[i]->getVisibility() != 2) {
            FlGui::instance()->selectedElements[i]->setVisibility(2);
            ele.push_back(FlGui::instance()->selectedElements[i]);
          }
        }
      }
      else {
        for(std::size_t i = 0; i < FlGui::instance()->selectedEdges.size();
            i++) {
          if(FlGui::instance()->selectedEdges[i]->getSelection() != 1) {
            FlGui::instance()->selectedEdges[i]->setSelection(1);
            ent.push_back(FlGui::instance()->selectedEdges[i]);
          }
        }
        for(std::size_t i = 0; i < FlGui::instance()->selectedFaces.size();
            i++) {
          if(FlGui::instance()->selectedFaces[i]->getSelection() != 1) {
            FlGui::instance()->selectedFaces[i]->setSelection(1);
            ent.push_back(FlGui::instance()->selectedFaces[i]);
          }
        }
        for(std::size_t i = 0; i < FlGui::instance()->selectedRegions.size();
            i++) {
          if(FlGui::instance()->selectedRegions[i]->getSelection() != 1) {
            FlGui::instance()->selectedRegions[i]->setSelection(1);
            ent.push_back(FlGui::instance()->selectedRegions[i]);
          }
        }
      }
    }
    if(ib == 'r') {
      if(CTX::instance()->pickElements) {
        for(std::size_t i = 0; i < FlGui::instance()->selectedElements.size();
            i++)
          FlGui::instance()->selectedElements[i]->setVisibility(1);
      }
      else {
        for(std::size_t i = 0; i < FlGui::instance()->selectedEdges.size(); i++)
          FlGui::instance()->selectedEdges[i]->setSelection(0);
        for(std::size_t i = 0; i < FlGui::instance()->selectedFaces.size(); i++)
          FlGui::instance()->selectedFaces[i]->setSelection(0);
        for(std::size_t i = 0; i < FlGui::instance()->selectedRegions.size();
            i++)
          FlGui::instance()->selectedRegions[i]->setSelection(0);
      }
    }
    if(ib == 'u') {
      if(CTX::instance()->pickElements) {
        if(ele.size()) {
          ele[ele.size() - 1]->setVisibility(1);
          ele.pop_back();
        }
      }
      else {
        if(ent.size()) {
          ent[ent.size() - 1]->setSelection(0);
          ent.pop_back();
        }
      }
    }
    if(ib == 'e') {
      if(CTX::instance()->pickElements) {
        for(std::size_t i = 0; i < ele.size(); i++)
          if(ele[i]->getVisibility() == 2) ele[i]->setVisibility(0);
      }
      else {
        for(std::size_t i = 0; i < ent.size(); i++)
          if(ent[i]->getSelection() == 1) {
            ent[i]->setVisibility(0);
            ent[i]->setSelection(0);
          }
      }
      if(action == "delete")
        GModel::current()->removeInvisibleElements();
      else if(action == "reverse")
        GModel::current()->reverseInvisibleElements();
      else
        Msg::Error("Unknown action on mesh part");
      ele.clear();
      ent.clear();
    }
    if(ib == 'q') {
      GModel::current()->setSelection(0);
      break;
    }
  }

  CTX::instance()->mesh.changed = ENT_ALL;
  CTX::instance()->pickElements = 0;
  drawContext::global()->draw();
  FlGui::instance()->updateStatistics();
  Msg::StatusGl("");
}

static void mesh_delete_parts_cb(Fl_Widget *w, void *data)
{
  mesh_modify_parts(w, data, "delete");
}

static void mesh_reverse_parts_cb(Fl_Widget *w, void *data)
{
  mesh_modify_parts(w, data, "reverse");
}

static void mesh_inspect_cb(Fl_Widget *w, void *data)
{
  CTX::instance()->pickElements = 1;
  CTX::instance()->mesh.changed = ENT_ALL;
  drawContext::global()->draw();

  while(1) {
    if(!FlGui::available()) return;

    Msg::StatusGl("Select element\n[Press 'q' to abort]");
    char ib = FlGui::instance()->selectEntity(ENT_ALL);
    if(!FlGui::available()) return;
    if(ib == 'l') {
      if(FlGui::instance()->selectedElements.size()) {
        MElement *ele = FlGui::instance()->selectedElements[0];
        GModel::current()->setSelection(0);
        ele->setVisibility(2);
        CTX::instance()->mesh.changed = ENT_ALL;
        drawContext::global()->draw();
        std::vector<std::string> info =
          SplitString(ele->getInfoString(true), '\n');
        for(std::size_t i = 0; i < info.size(); i++)
          Msg::Direct("%s", info[i].c_str());
        if(CTX::instance()->tooltips) {
          std::string str;
          for(std::size_t i = 0; i < info.size(); i++) str += info[i] + "\n";
          FlGui::instance()->getCurrentOpenglWindow()->drawTooltip(str);
        }
      }
    }
    if(ib == 'q') {
      GModel::current()->setSelection(0);
      break;
    }
  }

  CTX::instance()->pickElements = 0;
  CTX::instance()->mesh.changed = ENT_ALL;
  drawContext::global()->draw();
  Msg::StatusGl("");
}

static void mesh_degree_cb(Fl_Widget *w, void *data)
{
  int degree = (intptr_t)data;
  GModel::current()->setOrderN(degree, CTX::instance()->mesh.secondOrderLinear,
                               CTX::instance()->mesh.secondOrderIncomplete,
                               CTX::instance()->mesh.meshOnlyVisible);
  drawContext::global()->draw();
}

static void mesh_optimize_cb(Fl_Widget *w, void *data)
{
  if(CTX::instance()->lock) {
    Msg::Info("I'm busy! Ask me that later...");
    return;
  }
  CTX::instance()->lock = 1;
  GModel::current()->optimizeMesh("");
  CTX::instance()->lock = 0;
  drawContext::global()->draw();
  FlGui::instance()->updateStatistics();
}

static void mesh_optimize_quad_topo_cb(Fl_Widget *w, void *data)
{
  CTX::instance()->lock = 1;
  GModel::current()->optimizeMesh("QuadQuasiStructured");
  CTX::instance()->lock = 0;
  drawContext::global()->draw();
  FlGui::instance()->updateStatistics();
}

static void mesh_untangle_cb(Fl_Widget *w, void *data)
{
  CTX::instance()->lock = 1;
  GModel::current()->optimizeMesh("UntangleMeshGeometry");
  CTX::instance()->lock = 0;
  drawContext::global()->draw();
  FlGui::instance()->updateStatistics();
}

static void mesh_cross_compute_cb(Fl_Widget *w, void *data)
{
#if defined(HAVE_MESH)
  std::vector<int> tags;
  computeCrossField(GModel::current(), tags);
#endif
  drawContext::global()->draw();
}

static void mesh_refine_cb(Fl_Widget *w, void *data)
{
  GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear,
                                CTX::instance()->mesh.algoSubdivide == 1,
                                CTX::instance()->mesh.algoSubdivide == 2,
                                CTX::instance()->mesh.algoSubdivide == 3);
  drawContext::global()->draw();
  FlGui::instance()->updateStatistics();
}

static void mesh_smooth_cb(Fl_Widget *w, void *data)
{
  GModel::current()->optimizeMesh("Laplace2D");
  drawContext::global()->draw();
}

static void mesh_recombine_cb(Fl_Widget *w, void *data)
{
  GModel::current()->recombineMesh();
  drawContext::global()->draw();
  FlGui::instance()->updateStatistics();
}

#if defined(HAVE_NETGEN)
static void mesh_optimize_netgen_cb(Fl_Widget *w, void *data)
{
  if(CTX::instance()->lock) {
    Msg::Info("I'm busy! Ask me that later...");
    return;
  }
  CTX::instance()->lock = 1;
  GModel::current()->optimizeMesh("Netgen");
  CTX::instance()->lock = 0;
  drawContext::global()->draw();
  FlGui::instance()->updateStatistics();
}
#endif

static void mesh_partition_cb(Fl_Widget *w, void *data) { partition_dialog(); }

static void mesh_unpartition_cb(Fl_Widget *w, void *data)
{
  int ier = GModel::current()->unpartitionMesh();

  // Update the screen
  if(!ier) {
    opt_mesh_zone_definition(0, GMSH_SET, 0.);
    opt_mesh_color_carousel(0, GMSH_SET | GMSH_GUI, 1.);
    CTX::instance()->mesh.changed = ENT_ALL;
    FlGui::instance()->resetVisibility();
    drawContext::global()->draw();
  }
}

static void mesh_convert_old_partitioning_cb(Fl_Widget *w, void *data)
{
  int ier = GModel::current()->convertOldPartitioningToNewOne();

  // Update the screen
  if(!ier) {
    opt_mesh_zone_definition(0, GMSH_SET, 0.);
    opt_mesh_color_carousel(0, GMSH_SET | GMSH_GUI, 1.);
    CTX::instance()->mesh.changed = ENT_ALL;
    drawContext::global()->draw();
  }
}

static void mesh_define_length_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->meshContext->show(0);
  action_point_line_surface_volume(8, "Point");
  FlGui::instance()->meshContext->hide();
}

static void mesh_define_recombine_cb(Fl_Widget *w, void *data)
{
  action_point_line_surface_volume(9, "Surface");
}

static void mesh_define_transfinite(int dim)
{
  opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  switch(dim) {
  case 1: opt_geometry_curves(0, GMSH_SET | GMSH_GUI, 1); break;
  case 2: opt_geometry_surfaces(0, GMSH_SET | GMSH_GUI, 1); break;
  case 3: opt_geometry_volumes(0, GMSH_SET | GMSH_GUI, 1); break;
  }
  drawContext::global()->draw();

  std::vector<int> p;
  char ib;
  while(1) {
    if(!FlGui::available()) return;

    switch(dim) {
    case 1:
      if(p.empty())
        Msg::StatusGl("Select curves\n"
                      "[Press 'e' to end selection or 'q' to abort]");
      else
        Msg::StatusGl("Select curves\n"
                      "[Press 'e' to end selection, 'u' to undo last selection "
                      "or 'q' to abort]");
      ib = FlGui::instance()->selectEntity(ENT_CURVE);
      if(!FlGui::available()) return;
      break;
    case 2:
      Msg::StatusGl("Select surface\n[Press 'q' to abort]");
      ib = FlGui::instance()->selectEntity(ENT_SURFACE);
      if(!FlGui::available()) return;
      break;
    case 3:
      Msg::StatusGl("Select volume\n[Press 'q' to abort]");
      ib = FlGui::instance()->selectEntity(ENT_VOLUME);
      if(!FlGui::available()) return;
      break;
    default: ib = 'l'; break;
    }

    if(ib == 'e') {
      if(dim == 1) {
        if(p.size())
          scriptSetTransfiniteLine(
            p, GModel::current()->getFileName(),
            FlGui::instance()->meshContext->choice[0]->text(),
            FlGui::instance()->meshContext->input[2]->value(),
            FlGui::instance()->meshContext->input[1]->value());
      }
      GModel::current()->setSelection(0);
      drawContext::global()->draw();
      p.clear();
    }
    if(ib == 'u') {
      if(dim == 1) {
        if(p.size()) {
          GEdge *ge = GModel::current()->getEdgeByTag(p.back());
          if(ge) ge->setSelection(0);
          drawContext::global()->draw();
          p.pop_back();
        }
      }
    }
    if(ib == 'q') {
      GModel::current()->setSelection(0);
      drawContext::global()->draw();
      break;
    }
    if(ib == 'r') {
      Msg::Warning("Entity de-selection not supported yet during "
                   "transfinite definition");
    }
    if(ib == 'l') {
      switch(dim) {
      case 1:
        for(std::size_t i = 0; i < FlGui::instance()->selectedEdges.size();
            i++) {
          FlGui::instance()->selectedEdges[i]->setSelection(1);
          p.push_back(FlGui::instance()->selectedEdges[i]->tag());
        }
        drawContext::global()->draw();
        break;
      case 2:
      case 3:
        if(dim == 2) {
          FlGui::instance()->selectedFaces[0]->setSelection(1);
          drawContext::global()->draw();
          p.push_back(FlGui::instance()->selectedFaces[0]->tag());
        }
        else {
          FlGui::instance()->selectedRegions[0]->setSelection(1);
          drawContext::global()->draw();
          p.push_back(FlGui::instance()->selectedRegions[0]->tag());
        }
        while(1) {
          if(!FlGui::available()) return;

          if(p.size() == 1)
            Msg::StatusGl("Select (ordered) boundary points\n"
                          "[Press 'e' to end selection or 'q' to abort]");
          else
            Msg::StatusGl(
              "Select (ordered) boundary points\n"
              "[Press 'e' to end selection, 'u' to undo last selection "
              "or 'q' to abort]");
          ib = FlGui::instance()->selectEntity(ENT_POINT);
          if(!FlGui::available()) return;
          if(ib == 'l') {
            for(std::size_t i = 0;
                i < FlGui::instance()->selectedVertices.size(); i++) {
              FlGui::instance()->selectedVertices[i]->setSelection(1);
              p.push_back(FlGui::instance()->selectedVertices[i]->tag());
              break;
            }
            drawContext::global()->draw();
          }
          if(ib == 'u') {
            if(p.size() > 1) {
              GVertex *gv = GModel::current()->getVertexByTag(p.back());
              if(gv) gv->setSelection(0);
              drawContext::global()->draw();
              p.pop_back();
            }
          }
          if(ib == 'r') {
            Msg::Warning("Entity de-selection not supported yet during "
                         "transfinite definition");
          }
          if(ib == 'e') {
            switch(dim) {
            case 2:
              if((p.size() == 0 + 1 || p.size() == 3 + 1 || p.size() == 4 + 1))
                scriptSetTransfiniteSurface(
                  p, GModel::current()->getFileName(),
                  FlGui::instance()->meshContext->choice[1]->text());
              else
                Msg::Error("Wrong number of points for mesh constraint");
              break;
            case 3:
              if((p.size() == 0 + 1 || p.size() == 6 + 1 || p.size() == 8 + 1))
                scriptSetTransfiniteVolume(p, GModel::current()->getFileName());
              else
                Msg::Error("Wrong number of points for transfinite volume");
              break;
            }
            GModel::current()->setSelection(0);
            drawContext::global()->draw();
            p.clear();
            break;
          }
          if(ib == 'q') {
            GModel::current()->setSelection(0);
            drawContext::global()->draw();
            goto stopall;
          }
        }
        break;
      }
    }
  }

stopall:
  Msg::StatusGl("");
}

static void mesh_define_transfinite_line_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->meshContext->show(1);
  mesh_define_transfinite(1);
  FlGui::instance()->meshContext->hide();
}

static void mesh_define_transfinite_surface_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->meshContext->show(2);
  mesh_define_transfinite(2);
  FlGui::instance()->meshContext->hide();
}

static void mesh_define_transfinite_volume_cb(Fl_Widget *w, void *data)
{
  mesh_define_transfinite(3);
}

static void mesh_define_embedded_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string what((const char *)data);
  std::vector<int> entities;
  bool selectEntities = true;

  int type;
  const char *str = "";
  if(what == "Surface") {
    type = ENT_SURFACE;
    str = "surfaces";
    opt_geometry_surfaces(0, GMSH_SET | GMSH_GUI, 1);
  }
  else if(what == "Curve") {
    type = ENT_CURVE;
    str = "curves";
    opt_geometry_curves(0, GMSH_SET | GMSH_GUI, 1);
  }
  else if(what == "Point") {
    type = ENT_POINT;
    str = "points";
    opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  }
  else {
    Msg::Error("Unknown type of entity to embed: %s", what.c_str());
    return;
  }
  while(1) {
    if(!FlGui::available()) return;

    if(entities.empty())
      Msg::StatusGl("Select %s\n"
                    "[Press 'e' to end selection or 'q' to abort]",
                    str);
    else if(selectEntities)
      Msg::StatusGl(
        "Select %s\n"
        "[Press 'e' to end selection, 'u' to undo last selection or "
        "'q' to abort]",
        str);
    else
      Msg::StatusGl("Select entity in which to embed the %s\n"
                    "[Press 'q' to abort]",
                    str);
    int t = type;
    if(!selectEntities) {
      switch(FlGui::instance()->transformContext->choice->value()) {
      case 2: t = ENT_CURVE; break;
      case 3: t = ENT_SURFACE; break;
      case 4: t = ENT_VOLUME; break;
      default: t = ENT_ALL; break;
      }
    }
    char ib = FlGui::instance()->selectEntity(t);
    if(!FlGui::available()) return;
    if(ib == 'l') {
      if(selectEntities && what == "Point") {
        for(std::size_t i = 0; i < FlGui::instance()->selectedVertices.size();
            i++) {
          if(FlGui::instance()->selectedVertices[i]->getSelection() != 1) {
            FlGui::instance()->selectedVertices[i]->setSelection(1);
            entities.push_back(FlGui::instance()->selectedVertices[i]->tag());
          }
        }
      }
      else if(selectEntities && what == "Curve") {
        for(std::size_t i = 0; i < FlGui::instance()->selectedEdges.size();
            i++) {
          if(FlGui::instance()->selectedEdges[i]->getSelection() != 1) {
            FlGui::instance()->selectedEdges[i]->setSelection(1);
            entities.push_back(FlGui::instance()->selectedEdges[i]->tag());
          }
        }
      }
      else if(selectEntities && what == "Surface") {
        for(std::size_t i = 0; i < FlGui::instance()->selectedFaces.size();
            i++) {
          if(FlGui::instance()->selectedFaces[i]->getSelection() != 1) {
            FlGui::instance()->selectedFaces[i]->setSelection(1);
            entities.push_back(FlGui::instance()->selectedFaces[i]->tag());
          }
        }
      }
      else if(!selectEntities && (FlGui::instance()->selectedFaces.size() ||
                                  FlGui::instance()->selectedRegions.size())) {
        int dim = FlGui::instance()->selectedFaces.size() ? 2 : 3;
        if(dim == 2)
          FlGui::instance()->selectedFaces[0]->setSelection(1);
        else
          FlGui::instance()->selectedRegions[0]->setSelection(1);
        drawContext::global()->draw();
        int tag = (dim == 2) ? FlGui::instance()->selectedFaces[0]->tag() :
                               FlGui::instance()->selectedRegions[0]->tag();
        scriptEmbed(GModel::current()->getFileName(), what, entities, dim, tag);
        GModel::current()->setSelection(0);
        selectEntities = true;
        entities.clear();
      }
    }
    if(ib == 'r') {
      Msg::Warning(
        "Entity de-selection not supported yet during boolean operation");
    }
    if(ib == 'u') {
      if(selectEntities && entities.size()) {
        int dim = (what == "Surface") ? 2 : (what == "Curve") ? 1 : 0;
        GEntity *ge = GModel::current()->getEntityByTag(dim, entities.back());
        if(ge) ge->setSelection(0);
        entities.pop_back();
      }
    }
    if(ib == 'e') {
      if(selectEntities) {
        if(entities.empty())
          Msg::Error("At least one entity must be selected");
        else
          selectEntities = false;
      }
    }
    if(ib == 'q') {
      GModel::current()->setSelection(0);
      break;
    }
  }

  FlGui::instance()->transformContext->hide();
  drawContext::global()->draw();
  Msg::StatusGl("");
}

static void mesh_define_compound_entity_cb(Fl_Widget *w, void *data)
{
  action_point_line_surface_volume(10, (const char *)data);
}

#endif // HAVE_MESH

// clang-format off

// The static menus (we cannot use the 'g', 'm' 's' and 'p' mnemonics since they
// are already defined as global shortcuts)
static Fl_Menu_Item bar_table[] = {
  {"&File", 0, nullptr, nullptr, FL_SUBMENU},
    {"&New...",     FL_CTRL+'n', (Fl_Callback *)file_new_cb, nullptr},
    {"&Open...",    FL_CTRL+'o', (Fl_Callback *)file_open_merge_cb, (void*)"open"},
    {"Open Recent", 0, nullptr, nullptr, FL_SUBMENU},
      {"", 0, (Fl_Callback *)file_open_recent_cb, nullptr},
      {"", FL_CTRL+FL_SHIFT+'r', (Fl_Callback *)file_open_recent_cb, nullptr},
      {"", 0, (Fl_Callback *)file_open_recent_cb, nullptr},
      {"", 0, (Fl_Callback *)file_open_recent_cb, nullptr},
      {"", 0, (Fl_Callback *)file_open_recent_cb, nullptr},
      {"", 0, (Fl_Callback *)file_open_recent_cb, nullptr},
      {"", 0, (Fl_Callback *)file_open_recent_cb, nullptr},
      {"", 0, (Fl_Callback *)file_open_recent_cb, nullptr},
      {"", 0, (Fl_Callback *)file_open_recent_cb, nullptr},
      {"", 0, (Fl_Callback *)file_open_recent_cb, nullptr},
      {nullptr},
    {"M&erge...",   FL_CTRL+FL_SHIFT+'o', (Fl_Callback *)file_open_merge_cb, (void*)"merge"},
    {"Watch Pattern...",    0, (Fl_Callback *)file_watch_cb, nullptr, FL_MENU_DIVIDER},
    {"&Clear",      0, (Fl_Callback *)file_clear_cb, nullptr},
    {"&Rename...",  FL_CTRL+'r', (Fl_Callback *)file_rename_cb, nullptr},
    {"Delete",      0, (Fl_Callback *)file_delete_cb, nullptr, FL_MENU_DIVIDER},
    {"Remote", 0, nullptr, nullptr, FL_MENU_DIVIDER | FL_SUBMENU},
      {"Start...",  0, (Fl_Callback *)file_remote_cb, (void*)"start"},
      {"Merge...",  0, (Fl_Callback *)file_remote_cb, (void*)"merge"},
      {"Clear",     0, (Fl_Callback *)file_remote_cb, (void*)"clear"},
      {"Stop",      0, (Fl_Callback *)file_remote_cb, (void*)"stop"},
      {nullptr},
    {"Sa&ve Mesh",  FL_CTRL+FL_SHIFT+'s', (Fl_Callback *)mesh_save_cb, nullptr},
    {"Save Model Options", FL_CTRL+'j', (Fl_Callback *)file_options_save_cb, (void*)"file"},
    {"Save Options As Default", FL_CTRL+FL_SHIFT+'j', (Fl_Callback *)file_options_save_cb, (void*)"default", FL_MENU_DIVIDER},
    {"&Export...",  FL_CTRL+'e', (Fl_Callback *)file_export_cb, nullptr, FL_MENU_DIVIDER},
    {"&Quit",       FL_CTRL+'q', (Fl_Callback *)file_quit_cb, nullptr},
    {nullptr},
  {"&Tools", 0, nullptr, nullptr, FL_SUBMENU},
    {"&Options",         FL_CTRL+FL_SHIFT+'n', (Fl_Callback *)options_cb, nullptr},
    {"Pl&ugins",         FL_CTRL+FL_SHIFT+'u', (Fl_Callback *)plugin_cb, (void*)(-1)},
    {"&Visibility",      FL_CTRL+FL_SHIFT+'v', (Fl_Callback *)visibility_cb, nullptr},
    {"&Clipping",        FL_CTRL+FL_SHIFT+'c', (Fl_Callback *)clip_cb, nullptr},
    {"&Manipulator",     FL_CTRL+FL_SHIFT+'m', (Fl_Callback *)manip_cb, nullptr, FL_MENU_DIVIDER},
#if defined(HAVE_3M)
    {"&3M",              0, (Fl_Callback *)window3M_cb, 0, FL_MENU_DIVIDER},
#endif
    {"S&tatistics",      FL_CTRL+'i', (Fl_Callback *)statistics_cb, nullptr},
    {"M&essage Console", FL_CTRL+'l', (Fl_Callback *)show_hide_message_cb, nullptr},
    {nullptr},
  {"&Window", 0, nullptr, nullptr, FL_SUBMENU},
    {"New Window", 0, (Fl_Callback *)file_window_cb, (void*)"new", FL_MENU_DIVIDER},
#if defined(WIN32)
    {"Copy to Clipboard",  FL_CTRL+'c', (Fl_Callback *)file_window_cb, (void*)"copy", FL_MENU_DIVIDER},
#endif
    {"Split Horizontally", 0, (Fl_Callback *)file_window_cb, (void*)"split_h"},
    {"Split Vertically",   0, (Fl_Callback *)file_window_cb, (void*)"split_v"},
    {"Unsplit",            0, (Fl_Callback *)file_window_cb, (void*)"split_u", FL_MENU_DIVIDER},
    {"Minimize",           FL_CTRL+'m', (Fl_Callback *)window_cb, (void*)"minimize"},
    {"Zoom",               0, (Fl_Callback *)window_cb, (void*)"zoom"},
    {"Enter Full Screen",  FL_CTRL+'f', (Fl_Callback *)window_cb, (void*)"fullscreen", FL_MENU_DIVIDER},
    {"Attach/Detach Menu", FL_CTRL+'d', (Fl_Callback *)attach_detach_menu_cb, nullptr, FL_MENU_DIVIDER},
    {"Bring All to Front", 0, (Fl_Callback *)window_cb, (void*)"front"},
    {nullptr},
  {"&Help", 0, nullptr, nullptr, FL_SUBMENU},
    {"On&line Documentation", 0, (Fl_Callback *)help_online_cb, nullptr, FL_MENU_DIVIDER},
    {"&Keyboard and Mouse Usage",  FL_CTRL+'h', (Fl_Callback *)help_basic_cb, nullptr, FL_MENU_DIVIDER},
    {"&Current Options and Workspace", FL_CTRL+FL_SHIFT+'h', (Fl_Callback *)status_options_cb, (void*)"?", 0},
    {"&Restore all Options to Default Settings", 0, (Fl_Callback *)options_restore_defaults_cb, nullptr, FL_MENU_DIVIDER},
    {"&About Gmsh",           0, (Fl_Callback *)help_about_cb, nullptr},
    {nullptr},
  {nullptr}
};

#if defined(__APPLE__)

// Alternative items for the macOS system menu bar (removed '&' shortcuts: they
// would cause spurious menu items to appear on the menu window; removed
// File->Quit)
static Fl_Menu_Item sysbar_table[] = {
  {"File", 0, nullptr, nullptr, FL_SUBMENU},
    {"New...",     FL_META+'n', (Fl_Callback *)file_new_cb, nullptr},
    {"Open...",    FL_META+'o', (Fl_Callback *)file_open_merge_cb, (void*)"open"},
    {"Open Recent", 0, nullptr, nullptr, FL_SUBMENU},
      {"", 0, (Fl_Callback *)file_open_recent_cb, nullptr},
      {"", FL_META+FL_SHIFT+'r', (Fl_Callback *)file_open_recent_cb, nullptr},
      {"", 0, (Fl_Callback *)file_open_recent_cb, nullptr},
      {"", 0, (Fl_Callback *)file_open_recent_cb, nullptr},
      {"", 0, (Fl_Callback *)file_open_recent_cb, nullptr},
      {"", 0, (Fl_Callback *)file_open_recent_cb, nullptr},
      {"", 0, (Fl_Callback *)file_open_recent_cb, nullptr},
      {"", 0, (Fl_Callback *)file_open_recent_cb, nullptr},
      {"", 0, (Fl_Callback *)file_open_recent_cb, nullptr},
      {"", 0, (Fl_Callback *)file_open_recent_cb, nullptr},
      {nullptr},
    {"Merge...",   FL_META+FL_SHIFT+'o', (Fl_Callback *)file_open_merge_cb, (void*)"merge"},
    {"Watch Pattern...",   0, (Fl_Callback *)file_watch_cb, nullptr, FL_MENU_DIVIDER},
    {"Clear",      0, (Fl_Callback *)file_clear_cb, nullptr},
    {"Rename...",  FL_META+'r', (Fl_Callback *)file_rename_cb, nullptr},
    {"Delete",     0, (Fl_Callback *)file_delete_cb, nullptr, FL_MENU_DIVIDER},
    {"Remote", 0, nullptr, nullptr, FL_MENU_DIVIDER | FL_SUBMENU},
      {"Start...",  0, (Fl_Callback *)file_remote_cb, (void*)"start"},
      {"Merge...",  0, (Fl_Callback *)file_remote_cb, (void*)"merge"},
      {"Clear",     0, (Fl_Callback *)file_remote_cb, (void*)"clear"},
      {"Stop",      0, (Fl_Callback *)file_remote_cb, (void*)"stop"},
      {nullptr},
    {"Save Mesh",  FL_META+'s', (Fl_Callback *)mesh_save_cb, nullptr},
    {"Save Model Options", FL_META+'j', (Fl_Callback *)file_options_save_cb, (void*)"file"},
    {"Save Options As Default", FL_META+FL_SHIFT+'j', (Fl_Callback *)file_options_save_cb, (void*)"default", FL_MENU_DIVIDER},
    {"Export...",  FL_META+'e', (Fl_Callback *)file_export_cb, nullptr},
    {nullptr},
  {"Tools", 0, nullptr, nullptr, FL_SUBMENU},
    {"Options",         FL_META+FL_SHIFT+'n', (Fl_Callback *)options_cb, nullptr},
    {"Plugins",         FL_META+FL_SHIFT+'u', (Fl_Callback *)plugin_cb, (void*)(-1)},
    {"Visibility",      FL_META+FL_SHIFT+'v', (Fl_Callback *)visibility_cb, nullptr},
    {"Clipping",        FL_META+FL_SHIFT+'c', (Fl_Callback *)clip_cb, nullptr},
    {"Manipulator",     FL_META+FL_SHIFT+'m', (Fl_Callback *)manip_cb, nullptr, FL_MENU_DIVIDER},
#if defined(HAVE_3M)
    {"3M",              0, (Fl_Callback *)window3M_cb, 0, FL_MENU_DIVIDER},
#endif
    {"Statistics",      FL_META+'i', (Fl_Callback *)statistics_cb, nullptr},
    {"Message Console", FL_META+'l', (Fl_Callback *)show_hide_message_cb, nullptr},
    {nullptr},
  {"Window", 0, nullptr, nullptr, FL_SUBMENU},
    {"New Window", 0, (Fl_Callback *)file_window_cb, (void*)"new", FL_MENU_DIVIDER},
    {"Split Horizontally", 0, (Fl_Callback *)file_window_cb, (void*)"split_h"},
    {"Split Vertically",   0, (Fl_Callback *)file_window_cb, (void*)"split_v"},
    {"Unsplit",            0, (Fl_Callback *)file_window_cb, (void*)"split_u", FL_MENU_DIVIDER},
    {"Minimize",           FL_META+'m', (Fl_Callback *)window_cb, (void*)"minimize"},
    {"Zoom",               0, (Fl_Callback *)window_cb, (void*)"zoom"},
    {"Enter Full Screen",  FL_META+'f', (Fl_Callback *)window_cb, (void*)"fullscreen", FL_MENU_DIVIDER},
    {"Attach/Detach Menu", FL_META+'d', (Fl_Callback *)attach_detach_menu_cb, nullptr, FL_MENU_DIVIDER},
    {"Bring All to Front", 0, (Fl_Callback *)window_cb, (void*)"front"},
    {nullptr},
  {"Help", 0, nullptr, nullptr, FL_SUBMENU},
    {"Online Documentation", 0, (Fl_Callback *)help_online_cb, nullptr, FL_MENU_DIVIDER},
    {"Keyboard and Mouse Usage", 0, (Fl_Callback *)help_basic_cb, nullptr, FL_MENU_DIVIDER},
    {"Current Options and Workspace", FL_META+FL_SHIFT+'h', (Fl_Callback *)status_options_cb, (void*)"?"},
    {"Restore all Options to Default Settings", 0, (Fl_Callback *)options_restore_defaults_cb, nullptr},
    {nullptr},
  {nullptr}
};

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
    else if(!strcmp(str, "x")) {
      // set X-axis pointing out or into (shift) the screen
      if(CTX::instance()->camera) { ctx->camera.alongX(); }
      else {
        if(!Fl::event_state(FL_SHIFT)) {
          ctx->r[0] = -90.;
          ctx->r[1] = 0.;
          ctx->r[2] = -90.;
        }
        else {
          ctx->r[0] = -90.;
          ctx->r[1] = 0.;
          ctx->r[2] = 90.;
        }
        ctx->setQuaternionFromEulerAngles();
      }
    }
    else if(!strcmp(str, "y")) {
      // set Y-axis pointing out or into (shift) the screen
      if(CTX::instance()->camera) { ctx->camera.alongY(); }
      else {
        if(!Fl::event_state(FL_SHIFT)) {
          ctx->r[0] = -90.;
          ctx->r[1] = 0.;
          ctx->r[2] = 180.;
        }
        else {
          ctx->r[0] = -90.;
          ctx->r[1] = 0.;
          ctx->r[2] = 0.;
        }
        ctx->setQuaternionFromEulerAngles();
      }
    }
    else if(!strcmp(str, "z")) {
      // set Z-axis pointing out or into (shift) the screen
      if(CTX::instance()->camera) { ctx->camera.alongZ(); }
      else {
        if(!Fl::event_state(FL_SHIFT)) {
          ctx->r[0] = 0.;
          ctx->r[1] = 0.;
          ctx->r[2] = 0.;
        }
        else {
          ctx->r[0] = 0.;
          ctx->r[1] = 180.;
          ctx->r[2] = 0.;
        }
        ctx->setQuaternionFromEulerAngles();
      }
    }
    else if(!strcmp(str, "1:1")) {
      // if Shift is pressed, reset bounding box around visible
      // entities
      if(Fl::event_state(FL_SHIFT)) SetBoundingBox(true);
      // reset translation and scaling, or sync translation and
      // scaling with the first window (alt)
      if(CTX::instance()->camera) { ctx->camera.lookAtCg(); }
      else {
        if(Fl::event_state(FL_CTRL) || Fl::event_state(FL_META)) {
          if(i != 0) {
            drawContext *ctx0 = gls[0]->getDrawContext();
            for(int j = 0; j < 3; j++) {
              ctx->t[j] = ctx0->t[j];
              ctx->s[j] = ctx0->s[j];
            }
          }
        }
        else {
          ctx->t[0] = ctx->t[1] = ctx->t[2] = 0.;
          ctx->s[0] = ctx->s[1] = ctx->s[2] = 1.;
        }
      }
    }
    else if(!strcmp(str, "reset")) {
      if(CTX::instance()->camera) { ctx->camera.init(); }
      else {
        // reset everything
        ctx->t[0] = ctx->t[1] = ctx->t[2] = 0.;
        ctx->s[0] = ctx->s[1] = ctx->s[2] = 1.;
        ctx->r[0] = ctx->r[1] = ctx->r[2] = 0.;
        ctx->setQuaternionFromEulerAngles();
      }
    }
  }
  drawContext::global()->draw();
  FlGui::instance()->manip->update();
}

void quick_access_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string what((const char *)data);
  if(what == "general")
    general_options_cb(nullptr, nullptr);
  else if(what == "geometry")
    geometry_options_cb(nullptr, nullptr);
  else if(what == "mesh")
    mesh_options_cb(nullptr, nullptr);
  else if(what == "view")
    view_options_cb(nullptr, (void *)-1);
  else if(what == "reset_viewport") {
    status_xyz1p_cb(nullptr, (void *)"1:1");
    status_xyz1p_cb(nullptr, (void *)"z");
  }
  else if(what == "select_center") {
    opt_general_rotation_center_cg(0, GMSH_SET | GMSH_GUI, 0);
    general_options_ok_cb(nullptr, (void *)"rotation_center");
    general_options_rotation_center_select_cb(nullptr, nullptr);
  }
  else if(what == "hover_meshes") {
    opt_general_mouse_hover_meshes(
      0, GMSH_SET | GMSH_GUI, !opt_general_mouse_hover_meshes(0, GMSH_GET, 0));
  }
  else if(what == "split_hor") {
    file_window_cb(nullptr, (void *)"split_h");
  }
  else if(what == "split_ver") {
    file_window_cb(nullptr, (void *)"split_v");
  }
  else if(what == "unsplit") {
    file_window_cb(nullptr, (void *)"split_u");
  }
  else if(what == "axes") {
    int old = opt_general_axes(0, GMSH_GET, 0);
    opt_general_axes(0, GMSH_SET | GMSH_GUI, old ? 0 : 3);
    if(!old) {
      opt_general_axes_auto_position(0, GMSH_SET | GMSH_GUI, 0);
      general_options_axes_fit_cb(nullptr, nullptr);
    }
  }
  else if(what == "orthographic")
    opt_general_orthographic(0, GMSH_SET | GMSH_GUI, 1);
  else if(what == "perspective") {
    opt_general_orthographic(0, GMSH_SET | GMSH_GUI, 0);
    drawContext::global()->draw();
    numberOrStringOptionChooser("General", 0, "ClipFactor", true, "Factor",
                                true, 0.1, 20., 0.1);
  }
  else if(what == "geometry_points")
    opt_geometry_points(0, GMSH_SET | GMSH_GUI,
                        !opt_geometry_points(0, GMSH_GET, 0));
  else if(what == "geometry_curves")
    opt_geometry_curves(0, GMSH_SET | GMSH_GUI,
                        !opt_geometry_curves(0, GMSH_GET, 0));
  else if(what == "geometry_surfaces")
    opt_geometry_surfaces(0, GMSH_SET | GMSH_GUI,
                          !opt_geometry_surfaces(0, GMSH_GET, 0));
  else if(what == "geometry_volumes")
    opt_geometry_volumes(0, GMSH_SET | GMSH_GUI,
                         !opt_geometry_volumes(0, GMSH_GET, 0));
  else if(what == "mesh_nodes")
    opt_mesh_nodes(0, GMSH_SET | GMSH_GUI, !opt_mesh_nodes(0, GMSH_GET, 0));
  else if(what == "mesh_lines")
    opt_mesh_lines(0, GMSH_SET | GMSH_GUI, !opt_mesh_lines(0, GMSH_GET, 0));
  else if(what == "mesh_surface_edges")
    opt_mesh_surface_edges(0, GMSH_SET | GMSH_GUI,
                           !opt_mesh_surface_edges(0, GMSH_GET, 0));
  else if(what == "mesh_surface_faces")
    opt_mesh_surface_faces(0, GMSH_SET | GMSH_GUI,
                           !opt_mesh_surface_faces(0, GMSH_GET, 0));
  else if(what == "mesh_volume_edges")
    opt_mesh_volume_edges(0, GMSH_SET | GMSH_GUI,
                          !opt_mesh_volume_edges(0, GMSH_GET, 0));
  else if(what == "mesh_volume_faces")
    opt_mesh_volume_faces(0, GMSH_SET | GMSH_GUI,
                          !opt_mesh_volume_faces(0, GMSH_GET, 0));
  else if(what == "mesh_size")
    numberOrStringOptionChooser("Mesh", 0, "MeshSizeFactor", true, "Factor",
                                true, 0.01, 100, 0.01);
  else if(what == "view_element_outlines") {
    int set = 0;
    for(std::size_t i = 0; i < PView::list.size(); i++)
      if(opt_view_visible(i, GMSH_GET, 0) &&
         (set = opt_view_show_element(i, GMSH_GET, 0)))
        break;
    for(std::size_t i = 0; i < PView::list.size(); i++)
      if(opt_view_visible(i, GMSH_GET, 0))
        opt_view_show_element(i, GMSH_SET | GMSH_GUI, !set);
  }
  else if(what == "view_normal_raise") {
    double val = 0.;
    for(std::size_t i = 0; i < PView::list.size(); i++) {
      if(opt_view_visible(i, GMSH_GET, 0)) {
        double maxval = std::max(fabs(opt_view_min(i, GMSH_GET, 0)),
                                 fabs(opt_view_max(i, GMSH_GET, 0)));
        if(!maxval) maxval = 1.;
        double val2 = 2. * CTX::instance()->lc / maxval;
        val =
          numberOrStringOptionChooser("View", i, "NormalRaise", true, "Raise",
                                      true, -val2, val2, val2 / 200.);
        break;
      }
    }
    for(std::size_t i = 0; i < PView::list.size(); i++)
      if(opt_view_visible(i, GMSH_GET, 0))
        opt_view_normal_raise(i, GMSH_SET | GMSH_GUI, val);
  }
  else if(what == "view_iso") {
    for(std::size_t i = 0; i < PView::list.size(); i++)
      if(opt_view_visible(i, GMSH_GET, 0))
        opt_view_intervals_type(i, GMSH_SET | GMSH_GUI, 1);
    drawContext::global()->draw();
    double val = 0.;
    for(std::size_t i = 0; i < PView::list.size(); i++) {
      if(opt_view_visible(i, GMSH_GET, 0)) {
        val = numberOrStringOptionChooser("View", i, "NbIso", true, "Intervals",
                                          true, 1, 100, 1);
        break;
      }
    }
    for(std::size_t i = 0; i < PView::list.size(); i++)
      if(opt_view_visible(i, GMSH_GET, 0))
        opt_view_nb_iso(i, GMSH_SET | GMSH_GUI, val);
  }
  else if(what == "view_continous") {
    for(std::size_t i = 0; i < PView::list.size(); i++)
      if(opt_view_visible(i, GMSH_GET, 0))
        opt_view_intervals_type(i, GMSH_SET | GMSH_GUI, 2);
  }
  else if(what == "view_filled") {
    for(std::size_t i = 0; i < PView::list.size(); i++)
      if(opt_view_visible(i, GMSH_GET, 0))
        opt_view_intervals_type(i, GMSH_SET | GMSH_GUI, 3);
    drawContext::global()->draw();
    double val = 0.;
    for(std::size_t i = 0; i < PView::list.size(); i++) {
      if(opt_view_visible(i, GMSH_GET, 0)) {
        val = numberOrStringOptionChooser("View", i, "NbIso", true, "Intervals",
                                          true, 1, 100, 1);
        break;
      }
    }
    for(std::size_t i = 0; i < PView::list.size(); i++)
      if(opt_view_visible(i, GMSH_GET, 0))
        opt_view_nb_iso(i, GMSH_SET | GMSH_GUI, val);
  }
  else if(what == "view_numeric") {
    for(std::size_t i = 0; i < PView::list.size(); i++)
      if(opt_view_visible(i, GMSH_GET, 0))
        opt_view_intervals_type(i, GMSH_SET | GMSH_GUI, 4);
  }
  else if(what == "view_line") {
    for(std::size_t i = 0; i < PView::list.size(); i++)
      if(opt_view_visible(i, GMSH_GET, 0))
        opt_view_vector_type(i, GMSH_SET | GMSH_GUI, 1);
  }
  else if(what == "view_3d_arrow") {
    for(std::size_t i = 0; i < PView::list.size(); i++)
      if(opt_view_visible(i, GMSH_GET, 0))
        opt_view_vector_type(i, GMSH_SET | GMSH_GUI, 4);
  }
  else if(what == "view_displacement") {
    for(std::size_t i = 0; i < PView::list.size(); i++)
      if(opt_view_visible(i, GMSH_GET, 0))
        opt_view_vector_type(i, GMSH_SET | GMSH_GUI, 5);
    drawContext::global()->draw();
    double val = 0.;
    for(std::size_t i = 0; i < PView::list.size(); i++) {
      if(opt_view_visible(i, GMSH_GET, 0)) {
        double maxval = std::max(fabs(opt_view_min(i, GMSH_GET, 0)),
                                 fabs(opt_view_max(i, GMSH_GET, 0)));
        if(!maxval) maxval = 1.;
        double val3 = 2. * CTX::instance()->lc / maxval;
        val = numberOrStringOptionChooser("View", i, "DisplacementFactor", true,
                                          "Factor", true, 0, val3, val3 / 100.);
        break;
      }
    }
    for(std::size_t i = 0; i < PView::list.size(); i++)
      if(opt_view_visible(i, GMSH_GET, 0))
        opt_view_displacement_factor(i, GMSH_SET | GMSH_GUI, val);
  }
  else if(what == "view_glyph_barycenter") {
    for(std::size_t i = 0; i < PView::list.size(); i++)
      if(opt_view_visible(i, GMSH_GET, 0))
        opt_view_glyph_location(i, GMSH_SET | GMSH_GUI, 1);
  }
  else if(what == "view_glyph_node") {
    for(std::size_t i = 0; i < PView::list.size(); i++)
      if(opt_view_visible(i, GMSH_GET, 0))
        opt_view_glyph_location(i, GMSH_SET | GMSH_GUI, 2);
  }
  else if(what == "view_range_default") {
    for(std::size_t i = 0; i < PView::list.size(); i++)
      if(opt_view_visible(i, GMSH_GET, 0))
        opt_view_range_type(i, GMSH_SET | GMSH_GUI, 1);
  }
  else if(what == "view_range_per_step") {
    for(std::size_t i = 0; i < PView::list.size(); i++)
      if(opt_view_visible(i, GMSH_GET, 0))
        opt_view_range_type(i, GMSH_SET | GMSH_GUI, 3);
  }
  else if(what == "mesh_toggle") {
    static int value = 1;
    static int old_p = (int)opt_mesh_nodes(0, GMSH_GET, 0.);
    static int old_l = (int)opt_mesh_lines(0, GMSH_GET, 0.);
    static int old_se = (int)opt_mesh_surface_edges(0, GMSH_GET, 0.);
    static int old_sf = (int)opt_mesh_surface_faces(0, GMSH_GET, 0.);
    static int old_ve = (int)opt_mesh_volume_edges(0, GMSH_GET, 0.);
    static int old_vf = (int)opt_mesh_volume_faces(0, GMSH_GET, 0.);
    if(!value) { // retore visibility
      Msg::StatusBar(false, "Mesh display restored");
      value = 1;
      opt_mesh_nodes(0, GMSH_SET | GMSH_GUI, old_p);
      opt_mesh_lines(0, GMSH_SET | GMSH_GUI, old_l);
      opt_mesh_surface_edges(0, GMSH_SET | GMSH_GUI, old_se);
      opt_mesh_surface_faces(0, GMSH_SET | GMSH_GUI, old_sf);
      opt_mesh_volume_edges(0, GMSH_SET | GMSH_GUI, old_ve);
      opt_mesh_volume_faces(0, GMSH_SET | GMSH_GUI, old_vf);
    }
    else {
      Msg::StatusBar(false, "Mesh display OFF");
      value = 0;
      old_p = (int)opt_mesh_nodes(0, GMSH_GET, 0.);
      old_l = (int)opt_mesh_lines(0, GMSH_GET, 0.);
      old_se = (int)opt_mesh_surface_edges(0, GMSH_GET, 0.);
      old_sf = (int)opt_mesh_surface_faces(0, GMSH_GET, 0.);
      old_ve = (int)opt_mesh_volume_edges(0, GMSH_GET, 0.);
      old_vf = (int)opt_mesh_volume_faces(0, GMSH_GET, 0.);
      opt_mesh_nodes(0, GMSH_SET | GMSH_GUI, 0);
      opt_mesh_lines(0, GMSH_SET | GMSH_GUI, 0);
      opt_mesh_surface_edges(0, GMSH_SET | GMSH_GUI, 0);
      opt_mesh_surface_faces(0, GMSH_SET | GMSH_GUI, 0);
      opt_mesh_volume_edges(0, GMSH_SET | GMSH_GUI, 0);
      opt_mesh_volume_faces(0, GMSH_SET | GMSH_GUI, 0);
    }
  }

#if defined(HAVE_TOUCHBAR)
  updateTouchBar();
#endif
}

static void model_switch_cb(Fl_Widget *w, void *data)
{
  int index = (intptr_t)data;
  GModel::current(index);
  SetBoundingBox();
  for(std::size_t i = 0; i < GModel::list.size(); i++)
    GModel::list[i]->setVisibility(0);
  GModel::current()->setVisibility(1);
  CTX::instance()->mesh.changed = ENT_ALL;
  Msg::SetWindowTitle(GModel::current()->getFileName());
  FlGui::instance()->resetVisibility();
  drawContext::global()->draw();
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
      Fl::event_x(), Fl::event_y(), nullptr, &menu[selected], nullptr);
    if(m) m->do_callback(nullptr);
    for(std::size_t i = 0; i < tofree.size(); i++) free(tofree[i]);
    drawContext::global()->draw();
  }
  else if(what == "?") { // display options
    help_options_cb(nullptr, nullptr);
    FlGui::instance()->help->options->show();
  }
  else if(what == "p") { // toggle projection mode
    opt_general_orthographic(0, GMSH_SET | GMSH_GUI,
                             !opt_general_orthographic(0, GMSH_GET, 0));
    drawContext::global()->draw();
  }
  else if(what == "quick_access") { // quick access menu
    // clang-format off
    static Fl_Menu_Item menu[] = {
      { "Reset viewport", 0, quick_access_cb, (void*)"reset_viewport" },
      { "Select rotation center", 0, quick_access_cb, (void*)"select_center" },
      { "Split window", 0, nullptr, nullptr, FL_SUBMENU | FL_MENU_DIVIDER },
         { "Horizontally", 0, quick_access_cb, (void*)"split_hor"},
         { "Vertically", 0, quick_access_cb, (void*)"split_ver"},
         { "Unsplit", 0, quick_access_cb, (void*)"unsplit"},
         { nullptr },
      { "Axes", FL_ALT + 'a', quick_access_cb, (void*)"axes",
        FL_MENU_TOGGLE },
      { "Mouse hover over meshes", 0, quick_access_cb, (void*)"hover_meshes",
        FL_MENU_TOGGLE },
      { "Projection mode", 0, nullptr, nullptr, FL_SUBMENU },
         { "Orthographic", FL_ALT + 'o', quick_access_cb, (void*)"orthographic"},
         { "Perspective", 0, quick_access_cb, (void*)"perspective"},
         { nullptr },
      { "All general options...", 0, quick_access_cb, (void*)"general",
        FL_MENU_DIVIDER, 0, FL_ITALIC },
      { "Geometry visibility", 0, nullptr, nullptr, FL_SUBMENU },
         { "Points", FL_ALT + 'p', quick_access_cb, (void*)"geometry_points",
           FL_MENU_TOGGLE },
         { "Curves", FL_ALT + 'l', quick_access_cb, (void*)"geometry_curves",
           FL_MENU_TOGGLE },
         { "Surfaces ", FL_ALT + 's', quick_access_cb, (void*)"geometry_surfaces",
           FL_MENU_TOGGLE },
         { "Volumes", FL_ALT + 'v', quick_access_cb, (void*)"geometry_volumes",
           FL_MENU_TOGGLE },
         { nullptr },
      { "All geometry options...", 0, quick_access_cb, (void*)"geometry",
        FL_MENU_DIVIDER, 0, FL_ITALIC },
      { "Mesh visibility", 0, nullptr, nullptr, FL_SUBMENU },
         { "Nodes", FL_ALT + FL_SHIFT + 'p', quick_access_cb, (void*)"mesh_nodes",
           FL_MENU_TOGGLE },
         { "1D elements", FL_ALT + FL_SHIFT + 'l', quick_access_cb, (void*)"mesh_lines",
           FL_MENU_TOGGLE },
         { "2D element edges ", FL_ALT + FL_SHIFT + 's', quick_access_cb,
           (void*)"mesh_surface_edges", FL_MENU_TOGGLE },
         { "2D element faces", FL_ALT + FL_SHIFT + 'd', quick_access_cb,
           (void*)"mesh_surface_faces", FL_MENU_TOGGLE },
         { "3D element edges", FL_ALT + FL_SHIFT + 'v', quick_access_cb,
           (void*)"mesh_volume_edges", FL_MENU_TOGGLE },
         { "3D element faces", FL_ALT + FL_SHIFT + 'b', quick_access_cb,
           (void*)"mesh_volume_faces", FL_MENU_TOGGLE },
         { nullptr },
      { "Toggle mesh display", FL_ALT + 'm', quick_access_cb, (void*)"mesh_toggle" },
      { "Global mesh size factor", 0, quick_access_cb, (void*)"mesh_size" },
      { "All mesh options...", 0, quick_access_cb, (void*)"mesh",
        FL_MENU_DIVIDER, 0, FL_ITALIC },
      { "View element outlines ", FL_ALT + 'e', quick_access_cb,
        (void*)"view_element_outlines", FL_MENU_TOGGLE },
      { "View normal raise", 0, quick_access_cb, (void*)"view_normal_raise" },
      { "View intervals", 0, nullptr, nullptr, FL_SUBMENU },
         { "Iso-values", FL_ALT + 't', quick_access_cb, (void*)"view_iso"},
         { "Continuous map", 0, quick_access_cb, (void*)"view_continous"},
         { "Filled iso-values", 0, quick_access_cb, (void*)"view_filled"},
         { "Numeric values", 0, quick_access_cb, (void*)"view_numeric"},
         { nullptr },
      { "View range", 0, nullptr, nullptr, FL_SUBMENU },
         { "Default", 0, quick_access_cb, (void*)"view_range_default"},
         { "Per time step", 0, quick_access_cb, (void*)"view_range_per_step"},
         { nullptr },
      { "View vector display", 0, nullptr, nullptr, FL_SUBMENU },
         { "Line", 0, quick_access_cb, (void*)"view_line"},
         { "3D arrow", 0, quick_access_cb, (void*)"view_3d_arrow"},
         { "Displacement", 0, quick_access_cb, (void*)"view_displacement"},
         { nullptr },
      { "View glyph location", 0, nullptr, nullptr, FL_SUBMENU },
         { "Barycenter", 0, quick_access_cb, (void*)"view_glyph_barycenter"},
         { "Node", 0, quick_access_cb, (void*)"view_glyph_node"},
         { nullptr },
      { "All view options...", 0, quick_access_cb, (void*)"view", 0, 0, FL_ITALIC },
      { nullptr }
    };
    // clang-format on
    const int gen = 7, geo = 14, msh = 21, pos = 32, end = 54;
    if(opt_general_axes(0, GMSH_GET, 0))
      menu[gen + 0].set();
    else
      menu[gen + 0].clear();
    if(opt_general_mouse_hover_meshes(0, GMSH_GET, 0))
      menu[gen + 1].set();
    else
      menu[gen + 1].clear();
    for(std::size_t i = 0; i < PView::list.size(); i++)
      if(opt_view_visible(i, GMSH_GET, 0) && opt_view_axes(i, GMSH_GET, 0))
        menu[gen + 7].set();
    if(opt_geometry_points(0, GMSH_GET, 0))
      menu[geo + 1].set();
    else
      menu[geo + 1].clear();
    if(opt_geometry_curves(0, GMSH_GET, 0))
      menu[geo + 2].set();
    else
      menu[geo + 2].clear();
    if(opt_geometry_surfaces(0, GMSH_GET, 0))
      menu[geo + 3].set();
    else
      menu[geo + 3].clear();
    if(opt_geometry_volumes(0, GMSH_GET, 0))
      menu[geo + 4].set();
    else
      menu[geo + 4].clear();
    if(opt_mesh_nodes(0, GMSH_GET, 0))
      menu[msh + 1].set();
    else
      menu[msh + 1].clear();
    if(opt_mesh_lines(0, GMSH_GET, 0))
      menu[msh + 2].set();
    else
      menu[msh + 2].clear();
    if(opt_mesh_surface_edges(0, GMSH_GET, 0))
      menu[msh + 3].set();
    else
      menu[msh + 3].clear();
    if(opt_mesh_surface_faces(0, GMSH_GET, 0))
      menu[msh + 4].set();
    else
      menu[msh + 4].clear();
    if(opt_mesh_volume_edges(0, GMSH_GET, 0))
      menu[msh + 5].set();
    else
      menu[msh + 5].clear();
    if(opt_mesh_volume_faces(0, GMSH_GET, 0))
      menu[msh + 6].set();
    else
      menu[msh + 6].clear();
    if(PView::list.empty()) {
      // if there are no post-processing view, hide all entries below the mesh
      // options...
      menu[pos - 1].flags = 0;
      for(int i = pos; i <= end; i++) menu[i].hide();
    }
    else {
      // otherwise add a divider and show the post-pro view entries
      menu[pos - 1].flags = FL_MENU_DIVIDER;
      for(int i = pos; i <= end; i++) menu[i].show();
      menu[pos].clear();
      for(std::size_t i = 0; i < PView::list.size(); i++) {
        if(opt_view_visible(i, GMSH_GET, 0) &&
           opt_view_show_element(i, GMSH_GET, 0)) {
          menu[pos].set();
          break;
        }
      }
    }
    // popup the menu
    static Fl_Menu_Item *picked =
      &menu[msh + 8]; // toggle mesh display - the default
    picked = (Fl_Menu_Item *)menu->popup(
      Fl::event_x(), Fl::event_y(), nullptr,
      (picked && picked->visible()) ? picked : &menu[msh + 8], nullptr);
    if(picked && picked->callback())
      picked->do_callback(nullptr, picked->user_data());
    drawContext::global()->draw();
  }
  else if(what == "S") { // mouse selection
    if(CTX::instance()->mouseSelection) {
      opt_general_mouse_selection(0, GMSH_SET | GMSH_GUI, 0);
      for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++)
        for(std::size_t j = 0; j < FlGui::instance()->graph[i]->gl.size(); j++)
          FlGui::instance()->graph[i]->gl[j]->cursor(FL_CURSOR_DEFAULT,
                                                     FL_BLACK, FL_WHITE);
    }
    else
      opt_general_mouse_selection(0, GMSH_SET | GMSH_GUI, 1);
  }
}

static int stop_anim = 0, view_in_cycle = -1;

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

  if(time) {
    for(std::size_t i = 0; i < PView::list.size(); i++) {
      if(opt_view_visible(i, GMSH_GET, 0)) {
        // skip empty steps
        int step = (int)opt_view_timestep(i, GMSH_GET, 0) + incr;
        int numSteps = (int)opt_view_nb_timestep(i, GMSH_GET, 0);
        for(int j = 0; j < numSteps; j++) {
          if(PView::list[i]->getData()->hasTimeStep(step))
            break;
          else
            step += incr;
          if(step < 0) step = numSteps - 1;
          if(step > numSteps - 1) step = 0;
        }
        opt_view_timestep(i, GMSH_SET | GMSH_GUI, step);
      }
    }
  }
  else { // hide all views except view_in_cycle
    if(incr == 0) {
      view_in_cycle = 0;
      for(int i = 0; i < (int)PView::list.size(); i++)
        opt_view_visible(i, GMSH_SET | GMSH_GUI, (i == view_in_cycle));
    }
    else if(incr > 0) {
      if((view_in_cycle += incr) >= (int)PView::list.size()) view_in_cycle = 0;
      for(int i = 0; i < (int)PView::list.size(); i++)
        opt_view_visible(i, GMSH_SET | GMSH_GUI, (i == view_in_cycle));
    }
    else {
      if((view_in_cycle += incr) < 0) view_in_cycle = PView::list.size() - 1;
      for(int i = PView::list.size() - 1; i >= 0; i--)
        opt_view_visible(i, GMSH_SET | GMSH_GUI, (i == view_in_cycle));
    }
  }
  if(redraw) drawContext::global()->draw();
  busy = false;
}

static void status_play_cb(Fl_Widget *w, void *data)
{
  static double anim_time;
  getGraphicWindow(w)->setAnimButtons(0);
  stop_anim = 0;
  anim_time = TimeOfDay();
  while(1) {
    if(!FlGui::available()) return;

    if(stop_anim) break;
    if(TimeOfDay() - anim_time > CTX::instance()->post.animDelay) {
      anim_time = TimeOfDay();
      status_play_manual(!CTX::instance()->post.animCycle,
                         CTX::instance()->post.animStep);
    }
    FlGui::check();
  }
}

static void status_pause_cb(Fl_Widget *w, void *data)
{
  stop_anim = 1;
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
  else {
    view_in_cycle = 0;
    for(std::size_t i = 0; i < PView::list.size(); i++)
      opt_view_visible(i, GMSH_SET | GMSH_GUI, !i);
  }
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
  g->getMessageBrowser()->clear();
  for(int i = 0; i < (int)g->getMessages().size(); i++)
    g->getMessageBrowser()->add(g->getMessages()[i].c_str());
}

static void tile_cb(Fl_Widget *w, void *data)
{
  if(Fl::event() == FL_RELEASE) {
    // rebuild the tree when we relase the mouse after resizing
    FlGui::instance()->rebuildTree(true);
  }
}

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
    Fl_Window::resize(X, Y, W, H);
    const int minimum_non_message_height = 100;
    if(special && mh < h() - minimum_non_message_height)
      FlGui::instance()->graph[0]->setMessageHeight(mh);
  }
};

class mainWindowProgress : public Fl_Progress {
public:
  mainWindowProgress(int x, int y, int w, int h, const char *l = nullptr)
    : Fl_Progress(x, y, w, h, l)
  {
  }
  int handle(int event)
  {
    if(event == FL_PUSH) {
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
  : _autoScrollMessages(true)
{
  int mh = main ? BH : 0; // menu bar height
#if defined(__APPLE__)
  if(CTX::instance()->systemMenuBar) mh = 0;
#endif
  int sh = 2 * FL_NORMAL_SIZE - 3; // status bar height
  int sw = FL_NORMAL_SIZE + 2; // status button width

  int mheight = main ? 2 * BH /* nonzero! */ : 0;
  int glheight = CTX::instance()->glSize[1] - mheight;
  // make sure glheight is positive
  if(glheight <= 0) {
    CTX::instance()->glSize[1] = 600;
    glheight = CTX::instance()->glSize[1] - mheight;
  }
  int height = mh + glheight + mheight + sh;
  // make sure height < screen height
  if(height > Fl::h()) {
    height = Fl::h();
    glheight = height - mh - mheight - sh;
    CTX::instance()->glSize[1] = glheight + mheight;
  }

  int twidth = (main && !detachedMenu) ? 14 * sw : 0;
  int glwidth = CTX::instance()->glSize[0] - twidth;
  // make sure glwidth is positive
  if(glwidth <= 0) {
    CTX::instance()->glSize[0] = 600;
    glwidth = CTX::instance()->glSize[0] - twidth;
  }
  int width = glwidth + twidth;
  // make sure width < screen width
  if(width > Fl::w()) {
    width = Fl::w();
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
      _sysbar->menu(sysbar_table);
      _sysbar->global();
      fillRecentHistoryMenu();
    }
    else {
#endif
      _bar = new Fl_Menu_Bar(0, 0, width, BH);
      _bar->menu(bar_table);
      _bar->global();
      fillRecentHistoryMenu();
#if defined(__APPLE__)
    }
#endif
  }

  // minimum width should be exactly the width of the status bar buttons (see
  // below)
  _minWidth = 10 + 11 * sw + 1.75 * FL_NORMAL_SIZE;
  _minHeight = 100;
  _win->size_range(_minWidth, _minHeight);

  // a dummy resizable box that won't eat events
  dummyBox *resbox = new dummyBox(_minWidth, mh, width - _minWidth, glheight);
  _win->resizable(resbox);

  // tiled windows (tree menu, opengl, messages)
  _tile = new Fl_Tile(0, mh, glwidth + twidth, glheight + mheight);

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

  int mode = FL_RGB | FL_DEPTH | (CTX::instance()->db ? FL_DOUBLE : FL_SINGLE);
  if(CTX::instance()->antialiasing) mode |= FL_MULTISAMPLE;
  if(CTX::instance()->stereo) {
    mode |= FL_DOUBLE;
    mode |= FL_STEREO;
  }
  for(std::size_t i = 0; i < gl.size(); i++) gl[i]->mode(mode);

  if(main) {
    _browser = new messageBrowser(twidth, mh + glheight, glwidth, mheight);
    int s = CTX::instance()->msgFontSize;
    _browser->textsize(s <= 0 ? FL_NORMAL_SIZE - 2 : s);
    _browser->callback(message_browser_cb, this);
    _browser->search_callback(message_menu_search_cb, this);
    _browser->autoscroll_callback(message_menu_autoscroll_cb, this);
    _browser->save_callback(message_menu_save_cb, this);
    _browser->clear_callback(message_menu_clear_cb, this);
  }
  else {
    _browser = nullptr;
  }

  if(main && !detachedMenu) {
    _onelab = new onelabGroup(0, mh, twidth, height - mh - sh);
    _onelab->enableTreeWidgetResize(false);
  }
  else {
    _onelab = nullptr;
  }

  _tile->callback(tile_cb);
  _tile->end();

  // resize the tiles to match the prescribed sizes
  _tile->position(0, mh + glheight, 0, mh + CTX::instance()->glSize[1]);

  // if the tree widget is too small it will not be rebuilt correctly (probably
  // a bug)... so impose minimum width
  int minw = 3 * BB / 2 + 4 * WB;
  if(CTX::instance()->menuSize[0] < minw) CTX::instance()->menuSize[0] = minw;
  _tile->position(twidth, 0, CTX::instance()->menuSize[0], 0);

  // bottom button bar
  _bottom = new Fl_Box(0, mh + glheight + mheight, width, sh);
  _bottom->box(GMSH_SIMPLE_TOP_BOX);

  int x = 2;
  int sht = sh - 4; // leave a 2 pixel border at the bottom

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
  _butt[4] =
    new Fl_Button(x, mh + glheight + mheight + 2, sw, sht, "@-1gmsh_rotate");
  _butt[4]->callback(status_xyz1p_cb, (void *)"r");
  _butt[4]->tooltip(
    "Rotate +90 or -90 (Shift) degrees, or sync rotations (Ctrl)");
  x += sw;
  _butt[3] = new Fl_Button(x, mh + glheight + mheight + 2, 2 * FL_NORMAL_SIZE,
                           sht, "1:1");
  _butt[3]->callback(status_xyz1p_cb, (void *)"1:1");
  _butt[3]->tooltip("Set unit scale, sync scale between viewports (Ctrl), "
                    "or reset bounding box around visible entities (Shift) "
                    "(Alt+1, Alt+Ctrl+1, Alt+Shift+1)");
  x += 1.75 * FL_NORMAL_SIZE;
  _butt[9] = new Fl_Button(x, mh + glheight + mheight + 2, sw, sht, "S");
  _butt[9]->callback(status_options_cb, (void *)"S");
  _butt[9]->tooltip("Toggle mouse selection ON/OFF (Escape)");
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

  for(int i = 0; i < 12; i++) {
    _butt[i]->box(FL_FLAT_BOX);
    _butt[i]->selection_color(FL_WHITE);
    _butt[i]->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
  }

  x += 4;
  _label =
    new mainWindowProgress(x, mh + glheight + mheight + 2, width - x - 2, sht);
  _label->box(FL_FLAT_BOX);
  _label->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
  if(CTX::instance()->guiColorScheme)
    _label->color(FL_BACKGROUND_COLOR, FL_LIGHT3);
  else
    _label->color(FL_BACKGROUND_COLOR, FL_DARK2);

  _win->position(CTX::instance()->glPosition[0],
                 CTX::instance()->glPosition[1]);
  _win->end();

  if(main && detachedMenu) {
    _menuwin =
      new mainWindow(CTX::instance()->menuSize[0], CTX::instance()->menuSize[1],
                     CTX::instance()->nonModalWindows ? true : false, "Gmsh");
    _menuwin->callback(file_quit_cb);
    _menuwin->box(GMSH_WINDOW_BOX);
    _onelab = new onelabGroup(0, 0, _menuwin->w(), _menuwin->h());
    _onelab->enableTreeWidgetResize(true);
    _menuwin->position(CTX::instance()->menuPosition[0],
                       CTX::instance()->menuPosition[1]);
    _menuwin->resizable(_onelab);
    _menuwin->size_range(_onelab->getMinWindowWidth(),
                         _onelab->getMinWindowHeight());
    _menuwin->end();
  }
  else {
    _menuwin = nullptr;
  }
}

graphicWindow::~graphicWindow()
{
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
    new mainWindow(_onelab->w(), CTX::instance()->menuSize[1],
                   CTX::instance()->nonModalWindows ? true : false, "Gmsh");
  _menuwin->callback(file_quit_cb);
  _menuwin->box(GMSH_WINDOW_BOX);
  _onelab->box(FL_FLAT_BOX);
  _menuwin->add(_onelab);
  _onelab->resize(0, 0, _menuwin->w(), _menuwin->h());
  _menuwin->position(CTX::instance()->menuPosition[0],
                     CTX::instance()->menuPosition[1]);
  _menuwin->resizable(_onelab);
  _menuwin->size_range(_onelab->getMinWindowWidth(),
                       _onelab->getMinWindowHeight());
  _menuwin->end();
  _menuwin->show();

  _onelab->enableTreeWidgetResize(true);
  _onelab->rebuildTree(true);
}

void graphicWindow::attachMenu()
{
  if(!_menuwin || !_onelab || !_browser) return;
  CTX::instance()->menuSize[1] = _menuwin->h();
  CTX::instance()->menuPosition[0] = _menuwin->x();
  CTX::instance()->menuPosition[1] = _menuwin->y();
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

  _onelab->enableTreeWidgetResize(false);
  _onelab->rebuildTree(true);
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
    int width = CTX::instance()->menuSize[0];
    if(width < FL_NORMAL_SIZE) width = _onelab->getMinWindowWidth();
    int maxw = _win->w();
    if(width > maxw) width = maxw / 2;
    setMenuWidth(width);
    // necessary until resizing of 0-sized groups works
    _onelab->rebuildTree(true);
  }
}

void graphicWindow::hideMenu()
{
  if(_menuwin || !_onelab) return;
  CTX::instance()->menuSize[0] = _onelab->w();
  setMenuWidth(0);
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

int graphicWindow::getMenuPositionX()
{
  if(!_menuwin) return 0;
  return _menuwin->x();
}

int graphicWindow::getMenuPositionY()
{
  if(!_menuwin) return 0;
  return _menuwin->y();
}

bool graphicWindow::split(openglWindow *g, char how, double ratio)
{
  if(_tile->find(g) == _tile->children()) return false; // not found

  if(how == 'u') {
    // after many tries I cannot figure out how to do this cleanly, so let's be
    // brutal :-)
    int mode = g->mode();
    openglWindow::setLastHandled(nullptr);
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

void graphicWindow::setStereo(bool st)
{
  openglWindow::setLastHandled(nullptr);
  for(std::size_t i = 0; i < gl.size(); i++) {
    if(st) { gl[i]->mode(FL_RGB | FL_DEPTH | FL_DOUBLE | FL_STEREO); }
    else {
      gl[i]->mode(FL_RGB | FL_DEPTH | FL_DOUBLE);
    }
    gl[i]->show();
  }
  Msg::Info("new gl window for stereo vision!");
}

void graphicWindow::setAnimButtons(int mode)
{
  if(mode) {
    _butt[7]->callback(status_play_cb);
    _butt[7]->label("@-1gmsh_play");
  }
  else {
    _butt[7]->callback(status_pause_cb);
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
  if(_autoScrollMessages) _browser->bottomline(_browser->size());
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

void graphicWindow::addMessage(const char *msg)
{
  if(!_browser) return;

    // this routine can be called from multiple threads, e.g. via Msg::Info
    // calls in meshGFace(). We should use FlGui::lock/unlock, but currently
    // this does not seem to work (17/02/2017)
#pragma omp critical
  {
    _messages.push_back(msg);
    _browser->add(msg);
    if(_autoScrollMessages && _win->shown() && _browser->h() >= FL_NORMAL_SIZE)
      _browser->bottomline(_browser->size());
  }
}

void graphicWindow::clearMessages()
{
  _messages.clear();
  if(!_browser) return;
  _browser->clear();
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
    const char *c = _browser->text(i);
    if(c[0] == '@')
      fprintf(fp, "%s\n", &c[5]);
    else
      fprintf(fp, "%s\n", c);
  }
  Msg::StatusBar(true, "Done writing '%s'", filename);
  fclose(fp);
}

void graphicWindow::copySelectedMessagesToClipboard()
{
  if(!_browser) return;

  std::string buff;
  for(int i = 1; i <= _browser->size(); i++) {
    if(_browser->selected(i)) {
      const char *c = _browser->text(i);
      if(strlen(c) > 5 && c[0] == '@')
        buff += std::string(&c[5]);
      else
        buff += std::string(c);
      buff += "\n";
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

void graphicWindow::changeMessageFontSize(int incr)
{
  if(!_browser) return;
  setMessageFontSize(_browser->textsize() + incr);
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
  if(CTX::instance()->systemMenuBar) table = sysbar_table;
#endif

  static char recent[10][256];
  for(int i = 0; i < 10; i++) {
    if(i < (int)CTX::instance()->recentFiles.size()) {
      if(check_utf8(CTX::instance()->recentFiles[i]))
        strcpy(recent[i], CTX::instance()->recentFiles[i].c_str());
      else {
        Msg::Info("Ignoring invalid General.RecentFile%d", i);
        strcpy(recent[i], "");
      }
    }
    else
      strcpy(recent[i], "");
    table[4 + i].text = recent[i];
    table[4 + i].user_data_ = (void *)recent[i];
  }

#if defined(__APPLE__)
  if(CTX::instance()->systemMenuBar) _sysbar->menu(table);
#endif
}

typedef struct {
  std::string label;
  Fl_Callback *callback;
  void *arg;
} menuItem;

static menuItem static_modules[] = {
  {"0Modules/Geometry/Elementary entities/Set geometry kernel/Built-in",
   (Fl_Callback *)geometry_elementary_set_factory_cb, (void *)"Built-in"},
  {"0Modules/Geometry/Elementary entities/Set geometry kernel/OpenCASCADE",
   (Fl_Callback *)geometry_elementary_set_factory_cb, (void *)"OpenCASCADE"},
  {"0Modules/Geometry/Elementary entities/Add/Parameter",
   (Fl_Callback *)geometry_elementary_add_new_cb, (void *)"Parameter"},
  {"0Modules/Geometry/Elementary entities/Add/Point",
   (Fl_Callback *)geometry_elementary_add_new_cb, (void *)"Point"},
  {"0Modules/Geometry/Elementary entities/Add/Line",
   (Fl_Callback *)geometry_elementary_add_new_cb, (void *)"Line"},
  {"0Modules/Geometry/Elementary entities/Add/Spline",
   (Fl_Callback *)geometry_elementary_add_new_cb, (void *)"Spline"},
  {"0Modules/Geometry/Elementary entities/Add/Bezier",
   (Fl_Callback *)geometry_elementary_add_new_cb, (void *)"Bezier"},
  {"0Modules/Geometry/Elementary entities/Add/B-Spline",
   (Fl_Callback *)geometry_elementary_add_new_cb, (void *)"BSpline"},
  {"0Modules/Geometry/Elementary entities/Add/Circle",
   (Fl_Callback *)geometry_elementary_add_new_cb, (void *)"Circle"},
  {"0Modules/Geometry/Elementary entities/Add/Circle arc",
   (Fl_Callback *)geometry_elementary_add_new_cb, (void *)"Circle arc"},
  {"0Modules/Geometry/Elementary entities/Add/Ellipse",
   (Fl_Callback *)geometry_elementary_add_new_cb, (void *)"Ellipse"},
  {"0Modules/Geometry/Elementary entities/Add/Ellipse arc",
   (Fl_Callback *)geometry_elementary_add_new_cb, (void *)"Ellipse arc"},
  {"0Modules/Geometry/Elementary entities/Add/Rectangle",
   (Fl_Callback *)geometry_elementary_add_new_cb, (void *)"Rectangle"},
  {"0Modules/Geometry/Elementary entities/Add/Disk",
   (Fl_Callback *)geometry_elementary_add_new_cb, (void *)"Disk"},
  {"0Modules/Geometry/Elementary entities/Add/Plane surface",
   (Fl_Callback *)geometry_elementary_add_new_cb, (void *)"Plane Surface"},
  {"0Modules/Geometry/Elementary entities/Add/Surface filling",
   (Fl_Callback *)geometry_elementary_add_new_cb, (void *)"Surface"},
  {"0Modules/Geometry/Elementary entities/Add/Sphere",
   (Fl_Callback *)geometry_elementary_add_new_cb, (void *)"Sphere"},
  {"0Modules/Geometry/Elementary entities/Add/Cylinder",
   (Fl_Callback *)geometry_elementary_add_new_cb, (void *)"Cylinder"},
  {"0Modules/Geometry/Elementary entities/Add/Box",
   (Fl_Callback *)geometry_elementary_add_new_cb, (void *)"Box"},
  {"0Modules/Geometry/Elementary entities/Add/Torus",
   (Fl_Callback *)geometry_elementary_add_new_cb, (void *)"Torus"},
  {"0Modules/Geometry/Elementary entities/Add/Cone",
   (Fl_Callback *)geometry_elementary_add_new_cb, (void *)"Cone"},
  {"0Modules/Geometry/Elementary entities/Add/Wedge",
   (Fl_Callback *)geometry_elementary_add_new_cb, (void *)"Wedge"},
  {"0Modules/Geometry/Elementary entities/Add/Volume",
   (Fl_Callback *)geometry_elementary_add_new_cb, (void *)"Volume"},
  {"0Modules/Geometry/Elementary entities/Transform/Translate",
   (Fl_Callback *)geometry_elementary_translate_cb},
  {"0Modules/Geometry/Elementary entities/Transform/Rotate",
   (Fl_Callback *)geometry_elementary_rotate_cb},
  {"0Modules/Geometry/Elementary entities/Transform/Scale",
   (Fl_Callback *)geometry_elementary_scale_cb},
  {"0Modules/Geometry/Elementary entities/Transform/Symmetry",
   (Fl_Callback *)geometry_elementary_symmetry_cb},
  {"0Modules/Geometry/Elementary entities/Extrude/Translate",
   (Fl_Callback *)geometry_elementary_extrude_translate_cb},
  {"0Modules/Geometry/Elementary entities/Extrude/Rotate",
   (Fl_Callback *)geometry_elementary_extrude_rotate_cb},
  {"0Modules/Geometry/Elementary entities/Extrude/Pipe",
   (Fl_Callback *)geometry_elementary_pipe_cb},
  {"0Modules/Geometry/Elementary entities/Boolean/Intersection",
   (Fl_Callback *)geometry_elementary_boolean_cb,
   (void *)"BooleanIntersection"},
  {"0Modules/Geometry/Elementary entities/Boolean/Union",
   (Fl_Callback *)geometry_elementary_boolean_cb, (void *)"BooleanUnion"},
  {"0Modules/Geometry/Elementary entities/Boolean/Difference",
   (Fl_Callback *)geometry_elementary_boolean_cb, (void *)"BooleanDifference"},
  {"0Modules/Geometry/Elementary entities/Boolean/Fragments",
   (Fl_Callback *)geometry_elementary_boolean_cb, (void *)"BooleanFragments"},
  {"0Modules/Geometry/Elementary entities/Fillet",
   (Fl_Callback *)geometry_elementary_fillet_cb},
  {"0Modules/Geometry/Elementary entities/Split curve",
   (Fl_Callback *)geometry_elementary_split_cb, (void *)"Curve"},
  {"0Modules/Geometry/Elementary entities/Delete",
   (Fl_Callback *)geometry_elementary_delete_cb},
  {"0Modules/Geometry/Elementary entities/Coherence",
   (Fl_Callback *)geometry_elementary_coherence_cb},
  {"0Modules/Geometry/Physical groups/Add/Point",
   (Fl_Callback *)geometry_physical_add_cb, (void *)"Point"},
  {"0Modules/Geometry/Physical groups/Add/Curve",
   (Fl_Callback *)geometry_physical_add_cb, (void *)"Curve"},
  {"0Modules/Geometry/Physical groups/Add/Surface",
   (Fl_Callback *)geometry_physical_add_cb, (void *)"Surface"},
  {"0Modules/Geometry/Physical groups/Add/Volume",
   (Fl_Callback *)geometry_physical_add_cb, (void *)"Volume"},
  {"0Modules/Geometry/Physical groups/Remove/Point",
   (Fl_Callback *)geometry_physical_remove_cb, (void *)"Point"},
  {"0Modules/Geometry/Physical groups/Remove/Curve",
   (Fl_Callback *)geometry_physical_remove_cb, (void *)"Curve"},
  {"0Modules/Geometry/Physical groups/Remove/Surface",
   (Fl_Callback *)geometry_physical_remove_cb, (void *)"Surface"},
  {"0Modules/Geometry/Physical groups/Remove/Volume",
   (Fl_Callback *)geometry_physical_remove_cb, (void *)"Volume"},
  {"0Modules/Geometry/Reload script", (Fl_Callback *)geometry_reload_cb},
  {"0Modules/Geometry/Remove last script command",
   (Fl_Callback *)geometry_remove_last_command_cb},
  {"0Modules/Geometry/Edit script", (Fl_Callback *)geometry_edit_cb},
#if defined(HAVE_MESH)
  {"0Modules/Mesh/Define/Size at points", (Fl_Callback *)mesh_define_length_cb},
  {"0Modules/Mesh/Define/Size fields", (Fl_Callback *)field_cb},
  {"0Modules/Mesh/Define/Embedded/Point",
   (Fl_Callback *)mesh_define_embedded_cb, (void *)"Point"},
  {"0Modules/Mesh/Define/Embedded/Curve",
   (Fl_Callback *)mesh_define_embedded_cb, (void *)"Curve"},
  {"0Modules/Mesh/Define/Embedded/Surface",
   (Fl_Callback *)mesh_define_embedded_cb, (void *)"Surface"},
  {"0Modules/Mesh/Define/Transfinite/Curve",
   (Fl_Callback *)mesh_define_transfinite_line_cb},
  {"0Modules/Mesh/Define/Transfinite/Surface",
   (Fl_Callback *)mesh_define_transfinite_surface_cb},
  {"0Modules/Mesh/Define/Transfinite/Volume",
   (Fl_Callback *)mesh_define_transfinite_volume_cb},
  {"0Modules/Mesh/Define/Compound/Curve",
   (Fl_Callback *)mesh_define_compound_entity_cb, (void *)"Curve"},
  {"0Modules/Mesh/Define/Compound/Surface",
   (Fl_Callback *)mesh_define_compound_entity_cb, (void *)"Surface"},
  {"0Modules/Mesh/Define/Recombine", (Fl_Callback *)mesh_define_recombine_cb},
  {"0Modules/Mesh/1D", (Fl_Callback *)mesh_1d_cb},
  {"0Modules/Mesh/2D", (Fl_Callback *)mesh_2d_cb},
  {"0Modules/Mesh/3D", (Fl_Callback *)mesh_3d_cb},
  {"0Modules/Mesh/Optimize 3D", (Fl_Callback *)mesh_optimize_cb},
#if defined(HAVE_NETGEN)
  {"0Modules/Mesh/Optimize 3D (Netgen)",
   (Fl_Callback *)mesh_optimize_netgen_cb},
#endif
  {"0Modules/Mesh/Set order 1", (Fl_Callback *)mesh_degree_cb, (void *)1},
  {"0Modules/Mesh/Set order 2", (Fl_Callback *)mesh_degree_cb, (void *)2},
  {"0Modules/Mesh/Set order 3", (Fl_Callback *)mesh_degree_cb, (void *)3},
  {"0Modules/Mesh/High-order tools", (Fl_Callback *)highordertools_cb},
  {"0Modules/Mesh/Refine by splitting", (Fl_Callback *)mesh_refine_cb},
#if defined(HAVE_METIS)
  {"0Modules/Mesh/Partition", (Fl_Callback *)mesh_partition_cb},
  {"0Modules/Mesh/Unpartition", (Fl_Callback *)mesh_unpartition_cb},
#endif
  {"0Modules/Mesh/Smooth 2D", (Fl_Callback *)mesh_smooth_cb},
  {"0Modules/Mesh/Recombine 2D", (Fl_Callback *)mesh_recombine_cb},
  {"0Modules/Mesh/Reclassify 2D", (Fl_Callback *)mesh_classify_cb},
  {"0Modules/Mesh/Experimental/Compute quad layout",
   (Fl_Callback *)mesh_cross_compute_cb},
#if defined(HAVE_METIS)
  {"0Modules/Mesh/Experimental/Convert old partitioning",
   (Fl_Callback *)mesh_convert_old_partitioning_cb},
#endif
  {"0Modules/Mesh/Experimental/Optimize quad topology",
   (Fl_Callback *)mesh_optimize_quad_topo_cb},
  {"0Modules/Mesh/Experimental/Untangle geometry",
   (Fl_Callback *)mesh_untangle_cb},
  {"0Modules/Mesh/Reverse/Elements", (Fl_Callback *)mesh_reverse_parts_cb,
   (void *)"elements"},
  {"0Modules/Mesh/Reverse/Curves", (Fl_Callback *)mesh_reverse_parts_cb,
   (void *)"curves"},
  {"0Modules/Mesh/Reverse/Surfaces", (Fl_Callback *)mesh_reverse_parts_cb,
   (void *)"surfaces"},
  {"0Modules/Mesh/Reverse/Volumes", (Fl_Callback *)mesh_reverse_parts_cb,
   (void *)"volumes"},
  {"0Modules/Mesh/Delete/Elements", (Fl_Callback *)mesh_delete_parts_cb,
   (void *)"elements"},
  {"0Modules/Mesh/Delete/Curves", (Fl_Callback *)mesh_delete_parts_cb,
   (void *)"curves"},
  {"0Modules/Mesh/Delete/Surfaces", (Fl_Callback *)mesh_delete_parts_cb,
   (void *)"surfaces"},
  {"0Modules/Mesh/Delete/Volumes", (Fl_Callback *)mesh_delete_parts_cb,
   (void *)"volumes"},
  {"0Modules/Mesh/Inspect", (Fl_Callback *)mesh_inspect_cb},
  {"0Modules/Mesh/Save", (Fl_Callback *)mesh_save_cb},
#endif
};

void onelabGroup::_addGmshMenus()
{
  _tree->sortorder(FL_TREE_SORT_NONE);

  // add static geometry and mesh module items
  for(std::size_t i = 0; i < sizeof(static_modules) / sizeof(static_modules[0]);
      i++)
    _addMenu(static_modules[i].label, static_modules[i].callback,
             static_modules[i].arg);

  // add dynamic solver module items
  for(int i = 0; i < 5; i++) {
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
