#ifndef _BASISHIERARCHICALSCALAR_H_
#define _BASISHIERARCHICALSCALAR_H_

#include <string>
#include "BasisLocalScalar.h"
#include "Polynomial.h"
#include "ReferenceSpace.h"

/**
   @interface BasisHierarchicalScalar
   @brief Interface for Hierarchical Scalar Local Basis

   This is an interface for Hierarchical Scalar Local Basis.@n
*/

class BasisHierarchicalScalar: public BasisLocalScalar{
 protected:
  // Orientation //
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

  virtual fullMatrix<double>* getFunctions(unsigned int orientation,
					   double u, double v, double w) const;

  virtual void preEvaluateFunctions    (const fullMatrix<double>& point) const;
  virtual void preEvaluateGradFunctions(const fullMatrix<double>& point) const;

  virtual const fullMatrix<double>&
    getPreEvaluatedFunctions(const MElement& element) const;

  virtual const fullMatrix<double>&
    getPreEvaluatedGradFunctions(const MElement& element) const;

  virtual const fullMatrix<double>&
    getPreEvaluatedFunctions(unsigned int orientation) const;

  virtual const fullMatrix<double>&
    getPreEvaluatedGradFunctions(unsigned int orientation) const;

  virtual unsigned int getNOrientation(void) const;
  virtual unsigned int getOrientation(const MElement& element) const;

  std::string toString(void) const;

 protected:
  BasisHierarchicalScalar(void);

 private:
  void getGrad(void) const;
};

/**
   @internal
   @fn BasisHierarchicalScalar::BasisHierarchicalScalar

   Instanciates an new BasisHierarchicalScalar
   @endinternal
   **

   @fn BasisHierarchicalScalar::~BasisHierarchicalScalar

   Deletes this BasisHierarchicalScalar
   **

   @fn BasisHierarchicalScalar::toString
   @return Returns a string describing this
   BasisHierarchicalScalar
 */

#endif
