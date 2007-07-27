#include "Draw.h"
#include "Options.h"
#include "Context.h"
#include "SelectBuffer.h"
#include "GUI_Projection.h"

extern GModel *GMODEL;
extern Context_T CTX;

#if defined(HAVE_FOURIER_MODEL)

static double currentParams[9];

void uvPlot::draw()
{
  // draw background
  fl_color(FL_WHITE);
  fl_rectf(0, 0, w(), h());

  // draw points
  fl_color(FL_BLACK);
  if(_u.size() != _v.size()) return;
  for(unsigned int i = 0; i < _u.size(); i++){
    int x = (int)(_u[i] * w());
    int y = (int)(_v[i] * h());
    fl_rect(x, y, 3, 3);
  }

  fl_font(FL_HELVETICA, 14);
  fl_draw("Hello", w() / 2, h() / 2);
}

projection::projection(FProjectionFace *f, int x, int y, int w, int h, int BB, int BH, 
		       projectionEditor *e) 
  : face(f)
{
  group = new Fl_Scroll(x, y, w, h);
  SBoundingBox3d bounds = GMODEL->bounds();
  ProjectionSurface *ps = f->GetProjectionSurface();
  for(int i = 0; i < ps->GetNumParameters() + 9; i++){
    Fl_Value_Input *v = new Fl_Value_Input(x, y + i * BH, BB, BH);

    ps->GetScale(currentParams[0],currentParams[1],currentParams[2]);
    ps->GetOrigin(currentParams[6],currentParams[7],currentParams[8]);

    if(i < 3){ // scaling
      v->maximum(CTX.lc * 10.);
      v->minimum(CTX.lc / 100.);
      v->step(CTX.lc / 100.);
      v->label((i == 0) ? "X scale" : (i == 1) ? "Y scale" : "Z scale");
      v->value(currentParams[i]);
    }
    else if(i < 6){ //rotation
      currentParams[i] = 0.;
      v->maximum(-180.);
      v->minimum(180.);
      v->step(0.1);
      v->label((i == 3) ? "X rotation" : (i == 4) ? "Y rotation" : 
	       "Z rotation");
      v->value(currentParams[i]);
    }
    else if(i < 9){ // translation
      v->maximum(bounds.max()[i] + 10. * CTX.lc);
      v->minimum(bounds.min()[i] - 10. * CTX.lc);
      v->step(CTX.lc / 100.);
      v->label((i == 6) ? "X translation" : (i == 7) ? "Y translation" : 
	       "Z translation");
      //v->value(currentParams[i]);
      v->value(bounds.center()[i]);
    }
    else{ // other parameters
      v->maximum(10. * CTX.lc);
      v->minimum(-10. * CTX.lc);
      v->step(CTX.lc / 100.);
      v->label("My nice label");
      v->value(ps->GetParameter(i - 9));
      v->value(currentParams[i]);
    }
    v->align(FL_ALIGN_RIGHT);
    v->callback(update_cb, e);
    parameters.push_back(v);
  }
  group->end();
  group->hide();
}

projectionEditor::projectionEditor(std::vector<FProjectionFace*> &faces) 
{
  // construct GUI in terms of standard sizes
  const int BH = 2 * GetFontSize() + 1, BB = 7 * GetFontSize(), WB = 7;
  const int width = (int)(3.5 * BB), height = 18 * BH;
  
  // create all widgets (we construct this once, we never deallocate!)
  _window = new Dialog_Window(width, height, "Reparameterize");
  
  new Fl_Box(WB, WB + BH, BB / 2, BH, "Select:");
  
  Fl_Group *o = new Fl_Group(WB, WB, 2 * BB, 3 * BH);
  _select[0] = 
    new Fl_Round_Button(2 * WB + BB / 2, WB, BB, BH, "Points");
  _select[0]->value(1);
  _select[1] = 
    new Fl_Round_Button(2 * WB + BB / 2, WB + BH, BB, BH, "Elements");
  _select[2] = 
    new Fl_Round_Button(2 * WB + BB / 2, WB + 2 * BH, BB, BH, "Surfaces");
  for(int i = 0; i < 3; i++){
    _select[i]->callback(select_cb, this);
    _select[i]->type(FL_RADIO_BUTTON);
  }
  o->end();
  
  Fl_Toggle_Button *b1 = new Fl_Toggle_Button
    (width - WB - 3 * BB / 2, WB, 3 * BB / 2, BH, "Hide unselected");
  b1->callback(hide_cb);
  
  Fl_Button *b2 = new Fl_Button
    (width - WB - 3 * BB / 2, WB + BH, 3 * BB / 2, BH, "Save selection");
  b2->callback(save_cb, this);

  const int brw = (int)(1.25 * BB);

  _browser = new Fl_Hold_Browser(WB, 2 * WB + 3 * BH, brw, 5 * BH);
  _browser->callback(browse_cb, this);
  for(unsigned int i = 0; i < faces.size(); i++){
    ProjectionSurface *ps = faces[i]->GetProjectionSurface();
    _browser->add(ps->GetName().c_str());
    _projections.push_back
      (new projection(faces[i], 2 * WB + brw, 2 * WB + 3 * BH, 
		      width - 3 * WB - brw, 5 * BH, BB, BH, this));
  }
  
  _uvPlot = 
    new uvPlot(WB, 3 * WB + 8 * BH, width - 2 * WB, height - 5 * WB - 9 * BH);
  _uvPlot->end();

  Fl_Button *b3 = new Fl_Button(width - 2 * WB - 2 * BB, height - WB - BH, 
				BB, BH, "Compute");
  b3->callback(compute_cb, this);

  Fl_Button *b4 = new Fl_Button(width - WB - BB, height - WB - BH,
				BB, BH, "Cancel");
  b4->callback(close_cb, _window);
  
  _window->end();
  _window->hotspot(_window);
  _window->resizable(_uvPlot);
  _window->size_range(width, (int)(0.75 * height));
}

