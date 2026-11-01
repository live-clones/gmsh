// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include <cstdint>
#include <string.h>
#include <algorithm>
#include <FL/Fl.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Color_Chooser.H>
#include <FL/fl_ask.H>
#include <FL/fl_draw.H>
#include "GmshDefines.h"
#include "GmshMessage.h"
#include "FlGui.h"
#include "accentTabs.h"
#include "inputValue.h"
#include "optionWindow.h"
#include "hintInput.h"
#include "gamepadWindow.h"
#include "graphicWindow.h"
#include "openglWindow.h"
#include "paletteWindow.h"
#include "manipWindow.h"
#include "extraDialogs.h"
#include "drawContext.h"
#include "Options.h"
#include "GModel.h"
#include "MElement.h"
#include "PView.h"
#include "PViewData.h"
#include "PViewOptions.h"
#include "OS.h"
#include "Context.h"
#include "StringUtils.h"
#include "gmshLocalNetworkClient.h"
extern StringXColor GeneralOptions_Color[];
extern StringXColor GeometryOptions_Color[];
extern StringXColor MeshOptions_Color[];
extern StringXColor ViewOptions_Color[];

// the colour options of a table that get a button: a new one in the table
// needs no code here
static int colorOptions(StringXColor *table)
{
  int n = 0;
  for(int i = 0; table[i].str; i++)
    if(!(table[i].level & GMSH_DEPRECATED)) n++;
  return n;
}

static Fl_Menu_Item menu_point_display[] = {{"Color dot", 0, nullptr, nullptr},
                                            {"3D sphere", 0, nullptr, nullptr},
                                            {nullptr}};

static Fl_Menu_Item menu_point_display_post[] = {
  {"Color dot", 0, nullptr, nullptr},
  {"3D sphere", 0, nullptr, nullptr},
  {"Scaled dot", 0, nullptr, nullptr},
  {"Scaled sphere", 0, nullptr, nullptr},
  {nullptr}};

static Fl_Menu_Item menu_line_display[] = {
  {"Color segment", 0, nullptr, nullptr},
  {"3D cylinder", 0, nullptr, nullptr},
  {nullptr}};

static Fl_Menu_Item menu_line_display_post[] = {
  {"Color segment", 0, nullptr, nullptr},
  {"3D cylinder", 0, nullptr, nullptr},
  {"Tapered cylinder", 0, nullptr, nullptr},
  {nullptr}};

static Fl_Menu_Item menu_surface_display[] = {
  {"Cross", 0, nullptr, nullptr},
  {"Wireframe", 0, nullptr, nullptr},
  {"Solid", 0, nullptr, nullptr},
  {nullptr}};

static Fl_Menu_Item menu_volume_display[] = {
  {"Sphere", 0, nullptr, nullptr},
  {"Diamond", 0, nullptr, nullptr},
  {nullptr}};

static Fl_Menu_Item menu_axes_mode[] = {{"None", 0, nullptr, nullptr},
                                        {"Simple axes", 0, nullptr, nullptr},
                                        {"Box", 0, nullptr, nullptr},
                                        {"Full grid", 0, nullptr, nullptr},
                                        {"Open grid", 0, nullptr, nullptr},
                                        {"Ruler", 0, nullptr, nullptr},
                                        {nullptr}};

static Fl_Menu_Item menu_position[] = {
  {"Manual", 0, nullptr, nullptr},
  {"Automatic", 0, nullptr, nullptr},
  {"Top left", 0, nullptr, nullptr},
  {"Top right", 0, nullptr, nullptr},
  {"Bottom left", 0, nullptr, nullptr},
  {"Bottom right", 0, nullptr, nullptr},
  {"Top", 0, nullptr, nullptr},
  {"Bottom", 0, nullptr, nullptr},
  {"Left", 0, nullptr, nullptr},
  {"Right", 0, nullptr, nullptr},
  {"Full", 0, nullptr, nullptr},
  {"Top third", 0, nullptr, nullptr},
  {"In model coordinates", 0, nullptr, nullptr},
  {nullptr}};

Fl_Menu_Item menu_font_names[] = {
  {"Times-Roman", 0, nullptr, (void *)FL_TIMES},
  {"Times-Bold", 0, nullptr, (void *)FL_TIMES_BOLD},
  {"Times-Italic", 0, nullptr, (void *)FL_TIMES_ITALIC},
  {"Times-BoldItalic", 0, nullptr, (void *)FL_TIMES_BOLD_ITALIC},
  {"Helvetica", 0, nullptr, (void *)FL_HELVETICA},
  {"Helvetica-Bold", 0, nullptr, (void *)FL_HELVETICA_BOLD},
  {"Helvetica-Oblique", 0, nullptr, (void *)FL_HELVETICA_ITALIC},
  {"Helvetica-BoldOblique", 0, nullptr, (void *)FL_HELVETICA_BOLD_ITALIC},
  {"Courier", 0, nullptr, (void *)FL_COURIER},
  {"Courier-Bold", 0, nullptr, (void *)FL_COURIER_BOLD},
  {"Courier-Oblique", 0, nullptr, (void *)FL_COURIER_ITALIC},
  {"Courier-BoldOblique", 0, nullptr, (void *)FL_COURIER_BOLD_ITALIC},
  {"Symbol", 0, nullptr, (void *)FL_SYMBOL},
  {"Screen", 0, nullptr, (void *)FL_SCREEN},
  {nullptr}};

Fl_Menu_Item menu_shading_mode[] = {
  {"Classic", 0, nullptr},
  {"Studio (X floor)", 0, nullptr},
  {"Studio (Y floor)", 0, nullptr},
  {"Studio (Z floor)", 0, nullptr},
  {nullptr}};

static void color_cb(Fl_Widget *w, void *data)
{
  unsigned int (*fct)(int, int, unsigned int);
  fct = (unsigned int (*)(int, int, unsigned int))data;
  uchar r = CTX::instance()->unpackRed(fct(0, GMSH_GET, 0));
  uchar g = CTX::instance()->unpackGreen(fct(0, GMSH_GET, 0));
  uchar b = CTX::instance()->unpackBlue(fct(0, GMSH_GET, 0));
  if(fl_color_chooser("Color Chooser", r, g, b))
    fct(0, GMSH_SET | GMSH_GUI, CTX::instance()->packColor(r, g, b, 255));
  drawContext::global()->draw();
}

static void view_color_cb(Fl_Widget *w, void *data)
{
  unsigned int (*fct)(int, int, unsigned int);
  fct = (unsigned int (*)(int, int, unsigned int))data;
  uchar r = CTX::instance()->unpackRed(
    fct(FlGui::instance()->options->view.index, GMSH_GET, 0));
  uchar g = CTX::instance()->unpackGreen(
    fct(FlGui::instance()->options->view.index, GMSH_GET, 0));
  uchar b = CTX::instance()->unpackBlue(
    fct(FlGui::instance()->options->view.index, GMSH_GET, 0));
  if(fl_color_chooser("Color Chooser", r, g, b))
    fct(FlGui::instance()->options->view.index, GMSH_SET | GMSH_GUI,
        CTX::instance()->packColor(r, g, b, 255));
  drawContext::global()->draw();
}

void general_gmpdcf_cb(Fl_Widget *w, void *data)
{
  // built once there is a gamepad, which may be connected later
  optionWindow *o = FlGui::instance()->options;
  if(!o->gmpdoption || !o->gmpdoption->win) {
    delete o->gmpdoption;
    o->gmpdoption = new gamepadWindow;
  }
  o->gmpdoption->show();
}

void options_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->options->win->show();
}

static void options_browser_cb(Fl_Widget *w, void *data)
{
  // the view clicked is shown; the others selected change with it
  int line = FlGui::instance()->options->viewList->browser->value();
  if(line > 0) FlGui::instance()->options->showGroup(line + 5, true, true);
}

static void options_category_cb(Fl_Widget *w, void *data)
{ FlGui::instance()->options->categoryChosen(); }

static void options_section_cb(Fl_Widget *w, void *data)
{
  int i = (intptr_t)data;
  FlGui::instance()->options->toggleSection(i / 100, i % 100);
}

static void options_search_cb(Fl_Widget *w, void *data)
{ FlGui::instance()->options->layout(false); }

static void options_resized_cb(void *data)
{ FlGui::instance()->options->layout(true); }

static void options_select_views_cb(Fl_Widget *w, void *data)
{ FlGui::instance()->options->selectViews((const char *)data); }

static void options_show_file_cb(Fl_Widget *w, void *data)
{
  std::string what((const char *)data);
  std::string file = CTX::instance()->homeDir;
  if(what == "session")
    file += CTX::instance()->sessionFileName;
  else
    file += CTX::instance()->optionsFileName;
  fl_message("File path: %s", file.c_str());
}

void options_restore_defaults_cb(Fl_Widget *w, void *data)
{
  if(fl_choice(
       "Do you really want to reset all options to their default values?",
       "Cancel", "Restore", nullptr)) {
    UnlinkFile(CTX::instance()->homeDir + CTX::instance()->sessionFileName);
    UnlinkFile(CTX::instance()->homeDir + CTX::instance()->optionsFileName);
    ReInitOptions(0);
    InitOptionsGUI(0);
    FlGui::instance()->rebuildTree();
    drawContext::global()->draw();
  }
}

void general_options_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->options->showGroup(1);
}

static void general_options_color_scheme_cb(Fl_Widget *w, void *data)
{
  opt_general_color_scheme(
    0, GMSH_SET, FlGui::instance()->options->general.choice[3]->value());
  drawContext::global()->draw();
}

void general_options_rotation_center_select_cb(Fl_Widget *w, void *data)
{
  Msg::StatusGl("Select point on geometry, mesh or post-processing view\n"
                "[Press 'q' to abort]");

  // the point clicked, from the depth of the pick: no need to pick mesh
  // elements for it, which rebuilt the arrays of the mesh twice (a freeze of
  // seconds on a large mesh) to give the barycentre of an element
  char ib = FlGui::instance()->selectEntity(ENT_ALL);
  if(ib == 'l') {
    SPoint3 pc(0., 0., 0.);
    drawContext *ctx =
      FlGui::instance()->getCurrentOpenglWindow()->getDrawContext();
    double xyz[3];
    if(FlGui::instance()->selectedVertices.size())
      pc.setPosition(FlGui::instance()->selectedVertices[0]->x(),
                     FlGui::instance()->selectedVertices[0]->y(),
                     FlGui::instance()->selectedVertices[0]->z());
    else if(ctx->pickPoint(xyz)) {
      pc.setPosition(xyz[0], xyz[1], xyz[2]);
      // on the curve or surface itself, not on the polyline or the
      // triangulation it is drawn as
      double t, uv[2] = {0., 0.};
      if(FlGui::instance()->selectedEdges.size()) {
        GPoint gp = FlGui::instance()->selectedEdges[0]->closestPoint(pc, t);
        if(gp.succeeded()) pc.setPosition(gp.x(), gp.y(), gp.z());
      }
      else if(FlGui::instance()->selectedFaces.size()) {
        GPoint gp = FlGui::instance()->selectedFaces[0]->closestPoint(pc, uv);
        if(gp.succeeded()) pc.setPosition(gp.x(), gp.y(), gp.z());
      }
    }
    else if(FlGui::instance()->selectedElements.size())
      pc = FlGui::instance()->selectedElements[0]->barycenter();
    else if(FlGui::instance()->selectedEdges.size())
      pc = FlGui::instance()->selectedEdges[0]->bounds().center();
    else if(FlGui::instance()->selectedFaces.size())
      pc = FlGui::instance()->selectedFaces[0]->bounds().center();
    else if(FlGui::instance()->selectedRegions.size())
      pc = FlGui::instance()->selectedRegions[0]->bounds().center();
    else if(FlGui::instance()->selectedViews.size() &&
            FlGui::instance()->selectedViews[0]->getData())
      pc = FlGui::instance()
             ->selectedViews[0]
             ->getData()
             ->getBoundingBox()
             .center();
    opt_general_rotation_center0(0, GMSH_SET | GMSH_GUI, pc.x());
    opt_general_rotation_center1(0, GMSH_SET | GMSH_GUI, pc.y());
    opt_general_rotation_center2(0, GMSH_SET | GMSH_GUI, pc.z());
    ctx->recenterForRotationCenterChange(pc);
    FlGui::instance()->manip->update();
  }
  GModel::current()->setSelection(0);
  drawContext::global()->draw();
  Msg::StatusGl("");
}

void general_options_axes_fit_cb(Fl_Widget *w, void *data)
{
  SBoundingBox3d bbox = GModel::current()->bounds(true);
  for(std::size_t i = 0; i < PView::list.size(); i++) {
    if(PView::list[i]->getOptions()->visible &&
       !PView::list[i]->getData()->getBoundingBox().empty())
      bbox += PView::list[i]->getData()->getBoundingBox();
  }
  if(bbox.empty())
    bbox = SBoundingBox3d(CTX::instance()->min[0], CTX::instance()->min[1],
                          CTX::instance()->min[2], CTX::instance()->max[0],
                          CTX::instance()->max[1], CTX::instance()->max[2]);
  opt_general_axes_xmin(0, GMSH_SET | GMSH_GUI, bbox.min().x());
  opt_general_axes_ymin(0, GMSH_SET | GMSH_GUI, bbox.min().y());
  opt_general_axes_zmin(0, GMSH_SET | GMSH_GUI, bbox.min().z());
  opt_general_axes_xmax(0, GMSH_SET | GMSH_GUI, bbox.max().x());
  opt_general_axes_ymax(0, GMSH_SET | GMSH_GUI, bbox.max().y());
  opt_general_axes_zmax(0, GMSH_SET | GMSH_GUI, bbox.max().z());
  drawContext::global()->draw();
}

void general_options_ok_cb(Fl_Widget *w, void *data)
{
  optionWindow *o = FlGui::instance()->options;
  o->activate((const char *)data);

  static double lc = 0.;
  if(lc != CTX::instance()->lc) {
    lc = CTX::instance()->lc;
    for(int i = 2; i < 5; i++) {
      o->general.value[i]->minimum(-5 * CTX::instance()->lc);
      o->general.value[i]->maximum(5 * CTX::instance()->lc);
    }
  }
  if(data) {
    const char *name = (const char *)data;
    if(!strcmp(name, "rotation_center_coord")) {
      CTX::instance()->drawRotationCenter = 1;
      SPoint3 p(o->general.value[8]->value(), o->general.value[9]->value(),
                o->general.value[10]->value());
      drawContext *ctx =
        FlGui::instance()->getCurrentOpenglWindow()->getDrawContext();
      ctx->recenterForRotationCenterChange(p);
      FlGui::instance()->manip->update();
    }
    else if(!strcmp(name, "rotation_center")) {
      // pre-fill with cg
      for(int i = 0; i < 3; i++)
        o->general.value[8 + i]->value(CTX::instance()->cg[i]);
      SPoint3 p(CTX::instance()->cg[0], CTX::instance()->cg[1],
                CTX::instance()->cg[2]);
      drawContext *ctx =
        FlGui::instance()->getCurrentOpenglWindow()->getDrawContext();
      ctx->recenterForRotationCenterChange(p);
      FlGui::instance()->manip->update();
    }
    else if(!strcmp(name, "light_value")) {
      double x, y, z;
      x = o->general.value[2]->value();
      y = o->general.value[3]->value();
      z = o->general.value[4]->value();
      o->general.sphere->setValue(x, y, z);
    }
    else if(!strcmp(name, "light_sphere")) {
      double x, y, z;
      o->general.sphere->getValue(x, y, z);
      o->general.value[2]->value(x);
      o->general.value[3]->value(y);
      o->general.value[4]->value(z);
    }
  }

  opt_general_axes_auto_position(0, GMSH_SET, o->general.butt[0]->value());
  opt_general_small_axes(0, GMSH_SET, o->general.butt[1]->value());
  opt_general_fast_redraw(0, GMSH_SET, o->general.butt[2]->value());
  opt_general_mouse_hover_meshes(0, GMSH_SET, o->general.butt[11]->value());
  opt_general_mouse_hover_highlight(0, GMSH_SET, o->general.butt[23]->value());
  opt_general_mouse_invert_zoom(0, GMSH_SET, o->general.butt[22]->value());
  if(opt_general_antialiasing(0, GMSH_GET, 0) != o->general.butt[12]->value())
    opt_general_antialiasing(0, GMSH_SET, o->general.butt[12]->value());
  if(opt_general_shaders(0, GMSH_GET, 0) != o->general.butt[3]->value())
    opt_general_shaders(0, GMSH_SET | GMSH_GUI, o->general.butt[3]->value());
  opt_general_trackball(0, GMSH_SET, o->general.butt[5]->value());
  opt_general_terminal(0, GMSH_SET, o->general.butt[7]->value());
  double sessionrc = opt_general_session_save(0, GMSH_GET, 0);
  opt_general_session_save(0, GMSH_SET, o->general.butt[8]->value());
  if(sessionrc && !opt_general_session_save(0, GMSH_GET, 0))
    PrintOptions(
      0, GMSH_SESSIONRC, 1, 1,
      (CTX::instance()->homeDir + CTX::instance()->sessionFileName).c_str());
  opt_general_options_save(0, GMSH_SET, o->general.butt[9]->value());
  opt_general_expert_mode(0, GMSH_SET, o->general.butt[10]->value());
#if defined(HAVE_VISUDEV)
  opt_general_heavy_visualization(0, GMSH_SET, o->general.butt[20]->value());
#endif

  if(opt_general_gui_color_scheme(0, GMSH_GET, 0) !=
     o->general.choice[9]->value()) {
    opt_general_gui_color_scheme(0, GMSH_SET, o->general.choice[9]->value());
  }

  opt_general_tooltips(0, GMSH_SET, o->general.butt[13]->value());
  opt_general_confirm_overwrite(0, GMSH_SET, o->general.butt[14]->value());
  opt_general_rotation_center_cg(0, GMSH_SET, o->general.butt[15]->value());
  opt_general_draw_bounding_box(0, GMSH_SET, o->general.butt[6]->value());
  opt_general_polygon_offset_always(0, GMSH_SET, o->general.butt[4]->value());
  opt_general_axes_mikado(0, GMSH_SET, o->general.butt[16]->value());

  opt_general_shine_exponent(0, GMSH_SET, o->general.value[0]->value());
  opt_general_shine(0, GMSH_SET, o->general.value[1]->value());
  opt_general_light00(0, GMSH_SET, o->general.value[2]->value());
  opt_general_light01(0, GMSH_SET, o->general.value[3]->value());
  opt_general_light02(0, GMSH_SET, o->general.value[4]->value());
  opt_general_light03(0, GMSH_SET, o->general.value[13]->value());
  opt_general_verbosity(0, GMSH_SET, o->general.value[5]->value());
  opt_general_point_size(0, GMSH_SET, o->general.value[6]->value());
  opt_general_line_width(0, GMSH_SET, o->general.value[7]->value());
  opt_general_rotation_center0(0, GMSH_SET, o->general.value[8]->value());
  opt_general_rotation_center1(0, GMSH_SET, o->general.value[9]->value());
  opt_general_rotation_center2(0, GMSH_SET, o->general.value[10]->value());
  opt_general_quadric_subdivisions(0, GMSH_SET, o->general.value[11]->value());
  opt_general_graphics_fontsize(0, GMSH_SET, o->general.value[12]->value());
  opt_general_graphics_fontsize_title(0, GMSH_SET,
                                      o->general.value[28]->value());
  opt_general_clip_factor(0, GMSH_SET, o->general.value[14]->value());
  opt_general_polygon_offset_factor(0, GMSH_SET, o->general.value[15]->value());
  opt_general_polygon_offset_units(0, GMSH_SET, o->general.value[16]->value());
  opt_general_axes_ticks0(0, GMSH_SET, o->general.value[17]->value());
  opt_general_axes_ticks1(0, GMSH_SET, o->general.value[18]->value());
  opt_general_axes_ticks2(0, GMSH_SET, o->general.value[19]->value());
  opt_general_axes_xmin(0, GMSH_SET, o->general.value[20]->value());
  opt_general_axes_ymin(0, GMSH_SET, o->general.value[21]->value());
  opt_general_axes_zmin(0, GMSH_SET, o->general.value[22]->value());
  opt_general_axes_xmax(0, GMSH_SET, o->general.value[23]->value());
  opt_general_axes_ymax(0, GMSH_SET, o->general.value[24]->value());
  opt_general_axes_zmax(0, GMSH_SET, o->general.value[25]->value());
  opt_general_small_axes_position0(0, GMSH_SET, o->general.value[26]->value());
  opt_general_small_axes_position1(0, GMSH_SET, o->general.value[27]->value());
  opt_general_num_threads(0, GMSH_SET, o->general.value[32]->value());

  opt_general_default_filename(0, GMSH_SET, o->general.input[0]->value());
  opt_general_editor(0, GMSH_SET, o->general.input[1]->value());
  opt_general_axes_format0(0, GMSH_SET, o->general.input[3]->value());
  opt_general_axes_format1(0, GMSH_SET, o->general.input[4]->value());
  opt_general_axes_format2(0, GMSH_SET, o->general.input[5]->value());
  opt_general_axes_label0(0, GMSH_SET, o->general.input[6]->value());
  opt_general_axes_label1(0, GMSH_SET, o->general.input[7]->value());
  opt_general_axes_label2(0, GMSH_SET, o->general.input[8]->value());

  opt_general_vector_type(0, GMSH_SET, o->general.choice[0]->value() + 1);
  opt_general_graphics_font(0, GMSH_SET, o->general.choice[1]->text());
  opt_general_graphics_font_title(0, GMSH_SET, o->general.choice[6]->text());
  opt_general_graphics_font_engine(0, GMSH_SET, o->general.choice[7]->text());
  opt_general_orthographic(0, GMSH_SET, !o->general.choice[2]->value());
  opt_general_axes(0, GMSH_SET, o->general.choice[4]->value());
  opt_general_background_gradient(0, GMSH_SET, o->general.choice[5]->value());
  opt_general_shading(0, GMSH_SET, o->general.choice[8]->value());
  // light 0's W means nothing to studio shading
  o->activate("shaders");
  opt_general_studio_samples(0, GMSH_SET, o->general.value[33]->value());
  opt_general_studio_floor_offset(0, GMSH_SET, o->general.value[34]->value());
  opt_general_studio_light_spread(0, GMSH_SET, o->general.value[35]->value());
  opt_general_brightness(0, GMSH_SET, o->general.value[36]->value());

  if((opt_general_gamepad(0, GMSH_GET, 0) != o->general.butt[19]->value()) ||
     (opt_general_camera_mode(0, GMSH_GET, 0) !=
      o->general.butt[18]->value())) {
    if((opt_general_gamepad(0, GMSH_GET, 0) == 1) &&
       (o->general.butt[18]->value() == 0)) {
      o->general.butt[19]->value(0);
    }
    if((opt_general_camera_mode(0, GMSH_GET, 0) == 0) &&
       (o->general.butt[19]->value() == 1)) {
      o->general.butt[18]->value(1);
    }
  }
  opt_general_gamepad(0, GMSH_SET, o->general.butt[19]->value());
  opt_general_camera_mode(0, GMSH_SET, o->general.butt[18]->value());
  o->activate((const char *)data);

  opt_general_eye_sep_ratio(0, GMSH_SET, o->general.value[29]->value());
  opt_general_focallength_ratio(0, GMSH_SET, o->general.value[30]->value());
  opt_general_camera_aperture(0, GMSH_SET, o->general.value[31]->value());
  if(opt_general_stereo_mode(0, GMSH_GET, 0) != o->general.butt[17]->value()) {
    opt_general_stereo_mode(0, GMSH_SET, o->general.butt[17]->value());
    for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++)
      FlGui::instance()->graph[i]->setStereo((bool)CTX::instance()->stereo);
  }

  if(CTX::instance()->fastRedraw)
    CTX::instance()->post.draw = CTX::instance()->mesh.draw = 0;
  drawContext::global()->draw();
  CTX::instance()->post.draw = CTX::instance()->mesh.draw = 1;
  CTX::instance()->drawRotationCenter = 0;
}

static void general_arrow_param_cb(Fl_Widget *w, void *data)
{
  double a = opt_general_arrow_head_radius(0, GMSH_GET, 0);
  double b = opt_general_arrow_stem_length(0, GMSH_GET, 0);
  double c = opt_general_arrow_stem_radius(0, GMSH_GET, 0);
  while(arrowEditor("Arrow Editor", a, b, c)) {
    opt_general_arrow_head_radius(0, GMSH_SET, a);
    opt_general_arrow_stem_length(0, GMSH_SET, b);
    opt_general_arrow_stem_radius(0, GMSH_SET, c);
    drawContext::global()->draw();
  }
}

void geometry_options_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->options->showGroup(2);
}

