//
// C++ Interface: terms
//
// Description: Class to bluid the interface element (used at initialization)
//
//
// Author:  <Gauthier BECKER>, (C) 2011
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _IELEMENT_H_
#define _IELEMENT_H_
#include "MVertex.h"
#include "MElement.h"
class IElement{
 public:
  enum IEtype{Edge};
 protected:
  std::vector<MVertex*> vertex;
  MElement *elem;
  int phys;
 public:
  IElement(std::vector<MVertex*> &v,MElement *e, int i) : vertex(v), elem(e), phys(i){};
  ~IElement(){};
  virtual unsigned long int getkey() const=0;
  virtual IEtype getType() const=0;
  // As for now only IEdge exists I don't know if these method are virtual pure
  // virtual or are only for IEdge
  virtual std::vector<MVertex*> getVertices() const{return vertex;}
  virtual MElement* getElement() const{return elem;}
  virtual MVertex* getFirstInteriorVertex() const {return vertex[2];}
  virtual MVertex* getLastInteriorVertex() const {return *vertex.end();}
  virtual int getPhys() const {return phys;}

};
#endif // _IELEMENT_H_
