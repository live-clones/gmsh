// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <FL/Fl_Tabs.H>
#include <FL/Fl_Value_Input.H>
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
#include "meshGFaceOptimize.h"
#include "discreteEdge.h"
#include "discreteFace.h"

static void NoElementsSelectedMode(classificationEditor *e)
{
  e->_buttons[CLASSBUTTON_DEL]->deactivate();
  e->_buttons[CLASSBUTTON_ADD]->deactivate();
  e->_buttons[CLASSBUTTON_CLEAR]->deactivate();
  //  e->_buttons[CLASSBUTTON_OK]->deactivate();
  e->_togbuttons[CLASSTOGBUTTON_CLOS]->deactivate();
  e->_inputs[CLASSVALUE_ANGLE]->deactivate();

  e->_buttons[CLASSBUTTON_SELECT]->activate(); 
  e->_togbuttons[CLASSTOGBUTTON_HIDE]->activate(); 
}

static void ElementsSelectedMode(classificationEditor *e)
{
  e->_buttons[CLASSBUTTON_DEL]->activate();
  e->_buttons[CLASSBUTTON_ADD]->activate();
  e->_buttons[CLASSBUTTON_CLEAR]->activate();
  e->_togbuttons[CLASSTOGBUTTON_CLOS]->activate();
  e->_inputs[CLASSVALUE_ANGLE]->activate();
  //  e->_buttons[CLASSBUTTON_OK]->activate();

  e->_buttons[CLASSBUTTON_SELECT]->deactivate(); 
  e->_togbuttons[CLASSTOGBUTTON_HIDE]->deactivate(); 
}

// we should 
static void class_selectgface_cb(Fl_Widget *w, void *data)
{
  classificationEditor *e = (classificationEditor*)data;
  std::vector<GFace*> temp;

  opt_geometry_surfaces(0, GMSH_SET | GMSH_GUI, 1);

  while(1) {
    CTX::instance()->mesh.changed = ENT_ALL;
    drawContext::global()->draw();

    Msg::StatusBar(3, false, "Select Model Face\n"
                   "[Press 'e' to end selection or 'q' to abort]");
    
    char ib = FlGui::instance()->selectEntity(ENT_SURFACE);
    if(ib == 'l') {
      for(unsigned int i = 0; i < FlGui::instance()->selectedFaces.size(); i++){
        FlGui::instance()->selectedFaces[i]->setSelection(1);
        temp.push_back(FlGui::instance()->selectedFaces[i]);
      }
    }
    // ok store the list of gfaces !
    if(ib == 'e') {
      GModel::current()->setSelection(0);
      for(unsigned int i = 0; i < temp.size(); i++){
        e->_faces.insert(temp[i]);
      }
      break;
    }
    // do nothing
    if(ib == 'q') {
      GModel::current()->setSelection(0);
      break;
    }
  } 
  CTX::instance()->mesh.changed = ENT_ALL;
  drawContext::global()->draw();  
  Msg::StatusBar(3, false, "");
}

