// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#if !defined(HAVE_NO_STDINT_H)
#include <stdint.h>
#elif defined(HAVE_NO_INTPTR_T)
typedef unsigned long intptr_t;
#endif
#include <string.h>
#include <FL/Fl.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Color_Chooser.H>
#include <FL/fl_ask.H>
#include "GmshDefines.h"
#include "GmshMessage.h"
#include "FlGui.h"
#include "inputValue.h"
#include "optionWindow.h"
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
#if defined(HAVE_TOUCHBAR)
#include "touchBar.h"
#endif

extern StringXColor GeneralOptions_Color[];
extern StringXColor GeometryOptions_Color[];
extern StringXColor MeshOptions_Color[];
extern StringXColor ViewOptions_Color[];

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
  {"ZapfDingbats", 0, nullptr, (void *)FL_ZAPF_DINGBATS},
  {"Screen", 0, nullptr, (void *)FL_SCREEN},
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
  FlGui::instance()->options->gmpdoption = new gamepadWindow;
  FlGui::instance()->options->gmpdoption->win->show();
}

void options_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->options->win->show();
}

static void options_browser_cb(Fl_Widget *w, void *data)
{
  // allows multiple selections with the mouse
  FlGui::instance()->options->showGroup(
    FlGui::instance()->options->browser->value(), true, true);
}

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
    FlGui::instance()->rebuildTree(true);
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
  Msg::StatusGl(
    "Select geometrical entity, mesh element or post-processing view\n"
    "[Press 'q' to abort]");

  CTX::instance()->pickElements = 1;
  CTX::instance()->mesh.changed = ENT_ALL;
  drawContext::global()->draw();
  char ib = FlGui::instance()->selectEntity(ENT_ALL);
  if(ib == 'l') {
    SPoint3 pc(0., 0., 0.);
    if(FlGui::instance()->selectedVertices.size())
      pc.setPosition(FlGui::instance()->selectedVertices[0]->x(),
                     FlGui::instance()->selectedVertices[0]->y(),
                     FlGui::instance()->selectedVertices[0]->z());
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
    drawContext *ctx =
      FlGui::instance()->getCurrentOpenglWindow()->getDrawContext();
    ctx->recenterForRotationCenterChange(pc);
    FlGui::instance()->manip->update();
  }
  CTX::instance()->pickElements = 0;
  CTX::instance()->mesh.changed = ENT_ALL;
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
  opt_general_mouse_invert_zoom(0, GMSH_SET, o->general.butt[22]->value());
  if(opt_general_double_buffer(0, GMSH_GET, 0) != o->general.butt[3]->value())
    opt_general_double_buffer(0, GMSH_SET, o->general.butt[3]->value());
  if(opt_general_antialiasing(0, GMSH_GET, 0) != o->general.butt[12]->value())
    opt_general_antialiasing(0, GMSH_SET, o->general.butt[12]->value());
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
     o->general.butt[21]->value()) {
    opt_general_gui_color_scheme(0, GMSH_SET, o->general.butt[21]->value());
    opt_general_color_scheme(0, GMSH_SET | GMSH_GUI,
                             o->general.butt[21]->value() ? 3. : 1.);
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
  opt_general_axes_tics0(0, GMSH_SET, o->general.value[17]->value());
  opt_general_axes_tics1(0, GMSH_SET, o->general.value[18]->value());
  opt_general_axes_tics2(0, GMSH_SET, o->general.value[19]->value());
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

#if defined(HAVE_TOUCHBAR)
  updateTouchBar();
#endif

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
  opt_mesh_surface_edges(0, GMSH_SET, o->mesh.butt[8]->value());
  opt_mesh_surface_faces(0, GMSH_SET, o->mesh.butt[9]->value());
  opt_mesh_volume_edges(0, GMSH_SET, o->mesh.butt[10]->value());
  opt_mesh_volume_faces(0, GMSH_SET, o->mesh.butt[11]->value());
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
  opt_mesh_algo2d(0, GMSH_SET,
                  (o->mesh.choice[2]->value() == 1) ? ALGO_2D_MESHADAPT :
                  (o->mesh.choice[2]->value() == 2) ? ALGO_2D_DELAUNAY :
                  (o->mesh.choice[2]->value() == 3) ? ALGO_2D_FRONTAL :
                  (o->mesh.choice[2]->value() == 4) ? ALGO_2D_BAMG :
                  (o->mesh.choice[2]->value() == 5) ? ALGO_2D_FRONTAL_QUAD :
                  (o->mesh.choice[2]->value() == 6) ? ALGO_2D_PACK_PRLGRMS :
                  (o->mesh.choice[2]->value() == 7) ? ALGO_2D_INITIAL_ONLY :
                                                      ALGO_2D_AUTO);
  opt_mesh_algo3d(0, GMSH_SET,
                  (o->mesh.choice[3]->value() == 1) ? ALGO_3D_FRONTAL :
                  (o->mesh.choice[3]->value() == 2) ? ALGO_3D_HXT :
                  (o->mesh.choice[3]->value() == 3) ? ALGO_3D_MMG3D :
                  (o->mesh.choice[3]->value() == 4) ? ALGO_3D_INITIAL_ONLY :
                                                      ALGO_3D_DELAUNAY);
  opt_mesh_algo_recombine(0, GMSH_SET, o->mesh.choice[1]->value());
  opt_mesh_algo_subdivide(0, GMSH_SET, o->mesh.choice[5]->value());
  opt_mesh_color_carousel(0, GMSH_SET, o->mesh.choice[4]->value());
  opt_mesh_quality_type(0, GMSH_SET, o->mesh.choice[6]->value());
  opt_mesh_label_type(0, GMSH_SET, o->mesh.choice[7]->value());
  opt_mesh_light_lines(0, GMSH_SET, o->mesh.choice[10]->value());

#if defined(HAVE_TOUCHBAR)
  updateTouchBar();
#endif

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
       FlGui::instance()->options->browser->selected(i + 6)) {
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

  if(current < 0) return;

  optionWindow *o = FlGui::instance()->options;
  o->activate((const char *)data);

  if(data) {
    std::string str((const char *)data);
    if(str == "range_min" || str == "range_max") {
      double vmin = 1e200;
      double vmax = -1e200;
      for(int i = 0; i < (int)PView::list.size(); i++) {
        if(i == current ||
           FlGui::instance()->options->browser->selected(i + 6)) {
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
  double target_error = opt_view_target_error(current, GMSH_GET, 0);
  double show_element = opt_view_show_element(current, GMSH_GET, 0);
  double draw_skin_only = opt_view_draw_skin_only(current, GMSH_GET, 0);
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
  double draw_scalars = opt_view_draw_scalars(current, GMSH_GET, 0);
  double draw_vectors = opt_view_draw_vectors(current, GMSH_GET, 0);
  double draw_tensors = opt_view_draw_tensors(current, GMSH_GET, 0);
  double use_gen_raise = opt_view_use_gen_raise(current, GMSH_GET, 0);
  double fake_transparency = opt_view_fake_transparency(current, GMSH_GET, 0);
  double use_stipple = opt_view_use_stipple(current, GMSH_GET, 0);

  double normals = opt_view_normals(current, GMSH_GET, 0);
  double tangents = opt_view_tangents(current, GMSH_GET, 0);
  double custom_min = opt_view_custom_min(current, GMSH_GET, 0);
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
  double line_width = opt_view_line_width(current, GMSH_GET, 0);
  double explode = opt_view_explode(current, GMSH_GET, 0);
  double angle_smooth_normals =
    opt_view_angle_smooth_normals(current, GMSH_GET, 0);
  double position0 = opt_view_position0(current, GMSH_GET, 0);
  double position1 = opt_view_position1(current, GMSH_GET, 0);
  double size0 = opt_view_size0(current, GMSH_GET, 0);
  double size1 = opt_view_size1(current, GMSH_GET, 0);
  double axes_tics0 = opt_view_axes_tics0(current, GMSH_GET, 0);
  double axes_tics1 = opt_view_axes_tics1(current, GMSH_GET, 0);
  double axes_tics2 = opt_view_axes_tics2(current, GMSH_GET, 0);
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
  std::string format = opt_view_format(current, GMSH_GET, "");
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
    if(i == current || FlGui::instance()->options->browser->selected(i + 6)) {
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

      val = o->view.butt[38]->value();
      if(force || (val != saturate_values))
        opt_view_saturate_values(i, GMSH_SET, val);

      val = o->view.butt[10]->value();
      if(force || (val != show_element))
        opt_view_show_element(i, GMSH_SET, val);

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

      val = o->view.butt[6]->value();
      if(force || (val != use_gen_raise))
        opt_view_use_gen_raise(i, GMSH_SET, val);

      val = o->view.butt[24]->value();
      if(force || (val != fake_transparency))
        opt_view_fake_transparency(i, GMSH_SET, val);

      val = o->view.butt[26]->value();
      if(force || (val != use_stipple)) opt_view_use_stipple(i, GMSH_SET, val);

      // view_values

      val = o->view.value[0]->value();
      if(force || (val != normals)) opt_view_normals(i, GMSH_SET, val);

      val = o->view.value[1]->value();
      if(force || (val != tangents)) opt_view_tangents(i, GMSH_SET, val);

      val = o->view.value[31]->value();
      if(force || (val != custom_min)) opt_view_custom_min(i, GMSH_SET, val);

      val = o->view.value[32]->value();
      if(force || (val != custom_max)) opt_view_custom_max(i, GMSH_SET, val);

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
      if(force || (val != axes_tics0)) opt_view_axes_tics0(i, GMSH_SET, val);

      val = o->view.value[4]->value();
      if(force || (val != axes_tics1)) opt_view_axes_tics1(i, GMSH_SET, val);

      val = o->view.value[5]->value();
      if(force || (val != axes_tics2)) opt_view_axes_tics2(i, GMSH_SET, val);

      val = o->view.value[70]->value();
      if(force || (val != component_map0))
        opt_view_component_map0(i, GMSH_SET, val);

      val = o->view.value[70]->value();
      if(force || (val != component_map0))
        opt_view_component_map0(i, GMSH_SET, val);

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
      if(force || (str != format)) opt_view_format(i, GMSH_SET, str);

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

      // colorbar window

      if(force || (i != current)) {
        ColorTable_Copy(&PView::list[current]->getOptions()->colorTable);
        ColorTable_Paste(&PView::list[i]->getOptions()->colorTable);
        PView::list[i]->setChanged(true);
      }
    }
  }

#if defined(HAVE_TOUCHBAR)
  updateTouchBar();
#endif

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

optionWindow::optionWindow(int deltaFontSize)
{
  general.butt.resize(50, nullptr);
  general.push.resize(50, nullptr);
  general.value.resize(50, nullptr);
  general.color.resize(50, nullptr);
  general.input.resize(50, nullptr);
  general.choice.resize(50, nullptr);
  geo.butt.resize(50, nullptr);
  geo.value.resize(50, nullptr);
  geo.color.resize(50, nullptr);
  geo.choice.resize(50, nullptr);
  mesh.butt.resize(50, nullptr);
  mesh.retbutt.resize(50, nullptr);
  mesh.input.resize(50, nullptr);
  mesh.value.resize(50, nullptr);
  mesh.color.resize(50, nullptr);
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
  view.color.resize(50, nullptr);
  view.label.resize(50, nullptr);
  view.menu.resize(50, nullptr);

  FL_NORMAL_SIZE -= deltaFontSize;

  int width = 37 * FL_NORMAL_SIZE + WB;
  int height = 12 * BH + 4 * WB;
  int L = 7 * FL_NORMAL_SIZE;

  win = new paletteWindow(width, height,
                          CTX::instance()->nonModalWindows ? true : false);
  win->box(GMSH_WINDOW_BOX);
  win->label("Options - General");

  // Selection browser
  browser = new Fl_Multi_Browser(0, 0, L, height);
  browser->box(GMSH_SIMPLE_RIGHT_BOX);
  browser->has_scrollbar(Fl_Browser_::VERTICAL);
  browser->add("General");
  browser->add("Geometry");
  browser->add("Mesh");
  browser->add("Solver");
  browser->add("Post-pro");
  browser->callback(options_browser_cb);
  browser->value(1);

  redraw = new Fl_Return_Button(WB, height - BH - WB, L - WB, BH, "Redraw");
  redraw->callback(redraw_cb);

  width -= L;
  int BW = width - 4 * WB;

  // General options
  general.group = new Fl_Group(L, 0, width, height, "General Options");
  {
    Fl_Tabs *o = new Fl_Tabs(L + WB, WB, width - 2 * WB, height - 2 * WB);
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "General");

      general.butt[21] = new Fl_Check_Button(L + 2 * WB, 2 * WB + 1 * BH, BW,
                                             BH, "Use dark interface");
      general.butt[21]->tooltip("General.FltkColorScheme");
      general.butt[21]->type(FL_TOGGLE_BUTTON);
      general.butt[21]->callback(general_options_ok_cb);

      general.butt[13] = new Fl_Check_Button(L + 2 * WB, 2 * WB + 2 * BH, BW,
                                             BH, "Show tooltips");
      general.butt[13]->tooltip("General.Tooltips");
      general.butt[13]->type(FL_TOGGLE_BUTTON);
      general.butt[13]->callback(general_options_ok_cb);

      general.butt[6] = new Fl_Check_Button(L + 2 * WB, 2 * WB + 3 * BH, BW, BH,
                                            "Show bounding boxes");
      general.butt[6]->tooltip("General.DrawBoundingBoxes (Alt+b)");
      general.butt[6]->type(FL_TOGGLE_BUTTON);
      general.butt[6]->callback(general_options_ok_cb);

      general.butt[2] =
        new Fl_Check_Button(L + 2 * WB, 2 * WB + 4 * BH, BW, BH,
                            "Draw simplified model during user interaction");
      general.butt[2]->tooltip("General.FastRedraw (Alt+f)");
      general.butt[2]->type(FL_TOGGLE_BUTTON);
      general.butt[2]->callback(general_options_ok_cb, (void *)"fast_redraw");

      general.butt[11] =
        new Fl_Check_Button(L + 2 * WB, 2 * WB + 5 * BH, BW, BH,
                            "Enable mouse hover over meshes and views");
      general.butt[11]->tooltip("General.MouseHoverMeshes");
      general.butt[11]->type(FL_TOGGLE_BUTTON);
      general.butt[11]->callback(general_options_ok_cb);

      general.butt[3] = new Fl_Check_Button(L + 2 * WB, 2 * WB + 6 * BH, BW, BH,
                                            "Enable double buffering");
      general.butt[3]->tooltip("General.DoubleBuffer");
      general.butt[3]->type(FL_TOGGLE_BUTTON);
      general.butt[3]->callback(general_options_ok_cb);

      general.butt[12] = new Fl_Check_Button(L + 2 * WB, 2 * WB + 7 * BH, BW,
                                             BH, "Enable antialiasing");
      general.butt[12]->tooltip("General.Antialiasing");
      general.butt[12]->type(FL_TOGGLE_BUTTON);
      general.butt[12]->callback(general_options_ok_cb);

      general.butt[5] =
        new Fl_Check_Button(L + 2 * WB, 2 * WB + 8 * BH, BW, BH,
                            "Use trackball rotation instead of Euler angles");
      general.butt[5]->tooltip("General.Trackball");
      general.butt[5]->type(FL_TOGGLE_BUTTON);
      general.butt[5]->callback(general_options_ok_cb);

      general.butt[15] =
        new Fl_Check_Button(L + 2 * WB, 2 * WB + 9 * BH, BW, BH,
                            "Rotate around pseudo center of mass");
      general.butt[15]->tooltip("General.RotationCenterGravity");
      general.butt[15]->type(FL_TOGGLE_BUTTON);
      general.butt[15]->callback(general_options_ok_cb,
                                 (void *)"rotation_center");

      general.push[0] =
        new Fl_Button(L + 2 * IW - 2 * WB, 2 * WB + 10 * BH, BB, BH, "Select");
      general.push[0]->callback(general_options_rotation_center_select_cb);

      general.value[8] =
        new Fl_Value_Input(L + 2 * WB, 2 * WB + 10 * BH, IW / 3, BH);
      general.value[8]->tooltip("General.RotationCenterX");
      general.value[8]->callback(general_options_ok_cb,
                                 (void *)"rotation_center_coord");
      general.value[9] =
        new Fl_Value_Input(L + 2 * WB + IW / 3, 2 * WB + 10 * BH, IW / 3, BH);
      general.value[9]->tooltip("General.RotationCenterY");
      general.value[9]->callback(general_options_ok_cb,
                                 (void *)"rotation_center_coord");
      general.value[10] =
        new Fl_Value_Input(L + 2 * WB + 2 * IW / 3, 2 * WB + 10 * BH, IW / 3,
                           BH, "Rotation center");
      general.value[10]->tooltip("General.RotationCenterZ");
      general.value[10]->align(FL_ALIGN_RIGHT);
      general.value[10]->callback(general_options_ok_cb,
                                  (void *)"rotation_center_coord");

      general.butt[22] =
        new Fl_Check_Button(L + 2 * WB, 2 * WB + 11 * BH, BW, BH,
                            "Invert mouse wheel zoom direction");
      general.butt[22]->tooltip("General.MouseInvertZoom");
      general.butt[22]->type(FL_TOGGLE_BUTTON);
      general.butt[22]->callback(general_options_ok_cb);

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Advanced");

      general.butt[7] = new Fl_Check_Button(L + 2 * WB, 2 * WB + 1 * BH, BW, BH,
                                            "Print messages on terminal");
      general.butt[7]->tooltip("General.Terminal");
      general.butt[7]->type(FL_TOGGLE_BUTTON);
      general.butt[7]->callback(general_options_ok_cb);

      general.value[5] = new Fl_Value_Input(L + 2 * WB, 2 * WB + 2 * BH, IW, BH,
                                            "Message verbosity");
      general.value[5]->tooltip("General.Verbosity");
      general.value[5]->minimum(0);
      general.value[5]->maximum(10);
      if(CTX::instance()->inputScrolling) general.value[5]->step(1);
      general.value[5]->align(FL_ALIGN_RIGHT);
      general.value[5]->callback(general_options_ok_cb);

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
        new Fl_Check_Button(L + 2 * WB, 2 * WB + 5 * BH, BW, BH,
                            "Ask confirmation before overwriting files");
      general.butt[14]->tooltip("General.ConfirmOverwrite");
      general.butt[14]->type(FL_TOGGLE_BUTTON);
      general.butt[14]->callback(general_options_ok_cb);

      general.butt[8] = new Fl_Check_Button(L + 2 * WB, 2 * WB + 6 * BH, BW, BH,
                                            "Save session information on exit");
      general.butt[8]->tooltip("General.SaveSession");
      general.butt[8]->type(FL_TOGGLE_BUTTON);
      general.butt[8]->callback(general_options_ok_cb);

      Fl_Button *b0 =
        new Fl_Button(L + width - 2 * WB - BW / 3, 2 * WB + 6 * BH, BW / 3, BH,
                      "Show file path");
      b0->callback(options_show_file_cb, (void *)"session");

      general.butt[9] = new Fl_Check_Button(
        L + 2 * WB, 2 * WB + 7 * BH, BW / 2 - WB, BH, "Save options on exit");
      general.butt[9]->tooltip("General.SaveOptions");
      general.butt[9]->type(FL_TOGGLE_BUTTON);
      general.butt[9]->callback(general_options_ok_cb);

      Fl_Button *b1 =
        new Fl_Button(L + width - 2 * WB - BW / 3, 2 * WB + 7 * BH, BW / 3, BH,
                      "Show file path");
      b1->callback(options_show_file_cb, (void *)"option");

      general.butt[10] = new Fl_Check_Button(L + 2 * WB, 2 * WB + 8 * BH, BW,
                                             BH, "Enable expert mode");
      general.butt[10]->tooltip("General.ExpertMode");
      general.butt[10]->type(FL_TOGGLE_BUTTON);
      general.butt[10]->callback(general_options_ok_cb);

      general.value[32] = new Fl_Value_Input(L + 2 * WB, 2 * WB + 9 * BH, IW,
                                             BH, "Number of threads");
      general.value[32]->tooltip("General.NumThreads");
      general.value[32]->minimum(0);
      general.value[32]->maximum(16);
      if(CTX::instance()->inputScrolling) general.value[32]->step(1);
      general.value[32]->align(FL_ALIGN_RIGHT);
      general.value[32]->callback(general_options_ok_cb);
#if !defined(_OPENMP)
      general.value[32]->deactivate();
#endif

#if defined(HAVE_VISUDEV)
      general.butt[20] =
        new Fl_Check_Button(L + 2 * WB, 2 * WB + 10 * BH, BW / 2 - WB, BH,
                            "Enable heavy visualization capabilities");
      general.butt[20]->type(FL_TOGGLE_BUTTON);
      general.butt[20]->callback(general_options_ok_cb);
#endif

      Fl_Button *b2 = new Fl_Button(L + 2 * WB, 2 * WB + 11 * BH, BW, BH,
                                    "Restore all options to default settings");
      b2->callback(options_restore_defaults_cb);
      if(CTX::instance()->guiColorScheme)
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

      general.butt[16] = new Fl_Check_Button(
        L + width - (int)(0.85 * IW) - 2 * WB, 2 * WB + 1 * BH,
        (int)(0.85 * IW), BH, "Mikado style");
      general.butt[16]->tooltip("General.AxesMikado");
      general.butt[16]->type(FL_TOGGLE_BUTTON);
      general.butt[16]->callback(general_options_ok_cb);

      general.value[17] =
        new Fl_Value_Input(L + 2 * WB, 2 * WB + 2 * BH, IW / 3, BH);
      general.value[17]->tooltip("General.AxesTicsX");
      general.value[17]->minimum(0.);
      if(CTX::instance()->inputScrolling) general.value[17]->step(1);
      general.value[17]->maximum(100);
      general.value[17]->callback(general_options_ok_cb);
      general.value[18] = new Fl_Value_Input(L + 2 * WB + 1 * IW / 3,
                                             2 * WB + 2 * BH, IW / 3, BH);
      general.value[18]->tooltip("General.AxesTicsY");
      general.value[18]->minimum(0.);
      if(CTX::instance()->inputScrolling) general.value[18]->step(1);
      general.value[18]->maximum(100);
      general.value[18]->callback(general_options_ok_cb);
      general.value[19] = new Fl_Value_Input(
        L + 2 * WB + 2 * IW / 3, 2 * WB + 2 * BH, IW / 3, BH, "Axes tics");
      general.value[19]->tooltip("General.AxesTicsZ");
      general.value[19]->minimum(0.);
      if(CTX::instance()->inputScrolling) general.value[19]->step(1);
      general.value[19]->maximum(100);
      general.value[19]->align(FL_ALIGN_RIGHT);
      general.value[19]->callback(general_options_ok_cb);

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
        new Fl_Check_Button(L + 2 * WB, 2 * WB + 5 * BH, BW, BH,
                            "Set position and size of axes automatically");
      general.butt[0]->tooltip("General.AxesAutoPosition");
      general.butt[0]->type(FL_TOGGLE_BUTTON);
      general.butt[0]->callback(general_options_ok_cb,
                                (void *)"general_axes_auto");

      general.value[20] =
        new Fl_Value_Input(L + 2 * WB, 2 * WB + 6 * BH, IW / 3, BH);
      general.value[20]->callback(general_options_ok_cb);
      general.value[20]->tooltip("General.AxesMinX");
      general.value[21] =
        new Fl_Value_Input(L + 2 * WB + IW / 3, 2 * WB + 6 * BH, IW / 3, BH);
      general.value[21]->tooltip("General.AxesMinY");
      general.value[21]->callback(general_options_ok_cb);
      general.value[22] = new Fl_Value_Input(
        L + 2 * WB + 2 * IW / 3, 2 * WB + 6 * BH, IW / 3, BH, "Axes minimum");
      general.value[22]->tooltip("General.AxesMinZ");
      general.value[22]->align(FL_ALIGN_RIGHT);
      general.value[22]->callback(general_options_ok_cb);

      general.value[23] =
        new Fl_Value_Input(L + 2 * WB, 2 * WB + 7 * BH, IW / 3, BH);
      general.value[23]->tooltip("General.AxesMaxX");
      general.value[23]->callback(general_options_ok_cb);
      general.value[24] =
        new Fl_Value_Input(L + 2 * WB + IW / 3, 2 * WB + 7 * BH, IW / 3, BH);
      general.value[24]->tooltip("General.AxesMaxY");
      general.value[24]->callback(general_options_ok_cb);
      general.value[25] = new Fl_Value_Input(
        L + 2 * WB + 2 * IW / 3, 2 * WB + 7 * BH, IW / 3, BH, "Axes maximum");
      general.value[25]->tooltip("General.AxesMaxZ");
      general.value[25]->align(FL_ALIGN_RIGHT);
      general.value[25]->callback(general_options_ok_cb);

      general.push[1] =
        new Fl_Button(L + 2 * WB, 2 * WB + 8 * BH, IW, BH, "Fit to visible");
      general.push[1]->callback(general_options_axes_fit_cb);

      general.butt[1] = new Fl_Check_Button(L + 2 * WB, 2 * WB + 9 * BH, BW, BH,
                                            "Show small axes");
      general.butt[1]->tooltip("General.SmallAxes (Alt+Shift+a)");
      general.butt[1]->type(FL_TOGGLE_BUTTON);
      general.butt[1]->callback(general_options_ok_cb,
                                (void *)"general_small_axes");

      general.value[26] =
        new Fl_Value_Input(L + 2 * WB, 2 * WB + 10 * BH, IW / 2, BH);
      general.value[26]->tooltip("General.SmallAxesPositionX");
      general.value[26]->minimum(-2000);
      general.value[26]->maximum(2000);
      if(CTX::instance()->inputScrolling) general.value[26]->step(1);
      general.value[26]->callback(general_options_ok_cb);
      general.value[27] =
        new Fl_Value_Input(L + 2 * WB + IW / 2, 2 * WB + 10 * BH, IW / 2, BH,
                           "Small axes position");
      general.value[26]->tooltip("General.SmallAxesPositionY");
      general.value[27]->align(FL_ALIGN_RIGHT);
      general.value[27]->minimum(-2000);
      general.value[27]->maximum(2000);
      if(CTX::instance()->inputScrolling) general.value[27]->step(1);
      general.value[27]->callback(general_options_ok_cb);

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

      general.value[14] = new Fl_Value_Input(L + 2 * WB, 2 * WB + 2 * BH, IW,
                                             BH, "Z-clipping distance factor");
      general.value[14]->tooltip("General.ClipFactor");
      general.value[14]->minimum(0.1);
      general.value[14]->maximum(20.);
      if(CTX::instance()->inputScrolling) general.value[14]->step(0.1);
      general.value[14]->align(FL_ALIGN_RIGHT);
      general.value[14]->callback(general_options_ok_cb);

      general.value[15] =
        new Fl_Value_Input(L + 2 * WB, 2 * WB + 3 * BH, IW / 2, BH);
      general.value[15]->tooltip("General.PolygonOffsetFactor");
      general.value[15]->minimum(0.);
      general.value[15]->maximum(10.);
      if(CTX::instance()->inputScrolling) general.value[15]->step(0.01);
      general.value[15]->align(FL_ALIGN_RIGHT);
      general.value[15]->callback(general_options_ok_cb);

      general.value[16] =
        new Fl_Value_Input(L + 2 * WB + IW / 2, 2 * WB + 3 * BH, IW / 2, BH,
                           "Polygon offset factor/units");
      general.value[16]->tooltip("General.PolygonOffsetUnits");
      general.value[16]->minimum(0.);
      general.value[16]->maximum(10.);
      if(CTX::instance()->inputScrolling) general.value[16]->step(0.01);
      general.value[16]->align(FL_ALIGN_RIGHT);
      general.value[16]->callback(general_options_ok_cb);

      general.butt[4] = new Fl_Check_Button(L + 2 * WB, 2 * WB + 4 * BH, BW, BH,
                                            "Always apply polygon offset");
      general.butt[4]->tooltip("General.PolygonOffsetAlwaysOn");
      general.butt[4]->type(FL_TOGGLE_BUTTON);
      general.butt[4]->callback(general_options_ok_cb);

      general.value[11] = new Fl_Value_Input(L + 2 * WB, 2 * WB + 5 * BH, IW,
                                             BH, "Quadric subdivisions");
      general.value[11]->tooltip("General.QuadricSubdivisions");
      general.value[11]->minimum(3);
      general.value[11]->maximum(30);
      if(CTX::instance()->inputScrolling) general.value[11]->step(1);
      general.value[11]->align(FL_ALIGN_RIGHT);
      general.value[11]->callback(general_options_ok_cb);

      general.value[6] =
        new Fl_Value_Input(L + 2 * WB, 2 * WB + 6 * BH, IW, BH, "Point size");
      general.value[6]->minimum(0.1);
      general.value[6]->maximum(50);
      if(CTX::instance()->inputScrolling) general.value[6]->step(0.1);
      general.value[6]->align(FL_ALIGN_RIGHT);
      general.value[6]->callback(general_options_ok_cb);

      general.value[7] =
        new Fl_Value_Input(L + 2 * WB, 2 * WB + 7 * BH, IW, BH, "Line width");
      general.value[7]->tooltip("General.PointSize");
      general.value[7]->minimum(0.1);
      general.value[7]->maximum(50);
      if(CTX::instance()->inputScrolling) general.value[7]->step(0.1);
      general.value[7]->align(FL_ALIGN_RIGHT);
      general.value[7]->callback(general_options_ok_cb);

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
        {"Cairo", 0, nullptr, nullptr
#if !defined(HAVE_CAIRO)
         ,
         FL_MENU_INACTIVE
#endif
        },
        {"StringTexture", 0, nullptr, nullptr},
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
      general.value[12] = new Fl_Value_Input(L + 2 * WB + w1, 2 * WB + 10 * BH,
                                             w2, BH, "Default font");
      general.value[12]->tooltip("General.GraphicsFontSize");
      general.value[12]->minimum(5);
      general.value[12]->maximum(40);
      if(CTX::instance()->inputScrolling) general.value[12]->step(1);
      general.value[12]->align(FL_ALIGN_RIGHT);
      general.value[12]->callback(general_options_ok_cb);

      general.choice[6] = new Fl_Choice(L + 2 * WB, 2 * WB + 11 * BH, w1, BH);
      general.choice[6]->tooltip("General.GraphicsFontTitle");
      general.choice[6]->menu(menu_font_names);
      general.choice[6]->align(FL_ALIGN_RIGHT);
      general.choice[6]->callback(general_options_ok_cb);
      general.value[28] = new Fl_Value_Input(L + 2 * WB + w1, 2 * WB + 11 * BH,
                                             w2, BH, "Title font");
      general.value[28]->tooltip("General.GraphicsFontSizeTitle");
      general.value[28]->minimum(5);
      general.value[28]->maximum(40);
      if(CTX::instance()->inputScrolling) general.value[28]->step(1);
      general.value[28]->align(FL_ALIGN_RIGHT);
      general.value[28]->callback(general_options_ok_cb);

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Color");
      o->hide();

      general.value[2] =
        new Fl_Value_Input(L + 2 * WB, 2 * WB + 1 * BH, IW / 3, BH);
      general.value[2]->tooltip("General.Light0X");
      general.value[2]->minimum(-1.);
      general.value[2]->maximum(1.);
      if(CTX::instance()->inputScrolling) general.value[2]->step(0.01);
      general.value[2]->callback(general_options_ok_cb, (void *)"light_value");

      general.value[3] =
        new Fl_Value_Input(L + 2 * WB + IW / 3, 2 * WB + 1 * BH, IW / 3, BH);
      general.value[3]->tooltip("General.Light0Y");
      general.value[3]->minimum(-1.);
      general.value[3]->maximum(1.);
      if(CTX::instance()->inputScrolling) general.value[3]->step(0.01);
      general.value[3]->callback(general_options_ok_cb, (void *)"light_value");

      general.value[4] = new Fl_Value_Input(
        L + 2 * WB + 2 * IW / 3, 2 * WB + 1 * BH, IW / 3, BH, "Light position");
      general.value[4]->tooltip("General.Light0Z");
      general.value[4]->minimum(-1.);
      general.value[4]->maximum(1.);
      if(CTX::instance()->inputScrolling) general.value[4]->step(0.01);
      general.value[4]->align(FL_ALIGN_RIGHT);
      general.value[4]->callback(general_options_ok_cb, (void *)"light_value");

      general.value[13] = new Fl_Value_Input(L + 2 * WB, 2 * WB + 2 * BH, IW,
                                             BH, "Light position divisor");
      general.value[13]->tooltip("General.Light0W");
      general.value[13]->minimum(0.);
      general.value[13]->maximum(1.);
      if(CTX::instance()->inputScrolling) general.value[13]->step(0.01);
      general.value[13]->align(FL_ALIGN_RIGHT);
      general.value[13]->callback(general_options_ok_cb);

      general.sphere = new spherePositionWidget(L + width - 2 * BH - 2 * WB,
                                                2 * WB + 1 * BH, 2 * BH);
      general.sphere->callback(general_options_ok_cb, (void *)"light_sphere");

      general.value[1] =
        new Fl_Value_Input(L + 2 * WB, 2 * WB + 3 * BH, IW / 2, BH);
      general.value[1]->tooltip("General.Shininess");
      general.value[1]->minimum(0);
      general.value[1]->maximum(10);
      if(CTX::instance()->inputScrolling) general.value[1]->step(0.1);
      general.value[1]->callback(general_options_ok_cb);
      general.value[0] =
        new Fl_Value_Input(L + 2 * WB + IW / 2, 2 * WB + 3 * BH, IW / 2, BH,
                           "Material shininess/exponent");
      general.value[0]->tooltip("General.ShininessExponent");
      general.value[0]->minimum(0);
      general.value[0]->maximum(128);
      if(CTX::instance()->inputScrolling) general.value[0]->step(1);
      general.value[0]->align(FL_ALIGN_RIGHT);
      general.value[0]->callback(general_options_ok_cb);

      static Fl_Menu_Item menu_color_scheme[] = {
        {"Light", 0, nullptr, nullptr},
        {"Default", 0, nullptr, nullptr},
        {"Grayscale", 0, nullptr, nullptr},
        {"Dark", 0, nullptr, nullptr},
        {nullptr}};

      general.choice[3] = new Fl_Choice(L + 2 * WB, 2 * WB + 4 * BH, IW, BH,
                                        "Predefined color scheme");
      general.choice[3]->tooltip("General.ColorScheme (Alt+c)");
      general.choice[3]->menu(menu_color_scheme);
      general.choice[3]->align(FL_ALIGN_RIGHT);
      general.choice[3]->callback(general_options_color_scheme_cb);

      static Fl_Menu_Item menu_bg_grad[] = {{"None", 0, nullptr, nullptr},
                                            {"Vertical", 0, nullptr, nullptr},
                                            {"Horizontal", 0, nullptr, nullptr},
                                            {"Radial", 0, nullptr, nullptr},
                                            {nullptr}};

      general.choice[5] = new Fl_Choice(L + 2 * WB, 2 * WB + 5 * BH, IW, BH,
                                        "Background gradient");
      general.choice[5]->tooltip("General.BackgroundGradient");
      general.choice[5]->menu(menu_bg_grad);
      general.choice[5]->align(FL_ALIGN_RIGHT);
      general.choice[5]->callback(general_options_ok_cb);

      Fl_Scroll *s = new Fl_Scroll(L + 2 * WB, 3 * WB + 6 * BH, IW + 20,
                                   height - 5 * WB - 6 * BH);
      std::size_t i = 0, j = 0;
      while(GeneralOptions_Color[j].str) {
        if(GeneralOptions_Color[j].level & GMSH_DEPRECATED) {
          j++;
          continue;
        }
        general.color[i] = new Fl_Button(L + 2 * WB, 3 * WB + (6 + i) * BH, IW,
                                         BH, GeneralOptions_Color[j].str);
        general.color[i]->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE |
                                FL_ALIGN_CLIP);
        general.color[i]->callback(color_cb,
                                   (void *)GeneralOptions_Color[j].function);
        i++;
        j++;
        if(i >= general.color.size()) {
          Msg::Error("General color widget vector should be resized");
          break;
        }
      }
      s->end();

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Camera");
      o->hide();

      general.butt[18] = new Fl_Check_Button(
        L + 2 * WB, 2 * WB + 1 * BH, BW, BH, "Enable camera (experimental)");
      general.butt[18]->tooltip("General.Camera");
      general.butt[18]->type(FL_TOGGLE_BUTTON);
      general.butt[18]->value(opt_general_camera_mode(0, GMSH_GET, 0));
      general.butt[18]->callback(general_options_ok_cb,
                                 (void *)"general_camera");

      general.butt[17] =
        new Fl_Check_Button(L + 2 * WB, 2 * WB + 2 * BH, BW, BH,
                            "Enable stereo rendering (experimental)");
      general.butt[17]->tooltip("General.Stereo");
      general.butt[17]->type(FL_TOGGLE_BUTTON);
      general.butt[17]->value(opt_general_stereo_mode(0, GMSH_GET, 0));
      general.butt[17]->callback(general_options_ok_cb);

      general.value[29] = new Fl_Value_Input(L + 2 * WB, 2 * WB + 3 * BH, IW,
                                             BH, "Eye separation ratio (%)");
      general.value[29]->tooltip("General.CameraEyeSeparationRatio");
      general.value[29]->minimum(0.1);
      general.value[29]->maximum(10.);
      if(CTX::instance()->inputScrolling) general.value[29]->step(.1);
      general.value[29]->value(CTX::instance()->eye_sep_ratio);
      general.value[29]->align(FL_ALIGN_RIGHT);
      general.value[29]->callback(general_options_ok_cb);

      general.value[30] = new Fl_Value_Input(L + 2 * WB, 2 * WB + 4 * BH, IW,
                                             BH, "Focal length ratio (%)");
      general.value[30]->tooltip("General.CameraFocalLengthRatio");
      general.value[30]->minimum(0.1);
      general.value[30]->maximum(10.);
      if(CTX::instance()->inputScrolling) general.value[30]->step(.1);
      general.value[30]->value(CTX::instance()->focallength_ratio);
      general.value[30]->align(FL_ALIGN_RIGHT);
      general.value[30]->callback(general_options_ok_cb);

      general.value[31] = new Fl_Value_Input(L + 2 * WB, 2 * WB + 5 * BH, IW,
                                             BH, "Camera Aperture (degrees)");
      general.value[31]->tooltip("General.CameraAperture");
      general.value[31]->minimum(10.);
      general.value[31]->maximum(120.);
      if(CTX::instance()->inputScrolling) general.value[31]->step(1);
      general.value[31]->value(CTX::instance()->camera_aperture);
      general.value[31]->align(FL_ALIGN_RIGHT);
      general.value[31]->callback(general_options_ok_cb);

      general.butt[19] = new Fl_Check_Button(
        L + 2 * WB, 2 * WB + 7 * BH, BW, BH, "Enable gamepad (experimental)");
      general.butt[19]->type(FL_TOGGLE_BUTTON);
      general.butt[19]->value(opt_general_gamepad(0, GMSH_GET, 0));
      general.butt[19]->callback(general_options_ok_cb,
                                 (void *)"general_camera");

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
    o->end();
  }

  general.group->end();

  // Geometry options
  geo.group = new Fl_Group(L, 0, width, height, "Geometry Options");
  geo.group->hide();
  {
    Fl_Tabs *o = new Fl_Tabs(L + WB, WB, width - 2 * WB, height - 2 * WB);
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "General");
      o->hide();

      geo.value[2] = new Fl_Value_Input(L + 2 * WB, 2 * WB + 1 * BH, IW, BH,
                                        "Geometry tolerance");
      geo.value[2]->tooltip("Geometry.Tolerance");
      geo.value[2]->align(FL_ALIGN_RIGHT);
      geo.value[2]->callback(geometry_options_ok_cb);

      geo.butt[8] = new Fl_Check_Button(
        L + 2 * WB, 2 * WB + 2 * BH, BW, BH,
        "Remove duplicate entities in GEO model transforms");
      geo.butt[8]->tooltip("Geometry.AutoCoherence");
      geo.butt[8]->type(FL_TOGGLE_BUTTON);
      geo.butt[8]->callback(geometry_options_ok_cb);

      Fl_Box *b = new Fl_Box(L + 2 * WB, 2 * WB + 3 * BH, BW, 2);
      b->box(FL_ENGRAVED_FRAME);
      b->labeltype(FL_NO_LABEL);

      Fl_Box *b2 = new Fl_Box(FL_NO_BOX, L + 2 * WB, 2 * WB + 3 * BH + 1, IW,
                              BH, "Open CASCADE model healing options:");
      b2->align(FL_ALIGN_INSIDE | FL_ALIGN_LEFT);

      geo.butt[16] = new Fl_Check_Button(L + 2 * WB, 2 * WB + 4 * BH, BW, BH,
                                         "Remove degenerated edges and faces");
      geo.butt[16]->tooltip("Geometry.OCCFixDegenerated");
      geo.butt[16]->type(FL_TOGGLE_BUTTON);
      geo.butt[16]->callback(geometry_options_ok_cb);

      geo.butt[11] = new Fl_Check_Button(L + 2 * WB, 2 * WB + 5 * BH, BW, BH,
                                         "Remove small edges");
      geo.butt[11]->tooltip("Geometry.OCCFixSmallEdges");
      geo.butt[11]->type(FL_TOGGLE_BUTTON);
      geo.butt[11]->callback(geometry_options_ok_cb);

      geo.butt[12] = new Fl_Check_Button(L + 2 * WB, 2 * WB + 6 * BH, BW, BH,
                                         "Remove small faces");
      geo.butt[12]->tooltip("Geometry.OCCFixSmallFaces");
      geo.butt[12]->type(FL_TOGGLE_BUTTON);
      geo.butt[12]->callback(geometry_options_ok_cb);

      geo.butt[13] =
        new Fl_Check_Button(L + 2 * WB, 2 * WB + 7 * BH, BW, BH, "Sew faces");
      geo.butt[13]->tooltip("Geometry.OCCFixSewFaces");
      geo.butt[13]->type(FL_TOGGLE_BUTTON);
      geo.butt[13]->callback(geometry_options_ok_cb);

      geo.butt[14] = new Fl_Check_Button(L + 2 * WB, 2 * WB + 8 * BH, BW, BH,
                                         "Fix shells and make solids");
      geo.butt[14]->tooltip("Geometry.OCCMakeSolids");
      geo.butt[14]->type(FL_TOGGLE_BUTTON);
      geo.butt[14]->callback(geometry_options_ok_cb);

      geo.value[20] = new Fl_Value_Input(L + 2 * WB, 2 * WB + 9 * BH, IW, BH,
                                         "Global model scaling");
      geo.value[20]->tooltip("Geometry.OCCScaling");
      geo.value[20]->align(FL_ALIGN_RIGHT);
      geo.value[20]->callback(geometry_options_ok_cb);

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

      geo.butt[0] = new Fl_Check_Button(L + 2 * WB, 2 * WB + 1 * BH,
                                        BW / 2 - WB, BH, "Points");
      geo.butt[0]->tooltip("Geometry.Points (Alt+p)");
      geo.butt[0]->type(FL_TOGGLE_BUTTON);
      geo.butt[0]->callback(geometry_options_ok_cb);

      geo.butt[1] = new Fl_Check_Button(L + 2 * WB, 2 * WB + 2 * BH,
                                        BW / 2 - WB, BH, "Curves");
      geo.butt[1]->tooltip("Geometry.Curves (Alt+l)");
      geo.butt[1]->type(FL_TOGGLE_BUTTON);
      geo.butt[1]->callback(geometry_options_ok_cb);

      geo.butt[2] = new Fl_Check_Button(L + 2 * WB, 2 * WB + 3 * BH,
                                        BW / 2 - WB, BH, "Surfaces");
      geo.butt[2]->tooltip("Geometry.Surfaces (Alt+s)");
      geo.butt[2]->type(FL_TOGGLE_BUTTON);
      geo.butt[2]->callback(geometry_options_ok_cb);

      geo.butt[3] = new Fl_Check_Button(L + 2 * WB, 2 * WB + 4 * BH,
                                        BW / 2 - WB, BH, "Volumes");
      geo.butt[3]->tooltip("Geometry.Volumes (Alt+v)");
      geo.butt[3]->type(FL_TOGGLE_BUTTON);
      geo.butt[3]->callback(geometry_options_ok_cb);

      geo.butt[4] = new Fl_Check_Button(L + width / 2, 2 * WB + 1 * BH,
                                        BW / 2 - WB, BH, "Point labels");
      geo.butt[4]->tooltip("Geometry.PointLabels");
      geo.butt[4]->type(FL_TOGGLE_BUTTON);
      geo.butt[4]->callback(geometry_options_ok_cb);

      geo.butt[5] = new Fl_Check_Button(L + width / 2, 2 * WB + 2 * BH,
                                        BW / 2 - WB, BH, "Curve labels");
      geo.butt[5]->tooltip("Geometry.CurveLabels");
      geo.butt[5]->type(FL_TOGGLE_BUTTON);
      geo.butt[5]->callback(geometry_options_ok_cb);

      geo.butt[6] = new Fl_Check_Button(L + width / 2, 2 * WB + 3 * BH,
                                        BW / 2 - WB, BH, "Surface labels");
      geo.butt[6]->tooltip("Geometry.SurfaceLabels");
      geo.butt[6]->type(FL_TOGGLE_BUTTON);
      geo.butt[6]->callback(geometry_options_ok_cb);

      geo.butt[7] = new Fl_Check_Button(L + width / 2, 2 * WB + 4 * BH,
                                        BW / 2 - WB, BH, "Volume labels");
      geo.butt[7]->tooltip("Geometry.VolumeLabels");
      geo.butt[7]->type(FL_TOGGLE_BUTTON);
      geo.butt[7]->callback(geometry_options_ok_cb);

      static Fl_Menu_Item menu_label_type[] = {
        {"Description", 0, nullptr, nullptr},
        {"Elementary tag", 0, nullptr, nullptr},
        {"Physical tag(s)", 0, nullptr, nullptr},
        {"Elementary name", 0, nullptr, nullptr},
        {"Physical name(s)", 0, nullptr, nullptr},
        {nullptr}};
      geo.choice[4] =
        new Fl_Choice(L + 2 * WB, 2 * WB + 5 * BH, IW, BH, "Label type");
      geo.choice[4]->tooltip("Geometry.LabelType");
      geo.choice[4]->menu(menu_label_type);
      geo.choice[4]->align(FL_ALIGN_RIGHT);
      geo.choice[4]->callback(geometry_options_ok_cb);

      geo.value[0] =
        new Fl_Value_Input(L + 2 * WB, 2 * WB + 6 * BH, IW / 2, BH);
      geo.value[0]->tooltip("Geometry.Normals");
      geo.value[0]->minimum(0);
      geo.value[0]->maximum(500);
      if(CTX::instance()->inputScrolling) geo.value[0]->step(1);
      geo.value[0]->align(FL_ALIGN_RIGHT);
      geo.value[0]->when(FL_WHEN_RELEASE);
      geo.value[0]->callback(geometry_options_ok_cb);

      geo.value[1] = new Fl_Value_Input(L + 2 * WB + IW / 2, 2 * WB + 6 * BH,
                                        IW / 2, BH, "Normals and tangents");
      geo.value[1]->tooltip("Geometry.Tangents");
      geo.value[1]->minimum(0);
      geo.value[1]->maximum(500);
      if(CTX::instance()->inputScrolling) geo.value[1]->step(1);
      geo.value[1]->align(FL_ALIGN_RIGHT);
      geo.value[1]->when(FL_WHEN_RELEASE);
      geo.value[1]->callback(geometry_options_ok_cb);

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
      geo.value[7] = new Fl_Value_Input(L + 2 * WB, 2 * WB + 2 * BH, ss, BH);
      geo.value[7]->tooltip("Geometry.TransformXX");
      geo.value[8] =
        new Fl_Value_Input(L + 2 * WB + ss, 2 * WB + 2 * BH, ss, BH);
      geo.value[8]->tooltip("Geometry.TransformXY");
      geo.value[9] =
        new Fl_Value_Input(L + 2 * WB + 2 * ss, 2 * WB + 2 * BH, ss, BH, " X");
      geo.value[9]->tooltip("Geometry.TransformXZ");
      geo.value[10] =
        new Fl_Value_Input(L + 2 * WB + IW, 2 * WB + 2 * BH, 7 * IW / 10, BH);
      geo.value[10]->tooltip("Geometry.OffsetX");

      geo.value[11] = new Fl_Value_Input(L + 2 * WB, 2 * WB + 3 * BH, ss, BH);
      geo.value[11]->tooltip("Geometry.TransformYX");
      geo.value[12] =
        new Fl_Value_Input(L + 2 * WB + ss, 2 * WB + 3 * BH, ss, BH);
      geo.value[12]->tooltip("Geometry.TransformYY");
      geo.value[13] = new Fl_Value_Input(L + 2 * WB + 2 * ss, 2 * WB + 3 * BH,
                                         ss, BH, " Y +");
      geo.value[13]->tooltip("Geometry.TransformYZ");
      geo.value[14] =
        new Fl_Value_Input(L + 2 * WB + IW, 2 * WB + 3 * BH, 7 * IW / 10, BH);
      geo.value[14]->tooltip("Geometry.OffsetY");

      geo.value[15] = new Fl_Value_Input(L + 2 * WB, 2 * WB + 4 * BH, ss, BH);
      geo.value[15]->tooltip("Geometry.TransformZX");
      geo.value[16] =
        new Fl_Value_Input(L + 2 * WB + ss, 2 * WB + 4 * BH, ss, BH);
      geo.value[16]->tooltip("Geometry.TransformZY");
      geo.value[17] =
        new Fl_Value_Input(L + 2 * WB + 2 * ss, 2 * WB + 4 * BH, ss, BH, " Z");
      geo.value[17]->tooltip("Geometry.TransformZZ");
      geo.value[18] =
        new Fl_Value_Input(L + 2 * WB + IW, 2 * WB + 4 * BH, 7 * IW / 10, BH);
      geo.value[18]->tooltip("Geometry.OffsetZ");

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
        new Fl_Value_Input(L + 2 * WB, 2 * WB + 2 * BH, IW, BH, "Point size");
      geo.value[3]->tooltip("Geometry.PointSize");
      geo.value[3]->minimum(0.1);
      geo.value[3]->maximum(50);
      if(CTX::instance()->inputScrolling) geo.value[3]->step(0.1);
      geo.value[3]->align(FL_ALIGN_RIGHT);
      geo.value[3]->callback(geometry_options_ok_cb);

      geo.value[5] = new Fl_Value_Input(L + 2 * WB, 2 * WB + 3 * BH, IW, BH,
                                        "Selected point size");
      geo.value[5]->tooltip("Geometry.PointSelectSize");
      geo.value[5]->minimum(0.1);
      geo.value[5]->maximum(50);
      if(CTX::instance()->inputScrolling) geo.value[5]->step(0.1);
      geo.value[5]->align(FL_ALIGN_RIGHT);
      geo.value[5]->callback(geometry_options_ok_cb);

      geo.choice[1] =
        new Fl_Choice(L + 2 * WB, 2 * WB + 4 * BH, IW, BH, "Curve display");
      geo.choice[1]->tooltip("Geometry.CurveType");
      geo.choice[1]->menu(menu_line_display);
      geo.choice[1]->align(FL_ALIGN_RIGHT);
      geo.choice[1]->callback(geometry_options_ok_cb);

      geo.value[4] =
        new Fl_Value_Input(L + 2 * WB, 2 * WB + 5 * BH, IW, BH, "Curve width");
      geo.value[4]->tooltip("Geometry.CurveWidth");
      geo.value[4]->minimum(0.1);
      geo.value[4]->maximum(50);
      if(CTX::instance()->inputScrolling) geo.value[4]->step(0.1);
      geo.value[4]->align(FL_ALIGN_RIGHT);
      geo.value[4]->callback(geometry_options_ok_cb);

      geo.value[6] = new Fl_Value_Input(L + 2 * WB, 2 * WB + 6 * BH, IW, BH,
                                        "Selected curve width");
      geo.value[6]->tooltip("Geometry.CurveSelectWidth");
      geo.value[6]->minimum(0.1);
      geo.value[6]->maximum(50);
      if(CTX::instance()->inputScrolling) geo.value[6]->step(0.1);
      geo.value[6]->align(FL_ALIGN_RIGHT);
      geo.value[6]->callback(geometry_options_ok_cb);

      geo.value[19] = new Fl_Value_Input(L + 2 * WB, 2 * WB + 7 * BH, IW, BH,
                                         "Curve subdivisions");
      geo.value[19]->tooltip("Geometry.NumSubEdges");
      geo.value[19]->minimum(1);
      geo.value[19]->maximum(50);
      if(CTX::instance()->inputScrolling) geo.value[19]->step(1);
      geo.value[19]->align(FL_ALIGN_RIGHT);
      geo.value[19]->callback(geometry_options_ok_cb);

      geo.choice[2] =
        new Fl_Choice(L + 2 * WB, 2 * WB + 8 * BH, IW, BH, "Surface display");
      geo.choice[2]->tooltip("Geometry.SurfaceType (Alt+d)");
      geo.choice[2]->menu(menu_surface_display);
      geo.choice[2]->align(FL_ALIGN_RIGHT);
      geo.choice[2]->callback(geometry_options_ok_cb);

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Color");
      o->hide();

      geo.butt[9] = new Fl_Check_Button(L + 2 * WB, 2 * WB + 1 * BH, BW, BH,
                                        "Enable lighting");
      geo.butt[9]->tooltip("Geometry.Light (Alt+w)");
      geo.butt[9]->type(FL_TOGGLE_BUTTON);
      geo.butt[9]->callback(geometry_options_ok_cb);

      geo.butt[15] = new Fl_Check_Button(L + 2 * WB, 2 * WB + 2 * BH, BW, BH,
                                         "Use two-side lighting");
      geo.butt[15]->tooltip("Geometry.LightTwoSide");
      geo.butt[15]->type(FL_TOGGLE_BUTTON);
      geo.butt[15]->callback(geometry_options_ok_cb);

      geo.butt[10] = new Fl_Check_Button(L + 2 * WB, 2 * WB + 3 * BH, BW, BH,
                                         "Highlight orphan entities");
      geo.butt[10]->tooltip("Geometry.HighlightOrphans");
      geo.butt[10]->type(FL_TOGGLE_BUTTON);
      geo.butt[10]->callback(geometry_options_ok_cb);

      Fl_Scroll *s = new Fl_Scroll(L + 2 * WB, 2 * WB + 4 * BH, IW + 20,
                                   height - 4 * WB - 4 * BH);
      std::size_t i = 0, j = 0;
      while(GeometryOptions_Color[j].str) {
        if(GeometryOptions_Color[j].level & GMSH_DEPRECATED) {
          j++;
          continue;
        }
        geo.color[i] = new Fl_Button(L + 2 * WB, 2 * WB + (4 + i) * BH, IW, BH,
                                     GeometryOptions_Color[j].str);
        geo.color[i]->callback(color_cb,
                               (void *)GeometryOptions_Color[j].function);
        i++;
        j++;
        if(i >= geo.color.size()) {
          Msg::Error("Geometry color widget vector should be resized");
          break;
        }
      }
      s->end();

      o->end();
    }
    o->end();
  }
  geo.group->end();

  // Mesh options
  mesh.group = new Fl_Group(L, 0, width, height, "Mesh Options");
  mesh.group->hide();
  {
    Fl_Tabs *o = new Fl_Tabs(L + WB, WB, width - 2 * WB, height - 2 * WB);
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "General");
      o->hide();

      static Fl_Menu_Item menu_2d_algo[] = {
        {"Automatic", 0, nullptr, nullptr},
        {"MeshAdapt", 0, nullptr, nullptr},
        {"Delaunay", 0, nullptr, nullptr},
        {"Frontal-Delaunay", 0, nullptr, nullptr},
        {"BAMG (experimental)", 0, nullptr, nullptr},
        {"Frontal-Delaunay for Quads (experimental)", 0, nullptr, nullptr},
        {"Packing of Parallelograms (experimental, planar only)", 0, nullptr,
         nullptr},
        {"Initial Mesh Only (no node insertion)", 0, nullptr, nullptr},
        {nullptr}};
      static Fl_Menu_Item menu_3d_algo[] = {
        {"Delaunay", 0, nullptr, nullptr},
        {"Frontal", 0, nullptr, nullptr},
        {"HXT (experimental)", 0, nullptr, nullptr},
        {"MMG3D (experimental, single volume only)", 0, nullptr, nullptr},
        {"Initial Mesh Only (no node insertion)", 0, nullptr, nullptr},
        {nullptr}};
      static Fl_Menu_Item menu_recombination_algo[] = {
        {"Simple", 0, nullptr, nullptr},
        {"Blossom", 0, nullptr, nullptr},
        {"Simple Full-Quad", 0, nullptr, nullptr},
        {"Blossom Full-Quad", 0, nullptr, nullptr},
        {nullptr}};
      static Fl_Menu_Item menu_subdivision_algo[] = {
        {"None", 0, nullptr, nullptr},
        {"All Quads", 0, nullptr, nullptr},
        {"All Hexas", 0, nullptr, nullptr},
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

      mesh.butt[21] = new Fl_Check_Button(L + 2 * WB, 2 * WB + 4 * BH, BW, BH,
                                          "Recombine all triangular meshes");
      mesh.butt[21]->tooltip("Mesh.RecombineAll");
      mesh.butt[21]->type(FL_TOGGLE_BUTTON);
      mesh.butt[21]->callback(mesh_options_ok_cb);

      mesh.choice[5] = new Fl_Choice(L + 2 * WB, 2 * WB + 5 * BH, IW, BH,
                                     "Subdivision algorithm");
      mesh.choice[5]->tooltip("Mesh.SubdivisionAlgorithm");
      mesh.choice[5]->menu(menu_subdivision_algo);
      mesh.choice[5]->align(FL_ALIGN_RIGHT);
      mesh.choice[5]->callback(mesh_options_ok_cb);

      mesh.value[0] = new Fl_Value_Input(L + 2 * WB, 2 * WB + 6 * BH, IW, BH,
                                         "Smoothing steps");
      mesh.value[0]->tooltip("Mesh.Smoothing");
      mesh.value[0]->minimum(0);
      mesh.value[0]->maximum(100);
      if(CTX::instance()->inputScrolling) mesh.value[0]->step(1);
      mesh.value[0]->align(FL_ALIGN_RIGHT);
      mesh.value[0]->callback(mesh_options_ok_cb);

      mesh.value[2] = new inputValueFloat(L + 2 * WB, 2 * WB + 7 * BH, IW, BH,
                                          "Element size factor");
      mesh.value[2]->tooltip("Mesh.MeshSizeFactor");
      mesh.value[2]->minimum(0.001);
      mesh.value[2]->maximum(1000);
      if(CTX::instance()->inputScrolling) mesh.value[2]->step(0.01);
      mesh.value[2]->align(FL_ALIGN_RIGHT);
      mesh.value[2]->callback(mesh_options_ok_cb);

      mesh.value[25] =
        new Fl_Value_Input(L + 2 * WB, 2 * WB + 8 * BH, IW / 2, BH);
      mesh.value[25]->tooltip("Mesh.MeshSizeMin");
      mesh.value[25]->align(FL_ALIGN_RIGHT);
      mesh.value[25]->callback(mesh_options_ok_cb);

      mesh.value[26] = new Fl_Value_Input(L + 2 * WB + IW / 2, 2 * WB + 8 * BH,
                                          IW / 2, BH, "Min/Max element size");
      mesh.value[26]->tooltip("Mesh.MeshSizeMax");
      mesh.value[26]->align(FL_ALIGN_RIGHT);
      mesh.value[26]->callback(mesh_options_ok_cb);

      mesh.value[3] = new Fl_Value_Input(L + 2 * WB, 2 * WB + 9 * BH, IW / 3,
                                         BH, "Element order");
      mesh.value[3]->tooltip("Mesh.ElementOrder");
      mesh.value[3]->minimum(1);
      mesh.value[3]->maximum(2);
      if(CTX::instance()->inputScrolling) mesh.value[3]->step(1);
      mesh.value[3]->align(FL_ALIGN_RIGHT);
      mesh.value[3]->callback(mesh_options_ok_cb);

      mesh.butt[4] =
        new Fl_Check_Button(L + 2 * WB + 1.25 * IW, 2 * WB + 9 * BH, BW, BH,
                            "Use incomplete elements");
      mesh.butt[4]->tooltip("Mesh.SecondOrderIncomplete");
      mesh.butt[4]->type(FL_TOGGLE_BUTTON);
      mesh.butt[4]->callback(mesh_options_ok_cb);

      o->end();
    }

    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Advanced");
      o->hide();

      mesh.butt[5] =
        new Fl_Check_Button(L + 2 * WB, 2 * WB + 1 * BH, BW, BH,
                            "Compute element sizes using point values");
      mesh.butt[5]->tooltip("Mesh.MeshSizeFromPoints");
      mesh.butt[5]->type(FL_TOGGLE_BUTTON);
      mesh.butt[5]->callback(mesh_options_ok_cb);

      mesh.butt[26] = new Fl_Check_Button(
        L + 2 * WB, 2 * WB + 2 * BH, BW, BH,
        "Compute element sizes using parametric point values");
      mesh.butt[26]->tooltip("Mesh.MeshSizeFromParametricPoints");
      mesh.butt[26]->type(FL_TOGGLE_BUTTON);
      mesh.butt[26]->callback(mesh_options_ok_cb);

      mesh.value[1] =
        new Fl_Value_Input(L + 2 * WB, 2 * WB + 3 * BH, IW / 2, BH,
                           "Compute element sizes from curvature");
      mesh.value[1]->tooltip("Mesh.MeshSizeFromCurvature (number of elements "
                             "per 2 * Pi radians)");
      mesh.value[1]->minimum(0);
      mesh.value[1]->maximum(50);
      if(CTX::instance()->inputScrolling) mesh.value[1]->step(1);
      mesh.value[1]->align(FL_ALIGN_RIGHT);
      mesh.value[1]->callback(mesh_options_ok_cb);

      mesh.butt[16] = new Fl_Check_Button(L + 2 * WB, 2 * WB + 4 * BH, BW, BH,
                                          "Extend element sizes from boundary");
      mesh.butt[16]->tooltip("Mesh.MeshSizeExtendFromBoundary");
      mesh.butt[16]->type(FL_TOGGLE_BUTTON);
      mesh.butt[16]->callback(mesh_options_ok_cb);

      mesh.butt[2] = new Fl_Check_Button(L + 2 * WB, 2 * WB + 5 * BH, BW, BH,
                                         "Optimize quality of tetrahedra");
      mesh.butt[2]->tooltip("Mesh.Optimize");
      mesh.butt[2]->type(FL_TOGGLE_BUTTON);
      mesh.butt[2]->callback(mesh_options_ok_cb);

      mesh.butt[24] =
        new Fl_Check_Button(L + 2 * WB, 2 * WB + 6 * BH, BW, BH,
                            "Optimize quality of tetrahedra with Netgen");
      mesh.butt[24]->tooltip("Mesh.OptimizeNetgen");
      mesh.butt[24]->type(FL_TOGGLE_BUTTON);
#if !defined(HAVE_NETGEN)
      mesh.butt[24]->deactivate();
#endif
      mesh.butt[24]->callback(mesh_options_ok_cb);

      mesh.butt[3] = new Fl_Check_Button(L + 2 * WB, 2 * WB + 7 * BH, BW, BH,
                                         "Optimize high-order meshes");
      mesh.butt[3]->tooltip("Mesh.HighOrderOptimize");
      mesh.butt[3]->type(FL_TOGGLE_BUTTON);
      mesh.butt[3]->callback(mesh_options_ok_cb);

      o->end();
    }

    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Visibility");

      mesh.butt[6] = new Fl_Check_Button(L + 2 * WB, 2 * WB + 1 * BH,
                                         BW / 2 - WB, BH, "Nodes");
      mesh.butt[6]->tooltip("Mesh.Points (Alt+Shift+p)");
      mesh.butt[6]->type(FL_TOGGLE_BUTTON);
      mesh.butt[6]->callback(mesh_options_ok_cb);

      mesh.butt[7] = new Fl_Check_Button(L + 2 * WB, 2 * WB + 2 * BH,
                                         BW / 2 - WB, BH, "1D elements");
      mesh.butt[7]->tooltip("Mesh.Lines (Alt+Shift+l)");
      mesh.butt[7]->type(FL_TOGGLE_BUTTON);
      mesh.butt[7]->callback(mesh_options_ok_cb);

      mesh.butt[8] = new Fl_Check_Button(L + 2 * WB, 2 * WB + 3 * BH,
                                         BW / 2 - WB, BH, "2D element edges");
      mesh.butt[8]->tooltip("Mesh.SurfaceEdges (Alt+Shift+s)");
      mesh.butt[8]->type(FL_TOGGLE_BUTTON);
      mesh.butt[8]->callback(mesh_options_ok_cb);

      mesh.butt[9] = new Fl_Check_Button(L + 2 * WB, 2 * WB + 4 * BH,
                                         BW / 2 - WB, BH, "2D element faces");
      mesh.butt[9]->tooltip("Mesh.SurfaceFaces (Alt+Shift+d)");
      mesh.butt[9]->type(FL_TOGGLE_BUTTON);
      mesh.butt[9]->callback(mesh_options_ok_cb);

      mesh.butt[10] = new Fl_Check_Button(L + 2 * WB, 2 * WB + 5 * BH,
                                          BW / 2 - WB, BH, "3D element edges");
      mesh.butt[10]->tooltip("Mesh.VolumeEdges (Alt+Shift+v)");
      mesh.butt[10]->type(FL_TOGGLE_BUTTON);
      mesh.butt[10]->callback(mesh_options_ok_cb);

      mesh.butt[11] = new Fl_Check_Button(L + 2 * WB, 2 * WB + 6 * BH,
                                          BW / 2 - WB, BH, "3D element faces");
      mesh.butt[11]->tooltip("Mesh.VolumeFaces (Alt+Shift+b)");
      mesh.butt[11]->type(FL_TOGGLE_BUTTON);
      mesh.butt[11]->callback(mesh_options_ok_cb);

      mesh.butt[12] = new Fl_Check_Button(L + width / 2, 2 * WB + 1 * BH,
                                          BW / 2 - WB, BH, "Node labels");
      mesh.butt[12]->tooltip("Mesh.NodeLabels");
      mesh.butt[12]->type(FL_TOGGLE_BUTTON);
      mesh.butt[12]->callback(mesh_options_ok_cb);

      mesh.butt[13] = new Fl_Check_Button(L + width / 2, 2 * WB + 2 * BH,
                                          BW / 2 - WB, BH, "1D element labels");
      mesh.butt[13]->tooltip("Mesh.LineLabels");
      mesh.butt[13]->type(FL_TOGGLE_BUTTON);
      mesh.butt[13]->callback(mesh_options_ok_cb);

      mesh.butt[14] = new Fl_Check_Button(L + width / 2, 2 * WB + 3 * BH,
                                          BW / 2 - WB, BH, "2D element labels");
      mesh.butt[14]->tooltip("Mesh.SurfaceLabels");
      mesh.butt[14]->type(FL_TOGGLE_BUTTON);
      mesh.butt[14]->callback(mesh_options_ok_cb);

      mesh.butt[15] = new Fl_Check_Button(L + width / 2, 2 * WB + 4 * BH,
                                          BW / 2 - WB, BH, "3D element labels");
      mesh.butt[15]->tooltip("Mesh.VolumeLabels");
      mesh.butt[15]->type(FL_TOGGLE_BUTTON);
      mesh.butt[15]->callback(mesh_options_ok_cb);

      static Fl_Menu_Item menu_label_type[] = {
        {"Node/element tag", 0, nullptr, nullptr},
        {"Elementary entity tag", 0, nullptr, nullptr},
        {"Physical group tag(s)", 0, nullptr, nullptr},
        {"Mesh partition", 0, nullptr, nullptr},
        {"Coordinates", 0, nullptr, nullptr},
        {nullptr}};
      mesh.choice[7] =
        new Fl_Choice(L + 2 * WB, 2 * WB + 7 * BH, IW, BH, "Label type");
      mesh.choice[7]->tooltip("Mesh.LabelType");
      mesh.choice[7]->menu(menu_label_type);
      mesh.choice[7]->align(FL_ALIGN_RIGHT);
      mesh.choice[7]->callback(mesh_options_ok_cb);

      mesh.value[12] =
        new Fl_Value_Input(L + width - (int)(0.85 * IW) - 2 * WB,
                           2 * WB + 7 * BH, IW / 3, BH, "Sampling");
      mesh.value[12]->tooltip("Mesh.LabelSampling");
      mesh.value[12]->minimum(1);
      mesh.value[12]->maximum(100);
      if(CTX::instance()->inputScrolling) mesh.value[12]->step(1);
      mesh.value[12]->align(FL_ALIGN_RIGHT);
      mesh.value[12]->when(FL_WHEN_RELEASE);
      mesh.value[12]->callback(mesh_options_ok_cb);

      static Fl_Menu_Item menu_mesh_element_types[] = {
        {"Triangles", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Quadrangles", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Tetrahedra", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Hexahedra", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Prisms", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Pyramids", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Trihedra", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {nullptr}};

      mesh.menu =
        new Fl_Menu_Button(L + 2 * WB, 2 * WB + 8 * BH, IW, BH, "Elements");
      mesh.menu->tooltip(
        "Mesh.Triangles, Mesh.Quadrangles, Mesh.Tetrahedra, "
        "Mesh.Hexahedra, Mesh.Prisms, Mesh.Pyramids, Mesh.Trihedra");
      mesh.menu->menu(menu_mesh_element_types);
      mesh.menu->callback(mesh_options_ok_cb);

      mesh.value[4] =
        new Fl_Value_Input(L + 2 * WB, 2 * WB + 9 * BH, IW / 4, BH);
      mesh.value[4]->tooltip("Mesh.QualityInf");
      mesh.value[4]->minimum(0);
      mesh.value[4]->maximum(1);
      if(CTX::instance()->inputScrolling) mesh.value[4]->step(0.01);
      mesh.value[4]->align(FL_ALIGN_RIGHT);
      mesh.value[4]->when(FL_WHEN_RELEASE);
      mesh.value[4]->callback(mesh_options_ok_cb);

      mesh.value[5] = new Fl_Value_Input(L + 2 * WB + IW / 4, 2 * WB + 9 * BH,
                                         IW / 2 - IW / 4, BH);
      mesh.value[5]->tooltip("Mesh.QualitySup");
      mesh.value[5]->minimum(0);
      mesh.value[5]->maximum(1);
      if(CTX::instance()->inputScrolling) mesh.value[5]->step(0.01);
      mesh.value[5]->align(FL_ALIGN_RIGHT);
      mesh.value[5]->when(FL_WHEN_RELEASE);
      mesh.value[5]->callback(mesh_options_ok_cb);

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

      mesh.value[6] =
        new Fl_Value_Input(L + 2 * WB, 2 * WB + 10 * BH, IW / 2, BH);
      mesh.value[6]->tooltip("Mesh.RadiusInf");
      mesh.value[6]->align(FL_ALIGN_RIGHT);
      mesh.value[6]->when(FL_WHEN_RELEASE);
      mesh.value[6]->callback(mesh_options_ok_cb);

      mesh.value[7] = new Fl_Value_Input(L + 2 * WB + IW / 2, 2 * WB + 10 * BH,
                                         IW / 2, BH, "Size range");
      mesh.value[7]->tooltip("Mesh.RadiusSup");
      mesh.value[7]->align(FL_ALIGN_RIGHT);
      mesh.value[7]->when(FL_WHEN_RELEASE);
      mesh.value[7]->callback(mesh_options_ok_cb);

      mesh.value[8] =
        new Fl_Value_Input(L + 2 * WB, 2 * WB + 11 * BH, IW / 2, BH);
      mesh.value[8]->tooltip("Mesh.Normals");
      mesh.value[8]->minimum(0);
      mesh.value[8]->maximum(500);
      if(CTX::instance()->inputScrolling) mesh.value[8]->step(1);
      mesh.value[8]->align(FL_ALIGN_RIGHT);
      mesh.value[8]->when(FL_WHEN_RELEASE);
      mesh.value[8]->callback(mesh_options_ok_cb);

      mesh.value[13] = new Fl_Value_Input(L + 2 * WB + IW / 2, 2 * WB + 11 * BH,
                                          IW / 2, BH, "Normals and tangents");
      mesh.value[13]->tooltip("Mesh.Tangents");
      mesh.value[13]->minimum(0);
      mesh.value[13]->maximum(200);
      if(CTX::instance()->inputScrolling) mesh.value[13]->step(1.0);
      mesh.value[13]->align(FL_ALIGN_RIGHT);
      mesh.value[13]->when(FL_WHEN_RELEASE);
      mesh.value[13]->callback(mesh_options_ok_cb);

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Aspect");
      o->hide();

      mesh.value[9] = new Fl_Value_Input(L + 2 * WB, 2 * WB + 1 * BH, IW, BH,
                                         "Element shrinking factor");
      mesh.value[9]->tooltip("Mesh.Explode");
      mesh.value[9]->minimum(0);
      mesh.value[9]->maximum(1);
      if(CTX::instance()->inputScrolling) mesh.value[9]->step(0.01);
      mesh.value[9]->align(FL_ALIGN_RIGHT);
      mesh.value[9]->when(FL_WHEN_RELEASE);
      mesh.value[9]->callback(mesh_options_ok_cb);

      mesh.choice[0] =
        new Fl_Choice(L + 2 * WB, 2 * WB + 2 * BH, IW, BH, "Point display");
      mesh.choice[0]->tooltip("Mesh.PointType");
      mesh.choice[0]->menu(menu_point_display);
      mesh.choice[0]->align(FL_ALIGN_RIGHT);
      mesh.choice[0]->callback(mesh_options_ok_cb);

      mesh.value[10] =
        new Fl_Value_Input(L + 2 * WB, 2 * WB + 3 * BH, IW, BH, "Point size");
      mesh.value[10]->tooltip("Mesh.PointSize");
      mesh.value[10]->minimum(0.1);
      mesh.value[10]->maximum(50);
      if(CTX::instance()->inputScrolling) mesh.value[10]->step(0.1);
      mesh.value[10]->align(FL_ALIGN_RIGHT);
      mesh.value[10]->callback(mesh_options_ok_cb);

      mesh.value[11] =
        new Fl_Value_Input(L + 2 * WB, 2 * WB + 4 * BH, IW, BH, "Line width");
      mesh.value[11]->tooltip("Mesh.LineWidth");
      mesh.value[11]->minimum(0.1);
      mesh.value[11]->maximum(50);
      if(CTX::instance()->inputScrolling) mesh.value[11]->step(0.1);
      mesh.value[11]->align(FL_ALIGN_RIGHT);
      mesh.value[11]->callback(mesh_options_ok_cb);

      mesh.value[14] = new Fl_Value_Input(L + 2 * WB, 2 * WB + 5 * BH, IW, BH,
                                          "High-order element subdivisions");
      mesh.value[14]->tooltip("Mesh.NumSubEdges");
      mesh.value[14]->minimum(1);
      mesh.value[14]->maximum(10);
      if(CTX::instance()->inputScrolling) mesh.value[14]->step(1);
      mesh.value[14]->align(FL_ALIGN_RIGHT);
      mesh.value[14]->when(FL_WHEN_RELEASE);
      mesh.value[14]->callback(mesh_options_ok_cb);

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Color");
      o->hide();

      mesh.butt[17] = new Fl_Check_Button(L + 2 * WB, 2 * WB + 1 * BH, BW, BH,
                                          "Enable lighting");
      mesh.butt[17]->tooltip("Mesh.Light (Alt+w)");
      mesh.butt[17]->type(FL_TOGGLE_BUTTON);
      mesh.butt[17]->callback(mesh_options_ok_cb, (void *)"mesh_light");

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

      mesh.butt[18] = new Fl_Check_Button(L + 2 * WB, 2 * WB + 3 * BH, BW, BH,
                                          "Use two-side lighting");
      mesh.butt[18]->tooltip("Mesh.LightTwoSide");
      mesh.butt[18]->type(FL_TOGGLE_BUTTON);
      mesh.butt[18]->callback(mesh_options_ok_cb);

      mesh.butt[19] = new Fl_Check_Button(L + 2 * WB, 2 * WB + 4 * BH, BW, BH,
                                          "Smooth normals");
      mesh.butt[19]->tooltip("Mesh.SmoothNormals");
      mesh.butt[19]->type(FL_TOGGLE_BUTTON);
      mesh.butt[19]->callback(mesh_options_ok_cb);

      mesh.value[18] = new Fl_Value_Input(L + 2 * WB, 2 * WB + 5 * BH, IW, BH,
                                          "Smoothing threshold angle");
      mesh.value[18]->tooltip("Mesh.AngleSmoothNormals");
      mesh.value[18]->minimum(0.);
      mesh.value[18]->maximum(180.);
      if(CTX::instance()->inputScrolling) mesh.value[18]->step(1.);
      mesh.value[18]->align(FL_ALIGN_RIGHT);
      mesh.value[18]->when(FL_WHEN_RELEASE);
      mesh.value[18]->callback(mesh_options_ok_cb);

      static Fl_Menu_Item menu_mesh_color[] = {
        {"By element type", 0, nullptr, nullptr},
        {"By elementary entity", 0, nullptr, nullptr},
        {"By physical group", 0, nullptr, nullptr},
        {"By mesh partition", 0, nullptr, nullptr},
        {nullptr}};
      mesh.choice[4] =
        new Fl_Choice(L + 2 * WB, 2 * WB + 6 * BH, IW, BH, "Coloring mode");
      mesh.choice[4]->tooltip("Mesh.ColorCarousel");
      mesh.choice[4]->menu(menu_mesh_color);
      mesh.choice[4]->align(FL_ALIGN_RIGHT);
      mesh.choice[4]->callback(mesh_options_ok_cb);

      Fl_Scroll *s = new Fl_Scroll(L + 2 * WB, 3 * WB + 7 * BH, IW + 20,
                                   height - 5 * WB - 7 * BH);
      std::size_t i = 0, j = 0;
      while(MeshOptions_Color[j].str) {
        if(MeshOptions_Color[j].level & GMSH_DEPRECATED) {
          j++;
          continue;
        }
        mesh.color[i] = new Fl_Button(L + 2 * WB, 3 * WB + (7 + i) * BH, IW, BH,
                                      MeshOptions_Color[j].str);
        mesh.color[i]->callback(color_cb,
                                (void *)MeshOptions_Color[j].function);
        i++;
        j++;
        if(i >= mesh.color.size()) {
          Msg::Error("Mesh color widget vector should be resized");
          break;
        }
      }
      s->end();

      o->end();
    }
    o->end();
  }
  mesh.group->end();

  // Solver options
  solver.group = new Fl_Group(L, 0, width, height, "Solver Options");
  solver.group->hide();
  {
    Fl_Tabs *o = new Fl_Tabs(L + WB, WB, width - 2 * WB, height - 2 * WB);
    {
      {
        Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                   height - 2 * WB - BH, "General");

        solver.input[0] =
          new Fl_Input(L + 2 * WB, 2 * WB + 1 * BH, IW, BH, "Base socket name");
        solver.input[0]->tooltip("Solver.SocketName");
        solver.input[0]->align(FL_ALIGN_RIGHT);
        solver.input[0]->callback(solver_options_ok_cb);

        solver.value[0] = new Fl_Value_Input(L + 2 * WB, 2 * WB + 2 * BH, IW,
                                             BH, "Timeout (in seconds)");
        solver.value[0]->tooltip("Solver.Timout");
        solver.value[0]->align(FL_ALIGN_RIGHT);
        solver.value[0]->callback(solver_options_ok_cb);

        solver.butt[0] =
          new Fl_Check_Button(L + 2 * WB, 2 * WB + 3 * BH, BW, BH,
                              "Always listen to incoming connection requests");
        solver.butt[0]->tooltip("Solver.AlwaysListen");
        solver.butt[0]->type(FL_TOGGLE_BUTTON);
        solver.butt[0]->callback(solver_options_ok_cb);

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
    o->end();
  }
  solver.group->end();

  // Post-processing options
  post.group = new Fl_Group(L, 0, width, height, "Post-processing Options");
  post.group->hide();
  {
    Fl_Tabs *o = new Fl_Tabs(L + WB, WB, width - 2 * WB, height - 2 * WB);
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

      post.value[0] = new Fl_Value_Input(L + 2 * WB, 2 * WB + 2 * BH, IW, BH,
                                         "Frame duration (in seconds)");
      post.value[0]->tooltip("PostProcessing.AnimationDelay");
      post.value[0]->minimum(0);
      post.value[0]->maximum(10);
      if(CTX::instance()->inputScrolling) post.value[0]->step(0.01);
      post.value[0]->align(FL_ALIGN_RIGHT);
      post.value[0]->callback(post_options_ok_cb);

      post.value[1] = new Fl_Value_Input(L + 2 * WB, 2 * WB + 3 * BH, IW, BH,
                                         "Animation increment step");
      post.value[1]->tooltip("PostProcessing.AnimationStep");
      post.value[1]->minimum(1);
      post.value[1]->maximum(100);
      if(CTX::instance()->inputScrolling) post.value[1]->step(1);
      post.value[1]->align(FL_ALIGN_RIGHT);
      post.value[1]->callback(post_options_ok_cb);

      post.butt[0] =
        new Fl_Check_Button(L + 2 * WB, 2 * WB + 4 * BH, BW, BH,
                            "Cycle through views instead of steps");
      post.butt[0]->tooltip("PostProcessing.AnimationCycle");
      post.butt[0]->type(FL_TOGGLE_BUTTON);
      post.butt[0]->callback(post_options_ok_cb);

      post.butt[1] =
        new Fl_Check_Button(L + 2 * WB, 2 * WB + 5 * BH, BW, BH,
                            "Remove original views after combination");
      post.butt[1]->tooltip("PostProcessing.CombineRemoveOriginal");
      post.butt[1]->type(FL_TOGGLE_BUTTON);
      post.butt[1]->callback(post_options_ok_cb);

      post.butt[2] = new Fl_Check_Button(L + 2 * WB, 2 * WB + 6 * BH, BW, BH,
                                         "Draw value scales horizontally");
      post.butt[2]->tooltip("PostProcessing.HorizontalScales");
      post.butt[2]->type(FL_TOGGLE_BUTTON);
      post.butt[2]->callback(post_options_ok_cb);

      o->end();
    }
    o->end();
  }
  post.group->end();

  // View options
  view.index = -1;
  view.group = new Fl_Group(L, 0, width, height, "View Options");
  view.group->hide();
  {
    Fl_Tabs *o = new Fl_Tabs(L + WB, WB, width - 2 * WB, height - 2 * WB);
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
      view.value[50] =
        new Fl_Value_Input(L + 2 * WB + sw, 2 * WB + 3 * BH, IW - 2 * sw, BH);
      view.value[50]->tooltip("View.TimeStep");
      view.value[50]->callback(view_options_timestep_cb, (void *)"=");
      view.value[50]->align(FL_ALIGN_RIGHT);
      view.value[50]->minimum(0);
      view.value[50]->maximum(0);
      if(CTX::instance()->inputScrolling) view.value[50]->step(1);
      view.label[0] =
        new Fl_Box(L + 2 * WB + IW, 2 * WB + 3 * BH, width / 2, BH, "Step");
      view.label[0]->box(FL_NO_BOX);
      view.label[0]->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);

      view.range =
        new Fl_Group(L + 2 * WB, 2 * WB + 4 * BH, width - 4 * WB, 8 * BH);

      view.value[30] =
        new Fl_Value_Input(L + 2 * WB, 2 * WB + 4 * BH, IW, BH, "Intervals");
      view.value[30]->tooltip("View.NbIso");
      view.value[30]->align(FL_ALIGN_RIGHT);
      view.value[30]->minimum(1);
      view.value[30]->maximum(256);
      if(CTX::instance()->inputScrolling) view.value[30]->step(1);
      view.value[30]->when(FL_WHEN_RELEASE);
      view.value[30]->callback(view_options_ok_cb);

      view.input[1] =
        new Fl_Input(L + width - (int)(0.85 * IW) - 2 * WB, 2 * WB + 4 * BH,
                     (int)(0.5 * 0.85 * IW), BH, "Format");
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
        {"Double logarithmic", 0, nullptr, nullptr},
        {nullptr}};
      view.choice[1] = new Fl_Choice(L + width - (int)(0.85 * IW) - 2 * WB,
                                     2 * WB + 5 * BH, (int)(0.85 * IW), BH);
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

      view.butt[38] =
        new Fl_Check_Button(L + width - (int)(0.85 * IW) - 2 * WB,
                            2 * WB + 6 * BH, (int)(0.85 * IW), BH, "Saturate");
      view.butt[38]->tooltip("View.SaturateValues");
      view.butt[38]->type(FL_TOGGLE_BUTTON);
      view.butt[38]->callback(view_options_ok_cb);

      int sw2 = (int)(2.5 * FL_NORMAL_SIZE);
      view.push[1] = new Fl_Button(L + 2 * WB, 2 * WB + 7 * BH, sw2, BH, "Min");
      view.push[1]->callback(view_options_ok_cb, (void *)"range_min");
      view.value[31] = new Fl_Value_Input(L + 2 * WB + sw2, 2 * WB + 7 * BH,
                                          IW - sw2, BH, "Custom min");
      view.value[31]->tooltip("View.CustomMin");
      view.value[31]->align(FL_ALIGN_RIGHT);
      view.value[31]->when(FL_WHEN_RELEASE);
      view.value[31]->callback(view_options_ok_cb);

      view.push[2] = new Fl_Button(L + 2 * WB, 2 * WB + 8 * BH, sw2, BH, "Max");
      view.push[2]->callback(view_options_ok_cb, (void *)"range_max");
      view.value[32] = new Fl_Value_Input(L + 2 * WB + sw2, 2 * WB + 8 * BH,
                                          IW - sw2, BH, "Custom max");
      view.value[32]->tooltip("View.CustomMax");
      view.value[32]->align(FL_ALIGN_RIGHT);
      view.value[32]->when(FL_WHEN_RELEASE);
      view.value[32]->callback(view_options_ok_cb);

      view.butt[0] = new Fl_Check_Button(L + 2 * WB, 2 * WB + 9 * BH, BW, BH,
                                         "Adapt visualization grid");
      view.butt[0]->tooltip("View.AdaptVisualizationGrid");
      view.butt[0]->type(FL_TOGGLE_BUTTON);
      view.butt[0]->callback(view_options_ok_cb, (void *)"view_adaptive");

      view.push[5] = new Fl_Button(L + 2 * WB, 2 * WB + 10 * BH, sw, BH, "-");
      view.push[5]->callback(view_options_max_recursion_cb, (void *)"-");
      view.push[6] =
        new Fl_Button(L + 2 * WB + IW - sw, 2 * WB + 10 * BH, sw, BH, "+");
      view.push[6]->callback(view_options_max_recursion_cb, (void *)"+");
      view.value[33] =
        new Fl_Value_Input(L + 2 * WB + sw, 2 * WB + 10 * BH, IW - 2 * sw, BH);
      view.value[33]->tooltip("View.MaxRecursionLevel");
      view.value[33]->align(FL_ALIGN_RIGHT);
      view.value[33]->minimum(0);
      view.value[33]->maximum(6);
      if(CTX::instance()->inputScrolling) view.value[33]->step(1);
      view.value[33]->when(FL_WHEN_RELEASE);
      view.value[33]->callback(view_options_ok_cb);
      view.label[1] = new Fl_Box(L + 2 * WB + IW, 2 * WB + 10 * BH, width / 2,
                                 BH, "Maximum recursion level");
      view.label[1]->box(FL_NO_BOX);
      view.label[1]->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);

      view.value[34] = new Fl_Value_Input(L + 2 * WB, 2 * WB + 11 * BH, IW, BH,
                                          "Target visualization error");
      view.value[34]->tooltip("View.TargetError");
      view.value[34]->align(FL_ALIGN_RIGHT);
      view.value[34]->minimum(-1.e-4);
      view.value[34]->maximum(0.1);
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

      view.butt[3] = new Fl_Check_Button(L + width - (int)(0.85 * IW) - 2 * WB,
                                         2 * WB + 1 * BH, (int)(0.85 * IW), BH,
                                         "Mikado style");
      view.butt[3]->tooltip("View.AxesMikado");
      view.butt[3]->type(FL_TOGGLE_BUTTON);
      view.butt[3]->callback(view_options_ok_cb);

      view.value[3] =
        new Fl_Value_Input(L + 2 * WB, 2 * WB + 2 * BH, IW / 3, BH);
      view.value[3]->tooltip("View.AxesTicsX");
      view.value[3]->minimum(0.);
      if(CTX::instance()->inputScrolling) view.value[3]->step(1);
      view.value[3]->maximum(100);
      view.value[3]->callback(view_options_ok_cb);
      view.value[4] = new Fl_Value_Input(L + 2 * WB + 1 * IW / 3,
                                         2 * WB + 2 * BH, IW / 3, BH);
      view.value[4]->tooltip("View.AxesTicsY");
      view.value[4]->minimum(0.);
      if(CTX::instance()->inputScrolling) view.value[4]->step(1);
      view.value[4]->maximum(100);
      view.value[4]->callback(view_options_ok_cb);
      view.value[5] = new Fl_Value_Input(
        L + 2 * WB + 2 * IW / 3, 2 * WB + 2 * BH, IW / 3, BH, "Axes tics");
      view.value[5]->tooltip("View.AxesTicsZ");
      view.value[5]->minimum(0.);
      if(CTX::instance()->inputScrolling) view.value[5]->step(1);
      view.value[5]->maximum(100);
      view.value[5]->align(FL_ALIGN_RIGHT);
      view.value[5]->callback(view_options_ok_cb);

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

      view.butt[25] = new Fl_Check_Button(L + 2 * WB, 2 * WB + 5 * BH, BW, BH,
                                          "Position 3D axes automatically");
      view.butt[25]->tooltip("View.AxesAutoPosition");
      view.butt[25]->type(FL_TOGGLE_BUTTON);
      view.butt[25]->callback(view_options_ok_cb, (void *)"view_axes_auto_3d");

      view.value[13] =
        new Fl_Value_Input(L + 2 * WB, 2 * WB + 6 * BH, IW / 3, BH);
      view.value[13]->tooltip("View.AxesMinX");
      view.value[13]->callback(view_options_ok_cb);
      view.value[14] =
        new Fl_Value_Input(L + 2 * WB + IW / 3, 2 * WB + 6 * BH, IW / 3, BH);
      view.value[14]->tooltip("View.AxesMinY");
      view.value[14]->callback(view_options_ok_cb);
      view.value[15] =
        new Fl_Value_Input(L + 2 * WB + 2 * IW / 3, 2 * WB + 6 * BH, IW / 3, BH,
                           "3D axes minimum");
      view.value[15]->tooltip("View.AxesMinZ");
      view.value[15]->align(FL_ALIGN_RIGHT);
      view.value[15]->callback(view_options_ok_cb);

      view.value[16] =
        new Fl_Value_Input(L + 2 * WB, 2 * WB + 7 * BH, IW / 3, BH);
      view.value[16]->tooltip("View.AxesMaxX");
      view.value[16]->callback(view_options_ok_cb);
      view.value[17] =
        new Fl_Value_Input(L + 2 * WB + IW / 3, 2 * WB + 7 * BH, IW / 3, BH);
      view.value[17]->tooltip("View.AxesMaxY");
      view.value[17]->callback(view_options_ok_cb);
      view.value[18] =
        new Fl_Value_Input(L + 2 * WB + 2 * IW / 3, 2 * WB + 7 * BH, IW / 3, BH,
                           "3D axes maximum");
      view.value[18]->tooltip("View.AxesMaxZ");
      view.value[18]->align(FL_ALIGN_RIGHT);
      view.value[18]->callback(view_options_ok_cb);

      view.choice[16] = new Fl_Choice(L + 2 * WB, 2 * WB + 8 * BH, IW, BH,
                                      "2D axes/value scale position");
      view.choice[16]->tooltip("View.AutoPosition");
      view.choice[16]->menu(menu_position);
      view.choice[16]->align(FL_ALIGN_RIGHT);
      view.choice[16]->callback(view_options_ok_cb,
                                (void *)"view_axes_auto_2d");

      view.value[20] =
        new Fl_Value_Input(L + 2 * WB, 2 * WB + 9 * BH, IW / 2, BH);
      view.value[20]->minimum(-2000);
      view.value[20]->maximum(2000);
      if(CTX::instance()->inputScrolling) view.value[20]->step(0.5);
      view.value[20]->callback(view_options_ok_cb);
      view.value[21] =
        new Fl_Value_Input(L + 2 * WB + IW / 2, 2 * WB + 9 * BH, IW / 2, BH,
                           "2D axes/value scale position");
      view.value[21]->align(FL_ALIGN_RIGHT);
      view.value[21]->minimum(-2000);
      view.value[21]->maximum(2000);
      if(CTX::instance()->inputScrolling) view.value[21]->step(0.5);
      view.value[21]->callback(view_options_ok_cb);

      view.value[22] =
        new Fl_Value_Input(L + 2 * WB, 2 * WB + 10 * BH, IW / 2, BH);
      view.value[22]->tooltip("View.PositionX");
      view.value[22]->minimum(0);
      view.value[22]->maximum(2000);
      if(CTX::instance()->inputScrolling) view.value[22]->step(0.5);
      view.value[22]->callback(view_options_ok_cb);
      view.value[23] =
        new Fl_Value_Input(L + 2 * WB + IW / 2, 2 * WB + 10 * BH, IW / 2, BH,
                           "2D axes/value scale size");
      view.value[23]->tooltip("View.PositionY");
      view.value[23]->align(FL_ALIGN_RIGHT);
      view.value[23]->minimum(0);
      view.value[23]->maximum(2000);
      if(CTX::instance()->inputScrolling) view.value[23]->step(0.5);
      view.value[23]->callback(view_options_ok_cb);

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Visibility");
      o->hide();

      view.butt[4] = new Fl_Check_Button(L + 2 * WB, 2 * WB + 1 * BH, BW, BH,
                                         "Show value scale");
      view.butt[4]->tooltip("View.ShowScale (Alt+i)");
      view.butt[4]->type(FL_TOGGLE_BUTTON);
      view.butt[4]->callback(view_options_ok_cb);

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

      view.butt[5] = new Fl_Check_Button(L + 2 * WB, 2 * WB + 3 * BH, BW, BH,
                                         "Show annotations");
      view.butt[5]->tooltip("View.DrawStrings (Alt+n)");
      view.butt[5]->type(FL_TOGGLE_BUTTON);
      view.butt[5]->callback(view_options_ok_cb);

      view.butt[10] = new Fl_Check_Button(L + 2 * WB, 2 * WB + 4 * BH, BW, BH,
                                          "Draw element outlines");
      view.butt[10]->tooltip("View.ShowElement (Alt+e)");
      view.butt[10]->type(FL_TOGGLE_BUTTON);
      view.butt[10]->callback(view_options_ok_cb);

      view.butt[2] = new Fl_Check_Button(L + 2 * WB, 2 * WB + 5 * BH, BW, BH,
                                         "Draw only skin of 3D views");
      view.butt[2]->tooltip("View.DrawSkinOnly");
      view.butt[2]->type(FL_TOGGLE_BUTTON);
      view.butt[2]->callback(view_options_ok_cb);

      static Fl_Menu_Item menu_view_element_types[] = {
        {"Points", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Lines", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Triangles", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Quadrangles", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Tetrahedra", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Hexahedra", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Prisms", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Pyramids", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {nullptr}};

      view.menu[1] =
        new Fl_Menu_Button(L + 2 * WB, 2 * WB + 6 * BH, IW, BH, "Elements");
      view.menu[1]->tooltip(
        "View.DrawPoints, View.DrawLines, View.DrawTriangles, "
        "View.DrawQuadrangles, View.DrawTetrahedra, View.DrawHexahedra, "
        "View.DrawPrisms, View.DrawPyramids");
      view.menu[1]->menu(menu_view_element_types);
      view.menu[1]->callback(view_options_ok_cb);

      view.value[6] = new Fl_Value_Input(L + 3 * WB + IW, 2 * WB + 6 * BH,
                                         IW / 3, BH, "Sampling");
      view.value[6]->tooltip("View.Sampling");
      view.value[6]->minimum(1);
      view.value[6]->maximum(100);
      if(CTX::instance()->inputScrolling) view.value[6]->step(1);
      view.value[6]->align(FL_ALIGN_RIGHT);
      view.value[6]->when(FL_WHEN_RELEASE);
      view.value[6]->callback(view_options_ok_cb);

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
        new Fl_Value_Input(L + 2 * WB, 2 * WB + 8 * BH, IW / 2, BH);
      view.value[0]->tooltip("View.Normals");
      view.value[0]->minimum(0);
      view.value[0]->maximum(500);
      if(CTX::instance()->inputScrolling) view.value[0]->step(1);
      view.value[0]->align(FL_ALIGN_RIGHT);
      view.value[0]->when(FL_WHEN_RELEASE);
      view.value[0]->callback(view_options_ok_cb);

      view.value[1] = new Fl_Value_Input(L + 2 * WB + IW / 2, 2 * WB + 8 * BH,
                                         IW / 2, BH, "Normals and tangents");
      view.value[1]->tooltip("View.Tangents");
      view.value[1]->minimum(0);
      view.value[1]->maximum(500);
      if(CTX::instance()->inputScrolling) view.value[1]->step(1);
      view.value[1]->align(FL_ALIGN_RIGHT);
      view.value[1]->when(FL_WHEN_RELEASE);
      view.value[1]->callback(view_options_ok_cb);

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

      for(int i = 0; i < 9; i++) {
        int W = width - 5 * WB - IW;
        int w = W / 9;
        view.value[70 + i] =
          new Fl_Value_Input(L + 3 * WB + IW + i * w, 2 * WB + 10 * BH, w, BH);
        view.value[70 + i]->tooltip("View.ComponentMap");
        view.value[70 + i]->minimum(-1);
        view.value[70 + i]->maximum(9);
        if(CTX::instance()->inputScrolling) view.value[70 + i]->step(1);
        view.value[70 + i]->callback(view_options_ok_cb);
      }

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Transfo");
      o->hide();

      Fl_Box *b = new Fl_Box(FL_NO_BOX, L + 2 * WB, 2 * WB + 1 * BH, IW, BH,
                             "Coordinate transformation:");
      b->align(FL_ALIGN_INSIDE | FL_ALIGN_LEFT);

      int ss = 2 * IW / 3 / 3 + 4;
      view.value[51] = new Fl_Value_Input(L + 2 * WB, 2 * WB + 2 * BH, ss, BH);
      view.value[51]->tooltip("View.TransformXX");
      view.value[52] =
        new Fl_Value_Input(L + 2 * WB + ss, 2 * WB + 2 * BH, ss, BH);
      view.value[52]->tooltip("View.TransformXY");
      view.value[53] =
        new Fl_Value_Input(L + 2 * WB + 2 * ss, 2 * WB + 2 * BH, ss, BH, " X");
      view.value[53]->tooltip("View.TransformXZ");
      view.value[40] =
        new inputValueFloat(L + 2 * WB + IW, 2 * WB + 2 * BH, 7 * IW / 10, BH);
      view.value[40]->tooltip("View.OffsetX");

      view.value[54] = new Fl_Value_Input(L + 2 * WB, 2 * WB + 3 * BH, ss, BH);
      view.value[54]->tooltip("View.TransformYX");
      view.value[55] =
        new Fl_Value_Input(L + 2 * WB + ss, 2 * WB + 3 * BH, ss, BH);
      view.value[55]->tooltip("View.TransformYY");
      view.value[56] = new Fl_Value_Input(L + 2 * WB + 2 * ss, 2 * WB + 3 * BH,
                                          ss, BH, " Y +");
      view.value[56]->tooltip("View.TransformYZ");
      view.value[41] =
        new inputValueFloat(L + 2 * WB + IW, 2 * WB + 3 * BH, 7 * IW / 10, BH);
      view.value[41]->tooltip("View.OffsetY");

      view.value[57] = new Fl_Value_Input(L + 2 * WB, 2 * WB + 4 * BH, ss, BH);
      view.value[57]->tooltip("View.TransformZX");
      view.value[58] =
        new Fl_Value_Input(L + 2 * WB + ss, 2 * WB + 4 * BH, ss, BH);
      view.value[58]->tooltip("View.TransformZY");
      view.value[59] =
        new Fl_Value_Input(L + 2 * WB + 2 * ss, 2 * WB + 4 * BH, ss, BH, " Z");
      view.value[59]->tooltip("View.TransformZZ");
      view.value[42] =
        new inputValueFloat(L + 2 * WB + IW, 2 * WB + 4 * BH, 7 * IW / 10, BH);
      view.value[42]->tooltip("View.OffsetZ");

      Fl_Box *b2 = new Fl_Box(FL_NO_BOX, L + 2 * WB + 2 * IW - 3 * WB,
                              2 * WB + 1 * BH, 7 * IW / 10, BH, "Raise:");
      b2->align(FL_ALIGN_INSIDE | FL_ALIGN_LEFT);

      view.value[43] = new inputValueFloat(L + 2 * WB + 2 * IW - 3 * WB,
                                           2 * WB + 2 * BH, 7 * IW / 10, BH);
      view.value[43]->tooltip("View.RaizeX");
      view.value[44] = new inputValueFloat(L + 2 * WB + 2 * IW - 3 * WB,
                                           2 * WB + 3 * BH, 7 * IW / 10, BH);
      view.value[44]->tooltip("View.RaizeY");
      view.value[45] = new inputValueFloat(L + 2 * WB + 2 * IW - 3 * WB,
                                           2 * WB + 4 * BH, 7 * IW / 10, BH);
      view.value[45]->tooltip("View.RaizeZ");
      view.value[46] = new inputValueFloat(L + 2 * WB, 2 * WB + 5 * BH, 3 * ss,
                                           BH, "Normal raise");
      view.value[46]->tooltip("View.NormalRaize");

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

      view.butt[6] =
        new Fl_Check_Button(L + 2 * WB, 2 * WB + 6 * BH, BW, BH,
                            "Use general transformation expressions");
      view.butt[6]->tooltip("View.UseGeneralizedRaise");
      view.butt[6]->type(FL_TOGGLE_BUTTON);
      view.butt[6]->callback(view_options_ok_cb,
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

      view.value[12] = new Fl_Value_Input(L + 2 * WB, 2 * WB + 1 * BH, IW, BH,
                                          "Element shrinking factor");
      view.value[12]->tooltip("View.Explode");
      view.value[12]->minimum(0.);
      if(CTX::instance()->inputScrolling) view.value[12]->step(0.01);
      view.value[12]->maximum(1.);
      view.value[12]->align(FL_ALIGN_RIGHT);
      view.value[12]->when(FL_WHEN_RELEASE);
      view.value[12]->callback(view_options_ok_cb);

      view.choice[5] =
        new Fl_Choice(L + 2 * WB, 2 * WB + 2 * BH, IW, BH, "Point display");
      view.choice[5]->tooltip("View.PointType");
      view.choice[5]->menu(menu_point_display_post);
      view.choice[5]->align(FL_ALIGN_RIGHT);
      view.choice[5]->callback(view_options_ok_cb);

      view.value[61] =
        new Fl_Value_Input(L + 2 * WB, 2 * WB + 3 * BH, IW, BH, "Point size");
      view.value[61]->tooltip("View.PointSize");
      view.value[61]->minimum(0.1);
      view.value[61]->maximum(50);
      if(CTX::instance()->inputScrolling) view.value[61]->step(0.1);
      view.value[61]->align(FL_ALIGN_RIGHT);
      view.value[61]->callback(view_options_ok_cb);

      view.choice[6] =
        new Fl_Choice(L + 2 * WB, 2 * WB + 4 * BH, IW, BH, "Line display");
      view.choice[6]->tooltip("View.LineType");
      view.choice[6]->menu(menu_line_display_post);
      view.choice[6]->align(FL_ALIGN_RIGHT);
      view.choice[6]->callback(view_options_ok_cb);

      view.butt[26] =
        new Fl_Check_Button(L + width - (int)(0.85 * IW) - 2 * WB,
                            2 * WB + 4 * BH, (int)(0.85 * IW), BH, "Stipple");
      view.butt[26]->tooltip("View.Stipple");
      view.butt[26]->type(FL_TOGGLE_BUTTON);
      view.butt[26]->callback(view_options_ok_cb);

      view.value[62] =
        new Fl_Value_Input(L + 2 * WB, 2 * WB + 5 * BH, IW, BH, "Line width");
      view.value[62]->tooltip("View.LineWidth");
      view.value[62]->minimum(0.1);
      view.value[62]->maximum(50);
      if(CTX::instance()->inputScrolling) view.value[62]->step(0.1);
      view.value[62]->align(FL_ALIGN_RIGHT);
      view.value[62]->callback(view_options_ok_cb);

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
          new Fl_Value_Input(L + 2 * WB, 2 * WB + 7 * BH, IW / 2, BH);
        view.value[64]->tooltip("View.ArrowSizeMin");
        view.value[64]->minimum(0);
        view.value[64]->maximum(500);
        if(CTX::instance()->inputScrolling) view.value[64]->step(1);
        view.value[64]->align(FL_ALIGN_RIGHT);
        view.value[64]->callback(view_options_ok_cb);
        view.value[60] = new Fl_Value_Input(
          L + 2 * WB + IW / 2, 2 * WB + 7 * BH, IW / 2, BH, "Arrow size");
        view.value[60]->tooltip("View.ArrowSizeMax");
        view.value[60]->minimum(0);
        view.value[60]->maximum(500);
        if(CTX::instance()->inputScrolling) view.value[60]->step(1);
        view.value[60]->align(FL_ALIGN_RIGHT);
        view.value[60]->callback(view_options_ok_cb);

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
      view.choice[15] = new Fl_Choice(L + width - (int)(0.85 * IW) - 2 * WB,
                                      2 * WB + 10 * BH, (int)(0.85 * IW), BH);
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
        {"Frame", 0, nullptr, nullptr},
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

      view.butt[11] = new Fl_Check_Button(L + 2 * WB, 2 * WB + 1 * BH, BW, BH,
                                          "Enable lighting");
      view.butt[11]->tooltip("View.Light (Alt+w)");
      view.butt[11]->type(FL_TOGGLE_BUTTON);
      view.butt[11]->callback(view_options_ok_cb, (void *)"view_light");

      view.butt[8] = new Fl_Check_Button(L + 2 * WB, 2 * WB + 2 * BH, BW, BH,
                                         "Enable lighting of lines");
      view.butt[8]->tooltip("View.LightLines");
      view.butt[8]->type(FL_TOGGLE_BUTTON);
      view.butt[8]->callback(view_options_ok_cb);

      view.butt[9] = new Fl_Check_Button(L + 2 * WB, 2 * WB + 3 * BH, BW, BH,
                                         "Use two-side lighting");
      view.butt[9]->tooltip("View.LightTwoSide");
      view.butt[9]->type(FL_TOGGLE_BUTTON);
      view.butt[9]->callback(view_options_ok_cb);

      view.butt[12] = new Fl_Check_Button(L + 2 * WB, 2 * WB + 4 * BH, BW, BH,
                                          "Smooth normals");
      view.butt[12]->tooltip("View.SmoothNormals");
      view.butt[12]->type(FL_TOGGLE_BUTTON);
      view.butt[12]->callback(view_options_ok_cb);

      view.value[10] = new Fl_Value_Input(L + 2 * WB, 2 * WB + 5 * BH, IW, BH,
                                          "Smoothing threshold angle");
      view.value[10]->tooltip("View.AngleSmoothNormals");
      view.value[10]->minimum(0.);
      if(CTX::instance()->inputScrolling) view.value[10]->step(1.);
      view.value[10]->maximum(180.);
      view.value[10]->align(FL_ALIGN_RIGHT);
      view.value[10]->when(FL_WHEN_RELEASE);
      view.value[10]->callback(view_options_ok_cb);

      view.butt[24] = new Fl_Check_Button(L + 2 * WB, 2 * WB + 6 * BH, BW, BH,
                                          "Use fake transparency mode");
      view.butt[24]->tooltip("View.FakeTransparency");
      view.butt[24]->type(FL_TOGGLE_BUTTON);
      view.butt[24]->callback(view_options_ok_cb);

      Fl_Scroll *s = new Fl_Scroll(L + 2 * WB, 3 * WB + 7 * BH, IW + 20,
                                   height - 5 * WB - 7 * BH);
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
        if(i >= view.color.size()) {
          Msg::Error("View color widget vector should be resized");
          break;
        }
      }
      s->end();

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Map");
      // o->label("@-1gmsh_colormap");
      o->hide();

      view.colorbar = new colorbarWindow(L + 2 * WB, 2 * WB + BH,
                                         width - 4 * WB, height - 4 * WB - BH);
      view.colorbar->end();
      view.colorbar->callback(view_options_ok_cb);

      o->end();
    }
    o->end();
  }
  view.group->end();

  win->position(CTX::instance()->optPosition[0],
                CTX::instance()->optPosition[1]);
  win->end();

  FL_NORMAL_SIZE += deltaFontSize;
}

