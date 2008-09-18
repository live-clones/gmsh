// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Stephen Guzik
//

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
#include "Partition.h"

#include <FL/Fl_Value_Slider.H>
#include <FL/Fl_Menu_Window.H>
#include <FL/Fl_Select_Browser.H>
#include <FL/Fl_Toggle_Button.H>
#include <FL/Fl_Round_Button.H>
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
    Fl_Check_Button *b[7];
    Fl_Button *ok, *cancel;
  };
  static _pos_dialog *dialog = NULL;

  const int BH = 2 * GetFontSize() + 1;
  const int BB = 7 * GetFontSize() + 9;
  const int WB = 7;

  if(!dialog){
    dialog = new _pos_dialog;
    int h = 3 * WB + 8 * BH, w = 2 * BB + 3 * WB, y = WB;
    // not a "Dialog_Window" since it is modal 
    dialog->window = new Fl_Double_Window(w, h, "POS Options");
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->b[0] = new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Save all (ignore physical groups)"); y += BH;
    dialog->b[1] = new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Print elementary tags"); y += BH;
    dialog->b[2] = new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Print element numbers"); y += BH;
    dialog->b[3] = new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Print Gamma quality measure"); y += BH;
    dialog->b[4] = new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Print Eta quality measure"); y += BH;
    dialog->b[5] = new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Print Rho quality measure"); y += BH;
    dialog->b[6] = new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Print Disto quality measure"); y += BH;
    for(int i = 0; i < 6; i++)
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
        opt_print_pos_disto(0, GMSH_SET | GMSH_GUI, dialog->b[6]->value() ? 1 : 0);
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


// CGNS write dialog - widget pointers, callbacks, and dialog routine
#if defined(HAVE_LIBCGNS)

// Forward declarations of some callbacks
void cgnsw_gc_location_cb(Fl_Widget *widget, void *data);
void cgnsw_write_dummy_bc_cb(Fl_Widget *widget, void *data);
void cgnsw_bc_location_cb(Fl_Widget *widget, void *data);
void cgnsw_write_normals_cb(Fl_Widget *widget, void *data);
void cgnsw_normal_source_cb(Fl_Widget *widget, void *data);

// Pointers to required widgets
struct CGNSWriteDialog
{
  Fl_Window *window;
  Fl_Choice *choiceZoneDef;
  Fl_Input *inputBaseName;
  Fl_Input *inputZoneName;
  Fl_Input *inputInterfaceName;
  Fl_Input *inputPatchName;
  Fl_Round_Button *roundButton0GCatVertex;
  Fl_Round_Button *roundButton1GCatFace;
  Fl_Check_Button *checkButtonWriteBC;
  Fl_Round_Button *roundButton0BCatVertex;
  Fl_Round_Button *roundButton1BCatFace;
  Fl_Check_Button *checkButtonWriteNormals;
  Fl_Round_Button *roundButton0NormalGeo;
  Fl_Round_Button *roundButton1NormalElem;
  Fl_Choice *choiceVecDim;
  Fl_Check_Button *checkButtonUnknownUserDef;
  const char *filename;
  int status;
  void write_all_options()
  {
    opt_mesh_zone_definition(0, GMSH_SET | GMSH_GUI, choiceZoneDef->value());
    CTX.mesh.cgns_options.baseName = inputBaseName->value();
    CTX.mesh.cgns_options.zoneName = inputZoneName->value();
    CTX.mesh.cgns_options.interfaceName = inputInterfaceName->value();
    CTX.mesh.cgns_options.patchName = inputPatchName->value();
    CTX.mesh.cgns_options.gridConnectivityLocation =
      roundButton1GCatFace->value();
    CTX.mesh.cgns_options.writeBC = checkButtonWriteBC->value();
    CTX.mesh.cgns_options.bocoLocation = roundButton1BCatFace->value();
    CTX.mesh.cgns_options.normalSource = (checkButtonWriteNormals->value()) ?
       roundButton1NormalElem->value() + 1 : 0;
    CTX.mesh.cgns_options.vectorDim = choiceVecDim->value() + 2;
    CTX.mesh.cgns_options.writeUserDef = checkButtonUnknownUserDef->value();
  }
  void read_all_options()
  {
    choiceZoneDef->value(CTX.mesh.zone_definition);
    inputBaseName->value(CTX.mesh.cgns_options.baseName.c_str());
    inputZoneName->value(CTX.mesh.cgns_options.zoneName.c_str());
    inputInterfaceName->value(CTX.mesh.cgns_options.interfaceName.c_str());
    inputPatchName->value(CTX.mesh.cgns_options.patchName.c_str());
    checkButtonWriteBC->value(CTX.mesh.cgns_options.writeBC);
    checkButtonWriteNormals->value(CTX.mesh.cgns_options.normalSource);
    choiceVecDim->value(CTX.mesh.cgns_options.vectorDim - 2);
    checkButtonUnknownUserDef->value(CTX.mesh.cgns_options.writeUserDef);

    // Call all callbacks to ensure consistent options
    cgnsw_gc_location_cb
      ((CTX.mesh.cgns_options.gridConnectivityLocation) ?
       roundButton1GCatFace : roundButton0GCatVertex, this);
    // The order of the next 4 is important
    cgnsw_normal_source_cb
      ((CTX.mesh.cgns_options.normalSource == 2) ?
       roundButton1NormalElem : roundButton0NormalGeo, this);
    cgnsw_write_normals_cb(checkButtonWriteNormals, this);
    cgnsw_bc_location_cb
      ((CTX.mesh.cgns_options.bocoLocation) ?
       roundButton1BCatFace : roundButton0BCatVertex, this);
    cgnsw_write_dummy_bc_cb(checkButtonWriteBC, this);
  }
};

void cgnsw_gc_location_cb(Fl_Widget *widget, void *data)
{
  CGNSWriteDialog *dlg = static_cast<CGNSWriteDialog*>(data);
  if(widget == dlg->roundButton0GCatVertex) {
    dlg->roundButton0GCatVertex->set();
    dlg->roundButton1GCatFace->clear();
  }
  else {
    dlg->roundButton0GCatVertex->clear();
    dlg->roundButton1GCatFace->set();
  }
}

void cgnsw_write_dummy_bc_cb(Fl_Widget *widget, void *data)
{
  CGNSWriteDialog *dlg = static_cast<CGNSWriteDialog*>(data);
  if(dlg->checkButtonWriteBC->value()) {
    dlg->roundButton0BCatVertex->activate();
//     dlg->roundButton1BCatFace->activate();  //**Tmp
    dlg->checkButtonWriteNormals->activate();
    if(dlg->checkButtonWriteNormals->value()) {
      if(dlg->roundButton0BCatVertex->value())
        dlg->roundButton0NormalGeo->activate();
      dlg->roundButton1NormalElem->activate();
    }
  }
  else {
    dlg->roundButton0BCatVertex->deactivate();
    dlg->roundButton1BCatFace->deactivate();
    dlg->checkButtonWriteNormals->deactivate();
    dlg->roundButton0NormalGeo->deactivate();
    dlg->roundButton1NormalElem->deactivate();
  } 
}

void cgnsw_bc_location_cb(Fl_Widget *widget, void *data)
{
  CGNSWriteDialog *dlg = static_cast<CGNSWriteDialog*>(data);
  if(widget == dlg->roundButton0BCatVertex) {
    dlg->roundButton0BCatVertex->set();
    dlg->roundButton1BCatFace->clear();
    if(dlg->checkButtonWriteNormals->value())
      dlg->roundButton0NormalGeo->activate();
  }
  else {
    dlg->roundButton0BCatVertex->clear();
    dlg->roundButton1BCatFace->set();
    dlg->roundButton0NormalGeo->clear();
    dlg->roundButton0NormalGeo->deactivate();
    dlg->roundButton1NormalElem->set();
  }
}

void cgnsw_write_normals_cb(Fl_Widget *widget, void *data)
{
  CGNSWriteDialog *dlg = static_cast<CGNSWriteDialog*>(data);
  if(dlg->checkButtonWriteNormals->value()) {
    if(dlg->roundButton0BCatVertex->value())
      dlg->roundButton0NormalGeo->activate();
    dlg->roundButton1NormalElem->activate();
  }
  else {
    dlg->roundButton0NormalGeo->deactivate();
    dlg->roundButton1NormalElem->deactivate();
  } 
}

void cgnsw_normal_source_cb(Fl_Widget *widget, void *data)
{
  CGNSWriteDialog *dlg = static_cast<CGNSWriteDialog*>(data);
  if(widget == dlg->roundButton0NormalGeo) {
    dlg->roundButton0NormalGeo->set();
    dlg->roundButton1NormalElem->clear();
  }
  else {
    dlg->roundButton0NormalGeo->clear();
    dlg->roundButton1NormalElem->set();
  }
}

void cgnsw_defaults_cb(Fl_Widget *widget, void *data)
{
  CGNSWriteDialog *dlg = static_cast<CGNSWriteDialog*>(data);
  CTX.mesh.cgns_options.setDefaults();
  dlg->read_all_options();
}

void cgnsw_write_cb(Fl_Widget *widget, void *data)
{
  CGNSWriteDialog *dlg = static_cast<CGNSWriteDialog*>(data);

  // Write all options
  dlg->write_all_options();
  dlg->window->hide();

  // Write the data
  CreateOutputFile(dlg->filename, FORMAT_CGNS);
  dlg->status = 1;
}

void cgnsw_cancel_cb(Fl_Widget *widget, void *data)
{
  CGNSWriteDialog *dlg = static_cast<CGNSWriteDialog*>(data);
  dlg->window->hide();
  dlg->status = 0;
}

int cgns_write_dialog(const char *filename)
{
  static CGNSWriteDialog dlg;
  dlg.filename = filename;

  static Fl_Menu_Item zoneDefMenu[] = {
    {"Single zone", 0, 0, 0},
    {"Partition", 0, 0, 0},
    {"Physical", 0, 0, 0},
    {0}
  };
      
  static Fl_Menu_Item vectorDimMenu[] = {
    {"2", 0, 0, 0},
    {"3", 0, 0, 0},
    {0}
  };

  const int BH = 2*GetFontSize() + 1;   // button height
  const int RBH = 3*GetFontSize()/2;    // radio button height
  const int IW = 10*GetFontSize();      // Input field width
  const int BB = 7*GetFontSize() + 9;   // Width of a button with an internal
                                        // label
  const int WB = 7;                     // Window border

  const int col1 = WB;                  // Start of left column
  const int col2 = 2*WB + 2*BB;         // Start of right column
  const int hcol1 = 5*WB + 2*RBH + 3*BH;
                                        // Height of left column
  const int hcol2 = 4*WB + 4*RBH + 2*BH;
                                        // Height of right column

  const int h = 4 + 8*WB + 5*BH + std::max(hcol1, hcol2);
                                        // Window height
  const int w = 3*WB + 4*BB;            // Window width
  int y = WB;

  dlg.window = new Dialog_Window(w, h, true, "CGNS Options");
  dlg.window->box(GMSH_WINDOW_BOX);
  dlg.window->callback((Fl_Callback *)cgnsw_cancel_cb, &dlg);

  // Zone definition
  dlg.choiceZoneDef = new Fl_Choice(col1, y, IW, BH, "Zone definition");
  dlg.choiceZoneDef->menu(zoneDefMenu);
  dlg.choiceZoneDef->align(FL_ALIGN_RIGHT);
  y += BH + WB;

  // Box (line) [0]
  {
    Fl_Box *const o = new Fl_Box(WB, y, w - 2*WB, 2);
    o->box(FL_ENGRAVED_FRAME);
    o->labeltype(FL_NO_LABEL);
  }
  y += 2 + WB;

  // Base name
  dlg.inputBaseName = new Fl_Input(col1, y, BB, BH, "Base name");
  dlg.inputBaseName->align(FL_ALIGN_RIGHT);
  // Zone name
  dlg.inputZoneName = new Fl_Input(col2, y, BB, BH, "Zone name");
  dlg.inputZoneName->align(FL_ALIGN_RIGHT);
  y += BH + WB;
  // Interface name
  dlg.inputInterfaceName = new Fl_Input(col1, y, BB, BH, "Interface name");
  dlg.inputInterfaceName->align(FL_ALIGN_RIGHT);
  // BC Patch name
  dlg.inputPatchName = new Fl_Input(col2, y, BB, BH, "BC patch name");
  dlg.inputPatchName->align(FL_ALIGN_RIGHT);
  y += BH + WB;

//--Left column

  int yl = y;
  {
    Fl_Box *const o = new Fl_Box(col1, yl, 0, BH, "Grid connectivity location");
    o->align(FL_ALIGN_RIGHT);
    yl += BH;
  }
  {
    Fl_Box *const o = new Fl_Box(col1, yl, 2*BB, 2*WB + 2*RBH);
    o->box(FL_ENGRAVED_FRAME);
    o->labeltype(FL_NO_LABEL);
    yl += WB;
  }
  // Grid connectivity location
  {
    const int GH = 2*RBH + 2*WB;
    Fl_Group *g = new Fl_Group(col1, yl, 2*BB, GH);
    dlg.roundButton0GCatVertex = new Fl_Round_Button(col1 + WB, yl, RBH, RBH,
                                                     "Vertex");
    dlg.roundButton0GCatVertex->callback((Fl_Callback *)cgnsw_gc_location_cb,
                                         &dlg);
    dlg.roundButton0GCatVertex->align(FL_ALIGN_RIGHT);
    yl += RBH;
    dlg.roundButton1GCatFace = new Fl_Round_Button(col1 + WB, yl, RBH, RBH,
                                                   "Face");
    dlg.roundButton1GCatFace->callback((Fl_Callback *)cgnsw_gc_location_cb,
                                       &dlg);
    dlg.roundButton1GCatFace->align(FL_ALIGN_RIGHT);
    dlg.roundButton1GCatFace->deactivate();  //**Tmp
    yl += RBH + 2*WB;
    g->end();
    g->show();
  }

  // 2D Vector Dim
  yl += WB;
  dlg.choiceVecDim = new Fl_Choice(WB, yl, BB/2, BH, "Vector Dimension");
  dlg.choiceVecDim->menu(vectorDimMenu);
  dlg.choiceVecDim->align(FL_ALIGN_RIGHT);
  yl += BH;
  {
    Fl_Box *const o = new Fl_Box(col1, yl, 0, BH,
                                 "(only affects 2-D mesh output)");
    o->align(FL_ALIGN_RIGHT);
    yl += BH + WB;
  }

//--Right column

  int yr = y;

  // Write exterior BC
  dlg.checkButtonWriteBC = new Fl_Check_Button(col2, yr, RBH, BH,
                                               "Write dummy BC");
  dlg.checkButtonWriteBC->callback((Fl_Callback *)cgnsw_write_dummy_bc_cb,
                                   &dlg);
  dlg.checkButtonWriteBC->align(FL_ALIGN_RIGHT);
  yr += BH;
  {
    Fl_Box *const o = new Fl_Box(col2, yr, 2*BB, BH + 4*RBH + 3*WB);
    o->box(FL_ENGRAVED_FRAME);
    o->labeltype(FL_NO_LABEL);
    yr += WB;
  }

  // BC location
  {
    const int GH = 2*RBH + WB;
    Fl_Group *g = new Fl_Group(col2, yr, 2*BB, GH);
    dlg.roundButton0BCatVertex = new Fl_Round_Button(col2 + WB, yr, RBH, RBH,
                                                     "Vertex");
    dlg.roundButton0BCatVertex->callback((Fl_Callback *)cgnsw_bc_location_cb,
                                         &dlg);
    dlg.roundButton0BCatVertex->align(FL_ALIGN_RIGHT);
    yr += RBH;
    dlg.roundButton1BCatFace = new Fl_Round_Button(col2 + WB, yr, RBH, RBH,
                                                   "Face");
    dlg.roundButton1BCatFace->callback((Fl_Callback *)cgnsw_bc_location_cb,
                                       &dlg);
    dlg.roundButton1BCatFace->align(FL_ALIGN_RIGHT);
    dlg.roundButton1BCatFace->deactivate();  //**Tmp
    yr += RBH + WB;
    g->end();
    g->show();
  }

  // Write normals
  dlg.checkButtonWriteNormals = new Fl_Check_Button(col2 + WB, yr, RBH, BH,
                                                    "Write normals");
  dlg.checkButtonWriteNormals->callback((Fl_Callback *)cgnsw_write_normals_cb,
                                        &dlg);
  dlg.checkButtonWriteNormals->align(FL_ALIGN_RIGHT);
  yr += BH;
  
  // Normal source
  {
    const int GH = 2*RBH + WB;
    Fl_Group *g = new Fl_Group(col2, yr, 2*BB, GH);
    dlg.roundButton0NormalGeo = new Fl_Round_Button(col2 + 2*WB, yr, RBH, RBH,
                                                    "From geometry");
    dlg.roundButton0NormalGeo->callback((Fl_Callback *)cgnsw_normal_source_cb,
                                         &dlg);
    dlg.roundButton0NormalGeo->align(FL_ALIGN_RIGHT);
    yr += RBH;
    dlg.roundButton1NormalElem = new Fl_Round_Button(col2 + 2*WB, yr, RBH, RBH,
                                                     "From elements");
    dlg.roundButton1NormalElem->callback((Fl_Callback *)cgnsw_normal_source_cb,
                                         &dlg);
    dlg.roundButton1NormalElem->align(FL_ALIGN_RIGHT);
    yr += RBH + 2*WB;
    g->end();
    g->show();
  }

  y = std::max(yl, yr);
  // User defined
  dlg.checkButtonUnknownUserDef = new Fl_Check_Button
    (col1, y, RBH, BH, "Write user-defined elements for unsupported types");
  dlg.checkButtonUnknownUserDef->align(FL_ALIGN_RIGHT);
  dlg.checkButtonUnknownUserDef->deactivate();  //**Tmp
  y += BH + WB;

  // Dialog termination group
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
    // Defaults Button [1]
    {
      Fl_Button *const o = new Fl_Button
         (WB, y, BB, BH, "Defaults");
      o->callback((Fl_Callback *)cgnsw_defaults_cb, &dlg);
    }
    // Write Button [2]
    {
      Fl_Return_Button *const o = new Fl_Return_Button(w - 2*(WB + BB), y, BB,
                                                       BH, "Write");
      o->callback((Fl_Callback *)cgnsw_write_cb, &dlg);
    }
    // Cancel Button [3]
    {
      Fl_Button *const o = new Fl_Button(w - (WB + BB), y, BB, BH, "Cancel");
      o->callback((Fl_Callback *)cgnsw_cancel_cb, &dlg);
    }
    y += BH + WB;
    g->end();
    g->show();
  }

  dlg.window->end();
  dlg.window->hotspot(dlg.window);

  dlg.read_all_options();
  dlg.window->show();

  // Wait here for status
  while(dlg.window->shown()) Fl::wait();
  delete dlg.window;
  return dlg.status;
}

