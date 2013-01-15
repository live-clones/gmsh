#ifndef _BASISLAGRANGE_H_
#define _BASISLAGRANGE_H_

#include "BasisScalar.h"
#include "FunctionSpaceScalar.h"
#include "FunctionSpaceVector.h"
#include "fullMatrix.h"
#include "polynomialBasis.h"

/**
   @interface BasisLagrange
   @brief Interface for Lagrange Basis
   
   This is an interface for Lagrange Basis.@n
   
   These Scalar Basis allow a @em Coefficient Matrix,
   and a Monomial Matrix, to be consulted.@n
   
   A vector from an Other Basis (set of Functions)
   can also be projected into a Lagrange Basis.@n
   
   @todo
   Add a method to get lagrange Point in polynomialBasis
*/

class BasisLagrange: public BasisScalar{
 protected:
  polynomialBasis*    lBasis; // Lagrange Basis
  fullMatrix<double>* lPoint; // Lagrange Points

 public:
  virtual ~BasisLagrange(void);

  virtual fullMatrix<double>* getFunctions(const MElement& element, 
					   double u, double v, double w) const;

  virtual fullMatrix<double>* getFunctions(unsigned int permutation, 
					   double u, double v, double w) const;

  virtual void preEvaluateFunctions    (const fullMatrix<double>& point) const;
  virtual void preEvaluateGradFunctions(const fullMatrix<double>& point) const;

  virtual const fullMatrix<double>& 
    getPreEvaluatedFunctions(const MElement& element) const;
 
  virtual const fullMatrix<double>& 
    getPreEvaluatedGradFunctions(const MElement& element) const;

  //! @return Returns the Coefficient Matrix
  const fullMatrix<double>& getCoefficient(void) const;
  
  //! @return Returns the Monomial Matrix
  const fullMatrix<double>& getMonomial(void) const;
  
  //! @param element A MElement
  //! @param coef A vector of coefficient associated
  //! to the given Element
  //! @param fSpace The (scalar) Function Space
  //! of the given Coefficients
  //! @return Projects the given Coefficients in this BasisLagrange
  std::vector<double> project(const MElement& element,
			      const std::vector<double>& coef,
			      const FunctionSpaceScalar& fSpace);
  
  //! @param element A MElement
  //! @param coef A vector of coefficient associated
  //! to the given Element
  //! @param fSpace The (vectorial) Function Space
  //! of the given Coefficients
  //! @return Projects the given Coefficients in this BasisLagrange
  std::vector<fullVector<double> > 
    project(const MElement& element,
	    const std::vector<double>& coef,
	    const FunctionSpaceVector& fSpace);
  
 protected:
  BasisLagrange(void);
};

//////////////////////
// Inline Functions //
//////////////////////

inline const fullMatrix<double>& BasisLagrange::
getCoefficient(void) const{
  return lBasis->coefficients;
}

inline const fullMatrix<double>& BasisLagrange::
getMonomial(void) const{
  return lBasis->monomials;
}

#endif
