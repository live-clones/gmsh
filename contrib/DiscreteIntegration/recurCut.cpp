#ifndef RECURCUT_CC
#define RECURCUT_CC

#include "recurCut.h"

inline DI_Point middle (const DI_Point &p1, const DI_Point &p2) {
  return DI_Point ((p1.x() + p2.x()) / 2, (p1.y() + p2.y()) / 2, (p1.z() + p2.z()) / 2);
}

// create sub-elements recursively (according to a pattern) until maxlevel
void recurCut(RecurElement *re, int maxlevel, int level)
{
  if(level++ >= maxlevel) return;

  if(re->type() == DI_LIN) {
    // p1 p12 p2
    DI_Point p1 = re->el->pt(0);
    DI_Point p2 = re->el->pt(1);
    DI_Point p12 = middle(p1, p2);
    RecurElement *re0 = new RecurElement(&DI_Line(p1, p12));
    recurCut(re0, maxlevel, level);
    re->sub[0] = re0; re0->super = re;
    RecurElement *re1 = new RecurElement(&DI_Line(p12, p2));
    recurCut(re1, maxlevel, level);
    re->sub[1] = re1; re1->super = re;
  }
  if(re->type() == DI_TRI) {
    // p3
    // p13   p23
    // p1    p12    p2
    DI_Point p1 = re->el->pt(0);
    DI_Point p2 = re->el->pt(1);
    DI_Point p3 = re->el->pt(2);
    DI_Point p12 = middle(p1, p2);
    DI_Point p13 = middle(p1, p3);
    DI_Point p23 = middle(p2, p3);
    RecurElement *re0 = new RecurElement(&DI_Triangle(p1, p12, p13));
    recurCut(re0, maxlevel, level);
    re->sub[0] = re0; re0->super = re;
    RecurElement *re1 = new RecurElement(&DI_Triangle(p2, p12, p23));
    recurCut(re1, maxlevel, level);
    re->sub[1] = re1; re1->super = re;
    RecurElement *re2 = new RecurElement(&DI_Triangle(p3, p13, p23));
    recurCut(re2, maxlevel, level);
    re->sub[2] = re2; re2->super = re;
    RecurElement *re3 = new RecurElement(&DI_Triangle(p12, p13, p23));
    recurCut(re3, maxlevel, level);
    re->sub[3] = re3; re3->super = re;
  }
  else if(re->type() == DI_QUA) {
    // p4    p34    p3
    // p14   p1234  p23
    // p1    p12    p2
    DI_Point p1 = re->el->pt(0);
    DI_Point p2 = re->el->pt(1);
    DI_Point p3 = re->el->pt(2);
    DI_Point p4 = re->el->pt(3);
    DI_Point p12 = middle(p1, p2);
    DI_Point p23 = middle(p2, p3);
    DI_Point p34 = middle(p3, p4);
    DI_Point p14 = middle(p1, p4);
    DI_Point p1234 = middle(p12, p34);
    RecurElement *re0 = new RecurElement(&DI_Quad(p1, p12, p1234, p14));
    recurCut(re0, maxlevel, level);
    re->sub[0] = re0; re0->super = re;
    RecurElement *re1 = new RecurElement(&DI_Quad(p12, p2, p23, p1234));
    recurCut(re1, maxlevel, level);
    re->sub[1] = re1; re1->super = re;
    RecurElement *re2 = new RecurElement(&DI_Quad(p1234, p23, p3, p34));
    recurCut(re2, maxlevel, level);
    re->sub[2] = re2; re2->super = re;
    RecurElement *re3 = new RecurElement(&DI_Quad(p14, p1234, p34, p4));
    recurCut(re3, maxlevel, level);
    re->sub[3] = re3; re3->super = re;
  }
  else if(re->type() == DI_TET) {
    DI_Point p1 = re->el->pt(0);
    DI_Point p2 = re->el->pt(1);
    DI_Point p3 = re->el->pt(2);
    DI_Point p4 = re->el->pt(3);
    DI_Point p12 = middle(p1, p2);
    DI_Point p13 = middle(p1, p3);
    DI_Point p14 = middle(p1, p4);
    DI_Point p23 = middle(p2, p3);
    DI_Point p24 = middle(p2, p4);
    DI_Point p34 = middle(p3, p4);
    RecurElement *re0 = new RecurElement(&DI_Tetra(p1, p12, p13, p14));
    recurCut(re0, maxlevel, level);
    re->sub[0] = re0; re0->super = re;
    RecurElement *re1 = new RecurElement(&DI_Tetra(p2, p12, p23, p24));
    recurCut(re1, maxlevel, level);
    re->sub[1] = re1; re1->super = re;
    RecurElement *re2 = new RecurElement(&DI_Tetra(p3, p13, p23, p34));
    recurCut(re2, maxlevel, level);
    re->sub[2] = re2; re2->super = re;
    RecurElement *re3 = new RecurElement(&DI_Tetra(p4, p14, p24, p34));
    recurCut(re3, maxlevel, level);
    re->sub[3] = re3; re3->super = re;
    RecurElement *re4 = new RecurElement(&DI_Tetra(p12, p14, p24, p34));
    recurCut(re4, maxlevel, level);
    re->sub[4] = re4; re4->super = re;
    RecurElement *re5 = new RecurElement(&DI_Tetra(p12, p23, p24, p34));
    recurCut(re5, maxlevel, level);
    re->sub[5] = re5; re5->super = re;
    RecurElement *re6 = new RecurElement(&DI_Tetra(p12, p13, p23, p34));
    recurCut(re6, maxlevel, level);
    re->sub[6] = re6; re6->super = re;
    RecurElement *re7 = new RecurElement(&DI_Tetra(p12, p13, p14, p34));
    recurCut(re7, maxlevel, level);
    re->sub[7] = re7; re7->super = re;
  }
  else if(re->type() == DI_HEX) {
    DI_Point p1 = re->el->pt(0);
    DI_Point p2 = re->el->pt(1);
    DI_Point p3 = re->el->pt(2);
    DI_Point p4 = re->el->pt(3);
    DI_Point p5 = re->el->pt(4);
    DI_Point p6 = re->el->pt(5);
    DI_Point p7 = re->el->pt(6);
    DI_Point p8 = re->el->pt(7);
    DI_Point p12 = middle(p1, p2);
    DI_Point p14 = middle(p1, p4);
    DI_Point p15 = middle(p1, p5);
    DI_Point p23 = middle(p2, p3);
    DI_Point p26 = middle(p2, p6);
    DI_Point p34 = middle(p3, p4);
    DI_Point p37 = middle(p3, p7);
    DI_Point p48 = middle(p4, p8);
    DI_Point p56 = middle(p5, p6);
    DI_Point p58 = middle(p5, p8);
    DI_Point p67 = middle(p6, p7);
    DI_Point p78 = middle(p7, p8);
    DI_Point p1234 = middle(p12, p34);
    DI_Point p1256 = middle(p12, p56);
    DI_Point p1458 = middle(p14, p58);
    DI_Point p2367 = middle(p23, p67);
    DI_Point p3478 = middle(p34, p78);
    DI_Point p5678 = middle(p56, p78);
    DI_Point p12345678 = middle(p1234, p5678);
    RecurElement *re0 = new RecurElement(&DI_Hexa(p1, p12, p1234, p14, p15, p1256, p12345678, p1458));
    recurCut(re0, maxlevel, level);
    re->sub[0] = re0; re0->super = re;
    RecurElement *re1 = new RecurElement(&DI_Hexa(p2, p23, p1234, p12, p26, p2367, p12345678, p1256));
    recurCut(re1, maxlevel, level);
    re->sub[1] = re1; re1->super = re;
    RecurElement *re2 = new RecurElement(&DI_Hexa(p3, p34, p1234, p23, p37, p3478, p12345678, p2367));
    recurCut(re2, maxlevel, level);
    re->sub[2] = re2; re2->super = re;
    RecurElement *re3 = new RecurElement(&DI_Hexa(p4, p14, p1234, p34, p48, p1458, p12345678, p3478));
    recurCut(re3, maxlevel, level);
    re->sub[3] = re3; re3->super = re;
    RecurElement *re4 = new RecurElement(&DI_Hexa(p5, p58, p5678, p56, p15, p1458, p12345678, p1256));
    recurCut(re4, maxlevel, level);
    re->sub[4] = re4; re4->super = re;
    RecurElement *re5 = new RecurElement(&DI_Hexa(p6, p56, p5678, p67, p26, p1256, p12345678, p2367));
    recurCut(re5, maxlevel, level);
    re->sub[5] = re5; re5->super = re;
    RecurElement *re6 = new RecurElement(&DI_Hexa(p7, p67, p5678, p78, p37, p2367, p12345678, p3478));
    recurCut(re6, maxlevel, level);
    re->sub[6] = re6; re6->super = re;
    RecurElement *re7 = new RecurElement(&DI_Hexa(p8, p78, p5678, p58, p48, p3478, p12345678, p1458));
    recurCut(re7, maxlevel, level);
    re->sub[7] = re7; re7->super = re;
  }
}

