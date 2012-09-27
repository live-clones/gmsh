// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GmshConfig.h"
#if !defined(HAVE_NO_STDINT_H)
#include <stdint.h>
#elif defined(HAVE_NO_INTPTR_T)
typedef unsigned long intptr_t;
#endif
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <FL/Fl_Box.H>
#include <FL/fl_ask.H>
#include <FL/filename.H>
#include "GmshMessage.h"
#include "GmshSocket.h"
#include "FlGui.h"
#include "menuWindow.h"
#include "mainWindow.h"
#include "graphicWindow.h"
#include "optionWindow.h"
#include "statisticsWindow.h"
#include "contextWindow.h"
#include "visibilityWindow.h"
#include "highOrderToolsWindow.h"
#include "clippingWindow.h"
#include "manipWindow.h"
#include "fieldWindow.h"
#include "pluginWindow.h"
#include "aboutWindow.h"
#include "onelabWindow.h"
#include "fileDialogs.h"
#include "extraDialogs.h"
#include "partitionDialog.h"
#include "projectionEditor.h"
#include "classificationEditor.h"
#include "Options.h"
#include "CommandLine.h"
#include "GModel.h"
#include "PView.h"
#include "PViewData.h"
#include "PViewOptions.h"
#include "OS.h"
#include "StringUtils.h"
#include "OpenFile.h"
#include "CreateFile.h"
#include "findLinks.h"
#include "GeoStringInterface.h"
#include "Options.h"
#include "Context.h"
#include "Generator.h"
#include "HighOrder.h"
#include "Field.h"
#if defined(HAVE_ONELAB)
#include "onelab.h"
#endif
#if defined(HAVE_3M)
#include "3M.h"
#endif

static void file_new_cb(Fl_Widget *w, void *data)
{
 test:
  if(fileChooser(FILE_CHOOSER_CREATE, "New", "",
                 GModel::current()->getFileName().c_str())) {
    std::string name = fileChooserGetName(1);
    if(!StatFile(name)){
      if(fl_choice("File '%s' already exists.\n\nDo you want to erase it?",
                   "Cancel", "Erase", 0, name.c_str()))
        UnlinkFile(name);
      else
        goto test;
    }
    FILE *fp = fopen(name.c_str(), "w");
    if(!fp){
      Msg::Error("Unable to open file '%s'", name.c_str());
      return;
    }
    time_t now;
    time(&now);
    fprintf(fp, "// Gmsh project created on %s", ctime(&now));
    fclose(fp);
    OpenProject(name);
    drawContext::global()->draw();
  }
}

#if defined(HAVE_NATIVE_FILE_CHOOSER)
#  define TT "\t"
#  define NN "\n"
#else
#  define TT " ("
#  define NN ")\t"
#endif

static const char *input_formats =
  "All Files" TT "*.*" NN
  "Geometry - Gmsh GEO" TT "*.geo" NN
#if defined(HAVE_ACIS)
  "Geometry - ACIS" TT "*.sat" NN
#endif
#if defined(HAVE_OCC)
  "Geometry - OpenCASCADE BRep" TT "*.brep" NN
  "Geometry - OpenCASCADE IGES" TT "*.{igs,iges}" NN
  "Geometry - OpenCASCADE STEP" TT "*.{stp,step}" NN
#endif
  "Mesh - Gmsh MSH" TT "*.msh" NN
  "Mesh - Diffpack 3D" TT "*.diff" NN
  "Mesh - I-deas Universal" TT "*.unv" NN
#if defined(HAVE_MED)
  "Mesh - MED" TT "*.{med,mmed}" NN
#endif
  "Mesh - INRIA Medit" TT "*.mesh" NN
  "Mesh - Nastran Bulk Data File" TT "*.{bdf,nas}" NN
  "Mesh - Plot3D Structured Mesh" TT "*.p3d" NN
  "Mesh - STL Surface" TT "*.stl" NN
  "Mesh - VTK" TT "*.vtk" NN
  "Mesh - VRML Surface" TT "*.{wrl,vrml}" NN
  "Mesh - PLY2 Surface" TT "*.ply2" NN
  "Post-processing - Gmsh POS" TT "*.pos" NN
#if defined(HAVE_MED)
  "Post-processing - MED" TT "*.{rmed}" NN
#endif
  "Image - BMP" TT "*.bmp" NN
#if defined(HAVE_LIBJPEG)
  "Image - JPEG" TT "*.{jpg,jpeg}" NN
#endif
  "Image - PBM" TT "*.pbm" NN
  "Image - PGM" TT "*.pgm" NN
#if defined(HAVE_LIBPNG)
  "Image - PNG" TT "*.png" NN
#endif
  "Image - PNM" TT "*.pnm" NN
  "Image - PPM" TT "*.ppm" NN;

static void file_open_cb(Fl_Widget *w, void *data)
{
  int n = PView::list.size();
  if(fileChooser(FILE_CHOOSER_SINGLE, "Open", input_formats,
                 GModel::current()->getFileName().c_str())) {
    OpenProject(fileChooserGetName(1));
    drawContext::global()->draw();
  }
  if(n != (int)PView::list.size())
    FlGui::instance()->menu->setContext(menu_post, 0);
}

static void file_merge_cb(Fl_Widget *w, void *data)
{
  int n = PView::list.size();
  int f = fileChooser(FILE_CHOOSER_MULTI, "Merge", input_formats,
                      GModel::current()->getFileName().c_str());
  if(f) {
    for(int i = 1; i <= f; i++)
      MergeFile(fileChooserGetName(i));
    drawContext::global()->draw();
  }
  if(n != (int)PView::list.size())
    FlGui::instance()->menu->setContext(menu_post, 0);
}

static void file_open_recent_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string str((const char*)data);
  int n = PView::list.size();
  OpenProject(str);
  drawContext::global()->draw();
  if(n != (int)PView::list.size())
    FlGui::instance()->menu->setContext(menu_post, 0);
}

static void file_clear_cb(Fl_Widget *w, void *data)
{
  ClearProject();
  drawContext::global()->draw();
}

static void file_remote_cb(Fl_Widget *w, void *data)
{
#if defined(HAVE_ONELAB)
  onelab::localNetworkClient *c;
  onelab::server::citer it = onelab::server::instance()->findClient("GmshRemote");
  if(it == onelab::server::instance()->lastClient()){
    c = new onelab::localNetworkClient("GmshRemote", "");
    c->setSocketSwitch("-socket");
  }
  else
    c = (onelab::localNetworkClient*)it->second;
  GmshServer *server = c->getGmshServer();

  std::string str((const char*)data);

  if(str == "start"){
    if(server){
      Msg::Error("Cannot start: remote Gmsh is already running");
      return;
    }
    c->setExecutable(connectionChooser());
    if(c->getExecutable().size()) c->run();
  }
  else{
    if(!server){
      Msg::Error("Cannot %s: remote Gmsh not running", str.c_str());
      return;
    }
    if(str == "stop"){
      server->SendString(GmshSocket::GMSH_STOP, "Disconnect!");
    }
    else if(str == "merge"){
      const char *file = fl_input("Merge", "/tmp/data.pos");
      if(file) server->SendString(GmshSocket::GMSH_MERGE_FILE, file);
    }
    else if(str == "clear"){
      server->SendString(GmshSocket::GMSH_PARSE_STRING, "Delete All;");
      for(int i = PView::list.size() - 1; i >= 0; i--)
        if(PView::list[i]->getData()->isRemote()) delete PView::list[i];
      FlGui::instance()->updateViews();
      drawContext::global()->draw();
    }
    else if(str == "test"){
      server->SendString(GmshSocket::GMSH_SPEED_TEST, "Speed test");
    }
  }
#endif
}

static void file_window_cb(Fl_Widget *w, void *data)
{
  std::string str((const char*)data);
  if(str == "new"){
    graphicWindow *g1 = FlGui::instance()->graph.back();
    graphicWindow *g2 = new graphicWindow(false, CTX::instance()->numTiles);
    FlGui::instance()->graph.push_back(g2);
    FlGui::instance()->setGraphicTitle(GModel::current()->getFileName());
    g2->win->resize(g1->win->x() + 10, g1->win->y() + 10,
                    g1->win->w(), g1->win->h());
    g2->win->show();
  }
  else if(str == "split_h"){
    FlGui::instance()->splitCurrentOpenglWindow('h');
  }
  else if(str == "split_v"){
    FlGui::instance()->splitCurrentOpenglWindow('v');
  }
  else if(str == "split_u"){
    FlGui::instance()->splitCurrentOpenglWindow('u');
  }
  drawContext::global()->draw();
}

static int _save_msh(const char *name){ return mshFileDialog(name); }
static int _save_mesh_stat(const char *name){ return meshStatFileDialog(name); }
static int _save_options(const char *name){ return optionsFileDialog(name); }
static int _save_geo(const char *name){ return geoFileDialog(name); }
static int _save_brep(const char *name){ CreateOutputFile(name, FORMAT_BREP); return 1; }
static int _save_step(const char *name){ CreateOutputFile(name, FORMAT_STEP); return 1; }
static int _save_cgns(const char *name){ return cgnsFileDialog(name); }
static int _save_unv(const char *name){ return unvFileDialog(name); }
static int _save_vtk(const char *name){ return genericMeshFileDialog
    (name, "VTK Options", FORMAT_VTK, true, false); }
static int _save_diff(const char *name){ return genericMeshFileDialog
    (name, "Diffpack Options", FORMAT_DIFF, true, false); }
static int _save_inp(const char *name){ return genericMeshFileDialog
    (name, "Abaqus INP Options", FORMAT_INP, false, false); }
static int _save_med(const char *name){ return genericMeshFileDialog
    (name, "MED Options", FORMAT_MED, false, false); }
static int _save_mesh(const char *name){ return genericMeshFileDialog
    (name, "MESH Options", FORMAT_MESH, false, true); }
static int _save_mail(const char *name){ return genericMeshFileDialog
    (name, "MAIL Options", FORMAT_MAIL, false, false); }
static int _save_bdf(const char *name){ return bdfFileDialog(name); }
static int _save_p3d(const char *name){ return genericMeshFileDialog
    (name, "P3D Options", FORMAT_P3D, false, false); }
static int _save_ir3(const char *name){ return genericMeshFileDialog
    (name, "Iridium Options", FORMAT_IR3, false, true); }
static int _save_stl(const char *name){ return genericMeshFileDialog
    (name, "STL Options", FORMAT_STL, true, false); }
static int _save_vrml(const char *name){ return genericMeshFileDialog
    (name, "VRML Options", FORMAT_VRML, false, false); }
static int _save_ply2(const char *name){ return genericMeshFileDialog
    (name, "PLY2 Options", FORMAT_PLY2, false, false); }
static int _save_eps(const char *name){ return gl2psFileDialog
    (name, "EPS Options", FORMAT_EPS); }
static int _save_gif(const char *name){ return gifFileDialog(name); }
static int _save_jpeg(const char *name){ return jpegFileDialog(name); }
static int _save_mpeg(const char *name){ return mpegFileDialog(name); }
static int _save_tex(const char *name){ return latexFileDialog(name); }
static int _save_pdf(const char *name){ return gl2psFileDialog
    (name, "PDF Options", FORMAT_PDF); }
static int _save_png(const char *name){ return genericBitmapFileDialog
    (name, "PNG Options", FORMAT_PNG); }
static int _save_ps(const char *name){ return gl2psFileDialog
    (name, "PS Options", FORMAT_PS); }
static int _save_ppm(const char *name){ return genericBitmapFileDialog
    (name, "PPM Options", FORMAT_PPM); }
static int _save_svg(const char *name){ return gl2psFileDialog
    (name, "SVG Options", FORMAT_SVG); }
static int _save_yuv(const char *name){ return genericBitmapFileDialog
    (name, "YUV Options", FORMAT_YUV); }
static int _save_view_pos(const char *name){ return posFileDialog(name); }
static int _save_view_med(const char *name){ return genericViewFileDialog
    (name, "MED Options", 6); }
static int _save_view_txt(const char *name){ return genericViewFileDialog
    (name, "TXT Options", 4); }

static int _save_auto(const char *name)
{
  switch(GuessFileFormatFromFileName(name)){
  case FORMAT_MSH  : return _save_msh(name);
  case FORMAT_POS  : return _save_view_pos(name);
  case FORMAT_TXT  : return _save_view_txt(name);
  case FORMAT_OPT  : return _save_options(name);
  case FORMAT_GEO  : return _save_geo(name);
  case FORMAT_BREP : return _save_brep(name);
  case FORMAT_STEP : return _save_step(name);
  case FORMAT_CGNS : return _save_cgns(name);
  case FORMAT_UNV  : return _save_unv(name);
  case FORMAT_VTK  : return _save_vtk(name);
  case FORMAT_MED  : return _save_med(name);
  case FORMAT_RMED : return _save_view_med(name);
  case FORMAT_MESH : return _save_mesh(name);
  case FORMAT_MAIL : return _save_mail(name);
  case FORMAT_BDF  : return _save_bdf(name);
  case FORMAT_DIFF : return _save_diff(name);
  case FORMAT_INP  : return _save_inp(name);
  case FORMAT_P3D  : return _save_p3d(name);
  case FORMAT_IR3  : return _save_ir3(name);
  case FORMAT_STL  : return _save_stl(name);
  case FORMAT_VRML : return _save_vrml(name);
  case FORMAT_PLY2 : return _save_ply2(name);
  case FORMAT_EPS  : return _save_eps(name);
  case FORMAT_GIF  : return _save_gif(name);
  case FORMAT_JPEG : return _save_jpeg(name);
  case FORMAT_MPEG : return _save_mpeg(name);
  case FORMAT_TEX  : return _save_tex(name);
  case FORMAT_PDF  : return _save_pdf(name);
  case FORMAT_PNG  : return _save_png(name);
  case FORMAT_PS   : return _save_ps(name);
  case FORMAT_PPM  : return _save_ppm(name);
  case FORMAT_SVG  : return _save_svg(name);
  case FORMAT_YUV  : return _save_yuv(name);
  default :
    CreateOutputFile(name, FORMAT_AUTO);
    return 1;
  }
}

typedef struct{
  const char *pat;
  int (*func) (const char *name);
} patXfunc;

