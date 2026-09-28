// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// The file chooser of this interface: FLTK's own, or the native one of the
// system. What an output format asks once the file is chosen is described in
// src/gui/GuiExport.cpp, for the three interfaces at once.

#include <errno.h>
#include <FL/Fl_Native_File_Chooser.H>
#include <FL/Fl_File_Chooser.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_File_Input.H>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "StringUtils.h"
#include "fileDialogs.h"
#include "Context.h"
#include "GModel.h"

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
