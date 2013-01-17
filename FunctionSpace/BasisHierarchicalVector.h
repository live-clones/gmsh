#ifndef _BASISHIERARCHICALVECTOR_H_
#define _BASISHIERARCHICALVECTOR_H_

#include <string>
#include "BasisLocal.h"
#include "Polynomial.h"
#include "ReferenceSpace.h"

/**
   @interface BasisHierarchicalVector
   @brief Interface for Hierarchical Vectorial Local Basis

   This is an interface for Hierarchical Vectorial Local Basis.@n
*/

class BasisHierarchicalVector: public BasisLocal{
 protected:
  // Orientation //
  ReferenceSpace* refSpace;
  unsigned int    nRefSpace;

  // Basis //
  std::vector<Polynomial>*** basis;

  // Curl Basis //
  mutable bool hasCurl;
  mutable std::vector<Polynomial>*** curl;

  // PreEvaluation //
  mutable bool preEvaluated;
  mutable bool preEvaluatedCurl;

  mutable fullMatrix<double>** preEvaluatedFunction;
  mutable fullMatrix<double>** preEvaluatedCurlFunction;

 public:
  virtual ~BasisHierarchicalVector(void);

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
  BasisHierarchicalVector(void);

 private:
  void getCurl(void) const;
};

/**
   @internal
   @fn BasisHierarchicalVector::BasisHierarchicalVector

   Instanciates an new BasisHierarchicalVector
   @endinternal
   **

   @fn BasisHierarchicalVector::~BasisHierarchicalVector

   Deletes this BasisHierarchicalVector
   **

   @fn BasisHierarchicalVector::toString
   @return Returns a string describing this
   BasisHierarchicalVector
 */

#endif

