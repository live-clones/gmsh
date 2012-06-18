#ifndef _LOCALFUNCTIONSPACE1FORM_H_
#define _LOCALFUNCTIONSPACE1FORM_H_

/**
   @class LocalFunctionSpace1Form
   @brief 1 Form Local Function Spaces
   
   A Local Function Space build on a @em 1 @em Form.
 */

#include <vector>
#include "Polynomial.h"
#include "Basis.h"
#include "Element.h"
#include "LocalFunctionSpaceVector.h"

class LocalFunctionSpace1Form: public LocalFunctionSpaceVector{
 private:
  const std::vector<std::vector<Polynomial> >* basis;
  
 public:
  //! Instantiate a new LocalFunctionSpace1Form
  //! @param basis The Basis used to build 
  //! this Function Space
  //! @param elem The Element on which this
  //! Function Space is defined
  LocalFunctionSpace1Form(const Basis& basis, 
			  const Element& elem);
  
  //! Deletes this LocalFunctionSpace1Form
  //!
  virtual ~LocalFunctionSpace1Form(void);

  virtual fullVector<double> interpolate(const fullVector<double>& coef, 
					 double x, double y, double z) const;
};

#endif