// return true if the element re->el is crossed or run along by a primitive levelset in RPN and by the final levelset
// (the levelset is computed with the values at the nodes of the element e)
bool signChange (RecurElement *re, const DI_Element *e, const std::vector<const gLevelset *> &RPN,
                 std::map<int, double> nodeLs[8]) {
  bool cS = false;
  DI_Element* elem = re->root()->el;
  std::vector<DI_CuttingPoint> cp;
  std::vector<const gLevelset *> RPNi;
  for(unsigned int l = 0; l < RPN.size(); l++) {
    const gLevelset *Lsi = RPN[l];
    RPNi.push_back(Lsi);
    if(Lsi->isPrimitive()) {
      if(nodeLs && nodeLs[0].count(Lsi->getTag())) elem->addLs(Lsi->getTag(), nodeLs);
      else elem->addLs(e, *Lsi);
      for(unsigned int i = 0; i < cp.size(); i++)
        cp[i].addLs(elem);
      if (re->super) re->el->addLs(elem);
      re->el->getCuttingPoints(elem, RPNi, cp);
    }
    else {
      for(unsigned int p = 0; p < cp.size(); p++)
        cp[p].chooseLs(Lsi);
      re->el->chooseLs(Lsi);
    }
  }
  re->el->clearLs();
  re->root()->el->clearLs();

  if(cp.size() > 1 || (re->type() == DI_LIN && cp.size() > 0)) {
    for(int i = 0; i < (int)cp.size(); i++)
      if(cp[i].ls() == 0) {cS = true; break;}
  }
  return cS;
}