static void file_save_as_cb(Fl_Widget *w, void *data)
{
  static patXfunc formats[] = {
    {"Guess From Extension" TT "*.*", _save_auto},
    {"Geometry - Gmsh Options" TT "*.opt", _save_options},
    {"Geometry - Gmsh Unrolled GEO" TT "*.geo", _save_geo},
#if defined(HAVE_OCC)
    {"Geometry - OpenCASCADE STEP" TT "*.step", _save_step},
    {"Geometry - OpenCASCADE BRep" TT "*.brep", _save_brep},
#endif
    {"Mesh - Gmsh MSH" TT "*.msh", _save_msh},
    {"Mesh - Abaqus INP" TT "*.inp", _save_inp},
#if defined(HAVE_LIBCGNS)
    {"Mesh - CGNS (Experimental)" TT "*.cgns", _save_cgns},
#endif
    {"Mesh - Diffpack 3D" TT "*.diff", _save_diff},
    {"Mesh - I-deas Universal" TT "*.unv", _save_unv},
    {"Mesh - Iridum" TT "*.ir3", _save_ir3},
#if defined(HAVE_MED)
    {"Mesh - MED" TT "*.med", _save_med},
#endif
    {"Mesh - INRIA Medit" TT "*.mesh", _save_mesh},
    {"Mesh - CEA Triangulation" TT "*.mail", _save_mail},
    {"Mesh - Nastran Bulk Data File" TT "*.bdf", _save_bdf},
    {"Mesh - Plot3D Structured Mesh" TT "*.p3d", _save_p3d},
    {"Mesh - STL Surface" TT "*.stl", _save_stl},
    {"Mesh - VRML Surface" TT "*.wrl", _save_vrml},
    {"Mesh - VTK" TT "*.vtk", _save_vtk},
    {"Mesh - PLY2 Surface" TT "*.ply2", _save_ply2},
    {"Post-processing - Gmsh POS" TT "*.pos", _save_view_pos},
#if defined(HAVE_MED)
    {"Post-processing - MED" TT "*.rmed", _save_view_med},
#endif
    {"Post-processing - Generic TXT" TT "*.txt", _save_view_txt},
    {"Post-processing - Mesh Statistics" TT "*.pos", _save_mesh_stat},
    {"Image - Encapsulated PostScript" TT "*.eps", _save_eps},
    {"Image - GIF" TT "*.gif", _save_gif},
#if defined(HAVE_LIBJPEG)
    {"Image - JPEG" TT "*.jpg", _save_jpeg},
#endif
    {"Image - LaTeX" TT "*.tex", _save_tex},
    {"Image - PDF" TT "*.pdf", _save_pdf},
#if defined(HAVE_LIBPNG)
    {"Image - PNG" TT "*.png", _save_png},
#endif
    {"Image - PostScript" TT "*.ps", _save_ps},
    {"Image - PPM" TT "*.ppm", _save_ppm},
    {"Image - SVG" TT "*.svg", _save_svg},
    {"Image - YUV" TT "*.yuv", _save_yuv},
#if defined(HAVE_MPEG_ENCODE)
    {"Movie - MPEG" TT "*.mpg", _save_mpeg},
#endif
  };
  int nbformats = sizeof(formats) / sizeof(formats[0]);
  static char *pat = 0;
  if(!pat) {
    pat = new char[nbformats * 256];
    strcpy(pat, formats[0].pat);
    for(int i = 1; i < nbformats; i++) {
      strcat(pat, NN);
      strcat(pat, formats[i].pat);
    }
  }

 test:
  if(fileChooser(FILE_CHOOSER_CREATE, "Save As", pat,
                 GModel::current()->getFileName().c_str())) {
    std::string name = fileChooserGetName(1);
    if(CTX::instance()->confirmOverwrite) {
      if(!StatFile(name))
        if(!fl_choice("File '%s' already exists.\n\nDo you want to replace it?",
                      "Cancel", "Replace", 0, name.c_str()))
          goto test;
    }
    int i = fileChooserGetFilter();
    if(i >= 0 && i < nbformats){
      if(!formats[i].func(name.c_str())) goto test;
    }
    else{ // handle any additional automatic fltk filter
      if(!_save_auto(name.c_str())) goto test;
    }
  }
}

static void file_options_save_cb(Fl_Widget *w, void *data)
{
  std::string str((const char*)data), fileName;
  if(str == "file")
    fileName = GModel::current()->getFileName() + ".opt";
  else
    fileName = CTX::instance()->homeDir + CTX::instance()->optionsFileName;
  Msg::StatusBar(2, true, "Writing '%s'...", fileName.c_str());
  if(str == "file")
    PrintOptions(0, GMSH_FULLRC, 1, 0, fileName.c_str());
  else
    PrintOptions(0, GMSH_OPTIONSRC, 1, 1, fileName.c_str());
  Msg::StatusBar(2, true, "Done writing '%s'", fileName.c_str());
}

static void file_rename_cb(Fl_Widget *w, void *data)
{
 test:
  if(fileChooser(FILE_CHOOSER_CREATE, "Rename", "",
                 GModel::current()->getFileName().c_str())) {
    std::string name = fileChooserGetName(1);
    if(CTX::instance()->confirmOverwrite) {
      if(!StatFile(name))
        if(!fl_choice("File '%s' already exists.\n\nDo you want to replace it?",
                      "Cancel", "Replace", 0, name.c_str()))
          goto test;
    }
    rename(GModel::current()->getFileName().c_str(), name.c_str());
    GModel::current()->setFileName(name);
    GModel::current()->setName(SplitFileName(name)[1]);
    FlGui::instance()->setGraphicTitle(GModel::current()->getFileName());
    drawContext::global()->draw();
  }
}

void file_quit_cb(Fl_Widget *w, void *data)
{
  Msg::Exit(0);
}

void file_watch_cb(Fl_Widget *w, void *data)
{
  if(w) CTX::instance()->watchFilePattern = patternChooser();

  if(CTX::instance()->watchFilePattern.empty()) return;

  std::string pattern = FixRelativePath
    (GModel::current()->getFileName(), CTX::instance()->watchFilePattern);
  std::string directory = SplitFileName(pattern)[0];
  if(directory.empty()) directory = "./";

  dirent **files = 0;
  int num = fl_filename_list(directory.c_str(), &files, fl_numericsort);
  if(num <= 0) return;
  std::vector<std::string> matches;
  for (int i = 0; i < num; i++) {
    std::string name = directory + files[i]->d_name;
    if(fl_filename_match(name.c_str(), pattern.c_str()))
      matches.push_back(name);
    free((void*)files[i]);
  }
  if(files) free((void*)files);

  Msg::Info("%d match%s for pattern '%s'", (int)matches.size(),
            (matches.size() > 1) ? "es" : "", pattern.c_str());

  std::set<std::string> allFiles;
  for(unsigned int i = 0; i < GModel::list.size(); i++)
    allFiles.insert(GetFileNameWithoutPath(GModel::list[i]->getFileName()));
  for(unsigned int i = 0; i < PView::list.size(); i++)
    for(int j = 0; j < PView::list[i]->getData()->getNumTimeSteps(); j++)
      allFiles.insert(GetFileNameWithoutPath(PView::list[i]->getData()->getFileName(j)));

  for(unsigned int i = 0; i < matches.size(); i++)
    if(allFiles.find(GetFileNameWithoutPath(matches[i])) == allFiles.end())
      MergeFile(matches[i]);
  drawContext::global()->draw();
}

#if defined(__APPLE__)
#  define CC(str) "Cmd+" str " "
#else
#  define CC(str) "Ctrl+" str
#endif

static void help_short_cb(Fl_Widget *w, void *data)
{
  Msg::Direct(" ");
  Msg::Direct("Keyboard shortcuts:");
  Msg::Direct(" ");
  Msg::Direct("  Left arrow    Go to previous time step");
  Msg::Direct("  Right arrow   Go to next time step");
  Msg::Direct("  Up arrow      Make previous view visible");
  Msg::Direct("  Down arrow    Make next view visible");
  Msg::Direct(" ");
  Msg::Direct("  <             Go back to previous context");
  Msg::Direct("  >             Go forward to next context");
  Msg::Direct("  0             Reload project file");
  Msg::Direct("  1 or F1       Mesh lines");
  Msg::Direct("  2 or F2       Mesh surfaces");
  Msg::Direct("  3 or F3       Mesh volumes");
  Msg::Direct("  Escape        Cancel lasso zoom/selection, toggle mouse selection ON/OFF");
  Msg::Direct(" ");
  Msg::Direct("  g             Go to geometry module");
  Msg::Direct("  m             Go to mesh module");
  Msg::Direct("  p             Go to post-processing module");
  Msg::Direct("  s             Go to solver module");
  Msg::Direct(" ");
  Msg::Direct("  Shift+a       Bring all windows to front");
  Msg::Direct("  Shift+g       Show geometry options");
  Msg::Direct("  Shift+m       Show mesh options");
  Msg::Direct("  Shift+o       Show general options");
  Msg::Direct("  Shift+p       Show post-processing options");
  Msg::Direct("  Shift+s       Show solver options");
  Msg::Direct("  Shift+u       Show post-processing view plugins");
  Msg::Direct("  Shift+w       Show post-processing view options");
  Msg::Direct("  Shift+Escape  Enable full mouse selection");
  Msg::Direct(" ");
  Msg::Direct("  " CC("i") "        Show statistics window");
  Msg::Direct("  " CC("l") "        Show message console");
#if defined(__APPLE__)
  Msg::Direct("  " CC("m") "        Minimize window");
#endif
  Msg::Direct("  " CC("n") "        Create new project file");
  Msg::Direct("  " CC("o") "        Open project file");
  Msg::Direct("  " CC("q") "        Quit");
  Msg::Direct("  " CC("r") "        Rename project file");
  Msg::Direct("  " CC("s") "        Save file as");
  Msg::Direct(" ");
  Msg::Direct("  Shift+" CC("c") "  Show clipping plane window");
  Msg::Direct("  Shift+" CC("m") "  Show manipulator window");
  Msg::Direct("  Shift+" CC("n") "  Show option window");
  Msg::Direct("  Shift+" CC("o") "  Merge file(s)");
  Msg::Direct("  Shift+" CC("s") "  Save mesh in default format");
  Msg::Direct("  Shift+" CC("u") "  Show plugin window");
  Msg::Direct("  Shift+" CC("v") "  Show visibility window");
  Msg::Direct(" ");
  Msg::Direct("  Alt+a         Loop through axes modes");
  Msg::Direct("  Alt+b         Hide/show bounding boxes");
  Msg::Direct("  Alt+c         Loop through predefined color schemes");
  Msg::Direct("  Alt+e         Hide/Show element outlines for visible post-pro views");
  Msg::Direct("  Alt+f         Change redraw mode (fast/full)");
  Msg::Direct("  Alt+h         Hide/show all post-processing views");
  Msg::Direct("  Alt+i         Hide/show all post-processing view scales");
  Msg::Direct("  Alt+l         Hide/show geometry lines");
  Msg::Direct("  Alt+m         Toggle visibility of all mesh entities");
  Msg::Direct("  Alt+n         Hide/show all post-processing view annotations");
  Msg::Direct("  Alt+o         Change projection mode (orthographic/perspective)");
  Msg::Direct("  Alt+p         Hide/show geometry points");
  Msg::Direct("  Alt+r         Loop through range modes for visible post-pro views");
  Msg::Direct("  Alt+s         Hide/show geometry surfaces");
  Msg::Direct("  Alt+t         Loop through interval modes for visible post-pro views");
  Msg::Direct("  Alt+v         Hide/show geometry volumes");
  Msg::Direct("  Alt+w         Enable/disable all lighting");
  Msg::Direct("  Alt+x         Set X view");
  Msg::Direct("  Alt+y         Set Y view");
  Msg::Direct("  Alt+z         Set Z view");
  Msg::Direct(" ");
  Msg::Direct("  Alt+Shift+a   Hide/show small axes");
  Msg::Direct("  Alt+Shift+b   Hide/show mesh volume faces");
  Msg::Direct("  Alt+Shift+d   Hide/show mesh surface faces");
  Msg::Direct("  Alt+Shift+l   Hide/show mesh lines");
  Msg::Direct("  Alt+Shift+o   Adjust projection parameters");
  Msg::Direct("  Alt+Shift+p   Hide/show mesh points");
  Msg::Direct("  Alt+Shift+s   Hide/show mesh surface edges");
  Msg::Direct("  Alt+Shift+v   Hide/show mesh volume edges");
  Msg::Direct("  Alt+Shift+w   Reverse all mesh normals");
  Msg::Direct("  Alt+Shift+x   Set -X view");
  Msg::Direct("  Alt+Shift+y   Set -Y view");
  Msg::Direct("  Alt+Shift+z   Set -Z view");
  Msg::Direct(" ");
  FlGui::instance()->showMessages();
}

#undef CC

static void help_mouse_cb(Fl_Widget *w, void *data)
{
  Msg::Direct(" ");
  Msg::Direct("Mouse actions:");
  Msg::Direct(" ");
  Msg::Direct("  Move                - Highlight the entity under the mouse pointer");
  Msg::Direct("                        and display its properties in the status bar");
  Msg::Direct("                      - Resize a lasso zoom or a lasso (un)selection");
  Msg::Direct("  Left button         - Rotate");
  Msg::Direct("                      - Select an entity");
  Msg::Direct("                      - Accept a lasso zoom or a lasso selection");
  Msg::Direct("  Ctrl+Left button    Start a lasso zoom or a lasso (un)selection");
  Msg::Direct("  Middle button       - Zoom");
  Msg::Direct("                      - Unselect an entity");
  Msg::Direct("                      - Accept a lasso zoom or a lasso unselection");
  Msg::Direct("  Ctrl+Middle button  Orthogonalize display");
  Msg::Direct("  Right button        - Pan");
  Msg::Direct("                      - Cancel a lasso zoom or a lasso (un)selection");
  Msg::Direct("                      - Pop-up menu on post-processing view button");
  Msg::Direct("  Ctrl+Right button   Reset to default viewpoint");
  Msg::Direct(" ");
  Msg::Direct("  For a 2 button mouse, Middle button = Shift+Left button");
  Msg::Direct("  For a 1 button mouse, Middle button = Shift+Left button, "
              "Right button = Alt+Left button");
  Msg::Direct(" ");
  FlGui::instance()->showMessages();
}

static void help_command_line_cb(Fl_Widget *w, void *data)
{
  Msg::Direct(" ");
  PrintUsage("gmsh");
  FlGui::instance()->showMessages();
}

static void help_online_cb(Fl_Widget *w, void *data)
{
  std::string prog = FixWindowsPath(CTX::instance()->webBrowser);
  SystemCall(ReplaceSubString("%s", "http://geuz.org/gmsh/doc/texinfo/", prog));
}

void help_about_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->about->win->show();
}

void mod_geometry_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->menu->setContext(menu_geometry, 0);
}

void mod_mesh_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->menu->setContext(menu_mesh, 0);
}

void mod_solver_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->menu->setContext(menu_solver, 0);
}

void mod_post_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->menu->setContext(menu_post, 0);
}

void mod_back_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->menu->setContext(0, -1);
}

void mod_forward_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->menu->setContext(0, 1);
}

static void geometry_elementary_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->menu->setContext(menu_geometry_elementary, 0);
}

static void geometry_physical_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->menu->setContext(menu_geometry_physical, 0);
}

static void geometry_edit_cb(Fl_Widget *w, void *data)
{
  std::string prog = FixWindowsPath(CTX::instance()->editor);
  std::string file = FixWindowsPath(GModel::current()->getFileName());
  SystemCall(ReplaceSubString("%s", file, prog));
}

