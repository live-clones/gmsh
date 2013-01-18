#ifndef _BASISHIERARCHICAL1FROM_H_
#define _BASISHIERARCHICAL1FROM_H_

#include <string>
#include "BasisLocal.h"
#include "Polynomial.h"
#include "ReferenceSpace.h"

/**
   @interface BasisHierarchical1From
   @brief Interface for Hierarchical 1-Froml Local Basis

   This is an interface for Hierarchical 1-Froml Local Basis.@n
*/

class BasisHierarchical1From: public BasisLocal{
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
  virtual ~BasisHierarchical1From(void);

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
  BasisHierarchical1From(void);

 private:
  void getCurl(void) const;
};

/**
   @internal
   @fn BasisHierarchical1From::BasisHierarchical1From

   Instanciates an new BasisHierarchical1From
   @endinternal
   **

   @fn BasisHierarchical1From::~BasisHierarchical1From

   Deletes this BasisHierarchical1From
   **

   @fn BasisHierarchical1From::toString
   @return Returns a string describing this
   BasisHierarchical1From
 */

#endif

