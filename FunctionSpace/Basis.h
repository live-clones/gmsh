#ifndef _BASIS_H_
#define _BASIS_H_

#include <string>
#include "MElement.h"
#include "ReferenceSpace.h"

/**
   @interface Basis
   @brief Common Interface of all Basis

   This class is the @em common @em interface for all Basis.@n

   A Basis is @em set of @em linearly @em independent Polynomial%s
   (or Vector%s of Polynomial%s).@n

   @note
   The returned matrices are the result of the evaluation
   of the basis functions (at @c N points).@n

   The @c i-th row of these matrices is always refering to the
   @c i-th function of the basis.@n

   Depending on the nature of the returned value
   (@em scalar or @em vector), the columns are organized
   diferently.

   For @em scalar values, we have:
   @li The @c j-th column of the @c i-th row is
   the evaluation of the @c i-th function at the @c j-th point

   For @em vectorial values, we have:
   @li The @c j-th column of the @c i-th row is
   the @em first @em coordinate of
   the evaluation of the @c i-th function at the @c 3 @c x @c j-th point

   @li The @c (@c j-th @c + @c 1 @c ) column of the @c i-th row is
   the @em second @em coordinate of
   the evaluation of the @c i-th function at the @c 3 @c x @c j-th point

   @li The @c (@c j-th @c + @c 2 @c ) column of the @c i-th row is
   the @em third @em coordinate of
   the evaluation of the @c i-th function at the @c 3 @c x @c j-th point
 */

class Basis{
 protected:
  ReferenceSpace* refSpace;

  bool scalar;
  bool local;

  size_t order;
  size_t type;
  size_t dim;

  size_t nVertex;
  size_t nEdge;
  size_t nFace;
  size_t nCell;

  size_t nFunction;

 public:
  // Destructor //
  virtual ~Basis(void);

  // Scalar & Local //
  bool isScalar(void) const;
  bool isLocal(void) const;

  // Type of Basis //
  size_t getOrder(void) const;
  size_t getType(void) const;
  size_t getDim(void) const;

  // Number of Functions //
  size_t getNVertexBased(void) const;
  size_t getNEdgeBased(void) const;
  size_t getNFaceBased(void) const;
  size_t getNCellBased(void) const;
  size_t getNFunction(void) const;

  // Reference Element //
  const ReferenceSpace& getReferenceSpace(void) const;

  // Direct Access to Evaluated Functions //
  virtual void getFunctions(fullMatrix<double>& retValues,
                            const MElement& element,
                            double u, double v, double w) const = 0;

  virtual void getFunctions(fullMatrix<double>& retValues,
                            size_t orientation,
                            double u, double v, double w) const = 0;

  // Precompute Functions //
  virtual void preEvaluateFunctions(const fullMatrix<double>& point) const = 0;
  virtual void preEvaluateDerivatives(const fullMatrix<double>& point) const = 0;

  // Access to Precomputed Functions //
  virtual const fullMatrix<double>&
    getPreEvaluatedFunctions(const MElement& element) const = 0;

  virtual const fullMatrix<double>&
    getPreEvaluatedDerivatives(const MElement& element) const = 0;

  virtual const fullMatrix<double>&
    getPreEvaluatedFunctions(size_t orientation) const = 0;

  virtual const fullMatrix<double>&
    getPreEvaluatedDerivatives(size_t orientation) const = 0;

  virtual std::string toString(void) const = 0;

 protected:
  // 'Constructor' //
  Basis(void);
};


