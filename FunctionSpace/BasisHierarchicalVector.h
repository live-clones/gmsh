#ifndef _BASISHIERARCHICALVECTOR_H_
#define _BASISHIERARCHICALVECTOR_H_

#include <string>
#include "BasisLocalVector.h"
#include "Polynomial.h"
#include "ReferenceSpace.h"

/**
   @interface BasisHierarchicalVector
   @brief Interface for Hierarchical Vectorial Local Basis

   This is an interface for Hierarchical Vectorial Local Basis.@n
*/

class BasisHierarchicalVector: public BasisLocalVector{
 protected:
  // Orientation //
  ReferenceSpace* refSpace;
  unsigned int    nRefSpace;

  // Basis //
  std::vector<Polynomial>*** basis;

  // Curl Basis //
  mutable bool hasCurl;
  mutable std::vector<Polynomial>*** curl;

  // Div Basis //
  mutable bool hasDiv;
  mutable Polynomial*** div;

  // PreEvaluation //
  mutable bool preEvaluated;
  mutable bool preEvaluatedCurl;
  mutable bool preEvaluatedDiv;

  mutable fullMatrix<double>** preEvaluatedFunction;
  mutable fullMatrix<double>** preEvaluatedCurlFunction;
  mutable fullMatrix<double>** preEvaluatedDivFunction;

 public:
  virtual ~BasisHierarchicalVector(void);

  virtual fullMatrix<double>* getFunctions(const MElement& element,
					   double u, double v, double w) const;

  virtual fullMatrix<double>* getFunctions(unsigned int orientation,
					   double u, double v, double w) const;

  virtual void preEvaluateFunctions    (const fullMatrix<double>& point) const;
  virtual void preEvaluateCurlFunctions(const fullMatrix<double>& point) const;
  virtual void preEvaluateDivFunctions (const fullMatrix<double>& point) const;

  virtual const fullMatrix<double>&
    getPreEvaluatedFunctions(const MElement& element) const;

  virtual const fullMatrix<double>&
    getPreEvaluatedCurlFunctions(const MElement& element) const;

  virtual const fullMatrix<double>&
    getPreEvaluatedDivFunctions (const MElement& element)const;

  virtual const fullMatrix<double>&
    getPreEvaluatedFunctions(unsigned int orientation) const;

  virtual const fullMatrix<double>&
    getPreEvaluatedCurlFunctions(unsigned int orientation) const;

  virtual const fullMatrix<double>&
    getPreEvaluatedDivFunctions(unsigned int orientation) const;

  virtual unsigned int getNOrientation(void) const;
  virtual unsigned int getOrientation(const MElement& element) const;

  std::string toString(void) const;

 protected:
  BasisHierarchicalVector(void);

 private:
  void getCurl(void) const;
  void getDiv(void) const;
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

