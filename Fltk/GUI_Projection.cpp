#include "Gmsh.h"
#include "GmshUI.h"
#include "GModel.h"
#include "projectionFace.h"
#include "Draw.h"
#include "Options.h"
#include "Context.h"
#include "GUI.h"
#include "Shortcut_Window.h"

extern GModel *GMODEL;
extern Context_T CTX;

int projection_editor(char *title, projectionFace *p)
{
  struct _editor{
    Fl_Window *window;
    Fl_Value_Input *scale[3], *rotation[3], *translation[3];
    Fl_Button *cancel, *print;
  };
  static _editor *editor = 0;

  const int BH = 2 * GetFontSize() + 1;
  const int BB = 7 * GetFontSize();
  const int WB = 7;
  
  SBoundingBox3d bounds = GMODEL->bounds();

  if(!editor){
    editor = new _editor;
    editor->window = new Dialog_Window(2 * BB + 3 * WB, 10 * BH + 3 * WB);

    editor->scale[0] = new Fl_Value_Input(WB, WB, BB, BH, "Scale Factor X");
    editor->scale[1] = new Fl_Value_Input(WB, WB + BH, BB, BH, "Scale Factor Y");
    editor->scale[2] = new Fl_Value_Input(WB, WB + 2 * BH, BB, BH, "Scale Factor Z");
    for(int i = 0; i < 3; i++){
      editor->scale[i]->align(FL_ALIGN_RIGHT);
      editor->scale[i]->maximum(CTX.lc * 10.);
      editor->scale[i]->minimum(CTX.lc / 100.);
      editor->scale[i]->step(CTX.lc / 100.);
    }

    editor->rotation[0] = new Fl_Value_Input(WB, WB + 3*BH, BB, BH, "Rotation X");
    editor->rotation[1] = new Fl_Value_Input(WB, WB + 4*BH, BB, BH, "Rotation Y");
    editor->rotation[2] = new Fl_Value_Input(WB, WB + 5*BH, BB, BH, "Rotation Z");
    for(int i = 0; i < 3; i++){
      editor->rotation[i]->align(FL_ALIGN_RIGHT);
      editor->rotation[i]->maximum(-180.);
      editor->rotation[i]->minimum(180.);
      editor->rotation[i]->step(0.1);
    }

    editor->translation[0] = new Fl_Value_Input(WB, WB + 6*BH, BB, BH, "Translation X");
    editor->translation[1] = new Fl_Value_Input(WB, WB + 7*BH, BB, BH, "Translation Y");
    editor->translation[2] = new Fl_Value_Input(WB, WB + 8*BH, BB, BH, "Translation Z");
    for(int i = 0; i < 3; i++){
      editor->translation[i]->align(FL_ALIGN_RIGHT);    
      editor->translation[i]->maximum(bounds.max()[i] + CTX.lc);
      editor->translation[i]->minimum(bounds.min()[i] - CTX.lc);
      editor->translation[i]->step(CTX.lc / 100.);
    }

    editor->print = new Fl_Button(WB , 2 * WB + 9 * BH, BB, BH, "Print");
    editor->cancel = new Fl_Button(2 * WB + BB, 2 * WB + 9 * BH, BB, BH, "Cancel");

    editor->window->end();
    editor->window->hotspot(editor->window);
  }
  
  editor->window->label(title);
  for(int i = 0; i < 3; i++){
    editor->scale[i]->value(CTX.lc);
    editor->rotation[i]->value(0.);
    editor->translation[i]->value(0.5 * (bounds.max()[i] + bounds.min()[i]));
  }

  p->setScale(SVector3(editor->scale[0]->value(),
		       editor->scale[1]->value(),
		       editor->scale[2]->value()));
  p->setRotation(SVector3(editor->rotation[0]->value(),
			  editor->rotation[1]->value(),
			  editor->rotation[2]->value()));
  p->setTranslation(SVector3(editor->translation[0]->value(),
			     editor->translation[1]->value(),
			     editor->translation[2]->value()));
  Draw();

  editor->window->show();

  while(editor->window->shown()){
    Fl::wait();
    for (;;) {
      Fl_Widget* o = Fl::readqueue();
      if(!o) break;
      if(o == editor->window || o == editor->cancel){
	editor->window->hide();
      	return 0;
      }
      else if(o == editor->print){
	for(int i = 0; i < 3; i++) printf("%g\n", editor->scale[i]->value());
	for(int i = 0; i < 3; i++) printf("%g\n", editor->rotation[i]->value());
	for(int i = 0; i < 3; i++) printf("%g\n", editor->translation[i]->value());
      }
      else{
	p->setScale(SVector3(editor->scale[0]->value(),
			     editor->scale[1]->value(),
			     editor->scale[2]->value()));
	p->setRotation(SVector3(editor->rotation[0]->value(),
				editor->rotation[1]->value(),
				editor->rotation[2]->value()));
	p->setTranslation(SVector3(editor->translation[0]->value(),
				   editor->translation[1]->value(),
				   editor->translation[2]->value()));
      }
      Draw();
    }
  }
  return 0;
}

void mesh_parameterize_cb(Fl_Widget* w, void* data)
{
  projectionFace *p = new parabolicCylinder(GMODEL, 10000);

  GMODEL->add(p);

  CTX.mesh.changed = ENT_SURFACE;

  opt_geometry_surfaces(0, GMSH_SET | GMSH_GUI, 1);
 
  Draw();
  
  projection_editor("Projection editor", p);

  Msg(INFO, "Model added: %d faces", GMODEL->numFace());
}
