// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Stephen Guzik
//   Sebastian Eiser

#include <functional>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Value_Slider.H>
#include <FL/Fl_Value_Input.H>
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
#include "extraDialogs.h"
#include "windowPlacement.h"
#include "CreateFile.h"
#include "Options.h"
#include "Context.h"
#include "GModel.h"
#include "PView.h"
#include "PViewOptions.h"

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
  Fl_Window *window() { return _win; }
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
    }
    if(fc->window())
      placeWindow(fc->window(), CTX::instance()->fileChooserOffset);
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
  // the names are numbered from 1
  if(num < 1) return "";
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

void fileChooserStoreOffset(int offset[2])
{
  if(CTX::instance()->nativeFileChooser) {
    // not available
  }
  else if(fc && fc->window()) {
    storeWindowOffset(fc->window(), offset);
  }
}

// the modal window of an export dialog
static Fl_Double_Window *dialogWindow(int w, int h, const char *title = nullptr)
{
  Fl_Double_Window *window = new Fl_Double_Window(w, h, title);
  window->box(GMSH_WINDOW_BOX);
  window->set_modal();
  return window;
}

// its OK and Cancel buttons, bw wide under y, which end the window
static void okCancelButtons(Fl_Window *window, int y, int bw, Fl_Button *&ok,
                            Fl_Button *&cancel)
{
  ok = new Fl_Return_Button(WB, y + WB, bw, BH, "OK");
  cancel = new Fl_Button(2 * WB + bw, y + WB, bw, BH, "Cancel");
  window->end();
  window->hotspot(window);
}

// The dialogs whose rows each show an option and set it on OK. A row is a
// check box, a value, two values on one line (the label after the second), a
// slider or a choice; the ranges of the values and the items of the choices
// are those of the options (see GetOptionRange() and GetOptionChoices() in
// Options.h)
enum dialogRowKind { Check, Value, TwoValues, Slider, Choice };
struct dialogRow {
  dialogRowKind kind;
  const char *label, *option, *option2;
};

class optionDialog {
private:
  Fl_Window *_window;
  Fl_Button *_ok, *_cancel;
  // the widget of each option, and the values of its items if a choice
  struct field {
    Fl_Widget *widget;
    std::string option;
    std::vector<double> values;
  };
  std::vector<field> _fields;
  // "Print.Text" as "Print" and "Text"
  static std::string _category(const std::string &o)
  { return o.substr(0, o.find('.')); }
  static std::string _name(const std::string &o)
  { return o.substr(o.find('.') + 1); }
  static double _get(const std::string &o)
  {
    double v = 0.;
    NumberOption(GMSH_GET, _category(o).c_str(), 0, _name(o).c_str(), v);
    return v;
  }
  Fl_Widget *_add(Fl_Widget *w, const char *option)
  {
    w->tooltip(option);
    if(Fl_Valuator *v = dynamic_cast<Fl_Valuator *>(w)) optionRange(v, option);
    std::vector<double> values;
    if(Fl_Choice *c = dynamic_cast<Fl_Choice *>(w))
      values = choiceItems(c, option);
    _fields.push_back({w, option, values});
    return w;
  }

public:
  // the rows under each other, bw the width of half a row
  optionDialog(const char *title, int bw, const std::vector<dialogRow> &rows)
  {
    int w = 2 * bw + 3 * WB, y = WB;
    _window = dialogWindow(w, 3 * WB + ((int)rows.size() + 1) * BH, title);
    for(const dialogRow &r : rows) {
      Fl_Widget *o = nullptr;
      switch(r.kind) {
      case Check: o = new Fl_Check_Button(WB, y, 2 * bw + WB, BH, r.label); break;
      case Value: o = new Fl_Value_Input(WB, y, bw, BH, r.label); break;
      case TwoValues:
        _add(new Fl_Value_Input(WB, y, bw / 2, BH), r.option);
        o = new Fl_Value_Input(WB + bw / 2, y, bw - bw / 2, BH, r.label);
        _add(o, r.option2);
        break;
      case Slider:
        o = new Fl_Value_Slider(WB, y, bw, BH, r.label);
        o->type(FL_HOR_SLIDER);
        break;
      case Choice: o = new Fl_Choice(WB, y, bw + bw / 2, BH, r.label); break;
      }
      if(r.kind != Check) o->align(FL_ALIGN_RIGHT);
      if(r.kind != TwoValues) _add(o, r.option);
      y += BH;
    }
    okCancelButtons(_window, y, bw, _ok, _cancel);
  }
  // the widget of an option, to enable or disable it
  Fl_Widget *field(const std::string &option)
  {
    for(auto &f : _fields)
      if(f.option == option) return f.widget;
    return nullptr;
  }
  // shows the values of the options, then calls adjust(); on OK, sets the
  // options of the rows that are enabled and calls apply(); other() is called
  // with the other widgets clicked (see runDialog())
  int run(const char *title, const std::function<void()> &apply,
          const std::function<void()> &adjust = nullptr,
          const std::function<void(Fl_Widget *)> &other = nullptr)
  {
    if(title) _window->label(title);
    for(auto &f : _fields) {
      double v = _get(f.option);
      if(Fl_Button *b = dynamic_cast<Fl_Button *>(f.widget))
        b->value(v != 0);
      else if(Fl_Valuator *val = dynamic_cast<Fl_Valuator *>(f.widget))
        val->value(v);
      else if(Fl_Choice *c = dynamic_cast<Fl_Choice *>(f.widget)) {
        for(std::size_t i = 0; i < f.values.size(); i++)
          if(f.values[i] == v) c->value((int)i);
      }
    }
    if(adjust) adjust();
    return runDialog(
      _window, _ok, _cancel,
      [&]() {
        for(auto &f : _fields) {
          if(!f.widget->active()) continue;
          double v = _get(f.option);
          if(Fl_Button *b = dynamic_cast<Fl_Button *>(f.widget))
            v = checkValue(b, v);
          else if(Fl_Valuator *val = dynamic_cast<Fl_Valuator *>(f.widget))
            v = val->value();
          else if(Fl_Choice *c = dynamic_cast<Fl_Choice *>(f.widget)) {
            if(c->value() >= 0 && c->value() < (int)f.values.size())
              v = f.values[c->value()];
          }
          NumberOption(GMSH_SET | GMSH_GUI, _category(f.option).c_str(), 0,
                       _name(f.option).c_str(), v);
        }
        apply();
      },
      other);
  }
};

