#include "Gmsh.h"
#include "GmshUI.h"
#include "GModel.h"
#include "projectionFace.h"
#include "Draw.h"
#include "Context.h"

#include "Shortcut_Window.h"

#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Value_Slider.H>

extern GModel *GMODEL;
extern Context_T CTX;

int projection_editor(char *title, double &a, double &b, double &c)
{
  struct _editor{
    Fl_Window *window;
    Fl_Value_Slider *sa, *sb, *sc;
    Fl_Button *cancel;
  };
  static _editor *editor = 0;

  const int BH = 2 * CTX.fontsize + 1;
  const int BB = 7 * CTX.fontsize;
  const int WB = 7;

  if(!editor){
    editor = new _editor;
    editor->window = new Dialog_Window(2 * BB + 3 * WB, 4 * BH + 3 * WB);
    editor->sa = new Fl_Value_Slider(WB, WB, BB, BH, "blabla");
    editor->sa->type(FL_HOR_SLIDER);
    editor->sa->align(FL_ALIGN_RIGHT);
    editor->sb = new Fl_Value_Slider(WB, WB + BH, BB, BH, "blibli");
    editor->sb->type(FL_HOR_SLIDER);
    editor->sb->align(FL_ALIGN_RIGHT);
    editor->sc = new Fl_Value_Slider(WB, WB + 2 * BH, BB, BH, "blublu");
    editor->sc->type(FL_HOR_SLIDER);
    editor->sc->align(FL_ALIGN_RIGHT);
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

      Draw();

      if (o == editor->sa)
	a = editor->sa->value();
      if (o == editor->sb)
	b = editor->sb->value();
      if (o == editor->sc)
	c = editor->sc->value();
      if (o == editor->window || o == editor->cancel){
	editor->window->hide();
	return 0;
      }
    }
  }
  return 0;
}

void mesh_parameterize_cb(Fl_Widget* w, void* data)
{
  projectionFace *p = new parabolicCylinder(GMODEL,10000);

  GMODEL->add( p );

  CTX.mesh.changed = ENT_SURFACE;
  CTX.geom.surfaces = 1;
  
  double a=0., b=0., c=0.;
  projection_editor("Projection editor", a, b, c);

  Draw();

  //SBoundingBox3d bb = GMODEL->bounds();

  Msg(INFO, "Model added: %d faces", GMODEL->numFace());
}