void optionWindow::showGroup(int num, bool showWindow,
                             bool allowMultipleSelections)
{
  general.group->hide();
  geo.group->hide();
  mesh.group->hide();
  solver.group->hide();
  post.group->hide();
  view.group->hide();

  if(num > 5 && allowMultipleSelections) {
    for(int i = 1; i <= 5; i++) browser->select(i, 0);
  }
  else {
    browser->deselect();
  }
  browser->select(num, 1);
  switch(num) {
  case 0:
  case 1:
    win->label("Options - General");
    general.group->show();
    break;
  case 2:
    win->label("Options - Geometry");
    geo.group->show();
    break;
  case 3:
    win->label("Options - Mesh");
    mesh.group->show();
    break;
  case 4:
    win->label("Options - Solver");
    solver.group->show();
    break;
  case 5:
    win->label("Options - Post-pro");
    post.group->show();
    break;
  default: {
    updateViewGroup(num - 6);
    static char str[128];
    sprintf(str, "Options - View [%d]", num - 6);
    win->label(str);
    view.group->show();
  } break;
  }
  if(showWindow) win->show();
}

void optionWindow::resetBrowser()
{
  int select = browser->value();
  browser->clear();
  browser->add("General");
  browser->add("Geometry");
  browser->add("Mesh");
  browser->add("Solver");
  browser->add("Post-pro");
  for(std::size_t i = 0; i < PView::list.size(); i++) {
    char str[128];
    sprintf(str, "View [%lu]", i);
    browser->add(str);
  }
  int num = (select <= browser->size()) ? select : browser->size();
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
    sprintf(str, "View [%lu]", i);
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
  PViewOptions *opt = v->getOptions();

  double maxval = std::max(fabs(data->getMin()), fabs(data->getMax()));
  if(!maxval) maxval = 1.;
  double val1 = 10. * CTX::instance()->lc;
  double val2 = 2. * CTX::instance()->lc / maxval;

  opt_view_name(index, GMSH_GUI, "");
  opt_view_format(index, GMSH_GUI, "");
  opt_view_type(index, GMSH_GUI, 0);
  opt_view_show_scale(index, GMSH_GUI, 0);
  opt_view_draw_strings(index, GMSH_GUI, 0);

  opt_view_adapt_visualization_grid(index, GMSH_GUI, 0);
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
  opt_view_axes_mikado(index, GMSH_GUI, 0);
  opt_view_axes_format0(index, GMSH_GUI, "");
  opt_view_axes_format1(index, GMSH_GUI, "");
  opt_view_axes_format2(index, GMSH_GUI, "");
  opt_view_axes_tics0(index, GMSH_GUI, 0);
  opt_view_axes_tics1(index, GMSH_GUI, 0);
  opt_view_axes_tics2(index, GMSH_GUI, 0);
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

  if(data->getNumElements()) {
    view.range->activate();
    ((Fl_Menu_Item *)view.choice[13]->menu())[0].activate();
  }
  else {
    view.range->deactivate();
    ((Fl_Menu_Item *)view.choice[13]->menu())[0].deactivate();
  }
  opt_view_show_element(index, GMSH_GUI, 0);
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

  opt_view_fake_transparency(index, GMSH_GUI, 0);
  opt_view_use_stipple(index, GMSH_GUI, 0);
  opt_view_color_points(index, GMSH_GUI, 0);
  opt_view_color_lines(index, GMSH_GUI, 0);
  opt_view_color_triangles(index, GMSH_GUI, 0);
  opt_view_color_quadrangles(index, GMSH_GUI, 0);
  opt_view_color_tetrahedra(index, GMSH_GUI, 0);
  opt_view_color_hexahedra(index, GMSH_GUI, 0);
  opt_view_color_prisms(index, GMSH_GUI, 0);
  opt_view_color_pyramids(index, GMSH_GUI, 0);
  opt_view_color_trihedra(index, GMSH_GUI, 0);
  opt_view_color_tangents(index, GMSH_GUI, 0);
  opt_view_color_normals(index, GMSH_GUI, 0);
  opt_view_color_text2d(index, GMSH_GUI, 0);
  opt_view_color_text3d(index, GMSH_GUI, 0);
  opt_view_color_axes(index, GMSH_GUI, 0);
  opt_view_color_background2d(index, GMSH_GUI, 0);

  view.colorbar->update(data->getName().c_str(), data->getMin(), data->getMax(),
                        &opt->colorTable, &v->getChanged());
}

