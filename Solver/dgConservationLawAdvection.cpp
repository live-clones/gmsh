#include "dgConservationLaw.h"
#include "fullMatrix.h"
#include "dgGroupOfElements.h"
#include "SPoint3.h"
#include "MElement.h"
void getV(SPoint3 &p, double (&v)[3]){
  /*double r=hypot(p.x(),p.y());
  double alpha=atan2(p.y(),p.x());
  v[0]=r*sin(alpha);
  v[1]=-r*cos(alpha);
  v[2]=0;*/
  v[0]=0.15;
  v[1]=0;
  v[2]=0;
}

class dgAdvectionFluxTerm : public dgTerm {
  void operator () (const dgElement &el, fullMatrix<double> fcx[]) const
  {
    const fullMatrix<double> &sol = el.solution();
    const fullMatrix<double> &QP = el.integration();
    for(int i=0; i< sol.size1(); i++) {
      SPoint3 p;
      el.element()->pnt(QP(i,0),QP(i,1),QP(i,2),p);
      double v[3];
      getV(p,v);
      fcx[0](i,0) = sol(i,0)*v[0];
      fcx[1](i,0) = sol(i,0)*v[1];
      fcx[2](i,0) = sol(i,0)*v[2];
    }
  }
};

class dgAdvectionRiemanTerm : public dgFaceTerm{
 public:
  void operator () (const dgFace &face, fullMatrix<double> fcx[]) const
  {
    const fullMatrix<double> &solLeft = face.solutionLeft();
    const fullMatrix<double> &solRight = face.solutionRight();
    const fullMatrix<double> &normals = face.normals();
    const fullMatrix<double> &QP = face.integration();
    for(int i=0; i< solLeft.size1(); i++) {
      SPoint3 p;
      face.face()->pnt(QP(i,0),QP(i,1),QP(i,2),p);
      double v[3];
      getV(p,v);
      double un=v[0]*normals(0,i)+v[1]*normals(1,i)+v[2]*normals(2,i);
      if(un>0){
        fcx[0](i,0) = -solLeft(i,0)*un;
        if(fcx[0].size2()==2)
          fcx[0](i,1) = solLeft(i,0)*un;
      }else{
        fcx[0](i,0) = -solRight(i,0)*un;
        if(fcx[0].size2()==2)
          fcx[0](i,1) = solRight(i,0)*un;
      }
    }
  }
};
class dgAdvectionBoundary0External : public dgBoundaryCondition {
  boundaryType  type() const {
    return EXTERNAL_VALUES;
  }
  void operator () (const dgFace &face, fullMatrix<double> fcx[]) const{
    const fullMatrix<double> &solLeft = face.solutionLeft();
    for(int i=0; i< solLeft.size1(); i++) {
      fcx[0](i,0) = 0;
    }
  }
};

class dgConservationLawAdvection : public dgConservationLaw {
  public:
  dgConservationLawAdvection() 
  {
    _nbf = 1;
    _convective = new dgAdvectionFluxTerm;
    _riemannSolver = new dgAdvectionRiemanTerm;
    _boundaryConditions["Left"] = new dgAdvectionBoundary0External();
    _boundaryConditions["Right"] = new dgAdvectionBoundary0External();
    _boundaryConditions["Top"] = new dgAdvectionBoundary0External();
    _boundaryConditions["Bottom"] = new dgAdvectionBoundary0External();
  }
  ~dgConservationLawAdvection()
  {
    delete _convective;
    delete _riemannSolver;
    delete _boundaryConditions["Left"];
    delete _boundaryConditions["Right"];
    delete _boundaryConditions["Top"];
    delete _boundaryConditions["Bottom"];
  }
};

dgConservationLaw *dgNewConservationLawAdvection() {
  return new dgConservationLawAdvection;
}