// Generic save bitmap dialog

int genericBitmapFileDialog(const char *name, const char *title, int format)
{
  static optionDialog *dialog = nullptr;
  if(!dialog)
    dialog = new optionDialog(
      nullptr, BB,
      {{Check, "Print text strings", "Print.Text"},
       {Check, "Print background", "Print.Background"},
       {Check, "Composite all window tiles", "Print.CompositeWindows"},
       {Check, "Scale sizes with the picture", "Print.ScalePixelSizes"},
       {TwoValues, "Dimensions", "Print.Width", "Print.Height"},
       {Value, "Supersampling", "Print.Supersampling"},
       {Slider, "Quality", "Print.JpegQuality"},
       {Slider, "Smoothing", "Print.JpegSmoothing"}});
  return dialog->run(
    title, [&]() { CreateOutputFile(name, format); },
    [&]() {
      // (the quality and smoothing of JPEG pictures)
      for(const char *o : {"Print.JpegQuality", "Print.JpegSmoothing"}) {
        if(format == FORMAT_JPEG)
          dialog->field(o)->activate();
        else
          dialog->field(o)->deactivate();
      }
    });
}

// pgf dialog

int pgfBitmapFileDialog(const char *name, const char *title, int format)
{
  static optionDialog *dialog = nullptr;
  if(!dialog)
    dialog = new optionDialog(
      nullptr, BB,
      {{Check, "Flat graphics", "Print.PgfTwoDim"},
       {Check, "Export axis (for entire fig)", "Print.PgfExportAxis"},
       {Check, "Horizontal colorbar", "Print.PgfHorizontalBar"},
       {TwoValues, "Dimensions", "Print.Width", "Print.Height"}});
  return dialog->run(title, [&]() {
    // never any text, background or compositing in the bitmap of a PGF
    // figure: for this file only, the options are set back after
    double text = opt_print_text(0, GMSH_GET, 0);
    double background = opt_print_background(0, GMSH_GET, 0);
    double composite = opt_print_composite_windows(0, GMSH_GET, 0);
    opt_print_text(0, GMSH_SET, 0);
    opt_print_background(0, GMSH_SET, 0);
    opt_print_composite_windows(0, GMSH_SET, 0);
    CreateOutputFile(name, format);
    opt_print_text(0, GMSH_SET, text);
    opt_print_background(0, GMSH_SET, background);
    opt_print_composite_windows(0, GMSH_SET, composite);
  });
}

// TeX dialog

int latexFileDialog(const char *name)
{
  static optionDialog *dialog = nullptr;
  if(!dialog)
    dialog = new optionDialog(
      "LaTeX Options", BB,
      {{Check, "Print strings as equations", "Print.TexAsEquation"},
       {Check, "Force font size", "Print.TexForceFontSize"},
       {Value, "Graphics width in mm", "Print.TexWidthInMm"}});
  return dialog->run(nullptr, [&]() { CreateOutputFile(name, FORMAT_TEX); });
}

// Save mpeg dialog

