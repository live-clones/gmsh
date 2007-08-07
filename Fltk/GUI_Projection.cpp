#include "GModelIO_F.h"
#include "Draw.h"
#include "Options.h"
#include "Context.h"
#include "SelectBuffer.h"
#include "GUI_Projection.h"
#include "GUI_Extras.h"
#include "FFace.h"

extern GModel *GMODEL;
extern Context_T CTX;

#if defined(HAVE_FOURIER_MODEL)

#include "FPatch.h"
#include "PlaneProjectionSurface.h"
#include "ParaboloidProjectionSurface.h"
#include "CylindricalProjectionSurface.h"
#include "RevolvedParabolaProjectionSurface.h"

static FProjectionFace *createProjectionFaceFromName(char *name)
{
  int tag = GMODEL->numFace() + 1;
  FProjectionFace *f = 0;
  if(!strcmp(name, "plane"))
    f = new FProjectionFace(GMODEL, tag, new PlaneProjectionSurface(tag));
  else if(!strcmp(name, "paraboloid"))
    f = new FProjectionFace(GMODEL, tag, new ParaboloidProjectionSurface(tag));
  else if(!strcmp(name, "Cylinder"))
    f = new FProjectionFace(GMODEL, tag, new CylindricalProjectionSurface(tag));
  else if(!strcmp(name, "revolvedParabola"))
    f = new FProjectionFace(GMODEL, tag, new RevolvedParabolaProjectionSurface(tag));
  else
    Msg(GERROR, "Unknown projection face `%s'", name);
  if(f){
    f->setVisibility(false);
    GMODEL->add(f);
  }
  return f;
}

uvPlot::uvPlot(int x, int y, int w, int h, const char *l)
  : Fl_Window(x, y, w, h, l), _dmin(0.), _dmax(0.)
{
  ColorTable_InitParam(2, &_colorTable);
  ColorTable_Recompute(&_colorTable);
}

void uvPlot::set(std::vector<double> &u, std::vector<double> &v, 
		 std::vector<double> &dist, std::vector<std::complex<double> > &f)
{ 
  _u = u; 
  _v = v;
  _dist = dist;
  _f = f;
  if(dist.empty()){
    _dmin = _dmax = 0.;
  }
  else{
    _dmin = _dmax = dist[0];
    for(unsigned int i = 1; i < dist.size(); i++){
      _dmin = std::min(_dmin, dist[i]);
      _dmax = std::max(_dmax, dist[i]);
    }
  }
  redraw();
}

void uvPlot::color(double d)
{
  int index;
  if(_dmin == _dmax)
    index = _colorTable.size / 2;
  else
    index = (int)((d - _dmin) * (_colorTable.size - 1) / (_dmax - _dmin));
  unsigned int color = _colorTable.table[index];
  int r = CTX.UNPACK_RED(color);
  int g = CTX.UNPACK_GREEN(color);
  int b = CTX.UNPACK_BLUE(color);
  fl_color(r, g, b);
}

void uvPlot::draw()
{
  // draw background
  fl_color(FL_WHITE);
  fl_rectf(0, 0, w(), h());

  // draw points in u,v space, colored by their distance to the
  // projection surface
  int pw = w();
  int ph = h() - (2 * GetFontSize() + 5);
  for(unsigned int i = 0; i < _u.size(); i++){
    int x = (int)(_u[i] * pw);
    int y = (int)(_v[i] * ph);
    color(_dist[i]);
    fl_rect(x, y, 3, 3);
  }

  // draw color bar
  for(int i = 0; i < w(); i++){
    int index = (int)(i * (_colorTable.size - 1) / w());
    unsigned int color = _colorTable.table[index];
    int r = CTX.UNPACK_RED(color);
    int g = CTX.UNPACK_GREEN(color);
    int b = CTX.UNPACK_BLUE(color);
    fl_color(r, g, b);
    fl_line(i, ph, i, ph + 10);
  }

  // draw labels
  fl_color(FL_BLACK);
  fl_font(FL_HELVETICA, GetFontSize());
  static char min[256], max[256], pts[256];
  sprintf(min, "%g", _dmin);
  sprintf(max, "%g", _dmax);
  sprintf(pts, "[%d pts]", _u.size());
  fl_draw(min, 5, h() - 5);
  fl_draw(pts, pw / 2 - (int)fl_width(pts) / 2, h() - 5);
  fl_draw(max, pw - (int)fl_width(max) - 5, h() - 5);
}

