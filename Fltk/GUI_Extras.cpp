// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <limits>

#include "GmshUI.h"
#include "GmshDefines.h"
#include "CreateFile.h"
#include "Options.h"
#include "Context.h"
#include "Draw.h"
#include "GUI.h"
#include "Shortcut_Window.h"
#include "GModel.h"

#include <FL/Fl_Value_Slider.H>
#include <FL/Fl_Menu_Window.H>
#include <FL/Fl_Select_Browser.H>
#include <FL/Fl_Toggle_Button.H>
#include <errno.h>

#if defined(HAVE_NATIVE_FILE_CHOOSER)
#include <FL/Fl_Native_File_Chooser.H>
static Fl_Native_File_Chooser *fc = 0;
#else
#include "File_Picker.h"
static File_Picker *fc = 0;
#endif

extern Context_T CTX;

// File chooser

int file_chooser(int multi, int create, const char *message,
                 const char *filter, const char *fname)
{
  static char thefilter[1024] = "";
  static int thefilterindex = 0;

  if(strncmp(thefilter, filter, 1024)) {
    // reset the filter and the selection if the filter has changed
    strncpy(thefilter, filter, 1024);
    thefilterindex = 0;
  }

#if defined(HAVE_NATIVE_FILE_CHOOSER)
  if(!fc) fc = new Fl_Native_File_Chooser();
  if(multi)
    fc->type(Fl_Native_File_Chooser::BROWSE_MULTI_FILE);
  else if(create)
    fc->type(Fl_Native_File_Chooser::BROWSE_SAVE_FILE);
  else
    fc->type(Fl_Native_File_Chooser::BROWSE_FILE);
  fc->title(message);
  fc->filter(filter);
  fc->filter_value(thefilterindex);
  if(fname) fc->preset_file(fname);
  int ret = 0;
  switch(fc->show()) {
  case -1: break; // error
  case  1: break; // cancel
  default: if(fc->filename()) ret = fc->count(); break;
  }
  thefilterindex = fc->filter_value();
  // hack to clear the KEYDOWN state that remains when calling the
  // file chooser on Mac and Windows using a keyboard shortcut
  Fl::e_state = 0;
  return ret;
#else
  Fl_File_Chooser::show_label = "Format:";
  Fl_File_Chooser::all_files_label = "All files (*)";
  if(!fc) {
    fc = new File_Picker(getenv("PWD") ? "." : CTX.home_dir, thefilter, 
                         Fl_File_Chooser::SINGLE, message);
    fc->position(CTX.file_chooser_position[0], CTX.file_chooser_position[1]);
  }
  if(multi)
    fc->type(Fl_File_Chooser::MULTI);
  else if(create)
    fc->type(Fl_File_Chooser::CREATE);
  else
    fc->type(Fl_File_Chooser::SINGLE);
  fc->label(message);
  fc->filter(thefilter);
  fc->filter_value(thefilterindex);
  if(fname) fc->value(fname);
  fc->show();
  while(fc->shown()) Fl::wait();
  thefilterindex = fc->filter_value();
  if(fc->value())
    return fc->count();
  else
    return 0;
#endif
}

std::string file_chooser_get_name(int num)
{
  if(!fc) return "";
#if defined(HAVE_NATIVE_FILE_CHOOSER)
  return std::string(fc->filename(num - 1));
#else
  return std::string(fc->value(num));
#endif
}

int file_chooser_get_filter()
{
  if(!fc) return 0;
  return fc->filter_value();
}

void file_chooser_get_position(int *x, int *y)
{
  if(!fc) return;
#if !defined(HAVE_NATIVE_FILE_CHOOSER)
  *x = fc->x();
  *y = fc->y();
#endif
}

// Arrow editor

int arrow_editor(const char *title, double &a, double &b, double &c)
{
  struct _editor{
    Fl_Window *window;
    Fl_Value_Slider *sa, *sb, *sc;
    Fl_Button *apply, *cancel;
  };
  static _editor *editor = NULL;

  const int BH = 2 * GetFontSize() + 1;
  const int BB = 7 * GetFontSize() + 9;
  const int WB = 7;

  if(!editor){
    editor = new _editor;
    editor->window = new Dialog_Window(2 * BB + 3 * WB, 4 * BH + 3 * WB, CTX.non_modal_windows);
    editor->sa = new Fl_Value_Slider(WB, WB, BB, BH, "Head radius");
    editor->sa->type(FL_HOR_SLIDER);
    editor->sa->align(FL_ALIGN_RIGHT);
    editor->sb = new Fl_Value_Slider(WB, WB + BH, BB, BH, "Stem length");
    editor->sb->type(FL_HOR_SLIDER);
    editor->sb->align(FL_ALIGN_RIGHT);
    editor->sc = new Fl_Value_Slider(WB, WB + 2 * BH, BB, BH, "Stem radius");
    editor->sc->type(FL_HOR_SLIDER);
    editor->sc->align(FL_ALIGN_RIGHT);
    editor->apply = new Fl_Return_Button(WB, 2 * WB + 3 * BH, BB, BH, "Apply");
    editor->cancel = new Fl_Button(2 * WB + BB, 2 * WB + 3 * BH, BB, BH, "Cancel");
    editor->window->end();
    editor->window->hotspot(editor->window);
  }
  
  editor->window->label(title);
  editor->sa->value(a);
  editor->sb->value(b);
  editor->sc->value(c);
  editor->window->show();

  while(editor->window->shown()){
    Fl::wait();
    for (;;) {
      Fl_Widget* o = Fl::readqueue();
      if (!o) break;
      if (o == editor->apply) {
        a = editor->sa->value();
        b = editor->sb->value();
        c = editor->sc->value();
        return 1;
      }
      if (o == editor->window || o == editor->cancel){
        editor->window->hide();
        return 0;
      }
    }
  }
  return 0;
}

// Perspective editor (aka z-clipping planes factor slider)

static void persp_change_factor(Fl_Widget* w, void* data)
{
  opt_general_clip_factor(0, GMSH_SET|GMSH_GUI, ((Fl_Slider*)w)->value());
  Draw();
}

class Release_Slider : public Fl_Slider {
  int handle(int event){ 
    switch (event) {
    case FL_RELEASE: 
      if(window())
        window()->hide();
      return 1;
    default:
      return Fl_Slider::handle(event);
    }
  };
public:
  Release_Slider(int x,int y,int w,int h,const char *l=0)
    : Fl_Slider(x, y, w, h, l) {}
};

int perspective_editor()
{
  struct _editor{
    Fl_Menu_Window *window;
    Release_Slider *sa;
  };
  static _editor *editor = NULL;

  if(!editor){
    editor = new _editor;
    editor->window = new Fl_Menu_Window(20, 100);
    if(CTX.non_modal_windows) editor->window->set_non_modal();
    editor->sa = new Release_Slider(0, 0, 20, 100);
    editor->sa->type(FL_VERT_NICE_SLIDER);
    editor->sa->minimum(12);
    editor->sa->maximum(0.75);
    editor->sa->callback(persp_change_factor);
    editor->window->border(0);
    editor->window->end();
  }

  editor->window->hotspot(editor->window);
  editor->sa->value(CTX.clip_factor);

  if(editor->window->non_modal() && !editor->window->shown())
    editor->window->show(); // fix ordering
  editor->window->show();
  return 0;
}

// Model chooser

static void model_switch(Fl_Widget* w, void* data)
{
  Fl_Select_Browser *b = (Fl_Select_Browser *)w;
  GModel::current(b->value() - 1);
  if(w->window()) w->window()->hide();
  CTX.mesh.changed = ENT_ALL;
  Draw();
}

