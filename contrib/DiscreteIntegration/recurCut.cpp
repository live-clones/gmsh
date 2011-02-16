#ifndef RECURCUT_CC
#define RECURCUT_CC

#include "recurCut.h"

inline DI_Point* middle (const DI_Point *p1, const DI_Point *p2) {
  return new DI_Point ((p1->x() + p2->x()) / 2, (p1->y() + p2->y()) / 2, (p1->z() + p2->z()) / 2);
}

// create sub-elements recursively (according to a pattern) until maxlevel
void recurCut(RecurElement *re, int maxlevel, int level)
{
  if(level++ >= maxlevel) return;

  if(re->type() == DI_LIN) {
    // p1 p12 p2
    DI_Point* p1 = re->el->pt(0);
    DI_Point* p2 = re->el->pt(1);
    DI_Point* p12 = middle(p1, p2);
    DI_Line *l0 = new DI_Line(p1, p12);
    RecurElement *re0 = new RecurElement(l0);
    recurCut(re0, maxlevel, level);
    re->sub[0] = re0; re0->super = re;
    DI_Line *l1 = new DI_Line(p12, p2);
    RecurElement *re1 = new RecurElement(l1);
    recurCut(re1, maxlevel, level);
    re->sub[1] = re1; re1->super = re;
    delete p12;
    delete l0; delete l1;
  }
  if(re->type() == DI_TRI) {
    // p3
    // p13   p23
    // p1    p12    p2
    DI_Point *p1 = re->el->pt(0);
    DI_Point *p2 = re->el->pt(1);
    DI_Point *p3 = re->el->pt(2);
    DI_Point *p12 = middle(p1, p2);
    DI_Point *p13 = middle(p1, p3);
    DI_Point *p23 = middle(p2, p3);
    DI_Triangle *t0 = new DI_Triangle(p1, p12, p13);
    RecurElement *re0 = new RecurElement(t0);
    recurCut(re0, maxlevel, level);
    re->sub[0] = re0; re0->super = re;
    DI_Triangle *t1 = new DI_Triangle(p2, p23, p12);
    RecurElement *re1 = new RecurElement(t1);
    recurCut(re1, maxlevel, level);
    re->sub[1] = re1; re1->super = re;
    DI_Triangle *t2 = new DI_Triangle(p3, p13, p23);
    RecurElement *re2 = new RecurElement(t2);
    recurCut(re2, maxlevel, level);
    re->sub[2] = re2; re2->super = re;
    DI_Triangle *t3 = new DI_Triangle(p12, p23, p13);
    RecurElement *re3 = new RecurElement(t3);
    recurCut(re3, maxlevel, level);
    re->sub[3] = re3; re3->super = re;
    delete p12; delete p13; delete p23;
    delete t0; delete t1; delete t2; delete t3;
  }
  else if(re->type() == DI_QUA) {
    // p4    p34    p3
    // p14   p1234  p23
    // p1    p12    p2
    DI_Point *p1 = re->el->pt(0);
    DI_Point *p2 = re->el->pt(1);
    DI_Point *p3 = re->el->pt(2);
    DI_Point *p4 = re->el->pt(3);
    DI_Point *p12 = middle(p1, p2);
    DI_Point *p23 = middle(p2, p3);
    DI_Point *p34 = middle(p3, p4);
    DI_Point *p14 = middle(p1, p4);
    DI_Point *p1234 = middle(p12, p34);
    DI_Quad *q0 = new DI_Quad(p1, p12, p1234, p14);
    RecurElement *re0 = new RecurElement(q0);
    recurCut(re0, maxlevel, level);
    re->sub[0] = re0; re0->super = re;
    DI_Quad *q1 = new DI_Quad(p12, p2, p23, p1234);
    RecurElement *re1 = new RecurElement(q1);
    recurCut(re1, maxlevel, level);
    re->sub[1] = re1; re1->super = re;
    DI_Quad *q2 = new DI_Quad(p1234, p23, p3, p34);
    RecurElement *re2 = new RecurElement(q2);
    recurCut(re2, maxlevel, level);
    re->sub[2] = re2; re2->super = re;
    DI_Quad *q3 = new DI_Quad(p14, p1234, p34, p4);
    RecurElement *re3 = new RecurElement(q3);
    recurCut(re3, maxlevel, level);
    re->sub[3] = re3; re3->super = re;
    delete p12; delete p23; delete p34;
    delete p14; delete p1234;
    delete q0; delete q1; delete q2; delete q3;
  }
  else if(re->type() == DI_TET) {
    //       p4
    //       p14   p34
    //   p24 p1    p13    p3
    //    p12   p23
    // p2
    DI_Point *p1 = re->el->pt(0);
    DI_Point *p2 = re->el->pt(1);
    DI_Point *p3 = re->el->pt(2);
    DI_Point *p4 = re->el->pt(3);
    DI_Point *p12 = middle(p1, p2);
    DI_Point *p13 = middle(p1, p3);
    DI_Point *p14 = middle(p1, p4);
    DI_Point *p23 = middle(p2, p3);
    DI_Point *p24 = middle(p2, p4);
    DI_Point *p34 = middle(p3, p4);
    DI_Tetra *t0 = new DI_Tetra(p1, p12, p13, p14);
    RecurElement *re0 = new RecurElement(t0);
    recurCut(re0, maxlevel, level);
    re->sub[0] = re0; re0->super = re;
    DI_Tetra *t1 = new DI_Tetra(p2, p23, p12, p24);
    RecurElement *re1 = new RecurElement(t1);
    recurCut(re1, maxlevel, level);
    re->sub[1] = re1; re1->super = re;
    DI_Tetra *t2 = new DI_Tetra(p3, p13, p23, p34);
    RecurElement *re2 = new RecurElement(t2);
    recurCut(re2, maxlevel, level);
    re->sub[2] = re2; re2->super = re;
    DI_Tetra *t3 = new DI_Tetra(p4, p14, p34, p24);
    RecurElement *re3 = new RecurElement(t3);
    recurCut(re3, maxlevel, level);
    re->sub[3] = re3; re3->super = re;
    DI_Tetra *t4 = new DI_Tetra(p12, p14, p24, p34);
    RecurElement *re4 = new RecurElement(t4);
    recurCut(re4, maxlevel, level);
    re->sub[4] = re4; re4->super = re;
    DI_Tetra *t5 = new DI_Tetra(p12, p23, p34, p24);
    RecurElement *re5 = new RecurElement(t5);
    recurCut(re5, maxlevel, level);
    re->sub[5] = re5; re5->super = re;
    DI_Tetra *t6 = new DI_Tetra(p12, p13, p34, p23);
    RecurElement *re6 = new RecurElement(t6);
    recurCut(re6, maxlevel, level);
    re->sub[6] = re6; re6->super = re;
    DI_Tetra *t7 = new DI_Tetra(p12, p13, p14, p34);
    RecurElement *re7 = new RecurElement(t7);
    recurCut(re7, maxlevel, level);
    re->sub[7] = re7; re7->super = re;
    delete p12; delete p13; delete p14;
    delete p23; delete p24; delete p34;
    delete t0; delete t1; delete t2; delete t3;
    delete t4; delete t5; delete t6; delete t7;
  }
  else if(re->type() == DI_HEX) {
    DI_Point *p1 = re->el->pt(0);
    DI_Point *p2 = re->el->pt(1);
    DI_Point *p3 = re->el->pt(2);
    DI_Point *p4 = re->el->pt(3);
    DI_Point *p5 = re->el->pt(4);
    DI_Point *p6 = re->el->pt(5);
    DI_Point *p7 = re->el->pt(6);
    DI_Point *p8 = re->el->pt(7);
    DI_Point *p12 = middle(p1, p2);
    DI_Point *p14 = middle(p1, p4);
    DI_Point *p15 = middle(p1, p5);
    DI_Point *p23 = middle(p2, p3);
    DI_Point *p26 = middle(p2, p6);
    DI_Point *p34 = middle(p3, p4);
    DI_Point *p37 = middle(p3, p7);
    DI_Point *p48 = middle(p4, p8);
    DI_Point *p56 = middle(p5, p6);
    DI_Point *p58 = middle(p5, p8);
    DI_Point *p67 = middle(p6, p7);
    DI_Point *p78 = middle(p7, p8);
    DI_Point *p1234 = middle(p12, p34);
    DI_Point *p1256 = middle(p12, p56);
    DI_Point *p1458 = middle(p14, p58);
    DI_Point *p2367 = middle(p23, p67);
    DI_Point *p3478 = middle(p34, p78);
    DI_Point *p5678 = middle(p56, p78);
    DI_Point *p12345678 = middle(p1234, p5678);
    DI_Hexa *h0 = new DI_Hexa(p1, p12, p1234, p14, p15, p1256, p12345678, p1458);
    RecurElement *re0 = new RecurElement(h0);
    recurCut(re0, maxlevel, level);
    re->sub[0] = re0; re0->super = re;
    DI_Hexa *h1 = new DI_Hexa(p12, p2, p23, p1234, p1256, p26, p2367, p12345678);
    RecurElement *re1 = new RecurElement(h1);
    recurCut(re1, maxlevel, level);
    re->sub[1] = re1; re1->super = re;
    DI_Hexa *h2 = new DI_Hexa(p1234, p23, p3, p34, p12345678, p2367, p37, p3478);
    RecurElement *re2 = new RecurElement(h2);
    recurCut(re2, maxlevel, level);
    re->sub[2] = re2; re2->super = re;
    DI_Hexa *h3 = new DI_Hexa(p14, p1234, p34, p4, p1458, p12345678, p3478, p48);
    RecurElement *re3 = new RecurElement(h3);
    recurCut(re3, maxlevel, level);
    re->sub[3] = re3; re3->super = re;
    DI_Hexa *h4 = new DI_Hexa(p15, p1256, p12345678, p1458, p5, p56, p5678, p58);
    RecurElement *re4 = new RecurElement(h4);
    recurCut(re4, maxlevel, level);
    re->sub[4] = re4; re4->super = re;
    DI_Hexa *h5 = new DI_Hexa(p1256, p26, p2367, p12345678, p56, p6, p67, p5678);
    RecurElement *re5 = new RecurElement(h5);
    recurCut(re5, maxlevel, level);
    re->sub[5] = re5; re5->super = re;
    DI_Hexa *h6 = new DI_Hexa(p12345678, p2367, p37, p3478, p5678, p67, p7, p78);
    RecurElement *re6 = new RecurElement(h6);
    recurCut(re6, maxlevel, level);
    re->sub[6] = re6; re6->super = re;
    DI_Hexa *h7 = new DI_Hexa(p1458, p12345678, p3478, p48, p58, p5678, p78, p8);
    RecurElement *re7 = new RecurElement(h7);
    recurCut(re7, maxlevel, level);
    re->sub[7] = re7; re7->super = re;
    delete p12; delete p14; delete p15;
    delete p23; delete p26; delete p34;
    delete p37; delete p48; delete p56;
    delete p58; delete p67; delete p78;
    delete p1234; delete p1256;
    delete p1458; delete p2367;
    delete p3478; delete p5678;
    delete p12345678;
    delete h0; delete h1; delete h2; delete h3;
    delete h4; delete h5; delete h6; delete h7;
  }
}