projection::projection(FProjectionFace *f, int x, int y, int w, int h, int BB, int BH, 
		       projectionEditor *e) 
  : face(f)
{
  group = new Fl_Scroll(x, y, w, h);
  SBoundingBox3d bounds = GMODEL->bounds();
  ProjectionSurface *ps = f->GetProjectionSurface();
  currentParams = new double[ps->GetNumParameters() + 9];
  for(int i = 0; i < ps->GetNumParameters() + 9; i++){
    Fl_Value_Input *v = new Fl_Value_Input(x, y + i * BH, BB, BH);
    if(i < 3){ // scaling
      currentParams[i] = 1.;
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
      v->label((i == 3) ? "X rotation" : (i == 4) ? "Y rotation" : "Z rotation");
      v->value(currentParams[i]);
    }
    else if(i < 9){ // translation
      currentParams[i] = bounds.center()[i - 6];
      v->maximum(bounds.max()[i] + 10. * CTX.lc);
      v->minimum(bounds.min()[i] - 10. * CTX.lc);
      v->step(CTX.lc / 100.);
      v->label((i == 6) ? "X translation" : (i == 7) ? "Y translation" : 
	       "Z translation");
      v->value(currentParams[i]);
    }
    else{ // other parameters
      currentParams[i] = ps->GetParameter(i - 9);
      v->maximum(10. * CTX.lc);
      v->minimum(-10. * CTX.lc);
      v->step(CTX.lc / 100.);
      v->label(strdup(ps->GetLabel(i - 9).c_str()));
      v->value(currentParams[i]);
    }
    ps->SetOrigin(currentParams[6], currentParams[7], currentParams[8]);
    v->align(FL_ALIGN_RIGHT);
    v->callback(update_cb, e);
    parameters.push_back(v);
  }
  group->end();
  group->hide();
}