// Set isCrossed to true if a sub RecurElement is crossed. 
// If it has no sub RecurElement, set isCrossed to true if the element is crossed or run along by the levelset
//(the levelset is computed with the values at the nodes of the triangle e)
bool computeIsCrossed (RecurElement *re, const DI_Element *e, const std::vector<const gLevelset *> &RPN,
                       std::map<int, double> nodeLs[8]) {
  if (!re->sub[0])
    re->isCrossed = signChange(re, e, RPN, nodeLs);
  else {
    bool iC = computeIsCrossed(re->sub[0], e, RPN, nodeLs);
    for(int i = 1; i < re->nbSub(); i++){
      bool iCi = computeIsCrossed(re->sub[i], e, RPN, nodeLs);
      iC = iC || iCi;
    }
    re->isCrossed = iC;
  }
  return re->isCrossed;
}

// Recursively set the visibility to true if the RecurElement is crossed and has no sub RecurElement
// or if the RecurElement is not crossed and the super RecurElement is crossed.
void recurChangeVisibility(RecurElement *re){
  bool superIC = (re->super) ? re->super->isCrossed : true;

  if((re->isCrossed && !re->sub[0]) || (!re->isCrossed && superIC)) {
    re->visible = true;
    return;
  }
  for(int i = 0; i < re->nbSub(); i++)
    recurChangeVisibility(re->sub[i]);
}