int mpegFileDialog(const char *name, int format)
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
    dialog->window = new Fl_Double_Window(w, h, "Movie Options");
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
    optionRange(dialog->v[4], "Print.ParameterSteps");
    y += BH;
    dialog->param->end();

    y += WB;

    dialog->v[0] =
      new Fl_Value_Input(WB, y, ww2, BH, "Frame duration (in seconds)");
    dialog->v[0]->tooltip("PostProcessing.AnimationDelay");
    y += BH;
    optionRange(dialog->v[0], "PostProcessing.AnimationDelay");
    dialog->v[0]->precision(3);
    dialog->v[0]->align(FL_ALIGN_RIGHT);

    dialog->v[1] = new Fl_Value_Input(WB, y, ww2, BH, "Steps between frames");
    dialog->v[1]->tooltip("PostProcessing.AnimationStep");
    y += BH;
    optionRange(dialog->v[1], "PostProcessing.AnimationStep");
    dialog->v[1]->align(FL_ALIGN_RIGHT);

    dialog->c[0] = new Fl_Check_Button(WB, y, ww, BH, "Print background");
    dialog->c[0]->tooltip("Print.Background");
    y += BH;

    dialog->c[1] =
      new Fl_Check_Button(WB, y, ww, BH, "Composite all window tiles");
    dialog->c[1]->tooltip("Print.CompositeWindows");
    y += BH;

    dialog->c[2] = new Fl_Check_Button(WB, y, ww, BH, "Delete temporary files");
    dialog->c[2]->tooltip("Print.DeleteTemporaryFiles");
    y += BH;

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

  auto save = [&](bool preview) {
    opt_post_anim_cycle(0, GMSH_SET | GMSH_GUI,
                        dialog->b[2]->value() ? 2 :
                        dialog->b[1]->value() ? 1 :
                                                0);
    opt_post_anim_delay(0, GMSH_SET | GMSH_GUI, dialog->v[0]->value());
    opt_post_anim_step(0, GMSH_SET | GMSH_GUI, (int)dialog->v[1]->value());

    opt_print_parameter_command(0, GMSH_SET | GMSH_GUI, dialog->p->value());
    opt_print_parameter_first(0, GMSH_SET | GMSH_GUI, dialog->v[2]->value());
    opt_print_parameter_last(0, GMSH_SET | GMSH_GUI, dialog->v[3]->value());
    opt_print_parameter_steps(0, GMSH_SET | GMSH_GUI, dialog->v[4]->value());
    opt_print_background(0, GMSH_SET | GMSH_GUI, (int)dialog->c[0]->value());
    opt_print_composite_windows(0, GMSH_SET | GMSH_GUI,
                                (int)dialog->c[1]->value());
    opt_print_delete_tmp_files(0, GMSH_SET | GMSH_GUI,
                               (int)dialog->c[2]->value());
    dialog->buttons->deactivate();
    CreateOutputFile(name, preview ? FORMAT_MPEG_PREVIEW : format, !preview);
    dialog->buttons->activate();
  };
  return runDialog(
    dialog->window, dialog->ok, dialog->cancel, [&]() { save(false); },
    [&](Fl_Widget *o) {
      if(o == dialog->b[0] || o == dialog->b[1] || o == dialog->b[2]) {
        if(dialog->b[2]->value())
          dialog->param->activate();
        else
          dialog->param->deactivate();
      }
      if(o == dialog->preview) save(true);
    });
}

// Save gif dialog

int gifFileDialog(const char *name)
{
  static optionDialog *dialog = nullptr;
  if(!dialog)
    dialog = new optionDialog(
      "GIF Options", BB,
      {{Check, "Dither", "Print.GifDither"},
       {Check, "Interlace", "Print.GifInterlace"},
       {Check, "Sort colormap", "Print.GifSort"},
       {Check, "Transparent background", "Print.GifTransparent"},
       {Check, "Print text strings", "Print.Text"},
       {Check, "Print background", "Print.Background"},
       {Check, "Composite all window tiles", "Print.CompositeWindows"}});
  return dialog->run(nullptr, [&]() { CreateOutputFile(name, FORMAT_GIF); });
}

// Save ps/eps/pdf dialog

int gl2psFileDialog(const char *name, const char *title, int format)
{
  static optionDialog *dialog = nullptr;
  if(!dialog)
    dialog = new optionDialog(
      nullptr, BB,
      {{Choice, "Type", "Print.EpsQuality"},
       {Check, "Compress", "Print.EpsCompress"},
       {Check, "Remove hidden primitives", "Print.EpsOcclusionCulling"},
       {Check, "Optimize BSP tree", "Print.EpsBestRoot"},
       {Check, "Use level 3 shading", "Print.EpsPS3Shading"},
       {Check, "Print text strings", "Print.Text"},
       {Check, "Print background", "Print.Background"}});
  // what applies to the type of the file: compressed with zlib; with vector
  // graphics, the hidden primitives, the BSP tree of the accurate sort and
  // the level 3 shading of PostScript
  auto activate = [&]() {
    int quality = ((Fl_Choice *)dialog->field("Print.EpsQuality"))->value();
    bool vector = (quality != 0),
         ps = (format == FORMAT_PS || format == FORMAT_EPS);
#if defined(HAVE_LIBZ)
    bool zlib = true;
#else
    bool zlib = false;
#endif
    for(auto &f : std::vector<std::pair<const char *, bool>>{
          {"Print.EpsCompress", zlib},
          {"Print.EpsOcclusionCulling", vector},
          {"Print.EpsBestRoot", quality == 2},
          {"Print.EpsPS3Shading", vector && ps}}) {
      if(f.second)
        dialog->field(f.first)->activate();
      else
        dialog->field(f.first)->deactivate();
    }
  };
  return dialog->run(
    title, [&]() { CreateOutputFile(name, format); },
    activate,
    [&](Fl_Widget *o) {
      if(o == dialog->field("Print.EpsQuality")) activate();
    });
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
    dialog->window = dialogWindow(w, h, "Options");
    dialog->b[0] =
      new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Save only modified options");
    y += BH;
    dialog->b[0]->value(1);
    dialog->b[1] =
      new Fl_Check_Button(WB, y, 2 * BB + WB, BH, "Print help strings");
    y += BH;
    dialog->b[1]->value(0);
    okCancelButtons(dialog->window, y, BB, dialog->ok, dialog->cancel);
  }

  return runDialog(dialog->window, dialog->ok, dialog->cancel, [&]() {
    Msg::StatusBar(true, "Writing '%s'...", name);
    PrintOptions(0, GMSH_FULLRC, dialog->b[0]->value(), dialog->b[1]->value(),
                 name);
    Msg::StatusBar(true, "Done writing '%s'", name);
  });
}

