// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <FL/Fl_Tabs.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Return_Button.H>
#include "FlGui.h"
#include "classificationEditor.h"
#include "paletteWindow.h"
#include "Numeric.h"
#include "drawContext.h"
#include "Options.h"
#include "Context.h"
#include "GmshMessage.h"
#include "MLine.h"
#include "meshGFaceDelaunayInsertion.h"
#include "discreteEdge.h"
#include "discreteFace.h"

struct compareMLinePtr {
  bool operator () (MLine *l1, MLine *l2) const
  {
    static Less_Edge le;
    return le(l1->getEdge(0), l2->getEdge(0)); 
  }
};

static void recurClassify(MTri3 *t, GFace *gf,
                          std::map<MLine*, GEdge*, compareMLinePtr> &lines,
                          std::map<MTriangle*, GFace*> &reverse)
{
  if(!t->isDeleted()){
    gf->triangles.push_back(t->tri());
    reverse[t->tri()] = gf;
    t->setDeleted(true);
    for(int i = 0; i < 3; i++){
      MTri3 *tn = t->getNeigh(i);
      if(tn){
        edgeXface exf(t, i);
        MLine ml(exf.v[0], exf.v[1]);       
        std::map<MLine*, GEdge*, compareMLinePtr>::iterator it = lines.find(&ml);
        if(it == lines.end())
          recurClassify(tn, gf, lines, reverse);
      }
    }  
  }
}

static GEdge *getNewModelEdge(GFace *gf1, GFace *gf2, 
                              std::map<std::pair<int, int>, GEdge*> &newEdges)
{
  int t1 = gf1 ? gf1->tag() : -1;
  int t2 = gf2 ? gf2->tag() : -1;
  int i1 = std::min(t1, t2);
  int i2 = std::max(t1, t2);

  if(i1 == i2) return 0;

  std::map<std::pair<int, int>, GEdge*>::iterator it = 
    newEdges.find(std::make_pair<int, int>(i1, i2));
  if(it == newEdges.end()){
    discreteEdge *ge = new discreteEdge
      (GModel::current(), GModel::current()->maxEdgeNum() + 1, 0, 0);
    GModel::current()->add(ge);
    newEdges[std::make_pair<int, int>(i1, i2)] = ge;
    return ge;
  }
  else
    return it->second;  
}

static void recurClassifyEdges(MTri3 *t, 
                               std::map<MTriangle*, GFace*> &reverse,
                               std::map<MLine*, GEdge*, compareMLinePtr> &lines,
                               std::set<MLine*> &touched,
                               std::map<std::pair<int, int>, GEdge*> &newEdges)
{
  if(!t->isDeleted()){
    t->setDeleted(true);
    GFace *gf1 = reverse[t->tri()];
    for(int i = 0; i < 3; i++){
      GFace *gf2 = 0;
      MTri3 *tn = t->getNeigh(i);
      if(tn)
        gf2 = reverse[tn->tri()];
      edgeXface exf(t, i);
      MLine ml(exf.v[0], exf.v[1]);
      std::map<MLine*, GEdge*, compareMLinePtr>::iterator it = lines.find(&ml);
      if(it != lines.end()){
        if(touched.find(it->first) == touched.end()){
          GEdge *ge =  getNewModelEdge(gf1, gf2, newEdges);
          if(ge) ge->lines.push_back(it->first);
          touched.insert(it->first);
        }
      }
      if(tn)
        recurClassifyEdges(tn, reverse, lines, touched, newEdges);
    }
  }
}

static void NoElementsSelectedMode(classificationEditor *e)
{
  e->buttons[CLASS_BUTTON_SELECT_ELEMENTS]->activate(); 
  e->buttons[CLASS_BUTTON_SELECT_ALL_ELEMENTS]->activate(); 

  e->buttons[CLASS_BUTTON_DELETE_FROM_SELECTION]->deactivate();
  e->buttons[CLASS_BUTTON_RESET_SELECTION]->deactivate();
  e->toggles[CLASS_TOGGLE_BOUNDARY]->deactivate();
  e->inputs[CLASS_VALUE_ANGLE]->deactivate();
  e->buttons[CLASS_BUTTON_CLASSIFY]->deactivate();

  CTX::instance()->mesh.changed = ENT_ALL;
  CTX::instance()->pickElements = 0;
  drawContext::global()->draw();  
  Msg::StatusBar(3, false, "");
}

