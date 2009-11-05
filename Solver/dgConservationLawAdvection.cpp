#include "dgConservationLaw.h"
#include "fullMatrix.h"
#include "dgGroupOfElements.h"
#include "SPoint3.h"
#include "MElement.h"
class testSourceTerm : public dgTerm {
  void operator () (const dgElement &el, fullMatrix<double> fcx[]) const{
    const fullMatrix<double> &sol = el.solution();
    const fullMatrix<double> &qp = el.integration();
    SPoint3 p;
    for(int i=0; i< sol.size1(); i++) {
      el.element()->pnt(qp(i,0),qp(i,1),qp(i,2),p);
      //printf("%e -  %e (%i)\n",p.x(),sol(i,0),sol.size2());
      fcx[0](i,0) = (p.x()*p.x()+p.y()*p.y()) - sol(i,0);
    }
  }
};

class dgConservationLawAdvection : public dgConservationLaw {
  public:
  dgConservationLawAdvection() {
    _nbf = 1;
    _source = new testSourceTerm;
  }
};

dgConservationLaw *dgNewConservationLawAdvection() {
  return new dgConservationLawAdvection;
}
