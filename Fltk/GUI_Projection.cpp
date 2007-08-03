#include "Draw.h"
#include "Options.h"
#include "Context.h"
#include "SelectBuffer.h"
#include "GUI_Projection.h"

extern GModel *GMODEL;
extern Context_T CTX;

#if defined(HAVE_FOURIER_MODEL)

void uvPlot::draw()
{
  // draw background
  fl_color(FL_WHITE);
  fl_rectf(0, 0, w(), h());

  // draw points
  if(_u.size() != _v.size()) return;
  for(unsigned int i = 0; i < _u.size(); i++){
    int x = (int)(_u[i] * w());
    int y = (int)(_v[i] * h());
    // fixme: change color depending on f
    fl_color(FL_BLACK);
    fl_rect(x, y, 3, 3);
  }

  //fl_font(FL_HELVETICA, 14);
  //fl_draw("Hello", w() / 2, h() / 2);
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
      v->label((i == 3) ? "X rotation" : (i == 4) ? "Y rotation" : 
	       "Z rotation");
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
  
  projection *p = e->getCurrentProjection();
  if(p){
    p->face->setVisibility(true);
    p->group->show();
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
    Draw();
    
    // project all selected points and update u,v display
    std::vector<double> u, v, f;
    std::vector<GEntity*> &ent(e->getEntities());
    for(unsigned int i = 0; i < ent.size(); i++){
      if(ent[i]->getSelection()){
	GVertex *ve = dynamic_cast<GVertex*>(ent[i]);
	if(!ve)
	  Msg(GERROR, "Problem in point selection processing");
	else{
	  double uu, vv, xx, yy, zz;
	  ps->OrthoProjectionOnSurface(ve->x(),ve->y(),ve->z(),uu,vv);
	  u.push_back(uu);
	  v.push_back(vv);
	  ps->F(uu,vv,xx,yy,zz);
	  double dx = xx - ve->x(), dy= yy - ve->y(), dz = zz - ve->z();
	  f.push_back(sqrt(dx * dx + dy * dy + dz * dz));
	}
      }
    }
    // loop over elements and do the same thing
    e->uv()->fill(u, v, f);
  }
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
    update_cb(w, data);
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

  projection *p = e->getCurrentProjection();
  if(p){
    ProjectionSurface *ps = p->face->GetProjectionSurface();

    // project all selected points and update u,v display
    std::vector<double> u, v;
    std::vector<std::complex<double> > f;
    std::vector<GEntity*> &ent(e->getEntities());
    for(unsigned int i = 0; i < ent.size(); i++){
      GVertex *ve = dynamic_cast<GVertex*>(ent[i]);
      if(!ve){
	Msg(GERROR, "Problem in point selection processing");
      }
      else{
	double uu, vv;
	ps->OrthoProjectionOnSurface(ve->x(),ve->y(),ve->z(),uu,vv);
	u.push_back(uu);
	v.push_back(vv);
	double p[3], n[3];
	ps->F(u[i],v[i],p[0],p[1],p[2]);
	ps->GetUnitNormal(u[i],v[i],n[0],n[1],n[2]);
	f.push_back((ve->x() - p[0]) * n[0] + (ve->y() - p[1]) * n[1] + 
		    (ve->z() - p[2]) * n[2]);
      }
    }
    Patch* patch = new FPatch(0,ps,u,v,f,3);
    patch->SetMinU(0.0);
    patch->SetMaxU(0.5);

    double LL[2], LR[2], UL[2], UR[2];
    LL[0] = 0.0; LL[1] = 0.0;
    LR[0] = 1.0; LR[1] = 0.0;
    UL[0] = 0.0; UL[1] = 1.0;
    UR[0] = 1.0; UR[1] = 1.0;

    int i1, i2;
    double xx,yy,zz;

    int tagVertex = GMODEL->numVertex();
    patch->F(LL[0],LL[1],xx,yy,zz);
    FM_Vertex* vLL = new FM_Vertex(++tagVertex,xx,yy,zz);
    GMODEL->add(new FVertex(GMODEL,vLL->GetTag(),vLL));
    patch->F(LR[0],LR[1],xx,yy,zz);
    FM_Vertex* vLR = new FM_Vertex(++tagVertex,xx,yy,zz);
    GMODEL->add(new FVertex(GMODEL,vLR->GetTag(),vLR));
    patch->F(UL[0],UL[1],xx,yy,zz);
    FM_Vertex* vUL = new FM_Vertex(++tagVertex,xx,yy,zz);
    GMODEL->add(new FVertex(GMODEL,vUL->GetTag(),vUL));
    patch->F(UR[0],UR[1],xx,yy,zz);
    FM_Vertex* vUR = new FM_Vertex(++tagVertex,xx,yy,zz);
    GMODEL->add(new FVertex(GMODEL,vUR->GetTag(),vUR));

    Curve* curveB = new FCurve(0,patch,LL,LR);
    Curve* curveR = new FCurve(0,patch,LR,UR);
    Curve* curveT = new FCurve(0,patch,UR,UL);
    Curve* curveL = new FCurve(0,patch,UL,LL);

    int tagEdge = GMODEL->numEdge();
    FM_Edge* eB = new FM_Edge(++tagEdge,curveB,vLL,vLR);
    i1 = eB->GetStartPoint()->GetTag();
    i2 = eB->GetEndPoint()->GetTag();
    GMODEL->add(new FEdge(GMODEL,eB,eB->GetTag(),GMODEL->vertexByTag(i1),
			  GMODEL->vertexByTag(i2)));
    FM_Edge* eR = new FM_Edge(++tagEdge,curveR,vLR,vUR); 
    i1 = eR->GetStartPoint()->GetTag();
    i2 = eR->GetEndPoint()->GetTag();
    GMODEL->add(new FEdge(GMODEL,eR,eR->GetTag(),GMODEL->vertexByTag(i1),
			  GMODEL->vertexByTag(i2))); 
    FM_Edge* eT = new FM_Edge(++tagEdge,curveT,vUR,vUL);
    i1 = eT->GetStartPoint()->GetTag();
    i2 = eT->GetEndPoint()->GetTag();
    GMODEL->add(new FEdge(GMODEL,eT,eT->GetTag(),GMODEL->vertexByTag(i1),
			  GMODEL->vertexByTag(i2)));
    FM_Edge* eL = new FM_Edge(++tagEdge,curveL,vUL,vLL); 
    i1 = eL->GetStartPoint()->GetTag();
    i2 = eL->GetEndPoint()->GetTag();
    GMODEL->add(new FEdge(GMODEL,eL,eL->GetTag(),GMODEL->vertexByTag(i1),
			  GMODEL->vertexByTag(i2)));

    FM_Face* face = new FM_Face(GMODEL->numFace() + 1,patch);
    face->AddEdge(eB); face->AddEdge(eR); face->AddEdge(eT); face->AddEdge(eL);
    std::list<GEdge*> l_edges;
    for (int j=0;j<face->GetNumEdges();j++) {
      int tag = face->GetEdge(j)->GetTag(); 
      l_edges.push_back(GMODEL->edgeByTag(tag));
    }
    GMODEL->add(new FFace(GMODEL,face,face->GetTag(),l_edges));

    int nU=64;
    int nV=64;
    
    std::vector<int> color(3);
    
    std::vector<std::vector<double> > x(nU,std::vector<double>(nV));
    std::vector<std::vector<double> > y(nU,std::vector<double>(nV));
    std::vector<std::vector<double> > z(nU,std::vector<double>(nV));
    
    std::vector<std::vector<int> > mask = ones(nU,nV);
    
    double hU = 1./(nU-1);
    double hV = 1./(nV-1);
    
    for (int j=0;j<nU;j++) {
      for (int k=0;k<nV;k++) {
	double u = j*hU;
	double v = k*hV;
	patch->F(u,v,x[j][k],y[j][k],z[j][k]);
      }
    }
    color[0] = 0; color[1] = 0; color[2] = 1;
    plotSceneViewer(0,"patch.iv",color,x,y,z,nU,nV,mask);
  }
  //Msg(GERROR, "Compute!");
}

void mesh_parameterize_cb(Fl_Widget* w, void* data)
{
  // display geometry surfaces
  opt_geometry_surfaces(0, GMSH_SET | GMSH_GUI, 1);

  // create one instance of each available projection surface
  std::vector<FProjectionFace*> faces;
  if(faces.empty()){
    int tag = GMODEL->numFace();
    faces.push_back(new FProjectionFace(GMODEL, ++tag, 
					new CylindricalProjectionSurface(tag)));
    faces.push_back(new FProjectionFace(GMODEL, ++tag,
					new RevolvedParabolaProjectionSurface(tag)));
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