static void ElementsSelectedMode(classificationEditor *e)
{
  e->buttons[CLASS_BUTTON_DELETE_FROM_SELECTION]->activate();
  e->buttons[CLASS_BUTTON_RESET_SELECTION]->activate();
  e->toggles[CLASS_TOGGLE_BOUNDARY]->activate();
  e->inputs[CLASS_VALUE_ANGLE]->activate();

  e->buttons[CLASS_BUTTON_SELECT_ELEMENTS]->deactivate(); 
  e->buttons[CLASS_BUTTON_SELECT_ALL_ELEMENTS]->deactivate(); 
}

static void update_edges_cb(Fl_Widget *w, void *data)
{
  classificationEditor *e = (classificationEditor*)data;
 
  if(!e->selected) return;

  for(unsigned int i = 0; i < e->selected->lines.size(); i++)
    delete e->selected->lines[i];
  e->selected->lines.clear();

  double threshold = e->inputs[CLASS_VALUE_ANGLE]->value() / 180. * M_PI;
  for(unsigned int i = 0; i < e->edges_detected.size(); i++){
    edge_angle ea = e->edges_detected[i];
    if(ea.angle <= threshold) break;
    e->selected->lines.push_back(new MLine(ea.v1, ea.v2));
  } 

  if(e->toggles[CLASS_TOGGLE_BOUNDARY]->value()){
    for(unsigned int i = 0 ; i < e->edges_lonly.size(); i++){
      edge_angle ea = e->edges_lonly[i];
      e->selected->lines.push_back(new MLine(ea.v1, ea.v2));
    } 
  }

  Msg::Info("Edges: %d inside, %d boundary, %d selected", (int)e->edges_detected.size(),
            (int)e->edges_lonly.size(), (int)e->selected->lines.size());
  
  CTX::instance()->mesh.changed = ENT_ALL;
  drawContext::global()->draw();   
}

static void class_select_elements_cb(Fl_Widget *w, void *data)
{
  classificationEditor *e = (classificationEditor*)data;
  std::vector<MTriangle*> &ele(e->elements);

  // allocate discrete edge to hold the selected mesh segments
  if(!e->selected){
    e->selected = new discreteEdge
      (GModel::current(), GModel::current()->maxEdgeNum() + 1, 0, 0);
    GModel::current()->add(e->selected);
  }

  CTX::instance()->pickElements = 1;

  while(1) {
    CTX::instance()->mesh.changed = ENT_ALL;
    drawContext::global()->draw();

    Msg::StatusBar(3, false, "Select elements\n"
                   "[Press 'e' to end selection or 'q' to abort]");
    
    char ib = FlGui::instance()->selectEntity(ENT_ALL);
    if(ib == 'l') {
      for(unsigned int i = 0; i < FlGui::instance()->selectedElements.size(); i++){
        MElement *me = FlGui::instance()->selectedElements[i];
        if(me->getType() == TYPE_TRI && me->getVisibility() != 2){
          me->setVisibility(2); ele.push_back((MTriangle*)me);
        }
      }
    }
    if(ib == 'r') {
      for(unsigned int i = 0; i < FlGui::instance()->selectedElements.size(); i++)
        FlGui::instance()->selectedElements[i]->setVisibility(1);
    }
    if(ib == 'e') { // ok, compute the edges
      GModel::current()->setSelection(0);
      e2t_cont adj;
      buildEdgeToTriangle(ele, adj);
      buildListOfEdgeAngle(adj, e->edges_detected, e->edges_lonly);
      ElementsSelectedMode(e);
      break;
    }
    if(ib == 'q') { // do nothing
      GModel::current()->setSelection(0);
      ele.clear();
      break;
    }
  }
  
  update_edges_cb(0, data);

  CTX::instance()->mesh.changed = ENT_ALL;
  CTX::instance()->pickElements = 0;
  drawContext::global()->draw();  
  Msg::StatusBar(3, false, "");
}