projectionEditor::projectionEditor() 
{
  // construct GUI in terms of standard sizes
  const int BH = 2 * GetFontSize() + 1, BB = 7 * GetFontSize(), WB = 7;
  const int width = (int)(3.5 * BB), height = 24 * BH;
  
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

  {  
    Fl_Toggle_Button *b1 = new Fl_Toggle_Button
      (width - WB - 3 * BB / 2, WB, 3 * BB / 2, BH, "Hide unselected");
    b1->callback(hide_cb);
    Fl_Button *b2 = new Fl_Button
      (width - WB - 3 * BB / 2, WB + BH, 3 * BB / 2, BH, "Save selection");
    b2->callback(save_selection_cb, this);
  }

  const int brw = (int)(1.25 * BB);

  _browser = new Fl_Hold_Browser(WB, 2 * WB + 3 * BH, brw, 5 * BH);
  _browser->callback(browse_cb, this);

  _paramWin[0] = 2 * WB + brw;
  _paramWin[1] = 2 * WB + 3 * BH;
  _paramWin[2] = width - 3 * WB - brw;
  _paramWin[3] = 6 * BH;
  _paramWin[4] = BB;
  _paramWin[5] = BH;

  {
    Fl_Button *b1 = new Fl_Button(WB, 2 * WB + 8 * BH, brw / 2, BH, "Load");
    b1->callback(load_projection_cb, this);
    Fl_Button *b2 = new Fl_Button(WB + brw / 2, 2 * WB + 8 * BH, brw / 2, BH, "Save");
    b2->callback(save_projection_cb, this);
  }

  int hard = 8;
  int uvw = width - 2 * WB - 2 * hard - 3 * WB;
  int uvh = height - 8 * WB - 14 * BH - 2 * hard;

  hardEdges[0] = new Fl_Toggle_Button(WB, 3 * WB + 9 * BH + hard, 
				      hard, uvh);
  hardEdges[1] = new Fl_Toggle_Button(width - 4 * WB - hard, 3 * WB + 9 * BH + hard,
				      hard, uvh);
  hardEdges[2] = new Fl_Toggle_Button(WB + hard, 3 * WB + 9 * BH, 
				      uvw, hard);
  hardEdges[3] = new Fl_Toggle_Button(WB + hard, height - 5 * WB - 5 * BH - hard, 
				      uvw, hard);
  for(int i = 0; i < 4; i++)
    hardEdges[i]->tooltip("Push to mark edge as `hard'");

  _uvPlot = new uvPlot(WB + hard, 3 * WB + 9 * BH + hard, uvw, uvh);
  _uvPlot->end();

  Fl_Slider *s = new Fl_Slider(width - 3 * WB, 3 * WB + 9 * BH + hard, 2 * WB, uvh);
  s->minimum(1.);
  s->maximum(0.);
  s->value(1.);
  s->callback(filter_cb, this);
  s->tooltip("Filter selection by distance to projection surface");
  
  modes[0] = new Fl_Value_Input(WB, height - 4 * WB - 5 * BH, BB  / 2, BH);
  modes[0]->tooltip("Number of Fourier modes along u");
  modes[1] = new Fl_Value_Input(WB + BB / 2, height - 4 * WB - 5 * BH, BB  / 2, BH, 
				"Fourier modes");
  modes[1]->tooltip("Number of Fourier modes along v");
  modes[2] = new Fl_Value_Input(WB, height - 4 * WB - 4 * BH, BB  / 2, BH);
  modes[2]->tooltip("Number of Chebyshev modes along u");
  modes[3] = new Fl_Value_Input(WB + BB / 2, height - 4 * WB - 4 * BH, BB  / 2, BH, 
				"Chebyshev modes");
  modes[3]->tooltip("Number of Chebyshev modes along v");
  for(int i = 0; i < 4; i++){
    modes[i]->value(8);
    modes[i]->maximum(128);
    modes[i]->minimum(1);
    modes[i]->step(1);
    modes[i]->align(FL_ALIGN_RIGHT);
  }    

  {
    Fl_Button *b = new Fl_Button(width - WB - BB, height - 4 * WB - 5 * BH, 
				  BB, 2 * BH, "Generate\nPatch");
    b->callback(compute_cb, this);
  }

  {
    int bb = (int)(0.37 * BB);
    new Fl_Box(WB, height - 3 * WB - 3 * BH, BB / 2, BH, "Delete:");
    Fl_Button *b1 = new Fl_Button(WB + BB / 2, height - 3 * WB - 3 * BH, 
				  bb, BH, "last");
    b1->callback(action_cb, (void*)"delete_last");
    Fl_Button *b2 = new Fl_Button(WB + BB / 2 + bb, height - 3 * WB - 3 * BH,
				  bb, BH, "all");
    b2->callback(action_cb, (void*)"delete_all");
    Fl_Button *b3 = new Fl_Button(WB + BB / 2 + 2 * bb, height - 3 * WB - 3 * BH,
				  bb, BH, "sel.");
    b3->callback(action_cb, (void*)"delete_select");
  }

  {
    int bb = (int)(0.37 * BB);
    int s = width - WB - BB / 2 - 3 * bb;
    new Fl_Box(s, height - 3 * WB - 3 * BH, BB / 2, BH, "Save:");
    Fl_Button *b1 = new Fl_Button(s + BB / 2, height - 3 * WB - 3 * BH,
				  bb, BH, "last");
    b1->callback(action_cb, (void*)"save_last");
    Fl_Button *b2 = new Fl_Button(s + BB / 2 + bb, height - 3 * WB - 3 * BH,
				  bb, BH, "all");
    b2->callback(action_cb, (void*)"save_all");
    Fl_Button *b3 = new Fl_Button(s + BB / 2 + 2 * bb, height - 3 * WB - 3 * BH,
				  bb, BH, "sel.");
    b3->callback(action_cb, (void*)"save_select");
  }

  {
    Fl_Button *b1 = new Fl_Button(WB, height - 2 * WB - 2 * BH, 
				  BB, BH, "Blend");
    Fl_Button *b2 = new Fl_Button(2 * WB + BB, height - 2 * WB - 2 * BH, 
				  BB, BH, "Intersect");
  }

  Fl_Button *b = new Fl_Button(width - WB - BB, height - WB - BH, BB, BH, "Cancel");
  b->callback(close_cb, _window);
  
  _window->end();
  _window->hotspot(_window);
  _window->resizable(_uvPlot);
  _window->size_range(width, (int)(0.85 * height));
}