void recurChangeVisibility(RecurElement *re, const std::vector<const gLevelset *> &RPN, double TOL){
  printf("rCV : "); re->el->printls();
  if(!re->sub[0]){
    re->visible = true;
  }
  else {
    re->el->printls();
    double v = re->Ls();
    double vm = 0.;
    if(!re->sub[0]->sub[0]) {
      for(int i = 0; i < re->nbSub(); i++){
        re->sub[i]->el->printls();
        vm += re->sub[i]->Ls();
      }
      vm = vm / re->nbSub();
    }
    else {
      for(int i = 0; i < re->nbSub(); i++){
        for(int j = 0; j < re->sub[0]->nbSub(); j++){
          re->sub[i]->sub[j]->el->printls();
          vm += re->sub[i]->sub[j]->Ls();
        }
      }
      vm = vm / (re->nbSub()*re->sub[0]->nbSub());
    }
    if(fabs(v - vm) < TOL)
      re->visible = true;
    else {
      for(int i = 0; i < re->nbSub(); i++)
        recurChangeVisibility(re->sub[i], RPN, TOL);
    }
    printf("v=%g vm=%g vis=%d \n",v,vm,re->visible);
  }
}

void recurAddLs(RecurElement *re) {
  if(re != re->root())
    re->el->addLs(re->root()->el);
  if(re->sub[0])
    for(int i = 0; i < re->nbSub(); i++)
      recurAddLs(re->sub[i]);
}

void recurClearLs(RecurElement *re) {
  re->el->clearLs();
  if(re->sub[0])
    for(int i = 0; i < re->nbSub(); i++)
      recurClearLs(re->sub[i]);
}

RecurElement::RecurElement(const DI_Element *e) : visible(false), isCrossed(false)
{
  switch(e->type()) {
    case DI_LIN :
      el = new DI_Line(*((DI_Line*)e));
      break;
    case DI_TRI :
      el = new DI_Triangle(*((DI_Triangle*)e));
      break;
    case DI_QUA :
      el = new DI_Quad(*((DI_Quad*)e));
      break;
    case DI_TET :
      el = new DI_Tetra(*((DI_Tetra*)e));
      break;
    case DI_HEX :
      el = new DI_Hexa(*((DI_Hexa*)e));
      break;
    default :
      el = NULL;
  }
  super = NULL;
  sub = new RecurElement*[nbSub()];
  for(int i = 0; i < nbSub(); i++)
    sub[i] = NULL;
}

RecurElement::~RecurElement ()
{
  for(int i = 0; i < nbSub(); i++)
    if(sub[i]) delete sub[i];
  if(el) delete el;
}

int RecurElement::nbSub() const
{
  switch(type()) {
    case DI_LIN :
      return 2;
    case DI_TRI :
      return 4;
    case DI_QUA :
      return 4;
    case DI_TET :
      return 8;
    case DI_HEX :
      return 8;
    default :
      return 0;
  }
}

RecurElement* RecurElement::root()
{
  if(super) return super->root();
  return this;
}

double RecurElement::Ls() const
{
  double Tot = 0;
  for(int i = 0; i < nbVert(); i++)
    Tot += el->ls(i);
  return Tot / nbVert();
}

bool RecurElement::cut(int maxlevel, const DI_Element *e, const gLevelset &LS, double TOL,
                       std::map<int, double> nodeLs[8])
{
  std::vector<const gLevelset *> RPN;
  LS.getRPN(RPN);
  recurCut(this, maxlevel, 0);
  bool iC = computeIsCrossed(root(), e, RPN, nodeLs);
  if(TOL < 0.)
    recurChangeVisibility(root());
  else {
    root()->el->addLs(e, LS);
    recurAddLs(root());
    recurChangeVisibility(root(), RPN, TOL);
    recurClearLs(root());
  }
  return iC;
}