#else

int cgns_write_dialog(const char *const name)
{
  CreateOutputFile(name, FORMAT_CGNS);
  return 1;
}

#endif  // compiling CGNS write dialog


// Partition dialog - widget pointers, callbacks and dialog routine
#if defined(HAVE_CHACO) || defined(HAVE_METIS)

// Forward declarations of some callbacks
void partition_opt_chaco_globalalg_cb(Fl_Widget *widget, void *data);
void partition_opt_architecture_cb(Fl_Widget *widget, void *data);
void partition_opt_num_partitions_cb(Fl_Widget *widget, void *data);
void partition_opt_spectralcheck_cb(Fl_Widget *widget, void *data);
void partition_select_groups_cb(Fl_Widget *widget, void *data);

// Pointers to required widgets
struct PartitionDialog
{
  Fl_Window *window;
  // Group 0
  Fl_Choice *choicePartitioner;
  Fl_Value_Input *inputNumPartition;
  // Group 1
  Fl_Choice *choiceChacoAlg;
  Fl_Toggle_Button *toggleButtonAdvChaco;
  // Group 2
  Fl_Choice *choiceArchitecture;
  Fl_Value_Input *inputNumPartition1;
  Fl_Value_Input *inputNumPartition2;
  Fl_Value_Input *inputNumPartition3;
  Fl_Choice *choiceDivisions;
  Fl_Value_Input *inputVMax;
  Fl_Choice *choiceEigensolver;
  Fl_Value_Input *inputEigtol;
  Fl_Choice *choiceLocalAlgorithm;
  Fl_Value_Input *inputSeed;
  Fl_Check_Button *checkButtonRefPart;
  Fl_Check_Button *checkButtonIntVert;
  Fl_Check_Button *checkButtonRefMap;
  Fl_Check_Button *checkButtonTermProp;
  // Group 3
  Fl_Choice *choiceMetisAlg;
  Fl_Toggle_Button *toggleButtonAdvMetis;
  // Group 4
  Fl_Choice *choiceEdgeMatch;
  Fl_Choice *choiceRefineAlg;
  void write_all_options()
  {
    // Group 0
    CTX.mesh.partition_options.partitioner = choicePartitioner->value() + 1;
    CTX.mesh.partition_options.num_partitions =
      static_cast<int>(inputNumPartition->value());

    // Group 1
    CTX.mesh.partition_options.global_method = choiceChacoAlg->value() + 1;

    // Group 2
    CTX.mesh.partition_options.architecture = choiceArchitecture->value();
    switch(CTX.mesh.partition_options.architecture) {
    case 0:
      CTX.mesh.partition_options.ndims_tot =
        static_cast<int>(inputNumPartition1->value());
      break;
    case 3:
      CTX.mesh.partition_options.mesh_dims[2] =
        static_cast<int>(inputNumPartition3->value());
    case 2:
      CTX.mesh.partition_options.mesh_dims[1] =
        static_cast<int>(inputNumPartition2->value());
    case 1:
      CTX.mesh.partition_options.mesh_dims[0] =
        static_cast<int>(inputNumPartition1->value());
      break;
    }
    CTX.mesh.partition_options.ndims = choiceDivisions->value() + 1;
    CTX.mesh.partition_options.vmax = static_cast<int>(inputVMax->value());
    CTX.mesh.partition_options.rqi_flag = choiceEigensolver->value();
    CTX.mesh.partition_options.eigtol = inputEigtol->value();
    CTX.mesh.partition_options.local_method = choiceLocalAlgorithm->value() + 1;
    CTX.mesh.partition_options.seed = static_cast<long>(inputSeed->value());
    CTX.mesh.partition_options.refine_partition = checkButtonRefPart->value();
    CTX.mesh.partition_options.internal_vertices = checkButtonIntVert->value();
    CTX.mesh.partition_options.refine_map = checkButtonRefMap->value();
    CTX.mesh.partition_options.terminal_propogation =
      checkButtonTermProp->value();
  
    // Group 3
    CTX.mesh.partition_options.algorithm = choiceMetisAlg->value() + 1;

    // Group 4
    CTX.mesh.partition_options.edge_matching = choiceEdgeMatch->value() + 1;
    CTX.mesh.partition_options.refine_algorithm = choiceRefineAlg->value() + 1;
  }
  void read_all_options()
  {
    // Group 0
    choicePartitioner->value(CTX.mesh.partition_options.partitioner - 1);
    inputNumPartition->value(CTX.mesh.partition_options.num_partitions);

    // Group 1
    choiceChacoAlg->value(CTX.mesh.partition_options.global_method - 1);

    // Group 2
    choiceArchitecture->value(CTX.mesh.partition_options.architecture);
    switch(CTX.mesh.partition_options.architecture) {
    case 0:
      inputNumPartition1->value(CTX.mesh.partition_options.ndims_tot);
      break;
    case 1:
      inputNumPartition1->value(CTX.mesh.partition_options.mesh_dims[0]);
      break;
    }
    inputNumPartition2->value(CTX.mesh.partition_options.mesh_dims[1]);
    inputNumPartition3->value(CTX.mesh.partition_options.mesh_dims[2]);
    choiceDivisions->value(CTX.mesh.partition_options.ndims - 1);
    inputVMax->value(CTX.mesh.partition_options.vmax);
    choiceEigensolver->value(CTX.mesh.partition_options.rqi_flag);
    inputEigtol->value(CTX.mesh.partition_options.eigtol);
    choiceLocalAlgorithm->value(CTX.mesh.partition_options.local_method - 1);
    inputSeed->value(CTX.mesh.partition_options.seed);
    checkButtonRefPart->value(CTX.mesh.partition_options.refine_partition);
    checkButtonIntVert->value(CTX.mesh.partition_options.internal_vertices);
    checkButtonRefMap->value(CTX.mesh.partition_options.refine_map);
    checkButtonTermProp->value(CTX.mesh.partition_options.terminal_propogation);
  
    // Group 3
    choiceMetisAlg->value(CTX.mesh.partition_options.algorithm - 1);

    // Group 4
    choiceEdgeMatch->value(CTX.mesh.partition_options.edge_matching - 1);
    choiceRefineAlg->value(CTX.mesh.partition_options.refine_algorithm - 1);

    // Call all callbacks to ensure consistent options
    partition_opt_chaco_globalalg_cb(choiceChacoAlg, this);
    partition_opt_architecture_cb(choiceArchitecture, this);
    partition_opt_num_partitions_cb(inputNumPartition, this);
    partition_opt_spectralcheck_cb(choiceDivisions, this);
  }
};