void optionWindow::activate(const char *what)
{
  if(!what) return;

  // activate/deactivate parts of the option window depending on the
  // user's choices (or the option settings)
  if(!strcmp(what, "fast_redraw")) {
    if(general.butt[2]->value()) {
      browser->resize(browser->x(), browser->y(), browser->w(),
                      win->h() - 2 * WB - BH);
      redraw->show();
      win->redraw();
    }
    else {
      browser->resize(browser->x(), browser->y(), browser->w(), win->h());
      redraw->hide();
      win->redraw();
    }
  }
  else if(!strcmp(what, "rotation_center")) {
    if(general.butt[15]->value()) {
      general.push[0]->deactivate();
      general.value[8]->deactivate();
      general.value[9]->deactivate();
      general.value[10]->deactivate();
    }
    else {
      general.push[0]->activate();
      general.value[8]->activate();
      general.value[9]->activate();
      general.value[10]->activate();
    }
  }
  else if(!strcmp(what, "general_axes")) {
    if(general.choice[4]->value()) {
      general.value[17]->activate();
      general.value[18]->activate();
      general.value[19]->activate();
      general.input[3]->activate();
      general.input[4]->activate();
      general.input[5]->activate();
      general.input[6]->activate();
      general.input[7]->activate();
      general.input[8]->activate();
    }
    else {
      general.value[17]->deactivate();
      general.value[18]->deactivate();
      general.value[19]->deactivate();
      general.input[3]->deactivate();
      general.input[4]->deactivate();
      general.input[5]->deactivate();
      general.input[6]->deactivate();
      general.input[7]->deactivate();
      general.input[8]->deactivate();
    }
  }
  else if(!strcmp(what, "general_axes_auto")) {
    if(general.butt[0]->value()) {
      general.value[20]->deactivate();
      general.value[21]->deactivate();
      general.value[22]->deactivate();
      general.value[23]->deactivate();
      general.value[24]->deactivate();
      general.value[25]->deactivate();
      general.push[1]->deactivate();
    }
    else {
      general.value[20]->activate();
      general.value[21]->activate();
      general.value[22]->activate();
      general.value[23]->activate();
      general.value[24]->activate();
      general.value[25]->activate();
      general.push[1]->activate();
    }
  }
  else if(!strcmp(what, "general_small_axes")) {
    if(general.butt[1]->value()) {
      general.value[26]->activate();
      general.value[27]->activate();
    }
    else {
      general.value[26]->deactivate();
      general.value[27]->deactivate();
    }
  }
  else if(!strcmp(what, "general_camera")) {
    if(general.butt[19]->value()) {
      if(CTX::instance()->gamepad && CTX::instance()->gamepad->active)
        general.gamepadconfig->activate();
    }
    else {
      general.gamepadconfig->deactivate();
    }
    if(general.butt[17]->value() == 0) { general.value[29]->deactivate(); }
    else {
      general.value[29]->activate();
    }
    if(general.butt[18]->value() == 0) {
      general.value[30]->deactivate();
      general.value[31]->deactivate();
    }
    else {
      general.value[30]->activate();
      general.value[31]->activate();
    }
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
    if(view.choice[7]->value() == 1) {
      view.value[31]->activate();
      view.value[32]->activate();
      view.push[1]->activate();
      view.push[2]->activate();
      view.butt[38]->activate();
    }
    else {
      view.value[31]->deactivate();
      view.value[32]->deactivate();
      view.push[1]->deactivate();
      view.push[2]->deactivate();
      view.butt[38]->deactivate();
    }
  }
  else if(!strcmp(what, "view_adaptive")) {
    if(view.butt[0]->value()) {
      view.push[5]->activate();
      view.push[6]->activate();
      view.value[33]->activate();
      view.value[34]->activate();
      view.label[1]->activate();
    }
    else {
      view.push[5]->deactivate();
      view.push[6]->deactivate();
      view.value[33]->deactivate();
      view.value[34]->deactivate();
      view.label[1]->deactivate();
    }
  }
  else if(!strcmp(what, "view_general_transform")) {
    if(view.butt[6]->value()) {
      view.choice[11]->activate();
      view.value[2]->activate();
      view.input[4]->activate();
      view.input[5]->activate();
      view.input[6]->activate();
    }
    else {
      view.choice[11]->deactivate();
      view.value[2]->deactivate();
      view.input[4]->deactivate();
      view.input[5]->deactivate();
      view.input[6]->deactivate();
    }
  }
  else if(!strcmp(what, "mesh_light")) {
    if(mesh.butt[17]->value()) {
      mesh.butt[18]->activate();
      mesh.butt[19]->activate();
      mesh.choice[10]->activate();
      mesh.value[18]->activate();
    }
    else {
      mesh.butt[18]->deactivate();
      mesh.butt[19]->deactivate();
      mesh.choice[10]->deactivate();
      mesh.value[18]->deactivate();
    }
  }
  else if(!strcmp(what, "view_light")) {
    if(view.butt[11]->value()) {
      view.butt[8]->activate();
      view.butt[9]->activate();
      view.butt[12]->activate();
      view.value[10]->activate();
    }
    else {
      view.butt[8]->deactivate();
      view.butt[9]->deactivate();
      view.butt[12]->deactivate();
      view.value[10]->deactivate();
    }
  }
  else if(!strcmp(what, "view_axes")) {
    if(view.choice[8]->value()) {
      view.value[3]->activate();
      view.value[4]->activate();
      view.value[5]->activate();
      view.input[7]->activate();
      view.input[8]->activate();
      view.input[9]->activate();
      view.input[10]->activate();
      view.input[11]->activate();
      view.input[12]->activate();
    }
    else {
      view.value[3]->deactivate();
      view.value[4]->deactivate();
      view.value[5]->deactivate();
      view.input[7]->deactivate();
      view.input[8]->deactivate();
      view.input[9]->deactivate();
      view.input[10]->deactivate();
      view.input[11]->deactivate();
      view.input[12]->deactivate();
    }
  }
  else if(!strcmp(what, "view_axes_auto_3d")) {
    if(view.butt[25]->value()) {
      view.value[13]->deactivate();
      view.value[14]->deactivate();
      view.value[15]->deactivate();
      view.value[16]->deactivate();
      view.value[17]->deactivate();
      view.value[18]->deactivate();
    }
    else {
      view.value[13]->activate();
      view.value[14]->activate();
      view.value[15]->activate();
      view.value[16]->activate();
      view.value[17]->activate();
      view.value[18]->activate();
    }
  }
  else if(!strcmp(what, "view_axes_auto_2d")) {
    if(view.choice[16]->value() == 0 || view.choice[16]->value() == 12) {
      view.value[20]->activate();
      view.value[21]->activate();
      view.value[22]->activate();
      view.value[23]->activate();
    }
    else {
      view.value[20]->deactivate();
      view.value[21]->deactivate();
      view.value[22]->deactivate();
      view.value[23]->deactivate();
    }
  }
}