void geometry_reload_cb(Fl_Widget *w, void *data)
{
  std::string fileName = GModel::current()->getFileName();
  OpenProject(fileName);
  drawContext::global()->draw();
}

static void geometry_elementary_add_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->menu->setContext(menu_geometry_elementary_add, 0);
}

static void add_new_point()
{
  opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  drawContext::global()->draw();

  FlGui::instance()->geoContext->show(1);

  while(1) {
    for(unsigned int i = 0; i < FlGui::instance()->graph.size(); i++)
      for(unsigned int j = 0; j < FlGui::instance()->graph[i]->gl.size(); j++)
        FlGui::instance()->graph[i]->gl[j]->addPointMode = true;
    Msg::StatusBar(3, false, "Move mouse and/or enter coordinates\n"
                   "[Press 'Shift' to hold position, 'e' to add point "
                   "or 'q' to abort]");
    char ib = FlGui::instance()->selectEntity(ENT_NONE);
    if(ib == 'e'){
      add_point(GModel::current()->getFileName(),
                FlGui::instance()->geoContext->input[2]->value(),
                FlGui::instance()->geoContext->input[3]->value(),
                FlGui::instance()->geoContext->input[4]->value(),
                FlGui::instance()->geoContext->input[5]->value());
      FlGui::instance()->resetVisibility();
      drawContext::global()->draw();
    }
    if(ib == 'q'){
      for(unsigned int i = 0; i < FlGui::instance()->graph.size(); i++)
        for(unsigned int j = 0; j < FlGui::instance()->graph[i]->gl.size(); j++)
          FlGui::instance()->graph[i]->gl[j]->addPointMode = false;
      break;
    }
  }

  // at the end, not during creation to avoid having things jumping around
  SetBoundingBox();
  Msg::StatusBar(3, false, "");
}