// return true if the element re->el is crossed or run along by a primitive levelset in RPN and by the final levelset
// (the levelset is computed with the values at the nodes of the element e)
bool signChange (RecurElement *re, const DI_Element *e, const std::vector<const gLevelset *> &RPN,
                 double **nodeLs) {
  bool cS = false;
  DI_Element* elem = re->root()->el;
  std::vector<DI_CuttingPoint *> cp;
  std::vector<const gLevelset *> RPNi;
  int iPrim = 0;
  for(unsigned int l = 0; l < RPN.size(); l++) {
    const gLevelset *Lsi = RPN[l];
    RPNi.push_back(Lsi);
    if(Lsi->isPrimitive()) {
      elem->addLs(e, Lsi, iPrim++, nodeLs);
      for(unsigned int i = 0; i < cp.size(); i++)
        cp[i]->addLs(elem);
      if (re->super) re->el->addLs(elem);
      re->el->getCuttingPoints(elem, RPNi, cp);
    }
    else {
      for(unsigned int p = 0; p < cp.size(); p++)
        cp[p]->chooseLs(Lsi);
      if (re->super) re->el->chooseLs(Lsi);
    }
  }
  re->root()->el->clearLs();
  if(re->super) re->el->clearLs();

  if(cp.size() > 1 || (re->type() == DI_LIN && cp.size() > 0)) {
    for(int i = 0; i < (int)cp.size(); i++)
      if(cp[i]->ls() == 0) {cS = true; break;}
  }
  for(int i = 0; i < (int)cp.size(); i++)
    delete cp[i];
  return cS;
}

