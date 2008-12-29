// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <string.h>
#include <stdio.h>
#include <time.h>
#include <FL/Fl_Box.H>
#include <FL/fl_ask.H>
#include "GUI.h"
#include "Draw.h"
#include "menuWindow.h"
#include "shortcutWindow.h"
#include "graphicWindow.h"
#include "optionWindow.h"
#include "statisticsWindow.h"
#include "messageWindow.h"
#include "contextWindow.h"
#include "visibilityWindow.h"
#include "clippingWindow.h"
#include "manipWindow.h"
#include "fieldWindow.h"
#include "pluginWindow.h"
#include "solverWindow.h"
#include "aboutWindow.h"
#include "fileDialogs.h"
#include "partitionDialog.h"
#include "projectionEditor.h"
#include "classificationEditor.h"
#include "Options.h"
#include "Solvers.h"
#include "GmshMessage.h"
#include "CommandLine.h"
#include "Generator.h"
#include "HighOrder.h"
#include "GModel.h"
#include "PView.h"
#include "PViewData.h"
#include "PViewOptions.h"
#include "Field.h"
#include "OS.h"
#include "StringUtils.h"
#include "OpenFile.h"
#include "CreateFile.h"
#include "findLinks.h"
#include "GeoStringInterface.h"
#include "Options.h"
#include "Context.h"

extern Context_T CTX;