void projectionEditor::load(FProjectionFace *face, std::string tag)
{
  ProjectionSurface *ps = face->GetProjectionSurface();
  _browser->add(tag.size() ? tag.c_str() : ps->GetName().c_str());
  projection *p =  new projection(face, _paramWin[0], _paramWin[1], _paramWin[2],
				  _paramWin[3], _paramWin[4], _paramWin[5], this);
  _projections.push_back(p);
  _window->add(p->group);
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

projection *projectionEditor::getLastProjection()
{
  return _projections[_projections.size() - 1];
}

void browse_cb(Fl_Widget *w, void *data)
{
  projectionEditor *e = (projectionEditor*)data;

  std::vector<projection*> &projections(e->getProjections());
  for(unsigned int i = 0; i < projections.size(); i++){
    projections[i]->face->setVisibility(false);
    projections[i]->group->hide();
  }
  
  projection *p = e->getCurrentProjection();
  if(p){
    p->face->setVisibility(true);
    p->group->show();
  }

  update_cb(0, data);
}

void update_cb(Fl_Widget *w, void *data)
{
  projectionEditor *e = (projectionEditor*)data;

  // get all parameters from GUI and modify projection surface accordingly

  projection *p = e->getCurrentProjection();
  if(p){
    ProjectionSurface *ps = p->face->GetProjectionSurface();
    ps->Rescale(p->parameters[0]->value() / p->currentParams[0],
		p->parameters[1]->value() / p->currentParams[1],
		p->parameters[2]->value() / p->currentParams[2]);
    ps->Rotate(p->parameters[3]->value() - p->currentParams[3],
	       p->parameters[4]->value() - p->currentParams[4],
	       p->parameters[5]->value() - p->currentParams[5]);
    ps->Translate(p->parameters[6]->value() - p->currentParams[6],
		  p->parameters[7]->value() - p->currentParams[7],
		  p->parameters[8]->value() - p->currentParams[8]);
    for (int i = 0; i < 9; i++)
      p->currentParams[i] = p->parameters[i]->value();
    for (int i = 9; i < 9 + ps->GetNumParameters(); i++)
      ps->SetParameter(i - 9, p->parameters[i]->value());
    p->face->computeGraphicsRep(64, 64); // FIXME: hardcoded for now!
   
    // project all selected points and update u,v display
    std::vector<double> u, v, dist;
    std::vector<std::complex<double> > f;
    std::vector<GEntity*> &ent(e->getEntities());
    for(unsigned int i = 0; i < ent.size(); i++){
      if(ent[i]->getSelection()){
	GVertex *gv = dynamic_cast<GVertex*>(ent[i]);
	if(!gv)
	  Msg(GERROR, "Problem in point selection processing");
	else{
	  double uu, vv, p[3], n[3];
	  ps->OrthoProjectionOnSurface(gv->x(), gv->y(), gv->z(), uu, vv);
	  if(uu >= 0. && uu <= 1. && vv >= 0. && vv <= 1.){
	    ps->F(uu, vv, p[0], p[1], p[2]);
	    ps->GetUnitNormal(uu, vv, n[0], n[1], n[2]);
	    double dx = gv->x() - p[0], dy = gv->y() - p[1], dz = gv->z() - p[2];
	    u.push_back(uu);
	    v.push_back(vv);
	    dist.push_back(sqrt(dx * dx + dy * dy + dz * dz));
	    f.push_back(dx * n[0] + dy * n[1] + dz * n[2]);
	  }
	}
      }
    }
    // deal with elements here
    e->uv()->set(u, v, dist, f);
  }

  Draw();
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
	  ele[ele.size() - 1]->setVisibility(1); ele.pop_back();
	}
      }
      else{
	if(ent.size()){
	  ent[ent.size() - 1]->setSelection(0); ent.pop_back();
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
      ele.clear();
      ent.clear();
      break;
    }
    update_cb(0, data);
  }

  CTX.mesh.changed = ENT_ALL;
  CTX.pick_elements = 0;
  Draw();  
  Msg(ONSCREEN, "");
}

