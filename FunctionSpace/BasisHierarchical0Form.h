#ifndef _BASISHIERARCHICAL0FORM_H_
#define _BASISHIERARCHICAL0FORM_H_

#include "BasisLocal.h"
#include "Polynomial.h"

/**
   @interface BasisHierarchical0Form
   @brief Interface for hierarchical 0-form local Basis

   This is an interface for hierarchical 0-form local Basis.@n
*/

class BasisHierarchical0Form: public BasisLocal{
 protected:
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
  virtual ~BasisHierarchical0Form(void);

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
  BasisHierarchical0Form(void);

 private:
  void getGrad(void) const;
};

/**
   @internal
   @fn BasisHierarchical0Form::BasisHierarchical0Form
   Instanciates an new BasisHierarchical0Form
   @endinternal
   **

   @fn BasisHierarchical0Form::~BasisHierarchical0Form
   Deletes this BasisHierarchical0Form
 */

#endif