int model_chooser()
{
  struct _menu{
    Fl_Menu_Window *window;
    Fl_Select_Browser *browser;
  };
  static _menu *menu = NULL;

  if(!menu){
    menu = new _menu;
    menu->window = new Fl_Menu_Window(200, 100);
    if(CTX.non_modal_windows) menu->window->set_non_modal();
    menu->window->border(0);
    menu->browser = new Fl_Select_Browser(0, 0, 200, 100);
    menu->browser->callback(model_switch);
    menu->browser->when(FL_WHEN_RELEASE_ALWAYS);
    menu->window->end();
  }

  menu->window->hotspot(menu->window);
  menu->browser->clear();
  for(unsigned int i = 0; i < GModel::list.size(); i++){
    char tmp[256];
    sprintf(tmp, "Model %d <<%s>>", i, GModel::list[i]->getName().c_str());
    menu->browser->add(tmp);
  }

  if(menu->window->non_modal() && !menu->window->shown())
    menu->window->show(); // fix ordering
  menu->window->show();
  return 0;
}

// Generic save bitmap dialog

int generic_bitmap_dialog(const char *name, const char *title, int format)
{
  struct _generic_bitmap_dialog{
    Fl_Window *window;
    Fl_Check_Button *b;
    Fl_Button *ok, *cancel;
  };
  static _generic_bitmap_dialog *dialog = NULL;

  const int BH = 2 * GetFontSize() + 1;
  const int BB = 7 * GetFontSize() + 9;
  const int WB = 7;

  if(!dialog){
    dialog = new _generic_bitmap_dialog;
    int h = 3 * WB + 2 * BH, w = 2 * BB + 3 * WB, y = WB;
    // not a "Dialog_Window" since it is modal 
    dialog->window = new Fl_Double_Window(w, h);
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->b = new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Print text strings"); y += BH;
    dialog->b->type(FL_TOGGLE_BUTTON);
    dialog->ok = new Fl_Return_Button(WB, y + WB, BB, BH, "OK");
    dialog->cancel = new Fl_Button(2 * WB + BB, y + WB, BB, BH, "Cancel");
    dialog->window->set_modal();
    dialog->window->end();
    dialog->window->hotspot(dialog->window);
  }
  
  dialog->window->label(title);
  dialog->b->value(CTX.print.text);
  dialog->window->show();

  while(dialog->window->shown()){
    Fl::wait();
    for (;;) {
      Fl_Widget* o = Fl::readqueue();
      if (!o) break;
      if (o == dialog->ok) {
        opt_print_text(0, GMSH_SET | GMSH_GUI, (int)dialog->b->value());
        CreateOutputFile(name, format);
        dialog->window->hide();
        return 1;
      }
      if (o == dialog->window || o == dialog->cancel){
        dialog->window->hide();
        return 0;
      }
    }
  }
  return 0;
}

// TeX dialog

int latex_dialog(const char *name)
{
  struct _latex_dialog{
    Fl_Window *window;
    Fl_Check_Button *b;
    Fl_Button *ok, *cancel;
  };
  static _latex_dialog *dialog = NULL;

  const int BH = 2 * GetFontSize() + 1;
  const int BB = 7 * GetFontSize() + 9;
  const int WB = 7;

  if(!dialog){
    dialog = new _latex_dialog;
    int h = 3 * WB + 2 * BH, w = 2 * BB + 3 * WB, y = WB;
    // not a "Dialog_Window" since it is modal 
    dialog->window = new Fl_Double_Window(w, h, "LaTeX Options");
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->b = new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Print strings as equations"); y += BH;
    dialog->b->type(FL_TOGGLE_BUTTON);
    dialog->ok = new Fl_Return_Button(WB, y + WB, BB, BH, "OK");
    dialog->cancel = new Fl_Button(2 * WB + BB, y + WB, BB, BH, "Cancel");
    dialog->window->set_modal();
    dialog->window->end();
    dialog->window->hotspot(dialog->window);
  }
  
  dialog->b->value(CTX.print.tex_as_equation);
  dialog->window->show();

  while(dialog->window->shown()){
    Fl::wait();
    for (;;) {
      Fl_Widget* o = Fl::readqueue();
      if (!o) break;
      if (o == dialog->ok) {
        opt_print_tex_as_equation(0, GMSH_SET | GMSH_GUI, (int)dialog->b->value());
        CreateOutputFile(name, FORMAT_TEX);
        dialog->window->hide();
        return 1;
      }
      if (o == dialog->window || o == dialog->cancel){
        dialog->window->hide();
        return 0;
      }
    }
  }
  return 0;
}

// Save jpeg dialog

int jpeg_dialog(const char *name)
{
  struct _jpeg_dialog{
    Fl_Window *window;
    Fl_Value_Slider *s[2];
    Fl_Check_Button *b;
    Fl_Button *ok, *cancel;
  };
  static _jpeg_dialog *dialog = NULL;

  const int BH = 2 * GetFontSize() + 1;
  const int BB = 7 * GetFontSize() + 9;
  const int WB = 7;

  if(!dialog){
    dialog = new _jpeg_dialog;
    int h = 3 * WB + 4 * BH, w = 2 * BB + 3 * WB, y = WB;
    // not a "Dialog_Window" since it is modal 
    dialog->window = new Fl_Double_Window(w, h, "JPEG Options");
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->s[0] = new Fl_Value_Slider(WB, y, BB, BH, "Quality"); y += BH;
    dialog->s[0]->type(FL_HOR_SLIDER);
    dialog->s[0]->align(FL_ALIGN_RIGHT);
    dialog->s[0]->minimum(1);
    dialog->s[0]->maximum(100);
    dialog->s[0]->step(1);
    dialog->s[1] = new Fl_Value_Slider(WB, y, BB, BH, "Smoothing"); y += BH;
    dialog->s[1]->type(FL_HOR_SLIDER);
    dialog->s[1]->align(FL_ALIGN_RIGHT);
    dialog->s[1]->minimum(0);
    dialog->s[1]->maximum(100);
    dialog->s[1]->step(1);
    dialog->b = new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Print text strings"); y += BH;
    dialog->b->type(FL_TOGGLE_BUTTON);
    dialog->ok = new Fl_Return_Button(WB, y + WB, BB, BH, "OK");
    dialog->cancel = new Fl_Button(2 * WB + BB, y + WB, BB, BH, "Cancel");
    dialog->window->set_modal();
    dialog->window->end();
    dialog->window->hotspot(dialog->window);
  }
  
  dialog->s[0]->value(CTX.print.jpeg_quality);
  dialog->s[1]->value(CTX.print.jpeg_smoothing);
  dialog->b->value(CTX.print.text);
  dialog->window->show();

  while(dialog->window->shown()){
    Fl::wait();
    for (;;) {
      Fl_Widget* o = Fl::readqueue();
      if (!o) break;
      if (o == dialog->ok) {
        opt_print_jpeg_quality(0, GMSH_SET | GMSH_GUI, (int)dialog->s[0]->value());
        opt_print_jpeg_smoothing(0, GMSH_SET | GMSH_GUI, (int)dialog->s[1]->value());
        opt_print_text(0, GMSH_SET | GMSH_GUI, (int)dialog->b->value());
        CreateOutputFile(name, FORMAT_JPEG);
        dialog->window->hide();
        return 1;
      }
      if (o == dialog->window || o == dialog->cancel){
        dialog->window->hide();
        return 0;
      }
    }
  }
  return 0;
}

// Save gif dialog