static void geometry_options_ok_cb(Fl_Widget *w, void *data)
{
  optionWindow *o = FlGui::instance()->options;
  o->activate((const char *)data);

  opt_geometry_points(0, GMSH_SET, o->geo.butt[0]->value());
  opt_geometry_curves(0, GMSH_SET, o->geo.butt[1]->value());
  opt_geometry_surfaces(0, GMSH_SET, o->geo.butt[2]->value());
  opt_geometry_volumes(0, GMSH_SET, o->geo.butt[3]->value());
  opt_geometry_point_labels(0, GMSH_SET, o->geo.butt[4]->value());
  opt_geometry_curve_labels(0, GMSH_SET, o->geo.butt[5]->value());
  opt_geometry_surface_labels(0, GMSH_SET, o->geo.butt[6]->value());
  opt_geometry_volume_labels(0, GMSH_SET, o->geo.butt[7]->value());
  opt_geometry_auto_coherence(0, GMSH_SET, o->geo.butt[8]->value());
  opt_geometry_light(0, GMSH_SET, o->geo.butt[9]->value());
  opt_geometry_highlight_orphans(0, GMSH_SET, o->geo.butt[10]->value());

  opt_geometry_occ_fix_degenerated(0, GMSH_SET, o->geo.butt[16]->value());
  opt_geometry_occ_fix_small_edges(0, GMSH_SET, o->geo.butt[11]->value());
  opt_geometry_occ_fix_small_faces(0, GMSH_SET, o->geo.butt[12]->value());
  opt_geometry_occ_sew_faces(0, GMSH_SET, o->geo.butt[13]->value());
  opt_geometry_occ_make_solids(0, GMSH_SET, o->geo.butt[14]->value());
  opt_geometry_occ_scaling(0, GMSH_SET, o->geo.value[20]->value());

  opt_geometry_light_two_side(0, GMSH_SET, o->geo.butt[15]->value());

  opt_geometry_normals(0, GMSH_SET, o->geo.value[0]->value());
  opt_geometry_tangents(0, GMSH_SET, o->geo.value[1]->value());
  opt_geometry_tolerance(0, GMSH_SET, o->geo.value[2]->value());
  opt_geometry_point_size(0, GMSH_SET, o->geo.value[3]->value());
  opt_geometry_curve_width(0, GMSH_SET, o->geo.value[4]->value());
  opt_geometry_point_sel_size(0, GMSH_SET, o->geo.value[5]->value());
  opt_geometry_curve_sel_width(0, GMSH_SET, o->geo.value[6]->value());
  opt_geometry_transform00(0, GMSH_SET, o->geo.value[7]->value());
  opt_geometry_transform01(0, GMSH_SET, o->geo.value[8]->value());
  opt_geometry_transform02(0, GMSH_SET, o->geo.value[9]->value());
  opt_geometry_transform10(0, GMSH_SET, o->geo.value[11]->value());
  opt_geometry_transform11(0, GMSH_SET, o->geo.value[12]->value());
  opt_geometry_transform12(0, GMSH_SET, o->geo.value[13]->value());
  opt_geometry_transform20(0, GMSH_SET, o->geo.value[15]->value());
  opt_geometry_transform21(0, GMSH_SET, o->geo.value[16]->value());
  opt_geometry_transform22(0, GMSH_SET, o->geo.value[17]->value());
  opt_geometry_offset0(0, GMSH_SET, o->geo.value[10]->value());
  opt_geometry_offset1(0, GMSH_SET, o->geo.value[14]->value());
  opt_geometry_offset2(0, GMSH_SET, o->geo.value[18]->value());
  opt_geometry_num_sub_edges(0, GMSH_SET, o->geo.value[19]->value());

  opt_geometry_point_type(0, GMSH_SET, o->geo.choice[0]->value());
  opt_geometry_curve_type(0, GMSH_SET, o->geo.choice[1]->value());
  opt_geometry_surface_type(0, GMSH_SET, o->geo.choice[2]->value());
  opt_geometry_transform(0, GMSH_SET, o->geo.choice[3]->value());
  opt_geometry_label_type(0, GMSH_SET, o->geo.choice[4]->value());
  opt_geometry_volume_type(0, GMSH_SET, o->geo.choice[5]->value());
  opt_geometry_opacity(0, GMSH_SET, o->geo.value[21]->value());
  opt_geometry_opacity_mode(0, GMSH_SET, o->geo.choice[6]->value());

  if(CTX::instance()->fastRedraw)
    CTX::instance()->post.draw = CTX::instance()->mesh.draw = 0;
  drawContext::global()->draw();
  CTX::instance()->post.draw = CTX::instance()->mesh.draw = 1;
}

void mesh_options_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->options->showGroup(3);
}

static void mesh_options_ok_cb(Fl_Widget *w, void *data)
{
  optionWindow *o = FlGui::instance()->options;
  o->activate((const char *)data);

  opt_mesh_lc_from_curvature(0, GMSH_SET, o->mesh.value[1]->value());
  opt_mesh_lc_from_points(0, GMSH_SET, o->mesh.butt[5]->value());
  opt_mesh_lc_from_parametric_points(0, GMSH_SET, o->mesh.butt[26]->value());
  opt_mesh_lc_extend_from_boundary(0, GMSH_SET, o->mesh.butt[16]->value());
  opt_mesh_optimize(0, GMSH_SET, o->mesh.butt[2]->value());
  opt_mesh_optimize_netgen(0, GMSH_SET, o->mesh.butt[24]->value());
  opt_mesh_order(0, GMSH_SET, o->mesh.value[3]->value());
  // a check box for one of the five values (2), written only when this
  // widget was changed (FLTK clears the flag after its callback), so that the
  // other values, set elsewhere, are kept
  if(o->mesh.butt[3]->changed())
    opt_mesh_ho_optimize(0, GMSH_SET, o->mesh.butt[3]->value() ? 2 : 0);
  opt_mesh_second_order_incomplete(0, GMSH_SET, o->mesh.butt[4]->value());
  opt_mesh_nodes(0, GMSH_SET, o->mesh.butt[6]->value());
  opt_mesh_lines(0, GMSH_SET, o->mesh.butt[7]->value());
  opt_mesh_triangles(0, GMSH_SET, o->mesh.menu->menu()[0].value() ? 1 : 0);
  opt_mesh_quadrangles(0, GMSH_SET, o->mesh.menu->menu()[1].value() ? 1 : 0);
  opt_mesh_tetrahedra(0, GMSH_SET, o->mesh.menu->menu()[2].value() ? 1 : 0);
  opt_mesh_hexahedra(0, GMSH_SET, o->mesh.menu->menu()[3].value() ? 1 : 0);
  opt_mesh_prisms(0, GMSH_SET, o->mesh.menu->menu()[4].value() ? 1 : 0);
  opt_mesh_pyramids(0, GMSH_SET, o->mesh.menu->menu()[5].value() ? 1 : 0);
  opt_mesh_trihedra(0, GMSH_SET, o->mesh.menu->menu()[6].value() ? 1 : 0);
  opt_mesh_polygons(0, GMSH_SET, o->mesh.menu->menu()[7].value() ? 1 : 0);
  opt_mesh_polyhedra(0, GMSH_SET, o->mesh.menu->menu()[8].value() ? 1 : 0);
  opt_mesh_surface_edges(0, GMSH_SET, o->mesh.butt[8]->value());
  opt_mesh_surface_faces(0, GMSH_SET, o->mesh.butt[9]->value());
  opt_mesh_volume_edges(0, GMSH_SET, o->mesh.butt[10]->value());
  opt_mesh_volume_faces(0, GMSH_SET, o->mesh.butt[11]->value());
  opt_mesh_draw_skin_edges_only(0, GMSH_SET, o->mesh.butt[1]->value());
  opt_mesh_draw_skin_only(0, GMSH_SET, o->mesh.choice[12]->value());
  opt_mesh_node_labels(0, GMSH_SET, o->mesh.butt[12]->value());
  opt_mesh_line_labels(0, GMSH_SET, o->mesh.butt[13]->value());
  opt_mesh_surface_labels(0, GMSH_SET, o->mesh.butt[14]->value());
  opt_mesh_volume_labels(0, GMSH_SET, o->mesh.butt[15]->value());
  opt_mesh_light(0, GMSH_SET, o->mesh.butt[17]->value());
  opt_mesh_light_two_side(0, GMSH_SET, o->mesh.butt[18]->value());
  opt_mesh_smooth_normals(0, GMSH_SET, o->mesh.butt[19]->value());
  opt_mesh_recombine_all(0, GMSH_SET, o->mesh.butt[21]->value());

  opt_mesh_nb_smoothing(0, GMSH_SET, o->mesh.value[0]->value());
  opt_mesh_lc_factor(0, GMSH_SET, o->mesh.value[2]->value());
  opt_mesh_lc_min(0, GMSH_SET, o->mesh.value[25]->value());
  opt_mesh_lc_max(0, GMSH_SET, o->mesh.value[26]->value());
  opt_mesh_quality_inf(0, GMSH_SET, o->mesh.value[4]->value());
  opt_mesh_quality_sup(0, GMSH_SET, o->mesh.value[5]->value());
  opt_mesh_radius_inf(0, GMSH_SET, o->mesh.value[6]->value());
  opt_mesh_radius_sup(0, GMSH_SET, o->mesh.value[7]->value());
  opt_mesh_normals(0, GMSH_SET, o->mesh.value[8]->value());
  opt_mesh_explode(0, GMSH_SET, o->mesh.value[9]->value());
  opt_mesh_tangents(0, GMSH_SET, o->mesh.value[13]->value());
  opt_mesh_num_sub_edges(0, GMSH_SET, o->mesh.value[14]->value());
  opt_mesh_node_size(0, GMSH_SET, o->mesh.value[10]->value());
  opt_mesh_line_width(0, GMSH_SET, o->mesh.value[11]->value());
  opt_mesh_label_sampling(0, GMSH_SET, o->mesh.value[12]->value());
  opt_mesh_angle_smooth_normals(0, GMSH_SET, o->mesh.value[18]->value());

  opt_mesh_node_type(0, GMSH_SET, o->mesh.choice[0]->value());
  // the algorithm menus do not list every value (10 in 2D, the R-tree in 3D):
  // written only when changed, as the high-order optimization above
  if(o->mesh.choice[2]->changed())
    opt_mesh_algo2d(
      0, GMSH_SET,
      (o->mesh.choice[2]->value() == 1) ? ALGO_2D_MESHADAPT :
      (o->mesh.choice[2]->value() == 2) ? ALGO_2D_DELAUNAY :
      (o->mesh.choice[2]->value() == 3) ? ALGO_2D_FRONTAL :
      (o->mesh.choice[2]->value() == 4) ? ALGO_2D_BAMG :
      (o->mesh.choice[2]->value() == 5) ? ALGO_2D_FRONTAL_QUAD :
      (o->mesh.choice[2]->value() == 6) ? ALGO_2D_PACK_PRLGRMS :
      (o->mesh.choice[2]->value() == 7) ? ALGO_2D_QUAD_QUASI_STRUCT :
      (o->mesh.choice[2]->value() == 8) ? ALGO_2D_INITIAL_ONLY :
                                          ALGO_2D_AUTO);
  if(o->mesh.choice[3]->changed())
    opt_mesh_algo3d(0, GMSH_SET,
                    (o->mesh.choice[3]->value() == 1) ? ALGO_3D_PDEL3D :
                    (o->mesh.choice[3]->value() == 2) ? ALGO_3D_FRONTAL :
                    (o->mesh.choice[3]->value() == 3) ? ALGO_3D_HXT :
                    (o->mesh.choice[3]->value() == 4) ? ALGO_3D_MMG3D :
                    (o->mesh.choice[3]->value() == 5) ? ALGO_3D_INITIAL_ONLY :
                                                        ALGO_3D_DELAUNAY);
  opt_mesh_algo_recombine(0, GMSH_SET, o->mesh.choice[1]->value());
  opt_mesh_algo_subdivide(0, GMSH_SET, o->mesh.choice[5]->value());
  opt_mesh_color_carousel(0, GMSH_SET, o->mesh.choice[4]->value());
  opt_mesh_opacity(0, GMSH_SET, o->mesh.value[27]->value());
  opt_mesh_opacity_mode(0, GMSH_SET, o->mesh.choice[11]->value());
  opt_mesh_quality_type(0, GMSH_SET, o->mesh.choice[6]->value());
  opt_mesh_label_type(0, GMSH_SET, o->mesh.choice[7]->value());
  opt_mesh_light_lines(0, GMSH_SET, o->mesh.choice[10]->value());

  if(CTX::instance()->fastRedraw)
    CTX::instance()->post.draw = CTX::instance()->mesh.draw = 0;
  drawContext::global()->draw();
  CTX::instance()->post.draw = CTX::instance()->mesh.draw = 1;
}

void solver_options_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->options->showGroup(4);
}

static void solver_options_ok_cb(Fl_Widget *w, void *data)
{
  optionWindow *o = FlGui::instance()->options;
  o->activate((const char *)data);

#if defined(HAVE_ONELAB)
  int old_listen =
    (int)opt_solver_listen(0, GMSH_GET, o->solver.butt[0]->value());
  opt_solver_listen(0, GMSH_SET, o->solver.butt[0]->value());
  if(!old_listen && o->solver.butt[0]->value()) {
    auto it = onelab::server::instance()->findClient("Listen");
    if(it == onelab::server::instance()->lastClient()) {
      onelab::localNetworkClient *c = new gmshLocalNetworkClient("Listen", "");
      c->run();
    }
    else
      (*it)->run();
  }
#endif

  opt_solver_socket_name(0, GMSH_SET, o->solver.input[0]->value());
  opt_solver_timeout(0, GMSH_SET, o->solver.value[0]->value());
  opt_solver_python_interpreter(0, GMSH_SET, o->solver.input[1]->value());
  opt_solver_octave_interpreter(0, GMSH_SET, o->solver.input[2]->value());

  if(CTX::instance()->fastRedraw)
    CTX::instance()->post.draw = CTX::instance()->mesh.draw = 0;
  drawContext::global()->draw();
  CTX::instance()->post.draw = CTX::instance()->mesh.draw = 1;
}

void post_options_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->options->showGroup(5);
}

static void post_options_ok_cb(Fl_Widget *w, void *data)
{
  optionWindow *o = FlGui::instance()->options;
  o->activate((const char *)data);

  opt_post_anim_cycle(0, GMSH_SET, o->post.butt[0]->value());
  opt_post_combine_remove_orig(0, GMSH_SET, o->post.butt[1]->value());
  opt_post_horizontal_scales(0, GMSH_SET, o->post.butt[2]->value());

  opt_post_anim_delay(0, GMSH_SET, o->post.value[0]->value());
  opt_post_anim_step(0, GMSH_SET, o->post.value[1]->value());

  opt_post_link(0, GMSH_SET, o->post.choice[0]->value());

  if(CTX::instance()->fastRedraw)
    CTX::instance()->post.draw = CTX::instance()->mesh.draw = 0;
  drawContext::global()->draw();
  CTX::instance()->post.draw = CTX::instance()->mesh.draw = 1;
}

void view_options_cb(Fl_Widget *w, void *data)
{
  int num = (intptr_t)data;
  if(num < 0) { // automatic
    int current = FlGui::instance()->options->view.index;
    if(current >= 0 && current < (int)PView::list.size())
      num = current;
    else
      num = 0;
  }
  if(num >= 0 && num < (int)PView::list.size())
    FlGui::instance()->options->showGroup(num + 6);
}

static void view_options_timestep_cb(Fl_Widget *w, void *data)
{
  std::string str((const char *)data);
  for(int i = 0; i < (int)PView::list.size(); i++) {
    if(i == FlGui::instance()->options->view.index ||
       FlGui::instance()->options->viewList->browser->selected(i + 1)) {
      if(str == "=")
        opt_view_timestep(i, GMSH_SET, ((Fl_Value_Input *)w)->value());
      else if(str == "-")
        opt_view_timestep(i, GMSH_SET | GMSH_GUI,
                          opt_view_timestep(i, GMSH_GET, 0) - 1);
      else if(str == "+")
        opt_view_timestep(i, GMSH_SET | GMSH_GUI,
                          opt_view_timestep(i, GMSH_GET, 0) + 1);
    }
  }
  drawContext::global()->draw();
}

