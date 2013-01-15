#ifndef _BASISLAGRANGE_H_
#define _BASISLAGRANGE_H_

#include "BasisScalar.h"
#include "polynomialBasis.h"

class BasisLagrange: public BasisScalar{
 protected:
  polynomialBasis* basis;

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

 protected:
  BasisLagrange(void);
};

#endif
