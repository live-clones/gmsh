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
  inline double ls() const;
  // creates RecurElements forming a mesh of the DI_Element e with refined elements close to the zero levelset
  // return false if the element is not crossed or run along by the levelset
  bool cut (int maxlevel, const DI_Element *e, std::vector<const gLevelset *> &LsRPN, double TOL = -1.,
            double **nodeLs = NULL);
};

// push the DI_Elements of the visible RecurElements into v
template <class T>
static void pushSubElements (RecurElement *re, std::vector<T *> &v)
{
  if(re->visible)
    v.push_back(new T(*((T*)re->el)));
  if(re->sub[0]){
    for(int i = 0; i < re->nbSub(); i++)
      pushSubElements(re->sub[i], v);
  }
}

#endif