int gif_dialog(const char *name)
{
  struct _gif_dialog{
    Fl_Window *window;
    Fl_Check_Button *b[5];
    Fl_Button *ok, *cancel;
  };
  static _gif_dialog *dialog = NULL;

  const int BH = 2 * GetFontSize() + 1;
  const int BB = 7 * GetFontSize() + 9;
  const int WB = 7;

  if(!dialog){
    dialog = new _gif_dialog;
    int h = 3 * WB + 6 * BH, w = 2 * BB + 3 * WB, y = WB;
    // not a "Dialog_Window" since it is modal 
    dialog->window = new Fl_Double_Window(w, h, "GIF Options");
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->b[0] = new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Dither"); y += BH;
    dialog->b[1] = new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Interlace"); y += BH;
    dialog->b[2] = new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Sort colormap"); y += BH;
    dialog->b[3] = new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Transparent background"); y += BH;
    dialog->b[4] = new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Print text strings"); y += BH;
    for(int i = 0; i < 5; i++){
      dialog->b[i]->type(FL_TOGGLE_BUTTON);
    }
    dialog->ok = new Fl_Return_Button(WB, y + WB, BB, BH, "OK");
    dialog->cancel = new Fl_Button(2 * WB + BB, y + WB, BB, BH, "Cancel");
    dialog->window->set_modal();
    dialog->window->end();
    dialog->window->hotspot(dialog->window);
  }
  
  dialog->b[0]->value(CTX.print.gif_dither);
  dialog->b[1]->value(CTX.print.gif_interlace);
  dialog->b[2]->value(CTX.print.gif_sort);
  dialog->b[3]->value(CTX.print.gif_transparent);
  dialog->b[4]->value(CTX.print.text);
  dialog->window->show();

  while(dialog->window->shown()){
    Fl::wait();
    for (;;) {
      Fl_Widget* o = Fl::readqueue();
      if (!o) break;
      if (o == dialog->ok) {
        opt_print_gif_dither(0, GMSH_SET | GMSH_GUI, dialog->b[0]->value());
        opt_print_gif_interlace(0, GMSH_SET | GMSH_GUI, dialog->b[1]->value());
        opt_print_gif_sort(0, GMSH_SET | GMSH_GUI, dialog->b[2]->value());
        opt_print_gif_transparent(0, GMSH_SET | GMSH_GUI, dialog->b[3]->value());
        opt_print_text(0, GMSH_SET | GMSH_GUI, dialog->b[4]->value());
        CreateOutputFile(name, FORMAT_GIF);
        dialog->window->hide();
        return 1;
      }
      if (o == dialog->window || o == dialog->cancel){
        dialog->window->hide();
        return 0;
      }
    }
  }
  return 0;
}

// Save ps/eps/pdf dialog

static void activate_gl2ps_choices(int format, int quality, Fl_Check_Button *b[5])
{
#if defined(HAVE_LIBZ)
  b[0]->activate();
#else
  b[0]->deactivate();
#endif
  switch(quality){
  case 0: // raster
    b[1]->deactivate(); 
    b[2]->deactivate(); 
    b[3]->deactivate(); 
    b[4]->deactivate();
    break;
  case 1: // simple sort
  case 3: // unsorted
    b[1]->activate();   
    b[2]->activate();
    b[3]->deactivate(); 
    if(format == FORMAT_PDF || format == FORMAT_SVG)
      b[4]->deactivate();
    else
      b[4]->activate();
    break;
  case 2: // bsp sort
    b[1]->activate();   
    b[2]->activate();
    b[3]->activate();   
    if(format == FORMAT_PDF || format == FORMAT_SVG)
      b[4]->deactivate();
    else
      b[4]->activate();
    break;
  }
}

int gl2ps_dialog(const char *name, const char *title, int format)
{
  struct _gl2ps_dialog{
    Fl_Window *window;
    Fl_Check_Button *b[6];
    Fl_Choice *c;
    Fl_Button *ok, *cancel;
  };
  static _gl2ps_dialog *dialog = NULL;

  static Fl_Menu_Item sortmenu[] = {
    {"Raster image", 0, 0, 0},
    {"Vector simple sort", 0, 0, 0},
    {"Vector accurate sort", 0, 0, 0},
    {"Vector unsorted", 0, 0, 0},
    {0}
  };

  const int BH = 2 * GetFontSize() + 1;
  const int BB = 7 * GetFontSize() + 9;
  const int WB = 7;

  if(!dialog){
    dialog = new _gl2ps_dialog;
    int h = 3 * WB + 8 * BH, w = 2 * BB + 3 * WB, y = WB;
    // not a "Dialog_Window" since it is modal 
    dialog->window = new Fl_Double_Window(w, h);
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->c = new Fl_Choice(WB, y, BB + WB + BB / 2, BH, "Type"); y += BH;
    dialog->c->menu(sortmenu);
    dialog->c->align(FL_ALIGN_RIGHT);
    dialog->b[0] = new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Compress"); y += BH;
    dialog->b[1] = new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Print background"); y += BH;
    dialog->b[2] = new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Remove hidden primitives"); y += BH;
    dialog->b[3] = new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Optimize BSP tree"); y += BH;
    dialog->b[4] = new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Use level 3 shading"); y += BH;
    dialog->b[5] = new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Print text strings"); y += BH;
    for(int i = 0; i < 6; i++){
      dialog->b[i]->type(FL_TOGGLE_BUTTON);
    }
    dialog->ok = new Fl_Return_Button(WB, y + WB, BB, BH, "OK");
    dialog->cancel = new Fl_Button(2 * WB + BB, y + WB, BB, BH, "Cancel");
    dialog->window->set_modal();
    dialog->window->end();
    dialog->window->hotspot(dialog->window);
  }
  
  dialog->window->label(title);
  dialog->c->value(CTX.print.eps_quality);
  dialog->b[0]->value(CTX.print.eps_compress);
  dialog->b[1]->value(CTX.print.eps_background);
  dialog->b[2]->value(CTX.print.eps_occlusion_culling);
  dialog->b[3]->value(CTX.print.eps_best_root);
  dialog->b[4]->value(CTX.print.eps_ps3shading);
  dialog->b[5]->value(CTX.print.text);

  activate_gl2ps_choices(format, CTX.print.eps_quality, dialog->b);

  dialog->window->show();

  while(dialog->window->shown()){
    Fl::wait();
    for (;;) {
      Fl_Widget* o = Fl::readqueue();
      if (!o) break;

      if (o == dialog->c){
        activate_gl2ps_choices(format, dialog->c->value(), dialog->b);
      }
      if (o == dialog->ok) {
        opt_print_eps_quality(0, GMSH_SET | GMSH_GUI, dialog->c->value());
        opt_print_eps_compress(0, GMSH_SET | GMSH_GUI, dialog->b[0]->value());
        opt_print_eps_background(0, GMSH_SET | GMSH_GUI, dialog->b[1]->value());
        opt_print_eps_occlusion_culling(0, GMSH_SET | GMSH_GUI, dialog->b[2]->value());
        opt_print_eps_best_root(0, GMSH_SET | GMSH_GUI, dialog->b[3]->value());
        opt_print_eps_ps3shading(0, GMSH_SET | GMSH_GUI, dialog->b[4]->value());
        opt_print_text(0, GMSH_SET | GMSH_GUI, dialog->b[5]->value());
        CreateOutputFile(name, format);
        dialog->window->hide();
        return 1;
      }
      if (o == dialog->window || o == dialog->cancel){
        dialog->window->hide();
        return 0;
      }
    }
  }
  return 0;
}

// Save options dialog