int projectionEditor::getSelectionMode() 
{ 
  if(_select[0]->value())
    return ENT_POINT;
  else if(_select[2]->value())
    return ENT_SURFACE;
  return ENT_ALL;
}

projection *projectionEditor::getCurrentProjection()
{
  for(int i = 1; i <= _browser->size(); i++)
    if(_browser->selected(i)) return _projections[i - 1];
  return 0;
}

void browse_cb(Fl_Widget *w, void *data)
{
  projectionEditor *e = (projectionEditor*)data;

  std::vector<projection*> &projections(e->getProjections());
  for(unsigned int i = 0; i < projections.size(); i++){
    projections[i]->face->setVisibility(false);
    projections[i]->group->hide();
  }
  
  /*
<<<<<<< GUI_Projection.cpp
  for(int i = 0; i < MAX_PROJECTION_PARAMETERS; i++)  
    e->getValueInput(i)->hide();

  FProjectionFace *f = e->getCurrentProjectionFace();
  if(f){
    f->setVisibility(true);
    ProjectionSurface *ps = f->GetProjectionSurface();
    for(int i = 0; i < 9; i++){
      e->getValueInput(i)->show();
      ps->GetScale(currentParams[0],currentParams[1],currentParams[2]);
      ps->GetOrigin(currentParams[6],currentParams[7],currentParams[8]);
      if(i < 3){ // scaling
	e->getValueInput(i)->maximum(CTX.lc * 10.);
	e->getValueInput(i)->minimum(CTX.lc / 100.);
	e->getValueInput(i)->step(CTX.lc / 100.);
	e->getValueInput(i)->
	  label((i == 0) ? "X scale" : (i == 1) ? "Y scale" : "Z scale");
	e->getValueInput(i)->value(currentParams[i]);
      }
      else if(i < 6){ //rotation
	currentParams[i] = 0.;
	e->getValueInput(i)->maximum(180.);
	e->getValueInput(i)->minimum(-180.);
	e->getValueInput(i)->step(0.1);
	e->getValueInput(i)->
	  label((i == 3) ? "X Rotation" : (i == 4) ? "Y Rotation" : 
		"Z Rotation");
	e->getValueInput(i)->value(currentParams[i]);
      }
      else{ // translation
	e->getValueInput(i)->maximum(bounds.max()[i] + CTX.lc);
	e->getValueInput(i)->minimum(bounds.min()[i] - CTX.lc);
	e->getValueInput(i)->step(( CTX.lc) / 100.);
	e->getValueInput(i)->
	  label((i == 6) ? "X Translation" : (i == 7) ? "Y Translation" : 
		"Z Translation");
	e->getValueInput(i)->value(currentParams[i]);
      }
    }
    for(int i = 9; i < 9 + ps->GetNumParameters(); i++){
      currentParams[i] = ps->GetParameter(i - 9);
      e->getValueInput(i)->show();
      e->getValueInput(i)->maximum(10. * CTX.lc);
      e->getValueInput(i)->minimum(-10. * CTX.lc);
      e->getValueInput(i)->step(CTX.lc / 100.);
      e->getValueInput(i)->label("My nice label");
      e->getValueInput(i)->value(currentParams[i]);
    }
=======
  */

  projection *p = e->getCurrentProjection();
  if(p){
    p->face->setVisibility(true);
    p->group->show();


    // >>>>>>> 1.12

  }
  Draw();
}

void update_cb(Fl_Widget *w, void *data)
{
  projectionEditor *e = (projectionEditor*)data;

  // get all parameters from GUI and modify projection surface accordingly

  projection *p = e->getCurrentProjection();
  if(p){
    ProjectionSurface *ps = p->face->GetProjectionSurface();
    ps->Rescale(p->parameters[0]->value() / currentParams[0],
		p->parameters[1]->value() / currentParams[1],
		p->parameters[2]->value() / currentParams[2]);
    ps->Rotate(p->parameters[3]->value() - currentParams[3],
	       p->parameters[4]->value() - currentParams[4],
	       p->parameters[5]->value() - currentParams[5]);
    ps->Translate(p->parameters[6]->value() - currentParams[6],
		  p->parameters[7]->value() - currentParams[7],
		  p->parameters[8]->value() - currentParams[8]);
    for (int i = 9; i < 9 + ps->GetNumParameters(); i++)
      ps->SetParameter(i - 9, p->parameters[i]->value() - currentParams[i]);

    Draw();
    for (int i = 0; i < 9; i++)
      currentParams[i] = p->parameters[i]->value();
}

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
  std::vector<FProjectionFace*> faces;
  if(faces.empty()){
    faces.push_back(new FProjectionFace
		    (GMODEL, 10000, new CylindricalProjectionSurface(0)));
    faces.push_back(new FProjectionFace
		    (GMODEL, 10001, new RevolvedParabolaProjectionSurface(1)));
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

#else

void mesh_parameterize_cb(Fl_Widget* w, void* data)
{
  Msg(GERROR, "You must compile FourierModel to reparameterize meshes");
}

#endif
