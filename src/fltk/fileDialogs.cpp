// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Stephen Guzik
//   Sebastian Eiser

#include <limits>
#include <sstream>
#include <errno.h>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Value_Slider.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Menu_Window.H>
#include <FL/Fl_Select_Browser.H>
#include <FL/Fl_Toggle_Button.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Native_File_Chooser.H>
#include <FL/Fl_File_Chooser.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_File_Input.H>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "GmshDefines.h"
#include "StringUtils.h"
#include "FlGui.h"
#include "optionWindow.h"
#include "fileDialogs.h"
#include "CreateFile.h"
#include "Options.h"
#include "Context.h"
#include "GModel.h"
#include "PView.h"
#include "PViewOptions.h"
#include <iostream>

// basic file chooser
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
    _win = dynamic_cast<Fl_Window *>(newButton->parent()->parent());
    _in = dynamic_cast<Fl_File_Input *>(
      previewButton->parent()->parent()->resizable());
  }
  void show()
  {
    if(_win) {
      _win->show();
      rescan(); // necessary since fltk 1.1.7
      if(_in)
        _in->take_focus();
      else
        _win->take_focus();
    }
    else
      Fl_File_Chooser::show();
  }
  void position(int x, int y)
  {
    if(_win) _win->position(x, y);
  }
  int x()
  {
    if(_win)
      return _win->x();
    else
      return 100;
  }
  int y()
  {
    if(_win)
      return _win->y();
    else
      return 100;
  }
};

static flFileChooser *fc = nullptr;

// native file chooser
static Fl_Native_File_Chooser *nfc = nullptr;

int fileChooser(FILE_CHOOSER_TYPE type, const char *message, const char *filter,
                const char *fname)
{
  static char thefilter[2000] = "";
  static char thefilter2[2000] = "";
  static int thefilterindex = 0;

  // reset the filter and the selection if the filter has changed
  if(strncmp(thefilter, filter, sizeof(thefilter) - 1)) {
    strncpy(thefilter, filter, sizeof(thefilter) - 1);
    thefilter[sizeof(thefilter) - 1] = '\0';
    thefilterindex = 0;
    // for the basic file chooser, we should replace
    //  * "\t" with " ("
    //  * "\n" with ")\t"
    std::string tmp(thefilter);
    ReplaceSubStringInPlace("\t", " (", tmp);
    ReplaceSubStringInPlace("\n", ")\t", tmp);
    strncpy(thefilter2, tmp.c_str(), sizeof(thefilter2) - 1);
    thefilter2[sizeof(thefilter2) - 1] = '\0';
  }

  // determine where to start
  std::string thepath;
  if(fname)
    thepath = std::string(fname);
  else {
    std::vector<std::string> tmp =
      SplitFileName(GModel::current()->getFileName());
    thepath = tmp[0] + tmp[1]; // i.e., without the extension!
  }
  std::vector<std::string> split = SplitFileName(thepath);
  if(split[0].empty()) thepath = std::string("./") + thepath;

  if(CTX::instance()->nativeFileChooser) {
    if(!nfc) {
      nfc = new Fl_Native_File_Chooser();
      nfc->preset_file(thepath.c_str());
    }
    else {
      std::string name = split[1] + split[2];
      nfc->preset_file(name.c_str());
    }

    switch(type) {
    case FILE_CHOOSER_MULTI:
      nfc->type(Fl_Native_File_Chooser::BROWSE_MULTI_FILE);
      break;
    case FILE_CHOOSER_CREATE:
      nfc->type(Fl_Native_File_Chooser::BROWSE_SAVE_FILE);
      break;
    case FILE_CHOOSER_DIRECTORY:
      nfc->type(Fl_Native_File_Chooser::BROWSE_DIRECTORY);
      break;
    default: nfc->type(Fl_Native_File_Chooser::BROWSE_FILE); break;
    }
    nfc->title(message);
    nfc->filter(thefilter);
    nfc->filter_value(thefilterindex);

    int ret = 0;
    switch(nfc->show()) {
    case -1: break; // error
    case 1: break; // cancel
    default:
      if(nfc->filename()) ret = nfc->count();
      break;
    }
    thefilterindex = nfc->filter_value();
    // hack to clear the KEYDOWN state that remains when calling the
    // file chooser on Mac and Windows using a keyboard shortcut
    Fl::e_state = 0;
    return ret;
  }
  else {
    Fl_File_Chooser::show_label = "Format:";
    Fl_File_Chooser::all_files_label = "All files (*)";
    if(!fc) {
      fc = new flFileChooser(thepath.c_str(), thefilter2,
                             Fl_File_Chooser::SINGLE, message);
      fc->position(CTX::instance()->fileChooserPosition[0],
                   CTX::instance()->fileChooserPosition[1]);
    }
    switch(type) {
    case FILE_CHOOSER_MULTI: fc->type(Fl_File_Chooser::MULTI); break;
    case FILE_CHOOSER_CREATE: fc->type(Fl_File_Chooser::CREATE); break;
    case FILE_CHOOSER_DIRECTORY: fc->type(Fl_File_Chooser::DIRECTORY); break;
    default: fc->type(Fl_File_Chooser::SINGLE); break;
    }
    fc->label(message);
    fc->filter(thefilter2);
    fc->filter_value(thefilterindex);
    fc->show();
    while(fc->shown()) Fl::wait();
    thefilterindex = fc->filter_value();
    if(fc->value())
      return fc->count();
    else
      return 0;
  }
}

std::string fileChooserGetName(int num)
{
  if(CTX::instance()->nativeFileChooser) {
    if(!nfc) return "";
    return std::string(nfc->filename(num - 1));
  }
  else {
    if(!fc) return "";
    return std::string(fc->value(num));
  }
}

int fileChooserGetFilter()
{
  if(CTX::instance()->nativeFileChooser) {
    if(!nfc) return 0;
    return nfc->filter_value();
  }
  else {
    if(!fc) return 0;
    return fc->filter_value();
  }
}

void fileChooserGetPosition(int *x, int *y)
{
  if(CTX::instance()->nativeFileChooser) {
    // not available
  }
  else {
    if(!fc) return;
    *x = fc->x();
    *y = fc->y();
  }
}

// Generic save bitmap dialog

int genericBitmapFileDialog(const char *name, const char *title, int format)
{
  struct _genericBitmapFileDialog {
    Fl_Window *window;
    Fl_Value_Slider *s[2];
    Fl_Check_Button *b[3];
    Fl_Value_Input *v[2];
    Fl_Button *ok, *cancel;
  };
  static _genericBitmapFileDialog *dialog = nullptr;

  if(!dialog) {
    dialog = new _genericBitmapFileDialog;
    int h = 3 * WB + 7 * BH, w = 2 * BB + 3 * WB, y = WB;
    dialog->window = new Fl_Double_Window(w, h);
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->window->set_modal();
    dialog->b[0] =
      new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Print text strings");
    dialog->b[0]->tooltip("Print.Text");
    y += BH;
    dialog->b[0]->type(FL_TOGGLE_BUTTON);
    dialog->b[1] =
      new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Print background");
    dialog->b[1]->tooltip("Print.Background");
    y += BH;
    dialog->b[1]->type(FL_TOGGLE_BUTTON);
    dialog->b[2] =
      new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Composite all window tiles");
    dialog->b[2]->tooltip("Print.CompositeWindows");
    y += BH;
    dialog->b[2]->type(FL_TOGGLE_BUTTON);
    dialog->v[0] = new Fl_Value_Input(WB, y, BB / 2, BH);
    dialog->v[0]->tooltip("Print.Width");
    dialog->v[0]->minimum(-1);
    dialog->v[0]->maximum(5000);
    if(CTX::instance()->inputScrolling) dialog->v[0]->step(1);
    dialog->v[1] =
      new Fl_Value_Input(WB + BB / 2, y, BB - BB / 2, BH, "Dimensions");
    dialog->v[1]->tooltip("Print.Height");
    y += BH;
    dialog->v[1]->minimum(-1);
    dialog->v[1]->maximum(5000);
    if(CTX::instance()->inputScrolling) dialog->v[1]->step(1);
    dialog->v[1]->align(FL_ALIGN_RIGHT);
    dialog->s[0] = new Fl_Value_Slider(WB, y, BB, BH, "Quality");
    dialog->s[0]->tooltip("Print.JpegQuality");
    y += BH;
    dialog->s[0]->type(FL_HOR_SLIDER);
    dialog->s[0]->align(FL_ALIGN_RIGHT);
    dialog->s[0]->minimum(1);
    dialog->s[0]->maximum(100);
    if(CTX::instance()->inputScrolling) dialog->s[0]->step(1);
    dialog->s[1] = new Fl_Value_Slider(WB, y, BB, BH, "Smoothing");
    dialog->s[1]->tooltip("Print.JpegSmoothing");
    y += BH;
    dialog->s[1]->type(FL_HOR_SLIDER);
    dialog->s[1]->align(FL_ALIGN_RIGHT);
    dialog->s[1]->minimum(0);
    dialog->s[1]->maximum(100);
    if(CTX::instance()->inputScrolling) dialog->s[1]->step(1);
    dialog->ok = new Fl_Return_Button(WB, y + WB, BB, BH, "OK");
    dialog->cancel = new Fl_Button(2 * WB + BB, y + WB, BB, BH, "Cancel");
    dialog->window->end();
    dialog->window->hotspot(dialog->window);
  }

  if(format == FORMAT_JPEG) {
    dialog->s[0]->activate();
    dialog->s[1]->activate();
  }
  else {
    dialog->s[0]->deactivate();
    dialog->s[1]->deactivate();
  }

  dialog->window->label(title);
  dialog->s[0]->value(opt_print_jpeg_quality(0, GMSH_GET, 0));
  dialog->s[1]->value(opt_print_jpeg_smoothing(0, GMSH_GET, 0));
  dialog->b[0]->value(opt_print_text(0, GMSH_GET, 0));
  dialog->b[1]->value(opt_print_background(0, GMSH_GET, 0));
  dialog->b[2]->value(opt_print_composite_windows(0, GMSH_GET, 0));
  dialog->v[0]->value(opt_print_width(0, GMSH_GET, 0));
  dialog->v[1]->value(opt_print_height(0, GMSH_GET, 0));
  dialog->window->show();

  while(dialog->window->shown()) {
    Fl::wait();
    for(;;) {
      Fl_Widget *o = Fl::readqueue();
      if(!o) break;
      if(o == dialog->ok) {
        opt_print_jpeg_quality(0, GMSH_SET | GMSH_GUI,
                               (int)dialog->s[0]->value());
        opt_print_jpeg_smoothing(0, GMSH_SET | GMSH_GUI,
                                 (int)dialog->s[1]->value());
        opt_print_text(0, GMSH_SET | GMSH_GUI, (int)dialog->b[0]->value());
        opt_print_background(0, GMSH_SET | GMSH_GUI,
                             (int)dialog->b[1]->value());
        opt_print_composite_windows(0, GMSH_SET | GMSH_GUI,
                                    (int)dialog->b[2]->value());
        opt_print_width(0, GMSH_SET | GMSH_GUI, (int)dialog->v[0]->value());
        opt_print_height(0, GMSH_SET | GMSH_GUI, (int)dialog->v[1]->value());
        CreateOutputFile(name, format);
        dialog->window->hide();
        return 1;
      }
      if(o == dialog->window || o == dialog->cancel) {
        dialog->window->hide();
        return 0;
      }
    }
  }
  return 0;
}

