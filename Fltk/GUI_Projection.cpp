#include "Draw.h"
#include "Options.h"
#include "Context.h"
#include "SelectBuffer.h"
#include "GUI_Projection.h"

extern GModel *GMODEL;
extern Context_T CTX;

void uvPlot::draw()
{
  // draw background
  fl_color(FL_WHITE);
  fl_rectf(0, 0, w(), h());

  // draw points
  fl_color(FL_BLACK);
  if(_u.size() != _v.size()) return;
  for(unsigned int i = 0; i < _u.size(); i++)
    fl_rect(_u[i] * w(), _v[i] * h(), 3, 3);

  fl_font(FL_HELVETICA, 14);
  fl_draw("Hello", w() / 2, h() / 2);
}

projectionEditor::projectionEditor(std::vector<projectionFace*> &faces) 
  : _faces(faces)
{
  // construct GUI in terms of standard sizes
  const int BH = 2 * GetFontSize() + 1, BB = 7 * GetFontSize(), WB = 7;
  const int width = 3.5 * BB, height = 18 * BH;
  
  // create all widgets (we construct this once, we never deallocate!)
  _window = new Dialog_Window(width, height, "Reparameterize");
  
  new Fl_Box(WB, WB + BH, 0.5 * BB, BH, "Select:");

  Fl_Group *o = new Fl_Group(WB, WB, 2 * BB, 3 * BH);
  _select[0] = new Fl_Round_Button(2 * WB + 0.5 * BB, WB, BB, BH, "Points");
  _select[0]->value(1);
  _select[1] = new Fl_Round_Button(2 * WB + 0.5 * BB, WB + BH, BB, BH, "Elements");
  _select[2] = new Fl_Round_Button(2 * WB + 0.5 * BB, WB + 2 * BH, BB, BH, "Surfaces");
  for(int i = 0; i < 3; i++){
    _select[i]->callback(select_cb, this);
    _select[i]->type(FL_RADIO_BUTTON);
  }
  o->end();
  
  Fl_Toggle_Button *b1 = 
    new Fl_Toggle_Button(width - WB - 1.5 * BB, WB, 1.5 * BB, BH, "Hide unselected");
  b1->callback(hide_cb);

  Fl_Button *b2 = 
    new Fl_Button(width - WB - 1.5 * BB, WB + BH, 1.5 * BB, BH, "Save selection");
  b2->callback(save_cb, this);

  _browser = new Fl_Hold_Browser(WB, 2 * WB + 3 * BH, BB, 5 * BH);
  _browser->callback(browse_cb, this);
  for(unsigned int i = 0; i < _faces.size(); i++){
    _browser->add("test");
  }

  Fl_Scroll *s = new Fl_Scroll(2 * WB + BB, 2 * WB + 3 * BH, width - 3 * WB - BB, 5 * BH);
  for(int i = 0; i < 20; i++){
    _input[i] = new Fl_Value_Input(2 * WB + BB, 2 * WB + (i + 3) * BH, BB, BH);
    _input[i]->align(FL_ALIGN_RIGHT);
    _input[i]->callback(update_cb, this);
    _input[i]->minimum(0.);
    _input[i]->maximum(1.);
    _input[i]->step(0.01);
    //_input[i]->hide();
  }
  s->end();

  _uvPlot = new uvPlot(WB, 3 * WB + 8 * BH, width - 2 * WB, height - 5 * WB - 9 * BH);
  _uvPlot->end();

  Fl_Button *b3 = 
    new Fl_Button(width - 2 * WB - 2 * BB, height - WB - BH, BB, BH, "Compute");
  b3->callback(compute_cb, this);

  Fl_Button *b4 = 
    new Fl_Button(width - WB - BB, height - WB - BH, BB, BH, "Cancel");
  b4->callback(close_cb, _window);

  _window->end();
  _window->hotspot(_window);
  _window->resizable(_uvPlot);
  _window->size_range(width, 0.75 * height);
}

int projectionEditor::getSelectionMode() 
{ 
  if(_select[0]->value())
    return ENT_POINT;
  else if(_select[2]->value())
    return ENT_SURFACE;
  return ENT_ALL;
}

void browse_cb(Fl_Widget *w, void *data)
{
  projectionEditor *e = (projectionEditor*)data;
  SBoundingBox3d bounds = GMODEL->bounds();

  // change active projection face 
  //e->face()->setVisibility(true);

  // set and show parameters accordingly

}

void update_cb(Fl_Widget *w, void *data)
{
  projectionEditor *e = (projectionEditor*)data;

  // get all parameters from GUI and modify projection surface accordingly

  // project all selected points and update u,v display
  std::vector<double> u, v;
  for(int i = 0; i < 5000; i++){
    u.push_back((double)rand() / (double)RAND_MAX);
    v.push_back((double)rand() / (double)RAND_MAX);
  }
  e->uv()->fill(u, v);
}