// Chaco option considerations based on the global algorithm
void partition_opt_chaco_globalalg_cb(Fl_Widget *widget, void *data)
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
    dlg->choiceEigensolver->value(1);
    dlg->choiceEigensolver->activate();
    if(dlg->choiceDivisions->value() != 0 &&
       dlg->checkButtonTermProp->value())
      dlg->choiceDivisions->value(0);
  }
  else {
    dlg->choiceEigensolver->deactivate();
  }
}

// Chaco option considerations based on the architecture
void partition_opt_architecture_cb(Fl_Widget *widget, void *data)
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
  // Set topology dimensions from main number of partitions
  partition_opt_num_partitions_cb(dlg->inputNumPartition, data);
}

// Match several locations that provide a partition number
void partition_opt_num_partitions_cb(Fl_Widget *widget, void *data)
{
  PartitionDialog *dlg = static_cast<PartitionDialog*>(data);
  unsigned val;
  if(widget == dlg->inputNumPartition) {
    val = static_cast<unsigned>(dlg->inputNumPartition->value());
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
        unsigned x = static_cast<unsigned>(dlg->inputNumPartition1->value());
        val = 1 << x;
      }
      break;
    case 1:
      val = static_cast<unsigned>(dlg->inputNumPartition1->value());
      break;
    case 2:
      val = static_cast<unsigned>
        (dlg->inputNumPartition1->value()*dlg->inputNumPartition2->value());
      break;
    case 3:
      val = static_cast<unsigned>
        (dlg->inputNumPartition1->value()*dlg->inputNumPartition2->value()*
         dlg->inputNumPartition3->value());
      break;
    }
    dlg->inputNumPartition->value(val);
  }
  switch(dlg->choicePartitioner->value()) {
  case 0:
    if(val <= 3) {
      dlg->choiceDivisions->value(0);
      dlg->choiceDivisions->mode(1, FL_MENU_INACTIVE);
      dlg->choiceDivisions->mode(2, FL_MENU_INACTIVE);
    }
    else if(val <= 7) {
      if(dlg->choiceDivisions->value() > 1) dlg->choiceDivisions->value(1);
      dlg->choiceDivisions->mode(1, 0);
      dlg->choiceDivisions->mode(2, FL_MENU_INACTIVE);
    }
    else {
      dlg->choiceDivisions->mode(1, 0);
      dlg->choiceDivisions->mode(2, 0);
    }
    break;
  case 1:
    dlg->choiceMetisAlg->value((val <= 8) ? 0: 1);
    break;
  }
}

