// $Id: GUI_Extras.cpp,v 1.2 2004-12-30 23:25:03 geuzaine Exp $
//
// Copyright (C) 1997-2004 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Value_Slider.H>
#include <errno.h>

#include "Gmsh.h"
#include "GmshUI.h"
#include "Mesh.h"
#include "File_Picker.h"
#include "CreateFile.h"
#include "Options.h"
#include "Context.h"

extern Context_T CTX;

// File chooser

static File_Picker *fc = NULL;

int file_chooser(int multi, int create, const char *message,
		 const char *pat, int patindex, char *fname)
{
  static char oldfilter[1024];

  Fl_File_Chooser::show_label = "Format:";
  Fl_File_Chooser::all_files_label = "All files (*)";

  if(!fc) {
    fc = new File_Picker(getenv("PWD") ? "." : CTX.home_dir, pat, 
			      Fl_File_Chooser::SINGLE, message);
    fc->position(CTX.file_chooser_position[0], CTX.file_chooser_position[1]);
    strncpy(oldfilter, pat, 1024);
  }

  fc->label(message);

  if(fname)
    fc->value(fname);

  if(strncmp(oldfilter, pat, 1024)) {
    strncpy(oldfilter, pat, 1024);
    fc->filter(pat);
    fc->filter_value(patindex);
  }

  if(multi)
    fc->type(Fl_File_Chooser::MULTI);
  else if(create)
    fc->type(Fl_File_Chooser::CREATE);
  else
    fc->type(Fl_File_Chooser::SINGLE);

  fc->show();

  while(fc->shown())
    Fl::wait();

  if(fc->value())
    return fc->count();
  else
    return 0;
}

char *file_chooser_get_name(int num)
{
  if(!fc)
    return "";
  return (char *)fc->value(num);
}

int file_chooser_get_filter()
{
  if(!fc)
    return 0;
  return fc->filter_value();
}

void file_chooser_get_position(int *x, int *y)
{
  if(!fc)
    return;
  *x = fc->x();
  *y = fc->y();
}

// Arrow editor

