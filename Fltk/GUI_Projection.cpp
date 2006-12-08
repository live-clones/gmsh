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

int projection_editor(char *title, projectionFace *p)
{
  
  struct _editor{
    Fl_Window *window;
    Fl_Value_Slider *sa, *sb, *sc, *ra, *rb, *rc, *ta, *tb, *tc;
    Fl_Button *cancel;
  };
  static _editor *editor = 0;

  const int BH = 2 * CTX.fontsize + 1;
  const int BB = 7 * CTX.fontsize;
  const int WB = 7;
  
  SBoundingBox3d bounds = GMODEL->bounds();

  if(!editor){
    editor = new _editor;
    editor->window = new Dialog_Window(2 * BB + 3 * WB, 10 * BH + 3 * WB);

    editor->sa = new Fl_Value_Slider(WB, WB, BB, BH, "Scale Factor X");
    editor->sa->type(FL_HOR_SLIDER);
    editor->sa->align(FL_ALIGN_RIGHT);
    editor->sa->maximum( bounds.max()[0] + 1 );
    editor->sa->minimum(.1);
    editor->sb = new Fl_Value_Slider(WB, WB + BH, BB, BH, "Scale Factor Y");
    editor->sb->type(FL_HOR_SLIDER);
    editor->sb->align(FL_ALIGN_RIGHT);
    editor->sb->maximum( bounds.max()[1] + 1 );
    editor->sb->minimum(.1);
    editor->sc = new Fl_Value_Slider(WB, WB + 2 * BH, BB, BH, "Scale Factor Z");
    editor->sc->type(FL_HOR_SLIDER);
    editor->sc->align(FL_ALIGN_RIGHT);
    editor->sc->maximum( bounds.max()[2] + 1 );
    editor->sc->minimum(.1);

    editor->ra = new Fl_Value_Slider(WB, WB + 3*BH, BB, BH, "Rotation X");
    editor->ra->type(FL_HOR_SLIDER);
    editor->ra->align(FL_ALIGN_RIGHT);
    editor->ra->maximum(360);
    editor->ra->minimum(0);

    editor->rb = new Fl_Value_Slider(WB, WB + 4*BH, BB, BH, "Rotation Y");
    editor->rb->type(FL_HOR_SLIDER);
    editor->rb->align(FL_ALIGN_RIGHT);
    editor->rb->maximum(360);
    editor->rb->minimum(0);

    editor->rc = new Fl_Value_Slider(WB, WB + 5*BH, BB, BH, "Rotation Z");
    editor->rc->type(FL_HOR_SLIDER);
    editor->rc->align(FL_ALIGN_RIGHT);
    editor->rc->maximum(360);
    editor->rc->minimum(0);

    editor->ta = new Fl_Value_Slider(WB, WB + 6*BH, BB, BH, "Translation X");
    editor->ta->type(FL_HOR_SLIDER);
    editor->ta->align(FL_ALIGN_RIGHT);
    editor->ta->maximum( bounds.max()[0] + 2 );
    editor->ta->minimum( bounds.min()[0] - 2 );

    editor->tb = new Fl_Value_Slider(WB, WB + 7*BH, BB, BH, "Translation Y");
    editor->tb->type(FL_HOR_SLIDER);
    editor->tb->align(FL_ALIGN_RIGHT);
    editor->tb->maximum( bounds.max()[1] + 2 );
    editor->tb->minimum( bounds.min()[1] - 2 );

    editor->tc = new Fl_Value_Slider(WB, WB + 8*BH, BB, BH, "Translation Z");
    editor->tc->type(FL_HOR_SLIDER);
    editor->tc->align(FL_ALIGN_RIGHT);    
    editor->tc->maximum( bounds.max()[2] + 2 );
    editor->tc->minimum( bounds.min()[2] - 2 );

    editor->cancel = new Fl_Button(2 * WB + BB, 2 * WB + 9 * BH, BB, BH, "Cancel");
    editor->window->end();
    editor->window->hotspot(editor->window);
  }
  
  editor->window->label(title);
  editor->sa->value( (bounds.max()[0] + bounds.min()[0])/2 );
  editor->sb->value( (bounds.max()[1] + bounds.min()[1])/2 );  
  editor->sc->value( (bounds.max()[2] + bounds.min()[2])/2 );
  editor->ra->value(0);
  editor->rb->value(0);
  editor->rc->value(0);
  editor->ta->value( (bounds.max()[0] + bounds.min()[0])/2 );
  editor->tb->value( (bounds.max()[1] + bounds.min()[1])/2 );
  editor->tc->value( (bounds.max()[2] + bounds.min()[2])/2 );

        SVector3 rescale(editor->sa->value(),editor->sb->value(),editor->sc->value());
        p->setScale(rescale);
        SVector3 rerot(editor->ra->value(),editor->rb->value(),editor->rc->value());
        p->setRotation(rerot);   
        SVector3 retrans(editor->ta->value(),editor->tb->value(),editor->tc->value());
        p->setTranslation(retrans);         
      
  Draw();


  editor->window->show();

  while(editor->window->shown()){
    Fl::wait();
    for (;;) {
      Fl_Widget* o = Fl::readqueue();
      if (!o) break;

 /*     if (o == editor->sa)
        SVector3 rescale(editor->sa->value(),0,0);
	      p->scale(rescale);
      if (o == editor->sb)
        SVector3 rescale(editor->sa->value(),0,0);
	      p->scale(rescale);
      if (o == editor->sc)
        SVector3 rescale(editor->sa->value(),0,0);
	      p->scale(rescale);
  */
      if (o == editor->window || o == editor->cancel)
      {
	      editor->window->hide();
      	return 0;
      }
      else
      {
        SVector3 rescale(editor->sa->value(),editor->sb->value(),editor->sc->value());
        p->setScale(rescale);

        SVector3 rerot(editor->ra->value(),editor->rb->value(),editor->rc->value());
        p->setRotation(rerot);   

        SVector3 retrans(editor->ta->value(),editor->tb->value(),editor->tc->value());
        p->setTranslation(retrans);     
      }
      
      Draw();

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
  
  Draw();
  
  projection_editor("Projection editor", p);


  //SBoundingBox3d bb = GMODEL->bounds();

  Msg(INFO, "Model added: %d faces", GMODEL->numFace());
}