// Option considerations for the Chaco spectral algorithm
void partition_opt_spectralcheck_cb(Fl_Widget *widget, void *data)
{
  PartitionDialog *dlg = static_cast<PartitionDialog*>(data);
  if(dlg->choiceChacoAlg->value() == 1) {
    if(widget == dlg->choiceDivisions && dlg->choiceDivisions->value() != 0)
      dlg->checkButtonTermProp->value(0);
    else if(widget == dlg->checkButtonTermProp)
      dlg->choiceDivisions->value(0);
  }
}

void partition_defaults_cb(Fl_Widget *widget, void *data)
{
  PartitionDialog *dlg = static_cast<PartitionDialog*>(data);
  CTX.mesh.partition_options.setDefaults();
  dlg->read_all_options();
  partition_select_groups_cb(dlg->choicePartitioner, data);
}

void partition_partition_cb(Fl_Widget *widget, void *data)
{
  PartitionDialog *dlg = static_cast<PartitionDialog*>(data);

  // Write all options
  dlg->write_all_options();

  // Partition the mesh
  int ier = PartitionMesh(GModel::current(), CTX.mesh.partition_options);

  // Update the screen
  if(!ier) {
    opt_mesh_zone_definition(0, GMSH_SET, 1.);  // Define zone by partition
    opt_mesh_color_carousel(0, GMSH_SET | GMSH_GUI, 3.);
    CTX.mesh.changed = ENT_ALL;
    Draw();
  }
}