static void view_options_ok_cb(Fl_Widget *w, void *data)
{
  int current = FlGui::instance()->options->view.index;

  if(current < 0 || current >= (int)PView::list.size()) return;

  optionWindow *o = FlGui::instance()->options;
  o->activate((const char *)data);

  if(data) {
    std::string str((const char *)data);
    if(str == "range_min" || str == "range_max") {
      double vmin = 1e200;
      double vmax = -1e200;
      for(int i = 0; i < (int)PView::list.size(); i++) {
        if(i == current ||
           FlGui::instance()->options->viewList->browser->selected(i + 1)) {
          // compute min/max taking current visibility status and tensor display
          // mode into account
          if(str == "range_min")
            vmin = std::min(vmin, opt_view_min_visible(i, GMSH_GET, 0));
          else if(str == "range_max")
            vmax = std::max(vmax, opt_view_max_visible(i, GMSH_GET, 0));
        }
      }
      if(str == "range_min")
        o->view.value[31]->value(vmin);
      else if(str == "range_max")
        o->view.value[32]->value(vmax);
    }
  }

  int force = (int)opt_post_link(0, GMSH_GET, 0);

  // get the old values for the current view
  double scale_type = opt_view_scale_type(current, GMSH_GET, 0);
  double intervals_type = opt_view_intervals_type(current, GMSH_GET, 0);
  double point_type = opt_view_point_type(current, GMSH_GET, 0);
  double line_type = opt_view_line_type(current, GMSH_GET, 0);
  double vector_type = opt_view_vector_type(current, GMSH_GET, 0);
  double glyph_location = opt_view_glyph_location(current, GMSH_GET, 0);
  double tensor_type = opt_view_tensor_type(current, GMSH_GET, 0);
  double range_type = opt_view_range_type(current, GMSH_GET, 0);
  double axes = opt_view_axes(current, GMSH_GET, 0);
  double mikado = opt_view_axes_mikado(current, GMSH_GET, 0);
  double boundary = opt_view_boundary(current, GMSH_GET, 0);
  double external_view = opt_view_external_view(current, GMSH_GET, 0);
  double gen_raise_view = opt_view_gen_raise_view(current, GMSH_GET, 0);
  double show_time = opt_view_show_time(current, GMSH_GET, 0);
  double force_num_components =
    opt_view_force_num_components(current, GMSH_GET, 0);
  double center_glyphs = opt_view_center_glyphs(current, GMSH_GET, 0);

  double type = opt_view_type(current, GMSH_GET, 0);
  double saturate_values = opt_view_saturate_values(current, GMSH_GET, 0);
  double max_recursion_level =
    opt_view_max_recursion_level(current, GMSH_GET, 0);
  double adapt_vis_grid =
    opt_view_adapt_visualization_grid(current, GMSH_GET, 0);
  double adapt_skin_only = opt_view_adapt_skin_only(current, GMSH_GET, 0);
  double target_error = opt_view_target_error(current, GMSH_GET, 0);
  double show_element = opt_view_show_element(current, GMSH_GET, 0);
  double draw_skin_only = opt_view_draw_skin_only(current, GMSH_GET, 0);
  double draw_skin_edges_only =
    opt_view_draw_skin_edges_only(current, GMSH_GET, 0);
  double show_scale = opt_view_show_scale(current, GMSH_GET, 0);
  double auto_position = opt_view_auto_position(current, GMSH_GET, 0);
  double axes_auto_position = opt_view_axes_auto_position(current, GMSH_GET, 0);
  double draw_strings = opt_view_draw_strings(current, GMSH_GET, 0);
  double light = opt_view_light(current, GMSH_GET, 0);
  double light_two_side = opt_view_light_two_side(current, GMSH_GET, 0);
  double light_lines = opt_view_light_lines(current, GMSH_GET, 0);
  double smooth_normals = opt_view_smooth_normals(current, GMSH_GET, 0);
  double draw_points = opt_view_draw_points(current, GMSH_GET, 0);
  double draw_lines = opt_view_draw_lines(current, GMSH_GET, 0);
  double draw_triangles = opt_view_draw_triangles(current, GMSH_GET, 0);
  double draw_quadrangles = opt_view_draw_quadrangles(current, GMSH_GET, 0);
  double draw_tetrahedra = opt_view_draw_tetrahedra(current, GMSH_GET, 0);
  double draw_hexahedra = opt_view_draw_hexahedra(current, GMSH_GET, 0);
  double draw_prisms = opt_view_draw_prisms(current, GMSH_GET, 0);
  double draw_pyramids = opt_view_draw_pyramids(current, GMSH_GET, 0);
  double draw_trihedra = opt_view_draw_trihedra(current, GMSH_GET, 0);
  double draw_polygons = opt_view_draw_polygons(current, GMSH_GET, 0);
  double draw_polyhedra = opt_view_draw_polyhedra(current, GMSH_GET, 0);
  double draw_scalars = opt_view_draw_scalars(current, GMSH_GET, 0);
  double draw_vectors = opt_view_draw_vectors(current, GMSH_GET, 0);
  double draw_tensors = opt_view_draw_tensors(current, GMSH_GET, 0);
  double use_gen_raise = opt_view_use_gen_raise(current, GMSH_GET, 0);
  double use_stipple = opt_view_use_stipple(current, GMSH_GET, 0);
  double opacity = opt_view_opacity(current, GMSH_GET, 0);

  double normals = opt_view_normals(current, GMSH_GET, 0);
  double tangents = opt_view_tangents(current, GMSH_GET, 0);
  double custom_min = opt_view_custom_min(current, GMSH_GET, 0);
  double scale_threshold = opt_view_scale_threshold(current, GMSH_GET, 0);
  double custom_max = opt_view_custom_max(current, GMSH_GET, 0);
  double nb_iso = opt_view_nb_iso(current, GMSH_GET, 0);
  double offset0 = opt_view_offset0(current, GMSH_GET, 0);
  double offset1 = opt_view_offset1(current, GMSH_GET, 0);
  double offset2 = opt_view_offset2(current, GMSH_GET, 0);
  double transform00 = opt_view_transform00(current, GMSH_GET, 0);
  double transform01 = opt_view_transform01(current, GMSH_GET, 0);
  double transform02 = opt_view_transform02(current, GMSH_GET, 0);
  double transform10 = opt_view_transform10(current, GMSH_GET, 0);
  double transform11 = opt_view_transform11(current, GMSH_GET, 0);
  double transform12 = opt_view_transform12(current, GMSH_GET, 0);
  double transform20 = opt_view_transform20(current, GMSH_GET, 0);
  double transform21 = opt_view_transform21(current, GMSH_GET, 0);
  double transform22 = opt_view_transform22(current, GMSH_GET, 0);
  double raise0 = opt_view_raise0(current, GMSH_GET, 0);
  double raise1 = opt_view_raise1(current, GMSH_GET, 0);
  double raise2 = opt_view_raise2(current, GMSH_GET, 0);
  double normal_raise = opt_view_normal_raise(current, GMSH_GET, 0);
  double timestep = opt_view_timestep(current, GMSH_GET, 0);
  double arrow_size_min = opt_view_arrow_size_min(current, GMSH_GET, 0);
  double arrow_size_max = opt_view_arrow_size_max(current, GMSH_GET, 0);
  double displacement_factor =
    opt_view_displacement_factor(current, GMSH_GET, 0);
  double point_size = opt_view_point_size(current, GMSH_GET, 0);
  int colormap_number = (int)opt_view_colormap_number(current, GMSH_GET, 0);
  // a map picked in the map widget itself: the chooser follows, or it
  // would put the map it still shows back
  if(w == o->view.colorbar) o->view.choice[17]->value(colormap_number);
  double line_width = opt_view_line_width(current, GMSH_GET, 0);
  double outline_width = opt_view_outline_width(current, GMSH_GET, 0);
  double explode = opt_view_explode(current, GMSH_GET, 0);
  double angle_smooth_normals =
    opt_view_angle_smooth_normals(current, GMSH_GET, 0);
  double position0 = opt_view_position0(current, GMSH_GET, 0);
  double position1 = opt_view_position1(current, GMSH_GET, 0);
  double size0 = opt_view_size0(current, GMSH_GET, 0);
  double size1 = opt_view_size1(current, GMSH_GET, 0);
  double axes_ticks0 = opt_view_axes_ticks0(current, GMSH_GET, 0);
  double axes_ticks1 = opt_view_axes_ticks1(current, GMSH_GET, 0);
  double axes_ticks2 = opt_view_axes_ticks2(current, GMSH_GET, 0);
  double axes_xmin = opt_view_axes_xmin(current, GMSH_GET, 0);
  double axes_ymin = opt_view_axes_ymin(current, GMSH_GET, 0);
  double axes_zmin = opt_view_axes_zmin(current, GMSH_GET, 0);
  double axes_xmax = opt_view_axes_xmax(current, GMSH_GET, 0);
  double axes_ymax = opt_view_axes_ymax(current, GMSH_GET, 0);
  double axes_zmax = opt_view_axes_zmax(current, GMSH_GET, 0);
  double gen_raise_factor = opt_view_gen_raise_factor(current, GMSH_GET, 0);
  double component_map0 = opt_view_component_map0(current, GMSH_GET, 0);
  double component_map1 = opt_view_component_map1(current, GMSH_GET, 0);
  double component_map2 = opt_view_component_map2(current, GMSH_GET, 0);
  double component_map3 = opt_view_component_map3(current, GMSH_GET, 0);
  double component_map4 = opt_view_component_map4(current, GMSH_GET, 0);
  double component_map5 = opt_view_component_map5(current, GMSH_GET, 0);
  double component_map6 = opt_view_component_map6(current, GMSH_GET, 0);
  double component_map7 = opt_view_component_map7(current, GMSH_GET, 0);
  double component_map8 = opt_view_component_map8(current, GMSH_GET, 0);
  double sampling = opt_view_sampling(current, GMSH_GET, 0);

  std::string name = opt_view_name(current, GMSH_GET, "");
  std::string format = opt_view_number_format(current, GMSH_GET, "");
  std::string axes_label0 = opt_view_axes_label0(current, GMSH_GET, "");
  std::string axes_label1 = opt_view_axes_label1(current, GMSH_GET, "");
  std::string axes_label2 = opt_view_axes_label2(current, GMSH_GET, "");
  std::string axes_format0 = opt_view_axes_format0(current, GMSH_GET, "");
  std::string axes_format1 = opt_view_axes_format1(current, GMSH_GET, "");
  std::string axes_format2 = opt_view_axes_format2(current, GMSH_GET, "");
  std::string gen_raise0 = opt_view_gen_raise0(current, GMSH_GET, "");
  std::string gen_raise1 = opt_view_gen_raise1(current, GMSH_GET, "");
  std::string gen_raise2 = opt_view_gen_raise2(current, GMSH_GET, "");

  // modify only the views that need to be updated
  for(int i = 0; i < (int)PView::list.size(); i++) {
    if(i == current ||
       FlGui::instance()->options->viewList->browser->selected(i + 1)) {
      double val;

      // view_choice

      val = o->view.choice[1]->value() + 1;
      if(force || (val != scale_type)) opt_view_scale_type(i, GMSH_SET, val);

      val = o->view.choice[0]->value() + 1;
      if(force || (val != intervals_type))
        opt_view_intervals_type(i, GMSH_SET, val);

      val = o->view.choice[5]->value();
      if(force || (val != point_type)) opt_view_point_type(i, GMSH_SET, val);

      val = o->view.choice[6]->value();
      if(force || (val != line_type)) opt_view_line_type(i, GMSH_SET, val);

      val = o->view.choice[2]->value() + 1;
      if(force || (val != vector_type)) opt_view_vector_type(i, GMSH_SET, val);

      val = o->view.choice[3]->value() + 1;
      if(force || (val != glyph_location))
        opt_view_glyph_location(i, GMSH_SET, val);

      val = o->view.choice[4]->value() + 1;
      if(force || (val != tensor_type)) opt_view_tensor_type(i, GMSH_SET, val);

      val = o->view.choice[7]->value() + 1;
      if(force || (val != range_type)) opt_view_range_type(i, GMSH_SET, val);

      val = o->view.choice[8]->value();
      if(force || (val != axes)) opt_view_axes(i, GMSH_SET, val);

      val = o->view.choice[17]->value();
      if(force || (val != colormap_number)) {
        opt_view_colormap_number(i, GMSH_SET, val);
        o->view.colorbar->redraw();
      }

      val = o->view.choice[9]->value();
      if(force || (val != boundary)) opt_view_boundary(i, GMSH_SET, val);

      val = o->view.choice[10]->value() - 1;
      if(force || (val != external_view))
        opt_view_external_view(i, GMSH_SET, val);

      val = o->view.choice[11]->value() - 1;
      if(force || (val != gen_raise_view))
        opt_view_gen_raise_view(i, GMSH_SET, val);

      val = o->view.choice[12]->value();
      if(force || (val != show_time)) opt_view_show_time(i, GMSH_SET, val);

      val = o->view.choice[13]->value() + 1;
      if(force || (val != type)) opt_view_type(i, GMSH_SET, val);

      val = (o->view.choice[14]->value() == 1) ? 1 :
            (o->view.choice[14]->value() == 2) ? 3 :
            (o->view.choice[14]->value() == 3) ? 9 :
                                                 0;
      if(force || (val != force_num_components))
        opt_view_force_num_components(i, GMSH_SET, val);

      val = o->view.choice[15]->value();
      if(force || (val != center_glyphs))
        opt_view_center_glyphs(i, GMSH_SET, val);

      val = o->view.choice[16]->value();
      if(force || (val != auto_position))
        opt_view_auto_position(i, GMSH_SET, val);

      // view_butts

      val = o->view.butt[0]->value();
      if(force || (val != adapt_vis_grid))
        opt_view_adapt_visualization_grid(i, GMSH_SET, val);

      val = o->view.choice[18]->value();
      if(force || (val != adapt_skin_only))
        opt_view_adapt_skin_only(i, GMSH_SET, val);

      val = o->view.butt[38]->value();
      if(force || (val != saturate_values))
        opt_view_saturate_values(i, GMSH_SET, val);

      val = o->view.butt[10]->value();
      if(force || (val != show_element))
        opt_view_show_element(i, GMSH_SET, val);

      val = o->view.butt[1]->value();
      if(force || (val != draw_skin_edges_only))
        opt_view_draw_skin_edges_only(i, GMSH_SET, val);

      val = o->view.butt[2]->value();
      if(force || (val != draw_skin_only))
        opt_view_draw_skin_only(i, GMSH_SET, val);

      val = o->view.butt[4]->value();
      if(force || (val != show_scale)) opt_view_show_scale(i, GMSH_SET, val);

      val = o->view.butt[3]->value();
      if(force || (val != mikado)) opt_view_axes_mikado(i, GMSH_SET, val);

      val = o->view.butt[25]->value();
      if(force || (val != axes_auto_position))
        opt_view_axes_auto_position(i, GMSH_SET, val);

      val = o->view.butt[5]->value();
      if(force || (val != draw_strings))
        opt_view_draw_strings(i, GMSH_SET, val);

      val = o->view.butt[11]->value();
      if(force || (val != light)) opt_view_light(i, GMSH_SET, val);

      val = o->view.butt[8]->value();
      if(force || (val != light_lines)) opt_view_light_lines(i, GMSH_SET, val);

      val = o->view.butt[9]->value();
      if(force || (val != light_two_side))
        opt_view_light_two_side(i, GMSH_SET, val);

      val = o->view.butt[12]->value();
      if(force || (val != smooth_normals))
        opt_view_smooth_normals(i, GMSH_SET, val);

      val = o->view.menu[0]->menu()[0].value() ? 1 : 0;
      if(force || (val != draw_scalars))
        opt_view_draw_scalars(i, GMSH_SET, val);

      val = o->view.menu[0]->menu()[1].value() ? 1 : 0;
      if(force || (val != draw_vectors))
        opt_view_draw_vectors(i, GMSH_SET, val);

      val = o->view.menu[0]->menu()[2].value() ? 1 : 0;
      if(force || (val != draw_tensors))
        opt_view_draw_tensors(i, GMSH_SET, val);

      val = o->view.menu[1]->menu()[0].value() ? 1 : 0;
      if(force || (val != draw_points)) opt_view_draw_points(i, GMSH_SET, val);

      val = o->view.menu[1]->menu()[1].value() ? 1 : 0;
      if(force || (val != draw_lines)) opt_view_draw_lines(i, GMSH_SET, val);

      val = o->view.menu[1]->menu()[2].value() ? 1 : 0;
      if(force || (val != draw_triangles))
        opt_view_draw_triangles(i, GMSH_SET, val);

      val = o->view.menu[1]->menu()[3].value() ? 1 : 0;
      if(force || (val != draw_quadrangles))
        opt_view_draw_quadrangles(i, GMSH_SET, val);

      val = o->view.menu[1]->menu()[4].value() ? 1 : 0;
      if(force || (val != draw_tetrahedra))
        opt_view_draw_tetrahedra(i, GMSH_SET, val);

      val = o->view.menu[1]->menu()[5].value() ? 1 : 0;
      if(force || (val != draw_hexahedra))
        opt_view_draw_hexahedra(i, GMSH_SET, val);

      val = o->view.menu[1]->menu()[6].value() ? 1 : 0;
      if(force || (val != draw_prisms)) opt_view_draw_prisms(i, GMSH_SET, val);

      val = o->view.menu[1]->menu()[7].value() ? 1 : 0;
      if(force || (val != draw_pyramids))
        opt_view_draw_pyramids(i, GMSH_SET, val);

      val = o->view.menu[1]->menu()[8].value() ? 1 : 0;
      if(force || (val != draw_trihedra))
        opt_view_draw_trihedra(i, GMSH_SET, val);

      val = o->view.menu[1]->menu()[9].value() ? 1 : 0;
      if(force || (val != draw_polygons))
        opt_view_draw_polygons(i, GMSH_SET, val);

      val = o->view.menu[1]->menu()[10].value() ? 1 : 0;
      if(force || (val != draw_polyhedra))
        opt_view_draw_polyhedra(i, GMSH_SET, val);

      val = o->view.butt[6]->value();
      if(force || (val != use_gen_raise))
        opt_view_use_gen_raise(i, GMSH_SET, val);

      val = o->view.butt[26]->value();
      if(force || (val != use_stipple)) opt_view_use_stipple(i, GMSH_SET, val);

      val = o->view.value[79]->value();
      if(force || (val != opacity)) opt_view_opacity(i, GMSH_SET, val);

      // view_values

      val = o->view.value[0]->value();
      if(force || (val != normals)) opt_view_normals(i, GMSH_SET, val);

      val = o->view.value[1]->value();
      if(force || (val != tangents)) opt_view_tangents(i, GMSH_SET, val);

      val = o->view.value[31]->value();
      if(force || (val != custom_min)) opt_view_custom_min(i, GMSH_SET, val);

      val = o->view.value[32]->value();
      if(force || (val != custom_max)) opt_view_custom_max(i, GMSH_SET, val);

      val = o->view.value[35]->value();
      if(force || (val != scale_threshold))
        opt_view_scale_threshold(i, GMSH_SET, val);

      val = o->view.value[33]->value();
      if(force || (val != max_recursion_level))
        opt_view_max_recursion_level(i, GMSH_SET, val);

      val = o->view.value[34]->value();
      if(force || (val != target_error))
        opt_view_target_error(i, GMSH_SET, val);

      val = o->view.value[30]->value();
      if(force || (val != nb_iso)) opt_view_nb_iso(i, GMSH_SET, val);

      val = o->view.value[40]->value();
      if(force || (val != offset0)) opt_view_offset0(i, GMSH_SET, val);

      val = o->view.value[41]->value();
      if(force || (val != offset1)) opt_view_offset1(i, GMSH_SET, val);

      val = o->view.value[42]->value();
      if(force || (val != offset2)) opt_view_offset2(i, GMSH_SET, val);

      val = o->view.value[51]->value();
      if(force || (val != transform00)) opt_view_transform00(i, GMSH_SET, val);

      val = o->view.value[52]->value();
      if(force || (val != transform01)) opt_view_transform01(i, GMSH_SET, val);

      val = o->view.value[53]->value();
      if(force || (val != transform02)) opt_view_transform02(i, GMSH_SET, val);

      val = o->view.value[54]->value();
      if(force || (val != transform10)) opt_view_transform10(i, GMSH_SET, val);

      val = o->view.value[55]->value();
      if(force || (val != transform11)) opt_view_transform11(i, GMSH_SET, val);

      val = o->view.value[56]->value();
      if(force || (val != transform12)) opt_view_transform12(i, GMSH_SET, val);

      val = o->view.value[57]->value();
      if(force || (val != transform20)) opt_view_transform20(i, GMSH_SET, val);

      val = o->view.value[58]->value();
      if(force || (val != transform21)) opt_view_transform21(i, GMSH_SET, val);

      val = o->view.value[59]->value();
      if(force || (val != transform22)) opt_view_transform22(i, GMSH_SET, val);

      val = o->view.value[43]->value();
      if(force || (val != raise0)) opt_view_raise0(i, GMSH_SET, val);

      val = o->view.value[44]->value();
      if(force || (val != raise1)) opt_view_raise1(i, GMSH_SET, val);

      val = o->view.value[45]->value();
      if(force || (val != raise2)) opt_view_raise2(i, GMSH_SET, val);

      val = o->view.value[46]->value();
      if(force || (val != normal_raise))
        opt_view_normal_raise(i, GMSH_SET, val);

      val = o->view.value[50]->value();
      if(force || (val != timestep)) opt_view_timestep(i, GMSH_SET, val);

      val = o->view.value[64]->value();
      if(force || (val != arrow_size_min))
        opt_view_arrow_size_min(i, GMSH_SET, val);

      val = o->view.value[60]->value();
      if(force || (val != arrow_size_max))
        opt_view_arrow_size_max(i, GMSH_SET, val);

      val = o->view.value[63]->value();
      if(force || (val != displacement_factor))
        opt_view_displacement_factor(i, GMSH_SET, val);

      val = o->view.value[61]->value();
      if(force || (val != point_size)) opt_view_point_size(i, GMSH_SET, val);

      val = o->view.value[62]->value();
      if(force || (val != line_width)) opt_view_line_width(i, GMSH_SET, val);

      val = o->view.value[80]->value();
      if(force || (val != outline_width))
        opt_view_outline_width(i, GMSH_SET, val);

      val = o->view.value[12]->value();
      if(force || (val != explode)) opt_view_explode(i, GMSH_SET, val);

      val = o->view.value[10]->value();
      if(force || (val != angle_smooth_normals))
        opt_view_angle_smooth_normals(i, GMSH_SET, val);

      val = o->view.value[20]->value();
      if(force || (val != position0)) opt_view_position0(i, GMSH_SET, val);

      val = o->view.value[21]->value();
      if(force || (val != position1)) opt_view_position1(i, GMSH_SET, val);

      val = o->view.value[22]->value();
      if(force || (val != size0)) opt_view_size0(i, GMSH_SET, val);

      val = o->view.value[23]->value();
      if(force || (val != size1)) opt_view_size1(i, GMSH_SET, val);

      val = o->view.value[13]->value();
      if(force || (val != axes_xmin)) opt_view_axes_xmin(i, GMSH_SET, val);

      val = o->view.value[14]->value();
      if(force || (val != axes_ymin)) opt_view_axes_ymin(i, GMSH_SET, val);

      val = o->view.value[15]->value();
      if(force || (val != axes_zmin)) opt_view_axes_zmin(i, GMSH_SET, val);

      val = o->view.value[16]->value();
      if(force || (val != axes_xmax)) opt_view_axes_xmax(i, GMSH_SET, val);

      val = o->view.value[17]->value();
      if(force || (val != axes_ymax)) opt_view_axes_ymax(i, GMSH_SET, val);

      val = o->view.value[18]->value();
      if(force || (val != axes_zmax)) opt_view_axes_zmax(i, GMSH_SET, val);

      val = o->view.value[2]->value();
      if(force || (val != gen_raise_factor))
        opt_view_gen_raise_factor(i, GMSH_SET, val);

      val = o->view.value[3]->value();
      if(force || (val != axes_ticks0)) opt_view_axes_ticks0(i, GMSH_SET, val);

      val = o->view.value[4]->value();
      if(force || (val != axes_ticks1)) opt_view_axes_ticks1(i, GMSH_SET, val);

      val = o->view.value[5]->value();
      if(force || (val != axes_ticks2)) opt_view_axes_ticks2(i, GMSH_SET, val);

      val = o->view.value[70]->value();
      if(force || (val != component_map0))
        opt_view_component_map0(i, GMSH_SET, val);

      val = o->view.value[71]->value();
      if(force || (val != component_map1))
        opt_view_component_map1(i, GMSH_SET, val);

      val = o->view.value[72]->value();
      if(force || (val != component_map2))
        opt_view_component_map2(i, GMSH_SET, val);

      val = o->view.value[73]->value();
      if(force || (val != component_map3))
        opt_view_component_map3(i, GMSH_SET, val);

      val = o->view.value[74]->value();
      if(force || (val != component_map4))
        opt_view_component_map4(i, GMSH_SET, val);

      val = o->view.value[75]->value();
      if(force || (val != component_map5))
        opt_view_component_map5(i, GMSH_SET, val);

      val = o->view.value[76]->value();
      if(force || (val != component_map6))
        opt_view_component_map6(i, GMSH_SET, val);

      val = o->view.value[77]->value();
      if(force || (val != component_map7))
        opt_view_component_map7(i, GMSH_SET, val);

      val = o->view.value[78]->value();
      if(force || (val != component_map8))
        opt_view_component_map8(i, GMSH_SET, val);

      val = o->view.value[6]->value();
      if(force || (val != sampling)) opt_view_sampling(i, GMSH_SET, val);

      // view_inputs

      std::string str;

      str = o->view.input[0]->value();
      if(force || (str != name)) opt_view_name(i, GMSH_SET, str);

      str = o->view.input[1]->value();
      if(force || (str != format)) opt_view_number_format(i, GMSH_SET, str);

      str = o->view.input[10]->value();
      if(force || (str != axes_label0)) opt_view_axes_label0(i, GMSH_SET, str);

      str = o->view.input[11]->value();
      if(force || (str != axes_label1)) opt_view_axes_label1(i, GMSH_SET, str);

      str = o->view.input[12]->value();
      if(force || (str != axes_label2)) opt_view_axes_label2(i, GMSH_SET, str);

      str = o->view.input[7]->value();
      if(force || (str != axes_format0))
        opt_view_axes_format0(i, GMSH_SET, str);

      str = o->view.input[8]->value();
      if(force || (str != axes_format1))
        opt_view_axes_format1(i, GMSH_SET, str);

      str = o->view.input[9]->value();
      if(force || (str != axes_format2))
        opt_view_axes_format2(i, GMSH_SET, str);

      str = o->view.input[4]->value();
      if(force || (str != gen_raise0)) opt_view_gen_raise0(i, GMSH_SET, str);

      str = o->view.input[5]->value();
      if(force || (str != gen_raise1)) opt_view_gen_raise1(i, GMSH_SET, str);

      str = o->view.input[6]->value();
      if(force || (str != gen_raise2)) opt_view_gen_raise2(i, GMSH_SET, str);

      // colors (since the color buttons modify the values directly
      // through callbacks, we can use the opt_XXX routines directly)
      if(force || (i != current)) {
        opt_view_color_points(i, GMSH_SET,
                              opt_view_color_points(current, GMSH_GET, 0));
        opt_view_color_lines(i, GMSH_SET,
                             opt_view_color_lines(current, GMSH_GET, 0));
        opt_view_color_triangles(
          i, GMSH_SET, opt_view_color_triangles(current, GMSH_GET, 0));
        opt_view_color_quadrangles(
          i, GMSH_SET, opt_view_color_quadrangles(current, GMSH_GET, 0));
        opt_view_color_tetrahedra(
          i, GMSH_SET, opt_view_color_tetrahedra(current, GMSH_GET, 0));
        opt_view_color_hexahedra(
          i, GMSH_SET, opt_view_color_hexahedra(current, GMSH_GET, 0));
        opt_view_color_prisms(i, GMSH_SET,
                              opt_view_color_prisms(current, GMSH_GET, 0));
        opt_view_color_pyramids(i, GMSH_SET,
                                opt_view_color_pyramids(current, GMSH_GET, 0));
        opt_view_color_trihedra(i, GMSH_SET,
                                opt_view_color_trihedra(current, GMSH_GET, 0));
        opt_view_color_polygons(i, GMSH_SET,
                                opt_view_color_polygons(current, GMSH_GET, 0));
        opt_view_color_polyhedra(
          i, GMSH_SET, opt_view_color_polyhedra(current, GMSH_GET, 0));
        opt_view_color_tangents(i, GMSH_SET,
                                opt_view_color_tangents(current, GMSH_GET, 0));
        opt_view_color_normals(i, GMSH_SET,
                               opt_view_color_normals(current, GMSH_GET, 0));
        opt_view_color_text2d(i, GMSH_SET,
                              opt_view_color_text2d(current, GMSH_GET, 0));
        opt_view_color_text3d(i, GMSH_SET,
                              opt_view_color_text3d(current, GMSH_GET, 0));
        opt_view_color_axes(i, GMSH_SET,
                            opt_view_color_axes(current, GMSH_GET, 0));
        opt_view_color_background2d(
          i, GMSH_SET, opt_view_color_background2d(current, GMSH_GET, 0));
      }
    }
  }

  // colorbar window: copied once the loop above has set the current view,
  // or the views before it get its old map back
  for(int i = 0; i < (int)PView::list.size(); i++) {
    if((force && i == current) ||
       (i != current &&
        FlGui::instance()->options->viewList->browser->selected(i + 1))) {
      ColorTable_Copy(&PView::list[current]->getOptions()->colorTable);
      ColorTable_Paste(&PView::list[i]->getOptions()->colorTable);
      PView::list[i]->setChanged(true);
    }
  }

  if(CTX::instance()->fastRedraw)
    CTX::instance()->post.draw = CTX::instance()->mesh.draw = 0;
  drawContext::global()->draw();
  CTX::instance()->post.draw = CTX::instance()->mesh.draw = 1;
}

static void view_options_max_recursion_cb(Fl_Widget *w, void *data)
{
  std::string str((const char *)data);
  int val = (int)FlGui::instance()->options->view.value[33]->value();
  if(str == "-" && val > 0)
    FlGui::instance()->options->view.value[33]->value(val - 1);
  else if(str == "+")
    FlGui::instance()->options->view.value[33]->value(val + 1);
  view_options_ok_cb(nullptr, nullptr);
}

// a check button with the option it sets as tooltip (if any), as this
// window's are
static Fl_Check_Button *checkButton(int x, int y, int w, int h,
                                    const char *label, const char *tooltip,
                                    Fl_Callback *cb = nullptr,
                                    void *data = nullptr)
{
  Fl_Check_Button *b = new Fl_Check_Button(x, y, w, h, label);
  b->tooltip(tooltip);
  if(cb) b->callback(cb, data);
  return b;
}

// a value input with the option it sets as tooltip (if any), as this window's
// are
static Fl_Value_Input *valueInput(int x, int y, int w, int h, const char *label,
                                  const char *tooltip,
                                  Fl_Callback *cb = nullptr,
                                  void *data = nullptr)
{
  Fl_Value_Input *v = new Fl_Value_Input(x, y, w, h, label);
  v->tooltip(tooltip);
  if(cb) v->callback(cb, data);
  return v;
}

// with its range and the step of its scrolling (when General.InputScrolling
// is set)
static Fl_Value_Input *valueInput(int x, int y, int w, int h, const char *label,
                                  const char *tooltip, double min, double max,
                                  double step, Fl_Callback *cb,
                                  void *data = nullptr)
{
  Fl_Value_Input *v = valueInput(x, y, w, h, label, tooltip, cb, data);
  v->minimum(min);
  v->maximum(max);
  if(CTX::instance()->inputScrolling) v->step(step);
  return v;
}

