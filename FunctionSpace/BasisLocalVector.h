#ifndef _BASISLOCALVECTOR_H_
#define _BASISLOCALVECTOR_H_

#include "BasisLocal.h"
#include "MElement.h"
#include "fullMatrix.h"

/**
   @interface BasisLocalVector
   @brief Common Interface for all
   @em Vectorial Local Basis

   This class is the @em common @em interface for all
   @em vectorial Local Basis.@n
*/

class BasisLocalVector: public BasisLocal{
 public:
  virtual ~BasisLocalVector(void);

  virtual fullMatrix<double>* getFunctions(const MElement& element,
					   double u, double v, double w) const = 0;

  virtual fullMatrix<double>* getFunctions(unsigned int orientation,
					   double u, double v, double w) const = 0;

  virtual void preEvaluateFunctions    (const fullMatrix<double>& point) const = 0;
  virtual void preEvaluateCurlFunctions(const fullMatrix<double>& point) const = 0;
  virtual void preEvaluateDivFunctions (const fullMatrix<double>& point) const = 0;

  virtual const fullMatrix<double>&
    getPreEvaluatedFunctions(const MElement& element) const = 0;

  virtual const fullMatrix<double>&
    getPreEvaluatedCurlFunctions(const MElement& element) const = 0;

  virtual const fullMatrix<double>&
    getPreEvaluatedDivFunctions(const MElement& element) const = 0;

  virtual const fullMatrix<double>&
    getPreEvaluatedFunctions(unsigned int orientation) const = 0;

  virtual const fullMatrix<double>&
    getPreEvaluatedCurlFunctions(unsigned int orientation) const = 0;

  virtual const fullMatrix<double>&
    getPreEvaluatedDivFunctions(unsigned int orientation) const = 0;

 protected:
  BasisLocalVector(void);
};


/**
   @internal
   @fn BasisLocalVector::BasisLocalVector

   Instantiates a new BasisLocalVector
   @endinternal
   **

   @fn BasisLocalVector::~BasisLocalVector

   Deletes this BasisLocalVector
   **

   @fn BasisLocalVector::getFunctions(const MElement&, double, double, double) const
   @param element A MElement
   @param u A @c u coordinate in the reference space of this BasisLocal
   @param v A @c v coordinate in the reference space of this BasisLocal
   @param w A @c w coordinate in the reference space of this BasisLocal
   @return Instanciates a new Matrix with the @em evaluation
   of every basis function at the given coordinates, and for the
   given element @em orientation

   @note
   The returned Matrix if of size BasisLocalVector::getNFunction() @c x 3@n
   Each row is a succession of values in 3 coordinates

   @warning
   The Instanciated Matrix must be deleted by the @em calling function
   **

   @fn BasisLocalVector::getFunctions(unsigned int, double, double, double) const
   @param orientation A natural number defining the reference space @em orientation
   @param u A @c u coordinate in the reference space of this BasisLocal
   @param v A @c v coordinate in the reference space of this BasisLocal
   @param w A @c w coordinate in the reference space of this BasisLocal
   @return Instanciates a new fullMatrix<double> with the @em evaluation
   of every basis function at the given coordinates, and for the
   given orientation

   @note
   The returned Matrix if of size BasisLocalVector::getNFunction() @c x 3@n
   Each row is a succession of values in 3 coordinates

   @warning
   The Instanciated Matrix must be deleted by the @em calling function
   **

   @fn BasisLocalVector::preEvaluateFunctions
   @param point A Matrix with points coordinate (each line is a point and got 3 coordinates, @em i.e. 3 rows)
   @return Pre Evaluates every basis function at the given points
   **

   @fn BasisLocalVector::preEvaluateCurlFunctions
   @param point A Matrix with points coordinate (each line is a point and got 3 coordinates, @em i.e. 3 rows)
   @return Pre Evaluates every basis function @em curl at the given points
   **

   @fn BasisLocalVector::preEvaluateDivFunctions
   @param point A Matrix with points coordinate (each line is a point and got 3 coordinates, @em i.e. 3 rows)
   @return Pre Evaluates every basis function @em divergence at the given points
   **

   @fn BasisLocalVector::getPreEvaluatedFunctions(const MElement&) const
   @param element A MElement
   @return Returns a Matrix with the PreEvaluated basis functions
   (see BasisLocalFunction::preEvaluateFunctions()), with the given
   element @em orientation

   @note
   The returned Matrix is of size BasisLocalVector::getNFunction() @c x @c ( @c number @c of @c PreEvaluated @c points @c x @c 3 @c ) @n
   Each row is a succession of values in 3 coordinates

   @note
   If no PreEvaluation has been done before calling this function,
   an Exception is thrown
   **

   @fn BasisLocalVector::getPreEvaluatedCurlFunctions(const MElement&) const
   @param element A MElement
   @return Returns a Matrix with the PreEvaluated basis functions @em curl
   (see BasisLocalFunction::preEvaluateCurlFunctions()), with the given
   element @em orientation

   @note
   The returned Matrix is of size BasisLocalVector::getNFunction() @c x @c ( @c number @c of @c PreEvaluated @c points @c x @c 3 @c ) @n
   Each row is a succession of values in 3 coordinates

   @note
   If no PreEvaluation of the curl has been done before calling this function,
   an Exception is thrown
   **

   @fn BasisLocalVector::getPreEvaluatedDivFunctions(const MElement&) const
   @param element A MElement
   @return Returns a Matrix with the PreEvaluated basis functions @em divergence
   (see BasisLocalFunction::preEvaluateDivFunctions()), with the given
   element @em orientation

   @note
   The returned Matrix is of size BasisLocalVector::getNFunction() @c x @c number @c of @c
   PreEvaluated @c points

   @note
   If no PreEvaluation of the divergence has been done before calling this function,
   an Exception is thrown
   **

   @fn BasisLocalVector::getPreEvaluatedFunctions(unsigned int) const
   @param orientation A number definig the orientation of the reference space
   @return Same as BasisLocalVector::getPreEvaluatedFunctions(const MElement&) const
   but the orientation is not given by en element but by a number (@c orientation)
   **

   @fn BasisLocalVector::getPreEvaluatedCurlFunctions(unsigned int) const
   @param orientation A number definig the orientation of the reference space
   @return Same as BasisLocalVector::getPreEvaluatedCurlFunctions(const MElement&) const
   but the orientation is not given by en element but by a number (@c orientation)
   **

   @fn BasisLocalVector::getPreEvaluatedDivFunctions(unsigned int) const
   @param orientation A number definig the orientation of the reference space
   @return Same as BasisLocalVector::getPreEvaluatedDivFunctions(const MElement&) const
   but the orientation is not given by en element but by a number (@c orientation)
*/

#endif
