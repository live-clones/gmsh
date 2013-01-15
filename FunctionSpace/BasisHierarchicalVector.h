#ifndef _BASISHIERARCHICALVECTOR_H_
#define _BASISHIERARCHICALVECTOR_H_

#include <string>
#include "BasisVector.h"
#include "Polynomial.h"
#include "ReferenceSpace.h"

class BasisHierarchicalVector: public BasisVector{
 protected:
  // Permutation //
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

  virtual fullMatrix<double>* getFunctions(unsigned int permutation, 
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

  std::string toString(void) const;

 protected:
  BasisHierarchicalVector(void);

 private:
  void getCurl(void) const;
  void getDiv(void) const;
};

#endif