optionWindow::optionWindow(int deltaFontSize) : gmpdoption(nullptr)
{
  general.butt.resize(50, nullptr);
  general.push.resize(50, nullptr);
  general.value.resize(50, nullptr);
  general.color.resize(colorOptions(GeneralOptions_Color), nullptr);
  general.input.resize(50, nullptr);
  general.choice.resize(50, nullptr);
  geo.butt.resize(50, nullptr);
  geo.value.resize(50, nullptr);
  geo.color.resize(colorOptions(GeometryOptions_Color), nullptr);
  geo.choice.resize(50, nullptr);
  mesh.butt.resize(50, nullptr);
  mesh.retbutt.resize(50, nullptr);
  mesh.input.resize(50, nullptr);
  mesh.value.resize(50, nullptr);
  mesh.color.resize(colorOptions(MeshOptions_Color), nullptr);
  mesh.choice.resize(50, nullptr);
  solver.butt.resize(50, nullptr);
  solver.value.resize(50, nullptr);
  solver.input.resize(50, nullptr);
  post.butt.resize(50, nullptr);
  post.value.resize(50, nullptr);
  post.choice.resize(50, nullptr);
  view.butt.resize(50, nullptr);
  view.value.resize(100, nullptr);
  view.input.resize(50, nullptr);
  view.push.resize(50, nullptr);
  view.choice.resize(50, nullptr);
  view.color.resize(colorOptions(ViewOptions_Color), nullptr);
  view.label.resize(50, nullptr);
  view.menu.resize(50, nullptr);

  FL_NORMAL_SIZE -= deltaFontSize;

  // the widgets of each section are built at their place in a tab of at most
  // 11 rows of this width; layout() then stacks the sections in the scroll
  // the sections lie in a scroll inside the frame of the tabs
  int L = WB + Fl::box_dx(FL_THIN_UP_BOX);
  int width = TW - 2 * L - Fl::scrollbar_size();
  int height = 12 * BH + 4 * WB;
  _rowHeight = BH;
  _buttonWidth = BB;
  _width = width;
  _current = 0;

  // the scrollbar, shown when needed, ends where the search and the category
  // bar end, so that everything is aligned on the right
  int winWidth = TW;
  int winHeight = CTX::instance()->optHeight;
  {
    int sx, sy, sw, sh;
    Fl::screen_work_area(sx, sy, sw, sh);
    winHeight = std::min(winHeight, sh - 2 * BH);
  }
  winHeight = std::max(winHeight, 12 * BH);

  win = new paletteWindow(winWidth, winHeight,
                          CTX::instance()->nonModalWindows ? true : false,
                          nullptr, CTX::instance()->optOffset);
  win->box(GMSH_WINDOW_BOX);
  // the tabs show the category, the view list the views
  win->label("Options");

  // the search goes through all the categories, hence above them
  search =
    searchBox(WB, WB, winWidth - 2 * WB, BH, "Search options",
              "Show only the options whose label, name or choices match the\n"
              "regular expression, whatever the case",
              options_search_cb);

  // the categories as tabs, empty: what they show is placed by layout()
  {
    static const char *names[6] = {"General", "Geometry", "Mesh",
                                   "Solver",  "Post-pro", "Views"};
    _tabs = new accentTabs(WB, 2 * WB + BH, winWidth - 2 * WB,
                           winHeight - 3 * WB - BH);
    for(int i = 0; i < 6; i++) {
      _categoryTab[i] = new Fl_Group(WB, 2 * WB + 2 * BH, winWidth - 2 * WB,
                                     winHeight - 3 * WB - 2 * BH, names[i]);
      _categoryTab[i]->end();
    }
    _tabs->end();
    _tabs->callback(options_category_cb);
  }

  // the views whose options change together: the one shown and the selected
  viewList =
    new targetList(L + WB, 2 * WB + 2 * BH, winWidth - 2 * L - 2 * WB, BH,
                   {"All", "Visible", "Only this"}, options_select_views_cb);
  viewList->browser->callback(options_browser_cb);
  viewList->hide();

  scroll = new Fl_Scroll(L, 3 * WB + 2 * BH, winWidth - 2 * L,
                         winHeight - 4 * WB - 2 * BH);
  scroll->type(Fl_Scroll::VERTICAL);

  int BW = width - 4 * WB;
  // the second column of a row: after the field and a label of 7 em, to the
  // right margin
  int C2 = L + 2 * WB + IW + 7 * FL_NORMAL_SIZE;
  int RW = width - 4 * WB - IW - 7 * FL_NORMAL_SIZE;

  // General options
  general.group = new Fl_Group(L, 0, width, height, "General Options");
  {
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "General");

      static Fl_Menu_Item menu_interface[] = {{"Light", 0, nullptr, nullptr},
                                              {"Dark", 0, nullptr, nullptr},
                                              {"System", 0, nullptr, nullptr},
                                              {nullptr}};
      general.choice[9] =
        new Fl_Choice(L + 2 * WB, 2 * WB + 1 * BH, IW, BH, "Interface");
      general.choice[9]->menu(menu_interface);
      general.choice[9]->align(FL_ALIGN_RIGHT);
      general.choice[9]->tooltip("General.FltkColorScheme");
      general.choice[9]->callback(general_options_ok_cb);

      static Fl_Menu_Item menu_color_scheme[] = {
        {"Light", 0, nullptr, nullptr},
        {"Default", 0, nullptr, nullptr},
        {"Grayscale", 0, nullptr, nullptr},
        {"Dark", 0, nullptr, nullptr},
        {nullptr}};

      general.choice[3] =
        new Fl_Choice(L + 2 * WB, 2 * WB + 2 * BH, IW, BH, "Graphics");
      general.choice[3]->tooltip(
        "Predefined color scheme of the graphics (General.ColorScheme, Alt+c)");
      general.choice[3]->menu(menu_color_scheme);
      general.choice[3]->align(FL_ALIGN_RIGHT);
      general.choice[3]->callback(general_options_color_scheme_cb);

      general.butt[13] = checkButton(L + 2 * WB, 2 * WB + 3 * BH, BW, BH,
                                     "Show tooltips and hover information box",
                                     "General.Tooltips", general_options_ok_cb);

      general.butt[23] =
        checkButton(L + 2 * WB, 2 * WB + 4 * BH, BW / 2 - WB, BH,
                    "Highlight hovered entity", "General.MouseHoverHighlight",
                    general_options_ok_cb);

      general.butt[11] =
        checkButton(L + 2 * WB + BW / 2, 2 * WB + 4 * BH, BW - BW / 2, BH,
                    "Hover mesh and views", "General.MouseHoverMeshes",
                    general_options_ok_cb);

      general.butt[6] =
        checkButton(L + 2 * WB, 2 * WB + 5 * BH, BW, BH, "Show bounding boxes",
                    "General.DrawBoundingBoxes (Alt+b)", general_options_ok_cb);

      general.butt[2] =
        checkButton(L + 2 * WB, 2 * WB + 6 * BH, BW, BH,
                    "Draw simplified model during user interaction",
                    "General.FastRedraw (Alt+f)", general_options_ok_cb,
                    (void *)"fast_redraw");

      general.butt[3] = checkButton(L + 2 * WB, 2 * WB + 7 * BH, BW, BH,
                                    "Draw with the shader pipeline",
                                    "General.Shaders", general_options_ok_cb);

      general.butt[12] =
        checkButton(L + 2 * WB, 2 * WB + 8 * BH, BW, BH, "Enable antialiasing",
                    "General.Antialiasing", general_options_ok_cb);

      general.butt[5] =
        checkButton(L + 2 * WB, 2 * WB + 9 * BH, BW, BH,
                    "Use trackball rotation instead of Euler angles",
                    "General.Trackball", general_options_ok_cb);

      general.butt[15] = checkButton(
        L + 2 * WB, 2 * WB + 10 * BH, BW, BH,
        "Rotate around pseudo center of mass", "General.RotationCenterGravity",
        general_options_ok_cb, (void *)"rotation_center");

      general.push[0] =
        new Fl_Button(L + 2 * IW - 2 * WB, 2 * WB + 11 * BH, BB, BH, "Select");
      general.push[0]->callback(general_options_rotation_center_select_cb);

      general.value[8] =
        valueInput(L + 2 * WB, 2 * WB + 11 * BH, IW / 3, BH, nullptr,
                   "General.RotationCenterX", general_options_ok_cb,
                   (void *)"rotation_center_coord");
      general.value[9] =
        valueInput(L + 2 * WB + IW / 3, 2 * WB + 11 * BH, IW / 3, BH, nullptr,
                   "General.RotationCenterY", general_options_ok_cb,
                   (void *)"rotation_center_coord");
      general.value[10] =
        valueInput(L + 2 * WB + 2 * IW / 3, 2 * WB + 11 * BH, IW / 3, BH,
                   "Rotation center", "General.RotationCenterZ",
                   general_options_ok_cb, (void *)"rotation_center_coord");
      general.value[10]->align(FL_ALIGN_RIGHT);

      general.butt[22] =
        checkButton(L + 2 * WB, 2 * WB + 12 * BH, BW, BH,
                    "Invert mouse wheel zoom direction",
                    "General.MouseInvertZoom", general_options_ok_cb);

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Advanced");

      general.butt[7] = checkButton(L + 2 * WB, 2 * WB + 1 * BH, BW, BH,
                                    "Print messages on terminal",
                                    "General.Terminal", general_options_ok_cb);

      general.value[5] =
        valueInput(L + 2 * WB, 2 * WB + 2 * BH, IW, BH, "Message verbosity",
                   "General.Verbosity", 0, 10, 1, general_options_ok_cb);
      general.value[5]->align(FL_ALIGN_RIGHT);

      general.input[1] = new Fl_Input(L + 2 * WB, 2 * WB + 3 * BH, IW, BH,
                                      "Text editor command");
      general.input[1]->tooltip("General.TextEditor");
      general.input[1]->align(FL_ALIGN_RIGHT);
      general.input[1]->callback(general_options_ok_cb);

      general.input[0] =
        new Fl_Input(L + 2 * WB, 2 * WB + 4 * BH, IW, BH, "Default file name");
      general.input[0]->tooltip("General.DefaultFileName");
      general.input[0]->align(FL_ALIGN_RIGHT);
      general.input[0]->callback(general_options_ok_cb);

      general.butt[14] =
        checkButton(L + 2 * WB, 2 * WB + 5 * BH, BW, BH,
                    "Ask confirmation before overwriting files",
                    "General.ConfirmOverwrite", general_options_ok_cb);

      general.butt[8] =
        checkButton(L + 2 * WB, 2 * WB + 6 * BH, BW - BW / 3 - WB, BH,
                    "Save session information on exit", "General.SaveSession",
                    general_options_ok_cb);

      Fl_Button *b0 =
        new Fl_Button(L + width - 2 * WB - BW / 3, 2 * WB + 6 * BH, BW / 3, BH,
                      "Show file path");
      b0->callback(options_show_file_cb, (void *)"session");

      general.butt[9] = checkButton(
        L + 2 * WB, 2 * WB + 7 * BH, BW / 2 - WB, BH, "Save options on exit",
        "General.SaveOptions", general_options_ok_cb);

      Fl_Button *b1 =
        new Fl_Button(L + width - 2 * WB - BW / 3, 2 * WB + 7 * BH, BW / 3, BH,
                      "Show file path");
      b1->callback(options_show_file_cb, (void *)"option");

      general.butt[10] =
        checkButton(L + 2 * WB, 2 * WB + 8 * BH, BW, BH, "Enable expert mode",
                    "General.ExpertMode", general_options_ok_cb);

      general.value[32] = valueInput(
        L + 2 * WB, 2 * WB + 9 * BH, IW, BH, "Maximum number of threads",
        "General.NumThreads", 0, 16, 1, general_options_ok_cb);
      general.value[32]->align(FL_ALIGN_RIGHT);
#if !defined(_OPENMP)
      general.value[32]->deactivate();
#endif

      general.butt[20] = checkButton(L + 2 * WB, 2 * WB + 10 * BH, BW, BH,
                                     "Enable heavy visualization capabilities",
                                     nullptr, general_options_ok_cb);

#if !defined(HAVE_VISUDEV)
      general.butt[20]->deactivate();
#endif

      Fl_Button *b2 = new Fl_Button(L + 2 * WB, 2 * WB + 11 * BH, BW, BH,
                                    "Restore all options to default settings");
      b2->callback(options_restore_defaults_cb);
      if(CTX::instance()->guiDark)
        b2->color(FL_DARK_RED);
      else
        b2->labelcolor(FL_DARK_RED);

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Axes");

      general.choice[4] =
        new Fl_Choice(L + 2 * WB, 2 * WB + 1 * BH, IW, BH, "Axes mode");
      general.choice[4]->tooltip("General.Axes (Alt+a)");
      general.choice[4]->menu(menu_axes_mode);
      general.choice[4]->align(FL_ALIGN_RIGHT);
      general.choice[4]->callback(general_options_ok_cb,
                                  (void *)"general_axes");

      general.butt[16] =
        checkButton(C2, 2 * WB + 1 * BH, RW, BH, "Mikado style",
                    "General.AxesMikado", general_options_ok_cb);

      general.value[17] =
        valueInput(L + 2 * WB, 2 * WB + 2 * BH, IW / 3, BH, nullptr,
                   "General.AxesTicksX", 0., 100, 1, general_options_ok_cb);
      general.value[18] = valueInput(L + 2 * WB + 1 * IW / 3, 2 * WB + 2 * BH,
                                     IW / 3, BH, nullptr, "General.AxesTicksY",
                                     0., 100, 1, general_options_ok_cb);
      general.value[19] = valueInput(
        L + 2 * WB + 2 * IW / 3, 2 * WB + 2 * BH, IW / 3, BH, "Axes ticks",
        "General.AxesTicksZ", 0., 100, 1, general_options_ok_cb);
      general.value[19]->align(FL_ALIGN_RIGHT);

      general.input[3] = new Fl_Input(L + 2 * WB, 2 * WB + 3 * BH, IW / 3, BH);
      general.input[3]->tooltip("General.AxesFormatX");
      general.input[3]->callback(general_options_ok_cb);
      general.input[4] =
        new Fl_Input(L + 2 * WB + 1 * IW / 3, 2 * WB + 3 * BH, IW / 3, BH);
      general.input[4]->callback(general_options_ok_cb);
      general.input[4]->tooltip("General.AxesFormatY");
      general.input[5] = new Fl_Input(L + 2 * WB + 2 * IW / 3, 2 * WB + 3 * BH,
                                      IW / 3, BH, "Axes format");
      general.input[5]->tooltip("General.AxesFormatZ");
      general.input[5]->align(FL_ALIGN_RIGHT);
      general.input[5]->callback(general_options_ok_cb);

      general.input[6] = new Fl_Input(L + 2 * WB, 2 * WB + 4 * BH, IW / 3, BH);
      general.input[6]->tooltip("General.AxesLabelX");
      general.input[6]->callback(general_options_ok_cb);
      general.input[7] =
        new Fl_Input(L + 2 * WB + 1 * IW / 3, 2 * WB + 4 * BH, IW / 3, BH);
      general.input[7]->tooltip("General.AxesLabelY");
      general.input[7]->callback(general_options_ok_cb);
      general.input[8] = new Fl_Input(L + 2 * WB + 2 * IW / 3, 2 * WB + 4 * BH,
                                      IW / 3, BH, "Axes labels");
      general.input[8]->tooltip("General.AxesLabelZ");
      general.input[8]->align(FL_ALIGN_RIGHT);
      general.input[8]->callback(general_options_ok_cb);

      general.butt[0] =
        checkButton(L + 2 * WB, 2 * WB + 5 * BH, BW, BH,
                    "Set position and size of axes automatically",
                    "General.AxesAutoPosition", general_options_ok_cb,
                    (void *)"general_axes_auto");

      general.value[20] =
        valueInput(L + 2 * WB, 2 * WB + 6 * BH, IW / 3, BH, nullptr,
                   "General.AxesMinX", general_options_ok_cb);
      general.value[21] =
        valueInput(L + 2 * WB + IW / 3, 2 * WB + 6 * BH, IW / 3, BH, nullptr,
                   "General.AxesMinY", general_options_ok_cb);
      general.value[22] =
        valueInput(L + 2 * WB + 2 * IW / 3, 2 * WB + 6 * BH, IW / 3, BH,
                   "Axes minimum", "General.AxesMinZ", general_options_ok_cb);
      general.value[22]->align(FL_ALIGN_RIGHT);

      general.value[23] =
        valueInput(L + 2 * WB, 2 * WB + 7 * BH, IW / 3, BH, nullptr,
                   "General.AxesMaxX", general_options_ok_cb);
      general.value[24] =
        valueInput(L + 2 * WB + IW / 3, 2 * WB + 7 * BH, IW / 3, BH, nullptr,
                   "General.AxesMaxY", general_options_ok_cb);
      general.value[25] =
        valueInput(L + 2 * WB + 2 * IW / 3, 2 * WB + 7 * BH, IW / 3, BH,
                   "Axes maximum", "General.AxesMaxZ", general_options_ok_cb);
      general.value[25]->align(FL_ALIGN_RIGHT);

      general.push[1] =
        new Fl_Button(L + 2 * WB, 2 * WB + 8 * BH, IW, BH, "Fit to visible");
      general.push[1]->callback(general_options_axes_fit_cb);

      general.butt[1] =
        checkButton(L + 2 * WB, 2 * WB + 9 * BH, BW, BH, "Show small axes",
                    "General.SmallAxes (Alt+Shift+a)", general_options_ok_cb,
                    (void *)"general_small_axes");

      general.value[26] = valueInput(L + 2 * WB, 2 * WB + 10 * BH, IW / 2, BH,
                                     nullptr, "General.SmallAxesPositionX",
                                     -2000, 2000, 1, general_options_ok_cb);
      general.value[27] =
        valueInput(L + 2 * WB + IW / 2, 2 * WB + 10 * BH, IW / 2, BH,
                   "Small axes position", "General.SmallAxesPositionY", -2000,
                   2000, 1, general_options_ok_cb);
      general.value[27]->align(FL_ALIGN_RIGHT);

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Aspect");
      o->hide();

      static Fl_Menu_Item menu_projection[] = {
        {"Orthographic", 0, nullptr, nullptr},
        {"Perspective", 0, nullptr, nullptr},
        {nullptr}};
      general.choice[2] =
        new Fl_Choice(L + 2 * WB, 2 * WB + 1 * BH, IW, BH, "Projection mode");
      general.choice[2]->tooltip("General.Orthographic (Alt+o)");
      general.choice[2]->menu(menu_projection);
      general.choice[2]->align(FL_ALIGN_RIGHT);
      general.choice[2]->callback(general_options_ok_cb);

      general.value[14] = valueInput(
        L + 2 * WB, 2 * WB + 2 * BH, IW, BH, "Z-clipping distance factor",
        "General.ClipFactor", 0.1, 20., 0.1, general_options_ok_cb);
      general.value[14]->align(FL_ALIGN_RIGHT);

      general.value[15] = valueInput(L + 2 * WB, 2 * WB + 3 * BH, IW / 2, BH,
                                     nullptr, "General.PolygonOffsetFactor", 0.,
                                     10., 0.01, general_options_ok_cb);
      general.value[15]->align(FL_ALIGN_RIGHT);

      general.value[16] =
        valueInput(L + 2 * WB + IW / 2, 2 * WB + 3 * BH, IW / 2, BH,
                   "Polygon offset factor/units", "General.PolygonOffsetUnits",
                   0., 10., 0.01, general_options_ok_cb);
      general.value[16]->align(FL_ALIGN_RIGHT);

      general.butt[4] = checkButton(
        L + 2 * WB, 2 * WB + 4 * BH, BW, BH, "Always apply polygon offset",
        "General.PolygonOffsetAlwaysOn", general_options_ok_cb);

      general.value[11] = valueInput(
        L + 2 * WB, 2 * WB + 5 * BH, IW, BH, "Quadric subdivisions",
        "General.QuadricSubdivisions", 3, 30, 1, general_options_ok_cb);
      general.value[11]->align(FL_ALIGN_RIGHT);

      general.value[6] =
        valueInput(L + 2 * WB, 2 * WB + 6 * BH, IW, BH, "Point size",
                   "General.PointSize", 0.1, 50, 0.1, general_options_ok_cb);
      general.value[6]->align(FL_ALIGN_RIGHT);

      general.value[7] =
        valueInput(L + 2 * WB, 2 * WB + 7 * BH, IW, BH, "Line width",
                   "General.LineWidth", 0.1, 50, 0.1, general_options_ok_cb);
      general.value[7]->align(FL_ALIGN_RIGHT);

      static Fl_Menu_Item menu_genvectype[] = {
        {"Line", 0, nullptr, nullptr},
        {"Arrow", 0, nullptr, nullptr},
        {"Pyramid", 0, nullptr, nullptr},
        {"3D arrow", 0, nullptr, nullptr},
        {nullptr}};
      general.choice[0] =
        new Fl_Choice(L + 2 * WB, 2 * WB + 8 * BH, IW, BH, "Vector display");
      general.choice[0]->tooltip("General.VectorType");
      general.choice[0]->menu(menu_genvectype);
      general.choice[0]->align(FL_ALIGN_RIGHT);
      general.choice[0]->callback(general_options_ok_cb);

      Fl_Button *b = new Fl_Button(L + 2 * IW - 2 * WB, 2 * WB + 8 * BH, BB, BH,
                                   "Edit arrow");
      b->callback(general_arrow_param_cb);

      static Fl_Menu_Item menu_font_engine[] = {
        {"Native", 0, nullptr, nullptr},
        {"StringTexture", 0, nullptr, nullptr},
        {"Embedded", 0, nullptr, nullptr},
        {nullptr}};
      general.choice[7] = new Fl_Choice(L + 2 * WB, 2 * WB + 9 * BH, IW, BH,
                                        "Font rendering engine");
      general.choice[7]->tooltip("General.GraphicsFontEngine");
      general.choice[7]->menu(menu_font_engine);
      general.choice[7]->align(FL_ALIGN_RIGHT);
      general.choice[7]->callback(general_options_ok_cb);

      int w1 = (int)(4. * IW / 5.), w2 = IW - w1;
      general.choice[1] = new Fl_Choice(L + 2 * WB, 2 * WB + 10 * BH, w1, BH);
      general.choice[1]->tooltip("General.GraphicsFont");
      general.choice[1]->menu(menu_font_names);
      general.choice[1]->align(FL_ALIGN_RIGHT);
      general.choice[1]->callback(general_options_ok_cb);
      general.value[12] =
        valueInput(L + 2 * WB + w1, 2 * WB + 10 * BH, w2, BH, "Default font",
                   "General.GraphicsFontSize", 5, 40, 1, general_options_ok_cb);
      general.value[12]->align(FL_ALIGN_RIGHT);

      general.choice[6] = new Fl_Choice(L + 2 * WB, 2 * WB + 11 * BH, w1, BH);
      general.choice[6]->tooltip("General.GraphicsFontTitle");
      general.choice[6]->menu(menu_font_names);
      general.choice[6]->align(FL_ALIGN_RIGHT);
      general.choice[6]->callback(general_options_ok_cb);
      general.value[28] = valueInput(
        L + 2 * WB + w1, 2 * WB + 11 * BH, w2, BH, "Title font",
        "General.GraphicsFontSizeTitle", 5, 40, 1, general_options_ok_cb);
      general.value[28]->align(FL_ALIGN_RIGHT);

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Color");
      o->hide();

      general.value[2] = valueInput(
        L + 2 * WB, 2 * WB + 1 * BH, IW / 3, BH, nullptr, "General.Light0X",
        -1., 1., 0.01, general_options_ok_cb, (void *)"light_value");

      general.value[3] =
        valueInput(L + 2 * WB + IW / 3, 2 * WB + 1 * BH, IW / 3, BH, nullptr,
                   "General.Light0Y", -1., 1., 0.01, general_options_ok_cb,
                   (void *)"light_value");

      general.value[4] =
        valueInput(L + 2 * WB + 2 * IW / 3, 2 * WB + 1 * BH, IW / 3, BH,
                   "Light position", "General.Light0Z", -1., 1., 0.01,
                   general_options_ok_cb, (void *)"light_value");
      general.value[4]->align(FL_ALIGN_RIGHT);

      general.value[13] =
        valueInput(L + 2 * WB, 2 * WB + 2 * BH, IW / 2, BH, nullptr,
                   "General.Light0W", 0., 1., 0.01, general_options_ok_cb);
      general.value[36] =
        valueInput(L + 2 * WB + IW / 2, 2 * WB + 2 * BH, IW / 2, BH,
                   "Proximity and brightness", "General.Brightness", 0, 10,
                   0.05, general_options_ok_cb);
      general.value[36]->align(FL_ALIGN_RIGHT);

      // the ball beside the two rows, after the longer of their labels
      fl_font(FL_HELVETICA, FL_NORMAL_SIZE);
      int xs = L + 2 * WB + IW + WB +
               (int)std::max(fl_width(general.value[4]->label()),
                             fl_width(general.value[36]->label()));
      int ws = std::min(2 * BH, L + width - 2 * WB - xs);
      general.sphere =
        new spherePositionWidget(L + width - 2 * WB - ws, 2 * WB + 1 * BH, ws);
      general.sphere->callback(general_options_ok_cb, (void *)"light_sphere");

      general.value[1] =
        valueInput(L + 2 * WB, 2 * WB + 3 * BH, IW / 2, BH, nullptr,
                   "General.Shininess", 0, 10, 0.1, general_options_ok_cb);
      general.value[0] = valueInput(
        L + 2 * WB + IW / 2, 2 * WB + 3 * BH, IW / 2, BH,
        "Material shininess and exponent", "General.ShininessExponent", 0, 128,
        1, general_options_ok_cb);
      general.value[0]->align(FL_ALIGN_RIGHT);

      general.choice[8] = new Fl_Choice(L + 2 * WB, 2 * WB + 4 * BH, IW, BH,
                                        "Shading mode");
      general.choice[8]->tooltip("General.Shading");
      general.choice[8]->menu(menu_shading_mode);
      general.choice[8]->align(FL_ALIGN_RIGHT);
      general.choice[8]->callback(general_options_ok_cb);

      general.value[33] =
        valueInput(L + 2 * WB, 2 * WB + 5 * BH, IW / 3, BH, nullptr,
                   "General.StudioSamples", 1, 256, 1, general_options_ok_cb);
      general.value[33]->align(FL_ALIGN_RIGHT);

      general.value[35] = valueInput(
        L + 2 * WB + IW / 3, 2 * WB + 5 * BH, IW / 3, BH, nullptr,
        "General.StudioLightSpread", 0, 90, .1, general_options_ok_cb);

      general.value[34] = valueInput(
        L + 2 * WB + 2 * IW / 3, 2 * WB + 5 * BH, IW / 3, BH,
        "Studio samples, spread, floor offset", "General.StudioFloorOffset",
        -10, 10, 0.01, general_options_ok_cb);
      general.value[34]->align(FL_ALIGN_RIGHT);

      static Fl_Menu_Item menu_bg_grad[] = {{"None", 0, nullptr, nullptr},
                                            {"Vertical", 0, nullptr, nullptr},
                                            {"Horizontal", 0, nullptr, nullptr},
                                            {"Radial", 0, nullptr, nullptr},
                                            {nullptr}};

      general.choice[5] = new Fl_Choice(L + 2 * WB, 2 * WB + 6 * BH, IW, BH,
                                        "Background gradient");
      general.choice[5]->tooltip("General.BackgroundGradient");
      general.choice[5]->menu(menu_bg_grad);
      general.choice[5]->align(FL_ALIGN_RIGHT);
      general.choice[5]->callback(general_options_ok_cb);

      std::size_t i = 0, j = 0;
      while(GeneralOptions_Color[j].str) {
        if(GeneralOptions_Color[j].level & GMSH_DEPRECATED) {
          j++;
          continue;
        }
        general.color[i] = new Fl_Button(L + 2 * WB, 3 * WB + (7 + i) * BH, IW,
                                         BH, GeneralOptions_Color[j].str);
        general.color[i]->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE |
                                FL_ALIGN_CLIP);
        general.color[i]->callback(color_cb,
                                   (void *)GeneralOptions_Color[j].function);
        i++;
        j++;
      }

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Camera");
      o->hide();

      general.butt[18] = checkButton(
        L + 2 * WB, 2 * WB + 1 * BH, BW, BH, "Enable camera", "General.Camera",
        general_options_ok_cb, (void *)"general_camera");
      general.butt[18]->value(opt_general_camera_mode(0, GMSH_GET, 0));

      general.butt[17] = checkButton(L + 2 * WB, 2 * WB + 2 * BH, BW, BH,
                                     "Enable stereo rendering",
                                     "General.Stereo", general_options_ok_cb);
      general.butt[17]->value(opt_general_stereo_mode(0, GMSH_GET, 0));

      general.value[29] = valueInput(L + 2 * WB, 2 * WB + 3 * BH, IW, BH,
                                     "Eye separation ratio (%)",
                                     "General.CameraEyeSeparationRatio", 0.1,
                                     10., .1, general_options_ok_cb);
      general.value[29]->value(CTX::instance()->eye_sep_ratio);
      general.value[29]->align(FL_ALIGN_RIGHT);

      general.value[30] = valueInput(
        L + 2 * WB, 2 * WB + 4 * BH, IW, BH, "Focal length ratio (%)",
        "General.CameraFocalLengthRatio", 0.1, 10., .1, general_options_ok_cb);
      general.value[30]->value(CTX::instance()->focallength_ratio);
      general.value[30]->align(FL_ALIGN_RIGHT);

      general.value[31] = valueInput(
        L + 2 * WB, 2 * WB + 5 * BH, IW, BH, "Camera Aperture (degrees)",
        "General.CameraAperture", 10., 120., 1, general_options_ok_cb);
      general.value[31]->value(CTX::instance()->camera_aperture);
      general.value[31]->align(FL_ALIGN_RIGHT);

      general.butt[19] = checkButton(
        L + 2 * WB, 2 * WB + 7 * BH, BW, BH, "Enable gamepad (experimental)",
        nullptr, general_options_ok_cb, (void *)"general_camera");
      general.butt[19]->value(opt_general_gamepad(0, GMSH_GET, 0));

      general.gamepadconfig =
        new Fl_Button(L + 2 * WB, 2 * WB + 8 * BH, BW, BH, "Configure Gamepad");
      general.gamepadconfig->callback(general_gmpdcf_cb);

      if(opt_general_camera_mode(0, GMSH_GET, 0) == 0) {
        general.value[30]->deactivate();
        general.value[31]->deactivate();
      }

      if(opt_general_stereo_mode(0, GMSH_GET, 0) == 0)
        general.value[29]->deactivate();

      if(CTX::instance()->gamepad && CTX::instance()->gamepad->active) {
        general.gamepadconfig->activate();
        opt_general_camera_mode(0, GMSH_SET, 1);
        general.butt[18]->value(opt_general_camera_mode(0, GMSH_GET, 0));
      }
      else {
        general.gamepadconfig->deactivate();
      }
      o->end();
    }
  }

  general.group->end();

  // Geometry options
  geo.group = new Fl_Group(L, 0, width, height, "Geometry Options");
  geo.group->hide();
  {
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "General");
      o->hide();

      geo.value[2] =
        valueInput(L + 2 * WB, 2 * WB + 1 * BH, IW, BH, "Geometry tolerance",
                   "Geometry.Tolerance", geometry_options_ok_cb);
      geo.value[2]->align(FL_ALIGN_RIGHT);

      geo.butt[8] =
        checkButton(L + 2 * WB, 2 * WB + 2 * BH, BW, BH,
                    "Remove duplicate entities in GEO model transforms",
                    "Geometry.AutoCoherence", geometry_options_ok_cb);

      Fl_Box *b = new Fl_Box(L + 2 * WB, 2 * WB + 3 * BH, BW, 2);
      b->box(FL_ENGRAVED_FRAME);
      b->labeltype(FL_NO_LABEL);

      Fl_Box *b2 = new Fl_Box(FL_NO_BOX, L + 2 * WB, 2 * WB + 3 * BH + 1, IW,
                              BH, "Open CASCADE model healing options:");
      b2->align(FL_ALIGN_INSIDE | FL_ALIGN_LEFT);

      geo.butt[16] =
        checkButton(L + 2 * WB, 2 * WB + 4 * BH, BW, BH,
                    "Remove degenerated edges and faces",
                    "Geometry.OCCFixDegenerated", geometry_options_ok_cb);

      geo.butt[11] =
        checkButton(L + 2 * WB, 2 * WB + 5 * BH, BW, BH, "Remove small edges",
                    "Geometry.OCCFixSmallEdges", geometry_options_ok_cb);

      geo.butt[12] =
        checkButton(L + 2 * WB, 2 * WB + 6 * BH, BW, BH, "Remove small faces",
                    "Geometry.OCCFixSmallFaces", geometry_options_ok_cb);

      geo.butt[13] =
        checkButton(L + 2 * WB, 2 * WB + 7 * BH, BW, BH, "Sew faces",
                    "Geometry.OCCSewFaces", geometry_options_ok_cb);

      geo.butt[14] = checkButton(
        L + 2 * WB, 2 * WB + 8 * BH, BW, BH, "Fix shells and make solids",
        "Geometry.OCCMakeSolids", geometry_options_ok_cb);

      geo.value[20] =
        valueInput(L + 2 * WB, 2 * WB + 9 * BH, IW, BH, "Global model scaling",
                   "Geometry.OCCScaling", geometry_options_ok_cb);
      geo.value[20]->align(FL_ALIGN_RIGHT);

