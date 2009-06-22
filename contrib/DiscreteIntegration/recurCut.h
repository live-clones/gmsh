#ifndef _RECUR_H_
#define _RECUR_H_

#include "DILevelset.h"
#include "Integration3D.h"

class RecurElement
{
 public:
  bool visible;
  bool isCrossed;
  DI_Element *el;
  RecurElement **sub;
  RecurElement *super;
  RecurElement (const DI_Element *e);
  ~RecurElement();
  int nbVert() const {return el->nbVert();}
  int type() const {return el->type();}
  int nbSub() const;
  // return the reference element at the root of the tree structure
  RecurElement* root();
  // return a mean value of the levelset in the element
  inline double Ls() const;
  // creates RecurElements forming a mesh of the DI_Element e with refined elements close to the zero levelset
  // return false if the element is not crossed or run along by the levelset
  bool cut (int maxlevel, const DI_Element *e, const gLevelset &LS, double TOL = -1.);
  // push the DI_Elements of the visible RecurElements into v
  void pushSubLines (std::vector<DI_Line> &v);
  void pushSubTriangles (std::vector<DI_Triangle> &v);
  void pushSubQuads (std::vector<DI_Quad> &v);
  void pushSubTetras (std::vector<DI_Tetra> &v);
  void pushSubHexas (std::vector<DI_Hexa> &v);
};

/*
class RecurTriangle
{
 public:
  bool visible;
  bool isCrossed;
  DI_Triangle *tri;
  RecurTriangle *sub[4];
  RecurTriangle *super;
  RecurTriangle(DI_Triangle triangle) : visible(false), isCrossed(false)
  {
    tri = new DI_Triangle(triangle);
    sub[0] = sub[1] = sub[2] = sub[3] = super = NULL;
  }
  RecurTriangle (const RecurTriangle &cp) : visible(cp.visible),isCrossed(cp.isCrossed){
    tri = new DI_Triangle(*(cp.tri));
    for(int i=0;i<4;i++) sub[i]=cp.sub[i];
    super = cp.super;
  }
  ~RecurTriangle() {
    delete tri;
    if(sub[0]) delete sub[0];
    if(sub[1]) delete sub[1];
    if(sub[2]) delete sub[2];
    if(sub[3]) delete sub[3];
  }
  void setVisibility (bool vis) {visible=vis;}
  // return the reference triangle at the root of the tree structure
  RecurTriangle* root();
  // return a mean value of the levelset in the triangle
  inline double V() const {return (tri->ls(0) + tri->ls(1) + tri->ls(2))/3.;}
  // creates RecurTriangles forming a mesh of the DI_Triangle tri with refined elements close to the zero levelset
  // return false if the triangle is not crossed or run along by the final levelset
  bool cut (int maxlevel, const DI_Triangle *e, const std::vector<const gLevelset *> RPN, double TOL=-1.);
  // push the DI_Triangles of the visible RecurTriangles into vT
  void pushTriangles (std::vector<DI_Triangle> &vT);
};

class RecurQuad
{
 public:
  bool visible;
  bool isCrossed;
  DI_Quad *quad;
  RecurQuad *sub[4];
  RecurQuad *super;
  RecurQuad (DI_Quad q) : visible(false), isCrossed(false)
  {
    quad = new DI_Quad(q);
    sub[0] = sub[1] = sub[2] = sub[3] = super = NULL;
  }
  RecurQuad (const RecurQuad &cp) : visible(cp.visible),isCrossed(cp.isCrossed) {
    quad = new DI_Quad(*(cp.quad));
    for(int i=0;i<4;i++) sub[i]=cp.sub[i];
    super=cp.super;
  }
  ~RecurQuad() {
    delete quad;
    if(sub[0]) delete sub[0];
    if(sub[1]) delete sub[1];
    if(sub[2]) delete sub[2];
    if(sub[3]) delete sub[3];
  }
  void setVisibility (bool vis) {visible=vis;}
  // return the reference quad at the root of the tree structure
  RecurQuad* root();
  // return a mean value of the levelset in the quad
  inline double V() const {return (quad->ls(0) + quad->ls(1) + quad->ls(2) + quad->ls(3))/4.;}
  // creates RecurQuads forming a mesh of the DI_Quad quad with refined elements close to the zero levelset
  // return false if the quad is not crossed or run along by the final levelset
  bool cut (int maxlevel, const DI_Quad *e, const std::vector<const gLevelset *> RPN, double TOL=-1.);
  // push the DI_Quads of the visible RecurQuads into vQ
  void pushQuads (std::vector<DI_Quad> &vQ);
};
*/

#endif