// pgf dialog

int pgfBitmapFileDialog(const char *name, const char *title, int format)
{
  struct _pgfBitmapFileDialog {
    Fl_Window *window;
    Fl_Value_Slider *s[2];
    Fl_Check_Button *b[3];
    Fl_Value_Input *v[2];
    Fl_Button *ok, *cancel;
  };
  static _pgfBitmapFileDialog *dialog = nullptr;

  if(!dialog) {
    dialog = new _pgfBitmapFileDialog;
    int h = 3 * WB + 5 * BH, w = 2 * BB + 3 * WB, y = WB;
    dialog->window = new Fl_Double_Window(w, h);
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->window->set_modal();
    dialog->b[0] = new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Flat graphics");
    dialog->b[0]->tooltip("Print.PgfTwoDim");
    y += BH;
    dialog->b[0]->type(FL_TOGGLE_BUTTON);
    dialog->b[1] = new Fl_Check_Button(WB, y, 2 * BB + WB, BH,
                                       "Export axis (for entire fig)");
    dialog->b[1]->tooltip("Print.PgfExportAxis");
    y += BH;
    dialog->b[1]->type(FL_TOGGLE_BUTTON);
    dialog->b[2] =
      new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Horizontal colorbar");
    dialog->b[2]->tooltip("Print.PgfHorizontalBar");
    y += BH;
    dialog->b[2]->type(FL_TOGGLE_BUTTON);
    dialog->v[0] = new Fl_Value_Input(WB, y, BB / 2, BH);
    dialog->v[0]->tooltip("Print.Width");
    dialog->v[0]->minimum(-1);
    dialog->v[0]->maximum(5000);
    if(CTX::instance()->inputScrolling) dialog->v[0]->step(1);
    dialog->v[1] =
      new Fl_Value_Input(WB + BB / 2, y, BB - BB / 2, BH, "Dimensions");
    dialog->v[1]->tooltip("Print.Height");
    y += BH;
    dialog->v[1]->minimum(-1);
    dialog->v[1]->maximum(5000);
    if(CTX::instance()->inputScrolling) dialog->v[1]->step(1);
    dialog->v[1]->align(FL_ALIGN_RIGHT);
    dialog->ok = new Fl_Return_Button(WB, y + WB, BB, BH, "OK");
    dialog->cancel = new Fl_Button(2 * WB + BB, y + WB, BB, BH, "Cancel");
    dialog->window->end();
    dialog->window->hotspot(dialog->window);
  }

  dialog->window->label(title);
  dialog->b[0]->value(opt_print_pgf_two_dim(0, GMSH_GET, 0));
  dialog->b[1]->value(opt_print_pgf_export_axis(0, GMSH_GET, 0));
  dialog->b[2]->value(opt_print_pgf_horiz_bar(0, GMSH_GET, 0));
  dialog->v[0]->value(opt_print_width(0, GMSH_GET, 0));
  dialog->v[1]->value(opt_print_height(0, GMSH_GET, 0));
  dialog->window->show();

  while(dialog->window->shown()) {
    Fl::wait();
    for(;;) {
      Fl_Widget *o = Fl::readqueue();
      if(!o) break;
      if(o == dialog->ok) {
        opt_print_text(0, GMSH_SET | GMSH_GUI, 0); // never print any text
        opt_print_background(0, GMSH_SET | GMSH_GUI,
                             0); // never print background
        opt_print_pgf_two_dim(0, GMSH_SET | GMSH_GUI,
                              (int)dialog->b[0]->value());
        opt_print_pgf_export_axis(0, GMSH_SET | GMSH_GUI,
                                  (int)dialog->b[1]->value());
        opt_print_pgf_horiz_bar(0, GMSH_SET | GMSH_GUI,
                                (int)dialog->b[2]->value());
        opt_print_composite_windows(0, GMSH_SET | GMSH_GUI,
                                    0); // never do compositing print
        opt_print_width(0, GMSH_SET | GMSH_GUI, (int)dialog->v[0]->value());
        opt_print_height(0, GMSH_SET | GMSH_GUI, (int)dialog->v[1]->value());
        CreateOutputFile(name, format);
        dialog->window->hide();
        return 1;
      }
      if(o == dialog->window || o == dialog->cancel) {
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
  struct _latexFileDialog {
    Fl_Window *window;
    Fl_Check_Button *b[2];
    Fl_Value_Input *v;
    Fl_Button *ok, *cancel;
  };
  static _latexFileDialog *dialog = nullptr;

  if(!dialog) {
    dialog = new _latexFileDialog;
    int h = 3 * WB + 4 * BH, w = 2 * BB + 3 * WB, y = WB;
    dialog->window = new Fl_Double_Window(w, h, "LaTeX Options");
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->window->set_modal();
    dialog->b[0] =
      new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Print strings as equations");
    dialog->b[0]->tooltip("Print.TexAsEquation");
    dialog->b[0]->type(FL_TOGGLE_BUTTON);
    y += BH;
    dialog->b[1] =
      new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Force font size");
    dialog->b[1]->tooltip("Print.TexForceFontSize");
    dialog->b[1]->type(FL_TOGGLE_BUTTON);
    y += BH;
    dialog->v = new Fl_Value_Input(WB, y, BB / 2, BH, "Graphics width in mm");
    dialog->v->tooltip("Print.TexWidthInMm (Set value to 0 to use the natural "
                       "width inferred from the width in pixels)");
    dialog->v->minimum(0);
    dialog->v->maximum(5000);
    if(CTX::instance()->inputScrolling) dialog->v->step(1);
    dialog->v->align(FL_ALIGN_RIGHT);
    y += BH;
    dialog->ok = new Fl_Return_Button(WB, y + WB, BB, BH, "OK");
    dialog->cancel = new Fl_Button(2 * WB + BB, y + WB, BB, BH, "Cancel");
    dialog->window->end();
    dialog->window->hotspot(dialog->window);
  }

  dialog->b[0]->value(opt_print_tex_as_equation(0, GMSH_GET, 0));
  dialog->b[1]->value(opt_print_tex_force_fontsize(0, GMSH_GET, 0));
  dialog->v->value(opt_print_tex_width_in_mm(0, GMSH_GET, 0));
  dialog->window->show();

  while(dialog->window->shown()) {
    Fl::wait();
    for(;;) {
      Fl_Widget *o = Fl::readqueue();
      if(!o) break;
      if(o == dialog->ok) {
        opt_print_tex_as_equation(0, GMSH_SET | GMSH_GUI,
                                  (int)dialog->b[0]->value());
        opt_print_tex_force_fontsize(0, GMSH_SET | GMSH_GUI,
                                     (int)dialog->b[1]->value());
        opt_print_tex_width_in_mm(0, GMSH_SET | GMSH_GUI, dialog->v->value());
        CreateOutputFile(name, FORMAT_TEX);
        dialog->window->hide();
        return 1;
      }
      if(o == dialog->window || o == dialog->cancel) {
        dialog->window->hide();
        return 0;
      }
    }
  }
  return 0;
}

// Save mpeg dialog

int mpegFileDialog(const char *name)
{
  struct _mpegFileDialog {
    Fl_Window *window;
    Fl_Round_Button *b[3];
    Fl_Group *param;
    Fl_Check_Button *c[3];
    Fl_Input *p;
    Fl_Value_Input *v[5];
    Fl_Group *buttons;
    Fl_Button *ok, *preview, *cancel;
  };
  static _mpegFileDialog *dialog = nullptr;

  if(!dialog) {
    dialog = new _mpegFileDialog;
    int h = 4 * WB + 11 * BH, w = 3 * BB + 4 * WB, y = WB;
    int ww = w - 2 * WB;
    dialog->window = new Fl_Double_Window(w, h, "MPEG Options");
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->window->set_non_modal();
    {
      Fl_Group *o = new Fl_Group(WB, y, ww, 3 * BH);
      dialog->b[0] =
        new Fl_Round_Button(WB, y, ww, BH, "Cycle through time steps");
      dialog->b[0]->tooltip("PostProcessing.AnimationCycle");
      y += BH;
      dialog->b[0]->type(FL_RADIO_BUTTON);
      dialog->b[1] = new Fl_Round_Button(WB, y, ww, BH, "Cycle through views");
      dialog->b[1]->tooltip("PostProcessing.AnimationCycle");
      y += BH;
      dialog->b[1]->type(FL_RADIO_BUTTON);
      dialog->b[2] =
        new Fl_Round_Button(WB, y, ww, BH, "Loop over print parameter value");
      dialog->b[2]->tooltip("PostProcessing.AnimationCycle");
      y += BH;
      dialog->b[2]->type(FL_RADIO_BUTTON);
      o->end();
    }

    int ww2 = (2 * BB + WB) / 4;

    dialog->param = new Fl_Group(WB, y, ww, 2 * BH);
    dialog->p = new Fl_Input(WB, y, ww, BH);
    dialog->p->tooltip("Print.ParameterCommand");
    y += BH;
    dialog->p->align(FL_ALIGN_RIGHT);

    dialog->v[2] = new Fl_Value_Input(WB, y, ww2, BH);
    dialog->v[2]->tooltip("Print.ParameterFirst");
    dialog->v[3] = new Fl_Value_Input(WB + ww2, y, ww2, BH);
    dialog->v[3]->tooltip("Print.ParameterLast");
    dialog->v[4] = new Fl_Value_Input(WB + 2 * ww2, y, 2 * BB + WB - 3 * ww2,
                                      BH, "First / Last / Steps");
    dialog->v[4]->tooltip("Print.ParameterSteps");
    dialog->v[4]->align(FL_ALIGN_RIGHT);
    dialog->v[4]->minimum(1);
    dialog->v[4]->maximum(500);
    if(CTX::instance()->inputScrolling) dialog->v[4]->step(1);
    y += BH;
    dialog->param->end();

    y += WB;

    dialog->v[0] =
      new Fl_Value_Input(WB, y, ww2, BH, "Frame duration (in seconds)");
    dialog->v[0]->tooltip("PostProcessing.AnimationDelay");
    y += BH;
    dialog->v[0]->minimum(1. / 30.);
    dialog->v[0]->maximum(2.);
    if(CTX::instance()->inputScrolling) dialog->v[0]->step(1. / 30.);
    dialog->v[0]->precision(3);
    dialog->v[0]->align(FL_ALIGN_RIGHT);

    dialog->v[1] = new Fl_Value_Input(WB, y, ww2, BH, "Steps between frames");
    dialog->v[1]->tooltip("PostProcessing.AnimationStep");
    y += BH;
    dialog->v[1]->minimum(1);
    dialog->v[1]->maximum(100);
    if(CTX::instance()->inputScrolling) dialog->v[1]->step(1);
    dialog->v[1]->align(FL_ALIGN_RIGHT);

    dialog->c[0] = new Fl_Check_Button(WB, y, ww, BH, "Print background");
    dialog->c[0]->tooltip("Print.Background");
    y += BH;
    dialog->c[0]->type(FL_TOGGLE_BUTTON);

    dialog->c[1] =
      new Fl_Check_Button(WB, y, ww, BH, "Composite all window tiles");
    dialog->c[1]->tooltip("Print.CompositeWindows");
    y += BH;
    dialog->c[1]->type(FL_TOGGLE_BUTTON);

    dialog->c[2] = new Fl_Check_Button(WB, y, ww, BH, "Delete temporary files");
    dialog->c[2]->tooltip("Print.DeleteTemporaryFiles");
    y += BH;
    dialog->c[2]->type(FL_TOGGLE_BUTTON);

    dialog->buttons = new Fl_Group(WB, y + WB, ww, BH);
    dialog->ok = new Fl_Return_Button(WB, y + WB, BB, BH, "OK");
    dialog->preview = new Fl_Button(2 * WB + BB, y + WB, BB, BH, "Preview");
    dialog->cancel = new Fl_Button(3 * WB + 2 * BB, y + WB, BB, BH, "Cancel");
    dialog->buttons->end();

    dialog->window->end();
    dialog->window->hotspot(dialog->window);
  }

  dialog->b[0]->value(opt_post_anim_cycle(0, GMSH_GET, 0) == 0);
  dialog->b[1]->value(opt_post_anim_cycle(0, GMSH_GET, 0) == 1);
  dialog->b[2]->value(opt_post_anim_cycle(0, GMSH_GET, 0) == 2);
  dialog->c[0]->value(opt_print_background(0, GMSH_GET, 0));
  dialog->c[1]->value(opt_print_composite_windows(0, GMSH_GET, 0));
  dialog->c[2]->value(opt_print_delete_tmp_files(0, GMSH_GET, 0));
  static char cmd[1024] = "";
  std::string s = opt_print_parameter_command(0, GMSH_GET, "");
  strncpy(cmd, s.c_str(), sizeof(cmd) - 1);
  cmd[sizeof(cmd) - 1] = '\0';
  dialog->p->value(cmd);
  if(dialog->b[2]->value())
    dialog->param->activate();
  else
    dialog->param->deactivate();
  dialog->v[0]->value(opt_post_anim_delay(0, GMSH_GET, 0));
  dialog->v[1]->value(opt_post_anim_step(0, GMSH_GET, 0));
  dialog->v[2]->value(opt_print_parameter_first(0, GMSH_GET, 0));
  dialog->v[3]->value(opt_print_parameter_last(0, GMSH_GET, 0));
  dialog->v[4]->value(opt_print_parameter_steps(0, GMSH_GET, 0));

  dialog->window->show();

  while(dialog->window->shown()) {
    Fl::wait();
    for(;;) {
      Fl_Widget *o = Fl::readqueue();
      if(!o) break;
      if(o == dialog->b[0] || o == dialog->b[1] || o == dialog->b[2]) {
        if(dialog->b[2]->value())
          dialog->param->activate();
        else
          dialog->param->deactivate();
      }
      if(o == dialog->ok || o == dialog->preview) {
        opt_post_anim_cycle(0, GMSH_SET | GMSH_GUI,
                            dialog->b[2]->value() ? 2 :
                            dialog->b[1]->value() ? 1 :
                                                    0);
        opt_post_anim_delay(0, GMSH_SET | GMSH_GUI, dialog->v[0]->value());
        opt_post_anim_step(0, GMSH_SET | GMSH_GUI, (int)dialog->v[1]->value());

        opt_print_parameter_command(0, GMSH_SET | GMSH_GUI, dialog->p->value());
        opt_print_parameter_first(0, GMSH_SET | GMSH_GUI,
                                  dialog->v[2]->value());
        opt_print_parameter_last(0, GMSH_SET | GMSH_GUI, dialog->v[3]->value());
        opt_print_parameter_steps(0, GMSH_SET | GMSH_GUI,
                                  dialog->v[4]->value());
        opt_print_background(0, GMSH_SET | GMSH_GUI,
                             (int)dialog->c[0]->value());
        opt_print_composite_windows(0, GMSH_SET | GMSH_GUI,
                                    (int)dialog->c[1]->value());
        opt_print_delete_tmp_files(0, GMSH_SET | GMSH_GUI,
                                   (int)dialog->c[2]->value());
        int format = (o == dialog->preview) ? FORMAT_MPEG_PREVIEW : FORMAT_MPEG;
        dialog->buttons->deactivate();
        CreateOutputFile(name, format, o == dialog->ok);
        dialog->buttons->activate();
        if(o == dialog->ok) {
          dialog->window->hide();
          return 1;
        }
      }
      if(o == dialog->window || o == dialog->cancel) {
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
  struct _gifFileDialog {
    Fl_Window *window;
    Fl_Check_Button *b[7];
    Fl_Button *ok, *cancel;
  };
  static _gifFileDialog *dialog = nullptr;

  if(!dialog) {
    dialog = new _gifFileDialog;
    int h = 3 * WB + 8 * BH, w = 2 * BB + 3 * WB, y = WB;
    dialog->window = new Fl_Double_Window(w, h, "GIF Options");
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->window->set_modal();
    dialog->b[0] = new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Dither");
    dialog->b[0]->tooltip("Print.GifDither");
    y += BH;
    dialog->b[1] = new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Interlace");
    dialog->b[1]->tooltip("Print.GifInterlace");
    y += BH;
    dialog->b[2] = new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Sort colormap");
    dialog->b[2]->tooltip("Print.GifSort");
    y += BH;
    dialog->b[3] =
      new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Transparent background");
    dialog->b[3]->tooltip("Print.Transparent");
    y += BH;
    dialog->b[4] =
      new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Print text strings");
    dialog->b[4]->tooltip("Print.Text");
    y += BH;
    dialog->b[5] =
      new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Print background");
    dialog->b[5]->tooltip("Print.Background");
    y += BH;
    dialog->b[6] =
      new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Composite all window tiles");
    dialog->b[6]->tooltip("Print.CompositeWindows");
    y += BH;
    for(int i = 0; i < 7; i++) { dialog->b[i]->type(FL_TOGGLE_BUTTON); }
    dialog->ok = new Fl_Return_Button(WB, y + WB, BB, BH, "OK");
    dialog->cancel = new Fl_Button(2 * WB + BB, y + WB, BB, BH, "Cancel");
    dialog->window->end();
    dialog->window->hotspot(dialog->window);
  }

  dialog->b[0]->value(opt_print_gif_dither(0, GMSH_GET, 0));
  dialog->b[1]->value(opt_print_gif_interlace(0, GMSH_GET, 0));
  dialog->b[2]->value(opt_print_gif_sort(0, GMSH_GET, 0));
  dialog->b[3]->value(opt_print_gif_transparent(0, GMSH_GET, 0));
  dialog->b[4]->value(opt_print_text(0, GMSH_GET, 0));
  dialog->b[5]->value(opt_print_background(0, GMSH_GET, 0));
  dialog->b[6]->value(opt_print_composite_windows(0, GMSH_GET, 0));
  dialog->window->show();

  while(dialog->window->shown()) {
    Fl::wait();
    for(;;) {
      Fl_Widget *o = Fl::readqueue();
      if(!o) break;
      if(o == dialog->ok) {
        opt_print_gif_dither(0, GMSH_SET | GMSH_GUI, dialog->b[0]->value());
        opt_print_gif_interlace(0, GMSH_SET | GMSH_GUI, dialog->b[1]->value());
        opt_print_gif_sort(0, GMSH_SET | GMSH_GUI, dialog->b[2]->value());
        opt_print_gif_transparent(0, GMSH_SET | GMSH_GUI,
                                  dialog->b[3]->value());
        opt_print_text(0, GMSH_SET | GMSH_GUI, dialog->b[4]->value());
        opt_print_background(0, GMSH_SET | GMSH_GUI, dialog->b[5]->value());
        opt_print_composite_windows(0, GMSH_SET | GMSH_GUI,
                                    dialog->b[6]->value());
        CreateOutputFile(name, FORMAT_GIF);
        dialog->window->hide();
        return 1;
      }
      if(o == dialog->window || o == dialog->cancel) {
        dialog->window->hide();
        return 0;
      }
    }
  }
  return 0;
}

// Save ps/eps/pdf dialog

static void activate_gl2ps_choices(int format, int quality,
                                   Fl_Check_Button *b[5])
{
#if defined(HAVE_LIBZ)
  b[0]->activate();
#else
  b[0]->deactivate();
#endif
  switch(quality) {
  case 0: // raster
    b[1]->deactivate();
    b[2]->deactivate();
    b[3]->deactivate();
    break;
  case 1: // simple sort
  case 3: // unsorted
    b[1]->activate();
    b[2]->deactivate();
    if(format == FORMAT_PS || format == FORMAT_EPS)
      b[3]->activate();
    else
      b[3]->deactivate();
    break;
  case 2: // bsp sort
    b[1]->activate();
    b[2]->activate();
    if(format == FORMAT_PS || format == FORMAT_EPS)
      b[3]->activate();
    else
      b[3]->deactivate();
    break;
  }
}

int gl2psFileDialog(const char *name, const char *title, int format)
{
  struct _gl2psFileDialog {
    Fl_Window *window;
    Fl_Check_Button *b[6];
    Fl_Choice *c;
    Fl_Button *ok, *cancel;
  };
  static _gl2psFileDialog *dialog = nullptr;

  static Fl_Menu_Item sortmenu[] = {
    {"Raster image", 0, nullptr, nullptr},
    {"Vector simple sort", 0, nullptr, nullptr},
    {"Vector accurate sort", 0, nullptr, nullptr},
    {"Vector unsorted", 0, nullptr, nullptr},
    {nullptr}};

  if(!dialog) {
    dialog = new _gl2psFileDialog;
    int h = 3 * WB + 8 * BH, w = 2 * BB + 3 * WB, y = WB;
    dialog->window = new Fl_Double_Window(w, h);
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->window->set_modal();
    dialog->c = new Fl_Choice(WB, y, BB + WB + BB / 2, BH, "Type");
    dialog->c->tooltip("Print.EpsQuality");
    y += BH;
    dialog->c->menu(sortmenu);
    dialog->c->align(FL_ALIGN_RIGHT);
    dialog->b[0] = new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Compress");
    dialog->b[0]->tooltip("EpsCompress");
    y += BH;
    dialog->b[1] =
      new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Remove hidden primitives");
    dialog->b[1]->tooltip("Print.EpsOcclusionCulling");
    y += BH;
    dialog->b[2] =
      new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Optimize BSP tree");
    dialog->b[2]->tooltip("Print.EpsBestRoot");
    y += BH;
    dialog->b[3] =
      new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Use level 3 shading");
    dialog->b[3]->tooltip("Print.EpsPS3Shading");
    y += BH;
    dialog->b[4] =
      new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Print text strings");
    dialog->b[4]->tooltip("Print.Text");
    y += BH;
    dialog->b[5] =
      new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Print background");
    dialog->b[5]->tooltip("Print.Background");
    y += BH;
    for(int i = 0; i < 6; i++) { dialog->b[i]->type(FL_TOGGLE_BUTTON); }
    dialog->ok = new Fl_Return_Button(WB, y + WB, BB, BH, "OK");
    dialog->cancel = new Fl_Button(2 * WB + BB, y + WB, BB, BH, "Cancel");
    dialog->window->end();
    dialog->window->hotspot(dialog->window);
  }

  dialog->window->label(title);
  dialog->c->value(opt_print_eps_quality(0, GMSH_GET, 0));
  dialog->b[0]->value(opt_print_eps_compress(0, GMSH_GET, 0));
  dialog->b[1]->value(opt_print_eps_occlusion_culling(0, GMSH_GET, 0));
  dialog->b[2]->value(opt_print_eps_best_root(0, GMSH_GET, 0));
  dialog->b[3]->value(opt_print_eps_ps3shading(0, GMSH_GET, 0));
  dialog->b[4]->value(opt_print_text(0, GMSH_GET, 0));
  dialog->b[5]->value(opt_print_background(0, GMSH_GET, 0));

  activate_gl2ps_choices(format, opt_print_eps_quality(0, GMSH_GET, 0),
                         dialog->b);

  dialog->window->show();

  while(dialog->window->shown()) {
    Fl::wait();
    for(;;) {
      Fl_Widget *o = Fl::readqueue();
      if(!o) break;

      if(o == dialog->c) {
        activate_gl2ps_choices(format, dialog->c->value(), dialog->b);
      }
      if(o == dialog->ok) {
        opt_print_eps_quality(0, GMSH_SET | GMSH_GUI, dialog->c->value());
        opt_print_eps_compress(0, GMSH_SET | GMSH_GUI, dialog->b[0]->value());
        opt_print_eps_occlusion_culling(0, GMSH_SET | GMSH_GUI,
                                        dialog->b[1]->value());
        opt_print_eps_best_root(0, GMSH_SET | GMSH_GUI, dialog->b[2]->value());
        opt_print_eps_ps3shading(0, GMSH_SET | GMSH_GUI, dialog->b[3]->value());
        opt_print_text(0, GMSH_SET | GMSH_GUI, dialog->b[4]->value());
        opt_print_background(0, GMSH_SET | GMSH_GUI, dialog->b[5]->value());
        CreateOutputFile(name, format);
        dialog->window->hide();
        return 1;
      }
      if(o == dialog->window || o == dialog->cancel) {
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
  struct _optionsFileDialog {
    Fl_Window *window;
    Fl_Check_Button *b[2];
    Fl_Button *ok, *cancel;
  };
  static _optionsFileDialog *dialog = nullptr;

  if(!dialog) {
    dialog = new _optionsFileDialog;
    int h = 3 * WB + 3 * BH, w = 2 * BB + 3 * WB, y = WB;
    dialog->window = new Fl_Double_Window(w, h, "Options");
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->window->set_modal();
    dialog->b[0] =
      new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Save only modified options");
    y += BH;
    dialog->b[0]->value(1);
    dialog->b[0]->type(FL_TOGGLE_BUTTON);
    dialog->b[1] =
      new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Print help strings");
    y += BH;
    dialog->b[1]->value(0);
    dialog->b[1]->type(FL_TOGGLE_BUTTON);
    dialog->ok = new Fl_Return_Button(WB, y + WB, BB, BH, "OK");
    dialog->cancel = new Fl_Button(2 * WB + BB, y + WB, BB, BH, "Cancel");
    dialog->window->end();
    dialog->window->hotspot(dialog->window);
  }

  dialog->window->show();

  while(dialog->window->shown()) {
    Fl::wait();
    for(;;) {
      Fl_Widget *o = Fl::readqueue();
      if(!o) break;
      if(o == dialog->ok) {
        Msg::StatusBar(true, "Writing '%s'...", name);
        PrintOptions(0, GMSH_FULLRC, dialog->b[0]->value(),
                     dialog->b[1]->value(), name);
        Msg::StatusBar(true, "Done writing '%s'", name);
        dialog->window->hide();
        return 1;
      }
      if(o == dialog->window || o == dialog->cancel) {
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
  struct _geoFileDialog {
    Fl_Window *window;
    Fl_Check_Button *b[2];
    Fl_Button *ok, *cancel;
  };
  static _geoFileDialog *dialog = nullptr;

  if(!dialog) {
    dialog = new _geoFileDialog;
    int h = 3 * WB + 3 * BH, w = 2 * BB + 3 * WB, y = WB;
    dialog->window = new Fl_Double_Window(w, h, "GEO Options");
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->window->set_modal();
    dialog->b[0] =
      new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Save physical group labels");
    dialog->b[0]->tooltip("Print.GeoLabels");
    y += BH;
    dialog->b[0]->type(FL_TOGGLE_BUTTON);
    dialog->b[1] = new Fl_Check_Button(WB, y, 2 * BB + WB, BH,
                                       "Only save physical entities");
    dialog->b[1]->tooltip("Print.GeoOnlyPhysicals");
    y += BH;
    dialog->b[1]->type(FL_TOGGLE_BUTTON);
    dialog->ok = new Fl_Return_Button(WB, y + WB, BB, BH, "OK");
    dialog->cancel = new Fl_Button(2 * WB + BB, y + WB, BB, BH, "Cancel");
    dialog->window->end();
    dialog->window->hotspot(dialog->window);
  }

  dialog->b[0]->value(opt_print_geo_labels(0, GMSH_GET, 0));
  dialog->b[1]->value(opt_print_geo_only_physicals(0, GMSH_GET, 0));
  dialog->window->show();

  while(dialog->window->shown()) {
    Fl::wait();
    for(;;) {
      Fl_Widget *o = Fl::readqueue();
      if(!o) break;
      if(o == dialog->ok) {
        opt_print_geo_labels(0, GMSH_SET | GMSH_GUI,
                             dialog->b[0]->value() ? 1 : 0);
        opt_print_geo_only_physicals(0, GMSH_SET | GMSH_GUI,
                                     dialog->b[1]->value() ? 1 : 0);
        CreateOutputFile(name, FORMAT_GEO);
        dialog->window->hide();
        return 1;
      }
      if(o == dialog->window || o == dialog->cancel) {
        dialog->window->hide();
        return 0;
      }
    }
  }
  return 0;
}

int meshStatFileDialog(const char *name)
{
  struct _meshStatFileDialog {
    Fl_Window *window;
    Fl_Check_Button *b[8];
    Fl_Button *ok, *cancel;
  };
  static _meshStatFileDialog *dialog = nullptr;

  int BBB = BB + 9; // labels too long

  if(!dialog) {
    dialog = new _meshStatFileDialog;
    int h = 3 * WB + 9 * BH, w = 2 * BBB + 3 * WB, y = WB;
    dialog->window = new Fl_Double_Window(w, h, "POS Options");
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->window->set_modal();
    dialog->b[0] =
      new Fl_Check_Button(WB, y, 2 * BBB + WB, BH, "Save all elements");
    dialog->b[0]->tooltip("Mesh.SaveAll");
    y += BH;
    dialog->b[1] =
      new Fl_Check_Button(WB, y, 2 * BBB + WB, BH, "Print elementary tags");
    dialog->b[1]->tooltip("Print.PostElementary");
    y += BH;
    dialog->b[2] =
      new Fl_Check_Button(WB, y, 2 * BBB + WB, BH, "Print element numbers");
    dialog->b[2]->tooltip("Print.PostElement");
    y += BH;
    dialog->b[3] = new Fl_Check_Button(WB, y, 2 * BBB + WB, BH,
                                       "Print SICN quality measure");
    dialog->b[3]->tooltip("Print.PostSICN");
    y += BH;
    dialog->b[4] = new Fl_Check_Button(WB, y, 2 * BBB + WB, BH,
                                       "Print SIGE quality measure");
    dialog->b[4]->tooltip("Print.PostSIGE");
    y += BH;
    dialog->b[5] = new Fl_Check_Button(WB, y, 2 * BBB + WB, BH,
                                       "Print Gamma quality measure");
    dialog->b[5]->tooltip("Print.PostGamma");
    y += BH;
    dialog->b[6] =
      new Fl_Check_Button(WB, y, 2 * BBB + WB, BH, "Print Eta quality measure");
    dialog->b[6]->tooltip("Print.PostEta");
    y += BH;
    dialog->b[7] = new Fl_Check_Button(WB, y, 2 * BBB + WB, BH,
                                       "Print Disto quality measure");
    dialog->b[7]->tooltip("Print.PostDisto");
    y += BH;
    for(int i = 0; i < 6; i++) dialog->b[i]->type(FL_TOGGLE_BUTTON);
    dialog->ok = new Fl_Return_Button(WB, y + WB, BBB, BH, "OK");
    dialog->cancel = new Fl_Button(2 * WB + BBB, y + WB, BBB, BH, "Cancel");
    dialog->window->end();
    dialog->window->hotspot(dialog->window);
  }

  dialog->b[0]->value(opt_mesh_save_all(0, GMSH_GET, 0));
  dialog->b[1]->value(opt_print_pos_elementary(0, GMSH_GET, 0));
  dialog->b[2]->value(opt_print_pos_element(0, GMSH_GET, 0));
  dialog->b[3]->value(opt_print_pos_SICN(0, GMSH_GET, 0));
  dialog->b[4]->value(opt_print_pos_SIGE(0, GMSH_GET, 0));
  dialog->b[5]->value(opt_print_pos_gamma(0, GMSH_GET, 0));
  dialog->b[6]->value(opt_print_pos_eta(0, GMSH_GET, 0));
  dialog->b[7]->value(opt_print_pos_disto(0, GMSH_GET, 0));
  dialog->window->show();

  while(dialog->window->shown()) {
    Fl::wait();
    for(;;) {
      Fl_Widget *o = Fl::readqueue();
      if(!o) break;
      if(o == dialog->ok) {
        opt_mesh_save_all(0, GMSH_SET | GMSH_GUI,
                          dialog->b[0]->value() ? 1 : 0);
        opt_print_pos_elementary(0, GMSH_SET | GMSH_GUI,
                                 dialog->b[1]->value() ? 1 : 0);
        opt_print_pos_element(0, GMSH_SET | GMSH_GUI,
                              dialog->b[2]->value() ? 1 : 0);
        opt_print_pos_SICN(0, GMSH_SET | GMSH_GUI,
                           dialog->b[3]->value() ? 1 : 0);
        opt_print_pos_SIGE(0, GMSH_SET | GMSH_GUI,
                           dialog->b[4]->value() ? 1 : 0);
        opt_print_pos_gamma(0, GMSH_SET | GMSH_GUI,
                            dialog->b[5]->value() ? 1 : 0);
        opt_print_pos_eta(0, GMSH_SET | GMSH_GUI,
                          dialog->b[6]->value() ? 1 : 0);
        opt_print_pos_disto(0, GMSH_SET | GMSH_GUI,
                            dialog->b[7]->value() ? 1 : 0);
        CreateOutputFile(name, FORMAT_POS);
        dialog->window->hide();
        return 1;
      }
      if(o == dialog->window || o == dialog->cancel) {
        dialog->window->hide();
        return 0;
      }
    }
  }
  return 0;
}

// Save msh dialog
struct _mshFileDialog {
  Fl_Window *window;
  Fl_Check_Button *b[4];
  Fl_Choice *c;
  Fl_Button *ok, *cancel;
};

int mshFileDialog(const char *name)
{
  static _mshFileDialog *dialog = nullptr;

  static Fl_Menu_Item formatmenu[] = {{"Version 1", 0, nullptr, nullptr},
                                      {"Version 2 ASCII", 0, nullptr, nullptr},
                                      {"Version 2 Binary", 0, nullptr, nullptr},
                                      {"Version 4 ASCII", 0, nullptr, nullptr},
                                      {"Version 4 Binary", 0, nullptr, nullptr},
                                      {nullptr}};

  int BBB = BB + 9; // labels too long

  if(!dialog) {
    dialog = new _mshFileDialog;
    int h = 3 * WB + 6 * BH, w = 2 * BBB + 3 * WB, y = WB;
    dialog->window = new Fl_Double_Window(w, h, "MSH Options");
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->window->set_modal();
    dialog->c = new Fl_Choice(WB, y, BBB + BBB / 2, BH, "Format");
    dialog->c->tooltip("Mesh.MshFileVersion, Mesh.Binary");
    y += BH;
    dialog->c->menu(formatmenu);
    dialog->c->align(FL_ALIGN_RIGHT);
    dialog->c->callback((Fl_Callback *)format_cb, dialog);
    dialog->b[0] =
      new Fl_Check_Button(WB, y, 2 * BBB + WB, BH, "Save all elements");
    dialog->b[0]->tooltip("Mesh.SaveAll");
    y += BH;
    dialog->b[0]->type(FL_TOGGLE_BUTTON);
    dialog->b[1] = new Fl_Check_Button(WB, y, 2 * BBB + WB, BH,
                                       "Save parametric coordinates");
    dialog->b[1]->tooltip("Mesh.SaveParametric");
    y += BH;
    dialog->b[1]->type(FL_TOGGLE_BUTTON);
    dialog->b[2] = new Fl_Check_Button(WB, y, 2 * BBB + WB, BH,
                                       "Save one file per partition");
    dialog->b[2]->tooltip("Mesh.PartitionSplitMeshFiles");
    y += BH;
    dialog->b[2]->type(FL_TOGGLE_BUTTON);
    dialog->b[3] = new Fl_Check_Button(WB, y, 2 * BBB + WB, BH,
                                       "Save partition topology file");
    dialog->b[3]->tooltip("Mesh.PartitionTopologyFile");
    y += BH;
    dialog->b[3]->type(FL_TOGGLE_BUTTON);

    dialog->ok = new Fl_Return_Button(WB, y + WB, BBB, BH, "OK");
    dialog->cancel = new Fl_Button(2 * WB + BBB, y + WB, BBB, BH, "Cancel");
    dialog->window->end();
    dialog->window->hotspot(dialog->window);
  }

  if(opt_mesh_msh_file_version(0, GMSH_GET, 0) == 1.0)
    dialog->c->value(0);
  else if(opt_mesh_msh_file_version(0, GMSH_GET, 0) < 4.0)
    dialog->c->value(!opt_mesh_binary(0, GMSH_GET, 0) ? 1 : 2);
  else
    dialog->c->value(!opt_mesh_binary(0, GMSH_GET, 0) ? 3 : 4);
  dialog->b[0]->value(opt_mesh_save_all(0, GMSH_GET, 0) ? 1 : 0);
  dialog->b[1]->value(opt_mesh_save_parametric(0, GMSH_GET, 0) ? 1 : 0);
  dialog->b[2]->value(opt_mesh_partition_split_mesh_files(0, GMSH_GET, 0) ? 1 :
                                                                            0);
  dialog->b[3]->value(
    opt_mesh_partition_save_topology_file(0, GMSH_GET, 0) ? 1 : 0);
  if(GModel::current()->getNumPartitions() == 0) {
    dialog->b[2]->deactivate();
    dialog->b[3]->deactivate();
  }
  dialog->window->show();

  while(dialog->window->shown()) {
    Fl::wait();
    for(;;) {
      Fl_Widget *o = Fl::readqueue();
      if(!o) break;
      if(o == dialog->ok) {
        opt_mesh_msh_file_version(
          0, GMSH_SET | GMSH_GUI,
          (dialog->c->value() == 0)                            ? 1.0 :
          (dialog->c->value() == 1 || dialog->c->value() == 2) ? 2.2 :
                                                                 4.1);
        opt_mesh_binary(
          0, GMSH_SET | GMSH_GUI,
          (dialog->c->value() == 2 || dialog->c->value() == 4) ? 1 : 0);
        opt_mesh_save_all(0, GMSH_SET | GMSH_GUI,
                          dialog->b[0]->value() ? 1 : 0);
        opt_mesh_save_parametric(0, GMSH_SET | GMSH_GUI,
                                 dialog->b[1]->value() ? 1 : 0);
        opt_mesh_partition_split_mesh_files(0, GMSH_SET | GMSH_GUI,
                                            dialog->b[2]->value() ? 1 : 0);
        opt_mesh_partition_save_topology_file(0, GMSH_SET | GMSH_GUI,
                                              dialog->b[3]->value() ? 1 : 0);
        CreateOutputFile(name, FORMAT_MSH);
        dialog->window->hide();
        return 1;
      }
      if(o == dialog->window || o == dialog->cancel) {
        dialog->window->hide();
        return 0;
      }
    }
  }
  return 0;
}

void format_cb(Fl_Widget *widget, void *data)
{
  _mshFileDialog *dialog = static_cast<_mshFileDialog *>(data);
  if((dialog->c->value() == 3 || dialog->c->value() == 4 ||
      dialog->c->value() == 1 || dialog->c->value() == 2) &&
     GModel::current()->getNumPartitions() > 0) {
    dialog->b[2]->activate();
    dialog->b[3]->activate();
  }
  else {
    dialog->b[2]->deactivate();
    dialog->b[3]->deactivate();
  }
}

// unv/inp mesh dialog

int unvinpFileDialog(const char *name, const char *title, int format)
{
  struct _unvFileDialog {
    Fl_Window *window;
    Fl_Check_Button *b[2];
    Fl_Button *ok, *cancel;
  };
  static _unvFileDialog *dialog = nullptr;

  int BBB = BB + 9; // labels too long

  if(!dialog) {
    dialog = new _unvFileDialog;
    int h = 3 * WB + 3 * BH, w = 2 * BBB + 3 * WB, y = WB;
    dialog->window = new Fl_Double_Window(w, h, title);
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->window->set_modal();
    dialog->b[0] =
      new Fl_Check_Button(WB, y, 2 * BBB + WB, BH, "Save all elements");
    dialog->b[0]->tooltip("Mesh.SaveAll");
    y += BH;
    dialog->b[0]->type(FL_TOGGLE_BUTTON);
    dialog->b[1] =
      new Fl_Check_Button(WB, y, 2 * BBB + WB, BH, "Save groups of nodes");
    dialog->b[1]->tooltip("Mesh.SaveGroupsOfNodes");
    y += BH;
    dialog->b[1]->type(FL_TOGGLE_BUTTON);
    dialog->ok = new Fl_Return_Button(WB, y + WB, BBB, BH, "OK");
    dialog->cancel = new Fl_Button(2 * WB + BBB, y + WB, BBB, BH, "Cancel");
    dialog->window->end();
    dialog->window->hotspot(dialog->window);
  }

  dialog->b[0]->value(opt_mesh_save_all(0, GMSH_GET, 0) ? 1 : 0);
  dialog->b[1]->value(opt_mesh_save_groups_of_nodes(0, GMSH_GET, 0) ? 1 : 0);
  dialog->window->show();

  while(dialog->window->shown()) {
    Fl::wait();
    for(;;) {
      Fl_Widget *o = Fl::readqueue();
      if(!o) break;
      if(o == dialog->ok) {
        opt_mesh_save_all(0, GMSH_SET | GMSH_GUI,
                          dialog->b[0]->value() ? 1 : 0);
        opt_mesh_save_groups_of_nodes(0, GMSH_SET | GMSH_GUI,
                                      dialog->b[1]->value() ? 1 : 0);
        CreateOutputFile(name, format);
        dialog->window->hide();
        return 1;
      }
      if(o == dialog->window || o == dialog->cancel) {
        dialog->window->hide();
        return 0;
      }
    }
  }
  return 0;
}

// key mesh dialog

int keyFileDialog(const char *name, const char *title, int format)
{
  struct _keyFileDialog {
    Fl_Window *window;
    Fl_Choice *c[3];
    Fl_Check_Button *b[2];
    Fl_Button *ok, *cancel;
  };
  static _keyFileDialog *dialog = nullptr;

  static Fl_Menu_Item beammenu[] = {{"Physical groups", 0, nullptr, nullptr},
                                    {"Save all", 0, nullptr, nullptr},
                                    {"Ignore", 0, nullptr, nullptr},
                                    {nullptr}};

  static Fl_Menu_Item shellmenu[] = {{"Physical groups", 0, nullptr, nullptr},
                                     {"Save all", 0, nullptr, nullptr},
                                     {"Ignore", 0, nullptr, nullptr},
                                     {nullptr}};

  static Fl_Menu_Item solidmenu[] = {{"Physical groups", 0, nullptr, nullptr},
                                     {"Save all", 0, nullptr, nullptr},
                                     {"Ignore", 0, nullptr, nullptr},
                                     {nullptr}};

  int BBB = BB + 16; // labels too long

  if(!dialog) {
    dialog = new _keyFileDialog;
    int h = 3 * WB + 6 * BH, w = 2 * BBB + 3 * WB, y = WB;
    dialog->window = new Fl_Double_Window(w, h, title);
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->window->set_modal();
    dialog->c[0] = new Fl_Choice(WB, y, BBB + BBB / 4, BH, "Line");
    y += BH;
    dialog->c[0]->menu(beammenu);
    dialog->c[0]->align(FL_ALIGN_RIGHT);
    dialog->c[1] = new Fl_Choice(WB, y, BBB + BBB / 4, BH, "Surface");
    y += BH;
    dialog->c[1]->menu(shellmenu);
    dialog->c[1]->align(FL_ALIGN_RIGHT);
    dialog->c[2] = new Fl_Choice(WB, y, BBB + BBB / 4, BH, "Volume");
    y += BH;
    dialog->c[2]->menu(solidmenu);
    dialog->c[2]->align(FL_ALIGN_RIGHT);
    dialog->b[0] =
      new Fl_Check_Button(WB, y, 2 * BBB + WB, BH, "Save groups of elements");
    dialog->b[0]->tooltip("Mesh.SaveAll");
    y += BH;
    dialog->b[0]->type(FL_TOGGLE_BUTTON);
    dialog->b[1] =
      new Fl_Check_Button(WB, y, 2 * BBB + WB, BH, "Save groups of nodes");
    dialog->b[1]->tooltip("Mesh.SaveGroupsOfNodes");
    y += BH;
    dialog->b[1]->type(FL_TOGGLE_BUTTON);
    dialog->ok = new Fl_Return_Button(WB, y + WB, BBB, BH, "OK");
    dialog->cancel = new Fl_Button(2 * WB + BBB, y + WB, BBB, BH, "Cancel");
    dialog->window->end();
    dialog->window->hotspot(dialog->window);
  }

  dialog->c[0]->value(((int)opt_mesh_save_all(0, GMSH_GET, 0) & 4) ? 1 :
                      ((int)opt_mesh_save_all(0, GMSH_GET, 0) & 8) ? 2 :
                                                                     0);
  dialog->c[1]->value(((int)opt_mesh_save_all(0, GMSH_GET, 0) & 16) ? 1 :
                      ((int)opt_mesh_save_all(0, GMSH_GET, 0) & 32) ? 2 :
                                                                      0);
  dialog->c[2]->value(((int)opt_mesh_save_all(0, GMSH_GET, 0) & 64)  ? 1 :
                      ((int)opt_mesh_save_all(0, GMSH_GET, 0) & 128) ? 2 :
                                                                       0);
  dialog->b[0]->value(
    (int)opt_mesh_save_groups_of_nodes(0, GMSH_GET, 0) & 2 ? 1 : 0);
  dialog->b[1]->value(
    (int)opt_mesh_save_groups_of_nodes(0, GMSH_GET, 0) & 1 ? 1 : 0);
  dialog->window->show();

  while(dialog->window->shown()) {
    Fl::wait();
    for(;;) {
      Fl_Widget *o = Fl::readqueue();
      if(!o) break;
      if(o == dialog->ok) {
        opt_mesh_save_all(0, GMSH_SET | GMSH_GUI,
                          dialog->c[0]->value() * 4 +
                            dialog->c[1]->value() * 16 +
                            dialog->c[2]->value() * 64);
        opt_mesh_save_groups_of_nodes(0, GMSH_SET | GMSH_GUI,
                                      (dialog->b[0]->value() ? 2 : 0) +
                                        (dialog->b[1]->value() ? 1 : 0));
        CreateOutputFile(name, format);
        dialog->window->hide();
        return 1;
      }
      if(o == dialog->window || o == dialog->cancel) {
        dialog->window->hide();
        return 0;
      }
    }
  }
  return 0;
}

// rad mesh dialog

int radFileDialog(const char *name, const char *title, int format)
{
  struct _radFileDialog {
    Fl_Window *window;
    Fl_Choice *c[3];
    Fl_Check_Button *b[2];
    Fl_Button *ok, *cancel;
  };
  static _radFileDialog *dialog = nullptr;

  static Fl_Menu_Item beammenu[] = {{"Physical groups", 0, nullptr, nullptr},
                                    {"Save all", 0, nullptr, nullptr},
                                    {"Ignore", 0, nullptr, nullptr},
                                    {nullptr}};

  static Fl_Menu_Item shellmenu[] = {{"Physical groups", 0, nullptr, nullptr},
                                     {"Save all", 0, nullptr, nullptr},
                                     {"Ignore", 0, nullptr, nullptr},
                                     {nullptr}};

  static Fl_Menu_Item solidmenu[] = {{"Physical groups", 0, nullptr, nullptr},
                                     {"Save all", 0, nullptr, nullptr},
                                     {"Ignore", 0, nullptr, nullptr},
                                     {nullptr}};

  int BBB = BB + 16; // labels too long

  if(!dialog) {
    dialog = new _radFileDialog;
    int h = 3 * WB + 6 * BH, w = 2 * BBB + 3 * WB, y = WB;
    dialog->window = new Fl_Double_Window(w, h, title);
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->window->set_modal();
    dialog->c[0] = new Fl_Choice(WB, y, BBB + BBB / 4, BH, "Line");
    y += BH;
    dialog->c[0]->menu(beammenu);
    dialog->c[0]->align(FL_ALIGN_RIGHT);
    dialog->c[1] = new Fl_Choice(WB, y, BBB + BBB / 4, BH, "Surface");
    y += BH;
    dialog->c[1]->menu(shellmenu);
    dialog->c[1]->align(FL_ALIGN_RIGHT);
    dialog->c[2] = new Fl_Choice(WB, y, BBB + BBB / 4, BH, "Volume");
    y += BH;
    dialog->c[2]->menu(solidmenu);
    dialog->c[2]->align(FL_ALIGN_RIGHT);
    dialog->b[0] =
      new Fl_Check_Button(WB, y, 2 * BBB + WB, BH, "Save groups of elements");
    dialog->b[0]->tooltip("Mesh.SaveAll");
    y += BH;
    dialog->b[0]->type(FL_TOGGLE_BUTTON);
    dialog->b[1] =
      new Fl_Check_Button(WB, y, 2 * BBB + WB, BH, "Save groups of nodes");
    dialog->b[1]->tooltip("Mesh.SaveGroupsOfNodes");
    y += BH;
    dialog->b[1]->type(FL_TOGGLE_BUTTON);
    dialog->ok = new Fl_Return_Button(WB, y + WB, BBB, BH, "OK");
    dialog->cancel = new Fl_Button(2 * WB + BBB, y + WB, BBB, BH, "Cancel");
    dialog->window->end();
    dialog->window->hotspot(dialog->window);
  }

  dialog->c[0]->value(((int)opt_mesh_save_all(0, GMSH_GET, 0) & 4) ? 1 :
                      ((int)opt_mesh_save_all(0, GMSH_GET, 0) & 8) ? 2 :
                                                                     0);
  dialog->c[1]->value(((int)opt_mesh_save_all(0, GMSH_GET, 0) & 16) ? 1 :
                      ((int)opt_mesh_save_all(0, GMSH_GET, 0) & 32) ? 2 :
                                                                      0);
  dialog->c[2]->value(((int)opt_mesh_save_all(0, GMSH_GET, 0) & 64)  ? 1 :
                      ((int)opt_mesh_save_all(0, GMSH_GET, 0) & 128) ? 2 :
                                                                       0);
  dialog->b[0]->value(
    (int)opt_mesh_save_groups_of_nodes(0, GMSH_GET, 0) & 2 ? 1 : 0);
  dialog->b[1]->value(
    (int)opt_mesh_save_groups_of_nodes(0, GMSH_GET, 0) & 1 ? 1 : 0);
  dialog->window->show();

  while(dialog->window->shown()) {
    Fl::wait();
    for(;;) {
      Fl_Widget *o = Fl::readqueue();
      if(!o) break;
      if(o == dialog->ok) {
        opt_mesh_save_all(0, GMSH_SET | GMSH_GUI,
                          dialog->c[0]->value() * 4 +
                            dialog->c[1]->value() * 16 +
                            dialog->c[2]->value() * 64);
        opt_mesh_save_groups_of_nodes(0, GMSH_SET | GMSH_GUI,
                                      (dialog->b[0]->value() ? 2 : 0) +
                                        (dialog->b[1]->value() ? 1 : 0));
        CreateOutputFile(name, format);
        dialog->window->hide();
        return 1;
      }
      if(o == dialog->window || o == dialog->cancel) {
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
  struct _bdfFileDialog {
    Fl_Window *window;
    Fl_Choice *c, *d;
    Fl_Check_Button *b;
    Fl_Button *ok, *cancel;
  };
  static _bdfFileDialog *dialog = nullptr;

  static Fl_Menu_Item formatmenu[] = {{"Free field", 0, nullptr, nullptr},
                                      {"Small field", 0, nullptr, nullptr},
                                      {"Long field", 0, nullptr, nullptr},
                                      {nullptr}};

  static Fl_Menu_Item tagmenu[] = {{"Elementary entity", 0, nullptr, nullptr},
                                   {"Physical entity", 0, nullptr, nullptr},
                                   {"Partition", 0, nullptr, nullptr},
                                   {nullptr}};

  int BBB = BB + 16; // labels too long

  if(!dialog) {
    dialog = new _bdfFileDialog;
    int h = 3 * WB + 4 * BH, w = 2 * BBB + 3 * WB, y = WB;
    dialog->window = new Fl_Double_Window(w, h, "BDF Options");
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->window->set_modal();
    dialog->c = new Fl_Choice(WB, y, BBB + BBB / 4, BH, "Format");
    dialog->c->tooltip("Mesh.BdfFieldFormat");
    y += BH;
    dialog->c->menu(formatmenu);
    dialog->c->align(FL_ALIGN_RIGHT);
    dialog->d = new Fl_Choice(WB, y, BBB + BBB / 4, BH, "Element tag");
    dialog->d->tooltip("Mesh.SaveElementTagType");
    y += BH;
    dialog->d->menu(tagmenu);
    dialog->d->align(FL_ALIGN_RIGHT);
    dialog->b =
      new Fl_Check_Button(WB, y, 2 * BBB + WB, BH, "Save all elements");
    dialog->b->tooltip("Mesh.SaveAll");
    y += BH;
    dialog->b->type(FL_TOGGLE_BUTTON);
    dialog->ok = new Fl_Return_Button(WB, y + WB, BBB, BH, "OK");
    dialog->cancel = new Fl_Button(2 * WB + BBB, y + WB, BBB, BH, "Cancel");
    dialog->window->end();
    dialog->window->hotspot(dialog->window);
  }

  dialog->c->value(opt_mesh_bdf_field_format(0, GMSH_GET, 0));
  dialog->d->value((opt_mesh_save_element_tag_type(0, GMSH_GET, 0) == 3) ? 2 :
                   (opt_mesh_save_element_tag_type(0, GMSH_GET, 0) == 2) ? 1 :
                                                                           0);
  dialog->b->value(opt_mesh_save_all(0, GMSH_GET, 0) ? 1 : 0);
  dialog->window->show();

  while(dialog->window->shown()) {
    Fl::wait();
    for(;;) {
      Fl_Widget *o = Fl::readqueue();
      if(!o) break;
      if(o == dialog->ok) {
        opt_mesh_bdf_field_format(0, GMSH_SET | GMSH_GUI, dialog->c->value());
        opt_mesh_save_element_tag_type(0, GMSH_SET | GMSH_GUI,
                                       dialog->d->value() + 1);
        opt_mesh_save_all(0, GMSH_SET | GMSH_GUI, dialog->b->value() ? 1 : 0);
        CreateOutputFile(name, FORMAT_BDF);
        dialog->window->hide();
        return 1;
      }
      if(o == dialog->window || o == dialog->cancel) {
        dialog->window->hide();
        return 0;
      }
    }
  }
  return 0;
}

// Generic mesh dialog

int stlFileDialog(const char *name)
{
  struct _stlFileDialog {
    Fl_Window *window;
    Fl_Choice *c[2];
    Fl_Check_Button *b;
    Fl_Button *ok, *cancel;
  };
  static _stlFileDialog *dialog = nullptr;

  static Fl_Menu_Item formatmenu[] = {
    {"ASCII", 0, nullptr, nullptr}, {"Binary", 0, nullptr, nullptr}, {nullptr}};
  static Fl_Menu_Item solidmenu[] = {
    {"Single", 0, nullptr, nullptr},
    {"Per surface", 0, nullptr, nullptr},
    {"Per physical surface", 0, nullptr, nullptr},
    {nullptr}};

  int BBB = BB + 9; // labels too long

  if(!dialog) {
    dialog = new _stlFileDialog;
    int h = 3 * WB + 4 * BH, w = 2 * BBB + 3 * WB, y = WB;
    dialog->window = new Fl_Double_Window(w, h, "STL Options");
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->window->set_modal();
    dialog->c[0] = new Fl_Choice(WB, y, BBB + BBB / 4, BH, "Format");
    dialog->c[0]->tooltip("Mesh.Binary");
    y += BH;
    dialog->c[0]->menu(formatmenu);
    dialog->c[0]->align(FL_ALIGN_RIGHT);
    dialog->b =
      new Fl_Check_Button(WB, y, 2 * BBB + WB, BH, "Save all elements");
    dialog->b->tooltip("Mesh.SaveAll");
    y += BH;
    dialog->b->type(FL_TOGGLE_BUTTON);
    dialog->c[1] = new Fl_Choice(WB, y, BBB + BBB / 4, BH, "Solid");
    dialog->c[1]->tooltip("Mesh.StlOneSolidPerSurface");
    y += BH;
    dialog->c[1]->menu(solidmenu);
    dialog->c[1]->align(FL_ALIGN_RIGHT);
    dialog->ok = new Fl_Return_Button(WB, y + WB, BBB, BH, "OK");
    dialog->cancel = new Fl_Button(2 * WB + BBB, y + WB, BBB, BH, "Cancel");
    dialog->window->end();
    dialog->window->hotspot(dialog->window);
  }

  dialog->c[0]->value(opt_mesh_binary(0, GMSH_GET, 0) ? 1 : 0);
  dialog->b->value(opt_mesh_save_all(0, GMSH_GET, 0) ? 1 : 0);
  dialog->c[1]->value(
    opt_mesh_stl_one_solid_per_surface(0, GMSH_GET, 0) == 2 ? 2 :
    opt_mesh_stl_one_solid_per_surface(0, GMSH_GET, 0) == 1 ? 1 :
                                                              0);

  if(dialog->c[1]->value() == 2)
    dialog->b->deactivate();
  else
    dialog->b->activate();

  dialog->window->show();

  while(dialog->window->shown()) {
    Fl::wait();
    for(;;) {
      Fl_Widget *o = Fl::readqueue();
      if(!o) break;
      if(o == dialog->c[1]) {
        if(dialog->c[1]->value() == 2)
          dialog->b->deactivate();
        else
          dialog->b->activate();
      }
      if(o == dialog->ok) {
        opt_mesh_binary(0, GMSH_SET | GMSH_GUI, dialog->c[0]->value());
        opt_mesh_save_all(0, GMSH_SET | GMSH_GUI, dialog->b->value() ? 1 : 0);
        opt_mesh_stl_one_solid_per_surface(0, GMSH_SET | GMSH_GUI,
                                           dialog->c[1]->value());
        CreateOutputFile(name, FORMAT_STL);
        dialog->window->hide();
        return 1;
      }
      if(o == dialog->window || o == dialog->cancel) {
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
  struct _genericMeshFileDialog {
    Fl_Window *window;
    Fl_Choice *c, *d;
    Fl_Check_Button *b;
    Fl_Button *ok, *cancel;
  };
  static _genericMeshFileDialog *dialog = nullptr;

  static Fl_Menu_Item formatmenu[] = {
    {"ASCII", 0, nullptr, nullptr}, {"Binary", 0, nullptr, nullptr}, {nullptr}};

  static Fl_Menu_Item tagmenu[] = {{"Elementary entity", 0, nullptr, nullptr},
                                   {"Physical entity", 0, nullptr, nullptr},
                                   {"Partition", 0, nullptr, nullptr},
                                   {nullptr}};

  int BBB = BB + 16; // labels too long

  if(!dialog) {
    dialog = new _genericMeshFileDialog;
    int h = 3 * WB + 4 * BH, w = 2 * BBB + 3 * WB, y = WB;
    dialog->window = new Fl_Double_Window(w, h);
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->window->set_modal();
    dialog->c = new Fl_Choice(WB, y, BBB + BBB / 4, BH, "Format");
    dialog->c->tooltip("Mesh.Binary");
    y += BH;
    dialog->c->menu(formatmenu);
    dialog->c->align(FL_ALIGN_RIGHT);
    dialog->d = new Fl_Choice(WB, y, BBB + BBB / 4, BH, "Element tag");
    dialog->d->tooltip("Mesh.SaveElementTagType");
    y += BH;
    dialog->d->menu(tagmenu);
    dialog->d->align(FL_ALIGN_RIGHT);
    dialog->b =
      new Fl_Check_Button(WB, y, 2 * BBB + WB, BH, "Save all elements");
    dialog->b->tooltip("Mesh.SaveAll");
    y += BH;
    dialog->b->type(FL_TOGGLE_BUTTON);
    dialog->ok = new Fl_Return_Button(WB, y + WB, BBB, BH, "OK");
    dialog->cancel = new Fl_Button(2 * WB + BBB, y + WB, BBB, BH, "Cancel");
    dialog->window->end();
    dialog->window->hotspot(dialog->window);
  }

  dialog->window->label(title);
  dialog->c->value(opt_mesh_binary(0, GMSH_GET, 0) ? 1 : 0);
  if(binary_support)
    dialog->c->activate();
  else
    dialog->c->deactivate();
  dialog->d->value((opt_mesh_save_element_tag_type(0, GMSH_GET, 0) == 3) ? 2 :
                   (opt_mesh_save_element_tag_type(0, GMSH_GET, 0) == 2) ? 1 :
                                                                           0);
  if(element_tag_support)
    dialog->d->activate();
  else
    dialog->d->deactivate();
  dialog->b->value(opt_mesh_save_all(0, GMSH_GET, 0) ? 1 : 0);
  dialog->window->show();

  while(dialog->window->shown()) {
    Fl::wait();
    for(;;) {
      Fl_Widget *o = Fl::readqueue();
      if(!o) break;
      if(o == dialog->ok) {
        opt_mesh_binary(0, GMSH_SET | GMSH_GUI, dialog->c->value());
        opt_mesh_save_element_tag_type(0, GMSH_SET | GMSH_GUI,
                                       dialog->d->value() + 1);
        opt_mesh_save_all(0, GMSH_SET | GMSH_GUI, dialog->b->value() ? 1 : 0);
        CreateOutputFile(name, format);
        dialog->window->hide();
        return 1;
      }
      if(o == dialog->window || o == dialog->cancel) {
        dialog->window->hide();
        return 0;
      }
    }
  }
  return 0;
}

// POS format post-processing export dialog

static void _saveViews(const std::string &name, int which, int format,
                       bool canAppend)
{
  if(PView::list.empty()) { Msg::Error("No views to save"); }
  else if(which == 0) {
    int iview = FlGui::instance()->options->view.index;
    if(iview < 0 || iview >= (int)PView::list.size()) {
      Msg::Info("No or invalid current view: saving View[0]");
      iview = 0;
    }
    PView::list[iview]->write(name, format);
  }
  else if(which == 1) {
    int numVisible = 0;
    for(std::size_t i = 0; i < PView::list.size(); i++)
      if(PView::list[i]->getOptions()->visible) numVisible++;
    if(!numVisible) { Msg::Error("No visible view"); }
    else {
      bool first = true;
      for(std::size_t i = 0; i < PView::list.size(); i++) {
        if(PView::list[i]->getOptions()->visible) {
          std::string fileName = name;
          if(!canAppend && numVisible > 1) {
            std::ostringstream os;
            os << "_" << i;
            fileName += os.str();
          }
          PView::list[i]->write(fileName, format, first ? false : canAppend);
          first = false;
        }
      }
    }
  }
  else {
    for(std::size_t i = 0; i < PView::list.size(); i++) {
      std::string fileName = name;
      if(!canAppend && PView::list.size() > 1) {
        std::ostringstream os;
        os << "_" << i;
        fileName += os.str();
      }
      PView::list[i]->write(fileName, format, i ? canAppend : false);
    }
  }
}

int posFileDialog(const char *name)
{
  struct _posFileDialog {
    Fl_Window *window;
    Fl_Choice *c[2];
    Fl_Button *ok, *cancel;
  };
  static _posFileDialog *dialog = nullptr;

  static Fl_Menu_Item viewmenu[] = {{"Current", 0, nullptr, nullptr},
                                    {"Visible", 0, nullptr, nullptr},
                                    {"All", 0, nullptr, nullptr},
                                    {nullptr}};
  static Fl_Menu_Item formatmenu[] = {{"Parsed", 0, nullptr, nullptr},
                                      {"Mesh-based", 0, nullptr, nullptr},
                                      {"Legacy ASCII", 0, nullptr, nullptr},
                                      {"Legacy Binary", 0, nullptr, nullptr},
                                      {nullptr}};

  int BBB = BB + 9; // labels too long

  if(!dialog) {
    dialog = new _posFileDialog;
    int h = 3 * WB + 3 * BH, w = 2 * BBB + 3 * WB, y = WB;
    dialog->window = new Fl_Double_Window(w, h, "POS Options");
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->window->set_modal();
    dialog->c[0] = new Fl_Choice(WB, y, BBB + BBB / 2, BH, "View(s)");
    y += BH;
    dialog->c[0]->menu(viewmenu);
    dialog->c[0]->align(FL_ALIGN_RIGHT);
    dialog->c[1] = new Fl_Choice(WB, y, BBB + BBB / 2, BH, "Format");
    y += BH;
    dialog->c[1]->menu(formatmenu);
    dialog->c[1]->align(FL_ALIGN_RIGHT);
    dialog->ok = new Fl_Return_Button(WB, y + WB, BBB, BH, "OK");
    dialog->cancel = new Fl_Button(2 * WB + BBB, y + WB, BBB, BH, "Cancel");
    dialog->window->end();
    dialog->window->hotspot(dialog->window);
  }

  dialog->window->show();

  while(dialog->window->shown()) {
    Fl::wait();
    for(;;) {
      Fl_Widget *o = Fl::readqueue();
      if(!o) break;
      if(o == dialog->ok) {
        int format = 2;
        switch(dialog->c[1]->value()) {
        case 0: format = 2; break;
        case 1: format = 5; break;
        case 2: format = 0; break;
        case 3: format = 1; break;
        }
        bool canAppend = (format == 2) ? true : false;
        _saveViews(name, dialog->c[0]->value(), format, canAppend);
        dialog->window->hide();
        return 1;
      }
      if(o == dialog->window || o == dialog->cancel) {
        dialog->window->hide();
        return 0;
      }
    }
  }
  return 0;
}

// FIXME: The way this is written makes it non scriptable. It would be much
// better to have options giverning the various parameters, and go through the
// standard file creation mechanism...

static void _saveAdaptedViews(const std::string &name, int useDefaultName,
                              int which, bool isBinary, int adaptLev,
                              double adaptErr, int npart, bool canAppend)
{
  if(PView::list.empty()) { Msg::Error("No views to save"); }
  else if(which == 0) {
    int iview = FlGui::instance()->options->view.index;
    if(iview < 0 || iview >= (int)PView::list.size()) {
      Msg::Info("No or invalid current view: saving View[0]");
      iview = 0;
    }
    PView::list[iview]->writeAdapt(name, useDefaultName, isBinary, adaptLev,
                                   adaptErr, npart);
  }
  else if(which == 1) {
    int numVisible = 0;
    for(std::size_t i = 0; i < PView::list.size(); i++)
      if(PView::list[i]->getOptions()->visible) numVisible++;
    if(!numVisible) { Msg::Error("No visible view"); }
    else {
      bool first = true;
      for(std::size_t i = 0; i < PView::list.size(); i++) {
        if(PView::list[i]->getOptions()->visible) {
          std::string fileName = name;
          if(!canAppend && numVisible > 1) {
            std::ostringstream os;
            os << "_" << i;
            fileName += os.str();
          }
          PView::list[i]->writeAdapt(fileName, useDefaultName, isBinary,
                                     adaptLev, adaptErr, npart,
                                     first ? false : canAppend);
          first = false;
        }
      }
    }
  }
  else {
    for(std::size_t i = 0; i < PView::list.size(); i++) {
      std::string fileName = name;
      if(!canAppend && PView::list.size() > 1) {
        std::ostringstream os;
        os << "_" << i;
        fileName += os.str();
      }
      PView::list[i]->writeAdapt(fileName, useDefaultName, isBinary, adaptLev,
                                 adaptErr, npart, i ? canAppend : false);
    }
  }
}

int pvtuAdaptFileDialog(const char *name)
{
  struct _pvtuAdaptFileDialog {
    Fl_Window *window;
    Fl_Choice *c[2];
    Fl_Button *ok, *cancel, *push[2];
    Fl_Value_Input *vi[3];
    Fl_Check_Button *defautName;
  };
  static _pvtuAdaptFileDialog *dialog = nullptr;

  static Fl_Menu_Item viewmenu[] = {{"Current", 0, nullptr, nullptr},
                                    {"Visible", 0, nullptr, nullptr},
                                    {"All", 0, nullptr, nullptr},
                                    {nullptr}};
  static Fl_Menu_Item formatmenu[] = {
    {"Binary", 0, nullptr, nullptr}, {"ASCII", 0, nullptr, nullptr}, {nullptr}};

  int BBB = BB + 9; // labels too long

  if(!dialog) {
    dialog = new _pvtuAdaptFileDialog;
    int h = 7 * BH + 3 * WB, w = 2 * BBB + 3 * WB, y = WB;
    dialog->window = new Fl_Double_Window(w, h, "Adaptive View Options");
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->window->set_modal();
    dialog->c[0] = new Fl_Choice(WB, y, BB, BH, "View(s)");
    y += BH;
    dialog->c[0]->menu(viewmenu);
    dialog->c[0]->align(FL_ALIGN_RIGHT);
    dialog->c[1] = new Fl_Choice(WB, y, BB, BH, "Format");
    y += BH;
    dialog->c[1]->menu(formatmenu);
    dialog->c[1]->align(FL_ALIGN_RIGHT);

    dialog->vi[0] = new Fl_Value_Input(WB, y, BB, BH, "Recursion level");
    y += BH;
    dialog->vi[0]->align(FL_ALIGN_RIGHT);
    dialog->vi[0]->minimum(0);
    dialog->vi[0]->maximum(6);
    if(CTX::instance()->inputScrolling) dialog->vi[0]->step(1);
    dialog->vi[0]->value(1);
    dialog->vi[0]->when(FL_WHEN_RELEASE);

    dialog->vi[1] = new Fl_Value_Input(WB, y, BB, BH, "Target error");
    y += BH;
    dialog->vi[1]->align(FL_ALIGN_RIGHT);
    dialog->vi[1]->minimum(-1.e-4);
    dialog->vi[1]->maximum(0.1);
    if(CTX::instance()->inputScrolling) dialog->vi[1]->step(1.e-4);
    dialog->vi[1]->value(-1.e-4);
    dialog->vi[1]->when(FL_WHEN_RELEASE);

    dialog->vi[2] = new Fl_Value_Input(WB, y, BB, BH, "Number of parts");
    y += BH;
    dialog->vi[2]->align(FL_ALIGN_RIGHT);
    dialog->vi[2]->minimum(1);
    dialog->vi[2]->maximum(262144);
    if(CTX::instance()->inputScrolling) dialog->vi[2]->step(1);
    dialog->vi[2]->value(4);
    dialog->vi[2]->when(FL_WHEN_RELEASE);

    dialog->defautName =
      new Fl_Check_Button(WB, y, w - 2 * WB, BH, "Use default filename");
    y += BH;
    dialog->defautName->value(1);

    dialog->ok = new Fl_Return_Button(WB, y + WB, BBB, BH, "OK");
    dialog->cancel = new Fl_Button(2 * WB + BBB, y + WB, BBB, BH, "Cancel");
    dialog->window->end();
    dialog->window->hotspot(dialog->window);
  }

  dialog->window->show();

  while(dialog->window->shown()) {
    Fl::wait();
    for(;;) {
      Fl_Widget *o = Fl::readqueue();
      if(!o) break;
      if(o == dialog->ok) {
        bool isBinary = true;
        switch(dialog->c[1]->value()) {
        case 0: isBinary = true; break;
        case 1: isBinary = false; break;
        }

        // Only one view can currently be saved at a time in a pvtu file set,
        // with a repetition of the topology structure.  Views/Fields can then
        // be appended in ParaView using the AppendAttributes filter bool
        // canAppend = (format == 2) ? true : false;

        int adaptLev = dialog->vi[0]->value();
        double adaptErr = dialog->vi[1]->value();
        int npart = dialog->vi[2]->value();
        int useDefaultName = dialog->defautName->value();
        bool canAppend =
          false; // Not yet implemented for VTK format here due to a tradeoff
                 // to limit memory consumption for high levels of adaptation
        _saveAdaptedViews(name, useDefaultName, dialog->c[0]->value(), isBinary,
                          adaptLev, adaptErr, npart, canAppend);
        dialog->window->hide();
        return 1;
      }
      if(o == dialog->window || o == dialog->cancel) {
        dialog->window->hide();
        return 0;
      }
    }
  }
  return 0;
}

int x3dViewFileDialog(const char *name, const char *title, int format)
{
  struct _viewFileDialog {
    Fl_Window *window;
    Fl_Choice *c;
    Fl_Value_Input *input[2];
    Fl_Check_Button *e[2];
    Fl_Button *ok, *cancel;
  };
  static _viewFileDialog *dialog = nullptr;

  static Fl_Menu_Item viewmenu[] = {{"Current", 0, nullptr, nullptr},
                                    {"Visible", 0, nullptr, nullptr},
                                    {"All", 0, nullptr, nullptr},
                                    {nullptr}};

  int BBB = BB + 9; // labels too long

  if(!dialog) {
    dialog = new _viewFileDialog;
    int h = 6 * BH + 3 * WB, w = 2 * BBB + 3 * WB, y = WB;
    dialog->window = new Fl_Double_Window(w, h);
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->window->set_modal();
    dialog->c = new Fl_Choice(WB, y, BBB + BBB / 2, BH, "View(s)");
    y += BH;
    dialog->c->menu(viewmenu);
    dialog->c->align(FL_ALIGN_RIGHT);
    dialog->e[0] =
      new Fl_Check_Button(WB, y, w - 2 * WB, BH, "Remove inner borders");
    dialog->e[0]->tooltip("Print.X3dRemoveInnerBorders");
    y += BH;
    dialog->e[0]->type(FL_TOGGLE_BUTTON);
    dialog->input[0] = new Fl_Value_Input(WB, y, BB, BH, "Log10(Precision)");
    dialog->input[0]->tooltip("Print.X3dPrecision");
    y += BH;
    dialog->input[0]->align(FL_ALIGN_RIGHT);
    dialog->input[0]->minimum(-16);
    dialog->input[0]->maximum(16);
    if(CTX::instance()->inputScrolling) dialog->input[0]->step(.25);
    dialog->input[1] = new Fl_Value_Input(WB, y, BB, BH, "Transparency");
    dialog->input[1]->tooltip("Print.X3dTransparency");
    y += BH;
    dialog->input[1]->align(FL_ALIGN_RIGHT);
    dialog->input[1]->minimum(0.);
    dialog->input[1]->maximum(1.);
    if(CTX::instance()->inputScrolling) dialog->input[1]->step(0.05);
    dialog->e[1] = new Fl_Check_Button(WB, y, w - 2 * WB, BH,
                                       "High compatibility (no scale)");
    dialog->e[1]->tooltip("Print.X3dCompatibility");
    y += BH;
    dialog->e[1]->type(FL_TOGGLE_BUTTON);
    dialog->ok = new Fl_Return_Button(WB, y + WB, BBB, BH, "OK");
    dialog->cancel = new Fl_Button(2 * WB + BBB, y + WB, BBB, BH, "Cancel");
    dialog->window->end();
    dialog->window->hotspot(dialog->window);
  }

  dialog->window->label(title);
  dialog->window->show();

  dialog->input[0]->value(log10(opt_print_x3d_precision(0, GMSH_GET, 0)));
  dialog->input[1]->value(opt_print_x3d_transparency(0, GMSH_GET, 0));
  dialog->e[0]->value(opt_print_x3d_remove_inner_borders(0, GMSH_GET, 0));
  dialog->e[1]->value(opt_print_x3d_compatibility(0, GMSH_GET, 0));

  while(dialog->window->shown()) {
    Fl::wait();
    for(;;) {
      Fl_Widget *o = Fl::readqueue();
      if(!o) break;
      if(o == dialog->ok) {
        opt_print_x3d_precision(0, GMSH_SET | GMSH_GUI,
                                pow(10., dialog->input[0]->value()));
        opt_print_x3d_transparency(0, GMSH_SET | GMSH_GUI,
                                   dialog->input[1]->value());
        opt_print_x3d_remove_inner_borders(0, GMSH_SET | GMSH_GUI,
                                           dialog->e[0]->value());
        opt_print_x3d_compatibility(0, GMSH_SET | GMSH_GUI,
                                    dialog->e[1]->value());
        _saveViews(name, dialog->c->value(), format, false);
        dialog->window->hide();
        return 1;
      }
      if(o == dialog->window || o == dialog->cancel) {
        dialog->window->hide();
        return 0;
      }
    }
  }
  return 0;
}

int genericViewFileDialog(const char *name, const char *title, int format)
{
  struct _viewFileDialog {
    Fl_Window *window;
    Fl_Choice *c[1];
    Fl_Button *ok, *cancel;
  };
  static _viewFileDialog *dialog = nullptr;

  static Fl_Menu_Item viewmenu[] = {{"Current", 0, nullptr, nullptr},
                                    {"Visible", 0, nullptr, nullptr},
                                    {"All", 0, nullptr, nullptr},
                                    {nullptr}};

  int BBB = BB + 9; // labels too long

  if(!dialog) {
    dialog = new _viewFileDialog;
    int h = 3 * WB + 2 * BH, w = 2 * BBB + 3 * WB, y = WB;
    dialog->window = new Fl_Double_Window(w, h);
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->window->set_modal();
    dialog->c[0] = new Fl_Choice(WB, y, BBB + BBB / 2, BH, "View(s)");
    y += BH;
    dialog->c[0]->menu(viewmenu);
    dialog->c[0]->align(FL_ALIGN_RIGHT);
    dialog->ok = new Fl_Return_Button(WB, y + WB, BBB, BH, "OK");
    dialog->cancel = new Fl_Button(2 * WB + BBB, y + WB, BBB, BH, "Cancel");
    dialog->window->end();
    dialog->window->hotspot(dialog->window);
  }

  dialog->window->label(title);
  dialog->window->show();

  while(dialog->window->shown()) {
    Fl::wait();
    for(;;) {
      Fl_Widget *o = Fl::readqueue();
      if(!o) break;
      if(o == dialog->ok) {
        _saveViews(name, dialog->c[0]->value(), format, false);
        dialog->window->hide();
        return 1;
      }
      if(o == dialog->window || o == dialog->cancel) {
        dialog->window->hide();
        return 0;
      }
    }
  }
  return 0;
}

int cgnsFileDialog(const char *filename)
{
  CreateOutputFile(filename, FORMAT_CGNS);
  return 1;
}