// geo dialog

int geoFileDialog(const char *name)
{
  static optionDialog *dialog = nullptr;
  if(!dialog)
    dialog = new optionDialog(
      "GEO Options", BB,
      {{Check, "Save physical group labels", "Print.GeoLabels"},
       {Check, "Only save physical entities", "Print.GeoOnlyPhysicals"}});
  return dialog->run(nullptr, [&]() { CreateOutputFile(name, FORMAT_GEO); });
}

int meshStatFileDialog(const char *name)
{
  static optionDialog *dialog = nullptr;
  if(!dialog)
    dialog = new optionDialog(
      "POS Options", BB + 9,
      {{Check, "Save all elements", "Mesh.SaveAll"},
       {Check, "Print elementary tags", "Print.PostElementary"},
       {Check, "Print element numbers", "Print.PostElement"},
       {Check, "Print SICN quality measure", "Print.PostSICN"},
       {Check, "Print SIGE quality measure", "Print.PostSIGE"},
       {Check, "Print Gamma quality measure", "Print.PostGamma"},
       {Check, "Print Eta quality measure", "Print.PostEta"},
       {Check, "Print Disto quality measure", "Print.PostDisto"}});
  return dialog->run(nullptr, [&]() { CreateOutputFile(name, FORMAT_POS); });
}

// the choice of the views to save with the mesh (Mesh.SaveViews): with views
// and no mesh, the views are what there is to save
static int _viewsToSave()
{
  int views = (int)opt_mesh_save_views(0, GMSH_GET, 0);
  if(!views && !PView::list.empty() && !GModel::current()->getNumMeshElements())
    views = 1;
  return views;
}

// a file written with the views chosen: the views proposed by _viewsToSave()
// where the option says none are for this file only, the option is put back
static void _writeWithViews(int proposed, int option,
                            const std::function<void()> &write)
{
  write();
  if(proposed != option && (int)opt_mesh_save_views(0, GMSH_GET, 0) == proposed)
    opt_mesh_save_views(0, GMSH_SET | GMSH_GUI, option);
}

// Save msh dialog
struct _mshFileDialog {
  Fl_Window *window;
  Fl_Check_Button *b[5];
  Fl_Choice *c, *views;
  Fl_Button *ok, *cancel;
};

