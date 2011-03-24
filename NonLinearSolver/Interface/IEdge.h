//
// C++ Interface: terms
//
// Description: Class to bluid an interface line (used at initialization)
//
//
// Author:  <Gauthier BECKER>, (C) 2011
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _IEDEGE_H_
#define _IEDEGE_H_
#include "IElement.h"
#include "MVertex.h"
#include "MElement.h"
// Class used to build 2D interface element
class IEdge : public IElement{
  public :
    IEdge(std::vector<MVertex*> &v,MElement *e, int i) : IElement(v,e,i){};
    ~IEdge(){};
    unsigned long int getkey() const{
      int i1,i2,i3;
      i1 = vertex[0]->getNum();
      i2 = vertex[1]->getNum();
      i1>i2 ? i3=i1*100000+i2 : i3=i2*100000+i1; // change this
      return i3;
    }
    virtual IElement::IEtype getType()const{return IElement::Edge;}
};
#endif // _IEDEGE_H_
