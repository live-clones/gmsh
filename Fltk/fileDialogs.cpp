// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Stephen Guzik
//

#include <limits>
#include <errno.h>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Value_Slider.H>
#include <FL/Fl_Menu_Window.H>
#include <FL/Fl_Select_Browser.H>
#include <FL/Fl_Toggle_Button.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Choice.H>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "GmshDefines.h"
#include "FlGui.h"
#include "fileDialogs.h"
#include "CreateFile.h"
#include "Options.h"
#include "GModel.h"
#include "Context.h"

// File chooser

#if defined(HAVE_NATIVE_FILE_CHOOSER)

#include <FL/Fl_Native_File_Chooser.H>
static Fl_Native_File_Chooser *fc = 0;

#else

#include <FL/Fl_File_Chooser.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_File_Input.H>

class flFileChooser : public Fl_File_Chooser {
  // we derive our own so we can set its position (The original file
  // chooser doesn't expose its window to the world, so we need to use
  // a cheap hack to get to it. Even worse is the hack used to get the
  // focus on the file input widget.)
 private:
  Fl_Window *_win;
  Fl_File_Input *_in;
 public:
  flFileChooser(const char *d, const char *p, int t, const char *title)
    : Fl_File_Chooser(d, p, t, title) 
  { 
    _win = dynamic_cast<Fl_Window*>(newButton->parent()->parent()); 
    _in = dynamic_cast<Fl_File_Input *>(previewButton->parent()->parent()->resizable());
  }
  void show()
  {
    if(_win){
      _win->show();
      rescan(); // necessary since fltk 1.1.7
      if(_in) _in->take_focus();
      else _win->take_focus();
    }
    else
      Fl_File_Chooser::show();
  }
  void position(int x, int y){ if(_win) _win->position(x,y); }
  int x(){ if(_win) return _win->x(); else return 100; }
  int y(){ if(_win) return _win->y(); else return 100; }
};

static flFileChooser *fc = 0;

#endif

int fileChooser(FILE_CHOOSER_TYPE type, const char *message,
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
  switch(type){
  case FILE_CHOOSER_MULTI: 
    fc->type(Fl_Native_File_Chooser::BROWSE_MULTI_FILE); break;
  case FILE_CHOOSER_CREATE:
    fc->type(Fl_Native_File_Chooser::BROWSE_SAVE_FILE); break;
  case FILE_CHOOSER_DIRECTORY:
    fc->type(Fl_Native_File_Chooser::BROWSE_DIRECTORY); break;
  default:
    fc->type(Fl_Native_File_Chooser::BROWSE_FILE); break;
  }
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
    fc = new flFileChooser(getenv("PWD") ? "." : CTX::instance()->homeDir.c_str(), 
                           thefilter, Fl_File_Chooser::SINGLE, message);
    fc->position(CTX::instance()->fileChooserPosition[0], 
                 CTX::instance()->fileChooserPosition[1]);
  }
  switch(type){
  case FILE_CHOOSER_MULTI: 
    fc->type(Fl_File_Chooser::MULTI); break;
  case FILE_CHOOSER_CREATE:
    fc->type(Fl_File_Chooser::CREATE); break;
  case FILE_CHOOSER_DIRECTORY:
    fc->type(Fl_File_Chooser::DIRECTORY); break;
  default:
    fc->type(Fl_File_Chooser::SINGLE); break;
  }
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

std::string fileChooserGetName(int num)
{
  if(!fc) return "";
#if defined(HAVE_NATIVE_FILE_CHOOSER)
  return std::string(fc->filename(num - 1));
#else
  return std::string(fc->value(num));
#endif
}

int fileChooserGetFilter()
{
  if(!fc) return 0;
  return fc->filter_value();
}

void fileChooserGetPosition(int *x, int *y)
{
  if(!fc) return;
#if !defined(HAVE_NATIVE_FILE_CHOOSER)
  *x = fc->x();
  *y = fc->y();
#endif
}

// Generic save bitmap dialog