void filter_cb(Fl_Widget *w, void *data)
{
  Fl_Slider *slider = (Fl_Slider*)w;
  projectionEditor *e = (projectionEditor*)data;
  projection *p = e->getCurrentProjection();
  if(p){
    SBoundingBox3d bbox = GMODEL->bounds();
    double lc = norm(SVector3(bbox.max(), bbox.min()));
    double threshold = slider->value() * lc;
    ProjectionSurface *ps = p->face->GetProjectionSurface();
    std::vector<GEntity*> &ent(e->getEntities());
    for(unsigned int i = 0; i < ent.size(); i++){
      GVertex *gv = dynamic_cast<GVertex*>(ent[i]);
      if(gv){
	double uu, vv, p[3], n[3];
	ps->OrthoProjectionOnSurface(gv->x(), gv->y(), gv->z(), uu, vv);
	ps->F(uu, vv, p[0], p[1], p[2]);
	double dx = gv->x() - p[0], dy = gv->y() - p[1], dz = gv->z() - p[2];
	if(uu >= 0. && uu <= 1. && vv >= 0. && vv < 1. &&
	   sqrt(dx * dx + dy * dy + dz * dz) < threshold)
	  gv->setSelection(true);
	else
	  gv->setSelection(false);
      }
    }
    // deal with elements here
  }
  update_cb(0, data);
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

void save_selection_cb(Fl_Widget *w, void *data)
{
  projectionEditor *e = (projectionEditor*)data;
  std::vector<GEntity*> &ent(e->getEntities());
  if(file_chooser(0, 1, "Save Selection", "*.geo")){
    FILE *fp = fopen(file_chooser_get_name(1), "w");
    if(!fp){
      Msg(GERROR, "Unable to open file `%s'", file_chooser_get_name(1));
      return;
    }
    // maybe we should save as mesh file
    for(unsigned int i = 0; i < ent.size(); i++){
      GVertex *gv = dynamic_cast<GVertex*>(ent[i]);
      if(gv && gv->getSelection())
	fprintf(fp, "Point(%d) = {%.16g,%.16g,%.16g,1};\n", gv->tag(), 
		gv->x(), gv->y(), gv->z());
    }
    // deal with elements here
    fclose(fp);
  }
}

void load_projection_cb(Fl_Widget *w, void *data)
{
  projectionEditor *e = (projectionEditor*)data;
  if(file_chooser(0, 0, "Load Projection", "*.pro")){
    FILE *fp = fopen(file_chooser_get_name(1), "r");
    if(!fp){
      Msg(GERROR, "Unable to open file `%s'", file_chooser_get_name(1));
      return;
    }
    int num;
    if(!fscanf(fp, "%d", &num)){
      Msg(GERROR, "Bad projection file format");
      return;
    }
    for(int proj = 0; proj < num; proj++){
      char name[256], tag[256];
      if(!fscanf(fp, "%s", tag) || !fscanf(fp, "%s", name)){
	Msg(GERROR, "Bad projection file format");
	return;
      }
      FProjectionFace *face = createProjectionFaceFromName(name);
      if(face){
	e->load(face, tag);
	projection *p = e->getLastProjection();
	if(p){
	  for(unsigned int i = 0; i < p->parameters.size(); i++){
	    double val;
	    if(!fscanf(fp, "%lf", &val)){
	      Msg(GERROR, "Missing paramater for projection `%s'", name);
	      break;
	    }
	    p->parameters[i]->value(val);
	  }
	}
      }
    }
    fclose(fp);
    update_cb(0, data);
  }
}

void save_projection_cb(Fl_Widget *w, void *data)
{
  projectionEditor *e = (projectionEditor*)data;
  projection *p = e->getCurrentProjection();
  if(p){
    ProjectionSurface *ps = p->face->GetProjectionSurface();
    if(file_chooser(0, 1, "Save Projection", "*.pro")){
      FILE *fp = fopen(file_chooser_get_name(1), "w");
      if(!fp){
	Msg(GERROR, "Unable to open file `%s'", file_chooser_get_name(1));
	return;
      }
      fprintf(fp, "1\n%s\n%s\n", ps->GetName().c_str(), ps->GetName().c_str());
      for(unsigned int i = 0; i < p->parameters.size(); i++)
	fprintf(fp, "%.16g\n", p->parameters[i]->value());
      fclose(fp);
    }
  }
}

void compute_cb(Fl_Widget *w, void *data)
{
  projectionEditor *e = (projectionEditor*)data;

  projection *p = e->getCurrentProjection();
  if(p){
    // get the projection data
    std::vector<double> u, v, dist;
    std::vector<std::complex<double> > f;
    e->uv()->get(u, v, dist, f);
    if(f.empty()) return;

    int uModes = (int)e->modes[0]->value();
    int vModes = (int)e->modes[1]->value();

    if(f.size() < uModes * vModes){
      Msg(GERROR, "Number of points < uModes * vModes");
      return;
    }

    int uM = (int)e->modes[2]->value();
    int vM = (int)e->modes[3]->value();
    int h0 = e->hardEdges[0]->value();
    int h1 = e->hardEdges[1]->value();
    int h2 = e->hardEdges[2]->value();
    int h3 = e->hardEdges[3]->value();

    // create the Fourier faces (with boundaries)
    ProjectionSurface *ps = p->face->GetProjectionSurface();
    if(ps->IsUPeriodic()) {
      Patch* patchL = new FPatch(0, ps->clone(), u, v, f, 3, uModes, vModes,
				 uM, vM, h0, h1, h2, h3);
      patchL->SetMinU(-0.35);
      patchL->SetMaxU(0.35);
      makeGFace(patchL);
      Patch* patchR = new FPatch(0, ps->clone(), u, v, f, 3, uModes, vModes,
				 uM, vM, h0, h1, h2, h3);
      patchR->SetMinU(0.15);
      patchR->SetMaxU(0.85);
      makeGFace(patchR);
    }
    else if (ps->IsVPeriodic()) {
      Patch* patchL = new FPatch(0, ps->clone(), u, v, f, 3, uModes, vModes, 
				 uM, vM, h0, h1, h2, h3);
      patchL->SetMinV(-0.35);
      patchL->SetMaxV(0.35);
      makeGFace(patchL);
      Patch* patchR = new FPatch(0, ps->clone(), u, v, f, 3, uModes, vModes,
				 uM, vM, h0, h1, h2, h3);
      patchR->SetMinV(0.15);
      patchR->SetMaxV(0.85);
      makeGFace(patchR);
    }
    else {
      Patch* patch = new FPatch(0, ps->clone(), u, v, f, 3, uModes, vModes, 
				uM, vM, h0, h1, h2, h3);
      makeGFace(patch);
    }
  }

  Draw();
}

void delete_fourier(GFace *gf)
{
  if(gf->getNativeType() != GEntity::FourierModel) return;

  // don't actually delete the data so we can add `undo' later
  std::list<GVertex*> vertices = gf->vertices();
  for(std::list<GVertex*>::iterator it = vertices.begin(); it != vertices.end(); it++)
    GMODEL->remove(*it);

  std::list<GEdge*> edges = gf->edges();
  for(std::list<GEdge*>::iterator it = edges.begin(); it != edges.end(); it++)
    GMODEL->remove(*it);

  GMODEL->remove(gf);
}

void action_cb(Fl_Widget *w, void *data)
{
  std::string what((char*)data);
  std::vector<GFace*> faces;

  if(what == "delete_last" || what == "save_last"){
    int id = -1;
    for(GModel::fiter it = GMODEL->firstFace(); it != GMODEL->lastFace(); it++)
      if((*it)->getNativeType() == GEntity::FourierModel) 
	id = std::max(id, (*it)->tag());
    if(id > 0) faces.push_back(GMODEL->faceByTag(id));
  }
  else if(what == "delete_all" || what == "save_all"){
    for(GModel::fiter it = GMODEL->firstFace(); it != GMODEL->lastFace(); it++)
      if((*it)->getNativeType() == GEntity::FourierModel)
	faces.push_back(*it);
  }
  else if(what == "delete_select" || what == "save_select"){
    Msg(ONSCREEN, "Select Surface\n[Press 'e' to end selection 'q' to abort]");
    std::vector<GVertex*> vertices;
    std::vector<GEdge*> edges;
    std::vector<GFace*> faces;
    std::vector<GRegion*> regions;
    std::vector<MElement*> elements;
    char ib = SelectEntity(ENT_SURFACE, vertices, edges, faces, regions, elements);
    if(ib == 'l') faces.insert(faces.end(), faces.begin(), faces.end());
    Msg(ONSCREEN, "");
  }

  if(what[0] == 'd'){
    for(unsigned int i = 0; i < faces.size(); i++) 
      delete_fourier(faces[i]);
  }
  else{
    char *filename = "patches.fm";
    FILE *fp = fopen(filename, "w+");
    if(!fp){
      printf("Unable to open file '%s'\n", filename);
      return;
    }
    fprintf(fp, "%d\n", (int)faces.size());
    for(unsigned int i = 0; i < faces.size(); i++){
      FFace* ff = (FFace*)faces[i];
      ff->GetFMFace()->GetPatch()->Export(fp);
    }
    fclose(fp);
  }

  Draw();
}

void mesh_parameterize_cb(Fl_Widget* w, void* data)
{
  // display geometry surfaces
  opt_geometry_surfaces(0, GMSH_SET | GMSH_GUI, 1);

  // create the (static) editor
  static projectionEditor *editor = 0;
  if(!editor){
    editor = new projectionEditor();
    editor->load(createProjectionFaceFromName("plane"));
    editor->load(createProjectionFaceFromName("paraboloid"));
    editor->load(createProjectionFaceFromName("Cylinder"));
    editor->load(createProjectionFaceFromName("revolvedParabola"));
  }
  editor->show();
}

#else

void mesh_parameterize_cb(Fl_Widget* w, void* data)
{
  Msg(GERROR, "You must compile FourierModel to reparameterize meshes");
}

#endif