int options_dialog(const char *name)
{
  struct _options_dialog{
    Fl_Window *window;
    Fl_Check_Button *b[2];
    Fl_Button *ok, *cancel;
  };
  static _options_dialog *dialog = NULL;

  const int BH = 2 * GetFontSize() + 1;
  const int BB = 7 * GetFontSize() + 9;
  const int WB = 7;

  if(!dialog){
    dialog = new _options_dialog;
    int h = 3 * WB + 3 * BH, w = 2 * BB + 3 * WB, y = WB;
    // not a "Dialog_Window" since it is modal 
    dialog->window = new Fl_Double_Window(w, h, "Options");
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->b[0] = new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Save only modified options"); y += BH;
    dialog->b[0]->value(1);
    dialog->b[0]->type(FL_TOGGLE_BUTTON);
    dialog->b[1] = new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Print help strings"); y += BH;
    dialog->b[1]->value(0);
    dialog->b[1]->type(FL_TOGGLE_BUTTON);
    dialog->ok = new Fl_Return_Button(WB, y + WB, BB, BH, "OK");
    dialog->cancel = new Fl_Button(2 * WB + BB, y + WB, BB, BH, "Cancel");
    dialog->window->set_modal();
    dialog->window->end();
    dialog->window->hotspot(dialog->window);
  }
  
  dialog->window->show();

  while(dialog->window->shown()){
    Fl::wait();
    for (;;) {
      Fl_Widget* o = Fl::readqueue();
      if (!o) break;
      if (o == dialog->ok) {
        Print_Options(0, GMSH_FULLRC, dialog->b[0]->value(), dialog->b[1]->value(), name);
        dialog->window->hide();
        return 1;
      }
      if (o == dialog->window || o == dialog->cancel){
        dialog->window->hide();
        return 0;
      }
    }
  }
  return 0;
}

// geo dialog

int geo_dialog(const char *name)
{
  struct _geo_dialog{
    Fl_Window *window;
    Fl_Check_Button *b;
    Fl_Button *ok, *cancel;
  };
  static _geo_dialog *dialog = NULL;

  const int BH = 2 * GetFontSize() + 1;
  const int BB = 7 * GetFontSize() + 9;
  const int WB = 7;

  if(!dialog){
    dialog = new _geo_dialog;
    int h = 3 * WB + 2 * BH, w = 2 * BB + 3 * WB, y = WB;
    // not a "Dialog_Window" since it is modal 
    dialog->window = new Fl_Double_Window(w, h, "GEO Options");
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->b = new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Save physical group labels"); y += BH;
    dialog->b->type(FL_TOGGLE_BUTTON);
    dialog->ok = new Fl_Return_Button(WB, y + WB, BB, BH, "OK");
    dialog->cancel = new Fl_Button(2 * WB + BB, y + WB, BB, BH, "Cancel");
    dialog->window->set_modal();
    dialog->window->end();
    dialog->window->hotspot(dialog->window);
  }
  
  dialog->b->value(CTX.print.geo_labels ? 1 : 0);
  dialog->window->show();

  while(dialog->window->shown()){
    Fl::wait();
    for (;;) {
      Fl_Widget* o = Fl::readqueue();
      if (!o) break;
      if (o == dialog->ok) {
        opt_print_geo_labels(0, GMSH_SET | GMSH_GUI, dialog->b->value() ? 1 : 0);
        CreateOutputFile(name, FORMAT_GEO);
        dialog->window->hide();
        return 1;
      }
      if (o == dialog->window || o == dialog->cancel){
        dialog->window->hide();
        return 0;
      }
    }
  }
  return 0;
}

int pos_dialog(const char *name)
{
  struct _pos_dialog{
    Fl_Window *window;
    Fl_Check_Button *b[6];
    Fl_Button *ok, *cancel;
  };
  static _pos_dialog *dialog = NULL;

  const int BH = 2 * GetFontSize() + 1;
  const int BB = 7 * GetFontSize() + 9;
  const int WB = 7;

  if(!dialog){
    dialog = new _pos_dialog;
    int h = 3 * WB + 7 * BH, w = 2 * BB + 3 * WB, y = WB;
    // not a "Dialog_Window" since it is modal 
    dialog->window = new Fl_Double_Window(w, h, "POS Options");
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->b[0] = new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Save all (ignore physical groups)"); y += BH;
    dialog->b[1] = new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Print elementary tags"); y += BH;
    dialog->b[2] = new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Print element numbers"); y += BH;
    dialog->b[3] = new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Print Gamma quality measure"); y += BH;
    dialog->b[4] = new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Print Eta quality measure"); y += BH;
    dialog->b[5] = new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Print Rho quality measure"); y += BH;
    for(int i = 0; i < 5; i++)
      dialog->b[i]->type(FL_TOGGLE_BUTTON);
    dialog->ok = new Fl_Return_Button(WB, y + WB, BB, BH, "OK");
    dialog->cancel = new Fl_Button(2 * WB + BB, y + WB, BB, BH, "Cancel");
    dialog->window->set_modal();
    dialog->window->end();
    dialog->window->hotspot(dialog->window);
  }
  
  dialog->b[0]->value(CTX.mesh.save_all ? 1 : 0);
  dialog->b[1]->value(CTX.print.pos_elementary ? 1 : 0);
  dialog->b[2]->value(CTX.print.pos_element ? 1 : 0);
  dialog->b[3]->value(CTX.print.pos_gamma ? 1 : 0);
  dialog->b[4]->value(CTX.print.pos_eta ? 1 : 0);
  dialog->b[5]->value(CTX.print.pos_rho ? 1 : 0);
  dialog->window->show();

  while(dialog->window->shown()){
    Fl::wait();
    for (;;) {
      Fl_Widget* o = Fl::readqueue();
      if (!o) break;
      if (o == dialog->ok) {
        opt_mesh_save_all(0, GMSH_SET | GMSH_GUI, dialog->b[0]->value() ? 1 : 0);
        opt_print_pos_elementary(0, GMSH_SET | GMSH_GUI, dialog->b[1]->value() ? 1 : 0);
        opt_print_pos_element(0, GMSH_SET | GMSH_GUI, dialog->b[2]->value() ? 1 : 0);
        opt_print_pos_gamma(0, GMSH_SET | GMSH_GUI, dialog->b[3]->value() ? 1 : 0);
        opt_print_pos_eta(0, GMSH_SET | GMSH_GUI, dialog->b[4]->value() ? 1 : 0);
        opt_print_pos_rho(0, GMSH_SET | GMSH_GUI, dialog->b[5]->value() ? 1 : 0);
        CreateOutputFile(name, FORMAT_POS);
        dialog->window->hide();
        return 1;
      }
      if (o == dialog->window || o == dialog->cancel){
        dialog->window->hide();
        return 0;
      }
    }
  }
  return 0;
}

// Generic save mesh dialog

int generic_mesh_dialog(const char *name, const char *title, int format)
{
  struct _generic_mesh_dialog{
    Fl_Window *window;
    Fl_Check_Button *b;
    Fl_Button *ok, *cancel;
  };
  static _generic_mesh_dialog *dialog = NULL;

  const int BH = 2 * GetFontSize() + 1;
  const int BB = 7 * GetFontSize() + 9;
  const int WB = 7;

  if(!dialog){
    dialog = new _generic_mesh_dialog;
    int h = 3 * WB + 2 * BH, w = 2 * BB + 3 * WB, y = WB;
    // not a "Dialog_Window" since it is modal 
    dialog->window = new Fl_Double_Window(w, h);
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->b = new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Save all (ignore physical groups)"); y += BH;
    dialog->b->type(FL_TOGGLE_BUTTON);
    dialog->ok = new Fl_Return_Button(WB, y + WB, BB, BH, "OK");
    dialog->cancel = new Fl_Button(2 * WB + BB, y + WB, BB, BH, "Cancel");
    dialog->window->set_modal();
    dialog->window->end();
    dialog->window->hotspot(dialog->window);
  }
  
  dialog->window->label(title);
  dialog->b->value(CTX.mesh.save_all ? 1 : 0);
  dialog->window->show();

  while(dialog->window->shown()){
    Fl::wait();
    for (;;) {
      Fl_Widget* o = Fl::readqueue();
      if (!o) break;
      if (o == dialog->ok) {
        opt_mesh_save_all(0, GMSH_SET | GMSH_GUI, dialog->b->value() ? 1 : 0);
        CreateOutputFile(name, format);
        dialog->window->hide();
        return 1;
      }
      if (o == dialog->window || o == dialog->cancel){
        dialog->window->hide();
        return 0;
      }
    }
  }
  return 0;
}

