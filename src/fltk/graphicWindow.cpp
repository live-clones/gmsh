// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
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
#include "GuiActions.h"
#include "GuiDialogs.h"
#include "GuiMenus.h"
#include "menuFltk.h"
#include "openglWindow.h"
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
  "Mesh - Wavefront File Format\t*.obj\n"
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

static void file_remote_cb(Fl_Widget *w, void *data)
{
  std::string str((const char *)data);
  std::string arg;
  if(str == "start") {
    // described once, and shown rather than waited for
    Dialog::showRemoteCommand();
    return;
  }
  if(str == "merge") {
    const char *file = fl_input("Merge", "/tmp/data.pos");
    if(!file) return;
    arg = file;
  }
  remoteAction(str, arg);
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
static int _save_visibility(const char *name)
{
  CreateOutputFile(name, FORMAT_VIS);
  return 1;
}
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
static int _save_obj(const char *name)
{
  return genericMeshFileDialog(name, "OBJ Options", FORMAT_OBJ, false, false);
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
  case FORMAT_VIS: return _save_visibility(name);
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
  case FORMAT_OBJ: return _save_obj(name);
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
    {"Geometry - Gmsh Visibility\t*.vis", _save_visibility},
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
    {"Mesh - Wavefront File Format\t*.obj", _save_obj},
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

void file_quit_cb(Fl_Widget *w, void *data)
{
  projectQuit();
}

void file_watch_cb(Fl_Widget *w, void *data)
{
  if(w)
    Dialog::showWatchPattern();
  else
    watchFiles();
}

void help_about_cb(Fl_Widget *w, void *data)
{
  Dialog::show(Dialog::About, -1);
}

void onelab_reload_cb(Fl_Widget *w, void *data)
{
  projectReload();
}

void geometry_reload_cb(Fl_Widget *w, void *data)
{
  geometryReload();
}

void geometry_remove_last_command_cb(Fl_Widget *w, void *data)
{
  geometryRemoveLastCommand();
}

void mesh_save_cb(Fl_Widget *w, void *data)
{
  meshSave();
}

void mesh_1d_cb(Fl_Widget *w, void *data)
{
  meshDimension(1);
}

void mesh_2d_cb(Fl_Widget *w, void *data)
{
  meshDimension(2);
}

void mesh_3d_cb(Fl_Widget *w, void *data)
{
  meshDimension(3);
}

#if defined(HAVE_MESH)

#if defined(HAVE_NETGEN)
#endif

#endif // HAVE_MESH

// The menu description of src/common/GuiMenus.h names these actions rather than
// naming FLTK callbacks, because the file chooser and the windows are the one
// part of a menu entry that is genuinely toolkit business.

void fltkFileAction(const std::string &what)
{
  if(what == "new")
    file_new_cb(nullptr, nullptr);
  else if(what == "open")
    file_open_merge_cb(nullptr, (void *)"open");
  else if(what == "merge")
    file_open_merge_cb(nullptr, (void *)"merge");
  else if(what == "rename")
    file_rename_cb(nullptr, nullptr);
  else if(what == "export")
    file_export_cb(nullptr, nullptr);
  else if(what == "watch")
    Dialog::showWatchPattern();
#if defined(HAVE_ONELAB)
  else if(what == "remote_start")
    file_remote_cb(nullptr, (void *)"start");
  else if(what == "remote_merge")
    file_remote_cb(nullptr, (void *)"merge");
  else if(what == "remote_clear")
    file_remote_cb(nullptr, (void *)"clear");
  else if(what == "remote_stop")
    file_remote_cb(nullptr, (void *)"stop");
#endif
  else
    Msg::Error("Unknown file action '%s'", what.c_str());
}

void fltkWindowAction(const std::string &what)
{
  if(what == "new" || what == "split_h" || what == "split_v" ||
     what == "split_u" || what == "copy")
    file_window_cb(nullptr, (void *)what.c_str());
  else if(what == "attach_detach")
    attach_detach_menu_cb(nullptr, nullptr);
  else if(what == "minimize" || what == "zoom" || what == "fullscreen" ||
          what == "front")
    window_cb(nullptr, (void *)what.c_str());
#if defined(HAVE_3M)
  else if(what == "3m")
    window3M_cb(nullptr, nullptr);
#endif
  else
    Msg::Error("Unknown window action '%s'", what.c_str());
}

// clang-format off

// clang-format on

static graphicWindow *getGraphicWindow(Fl_Widget *w)
{
  if(!w || !w->parent()) return FlGui::instance()->graph[0];
  for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++)
    if(FlGui::instance()->graph[i]->getWindow() == w->parent())
      return FlGui::instance()->graph[i];
  return FlGui::instance()->graph[0];
}

// The views the status bar acts upon are the panes of the graphic window the
// pointer is over, which is what makes this the interface's.
void fltkOrientViews(const std::string &what, bool reverse, bool sync)
{
  std::vector<openglWindow *> gls;
  openglWindow *last = FlGui::instance()->getCurrentOpenglWindow();
  if(last && last->parent())
    gls = getGraphicWindow(last->parent())->gl;
  else if(last)
    gls.push_back(last);

  for(std::size_t i = 0; i < gls.size(); i++) {
    drawContext *ctx = gls[i]->getDrawContext();
    // Control makes the other views follow the first instead of being
    // oriented themselves; that part stays here, being about the list of
    // views, which is ours
    if(sync && (what == "r" || what == "1:1")) {
      if(i == 0) continue;
      drawContext *first = gls[0]->getDrawContext();
      if(what == "r")
        ctx->setQuaternion(first->quaternion[0], first->quaternion[1],
                           first->quaternion[2], first->quaternion[3]);
      else if(!CTX::instance()->camera) {
        for(int j = 0; j < 3; j++) {
          ctx->t[j] = first->t[j];
          ctx->s[j] = first->s[j];
        }
      }
      continue;
    }
    viewSetOrientation(ctx, what, reverse);
  }
  drawContext::global()->draw();
}

void status_options_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string what((const char *)data);

  if(what == "?") { // display options
    Dialog::show(Dialog::CurrentOptions, -1);
  }
  else if(what == "p") { // toggle projection mode
    opt_general_orthographic(0, GMSH_SET | GMSH_GUI,
                             !opt_general_orthographic(0, GMSH_GET, 0));
    drawContext::global()->draw();
  }
}