static void class_select_all_elements_cb(Fl_Widget *w, void *data)
{
  classificationEditor *e = (classificationEditor*)data;

  // allocate discrete edge to hold the selected mesh segments
  if(!e->selected){
    e->selected = new discreteEdge
      (GModel::current(), GModel::current()->maxEdgeNum() + 1, 0, 0);
    GModel::current()->add(e->selected);
  }

  for(GModel::fiter it = GModel::current()->firstFace(); 
      it != GModel::current()->lastFace(); ++it)
    e->elements.insert(e->elements.end(), (*it)->triangles.begin(), 
                       (*it)->triangles.end());

  e2t_cont adj;
  buildEdgeToTriangle(e->elements, adj);
  buildListOfEdgeAngle(adj, e->edges_detected, e->edges_lonly);
  ElementsSelectedMode(e);
  update_edges_cb(0, data);

  CTX::instance()->mesh.changed = ENT_ALL;
  CTX::instance()->pickElements = 0;
  drawContext::global()->draw();  
  Msg::StatusBar(3, false, "");
}

static void class_hide_cb(Fl_Widget *w, void *data)
{
  CTX::instance()->hideUnselected = !CTX::instance()->hideUnselected;
  CTX::instance()->mesh.changed = ENT_ALL;
  drawContext::global()->draw();
}

static void show_only_edges_cb(Fl_Widget *w, void *data)
{
  classificationEditor *e = (classificationEditor*)data;
  static int old_sf = (int)opt_mesh_surfaces_faces(0, GMSH_GET, 0.);
  static int old_se = (int)opt_mesh_surfaces_edges(0, GMSH_GET, 0.);
  if(e->toggles[CLASS_TOGGLE_SHOW_ONLY_EDGES]->value()){
    opt_mesh_lines(0, GMSH_SET | GMSH_GUI, 1.);
    old_sf = (int)opt_mesh_surfaces_faces(0, GMSH_GET, 0.);
    old_se = (int)opt_mesh_surfaces_edges(0, GMSH_GET, 0.);
    opt_mesh_surfaces_faces(0, GMSH_SET | GMSH_GUI, 0.);
    opt_mesh_surfaces_edges(0, GMSH_SET | GMSH_GUI, 0.);
  }
  else{
    opt_mesh_surfaces_faces(0, GMSH_SET | GMSH_GUI, old_sf);
    opt_mesh_surfaces_edges(0, GMSH_SET | GMSH_GUI, old_se);
  }
  drawContext::global()->draw();
}

static void class_delete_edge_cb(Fl_Widget *w, void *data)
{
  classificationEditor *e = (classificationEditor*)data;

  if(!e->selected) return;

  CTX::instance()->pickElements = 1;
  std::vector<MLine*> ele;
  
  while(1) {
    CTX::instance()->mesh.changed = ENT_ALL;
    drawContext::global()->draw();

    Msg::StatusBar(3, false, "Select elements\n"
                   "[Press 'e' to end selection or 'q' to abort]");
    
    char ib = FlGui::instance()->selectEntity(ENT_ALL);
    if(ib == 'l') {
      for(unsigned int i = 0; i < FlGui::instance()->selectedElements.size(); i++){
        MElement *me = FlGui::instance()->selectedElements[i];
        if(me->getType() == TYPE_LIN && me->getVisibility() != 2){
          me->setVisibility(2); ele.push_back((MLine*)me);
        }
      }
    }
    if(ib == 'r') {
      for(unsigned int i = 0; i < FlGui::instance()->selectedElements.size(); i++)
        FlGui::instance()->selectedElements[i]->setVisibility(1);
    }
    if(ib == 'e') {
      GModel::current()->setSelection(0);
      break;
    }
    if(ib == 'q') {
      GModel::current()->setSelection(0);
      ele.clear();
      break;
    }
  }

  std::sort(ele.begin(), ele.end());

  //  look in all selected edges if a deleted one is present and delete it
  std::vector<MLine*> temp = e->selected->lines;
  e->selected->lines.clear();
  for(unsigned int i = 0; i < temp.size(); i++){      
    std::vector<MLine*>::iterator it = std::find(ele.begin(), ele.end(), temp[i]);
    if(it != ele.end()) 
      delete temp[i];
    else
      e->selected->lines.push_back(temp[i]);
  }
  
  CTX::instance()->mesh.changed = ENT_ALL;
  CTX::instance()->pickElements = 0;
  drawContext::global()->draw();  
  Msg::StatusBar(3, false, "");

  e->elements.clear();
  e->edges_detected.clear();
}