int genericBitmapFileDialog(const char *name, const char *title, int format)
{
  struct _genericBitmapFileDialog{
    Fl_Window *window;
    Fl_Check_Button *b[2];
    Fl_Button *ok, *cancel;
  };
  static _genericBitmapFileDialog *dialog = NULL;

  if(!dialog){
    dialog = new _genericBitmapFileDialog;
    int h = 3 * WB + 3 * BH, w = 2 * BB + 3 * WB, y = WB;
    dialog->window = new Fl_Double_Window(w, h);
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->window->set_modal();
    dialog->b[0] = new Fl_Check_Button
      (WB, y, 2 * BB + WB, BH, "Print text strings"); y += BH;
    dialog->b[0]->type(FL_TOGGLE_BUTTON);
    dialog->b[1] = new Fl_Check_Button
      (WB, y, 2 * BB + WB, BH, "Composite all window tiles"); y += BH;
    dialog->b[1]->type(FL_TOGGLE_BUTTON);
    dialog->ok = new Fl_Return_Button(WB, y + WB, BB, BH, "OK");
    dialog->cancel = new Fl_Button(2 * WB + BB, y + WB, BB, BH, "Cancel");
    dialog->window->end();
    dialog->window->hotspot(dialog->window);
  }
  
  dialog->window->label(title);
  dialog->b[0]->value(CTX::instance()->print.text);
  dialog->b[1]->value(CTX::instance()->print.compositeWindows);
  dialog->window->show();

  while(dialog->window->shown()){
    Fl::wait();
    for (;;) {
      Fl_Widget* o = Fl::readqueue();
      if (!o) break;
      if (o == dialog->ok) {
        opt_print_text(0, GMSH_SET | GMSH_GUI, (int)dialog->b[0]->value());
        opt_print_composite_windows(0, GMSH_SET | GMSH_GUI, (int)dialog->b[1]->value());
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

int latexFileDialog(const char *name)
{
  struct _latexFileDialog{
    Fl_Window *window;
    Fl_Check_Button *b;
    Fl_Button *ok, *cancel;
  };
  static _latexFileDialog *dialog = NULL;
  
  if(!dialog){
    dialog = new _latexFileDialog;
    int h = 3 * WB + 2 * BH, w = 2 * BB + 3 * WB, y = WB;
    dialog->window = new Fl_Double_Window(w, h, "LaTeX Options");
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->window->set_modal();
    dialog->b = new Fl_Check_Button
      (WB, y, 2 * BB + WB, BH, "Print strings as equations"); y += BH;
    dialog->b->type(FL_TOGGLE_BUTTON);
    dialog->ok = new Fl_Return_Button(WB, y + WB, BB, BH, "OK");
    dialog->cancel = new Fl_Button(2 * WB + BB, y + WB, BB, BH, "Cancel");
    dialog->window->end();
    dialog->window->hotspot(dialog->window);
  }
  
  dialog->b->value(CTX::instance()->print.texAsEquation);
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

int jpegFileDialog(const char *name)
{
  struct _jpegFileDialog{
    Fl_Window *window;
    Fl_Value_Slider *s[2];
    Fl_Check_Button *b[2];
    Fl_Button *ok, *cancel;
  };
  static _jpegFileDialog *dialog = NULL;

  if(!dialog){
    dialog = new _jpegFileDialog;
    int h = 3 * WB + 5 * BH, w = 2 * BB + 3 * WB, y = WB;
    dialog->window = new Fl_Double_Window(w, h, "JPEG Options");
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->window->set_modal();
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
    dialog->b[0] = new Fl_Check_Button
      (WB, y, 2 * BB + WB, BH, "Print text strings"); y += BH;
    dialog->b[0]->type(FL_TOGGLE_BUTTON);
    dialog->b[1] = new Fl_Check_Button
      (WB, y, 2 * BB + WB, BH, "Composite all window tiles"); y += BH;
    dialog->b[1]->type(FL_TOGGLE_BUTTON);
    dialog->ok = new Fl_Return_Button(WB, y + WB, BB, BH, "OK");
    dialog->cancel = new Fl_Button(2 * WB + BB, y + WB, BB, BH, "Cancel");
    dialog->window->end();
    dialog->window->hotspot(dialog->window);
  }
  
  dialog->s[0]->value(CTX::instance()->print.jpegQuality);
  dialog->s[1]->value(CTX::instance()->print.jpegSmoothing);
  dialog->b[0]->value(CTX::instance()->print.text);
  dialog->b[1]->value(CTX::instance()->print.compositeWindows);
  dialog->window->show();

  while(dialog->window->shown()){
    Fl::wait();
    for (;;) {
      Fl_Widget* o = Fl::readqueue();
      if (!o) break;
      if (o == dialog->ok) {
        opt_print_jpeg_quality(0, GMSH_SET | GMSH_GUI, (int)dialog->s[0]->value());
        opt_print_jpeg_smoothing(0, GMSH_SET | GMSH_GUI, (int)dialog->s[1]->value());
        opt_print_text(0, GMSH_SET | GMSH_GUI, (int)dialog->b[0]->value());
        opt_print_composite_windows(0, GMSH_SET | GMSH_GUI, (int)dialog->b[1]->value());
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

int gifFileDialog(const char *name)
{
  struct _gifFileDialog{
    Fl_Window *window;
    Fl_Check_Button *b[6];
    Fl_Button *ok, *cancel;
  };
  static _gifFileDialog *dialog = NULL;

  if(!dialog){
    dialog = new _gifFileDialog;
    int h = 3 * WB + 7 * BH, w = 2 * BB + 3 * WB, y = WB;
    dialog->window = new Fl_Double_Window(w, h, "GIF Options");
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->window->set_modal();
    dialog->b[0] = new Fl_Check_Button
      (WB, y, 2 * BB + WB, BH, "Dither"); y += BH;
    dialog->b[1] = new Fl_Check_Button
      (WB, y, 2 * BB + WB, BH, "Interlace"); y += BH;
    dialog->b[2] = new Fl_Check_Button
      (WB, y, 2 * BB + WB, BH, "Sort colormap"); y += BH;
    dialog->b[3] = new Fl_Check_Button
      (WB, y, 2 * BB + WB, BH, "Transparent background"); y += BH;
    dialog->b[4] = new Fl_Check_Button
      (WB, y, 2 * BB + WB, BH, "Print text strings"); y += BH;
    dialog->b[5] = new Fl_Check_Button
      (WB, y, 2 * BB + WB, BH, "Composite all window tiles"); y += BH;
    for(int i = 0; i < 6; i++){
      dialog->b[i]->type(FL_TOGGLE_BUTTON);
    }
    dialog->ok = new Fl_Return_Button(WB, y + WB, BB, BH, "OK");
    dialog->cancel = new Fl_Button(2 * WB + BB, y + WB, BB, BH, "Cancel");
    dialog->window->end();
    dialog->window->hotspot(dialog->window);
  }
  
  dialog->b[0]->value(CTX::instance()->print.gifDither);
  dialog->b[1]->value(CTX::instance()->print.gifInterlace);
  dialog->b[2]->value(CTX::instance()->print.gifSort);
  dialog->b[3]->value(CTX::instance()->print.gifTransparent);
  dialog->b[4]->value(CTX::instance()->print.text);
  dialog->b[5]->value(CTX::instance()->print.compositeWindows);
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
        opt_print_composite_windows(0, GMSH_SET | GMSH_GUI, dialog->b[5]->value());
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

int gl2psFileDialog(const char *name, const char *title, int format)
{
  struct _gl2psFileDialog{
    Fl_Window *window;
    Fl_Check_Button *b[6];
    Fl_Choice *c;
    Fl_Button *ok, *cancel;
  };
  static _gl2psFileDialog *dialog = NULL;

  static Fl_Menu_Item sortmenu[] = {
    {"Raster image", 0, 0, 0},
    {"Vector simple sort", 0, 0, 0},
    {"Vector accurate sort", 0, 0, 0},
    {"Vector unsorted", 0, 0, 0},
    {0}
  };

  if(!dialog){
    dialog = new _gl2psFileDialog;
    int h = 3 * WB + 8 * BH, w = 2 * BB + 3 * WB, y = WB;
    dialog->window = new Fl_Double_Window(w, h);
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->window->set_modal();
    dialog->c = new Fl_Choice(WB, y, BB + WB + BB / 2, BH, "Type"); y += BH;
    dialog->c->menu(sortmenu);
    dialog->c->align(FL_ALIGN_RIGHT);
    dialog->b[0] = new Fl_Check_Button
      (WB, y, 2 * BB + WB, BH, "Compress"); y += BH;
    dialog->b[1] = new Fl_Check_Button
      (WB, y, 2 * BB + WB, BH, "Print background"); y += BH;
    dialog->b[2] = new Fl_Check_Button
      (WB, y, 2 * BB + WB, BH, "Remove hidden primitives"); y += BH;
    dialog->b[3] = new Fl_Check_Button
      (WB, y, 2 * BB + WB, BH, "Optimize BSP tree"); y += BH;
    dialog->b[4] = new Fl_Check_Button
      (WB, y, 2 * BB + WB, BH, "Use level 3 shading"); y += BH;
    dialog->b[5] = new Fl_Check_Button
      (WB, y, 2 * BB + WB, BH, "Print text strings"); y += BH;
    for(int i = 0; i < 6; i++){
      dialog->b[i]->type(FL_TOGGLE_BUTTON);
    }
    dialog->ok = new Fl_Return_Button(WB, y + WB, BB, BH, "OK");
    dialog->cancel = new Fl_Button(2 * WB + BB, y + WB, BB, BH, "Cancel");
    dialog->window->end();
    dialog->window->hotspot(dialog->window);
  }
  
  dialog->window->label(title);
  dialog->c->value(CTX::instance()->print.epsQuality);
  dialog->b[0]->value(CTX::instance()->print.epsCompress);
  dialog->b[1]->value(CTX::instance()->print.epsBackground);
  dialog->b[2]->value(CTX::instance()->print.epsOcclusionCulling);
  dialog->b[3]->value(CTX::instance()->print.epsBestRoot);
  dialog->b[4]->value(CTX::instance()->print.epsPS3Shading);
  dialog->b[5]->value(CTX::instance()->print.text);

  activate_gl2ps_choices(format, CTX::instance()->print.epsQuality, dialog->b);

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

int optionsFileDialog(const char *name)
{
  struct _optionsFileDialog{
    Fl_Window *window;
    Fl_Check_Button *b[2];
    Fl_Button *ok, *cancel;
  };
  static _optionsFileDialog *dialog = NULL;

  if(!dialog){
    dialog = new _optionsFileDialog;
    int h = 3 * WB + 3 * BH, w = 2 * BB + 3 * WB, y = WB;
    dialog->window = new Fl_Double_Window(w, h, "Options");
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->window->set_modal();
    dialog->b[0] = new Fl_Check_Button
      (WB, y, 2 * BB + WB, BH, "Save only modified options"); y += BH;
    dialog->b[0]->value(1);
    dialog->b[0]->type(FL_TOGGLE_BUTTON);
    dialog->b[1] = new Fl_Check_Button
      (WB, y, 2 * BB + WB, BH, "Print help strings"); y += BH;
    dialog->b[1]->value(0);
    dialog->b[1]->type(FL_TOGGLE_BUTTON);
    dialog->ok = new Fl_Return_Button(WB, y + WB, BB, BH, "OK");
    dialog->cancel = new Fl_Button(2 * WB + BB, y + WB, BB, BH, "Cancel");
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
        Msg::StatusBar(2, true, "Writing '%s'", name);
        PrintOptions(0, GMSH_FULLRC, dialog->b[0]->value(), dialog->b[1]->value(), name);
        Msg::StatusBar(2, true, "Done writing '%s'", name);
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

int geoFileDialog(const char *name)
{
  struct _geoFileDialog{
    Fl_Window *window;
    Fl_Check_Button *b;
    Fl_Button *ok, *cancel;
  };
  static _geoFileDialog *dialog = NULL;

  if(!dialog){
    dialog = new _geoFileDialog;
    int h = 3 * WB + 2 * BH, w = 2 * BB + 3 * WB, y = WB;
    dialog->window = new Fl_Double_Window(w, h, "GEO Options");
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->window->set_modal();
    dialog->b = new Fl_Check_Button
      (WB, y, 2 * BB + WB, BH, "Save physical group labels"); y += BH;
    dialog->b->type(FL_TOGGLE_BUTTON);
    dialog->ok = new Fl_Return_Button(WB, y + WB, BB, BH, "OK");
    dialog->cancel = new Fl_Button(2 * WB + BB, y + WB, BB, BH, "Cancel");
    dialog->window->end();
    dialog->window->hotspot(dialog->window);
  }
  
  dialog->b->value(CTX::instance()->print.geoLabels ? 1 : 0);
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

int posFileDialog(const char *name)
{
  struct _posFileDialog{
    Fl_Window *window;
    Fl_Check_Button *b[7];
    Fl_Button *ok, *cancel;
  };
  static _posFileDialog *dialog = NULL;

  int BBB = BB + 9; // labels too long

  if(!dialog){
    dialog = new _posFileDialog;
    int h = 3 * WB + 8 * BH, w = 2 * BBB + 3 * WB, y = WB;
    dialog->window = new Fl_Double_Window(w, h, "POS Options");
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->window->set_modal();
    dialog->b[0] = new Fl_Check_Button
      (WB, y, 2 * BBB + WB, BH, "Save all (ignore physical groups)"); y += BH;
    dialog->b[1] = new Fl_Check_Button
      (WB, y, 2 * BBB + WB, BH, "Print elementary tags"); y += BH;
    dialog->b[2] = new Fl_Check_Button
      (WB, y, 2 * BBB + WB, BH, "Print element numbers"); y += BH;
    dialog->b[3] = new Fl_Check_Button
      (WB, y, 2 * BBB + WB, BH, "Print Gamma quality measure"); y += BH;
    dialog->b[4] = new Fl_Check_Button
      (WB, y, 2 * BBB + WB, BH, "Print Eta quality measure"); y += BH;
    dialog->b[5] = new Fl_Check_Button
      (WB, y, 2 * BBB + WB, BH, "Print Rho quality measure"); y += BH;
    dialog->b[6] = new Fl_Check_Button
      (WB, y, 2 * BBB + WB, BH, "Print Disto quality measure"); y += BH;
    for(int i = 0; i < 6; i++)
      dialog->b[i]->type(FL_TOGGLE_BUTTON);
    dialog->ok = new Fl_Return_Button(WB, y + WB, BBB, BH, "OK");
    dialog->cancel = new Fl_Button(2 * WB + BBB, y + WB, BBB, BH, "Cancel");
    dialog->window->end();
    dialog->window->hotspot(dialog->window);
  }
  
  dialog->b[0]->value(CTX::instance()->mesh.saveAll ? 1 : 0);
  dialog->b[1]->value(CTX::instance()->print.posElementary ? 1 : 0);
  dialog->b[2]->value(CTX::instance()->print.posElement ? 1 : 0);
  dialog->b[3]->value(CTX::instance()->print.posGamma ? 1 : 0);
  dialog->b[4]->value(CTX::instance()->print.posEta ? 1 : 0);
  dialog->b[5]->value(CTX::instance()->print.posRho ? 1 : 0);
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

// Save msh dialog

int mshFileDialog(const char *name)
{
  struct _mshFileDialog{
    Fl_Window *window;
    Fl_Check_Button *b[3];
    Fl_Choice *c;
    Fl_Button *ok, *cancel;
  };
  static _mshFileDialog *dialog = NULL;

  static Fl_Menu_Item formatmenu[] = {
    {"Version 1", 0, 0, 0},
    {"Version 2 ASCII", 0, 0, 0},
    {"Version 2 Binary", 0, 0, 0},
    {0}
  };

  int BBB = BB + 9; // labels too long

  if(!dialog){
    dialog = new _mshFileDialog;
    int h = 3 * WB + 5 * BH, w = 2 * BBB + 3 * WB, y = WB;
    dialog->window = new Fl_Double_Window(w, h, "MSH Options");
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->window->set_modal();
    dialog->c = new Fl_Choice(WB, y, BBB + BBB / 2, BH, "Format"); y += BH;
    dialog->c->menu(formatmenu);
    dialog->c->align(FL_ALIGN_RIGHT);
    dialog->b[0] = new Fl_Check_Button
      (WB, y, 2 * BBB + WB, BH, "Save all (ignore physical groups)"); y += BH;
    dialog->b[0]->type(FL_TOGGLE_BUTTON);
    dialog->b[1] = new Fl_Check_Button
      (WB, y, 2 * BBB + WB, BH, "Save parametric coordinates"); y += BH;
    dialog->b[1]->type(FL_TOGGLE_BUTTON);
    dialog->b[2] = new Fl_Check_Button
      (WB, y, 2 * BBB + WB, BH, "Save one file per partition"); y += BH;
    dialog->b[2]->type(FL_TOGGLE_BUTTON);

    dialog->ok = new Fl_Return_Button(WB, y + WB, BBB, BH, "OK");
    dialog->cancel = new Fl_Button(2 * WB + BBB, y + WB, BBB, BH, "Cancel");
    dialog->window->end();
    dialog->window->hotspot(dialog->window);
  }
  
  dialog->c->value((CTX::instance()->mesh.mshFileVersion == 1.0) ? 0 : 
                   CTX::instance()->mesh.binary ? 2 : 1);
  dialog->b[0]->value(CTX::instance()->mesh.saveAll ? 1 : 0);
  dialog->b[1]->value(CTX::instance()->mesh.saveParametric ? 1 : 0);
  dialog->b[2]->value(CTX::instance()->mesh.mshFilePartitioned ? 1 : 0);
  dialog->window->show();

  while(dialog->window->shown()){
    Fl::wait();
    for (;;) {
      Fl_Widget* o = Fl::readqueue();
      if (!o) break;
      if (o == dialog->ok) {
        opt_mesh_msh_file_version(0, GMSH_SET | GMSH_GUI, 
                                  (dialog->c->value() == 0) ? 1.0 : 2.2);
        opt_mesh_binary(0, GMSH_SET | GMSH_GUI, (dialog->c->value() == 2) ? 1 : 0);
        opt_mesh_save_all(0, GMSH_SET | GMSH_GUI, dialog->b[0]->value() ? 1 : 0);
        opt_mesh_save_parametric(0, GMSH_SET | GMSH_GUI, dialog->b[1]->value() ? 1 : 0);
        opt_mesh_msh_file_partitioned(0, GMSH_SET | GMSH_GUI, dialog->b[2]->value() ? 1 : 0);
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

int unvFileDialog(const char *name)
{
  struct _unvFileDialog{
    Fl_Window *window;
    Fl_Check_Button *b[2];
    Fl_Button *ok, *cancel;
  };
  static _unvFileDialog *dialog = NULL;

  int BBB = BB + 9; // labels too long

  if(!dialog){
    dialog = new _unvFileDialog;
    int h = 3 * WB + 3 * BH, w = 2 * BBB + 3 * WB, y = WB;
    dialog->window = new Fl_Double_Window(w, h, "UNV Options");
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->window->set_modal();
    dialog->b[0] = new Fl_Check_Button
      (WB, y, 2 * BBB + WB, BH, "Save all (ignore physical groups)"); y += BH;
    dialog->b[0]->type(FL_TOGGLE_BUTTON);
    dialog->b[1] = new Fl_Check_Button
      (WB, y, 2 * BBB + WB, BH, "Save groups of nodes"); y += BH;
    dialog->b[1]->type(FL_TOGGLE_BUTTON);
    dialog->ok = new Fl_Return_Button(WB, y + WB, BBB, BH, "OK");
    dialog->cancel = new Fl_Button(2 * WB + BBB, y + WB, BBB, BH, "Cancel");
    dialog->window->end();
    dialog->window->hotspot(dialog->window);
  }
  
  dialog->b[0]->value(CTX::instance()->mesh.saveAll ? 1 : 0);
  dialog->b[1]->value(CTX::instance()->mesh.saveGroupsOfNodes ? 1 : 0);
  dialog->window->show();

  while(dialog->window->shown()){
    Fl::wait();
    for (;;) {
      Fl_Widget* o = Fl::readqueue();
      if (!o) break;
      if (o == dialog->ok) {
        opt_mesh_save_all(0, GMSH_SET | GMSH_GUI, dialog->b[0]->value() ? 1 : 0);
        opt_mesh_save_groups_of_nodes(0, GMSH_SET | GMSH_GUI, 
                                      dialog->b[1]->value() ? 1 : 0);
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

int bdfFileDialog(const char *name)
{
  struct _bdfFileDialog{
    Fl_Window *window;
    Fl_Choice *c, *d;
    Fl_Check_Button *b;
    Fl_Button *ok, *cancel;
  };
  static _bdfFileDialog *dialog = NULL;

  static Fl_Menu_Item formatmenu[] = {
    {"Free field", 0, 0, 0},
    {"Small field", 0, 0, 0},
    {"Long field", 0, 0, 0},
    {0}
  };

  static Fl_Menu_Item tagmenu[] = {
    {"Elementary entity", 0, 0, 0},
    {"Physical entity", 0, 0, 0},
    {"Partition", 0, 0, 0},
    {0}
  };
  
  int BBB = BB + 16; // labels too long

  if(!dialog){
    dialog = new _bdfFileDialog;
    int h = 3 * WB + 4 * BH, w = 2 * BBB + 3 * WB, y = WB;
    dialog->window = new Fl_Double_Window(w, h, "BDF Options");
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->window->set_modal();
    dialog->c = new Fl_Choice(WB, y, BBB + BBB / 4, BH, "Format"); y += BH;
    dialog->c->menu(formatmenu);
    dialog->c->align(FL_ALIGN_RIGHT);
    dialog->d = new Fl_Choice(WB, y, BBB + BBB / 4, BH, "Element tag"); y += BH;
    dialog->d->menu(tagmenu);
    dialog->d->align(FL_ALIGN_RIGHT);
    dialog->b = new Fl_Check_Button
      (WB, y, 2 * BBB + WB, BH, "Save all (ignore physical groups)"); y += BH;
    dialog->b->type(FL_TOGGLE_BUTTON);
    dialog->ok = new Fl_Return_Button(WB, y + WB, BBB, BH, "OK");
    dialog->cancel = new Fl_Button(2 * WB + BBB, y + WB, BBB, BH, "Cancel");
    dialog->window->end();
    dialog->window->hotspot(dialog->window);
  }
  
  dialog->c->value(CTX::instance()->mesh.bdfFieldFormat);
  dialog->d->value((CTX::instance()->mesh.saveElementTagType == 3) ? 2 :
                   (CTX::instance()->mesh.saveElementTagType == 2) ? 1 : 0);
  dialog->b->value(CTX::instance()->mesh.saveAll ? 1 : 0);
  dialog->window->show();

  while(dialog->window->shown()){
    Fl::wait();
    for (;;) {
      Fl_Widget* o = Fl::readqueue();
      if (!o) break;
      if (o == dialog->ok) {
        opt_mesh_bdf_field_format(0, GMSH_SET | GMSH_GUI, dialog->c->value());
        opt_mesh_save_element_tag_type(0, GMSH_SET | GMSH_GUI, 
                                       dialog->d->value() + 1);
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

// Generic mesh dialog

int genericMeshFileDialog(const char *name, const char *title, int format,
                        bool binary_support, bool element_tag_support)
{
  struct _genericMeshFileDialog{
    Fl_Window *window;
    Fl_Choice *c, *d;
    Fl_Check_Button *b;
    Fl_Button *ok, *cancel;
  };
  static _genericMeshFileDialog *dialog = NULL;

  static Fl_Menu_Item formatmenu[] = {
    {"ASCII", 0, 0, 0},
    {"Binary", 0, 0, 0},
    {0}
  };

  static Fl_Menu_Item tagmenu[] = {
    {"Elementary entity", 0, 0, 0},
    {"Physical entity", 0, 0, 0},
    {"Partition", 0, 0, 0},
    {0}
  };

  int BBB = BB + 16; // labels too long

  if(!dialog){
    dialog = new _genericMeshFileDialog;
    int h = 3 * WB + 4 * BH, w = 2 * BBB + 3 * WB, y = WB;
    dialog->window = new Fl_Double_Window(w, h);
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->window->set_modal();
    dialog->c = new Fl_Choice(WB, y, BBB + BBB / 4, BH, "Format"); y += BH;
    dialog->c->menu(formatmenu);
    dialog->c->align(FL_ALIGN_RIGHT);
    dialog->d = new Fl_Choice(WB, y, BBB + BBB / 4, BH, "Element tag"); y += BH;
    dialog->d->menu(tagmenu);
    dialog->d->align(FL_ALIGN_RIGHT);
    dialog->b = new Fl_Check_Button
      (WB, y, 2 * BBB + WB, BH, "Save all (ignore physical groups)"); y += BH;
    dialog->b->type(FL_TOGGLE_BUTTON);
    dialog->ok = new Fl_Return_Button(WB, y + WB, BBB, BH, "OK");
    dialog->cancel = new Fl_Button(2 * WB + BBB, y + WB, BBB, BH, "Cancel");
    dialog->window->end();
    dialog->window->hotspot(dialog->window);
  }
  
  dialog->window->label(title);
  dialog->c->value(CTX::instance()->mesh.binary ? 1 : 0);
  if(binary_support)
    dialog->c->activate();
  else
    dialog->c->deactivate();
  dialog->d->value((CTX::instance()->mesh.saveElementTagType == 3) ? 2 :
                   (CTX::instance()->mesh.saveElementTagType == 2) ? 1 : 0);
  if(element_tag_support)
    dialog->d->activate();
  else
    dialog->d->deactivate();
  dialog->b->value(CTX::instance()->mesh.saveAll ? 1 : 0);
  dialog->window->show();

  while(dialog->window->shown()){
    Fl::wait();
    for (;;) {
      Fl_Widget* o = Fl::readqueue();
      if (!o) break;
      if (o == dialog->ok) {
        opt_mesh_binary(0, GMSH_SET | GMSH_GUI, dialog->c->value());
        opt_mesh_save_element_tag_type(0, GMSH_SET | GMSH_GUI, 
                                       dialog->d->value() + 1);
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
    CTX::instance()->cgnsOptions.baseName = inputBaseName->value();
    CTX::instance()->cgnsOptions.zoneName = inputZoneName->value();
    CTX::instance()->cgnsOptions.interfaceName = inputInterfaceName->value();
    CTX::instance()->cgnsOptions.patchName = inputPatchName->value();
    CTX::instance()->cgnsOptions.gridConnectivityLocation =
      roundButton1GCatFace->value();
    CTX::instance()->cgnsOptions.writeBC = checkButtonWriteBC->value();
    CTX::instance()->cgnsOptions.bocoLocation = roundButton1BCatFace->value();
    CTX::instance()->cgnsOptions.normalSource = (checkButtonWriteNormals->value()) ?
       roundButton1NormalElem->value() + 1 : 0;
    CTX::instance()->cgnsOptions.vectorDim = choiceVecDim->value() + 2;
    CTX::instance()->cgnsOptions.writeUserDef = checkButtonUnknownUserDef->value();
  }
  void read_all_options()
  {
    choiceZoneDef->value(CTX::instance()->mesh.zoneDefinition);
    inputBaseName->value(CTX::instance()->cgnsOptions.baseName.c_str());
    inputZoneName->value(CTX::instance()->cgnsOptions.zoneName.c_str());
    inputInterfaceName->value(CTX::instance()->cgnsOptions.interfaceName.c_str());
    inputPatchName->value(CTX::instance()->cgnsOptions.patchName.c_str());
    checkButtonWriteBC->value(CTX::instance()->cgnsOptions.writeBC);
    checkButtonWriteNormals->value(CTX::instance()->cgnsOptions.normalSource);
    choiceVecDim->value(CTX::instance()->cgnsOptions.vectorDim - 2);
    checkButtonUnknownUserDef->value(CTX::instance()->cgnsOptions.writeUserDef);

    // Call all callbacks to ensure consistent options
    cgnsw_gc_location_cb
      ((CTX::instance()->cgnsOptions.gridConnectivityLocation) ?
       roundButton1GCatFace : roundButton0GCatVertex, this);
    // The order of the next 4 is important
    cgnsw_normal_source_cb
      ((CTX::instance()->cgnsOptions.normalSource == 2) ?
       roundButton1NormalElem : roundButton0NormalGeo, this);
    cgnsw_write_normals_cb(checkButtonWriteNormals, this);
    cgnsw_bc_location_cb
      ((CTX::instance()->cgnsOptions.bocoLocation) ?
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
    // dlg->roundButton1BCatFace->activate();  //**Tmp
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
  CTX::instance()->cgnsOptions.setDefaults();
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

int cgnsFileDialog(const char *filename)
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

  const int RBH = 3 * FL_NORMAL_SIZE/2; // radio button height
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

  dlg.window = new Fl_Double_Window(w, h, "CGNS Options");
  dlg.window->box(GMSH_WINDOW_BOX);
  dlg.window->set_modal();
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

int cgnsFileDialog(const char *filename)
{
  CreateOutputFile(filename, FORMAT_CGNS);
  return 1;
}

#endif  // compiling CGNS write dialog
