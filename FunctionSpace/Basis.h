#ifndef _BASIS_H_
#define _BASIS_H_

#include <string>
#include "MElement.h"

/**
   @interface Basis
   @brief Common Interface of all Basis

   This class is the common interface for all Basis.

   A Basis is set of linearly independent Polynomial%s
   (or Vector%s of Polynomial%s).

   The returned matrices are the result of the evaluation
   of the basis functions (at N points).

   The i-th row of these matrices is always refering to the
   i-th function of the basis.

   Depending on the nature of the returned value (scalar or vector),
   the columns are organized diferently.

   For scalar values, we have:
   @li The j-th column of the i-th row is
   the evaluation of the i-th function at the j-th point

   For vectorial values, we have:
   @li The j-th column of the i-th row is the first coordinate of
   the evaluation of the i-th function at the 3 x j-th point

   @li The (j-th + 1) column of the i-th row is the second coordinate of
   the evaluation of the i-th function at the 3 x j-th point

   @li The (j-th + 2) column of the i-th row is the third coordinate of
   the evaluation of the i-th function at the 3 x j-th point
 */

class Basis{
 protected:
  bool scalar;
  bool local;

  size_t order;
  size_t type;
  size_t form;
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
  size_t getForm(void) const;
  size_t getDim(void) const;

  // Number of Functions //
  size_t getNVertexBased(void) const;
  size_t getNEdgeBased(void) const;
  size_t getNFaceBased(void) const;
  size_t getNCellBased(void) const;
  size_t getNFunction(void) const;

  // Direct Access to Evaluated Functions //
  virtual void getFunctions(fullMatrix<double>& retValues,
                            const MElement& element,
                            double u, double v, double w) const = 0;

  virtual void getFunctions(fullMatrix<double>& retValues,
                            size_t orientation,
                            double u, double v, double w) const = 0;

  virtual void getDerivative(fullMatrix<double>& retValues,
                             const MElement& element,
                             double u, double v, double w) const = 0;

  // Precompute Functions //
  virtual
    void preEvaluateFunctions(const fullMatrix<double>& point) const = 0;
  virtual
    void preEvaluateDerivatives(const fullMatrix<double>& point) const = 0;

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
   @li true, if this is a scalar Basis
   @li false, if this is a vectorial Basis

   Scalar basis are sets of Polynomial%s,
   and Vectorial basis are sets of Vector%s of Polynomial%s
   **

   @fn Basis::isLocal
   @return Returns:
   @li true, if this is a Local Basis
   @li false, if this is a Global Basis
   **

   @fn Basis::getOrder
   @return Returns the polynomial order of the Basis
   **

   @fn Basis::getType
   @return Returns the type of the Basis (coherent with gmsh element types):
   @li 1 for Points
   @li 2 for Lines
   @li 3 for Triangles
   @li 4 for Quadrangles
   @li 5 for Tetrahedra
   @li 6 for Pyramids
   @li 7 for Prisms
   @li 8 for Hexahedra
   **

   @fn Basis::getForm
   @return Returns the diferential form of the Basis:
   @li 0 for 0-form
   @li 1 for 1-form
   @li 2 for 2-form
   @li 3 for 3-form
   **

   @fn Basis::getDim
   @return Returns the dimension (1D, 2D or 3D) of the Basis
   **

   @fn Basis::getNVertexBased
   @return Returns the number of Vertex based functions of this Basis
   **

   @fn Basis::getNEdgeBased
   @return Returns the number of Edge based functions of this Basis
   **

   @fn Basis::getNFaceBased
   @return Returns the number of Face based functions of this Basis
   **

   @fn Basis::getNCellBased
   @return Returns the number of Cell based functions of this Basis
   **

   @fn Basis::getNFunction
   @return Returns the number of Polynomial%s
   (or Vector%s of Polynomial%s) Functions in this Basis
   **

   @fn Basis::getFunctions(fullMatrix<double>&, const MElement&, double, double, double) const
   @param retValues An allocated matrix
   @param element A MElement
   @param u A u coordinate in the reference space of this Basis
   @param v A v coordinate in the reference space of this Basis
   @param w A w coordinate in the reference space of this Basis

   The given matrix is populated with the evaluation of every basis function
   at the given coordinates, and for the orientation of the given element
   **

   @fn Basis::getFunctions(fullMatrix<double>&, size_t, double, double, double) const
   @param retValues An allocated matrix
   @param orientation A integer
   @param u A u coordinate in the reference space of this Basis
   @param v A v coordinate in the reference space of this Basis
   @param w A w coordinate in the reference space of this Basis

   The given matrix is populated with the evaluation of every basis function
   at the given coordinates, and for the given orientation
   **

   @fn Basis::getDerivative(fullMatrix<double>&, const MElement&, double, double, double) const
   @param retValues An allocated matrix
   @param element A MElement
   @param u A u coordinate in the reference space of this Basis
   @param v A v coordinate in the reference space of this Basis
   @param w A w coordinate in the reference space of this Basis

   The given matrix is populated with the evaluation of the derivative
   of every basis function at the given coordinates,
   and for the orientation of the given element
   **

   @fn Basis::preEvaluateFunctions
   @param point A Matrix with points coordinate
   (each line is a point and got 3 coordinates, i.e. 3 rows)

   Pre Evaluates every basis function at the given points
   **

   @fn Basis::preEvaluateDerivatives
   @param point A Matrix with points coordinate
   (each line is a point and got 3 coordinates, i.e. 3 rows)

   Pre Evaluates every basis function derivative at the given points

   @li For 0-Form it computes the gradient
   @li For 1-Form it computes the curl
   @li For 2-Form it computes the divergence
   **

   @fn Basis::getPreEvaluatedFunctions(size_t) const
   @param orientation A natural number defining the reference space orientation
   @return Returns a Matrix with the PreEvaluated basis functions
   (see Basis::preEvaluateFunctions()), with the given orientation

   If no PreEvaluation has been done before calling this function,
   an Exception is thrown
   **

   @fn Basis::getPreEvaluatedDerivatives(size_t) const
   @param orientation A natural number defining the reference space orientation
   @return Returns a Matrix with the PreEvaluated basis functions derivatives
   (see Basis::preEvaluateDerivatives()), with the given orientation

   If no PreEvaluation of the gradient has been done
   before calling this function, an Exception is thrown
   **

   @fn Basis::getPreEvaluatedFunctions(const MElement&) const
   @param element A MElement
   @return Same as Basis::getPreEvaluatedFunctions,
   but the orientation is computed with the given element
   **

   @fn Basis::getPreEvaluatedDerivatives(const MElement&) const
   @param element A MElement
   @return Same as Basis::getPreEvaluatedFunctions,
   but the orientation is computed with the given element
   **

   @fn Basis::toString
   @return Returns a string describing this Basis
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

inline size_t Basis::getForm(void) const{
  return form;
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

#endif
