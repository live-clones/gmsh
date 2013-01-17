#ifndef _BASISLOCALSCALAR_H_
#define _BASISLOCALSCALAR_H_

#include "BasisLocal.h"
#include "MElement.h"
#include "fullMatrix.h"

/**
   @interface BasisLocalScalar
   @brief Common Interface for all
   @em Scalar Local Basis

   This class is the @em common @em interface for all
   @em scalar Local Basis.@n
*/

class BasisLocalScalar: public BasisLocal{
 public:
  virtual ~BasisLocalScalar(void);

  virtual fullMatrix<double>* getFunctions(const MElement& element,
					   double u, double v, double w) const = 0;

  virtual fullMatrix<double>* getFunctions(unsigned int orientation,
					   double u, double v, double w) const = 0;

  virtual void preEvaluateFunctions    (const fullMatrix<double>& point) const = 0;
  virtual void preEvaluateGradFunctions(const fullMatrix<double>& point) const = 0;

  virtual const fullMatrix<double>&
    getPreEvaluatedFunctions(const MElement& element) const = 0;

  virtual const fullMatrix<double>&
    getPreEvaluatedGradFunctions(const MElement& element) const = 0;

  virtual const fullMatrix<double>&
    getPreEvaluatedFunctions(unsigned int orientation) const = 0;

  virtual const fullMatrix<double>&
    getPreEvaluatedGradFunctions(unsigned int orientation) const = 0;

 protected:
  BasisLocalScalar(void);
};


/**
   @internal
   @fn BasisLocalScalar::BasisLocalScalar

   Instantiates a new BasisLocalScalar
   @endinternal
   **

   @fn BasisLocalScalar::~BasisLocalScalar

   Deletes this BasisLocalScalar
   **

   @fn BasisLocalScalar::getFunctions(const MElement&, double, double, double) const
   @param element A MElement
   @param u A @c u coordinate in the reference space of this BasisLocal
   @param v A @c v coordinate in the reference space of this BasisLocal
   @param w A @c w coordinate in the reference space of this BasisLocal
   @return Instanciates a new Matrix with the @em evaluation
   of every basis function at the given coordinates, and for the
   given element @em orientation

   @note
   The returned Matrix if of size BasisLocalScalar::getNFunction() @c x 1

   @warning
   The Instanciated Matrix must be deleted by the @em calling function
   **

   @fn BasisLocalScalar::getFunctions(unsigned int, double, double, double) const
   @param orientation A natural number defining the reference space @em orientation
   @param u A @c u coordinate in the reference space of this BasisLocal
   @param v A @c v coordinate in the reference space of this BasisLocal
   @param w A @c w coordinate in the reference space of this BasisLocal
   @return Instanciates a new fullMatrix<double> with the @em evaluation
   of every basis function at the given coordinates, and for the
   given orientation

   @note
   The returned Matrix if of size BasisLocalScalar::getNFunction() @c x 1

   @warning
   The Instanciated Matrix must be deleted by the @em calling function
   **

   @fn BasisLocalScalar::preEvaluateFunctions
   @param point A Matrix with points coordinate (each line is a point and got 3 coordinates, @em i.e. 3 rows)
   @return Pre Evaluates every basis function at the given points
   **

   @fn BasisLocalScalar::preEvaluateGradFunctions
   @param point A Matrix with points coordinate (each line is a point and got 3 coordinates, @em i.e. 3 rows)
   @return Pre Evaluates every basis function @em gradient at the given points
   **

   @fn BasisLocalScalar::getPreEvaluatedFunctions(const MElement&) const
   @param element A MElement
   @return Returns a Matrix with the PreEvaluated basis functions
   (see BasisLocalFunction::preEvaluateFunctions()), with the given
   element @em orientation

   @note
   The returned Matrix is of size BasisLocalScalar::getNFunction() @c x @c number @c of @c
   PreEvaluated @c points

   @note
   If no PreEvaluation has been done before calling this function,
   an Exception is thrown
   **

   @fn BasisLocalScalar::getPreEvaluatedGradFunctions(const MElement&) const
   @param element A MElement
   @return Returns a Matrix with the PreEvaluated basis functions @em gradient
   (see BasisLocalFunction::preEvaluateGradFunctions()), with the given
   element @em orientation

   @note
   The returned Matrix is of size BasisLocalScalar::getNFunction() @c x @c ( @c number @c of @c PreEvaluated @c points @c x @c 3 @c ) @n
   Each row is a succession of values in 3 coordinates

   @note
   If no PreEvaluation of the gradient has been done before calling this function,
   an Exception is thrown
   **

   @fn BasisLocalScalar::getPreEvaluatedFunctions(unsigned int) const
   @param orientation A number definig the orientation of the reference space
   @return Same as BasisLocalScalar::getPreEvaluatedFunctions(const MElement&) const
   but the orientation is not given by en element but by a number (@c orientation)
   **

   @fn BasisLocalScalar::getPreEvaluatedGradFunctions(unsigned int) const
   @param orientation A number definig the orientation of the reference space
   @return Same as BasisLocalScalar::getPreEvaluatedGradFunctions(const MElement&) const
   but the orientation is not given by en element but by a number (@c orientation)
 */

#endif