// Save msh dialog

int msh_dialog(const char *name)
{
  struct _msh_dialog{
    Fl_Window *window;
    Fl_Check_Button *b;
    Fl_Choice *c;
    Fl_Button *ok, *cancel;
  };
  static _msh_dialog *dialog = NULL;

  static Fl_Menu_Item formatmenu[] = {
    {"Version 1.0", 0, 0, 0},
    {"Version 2.0 ASCII", 0, 0, 0},
    {"Version 2.0 Binary", 0, 0, 0},
    {0}
  };

  const int BH = 2 * GetFontSize() + 1;
  const int BB = 7 * GetFontSize() + 9;
  const int WB = 7;

  if(!dialog){
    dialog = new _msh_dialog;
    int h = 3 * WB + 3 * BH, w = 2 * BB + 3 * WB, y = WB;
    // not a "Dialog_Window" since it is modal 
    dialog->window = new Fl_Double_Window(w, h, "MSH Options");
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->c = new Fl_Choice(WB, y, BB + BB / 2, BH, "Format"); y += BH;
    dialog->c->menu(formatmenu);
    dialog->c->align(FL_ALIGN_RIGHT);
    dialog->b = new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Save all (ignore physical groups)"); y += BH;
    dialog->b->type(FL_TOGGLE_BUTTON);
    dialog->ok = new Fl_Return_Button(WB, y + WB, BB, BH, "OK");
    dialog->cancel = new Fl_Button(2 * WB + BB, y + WB, BB, BH, "Cancel");
    dialog->window->set_modal();
    dialog->window->end();
    dialog->window->hotspot(dialog->window);
  }
  
  dialog->c->value((CTX.mesh.msh_file_version == 1.0) ? 0 : 
                   CTX.mesh.msh_binary ? 2 : 1);
  dialog->b->value(CTX.mesh.save_all ? 1 : 0);
  dialog->window->show();

  while(dialog->window->shown()){
    Fl::wait();
    for (;;) {
      Fl_Widget* o = Fl::readqueue();
      if (!o) break;
      if (o == dialog->ok) {
        opt_mesh_msh_file_version(0, GMSH_SET | GMSH_GUI, 
                                  (dialog->c->value() == 0) ? 1. : 2.);
        opt_mesh_msh_binary(0, GMSH_SET | GMSH_GUI, 
                            (dialog->c->value() == 2) ? 1 : 0);
        opt_mesh_save_all(0, GMSH_SET | GMSH_GUI, dialog->b->value() ? 1 : 0);
        CreateOutputFile(name, FORMAT_MSH);
        dialog->window->hide();
        return 1;
      }
      if (o == dialog->window || o == dialog->cancel){
        dialog->window->hide();
        return 0;
      }
    }
  }
  return 0;
}

// unv mesh dialog

int unv_dialog(const char *name)
{
  struct _unv_dialog{
    Fl_Window *window;
    Fl_Check_Button *b[2];
    Fl_Button *ok, *cancel;
  };
  static _unv_dialog *dialog = NULL;

  const int BH = 2 * GetFontSize() + 1;
  const int BB = 7 * GetFontSize() + 9;
  const int WB = 7;

  if(!dialog){
    dialog = new _unv_dialog;
    int h = 3 * WB + 3 * BH, w = 2 * BB + 3 * WB, y = WB;
    // not a "Dialog_Window" since it is modal 
    dialog->window = new Fl_Double_Window(w, h, "UNV Options");
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->b[0] = new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Save all (ignore physical groups)"); y += BH;
    dialog->b[0]->type(FL_TOGGLE_BUTTON);
    dialog->b[1] = new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Save groups of nodes"); y += BH;
    dialog->b[1]->type(FL_TOGGLE_BUTTON);
    dialog->ok = new Fl_Return_Button(WB, y + WB, BB, BH, "OK");
    dialog->cancel = new Fl_Button(2 * WB + BB, y + WB, BB, BH, "Cancel");
    dialog->window->set_modal();
    dialog->window->end();
    dialog->window->hotspot(dialog->window);
  }
  
  dialog->b[0]->value(CTX.mesh.save_all ? 1 : 0);
  dialog->b[1]->value(CTX.mesh.save_groups_of_nodes ? 1 : 0);
  dialog->window->show();

  while(dialog->window->shown()){
    Fl::wait();
    for (;;) {
      Fl_Widget* o = Fl::readqueue();
      if (!o) break;
      if (o == dialog->ok) {
        opt_mesh_save_all(0, GMSH_SET | GMSH_GUI, dialog->b[0]->value() ? 1 : 0);
        opt_mesh_save_groups_of_nodes(0, GMSH_SET | GMSH_GUI, dialog->b[1]->value() ? 1 : 0);
        CreateOutputFile(name, FORMAT_UNV);
        dialog->window->hide();
        return 1;
      }
      if (o == dialog->window || o == dialog->cancel){
        dialog->window->hide();
        return 0;
      }
    }
  }
  return 0;
}

// Save bdf dialog

int bdf_dialog(const char *name)
{
  struct _bdf_dialog{
    Fl_Window *window;
    Fl_Choice *c;
    Fl_Check_Button *b;
    Fl_Button *ok, *cancel;
  };
  static _bdf_dialog *dialog = NULL;

  static Fl_Menu_Item formatmenu[] = {
    {"Free field", 0, 0, 0},
    {"Small field", 0, 0, 0},
    {"Long field", 0, 0, 0},
    {0}
  };

  const int BH = 2 * GetFontSize() + 1;
  const int BB = 7 * GetFontSize() + 9;
  const int WB = 7;

  if(!dialog){
    dialog = new _bdf_dialog;
    int h = 3 * WB + 3 * BH, w = 2 * BB + 3 * WB, y = WB;
    // not a "Dialog_Window" since it is modal 
    dialog->window = new Fl_Double_Window(w, h, "BDF Options");
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->c = new Fl_Choice(WB, y, BB + BB / 2, BH, "Format"); y += BH;
    dialog->c->menu(formatmenu);
    dialog->c->align(FL_ALIGN_RIGHT);
    dialog->b = new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Save all (ignore physical groups)"); y += BH;
    dialog->b->type(FL_TOGGLE_BUTTON);
    dialog->ok = new Fl_Return_Button(WB, y + WB, BB, BH, "OK");
    dialog->cancel = new Fl_Button(2 * WB + BB, y + WB, BB, BH, "Cancel");
    dialog->window->set_modal();
    dialog->window->end();
    dialog->window->hotspot(dialog->window);
  }
  
  dialog->c->value(CTX.mesh.bdf_field_format);
  dialog->b->value(CTX.mesh.save_all ? 1 : 0);
  dialog->window->show();

  while(dialog->window->shown()){
    Fl::wait();
    for (;;) {
      Fl_Widget* o = Fl::readqueue();
      if (!o) break;
      if (o == dialog->ok) {
        opt_mesh_bdf_field_format(0, GMSH_SET | GMSH_GUI, dialog->c->value());
        opt_mesh_save_all(0, GMSH_SET | GMSH_GUI, dialog->b->value() ? 1 : 0);
        CreateOutputFile(name, FORMAT_BDF);
        dialog->window->hide();
        return 1;
      }
      if (o == dialog->window || o == dialog->cancel){
        dialog->window->hide();
        return 0;
      }
    }
  }
  return 0;
}

// Save stl dialog

