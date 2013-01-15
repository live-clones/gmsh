#ifndef _BASISHIERARCHICALSCALAR_H_
#define _BASISHIERARCHICALSCALAR_H_

#include <string>
#include "BasisScalar.h"
#include "Polynomial.h"
#include "ReferenceSpace.h"

class BasisHierarchicalScalar: public BasisScalar{
 protected:
  // Permutation //
  ReferenceSpace* refSpace;
  unsigned int    nRefSpace;

  // Basis //
  Polynomial*** basis;

  // Grad Basis //
  mutable bool hasGrad;
  mutable std::vector<Polynomial>*** grad;

  // PreEvaluation //
  mutable bool preEvaluated;
  mutable bool preEvaluatedGrad;

  mutable fullMatrix<double>** preEvaluatedFunction;
  mutable fullMatrix<double>** preEvaluatedGradFunction;

 public:
  virtual ~BasisHierarchicalScalar(void);
  
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

  std::string toString(void) const;

 protected:
  BasisHierarchicalScalar(void);

 private:
  void getGrad(void) const;
};

#endif
