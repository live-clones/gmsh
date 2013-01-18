#ifndef _BASISHIERARCHICAL0FROM_H_
#define _BASISHIERARCHICAL0FROM_H_

#include <string>
#include "BasisLocal.h"
#include "Polynomial.h"
#include "ReferenceSpace.h"

/**
   @interface BasisHierarchical0From
   @brief Interface for Hierarchical 0-From Local Basis

   This is an interface for Hierarchical 0-From Local Basis.@n
*/

class BasisHierarchical0From: public BasisLocal{
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
  virtual ~BasisHierarchical0From(void);

  virtual unsigned int getNOrientation(void) const;
  virtual unsigned int getOrientation(const MElement& element) const;

  virtual fullMatrix<double>* getFunctions(const MElement& element,
					   double u, double v, double w) const;

  virtual fullMatrix<double>* getFunctions(unsigned int orientation,
					   double u, double v, double w) const;

  virtual void preEvaluateFunctions(const fullMatrix<double>& point) const;
  virtual void preEvaluateDerivatives(const fullMatrix<double>& point) const;

  virtual const fullMatrix<double>&
    getPreEvaluatedFunctions(const MElement& element) const;

  virtual const fullMatrix<double>&
    getPreEvaluatedDerivatives(const MElement& element) const;

  virtual const fullMatrix<double>&
    getPreEvaluatedFunctions(unsigned int orientation) const;

  virtual const fullMatrix<double>&
    getPreEvaluatedDerivatives(unsigned int orientation) const;

  std::string toString(void) const;

 protected:
  BasisHierarchical0From(void);

 private:
  void getGrad(void) const;
};

/**
   @internal
   @fn BasisHierarchical0From::BasisHierarchical0From

   Instanciates an new BasisHierarchical0From
   @endinternal
   **

   @fn BasisHierarchical0From::~BasisHierarchical0From

   Deletes this BasisHierarchical0From
   **

   @fn BasisHierarchical0From::toString
   @return Returns a string describing this
   BasisHierarchical0From
 */

#endif