#if !defined(HAVE_OCC)
      b2->deactivate();
      geo.butt[16]->deactivate();
      geo.butt[11]->deactivate();
      geo.butt[12]->deactivate();
      geo.butt[13]->deactivate();
      geo.butt[14]->deactivate();
      geo.value[20]->deactivate();
#endif
      o->end();
    }
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Visibility");

      geo.butt[0] =
        checkButton(L + 2 * WB, 2 * WB + 1 * BH, BW / 2 - WB, BH, "Points",
                    "Geometry.Points (Alt+p)", geometry_options_ok_cb);

      geo.butt[1] =
        checkButton(L + 2 * WB, 2 * WB + 2 * BH, BW / 2 - WB, BH, "Curves",
                    "Geometry.Curves (Alt+l)", geometry_options_ok_cb);

      geo.butt[2] =
        checkButton(L + 2 * WB, 2 * WB + 3 * BH, BW / 2 - WB, BH, "Surfaces",
                    "Geometry.Surfaces (Alt+s)", geometry_options_ok_cb);

      geo.butt[3] =
        checkButton(L + 2 * WB, 2 * WB + 4 * BH, BW / 2 - WB, BH, "Volumes",
                    "Geometry.Volumes (Alt+v)", geometry_options_ok_cb);

      geo.butt[4] = checkButton(L + width / 2, 2 * WB + 1 * BH,
                                width - width / 2 - 2 * WB, BH, "Point labels",
                                "Geometry.PointLabels", geometry_options_ok_cb);

      geo.butt[5] = checkButton(L + width / 2, 2 * WB + 2 * BH,
                                width - width / 2 - 2 * WB, BH, "Curve labels",
                                "Geometry.CurveLabels", geometry_options_ok_cb);

      geo.butt[6] = checkButton(
        L + width / 2, 2 * WB + 3 * BH, width - width / 2 - 2 * WB, BH,
        "Surface labels", "Geometry.SurfaceLabels", geometry_options_ok_cb);

      geo.butt[7] = checkButton(
        L + width / 2, 2 * WB + 4 * BH, width - width / 2 - 2 * WB, BH,
        "Volume labels", "Geometry.VolumeLabels", geometry_options_ok_cb);

      static Fl_Menu_Item menu_label_type[] = {
        {"Description", 0, nullptr, nullptr},
        {"Elementary tag", 0, nullptr, nullptr},
        {"Physical tag(s)", 0, nullptr, nullptr},
        {"Elementary name", 0, nullptr, nullptr},
        {"Physical name(s)", 0, nullptr, nullptr},
        {"Coordinates", 0, nullptr, nullptr},
        {nullptr}};
      geo.choice[4] =
        new Fl_Choice(L + 2 * WB, 2 * WB + 5 * BH, IW, BH, "Label type");
      geo.choice[4]->tooltip("Geometry.LabelType");
      geo.choice[4]->menu(menu_label_type);
      geo.choice[4]->align(FL_ALIGN_RIGHT);
      geo.choice[4]->callback(geometry_options_ok_cb);

      geo.value[0] =
        valueInput(L + 2 * WB, 2 * WB + 6 * BH, IW / 2, BH, nullptr,
                   "Geometry.Normals", 0, 500, 1, geometry_options_ok_cb);
      geo.value[0]->align(FL_ALIGN_RIGHT);
      geo.value[0]->when(FL_WHEN_RELEASE);

      geo.value[1] = valueInput(L + 2 * WB + IW / 2, 2 * WB + 6 * BH, IW / 2,
                                BH, "Normals and tangents", "Geometry.Tangents",
                                0, 500, 1, geometry_options_ok_cb);
      geo.value[1]->align(FL_ALIGN_RIGHT);
      geo.value[1]->when(FL_WHEN_RELEASE);

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Transfo");
      o->hide();

      static Fl_Menu_Item menu_transform[] = {{"None", 0, nullptr, nullptr},
                                              {"Scaling", 0, nullptr, nullptr},
                                              {nullptr}};
      geo.choice[3] = new Fl_Choice(L + 2 * WB, 2 * WB + 1 * BH, IW, BH,
                                    "Main window transform");
      geo.choice[3]->tooltip("Geometry.Transform");
      geo.choice[3]->menu(menu_transform);
      geo.choice[3]->align(FL_ALIGN_RIGHT);
      geo.choice[3]->callback(geometry_options_ok_cb, (void *)"geo_transform");

      int ss = 2 * IW / 3 / 3 + 4;
      geo.value[7] = valueInput(L + 2 * WB, 2 * WB + 2 * BH, ss, BH, nullptr,
                                "Geometry.TransformXX");
      geo.value[8] = valueInput(L + 2 * WB + ss, 2 * WB + 2 * BH, ss, BH,
                                nullptr, "Geometry.TransformXY");
      geo.value[9] = valueInput(L + 2 * WB + 2 * ss, 2 * WB + 2 * BH, ss, BH,
                                " X", "Geometry.TransformXZ");
      geo.value[10] = valueInput(L + 2 * WB + IW, 2 * WB + 2 * BH, 7 * IW / 10,
                                 BH, nullptr, "Geometry.OffsetX");

      geo.value[11] = valueInput(L + 2 * WB, 2 * WB + 3 * BH, ss, BH, nullptr,
                                 "Geometry.TransformYX");
      geo.value[12] = valueInput(L + 2 * WB + ss, 2 * WB + 3 * BH, ss, BH,
                                 nullptr, "Geometry.TransformYY");
      geo.value[13] = valueInput(L + 2 * WB + 2 * ss, 2 * WB + 3 * BH, ss, BH,
                                 " Y +", "Geometry.TransformYZ");
      geo.value[14] = valueInput(L + 2 * WB + IW, 2 * WB + 3 * BH, 7 * IW / 10,
                                 BH, nullptr, "Geometry.OffsetY");

      geo.value[15] = valueInput(L + 2 * WB, 2 * WB + 4 * BH, ss, BH, nullptr,
                                 "Geometry.TransformZX");
      geo.value[16] = valueInput(L + 2 * WB + ss, 2 * WB + 4 * BH, ss, BH,
                                 nullptr, "Geometry.TransformZY");
      geo.value[17] = valueInput(L + 2 * WB + 2 * ss, 2 * WB + 4 * BH, ss, BH,
                                 " Z", "Geometry.TransformZZ");
      geo.value[18] = valueInput(L + 2 * WB + IW, 2 * WB + 4 * BH, 7 * IW / 10,
                                 BH, nullptr, "Geometry.OffsetZ");

      for(int i = 7; i <= 18; i++) {
        geo.value[i]->minimum(-1.);
        geo.value[i]->maximum(1.);
        if(CTX::instance()->inputScrolling) geo.value[i]->step(0.1);
        geo.value[i]->align(FL_ALIGN_RIGHT);
        geo.value[i]->when(FL_WHEN_RELEASE);
        geo.value[i]->callback(geometry_options_ok_cb);
      }

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Aspect");
      o->hide();

      geo.choice[0] =
        new Fl_Choice(L + 2 * WB, 2 * WB + 1 * BH, IW, BH, "Point display");
      geo.choice[0]->tooltip("Geometry.PointType");
      geo.choice[0]->menu(menu_point_display);
      geo.choice[0]->align(FL_ALIGN_RIGHT);
      geo.choice[0]->callback(geometry_options_ok_cb);

      geo.value[3] =
        valueInput(L + 2 * WB, 2 * WB + 2 * BH, IW, BH, "Point size",
                   "Geometry.PointSize", 0.1, 50, 0.1, geometry_options_ok_cb);
      geo.value[3]->align(FL_ALIGN_RIGHT);

      geo.value[5] = valueInput(
        L + 2 * WB, 2 * WB + 3 * BH, IW, BH, "Selected point size",
        "Geometry.PointSelectSize", 0.1, 50, 0.1, geometry_options_ok_cb);
      geo.value[5]->align(FL_ALIGN_RIGHT);

      geo.choice[1] =
        new Fl_Choice(L + 2 * WB, 2 * WB + 4 * BH, IW, BH, "Curve display");
      geo.choice[1]->tooltip("Geometry.CurveType");
      geo.choice[1]->menu(menu_line_display);
      geo.choice[1]->align(FL_ALIGN_RIGHT);
      geo.choice[1]->callback(geometry_options_ok_cb);

      geo.value[4] =
        valueInput(L + 2 * WB, 2 * WB + 5 * BH, IW, BH, "Curve width",
                   "Geometry.CurveWidth", 0.1, 50, 0.1, geometry_options_ok_cb);
      geo.value[4]->align(FL_ALIGN_RIGHT);

      geo.value[6] = valueInput(
        L + 2 * WB, 2 * WB + 6 * BH, IW, BH, "Selected curve width",
        "Geometry.CurveSelectWidth", 0.1, 50, 0.1, geometry_options_ok_cb);
      geo.value[6]->align(FL_ALIGN_RIGHT);

      geo.value[19] =
        valueInput(L + 2 * WB, 2 * WB + 7 * BH, IW, BH, "Curve subdivisions",
                   "Geometry.NumSubEdges", 1, 1000, 1, geometry_options_ok_cb);
      geo.value[19]->align(FL_ALIGN_RIGHT);

      geo.choice[2] =
        new Fl_Choice(L + 2 * WB, 2 * WB + 8 * BH, IW, BH, "Surface display");
      geo.choice[2]->tooltip("Geometry.SurfaceType (Alt+d)");
      geo.choice[2]->menu(menu_surface_display);
      geo.choice[2]->align(FL_ALIGN_RIGHT);
      geo.choice[2]->callback(geometry_options_ok_cb);

      geo.choice[5] =
        new Fl_Choice(L + 2 * WB, 2 * WB + 9 * BH, IW, BH, "Volume display");
      geo.choice[5]->tooltip("Geometry.VolumeType");
      geo.choice[5]->menu(menu_volume_display);
      geo.choice[5]->align(FL_ALIGN_RIGHT);
      geo.choice[5]->callback(geometry_options_ok_cb);

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Color");
      o->hide();

      geo.butt[9] =
        checkButton(L + 2 * WB, 2 * WB + 1 * BH, BW, BH, "Enable lighting",
                    "Geometry.Light (Alt+w)", geometry_options_ok_cb);

      geo.butt[15] = checkButton(
        L + 2 * WB, 2 * WB + 2 * BH, BW, BH, "Use two-side lighting",
        "Geometry.LightTwoSide", geometry_options_ok_cb);

      geo.butt[10] =
        checkButton(L + 2 * WB, 2 * WB + 3 * BH, BW, BH,
                    "Highlight orphan and boundary entities",
                    "Geometry.HighlightOrphans", geometry_options_ok_cb);

      int w1 = (int)(3. * IW / 4.), w2 = IW - w1;
      static Fl_Menu_Item menu_transparency_mode[] = {
        {"Surfaces", 0, nullptr, nullptr},
        {"Everything", 0, nullptr, nullptr},
        {nullptr}};
      geo.value[21] =
        valueInput(L + 2 * WB, 2 * WB + 4 * BH, w2, BH, nullptr,
                   "Geometry.Opacity", 0., 1., 0.01, geometry_options_ok_cb);
      geo.value[21]->align(FL_ALIGN_RIGHT);
      geo.value[21]->when(FL_WHEN_CHANGED | FL_WHEN_RELEASE);

      geo.choice[6] = new Fl_Choice(L + 2 * WB + w2, 2 * WB + 4 * BH,
                                    w1, BH, "Opacity");
      geo.choice[6]->tooltip("Geometry.OpacityMode");
      geo.choice[6]->menu(menu_transparency_mode);
      geo.choice[6]->align(FL_ALIGN_RIGHT);
      geo.choice[6]->callback(geometry_options_ok_cb);

      std::size_t i = 0, j = 0;
      while(GeometryOptions_Color[j].str) {
        if(GeometryOptions_Color[j].level & GMSH_DEPRECATED) {
          j++;
          continue;
        }
        geo.color[i] = new Fl_Button(L + 2 * WB, 3 * WB + (5 + i) * BH, IW, BH,
                                     GeometryOptions_Color[j].str);
        geo.color[i]->callback(color_cb,
                               (void *)GeometryOptions_Color[j].function);
        i++;
        j++;
      }

      o->end();
    }
  }
  geo.group->end();

  // Mesh options
  mesh.group = new Fl_Group(L, 0, width, height, "Mesh Options");
  mesh.group->hide();
  {
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "General");
      o->hide();

      static Fl_Menu_Item menu_2d_algo[] = {
        {"Automatic", 0, nullptr, nullptr},
        {"MeshAdapt", 0, nullptr, nullptr},
        {"Delaunay", 0, nullptr, nullptr},
        {"Frontal-Delaunay", 0, nullptr, nullptr},
        {"BAMG", 0, nullptr, nullptr},
        {"Frontal-Delaunay for Quads (experimental)", 0, nullptr, nullptr},
        {"Packing of parallelograms (experimental)", 0, nullptr, nullptr},
        {"Quasi-Structured Quad (experimental)", 0, nullptr, nullptr},
        {"Initial Mesh Only", 0, nullptr, nullptr},
        {nullptr}};
      static Fl_Menu_Item menu_3d_algo[] = {
        {"Delaunay", 0, nullptr, nullptr},
        {"Parallel Delaunay", 0, nullptr, nullptr},
        {"Frontal", 0, nullptr, nullptr},
        {"HXT (experimental)", 0, nullptr, nullptr},
        {"MMG3D (experimental)", 0, nullptr, nullptr},
        {"Initial Mesh Only (no node insertion)", 0, nullptr, nullptr},
        {nullptr}};
      static Fl_Menu_Item menu_recombination_algo[] = {
        {"Simple", 0, nullptr, nullptr},
        {"Blossom", 0, nullptr, nullptr},
        {"Simple Full-Quad", 0, nullptr, nullptr},
        {"Blossom Full-Quad", 0, nullptr, nullptr},
        {"Christos's bipartite labelling", 0, nullptr, nullptr},
        {nullptr}};
      static Fl_Menu_Item menu_subdivision_algo[] = {
        {"None", 0, nullptr, nullptr},
        {"All Quads", 0, nullptr, nullptr},
        {"All Hexas", 0, nullptr, nullptr},
        {"Barycentric", 0, nullptr, nullptr},
        {nullptr}};

      mesh.choice[2] =
        new Fl_Choice(L + 2 * WB, 2 * WB + 1 * BH, IW, BH, "2D algorithm");
      mesh.choice[2]->tooltip("Mesh.Algorithm");
      mesh.choice[2]->menu(menu_2d_algo);
      mesh.choice[2]->align(FL_ALIGN_RIGHT);
      mesh.choice[2]->callback(mesh_options_ok_cb);

      mesh.choice[3] =
        new Fl_Choice(L + 2 * WB, 2 * WB + 2 * BH, IW, BH, "3D algorithm");
      mesh.choice[3]->tooltip("Mesh.Algorithm3D");
      mesh.choice[3]->menu(menu_3d_algo);
      mesh.choice[3]->align(FL_ALIGN_RIGHT);
      mesh.choice[3]->callback(mesh_options_ok_cb);

      mesh.choice[1] = new Fl_Choice(L + 2 * WB, 2 * WB + 3 * BH, IW, BH,
                                     "2D recombination algorithm");
      mesh.choice[1]->tooltip("Mesh.RecombinationAlgorithm");
      mesh.choice[1]->menu(menu_recombination_algo);
      mesh.choice[1]->align(FL_ALIGN_RIGHT);
      mesh.choice[1]->callback(mesh_options_ok_cb);

      mesh.butt[21] = checkButton(L + 2 * WB, 2 * WB + 4 * BH, BW, BH,
                                  "Recombine all triangular meshes",
                                  "Mesh.RecombineAll", mesh_options_ok_cb);

      mesh.choice[5] = new Fl_Choice(L + 2 * WB, 2 * WB + 5 * BH, IW, BH,
                                     "Subdivision algorithm");
      mesh.choice[5]->tooltip("Mesh.SubdivisionAlgorithm");
      mesh.choice[5]->menu(menu_subdivision_algo);
      mesh.choice[5]->align(FL_ALIGN_RIGHT);
      mesh.choice[5]->callback(mesh_options_ok_cb);

      mesh.value[0] =
        valueInput(L + 2 * WB, 2 * WB + 6 * BH, IW, BH, "Smoothing steps",
                   "Mesh.Smoothing", 0, 100, 1, mesh_options_ok_cb);
      mesh.value[0]->align(FL_ALIGN_RIGHT);

      mesh.value[2] = new inputValueFloat(L + 2 * WB, 2 * WB + 7 * BH, IW, BH,
                                          "Element size factor");
      mesh.value[2]->tooltip("Mesh.MeshSizeFactor");
      mesh.value[2]->minimum(0.001);
      mesh.value[2]->maximum(1000);
      if(CTX::instance()->inputScrolling) mesh.value[2]->step(0.01);
      mesh.value[2]->align(FL_ALIGN_RIGHT);
      mesh.value[2]->callback(mesh_options_ok_cb);

      mesh.value[25] =
        valueInput(L + 2 * WB, 2 * WB + 8 * BH, IW / 2, BH, nullptr,
                   "Mesh.MeshSizeMin", mesh_options_ok_cb);
      mesh.value[25]->align(FL_ALIGN_RIGHT);

      mesh.value[26] = valueInput(L + 2 * WB + IW / 2, 2 * WB + 8 * BH, IW / 2,
                                  BH, "Min/Max element size",
                                  "Mesh.MeshSizeMax", mesh_options_ok_cb);
      mesh.value[26]->align(FL_ALIGN_RIGHT);

      mesh.value[3] =
        valueInput(L + 2 * WB, 2 * WB + 9 * BH, IW / 3, BH, "Element order",
                   "Mesh.ElementOrder", 1, 2, 1, mesh_options_ok_cb);
      mesh.value[3]->align(FL_ALIGN_RIGHT);

      mesh.butt[4] =
        checkButton(L + width / 2, 2 * WB + 9 * BH, width - width / 2 - 2 * WB,
                    BH, "Incomplete elements", "Mesh.SecondOrderIncomplete",
                    mesh_options_ok_cb);

      o->end();
    }

    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Advanced");
      o->hide();

      mesh.butt[5] = checkButton(L + 2 * WB, 2 * WB + 1 * BH, BW, BH,
                                 "Compute element sizes using point values",
                                 "Mesh.MeshSizeFromPoints", mesh_options_ok_cb);

      mesh.butt[26] =
        checkButton(L + 2 * WB, 2 * WB + 2 * BH, BW, BH,
                    "Compute element sizes using parametric point values",
                    "Mesh.MeshSizeFromParametricPoints", mesh_options_ok_cb);

      mesh.value[1] =
        valueInput(L + 2 * WB, 2 * WB + 3 * BH, IW / 2, BH,
                   "Compute element sizes from curvature",
                   "Mesh.MeshSizeFromCurvature (number of elements "
                   "per 2 * Pi radians)",
                   0, 50, 1, mesh_options_ok_cb);
      mesh.value[1]->align(FL_ALIGN_RIGHT);

      mesh.butt[16] =
        checkButton(L + 2 * WB, 2 * WB + 4 * BH, BW, BH,
                    "Extend element sizes from boundary",
                    "Mesh.MeshSizeExtendFromBoundary", mesh_options_ok_cb);

      mesh.butt[2] = checkButton(L + 2 * WB, 2 * WB + 5 * BH, BW, BH,
                                 "Optimize quality of tetrahedra",
                                 "Mesh.Optimize", mesh_options_ok_cb);

      mesh.butt[24] = checkButton(L + 2 * WB, 2 * WB + 6 * BH, BW, BH,
                                  "Optimize quality of tetrahedra with Netgen",
                                  "Mesh.OptimizeNetgen");
#if !defined(HAVE_NETGEN)
      mesh.butt[24]->deactivate();
