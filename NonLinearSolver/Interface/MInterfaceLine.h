//
// C++ Interface: terms
//
// Description: Class of interface element of line used for DG
//
//
// Author:  <Gauthier BECKER>, (C) 2011
//
// Copyright: See COPYING file that comes with this distribution
//
//
// Has to be merge with interface element defined in dg project HOW ??

#ifndef _MINTERFACELINE_H_
#define _MINTERFACELINE_H_
#include "MLine.h"
#include "MVertex.h"
#include "MInterfaceElement.h"
class MInterfaceLine : public MLineN, public MInterfaceElement{ // or don't derivate but in this case a vector with the vertices of interface element has to be save ??
  protected :
    // table of pointer on the two elements linked to the interface element
    MElement *_numElem[2];
    // edge's number linked to interface element of minus and plus element
    int _numEdge[2];
    // dir = true if the edge and the interface element are defined in the same sens and dir = false otherwise
    bool _dir[2];

  public :

    MInterfaceLine(std::vector<MVertex*> &v, int num = 0, int part = 0, MElement *e_minus = 0, MElement *e_plus = 0);

    // Destructor
    ~MInterfaceLine(){}

    // Try to avoid this HOW
    int getNumber() const{return this->getNum();}
    // Give the number of minus 0 or plus 1 element
    MElement* getElem(int index) const {return _numElem[index];}

    void getuvOnElem(const double u, double &uem, double &vem, double &uep, double &vep);

    // Return the edge number of element
    int getEdgeOrFaceNumber(const int i) const {return _numEdge[i];}

    // Return the local vertex number of interface
    void getLocalVertexNum(const int i,std::vector<int> &vn);
    // Compute the characteristic size of the side h_s = max_e (area_e/perimeter_e)
    double getCharacteristicSize(){
      double cm = this->characSize(_numElem[0]);
      double cp = this->characSize(_numElem[1]);
      return cm > cp ? cm : cp;
    }
    bool isSameDirection(const int i) const {return _dir[i];}
};
#endif // _MINTERFACELINE_H_