/*
//----------------------------------------------------------------------------------------------



// create sub-triangles recursively (according to a 4-sub-triangles pattern) until maxlevel
void recurCut(RecurTriangle *t, int maxlevel, int level)
{
  if(level++ >= maxlevel) return;

  // p3
  // p13   p23
  // p1    p12    p2
  DI_Point p1 = t->tri->pt(0);
  DI_Point p2 = t->tri->pt(1);
  DI_Point p3 = t->tri->pt(2);
  DI_Point p12 ((p1.x()+p2.x())*0.5,(p1.y()+p2.y())*0.5,(p1.z()+p2.z())*0.5);
  DI_Point p13 ((p1.x()+p3.x())*0.5,(p1.y()+p3.y())*0.5,(p1.z()+p3.z())*0.5);
  DI_Point p23 ((p2.x()+p3.x())*0.5,(p2.y()+p3.y())*0.5,(p2.z()+p3.z())*0.5);
  RecurTriangle *tr1 = new RecurTriangle(DI_Triangle(p1,p12,p13));
  recurCut(tr1, maxlevel, level);
  RecurTriangle *tr2 = new RecurTriangle(DI_Triangle(p2,p23,p12));
  recurCut(tr2, maxlevel, level);
  RecurTriangle *tr3 = new RecurTriangle(DI_Triangle(p3,p13,p23));
  recurCut(tr3, maxlevel, level);
  RecurTriangle *tr4 = new RecurTriangle(DI_Triangle(p12,p23,p13));
  recurCut(tr4, maxlevel, level);
  tr1->super = t;
  tr2->super = t;
  tr3->super = t;
  tr4->super = t;
  t->sub[0] = tr1;
  t->sub[1] = tr2;
  t->sub[2] = tr3;
  t->sub[3] = tr4;
}

// return true if the triangle t->tri is crossed or run along by a primitive levelset in RPN and by the final levelset
// (the levelset is computed with the values at the nodes of the triangle e)
bool signChange (RecurTriangle *t, const DI_Triangle *e, const std::vector<const gLevelset *> RPN) {
  bool cS=false;
  std::vector<const gLevelset *> RPNi;
  DI_Triangle tt(*(t->root()->tri));
  std::vector<DI_CuttingPoint> cp;
  for(int l=0;l<(int)RPN.size();l++) {
    const gLevelset *Lsi = RPN[l];
    RPNi.push_back(Lsi);
    if(Lsi->isPrimitive()) {
      tt.computeLs(e,*Lsi);
      for(int i=0;i<(int)cp.size();i++)
        cp[i].addLs(&tt);
      t->tri->addLs(&tt);
      t->tri->getCuttingPoints(&tt,RPNi,cp);
    }
    else {
      for(int p=0;p<(int)cp.size();p++)
        cp[p].chooseLs(Lsi);
      t->tri->chooseLs(Lsi);
    }
  }
  if(cp.size()>1) {
    for(int i=0;i<(int)cp.size();i++)
      if(cp[i].ls()==0) {cS=true; break;}
  }
  t->tri->clearLs();
  return cS;
}

// Set isCrossed to true if a sub RecurTriangle is crossed. 
// If it has no sub RecurTriangle, set isCrossed to true if the triangle is crossed or run along by the levelset
//(the levelset is computed with the values at the nodes of the triangle e)
bool computeIsCrossed (RecurTriangle *t, const DI_Triangle *e, const std::vector<const gLevelset *> RPN) {
  if (t->sub[0]==NULL)
    t->isCrossed = signChange(t,e,RPN);
  else {
    bool iC0 = computeIsCrossed(t->sub[0],e,RPN);
    bool iC1 = computeIsCrossed(t->sub[1],e,RPN);
    bool iC2 = computeIsCrossed(t->sub[2],e,RPN);
    bool iC3 = computeIsCrossed(t->sub[3],e,RPN);
    t->isCrossed = (iC0 || iC1 || iC2 || iC3);
  }
  return t->isCrossed;
}

// Recursively set the visibility to true if the RecurTriangle is crossed and has no sub recurTriangle
// or if the RecurTriangle is not crossed and the super RecurTriangle is crossed.
void changeVisibility(RecurTriangle *t){
  bool superIC = true;
  if(t->super)
    superIC = t->super->isCrossed;
  if((t->isCrossed && t->sub[0]==NULL) || (!t->isCrossed && superIC))
    t->setVisibility(true);

  if(t->sub[0]){
    changeVisibility(t->sub[0]);
    changeVisibility(t->sub[1]);
    changeVisibility(t->sub[2]);
    changeVisibility(t->sub[3]);
  }
}

RecurTriangle* RecurTriangle::root()
{
  if(super) return super->root();
  return this;
}

bool RecurTriangle::cut(int maxlevel, const DI_Triangle *e, const std::vector<const gLevelset *> RPN, double TOL)
{
  recurCut(this, maxlevel, 0);
  bool iC=false;
  if(TOL<0.){
    iC = computeIsCrossed(root(),e,RPN);
    changeVisibility(root());
  }
  else{
    iC = computeIsCrossed(root(),e,RPN);
    changeVisibility(root());
  }
  return iC;
}

void RecurTriangle::pushTriangles (std::vector<DI_Triangle> &vT)
{
  if(visible)
    vT.push_back(DI_Triangle(*tri));
  if(sub[0]){
    sub[0]->pushTriangles(vT);
    sub[1]->pushTriangles(vT);
    sub[2]->pushTriangles(vT);
    sub[3]->pushTriangles(vT);
  }
}

//----------------------------------------------------------------------------------------------

// create sub-quads recursively (according to a 4-sub-quads pattern) until maxlevel
void recurCut(RecurQuad *q, int maxlevel, int level)
{
  if(level++ >= maxlevel) return;

  // p4    p34    p3
  // p14   p1234  p23
  // p1    p12    p2
  DI_Point p1 = q->quad->pt(0);
  DI_Point p2 = q->quad->pt(1);
  DI_Point p3 = q->quad->pt(2);
  DI_Point p4 = q->quad->pt(3);
  DI_Point p12 ((p1.x()+p2.x())*0.5,(p1.y()+p2.y())*0.5,(p1.z()+p2.z())*0.5);
  DI_Point p23 ((p2.x()+p3.x())*0.5,(p2.y()+p3.y())*0.5,(p2.z()+p3.z())*0.5);
  DI_Point p34 ((p3.x()+p4.x())*0.5,(p3.y()+p4.y())*0.5,(p3.z()+p4.z())*0.5);
  DI_Point p14 ((p1.x()+p4.x())*0.5,(p1.y()+p4.y())*0.5,(p1.z()+p4.z())*0.5);
  DI_Point p1234 ((p12.x()+p34.x())*0.5,(p12.y()+p34.y())*0.5,(p12.z()+p34.z())*0.5);
  RecurQuad *q1 = new RecurQuad(DI_Quad(p1,p12,p1234,p14));
  recurCut(q1, maxlevel, level);
  RecurQuad *q2 = new RecurQuad(DI_Quad(p12,p2,p23,p1234));
  recurCut(q2, maxlevel, level);
  RecurQuad *q3 = new RecurQuad(DI_Quad(p1234,p23,p3,p34));
  recurCut(q3, maxlevel, level);
  RecurQuad *q4 = new RecurQuad(DI_Quad(p14,p1234,p34,p4));
  recurCut(q4, maxlevel, level);
  q1->super = q;
  q2->super = q;
  q3->super = q;
  q4->super = q;
  q->sub[0] = q1;
  q->sub[1] = q2;
  q->sub[2] = q3;
  q->sub[3] = q4;
}

// return true if the quad q->quad is crossed or run along by a primitive levelset in RPN and by the final levelset
// (the levelset is computed with the values at the nodes of the quad e)
bool signChange (RecurQuad *q, const DI_Quad *e, const std::vector<const gLevelset *> RPN) {
  bool cS=false;
  std::vector<const gLevelset *> RPNi;
  DI_Quad qq(*(q->root()->quad));
  std::vector<DI_CuttingPoint> cp;
  for(int l=0;l<(int)RPN.size();l++) {
    const gLevelset *Lsi = RPN[l];
    RPNi.push_back(Lsi);
    if(Lsi->isPrimitive()) {
      qq.computeLs(e,*Lsi);
      for(int i=0;i<(int)cp.size();i++)
        cp[i].addLs(&qq);
      q->quad->addLs(&qq);
      q->quad->getCuttingPoints(&qq,RPNi,cp);
    }
    else {
      for(int p=0;p<(int)cp.size();p++)
        cp[p].chooseLs(Lsi);
      q->quad->chooseLs(Lsi);
    }
  }
  if(cp.size()>1) {
    for(int i=0;i<(int)cp.size();i++)
      if(cp[i].ls()==0) {cS=true; break;}
  }
  q->quad->clearLs();
  return cS;
}

// Set isCrossed to true if a sub RecurQuad is crossed. 
// If it has no sub RecurQuad, set isCrossed to true if the quad is crossed or run along by the levelset
//(the levelset is computed with the values at the nodes of the quad e)
bool computeIsCrossed (RecurQuad *q, const DI_Quad *e, const std::vector<const gLevelset *> RPN) {
  if (q->sub[0]==NULL)
    q->isCrossed = signChange(q,e,RPN);
  else {
    bool iC0 = computeIsCrossed(q->sub[0],e,RPN);
    bool iC1 = computeIsCrossed(q->sub[1],e,RPN);
    bool iC2 = computeIsCrossed(q->sub[2],e,RPN);
    bool iC3 = computeIsCrossed(q->sub[3],e,RPN);
    q->isCrossed = (iC0 || iC1 || iC2 || iC3);
  }
  return q->isCrossed;
}

// Recursively set the visibility to true if the RecurQuad is crossed and has no sub RecurQuad
// or if the RecurQuad is not crossed and the parent RecurQuad is crossed.
void changeVisibility(RecurQuad *q){
  bool superIC = true;
  if(q->super)
    superIC = q->super->isCrossed;
  if((q->isCrossed && q->sub[0]==NULL) || (!q->isCrossed && superIC))
    q->setVisibility(true);

  if(q->sub[0]){
    changeVisibility(q->sub[0]);
    changeVisibility(q->sub[1]);
    changeVisibility(q->sub[2]);
    changeVisibility(q->sub[3]);
  }
}

RecurQuad* RecurQuad::root()
{
  if(super) return super->root();
  return this;
}

bool RecurQuad::cut(int maxlevel, const DI_Quad *e, const std::vector<const gLevelset *> RPN, double TOL)
{
  recurCut(this, maxlevel, 0);
  bool iC=false;
  if(TOL<0.){
    iC = computeIsCrossed(root(),e,RPN);
    changeVisibility(root());
  }
  else{
    iC = computeIsCrossed(root(),e,RPN);
    changeVisibility(root());
  }
  return iC;
}

void RecurQuad::pushQuads (std::vector<DI_Quad> &vQ)
{
  if(visible)
    vQ.push_back(DI_Quad(*quad));
  if(sub[0]){
    sub[0]->pushQuads(vQ);
    sub[1]->pushQuads(vQ);
    sub[2]->pushQuads(vQ);
    sub[3]->pushQuads(vQ);
  }
}
*/

#endif
