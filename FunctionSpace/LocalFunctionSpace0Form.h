#ifndef _LOCALFUNCTIONSPACE0FORM_H_
#define _LOCALFUNCTIONSPACE0FORM_H_

#include <vector>
#include "Polynomial.h"
#include "Basis.h"
#include "Element.h"
#include "Jacobian.h"
#include "LocalFunctionSpaceScalar.h"

/**
   @class LocalFunctionSpace0Form
   @brief 0 Form Local Function Spaces
   
   A Local Function Space build on a @em 0 @em Form
 */

class LocalFunctionSpace0Form: public LocalFunctionSpaceScalar{
 private:
  const std::vector<Polynomial>* basis;
  Jacobian* jac;  

 public:
  //! Instantiate a new LocalFunctionSpace0Form
  //! @param basis The Basis used to build 
  //! this Function Space
  //! @param elem The Element on which this
  //! Function Space is defined
  LocalFunctionSpace0Form(const Basis& basis, 
			  const Element& elem);
  
  //! Deletes this LocalFunctionSpace0Form
  //!
  virtual ~LocalFunctionSpace0Form(void);
  
  virtual double interpolate(const fullVector<double>& coef, 
			      double x, double y, double z) const;
};

#endif