static void file_new_cb(Fl_Widget *w, void *data)
{
 test:
  if(file_chooser(0, 1, "New", "*")) {
    std::string name = file_chooser_get_name(1);
    if(!StatFile(name.c_str())){
      if(fl_choice("File '%s' already exists.\n\nDo you want to erase it?",
                   "Cancel", "Erase", NULL, name.c_str()))
        UnlinkFile(name.c_str());
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
    OpenProject(name.c_str());
    Draw();
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
  "All files" TT "*" NN
  "Gmsh geometry" TT "*.geo" NN
  "Gmsh mesh" TT "*.msh" NN
  "Gmsh post-processing view" TT "*.pos" NN
#if defined(HAVE_OCC)
  "STEP model" TT "*.{stp,step}" NN
  "IGES model" TT "*.{igs,iges}" NN
  "BRep model" TT "*.brep" NN
#endif
  "I-deas universal mesh" TT "*.unv" NN
  "Diffpack 3D mesh" TT "*.diff" NN
  "VTK mesh" TT "*.vtk" NN
#if defined(HAVE_MED)
  "MED file" TT "*.{med,mmed,rmed}" NN
#endif
  "Medit mesh" TT "*.mesh" NN
  "Nastran bulk data file" TT "*.{bdf,nas}" NN
  "Plot3D structured mesh" TT "*.p3d" NN
  "STL surface mesh" TT "*.stl" NN
  "VRML surface mesh" TT "*.{wrl,vrml}" NN
#if defined(HAVE_LIBJPEG)
  "JPEG" TT "*.{jpg,jpeg}" NN
#endif
#if defined(HAVE_LIBPNG)
  "PNG" TT "*.png" NN
#endif
  "BMP" TT "*.bmp" NN
  "PPM" TT "*.ppm" NN
  "PGM" TT "*.pgm" NN
  "PBM" TT "*.pbm" NN
  "PNM" TT "*.pnm" NN;

static void file_open_cb(Fl_Widget *w, void *data)
{
  int n = PView::list.size();
  if(file_chooser(0, 0, "Open", input_formats)) {
    OpenProject(file_chooser_get_name(1).c_str());
    Draw();
  }
  if(n != (int)PView::list.size())
    GUI::instance()->menu->setContext(menu_post, 0);
}

static void file_merge_cb(Fl_Widget *w, void *data)
{
  int n = PView::list.size();
  int f = file_chooser(1, 0, "Merge", input_formats);
  if(f) {
    for(int i = 1; i <= f; i++)
      MergeFile(file_chooser_get_name(i).c_str());
    Draw();
  }
  if(n != (int)PView::list.size())
    GUI::instance()->menu->setContext(menu_post, 0);
}

static int _save_msh(const char *name){ return msh_dialog(name); }
static int _save_pos(const char *name){ return pos_dialog(name); }
static int _save_options(const char *name){ return options_dialog(name); }
static int _save_geo(const char *name){ return geo_dialog(name); }
static int _save_cgns(const char *name){ return cgns_write_dialog(name); }
static int _save_unv(const char *name){ return unv_dialog(name); }
static int _save_vtk(const char *name){ return generic_mesh_dialog
    (name, "VTK Options", FORMAT_VTK, true); }
static int _save_diff(const char *name){ return generic_mesh_dialog
    (name, "Diffpack Options", FORMAT_DIFF, true); }
static int _save_med(const char *name){ return generic_mesh_dialog
    (name, "MED Options", FORMAT_MED, false); }
static int _save_mesh(const char *name){ return generic_mesh_dialog
    (name, "MESH Options", FORMAT_MESH, false); }
static int _save_bdf(const char *name){ return bdf_dialog(name); }
static int _save_p3d(const char *name){ return generic_mesh_dialog
    (name, "P3D Options", FORMAT_P3D, false); }
static int _save_stl(const char *name){ return generic_mesh_dialog
    (name, "STL Options", FORMAT_STL, true); }
static int _save_vrml(const char *name){ return generic_mesh_dialog
    (name, "VRML Options", FORMAT_VRML, false); }
static int _save_eps(const char *name){ return gl2ps_dialog
    (name, "EPS Options", FORMAT_EPS); }
static int _save_gif(const char *name){ return gif_dialog(name); }
static int _save_jpeg(const char *name){ return jpeg_dialog(name); }
static int _save_tex(const char *name){ return latex_dialog(name); }
static int _save_pdf(const char *name){ return gl2ps_dialog
    (name, "PDF Options", FORMAT_PDF); }
static int _save_png(const char *name){ return generic_bitmap_dialog
    (name, "PNG Options", FORMAT_PNG); }
static int _save_ps(const char *name){ return gl2ps_dialog
    (name, "PS Options", FORMAT_PS); }
static int _save_ppm(const char *name){ return generic_bitmap_dialog
    (name, "PPM Options", FORMAT_PPM); }
static int _save_svg(const char *name){ return gl2ps_dialog
    (name, "SVG Options", FORMAT_SVG); }
static int _save_yuv(const char *name){ return generic_bitmap_dialog
    (name, "YUV Options", FORMAT_YUV); }

static int _save_auto(const char *name)
{
  switch(GuessFileFormatFromFileName(name)){
  case FORMAT_MSH  : return _save_msh(name);
  case FORMAT_POS  : return _save_pos(name);
  case FORMAT_OPT  : return _save_options(name);
  case FORMAT_GEO  : return _save_geo(name);
  case FORMAT_CGNS : return _save_cgns(name);
  case FORMAT_UNV  : return _save_unv(name);
  case FORMAT_VTK  : return _save_vtk(name);
  case FORMAT_MED  : return _save_med(name);
  case FORMAT_MESH : return _save_mesh(name);
  case FORMAT_BDF  : return _save_bdf(name);
  case FORMAT_DIFF : return _save_diff(name);
  case FORMAT_P3D  : return _save_p3d(name);
  case FORMAT_STL  : return _save_stl(name);
  case FORMAT_VRML : return _save_vrml(name);
  case FORMAT_EPS  : return _save_eps(name);
  case FORMAT_GIF  : return _save_gif(name);
  case FORMAT_JPEG : return _save_jpeg(name);
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
    {"Guess from extension" TT "*.*", _save_auto},
    {"Gmsh mesh" TT "*.msh", _save_msh},
    {"Gmsh mesh statistics" TT "*.pos", _save_pos},
    {"Gmsh options" TT "*.opt", _save_options},
    {"Gmsh unrolled geometry" TT "*.geo", _save_geo},
#if defined(HAVE_LIBCGNS)
    {"CGNS" TT "*.cgns", _save_cgns},
#endif
    {"I-deas universal mesh" TT "*.unv", _save_unv},
    {"Diffpack 3D mesh" TT "*.diff", _save_diff},
    {"VTK mesh" TT "*.vtk", _save_vtk},
#if defined(HAVE_MED)
    {"MED file" TT "*.med", _save_med},
#endif
    {"Medit mesh" TT "*.mesh", _save_mesh},
    {"Nastran bulk data file" TT "*.bdf", _save_bdf},
    {"Plot3D structured mesh" TT "*.p3d", _save_p3d},
    {"STL surface mesh" TT "*.stl", _save_stl},
    {"VRML surface mesh" TT "*.wrl", _save_vrml},
    {"Encapsulated PostScript" TT "*.eps", _save_eps},
    {"GIF" TT "*.gif", _save_gif},
#if defined(HAVE_LIBJPEG)
    {"JPEG" TT "*.jpg", _save_jpeg},
#endif
    {"LaTeX" TT "*.tex", _save_tex},
    {"PDF" TT "*.pdf", _save_pdf},
#if defined(HAVE_LIBPNG)
    {"PNG" TT "*.png", _save_png},
#endif
    {"PostScript" TT "*.ps", _save_ps},
    {"PPM" TT "*.ppm", _save_ppm},
    {"SVG" TT "*.svg", _save_svg},
    {"YUV" TT "*.yuv", _save_yuv},
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
  if(file_chooser(0, 1, "Save As", pat)) {
    std::string name = file_chooser_get_name(1);
    if(CTX.confirm_overwrite) {
      if(!StatFile(name.c_str()))
        if(!fl_choice("File '%s' already exists.\n\nDo you want to replace it?", 
                      "Cancel", "Replace", NULL, name.c_str()))
          goto test;
    }
    int i = file_chooser_get_filter();
    if(i >= 0 && i < nbformats){
      if(!formats[i].func(name.c_str())) goto test;
    }
    else{ // handle any additional automatic fltk filter
      if(!_save_auto(name.c_str())) goto test;
    }
  }
}

#undef TT
#undef NN

static void file_rename_cb(Fl_Widget *w, void *data)
{
 test:
  if(file_chooser(0, 1, "Rename", "*", CTX.filename)) {
    std::string name = file_chooser_get_name(1);
    if(CTX.confirm_overwrite) {
      if(!StatFile(name.c_str()))
        if(!fl_choice("File '%s' already exists.\n\nDo you want to replace it?", 
                      "Cancel", "Replace", NULL, name.c_str()))
          goto test;
    }
    rename(CTX.filename, name.c_str());
    OpenProject(name.c_str());
    Draw();
  }
}

void file_quit_cb(Fl_Widget *w, void *data)
{
  Msg::Exit(0);
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
  GUI::instance()->messages->show();
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
  GUI::instance()->messages->show();
}

static void help_command_line_cb(Fl_Widget *w, void *data)
{
  Msg::Direct(" ");
  Print_Usage("gmsh");
  GUI::instance()->messages->show();
}

static void help_online_cb(Fl_Widget *w, void *data)
{
  std::string prog = FixWindowsPath(CTX.web_browser);
  char cmd[1024];
  ReplaceMultiFormat(prog.c_str(), "http://geuz.org/gmsh/doc/texinfo/", cmd);
  SystemCall(cmd);
}

static void help_about_cb(Fl_Widget *w, void *data)
{
  GUI::instance()->about->win->show();
}

void mod_geometry_cb(Fl_Widget *w, void *data)
{
  GUI::instance()->menu->setContext(menu_geometry, 0);
}

void mod_mesh_cb(Fl_Widget *w, void *data)
{
  GUI::instance()->menu->setContext(menu_mesh, 0);
}

void mod_solver_cb(Fl_Widget *w, void *data)
{
  GUI::instance()->menu->setContext(menu_solver, 0);
}

void mod_post_cb(Fl_Widget *w, void *data)
{
  GUI::instance()->menu->setContext(menu_post, 0);
}

void mod_back_cb(Fl_Widget *w, void *data)
{
  GUI::instance()->menu->setContext(NULL, -1);
}

void mod_forward_cb(Fl_Widget *w, void *data)
{
  GUI::instance()->menu->setContext(NULL, 1);
}

static void geometry_elementary_cb(Fl_Widget *w, void *data)
{
  GUI::instance()->menu->setContext(menu_geometry_elementary, 0);
}

static void geometry_physical_cb(Fl_Widget *w, void *data)
{
  GUI::instance()->menu->setContext(menu_geometry_physical, 0);
}

static void geometry_edit_cb(Fl_Widget *w, void *data)
{
  std::string prog = FixWindowsPath(CTX.editor);
  std::string file = FixWindowsPath(CTX.filename);
  char cmd[1024];
  ReplaceMultiFormat(prog.c_str(), file.c_str(), cmd);
  SystemCall(cmd);
}

void geometry_reload_cb(Fl_Widget *w, void *data)
{
  OpenProject(CTX.filename);
  Draw();
}

static void geometry_elementary_add_cb(Fl_Widget *w, void *data)
{
  GUI::instance()->menu->setContext(menu_geometry_elementary_add, 0);
}

static void add_new_point()
{
  opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  Draw();

  GUI::instance()->geoContext->show(1);

  while(1) {
    for(unsigned int i = 0; i < GUI::instance()->graph.size(); i++)
      GUI::instance()->graph[i]->gl->addPointMode = true;
    Msg::StatusBar(3, false, "Move mouse and/or enter coordinates\n"
                   "[Press 'Shift' to hold position, 'e' to add point "
                   "or 'q' to abort]");
    char ib = GUI::instance()->selectEntity(ENT_NONE);
    if(ib == 'e'){
      add_point(CTX.filename,
                GUI::instance()->geoContext->input[2]->value(),
                GUI::instance()->geoContext->input[3]->value(),
                GUI::instance()->geoContext->input[4]->value(),
                GUI::instance()->geoContext->input[5]->value());
      GUI::instance()->resetVisibility();
      Draw();
    }
    if(ib == 'q'){
      for(unsigned int i = 0; i < GUI::instance()->graph.size(); i++)
        GUI::instance()->graph[i]->gl->addPointMode = false;
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
  Draw();

  std::vector<int> p;
  while(1) {
    if(p.empty())
      Msg::StatusBar(3, false, "Select control points\n"
                     "[Press 'e' to end selection or 'q' to abort]");
    else
      Msg::StatusBar(3, false, "Select control points\n"
                     "[Press 'e' to end selection, 'u' to undo last selection "
                     "or 'q' to abort]");
    char ib = GUI::instance()->selectEntity(ENT_POINT);
    if(ib == 'l') {
      for(unsigned int i = 0; i < GUI::instance()->selectedVertices.size(); i++){
        GUI::instance()->selectedVertices[i]->setSelection(1);
        p.push_back(GUI::instance()->selectedVertices[i]->tag());
      }
      Draw();
    }
    if(ib == 'r') {
      Msg::Warning("Entity de-selection not supported yet during multi-line creation");
    }
    if(ib == 'e') {
      if(p.size() >= 2)
	add_multline(type, p, CTX.filename);
      GUI::instance()->resetVisibility();
      GModel::current()->setSelection(0);
      Draw();
      p.clear();
    }
    if(ib == 'u') {
      if(p.size()){
        GVertex *gv = GModel::current()->getVertexByTag(p.back());
        if(gv) gv->setSelection(0);
        Draw();
        p.pop_back();
      }
    }
    if(ib == 'q') {
      GModel::current()->setSelection(0);
      Draw();
      break;
    }
  }

  Msg::StatusBar(3, false, "");
}

static void add_new_line()
{
  opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  opt_geometry_lines(0, GMSH_SET | GMSH_GUI, 1);
  Draw();

  std::vector<int> p;
  while(1) {
    if(p.empty())
      Msg::StatusBar(3, false, "Select start point\n"
                     "[Press 'q' to abort]");
    if(p.size() == 1)
      Msg::StatusBar(3, false, "Select end point\n"
                     "[Press 'u' to undo last selection or 'q' to abort]");
    char ib = GUI::instance()->selectEntity(ENT_POINT);
    if(ib == 'l') {
      GUI::instance()->selectedVertices[0]->setSelection(1);
      Draw();
      p.push_back(GUI::instance()->selectedVertices[0]->tag());
    }
    if(ib == 'r') {
      Msg::Warning("Entity de-selection not supported yet during line creation");
    }
    if(ib == 'u') {
      if(p.size()){
        GVertex *gv = GModel::current()->getVertexByTag(p.back());
        if(gv) gv->setSelection(0);
        Draw();
        p.pop_back();
      }
    }
    if(ib == 'q') {
      GModel::current()->setSelection(0);
      Draw();
      break;
    }
    if(p.size() == 2) {
      add_multline("Line", p, CTX.filename);
      GUI::instance()->resetVisibility();
      GModel::current()->setSelection(0);
      Draw();
      p.clear();
    }
  }

  Msg::StatusBar(3, false, "");
}

static void add_new_circle()
{
  opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  opt_geometry_lines(0, GMSH_SET | GMSH_GUI, 1);
  Draw();

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
    char ib = GUI::instance()->selectEntity(ENT_POINT);
    if(ib == 'l') {
      GUI::instance()->selectedVertices[0]->setSelection(1);
      Draw();
      p.push_back(GUI::instance()->selectedVertices[0]->tag());
    }
    if(ib == 'r') {
      Msg::Warning("Entity de-selection not supported yet during circle creation");
    }
    if(ib == 'u') {
      if(p.size()){
        GVertex *gv = GModel::current()->getVertexByTag(p.back());
        if(gv) gv->setSelection(0);
        Draw();
        p.pop_back();
      }
    }
    if(ib == 'q') {
      GModel::current()->setSelection(0);
      Draw();
      break;
    }
    if(p.size() == 3) {
      add_circ(p[0], p[1], p[2], CTX.filename); // begin, center, end
      GUI::instance()->resetVisibility();
      GModel::current()->setSelection(0);
      Draw();
      p.clear();
    }
  }

  Msg::StatusBar(3, false, "");
}

static void add_new_ellipse()
{
  opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  opt_geometry_lines(0, GMSH_SET | GMSH_GUI, 1);
  Draw();

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
    char ib = GUI::instance()->selectEntity(ENT_POINT);
    if(ib == 'l') {
      GUI::instance()->selectedVertices[0]->setSelection(1);
      Draw();
      p.push_back(GUI::instance()->selectedVertices[0]->tag());
    }
    if(ib == 'r') {
      Msg::Warning("Entity de-selection not supported yet during ellipse creation");
    }
    if(ib == 'u') {
      if(p.size()){
        GVertex *gv = GModel::current()->getVertexByTag(p.back());
        if(gv) gv->setSelection(0);
        Draw();
        p.pop_back();
      }
    }
    if(ib == 'q') {
      GModel::current()->setSelection(0);
      Draw();
      break;
    }
    if(p.size() == 4) {
      add_ell(p[0], p[1], p[2], p[3], CTX.filename);
      GUI::instance()->resetVisibility();
      GModel::current()->setSelection(0);
      Draw();
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

  Draw();
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
  Draw();

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
      
      char ib = GUI::instance()->selectEntity(type);
      if(ib == 'q') {
        GModel::current()->setSelection(0);
        Draw();
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
          Draw();
        }
      }
      if(ib == 'r') {
        Msg::Warning("Entity de-selection not supported yet during "
                     "surface/volume creation");
      }
      if(ib == 'l') {
        int num = (type == ENT_LINE) ?
          GUI::instance()->selectedEdges[0]->tag() :
          GUI::instance()->selectedFaces[0]->tag();
        if(select_contour(type, num, List1)) {
          if(type == ENT_LINE)
            add_lineloop(List1, CTX.filename, &num);
          else
            add_surfloop(List1, CTX.filename, &num);
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
            ib = GUI::instance()->selectEntity(type);
            if(ib == 'q') {
              GModel::current()->setSelection(0);
              Draw();
              goto stopall;
            }
            if(ib == 'e') {
              GModel::current()->setSelection(0);
              Draw();
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
                Draw();
              }
            }
            if(ib == 'l') {
              int num = (type == ENT_LINE) ? 
                GUI::instance()->selectedEdges[0]->tag() :
                GUI::instance()->selectedFaces[0]->tag();
              if(select_contour(type, num, List1)) {
                if(type == ENT_LINE)
                  add_lineloop(List1, CTX.filename, &num);
                else
                  add_surfloop(List1, CTX.filename, &num);
                List_Reset(List1);
                List_Add(List2, &num);
              }
            }
            if(ib == 'r') {
              Msg::Warning("Entity de-selection not supported yet during "
                           "surface/volume creation");
            }
          }
          if(List_Nbr(List2)) {
            switch (mode) {
            case 0: add_surf("Plane Surface", List2, CTX.filename); break;
            case 1: add_surf("Ruled Surface", List2, CTX.filename); break;
            case 2: add_vol(List2, CTX.filename); break;
            }
            GUI::instance()->resetVisibility();
            GModel::current()->setSelection(0);
            Draw();
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
    GUI::instance()->menu->setContext(menu_geometry_elementary_add_new, 0);
    return;
  }

  std::string str((const char*)data);
  if(str == "Parameter")
    GUI::instance()->geoContext->show(0);
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
  Draw();
  Msg::StatusBar(3, false, "Select a line to split\n"
                 "[Press 'q' to abort]");
  GEdge* edge_to_split = 0;
  while(1){
    char ib = GUI::instance()->selectEntity(ENT_LINE);
    if(ib == 'q')
      break;
    if(!GUI::instance()->selectedEdges.empty()){
      edge_to_split = GUI::instance()->selectedEdges[0];
      edge_to_split->setSelection(1);
      break;
    }
  }
  Msg::StatusBar(3, false, "");
  if(GUI::instance()->selectedEdges.empty()) return;
  List_T *List1 = List_Create(5, 5, sizeof(int));
  Msg::StatusBar(3, false, "Select break points\n"
                 "[Press 'e' to end selection or 'q' to abort]");
  opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  Draw();
  while(1){
    char ib = GUI::instance()->selectEntity(ENT_POINT);
    if(ib == 'q')
      break;
    if(ib == 'e'){
      split_edge(edge_to_split->tag(), List1, CTX.filename);
      break;
    }
    for(unsigned int i = 0; i < GUI::instance()->selectedVertices.size(); i++){
      int tag = GUI::instance()->selectedVertices[i]->tag();
      int index = List_ISearchSeq(List1, &tag, fcmp_int); 
      if(index < 0) List_Add(List1, &tag);
      GUI::instance()->selectedVertices[i]->setSelection(1);
    }
  }
  Msg::StatusBar(3, false, "");
  GUI::instance()->resetVisibility();
  GModel::current()->setSelection(0);
  Draw();
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
    GUI::instance()->meshContext->show(0);
  }

  Draw();
    
  List_T *List1 = List_Create(5, 5, sizeof(int));
  while(1) {
    if(!List_Nbr(List1))
      Msg::StatusBar(3, false, "Select %s\n"
                     "[Press 'e' to end selection or 'q' to abort]", str);
    else
      Msg::StatusBar(3, false, "Select %s\n"
                     "[Press 'e' to end selection, 'u' to undo last selection "
                     "or 'q' to abort]", str);
    
    char ib = GUI::instance()->selectEntity(type);
    if(ib == 'l') {
      // we don't use List_Insert in order to keep the original
      // ordering (this is slower, but this way undo works as
      // expected)
      int tag;
      switch (type) {
      case ENT_POINT: 
        for(unsigned int i = 0; i < GUI::instance()->selectedVertices.size(); i++){
          GUI::instance()->selectedVertices[i]->setSelection(1);
          tag = GUI::instance()->selectedVertices[i]->tag();
          if(List_ISearchSeq(List1, &tag, fcmp_int) < 0)
            List_Add(List1, &tag);
        }
        break;
      case ENT_LINE:
        for(unsigned int i = 0; i < GUI::instance()->selectedEdges.size(); i++){
          GUI::instance()->selectedEdges[i]->setSelection(1);
          tag = GUI::instance()->selectedEdges[i]->tag();
          if(List_ISearchSeq(List1, &tag, fcmp_int) < 0)
            List_Add(List1, &tag);
        }
        break;
      case ENT_SURFACE:
        for(unsigned int i = 0; i < GUI::instance()->selectedFaces.size(); i++){
          GUI::instance()->selectedFaces[i]->setSelection(1);
          tag = GUI::instance()->selectedFaces[i]->tag();
          if(List_ISearchSeq(List1, &tag, fcmp_int) < 0)
            List_Add(List1, &tag);
        }
        break;
      case ENT_VOLUME:
        for(unsigned int i = 0; i < GUI::instance()->selectedRegions.size(); i++){
          GUI::instance()->selectedRegions[i]->setSelection(1);
          tag = GUI::instance()->selectedRegions[i]->tag();
          if(List_ISearchSeq(List1, &tag, fcmp_int) < 0)
            List_Add(List1, &tag);
        }
        break;
      }
      Draw();
    }
    if(ib == 'r') {
      // we don't use List_Suppress in order to keep the original
      // ordering (this is slower, but this way undo works as
      // expected)
      int index, tag;
      switch (type) {
      case ENT_POINT:
        for(unsigned int i = 0; i < GUI::instance()->selectedVertices.size(); i++){
          tag = GUI::instance()->selectedVertices[i]->tag();
          index = List_ISearchSeq(List1, &tag, fcmp_int); 
          if(index >= 0) List_PSuppress(List1, index);
          GUI::instance()->selectedVertices[i]->setSelection(0);
        }
        break;
      case ENT_LINE:
        for(unsigned int i = 0; i < GUI::instance()->selectedEdges.size(); i++){
          tag = GUI::instance()->selectedEdges[i]->tag();
          index = List_ISearchSeq(List1, &tag, fcmp_int); 
          if(index >= 0) List_PSuppress(List1, index);
          GUI::instance()->selectedEdges[i]->setSelection(0);
        }
        break;
      case ENT_SURFACE:
        for(unsigned int i = 0; i < GUI::instance()->selectedFaces.size(); i++){
          tag = GUI::instance()->selectedFaces[i]->tag();
          index = List_ISearchSeq(List1, &tag, fcmp_int); 
          if(index >= 0) List_PSuppress(List1, index);
          GUI::instance()->selectedFaces[i]->setSelection(0);
        }
        break;
      case ENT_VOLUME:
        for(unsigned int i = 0; i < GUI::instance()->selectedRegions.size(); i++){
          tag = GUI::instance()->selectedRegions[i]->tag();
          index = List_ISearchSeq(List1, &tag, fcmp_int); 
          if(index >= 0) List_PSuppress(List1, index);
          GUI::instance()->selectedRegions[i]->setSelection(0);
        }
        break;
      }
      Draw();
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
        Draw();
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
          translate(mode, List1, CTX.filename, what,
                    GUI::instance()->geoContext->input[6]->value(),
                    GUI::instance()->geoContext->input[7]->value(),
                    GUI::instance()->geoContext->input[8]->value());
          break;
        case 1:
          rotate(mode, List1, CTX.filename, what,
                 GUI::instance()->geoContext->input[12]->value(),
                 GUI::instance()->geoContext->input[13]->value(),
                 GUI::instance()->geoContext->input[14]->value(),
                 GUI::instance()->geoContext->input[9]->value(),
                 GUI::instance()->geoContext->input[10]->value(),
                 GUI::instance()->geoContext->input[11]->value(),
                 GUI::instance()->geoContext->input[15]->value());
          break;
        case 2:
          dilate(mode, List1, CTX.filename, what,
                 GUI::instance()->geoContext->input[16]->value(),
                 GUI::instance()->geoContext->input[17]->value(),
                 GUI::instance()->geoContext->input[18]->value(),
                 GUI::instance()->geoContext->input[19]->value());
          break;
        case 3:
          symmetry(mode, List1, CTX.filename, what,
                   GUI::instance()->geoContext->input[20]->value(),
                   GUI::instance()->geoContext->input[21]->value(),
                   GUI::instance()->geoContext->input[22]->value(),
                   GUI::instance()->geoContext->input[23]->value());
          break;
        case 4:
          extrude(List1, CTX.filename, what,
                  GUI::instance()->geoContext->input[6]->value(),
                  GUI::instance()->geoContext->input[7]->value(),
                  GUI::instance()->geoContext->input[8]->value());
          break;
        case 5:
          protude(List1, CTX.filename, what,
                  GUI::instance()->geoContext->input[12]->value(),
                  GUI::instance()->geoContext->input[13]->value(),
                  GUI::instance()->geoContext->input[14]->value(),
                  GUI::instance()->geoContext->input[9]->value(),
                  GUI::instance()->geoContext->input[10]->value(),
                  GUI::instance()->geoContext->input[11]->value(),
                  GUI::instance()->geoContext->input[15]->value());
          break;
        case 6:
          delet(List1, CTX.filename, what);
          break;
        case 7:
          add_physical(what, List1, CTX.filename);
          break;
        case 8:
          add_charlength(List1, CTX.filename, 
                         GUI::instance()->meshContext->input[0]->value());
          break;
        case 9:
          add_recosurf(List1, CTX.filename);
          break;

        default:
          Msg::Error("Unknown action on selected entities");
          break;
        }
        List_Reset(List1);
        GUI::instance()->resetVisibility();
        GModel::current()->setSelection(0);
        if(action <= 6) SetBoundingBox();
        Draw();
      }
    }
    if(ib == 'q') {
      GModel::current()->setSelection(0);
      Draw();
      break;
    }
  }
  List_Delete(List1);

  Msg::StatusBar(3, false, "");
}
  
static void geometry_elementary_add_translate_cb(Fl_Widget *w, void *data)
{
  if(!data){
    GUI::instance()->menu->setContext(menu_geometry_elementary_add_translate, 0);
    return;
  }
  GUI::instance()->geoContext->show(2);
  action_point_line_surface_volume(0, 1, (const char*)data);
}

static void geometry_elementary_add_rotate_cb(Fl_Widget *w, void *data)
{
  if(!data){
    GUI::instance()->menu->setContext(menu_geometry_elementary_add_rotate, 0);
    return;
  }
  GUI::instance()->geoContext->show(3);
  action_point_line_surface_volume(1, 1, (const char*)data);
}

static void geometry_elementary_add_scale_cb(Fl_Widget *w, void *data)
{
  if(!data){
    GUI::instance()->menu->setContext(menu_geometry_elementary_add_scale, 0);
    return;
  }
  GUI::instance()->geoContext->show(4);
  action_point_line_surface_volume(2, 1, (const char*)data);
}

static void geometry_elementary_add_symmetry_cb(Fl_Widget *w, void *data)
{
  if(!data){
    GUI::instance()->menu->setContext(menu_geometry_elementary_add_symmetry, 0);
    return;
  }
  GUI::instance()->geoContext->show(5);
  action_point_line_surface_volume(3, 1, (const char*)data);
}

static void geometry_elementary_translate_cb(Fl_Widget *w, void *data)
{
  if(!data){
    GUI::instance()->menu->setContext(menu_geometry_elementary_translate, 0);
    return;
  }
  GUI::instance()->geoContext->show(2);
  action_point_line_surface_volume(0, 0, (const char*)data);
}

static void geometry_elementary_rotate_cb(Fl_Widget *w, void *data)
{
  if(!data){
    GUI::instance()->menu->setContext(menu_geometry_elementary_rotate, 0);
    return;
  }
  GUI::instance()->geoContext->show(3);
  action_point_line_surface_volume(1, 0, (const char*)data);
}

static void geometry_elementary_scale_cb(Fl_Widget *w, void *data)
{
  if(!data){
    GUI::instance()->menu->setContext(menu_geometry_elementary_scale, 0);
    return;
  }
  GUI::instance()->geoContext->show(4);
  action_point_line_surface_volume(2, 0, (const char*)data);
}

static void geometry_elementary_symmetry_cb(Fl_Widget *w, void *data)
{
  if(!data){
    GUI::instance()->menu->setContext(menu_geometry_elementary_symmetry, 0);
    return;
  }
  GUI::instance()->geoContext->show(5);
  action_point_line_surface_volume(3, 0, (const char*)data);
}

static void geometry_elementary_extrude_cb(Fl_Widget *w, void *data)
{
  GUI::instance()->menu->setContext(menu_geometry_elementary_extrude, 0);
}

static void geometry_elementary_extrude_translate_cb(Fl_Widget *w, void *data)
{
  if(!data){
    GUI::instance()->menu->setContext(menu_geometry_elementary_extrude_translate, 0);
    return;
  }
  GUI::instance()->geoContext->show(2);
  action_point_line_surface_volume(4, 0, (const char*)data);
}

static void geometry_elementary_extrude_rotate_cb(Fl_Widget *w, void *data)
{
  if(!data){
    GUI::instance()->menu->setContext(menu_geometry_elementary_extrude_rotate, 0);
    return;
  }
  GUI::instance()->geoContext->show(3);
  action_point_line_surface_volume(5, 0, (const char*)data);
}

static void geometry_elementary_delete_cb(Fl_Widget *w, void *data)
{
  if(!data){
    GUI::instance()->menu->setContext(menu_geometry_elementary_delete, 0);
    return;
  }
  action_point_line_surface_volume(6, 0, (const char*)data);
}

static void geometry_elementary_split_cb(Fl_Widget *w, void *data)
{
  if(!data){
    GUI::instance()->menu->setContext(menu_geometry_elementary_split, 0);
    return;
  }
  split_selection();
}

static void geometry_elementary_coherence_cb(Fl_Widget *w, void *data)
{
  coherence(CTX.filename);
}

static void geometry_physical_add_cb(Fl_Widget *w, void *data)
{
  if(!data){
    GUI::instance()->menu->setContext(menu_geometry_physical_add, 0);
    return;
  }
  std::string str((const char*)data);
  if(str == "Point")
    GUI::instance()->callForSolverPlugin(0);
  else if(str == "Line")
    GUI::instance()->callForSolverPlugin(1);

  action_point_line_surface_volume(7, 0, str.c_str());
}

static void mesh_save_cb(Fl_Widget *w, void *data)
{
  char name[256];
  if(CTX.output_filename)
    strcpy(name, CTX.output_filename);
  else
    GetDefaultFileName(CTX.mesh.format, name);
  if(CTX.confirm_overwrite) {
    if(!StatFile(name))
      if(!fl_choice("File '%s' already exists.\n\nDo you want to replace it?",
                    "Cancel", "Replace", NULL, name))
        return;
  }
  CreateOutputFile(name, CTX.mesh.format);
}

static void mesh_define_cb(Fl_Widget *w, void *data)
{
  GUI::instance()->menu->setContext(menu_mesh_define, 0);
}

void mesh_1d_cb(Fl_Widget *w, void *data)
{
  GModel::current()->mesh(1);
  Draw();
  Msg::StatusBar(2, false, " ");
}

void mesh_2d_cb(Fl_Widget *w, void *data)
{
  GModel::current()->mesh(2);
  Draw();
  Msg::StatusBar(2, false, " ");
}

void mesh_3d_cb(Fl_Widget *w, void *data)
{
  GModel::current()->mesh(3);
  Draw();
  Msg::StatusBar(2, false, " ");
}

static void mesh_delete_cb(Fl_Widget *w, void *data)
{
  GUI::instance()->menu->setContext(menu_mesh_delete, 0);
}

static void mesh_delete_parts_cb(Fl_Widget *w, void *data)
{
  const char *str = (const char*)data;
  int what;

  if(!strcmp(str, "elements")){
    CTX.pick_elements = 1;
    what = ENT_ALL;
  }
  else if(!strcmp(str, "lines")){
    CTX.pick_elements = 0;
    what = ENT_LINE;
  }
  else if(!strcmp(str, "surfaces")){
    CTX.pick_elements = 0;
    what = ENT_SURFACE;
  }
  else if(!strcmp(str, "volumes")){
    CTX.pick_elements = 0;
    what = ENT_VOLUME;
  }
  else
    return;

  std::vector<MElement*> ele;
  std::vector<GEntity*> ent;

  while(1) {
    CTX.mesh.changed = ENT_ALL;
    Draw();

    if(ele.size() || ent.size())
      Msg::StatusBar(3, false, "Select %s\n"
                     "[Press 'e' to end selection, 'u' to undo last selection or "
                     "'q' to abort]", str);
    else
      Msg::StatusBar(3, false, "Select %s\n"
                     "[Press 'e' to end selection or 'q' to abort]", str);

    char ib = GUI::instance()->selectEntity(what);
    if(ib == 'l') {
      if(CTX.pick_elements){
        for(unsigned int i = 0; i < GUI::instance()->selectedElements.size(); i++){
          if(GUI::instance()->selectedElements[i]->getVisibility() != 2){
            GUI::instance()->selectedElements[i]->setVisibility(2); 
            ele.push_back(GUI::instance()->selectedElements[i]);
          }
        }
      }
      else{
        for(unsigned int i = 0; i < GUI::instance()->selectedEdges.size(); i++){
          if(GUI::instance()->selectedEdges[i]->getSelection() != 1){
            GUI::instance()->selectedEdges[i]->setSelection(1); 
            ent.push_back(GUI::instance()->selectedEdges[i]);
          }
        }
        for(unsigned int i = 0; i < GUI::instance()->selectedFaces.size(); i++){
          if(GUI::instance()->selectedFaces[i]->getSelection() != 1){
            GUI::instance()->selectedFaces[i]->setSelection(1); 
            ent.push_back(GUI::instance()->selectedFaces[i]);
          }
        }
        for(unsigned int i = 0; i < GUI::instance()->selectedRegions.size(); i++){
          if(GUI::instance()->selectedRegions[i]->getSelection() != 1){
            GUI::instance()->selectedRegions[i]->setSelection(1);
            ent.push_back(GUI::instance()->selectedRegions[i]);
          }
        }
      }
    }
    if(ib == 'r') {
      if(CTX.pick_elements){
        for(unsigned int i = 0; i < GUI::instance()->selectedElements.size(); i++)
          GUI::instance()->selectedElements[i]->setVisibility(1);
      }
      else{
        for(unsigned int i = 0; i < GUI::instance()->selectedEdges.size(); i++)
          GUI::instance()->selectedEdges[i]->setSelection(0);
        for(unsigned int i = 0; i < GUI::instance()->selectedFaces.size(); i++)
          GUI::instance()->selectedFaces[i]->setSelection(0);
        for(unsigned int i = 0; i < GUI::instance()->selectedRegions.size(); i++)
          GUI::instance()->selectedRegions[i]->setSelection(0);
      }
    }
    if(ib == 'u') {
      if(CTX.pick_elements){
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
      if(CTX.pick_elements){
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

  CTX.mesh.changed = ENT_ALL;
  CTX.pick_elements = 0;
  Draw();  
  Msg::StatusBar(3, false, "");
}

static void mesh_inspect_cb(Fl_Widget *w, void *data)
{
  CTX.pick_elements = 1;
  CTX.mesh.changed = ENT_ALL;
  Draw();

  while(1) {
    Msg::StatusBar(3, false, "Select element\n[Press 'q' to abort]");
    char ib = GUI::instance()->selectEntity(ENT_ALL);
    if(ib == 'l') {
      if(GUI::instance()->selectedElements.size()){
        MElement *ele = GUI::instance()->selectedElements[0];
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
        Msg::Direct("  Disto: %g", ele->distoShapeMeasure());
        CTX.mesh.changed = ENT_ALL;
        Draw();
        GUI::instance()->messages->show();
      }
    }
    if(ib == 'q') {
      GModel::current()->setSelection(0);
      break;
    }
  }

  CTX.pick_elements = 0;
  CTX.mesh.changed = ENT_ALL;
  Draw();
  Msg::StatusBar(3, false, "");
}

static void mesh_degree_cb(Fl_Widget *w, void *data)
{
  if((long)data == 2)
    SetOrderN(GModel::current(), 2, CTX.mesh.second_order_linear, 
              CTX.mesh.second_order_incomplete);
  else
    SetOrder1(GModel::current());
  CTX.mesh.changed |= (ENT_LINE | ENT_SURFACE | ENT_VOLUME);
  Draw();
  Msg::StatusBar(2, false, " ");
}

static void mesh_optimize_cb(Fl_Widget *w, void *data)
{
  if(CTX.threads_lock) {
    Msg::Info("I'm busy! Ask me that later...");
    return;
  }
  CTX.threads_lock = 1;
  OptimizeMesh(GModel::current());
  CTX.threads_lock = 0;
  CTX.mesh.changed |= (ENT_LINE | ENT_SURFACE | ENT_VOLUME);
  Draw();
  Msg::StatusBar(2, false, " ");
}

static void mesh_refine_cb(Fl_Widget *w, void *data)
{
  RefineMesh(GModel::current(), CTX.mesh.second_order_linear);
  CTX.mesh.changed |= (ENT_LINE | ENT_SURFACE | ENT_VOLUME);
  Draw();
  Msg::StatusBar(2, false, " ");
}

static void mesh_optimize_netgen_cb(Fl_Widget *w, void *data)
{
  if(CTX.threads_lock) {
    Msg::Info("I'm busy! Ask me that later...");
    return;
  }
  CTX.threads_lock = 1;
  OptimizeMeshNetgen(GModel::current());
  CTX.threads_lock = 0;
  CTX.mesh.changed |= (ENT_LINE | ENT_SURFACE | ENT_VOLUME);
  Draw();
  Msg::StatusBar(2, false, " ");
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
  GUI::instance()->menu->setContext(menu_mesh_define_transfinite, 0);
}

static void add_transfinite(int dim)
{
  opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  switch (dim) {
  case 1: opt_geometry_lines(0, GMSH_SET | GMSH_GUI, 1); break;
  case 2: opt_geometry_surfaces(0, GMSH_SET | GMSH_GUI, 1); break;
  case 3: opt_geometry_volumes(0, GMSH_SET | GMSH_GUI, 1); break;
  }
  Draw();

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
      ib = GUI::instance()->selectEntity(ENT_LINE);
      break;
    case 2:
      Msg::StatusBar(3, false, "Select surface\n[Press 'q' to abort]");
      ib = GUI::instance()->selectEntity(ENT_SURFACE);
      break;
    case 3:
      Msg::StatusBar(3, false, "Select volume\n[Press 'q' to abort]");
      ib = GUI::instance()->selectEntity(ENT_VOLUME);
      break;
    default:
      ib = 'l';
      break;
    }

    if(ib == 'e') {
      if(dim == 1) {
        if(p.size())
          add_trsfline(p, CTX.filename,
                       GUI::instance()->meshContext->choice[0]->text(),
                       GUI::instance()->meshContext->input[2]->value(),
                       GUI::instance()->meshContext->input[1]->value());
      }
      GModel::current()->setSelection(0);
      Draw();
      p.clear();
    }
    if(ib == 'u') {
      if(dim == 1) {
        if(p.size()){
          GEdge *ge = GModel::current()->getEdgeByTag(p.back());
          if(ge) ge->setSelection(0);
          Draw();
          p.pop_back();
        }
      }
    }
    if(ib == 'q') {
      GModel::current()->setSelection(0);
      Draw();
      break;
    }
    if(ib == 'r') {
      Msg::Warning("Entity de-selection not supported yet during "
                   "transfinite definition");
    }
    if(ib == 'l') {
      switch (dim) {
      case 1:
        for(unsigned int i = 0; i < GUI::instance()->selectedEdges.size(); i++){
          GUI::instance()->selectedEdges[i]->setSelection(1);
          p.push_back(GUI::instance()->selectedEdges[i]->tag());
        }
        Draw();
        break;
      case 2:
      case 3:
        if(dim == 2){
          GUI::instance()->selectedFaces[0]->setSelection(1);
          Draw();
          p.push_back(GUI::instance()->selectedFaces[0]->tag());
        }
        else{
          GUI::instance()->selectedRegions[0]->setSelection(1);
          Draw();
          p.push_back(GUI::instance()->selectedRegions[0]->tag());
        }
        while(1) {
          if(p.size() == 1)
            Msg::StatusBar(3, false, "Select (ordered) boundary points\n"
                           "[Press 'e' to end selection or 'q' to abort]");
          else
            Msg::StatusBar(3, false, "Select (ordered) boundary points\n"
                           "[Press 'e' to end selection, 'u' to undo last selection "
                           "or 'q' to abort]");
          ib = GUI::instance()->selectEntity(ENT_POINT);
          if(ib == 'l') {
            GUI::instance()->selectedVertices[0]->setSelection(1);
            Draw();
            p.push_back(GUI::instance()->selectedVertices[0]->tag());
          }
          if(ib == 'u') {
            if(p.size() > 1){
              GVertex *gv = GModel::current()->getVertexByTag(p.back());
              if(gv) gv->setSelection(0);
              Draw();
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
              if(p.size() == 0 + 1 || p.size() == 3 + 1 || p.size() == 4 + 1)
                add_trsfsurf(p, CTX.filename,
                             GUI::instance()->meshContext->choice[1]->text());
              else
                Msg::Error("Wrong number of points for transfinite surface");
              break;
            case 3:
              if(p.size() == 6 + 1 || p.size() == 8 + 1)
                add_trsfvol(p, CTX.filename);
              else
                Msg::Error("Wrong number of points for transfinite volume");
              break;
            }
            GModel::current()->setSelection(0);
            Draw();
            p.clear();
            break;
          }
          if(ib == 'q') {
            GModel::current()->setSelection(0);
            Draw();
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
  GUI::instance()->meshContext->show(1);
  add_transfinite(1);
}

static void mesh_define_transfinite_surface_cb(Fl_Widget *w, void *data)
{
  GUI::instance()->meshContext->show(2);
  add_transfinite(2);
}

static void mesh_define_transfinite_volume_cb(Fl_Widget *w, void *data)
{
  add_transfinite(3);
}

static void view_toggle_cb(Fl_Widget *w, void *data)
{
  int num = (int)(long)data;
  opt_view_visible(num, GMSH_SET,
                   GUI::instance()->menu->toggle[num]->value());
  Draw();
}

static void view_reload(int index)
{
  if(index >= 0 && index < (int)PView::list.size()){
    PView *p = PView::list[index];

    if(StatFile(p->getData()->getFileName().c_str())){
      Msg::Error("File '%s' does not exist", p->getData()->getFileName().c_str());
      return;
    }

    int n = PView::list.size();

    // FIXME: use fileIndex
    MergeFile(p->getData()->getFileName().c_str());

    if((int)PView::list.size() > n){ // we loaded a new view
      // delete old data and replace with new
      delete p->getData();
      p->setData(PView::list.back()->getData());
      PView::list.back()->setData(0);
      // delete new view
      delete PView::list.back();
      // in case the reloaded view has a different number of time steps
      if(p->getOptions()->TimeStep > p->getData()->getNumTimeSteps() - 1)
        p->getOptions()->TimeStep = 0;
      p->setChanged(true);
      GUI::instance()->updateViews();
    }
  }
}

static void view_reload_cb(Fl_Widget *w, void *data)
{
  view_reload((int)(long)data);
  Draw();
}

static void view_reload_all_cb(Fl_Widget *w, void *data)
{
  for(unsigned int i = 0; i < PView::list.size(); i++)
    view_reload(i);
  Draw();
}

static void view_reload_visible_cb(Fl_Widget *w, void *data)
{
  for(unsigned int i = 0; i < PView::list.size(); i++)
    if(opt_view_visible(i, GMSH_GET, 0))
      view_reload(i);
  Draw();
}

static void view_remove_other_cb(Fl_Widget *w, void *data)
{
  if(PView::list.empty()) return;
  for(int i = PView::list.size() - 1; i >= 0; i--)
    if(i != (long)data) delete PView::list[i];
  GUI::instance()->updateViews();
  Draw();
}

static void view_remove_all_cb(Fl_Widget *w, void *data)
{
  if(PView::list.empty()) return;
  while(PView::list.size()) delete PView::list[0];
  GUI::instance()->updateViews();
  Draw();
}

static void view_remove_visible_cb(Fl_Widget *w, void *data)
{
  if(PView::list.empty()) return;
  for(int i = PView::list.size() - 1; i >= 0; i--)
    if(opt_view_visible(i, GMSH_GET, 0)) delete PView::list[i];
  GUI::instance()->updateViews();
  Draw();
}

static void view_remove_invisible_cb(Fl_Widget *w, void *data)
{
  if(PView::list.empty()) return;
  for(int i = PView::list.size() - 1; i >= 0; i--)
    if(!opt_view_visible(i, GMSH_GET, 0)) delete PView::list[i];
  GUI::instance()->updateViews();
  Draw();
}

static void view_remove_empty_cb(Fl_Widget *w, void *data)
{
  if(PView::list.empty()) return;
  for(int i = PView::list.size() - 1; i >= 0; i--)
    if(PView::list[i]->getData()->empty()) delete PView::list[i];
  GUI::instance()->updateViews();
  Draw();
}

static void view_remove_cb(Fl_Widget *w, void *data)
{
  delete PView::list[(int)(long)data];
  GUI::instance()->updateViews();
  Draw();
}

static void view_save_as(int index, const char *title, int format)
{
  PView *view = PView::list[index];
  
 test:
  if(file_chooser(0, 1, title, "*", view->getData()->getFileName().c_str())){
    std::string name = file_chooser_get_name(1);
    if(CTX.confirm_overwrite) {
      if(!StatFile(name.c_str()))
        if(!fl_choice("File '%s' already exists.\n\nDo you want to replace it?",
                      "Cancel", "Replace", NULL, name.c_str()))
          goto test;
    }
    view->write(name.c_str(), format);
  }
}

static void view_save_ascii_cb(Fl_Widget *w, void *data)
{
  view_save_as((int)(long)data, "Save As ASCII View", 0);
}

static void view_save_binary_cb(Fl_Widget *w, void *data)
{
  view_save_as((int)(long)data, "Save As Binary View", 1);
}

static void view_save_parsed_cb(Fl_Widget *w, void *data)
{
  view_save_as((int)(long)data, "Save As Parsed View", 2);
}

static void view_save_stl_cb(Fl_Widget *w, void *data)
{
  view_save_as((int)(long)data, "Save As STL Triangulation", 3);
}

static void view_save_txt_cb(Fl_Widget *w, void *data)
{
  view_save_as((int)(long)data, "Save As Raw Text", 4);
}

static void view_save_msh_cb(Fl_Widget *w, void *data)
{
  view_save_as((int)(long)data, "Save As Gmsh Mesh", 5);
}

static void view_save_med_cb(Fl_Widget *w, void *data)
{
  view_save_as((int)(long)data, "Save As MED file", 6);
}

static void view_alias_cb(Fl_Widget *w, void *data)
{
  new PView(PView::list[(int)(long)data], false);
  GUI::instance()->updateViews();
  Draw();
}

static void view_alias_with_options_cb(Fl_Widget *w, void *data)
{
  new PView(PView::list[(int)(long)data], true);
  GUI::instance()->updateViews();
  Draw();
}

static void view_combine_space_all_cb(Fl_Widget *w, void *data)
{
  PView::combine(false, 1, CTX.post.combine_remove_orig);
  GUI::instance()->updateViews();
  Draw();
}

static void view_combine_space_visible_cb(Fl_Widget *w, void *data)
{
  PView::combine(false, 0, CTX.post.combine_remove_orig);
  GUI::instance()->updateViews();
  Draw();
}

static void view_combine_space_by_name_cb(Fl_Widget *w, void *data)
{
  PView::combine(false, 2, CTX.post.combine_remove_orig);
  GUI::instance()->updateViews();
  Draw();
}

static void view_combine_time_all_cb(Fl_Widget *w, void *data)
{
  PView::combine(true, 1, CTX.post.combine_remove_orig);
  GUI::instance()->updateViews();
  Draw();
}

static void view_combine_time_visible_cb(Fl_Widget *w, void *data)
{
  PView::combine(true, 0, CTX.post.combine_remove_orig);
  GUI::instance()->updateViews();
  Draw();
}

static void view_combine_time_by_name_cb(Fl_Widget *w, void *data)
{
  PView::combine(true, 2, CTX.post.combine_remove_orig);
  GUI::instance()->updateViews();
  Draw();
}

static void view_all_visible_cb(Fl_Widget *w, void *data)
{
  for(unsigned int i = 0; i < PView::list.size(); i++)
    opt_view_visible(i, GMSH_SET | GMSH_GUI, 
                     (long)data < 0 ? !opt_view_visible(i, GMSH_GET, 0) :
                     (long)data > 0 ? 1 : 0);
  Draw();
}

static void view_applybgmesh_cb(Fl_Widget *w, void *data)
{
  int index =  (int)(long)data;
  if(index >= 0 && index < (int)PView::list.size()){
    GModel::current()->getFields()->set_background_mesh(index);
  }
}

// The static menus (we cannot use the 'g', 'm' 's' and 'p' mnemonics
// since they are already defined as global shortcuts)
static Fl_Menu_Item bar_table[] = {
  {"&File", 0, 0, 0, FL_SUBMENU},
    {"&New...",     FL_CTRL+'n', (Fl_Callback *)file_new_cb, 0},
    {"&Open...",    FL_CTRL+'o', (Fl_Callback *)file_open_cb, 0},
    {"M&erge...",   FL_CTRL+FL_SHIFT+'o', (Fl_Callback *)file_merge_cb, 0, FL_MENU_DIVIDER},
    {"&Rename...",  FL_CTRL+'r', (Fl_Callback *)file_rename_cb, 0},
    {"Save &As...", FL_CTRL+'s', (Fl_Callback *)file_save_as_cb, 0},
    {"Sa&ve Mesh",  FL_CTRL+FL_SHIFT+'s', (Fl_Callback *)mesh_save_cb, 0, FL_MENU_DIVIDER},
    {"&Quit",       FL_CTRL+'q', (Fl_Callback *)file_quit_cb, 0},
    {0},
  {"&Tools", 0, 0, 0, FL_SUBMENU},
    {"&Options...",      FL_CTRL+FL_SHIFT+'n', (Fl_Callback *)options_cb, 0},
    {"Pl&ugins...",      FL_CTRL+FL_SHIFT+'u', (Fl_Callback *)plugin_cb, (void*)(-1)},
    {"&Visibility",      FL_CTRL+FL_SHIFT+'v', (Fl_Callback *)visibility_cb, 0},
    {"&Clipping",        FL_CTRL+FL_SHIFT+'c', (Fl_Callback *)clip_cb, 0},
    {"&Manipulator",     FL_CTRL+FL_SHIFT+'m', (Fl_Callback *)manip_cb, 0, FL_MENU_DIVIDER},
    {"S&tatistics",      FL_CTRL+'i', (Fl_Callback *)statistics_cb, 0},
    {"M&essage Console", FL_CTRL+'l', (Fl_Callback *)message_cb, 0},
    {0},
  {"&Help", 0, 0, 0, FL_SUBMENU},
    {"On&line Documentation", 0, (Fl_Callback *)help_online_cb, 0, FL_MENU_DIVIDER},
    {"M&ouse Actions",        0, (Fl_Callback *)help_mouse_cb, 0},
    {"&Keyboard Shortcuts",   0, (Fl_Callback *)help_short_cb, 0},
    {"C&ommand Line Options", 0, (Fl_Callback *)help_command_line_cb, 0},
    {"&Current Options",      0, (Fl_Callback *)status_xyz1p_cb, (void*)"?", FL_MENU_DIVIDER},
    {"&About Gmsh...",        0, (Fl_Callback *)help_about_cb, 0},
    {0},
  {0}
};

#if defined(__APPLE__)

#if (FL_MAJOR_VERSION == 1) && (FL_MINOR_VERSION == 1) && (FL_PATCH_VERSION <= 6)
#undef FL_META
#define FL_META FL_CTRL
#endif

// Alternative items for the MacOS system menu bar (removed '&'
// shortcuts: they would cause spurious menu items to appear on the
// menu window; removed File->Quit)
static Fl_Menu_Item sysbar_table[] = {
  {"File", 0, 0, 0, FL_SUBMENU},
    {"New...",     FL_META+'n', (Fl_Callback *)file_new_cb, 0},
    {"Open...",    FL_META+'o', (Fl_Callback *)file_open_cb, 0},
    {"Merge...",   FL_META+FL_SHIFT+'o', (Fl_Callback *)file_merge_cb, 0, FL_MENU_DIVIDER},
    {"Rename...",  FL_META+'r', (Fl_Callback *)file_rename_cb, 0},
    {"Save As...", FL_META+'s', (Fl_Callback *)file_save_as_cb, 0},
    {"Save Mesh",  FL_META+FL_SHIFT+'s', (Fl_Callback *)mesh_save_cb, 0},
    {0},
  {"Tools", 0, 0, 0, FL_SUBMENU},
    {"Options...",      FL_META+FL_SHIFT+'n', (Fl_Callback *)options_cb, 0},
    {"Plugins...",      FL_META+FL_SHIFT+'u', (Fl_Callback *)plugin_cb, (void*)(-1)},
    {"Visibility",      FL_META+FL_SHIFT+'v', (Fl_Callback *)visibility_cb, 0},
    {"Clipping",        FL_META+FL_SHIFT+'c', (Fl_Callback *)clip_cb, 0},
    {"Manipulator",     FL_META+FL_SHIFT+'m', (Fl_Callback *)manip_cb, 0, FL_MENU_DIVIDER},
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
    {"Current Options",      0, (Fl_Callback *)status_xyz1p_cb, (void*)"?", FL_MENU_DIVIDER},
    {"About Gmsh...",        0, (Fl_Callback *)help_about_cb, 0},
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
  {"0Geometry", NULL} ,
  {"Elementary entities", (Fl_Callback *)geometry_elementary_cb} ,
  {"Physical groups",     (Fl_Callback *)geometry_physical_cb} ,
  {"Edit",                (Fl_Callback *)geometry_edit_cb} , 
  {"Reload",              (Fl_Callback *)geometry_reload_cb} , 
  {0}
};  
  contextItem menu_geometry_elementary[] = {
    {"0Geometry>Elementary", NULL} ,
    {"Add",       (Fl_Callback *)geometry_elementary_add_cb} ,
    {"Delete",    (Fl_Callback *)geometry_elementary_delete_cb, (void*)0} ,
    {"Translate", (Fl_Callback *)geometry_elementary_translate_cb, (void*)0} ,
    {"Rotate",    (Fl_Callback *)geometry_elementary_rotate_cb, (void*)0} ,
    {"Split",     (Fl_Callback *)geometry_elementary_split_cb, (void*)0} ,
    {"Scale",     (Fl_Callback *)geometry_elementary_scale_cb, (void*)0} ,
    {"Symmetry",  (Fl_Callback *)geometry_elementary_symmetry_cb, (void*)0} ,
    {"Extrude",   (Fl_Callback *)geometry_elementary_extrude_cb, (void*)0} ,
    {"Coherence", (Fl_Callback *)geometry_elementary_coherence_cb} ,
    {0} 
  };  
    contextItem menu_geometry_elementary_add[] = {
      {"0Geometry>Elementary>Add", NULL} ,
      {"New",       (Fl_Callback *)geometry_elementary_add_new_cb, (void*)0} ,
      {"Translate", (Fl_Callback *)geometry_elementary_add_translate_cb, (void*)0} ,
      {"Rotate",    (Fl_Callback *)geometry_elementary_add_rotate_cb, (void*)0} ,
      {"Scale",     (Fl_Callback *)geometry_elementary_add_scale_cb, (void*)0} ,
      {"Symmetry",  (Fl_Callback *)geometry_elementary_add_symmetry_cb, (void*)0} ,
      {0} 
    };  
      contextItem menu_geometry_elementary_add_new[] = {
        {"0Geometry>Elementary>Add>New", NULL} ,
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
        {0} 
      };  
      contextItem menu_geometry_elementary_add_translate[] = {
        {"0Geometry>Elementary>Add>Translate", NULL} ,
        {"Point",   (Fl_Callback *)geometry_elementary_add_translate_cb, (void*)"Point"} ,  
        {"Line",    (Fl_Callback *)geometry_elementary_add_translate_cb, (void*)"Line"} ,	  
        {"Surface", (Fl_Callback *)geometry_elementary_add_translate_cb, (void*)"Surface"} ,
        {"Volume",  (Fl_Callback *)geometry_elementary_add_translate_cb, (void*)"Volume"} , 
        {0} 
      };  
      contextItem menu_geometry_elementary_add_rotate[] = {
        {"0Geometry>Elementary>Add>Rotate", NULL} ,
        {"Point",   (Fl_Callback *)geometry_elementary_add_rotate_cb, (void*)"Point"} ,  
        {"Line",    (Fl_Callback *)geometry_elementary_add_rotate_cb, (void*)"Line"} ,	  
        {"Surface", (Fl_Callback *)geometry_elementary_add_rotate_cb, (void*)"Surface"} ,
        {"Volume",  (Fl_Callback *)geometry_elementary_add_rotate_cb, (void*)"Volume"} , 
        {0} 
      };  
      contextItem menu_geometry_elementary_add_scale[] = {
        {"0Geometry>Elementary>Add>Scale", NULL} ,
        {"Point",   (Fl_Callback *)geometry_elementary_add_scale_cb, (void*)"Point"} ,  
        {"Line",    (Fl_Callback *)geometry_elementary_add_scale_cb, (void*)"Line"} ,	  
        {"Surface", (Fl_Callback *)geometry_elementary_add_scale_cb, (void*)"Surface"} ,
        {"Volume",  (Fl_Callback *)geometry_elementary_add_scale_cb, (void*)"Volume"} , 
        {0} 
      };  
      contextItem menu_geometry_elementary_add_symmetry[] = {
        {"0Geometry>Elementary>Add>Symmetry", NULL} ,
        {"Point",   (Fl_Callback *)geometry_elementary_add_symmetry_cb, (void*)"Point"} ,  
        {"Line",    (Fl_Callback *)geometry_elementary_add_symmetry_cb, (void*)"Line"} ,	  
        {"Surface", (Fl_Callback *)geometry_elementary_add_symmetry_cb, (void*)"Surface"} ,
        {"Volume",  (Fl_Callback *)geometry_elementary_add_symmetry_cb, (void*)"Volume"} , 
        {0} 
      };  
    contextItem menu_geometry_elementary_delete[] = {
      {"0Geometry>Elementary>Delete", NULL} ,
      {"Point",   (Fl_Callback *)geometry_elementary_delete_cb, (void*)"Point"} ,
      {"Line",    (Fl_Callback *)geometry_elementary_delete_cb, (void*)"Line"} ,
      {"Surface", (Fl_Callback *)geometry_elementary_delete_cb, (void*)"Surface"} ,
      {"Volume",  (Fl_Callback *)geometry_elementary_delete_cb, (void*)"Volume"} ,
      {0} 
    };  
    contextItem menu_geometry_elementary_split[] = {
      {"0Geometry>Elementary>Split",NULL},
        {"Line",(Fl_Callback *)geometry_elementary_split_cb,(void*)"Line"},
        {0}
    };
    contextItem menu_geometry_elementary_translate[] = {
      {"0Geometry>Elementary>Translate", NULL} ,
      {"Point",   (Fl_Callback *)geometry_elementary_translate_cb, (void*)"Point"} ,  
      {"Line",    (Fl_Callback *)geometry_elementary_translate_cb, (void*)"Line"} ,	  
      {"Surface", (Fl_Callback *)geometry_elementary_translate_cb, (void*)"Surface"} ,
      {"Volume",  (Fl_Callback *)geometry_elementary_translate_cb, (void*)"Volume"} , 
      {0} 
    };  
    contextItem menu_geometry_elementary_rotate[] = {
      {"0Geometry>Elementary>Rotate", NULL} ,
      {"Point",   (Fl_Callback *)geometry_elementary_rotate_cb, (void*)"Point"} ,  
      {"Line",    (Fl_Callback *)geometry_elementary_rotate_cb, (void*)"Line"} ,	  
      {"Surface", (Fl_Callback *)geometry_elementary_rotate_cb, (void*)"Surface"} ,
      {"Volume",  (Fl_Callback *)geometry_elementary_rotate_cb, (void*)"Volume"} , 
      {0} 
    };  
    contextItem menu_geometry_elementary_scale[] = {
      {"0Geometry>Elementary>Scale", NULL} ,
      {"Point",   (Fl_Callback *)geometry_elementary_scale_cb, (void*)"Point"} ,  
      {"Line",    (Fl_Callback *)geometry_elementary_scale_cb, (void*)"Line"} ,	  
      {"Surface", (Fl_Callback *)geometry_elementary_scale_cb, (void*)"Surface"} ,
      {"Volume",  (Fl_Callback *)geometry_elementary_scale_cb, (void*)"Volume"} , 
      {0} 
    };  
    contextItem menu_geometry_elementary_symmetry[] = {
      {"0Geometry>Elementary>Symmetry", NULL} ,
      {"Point",   (Fl_Callback *)geometry_elementary_symmetry_cb, (void*)"Point"} ,  
      {"Line",    (Fl_Callback *)geometry_elementary_symmetry_cb, (void*)"Line"} ,	  
      {"Surface", (Fl_Callback *)geometry_elementary_symmetry_cb, (void*)"Surface"} ,
      {"Volume",  (Fl_Callback *)geometry_elementary_symmetry_cb, (void*)"Volume"} , 
      {0} 
    };  
    contextItem menu_geometry_elementary_extrude[] = {
      {"0Geometry>Elementary>Extrude", NULL} ,
      {"Translate", (Fl_Callback *)geometry_elementary_extrude_translate_cb, (void*)0} ,
      {"Rotate",    (Fl_Callback *)geometry_elementary_extrude_rotate_cb, (void*)0} ,
      {0} 
    };  
      contextItem menu_geometry_elementary_extrude_translate[] = {
        {"0Geometry>Elementary>Extrude>Translate", NULL} ,
        {"Point",   (Fl_Callback *)geometry_elementary_extrude_translate_cb, (void*)"Point"} ,
        {"Line",    (Fl_Callback *)geometry_elementary_extrude_translate_cb, (void*)"Line"} ,
        {"Surface", (Fl_Callback *)geometry_elementary_extrude_translate_cb, (void*)"Surface"} ,
        {0} 
      };  
      contextItem menu_geometry_elementary_extrude_rotate[] = {
        {"0Geometry>Elementary>Extrude>Rotate", NULL} ,
        {"Point",   (Fl_Callback *)geometry_elementary_extrude_rotate_cb, (void*)"Point"} ,
        {"Line",    (Fl_Callback *)geometry_elementary_extrude_rotate_cb, (void*)"Line"} ,
        {"Surface", (Fl_Callback *)geometry_elementary_extrude_rotate_cb, (void*)"Surface"} ,
        {0} 
      };  
  contextItem menu_geometry_physical[] = {
    {"0Geometry>Physical", NULL} ,
    {"Add",    (Fl_Callback *)geometry_physical_add_cb, (void*)0} ,
    {0} 
  };  
    contextItem menu_geometry_physical_add[] = {
      {"0Geometry>Physical>Add", NULL} ,
      {"Point",   (Fl_Callback *)geometry_physical_add_cb, (void*)"Point" } ,
      {"Line",    (Fl_Callback *)geometry_physical_add_cb, (void*)"Line" } ,
      {"Surface", (Fl_Callback *)geometry_physical_add_cb, (void*)"Surface" } ,
      {"Volume",  (Fl_Callback *)geometry_physical_add_cb, (void*)"Volume" } ,
      {0} 
    };  

contextItem menu_mesh[] = {
  {"1Mesh", NULL} ,
  {"Define",       (Fl_Callback *)mesh_define_cb} ,
  {"Inspect",      (Fl_Callback *)mesh_inspect_cb} , 
  {"Delete",       (Fl_Callback *)mesh_delete_cb} , 
  {"1D",           (Fl_Callback *)mesh_1d_cb} ,
  {"2D",           (Fl_Callback *)mesh_2d_cb} , 
  {"3D",           (Fl_Callback *)mesh_3d_cb} , 
  {"First order",  (Fl_Callback *)mesh_degree_cb, (void*)1 } , 
  {"Second order", (Fl_Callback *)mesh_degree_cb, (void*)2 } , 
  {"Refine",       (Fl_Callback *)mesh_refine_cb} ,
  {"Optimize",     (Fl_Callback *)mesh_optimize_cb} , 
#if defined(HAVE_NETGEN)
  {"Optimize (Netgen)", (Fl_Callback *)mesh_optimize_netgen_cb} , 
#endif
#if defined(HAVE_METIS) || defined(HAVE_CHACO)
  {"Partition", (Fl_Callback *)mesh_partition_cb} ,
#endif
#if defined(HAVE_FOURIER_MODEL)
  {"Reparameterize",   (Fl_Callback *)mesh_parameterize_cb} , 
#endif
  {"Reclassify",   (Fl_Callback *)mesh_classify_cb} , 
  {"Save",         (Fl_Callback *)mesh_save_cb} ,
  {0} 
};  
  contextItem menu_mesh_define[] = {
    {"1Mesh>Define", NULL} ,
    {"Fields",      (Fl_Callback *)field_cb},
    {"Characteristic length", (Fl_Callback *)mesh_define_length_cb  } ,
    {"Recombine",   (Fl_Callback *)mesh_define_recombine_cb  } ,
    {"Transfinite", (Fl_Callback *)mesh_define_transfinite_cb  } , 
    {0} 
  };  
    contextItem menu_mesh_define_transfinite[] = {
      {"1Mesh>Define>Transfinite", NULL} ,
      {"Line",    (Fl_Callback *)mesh_define_transfinite_line_cb} ,
      {"Surface", (Fl_Callback *)mesh_define_transfinite_surface_cb} ,
      {"Volume",  (Fl_Callback *)mesh_define_transfinite_volume_cb} , 
      {0} 
    };  
  contextItem menu_mesh_delete[] = {
    {"1Mesh>Edit>Delete", NULL} ,
    {"Elements", (Fl_Callback *)mesh_delete_parts_cb, (void*)"elements"} ,
    {"Lines",    (Fl_Callback *)mesh_delete_parts_cb, (void*)"lines"} ,
    {"Surfaces", (Fl_Callback *)mesh_delete_parts_cb, (void*)"surfaces"} ,
    {"Volumes",  (Fl_Callback *)mesh_delete_parts_cb, (void*)"volumes"} ,
    {0} 
  };  

contextItem menu_solver[] = {
  {"2Solver", NULL} ,
  {"Solver 0", (Fl_Callback *)solver_cb , (void*)0} ,
  {"Solver 1", (Fl_Callback *)solver_cb , (void*)1} ,
  {"Solver 2", (Fl_Callback *)solver_cb , (void*)2} ,
  {"Solver 3", (Fl_Callback *)solver_cb , (void*)3} ,
  {"Solver 4", (Fl_Callback *)solver_cb , (void*)4} ,
  {0} 
};

contextItem menu_post[] = {
  {"3Post-processing", NULL} ,
  {0} 
};

menuWindow::menuWindow(int fontsize) : _fontsize(fontsize)
{
  int width = 14 * fontsize;

  // this is the initial height: no dynamic button is shown
#if defined(__APPLE__)
  if(CTX.system_menu_bar){
    _MH = BH + 6; // the menu bar is not in the application
  }
  else{
#endif
    _MH = BH + BH + 6;
#if defined(__APPLE__)
  }
#endif

  win = new mainWindow(width, _MH + NB_BUTT_SCROLL * BH, CTX.non_modal_windows, "Gmsh");
  win->box(GMSH_WINDOW_BOX);
  win->callback(file_quit_cb);

  int y;
#if defined(__APPLE__)
  if(CTX.system_menu_bar){
    // the system menubar is kind of a hack in fltk < 1.1.7: it still
    // creates a real (invisible) menubar. To avoid spurious mouse
    // click events we make it a 1x1 pixel rectangle, 1 pixel off the
    // edge (so it falls behind the navigation buttons)
    sysbar = new Fl_Sys_Menu_Bar(1, 1, 1, 1);
    sysbar->menu(sysbar_table);
    sysbar->global();
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
  win->position(CTX.position[0], CTX.position[1]);
  
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
      menu_history[i] = NULL;
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
  else {
    menu = menu_asked;
    if(!nb_back || menu_history[nb_back - 1] != menu) {
      menu_history[nb_back++] = menu;
    }
    nb_forward = 0;
  }

  if(menu[0].label[0] == '0'){
    module->value(0);
  }
  else if(menu[0].label[0] == '1'){
    module->value(1);
  }
  else if(menu[0].label[0] == '2'){
    module->value(2);
    menu[1].label = opt_solver_name0(0, GMSH_GET, 0);
    menu[2].label = opt_solver_name1(0, GMSH_GET, 0);
    menu[3].label = opt_solver_name2(0, GMSH_GET, 0);
    menu[4].label = opt_solver_name3(0, GMSH_GET, 0);
    menu[5].label = opt_solver_name4(0, GMSH_GET, 0);
    for(int i = 0; i < MAX_NUM_SOLVERS; i++) {
      if(!strlen(menu[i + 1].label))
        menu[i + 1].label = NULL;
    }
  }
  else if(menu[0].label[0] == '3'){
    module->value(3);
  }
  else {
    Msg::Warning("Something is wrong in your dynamic context definition");
    return;
  }

  Msg::StatusBar(1, false, menu[0].label + 1);

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

  int width = win->w();
  int popw = 4 * _fontsize + 3;

  // construct the dynamic menu
  int nb = 0;
  if(module->value() == 3){ // post-processing context
    for(nb = 0; nb < (int)PView::list.size(); nb++) {
      PViewData *data = PView::list[nb]->getData();
      PViewOptions *opt = PView::list[nb]->getOptions();
      
      Fl_Light_Button *b1 = new Fl_Light_Button(0, _MH + nb * BH, width - popw, BH);
      b1->callback(view_toggle_cb, (void *)nb);
      b1->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
      b1->value(opt->Visible);
      b1->copy_label(data->getName().c_str());
      b1->tooltip(data->getFileName().c_str());
      
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
                  (Fl_Callback *) view_remove_visible_cb, (void *)nb, 0);
        p[j]->add("Remove/Invisible Views", 0, 
                  (Fl_Callback *) view_remove_invisible_cb, (void *)nb, 0);
        p[j]->add("Remove/Empty Views", 0, 
                  (Fl_Callback *) view_remove_empty_cb, (void *)nb, 0);
        p[j]->add("Remove/All Views", 0, 
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
                  (Fl_Callback *) view_all_visible_cb, (void *)1, 0);
        p[j]->add("Set Visibility/All Off", 0, 
                  (Fl_Callback *) view_all_visible_cb, (void *)0, 0);
        p[j]->add("Set Visibility/Invert", 0, 
                  (Fl_Callback *) view_all_visible_cb, (void *)-1, 0);
        p[j]->add("Save As/Parsed View...", 0, 
                  (Fl_Callback *) view_save_parsed_cb, (void *)nb, 0);
        p[j]->add("Save As/ASCII View...", 0, 
                  (Fl_Callback *) view_save_ascii_cb, (void *)nb, 0);
        p[j]->add("Save As/Binary View...", 0, 
                  (Fl_Callback *) view_save_binary_cb, (void *)nb, 0);
        p[j]->add("Save As/STL Triangulation...", 0, 
                  (Fl_Callback *) view_save_stl_cb, (void *)nb, 0);
        p[j]->add("Save As/Raw Text...", 0, 
                  (Fl_Callback *) view_save_txt_cb, (void *)nb, 0);
        p[j]->add("Save As/Gmsh Mesh...", 0, 
                  (Fl_Callback *) view_save_msh_cb, (void *)nb, 0);
#if defined(HAVE_MED)
        p[j]->add("Save As/MED file...", 0, 
                  (Fl_Callback *) view_save_med_cb, (void *)nb, 0);
#endif
        p[j]->add("Apply As Background Mesh", 0, 
                  (Fl_Callback *) view_applybgmesh_cb, (void *)nb, FL_MENU_DIVIDER);
        p[j]->add("Options...", 'o', 
                  (Fl_Callback *) view_options_cb, (void *)nb, 0);
        p[j]->add("Plugins...", 'p', 
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
    while(menu[nb + 1].label) {
      Fl_Button *b = new Fl_Button(0, _MH + nb * BH, width, BH);
      b->copy_label(menu[nb + 1].label);
      b->callback(menu[nb + 1].callback, menu[nb + 1].arg);
      push.push_back(b);
      scroll->add(b);
      nb++;
    }
  }

  scroll->redraw();

  if(nb <= NB_BUTT_SCROLL)
    win->size(width, _MH + nb * BH);
  else
    win->size(width, _MH + NB_BUTT_SCROLL * BH);
}