#endif
      mesh.butt[24]->callback(mesh_options_ok_cb);

      mesh.butt[3] = checkButton(L + 2 * WB, 2 * WB + 7 * BH, BW, BH,
                                 "Optimize high-order meshes",
                                 "Mesh.HighOrderOptimize", mesh_options_ok_cb);

      o->end();
    }

    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Visibility");

      mesh.butt[6] =
        checkButton(L + 2 * WB, 2 * WB + 1 * BH, BW / 2 - WB, BH, "Nodes",
                    "Mesh.Nodes (Alt+Shift+p)", mesh_options_ok_cb);

      mesh.butt[7] =
        checkButton(L + 2 * WB, 2 * WB + 2 * BH, BW / 2 - WB, BH, "1D elements",
                    "Mesh.Lines (Alt+Shift+l)", mesh_options_ok_cb);

      mesh.butt[8] = checkButton(
        L + 2 * WB, 2 * WB + 3 * BH, BW / 2 - WB, BH, "2D element edges",
        "Mesh.SurfaceEdges (Alt+Shift+s)", mesh_options_ok_cb);

      mesh.butt[9] = checkButton(
        L + 2 * WB, 2 * WB + 4 * BH, BW / 2 - WB, BH, "2D element faces",
        "Mesh.SurfaceFaces (Alt+Shift+d)", mesh_options_ok_cb);

      mesh.butt[10] = checkButton(
        L + 2 * WB, 2 * WB + 5 * BH, BW / 2 - WB, BH, "3D element edges",
        "Mesh.VolumeEdges (Alt+Shift+v)", mesh_options_ok_cb);

      mesh.butt[11] = checkButton(
        L + 2 * WB, 2 * WB + 6 * BH, BW / 2 - WB, BH, "3D element faces",
        "Mesh.VolumeFaces (Alt+Shift+b)", mesh_options_ok_cb);

      mesh.butt[1] = checkButton(
        L + width / 2, 2 * WB + 5 * BH, width - width / 2 - 2 * WB, BH,
        "Hide interior edges", "Mesh.DrawSkinEdgesOnly", mesh_options_ok_cb);

      static Fl_Menu_Item menu_skin[] = {
        {"Show interior faces", 0, nullptr, nullptr},
        {"Hide interior faces", 0, nullptr, nullptr},
        {"Hide partition faces", 0, nullptr, nullptr},
        {nullptr}};
      mesh.choice[12] = new Fl_Choice(L + width / 2, 2 * WB + 6 * BH,
                                      width - width / 2 - 2 * WB, BH);
      mesh.choice[12]->menu(menu_skin);
      mesh.choice[12]->tooltip("Mesh.DrawSkinOnly");
      mesh.choice[12]->callback(mesh_options_ok_cb);

      mesh.butt[12] =
        checkButton(L + width / 2, 2 * WB + 1 * BH, width - width / 2 - 2 * WB,
                    BH, "Node labels", "Mesh.NodeLabels", mesh_options_ok_cb);

      mesh.butt[13] = checkButton(
        L + width / 2, 2 * WB + 2 * BH, width - width / 2 - 2 * WB, BH,
        "1D element labels", "Mesh.LineLabels", mesh_options_ok_cb);

      mesh.butt[14] = checkButton(
        L + width / 2, 2 * WB + 3 * BH, width - width / 2 - 2 * WB, BH,
        "2D element labels", "Mesh.SurfaceLabels", mesh_options_ok_cb);

      mesh.butt[15] = checkButton(
        L + width / 2, 2 * WB + 4 * BH, width - width / 2 - 2 * WB, BH,
        "3D element labels", "Mesh.VolumeLabels", mesh_options_ok_cb);

      static Fl_Menu_Item menu_label_type[] = {
        {"Node/element tag", 0, nullptr, nullptr},
        {"Elementary entity tag", 0, nullptr, nullptr},
        {"Physical group tag(s)", 0, nullptr, nullptr},
        {"Mesh partition", 0, nullptr, nullptr},
        {"Coordinates", 0, nullptr, nullptr},
        {nullptr}};
      mesh.choice[7] =
        new Fl_Choice(L + 2 * WB, 2 * WB + 7 * BH, IW, BH, "Label");
      mesh.choice[7]->tooltip("Mesh.LabelType");
      mesh.choice[7]->menu(menu_label_type);
      mesh.choice[7]->align(FL_ALIGN_RIGHT);
      mesh.choice[7]->callback(mesh_options_ok_cb);

      mesh.value[12] =
        valueInput(L + width / 2, 2 * WB + 7 * BH, IW / 2, BH, "Sampling",
                   "Mesh.LabelSampling", 1, 100, 1, mesh_options_ok_cb);
      mesh.value[12]->align(FL_ALIGN_RIGHT);
      mesh.value[12]->when(FL_WHEN_RELEASE);

      static Fl_Menu_Item menu_mesh_element_types[] = {
        {"Triangles", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Quadrangles", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Tetrahedra", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Hexahedra", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Prisms", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Pyramids", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Trihedra", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Polygons", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Polyhedra", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {nullptr}};

      mesh.menu =
        new Fl_Menu_Button(L + 2 * WB, 2 * WB + 8 * BH, IW, BH, "Elements");
      mesh.menu->tooltip(
        "Mesh.Triangles, Mesh.Quadrangles, Mesh.Tetrahedra, "
        "Mesh.Hexahedra, Mesh.Prisms, Mesh.Pyramids, Mesh.Trihedra, "
        "Mesh.Polygons, Mesh.Polyhedra");
      mesh.menu->menu(menu_mesh_element_types);
      mesh.menu->callback(mesh_options_ok_cb);

      mesh.value[4] =
        valueInput(L + 2 * WB, 2 * WB + 9 * BH, IW / 4, BH, nullptr,
                   "Mesh.QualityInf", 0, 1, 0.01, mesh_options_ok_cb);
      mesh.value[4]->align(FL_ALIGN_RIGHT);
      mesh.value[4]->when(FL_WHEN_RELEASE);

      mesh.value[5] =
        valueInput(L + 2 * WB + IW / 4, 2 * WB + 9 * BH, IW / 2 - IW / 4, BH,
                   nullptr, "Mesh.QualitySup", 0, 1, 0.01, mesh_options_ok_cb);
      mesh.value[5]->align(FL_ALIGN_RIGHT);
      mesh.value[5]->when(FL_WHEN_RELEASE);

      static Fl_Menu_Item menu_quality_type[] = {{"SICN", 0, nullptr, nullptr},
                                                 {"SIGE", 0, nullptr, nullptr},
                                                 {"Gamma", 0, nullptr, nullptr},
                                                 {"Disto", 0, nullptr, nullptr},
                                                 {nullptr}};
      mesh.choice[6] = new Fl_Choice(L + 2 * WB + IW / 2, 2 * WB + 9 * BH,
                                     IW / 2, BH, "Quality range");
      mesh.choice[6]->tooltip("Mesh.QualityType");
      mesh.choice[6]->menu(menu_quality_type);
      mesh.choice[6]->align(FL_ALIGN_RIGHT);
      mesh.choice[6]->callback(mesh_options_ok_cb);

      mesh.value[6] = valueInput(L + 2 * WB, 2 * WB + 10 * BH, IW / 2, BH,
                                 nullptr, "Mesh.RadiusInf", mesh_options_ok_cb);
      mesh.value[6]->align(FL_ALIGN_RIGHT);
      mesh.value[6]->when(FL_WHEN_RELEASE);

      mesh.value[7] =
        valueInput(L + 2 * WB + IW / 2, 2 * WB + 10 * BH, IW / 2, BH,
                   "Size range", "Mesh.RadiusSup", mesh_options_ok_cb);
      mesh.value[7]->align(FL_ALIGN_RIGHT);
      mesh.value[7]->when(FL_WHEN_RELEASE);

      mesh.value[8] =
        valueInput(L + 2 * WB, 2 * WB + 11 * BH, IW / 2, BH, nullptr,
                   "Mesh.Normals", 0, 500, 1, mesh_options_ok_cb);
      mesh.value[8]->align(FL_ALIGN_RIGHT);
      mesh.value[8]->when(FL_WHEN_RELEASE);

      mesh.value[13] = valueInput(L + 2 * WB + IW / 2, 2 * WB + 11 * BH, IW / 2,
                                  BH, "Normals and tangents", "Mesh.Tangents",
                                  0, 200, 1.0, mesh_options_ok_cb);
      mesh.value[13]->align(FL_ALIGN_RIGHT);
      mesh.value[13]->when(FL_WHEN_RELEASE);

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Aspect");
      o->hide();

      mesh.value[9] = valueInput(L + 2 * WB, 2 * WB + 1 * BH, IW, BH,
                                 "Element shrinking factor", "Mesh.Explode", 0,
                                 1, 0.01, mesh_options_ok_cb);
      mesh.value[9]->align(FL_ALIGN_RIGHT);
      mesh.value[9]->when(FL_WHEN_RELEASE);

      mesh.choice[0] =
        new Fl_Choice(L + 2 * WB, 2 * WB + 2 * BH, IW, BH, "Point display");
      mesh.choice[0]->tooltip("Mesh.PointType");
      mesh.choice[0]->menu(menu_point_display);
      mesh.choice[0]->align(FL_ALIGN_RIGHT);
      mesh.choice[0]->callback(mesh_options_ok_cb);

      mesh.value[10] =
        valueInput(L + 2 * WB, 2 * WB + 3 * BH, IW, BH, "Point size",
                   "Mesh.PointSize", 0.1, 50, 0.1, mesh_options_ok_cb);
      mesh.value[10]->align(FL_ALIGN_RIGHT);

      mesh.value[11] =
        valueInput(L + 2 * WB, 2 * WB + 4 * BH, IW, BH, "Line width",
                   "Mesh.LineWidth", 0.1, 50, 0.1, mesh_options_ok_cb);
      mesh.value[11]->align(FL_ALIGN_RIGHT);

      mesh.value[14] = valueInput(
        L + 2 * WB, 2 * WB + 5 * BH, IW, BH, "High-order element subdivisions",
        "Mesh.NumSubEdges", 1, 10, 1, mesh_options_ok_cb);
      mesh.value[14]->align(FL_ALIGN_RIGHT);
      mesh.value[14]->when(FL_WHEN_RELEASE);

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Color");
      o->hide();

      mesh.butt[17] = checkButton(L + 2 * WB, 2 * WB + 1 * BH, BW, BH,
                                  "Enable lighting", "Mesh.Light (Alt+w)",
                                  mesh_options_ok_cb, (void *)"mesh_light");

      static Fl_Menu_Item menu_mesh_light_lines[] = {
        {"No", 0, nullptr, nullptr},
        {"Surface", 0, nullptr, nullptr},
        {"Volume and surface", 0, nullptr, nullptr},
        {nullptr}};
      mesh.choice[10] =
        new Fl_Choice(L + 2 * WB, 2 * WB + 2 * BH, IW, BH, "Edge lighting");
      mesh.choice[10]->tooltip("Mesh.LightLines");
      mesh.choice[10]->menu(menu_mesh_light_lines);
      mesh.choice[10]->align(FL_ALIGN_RIGHT);
      mesh.choice[10]->callback(mesh_options_ok_cb);

      mesh.butt[18] = checkButton(L + 2 * WB, 2 * WB + 3 * BH, BW, BH,
                                  "Use two-side lighting", "Mesh.LightTwoSide",
                                  mesh_options_ok_cb);

      mesh.butt[19] =
        checkButton(L + 2 * WB, 2 * WB + 4 * BH, BW, BH, "Smooth normals",
                    "Mesh.SmoothNormals", mesh_options_ok_cb);

      mesh.value[18] = valueInput(
        L + 2 * WB, 2 * WB + 5 * BH, IW, BH, "Smoothing threshold angle",
        "Mesh.AngleSmoothNormals", 0., 180., 1., mesh_options_ok_cb);
      mesh.value[18]->align(FL_ALIGN_RIGHT);
      mesh.value[18]->when(FL_WHEN_RELEASE);

      int w1 = (int)(3. * IW / 4.), w2 = IW - w1;
      static Fl_Menu_Item menu_transparency_mode[] = {
        {"Surfaces", 0, nullptr, nullptr},
        {"Everything", 0, nullptr, nullptr},
        {nullptr}};
      mesh.value[27] =
        valueInput(L + 2 * WB, 2 * WB + 6 * BH, w2, BH, nullptr, "Mesh.Opacity",
                   0., 1., 0.01, mesh_options_ok_cb);
      mesh.value[27]->align(FL_ALIGN_RIGHT);
      mesh.value[27]->when(FL_WHEN_CHANGED | FL_WHEN_RELEASE);

      mesh.choice[11] = new Fl_Choice(L + 2 * WB + w2, 2 * WB + 6 * BH,
                                      w1, BH, "Opacity");
      mesh.choice[11]->tooltip("Mesh.OpacityMode");
      mesh.choice[11]->menu(menu_transparency_mode);
      mesh.choice[11]->align(FL_ALIGN_RIGHT);
      mesh.choice[11]->callback(mesh_options_ok_cb);

      static Fl_Menu_Item menu_mesh_color[] = {
        {"By element type", 0, nullptr, nullptr},
        {"By elementary entity", 0, nullptr, nullptr},
        {"By physical group", 0, nullptr, nullptr},
        {"By mesh partition", 0, nullptr, nullptr},
        {nullptr}};
      mesh.choice[4] =
        new Fl_Choice(L + 2 * WB, 2 * WB + 7 * BH, IW, BH, "Coloring mode");
      mesh.choice[4]->tooltip("Mesh.ColorCarousel");
      mesh.choice[4]->menu(menu_mesh_color);
      mesh.choice[4]->align(FL_ALIGN_RIGHT);
      mesh.choice[4]->callback(mesh_options_ok_cb);

      std::size_t i = 0, j = 0;
      while(MeshOptions_Color[j].str) {
        if(MeshOptions_Color[j].level & GMSH_DEPRECATED) {
          j++;
          continue;
        }
        mesh.color[i] = new Fl_Button(L + 2 * WB, 3 * WB + (8 + i) * BH, IW, BH,
                                      MeshOptions_Color[j].str);
        mesh.color[i]->callback(color_cb,
                                (void *)MeshOptions_Color[j].function);
        i++;
        j++;
      }

      o->end();
    }
  }
  mesh.group->end();

  // Solver options
  solver.group = new Fl_Group(L, 0, width, height, "Solver Options");
  solver.group->hide();
  {
    {
      {
        Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                   height - 2 * WB - BH, "General");

        solver.input[0] =
          new Fl_Input(L + 2 * WB, 2 * WB + 1 * BH, IW, BH, "Base socket name");
        solver.input[0]->tooltip("Solver.SocketName");
        solver.input[0]->align(FL_ALIGN_RIGHT);
        solver.input[0]->callback(solver_options_ok_cb);

        solver.value[0] = valueInput(L + 2 * WB, 2 * WB + 2 * BH, IW, BH,
                                     "Timeout (in seconds)", "Solver.Timeout",
                                     solver_options_ok_cb);
        solver.value[0]->align(FL_ALIGN_RIGHT);

        solver.butt[0] =
          checkButton(L + 2 * WB, 2 * WB + 3 * BH, BW, BH,
                      "Always listen to incoming connection requests",
                      "Solver.AlwaysListen", solver_options_ok_cb);

        solver.input[1] = new Fl_Input(L + 2 * WB, 2 * WB + 4 * BH, IW, BH,
                                       "Python interpreter");
        solver.input[1]->tooltip("Solver.PythonInterpreter");
        solver.input[1]->align(FL_ALIGN_RIGHT);
        solver.input[1]->callback(solver_options_ok_cb);

        solver.input[2] = new Fl_Input(L + 2 * WB, 2 * WB + 5 * BH, IW, BH,
                                       "Octave interpreter");
        solver.input[2]->tooltip("Solver.OctaveInterpreter");
        solver.input[2]->align(FL_ALIGN_RIGHT);
        solver.input[2]->callback(solver_options_ok_cb);

        o->end();
      }
    }
  }
  solver.group->end();

  // Post-processing options
  post.group = new Fl_Group(L, 0, width, height, "Post-processing Options");
  post.group->hide();
  {
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "General");

      static Fl_Menu_Item menu_links[] = {
        {"Apply next changes to selected views", 0, nullptr, nullptr},
        {"Force same options for selected views", 0, nullptr, nullptr},
        {nullptr}};

      post.choice[0] =
        new Fl_Choice(L + 2 * WB, 2 * WB + 1 * BH, IW, BH, "View links");
      post.choice[0]->tooltip("PostProcessing.Link");
      post.choice[0]->menu(menu_links);
      post.choice[0]->align(FL_ALIGN_RIGHT);
      post.choice[0]->callback(post_options_ok_cb);

      post.value[0] = valueInput(
        L + 2 * WB, 2 * WB + 2 * BH, IW, BH, "Frame duration (in seconds)",
        "PostProcessing.AnimationDelay", 0, 10, 0.01, post_options_ok_cb);
      post.value[0]->align(FL_ALIGN_RIGHT);

      post.value[1] = valueInput(
        L + 2 * WB, 2 * WB + 3 * BH, IW, BH, "Animation increment step",
        "PostProcessing.AnimationStep", 1, 100, 1, post_options_ok_cb);
      post.value[1]->align(FL_ALIGN_RIGHT);

      post.butt[0] =
        checkButton(L + 2 * WB, 2 * WB + 4 * BH, BW, BH,
                    "Cycle through views instead of steps",
                    "PostProcessing.AnimationCycle", post_options_ok_cb);

      post.butt[1] =
        checkButton(L + 2 * WB, 2 * WB + 5 * BH, BW, BH,
                    "Remove original views after combination",
                    "PostProcessing.CombineRemoveOriginal", post_options_ok_cb);

      post.butt[2] = checkButton(
        L + 2 * WB, 2 * WB + 6 * BH, BW, BH, "Draw value scales horizontally",
        "PostProcessing.HorizontalScales", post_options_ok_cb);

      o->end();
    }
  }
  post.group->end();

  // View options
  view.index = -1;
  view.group = new Fl_Group(L, 0, width, height, "View Options");
  view.group->hide();
  {
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "General");

      static Fl_Menu_Item menu_plot_type[] = {{"3D", 0, nullptr, nullptr},
                                              {"2D space", 0, nullptr, nullptr},
                                              {"2D time", 0, nullptr, nullptr},
                                              {"2D", 0, nullptr, nullptr},
                                              {nullptr}};
      view.choice[13] =
        new Fl_Choice(L + 2 * WB, 2 * WB + 1 * BH, IW, BH, "Plot type");
      view.choice[13]->tooltip("View.Type");
      view.choice[13]->menu(menu_plot_type);
      view.choice[13]->align(FL_ALIGN_RIGHT);
      view.choice[13]->callback(view_options_ok_cb);

      view.input[0] =
        new Fl_Input(L + 2 * WB, 2 * WB + 2 * BH, IW, BH, "View name");
      view.input[0]->tooltip("View.Name");
      view.input[0]->align(FL_ALIGN_RIGHT);
      view.input[0]->callback(view_options_ok_cb);

      int sw = (int)(1.5 * FL_NORMAL_SIZE);
      view.push[3] = new Fl_Button(L + 2 * WB, 2 * WB + 3 * BH, sw, BH, "-");
      view.push[3]->callback(view_options_timestep_cb, (void *)"-");
      view.push[4] =
        new Fl_Button(L + 2 * WB + IW - sw, 2 * WB + 3 * BH, sw, BH, "+");
      view.push[4]->callback(view_options_timestep_cb, (void *)"+");
      view.value[50] = valueInput(L + 2 * WB + sw, 2 * WB + 3 * BH, IW - 2 * sw,
                                  BH, nullptr, "View.TimeStep", 0, 0, 1,
                                  view_options_timestep_cb, (void *)"=");
      view.value[50]->align(FL_ALIGN_RIGHT);
      view.label[0] =
        new Fl_Box(L + 2 * WB + IW, 2 * WB + 3 * BH, width / 2, BH, "Step");
      view.label[0]->box(FL_NO_BOX);
      view.label[0]->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);

      view.range =
        new Fl_Group(L + 2 * WB, 2 * WB + 4 * BH, width - 4 * WB, 8 * BH);

      view.value[30] =
        valueInput(L + 2 * WB, 2 * WB + 4 * BH, IW, BH, "Intervals",
                   "View.NbIso", 1, 256, 1, view_options_ok_cb);
      view.value[30]->align(FL_ALIGN_RIGHT);
      view.value[30]->when(FL_WHEN_RELEASE);

      view.input[1] = new Fl_Input(C2, 2 * WB + 4 * BH, RW / 2, BH, "Format");
      view.input[1]->tooltip("View.Format");
      view.input[1]->align(FL_ALIGN_RIGHT);
      view.input[1]->callback(view_options_ok_cb);

      static Fl_Menu_Item menu_iso[] = {
        {"Iso-values", 0, nullptr, nullptr},
        {"Continuous map", 0, nullptr, nullptr},
        {"Filled iso-values", 0, nullptr, nullptr},
        {"Numeric values", 0, nullptr, nullptr},
        {nullptr}};
      view.choice[0] =
        new Fl_Choice(L + 2 * WB, 2 * WB + 5 * BH, IW, BH, "Intervals type");
      view.choice[0]->tooltip("View.IntervalsType (Alt+t)");
      view.choice[0]->menu(menu_iso);
      view.choice[0]->align(FL_ALIGN_RIGHT);
      view.choice[0]->callback(view_options_ok_cb);

      static Fl_Menu_Item menu_scale[] = {
        {"Linear", 0, nullptr, nullptr},
        {"Logarithmic", 0, nullptr, nullptr},
        {"Symmetric log", 0, nullptr, nullptr},
        {nullptr}};
      view.choice[1] = new Fl_Choice(C2, 2 * WB + 5 * BH, RW, BH);
      view.choice[1]->tooltip("View.ScaleType");
      view.choice[1]->menu(menu_scale);
      view.choice[1]->align(FL_ALIGN_RIGHT);
      view.choice[1]->callback(view_options_ok_cb);

      static Fl_Menu_Item menu_range[] = {{"Default", 0, nullptr, nullptr},
                                          {"Custom", 0, nullptr, nullptr},
                                          {"Per step", 0, nullptr, nullptr},
                                          {nullptr}};
      view.choice[7] =
        new Fl_Choice(L + 2 * WB, 2 * WB + 6 * BH, IW, BH, "Range mode");
      view.choice[7]->tooltip("View.RangeType (Alt+r)");
      view.choice[7]->menu(menu_range);
      view.choice[7]->align(FL_ALIGN_RIGHT);
      view.choice[7]->callback(view_options_ok_cb, (void *)"custom_range");

      view.butt[38] = checkButton(C2, 2 * WB + 6 * BH, RW, BH, "Saturate",
                                  "View.SaturateValues", view_options_ok_cb);

      int sw2 = (int)(2.5 * FL_NORMAL_SIZE);
      view.push[1] = new Fl_Button(L + 2 * WB, 2 * WB + 7 * BH, sw2, BH, "Min");
      view.push[1]->callback(view_options_ok_cb, (void *)"range_min");
      view.value[31] =
        valueInput(L + 2 * WB + sw2, 2 * WB + 7 * BH, IW - sw2, BH,
                   "Custom min", "View.CustomMin", view_options_ok_cb);
      view.value[31]->align(FL_ALIGN_RIGHT);
      view.value[31]->when(FL_WHEN_RELEASE);

      view.value[35] = valueInput(C2, 2 * WB + 7 * BH, RW / 2, BH, "Threshold",
                                  "View.ScaleThreshold", view_options_ok_cb);
      view.value[35]->align(FL_ALIGN_RIGHT);
      view.value[35]->when(FL_WHEN_RELEASE);

      view.push[2] = new Fl_Button(L + 2 * WB, 2 * WB + 8 * BH, sw2, BH, "Max");
      view.push[2]->callback(view_options_ok_cb, (void *)"range_max");
      view.value[32] =
        valueInput(L + 2 * WB + sw2, 2 * WB + 8 * BH, IW - sw2, BH,
                   "Custom max", "View.CustomMax", view_options_ok_cb);
      view.value[32]->align(FL_ALIGN_RIGHT);
      view.value[32]->when(FL_WHEN_RELEASE);

      view.butt[0] =
        checkButton(L + 2 * WB, 2 * WB + 9 * BH, C2 - L - 3 * WB, BH,
                    "Adapt visualization grid", "View.AdaptVisualizationGrid",
                    view_options_ok_cb, (void *)"view_adaptive");

      static Fl_Menu_Item menu_adapt_skin[] = {
        {"Adapt everything", 0, nullptr, nullptr},
        {"Adapt skin only", 0, nullptr, nullptr},
        {"Skin w/o partitions", 0, nullptr, nullptr},
        {nullptr}};
      view.choice[18] = new Fl_Choice(C2, 2 * WB + 9 * BH, RW, BH);
      view.choice[18]->menu(menu_adapt_skin);
      view.choice[18]->tooltip("View.AdaptSkinOnly");
      view.choice[18]->callback(view_options_ok_cb);

      view.push[5] = new Fl_Button(L + 2 * WB, 2 * WB + 10 * BH, sw, BH, "-");
      view.push[5]->callback(view_options_max_recursion_cb, (void *)"-");
      view.push[6] =
        new Fl_Button(L + 2 * WB + IW - sw, 2 * WB + 10 * BH, sw, BH, "+");
      view.push[6]->callback(view_options_max_recursion_cb, (void *)"+");
      view.value[33] =
        valueInput(L + 2 * WB + sw, 2 * WB + 10 * BH, IW - 2 * sw, BH, nullptr,
                   "View.MaxRecursionLevel", 0, 6, 1, view_options_ok_cb);
      view.value[33]->align(FL_ALIGN_RIGHT);
      view.value[33]->when(FL_WHEN_RELEASE);
      view.label[1] = new Fl_Box(L + 2 * WB + IW, 2 * WB + 10 * BH, width / 2,
                                 BH, "Maximum recursion level");
      view.label[1]->box(FL_NO_BOX);
      view.label[1]->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);

      // (shown as it is set, e.g. 1e-6, whatever the step of the scrolling)
      view.value[34] = new inputValueFloat(L + 2 * WB, 2 * WB + 11 * BH, IW, BH,
                                           "Target visualization error");
      view.value[34]->tooltip("View.TargetError");
      view.value[34]->align(FL_ALIGN_RIGHT);
      // (a fraction of the range of the view; negative: refine everything)
      view.value[34]->minimum(-1.e-4);
      view.value[34]->maximum(1e-1);
      if(CTX::instance()->inputScrolling) view.value[34]->step(1.e-4);
      view.value[34]->when(FL_WHEN_RELEASE);
      view.value[34]->callback(view_options_ok_cb);

      view.range->end();

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Axes");
      o->hide();

      view.choice[8] =
        new Fl_Choice(L + 2 * WB, 2 * WB + 1 * BH, IW, BH, "Axes mode");
      view.choice[8]->tooltip("View.Axes (Alt+a)");
      view.choice[8]->menu(menu_axes_mode);
      view.choice[8]->align(FL_ALIGN_RIGHT);
      view.choice[8]->callback(view_options_ok_cb, (void *)"view_axes");

      view.butt[3] = checkButton(C2, 2 * WB + 1 * BH, RW, BH, "Mikado style",
                                 "View.AxesMikado", view_options_ok_cb);

      view.value[3] =
        valueInput(L + 2 * WB, 2 * WB + 2 * BH, IW / 3, BH, nullptr,
                   "View.AxesTicksX", 0., 100, 1, view_options_ok_cb);
      view.value[4] =
        valueInput(L + 2 * WB + 1 * IW / 3, 2 * WB + 2 * BH, IW / 3, BH,
                   nullptr, "View.AxesTicksY", 0., 100, 1, view_options_ok_cb);
      view.value[5] = valueInput(L + 2 * WB + 2 * IW / 3, 2 * WB + 2 * BH,
                                 IW / 3, BH, "Axes ticks", "View.AxesTicksZ",
                                 0., 100, 1, view_options_ok_cb);
      view.value[5]->align(FL_ALIGN_RIGHT);

      view.input[7] = new Fl_Input(L + 2 * WB, 2 * WB + 3 * BH, IW / 3, BH);
      view.input[7]->tooltip("View.AxesFormatX");
      view.input[7]->callback(view_options_ok_cb);
      view.input[8] =
        new Fl_Input(L + 2 * WB + 1 * IW / 3, 2 * WB + 3 * BH, IW / 3, BH);
      view.input[8]->tooltip("View.AxesFormatY");
      view.input[8]->callback(view_options_ok_cb);
      view.input[9] = new Fl_Input(L + 2 * WB + 2 * IW / 3, 2 * WB + 3 * BH,
                                   IW / 3, BH, "Axes format");
      view.input[9]->tooltip("View.AxesFormatZ");
      view.input[9]->align(FL_ALIGN_RIGHT);
      view.input[9]->callback(view_options_ok_cb);

      view.input[10] = new Fl_Input(L + 2 * WB, 2 * WB + 4 * BH, IW / 3, BH);
      view.input[10]->tooltip("View.AxesLabelX");
      view.input[10]->callback(view_options_ok_cb);
      view.input[11] =
        new Fl_Input(L + 2 * WB + 1 * IW / 3, 2 * WB + 4 * BH, IW / 3, BH);
      view.input[11]->tooltip("View.AxesLabelY");
      view.input[11]->callback(view_options_ok_cb);
      view.input[12] = new Fl_Input(L + 2 * WB + 2 * IW / 3, 2 * WB + 4 * BH,
                                    IW / 3, BH, "Axes labels");
      view.input[12]->tooltip("View.AxesLabelZ");
      view.input[12]->align(FL_ALIGN_RIGHT);
      view.input[12]->callback(view_options_ok_cb);

      view.butt[25] =
        checkButton(L + 2 * WB, 2 * WB + 5 * BH, BW, BH,
                    "Position 3D axes automatically", "View.AxesAutoPosition",
                    view_options_ok_cb, (void *)"view_axes_auto_3d");

      view.value[13] = valueInput(L + 2 * WB, 2 * WB + 6 * BH, IW / 3, BH,
                                  nullptr, "View.AxesMinX", view_options_ok_cb);
      view.value[14] =
        valueInput(L + 2 * WB + IW / 3, 2 * WB + 6 * BH, IW / 3, BH, nullptr,
                   "View.AxesMinY", view_options_ok_cb);
      view.value[15] =
        valueInput(L + 2 * WB + 2 * IW / 3, 2 * WB + 6 * BH, IW / 3, BH,
                   "3D axes minimum", "View.AxesMinZ", view_options_ok_cb);
      view.value[15]->align(FL_ALIGN_RIGHT);

      view.value[16] = valueInput(L + 2 * WB, 2 * WB + 7 * BH, IW / 3, BH,
                                  nullptr, "View.AxesMaxX", view_options_ok_cb);
      view.value[17] =
        valueInput(L + 2 * WB + IW / 3, 2 * WB + 7 * BH, IW / 3, BH, nullptr,
                   "View.AxesMaxY", view_options_ok_cb);
      view.value[18] =
        valueInput(L + 2 * WB + 2 * IW / 3, 2 * WB + 7 * BH, IW / 3, BH,
                   "3D axes maximum", "View.AxesMaxZ", view_options_ok_cb);
      view.value[18]->align(FL_ALIGN_RIGHT);

      view.choice[16] = new Fl_Choice(L + 2 * WB, 2 * WB + 8 * BH, IW, BH,
                                      "2D axes/value scale position");
      view.choice[16]->tooltip("View.AutoPosition");
      view.choice[16]->menu(menu_position);
      view.choice[16]->align(FL_ALIGN_RIGHT);
      view.choice[16]->callback(view_options_ok_cb,
                                (void *)"view_axes_auto_2d");

      view.value[20] =
        valueInput(L + 2 * WB, 2 * WB + 9 * BH, IW / 2, BH, nullptr,
                   "View.PositionX", -2000, 2000, 0.5, view_options_ok_cb);
      view.value[21] =
        valueInput(L + 2 * WB + IW / 2, 2 * WB + 9 * BH, IW / 2, BH,
                   "2D axes/value scale position", "View.PositionY", -2000,
                   2000, 0.5, view_options_ok_cb);
      view.value[21]->align(FL_ALIGN_RIGHT);

      view.value[22] =
        valueInput(L + 2 * WB, 2 * WB + 10 * BH, IW / 2, BH, nullptr,
                   "View.Width", 0, 2000, 0.5, view_options_ok_cb);
      view.value[23] = valueInput(L + 2 * WB + IW / 2, 2 * WB + 10 * BH, IW / 2,
                                  BH, "2D axes/value scale size", "View.Height",
                                  0, 2000, 0.5, view_options_ok_cb);
      view.value[23]->align(FL_ALIGN_RIGHT);

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Visibility");
      o->hide();

      view.butt[4] =
        checkButton(L + 2 * WB, 2 * WB + 1 * BH, BW, BH, "Show value scale",
                    "View.ShowScale (Alt+i)", view_options_ok_cb);

      static Fl_Menu_Item time_display[] = {
        {"None", 0, nullptr, nullptr},
        {"Time series", 0, nullptr, nullptr},
        {"Harmonic data", 0, nullptr, nullptr},
        {"Automatic", 0, nullptr, nullptr},
        {"Step data", 0, nullptr, nullptr},
        {"Multi-step data", 0, nullptr, nullptr},
        {"Real eigenvalues", 0, nullptr, nullptr},
        {"Complex eigenvalues", 0, nullptr, nullptr},
        {nullptr}};
      view.choice[12] =
        new Fl_Choice(L + 2 * WB, 2 * WB + 2 * BH, IW, BH, "Time display");
      view.choice[12]->tooltip("View.ShowTime");
      view.choice[12]->menu(time_display);
      view.choice[12]->align(FL_ALIGN_RIGHT);
      view.choice[12]->callback(view_options_ok_cb);

      view.butt[5] =
        checkButton(L + 2 * WB, 2 * WB + 3 * BH, BW, BH, "Show annotations",
                    "View.DrawStrings (Alt+n)", view_options_ok_cb);

      view.butt[10] = checkButton(
        L + 2 * WB, 2 * WB + 4 * BH, BW / 2 - WB, BH, "Draw element outlines",
        "View.ShowElement (Alt+e)", view_options_ok_cb);

      view.butt[1] = checkButton(
        L + width / 2, 2 * WB + 4 * BH, width - width / 2 - 2 * WB, BH,
        "Hide interior edges", "View.DrawSkinEdgesOnly", view_options_ok_cb);

      view.butt[2] = checkButton(
        L + width / 2, 2 * WB + 5 * BH, width - width / 2 - 2 * WB, BH,
        "Hide interior faces", "View.DrawSkinOnly", view_options_ok_cb);

      static Fl_Menu_Item menu_view_element_types[] = {
        {"Points", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Lines", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Triangles", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Quadrangles", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Tetrahedra", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Hexahedra", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Prisms", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Pyramids", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Trihedra", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Polygons", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Polyhedra", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {nullptr}};

      view.menu[1] =
        new Fl_Menu_Button(L + 2 * WB, 2 * WB + 6 * BH, IW, BH, "Elements");
      view.menu[1]->tooltip(
        "View.DrawPoints, View.DrawLines, View.DrawTriangles, "
        "View.DrawQuadrangles, View.DrawTetrahedra, View.DrawHexahedra, "
        "View.DrawPrisms, View.DrawPyramids, View.DrawTrihedra, "
        "View.DrawPolygons, View.DrawPolyhedra");
      view.menu[1]->menu(menu_view_element_types);
      view.menu[1]->callback(view_options_ok_cb);

      view.value[6] =
        valueInput(L + 3 * WB + IW, 2 * WB + 6 * BH, IW / 3, BH, "Sampling",
                   "View.Sampling", 1, 100, 1, view_options_ok_cb);
      view.value[6]->align(FL_ALIGN_RIGHT);
      view.value[6]->when(FL_WHEN_RELEASE);

      static Fl_Menu_Item menu_boundary[] = {
        {"None", 0, nullptr, nullptr},
        {"Dimension - 1", 0, nullptr, nullptr},
        {"Dimension - 2", 0, nullptr, nullptr},
        {"Dimension - 3", 0, nullptr, nullptr},
        {nullptr}};
      view.choice[9] = new Fl_Choice(L + 2 * WB, 2 * WB + 7 * BH, IW, BH,
                                     "Element boundary mode");
      view.choice[9]->tooltip("View.Boundary");
      view.choice[9]->menu(menu_boundary);
      view.choice[9]->align(FL_ALIGN_RIGHT);
      view.choice[9]->callback(view_options_ok_cb);

      view.value[0] =
        valueInput(L + 2 * WB, 2 * WB + 8 * BH, IW / 2, BH, nullptr,
                   "View.Normals", 0, 500, 1, view_options_ok_cb);
      view.value[0]->align(FL_ALIGN_RIGHT);
      view.value[0]->when(FL_WHEN_RELEASE);

      view.value[1] = valueInput(L + 2 * WB + IW / 2, 2 * WB + 8 * BH, IW / 2,
                                 BH, "Normals and tangents", "View.Tangents", 0,
                                 500, 1, view_options_ok_cb);
      view.value[1]->align(FL_ALIGN_RIGHT);
      view.value[1]->when(FL_WHEN_RELEASE);

      static Fl_Menu_Item menu_view_field_types[] = {
        {"Scalar", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Vector", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Tensor", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {nullptr}};
      view.menu[0] =
        new Fl_Menu_Button(L + 2 * WB, 2 * WB + 9 * BH, IW, BH, "Fields");
      view.menu[0]->tooltip(
        "View.DrawScalars, View.DrawVectors, View.DrawTensors");
      view.menu[0]->menu(menu_view_field_types);
      view.menu[0]->callback(view_options_ok_cb);

      static Fl_Menu_Item menu_force_field_type[] = {
        {"Original Field", 0, nullptr, nullptr},
        {"Force Scalar", 0, nullptr, nullptr},
        {"Force Vector", 0, nullptr, nullptr},
        {"Force Tensor", 0, nullptr, nullptr},
        {nullptr}};
      view.choice[14] = new Fl_Choice(L + 2 * WB, 2 * WB + 10 * BH, IW, BH);
      view.choice[14]->tooltip("View.ForceNumComponents");
      view.choice[14]->menu(menu_force_field_type);
      view.choice[14]->align(FL_ALIGN_RIGHT);
      view.choice[14]->callback(view_options_ok_cb);

      // the 9 fields of the map widen together
      int W = width - 5 * WB - IW;
      Fl_Group *row = new Fl_Group(L + 3 * WB + IW, 2 * WB + 10 * BH, W, BH);
      for(int i = 0; i < 9; i++) {
        int w = W / 9;
        view.value[70 + i] = valueInput(
          L + 3 * WB + IW + i * w, 2 * WB + 10 * BH, (i < 8) ? w : W - 8 * w,
          BH, nullptr, nullptr, -1, 9, 1, view_options_ok_cb);
        view.value[70 + i]->copy_tooltip(
          ("View.ComponentMap" + std::to_string(i)).c_str());
      }
      row->end();

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Transfo");
      o->hide();

      // the matrix, the offsets and the raise move together, as one table
      Fl_Group *table = new Fl_Group(L + 2 * WB, 2 * WB + 1 * BH,
                                     2 * IW - 3 * WB + 7 * IW / 10, 4 * BH);
      Fl_Box *b = new Fl_Box(FL_NO_BOX, L + 2 * WB, 2 * WB + 1 * BH, IW, BH,
                             "Coordinate transformation:");
      b->align(FL_ALIGN_INSIDE | FL_ALIGN_LEFT);

      int ss = 2 * IW / 3 / 3 + 4;
      view.value[51] = valueInput(L + 2 * WB, 2 * WB + 2 * BH, ss, BH, nullptr,
                                  "View.TransformXX");
      view.value[52] = valueInput(L + 2 * WB + ss, 2 * WB + 2 * BH, ss, BH,
                                  nullptr, "View.TransformXY");
      view.value[53] = valueInput(L + 2 * WB + 2 * ss, 2 * WB + 2 * BH, ss, BH,
                                  " X", "View.TransformXZ");
      view.value[40] =
        new inputValueFloat(L + 2 * WB + IW, 2 * WB + 2 * BH, 7 * IW / 10, BH);
      view.value[40]->tooltip("View.OffsetX");

      view.value[54] = valueInput(L + 2 * WB, 2 * WB + 3 * BH, ss, BH, nullptr,
                                  "View.TransformYX");
      view.value[55] = valueInput(L + 2 * WB + ss, 2 * WB + 3 * BH, ss, BH,
                                  nullptr, "View.TransformYY");
      view.value[56] = valueInput(L + 2 * WB + 2 * ss, 2 * WB + 3 * BH, ss, BH,
                                  " Y +", "View.TransformYZ");
      view.value[41] =
        new inputValueFloat(L + 2 * WB + IW, 2 * WB + 3 * BH, 7 * IW / 10, BH);
      view.value[41]->tooltip("View.OffsetY");

      view.value[57] = valueInput(L + 2 * WB, 2 * WB + 4 * BH, ss, BH, nullptr,
                                  "View.TransformZX");
      view.value[58] = valueInput(L + 2 * WB + ss, 2 * WB + 4 * BH, ss, BH,
                                  nullptr, "View.TransformZY");
      view.value[59] = valueInput(L + 2 * WB + 2 * ss, 2 * WB + 4 * BH, ss, BH,
                                  " Z", "View.TransformZZ");
      view.value[42] =
        new inputValueFloat(L + 2 * WB + IW, 2 * WB + 4 * BH, 7 * IW / 10, BH);
      view.value[42]->tooltip("View.OffsetZ");

      Fl_Box *b2 = new Fl_Box(FL_NO_BOX, L + 2 * WB + 2 * IW - 3 * WB,
                              2 * WB + 1 * BH, 7 * IW / 10, BH, "Raise:");
      b2->align(FL_ALIGN_INSIDE | FL_ALIGN_LEFT);

      view.value[43] = new inputValueFloat(L + 2 * WB + 2 * IW - 3 * WB,
                                           2 * WB + 2 * BH, 7 * IW / 10, BH);
      view.value[43]->tooltip("View.RaiseX");
      view.value[44] = new inputValueFloat(L + 2 * WB + 2 * IW - 3 * WB,
                                           2 * WB + 3 * BH, 7 * IW / 10, BH);
      view.value[44]->tooltip("View.RaiseY");
      view.value[45] = new inputValueFloat(L + 2 * WB + 2 * IW - 3 * WB,
                                           2 * WB + 4 * BH, 7 * IW / 10, BH);
      view.value[45]->tooltip("View.RaiseZ");
      table->end();
      view.value[46] = new inputValueFloat(L + 2 * WB, 2 * WB + 5 * BH, 3 * ss,
                                           BH, "Normal raise");
      view.value[46]->tooltip("View.NormalRaise");

      for(int i = 40; i <= 46; i++) {
        view.value[i]->align(FL_ALIGN_RIGHT);
        view.value[i]->when(FL_WHEN_RELEASE);
        view.value[i]->callback(view_options_ok_cb);
      }
      for(int i = 51; i <= 59; i++) {
        view.value[i]->minimum(-1.);
        view.value[i]->maximum(1.);
        if(CTX::instance()->inputScrolling) view.value[i]->step(0.1);
        view.value[i]->align(FL_ALIGN_RIGHT);
        view.value[i]->when(FL_WHEN_RELEASE);
        view.value[i]->callback(view_options_ok_cb);
      }

      view.butt[6] = checkButton(L + 2 * WB, 2 * WB + 6 * BH, BW, BH,
                                 "Use general transformation expressions",
                                 "View.UseGeneralizedRaise", view_options_ok_cb,
                                 (void *)"view_general_transform");

      view.choice[11] =
        new Fl_Choice(L + 2 * WB, 2 * WB + 7 * BH, IW, BH, "Data source");
      view.choice[11]->tooltip("View.GeneralizedRaiseView");
      view.choice[11]->align(FL_ALIGN_RIGHT);
      view.choice[11]->add("Self");
      view.choice[11]->callback(view_options_ok_cb);

      view.value[2] =
        new inputValueFloat(L + 2 * WB, 2 * WB + 8 * BH, IW, BH, "Factor");
      view.value[2]->tooltip("View.GeneralizedRaiseFactor");
      view.value[2]->align(FL_ALIGN_RIGHT);
      view.value[2]->when(FL_WHEN_RELEASE);
      view.value[2]->callback(view_options_ok_cb);

      view.input[4] =
        new Fl_Input(L + 2 * WB, 2 * WB + 9 * BH, IW, BH, "X expression");
      view.input[4]->tooltip("View.GeneralizedRaiseX");
      view.input[4]->align(FL_ALIGN_RIGHT);
      view.input[4]->callback(view_options_ok_cb);

      view.input[5] =
        new Fl_Input(L + 2 * WB, 2 * WB + 10 * BH, IW, BH, "Y expression");
      view.input[5]->tooltip("View.GeneralizedRaiseY");
      view.input[5]->align(FL_ALIGN_RIGHT);
      view.input[5]->callback(view_options_ok_cb);

      view.input[6] =
        new Fl_Input(L + 2 * WB, 2 * WB + 11 * BH, IW, BH, "Z expression");
      view.input[6]->tooltip("View.GeneralizedRaiseZ");
      view.input[6]->align(FL_ALIGN_RIGHT);
      view.input[6]->callback(view_options_ok_cb);

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Aspect");
      o->hide();

      view.value[12] = valueInput(L + 2 * WB, 2 * WB + 1 * BH, IW, BH,
                                  "Element shrinking factor", "View.Explode",
                                  0., 1., 0.01, view_options_ok_cb);
      view.value[12]->align(FL_ALIGN_RIGHT);
      view.value[12]->when(FL_WHEN_RELEASE);

      view.choice[5] =
        new Fl_Choice(L + 2 * WB, 2 * WB + 2 * BH, IW, BH, "Point display");
      view.choice[5]->tooltip("View.PointType");
      view.choice[5]->menu(menu_point_display_post);
      view.choice[5]->align(FL_ALIGN_RIGHT);
      view.choice[5]->callback(view_options_ok_cb);

      view.value[61] =
        valueInput(L + 2 * WB, 2 * WB + 3 * BH, IW, BH, "Point size",
                   "View.PointSize", 0.1, 50, 0.1, view_options_ok_cb);
      view.value[61]->align(FL_ALIGN_RIGHT);

      view.choice[6] =
        new Fl_Choice(L + 2 * WB, 2 * WB + 4 * BH, IW, BH, "Line display");
      view.choice[6]->tooltip("View.LineType");
      view.choice[6]->menu(menu_line_display_post);
      view.choice[6]->align(FL_ALIGN_RIGHT);
      view.choice[6]->callback(view_options_ok_cb);

      view.butt[26] = checkButton(C2, 2 * WB + 4 * BH, RW, BH, "Stipple",
                                  "View.Stipple", view_options_ok_cb);

      view.value[62] =
        valueInput(L + 2 * WB, 2 * WB + 5 * BH, IW / 2, BH, nullptr,
                   "View.LineWidth", 0.1, 50, 0.1, view_options_ok_cb);
      view.value[62]->align(FL_ALIGN_RIGHT);
      view.value[80] =
        valueInput(L + 2 * WB + IW / 2, 2 * WB + 5 * BH, IW - IW / 2, BH,
                   "Line / outline width", "View.OutlineWidth", 0.1, 50, 0.1,
                   view_options_ok_cb);
      view.value[80]->align(FL_ALIGN_RIGHT);

      {
        static Fl_Menu_Item menu_vectype[] = {
          {"Line", 0, nullptr, nullptr},
          {"Arrow", 0, nullptr, nullptr},
          {"Pyramid", 0, nullptr, nullptr},
          {"3D arrow", 0, nullptr, nullptr},
          {"Displacement", 0, nullptr, nullptr},
          {"Comet", 0, nullptr, nullptr},
          {nullptr}};
        view.choice[2] =
          new Fl_Choice(L + 2 * WB, 2 * WB + 6 * BH, IW, BH, "Vector display");
        view.choice[2]->tooltip("View.VectorType");
        view.choice[2]->menu(menu_vectype);
        view.choice[2]->align(FL_ALIGN_RIGHT);
        view.choice[2]->callback(view_options_ok_cb);

        view.value[64] =
          valueInput(L + 2 * WB, 2 * WB + 7 * BH, IW / 2, BH, nullptr,
                     "View.ArrowSizeMin", 0, 500, 1, view_options_ok_cb);
        view.value[64]->align(FL_ALIGN_RIGHT);
        view.value[60] = valueInput(
          L + 2 * WB + IW / 2, 2 * WB + 7 * BH, IW / 2, BH, "Arrow size",
          "View.ArrowSizeMax", 0, 500, 1, view_options_ok_cb);
        view.value[60]->align(FL_ALIGN_RIGHT);

        view.value[63] = new inputValueFloat(L + 2 * WB, 2 * WB + 8 * BH, IW,
                                             BH, "Displacement factor");
        view.value[63]->tooltip("View.DisplacementFactor");
        view.value[63]->minimum(0.);
        view.value[63]->maximum(1.);
        if(CTX::instance()->inputScrolling) view.value[63]->step(0.01);
        view.value[63]->align(FL_ALIGN_RIGHT);
        view.value[63]->when(FL_WHEN_RELEASE);
        view.value[63]->callback(view_options_ok_cb);

        view.choice[10] = new Fl_Choice(L + 2 * WB, 2 * WB + 9 * BH, IW, BH,
                                        "Data source for vector fields");
        view.choice[10]->tooltip("View.ExternalView");
        view.choice[10]->align(FL_ALIGN_RIGHT);
        view.choice[10]->add("Self");
        view.choice[10]->callback(view_options_ok_cb);
      }

      static Fl_Menu_Item menu_glyph_loc[] = {
        {"Barycenter", 0, nullptr, nullptr},
        {"Node", 0, nullptr, nullptr},
        {nullptr}};
      view.choice[3] =
        new Fl_Choice(L + 2 * WB, 2 * WB + 10 * BH, IW, BH, "Glyph location");
      view.choice[3]->tooltip("View.GlyphLocation");
      view.choice[3]->menu(menu_glyph_loc);
      view.choice[3]->align(FL_ALIGN_RIGHT);
      view.choice[3]->callback(view_options_ok_cb);

      static Fl_Menu_Item menu_glyph_center[] = {
        {"Left-aligned", 0, nullptr, nullptr},
        {"Centered", 0, nullptr, nullptr},
        {"Right-aligned", 0, nullptr, nullptr},
        {nullptr}};
      view.choice[15] = new Fl_Choice(C2, 2 * WB + 10 * BH, RW, BH);
      view.choice[15]->tooltip("View.CenterGlyphs");
      view.choice[15]->menu(menu_glyph_center);
      view.choice[15]->callback(view_options_ok_cb);

      static Fl_Menu_Item menu_tensor[] = {
        {"Von-Mises", 0, nullptr, nullptr},
        {"Maximum eigenvalue", 0, nullptr, nullptr},
        {"Minimum eigenvalue", 0, nullptr, nullptr},
        {"Eigenvectors", 0, nullptr, nullptr},
        {"Ellipse", 0, nullptr, nullptr},
        {"Ellipsoid", 0, nullptr, nullptr},
        {"Frame (box)", 0, nullptr, nullptr},
        {"Frame (vectors)", 0, nullptr, nullptr},
        {nullptr}};
      view.choice[4] =
        new Fl_Choice(L + 2 * WB, 2 * WB + 11 * BH, IW, BH, "Tensor display");
      view.choice[4]->tooltip("View.TensorType");
      view.choice[4]->menu(menu_tensor);
      view.choice[4]->align(FL_ALIGN_RIGHT);
      view.choice[4]->callback(view_options_ok_cb);

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Color");
      o->hide();

      view.butt[11] = checkButton(L + 2 * WB, 2 * WB + 1 * BH, BW, BH,
                                  "Enable lighting", "View.Light (Alt+w)",
                                  view_options_ok_cb, (void *)"view_light");

      view.butt[8] = checkButton(L + 2 * WB, 2 * WB + 2 * BH, BW, BH,
                                 "Enable lighting of lines", "View.LightLines",
                                 view_options_ok_cb);

      view.butt[9] = checkButton(L + 2 * WB, 2 * WB + 3 * BH, BW, BH,
                                 "Use two-side lighting", "View.LightTwoSide",
                                 view_options_ok_cb);

      view.butt[12] =
        checkButton(L + 2 * WB, 2 * WB + 4 * BH, BW, BH, "Smooth normals",
                    "View.SmoothNormals", view_options_ok_cb);

      view.value[10] = valueInput(
        L + 2 * WB, 2 * WB + 5 * BH, IW, BH, "Smoothing threshold angle",
        "View.AngleSmoothNormals", 0., 180., 1., view_options_ok_cb);
      view.value[10]->align(FL_ALIGN_RIGHT);
      view.value[10]->when(FL_WHEN_RELEASE);

      view.value[79] =
        valueInput(L + 2 * WB, 2 * WB + 6 * BH, IW, BH, "Opacity",
                   "View.Opacity", 0., 1., 0.01, view_options_ok_cb);
      view.value[79]->align(FL_ALIGN_RIGHT);
      view.value[79]->when(FL_WHEN_CHANGED | FL_WHEN_RELEASE);

      std::size_t i = 0, j = 0;
      while(ViewOptions_Color[j].str) {
        if(ViewOptions_Color[j].level & GMSH_DEPRECATED) {
          j++;
          continue;
        }
        view.color[i] = new Fl_Button(L + 2 * WB, 3 * WB + (7 + i) * BH, IW, BH,
                                      ViewOptions_Color[j].str);
        view.color[i]->callback(view_color_cb,
                                (void *)ViewOptions_Color[j].function);
        i++;
        j++;
      }

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Map");
      // o->label("@-1gmsh_colormap");
      o->hide();

      // the predefined maps by name, above the map itself
      static std::vector<Fl_Menu_Item> menu_colormap;
      if(menu_colormap.empty()) {
        for(int i = 0; i < ColorTable_NumPredefined(); i++) {
          Fl_Menu_Item item = {ColorTable_Name(i), 0, nullptr, nullptr};
          menu_colormap.push_back(item);
        }
        Fl_Menu_Item last = {nullptr};
        menu_colormap.push_back(last);
      }
      view.choice[17] = new Fl_Choice(L + 2 * WB, 2 * WB + BH, IW, BH,
                                      "Predefined colormap");
      view.choice[17]->tooltip("View.ColormapNumber");
      view.choice[17]->menu(&menu_colormap[0]);
      view.choice[17]->align(FL_ALIGN_RIGHT);
      view.choice[17]->callback(view_options_ok_cb);
      // the keys go to the map widget below
      view.choice[17]->clear_visible_focus();

      // 16:9, but tall enough for its help
      int cw = width - 4 * WB;
      view.colorbar =
        new colorbarWindow(L + 2 * WB, 3 * WB + 2 * BH, cw, 9 * cw / 16);
      view.colorbar->size(cw,
                          std::max(9 * cw / 16, view.colorbar->helpHeight()));
      view.colorbar->callback(view_options_ok_cb);

      o->end();
    }
  }
  view.group->end();

  scroll->end();

  redraw = new Fl_Return_Button(winWidth - BB - WB, winHeight - BH - WB, BB, BH,
                                "Redraw");
  redraw->callback(redraw_cb);
  redraw->hide();

  win->end();

  _category[0] = general.group;
  _category[1] = geo.group;
  _category[2] = mesh.group;
  _category[3] = solver.group;
  _category[4] = post.group;
  _category[5] = view.group;
  for(int c = 0; c < 6; c++) _makeSections(c);
  win->resizable(scroll);
  ((paletteWindow *)win)->sizeRange(winWidth, 12 * BH); // height: layout()
  ((paletteWindow *)win)->whenResized(options_resized_cb, nullptr);
  layout(false);

  FL_NORMAL_SIZE += deltaFontSize;
}