/**
   @internal
   @fn Basis::Basis

   Instantiate a new Basis
   @endinternal
   **

   @fn Basis::~Basis

   Deletes this Basis
   **

   @fn Basis::isScalar
   @return Returns:
   @li @c true, if this is a
   @em scalar Basis
   @li @c false, if this is a
   @em vectorial Basis

   @note
   Scalar basis are sets of
   Polynomial%s@n
   Vectorial basis are sets of
   Vector%s of Polynomial%s
   **

   @fn Basis::isLocal
   @return Returns:
   @li @c true, if this is a
   @em Local Basis
   @li @c false, if this is a
   @em Global Basis
   **

   @fn Basis::getOrder
   @return Returns the @em polynomial @em order of the Basis
   **

   @fn Basis::getType
   @return Returns the @em type of the Basis:
   @li 0 for 0-form
   @li 1 for 1-form
   @li 2 for 2-form
   @li 3 for 3-form
   **

   @fn Basis::getDim
   @return Returns the @em dimension
   (@c 1D, @c 2D or @c 3D) of the Basis
   **

   @fn Basis::getNVertexBased
   @return Returns the number of @em Vertex
   @em Based functions of this Basis
   **

   @fn Basis::getNEdgeBased
   @return Returns the number of @em Edge
   @em Based functions of this Basis
   **

   @fn Basis::getNFaceBased
   @return Returns the number of @em Face
   @em Based functions of this Basis
   **

   @fn Basis::getNCellBased
   @return Returns the number of @em Cell
   @em Based functions of this Basis
   **

   @fn Basis::getNFunction
   @return Returns the number of Polynomial%s
   (or Vector%s of Polynomial%s) Functions
   in this Basis
   **

   @fn Basis::getNOrientation
   @return Returns the number of
   @em orientation of this Basis
   Reference Space
   **

   @fn Basis::getOrientation
   @param element A MElement
   @return Returns a number
   (from 0 to Basis::getNOrientation() - 1)
   charaterizing the @em orientation
   of the given element
   **

   @fn Basis::getFunctions(size_t, double, double, double) const
   @param orientation A natural number defining the reference space @em orientation
   @param u A @c u coordinate in the reference space of this Basis
   @param v A @c v coordinate in the reference space of this Basis
   @param w A @c w coordinate in the reference space of this Basis
   @return Instanciates a new fullMatrix<double> with the @em evaluation
   of every basis function at the given coordinates, and for the
   given orientation

   @warning
   The Instanciated Matrix must be deleted by the @em calling function
   **

   @fn Basis::getFunctions(const MElement&, double, double, double) const
   @param element A MElement
   @param u A @c u coordinate in the reference space of this Basis
   @param v A @c v coordinate in the reference space of this Basis
   @param w A @c w coordinate in the reference space of this Basis
   @return Same as Basis::getFunction(Basis::getOrientation(@c element),
   @c u, @c u, @c w)
   **

   @fn Basis::preEvaluateFunctions
   @param point A Matrix with points coordinate
   (each line is a point and got 3 coordinates, @em i.e. 3 rows)
   @return Pre Evaluates every basis function at the given points
   **

   @fn Basis::preEvaluateDerivatives
   @param point A Matrix with points coordinate
   (each line is a point and got 3 coordinates, @em i.e. 3 rows)
   @return Pre Evaluates every basis function @em derivative at the given points

   @note
   @li For 0-Form it computes the @em gradient
   @li For 1-Form it computes the @em curl
   @li For 2-Form it computes the @em divergence
   @li For 3-Form it computes the @em ???
   @todo What is the derivative of a 3-Form
   (does it exists -- discontinous field nope ?) ?
   **

   @fn Basis::getPreEvaluatedFunctions(size_t) const
   @param orientation A natural number defining the reference space @em orientation
   @return Returns a Matrix with the PreEvaluated basis functions
   (see Basis::preEvaluateFunctions()), with the given @em orientation

   @note
   If no PreEvaluation has been done before calling this function,
   an Exception is thrown
   **

   @fn Basis::getPreEvaluatedDerivatives(size_t) const
   @param orientation A natural number defining the reference space @em orientation
   @return Returns a Matrix with the PreEvaluated basis functions @em derivatives
   (see Basis::preEvaluateDerivatives()), with the given @em orientation

   @note
   If no PreEvaluation of the gradient has been done before calling this function,
   an Exception is thrown
   **

   @fn Basis::getPreEvaluatedFunctions(const MElement&) const
   @return Same as Basis::getPreEvaluatedFunctions(Basis::getOrientation(@c element))
   **

   @fn Basis::getPreEvaluatedDerivatives(const MElement&) const
   @return Same as Basis::getPreEvaluatedDerivatives(Basis::getOrientation(@c element))
*/

//////////////////////
// Inline Functions //
//////////////////////

inline bool Basis::isScalar(void) const{
  return scalar;
}

inline bool Basis::isLocal(void) const{
  return local;
}

inline size_t Basis::getOrder(void) const{
  return order;
}

inline size_t Basis::getType(void) const{
  return type;
}

inline size_t Basis::getDim(void) const{
  return dim;
}

inline size_t Basis::getNVertexBased(void) const{
  return nVertex;
}

inline size_t Basis::getNEdgeBased(void) const{
  return nEdge;
}

inline size_t Basis::getNFaceBased(void) const{
  return nFace;
}

inline size_t Basis::getNCellBased(void) const{
  return nCell;
}

inline size_t Basis::getNFunction(void) const{
  return nFunction;
}

inline const ReferenceSpace& Basis::getReferenceSpace(void) const{
  return *refSpace;
}

#endif