void select_cb(Fl_Widget *w, void *data)
{
  projectionEditor *e = (projectionEditor*)data;

  int what = e->getSelectionMode();
  char *str;

  switch(what){
  case ENT_ALL: CTX.pick_elements = 1; str = "Elements"; break;
  case ENT_POINT: CTX.pick_elements = 0; str = "Points"; break;
  case ENT_SURFACE: CTX.pick_elements = 0; str = "Surfaces"; break;
  default: return;
  }

  std::vector<GVertex*> vertices;
  std::vector<GEdge*> edges;
  std::vector<GFace*> faces;
  std::vector<GRegion*> regions;
  std::vector<MElement*> elements;

  std::vector<MElement*> &ele(e->getElements());
  std::vector<GEntity*> &ent(e->getEntities());

  while(1) {
    CTX.mesh.changed = ENT_ALL;
    Draw();

    if(ele.size() || ent.size())
      Msg(ONSCREEN, "Select %s\n"
	  "[Press 'e' to end selection, 'u' to undo last selection or 'q' to abort]", str);
    else
      Msg(ONSCREEN, "Select %s\n"
	  "[Press 'e' to end selection or 'q' to abort]", str);

    char ib = SelectEntity(what, vertices, edges, faces, regions, elements);
    if(ib == 'l') {
      if(CTX.pick_elements){
	for(unsigned int i = 0; i < elements.size(); i++){
	  if(elements[i]->getVisibility() != 2){
	    elements[i]->setVisibility(2); ele.push_back(elements[i]);
	  }
	}
      }
      else{
	for(unsigned int i = 0; i < vertices.size(); i++){
	  if(vertices[i]->getSelection() != 1){
	    vertices[i]->setSelection(1); ent.push_back(vertices[i]);
	  }
	}
	for(unsigned int i = 0; i < faces.size(); i++){
	  if(faces[i]->getSelection() != 1){
	    faces[i]->setSelection(1); ent.push_back(faces[i]);
	  }
	}
      }
    }
    if(ib == 'r') {
      if(CTX.pick_elements){
	for(unsigned int i = 0; i < elements.size(); i++)
	  elements[i]->setVisibility(1);
      }
      else{
	for(unsigned int i = 0; i < vertices.size(); i++)
	  vertices[i]->setSelection(0);
	for(unsigned int i = 0; i < faces.size(); i++)
	  faces[i]->setSelection(0);
      }
    }
    if(ib == 'u') {
      if(CTX.pick_elements){
	if(ele.size()){
	  ele[ele.size() - 1]->setVisibility(1);
	  ele.pop_back();
	}
      }
      else{
	if(ent.size()){
	  ent[ent.size() - 1]->setSelection(0);
	  ent.pop_back();
	}
      }
    }
    if(ib == 'e') {
      ZeroHighlight();
      ele.clear();
      ent.clear();
    }
    if(ib == 'q') {
      ZeroHighlight();
      break;
    }
  }

  CTX.mesh.changed = ENT_ALL;
  CTX.pick_elements = 0;
  Draw();  
  Msg(ONSCREEN, "");
}

void close_cb(Fl_Widget *w, void *data)
{
  if(data) ((Fl_Window *) data)->hide();
}

void hide_cb(Fl_Widget *w, void *data)
{
  CTX.hide_unselected = !CTX.hide_unselected;
  CTX.mesh.changed = ENT_ALL;
  Draw();
}

void save_cb(Fl_Widget *w, void *data)
{
  projectionEditor *e = (projectionEditor*)data;

  std::vector<GEntity*> &ent(e->getEntities());
  for(unsigned int i = 0; i < ent.size(); i++){
    printf("entity %d\n", ent[i]->tag());
  }

  std::vector<MElement*> &ele(e->getElements());
  for(unsigned int i = 0; i < ele.size(); i++){
    printf("element %d\n", ele[i]->getNum());
  }
}

void compute_cb(Fl_Widget *w, void *data)
{
  projectionEditor *e = (projectionEditor*)data;

  Msg(GERROR, "Compute!");
}

void mesh_parameterize_cb(Fl_Widget* w, void* data)
{
  // display geometry surfaces
  opt_geometry_surfaces(0, GMSH_SET | GMSH_GUI, 1);

  // create one instance of each available projection surface
  std::vector<projectionFace*> faces;
  if(faces.empty()){
    faces.push_back(new parabolicCylinder(GMODEL, 10000));
    faces.push_back(new parabolicCylinder(GMODEL, 10001));
  }

  // make each projection surface invisible and 
  for(unsigned int i = 0; i < faces.size(); i++){
    faces[i]->setVisibility(false);
    GMODEL->add(faces[i]);
  }
 
  // launch editor
  static projectionEditor *editor = 0;
  if(!editor) editor = new projectionEditor(faces);
  editor->show();
}