// Set isCrossed to true if a sub RecurElement is crossed. 
// If it has no sub RecurElement, set isCrossed to true if the element is crossed or run along by the levelset
//(the levelset is computed with the values at the nodes of the triangle e)
bool computeIsCrossed (RecurElement *re, const DI_Element *e, const std::vector<const gLevelset *> &RPN,
                       double **nodeLs) {
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
    double v = re->ls();
    double vm = 0.;
    if(!re->sub[0]->sub[0]) {
      for(int i = 0; i < re->nbSub(); i++){
        vm += re->sub[i]->ls();
      }
      vm = vm / re->nbSub();
    }
    else {
      for(int i = 0; i < re->nbSub(); i++){
        for(int j = 0; j < re->sub[0]->nbSub(); j++){
          vm += re->sub[i]->sub[j]->ls();
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
  delete [] sub;
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

double RecurElement::ls() const
{
  double Tot = 0;
  for(int i = 0; i < nbVert(); i++)
    Tot += el->ls(i);
  return Tot / nbVert();
}

bool RecurElement::cut(int maxlevel, const DI_Element *e, std::vector<const gLevelset *> &LsRPN,
                       double TOL, double **nodeLs)
{
  recurCut(this, maxlevel, 0);
  bool iC = computeIsCrossed(root(), e, LsRPN, nodeLs);
  if(TOL < 0.)
    recurChangeVisibility(root());
  else {
    root()->el->addLs(e, LsRPN.back());
    recurAddLs(root());
    recurChangeVisibility(root(), LsRPN, TOL);
    recurClearLs(root());
  }
  return iC;
}

#endif