void partition_cancel_cb(Fl_Widget *widget, void *data)
{
  PartitionDialog *dlg = static_cast<PartitionDialog*>(data);
  dlg->window->hide();
  Fl::delete_widget(dlg->window);
}

// Select groups to display
void partition_select_groups_cb(Fl_Widget *widget, void *data)
{
  PartitionDialog *dlg = static_cast<PartitionDialog*>(data);
  // If this callback was made by the "Advanced" toggle buttons, set the label
  if(dlg->toggleButtonAdvChaco == widget) {
    dlg->toggleButtonAdvChaco->label((dlg->toggleButtonAdvChaco->value()) ?
                                     "Advanced @-28->" : "Advanced @-22->");
  }
  else if(dlg->toggleButtonAdvMetis == widget) {
    dlg->toggleButtonAdvMetis->label((dlg->toggleButtonAdvMetis->value()) ?
                                     "Advanced @-28->" : "Advanced @-22->");
  }
  const int WB = 7;                     // Window border
  // Get the groups
  Fl_Widget *const *g = dlg->window->array();
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
    o = static_cast<Fl_Group*>(g[5])->child(3);
    o->position(o->x(), yG);
    yG += WB + o->h();
  }
  y += g[5]->h();
  // Resize and redraw the window
  dlg->window->size(dlg->window->w(), y);
  dlg->window->redraw();
}