static void class_reset_selection_cb(Fl_Widget *w, void *data)
{
  classificationEditor *e = (classificationEditor*)data;
  if(!e->selected) return;
  for(unsigned int i = 0; i < e->selected->lines.size(); i++)
    delete e->selected->lines[i];
  e->selected->lines.clear();
  e->selected->deleteVertexArrays();
  e->elements.clear();
  e->edges_detected.clear();
  NoElementsSelectedMode(e);
}

static void class_select_surfaces_cb(Fl_Widget *w, void *data)
{
  classificationEditor *e = (classificationEditor*)data;
  std::vector<GFace*> temp;

  opt_geometry_surfaces(0, GMSH_SET | GMSH_GUI, 1);

  while(1) {
    CTX::instance()->mesh.changed = ENT_ALL;
    drawContext::global()->draw();

    Msg::StatusBar(3, false, "Select Surface\n"
                   "[Press 'e' to end selection or 'q' to abort]");
    
    char ib = FlGui::instance()->selectEntity(ENT_SURFACE);
    if(ib == 'l') {
      for(unsigned int i = 0; i < FlGui::instance()->selectedFaces.size(); i++){
        FlGui::instance()->selectedFaces[i]->setSelection(1);
        temp.push_back(FlGui::instance()->selectedFaces[i]);
      }
    }
    if(ib == 'e') { // store the list of gfaces
      GModel::current()->setSelection(0);
      for(unsigned int i = 0; i < temp.size(); i++){
        e->faces.insert(temp[i]);
      }
      break;
    }
    if(ib == 'q') { // do nothing
      GModel::current()->setSelection(0);
      break;
    }
  } 

  if(e->faces.size())
    e->buttons[CLASS_BUTTON_CLASSIFY]->activate();

  CTX::instance()->mesh.changed = ENT_ALL;
  drawContext::global()->draw();  
  Msg::StatusBar(3, false, "");
}

static void class_select_all_surfaces_cb(Fl_Widget *w, void *data)
{
  classificationEditor *e = (classificationEditor*)data;

  for(GModel::fiter it = GModel::current()->firstFace(); 
      it != GModel::current()->lastFace(); ++it)
    e->faces.insert(*it);

  if(e->faces.size())
    e->buttons[CLASS_BUTTON_CLASSIFY]->activate();

  CTX::instance()->mesh.changed = ENT_ALL;
  drawContext::global()->draw();  
  Msg::StatusBar(3, false, "");
}