static void class_deleteedge_cb(Fl_Widget *w, void *data)
{
  classificationEditor *e = (classificationEditor*)data;
  std::vector<MLine*> ele;
  
  CTX::instance()->pickElements = 1;
  
  while(1) {
    CTX::instance()->mesh.changed = ENT_ALL;
    drawContext::global()->draw();

    Msg::StatusBar(3, false, "Select Elements\n"
                   "[Press 'e' to end selection or 'q' to abort]");
    
    char ib = FlGui::instance()->selectEntity(ENT_ALL);
    if(ib == 'l') {
      if(CTX::instance()->pickElements){
        for(unsigned int i = 0; i < FlGui::instance()->selectedElements.size(); i++){
          MElement *me = FlGui::instance()->selectedElements[i];
          if(me->getType() == TYPE_LIN && me->getVisibility() != 2){
            me->setVisibility(2); ele.push_back((MLine*)me);
          }
        }
      }
    }
    if(ib == 'r') {
      for(unsigned int i = 0; i < FlGui::instance()->selectedElements.size(); i++)
        FlGui::instance()->selectedElements[i]->setVisibility(1);
    }
    // ok, we compute edges !
    if(ib == 'e') {
      GModel::current()->setSelection(0);
      break;
    }
    // do nothing
    if(ib == 'q') {
      GModel::current()->setSelection(0);
      ele.clear();
      break;
    }
  }

  std::sort(ele.begin(),ele.end());
  //  look in all temporary edges if a deleted one is present and delete it !
  std::vector<MLine*> temp = e->temporary->lines;
  e->temporary->lines.clear();
       
  for(unsigned int i = 0; i < temp.size(); i++){      
    std::vector<MLine*>::iterator it = std::find(ele.begin(), ele.end(), temp[i]);
    if(it != ele.end()){
      delete temp[i];
    }
    else e->temporary->lines.push_back(temp[i]);
  }
  
  CTX::instance()->mesh.changed = ENT_ALL;
  CTX::instance()->pickElements = 0;
  drawContext::global()->draw();  
  Msg::StatusBar(3, false, "");
}

static void class_save_cb(Fl_Widget *w, void *data)
{
  classificationEditor *e = (classificationEditor*)data;

  e->saved->lines.insert(e->saved->lines.end(), e->temporary->lines.begin(),
                         e->temporary->lines.end());
  e->temporary->lines.clear();
  e->_elements.clear();
  e->edges_detected.clear();

  CTX::instance()->mesh.changed = ENT_ALL;
  CTX::instance()->pickElements = 0;
  NoElementsSelectedMode(e);
  drawContext::global()->draw();  
  Msg::StatusBar(3, false, "");
}

static void class_clear_cb(Fl_Widget *w, void *data)
{
  classificationEditor *e = (classificationEditor*)data;

  for(unsigned int i = 0; i < e->temporary->lines.size(); i++){      
    delete e->temporary->lines[i];
  }
  e->temporary->lines.clear();

  CTX::instance()->mesh.changed = ENT_ALL;
  CTX::instance()->pickElements = 0;
  NoElementsSelectedMode(e);
  drawContext::global()->draw();  
  Msg::StatusBar(3, false, "");
}

static void class_ok_cb(Fl_Widget *w, void *data)
{
  classificationEditor *e = (classificationEditor*)data;
  e->edge_detec->deactivate();
  e->edge_detec->hide();
  e->face_color->activate();
  e->face_color->show();
  class_save_cb(w,data);
  opt_mesh_lines(0, GMSH_SET | GMSH_GUI, e->op[0]);
  opt_mesh_surfaces_edges(0, GMSH_SET | GMSH_GUI, e->op[1]);
  opt_mesh_surfaces_faces(0, GMSH_SET | GMSH_GUI, e->op[2]);
  opt_mesh_line_width(0, GMSH_SET | GMSH_GUI, e->op[3]);

  Msg::StatusBar(3, false, "");
}


