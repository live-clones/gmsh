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

#include "MInterfaceLine.h"
MInterfaceLine::MInterfaceLine(std::vector<MVertex*> &v, int num, int part,
                               MElement *e_minus, MElement *e_plus) : MLineN(v, num, part), MInterfaceElement(),
                                                                      _num(MElement::getGlobalNumber()) //avoid this ??
{
  _numElem[0]=e_minus;
  _numElem[1]=e_plus;
  // Edge of element linked to interface element we identifie an interior point of the MLine (degree 2 min for shell) thus we used v[0]
  for(int jj=0;jj<2;jj++){
    int nopv = _numElem[jj]->getNumPrimaryVertices();
    std::vector<MVertex*> vv;
    for(int i = 0; i < nopv; i++){
      _numElem[jj]->getEdgeVertices(i,vv);
      for(int j = 2; j < vv.size(); j++){
        if(vv[j] == v[2]){ // v[2] because it is the first interior node
          _numEdge[jj] = i;
          if(v[0] == vv[0]) _dir[jj] = true; // same orientation
          else _dir[jj] = false;
        }
      }
    }
  }
}

void MInterfaceLine::getLocalVertexNum(const int i,std::vector<int> &vn)
{
  switch(_numEdge[i]){
  case 0 :
    vn[0] = 0;
    vn[1] = 1;
    break;
  case 1 :
    vn[0] = 1;
    vn[1] = 2;
    break;
  case 2 :
    if(_numElem[i]->getType()==TYPE_TRI){vn[0]=2;vn[1]=0;}
    else{vn[0]=2;vn[1]=3;}
    break;
  case 3 :
    vn[0] = 3;
    vn[1] = 0;
    break;
  default : Msg::Error("Impossible to get local vertex number in this case");
  }
  // interior edge node
  for(int j=2;j<vn.size();j++)
    vn[j]=_numElem[i]->getNumEdges()+_numEdge[i]*(_numElem[i]->getPolynomialOrder()-1)+(j-2);
}

  // Get the u v value on element for a abscissa u on the interface element // TODO optmize by store in the class interface element the corresponding value (if many step must be compute once)??
void MInterfaceLine::getuvOnElem(const double u, double &uem, double &vem, double &uep, double &vep)
{  // w = 0 as no volume element are taken into account. The point is defined between u=-1 and u=1 on the interface element
  double ue=0.,ve=0.;
  for(int jj=0;jj<2;jj++){
    switch(_numElem[jj]->getType()){
    case TYPE_TRI :
      switch(_numEdge[jj]){
      case 0 :
        if(_dir[jj]) {ue = 0.5 * ( 1 + u ); ve = 0.;}
        else {ue = 0.5 * ( 1 - u ); ve = 0.;}
        break;
      case 1 :
        if(_dir[jj]) {ue = 0.5 * (1 - u) ; ve = 0.5 * ( 1 + u );}
        else {ue = 0.5 * (1 + u) ; ve = 0.5 * ( 1 - u );}
        break;
      case 2 :
        if(_dir[jj]) { ue = 0; ve = 0.5 * (1 - u);}
        else { ue = 0; ve = 0.5 * (1 + u);}
        break;
      }
    break;
    case TYPE_QUA :
      switch(_numEdge[jj]){
      case 0 :
        if(_dir[jj]) {ue = u; ve = -1.;}
        else {ue =-u; ve=-1;}
        break;
      case 1 :
        if(_dir[jj]) {ue =1.; ve = u;}
        else {ue = 1.; ve = -u;}
        break;
      case 2 :
        if(_dir[jj]) {ue = -u; ve = 1;}
        else {ue = u; ve = 1;}
        break;
      case 3 :
        if(_dir[jj]) {ue = -1; ve = -u;}
        else {ue = -1; ve = u;}
        break;
      }
      break;
      default : Msg::Error("The Method doesn't work for this type of element");
    }
    if(jj==0){uem=ue;vem=ve;}
    else {uep=ue;vep=ve;}
  }
}