void partition_dialog()
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

  const int h = 6 * WB + 3 * BH + 4;    // This will be resized based on groups
                                        // that are displayed
  const int w = 3 * BB + IW + 3 * WB;   // Window width
  int y = 0;

  dlg.window = new Dialog_Window(w, h, CTX.non_modal_windows,
                                 "Partitioner Options");
  dlg.window->box(GMSH_WINDOW_BOX);
  dlg.window->callback((Fl_Callback *)partition_cancel_cb, &dlg);

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
      o->callback((Fl_Callback *)partition_select_groups_cb, &dlg);
#if !defined(HAVE_CHACO)
      o->mode(0, FL_MENU_INACTIVE);
#endif
#if !defined(HAVE_METIS)
      o->mode(1, FL_MENU_INACTIVE);
#endif
      o->align(FL_ALIGN_RIGHT);
    }
    // Number of partitions
    {
      Fl_Value_Input *const o = new Fl_Value_Input
        (2*WB + 2*BB, y, IW, BH, "Number of\nPartitions");
      dlg.inputNumPartition = o;
      o->minimum(1);
      o->maximum(std::numeric_limits<int>::max());
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
    // Architecture
    {
      Fl_Choice *const o = new Fl_Choice(WB, y, BB, BH, "Architecture");
      dlg.choiceArchitecture = o;
      o->menu(chachoArchitectureMenu);
      o->callback((Fl_Callback *)partition_opt_architecture_cb, &dlg);
      o->align(FL_ALIGN_RIGHT);
    }
    // Mesh_dim1
    {
      Fl_Value_Input *const o = new Fl_Value_Input
        (2*WB + 2*BB, y, IW/3, BH);
      dlg.inputNumPartition1 = o;
      o->minimum(1);
      o->maximum(std::numeric_limits<int>::max());
      o->callback((Fl_Callback *)partition_opt_num_partitions_cb, &dlg);
      o->step(1);
    }
    // Mesh_dim2
    {
      Fl_Value_Input *const o = new Fl_Value_Input
        (2*WB + 2*BB + IW/3, y, IW/3, BH);
      dlg.inputNumPartition2 = o;
      o->minimum(1);
      o->maximum(std::numeric_limits<int>::max());
      o->callback((Fl_Callback *)partition_opt_num_partitions_cb, &dlg);
      o->step(1);
    }
    // Mesh_dim3
    {
      Fl_Value_Input *const o = new Fl_Value_Input
        (2*WB + 2*BB + 2*IW/3, y, IW/3, BH);
      dlg.inputNumPartition3 = o;
      o->minimum(1);
      o->maximum(std::numeric_limits<int>::max());
      o->callback((Fl_Callback *)partition_opt_num_partitions_cb, &dlg);
      o->step(1);
    }
    // Label
    {
      Fl_Box *const o = new Fl_Box(2*WB + 2*BB + IW, y, 0, BH,
                                   "Topology\ndimensions");
      o->align(FL_ALIGN_RIGHT);
    }
    y += BH + WB + 2;  // +2 for multiline labels
    // Divisions
    {
      Fl_Choice *const o = new Fl_Choice(WB, y, BB, BH, "Divisions");
      dlg.choiceDivisions = o;
      o->copy(chachoDivisionsMenu);
      o->callback((Fl_Callback *)partition_opt_spectralcheck_cb, &dlg);
      o->align(FL_ALIGN_RIGHT);
    }
    // Vmax
    {
      Fl_Value_Input *const o = new Fl_Value_Input
        (2*WB + 2*BB, y, IW, BH, "Max. vertices in\ncoarse graph");
      dlg.inputVMax = o;
      o->minimum(2);
      o->maximum(std::numeric_limits<double>::max());
      o->step(1);
      o->align(FL_ALIGN_RIGHT);
    }
    y += BH + WB + 2;  // +2 for multiline labels
    // Eigensolver
    {
      Fl_Choice *const o = new Fl_Choice(WB, y, BB, BH, "Eigensolver");
      dlg.choiceEigensolver = o;
      o->menu(chachoEigSolMenu);
      o->align(FL_ALIGN_RIGHT);
    }
    // Eigtol
    {
      Fl_Value_Input *const o = new Fl_Value_Input
        (2*WB + 2*BB, y, IW, BH, "Eigensolver\ntolerance");
      dlg.inputEigtol = o;
      o->minimum(std::numeric_limits<double>::min());
      o->maximum(std::numeric_limits<double>::max());
      o->step(5.E-3);
      o->align(FL_ALIGN_RIGHT);
    }
    y += BH + WB + 1;  // +1 for multiline label
    // Local method
    {
      Fl_Choice *const o = new Fl_Choice(WB, y, BB, BH, "Local algorithm");
      dlg.choiceLocalAlgorithm = o;
      o->menu(chachoLocalMethodMenu);
      o->align(FL_ALIGN_RIGHT);
    }
    // Seed
    {
      Fl_Value_Input *const o = new Fl_Value_Input
        (2*WB + 2*BB, y, IW, BH, "Seed");
      dlg.inputSeed = o;
      o->minimum(1);
      o->maximum(std::numeric_limits<int>::max());
      o->step(1);
      o->align(FL_ALIGN_RIGHT);
    }
    y += BH + WB;
    // Parameters
    {
      Fl_Check_Button *const o = new Fl_Check_Button(WB, y, 2*WB, BH,
                                                     "Refine partition");
      dlg.checkButtonRefPart = o;
      o->align(FL_ALIGN_RIGHT);
    }
    {
      Fl_Check_Button *const o = new Fl_Check_Button(2*WB + 2*BB, y, 2*WB, BH,
                                                     "Internal vertices");
      dlg.checkButtonIntVert = o;
      o->align(FL_ALIGN_RIGHT);
    }
    y += BH;
    {
      Fl_Check_Button *const o = new Fl_Check_Button(WB, y, 2*WB, BH,
                                                     "Refine map");
      dlg.checkButtonRefMap = o;
      o->align(FL_ALIGN_RIGHT);
    }
    {
      Fl_Check_Button *const o = new Fl_Check_Button(2*WB + 2*BB, y, 2*WB, BH,
                                                     "Terminal propogation");
      dlg.checkButtonTermProp = o;
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
    // Edge matching algorithm
    {
      Fl_Choice *const o = new Fl_Choice(WB, y, BB, BH, "Edge matching");
      dlg.choiceEdgeMatch = o;
      o->menu(metisEdgeMatchingMenu);
      o->align(FL_ALIGN_RIGHT);
    }
    // Refinement algorithm
    {
      Fl_Choice *const o = new Fl_Choice(2*WB + 2*BB, y, BB, BH,
                                         "Refinement\nalgorithm");
      dlg.choiceRefineAlg = o;
      o->menu(metisRefineAlgMenu);
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
    // Defaults Button [1]
    {
      Fl_Button *const o = new Fl_Button
         (WB, y, BB, BH, "Defaults");
      o->callback((Fl_Callback *)partition_defaults_cb, &dlg);
    }
    // Partition Button [2]
    {
      Fl_Return_Button *const o = new Fl_Return_Button
        (w - 2*(WB + BB), y, BB, BH, "Partition");
      o->callback((Fl_Callback *)partition_partition_cb, &dlg);
    }
    // Cancel Button [3]
    {
      Fl_Button *const o = new Fl_Button(w - (WB + BB), y, BB, BH, "Cancel");
      o->callback((Fl_Callback *)partition_cancel_cb, &dlg);
    }
    y += BH + WB;
    g->end();
    g->show();
  }

  dlg.window->end();
  dlg.window->hotspot(dlg.window);

  dlg.read_all_options();
  // Set the groups to be initally displayed
  partition_select_groups_cb(dlg.window, &dlg);
  dlg.window->show();
}

#endif  // compiling partition dialog