int arrow_editor(char *title, double &a, double &b, double &c)
{
  struct _editor{
    Fl_Window *window;
    Fl_Value_Slider *sa, *sb, *sc;
    Fl_Button *apply, *cancel;
  };
  static _editor *editor = NULL;

  if(!editor){
    editor = new _editor;
    editor->window = new Fl_Window(200, 140);
    editor->sa = new Fl_Value_Slider(10, 10, 100, 25, "Head radius");
    editor->sa->type(FL_HOR_SLIDER);
    editor->sa->align(FL_ALIGN_RIGHT);
    editor->sb = new Fl_Value_Slider(10, 40, 100, 25, "Stem length");
    editor->sb->type(FL_HOR_SLIDER);
    editor->sb->align(FL_ALIGN_RIGHT);
    editor->sc = new Fl_Value_Slider(10, 70, 100, 25, "Stem radius");
    editor->sc->type(FL_HOR_SLIDER);
    editor->sc->align(FL_ALIGN_RIGHT);
    editor->apply = new Fl_Return_Button(10, 105, 85, 25, "Apply");
    editor->cancel = new Fl_Button(105, 105, 85, 25, "Cancel");
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

// jpeg dialog

int jpeg_dialog(char *name, int TeX)
{
  struct _jpeg_dialog{
    Fl_Window *window;
    Fl_Value_Slider *s[2];
    Fl_Button *ok, *cancel;
  };
  static _jpeg_dialog *dialog = NULL;

  if(!dialog){
    dialog = new _jpeg_dialog;
    int h = 3*10 + 25 + 2*25, y = 0;
    dialog->window = new Fl_Window(200, h, "JPEG options"); y = 10;
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->s[0] = new Fl_Value_Slider(10, y, 100, 25, "Quality"); y += 25;
    dialog->s[0]->type(FL_HOR_SLIDER);
    dialog->s[0]->align(FL_ALIGN_RIGHT);
    dialog->s[0]->minimum(1);
    dialog->s[0]->maximum(100);
    dialog->s[0]->step(1);
    dialog->s[1] = new Fl_Value_Slider(10, y, 100, 25, "Smoothing"); y += 25;
    dialog->s[1]->type(FL_HOR_SLIDER);
    dialog->s[1]->align(FL_ALIGN_RIGHT);
    dialog->s[1]->minimum(0);
    dialog->s[1]->maximum(100);
    dialog->s[1]->step(1);
    dialog->ok = new Fl_Return_Button(10, y+10, 85, 25, "OK");
    dialog->cancel = new Fl_Button(105, y+10, 85, 25, "Cancel");
    dialog->window->set_modal();
    dialog->window->end();
    dialog->window->hotspot(dialog->window);
  }
  
  dialog->s[0]->value(CTX.print.jpeg_quality);
  dialog->s[1]->value(CTX.print.jpeg_smoothing);
  dialog->window->show();

  while(dialog->window->shown()){
    Fl::wait();
    for (;;) {
      Fl_Widget* o = Fl::readqueue();
      if (!o) break;
      if (o == dialog->ok) {
	CTX.print.jpeg_quality = (int)dialog->s[0]->value();
	CTX.print.jpeg_smoothing = (int)dialog->s[1]->value();
	CreateOutputFile(name, TeX ? FORMAT_JPEGTEX : FORMAT_JPEG);
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

// gif dialog

int gif_dialog(char *name)
{
  struct _gif_dialog{
    Fl_Window *window;
    Fl_Check_Button *b[4];
    Fl_Button *ok, *cancel;
  };
  static _gif_dialog *dialog = NULL;

  if(!dialog){
    dialog = new _gif_dialog;
    int h = 3*10 + 25 + 4*25, y = 0;
    dialog->window = new Fl_Window(200, h, "GIF options"); y = 10;
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->b[0] = new Fl_Check_Button(10, y, 180, 25, "Dither"); y += 25;
    dialog->b[1] = new Fl_Check_Button(10, y, 180, 25, "Interlace"); y += 25;
    dialog->b[2] = new Fl_Check_Button(10, y, 180, 25, "Sort colormap"); y += 25;
    dialog->b[3] = new Fl_Check_Button(10, y, 180, 25, "Transparent background"); y += 25;
    for(int i = 0; i < 4; i++){
      dialog->b[i]->type(FL_TOGGLE_BUTTON);
      dialog->b[i]->down_box(GMSH_TOGGLE_BOX);
      dialog->b[i]->selection_color(GMSH_TOGGLE_COLOR);
    }
    dialog->ok = new Fl_Return_Button(10, y+10, 85, 25, "OK");
    dialog->cancel = new Fl_Button(105, y+10, 85, 25, "Cancel");
    dialog->window->set_modal();
    dialog->window->end();
    dialog->window->hotspot(dialog->window);
  }
  
  dialog->b[0]->value(CTX.print.gif_dither);
  dialog->b[1]->value(CTX.print.gif_interlace);
  dialog->b[2]->value(CTX.print.gif_sort);
  dialog->b[3]->value(CTX.print.gif_transparent);
  dialog->window->show();

  while(dialog->window->shown()){
    Fl::wait();
    for (;;) {
      Fl_Widget* o = Fl::readqueue();
      if (!o) break;
      if (o == dialog->ok) {
	CTX.print.gif_dither = dialog->b[0]->value();
	CTX.print.gif_interlace = dialog->b[1]->value();
	CTX.print.gif_sort = dialog->b[2]->value();
	CTX.print.gif_transparent = dialog->b[3]->value();
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

// ps/eps/pdf dialog

static void activate_gl2ps_choices(int format, Fl_Check_Button *b[5])
{
#if defined(HAVE_LIBZ)
  b[0]->activate();
#else
  b[0]->deactivate();
#endif
  switch(format){
  case 0: 
    b[1]->deactivate(); b[2]->deactivate(); 
    b[3]->deactivate(); b[4]->deactivate();
    break;
  case 1:
    b[1]->activate();   b[2]->activate();
    b[3]->deactivate(); b[4]->activate();
    break;
  case 2:
    b[1]->activate();   b[2]->activate();
    b[3]->activate();   b[4]->activate();
    break;
  }
}

int gl2ps_dialog(char *name, char *title, int format, int TeX)
{
  struct _gl2ps_dialog{
    Fl_Window *window;
    Fl_Check_Button *b[5];
    Fl_Choice *c;
    Fl_Button *ok, *cancel;
  };
  static _gl2ps_dialog *dialog = NULL;

  static Fl_Menu_Item sortmenu[] = {
    {"Raster image", 0, 0, 0},
    {"Vector simple sort", 0, 0, 0},
    {"Vector accurate sort", 0, 0, 0},
    {0}
  };

  if(!dialog){
    dialog = new _gl2ps_dialog;
    int h = 3*10 + 25 + 6*25, y = 0;
    dialog->window = new Fl_Window(200, h); y = 10;
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->c = new Fl_Choice(10, y, 145, 25, "Type"); y+= 25;
    dialog->c->menu(sortmenu);
    dialog->c->align(FL_ALIGN_RIGHT);
    dialog->b[0] = new Fl_Check_Button(10, y, 180, 25, "Compress"); y += 25;
    dialog->b[1] = new Fl_Check_Button(10, y, 180, 25, "Print background"); y += 25;
    dialog->b[2] = new Fl_Check_Button(10, y, 180, 25, "Remove hidden primitives"); y += 25;
    dialog->b[3] = new Fl_Check_Button(10, y, 180, 25, "Optimize BSP tree"); y += 25;
    dialog->b[4] = new Fl_Check_Button(10, y, 180, 25, "Use level 3 shading"); y += 25;
    for(int i = 0; i < 5; i++){
      dialog->b[i]->type(FL_TOGGLE_BUTTON);
      dialog->b[i]->down_box(GMSH_TOGGLE_BOX);
      dialog->b[i]->selection_color(GMSH_TOGGLE_COLOR);
    }
    dialog->ok = new Fl_Return_Button(10, y+10, 85, 25, "OK");
    dialog->cancel = new Fl_Button(105, y+10, 85, 25, "Cancel");
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
  activate_gl2ps_choices(CTX.print.eps_quality, dialog->b);
  dialog->window->show();

  while(dialog->window->shown()){
    Fl::wait();
    for (;;) {
      Fl_Widget* o = Fl::readqueue();
      if (!o) break;

      if (o == dialog->c){
	activate_gl2ps_choices(dialog->c->value(), dialog->b);
      }
      if (o == dialog->ok) {
	CTX.print.eps_quality = dialog->c->value();
	CTX.print.eps_compress = dialog->b[0]->value();
	CTX.print.eps_background = dialog->b[1]->value();
	CTX.print.eps_occlusion_culling = dialog->b[2]->value();
	CTX.print.eps_best_root = dialog->b[3]->value();
	CTX.print.eps_ps3shading = dialog->b[4]->value();
	CreateOutputFile(name, 
			 (format == 2) ? (TeX ? FORMAT_PDFTEX : FORMAT_PDF) : 
			 (format == 1) ? (TeX ? FORMAT_EPSTEX : FORMAT_EPS) : 
			 FORMAT_PS);
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

// gmsh options dialog

int options_dialog(char *name)
{
  struct _options_dialog{
    Fl_Window *window;
    Fl_Check_Button *b;
    Fl_Button *ok, *cancel;
  };
  static _options_dialog *dialog = NULL;

  if(!dialog){
    dialog = new _options_dialog;
    int h = 3*10 + 25 + 1*25, y = 0;
    dialog->window = new Fl_Window(200, h, "Options"); y = 10;
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->b = new Fl_Check_Button(10, y, 180, 25, "Save only modified options"); y += 25;
    dialog->b->value(1);
    dialog->b->type(FL_TOGGLE_BUTTON);
    dialog->b->down_box(GMSH_TOGGLE_BOX);
    dialog->b->selection_color(GMSH_TOGGLE_COLOR);
    dialog->ok = new Fl_Return_Button(10, y+10, 85, 25, "OK");
    dialog->cancel = new Fl_Button(105, y+10, 85, 25, "Cancel");
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
	Print_Options(0, GMSH_FULLRC, dialog->b->value(), name);
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

// save msh dialog

int msh_dialog(char *name)
{
  struct _msh_dialog{
    Fl_Window *window;
    Fl_Check_Button *b;
    Fl_Choice *c;
    Fl_Button *ok, *cancel;
  };
  static _msh_dialog *dialog = NULL;

  static Fl_Menu_Item versionmenu[] = {
    {"Version 1.0", 0, 0, 0},
    {"Version 2.0", 0, 0, 0},
    {0}
  };

  if(!dialog){
    dialog = new _msh_dialog;
    int h = 3*10 + 25 + 2*25, y = 0;
    dialog->window = new Fl_Window(200, h, "MSH options"); y = 10;
    dialog->window->box(GMSH_WINDOW_BOX);
    dialog->c = new Fl_Choice(10, y, 130, 25, "Format"); y+= 25;
    dialog->c->menu(versionmenu);
    dialog->c->align(FL_ALIGN_RIGHT);
    dialog->b = new Fl_Check_Button(10, y, 180, 25, "Save all elements"); y += 25;
    dialog->b->type(FL_TOGGLE_BUTTON);
    dialog->b->down_box(GMSH_TOGGLE_BOX);
    dialog->b->selection_color(GMSH_TOGGLE_COLOR);
    dialog->ok = new Fl_Return_Button(10, y+10, 85, 25, "OK");
    dialog->cancel = new Fl_Button(105, y+10, 85, 25, "Cancel");
    dialog->window->set_modal();
    dialog->window->end();
    dialog->window->hotspot(dialog->window);
  }
  
  dialog->c->value((CTX.mesh.msh_file_version==1.0) ? 0 : 1);
  dialog->b->value(CTX.mesh.save_all);
  dialog->window->show();

  while(dialog->window->shown()){
    Fl::wait();
    for (;;) {
      Fl_Widget* o = Fl::readqueue();
      if (!o) break;
      if (o == dialog->ok) {
	CTX.mesh.msh_file_version = dialog->c->value() + 1;
	CTX.mesh.save_all = dialog->b->value();
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