int stl_dialog(const char *name)
{
  struct _stl_dialog{
    Fl_Window *window;
    Fl_Choice *c;
    Fl_Check_Button *b;
    Fl_Button *ok, *cancel;
  };
  static _stl_dialog *dialog = NULL;

  static Fl_Menu_Item formatmenu[] = {
    {"ASCII", 0, 0, 0},
    {"Binary", 0, 0, 0},
    {0}
  };

  const int BH = 2 * GetFontSize() + 1;
  const int BB = 7 * GetFontSize() + 9;
  const int WB = 7;

  if(!dialog){
    dialog = new _stl_dialog;
    int h = 3 * WB + 3 * BH, w = 2 * BB + 3 * WB, y = WB;
    // not a "Dialog_Window" since it is modal 
    dialog->window = new Fl_Double_Window(w, h, "STL Options");
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->c = new Fl_Choice(WB, y, BB + BB / 2, BH, "Format"); y += BH;
    dialog->c->menu(formatmenu);
    dialog->c->align(FL_ALIGN_RIGHT);
    dialog->b = new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Save all (ignore physical groups)"); y += BH;
    dialog->b->type(FL_TOGGLE_BUTTON);
    dialog->ok = new Fl_Return_Button(WB, y + WB, BB, BH, "OK");
    dialog->cancel = new Fl_Button(2 * WB + BB, y + WB, BB, BH, "Cancel");
    dialog->window->set_modal();
    dialog->window->end();
    dialog->window->hotspot(dialog->window);
  }
  
  dialog->c->value(CTX.mesh.stl_binary ? 1 : 0);
  dialog->b->value(CTX.mesh.save_all ? 1 : 0);
  dialog->window->show();

  while(dialog->window->shown()){
    Fl::wait();
    for (;;) {
      Fl_Widget* o = Fl::readqueue();
      if (!o) break;
      if (o == dialog->ok) {
        opt_mesh_stl_binary(0, GMSH_SET | GMSH_GUI, dialog->c->value());
        opt_mesh_save_all(0, GMSH_SET | GMSH_GUI, dialog->b->value() ? 1 : 0);
        CreateOutputFile(name, FORMAT_STL);
        dialog->window->hide();
        return 1;
      }
      if (o == dialog->window || o == dialog->cancel){
        dialog->window->hide();
        return 0;
      }
    }
  }
  return 0;
}

// Partition dialog

struct PartitionDialog 
{
  Fl_Choice *choicePartitioner;
  Fl_Choice *choiceChacoAlg;
  Fl_Choice *choiceMetisAlg;
  Fl_Toggle_Button *toggleButtonAdvChaco;
  Fl_Toggle_Button *toggleButtonAdvMetis;
  Fl_Choice *choiceArchitecture;
  Fl_Value_Input *inputNumPartition;
  Fl_Value_Input *inputNumPartition1;
  Fl_Value_Input *inputNumPartition2;
  Fl_Value_Input *inputNumPartition3;
  Fl_Choice *choiceDivisions;
  Fl_Choice *choiceEigensolver;
  Fl_Choice *choiceLocalAlgorithm;
  Fl_Check_Button *checkButtonTermProp;
};

inline void partition_opt_chaco_globalalg_cb(Fl_Widget *widget, void *data)
{
  PartitionDialog *dlg = static_cast<PartitionDialog*>(data);
  unsigned opt = dlg->choiceChacoAlg->value();
  if(opt == 0) {
    dlg->choiceLocalAlgorithm->value(0);
    dlg->choiceLocalAlgorithm->deactivate();
  }
  else {
    dlg->choiceLocalAlgorithm->activate();
  }
  if(opt == 1) {
    dlg->choiceEigensolver->activate();
    if(dlg->choiceDivisions->value() != 0 &&
       dlg->checkButtonTermProp->value())
      dlg->choiceDivisions->value(0);
  }
  else {
    dlg->choiceEigensolver->deactivate();
  }
}

inline void partition_opt_architecture_cb(Fl_Widget *widget, void *data)
{
  PartitionDialog *dlg = static_cast<PartitionDialog*>(data);
  switch(static_cast<int>(dlg->choiceArchitecture->value())) {
  case 0:
    dlg->inputNumPartition1->maximum(31);
    dlg->inputNumPartition2->deactivate();
    dlg->inputNumPartition3->deactivate();
    break;
  case 1:
    dlg->inputNumPartition1->maximum(std::numeric_limits<int>::max());
    dlg->inputNumPartition2->deactivate();
    dlg->inputNumPartition3->deactivate();
    break;
  case 2:
    dlg->inputNumPartition1->maximum(std::numeric_limits<int>::max());
    dlg->inputNumPartition2->activate();
    dlg->inputNumPartition3->deactivate();
    break;
  case 3:
    dlg->inputNumPartition1->maximum(std::numeric_limits<int>::max());
    dlg->inputNumPartition2->activate();
    dlg->inputNumPartition3->activate();
    break;
  }
}

inline void partition_opt_num_partitions_cb(Fl_Widget *widget, void *data)
{
  PartitionDialog *dlg = static_cast<PartitionDialog*>(data);
  unsigned val;
  if(widget == dlg->inputNumPartition) {
    val = dlg->inputNumPartition->value();
    switch(static_cast<int>(dlg->choiceArchitecture->value())) {
    case 0:
      {
        unsigned y = 0;
        unsigned x = val;
        while(x >>= 1) ++y;
        dlg->inputNumPartition1->value(y);
      }
      break;
    case 1:
    case 2:
    case 3:
      dlg->inputNumPartition1->value(val);
      dlg->inputNumPartition2->value(1);
      dlg->inputNumPartition3->value(1);
      break;
    }
  }
  else {
    switch(static_cast<int>(dlg->choiceArchitecture->value())) {
    case 0:
      {
        unsigned x = dlg->inputNumPartition1->value();
        val = 1 << x;
      }
      break;
    case 1:
      val = dlg->inputNumPartition1->value();
      break;
    case 2:
      val = dlg->inputNumPartition1->value()*dlg->inputNumPartition2->value();
      break;
    case 3:
      val = dlg->inputNumPartition1->value()*dlg->inputNumPartition2->value()*
        dlg->inputNumPartition3->value();
      break;
    }
    dlg->inputNumPartition->value(val);
  }
  if(dlg->choicePartitioner->value() == 1) {
    dlg->choiceMetisAlg->value((val <= 8) ? 0: 1);
  }
}

inline void partition_opt_spectralcheck_cb(Fl_Widget *widget, void *data)
{
  PartitionDialog *dlg = static_cast<PartitionDialog*>(data);
  if(dlg->choiceChacoAlg->value() == 1) {
    if(widget == dlg->choiceDivisions && dlg->choiceDivisions->value() != 0)
      dlg->checkButtonTermProp->value(0);
    else if(widget == dlg->checkButtonTermProp)
      dlg->choiceDivisions->value(0);
  }
}

inline void partition_partition_cb(Fl_Widget *widget, void *data)
{
  Fl::delete_widget(widget->window());
}
inline void partition_cancel_cb(Fl_Widget *widget, void *data)
{
  Fl::delete_widget(widget->window());
}
inline void partition_select_groups_cb(Fl_Widget *widget, void *data)
{
  PartitionDialog *dlg = static_cast<PartitionDialog*>(data);
  const int WB = 7;                     // Window border
  Fl_Window *const w = widget->window();
  // Get the groups
  Fl_Widget *const *g = w->array();
  int y = g[0]->h();
  switch(dlg->choicePartitioner->value()) {
  case 0:
    g[1]->show();
    y += g[1]->h();
    if(dlg->toggleButtonAdvChaco->value()) {
      g[2]->show();
      y += g[2]->h();
    }
    else g[2]->hide();
    g[3]->hide();
    g[4]->hide();
    break;
  case 1:
    g[3]->show();
    y += g[3]->h();
    if(dlg->toggleButtonAdvMetis->value()) {
      g[4]->show();
      y += g[4]->h();
    }
    else g[4]->hide();
    g[1]->hide();
    g[2]->hide();
    break;
  }
  // Reset the vertical position of all widgets in group 6
  {
    int yG = y;
    g[5]->position(g[5]->x(), yG);
    Fl_Widget *o = static_cast<Fl_Group*>(g[5])->child(0);
    o->position(o->x(), yG);
    yG += WB + o->h();
    o = static_cast<Fl_Group*>(g[5])->child(1);
    o->position(o->x(), yG);
    o = static_cast<Fl_Group*>(g[5])->child(2);
    o->position(o->x(), yG);
    yG += WB + o->h();
  }
  y += g[5]->h();
  // Resize and redraw the window
  w->size(w->w(), y);
  w->redraw();
}

