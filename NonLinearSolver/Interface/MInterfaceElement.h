//
// C++ Interface: terms
//
// Description: Class of interface element used for DG
//
//
// Author:  <Gauthier BECKER>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//
// Has to be merge with interface element defined in dg project HOW ??

# ifndef _MINTERFACEELEMENT_H_
# define _MINTERFACEELEMENT_H_
#include "MElement.h"
// MinterfaceElement is a pure virtual class whose is interace has to be derived and derived from MElement too
// so MinterfaceElement can't not be derived from MElement
class MInterfaceElement{
 public:
  MInterfaceElement(){}
  ~MInterfaceElement(){}
  virtual MElement* getElem(const int index) const=0;
  virtual int getEdgeOrFaceNumber(const int index) const=0;
  virtual bool isSameDirection(const int index) const=0;
  // should return the element number !!
  virtual int getNumber() const=0; // {return{this->getNum();} in your derived class it derived from an MElement* too !!
  // compute the characteritic size of one element (This function can be defined as a method of MElement) ??
  static double characSize(MElement *e); // Area/perimeter
};
#endif // _MINTERFACEELEMENT