struct compareMLinePtr 
{
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
                              std::map<std::pair<int, int>, GEdge* > &newEdges)
{
  int t1 = gf1 ? gf1->tag() : -1;
  int t2 = gf2 ? gf2->tag() : -1;
  int i1 = std::min(t1,t2);
  int i2 = std::max(t1,t2);

  if(i1 == i2) return 0;

  std::map<std::pair<int, int>, GEdge*>::iterator it = 
    newEdges.find(std::make_pair<int, int>(i1, i2));
  if(it == newEdges.end()){
    discreteEdge *temporary = new discreteEdge(GModel::current(), GModel::current()->maxEdgeNum() + 1, 0, 0);
    //printf("add new edge gf1=%d gf2=%d \n", t1, t2);
    GModel::current()->add(temporary);
    newEdges[std::make_pair<int, int>(i1, i2)] = temporary;
    return temporary;
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

static void class_color_cb(Fl_Widget* w, void* data)
{
  classificationEditor *e = (classificationEditor*)data;
  std::map<MLine*, GEdge*, compareMLinePtr> lines;
  {
    GModel::eiter it =  GModel::current()->firstEdge();
    GModel::eiter ite = GModel::current()->lastEdge();
    for( ; it != ite; ++it){
      for(unsigned int i = 0; i < (*it)->lines.size();i++) 
        lines[(*it)->lines[i]] = *it;
    }
  }

  std::list<MTri3*> tris;
  {
    std::set<GFace*>::iterator it = e->_faces.begin();
    while(it != e->_faces.end()){
      GFace *gf = *it;
      for(unsigned int i = 0; i < gf->triangles.size(); i++){
        tris.push_back(new MTri3(gf->triangles[i], 0));
      }
      gf->triangles.clear();
      ++it;
    }
  }

  if ( !tris.size() )return;


  connectTriangles(tris);

  {
    std::map<MTriangle*,GFace*> reverse;

    // color all triangles
    std::list<MTri3*> ::iterator it = tris.begin();
    while(it != tris.end()){
      if(!(*it)->isDeleted()){
        discreteFace *temporary = new discreteFace(GModel::current(), GModel::current()->maxFaceNum() + 1);
        recurClassify(*it, temporary, lines, reverse);
        GModel::current()->add(temporary);
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
    
    //classify edges that are bound by different GFaces
    //--------------------------------------------------
    std::map<std::pair<int, int>, GEdge*> newEdges;
    std::set<MLine*> touched;
    recurClassifyEdges(*it, reverse, lines, touched, newEdges);
    GModel::current()->remove(e->saved);

    //check if new edges should not be splitted 
    //splitted if composed of several open or closed edges
    //-----------------------------------------------------
    for (std::map<std::pair<int, int>, GEdge*>::iterator it = newEdges.begin() ; it != newEdges.end() ; ++it){

      GEdge *ge = it->second;
      //printf("NEW edge with tag  = %d \n", ge->tag());

      std::list<MLine*> segments;
      for (unsigned int i = 0; i < ge->lines.size(); i++){
        segments.push_back(ge->lines[i]);
      }

      //for each actual GEdge
      while (!segments.empty()) {
        std::vector<MLine*> myLines;
        std::list<MLine*>::iterator it = segments.begin();
        MVertex *vB = (*it)->getVertex(0);
        MVertex *vE = (*it)->getVertex(1);
        myLines.push_back(*it);
        segments.erase(it);
        it++;
        //printf("***candidate mline %d %d of size %d \n", vB->getNum(), vE->getNum(), segments.size());

        for (int i=0; i<2; i++) {
          for (std::list<MLine*>::iterator it = segments.begin() ; it != segments.end(); ++it){ 
            MVertex *v1 = (*it)->getVertex(0);
            MVertex *v2 = (*it)->getVertex(1);
            //printf("mline %d %d \n", v1->getNum(), v2->getNum());
            std::list<MLine*>::iterator itp;
            if ( v1 == vE  ){
              //printf("->push back this mline \n");
              myLines.push_back(*it);
              itp = it;
              it++;
              segments.erase(itp);
              vE = v2;
              i = -1;
            }
            else if ( v2 == vE){
              //printf("->push back this mline \n");
              myLines.push_back(*it);
              itp = it;
              it++;
              segments.erase(itp);
              vE = v1;
              i=-1;
            }
            if (it == segments.end()) break;
          }
          if (vB == vE) break;
          if (segments.empty()) break;
          //printf("not found VB=%d vE=%d\n", vB->getNum(), vE->getNum());
          MVertex *temp = vB;
          vB = vE;
          vE = temp;
          //printf("not found VB=%d vE=%d\n", vB->getNum(), vE->getNum());
        }
        GEdge *newGe = new discreteEdge(GModel::current(), GModel::current()->maxEdgeNum() + 1, 0, 0);
        newGe->lines.insert(newGe->lines.end(), myLines.begin(), myLines.end());
        GModel::current()->add(newGe);
      }//end for each actual GEdge
    }
    //printf("end new edge with tag \n");

    for (std::map<std::pair<int, int>, GEdge*>::iterator it = newEdges.begin() ; it != newEdges.end() ; ++it){
      GEdge *ge = it->second;
      GModel::current()->remove(ge);
    }



    while(it != tris.end()){
      delete *it;
      ++it;
    }
  }
  
  CTX::instance()->mesh.changed = ENT_ALL;
  drawContext::global()->draw();  
  Msg::StatusBar(3, false, "");
}

static void updateedges_cb(Fl_Widget* w, void* data)
{
  classificationEditor *e = (classificationEditor*)data;
 
  printf("%d inside edges detected\n", (int)e->edges_detected.size());

  for(unsigned int i = 0; i < e->temporary->lines.size(); i++){
    delete e->temporary->lines[i];
  }
  e->temporary->lines.clear();

  for(unsigned int i = 0; i < e->edges_detected.size(); i++){
    edge_angle ea =  e->edges_detected[i];
    // printf("angle = %g\n",ea.angle);
    if(ea.angle <= e->_inputs[CLASSVALUE_ANGLE]->value() / 180 * M_PI)
      break;
    e->temporary->lines.push_back(new MLine(ea.v1, ea.v2));
  } 

  printf("%d boundary edges detected\n", (int)e->edges_lonly.size());
  if(e->_togbuttons[CLASSTOGBUTTON_CLOS]->value()){
    for(unsigned int i = 0 ; i < e->edges_lonly.size(); i++){
      edge_angle ea = e->edges_lonly[i];
      e->temporary->lines.push_back(new MLine(ea.v1, ea.v2));
      //check if closed loop
    } 
  }
  
  CTX::instance()->mesh.changed = ENT_ALL;
  drawContext::global()->draw();   
}

static void class_hide_cb(Fl_Widget *w, void *data)
{
  CTX::instance()->hideUnselected = !CTX::instance()->hideUnselected;
  CTX::instance()->mesh.changed = ENT_ALL;
  drawContext::global()->draw();
}

static void buildListOfEdgeAngle(e2t_cont adj, std::vector<edge_angle> &edges_detected,
                                 std::vector<edge_angle> &edges_lonly)
{
  e2t_cont::iterator it = adj.begin();
  for(; it != adj.end(); ++it){
    if(it->second.second)
      edges_detected.push_back(edge_angle(it->first.getVertex(0), 
                                          it->first.getVertex(1), 
                                          it->second.first, it->second.second));
    else 
      edges_lonly.push_back(edge_angle(it->first.getVertex(0),
                                       it->first.getVertex(1), 
                                       it->second.first, it->second.second));
  }
  std::sort(edges_detected.begin(), edges_detected.end());
}

static void class_select_cb(Fl_Widget *w, void *data)
{
  classificationEditor *e = (classificationEditor*)data;
  std::vector<MTriangle*> &ele(e->getElements());

  CTX::instance()->pickElements = 1;

  while(1) {
    CTX::instance()->mesh.changed = ENT_ALL;
    drawContext::global()->draw();

    Msg::StatusBar(3, false, "Select Elements\n"
                   "[Press 'e' to end selection or 'q' to abort]");
    
    char ib = FlGui::instance()->selectEntity(ENT_ALL);
    if(ib == 'l') {
      if(CTX::instance()->pickElements){
        for(unsigned int i = 0; i < FlGui::instance()->selectedElements.size(); i++){
          MElement *me = FlGui::instance()->selectedElements[i];
          if(me->getType() == TYPE_TRI && me->getVisibility() != 2){
            me->setVisibility(2); ele.push_back((MTriangle*)me);
          }
        }
      }
    }
    if(ib == 'r') {
      for(unsigned int i = 0; i < FlGui::instance()->selectedElements.size(); i++)
        FlGui::instance()->selectedElements[i]->setVisibility(1);
    }
    // ok, we compute edges !
    if(ib == 'e') {
      GModel::current()->setSelection(0);
      e2t_cont adj;
      buildEdgeToTriangle(ele, adj);
      buildListOfEdgeAngle(adj, e->edges_detected, e->edges_lonly);
      ElementsSelectedMode(e);
      break;
    }
    // do nothing
    if(ib == 'q') {
      GModel::current()->setSelection(0);
      ele.clear();
      break;
    }
  }
  
  updateedges_cb(0, data);

  CTX::instance()->mesh.changed = ENT_ALL;
  CTX::instance()->pickElements = 0;
  drawContext::global()->draw();  
  Msg::StatusBar(3, false, "");
}

edge_angle::edge_angle(MVertex *_v1, MVertex *_v2, MElement *t1, MElement *t2)
  : v1(_v1), v2(_v2)
{
  if(!t2) angle = 0;
  else{
    double c1[3];
    double c2[3];
    double c3[3];
    {
      MVertex *p1 = t1->getVertex(0);
      MVertex *p2 = t1->getVertex(1);
      MVertex *p3 = t1->getVertex(2);
      double a[3] = {p1->x() - p2->x(), p1->y() - p2->y(), p1->z() - p2->z()};
      double b[3] = {p1->x() - p3->x(), p1->y() - p3->y(), p1->z() - p3->z()};
      c1[2] = a[0] * b[1] - a[1] * b[0];
      c1[1] = -a[0] * b[2] + a[2] * b[0];
      c1[0] = a[1] * b[2] - a[2] * b[1];
    }
    {
      MVertex *p1 = t2->getVertex(0);
      MVertex *p2 = t2->getVertex(1);
      MVertex *p3 = t2->getVertex(2);
      double a[3] = {p1->x() - p2->x(), p1->y() - p2->y(), p1->z() - p2->z()};
      double b[3] = {p1->x() - p3->x(), p1->y() - p3->y(), p1->z() - p3->z()};
      c2[2] = a[0] * b[1] - a[1] * b[0];
      c2[1] = -a[0] * b[2] + a[2] * b[0];
      c2[0] = a[1] * b[2] - a[2] * b[1];
    }
    norme(c1);
    norme(c2);
    prodve(c1, c2, c3);
    double cosa; prosca(c1, c2, &cosa);
    double sina = norme(c3);
    angle = atan2(sina, cosa);
  }
}

classificationEditor::classificationEditor()
{
  op[0] = opt_mesh_lines(0, GMSH_GET, 0.);
  op[1] = opt_mesh_surfaces_edges(0, GMSH_GET, 0.);
  op[2] = opt_mesh_surfaces_faces(0, GMSH_GET, 0.);
  op[3] = opt_mesh_line_width(0, GMSH_SET | GMSH_GET,0.);

  opt_mesh_lines(0, GMSH_SET | GMSH_GUI, 1);
  opt_mesh_surfaces_edges(0, GMSH_SET | GMSH_GUI, 0);
  opt_mesh_surfaces_faces(0, GMSH_SET | GMSH_GUI, 1);
  opt_mesh_line_width(0, GMSH_SET | GMSH_GUI, 1.5);

  // construct GUI in terms of standard sizes
  int BBB = (int)(1.4 * BB); // labels too long
  const int width = (int)(3.5 * BBB), height = 10 * BH;

  _window = new paletteWindow
    (width, height, CTX::instance()->nonModalWindows ? true : false, "Classify");
  
  new Fl_Tabs(WB, WB, width - 2 * WB, height - 2 * WB);
  {
    Fl_Group *o = new Fl_Group
      (WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "Edge Detection");
    edge_detec = o;
    
    _buttons[CLASSBUTTON_OK] = new Fl_Button 
      (4*WB+2*BBB, 7*WB+6*BH, BBB, BH, "OK");
    _buttons[CLASSBUTTON_OK]->callback(class_ok_cb, this);
    
    _buttons[CLASSBUTTON_SELECT] = new Fl_Button 
      (2*WB, 2*WB+1*BH, BBB, BH, "Select Elements");
    _buttons[CLASSBUTTON_SELECT]->callback(class_select_cb, this);
    
    _togbuttons[CLASSTOGBUTTON_HIDE] = new Fl_Toggle_Button
      (3*WB+BBB, 2*WB+1*BH, BBB, BH, "Hide Unselected");
    _togbuttons[CLASSTOGBUTTON_HIDE]->callback(class_hide_cb,this);

    _togbuttons[CLASSTOGBUTTON_CLOS] = new Fl_Toggle_Button
      (2*WB, 4*WB+3*BH, BBB, BH, "Include Closure");
    _togbuttons[CLASSTOGBUTTON_CLOS]->callback(updateedges_cb,this);
    
    _inputs[CLASSVALUE_ANGLE] = new Fl_Value_Input
      (3*WB+BBB, 4*WB+3*BH, BBB, BH, "Treshold Angle");
    _inputs[CLASSVALUE_ANGLE]->value(40);
    _inputs [CLASSVALUE_ANGLE]->maximum(90);
    _inputs[CLASSVALUE_ANGLE]->minimum(0);
    _inputs[CLASSVALUE_ANGLE]->align(FL_ALIGN_RIGHT);
    _inputs[CLASSVALUE_ANGLE]->step(1);
    _inputs[CLASSVALUE_ANGLE]->when(FL_WHEN_RELEASE);  
    _inputs[CLASSVALUE_ANGLE]->callback(updateedges_cb,this);

    _buttons[CLASSBUTTON_DEL] = new Fl_Button 
      (2*WB, 5*WB+4*BH, BBB, BH, "Delete Edge");
    _buttons[CLASSBUTTON_DEL]->callback(class_deleteedge_cb, this);    
    _buttons[CLASSBUTTON_DEL]->deactivate();

    _buttons[CLASSBUTTON_ADD] = new Fl_Button
      (2*WB, 6*WB+5*BH, BBB, BH, "Save Selection");
    _buttons[CLASSBUTTON_ADD]->callback(class_save_cb, this);    
    _buttons[CLASSBUTTON_ADD]->deactivate();

    _buttons[CLASSBUTTON_CLEAR] = new Fl_Button 
      (2*WB, 7*WB+6*BH, BBB, BH, "Clear Selection");
    _buttons[CLASSBUTTON_CLEAR]->callback(class_clear_cb, this);    
    _buttons[CLASSBUTTON_CLEAR]->deactivate();
    o->end();
  }
  {
    Fl_Group *o = new Fl_Group
      (WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "Face Colouring");
    face_color = o;
    o->deactivate();
    o->hide();
    _buttons[CLASSBUTTON_SELFAC] = new Fl_Button
      (2*WB, 2*WB+1*BH, BBB, BH, "Select Model Face");
    _buttons[CLASSBUTTON_SELFAC]->callback(class_selectgface_cb, this);
    _buttons[CLASSBUTTON_COLOR] = new Fl_Button 
      (2*WB, 3*WB+2*BH, BBB, BH, "Classify Mesh Faces");
    _buttons[CLASSBUTTON_COLOR]->callback(class_color_cb, this);
    o->end();
  }
  {
    Fl_Group *o = new Fl_Group
      (WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "Reparametrize Surfaces");
    reverse_eng = o;
    o->hide();
    o->deactivate();
    o->end();
  }
  NoElementsSelectedMode(this);

  // allocate detected edges
  // temporary for the selection
  // saved for the ones that have been saved by the user
  // and that will be used for next step

  temporary = new discreteEdge(GModel::current(), GModel::current()->maxEdgeNum() + 1, 0, 0);
  GModel::current()->add(temporary);
  saved = new discreteEdge(GModel::current(), GModel::current()->maxEdgeNum() + 1, 0, 0);
  GModel::current()->add(saved);
  
  _window->end();
  _window->hotspot(_window);
  _window->size_range(width, (int)(0.85 * height));    
}

void mesh_classify_cb(Fl_Widget* w, void* data)
{
  // create the (static) editor
  static classificationEditor *editor = 0;
  if(!editor){
    editor = new classificationEditor();
  }
  editor->show();
}