static void class_classify_cb(Fl_Widget *w, void *data)
{
  classificationEditor *e = (classificationEditor*)data;
  std::map<MLine*, GEdge*, compareMLinePtr> lines;
  for(GModel::eiter it = GModel::current()->firstEdge(); 
      it != GModel::current()->lastEdge(); ++it){
    for(unsigned int i = 0; i < (*it)->lines.size();i++) 
      lines[(*it)->lines[i]] = *it;
  }

  std::list<MTri3*> tris;
  {
    std::set<GFace*>::iterator it = e->faces.begin();
    while(it != e->faces.end()){
      GFace *gf = *it;
      for(unsigned int i = 0; i < gf->triangles.size(); i++)
        tris.push_back(new MTri3(gf->triangles[i], 0));
      gf->triangles.clear();
      ++it;
    }
  }
  if(tris.empty()) return;

  connectTriangles(tris);

  std::map<MTriangle*, GFace*> reverse;
  // color all triangles
  std::list<MTri3*> ::iterator it = tris.begin();
  while(it != tris.end()){
    if(!(*it)->isDeleted()){
      discreteFace *gf = new discreteFace
        (GModel::current(), GModel::current()->maxFaceNum() + 1);
      recurClassify(*it, gf, lines, reverse);
      GModel::current()->add(gf);
    }
    ++it;
  }
  
  // color some lines
  it = tris.begin();
  while(it != tris.end()){
    (*it)->setDeleted(false);
    ++it;
  }
  
  it = tris.begin();
  
  // classify edges that are bound by different GFaces
  std::map<std::pair<int, int>, GEdge*> newEdges;
  std::set<MLine*> touched;
  recurClassifyEdges(*it, reverse, lines, touched, newEdges);
  
  // check if new edges should not be splitted 
  // splitted if composed of several open or closed edges
  for (std::map<std::pair<int, int>, GEdge*>::iterator it = newEdges.begin();
       it != newEdges.end() ; ++it){
    std::list<MLine*> segments;
    for(unsigned int i = 0; i < it->second->lines.size(); i++)
      segments.push_back(it->second->lines[i]);
    while (!segments.empty()) {
      std::vector<MLine*> myLines;
      std::list<MLine*>::iterator it = segments.begin();
      MVertex *vB = (*it)->getVertex(0);
      MVertex *vE = (*it)->getVertex(1);
      myLines.push_back(*it);
      segments.erase(it);
      it++;
      for (int i = 0; i < 2; i++) {
        for (std::list<MLine*>::iterator it = segments.begin();
             it != segments.end(); ++it){ 
          MVertex *v1 = (*it)->getVertex(0);
          MVertex *v2 = (*it)->getVertex(1);
          std::list<MLine*>::iterator itp;
          if (v1 == vE){
            myLines.push_back(*it);
            itp = it;
            it++;
            segments.erase(itp);
            vE = v2;
            i = -1;
          }
          else if ( v2 == vE){
            myLines.push_back(*it);
            itp = it;
            it++;
            segments.erase(itp);
            vE = v1;
            i = -1;
          }
          if (it == segments.end()) break;
        }
        if (vB == vE) break;
        if (segments.empty()) break;
        MVertex *temp = vB;
        vB = vE;
        vE = temp;
      }
      GEdge *newGe = new discreteEdge
        (GModel::current(), GModel::current()->maxEdgeNum() + 1, 0, 0);
      newGe->lines.insert(newGe->lines.end(), myLines.begin(), myLines.end());
      GModel::current()->add(newGe);
    }
  }

  for (std::map<std::pair<int, int>, GEdge*>::iterator it = newEdges.begin();
       it != newEdges.end(); ++it){
    GEdge *ge = it->second;
    GModel::current()->remove(ge);
  }
  
  while(it != tris.end()){
    delete *it;
    ++it;
  }

  // remove selected, but do not delete its elements
  if(e->selected){
    GModel::current()->remove(e->selected);
    e->selected->lines.clear();
    delete e->selected;
    e->selected = 0;
  }
  e->elements.clear();
  e->edges_detected.clear();
  NoElementsSelectedMode(e);
}