int partition_dialog()
{
  static PartitionDialog dlg;

  static Fl_Menu_Item partitionTypeMenu[] = {
    {"Chaco", 0, 0, 0},
    {"Metis", 0, 0, 0},
    {0}
  };

  static Fl_Menu_Item chacoAlgMenu[] = {
    {"Multilevel-KL", 0, 0, 0},
    {"Spectral", 0, 0, 0},
    {"Inertial", 0, 0, 0, FL_MENU_INACTIVE},
    {"Linear", 0, 0, 0},
    {"Random", 0, 0, 0},
    {"Scattered", 0, 0, 0},
    {0}
  };

  static Fl_Menu_Item metisAlgMenu[] = {
    {"Recursive", 0, 0, 0},
    {"K-way", 0, 0, 0},
    {0}
  };

  static Fl_Menu_Item chachoArchitectureMenu[] = {
    {"Hypercube", 0, 0, 0},
    {"1-D Mesh", 0, 0, 0},
    {"2-D Mesh", 0, 0, 0},
    {"3-D Mesh", 0, 0, 0},
    {0}
  };

  static Fl_Menu_Item chachoLocalMethodMenu[] = {
    {"Kernighan-Lin", 0, 0, 0},
    {"None", 0, 0, 0},
    {0}
  };

  static Fl_Menu_Item chachoEigSolMenu[] = {
    {"Lanczos", 0, 0, 0},
    {"Multilevel RQI/Symmlq", 0, 0, 0},
    {0}
  };

  static Fl_Menu_Item chachoDivisionsMenu[] = {
    {"Bisection", 0, 0, 0},
    {"Quadrisection", 0, 0, 0},
    {"Octasection", 0, 0, 0},
    {0}
  };

  static Fl_Menu_Item metisEdgeMatchingMenu[] = {
    {"Random", 0, 0, 0},
    {"Heavy-edge", 0, 0, 0},
    {"Sorted heavy-edge", 0, 0, 0},
    {0}
  };

  static Fl_Menu_Item metisRefineAlgMenu[] = {
    {"Random", 0, 0, 0},
    {"Greedy", 0, 0, 0},
    {"Random (Min. Conn.)", 0, 0, 0},
    {0}
  };

  const int IW = 10*GetFontSize();      // Input field width
  const int BH = 2*GetFontSize() + 1;   // button height
  const int BB = 7*GetFontSize() + 9;   // Width of a button with an internal
                                        // label
  const int WB = 7;                     // Window border

  const int h = 3 * WB + 3 * BH;
  const int w = 3 * BB + IW + 3 * WB;
  int y = 0;

  Fl_Double_Window *const window =
    new Fl_Double_Window(w, h, "Partitioner Options");
  window->box(GMSH_WINDOW_BOX);

  // Main options group [0]
  {
    const int GH = BH + 2 + 3*WB;
    y += WB;
    Fl_Group *g = new Fl_Group(0, y, w, GH);
    // Partitioner
    {
      Fl_Choice *const o = new Fl_Choice(WB, y, BB, BH, "Partitioner");
      dlg.choicePartitioner = o;
      o->menu(partitionTypeMenu);
      o->value(CTX.mesh.partition_options.partitioner - 1);
      o->callback((Fl_Callback *)partition_select_groups_cb, &dlg);
      o->align(FL_ALIGN_RIGHT);
    }
    // Number of partitions
    {
      Fl_Value_Input *const o = new Fl_Value_Input
        (2*WB + 2*BB, y, IW, BH, "Number of\nPartitions");
      dlg.inputNumPartition = o;
      o->minimum(1);
      o->maximum(std::numeric_limits<int>::max());
      o->value(CTX.mesh.partition_options.num_partitions);
      o->callback((Fl_Callback *)partition_opt_num_partitions_cb, &dlg);
      o->step(1);
      o->align(FL_ALIGN_RIGHT);
    }
    y += BH + WB;
    // Box (line)
    { Fl_Box* o = new Fl_Box(WB, y, w - 2*WB, 2);
      o->box(FL_ENGRAVED_FRAME);
      o->labeltype(FL_NO_LABEL);
    }
    y += 2 + WB;
    g->end();
    g->show();
  }
  const int yMain = y;

  // Chaco options group [1]
  {
    const int GH = BH + WB;
    Fl_Group *g = new Fl_Group(0, y, w, GH);
    // Algorithm
    {
      Fl_Choice *const o = new Fl_Choice(WB, y, IW, BH, "Global Algorithm");
      dlg.choiceChacoAlg = o;
      o->menu(chacoAlgMenu);
      o->value(CTX.mesh.partition_options.algorithm - 1);
      o->callback((Fl_Callback *)partition_opt_chaco_globalalg_cb, &dlg);
      o->align(FL_ALIGN_RIGHT);
    }
    // Advanced Button
    {
      Fl_Toggle_Button *const o = new Fl_Toggle_Button
        (w - (WB + BB), y, BB, BH, "Advanced @-22->");
      dlg.toggleButtonAdvChaco = o;
      o->callback((Fl_Callback *)partition_select_groups_cb, &dlg);
    }
    y += BH + WB;
    g->end();
    g->hide();
  }

  // Chaco advanced options group [2]
  {
    const int GH = 2 + WB + 5*(BH + WB) + BH + 6;
    Fl_Group *g = new Fl_Group(0, y, w, GH);
    // Box (line)
    {
      Fl_Box *const o = new Fl_Box(WB, y, w - 2*WB, 2);
      o->box(FL_ENGRAVED_FRAME);
      o->labeltype(FL_NO_LABEL);
    }
    y += 2 + WB + 1;  // +1 for multiline label
    {
      Fl_Choice *const o = new Fl_Choice(WB, y, BB, BH, "Architecture");
      dlg.choiceArchitecture = o;
      o->menu(chachoArchitectureMenu);
      o->value(CTX.mesh.partition_options.architecture);
      o->callback((Fl_Callback *)partition_opt_architecture_cb, &dlg);
      o->align(FL_ALIGN_RIGHT);
    }
    {
      Fl_Value_Input *const o = new Fl_Value_Input
        (2*WB + 2*BB, y, IW/3, BH);
      dlg.inputNumPartition1 = o;
      o->minimum(1);
      o->maximum(std::numeric_limits<int>::max());
      switch(CTX.mesh.partition_options.architecture) {
      case 0:
         o->value(CTX.mesh.partition_options.ndims_tot);
         break;
      case 1:
         o->value(CTX.mesh.partition_options.mesh_dims[0]);
         break;
      }
      o->callback((Fl_Callback *)partition_opt_num_partitions_cb, &dlg);
      o->step(1);
    }
    {
      Fl_Value_Input *const o = new Fl_Value_Input
        (2*WB + 2*BB + IW/3, y, IW/3, BH);
      dlg.inputNumPartition2 = o;
      o->minimum(1);
      o->maximum(std::numeric_limits<int>::max());
      o->value(CTX.mesh.partition_options.mesh_dims[1]);
      o->callback((Fl_Callback *)partition_opt_num_partitions_cb, &dlg);
      o->step(1);
      if(CTX.mesh.partition_options.architecture < 2) o->deactivate();
    }
    {
      Fl_Value_Input *const o = new Fl_Value_Input
        (2*WB + 2*BB + 2*IW/3, y, IW/3, BH);
      dlg.inputNumPartition3 = o;
      o->minimum(1);
      o->maximum(std::numeric_limits<int>::max());
      o->value(CTX.mesh.partition_options.mesh_dims[2]);
      o->callback((Fl_Callback *)partition_opt_num_partitions_cb, &dlg);
      o->step(1);
      if(CTX.mesh.partition_options.architecture < 3) o->deactivate();
    }
    {
      Fl_Box *const o = new Fl_Box(2*WB + 2*BB + IW, y, 0, BH,
                                   "Topology\ndimensions");
      o->align(FL_ALIGN_RIGHT);
    }
    y += BH + WB + 2;  // +2 for multiline labels
    {
      Fl_Choice *const o = new Fl_Choice(WB, y, BB, BH, "Divisions");
      dlg.choiceDivisions = o;
      o->menu(chachoDivisionsMenu);
      o->value(CTX.mesh.partition_options.ndims - 1);
      o->callback((Fl_Callback *)partition_opt_spectralcheck_cb, &dlg);
      o->align(FL_ALIGN_RIGHT);
    }
    {
      Fl_Value_Input *const o = new Fl_Value_Input
        (2*WB + 2*BB, y, IW, BH, "Max. vertices in\ncoarse graph");
      o->minimum(2);
      o->maximum(std::numeric_limits<double>::max());
      o->value(CTX.mesh.partition_options.vmax);
      o->step(1);
      o->align(FL_ALIGN_RIGHT);
    }
    y += BH + WB + 2;  // +2 for multiline labels
    {
      Fl_Choice *const o = new Fl_Choice(WB, y, BB, BH, "Eigensolver");
      dlg.choiceEigensolver = o;
      o->menu(chachoEigSolMenu);
      o->value(CTX.mesh.partition_options.rqi_flag);
      if(CTX.mesh.partition_options.algorithm != 2) o->deactivate();
      o->align(FL_ALIGN_RIGHT);
    }
    {
      Fl_Value_Input *const o = new Fl_Value_Input
        (2*WB + 2*BB, y, IW, BH, "Eigensolver\ntolerance");
      o->minimum(std::numeric_limits<double>::min());
      o->maximum(std::numeric_limits<double>::max());
      o->value(CTX.mesh.partition_options.eigtol);
      o->step(5.E-3);
      o->align(FL_ALIGN_RIGHT);
    }
    y += BH + WB + 1;  // +1 for multiline label
    {
      Fl_Choice *const o = new Fl_Choice(WB, y, BB, BH, "Local algorithm");
      dlg.choiceLocalAlgorithm = o;
      o->menu(chachoLocalMethodMenu);
      o->value(CTX.mesh.partition_options.local_method + 1);
      if(CTX.mesh.partition_options.algorithm == 1) o->deactivate();
      o->align(FL_ALIGN_RIGHT);
    }
    {
      Fl_Value_Input *const o = new Fl_Value_Input
        (2*WB + 2*BB, y, IW, BH, "Seed");
      o->minimum(1);
      o->maximum(std::numeric_limits<int>::max());
      o->value(CTX.mesh.partition_options.seed);
      o->step(1);
      o->align(FL_ALIGN_RIGHT);
    }
    y += BH + WB;
    {
      Fl_Check_Button *const o = new Fl_Check_Button(WB, y, 2*WB, BH,
                                                     "Refine partition");
      o->value(CTX.mesh.partition_options.refine_partition);
      o->align(FL_ALIGN_RIGHT);
    }
    {
      Fl_Check_Button *const o = new Fl_Check_Button(2*WB + 2*BB, y, 2*WB, BH,
                                                     "Internal vertices");
      o->value(CTX.mesh.partition_options.internal_vertices);
      o->align(FL_ALIGN_RIGHT);
    }
    y += BH;
    {
      Fl_Check_Button *const o = new Fl_Check_Button(WB, y, 2*WB, BH,
                                                     "Refine map");
      o->value(CTX.mesh.partition_options.refine_map);
      o->align(FL_ALIGN_RIGHT);
    }
    {
      Fl_Check_Button *const o = new Fl_Check_Button(2*WB + 2*BB, y, 2*WB, BH,
                                                     "Terminal propogation");
      dlg.checkButtonTermProp = o;
      o->value(CTX.mesh.partition_options.terminal_propogation);
      o->callback((Fl_Callback *)partition_opt_spectralcheck_cb, &dlg);
      o->align(FL_ALIGN_RIGHT);
    }
    y += BH + WB;
    g->end();
    g->hide();
  }

  // Metis options group [3]
  y = yMain;
  {
    const int GH = BH + WB;
    Fl_Group *g = new Fl_Group(0, y, w, GH);
    // Algorithm
    {
      Fl_Choice *const o = new Fl_Choice(WB, y, BB, BH, "Algorithm");
      dlg.choiceMetisAlg = o;
      o->menu(metisAlgMenu);
      o->value(CTX.mesh.partition_options.algorithm - 1);
      o->align(FL_ALIGN_RIGHT);
    }
    // Advanced Button
    {
      Fl_Toggle_Button *const o = new Fl_Toggle_Button
        (w - (WB + BB), y, BB, BH, "Advanced @-22->");
      dlg.toggleButtonAdvMetis = o;
      o->callback((Fl_Callback *)partition_select_groups_cb, &dlg);
    }
    y += BH + WB;
    g->end();
    g->hide();
  }

  // Metis advanced option group [4]
  {
    const int GH = 2 + WB + (BH + WB) + 2;
    Fl_Group *g = new Fl_Group(0, y, w, GH);
    // Box (line)
    {
      Fl_Box *const o = new Fl_Box(WB, y, w - 2*WB, 2);
      o->box(FL_ENGRAVED_FRAME);
      o->labeltype(FL_NO_LABEL);
    }
    y += 2 + WB + 1;  // +1 for multiline label
    {
      Fl_Choice *const o = new Fl_Choice(WB, y, BB, BH, "Edge matching");
      o->menu(metisEdgeMatchingMenu);
      o->value(CTX.mesh.partition_options.edge_matching - 1);
      o->align(FL_ALIGN_RIGHT);
    }
    {
      Fl_Choice *const o = new Fl_Choice(2*WB + 2*BB, y, BB, BH,
                                         "Refinement\nalgorithm");
      o->menu(metisRefineAlgMenu);
      o->value(CTX.mesh.partition_options.refine_algorithm - 1);
      o->align(FL_ALIGN_RIGHT);
    }
    y += BH + WB + 1;  // +1 for multiline label
    g->end();
    g->hide();
  }
  
  // Dialog termination group [5]
  {
    const int GH = 2 + BH + 2*WB;
    Fl_Group *g = new Fl_Group(0, y, w, GH);
    // Box (line) [0]
    {
      Fl_Box *const o = new Fl_Box(WB, y, w - 2*WB, 2);
      o->box(FL_ENGRAVED_FRAME);
      o->labeltype(FL_NO_LABEL);
    }
    y += 2 + WB;
    // Partition Button [1]
    {
      Fl_Return_Button *const o = new Fl_Return_Button
        (w - 2*(WB + BB), y, BB, BH, "Partition");
      o->callback((Fl_Callback *)partition_partition_cb);
    }
    // Cancel Button [2]
    {
      Fl_Button *const o = new Fl_Button(w - (WB + BB), y, BB, BH, "Cancel");
      o->callback((Fl_Callback *)partition_cancel_cb);
    }
    y += BH + WB;
    g->end();
    g->show();
  }

  window->set_modal();
  window->end();
  window->hotspot(window);

  partition_select_groups_cb(window->child(0), &dlg);
  window->show();
}
