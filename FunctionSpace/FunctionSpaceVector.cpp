#include "Mapper.h"
#include "FunctionSpaceVector.h"

using namespace std;

FunctionSpaceVector::
FunctionSpaceVector(const vector<const GroupOfElement*>& goe,
                    const vector<const GroupOfElement*>& exclude,
                    size_t order, string family){
  // Init
  init(goe, exclude, order, family);
}

FunctionSpaceVector::
FunctionSpaceVector(const vector<const GroupOfElement*>& goe,
                    size_t order, string family){
  // Dummy Exclude
  vector<const GroupOfElement*> dummy;

  // Init
  init(goe, dummy, order, family);
}

FunctionSpaceVector::
FunctionSpaceVector(const GroupOfElement& goe,
                    size_t order, string family){
  // Temp vector
  vector<const GroupOfElement*> tmp(1);
  tmp[0] = &goe;

  // Dummy Exclude
  vector<const GroupOfElement*> dummy;

  // Init
  init(tmp, dummy, order, family);
}

FunctionSpaceVector::~FunctionSpaceVector(void){
  // Done by FunctionSpace
}

void FunctionSpaceVector::init(const vector<const GroupOfElement*>& goe,
                               const vector<const GroupOfElement*>& exclude,
                               size_t order, string family){
  // Init
  this->scalar = false;
  this->form   = 1;
  this->order  = order;

  // Build FunctionSpace
  build(goe, exclude, family);
}

fullVector<double> FunctionSpaceVector::
interpolateInABC(const MElement& element,
                 const vector<double>& coef,
                 double abc[3]) const{

  // Get Jacobian //
  fullMatrix<double> invJac(3, 3);
  ReferenceSpaceManager::getJacobian(element, abc[0], abc[1], abc[2], invJac);
  invJac.invertInPlace();

  // Get Basis Functions //
  const Basis& basis = getBasis(element);
  const size_t nFun  = basis.getNFunction();
  fullMatrix<double> fun(nFun, 3);

  basis.getFunctions(fun, element, abc[0], abc[1], abc[2]);

  // Get All Dofs (even those that are supposed to be rejected)
  vector<Dof> myDof;
  getKeys(element, myDof, true);

  // Interpolate (in Reference Place) //
  fullMatrix<double> val(1, 3);
  val(0, 0) = 0;
  val(0, 1) = 0;
  val(0, 2) = 0;

  for(size_t i = 0, j = 0; i < nFun; i++){
    if(myDof[i] != rejectedDof){
      val(0, 0) += fun(i, 0) * coef[j];
      val(0, 1) += fun(i, 1) * coef[j];
      val(0, 2) += fun(i, 2) * coef[j];

      j++;
    }
  }

  // Return Interpolated Value //
  fullVector<double> map(3);
  Mapper::hCurl(val, 0, 0, invJac, map);
  return map;
}

fullVector<double> FunctionSpaceVector::
interpolateDerivativeInABC(const MElement& element,
                           const vector<double>& coef,
                           double abc[3]) const{
  // Get Jacobian //
  fullMatrix<double> jac(3, 3);
  double det =
    ReferenceSpaceManager::getJacobian(element, abc[0], abc[1], abc[2], jac);

  // Get Basis Functions //
  const Basis& basis = getBasis(element);
  const size_t nFun  = basis.getNFunction();
  fullMatrix<double> fun(nFun, 3);

  basis.getDerivative(fun, element, abc[0], abc[1], abc[2]);

  // Get All Dofs (even those that are supposed to be rejected)
  vector<Dof> myDof;
  getKeys(element, myDof, true);

  // Interpolate (in Reference Place) //
  fullMatrix<double> val(1, 3);
  val(0, 0) = 0;
  val(0, 1) = 0;
  val(0, 2) = 0;

  for(size_t i = 0, j = 0; i < nFun; i++){
    if(myDof[i] != rejectedDof){
      val(0, 0) += fun(i, 0) * coef[j];
      val(0, 1) += fun(i, 1) * coef[j];
      val(0, 2) += fun(i, 2) * coef[j];

      j++;
    }
  }

  // Return Interpolated Value //
  fullVector<double> map(3);
  Mapper::hDiv(val, 0, 0, jac, det, map);
  return map;
}