int mshFileDialog(const char *name)
{
  static _mshFileDialog *dialog = nullptr;

  static Fl_Menu_Item formatmenu[] = {
    {"Version 1", 0, nullptr, nullptr},
    {"Version 2 ASCII", 0, nullptr, nullptr},
    {"Version 2 Binary", 0, nullptr, nullptr},
    {"Version 4.1 ASCII", 0, nullptr, nullptr},
    {"Version 4.1 Binary", 0, nullptr, nullptr},
    {"Version 4.2 ASCII", 0, nullptr, nullptr},
    {"Version 4.2 Binary", 0, nullptr, nullptr},
    {nullptr}};

  int BBB = BB + 9; // labels too long

  if(!dialog) {
    dialog = new _mshFileDialog;
    int h = 3 * WB + 8 * BH, w = 2 * BBB + 3 * WB, y = WB;
    dialog->window = dialogWindow(w, h, "MSH Options");
    dialog->c = new Fl_Choice(WB, y, BBB + BBB / 2, BH, "Format");
    dialog->c->tooltip("Mesh.MshFileVersion, Mesh.Binary");
    y += BH;
    dialog->c->menu(formatmenu);
    dialog->c->align(FL_ALIGN_RIGHT);
    dialog->c->callback((Fl_Callback *)format_cb, dialog);
    dialog->views = new Fl_Choice(WB, y, BBB + BBB / 2, BH, "Views");
    dialog->views->tooltip("Mesh.SaveViews");
    y += BH;
    choiceItems(dialog->views, "Mesh.SaveViews");
    dialog->views->align(FL_ALIGN_RIGHT);
    dialog->b[0] =
      new Fl_Check_Button(WB, y, 2 * BBB + WB, BH, "Save all elements");
    dialog->b[0]->tooltip("Mesh.SaveAll");
    y += BH;
    dialog->b[1] = new Fl_Check_Button(WB, y, 2 * BBB + WB, BH,
                                       "Save parametric coordinates");
    dialog->b[1]->tooltip("Mesh.SaveParametric");
    y += BH;
    dialog->b[2] = new Fl_Check_Button(WB, y, 2 * BBB + WB, BH,
                                       "Save one file per partition");
    dialog->b[2]->tooltip("Mesh.PartitionSplitMeshFiles");
    y += BH;
    dialog->b[3] = new Fl_Check_Button(WB, y, 2 * BBB + WB, BH,
                                       "Save partition topology file");
    dialog->b[3]->tooltip("Mesh.PartitionTopologyFile");
    y += BH;
    dialog->b[4] = new Fl_Check_Button(WB, y, 2 * BBB + WB, BH,
                                       "Save high order views refined");
    dialog->b[4]->tooltip("PostProcessing.SaveAdapted");
    y += BH;

    okCancelButtons(dialog->window, y, BBB, dialog->ok, dialog->cancel);
  }

  if(opt_mesh_msh_file_version(0, GMSH_GET, 0) == 1.0)
    dialog->c->value(0);
  else if(opt_mesh_msh_file_version(0, GMSH_GET, 0) < 4.0)
    dialog->c->value(!opt_mesh_binary(0, GMSH_GET, 0) ? 1 : 2);
  else if(opt_mesh_msh_file_version(0, GMSH_GET, 0) < 4.2)
    dialog->c->value(!opt_mesh_binary(0, GMSH_GET, 0) ? 3 : 4);
  else
    dialog->c->value(!opt_mesh_binary(0, GMSH_GET, 0) ? 5 : 6);
  dialog->views->value(_viewsToSave());
  dialog->b[0]->value(opt_mesh_save_all(0, GMSH_GET, 0) ? 1 : 0);
  dialog->b[1]->value(opt_mesh_save_parametric(0, GMSH_GET, 0) ? 1 : 0);
  dialog->b[4]->value(opt_post_save_adapted(0, GMSH_GET, 0) ? 1 : 0);
  dialog->b[2]->value(opt_mesh_partition_split_mesh_files(0, GMSH_GET, 0) ? 1 :
                                                                            0);
  dialog->b[3]->value(
    opt_mesh_partition_save_topology_file(0, GMSH_GET, 0) ? 1 : 0);
  // what the format and the model allow, each time the dialog is shown
  format_cb(nullptr, dialog);
  int option = (int)opt_mesh_save_views(0, GMSH_GET, 0);
  int proposed = _viewsToSave();
  return runDialog(dialog->window, dialog->ok, dialog->cancel, [&]() {
    opt_mesh_msh_file_version(0, GMSH_SET | GMSH_GUI,
                              (dialog->c->value() == 0) ? 1.0 :
                              (dialog->c->value() <= 2) ? 2.2 :
                              (dialog->c->value() <= 4) ? 4.1 :
                                                          4.2);
    opt_mesh_binary(0, GMSH_SET | GMSH_GUI,
                    (dialog->c->value() && !(dialog->c->value() % 2)) ? 1 : 0);
    if(dialog->views->active()) {
      opt_mesh_save_views(0, GMSH_SET | GMSH_GUI, dialog->views->value());
      opt_post_save_adapted(0, GMSH_SET | GMSH_GUI,
                            dialog->b[4]->value() ? 1 : 0);
    }
    // (the value kept unless the box changed: the KEY format reads its bits)
    if(dialog->b[0]->value() != (opt_mesh_save_all(0, GMSH_GET, 0) ? 1 : 0))
      opt_mesh_save_all(0, GMSH_SET | GMSH_GUI, dialog->b[0]->value() ? 1 : 0);
    opt_mesh_save_parametric(0, GMSH_SET | GMSH_GUI,
                             dialog->b[1]->value() ? 1 : 0);
    opt_mesh_partition_split_mesh_files(0, GMSH_SET | GMSH_GUI,
                                        dialog->b[2]->value() ? 1 : 0);
    opt_mesh_partition_save_topology_file(0, GMSH_SET | GMSH_GUI,
                                          dialog->b[3]->value() ? 1 : 0);
    _writeWithViews(proposed, option,
                    [&]() { CreateOutputFile(name, FORMAT_MSH); });
  });
}