classificationEditor::classificationEditor() : selected(0)
{
  opt_mesh_lines(0, GMSH_SET | GMSH_GUI, 1.);

  drawContext::global()->draw();

  int BBB = (int)(1.4 * BB);
  const int width = (int)(3.15 * BBB), height = (int)(9.5 * BH);

  window = new paletteWindow
    (width, height, CTX::instance()->nonModalWindows ? true : false, "Reclassify");
  window->box(GMSH_WINDOW_BOX);
  
  int x = WB, y = WB;
  {
    Fl_Box *b = new Fl_Box
      (x, y, width, BH, "1. Select mesh elements on which to perform edge detection");
    b->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
    
    x += WB;
    y += BH;
    buttons[CLASS_BUTTON_SELECT_ELEMENTS] = new Fl_Button
      (x, y, BBB, BH, "Select elements");
    buttons[CLASS_BUTTON_SELECT_ELEMENTS]->callback(class_select_elements_cb, this);

    buttons[CLASS_BUTTON_SELECT_ALL_ELEMENTS] = new Fl_Button
      (x + BBB + WB, y, (int)(0.5 * BBB) - WB, BH, "All");
    buttons[CLASS_BUTTON_SELECT_ALL_ELEMENTS]->callback(class_select_all_elements_cb, this);
    
    toggles[CLASS_TOGGLE_HIDE] = new Fl_Check_Button
      ((int)(x + 1.5 * BBB + WB), y, (int)(width - 1.5 * BBB - x - 2 * WB), BH, 
       "Hide unselected elements");
    toggles[CLASS_TOGGLE_HIDE]->type(FL_TOGGLE_BUTTON);
    toggles[CLASS_TOGGLE_HIDE]->callback(class_hide_cb, this);
    
    x -= WB;
  }
  {
    y += BH / 2;
    Fl_Box* b = new Fl_Box(x, y + BH - WB, width - 2 * WB, 2);
    b->box(FL_ENGRAVED_FRAME);
    b->labeltype(FL_NO_LABEL);
  }
  {
    y += BH;
    Fl_Box *b = new Fl_Box
      (x, y, width, BH, "2. Fine-tune edge selection");
    b->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
    
    x += WB;
    y += BH;
    inputs[CLASS_VALUE_ANGLE] = new Fl_Value_Input
      (x, y, 2 * BBB / 3, BH, "Threshold angle");
    inputs[CLASS_VALUE_ANGLE]->value(40);
    inputs[CLASS_VALUE_ANGLE]->maximum(180);
    inputs[CLASS_VALUE_ANGLE]->minimum(0);
    inputs[CLASS_VALUE_ANGLE]->align(FL_ALIGN_RIGHT);
    inputs[CLASS_VALUE_ANGLE]->step(1);
    inputs[CLASS_VALUE_ANGLE]->when(FL_WHEN_RELEASE);  
    inputs[CLASS_VALUE_ANGLE]->callback(update_edges_cb, this);

    toggles[CLASS_TOGGLE_SHOW_ONLY_EDGES] = new Fl_Check_Button
      ((int)(x + 1.5 * BBB + WB), y, (int)(width - x - 1.5 * BBB - 2 * WB), BH,
       "Show only edges");
    toggles[CLASS_TOGGLE_SHOW_ONLY_EDGES]->type(FL_TOGGLE_BUTTON);
    toggles[CLASS_TOGGLE_SHOW_ONLY_EDGES]->callback(show_only_edges_cb, this);
    
    y += BH;
    toggles[CLASS_TOGGLE_BOUNDARY] = new Fl_Check_Button
      (x, y, width - x - 2 * WB, BH, "Include edges on boundary (closure)");
    toggles[CLASS_TOGGLE_BOUNDARY]->type(FL_TOGGLE_BUTTON);
    toggles[CLASS_TOGGLE_BOUNDARY]->callback(update_edges_cb, this);
    
    y += BH;
    buttons[CLASS_BUTTON_DELETE_FROM_SELECTION] = new Fl_Button 
      (x, y, (int)(1.5 * BBB), BH, "Delete edges from selection");
    buttons[CLASS_BUTTON_DELETE_FROM_SELECTION]->callback(class_delete_edge_cb, this);    
    buttons[CLASS_BUTTON_DELETE_FROM_SELECTION]->deactivate();
    
    buttons[CLASS_BUTTON_RESET_SELECTION] = new Fl_Button 
      (x + (int)(1.5 * BBB + WB), y, BBB, BH, "Reset selection");
    buttons[CLASS_BUTTON_RESET_SELECTION]->callback(class_reset_selection_cb, this);    
    buttons[CLASS_BUTTON_RESET_SELECTION]->deactivate();
    
    x -= WB;
  }
  {
    y += BH / 2;
    Fl_Box* b = new Fl_Box(x, y + BH - WB, width - 2 * WB, 2);
    b->box(FL_ENGRAVED_FRAME);
    b->labeltype(FL_NO_LABEL);
  }
  {
    y += BH;
    Fl_Box *b = new Fl_Box
      (x, y, width, BH, "3. Reclassify surfaces using selected edges");
    b->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
    
    x += WB;
    y += BH;

    buttons[CLASS_BUTTON_SELECT_SURFACES] = new Fl_Button
      (x, y, BBB, BH, "Select surfaces");
    buttons[CLASS_BUTTON_SELECT_SURFACES]->callback(class_select_surfaces_cb, this);

    buttons[CLASS_BUTTON_SELECT_ALL_SURFACES] = new Fl_Button
      (x + BBB + WB, y, (int)(0.5 * BBB) - WB, BH, "All");
    buttons[CLASS_BUTTON_SELECT_ALL_SURFACES]->callback(class_select_all_surfaces_cb, this);

    buttons[CLASS_BUTTON_CLASSIFY] = new Fl_Return_Button 
      ((int)(x + 1.5 * BBB + WB), y, BBB, BH, "Reclassify");
    buttons[CLASS_BUTTON_CLASSIFY]->callback(class_classify_cb, this);
    buttons[CLASS_BUTTON_CLASSIFY]->deactivate();

    x -= WB;
  }

  window->end();
  window->hotspot(window);

  NoElementsSelectedMode(this);
}

void mesh_classify_cb(Fl_Widget* w, void* data)
{
  // create the (static) editor
  static classificationEditor *editor = 0;
  if(!editor) editor = new classificationEditor();
  editor->show();
}