void optionWindow::_makeSections(int c)
{
  // the groups built as tabs become sections; the tab shown first is open
  Fl_Group *g = _category[c];
  bool first = true;
  g->label(nullptr);
  g->resizable(nullptr);
  std::vector<Fl_Group *> groups;
  for(int i = 0; i < g->children(); i++)
    if(g->child(i)->as_group()) groups.push_back(g->child(i)->as_group());
  for(std::size_t i = 0; i < groups.size(); i++) {
    section sec;
    sec.group = groups[i];
    sec.name = sec.group->label();
    sec.open = first && sec.group->visible();
    if(sec.open) first = false;
    sec.group->label(nullptr);
    sec.group->resizable(nullptr);
    sec.group->show();
    // the widgets top to bottom, grouped in blocks of those that overlap
    std::vector<Fl_Widget *> w(sec.group->array(),
                               sec.group->array() + sec.group->children());
    std::stable_sort(w.begin(), w.end(), [](Fl_Widget *a, Fl_Widget *b) {
      return a->y() < b->y();
    });
    for(Fl_Widget *o : w) {
      int y = o->y() - sec.group->y();
      if(sec.blocks.empty() || y >= sec.blocks.back().y + sec.blocks.back().h) {
        block b;
        b.y = y;
        b.h = 0;
        sec.blocks.push_back(b);
      }
      block &b = sec.blocks.back();
      b.h = std::max(b.h, y + o->h() - b.y);
      b.widgets.push_back(o);
      b.dy.push_back(y - b.y);
    }
    // the right column starts in the middle, the right margin is 2 * WB in
    int L = sec.group->x() - WB; // the left edge of the scroll
    sec.rules.record(sec.group, L + _width / 2 - 1, L + _width - 2 * WB);
    sec.header = new Fl_Button(0, 0, sec.group->w(), _rowHeight);
    sec.header->box(FL_FLAT_BOX);
    sec.header->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
    sec.header->labelfont(FL_BOLD);
    sec.header->clear_visible_focus();
    sec.header->callback(options_section_cb, (void *)(intptr_t)(100 * c + i));
    g->add(sec.header);
    _sections[c].push_back(sec);
  }
}

