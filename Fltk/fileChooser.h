// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _FILE_PICKER_H_
#define _FILE_PICKER_H_

#include <FL/Fl_File_Chooser.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_File_Input.H>

// The FLTK team doesn't want to add a position() method to the file
// chooser, so we have to derive our own. To make things worse, the 
// original file chooser doesn't expose its window to the world, so
// we need to use a cheap hack to get to it. Even worse is the hack
// used to get the focus on the file input widget. Sigh...

class fileChooser : public Fl_File_Chooser {
 private:
  Fl_Window *_win;
  Fl_File_Input *_in;
 public:
  fileChooser(const char *d, const char *p, int t, const char *title)
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
      if(_in)
        _in->take_focus();
      else
        _win->take_focus();
    }
    else
      Fl_File_Chooser::show();
  }
  void position(int x, int y){ if(_win) _win->position(x,y); }
  int x(){ if(_win) return _win->x(); else return 100; }
  int y(){ if(_win) return _win->y(); else return 100; }
};

#endif