// Picking with the mouse, on or off. Turning it off puts the pointer back to
// what it was: it is the interface that has the pointers, which is why
// Gui::setMouseSelection() comes here.
void fltkSetMouseSelection(bool on)
{
  opt_general_mouse_selection(0, GMSH_SET | GMSH_GUI, on ? 1 : 0);
  if(!on)
    for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++)
      for(std::size_t j = 0; j < FlGui::instance()->graph[i]->gl.size(); j++)
        FlGui::instance()->graph[i]->gl[j]->cursor(FL_CURSOR_DEFAULT, FL_BLACK,
                                                   FL_WHITE);
  for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++)
    FlGui::instance()->graph[i]->refreshStatusButtons();
}

// While the animation plays, the FLTK interface runs a loop of its own and
// pumps the events itself; Gui::toggleAnimation() starts and stops it.
static bool stop_anim = false;
static bool playing_anim = false;

bool fltkAnimating() { return playing_anim; }

void fltkToggleAnimation()
{
  if(playing_anim) {
    stop_anim = true;
    return;
  }
  playing_anim = true;
  stop_anim = false;
  double last = TimeOfDay();
  while(1) {
    if(!FlGui::available()) return;
    if(stop_anim) break;
    if(TimeOfDay() - last > CTX::instance()->post.animDelay) {
      last = TimeOfDay();
      animationStep(!CTX::instance()->post.animCycle,
                    CTX::instance()->post.animStep);
    }
    FlGui::check();
  }
  playing_anim = false;
  for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++)
    FlGui::instance()->graph[i]->refreshStatusButtons();
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
      _sysbar->menu(fltkMenuBuild(true));
      _sysbar->global();
    }
    else {
#endif
      _bar = new menuBarFltk(0, 0, width, BH);
      _bar->menu(fltkMenuBuild(false));
      _bar->global();
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

  // The buttons, as src/common/GuiStatus.h describes them: what they say,
  // what they do, and what they say about themselves. They used to be twelve
  // of them built here by hand, indexed in the order they happened to be
  // declared rather than the order they are drawn in.
  {
    std::vector<StatusBar::Button> wanted = StatusBar::bar();
    for(const auto &b : wanted) {
      if(b.gapBefore) x += 4;
      int bw = b.widthEm > 0. ? (int)(b.widthEm * FL_NORMAL_SIZE) : sw;
      statusButtonFltk *button =
        new statusButtonFltk(x, mh + glheight + mheight + 2, bw, sht);
      button->what = b;
      button->copy_label(button->shown().c_str());
      button->copy_tooltip(b.tooltip.c_str());
      if(b.action) {
        // Shift and Control are read when it is pressed, not described: what
        // they mean is the button's business
        button->callback(
          [](Fl_Widget *w, void *) {
            statusButtonFltk *b = (statusButtonFltk *)w;
            if(b->what.action)
              b->what.action(Fl::event_state(FL_SHIFT) ? true : false,
                             Fl::event_state(FL_CTRL) ||
                               Fl::event_state(FL_META));
          },
          nullptr);
      }
      button->box(FL_FLAT_BOX);
      button->selection_color(FL_WHITE);
      button->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
      _butt.push_back(button);
      x += bw;
    }
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

void graphicWindow::refreshStatusButtons()
{
  for(auto *b : _butt) b->refresh();
}

// What a button of the status bar is worth right now, asked of the description
// rather than remembered: an option changed from a script cannot leave it
// showing the wrong thing.
void statusButtonFltk::refresh()
{
  std::string text = shown();
  if(!label() || text != label()) copy_label(text.c_str());
  bool enabled = what.enabled ? what.enabled() : true;
  if(enabled != (active() ? true : false)) {
    if(enabled)
      activate();
    else
      deactivate();
  }
  // it is worth looking at: red, as the bar this reproduces paints the one
  // that says the mouse does not pick
  Fl_Color want = (what.alert && what.alert()) ? FL_RED : FL_BACKGROUND_COLOR;
  if(color() != want) color(want);
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
#pragma omp critical(addMessage)
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

void graphicWindow::fillRecentHistoryMenu()
{
  // the recent files are read while the menu description is built, so there is
  // nothing to patch in place any more: the menu is simply built again
  Menu::invalidate();
#if defined(__APPLE__)
  if(CTX::instance()->systemMenuBar) {
    if(_sysbar) _sysbar->menu(fltkMenuBuild(true));
    return;
  }
#endif
  if(_bar) _bar->menu(fltkMenuBuild(false));
}


void onelabGroup::_addGmshMenus()
{
  _tree->sortorder(FL_TREE_SORT_NONE);

  // the static geometry and mesh items, from the shared description
  fltkModulesBuild([this](const std::string &path, Fl_Callback *cb, void *data) {
    _addMenu(path, cb, data);
  });

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