static void add_new_multiline(std::string type)
{
  opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  opt_geometry_lines(0, GMSH_SET | GMSH_GUI, 1);
  drawContext::global()->draw();

  std::vector<int> p;
  while(1) {
    if(p.empty())
      Msg::StatusBar(3, false, "Select control points\n"
                     "[Press 'e' to end selection or 'q' to abort]");
    else
      Msg::StatusBar(3, false, "Select control points\n"
                     "[Press 'e' to end selection, 'u' to undo last selection "
                     "or 'q' to abort]");
    char ib = FlGui::instance()->selectEntity(ENT_POINT);
    if(ib == 'l') {
      for(unsigned int i = 0; i < FlGui::instance()->selectedVertices.size(); i++){
        FlGui::instance()->selectedVertices[i]->setSelection(1);
        p.push_back(FlGui::instance()->selectedVertices[i]->tag());
      }
      drawContext::global()->draw();
    }
    if(ib == 'r') {
      Msg::Warning("Entity de-selection not supported yet during multi-line creation");
    }
    if(ib == 'e') {
      if(p.size() >= 2)
        add_multline(type, p, GModel::current()->getFileName());
      FlGui::instance()->resetVisibility();
      GModel::current()->setSelection(0);
      drawContext::global()->draw();
      p.clear();
    }
    if(ib == 'u') {
      if(p.size()){
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

  Msg::StatusBar(3, false, "");
}

static void add_new_line()
{
  opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  opt_geometry_lines(0, GMSH_SET | GMSH_GUI, 1);
  drawContext::global()->draw();

  std::vector<int> p;
  while(1) {
    if(p.empty())
      Msg::StatusBar(3, false, "Select start point\n"
                     "[Press 'q' to abort]");
    if(p.size() == 1)
      Msg::StatusBar(3, false, "Select end point\n"
                     "[Press 'u' to undo last selection or 'q' to abort]");
    char ib = FlGui::instance()->selectEntity(ENT_POINT);
    if(ib == 'l') {
      FlGui::instance()->selectedVertices[0]->setSelection(1);
      drawContext::global()->draw();
      p.push_back(FlGui::instance()->selectedVertices[0]->tag());
    }
    if(ib == 'r') {
      Msg::Warning("Entity de-selection not supported yet during line creation");
    }
    if(ib == 'u') {
      if(p.size()){
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
      add_multline("Line", p, GModel::current()->getFileName());
      FlGui::instance()->resetVisibility();
      GModel::current()->setSelection(0);
      drawContext::global()->draw();
      p.clear();
    }
  }

  Msg::StatusBar(3, false, "");
}

static void add_new_circle()
{
  opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  opt_geometry_lines(0, GMSH_SET | GMSH_GUI, 1);
  drawContext::global()->draw();

  std::vector<int> p;
  while(1) {
    if(p.empty())
      Msg::StatusBar(3, false, "Select start point\n"
                     "[Press 'q' to abort]");
    if(p.size() == 1)
      Msg::StatusBar(3, false, "Select center point\n"
                     "[Press 'u' to undo last selection or 'q' to abort]");
    if(p.size() == 2)
      Msg::StatusBar(3, false, "Select end point\n"
                     "[Press 'u' to undo last selection or 'q' to abort]");
    char ib = FlGui::instance()->selectEntity(ENT_POINT);
    if(ib == 'l') {
      FlGui::instance()->selectedVertices[0]->setSelection(1);
      drawContext::global()->draw();
      p.push_back(FlGui::instance()->selectedVertices[0]->tag());
    }
    if(ib == 'r') {
      Msg::Warning("Entity de-selection not supported yet during circle creation");
    }
    if(ib == 'u') {
      if(p.size()){
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
      add_circ(p[0], p[1], p[2], GModel::current()->getFileName()); // begin, center, end
      FlGui::instance()->resetVisibility();
      GModel::current()->setSelection(0);
      drawContext::global()->draw();
      p.clear();
    }
  }

  Msg::StatusBar(3, false, "");
}

static void add_new_ellipse()
{
  opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  opt_geometry_lines(0, GMSH_SET | GMSH_GUI, 1);
  drawContext::global()->draw();

  std::vector<int> p;
  while(1) {
    if(p.empty())
      Msg::StatusBar(3, false, "Select start point\n"
                     "[Press 'q' to abort]");
    if(p.size() == 1)
      Msg::StatusBar(3, false, "Select center point\n"
                     "[Press 'u' to undo last selection or 'q' to abort]");
    if(p.size() == 2)
      Msg::StatusBar(3, false, "Select major axis point\n"
                     "[Press 'u' to undo last selection or 'q' to abort]");
    if(p.size() == 3)
      Msg::StatusBar(3, false, "Select end point\n"
                     "[Press 'u' to undo last selection or 'q' to abort]");
    char ib = FlGui::instance()->selectEntity(ENT_POINT);
    if(ib == 'l') {
      FlGui::instance()->selectedVertices[0]->setSelection(1);
      drawContext::global()->draw();
      p.push_back(FlGui::instance()->selectedVertices[0]->tag());
    }
    if(ib == 'r') {
      Msg::Warning("Entity de-selection not supported yet during ellipse creation");
    }
    if(ib == 'u') {
      if(p.size()){
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
      add_ell(p[0], p[1], p[2], p[3], GModel::current()->getFileName());
      FlGui::instance()->resetVisibility();
      GModel::current()->setSelection(0);
      drawContext::global()->draw();
      p.clear();
    }
  }

  Msg::StatusBar(3, false, "");
}

static int select_contour(int type, int num, List_T * List)
{
  int k = 0;

  switch (type) {
  case ENT_LINE:
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
    type = ENT_LINE;
    opt_geometry_lines(0, GMSH_SET | GMSH_GUI, 1);
    opt_geometry_surfaces(0, GMSH_SET | GMSH_GUI, 1);
  }
  drawContext::global()->draw();

  while(1) {
    List_Reset(List1);
    List_Reset(List2);

    while(1) {
      if(type == ENT_LINE){
        if(!List_Nbr(List1))
          Msg::StatusBar(3, false, "Select surface boundary\n"
                         "[Press 'q' to abort]");
        else
          Msg::StatusBar(3, false, "Select surface boundary\n"
                         "[Press 'u' to undo last selection or 'q' to abort]");
      }
      else{
        if(!List_Nbr(List1))
          Msg::StatusBar(3, false, "Select volume boundary\n"
                         "[Press 'q' to abort]");
        else
          Msg::StatusBar(3, false, "Select volume boundary\n"
                         "[Press 'u' to undo last selection or 'q' to abort]");
      }

      char ib = FlGui::instance()->selectEntity(type);
      if(ib == 'q') {
        GModel::current()->setSelection(0);
        drawContext::global()->draw();
        goto stopall;
      }
      if(ib == 'u') {
        if(List_Nbr(List1) > 0){
          int num;
          List_Read(List1, List_Nbr(List1)-1, &num);
          if(type == ENT_LINE){
            GEdge *ge = GModel::current()->getEdgeByTag(abs(num));
            if(ge) ge->setSelection(0);
          }
          else{
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
        int num = (type == ENT_LINE) ?
          FlGui::instance()->selectedEdges[0]->tag() :
          FlGui::instance()->selectedFaces[0]->tag();
        if(select_contour(type, num, List1)) {
          if(type == ENT_LINE)
            add_lineloop(List1, GModel::current()->getFileName(), &num);
          else
            add_surfloop(List1, GModel::current()->getFileName(), &num);
          List_Reset(List1);
          List_Add(List2, &num);
          while(1) {
            if(!List_Nbr(List1))
              Msg::StatusBar
                (3, false, "Select hole boundaries (if none, press 'e')\n"
                 "[Press 'e' to end selection or 'q' to abort]");
            else
              Msg::StatusBar
                (3, false, "Select hole boundaries\n"
                 "[Press 'e' to end selection, 'u' to undo last selection "
                 "or 'q' to abort]");
            ib = FlGui::instance()->selectEntity(type);
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
              if(List_Nbr(List1) > 0){
                int num;
                List_Read(List1, List_Nbr(List1)-1, &num);
                if(type == ENT_LINE){
                  GEdge *ge = GModel::current()->getEdgeByTag(abs(num));
                  if(ge) ge->setSelection(0);
                }
                else{
                  GFace *gf = GModel::current()->getFaceByTag(abs(num));
                  if(gf) gf->setSelection(0);
                }
                List_Pop(List1);
                drawContext::global()->draw();
              }
            }
            if(ib == 'l') {
              int size = (type == ENT_LINE) ?
                FlGui::instance()->selectedEdges.size() :
                FlGui::instance()->selectedFaces.size();
              for(int i=0;i<size;i++){
                int num = (type == ENT_LINE) ?
                  FlGui::instance()->selectedEdges[i]->tag() :
                  FlGui::instance()->selectedFaces[i]->tag();
                if(select_contour(type, num, List1)) {
                  if(type == ENT_LINE)
                    add_lineloop(List1, GModel::current()->getFileName(), &num);
                  else
                    add_surfloop(List1, GModel::current()->getFileName(), &num);
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
          List_Unique(List2,fcmp_absint);
          if(List_Nbr(List2)) {
            switch (mode) {
            case 0: add_surf("Plane Surface", List2,
                             GModel::current()->getFileName()); break;
            case 1: add_surf("Ruled Surface", List2,
                             GModel::current()->getFileName()); break;
            case 2: add_vol(List2, GModel::current()->getFileName()); break;
            }
            FlGui::instance()->resetVisibility();
            GModel::current()->setSelection(0);
            drawContext::global()->draw();
            break;
          }
        } // if select_contour
      }
    }
  }

 stopall:
  List_Delete(List1);
  List_Delete(List2);

  Msg::StatusBar(3, false, "");
}

static void geometry_elementary_add_new_cb(Fl_Widget *w, void *data)
{
  if(!data){
    FlGui::instance()->menu->setContext(menu_geometry_elementary_add_new, 0);
    return;
  }

  std::string str((const char*)data);
  if(str == "Parameter")
    FlGui::instance()->geoContext->show(0);
  else if(str == "Point")
    add_new_point();
  else if(str == "Line")
    add_new_line();
  else if(str == "Spline")
    add_new_multiline(str);
  else if(str == "BSpline")
    add_new_multiline(str);
  else if(str == "Circle")
    add_new_circle();
  else if(str == "Ellipse")
    add_new_ellipse();
  else if(str == "Plane Surface")
    add_new_surface_volume(0);
  else if(str == "Ruled Surface")
    add_new_surface_volume(1);
  else if(str == "Volume")
    add_new_surface_volume(2);
  else
    Msg::Error("Unknown entity to create: %s", str.c_str());
}

static void split_selection()
{
  opt_geometry_lines(0, GMSH_SET | GMSH_GUI, 1);
  drawContext::global()->draw();
  Msg::StatusBar(3, false, "Select a line to split\n"
                 "[Press 'q' to abort]");
  GEdge* edge_to_split = 0;
  while(1){
    char ib = FlGui::instance()->selectEntity(ENT_LINE);
    if(ib == 'q')
      break;
    if(!FlGui::instance()->selectedEdges.empty()){
      edge_to_split = FlGui::instance()->selectedEdges[0];
      edge_to_split->setSelection(1);
      break;
    }
  }
  Msg::StatusBar(3, false, "");
  if(FlGui::instance()->selectedEdges.empty()) return;
  List_T *List1 = List_Create(5, 5, sizeof(int));
  Msg::StatusBar(3, false, "Select break points\n"
                 "[Press 'e' to end selection or 'q' to abort]");
  opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  drawContext::global()->draw();
  while(1){
    char ib = FlGui::instance()->selectEntity(ENT_POINT);
    if(ib == 'q')
      break;
    if(ib == 'e'){
      split_edge(edge_to_split->tag(), List1, GModel::current()->getFileName());
      break;
    }
    for(unsigned int i = 0; i < FlGui::instance()->selectedVertices.size(); i++){
      int tag = FlGui::instance()->selectedVertices[i]->tag();
      int index = List_ISearchSeq(List1, &tag, fcmp_int);
      if(index < 0) List_Add(List1, &tag);
      FlGui::instance()->selectedVertices[i]->setSelection(1);
    }
  }
  Msg::StatusBar(3, false, "");
  FlGui::instance()->resetVisibility();
  GModel::current()->setSelection(0);
  drawContext::global()->draw();
}

static void action_point_line_surface_volume(int action, int mode, const char *what)
{
  int type;
  const char *str;

  if(!strcmp(what, "Point")) {
    type = ENT_POINT;
    str = "points";
    opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  }
  else if(!strcmp(what, "Line")) {
    type = ENT_LINE;
    str = "lines";
    opt_geometry_lines(0, GMSH_SET | GMSH_GUI, 1);
  }
  else if(!strcmp(what, "Surface")) {
    type = ENT_SURFACE;
    str = "surfaces";
    opt_geometry_surfaces(0, GMSH_SET | GMSH_GUI, 1);
  }
  else if(!strcmp(what, "Volume")) {
    type = ENT_VOLUME;
    str = "volumes";
    opt_geometry_volumes(0, GMSH_SET | GMSH_GUI, 1);
  }
  else{
    Msg::Error("Unknown entity to select");
    return;
  }

  if(action == 8){
    FlGui::instance()->meshContext->show(0);
  }

  drawContext::global()->draw();

  List_T *List1 = List_Create(5, 5, sizeof(int));
  while(1) {
    if(!List_Nbr(List1))
      Msg::StatusBar(3, false, "Select %s\n"
                     "[Press 'e' to end selection or 'q' to abort]", str);
    else
      Msg::StatusBar(3, false, "Select %s\n"
                     "[Press 'e' to end selection, 'u' to undo last selection "
                     "or 'q' to abort]", str);

    char ib = FlGui::instance()->selectEntity(type);
    if(ib == 'l') {
      // we don't use List_Insert in order to keep the original
      // ordering (this is slower, but this way undo works as
      // expected)
      int tag;
      switch (type) {
      case ENT_POINT:
        for(unsigned int i = 0; i < FlGui::instance()->selectedVertices.size(); i++){
          FlGui::instance()->selectedVertices[i]->setSelection(1);
          tag = FlGui::instance()->selectedVertices[i]->tag();
          if(List_ISearchSeq(List1, &tag, fcmp_int) < 0)
            List_Add(List1, &tag);
        }
        break;
      case ENT_LINE:
        for(unsigned int i = 0; i < FlGui::instance()->selectedEdges.size(); i++){
          FlGui::instance()->selectedEdges[i]->setSelection(1);
          tag = FlGui::instance()->selectedEdges[i]->tag();
          if(List_ISearchSeq(List1, &tag, fcmp_int) < 0)
            List_Add(List1, &tag);
        }
        break;
      case ENT_SURFACE:
        for(unsigned int i = 0; i < FlGui::instance()->selectedFaces.size(); i++){
          FlGui::instance()->selectedFaces[i]->setSelection(1);
          tag = FlGui::instance()->selectedFaces[i]->tag();
          if(List_ISearchSeq(List1, &tag, fcmp_int) < 0)
            List_Add(List1, &tag);
        }
        break;
      case ENT_VOLUME:
        for(unsigned int i = 0; i < FlGui::instance()->selectedRegions.size(); i++){
          FlGui::instance()->selectedRegions[i]->setSelection(1);
          tag = FlGui::instance()->selectedRegions[i]->tag();
          if(List_ISearchSeq(List1, &tag, fcmp_int) < 0)
            List_Add(List1, &tag);
        }
        break;
      }
      drawContext::global()->draw();
    }
    if(ib == 'r') {
      // we don't use List_Suppress in order to keep the original
      // ordering (this is slower, but this way undo works as
      // expected)
      int index, tag;
      switch (type) {
      case ENT_POINT:
        for(unsigned int i = 0; i < FlGui::instance()->selectedVertices.size(); i++){
          tag = FlGui::instance()->selectedVertices[i]->tag();
          index = List_ISearchSeq(List1, &tag, fcmp_int);
          if(index >= 0) List_PSuppress(List1, index);
          FlGui::instance()->selectedVertices[i]->setSelection(0);
        }
        break;
      case ENT_LINE:
        for(unsigned int i = 0; i < FlGui::instance()->selectedEdges.size(); i++){
          tag = FlGui::instance()->selectedEdges[i]->tag();
          index = List_ISearchSeq(List1, &tag, fcmp_int);
          if(index >= 0) List_PSuppress(List1, index);
          FlGui::instance()->selectedEdges[i]->setSelection(0);
        }
        break;
      case ENT_SURFACE:
        for(unsigned int i = 0; i < FlGui::instance()->selectedFaces.size(); i++){
          tag = FlGui::instance()->selectedFaces[i]->tag();
          index = List_ISearchSeq(List1, &tag, fcmp_int);
          if(index >= 0) List_PSuppress(List1, index);
          FlGui::instance()->selectedFaces[i]->setSelection(0);
        }
        break;
      case ENT_VOLUME:
        for(unsigned int i = 0; i < FlGui::instance()->selectedRegions.size(); i++){
          tag = FlGui::instance()->selectedRegions[i]->tag();
          index = List_ISearchSeq(List1, &tag, fcmp_int);
          if(index >= 0) List_PSuppress(List1, index);
          FlGui::instance()->selectedRegions[i]->setSelection(0);
        }
        break;
      }
      drawContext::global()->draw();
    }
    if(ib == 'u') {
      if(List_Nbr(List1)) {
        int num;
        List_Read(List1, List_Nbr(List1) - 1, &num);
        if(type == ENT_POINT){
          GVertex *gv = GModel::current()->getVertexByTag(num);
          if(gv) gv->setSelection(0);
        }
        else if(type == ENT_LINE){
          GEdge *ge = GModel::current()->getEdgeByTag(num);
          if(ge) ge->setSelection(0);
        }
        else if(type == ENT_SURFACE){
          GFace *gf = GModel::current()->getFaceByTag(num);
          if(gf) gf->setSelection(0);
        }
        else if(type == ENT_VOLUME){
          GRegion *gr = GModel::current()->getRegionByTag(num);
          if(gr) gr->setSelection(0);
        }
        drawContext::global()->draw();
        List_Pop(List1);
      }
    }
    if(ib == 'i') {
      Msg::Error("Inverting selection!");
    }
    if(ib == 'e') {
      if(List_Nbr(List1)){
        switch (action) {
        case 0:
          translate(mode, List1, GModel::current()->getFileName(), what,
                    FlGui::instance()->geoContext->input[6]->value(),
                    FlGui::instance()->geoContext->input[7]->value(),
                    FlGui::instance()->geoContext->input[8]->value());
          break;
        case 1:
          rotate(mode, List1, GModel::current()->getFileName(), what,
                 FlGui::instance()->geoContext->input[12]->value(),
                 FlGui::instance()->geoContext->input[13]->value(),
                 FlGui::instance()->geoContext->input[14]->value(),
                 FlGui::instance()->geoContext->input[9]->value(),
                 FlGui::instance()->geoContext->input[10]->value(),
                 FlGui::instance()->geoContext->input[11]->value(),
                 FlGui::instance()->geoContext->input[15]->value());
          break;
        case 2:
          dilate(mode, List1, GModel::current()->getFileName(), what,
                 FlGui::instance()->geoContext->input[16]->value(),
                 FlGui::instance()->geoContext->input[17]->value(),
                 FlGui::instance()->geoContext->input[18]->value(),
                 FlGui::instance()->geoContext->input[19]->value());
          break;
        case 3:
          symmetry(mode, List1, GModel::current()->getFileName(), what,
                   FlGui::instance()->geoContext->input[20]->value(),
                   FlGui::instance()->geoContext->input[21]->value(),
                   FlGui::instance()->geoContext->input[22]->value(),
                   FlGui::instance()->geoContext->input[23]->value());
          break;
        case 4:
          extrude(List1, GModel::current()->getFileName(), what,
                  FlGui::instance()->geoContext->input[6]->value(),
                  FlGui::instance()->geoContext->input[7]->value(),
                  FlGui::instance()->geoContext->input[8]->value());
          break;
        case 5:
          protude(List1, GModel::current()->getFileName(), what,
                  FlGui::instance()->geoContext->input[12]->value(),
                  FlGui::instance()->geoContext->input[13]->value(),
                  FlGui::instance()->geoContext->input[14]->value(),
                  FlGui::instance()->geoContext->input[9]->value(),
                  FlGui::instance()->geoContext->input[10]->value(),
                  FlGui::instance()->geoContext->input[11]->value(),
                  FlGui::instance()->geoContext->input[15]->value());
          break;
        case 6:
          delet(List1, GModel::current()->getFileName(), what);
          break;
        case 7:
          add_physical(what, List1, GModel::current()->getFileName());
          break;
        case 8:
          add_charlength(List1, GModel::current()->getFileName(),
                         FlGui::instance()->meshContext->input[0]->value());
          break;
        case 9:
          add_recosurf(List1, GModel::current()->getFileName());
          break;
        case 10:
          add_compound(what, List1, GModel::current()->getFileName());
          break;
        default:
          Msg::Error("Unknown action on selected entities");
          break;
        }
        List_Reset(List1);
        FlGui::instance()->resetVisibility();
        GModel::current()->setSelection(0);
        if(action <= 6) SetBoundingBox();
        drawContext::global()->draw();
      }
    }
    if(ib == 'q') {
      GModel::current()->setSelection(0);
      drawContext::global()->draw();
      break;
    }
  }
  List_Delete(List1);

  Msg::StatusBar(3, false, "");
}

static void geometry_elementary_add_translate_cb(Fl_Widget *w, void *data)
{
  if(!data){
    FlGui::instance()->menu->setContext(menu_geometry_elementary_add_translate, 0);
    return;
  }
  FlGui::instance()->geoContext->show(2);
  action_point_line_surface_volume(0, 1, (const char*)data);
}

static void geometry_elementary_add_rotate_cb(Fl_Widget *w, void *data)
{
  if(!data){
    FlGui::instance()->menu->setContext(menu_geometry_elementary_add_rotate, 0);
    return;
  }
  FlGui::instance()->geoContext->show(3);
  action_point_line_surface_volume(1, 1, (const char*)data);
}

static void geometry_elementary_add_scale_cb(Fl_Widget *w, void *data)
{
  if(!data){
    FlGui::instance()->menu->setContext(menu_geometry_elementary_add_scale, 0);
    return;
  }
  FlGui::instance()->geoContext->show(4);
  action_point_line_surface_volume(2, 1, (const char*)data);
}

static void geometry_elementary_add_symmetry_cb(Fl_Widget *w, void *data)
{
  if(!data){
    FlGui::instance()->menu->setContext(menu_geometry_elementary_add_symmetry, 0);
    return;
  }
  FlGui::instance()->geoContext->show(5);
  action_point_line_surface_volume(3, 1, (const char*)data);
}

static void geometry_elementary_translate_cb(Fl_Widget *w, void *data)
{
  if(!data){
    FlGui::instance()->menu->setContext(menu_geometry_elementary_translate, 0);
    return;
  }
  FlGui::instance()->geoContext->show(2);
  action_point_line_surface_volume(0, 0, (const char*)data);
}

static void geometry_elementary_rotate_cb(Fl_Widget *w, void *data)
{
  if(!data){
    FlGui::instance()->menu->setContext(menu_geometry_elementary_rotate, 0);
    return;
  }
  FlGui::instance()->geoContext->show(3);
  action_point_line_surface_volume(1, 0, (const char*)data);
}

static void geometry_elementary_scale_cb(Fl_Widget *w, void *data)
{
  if(!data){
    FlGui::instance()->menu->setContext(menu_geometry_elementary_scale, 0);
    return;
  }
  FlGui::instance()->geoContext->show(4);
  action_point_line_surface_volume(2, 0, (const char*)data);
}

static void geometry_elementary_symmetry_cb(Fl_Widget *w, void *data)
{
  if(!data){
    FlGui::instance()->menu->setContext(menu_geometry_elementary_symmetry, 0);
    return;
  }
  FlGui::instance()->geoContext->show(5);
  action_point_line_surface_volume(3, 0, (const char*)data);
}

static void geometry_elementary_extrude_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->menu->setContext(menu_geometry_elementary_extrude, 0);
}

static void geometry_elementary_extrude_translate_cb(Fl_Widget *w, void *data)
{
  if(!data){
    FlGui::instance()->menu->setContext(menu_geometry_elementary_extrude_translate, 0);
    return;
  }
  FlGui::instance()->geoContext->show(2);
  action_point_line_surface_volume(4, 0, (const char*)data);
}

static void geometry_elementary_extrude_rotate_cb(Fl_Widget *w, void *data)
{
  if(!data){
    FlGui::instance()->menu->setContext(menu_geometry_elementary_extrude_rotate, 0);
    return;
  }
  FlGui::instance()->geoContext->show(3);
  action_point_line_surface_volume(5, 0, (const char*)data);
}

static void geometry_elementary_delete_cb(Fl_Widget *w, void *data)
{
  if(!data){
    FlGui::instance()->menu->setContext(menu_geometry_elementary_delete, 0);
    return;
  }
  action_point_line_surface_volume(6, 0, (const char*)data);
}

static void geometry_elementary_split_cb(Fl_Widget *w, void *data)
{
  if(!data){
    FlGui::instance()->menu->setContext(menu_geometry_elementary_split, 0);
    return;
  }
  split_selection();
}

static void geometry_elementary_coherence_cb(Fl_Widget *w, void *data)
{
  coherence(GModel::current()->getFileName());
}

static void geometry_physical_add_cb(Fl_Widget *w, void *data)
{
  if(!data){
    FlGui::instance()->menu->setContext(menu_geometry_physical_add, 0);
    return;
  }
  std::string str((const char*)data);
  if(str == "Point")
    FlGui::instance()->callForSolverPlugin(0);
  else if(str == "Line")
    FlGui::instance()->callForSolverPlugin(1);

  action_point_line_surface_volume(7, 0, str.c_str());
}

void mesh_save_cb(Fl_Widget *w, void *data)
{
  std::string name = CTX::instance()->outputFileName;
  if(name.empty()){
    if(CTX::instance()->mesh.fileFormat == FORMAT_AUTO)
      name = GetDefaultFileName(FORMAT_MSH);
    else
      name = GetDefaultFileName(CTX::instance()->mesh.fileFormat);
  }
  if(CTX::instance()->confirmOverwrite) {
    if(!StatFile(name))
      if(!fl_choice("File '%s' already exists.\n\nDo you want to replace it?",
                    "Cancel", "Replace", 0, name.c_str()))
        return;
  }
  CreateOutputFile(name, CTX::instance()->mesh.fileFormat);
}

static void mesh_define_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->menu->setContext(menu_mesh_define, 0);
}

void mesh_1d_cb(Fl_Widget *w, void *data)
{
  GModel::current()->mesh(1);
  drawContext::global()->draw();
}

void mesh_2d_cb(Fl_Widget *w, void *data)
{
  GModel::current()->mesh(2);
  drawContext::global()->draw();
}

void mesh_3d_cb(Fl_Widget *w, void *data)
{
  GModel::current()->mesh(3);
  drawContext::global()->draw();
}

static void mesh_delete_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->menu->setContext(menu_mesh_delete, 0);
}

static void mesh_delete_parts_cb(Fl_Widget *w, void *data)
{
  const char *str = (const char*)data;
  int what;

  if(!strcmp(str, "elements")){
    CTX::instance()->pickElements = 1;
    what = ENT_ALL;
  }
  else if(!strcmp(str, "lines")){
    CTX::instance()->pickElements = 0;
    what = ENT_LINE;
  }
  else if(!strcmp(str, "surfaces")){
    CTX::instance()->pickElements = 0;
    what = ENT_SURFACE;
  }
  else if(!strcmp(str, "volumes")){
    CTX::instance()->pickElements = 0;
    what = ENT_VOLUME;
  }
  else
    return;

  std::vector<MElement*> ele;
  std::vector<GEntity*> ent;

  while(1) {
    CTX::instance()->mesh.changed = ENT_ALL;
    drawContext::global()->draw();

    if(ele.size() || ent.size())
      Msg::StatusBar(3, false, "Select %s\n"
                     "[Press 'e' to end selection, 'u' to undo last selection or "
                     "'q' to abort]", str);
    else
      Msg::StatusBar(3, false, "Select %s\n"
                     "[Press 'e' to end selection or 'q' to abort]", str);

    char ib = FlGui::instance()->selectEntity(what);
    if(ib == 'l') {
      if(CTX::instance()->pickElements){
        for(unsigned int i = 0; i < FlGui::instance()->selectedElements.size(); i++){
          if(FlGui::instance()->selectedElements[i]->getVisibility() != 2){
            FlGui::instance()->selectedElements[i]->setVisibility(2);
            ele.push_back(FlGui::instance()->selectedElements[i]);
          }
        }
      }
      else{
        for(unsigned int i = 0; i < FlGui::instance()->selectedEdges.size(); i++){
          if(FlGui::instance()->selectedEdges[i]->getSelection() != 1){
            FlGui::instance()->selectedEdges[i]->setSelection(1);
            ent.push_back(FlGui::instance()->selectedEdges[i]);
          }
        }
        for(unsigned int i = 0; i < FlGui::instance()->selectedFaces.size(); i++){
          if(FlGui::instance()->selectedFaces[i]->getSelection() != 1){
            FlGui::instance()->selectedFaces[i]->setSelection(1);
            ent.push_back(FlGui::instance()->selectedFaces[i]);
          }
        }
        for(unsigned int i = 0; i < FlGui::instance()->selectedRegions.size(); i++){
          if(FlGui::instance()->selectedRegions[i]->getSelection() != 1){
            FlGui::instance()->selectedRegions[i]->setSelection(1);
            ent.push_back(FlGui::instance()->selectedRegions[i]);
          }
        }
      }
    }
    if(ib == 'r') {
      if(CTX::instance()->pickElements){
        for(unsigned int i = 0; i < FlGui::instance()->selectedElements.size(); i++)
          FlGui::instance()->selectedElements[i]->setVisibility(1);
      }
      else{
        for(unsigned int i = 0; i < FlGui::instance()->selectedEdges.size(); i++)
          FlGui::instance()->selectedEdges[i]->setSelection(0);
        for(unsigned int i = 0; i < FlGui::instance()->selectedFaces.size(); i++)
          FlGui::instance()->selectedFaces[i]->setSelection(0);
        for(unsigned int i = 0; i < FlGui::instance()->selectedRegions.size(); i++)
          FlGui::instance()->selectedRegions[i]->setSelection(0);
      }
    }
    if(ib == 'u') {
      if(CTX::instance()->pickElements){
        if(ele.size()){
          ele[ele.size() - 1]->setVisibility(1);
          ele.pop_back();
        }
      }
      else{
        if(ent.size()){
          ent[ent.size() - 1]->setSelection(0);
          ent.pop_back();
        }
      }
    }
    if(ib == 'e') {
      if(CTX::instance()->pickElements){
        for(unsigned int i = 0; i < ele.size(); i++)
          if(ele[i]->getVisibility() == 2) ele[i]->setVisibility(0);
      }
      else{
        for(unsigned int i = 0; i < ent.size(); i++)
          if(ent[i]->getSelection() == 1) ent[i]->setVisibility(0);
      }
      GModel::current()->removeInvisibleElements();
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
  Msg::StatusBar(3, false, "");
}

static void mesh_inspect_cb(Fl_Widget *w, void *data)
{
  CTX::instance()->pickElements = 1;
  CTX::instance()->mesh.changed = ENT_ALL;
  drawContext::global()->draw();

  while(1) {
    Msg::StatusBar(3, false, "Select element\n[Press 'q' to abort]");
    char ib = FlGui::instance()->selectEntity(ENT_ALL);
    if(ib == 'l') {
      if(FlGui::instance()->selectedElements.size()){
        MElement *ele = FlGui::instance()->selectedElements[0];
        GModel::current()->setSelection(0);
        ele->setVisibility(2);
        Msg::Direct("Element %d:", ele->getNum());
        int type = ele->getTypeForMSH();
        const char *name;
        MElement::getInfoMSH(type, &name);
        Msg::Direct("  Type: %d ('%s')", type, name);
        Msg::Direct("  Dimension: %d", ele->getDim());
        Msg::Direct("  Order: %d", ele->getPolynomialOrder());
        Msg::Direct("  Partition: %d", ele->getPartition());
        char tmp1[32], tmp2[512];
        sprintf(tmp2, "  Vertices:");
        for(int i = 0; i < ele->getNumVertices(); i++){
          sprintf(tmp1, " %d", ele->getVertex(i)->getNum());
          strcat(tmp2, tmp1);
        }
        Msg::Direct(tmp2);
        SPoint3 pt = ele->barycenter();
        Msg::Direct("  Barycenter: (%g,%g,%g)", pt[0], pt[1], pt[2]);
        Msg::Direct("  Rho: %g", ele->rhoShapeMeasure());
        Msg::Direct("  Gamma: %g", ele->gammaShapeMeasure());
        Msg::Direct("  Eta: %g", ele->etaShapeMeasure());
        double jmin, jmax; ele->scaledJacRange(jmin, jmax);
        Msg::Direct("  Scaled Jacobian Range: %g %g", jmin, jmax);
        Msg::Direct("  Inner / outer radius: %g / %g",
                    ele->getInnerRadius(), ele->getOuterRadius());
        CTX::instance()->mesh.changed = ENT_ALL;
        drawContext::global()->draw();
        FlGui::instance()->showMessages();
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
  Msg::StatusBar(3, false, "");
}

static void mesh_change_order_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->menu->setContext(menu_mesh_degree, 0);
}


static void mesh_degree_cb(Fl_Widget *w, void *data)
{
  int degree = (intptr_t)data;
  if(degree == 2)
    SetOrderN(GModel::current(), 2, CTX::instance()->mesh.secondOrderLinear,
              CTX::instance()->mesh.secondOrderIncomplete);
  else if (degree == 1)
    SetOrder1(GModel::current());
  else // For now, use the same options as for second order meshes
    SetOrderN(GModel::current(), degree,
	      CTX::instance()->mesh.secondOrderLinear,
              CTX::instance()->mesh.secondOrderIncomplete);
  CTX::instance()->mesh.changed |= (ENT_LINE | ENT_SURFACE | ENT_VOLUME);
  drawContext::global()->draw();
}

static void mesh_optimize_cb(Fl_Widget *w, void *data)
{
  if(CTX::instance()->lock) {
    Msg::Info("I'm busy! Ask me that later...");
    return;
  }
  CTX::instance()->lock = 1;
  OptimizeMesh(GModel::current());
  CTX::instance()->lock = 0;
  CTX::instance()->mesh.changed |= (ENT_LINE | ENT_SURFACE | ENT_VOLUME);
  drawContext::global()->draw();
}

static void mesh_refine_cb(Fl_Widget *w, void *data)
{
  RefineMesh(GModel::current(), CTX::instance()->mesh.secondOrderLinear);
  CTX::instance()->mesh.changed |= (ENT_LINE | ENT_SURFACE | ENT_VOLUME);
  drawContext::global()->draw();
}

static void mesh_optimize_netgen_cb(Fl_Widget *w, void *data)
{
  if(CTX::instance()->lock) {
    Msg::Info("I'm busy! Ask me that later...");
    return;
  }
  CTX::instance()->lock = 1;
  OptimizeMeshNetgen(GModel::current());
  CTX::instance()->lock = 0;
  CTX::instance()->mesh.changed |= (ENT_LINE | ENT_SURFACE | ENT_VOLUME);
  drawContext::global()->draw();
}

static void mesh_partition_cb(Fl_Widget *w, void *data)
{
  partition_dialog();
}

static void mesh_define_length_cb(Fl_Widget *w, void *data)
{
  action_point_line_surface_volume(8, 0, "Point");
}

static void mesh_define_recombine_cb(Fl_Widget *w, void *data)
{
  action_point_line_surface_volume(9, 0, "Surface");
}

static void mesh_define_transfinite_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->menu->setContext(menu_mesh_define_transfinite, 0);
}

static void add_transfinite_embedded(int dim, bool embed)
{
  opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  switch (dim) {
  case 1: opt_geometry_lines(0, GMSH_SET | GMSH_GUI, 1); break;
  case 2: opt_geometry_surfaces(0, GMSH_SET | GMSH_GUI, 1); break;
  case 3: opt_geometry_volumes(0, GMSH_SET | GMSH_GUI, 1); break;
  }
  drawContext::global()->draw();

  std::vector<int> p;
  char ib;
  while(1) {
    switch (dim) {
    case 1:
      if(p.empty())
        Msg::StatusBar(3, false, "Select lines\n"
                       "[Press 'e' to end selection or 'q' to abort]");
      else
        Msg::StatusBar(3, false, "Select lines\n"
                       "[Press 'e' to end selection, 'u' to undo last selection "
                       "or 'q' to abort]");
      ib = FlGui::instance()->selectEntity(ENT_LINE);
      break;
    case 2:
      Msg::StatusBar(3, false, "Select surface\n[Press 'q' to abort]");
      ib = FlGui::instance()->selectEntity(ENT_SURFACE);
      break;
    case 3:
      Msg::StatusBar(3, false, "Select volume\n[Press 'q' to abort]");
      ib = FlGui::instance()->selectEntity(ENT_VOLUME);
      break;
    default:
      ib = 'l';
      break;
    }

    if(ib == 'e') {
      if(dim == 1) {
        if(p.size())
          add_trsfline(p, GModel::current()->getFileName(),
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
        if(p.size()){
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
      switch (dim) {
      case 1:
        for(unsigned int i = 0; i < FlGui::instance()->selectedEdges.size(); i++){
          FlGui::instance()->selectedEdges[i]->setSelection(1);
          p.push_back(FlGui::instance()->selectedEdges[i]->tag());
        }
        drawContext::global()->draw();
        break;
      case 2:
      case 3:
        if(dim == 2){
          FlGui::instance()->selectedFaces[0]->setSelection(1);
          drawContext::global()->draw();
          p.push_back(FlGui::instance()->selectedFaces[0]->tag());
        }
        else{
          FlGui::instance()->selectedRegions[0]->setSelection(1);
          drawContext::global()->draw();
          p.push_back(FlGui::instance()->selectedRegions[0]->tag());
        }
        while(1) {
          if(p.size() == 1)
            Msg::StatusBar(3, false, "Select %s points\n"
                           "[Press 'e' to end selection or 'q' to abort]",
                           embed ? "embedded" : "(ordered) boundary");
          else
            Msg::StatusBar(3, false, "Select %s points\n"
                           "[Press 'e' to end selection, 'u' to undo last selection "
                           "or 'q' to abort]",
                           embed ? "embedded" : "(ordered) boundary");
          ib = FlGui::instance()->selectEntity(ENT_POINT);
          if(ib == 'l') {
            for(unsigned int i = 0; i < FlGui::instance()->selectedVertices.size(); i++){
              FlGui::instance()->selectedVertices[i]->setSelection(1);
              p.push_back(FlGui::instance()->selectedVertices[i]->tag());
              if(!embed) break;
            }
            drawContext::global()->draw();
          }
          if(ib == 'u') {
            if(p.size() > 1){
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
            switch (dim) {
            case 2:
              if(embed && p.size())
                add_embedded("Point", p, GModel::current()->getFileName());
              else if(!embed &&
                      (p.size() == 0 + 1 || p.size() == 3 + 1 || p.size() == 4 + 1))
                add_trsfsurf(p, GModel::current()->getFileName(),
                             FlGui::instance()->meshContext->choice[1]->text());
              else
                Msg::Error("Wrong number of points for mesh constraint");
              break;
            case 3:
              if(p.size() == 6 + 1 || p.size() == 8 + 1)
                add_trsfvol(p, GModel::current()->getFileName());
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
  Msg::StatusBar(3, false, "");
}

static void mesh_define_transfinite_line_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->meshContext->show(1);
  add_transfinite_embedded(1, false);
}

static void mesh_define_transfinite_surface_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->meshContext->show(2);
  add_transfinite_embedded(2, false);
}

static void mesh_define_transfinite_volume_cb(Fl_Widget *w, void *data)
{
  add_transfinite_embedded(3, false);
}

static void mesh_define_embedded_cb(Fl_Widget *w, void *data)
{
  add_transfinite_embedded(2, true);
}

static void mesh_define_compound_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->menu->setContext(menu_mesh_define_compound, 0);
}

static void mesh_define_compound_entity_cb(Fl_Widget *w, void *data)
{
  action_point_line_surface_volume(10, 0, (const char *)data);
}

static void view_toggle_cb(Fl_Widget *w, void *data)
{
  int num = (intptr_t)data;
  opt_view_visible(num, GMSH_SET,
                   FlGui::instance()->menu->toggle[num]->value());
  drawContext::global()->draw();
}

static void view_reload(int index)
{
  if(index >= 0 && index < (int)PView::list.size()){
    PView *p = PView::list[index];

    if(StatFile(p->getData()->getFileName())){
      Msg::Error("File '%s' does not exist", p->getData()->getFileName().c_str());
      return;
    }

    int n = PView::list.size();

    // FIXME: use fileIndex
    MergeFile(p->getData()->getFileName());

    if((int)PView::list.size() > n){ // we loaded a new view
      // delete old data and replace with new
      delete p->getData();
      p->setData(PView::list.back()->getData());
      PView::list.back()->setData(0);
      // delete new view
      delete PView::list.back();
      // in case the reloaded view has a different number of time steps
      if(p->getOptions()->timeStep > p->getData()->getNumTimeSteps() - 1)
        p->getOptions()->timeStep = 0;
      p->setChanged(true);
      FlGui::instance()->updateViews();
    }
  }
}

static void view_reload_cb(Fl_Widget *w, void *data)
{
  view_reload((intptr_t)data);
  drawContext::global()->draw();
}

static void view_reload_all_cb(Fl_Widget *w, void *data)
{
  for(unsigned int i = 0; i < PView::list.size(); i++)
    view_reload(i);
  drawContext::global()->draw();
}

static void view_reload_visible_cb(Fl_Widget *w, void *data)
{
  for(unsigned int i = 0; i < PView::list.size(); i++)
    if(opt_view_visible(i, GMSH_GET, 0))
      view_reload(i);
  drawContext::global()->draw();
}

static void view_remove_other_cb(Fl_Widget *w, void *data)
{
  if(PView::list.empty()) return;
  for(int i = PView::list.size() - 1; i >= 0; i--)
    if(i != (intptr_t)data) delete PView::list[i];
  FlGui::instance()->updateViews();
  drawContext::global()->draw();
}

static void view_remove_all_cb(Fl_Widget *w, void *data)
{
  if(PView::list.empty()) return;
  int mode = (intptr_t)data;
  if(mode == -1){ // remove all
    if(PView::list.empty()) return;
    while(PView::list.size()) delete PView::list[0];
  }
  else if(mode == -2){ // remove all visible
    for(int i = PView::list.size() - 1; i >= 0; i--)
      if(opt_view_visible(i, GMSH_GET, 0)) delete PView::list[i];
  }
  else if(mode == -3){ // remove all invisible
    for(int i = PView::list.size() - 1; i >= 0; i--)
      if(!opt_view_visible(i, GMSH_GET, 0)) delete PView::list[i];
  }
  else if(mode == -4){ // remove all empty
    for(int i = PView::list.size() - 1; i >= 0; i--)
      if(PView::list[i]->getData()->empty()) delete PView::list[i];
  }
  else if(mode >=0 && mode < (int)PView::list.size()){ // remove by name
    std::string name = PView::list[mode]->getData()->getName();
    for(int i = PView::list.size() - 1; i >= 0; i--)
      if(PView::list[i]->getData()->getName() == name) delete PView::list[i];
  }

  FlGui::instance()->updateViews();
  drawContext::global()->draw();
}

static void view_remove_cb(Fl_Widget *w, void *data)
{
  delete PView::list[(intptr_t)data];
  FlGui::instance()->updateViews();
  drawContext::global()->draw();
}

static void view_save_cb(Fl_Widget *w, void *data)
{
  static const char *formats =
    "Gmsh Parsed" TT "*.pos" NN
    "Gmsh Mesh-based" TT "*.pos" NN
    "Gmsh Legacy ASCII" TT "*.pos" NN
    "Gmsh Legacy Binary" TT "*.pos" NN
    "MED" TT "*.rmed" NN
    "STL Surface" TT "*.stl" NN
    "Generic TXT" TT "*.txt" NN;

  PView *view = PView::list[(intptr_t)data];
 test:
  if(fileChooser(FILE_CHOOSER_CREATE, "Save As", formats,
                 view->getData()->getFileName().c_str())){
    std::string name = fileChooserGetName(1);
    if(CTX::instance()->confirmOverwrite) {
      if(!StatFile(name))
        if(!fl_choice("File '%s' already exists.\n\nDo you want to replace it?",
                      "Cancel", "Replace", 0, name.c_str()))
          goto test;
    }
    int format = 0;
    switch(fileChooserGetFilter()){
    case 0: format = 2; break;
    case 1: format = 5; break;
    case 2: format = 0; break;
    case 3: format = 1; break;
    case 4: format = 6; break;
    case 5: format = 3; break;
    case 6: format = 4; break;
    }
    view->write(name, format);
  }
}

#undef TT
#undef NN

static void view_alias_cb(Fl_Widget *w, void *data)
{
  new PView(PView::list[(intptr_t)data], false);
  FlGui::instance()->updateViews();
  drawContext::global()->draw();
}

static void view_alias_with_options_cb(Fl_Widget *w, void *data)
{
  new PView(PView::list[(intptr_t)data], true);
  FlGui::instance()->updateViews();
  drawContext::global()->draw();
}

static void view_combine_space_all_cb(Fl_Widget *w, void *data)
{
  PView::combine(false, 1, CTX::instance()->post.combineRemoveOrig);
  FlGui::instance()->updateViews();
  drawContext::global()->draw();
}

static void view_combine_space_visible_cb(Fl_Widget *w, void *data)
{
  PView::combine(false, 0, CTX::instance()->post.combineRemoveOrig);
  FlGui::instance()->updateViews();
  drawContext::global()->draw();
}

static void view_combine_space_by_name_cb(Fl_Widget *w, void *data)
{
  PView::combine(false, 2, CTX::instance()->post.combineRemoveOrig);
  FlGui::instance()->updateViews();
  drawContext::global()->draw();
}

static void view_combine_time_all_cb(Fl_Widget *w, void *data)
{
  PView::combine(true, 1, CTX::instance()->post.combineRemoveOrig);
  FlGui::instance()->updateViews();
  drawContext::global()->draw();
}

static void view_combine_time_visible_cb(Fl_Widget *w, void *data)
{
  PView::combine(true, 0, CTX::instance()->post.combineRemoveOrig);
  FlGui::instance()->updateViews();
  drawContext::global()->draw();
}

static void view_combine_time_by_name_cb(Fl_Widget *w, void *data)
{
  PView::combine(true, 2, CTX::instance()->post.combineRemoveOrig);
  FlGui::instance()->updateViews();
  drawContext::global()->draw();
}

static void view_all_visible_cb(Fl_Widget *w, void *data)
{
  int mode = (intptr_t)data;
  std::string name;
  if(mode >= 0) name = PView::list[mode]->getData()->getName();
  for(unsigned int i = 0; i < PView::list.size(); i++)
    opt_view_visible(i, GMSH_SET | GMSH_GUI,
                     (mode == -1) ? 1 :
                     (mode == -2) ? 0 :
                     (mode == -3) ? !opt_view_visible(i, GMSH_GET, 0) :
                     (name == PView::list[i]->getData()->getName()) ? 1 :
                     0);
  drawContext::global()->draw();
}

static void view_applybgmesh_cb(Fl_Widget *w, void *data)
{
  int index =  (intptr_t)data;
  if(index >= 0 && index < (int)PView::list.size())
    GModel::current()->getFields()->setBackgroundMesh(index);
}

// The static menus (we cannot use the 'g', 'm' 's' and 'p' mnemonics
// since they are already defined as global shortcuts)
static Fl_Menu_Item bar_table[] = {
  {"&File", 0, 0, 0, FL_SUBMENU},
    {"&New...",     FL_CTRL+'n', (Fl_Callback *)file_new_cb, 0},
    {"&Open...",    FL_CTRL+'o', (Fl_Callback *)file_open_cb, 0},
    {"Open Recent", 0, 0, 0, FL_SUBMENU},
      {"", 0, (Fl_Callback *)file_open_recent_cb, 0},
      {"", 0, (Fl_Callback *)file_open_recent_cb, 0},
      {"", 0, (Fl_Callback *)file_open_recent_cb, 0},
      {"", 0, (Fl_Callback *)file_open_recent_cb, 0},
      {"", 0, (Fl_Callback *)file_open_recent_cb, 0},
      {0},
    {"M&erge...",   FL_CTRL+FL_SHIFT+'o', (Fl_Callback *)file_merge_cb, 0},
    {"Watch Pattern...",    0, (Fl_Callback *)file_watch_cb, 0},
    {"&Clear",      0, (Fl_Callback *)file_clear_cb, 0, FL_MENU_DIVIDER},
#if defined(HAVE_ONELAB)
    {"Remote", 0, 0, 0, FL_MENU_DIVIDER | FL_SUBMENU},
      {"Start...",  0, (Fl_Callback *)file_remote_cb, (void*)"start"},
      {"Merge...",  0, (Fl_Callback *)file_remote_cb, (void*)"merge"},
      {"Clear",     0, (Fl_Callback *)file_remote_cb, (void*)"clear"},
      {"Stop",      0, (Fl_Callback *)file_remote_cb, (void*)"stop"},
      {0},
#endif
    {"New Window", 0, (Fl_Callback *)file_window_cb, (void*)"new"},
    {"Split Window", 0, 0, 0, FL_MENU_DIVIDER | FL_SUBMENU},
      {"Horizontally", 0, (Fl_Callback *)file_window_cb, (void*)"split_h"},
      {"Vertically",   0, (Fl_Callback *)file_window_cb, (void*)"split_v"},
      {"Clear",        0, (Fl_Callback *)file_window_cb, (void*)"split_u"},
      {0},
    {"&Rename...",  FL_CTRL+'r', (Fl_Callback *)file_rename_cb, 0},
    {"Save &As...", FL_CTRL+'s', (Fl_Callback *)file_save_as_cb, 0},
    {"Sa&ve Mesh",  FL_CTRL+FL_SHIFT+'s', (Fl_Callback *)mesh_save_cb, 0},
    {"Save Options", 0, 0, 0, FL_SUBMENU | FL_MENU_DIVIDER},
      {"For Current File", 0, (Fl_Callback *)file_options_save_cb, (void*)"file"},
      {"As Default", 0, (Fl_Callback *)file_options_save_cb, (void*)"default"},
      {0},
    {"&Quit",       FL_CTRL+'q', (Fl_Callback *)file_quit_cb, 0},
    {0},
  {"&Tools", 0, 0, 0, FL_SUBMENU},
    {"&Options",         FL_CTRL+FL_SHIFT+'n', (Fl_Callback *)options_cb, 0},
    {"Pl&ugins",         FL_CTRL+FL_SHIFT+'u', (Fl_Callback *)plugin_cb, (void*)(-1)},
    {"&Visibility",      FL_CTRL+FL_SHIFT+'v', (Fl_Callback *)visibility_cb, 0},
    {"&Clipping",        FL_CTRL+FL_SHIFT+'c', (Fl_Callback *)clip_cb, 0},
    {"&Manipulator",     FL_CTRL+FL_SHIFT+'m', (Fl_Callback *)manip_cb, 0},
#if defined(HAVE_ONELAB)
    {"&OneLab",          0, (Fl_Callback *)solver_cb, (void*)(-1), FL_MENU_DIVIDER},
#endif
#if defined(HAVE_3M)
    {"&3M",              0, (Fl_Callback *)window3M_cb, 0, FL_MENU_DIVIDER},
#endif
    {"S&tatistics",      FL_CTRL+'i', (Fl_Callback *)statistics_cb, 0},
    {"M&essage Console", FL_CTRL+'l', (Fl_Callback *)message_cb, 0},
    {0},
  {"&Help", 0, 0, 0, FL_SUBMENU},
    {"On&line Documentation", 0, (Fl_Callback *)help_online_cb, 0, FL_MENU_DIVIDER},
    {"M&ouse Actions",        0, (Fl_Callback *)help_mouse_cb, 0},
    {"&Keyboard Shortcuts",   0, (Fl_Callback *)help_short_cb, 0},
    {"C&ommand Line Options", 0, (Fl_Callback *)help_command_line_cb, 0},
    {"&Current Options",      0, (Fl_Callback *)status_options_cb, (void*)"?", FL_MENU_DIVIDER},
    {"&About Gmsh",           0, (Fl_Callback *)help_about_cb, 0},
    {0},
  {0}
};

#if defined(__APPLE__)

// Alternative items for the MacOS system menu bar (removed '&'
// shortcuts: they would cause spurious menu items to appear on the
// menu window; removed File->Quit)
static Fl_Menu_Item sysbar_table[] = {
  {"File", 0, 0, 0, FL_SUBMENU},
    {"New...",     FL_META+'n', (Fl_Callback *)file_new_cb, 0},
    {"Open...",    FL_META+'o', (Fl_Callback *)file_open_cb, 0},
  // system menu bar is not dynamic in fltk 1.1; it is in fltk 1.3
#if (FL_MAJOR_VERSION == 1) && (FL_MINOR_VERSION == 3)
    {"Open Recent", 0, 0, 0, FL_SUBMENU},
      {"", 0, (Fl_Callback *)file_open_recent_cb, 0},
      {"", 0, (Fl_Callback *)file_open_recent_cb, 0},
      {"", 0, (Fl_Callback *)file_open_recent_cb, 0},
      {"", 0, (Fl_Callback *)file_open_recent_cb, 0},
      {"", 0, (Fl_Callback *)file_open_recent_cb, 0},
      {0},
#endif
    {"Merge...",   FL_META+FL_SHIFT+'o', (Fl_Callback *)file_merge_cb, 0},
    {"Watch Pattern...",   0, (Fl_Callback *)file_watch_cb, 0},
    {"Clear",      0, (Fl_Callback *)file_clear_cb, 0, FL_MENU_DIVIDER},
    {"Remote", 0, 0, 0, FL_MENU_DIVIDER | FL_SUBMENU},
      {"Start...",  0, (Fl_Callback *)file_remote_cb, (void*)"start"},
      {"Merge...",  0, (Fl_Callback *)file_remote_cb, (void*)"merge"},
      {"Clear",     0, (Fl_Callback *)file_remote_cb, (void*)"clear"},
      {"Stop",      0, (Fl_Callback *)file_remote_cb, (void*)"stop"},
      {0},
    {"New Window", 0, (Fl_Callback *)file_window_cb, (void*)"new"},
    {"Split Window", 0, 0, 0, FL_MENU_DIVIDER | FL_SUBMENU},
      {"Horizontally", 0, (Fl_Callback *)file_window_cb, (void*)"split_h"},
      {"Vertically",   0, (Fl_Callback *)file_window_cb, (void*)"split_v"},
      {"Clear",        0, (Fl_Callback *)file_window_cb, (void*)"split_u"},
      {0},
    {"Rename...",  FL_META+'r', (Fl_Callback *)file_rename_cb, 0},
    {"Save As...", FL_META+'s', (Fl_Callback *)file_save_as_cb, 0},
    {"Save Mesh",  FL_META+FL_SHIFT+'s', (Fl_Callback *)mesh_save_cb, 0},
    {"Save Options", 0, 0, 0, FL_SUBMENU},
      {"For Current File", 0, (Fl_Callback *)file_options_save_cb, (void*)"file"},
      {"As Default", 0, (Fl_Callback *)file_options_save_cb, (void*)"default"},
      {0},
    {0},
  {"Tools", 0, 0, 0, FL_SUBMENU},
    {"Options",         FL_META+FL_SHIFT+'n', (Fl_Callback *)options_cb, 0},
    {"Plugins",         FL_META+FL_SHIFT+'u', (Fl_Callback *)plugin_cb, (void*)(-1)},
    {"Visibility",      FL_META+FL_SHIFT+'v', (Fl_Callback *)visibility_cb, 0},
    {"Clipping",        FL_META+FL_SHIFT+'c', (Fl_Callback *)clip_cb, 0},
    {"Manipulator",     FL_META+FL_SHIFT+'m', (Fl_Callback *)manip_cb, 0},
#if defined(HAVE_ONELAB)
    {"OneLab",          0, (Fl_Callback *)solver_cb, (void*)(-1), FL_MENU_DIVIDER},
#endif
#if defined(HAVE_3M)
    {"3M",              0, (Fl_Callback *)window3M_cb, 0, FL_MENU_DIVIDER},
#endif
    {"Statistics",      FL_META+'i', (Fl_Callback *)statistics_cb, 0},
    {"Message Console", FL_META+'l', (Fl_Callback *)message_cb, 0},
    {0},
  {"Window", 0, 0, 0, FL_SUBMENU},
    {"Minimize",           FL_META+'m', (Fl_Callback *)window_cb, (void*)"minimize"},
    {"Zoom",               0, (Fl_Callback *)window_cb, (void*)"zoom", FL_MENU_DIVIDER},
    {"Bring All to Front", 0, (Fl_Callback *)window_cb, (void*)"front"},
    {0},
  {"Help", 0, 0, 0, FL_SUBMENU},
    {"Online Documentation", 0, (Fl_Callback *)help_online_cb, 0, FL_MENU_DIVIDER},
    {"Mouse Actions",        0, (Fl_Callback *)help_mouse_cb, 0},
    {"Keyboard Shortcuts",   0, (Fl_Callback *)help_short_cb, 0},
    {"Command Line Options", 0, (Fl_Callback *)help_command_line_cb, 0},
#if (FL_MAJOR_VERSION == 1) && (FL_MINOR_VERSION == 3)
    {"Current Options",      0, (Fl_Callback *)status_options_cb, (void*)"?"},
#else
    {"Current Options",      0, (Fl_Callback *)status_options_cb, (void*)"?", FL_MENU_DIVIDER},
    {"About Gmsh",           0, (Fl_Callback *)help_about_cb, 0},
#endif
    {0},
  {0}
};

#endif

static Fl_Menu_Item module_table[] = {
  {"Geometry",        'g', (Fl_Callback *)mod_geometry_cb, 0},
  {"Mesh",            'm', (Fl_Callback *)mod_mesh_cb, 0},
  {"Solver",          's', (Fl_Callback *)mod_solver_cb, 0},
  {"Post-processing", 'p', (Fl_Callback *)mod_post_cb, 0},
  {0}
};

// Dynamic menus contexts
contextItem menu_geometry[] = {
  {"0Geometry"} ,
  {"Elementary entities", (Fl_Callback *)geometry_elementary_cb} ,
  {"Physical groups",     (Fl_Callback *)geometry_physical_cb} ,
  {"Edit",                (Fl_Callback *)geometry_edit_cb} ,
  {"Reload",              (Fl_Callback *)geometry_reload_cb} ,
  {""}
};
  contextItem menu_geometry_elementary[] = {
    {"0Geometry>Elementary"} ,
    {"Add",       (Fl_Callback *)geometry_elementary_add_cb} ,
    {"Delete",    (Fl_Callback *)geometry_elementary_delete_cb, (void*)0} ,
    {"Translate", (Fl_Callback *)geometry_elementary_translate_cb, (void*)0} ,
    {"Rotate",    (Fl_Callback *)geometry_elementary_rotate_cb, (void*)0} ,
    {"Split",     (Fl_Callback *)geometry_elementary_split_cb, (void*)0} ,
    {"Scale",     (Fl_Callback *)geometry_elementary_scale_cb, (void*)0} ,
    {"Symmetry",  (Fl_Callback *)geometry_elementary_symmetry_cb, (void*)0} ,
    {"Extrude",   (Fl_Callback *)geometry_elementary_extrude_cb, (void*)0} ,
    {"Coherence", (Fl_Callback *)geometry_elementary_coherence_cb} ,
    {""}
  };
    contextItem menu_geometry_elementary_add[] = {
      {"0Geometry>Elementary>Add"} ,
      {"New",       (Fl_Callback *)geometry_elementary_add_new_cb, (void*)0} ,
      {"Translate", (Fl_Callback *)geometry_elementary_add_translate_cb, (void*)0} ,
      {"Rotate",    (Fl_Callback *)geometry_elementary_add_rotate_cb, (void*)0} ,
      {"Scale",     (Fl_Callback *)geometry_elementary_add_scale_cb, (void*)0} ,
      {"Symmetry",  (Fl_Callback *)geometry_elementary_add_symmetry_cb, (void*)0} ,
      {""}
    };
      contextItem menu_geometry_elementary_add_new[] = {
        {"0Geometry>Elementary>Add>New"} ,
        {"Parameter",     (Fl_Callback *)geometry_elementary_add_new_cb, (void*)"Parameter"} ,
        {"Point",         (Fl_Callback *)geometry_elementary_add_new_cb, (void*)"Point"} ,
        {"Straight line", (Fl_Callback *)geometry_elementary_add_new_cb, (void*)"Line"} ,
        {"Spline",        (Fl_Callback *)geometry_elementary_add_new_cb, (void*)"Spline"} ,
        {"B-Spline",      (Fl_Callback *)geometry_elementary_add_new_cb, (void*)"BSpline"} ,
        {"Circle arc",    (Fl_Callback *)geometry_elementary_add_new_cb, (void*)"Circle"} ,
        {"Ellipse arc",   (Fl_Callback *)geometry_elementary_add_new_cb, (void*)"Ellipse"} ,
        {"Plane surface", (Fl_Callback *)geometry_elementary_add_new_cb, (void*)"Plane Surface"} ,
        {"Ruled surface", (Fl_Callback *)geometry_elementary_add_new_cb, (void*)"Ruled Surface"} ,
        {"Volume",        (Fl_Callback *)geometry_elementary_add_new_cb, (void*)"Volume"} ,
        {""}
      };
      contextItem menu_geometry_elementary_add_translate[] = {
        {"0Geometry>Elementary>Add>Translate"} ,
        {"Point",   (Fl_Callback *)geometry_elementary_add_translate_cb, (void*)"Point"} ,
        {"Line",    (Fl_Callback *)geometry_elementary_add_translate_cb, (void*)"Line"} ,
        {"Surface", (Fl_Callback *)geometry_elementary_add_translate_cb, (void*)"Surface"} ,
        {"Volume",  (Fl_Callback *)geometry_elementary_add_translate_cb, (void*)"Volume"} ,
        {""}
      };
      contextItem menu_geometry_elementary_add_rotate[] = {
        {"0Geometry>Elementary>Add>Rotate"} ,
        {"Point",   (Fl_Callback *)geometry_elementary_add_rotate_cb, (void*)"Point"} ,
        {"Line",    (Fl_Callback *)geometry_elementary_add_rotate_cb, (void*)"Line"} ,
        {"Surface", (Fl_Callback *)geometry_elementary_add_rotate_cb, (void*)"Surface"} ,
        {"Volume",  (Fl_Callback *)geometry_elementary_add_rotate_cb, (void*)"Volume"} ,
        {""}
      };
      contextItem menu_geometry_elementary_add_scale[] = {
        {"0Geometry>Elementary>Add>Scale"} ,
        {"Point",   (Fl_Callback *)geometry_elementary_add_scale_cb, (void*)"Point"} ,
        {"Line",    (Fl_Callback *)geometry_elementary_add_scale_cb, (void*)"Line"} ,
        {"Surface", (Fl_Callback *)geometry_elementary_add_scale_cb, (void*)"Surface"} ,
        {"Volume",  (Fl_Callback *)geometry_elementary_add_scale_cb, (void*)"Volume"} ,
        {""}
      };
      contextItem menu_geometry_elementary_add_symmetry[] = {
        {"0Geometry>Elementary>Add>Symmetry"} ,
        {"Point",   (Fl_Callback *)geometry_elementary_add_symmetry_cb, (void*)"Point"} ,
        {"Line",    (Fl_Callback *)geometry_elementary_add_symmetry_cb, (void*)"Line"} ,
        {"Surface", (Fl_Callback *)geometry_elementary_add_symmetry_cb, (void*)"Surface"} ,
        {"Volume",  (Fl_Callback *)geometry_elementary_add_symmetry_cb, (void*)"Volume"} ,
        {""}
      };
    contextItem menu_geometry_elementary_delete[] = {
      {"0Geometry>Elementary>Delete"} ,
      {"Point",   (Fl_Callback *)geometry_elementary_delete_cb, (void*)"Point"} ,
      {"Line",    (Fl_Callback *)geometry_elementary_delete_cb, (void*)"Line"} ,
      {"Surface", (Fl_Callback *)geometry_elementary_delete_cb, (void*)"Surface"} ,
      {"Volume",  (Fl_Callback *)geometry_elementary_delete_cb, (void*)"Volume"} ,
      {""}
    };
    contextItem menu_geometry_elementary_split[] = {
      {"0Geometry>Elementary>Split"},
        {"Line",(Fl_Callback *)geometry_elementary_split_cb,(void*)"Line"},
        {""}
    };
    contextItem menu_geometry_elementary_translate[] = {
      {"0Geometry>Elementary>Translate"} ,
      {"Point",   (Fl_Callback *)geometry_elementary_translate_cb, (void*)"Point"} ,
      {"Line",    (Fl_Callback *)geometry_elementary_translate_cb, (void*)"Line"} ,
      {"Surface", (Fl_Callback *)geometry_elementary_translate_cb, (void*)"Surface"} ,
      {"Volume",  (Fl_Callback *)geometry_elementary_translate_cb, (void*)"Volume"} ,
      {""}
    };
    contextItem menu_geometry_elementary_rotate[] = {
      {"0Geometry>Elementary>Rotate"} ,
      {"Point",   (Fl_Callback *)geometry_elementary_rotate_cb, (void*)"Point"} ,
      {"Line",    (Fl_Callback *)geometry_elementary_rotate_cb, (void*)"Line"} ,
      {"Surface", (Fl_Callback *)geometry_elementary_rotate_cb, (void*)"Surface"} ,
      {"Volume",  (Fl_Callback *)geometry_elementary_rotate_cb, (void*)"Volume"} ,
      {""}
    };
    contextItem menu_geometry_elementary_scale[] = {
      {"0Geometry>Elementary>Scale"} ,
      {"Point",   (Fl_Callback *)geometry_elementary_scale_cb, (void*)"Point"} ,
      {"Line",    (Fl_Callback *)geometry_elementary_scale_cb, (void*)"Line"} ,
      {"Surface", (Fl_Callback *)geometry_elementary_scale_cb, (void*)"Surface"} ,
      {"Volume",  (Fl_Callback *)geometry_elementary_scale_cb, (void*)"Volume"} ,
      {""}
    };
    contextItem menu_geometry_elementary_symmetry[] = {
      {"0Geometry>Elementary>Symmetry"} ,
      {"Point",   (Fl_Callback *)geometry_elementary_symmetry_cb, (void*)"Point"} ,
      {"Line",    (Fl_Callback *)geometry_elementary_symmetry_cb, (void*)"Line"} ,
      {"Surface", (Fl_Callback *)geometry_elementary_symmetry_cb, (void*)"Surface"} ,
      {"Volume",  (Fl_Callback *)geometry_elementary_symmetry_cb, (void*)"Volume"} ,
      {""}
    };
    contextItem menu_geometry_elementary_extrude[] = {
      {"0Geometry>Elementary>Extrude"} ,
      {"Translate", (Fl_Callback *)geometry_elementary_extrude_translate_cb, (void*)0} ,
      {"Rotate",    (Fl_Callback *)geometry_elementary_extrude_rotate_cb, (void*)0} ,
      {""}
    };
      contextItem menu_geometry_elementary_extrude_translate[] = {
        {"0Geometry>Elementary>Extrude>Translate"} ,
        {"Point",   (Fl_Callback *)geometry_elementary_extrude_translate_cb, (void*)"Point"} ,
        {"Line",    (Fl_Callback *)geometry_elementary_extrude_translate_cb, (void*)"Line"} ,
        {"Surface", (Fl_Callback *)geometry_elementary_extrude_translate_cb, (void*)"Surface"} ,
        {""}
      };
      contextItem menu_geometry_elementary_extrude_rotate[] = {
        {"0Geometry>Elementary>Extrude>Rotate"} ,
        {"Point",   (Fl_Callback *)geometry_elementary_extrude_rotate_cb, (void*)"Point"} ,
        {"Line",    (Fl_Callback *)geometry_elementary_extrude_rotate_cb, (void*)"Line"} ,
        {"Surface", (Fl_Callback *)geometry_elementary_extrude_rotate_cb, (void*)"Surface"} ,
        {""}
      };
  contextItem menu_geometry_physical[] = {
    {"0Geometry>Physical"} ,
    {"Add",    (Fl_Callback *)geometry_physical_add_cb, (void*)0} ,
    {""}
  };
    contextItem menu_geometry_physical_add[] = {
      {"0Geometry>Physical>Add"} ,
      {"Point",   (Fl_Callback *)geometry_physical_add_cb, (void*)"Point" } ,
      {"Line",    (Fl_Callback *)geometry_physical_add_cb, (void*)"Line" } ,
      {"Surface", (Fl_Callback *)geometry_physical_add_cb, (void*)"Surface" } ,
      {"Volume",  (Fl_Callback *)geometry_physical_add_cb, (void*)"Volume" } ,
      {""}
    };

contextItem menu_mesh[] = {
  {"1Mesh"} ,
  {"Define",       (Fl_Callback *)mesh_define_cb} ,
  {"1D",           (Fl_Callback *)mesh_1d_cb} ,
  {"2D",           (Fl_Callback *)mesh_2d_cb} ,
  {"3D",           (Fl_Callback *)mesh_3d_cb} ,
  {"Optimize 3D",  (Fl_Callback *)mesh_optimize_cb} ,
#if defined(HAVE_NETGEN)
  {"Optimize 3D (Netgen)", (Fl_Callback *)mesh_optimize_netgen_cb} ,
#endif
  {"Set order",    (Fl_Callback *)mesh_change_order_cb} ,
  {"Inspect",      (Fl_Callback *)mesh_inspect_cb} ,
  {"Refine by splitting", (Fl_Callback *)mesh_refine_cb} ,
#if defined(HAVE_METIS) || defined(HAVE_CHACO)
  {"Partition",    (Fl_Callback *)mesh_partition_cb} ,
#endif
  {"Reclassify 2D", (Fl_Callback *)mesh_classify_cb} ,
#if defined(HAVE_FOURIER_MODEL)
  {"Reparameterize 2D", (Fl_Callback *)mesh_parameterize_cb} ,
#endif
  {"Delete",       (Fl_Callback *)mesh_delete_cb} ,
  {"Save",         (Fl_Callback *)mesh_save_cb} ,
  {""}
};
  contextItem menu_mesh_define[] = {
    {"1Mesh>Define"} ,
    {"Size fields",  (Fl_Callback *)field_cb},
    {"Element size at points", (Fl_Callback *)mesh_define_length_cb  } ,
    {"Embedded points", (Fl_Callback *)mesh_define_embedded_cb, (void*)"point" } ,
    {"Recombine",   (Fl_Callback *)mesh_define_recombine_cb  } ,
    {"Transfinite", (Fl_Callback *)mesh_define_transfinite_cb  } ,
    {"Compound",    (Fl_Callback *)mesh_define_compound_cb  } ,
    {""}
  };
    contextItem menu_mesh_define_transfinite[] = {
      {"1Mesh>Define>Transfinite"} ,
      {"Line",    (Fl_Callback *)mesh_define_transfinite_line_cb} ,
      {"Surface", (Fl_Callback *)mesh_define_transfinite_surface_cb} ,
      {"Volume",  (Fl_Callback *)mesh_define_transfinite_volume_cb} ,
      {""}
    };
    contextItem menu_mesh_define_compound[] = {
      {"1Mesh>Define>Compound"} ,
      {"Line",    (Fl_Callback *)mesh_define_compound_entity_cb, (void*)"Line"} ,
      {"Surface", (Fl_Callback *)mesh_define_compound_entity_cb, (void*)"Surface"} ,
      {"Volume",  (Fl_Callback *)mesh_define_compound_entity_cb, (void*)"Volume"} ,
      {""}
    };
  contextItem menu_mesh_delete[] = {
    {"1Mesh>Edit>Delete"} ,
    {"Elements", (Fl_Callback *)mesh_delete_parts_cb, (void*)"elements"} ,
    {"Lines",    (Fl_Callback *)mesh_delete_parts_cb, (void*)"lines"} ,
    {"Surfaces", (Fl_Callback *)mesh_delete_parts_cb, (void*)"surfaces"} ,
    {"Volumes",  (Fl_Callback *)mesh_delete_parts_cb, (void*)"volumes"} ,
    {""}
  };
  contextItem menu_mesh_degree[] = {
    {"1Mesh>Set order"} ,
    {"1",  (Fl_Callback *)mesh_degree_cb, (void*)1},
    {"2",  (Fl_Callback *)mesh_degree_cb, (void*)2},
    {"3",  (Fl_Callback *)mesh_degree_cb, (void*)3},
    {"4",  (Fl_Callback *)mesh_degree_cb, (void*)4},
    {"5",  (Fl_Callback *)mesh_degree_cb, (void*)5},
    {"Optimize",  (Fl_Callback *)highordertools_cb},
    {""}
  };

contextItem menu_solver[] = {
  {"2Solver"} ,
  {"Solver 0", (Fl_Callback *)solver_cb , (void*)0} ,
  {"Solver 1", (Fl_Callback *)solver_cb , (void*)1} ,
  {"Solver 2", (Fl_Callback *)solver_cb , (void*)2} ,
  {"Solver 3", (Fl_Callback *)solver_cb , (void*)3} ,
  {"Solver 4", (Fl_Callback *)solver_cb , (void*)4} ,
  {""}
};

contextItem menu_post[] = {
  {"3Post-processing"} ,
  {""}
};

menuWindow::menuWindow()
{
  int width = 14 * FL_NORMAL_SIZE;

  // this is the initial height: no dynamic button is shown
#if defined(__APPLE__)
  if(CTX::instance()->systemMenuBar){
    _MH = BH + 6; // the menu bar is not in the application
  }
  else{
#endif
    _MH = BH + BH + 6;
#if defined(__APPLE__)
  }
#endif

  win = new mainWindow
    (width, _MH + NB_BUTT_SCROLL * BH, CTX::instance()->nonModalWindows ?
     true : false, "Gmsh");
  win->box(GMSH_WINDOW_BOX);
  win->callback(file_quit_cb);

  int y;
#if defined(__APPLE__)
  if(CTX::instance()->systemMenuBar){
    // the system menubar is kind of a hack in fltk < 1.1.7: it still
    // creates a real (invisible) menubar. To avoid spurious mouse
    // click events we make it a 1x1 pixel rectangle, 1 pixel off the
    // edge (so it falls behind the navigation buttons)
    sysbar = new Fl_Sys_Menu_Bar(1, 1, 1, 1);
    sysbar->menu(sysbar_table);
    sysbar->global();
    fillRecentHistoryMenu();
    Fl_Box *o = new Fl_Box(0, 0, width, BH + 6);
    o->box(FL_UP_BOX);
    y = 3;
  }
  else{
#endif
    bar = new Fl_Menu_Bar(0, 0, width, BH);
    bar->menu(bar_table);
    bar->box(FL_UP_BOX);
    bar->global();
    fillRecentHistoryMenu();
    Fl_Box *o = new Fl_Box(0, BH, width, BH + 6);
    o->box(FL_UP_BOX);
    y = BH + 3;
#if defined(__APPLE__)
  }
#endif

  navig[0] = new Fl_Button(1, y, 18, BH / 2, "@#-1<");
  navig[0]->labeltype(FL_SYMBOL_LABEL);
  navig[0]->box(FL_FLAT_BOX);
  navig[0]->selection_color(FL_WHITE);
  navig[0]->callback(mod_back_cb);
  navig[0]->tooltip("Go back one in the menu history (<)");

  navig[1] = new Fl_Button(1, y + BH / 2, 18, BH / 2, "@#-1>");
  navig[1]->labeltype(FL_SYMBOL_LABEL);
  navig[1]->box(FL_FLAT_BOX);
  navig[1]->selection_color(FL_WHITE);
  navig[1]->callback(mod_forward_cb);
  navig[1]->tooltip("Go forward one in the menu history (>)");

  module = new Fl_Choice(19, y, width - 24, BH);
  module->menu(module_table);
  module->box(FL_THIN_DOWN_BOX);
  // force the executation of the callback even if we didn't change
  // the selection (we want to go back to the top-level menu every
  // time we select one of the categories, even if the category is not
  // changed):
  module->when(FL_WHEN_RELEASE_ALWAYS);

  // create an empty scroll area that will get populated dynamically
  // in set_context()
  scroll = new Fl_Scroll(0, _MH, width, NB_BUTT_SCROLL * BH);
  scroll->type(Fl_Scroll::VERTICAL);
  scroll->end();

  win->size(width, _MH);
  win->position(CTX::instance()->menuPosition[0],
                CTX::instance()->menuPosition[1]);

  win->end();
}

void menuWindow::setContext(contextItem *menu_asked, int flag)
{
  static int nb_back = 0, nb_forward = 0, init_context = 0;
  static contextItem *menu_history[NB_HISTORY_MAX];
  contextItem *menu;

  if(!init_context) {
    init_context = 1;
    for(int i = 0; i < NB_HISTORY_MAX; i++) {
      menu_history[i] = 0;
    }
  }

  if(nb_back > NB_HISTORY_MAX - 2)
    nb_back = 1; // we should do a circular list

  if(flag == -1) {
    if(nb_back > 1) {
      nb_back--;
      nb_forward++;
      menu = menu_history[nb_back - 1];
    }
    else
      return;
  }
  else if(flag == 1) {
    if(nb_forward > 0) {
      nb_back++;
      nb_forward--;
      menu = menu_history[nb_back - 1];
    }
    else
      return;
  }
  else if(menu_asked){
    menu = menu_asked;
    if(!nb_back || menu_history[nb_back - 1] != menu) {
      menu_history[nb_back++] = menu;
    }
    nb_forward = 0;
  }
  else{
    Msg::Warning("No menu asked...");
    return;
  }

  if(menu[0].label[0] == '0'){
    module->value(0);
  }
  else if(menu[0].label[0] == '1'){
    module->value(1);
  }
  else if(menu[0].label[0] == '2'){
    module->value(2);
    menu[1].label = opt_solver_name0(0, GMSH_GET, "");
    menu[2].label = opt_solver_name1(0, GMSH_GET, "");
    menu[3].label = opt_solver_name2(0, GMSH_GET, "");
    menu[4].label = opt_solver_name3(0, GMSH_GET, "");
    menu[5].label = opt_solver_name4(0, GMSH_GET, "");
  }
  else if(menu[0].label[0] == '3'){
    module->value(3);
  }
  else {
    Msg::Warning("Something is wrong in dynamic menu definition");
    return;
  }

  Msg::StatusBar(1, false, menu[0].label.c_str() + 1);

  // cannot use scroll->clear() in fltk 1.1 (should be fixed in 1.3)
  for(unsigned int i = 0; i < push.size(); i++){
    scroll->remove(push[i]);
    Fl::delete_widget(push[i]);
  }
  for(unsigned int i = 0; i < toggle.size(); i++){
    scroll->remove(toggle[i]);
    Fl::delete_widget(toggle[i]);
  }
  for(unsigned int i = 0; i < toggle2.size(); i++){
    scroll->remove(toggle2[i]);
    Fl::delete_widget(toggle2[i]);
  }
  for(unsigned int i = 0; i < popup.size(); i++){
    scroll->remove(popup[i]);
    Fl::delete_widget(popup[i]);
  }
  for(unsigned int i = 0; i < popup2.size(); i++){
    scroll->remove(popup2[i]);
    Fl::delete_widget(popup2[i]);
  }

  // reset the vectors
  push.clear();
  toggle.clear();
  toggle2.clear();
  popup.clear();
  popup2.clear();
  for(unsigned int i = 0; i < label.size(); i++)
    delete [] label[i];
  label.clear();
  for(unsigned int i = 0; i < label2.size(); i++)
    delete [] label2[i];
  label2.clear();

  int width = win->w();
  int popw = 4 * FL_NORMAL_SIZE + 3;

  // construct the dynamic menu
  int nb = 0;
  if(module->value() == 3){ // post-processing context
    for(nb = 0; nb < (int)PView::list.size(); nb++) {
      PViewData *data = PView::list[nb]->getData();
      PViewOptions *opt = PView::list[nb]->getOptions();

      Fl_Light_Button *b1 = new Fl_Light_Button(0, _MH + nb * BH, width - popw, BH);
      b1->callback(view_toggle_cb, (void *)nb);
      b1->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
      b1->value(opt->visible);
      b1->copy_label(data->getName().c_str());
      char *tmp2 = new char[data->getFileName().size() + 1];
      strcpy(tmp2, data->getFileName().c_str());
      b1->tooltip(tmp2);
      label2.push_back(tmp2);

      char *tmp = new char[32];
      sprintf(tmp, "[%d]@#-1>", nb);
      Fl_Button *b2 = new Fl_Button(width - popw, _MH + nb * BH, popw, BH, tmp);
      label.push_back(tmp);
      b2->align(FL_ALIGN_RIGHT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
      b2->tooltip("Show view option menu (Shift+w)");

      popupButton *p[2];
      p[0] = new popupButton(width - popw, _MH + nb * BH, popw, BH);
      p[0]->type(Fl_Menu_Button::POPUP123);
      p[1] = new popupButton(0, _MH + nb * BH, width - popw, BH);
      p[1]->type(Fl_Menu_Button::POPUP3);

      for(int j = 0; j < 2; j++) {
        p[j]->add("Reload/View", 'r',
                  (Fl_Callback *) view_reload_cb, (void *)nb, 0);
        p[j]->add("Reload/Visible Views", 0,
                  (Fl_Callback *) view_reload_visible_cb, (void *)nb, 0);
        p[j]->add("Reload/All Views", 0,
                  (Fl_Callback *) view_reload_all_cb, (void *)nb, 0);
        p[j]->add("Remove/View", FL_Delete,
                  (Fl_Callback *) view_remove_cb, (void *)nb, 0);
        p[j]->add("Remove/Other Views", 0,
                  (Fl_Callback *) view_remove_other_cb, (void *)nb, 0);
        p[j]->add("Remove/Visible Views", 0,
                  (Fl_Callback *) view_remove_all_cb, (void *)-2, 0);
        p[j]->add("Remove/Invisible Views", 0,
                  (Fl_Callback *) view_remove_all_cb, (void *)-3, 0);
        p[j]->add("Remove/Empty Views", 0,
                  (Fl_Callback *) view_remove_all_cb, (void *)-4, 0);
        p[j]->add("Remove/All Views", 0,
                  (Fl_Callback *) view_remove_all_cb, (void *)-1, 0);
        p[j]->add("Remove/By Name", 0,
                  (Fl_Callback *) view_remove_all_cb, (void *)nb, 0);
        p[j]->add("Alias/View without Options", 0,
                  (Fl_Callback *) view_alias_cb, (void *)nb, 0);
        p[j]->add("Alias/View with Options", 0,
                  (Fl_Callback *) view_alias_with_options_cb, (void *)nb, 0);
        p[j]->add("Combine Elements/From Visible Views", 0,
                  (Fl_Callback *) view_combine_space_visible_cb, (void *)nb, 0);
        p[j]->add("Combine Elements/From All Views", 0,
                  (Fl_Callback *) view_combine_space_all_cb, (void *)nb, 0);
        p[j]->add("Combine Elements/By View Name", 0,
                  (Fl_Callback *) view_combine_space_by_name_cb, (void *)nb, 0);
        p[j]->add("Combine Time Steps/From Visible Views", 0,
                  (Fl_Callback *) view_combine_time_visible_cb, (void *)nb, 0);
        p[j]->add("Combine Time Steps/From All Views", 0,
                  (Fl_Callback *) view_combine_time_all_cb, (void *)nb, 0);
        p[j]->add("Combine Time Steps/By View Name", 0,
                 (Fl_Callback *) view_combine_time_by_name_cb, (void *)nb, 0);
        p[j]->add("Set Visibility/All On", 0,
                  (Fl_Callback *) view_all_visible_cb, (void *)-1, 0);
        p[j]->add("Set Visibility/All Off", 0,
                  (Fl_Callback *) view_all_visible_cb, (void *)-2, 0);
        p[j]->add("Set Visibility/Invert", 0,
                  (Fl_Callback *) view_all_visible_cb, (void *)-3, 0);
        p[j]->add("Set Visibility/By name", 0,
                  (Fl_Callback *) view_all_visible_cb, (void *)nb, 0);
        p[j]->add("Apply As Background Mesh", 0,
                  (Fl_Callback *) view_applybgmesh_cb, (void *)nb, 0);
        p[j]->add("Save As...", 0,
                  (Fl_Callback *) view_save_cb, (void *)nb, FL_MENU_DIVIDER);
        p[j]->add("Options", 'o',
                  (Fl_Callback *) view_options_cb, (void *)nb, 0);
        p[j]->add("Plugins", 'p',
                  (Fl_Callback *) plugin_cb, (void *)nb, 0);
      }

      toggle.push_back(b1);
      toggle2.push_back(b2);
      popup.push_back(p[0]);
      popup2.push_back(p[1]);
      scroll->add(b1);
      scroll->add(b2);
      scroll->add(p[0]);
      scroll->add(p[1]);
    }
  }
  else{ // geometry, mesh and solver contexts
    while(menu[nb + 1].label.size()) {
      Fl_Button *b = new Fl_Button(0, _MH + nb * BH, width, BH);
      b->copy_label(menu[nb + 1].label.c_str());
      b->callback(menu[nb + 1].callback, menu[nb + 1].arg);
      push.push_back(b);
      scroll->add(b);
      nb++;
    }
  }

  /* scroll to the end of the list
  int hh = (nb - NB_BUTT_SCROLL) * BH;
  if(hh > 0) scroll->scroll_to(0, hh);
  */

  scroll->redraw();

  if(nb <= NB_BUTT_SCROLL)
    win->size(width, _MH + nb * BH);
  else
    win->size(width, _MH + NB_BUTT_SCROLL * BH);
}

void menuWindow::fillRecentHistoryMenu()
{
  Fl_Menu_Item *table = bar_table;
#if defined(__APPLE__) && (FL_MAJOR_VERSION == 1) && (FL_MINOR_VERSION == 3)
  if(CTX::instance()->systemMenuBar)
    table = sysbar_table;
#endif

  for(int i = 0; i < 5; i++){
    table[4 + i].text = CTX::instance()->recentFiles[i].c_str();
    table[4 + i].user_data_ = (void*)CTX::instance()->recentFiles[i].c_str();
  }

#if defined(__APPLE__) && (FL_MAJOR_VERSION == 1) && (FL_MINOR_VERSION == 3)
  if(CTX::instance()->systemMenuBar)
    sysbar->menu(table);
#endif
}