void format_cb(Fl_Widget *widget, void *data)
{
  _mshFileDialog *dialog = static_cast<_mshFileDialog *>(data);
  // (no views in MSH 1)
  if(!PView::list.empty() && dialog->c->value() != 0) {
    dialog->views->activate();
    dialog->b[4]->activate();
  }
  else {
    dialog->views->deactivate();
    dialog->b[4]->deactivate();
  }
  // the partitions in files of their own, and their topology, in every
  // version after 1
  if(dialog->c->value() != 0 && GModel::current()->getNumPartitions() > 0) {
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
  // (shared by the UNV and the INP exports)
  static optionDialog *dialog = nullptr;
  if(!dialog)
    dialog = new optionDialog(
      nullptr, BB + 9,
      {{Check, "Save all elements", "Mesh.SaveAll"},
       {Check, "Save groups of nodes", "Mesh.SaveGroupsOfNodes"}});
  return dialog->run(title, [&]() { CreateOutputFile(name, format); });
}

// LSDYNA KEY and RADIOSS mesh dialog

int keyRadFileDialog(const char *name, const char *title, int format)
{
  struct _keyRadFileDialog {
    Fl_Window *window;
    Fl_Choice *c[3];
    Fl_Check_Button *b[2];
    Fl_Button *ok, *cancel;
  };
  static _keyRadFileDialog *dialog = nullptr;

  // the elements of each dimension saved (two bits of Mesh.SaveAll each)
  static Fl_Menu_Item menu[] = {{"Physical groups", 0, nullptr, nullptr},
                                {"Save all", 0, nullptr, nullptr},
                                {"Ignore", 0, nullptr, nullptr},
                                {nullptr}};

  int BBB = BB + 16; // labels too long

  if(!dialog) {
    dialog = new _keyRadFileDialog;
    int h = 3 * WB + 6 * BH, w = 2 * BBB + 3 * WB, y = WB;
    dialog->window = dialogWindow(w, h, title);
    const char *labels[3] = {"Line", "Surface", "Volume"};
    for(int i = 0; i < 3; i++) {
      dialog->c[i] = new Fl_Choice(WB, y, BBB + BBB / 4, BH, labels[i]);
      y += BH;
      dialog->c[i]->menu(menu);
      dialog->c[i]->tooltip("Mesh.SaveAll");
      dialog->c[i]->align(FL_ALIGN_RIGHT);
    }
    dialog->b[0] =
      new Fl_Check_Button(WB, y, 2 * BBB + WB, BH, "Save groups of elements");
    dialog->b[0]->tooltip("Mesh.SaveGroupsOfNodes");
    y += BH;
    dialog->b[1] =
      new Fl_Check_Button(WB, y, 2 * BBB + WB, BH, "Save groups of nodes");
    dialog->b[1]->tooltip("Mesh.SaveGroupsOfNodes");
    y += BH;
    okCancelButtons(dialog->window, y, BBB, dialog->ok, dialog->cancel);
  }

  dialog->window->label(title);
  // the bits of the options the dialog shows, the others kept, and the
  // options written only if changed (a negative Mesh.SaveGroupsOfNodes has
  // a meaning of its own)
  const int allMask = 4 | 8 | 16 | 32 | 64 | 128, groupsMask = 2 | 1;
  int all = (int)opt_mesh_save_all(0, GMSH_GET, 0);
  int groups = (int)opt_mesh_save_groups_of_nodes(0, GMSH_GET, 0);
  int choices[3];
  for(int i = 0; i < 3; i++) {
    int bits = 4 << (2 * i);
    choices[i] = (all & bits) ? 1 : (all & (2 * bits)) ? 2 : 0;
    dialog->c[i]->value(choices[i]);
  }
  dialog->b[0]->value(groups & 2 ? 1 : 0);
  dialog->b[1]->value(groups & 1 ? 1 : 0);
  return runDialog(dialog->window, dialog->ok, dialog->cancel, [&]() {
    if(dialog->c[0]->value() != choices[0] ||
       dialog->c[1]->value() != choices[1] ||
       dialog->c[2]->value() != choices[2])
      opt_mesh_save_all(0, GMSH_SET | GMSH_GUI,
                        (all & ~allMask) + dialog->c[0]->value() * 4 +
                          dialog->c[1]->value() * 16 +
                          dialog->c[2]->value() * 64);
    int g = (dialog->b[0]->value() ? 2 : 0) + (dialog->b[1]->value() ? 1 : 0);
    if(g != (groups & groupsMask))
      opt_mesh_save_groups_of_nodes(0, GMSH_SET | GMSH_GUI,
                                    (groups & ~groupsMask) + g);
    CreateOutputFile(name, format);
  });
}

// Save bdf dialog

int bdfFileDialog(const char *name)
{
  static optionDialog *dialog = nullptr;
  if(!dialog)
    dialog = new optionDialog("BDF Options", BB + 16,
                              {{Choice, "Format", "Mesh.BdfFieldFormat"},
                               {Choice, "Element tag", "Mesh.SaveElementTagType"},
                               {Check, "Save all elements", "Mesh.SaveAll"}});
  return dialog->run(nullptr, [&]() { CreateOutputFile(name, FORMAT_BDF); });
}

// Generic mesh dialog

int stlFileDialog(const char *name)
{
  static optionDialog *dialog = nullptr;
  if(!dialog)
    dialog = new optionDialog("STL Options", BB + 9,
                              {{Choice, "Format", "Mesh.Binary"},
                               {Check, "Save all elements", "Mesh.SaveAll"},
                               {Choice, "Solid", "Mesh.StlOneSolidPerSurface"}});
  // a solid per physical surface saves the elements of the physical groups
  auto activate = [&]() {
    if(((Fl_Choice *)dialog->field("Mesh.StlOneSolidPerSurface"))->value() == 2)
      dialog->field("Mesh.SaveAll")->deactivate();
    else
      dialog->field("Mesh.SaveAll")->activate();
  };
  return dialog->run(
    nullptr, [&]() { CreateOutputFile(name, FORMAT_STL); },
    activate,
    [&](Fl_Widget *o) {
      if(o == dialog->field("Mesh.StlOneSolidPerSurface")) activate();
    });
}

// Generic mesh dialog

int genericMeshFileDialog(const char *name, const char *title, int format,
                          bool binary_support, bool element_tag_support)
{
  static optionDialog *dialog = nullptr;
  if(!dialog)
    dialog = new optionDialog(nullptr, BB + 16,
                              {{Choice, "Format", "Mesh.Binary"},
                               {Choice, "Element tag", "Mesh.SaveElementTagType"},
                               {Check, "Save all elements", "Mesh.SaveAll"}});
  return dialog->run(
    title, [&]() { CreateOutputFile(name, format); },
    [&]() {
      // what the format supports
      for(auto &f : std::vector<std::pair<const char *, bool>>{
            {"Mesh.Binary", binary_support},
            {"Mesh.SaveElementTagType", element_tag_support}}) {
        if(f.second)
          dialog->field(f.first)->activate();
        else
          dialog->field(f.first)->deactivate();
      }
    });
}

int medFileDialog(const char *name)
{
  static optionDialog *dialog = nullptr;
  if(!dialog)
    dialog = new optionDialog("MED Options", BB + 16,
                              {{Choice, "Views", "Mesh.SaveViews"},
                               {Check, "Save all elements", "Mesh.SaveAll"}});
  int option = 0, proposed = 0;
  return dialog->run(
    nullptr,
    [&]() {
      _writeWithViews(proposed, option,
                      [&]() { CreateOutputFile(name, FORMAT_MED); });
    },
    [&]() {
      // the views to save, if there are views
      Fl_Choice *views = (Fl_Choice *)dialog->field("Mesh.SaveViews");
      option = (int)opt_mesh_save_views(0, GMSH_GET, 0);
      proposed = _viewsToSave();
      views->value(proposed);
      if(PView::list.empty())
        views->deactivate();
      else
        views->activate();
    });
}

int vtuFileDialog(const char *name)
{
  static optionDialog *dialog = nullptr;
  if(!dialog)
    dialog = new optionDialog(
      "VTU Options", BB + 16,
      {{Choice, "Format", "Mesh.Binary"},
       {Choice, "Views", "Mesh.SaveViews"},
       {Check, "Save all elements", "Mesh.SaveAll"},
       {Check, "Save high order views refined", "PostProcessing.SaveAdapted"}});
  int option = 0, proposed = 0;
  return dialog->run(
    nullptr,
    [&]() {
      _writeWithViews(proposed, option,
                      [&]() { CreateOutputFile(name, FORMAT_VTU); });
    },
    [&]() {
      // the views to save, and how, if there are views
      Fl_Choice *views = (Fl_Choice *)dialog->field("Mesh.SaveViews");
      option = (int)opt_mesh_save_views(0, GMSH_GET, 0);
      proposed = _viewsToSave();
      views->value(proposed);
      for(const char *o : {"Mesh.SaveViews", "PostProcessing.SaveAdapted"}) {
        if(PView::list.empty())
          dialog->field(o)->deactivate();
        else
          dialog->field(o)->activate();
      }
    });
}

// POS format post-processing export dialog

// write the current, visible or all views (which = 0, 1 or 2): in the file, or
// if the format cannot hold several, in a file for each, name_i.ext
static void _saveViews(const std::string &name, int which, int format,
                       bool canAppend)
{
  std::vector<PView *> views;
  if(which == 0 && PView::list.size()) {
    int iview = FlGui::instance()->options->view.index;
    if(iview < 0 || iview >= (int)PView::list.size()) {
      Msg::Info("No or invalid current view: saving View[0]");
      iview = 0;
    }
    views.push_back(PView::list[iview]);
  }
  else {
    for(auto v : PView::list)
      if(which == 2 || v->getOptions()->visible) views.push_back(v);
  }
  if(views.empty()) {
    Msg::Error((which == 1) ? "No visible view" : "No views to save");
    return;
  }
  std::vector<std::string> split = SplitFileName(name);
  std::vector<std::pair<std::string, bool> > files;
  for(std::size_t i = 0; i < views.size(); i++) {
    std::string fileName = name;
    if(!canAppend && views.size() > 1)
      fileName = split[0] + split[1] + "_" +
                 std::to_string(views[i]->getIndex()) + split[2];
    views[i]->write(fileName, format, i ? canAppend : false, &files);
  }
  CreateReadBackScript(name, files);
}

int posFileDialog(const char *name)
{
  struct _posFileDialog {
    Fl_Window *window;
    Fl_Choice *c[2];
    Fl_Check_Button *adapted;
    Fl_Button *ok, *cancel;
  };
  static _posFileDialog *dialog = nullptr;

  static Fl_Menu_Item viewmenu[] = {{"Current", 0, nullptr, nullptr},
                                    {"Visible", 0, nullptr, nullptr},
                                    {"All", 0, nullptr, nullptr},
                                    {nullptr}};
  static Fl_Menu_Item formatmenu[] = {{"Parsed", 0, nullptr, nullptr},
                                      {"Legacy ASCII", 0, nullptr, nullptr},
                                      {"Legacy Binary", 0, nullptr, nullptr},
                                      {nullptr}};

  int BBB = BB + 9; // labels too long

  if(!dialog) {
    dialog = new _posFileDialog;
    int h = 3 * WB + 4 * BH, w = 2 * BBB + 3 * WB, y = WB;
    dialog->window = dialogWindow(w, h, "POS Options");
    dialog->c[0] = new Fl_Choice(WB, y, BBB + BBB / 2, BH, "View(s)");
    y += BH;
    dialog->c[0]->menu(viewmenu);
    dialog->c[0]->align(FL_ALIGN_RIGHT);
    dialog->c[1] = new Fl_Choice(WB, y, BBB + BBB / 2, BH, "Format");
    y += BH;
    dialog->c[1]->menu(formatmenu);
    dialog->c[1]->align(FL_ALIGN_RIGHT);
    dialog->adapted = new Fl_Check_Button(WB, y, 2 * BBB + WB, BH,
                                          "Save high order views refined");
    dialog->adapted->tooltip("PostProcessing.SaveAdapted");
    y += BH;
    okCancelButtons(dialog->window, y, BBB, dialog->ok, dialog->cancel);
  }

  dialog->adapted->value(opt_post_save_adapted(0, GMSH_GET, 0) ? 1 : 0);
  return runDialog(dialog->window, dialog->ok, dialog->cancel, [&]() {
    const int formats[] = {PView::POS_PARSED, PView::POS_ASCII,
                           PView::POS_BINARY};
    int format = formats[dialog->c[1]->value()];
    bool canAppend = (format == PView::POS_PARSED);
    opt_post_save_adapted(0, GMSH_SET | GMSH_GUI,
                          dialog->adapted->value() ? 1 : 0);
    _saveViews(name, dialog->c[0]->value(), format, canAppend);
  });
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
    dialog->window = dialogWindow(w, h);
    dialog->c = new Fl_Choice(WB, y, BBB + BBB / 2, BH, "View(s)");
    y += BH;
    dialog->c->menu(viewmenu);
    dialog->c->align(FL_ALIGN_RIGHT);
    dialog->e[0] =
      new Fl_Check_Button(WB, y, w - 2 * WB, BH, "Remove inner borders");
    dialog->e[0]->tooltip("Print.X3dRemoveInnerBorders");
    y += BH;
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
    okCancelButtons(dialog->window, y, BBB, dialog->ok, dialog->cancel);
  }

  dialog->window->label(title);
  dialog->input[0]->value(log10(opt_print_x3d_precision(0, GMSH_GET, 0)));
  dialog->input[1]->value(opt_print_x3d_transparency(0, GMSH_GET, 0));
  dialog->e[0]->value(opt_print_x3d_remove_inner_borders(0, GMSH_GET, 0));
  dialog->e[1]->value(opt_print_x3d_compatibility(0, GMSH_GET, 0));

  return runDialog(dialog->window, dialog->ok, dialog->cancel, [&]() {
    opt_print_x3d_precision(0, GMSH_SET | GMSH_GUI,
                            pow(10., dialog->input[0]->value()));
    opt_print_x3d_transparency(0, GMSH_SET | GMSH_GUI,
                               dialog->input[1]->value());
    opt_print_x3d_remove_inner_borders(0, GMSH_SET | GMSH_GUI,
                                       dialog->e[0]->value());
    opt_print_x3d_compatibility(0, GMSH_SET | GMSH_GUI, dialog->e[1]->value());
    _saveViews(name, dialog->c->value(), format, false);
  });
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
    dialog->window = dialogWindow(w, h);
    dialog->c[0] = new Fl_Choice(WB, y, BBB + BBB / 2, BH, "View(s)");
    y += BH;
    dialog->c[0]->menu(viewmenu);
    dialog->c[0]->align(FL_ALIGN_RIGHT);
    okCancelButtons(dialog->window, y, BBB, dialog->ok, dialog->cancel);
  }

  dialog->window->label(title);
  return runDialog(dialog->window, dialog->ok, dialog->cancel, [&]() {
    _saveViews(name, dialog->c[0]->value(), format, false);
  });
}