static bool matches(Fl_Widget *w, const searchFilter &f)
{
  if(!w->visible()) return false;
  auto has = [&f](const char *text) { return text && f.matches(text); };
  // the tooltip holds the name of the option
  if(has(w->label()) || has(w->tooltip())) return true;
  if(Fl_Menu_ *m = dynamic_cast<Fl_Menu_ *>(w)) {
    for(int i = 0; i < m->size(); i++)
      if(has(m->text(i))) return true;
  }
  if(Fl_Group *g = w->as_group()) {
    for(int i = 0; i < g->children(); i++)
      if(matches(g->child(i), f)) return true;
  }
  return false;
}

bool optionWindow::_searching() { return !_filter.empty(); }

void optionWindow::layout(bool keepPosition)
{
  static const char *names[6] = {"General", "Geometry", "Mesh",
                                 "Solver",  "Post-pro", "View"};
  int bh = _rowHeight, ww = win->w(), wh = win->h();
  _filter.set(search);
  bool searching = !_filter.empty();

  // widgets hidden by the previous search are shown again
  for(Fl_Widget *w : _hiddenBySearch) w->show();
  _hiddenBySearch.clear();

  // the blocks to show: all of them in the current category, or those that
  // match in every category while searching
  std::vector<std::vector<std::vector<bool>>> shown(6);
  bool any[6];
  for(int c = 0; c < 6; c++) {
    any[c] = false;
    bool active = searching ? (c < 5 || PView::list.size()) : (c == _current);
    shown[c].resize(_sections[c].size());
    for(std::size_t i = 0; i < _sections[c].size(); i++) {
      section &sec = _sections[c][i];
      bool all = !searching || _filter.matches(sec.name);
      for(block &b : sec.blocks) {
        bool show = active && all;
        if(active && !all)
          for(Fl_Widget *w : b.widgets)
            if(matches(w, _filter)) show = true;
        shown[c][i].push_back(show);
        if(show) any[c] = true;
      }
    }
  }

  // below the search field, the tabs down to the bottom (or the Redraw
  // button); in their frame the views, as many as there are but down to two
  // in a short window, then the options; the least height of the window
  // leaves three rows of options
  int ty = 2 * WB + bh;
  int tabsBottom = redraw->visible() ? wh - bh - 2 * WB : wh - WB;
  int L = scroll->x();
  int y = ty + bh + WB;
  int bottom = tabsBottom - WB;
  int least = y + 3 * bh + (wh - bottom);
  _tabs->Fl_Widget::resize(WB, ty, ww - 2 * WB, tabsBottom - ty);
  for(int c = 0; c < 6; c++)
    _categoryTab[c]->resize(WB, ty + bh, ww - 2 * WB, tabsBottom - ty - bh);
  // the tab of the category stays while searching in all of them
  _tabs->value(_categoryTab[std::max(0, _current)]);
  _tabs->redraw();
  if(any[5] && PView::list.size()) {
    int h = std::min(viewList->heightFor(PView::list.size()),
                     bottom - y - WB - 3 * bh);
    h = std::max(h, viewList->heightFor(2));
    viewList->resize(L + WB, y, ww - 2 * L - 2 * WB, h);
    viewList->show();
    y += h + WB;
    least += viewList->heightFor(2) + WB;
  }
  else
    viewList->hide();
  // taller if needed, laid out again then
  if(((paletteWindow *)win)->leastHeight(least)) {
    // laid out again by the resize, but scrolled to the top
    layout(keepPosition);
    return;
  }

  int ypos = keepPosition ? scroll->yposition() : 0;
  scroll->scroll_to(0, 0);
  scroll->resize(L, y, ww - 2 * L, std::max(0, bottom - y));
  // sized too: hidden, it is scaled with the window like the scroll it lies in
  redraw->resize(ww - _buttonWidth - WB, wh - bh - WB, _buttonWidth, bh);

  // the sections follow the width; the colormap keeps its shape
  int cw = scroll->w() - Fl::scrollbar_size(), extra = cw - _width;
  int sw = _width - 2 * WB + extra;
  for(int c = 0; c < 6; c++)
    for(section &sec : _sections[c]) sec.rules.apply(extra);
  int cbw = view.colorbar->w();
  view.colorbar->size(cbw, std::max(9 * cbw / 16, view.colorbar->helpHeight()));

  // the sections stacked down the scroll; a group is first moved, which moves
  // its children, then its children are placed and its height set. The
  // groups leave room for the scrollbar, or they could scroll sideways
  int yy = scroll->y();
  bool first = true;
  for(int c = 0; c < 6; c++) {
    Fl_Group *g = _category[c];
    if(!any[c]) {
      // hidden, and out of the way: FLTK 1.3 scrolls over hidden children
      g->hide();
      g->resize(g->x(), scroll->y(), g->w(), 0);
      continue;
    }
    g->show();
    int y0 = yy;
    g->resize(L, y0, cw, g->h());
    for(std::size_t i = 0; i < _sections[c].size(); i++) {
      section &sec = _sections[c][i];
      std::vector<bool> &show = shown[c][i];
      if(std::find(show.begin(), show.end(), true) == show.end()) {
        sec.header->hide();
        sec.group->hide();
        continue;
      }
      bool open = searching || sec.open;
      std::string label = std::string(open ? "@-22> " : "@-2> ") +
                          (searching ? std::string(names[c]) + " - " : "") +
                          sec.name;
      sec.header->copy_label(label.c_str());
      // a line between sections
      sec.header->box(first ? FL_FLAT_BOX : GMSH_SIMPLE_TOP_BOX);
      sec.header->down_box(sec.header->box()); // no pressed look
      first = false;
      sec.header->resize(L + WB, yy, sw, bh);
      sec.header->show();
      yy += bh;
      if(!open) {
        sec.group->hide();
        continue;
      }
      sec.group->show();
      sec.group->resize(sec.group->x(), yy, sw, sec.group->h());
      int bottom = 0;
      for(std::size_t j = 0; j < sec.blocks.size(); j++) {
        block &b = sec.blocks[j];
        if(!show[j]) {
          for(Fl_Widget *w : b.widgets) {
            if(w->visible()) _hiddenBySearch.push_back(w);
            w->hide();
          }
          continue;
        }
        int gap = j ? b.y - sec.blocks[j - 1].y - sec.blocks[j - 1].h : b.y;
        int top = bottom + gap;
        int h = 0;
        for(std::size_t k = 0; k < b.widgets.size(); k++) {
          b.widgets[k]->position(b.widgets[k]->x(), yy + top + b.dy[k]);
          h = std::max(h, b.dy[k] + b.widgets[k]->h());
        }
        bottom = top + h;
      }
      sec.group->resize(sec.group->x(), yy, sw, bottom + WB);
      yy += bottom + WB;
    }
    g->resize(L, y0, cw, yy - y0);
  }
  int most = std::max(0, yy - scroll->y() - scroll->h());
  scroll->scroll_to(0, std::min(ypos, most));

  win->init_sizes();
  win->redraw();
}

void optionWindow::categoryChosen()
{
  int c = _tabs->find(_tabs->value());
  int n = PView::list.size();
  if(c == 5 && !n) { // no views: the tab is greyed out, and stays so
    layout(true);
    return;
  }
  search->value("");
  if(c < 5)
    showGroup(c + 1);
  else
    showGroup(6 + std::max(0, std::min(view.index, n - 1)), true, true);
}

void optionWindow::toggleSection(int c, int i)
{
  section &sec = _sections[c][i];
  if(_searching()) {
    // a result leads to its section, in full, scrolled to it
    sec.open = true;
    _current = -1;
    int n = PView::list.size();
    showGroup(c < 5 ? c + 1 : 6 + std::max(0, std::min(view.index, n - 1)),
              true, true);
    int bottom = scroll->y();
    for(int k = 0; k < 6; k++)
      if(_category[k]->visible())
        bottom = std::max(bottom, _category[k]->y() + _category[k]->h());
    int most = std::max(0, bottom - scroll->y() - scroll->h());
    scroll->scroll_to(0, std::min(sec.header->y() - scroll->y(), most));
    return;
  }
  sec.open = !sec.open;
  layout(true);
}

void optionWindow::updateViewTargets()
{
  // the view shown in bold ("@." stops the formatting of the name)
  int n = 0;
  for(int i = 0; i < (int)PView::list.size(); i++) {
    if(i == view.index || viewList->browser->selected(i + 1)) n++;
    std::string str =
      (i == view.index ? "@b@." : "@.") + targetList::viewName(i);
    const char *text = viewList->browser->text(i + 1);
    if(!text || str != text) viewList->browser->text(i + 1, str.c_str());
  }
  std::string str = (n > 1) ? "Applies to " + std::to_string(n) + " views" :
                              "Applies to this view only";
  viewList->count->copy_label(str.c_str());
}

void optionWindow::selectViews(const std::string &which)
{
  viewList->selectViews(which, 0, view.index);
  updateViewTargets();
}

void optionWindow::showGroup(int num, bool showWindow,
                             bool allowMultipleSelections)
{
  // a category asked for: the search is left
  if(showWindow) search->value("");
  int c = (num <= 1) ? 0 : (num <= 5) ? num - 1 : 5;
  if(c == 5) {
    if(!allowMultipleSelections) viewList->browser->deselect();
    viewList->browser->select(num - 5, 1);
    updateViewGroup(num - 6);
  }
  updateViewTargets();
  bool same = (c == _current);
  _current = c;
  layout(same);
  if(showWindow) win->show();
}

void optionWindow::resetBrowser()
{
  viewList->browser->clear();
  for(std::size_t i = 0; i < PView::list.size(); i++)
    viewList->browser->add(""); // the names set by updateViewTargets()
  int n = PView::list.size();
  // the options of a view are also searched in the other categories: those of
  // the view shown, kept or the nearest left
  if(n)
    updateViewGroup(std::max(0, std::min(view.index, n - 1)));
  else {
    view.index = -1;
    view.colorbar->update(-1, 0., 0.);
  }
  if(n)
    _categoryTab[5]->activate();
  else
    _categoryTab[5]->deactivate();
  int num = _current + 1;
  if(_current == 5) num = n ? 6 + std::max(0, std::min(view.index, n - 1)) : 5;
  showGroup(num, false);
}

void optionWindow::resetExternalViewList()
{
  char str[32];
  view.choice[10]->clear();
  view.choice[11]->clear();
  view.choice[10]->add("Self");
  view.choice[11]->add("Self");
  for(std::size_t i = 0; i < PView::list.size(); i++) {
    sprintf(str, "View [%zu]", i);
    view.choice[10]->add(str, 0, nullptr);
    view.choice[11]->add(str, 0, nullptr);
  }
  if(view.index >= 0 && view.index < (int)PView::list.size()) {
    opt_view_external_view(view.index, GMSH_GUI, 0);
    opt_view_gen_raise_view(view.index, GMSH_GUI, 0);
  }
}

void optionWindow::updateViewGroup(int index)
{
  if(index < 0 || index >= (int)PView::list.size()) return;

  view.index = index;

  PView *v = PView::list[index];
  PViewData *data = v->getData();

  double maxval = std::max(fabs(data->getMin()), fabs(data->getMax()));
  if(!maxval) maxval = 1.;
  double val1 = 10. * CTX::instance()->lc;
  double val2 = 2. * CTX::instance()->lc / maxval;

  opt_view_name(index, GMSH_GUI, "");
  opt_view_number_format(index, GMSH_GUI, "");
  opt_view_type(index, GMSH_GUI, 0);
  opt_view_show_scale(index, GMSH_GUI, 0);
  opt_view_draw_strings(index, GMSH_GUI, 0);

  opt_view_adapt_visualization_grid(index, GMSH_GUI, 0);
  opt_view_adapt_skin_only(index, GMSH_GUI, 0);
  opt_view_max_recursion_level(index, GMSH_GUI, 0);
  opt_view_target_error(index, GMSH_GUI, 0);

  if(data->getNumPoints() || data->getNumLines()) {
    ((Fl_Menu_Item *)view.choice[13]->menu())[1].activate();
    ((Fl_Menu_Item *)view.choice[13]->menu())[2].activate();
  }
  else {
    ((Fl_Menu_Item *)view.choice[13]->menu())[1].deactivate();
    ((Fl_Menu_Item *)view.choice[13]->menu())[2].deactivate();
  }

  opt_view_auto_position(index, GMSH_GUI, 0);
  opt_view_position0(index, GMSH_GUI, 0);
  opt_view_position1(index, GMSH_GUI, 0);
  opt_view_size0(index, GMSH_GUI, 0);
  opt_view_size1(index, GMSH_GUI, 0);

  opt_view_axes(index, GMSH_GUI, 0);
  opt_view_colormap_number(index, GMSH_GUI, 0);
  opt_view_axes_mikado(index, GMSH_GUI, 0);
  opt_view_axes_format0(index, GMSH_GUI, "");
  opt_view_axes_format1(index, GMSH_GUI, "");
  opt_view_axes_format2(index, GMSH_GUI, "");
  opt_view_axes_ticks0(index, GMSH_GUI, 0);
  opt_view_axes_ticks1(index, GMSH_GUI, 0);
  opt_view_axes_ticks2(index, GMSH_GUI, 0);
  opt_view_axes_label0(index, GMSH_GUI, "");
  opt_view_axes_label1(index, GMSH_GUI, "");
  opt_view_axes_label2(index, GMSH_GUI, "");
  opt_view_axes_auto_position(index, GMSH_GUI, 0);
  opt_view_axes_xmin(index, GMSH_GUI, 0);
  opt_view_axes_xmax(index, GMSH_GUI, 0);
  opt_view_axes_ymin(index, GMSH_GUI, 0);
  opt_view_axes_ymax(index, GMSH_GUI, 0);
  opt_view_axes_zmin(index, GMSH_GUI, 0);
  opt_view_axes_zmax(index, GMSH_GUI, 0);
  for(int i = 13; i <= 18; i++) {
    if(CTX::instance()->inputScrolling)
      view.value[i]->step(CTX::instance()->lc / 200., 1);
    view.value[i]->minimum(-CTX::instance()->lc);
    view.value[i]->maximum(CTX::instance()->lc);
  }

  if(data->hasElements()) {
    view.range->activate();
    ((Fl_Menu_Item *)view.choice[13]->menu())[0].activate();
  }
  else {
    view.range->deactivate();
    ((Fl_Menu_Item *)view.choice[13]->menu())[0].deactivate();
  }
  opt_view_show_element(index, GMSH_GUI, 0);
  opt_view_draw_skin_edges_only(index, GMSH_GUI, 0);
  opt_view_draw_skin_only(index, GMSH_GUI, 0);
  opt_view_light(index, GMSH_GUI, 0);
  opt_view_light_two_side(index, GMSH_GUI, 0);
  opt_view_light_lines(index, GMSH_GUI, 0);
  opt_view_smooth_normals(index, GMSH_GUI, 0);
  opt_view_angle_smooth_normals(index, GMSH_GUI, 0);
  opt_view_boundary(index, GMSH_GUI, 0);
  opt_view_explode(index, GMSH_GUI, 0);
  opt_view_draw_points(index, GMSH_GUI, 0);
  opt_view_draw_lines(index, GMSH_GUI, 0);
  opt_view_draw_triangles(index, GMSH_GUI, 0);
  opt_view_draw_quadrangles(index, GMSH_GUI, 0);
  opt_view_draw_tetrahedra(index, GMSH_GUI, 0);
  opt_view_draw_hexahedra(index, GMSH_GUI, 0);
  opt_view_draw_prisms(index, GMSH_GUI, 0);
  opt_view_draw_pyramids(index, GMSH_GUI, 0);
  opt_view_draw_trihedra(index, GMSH_GUI, 0);
  opt_view_draw_polygons(index, GMSH_GUI, 0);
  opt_view_draw_polyhedra(index, GMSH_GUI, 0);
  opt_view_draw_scalars(index, GMSH_GUI, 0);
  opt_view_draw_vectors(index, GMSH_GUI, 0);
  opt_view_draw_tensors(index, GMSH_GUI, 0);
  opt_view_normals(index, GMSH_GUI, 0);
  opt_view_tangents(index, GMSH_GUI, 0);
  opt_view_sampling(index, GMSH_GUI, 0);

  opt_view_nb_iso(index, GMSH_GUI, 0);
  opt_view_intervals_type(index, GMSH_GUI, 0);
  opt_view_range_type(index, GMSH_GUI, 0);
  opt_view_custom_min(index, GMSH_GUI, 0);
  opt_view_custom_max(index, GMSH_GUI, 0);
  opt_view_scale_type(index, GMSH_GUI, 0);
  opt_view_scale_threshold(index, GMSH_GUI, 0);
  opt_view_saturate_values(index, GMSH_GUI, 0);

  opt_view_offset0(index, GMSH_GUI, 0);
  opt_view_offset1(index, GMSH_GUI, 0);
  opt_view_offset2(index, GMSH_GUI, 0);
  for(int i = 40; i <= 42; i++) {
    if(CTX::instance()->inputScrolling) view.value[i]->step(val1 / 200., 1);
    view.value[i]->minimum(-val1);
    view.value[i]->maximum(val1);
  }
  opt_view_transform00(index, GMSH_GUI, 0);
  opt_view_transform01(index, GMSH_GUI, 0);
  opt_view_transform02(index, GMSH_GUI, 0);
  opt_view_transform10(index, GMSH_GUI, 0);
  opt_view_transform11(index, GMSH_GUI, 0);
  opt_view_transform12(index, GMSH_GUI, 0);
  opt_view_transform20(index, GMSH_GUI, 0);
  opt_view_transform21(index, GMSH_GUI, 0);
  opt_view_transform22(index, GMSH_GUI, 0);
  opt_view_raise0(index, GMSH_GUI, 0);
  opt_view_raise1(index, GMSH_GUI, 0);
  opt_view_raise2(index, GMSH_GUI, 0);
  opt_view_normal_raise(index, GMSH_GUI, 0);
  for(int i = 43; i <= 46; i++) {
    if(CTX::instance()->inputScrolling) view.value[i]->step(val2 / 200., 1);
    view.value[i]->minimum(-val2);
    view.value[i]->maximum(val2);
  }
  opt_view_use_gen_raise(index, GMSH_GUI, 0);
  opt_view_gen_raise_view(index, GMSH_GUI, 0);
  opt_view_gen_raise_factor(index, GMSH_GUI, 0);
  opt_view_gen_raise0(index, GMSH_GUI, "");
  opt_view_gen_raise1(index, GMSH_GUI, "");
  opt_view_gen_raise2(index, GMSH_GUI, "");
  if(CTX::instance()->inputScrolling) view.value[2]->step(val2 / 200., 1);
  view.value[2]->minimum(-val2);
  view.value[2]->maximum(val2);

  if(data->getNumTimeSteps() == 1) {
    view.value[50]->deactivate();
    view.push[3]->deactivate();
    view.push[4]->deactivate();
    view.label[0]->deactivate();
  }
  else {
    view.value[50]->activate();
    view.push[3]->activate();
    view.push[4]->activate();
    view.label[0]->activate();
  }
  view.value[50]->maximum(data->getNumTimeSteps() - 1);
  opt_view_timestep(index, GMSH_GUI, 0);
  opt_view_show_time(index, GMSH_GUI, 0);
  opt_view_force_num_components(index, GMSH_GUI, 0);
  opt_view_component_map0(index, GMSH_GUI, 0);
  opt_view_component_map1(index, GMSH_GUI, 0);
  opt_view_component_map2(index, GMSH_GUI, 0);
  opt_view_component_map3(index, GMSH_GUI, 0);
  opt_view_component_map4(index, GMSH_GUI, 0);
  opt_view_component_map5(index, GMSH_GUI, 0);
  opt_view_component_map6(index, GMSH_GUI, 0);
  opt_view_component_map7(index, GMSH_GUI, 0);
  opt_view_component_map8(index, GMSH_GUI, 0);

  opt_view_point_size(index, GMSH_GUI, 0);
  opt_view_point_type(index, GMSH_GUI, 0);
  opt_view_line_width(index, GMSH_GUI, 0);
  opt_view_outline_width(index, GMSH_GUI, 0);
  opt_view_line_type(index, GMSH_GUI, 0);
  opt_view_vector_type(index, GMSH_GUI, 0);
  opt_view_arrow_size_min(index, GMSH_GUI, 0);
  opt_view_arrow_size_max(index, GMSH_GUI, 0);

  opt_view_displacement_factor(index, GMSH_GUI, 0);
  double val3 = 2. * CTX::instance()->lc / maxval;
  if(CTX::instance()->inputScrolling) view.value[63]->step(val3 / 100., 1);
  view.value[63]->maximum(val3);

  opt_view_external_view(index, GMSH_GUI, 0);
  opt_view_glyph_location(index, GMSH_GUI, 0);
  opt_view_center_glyphs(index, GMSH_GUI, 0);
  opt_view_tensor_type(index, GMSH_GUI, 0);

  opt_view_use_stipple(index, GMSH_GUI, 0);
  opt_view_opacity(index, GMSH_GUI, 0);
  opt_view_color_points(index, GMSH_GUI, 0);
  opt_view_color_lines(index, GMSH_GUI, 0);
  opt_view_color_triangles(index, GMSH_GUI, 0);
  opt_view_color_quadrangles(index, GMSH_GUI, 0);
  opt_view_color_tetrahedra(index, GMSH_GUI, 0);
  opt_view_color_hexahedra(index, GMSH_GUI, 0);
  opt_view_color_prisms(index, GMSH_GUI, 0);
  opt_view_color_pyramids(index, GMSH_GUI, 0);
  opt_view_color_trihedra(index, GMSH_GUI, 0);
  opt_view_color_polygons(index, GMSH_GUI, 0);
  opt_view_color_polyhedra(index, GMSH_GUI, 0);
  opt_view_color_tangents(index, GMSH_GUI, 0);
  opt_view_color_normals(index, GMSH_GUI, 0);
  opt_view_color_text2d(index, GMSH_GUI, 0);
  opt_view_color_text3d(index, GMSH_GUI, 0);
  opt_view_color_axes(index, GMSH_GUI, 0);
  opt_view_color_background2d(index, GMSH_GUI, 0);

  view.colorbar->update(v->getTag(), data->getMin(), data->getMax());
}

// the widgets enabled or greyed out together
static void setActive(bool on, std::initializer_list<Fl_Widget *> widgets)
{
  for(Fl_Widget *w : widgets) on ? w->activate() : w->deactivate();
}

void optionWindow::activate(const char *what)
{
  if(!what) return;

  // activate/deactivate parts of the option window depending on the
  // user's choices (or the option settings)
  if(!strcmp(what, "fast_redraw")) {
    // (no drawing here: this is also called by the option setter)
    if(general.butt[2]->value())
      redraw->show();
    else
      redraw->hide();
    layout(true);
  }
  else if(!strcmp(what, "shaders")) {
    // studio shading takes the direction of light 0 alone
    if(general.butt[3]->value() && general.choice[8]->value())
      general.value[13]->deactivate();
    else
      general.value[13]->activate();
    setActive(general.butt[3]->value(),
              {general.choice[8], general.value[33], general.value[34],
               general.value[35], geo.value[21], geo.choice[6], mesh.value[27],
               mesh.choice[11], view.value[79]});
  }
  else if(!strcmp(what, "rotation_center")) {
    setActive(
      !(general.butt[15]->value()),
      {general.push[0], general.value[8], general.value[9], general.value[10]});
  }
  else if(!strcmp(what, "general_axes")) {
    setActive(general.choice[4]->value(),
              {general.value[17], general.value[18], general.value[19],
               general.input[3], general.input[4], general.input[5],
               general.input[6], general.input[7], general.input[8]});
  }
  else if(!strcmp(what, "general_axes_auto")) {
    setActive(!(general.butt[0]->value()),
              {general.value[20], general.value[21], general.value[22],
               general.value[23], general.value[24], general.value[25],
               general.push[1]});
  }
  else if(!strcmp(what, "general_small_axes")) {
    setActive(general.butt[1]->value(), {general.value[26], general.value[27]});
  }
  else if(!strcmp(what, "general_camera")) {
    if(general.butt[19]->value()) {
      if(CTX::instance()->gamepad && CTX::instance()->gamepad->active)
        general.gamepadconfig->activate();
    }
    else {
      general.gamepadconfig->deactivate();
    }
    setActive(general.butt[17]->value(), {general.value[29]});
    setActive(general.butt[18]->value(),
              {general.value[30], general.value[31]});
  }
  else if(!strcmp(what, "geo_transform")) {
    if(geo.choice[3]->value() == 1) {
      for(int i = 7; i <= 18; i++) geo.value[i]->activate();
    }
    else {
      for(int i = 7; i <= 18; i++) geo.value[i]->deactivate();
    }
  }
  else if(!strcmp(what, "custom_range")) {
    setActive(view.choice[7]->value() == 1,
              {view.value[31], view.value[32], view.push[1], view.push[2],
               view.butt[38]});
  }
  else if(!strcmp(what, "view_adaptive")) {
    setActive(view.butt[0]->value(),
              {view.push[5], view.push[6], view.value[33], view.value[34],
               view.label[1]});
  }
  else if(!strcmp(what, "view_general_transform")) {
    setActive(view.butt[6]->value(),
              {view.choice[11], view.value[2], view.input[4], view.input[5],
               view.input[6]});
  }
  else if(!strcmp(what, "mesh_light")) {
    setActive(mesh.butt[17]->value(),
              {mesh.butt[18], mesh.butt[19], mesh.choice[10], mesh.value[18]});
  }
  else if(!strcmp(what, "view_light")) {
    setActive(view.butt[11]->value(),
              {view.butt[8], view.butt[9], view.butt[12], view.value[10]});
  }
  else if(!strcmp(what, "view_axes")) {
    setActive(view.choice[8]->value(),
              {view.value[3], view.value[4], view.value[5], view.input[7],
               view.input[8], view.input[9], view.input[10], view.input[11],
               view.input[12]});
  }
  else if(!strcmp(what, "view_axes_auto_3d")) {
    setActive(!(view.butt[25]->value()),
              {view.value[13], view.value[14], view.value[15], view.value[16],
               view.value[17], view.value[18]});
  }
  else if(!strcmp(what, "view_axes_auto_2d")) {
    setActive(view.choice[16]->value() == 0 || view.choice[16]->value() == 12,
              {view.value[20], view.value[21], view.value[22], view.value[23]});
  }
}
