//
// C++ Interface: terms
//
// Description: Class of interface element used for DG 2D only for the moment
// thus the interface element is a line
//
// Author:  <Gauthier BECKER>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//
# ifndef _MINTERFACEELEMENT_H_
# define _MINTERFACEELEMENT_H_

#include "MLine.h"
#include "SVector3.h"
#include "MEdge.h"
#include "quadratureRules.h"

class MInterfaceElement : public MLineN{ // or don't derivate but in this case a vector with the vertices of interface element has to be save ??
  protected :
    // table of pointer on the two elements linked to the interface element
    MElement *_numElem[2];
    // edge's number linked to interface element of minus and plus element
    int _numEdge[2];
    // dir = true if the edge and the interface element are defined in the same sens and dir = false otherwise
    bool _dir[2];

  public :
    // Build function CG/DG case
    MInterfaceElement(MVertex *v0, MVertex *v1, std::vector<MVertex*> &v, int num = 0, int part = 0, MElement *e_minus = 0, MElement *e_plus = 0)
      : MLineN(v0, v1, v, num, part)
    {
      _numElem[0] = e_minus;
      _numElem[1] = e_plus;

      // Edge of element linked to interface element we identifie an interior point of the MLine (degree 2 min for plate) thus we used v[0]
      for(int jj=0;jj<2;jj++){
        int nopv = _numElem[jj]->getNumPrimaryVertices();
        std::vector<MVertex*> vv;
        for(int i = 0; i < nopv; i++){
          _numElem[jj]->getEdgeVertices(i,vv);
          for(int j = 2; j < vv.size(); j++){
            if(vv[j] == v[0]){
              _numEdge[jj] = i;
              if(v0 == vv[0]) _dir[jj] = true; // same orientation
              else _dir[jj] = false;
            }
          }
        }
      }
    }
    MInterfaceElement(std::vector<MVertex*> &v, int num = 0, int part = 0, MElement *e_minus = 0, MElement *e_plus = 0)
      : MLineN(v, num, part)
    {
      _numElem[0] = e_minus;
      _numElem[1] = e_plus;

       // Edge of element linked to interface element we identifie an interior point of the MLine (degree 2 min for plate) thus we used v[0]
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
    // Destructor
    ~MInterfaceElement(){}

    // Give the number of the elements in a vector
    MElement ** getElem(){return _numElem;}

    // Give the number of minus 0 or plus 1 element
    MElement * getElem(int index){return _numElem[index];}

    // Get the u v value on element for a abscissa u on the interface element // TODO optmize by store in the class interface element the corresponding value (if many step must be compute once)??
    void getuvOnElem(const double u, double &uem, double &vem, double &uep, double &vep){ // w = 0 as no volume element are taken into account. The point is defined between u=-1 and u=1 on the interface element
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
    // Compute the characteristic size of the side h_s = max_e (area_e/perimeter_e)
    double getCharacteristicSize(){
      //printf("minus\n");
      double cm = this->characSize(_numElem[0]);
      //printf("plus\n");
      double cp = this->characSize(_numElem[1]);
      return cm > cp ? cm : cp;
    }

    // This function can be defined as a method of MElement ??
    double characSize(MElement *e){
      // Compute the area of the element
      // jacobian value compute somewhere else --> Optimize it ?? (But change at each iteration)
      GaussQuadrature Integ_Bulk(GaussQuadrature::GradGrad);
      IntPt *GP;
      double perimeter = 0., Area = 0.;
      double jac[3][3];
      int npts=Integ_Bulk.getIntPoints(e,&GP);
 //     Area = 0.;
      for( int i = 0; i < npts; i++){
        // Coordonate of Gauss' point i
        const double u = GP[i].pt[0]; const double v = GP[i].pt[1]; const double w = GP[i].pt[2];
        const double weight = GP[i].weight; const double detJ = e->getJacobian(u, v, w, jac); // Or compute jacobian with crossprod(phi0[0],phi0[1]) ??
        Area += weight * detJ;
      }
      // perimeter
      int nside = e->getNumEdges();
      for( int i = 0; i < nside; i++){
        // Distance between the two extremities
        MEdge edge = e->getEdge(i);
        perimeter += edge.getVertex(0)->distance(edge.getVertex(1));
      }
      return Area/perimeter;
    };
    bool getdir(const int i){return _dir[i];}
};
#endif // MInterfaceElement
