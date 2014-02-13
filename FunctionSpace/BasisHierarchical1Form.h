#ifndef _BASISHIERARCHICAL1FORM_H_
#define _BASISHIERARCHICAL1FORM_H_

#include "BasisLocal.h"
#include "Polynomial.h"

/**
   @interface BasisHierarchical1Form
   @brief Interface for hierarchical 1-form local Basis

   This is an interface for hierarchical 1-form local Basis.@n
*/

class BasisHierarchical1Form: public BasisLocal{
 protected:
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
  virtual ~BasisHierarchical1Form(void);

  virtual void getFunctions(fullMatrix<double>& retValues,
                            const MElement& element,
                            double u, double v, double w) const;

  virtual void getFunctions(fullMatrix<double>& retValues,
                            size_t orientation,
                            double u, double v, double w) const;

  virtual void getDerivative(fullMatrix<double>& retValues,
                             const MElement& element,
                             double u, double v, double w) const;

  virtual void preEvaluateFunctions(const fullMatrix<double>& point) const;
  virtual void preEvaluateDerivatives(const fullMatrix<double>& point) const;

  virtual const fullMatrix<double>&
    getPreEvaluatedFunctions(const MElement& element) const;

  virtual const fullMatrix<double>&
    getPreEvaluatedDerivatives(const MElement& element) const;

  virtual const fullMatrix<double>&
    getPreEvaluatedFunctions(size_t orientation) const;

  virtual const fullMatrix<double>&
    getPreEvaluatedDerivatives(size_t orientation) const;

  virtual std::string toString(void) const;

 protected:
  BasisHierarchical1Form(void);

 private:
  void getCurl(void) const;
};

/**
   @internal
   @fn BasisHierarchical1Form::BasisHierarchical1Form
   Instanciates an new BasisHierarchical1Form
   @endinternal
   **

   @fn BasisHierarchical1Form::~BasisHierarchical1Form
   Deletes this BasisHierarchical1Form
 */

#endif
